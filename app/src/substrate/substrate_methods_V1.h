/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_TIMESTAMP_V1 3
#define PD_CALL_BALANCES_V1 4
#define PD_CALL_STAKING_V1 6
#define PD_CALL_SESSION_V1 9
#define PD_CALL_GRANDPA_V1 10
#define PD_CALL_COUNCIL_V1 14
#define PD_CALL_TECHNICALCOMMITTEE_V1 15
#define PD_CALL_ELECTIONS_V1 16
#define PD_CALL_TECHNICALMEMBERSHIP_V1 17
#define PD_CALL_TREASURY_V1 18
#define PD_CALL_CLAIMS_V1 19
#define PD_CALL_VESTING_V1 20
#define PD_CALL_UTILITY_V1 21
#define PD_CALL_IDENTITY_V1 22
#define PD_CALL_PROXY_V1 23
#define PD_CALL_BOUNTIES_V1 26
#define PD_CALL_TIPS_V1 27
#define PD_CALL_CHAINBRIDGE_V1 28
#define PD_CALL_SWAP_V1 29
#define PD_CALL_XXCMIX_V1 30
#define PD_CALL_XXECONOMICS_V1 31
#define PD_CALL_XXCUSTODY_V1 32
#define PD_CALL_XXBETANETREWARDS_V1 33
#define PD_CALL_XXPUBLIC_V1 34
#define PD_CALL_MULTISIG_V1 35
#define PD_CALL_RECOVERY_V1 36
#define PD_CALL_ASSETS_V1 37
#define PD_CALL_UNIQUES_V1 38

#define PD_CALL_BALANCES_TRANSFER_ALL_V1 4
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V1_t;

#define PD_CALL_STAKING_BOND_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t controller;
    pd_CompactBalance_t amount;
    pd_OptionHash_t cmix_id;
} pd_staking_bond_V1_t;

#define PD_CALL_STAKING_BOND_EXTRA_V1 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V1_t;

#define PD_CALL_STAKING_UNBOND_V1 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V1_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V1 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V1_t;

#define PD_CALL_STAKING_VALIDATE_V1 4
typedef struct {
    pd_ValidatorPrefs_V1_t prefs;
} pd_staking_validate_V1_t;

#define PD_CALL_STAKING_NOMINATE_V1 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V1_t targets;
} pd_staking_nominate_V1_t;

#define PD_CALL_STAKING_CHILL_V1 6
typedef struct {
} pd_staking_chill_V1_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V1 7
typedef struct {
    pd_LookupasStaticLookupSource_V1_t controller;
} pd_staking_set_controller_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V1 17
typedef struct {
    pd_AccountId_V1_t validator_stash;
    pd_EraIndex_V1_t era;
} pd_staking_payout_stakers_V1_t;

#define PD_CALL_STAKING_REBOND_V1 18
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V1 5
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V1_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V1 8
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V1_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V1 9
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V1_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V1 11
typedef struct {
} pd_staking_force_no_eras_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V1 12
typedef struct {
} pd_staking_force_new_era_V1_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V1 13
typedef struct {
    pd_VecAccountId_V1_t invulnerables;
} pd_staking_set_invulnerables_V1_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V1 14
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V1 15
typedef struct {
} pd_staking_force_new_era_always_V1_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V1 16
typedef struct {
    pd_EraIndex_V1_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V1_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V1 19
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V1_t;

#define PD_CALL_STAKING_REAP_STASH_V1 20
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V1_t;

#define PD_CALL_STAKING_KICK_V1 21
typedef struct {
    pd_VecLookupasStaticLookupSource_V1_t who;
} pd_staking_kick_V1_t;

#define PD_CALL_STAKING_CHILL_OTHER_V1 23
typedef struct {
    pd_AccountId_V1_t controller;
} pd_staking_chill_other_V1_t;

#define PD_CALL_STAKING_SET_CMIX_ID_V1 24
typedef struct {
    pd_Hash_t cmix_id;
} pd_staking_set_cmix_id_V1_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V1 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V1_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_V1_t new_members;
    pd_OptionAccountId_V1_t prime;
    pd_MemberCount_V1_t old_count;
} pd_council_set_members_V1_t;

#define PD_CALL_COUNCIL_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V1_t;

#define PD_CALL_COUNCIL_CLOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V1_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_V1_t new_members;
    pd_OptionAccountId_V1_t prime;
    pd_MemberCount_V1_t old_count;
} pd_technicalcommittee_set_members_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V1_t;

#define PD_CALL_ELECTIONS_VOTE_V1 0
typedef struct {
    pd_VecAccountId_V1_t votes;
    pd_Compactu128_t amount;
} pd_elections_vote_V1_t;

#define PD_CALL_ELECTIONS_REMOVE_VOTER_V1 1
typedef struct {
} pd_elections_remove_voter_V1_t;

#define PD_CALL_ELECTIONS_SUBMIT_CANDIDACY_V1 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_elections_submit_candidacy_V1_t;

#define PD_CALL_ELECTIONS_REMOVE_MEMBER_V1 4
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_bool_t has_replacement;
} pd_elections_remove_member_V1_t;

#define PD_CALL_ELECTIONS_CLEAN_DEFUNCT_VOTERS_V1 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_elections_clean_defunct_voters_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V1 0
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_add_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V1 1
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_remove_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V1 2
typedef struct {
    pd_AccountId_V1_t remove;
    pd_AccountId_V1_t add;
} pd_technicalmembership_swap_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V1 3
typedef struct {
    pd_VecAccountId_V1_t members;
} pd_technicalmembership_reset_members_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V1 4
typedef struct {
    pd_AccountId_V1_t new_;
} pd_technicalmembership_change_key_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V1 5
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_set_prime_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V1 6
typedef struct {
} pd_technicalmembership_clear_prime_V1_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V1 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V1_t beneficiary;
} pd_treasury_propose_spend_V1_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V1 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V1_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V1 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V1_t;

#define PD_CALL_CLAIMS_CLAIM_V1 0
typedef struct {
    pd_AccountId_V1_t dest;
    pd_EcdsaSignature_V1_t ethereum_signature;
} pd_claims_claim_V1_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V1 2
typedef struct {
    pd_AccountId_V1_t dest;
    pd_EcdsaSignature_V1_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V1_t;

#define PD_CALL_CLAIMS_ATTEST_V1 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V1_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V1 4
typedef struct {
    pd_EthereumAddress_V1_t old;
    pd_EthereumAddress_V1_t new_;
    pd_OptionAccountId_V1_t maybe_preclaim;
} pd_claims_move_claim_V1_t;

#define PD_CALL_VESTING_VEST_V1 0
typedef struct {
} pd_vesting_vest_V1_t;

#define PD_CALL_VESTING_VEST_OTHER_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t target;
} pd_vesting_vest_other_V1_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V1 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V1_t;

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ALL_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V1_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V1 0
typedef struct {
    pd_AccountId_V1_t account;
} pd_identity_add_registrar_V1_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V1 3
typedef struct {
} pd_identity_clear_identity_V1_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V1 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V1_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V1 5
typedef struct {
    pd_RegistrarIndex_V1_t reg_index;
} pd_identity_cancel_request_V1_t;

#define PD_CALL_IDENTITY_SET_FEE_V1 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V1_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V1 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V1_t new_;
} pd_identity_set_account_id_V1_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V1 10
typedef struct {
    pd_LookupasStaticLookupSource_V1_t target;
} pd_identity_kill_identity_V1_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V1 13
typedef struct {
    pd_LookupasStaticLookupSource_V1_t sub;
} pd_identity_remove_sub_V1_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V1 14
typedef struct {
} pd_identity_quit_sub_V1_t;

#define PD_CALL_PROXY_ADD_PROXY_V1 1
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V1 2
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V1 3
typedef struct {
} pd_proxy_remove_proxies_V1_t;

#define PD_CALL_PROXY_ANONYMOUS_V1 4
typedef struct {
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V1_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V1 5
typedef struct {
    pd_AccountId_V1_t spawner;
    pd_ProxyType_V1_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V1_t;

#define PD_CALL_PROXY_ANNOUNCE_V1 6
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_announce_V1_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V1 7
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_remove_announcement_V1_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V1 8
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_reject_announcement_V1_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V1 9
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V1_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V1 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V1_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V1 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V1_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V1 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V1_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V1_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V1 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V1_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V1 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V1_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V1 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V1_t beneficiary;
} pd_bounties_award_bounty_V1_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V1 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V1_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V1 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V1_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V1 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V1_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V1 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V1_t who;
} pd_tips_report_awesome_V1_t;

#define PD_CALL_TIPS_RETRACT_TIP_V1 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V1_t;

#define PD_CALL_TIPS_TIP_NEW_V1 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V1_t who;
    pd_Compactu128_t tip_value;
} pd_tips_tip_new_V1_t;

#define PD_CALL_TIPS_TIP_V1 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_t tip_value;
} pd_tips_tip_V1_t;

#define PD_CALL_TIPS_CLOSE_TIP_V1 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V1_t;

#define PD_CALL_TIPS_SLASH_TIP_V1 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V1_t;

#define PD_CALL_CHAINBRIDGE_SET_THRESHOLD_V1 0
typedef struct {
    pd_u32_t threshold;
} pd_chainbridge_set_threshold_V1_t;

#define PD_CALL_CHAINBRIDGE_REMOVE_RESOURCE_V1 2
typedef struct {
    pd_H256_t id;
} pd_chainbridge_remove_resource_V1_t;

#define PD_CALL_CHAINBRIDGE_ADD_RELAYER_V1 4
typedef struct {
    pd_AccountId_V1_t v;
} pd_chainbridge_add_relayer_V1_t;

#define PD_CALL_CHAINBRIDGE_REMOVE_RELAYER_V1 5
typedef struct {
    pd_AccountId_V1_t v;
} pd_chainbridge_remove_relayer_V1_t;

#define PD_CALL_SWAP_TRANSFER_V1 1
typedef struct {
    pd_AccountId_V1_t to;
    pd_Balance_t amount;
} pd_swap_transfer_V1_t;

#define PD_CALL_SWAP_SET_SWAP_FEE_V1 2
typedef struct {
    pd_Compactu128_t fee;
} pd_swap_set_swap_fee_V1_t;

#define PD_CALL_SWAP_SET_FEE_DESTINATION_V1 3
typedef struct {
    pd_AccountId_V1_t dest;
} pd_swap_set_fee_destination_V1_t;

#define PD_CALL_XXCMIX_SET_SCHEDULING_ACCOUNT_V1 1
typedef struct {
    pd_AccountId_V1_t who;
} pd_xxcmix_set_scheduling_account_V1_t;

#define PD_CALL_XXCMIX_SET_CMIX_ADDRESS_SPACE_V1 5
typedef struct {
    pd_u8_t size;
} pd_xxcmix_set_cmix_address_space_V1_t;

#define PD_CALL_XXCMIX_SET_ADMIN_PERMISSION_V1 6
typedef struct {
    pd_BlockNumber_t permission;
} pd_xxcmix_set_admin_permission_V1_t;

#define PD_CALL_XXECONOMICS_SET_LIQUIDITY_REWARDS_STAKE_V1 2
typedef struct {
    pd_Compactu128_t amount;
} pd_xxeconomics_set_liquidity_rewards_stake_V1_t;

#define PD_CALL_XXECONOMICS_SET_LIQUIDITY_REWARDS_BALANCE_V1 3
typedef struct {
    pd_Compactu128_t amount;
} pd_xxeconomics_set_liquidity_rewards_balance_V1_t;

#define PD_CALL_XXCUSTODY_PAYOUT_V1 0
typedef struct {
    pd_AccountId_V1_t who;
} pd_xxcustody_payout_V1_t;

#define PD_CALL_XXCUSTODY_CUSTODY_BOND_V1 1
typedef struct {
    pd_AccountId_V1_t custody;
    pd_AccountId_V1_t controller;
    pd_Compactu128_t amount;
} pd_xxcustody_custody_bond_V1_t;

#define PD_CALL_XXCUSTODY_CUSTODY_BOND_EXTRA_V1 2
typedef struct {
    pd_AccountId_V1_t custody;
    pd_Compactu128_t amount;
} pd_xxcustody_custody_bond_extra_V1_t;

#define PD_CALL_XXCUSTODY_CUSTODY_SET_CONTROLLER_V1 3
typedef struct {
    pd_AccountId_V1_t custody;
    pd_AccountId_V1_t controller;
} pd_xxcustody_custody_set_controller_V1_t;

#define PD_CALL_XXCUSTODY_CUSTODY_SET_PROXY_V1 4
typedef struct {
    pd_AccountId_V1_t custody;
    pd_AccountId_V1_t proxy;
} pd_xxcustody_custody_set_proxy_V1_t;

#define PD_CALL_XXCUSTODY_TEAM_CUSTODY_SET_PROXY_V1 5
typedef struct {
    pd_AccountId_V1_t proxy;
} pd_xxcustody_team_custody_set_proxy_V1_t;

#define PD_CALL_XXCUSTODY_ADD_CUSTODIAN_V1 6
typedef struct {
    pd_AccountId_V1_t custodian;
} pd_xxcustody_add_custodian_V1_t;

#define PD_CALL_XXCUSTODY_REMOVE_CUSTODIAN_V1 7
typedef struct {
    pd_AccountId_V1_t custodian;
} pd_xxcustody_remove_custodian_V1_t;

#define PD_CALL_XXCUSTODY_REPLACE_TEAM_MEMBER_V1 8
typedef struct {
    pd_AccountId_V1_t who;
    pd_AccountId_V1_t new_;
} pd_xxcustody_replace_team_member_V1_t;

#define PD_CALL_XXBETANETREWARDS_APPROVE_V1 1
typedef struct {
} pd_xxbetanetrewards_approve_V1_t;

#define PD_CALL_XXPUBLIC_SET_TESTNET_MANAGER_ACCOUNT_V1 0
typedef struct {
    pd_AccountId_V1_t who;
} pd_xxpublic_set_testnet_manager_account_V1_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V1 1
typedef struct {
    pd_AccountId_V1_t lost;
    pd_AccountId_V1_t rescuer;
} pd_recovery_set_recovered_V1_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V1 3
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_initiate_recovery_V1_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V1 4
typedef struct {
    pd_AccountId_V1_t lost;
    pd_AccountId_V1_t rescuer;
} pd_recovery_vouch_recovery_V1_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V1 5
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_claim_recovery_V1_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V1 6
typedef struct {
    pd_AccountId_V1_t rescuer;
} pd_recovery_close_recovery_V1_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V1 7
typedef struct {
} pd_recovery_remove_recovery_V1_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V1 8
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_cancel_recovered_V1_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V1 1
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t owner;
    pd_bool_t is_sufficient;
    pd_Compactu64_t min_balance;
} pd_assets_force_create_V1_t;

#define PD_CALL_ASSETS_MINT_V1 3
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t beneficiary;
    pd_Compactu64_t amount;
} pd_assets_mint_V1_t;

#define PD_CALL_ASSETS_BURN_V1 4
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t who;
    pd_Compactu64_t amount;
} pd_assets_burn_V1_t;

#define PD_CALL_ASSETS_TRANSFER_V1 5
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t target;
    pd_Compactu64_t amount;
} pd_assets_transfer_V1_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V1 6
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t target;
    pd_Compactu64_t amount;
} pd_assets_transfer_keep_alive_V1_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V1 7
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t source;
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_Compactu64_t amount;
} pd_assets_force_transfer_V1_t;

#define PD_CALL_ASSETS_FREEZE_V1 8
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t who;
} pd_assets_freeze_V1_t;

#define PD_CALL_ASSETS_THAW_V1 9
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t who;
} pd_assets_thaw_V1_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V1 10
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V1_t;

#define PD_CALL_ASSETS_THAW_ASSET_V1 11
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V1_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V1 12
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t owner;
} pd_assets_transfer_ownership_V1_t;

#define PD_CALL_ASSETS_SET_TEAM_V1 13
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t issuer;
    pd_LookupasStaticLookupSource_V1_t admin;
    pd_LookupasStaticLookupSource_V1_t freezer;
} pd_assets_set_team_V1_t;

#define PD_CALL_ASSETS_SET_METADATA_V1 14
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V1_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V1 15
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V1_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V1 16
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V1_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V1 17
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V1_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V1 18
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t owner;
    pd_LookupasStaticLookupSource_V1_t issuer;
    pd_LookupasStaticLookupSource_V1_t admin;
    pd_LookupasStaticLookupSource_V1_t freezer;
    pd_Compactu64_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V1_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V1 19
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t delegate;
    pd_Compactu64_t amount;
} pd_assets_approve_transfer_V1_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V1 20
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t delegate;
} pd_assets_cancel_approval_V1_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V1 21
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t owner;
    pd_LookupasStaticLookupSource_V1_t delegate;
} pd_assets_force_cancel_approval_V1_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V1 22
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V1_t owner;
    pd_LookupasStaticLookupSource_V1_t destination;
    pd_Compactu64_t amount;
} pd_assets_transfer_approved_V1_t;

#define PD_CALL_UNIQUES_CREATE_V1 0
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V1_t admin;
} pd_uniques_create_V1_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V1 1
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V1_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V1_t;

#define PD_CALL_UNIQUES_MINT_V1 3
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_LookupasStaticLookupSource_V1_t owner;
} pd_uniques_mint_V1_t;

#define PD_CALL_UNIQUES_TRANSFER_V1 5
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_LookupasStaticLookupSource_V1_t dest;
} pd_uniques_transfer_V1_t;

#define PD_CALL_UNIQUES_FREEZE_V1 7
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
} pd_uniques_freeze_V1_t;

#define PD_CALL_UNIQUES_THAW_V1 8
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
} pd_uniques_thaw_V1_t;

#define PD_CALL_UNIQUES_FREEZE_CLASS_V1 9
typedef struct {
    pd_Compactu32_t class_;
} pd_uniques_freeze_class_V1_t;

#define PD_CALL_UNIQUES_THAW_CLASS_V1 10
typedef struct {
    pd_Compactu32_t class_;
} pd_uniques_thaw_class_V1_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V1 11
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V1_t owner;
} pd_uniques_transfer_ownership_V1_t;

#define PD_CALL_UNIQUES_SET_TEAM_V1 12
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V1_t issuer;
    pd_LookupasStaticLookupSource_V1_t admin;
    pd_LookupasStaticLookupSource_V1_t freezer;
} pd_uniques_set_team_V1_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V1 13
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_LookupasStaticLookupSource_V1_t delegate;
} pd_uniques_approve_transfer_V1_t;

#define PD_CALL_UNIQUES_FORCE_ASSET_STATUS_V1 15
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V1_t owner;
    pd_LookupasStaticLookupSource_V1_t issuer;
    pd_LookupasStaticLookupSource_V1_t admin;
    pd_LookupasStaticLookupSource_V1_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_asset_status_V1_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V1 19
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
} pd_uniques_clear_metadata_V1_t;

#define PD_CALL_UNIQUES_CLEAR_CLASS_METADATA_V1 21
typedef struct {
    pd_Compactu32_t class_;
} pd_uniques_clear_class_metadata_V1_t;

#endif

typedef union {
    pd_balances_transfer_all_V1_t balances_transfer_all_V1;
    pd_staking_bond_V1_t staking_bond_V1;
    pd_staking_bond_extra_V1_t staking_bond_extra_V1;
    pd_staking_unbond_V1_t staking_unbond_V1;
    pd_staking_withdraw_unbonded_V1_t staking_withdraw_unbonded_V1;
    pd_staking_validate_V1_t staking_validate_V1;
    pd_staking_nominate_V1_t staking_nominate_V1;
    pd_staking_chill_V1_t staking_chill_V1;
    pd_staking_set_controller_V1_t staking_set_controller_V1;
    pd_staking_payout_stakers_V1_t staking_payout_stakers_V1;
    pd_staking_rebond_V1_t staking_rebond_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_balances_force_unreserve_V1_t balances_force_unreserve_V1;
    pd_staking_set_validator_count_V1_t staking_set_validator_count_V1;
    pd_staking_increase_validator_count_V1_t staking_increase_validator_count_V1;
    pd_staking_force_no_eras_V1_t staking_force_no_eras_V1;
    pd_staking_force_new_era_V1_t staking_force_new_era_V1;
    pd_staking_set_invulnerables_V1_t staking_set_invulnerables_V1;
    pd_staking_force_unstake_V1_t staking_force_unstake_V1;
    pd_staking_force_new_era_always_V1_t staking_force_new_era_always_V1;
    pd_staking_cancel_deferred_slash_V1_t staking_cancel_deferred_slash_V1;
    pd_staking_set_history_depth_V1_t staking_set_history_depth_V1;
    pd_staking_reap_stash_V1_t staking_reap_stash_V1;
    pd_staking_kick_V1_t staking_kick_V1;
    pd_staking_chill_other_V1_t staking_chill_other_V1;
    pd_staking_set_cmix_id_V1_t staking_set_cmix_id_V1;
    pd_grandpa_note_stalled_V1_t grandpa_note_stalled_V1;
    pd_council_set_members_V1_t council_set_members_V1;
    pd_council_vote_V1_t council_vote_V1;
    pd_council_close_V1_t council_close_V1;
    pd_council_disapprove_proposal_V1_t council_disapprove_proposal_V1;
    pd_technicalcommittee_set_members_V1_t technicalcommittee_set_members_V1;
    pd_technicalcommittee_vote_V1_t technicalcommittee_vote_V1;
    pd_technicalcommittee_close_V1_t technicalcommittee_close_V1;
    pd_technicalcommittee_disapprove_proposal_V1_t technicalcommittee_disapprove_proposal_V1;
    pd_elections_vote_V1_t elections_vote_V1;
    pd_elections_remove_voter_V1_t elections_remove_voter_V1;
    pd_elections_submit_candidacy_V1_t elections_submit_candidacy_V1;
    pd_elections_remove_member_V1_t elections_remove_member_V1;
    pd_elections_clean_defunct_voters_V1_t elections_clean_defunct_voters_V1;
    pd_technicalmembership_add_member_V1_t technicalmembership_add_member_V1;
    pd_technicalmembership_remove_member_V1_t technicalmembership_remove_member_V1;
    pd_technicalmembership_swap_member_V1_t technicalmembership_swap_member_V1;
    pd_technicalmembership_reset_members_V1_t technicalmembership_reset_members_V1;
    pd_technicalmembership_change_key_V1_t technicalmembership_change_key_V1;
    pd_technicalmembership_set_prime_V1_t technicalmembership_set_prime_V1;
    pd_technicalmembership_clear_prime_V1_t technicalmembership_clear_prime_V1;
    pd_treasury_propose_spend_V1_t treasury_propose_spend_V1;
    pd_treasury_reject_proposal_V1_t treasury_reject_proposal_V1;
    pd_treasury_approve_proposal_V1_t treasury_approve_proposal_V1;
    pd_claims_claim_V1_t claims_claim_V1;
    pd_claims_claim_attest_V1_t claims_claim_attest_V1;
    pd_claims_attest_V1_t claims_attest_V1;
    pd_claims_move_claim_V1_t claims_move_claim_V1;
    pd_vesting_vest_V1_t vesting_vest_V1;
    pd_vesting_vest_other_V1_t vesting_vest_other_V1;
    pd_vesting_merge_schedules_V1_t vesting_merge_schedules_V1;
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
    pd_identity_add_registrar_V1_t identity_add_registrar_V1;
    pd_identity_clear_identity_V1_t identity_clear_identity_V1;
    pd_identity_request_judgement_V1_t identity_request_judgement_V1;
    pd_identity_cancel_request_V1_t identity_cancel_request_V1;
    pd_identity_set_fee_V1_t identity_set_fee_V1;
    pd_identity_set_account_id_V1_t identity_set_account_id_V1;
    pd_identity_kill_identity_V1_t identity_kill_identity_V1;
    pd_identity_remove_sub_V1_t identity_remove_sub_V1;
    pd_identity_quit_sub_V1_t identity_quit_sub_V1;
    pd_proxy_add_proxy_V1_t proxy_add_proxy_V1;
    pd_proxy_remove_proxy_V1_t proxy_remove_proxy_V1;
    pd_proxy_remove_proxies_V1_t proxy_remove_proxies_V1;
    pd_proxy_anonymous_V1_t proxy_anonymous_V1;
    pd_proxy_kill_anonymous_V1_t proxy_kill_anonymous_V1;
    pd_proxy_announce_V1_t proxy_announce_V1;
    pd_proxy_remove_announcement_V1_t proxy_remove_announcement_V1;
    pd_proxy_reject_announcement_V1_t proxy_reject_announcement_V1;
    pd_proxy_proxy_announced_V1_t proxy_proxy_announced_V1;
    pd_bounties_propose_bounty_V1_t bounties_propose_bounty_V1;
    pd_bounties_approve_bounty_V1_t bounties_approve_bounty_V1;
    pd_bounties_propose_curator_V1_t bounties_propose_curator_V1;
    pd_bounties_unassign_curator_V1_t bounties_unassign_curator_V1;
    pd_bounties_accept_curator_V1_t bounties_accept_curator_V1;
    pd_bounties_award_bounty_V1_t bounties_award_bounty_V1;
    pd_bounties_claim_bounty_V1_t bounties_claim_bounty_V1;
    pd_bounties_close_bounty_V1_t bounties_close_bounty_V1;
    pd_bounties_extend_bounty_expiry_V1_t bounties_extend_bounty_expiry_V1;
    pd_tips_report_awesome_V1_t tips_report_awesome_V1;
    pd_tips_retract_tip_V1_t tips_retract_tip_V1;
    pd_tips_tip_new_V1_t tips_tip_new_V1;
    pd_tips_tip_V1_t tips_tip_V1;
    pd_tips_close_tip_V1_t tips_close_tip_V1;
    pd_tips_slash_tip_V1_t tips_slash_tip_V1;
    pd_chainbridge_set_threshold_V1_t chainbridge_set_threshold_V1;
    pd_chainbridge_remove_resource_V1_t chainbridge_remove_resource_V1;
    pd_chainbridge_add_relayer_V1_t chainbridge_add_relayer_V1;
    pd_chainbridge_remove_relayer_V1_t chainbridge_remove_relayer_V1;
    pd_swap_transfer_V1_t swap_transfer_V1;
    pd_swap_set_swap_fee_V1_t swap_set_swap_fee_V1;
    pd_swap_set_fee_destination_V1_t swap_set_fee_destination_V1;
    pd_xxcmix_set_scheduling_account_V1_t xxcmix_set_scheduling_account_V1;
    pd_xxcmix_set_cmix_address_space_V1_t xxcmix_set_cmix_address_space_V1;
    pd_xxcmix_set_admin_permission_V1_t xxcmix_set_admin_permission_V1;
    pd_xxeconomics_set_liquidity_rewards_stake_V1_t xxeconomics_set_liquidity_rewards_stake_V1;
    pd_xxeconomics_set_liquidity_rewards_balance_V1_t xxeconomics_set_liquidity_rewards_balance_V1;
    pd_xxcustody_payout_V1_t xxcustody_payout_V1;
    pd_xxcustody_custody_bond_V1_t xxcustody_custody_bond_V1;
    pd_xxcustody_custody_bond_extra_V1_t xxcustody_custody_bond_extra_V1;
    pd_xxcustody_custody_set_controller_V1_t xxcustody_custody_set_controller_V1;
    pd_xxcustody_custody_set_proxy_V1_t xxcustody_custody_set_proxy_V1;
    pd_xxcustody_team_custody_set_proxy_V1_t xxcustody_team_custody_set_proxy_V1;
    pd_xxcustody_add_custodian_V1_t xxcustody_add_custodian_V1;
    pd_xxcustody_remove_custodian_V1_t xxcustody_remove_custodian_V1;
    pd_xxcustody_replace_team_member_V1_t xxcustody_replace_team_member_V1;
    pd_xxbetanetrewards_approve_V1_t xxbetanetrewards_approve_V1;
    pd_xxpublic_set_testnet_manager_account_V1_t xxpublic_set_testnet_manager_account_V1;
    pd_recovery_set_recovered_V1_t recovery_set_recovered_V1;
    pd_recovery_initiate_recovery_V1_t recovery_initiate_recovery_V1;
    pd_recovery_vouch_recovery_V1_t recovery_vouch_recovery_V1;
    pd_recovery_claim_recovery_V1_t recovery_claim_recovery_V1;
    pd_recovery_close_recovery_V1_t recovery_close_recovery_V1;
    pd_recovery_remove_recovery_V1_t recovery_remove_recovery_V1;
    pd_recovery_cancel_recovered_V1_t recovery_cancel_recovered_V1;
    pd_assets_force_create_V1_t assets_force_create_V1;
    pd_assets_mint_V1_t assets_mint_V1;
    pd_assets_burn_V1_t assets_burn_V1;
    pd_assets_transfer_V1_t assets_transfer_V1;
    pd_assets_transfer_keep_alive_V1_t assets_transfer_keep_alive_V1;
    pd_assets_force_transfer_V1_t assets_force_transfer_V1;
    pd_assets_freeze_V1_t assets_freeze_V1;
    pd_assets_thaw_V1_t assets_thaw_V1;
    pd_assets_freeze_asset_V1_t assets_freeze_asset_V1;
    pd_assets_thaw_asset_V1_t assets_thaw_asset_V1;
    pd_assets_transfer_ownership_V1_t assets_transfer_ownership_V1;
    pd_assets_set_team_V1_t assets_set_team_V1;
    pd_assets_set_metadata_V1_t assets_set_metadata_V1;
    pd_assets_clear_metadata_V1_t assets_clear_metadata_V1;
    pd_assets_force_set_metadata_V1_t assets_force_set_metadata_V1;
    pd_assets_force_clear_metadata_V1_t assets_force_clear_metadata_V1;
    pd_assets_force_asset_status_V1_t assets_force_asset_status_V1;
    pd_assets_approve_transfer_V1_t assets_approve_transfer_V1;
    pd_assets_cancel_approval_V1_t assets_cancel_approval_V1;
    pd_assets_force_cancel_approval_V1_t assets_force_cancel_approval_V1;
    pd_assets_transfer_approved_V1_t assets_transfer_approved_V1;
    pd_uniques_create_V1_t uniques_create_V1;
    pd_uniques_force_create_V1_t uniques_force_create_V1;
    pd_uniques_mint_V1_t uniques_mint_V1;
    pd_uniques_transfer_V1_t uniques_transfer_V1;
    pd_uniques_freeze_V1_t uniques_freeze_V1;
    pd_uniques_thaw_V1_t uniques_thaw_V1;
    pd_uniques_freeze_class_V1_t uniques_freeze_class_V1;
    pd_uniques_thaw_class_V1_t uniques_thaw_class_V1;
    pd_uniques_transfer_ownership_V1_t uniques_transfer_ownership_V1;
    pd_uniques_set_team_V1_t uniques_set_team_V1;
    pd_uniques_approve_transfer_V1_t uniques_approve_transfer_V1;
    pd_uniques_force_asset_status_V1_t uniques_force_asset_status_V1;
    pd_uniques_clear_metadata_V1_t uniques_clear_metadata_V1;
    pd_uniques_clear_class_metadata_V1_t uniques_clear_class_metadata_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t source;
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V1 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_PROXY_PROXY_V1 0
typedef struct {
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_V1_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_OpaqueCall_V1_t call;
    pd_bool_t store_call;
    pd_Weight_V1_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V1_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_Timepoint_V1_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_proxy_proxy_V1_t proxy_proxy_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
