/************************************************************
*
*  ot_made_easy_ot.hpp
*
*/

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

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
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#ifndef __OT_MADE_EASY_OT_HPP__
#define __OT_MADE_EASY_OT_HPP__

#include <opentxs/core/util/Common.hpp>

#include <vector>

namespace opentxs
{

#define OT_MADE_EASY_OT

using std::string;
using std::vector;

class MadeEasy
{
private:
    // do not allow construction
    MadeEasy()
    {
    }
    ~MadeEasy()
    {
    }

public:
    EXPORT OT_MADE_EASY_OT static string activate_smart_contract(
        const string& SERVER_ID, const string& NYM_ID, const string& ACCT_ID,
        const string& AGENT_NAME, const string& THE_SMART_CONTRACT);
    EXPORT OT_MADE_EASY_OT static string adjust_usage_credits(
        const string& SERVER_ID, const string& USER_NYM_ID,
        const string& TARGET_NYM_ID, const string& ADJUSTMENT);
    EXPORT OT_MADE_EASY_OT static string cancel_payment_plan(
        const string& SERVER_ID, const string& NYM_ID,
        const string& THE_PAYMENT_PLAN);
    EXPORT OT_MADE_EASY_OT static string check_user(
        const string& SERVER_ID, const string& NYM_ID,
        const string& TARGET_NYM_ID);
    EXPORT OT_MADE_EASY_OT static string create_asset_acct(
        const string& SERVER_ID, const string& NYM_ID,
        const string& ASSET_TYPE_ID);
    EXPORT OT_MADE_EASY_OT static string create_market_offer(
        const string& ASSET_ACCT_ID, const string& CURRENCY_ACCT_ID,
        const string& scale, const string& minIncrement, const string& quantity,
        const string& price, const bool bSelling,
        const string& strLifespanInSeconds, const string& strStopSign,
        const string& strActivationPrice);
    EXPORT OT_MADE_EASY_OT static string create_pseudonym(
        const int32_t nKeybits, const string& strNymIDSource,
        const string& strAltLocation);
    EXPORT OT_MADE_EASY_OT static string deposit_cheque(
        const string& SERVER_ID, const string& NYM_ID, const string& ACCT_ID,
        const string& STR_CHEQUE);
    EXPORT OT_MADE_EASY_OT static string deposit_payment_plan(
        const string& SERVER_ID, const string& NYM_ID,
        const string& THE_PAYMENT_PLAN);
    EXPORT OT_MADE_EASY_OT static string deposit_purse(const string& SERVER_ID,
                                                       const string& NYM_ID,
                                                       const string& ACCT_ID,
                                                       const string& STR_PURSE);
    EXPORT OT_MADE_EASY_OT static int32_t depositCashPurse(
        const string& serverID, const string& assetID, const string& nymID,
        const string& oldPurse, const vector<string>& selectedTokens,
        const string& accountID,
        const bool bReimportIfFailure); // So we don't re-import a purse that
                                        // wasn't internal to begin with.
    EXPORT OT_MADE_EASY_OT static string exchange_basket_currency(
        const string& SERVER_ID, const string& NYM_ID, const string& ASSET_TYPE,
        const string& THE_BASKET, const string& ACCT_ID, const bool IN_OR_OUT);
    EXPORT OT_MADE_EASY_OT static bool exchangeCashPurse(
        const string& serverID, const string& assetID, const string& nymID,
        string& oldPurse, const vector<string>& selectedTokens);
    EXPORT OT_MADE_EASY_OT static string exportCashPurse(
        const string& serverID, const string& assetID, const string& nymID,
        const string& oldPurse, const vector<string>& selectedTokens,
        string& recipientNymID, const bool bPasswordProtected,
        string& strRetainedCopy);
    EXPORT OT_MADE_EASY_OT static string get_box_receipt(
        const string& SERVER_ID, const string& NYM_ID, const string& ACCT_ID,
        const int32_t nBoxType, const string& STR_TRANS_NUM);
    EXPORT OT_MADE_EASY_OT static string get_market_list(
        const string& SERVER_ID, const string& NYM_ID);
    EXPORT OT_MADE_EASY_OT static string get_market_offers(
        const string& SERVER_ID, const string& NYM_ID, const string& MARKET_ID,
        const int64_t MAX_DEPTH);
    EXPORT OT_MADE_EASY_OT static string get_market_recent_trades(
        const string& SERVER_ID, const string& NYM_ID, const string& MARKET_ID);
    EXPORT OT_MADE_EASY_OT static string get_nym_market_offers(
        const string& SERVER_ID, const string& NYM_ID);
    EXPORT OT_MADE_EASY_OT static string get_payment_instrument(
        const string& SERVER_ID, const string& NYM_ID, const int32_t nIndex,
        const string& PRELOADED_INBOX); // PRELOADED_INBOX is optional.
    EXPORT OT_MADE_EASY_OT static bool importCashPurse(const string& serverID,
                                                       const string& nymID,
                                                       const string& assetID,
                                                       string& userInput,
                                                       const bool isPurse);
    EXPORT OT_MADE_EASY_OT static bool insure_enough_nums(
        const int32_t nNumberNeeded, const string& strMyServerID,
        const string& strMyNymID);
    EXPORT OT_MADE_EASY_OT static string issue_asset_type(
        const string& SERVER_ID, const string& NYM_ID,
        const string& THE_CONTRACT);
    EXPORT OT_MADE_EASY_OT static string issue_basket_currency(
        const string& SERVER_ID, const string& NYM_ID,
        const string& THE_BASKET);
    EXPORT OT_MADE_EASY_OT static string kill_market_offer(
        const string& SERVER_ID, const string& NYM_ID,
        const string& ASSET_ACCT_ID, const string& STR_TRANS_NUM);
    EXPORT OT_MADE_EASY_OT static string kill_payment_plan(
        const string& SERVER_ID, const string& NYM_ID, const string& ACCT_ID,
        const string& STR_TRANS_NUM);
    EXPORT OT_MADE_EASY_OT static string load_or_retrieve_contract(
        const string& SERVER_ID, const string& NYM_ID,
        const string& CONTRACT_ID);
    EXPORT OT_MADE_EASY_OT static string load_or_retrieve_encrypt_key(
        const string& SERVER_ID, const string& NYM_ID,
        const string& TARGET_NYM_ID);
    EXPORT OT_MADE_EASY_OT static string load_or_retrieve_mint(
        const string& SERVER_ID, const string& NYM_ID, const string& ASSET_ID);
    EXPORT OT_MADE_EASY_OT static string load_or_retrieve_signing_key(
        const string& SERVER_ID, const string& NYM_ID,
        const string& TARGET_NYM_ID);
    EXPORT OT_MADE_EASY_OT static string load_public_encryption_key(
        const string& NYM_ID); // from local storage.
    EXPORT OT_MADE_EASY_OT static string load_public_signing_key(
        const string& NYM_ID); // from local storage.
    EXPORT OT_MADE_EASY_OT static string pay_dividend(
        const string& SERVER_ID, const string& NYM_ID,
        const string& SOURCE_ACCT_ID, const string& SHARES_ASSET_ID,
        const string& STR_MEMO, const int64_t AMOUNT_PER_SHARE);
    EXPORT OT_MADE_EASY_OT static string process_inbox(
        const string& SERVER_ID, const string& NYM_ID, const string& ACCOUNT_ID,
        const string& RESPONSE_LEDGER);
    EXPORT OT_MADE_EASY_OT static bool processCashPurse(
        string& newPurse, string& newPurseForSender, const string& serverID,
        const string& assetID, const string& nymID, string& oldPurse,
        const vector<string>& selectedTokens, const string& recipientNymID,
        const bool bPWProtectOldPurse, const bool bPWProtectNewPurse);
    EXPORT OT_MADE_EASY_OT static string query_asset_types(
        const string& SERVER_ID, const string& NYM_ID,
        const string& ENCODED_MAP);
    EXPORT OT_MADE_EASY_OT static string register_nym(const string& SERVER_ID,
                                                      const string& NYM_ID);
    EXPORT OT_MADE_EASY_OT static bool retrieve_account(
        const string& SERVER_ID, const string& NYM_ID, const string& ACCOUNT_ID,
        const bool bForceDownload); // bForceDownload=false
    EXPORT OT_MADE_EASY_OT static string retrieve_contract(
        const string& SERVER_ID, const string& NYM_ID,
        const string& CONTRACT_ID);
    EXPORT OT_MADE_EASY_OT static string retrieve_mint(const string& SERVER_ID,
                                                       const string& NYM_ID,
                                                       const string& ASSET_ID);
    EXPORT OT_MADE_EASY_OT static int32_t retrieve_nym(
        const string& strServerID, const string& strMyNymID, bool& bWasMsgSent,
        const bool bForceDownload);
    EXPORT OT_MADE_EASY_OT static string send_transfer(
        const string& SERVER_ID, const string& NYM_ID, const string& ACCT_FROM,
        const string& ACCT_TO, const int64_t AMOUNT, const string& NOTE);
    EXPORT OT_MADE_EASY_OT static string send_user_cash(
        const string& SERVER_ID, const string& NYM_ID,
        const string& RECIPIENT_NYM_ID, const string& THE_PAYMENT,
        const string& SENDERS_COPY);
    EXPORT OT_MADE_EASY_OT static string send_user_cash_pubkey(
        const string& SERVER_ID, const string& NYM_ID,
        const string& RECIPIENT_NYM_ID, const string& RECIPIENT_PUBKEY,
        const string& THE_INSTRUMENT, const string& INSTRUMENT_FOR_SENDER);
    EXPORT OT_MADE_EASY_OT static string send_user_msg(
        const string& SERVER_ID, const string& NYM_ID,
        const string& RECIPIENT_NYM_ID, const string& THE_MESSAGE);
    EXPORT OT_MADE_EASY_OT static string send_user_msg_pubkey(
        const string& SERVER_ID, const string& NYM_ID,
        const string& RECIPIENT_NYM_ID, const string& RECIPIENT_PUBKEY,
        const string& THE_MESSAGE);
    EXPORT OT_MADE_EASY_OT static string send_user_payment(
        const string& SERVER_ID, const string& NYM_ID,
        const string& RECIPIENT_NYM_ID, const string& THE_PAYMENT);
    EXPORT OT_MADE_EASY_OT static string send_user_pmnt_pubkey(
        const string& SERVER_ID, const string& NYM_ID,
        const string& RECIPIENT_NYM_ID, const string& RECIPIENT_PUBKEY,
        const string& THE_INSTRUMENT);
    EXPORT OT_MADE_EASY_OT static string stat_asset_account(
        const string& ACCOUNT_ID);
    EXPORT OT_MADE_EASY_OT static string trigger_clause(
        const string& SERVER_ID, const string& NYM_ID,
        const string& STR_TRANS_NUM, const string& CLAUSE_NAME,
        const string& STR_PARAM);
    EXPORT OT_MADE_EASY_OT static string withdraw_cash(const string& SERVER_ID,
                                                       const string& NYM_ID,
                                                       const string& ACCT_ID,
                                                       const int64_t AMOUNT);
    EXPORT OT_MADE_EASY_OT static string withdraw_voucher(
        const string& SERVER_ID, const string& NYM_ID, const string& ACCT_ID,
        const string& RECIP_NYM_ID, const string& STR_MEMO,
        const int64_t AMOUNT);
};

} // namespace opentxs

#endif // __OT_MADE_EASY_OT_HPP__