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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V1.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V1(parser_context_t* c, pd_AccountId_V1_t* v);
parser_error_t _readAccountVoteSplit_V1(parser_context_t* c, pd_AccountVoteSplit_V1_t* v);
parser_error_t _readAccountVoteStandard_V1(parser_context_t* c, pd_AccountVoteStandard_V1_t* v);
parser_error_t _readAccountVote_V1(parser_context_t* c, pd_AccountVote_V1_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V1(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V1_t* v);
parser_error_t _readBoundedVecu8_V1(parser_context_t* c, pd_BoundedVecu8_V1_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V1(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V1_t* v);
parser_error_t _readBoxEquivocationProofHeader_V1(parser_context_t* c, pd_BoxEquivocationProofHeader_V1_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V1(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V1_t* v);
parser_error_t _readBoxPalletsOrigin_V1(parser_context_t* c, pd_BoxPalletsOrigin_V1_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V1(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V1_t* v);
parser_error_t _readBoxTasConfigProposal_V1(parser_context_t* c, pd_BoxTasConfigProposal_V1_t* v);
parser_error_t _readCallHashOf_V1(parser_context_t* c, pd_CallHashOf_V1_t* v);
parser_error_t _readChainId_V1(parser_context_t* c, pd_ChainId_V1_t* v);
parser_error_t _readCompactAccountIndex_V1(parser_context_t* c, pd_CompactAccountIndex_V1_t* v);
parser_error_t _readCompactPerBill_V1(parser_context_t* c, pd_CompactPerBill_V1_t* v);
parser_error_t _readConviction_V1(parser_context_t* c, pd_Conviction_V1_t* v);
parser_error_t _readDepositNonce_V1(parser_context_t* c, pd_DepositNonce_V1_t* v);
parser_error_t _readDestroyWitness_V1(parser_context_t* c, pd_DestroyWitness_V1_t* v);
parser_error_t _readEcdsaSignature_V1(parser_context_t* c, pd_EcdsaSignature_V1_t* v);
parser_error_t _readElectionScore_V1(parser_context_t* c, pd_ElectionScore_V1_t* v);
parser_error_t _readEraIndex_V1(parser_context_t* c, pd_EraIndex_V1_t* v);
parser_error_t _readEthereumAddress_V1(parser_context_t* c, pd_EthereumAddress_V1_t* v);
parser_error_t _readHeartbeatBlockNumber_V1(parser_context_t* c, pd_HeartbeatBlockNumber_V1_t* v);
parser_error_t _readIdentityFields_V1(parser_context_t* c, pd_IdentityFields_V1_t* v);
parser_error_t _readInstanceId_V1(parser_context_t* c, pd_InstanceId_V1_t* v);
parser_error_t _readJudgementBalanceOfT_V1(parser_context_t* c, pd_JudgementBalanceOfT_V1_t* v);
parser_error_t _readKeyOwnerProof_V1(parser_context_t* c, pd_KeyOwnerProof_V1_t* v);
parser_error_t _readKeyValue_V1(parser_context_t* c, pd_KeyValue_V1_t* v);
parser_error_t _readKey_V1(parser_context_t* c, pd_Key_V1_t* v);
parser_error_t _readKeys_V1(parser_context_t* c, pd_Keys_V1_t* v);
parser_error_t _readLookupasStaticLookupSource_V1(parser_context_t* c, pd_LookupasStaticLookupSource_V1_t* v);
parser_error_t _readMemberCount_V1(parser_context_t* c, pd_MemberCount_V1_t* v);
parser_error_t _readNextConfigDescriptor_V1(parser_context_t* c, pd_NextConfigDescriptor_V1_t* v);
parser_error_t _readOpaqueCall_V1(parser_context_t* c, pd_OpaqueCall_V1_t* v);
parser_error_t _readOptionAccountId_V1(parser_context_t* c, pd_OptionAccountId_V1_t* v);
parser_error_t _readOptionElectionScore_V1(parser_context_t* c, pd_OptionElectionScore_V1_t* v);
parser_error_t _readOptionInstanceId_V1(parser_context_t* c, pd_OptionInstanceId_V1_t* v);
parser_error_t _readOptionLookupasStaticLookupSource_V1(parser_context_t* c, pd_OptionLookupasStaticLookupSource_V1_t* v);
parser_error_t _readOptionPercent_V1(parser_context_t* c, pd_OptionPercent_V1_t* v);
parser_error_t _readOptionProxyType_V1(parser_context_t* c, pd_OptionProxyType_V1_t* v);
parser_error_t _readOptionReferendumIndex_V1(parser_context_t* c, pd_OptionReferendumIndex_V1_t* v);
parser_error_t _readOptionStatementKind_V1(parser_context_t* c, pd_OptionStatementKind_V1_t* v);
parser_error_t _readOptionTimepoint_V1(parser_context_t* c, pd_OptionTimepoint_V1_t* v);
parser_error_t _readOptionVecTupleBalanceOfTBalanceOfTBlockNumber_V1(parser_context_t* c, pd_OptionVecTupleBalanceOfTBalanceOfTBlockNumber_V1_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V1(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V1_t* v);
parser_error_t _readPerbill_V1(parser_context_t* c, pd_Perbill_V1_t* v);
parser_error_t _readPercent_V1(parser_context_t* c, pd_Percent_V1_t* v);
parser_error_t _readProxyType_V1(parser_context_t* c, pd_ProxyType_V1_t* v);
parser_error_t _readReferendumIndex_V1(parser_context_t* c, pd_ReferendumIndex_V1_t* v);
parser_error_t _readRegistrarIndex_V1(parser_context_t* c, pd_RegistrarIndex_V1_t* v);
parser_error_t _readRenouncing_V1(parser_context_t* c, pd_Renouncing_V1_t* v);
parser_error_t _readRewardOption_V1(parser_context_t* c, pd_RewardOption_V1_t* v);
parser_error_t _readSolutionOrSnapshotSize_V1(parser_context_t* c, pd_SolutionOrSnapshotSize_V1_t* v);
parser_error_t _readStatementKind_V1(parser_context_t* c, pd_StatementKind_V1_t* v);
parser_error_t _readSupportsAccountId_V1(parser_context_t* c, pd_SupportsAccountId_V1_t* v);
parser_error_t _readTimepoint_V1(parser_context_t* c, pd_Timepoint_V1_t* v);
parser_error_t _readTransferDataAccountIdBalanceOfTBlockNumber_V1(parser_context_t* c, pd_TransferDataAccountIdBalanceOfTBlockNumber_V1_t* v);
parser_error_t _readTupleAccountIdData_V1(parser_context_t* c, pd_TupleAccountIdData_V1_t* v);
parser_error_t _readTupleAccountIdu32_V1(parser_context_t* c, pd_TupleAccountIdu32_V1_t* v);
parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V1(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V1_t* v);
parser_error_t _readValidatorPrefs_V1(parser_context_t* c, pd_ValidatorPrefs_V1_t* v);
parser_error_t _readVecAccountId_V1(parser_context_t* c, pd_VecAccountId_V1_t* v);
parser_error_t _readVecInstanceId_V1(parser_context_t* c, pd_VecInstanceId_V1_t* v);
parser_error_t _readVecKeyValue_V1(parser_context_t* c, pd_VecKeyValue_V1_t* v);
parser_error_t _readVecKey_V1(parser_context_t* c, pd_VecKey_V1_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V1(parser_context_t* c, pd_VecLookupasStaticLookupSource_V1_t* v);
parser_error_t _readVecTransferDataAccountIdBalanceOfTBlockNumber_V1(parser_context_t* c, pd_VecTransferDataAccountIdBalanceOfTBlockNumber_V1_t* v);
parser_error_t _readVecTupleAccountIdData_V1(parser_context_t* c, pd_VecTupleAccountIdData_V1_t* v);
parser_error_t _readVecTupleAccountIdu32_V1(parser_context_t* c, pd_VecTupleAccountIdu32_V1_t* v);
parser_error_t _readVecTupleBalanceOfTBalanceOfTBlockNumber_V1(parser_context_t* c, pd_VecTupleBalanceOfTBalanceOfTBlockNumber_V1_t* v);
parser_error_t _readVecinflationIdealInterestPointBlockNumber_V1(parser_context_t* c, pd_VecinflationIdealInterestPointBlockNumber_V1_t* v);
parser_error_t _readVestingInfo_V1(parser_context_t* c, pd_VestingInfo_V1_t* v);
parser_error_t _readVote_V1(parser_context_t* c, pd_Vote_V1_t* v);
parser_error_t _readWeight_V1(parser_context_t* c, pd_Weight_V1_t* v);
parser_error_t _readchainbridgeChainId_V1(parser_context_t* c, pd_chainbridgeChainId_V1_t* v);
parser_error_t _readcmixSoftwareHashesHash_V1(parser_context_t* c, pd_cmixSoftwareHashesHash_V1_t* v);
parser_error_t _readcmixVariables_V1(parser_context_t* c, pd_cmixVariables_V1_t* v);
parser_error_t _readinflationIdealInterestPointBlockNumber_V1(parser_context_t* c, pd_inflationIdealInterestPointBlockNumber_V1_t* v);
parser_error_t _readinflationInflationFixedParams_V1(parser_context_t* c, pd_inflationInflationFixedParams_V1_t* v);
parser_error_t _readschedulePeriodBlockNumber_V1(parser_context_t* c, pd_schedulePeriodBlockNumber_V1_t* v);
parser_error_t _readschedulePriority_V1(parser_context_t* c, pd_schedulePriority_V1_t* v);

// toString functions
parser_error_t _toStringAccountId_V1(
    const pd_AccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V1(
    const pd_AccountVoteSplit_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V1(
    const pd_AccountVoteStandard_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V1(
    const pd_AccountVote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V1(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8_V1(
    const pd_BoundedVecu8_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V1(
    const pd_BoxEquivocationProofHashBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V1(
    const pd_BoxEquivocationProofHeader_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V1(
    const pd_BoxIdentityInfoMaxAdditionalFields_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V1(
    const pd_BoxPalletsOrigin_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V1(
    const pd_BoxRawSolutionSolutionOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxTasConfigProposal_V1(
    const pd_BoxTasConfigProposal_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V1(
    const pd_CallHashOf_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChainId_V1(
    const pd_ChainId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V1(
    const pd_CompactAccountIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V1(
    const pd_CompactPerBill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V1(
    const pd_Conviction_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDepositNonce_V1(
    const pd_DepositNonce_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V1(
    const pd_DestroyWitness_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V1(
    const pd_EcdsaSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V1(
    const pd_ElectionScore_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V1(
    const pd_EraIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V1(
    const pd_EthereumAddress_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V1(
    const pd_HeartbeatBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V1(
    const pd_IdentityFields_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInstanceId_V1(
    const pd_InstanceId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V1(
    const pd_JudgementBalanceOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V1(
    const pd_KeyOwnerProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V1(
    const pd_KeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V1(
    const pd_Key_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V1(
    const pd_Keys_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V1(
    const pd_LookupasStaticLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V1(
    const pd_MemberCount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V1(
    const pd_NextConfigDescriptor_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V1(
    const pd_OpaqueCall_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V1(
    const pd_OptionAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V1(
    const pd_OptionElectionScore_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionInstanceId_V1(
    const pd_OptionInstanceId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionLookupasStaticLookupSource_V1(
    const pd_OptionLookupasStaticLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPercent_V1(
    const pd_OptionPercent_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V1(
    const pd_OptionProxyType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V1(
    const pd_OptionReferendumIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V1(
    const pd_OptionStatementKind_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V1(
    const pd_OptionTimepoint_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTupleBalanceOfTBalanceOfTBlockNumber_V1(
    const pd_OptionVecTupleBalanceOfTBalanceOfTBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V1(
    const pd_OptionschedulePeriodBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V1(
    const pd_Perbill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V1(
    const pd_Percent_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V1(
    const pd_ProxyType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V1(
    const pd_ReferendumIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V1(
    const pd_RegistrarIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V1(
    const pd_Renouncing_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardOption_V1(
    const pd_RewardOption_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V1(
    const pd_SolutionOrSnapshotSize_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V1(
    const pd_StatementKind_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V1(
    const pd_SupportsAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V1(
    const pd_Timepoint_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTransferDataAccountIdBalanceOfTBlockNumber_V1(
    const pd_TransferDataAccountIdBalanceOfTBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V1(
    const pd_TupleAccountIdData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdu32_V1(
    const pd_TupleAccountIdu32_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V1(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V1(
    const pd_ValidatorPrefs_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V1(
    const pd_VecAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecInstanceId_V1(
    const pd_VecInstanceId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V1(
    const pd_VecKeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V1(
    const pd_VecKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V1(
    const pd_VecLookupasStaticLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTransferDataAccountIdBalanceOfTBlockNumber_V1(
    const pd_VecTransferDataAccountIdBalanceOfTBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V1(
    const pd_VecTupleAccountIdData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdu32_V1(
    const pd_VecTupleAccountIdu32_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleBalanceOfTBalanceOfTBlockNumber_V1(
    const pd_VecTupleBalanceOfTBalanceOfTBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecinflationIdealInterestPointBlockNumber_V1(
    const pd_VecinflationIdealInterestPointBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V1(
    const pd_VestingInfo_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V1(
    const pd_Vote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V1(
    const pd_Weight_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringchainbridgeChainId_V1(
    const pd_chainbridgeChainId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringcmixSoftwareHashesHash_V1(
    const pd_cmixSoftwareHashesHash_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringcmixVariables_V1(
    const pd_cmixVariables_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringinflationIdealInterestPointBlockNumber_V1(
    const pd_inflationIdealInterestPointBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringinflationInflationFixedParams_V1(
    const pd_inflationInflationFixedParams_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V1(
    const pd_schedulePeriodBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V1(
    const pd_schedulePriority_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
