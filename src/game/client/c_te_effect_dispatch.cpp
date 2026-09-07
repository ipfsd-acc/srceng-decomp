// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_effect_dispatch.cpp
// Functions: 195
// ============================================================

#include "game\client\c_te_effect_dispatch.h"

//------------------------------------------------------------------------------
// Address: 0x10001320
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CAchievementMgr::GetAchievedDuringCurrentGame(int)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<int,CUtlMemory<int,int> > *__thiscall CAchievementMgr::GetAchievedDuringCurrentGame(
        CAchievementMgr *this,
        int nPlayerSlot)
{
  return &this->m_AchievementsAwardedDuringCurrentGame[nPlayerSlot];
}

//------------------------------------------------------------------------------
// Address: 0x10016910
// Name: public: int CUtlVector<struct thinkfunc_t,class CUtlMemory<struct thinkfunc_t,int>>::InsertBefore(int,struct thinkfunc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int>>::InsertBefore(
        CUtlVector<thinkfunc_t,CUtlMemory<thinkfunc_t,int> > *this,
        int elem,
        const thinkfunc_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  thinkfunc_t *m_pMemory; // ecx
  int v7; // eax
  thinkfunc_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailPropSpriteDict_t,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100184F0
// Name: public: class CUtlVector<class CHandle<class C_BasePlayer>,class CUtlMemory<class CHandle<class C_BasePlayer>,int>> __near & C_BasePlayer::GetSplitScreenPlayers(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int> > *__thiscall C_BasePlayer::GetSplitScreenPlayers(
        C_BasePlayer *this)
{
  return &this->m_hSplitScreenPlayers;
}

//------------------------------------------------------------------------------
// Address: 0x1001AC30
// Name: public: int CUtlVector<class CHandle<class C_BasePlayer>,class CUtlMemory<class CHandle<class C_BasePlayer>,int>>::Find(class CHandle<class C_BasePlayer> const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int>>::Find(
        CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int> > *this,
        CHandle<C_BaseCombatWeapon> *src)
{
  int v2; // edi
  CHandle<C_BasePlayer> *m_pMemory; // esi
  CBaseEntityList *v4; // ebx
  C_BaseCombatWeapon *v5; // eax
  unsigned int m_Index; // edx
  C_BaseCombatWeapon *m_pEntity; // ecx
  int m_Size; // [esp+Ch] [ebp-4h]

  v2 = 0;
  m_Size = this->m_Size;
  if ( m_Size <= 0 )
    return -1;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = g_pEntityList;
  while ( 1 )
  {
    v5 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: src);
    m_Index = m_pMemory->m_Index;
    if ( m_pMemory->m_Index == -1 || v4->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseCombatWeapon *)v4->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == v5 )
      break;
    ++v2;
    ++m_pMemory;
    if ( v2 >= m_Size )
      return -1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001B540
// Name: public: int CUtlVector<class CBaseAchievement __near *,class CUtlMemory<class CBaseAchievement __near *,int>>::AddVectorToTail(class CUtlVector<class CBaseAchievement __near *,class CUtlMemory<class CBaseAchievement __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::AddVectorToTail(
        CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int> > *this,
        const CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  CBaseAchievement **m_pMemory; // edx
  CBaseAchievement **v7; // eax
  CBaseAchievement **v8; // ecx
  int v9; // eax
  int v10; // edx
  CBaseAchievement **v11; // ecx
  unsigned int v13; // [esp-4h] [ebp-14h]
  int base; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  v5 = v4 + m_Size;
  base = m_Size;
  if ( this->m_Memory.m_nAllocationCount < v4 + m_Size && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v5;
    v13 = 4 * v5;
    if ( m_pMemory != nullptr )
      v7 = (CBaseAchievement **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v13);
    else
      v7 = (CBaseAchievement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v13);
    this->m_Memory.m_pMemory = v7;
  }
  v8 = this->m_Memory.m_pMemory;
  this->m_Size += v4;
  v9 = 0;
  this->m_pElements = v8;
  if ( v4 > 0 )
  {
    v10 = m_Size;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        *v11 = src->m_Memory.m_pMemory[v9];
        m_Size = base;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < v4 );
  }
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1002A3B0
// Name: public: int CUtlVector<class matrix3x4a_t,class CUtlMemoryAligned<class matrix3x4a_t,16>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<matrix3x4a_t,CUtlMemoryAligned<matrix3x4a_t,16>>::InsertMultipleBefore(
        CUtlVector<matrix3x4a_t,CUtlMemoryAligned<matrix3x4a_t,16> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  matrix3x4a_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemoryAligned<matrix3x4a_t,16>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 48 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002DE90
// Name: public: int CUtlVector<class C_AnimationLayer,class CUtlMemory<class C_AnimationLayer,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::InsertMultipleBefore(
        CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  C_AnimationLayer *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  C_AnimationLayer *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<SaveRestoreBlockHeader_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          v12->m_nSequence.m_Val = 0;
          v12->m_flPrevCycle.m_Val = 0.0;
          v12->m_flWeight.m_Val = 0.0;
          v12->m_flPlaybackRate.m_Val = 1.0;
          v12->m_flCycle.m_Val = 0.0;
          v12->m_pOwner = nullptr;
          v12->m_nInvalidatePhysicsBits = 0;
          C_AnimationLayer::Reset(this: v12);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1002DF60
// Name: public: int CUtlVector<class CAttachmentData,class CUtlMemory<class CAttachmentData,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAttachmentData,CUtlMemory<CAttachmentData,int>>::InsertMultipleBefore(
        CUtlVector<CAttachmentData,CUtlMemory<CAttachmentData,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAttachmentData *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ScaleformPlayerScoreRow,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100325E0
// Name: public: int CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ScriptFunctionBinding_t *m_pMemory; // ecx
  int v6; // eax
  ScriptFunctionBinding_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDetailModel,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
    v7->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
    v7->m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
    v7->m_desc.m_Parameters.m_Size = 0;
    v7->m_desc.m_Parameters.m_pElements = nullptr;
    v7->m_desc.m_pszFunction = nullptr;
    v7->m_desc.m_ReturnType = 31;
    v7->m_desc.m_pszDescription = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10032670
// Name: public: void CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::RemoveAll(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 48 * v1;
    v5 = 48 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 7) = 0;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 4));
          this = v6;
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      v4 = *((void **)v3 + 4);
      *((_DWORD *)v3 + 8) = v4;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      --v1;
      v2 = v5 - 48;
      v5 -= 48;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032C80
// Name: public: CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::~CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this)
{
  bool v2; // sf
  ScriptFunctionBinding_t *m_pMemory; // eax

  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033EC0
// Name: public: void CUtlVector<class C_AnimationLayer,class CUtlMemory<class C_AnimationLayer,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::EnsureCapacity(
        CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int> > *this,
        int num)
{
  C_AnimationLayer *m_pMemory; // edx
  unsigned int v4; // eax
  C_AnimationLayer *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 40 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (C_AnimationLayer *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (C_AnimationLayer *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033F30
// Name: public: void CUtlVector<class CInterpolatedVar<class C_AnimationLayer>,class CUtlMemory<class CInterpolatedVar<class C_AnimationLayer>,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int>>::RemoveMultiple(
        CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int> > *this,
        int elem,
        int num)
{
  int v3; // edx
  int v6; // ecx
  int v7; // edi
  int v8; // [esp+8h] [ebp-4h]
  int elema; // [esp+14h] [ebp+8h]

  v3 = num;
  v6 = elem + num;
  v8 = elem + num;
  if ( elem + num - 1 >= elem )
  {
    v7 = elem + num - 1;
    elema = num;
    do
    {
      ((void (__thiscall *)(CInterpolatedVar<C_AnimationLayer> *, _DWORD))this->m_Memory.m_pMemory[v7].dtr_IInterpolatedVar)(
        a1: &this->m_Memory.m_pMemory[v7],
        a2: 0);
      --v7;
      --elema;
    }
    while ( elema != 0 );
    v3 = num;
    v6 = v8;
  }
  if ( this->m_Size - elem - v3 <= 0 || v3 <= 0 )
  {
    this->m_Size -= v3;
  }
  else
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[v6],
      count: 44 * (this->m_Size - elem - v3));
    this->m_Size -= num;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034290
// Name: public: void CUtlVector<class CInterpolatedVar<class C_AnimationLayer>,class CUtlMemory<class CInterpolatedVar<class C_AnimationLayer>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int>>::Purge(
        CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CInterpolatedVar<C_AnimationLayer> *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      ((void (__thiscall *)(CInterpolatedVar<C_AnimationLayer> *, _DWORD))this->m_Memory.m_pMemory[v3].dtr_IInterpolatedVar)(
        a1: &this->m_Memory.m_pMemory[v3],
        a2: 0);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100345F0
// Name: public: void CUtlVector<class C_AnimationLayer,class CUtlMemory<class C_AnimationLayer,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::RemoveMultiple(
        CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 40 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x10035590
// Name: public: int CUtlVector<class C_AnimationLayer,class CUtlMemory<class C_AnimationLayer,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::InsertBefore(
        CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  C_AnimationLayer *m_pMemory; // ecx
  int v6; // eax
  C_AnimationLayer *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SaveRestoreBlockHeader_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 40 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_pOwner = nullptr;
    v7->m_nInvalidatePhysicsBits = 0;
    v7->m_nSequence.m_Val = 0;
    v7->m_flPrevCycle.m_Val = 0.0;
    v7->m_flWeight.m_Val = 0.0;
    v7->m_flPlaybackRate.m_Val = 0.0;
    v7->m_flCycle.m_Val = 0.0;
    v7->m_flLayerAnimtime = 0.0;
    v7->m_flLayerFadeOuttime = 0.0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10036640
// Name: public: int CUtlVector<class CInterpolatedVar<class C_AnimationLayer>,class CUtlMemory<class CInterpolatedVar<class C_AnimationLayer>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int>>::InsertMultipleBefore(
        CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CInterpolatedVar<C_AnimationLayer> *m_pMemory; // ecx
  int v10; // eax
  int v11; // eax
  CInterpolatedVarArrayBase<C_AnimationLayer,0> *v12; // esi
  bool v13; // zf
  int v14; // [esp+14h] [ebp-4h]
  int numa; // [esp+24h] [ebp+Ch]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 44 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = 44 * v8;
      numa = 44 * v8;
      v14 = num;
      do
      {
        v12 = (CInterpolatedVar<C_AnimationLayer> *)((char *)this->m_Memory.m_pMemory + v11);
        if ( v12 != nullptr )
        {
          v12->__vftable = (CInterpolatedVarArrayBase<C_AnimationLayer,0>_vtbl *)&CInterpolatedVarArrayBase<C_AnimationLayer,0>::`vftable';
          v12->m_VarHistory.m_pElements = nullptr;
          *(_DWORD *)&v12->m_VarHistory.m_maxElement = 0;
          *(_DWORD *)&v12->m_VarHistory.m_count = 0x100000;
          CSimpleRingBuffer<CInterpolatedVarEntryBase<C_AnimationLayer,0>>::EnsureCapacity(
            this: &v12->m_VarHistory,
            capSize: 4);
          v12->m_pDebugName = nullptr;
          v12->m_pValue = nullptr;
          v12->m_InterpolationAmount = 0.0;
          *(_WORD *)&v12->m_fType = 1;
          v12->m_LastNetworkedTime = 0.0;
          v12->m_LastNetworkedValue = nullptr;
          v12->m_bLooping = nullptr;
          v12->__vftable = (CInterpolatedVarArrayBase<C_AnimationLayer,0>_vtbl *)&CInterpolatedVar<C_AnimationLayer>::`vftable';
          CInterpolatedVarArrayBase<C_AnimationLayer,0>::SetMaxCount(this: v12, flCurrentTime: 0.0, newmax: 1);
          v11 = numa;
          v8 = elem;
        }
        v11 += 44;
        v13 = v14-- == 1;
        numa = v11;
      }
      while ( !v13 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10046820
// Name: public: int CUtlVector<class CSceneEventInfo,class CUtlMemory<class CSceneEventInfo,int>>::InsertBefore(int,class CSceneEventInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSceneEventInfo,CUtlMemory<CSceneEventInfo,int>>::InsertBefore(
        CUtlVector<CSceneEventInfo,CUtlMemory<CSceneEventInfo,int> > *this,
        int elem,
        const CSceneEventInfo *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSceneEventInfo *m_pMemory; // ecx
  int v7; // eax
  CSceneEventInfo *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ParticleControlPoint_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 76 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CSceneEventInfo::CSceneEventInfo(this: v8, __that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1004FDB0
// Name: public: int CUtlVector<struct LessonEvent_t,class CUtlMemory<struct LessonEvent_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::InsertBefore(
        CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  LessonEvent_t *m_pMemory; // ecx
  int v6; // eax
  LessonEvent_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->elements.m_Memory.m_pMemory = nullptr;
    v7->elements.m_Memory.m_nAllocationCount = 0;
    v7->elements.m_Memory.m_nGrowSize = 0;
    v7->elements.m_Size = 0;
    v7->elements.m_pElements = nullptr;
    v7->szEventName.m_SymbolId.m_Id = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1004FE30
// Name: public: void CUtlVector<struct LessonEvent_t,class CUtlMemory<struct LessonEvent_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::RemoveAll(
        CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050070
// Name: public: CUtlVector<struct LessonEvent_t,class CUtlMemory<struct LessonEvent_t,int>>::~CUtlVector<struct LessonEvent_t,class CUtlMemory<struct LessonEvent_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::~CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>(
        CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int> > *this)
{
  bool v2; // sf
  LessonEvent_t *m_pMemory; // eax

  CUtlVector<LessonEvent_t,CUtlMemory<LessonEvent_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100767C0
// Name: public: int CUtlVector<class CSimplePhysics::CNode,class CUtlMemory<class CSimplePhysics::CNode,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSimplePhysics::CNode,CUtlMemory<CSimplePhysics::CNode,int>>::InsertMultipleBefore(
        CUtlVector<CSimplePhysics::CNode,CUtlMemory<CSimplePhysics::CNode,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSimplePhysics::CNode *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CSnowFallManager::SnowFall_t,int>::Grow(
      (CUtlMemory<vgui::SectionedListPanel::section_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10076840
// Name: public: int CUtlVector<struct CaptionLookup_t,class CUtlMemory<struct CaptionLookup_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100774A0
// Name: public: int CUtlVector<struct KeyValueSaverData,class CUtlMemory<struct KeyValueSaverData,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<KeyValueSaverData,CUtlMemory<KeyValueSaverData,int>>::AddToTail(
        CUtlVector<KeyValueSaverData,CUtlMemory<KeyValueSaverData,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValueSaverData *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<KeyValueSaverData,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 272 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1007BF20
// Name: public: int CUtlVector<struct OcclusionHandleViewIDPair_t,class CUtlMemory<struct OcclusionHandleViewIDPair_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int>>::AddToTail(
        CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  OcclusionHandleViewIDPair_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1007C7B0
// Name: public: void CUtlVector<struct OcclusionQueryHiddenData_t,class CUtlMemory<struct OcclusionQueryHiddenData_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int>>::RemoveAll(
        CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int> > *this)
{
  int v1; // edx
  int v2; // ebx
  OcclusionQueryHiddenData_t *v3; // esi
  OcclusionHandleViewIDPair_t *m_pMemory; // eax
  CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int> > *v5; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->occlusionHandles[0].m_Size = 0;
      if ( v3->occlusionHandles[0].m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->occlusionHandles[0].m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->occlusionHandles[0].m_Memory.m_pMemory);
          this = v5;
          v1 = i;
          v3->occlusionHandles[0].m_Memory.m_pMemory = nullptr;
        }
        v3->occlusionHandles[0].m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->occlusionHandles[0].m_Memory.m_pMemory;
      v3->occlusionHandles[0].m_pElements = m_pMemory;
      if ( v3->occlusionHandles[0].m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          this = v5;
          v1 = i;
          v3->occlusionHandles[0].m_Memory.m_pMemory = nullptr;
        }
        v3->occlusionHandles[0].m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
      i = v1;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CCF0
// Name: public: int CUtlVector<struct CPropData::propdata_breakablechunk_t,class CUtlMemory<struct CPropData::propdata_breakablechunk_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPropData::propdata_breakablechunk_t,CUtlMemory<CPropData::propdata_breakablechunk_t,int>>::InsertBefore(
        CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CParticleSystemMgr::RenderCache_t *m_pMemory; // ecx
  int v6; // eax
  CParticleSystemMgr::RenderCache_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_ParticleCollections.m_Memory.m_pMemory = nullptr;
    v7->m_ParticleCollections.m_Memory.m_nAllocationCount = 0;
    v7->m_ParticleCollections.m_Memory.m_nGrowSize = 0;
    v7->m_ParticleCollections.m_Size = 0;
    v7->m_ParticleCollections.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1007D080
// Name: public: CUtlVector<struct OcclusionQueryHiddenData_t,class CUtlMemory<struct OcclusionQueryHiddenData_t,int>>::~CUtlVector<struct OcclusionQueryHiddenData_t,class CUtlMemory<struct OcclusionQueryHiddenData_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int>>::~CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int>>(
        CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int> > *this)
{
  bool v2; // sf
  OcclusionQueryHiddenData_t *m_pMemory; // eax

  CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FAF0
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1008B5D0
// Name: public: int CUtlVector<struct loopingsound_t,class CUtlMemory<struct loopingsound_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<loopingsound_t,CUtlMemory<loopingsound_t,int>>::AddToTail(
        CUtlVector<loopingsound_t,CUtlMemory<loopingsound_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  loopingsound_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<loopingsound_t,int>::Grow((CUtlMemory<VMatrix,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v5 << 6);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10096260
// Name: public: CUtlVector<class VideoPanel __near *,class CUtlMemory<class VideoPanel __near *,int>>::~CUtlVector<class VideoPanel __near *,class CUtlMemory<class VideoPanel __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100965D0
// Name: public: int CUtlVector<class CHandle<class C_VGuiScreen>,class CUtlMemory<class CHandle<class C_VGuiScreen>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<C_VGuiScreen>,CUtlMemory<CHandle<C_VGuiScreen>,int>>::InsertBefore(
        CUtlVector<CHandle<C_VGuiScreen>,CUtlMemory<CHandle<C_VGuiScreen>,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CHandle<C_VGuiScreen> *m_pMemory; // ecx
  int v6; // eax
  CHandle<C_VGuiScreen> *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_Index = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100A2990
// Name: public: int CUtlVector<struct CClientThinkList::ThinkListChanges_t,class CUtlMemory<struct CClientThinkList::ThinkListChanges_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CClientThinkList::ThinkListChanges_t,CUtlMemory<CClientThinkList::ThinkListChanges_t,int>>::InsertBefore(
        CUtlVector<CClientThinkList::ThinkListChanges_t,CUtlMemory<CClientThinkList::ThinkListChanges_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CClientThinkList::ThinkListChanges_t *m_pMemory; // ecx
  int v6; // eax
  CClientThinkList::ThinkListChanges_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_hEnt.m_Index = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100AA0E0
// Name: public: int CUtlVector<struct CViewModelRenderablesList::CEntry,class CUtlMemoryFixedGrowable<struct CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(
        CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  CViewModelRenderablesList::CEntry *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v5 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<CViewModelRenderablesList::CEntry,int>::ConvertToGrowableMemory(
        this: &this->m_Memory,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: v5);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v8 = v7 - elem - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v8);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100AA160
// Name: public: int CUtlVector<struct CClientLeafSystem::RenderableInfo_t __near *,class CUtlMemoryFixedGrowable<struct CClientLeafSystem::RenderableInfo_t __near *,2048,int>>::InsertBefore(int,struct CClientLeafSystem::RenderableInfo_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CClientLeafSystem::RenderableInfo_t *,CUtlMemoryFixedGrowable<CClientLeafSystem::RenderableInfo_t *,2048,int>>::InsertBefore(
        CUtlVector<CClientLeafSystem::RenderableInfo_t *,CUtlMemoryFixedGrowable<CClientLeafSystem::RenderableInfo_t *,2048,int> > *this,
        int elem,
        CClientLeafSystem::RenderableInfo_t **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  CClientLeafSystem::RenderableInfo_t **m_pMemory; // ecx
  int v8; // eax
  CClientLeafSystem::RenderableInfo_t **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<CClientLeafSystem::RenderableInfo_t *,int>::ConvertToGrowableMemory(
        this: &this->m_Memory,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100B8160
// Name: public: void CUtlVector<class CTextureReference,class CUtlMemory<class CTextureReference,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CTextureReference,CUtlMemory<CTextureReference,int>>::Purge(
        CUtlVector<CTextureReference,CUtlMemory<CTextureReference,int> > *this)
{
  int i; // edi
  CTextureReference *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
    CTextureReference::~CTextureReference(this: &this->m_Memory.m_pMemory[i]);
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B81C0
// Name: public: void CUtlVector<class CBoneMergeCache::CMergedBone,class CUtlMemory<class CBoneMergeCache::CMergedBone,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBoneMergeCache::CMergedBone,CUtlMemory<CBoneMergeCache::CMergedBone,int>>::Purge(
        CUtlVector<CBoneMergeCache::CMergedBone,CUtlMemory<CBoneMergeCache::CMergedBone,int> > *this)
{
  bool v2; // sf
  CBoneMergeCache::CMergedBone *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B96A0
// Name: public: int CUtlVector<struct VisibleShadowInfo_t,class CUtlMemory<struct VisibleShadowInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VisibleShadowInfo_t,CUtlMemory<VisibleShadowInfo_t,int>>::AddToTail(
        CUtlVector<VisibleShadowInfo_t,CUtlMemory<VisibleShadowInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  VisibleShadowInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100B96F0
// Name: public: CUtlVector<int,class CUtlMemoryFixedGrowable<int,512,int>>::~CUtlVector<int,class CUtlMemoryFixedGrowable<int,512,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>::~CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>(
        CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int> > *this)
{
  bool v2; // sf
  int *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB200
// Name: public: int CUtlVector<int,class CUtlMemoryFixedGrowable<int,512,int>>::InsertBefore(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>::InsertBefore(
        CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int> > *this,
        int elem,
        int *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<CClientLeafSystem::RenderableInfo_t *,int>::ConvertToGrowableMemory(
        (CUtlMemory<CClientLeafSystem::RenderableInfo_t *,int> *)this,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100BF640
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int num)
{
  Vector *m_pMemory; // edx
  unsigned int v4; // eax
  Vector *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (Vector *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF6B0
// Name: public: void CUtlVector<struct CaptionLookup_t,class CUtlMemory<struct CaptionLookup_t,int>>::CopyArray(struct CaptionLookup_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::CopyArray(
        CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int> > *this,
        const CaptionLookup_t *pArray,
        int size)
{
  int v4; // edx
  int v5; // ecx

  this->m_Size = 0;
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::InsertMultipleBefore(
    (CUtlVector<Vector,CUtlMemory<Vector,int> > *)this,
    elem: 0,
    num: size);
  if ( size > 0 )
  {
    v4 = size;
    v5 = 0;
    do
    {
      this->m_Memory.m_pMemory[v5] = pArray[v5];
      ++v5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6340
// Name: public: int CUtlVector<struct CDecalEmitterSystem::DecalListEntry,class CUtlMemory<struct CDecalEmitterSystem::DecalListEntry,int>>::InsertBefore(int,struct CDecalEmitterSystem::DecalListEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDecalEmitterSystem::DecalListEntry,CUtlMemory<CDecalEmitterSystem::DecalListEntry,int>>::InsertBefore(
        CUtlVector<CDecalEmitterSystem::DecalListEntry,CUtlMemory<CDecalEmitterSystem::DecalListEntry,int> > *this,
        int elem,
        const CDecalEmitterSystem::DecalListEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDecalEmitterSystem::DecalListEntry *m_pMemory; // ecx
  int v7; // eax
  CDecalEmitterSystem::DecalListEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100C9270
// Name: public: void CUtlVector<class CDetailModel,class CUtlMemory<class CDetailModel,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDetailModel,CUtlMemory<CDetailModel,int>>::Purge(
        CUtlVector<CDetailModel,CUtlMemory<CDetailModel,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CDetailModel *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      ((void (__thiscall *)(CDetailModel *, _DWORD))this->m_Memory.m_pMemory[v3].dtr_IHandleEntity)(
        a1: &this->m_Memory.m_pMemory[v3],
        a2: 0);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C92D0
// Name: public: int CUtlVector<class CDetailModel,class CUtlMemory<class CDetailModel,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDetailModel,CUtlMemory<CDetailModel,int>>::InsertBefore(
        CUtlVector<CDetailModel,CUtlMemory<CDetailModel,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDetailModel *m_pMemory; // ecx
  int v6; // eax
  CDetailModel *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDetailModel,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->IClientRenderable::__vftable = (IClientRenderable_vtbl *)&IClientRenderable::`vftable';
    *((_BYTE *)v7 + 36) &= 0x8Fu;
    v7->IClientUnknown::IHandleEntity::__vftable = (CDetailModel_vtbl *)&CDetailModel::`vftable'{for `IClientUnknown'};
    v7->IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CDetailModel::`vftable'{for `IClientRenderable'};
    *(_WORD *)&v7->m_Color.g = -1;
    v7->m_Color.r = -1;
    v7->m_Color.exponent = 0;
    v7->m_pAdvInfo = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100EE240
// Name: public: class CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>> __near & CHud::GetHudPanelList(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *__thiscall CHud::GetHudPanelList(CHud *this)
{
  return &this->m_HudPanelList;
}

//------------------------------------------------------------------------------
// Address: 0x100FC4D0
// Name: public: void CUtlVector<class CCloseCaptionItem __near *,class CUtlMemory<class CCloseCaptionItem __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CCloseCaptionItem *,CUtlMemory<CCloseCaptionItem *,int>>::PurgeAndDeleteElements(
        CUtlVector<CCloseCaptionItem *,CUtlMemory<CCloseCaptionItem *,int> > *this)
{
  int i; // edi
  CCloseCaptionItem *v3; // ebx
  bool v4; // sf
  CCloseCaptionItem **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CCloseCaptionItem::~CCloseCaptionItem(this: this->m_Memory.m_pMemory[i]);
      C_BaseEntity::operator delete(pMem: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD730
// Name: public: int CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::InsertMultipleBefore(
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  AsyncCaption_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ecx
  char *v12; // eax
  int v13; // ecx
  int numa; // [esp+18h] [ebp+Ch]

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<AsyncCaption_t,int>::Grow((CUtlMemory<PanelItem_t,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 84 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = 84 * v8;
      numa = 84 * v8;
      do
      {
        v12 = (char *)this->m_Memory.m_pMemory + v11;
        if ( v12 != nullptr )
        {
          *(_DWORD *)v12 = AsyncCaption_t::BlockInfo_t::Less;
          *((_DWORD *)v12 + 1) = 0;
          *((_DWORD *)v12 + 2) = 0;
          *((_DWORD *)v12 + 3) = 0;
          v13 = *((_DWORD *)v12 + 1);
          *((_DWORD *)v12 + 4) = 0xFFFF;
          *((_DWORD *)v12 + 5) = -1;
          *((_DWORD *)v12 + 6) = v13;
          *((_DWORD *)v12 + 7) = 0;
          *((_DWORD *)v12 + 8) = 0;
          *((_DWORD *)v12 + 9) = 0;
          *((_DWORD *)v12 + 10) = 0;
          *((_DWORD *)v12 + 11) = 0;
          *((_DWORD *)v12 + 12) = 0;
          v12[52] = 0;
          *((_WORD *)v12 + 40) = -1;
          _V_memset(dest: v12 + 56, fill: 0, count: 24);
          v11 = numa;
          v8 = elem;
        }
        v11 += 84;
        --v3;
        numa = v11;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100FFFF0
// Name: public: void CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::RemoveAll(
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl*)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short> > *v3; // esi
  bool (__cdecl *m_LessFunc)(const AsyncCaption_t::BlockInfo_t *, const AsyncCaption_t::BlockInfo_t *); // eax
  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 84 * v1;
    for ( i = 84 * v1; ; v2 = i )
    {
      v3 = (CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl*)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short> > *)((char *)&this->m_Memory.m_pMemory->m_RequestedBlocks + v2);
      v3[1].m_Elements.m_nGrowSize = 0;
      if ( v3[1].m_Elements.m_nAllocationCount >= 0 )
      {
        if ( v3[1].m_LessFunc != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3[1].m_LessFunc);
          v3[1].m_LessFunc = nullptr;
        }
        v3[1].m_Elements.m_pMemory = nullptr;
      }
      m_LessFunc = v3[1].m_LessFunc;
      *(_DWORD *)&v3[1].m_Root = m_LessFunc;
      if ( v3[1].m_Elements.m_nAllocationCount >= 0 )
      {
        if ( m_LessFunc != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_LessFunc);
          v3[1].m_LessFunc = nullptr;
        }
        v3[1].m_Elements.m_pMemory = nullptr;
      }
      CUtlRBTree<AsyncCaption_t::BlockInfo_t,unsigned short,bool (__cdecl *)(AsyncCaption_t::BlockInfo_t const &,AsyncCaption_t::BlockInfo_t const &),CUtlMemory<UtlRBTreeNode_t<AsyncCaption_t::BlockInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: v3);
      v3->m_FirstFree = -1;
      if ( v3->m_Elements.m_nGrowSize >= 0 )
      {
        if ( v3->m_Elements.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Elements.m_pMemory);
          v3->m_Elements.m_pMemory = nullptr;
        }
        v3->m_Elements.m_nAllocationCount = 0;
      }
      v3->m_LastAlloc.index = -1;
      if ( v3->m_Elements.m_nGrowSize >= 0 )
      {
        if ( v3->m_Elements.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Elements.m_pMemory);
          v3->m_Elements.m_pMemory = nullptr;
        }
        v3->m_Elements.m_nAllocationCount = 0;
      }
      i -= 84;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100900
// Name: public: CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>>::~CUtlVector<struct AsyncCaption_t,class CUtlMemory<struct AsyncCaption_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::~CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>(
        CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int> > *this)
{
  bool v2; // sf
  AsyncCaption_t *m_pMemory; // eax

  CUtlVector<AsyncCaption_t,CUtlMemory<AsyncCaption_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106640
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101078E0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlBinaryBlock *v3; // esi
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_nActualLength = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010CE80
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow((CUtlMemory<CUtlSymbol,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10121690
// Name: public: int CUtlVector<struct CHudMessage::message_t,class CUtlMemory<struct CHudMessage::message_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHudMessage::message_t,CUtlMemory<CHudMessage::message_t,int>>::AddToTail(
        CUtlVector<CHudMessage::message_t,CUtlMemory<CHudMessage::message_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHudMessage::message_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101270E0
// Name: public: int CUtlVector<class CUtlVector<struct VoiceCommandMenuItem_t,class CUtlMemory<struct VoiceCommandMenuItem_t,int>>,class CUtlMemory<class CUtlVector<struct VoiceCommandMenuItem_t,class CUtlMemory<struct VoiceCommandMenuItem_t,int>>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int>>,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int>>,int>>::InsertBefore(
        CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> > *m_pMemory; // ecx
  int v6; // eax
  CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> > *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Memory.m_pMemory = nullptr;
    v7->m_Memory.m_nAllocationCount = 0;
    v7->m_Memory.m_nGrowSize = 0;
    v7->m_Size = 0;
    v7->m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1012E9B0
// Name: public: int CUtlVector<struct ParticleControlPoint_t,class CUtlMemory<struct ParticleControlPoint_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ParticleControlPoint_t,CUtlMemory<ParticleControlPoint_t,int>>::InsertBefore(
        CUtlVector<ParticleControlPoint_t,CUtlMemory<ParticleControlPoint_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ParticleControlPoint_t *m_pMemory; // ecx
  int v6; // eax
  ParticleControlPoint_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ParticleControlPoint_t,int>::Grow(
      (CUtlMemory<CSceneEventInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 76 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    ParticleControlPoint_t::ParticleControlPoint_t(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1012ED80
// Name: public: int CUtlVector<struct ParticleEffectList_t,class CUtlMemory<struct ParticleEffectList_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>::InsertBefore(
        CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ParticleEffectList_t *m_pMemory; // ecx
  int v6; // eax
  ParticleEffectList_t *v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->pControlPoints.m_Memory.m_pMemory = nullptr;
    v7->pControlPoints.m_Memory.m_nAllocationCount = 0;
    v7->pControlPoints.m_Memory.m_nGrowSize = 0;
    v7->pControlPoints.m_Size = 0;
    v7->pControlPoints.m_pElements = nullptr;
    v7->pParticleEffect.m_pObj = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1012EE10
// Name: public: void CUtlVector<struct ParticleEffectList_t,class CUtlMemory<struct ParticleEffectList_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>::Remove(
        CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int> > *this,
        int elem)
{
  ParticleEffectList_t *m_pMemory; // edi
  CNewParticleEffect *m_pObj; // ecx
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *v5; // edi

  m_pMemory = this->m_Memory.m_pMemory;
  m_pObj = this->m_Memory.m_pMemory[elem].pParticleEffect.m_pObj;
  v5 = (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pMemory[elem];
  if ( m_pObj != nullptr )
    CNewParticleEffect::Release(this: m_pObj);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: v5);
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 24 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1012EE70
// Name: public: void CUtlVector<struct ParticleEffectList_t,class CUtlMemory<struct ParticleEffectList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>::RemoveAll(
        CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  ParticleEffectList_t *m_pMemory; // esi
  CNewParticleEffect *v4; // ecx
  char *v5; // esi
  void *v6; // eax
  CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int> > *v7; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v7 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v8 = 24 * v1;
    do
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v4 = *(CNewParticleEffect **)((char *)&this->m_Memory.m_pMemory->pParticleEffect.m_pObj + v2);
      v5 = (char *)m_pMemory + v2;
      if ( v4 != nullptr )
        CNewParticleEffect::Release(this: v4);
      *((_DWORD *)v5 + 3) = 0;
      if ( *((int *)v5 + 2) >= 0 )
      {
        if ( *(_DWORD *)v5 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v5);
          *(_DWORD *)v5 = 0;
        }
        *((_DWORD *)v5 + 1) = 0;
      }
      v6 = *(void **)v5;
      *((_DWORD *)v5 + 4) = *(_DWORD *)v5;
      if ( *((int *)v5 + 2) >= 0 )
      {
        if ( v6 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
          *(_DWORD *)v5 = 0;
        }
        *((_DWORD *)v5 + 1) = 0;
      }
      this = v7;
      --v1;
      v2 = v8 - 24;
      v8 -= 24;
    }
    while ( v1 >= 0 );
    v7->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F4B0
// Name: public: CUtlVector<struct ParticleEffectList_t,class CUtlMemory<struct ParticleEffectList_t,int>>::~CUtlVector<struct ParticleEffectList_t,class CUtlMemory<struct ParticleEffectList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>::~CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>(
        CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int> > *this)
{
  bool v2; // sf
  ParticleEffectList_t *m_pMemory; // eax

  CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133080
// Name: public: void CUtlVector<class CParticleSubTextureGroup __near *,class CUtlMemory<class CParticleSubTextureGroup __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleSubTextureGroup *,CUtlMemory<CParticleSubTextureGroup *,int>>::PurgeAndDeleteElements(
        CUtlVector<CParticleSubTextureGroup *,CUtlMemory<CParticleSubTextureGroup *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CParticleSubTextureGroup **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    if ( this->m_Memory.m_pMemory[i] != nullptr )
      C_BaseEntity::operator delete(pMem: this->m_Memory.m_pMemory[i]);
  }
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10133610
// Name: public: int CUtlVector<struct ParticleInfo_t,class CUtlMemory<struct ParticleInfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ParticleInfo_t,CUtlMemory<ParticleInfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ParticleInfo_t,CUtlMemory<ParticleInfo_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ParticleInfo_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  ParticleInfo_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        v11->m_nCount = 0;
        v11->m_nChildCount = 0;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1013E5E0
// Name: public: int CUtlVector<struct touchevent_t,class CUtlMemory<struct touchevent_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<touchevent_t,CUtlMemory<touchevent_t,int>>::AddToTail(
        CUtlVector<touchevent_t,CUtlMemory<touchevent_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  touchevent_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CSnowFallManager::SnowFall_t,int>::Grow(
      (CUtlMemory<vgui::SectionedListPanel::section_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 36 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10142090
// Name: public: int CUtlVector<class CUtlVector<struct CEntityDataInstantiator<struct touchlink_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct touchlink_t>::HashEntry,int>>,class CUtlMemory<class CUtlVector<struct CEntityDataInstantiator<struct touchlink_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101423C0
// Name: public: void CUtlVector<class CUtlVector<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,int>>,class CUtlMemory<class CUtlVector<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101424D0
// Name: public: CUtlVector<class CUtlVector<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>>,class CUtlMemory<class CUtlVector<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<class CUtlVector<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>>,class CUtlMemory<class CUtlVector<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,class CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(
        CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101441D0
// Name: public: int CUtlVector<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,class CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPhysSaveRestoreBlockHandler::QueuedItem_t,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::InsertBefore(
        CUtlVector<CPhysSaveRestoreBlockHandler::QueuedItem_t,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // ecx
  int v6; // eax
  CPhysSaveRestoreBlockHandler::QueuedItem_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 56 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->header.hEntity.m_Index = -1;
    memset(dst: (unsigned __int8 *)v7, value: 0, count: 0x34u);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1014E550
// Name: public: int CUtlVector<struct ModelPoseDebugInfo::InfoText,class CUtlMemory<struct ModelPoseDebugInfo::InfoText,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int>>::InsertMultipleBefore(
        CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  ModelPoseDebugInfo::InfoText *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  unsigned __int8 *v12; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ModelPoseDebugInfo::InfoText,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 1240 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = (unsigned __int8 *)&this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          memset(dst: v12, value: 0, count: 0x4D8u);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10154280
// Name: public: int CUtlVector<struct typedescription_t,class CUtlMemory<struct typedescription_t,int>>::InsertBefore(int,struct typedescription_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<typedescription_t,CUtlMemory<typedescription_t,int>>::InsertBefore(
        CUtlVector<typedescription_t,CUtlMemory<typedescription_t,int> > *this,
        int elem,
        const typedescription_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  typedescription_t *m_pMemory; // ecx
  int v7; // eax
  typedescription_t *v8; // edi
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<typedescription_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 60 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  result = elem;
  if ( v8 != nullptr )
    qmemcpy(v8, src, sizeof(typedescription_t));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10157830
// Name: public: void CUtlVector<struct breakmodel_t,class CUtlMemory<struct breakmodel_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int>>::EnsureCapacity(
        CUtlVector<breakmodel_t,CUtlMemory<breakmodel_t,int> > *this,
        int num)
{
  breakmodel_t *m_pMemory; // edx
  unsigned int v4; // eax
  breakmodel_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 1068 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (breakmodel_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (breakmodel_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158550
// Name: public: void CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(
        CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158770
// Name: public: CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>::~CUtlVector<struct CParticleSystemMgr::RenderCache_t,class CUtlMemory<struct CParticleSystemMgr::RenderCache_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::~CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>(
        CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *this)
{
  bool v2; // sf
  CParticleSystemMgr::RenderCache_t *m_pMemory; // eax

  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168C70
// Name: public: int CUtlVector<struct SaveRestoreBlockHeader_t,class CUtlMemory<struct SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(
        CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SaveRestoreBlockHeader_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<SaveRestoreBlockHeader_t,int>::Grow(
      (CUtlMemory<C_AnimationLayer,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1016F1D0
// Name: public: bool CUtlVector<class C_BaseParticleEntity __near *,class CUtlMemory<class C_BaseParticleEntity __near *,int>>::FindAndRemove(class C_BaseParticleEntity __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101764F0
// Name: public: int CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(
        CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->activityIdx = -1;
          v11->startingIdx = -1;
          v11->count = -1;
          v11->totalWeight = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10176B00
// Name: public: int CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(int,struct CStudioHdr::CActivityToSequenceMapping::HashValueType const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        const Quaternion *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v7; // eax
  Quaternion *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101A29D0
// Name: public: int CUtlVector<struct CViewModelRenderablesList::CEntry,class CUtlMemoryFixedGrowable<struct CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(int,struct CViewModelRenderablesList::CEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(
        CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int> > *this,
        int elem,
        const CViewModelRenderablesList::CEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  CViewModelRenderablesList::CEntry *m_pMemory; // ecx
  int v8; // eax
  CViewModelRenderablesList::CEntry *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<CViewModelRenderablesList::CEntry,int>::ConvertToGrowableMemory(
        this: &this->m_Memory,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101A2A60
// Name: public: int CUtlVector<int,class CUtlMemoryFixedGrowable<int,32,int>>::InsertBefore(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemoryFixedGrowable<int,32,int>>::InsertBefore(
        CUtlVector<int,CUtlMemoryFixedGrowable<int,32,int> > *this,
        int elem,
        int *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<CClientLeafSystem::RenderableInfo_t *,int>::ConvertToGrowableMemory(
        (CUtlMemory<CClientLeafSystem::RenderableInfo_t *,int> *)this,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101AE930
// Name: public: virtual class CUtlVector<int,class CUtlMemory<int,int>> const __near & CAchievementMgrDelegateIAchievementMgr::GetAchievedDuringCurrentGame(int)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<int,CUtlMemory<int,int> > *__thiscall CAchievementMgrDelegateIAchievementMgr::GetAchievedDuringCurrentGame(
        CAchievementMgrDelegateIAchievementMgr *this,
        int nPlayerSlot)
{
  return CAchievementMgr::GetAchievedDuringCurrentGame(this: this->m_pDelegate, nPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101B44B0
// Name: public: int CUtlVector<class WeaponSet,class CUtlMemory<class WeaponSet,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<WeaponSet,CUtlMemory<WeaponSet,int>>::InsertMultipleBefore(
        CUtlVector<WeaponSet,CUtlMemory<WeaponSet,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v7; // ecx
  WeaponSet *m_pMemory; // edx
  int v9; // eax
  int v10; // ebx
  WeaponSet *v11; // esi
  BuyPresetWeapon other; // [esp+8h] [ebp-14h] BYREF

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
      (CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v7 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v9);
    v7 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v10 = v7;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          BuyPresetWeapon::BuyPresetWeapon(this: &this->m_Memory.m_pMemory[v10].m_primaryWeapon);
          BuyPresetWeapon::BuyPresetWeapon(this: &v11->m_secondaryWeapon);
          BuyPresetWeapon::BuyPresetWeapon(this: &other);
          BuyPresetWeapon::operator=(this: &v11->m_primaryWeapon, &other);
          BuyPresetWeapon::operator=(this: &v11->m_secondaryWeapon, &other);
          v7 = elem;
          v11->m_armor = 0;
          *(_WORD *)&v11->m_helmet = 0;
          v11->m_HEGrenade = false;
          v11->m_flashbangs = 0;
          *(_WORD *)&v11->m_defuser = 0;
        }
        ++v10;
        --num;
      }
      while ( num != 0 );
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101B45B0
// Name: public: int CUtlVector<class WeaponSet,class CUtlMemory<class WeaponSet,int>>::InsertBefore(int,class WeaponSet const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<WeaponSet,CUtlMemory<WeaponSet,int>>::InsertBefore(
        CUtlVector<WeaponSet,CUtlMemory<WeaponSet,int> > *this,
        int elem,
        const WeaponSet *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  WeaponSet *m_pMemory; // ecx
  int v7; // eax
  WeaponSet *v8; // edi
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
      (CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 56 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  result = elem;
  if ( v8 != nullptr )
    qmemcpy(v8, src, sizeof(WeaponSet));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B4640
// Name: public: int CUtlVector<struct vrect_t,class CUtlMemory<struct vrect_t,int>>::InsertBefore(int,struct vrect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vrect_t,CUtlMemory<vrect_t,int>>::InsertBefore(
        CUtlVector<CHudMenu::ProcessedLine,CUtlMemory<CHudMenu::ProcessedLine,int> > *this,
        int elem,
        const CHudMenu::ProcessedLine *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CHudMenu::ProcessedLine *m_pMemory; // ecx
  int v7; // eax
  CHudMenu::ProcessedLine *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101B6220
// Name: public: void CUtlVector<class BuyPreset,class CUtlMemory<class BuyPreset,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::RemoveAll(
        CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int> > *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      BuyPreset::~BuyPreset(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B6250
// Name: public: int CUtlVector<class BuyPreset,class CUtlMemory<class BuyPreset,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::InsertMultipleBefore(
        CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  BuyPreset *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  BuyPreset *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<BuyPreset,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 148 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          BuyPreset::BuyPreset(this: v12);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101B62F0
// Name: public: int CUtlVector<class BuyPreset,class CUtlMemory<class BuyPreset,int>>::InsertBefore(int,class BuyPreset const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::InsertBefore(
        CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int> > *this,
        int elem,
        const BuyPreset *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BuyPreset *m_pMemory; // ecx
  int v7; // eax
  BuyPreset *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<BuyPreset,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 148 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    BuyPreset::BuyPreset(this: v8, other: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101B6370
// Name: public: class CUtlVector<class BuyPreset,class CUtlMemory<class BuyPreset,int>> __near & CUtlVector<class BuyPreset,class CUtlMemory<class BuyPreset,int>>::operator=(class CUtlVector<class BuyPreset,class CUtlMemory<class BuyPreset,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int> > *__thiscall CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::operator=(
        CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int> > *this,
        const CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int> > *other)
{
  int v3; // esi
  int v4; // ebx
  int v5; // esi
  int v6; // ebx
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = this->m_Size - 1;
  nCount = other->m_Size;
  if ( v3 >= 0 )
  {
    v4 = v3;
    do
    {
      BuyPreset::~BuyPreset(this: &this->m_Memory.m_pMemory[v4--]);
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = 0;
  this->m_Size = 0;
  CUtlVector<BuyPreset,CUtlMemory<BuyPreset,int>>::InsertMultipleBefore(this, elem: 0, num: nCount);
  v6 = nCount;
  if ( nCount > 0 )
  {
    do
    {
      BuyPreset::operator=(this: &this->m_Memory.m_pMemory[v5], __that: &other->m_Memory.m_pMemory[v5]);
      ++v5;
      --v6;
    }
    while ( v6 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BBE10
// Name: public: int CUtlVector<class RoundStartSoundPlaybackData,class CUtlMemory<class RoundStartSoundPlaybackData,int>>::InsertBefore(int,class RoundStartSoundPlaybackData const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<RoundStartSoundPlaybackData,CUtlMemory<RoundStartSoundPlaybackData,int>>::InsertBefore(
        CUtlVector<RoundStartSoundPlaybackData,CUtlMemory<RoundStartSoundPlaybackData,int> > *this,
        int elem,
        const RoundStartSoundPlaybackData *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  RoundStartSoundPlaybackData *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ParticleControlPoint_t,int>::Grow(
      (CUtlMemory<CSceneEventInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 76 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CCD50
// Name: public: virtual class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> const __near * GameTypes::GetWeaponProgressionForCurrentModeCT(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *__thiscall GameTypes::GetWeaponProgressionForCurrentModeCT(
        GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return &v6->m_WeaponProgressionCT;
}

//------------------------------------------------------------------------------
// Address: 0x101CCDF0
// Name: public: virtual class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> const __near * GameTypes::GetWeaponProgressionForCurrentModeT(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *__thiscall GameTypes::GetWeaponProgressionForCurrentModeT(
        GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return &v6->m_WeaponProgressionT;
}

//------------------------------------------------------------------------------
// Address: 0x101CD360
// Name: public: void CUtlVector<struct vgui::CFooterPanel::ButtonLabel_t __near *,class CUtlMemory<struct vgui::CFooterPanel::ButtonLabel_t __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int>>::PurgeAndDeleteElements(
        CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  vgui::CFooterPanel::ButtonLabel_t **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    C_BaseEntity::operator delete(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD3D0
// Name: public: void CUtlVector<struct GameTypes::FreestyleBotDifficulty __near *,class CUtlMemory<struct GameTypes::FreestyleBotDifficulty __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int> > *this)
{
  int i; // ebx
  GameTypes::FreestyleBotDifficulty *v3; // edi
  KeyValues *m_pConvars; // ecx
  bool v5; // sf
  GameTypes::FreestyleBotDifficulty **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      m_pConvars = v3->m_pConvars;
      if ( m_pConvars != nullptr )
        KeyValues::deleteThis(this: m_pConvars);
      C_BaseEntity::operator delete(pMem: v3);
    }
  }
  v5 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v5 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD6A0
// Name: public: void CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(
        CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  IGameTypes::WeaponProgression *v3; // esi
  CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD860
// Name: public: void CUtlVector<struct GameTypes::Map __near *,class CUtlMemory<struct GameTypes::Map __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int> > *this)
{
  int v2; // eax
  GameTypes::Map *v3; // esi
  char **m_pMemory; // eax
  char **v5; // eax
  GameTypes::Map **v6; // ecx
  int i; // [esp+8h] [ebp-8h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int> > *)&v3->m_CTModels);
      v3->m_CTModels.m_Size = 0;
      if ( v3->m_CTModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_CTModels.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_CTModels.m_Memory.m_pMemory);
          v3->m_CTModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_CTModels.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_CTModels.m_Memory.m_pMemory;
      v3->m_CTModels.m_pElements = m_pMemory;
      if ( v3->m_CTModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_CTModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_CTModels.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int> > *)&v3->m_TModels);
      v3->m_TModels.m_Size = 0;
      if ( v3->m_TModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_TModels.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_TModels.m_Memory.m_pMemory);
          v3->m_TModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TModels.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->m_TModels.m_Memory.m_pMemory;
      v3->m_TModels.m_pElements = v5;
      if ( v3->m_TModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          v3->m_TModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TModels.m_Memory.m_nAllocationCount = 0;
      }
      C_BaseEntity::operator delete(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v6 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDDB0
// Name: public: void CUtlVector<struct GameTypes::GameMode __near *,class CUtlMemory<struct GameTypes::GameMode __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int> > *this)
{
  CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int> > *v1; // esi
  int v2; // eax
  GameTypes::GameMode *v3; // ebx
  KeyValues *m_pConvarsSP; // ecx
  KeyValues *m_pConvarsMP; // ecx
  IGameTypes::WeaponProgression *m_pMemory; // eax
  IGameTypes::WeaponProgression *v7; // eax
  char **v8; // eax
  GameTypes::GameMode **v9; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; v2 < v1->m_Size; i = v2 )
  {
    v3 = v1->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      m_pConvarsSP = v3->m_pConvarsSP;
      if ( m_pConvarsSP != nullptr )
        KeyValues::deleteThis(this: m_pConvarsSP);
      m_pConvarsMP = v3->m_pConvarsMP;
      if ( m_pConvarsMP != nullptr )
        KeyValues::deleteThis(this: m_pConvarsMP);
      CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(this: &v3->m_WeaponProgressionT);
      if ( v3->m_WeaponProgressionT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_WeaponProgressionT.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_WeaponProgressionT.m_Memory.m_pMemory);
          v3->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_WeaponProgressionT.m_Memory.m_pMemory;
      v3->m_WeaponProgressionT.m_pElements = m_pMemory;
      if ( v3->m_WeaponProgressionT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(this: &v3->m_WeaponProgressionCT);
      if ( v3->m_WeaponProgressionCT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_WeaponProgressionCT.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_WeaponProgressionCT.m_Memory.m_pMemory);
          v3->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
      }
      v7 = v3->m_WeaponProgressionCT.m_Memory.m_pMemory;
      v3->m_WeaponProgressionCT.m_pElements = v7;
      if ( v3->m_WeaponProgressionCT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v7 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
          v3->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<vgui::CFooterPanel::ButtonLabel_t *,CUtlMemory<vgui::CFooterPanel::ButtonLabel_t *,int> > *)&v3->m_Maps);
      v3->m_Maps.m_Size = 0;
      if ( v3->m_Maps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Maps.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Maps.m_Memory.m_pMemory);
          v3->m_Maps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Maps.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v3->m_Maps.m_Memory.m_pMemory;
      v3->m_Maps.m_pElements = v8;
      if ( v3->m_Maps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v8 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
          v3->m_Maps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Maps.m_Memory.m_nAllocationCount = 0;
      }
      C_BaseEntity::operator delete(pMem: v3);
      v1 = this;
      v2 = i;
    }
    ++v2;
  }
  v1->m_Size = 0;
  if ( v1->m_Memory.m_nGrowSize < 0 )
  {
    v1->m_pElements = v1->m_Memory.m_pMemory;
  }
  else
  {
    if ( v1->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Memory.m_pMemory);
      v1->m_Memory.m_pMemory = nullptr;
    }
    v9 = v1->m_Memory.m_pMemory;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_pElements = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDF80
// Name: public: void CUtlVector<struct GameTypes::GameType __near *,class CUtlMemory<struct GameTypes::GameType __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int> > *this)
{
  int v2; // eax
  GameTypes::GameType *v3; // esi
  GameTypes::GameMode **m_pMemory; // eax
  GameTypes::GameType **v5; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int>>::PurgeAndDeleteElements(this: &v3->m_GameModes);
      v3->m_GameModes.m_Size = 0;
      if ( v3->m_GameModes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_GameModes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_GameModes.m_Memory.m_pMemory);
          v3->m_GameModes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_GameModes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_GameModes.m_Memory.m_pMemory;
      v3->m_GameModes.m_pElements = m_pMemory;
      if ( v3->m_GameModes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_GameModes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_GameModes.m_Memory.m_nAllocationCount = 0;
      }
      C_BaseEntity::operator delete(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D0BA0
// Name: public: int CUtlVector<struct SaveGameDescription_t,class CUtlMemory<struct SaveGameDescription_t,int>>::InsertBefore(int,struct SaveGameDescription_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SaveGameDescription_t,CUtlMemory<SaveGameDescription_t,int>>::InsertBefore(
        CUtlVector<SaveGameDescription_t,CUtlMemory<SaveGameDescription_t,int> > *this,
        int elem,
        const SaveGameDescription_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SaveGameDescription_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SaveGameDescription_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 440 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F00B0
// Name: public: int CUtlVector<struct CommentaryItem_t,class CUtlMemory<struct CommentaryItem_t,int>>::InsertBefore(int,struct CommentaryItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CommentaryItem_t,CUtlMemory<CommentaryItem_t,int>>::InsertBefore(
        CUtlVector<CommentaryItem_t,CUtlMemory<CommentaryItem_t,int> > *this,
        int elem,
        const CommentaryItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CommentaryItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CommentaryItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 836 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FD530
// Name: public: int CUtlVector<struct BonusMapDescription_t,class CUtlMemory<struct BonusMapDescription_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BonusMapDescription_t,CUtlMemory<BonusMapDescription_t,int>>::InsertBefore(
        CUtlVector<BonusMapDescription_t,CUtlMemory<BonusMapDescription_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BonusMapDescription_t *m_pMemory; // ecx
  int v6; // eax
  BonusMapDescription_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<BonusMapDescription_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 904 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_WORD *)&v7->bIsFolder = 0;
    v7->szFileName[0] = 0;
    v7->szMapFileName[0] = 0;
    v7->szChapterName[0] = 0;
    v7->szImageName[0] = 0;
    v7->szMapName[0] = 0;
    v7->szComment[0] = 0;
    *(_WORD *)&v7->bLocked = 0;
    v7->m_pChallenges = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10200C50
// Name: public: void CUtlVector<class CGameSavePanel __near *,class CUtlMemory<class CGameSavePanel __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CGameSavePanel *,CUtlMemory<CGameSavePanel *,int>>::PurgeAndDeleteElements(
        CUtlVector<CGameSavePanel *,CUtlMemory<CGameSavePanel *,int> > *this)
{
  int i; // edi
  CGameSavePanel *v3; // ecx
  bool v4; // sf
  CGameSavePanel **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CGameSavePanel *, int))v3->dtr_Panel)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208FA0
// Name: public: void CUtlVector<struct CControlsScaleform::Option_t __near *,class CUtlMemory<struct CControlsScaleform::Option_t __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CControlsScaleform::Option_t *,CUtlMemory<CControlsScaleform::Option_t *,int>>::PurgeAndDeleteElements(
        CUtlVector<CControlsScaleform::Option_t *,CUtlMemory<CControlsScaleform::Option_t *,int> > *this)
{
  int i; // edi
  CControlsScaleform::Option_t *v3; // ecx
  bool v4; // sf
  CControlsScaleform::Option_t **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CControlsScaleform::Option_t *, int))v3->dtr_Option_t)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102099C0
// Name: public: int CUtlVector<struct CControlsScaleform::OptionChoiceData_t,class CUtlMemory<struct CControlsScaleform::OptionChoiceData_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CControlsScaleform::OptionChoiceData_t,CUtlMemory<CControlsScaleform::OptionChoiceData_t,int>>::AddToTail(
        CUtlVector<CControlsScaleform::OptionChoiceData_t,CUtlMemory<CControlsScaleform::OptionChoiceData_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CControlsScaleform::OptionChoiceData_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CControlsScaleform::OptionChoiceData_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v5 << 7);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1020D670
// Name: public: void CUtlVector<class CBaseAchievement __near *,class CUtlMemory<class CBaseAchievement __near *,int>>::Sort(int (*)(class CBaseAchievement __near * const __near *,class CBaseAchievement __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::Sort(
        CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  vgui::CConsolePanel::CompletionItem *v6; // ecx
  vgui::CConsolePanel::CompletionItem **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102115F0
// Name: public: void CUtlVector<class ScoreboardEntry,class CUtlMemory<class ScoreboardEntry,int>>::Sort(int (*)(class ScoreboardEntry const __near *,class ScoreboardEntry const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int>>::Sort(
        CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int> > *v2; // esi
  signed int m_Size; // eax
  ScoreboardEntry *m_pMemory; // ecx
  int v5; // edi
  int v6; // ebx
  ScoreboardEntry *v7; // eax
  _BYTE v8[1448]; // [esp+4h] [ebp-5B4h] BYREF
  CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int> > *v9; // [esp+5ACh] [ebp-Ch]
  int j; // [esp+5B0h] [ebp-8h]
  int i; // [esp+5B4h] [ebp-4h]

  v2 = this;
  m_Size = this->m_Size;
  v9 = this;
  if ( m_Size > 1 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( v2->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0x5A8u, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      i = m_Size - 1;
      do
      {
        if ( v5 >= 1 )
        {
          v6 = 1;
          for ( j = v5; j != 0; --j )
          {
            if ( pfnCompare(a1: &v2->m_Memory.m_pMemory[v6 - 1], a2: &v2->m_Memory.m_pMemory[v6]) < 0 )
            {
              v7 = &v2->m_Memory.m_pMemory[v6];
              qmemcpy(v8, &v7[-1], sizeof(v8));
              qmemcpy(&v7[-1], v7, sizeof(ScoreboardEntry));
              qmemcpy(v7, v8, sizeof(ScoreboardEntry));
              v2 = v9;
              v5 = i;
            }
            ++v6;
          }
        }
        i = --v5;
      }
      while ( v5 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102116B0
// Name: public: int CUtlVector<class ScoreboardEntry,class CUtlMemory<class ScoreboardEntry,int>>::InsertBefore(int,class ScoreboardEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int>>::InsertBefore(
        CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int> > *this,
        int elem,
        const ScoreboardEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ScoreboardEntry *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ScoreboardEntry,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 1448 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10224290
// Name: public: int CUtlVector<struct SFHudVoiceStatus::NoticeText_t,class CUtlMemory<struct SFHudVoiceStatus::NoticeText_t,int>>::InsertBefore(int,struct SFHudVoiceStatus::NoticeText_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SFHudVoiceStatus::NoticeText_t,CUtlMemory<SFHudVoiceStatus::NoticeText_t,int>>::InsertBefore(
        CUtlVector<SFHudVoiceStatus::NoticeText_t,CUtlMemory<SFHudVoiceStatus::NoticeText_t,int> > *this,
        int elem,
        const SFHudVoiceStatus::NoticeText_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SFHudVoiceStatus::NoticeText_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SFHudVoiceStatus::NoticeText_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2080 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10236A60
// Name: public: void CUtlVector<struct BMPResAnimData_t,class CUtlMemory<struct BMPResAnimData_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>::RemoveAll(
        CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int> > *this)
{
  int v1; // edi
  int v2; // eax
  char *v3; // esi
  _BYTE *v4; // eax
  _BYTE *v5; // eax
  KeyValues *v6; // ecx
  CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int> > *v7; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v7 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v8 = 20 * v1;
    while ( 1 )
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      if ( *(_DWORD *)v3 != 0 && **(_BYTE **)v3 != 0 )
      {
        C_BaseEntity::operator delete(pMem: *(void **)v3);
        *(_DWORD *)v3 = 0;
      }
      v4 = *((_BYTE **)v3 + 1);
      if ( v4 != nullptr && *v4 != 0 )
      {
        C_BaseEntity::operator delete(pMem: *((void **)v3 + 1));
        *((_DWORD *)v3 + 1) = 0;
      }
      v5 = *((_BYTE **)v3 + 2);
      if ( v5 != nullptr && *v5 != 0 )
      {
        C_BaseEntity::operator delete(pMem: *((void **)v3 + 2));
        *((_DWORD *)v3 + 2) = 0;
      }
      v6 = *((KeyValues **)v3 + 3);
      if ( v6 != nullptr )
      {
        KeyValues::deleteThis(this: v6);
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 = v8 - 20;
      v8 -= 20;
      if ( v1 < 0 )
        break;
      this = v7;
    }
    v7->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236B10
// Name: public: void CUtlVector<struct BMPResAttachData_t,class CUtlMemory<struct BMPResAttachData_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int>>::RemoveAll(
        CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int> > *this)
{
  int i; // edi
  BMPResAttachData_t *v3; // esi

  for ( i = this->m_Size - 1; i >= 0; --i )
  {
    v3 = &this->m_Memory.m_pMemory[i];
    if ( v3->m_pszModelName != nullptr && *v3->m_pszModelName != 0 )
    {
      C_BaseEntity::operator delete(pMem: (void *)v3->m_pszModelName);
      v3->m_pszModelName = nullptr;
    }
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10236B50
// Name: public: int CUtlVector<struct BMPResAnimData_t,class CUtlMemory<struct BMPResAnimData_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>::InsertBefore(
        CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BMPResAnimData_t *m_pMemory; // ecx
  int v6; // eax
  BMPResAnimData_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_pszName = nullptr;
    v7->m_pszSequence = nullptr;
    v7->m_pszActivity = nullptr;
    v7->m_pPoseParameters = nullptr;
    v7->m_bDefault = false;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10236BD0
// Name: public: CUtlVector<struct BMPResAnimData_t,class CUtlMemory<struct BMPResAnimData_t,int>>::~CUtlVector<struct BMPResAnimData_t,class CUtlMemory<struct BMPResAnimData_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>::~CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>(
        CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int> > *this)
{
  bool v2; // sf
  BMPResAnimData_t *m_pMemory; // eax

  CUtlVector<BMPResAnimData_t,CUtlMemory<BMPResAnimData_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10236C30
// Name: public: CUtlVector<struct BMPResAttachData_t,class CUtlMemory<struct BMPResAttachData_t,int>>::~CUtlVector<struct BMPResAttachData_t,class CUtlMemory<struct BMPResAttachData_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int>>::~CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int>>(
        CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int> > *this)
{
  bool v2; // sf
  BMPResAttachData_t *m_pMemory; // eax

  CUtlVector<BMPResAttachData_t,CUtlMemory<BMPResAttachData_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102438B0
// Name: public: void CUtlVector<class RayTracingEnvironment __near *,class CUtlMemory<class RayTracingEnvironment __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::PurgeAndDeleteElements(
        CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *this)
{
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int> > *v1; // ebx
  int v2; // eax
  unsigned int v3; // esi
  int *v4; // eax
  Vector *v5; // eax
  LightDesc_t *v6; // eax
  int *v7; // eax
  int j; // ebx
  int k; // ebx
  CacheOptimizedKDNode *v10; // eax
  RayTracingEnvironment **m_pMemory; // ecx
  int i; // [esp+8h] [ebp-8h]

  v1 = this;
  v2 = 0;
  for ( i = 0; v2 < v1->m_Size; i = v2 )
  {
    v3 = (unsigned int)v1->m_Memory.m_pMemory[v2];
    if ( v3 != 0 )
    {
      *(_DWORD *)(v3 + 192) = 0;
      if ( *(int *)(v3 + 188) >= 0 )
      {
        if ( *(_DWORD *)(v3 + 180) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 180));
          *(_DWORD *)(v3 + 180) = 0;
        }
        *(_DWORD *)(v3 + 184) = 0;
      }
      v4 = *(int **)(v3 + 180);
      *(_DWORD *)(v3 + 196) = v4;
      if ( *(int *)(v3 + 188) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *(_DWORD *)(v3 + 180) = 0;
        }
        *(_DWORD *)(v3 + 184) = 0;
      }
      *(_DWORD *)(v3 + 172) = 0;
      if ( *(int *)(v3 + 168) >= 0 )
      {
        if ( *(_DWORD *)(v3 + 160) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 160));
          *(_DWORD *)(v3 + 160) = 0;
        }
        *(_DWORD *)(v3 + 164) = 0;
      }
      v5 = *(Vector **)(v3 + 160);
      *(_DWORD *)(v3 + 176) = v5;
      if ( *(int *)(v3 + 168) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v5);
          *(_DWORD *)(v3 + 160) = 0;
        }
        *(_DWORD *)(v3 + 164) = 0;
      }
      *(_DWORD *)(v3 + 152) = 0;
      if ( *(int *)(v3 + 148) >= 0 )
      {
        if ( *(_DWORD *)(v3 + 140) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 140));
          *(_DWORD *)(v3 + 140) = 0;
        }
        *(_DWORD *)(v3 + 144) = 0;
      }
      v6 = *(LightDesc_t **)(v3 + 140);
      *(_DWORD *)(v3 + 156) = v6;
      if ( *(int *)(v3 + 148) >= 0 )
      {
        if ( v6 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
          *(_DWORD *)(v3 + 140) = 0;
        }
        *(_DWORD *)(v3 + 144) = 0;
      }
      *(_DWORD *)(v3 + 132) = 0;
      if ( *(int *)(v3 + 128) >= 0 )
      {
        if ( *(_DWORD *)(v3 + 120) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 120));
          *(_DWORD *)(v3 + 120) = 0;
        }
        *(_DWORD *)(v3 + 124) = 0;
      }
      v7 = *(int **)(v3 + 120);
      *(_DWORD *)(v3 + 136) = v7;
      if ( *(int *)(v3 + 128) >= 0 )
      {
        if ( v7 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
          *(_DWORD *)(v3 + 120) = 0;
        }
        *(_DWORD *)(v3 + 124) = 0;
      }
      *(_DWORD *)(v3 + 112) = 0;
      if ( *(_DWORD *)(v3 + 100) != 0 )
      {
        for ( j = 0; j < *(_DWORD *)(v3 + 104); ++j )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(*(_DWORD *)(v3 + 100) + 4 * j));
        *(_DWORD *)(v3 + 104) = 0;
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 100));
        v1 = this;
        *(_DWORD *)(v3 + 100) = 0;
      }
      *(_DWORD *)(v3 + 116) = 0;
      if ( *(_DWORD *)(v3 + 100) != 0 )
      {
        for ( k = 0; k < *(_DWORD *)(v3 + 104); ++k )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(*(_DWORD *)(v3 + 100) + 4 * k));
        *(_DWORD *)(v3 + 104) = 0;
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 100));
        v1 = this;
        *(_DWORD *)(v3 + 100) = 0;
      }
      *(_DWORD *)(v3 + 92) = 0;
      if ( *(int *)(v3 + 88) >= 0 )
      {
        if ( *(_DWORD *)(v3 + 80) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 80));
          *(_DWORD *)(v3 + 80) = 0;
        }
        *(_DWORD *)(v3 + 84) = 0;
      }
      v10 = *(CacheOptimizedKDNode **)(v3 + 80);
      *(_DWORD *)(v3 + 96) = v10;
      if ( *(int *)(v3 + 88) >= 0 )
      {
        if ( v10 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
          *(_DWORD *)(v3 + 80) = 0;
        }
        *(_DWORD *)(v3 + 84) = 0;
      }
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((v3 & 0xFFFFFFFC) - 4));
      v2 = i;
    }
    ++v2;
  }
  v1->m_Size = 0;
  if ( v1->m_Memory.m_nGrowSize < 0 )
  {
    v1->m_pElements = v1->m_Memory.m_pMemory;
  }
  else
  {
    if ( v1->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Memory.m_pMemory);
      v1->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = v1->m_Memory.m_pMemory;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102585A0
// Name: public: CClientEffectRegistration::CClientEffectRegistration(char const __near *,void (*)(class CEffectData const __near &))
// Source: json
//------------------------------------------------------------------------------
CClientEffectRegistration *__thiscall CClientEffectRegistration::CClientEffectRegistration(
        CClientEffectRegistration *this,
        const char *pEffectName,
        void (__cdecl *fn)(const CEffectData *))
{
  this->m_pEffectName = pEffectName;
  this->m_pFunction = fn;
  this->m_pNext = CClientEffectRegistration::s_pHead;
  CClientEffectRegistration::s_pHead = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102585D0
// Name: RecordEffect
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordEffect(const CEffectData *data@<edi>, const char *pEffectName)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  const char *value; // ebx
  void *v5; // eax
  char pName[1024]; // [esp+10h] [ebp-400h] BYREF

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) && data->m_fFlags >= 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "TempEntity");
    else
      v3 = nullptr;
    value = (const char *)((int (__stdcall *)(_DWORD))physprops->GetPropName)(a1: data->m_nSurfaceProp);
    V_snprintf(pDest: pName, maxLen: 0x400u, pFormat: "TE_DispatchEffect %s %s", pEffectName, value);
    KeyValues::SetInt(this: v3, keyName: "te", value: 2);
    KeyValues::SetString(this: v3, keyName: "name", value: pName);
    KeyValues::SetFloat(this: v3, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v3, keyName: "originx", value: data->m_vOrigin.x);
    KeyValues::SetFloat(this: v3, keyName: "originy", value: data->m_vOrigin.y);
    KeyValues::SetFloat(this: v3, keyName: "originz", value: data->m_vOrigin.z);
    KeyValues::SetFloat(this: v3, keyName: "startx", value: data->m_vStart.x);
    KeyValues::SetFloat(this: v3, keyName: "starty", value: data->m_vStart.y);
    KeyValues::SetFloat(this: v3, keyName: "startz", value: data->m_vStart.z);
    KeyValues::SetFloat(this: v3, keyName: "normalx", value: data->m_vNormal.x);
    KeyValues::SetFloat(this: v3, keyName: "normaly", value: data->m_vNormal.y);
    KeyValues::SetFloat(this: v3, keyName: "normalz", value: data->m_vNormal.z);
    KeyValues::SetFloat(this: v3, keyName: "anglesx", value: data->m_vAngles.x);
    KeyValues::SetFloat(this: v3, keyName: "anglesy", value: data->m_vAngles.y);
    KeyValues::SetFloat(this: v3, keyName: "anglesz", value: data->m_vAngles.z);
    KeyValues::SetInt(this: v3, keyName: "flags", value: data->m_fFlags);
    KeyValues::SetFloat(this: v3, keyName: "scale", value: data->m_flScale);
    KeyValues::SetFloat(this: v3, keyName: "magnitude", value: data->m_flMagnitude);
    KeyValues::SetFloat(this: v3, keyName: "radius", value: data->m_flRadius);
    KeyValues::SetString(this: v3, keyName: "surfaceprop", value);
    KeyValues::SetInt(this: v3, keyName: "color", value: data->m_nColor);
    KeyValues::SetInt(this: v3, keyName: "damagetype", value: data->m_nDamageType);
    KeyValues::SetInt(this: v3, keyName: "hitbox", value: data->m_nHitBox);
    KeyValues::SetString(this: v3, keyName: "effectname", value: pEffectName);
    KeyValues::SetInt(this: v3, keyName: "attachmentindex", value: data->m_nAttachmentIndex);
    v5 = (void *)CEffectData::entindex(this: data);
    KeyValues::SetPtr(this: v3, keyName: "entindex", value: v5);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v3);
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258890
// Name: public: virtual class ClientClass __near * C_TEEffectDispatch::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEEffectDispatch::GetClientClass(C_TEEffectDispatch *this)
{
  return &__g_C_TEEffectDispatchClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10258940
// Name: public: virtual void ErrorPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ErrorPrecache::CResourcePrecacher::Cache(
        ErrorPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "error",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102589A0
// Name: void ErrorEffectCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ErrorEffectCallback(const CEffectData *data)
{
  CNewParticleEffect *v1; // eax
  CNewParticleEffect *v2; // esi
  Vector vecForward; // [esp+4h] [ebp-24h] BYREF
  Vector vecRight; // [esp+10h] [ebp-18h] BYREF
  Vector vecUp; // [esp+1Ch] [ebp-Ch] BYREF

  v1 = (CNewParticleEffect *)CParticleOperatorInstance::operator new(nSize: 0x530u);
  if ( v1 != nullptr )
    v2 = CNewParticleEffect::CNewParticleEffect(this: v1, pOwner: nullptr, pEffectName: "error");
  else
    v2 = nullptr;
  *((_BYTE *)v2 + 944) |= 0x40u;
  v2->m_pDebugName = nullptr;
  CNewParticleEffect::AddRef(this: v2);
  if ( v2->m_pDef.m_pObject != nullptr )
  {
    v2->m_vSortOrigin = data->m_vOrigin;
    CNewParticleEffect::SetControlPoint(this: v2, nWhichPoint: 0, v: &data->m_vOrigin);
    CNewParticleEffect::SetControlPoint(this: v2, nWhichPoint: 1, v: &data->m_vStart);
    AngleVectors(angles: &data->m_vAngles, forward: &vecForward, right: &vecRight, up: &vecUp);
    CNewParticleEffect::SetControlPointOrientation(
      this: v2,
      nWhichPoint: 0,
      forward: &vecForward,
      right: &vecRight,
      up: &vecUp);
  }
  CNewParticleEffect::Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10258A60
// Name: void DispatchEffectToCallback(char const __near *,class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchEffectToCallback(const char *pEffectName, const CEffectData *m_EffectData)
{
  CClientEffectRegistration *i; // esi
  int m_Id; // edi
  int v4; // esi
  CUtlSymbol result; // [esp+Eh] [ebp-6h] BYREF
  CUtlSymbol v6; // [esp+10h] [ebp-4h] BYREF

  if ( (_S5_216 & 1) == 0 )
  {
    _S5_216 |= 1u;
    map.m_Vector.m_Memory.m_pMemory = nullptr;
    map.m_Vector.m_Memory.m_nAllocationCount = 0;
    map.m_Vector.m_Memory.m_nGrowSize = 32;
    map.m_Vector.m_Size = 0;
    map.m_Vector.m_pElements = nullptr;
    CUtlSymbolTable::CUtlSymbolTable(this: &map.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
    atexit(func: DispatchEffectToCallback_::_2_::_dynamic_atexit_destructor_for__map__);
  }
  if ( !bInitializedMap )
  {
    for ( i = CClientEffectRegistration::s_pHead; i != nullptr; i = i->m_pNext )
    {
      if ( CUtlSymbolTable::Find(this: &map.m_SymbolTable, &result, pString: i->m_pEffectName)->m_Id == 0xFFFF )
      {
        CUtlSymbolTable::AddString(this: &map.m_SymbolTable, result: &v6, pString: i->m_pEffectName);
        m_Id = v6.m_Id;
        if ( map.m_Vector.m_Size <= v6.m_Id && map.m_Vector.m_Size < v6.m_Id + 1 )
          CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
            this: (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)&map,
            elem: map.m_Vector.m_Size,
            num: v6.m_Id + 1 - map.m_Vector.m_Size);
        map.m_Vector.m_Memory.m_pMemory[m_Id] = i;
      }
      else
      {
        _Warning(a1: "Encountered multiple different effects with the same name \"%s\"!\n", i->m_pEffectName);
      }
    }
    bInitializedMap = true;
  }
  v4 = CUtlSymbolTable::Find(this: &map.m_SymbolTable, &result, pString: pEffectName)->m_Id;
  if ( (_WORD)v4 == 0xFFFF )
  {
    _Warning(a1: "DispatchEffect: effect \"%s\" not found on client\n", pEffectName);
  }
  else
  {
    g_pPrecacheSystem->LimitResourceAccess(this: g_pPrecacheSystem, a2: DISPATCH_EFFECT, a3: pEffectName);
    map.m_Vector.m_Memory.m_pMemory[v4]->m_pFunction(a1: m_EffectData);
    g_pPrecacheSystem->EndLimitedResourceAccess(this: g_pPrecacheSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258BC0
// Name: public: virtual void C_TEEffectDispatch::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEEffectDispatch::PostDataUpdate(C_TEEffectDispatch *this, DataUpdateType_t updateType)
{
  const char *v3; // eax
  const char *v4; // esi
  C_BaseTempEntity **p_m_pNextDynamic; // edi

  v3 = g_StringTableEffectDispatch->GetString(
         this: g_StringTableEffectDispatch,
         a2: *(_DWORD *)&this->m_EffectData.m_nColor);
  v4 = v3;
  if ( v3 != nullptr )
  {
    p_m_pNextDynamic = &this->m_pNextDynamic;
    DispatchEffectToCallback(pEffectName: v3, m_EffectData: (const CEffectData *)p_m_pNextDynamic);
    RecordEffect(data: (const CEffectData *)p_m_pNextDynamic, pEffectName: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258C00
// Name: void DispatchEffect(class IRecipientFilter __near &,float,char const __near *,class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchEffect(IRecipientFilter *filter, float delay, const char *pName, const CEffectData *data)
{
  if ( !te->SuppressTE(this: te, a2: filter) )
  {
    DispatchEffectToCallback(pEffectName: pName, m_EffectData: data);
    RecordEffect(pEffectName: pName, data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10258C40
// Name: void DispatchEffect(char const __near *,class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchEffect(const char *pName, const CEffectData *data)
{
  CPASFilter filter; // [esp+4h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: &data->m_vOrigin);
  if ( !te->SuppressTE(this: te, a2: &filter) )
  {
    DispatchEffectToCallback(pEffectName: pName, m_EffectData: data);
    RecordEffect(pEffectName: pName, data);
  }
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10258CA0
// Name: void DispatchEffect(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DispatchEffect(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IRecipientFilter *filter,
        float delay,
        KeyValues *pKeyValues)
{
  const char *String; // eax
  int v7; // ecx
  const char *v8; // esi
  CEffectData data; // [esp+10h] [ebp-68h] BYREF
  int v10; // [esp+74h] [ebp-4h]

  data.m_hEntity.m_Index = -1;
  data.m_nAttachmentIndex = 0;
  data.m_nSurfaceProp = 0;
  memset(&data.m_nMaterial, 0, 17);
  data.m_vOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  data.m_vOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  data.m_vOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  data.m_vStart.x = KeyValues::GetFloat(this: pKeyValues, keyName: "startx", defaultValue: 0.0);
  data.m_vStart.y = KeyValues::GetFloat(this: pKeyValues, keyName: "starty", defaultValue: 0.0);
  data.m_vStart.z = KeyValues::GetFloat(this: pKeyValues, keyName: "startz", defaultValue: 0.0);
  data.m_vNormal.x = KeyValues::GetFloat(this: pKeyValues, keyName: "normalx", defaultValue: 0.0);
  data.m_vNormal.y = KeyValues::GetFloat(this: pKeyValues, keyName: "normaly", defaultValue: 0.0);
  data.m_vNormal.z = KeyValues::GetFloat(this: pKeyValues, keyName: "normalz", defaultValue: 0.0);
  data.m_vAngles.x = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesx", defaultValue: 0.0);
  data.m_vAngles.y = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesy", defaultValue: 0.0);
  data.m_vAngles.z = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesz", defaultValue: 0.0);
  data.m_fFlags = KeyValues::GetInt(this: pKeyValues, keyName: "flags", defaultValue: 0);
  data.m_flScale = KeyValues::GetFloat(this: pKeyValues, keyName: "scale", defaultValue: 0.0);
  data.m_flMagnitude = KeyValues::GetFloat(this: pKeyValues, keyName: "magnitude", defaultValue: 0.0);
  data.m_flRadius = KeyValues::GetFloat(this: pKeyValues, keyName: "radius", defaultValue: 0.0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "surfaceprop", defaultValue: prType);
  data.m_nSurfaceProp = ((int (__thiscall *)(IPhysicsSurfaceProps *, const char *, int, int, int))physprops->GetSurfaceIndex)(
                          a1: physprops,
                          a2: String,
                          a3: a2,
                          a4: a3,
                          a5: a1);
  data.m_nDamageType = KeyValues::GetInt(this: pKeyValues, keyName: "damagetype", defaultValue: 0);
  data.m_nHitBox = KeyValues::GetInt(this: pKeyValues, keyName: "hitbox", defaultValue: 0);
  data.m_nColor = KeyValues::GetInt(this: pKeyValues, keyName: "color", defaultValue: 0);
  data.m_nAttachmentIndex = KeyValues::GetInt(this: pKeyValues, keyName: "attachmentindex", defaultValue: 0);
  v7 = *(_DWORD *)(cl_entitylist.m_Index + 4);
  if ( v7 != 0 )
    v10 = *(_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
  else
    v10 = -1;
  data.m_hEntity.m_Index = (unsigned int)KeyValues::GetPtr(
                                           this: pKeyValues,
                                           keyName: "entindex",
                                           defaultValue: (void *)v10);
  v8 = KeyValues::GetString(this: pKeyValues, keyName: "effectname", defaultValue: prType);
  if ( !te->SuppressTE(this: te, a2: filter) )
  {
    DispatchEffectToCallback(pEffectName: v8, m_EffectData: &data);
    RecordEffect(pEffectName: v8, &data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3300
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::InsertMultipleBefore(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ikcontextikrule_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 132 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102B3F50
// Name: public: int CUtlVector<struct ikcontextikrule_t,class CUtlMemory<struct ikcontextikrule_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>::AddToTail(
        CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  ikcontextikrule_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ikcontextikrule_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 132 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102B7D00
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertBefore(int,struct CExpressionSample const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem,
        const CExpressionSample *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v7; // eax
  CExpressionSample *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 10 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102B7F90
// Name: public: int CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::InsertBefore(int,class CEventRelativeTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::InsertBefore(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this,
        int elem,
        const CEventRelativeTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEventRelativeTag *m_pMemory; // ecx
  int v7; // eax
  CEventRelativeTag *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->m_Name);
    CUtlString::operator=(this: &v8->m_Name, src: &src->m_Name);
    v8->m_flPercentage = src->m_flPercentage;
    v8->m_pOwner = src->m_pOwner;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102B8020
// Name: public: int CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::InsertBefore(int,class CFlexTimingTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::InsertBefore(
        CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int> > *this,
        int elem,
        const CFlexTimingTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFlexTimingTag *m_pMemory; // ecx
  int v7; // eax
  CFlexTimingTag *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimSequence_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->m_Name);
    CUtlString::operator=(this: &v8->m_Name, src: &src->m_Name);
    v8->m_flPercentage = src->m_flPercentage;
    v8->m_pOwner = src->m_pOwner;
    v8->m_bLocked = src->m_bLocked;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102B80C0
// Name: public: int CUtlVector<class CEventAbsoluteTag,class CUtlMemory<class CEventAbsoluteTag,int>>::InsertBefore(int,class CEventAbsoluteTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int>>::InsertBefore(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this,
        int elem,
        const CEventAbsoluteTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEventAbsoluteTag *m_pMemory; // ecx
  int v7; // eax
  CEventAbsoluteTag *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimSequence_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CEventAbsoluteTag::CEventAbsoluteTag(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102B8930
// Name: public: void CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CEventRelativeTag *v3; // esi
  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B89A0
// Name: public: void CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::RemoveAll(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CEventAbsoluteTag *v3; // esi
  CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9610
// Name: public: CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::~CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this)
{
  bool v2; // sf
  CEventRelativeTag *m_pMemory; // eax

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9670
// Name: public: CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::~CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::~CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>(
        CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int> > *this)
{
  bool v2; // sf
  CFlexTimingTag *m_pMemory; // eax

  CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::RemoveAll((CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BB1D0
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v6; // eax
  CExpressionSample *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 10 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->value = 0.0;
    v7->time = 0.0;
    *((_WORD *)v7 + 4) = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102CB8B0
// Name: public: void CUtlVector<struct CMDLPanel::MDLData_t,class CUtlMemory<struct CMDLPanel::MDLData_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int>>::Purge(
        CUtlVector<CMDLPanel::MDLData_t,CUtlMemory<CMDLPanel::MDLData_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CMDLPanel::MDLData_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CMDL::~CMDL(this: &this->m_Memory.m_pMemory[v3--].m_MDL);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CE110
// Name: public: CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>>::CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int>>::CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int>>(
        CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *this,
        int growSize,
        int initSize)
{
  CDmxElement **m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (CDmxElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CE160
// Name: public: class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> const __near & CDmxAttribute::GetArray<class CDmxElement __near *>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CDmxAttribute::GetArray<CDmxElement *>(
        CDmxAttribute *this)
{
  if ( this->m_Type == AT_FIRST_ARRAY_TYPE )
    return (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x102CE5C0
// Name: public: class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> const __near & CDmxElement::GetArray<class CDmxElement __near *>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CDmxElement::GetArray<CDmxElement *>(
        CDmxElement *this,
        const char *pAttributeName)
{
  CDmxAttribute *Attribute; // eax

  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
  if ( (`CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxElement::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_Size = 0;
    `CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue.m_pElements = nullptr;
    atexit(func: `CDmxElement::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultValue'');
  }
  return &`CDmxElement::GetArray<CDmxElement *>'::`4'::defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x102D4970
// Name: public: void CUtlVector<class CSheet __near *,class CUtlMemory<class CSheet __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CSheet *,CUtlMemory<CSheet *,int>>::PurgeAndDeleteElements(
        CUtlVector<CSheet *,CUtlMemory<CSheet *,int> > *this)
{
  int i; // edi
  CSheet *v3; // ebx
  bool v4; // sf
  CSheet **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CSheet::~CSheet(this: this->m_Memory.m_pMemory[i]);
      C_BaseEntity::operator delete(pMem: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D49E0
// Name: public: void CUtlVector<class CParticleOperatorInstance __near *,class CUtlMemory<class CParticleOperatorInstance __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CParticleOperatorInstance *,CUtlMemory<CParticleOperatorInstance *,int>>::PurgeAndDeleteElements(
        CUtlVector<CParticleOperatorInstance *,CUtlMemory<CParticleOperatorInstance *,int> > *this)
{
  int i; // edi
  CParticleOperatorInstance *v3; // ecx
  bool v4; // sf
  CParticleOperatorInstance **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CParticleOperatorInstance *, int))v3->dtr_CParticleOperatorInstance)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D4A50
// Name: public: int CUtlVector<class IKeyBindingListener __near *,class CUtlMemory<class IKeyBindingListener __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<IKeyBindingListener *,CUtlMemory<IKeyBindingListener *,int>>::InsertMultipleBefore(
        CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CParticleSystemDefinition **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x102D6270
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F6E0
// Name: public: int CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>::InsertBefore(int,struct CacheOptimizedTriangle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
        CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int> > *this,
        int elem,
        const CacheOptimizedTriangle *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  CacheOptimizedTriangle *v10; // eax

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        this: &this->m_Memory,
        nBlocks: m_nBlocks + (v6 + v7 - 1) / v6);
  }
  v8 = ++this->m_Size - elem - 1;
  this->m_pElements = nullptr;
  if ( v8 > 0 )
  {
    v9 = *((_DWORD *)&this->m_Memory + 2);
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + 1) >> (v9 >> 27)][(elem + 1) & ((32 * v9) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (v9 >> 27)][elem & ((32 * v9) >> 5)],
      count: 48 * v8);
  }
  v10 = &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                               & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v10 != nullptr )
    *v10 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10372510
// Name: public: int CUtlVector<class CMDLAttachmentData,class CUtlMemory<class CMDLAttachmentData,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int>>::InsertMultipleBefore(
        CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMDLAttachmentData *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMDLAttachmentData,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 52 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1037C920
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  vgui::BoundKey_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1037C990
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103867D0
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10386850
// Name: public: int CUtlVector<struct vgui::AnimationController::RanEvent_t,class CUtlMemory<struct vgui::AnimationController::RanEvent_t,int>>::InsertBefore(int,struct vgui::AnimationController::RanEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem,
        const vgui::PropertySheet::Page_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // ecx
  int v7; // eax
  vgui::PropertySheet::Page_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10387410
// Name: public: int CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::AnimSequence_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::AnimSequence_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->cmdList.m_Memory.m_pMemory = nullptr;
    v7->cmdList.m_Memory.m_nAllocationCount = 0;
    v7->cmdList.m_Memory.m_nGrowSize = 0;
    v7->cmdList.m_Size = 0;
    v7->cmdList.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103874A0
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::Remove(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int v3; // eax

  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Memory.m_pMemory[elem].cmdList);
  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 28 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10388330
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10391310
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x10392CE0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399650
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<DetailPropSpriteDict_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103A7FE0
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103BA320
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103BC8F0
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103C19A0
// Name: public: void CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  vgui::CHistoryItem *m_pMemory; // esi
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      C_BaseEntity::operator delete(pMem: this->m_Memory.m_pMemory[v2].m_text);
      C_BaseEntity::operator delete(pMem: m_pMemory[v2].m_extraText);
      m_pMemory[v2--].m_text = nullptr;
      if ( --v1 < 0 )
        break;
      this = v4;
    }
    v4->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C1E80
// Name: public: void CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this,
        int elem)
{
  vgui::CHistoryItem *m_pMemory; // esi

  m_pMemory = this->m_Memory.m_pMemory;
  C_BaseEntity::operator delete(pMem: this->m_Memory.m_pMemory[elem].m_text);
  C_BaseEntity::operator delete(pMem: m_pMemory[elem].m_extraText);
  m_pMemory[elem].m_text = nullptr;
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 12 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103C1FB0
// Name: public: CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::~CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this)
{
  bool v2; // sf
  vgui::CHistoryItem *m_pMemory; // eax

  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C63D0
// Name: public: int CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::InsertBefore(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::FileData_t *m_pMemory; // ecx
  int v6; // eax
  vgui::FileData_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::FileData_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 288 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_FileAttributes);
    CUtlString::CUtlString(this: &v7->m_CreationTime);
    CUtlString::CUtlString(this: &v7->m_LastAccessTime);
    CUtlString::CUtlString(this: &v7->m_LastWriteTime);
    CUtlString::CUtlString(this: &v7->m_FileName);
    CUtlString::CUtlString(this: &v7->m_FullPath);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103C7330
// Name: public: void CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::Purge(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  vgui::FileData_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      vgui::FileData_t::~FileData_t(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8F40
// Name: public: int CUtlVector<class vgui::CItemButton __near *,class CUtlMemory<class vgui::CItemButton __near *,int>>::Find(class vgui::CItemButton __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::Find(
        CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int> > *this,
        vgui::CItemButton **src)
{
  int m_Size; // edx
  int result; // eax
  vgui::CItemButton **i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CAE80
// Name: public: int CUtlVector<struct vgui::SectionedListPanel::column_t,class CUtlMemory<struct vgui::SectionedListPanel::column_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::SectionedListPanel::column_t,CUtlMemory<vgui::SectionedListPanel::column_t,int>>::AddToTail(
        CUtlVector<vgui::SectionedListPanel::column_t,CUtlMemory<vgui::SectionedListPanel::column_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  vgui::SectionedListPanel::column_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::SectionedListPanel::column_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 172 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103CB030
// Name: public: int CUtlVector<struct vgui::SectionedListPanel::section_t,class CUtlMemory<struct vgui::SectionedListPanel::section_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::InsertBefore(
        CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::SectionedListPanel::section_t *m_pMemory; // ecx
  int v6; // eax
  vgui::SectionedListPanel::section_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CSnowFallManager::SnowFall_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Columns.m_Memory.m_pMemory = nullptr;
    v7->m_Columns.m_Memory.m_nAllocationCount = 0;
    v7->m_Columns.m_Memory.m_nGrowSize = 0;
    v7->m_Columns.m_Size = 0;
    v7->m_Columns.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103CB360
// Name: public: void CUtlVector<struct vgui::SectionedListPanel::section_t,class CUtlMemory<struct vgui::SectionedListPanel::section_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::RemoveAll(
        CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 36 * v1;
    v5 = 36 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 6) = 0;
      if ( *((int *)v3 + 5) >= 0 )
      {
        if ( *((_DWORD *)v3 + 3) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 3));
          this = v6;
          *((_DWORD *)v3 + 3) = 0;
        }
        *((_DWORD *)v3 + 4) = 0;
      }
      v4 = *((void **)v3 + 3);
      *((_DWORD *)v3 + 7) = v4;
      if ( *((int *)v3 + 5) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 3) = 0;
        }
        *((_DWORD *)v3 + 4) = 0;
      }
      --v1;
      v2 = v5 - 36;
      v5 -= 36;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CB530
// Name: public: CUtlVector<struct vgui::SectionedListPanel::section_t,class CUtlMemory<struct vgui::SectionedListPanel::section_t,int>>::~CUtlVector<struct vgui::SectionedListPanel::section_t,class CUtlMemory<struct vgui::SectionedListPanel::section_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::~CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>(
        CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int> > *this)
{
  bool v2; // sf
  vgui::SectionedListPanel::section_t *m_pMemory; // eax

  CUtlVector<vgui::SectionedListPanel::section_t,CUtlMemory<vgui::SectionedListPanel::section_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CDE20
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x103CF400
// Name: public: int CUtlVector<class CHandle<class C_BaseFlex>,class CUtlMemory<class CHandle<class C_BaseFlex>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CHandle<C_BaseFlex>,CUtlMemory<CHandle<C_BaseFlex>,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103CF9E0
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x103D82E0
// Name: public: void CUtlVector<struct vgui::PropertySheet::Page_t,class CUtlMemory<struct vgui::PropertySheet::Page_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int>>::Remove(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 8 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103D8320
// Name: public: void CUtlVector<class Color,class CUtlMemory<class Color,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::Remove(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103D87E0
// Name: public: int CUtlVector<class vgui::CItemButton __near *,class CUtlMemory<class vgui::CItemButton __near *,int>>::InsertBefore(int,class vgui::CItemButton __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int>>::InsertBefore(
        CUtlVector<vgui::CItemButton *,CUtlMemory<vgui::CItemButton *,int> > *this,
        int elem,
        vgui::CItemButton **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CItemButton **m_pMemory; // ecx
  int v7; // eax
  vgui::CItemButton **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10405610
// Name: public: class CUtlVector<class CHudElement __near *,class CUtlMemory<class CHudElement __near *,int>> __near & CHud::GetHudList(void)
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CHud::GetHudList(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10406470
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmxAttribute::GetArray<float>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmxAttribute::GetArray<float>(CDmxAttribute *this)
{
  if ( this->m_Type == AT_FLOAT_ARRAY )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<float>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<float>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<float>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<float>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x10408750
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int num)
{
  DmeTime_t *m_pMemory; // edx
  unsigned int v4; // eax
  DmeTime_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (DmeTime_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (DmeTime_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104087B0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool *v4; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408810
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int num)
{
  Vector2D *m_pMemory; // edx
  unsigned int v4; // eax
  Vector2D *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 8 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408870
// Name: public: void CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::EnsureCapacity(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int num)
{
  VMatrix *m_pMemory; // edx
  unsigned int v4; // eax
  VMatrix *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = num << 6;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104088D0
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int num)
{
  CUtlString *m_pMemory; // edx
  unsigned int v4; // eax
  CUtlString *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408930
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  Vector2D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x104089A0
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  Vector4D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10408A20
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        const QAngle *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v7; // eax
  QAngle *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10408AA0
// Name: public: int CUtlVector<struct randomsound_t,class CUtlMemory<struct randomsound_t,int>>::InsertBefore(int,struct randomsound_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        const VMatrix *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<loopingsound_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408B10
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10408B80
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  CUtlBinaryBlock *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v7, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1040A0C0
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  bool v2; // sf
  CUtlBinaryBlock *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042BE80
// Name: DT_TEEffectDispatch::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEEffectDispatch::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEEffectDispatch::g_RecvTable);
  return atexit(func: DT_TEEffectDispatch::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BEA0
// Name: DT_TEEffectDispatch::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEEffectDispatch::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEEffectDispatch::ignored>();
  DT_TEEffectDispatch::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042BED0
// Name: ErrorPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ErrorPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ErrorPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ErrorPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436AC0
// Name: DT_TEEffectDispatch::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEEffectDispatch::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEEffectDispatch::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102588A0
// Name: _C_TEEffectDispatch_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEEffectDispatch_CreateObject()
{
  return &_g_C_TEEffectDispatch.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042BEB0
// Name: _dynamic_initializer_for__ClientEffectReg_ErrorEffectCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ErrorEffectCallback__()
{
  CClientEffectRegistration *result; // eax

  result = CClientEffectRegistration::s_pHead;
  ClientEffectReg_ErrorEffectCallback.m_pNext = CClientEffectRegistration::s_pHead;
  CClientEffectRegistration::s_pHead = &ClientEffectReg_ErrorEffectCallback;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042BEF0
// Name: _dynamic_initializer_for____g_C_TEEnergySplash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEEnergySplash__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEEnergySplash);
  _g_C_TEEnergySplash.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEEnergySplash_vtbl *)&C_TEEnergySplash::`vftable'{for `IClientUnknown'};
  _g_C_TEEnergySplash.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEEnergySplash::`vftable'{for `IClientNetworkable'};
  _g_C_TEEnergySplash.m_vecPos.x = 0.0;
  _g_C_TEEnergySplash.m_vecPos.y = 0.0;
  _g_C_TEEnergySplash.m_vecPos.z = 0.0;
  _g_C_TEEnergySplash.m_vecDir.x = 0.0;
  _g_C_TEEnergySplash.m_vecDir.y = 0.0;
  _g_C_TEEnergySplash.m_vecDir.z = 0.0;
  _g_C_TEEnergySplash.m_bExplosive = false;
  _g_C_TEEnergySplash.m_pModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEEnergySplash__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BF60
// Name: _dynamic_initializer_for____g_C_TEEnergySplashClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEEnergySplashClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEEnergySplashClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEEnergySplashClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436AD0
// Name: _DispatchEffectToCallback_::_2_::_dynamic_atexit_destructor_for__map__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DispatchEffectToCallback_::_2_::_dynamic_atexit_destructor_for__map__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &map.m_SymbolTable);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&map);
}

//------------------------------------------------------------------------------
// Address: 0x10436AF0
// Name: _dynamic_atexit_destructor_for____g_C_TEEnergySplash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEEnergySplash__()
{
  _g_C_TEEnergySplash.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEEnergySplash_vtbl *)&C_TEEnergySplash::`vftable'{for `IClientUnknown'};
  _g_C_TEEnergySplash.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEEnergySplash::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEEnergySplash);
}
