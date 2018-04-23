#include <pjsua2/account.hpp>
#include <pjsua2/endpoint.hpp>
#include <pjsua2/presence.hpp>
#include <pj/ctype.h>
#include "util.hpp"

using namespace pj;
using namespace std;

#define THIS_FILE		"account.cpp"

///////////////////////////////////////////////////////////////////////////////

void AccountRegConfig::readObject(const ContainerNode &node) throw(Error)
{
    ContainerNode this_node = node.readContainer("AccountRegConfig");

    NODE_READ_STRING	(this_node, registrarUri);
    NODE_READ_BOOL	(this_node, registerOnAdd);
    NODE_READ_UNSIGNED	(this_node, timeoutSec);
    NODE_READ_UNSIGNED	(this_node, retryIntervalSec);
    NODE_READ_UNSIGNED	(this_node, firstRetryIntervalSec);
    NODE_READ_UNSIGNED	(this_node, randomRetryIntervalSec);
    NODE_READ_UNSIGNED	(this_node, delayBeforeRefreshSec);
    NODE_READ_BOOL	(this_node, dropCallsOnFail);
    NODE_READ_UNSIGNED	(this_node, unregWaitMsec);
    NODE_READ_UNSIGNED	(this_node, proxyUse);
    NODE_READ_STRING	(this_node, contactParams);

    readSipHeaders(this_node, "headers", headers);
}

void AccountRegConfig::writeObject(ContainerNode &node) const throw(Error)
{
    ContainerNode this_node = node.writeNewContainer("AccountRegConfig");

    NODE_WRITE_STRING	(this_node, registrarUri);
    NODE_WRITE_BOOL	(this_node, registerOnAdd);
    NODE_WRITE_UNSIGNED	(this_node, timeoutSec);
    NODE_WRITE_UNSIGNED	(this_node, retryIntervalSec);
    NODE_WRITE_UNSIGNED	(this_node, firstRetryIntervalSec);
    NODE_WRITE_UNSIGNED	(this_node, randomRetryIntervalSec);
    NODE_WRITE_UNSIGNED	(this_node, delayBeforeRefreshSec);
    NODE_WRITE_BOOL	(this_node, dropCallsOnFail);
    NODE_WRITE_UNSIGNED	(this_node, unregWaitMsec);
    NODE_WRITE_UNSIGNED	(this_node, proxyUse);
    NODE_WRITE_STRING	(this_node, contactParams);

    writeSipHeaders(this_node, "headers", headers);
}

