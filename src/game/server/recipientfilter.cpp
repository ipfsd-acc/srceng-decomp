// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/recipientfilter.cpp
// Functions: 24
// ============================================================

#include "game\server\recipientfilter.h"

//------------------------------------------------------------------------------
// Address: 0x10011970
// Name: public: void CRecipientFilter::MakeReliable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::MakeReliable(CFmtStrN<1024> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x101F45D0
// Name: public: virtual bool CRecipientFilter::IsReliable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRecipientFilter::IsReliable(CRecipientFilter *this)
{
  return this->m_bReliable;
}

//------------------------------------------------------------------------------
// Address: 0x101F45E0
// Name: public: virtual bool CRecipientFilter::IsInitMessage(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRecipientFilter::IsInitMessage(CRecipientFilter *this)
{
  return this->m_bInitMessage;
}

//------------------------------------------------------------------------------
// Address: 0x101F45F0
// Name: public: void CRecipientFilter::MakeInitMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::MakeInitMessage(CRecipientFilter *this)
{
  this->m_bInitMessage = true;
}

//------------------------------------------------------------------------------
// Address: 0x101F4600
// Name: public: bool CRecipientFilter::IgnorePredictionCull(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRecipientFilter::IgnorePredictionCull(CRecipientFilter *this)
{
  return this->m_bIgnorePredictionCull;
}

//------------------------------------------------------------------------------
// Address: 0x101F4610
// Name: public: void CRecipientFilter::SetIgnorePredictionCull(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::SetIgnorePredictionCull(CRecipientFilter *this, bool ignore)
{
  this->m_bIgnorePredictionCull = ignore;
}

//------------------------------------------------------------------------------
// Address: 0x101F4650
// Name: public: virtual int CRecipientFilter::GetRecipientIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRecipientFilter::GetRecipientIndex(CRecipientFilter *this, int slot)
{
  if ( slot < 0 || slot >= this->GetRecipientCount(this) )
    return -1;
  else
    return this->m_Recipients.m_Memory.m_pMemory[slot];
}

//------------------------------------------------------------------------------
// Address: 0x101F4680
// Name: public: void CRecipientFilter::RemoveAllRecipients(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::RemoveAllRecipients(CRecipientFilter *this)
{
  this->m_Recipients.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F4690
// Name: public: void CRecipientFilter::RemoveRecipient(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::RemoveRecipient(CRecipientFilter *this, signed int player)
{
  edict_t *v2; // eax

  if ( player != 0 )
  {
    v2 = *(edict_t **)(player + 24);
    if ( v2 != nullptr )
      player = v2 - gpGlobals->pEdicts;
    else
      player = 0;
    CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Recipients,
      src: (vgui::TreeNode *const *)&player);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F46E0
// Name: public: void CRecipientFilter::RemoveRecipientByPlayerIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::RemoveRecipientByPlayerIndex(CRecipientFilter *this, int playerindex)
{
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Recipients,
    src: (vgui::TreeNode *const *)&playerindex);
}

//------------------------------------------------------------------------------
// Address: 0x101F4700
// Name: public: void CRecipientFilter::RemoveRecipientsByTeam(class CTeam __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::RemoveRecipientsByTeam(CRecipientFilter *this, CTeam *team)
{
  CTeam *v2; // edi
  int v3; // ebx
  int i; // esi
  int v5; // eax
  signed int v6; // eax

  v2 = team;
  v3 = team->GetNumPlayers(this: team);
  for ( i = 0; i < v3; ++i )
  {
    v5 = (int)v2->GetPlayer(this: v2, a2: i);
    if ( v5 != 0 )
    {
      v6 = *(_DWORD *)(v5 + 24);
      if ( v6 != 0 )
        v6 = (signed int)(v6 - (unsigned int)gpGlobals->pEdicts) >> 4;
      team = (CTeam *)v6;
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Recipients,
        src: (vgui::TreeNode *const *)&team);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4770
// Name: public: void CRecipientFilter::RemoveRecipientsNotOnTeam(class CTeam __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::RemoveRecipientsNotOnTeam(CRecipientFilter *this, CTeam *team)
{
  int i; // edi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  signed int m_pPev; // eax
  vgui::TreeNode *src; // [esp+8h] [ebp-4h] BYREF

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: i);
    v5 = v4;
    if ( v4 != nullptr && CBaseEntity::GetTeam(this: v4) != team )
    {
      m_pPev = (signed int)v5->m_Network.m_pPev;
      if ( m_pPev != 0 )
        m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
      src = (vgui::TreeNode *)m_pPev;
      CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Recipients,
        &src);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F47E0
// Name: public: void CRecipientFilter::UsePredictionRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::UsePredictionRules(CRecipientFilter *this)
{
  int (*GetRecipientCount)(void); // edx
  CBasePlayer *m_pSuppressHost; // esi
  CBasePlayer *SplitScreenPlayerOwner; // eax
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenAndPictureInPicturePlayers; // edi
  int i; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  if ( !this->m_bUsingPredictionRules )
  {
    GetRecipientCount = (int (*)(void))this->GetRecipientCount;
    this->m_bUsingPredictionRules = true;
    if ( GetRecipientCount() != 0 && g_RecipientFilterPredictionSystem.m_nStatusPushed <= 0 )
    {
      m_pSuppressHost = (CBasePlayer *)g_RecipientFilterPredictionSystem.m_pSuppressHost;
      if ( g_RecipientFilterPredictionSystem.m_pSuppressHost != nullptr
        && g_RecipientFilterPredictionSystem.m_pSuppressHost->IsPlayer(this: g_RecipientFilterPredictionSystem.m_pSuppressHost) )
      {
        CRecipientFilter::RemoveRecipient(this, player: (signed int)m_pSuppressHost);
        if ( CBasePlayer::IsSplitScreenPlayer(this: m_pSuppressHost) )
        {
          SplitScreenPlayerOwner = CBasePlayer::GetSplitScreenPlayerOwner(this: m_pSuppressHost);
          CRecipientFilter::RemoveRecipient(this, player: (signed int)SplitScreenPlayerOwner);
        }
        else
        {
          SplitScreenAndPictureInPicturePlayers = CBasePlayer::GetSplitScreenAndPictureInPicturePlayers(this: m_pSuppressHost);
          for ( i = 0; i < SplitScreenAndPictureInPicturePlayers->m_Size; ++i )
          {
            m_Index = SplitScreenAndPictureInPicturePlayers->m_Memory.m_pMemory[i].m_Index;
            if ( m_Index != -1
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
            {
              m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
              if ( m_pEntity != nullptr )
                CRecipientFilter::RemoveRecipient(this, player: (signed int)m_pEntity);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F48B0
// Name: public: void CRecipientFilter::RemoveSplitScreenPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::RemoveSplitScreenPlayers(CRecipientFilter *this)
{
  int i; // edi
  CBasePlayer *v3; // eax

  for ( i = this->GetRecipientCount(this) - 1; i >= 0; --i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: this->m_Recipients.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && CBasePlayer::IsSplitScreenPlayer(this: v3) )
    {
      if ( this->m_Recipients.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &this->m_Recipients.m_Memory.m_pMemory[i],
          src: &this->m_Recipients.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_Recipients.m_Size - i - 1));
      --this->m_Recipients.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4910
// Name: public: CRecipientFilter::CRecipientFilter(void)
// Source: json
//------------------------------------------------------------------------------
CRecipientFilter *__thiscall CRecipientFilter::CRecipientFilter(CRecipientFilter *this)
{
  this->__vftable = (CRecipientFilter_vtbl *)&CRecipientFilter::`vftable';
  this->m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Recipients.m_pElements = nullptr;
  *(_WORD *)&this->m_bReliable = 0;
  this->m_Recipients.m_Size = 0;
  *(_WORD *)&this->m_bUsingPredictionRules = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F4940
// Name: public: virtual CRecipientFilter::~CRecipientFilter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::~CRecipientFilter(CRecipientFilter *this)
{
  this->__vftable = (CRecipientFilter_vtbl *)&CRecipientFilter::`vftable';
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Recipients);
  this->__vftable = (CRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101F4990
// Name: public: void CRecipientFilter::CopyFrom(class CRecipientFilter const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::CopyFrom(CRecipientFilter *this, CRecipientFilter *src)
{
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // edi
  int c; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  this->m_bReliable = src->IsReliable(this: src);
  this->m_bInitMessage = src->IsInitMessage(this: src);
  this->m_bUsingPredictionRules = src->m_bUsingPredictionRules;
  this->m_bIgnorePredictionCull = src->m_bIgnorePredictionCull;
  c = src->GetRecipientCount(this: src);
  for ( i = 0; i < c; ++i )
  {
    v4 = src->GetRecipientIndex(this: src, a2: i);
    m_Size = this->m_Recipients.m_Size;
    v11 = v4;
    m_nAllocationCount = this->m_Recipients.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recipients,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Recipients.m_Size;
    m_pMemory = this->m_Recipients.m_Memory.m_pMemory;
    v8 = this->m_Recipients.m_Size - m_Size - 1;
    this->m_Recipients.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_Recipients.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4A60
// Name: public: void CRecipientFilter::AddRecipient(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::AddRecipient(CRecipientFilter *this, CBasePlayer *player)
{
  edict_t *m_pPev; // eax
  signed int v3; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_Recipients; // esi
  int m_Size; // ecx
  int v6; // eax
  vgui::TreeNode **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  signed int *v12; // eax

  if ( player != nullptr )
  {
    m_pPev = player->m_Network.m_pPev;
    v3 = m_pPev != nullptr ? m_pPev - gpGlobals->pEdicts : 0;
    if ( !this->m_bUsingPredictionRules
      || (g_RecipientFilterPredictionSystem.m_nStatusPushed > 0
        ? nullptr
        : g_RecipientFilterPredictionSystem.m_pSuppressHost) != player )
    {
      p_m_Recipients = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recipients;
      m_Size = this->m_Recipients.m_Size;
      v6 = 0;
      if ( m_Size <= 0 )
        goto LABEL_13;
      m_pMemory = p_m_Recipients->m_pMemory;
      while ( *m_pMemory != (vgui::TreeNode *)v3 )
      {
        ++v6;
        ++m_pMemory;
        if ( v6 >= m_Size )
          goto LABEL_13;
      }
      if ( v6 == -1 )
      {
LABEL_13:
        m_nAllocationCount = p_m_Recipients->m_nAllocationCount;
        v9 = m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Recipients, num: m_Size - m_nAllocationCount + 1);
        ++p_m_Recipients[1].m_pMemory;
        v10 = p_m_Recipients->m_pMemory;
        v11 = (int)p_m_Recipients[1].m_pMemory - v9 - 1;
        p_m_Recipients[1].m_nAllocationCount = (int)p_m_Recipients->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
        v12 = (signed int *)&p_m_Recipients->m_pMemory[v9];
        if ( v12 != nullptr )
          *v12 = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4B20
// Name: public: void CRecipientFilter::AddRecipientsByTeam(class CTeam __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::AddRecipientsByTeam(CRecipientFilter *this, CTeam *team)
{
  CTeam *v2; // edi
  CRecipientFilter *v3; // esi
  int v4; // eax
  int v5; // ecx
  CBaseEntity *v6; // eax
  edict_t *m_pPev; // ecx
  signed int v8; // ebx
  int m_Size; // ecx
  int v10; // eax
  int *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v13; // edi
  int *v14; // ecx
  int v15; // eax
  signed int *v16; // eax
  int c; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  v2 = team;
  v3 = this;
  v4 = team->GetNumPlayers(this: team);
  v5 = 0;
  c = v4;
  i = 0;
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      v6 = v2->GetPlayer(this: v2, a2: v5);
      if ( v6 != nullptr )
      {
        m_pPev = v6->m_Network.m_pPev;
        v8 = m_pPev != nullptr ? m_pPev - gpGlobals->pEdicts : 0;
        if ( !v3->m_bUsingPredictionRules
          || (g_RecipientFilterPredictionSystem.m_nStatusPushed > 0
            ? nullptr
            : g_RecipientFilterPredictionSystem.m_pSuppressHost) != v6 )
        {
          m_Size = v3->m_Recipients.m_Size;
          v10 = 0;
          if ( m_Size <= 0 )
            goto LABEL_16;
          m_pMemory = v3->m_Recipients.m_Memory.m_pMemory;
          while ( *m_pMemory != v8 )
          {
            ++v10;
            ++m_pMemory;
            if ( v10 >= m_Size )
              goto LABEL_16;
          }
          if ( v10 == -1 )
          {
LABEL_16:
            m_nAllocationCount = v3->m_Recipients.m_Memory.m_nAllocationCount;
            v13 = v3->m_Recipients.m_Size;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_Recipients,
                num: v13 - m_nAllocationCount + 1);
            ++v3->m_Recipients.m_Size;
            v14 = v3->m_Recipients.m_Memory.m_pMemory;
            v15 = v3->m_Recipients.m_Size - v13 - 1;
            v3->m_Recipients.m_pElements = v14;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[v13 + 1], src: &v14[v13], count: 4 * v15);
            v16 = &v3->m_Recipients.m_Memory.m_pMemory[v13];
            v2 = team;
            if ( v16 != nullptr )
              *v16 = v8;
          }
        }
      }
      v5 = i + 1;
      i = v5;
      if ( v5 >= c )
        break;
      v3 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4C30
// Name: public: void CRecipientFilter::AddPlayersFromBitMask(class CBitVec<64> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::AddPlayersFromBitMask(CRecipientFilter *this, CBitVec<64> *playerbits)
{
  int v3; // eax
  unsigned int v4; // ecx
  CBitVec<64> *v5; // edx
  int i; // eax
  int v7; // esi
  CBasePlayer *v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  unsigned int *v11; // edx
  unsigned int v12; // edx

  v3 = 0;
  v4 = `GetStartBitMask'::`2'::g_StartMask[0] & playerbits->m_Ints[0];
  v5 = playerbits;
  while ( v4 == 0 )
  {
    v4 = v5->m_Ints[1];
    v5 = (CBitVec<64> *)((char *)v5 + 4);
    if ( ++v3 > 1 )
      return;
  }
  _BitScanForward(&v4, v4);
  for ( i = v4 + 32 * v3; i > -1; i = v12 + 32 * v9 )
  {
    v7 = i + 1;
    v8 = UTIL_PlayerByIndex(playerIndex: i + 1);
    if ( v8 != nullptr )
      CRecipientFilter::AddRecipient(this, player: v8);
    if ( v7 >= 64 )
      break;
    v9 = v7 >> 5;
    v10 = playerbits->m_Ints[v7 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v7 & 0x1F];
    v11 = &playerbits->m_Ints[v7 >> 5];
    while ( v10 == 0 )
    {
      v10 = v11[1];
      ++v11;
      if ( ++v9 > 1 )
        return;
    }
    _BitScanForward(&v12, v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4CD0
// Name: public: void CRecipientFilter::AddAllPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::AddAllPlayers(CRecipientFilter *this)
{
  CRecipientFilter *v1; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_Recipients; // esi
  int v3; // eax
  CBasePlayer *v4; // eax
  edict_t *m_pPev; // ecx
  signed int v6; // ebx
  int m_pMemory; // edx
  int v8; // eax
  vgui::TreeNode **v9; // ecx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v11; // edi
  vgui::TreeNode **v12; // ecx
  int v13; // eax
  signed int *v14; // eax
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  p_m_Recipients = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recipients;
  this->m_Recipients.m_Size = 0;
  v3 = 1;
  i = 1;
  if ( gpGlobals->maxClients >= 1 )
  {
    while ( 1 )
    {
      v4 = UTIL_PlayerByIndex(playerIndex: v3);
      if ( v4 != nullptr )
      {
        m_pPev = v4->m_Network.m_pPev;
        v6 = m_pPev != nullptr ? m_pPev - gpGlobals->pEdicts : 0;
        if ( !v1->m_bUsingPredictionRules
          || (g_RecipientFilterPredictionSystem.m_nStatusPushed > 0
            ? nullptr
            : g_RecipientFilterPredictionSystem.m_pSuppressHost) != v4 )
        {
          m_pMemory = (int)p_m_Recipients[1].m_pMemory;
          v8 = 0;
          if ( m_pMemory <= 0 )
            goto LABEL_16;
          v9 = p_m_Recipients->m_pMemory;
          while ( *v9 != (vgui::TreeNode *)v6 )
          {
            ++v8;
            ++v9;
            if ( v8 >= m_pMemory )
              goto LABEL_16;
          }
          if ( v8 == -1 )
          {
LABEL_16:
            m_nAllocationCount = p_m_Recipients->m_nAllocationCount;
            v11 = p_m_Recipients[1].m_pMemory;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Recipients, num: m_pMemory - m_nAllocationCount + 1);
            ++p_m_Recipients[1].m_pMemory;
            v12 = p_m_Recipients->m_pMemory;
            v13 = (char *)p_m_Recipients[1].m_pMemory - (char *)v11 - 1;
            p_m_Recipients[1].m_nAllocationCount = (int)p_m_Recipients->m_pMemory;
            if ( v13 > 0 )
              _V_memmove(dest: &v12[(_DWORD)v11 + 1], src: &v12[(_DWORD)v11], count: 4 * v13);
            v14 = (signed int *)&p_m_Recipients->m_pMemory[(_DWORD)v11];
            if ( v14 != nullptr )
              *v14 = v6;
          }
        }
      }
      v3 = i + 1;
      i = v3;
      if ( v3 > gpGlobals->maxClients )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4DD0
// Name: public: void CRecipientFilter::AddRecipientsByPVS(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::AddRecipientsByPVS(CRecipientFilter *this, const Vector *origin)
{
  CBitVec<64> playerbits; // [esp+4h] [ebp-8h] BYREF

  if ( gpGlobals->maxClients == 1 )
  {
    CRecipientFilter::AddAllPlayers(this);
  }
  else
  {
    playerbits = 0;
    engine->Message_DetermineMulticastRecipients(this: engine, a2: false, a3: origin, a4: &playerbits);
    CRecipientFilter::AddPlayersFromBitMask(this, &playerbits);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4E30
// Name: public: void CRecipientFilter::AddRecipientsByPAS(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecipientFilter::AddRecipientsByPAS(CRecipientFilter *this, const Vector *origin)
{
  CBitVec<64> playerbits; // [esp+4h] [ebp-8h] BYREF

  if ( gpGlobals->maxClients == 1 )
  {
    CRecipientFilter::AddAllPlayers(this);
  }
  else
  {
    playerbits = 0;
    engine->Message_DetermineMulticastRecipients(this: engine, a2: true, a3: origin, a4: &playerbits);
    CRecipientFilter::AddPlayersFromBitMask(this, &playerbits);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4E90
// Name: public: void CPASAttenuationFilter::Filter(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPASAttenuationFilter::Filter(
        CPASAttenuationFilter *this@<ecx>,
        int a2@<ebp>,
        const Vector *origin,
        float attenuation)
{
  bool v4; // zf
  CPASAttenuationFilter *v5; // esi
  int (__thiscall *GetRecipientCount)(struct CPASAttenuationFilter *); // eax
  int v7; // eax
  int v8; // eax
  edict_t *pEdicts; // edi
  edict_t *v10; // eax
  IServerUnknown *m_pUnk; // ecx
  int v12; // eax
  CBasePlayer *v13; // esi
  float *v14; // eax
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenAndPictureInPicturePlayers; // edi
  int v16; // esi
  CBaseEntity *v17; // eax
  float *v18; // eax
  int v19; // [esp-28h] [ebp-34h] BYREF
  int v20; // [esp-1Ch] [ebp-28h] BYREF
  CBasePlayer *v21; // [esp-10h] [ebp-1Ch]
  CPASAttenuationFilter *v22; // [esp-Ch] [ebp-18h]
  float v23; // [esp-8h] [ebp-14h]
  int v24; // [esp-4h] [ebp-10h]
  int v25; // [esp+0h] [ebp-Ch]
  float maxAudible; // [esp+4h] [ebp-8h]
  float retaddr; // [esp+Ch] [ebp+0h]

  v25 = a2;
  maxAudible = retaddr;
  v4 = gpGlobals->maxClients == 1;
  v5 = this;
  v22 = this;
  if ( !v4 )
  {
    if ( attenuation <= 0.0 )
    {
      CRecipientFilter::AddAllPlayers(this);
      return;
    }
    GetRecipientCount = this->GetRecipientCount;
    v23 = 2000.0 / attenuation;
    v7 = GetRecipientCount(this) - 1;
    v24 = v7;
    if ( v7 >= 0 )
    {
      while ( 1 )
      {
        v8 = v5->GetRecipientIndex(this: v5, a2: v7);
        pEdicts = gpGlobals->pEdicts;
        if ( pEdicts != nullptr )
          v10 = (pEdicts[v8].m_fStateFlags & 2) == 0 ? &pEdicts[v8] : nullptr;
        else
          v10 = nullptr;
        if ( v10 != nullptr || pEdicts != nullptr && (v10 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
        {
          m_pUnk = v10->m_pUnk;
          if ( m_pUnk != nullptr )
          {
            v12 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
            v13 = (CBasePlayer *)v12;
            v21 = (CBasePlayer *)v12;
            if ( v12 != 0
              && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v12 + 336))(a1: v12) != 0
              && v13->IsPlayer(this: v13)
              && !v13->pl.hltv
              && !v13->pl.replay )
            {
              v14 = (float *)v13->EarPosition(this: v13, result: (Vector *)&v20);
              if ( v23 < fsqrt(
                           (float)((float)((float)(v14[1] - origin->y) * (float)(v14[1] - origin->y))
                                 + (float)((float)(v14[2] - origin->z) * (float)(v14[2] - origin->z)))
                         + (float)((float)(*v14 - origin->x) * (float)(*v14 - origin->x))) )
              {
                if ( CBasePlayer::GetSplitScreenAndPictureInPicturePlayers(this: v13)->m_Size == 0 )
                  goto LABEL_26;
                SplitScreenAndPictureInPicturePlayers = CBasePlayer::GetSplitScreenAndPictureInPicturePlayers(this: v13);
                v16 = 0;
                if ( SplitScreenAndPictureInPicturePlayers->m_Size <= 0 )
                {
LABEL_25:
                  v13 = v21;
LABEL_26:
                  CRecipientFilter::RemoveRecipient(this: v22, player: (signed int)v13);
                  goto LABEL_27;
                }
                while ( 1 )
                {
                  v17 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&SplitScreenAndPictureInPicturePlayers->m_Memory.m_pMemory[v16]);
                  if ( v17 != nullptr )
                  {
                    v18 = (float *)v17->EarPosition(this: v17, result: (Vector *)&v19);
                    if ( v23 >= fsqrt(
                                  (float)((float)((float)(v18[1] - origin->y) * (float)(v18[1] - origin->y))
                                        + (float)((float)(v18[2] - origin->z) * (float)(v18[2] - origin->z)))
                                + (float)((float)(*v18 - origin->x) * (float)(*v18 - origin->x))) )
                      break;
                  }
                  if ( ++v16 >= SplitScreenAndPictureInPicturePlayers->m_Size )
                    goto LABEL_25;
                }
              }
            }
          }
        }
LABEL_27:
        if ( --v24 < 0 )
          return;
        v5 = v22;
        v7 = v24;
      }
    }
  }
}
