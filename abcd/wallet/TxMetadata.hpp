/*
 * Copyright (c) 2015, Airbitz, Inc.
 * All rights reserved.
 *
 * See the LICENSE file for more information.
 */

#ifndef ABCD_WALLET_TX_METADATA_HPP
#define ABCD_WALLET_TX_METADATA_HPP

#include "../json/JsonPtr.hpp"
#include "../util/Status.hpp"

namespace abcd {

/**
 * Common user-editable metadata for transactions and addresses.
 */
struct TxMetadata
{
    TxMetadata();
    TxMetadata(const tABC_TxDetails *pDetails);

    // User-editable metadata:
    std::string name;
    std::string category;
    std::string notes;
    unsigned bizId;
    double amountCurrency;

    // Transaction properties:
    int64_t amountSatoshi;
    int64_t amountFeesAirbitzSatoshi;
    int64_t amountFeesMinersSatoshi;

    /**
     * Loads the structure from a JSON object.
     */
    Status
    load(JsonPtr json);

    /**
     * Encodes the structure into a JSON object.
     */
    Status
    save(JsonPtr &result) const;

    /**
     * Converts this structure to the legacy format.
     */
    tABC_TxDetails *
    toDetails() const;
};

} // namespace abcd

#endif
