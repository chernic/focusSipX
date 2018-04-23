

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Apr 23 16:47:23 2018
 */
/* Compiler settings for .\FocusSipAtl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __FocusSipAtl_i_h__
#define __FocusSipAtl_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IComponentRegistrar_FWD_DEFINED__
#define __IComponentRegistrar_FWD_DEFINED__
typedef interface IComponentRegistrar IComponentRegistrar;
#endif 	/* __IComponentRegistrar_FWD_DEFINED__ */


#ifndef __IFocusSip_FWD_DEFINED__
#define __IFocusSip_FWD_DEFINED__
typedef interface IFocusSip IFocusSip;
#endif 	/* __IFocusSip_FWD_DEFINED__ */


#ifndef __CompReg_FWD_DEFINED__
#define __CompReg_FWD_DEFINED__

#ifdef __cplusplus
typedef class CompReg CompReg;
#else
typedef struct CompReg CompReg;
#endif /* __cplusplus */

#endif 	/* __CompReg_FWD_DEFINED__ */


#ifndef ___IFocusSipEvents_FWD_DEFINED__
#define ___IFocusSipEvents_FWD_DEFINED__
typedef interface _IFocusSipEvents _IFocusSipEvents;
#endif 	/* ___IFocusSipEvents_FWD_DEFINED__ */


#ifndef __FocusSip_FWD_DEFINED__
#define __FocusSip_FWD_DEFINED__

#ifdef __cplusplus
typedef class FocusSip FocusSip;
#else
typedef struct FocusSip FocusSip;
#endif /* __cplusplus */

#endif 	/* __FocusSip_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "focusua_structs.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_FocusSipAtl_0000_0000 */
/* [local] */ 

#define	ID_OnAboutBox	( 999 )

#define	ID_OnTestJsonString	( 100 )

#define	ID_OnCallState	( 1 )

#define	ID_OnJsonCallState	( 101 )

#define	ID_OnIncomingCall	( 2 )

#define	ID_OnJsonIncomingCall	( 102 )

#define	ID_OnTsxState	( 3 )

#define	ID_OnJsonTsxState	( 103 )

#define	ID_OnMediaState	( 4 )

#define	ID_OnJsonMediaState	( 104 )

#define	ID_OnStreamCreated2	( 7 )

#define	ID_OnJsonStreamCreated2	( 107 )

#define	ID_OnStreamDestroyed	( 8 )

#define	ID_OnJsonStreamDestroyed	( 108 )

#define	ID_OnRegState2	( 21 )

#define	ID_OnJsonRegState2	( 121 )

#define	ID_OnBuddyState	( 24 )

#define	ID_OnJsonBuddyState	( 124 )



extern RPC_IF_HANDLE __MIDL_itf_FocusSipAtl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_FocusSipAtl_0000_0000_v0_0_s_ifspec;

#ifndef __IComponentRegistrar_INTERFACE_DEFINED__
#define __IComponentRegistrar_INTERFACE_DEFINED__

/* interface IComponentRegistrar */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IComponentRegistrar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a817e7a2-43fa-11d0-9e44-00aa00b6770a")
    IComponentRegistrar : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ BSTR bstrPath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetComponents( 
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IComponentRegistrarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComponentRegistrar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComponentRegistrar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComponentRegistrar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComponentRegistrar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComponentRegistrar * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrPath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterAll )( 
            IComponentRegistrar * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterAll )( 
            IComponentRegistrar * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetComponents )( 
            IComponentRegistrar * This,
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        END_INTERFACE
    } IComponentRegistrarVtbl;

    interface IComponentRegistrar
    {
        CONST_VTBL struct IComponentRegistrarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComponentRegistrar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComponentRegistrar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComponentRegistrar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComponentRegistrar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IComponentRegistrar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IComponentRegistrar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IComponentRegistrar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IComponentRegistrar_Attach(This,bstrPath)	\
    ( (This)->lpVtbl -> Attach(This,bstrPath) ) 

#define IComponentRegistrar_RegisterAll(This)	\
    ( (This)->lpVtbl -> RegisterAll(This) ) 

#define IComponentRegistrar_UnregisterAll(This)	\
    ( (This)->lpVtbl -> UnregisterAll(This) ) 

#define IComponentRegistrar_GetComponents(This,pbstrCLSIDs,pbstrDescriptions)	\
    ( (This)->lpVtbl -> GetComponents(This,pbstrCLSIDs,pbstrDescriptions) ) 

#define IComponentRegistrar_RegisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> RegisterComponent(This,bstrCLSID) ) 

#define IComponentRegistrar_UnregisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> UnregisterComponent(This,bstrCLSID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComponentRegistrar_INTERFACE_DEFINED__ */


#ifndef __IFocusSip_INTERFACE_DEFINED__
#define __IFocusSip_INTERFACE_DEFINED__

/* interface IFocusSip */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFocusSip;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9A1199F0-327A-4952-996B-A4552F0E7C8C")
    IFocusSip : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE aboutbox( 
            /* [retval][out] */ Fs__Str *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE app_construct( 
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE app_destroy( 
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE app_create( 
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE app_init( 
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE app_start( 
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE app_default_config( 
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE app_test_config( 
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE acc_get_count( 
            /* [retval][out] */ Fs_Numb *pCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE acc_get_info( 
            /* [in] */ Fs_Numb acc_id,
            /* [out] */ Focusip_Acc_Info *pInfo,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE acc_add_short( 
            /* [in] */ Focusip_Acc_Config *pconfig,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE acc_add( 
            /* [in] */ Fs__Str _01label,
            /* [in] */ Fs__Str _02server,
            /* [in] */ Fs__Str _03proxy,
            /* [in] */ Fs__Str _04username,
            /* [in] */ Fs__Str _05domain,
            /* [in] */ Fs_Numb _06port,
            /* [in] */ Fs__Str _07authID,
            /* [in] */ Fs__Str _08password,
            /* [in] */ Fs_Numb _09rememberPassword,
            /* [in] */ Fs__Str _10displayName,
            /* [in] */ Fs__Str _11voicemailNumber,
            /* [in] */ Fs__Str _12srtp,
            /* [in] */ Fs__Str _13transport,
            /* [in] */ Fs__Str _14publicAddr,
            /* [in] */ Fs_Numb _15publish,
            /* [in] */ Fs_Numb _16ice,
            /* [in] */ Fs_Numb _17allowRewrite,
            /* [in] */ Fs_Numb _18disableSessionTimer,
            /* [out] */ Fs_Stat *retStatus,
            /* [retval][out] */ Fs_Numb *pAcc_Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE acc_set_online_status( 
            /* [in] */ Fs_Numb acc_id,
            /* [in] */ Fs_Numb is_online,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE acc_set_registration( 
            /* [in] */ Fs_Numb acc_id,
            /* [in] */ Fs_Numb reg_active,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE acc_del( 
            /* [in] */ Fs_Numb acc_id,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_get_max_count( 
            /* [retval][out] */ Fs_Numb *retCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_get_count( 
            /* [retval][out] */ Fs_Numb *retCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_is_active( 
            /* [in] */ Fs_Numb callIndex,
            /* [retval][out] */ Fs_Bool *pRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_has_media( 
            /* [in] */ Fs_Numb callIndex,
            /* [retval][out] */ Fs_Bool *pRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_get_info( 
            /* [in] */ Fs_Numb callIndex,
            /* [out] */ Focusip_Call_Info *pInfo,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_make_call_short( 
            /* [in] */ Fs__Str Uri,
            /* [in] */ Fs_Numb hasVideo,
            /* [retval][out] */ Fs_Numb *RetCallID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_make_call( 
            /* [in] */ Fs__Str _21callId,
            /* [in] */ Fs__Str _22numb,
            /* [in] */ Fs__Str _23number,
            /* [in] */ Fs__Str _24Para,
            /* [in] */ Fs__Str _25name,
            /* [in] */ Fs_Numb hasVideo,
            /* [retval][out] */ Fs_Numb *RetCallID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_answer( 
            /* [in] */ Fs_Numb callIndex,
            /* [in] */ Fs_Numb status_code,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_hangup( 
            /* [in] */ Fs_Numb callIndex,
            /* [in] */ Fs_Numb code,
            /* [in] */ Fs__Str reason,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_hangup_all( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_set_hold( 
            /* [in] */ Fs_Numb callIndex,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE call_release_hold( 
            /* [in] */ Fs_Numb callIndex,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vid_win_set_overlay_mode( 
            /* [in] */ Fs_Numb mode,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE vid_win_resize( 
            /* [in] */ Fs_Doub present,
            /* [retval][out] */ Fs_Stat *retStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFocusSipVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFocusSip * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFocusSip * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFocusSip * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFocusSip * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFocusSip * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFocusSip * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFocusSip * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *aboutbox )( 
            IFocusSip * This,
            /* [retval][out] */ Fs__Str *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *app_construct )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *app_destroy )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *app_create )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *app_init )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *app_start )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *app_default_config )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *app_test_config )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *acc_get_count )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Numb *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *acc_get_info )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb acc_id,
            /* [out] */ Focusip_Acc_Info *pInfo,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *acc_add_short )( 
            IFocusSip * This,
            /* [in] */ Focusip_Acc_Config *pconfig,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *acc_add )( 
            IFocusSip * This,
            /* [in] */ Fs__Str _01label,
            /* [in] */ Fs__Str _02server,
            /* [in] */ Fs__Str _03proxy,
            /* [in] */ Fs__Str _04username,
            /* [in] */ Fs__Str _05domain,
            /* [in] */ Fs_Numb _06port,
            /* [in] */ Fs__Str _07authID,
            /* [in] */ Fs__Str _08password,
            /* [in] */ Fs_Numb _09rememberPassword,
            /* [in] */ Fs__Str _10displayName,
            /* [in] */ Fs__Str _11voicemailNumber,
            /* [in] */ Fs__Str _12srtp,
            /* [in] */ Fs__Str _13transport,
            /* [in] */ Fs__Str _14publicAddr,
            /* [in] */ Fs_Numb _15publish,
            /* [in] */ Fs_Numb _16ice,
            /* [in] */ Fs_Numb _17allowRewrite,
            /* [in] */ Fs_Numb _18disableSessionTimer,
            /* [out] */ Fs_Stat *retStatus,
            /* [retval][out] */ Fs_Numb *pAcc_Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *acc_set_online_status )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb acc_id,
            /* [in] */ Fs_Numb is_online,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *acc_set_registration )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb acc_id,
            /* [in] */ Fs_Numb reg_active,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *acc_del )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb acc_id,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_get_max_count )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Numb *retCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_get_count )( 
            IFocusSip * This,
            /* [retval][out] */ Fs_Numb *retCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_is_active )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb callIndex,
            /* [retval][out] */ Fs_Bool *pRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_has_media )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb callIndex,
            /* [retval][out] */ Fs_Bool *pRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_get_info )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb callIndex,
            /* [out] */ Focusip_Call_Info *pInfo,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_make_call_short )( 
            IFocusSip * This,
            /* [in] */ Fs__Str Uri,
            /* [in] */ Fs_Numb hasVideo,
            /* [retval][out] */ Fs_Numb *RetCallID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_make_call )( 
            IFocusSip * This,
            /* [in] */ Fs__Str _21callId,
            /* [in] */ Fs__Str _22numb,
            /* [in] */ Fs__Str _23number,
            /* [in] */ Fs__Str _24Para,
            /* [in] */ Fs__Str _25name,
            /* [in] */ Fs_Numb hasVideo,
            /* [retval][out] */ Fs_Numb *RetCallID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_answer )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb callIndex,
            /* [in] */ Fs_Numb status_code,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_hangup )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb callIndex,
            /* [in] */ Fs_Numb code,
            /* [in] */ Fs__Str reason,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_hangup_all )( 
            IFocusSip * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_set_hold )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb callIndex,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *call_release_hold )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb callIndex,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vid_win_set_overlay_mode )( 
            IFocusSip * This,
            /* [in] */ Fs_Numb mode,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *vid_win_resize )( 
            IFocusSip * This,
            /* [in] */ Fs_Doub present,
            /* [retval][out] */ Fs_Stat *retStatus);
        
        END_INTERFACE
    } IFocusSipVtbl;

    interface IFocusSip
    {
        CONST_VTBL struct IFocusSipVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFocusSip_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFocusSip_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFocusSip_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFocusSip_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFocusSip_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFocusSip_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFocusSip_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFocusSip_aboutbox(This,ret)	\
    ( (This)->lpVtbl -> aboutbox(This,ret) ) 

#define IFocusSip_app_construct(This,retStatus)	\
    ( (This)->lpVtbl -> app_construct(This,retStatus) ) 

#define IFocusSip_app_destroy(This,retStatus)	\
    ( (This)->lpVtbl -> app_destroy(This,retStatus) ) 

#define IFocusSip_app_create(This,retStatus)	\
    ( (This)->lpVtbl -> app_create(This,retStatus) ) 

#define IFocusSip_app_init(This,retStatus)	\
    ( (This)->lpVtbl -> app_init(This,retStatus) ) 

#define IFocusSip_app_start(This,retStatus)	\
    ( (This)->lpVtbl -> app_start(This,retStatus) ) 

#define IFocusSip_app_default_config(This,retStatus)	\
    ( (This)->lpVtbl -> app_default_config(This,retStatus) ) 

#define IFocusSip_app_test_config(This,retStatus)	\
    ( (This)->lpVtbl -> app_test_config(This,retStatus) ) 

#define IFocusSip_acc_get_count(This,pCount)	\
    ( (This)->lpVtbl -> acc_get_count(This,pCount) ) 

#define IFocusSip_acc_get_info(This,acc_id,pInfo,retStatus)	\
    ( (This)->lpVtbl -> acc_get_info(This,acc_id,pInfo,retStatus) ) 

#define IFocusSip_acc_add_short(This,pconfig,retStatus)	\
    ( (This)->lpVtbl -> acc_add_short(This,pconfig,retStatus) ) 

#define IFocusSip_acc_add(This,_01label,_02server,_03proxy,_04username,_05domain,_06port,_07authID,_08password,_09rememberPassword,_10displayName,_11voicemailNumber,_12srtp,_13transport,_14publicAddr,_15publish,_16ice,_17allowRewrite,_18disableSessionTimer,retStatus,pAcc_Index)	\
    ( (This)->lpVtbl -> acc_add(This,_01label,_02server,_03proxy,_04username,_05domain,_06port,_07authID,_08password,_09rememberPassword,_10displayName,_11voicemailNumber,_12srtp,_13transport,_14publicAddr,_15publish,_16ice,_17allowRewrite,_18disableSessionTimer,retStatus,pAcc_Index) ) 

#define IFocusSip_acc_set_online_status(This,acc_id,is_online,retStatus)	\
    ( (This)->lpVtbl -> acc_set_online_status(This,acc_id,is_online,retStatus) ) 

#define IFocusSip_acc_set_registration(This,acc_id,reg_active,retStatus)	\
    ( (This)->lpVtbl -> acc_set_registration(This,acc_id,reg_active,retStatus) ) 

#define IFocusSip_acc_del(This,acc_id,retStatus)	\
    ( (This)->lpVtbl -> acc_del(This,acc_id,retStatus) ) 

#define IFocusSip_call_get_max_count(This,retCount)	\
    ( (This)->lpVtbl -> call_get_max_count(This,retCount) ) 

#define IFocusSip_call_get_count(This,retCount)	\
    ( (This)->lpVtbl -> call_get_count(This,retCount) ) 

#define IFocusSip_call_is_active(This,callIndex,pRet)	\
    ( (This)->lpVtbl -> call_is_active(This,callIndex,pRet) ) 

#define IFocusSip_call_has_media(This,callIndex,pRet)	\
    ( (This)->lpVtbl -> call_has_media(This,callIndex,pRet) ) 

#define IFocusSip_call_get_info(This,callIndex,pInfo,retStatus)	\
    ( (This)->lpVtbl -> call_get_info(This,callIndex,pInfo,retStatus) ) 

#define IFocusSip_call_make_call_short(This,Uri,hasVideo,RetCallID)	\
    ( (This)->lpVtbl -> call_make_call_short(This,Uri,hasVideo,RetCallID) ) 

#define IFocusSip_call_make_call(This,_21callId,_22numb,_23number,_24Para,_25name,hasVideo,RetCallID)	\
    ( (This)->lpVtbl -> call_make_call(This,_21callId,_22numb,_23number,_24Para,_25name,hasVideo,RetCallID) ) 

#define IFocusSip_call_answer(This,callIndex,status_code,retStatus)	\
    ( (This)->lpVtbl -> call_answer(This,callIndex,status_code,retStatus) ) 

#define IFocusSip_call_hangup(This,callIndex,code,reason,retStatus)	\
    ( (This)->lpVtbl -> call_hangup(This,callIndex,code,reason,retStatus) ) 

#define IFocusSip_call_hangup_all(This)	\
    ( (This)->lpVtbl -> call_hangup_all(This) ) 

#define IFocusSip_call_set_hold(This,callIndex,retStatus)	\
    ( (This)->lpVtbl -> call_set_hold(This,callIndex,retStatus) ) 

#define IFocusSip_call_release_hold(This,callIndex,retStatus)	\
    ( (This)->lpVtbl -> call_release_hold(This,callIndex,retStatus) ) 

#define IFocusSip_vid_win_set_overlay_mode(This,mode,retStatus)	\
    ( (This)->lpVtbl -> vid_win_set_overlay_mode(This,mode,retStatus) ) 

#define IFocusSip_vid_win_resize(This,present,retStatus)	\
    ( (This)->lpVtbl -> vid_win_resize(This,present,retStatus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFocusSip_INTERFACE_DEFINED__ */



#ifndef __FocusSipAtlLib_LIBRARY_DEFINED__
#define __FocusSipAtlLib_LIBRARY_DEFINED__

/* library FocusSipAtlLib */
/* [custom][helpstring][version][uuid] */ 











EXTERN_C const IID LIBID_FocusSipAtlLib;

EXTERN_C const CLSID CLSID_CompReg;

#ifdef __cplusplus

class DECLSPEC_UUID("194F9248-F190-4BF8-ADAD-6ED35F0B919D")
CompReg;
#endif

#ifndef ___IFocusSipEvents_DISPINTERFACE_DEFINED__
#define ___IFocusSipEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IFocusSipEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IFocusSipEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DC91CBCE-4B9E-4369-80B9-39341EEFD814")
    _IFocusSipEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IFocusSipEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IFocusSipEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IFocusSipEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IFocusSipEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IFocusSipEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IFocusSipEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IFocusSipEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IFocusSipEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IFocusSipEventsVtbl;

    interface _IFocusSipEvents
    {
        CONST_VTBL struct _IFocusSipEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IFocusSipEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IFocusSipEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IFocusSipEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IFocusSipEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IFocusSipEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IFocusSipEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IFocusSipEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IFocusSipEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FocusSip;

#ifdef __cplusplus

class DECLSPEC_UUID("15E1E788-3086-4B54-83C0-449EF56CD4EE")
FocusSip;
#endif
#endif /* __FocusSipAtlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


