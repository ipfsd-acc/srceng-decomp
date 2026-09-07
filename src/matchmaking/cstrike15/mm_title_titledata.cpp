// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/cstrike15/mm_title_titledata.cpp
// Functions: 4
// ============================================================

#include "matchmaking\cstrike15\mm_title_titledata.h"

//------------------------------------------------------------------------------
// Address: 0x100028C0
// Name: public: virtual struct TitleAchievementsDescription_t const __near * CMatchTitle::DescribeTitleAchievements(void)
// Source: json
//------------------------------------------------------------------------------
const TitleAchievementsDescription_t *__thiscall CMatchTitle::DescribeTitleAchievements(CMatchTitle *this)
{
  return tad;
}

//------------------------------------------------------------------------------
// Address: 0x100028D0
// Name: public: virtual struct TitleAvatarAwardsDescription_t const __near * CMatchTitle::DescribeTitleAvatarAwards(void)
// Source: json
//------------------------------------------------------------------------------
const TitleAvatarAwardsDescription_t *__thiscall CMatchTitle::DescribeTitleAvatarAwards(CMatchTitle *this)
{
  return taad;
}

//------------------------------------------------------------------------------
// Address: 0x100028E0
// Name: public: virtual struct TitleDlcDescription_t const __near * CMatchTitle::DescribeTitleDlcs(void)
// Source: json
//------------------------------------------------------------------------------
const TitleDlcDescription_t *__thiscall CMatchTitle::DescribeTitleDlcs(CMatchTitle *this)
{
  return tdlcs;
}

//------------------------------------------------------------------------------
// Address: 0x100028F0
// Name: public: virtual struct TitleDataFieldsDescription_t const __near * CMatchTitle::DescribeTitleDataStorage(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTable::StringPool_t **__thiscall CMatchTitle::DescribeTitleDataStorage(CMatchTitle *this)
{
  if ( (_S2_0 & 1) != 0 )
    return (CUtlSymbolTable::StringPool_t **)s_pTDFD;
  _S2_0 |= 1u;
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    stru_10081830.m_Memory.m_pMemory = nullptr;
    stru_10081830.m_Memory.m_nAllocationCount = 0;
    stru_10081830.m_Memory.m_nGrowSize = 0;
    stru_10081830.m_Size = 0;
    stru_10081830.m_pElements = nullptr;
    atexit(func: PrepareTitleDataStorageDescription_::_2_::_dynamic_atexit_destructor_for__s_tdfd__);
  }
  s_pTDFD = (const TitleDataFieldsDescription_t *)stru_10081830.m_Memory.m_pMemory;
  return stru_10081830.m_Memory.m_pMemory;
}
