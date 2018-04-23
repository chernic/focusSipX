// TestCom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>
#include <atlcom.h>
#include "../FocusSipAtl/FocusSipAtl_i.h"
#include "../FocusSipAtl/FocusSipAtl_i.c"

#include <iostream>
#include <thread>

using namespace std;

class CSink :
    public CComObjectRoot,
    public _IMyCarEvents
{
    BEGIN_COM_MAP(CSink)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(_IMyCarEvents)
    END_COM_MAP()

public:
    virtual ~CSink(){}
    STDMETHODIMP GetTypeInfoCount(UINT *pctinfo) { return E_NOTIMPL; }
    STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)   { return E_NOTIMPL; }
    STDMETHODIMP GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)  { return E_NOTIMPL; }

    STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
    {
        printf("sink, id: %d, parm: %f", dispIdMember, pDispParams->rgvarg[0].fltVal);

        return S_OK;
    }
};


CComModule m_commodule;

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitializeEx(0, COINIT_APARTMENTTHREADED);

    {
        CComPtr<IMyCar> spCar;
        spCar.CoCreateInstance(CLSID_MyCar, NULL, CLSCTX_INPROC_SERVER);

        CComObject<CSink>* sinkptr = nullptr;
        CComObject<CSink>::CreateInstance(&sinkptr);

        DWORD cookies = 0;

        AtlAdvise(spCar, sinkptr, __uuidof(_IMyCarEvents), &cookies);

        spCar->Run();
    }
    

	CoUninitialize();


	return 0;
}