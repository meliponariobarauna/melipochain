// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2014-2016 The Bitcoin Core developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2019 Coin Sciences Ltd
// Meliponariod code distributed under the GPLv3 license, see COPYING file.

#ifndef BITCOIN_RPCCLIENT_H
#define BITCOIN_RPCCLIENT_H

#include "json/json_spirit_reader_template.h"
#include "json/json_spirit_utils.h"
#include "json/json_spirit_writer_template.h"

json_spirit::Array RPCConvertValues(const std::string& strMethod, const std::vector<std::string>& strParams);
bool HaveAPIWithThisName(const std::string &strMethod);

#endif // BITCOIN_RPCCLIENT_H
