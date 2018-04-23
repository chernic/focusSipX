// FocusSipAtlmain.cpp : 定义控制台应用程序的入口点。
// 本文档示例在vs2008中测试通过

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
		使用VARIANT来传递参数意味着非强类型语言(例如VBScript)能够调用使用强类型语言(C++)实现的方法。

		https://www.cnblogs.com/caucyj/archive/2011/02/10/1950497.html
		VT_DISPATCH

		指定了一个指向对象的指针类型，值存放在pdispVal中。
		这个对象就是特制IDispatch接口实现的对象。这个对象能通过调用QueryInterface进行访问，
		不管它是否实现了其他需要的接口。那些没有实现IDispatch接口的对象，就需要把它传给VT_UNKNOWN

		VT_UNKNOWN
		指定一个存放在punkVal中的IUnknown实现对象的指针

		VT_UNKNOWN | VT_BYREF
		指定一个存放在ppunkVal中的指向IUnknown实现对象指针的指针。
		*/


		// 注意, 参数是从右往左传入
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
		// 这里输出了 printf信息, 使用了ATL所传过来的参数值
		// 这里返回了 www.focustar.net

		system("pause");

    }
	CoUninitialize();
	return 0;
}
