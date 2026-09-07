// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/dialogs/tilegendialog.cpp
// Functions: 152
// ============================================================

#include "missionchooser\vgui\dialogs\tilegendialog.h"

//------------------------------------------------------------------------------
// Address: 0x10001CB0
// Name: public: int CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::Find(class vgui::PageTab __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::Find(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        vgui::PageTab **src)
{
  int m_Size; // edx
  int result; // eax
  vgui::PageTab **i; // ecx

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
// Address: 0x10001F10
// Name: public: void CUtlVector<class CASW_Reward __near *,class CUtlMemory<class CASW_Reward __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CASW_Reward *,CUtlMemory<CASW_Reward *,int>>::PurgeAndDeleteElements(
        CUtlVector<CASW_Reward *,CUtlMemory<CASW_Reward *,int> > *this)
{
  int i; // ebx
  CASW_Reward *v3; // edi
  bool v4; // sf
  CASW_Reward **m_pMemory; // ecx
  char *m_szRewardName; // [esp-8h] [ebp-10h]

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      m_szRewardName = (char *)v3->m_szRewardName;
      v3->__vftable = (CASW_Reward_vtbl *)&CASW_Reward::`vftable';
      free(pMem: m_szRewardName);
      free(pMem: v3);
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
// Address: 0x100024B0
// Name: public: void CUtlVector<class CASW_Location __near *,class CUtlMemory<class CASW_Location __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CASW_Location *,CUtlMemory<CASW_Location *,int>>::PurgeAndDeleteElements(
        CUtlVector<CASW_Location *,CUtlMemory<CASW_Location *,int> > *this)
{
  int v1; // eax
  CASW_Location *v3; // edi
  KeyValues *m_pMissionKV; // ecx
  bool v5; // sf
  CASW_Reward **m_pMemory; // eax
  CASW_Location **v7; // ecx
  int i; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( i = 0; v1 < this->m_Size; i = v1 )
  {
    v3 = this->m_Memory.m_pMemory[v1];
    if ( v3 != nullptr )
    {
      m_pMissionKV = v3->m_pMissionKV;
      v3->__vftable = (CASW_Location_vtbl *)&CASW_Location::`vftable';
      if ( m_pMissionKV != nullptr )
        KeyValues::deleteThis(this: m_pMissionKV);
      CUtlVector<CASW_Reward *,CUtlMemory<CASW_Reward *,int>>::PurgeAndDeleteElements(this: &v3->m_Rewards);
      v5 = v3->m_Rewards.m_Memory.m_nGrowSize < 0;
      v3->m_Rewards.m_Size = 0;
      if ( !v5 )
      {
        if ( v3->m_Rewards.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Rewards.m_Memory.m_pMemory);
          v3->m_Rewards.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Rewards.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->m_Rewards.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Rewards.m_Memory.m_pMemory;
      v3->m_Rewards.m_pElements = m_pMemory;
      if ( !v5 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Rewards.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Rewards.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v1 = i;
    }
    ++v1;
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
    v7 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002940
// Name: public: void CUtlVector<class CASW_Location_Group __near *,class CUtlMemory<class CASW_Location_Group __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CASW_Location_Group *,CUtlMemory<CASW_Location_Group *,int>>::PurgeAndDeleteElements(
        CUtlVector<CASW_Location_Group *,CUtlMemory<CASW_Location_Group *,int> > *this)
{
  CUtlVector<CASW_Location_Group *,CUtlMemory<CASW_Location_Group *,int> > *v1; // edi
  int v2; // eax
  CASW_Location_Group *v3; // esi
  CASW_Location **m_pMemory; // eax
  int *v5; // eax
  CASW_Location_Group **v6; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; v2 < v1->m_Size; i = v2 )
  {
    v3 = v1->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      v3->__vftable = (CASW_Location_Group_vtbl *)&CASW_Location_Group::`vftable';
      CUtlVector<CASW_Location *,CUtlMemory<CASW_Location *,int>>::PurgeAndDeleteElements(this: &v3->m_Locations);
      free(pMem: (void *)v3->m_szGroupName);
      free(pMem: (void *)v3->m_szTitleText);
      free(pMem: (void *)v3->m_szDescriptionText);
      free(pMem: (void *)v3->m_szImageName);
      v3->m_Locations.m_Size = 0;
      if ( v3->m_Locations.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Locations.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Locations.m_Memory.m_pMemory);
          v3->m_Locations.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Locations.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Locations.m_Memory.m_pMemory;
      v3->m_Locations.m_pElements = m_pMemory;
      if ( v3->m_Locations.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Locations.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Locations.m_Memory.m_nAllocationCount = 0;
      }
      v3->m_UnlockedBy.m_Size = 0;
      if ( v3->m_UnlockedBy.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_UnlockedBy.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_UnlockedBy.m_Memory.m_pMemory);
          v3->m_UnlockedBy.m_Memory.m_pMemory = nullptr;
        }
        v3->m_UnlockedBy.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->m_UnlockedBy.m_Memory.m_pMemory;
      v3->m_UnlockedBy.m_pElements = v5;
      if ( v3->m_UnlockedBy.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          v3->m_UnlockedBy.m_Memory.m_pMemory = nullptr;
        }
        v3->m_UnlockedBy.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
      v1 = this;
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
    v6 = v1->m_Memory.m_pMemory;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_pElements = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D50
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        const Vector *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v7; // eax
  Vector *v8; // eax

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
// Address: 0x10004090
// Name: public: void CUtlVector<class CMapDisplacement,class CUtlMemory<class CMapDisplacement,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::RemoveAll(
        CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 68 * v1;
    v7 = 68 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 15) = 0;
      if ( *((int *)v3 + 14) >= 0 )
      {
        if ( *((_DWORD *)v3 + 12) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 12));
          *((_DWORD *)v3 + 12) = 0;
        }
        *((_DWORD *)v3 + 13) = 0;
      }
      v4 = *((void **)v3 + 12);
      *((_DWORD *)v3 + 16) = v4;
      if ( *((int *)v3 + 14) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 12) = 0;
        }
        *((_DWORD *)v3 + 13) = 0;
      }
      *((_DWORD *)v3 + 10) = 0;
      if ( *((int *)v3 + 9) >= 0 )
      {
        if ( *((_DWORD *)v3 + 7) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 7));
          *((_DWORD *)v3 + 7) = 0;
        }
        *((_DWORD *)v3 + 8) = 0;
      }
      v5 = *((void **)v3 + 7);
      *((_DWORD *)v3 + 11) = v5;
      if ( *((int *)v3 + 9) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 7) = 0;
        }
        *((_DWORD *)v3 + 8) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 68;
      v7 -= 68;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004180
// Name: public: void CUtlVector<struct MapBrushSide_t,class CUtlMemory<struct MapBrushSide_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::RemoveAll(
        CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    v5 = 44 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = &CCopyableUtlVector<Vector>::`vftable';
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          this = v6;
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      v4 = *((void **)v3 + 5);
      *((_DWORD *)v3 + 9) = v4;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      --v1;
      v2 = v5 - 44;
      v5 -= 44;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004220
// Name: public: CUtlVector<class CMapDisplacement,class CUtlMemory<class CMapDisplacement,int>>::~CUtlVector<class CMapDisplacement,class CUtlMemory<class CMapDisplacement,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::~CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>(
        CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *this)
{
  bool v2; // sf
  CMapDisplacement *m_pMemory; // eax

  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::RemoveAll(this);
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
// Address: 0x10004280
// Name: public: CUtlVector<struct MapBrushSide_t,class CUtlMemory<struct MapBrushSide_t,int>>::~CUtlVector<struct MapBrushSide_t,class CUtlMemory<struct MapBrushSide_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::~CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>(
        CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int> > *this)
{
  bool v2; // sf
  MapBrushSide_t *m_pMemory; // eax

  CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::RemoveAll(this);
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
// Address: 0x10004860
// Name: public: void CUtlVector<class CASW_MissionTextSpec,class CUtlMemory<class CASW_MissionTextSpec,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int>>::RemoveAll(
        CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 40 * v1;
    v4 = 40 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          this = v5;
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v5;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v4 - 40;
      v4 -= 40;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004900
// Name: public: CUtlVector<class CASW_MissionTextSpec,class CUtlMemory<class CASW_MissionTextSpec,int>>::~CUtlVector<class CASW_MissionTextSpec,class CUtlMemory<class CASW_MissionTextSpec,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int>>::~CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int>>(
        CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int> > *this)
{
  bool v2; // sf
  CASW_MissionTextSpec *m_pMemory; // eax

  CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int>>::RemoveAll(this);
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
// Address: 0x10007300
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
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
// Address: 0x10007370
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
    CUtlMemory<EnumEntry_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10007570
// Name: public: int CUtlVector<class CASW_MissionTextSpec,class CUtlMemory<class CASW_MissionTextSpec,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int>>::InsertBefore(
        CUtlVector<CASW_MissionTextSpec,CUtlMemory<CASW_MissionTextSpec,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CASW_MissionTextSpec *m_pMemory; // ecx
  int v6; // eax
  CASW_MissionTextSpec *v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CASW_MissionTextSpec,int>::Grow((CUtlMemory<CBSPFace,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 40 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)&v7->m_nObjectiveEntityName.m_Id = -1;
    CUtlString::CUtlString(this: &v7->m_sShortDesc);
    CUtlString::CUtlString(this: &v7->m_sLongDesc);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10009180
// Name: public: void CUtlVector<class CASW_Spawn_Definition __near *,class CUtlMemory<class CASW_Spawn_Definition __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CASW_Spawn_Definition *,CUtlMemory<CASW_Spawn_Definition *,int>>::PurgeAndDeleteElements(
        CUtlVector<CASW_Spawn_Definition *,CUtlMemory<CASW_Spawn_Definition *,int> > *this)
{
  int v1; // eax
  CASW_Spawn_Definition *v3; // edi
  bool v4; // sf
  CASW_Entry **m_pMemory; // eax
  CASW_Spawn_Definition **v6; // ecx
  int i; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( i = 0; v1 < this->m_Size; i = v1 )
  {
    v3 = this->m_Memory.m_pMemory[v1];
    if ( v3 != nullptr )
    {
      v3->__vftable = (CASW_Spawn_Definition_vtbl *)&CASW_Spawn_Definition::`vftable';
      CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&v3->m_Entries);
      v4 = v3->m_Entries.m_Memory.m_nGrowSize < 0;
      v3->m_Entries.m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_Entries.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Entries.m_Memory.m_pMemory);
          v3->m_Entries.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Entries.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Entries.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Entries.m_Memory.m_pMemory;
      v3->m_Entries.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Entries.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Entries.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v1 = i;
    }
    ++v1;
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
// Address: 0x100092F0
// Name: public: void CUtlVector<class CASW_Spawn_Set __near *,class CUtlMemory<class CASW_Spawn_Set __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CASW_Spawn_Set *,CUtlMemory<CASW_Spawn_Set *,int>>::PurgeAndDeleteElements(
        CUtlVector<CASW_Spawn_Set *,CUtlMemory<CASW_Spawn_Set *,int> > *this)
{
  int i; // edi
  CASW_Spawn_Set *v3; // ebx
  bool v4; // sf
  CASW_Spawn_Set **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CASW_Spawn_Set::~CASW_Spawn_Set(this: this->m_Memory.m_pMemory[i]);
      free(pMem: v3);
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
// Address: 0x1000B110
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
// Address: 0x1000B8D0
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BBC0
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
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
// Address: 0x1000CCC0
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x1000EB80
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
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>::Grow(
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
// Address: 0x10013500
// Name: public: int CUtlVector<struct KeyValue_t,class CUtlMemory<struct KeyValue_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int>>::InsertMultipleBefore(
        CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  KeyValue_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<StaticPropDictLump_t,int>::Grow(
      (CUtlMemory<StaticPropDictLump_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9 << 7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100157B0
// Name: public: int CUtlVector<class CInstanceSpawn,class CUtlMemory<class CInstanceSpawn,int>>::InsertBefore(int,class CInstanceSpawn const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>::InsertBefore(
        CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int> > *this,
        int elem,
        const CInstanceSpawn *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CInstanceSpawn *m_pMemory; // ecx
  int v7; // eax
  CInstanceSpawn *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CInstanceSpawn,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 296 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CInstanceSpawn::CInstanceSpawn(this: v8, __that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10017F10
// Name: public: void CUtlVector<class ITilegenExpression<float> __near *,class CUtlMemory<class ITilegenExpression<float> __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ITilegenExpression<float> *,CUtlMemory<ITilegenExpression<float> *,int>>::PurgeAndDeleteElements(
        CUtlVector<ITilegenExpression<bool> *,CUtlMemory<ITilegenExpression<bool> *,int> > *this)
{
  int i; // edi
  ITilegenExpression<bool> *v3; // ecx
  bool v4; // sf
  ITilegenExpression<bool> **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(ITilegenExpression<bool> *, int))v3->dtr_ITilegenExpression<bool>)(a1: v3, a2: 1);
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
// Address: 0x1001D030
// Name: public: void CUtlVector<class CTilegenState __near *,class CUtlMemory<class CTilegenState __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CTilegenState *,CUtlMemory<CTilegenState *,int>>::PurgeAndDeleteElements(
        CUtlVector<CTilegenState *,CUtlMemory<CTilegenState *,int> > *this)
{
  int i; // edi
  CTilegenState *v3; // ebx
  bool v4; // sf
  CTilegenState **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CTilegenState::~CTilegenState(this: this->m_Memory.m_pMemory[i]);
      free(pMem: v3);
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
// Address: 0x1001E790
// Name: public: void CUtlVector<class CTilegenRule __near *,class CUtlMemory<class CTilegenRule __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CTilegenRule *,CUtlMemory<CTilegenRule *,int>>::PurgeAndDeleteElements(
        CUtlVector<CTilegenRule *,CUtlMemory<CTilegenRule *,int> > *this)
{
  int i; // edi
  CTilegenRule *v3; // ebx
  bool v4; // sf
  CTilegenRule **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CTilegenRule::~CTilegenRule(this: this->m_Memory.m_pMemory[i]);
      free(pMem: v3);
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
// Address: 0x1001F390
// Name: public: int CUtlVector<struct CTilegenRule::SubstitutionVariable_t,class CUtlMemory<struct CTilegenRule::SubstitutionVariable_t,int>>::InsertBefore(int,struct CTilegenRule::SubstitutionVariable_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CTilegenRule::SubstitutionVariable_t,CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>>::InsertBefore(
        CUtlVector<CTilegenRule::SubstitutionVariable_t,CUtlMemory<CTilegenRule::SubstitutionVariable_t,int> > *this,
        int elem,
        const CTilegenRule::SubstitutionVariable_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CTilegenRule::SubstitutionVariable_t *m_pMemory; // ecx
  int v7; // eax
  CTilegenRule::SubstitutionVariable_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>::Grow(
      (CUtlMemory<MapBrush_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100247D0
// Name: public: void CUtlVector<class CRoomTemplate __near *,class CUtlMemory<class CRoomTemplate __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CRoomTemplate *,CUtlMemory<CRoomTemplate *,int>>::PurgeAndDeleteElements(
        CUtlVector<CRoomTemplate *,CUtlMemory<CRoomTemplate *,int> > *this)
{
  int i; // edi
  CRoomTemplate *v3; // ebx
  bool v4; // sf
  CRoomTemplate **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CRoomTemplate::~CRoomTemplate(this: this->m_Memory.m_pMemory[i]);
      free(pMem: v3);
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
// Address: 0x10024C20
// Name: public: void CUtlVector<class CLevelTheme __near *,class CUtlMemory<class CLevelTheme __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CLevelTheme *,CUtlMemory<CLevelTheme *,int>>::PurgeAndDeleteElements(
        CUtlVector<CLevelTheme *,CUtlMemory<CLevelTheme *,int> > *this)
{
  int v2; // eax
  CLevelTheme *v3; // esi
  CRoomTemplate **m_pMemory; // eax
  CLevelTheme **v5; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<CRoomTemplate *,CUtlMemory<CRoomTemplate *,int>>::PurgeAndDeleteElements(this: &v3->m_RoomTemplates);
      v3->m_RoomTemplates.m_Size = 0;
      if ( v3->m_RoomTemplates.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_RoomTemplates.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_RoomTemplates.m_Memory.m_pMemory);
          v3->m_RoomTemplates.m_Memory.m_pMemory = nullptr;
        }
        v3->m_RoomTemplates.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_RoomTemplates.m_Memory.m_pMemory;
      v3->m_RoomTemplates.m_pElements = m_pMemory;
      if ( v3->m_RoomTemplates.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_RoomTemplates.m_Memory.m_pMemory = nullptr;
        }
        v3->m_RoomTemplates.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
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
// Address: 0x100257D0
// Name: public: int CUtlVector<struct KeyValue_t,class CUtlMemory<struct KeyValue_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int>>::AddToTail(
        CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValue_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<StaticPropDictLump_t,int>::Grow(
      (CUtlMemory<StaticPropDictLump_t,int> *)this,
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
// Address: 0x10025FC0
// Name: public: void CUtlVector<class CASW_Encounter __near *,class CUtlMemory<class CASW_Encounter __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CASW_Encounter *,CUtlMemory<CASW_Encounter *,int>>::PurgeAndDeleteElements(
        CUtlVector<CASW_Encounter *,CUtlMemory<CASW_Encounter *,int> > *this)
{
  int v2; // eax
  CASW_Encounter *v3; // esi
  CASW_Spawn_Definition **m_pMemory; // eax
  CASW_Encounter **v5; // ecx
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      v3->m_SpawnDefs.m_Size = 0;
      if ( v3->m_SpawnDefs.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_SpawnDefs.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_SpawnDefs.m_Memory.m_pMemory);
          v3->m_SpawnDefs.m_Memory.m_pMemory = nullptr;
        }
        v3->m_SpawnDefs.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_SpawnDefs.m_Memory.m_pMemory;
      v3->m_SpawnDefs.m_pElements = m_pMemory;
      if ( v3->m_SpawnDefs.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_SpawnDefs.m_Memory.m_pMemory = nullptr;
        }
        v3->m_SpawnDefs.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
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
// Address: 0x10026080
// Name: public: int CUtlVector<class CInstanceSpawn,class CUtlMemory<class CInstanceSpawn,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>::InsertBefore(
        CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CInstanceSpawn *m_pMemory; // ecx
  int v6; // eax
  CInstanceSpawn *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CInstanceSpawn,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 296 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_AdditionalKeyValues.m_Memory.m_pMemory = nullptr;
    v7->m_AdditionalKeyValues.m_Memory.m_nAllocationCount = 0;
    v7->m_AdditionalKeyValues.m_Memory.m_nGrowSize = 0;
    v7->m_AdditionalKeyValues.m_Size = 0;
    v7->m_AdditionalKeyValues.m_pElements = nullptr;
    v7->m_AdditionalKeyValues.__vftable = (CCopyableUtlVector<KeyValue_t>_vtbl *)&CCopyableUtlVector<KeyValue_t>::`vftable';
    v7->m_InstanceSpawningMethod = ISM_INVALID;
    v7->m_nPlacedRoomIndex = -1;
    v7->m_InstanceFilename[0] = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100262C0
// Name: public: void CUtlVector<class CInstanceSpawn,class CUtlMemory<class CInstanceSpawn,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>::RemoveAll(
        CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 296 * v1;
    v5 = 296 * v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory->m_InstanceFilename[v2];
      *((_DWORD *)v3 + 65) = &CCopyableUtlVector<KeyValue_t>::`vftable';
      *((_DWORD *)v3 + 69) = 0;
      if ( *((int *)v3 + 68) >= 0 )
      {
        if ( *((_DWORD *)v3 + 66) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 66));
          this = v6;
          *((_DWORD *)v3 + 66) = 0;
        }
        *((_DWORD *)v3 + 67) = 0;
      }
      v4 = *((void **)v3 + 66);
      *((_DWORD *)v3 + 70) = v4;
      if ( *((int *)v3 + 68) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 66) = 0;
        }
        *((_DWORD *)v3 + 67) = 0;
      }
      --v1;
      v2 = v5 - 296;
      v5 -= 296;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026760
// Name: public: CUtlVector<class CInstanceSpawn,class CUtlMemory<class CInstanceSpawn,int>>::~CUtlVector<class CInstanceSpawn,class CUtlMemory<class CInstanceSpawn,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>::~CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>(
        CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int> > *this)
{
  bool v2; // sf
  CInstanceSpawn *m_pMemory; // eax

  CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>::RemoveAll(this);
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
// Address: 0x10029C30
// Name: public: void CUtlVector<struct CRoomTemplateListPanel::RoomTemplateFolder_t,class CUtlMemory<struct CRoomTemplateListPanel::RoomTemplateFolder_t,int>>::Sort(int (*)(struct CRoomTemplateListPanel::RoomTemplateFolder_t const __near *,struct CRoomTemplateListPanel::RoomTemplateFolder_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CRoomTemplateListPanel::RoomTemplateFolder_t,CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int>>::Sort(
        CUtlVector<CRoomTemplateListPanel::RoomTemplateFolder_t,CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  CUtlVector<CRoomTemplateListPanel::RoomTemplateFolder_t,CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int> > *v2; // esi
  signed int m_Size; // eax
  CRoomTemplateListPanel::RoomTemplateFolder_t *m_pMemory; // ecx
  int v5; // edi
  int v6; // ebx
  CRoomTemplateListPanel::RoomTemplateFolder_t *v7; // eax
  _BYTE v8[268]; // [esp+4h] [ebp-118h] BYREF
  CUtlVector<CRoomTemplateListPanel::RoomTemplateFolder_t,CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int> > *v9; // [esp+110h] [ebp-Ch]
  int j; // [esp+114h] [ebp-8h]
  int i; // [esp+118h] [ebp-4h]

  v2 = this;
  m_Size = this->m_Size;
  v9 = this;
  if ( m_Size > 1 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( v2->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0x10Cu, comp: pfnCompare);
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
              qmemcpy(&v7[-1], v7, sizeof(CRoomTemplateListPanel::RoomTemplateFolder_t));
              qmemcpy(v7, v8, sizeof(CRoomTemplateListPanel::RoomTemplateFolder_t));
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
// Address: 0x1002EE10
// Name: public: void CUtlVector<class CRoomTemplateExit __near *,class CUtlMemory<class CRoomTemplateExit __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CRoomTemplateExit *,CUtlMemory<CRoomTemplateExit *,int>>::Remove(
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
// Address: 0x10031890
// Name: public: static char const __near * CTileGenDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTileGenDialog::GetPanelClassName()
{
  return "CTileGenDialog";
}

//------------------------------------------------------------------------------
// Address: 0x100318A0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x100318F0
// Name: void VGUIMessageBox(class vgui::Panel __near *,char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VGUIMessageBox(vgui::Panel *pParent, char *pTitle, char *pMsg, ...)
{
  vgui::MessageBox *v3; // esi
  char pDest[4096]; // [esp+4h] [ebp-1000h] BYREF
  va_list params; // [esp+1018h] [ebp+14h] BYREF

  va_start(params, pMsg);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: pMsg, params);
  v3 = (vgui::MessageBox *)operator new(nSize: 0x238u);
  if ( v3 != nullptr )
  {
    vgui::MessageBox::MessageBox(this: v3, title: pTitle, text: pDest, parent: pParent);
    v3->__vftable = (vgui::MessageBox_vtbl *)&CModalPreserveMessageBox::`vftable';
    v3[1].__vftable = (vgui::MessageBox_vtbl *)g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  }
  else
  {
    v3 = nullptr;
  }
  v3->DoModal_2(this: v3, a2: nullptr);
  v3->Activate(this: v3);
  v3->RequestFocus(this: v3, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10031990
// Name: protected: virtual void CTileGenDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnClose(CTileGenDialog *this)
{
  vgui::Frame::OnClose(this);
  if ( this != nullptr )
    ((void (__thiscall *)(CTileGenDialog *, int))this->dtr_Panel)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100319B0
// Name: public: virtual void CTileGenDialog::OnUpdateCurrentTheme(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnUpdateCurrentTheme(CTileGenDialog *this, KeyValues *params)
{
  CThemeDetails::SetTheme(this: this->m_pCurrentThemeDetails, pTheme: CLevelTheme::s_pCurrentTheme);
  this->m_pCurrentThemeDetails->InvalidateLayout(this: this->m_pCurrentThemeDetails, a2: false, a3: false);
  CRoomTemplateListPanel::UpdateRoomList(this: this->m_pTemplateListPanel);
  CScrollingWindow::MoveToTopLeft(this: this->m_pTemplateListContainer);
  this->m_pTemplateListContainer->InvalidateLayout(this: this->m_pTemplateListContainer, a2: false, a3: false);
  this->m_pTemplateListContainer->Repaint(this: this->m_pTemplateListContainer);
}

//------------------------------------------------------------------------------
// Address: 0x10031A20
// Name: public: virtual void CTileGenDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::PerformLayout(CTileGenDialog *this)
{
  float v2; // xmm0_4
  int v3; // [esp-Ch] [ebp-18h]
  int v4; // [esp-8h] [ebp-14h]
  int screenTall; // [esp+4h] [ebp-8h] BYREF
  int screenWide; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_bFirstPerformLayout )
  {
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenWide, a3: &screenTall);
    v2 = (float)screenWide * 0.02;
    v4 = screenTall - 2 * (int)v2;
    v3 = screenWide - 3 * (int)v2;
    this->m_bFirstPerformLayout = false;
    vgui::Panel::SetBounds(this, x: (int)v2, y: (int)v2, wide: v3, tall: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031A90
// Name: public: virtual void CTileGenDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::ApplySchemeSettings(CTileGenDialog *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->LoadControlSettings(this, a2: "TileGenDialog.res", a3: "TILEGEN", a4: nullptr, a5: nullptr);
  this->SetSizeable(this, a2: true);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetMaximizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: true);
  this->SetMenuButtonVisible(this, a2: false);
  this->m_bFirstPerformLayout = true;
}

//------------------------------------------------------------------------------
// Address: 0x10031B10
// Name: public: virtual void CTileGenDialog::OnCheckButtonChecked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnCheckButtonChecked(CTileGenDialog *this, vgui::CheckButton *panel)
{
  vgui::CheckButton *m_pShowExitsCheck; // ecx
  vgui::CheckButton *m_pShowTileSquaresCheck; // ecx

  m_pShowExitsCheck = this->m_pShowExitsCheck;
  if ( panel == m_pShowExitsCheck )
  {
    this->m_bShowExits = m_pShowExitsCheck->IsSelected(this: m_pShowExitsCheck);
    CRoomTemplatePanel::UpdateAllImages();
    this->Repaint(this);
  }
  else
  {
    m_pShowTileSquaresCheck = this->m_pShowTileSquaresCheck;
    if ( panel == m_pShowTileSquaresCheck )
    {
      this->m_bShowTileSquares = m_pShowTileSquaresCheck->IsSelected(this: m_pShowTileSquaresCheck);
      CRoomTemplatePanel::UpdateAllImages();
      this->Repaint(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031B80
// Name: public: virtual void CTileGenDialog::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnTextChanged(CTileGenDialog *this, vgui::TextEntry *panel)
{
  char buf[256]; // [esp+4h] [ebp-100h] BYREF

  if ( panel == this->m_pTemplateFilter )
  {
    this->m_pTemplateFilter->GetText_2(this: this->m_pTemplateFilter, a2: buf, a3: 256);
    CRoomTemplateListPanel::SetFilterText(this: this->m_pTemplateListPanel, pText: buf);
    this->m_pTemplateListPanel->InvalidateLayout(this: this->m_pTemplateListPanel, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031BE0
// Name: public: void CTileGenDialog::DoFileOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::DoFileOpen(CTileGenDialog *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi

  this->m_FileSelectType = FST_LAYOUT_OPEN;
  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: nullptr,
           title: "Open Map Layout",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  vgui::FileOpenDialog::SetStartDirectory(this: v3, dir: g_layoutsdir);
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: "*.layout",
    filterName: "Map Layout (*.layout)",
    bActive: true,
    pFilterInfo: nullptr);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x10031C60
// Name: public: void CTileGenDialog::DoFileSaveAs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::DoFileSaveAs(CTileGenDialog *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi

  this->m_FileSelectType = FST_LAYOUT_SAVE_AS;
  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: nullptr,
           title: "Save Map Layout",
           bOpenOnly: false,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  vgui::FileOpenDialog::SetStartDirectory(this: v3, dir: g_layoutsdir);
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: "*.layout",
    filterName: "Map Layout (*.layout)",
    bActive: true,
    pFilterInfo: nullptr);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: true);
}

//------------------------------------------------------------------------------
// Address: 0x10031CE0
// Name: public: virtual struct vgui::PanelMap_t __near * CTileGenDialog::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall CTileGenDialog::GetPanelMap(CTileGenDialog *this)
{
  return &CTileGenDialog::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x10031CF0
// Name: public: class CMapLayoutPanel __near * CTileGenDialog::GetMapLayoutPanel(void)
// Source: json
//------------------------------------------------------------------------------
CMapLayoutPanel *__thiscall CTileGenDialog::GetMapLayoutPanel(CTileGenDialog *this)
{
  return this->m_pLayoutPage->m_pMapLayoutPanel;
}

//------------------------------------------------------------------------------
// Address: 0x10031D00
// Name: public: void CTileGenDialog::StartRubberBandSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::StartRubberBandSelection(CTileGenDialog *this, int mx, int my)
{
  this->m_iStartRubberBandX = mx;
  this->m_iStartRubberBandY = my;
}

//------------------------------------------------------------------------------
// Address: 0x10031D20
// Name: public: bool CTileGenDialog::GetRubberBandStart(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTileGenDialog::GetRubberBandStart(CTileGenDialog *this, int *sx, int *sy)
{
  int m_iStartRubberBandX; // eax

  m_iStartRubberBandX = this->m_iStartRubberBandX;
  if ( m_iStartRubberBandX == -1 )
    return 0;
  *sx = m_iStartRubberBandX;
  *sy = this->m_iStartRubberBandY;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10031D50
// Name: void cc_kv_editor(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_kv_editor()
{
  CKV_Editor_Frame *v0; // esi
  vgui::Panel *v1; // eax
  CKV_Editor_Frame *v2; // esi

  v0 = (CKV_Editor_Frame *)operator new(nSize: 0x330u);
  if ( v0 != nullptr )
  {
    v1 = g_pTileGenDialog->GetParent(this: g_pTileGenDialog);
    v2 = CKV_Editor_Frame::CKV_Editor_Frame(this: v0, parent: v1, name: "KVEditor");
  }
  else
  {
    v2 = nullptr;
  }
  v2->MoveToCenterOfScreen(this: v2);
  v2->Activate(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10031DA0
// Name: char __near * TileGenCopyString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl TileGenCopyString(const char *szString)
{
  int v2; // eax
  int v3; // esi
  char *v4; // edi

  if ( szString == nullptr )
    return nullptr;
  v2 = _V_strlen(str: szString);
  v3 = v2 + 1;
  if ( v2 + 1 <= 1 )
    return nullptr;
  v4 = (char *)operator new(nSize: v2 + 1);
  V_strncpy(pDest: v4, pSrc: szString, maxLen: v3);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10031DF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031E20
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x10031E30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031E60
// Name: public: void CTileGenDialog::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnFileSelected(CTileGenDialog *this, const char *fullpath)
{
  TileGen_FileSelectType m_FileSelectType; // eax
  CMapLayout *m_pMapLayout; // ecx
  CMapLayout *v5; // eax
  CMapLayout *v6; // eax
  vgui::MessageBox *v7; // eax
  vgui::MessageBox *v8; // eax

  m_FileSelectType = this->m_FileSelectType;
  if ( m_FileSelectType == FST_LAYOUT_SAVE_AS )
  {
    CMapLayout::SetCurrentFilename(this: this->m_pMapLayout, szFilename: fullpath);
    CMapLayout::SaveMapLayout(this: this->m_pMapLayout, filename: fullpath);
  }
  else if ( m_FileSelectType == FST_LAYOUT_OPEN )
  {
    m_pMapLayout = this->m_pMapLayout;
    if ( m_pMapLayout != nullptr )
      ((void (__thiscall *)(CMapLayout *, int))m_pMapLayout->dtr_CMapLayout)(a1: m_pMapLayout, a2: 1);
    v5 = (CMapLayout *)operator new(nSize: 0xE264u);
    if ( v5 != nullptr )
      v6 = CMapLayout::CMapLayout(this: v5, pGenerationOptions: nullptr);
    else
      v6 = nullptr;
    this->m_pMapLayout = v6;
    if ( CMapLayout::LoadMapLayout(this: v6, filename: fullpath) )
    {
      CMapLayoutPanel::CreateAllUIPanels(this: this->m_pLayoutPage->m_pMapLayoutPanel);
    }
    else
    {
      v7 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v7 != nullptr )
      {
        v8 = vgui::MessageBox::MessageBox(this: v7, title: "Error", text: "Error loading map layout", parent: this);
        v8->DoModal_2(this: v8, a2: nullptr);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031F40
// Name: public: void CTileGenDialog::GenerateMission(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::GenerateMission(CTileGenDialog *this, const char *szMissionFile)
{
  vgui::PropertySheet *m_pPropertySheet; // ecx
  vgui::PropertySheet_vtbl *v4; // edi
  int v5; // eax
  IBaseFileSystem *v6; // eax
  CLayoutSystem *m_pLayoutSystem; // edi
  vgui::MessageBox *v8; // eax
  vgui::MessageBox *v9; // eax
  CTilegenLayoutSystemPage *m_pLayoutSystemPage; // ecx
  KeyValues *m_pGenerationOptions; // edx
  KeyValues *Key; // ebx
  vgui::MessageBox *v13; // eax
  vgui::MessageBox *v14; // eax
  const char *String; // eax
  IBaseFileSystem *v16; // eax
  CLayoutSystem *v17; // eax
  CLayoutSystem *v18; // eax
  vgui::MessageBox *v19; // eax
  CMapLayout *m_pMapLayout; // ecx
  CMapLayout *v21; // edi
  KeyValues *Copy; // eax
  CMapLayout *v23; // eax
  CLayoutSystem *v24; // ecx
  vgui::MessageBox *v25; // eax
  vgui::MessageBox *v26; // eax

  m_pPropertySheet = this->m_pPropertySheet;
  v4 = m_pPropertySheet->__vftable;
  v5 = (int)m_pPropertySheet->GetPage(this: m_pPropertySheet, a2: 0);
  v4->SetActivePage(this: this->m_pPropertySheet, a2: (vgui::Panel *)v5);
  KeyValues::Clear(this: this->m_pGenerationOptions);
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  KeyValues::LoadFromFile(
    this: this->m_pGenerationOptions,
    filesystem: v6,
    resourceName: szMissionFile,
    pathID: "GAME",
    pfnEvaluateSymbolProc: nullptr);
  m_pLayoutSystem = this->m_pLayoutSystem;
  if ( m_pLayoutSystem != nullptr )
  {
    if ( m_pLayoutSystem->m_bGenerating )
    {
      v8 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v8 != nullptr )
      {
        v9 = vgui::MessageBox::MessageBox(
               this: v8,
               title: "Error",
               text: "Already generating a layout.  Please wait for this to finish before starting a new one.",
               parent: this);
        v9->DoModal_2(this: v9, a2: nullptr);
        return;
      }
      goto LABEL_8;
    }
    CLayoutSystem::~CLayoutSystem(this: this->m_pLayoutSystem);
    free(pMem: m_pLayoutSystem);
  }
  m_pLayoutSystemPage = this->m_pLayoutSystemPage;
  m_pGenerationOptions = this->m_pGenerationOptions;
  this->m_pLayoutSystem = nullptr;
  if ( CTilegenMissionPreprocessor::SubstituteRules(
         this: m_pLayoutSystemPage->m_pPreprocessor,
         pKeyValues: m_pGenerationOptions) )
  {
    Key = KeyValues::FindKey(this: this->m_pGenerationOptions, keyName: "mission_settings", bCreate: false);
    if ( Key == nullptr )
    {
      v13 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v13 != nullptr )
      {
        v14 = vgui::MessageBox::MessageBox(
                this: v13,
                title: "Error",
                text: "Mission is missing a Global Options block.",
                parent: this);
LABEL_27:
        v14->DoModal_2(this: v14, a2: nullptr);
        return;
      }
      goto LABEL_26;
    }
    String = KeyValues::GetString(
               this: this->m_pGenerationOptions,
               keyName: "Filename",
               defaultValue: "invalid_filename");
    KeyValues::SetString(this: Key, keyName: "Filename", value: String);
    if ( tilegen_preprocess_mission.m_pParent != nullptr && tilegen_preprocess_mission.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( g_pFullFileSystem != nullptr )
        v16 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v16 = nullptr;
      KeyValues::SaveToFile(
        this: this->m_pGenerationOptions,
        filesystem: v16,
        resourceName: "preprocessed_mission.txt",
        pathID: "GAME");
    }
    v17 = (CLayoutSystem *)operator new(nSize: 0x154u);
    if ( v17 != nullptr )
      v18 = CLayoutSystem::CLayoutSystem(this: v17);
    else
      v18 = nullptr;
    this->m_pLayoutSystem = v18;
    AddListeners(pLayoutSystem: v18);
    if ( !CLayoutSystem::LoadFromKeyValues(this: this->m_pLayoutSystem, pKeyValues: this->m_pGenerationOptions) )
    {
      v19 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v19 != nullptr )
      {
        v14 = vgui::MessageBox::MessageBox(
                this: v19,
                title: "Error",
                text: "Failed to load mission from pre-processed key-values.",
                parent: this);
        goto LABEL_27;
      }
LABEL_26:
      v14 = nullptr;
      goto LABEL_27;
    }
    m_pMapLayout = this->m_pMapLayout;
    if ( m_pMapLayout != nullptr )
      ((void (__thiscall *)(CMapLayout *, int))m_pMapLayout->dtr_CMapLayout)(a1: m_pMapLayout, a2: 1);
    v21 = (CMapLayout *)operator new(nSize: 0xE264u);
    if ( v21 != nullptr )
    {
      Copy = KeyValues::MakeCopy(this: Key);
      v23 = CMapLayout::CMapLayout(this: v21, pGenerationOptions: Copy);
    }
    else
    {
      v23 = nullptr;
    }
    v24 = this->m_pLayoutSystem;
    this->m_pMapLayout = v23;
    CLayoutSystem::BeginGeneration(this: v24, pMapLayout: v23);
  }
  else
  {
    v25 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v25 == nullptr )
    {
LABEL_8:
      (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
      return;
    }
    v26 = vgui::MessageBox::MessageBox(
            this: v25,
            title: "Error",
            text: "Failed to pre-process layout system definition.",
            parent: this);
    v26->DoModal_2(this: v26, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100321E0
// Name: public: void CTileGenDialog::OnStartDraggingSelectedRooms(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnStartDraggingSelectedRooms(CTileGenDialog *this)
{
  CMapLayoutPanel::GetCursorTile(
    this: this->m_pLayoutPage->m_pMapLayoutPanel,
    tilex: &this->m_iStartDragX,
    tiley: &this->m_iStartDragY);
}

//------------------------------------------------------------------------------
// Address: 0x10032200
// Name: public: void CTileGenDialog::Zoom(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::Zoom(CTileGenDialog *this, int iChange)
{
  vgui::ScrollBar *m_pHorizScrollbar; // ecx
  vgui::ScrollBar *v4; // ecx
  int v5; // eax
  vgui::ScrollBar *m_pVertScrollbar; // ecx
  vgui::ScrollBar *v7; // ecx
  int v8; // eax
  int v9; // xmm1_4
  float v10; // xmm0_4
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx
  vgui::ScrollBar *v12; // ecx
  vgui::ScrollBar *v13; // ecx
  vgui::ScrollBar *v14; // ecx
  vgui::ScrollBar *v15; // ecx
  float flVertFraction; // [esp+8h] [ebp-10h]
  float flHorizFraction; // [esp+Ch] [ebp-Ch]
  int scroll_min; // [esp+10h] [ebp-8h] BYREF
  int scroll_max; // [esp+14h] [ebp-4h] BYREF

  scroll_min = 0;
  scroll_max = 0;
  m_pHorizScrollbar = this->m_pLayoutPage->m_pScrollingWindow->m_pHorizScrollbar;
  m_pHorizScrollbar->GetRange(this: m_pHorizScrollbar, a2: &scroll_min, a3: &scroll_max);
  v4 = this->m_pLayoutPage->m_pScrollingWindow->m_pHorizScrollbar;
  v5 = v4->GetValue(this: v4);
  m_pVertScrollbar = this->m_pLayoutPage->m_pScrollingWindow->m_pVertScrollbar;
  flHorizFraction = (float)(v5 - scroll_min) / (float)(scroll_max - scroll_min);
  m_pVertScrollbar->GetRange(this: m_pVertScrollbar, a2: &scroll_min, a3: &scroll_max);
  v7 = this->m_pLayoutPage->m_pScrollingWindow->m_pVertScrollbar;
  v8 = v7->GetValue(this: v7);
  v9 = 1092616192;
  flVertFraction = (float)(v8 - scroll_min) / (float)(scroll_max - scroll_min);
  v10 = (float)iChange + this->m_fTileSize;
  if ( v10 < 10.0 || (v9 = 1109393408, v10 > 40.0) )
    v10 = *(float *)&v9;
  InvalidateLayout = this->InvalidateLayout;
  this->m_fTileSize = v10;
  InvalidateLayout(this, a2: true, a3: true);
  v12 = this->m_pLayoutPage->m_pScrollingWindow->m_pHorizScrollbar;
  v12->GetRange(this: v12, a2: &scroll_min, a3: &scroll_max);
  v13 = this->m_pLayoutPage->m_pScrollingWindow->m_pHorizScrollbar;
  v13->SetValue(
    this: v13,
    a2: (int)(float)((float)((float)(scroll_max - scroll_min) * flHorizFraction) + (float)scroll_min));
  v14 = this->m_pLayoutPage->m_pScrollingWindow->m_pVertScrollbar;
  v14->GetRange(this: v14, a2: &scroll_min, a3: &scroll_max);
  v15 = this->m_pLayoutPage->m_pScrollingWindow->m_pVertScrollbar;
  v15->SetValue(
    this: v15,
    a2: (int)(float)((float)((float)(scroll_max - scroll_min) * flVertFraction) + (float)scroll_min));
  this->InvalidateLayout(this, a2: true, a3: true);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10032410
// Name: public: void CTileGenDialog::GenerateRoomThumbnails(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::GenerateRoomThumbnails(CTileGenDialog *this, bool bAddToPerforce)
{
  KeyValues *v3; // eax
  CMapLayout *m_pMapLayout; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  int v9; // eax
  IBaseFileSystem *v10; // eax
  KeyValues *v11; // esi
  char filename[260]; // [esp+10h] [ebp-210h] BYREF
  char buffer[256]; // [esp+114h] [ebp-10Ch] BYREF
  float yPos; // [esp+214h] [ebp-Ch]
  int i; // [esp+218h] [ebp-8h]
  KeyValues *pKV; // [esp+21Ch] [ebp-4h]

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    pKV = KeyValues::KeyValues(this: v3, setName: "RoomThumbnails");
  else
    pKV = nullptr;
  m_pMapLayout = this->m_pMapLayout;
  v5 = 0;
  for ( i = 0; v5 < m_pMapLayout->m_PlacedRooms.m_Size; i = v5 )
  {
    v6 = &m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[v5]->__vftable;
    if ( v6 != nullptr )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(this: v7, setName: "Thumbnail");
      else
        v8 = nullptr;
      V_snprintf(
        pDest: filename,
        maxLen: 260,
        pFormat: "tilegen/roomtemplates/%s/%s.tga",
        *(const char **)(v6[3] + 20),
        (const char *)(v6[3] + 568));
      KeyValues::SetString(this: v8, keyName: "Filename", value: filename);
      v9 = v6[1];
      yPos = (float)(v6[2] - 60) * 256.0;
      KeyValues::SetFloat(this: v8, keyName: "RoomX", value: (float)(v9 - 60) * 256.0);
      KeyValues::SetFloat(this: v8, keyName: "RoomY", value: (float)((float)*(int *)(v6[3] + 1408) * 256.0) + yPos);
      KeyValues::SetFloat(this: v8, keyName: "RoomWide", value: (float)*(int *)(v6[3] + 1404) * 256.0);
      KeyValues::SetFloat(this: v8, keyName: "RoomTall", value: (float)*(int *)(v6[3] + 1408) * 256.0);
      KeyValues::SetFloat(this: v8, keyName: "OutputWide", value: (float)*(int *)(v6[3] + 1404) * this->m_fTileSize);
      KeyValues::SetFloat(this: v8, keyName: "OutputTall", value: (float)*(int *)(v6[3] + 1408) * this->m_fTileSize);
      KeyValues::AddSubKey(this: pKV, pSubkey: v8);
      v5 = i;
    }
    m_pMapLayout = this->m_pMapLayout;
    ++v5;
  }
  if ( g_pFullFileSystem != nullptr )
    v10 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v10 = nullptr;
  v11 = pKV;
  if ( KeyValues::SaveToFile(this: pKV, filesystem: v10, resourceName: "resource/roomthumbnails.txt", pathID: "GAME") )
  {
    KeyValues::deleteThis(this: v11);
    CMapLayout::SaveMapLayout(this: this->m_pMapLayout, filename: "maps/output.layout");
    if ( engine != nullptr )
    {
      V_snprintf(
        pDest: buffer,
        maxLen: 256,
        pFormat: "asw_random_weapons 0; asw_building_room_thumbnails 1; asw_add_room_thumbnails_to_perforce %d; asw_build_map %s",
        bAddToPerforce,
        "output.layout");
      engine->ClientCmd_Unrestricted(this: engine, a2: buffer);
    }
  }
  else
  {
    _Msg(a1: "Error: Couldn't save %s\n", "resource/roomthumbnails.txt");
    KeyValues::deleteThis(this: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100326A0
// Name: protected: virtual void CTileGenDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnCommand(CTileGenDialog *this, const char *command)
{
  CThemesDialog *v3; // eax
  CThemesDialog *v4; // edi
  vgui::MessageBox *v5; // eax
  vgui::MessageBox *v6; // eax
  vgui::MessageBox *v7; // eax
  CRoomTemplate *v8; // eax
  CRoomTemplate *v9; // edi
  CRoomTemplateEditDialog *v10; // eax
  vgui::MessageBox *v11; // eax
  vgui::MessageBox *v12; // eax
  CMapLayout *m_pMapLayout; // ecx
  CMapLayout *v14; // eax
  CMapLayout *v15; // ecx
  CMapLayout *v16; // eax
  CMapLayout *v17; // eax
  const char *v18; // eax
  vgui::MessageBox *v19; // eax
  vgui::MessageBox *v20; // eax
  vgui::MessageBox *v21; // esi
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  CLocation_Editor_Frame *v26; // eax
  CTile_Check_Frame *v27; // esi
  CTile_Check_Frame *v28; // eax
  CLayoutSystemKVEditor *m_pEditor; // edi
  bool IsChecked; // al
  CLayoutSystemKVEditor *v31; // edi
  bool v32; // al
  vgui::MessageBox *v33; // eax
  vgui::MessageBox *v34; // eax
  char buffer[512]; // [esp+Ch] [ebp-300h] BYREF
  char mapname[256]; // [esp+20Ch] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Themes") == 0 )
  {
    v3 = (CThemesDialog *)operator new(nSize: 0x220u);
    if ( v3 != nullptr )
      v4 = CThemesDialog::CThemesDialog(this: v3, parent: this, name: "ThemesDialog", bGlobal: true);
    else
      v4 = nullptr;
LABEL_5:
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    v4->DoModal(this: v4);
    vgui::Frame::OnCommand(this, command);
    return;
  }
  if ( _V_stricmp(s1: command, s2: "NewRoomTemplate") == 0 )
  {
    if ( CLevelTheme::s_pCurrentTheme == nullptr )
    {
      v5 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v5 != nullptr )
      {
        v6 = vgui::MessageBox::MessageBox(
               this: v5,
               title: "No theme selected",
               text: "You must select a theme before creating a new room template.",
               parent: this);
        v6->DoModal_2(this: v6, a2: nullptr);
        return;
      }
      goto LABEL_10;
    }
    v8 = (CRoomTemplate *)operator new(nSize: 0x588u);
    if ( v8 != nullptr )
    {
      v9 = CRoomTemplate::CRoomTemplate(this: v8, pLevelTheme: CLevelTheme::s_pCurrentTheme);
      if ( v9 != nullptr )
      {
        v10 = (CRoomTemplateEditDialog *)operator new(nSize: 0x268u);
        if ( v10 != nullptr )
          v4 = (CThemesDialog *)CRoomTemplateEditDialog::CRoomTemplateEditDialog(
                                  this: v10,
                                  parent: this,
                                  name: "RoomTemplateEditDialog",
                                  pRoomTemplate: v9,
                                  bCreatingNew: true);
        else
          v4 = nullptr;
        goto LABEL_5;
      }
    }
    goto LABEL_89;
  }
  if ( _V_stricmp(s1: command, s2: "ExportVMF") == 0 )
  {
    if ( !VMFExporter::ExportVMF(
            this: this->m_VMFExporter,
            pLayout: this->m_pMapLayout,
            mapname: "output.vmf",
            bPopupWarnings: true) )
    {
      v11 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v11 != nullptr )
      {
        v7 = vgui::MessageBox::MessageBox(
               this: v11,
               title: "VMF Export Error",
               text: this->m_VMFExporter->m_szLastExporterError,
               parent: this);
        goto LABEL_11;
      }
LABEL_10:
      v7 = nullptr;
LABEL_11:
      v7->DoModal_2(this: v7, a2: nullptr);
      return;
    }
    if ( !VMFExporter::ShowExportErrors(this: this->m_VMFExporter) )
    {
      v12 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v12 != nullptr )
      {
        v7 = vgui::MessageBox::MessageBox(
               this: v12,
               title: "VMF Export",
               text: "Output.vmf exported okay!",
               parent: this);
        goto LABEL_11;
      }
      goto LABEL_10;
    }
    return;
  }
  if ( _V_stricmp(s1: command, s2: "ExportAndPlay") != 0 && _V_stricmp(s1: command, s2: "ExportAndPlayClean") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "NewMapLayout") == 0 )
    {
      m_pMapLayout = this->m_pMapLayout;
      if ( m_pMapLayout != nullptr )
        ((void (__thiscall *)(CMapLayout *, int))m_pMapLayout->dtr_CMapLayout)(a1: m_pMapLayout, a2: 1);
      v14 = (CMapLayout *)operator new(nSize: 0xE264u);
      if ( v14 != nullptr )
        this->m_pMapLayout = CMapLayout::CMapLayout(this: v14, pGenerationOptions: nullptr);
      else
        this->m_pMapLayout = nullptr;
      return;
    }
    if ( _V_stricmp(s1: command, s2: "OpenMapLayout") == 0 )
    {
      CTileGenDialog::DoFileOpen(this);
      return;
    }
    if ( _V_stricmp(s1: command, s2: "OpenCurrentMapLayout") == 0 )
    {
      v15 = this->m_pMapLayout;
      if ( v15 != nullptr )
        ((void (__thiscall *)(CMapLayout *, int))v15->dtr_CMapLayout)(a1: v15, a2: 1);
      v16 = (CMapLayout *)operator new(nSize: 0xE264u);
      if ( v16 != nullptr )
        v17 = CMapLayout::CMapLayout(this: v16, pGenerationOptions: nullptr);
      else
        v17 = nullptr;
      this->m_pMapLayout = v17;
      v18 = engine->GetLevelNameShort(this: engine);
      V_snprintf(pDest: mapname, maxLen: 255, pFormat: "maps/%s.layout", v18);
      if ( !CMapLayout::LoadMapLayout(this: this->m_pMapLayout, filename: mapname) )
      {
        v19 = (vgui::MessageBox *)operator new(nSize: 0x234u);
        if ( v19 != nullptr )
        {
          v7 = vgui::MessageBox::MessageBox(this: v19, title: "Error", text: "Error loading map layout", parent: this);
          goto LABEL_11;
        }
        goto LABEL_10;
      }
      CMapLayoutPanel::CreateAllUIPanels(this: this->m_pLayoutPage->m_pMapLayoutPanel);
      return;
    }
    if ( _V_stricmp(s1: command, s2: "SaveMapLayout") == 0 )
    {
      if ( _V_strlen(str: this->m_pMapLayout->m_szFilename) > 0 )
      {
        CMapLayout::SaveMapLayout(this: this->m_pMapLayout, filename: this->m_pMapLayout->m_szFilename);
        return;
      }
    }
    else if ( _V_stricmp(s1: command, s2: "SaveMapLayoutAs") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "GenerateThumbnails") == 0 )
      {
        if ( p4 != nullptr )
        {
          v20 = (vgui::MessageBox *)operator new(nSize: 0x234u);
          if ( v20 != nullptr )
            v21 = vgui::MessageBox::MessageBox(
                    this: v20,
                    title: "Add to P4?",
                    text: "Would you like to add the thumbnails to perforce?",
                    parent: this);
          else
            v21 = nullptr;
          vgui::MessageBox::SetCancelButtonVisible(this: v21, state: true);
          v21->SetOKButtonText_2(this: v21, a2: "#MessageBox_Yes");
          vgui::MessageBox::SetCancelButtonText(this: v21, buttonText: "#MessageBox_No");
          v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v22 != nullptr )
            v23 = KeyValues::KeyValues(this: v22, setName: "AddToP4", firstKey: "add", firstValue: "1");
          else
            v23 = nullptr;
          v21->SetCommand(this: v21, a2: v23);
          v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v24 != nullptr )
            v25 = KeyValues::KeyValues(this: v24, setName: "AddToP4", firstKey: "add", firstValue: "0");
          else
            v25 = nullptr;
          vgui::MessageBox::SetCancelCommand(this: v21, command: v25);
          v21->DoModal_2(this: v21, a2: nullptr);
        }
        else
        {
          CTileGenDialog::GenerateRoomThumbnails(this, bAddToPerforce: false);
        }
        return;
      }
      if ( _V_stricmp(s1: command, s2: "PushEncountersApart") == 0 )
      {
        CASWMissionChooserNPCs::PushEncountersApart(pLayout: this->m_pMapLayout);
        vgui::Frame::OnCommand(this, command);
        return;
      }
      if ( _V_stricmp(s1: command, s2: "LocationLayoutEditor") != 0 )
      {
        if ( _V_stricmp(s1: command, s2: "ZoomIn") == 0 )
        {
          CTileGenDialog::Zoom(this, iChange: 10);
          return;
        }
        if ( _V_stricmp(s1: command, s2: "ZoomOut") == 0 )
        {
          CTileGenDialog::Zoom(this, iChange: -10);
          return;
        }
        if ( _V_stricmp(s1: command, s2: "TileCheck") != 0 )
        {
          if ( _V_stricmp(s1: command, s2: "ShowOptionalParameters") == 0 )
          {
            m_pEditor = this->m_pLayoutSystemPage->m_pEditor;
            IsChecked = vgui::Menu::IsChecked(
                          this: this->m_pToolsMenu,
                          itemID: this->m_nShowDefaultParametersMenuItemID);
            CLayoutSystemKVEditor::ShowOptionalValues(this: m_pEditor, bVisible: IsChecked);
            return;
          }
          if ( _V_stricmp(s1: command, s2: "ShowAddButtons") == 0 )
          {
            v31 = this->m_pLayoutSystemPage->m_pEditor;
            v32 = vgui::Menu::IsChecked(this: this->m_pToolsMenu, itemID: this->m_nShowAddButtonsMenuItemID);
            CLayoutSystemKVEditor::ShowAddButtons(this: v31, bVisible: v32);
            return;
          }
          goto LABEL_89;
        }
        v28 = (CTile_Check_Frame *)operator new(nSize: 0x228u);
        if ( v28 != nullptr )
        {
          v27 = CTile_Check_Frame::CTile_Check_Frame(this: v28, parent: this, name: "TileCheckFrame");
          goto LABEL_68;
        }
      }
      else
      {
        v26 = (CLocation_Editor_Frame *)operator new(nSize: 0x2CCu);
        if ( v26 != nullptr )
        {
          v27 = (CTile_Check_Frame *)CLocation_Editor_Frame::CLocation_Editor_Frame(
                                       this: v26,
                                       parent: this,
                                       name: "LocationEditorFrame");
LABEL_68:
          v27->MoveToCenterOfScreen(this: v27);
          v27->Activate(this: v27);
          return;
        }
      }
      v27 = nullptr;
      goto LABEL_68;
    }
    CTileGenDialog::DoFileSaveAs(this);
    return;
  }
  CMapLayout::SaveMapLayout(this: this->m_pMapLayout, filename: "maps/output.layout");
  if ( engine == nullptr )
  {
    v33 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v33 != nullptr )
      v34 = vgui::MessageBox::MessageBox(
              this: v33,
              title: "Map Exported",
              text: "To build and play map, enter into the console:\n\nasw_build_map output",
              parent: this);
    else
      v34 = nullptr;
    v34->DoModal_2(this: v34, a2: nullptr);
LABEL_89:
    vgui::Frame::OnCommand(this, command);
    return;
  }
  if ( _V_stricmp(s1: command, s2: "ExportAndPlayClean") != 0 )
    V_snprintf(
      pDest: buffer,
      maxLen: 512,
      pFormat: "asw_random_weapons 1; asw_director_spawn_npcs 1;  asw_spawner_spawn_npcs 1; asw_director_spawn_inview 1; asw_build_map %s",
      "output.layout");
  else
    V_snprintf(
      pDest: buffer,
      maxLen: 512,
      pFormat: "asw_random_weapons 0; asw_director_spawn_npcs 0;  asw_spawner_spawn_npcs 0; asw_build_map %s",
      "output.layout");
  engine->ClientCmd_Unrestricted(this: engine, a2: buffer);
  vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10032DF0
// Name: public: virtual void CTileGenDialog::OnAddToP4(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnAddToP4(CTileGenDialog *this, KeyValues *pKV)
{
  int Int; // eax

  Int = KeyValues::GetInt(this: pKV, keyName: "add", defaultValue: 0);
  CTileGenDialog::GenerateRoomThumbnails(this, bAddToPerforce: Int != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10032E20
// Name: public: void CUtlVector<class CRoom __near *,class CUtlMemory<class CRoom __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CRoom *,CUtlMemory<CRoom *,int>>::PurgeAndDeleteElements(
        CUtlVector<CRoom *,CUtlMemory<CRoom *,int> > *this)
{
  int i; // edi
  CRoom *v3; // ecx
  bool v4; // sf
  CRoom **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CRoom *, int))v3->dtr_CRoom)(a1: v3, a2: 1);
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
// Address: 0x10032E90
// Name: public: virtual CTileGenDialog::~CTileGenDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::~CTileGenDialog(CTileGenDialog *this)
{
  VMFExporter *m_VMFExporter; // ecx
  CMapLayout *m_pMapLayout; // ecx
  CLayoutSystem *m_pLayoutSystem; // edi

  this->__vftable = (CTileGenDialog_vtbl *)&CTileGenDialog::`vftable';
  g_pTileGenDialog = nullptr;
  m_VMFExporter = this->m_VMFExporter;
  if ( m_VMFExporter != nullptr )
    ((void (__thiscall *)(VMFExporter *, int))m_VMFExporter->dtr_VMFExporter)(a1: m_VMFExporter, a2: 1);
  m_pMapLayout = this->m_pMapLayout;
  if ( m_pMapLayout != nullptr )
    ((void (__thiscall *)(CMapLayout *, int))m_pMapLayout->dtr_CMapLayout)(a1: m_pMapLayout, a2: 1);
  KeyValues::deleteThis(this: this->m_pGenerationOptions);
  m_pLayoutSystem = this->m_pLayoutSystem;
  if ( m_pLayoutSystem != nullptr )
  {
    CLayoutSystem::~CLayoutSystem(this: this->m_pLayoutSystem);
    free(pMem: m_pLayoutSystem);
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SelectedRooms);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10032F10
// Name: public: virtual struct vgui::PanelMessageMap __near * CTileGenDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTileGenDialog::GetMessageMap(CTileGenDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTileGenDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTileGenDialog::GetMessageMap'::`2'::s_pMap;
  `CTileGenDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTileGenDialog");
  `CTileGenDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032F40
// Name: public: virtual struct PanelAnimationMap __near * CTileGenDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTileGenDialog::GetAnimMap(CTileGenDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CTileGenDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10032F50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTileGenDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTileGenDialog::GetKBMap(CTileGenDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTileGenDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTileGenDialog::GetKBMap'::`2'::s_pMap;
  `CTileGenDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTileGenDialog");
  `CTileGenDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032F80
// Name: public: virtual void CTileGenDialog::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnTick(CTileGenDialog *this)
{
  vgui::AnimationController *AnimationController; // eax
  CScrollingWindow *m_pScrollingWindow; // eax
  vgui::Panel *m_pView; // ecx
  vgui::Panel *v5; // esi
  float m_fTileSize; // xmm1_4
  int Tall; // eax
  CTileGenLayoutPage *m_pLayoutPage; // eax
  int m_iStartDragX; // edx
  int m_Size; // ecx
  bool v11; // al
  int v12; // edx
  CRoom *v13; // edx
  const CRoomTemplate *m_pRoomTemplate; // ecx
  int m_nTilesX; // ebx
  int v16; // esi
  int m_nTilesY; // ecx
  CRoom **v18; // ebx
  int v19; // edx
  int v20; // eax
  CRoom **m_pMemory; // ecx
  int v22; // ebx
  CRoom **v23; // eax
  CRoom *v24; // esi
  int v25; // edx
  vgui::Panel *m_pPlacedRoomPanel; // esi
  void *v27; // eax
  CTileGenLayoutPage *v28; // esi
  CMapLayout *m_pMapLayout; // ecx
  CRoom *v30; // ecx
  CLayoutSystem *m_pLayoutSystem; // ecx
  float currentTime; // [esp+0h] [ebp-218h]
  char roomName[260]; // [esp+10h] [ebp-208h] BYREF
  char coordinateString[200]; // [esp+114h] [ebp-104h] BYREF
  int v35; // [esp+1DCh] [ebp-3Ch]
  int v36; // [esp+1E0h] [ebp-38h]
  int nMouseX; // [esp+1E4h] [ebp-34h] BYREF
  int nMouseY; // [esp+1E8h] [ebp-30h] BYREF
  const CRoomTemplate *v39; // [esp+1ECh] [ebp-2Ch]
  int ydiff; // [esp+1F0h] [ebp-28h]
  int y; // [esp+1F4h] [ebp-24h]
  int iTileY; // [esp+1F8h] [ebp-20h] BYREF
  CRoom *pRoom; // [esp+1FCh] [ebp-1Ch]
  int i; // [esp+200h] [ebp-18h]
  int x; // [esp+204h] [ebp-14h]
  int xdiff; // [esp+208h] [ebp-10h]
  int nTileY; // [esp+20Ch] [ebp-Ch] BYREF
  int nTileX; // [esp+210h] [ebp-8h] BYREF
  bool bCollision; // [esp+217h] [ebp-1h]

  currentTime = _Plat_FloatTime();
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime);
  if ( this->m_pCursorTemplate == nullptr )
    goto LABEL_10;
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &nTileY, a3: &nTileX);
  m_pScrollingWindow = this->m_pLayoutPage->m_pScrollingWindow;
  if ( m_pScrollingWindow != nullptr
    && m_pScrollingWindow->m_pView != nullptr
    && vgui::PHandle::Get(this: &m_pScrollingWindow->m_hChildPanel) != nullptr )
  {
    m_pView = this->m_pLayoutPage->m_pScrollingWindow->m_pView;
    if ( m_pView->IsCursorOver(this: m_pView) )
    {
      this->m_pCursorPanel->SetVisible(this: this->m_pCursorPanel, a2: true);
      v5 = vgui::PHandle::Get(this: &this->m_pLayoutPage->m_pScrollingWindow->m_hChildPanel);
      vgui::Panel::ScreenToLocal(this: v5, x: &nTileY, y: &nTileX);
      m_fTileSize = this->m_fTileSize;
      nTileY = (int)(float)((float)(int)(float)((float)nTileY * (float)(1.0 / m_fTileSize)) * m_fTileSize);
      nTileX = (int)(float)((float)(int)(float)((float)((float)nTileX * (float)(1.0 / m_fTileSize)) + 1.0) * m_fTileSize);
      vgui::Panel::LocalToScreen(this: v5, x: &nTileY, y: &nTileX);
      vgui::Panel::ScreenToLocal(this, x: &nTileY, y: &nTileX);
      Tall = vgui::Panel::GetTall(this: this->m_pCursorPanel);
      nTileX -= Tall;
      vgui::Panel::SetPos(this: this->m_pCursorPanel, x: nTileY, y: nTileX);
      this->m_pCursorPanel->InvalidateLayout(this: this->m_pCursorPanel, a2: false, a3: false);
LABEL_9:
      this->Repaint(this);
      goto LABEL_10;
    }
  }
  if ( this->m_pCursorPanel->IsVisible(this: this->m_pCursorPanel) )
  {
    this->m_pCursorPanel->SetVisible(this: this->m_pCursorPanel, a2: false);
    goto LABEL_9;
  }
LABEL_10:
  if ( this->m_iStartDragX != -1 )
  {
    if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    {
      this->m_iStartDragX = -1;
      this->m_iStartDragY = -1;
      goto LABEL_48;
    }
    m_pLayoutPage = this->m_pLayoutPage;
    nTileX = 0;
    iTileY = 0;
    CMapLayoutPanel::GetCursorTile(this: m_pLayoutPage->m_pMapLayoutPanel, tilex: &nTileX, tiley: &iTileY);
    m_iStartDragX = this->m_iStartDragX;
    if ( nTileX != m_iStartDragX || iTileY != this->m_iStartDragY )
    {
      ydiff = iTileY - this->m_iStartDragY;
      m_Size = this->m_SelectedRooms.m_Size;
      xdiff = nTileX - m_iStartDragX;
      v11 = false;
      v12 = 0;
      bCollision = false;
      nTileY = m_Size;
      i = 0;
      if ( m_Size <= 0 )
        goto LABEL_41;
      while ( 1 )
      {
        if ( v11 )
          goto LABEL_48;
        v13 = this->m_SelectedRooms.m_Memory.m_pMemory[v12];
        pRoom = v13;
        if ( v13 == nullptr )
          goto LABEL_48;
        m_pRoomTemplate = v13->m_pRoomTemplate;
        v39 = m_pRoomTemplate;
        if ( m_pRoomTemplate == nullptr )
          goto LABEL_48;
        m_nTilesX = m_pRoomTemplate->m_nTilesX;
        v16 = 0;
        x = 0;
        v36 = m_nTilesX;
        if ( m_nTilesX <= 0 )
          goto LABEL_38;
LABEL_22:
        if ( v11 )
          goto LABEL_38;
        m_nTilesY = m_pRoomTemplate->m_nTilesY;
        y = 0;
        v35 = m_nTilesY;
        if ( m_nTilesY <= 0 )
          goto LABEL_37;
        v18 = &this->m_pMapLayout->m_pRoomGrid[xdiff][120 * v16] + 120 * v13->m_iPosX + ydiff + v13->m_iPosY;
        while ( *v18 == nullptr )
        {
LABEL_33:
          ++v18;
          if ( ++y >= m_nTilesY )
            goto LABEL_36;
        }
        v19 = this->m_SelectedRooms.m_Size;
        v20 = 0;
        if ( v19 <= 0 )
        {
LABEL_30:
          v20 = -1;
        }
        else
        {
          m_pMemory = this->m_SelectedRooms.m_Memory.m_pMemory;
          while ( *m_pMemory != *v18 )
          {
            ++v20;
            ++m_pMemory;
            if ( v20 >= v19 )
              goto LABEL_30;
          }
        }
        if ( v20 != -1 )
          break;
        bCollision = true;
LABEL_36:
        v13 = pRoom;
LABEL_37:
        v11 = bCollision;
        v16 = x + 1;
        x = v16;
        if ( v16 < v36 )
        {
          m_pRoomTemplate = v39;
          goto LABEL_22;
        }
LABEL_38:
        v12 = i + 1;
        i = v12;
        if ( v12 >= nTileY )
        {
          if ( !v11 )
          {
            m_Size = nTileY;
LABEL_41:
            v22 = 0;
            if ( m_Size > 0 )
            {
              do
              {
                v23 = this->m_SelectedRooms.m_Memory.m_pMemory;
                v24 = v23[v22];
                if ( v24 != nullptr )
                {
                  CMapLayout::RemoveRoom(this: this->m_pMapLayout, pRoom: v23[v22]);
                  v25 = ydiff;
                  v24->m_iPosX += xdiff;
                  v24->m_iPosY += v25;
                  CMapLayout::PlaceRoom(this: this->m_pMapLayout, pRoom: v24);
                  m_pPlacedRoomPanel = v24->m_pPlacedRoomPanel;
                  if ( m_pPlacedRoomPanel != nullptr )
                  {
                    v27 = __RTDynamicCast(
                            inptr: m_pPlacedRoomPanel,
                            VfDelta: 0,
                            SrcType: &vgui::Panel `RTTI Type Descriptor',
                            TargetType: &CPlacedRoomTemplatePanel `RTTI Type Descriptor',
                            isReference: 0);
                    if ( v27 != nullptr )
                      (*(void (__thiscall **)(void *))(*(_DWORD *)v27 + 844))(a1: v27);
                  }
                }
                ++v22;
              }
              while ( v22 < nTileY );
            }
            this->Repaint(this);
            CMapLayoutPanel::GetCursorTile(
              this: this->m_pLayoutPage->m_pMapLayoutPanel,
              tilex: &this->m_iStartDragX,
              tiley: &this->m_iStartDragY);
          }
          goto LABEL_48;
        }
      }
      m_nTilesY = v35;
      goto LABEL_33;
    }
  }
LABEL_48:
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &nMouseX, a3: &nMouseY);
  if ( vgui::Panel::IsWithin(this: this->m_pLayoutPage->m_pMapLayoutPanel, x: nMouseX, y: nMouseY)
    && (v28 = this->m_pLayoutPage, this->m_pPropertySheet->GetActivePage(this: this->m_pPropertySheet) == v28) )
  {
    nTileX = 0;
    nTileY = 0;
    CMapLayoutPanel::GetCursorTile(this: v28->m_pMapLayoutPanel, tilex: &nTileX, tiley: &nTileY);
    m_pMapLayout = this->m_pMapLayout;
    if ( m_pMapLayout != nullptr
      && nTileX >= 0
      && nTileY >= 0
      && nTileX < 120
      && nTileY < 120
      && (v30 = m_pMapLayout->m_pRoomGrid[nTileX][nTileY]) != nullptr )
    {
      v30->GetFullRoomName(this: v30, a2: roomName, a3: 260);
      V_snprintf(pDest: coordinateString, maxLen: 200, pFormat: "(%d, %d) - %s", nTileX, nTileY, roomName);
    }
    else
    {
      V_snprintf(pDest: coordinateString, maxLen: 200, pFormat: "(%d, %d)", nTileX, nTileY);
    }
  }
  else
  {
    coordinateString[0] = 0;
  }
  this->m_pCoordinateLabel->SetText(this: this->m_pCoordinateLabel, a2: coordinateString);
  m_pLayoutSystem = this->m_pLayoutSystem;
  if ( m_pLayoutSystem != nullptr && m_pLayoutSystem->m_bGenerating )
  {
    CLayoutSystem::ExecuteIteration(this: m_pLayoutSystem);
    CMapLayoutPanel::CreateAllUIPanels(this: this->m_pLayoutPage->m_pMapLayoutPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100334C0
// Name: public: virtual void CTileGenDialog::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::OnKeyCodeTyped(CTileGenDialog *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE )
  {
    if ( this->m_SelectedRooms.m_Size > 0 )
    {
      CUtlVector<CRoom *,CUtlMemory<CRoom *,int>>::PurgeAndDeleteElements(this: &this->m_SelectedRooms);
      this->Repaint(this);
    }
  }
  else if ( code == KEY_SPACE )
  {
    g_bProcessGenerator = true;
  }
  else
  {
    vgui::Frame::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033510
// Name: public: static void CTileGenDialog::PanelMessageFunc_OnUpdateCurrentTheme::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTileGenDialog::PanelMessageFunc_OnUpdateCurrentTheme::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CTileGenDialog::PanelMessageFunc_OnUpdateCurrentTheme::InitVar'::`2'::bAdded )
  {
    `CTileGenDialog::PanelMessageFunc_OnUpdateCurrentTheme::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CTileGenDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "UpdateCurrentTheme";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100335A0
// Name: public: static void CTileGenDialog::PanelMessageFunc_OnAddToP4::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTileGenDialog::PanelMessageFunc_OnAddToP4::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CTileGenDialog::PanelMessageFunc_OnAddToP4::InitVar'::`2'::bAdded )
  {
    `CTileGenDialog::PanelMessageFunc_OnAddToP4::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CTileGenDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "AddToP4";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033630
// Name: public: static void CTileGenDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTileGenDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CTileGenDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CTileGenDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CTileGenDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100336D0
// Name: public: static void CTileGenDialog::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTileGenDialog::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CTileGenDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CTileGenDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CTileGenDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033770
// Name: public: CTileGenDialog::CTileGenDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTileGenDialog *__thiscall CTileGenDialog::CTileGenDialog(
        CTileGenDialog *this,
        vgui::Panel *parent,
        vgui::MenuButton *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Menu *v7; // edi
  CMapLayout *v8; // eax
  CMapLayout *v9; // eax
  VMFExporter *v10; // eax
  VMFExporter *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  unsigned int v14; // eax
  CThemeDetails *v15; // eax
  CThemeDetails *v16; // eax
  CScrollingWindow *v17; // eax
  CScrollingWindow *v18; // eax
  CRoomTemplateListPanel *v19; // eax
  CRoomTemplateListPanel *v20; // eax
  vgui::TextEntry *v21; // eax
  vgui::TextEntry *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  BOOL m_bShowExits; // ecx
  vgui::CheckButton *v26; // eax
  vgui::CheckButton *v27; // eax
  BOOL m_bShowTileSquares; // ecx
  vgui::PropertySheet *v29; // eax
  vgui::PropertySheet *v30; // eax
  CTileGenLayoutPage *v31; // eax
  CTileGenLayoutPage *v32; // eax
  CTilegenLayoutSystemPage *v33; // eax
  CTilegenLayoutSystemPage *v34; // eax
  CRoomTemplatePanel *v35; // eax
  CRoomTemplatePanel *v36; // eax
  CScrollingWindow *m_pTemplateListContainer; // ecx
  vgui::MenuBar *v38; // eax
  vgui::MenuBar *v39; // eax
  vgui::MenuButton *v40; // eax
  vgui::MenuButton *v41; // ebx
  vgui::Menu *v42; // eax
  vgui::MenuButton *v43; // eax
  vgui::MenuButton *v44; // ebx
  vgui::Menu *v45; // eax
  vgui::Menu *v46; // eax
  int v47; // eax
  vgui::Menu *m_pToolsMenu; // ecx
  int v49; // eax
  vgui::Menu *v50; // ecx
  vgui::Button *v51; // eax
  vgui::Button *v52; // eax
  vgui::Button *v53; // eax
  vgui::Button *v54; // eax
  vgui::Label *v55; // eax
  vgui::Label *v56; // eax
  int m_nShowDefaultParametersMenuItemID; // [esp-8h] [ebp-14h]
  CRoomTemplateListPanel *m_pTemplateListPanel; // [esp-4h] [ebp-10h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  vgui::MenuButton *pFileMenuButton; // [esp+18h] [ebp+Ch]

  vgui::Frame::Frame(this, parent, panelName: (const char *)name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CTileGenDialog_vtbl *)&CTileGenDialog::`vftable';
  if ( `CTileGenDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CTileGenDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CTileGenDialog");
    v4->pfnClassName = CTileGenDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `CTileGenDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTileGenDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CTileGenDialog");
    v5->pfnClassName = CTileGenDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `CTileGenDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTileGenDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CTileGenDialog");
    v6->pfnClassName = CTileGenDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  v7 = nullptr;
  this->m_SelectedRooms.m_Memory.m_pMemory = nullptr;
  this->m_SelectedRooms.m_Memory.m_nAllocationCount = 0;
  this->m_SelectedRooms.m_Memory.m_nGrowSize = 0;
  this->m_SelectedRooms.m_Size = 0;
  this->m_SelectedRooms.m_pElements = nullptr;
  CTileGenDialog::PanelMessageFunc_OnUpdateCurrentTheme::InitVar(a1: (int)&savedregs);
  CTileGenDialog::PanelMessageFunc_OnAddToP4::InitVar(a1: (int)&savedregs);
  CTileGenDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CTileGenDialog::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  g_pTileGenDialog = this;
  v8 = (CMapLayout *)operator new(nSize: 0xE264u);
  if ( v8 != nullptr )
    v9 = CMapLayout::CMapLayout(this: v8, pGenerationOptions: nullptr);
  else
    v9 = nullptr;
  this->m_pMapLayout = v9;
  this->m_pLayoutSystem = nullptr;
  v10 = (VMFExporter *)operator new(nSize: 0x1BCu);
  if ( v10 != nullptr )
    v11 = VMFExporter::VMFExporter(this: v10);
  else
    v11 = nullptr;
  this->m_VMFExporter = v11;
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "EmptyOptions");
  else
    v13 = nullptr;
  this->m_pGenerationOptions = v13;
  v14 = g_pVGuiSchemeManager->LoadSchemeFromFile(
          this: g_pVGuiSchemeManager,
          a2: "tilegen/tilegen_scheme.res",
          a3: "TileGen");
  vgui::Panel::SetScheme(this, scheme: v14);
  if ( !g_bAddedTileGenLocalization )
  {
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "tilegen/tilegen_english.txt", a3: nullptr, a4: false);
    g_bAddedTileGenLocalization = true;
  }
  this->m_fTileSize = 30.0;
  *(_WORD *)&this->m_bShowExits = 257;
  this->m_iStartDragX = -1;
  this->m_iStartDragY = -1;
  this->m_iStartRubberBandX = -1;
  vgui::Panel::SetSize(this, wide: 384, tall: 420);
  vgui::Panel::SetMinimumSize(this, wide: 384, tall: 420);
  v15 = (CThemeDetails *)operator new(nSize: 0x170u);
  if ( v15 != nullptr )
    v16 = CThemeDetails::CThemeDetails(this: v15, parent: this, name: "CurrentThemeDetails", pThemesDialog: nullptr);
  else
    v16 = nullptr;
  this->m_pCurrentThemeDetails = v16;
  v16->m_iDesiredWidth = 356;
  v17 = (CScrollingWindow *)operator new(nSize: 0x168u);
  if ( v17 != nullptr )
    v18 = CScrollingWindow::CScrollingWindow(this: v17, parent: this, name: "TemplateListWindow");
  else
    v18 = nullptr;
  this->m_pTemplateListContainer = v18;
  v19 = (CRoomTemplateListPanel *)operator new(nSize: 0x288u);
  if ( v19 != nullptr )
    v20 = CRoomTemplateListPanel::CRoomTemplateListPanel(
            this: v19,
            parent: this->m_pTemplateListContainer,
            name: "TemplateListPanel");
  else
    v20 = nullptr;
  this->m_pTemplateListPanel = v20;
  v21 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v21 != nullptr )
    v22 = vgui::TextEntry::TextEntry(this: v21, parent: this, panelName: "TemplateFilter");
  else
    v22 = nullptr;
  this->m_pTemplateFilter = v22;
  v23 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(this: v23, parent: this, panelName: "ShowExitsCheck", text: szDescription);
  else
    v24 = nullptr;
  m_bShowExits = this->m_bShowExits;
  this->m_pShowExitsCheck = v24;
  v24->SetSelected(this: v24, a2: m_bShowExits);
  v26 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v26 != nullptr )
    v27 = vgui::CheckButton::CheckButton(
            this: v26,
            parent: this,
            panelName: "ShowTileSquaresCheck",
            text: szDescription);
  else
    v27 = nullptr;
  m_bShowTileSquares = this->m_bShowTileSquares;
  this->m_pShowTileSquaresCheck = v27;
  v27->SetSelected(this: v27, a2: m_bShowTileSquares);
  v29 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v29 != nullptr )
    v30 = vgui::PropertySheet::PropertySheet(this: v29, parent: this, panelName: "PropertySheet", draggableTabs: false);
  else
    v30 = nullptr;
  this->m_pPropertySheet = v30;
  v31 = (CTileGenLayoutPage *)operator new(nSize: 0x188u);
  if ( v31 != nullptr )
    v32 = CTileGenLayoutPage::CTileGenLayoutPage(this: v31, parent: this->m_pPropertySheet, name: "TileGenLayoutPage");
  else
    v32 = nullptr;
  this->m_pLayoutPage = v32;
  v33 = (CTilegenLayoutSystemPage *)operator new(nSize: 0x2B8u);
  if ( v33 != nullptr )
    v34 = CTilegenLayoutSystemPage::CTilegenLayoutSystemPage(
            this: v33,
            pParent: this->m_pPropertySheet,
            pName: "TilegenLayoutSystemPage");
  else
    v34 = nullptr;
  this->m_pLayoutSystemPage = v34;
  v34->UpdateList(this: v34);
  this->m_pPropertySheet->AddPage(
    this: this->m_pPropertySheet,
    a2: this->m_pLayoutPage,
    a3: "Layout",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pPropertySheet->AddPage(
    this: this->m_pPropertySheet,
    a2: this->m_pLayoutSystemPage,
    a3: "Missions",
    a4: nullptr,
    a5: false,
    a6: -1);
  v35 = (CRoomTemplatePanel *)operator new(nSize: 0x19Cu);
  if ( v35 != nullptr )
    v36 = CRoomTemplatePanel::CRoomTemplatePanel(this: v35, parent: this, name: "CursorRoomTemplatePanel");
  else
    v36 = nullptr;
  this->m_pCursorPanel = v36;
  v36->SetMouseInputEnabled(this: v36, a2: false);
  this->m_pCursorPanel->SetVisible(this: this->m_pCursorPanel, a2: false);
  m_pTemplateListPanel = this->m_pTemplateListPanel;
  m_pTemplateListContainer = this->m_pTemplateListContainer;
  this->m_pCursorTemplate = nullptr;
  CScrollingWindow::SetChildPanel(this: m_pTemplateListContainer, pPanel: m_pTemplateListPanel);
  CLevelTheme::LoadLevelThemes();
  CTileGenDialog::OnUpdateCurrentTheme(this, params: nullptr);
  v38 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v38 != nullptr )
    v39 = vgui::MenuBar::MenuBar(this: v38, parent: this, panelName: "TileGenMenuBar");
  else
    v39 = nullptr;
  this->m_pMenuBar = v39;
  v40 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v40 != nullptr )
  {
    v41 = vgui::MenuButton::MenuButton(this: v40, parent: this, panelName: "FileMenuButton", text: "&File");
    pFileMenuButton = v41;
  }
  else
  {
    pFileMenuButton = nullptr;
    v41 = nullptr;
  }
  v42 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v42 != nullptr )
    v7 = vgui::Menu::Menu(this: v42, parent: v41, panelName: "TileGenFileMenu");
  v7->AddMenuItem(this: v7, a2: "&New Map Layout", a3: "NewMapLayout", a4: this, a5: nullptr);
  v7->AddMenuItem(this: v7, a2: "&Open Map Layout...", a3: "OpenMapLayout", a4: this, a5: nullptr);
  v7->AddMenuItem(this: v7, a2: "&Open Current Map Layout...", a3: "OpenCurrentMapLayout", a4: this, a5: nullptr);
  v7->AddMenuItem(this: v7, a2: "&Save Map Layout", a3: "SaveMapLayout", a4: this, a5: nullptr);
  v7->AddMenuItem(this: v7, a2: "&Save Map Layout As...", a3: "SaveMapLayoutAs", a4: this, a5: nullptr);
  v7->AddSeparator(this: v7);
  v7->AddMenuItem(this: v7, a2: "&Export VMF", a3: "ExportVMF", a4: this, a5: nullptr);
  v7->AddMenuItem(this: v7, a2: "&Export VMF and Play Map", a3: "ExportAndPlay", a4: this, a5: nullptr);
  v7->AddMenuItem(this: v7, a2: "&Export VMF and Play Without Aliens", a3: "ExportAndPlayClean", a4: this, a5: nullptr);
  v41->SetMenu(this: v41, a2: v7);
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: v41);
  v43 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v43 != nullptr )
    v44 = vgui::MenuButton::MenuButton(this: v43, parent: this, panelName: "ToolsMenuButton", text: "&Tools");
  else
    v44 = nullptr;
  v45 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v45 != nullptr )
    v46 = vgui::Menu::Menu(this: v45, parent: v44, panelName: "TileGenToolsMenu");
  else
    v46 = nullptr;
  this->m_pToolsMenu = v46;
  v44->SetMenu(this: v44, a2: v46);
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: v44);
  this->m_pToolsMenu->AddMenuItem(
    this: this->m_pToolsMenu,
    a2: "Generate &Thumbnails",
    a3: "GenerateThumbnails",
    a4: this,
    a5: nullptr);
  this->m_pToolsMenu->AddMenuItem(
    this: this->m_pToolsMenu,
    a2: "&Location Layout Editor",
    a3: "LocationLayoutEditor",
    a4: this,
    a5: nullptr);
  this->m_pToolsMenu->AddMenuItem(
    this: this->m_pToolsMenu,
    a2: "&Check Room Templates for Errors",
    a3: "TileCheck",
    a4: this,
    a5: nullptr);
  this->m_pToolsMenu->AddSeparator(this: this->m_pToolsMenu);
  v47 = this->m_pToolsMenu->AddCheckableMenuItem(
          this: this->m_pToolsMenu,
          a2: "&Show Optional Parameters",
          a3: "ShowOptionalParameters",
          a4: this,
          a5: nullptr);
  m_pToolsMenu = this->m_pToolsMenu;
  this->m_nShowDefaultParametersMenuItemID = v47;
  v49 = m_pToolsMenu->AddCheckableMenuItem(
          this: m_pToolsMenu,
          a2: "&Show 'Add' Buttons",
          a3: "ShowAddButtons",
          a4: this,
          a5: nullptr);
  m_nShowDefaultParametersMenuItemID = this->m_nShowDefaultParametersMenuItemID;
  v50 = this->m_pToolsMenu;
  this->m_nShowAddButtonsMenuItemID = v49;
  vgui::Menu::SetMenuItemChecked(this: v50, itemID: m_nShowDefaultParametersMenuItemID, state: true);
  vgui::Menu::SetMenuItemChecked(this: this->m_pToolsMenu, itemID: this->m_nShowAddButtonsMenuItemID, state: true);
  CLayoutSystemKVEditor::ShowOptionalValues(this: this->m_pLayoutSystemPage->m_pEditor, bVisible: true);
  CLayoutSystemKVEditor::ShowAddButtons(this: this->m_pLayoutSystemPage->m_pEditor, bVisible: true);
  pFileMenuButton->SetKeyBoardInputEnabled(this: pFileMenuButton, a2: false);
  v7->SetKeyBoardInputEnabled(this: v7, a2: false);
  this->m_pMenuBar->SetKeyBoardInputEnabled(this: this->m_pMenuBar, a2: false);
  v51 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v51 != nullptr )
    v52 = vgui::Button::Button(
            this: v51,
            parent: this,
            panelName: "ZoomInButton",
            text: "+",
            pActionSignalTarget: this,
            pCmd: "ZoomIn");
  else
    v52 = nullptr;
  this->m_pZoomInButton = v52;
  v53 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v53 != nullptr )
    v54 = vgui::Button::Button(
            this: v53,
            parent: this,
            panelName: "ZoomOutButton",
            text: "-",
            pActionSignalTarget: this,
            pCmd: "ZoomOut");
  else
    v54 = nullptr;
  this->m_pZoomOutButton = v54;
  v55 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v55 != nullptr )
    v56 = vgui::Label::Label(this: v55, parent: this, panelName: "CoordinateLabel", text: szDescription);
  else
    v56 = nullptr;
  this->m_pCoordinateLabel = v56;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10033FB0
// Name: public: void CTileGenDialog::ToggleRoomSelection(class CRoom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::ToggleRoomSelection(CTileGenDialog *this, CRoom *pRoom)
{
  CRoom *v2; // ebx
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *p_m_SelectedRooms; // esi
  int m_Size; // ecx
  int v5; // eax
  CRoom **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v8; // edi
  vgui::TreeNode **v9; // ecx
  int v10; // eax
  CRoom **v11; // eax

  v2 = pRoom;
  p_m_SelectedRooms = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_SelectedRooms;
  m_Size = this->m_SelectedRooms.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_5;
  m_pMemory = (CRoom **)p_m_SelectedRooms->m_Memory.m_pMemory;
  while ( *m_pMemory != pRoom )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      goto LABEL_5;
  }
  if ( v5 == -1 )
  {
LABEL_5:
    m_nAllocationCount = p_m_SelectedRooms->m_Memory.m_nAllocationCount;
    v8 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: &p_m_SelectedRooms->m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_SelectedRooms->m_Size;
    v9 = p_m_SelectedRooms->m_Memory.m_pMemory;
    v10 = p_m_SelectedRooms->m_Size - v8 - 1;
    p_m_SelectedRooms->m_pElements = p_m_SelectedRooms->m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &v9[v8 + 1], src: &v9[v8], count: 4 * v10);
    v11 = (CRoom **)&p_m_SelectedRooms->m_Memory.m_pMemory[v8];
    if ( v11 != nullptr )
      *v11 = v2;
  }
  else
  {
    CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
      this: p_m_SelectedRooms,
      src: (vgui::TreeNode *const *)&pRoom);
  }
  v2->m_pPlacedRoomPanel->InvalidateLayout(this: v2->m_pPlacedRoomPanel, a2: true, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10034060
// Name: public: void CTileGenDialog::ClearRoomSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::ClearRoomSelection(CTileGenDialog *this)
{
  int m_nAllocationCount; // edx
  int m_Size; // edi
  CRoom **m_pMemory; // ebx
  int v4; // esi
  int v5; // eax
  int v6; // edi
  CRoom **v7; // edi
  int v8; // esi
  vgui::Panel *m_pPlacedRoomPanel; // ecx
  CUtlVector<CRoom *,CUtlMemory<CRoom *,int> > m_PreviouslySelectedRooms; // [esp+Ch] [ebp-24h] BYREF
  CRoom **v11; // [esp+20h] [ebp-10h]
  int iRooms; // [esp+24h] [ebp-Ch]
  CTileGenDialog *v13; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  m_nAllocationCount = 0;
  m_Size = this->m_SelectedRooms.m_Size;
  m_pMemory = nullptr;
  v4 = 0;
  v5 = 0;
  v13 = this;
  memset(&m_PreviouslySelectedRooms, 0, sizeof(m_PreviouslySelectedRooms));
  iRooms = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v11 = &this->m_SelectedRooms.m_Memory.m_pMemory[v5];
      v6 = v4;
      if ( v4 + 1 > m_nAllocationCount )
      {
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&m_PreviouslySelectedRooms,
          num: v4 - m_nAllocationCount + 1);
        v4 = m_PreviouslySelectedRooms.m_Size;
        m_pMemory = m_PreviouslySelectedRooms.m_Memory.m_pMemory;
      }
      m_PreviouslySelectedRooms.m_Size = ++v4;
      m_PreviouslySelectedRooms.m_pElements = m_pMemory;
      if ( v4 - v6 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (v4 - v6 - 1));
      v7 = &m_pMemory[v6];
      if ( v7 != nullptr )
        *v7 = *v11;
      m_Size = iRooms;
      this = v13;
      v5 = i + 1;
      i = v5;
      if ( v5 >= iRooms )
        break;
      m_nAllocationCount = m_PreviouslySelectedRooms.m_Memory.m_nAllocationCount;
    }
  }
  v8 = 0;
  this->m_SelectedRooms.m_Size = 0;
  if ( m_Size > 0 )
  {
    do
    {
      m_pPlacedRoomPanel = m_pMemory[v8]->m_pPlacedRoomPanel;
      if ( m_pPlacedRoomPanel != nullptr )
        m_pPlacedRoomPanel->InvalidateLayout(this: m_pPlacedRoomPanel, a2: true, a3: true);
      ++v8;
    }
    while ( v8 < iRooms );
  }
  if ( m_PreviouslySelectedRooms.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10034160
// Name: public: void CTileGenDialog::EndRubberBandSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::EndRubberBandSelection(CTileGenDialog *this, int mx, int my)
{
  float v4; // xmm0_4
  int v5; // edx
  int v6; // edi
  float v7; // xmm1_4
  int v8; // eax
  CRoom *v9; // eax
  int m_iPosX; // ecx
  const CRoomTemplate *m_pRoomTemplate; // edx
  int m_iPosY; // ecx
  int iRooms; // [esp+Ch] [ebp-10h]
  int *p_m_iStartRubberBandX; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int iStartTileX; // [esp+18h] [ebp-4h]
  int iEndTileX; // [esp+24h] [ebp+8h]
  int iEndTileY; // [esp+28h] [ebp+Ch]

  CTileGenDialog::ClearRoomSelection(this);
  v4 = 1.0 / this->m_fTileSize;
  p_m_iStartRubberBandX = &this->m_iStartRubberBandX;
  v5 = (int)(float)((float)mx * v4);
  v6 = 119 - (int)(float)((float)this->m_iStartRubberBandY * v4);
  v7 = (float)my * v4;
  iStartTileX = (int)(float)((float)this->m_iStartRubberBandX * v4);
  iEndTileX = v5;
  iEndTileY = 119 - (int)v7;
  if ( iStartTileX > v5 )
  {
    iStartTileX = v5;
    v5 = (int)(float)((float)this->m_iStartRubberBandX * v4);
    iEndTileX = v5;
  }
  if ( v6 > 119 - (int)v7 )
  {
    iEndTileY = 119 - (int)(float)((float)this->m_iStartRubberBandY * v4);
    v6 = 119 - (int)v7;
  }
  v8 = 0;
  iRooms = this->m_pMapLayout->m_PlacedRooms.m_Size;
  i = 0;
  if ( iRooms > 0 )
  {
    while ( 1 )
    {
      v9 = this->m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[v8];
      m_iPosX = v9->m_iPosX;
      if ( m_iPosX < v5 )
      {
        m_pRoomTemplate = v9->m_pRoomTemplate;
        if ( m_iPosX + m_pRoomTemplate->m_nTilesX > iStartTileX )
        {
          m_iPosY = v9->m_iPosY;
          if ( m_iPosY < iEndTileY && m_iPosY + m_pRoomTemplate->m_nTilesY > v6 )
            CTileGenDialog::ToggleRoomSelection(this, pRoom: v9);
        }
      }
      v8 = i + 1;
      i = v8;
      if ( v8 >= iRooms )
        break;
      v5 = iEndTileX;
    }
    *p_m_iStartRubberBandX = -1;
  }
  else
  {
    *p_m_iStartRubberBandX = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034290
// Name: public: void CTileGenDialog::SetCursorRoomTemplate(class CRoomTemplate const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::SetCursorRoomTemplate(CTileGenDialog *this, const CRoomTemplate *pRoomTemplate)
{
  const CRoomTemplate *m_pCursorTemplate; // ebx

  m_pCursorTemplate = this->m_pCursorTemplate;
  this->m_pCursorTemplate = pRoomTemplate;
  if ( pRoomTemplate != nullptr )
  {
    CTileGenDialog::ClearRoomSelection(this);
    CRoomTemplatePanel::SetRoomTemplate(this: this->m_pCursorPanel, pTemplate: pRoomTemplate);
    this->m_pCursorPanel->SetVisible(this: this->m_pCursorPanel, a2: true);
  }
  else
  {
    this->m_pCursorPanel->SetVisible(this: this->m_pCursorPanel, a2: false);
  }
  if ( m_pCursorTemplate != nullptr )
    CRoomTemplateListPanel::UpdatePanelsWithTemplate(this: this->m_pTemplateListPanel, pTemplate: m_pCursorTemplate);
  if ( pRoomTemplate != nullptr )
    CRoomTemplateListPanel::UpdatePanelsWithTemplate(this: this->m_pTemplateListPanel, pTemplate: pRoomTemplate);
}

//------------------------------------------------------------------------------
// Address: 0x10034300
// Name: public: void CTileGenDialog::SetRoomSelection(class CRoom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTileGenDialog::SetRoomSelection(CTileGenDialog *this, CRoom *pRoom)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CRoom **m_pMemory; // ecx
  int v6; // eax
  CRoom **v7; // eax

  CTileGenDialog::ClearRoomSelection(this);
  m_Size = this->m_SelectedRooms.m_Size;
  m_nAllocationCount = this->m_SelectedRooms.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SelectedRooms,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_SelectedRooms.m_Size;
  m_pMemory = this->m_SelectedRooms.m_Memory.m_pMemory;
  v6 = this->m_SelectedRooms.m_Size - m_Size - 1;
  this->m_SelectedRooms.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_SelectedRooms.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pRoom;
  pRoom->m_pPlacedRoomPanel->InvalidateLayout(this: pRoom->m_pPlacedRoomPanel, a2: true, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1005CF30
// Name: public: int CUtlVector<class CBSPFace __near *,class CUtlMemory<class CBSPFace __near *,int>>::InsertMultipleBefore(int,int,class CBSPFace __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int>>::InsertMultipleBefore(
        CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *this,
        int elem,
        int num,
        CBSPFace *const *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPFace **m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  CBSPFace **v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *v13 = pToInsert[v11];
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1005CFD0
// Name: public: int CUtlVector<struct dbrush_t,class CUtlMemory<struct dbrush_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(
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
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1005D050
// Name: public: int CUtlVector<struct HashedPlane_t,class CUtlMemory<struct HashedPlane_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::InsertMultipleBefore(
        CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  HashedPlane_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1005D6C0
// Name: public: int CUtlVector<struct BSPCluster_t,class CUtlMemory<struct BSPCluster_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int>>::AddToTail(
        CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1005E0A0
// Name: public: int CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertMultipleBefore(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPBrushSide *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CBSPBrushSide *v11; // eax
  int elema; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>::Grow(
      (CUtlMemory<MapBrush_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      for ( elema = num; elema != 0; --elema )
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_nPlaneIndex = -1;
          v11->m_nTextureInfoIndex = 0;
          v11->m_SurfaceFlags = 0;
          v11->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
          v11->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
          v11->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
          v11->m_Polygon.m_Points.m_Size = 0;
          v11->m_Polygon.m_Points.m_pElements = nullptr;
          v11->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        }
        ++v10;
      }
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1005E430
// Name: public: int CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPBrushSide *m_pMemory; // ecx
  int v6; // eax
  CBSPBrushSide *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>::Grow(
      (CUtlMemory<MapBrush_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_nPlaneIndex = -1;
    v7->m_nTextureInfoIndex = 0;
    v7->m_SurfaceFlags = 0;
    v7->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    v7->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
    v7->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
    v7->m_Polygon.m_Points.m_Size = 0;
    v7->m_Polygon.m_Points.m_pElements = nullptr;
    v7->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1005E4C0
// Name: public: int CUtlVector<class CBSPFace,class CUtlMemory<class CBSPFace,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::InsertMultipleBefore(
        CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPFace *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CBSPFace *v11; // eax
  int elema; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CASW_MissionTextSpec,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      for ( elema = num; elema != 0; --elema )
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_nTextureInfoIndex = -1;
          v11->m_nPlaneIndex = -1;
          v11->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
          v11->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
          v11->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
          v11->m_Polygon.m_Points.m_Size = 0;
          v11->m_Polygon.m_Points.m_pElements = nullptr;
          v11->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
          v11->m_nDisplacementIndex = -1;
          v11->m_nSerializedFaceIndex = -1;
        }
        ++v10;
      }
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1005ECB0
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near & CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::operator=(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *other)
{
  int m_Size; // ebx
  signed int v5; // eax
  Vector *m_pMemory; // ecx
  Vector *v7; // edx
  float *v8; // ecx
  Vector *v9; // edx
  int v10; // edx
  bool v11; // zf
  Vector *v12; // ecx
  Vector *v13; // edx
  Vector *v14; // ecx
  Vector *v15; // edx
  unsigned int v16; // edx
  int v17; // ebx
  Vector *v18; // eax
  Vector *v19; // ecx
  int i; // [esp+Ch] [ebp-8h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *othera; // [esp+1Ch] [ebp+8h]

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    othera = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)(((unsigned int)(m_Size - 4) >> 2) + 1);
    i = 4 * (_DWORD)othera;
    do
    {
      m_pMemory = other->m_Memory.m_pMemory;
      v7 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v7->x + v5) = *(float *)((char *)&other->m_Memory.m_pMemory->x + v5);
      *(float *)((char *)&v7->y + v5) = *(float *)((char *)&m_pMemory->y + v5);
      *(float *)((char *)&v7->z + v5) = *(float *)((char *)&m_pMemory->z + v5);
      v8 = (float *)((char *)&other->m_Memory.m_pMemory[1].x + v5);
      v9 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v9[1].x + v5) = *v8;
      v10 = (int)&v9[1] + v5;
      *(float *)(v10 + 4) = v8[1];
      v5 += 48;
      v11 = othera == (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)1;
      othera = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)othera - 1);
      *(float *)(v10 + 8) = v8[2];
      v12 = other->m_Memory.m_pMemory;
      v13 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v13[-2].x + v5) = *(float *)((char *)&other->m_Memory.m_pMemory[-2].x + v5);
      *(float *)((char *)&v13[-1] + v5 - 8) = *(float *)((char *)&v12[-1] + v5 - 8);
      *(float *)((char *)&v13[-1] + v5 - 4) = *(float *)((char *)&v12[-1] + v5 - 4);
      v14 = other->m_Memory.m_pMemory;
      v15 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v15[-1].x + v5) = *(float *)((char *)&other->m_Memory.m_pMemory[-1].x + v5);
      *(float *)((char *)v15 + v5 - 8) = *(float *)((char *)v14 + v5 - 8);
      *(float *)((char *)v15 + v5 - 4) = *(float *)((char *)v14 + v5 - 4);
    }
    while ( !v11 );
    v5 = i;
  }
  if ( v5 < m_Size )
  {
    v16 = v5;
    v17 = m_Size - v5;
    do
    {
      v18 = other->m_Memory.m_pMemory;
      v19 = this->m_Memory.m_pMemory;
      v19[v16].x = other->m_Memory.m_pMemory[v16].x;
      ++v16;
      --v17;
      v19[v16 - 1].y = v18[v16 - 1].y;
      v19[v16 - 1].z = v18[v16 - 1].z;
    }
    while ( v17 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005EDB0
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        const Vector *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  double v13; // st7
  float *v14; // ecx
  float *v15; // ecx
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      *(float *)&v10[(_DWORD)m_pMemory + 4] = *(p_z - 4);
      *(float *)&v10[(_DWORD)m_pMemory + 8] = *(p_z - 3);
      v11 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v11 = *(p_z - 2);
      v11[1] = *(p_z - 1);
      v11[2] = *p_z;
      v12 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v12 = p_z[1];
      v12[1] = p_z[2];
      v12[2] = p_z[3];
      v13 = p_z[4];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      p_z += 12;
      --v7;
      *v14 = v13;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = i;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v15 = &pArray[v5].z;
    v16 = v3 - v5;
    do
    {
      v17 = *(v15 - 2);
      v18 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v15 - 8 - (_DWORD)pArray);
      v15 += 3;
      --v16;
      *v18 = v17;
      v18[1] = *(v15 - 4);
      v18[2] = *(v15 - 3);
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005EEC0
// Name: public: class CUtlVector<struct HashedPlane_t,class CUtlMemory<struct HashedPlane_t,int>> __near & CUtlVector<struct HashedPlane_t,class CUtlMemory<struct HashedPlane_t,int>>::operator=(class CUtlVector<struct HashedPlane_t,class CUtlMemory<struct HashedPlane_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *__thiscall CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::operator=(
        CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *this,
        const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *other)
{
  int m_Size; // ebx
  int v5; // eax
  int v6; // edx
  HashedPlane_t *m_pMemory; // eax
  HashedPlane_t *v8; // ecx
  HashedPlane_t *v9; // eax
  HashedPlane_t *v10; // ecx
  HashedPlane_t *v11; // eax
  HashedPlane_t *v12; // ecx
  int v13; // ecx
  HashedPlane_t *v14; // ecx
  HashedPlane_t *v15; // eax
  HashedPlane_t *v16; // ecx
  HashedPlane_t *v17; // ecx
  HashedPlane_t *v18; // eax
  HashedPlane_t *v19; // ecx
  bool v20; // zf
  int v21; // edx
  HashedPlane_t *v22; // ecx
  HashedPlane_t *v23; // eax
  HashedPlane_t *v24; // ecx
  int i; // [esp+Ch] [ebp-8h]
  const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *othera; // [esp+1Ch] [ebp+8h]
  const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *otherb; // [esp+1Ch] [ebp+8h]

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    v6 = 0;
    othera = (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)(((unsigned int)(m_Size - 4) >> 2) + 1);
    i = 4 * (_DWORD)othera;
    do
    {
      m_pMemory = other->m_Memory.m_pMemory;
      v8 = this->m_Memory.m_pMemory;
      v8[v6].m_vNormal.x = other->m_Memory.m_pMemory[v6].m_vNormal.x;
      v9 = &m_pMemory[v6];
      v10 = &v8[v6];
      v10->m_vNormal.y = v9->m_vNormal.y;
      v10->m_vNormal.z = v9->m_vNormal.z;
      v10->m_flDistance = v9->m_flDistance;
      v10->m_Type = v9->m_Type;
      v10->m_nNextPlaneIndex = v9->m_nNextPlaneIndex;
      v11 = &other->m_Memory.m_pMemory[v6 + 1];
      v12 = this->m_Memory.m_pMemory;
      v12[v6 + 1].m_vNormal.x = v11->m_vNormal.x;
      v13 = (int)&v12[v6 + 1];
      *(float *)(v13 + 4) = v11->m_vNormal.y;
      *(float *)(v13 + 8) = v11->m_vNormal.z;
      *(float *)(v13 + 12) = v11->m_flDistance;
      *(_DWORD *)(v13 + 16) = v11->m_Type;
      *(_DWORD *)(v13 + 20) = v11->m_nNextPlaneIndex;
      v14 = this->m_Memory.m_pMemory;
      v15 = &other->m_Memory.m_pMemory[v6 + 2];
      v14[v6 + 2].m_vNormal.x = v15->m_vNormal.x;
      v16 = &v14[v6 + 2];
      v16->m_vNormal.y = v15->m_vNormal.y;
      v16->m_vNormal.z = v15->m_vNormal.z;
      v16->m_flDistance = v15->m_flDistance;
      v16->m_Type = v15->m_Type;
      v16->m_nNextPlaneIndex = v15->m_nNextPlaneIndex;
      v17 = this->m_Memory.m_pMemory;
      v18 = &other->m_Memory.m_pMemory[v6 + 3];
      v17[v6 + 3].m_vNormal.x = v18->m_vNormal.x;
      v19 = &v17[v6 + 3];
      v6 += 4;
      v20 = othera == (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)1;
      othera = (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)((char *)othera - 1);
      v19->m_vNormal.y = v18->m_vNormal.y;
      v19->m_vNormal.z = v18->m_vNormal.z;
      v19->m_flDistance = v18->m_flDistance;
      v19->m_Type = v18->m_Type;
      v19->m_nNextPlaneIndex = v18->m_nNextPlaneIndex;
    }
    while ( !v20 );
    v5 = i;
  }
  if ( v5 < m_Size )
  {
    v21 = v5;
    otherb = (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)(m_Size - v5);
    do
    {
      v22 = this->m_Memory.m_pMemory;
      v23 = &other->m_Memory.m_pMemory[v21];
      v22[v21].m_vNormal.x = v23->m_vNormal.x;
      v24 = &v22[v21];
      v24->m_vNormal.y = v23->m_vNormal.y;
      ++v21;
      v20 = otherb == (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)1;
      otherb = (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)((char *)otherb - 1);
      v24->m_vNormal.z = v23->m_vNormal.z;
      v24->m_flDistance = v23->m_flDistance;
      v24->m_Type = v23->m_Type;
      v24->m_nNextPlaneIndex = v23->m_nNextPlaneIndex;
    }
    while ( !v20 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005F030
// Name: public: void CUtlVector<class CBSPFace,class CUtlMemory<class CBSPFace,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::RemoveAll(
        CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 40 * v1;
    v5 = 40 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 2) = &CCopyableUtlVector<Vector>::`vftable';
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
      v2 = v5 - 40;
      v5 -= 40;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F0E0
// Name: public: void CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v6; // [esp+8h] [ebp-4h]

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
      *((_DWORD *)v3 + 3) = &CCopyableUtlVector<Vector>::`vftable';
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
      v2 = v5 - 36;
      v5 -= 36;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F9C0
// Name: public: CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::~CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::~CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this)
{
  bool v2; // sf
  CBSPBrushSide *m_pMemory; // eax

  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this);
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
// Address: 0x1005FA50
// Name: public: void CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::CopyArray(class CBSPBrushSide const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::CopyArray(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this,
        const CBSPBrushSide *pArray,
        int size)
{
  int v4; // edi
  int *p_m_nTextureInfoIndex; // esi
  char *v6; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v7; // ecx

  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this);
  v4 = size;
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertMultipleBefore(this, elem: this->m_Size, num: size);
  if ( size > 0 )
  {
    p_m_nTextureInfoIndex = &pArray->m_nTextureInfoIndex;
    do
    {
      v6 = (char *)this->m_Memory.m_pMemory + (unsigned int)p_m_nTextureInfoIndex - 4 - (_DWORD)pArray;
      *(_DWORD *)v6 = *(p_m_nTextureInfoIndex - 1);
      *((_DWORD *)v6 + 1) = *p_m_nTextureInfoIndex;
      *((_WORD *)v6 + 4) = *((_WORD *)p_m_nTextureInfoIndex + 2);
      if ( p_m_nTextureInfoIndex == (int *)-8 )
        v7 = nullptr;
      else
        v7 = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)(p_m_nTextureInfoIndex + 3);
      CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
        this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)(v6 + 16),
        other: v7);
      p_m_nTextureInfoIndex += 9;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005FAD0
// Name: public: int CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::InsertBefore(int,class CBSPBrushSide const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this,
        int elem,
        const CBSPBrushSide *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPBrushSide *m_pMemory; // ecx
  int v7; // eax
  CBSPBrushSide *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>::Grow(
      (CUtlMemory<MapBrush_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->m_nPlaneIndex = src->m_nPlaneIndex;
    v8->m_nTextureInfoIndex = src->m_nTextureInfoIndex;
    v8->m_SurfaceFlags = src->m_SurfaceFlags;
    v8->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    v8->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
    v8->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
    v8->m_Polygon.m_Points.m_Size = 0;
    v8->m_Polygon.m_Points.m_pElements = nullptr;
    v8->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
      this: &v8->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      pArray: src->m_Polygon.m_Points.m_Memory.m_pMemory,
      size: src->m_Polygon.m_Points.m_Size);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10063CB0
// Name: public: int CUtlVector<struct MapEntity_t,class CUtlMemory<struct MapEntity_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MapEntity_t,CUtlMemory<MapEntity_t,int>>::InsertBefore(
        CUtlVector<MapEntity_t,CUtlMemory<MapEntity_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MapEntity_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::CSizerBase::CSizerMember,int>::Grow(
      (CUtlMemory<vgui::CSizerBase::CSizerMember,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10063D20
// Name: public: int CUtlVector<struct MapBrush_t,class CUtlMemory<struct MapBrush_t,int>>::InsertMultipleBefore(int,int,struct MapBrush_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MapBrush_t,CUtlMemory<MapBrush_t,int>>::InsertMultipleBefore(
        CUtlVector<MapBrush_t,CUtlMemory<MapBrush_t,int> > *this,
        int elem,
        int num,
        const MapBrush_t *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MapBrush_t *m_pMemory; // ecx
  int v10; // eax
  const MapBrush_t *v11; // ecx
  int v12; // edx
  MapBrush_t *v13; // eax
  int elema; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    for ( elema = num; elema != 0; --elema )
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
      {
        *(_QWORD *)&v13->m_ContentsFlags = *(_QWORD *)&v11->m_ContentsFlags;
        *(_QWORD *)&v13->m_nNumSides = *(_QWORD *)&v11->m_nNumSides;
        *(_QWORD *)&v13->m_vMinBounds.y = *(_QWORD *)&v11->m_vMinBounds.y;
        *(_QWORD *)&v13->m_vMaxBounds.x = *(_QWORD *)&v11->m_vMaxBounds.x;
        v13->m_vMaxBounds.z = v11->m_vMaxBounds.z;
      }
      ++v12;
      ++v11;
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10063DF0
// Name: public: int CUtlVector<struct CMapDisplacement::Vertex_t,class CUtlMemory<struct CMapDisplacement::Vertex_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMapDisplacement::Vertex_t,CUtlMemory<CMapDisplacement::Vertex_t,int>>::InsertMultipleBefore(
        CUtlVector<CMapDisplacement::Vertex_t,CUtlMemory<CMapDisplacement::Vertex_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMapDisplacement::Vertex_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMapDisplacement::Vertex_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 96 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10065CF0
// Name: public: int CUtlVector<class CMapDisplacement,class CUtlMemory<class CMapDisplacement,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::InsertBefore(
        CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMapDisplacement *m_pMemory; // ecx
  int v6; // eax
  CMapDisplacement *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMapDisplacement,int>::Grow(
      (CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_nPower = 0;
    v7->m_nOriginalBrushSide = -1;
    v7->m_nFlags = 0;
    v7->m_ContentsFlags = 0;
    v7->m_vStartPosition.x = 0.0;
    v7->m_vStartPosition.y = 0.0;
    v7->m_vStartPosition.z = 0.0;
    v7->m_Vertices.m_Memory.m_pMemory = nullptr;
    v7->m_Vertices.m_Memory.m_nAllocationCount = 0;
    v7->m_Vertices.m_Memory.m_nGrowSize = 0;
    v7->m_Vertices.m_Size = 0;
    v7->m_Vertices.m_pElements = nullptr;
    v7->m_TriangleTags.m_Memory.m_pMemory = nullptr;
    v7->m_TriangleTags.m_Memory.m_nAllocationCount = 0;
    v7->m_TriangleTags.m_Memory.m_nGrowSize = 0;
    v7->m_TriangleTags.m_Size = 0;
    v7->m_TriangleTags.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10066810
// Name: public: int CUtlVector<struct MapBrushSide_t,class CUtlMemory<struct MapBrushSide_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::InsertBefore(
        CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MapBrushSide_t *m_pMemory; // ecx
  int v6; // eax
  MapBrushSide_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MapBrushSide_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    v7->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
    v7->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
    v7->m_Polygon.m_Points.m_Size = 0;
    v7->m_Polygon.m_Points.m_pElements = nullptr;
    v7->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10068FC0
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertBefore(int,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        unsigned __int16 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int16 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow((CUtlMemory<wchar_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10069030
// Name: public: int CUtlVector<struct dleaf_t,class CUtlMemory<struct dleaf_t,int>>::InsertBefore(int,struct dleaf_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int>>::InsertBefore(
        CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int> > *this,
        int elem,
        const dleaf_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dleaf_t *m_pMemory; // ecx
  int v7; // eax
  dleaf_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(
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
// Address: 0x100690C0
// Name: public: int CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::InsertMultipleBefore(int,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int elem,
        int num,
        const unsigned __int8 *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  unsigned __int8 *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10069150
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<StaticPropLump_t,int>::Grow(
      (CUtlMemory<MapTextureInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100691D0
// Name: public: int CUtlVector<struct dtexdata_t,class CUtlMemory<struct dtexdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::InsertMultipleBefore(
        CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dtexdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 32 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10069240
// Name: public: int CUtlVector<struct dmodel_t,class CUtlMemory<struct dmodel_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int>>::InsertMultipleBefore(
        CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dmodel_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dmodel_t,int>::Grow(
      (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
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
// Address: 0x100692C0
// Name: public: int CUtlVector<struct dplane_t,class CUtlMemory<struct dplane_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dplane_t,CUtlMemory<dplane_t,int>>::InsertMultipleBefore(
        CUtlVector<dplane_t,CUtlMemory<dplane_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dplane_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CRoomCandidate,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100695D0
// Name: public: int CUtlVector<struct dnode_t,class CUtlMemory<struct dnode_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::AddToTail(
        CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  dnode_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10069620
// Name: public: int CUtlVector<class CPhysCollide __near *,class CUtlMemory<class CPhysCollide __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int>>::InsertMultipleBefore(
        CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  struct CPhysCollide **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
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
// Address: 0x1007CEF0
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
// Address: 0x10086930
// Name: public: bool CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::FindAndRemove(class vgui::PHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
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
// Address: 0x10087E90
// Name: public: int CUtlVector<class vgui::CSizerBase::CSizerMember,class CUtlMemory<class vgui::CSizerBase::CSizerMember,int>>::InsertBefore(int,class vgui::CSizerBase::CSizerMember const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CSizerBase::CSizerMember,CUtlMemory<vgui::CSizerBase::CSizerMember,int>>::InsertBefore(
        CUtlVector<vgui::CSizerBase::CSizerMember,CUtlMemory<vgui::CSizerBase::CSizerMember,int> > *this,
        int elem,
        const vgui::CSizerBase::CSizerMember *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CSizerBase::CSizerMember *m_pMemory; // ecx
  int v7; // eax
  vgui::CSizerBase::CSizerMember *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::CSizerBase::CSizerMember,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10088020
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
// Address: 0x10093610
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
    CUtlMemory<CMapDisplacement,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x100948A0
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
    CUtlMemory<vgui::CSizerBase::CSizerMember,int>::Grow(
      (CUtlMemory<vgui::CSizerBase::CSizerMember,int> *)this,
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
// Address: 0x10094930
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::Remove(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int v3; // eax

  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Memory.m_pMemory[elem].cmdList);
  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 28 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10094990
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
// Address: 0x10095870
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
// Address: 0x10096FA0
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
// Address: 0x10097A80
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
// Address: 0x10097D60
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
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x100A2EA0
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
// Address: 0x100A3E00
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
// Address: 0x100AEBD0
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
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
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x100B47C0
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
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x100C9670
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
    CUtlMemory<CRoomCandidate,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x100CCF70
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
// Address: 0x100CD430
// Name: public: int CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::InsertBefore(int,class vgui::PageTab __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::InsertBefore(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem,
        vgui::PageTab **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PageTab **m_pMemory; // ecx
  int v7; // eax
  vgui::PageTab **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x100CFFA0
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x100D1560
// Name: public: int CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::InsertMultipleBefore(
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
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
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
// Address: 0x100D1B40
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
    CUtlMemory<EnumEntry_t,int>::Grow(
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
// Address: 0x100F67A0
// Name: public: void CUtlVector<struct VMFExporter::SideTranslation_t __near *,class CUtlMemory<struct VMFExporter::SideTranslation_t __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
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
// Address: 0x100F7F50
// Name: public: int CUtlVector<struct FGDVisGroupsBaseClass_s,class CUtlMemory<struct FGDVisGroupsBaseClass_s,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  FGDAutoVisGroups_s *m_pMemory; // ecx
  int v6; // eax
  FGDAutoVisGroups_s *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<FGDAutoVisGroups_s,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 280 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Classes.m_Memory.m_pMemory = nullptr;
    v7->m_Classes.m_Memory.m_nAllocationCount = 0;
    v7->m_Classes.m_Memory.m_nGrowSize = 0;
    v7->m_Classes.m_Size = 0;
    v7->m_Classes.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100F7FE0
// Name: public: void CUtlVector<struct FGDVisGroupsBaseClass_s,class CUtlMemory<struct FGDVisGroupsBaseClass_s,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::RemoveAll(
        CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // esi
  char **m_pMemory; // eax
  CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 280 * v1;
    for ( i = 280 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<char *,CUtlMemory<char *,int> > *)&this->m_Memory.m_pMemory->szClass[v2];
      CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements(this: v3 + 13);
      v3[13].m_Size = 0;
      if ( v3[13].m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3[13].m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3[13].m_Memory.m_pMemory);
          v3[13].m_Memory.m_pMemory = nullptr;
        }
        v3[13].m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3[13].m_Memory.m_pMemory;
      v3[13].m_pElements = m_pMemory;
      if ( v3[13].m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3[13].m_Memory.m_pMemory = nullptr;
        }
        v3[13].m_Memory.m_nAllocationCount = 0;
      }
      i -= 280;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8D20
// Name: public: void CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::RemoveAll(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  FGDAutoVisGroups_s *v3; // esi
  bool v4; // sf
  FGDVisGroupsBaseClass_s *m_pMemory; // eax
  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::RemoveAll(this: &v3->m_Classes);
      if ( v3->m_Classes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Classes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Classes.m_Memory.m_pMemory);
          v3->m_Classes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Classes.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Classes.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Classes.m_Memory.m_pMemory;
      v3->m_Classes.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Classes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Classes.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F9250
// Name: public: CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>::~CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::~CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this)
{
  bool v2; // sf
  FGDAutoVisGroups_s *m_pMemory; // eax

  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::RemoveAll(this);
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
// Address: 0x100FB390
// Name: public: int CUtlVector<struct GDIVITEM,class CUtlMemory<struct GDIVITEM,int>>::InsertBefore(int,struct GDIVITEM const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
        CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int> > *this,
        int elem,
        const GDIVITEM *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  GDIVITEM *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 268 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD3D0
// Name: _dynamic_initializer_for__CTileGenDialog::m_MessageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTileGenDialog::m_MessageMap__()
{
  *(_QWORD *)&CTileGenDialog::m_MessageMap[0].func = (unsigned int)CTileGenDialog::OnFileSelected;
  *((_QWORD *)&CTileGenDialog::m_MessageMap[0].func + 1) = 0;
  *(_QWORD *)&CTileGenDialog::m_MessageMap[0].secondParamType = 0;
  *(_QWORD *)&CTileGenDialog::m_MessageMap[0].nameSymbol = 0;
  CTileGenDialog::m_MessageMap[0].secondParamSymbol = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FD420
// Name: _dynamic_initializer_for__kv_editor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__kv_editor__()
{
  ConCommand::ConCommand(
    this: &kv_editor,
    pName: "kv_editor",
    callback: (void (__cdecl *)(const CCommand *))cc_kv_editor,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__kv_editor__);
}

//------------------------------------------------------------------------------
// Address: 0x100FD450
// Name: sub_100FD450
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_100FD450()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_1019CCA0 = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x100FD470
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x100FD490
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FD4A0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD500
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD530
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100FD550
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x100FD560
// Name: _dynamic_initializer_for__LOG_VBSP2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_VBSP2__()
{
  int result; // eax

  result = _LoggingSystem_RegisterLoggingChannel(a1: "VBSP2", a2: 0, a3: 0, a4: 1, a5: -8339264);
  LOG_VBSP2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD590
// Name: _dynamic_initializer_for__g_TesselateVerts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TesselateVerts__()
{
  g_TesselateVerts[0].m_Index = (CVertIndex)-65535;
  dword_10193EEA = -65536;
  dword_10193EF0 = -1;
  dword_10193EF6 = 0xFFFF;
  dword_10193EFC = 0x1FFFF;
  dword_10193F02 = 0x10000;
  dword_10193F08 = 65537;
  dword_10193F0E = 1;
  dword_10193F14 = -65535;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FD650
// Name: _dynamic_initializer_for__g_VertInfo_5x5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_5x5__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_5x5;
  for ( i = 24; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD670
// Name: _dynamic_initializer_for__g_VertInfo_9x9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_9x9__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_9x9;
  for ( i = 80; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD690
// Name: _dynamic_initializer_for__g_VertInfo_17x17__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_17x17__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_17x17;
  for ( i = 288; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD6B0
// Name: _dynamic_initializer_for__g_PowerInfoInitializer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_PowerInfoInitializer__()
{
  int i; // esi
  CPowerInfo *v1; // eax

  for ( i = 0; i <= 4; ++i )
  {
    v1 = g_PowerInfos[i];
    if ( v1 != nullptr )
      InitPowerInfo(pInfo: v1, iMaxPower: i);
  }
}
