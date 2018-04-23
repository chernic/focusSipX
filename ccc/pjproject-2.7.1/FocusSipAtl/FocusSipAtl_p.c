

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "FocusSipAtl_i.h"

#define TYPE_FORMAT_STRING_SIZE   1199                              
#define PROC_FORMAT_STRING_SIZE   1537                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _FocusSipAtl_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } FocusSipAtl_MIDL_TYPE_FORMAT_STRING;

typedef struct _FocusSipAtl_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } FocusSipAtl_MIDL_PROC_FORMAT_STRING;

typedef struct _FocusSipAtl_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } FocusSipAtl_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const FocusSipAtl_MIDL_TYPE_FORMAT_STRING FocusSipAtl__MIDL_TypeFormatString;
extern const FocusSipAtl_MIDL_PROC_FORMAT_STRING FocusSipAtl__MIDL_ProcFormatString;
extern const FocusSipAtl_MIDL_EXPR_FORMAT_STRING FocusSipAtl__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IComponentRegistrar_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IComponentRegistrar_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFocusSip_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFocusSip_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const FocusSipAtl_MIDL_PROC_FORMAT_STRING FocusSipAtl__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Attach */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x1 ),	/* 1 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrPath */

/* 24 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterAll */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnregisterAll */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x9 ),	/* 9 */
/* 74 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 82 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 90 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetComponents */

/* 96 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 98 */	NdrFcLong( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0xa ),	/* 10 */
/* 104 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 110 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 112 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 114 */	NdrFcShort( 0xb3 ),	/* 179 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbstrCLSIDs */

/* 120 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 122 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 124 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Parameter pbstrDescriptions */

/* 126 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 128 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 130 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Return value */

/* 132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 134 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterComponent */

/* 138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0xb ),	/* 11 */
/* 146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 152 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 154 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x1 ),	/* 1 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCLSID */

/* 162 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 166 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnregisterComponent */

/* 174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0xc ),	/* 12 */
/* 182 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 190 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrCLSID */

/* 198 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 202 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure aboutbox */

/* 210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x7 ),	/* 7 */
/* 218 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 224 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 226 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 228 */	NdrFcShort( 0x1 ),	/* 1 */
/* 230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ret */

/* 234 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 238 */	NdrFcShort( 0x42c ),	/* Type Offset=1068 */

	/* Return value */

/* 240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_construct */

/* 246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x24 ),	/* 36 */
/* 260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 262 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 270 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 278 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_destroy */

/* 282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x9 ),	/* 9 */
/* 290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x24 ),	/* 36 */
/* 296 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 298 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 306 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 308 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 314 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_create */

/* 318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0xa ),	/* 10 */
/* 326 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x24 ),	/* 36 */
/* 332 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 334 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 342 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 344 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_init */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0xb ),	/* 11 */
/* 362 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x24 ),	/* 36 */
/* 368 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 370 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 378 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 380 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 386 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_start */

/* 390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0xc ),	/* 12 */
/* 398 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x24 ),	/* 36 */
/* 404 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 406 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 414 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 416 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 422 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_default_config */

/* 426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0xd ),	/* 13 */
/* 434 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x24 ),	/* 36 */
/* 440 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 442 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 450 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 452 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 458 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_test_config */

/* 462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0xe ),	/* 14 */
/* 470 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x24 ),	/* 36 */
/* 476 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 478 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 486 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 488 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 492 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 494 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_get_count */

/* 498 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0xf ),	/* 15 */
/* 506 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x24 ),	/* 36 */
/* 512 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 514 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCount */

/* 522 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 524 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_get_info */

/* 534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x10 ),	/* 16 */
/* 542 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 546 */	NdrFcShort( 0x24 ),	/* 36 */
/* 548 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 550 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 552 */	NdrFcShort( 0xb ),	/* 11 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 560 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInfo */

/* 564 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 566 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 568 */	NdrFcShort( 0x43e ),	/* Type Offset=1086 */

	/* Parameter retStatus */

/* 570 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 572 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_add_short */

/* 582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x11 ),	/* 17 */
/* 590 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x24 ),	/* 36 */
/* 596 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 598 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x58 ),	/* 88 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pconfig */

/* 606 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 610 */	NdrFcShort( 0x46a ),	/* Type Offset=1130 */

	/* Parameter retStatus */

/* 612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 620 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_add */

/* 624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x12 ),	/* 18 */
/* 632 */	NdrFcShort( 0x58 ),	/* x86 Stack size/offset = 88 */
/* 634 */	NdrFcShort( 0x30 ),	/* 48 */
/* 636 */	NdrFcShort( 0x40 ),	/* 64 */
/* 638 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x15,		/* 21 */
/* 640 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x85 ),	/* 133 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter _01label */

/* 648 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 650 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 652 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _02server */

/* 654 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 656 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 658 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _03proxy */

/* 660 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 664 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _04username */

/* 666 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 668 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 670 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _05domain */

/* 672 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 674 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 676 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _06port */

/* 678 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 680 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter _07authID */

/* 684 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 686 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 688 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _08password */

/* 690 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 692 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 694 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _09rememberPassword */

/* 696 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 698 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter _10displayName */

/* 702 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 704 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 706 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _11voicemailNumber */

/* 708 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 710 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 712 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _12srtp */

/* 714 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 716 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 718 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _13transport */

/* 720 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 722 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 724 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _14publicAddr */

/* 726 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 728 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 730 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _15publish */

/* 732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 734 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter _16ice */

/* 738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 740 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter _17allowRewrite */

/* 744 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 746 */	NdrFcShort( 0x44 ),	/* x86 Stack size/offset = 68 */
/* 748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter _18disableSessionTimer */

/* 750 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 752 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 756 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 758 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAcc_Index */

/* 762 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 764 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 770 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
/* 772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_set_online_status */

/* 774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x13 ),	/* 19 */
/* 782 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 784 */	NdrFcShort( 0x10 ),	/* 16 */
/* 786 */	NdrFcShort( 0x24 ),	/* 36 */
/* 788 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 790 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 798 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 800 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter is_online */

/* 804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 806 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 810 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 812 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 818 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_set_registration */

/* 822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0x14 ),	/* 20 */
/* 830 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 832 */	NdrFcShort( 0x10 ),	/* 16 */
/* 834 */	NdrFcShort( 0x24 ),	/* 36 */
/* 836 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 838 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 848 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reg_active */

/* 852 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 854 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 858 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 860 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 866 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_del */

/* 870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x15 ),	/* 21 */
/* 878 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 882 */	NdrFcShort( 0x24 ),	/* 36 */
/* 884 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 886 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 894 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 896 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 900 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 908 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_get_max_count */

/* 912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x16 ),	/* 22 */
/* 920 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x24 ),	/* 36 */
/* 926 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 928 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retCount */

/* 936 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 944 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_get_count */

/* 948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0x17 ),	/* 23 */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x24 ),	/* 36 */
/* 962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 964 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retCount */

/* 972 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_is_active */

/* 984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x18 ),	/* 24 */
/* 992 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 996 */	NdrFcShort( 0x24 ),	/* 36 */
/* 998 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1000 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter callIndex */

/* 1008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1010 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1014 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1016 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_has_media */

/* 1026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1034 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1038 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1040 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1042 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter callIndex */

/* 1050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1056 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_get_info */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1076 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1080 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1082 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1084 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1086 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter callIndex */

/* 1092 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1094 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInfo */

/* 1098 */	NdrFcShort( 0xe113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=56 */
/* 1100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1102 */	NdrFcShort( 0x48c ),	/* Type Offset=1164 */

	/* Parameter retStatus */

/* 1104 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1106 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1112 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_make_call_short */

/* 1116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1124 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1128 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1130 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1132 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Uri */

/* 1140 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1144 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter hasVideo */

/* 1146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter RetCallID */

/* 1152 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1160 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_make_call */

/* 1164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1170 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1172 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1176 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1178 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1180 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1184 */	NdrFcShort( 0x46 ),	/* 70 */
/* 1186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter _21callId */

/* 1188 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1192 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _22numb */

/* 1194 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1198 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _23number */

/* 1200 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1202 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1204 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _24Para */

/* 1206 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1208 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1210 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter _25name */

/* 1212 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1214 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1216 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter hasVideo */

/* 1218 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1220 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter RetCallID */

/* 1224 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1226 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1232 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_answer */

/* 1236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1242 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1244 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1246 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1248 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1250 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1252 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter callIndex */

/* 1260 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1262 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter status_code */

/* 1266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1268 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 1272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1274 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_hangup */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1292 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1294 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1296 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1298 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1300 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0xe ),	/* 14 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter callIndex */

/* 1308 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter code */

/* 1314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1316 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reason */

/* 1320 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1324 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter retStatus */

/* 1326 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1328 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1332 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1334 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_hangup_all */

/* 1338 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1340 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1344 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1352 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1354 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1360 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1364 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_set_hold */

/* 1368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1376 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1380 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1382 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1384 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter callIndex */

/* 1392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1394 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 1398 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1400 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1406 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_release_hold */

/* 1410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1418 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1422 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1424 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1426 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1432 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter callIndex */

/* 1434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1436 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 1440 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1442 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure vid_win_set_overlay_mode */

/* 1452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1458 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1460 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1464 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1466 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1468 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mode */

/* 1476 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1478 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 1482 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1490 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure vid_win_resize */

/* 1494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1502 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1504 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1506 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1508 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1510 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter present */

/* 1518 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1520 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1522 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter retStatus */

/* 1524 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1526 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1532 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const FocusSipAtl_MIDL_TYPE_FORMAT_STRING FocusSipAtl__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0xe ),	/* Offset= 14 (18) */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 14 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 16 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 18 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 20 */	NdrFcShort( 0x8 ),	/* 8 */
/* 22 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (6) */
/* 24 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 26 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 28 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x4 ),	/* 4 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0xffde ),	/* Offset= -34 (2) */
/* 38 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 40 */	NdrFcShort( 0x3f6 ),	/* Offset= 1014 (1054) */
/* 42 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 44 */	NdrFcShort( 0x2 ),	/* Offset= 2 (46) */
/* 46 */	
			0x13, 0x0,	/* FC_OP */
/* 48 */	NdrFcShort( 0x3dc ),	/* Offset= 988 (1036) */
/* 50 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 52 */	NdrFcShort( 0x18 ),	/* 24 */
/* 54 */	NdrFcShort( 0xa ),	/* 10 */
/* 56 */	NdrFcLong( 0x8 ),	/* 8 */
/* 60 */	NdrFcShort( 0x5a ),	/* Offset= 90 (150) */
/* 62 */	NdrFcLong( 0xd ),	/* 13 */
/* 66 */	NdrFcShort( 0x90 ),	/* Offset= 144 (210) */
/* 68 */	NdrFcLong( 0x9 ),	/* 9 */
/* 72 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (266) */
/* 74 */	NdrFcLong( 0xc ),	/* 12 */
/* 78 */	NdrFcShort( 0x2c0 ),	/* Offset= 704 (782) */
/* 80 */	NdrFcLong( 0x24 ),	/* 36 */
/* 84 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (830) */
/* 86 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 90 */	NdrFcShort( 0x306 ),	/* Offset= 774 (864) */
/* 92 */	NdrFcLong( 0x10 ),	/* 16 */
/* 96 */	NdrFcShort( 0x320 ),	/* Offset= 800 (896) */
/* 98 */	NdrFcLong( 0x2 ),	/* 2 */
/* 102 */	NdrFcShort( 0x33a ),	/* Offset= 826 (928) */
/* 104 */	NdrFcLong( 0x3 ),	/* 3 */
/* 108 */	NdrFcShort( 0x354 ),	/* Offset= 852 (960) */
/* 110 */	NdrFcLong( 0x14 ),	/* 20 */
/* 114 */	NdrFcShort( 0x36e ),	/* Offset= 878 (992) */
/* 116 */	NdrFcShort( 0xffff ),	/* Offset= -1 (115) */
/* 118 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 120 */	NdrFcShort( 0x4 ),	/* 4 */
/* 122 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 128 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 130 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 132 */	NdrFcShort( 0x4 ),	/* 4 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x1 ),	/* 1 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	0x13, 0x0,	/* FC_OP */
/* 144 */	NdrFcShort( 0xff82 ),	/* Offset= -126 (18) */
/* 146 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 148 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 150 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 154 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 156 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 158 */	NdrFcShort( 0x4 ),	/* 4 */
/* 160 */	NdrFcShort( 0x4 ),	/* 4 */
/* 162 */	0x11, 0x0,	/* FC_RP */
/* 164 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (118) */
/* 166 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 168 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 170 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 182 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 184 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 186 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 188 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 198 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 202 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 204 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 206 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (170) */
/* 208 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 210 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x6 ),	/* Offset= 6 (222) */
/* 218 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 220 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 222 */	
			0x11, 0x0,	/* FC_RP */
/* 224 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (188) */
/* 226 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 228 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 238 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 240 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 242 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 244 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 254 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 258 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 260 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 262 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (226) */
/* 264 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 266 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x6 ),	/* Offset= 6 (278) */
/* 274 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 276 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 278 */	
			0x11, 0x0,	/* FC_RP */
/* 280 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (244) */
/* 282 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 284 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 286 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 288 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 290 */	NdrFcShort( 0x2 ),	/* Offset= 2 (292) */
/* 292 */	NdrFcShort( 0x10 ),	/* 16 */
/* 294 */	NdrFcShort( 0x2f ),	/* 47 */
/* 296 */	NdrFcLong( 0x14 ),	/* 20 */
/* 300 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 302 */	NdrFcLong( 0x3 ),	/* 3 */
/* 306 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 308 */	NdrFcLong( 0x11 ),	/* 17 */
/* 312 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 314 */	NdrFcLong( 0x2 ),	/* 2 */
/* 318 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 320 */	NdrFcLong( 0x4 ),	/* 4 */
/* 324 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 326 */	NdrFcLong( 0x5 ),	/* 5 */
/* 330 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 332 */	NdrFcLong( 0xb ),	/* 11 */
/* 336 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 338 */	NdrFcLong( 0xa ),	/* 10 */
/* 342 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 344 */	NdrFcLong( 0x6 ),	/* 6 */
/* 348 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (580) */
/* 350 */	NdrFcLong( 0x7 ),	/* 7 */
/* 354 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 356 */	NdrFcLong( 0x8 ),	/* 8 */
/* 360 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (586) */
/* 362 */	NdrFcLong( 0xd ),	/* 13 */
/* 366 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (170) */
/* 368 */	NdrFcLong( 0x9 ),	/* 9 */
/* 372 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (226) */
/* 374 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 378 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (590) */
/* 380 */	NdrFcLong( 0x24 ),	/* 36 */
/* 384 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (598) */
/* 386 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 390 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (598) */
/* 392 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 396 */	NdrFcShort( 0x100 ),	/* Offset= 256 (652) */
/* 398 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 402 */	NdrFcShort( 0xfe ),	/* Offset= 254 (656) */
/* 404 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 408 */	NdrFcShort( 0xfc ),	/* Offset= 252 (660) */
/* 410 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 414 */	NdrFcShort( 0xfa ),	/* Offset= 250 (664) */
/* 416 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 420 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (668) */
/* 422 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 426 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (672) */
/* 428 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 432 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (656) */
/* 434 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 438 */	NdrFcShort( 0xde ),	/* Offset= 222 (660) */
/* 440 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 444 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (676) */
/* 446 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 450 */	NdrFcShort( 0xde ),	/* Offset= 222 (672) */
/* 452 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 456 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (680) */
/* 458 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 462 */	NdrFcShort( 0xde ),	/* Offset= 222 (684) */
/* 464 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 468 */	NdrFcShort( 0xdc ),	/* Offset= 220 (688) */
/* 470 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 474 */	NdrFcShort( 0xda ),	/* Offset= 218 (692) */
/* 476 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 480 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (704) */
/* 482 */	NdrFcLong( 0x10 ),	/* 16 */
/* 486 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 488 */	NdrFcLong( 0x12 ),	/* 18 */
/* 492 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 494 */	NdrFcLong( 0x13 ),	/* 19 */
/* 498 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 500 */	NdrFcLong( 0x15 ),	/* 21 */
/* 504 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 506 */	NdrFcLong( 0x16 ),	/* 22 */
/* 510 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 512 */	NdrFcLong( 0x17 ),	/* 23 */
/* 516 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 518 */	NdrFcLong( 0xe ),	/* 14 */
/* 522 */	NdrFcShort( 0xbe ),	/* Offset= 190 (712) */
/* 524 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 528 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (722) */
/* 530 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 534 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (726) */
/* 536 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 540 */	NdrFcShort( 0x74 ),	/* Offset= 116 (656) */
/* 542 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 546 */	NdrFcShort( 0x72 ),	/* Offset= 114 (660) */
/* 548 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 552 */	NdrFcShort( 0x70 ),	/* Offset= 112 (664) */
/* 554 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 558 */	NdrFcShort( 0x66 ),	/* Offset= 102 (660) */
/* 560 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 564 */	NdrFcShort( 0x60 ),	/* Offset= 96 (660) */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x0 ),	/* Offset= 0 (570) */
/* 572 */	NdrFcLong( 0x1 ),	/* 1 */
/* 576 */	NdrFcShort( 0x0 ),	/* Offset= 0 (576) */
/* 578 */	NdrFcShort( 0xffff ),	/* Offset= -1 (577) */
/* 580 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 582 */	NdrFcShort( 0x8 ),	/* 8 */
/* 584 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 586 */	
			0x13, 0x0,	/* FC_OP */
/* 588 */	NdrFcShort( 0xfdc6 ),	/* Offset= -570 (18) */
/* 590 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 592 */	NdrFcShort( 0x2 ),	/* Offset= 2 (594) */
/* 594 */	
			0x13, 0x0,	/* FC_OP */
/* 596 */	NdrFcShort( 0x1b8 ),	/* Offset= 440 (1036) */
/* 598 */	
			0x13, 0x0,	/* FC_OP */
/* 600 */	NdrFcShort( 0x20 ),	/* Offset= 32 (632) */
/* 602 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 604 */	NdrFcLong( 0x2f ),	/* 47 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 612 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 614 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 616 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 618 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 620 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 622 */	NdrFcShort( 0x1 ),	/* 1 */
/* 624 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 626 */	NdrFcShort( 0x4 ),	/* 4 */
/* 628 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 630 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 632 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 634 */	NdrFcShort( 0x10 ),	/* 16 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0xa ),	/* Offset= 10 (648) */
/* 640 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 642 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 644 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (602) */
/* 646 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 648 */	
			0x13, 0x0,	/* FC_OP */
/* 650 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (620) */
/* 652 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 654 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 656 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 658 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 660 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 662 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 664 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 666 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 668 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 670 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 672 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 674 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 676 */	
			0x13, 0x0,	/* FC_OP */
/* 678 */	NdrFcShort( 0xff9e ),	/* Offset= -98 (580) */
/* 680 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 682 */	NdrFcShort( 0xffa0 ),	/* Offset= -96 (586) */
/* 684 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 686 */	NdrFcShort( 0xfdfc ),	/* Offset= -516 (170) */
/* 688 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 690 */	NdrFcShort( 0xfe30 ),	/* Offset= -464 (226) */
/* 692 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 694 */	NdrFcShort( 0x2 ),	/* Offset= 2 (696) */
/* 696 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 698 */	NdrFcShort( 0x2 ),	/* Offset= 2 (700) */
/* 700 */	
			0x13, 0x0,	/* FC_OP */
/* 702 */	NdrFcShort( 0x14e ),	/* Offset= 334 (1036) */
/* 704 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 706 */	NdrFcShort( 0x2 ),	/* Offset= 2 (708) */
/* 708 */	
			0x13, 0x0,	/* FC_OP */
/* 710 */	NdrFcShort( 0x14 ),	/* Offset= 20 (730) */
/* 712 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 714 */	NdrFcShort( 0x10 ),	/* 16 */
/* 716 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 718 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 720 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 722 */	
			0x13, 0x0,	/* FC_OP */
/* 724 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (712) */
/* 726 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 728 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 730 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 732 */	NdrFcShort( 0x20 ),	/* 32 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* Offset= 0 (736) */
/* 738 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 740 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 742 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 744 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 746 */	NdrFcShort( 0xfe30 ),	/* Offset= -464 (282) */
/* 748 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 750 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 752 */	NdrFcShort( 0x4 ),	/* 4 */
/* 754 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 760 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 762 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 764 */	NdrFcShort( 0x4 ),	/* 4 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x1 ),	/* 1 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	0x13, 0x0,	/* FC_OP */
/* 776 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (730) */
/* 778 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 780 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 782 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 784 */	NdrFcShort( 0x8 ),	/* 8 */
/* 786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 788 */	NdrFcShort( 0x6 ),	/* Offset= 6 (794) */
/* 790 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 792 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 794 */	
			0x11, 0x0,	/* FC_RP */
/* 796 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (750) */
/* 798 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 800 */	NdrFcShort( 0x4 ),	/* 4 */
/* 802 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 806 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 808 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 810 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 812 */	NdrFcShort( 0x4 ),	/* 4 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x1 ),	/* 1 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	0x13, 0x0,	/* FC_OP */
/* 824 */	NdrFcShort( 0xff40 ),	/* Offset= -192 (632) */
/* 826 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 828 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 830 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 836 */	NdrFcShort( 0x6 ),	/* Offset= 6 (842) */
/* 838 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 840 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 842 */	
			0x11, 0x0,	/* FC_RP */
/* 844 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (798) */
/* 846 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 848 */	NdrFcShort( 0x8 ),	/* 8 */
/* 850 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 852 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 854 */	NdrFcShort( 0x10 ),	/* 16 */
/* 856 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 858 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 860 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (846) */
			0x5b,		/* FC_END */
/* 864 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 866 */	NdrFcShort( 0x18 ),	/* 24 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0xa ),	/* Offset= 10 (880) */
/* 872 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 874 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 876 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (852) */
/* 878 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 880 */	
			0x11, 0x0,	/* FC_RP */
/* 882 */	NdrFcShort( 0xfd4a ),	/* Offset= -694 (188) */
/* 884 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 886 */	NdrFcShort( 0x1 ),	/* 1 */
/* 888 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 894 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 896 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 902 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 904 */	NdrFcShort( 0x4 ),	/* 4 */
/* 906 */	NdrFcShort( 0x4 ),	/* 4 */
/* 908 */	0x13, 0x0,	/* FC_OP */
/* 910 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (884) */
/* 912 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 914 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 916 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 918 */	NdrFcShort( 0x2 ),	/* 2 */
/* 920 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 926 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 928 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 934 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 936 */	NdrFcShort( 0x4 ),	/* 4 */
/* 938 */	NdrFcShort( 0x4 ),	/* 4 */
/* 940 */	0x13, 0x0,	/* FC_OP */
/* 942 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (916) */
/* 944 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 946 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 948 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 950 */	NdrFcShort( 0x4 ),	/* 4 */
/* 952 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 958 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 960 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 964 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 966 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 968 */	NdrFcShort( 0x4 ),	/* 4 */
/* 970 */	NdrFcShort( 0x4 ),	/* 4 */
/* 972 */	0x13, 0x0,	/* FC_OP */
/* 974 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (948) */
/* 976 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 978 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 980 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 982 */	NdrFcShort( 0x8 ),	/* 8 */
/* 984 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 988 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 990 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 992 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 996 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 998 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1000 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1002 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1004 */	0x13, 0x0,	/* FC_OP */
/* 1006 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (980) */
/* 1008 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1010 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1012 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1016 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1018 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1020 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1024 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1026 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1028 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1030 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1032 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1012) */
/* 1034 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1036 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1038 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1040 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1020) */
/* 1042 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1042) */
/* 1044 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1046 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1048 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1050 */	NdrFcShort( 0xfc18 ),	/* Offset= -1000 (50) */
/* 1052 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1054 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1056 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1058 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0xfc04 ),	/* Offset= -1020 (42) */
/* 1064 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1066 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1068) */
/* 1068 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0xfe16 ),	/* Offset= -490 (586) */
/* 1078 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1080 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1082 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1084 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1086) */
/* 1086 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1088 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1092) */
/* 1094 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1096 */	0x0,		/* 0 */
			NdrFcShort( 0xffe3 ),	/* Offset= -29 (1068) */
			0x8,		/* FC_LONG */
/* 1100 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1102 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1104 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1068) */
/* 1106 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1108 */	
			0x11, 0x0,	/* FC_RP */
/* 1110 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1130) */
/* 1112 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1114 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1116) */
/* 1116 */	
			0x12, 0x0,	/* FC_UP */
/* 1118 */	NdrFcShort( 0xffae ),	/* Offset= -82 (1036) */
/* 1120 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1122 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1124 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (1112) */
/* 1130 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1132 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1136) */
/* 1138 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1140 */	NdrFcShort( 0xfba8 ),	/* Offset= -1112 (28) */
/* 1142 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1144 */	NdrFcShort( 0xfba4 ),	/* Offset= -1116 (28) */
/* 1146 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1148 */	NdrFcShort( 0xfba0 ),	/* Offset= -1120 (28) */
/* 1150 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1152 */	NdrFcShort( 0xfb9c ),	/* Offset= -1124 (28) */
/* 1154 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1156 */	0x0,		/* 0 */
			NdrFcShort( 0xffdb ),	/* Offset= -37 (1120) */
			0x5b,		/* FC_END */
/* 1160 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1162 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1164) */
/* 1164 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1166 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1170 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1170) */
/* 1172 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1174 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1176 */	0x0,		/* 0 */
			NdrFcShort( 0xff93 ),	/* Offset= -109 (1068) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1180 */	0x0,		/* 0 */
			NdrFcShort( 0xff8f ),	/* Offset= -113 (1068) */
			0x8,		/* FC_LONG */
/* 1184 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1186 */	NdrFcShort( 0xff8a ),	/* Offset= -118 (1068) */
/* 1188 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1190 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1192 */	0x0,		/* 0 */
			NdrFcShort( 0xff83 ),	/* Offset= -125 (1068) */
			0x8,		/* FC_LONG */
/* 1196 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            }

        };



/* Standard interface: __MIDL_itf_FocusSipAtl_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IComponentRegistrar, ver. 0.0,
   GUID={0xa817e7a2,0x43fa,0x11d0,{0x9e,0x44,0x00,0xaa,0x00,0xb6,0x77,0x0a}} */

#pragma code_seg(".orpc")
static const unsigned short IComponentRegistrar_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    66,
    96,
    138,
    174
    };

static const MIDL_STUBLESS_PROXY_INFO IComponentRegistrar_ProxyInfo =
    {
    &Object_StubDesc,
    FocusSipAtl__MIDL_ProcFormatString.Format,
    &IComponentRegistrar_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IComponentRegistrar_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FocusSipAtl__MIDL_ProcFormatString.Format,
    &IComponentRegistrar_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IComponentRegistrarProxyVtbl = 
{
    &IComponentRegistrar_ProxyInfo,
    &IID_IComponentRegistrar,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IComponentRegistrar::Attach */ ,
    (void *) (INT_PTR) -1 /* IComponentRegistrar::RegisterAll */ ,
    (void *) (INT_PTR) -1 /* IComponentRegistrar::UnregisterAll */ ,
    (void *) (INT_PTR) -1 /* IComponentRegistrar::GetComponents */ ,
    (void *) (INT_PTR) -1 /* IComponentRegistrar::RegisterComponent */ ,
    (void *) (INT_PTR) -1 /* IComponentRegistrar::UnregisterComponent */
};


static const PRPC_STUB_FUNCTION IComponentRegistrar_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IComponentRegistrarStubVtbl =
{
    &IID_IComponentRegistrar,
    &IComponentRegistrar_ServerInfo,
    13,
    &IComponentRegistrar_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFocusSip, ver. 0.0,
   GUID={0x9A1199F0,0x327A,0x4952,{0x99,0x6B,0xA4,0x55,0x2F,0x0E,0x7C,0x8C}} */

#pragma code_seg(".orpc")
static const unsigned short IFocusSip_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    210,
    246,
    282,
    318,
    354,
    390,
    426,
    462,
    498,
    534,
    582,
    624,
    774,
    822,
    870,
    912,
    948,
    984,
    1026,
    1068,
    1116,
    1164,
    1236,
    1284,
    1338,
    1368,
    1410,
    1452,
    1494
    };

static const MIDL_STUBLESS_PROXY_INFO IFocusSip_ProxyInfo =
    {
    &Object_StubDesc,
    FocusSipAtl__MIDL_ProcFormatString.Format,
    &IFocusSip_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFocusSip_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FocusSipAtl__MIDL_ProcFormatString.Format,
    &IFocusSip_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(36) _IFocusSipProxyVtbl = 
{
    &IFocusSip_ProxyInfo,
    &IID_IFocusSip,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::aboutbox */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::app_construct */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::app_destroy */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::app_create */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::app_init */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::app_start */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::app_default_config */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::app_test_config */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::acc_get_count */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::acc_get_info */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::acc_add_short */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::acc_add */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::acc_set_online_status */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::acc_set_registration */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::acc_del */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_get_max_count */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_get_count */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_is_active */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_has_media */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_get_info */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_make_call_short */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_make_call */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_answer */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_hangup */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_hangup_all */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_set_hold */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::call_release_hold */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::vid_win_set_overlay_mode */ ,
    (void *) (INT_PTR) -1 /* IFocusSip::vid_win_resize */
};


static const PRPC_STUB_FUNCTION IFocusSip_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFocusSipStubVtbl =
{
    &IID_IFocusSip,
    &IFocusSip_ServerInfo,
    36,
    &IFocusSip_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    FocusSipAtl__MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _FocusSipAtl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IComponentRegistrarProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFocusSipProxyVtbl,
    0
};

const CInterfaceStubVtbl * _FocusSipAtl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IComponentRegistrarStubVtbl,
    ( CInterfaceStubVtbl *) &_IFocusSipStubVtbl,
    0
};

PCInterfaceName const _FocusSipAtl_InterfaceNamesList[] = 
{
    "IComponentRegistrar",
    "IFocusSip",
    0
};

const IID *  _FocusSipAtl_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _FocusSipAtl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _FocusSipAtl, pIID, n)

int __stdcall _FocusSipAtl_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _FocusSipAtl, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _FocusSipAtl, 2, *pIndex )
    
}

const ExtendedProxyFileInfo FocusSipAtl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _FocusSipAtl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _FocusSipAtl_StubVtblList,
    (const PCInterfaceName * ) & _FocusSipAtl_InterfaceNamesList,
    (const IID ** ) & _FocusSipAtl_BaseIIDList,
    & _FocusSipAtl_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

