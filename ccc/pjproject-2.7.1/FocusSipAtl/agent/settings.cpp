/* 
 * Copyright (C) 2011-2016 MicroSIP (http://www.microsip.org)
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

#include "stdafx.h"
#include "settings.h"
//include "Crypto.h"
#include <algorithm>
#include <vector>
AccountSettings accountSettings;

void AccountSettings::Init(){
    accountId               = 0;
    account.label           = CString("");
    account.server          = CString("");
    account.proxy           = CString("");
    account.username        = CString("");
    account.domain          = CString("");
    int port                = 0;
    account.authID          = CString("");
    account.password        = CString("");
    int rememberPassword    = 0;
    account.displayName     = CString("");
    account.voicemailNumber = CString("");
    account.srtp            = CString("");
    account.transport       = CString("");
    account.publicAddr      = CString("");
    int publish             = 0;
    int ice                 = 0;
    int allowRewrite        = 0;
    int disableSessionTimer = 0;

	userAgent				= CString("");
}
AccountSettings::AccountSettings(){
    Init();
}