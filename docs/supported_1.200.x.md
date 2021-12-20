# Elixxir  1.200.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> |
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |

## Babe

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHeader` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Plan config change |    |   |   | `NextConfigDescriptor` config <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## Staking

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/>`CompactBalance` amount <br/>`OptionHash` cmix_id <br/> |
|Bond extra | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Withdraw Unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> |
|Validate | :heavy_check_mark:  | :heavy_check_mark: |   | `ValidatorPrefs` prefs <br/> |
|Nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` targets <br/> |
|Chill | :heavy_check_mark:  | :heavy_check_mark: |   |  |
|Set controller | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/> |
|Set validator count |    | :heavy_check_mark: |   | `Compactu32` new_ <br/> |
|Increase validator count |    | :heavy_check_mark: |   | `Compactu32` additional <br/> |
|Scale validator count |    |   |   | `Percent` factor <br/> |
|Force no eras |    | :heavy_check_mark: |   |  |
|Force new era |    | :heavy_check_mark: |   |  |
|Set invulnerables |    | :heavy_check_mark: |   | `VecAccountId` invulnerables <br/> |
|Force unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Force new era always |    | :heavy_check_mark: |   |  |
|Cancel deferred slash |    | :heavy_check_mark: |   | `EraIndex` era <br/>`Vecu32` slash_indices <br/> |
|Payout stakers | :heavy_check_mark:  | :heavy_check_mark: |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> |
|Rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> |
|Set history depth |    | :heavy_check_mark: |   | `Compactu32` new_history_depth <br/>`Compactu32` era_items_deleted <br/> |
|Reap stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Kick |    | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` who <br/> |
|Set staking limits |    |   |   | `Balance` min_nominator_bond <br/>`Balance` min_validator_bond <br/>`Optionu32` max_nominator_count <br/>`Optionu32` max_validator_count <br/>`OptionPercent` threshold <br/>`Perbill` min_commission <br/> |
|Chill other |    | :heavy_check_mark: |   | `AccountId` controller <br/> |

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Submit unsigned |    |   |   | `BoxRawSolutionSolutionOfT` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> |
|Set minimum untrusted score |    |   |   | `OptionElectionScore` maybe_next_score <br/> |
|Set emergency election result |    |   |   | `SupportsAccountId` supports <br/> |
|Submit |    |   |   | `BoxRawSolutionSolutionOfT` raw_solution <br/>`u32` num_signed_submissions <br/> |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## Grandpa

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> |
|Note stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> |

## ImOnline

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Heartbeat |    |   |   | `HeartbeatBlockNumber` heartbeat <br/>`AuthorityIdasRuntimeAppPublicSignature` signature <br/> |

## Democracy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose |    |   |   | `Hash` proposal_hash <br/>`Compactu128` amount <br/> |
|Second |    |   |   | `Compactu32` proposal <br/>`Compactu32` seconds_upper_bound <br/> |
|Vote |    |   |   | `Compactu32` ref_index <br/>`AccountVoteBalanceOf` vote <br/> |
|Emergency cancel |    |   |   | `ReferendumIndex` ref_index <br/> |
|External propose |    |   |   | `Hash` proposal_hash <br/> |
|External propose majority |    |   |   | `Hash` proposal_hash <br/> |
|External propose default |    |   |   | `Hash` proposal_hash <br/> |
|Fast track |    |   |   | `Hash` proposal_hash <br/>`BlockNumber` voting_period <br/>`BlockNumber` delay <br/> |
|Veto external |    |   |   | `Hash` proposal_hash <br/> |
|Cancel referendum |    |   |   | `Compactu32` ref_index <br/> |
|Cancel queued |    |   |   | `ReferendumIndex` which <br/> |
|Delegate |    |   |   | `AccountId` to <br/>`Conviction` conviction <br/>`Balance` balance <br/> |
|Undelegate |    |   |   |  |
|Clear public proposals |    |   |   |  |
|Note preimage |    |   |   | `Bytes` encoded_proposal <br/> |
|Note preimage operational |    |   |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage |    |   |   | `Bytes` encoded_proposal <br/> |
|Note imminent preimage operational |    |   |   | `Bytes` encoded_proposal <br/> |
|Reap preimage |    |   |   | `Hash` proposal_hash <br/>`Compactu32` proposal_len_upper_bound <br/> |
|Unlock |    |   |   | `AccountId` target <br/> |
|Remove vote |    |   |   | `ReferendumIndex` index <br/> |
|Remove other vote |    |   |   | `AccountId` target <br/>`ReferendumIndex` index <br/> |
|Enact proposal |    |   |   | `Hash` proposal_hash <br/>`ReferendumIndex` index <br/> |
|Blacklist |    |   |   | `Hash` proposal_hash <br/>`OptionReferendumIndex` maybe_ref_index <br/> |
|Cancel proposal |    |   |   | `Compactu32` prop_index <br/> |

## Council

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    | :heavy_check_mark: |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> |
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> |
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> |
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> |
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> |
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> |

## Elections

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vote |    | :heavy_check_mark: |   | `VecAccountId` votes <br/>`Compactu128` amount <br/> |
|Remove voter |    | :heavy_check_mark: |   |  |
|Submit candidacy |    | :heavy_check_mark: |   | `Compactu32` candidate_count <br/> |
|Renounce candidacy |    |   |   | `Renouncing` renouncing <br/> |
|Remove member |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`bool` has_replacement <br/> |
|Clean defunct voters |    | :heavy_check_mark: |   | `u32` num_voters <br/>`u32` num_defunct <br/> |

## TechnicalMembership

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Remove member |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Swap member |    | :heavy_check_mark: |   | `AccountId` remove <br/>`AccountId` add <br/> |
|Reset members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |
|Change key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> |
|Set prime |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Clear prime |    | :heavy_check_mark: |   |  |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Reject proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |
|Approve proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |

## Claims

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/> |
|Mint claim |    |   |   | `EthereumAddress` who <br/>`Balance` amount <br/>`OptionVecTupleBalanceOfTBalanceOfTBlockNumber` vesting_schedules <br/>`OptionStatementKind` statement <br/> |
|Claim attest |    | :heavy_check_mark: |   | `AccountId` dest <br/>`EcdsaSignature` ethereum_signature <br/>`Bytes` statement <br/> |
|Attest |    | :heavy_check_mark: |   | `Bytes` statement <br/> |
|Move claim |    | :heavy_check_mark: |   | `EthereumAddress` old <br/>`EthereumAddress` new_ <br/>`OptionAccountId` maybe_preclaim <br/> |

## Vesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vest |    | :heavy_check_mark: |   |  |
|Vest other |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> |
|Vested transfer |    |   |   | `LookupasStaticLookupSource` target <br/>`VestingInfoBalanceOfTBlockNumber` schedule <br/> |
|Force vested transfer |    |   |   | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` target <br/>`VestingInfoBalanceOfTBlockNumber` schedule <br/> |
|Merge schedules |    | :heavy_check_mark: |   | `u32` schedule1_index <br/>`u32` schedule2_index <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch |    | :heavy_check_mark: |   | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all |    | :heavy_check_mark: |   | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> |
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> |
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> |
|Clear identity |    | :heavy_check_mark: |   |  |
|Request judgement |    | :heavy_check_mark: |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> |
|Cancel request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> |
|Set fee |    | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` fee <br/> |
|Set account id |    | :heavy_check_mark: |   | `Compactu32` index <br/>`AccountId` new_ <br/> |
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> |
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`LookupasStaticLookupSource` target <br/>`JudgementBalanceOfT` judgement <br/> |
|Kill identity |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> |
|Add sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Rename sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Remove sub |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` sub <br/> |
|Quit sub |    | :heavy_check_mark: |   |  |

## Proxy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |
|Add proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxies |    | :heavy_check_mark: |   |  |
|Anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> |
|Kill anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> |
|Announce |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Remove announcement |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Reject announcement |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> |
|Proxy announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |

## Bounties

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose bounty |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`Bytes` description <br/> |
|Approve bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Propose curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` curator <br/>`CompactBalance` fee <br/> |
|Unassign curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Accept curator |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Award bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Claim bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Close bounty |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/> |
|Extend bounty expiry |    | :heavy_check_mark: |   | `Compactu32` bounty_id <br/>`Bytes` remark <br/> |

## Tips

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report awesome |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/> |
|Retract tip |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Tip new |    | :heavy_check_mark: |   | `Bytes` reason <br/>`AccountId` who <br/>`Compactu128` tip_value <br/> |
|Tip |    | :heavy_check_mark: |   | `Hash` hash <br/>`Compactu128` tip_value <br/> |
|Close tip |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Slash tip |    | :heavy_check_mark: |   | `Hash` hash <br/> |

## ChainBridge

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set threshold |    | :heavy_check_mark: |   | `u32` threshold <br/> |
|Set resource |    |   |   | `H256` id <br/>`Vecu8` method <br/> |
|Remove resource |    | :heavy_check_mark: |   | `H256` id <br/> |
|Whitelist chain |    |   |   | `ChainId` id <br/> |
|Add relayer |    | :heavy_check_mark: |   | `AccountId` v <br/> |
|Remove relayer |    | :heavy_check_mark: |   | `AccountId` v <br/> |
|Acknowledge proposal |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`H256` r_id <br/>`BoxTasConfigProposal` call <br/> |
|Reject proposal |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`H256` r_id <br/>`BoxTasConfigProposal` call <br/> |
|Eval vote state |    |   |   | `DepositNonce` nonce <br/>`ChainId` src_id <br/>`BoxTasConfigProposal` prop <br/> |

## Swap

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer native |    |   |   | `Balance` amount <br/>`Vecu8` recipient <br/>`chainbridgeChainId` dest_id <br/> |
|Transfer |    | :heavy_check_mark: |   | `AccountId` to <br/>`Balance` amount <br/> |
|Set swap fee |    | :heavy_check_mark: |   | `Compactu128` fee <br/> |
|Set fee destination |    | :heavy_check_mark: |   | `AccountId` dest <br/> |

## XXCmix

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set cmix hashes |    |   |   | `cmixSoftwareHashesHash` hashes <br/> |
|Set scheduling account |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Set next cmix variables |    |   |   | `cmixVariables` variables <br/> |
|Submit cmix points |    |   |   | `VecTupleAccountIdu32` data <br/> |
|Submit cmix deductions |    |   |   | `VecTupleAccountIdu32` data <br/> |
|Set cmix address space |    | :heavy_check_mark: |   | `u8` size <br/> |
|Set admin permission |    | :heavy_check_mark: |   | `BlockNumber` permission <br/> |

## XXEconomics

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set inflation params |    |   |   | `inflationInflationFixedParams` params <br/> |
|Set interest points |    |   |   | `VecinflationIdealInterestPointBlockNumber` points <br/> |
|Set liquidity rewards stake |    | :heavy_check_mark: |   | `Compactu128` amount <br/> |
|Set liquidity rewards balance |    | :heavy_check_mark: |   | `Compactu128` amount <br/> |

## XXCustody

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Payout |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Custody bond |    | :heavy_check_mark: |   | `AccountId` custody <br/>`AccountId` controller <br/>`Compactu128` amount <br/> |
|Custody bond extra |    | :heavy_check_mark: |   | `AccountId` custody <br/>`Compactu128` amount <br/> |
|Custody set controller |    | :heavy_check_mark: |   | `AccountId` custody <br/>`AccountId` controller <br/> |
|Custody set proxy |    | :heavy_check_mark: |   | `AccountId` custody <br/>`AccountId` proxy <br/> |
|Team custody set proxy |    | :heavy_check_mark: |   | `AccountId` proxy <br/> |
|Add custodian |    | :heavy_check_mark: |   | `AccountId` custodian <br/> |
|Remove custodian |    | :heavy_check_mark: |   | `AccountId` custodian <br/> |
|Replace team member |    | :heavy_check_mark: |   | `AccountId` who <br/>`AccountId` new_ <br/> |

## XXBetanetRewards

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Select option |    |   |   | `RewardOption` option <br/> |
|Approve |    | :heavy_check_mark: |   |  |

## XXPublic

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set testnet manager account |    | :heavy_check_mark: |   | `AccountId` who <br/> |
|Set sale manager account |    |   |   | `AccountId` who <br/> |
|Testnet distribute |    |   |   | `VecTransferDataAccountIdBalanceOfTBlockNumber` data <br/> |
|Sale distribute |    |   |   | `VecTransferDataAccountIdBalanceOfTBlockNumber` data <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Recovery

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As recovered |    |   |   | `AccountId` account <br/>`Call` call <br/> |
|Set recovered |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> |
|Create recovery |    |   |   | `VecAccountId` friends <br/>`u16` threshold <br/>`BlockNumber` delay_period <br/> |
|Initiate recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> |
|Vouch recovery |    | :heavy_check_mark: |   | `AccountId` lost <br/>`AccountId` rescuer <br/> |
|Claim recovery |    | :heavy_check_mark: |   | `AccountId` account <br/> |
|Close recovery |    | :heavy_check_mark: |   | `AccountId` rescuer <br/> |
|Remove recovery |    | :heavy_check_mark: |   |  |
|Cancel recovered |    | :heavy_check_mark: |   | `AccountId` account <br/> |

## Assets

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    |   |   | `Compactu32` id <br/>`LookupasStaticLookupSource` admin <br/>`Balance` min_balance <br/> |
|Force create |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`bool` is_sufficient <br/>`Compactu64` min_balance <br/> |
|Destroy |    |   |   | `Compactu32` id <br/>`DestroyWitness` witness <br/> |
|Mint |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` beneficiary <br/>`Compactu64` amount <br/> |
|Burn |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/>`Compactu64` amount <br/> |
|Transfer |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` target <br/>`Compactu64` amount <br/> |
|Transfer keep alive |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` target <br/>`Compactu64` amount <br/> |
|Force transfer |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`Compactu64` amount <br/> |
|Freeze |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/> |
|Thaw |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/> |
|Freeze asset |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Thaw asset |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Transfer ownership |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/> |
|Set team |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/> |
|Set metadata |    | :heavy_check_mark: |   | `Compactu32` id <br/>`Vecu8` name <br/>`Vecu8` symbol <br/>`u8` decimals <br/> |
|Clear metadata |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Force set metadata |    | :heavy_check_mark: |   | `Compactu32` id <br/>`Vecu8` name <br/>`Vecu8` symbol <br/>`u8` decimals <br/>`bool` is_frozen <br/> |
|Force clear metadata |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Force asset status |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/>`Compactu64` min_balance <br/>`bool` is_sufficient <br/>`bool` is_frozen <br/> |
|Approve transfer |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` delegate <br/>`Compactu64` amount <br/> |
|Cancel approval |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` delegate <br/> |
|Force cancel approval |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` delegate <br/> |
|Transfer approved |    | :heavy_check_mark: |   | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` destination <br/>`Compactu64` amount <br/> |

## Uniques

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` admin <br/> |
|Force create |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` owner <br/>`bool` free_holding <br/> |
|Destroy |    |   |   | `Compactu32` class_ <br/>`DestroyWitness` witness <br/> |
|Mint |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`LookupasStaticLookupSource` owner <br/> |
|Burn |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`OptionLookupasStaticLookupSource` check_owner <br/> |
|Transfer |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`LookupasStaticLookupSource` dest <br/> |
|Redeposit |    |   |   | `Compactu32` class_ <br/>`VecInstanceId` instances <br/> |
|Freeze |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`Compactu32` instance <br/> |
|Thaw |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`Compactu32` instance <br/> |
|Freeze class |    | :heavy_check_mark: |   | `Compactu32` class_ <br/> |
|Thaw class |    | :heavy_check_mark: |   | `Compactu32` class_ <br/> |
|Transfer ownership |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` owner <br/> |
|Set team |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/> |
|Approve transfer |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`LookupasStaticLookupSource` delegate <br/> |
|Cancel approval |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`OptionLookupasStaticLookupSource` maybe_check_delegate <br/> |
|Force asset status |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/>`bool` free_holding <br/>`bool` is_frozen <br/> |
|Set attribute |    |   |   | `Compactu32` class_ <br/>`OptionInstanceId` maybe_instance <br/>`BoundedVecu8KeyLimit` key <br/>`BoundedVecu8ValueLimit` value <br/> |
|Clear attribute |    |   |   | `Compactu32` class_ <br/>`OptionInstanceId` maybe_instance <br/>`BoundedVecu8KeyLimit` key <br/> |
|Set metadata |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`BoundedVecu8StringLimit` data <br/>`bool` is_frozen <br/> |
|Clear metadata |    | :heavy_check_mark: |   | `Compactu32` class_ <br/>`Compactu32` instance <br/> |
|Set class metadata |    |   |   | `Compactu32` class_ <br/>`BoundedVecu8StringLimit` data <br/>`bool` is_frozen <br/> |
|Clear class metadata |    | :heavy_check_mark: |   | `Compactu32` class_ <br/> |

