

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Nov 20 16:08:03 2017
 */
/* Compiler settings for ..\src\activex-video-agent\activex-video-agent.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
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


#include "activex-video-agent.h"

#define TYPE_FORMAT_STRING_SIZE   1389                              
#define PROC_FORMAT_STRING_SIZE   2503                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _activex2Dpjsua_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } activex2Dpjsua_MIDL_TYPE_FORMAT_STRING;

typedef struct _activex2Dpjsua_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } activex2Dpjsua_MIDL_PROC_FORMAT_STRING;

typedef struct _activex2Dpjsua_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } activex2Dpjsua_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const activex2Dpjsua_MIDL_TYPE_FORMAT_STRING activex2Dpjsua__MIDL_TypeFormatString;
extern const activex2Dpjsua_MIDL_PROC_FORMAT_STRING activex2Dpjsua__MIDL_ProcFormatString;
extern const activex2Dpjsua_MIDL_EXPR_FORMAT_STRING activex2Dpjsua__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IApp_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IApp_ProxyInfo;


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


static const activex2Dpjsua_MIDL_PROC_FORMAT_STRING activex2Dpjsua__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure app_create */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x24 ),	/* 36 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 24 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_default_config */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 54 */	NdrFcShort( 0x153 ),	/* 339 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pConfig */

/* 60 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_test_config */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 88 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 90 */	NdrFcShort( 0x1 ),	/* 1 */
/* 92 */	NdrFcShort( 0x1a3 ),	/* 419 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pConfig */

/* 96 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter errmsg */

/* 102 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_init */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0xa ),	/* 10 */
/* 122 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x24 ),	/* 36 */
/* 128 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 130 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x2f6 ),	/* 758 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pConfig */

/* 138 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 142 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter pStatus */

/* 144 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_start */

/* 156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0xb ),	/* 11 */
/* 164 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x24 ),	/* 36 */
/* 170 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 172 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 180 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_destroy */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0xc ),	/* 12 */
/* 200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x24 ),	/* 36 */
/* 206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retStatus */

/* 216 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_get_max_count */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0xd ),	/* 13 */
/* 236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x24 ),	/* 36 */
/* 242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retCount */

/* 252 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_get_count */

/* 264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0xe ),	/* 14 */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x24 ),	/* 36 */
/* 278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 280 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retCount */

/* 288 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_is_active */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0xf ),	/* 15 */
/* 308 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 312 */	NdrFcShort( 0x24 ),	/* 36 */
/* 314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retVal */

/* 330 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_has_media */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x10 ),	/* 16 */
/* 350 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 354 */	NdrFcShort( 0x24 ),	/* 36 */
/* 356 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 358 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 372 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 374 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_get_info */

/* 384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x11 ),	/* 17 */
/* 392 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 394 */	NdrFcShort( 0x8 ),	/* 8 */
/* 396 */	NdrFcShort( 0x24 ),	/* 36 */
/* 398 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 400 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 402 */	NdrFcShort( 0x16 ),	/* 22 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 408 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInfo */

/* 414 */	NdrFcShort( 0xe113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=56 */
/* 416 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 418 */	NdrFcShort( 0x46e ),	/* Type Offset=1134 */

	/* Parameter pRet */

/* 420 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 428 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_make_call */

/* 432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x12 ),	/* 18 */
/* 440 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 442 */	NdrFcShort( 0x8 ),	/* 8 */
/* 444 */	NdrFcShort( 0x40 ),	/* 64 */
/* 446 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 448 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x1 ),	/* 1 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 458 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dst_uri */

/* 462 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 466 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter call_index */

/* 468 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 470 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 474 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 476 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 482 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_answer */

/* 486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x13 ),	/* 19 */
/* 494 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 496 */	NdrFcShort( 0x10 ),	/* 16 */
/* 498 */	NdrFcShort( 0x24 ),	/* 36 */
/* 500 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 502 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter status_code */

/* 516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 522 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 530 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_hangup */

/* 534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x14 ),	/* 20 */
/* 542 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 546 */	NdrFcShort( 0x24 ),	/* 36 */
/* 548 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 550 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 560 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 564 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 566 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 572 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_set_hold */

/* 576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x15 ),	/* 21 */
/* 584 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 588 */	NdrFcShort( 0x24 ),	/* 36 */
/* 590 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 592 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 600 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 602 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 606 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 608 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_release_hold */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x16 ),	/* 22 */
/* 626 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 630 */	NdrFcShort( 0x24 ),	/* 36 */
/* 632 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 642 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 648 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 656 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_xfer */

/* 660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x17 ),	/* 23 */
/* 668 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 672 */	NdrFcShort( 0x24 ),	/* 36 */
/* 674 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 676 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 684 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 686 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dst_uri */

/* 690 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 692 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 694 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pRet */

/* 696 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 698 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 702 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 704 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_dial_dtmf */

/* 708 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 710 */	NdrFcLong( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x18 ),	/* 24 */
/* 716 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 718 */	NdrFcShort( 0x8 ),	/* 8 */
/* 720 */	NdrFcShort( 0x24 ),	/* 36 */
/* 722 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 724 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 734 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter digits */

/* 738 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 740 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 742 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pRet */

/* 744 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 746 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_send_im */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x19 ),	/* 25 */
/* 764 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 768 */	NdrFcShort( 0x24 ),	/* 36 */
/* 770 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 772 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter text */

/* 786 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pRet */

/* 792 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 794 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 800 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_typing */

/* 804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x1a ),	/* 26 */
/* 812 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 814 */	NdrFcShort( 0x10 ),	/* 16 */
/* 816 */	NdrFcShort( 0x24 ),	/* 36 */
/* 818 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 820 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter is_typing */

/* 834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 836 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 840 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 842 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 848 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_hangup_all */

/* 852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x1b ),	/* 27 */
/* 860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 866 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 868 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_get_count */

/* 882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x1c ),	/* 28 */
/* 890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x24 ),	/* 36 */
/* 896 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 898 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCount */

/* 906 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 914 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_get_info */

/* 918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x1d ),	/* 29 */
/* 926 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 928 */	NdrFcShort( 0x8 ),	/* 8 */
/* 930 */	NdrFcShort( 0x24 ),	/* 36 */
/* 932 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 934 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 936 */	NdrFcShort( 0xa ),	/* 10 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 942 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInfo */

/* 948 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 952 */	NdrFcShort( 0x4a2 ),	/* Type Offset=1186 */

	/* Parameter pRet */

/* 954 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 960 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 962 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 964 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_add */

/* 966 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 968 */	NdrFcLong( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x1e ),	/* 30 */
/* 974 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 978 */	NdrFcShort( 0x40 ),	/* 64 */
/* 980 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 982 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0xd4 ),	/* 212 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pConfig */

/* 990 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 992 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 994 */	NdrFcShort( 0x4ce ),	/* Type Offset=1230 */

	/* Parameter pAcc_Index */

/* 996 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 998 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1002 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1004 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1008 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1010 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_set_online_status */

/* 1014 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1022 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1024 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1026 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1028 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1030 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 1038 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1040 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter is_online */

/* 1044 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1046 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1050 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1052 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1058 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_set_registration */

/* 1062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1070 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1072 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1074 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1076 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1078 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 1086 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reg_active */

/* 1092 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1098 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1100 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1106 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure buddy_get_count */

/* 1110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1118 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1124 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1126 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCount */

/* 1134 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure buddy_get_info */

/* 1146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1154 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1158 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1160 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1162 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1164 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter buddy_index */

/* 1170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInfo */

/* 1176 */	NdrFcShort( 0xa113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=40 */
/* 1178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1180 */	NdrFcShort( 0x4f0 ),	/* Type Offset=1264 */

	/* Parameter pRet */

/* 1182 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1184 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1190 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure buddy_add */

/* 1194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1202 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1208 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1210 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uri */

/* 1218 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1222 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pBuddy_Index */

/* 1224 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1226 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1230 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1232 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1238 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure buddy_subscribe_pres */

/* 1242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1250 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1252 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1254 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1256 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1258 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter buddy_index */

/* 1266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter subscribe */

/* 1272 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1278 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1280 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1286 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure im_send_text */

/* 1290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1298 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1302 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1304 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1306 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 1314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1316 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dst_uri */

/* 1320 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1322 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1324 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter text */

/* 1326 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pRet */

/* 1332 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1334 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1340 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure im_typing */

/* 1344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1352 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1354 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1356 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1358 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1360 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1364 */	NdrFcShort( 0xc ),	/* 12 */
/* 1366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 1368 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dst_uri */

/* 1374 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1378 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter is_typing */

/* 1380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1386 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1388 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1394 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure conf_connect */

/* 1398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1406 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1408 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1410 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1412 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1414 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_port */

/* 1422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1424 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter sink_port */

/* 1428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1430 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1434 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1436 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1442 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure conf_disconnect */

/* 1446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1454 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1456 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1458 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1460 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1462 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter src_port */

/* 1470 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1472 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter sink_port */

/* 1476 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1478 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1482 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1484 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1490 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure player_create */

/* 1494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1502 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1506 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1508 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1510 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0xc ),	/* 12 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filename */

/* 1518 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1520 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1522 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pPlayer_Id */

/* 1524 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1526 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1530 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1532 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1538 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure player_get_conf_port */

/* 1542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1550 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1554 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1556 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1558 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter player_id */

/* 1566 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1568 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPort */

/* 1572 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1574 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1578 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1580 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure player_set_pos */

/* 1584 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1586 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1590 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1592 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1594 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1596 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1598 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1600 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1606 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter player_id */

/* 1608 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1610 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter sample_pos */

/* 1614 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1616 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1620 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1622 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1628 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure player_destroy */

/* 1632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1640 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1644 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1646 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1648 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter player_id */

/* 1656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1658 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1662 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1670 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure recorder_create */

/* 1674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1682 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1686 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1688 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1690 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0xc ),	/* 12 */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filename */

/* 1698 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1700 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1702 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pRecorder_Id */

/* 1704 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1706 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1710 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1712 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1718 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure recorder_get_conf_port */

/* 1722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1728 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1730 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1734 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1736 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1738 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recorder_id */

/* 1746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1748 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPort */

/* 1752 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1754 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1758 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1760 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure recorder_destroy */

/* 1764 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1766 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1770 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1772 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1776 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1778 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1780 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1786 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter recorder_id */

/* 1788 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1790 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 1794 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1796 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1802 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_load_config */

/* 1806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1812 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1814 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1820 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1822 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1824 */	NdrFcShort( 0x256 ),	/* 598 */
/* 1826 */	NdrFcShort( 0xc ),	/* 12 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filename */

/* 1830 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1832 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1834 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pConfig */

/* 1836 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1838 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1840 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter pRet */

/* 1842 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1844 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_save_config */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1862 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1868 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1870 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x2ee ),	/* 750 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filename */

/* 1878 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1882 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pConfig */

/* 1884 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter pRet */

/* 1890 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1892 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1898 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_get_current_config */

/* 1902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1908 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1910 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1914 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1916 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1918 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1920 */	NdrFcShort( 0x385 ),	/* 901 */
/* 1922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pConfig */

/* 1926 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1928 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1930 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1934 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_get_error_msg */

/* 1938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1946 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1952 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1954 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1956 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter status */

/* 1962 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1964 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errmsg */

/* 1968 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1970 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1972 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 1974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1976 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_verify_sip_url */

/* 1980 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1988 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1994 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1996 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2000 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2002 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uri */

/* 2004 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2006 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2008 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pRet */

/* 2010 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2012 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2016 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2018 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure call_get_textstat */

/* 2022 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2028 */	NdrFcShort( 0x35 ),	/* 53 */
/* 2030 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2036 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2038 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2040 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2044 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter call_index */

/* 2046 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2048 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter textstat */

/* 2052 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2054 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2056 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 2058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2060 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_handle_events */

/* 2064 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2070 */	NdrFcShort( 0x36 ),	/* 54 */
/* 2072 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2076 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2078 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2080 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter msec_timeout */

/* 2088 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2090 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pEvCount */

/* 2094 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2096 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2102 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_parse_uri */

/* 2106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x37 ),	/* 55 */
/* 2114 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2120 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2122 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2124 */	NdrFcShort( 0xbe ),	/* 190 */
/* 2126 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uriString */

/* 2130 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2132 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2134 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pSipUri */

/* 2136 */	NdrFcShort( 0xe113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=56 */
/* 2138 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2140 */	NdrFcShort( 0x516 ),	/* Type Offset=1302 */

	/* Parameter pStatus */

/* 2142 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2144 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2150 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_print_uri */

/* 2154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2162 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2164 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2168 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2170 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2172 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2174 */	NdrFcShort( 0xc7 ),	/* 199 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSipURI */

/* 2178 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2182 */	NdrFcShort( 0x516 ),	/* Type Offset=1302 */

	/* Parameter context */

/* 2184 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2188 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter uriText */

/* 2190 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2194 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 2196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2198 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure app_compare_uri_string */

/* 2202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2208 */	NdrFcShort( 0x39 ),	/* 57 */
/* 2210 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2212 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2214 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2216 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2218 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2222 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter context */

/* 2226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2230 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter uri1 */

/* 2232 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2236 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter uri2 */

/* 2238 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2240 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2242 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter pStatus */

/* 2244 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2246 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2252 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure buddy_del */

/* 2256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2262 */	NdrFcShort( 0x3a ),	/* 58 */
/* 2264 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2268 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2270 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2272 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2278 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter buddy_index */

/* 2280 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2282 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 2286 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2288 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2292 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2294 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_del */

/* 2298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2306 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2308 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2310 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2312 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2314 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter acc_id */

/* 2322 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2324 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRet */

/* 2328 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2330 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_find_for_outgoing */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2348 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2352 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2354 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2356 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter url */

/* 2364 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2366 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2368 */	NdrFcShort( 0x494 ),	/* Type Offset=1172 */

	/* Parameter acc_id */

/* 2370 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2372 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2378 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure acc_enum_id */

/* 2382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2388 */	NdrFcShort( 0x3d ),	/* 61 */
/* 2390 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2394 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2396 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2398 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2400 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter accIdArray */

/* 2406 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2410 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Return value */

/* 2412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2414 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure conf_enum_ports */

/* 2418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2424 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2426 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2432 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2434 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2436 */	NdrFcShort( 0x17f ),	/* 383 */
/* 2438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPortsArray */

/* 2442 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2446 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */

	/* Return value */

/* 2448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2450 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure conf_get_port_info */

/* 2454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2460 */	NdrFcShort( 0x3f ),	/* 63 */
/* 2462 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2466 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2468 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2470 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2472 */	NdrFcShort( 0x2 ),	/* 2 */
/* 2474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2476 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter port_id */

/* 2478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2480 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pInfo */

/* 2484 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 2486 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2488 */	NdrFcShort( 0x556 ),	/* Type Offset=1366 */

	/* Parameter pRet */

/* 2490 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2492 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2496 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2498 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const activex2Dpjsua_MIDL_TYPE_FORMAT_STRING activex2Dpjsua__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x0,	/* FC_RP */
/*  8 */	NdrFcShort( 0x420 ),	/* Offset= 1056 (1064) */
/* 10 */	
			0x13, 0x0,	/* FC_OP */
/* 12 */	NdrFcShort( 0xe ),	/* Offset= 14 (26) */
/* 14 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 16 */	NdrFcShort( 0x2 ),	/* 2 */
/* 18 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 20 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 22 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 24 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 26 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 28 */	NdrFcShort( 0x8 ),	/* 8 */
/* 30 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (14) */
/* 32 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 34 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 36 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x4 ),	/* 4 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0xffde ),	/* Offset= -34 (10) */
/* 46 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 48 */	NdrFcShort( 0x2 ),	/* Offset= 2 (50) */
/* 50 */	
			0x13, 0x0,	/* FC_OP */
/* 52 */	NdrFcShort( 0x3d8 ),	/* Offset= 984 (1036) */
/* 54 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 56 */	NdrFcShort( 0x18 ),	/* 24 */
/* 58 */	NdrFcShort( 0xa ),	/* 10 */
/* 60 */	NdrFcLong( 0x8 ),	/* 8 */
/* 64 */	NdrFcShort( 0x5a ),	/* Offset= 90 (154) */
/* 66 */	NdrFcLong( 0xd ),	/* 13 */
/* 70 */	NdrFcShort( 0x90 ),	/* Offset= 144 (214) */
/* 72 */	NdrFcLong( 0x9 ),	/* 9 */
/* 76 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (270) */
/* 78 */	NdrFcLong( 0xc ),	/* 12 */
/* 82 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (782) */
/* 84 */	NdrFcLong( 0x24 ),	/* 36 */
/* 88 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (830) */
/* 90 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 94 */	NdrFcShort( 0x302 ),	/* Offset= 770 (864) */
/* 96 */	NdrFcLong( 0x10 ),	/* 16 */
/* 100 */	NdrFcShort( 0x31c ),	/* Offset= 796 (896) */
/* 102 */	NdrFcLong( 0x2 ),	/* 2 */
/* 106 */	NdrFcShort( 0x336 ),	/* Offset= 822 (928) */
/* 108 */	NdrFcLong( 0x3 ),	/* 3 */
/* 112 */	NdrFcShort( 0x350 ),	/* Offset= 848 (960) */
/* 114 */	NdrFcLong( 0x14 ),	/* 20 */
/* 118 */	NdrFcShort( 0x36a ),	/* Offset= 874 (992) */
/* 120 */	NdrFcShort( 0xffff ),	/* Offset= -1 (119) */
/* 122 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 124 */	NdrFcShort( 0x4 ),	/* 4 */
/* 126 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 132 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 134 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 136 */	NdrFcShort( 0x4 ),	/* 4 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x1 ),	/* 1 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	0x13, 0x0,	/* FC_OP */
/* 148 */	NdrFcShort( 0xff86 ),	/* Offset= -122 (26) */
/* 150 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 152 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 154 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 160 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 162 */	NdrFcShort( 0x4 ),	/* 4 */
/* 164 */	NdrFcShort( 0x4 ),	/* 4 */
/* 166 */	0x11, 0x0,	/* FC_RP */
/* 168 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (122) */
/* 170 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 172 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 174 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 186 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 188 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 190 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 192 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 202 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 206 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 208 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 210 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (174) */
/* 212 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 214 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x6 ),	/* Offset= 6 (226) */
/* 222 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 224 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 226 */	
			0x11, 0x0,	/* FC_RP */
/* 228 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (192) */
/* 230 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 232 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 242 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 244 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 246 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 248 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 258 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 262 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 264 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 266 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (230) */
/* 268 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 270 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x6 ),	/* Offset= 6 (282) */
/* 278 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 280 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 282 */	
			0x11, 0x0,	/* FC_RP */
/* 284 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (248) */
/* 286 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 288 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 290 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 292 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 294 */	NdrFcShort( 0x2 ),	/* Offset= 2 (296) */
/* 296 */	NdrFcShort( 0x10 ),	/* 16 */
/* 298 */	NdrFcShort( 0x2f ),	/* 47 */
/* 300 */	NdrFcLong( 0x14 ),	/* 20 */
/* 304 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 306 */	NdrFcLong( 0x3 ),	/* 3 */
/* 310 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 312 */	NdrFcLong( 0x11 ),	/* 17 */
/* 316 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 318 */	NdrFcLong( 0x2 ),	/* 2 */
/* 322 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 324 */	NdrFcLong( 0x4 ),	/* 4 */
/* 328 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 330 */	NdrFcLong( 0x5 ),	/* 5 */
/* 334 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 336 */	NdrFcLong( 0xb ),	/* 11 */
/* 340 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 342 */	NdrFcLong( 0xa ),	/* 10 */
/* 346 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 348 */	NdrFcLong( 0x6 ),	/* 6 */
/* 352 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (584) */
/* 354 */	NdrFcLong( 0x7 ),	/* 7 */
/* 358 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 360 */	NdrFcLong( 0x8 ),	/* 8 */
/* 364 */	NdrFcShort( 0xfe9e ),	/* Offset= -354 (10) */
/* 366 */	NdrFcLong( 0xd ),	/* 13 */
/* 370 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (174) */
/* 372 */	NdrFcLong( 0x9 ),	/* 9 */
/* 376 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (230) */
/* 378 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 382 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (590) */
/* 384 */	NdrFcLong( 0x24 ),	/* 36 */
/* 388 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (598) */
/* 390 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 394 */	NdrFcShort( 0xcc ),	/* Offset= 204 (598) */
/* 396 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 400 */	NdrFcShort( 0xfc ),	/* Offset= 252 (652) */
/* 402 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 406 */	NdrFcShort( 0xfa ),	/* Offset= 250 (656) */
/* 408 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 412 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (660) */
/* 414 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 418 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (664) */
/* 420 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 424 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (668) */
/* 426 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 430 */	NdrFcShort( 0xf2 ),	/* Offset= 242 (672) */
/* 432 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 436 */	NdrFcShort( 0xdc ),	/* Offset= 220 (656) */
/* 438 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 442 */	NdrFcShort( 0xda ),	/* Offset= 218 (660) */
/* 444 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 448 */	NdrFcShort( 0xe4 ),	/* Offset= 228 (676) */
/* 450 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 454 */	NdrFcShort( 0xda ),	/* Offset= 218 (672) */
/* 456 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 460 */	NdrFcShort( 0xdc ),	/* Offset= 220 (680) */
/* 462 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 466 */	NdrFcShort( 0xda ),	/* Offset= 218 (684) */
/* 468 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 472 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (688) */
/* 474 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 478 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (692) */
/* 480 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 484 */	NdrFcShort( 0xdc ),	/* Offset= 220 (704) */
/* 486 */	NdrFcLong( 0x10 ),	/* 16 */
/* 490 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 492 */	NdrFcLong( 0x12 ),	/* 18 */
/* 496 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 498 */	NdrFcLong( 0x13 ),	/* 19 */
/* 502 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 504 */	NdrFcLong( 0x15 ),	/* 21 */
/* 508 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 510 */	NdrFcLong( 0x16 ),	/* 22 */
/* 514 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 516 */	NdrFcLong( 0x17 ),	/* 23 */
/* 520 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 522 */	NdrFcLong( 0xe ),	/* 14 */
/* 526 */	NdrFcShort( 0xba ),	/* Offset= 186 (712) */
/* 528 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 532 */	NdrFcShort( 0xbe ),	/* Offset= 190 (722) */
/* 534 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 538 */	NdrFcShort( 0xbc ),	/* Offset= 188 (726) */
/* 540 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 544 */	NdrFcShort( 0x70 ),	/* Offset= 112 (656) */
/* 546 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 550 */	NdrFcShort( 0x6e ),	/* Offset= 110 (660) */
/* 552 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 556 */	NdrFcShort( 0x6c ),	/* Offset= 108 (664) */
/* 558 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 562 */	NdrFcShort( 0x62 ),	/* Offset= 98 (660) */
/* 564 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 568 */	NdrFcShort( 0x5c ),	/* Offset= 92 (660) */
/* 570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x0 ),	/* Offset= 0 (574) */
/* 576 */	NdrFcLong( 0x1 ),	/* 1 */
/* 580 */	NdrFcShort( 0x0 ),	/* Offset= 0 (580) */
/* 582 */	NdrFcShort( 0xffff ),	/* Offset= -1 (581) */
/* 584 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 588 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
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
/* 678 */	NdrFcShort( 0xffa2 ),	/* Offset= -94 (584) */
/* 680 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 682 */	NdrFcShort( 0xfd60 ),	/* Offset= -672 (10) */
/* 684 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 686 */	NdrFcShort( 0xfe00 ),	/* Offset= -512 (174) */
/* 688 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 690 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (230) */
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
/* 746 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (286) */
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
/* 882 */	NdrFcShort( 0xfd4e ),	/* Offset= -690 (192) */
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
/* 1050 */	NdrFcShort( 0xfc1c ),	/* Offset= -996 (54) */
/* 1052 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1054 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1056 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1058 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0xfc08 ),	/* Offset= -1016 (46) */
/* 1064 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1066 */	NdrFcShort( 0x70 ),	/* 112 */
/* 1068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1070 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1070) */
/* 1072 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1074 */	0x0,		/* 0 */
			NdrFcShort( 0xfbf1 ),	/* Offset= -1039 (36) */
			0x8,		/* FC_LONG */
/* 1078 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1080 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1082 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1084 */	0x0,		/* 0 */
			NdrFcShort( 0xfbe7 ),	/* Offset= -1049 (36) */
			0x8,		/* FC_LONG */
/* 1088 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1090 */	NdrFcShort( 0xfbe2 ),	/* Offset= -1054 (36) */
/* 1092 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1094 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1096 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1098 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1100 */	0x0,		/* 0 */
			NdrFcShort( 0xffd1 ),	/* Offset= -47 (1054) */
			0x8,		/* FC_LONG */
/* 1104 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1106 */	0x0,		/* 0 */
			NdrFcShort( 0xfbd1 ),	/* Offset= -1071 (36) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1110 */	0x0,		/* 0 */
			NdrFcShort( 0xffc7 ),	/* Offset= -57 (1054) */
			0x8,		/* FC_LONG */
/* 1114 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1116 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1118 */	NdrFcShort( 0xfbc6 ),	/* Offset= -1082 (36) */
/* 1120 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1122 */	NdrFcShort( 0xffbc ),	/* Offset= -68 (1054) */
/* 1124 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1126 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1128 */	NdrFcShort( 0xfbbc ),	/* Offset= -1092 (36) */
/* 1130 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1134) */
/* 1134 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1136 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1140) */
/* 1142 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1144 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1146 */	0x0,		/* 0 */
			NdrFcShort( 0xfba9 ),	/* Offset= -1111 (36) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1150 */	0x0,		/* 0 */
			NdrFcShort( 0xfba5 ),	/* Offset= -1115 (36) */
			0xd,		/* FC_ENUM16 */
/* 1154 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1156 */	NdrFcShort( 0xfba0 ),	/* Offset= -1120 (36) */
/* 1158 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1160 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1162 */	0x0,		/* 0 */
			NdrFcShort( 0xfb99 ),	/* Offset= -1127 (36) */
			0x8,		/* FC_LONG */
/* 1166 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1168 */	
			0x12, 0x0,	/* FC_UP */
/* 1170 */	NdrFcShort( 0xfb88 ),	/* Offset= -1144 (26) */
/* 1172 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1168) */
/* 1182 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1184 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1186) */
/* 1186 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1188 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1192) */
/* 1194 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1196 */	0x0,		/* 0 */
			NdrFcShort( 0xfb77 ),	/* Offset= -1161 (36) */
			0x8,		/* FC_LONG */
/* 1200 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1202 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1204 */	NdrFcShort( 0xfb70 ),	/* Offset= -1168 (36) */
/* 1206 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1208 */	
			0x11, 0x0,	/* FC_RP */
/* 1210 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1230) */
/* 1212 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1214 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1216) */
/* 1216 */	
			0x12, 0x0,	/* FC_UP */
/* 1218 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (1036) */
/* 1220 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1222 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1224 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (1212) */
/* 1230 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1232 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1236) */
/* 1238 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1240 */	NdrFcShort( 0xffbc ),	/* Offset= -68 (1172) */
/* 1242 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1244 */	NdrFcShort( 0xffb8 ),	/* Offset= -72 (1172) */
/* 1246 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1248 */	NdrFcShort( 0xffb4 ),	/* Offset= -76 (1172) */
/* 1250 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1252 */	NdrFcShort( 0xffb0 ),	/* Offset= -80 (1172) */
/* 1254 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1256 */	0x0,		/* 0 */
			NdrFcShort( 0xffdb ),	/* Offset= -37 (1220) */
			0x5b,		/* FC_END */
/* 1260 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1262 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1264) */
/* 1264 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1266 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1270) */
/* 1272 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1274 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1276 */	NdrFcShort( 0xfb28 ),	/* Offset= -1240 (36) */
/* 1278 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1280 */	NdrFcShort( 0xfb24 ),	/* Offset= -1244 (36) */
/* 1282 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1284 */	NdrFcShort( 0xfb20 ),	/* Offset= -1248 (36) */
/* 1286 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1288 */	0x0,		/* 0 */
			NdrFcShort( 0xfb1b ),	/* Offset= -1253 (36) */
			0xd,		/* FC_ENUM16 */
/* 1292 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1294 */	NdrFcShort( 0xfb16 ),	/* Offset= -1258 (36) */
/* 1296 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1298 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1300 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1302) */
/* 1302 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1304 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1308) */
/* 1310 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1312 */	NdrFcShort( 0xfb04 ),	/* Offset= -1276 (36) */
/* 1314 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1316 */	NdrFcShort( 0xfb00 ),	/* Offset= -1280 (36) */
/* 1318 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1320 */	NdrFcShort( 0xfafc ),	/* Offset= -1284 (36) */
/* 1322 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1324 */	NdrFcShort( 0xfaf8 ),	/* Offset= -1288 (36) */
/* 1326 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1328 */	0x0,		/* 0 */
			NdrFcShort( 0xfaf3 ),	/* Offset= -1293 (36) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1332 */	0x0,		/* 0 */
			NdrFcShort( 0xfaef ),	/* Offset= -1297 (36) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1336 */	0x0,		/* 0 */
			NdrFcShort( 0xfaeb ),	/* Offset= -1301 (36) */
			0x8,		/* FC_LONG */
/* 1340 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1342 */	0x0,		/* 0 */
			NdrFcShort( 0xfae5 ),	/* Offset= -1307 (36) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1346 */	0x0,		/* 0 */
			NdrFcShort( 0xfae1 ),	/* Offset= -1311 (36) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1350 */	0x0,		/* 0 */
			NdrFcShort( 0xfadd ),	/* Offset= -1315 (36) */
			0x5b,		/* FC_END */
/* 1354 */	
			0x11, 0x0,	/* FC_RP */
/* 1356 */	NdrFcShort( 0xffca ),	/* Offset= -54 (1302) */
/* 1358 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1360 */	NdrFcShort( 0xfece ),	/* Offset= -306 (1054) */
/* 1362 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1364 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1366) */
/* 1366 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1368 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1372) */
/* 1374 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1376 */	0x0,		/* 0 */
			NdrFcShort( 0xfac3 ),	/* Offset= -1341 (36) */
			0x8,		/* FC_LONG */
/* 1380 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1382 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1384 */	0x0,		/* 0 */
			NdrFcShort( 0xfeb5 ),	/* Offset= -331 (1054) */
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



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IApp, ver. 0.0,
   GUID={0x93462247,0xDA4E,0x4602,{0x81,0x7B,0x26,0xBA,0x0C,0x82,0x4E,0x23}} */

#pragma code_seg(".orpc")
static const unsigned short IApp_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    114,
    156,
    192,
    228,
    264,
    300,
    342,
    384,
    432,
    486,
    534,
    576,
    618,
    660,
    708,
    756,
    804,
    852,
    882,
    918,
    966,
    1014,
    1062,
    1110,
    1146,
    1194,
    1242,
    1290,
    1344,
    1398,
    1446,
    1494,
    1542,
    1584,
    1632,
    1674,
    1722,
    1764,
    1806,
    1854,
    1902,
    1938,
    1980,
    2022,
    2064,
    2106,
    2154,
    2202,
    2256,
    2298,
    2340,
    2382,
    2418,
    2454
    };

static const MIDL_STUBLESS_PROXY_INFO IApp_ProxyInfo =
    {
    &Object_StubDesc,
    activex2Dpjsua__MIDL_ProcFormatString.Format,
    &IApp_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IApp_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    activex2Dpjsua__MIDL_ProcFormatString.Format,
    &IApp_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(64) _IAppProxyVtbl = 
{
    &IApp_ProxyInfo,
    &IID_IApp,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IApp::app_create */ ,
    (void *) (INT_PTR) -1 /* IApp::app_default_config */ ,
    (void *) (INT_PTR) -1 /* IApp::app_test_config */ ,
    (void *) (INT_PTR) -1 /* IApp::app_init */ ,
    (void *) (INT_PTR) -1 /* IApp::app_start */ ,
    (void *) (INT_PTR) -1 /* IApp::app_destroy */ ,
    (void *) (INT_PTR) -1 /* IApp::call_get_max_count */ ,
    (void *) (INT_PTR) -1 /* IApp::call_get_count */ ,
    (void *) (INT_PTR) -1 /* IApp::call_is_active */ ,
    (void *) (INT_PTR) -1 /* IApp::call_has_media */ ,
    (void *) (INT_PTR) -1 /* IApp::call_get_info */ ,
    (void *) (INT_PTR) -1 /* IApp::call_make_call */ ,
    (void *) (INT_PTR) -1 /* IApp::call_answer */ ,
    (void *) (INT_PTR) -1 /* IApp::call_hangup */ ,
    (void *) (INT_PTR) -1 /* IApp::call_set_hold */ ,
    (void *) (INT_PTR) -1 /* IApp::call_release_hold */ ,
    (void *) (INT_PTR) -1 /* IApp::call_xfer */ ,
    (void *) (INT_PTR) -1 /* IApp::call_dial_dtmf */ ,
    (void *) (INT_PTR) -1 /* IApp::call_send_im */ ,
    (void *) (INT_PTR) -1 /* IApp::call_typing */ ,
    (void *) (INT_PTR) -1 /* IApp::call_hangup_all */ ,
    (void *) (INT_PTR) -1 /* IApp::acc_get_count */ ,
    (void *) (INT_PTR) -1 /* IApp::acc_get_info */ ,
    (void *) (INT_PTR) -1 /* IApp::acc_add */ ,
    (void *) (INT_PTR) -1 /* IApp::acc_set_online_status */ ,
    (void *) (INT_PTR) -1 /* IApp::acc_set_registration */ ,
    (void *) (INT_PTR) -1 /* IApp::buddy_get_count */ ,
    (void *) (INT_PTR) -1 /* IApp::buddy_get_info */ ,
    (void *) (INT_PTR) -1 /* IApp::buddy_add */ ,
    (void *) (INT_PTR) -1 /* IApp::buddy_subscribe_pres */ ,
    (void *) (INT_PTR) -1 /* IApp::im_send_text */ ,
    (void *) (INT_PTR) -1 /* IApp::im_typing */ ,
    (void *) (INT_PTR) -1 /* IApp::conf_connect */ ,
    (void *) (INT_PTR) -1 /* IApp::conf_disconnect */ ,
    (void *) (INT_PTR) -1 /* IApp::player_create */ ,
    (void *) (INT_PTR) -1 /* IApp::player_get_conf_port */ ,
    (void *) (INT_PTR) -1 /* IApp::player_set_pos */ ,
    (void *) (INT_PTR) -1 /* IApp::player_destroy */ ,
    (void *) (INT_PTR) -1 /* IApp::recorder_create */ ,
    (void *) (INT_PTR) -1 /* IApp::recorder_get_conf_port */ ,
    (void *) (INT_PTR) -1 /* IApp::recorder_destroy */ ,
    (void *) (INT_PTR) -1 /* IApp::app_load_config */ ,
    (void *) (INT_PTR) -1 /* IApp::app_save_config */ ,
    (void *) (INT_PTR) -1 /* IApp::app_get_current_config */ ,
    (void *) (INT_PTR) -1 /* IApp::app_get_error_msg */ ,
    (void *) (INT_PTR) -1 /* IApp::app_verify_sip_url */ ,
    (void *) (INT_PTR) -1 /* IApp::call_get_textstat */ ,
    (void *) (INT_PTR) -1 /* IApp::app_handle_events */ ,
    (void *) (INT_PTR) -1 /* IApp::app_parse_uri */ ,
    (void *) (INT_PTR) -1 /* IApp::app_print_uri */ ,
    (void *) (INT_PTR) -1 /* IApp::app_compare_uri_string */ ,
    (void *) (INT_PTR) -1 /* IApp::buddy_del */ ,
    (void *) (INT_PTR) -1 /* IApp::acc_del */ ,
    (void *) (INT_PTR) -1 /* IApp::acc_find_for_outgoing */ ,
    (void *) (INT_PTR) -1 /* IApp::acc_enum_id */ ,
    (void *) (INT_PTR) -1 /* IApp::conf_enum_ports */ ,
    (void *) (INT_PTR) -1 /* IApp::conf_get_port_info */
};


static const PRPC_STUB_FUNCTION IApp_table[] =
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

CInterfaceStubVtbl _IAppStubVtbl =
{
    &IID_IApp,
    &IApp_ServerInfo,
    64,
    &IApp_table[-3],
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
    activex2Dpjsua__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
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

const CInterfaceProxyVtbl * _activex2Dpjsua_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IAppProxyVtbl,
    0
};

const CInterfaceStubVtbl * _activex2Dpjsua_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IAppStubVtbl,
    0
};

PCInterfaceName const _activex2Dpjsua_InterfaceNamesList[] = 
{
    "IApp",
    0
};

const IID *  _activex2Dpjsua_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _activex2Dpjsua_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _activex2Dpjsua, pIID, n)

int __stdcall _activex2Dpjsua_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_activex2Dpjsua_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo activex2Dpjsua_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _activex2Dpjsua_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _activex2Dpjsua_StubVtblList,
    (const PCInterfaceName * ) & _activex2Dpjsua_InterfaceNamesList,
    (const IID ** ) & _activex2Dpjsua_BaseIIDList,
    & _activex2Dpjsua_IID_Lookup, 
    1,
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

