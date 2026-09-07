// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/test_stressentities.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10233640
// Name: void Test_SpawnRandomEntities(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl Test_SpawnRandomEntities(const CCommand *args)
{
  const char *v1; // eax
  int v2; // edi
  const char *v3; // eax
  int v4; // eax
  IUniformRandomStream *v5; // ecx
  int v6; // eax
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  int v9; // esi
  unsigned int m_Index; // eax
  unsigned int v11; // eax
  CBaseEntity *m_pEntity; // ecx
  int v13; // eax
  CHandle<CBaseEntity> *v14; // esi
  CBaseEntity *v15; // eax
  IUniformRandomStream **v16; // eax
  const char *v17; // [esp-18h] [ebp-24h]
  const CCommand *argsa; // [esp+14h] [ebp+8h]

  if ( args->m_nArgc < 3 )
    _Error(this: (ISceneTokenProcessor *)&stru_104C1AC8, a2: v17);
  if ( g_StressEntities.m_Size == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_104C1A70, a2: v17);
  v1 = locale;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  v2 = atoi(nptr: v1);
  v3 = locale;
  if ( args->m_nArgc > 2 )
    v3 = args->m_ppArgv[2];
  v4 = atoi(nptr: v3);
  v6 = _RandomInt(this: v5, a2: v2, a3: v4);
  if ( v6 > 0 )
  {
    for ( argsa = (const CCommand *)v6; argsa != nullptr; argsa = (const CCommand *)((char *)argsa - 1) )
    {
      v9 = _RandomInt(this: v7, a2: 0, a3: g_StressEntities.m_Size - 1);
      m_Index = g_StressEntities.m_Memory.m_pMemory[v9].m_Index;
      if ( m_Index != -1 )
      {
        v8 = (IUniformRandomStream *)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
          && v8->__vftable != nullptr )
        {
          v11 = g_StressEntities.m_Memory.m_pMemory[v9].m_Index;
          if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
            m_pEntity = nullptr;
          else
            m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
          UTIL_RemoveImmediate(oldObj: m_pEntity);
        }
      }
      v13 = _RandomInt(this: v8, a2: 0, a3: g_StressEntityRegs.m_Size - 1);
      v14 = &g_StressEntities.m_Memory.m_pMemory[v9];
      v15 = g_StressEntityRegs.m_Memory.m_pMemory[v13]->m_pFn();
      if ( v15 != nullptr )
      {
        v16 = (IUniformRandomStream **)v15->GetRefEHandle(this: v15);
        v7 = *v16;
        v14->m_Index = (unsigned int)*v16;
      }
      else
      {
        v14->m_Index = -1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10233780
// Name: void Test_RemoveAllRandomEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_RemoveAllRandomEntities()
{
  int v0; // esi
  CBaseEntityList *v1; // edx
  CHandle<CBaseEntity> *m_pMemory; // edi
  unsigned int m_Index; // eax
  unsigned int v4; // eax
  CBaseEntity *m_pEntity; // ecx

  v0 = 0;
  if ( g_StressEntities.m_Size > 0 )
  {
    v1 = g_pEntityList;
    m_pMemory = g_StressEntities.m_Memory.m_pMemory;
    do
    {
      m_Index = m_pMemory[v0].m_Index;
      if ( m_Index != -1
        && v1->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v1->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v4 = m_pMemory[v0].m_Index;
        if ( v4 == -1 || v1->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CBaseEntity *)v1->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
        UTIL_Remove(oldObj: m_pEntity);
        m_pMemory = g_StressEntities.m_Memory.m_pMemory;
        v1 = g_pEntityList;
      }
      ++v0;
    }
    while ( v0 < g_StressEntities.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10233810
// Name: void Test_RandomizeInPVS(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_RandomizeInPVS(const CCommand *args)
{
  const char *v1; // eax
  int v2; // edi
  unsigned int m_Index; // eax
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream v5; // ebx
  unsigned int v6; // edi
  CBaseEdict *RandomInt; // ecx
  const char *v8; // [esp+0h] [ebp-Ch]
  int percent; // [esp+8h] [ebp-4h]
  int i; // [esp+14h] [ebp+8h]

  if ( args->m_nArgc < 2 )
    _Error(this: (ISceneTokenProcessor *)&stru_104C1B18, a2: v8);
  v1 = locale;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  v2 = 0;
  percent = atoi(nptr: v1);
  for ( i = 0; v2 < g_StressEntities.m_Size; i = v2 )
  {
    m_Index = g_StressEntities.m_Memory.m_pMemory[v2].m_Index;
    if ( m_Index != -1 )
    {
      v4 = (IUniformRandomStream *)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        v5.__vftable = v4->__vftable;
        if ( v4->__vftable != nullptr && _RandomInt(this: v4, a2: 0, a3: 100) < percent )
        {
          if ( ((int)v5.__vftable[10].RandomFloat & 0x20) != 0 )
          {
            v6 = (int)v5.__vftable[10].RandomFloat & 0xFFFFFFDF;
            if ( v5.__vftable[10].RandomFloat != (float (__thiscall *)(IUniformRandomStream *, float, float))v6 )
            {
              if ( LOBYTE(v5.__vftable[5].RandomFloat) != 0 )
              {
                LOBYTE(v5.__vftable[5].RandomInt) |= 1u;
              }
              else
              {
                RandomInt = (CBaseEdict *)v5.__vftable[1].RandomInt;
                if ( RandomInt != nullptr )
                  CBaseEdict::StateChanged(this: RandomInt, offset: 0xA4u);
              }
              v5.__vftable[10].RandomFloat = (float (__thiscall *)(IUniformRandomStream *, float, float))v6;
            }
            if ( v5.__vftable[1].RandomInt != nullptr )
              *(_DWORD *)v5.__vftable[1].RandomInt |= 0x80u;
            CBaseEntity::DispatchUpdateTransmitState(this: (CBaseEntity *)v5.__vftable);
            v2 = i;
          }
          else
          {
            CBaseEntity::AddEffects(this: (CBaseEntity *)v5.__vftable, nEffects: 32);
          }
        }
      }
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10233930
// Name: void Test_InitRandomEntitySpawner(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_InitRandomEntitySpawner(const CCommand *args)
{
  CStressEntityReg **m_pMemory; // edx
  int m_Size; // ecx
  CStressEntityReg *v3; // edi
  int v4; // esi
  CStressEntityReg **v5; // eax
  int v6; // esi
  const char *v7; // eax
  CHandle<CBaseEntity> *v8; // eax

  m_pMemory = g_StressEntityRegs.m_Memory.m_pMemory;
  m_Size = 0;
  g_StressEntityRegs.m_Size = 0;
  if ( g_StressEntityRegs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_StressEntityRegs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_StressEntityRegs.m_Memory.m_pMemory);
      m_Size = g_StressEntityRegs.m_Size;
      m_pMemory = nullptr;
      g_StressEntityRegs.m_Memory.m_pMemory = nullptr;
    }
    g_StressEntityRegs.m_Memory.m_nAllocationCount = 0;
  }
  v3 = CStressEntityReg::s_pHead;
  for ( g_StressEntityRegs.m_pElements = m_pMemory; v3 != nullptr; v3 = v3->m_pNext )
  {
    v4 = m_Size;
    if ( m_Size + 1 > g_StressEntityRegs.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_StressEntityRegs,
        num: m_Size - g_StressEntityRegs.m_Memory.m_nAllocationCount + 1);
      m_Size = g_StressEntityRegs.m_Size;
      m_pMemory = g_StressEntityRegs.m_Memory.m_pMemory;
    }
    g_StressEntityRegs.m_Size = ++m_Size;
    g_StressEntityRegs.m_pElements = m_pMemory;
    if ( m_Size - v4 - 1 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v4 + 1], src: &m_pMemory[v4], count: 4 * (m_Size - v4 - 1));
      m_Size = g_StressEntityRegs.m_Size;
      m_pMemory = g_StressEntityRegs.m_Memory.m_pMemory;
    }
    v5 = &m_pMemory[v4];
    if ( v5 != nullptr )
    {
      *v5 = v3;
      m_Size = g_StressEntityRegs.m_Size;
      m_pMemory = g_StressEntityRegs.m_Memory.m_pMemory;
    }
  }
  v6 = 100;
  if ( args->m_nArgc >= 2 )
  {
    v7 = locale;
    if ( args->m_nArgc > 1 )
      v7 = args->m_ppArgv[1];
    v6 = atoi(nptr: v7);
  }
  v8 = g_StressEntities.m_Memory.m_pMemory;
  g_StressEntities.m_Size = 0;
  if ( g_StressEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_StressEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_StressEntities.m_Memory.m_pMemory);
      v8 = nullptr;
      g_StressEntities.m_Memory.m_pMemory = nullptr;
    }
    g_StressEntities.m_Memory.m_nAllocationCount = 0;
  }
  g_StressEntities.m_pElements = v8;
  g_StressEntities.m_Size = 0;
  CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>::InsertMultipleBefore(
    this: (CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *)&g_StressEntities,
    elem: 0,
    num: v6);
  _Msg(a1: "Test_InitRandomEntitySpawner: created %d slots.\n", v6);
}
