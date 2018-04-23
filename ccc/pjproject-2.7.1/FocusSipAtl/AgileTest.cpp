/* $Id: AgileTest.cpp 5676 2018-04-18 15:19:22Z chernic $ */
#include "stdafx.h"

#include "pjsua2/util.hpp"
#include "pjsua2/json.hpp"
#include "pjsua2/endpoint.hpp"
#include "pjsua2/account.hpp"

#include "pjsua2/focusua.hpp"

using namespace std;

#include "AgileTest.h"

#define THIS_FILE   "AgileTest.cpp"
/////////////////////////////////////////////////////////////////////////////
/** string methods */
BSTR str2bstr(const char *str, unsigned len){
    if (len == 0) {
    return SysAllocString(L"");
    } else {
    OLECHAR *tmp;
    BSTR result;
    tmp = (OLECHAR*) malloc((len+1) * sizeof(OLECHAR));
    pj_ansi_to_unicode(str, len, tmp, len+1);
    result = SysAllocString(tmp);
    free(tmp);
    return result;
    }
}

/////////////////////////////////////////////////////////////////////////////
Fs__Str DefaultTestJsonString(int call_id){
    // EpConfig
    pj::EpConfig epCfg;
    epCfg.uaConfig.maxCalls = 61;
    epCfg.uaConfig.userAgent = "Just JSON Test";

    pj::JsonDocument jDoc;
    jDoc.writeObject(epCfg);
    jDoc.saveFile("jsontest.js");
    
    string  sCb  = jDoc.saveString();
    Fs__Str bsCb = str2bstr( sCb.data(), sCb.size());

    return bsCb;
}

Fs__Str DefaultIncomingCall(int call_id){
    // srcAddress
    pj_sockaddr_in  addr;
    pj_str_t        s;
    pj_sockaddr_in_init(&addr, pj_cstr(&s, "127.0.0.1"), 50123);// 

    pjsip_rx_data *rdata = new pjsip_rx_data();

    //rdata->endpt_info.mod_data = NULL;

    // info <= info
    rdata->msg_info.info        = "msg_info";

    // wholeMsg msg_buf
    rdata->msg_info.msg_buf     = "msg_buf";
    rdata->msg_info.len         = 7;

    // dstAddress <= pkt_info
    pj_memcpy(&rdata->pkt_info.src_addr,  &addr,  sizeof(addr) );
    rdata->pkt_info.len         = 9;

    pj::JsonOnIncomingCallParam prm;
    prm.fromPj(call_id, *rdata);
    
    pj::JsonDocument jDoc;
    jDoc.writeObject(prm);
    jDoc.saveFile("JsonOnIncomingCallParam.js");

    string  sCb  = jDoc.saveString();
    Fs__Str bsCb = str2bstr( sCb.data(), sCb.size());
    
    return bsCb;
}
