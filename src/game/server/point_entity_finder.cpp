// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/point_entity_finder.cpp
// Functions: 7
// ============================================================

#include "game\server\point_entity_finder.h"

//------------------------------------------------------------------------------
// Address: 0x101D2640
// Name: private: virtual struct datamap_t __near * CPointEntityFinder::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointEntityFinder::GetDataDescMap(CPointEntityFinder *this)
{
  return &CPointEntityFinder::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D2650
// Name: private: void CPointEntityFinder::FindByDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointEntityFinder::FindByDistance(CPointEntityFinder *this)
{
  unsigned int m_Index; // eax
  CPointEntityFinder *Ent; // esi
  const char *pszValue; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  CBaseEntity *v9; // eax
  float *v10; // edi
  float z; // xmm0_4
  float v12; // xmm1_4
  EntFinderMethod_t m_FindMethod; // eax
  float v14; // xmm0_4
  bool v15; // cc
  float vecStart; // [esp+8h] [ebp-18h]
  float vecStart_4; // [esp+Ch] [ebp-14h]
  float vecStart_8; // [esp+10h] [ebp-10h]
  float flNewDist; // [esp+14h] [ebp-Ch]
  CBaseFilter *m_pEntity; // [esp+18h] [ebp-8h]
  float flBestDist; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  this->m_hEntity.m_Index = -1;
  m_Index = this->m_hFilter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  flBestDist = 0.0;
  Ent = (CPointEntityFinder *)CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
  if ( Ent != nullptr )
  {
    while ( 1 )
    {
      pszValue = Ent->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      if ( pszValue == "worldspawn" || _V_stricmp(s1: pszValue, s2: "worldspawn") == 0 )
        goto LABEL_49;
      v5 = Ent->m_iClassname.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      if ( v5 == "soundent" || _V_stricmp(s1: v5, s2: "soundent") == 0 )
        goto LABEL_49;
      v6 = Ent->m_iClassname.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      if ( v6 == "player_manager" || _V_stricmp(s1: v6, s2: "player_manager") == 0 )
        goto LABEL_49;
      v7 = Ent->m_iClassname.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      if ( v7 == "bodyque" || _V_stricmp(s1: v7, s2: "bodyque") == 0 )
        goto LABEL_49;
      v8 = Ent->m_iClassname.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      if ( v8 == "ai_network"
        || _V_stricmp(s1: v8, s2: "ai_network") == 0
        || Ent == this
        || m_pEntity != nullptr
        && (unsigned __int8)CBaseFilter::PassesFilter(this: m_pEntity, pCaller: this, pEntity: Ent) == 0 )
      {
        goto LABEL_49;
      }
      if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hReference) != nullptr )
      {
        v9 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hReference);
        v10 = (float *)v9;
        if ( (v9->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
        vecStart = v10[115];
        vecStart_4 = v10[116];
        z = v10[117];
      }
      else
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        vecStart = this->m_vecAbsOrigin.x;
        vecStart_4 = this->m_vecAbsOrigin.y;
        z = this->m_vecAbsOrigin.z;
      }
      vecStart_8 = z;
      if ( CHandle<CBaseEntity>::operator==(this: &this->m_hEntity, val: nullptr) )
      {
        CHandle<CBaseEntity>::operator=(this: &this->m_hEntity, val: Ent);
        if ( (Ent->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: Ent, a2: (int)&savedregs);
        v12 = (float)((float)((float)(Ent->m_vecAbsOrigin.x - vecStart) * (float)(Ent->m_vecAbsOrigin.x - vecStart))
                    + (float)((float)(Ent->m_vecAbsOrigin.y - vecStart_4) * (float)(Ent->m_vecAbsOrigin.y - vecStart_4)))
            + (float)((float)(Ent->m_vecAbsOrigin.z - z) * (float)(Ent->m_vecAbsOrigin.z - z));
        flBestDist = v12;
      }
      else
      {
        v12 = flBestDist;
      }
      if ( (Ent->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: Ent, a2: (int)&savedregs);
        v12 = flBestDist;
      }
      m_FindMethod = this->m_FindMethod;
      v14 = (float)((float)((float)(Ent->m_vecAbsOrigin.x - vecStart) * (float)(Ent->m_vecAbsOrigin.x - vecStart))
                  + (float)((float)(Ent->m_vecAbsOrigin.y - vecStart_4) * (float)(Ent->m_vecAbsOrigin.y - vecStart_4)))
          + (float)((float)(Ent->m_vecAbsOrigin.z - z) * (float)(Ent->m_vecAbsOrigin.z - z));
      flNewDist = (float)((float)((float)(Ent->m_vecAbsOrigin.x - vecStart) * (float)(Ent->m_vecAbsOrigin.x - vecStart))
                        + (float)((float)(Ent->m_vecAbsOrigin.y - vecStart_4)
                                * (float)(Ent->m_vecAbsOrigin.y - vecStart_4)))
                + (float)((float)(Ent->m_vecAbsOrigin.z - vecStart_8) * (float)(Ent->m_vecAbsOrigin.z - vecStart_8));
      if ( m_FindMethod == ENT_FIND_METHOD_NEAREST )
        break;
      if ( m_FindMethod == ENT_FIND_METHOD_FARTHEST )
      {
        v15 = v14 <= v12;
        goto LABEL_47;
      }
LABEL_49:
      Ent = (CPointEntityFinder *)CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
      if ( Ent == nullptr )
        return;
    }
    v15 = v12 <= v14;
LABEL_47:
    if ( !v15 )
    {
      CHandle<CBaseEntity>::operator=(this: &this->m_hEntity, val: Ent);
      flBestDist = flNewDist;
    }
    goto LABEL_49;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2A90
// Name: private: void CPointEntityFinder::FindByRandom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointEntityFinder::FindByRandom(CPointEntityFinder *this)
{
  CPointEntityFinder *v1; // edi
  unsigned int m_Index; // eax
  int m_Size; // esi
  CBaseEntity **m_pMemory; // ebx
  int v5; // edi
  CBaseEntity **v6; // edi
  IUniformRandomStream *v7; // ecx
  CBaseEntity *v8; // ebx
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > ValidEnts; // [esp+Ch] [ebp-20h] BYREF
  CPointEntityFinder *v10; // [esp+20h] [ebp-Ch]
  CBaseFilter *m_pEntity; // [esp+24h] [ebp-8h]
  CBaseEntity *pEntity; // [esp+28h] [ebp-4h]

  v1 = this;
  this->m_hEntity.m_Index = -1;
  m_Index = this->m_hFilter.m_Index;
  m_Size = 0;
  v10 = this;
  if ( m_Index == -1 )
  {
    m_pEntity = nullptr;
  }
  else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  else
  {
    m_pEntity = nullptr;
  }
  m_pMemory = nullptr;
  memset(&ValidEnts, 0, sizeof(ValidEnts));
  pEntity = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
  do
  {
    if ( m_pEntity != nullptr && (unsigned __int8)CBaseFilter::PassesFilter(this: m_pEntity, pCaller: v1, pEntity) != 0 )
    {
      v5 = m_Size;
      if ( m_Size + 1 > ValidEnts.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&ValidEnts,
          num: m_Size - ValidEnts.m_Memory.m_nAllocationCount + 1);
        m_Size = ValidEnts.m_Size;
        m_pMemory = ValidEnts.m_Memory.m_pMemory;
      }
      ValidEnts.m_Size = ++m_Size;
      ValidEnts.m_pElements = m_pMemory;
      if ( m_Size - v5 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * (m_Size - v5 - 1));
      v6 = &m_pMemory[v5];
      if ( v6 != nullptr )
        *v6 = pEntity;
      v1 = v10;
    }
    pEntity = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: pEntity);
  }
  while ( pEntity != nullptr );
  if ( m_Size != 0 )
  {
    v8 = m_pMemory[_RandomInt(this: v7, a2: 0, a3: m_Size - 1)];
    if ( v8 != nullptr )
    {
      v1->m_hEntity.m_Index = v8->GetRefEHandle(this: v8)->m_Index;
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ValidEnts);
      return;
    }
    v1->m_hEntity.m_Index = -1;
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ValidEnts);
}

//------------------------------------------------------------------------------
// Address: 0x101D2C00
// Name: private: void CPointEntityFinder::FindEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointEntityFinder::FindEntity(CPointEntityFinder *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  EntFinderMethod_t m_FindMethod; // eax
  __int32 v5; // eax

  pszValue = this->m_iRefName.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
      this->m_hReference.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
    else
      this->m_hReference.m_Index = -1;
  }
  m_FindMethod = this->m_FindMethod;
  if ( m_FindMethod != ENT_FIND_METHOD_NEAREST && (v5 = m_FindMethod - 1) != 0 )
  {
    if ( v5 == 1 )
      CPointEntityFinder::FindByRandom(this);
  }
  else
  {
    CPointEntityFinder::FindByDistance(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2C70
// Name: private: void CPointEntityFinder::InputFindEntity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointEntityFinder::InputFindEntity(CPointEntityFinder *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax

  CPointEntityFinder::FindEntity(this);
  m_Index = this->m_hEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  COutputEvent::FireOutput(
    this: &this->m_OnFoundEntity,
    pActivator: inputdata->pActivator,
    pCaller: m_pEntity,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x104086D0
// Name: CPointEntityFinder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointEntityFinder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointEntityFinder>(__formal: nullptr);
  CPointEntityFinder_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D2CD0
// Name: struct datamap_t __near * DataMapInit<class CPointEntityFinder>(class CPointEntityFinder __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointEntityFinder>()
{
  if ( (_S2_177 & 1) == 0 )
  {
    _S2_177 |= 1u;
    nameHolder_337.m_pszBase = "CPointEntityFinder";
    nameHolder_337.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_337.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_337.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_337.m_Names.m_Size = 0;
    nameHolder_337.m_Names.m_pElements = nullptr;
    nameHolder_337.m_nLenBase = 18;
    atexit(func: DataMapInit_CPointEntityFinder__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointEntityFinder::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_177 & 2) == 0 )
  {
    _S2_177 |= 2u;
    *(_QWORD *)&dataDesc_322[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_322[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_322[6].override_count = 0;
    *(_QWORD *)dataDesc_322[6].flatOffset = 0;
    dataDesc_322[6].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_322[6].flatGroup = 0;
    dataDesc_322[7].fieldType = FIELD_VOID;
    dataDesc_322[7].fieldName = "InputFindEntity";
    dataDesc_322[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_322[7].fieldSize = 524289;
    dataDesc_322[7].externalName = "FindEntity";
    dataDesc_322[7].pSaveRestoreOps = nullptr;
    dataDesc_322[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointEntityFinder::InputFindEntity;
    *(_QWORD *)&dataDesc_322[7].td = 0;
    *(_QWORD *)&dataDesc_322[7].override_field = 0;
    *(_QWORD *)&dataDesc_322[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_322[7].flatOffset[1] = 0;
  }
  CPointEntityFinder::m_DataMap.dataNumFields = 7;
  CPointEntityFinder::m_DataMap.dataDesc = &dataDesc_322[1];
  return &CPointEntityFinder::m_DataMap;
}
