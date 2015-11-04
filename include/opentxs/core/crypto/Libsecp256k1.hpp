/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#ifndef OPENTXS_CORE_CRYPTO_LIBSECP256K1_HPP
#define OPENTXS_CORE_CRYPTO_LIBSECP256K1_HPP

#include <opentxs/core/crypto/Crypto.hpp>
#include <opentxs/core/crypto/CryptoAsymmetric.hpp>
#include <opentxs/core/crypto/CryptoSymmetric.hpp>
#include <opentxs/core/crypto/OTEnvelope.hpp>
#include <opentxs/core/crypto/OTPasswordData.hpp>

extern "C" {
#include "secp256k1.h"
#include "secp256k1_ecdh.h"
}

namespace opentxs
{

class OTAsymmetricKey;
class OTData;
class OTPassword;
class OTPasswordData;
class Nym;
class OTSignature;
class CryptoUtil;
class FormattedKey;

class Libsecp256k1 : public Crypto, public CryptoAsymmetric
{
    friend class CryptoEngine;

private:
    Libsecp256k1() = delete;
    secp256k1_context* context_ = nullptr;

    CryptoUtil& ssl_;

protected:
    Libsecp256k1(CryptoUtil& ssl);
    virtual void Init_Override() const;
    virtual void Cleanup_Override() const;

public:
    virtual ~Libsecp256k1();

    EXPORT static const int PrivateKeySize = 32;
    EXPORT static const CryptoHash::HashType ECDHDefaultHMAC = CryptoHash::SHA256;
    EXPORT static const CryptoSymmetric::Mode ECDHDefaultAlgo = CryptoSymmetric::AES_256_ECB;

    bool SignContract(
        const String& strContractUnsigned,
        const OTAsymmetricKey& theKey,
        OTSignature& theSignature, // output
        const CryptoHash::HashType hashType,
        const OTPasswordData* pPWData = nullptr);
    bool VerifySignature(
        const String& strContractToVerify,
        const OTAsymmetricKey& theKey,
        const OTSignature& theSignature,
        const CryptoHash::HashType hashType,
        const OTPasswordData* pPWData = nullptr) const;

    bool OTSignatureToECDSASignature(
        const OTSignature& inSignature,
        secp256k1_ecdsa_signature& outSignature) const;
    bool ECDSASignatureToOTSignature(
        const secp256k1_ecdsa_signature& inSignature,
        OTSignature& outSignature) const;
    bool AsymmetricKeyToECDSAPubkey(
        const OTAsymmetricKey& asymmetricKey,
        secp256k1_pubkey& pubkey) const;
    bool ECDSAPubkeyToAsymmetricKey(
        const secp256k1_pubkey& pubkey,
        OTAsymmetricKey& asymmetricKey) const;
    bool AsymmetricKeyToECDSAPrivkey(
        const OTAsymmetricKey& asymmetricKey,
        const OTPasswordData& passwordData,
        OTPassword& privkey,
        bool ephemeral = false) const;
    bool AsymmetricKeyToECDSAPrivkey(
        const FormattedKey& asymmetricKey,
        const OTPasswordData& passwordData,
        OTPassword& privkey,
        bool ephemeral = false) const;
    bool ImportECDSAPrivkey(
        const FormattedKey& asymmetricKey,
        const OTPassword& password,
        OTPassword& privkey) const;
    bool ECDSAPrivkeyToAsymmetricKey(
        const OTPassword& privkey,
        const OTPasswordData& passwordData,
        OTAsymmetricKey& asymmetricKey,
        bool ephemeral = false) const;
    bool ExportECDSAPrivkey(
        const OTPassword& privkey,
        const OTPassword& password,
        OTAsymmetricKey& asymmetricKey) const;

    bool ECDH(
        const OTAsymmetricKey& publicKey,
        const OTAsymmetricKey& privateKey,
        const OTPasswordData& passwordData,
        OTPassword& secret,
        bool ephemeral = false) const;
    bool EncryptSessionKeyECDH(
        const OTPassword& sessionKey,
        const OTAsymmetricKey& privateKey,
        const OTAsymmetricKey& publicKey,
        const OTPasswordData& passwordData,
        symmetricEnvelope& encryptedSessionKey,
        bool ephemeral = false) const;
    bool DecryptSessionKeyECDH(
        const symmetricEnvelope& encryptedSessionKey,
        const OTAsymmetricKey& privateKey,
        const OTAsymmetricKey& publicKey,
        const OTPasswordData& passwordData,
        OTPassword& sessionKey) const;

    bool secp256k1_privkey_tweak_add(
        uint8_t key [PrivateKeySize],
        const uint8_t tweak [PrivateKeySize]) const;
    bool secp256k1_pubkey_create(
        secp256k1_pubkey& pubkey,
        const OTPassword& privkey) const;
    bool secp256k1_pubkey_serialize(
        OTData& serializedPubkey,
        const secp256k1_pubkey& pubkey) const;
    bool secp256k1_pubkey_parse(
        secp256k1_pubkey& pubkey,
        const OTPassword& serializedPubkey) const;
};

} // namespace opentxs

#endif // OPENTXS_CORE_CRYPTO_OTCRYPTO_HPP