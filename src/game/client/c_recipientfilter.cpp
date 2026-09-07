// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_recipientfilter.cpp
// Functions: 11
// ============================================================

#include "game\client\c_recipientfilter.h"

//------------------------------------------------------------------------------
// Address: 0x10249CB0
// Name: public: virtual int C_RecipientFilter::GetRecipientIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_RecipientFilter::GetRecipientIndex(C_RecipientFilter *this, int slot)
{
  if ( slot < 0 || slot >= this->GetRecipientCount(this) )
    return -1;
  else
    return this->m_Recipients.m_Memory.m_pMemory[slot];
}

//------------------------------------------------------------------------------
// Address: 0x10249CE0
// Name: public: void C_RecipientFilter::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RecipientFilter::Reset(C_RecipientFilter *this)
{
  this->m_bReliable = false;
  this->m_Recipients.m_Size = 0;
  *(_WORD *)&this->m_bUsingPredictionRules = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10249CF0
// Name: public: C_RecipientFilter::C_RecipientFilter(void)
// Source: json
//------------------------------------------------------------------------------
C_RecipientFilter *__thiscall C_RecipientFilter::C_RecipientFilter(C_RecipientFilter *this)
{
  this->__vftable = (C_RecipientFilter_vtbl *)&C_RecipientFilter::`vftable';
  this->m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Recipients.m_pElements = nullptr;
  this->m_bReliable = false;
  this->m_Recipients.m_Size = 0;
  *(_WORD *)&this->m_bUsingPredictionRules = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10249D20
// Name: public: virtual C_RecipientFilter::~C_RecipientFilter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RecipientFilter::~C_RecipientFilter(C_RecipientFilter *this)
{
  this->__vftable = (C_RecipientFilter_vtbl *)&C_RecipientFilter::`vftable';
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Recipients);
  this->__vftable = (C_RecipientFilter_vtbl *)&IRecipientFilter::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10249D40
// Name: public: void C_RecipientFilter::UsePredictionRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RecipientFilter::UsePredictionRules(C_RecipientFilter *this)
{
  int (__thiscall *GetRecipientCount)(struct C_RecipientFilter *); // edx
  C_BasePlayer *LocalPlayer; // eax
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  if ( !this->m_bUsingPredictionRules
    && prediction->InPrediction(this: prediction)
    && C_BasePlayer::HasAnyLocalPlayer() != 0 )
  {
    GetRecipientCount = this->GetRecipientCount;
    this->m_bUsingPredictionRules = true;
    if ( GetRecipientCount(this) != 0
      && (g_RecipientFilterPredictionSystem.m_nStatusPushed > 0 || g_RecipientFilterPredictionSystem.m_bSuppressEvent) )
    {
      LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
      if ( LocalPlayer != nullptr )
      {
        src = (vgui::TreeNode *)LocalPlayer->index;
        CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Recipients,
          &src);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249DC0
// Name: public: void C_RecipientFilter::RemoveSplitScreenPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RecipientFilter::RemoveSplitScreenPlayers(C_RecipientFilter *this)
{
  int i; // edi
  C_BasePlayer *v3; // eax

  for ( i = this->GetRecipientCount(this) - 1; i >= 0; --i )
  {
    v3 = UTIL_PlayerByIndex(entindex: this->m_Recipients.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && C_BasePlayer::IsSplitScreenPlayer(this: v3) )
    {
      if ( this->m_Recipients.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&this->m_Recipients.m_Memory.m_pMemory[i],
          src: (unsigned __int8 *)&this->m_Recipients.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_Recipients.m_Size - i - 1));
      --this->m_Recipients.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249E20
// Name: public: void C_RecipientFilter::CopyFrom(class C_RecipientFilter const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RecipientFilter::CopyFrom(C_RecipientFilter *this, C_RecipientFilter *src)
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
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recipients,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Recipients.m_Size;
    m_pMemory = this->m_Recipients.m_Memory.m_pMemory;
    v8 = this->m_Recipients.m_Size - m_Size - 1;
    this->m_Recipients.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v8);
    v9 = &this->m_Recipients.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249EF0
// Name: public: void C_RecipientFilter::AddRecipient(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RecipientFilter::AddRecipient(C_RecipientFilter *this, C_BasePlayer *player)
{
  int index; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_Recipients; // esi
  int m_Size; // ecx
  int v5; // eax
  vgui::TreeNode **m_pMemory; // edx
  vgui::TreeNode **v7; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v9; // ecx
  int v10; // eax
  int *v11; // eax

  if ( player != nullptr )
  {
    index = player->index;
    if ( !this->m_bUsingPredictionRules
      || g_RecipientFilterPredictionSystem.m_nStatusPushed <= 0 && !g_RecipientFilterPredictionSystem.m_bSuppressEvent )
    {
      p_m_Recipients = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recipients;
      m_Size = this->m_Recipients.m_Size;
      v5 = 0;
      if ( m_Size <= 0 )
        goto LABEL_11;
      m_pMemory = p_m_Recipients->m_pMemory;
      while ( *m_pMemory != (vgui::TreeNode *)index )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
          goto LABEL_11;
      }
      if ( v5 == -1 )
      {
LABEL_11:
        if ( C_BasePlayer::IsLocalPlayer(pEntity: player) )
        {
          v7 = p_m_Recipients[1].m_pMemory;
          m_nAllocationCount = p_m_Recipients->m_nAllocationCount;
          if ( (int)v7 + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Recipients, num: (int)v7 - m_nAllocationCount + 1);
          ++p_m_Recipients[1].m_pMemory;
          v9 = p_m_Recipients->m_pMemory;
          v10 = (char *)p_m_Recipients[1].m_pMemory - (char *)v7 - 1;
          p_m_Recipients[1].m_nAllocationCount = (int)p_m_Recipients->m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v9[(_DWORD)v7 + 1],
              src: (unsigned __int8 *)&v9[(_DWORD)v7],
              count: 4 * v10);
          v11 = (int *)&p_m_Recipients->m_pMemory[(_DWORD)v7];
          if ( v11 != nullptr )
            *v11 = index;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249FB0
// Name: public: CLocalPlayerFilter::CLocalPlayerFilter(void)
// Source: json
//------------------------------------------------------------------------------
CLocalPlayerFilter *__thiscall CLocalPlayerFilter::CLocalPlayerFilter(CLocalPlayerFilter *this)
{
  C_BasePlayer *LocalPlayer; // eax

  this->m_Recipients.m_Memory.m_pMemory = nullptr;
  this->m_Recipients.m_Memory.m_nAllocationCount = 0;
  this->m_Recipients.m_Memory.m_nGrowSize = 0;
  this->m_Recipients.m_pElements = nullptr;
  this->m_bReliable = false;
  this->m_Recipients.m_Size = 0;
  *(_WORD *)&this->m_bUsingPredictionRules = 0;
  this->__vftable = (CLocalPlayerFilter_vtbl *)&CLocalPlayerFilter::`vftable';
  if ( C_BasePlayer::GetLocalPlayer(nSlot: -1) != nullptr )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    C_RecipientFilter::AddRecipient(this, player: LocalPlayer);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024A030
// Name: public: void C_RecipientFilter::AddAllPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RecipientFilter::AddAllPlayers(C_RecipientFilter *this)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Recipients; // esi
  C_BasePlayer *LocalPlayer; // eax
  int index; // ebx
  int m_Size; // edx
  int v6; // ecx
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax

  if ( C_BasePlayer::HasAnyLocalPlayer() != 0 )
  {
    p_m_Recipients = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recipients;
    this->m_Recipients.m_Size = 0;
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
    if ( LocalPlayer != nullptr )
    {
      index = LocalPlayer->index;
      if ( !this->m_bUsingPredictionRules
        || g_RecipientFilterPredictionSystem.m_nStatusPushed <= 0 && !g_RecipientFilterPredictionSystem.m_bSuppressEvent )
      {
        m_Size = this->m_Recipients.m_Size;
        v6 = 0;
        if ( m_Size <= 0 )
          goto LABEL_12;
        m_pMemory = p_m_Recipients->m_pMemory;
        while ( *m_pMemory != (vgui::TreeNode *)index )
        {
          ++v6;
          ++m_pMemory;
          if ( v6 >= m_Size )
            goto LABEL_12;
        }
        if ( v6 == -1 )
        {
LABEL_12:
          if ( C_BasePlayer::IsLocalPlayer(pEntity: LocalPlayer) )
          {
            v8 = p_m_Recipients[1].m_pMemory;
            m_nAllocationCount = p_m_Recipients->m_nAllocationCount;
            if ( (int)v8 + 1 > m_nAllocationCount )
              CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Recipients, num: (int)v8 - m_nAllocationCount + 1);
            ++p_m_Recipients[1].m_pMemory;
            v10 = p_m_Recipients->m_pMemory;
            v11 = (char *)p_m_Recipients[1].m_pMemory - (char *)v8 - 1;
            p_m_Recipients[1].m_nAllocationCount = (int)p_m_Recipients->m_pMemory;
            if ( v11 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&v10[(_DWORD)v8 + 1],
                src: (unsigned __int8 *)&v10[(_DWORD)v8],
                count: 4 * v11);
            v12 = &p_m_Recipients->m_pMemory[(_DWORD)v8];
            if ( v12 != nullptr )
              *v12 = (vgui::TreeNode *)index;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024A100
// Name: public: void C_RecipientFilter::AddRecipientsByPVS(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_RecipientFilter::AddRecipientsByPVS(C_RecipientFilter *this, const Vector *origin)
{
  C_RecipientFilter::AddAllPlayers(this);
}
