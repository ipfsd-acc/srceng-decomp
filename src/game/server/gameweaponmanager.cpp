// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/gameweaponmanager.cpp
// Functions: 7
// ============================================================

#include "game\server\gameweaponmanager.h"

//------------------------------------------------------------------------------
// Address: 0x10152990
// Name: private: virtual struct datamap_t __near * CGameWeaponManager::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGameWeaponManager::GetDataDescMap(CGameWeaponManager *this)
{
  return &CGameWeaponManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101529B0
// Name: public: virtual void CGameWeaponManager::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameWeaponManager::Spawn(CGameWeaponManager *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v4; // edi
  const char *DebugName; // eax

  CBaseEntity::ThinkSet(this, func:  __thiscall CBaseEntity::`vcall'{200,{flat}}, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  pszValue = this->m_iszWeaponName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CreateEntityByName(className: pszValue, iForceEdictIndex: -1, bNotify: true);
  v4 = EntityByName;
  if ( EntityByName != nullptr )
  {
    this->m_bExpectingWeapon = __RTDynamicCast(
                                 inptr: EntityByName,
                                 VfDelta: 0,
                                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                                 TargetType: &CBaseCombatWeapon `RTTI Type Descriptor',
                                 isReference: 0) != nullptr;
    UTIL_Remove(oldObj: v4);
  }
  else
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "%s removed itself!\n", DebugName);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152A50
// Name: void WeaponManager_AmmoMod(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WeaponManager_AmmoMod(CBaseCombatWeapon *pWeapon)
{
  int v1; // eax
  CGameWeaponManager *v2; // eax
  int v3; // esi
  edict_t *m_pPev; // ecx
  int iNewClip; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  v1 = 0;
  for ( i = 0; v1 < g_Managers.m_Size; i = v1 )
  {
    v2 = g_Managers.m_Memory.m_pMemory[v1];
    if ( v2->m_iszWeaponName.pszValue == pWeapon->m_iClassname.pszValue )
    {
      iNewClip = (int)(float)((float)pWeapon->m_iClip1.m_Value * v2->m_flAmmoMod);
      v3 = iNewClip + _RandomInt(this: (IUniformRandomStream *)g_Managers.m_Memory.m_pMemory, a2: -2, a3: 2);
      if ( v3 <= pWeapon->GetMaxClip1(this: pWeapon) )
      {
        if ( v3 <= 0 )
          v3 = 1;
      }
      else
      {
        v3 = pWeapon->GetMaxClip1(this: pWeapon);
      }
      if ( pWeapon->m_iClip1.m_Value != v3 )
      {
        if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = pWeapon->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
        }
        pWeapon->m_iClip1.m_Value = v3;
      }
    }
    v1 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10152B30
// Name: public: CGameWeaponManager::CGameWeaponManager(void)
// Source: json
//------------------------------------------------------------------------------
CGameWeaponManager *__thiscall CGameWeaponManager::CGameWeaponManager(CGameWeaponManager *this)
{
  int m_Size; // eax
  int v3; // edi
  CGameWeaponManager **m_pMemory; // ecx
  int v5; // eax
  CGameWeaponManager **v6; // eax

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CGameWeaponManager_vtbl *)&CGameWeaponManager::`vftable';
  this->m_ManagedNonWeapons.m_Memory.m_pMemory = nullptr;
  this->m_ManagedNonWeapons.m_Memory.m_nAllocationCount = 0;
  this->m_ManagedNonWeapons.m_Memory.m_nGrowSize = 0;
  this->m_ManagedNonWeapons.m_Size = 0;
  this->m_ManagedNonWeapons.m_pElements = nullptr;
  this->m_flAmmoMod = 1.0;
  this->m_bExpectingWeapon = false;
  m_Size = g_Managers.m_Size;
  v3 = g_Managers.m_Size;
  if ( g_Managers.m_Size + 1 > g_Managers.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Managers,
      num: g_Managers.m_Size - g_Managers.m_Memory.m_nAllocationCount + 1);
    m_Size = g_Managers.m_Size;
  }
  m_pMemory = g_Managers.m_Memory.m_pMemory;
  g_Managers.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_Managers.m_pElements = g_Managers.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(dest: &g_Managers.m_Memory.m_pMemory[v3 + 1], src: &g_Managers.m_Memory.m_pMemory[v3], count: 4 * v5);
    m_pMemory = g_Managers.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10152C40
// Name: public: virtual void CGameWeaponManager::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameWeaponManager::Think(CGameWeaponManager *this)
{
  float thinkTime; // xmm0_4
  int m_Size; // ebx
  CGameWeaponManager *v3; // esi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CBaseEntity *j; // edi
  int v6; // esi
  CBaseEntity **m_pMemory; // ecx
  CBaseEntity **v8; // eax
  int v9; // eax
  int v10; // edx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v13; // esi
  CBaseEntity **v14; // edi
  CBaseEntity **v15; // eax
  int v16; // ecx
  int v17; // ecx
  int v18; // eax
  CBaseEntity *v19; // esi
  CBasePlayer *LocalPlayer; // edi
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > candidates; // [esp+14h] [ebp-24h] BYREF
  IHandleEntity *v22; // [esp+28h] [ebp-10h]
  const char *pszWeaponName; // [esp+2Ch] [ebp-Ch]
  int surplus; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  thinkTime = gpGlobals->curtime + 2.0;
  m_Size = 0;
  v3 = this;
  surplus = (int)this;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  pszWeaponName = v3->m_iszWeaponName.pszValue;
  if ( pszWeaponName == nullptr )
    pszWeaponName = locale;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  candidates.m_Memory.m_nAllocationCount = 64;
  candidates.m_Memory.m_nGrowSize = 0;
  candidates.m_Memory.m_pMemory = (CBaseEntity **)Alloc_2(this: _g_pMemAlloc, a2: 256u);
  candidates.m_Size = 0;
  candidates.m_pElements = candidates.m_Memory.m_pMemory;
  if ( v3->m_bExpectingWeapon )
  {
    for ( j = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: pszWeaponName);
          j != nullptr;
          j = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: j, szName: pszWeaponName) )
    {
      if ( (j->m_fEffects.m_Value & 0x20) == 0 && LOBYTE(j[1].m_rgflCoordinateFrame.m_flMatVal[0][3]) != 0 )
      {
        v6 = m_Size;
        if ( m_Size + 1 > candidates.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&candidates,
            num: m_Size - candidates.m_Memory.m_nAllocationCount + 1);
          m_Size = candidates.m_Size;
        }
        m_pMemory = candidates.m_Memory.m_pMemory;
        candidates.m_Size = ++m_Size;
        candidates.m_pElements = candidates.m_Memory.m_pMemory;
        if ( m_Size - v6 - 1 > 0 )
        {
          _V_memmove(
            dest: &candidates.m_Memory.m_pMemory[v6 + 1],
            src: &candidates.m_Memory.m_pMemory[v6],
            count: 4 * (m_Size - v6 - 1));
          m_pMemory = candidates.m_Memory.m_pMemory;
        }
        v8 = &m_pMemory[v6];
        v3 = (CGameWeaponManager *)surplus;
        if ( v8 != nullptr )
          *v8 = j;
      }
    }
  }
  else
  {
    v9 = 0;
    for ( i = 0; v9 < v3->m_ManagedNonWeapons.m_Size; i = v9 )
    {
      v10 = v9;
      m_Index = v3->m_ManagedNonWeapons.m_Memory.m_pMemory[v9].m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity,
            v22 = m_pEntity,
            m_pEntity != nullptr) )
      {
        if ( ((int)m_pEntity[41].__vftable & 0x20) == 0 )
        {
          v13 = m_Size;
          if ( m_Size + 1 > candidates.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&candidates,
              num: m_Size - candidates.m_Memory.m_nAllocationCount + 1);
            m_Size = candidates.m_Size;
          }
          v14 = candidates.m_Memory.m_pMemory;
          candidates.m_Size = ++m_Size;
          candidates.m_pElements = candidates.m_Memory.m_pMemory;
          if ( m_Size - v13 - 1 > 0 )
            _V_memmove(
              dest: &candidates.m_Memory.m_pMemory[v13 + 1],
              src: &candidates.m_Memory.m_pMemory[v13],
              count: 4 * (m_Size - v13 - 1));
          v15 = &v14[v13];
          v3 = (CGameWeaponManager *)surplus;
          if ( v15 != nullptr )
            *v15 = (CBaseEntity *)v22;
        }
      }
      else
      {
        v16 = v3->m_ManagedNonWeapons.m_Size;
        if ( v16 > 0 )
        {
          if ( i != v16 - 1 )
            v3->m_ManagedNonWeapons.m_Memory.m_pMemory[v10].m_Index = v3->m_ManagedNonWeapons.m_Memory.m_pMemory[v16 - 1].m_Index;
          --v3->m_ManagedNonWeapons.m_Size;
        }
        --i;
      }
      v9 = i + 1;
    }
  }
  v17 = m_Size - v3->m_iMaxPieces;
  v18 = 0;
  surplus = v17;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( v17 > 0 )
    {
      v19 = candidates.m_Memory.m_pMemory[v18];
      if ( gpGlobals->maxClients != 1 )
        goto LABEL_44;
      LocalPlayer = UTIL_GetLocalPlayer();
      if ( UTIL_FindClientInPVS(pEdict: v19->m_Network.m_pPev) == nullptr
        || !LocalPlayer->FInViewCone(this: LocalPlayer, a2: v19) )
      {
        goto LABEL_44;
      }
      if ( (v19->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v19, a2: (int)&savedregs);
      if ( (LocalPlayer->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: LocalPlayer, a2: (int)&savedregs);
      if ( (float)((float)(fabs(LocalPlayer->m_vecAbsOrigin.y - v19->m_vecAbsOrigin.y)
                         + fabs(LocalPlayer->m_vecAbsOrigin.x - v19->m_vecAbsOrigin.x))
                 + fabs(LocalPlayer->m_vecAbsOrigin.z - v19->m_vecAbsOrigin.z)) > 360.0 )
      {
LABEL_44:
        CBaseEntity::AddEffects(this: v19, nEffects: 32);
        UTIL_Remove(oldObj: v19);
        _DevMsg(a1: 2, a2: "Surplus %s removed\n", pszWeaponName);
        --surplus;
      }
      v18 = i + 1;
      i = v18;
      if ( v18 >= m_Size )
        break;
      v17 = surplus;
    }
  }
  if ( candidates.m_Memory.m_nGrowSize >= 0 && candidates.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: candidates.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10404DE0
// Name: CGameWeaponManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGameWeaponManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGameWeaponManager>(__formal: nullptr);
  CGameWeaponManager_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10152FB0
// Name: struct datamap_t __near * DataMapInit<class CGameWeaponManager>(class CGameWeaponManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGameWeaponManager>()
{
  if ( (_S2_129 & 1) == 0 )
  {
    _S2_129 |= 1u;
    nameHolder_226.m_pszBase = "CGameWeaponManager";
    nameHolder_226.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_226.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_226.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_226.m_Names.m_Size = 0;
    nameHolder_226.m_Names.m_pElements = nullptr;
    nameHolder_226.m_nLenBase = 18;
    atexit(func: DataMapInit_CGameWeaponManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGameWeaponManager::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_129 & 2) == 0 )
  {
    _S2_129 |= 2u;
    dataDesc_214[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_226,
                                  pszIdentifier: "Think");
    dataDesc_214[5].fieldSize = 1;
    dataDesc_214[5].flags = 32;
    *(_QWORD *)&dataDesc_214[5].td = 0;
    *(_QWORD *)&dataDesc_214[5].override_field = 0;
    *(_QWORD *)&dataDesc_214[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_214[5].flatOffset[1] = 0;
    dataDesc_214[6].fieldSize = 1;
    dataDesc_214[6].flags = 8;
    dataDesc_214[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_214[6].td = 0;
    *(_QWORD *)&dataDesc_214[6].override_field = 0;
    *(_QWORD *)&dataDesc_214[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_214[6].flatOffset[1] = 0;
    dataDesc_214[5].fieldOffset = 0;
    dataDesc_214[5].externalName = nullptr;
    dataDesc_214[5].pSaveRestoreOps = nullptr;
    dataDesc_214[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBaseEntity::`vcall'{200,{flat}};
    dataDesc_214[6].fieldType = FIELD_INTEGER;
    dataDesc_214[6].fieldName = "InputSetMaxPieces";
    dataDesc_214[6].fieldOffset = 0;
    dataDesc_214[6].externalName = "SetMaxPieces";
    dataDesc_214[6].pSaveRestoreOps = nullptr;
    dataDesc_214[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicAutosave::InputSetMinHitpointsThreshold;
    dataDesc_214[7].fieldType = FIELD_FLOAT;
    dataDesc_214[7].fieldName = "InputSetAmmoModifier";
    dataDesc_214[7].fieldOffset = 0;
    dataDesc_214[7].flags = 8;
    dataDesc_214[7].externalName = "SetAmmoModifier";
    dataDesc_214[7].pSaveRestoreOps = nullptr;
    dataDesc_214[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_SpeechFilter::InputSetIdleModifier;
    *(_QWORD *)&dataDesc_214[7].td = 0;
    *(_QWORD *)&dataDesc_214[7].override_field = 0;
    *(_QWORD *)&dataDesc_214[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_214[7].flatOffset[1] = 0;
    dataDesc_214[8].fieldType = FIELD_CUSTOM;
    dataDesc_214[8].fieldName = "m_ManagedNonWeapons";
    dataDesc_214[8].fieldOffset = 868;
    dataDesc_214[8].fieldSize = 1;
    dataDesc_214[8].flags = 2;
    dataDesc_214[8].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    dataDesc_214[8].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_214[8].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_214[8].td = 0;
    *(_QWORD *)&dataDesc_214[8].override_field = 0;
    *(_QWORD *)&dataDesc_214[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_214[8].flatOffset[1] = 0;
  }
  CGameWeaponManager::m_DataMap.dataNumFields = 8;
  CGameWeaponManager::m_DataMap.dataDesc = &dataDesc_214[1];
  return &CGameWeaponManager::m_DataMap;
}
