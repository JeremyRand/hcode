/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: import/chips/p9/procedures/ppe_closed/cme/pstate_cme/p9_cme_pstate.h $ */
/*                                                                        */
/* OpenPOWER HCODE Project                                                */
/*                                                                        */
/* COPYRIGHT 2015,2017                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//-----------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2014
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//-----------------------------------------------------------------------------

/// \file p9_cme_pstate.h
/// \brief Shared and global definitions for pstate H codes.
/// \owner  Rahul Batra Email: rbatra@us.ibm.com
///

#include "pk.h"
#include "p9_pstate_common.h"
#include "gpehw_common.h"

void p9_cme_pstate_pmcr_thread(void*);
void p9_cme_pstate_db_thread(void*);
void p9_cme_pstate_pmcr_handler(void*, PkIrqId);
void p9_cme_pstate_db_handler(void*, PkIrqId);
void p9_cme_pstate_intercme_in0_handler(void*, PkIrqId);

typedef struct
{
    PkSemaphore sem[2];
} CmePstateRecord;

typedef struct
{
    uint64_t seqNum;
    uint32_t cmeFlags;
    uint8_t coreGood[CORES_PER_EX];
} cme_pstate_pmcr_data_t;

typedef struct
{
    uint8_t qmFlag;
    uint8_t siblingCMEFlag;
    uint32_t cmeMaskGoodCore;
    uint8_t globalPS; //\todo use PState as type
    uint8_t localPS; //\todo use PState as type
    uint8_t resClkTblIdx;
    uint8_t qaccr21_23InitVal;
    uint8_t quadNum;
    uint8_t dpll_pstate0_value;
} cme_pstate_db_data_t;
