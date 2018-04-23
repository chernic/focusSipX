template<class T>
class CProxy_IFocusSipEvents :
	public IConnectionPointImpl<T, &__uuidof(_IFocusSipEvents)>
{
public:
	HRESULT Fire_OnAboutBox( FLOAT parmA,  FLOAT parmB)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[2];
				avarParams[1] = parmA;
				avarParams[1].vt = VT_R4;
				avarParams[0] = parmB;
				avarParams[0].vt = VT_R4;
				DISPPARAMS params = { avarParams, NULL, 2, 0 };
				hr = pConnection->Invoke(ID_OnAboutBox, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnTestJsonString( BSTR json)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[1];
				avarParams[0] = json;
				avarParams[0].vt = VT_BSTR;
				DISPPARAMS params = { avarParams, NULL, 1, 0 };
				hr = pConnection->Invoke(ID_OnTestJsonString, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnCallState( INT callIndex,  Focusip_Call_Info * cInfo)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[2];
				avarParams[1] = callIndex;
				avarParams[0] = cInfo;
				DISPPARAMS params = { avarParams, NULL, 2, 0 };
				hr = pConnection->Invoke(ID_OnCallState, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnJsonCallState( INT callIndex,  BSTR jsonData,  INT jsonSize)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[3];
				avarParams[2] = callIndex;
				avarParams[1] = jsonData;
				avarParams[1].vt = VT_BSTR;
				avarParams[0] = jsonSize;
				DISPPARAMS params = { avarParams, NULL, 3, 0 };
				hr = pConnection->Invoke(ID_OnJsonCallState, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnIncomingCall( INT callIndex)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[1];
				avarParams[0] = callIndex;
				DISPPARAMS params = { avarParams, NULL, 1, 0 };
				hr = pConnection->Invoke(ID_OnIncomingCall, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnJsonIncomingCall( INT callIndex,  BSTR jsonData,  INT jsonSize)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[3];
				avarParams[2] = callIndex;
				avarParams[1] = jsonData;
				avarParams[1].vt = VT_BSTR;
				avarParams[0] = jsonSize;
				DISPPARAMS params = { avarParams, NULL, 3, 0 };
				hr = pConnection->Invoke(ID_OnJsonIncomingCall, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnCallTsxState( INT callIndex)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[1];
				avarParams[0] = callIndex;
				DISPPARAMS params = { avarParams, NULL, 1, 0 };
				hr = pConnection->Invoke(ID_OnTsxState, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnJsonTsxState( INT callIndex,  BSTR jsonData,  INT jsonSize)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[3];
				avarParams[2] = callIndex;
				avarParams[1] = jsonData;
				avarParams[1].vt = VT_BSTR;
				avarParams[0] = jsonSize;
				DISPPARAMS params = { avarParams, NULL, 3, 0 };
				hr = pConnection->Invoke(ID_OnJsonTsxState, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnMediaState( INT callIndex)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[1];
				avarParams[0] = callIndex;
				DISPPARAMS params = { avarParams, NULL, 1, 0 };
				hr = pConnection->Invoke(ID_OnMediaState, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnJsonMediaState( INT callIndex,  BSTR jsonData,  INT jsonSize)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[3];
				avarParams[2] = callIndex;
				avarParams[1] = jsonData;
				avarParams[1].vt = VT_BSTR;
				avarParams[0] = jsonSize;
				DISPPARAMS params = { avarParams, NULL, 3, 0 };
				hr = pConnection->Invoke(ID_OnJsonMediaState, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnRegState2( INT accIndex,  Focusip_Reg_Info * rInfo)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[2];
				avarParams[1] = accIndex;
				avarParams[0] = rInfo;
				DISPPARAMS params = { avarParams, NULL, 2, 0 };
				hr = pConnection->Invoke(ID_OnRegState2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnJsonRegState2( INT accIndex,  BSTR jsonData,  INT jsonSize)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[3];
				avarParams[2] = accIndex;
				avarParams[1] = jsonData;
				avarParams[1].vt = VT_BSTR;
				avarParams[0] = jsonSize;
				DISPPARAMS params = { avarParams, NULL, 3, 0 };
				hr = pConnection->Invoke(ID_OnJsonRegState2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnBuddyState( INT buddyIndex,  Focusip_Buddy_Info * bInfo)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[2];
				avarParams[1] = buddyIndex;
				avarParams[0] = bInfo;
				DISPPARAMS params = { avarParams, NULL, 2, 0 };
				hr = pConnection->Invoke(ID_OnBuddyState, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
	HRESULT Fire_OnJsonBuddyState( INT buddyIndex,  BSTR jsonData,  INT jsonSize)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[3];
				avarParams[2] = buddyIndex;
				avarParams[1] = jsonData;
				avarParams[1].vt = VT_BSTR;
				avarParams[0] = jsonSize;
				DISPPARAMS params = { avarParams, NULL, 3, 0 };
				hr = pConnection->Invoke(ID_OnJsonBuddyState, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
};

