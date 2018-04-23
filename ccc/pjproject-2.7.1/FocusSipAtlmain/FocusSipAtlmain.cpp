// FocusSipAtlmain.cpp : �������̨Ӧ�ó������ڵ㡣
// ���ĵ�ʾ����vs2008�в���ͨ��

#include "stdafx.h"
#include <atlbase.h>
#include <atlcom.h>
#include "../FocusSipAtl/FocusSipAtl_i.h"
#include "../FocusSipAtl/FocusSipAtl_i.c"

#include <comdef.h> //_bstr_t
#include <iostream>

using namespace std;

class CSink :
    public CComObjectRoot,
    public _IFocusSipEvents
{
    BEGIN_COM_MAP(CSink)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(_IFocusSipEvents)
    END_COM_MAP()

public:
    virtual ~CSink(){}
    STDMETHODIMP GetTypeInfoCount(UINT *pctinfo) { return E_NOTIMPL; }
    STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)   { return E_NOTIMPL; }
    STDMETHODIMP GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)  { return E_NOTIMPL; }
    STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
    {
		printf("\n\nCongratulation! C++ use OCX OK. ");

		/*
		ʹ��VARIANT�����ݲ�����ζ�ŷ�ǿ��������(����VBScript)�ܹ�����ʹ��ǿ��������(C++)ʵ�ֵķ�����

		https://www.cnblogs.com/caucyj/archive/2011/02/10/1950497.html
		VT_DISPATCH

		ָ����һ��ָ������ָ�����ͣ�ֵ�����pdispVal�С�
		��������������IDispatch�ӿ�ʵ�ֵĶ������������ͨ������QueryInterface���з��ʣ�
		�������Ƿ�ʵ����������Ҫ�Ľӿڡ���Щû��ʵ��IDispatch�ӿڵĶ��󣬾���Ҫ��������VT_UNKNOWN

		VT_UNKNOWN
		ָ��һ�������punkVal�е�IUnknownʵ�ֶ����ָ��

		VT_UNKNOWN | VT_BYREF
		ָ��һ�������ppunkVal�е�ָ��IUnknownʵ�ֶ���ָ���ָ�롣
		*/


		// ע��, �����Ǵ���������
		if (dispIdMember == ID_OnAboutBox){

			printf("\n\nRaised OnAboutBox(). \n");

			printf(" sink, id: %d, parmB: %f . \n", dispIdMember, pDispParams->rgvarg[0].fltVal);
			printf(" sink, id: %d, parmA: %f . \n", dispIdMember, pDispParams->rgvarg[1].fltVal);


		}else if (dispIdMember == ID_OnRegState2){

			printf("\n\nRaised OnRegState(). \n");

			printf(" sink, id: %d, parm : %p . \n", dispIdMember, pDispParams->rgvarg[0].pdispVal);
			printf(" sink, id: %d, parm : %d . \n", dispIdMember, pDispParams->rgvarg[1].intVal);


		}else if (dispIdMember == ID_OnCallState){			printf("\n\nRaised OnCallState(). \n");

			printf(" sink, id: %d, parm : %p . \n", dispIdMember, pDispParams->rgvarg[0].intVal);

			printf(" sink, id: %d, parm : %d . \n", dispIdMember, pDispParams->rgvarg[1].intVal);

		}else if (dispIdMember == ID_OnBuddyState){			printf("\n\nRaised OnBuddyState(). \n");

			printf(" sink, id: %d, parm : %p . \n", dispIdMember, pDispParams->rgvarg[0].intVal);

			printf(" sink, id: %d, parm : %d . \n", dispIdMember, pDispParams->rgvarg[1].intVal);

		}
		/*
		else if (dispIdMember == ID_OnIncomingPager){		printf("\n\nRaised OnIncomingPager(). \n");

			_bstr_t b00 = pDispParams->rgvarg[0].bstrVal;
			char* lpszText00 = b00;
			printf(" sink, id: %d, parm : %s . \n", dispIdMember, lpszText00);

			_bstr_t b11 = pDispParams->rgvarg[1].bstrVal;
			char* lpszText11 = b11;
			printf(" sink, id: %d, parm : %s . \n", dispIdMember, lpszText11);

			_bstr_t b22 = pDispParams->rgvarg[2].bstrVal;
			char* lpszText22 = b22;
			printf(" sink, id: %d, parm : %s . \n", dispIdMember, lpszText22);

			printf(" sink, id: %d, parm : %d . \n", dispIdMember, pDispParams->rgvarg[3].intVal);

		}
		*/
		


		else if (dispIdMember == ID_OnIncomingCall){		printf("\n\nRaised OnIncomingCall(). \n");

			printf(" sink, id: %d, parm : %d . \n", dispIdMember, pDispParams->rgvarg[0].intVal);

		}
		else if (dispIdMember == ID_OnJsonIncomingCall){	printf("\n\nRaised OnJsonIncomingCall(). \n");

			printf(" sink, id: %d, parm : %d . \n", dispIdMember, pDispParams->rgvarg[0].intVal);

			_bstr_t bOnJsonIncomingCall						    = pDispParams->rgvarg[1].bstrVal;
			char* lpszOnJsonIncomingCall						= bOnJsonIncomingCall;
			printf(" sink, id: %d, parm : %s . \n", dispIdMember, lpszOnJsonIncomingCall);

			printf(" sink, id: %d, parm : %d . \n", dispIdMember, pDispParams->rgvarg[2].intVal);
		}



		else if (dispIdMember == ID_OnTestJsonString){		printf("\n\nRaised OnPassJsonString(). \n");

			_bstr_t bOnPassJsonString							= pDispParams->rgvarg[0].bstrVal;
			char* lpszOnPassJsonString							= bOnPassJsonString;
			printf(" sink, id: %d, parm : %s . \n", dispIdMember, lpszOnPassJsonString);

		}


        return S_OK;
    }
};


CComModule m_commodule;
int _tmain(int argc, _TCHAR* argv[])
{
	CoInitializeEx(0, COINIT_APARTMENTTHREADED);

    {
        CComPtr<IFocusSip> spFocusSip;
        spFocusSip.CoCreateInstance(CLSID_FocusSip, NULL, CLSCTX_INPROC_SERVER);

        CComObject<CSink>* sinkptr = NULL; //nullptr;
        CComObject<CSink>::CreateInstance(&sinkptr);

        DWORD cookies = 0;

        AtlAdvise(spFocusSip, sinkptr, __uuidof(_IFocusSipEvents), &cookies);

		BSTR Gret = ::SysAllocString( L"" );

		Fs_Stat ret;
		spFocusSip->app_construct( &ret);

        spFocusSip->aboutbox(&Gret);
		// ��������� printf��Ϣ, ʹ����ATL���������Ĳ���ֵ
		// ���ﷵ���� www.focustar.net

		system("pause");

    }
	CoUninitialize();
	return 0;
}
