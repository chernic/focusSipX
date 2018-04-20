

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Dec 15 17:40:55 2017
 */
/* Compiler settings for .\tinyAtlWin.idl:
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


MIDL_DEFINE_GUID(IID, IID_InoneWin,0x9830B9D6,0x2295,0x413A,0xAB,0xAD,0x85,0x52,0x63,0x39,0x1F,0x38);


MIDL_DEFINE_GUID(IID, LIBID_tinyAtlWinLib,0x31BC3635,0x9845,0x4C31,0xB1,0x40,0x2A,0xDB,0x73,0xA3,0x98,0x83);


MIDL_DEFINE_GUID(CLSID, CLSID_CompReg,0x53771816,0xFD4C,0x4FA9,0x99,0x6C,0x93,0x9E,0xDB,0x0F,0xD1,0xE9);


MIDL_DEFINE_GUID(IID, DIID__InoneWinEvents,0x8A4E5D16,0x62D7,0x471F,0xB4,0x48,0xAD,0x6F,0x11,0x28,0x69,0xE3);


MIDL_DEFINE_GUID(CLSID, CLSID_noneWin,0x8DE7F2C0,0xCED3,0x4C78,0xA0,0x5E,0xEC,0x72,0xCF,0xBA,0xF4,0xFE);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



