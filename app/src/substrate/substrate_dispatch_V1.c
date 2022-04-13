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

#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V1(
    parser_context_t* c, pd_balances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V1(
    parser_context_t* c, pd_balances_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V1(
    parser_context_t* c, pd_balances_transfer_keep_alive_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V1(
    parser_context_t* c, pd_balances_transfer_all_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V1(
    parser_context_t* c, pd_staking_bond_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readOptionHash(c, &m->cmix_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V1(
    parser_context_t* c, pd_staking_bond_extra_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V1(
    parser_context_t* c, pd_staking_unbond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V1(
    parser_context_t* c, pd_staking_withdraw_unbonded_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V1(
    parser_context_t* c, pd_staking_validate_V1_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V1(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V1(
    parser_context_t* c, pd_staking_nominate_V1_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V1(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V1(
    parser_context_t* c, pd_staking_chill_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V1(
    parser_context_t* c, pd_staking_set_controller_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V1(
    parser_context_t* c, pd_staking_payout_stakers_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V1(
    parser_context_t* c, pd_staking_rebond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V1(
    parser_context_t* c, pd_session_set_keys_V1_t* m)
{
    CHECK_ERROR(_readKeys_V1(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V1(
    parser_context_t* c, pd_session_purge_keys_V1_t* m)
{
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V1(
    parser_context_t* c, pd_system_fill_block_V1_t* m)
{
    CHECK_ERROR(_readPerbill_V1(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V1(
    parser_context_t* c, pd_system_remark_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V1(
    parser_context_t* c, pd_system_set_heap_pages_V1_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V1(
    parser_context_t* c, pd_system_set_code_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V1(
    parser_context_t* c, pd_system_set_code_without_checks_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V1(
    parser_context_t* c, pd_system_remark_with_event_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V1(
    parser_context_t* c, pd_timestamp_set_V1_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V1(
    parser_context_t* c, pd_balances_set_balance_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V1(
    parser_context_t* c, pd_balances_force_unreserve_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V1(
    parser_context_t* c, pd_staking_set_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V1(
    parser_context_t* c, pd_staking_increase_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V1(
    parser_context_t* c, pd_staking_force_no_eras_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V1(
    parser_context_t* c, pd_staking_force_new_era_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V1(
    parser_context_t* c, pd_staking_set_invulnerables_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V1(
    parser_context_t* c, pd_staking_force_unstake_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V1(
    parser_context_t* c, pd_staking_force_new_era_always_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V1(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V1_t* m)
{
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V1(
    parser_context_t* c, pd_staking_set_history_depth_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V1(
    parser_context_t* c, pd_staking_reap_stash_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V1(
    parser_context_t* c, pd_staking_kick_V1_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V1(
    parser_context_t* c, pd_staking_chill_other_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_cmix_id_V1(
    parser_context_t* c, pd_staking_set_cmix_id_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->cmix_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_transfer_cmix_id_V1(
    parser_context_t* c, pd_staking_transfer_cmix_id_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V1(
    parser_context_t* c, pd_grandpa_note_stalled_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V1(
    parser_context_t* c, pd_council_set_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V1(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V1(
    parser_context_t* c, pd_council_vote_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V1(
    parser_context_t* c, pd_council_close_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V1(
    parser_context_t* c, pd_council_disapprove_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V1(
    parser_context_t* c, pd_technicalcommittee_set_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V1(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V1(
    parser_context_t* c, pd_technicalcommittee_vote_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V1(
    parser_context_t* c, pd_technicalcommittee_close_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V1(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_vote_V1(
    parser_context_t* c, pd_elections_vote_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->votes))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_voter_V1(
    parser_context_t* c, pd_elections_remove_voter_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_submit_candidacy_V1(
    parser_context_t* c, pd_elections_submit_candidacy_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_member_V1(
    parser_context_t* c, pd_elections_remove_member_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_clean_defunct_voters_V1(
    parser_context_t* c, pd_elections_clean_defunct_voters_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_voters))
    CHECK_ERROR(_readu32(c, &m->num_defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V1(
    parser_context_t* c, pd_technicalmembership_add_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V1(
    parser_context_t* c, pd_technicalmembership_remove_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V1(
    parser_context_t* c, pd_technicalmembership_swap_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->remove))
    CHECK_ERROR(_readAccountId_V1(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V1(
    parser_context_t* c, pd_technicalmembership_reset_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V1(
    parser_context_t* c, pd_technicalmembership_change_key_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V1(
    parser_context_t* c, pd_technicalmembership_set_prime_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V1(
    parser_context_t* c, pd_technicalmembership_clear_prime_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V1(
    parser_context_t* c, pd_treasury_propose_spend_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V1(
    parser_context_t* c, pd_treasury_reject_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V1(
    parser_context_t* c, pd_treasury_approve_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_V1(
    parser_context_t* c, pd_claims_claim_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V1(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_attest_V1(
    parser_context_t* c, pd_claims_claim_attest_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V1(c, &m->ethereum_signature))
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_attest_V1(
    parser_context_t* c, pd_claims_attest_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_move_claim_V1(
    parser_context_t* c, pd_claims_move_claim_V1_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V1(c, &m->old))
    CHECK_ERROR(_readEthereumAddress_V1(c, &m->new_))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->maybe_preclaim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V1(
    parser_context_t* c, pd_vesting_vest_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V1(
    parser_context_t* c, pd_vesting_vest_other_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V1(
    parser_context_t* c, pd_vesting_merge_schedules_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V1(
    parser_context_t* c, pd_utility_batch_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V1(
    parser_context_t* c, pd_utility_batch_all_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V1(
    parser_context_t* c, pd_identity_add_registrar_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V1(
    parser_context_t* c, pd_identity_clear_identity_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V1(
    parser_context_t* c, pd_identity_request_judgement_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V1(
    parser_context_t* c, pd_identity_cancel_request_V1_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V1(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V1(
    parser_context_t* c, pd_identity_set_fee_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V1(
    parser_context_t* c, pd_identity_set_account_id_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V1(
    parser_context_t* c, pd_identity_kill_identity_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V1(
    parser_context_t* c, pd_identity_remove_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V1(
    parser_context_t* c, pd_identity_quit_sub_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V1(
    parser_context_t* c, pd_proxy_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V1(
    parser_context_t* c, pd_proxy_add_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V1(
    parser_context_t* c, pd_proxy_remove_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V1(
    parser_context_t* c, pd_proxy_remove_proxies_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V1(
    parser_context_t* c, pd_proxy_anonymous_V1_t* m)
{
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V1(
    parser_context_t* c, pd_proxy_kill_anonymous_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V1(
    parser_context_t* c, pd_proxy_announce_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V1(
    parser_context_t* c, pd_proxy_remove_announcement_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V1(
    parser_context_t* c, pd_proxy_reject_announcement_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V1(
    parser_context_t* c, pd_proxy_proxy_announced_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V1(
    parser_context_t* c, pd_bounties_propose_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V1(
    parser_context_t* c, pd_bounties_approve_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V1(
    parser_context_t* c, pd_bounties_propose_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V1(
    parser_context_t* c, pd_bounties_unassign_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V1(
    parser_context_t* c, pd_bounties_accept_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V1(
    parser_context_t* c, pd_bounties_award_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V1(
    parser_context_t* c, pd_bounties_claim_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V1(
    parser_context_t* c, pd_bounties_close_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V1(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_report_awesome_V1(
    parser_context_t* c, pd_tips_report_awesome_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_retract_tip_V1(
    parser_context_t* c, pd_tips_retract_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_new_V1(
    parser_context_t* c, pd_tips_tip_new_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    CHECK_ERROR(_readCompactu128(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_V1(
    parser_context_t* c, pd_tips_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readCompactu128(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_close_tip_V1(
    parser_context_t* c, pd_tips_close_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_slash_tip_V1(
    parser_context_t* c, pd_tips_slash_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_set_threshold_V1(
    parser_context_t* c, pd_chainbridge_set_threshold_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->threshold))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_remove_resource_V1(
    parser_context_t* c, pd_chainbridge_remove_resource_V1_t* m)
{
    CHECK_ERROR(_readH256(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_add_relayer_V1(
    parser_context_t* c, pd_chainbridge_add_relayer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->v))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_remove_relayer_V1(
    parser_context_t* c, pd_chainbridge_remove_relayer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->v))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_swap_transfer_V1(
    parser_context_t* c, pd_swap_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->to))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_swap_set_swap_fee_V1(
    parser_context_t* c, pd_swap_set_swap_fee_V1_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_swap_set_fee_destination_V1(
    parser_context_t* c, pd_swap_set_fee_destination_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcmix_set_scheduling_account_V1(
    parser_context_t* c, pd_xxcmix_set_scheduling_account_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcmix_set_cmix_address_space_V1(
    parser_context_t* c, pd_xxcmix_set_cmix_address_space_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcmix_set_admin_permission_V1(
    parser_context_t* c, pd_xxcmix_set_admin_permission_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->permission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxeconomics_set_liquidity_rewards_stake_V1(
    parser_context_t* c, pd_xxeconomics_set_liquidity_rewards_stake_V1_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxeconomics_set_liquidity_rewards_balance_V1(
    parser_context_t* c, pd_xxeconomics_set_liquidity_rewards_balance_V1_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_payout_V1(
    parser_context_t* c, pd_xxcustody_payout_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_custody_bond_V1(
    parser_context_t* c, pd_xxcustody_custody_bond_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->custody))
    CHECK_ERROR(_readAccountId_V1(c, &m->controller))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_custody_bond_extra_V1(
    parser_context_t* c, pd_xxcustody_custody_bond_extra_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->custody))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_custody_set_controller_V1(
    parser_context_t* c, pd_xxcustody_custody_set_controller_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->custody))
    CHECK_ERROR(_readAccountId_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_custody_set_proxy_V1(
    parser_context_t* c, pd_xxcustody_custody_set_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->custody))
    CHECK_ERROR(_readAccountId_V1(c, &m->proxy))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_team_custody_set_proxy_V1(
    parser_context_t* c, pd_xxcustody_team_custody_set_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->proxy))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_add_custodian_V1(
    parser_context_t* c, pd_xxcustody_add_custodian_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->custodian))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_remove_custodian_V1(
    parser_context_t* c, pd_xxcustody_remove_custodian_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->custodian))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxcustody_replace_team_member_V1(
    parser_context_t* c, pd_xxcustody_replace_team_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxbetanetrewards_approve_V1(
    parser_context_t* c, pd_xxbetanetrewards_approve_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xxpublic_set_testnet_manager_account_V1(
    parser_context_t* c, pd_xxpublic_set_testnet_manager_account_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V1(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V1(
    parser_context_t* c, pd_multisig_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V1(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V1(
    parser_context_t* c, pd_multisig_approve_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V1(
    parser_context_t* c, pd_multisig_cancel_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V1(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_set_recovered_V1(
    parser_context_t* c, pd_recovery_set_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->lost))
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery_V1(
    parser_context_t* c, pd_recovery_initiate_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery_V1(
    parser_context_t* c, pd_recovery_vouch_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->lost))
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery_V1(
    parser_context_t* c, pd_recovery_claim_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery_V1(
    parser_context_t* c, pd_recovery_close_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery_V1(
    parser_context_t* c, pd_recovery_remove_recovery_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered_V1(
    parser_context_t* c, pd_recovery_cancel_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_create_V1(
    parser_context_t* c, pd_assets_force_create_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readCompactu64(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_mint_V1(
    parser_context_t* c, pd_assets_mint_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->beneficiary))
    CHECK_ERROR(_readCompactu64(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_burn_V1(
    parser_context_t* c, pd_assets_burn_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readCompactu64(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_V1(
    parser_context_t* c, pd_assets_transfer_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readCompactu64(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_keep_alive_V1(
    parser_context_t* c, pd_assets_transfer_keep_alive_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readCompactu64(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_transfer_V1(
    parser_context_t* c, pd_assets_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactu64(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_V1(
    parser_context_t* c, pd_assets_freeze_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_V1(
    parser_context_t* c, pd_assets_thaw_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_asset_V1(
    parser_context_t* c, pd_assets_freeze_asset_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_asset_V1(
    parser_context_t* c, pd_assets_thaw_asset_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_ownership_V1(
    parser_context_t* c, pd_assets_transfer_ownership_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_team_V1(
    parser_context_t* c, pd_assets_set_team_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->issuer))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->admin))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_metadata_V1(
    parser_context_t* c, pd_assets_set_metadata_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_clear_metadata_V1(
    parser_context_t* c, pd_assets_clear_metadata_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_set_metadata_V1(
    parser_context_t* c, pd_assets_force_set_metadata_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_clear_metadata_V1(
    parser_context_t* c, pd_assets_force_clear_metadata_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_asset_status_V1(
    parser_context_t* c, pd_assets_force_asset_status_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->issuer))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->admin))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->freezer))
    CHECK_ERROR(_readCompactu64(c, &m->min_balance))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_approve_transfer_V1(
    parser_context_t* c, pd_assets_approve_transfer_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->delegate))
    CHECK_ERROR(_readCompactu64(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_cancel_approval_V1(
    parser_context_t* c, pd_assets_cancel_approval_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_cancel_approval_V1(
    parser_context_t* c, pd_assets_force_cancel_approval_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_approved_V1(
    parser_context_t* c, pd_assets_transfer_approved_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->destination))
    CHECK_ERROR(_readCompactu64(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_create_V1(
    parser_context_t* c, pd_uniques_create_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_force_create_V1(
    parser_context_t* c, pd_uniques_force_create_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->free_holding))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_mint_V1(
    parser_context_t* c, pd_uniques_mint_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readCompactu32(c, &m->instance))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_transfer_V1(
    parser_context_t* c, pd_uniques_transfer_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readCompactu32(c, &m->instance))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_freeze_V1(
    parser_context_t* c, pd_uniques_freeze_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readCompactu32(c, &m->instance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_thaw_V1(
    parser_context_t* c, pd_uniques_thaw_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readCompactu32(c, &m->instance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_freeze_class_V1(
    parser_context_t* c, pd_uniques_freeze_class_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_thaw_class_V1(
    parser_context_t* c, pd_uniques_thaw_class_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_transfer_ownership_V1(
    parser_context_t* c, pd_uniques_transfer_ownership_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_team_V1(
    parser_context_t* c, pd_uniques_set_team_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->issuer))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->admin))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_approve_transfer_V1(
    parser_context_t* c, pd_uniques_approve_transfer_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readCompactu32(c, &m->instance))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_force_asset_status_V1(
    parser_context_t* c, pd_uniques_force_asset_status_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->owner))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->issuer))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->admin))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->freezer))
    CHECK_ERROR(_readbool(c, &m->free_holding))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_metadata_V1(
    parser_context_t* c, pd_uniques_clear_metadata_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    CHECK_ERROR(_readCompactu32(c, &m->instance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_class_metadata_V1(
    parser_context_t* c, pd_uniques_clear_class_metadata_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->class_))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->nested.balances_transfer_V1))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->nested.balances_force_transfer_V1))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->nested.balances_transfer_keep_alive_V1))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V1(c, &method->basic.balances_transfer_all_V1))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->basic.staking_bond_V1))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->basic.staking_bond_extra_V1))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->basic.staking_unbond_V1))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->basic.staking_validate_V1))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->basic.staking_nominate_V1))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->basic.staking_chill_V1))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->basic.staking_set_controller_V1))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->basic.staking_payout_stakers_V1))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->basic.staking_rebond_V1))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V1(c, &method->basic.session_set_keys_V1))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V1(c, &method->basic.session_purge_keys_V1))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V1(c, &method->nested.system_fill_block_V1))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V1(c, &method->nested.system_remark_V1))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V1(c, &method->nested.system_set_heap_pages_V1))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V1(c, &method->nested.system_set_code_V1))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V1(c, &method->nested.system_set_code_without_checks_V1))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V1(c, &method->nested.system_remark_with_event_V1))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V1(c, &method->basic.timestamp_set_V1))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V1(c, &method->nested.balances_set_balance_V1))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V1(c, &method->basic.balances_force_unreserve_V1))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V1(c, &method->basic.staking_force_no_eras_V1))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V1(c, &method->basic.staking_force_new_era_V1))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V1(c, &method->basic.staking_set_invulnerables_V1))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V1(c, &method->basic.staking_force_unstake_V1))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V1(c, &method->basic.staking_force_new_era_always_V1))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V1(c, &method->basic.staking_cancel_deferred_slash_V1))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V1(c, &method->basic.staking_set_history_depth_V1))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_kick_V1(c, &method->basic.staking_kick_V1))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_staking_chill_other_V1(c, &method->basic.staking_chill_other_V1))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_staking_set_cmix_id_V1(c, &method->basic.staking_set_cmix_id_V1))
        break;
    case 1561: /* module 6 call 25 */
        CHECK_ERROR(_readMethod_staking_transfer_cmix_id_V1(c, &method->basic.staking_transfer_cmix_id_V1))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V1(c, &method->basic.grandpa_note_stalled_V1))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V1(c, &method->basic.council_set_members_V1))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V1(c, &method->basic.council_vote_V1))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_council_close_V1(c, &method->basic.council_close_V1))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V1(c, &method->basic.council_disapprove_proposal_V1))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V1(c, &method->basic.technicalcommittee_set_members_V1))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V1(c, &method->basic.technicalcommittee_vote_V1))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V1(c, &method->basic.technicalcommittee_close_V1))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V1(c, &method->basic.technicalcommittee_disapprove_proposal_V1))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_elections_vote_V1(c, &method->basic.elections_vote_V1))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_elections_remove_voter_V1(c, &method->basic.elections_remove_voter_V1))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_elections_submit_candidacy_V1(c, &method->basic.elections_submit_candidacy_V1))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_elections_remove_member_V1(c, &method->basic.elections_remove_member_V1))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_elections_clean_defunct_voters_V1(c, &method->basic.elections_clean_defunct_voters_V1))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V1(c, &method->basic.technicalmembership_add_member_V1))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V1(c, &method->basic.technicalmembership_remove_member_V1))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V1(c, &method->basic.technicalmembership_swap_member_V1))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V1(c, &method->basic.technicalmembership_reset_members_V1))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V1(c, &method->basic.technicalmembership_change_key_V1))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V1(c, &method->basic.technicalmembership_set_prime_V1))
        break;
    case 4358: /* module 17 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V1(c, &method->basic.technicalmembership_clear_prime_V1))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V1(c, &method->basic.treasury_propose_spend_V1))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V1(c, &method->basic.treasury_reject_proposal_V1))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V1(c, &method->basic.treasury_approve_proposal_V1))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V1(c, &method->basic.claims_claim_V1))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V1(c, &method->basic.claims_claim_attest_V1))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V1(c, &method->basic.claims_attest_V1))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V1(c, &method->basic.claims_move_claim_V1))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V1(c, &method->basic.vesting_vest_V1))
        break;
    case 5121: /* module 20 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V1(c, &method->basic.vesting_vest_other_V1))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V1(c, &method->basic.vesting_merge_schedules_V1))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V1(c, &method->basic.utility_batch_V1))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V1(c, &method->basic.utility_batch_all_V1))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V1(c, &method->basic.identity_add_registrar_V1))
        break;
    case 5635: /* module 22 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V1(c, &method->basic.identity_clear_identity_V1))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V1(c, &method->basic.identity_request_judgement_V1))
        break;
    case 5637: /* module 22 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V1(c, &method->basic.identity_cancel_request_V1))
        break;
    case 5638: /* module 22 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V1(c, &method->basic.identity_set_fee_V1))
        break;
    case 5639: /* module 22 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V1(c, &method->basic.identity_set_account_id_V1))
        break;
    case 5642: /* module 22 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V1(c, &method->basic.identity_kill_identity_V1))
        break;
    case 5645: /* module 22 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V1(c, &method->basic.identity_remove_sub_V1))
        break;
    case 5646: /* module 22 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V1(c, &method->basic.identity_quit_sub_V1))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V1(c, &method->nested.proxy_proxy_V1))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V1(c, &method->basic.proxy_add_proxy_V1))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V1(c, &method->basic.proxy_remove_proxy_V1))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V1(c, &method->basic.proxy_remove_proxies_V1))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V1(c, &method->basic.proxy_anonymous_V1))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V1(c, &method->basic.proxy_kill_anonymous_V1))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V1(c, &method->basic.proxy_announce_V1))
        break;
    case 5895: /* module 23 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V1(c, &method->basic.proxy_remove_announcement_V1))
        break;
    case 5896: /* module 23 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V1(c, &method->basic.proxy_reject_announcement_V1))
        break;
    case 5897: /* module 23 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V1(c, &method->basic.proxy_proxy_announced_V1))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V1(c, &method->basic.bounties_propose_bounty_V1))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V1(c, &method->basic.bounties_approve_bounty_V1))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V1(c, &method->basic.bounties_propose_curator_V1))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V1(c, &method->basic.bounties_unassign_curator_V1))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V1(c, &method->basic.bounties_accept_curator_V1))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V1(c, &method->basic.bounties_award_bounty_V1))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V1(c, &method->basic.bounties_claim_bounty_V1))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V1(c, &method->basic.bounties_close_bounty_V1))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V1(c, &method->basic.bounties_extend_bounty_expiry_V1))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_tips_report_awesome_V1(c, &method->basic.tips_report_awesome_V1))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_tips_retract_tip_V1(c, &method->basic.tips_retract_tip_V1))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_tips_tip_new_V1(c, &method->basic.tips_tip_new_V1))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_tips_tip_V1(c, &method->basic.tips_tip_V1))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_tips_close_tip_V1(c, &method->basic.tips_close_tip_V1))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_tips_slash_tip_V1(c, &method->basic.tips_slash_tip_V1))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_chainbridge_set_threshold_V1(c, &method->basic.chainbridge_set_threshold_V1))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_chainbridge_remove_resource_V1(c, &method->basic.chainbridge_remove_resource_V1))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_chainbridge_add_relayer_V1(c, &method->basic.chainbridge_add_relayer_V1))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_chainbridge_remove_relayer_V1(c, &method->basic.chainbridge_remove_relayer_V1))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_swap_transfer_V1(c, &method->basic.swap_transfer_V1))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_swap_set_swap_fee_V1(c, &method->basic.swap_set_swap_fee_V1))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_swap_set_fee_destination_V1(c, &method->basic.swap_set_fee_destination_V1))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_xxcmix_set_scheduling_account_V1(c, &method->basic.xxcmix_set_scheduling_account_V1))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_xxcmix_set_cmix_address_space_V1(c, &method->basic.xxcmix_set_cmix_address_space_V1))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_xxcmix_set_admin_permission_V1(c, &method->basic.xxcmix_set_admin_permission_V1))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_xxeconomics_set_liquidity_rewards_stake_V1(c, &method->basic.xxeconomics_set_liquidity_rewards_stake_V1))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_xxeconomics_set_liquidity_rewards_balance_V1(c, &method->basic.xxeconomics_set_liquidity_rewards_balance_V1))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_xxcustody_payout_V1(c, &method->basic.xxcustody_payout_V1))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_xxcustody_custody_bond_V1(c, &method->basic.xxcustody_custody_bond_V1))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_xxcustody_custody_bond_extra_V1(c, &method->basic.xxcustody_custody_bond_extra_V1))
        break;
    case 8195: /* module 32 call 3 */
        CHECK_ERROR(_readMethod_xxcustody_custody_set_controller_V1(c, &method->basic.xxcustody_custody_set_controller_V1))
        break;
    case 8196: /* module 32 call 4 */
        CHECK_ERROR(_readMethod_xxcustody_custody_set_proxy_V1(c, &method->basic.xxcustody_custody_set_proxy_V1))
        break;
    case 8197: /* module 32 call 5 */
        CHECK_ERROR(_readMethod_xxcustody_team_custody_set_proxy_V1(c, &method->basic.xxcustody_team_custody_set_proxy_V1))
        break;
    case 8198: /* module 32 call 6 */
        CHECK_ERROR(_readMethod_xxcustody_add_custodian_V1(c, &method->basic.xxcustody_add_custodian_V1))
        break;
    case 8199: /* module 32 call 7 */
        CHECK_ERROR(_readMethod_xxcustody_remove_custodian_V1(c, &method->basic.xxcustody_remove_custodian_V1))
        break;
    case 8200: /* module 32 call 8 */
        CHECK_ERROR(_readMethod_xxcustody_replace_team_member_V1(c, &method->basic.xxcustody_replace_team_member_V1))
        break;
    case 8449: /* module 33 call 1 */
        CHECK_ERROR(_readMethod_xxbetanetrewards_approve_V1(c, &method->basic.xxbetanetrewards_approve_V1))
        break;
    case 8704: /* module 34 call 0 */
        CHECK_ERROR(_readMethod_xxpublic_set_testnet_manager_account_V1(c, &method->basic.xxpublic_set_testnet_manager_account_V1))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V1(c, &method->nested.multisig_as_multi_threshold_1_V1))
        break;
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V1(c, &method->nested.multisig_as_multi_V1))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V1(c, &method->nested.multisig_approve_as_multi_V1))
        break;
    case 8963: /* module 35 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V1(c, &method->nested.multisig_cancel_as_multi_V1))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V1(c, &method->basic.recovery_set_recovered_V1))
        break;
    case 9219: /* module 36 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V1(c, &method->basic.recovery_initiate_recovery_V1))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V1(c, &method->basic.recovery_vouch_recovery_V1))
        break;
    case 9221: /* module 36 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V1(c, &method->basic.recovery_claim_recovery_V1))
        break;
    case 9222: /* module 36 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V1(c, &method->basic.recovery_close_recovery_V1))
        break;
    case 9223: /* module 36 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V1(c, &method->basic.recovery_remove_recovery_V1))
        break;
    case 9224: /* module 36 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V1(c, &method->basic.recovery_cancel_recovered_V1))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_assets_force_create_V1(c, &method->basic.assets_force_create_V1))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_assets_mint_V1(c, &method->basic.assets_mint_V1))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_assets_burn_V1(c, &method->basic.assets_burn_V1))
        break;
    case 9477: /* module 37 call 5 */
        CHECK_ERROR(_readMethod_assets_transfer_V1(c, &method->basic.assets_transfer_V1))
        break;
    case 9478: /* module 37 call 6 */
        CHECK_ERROR(_readMethod_assets_transfer_keep_alive_V1(c, &method->basic.assets_transfer_keep_alive_V1))
        break;
    case 9479: /* module 37 call 7 */
        CHECK_ERROR(_readMethod_assets_force_transfer_V1(c, &method->basic.assets_force_transfer_V1))
        break;
    case 9480: /* module 37 call 8 */
        CHECK_ERROR(_readMethod_assets_freeze_V1(c, &method->basic.assets_freeze_V1))
        break;
    case 9481: /* module 37 call 9 */
        CHECK_ERROR(_readMethod_assets_thaw_V1(c, &method->basic.assets_thaw_V1))
        break;
    case 9482: /* module 37 call 10 */
        CHECK_ERROR(_readMethod_assets_freeze_asset_V1(c, &method->basic.assets_freeze_asset_V1))
        break;
    case 9483: /* module 37 call 11 */
        CHECK_ERROR(_readMethod_assets_thaw_asset_V1(c, &method->basic.assets_thaw_asset_V1))
        break;
    case 9484: /* module 37 call 12 */
        CHECK_ERROR(_readMethod_assets_transfer_ownership_V1(c, &method->basic.assets_transfer_ownership_V1))
        break;
    case 9485: /* module 37 call 13 */
        CHECK_ERROR(_readMethod_assets_set_team_V1(c, &method->basic.assets_set_team_V1))
        break;
    case 9486: /* module 37 call 14 */
        CHECK_ERROR(_readMethod_assets_set_metadata_V1(c, &method->basic.assets_set_metadata_V1))
        break;
    case 9487: /* module 37 call 15 */
        CHECK_ERROR(_readMethod_assets_clear_metadata_V1(c, &method->basic.assets_clear_metadata_V1))
        break;
    case 9488: /* module 37 call 16 */
        CHECK_ERROR(_readMethod_assets_force_set_metadata_V1(c, &method->basic.assets_force_set_metadata_V1))
        break;
    case 9489: /* module 37 call 17 */
        CHECK_ERROR(_readMethod_assets_force_clear_metadata_V1(c, &method->basic.assets_force_clear_metadata_V1))
        break;
    case 9490: /* module 37 call 18 */
        CHECK_ERROR(_readMethod_assets_force_asset_status_V1(c, &method->basic.assets_force_asset_status_V1))
        break;
    case 9491: /* module 37 call 19 */
        CHECK_ERROR(_readMethod_assets_approve_transfer_V1(c, &method->basic.assets_approve_transfer_V1))
        break;
    case 9492: /* module 37 call 20 */
        CHECK_ERROR(_readMethod_assets_cancel_approval_V1(c, &method->basic.assets_cancel_approval_V1))
        break;
    case 9493: /* module 37 call 21 */
        CHECK_ERROR(_readMethod_assets_force_cancel_approval_V1(c, &method->basic.assets_force_cancel_approval_V1))
        break;
    case 9494: /* module 37 call 22 */
        CHECK_ERROR(_readMethod_assets_transfer_approved_V1(c, &method->basic.assets_transfer_approved_V1))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_uniques_create_V1(c, &method->basic.uniques_create_V1))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_uniques_force_create_V1(c, &method->basic.uniques_force_create_V1))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_uniques_mint_V1(c, &method->basic.uniques_mint_V1))
        break;
    case 9733: /* module 38 call 5 */
        CHECK_ERROR(_readMethod_uniques_transfer_V1(c, &method->basic.uniques_transfer_V1))
        break;
    case 9735: /* module 38 call 7 */
        CHECK_ERROR(_readMethod_uniques_freeze_V1(c, &method->basic.uniques_freeze_V1))
        break;
    case 9736: /* module 38 call 8 */
        CHECK_ERROR(_readMethod_uniques_thaw_V1(c, &method->basic.uniques_thaw_V1))
        break;
    case 9737: /* module 38 call 9 */
        CHECK_ERROR(_readMethod_uniques_freeze_class_V1(c, &method->basic.uniques_freeze_class_V1))
        break;
    case 9738: /* module 38 call 10 */
        CHECK_ERROR(_readMethod_uniques_thaw_class_V1(c, &method->basic.uniques_thaw_class_V1))
        break;
    case 9739: /* module 38 call 11 */
        CHECK_ERROR(_readMethod_uniques_transfer_ownership_V1(c, &method->basic.uniques_transfer_ownership_V1))
        break;
    case 9740: /* module 38 call 12 */
        CHECK_ERROR(_readMethod_uniques_set_team_V1(c, &method->basic.uniques_set_team_V1))
        break;
    case 9741: /* module 38 call 13 */
        CHECK_ERROR(_readMethod_uniques_approve_transfer_V1(c, &method->basic.uniques_approve_transfer_V1))
        break;
    case 9743: /* module 38 call 15 */
        CHECK_ERROR(_readMethod_uniques_force_asset_status_V1(c, &method->basic.uniques_force_asset_status_V1))
        break;
    case 9747: /* module 38 call 19 */
        CHECK_ERROR(_readMethod_uniques_clear_metadata_V1(c, &method->basic.uniques_clear_metadata_V1))
        break;
    case 9749: /* module 38 call 21 */
        CHECK_ERROR(_readMethod_uniques_clear_class_metadata_V1(c, &method->basic.uniques_clear_class_metadata_V1))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V1(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 4:
        return STR_MO_BALANCES;
    case 6:
        return STR_MO_STAKING;
    case 9:
        return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 3:
        return STR_MO_TIMESTAMP;
    case 10:
        return STR_MO_GRANDPA;
    case 14:
        return STR_MO_COUNCIL;
    case 15:
        return STR_MO_TECHNICALCOMMITTEE;
    case 16:
        return STR_MO_ELECTIONS;
    case 17:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 18:
        return STR_MO_TREASURY;
    case 19:
        return STR_MO_CLAIMS;
    case 20:
        return STR_MO_VESTING;
    case 21:
        return STR_MO_UTILITY;
    case 22:
        return STR_MO_IDENTITY;
    case 23:
        return STR_MO_PROXY;
    case 26:
        return STR_MO_BOUNTIES;
    case 27:
        return STR_MO_TIPS;
    case 28:
        return STR_MO_CHAINBRIDGE;
    case 29:
        return STR_MO_SWAP;
    case 30:
        return STR_MO_XXCMIX;
    case 31:
        return STR_MO_XXECONOMICS;
    case 32:
        return STR_MO_XXCUSTODY;
    case 33:
        return STR_MO_XXBETANETREWARDS;
    case 34:
        return STR_MO_XXPUBLIC;
    case 35:
        return STR_MO_MULTISIG;
    case 36:
        return STR_MO_RECOVERY;
    case 37:
        return STR_MO_ASSETS;
    case 38:
        return STR_MO_UNIQUES;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return STR_ME_TRANSFER;
    case 1026: /* module 4 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1027: /* module 4 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1028: /* module 4 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 1536: /* module 6 call 0 */
        return STR_ME_BOND;
    case 1537: /* module 6 call 1 */
        return STR_ME_BOND_EXTRA;
    case 1538: /* module 6 call 2 */
        return STR_ME_UNBOND;
    case 1539: /* module 6 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 1540: /* module 6 call 4 */
        return STR_ME_VALIDATE;
    case 1541: /* module 6 call 5 */
        return STR_ME_NOMINATE;
    case 1542: /* module 6 call 6 */
        return STR_ME_CHILL;
    case 1543: /* module 6 call 7 */
        return STR_ME_SET_CONTROLLER;
    case 1553: /* module 6 call 17 */
        return STR_ME_PAYOUT_STAKERS;
    case 1554: /* module 6 call 18 */
        return STR_ME_REBOND;
    case 2304: /* module 9 call 0 */
        return STR_ME_SET_KEYS;
    case 2305: /* module 9 call 1 */
        return STR_ME_PURGE_KEYS;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 5: /* module 0 call 5 */
        return STR_ME_SET_STORAGE;
    case 6: /* module 0 call 6 */
        return STR_ME_KILL_STORAGE;
    case 7: /* module 0 call 7 */
        return STR_ME_KILL_PREFIX;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 256: /* module 1 call 0 */
        return STR_ME_SCHEDULE;
    case 257: /* module 1 call 1 */
        return STR_ME_CANCEL;
    case 258: /* module 1 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 259: /* module 1 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 260: /* module 1 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 261: /* module 1 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 512: /* module 2 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 513: /* module 2 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 514: /* module 2 call 2 */
        return STR_ME_PLAN_CONFIG_CHANGE;
    case 768: /* module 3 call 0 */
        return STR_ME_SET;
    case 1025: /* module 4 call 1 */
        return STR_ME_SET_BALANCE;
    case 1029: /* module 4 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1280: /* module 5 call 0 */
        return STR_ME_SET_UNCLES;
    case 1544: /* module 6 call 8 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 1545: /* module 6 call 9 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 1546: /* module 6 call 10 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 1547: /* module 6 call 11 */
        return STR_ME_FORCE_NO_ERAS;
    case 1548: /* module 6 call 12 */
        return STR_ME_FORCE_NEW_ERA;
    case 1549: /* module 6 call 13 */
        return STR_ME_SET_INVULNERABLES;
    case 1550: /* module 6 call 14 */
        return STR_ME_FORCE_UNSTAKE;
    case 1551: /* module 6 call 15 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 1552: /* module 6 call 16 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 1555: /* module 6 call 19 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 1556: /* module 6 call 20 */
        return STR_ME_REAP_STASH;
    case 1557: /* module 6 call 21 */
        return STR_ME_KICK;
    case 1558: /* module 6 call 22 */
        return STR_ME_SET_STAKING_LIMITS;
    case 1559: /* module 6 call 23 */
        return STR_ME_CHILL_OTHER;
    case 1560: /* module 6 call 24 */
        return STR_ME_SET_CMIX_ID;
    case 1561: /* module 6 call 25 */
        return STR_ME_TRANSFER_CMIX_ID;
    case 1792: /* module 7 call 0 */
        return STR_ME_SUBMIT_UNSIGNED;
    case 1793: /* module 7 call 1 */
        return STR_ME_SET_MINIMUM_UNTRUSTED_SCORE;
    case 1794: /* module 7 call 2 */
        return STR_ME_SET_EMERGENCY_ELECTION_RESULT;
    case 1795: /* module 7 call 3 */
        return STR_ME_SUBMIT;
    case 2560: /* module 10 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 2561: /* module 10 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 2562: /* module 10 call 2 */
        return STR_ME_NOTE_STALLED;
    case 2816: /* module 11 call 0 */
        return STR_ME_HEARTBEAT;
    case 3328: /* module 13 call 0 */
        return STR_ME_PROPOSE;
    case 3329: /* module 13 call 1 */
        return STR_ME_SECOND;
    case 3330: /* module 13 call 2 */
        return STR_ME_VOTE;
    case 3331: /* module 13 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 3332: /* module 13 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 3333: /* module 13 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 3334: /* module 13 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 3335: /* module 13 call 7 */
        return STR_ME_FAST_TRACK;
    case 3336: /* module 13 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 3337: /* module 13 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 3338: /* module 13 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 3339: /* module 13 call 11 */
        return STR_ME_DELEGATE;
    case 3340: /* module 13 call 12 */
        return STR_ME_UNDELEGATE;
    case 3341: /* module 13 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 3342: /* module 13 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 3343: /* module 13 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 3344: /* module 13 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 3345: /* module 13 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 3346: /* module 13 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 3347: /* module 13 call 19 */
        return STR_ME_UNLOCK;
    case 3348: /* module 13 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 3349: /* module 13 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 3350: /* module 13 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 3351: /* module 13 call 23 */
        return STR_ME_BLACKLIST;
    case 3352: /* module 13 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 3584: /* module 14 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3585: /* module 14 call 1 */
        return STR_ME_EXECUTE;
    case 3586: /* module 14 call 2 */
        return STR_ME_PROPOSE;
    case 3587: /* module 14 call 3 */
        return STR_ME_VOTE;
    case 3588: /* module 14 call 4 */
        return STR_ME_CLOSE;
    case 3589: /* module 14 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3840: /* module 15 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3841: /* module 15 call 1 */
        return STR_ME_EXECUTE;
    case 3842: /* module 15 call 2 */
        return STR_ME_PROPOSE;
    case 3843: /* module 15 call 3 */
        return STR_ME_VOTE;
    case 3844: /* module 15 call 4 */
        return STR_ME_CLOSE;
    case 3845: /* module 15 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_VOTE;
    case 4097: /* module 16 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 4098: /* module 16 call 2 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 4099: /* module 16 call 3 */
        return STR_ME_RENOUNCE_CANDIDACY;
    case 4100: /* module 16 call 4 */
        return STR_ME_REMOVE_MEMBER;
    case 4101: /* module 16 call 5 */
        return STR_ME_CLEAN_DEFUNCT_VOTERS;
    case 4352: /* module 17 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4353: /* module 17 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4354: /* module 17 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4355: /* module 17 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4356: /* module 17 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4357: /* module 17 call 5 */
        return STR_ME_SET_PRIME;
    case 4358: /* module 17 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 4608: /* module 18 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4609: /* module 18 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4610: /* module 18 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4864: /* module 19 call 0 */
        return STR_ME_CLAIM;
    case 4865: /* module 19 call 1 */
        return STR_ME_MINT_CLAIM;
    case 4866: /* module 19 call 2 */
        return STR_ME_CLAIM_ATTEST;
    case 4867: /* module 19 call 3 */
        return STR_ME_ATTEST;
    case 4868: /* module 19 call 4 */
        return STR_ME_MOVE_CLAIM;
    case 5120: /* module 20 call 0 */
        return STR_ME_VEST;
    case 5121: /* module 20 call 1 */
        return STR_ME_VEST_OTHER;
    case 5122: /* module 20 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 5123: /* module 20 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 5124: /* module 20 call 4 */
        return STR_ME_MERGE_SCHEDULES;
    case 5376: /* module 21 call 0 */
        return STR_ME_BATCH;
    case 5377: /* module 21 call 1 */
        return STR_ME_AS_DERIVATIVE;
    case 5378: /* module 21 call 2 */
        return STR_ME_BATCH_ALL;
    case 5379: /* module 21 call 3 */
        return STR_ME_DISPATCH_AS;
    case 5632: /* module 22 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 5633: /* module 22 call 1 */
        return STR_ME_SET_IDENTITY;
    case 5634: /* module 22 call 2 */
        return STR_ME_SET_SUBS;
    case 5635: /* module 22 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 5636: /* module 22 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 5637: /* module 22 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 5638: /* module 22 call 6 */
        return STR_ME_SET_FEE;
    case 5639: /* module 22 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 5640: /* module 22 call 8 */
        return STR_ME_SET_FIELDS;
    case 5641: /* module 22 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 5642: /* module 22 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 5643: /* module 22 call 11 */
        return STR_ME_ADD_SUB;
    case 5644: /* module 22 call 12 */
        return STR_ME_RENAME_SUB;
    case 5645: /* module 22 call 13 */
        return STR_ME_REMOVE_SUB;
    case 5646: /* module 22 call 14 */
        return STR_ME_QUIT_SUB;
    case 5888: /* module 23 call 0 */
        return STR_ME_PROXY;
    case 5889: /* module 23 call 1 */
        return STR_ME_ADD_PROXY;
    case 5890: /* module 23 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 5891: /* module 23 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 5892: /* module 23 call 4 */
        return STR_ME_ANONYMOUS;
    case 5893: /* module 23 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 5894: /* module 23 call 6 */
        return STR_ME_ANNOUNCE;
    case 5895: /* module 23 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 5896: /* module 23 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 5897: /* module 23 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 6656: /* module 26 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 6657: /* module 26 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 6658: /* module 26 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 6659: /* module 26 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 6660: /* module 26 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 6661: /* module 26 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 6662: /* module 26 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 6663: /* module 26 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 6664: /* module 26 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 6912: /* module 27 call 0 */
        return STR_ME_REPORT_AWESOME;
    case 6913: /* module 27 call 1 */
        return STR_ME_RETRACT_TIP;
    case 6914: /* module 27 call 2 */
        return STR_ME_TIP_NEW;
    case 6915: /* module 27 call 3 */
        return STR_ME_TIP;
    case 6916: /* module 27 call 4 */
        return STR_ME_CLOSE_TIP;
    case 6917: /* module 27 call 5 */
        return STR_ME_SLASH_TIP;
    case 7168: /* module 28 call 0 */
        return STR_ME_SET_THRESHOLD;
    case 7169: /* module 28 call 1 */
        return STR_ME_SET_RESOURCE;
    case 7170: /* module 28 call 2 */
        return STR_ME_REMOVE_RESOURCE;
    case 7171: /* module 28 call 3 */
        return STR_ME_WHITELIST_CHAIN;
    case 7172: /* module 28 call 4 */
        return STR_ME_ADD_RELAYER;
    case 7173: /* module 28 call 5 */
        return STR_ME_REMOVE_RELAYER;
    case 7174: /* module 28 call 6 */
        return STR_ME_ACKNOWLEDGE_PROPOSAL;
    case 7175: /* module 28 call 7 */
        return STR_ME_REJECT_PROPOSAL;
    case 7176: /* module 28 call 8 */
        return STR_ME_EVAL_VOTE_STATE;
    case 7424: /* module 29 call 0 */
        return STR_ME_TRANSFER_NATIVE;
    case 7425: /* module 29 call 1 */
        return STR_ME_TRANSFER;
    case 7426: /* module 29 call 2 */
        return STR_ME_SET_SWAP_FEE;
    case 7427: /* module 29 call 3 */
        return STR_ME_SET_FEE_DESTINATION;
    case 7680: /* module 30 call 0 */
        return STR_ME_SET_CMIX_HASHES;
    case 7681: /* module 30 call 1 */
        return STR_ME_SET_SCHEDULING_ACCOUNT;
    case 7682: /* module 30 call 2 */
        return STR_ME_SET_NEXT_CMIX_VARIABLES;
    case 7683: /* module 30 call 3 */
        return STR_ME_SUBMIT_CMIX_POINTS;
    case 7684: /* module 30 call 4 */
        return STR_ME_SUBMIT_CMIX_DEDUCTIONS;
    case 7685: /* module 30 call 5 */
        return STR_ME_SET_CMIX_ADDRESS_SPACE;
    case 7686: /* module 30 call 6 */
        return STR_ME_SET_ADMIN_PERMISSION;
    case 7936: /* module 31 call 0 */
        return STR_ME_SET_INFLATION_PARAMS;
    case 7937: /* module 31 call 1 */
        return STR_ME_SET_INTEREST_POINTS;
    case 7938: /* module 31 call 2 */
        return STR_ME_SET_LIQUIDITY_REWARDS_STAKE;
    case 7939: /* module 31 call 3 */
        return STR_ME_SET_LIQUIDITY_REWARDS_BALANCE;
    case 8192: /* module 32 call 0 */
        return STR_ME_PAYOUT;
    case 8193: /* module 32 call 1 */
        return STR_ME_CUSTODY_BOND;
    case 8194: /* module 32 call 2 */
        return STR_ME_CUSTODY_BOND_EXTRA;
    case 8195: /* module 32 call 3 */
        return STR_ME_CUSTODY_SET_CONTROLLER;
    case 8196: /* module 32 call 4 */
        return STR_ME_CUSTODY_SET_PROXY;
    case 8197: /* module 32 call 5 */
        return STR_ME_TEAM_CUSTODY_SET_PROXY;
    case 8198: /* module 32 call 6 */
        return STR_ME_ADD_CUSTODIAN;
    case 8199: /* module 32 call 7 */
        return STR_ME_REMOVE_CUSTODIAN;
    case 8200: /* module 32 call 8 */
        return STR_ME_REPLACE_TEAM_MEMBER;
    case 8448: /* module 33 call 0 */
        return STR_ME_SELECT_OPTION;
    case 8449: /* module 33 call 1 */
        return STR_ME_APPROVE;
    case 8704: /* module 34 call 0 */
        return STR_ME_SET_TESTNET_MANAGER_ACCOUNT;
    case 8705: /* module 34 call 1 */
        return STR_ME_SET_SALE_MANAGER_ACCOUNT;
    case 8706: /* module 34 call 2 */
        return STR_ME_TESTNET_DISTRIBUTE;
    case 8707: /* module 34 call 3 */
        return STR_ME_SALE_DISTRIBUTE;
    case 8960: /* module 35 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 8961: /* module 35 call 1 */
        return STR_ME_AS_MULTI;
    case 8962: /* module 35 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 8963: /* module 35 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 9216: /* module 36 call 0 */
        return STR_ME_AS_RECOVERED;
    case 9217: /* module 36 call 1 */
        return STR_ME_SET_RECOVERED;
    case 9218: /* module 36 call 2 */
        return STR_ME_CREATE_RECOVERY;
    case 9219: /* module 36 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 9220: /* module 36 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 9221: /* module 36 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 9222: /* module 36 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 9223: /* module 36 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 9224: /* module 36 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    case 9472: /* module 37 call 0 */
        return STR_ME_CREATE;
    case 9473: /* module 37 call 1 */
        return STR_ME_FORCE_CREATE;
    case 9474: /* module 37 call 2 */
        return STR_ME_DESTROY;
    case 9475: /* module 37 call 3 */
        return STR_ME_MINT;
    case 9476: /* module 37 call 4 */
        return STR_ME_BURN;
    case 9477: /* module 37 call 5 */
        return STR_ME_TRANSFER;
    case 9478: /* module 37 call 6 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 9479: /* module 37 call 7 */
        return STR_ME_FORCE_TRANSFER;
    case 9480: /* module 37 call 8 */
        return STR_ME_FREEZE;
    case 9481: /* module 37 call 9 */
        return STR_ME_THAW;
    case 9482: /* module 37 call 10 */
        return STR_ME_FREEZE_ASSET;
    case 9483: /* module 37 call 11 */
        return STR_ME_THAW_ASSET;
    case 9484: /* module 37 call 12 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 9485: /* module 37 call 13 */
        return STR_ME_SET_TEAM;
    case 9486: /* module 37 call 14 */
        return STR_ME_SET_METADATA;
    case 9487: /* module 37 call 15 */
        return STR_ME_CLEAR_METADATA;
    case 9488: /* module 37 call 16 */
        return STR_ME_FORCE_SET_METADATA;
    case 9489: /* module 37 call 17 */
        return STR_ME_FORCE_CLEAR_METADATA;
    case 9490: /* module 37 call 18 */
        return STR_ME_FORCE_ASSET_STATUS;
    case 9491: /* module 37 call 19 */
        return STR_ME_APPROVE_TRANSFER;
    case 9492: /* module 37 call 20 */
        return STR_ME_CANCEL_APPROVAL;
    case 9493: /* module 37 call 21 */
        return STR_ME_FORCE_CANCEL_APPROVAL;
    case 9494: /* module 37 call 22 */
        return STR_ME_TRANSFER_APPROVED;
    case 9728: /* module 38 call 0 */
        return STR_ME_CREATE;
    case 9729: /* module 38 call 1 */
        return STR_ME_FORCE_CREATE;
    case 9730: /* module 38 call 2 */
        return STR_ME_DESTROY;
    case 9731: /* module 38 call 3 */
        return STR_ME_MINT;
    case 9732: /* module 38 call 4 */
        return STR_ME_BURN;
    case 9733: /* module 38 call 5 */
        return STR_ME_TRANSFER;
    case 9734: /* module 38 call 6 */
        return STR_ME_REDEPOSIT;
    case 9735: /* module 38 call 7 */
        return STR_ME_FREEZE;
    case 9736: /* module 38 call 8 */
        return STR_ME_THAW;
    case 9737: /* module 38 call 9 */
        return STR_ME_FREEZE_CLASS;
    case 9738: /* module 38 call 10 */
        return STR_ME_THAW_CLASS;
    case 9739: /* module 38 call 11 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 9740: /* module 38 call 12 */
        return STR_ME_SET_TEAM;
    case 9741: /* module 38 call 13 */
        return STR_ME_APPROVE_TRANSFER;
    case 9742: /* module 38 call 14 */
        return STR_ME_CANCEL_APPROVAL;
    case 9743: /* module 38 call 15 */
        return STR_ME_FORCE_ASSET_STATUS;
    case 9744: /* module 38 call 16 */
        return STR_ME_SET_ATTRIBUTE;
    case 9745: /* module 38 call 17 */
        return STR_ME_CLEAR_ATTRIBUTE;
    case 9746: /* module 38 call 18 */
        return STR_ME_SET_METADATA;
    case 9747: /* module 38 call 19 */
        return STR_ME_CLEAR_METADATA;
    case 9748: /* module 38 call 20 */
        return STR_ME_SET_CLASS_METADATA;
    case 9749: /* module 38 call 21 */
        return STR_ME_CLEAR_CLASS_METADATA;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 3;
    case 1027: /* module 4 call 3 */
        return 2;
    case 1028: /* module 4 call 4 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 3;
    case 1537: /* module 6 call 1 */
        return 1;
    case 1538: /* module 6 call 2 */
        return 1;
    case 1539: /* module 6 call 3 */
        return 1;
    case 1540: /* module 6 call 4 */
        return 1;
    case 1541: /* module 6 call 5 */
        return 1;
    case 1542: /* module 6 call 6 */
        return 0;
    case 1543: /* module 6 call 7 */
        return 1;
    case 1553: /* module 6 call 17 */
        return 2;
    case 1554: /* module 6 call 18 */
        return 1;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 0;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 1025: /* module 4 call 1 */
        return 3;
    case 1029: /* module 4 call 5 */
        return 2;
    case 1544: /* module 6 call 8 */
        return 1;
    case 1545: /* module 6 call 9 */
        return 1;
    case 1547: /* module 6 call 11 */
        return 0;
    case 1548: /* module 6 call 12 */
        return 0;
    case 1549: /* module 6 call 13 */
        return 1;
    case 1550: /* module 6 call 14 */
        return 2;
    case 1551: /* module 6 call 15 */
        return 0;
    case 1552: /* module 6 call 16 */
        return 2;
    case 1555: /* module 6 call 19 */
        return 2;
    case 1556: /* module 6 call 20 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 1;
    case 1559: /* module 6 call 23 */
        return 1;
    case 1560: /* module 6 call 24 */
        return 1;
    case 1561: /* module 6 call 25 */
        return 1;
    case 2562: /* module 10 call 2 */
        return 2;
    case 3584: /* module 14 call 0 */
        return 3;
    case 3587: /* module 14 call 3 */
        return 3;
    case 3588: /* module 14 call 4 */
        return 4;
    case 3589: /* module 14 call 5 */
        return 1;
    case 3840: /* module 15 call 0 */
        return 3;
    case 3843: /* module 15 call 3 */
        return 3;
    case 3844: /* module 15 call 4 */
        return 4;
    case 3845: /* module 15 call 5 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 2;
    case 4097: /* module 16 call 1 */
        return 0;
    case 4098: /* module 16 call 2 */
        return 1;
    case 4100: /* module 16 call 4 */
        return 2;
    case 4101: /* module 16 call 5 */
        return 2;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 1;
    case 4354: /* module 17 call 2 */
        return 2;
    case 4355: /* module 17 call 3 */
        return 1;
    case 4356: /* module 17 call 4 */
        return 1;
    case 4357: /* module 17 call 5 */
        return 1;
    case 4358: /* module 17 call 6 */
        return 0;
    case 4608: /* module 18 call 0 */
        return 2;
    case 4609: /* module 18 call 1 */
        return 1;
    case 4610: /* module 18 call 2 */
        return 1;
    case 4864: /* module 19 call 0 */
        return 2;
    case 4866: /* module 19 call 2 */
        return 3;
    case 4867: /* module 19 call 3 */
        return 1;
    case 4868: /* module 19 call 4 */
        return 3;
    case 5120: /* module 20 call 0 */
        return 0;
    case 5121: /* module 20 call 1 */
        return 1;
    case 5124: /* module 20 call 4 */
        return 2;
    case 5376: /* module 21 call 0 */
        return 1;
    case 5378: /* module 21 call 2 */
        return 1;
    case 5632: /* module 22 call 0 */
        return 1;
    case 5635: /* module 22 call 3 */
        return 0;
    case 5636: /* module 22 call 4 */
        return 2;
    case 5637: /* module 22 call 5 */
        return 1;
    case 5638: /* module 22 call 6 */
        return 2;
    case 5639: /* module 22 call 7 */
        return 2;
    case 5642: /* module 22 call 10 */
        return 1;
    case 5645: /* module 22 call 13 */
        return 1;
    case 5646: /* module 22 call 14 */
        return 0;
    case 5888: /* module 23 call 0 */
        return 3;
    case 5889: /* module 23 call 1 */
        return 3;
    case 5890: /* module 23 call 2 */
        return 3;
    case 5891: /* module 23 call 3 */
        return 0;
    case 5892: /* module 23 call 4 */
        return 3;
    case 5893: /* module 23 call 5 */
        return 5;
    case 5894: /* module 23 call 6 */
        return 2;
    case 5895: /* module 23 call 7 */
        return 2;
    case 5896: /* module 23 call 8 */
        return 2;
    case 5897: /* module 23 call 9 */
        return 4;
    case 6656: /* module 26 call 0 */
        return 2;
    case 6657: /* module 26 call 1 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 3;
    case 6659: /* module 26 call 3 */
        return 1;
    case 6660: /* module 26 call 4 */
        return 1;
    case 6661: /* module 26 call 5 */
        return 2;
    case 6662: /* module 26 call 6 */
        return 1;
    case 6663: /* module 26 call 7 */
        return 1;
    case 6664: /* module 26 call 8 */
        return 2;
    case 6912: /* module 27 call 0 */
        return 2;
    case 6913: /* module 27 call 1 */
        return 1;
    case 6914: /* module 27 call 2 */
        return 3;
    case 6915: /* module 27 call 3 */
        return 2;
    case 6916: /* module 27 call 4 */
        return 1;
    case 6917: /* module 27 call 5 */
        return 1;
    case 7168: /* module 28 call 0 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 1;
    case 7172: /* module 28 call 4 */
        return 1;
    case 7173: /* module 28 call 5 */
        return 1;
    case 7425: /* module 29 call 1 */
        return 2;
    case 7426: /* module 29 call 2 */
        return 1;
    case 7427: /* module 29 call 3 */
        return 1;
    case 7681: /* module 30 call 1 */
        return 1;
    case 7685: /* module 30 call 5 */
        return 1;
    case 7686: /* module 30 call 6 */
        return 1;
    case 7938: /* module 31 call 2 */
        return 1;
    case 7939: /* module 31 call 3 */
        return 1;
    case 8192: /* module 32 call 0 */
        return 1;
    case 8193: /* module 32 call 1 */
        return 3;
    case 8194: /* module 32 call 2 */
        return 2;
    case 8195: /* module 32 call 3 */
        return 2;
    case 8196: /* module 32 call 4 */
        return 2;
    case 8197: /* module 32 call 5 */
        return 1;
    case 8198: /* module 32 call 6 */
        return 1;
    case 8199: /* module 32 call 7 */
        return 1;
    case 8200: /* module 32 call 8 */
        return 2;
    case 8449: /* module 33 call 1 */
        return 0;
    case 8704: /* module 34 call 0 */
        return 1;
    case 8960: /* module 35 call 0 */
        return 2;
    case 8961: /* module 35 call 1 */
        return 6;
    case 8962: /* module 35 call 2 */
        return 5;
    case 8963: /* module 35 call 3 */
        return 4;
    case 9217: /* module 36 call 1 */
        return 2;
    case 9219: /* module 36 call 3 */
        return 1;
    case 9220: /* module 36 call 4 */
        return 2;
    case 9221: /* module 36 call 5 */
        return 1;
    case 9222: /* module 36 call 6 */
        return 1;
    case 9223: /* module 36 call 7 */
        return 0;
    case 9224: /* module 36 call 8 */
        return 1;
    case 9473: /* module 37 call 1 */
        return 4;
    case 9475: /* module 37 call 3 */
        return 3;
    case 9476: /* module 37 call 4 */
        return 3;
    case 9477: /* module 37 call 5 */
        return 3;
    case 9478: /* module 37 call 6 */
        return 3;
    case 9479: /* module 37 call 7 */
        return 4;
    case 9480: /* module 37 call 8 */
        return 2;
    case 9481: /* module 37 call 9 */
        return 2;
    case 9482: /* module 37 call 10 */
        return 1;
    case 9483: /* module 37 call 11 */
        return 1;
    case 9484: /* module 37 call 12 */
        return 2;
    case 9485: /* module 37 call 13 */
        return 4;
    case 9486: /* module 37 call 14 */
        return 4;
    case 9487: /* module 37 call 15 */
        return 1;
    case 9488: /* module 37 call 16 */
        return 5;
    case 9489: /* module 37 call 17 */
        return 1;
    case 9490: /* module 37 call 18 */
        return 8;
    case 9491: /* module 37 call 19 */
        return 3;
    case 9492: /* module 37 call 20 */
        return 2;
    case 9493: /* module 37 call 21 */
        return 3;
    case 9494: /* module 37 call 22 */
        return 4;
    case 9728: /* module 38 call 0 */
        return 2;
    case 9729: /* module 38 call 1 */
        return 3;
    case 9731: /* module 38 call 3 */
        return 3;
    case 9733: /* module 38 call 5 */
        return 3;
    case 9735: /* module 38 call 7 */
        return 2;
    case 9736: /* module 38 call 8 */
        return 2;
    case 9737: /* module 38 call 9 */
        return 1;
    case 9738: /* module 38 call 10 */
        return 1;
    case 9739: /* module 38 call 11 */
        return 2;
    case 9740: /* module 38 call 12 */
        return 4;
    case 9741: /* module 38 call 13 */
        return 3;
    case 9743: /* module 38 call 15 */
        return 7;
    case 9747: /* module 38 call 19 */
        return 2;
    case 9749: /* module 38 call 21 */
        return 1;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_cmix_id;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT_era_items_deleted;
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_cmix_id;
        default:
            return NULL;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_has_replacement;
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_voters;
        case 1:
            return STR_IT_num_defunct;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        case 2:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_old;
        case 1:
            return STR_IT_new_;
        case 2:
            return STR_IT_maybe_preclaim;
        default:
            return NULL;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule1_index;
        case 1:
            return STR_IT_schedule2_index;
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 5638: /* module 22 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 5639: /* module 22 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5642: /* module 22 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5645: /* module 22 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 5646: /* module 22 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 5897: /* module 23 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        case 1:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_v;
        default:
            return NULL;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_v;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_size;
        default:
            return NULL;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_permission;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_custody;
        case 1:
            return STR_IT_controller;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_custody;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_custody;
        case 1:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 8196: /* module 32 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_custody;
        case 1:
            return STR_IT_proxy;
        default:
            return NULL;
        }
    case 8197: /* module 32 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy;
        default:
            return NULL;
        }
    case 8198: /* module 32 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_custodian;
        default:
            return NULL;
        }
    case 8199: /* module 32 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_custodian;
        default:
            return NULL;
        }
    case 8200: /* module 32 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 8449: /* module 33 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 9222: /* module 36 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 9223: /* module 36 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 9224: /* module 36 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_is_sufficient;
        case 3:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_source;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9481: /* module 37 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9482: /* module 37 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9483: /* module 37 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9484: /* module 37 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 9485: /* module 37 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_issuer;
        case 2:
            return STR_IT_admin;
        case 3:
            return STR_IT_freezer;
        default:
            return NULL;
        }
    case 9486: /* module 37 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_symbol;
        case 3:
            return STR_IT_decimals;
        default:
            return NULL;
        }
    case 9487: /* module 37 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9488: /* module 37 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_symbol;
        case 3:
            return STR_IT_decimals;
        case 4:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 9489: /* module 37 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9490: /* module 37 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_issuer;
        case 3:
            return STR_IT_admin;
        case 4:
            return STR_IT_freezer;
        case 5:
            return STR_IT_min_balance;
        case 6:
            return STR_IT_is_sufficient;
        case 7:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 9491: /* module 37 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9492: /* module 37 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 9493: /* module 37 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 9494: /* module 37 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_destination;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_admin;
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_free_holding;
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_instance;
        case 2:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_instance;
        case 2:
            return STR_IT_dest;
        default:
            return NULL;
        }
    case 9735: /* module 38 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_instance;
        default:
            return NULL;
        }
    case 9736: /* module 38 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_instance;
        default:
            return NULL;
        }
    case 9737: /* module 38 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        default:
            return NULL;
        }
    case 9738: /* module 38 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        default:
            return NULL;
        }
    case 9739: /* module 38 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 9740: /* module 38 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_issuer;
        case 2:
            return STR_IT_admin;
        case 3:
            return STR_IT_freezer;
        default:
            return NULL;
        }
    case 9741: /* module 38 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_instance;
        case 2:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 9743: /* module 38 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_issuer;
        case 3:
            return STR_IT_admin;
        case 4:
            return STR_IT_freezer;
        case 5:
            return STR_IT_free_holding;
        case 6:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 9747: /* module 38 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        case 1:
            return STR_IT_instance;
        default:
            return NULL;
        }
    case 9749: /* module 38 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_class_;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(
    pd_Method_V1_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V1 - source */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_force_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_force_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_transfer_keep_alive_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.balances_transfer_all_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V1 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V1.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_bond_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V1 - cmix_id */;
            return _toStringOptionHash(
                &m->basic.staking_bond_V1.cmix_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_extra_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_unbond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V1 - prefs */;
            return _toStringValidatorPrefs_V1(
                &m->basic.staking_validate_V1.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V1 - targets */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_nominate_V1.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_set_controller_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V1 - validator_stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_payout_stakers_V1.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_payout_stakers_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_rebond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V1 - keys */;
            return _toStringKeys_V1(
                &m->basic.session_set_keys_V1.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V1 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V1.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V1 - ratio */;
            return _toStringPerbill_V1(
                &m->nested.system_fill_block_V1.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V1 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V1.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V1 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V1 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V1 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V1.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_set_balance_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V1 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V1.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V1 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V1.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.balances_force_unreserve_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V1 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V1 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V1 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V1.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V1 - invulnerables */;
            return _toStringVecAccountId_V1(
                &m->basic.staking_set_invulnerables_V1.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_force_unstake_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_cancel_deferred_slash_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V1 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V1.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V1 - new_history_depth */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V1.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V1 - era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V1.era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_reap_stash_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* staking_kick_V1 - who */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_kick_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V1 - controller */;
            return _toStringAccountId_V1(
                &m->basic.staking_chill_other_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* staking_set_cmix_id_V1 - cmix_id */;
            return _toStringHash(
                &m->basic.staking_set_cmix_id_V1.cmix_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0: /* staking_transfer_cmix_id_V1 - dest */;
            return _toStringAccountId_V1(
                &m->basic.staking_transfer_cmix_id_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V1 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V1 - new_members */;
            return _toStringVecAccountId_V1(
                &m->basic.council_set_members_V1.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V1 - prime */;
            return _toStringOptionAccountId_V1(
                &m->basic.council_set_members_V1.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V1 - old_count */;
            return _toStringMemberCount_V1(
                &m->basic.council_set_members_V1.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V1 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V1 - index */;
            return _toStringCompactu32(
                &m->basic.council_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V1 - index */;
            return _toStringCompactu32(
                &m->basic.council_close_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V1 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.council_close_V1.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V1 - new_members */;
            return _toStringVecAccountId_V1(
                &m->basic.technicalcommittee_set_members_V1.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V1 - prime */;
            return _toStringOptionAccountId_V1(
                &m->basic.technicalcommittee_set_members_V1.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V1 - old_count */;
            return _toStringMemberCount_V1(
                &m->basic.technicalcommittee_set_members_V1.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V1 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V1 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V1 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V1 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.technicalcommittee_close_V1.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* elections_vote_V1 - votes */;
            return _toStringVecAccountId_V1(
                &m->basic.elections_vote_V1.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_vote_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.elections_vote_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* elections_submit_candidacy_V1 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.elections_submit_candidacy_V1.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* elections_remove_member_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.elections_remove_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_remove_member_V1 - has_replacement */;
            return _toStringbool(
                &m->basic.elections_remove_member_V1.has_replacement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* elections_clean_defunct_voters_V1 - num_voters */;
            return _toStringu32(
                &m->basic.elections_clean_defunct_voters_V1.num_voters,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_clean_defunct_voters_V1 - num_defunct */;
            return _toStringu32(
                &m->basic.elections_clean_defunct_voters_V1.num_defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_add_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_remove_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V1 - remove */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_swap_member_V1.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V1 - add */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_swap_member_V1.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V1 - members */;
            return _toStringVecAccountId_V1(
                &m->basic.technicalmembership_reset_members_V1.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_change_key_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_set_prime_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V1 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.treasury_propose_spend_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V1 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V1 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* claims_claim_V1 - dest */;
            return _toStringAccountId_V1(
                &m->basic.claims_claim_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_V1 - ethereum_signature */;
            return _toStringEcdsaSignature_V1(
                &m->basic.claims_claim_V1.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* claims_claim_attest_V1 - dest */;
            return _toStringAccountId_V1(
                &m->basic.claims_claim_attest_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_attest_V1 - ethereum_signature */;
            return _toStringEcdsaSignature_V1(
                &m->basic.claims_claim_attest_V1.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_claim_attest_V1 - statement */;
            return _toStringBytes(
                &m->basic.claims_claim_attest_V1.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* claims_attest_V1 - statement */;
            return _toStringBytes(
                &m->basic.claims_attest_V1.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* claims_move_claim_V1 - old */;
            return _toStringEthereumAddress_V1(
                &m->basic.claims_move_claim_V1.old,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_move_claim_V1 - new_ */;
            return _toStringEthereumAddress_V1(
                &m->basic.claims_move_claim_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_move_claim_V1 - maybe_preclaim */;
            return _toStringOptionAccountId_V1(
                &m->basic.claims_move_claim_V1.maybe_preclaim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.vesting_vest_other_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V1 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V1.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V1 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V1.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.identity_add_registrar_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V1 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V1 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V1.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5637: /* module 22 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V1 - reg_index */;
            return _toStringRegistrarIndex_V1(
                &m->basic.identity_cancel_request_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5638: /* module 22 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V1 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V1 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5639: /* module 22 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V1 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.identity_set_account_id_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5642: /* module 22 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.identity_kill_identity_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5645: /* module 22 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V1 - sub */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.identity_remove_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5646: /* module 22 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V1 - real */;
            return _toStringAccountId_V1(
                &m->nested.proxy_proxy_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->nested.proxy_proxy_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V1 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_add_proxy_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_add_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_remove_proxy_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_remove_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V1 - spawner */;
            return _toStringAccountId_V1(
                &m->basic.proxy_kill_anonymous_V1.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_kill_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V1 - height */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V1.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V1 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V1.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_announce_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V1 - call_hash */;
            return _toStringCallHashOf_V1(
                &m->basic.proxy_announce_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_remove_announcement_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V1 - call_hash */;
            return _toStringCallHashOf_V1(
                &m->basic.proxy_remove_announcement_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_reject_announcement_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V1 - call_hash */;
            return _toStringCallHashOf_V1(
                &m->basic.proxy_reject_announcement_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5897: /* module 23 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_announced_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_announced_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->basic.proxy_proxy_announced_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V1 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_bounty_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V1 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V1.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_approve_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_propose_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V1 - curator */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.bounties_propose_curator_V1.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V1 - fee */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_curator_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_unassign_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_accept_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_award_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V1 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.bounties_award_bounty_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_claim_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_close_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_extend_bounty_expiry_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V1 - remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* tips_report_awesome_V1 - reason */;
            return _toStringBytes(
                &m->basic.tips_report_awesome_V1.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_report_awesome_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.tips_report_awesome_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* tips_retract_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_retract_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* tips_tip_new_V1 - reason */;
            return _toStringBytes(
                &m->basic.tips_tip_new_V1.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_new_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.tips_tip_new_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tips_tip_new_V1 - tip_value */;
            return _toStringCompactu128(
                &m->basic.tips_tip_new_V1.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* tips_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_V1 - tip_value */;
            return _toStringCompactu128(
                &m->basic.tips_tip_V1.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* tips_close_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_close_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0: /* tips_slash_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_slash_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* chainbridge_set_threshold_V1 - threshold */;
            return _toStringu32(
                &m->basic.chainbridge_set_threshold_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* chainbridge_remove_resource_V1 - id */;
            return _toStringH256(
                &m->basic.chainbridge_remove_resource_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* chainbridge_add_relayer_V1 - v */;
            return _toStringAccountId_V1(
                &m->basic.chainbridge_add_relayer_V1.v,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0: /* chainbridge_remove_relayer_V1 - v */;
            return _toStringAccountId_V1(
                &m->basic.chainbridge_remove_relayer_V1.v,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* swap_transfer_V1 - to */;
            return _toStringAccountId_V1(
                &m->basic.swap_transfer_V1.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* swap_transfer_V1 - amount */;
            return _toStringBalance(
                &m->basic.swap_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* swap_set_swap_fee_V1 - fee */;
            return _toStringCompactu128(
                &m->basic.swap_set_swap_fee_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* swap_set_fee_destination_V1 - dest */;
            return _toStringAccountId_V1(
                &m->basic.swap_set_fee_destination_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* xxcmix_set_scheduling_account_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.xxcmix_set_scheduling_account_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* xxcmix_set_cmix_address_space_V1 - size */;
            return _toStringu8(
                &m->basic.xxcmix_set_cmix_address_space_V1.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0: /* xxcmix_set_admin_permission_V1 - permission */;
            return _toStringBlockNumber(
                &m->basic.xxcmix_set_admin_permission_V1.permission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* xxeconomics_set_liquidity_rewards_stake_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.xxeconomics_set_liquidity_rewards_stake_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* xxeconomics_set_liquidity_rewards_balance_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.xxeconomics_set_liquidity_rewards_balance_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* xxcustody_payout_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_payout_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* xxcustody_custody_bond_V1 - custody */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_custody_bond_V1.custody,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xxcustody_custody_bond_V1 - controller */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_custody_bond_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xxcustody_custody_bond_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.xxcustody_custody_bond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0: /* xxcustody_custody_bond_extra_V1 - custody */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_custody_bond_extra_V1.custody,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xxcustody_custody_bond_extra_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.xxcustody_custody_bond_extra_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0: /* xxcustody_custody_set_controller_V1 - custody */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_custody_set_controller_V1.custody,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xxcustody_custody_set_controller_V1 - controller */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_custody_set_controller_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8196: /* module 32 call 4 */
        switch (itemIdx) {
        case 0: /* xxcustody_custody_set_proxy_V1 - custody */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_custody_set_proxy_V1.custody,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xxcustody_custody_set_proxy_V1 - proxy */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_custody_set_proxy_V1.proxy,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8197: /* module 32 call 5 */
        switch (itemIdx) {
        case 0: /* xxcustody_team_custody_set_proxy_V1 - proxy */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_team_custody_set_proxy_V1.proxy,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8198: /* module 32 call 6 */
        switch (itemIdx) {
        case 0: /* xxcustody_add_custodian_V1 - custodian */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_add_custodian_V1.custodian,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8199: /* module 32 call 7 */
        switch (itemIdx) {
        case 0: /* xxcustody_remove_custodian_V1 - custodian */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_remove_custodian_V1.custodian,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8200: /* module 32 call 8 */
        switch (itemIdx) {
        case 0: /* xxcustody_replace_team_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_replace_team_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xxcustody_replace_team_member_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.xxcustody_replace_team_member_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8449: /* module 33 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0: /* xxpublic_set_testnet_manager_account_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.xxpublic_set_testnet_manager_account_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_as_multi_threshold_1_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V1 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->nested.multisig_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V1 - call */;
            return _toStringOpaqueCall_V1(
                &m->nested.multisig_as_multi_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V1 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V1.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->nested.multisig_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_approve_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->nested.multisig_approve_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V1 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->nested.multisig_approve_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_cancel_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V1 - timepoint */;
            return _toStringTimepoint_V1(
                &m->nested.multisig_cancel_as_multi_V1.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V1 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0: /* recovery_set_recovered_V1 - lost */;
            return _toStringAccountId_V1(
                &m->basic.recovery_set_recovered_V1.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_set_recovered_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_set_recovered_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_initiate_recovery_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0: /* recovery_vouch_recovery_V1 - lost */;
            return _toStringAccountId_V1(
                &m->basic.recovery_vouch_recovery_V1.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_vouch_recovery_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_vouch_recovery_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_claim_recovery_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9222: /* module 36 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_close_recovery_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9223: /* module 36 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 9224: /* module 36 call 8 */
        switch (itemIdx) {
        case 0: /* recovery_cancel_recovered_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_cancel_recovered_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0: /* assets_force_create_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_create_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_create_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_create_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_create_V1 - is_sufficient */;
            return _toStringbool(
                &m->basic.assets_force_create_V1.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_create_V1 - min_balance */;
            return _toStringCompactu64(
                &m->basic.assets_force_create_V1.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0: /* assets_mint_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_mint_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_mint_V1 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_mint_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_mint_V1 - amount */;
            return _toStringCompactu64(
                &m->basic.assets_mint_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0: /* assets_burn_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_burn_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_burn_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_burn_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_burn_V1 - amount */;
            return _toStringCompactu64(
                &m->basic.assets_burn_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0: /* assets_transfer_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_V1 - amount */;
            return _toStringCompactu64(
                &m->basic.assets_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0: /* assets_transfer_keep_alive_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_keep_alive_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_keep_alive_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_transfer_keep_alive_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_keep_alive_V1 - amount */;
            return _toStringCompactu64(
                &m->basic.assets_transfer_keep_alive_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0: /* assets_force_transfer_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_transfer_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_transfer_V1 - source */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_transfer_V1 - amount */;
            return _toStringCompactu64(
                &m->basic.assets_force_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0: /* assets_freeze_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_freeze_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_freeze_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_freeze_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9481: /* module 37 call 9 */
        switch (itemIdx) {
        case 0: /* assets_thaw_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_thaw_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_thaw_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_thaw_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9482: /* module 37 call 10 */
        switch (itemIdx) {
        case 0: /* assets_freeze_asset_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_freeze_asset_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9483: /* module 37 call 11 */
        switch (itemIdx) {
        case 0: /* assets_thaw_asset_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_thaw_asset_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9484: /* module 37 call 12 */
        switch (itemIdx) {
        case 0: /* assets_transfer_ownership_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_ownership_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_ownership_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_transfer_ownership_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9485: /* module 37 call 13 */
        switch (itemIdx) {
        case 0: /* assets_set_team_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_set_team_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_team_V1 - issuer */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_set_team_V1.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_team_V1 - admin */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_set_team_V1.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_team_V1 - freezer */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_set_team_V1.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9486: /* module 37 call 14 */
        switch (itemIdx) {
        case 0: /* assets_set_metadata_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_set_metadata_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_metadata_V1 - name */;
            return _toStringVecu8(
                &m->basic.assets_set_metadata_V1.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_metadata_V1 - symbol */;
            return _toStringVecu8(
                &m->basic.assets_set_metadata_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_metadata_V1 - decimals */;
            return _toStringu8(
                &m->basic.assets_set_metadata_V1.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9487: /* module 37 call 15 */
        switch (itemIdx) {
        case 0: /* assets_clear_metadata_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_clear_metadata_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9488: /* module 37 call 16 */
        switch (itemIdx) {
        case 0: /* assets_force_set_metadata_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_set_metadata_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_set_metadata_V1 - name */;
            return _toStringVecu8(
                &m->basic.assets_force_set_metadata_V1.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_set_metadata_V1 - symbol */;
            return _toStringVecu8(
                &m->basic.assets_force_set_metadata_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_set_metadata_V1 - decimals */;
            return _toStringu8(
                &m->basic.assets_force_set_metadata_V1.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_set_metadata_V1 - is_frozen */;
            return _toStringbool(
                &m->basic.assets_force_set_metadata_V1.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9489: /* module 37 call 17 */
        switch (itemIdx) {
        case 0: /* assets_force_clear_metadata_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_clear_metadata_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9490: /* module 37 call 18 */
        switch (itemIdx) {
        case 0: /* assets_force_asset_status_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_asset_status_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_asset_status_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_asset_status_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_asset_status_V1 - issuer */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_asset_status_V1.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_asset_status_V1 - admin */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_asset_status_V1.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_asset_status_V1 - freezer */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_asset_status_V1.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* assets_force_asset_status_V1 - min_balance */;
            return _toStringCompactu64(
                &m->basic.assets_force_asset_status_V1.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* assets_force_asset_status_V1 - is_sufficient */;
            return _toStringbool(
                &m->basic.assets_force_asset_status_V1.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* assets_force_asset_status_V1 - is_frozen */;
            return _toStringbool(
                &m->basic.assets_force_asset_status_V1.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9491: /* module 37 call 19 */
        switch (itemIdx) {
        case 0: /* assets_approve_transfer_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_approve_transfer_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_approve_transfer_V1 - delegate */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_approve_transfer_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_approve_transfer_V1 - amount */;
            return _toStringCompactu64(
                &m->basic.assets_approve_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9492: /* module 37 call 20 */
        switch (itemIdx) {
        case 0: /* assets_cancel_approval_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_cancel_approval_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_cancel_approval_V1 - delegate */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_cancel_approval_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9493: /* module 37 call 21 */
        switch (itemIdx) {
        case 0: /* assets_force_cancel_approval_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_force_cancel_approval_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_cancel_approval_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_cancel_approval_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_cancel_approval_V1 - delegate */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_force_cancel_approval_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9494: /* module 37 call 22 */
        switch (itemIdx) {
        case 0: /* assets_transfer_approved_V1 - id */;
            return _toStringCompactu32(
                &m->basic.assets_transfer_approved_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_approved_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_transfer_approved_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_approved_V1 - destination */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.assets_transfer_approved_V1.destination,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_transfer_approved_V1 - amount */;
            return _toStringCompactu64(
                &m->basic.assets_transfer_approved_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* uniques_create_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_create_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_create_V1 - admin */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_create_V1.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* uniques_force_create_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_force_create_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_force_create_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_force_create_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_force_create_V1 - free_holding */;
            return _toStringbool(
                &m->basic.uniques_force_create_V1.free_holding,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* uniques_mint_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_mint_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_mint_V1 - instance */;
            return _toStringCompactu32(
                &m->basic.uniques_mint_V1.instance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_mint_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_mint_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0: /* uniques_transfer_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_transfer_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_transfer_V1 - instance */;
            return _toStringCompactu32(
                &m->basic.uniques_transfer_V1.instance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9735: /* module 38 call 7 */
        switch (itemIdx) {
        case 0: /* uniques_freeze_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_freeze_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_freeze_V1 - instance */;
            return _toStringCompactu32(
                &m->basic.uniques_freeze_V1.instance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9736: /* module 38 call 8 */
        switch (itemIdx) {
        case 0: /* uniques_thaw_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_thaw_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_thaw_V1 - instance */;
            return _toStringCompactu32(
                &m->basic.uniques_thaw_V1.instance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9737: /* module 38 call 9 */
        switch (itemIdx) {
        case 0: /* uniques_freeze_class_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_freeze_class_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9738: /* module 38 call 10 */
        switch (itemIdx) {
        case 0: /* uniques_thaw_class_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_thaw_class_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9739: /* module 38 call 11 */
        switch (itemIdx) {
        case 0: /* uniques_transfer_ownership_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_transfer_ownership_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_transfer_ownership_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_transfer_ownership_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9740: /* module 38 call 12 */
        switch (itemIdx) {
        case 0: /* uniques_set_team_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_set_team_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_team_V1 - issuer */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_set_team_V1.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_team_V1 - admin */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_set_team_V1.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_team_V1 - freezer */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_set_team_V1.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9741: /* module 38 call 13 */
        switch (itemIdx) {
        case 0: /* uniques_approve_transfer_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_approve_transfer_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_approve_transfer_V1 - instance */;
            return _toStringCompactu32(
                &m->basic.uniques_approve_transfer_V1.instance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_approve_transfer_V1 - delegate */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_approve_transfer_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9743: /* module 38 call 15 */
        switch (itemIdx) {
        case 0: /* uniques_force_asset_status_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_force_asset_status_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_force_asset_status_V1 - owner */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_force_asset_status_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_force_asset_status_V1 - issuer */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_force_asset_status_V1.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_force_asset_status_V1 - admin */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_force_asset_status_V1.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* uniques_force_asset_status_V1 - freezer */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.uniques_force_asset_status_V1.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* uniques_force_asset_status_V1 - free_holding */;
            return _toStringbool(
                &m->basic.uniques_force_asset_status_V1.free_holding,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* uniques_force_asset_status_V1 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_force_asset_status_V1.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9747: /* module 38 call 19 */
        switch (itemIdx) {
        case 0: /* uniques_clear_metadata_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_clear_metadata_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_clear_metadata_V1 - instance */;
            return _toStringCompactu32(
                &m->basic.uniques_clear_metadata_V1.instance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9749: /* module 38 call 21 */
        switch (itemIdx) {
        case 0: /* uniques_clear_class_metadata_V1 - class_ */;
            return _toStringCompactu32(
                &m->basic.uniques_clear_class_metadata_V1.class_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1539: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1550: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1556: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: // Timestamp:Set
    case 1028: // Balances:Transfer all
    case 1029: // Balances:Force unreserve
    case 1536: // Staking:Bond
    case 1537: // Staking:Bond extra
    case 1538: // Staking:Unbond
    case 1539: // Staking:Withdraw Unbonded
    case 1540: // Staking:Validate
    case 1541: // Staking:Nominate
    case 1542: // Staking:Chill
    case 1543: // Staking:Set controller
    case 1544: // Staking:Set validator count
    case 1545: // Staking:Increase validator count
    case 1547: // Staking:Force no eras
    case 1548: // Staking:Force new era
    case 1549: // Staking:Set invulnerables
    case 1550: // Staking:Force unstake
    case 1551: // Staking:Force new era always
    case 1552: // Staking:Cancel deferred slash
    case 1553: // Staking:Payout stakers
    case 1554: // Staking:Rebond
    case 1555: // Staking:Set history depth
    case 1556: // Staking:Reap stash
    case 1557: // Staking:Kick
    case 1559: // Staking:Chill other
    case 1560: // Staking:Set cmix id
    case 1561: // Staking:Transfer cmix id
    case 2304: // Session:Set keys
    case 2305: // Session:Purge keys
    case 2562: // Grandpa:Note stalled
    case 3584: // Council:Set members
    case 3587: // Council:Vote
    case 3588: // Council:Close
    case 3589: // Council:Disapprove proposal
    case 3840: // TechnicalCommittee:Set members
    case 3843: // TechnicalCommittee:Vote
    case 3844: // TechnicalCommittee:Close
    case 3845: // TechnicalCommittee:Disapprove proposal
    case 4096: // Elections:Vote
    case 4097: // Elections:Remove voter
    case 4098: // Elections:Submit candidacy
    case 4100: // Elections:Remove member
    case 4101: // Elections:Clean defunct voters
    case 4352: // TechnicalMembership:Add member
    case 4353: // TechnicalMembership:Remove member
    case 4354: // TechnicalMembership:Swap member
    case 4355: // TechnicalMembership:Reset members
    case 4356: // TechnicalMembership:Change key
    case 4357: // TechnicalMembership:Set prime
    case 4358: // TechnicalMembership:Clear prime
    case 4608: // Treasury:Propose spend
    case 4609: // Treasury:Reject proposal
    case 4610: // Treasury:Approve proposal
    case 4864: // Claims:Claim
    case 4866: // Claims:Claim attest
    case 4867: // Claims:Attest
    case 4868: // Claims:Move claim
    case 5120: // Vesting:Vest
    case 5121: // Vesting:Vest other
    case 5124: // Vesting:Merge schedules
    case 5376: // Utility:Batch
    case 5378: // Utility:Batch all
    case 5632: // Identity:Add registrar
    case 5635: // Identity:Clear identity
    case 5636: // Identity:Request judgement
    case 5637: // Identity:Cancel request
    case 5638: // Identity:Set fee
    case 5639: // Identity:Set account id
    case 5642: // Identity:Kill identity
    case 5645: // Identity:Remove sub
    case 5646: // Identity:Quit sub
    case 5889: // Proxy:Add proxy
    case 5890: // Proxy:Remove proxy
    case 5891: // Proxy:Remove proxies
    case 5892: // Proxy:Anonymous
    case 5893: // Proxy:Kill anonymous
    case 5894: // Proxy:Announce
    case 5895: // Proxy:Remove announcement
    case 5896: // Proxy:Reject announcement
    case 5897: // Proxy:Proxy announced
    case 6656: // Bounties:Propose bounty
    case 6657: // Bounties:Approve bounty
    case 6658: // Bounties:Propose curator
    case 6659: // Bounties:Unassign curator
    case 6660: // Bounties:Accept curator
    case 6661: // Bounties:Award bounty
    case 6662: // Bounties:Claim bounty
    case 6663: // Bounties:Close bounty
    case 6664: // Bounties:Extend bounty expiry
    case 6912: // Tips:Report awesome
    case 6913: // Tips:Retract tip
    case 6914: // Tips:Tip new
    case 6915: // Tips:Tip
    case 6916: // Tips:Close tip
    case 6917: // Tips:Slash tip
    case 7168: // ChainBridge:Set threshold
    case 7170: // ChainBridge:Remove resource
    case 7172: // ChainBridge:Add relayer
    case 7173: // ChainBridge:Remove relayer
    case 7425: // Swap:Transfer
    case 7426: // Swap:Set swap fee
    case 7427: // Swap:Set fee destination
    case 7681: // XXCmix:Set scheduling account
    case 7685: // XXCmix:Set cmix address space
    case 7686: // XXCmix:Set admin permission
    case 7938: // XXEconomics:Set liquidity rewards stake
    case 7939: // XXEconomics:Set liquidity rewards balance
    case 8192: // XXCustody:Payout
    case 8193: // XXCustody:Custody bond
    case 8194: // XXCustody:Custody bond extra
    case 8195: // XXCustody:Custody set controller
    case 8196: // XXCustody:Custody set proxy
    case 8197: // XXCustody:Team custody set proxy
    case 8198: // XXCustody:Add custodian
    case 8199: // XXCustody:Remove custodian
    case 8200: // XXCustody:Replace team member
    case 8449: // XXBetanetRewards:Approve
    case 8704: // XXPublic:Set testnet manager account
    case 9217: // Recovery:Set recovered
    case 9219: // Recovery:Initiate recovery
    case 9220: // Recovery:Vouch recovery
    case 9221: // Recovery:Claim recovery
    case 9222: // Recovery:Close recovery
    case 9223: // Recovery:Remove recovery
    case 9224: // Recovery:Cancel recovered
    case 9473: // Assets:Force create
    case 9475: // Assets:Mint
    case 9476: // Assets:Burn
    case 9477: // Assets:Transfer
    case 9478: // Assets:Transfer keep alive
    case 9479: // Assets:Force transfer
    case 9480: // Assets:Freeze
    case 9481: // Assets:Thaw
    case 9482: // Assets:Freeze asset
    case 9483: // Assets:Thaw asset
    case 9484: // Assets:Transfer ownership
    case 9485: // Assets:Set team
    case 9486: // Assets:Set metadata
    case 9487: // Assets:Clear metadata
    case 9488: // Assets:Force set metadata
    case 9489: // Assets:Force clear metadata
    case 9490: // Assets:Force asset status
    case 9491: // Assets:Approve transfer
    case 9492: // Assets:Cancel approval
    case 9493: // Assets:Force cancel approval
    case 9494: // Assets:Transfer approved
    case 9728: // Uniques:Create
    case 9729: // Uniques:Force create
    case 9731: // Uniques:Mint
    case 9733: // Uniques:Transfer
    case 9735: // Uniques:Freeze
    case 9736: // Uniques:Thaw
    case 9737: // Uniques:Freeze class
    case 9738: // Uniques:Thaw class
    case 9739: // Uniques:Transfer ownership
    case 9740: // Uniques:Set team
    case 9741: // Uniques:Approve transfer
    case 9743: // Uniques:Force asset status
    case 9747: // Uniques:Clear metadata
    case 9749: // Uniques:Clear class metadata
        return false;
    default:
        return true;
    }
}
