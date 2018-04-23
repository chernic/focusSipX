#ifndef __FOCUSUA2_CALLBACK_HPP__
#define __FOCUSUA2_CALLBACK_HPP__

/**
 * @file pjsua2/account.hpp
 * @brief PJSUA2 Account operations
 */
#include <pjsua-lib/pjsua.h>
#include <pjsua2/persistent.hpp>
#include <pjsua2/presence.hpp>
#include <pjsua2/siptypes.hpp>

/** PJSUA2 API is inside pj namespace */
namespace pj{

using std::string;

/** 1
 */
struct InfoAccountReg : public PersistentObject{
    /**
     * This is the URL to be put in the request URI for the registration,
     * and will look something like "sip:serviceprovider".
     *
     * C: 
     *
     * This field should be specified if registration is desired. If the
     * value is empty, no account registration will be performed.
     *
     * C: 
     */
    string      registrarUri;

    /**
     * Specify whether the account should register as soon as it is
     * added to the UA. Application can set this to PJ_FALSE and control
     * the registration manually with pjsua_acc_set_registration().
     *
     * Default: True
     */
    bool        registerOnAdd;

    /**
     * The optional custom SIP headers to be put in the registration
     * request.
     */
    SipHeaderVector headers;

    /**
     * Additional parameters that will be appended in the Contact header
     * of the registration requests. This will be appended after
     * \a AccountSipConfig.contactParams;
     *
     * The parameters should be preceeded by semicolon, and all strings must
     * be properly escaped. Example:
     *   ";my-param=X;another-param=Hi%20there"
     */
    string          contactParams;

    /**
     * Optional interval for registration, in seconds. If the value is zero,
     * default interval will be used (PJSUA_REG_INTERVAL, 300 seconds).
     */
    unsigned        timeoutSec;

    /**
     * Specify interval of auto registration retry upon registration failure
     * (including caused by transport problem), in second. Set to 0 to
     * disable auto re-registration. Note that if the registration retry
     * occurs because of transport failure, the first retry will be done
     * after \a firstRetryIntervalSec seconds instead. Also note that
     * the interval will be randomized slightly by some seconds (specified
     * in \a reg_retry_random_interval) to avoid all clients re-registering
     * at the same time.
     *
     * See also \a firstRetryIntervalSec and \a randomRetryIntervalSec
     * settings.
     *
     * Default: PJSUA_REG_RETRY_INTERVAL
     */
    unsigned        retryIntervalSec;

    /**
     * This specifies the interval for the first registration retry. The
     * registration retry is explained in \a retryIntervalSec. Note that
     * the value here will also be randomized by some seconds (specified
     * in \a reg_retry_random_interval) to avoid all clients re-registering
     * at the same time.
     *
     * See also \a retryIntervalSec and \a randomRetryIntervalSec settings.
     *
     * Default: 0
     */
    unsigned        firstRetryIntervalSec;

    /**
     * This specifies maximum randomized value to be added/substracted
     * to/from the registration retry interval specified in \a
     * reg_retry_interval and \a reg_first_retry_interval, in second.
     * This is useful to avoid all clients re-registering at the same time.
     * For example, if the registration retry interval is set to 100 seconds
     * and this is set to 10 seconds, the actual registration retry interval
     * will be in the range of 90 to 110 seconds.
     *
     * See also \a retryIntervalSec and \a firstRetryIntervalSec settings.
     *
     * Default: 10
     */
    unsigned        randomRetryIntervalSec;

    /**
     * Specify the number of seconds to refresh the client registration
     * before the registration expires.
     *
     * Default: PJSIP_REGISTER_CLIENT_DELAY_BEFORE_REFRESH, 5 seconds
     */
    unsigned        delayBeforeRefreshSec;

    /**
     * Specify whether calls of the configured account should be dropped
     * after registration failure and an attempt of re-registration has
     * also failed.
     *
     * Default: FALSE (disabled)
     */
    bool        dropCallsOnFail;

    /**
     * Specify the maximum time to wait for unregistration requests to
     * complete during library shutdown sequence.
     *
     * Default: PJSUA_UNREG_TIMEOUT
     */
    unsigned        unregWaitMsec;

    /**
     * Specify how the registration uses the outbound and account proxy
     * settings. This controls if and what Route headers will appear in
     * the REGISTER request of this account. The value is bitmask combination
     * of PJSUA_REG_USE_OUTBOUND_PROXY and PJSUA_REG_USE_ACC_PROXY bits.
     * If the value is set to 0, the REGISTER request will not use any proxy
     * (i.e. it will not have any Route headers).
     *
     * Default: 3 (PJSUA_REG_USE_OUTBOUND_PROXY | PJSUA_REG_USE_ACC_PROXY)
     */
    unsigned        proxyUse;

public:
    /**
     * Read this object from a container node.
     *
     * @param node      Container to read values from.
     */
    virtual void readObject(const ContainerNode &node) throw(Error);

    /**
     * Write this object to a container node.
     *
     * @param node      Container to write values to.
     */
    virtual void writeObject(ContainerNode &node) const throw(Error);

};

//////////////////////////////////////////////////////////////////////////////
/**
 * Account information. Application can query the account information
 * by calling Account::getInfo().
 */
struct AccountInfo{
    /**
     * The account ID.
     */
    pjsua_acc_id    id;

    /**
     * Flag to indicate whether this is the default account.
     */
    bool        isDefault;

    /**
     * Account URI
     */
    string      uri;

    /**
     * Flag to tell whether this account has registration setting
     * (reg_uri is not empty).
     */
    bool        regIsConfigured;

    /**
     * Flag to tell whether this account is currently registered
     * (has active registration session).
     */
    bool        regIsActive;

    /**
     * An up to date expiration interval for account registration session.
     */
    int         regExpiresSec;

    /**
     * Last registration status code. If status code is zero, the account
     * is currently not registered. Any other value indicates the SIP
     * status code of the registration.
     */
    pjsip_status_code   regStatus;

    /**
     * String describing the registration status.
     */
    string      regStatusText;

    /**
     * Last registration error code. When the status field contains a SIP
     * status code that indicates a registration failure, last registration
     * error code contains the error code that causes the failure. In any
     * other case, its value is zero.
     */
    pj_status_t     regLastErr;

    /**
     * Presence online status for this account.
     */
    bool        onlineStatus;

    /**
     * Presence online status text.
     */
    string      onlineStatusText;

public:
    /** Import from pjsip data */
    void fromPj(const pjsua_acc_info &pai);
};

} // namespace pj




#endif  /* __FOCUSUA2_CALLBACK_HPP__ */

