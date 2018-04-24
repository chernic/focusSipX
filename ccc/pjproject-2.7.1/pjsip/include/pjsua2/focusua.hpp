/* $Id: focusua.hpp 5676 2018-04-18 15:19:22Z chernic $ */

#ifndef __PJSUA2_FOCUSUA_HPP__
#define __PJSUA2_FOCUSUA_HPP__

/**
 * @file pjsua2/focusua.hpp
 * @brief PJSUA2 focusua operations
 */
#include <pjsua-lib/pjsua.h>
#include <pjsua2/persistent.hpp>
#include <pjsua2/presence.hpp>
#include <pjsua2/siptypes.hpp>
#include <pjsua2/call.hpp>

/** PJSUA2 API is inside pj namespace */
namespace pj{

/**
 * @defgroup PJSUA2_ACC Account
 * @ingroup PJSUA2_Ref
 * @{
 */

using std::string;

struct JsonAccountInfo : public AccountInfo, public PersistentObject{
public:
    /** Import from pjsip data */
    void fromPj(const pjsua_acc_info &pai);
    
    virtual void readObject(const ContainerNode &node) throw(Error);
    virtual void writeObject(ContainerNode &node) const throw(Error);
};

struct JsonOnIncomingCallParam: public PersistentObject{
    int         callId;
    string      info;
    string      wholeMsg;
    string      srcAddress;
    // void     *pjRxData;
public:
    /*  ����������麯����������±���
    1>focussip.cpp(1687) : error C2039: ��fromPj��: ���ǡ�pj::JsonOnIncomingCallParam���ĳ�Ա
    1>        account.hpp(1365) : �μ���pj::JsonOnIncomingCallParam��������
     */
    void fromPj(int call_id, pjsip_rx_data &rdata);

    /*  ����������麯����������±���
    1>focussip.cpp(1686) : error C2259: ��pj::JsonOnIncomingCallParam��: ����ʵ����������
    1>        �������г�Ա:
    1>        ��void pj::PersistentObject::readObject(const pj::ContainerNode &) throw(pj::Error)��: �ǳ����
    1>        persistent.hpp(65) : �μ���pj::PersistentObject::readObject��������
    1>        ��void pj::PersistentObject::writeObject(pj::ContainerNode &) throw(pj::Error) const��: �ǳ����
    1>        persistent.hpp(72) : �μ���pj::PersistentObject::writeObject��������
    */
    virtual void readObject(const ContainerNode &node) throw(Error);
    virtual void writeObject(ContainerNode &node) const throw(Error);
};

struct JsonOnCallStateParam: 
    public OnCallStateParam,
    public PersistentObject
{
public:
    void fromPj(int call_id, pjsip_event &rdata);
    virtual void readObject(const ContainerNode &node) throw(Error);
    virtual void writeObject(ContainerNode &node) const throw(Error);
};


/**
 * @}  PJSUA2
 */

} // namespace pj

#endif  /* __PJSUA2_FOCUSUA_HPP__ */

