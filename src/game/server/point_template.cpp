// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/point_template.cpp
// Functions: 65
// ============================================================

#include "game\server\point_template.h"

//------------------------------------------------------------------------------
// Address: 0x100FAA60
// Name: public: virtual void CPointTemplatePrecacher::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplatePrecacher::LevelInitPreEntity(CVisibilityMonitor *this)
{
  this->m_Entities.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D6920
// Name: public: virtual struct datamap_t __near * CPointTemplate::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointTemplate::GetDataDescMap(CPointTemplate *this)
{
  return &CPointTemplate::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D6930
// Name: public: bool CPointTemplate::ShouldRemoveTemplateEntities(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPointTemplate::ShouldRemoveTemplateEntities(CPointTemplate *this)
{
  return (this->m_spawnflags.m_Value & 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D6940
// Name: public: int CPointTemplate::GetNumTemplates(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPointTemplate::GetNumTemplates(CPointTemplate *this)
{
  return this->m_hTemplates.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101D6A30
// Name: public: virtual void CPointTemplate::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplate::Spawn(CPointTemplate *this)
{
  this->Precache(this);
  if ( g_pScriptVM != nullptr && !g_pScriptVM->ValueExists(this: g_pScriptVM, a2: nullptr, a3: "__ExecutePreSpawn") )
    g_pScriptVM->Run_3(this: g_pScriptVM, a2: (const char *)g_Script_spawn_helper, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x101D6A70
// Name: public: bool CPointTemplate::AllowNameFixup(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPointTemplate::AllowNameFixup(CPointTemplate *this)
{
  return (this->m_spawnflags.m_Value & 2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D6A80
// Name: public: int CPointTemplate::GetTemplateIndexForTemplate(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPointTemplate::GetTemplateIndexForTemplate(CPointTemplate *this, int iTemplate)
{
  return this->m_hTemplates.m_Memory.m_pMemory[iTemplate].iTemplateIndex;
}

//------------------------------------------------------------------------------
// Address: 0x101D6AA0
// Name: public: class CBaseEntity __near * CPointTemplate::GetTemplateEntity(int)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CPointTemplate::GetTemplateEntity(CPointTemplate *this, int iTemplateNumber)
{
  return this->m_hTemplateEntities.m_Memory.m_pMemory[iTemplateNumber];
}

//------------------------------------------------------------------------------
// Address: 0x101D6AC0
// Name: public: virtual void CPointTemplate::PerformPrecache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplate::PerformPrecache(CPointTemplate *this)
{
  CPointTemplate *v1; // edi
  int m_Size; // esi
  const char *pszValue; // edi
  int v4; // ebx
  template_t *m_pMemory; // eax
  int iTemplateIndex; // esi
  const char *EntityIOFixedMapData; // edi
  int iIndex; // [esp+8h] [ebp-10h] BYREF
  int nStringSize; // [esp+Ch] [ebp-Ch] BYREF
  CPointTemplate *v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v1 = this;
  m_Size = this->m_hTemplates.m_Size;
  v10 = this;
  if ( m_Size != 0 )
  {
    Templates_StartUniqueInstance();
    if ( m_Size > 0 )
    {
      v4 = 0;
      v11 = m_Size;
      while ( 1 )
      {
        m_pMemory = v1->m_hTemplates.m_Memory.m_pMemory;
        iTemplateIndex = m_pMemory[v4].iTemplateIndex;
        if ( (v1->m_spawnflags.m_Value & 2) != 0
          || !Templates_IndexRequiresEntityIOFixup(iIndex: m_pMemory[v4].iTemplateIndex) )
        {
          EntityIOFixedMapData = *(const char **)Templates_FindByIndex((int)&iIndex).pszValue;
          if ( EntityIOFixedMapData == nullptr )
            EntityIOFixedMapData = locale;
        }
        else
        {
          EntityIOFixedMapData = Templates_GetEntityIOFixedMapData(iIndex: iTemplateIndex);
        }
        nStringSize = Templates_GetStringSize(iIndex: iTemplateIndex);
        MapEntity_PrecacheEntity(pEntData: EntityIOFixedMapData, &nStringSize);
        ++v4;
        if ( --v11 == 0 )
          break;
        v1 = v10;
      }
    }
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Msg(a1: "Precache called on a point_template that has no templates: %s\n", pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6B90
// Name: bool ScriptPreInstanceSpawn(class CScriptScopeT<class CDefScriptScopeBase> __near *,class CBaseEntity __near *,struct string_t)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ScriptPreInstanceSpawn(CScriptScopeT<CDefScriptScopeBase> *pScriptScope, CBaseEntity *pChild)
{
  HSCRIPT__ *v2; // eax
  ScriptVariant_t v4; // [esp+4h] [ebp-8h] BYREF

  if ( pScriptScope->m_hScope == (HSCRIPT__ *)-1
    || !g_pScriptVM->ValueExists(this: g_pScriptVM, a2: pScriptScope->m_hScope, a3: "PreSpawnInstance") )
  {
    return 1;
  }
  *(_DWORD *)&v4.m_type = 0;
  v4.m_int = 0;
  v2 = pChild != nullptr ? CBaseEntity::GetScriptInstance(this: pChild) : nullptr;
  if ( CScriptScopeT<CDefScriptScopeBase>::Call<HSCRIPT__ *>(
         this: pScriptScope,
         pszFunction: "__ExecutePreSpawn",
         pReturn: &v4,
         arg1: v2) != 0 )
    return 1;
  if ( v4.m_type == 6 )
  {
    if ( v4.m_char != 0 )
      return 1;
  }
  else if ( v4.m_type != 5 || v4.m_int != 0 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D6C10
// Name: void ScriptPostSpawn(class CScriptScopeT<class CDefScriptScopeBase> __near *,class CBaseEntity __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall ScriptPostSpawn(
        int a1@<edi>,
        CScriptScopeT<CDefScriptScopeBase> *pScriptScope,
        CBaseEntity **ppEntities,
        int nEntities)
{
  CScriptScopeT<CDefScriptScopeBase> *v4; // ebx
  HSCRIPT__ *v5; // esi
  HSCRIPT__ *m_int; // edi
  int v7; // esi
  const char *pszValue; // eax
  char *v9; // eax
  CBaseEntity *v10; // ecx
  HSCRIPT__ *ScriptInstance; // eax
  HSCRIPT__ *m_hScope; // [esp-Ch] [ebp-124h]
  char szEntName[256]; // [esp+4h] [ebp-114h] BYREF
  HSCRIPT__ *hPostSpawnFunc; // [esp+104h] [ebp-14h]
  ScriptVariant_t varEntityMakerResultTable; // [esp+108h] [ebp-10h] BYREF
  HSCRIPT__ *v16; // [esp+110h] [ebp-8h] BYREF
  int v17; // [esp+114h] [ebp-4h]

  v4 = pScriptScope;
  if ( pScriptScope->m_hScope != (HSCRIPT__ *)-1 )
  {
    v5 = g_pScriptVM->LookupFunction(this: g_pScriptVM, a2: "PostSpawn", a3: pScriptScope->m_hScope);
    hPostSpawnFunc = v5;
    if ( v5 != nullptr )
    {
      *(_DWORD *)&varEntityMakerResultTable.m_type = 0;
      varEntityMakerResultTable.m_int = 0;
      if ( ((unsigned __int8 (__thiscall *)(IScriptVM *, HSCRIPT__ *, const char *, ScriptVariant_t *, int))g_pScriptVM->GetValue)(
             a1: g_pScriptVM,
             a2: pScriptScope->m_hScope != (HSCRIPT__ *)-1 ? pScriptScope->m_hScope : nullptr,
             a3: "__EntityMakerResult",
             a4: &varEntityMakerResultTable,
             a5: a1) != 0 )
      {
        if ( varEntityMakerResultTable.m_type == 33 )
        {
          m_int = (HSCRIPT__ *)varEntityMakerResultTable.m_int;
          v7 = 0;
          if ( nEntities > 0 )
          {
            do
            {
              pszValue = ppEntities[v7]->m_iName.m_Value.pszValue;
              if ( pszValue == nullptr )
                pszValue = locale;
              V_strncpy(pDest: szEntName, pSrc: pszValue, maxLen: 256);
              v9 = _V_strrchr(s: szEntName, c: 38);
              if ( v9 != nullptr )
                *v9 = 0;
              v10 = ppEntities[v7];
              if ( v10 != nullptr )
                ScriptInstance = CBaseEntity::GetScriptInstance(this: v10);
              else
                ScriptInstance = nullptr;
              v16 = ScriptInstance;
              v17 = 33;
              g_pScriptVM->SetValue(this: g_pScriptVM, a2: m_int, a3: szEntName, a4: (const ScriptVariant_t *)&v16);
              ++v7;
            }
            while ( v7 < nEntities );
            v4 = pScriptScope;
          }
          m_hScope = v4->m_hScope;
          v17 = 33;
          v16 = m_int;
          g_pScriptVM->ExecuteFunction(
            this: g_pScriptVM,
            a2: hPostSpawnFunc,
            a3: (ScriptVariant_t *)&v16,
            a4: 1,
            a5: nullptr,
            a6: m_hScope,
            a7: true);
          CScriptScopeT<CDefScriptScopeBase>::Call(this: v4, pszFunction: "__FinishSpawn", pReturn: nullptr);
          v5 = hPostSpawnFunc;
        }
        g_pScriptVM->ReleaseValue(this: g_pScriptVM, a2: &varEntityMakerResultTable);
      }
      g_pScriptVM->ReleaseFunction(this: g_pScriptVM, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6F70
// Name: public: void CPointTemplatePrecacher::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplatePrecacher::Precache(CPointTemplatePrecacher *this)
{
  int m_Size; // ebx
  int v3; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_Size = this->m_Ents.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
    this->m_Ents.m_Size = 0;
  }
  else
  {
    do
    {
      m_Index = this->m_Ents.m_Memory.m_pMemory[v3].m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
          m_pEntity->__vftable[64].GetRefEHandle(this: m_pEntity);
      }
      ++v3;
    }
    while ( v3 < m_Size );
    this->m_Ents.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6FE0
// Name: void PrecachePointTemplates(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecachePointTemplates()
{
  CPointTemplatePrecacher::Precache(this: &g_PointTemplatePrecacher);
}

//------------------------------------------------------------------------------
// Address: 0x101D6FF0
// Name: public: void CPointTemplate::CreationComplete(class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPointTemplate::CreationComplete(
        CPointTemplate *this@<ecx>,
        int a2@<edi>,
        const CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *entities)
{
  if ( entities->m_Size != 0 )
    ScriptPostSpawn(
      a1: a2,
      pScriptScope: &this->m_ScriptScope,
      ppEntities: entities->m_Memory.m_pMemory,
      nEntities: entities->m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x101D70A0
// Name: public: void CPointTemplate::FinishBuildingTemplates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplate::FinishBuildingTemplates(CPointTemplate *this)
{
  bool v2; // sf

  v2 = this->m_hTemplateEntities.m_Memory.m_nGrowSize < 0;
  this->m_hTemplateEntities.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_hTemplateEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hTemplateEntities.m_Memory.m_pMemory);
      this->m_hTemplateEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_hTemplateEntities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hTemplateEntities.m_pElements = this->m_hTemplateEntities.m_Memory.m_pMemory;
  Templates_ReconnectIOForGroup(pGroup: this);
}

//------------------------------------------------------------------------------
// Address: 0x101D7100
// Name: public: CPointTemplate::CPointTemplate(void)
// Source: json
//------------------------------------------------------------------------------
CPointTemplate *__thiscall CPointTemplate::CPointTemplate(CPointTemplate *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CPointTemplate_vtbl *)&CPointTemplate::`vftable';
  this->m_hTemplateEntities.m_Memory.m_pMemory = nullptr;
  this->m_hTemplateEntities.m_Memory.m_nAllocationCount = 0;
  this->m_hTemplateEntities.m_Memory.m_nGrowSize = 0;
  this->m_hTemplateEntities.m_Size = 0;
  this->m_hTemplateEntities.m_pElements = nullptr;
  this->m_hTemplates.m_Memory.m_pMemory = nullptr;
  this->m_hTemplates.m_Memory.m_nAllocationCount = 0;
  this->m_hTemplates.m_Memory.m_nGrowSize = 0;
  this->m_hTemplates.m_Size = 0;
  this->m_hTemplates.m_pElements = nullptr;
  this->m_pOutputOnSpawned.m_Value.iVal = 0;
  this->m_pOutputOnSpawned.m_Value.eVal.m_Index = -1;
  this->m_pOutputOnSpawned.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D7170
// Name: public: void CPointTemplatePrecacher::AddToPrecache(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplatePrecacher::AddToPrecache(CPointTemplatePrecacher *this, CBaseEntity *ent)
{
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<CPointTemplate> *m_pMemory; // ecx
  int v7; // eax
  CHandle<CPointTemplate> *v8; // eax

  if ( ent != nullptr )
    m_Index = ent->GetRefEHandle(this: ent)->m_Index;
  else
    m_Index = -1;
  m_nAllocationCount = this->m_Ents.m_Memory.m_nAllocationCount;
  m_Size = this->m_Ents.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Ents,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Ents.m_Size;
  m_pMemory = this->m_Ents.m_Memory.m_pMemory;
  v7 = this->m_Ents.m_Size - m_Size - 1;
  this->m_Ents.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Ents.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    v8->m_Index = m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x101D7220
// Name: public: virtual void CPointTemplate::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplate::Precache(CPointTemplate *this)
{
  CPointTemplatePrecacher::AddToPrecache(this: &g_PointTemplatePrecacher, ent: this);
}

//------------------------------------------------------------------------------
// Address: 0x101D7230
// Name: public: void CPointTemplate::StartBuildingTemplates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplate::StartBuildingTemplates(CPointTemplate *this)
{
  CPointTemplate *v1; // esi
  string_t *m_iszTemplateEntityNames; // edi
  CBaseEntity *EntityByName; // ebx
  const char *pszValue; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseEntity **m_pMemory; // ecx
  int v8; // eax
  CBaseEntity **v9; // ecx
  CBaseEntity **v10; // eax
  const char *v11; // ecx
  const char *v12; // eax
  bool v13; // zf
  int iOldNum; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  string_t *v16; // [esp+14h] [ebp-8h]

  v1 = this;
  m_iszTemplateEntityNames = this->m_iszTemplateEntityNames;
  v16 = this->m_iszTemplateEntityNames;
  v15 = 16;
  do
  {
    if ( m_iszTemplateEntityNames->pszValue != nullptr )
    {
      EntityByName = nullptr;
      iOldNum = v1->m_hTemplateEntities.m_Size;
      while ( 1 )
      {
        m_iszTemplateEntityNames = v16;
        pszValue = v16->pszValue;
        if ( v16->pszValue == nullptr )
          pszValue = locale;
        EntityByName = CGlobalEntityList::FindEntityByName(
                         this: &gEntList,
                         pStartEntity: EntityByName,
                         szName: pszValue,
                         pSearchingEntity: nullptr,
                         pActivator: nullptr,
                         pCaller: nullptr,
                         pFilter: nullptr);
        if ( EntityByName == nullptr )
          break;
        m_Size = v1->m_hTemplateEntities.m_Size;
        m_nAllocationCount = v1->m_hTemplateEntities.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_hTemplateEntities,
            num: m_Size - m_nAllocationCount + 1);
        ++v1->m_hTemplateEntities.m_Size;
        m_pMemory = v1->m_hTemplateEntities.m_Memory.m_pMemory;
        v8 = v1->m_hTemplateEntities.m_Size - m_Size - 1;
        v1->m_hTemplateEntities.m_pElements = m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = v1->m_hTemplateEntities.m_Memory.m_pMemory;
        v1 = this;
        v10 = &v9[m_Size];
        if ( v10 != nullptr )
          *v10 = EntityByName;
      }
      if ( iOldNum == v1->m_hTemplateEntities.m_Size )
      {
        v11 = v1->m_iName.m_Value.pszValue;
        if ( v11 == nullptr )
          v11 = locale;
        v12 = v16->pszValue;
        if ( v16->pszValue == nullptr )
          v12 = locale;
        _Warning(a1: "Couldn't find any entities named %s, which point_template %s is specifying.\n", v12, v11);
      }
    }
    ++m_iszTemplateEntityNames;
    v13 = v15-- == 1;
    v16 = m_iszTemplateEntityNames;
  }
  while ( !v13 );
}

//------------------------------------------------------------------------------
// Address: 0x101D7350
// Name: public: void CPointTemplate::AddTemplate(class CBaseEntity __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplate::AddTemplate(
        CPointTemplate *this,
        CBaseEntity *pEntity,
        const char *pszMapData,
        int nLen)
{
  int v5; // eax
  const char *pszValue; // esi
  unsigned int v7; // edx
  VMatrix matEntityToWorld; // [esp+8h] [ebp-144h] BYREF
  VMatrix matTemplateToWorld; // [esp+48h] [ebp-104h] BYREF
  VMatrix matEntityToTemplate; // [esp+88h] [ebp-C4h] BYREF
  VMatrix matWorldToTemplate; // [esp+C8h] [ebp-84h] BYREF
  template_t newTemplate; // [esp+108h] [ebp-44h] BYREF
  int savedregs; // [esp+14Ch] [ebp+0h] BYREF

  v5 = Templates_Add(pEntity, pszMapData, nLen, nHammerID: -1);
  if ( v5 == -1 )
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "point_template %s failed to add template.\n", pszValue);
  }
  else
  {
    v7 = (unsigned int)this->m_iEFlags >> 11;
    newTemplate.iTemplateIndex = v5;
    if ( (v7 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    VMatrix::SetupMatrixOrgAngles(
      this: &matTemplateToWorld,
      origin: &this->m_vecAbsOrigin,
      vAngles: &this->m_angAbsRotation);
    VMatrix::InverseTR(this: &matTemplateToWorld, ret: &matWorldToTemplate);
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    VMatrix::SetupMatrixOrgAngles(
      this: &matEntityToWorld,
      origin: &pEntity->m_vecAbsOrigin,
      vAngles: &pEntity->m_angAbsRotation);
    MatrixMultiply(src1: &matWorldToTemplate, src2: &matEntityToWorld, dst: &matEntityToTemplate);
    VMatrix::operator=(this: &newTemplate.matEntityToTemplate, mOther: &matEntityToTemplate);
    CUtlVector<template_t,CUtlMemory<template_t,int>>::InsertBefore(
      this: &this->m_hTemplates,
      elem: this->m_hTemplates.m_Size,
      src: &newTemplate);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7490
// Name: public: bool CPointTemplate::CreateInstance(class Vector const __near &,class QAngle const __near &,class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>> __near *,class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPointTemplate::CreateInstance(
        CPointTemplate *this,
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *pEntities,
        CBaseEntity *pEntityMaker,
        bool bCreateTime)
{
  int m_Size; // esi
  const char *pszValue; // edi
  void *v10; // esp
  HierarchicalSpawn_t *v11; // ebx
  CBaseEntity **v12; // esi
  int m_Value; // edx
  int v14; // ebx
  const char *EntityIOFixedMapData; // ebx
  int v16; // edi
  int m_nAllocationCount; // eax
  CBaseEntity **m_pMemory; // ecx
  int v19; // eax
  CBaseEntity **v20; // eax
  CBaseEntity *v21; // [esp-4h] [ebp-C8h]
  _BYTE v22[12]; // [esp+0h] [ebp-C4h] BYREF
  VMatrix matNewTemplateToWorld; // [esp+Ch] [ebp-B8h] BYREF
  VMatrix matStoredLocalToWorld; // [esp+4Ch] [ebp-78h] BYREF
  QAngle vecNewAngles; // [esp+8Ch] [ebp-38h] BYREF
  int iIndex; // [esp+98h] [ebp-2Ch] BYREF
  int v27; // [esp+9Ch] [ebp-28h] BYREF
  Vector vecNewOrigin; // [esp+A0h] [ebp-24h] BYREF
  int iTemplateIndex; // [esp+ACh] [ebp-18h]
  HierarchicalSpawn_t *pSpawnList; // [esp+B0h] [ebp-14h]
  int iTemplates; // [esp+B4h] [ebp-10h]
  int i; // [esp+B8h] [ebp-Ch]
  unsigned int v33; // [esp+BCh] [ebp-8h]
  CBaseEntity *pEntity; // [esp+C0h] [ebp-4h] BYREF
  const QAngle *vecAnglesa; // [esp+D0h] [ebp+Ch]

  m_Size = this->m_hTemplates.m_Size;
  iTemplates = m_Size;
  if ( m_Size != 0 )
  {
    Templates_StartUniqueInstance();
    v10 = alloca(16 * m_Size);
    v11 = (HierarchicalSpawn_t *)v22;
    pSpawnList = (HierarchicalSpawn_t *)v22;
    i = 0;
    if ( m_Size <= 0 )
    {
LABEL_21:
      SpawnHierarchicalList(nEntities: m_Size, pSpawnList: v11, bActivateEntities: true);
      if ( m_Size > 0 )
      {
        for ( vecAnglesa = (const QAngle *)m_Size;
              vecAnglesa != nullptr;
              vecAnglesa = (const QAngle *)((char *)vecAnglesa - 1) )
        {
          if ( v11->m_pEntity != nullptr )
          {
            v16 = pEntities->m_Size;
            m_nAllocationCount = pEntities->m_Memory.m_nAllocationCount;
            if ( v16 + 1 > m_nAllocationCount )
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)pEntities,
                num: v16 - m_nAllocationCount + 1);
            ++pEntities->m_Size;
            m_pMemory = pEntities->m_Memory.m_pMemory;
            v19 = pEntities->m_Size - v16 - 1;
            pEntities->m_pElements = pEntities->m_Memory.m_pMemory;
            if ( v19 > 0 )
              _V_memmove(dest: &m_pMemory[v16 + 1], src: &m_pMemory[v16], count: 4 * v19);
            v20 = &pEntities->m_Memory.m_pMemory[v16];
            if ( v20 != nullptr )
              *v20 = v11->m_pEntity;
          }
          ++v11;
        }
      }
      return 1;
    }
    else
    {
      v33 = 0;
      v12 = (CBaseEntity **)v22;
      while ( 1 )
      {
        m_Value = this->m_spawnflags.m_Value;
        pEntity = nullptr;
        v14 = this->m_hTemplates.m_Memory.m_pMemory[v33 / 0x44].iTemplateIndex;
        iTemplateIndex = v14;
        if ( (m_Value & 2) != 0
          || !Templates_IndexRequiresEntityIOFixup(iIndex: v14) && this->m_ScriptScope.m_hScope == (HSCRIPT__ *)-1 )
        {
          EntityIOFixedMapData = *(const char **)Templates_FindByIndex((int)&iIndex).pszValue;
          if ( EntityIOFixedMapData == nullptr )
            EntityIOFixedMapData = locale;
        }
        else
        {
          EntityIOFixedMapData = Templates_GetEntityIOFixedMapData(iIndex: v14);
        }
        MapEntity_ParseEntity(&pEntity, pEntData: EntityIOFixedMapData, pFilter: nullptr);
        if ( pEntity == nullptr )
          break;
        VMatrix::SetupMatrixOrgAngles(this: &matNewTemplateToWorld, origin: vecOrigin, vAngles: vecAngles);
        MatrixMultiply(
          src1: &matNewTemplateToWorld,
          src2: &this->m_hTemplates.m_Memory.m_pMemory[v33 / 0x44].matEntityToTemplate,
          dst: &matStoredLocalToWorld);
        vecNewOrigin.x = matStoredLocalToWorld.m[0][3];
        vecNewOrigin.y = matStoredLocalToWorld.m[1][3];
        vecNewOrigin.z = matStoredLocalToWorld.m[2][3];
        MatrixAngles(a1: (int)v12, src: &matStoredLocalToWorld, vAngles: &vecNewAngles);
        CBaseEntity::SetAbsOrigin(this: pEntity, absOrigin: &vecNewOrigin);
        CBaseEntity::SetAbsAngles(this: pEntity, absAngles: &vecNewAngles);
        if ( (this->m_spawnflags.m_Value & 2) == 0 )
          pEntity->m_bForcePurgeFixedupStrings = true;
        Templates_FindByIndex(iIndex: (int)&v27);
        if ( ScriptPreInstanceSpawn(pScriptScope: &this->m_ScriptScope, pChild: pEntity) != 0 )
        {
          *v12 = pEntity;
        }
        else
        {
          v21 = pEntity;
          *v12 = nullptr;
          UTIL_RemoveImmediate(oldObj: v21);
        }
        v33 += 68;
        v12[1] = nullptr;
        v12[2] = nullptr;
        v12 += 4;
        if ( ++i >= iTemplates )
        {
          v11 = pSpawnList;
          m_Size = iTemplates;
          goto LABEL_21;
        }
      }
      _Msg(a1: "Failed to initialize templated entity with mapdata: %s\n", EntityIOFixedMapData);
      return 0;
    }
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Msg(a1: "CreateInstance called on a point_template that has no templates: %s\n", pszValue);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7720
// Name: public: void CPointTemplate::InputForceSpawn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointTemplate::InputForceSpawn(CPointTemplate *this, inputdata_t *inputdata)
{
  unsigned int v3; // eax
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > hNewEntities; // [esp+Ch] [ebp-14h] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  v3 = (unsigned int)this->m_iEFlags >> 11;
  memset(&hNewEntities, 0, sizeof(hNewEntities));
  if ( (v3 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( CPointTemplate::CreateInstance(
         this,
         vecOrigin: &this->m_vecAbsOrigin,
         vecAngles: &this->m_angAbsRotation,
         pEntities: &hNewEntities,
         pEntityMaker: nullptr,
         bCreateTime: false) != 0 )
  {
    if ( hNewEntities.m_Size != 0 )
      ScriptPostSpawn(
        a1: 0,
        pScriptScope: &this->m_ScriptScope,
        ppEntities: hNewEntities.m_Memory.m_pMemory,
        nEntities: hNewEntities.m_Size);
    COutputEvent::FireOutput(this: &this->m_pOutputOnSpawned, pActivator: this, pCaller: this, fDelay: 0.0);
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hNewEntities);
}

//------------------------------------------------------------------------------
// Address: 0x1022F990
// Name: public: int CPointTemplate::GetNumTemplateEntities(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPointTemplate::GetNumTemplateEntities(CPointTemplate *this)
{
  return this->m_hTemplateEntities.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10400D70
// Name: _dynamic_initializer_for__point_clientcommand__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_clientcommand__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointClientCommand> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_clientcommand,
           a3: "point_clientcommand");
}

//------------------------------------------------------------------------------
// Address: 0x10400DA0
// Name: _dynamic_initializer_for__point_servercommand__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_servercommand__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointServerCommand> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_servercommand,
           a3: "point_servercommand");
}

//------------------------------------------------------------------------------
// Address: 0x10400DD0
// Name: _dynamic_initializer_for__point_broadcastclientcommand__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_broadcastclientcommand__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointBroadcastClientCommand> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_broadcastclientcommand,
           a3: "point_broadcastclientcommand");
}

//------------------------------------------------------------------------------
// Address: 0x10401560
// Name: _dynamic_initializer_for__point_commentary_node__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_commentary_node__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointCommentaryNode> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_commentary_node,
           a3: "point_commentary_node");
}

//------------------------------------------------------------------------------
// Address: 0x10401580
// Name: _dynamic_initializer_for__point_commentary_viewpoint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_commentary_viewpoint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CCommentaryViewPosition> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_commentary_viewpoint,
           a3: "point_commentary_viewpoint");
}

//------------------------------------------------------------------------------
// Address: 0x10404C70
// Name: _dynamic_initializer_for__point_gamestats_counter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_gamestats_counter__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointGamestatsCounter> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_gamestats_counter,
           a3: "point_gamestats_counter");
}

//------------------------------------------------------------------------------
// Address: 0x10405DC0
// Name: _dynamic_initializer_for__point_message__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_message__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CMessageEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_message,
           a3: "point_message");
}

//------------------------------------------------------------------------------
// Address: 0x10408590
// Name: _dynamic_initializer_for__point_bonusmaps_accessor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_bonusmaps_accessor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointBonusMapsAccessor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_bonusmaps_accessor,
           a3: "point_bonusmaps_accessor");
}

//------------------------------------------------------------------------------
// Address: 0x104085D0
// Name: _dynamic_initializer_for__point_camera__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_camera__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointCamera> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_camera,
           a3: "point_camera");
}

//------------------------------------------------------------------------------
// Address: 0x10408660
// Name: _dynamic_initializer_for__point_devshot_camera__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_devshot_camera__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointDevShotCamera> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_devshot_camera,
           a3: "point_devshot_camera");
}

//------------------------------------------------------------------------------
// Address: 0x104086B0
// Name: _dynamic_initializer_for__point_entity_finder__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_entity_finder__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointEntityFinder> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_entity_finder,
           a3: "point_entity_finder");
}

//------------------------------------------------------------------------------
// Address: 0x104086E0
// Name: _dynamic_initializer_for__point_playermoveconstraint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_playermoveconstraint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointPlayerMoveConstraint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_playermoveconstraint,
           a3: "point_playermoveconstraint");
}

//------------------------------------------------------------------------------
// Address: 0x10408710
// Name: _dynamic_initializer_for__point_posecontroller__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_posecontroller__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPoseController> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_posecontroller,
           a3: "point_posecontroller");
}

//------------------------------------------------------------------------------
// Address: 0x104087A0
// Name: _dynamic_initializer_for__point_spotlight__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_spotlight__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointSpotlight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_spotlight,
           a3: "point_spotlight");
}

//------------------------------------------------------------------------------
// Address: 0x104087C0
// Name: _dynamic_initializer_for__point_template__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_template__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointTemplate> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_template,
           a3: "point_template");
}

//------------------------------------------------------------------------------
// Address: 0x104087E0
// Name: template_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *template_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<template_t>();
  template_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104087F0
// Name: CPointTemplate_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointTemplate_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointTemplate>();
  CPointTemplate_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408840
// Name: _dynamic_initializer_for__point_anglesensor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_anglesensor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointAngleSensor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_anglesensor,
           a3: "point_anglesensor");
}

//------------------------------------------------------------------------------
// Address: 0x10408870
// Name: _dynamic_initializer_for__point_proximity_sensor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_proximity_sensor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointProximitySensor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_proximity_sensor,
           a3: "point_proximity_sensor");
}

//------------------------------------------------------------------------------
// Address: 0x104088D0
// Name: _dynamic_initializer_for__point_angularvelocitysensor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_angularvelocitysensor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointAngularVelocitySensor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_angularvelocitysensor,
           a3: "point_angularvelocitysensor");
}

//------------------------------------------------------------------------------
// Address: 0x10408900
// Name: _dynamic_initializer_for__point_velocitysensor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_velocitysensor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointVelocitySensor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_velocitysensor,
           a3: "point_velocitysensor");
}

//------------------------------------------------------------------------------
// Address: 0x10408940
// Name: _dynamic_initializer_for__point_hurt__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_hurt__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointHurt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_hurt,
           a3: "point_hurt");
}

//------------------------------------------------------------------------------
// Address: 0x10408960
// Name: _dynamic_initializer_for__point_teleport__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_teleport__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPointTeleport> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_teleport,
           a3: "point_teleport");
}

//------------------------------------------------------------------------------
// Address: 0x10408D40
// Name: _dynamic_initializer_for__point_enable_motion_fixup__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_enable_motion_fixup__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnableMotionFixup> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_enable_motion_fixup,
           a3: "point_enable_motion_fixup");
}

//------------------------------------------------------------------------------
// Address: 0x1040B3F0
// Name: _dynamic_initializer_for__point_tesla__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_tesla__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTesla> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_tesla,
           a3: "point_tesla");
}

//------------------------------------------------------------------------------
// Address: 0x1040BD90
// Name: _dynamic_initializer_for__point_viewcontrol__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_viewcontrol__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerCamera> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_viewcontrol,
           a3: "point_viewcontrol");
}

//------------------------------------------------------------------------------
// Address: 0x1040BDF0
// Name: _dynamic_initializer_for__point_viewcontrol_multiplayer__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_viewcontrol_multiplayer__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerCameraMultiplayer> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_viewcontrol_multiplayer,
           a3: "point_viewcontrol_multiplayer");
}

//------------------------------------------------------------------------------
// Address: 0x1040BE20
// Name: _dynamic_initializer_for__point_viewproxy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_viewproxy__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTriggerViewProxy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_viewproxy,
           a3: "point_viewproxy");
}

//------------------------------------------------------------------------------
// Address: 0x10410500
// Name: _dynamic_initializer_for__point_surroundtest__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__point_surroundtest__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSurroundTest> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &point_surroundtest,
           a3: "point_surroundtest");
}

//------------------------------------------------------------------------------
// Address: 0x10400DF0
// Name: _dynamic_initializer_for__drawline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__drawline__()
{
  ConCommand::ConCommand(
    this: &drawline,
    pName: "drawline",
    callback: (void (__cdecl *)())CC_DrawLine,
    pHelpString: "Draws line between two 3D Points.\n"
    "\tGreen if no collision\n"
    "\tRed is collides with something\n"
    "\tArguments: x1 y1 z1 x2 y2 z2",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__drawline__);
}

//------------------------------------------------------------------------------
// Address: 0x10400E20
// Name: _dynamic_initializer_for__drawcross__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__drawcross__()
{
  ConCommand::ConCommand(
    this: &drawcross,
    pName: "drawcross",
    callback: (void (__cdecl *)())CC_DrawCross,
    pHelpString: "Draws a cross at the given location\n\tArguments: x y z",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__drawcross__);
}

//------------------------------------------------------------------------------
// Address: 0x104015A0
// Name: _dynamic_initializer_for__g_CommentarySystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CommentarySystem__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_CommentarySystem, name: "CCommentarySystem");
  g_CommentarySystem.__vftable = (CCommentarySystem_vtbl *)&CCommentarySystem::`vftable';
  g_CommentarySystem.m_ModifiedConvars.m_Memory.m_pMemory = nullptr;
  g_CommentarySystem.m_ModifiedConvars.m_Memory.m_nAllocationCount = 0;
  g_CommentarySystem.m_ModifiedConvars.m_Memory.m_nGrowSize = 0;
  g_CommentarySystem.m_ModifiedConvars.m_Size = 0;
  g_CommentarySystem.m_ModifiedConvars.m_pElements = nullptr;
  g_CommentarySystem.m_hSpawnedEntities.m_Memory.m_pMemory = nullptr;
  g_CommentarySystem.m_hSpawnedEntities.m_Memory.m_nAllocationCount = 0;
  g_CommentarySystem.m_hSpawnedEntities.m_Memory.m_nGrowSize = 0;
  g_CommentarySystem.m_hSpawnedEntities.m_Size = 0;
  g_CommentarySystem.m_hSpawnedEntities.m_pElements = nullptr;
  g_CommentarySystem.m_hCurrentNode.m_Index = -1;
  g_CommentarySystem.m_hActiveCommentaryNode.m_Index = -1;
  g_CommentarySystem.m_hLastCommentaryNode.m_Index = -1;
  g_CommentarySystem.m_iCommentaryNodeCount = 0;
  g_CommentarySystem.m_pkvSavedModifications = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_CommentarySystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10404C90
// Name: _dynamic_initializer_for__g_GameStringPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameStringPool__()
{
  CStringPool::CStringPool(this: &g_GameStringPool.CStringPool, caseSensitivity: StringPoolCaseInsensitive);
  g_GameStringPool.__vftable = (CGameStringPool_vtbl *)&CGameStringPool::`vftable';
  g_GameStringPool.m_DeferredDeleteList.m_Memory.m_pMemory = nullptr;
  g_GameStringPool.m_DeferredDeleteList.m_Memory.m_nAllocationCount = 0;
  g_GameStringPool.m_DeferredDeleteList.m_Memory.m_nGrowSize = 0;
  g_GameStringPool.m_DeferredDeleteList.m_Size = 0;
  g_GameStringPool.m_DeferredDeleteList.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_GameStringPool__);
}

//------------------------------------------------------------------------------
// Address: 0x10404CE0
// Name: _dynamic_initializer_for__dumpgamestringtable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dumpgamestringtable__()
{
  ConCommand::ConCommand(
    this: &dumpgamestringtable,
    pName: "dumpgamestringtable",
    callback: CC_DumpGameStringTable,
    pHelpString: "Dump the contents of the game string table to the console.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dumpgamestringtable__);
}

//------------------------------------------------------------------------------
// Address: 0x10404D10
// Name: _dynamic_initializer_for__mp_forcecamera__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_forcecamera__()
{
  ConVar::ConVar(
    this: &mp_forcecamera,
    pName: "mp_forcecamera",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Restricts spectator modes for dead players",
    callback: MPForceCameraCallback);
  return atexit(func: dynamic_atexit_destructor_for__mp_forcecamera__);
}

//------------------------------------------------------------------------------
// Address: 0x10404D40
// Name: _dynamic_initializer_for__mp_allowspectators__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_allowspectators__()
{
  ConVar::ConVar(
    this: &mp_allowspectators,
    pName: "mp_allowspectators",
    pDefaultValue: "1.0",
    flags: 0x2000,
    pHelpString: "toggles whether the server allows spectator mode or not");
  return atexit(func: dynamic_atexit_destructor_for__mp_allowspectators__);
}

//------------------------------------------------------------------------------
// Address: 0x10404D70
// Name: _dynamic_initializer_for__friendlyfire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__friendlyfire__()
{
  ConVar::ConVar(
    this: &friendlyfire,
    pName: "mp_friendlyfire",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "Allows team members to injure other members of their team");
  return atexit(func: dynamic_atexit_destructor_for__friendlyfire__);
}

//------------------------------------------------------------------------------
// Address: 0x10404DA0
// Name: _dynamic_initializer_for__mp_fadetoblack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_fadetoblack__()
{
  ConVar::ConVar(
    this: &mp_fadetoblack,
    pName: "mp_fadetoblack",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "fade a player's screen to black when he dies");
  return atexit(func: dynamic_atexit_destructor_for__mp_fadetoblack__);
}

//------------------------------------------------------------------------------
// Address: 0x10404DD0
// Name: _dynamic_initializer_for__g_Managers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Managers__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Managers__);
}

//------------------------------------------------------------------------------
// Address: 0x104085B0
// Name: _dynamic_initializer_for__g_PointCameraList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PointCameraList__()
{
  CBaseEntityClassList::CBaseEntityClassList(this: &g_PointCameraList);
  g_PointCameraList.__vftable = (CEntityClassList<CPointCamera>_vtbl *)&CEntityClassList<CPointCamera>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_PointCameraList__);
}

//------------------------------------------------------------------------------
// Address: 0x10408680
// Name: _dynamic_initializer_for__DevShotSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__DevShotSystem__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &DevShotSystem, name: "CDevShotSystem");
  DevShotSystem.__vftable = (CDevShotSystem_vtbl *)&CDevShotSystem::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__DevShotSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10408800
// Name: _dynamic_initializer_for__g_PointTemplatePrecacher__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PointTemplatePrecacher__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_PointTemplatePrecacher, name: "CPointTemplatePrecacher");
  g_PointTemplatePrecacher.__vftable = (CPointTemplatePrecacher_vtbl *)&CPointTemplatePrecacher::`vftable';
  g_PointTemplatePrecacher.m_Ents.m_Memory.m_pMemory = nullptr;
  g_PointTemplatePrecacher.m_Ents.m_Memory.m_nAllocationCount = 0;
  g_PointTemplatePrecacher.m_Ents.m_Memory.m_nGrowSize = 0;
  g_PointTemplatePrecacher.m_Ents.m_Size = 0;
  g_PointTemplatePrecacher.m_Ents.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_PointTemplatePrecacher__);
}
