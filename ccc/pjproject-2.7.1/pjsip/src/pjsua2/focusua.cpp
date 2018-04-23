/* $Id: focusua.hpp 5676 2018-04-18 15:19:22Z chernic $ */
/*
 * Copyright (C) 2013 Teluu Inc. (http://www.teluu.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <pjsua2/account.hpp>
#include <pjsua2/endpoint.hpp>
#include <pjsua2/presence.hpp>
#include <pjsua2/focusua.hpp>
#include <pj/ctype.h>
#include "util.hpp"

using namespace pj;
using namespace std;

#define THIS_FILE   "focusua.cpp"

//
void JsonAccountInfo::fromPj(const pjsua_acc_info &pai){
    id                  = pai.id;
    isDefault           = pai.is_default != 0;
    uri                 = pj2Str(pai.acc_uri);
    regIsConfigured     = pai.has_registration != 0;
    regIsActive         = pai.has_registration && pai.expires > 0 &&(pai.status / 100 == 2);
    regExpiresSec       = pai.expires;
    regStatus           = pai.status;
    regStatusText       = pj2Str(pai.status_text);
    regLastErr          = pai.reg_last_err;
    onlineStatus        = pai.online_status != 0;
    onlineStatusText    = pj2Str(pai.online_status_text);
}
void JsonAccountInfo::readObject(const ContainerNode &node) throw(Error){
    ContainerNode this_node = node.readContainer("JsonAccountInfo");

    NODE_READ_INT           ( this_node, id);
    NODE_READ_BOOL          ( this_node, isDefault);
    NODE_READ_STRING        ( this_node, uri);
    NODE_READ_BOOL          ( this_node, regIsConfigured);
    NODE_READ_BOOL          ( this_node, regIsActive);
    NODE_READ_INT           ( this_node, regExpiresSec);
    //NODE_READ_INT           ( this_node, regStatus);
    NODE_READ_NUM_T         ( this_node, pjsip_status_code, regStatus);
    NODE_READ_STRING        ( this_node, regStatusText);
    NODE_READ_INT           ( this_node, regLastErr);
    NODE_READ_BOOL          ( this_node, onlineStatus);
    NODE_READ_STRING        ( this_node, onlineStatusText);
}
void JsonAccountInfo::writeObject(ContainerNode &node) const throw(Error){
    ContainerNode this_node = node.writeNewContainer("JsonAccountInfo");

    NODE_WRITE_INT           ( this_node, id);
    NODE_WRITE_BOOL          ( this_node, isDefault);
    NODE_WRITE_STRING        ( this_node, uri);
    NODE_WRITE_BOOL          ( this_node, regIsConfigured);
    NODE_WRITE_BOOL          ( this_node, regIsActive);
    NODE_WRITE_INT           ( this_node, regExpiresSec);
    /*NODE_WRITE_INT           ( this_node, regStatus);*/
    NODE_WRITE_NUM_T            ( this_node, pjsip_status_code, regStatus);
    NODE_WRITE_STRING        ( this_node, regStatusText);
    NODE_WRITE_INT           ( this_node, regLastErr);
    NODE_WRITE_BOOL          ( this_node, onlineStatus);
    NODE_WRITE_STRING        ( this_node, onlineStatusText);
}
//
void JsonOnIncomingCallParam::fromPj(int call_id, pjsip_rx_data &rdata){
    callId                 = call_id;
    // info                = pj2Str(rdata.info);
    // wholeMsg            = pj2Str(rdata.wholeMsg);
    // srcAddress          = pj2Str(rdata.srcAddress);

    // via: e:\github\focusSip\ccc\pjproject-2.7.1\pjsip\src\pjsua2\siptypes.cpp
    //      void SipRxData::fromPj(pjsip_rx_data &rdata)
    char straddr[PJ_INET6_ADDRSTRLEN+10];

    if(call_id !=  PJSUA_INVALID_ID){
        info        = pjsip_rx_data_get_info(&rdata);
    }else{
        info        = string("no_info");
    }

    wholeMsg        = string(rdata.msg_info.msg_buf, rdata.msg_info.len);
    pj_sockaddr_print(&rdata.pkt_info.src_addr, straddr, sizeof(straddr), 3);
    srcAddress      = straddr;

    //pjRxData      = (void *)&rdata;
    
}
void JsonOnIncomingCallParam::readObject(const ContainerNode &node) throw(Error){
    ContainerNode this_node = node.readContainer("JsonOnIncomingCallParam");

    NODE_READ_INT       ( this_node, callId);
    NODE_READ_STRING    ( this_node, info);
    NODE_READ_STRING    ( this_node, wholeMsg);
    NODE_READ_STRING    ( this_node, srcAddress);
}
void JsonOnIncomingCallParam::writeObject(ContainerNode &node) const throw(Error){
    ContainerNode this_node = node.writeNewContainer("JsonOnIncomingCallParam");

    NODE_WRITE_INT      ( this_node, callId);
    NODE_WRITE_STRING   ( this_node, info);
    NODE_WRITE_STRING   ( this_node, wholeMsg);
    NODE_WRITE_STRING   ( this_node, srcAddress);
}
//
void JsonOnCallStateParam::fromPj(int call_id, pjsip_event &rdata){
    PJ_UNUSED_ARG( call_id );
    PJ_UNUSED_ARG( rdata   );
}
void JsonOnCallStateParam::readObject(const ContainerNode &node) throw(Error){
    PJ_UNUSED_ARG( node );
}
void JsonOnCallStateParam::writeObject(ContainerNode &node) const throw(Error){
    PJ_UNUSED_ARG( node );
}
