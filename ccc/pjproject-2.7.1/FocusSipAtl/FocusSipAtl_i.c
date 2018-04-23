

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IComponentRegistrar,0xa817e7a2,0x43fa,0x11d0,0x9e,0x44,0x00,0xaa,0x00,0xb6,0x77,0x0a);


MIDL_DEFINE_GUID(IID, IID_IFocusSip,0x9A1199F0,0x327A,0x4952,0x99,0x6B,0xA4,0x55,0x2F,0x0E,0x7C,0x8C);


MIDL_DEFINE_GUID(IID, LIBID_FocusSipAtlLib,0xE376B48B,0x83F4,0x4739,0xA2,0x58,0x99,0x3B,0xD0,0xBD,0x90,0x57);


MIDL_DEFINE_GUID(CLSID, CLSID_CompReg,0x194F9248,0xF190,0x4BF8,0xAD,0xAD,0x6E,0xD3,0x5F,0x0B,0x91,0x9D);


MIDL_DEFINE_GUID(IID, DIID__IFocusSipEvents,0xDC91CBCE,0x4B9E,0x4369,0x80,0xB9,0x39,0x34,0x1E,0xEF,0xD8,0x14);


MIDL_DEFINE_GUID(CLSID, CLSID_FocusSip,0x15E1E788,0x3086,0x4B54,0x83,0xC0,0x44,0x9E,0xF5,0x6C,0xD4,0xEE);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



