// AgileTest.h : CFocusSip µÄÉùÃ÷
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif





// ABChernic
#include <pj/types.h>
#include <pjsua-lib/pjsua.h>
#include "focusua_typedef.h"
#include "focusua_common.h"
#include "focusua_structs.h"

/////////////////////////////////////////////////////////////////////////////
/** string methods **/
#define Cp(d,s) Cp2(&d,s)
BSTR str2bstr(const char *str, unsigned len);
static pj_str_t Pj_str(pj_pool_t *pool, Fs__Str s){
    pj_str_t ret;
    unsigned len;

    len = wcslen(s);
    if (len) {
    ret.ptr = (char*)pj_pool_alloc(pool, len+1);
    ret.slen = len;
    pj_unicode_to_ansi(s, len, ret.ptr, len+1);
    ret.ptr[ret.slen] = '\0';
    } else {
    ret.ptr = NULL;
    ret.slen = 0;
    }

    return ret;
}
static void Cp2(BSTR *dst, const pj_str_t *src){
    *dst = str2bstr(src->ptr, src->slen);
}



Fs__Str DefaultTestJsonString(int call_id);
Fs__Str DefaultIncomingCall(int call_id);
