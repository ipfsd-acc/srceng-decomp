// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/commentarysystem.cpp
// Functions: 97
// ============================================================

#include "game\server\commentarysystem.h"

//------------------------------------------------------------------------------
// Address: 0x100DF5E0
// Name: public: virtual int CSprite::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSprite::ObjectCaps(CBeam *this)
{
  unsigned int v1; // esi

  v1 = 0;
  if ( (this->m_spawnflags.m_Value & 0x8000) != 0 )
    v1 = 0x80000000;
  return v1 | CBaseEntity::ObjectCaps(this) & 0xFFFFFF7F;
}

//------------------------------------------------------------------------------
// Address: 0x100F5290
// Name: bool IsInCommentaryMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsInCommentaryMode()
{
  return g_bInCommentaryMode;
}

//------------------------------------------------------------------------------
// Address: 0x100F52A0
// Name: public: virtual void PrecachePointCommentaryNodePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecachePointCommentaryNodePrecache::CResourcePrecacher::Cache(
        PrecachePointCommentaryNodePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "models/extras/info_speech.mdl",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100F52D0
// Name: public: bool CPointCommentaryNode::CannotBeStopped(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPointCommentaryNode::CannotBeStopped(CPointCommentaryNode *this)
{
  return this->m_bUnstoppable || this->m_bPreventChangesWhileMoving;
}

//------------------------------------------------------------------------------
// Address: 0x100F52F0
// Name: public: virtual struct datamap_t __near * CPointCommentaryNode::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointCommentaryNode::GetDataDescMap(CPointCommentaryNode *this)
{
  return &CPointCommentaryNode::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F5300
// Name: public: virtual class ServerClass __near * CPointCommentaryNode::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPointCommentaryNode::GetServerClass(CPointCommentaryNode *this)
{
  return &g_CPointCommentaryNode_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100F5310
// Name: public: void CCommentarySystem::ParseEntKVBlock(class CBaseEntity __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::ParseEntKVBlock(CCommentarySystem *this, CBaseEntity *pNode, KeyValues *pkvNode)
{
  KeyValues *i; // ebx
  const char *Name; // eax
  const char *String; // esi
  int v6; // eax
  int j; // ecx
  CBaseEntity_vtbl *v8; // esi
  const char *v9; // eax
  CBaseEntity_vtbl *v10; // edi
  const char *v11; // eax
  char szTmp[1024]; // [esp+4h] [ebp-404h] BYREF
  CCommentarySystem *v13; // [esp+404h] [ebp-4h]

  v13 = this;
  for ( i = KeyValues::GetFirstSubKey(this: pkvNode); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( _V_strcmp(s1: Name, s2: "connections") != 0 )
    {
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
      if ( V_strnchr(pStr: String, c: 94, n: 1024) != nullptr )
      {
        V_strncpy(pDest: szTmp, pSrc: String, maxLen: 1024);
        v6 = _V_strlen(str: szTmp);
        for ( j = 0; j < v6; ++j )
        {
          if ( szTmp[j] == 94 )
            szTmp[j] = 34;
        }
        v8 = pNode->__vftable;
        v9 = KeyValues::GetName(this: i);
        v8->KeyValue_4(this: pNode, a2: v9, a3: szTmp);
      }
      else
      {
        v10 = pNode->__vftable;
        v11 = KeyValues::GetName(this: i);
        v10->KeyValue_4(this: pNode, a2: v11, a3: String);
      }
    }
    else
    {
      CCommentarySystem::ParseEntKVBlock(this: v13, pNode, pkvNode: i);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5420
// Name: public: void CCommentarySystem::ApplyCommentaryModifications(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::ApplyCommentaryModifications(CCommentarySystem *this)
{
  KeyValues *m_pkvSavedModifications; // ecx
  KeyValues *FirstSubKey; // esi
  KeyValues *Key; // eax
  KeyValues *v4; // edi
  const char *String; // eax
  CBaseEntity *EntityByModel; // ebx
  KeyValues *NextKey; // esi
  CBaseEntity_vtbl *v8; // edi
  const char *Name; // eax
  const char *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  const char *v13; // eax
  CBaseEntity *EntityByTarget; // ebx
  KeyValues *v15; // esi
  CBaseEntity_vtbl *v16; // edi
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // [esp-10h] [ebp-1Ch]
  const char *v20; // [esp-10h] [ebp-1Ch]
  KeyValues *pFindByModelname; // [esp+0h] [ebp-Ch]
  KeyValues *pFindByModelnamea; // [esp+0h] [ebp-Ch]
  KeyValues *pModifyBlock; // [esp+4h] [ebp-8h]
  KeyValues *pkvNode; // [esp+8h] [ebp-4h]

  m_pkvSavedModifications = this->m_pkvSavedModifications;
  if ( m_pkvSavedModifications != nullptr )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: m_pkvSavedModifications);
    pkvNode = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        pModifyBlock = KeyValues::FindKey(this: FirstSubKey, keyName: "modify", bCreate: false);
        if ( pModifyBlock != nullptr )
        {
          Key = KeyValues::FindKey(this: FirstSubKey, keyName: "find_by_modelname", bCreate: false);
          v4 = Key;
          pFindByModelname = Key;
          if ( Key != nullptr )
          {
            String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: locale);
            EntityByModel = CGlobalEntityList::FindEntityByModel(
                              this: &gEntList,
                              pStartEntity: nullptr,
                              szModelName: String);
            if ( EntityByModel != nullptr )
            {
              do
              {
                NextKey = KeyValues::GetFirstSubKey(this: pModifyBlock);
                if ( NextKey != nullptr )
                {
                  do
                  {
                    v8 = EntityByModel->__vftable;
                    v19 = KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: locale);
                    Name = KeyValues::GetName(this: NextKey);
                    v8->KeyValue_4(this: EntityByModel, a2: Name, a3: v19);
                    NextKey = KeyValues::GetNextKey(this: NextKey);
                  }
                  while ( NextKey != nullptr );
                  v4 = pFindByModelname;
                }
                v10 = KeyValues::GetString(this: v4, keyName: nullptr, defaultValue: locale);
                EntityByModel = CGlobalEntityList::FindEntityByModel(
                                  this: &gEntList,
                                  pStartEntity: EntityByModel,
                                  szModelName: v10);
              }
              while ( EntityByModel != nullptr );
              FirstSubKey = pkvNode;
            }
          }
          v11 = KeyValues::FindKey(this: FirstSubKey, keyName: "find_by_targetname", bCreate: false);
          v12 = v11;
          pFindByModelnamea = v11;
          if ( v11 != nullptr )
          {
            v13 = KeyValues::GetString(this: v11, keyName: nullptr, defaultValue: locale);
            EntityByTarget = CGlobalEntityList::FindEntityByTarget(this: &gEntList, pStartEntity: nullptr, szName: v13);
            if ( EntityByTarget != nullptr )
            {
              do
              {
                v15 = KeyValues::GetFirstSubKey(this: pModifyBlock);
                if ( v15 != nullptr )
                {
                  do
                  {
                    v16 = EntityByTarget->__vftable;
                    v20 = KeyValues::GetString(this: v15, keyName: nullptr, defaultValue: locale);
                    v17 = KeyValues::GetName(this: v15);
                    v16->KeyValue_4(this: EntityByTarget, a2: v17, a3: v20);
                    v15 = KeyValues::GetNextKey(this: v15);
                  }
                  while ( v15 != nullptr );
                  v12 = pFindByModelnamea;
                }
                v18 = KeyValues::GetString(this: v12, keyName: nullptr, defaultValue: locale);
                EntityByTarget = CGlobalEntityList::FindEntityByTarget(
                                   this: &gEntList,
                                   pStartEntity: EntityByTarget,
                                   szName: v18);
              }
              while ( EntityByTarget != nullptr );
              FirstSubKey = pkvNode;
            }
          }
        }
        pkvNode = KeyValues::GetNextKey(this: FirstSubKey);
        if ( pkvNode == nullptr )
          break;
        FirstSubKey = pkvNode;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F55D0
// Name: public: virtual struct datamap_t __near * CCommentarySystem::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCommentarySystem::GetDataDescMap(CCommentarySystem *this)
{
  return &CCommentarySystem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F55E0
// Name: void CC_CommentaryNotChanging(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CommentaryNotChanging()
{
  g_CommentarySystem.m_bCommentaryConvarsChanging = false;
}

//------------------------------------------------------------------------------
// Address: 0x100F55F0
// Name: public: virtual bool CPointCommentaryNode::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPointCommentaryNode::TestCollision(
        CPointCommentaryNode *this,
        const Ray_t *ray,
        unsigned int mask,
        CGameTrace *trace)
{
  return g_bTracingVsCommentaryNodes
      && !this->m_bDisabled
      && CBaseAnimating::TestCollision(this, ray, fContentsMask: mask, tr: trace);
}

//------------------------------------------------------------------------------
// Address: 0x100F5620
// Name: class ISaveRestoreBlockHandler __near * GetCommentarySaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CCommentary_SaveRestoreBlockHandler *__cdecl GetCommentarySaveRestoreBlockHandler()
{
  return &g_Commentary_SaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x100F5630
// Name: public: virtual struct datamap_t __near * CCommentaryAuto::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCommentaryAuto::GetDataDescMap(CCommentaryAuto *this)
{
  return &CCommentaryAuto::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F5640
// Name: public: virtual void CCommentaryAuto::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryAuto::Spawn(CCommentaryAuto *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100F5680
// Name: public: virtual void CCommentaryAuto::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryAuto::Think(CCommentaryAuto *this)
{
  if ( g_CommentarySystem.m_bCommentaryEnabledMidGame )
    COutputEvent::FireOutput(this: &this->m_OnCommentaryMidGame, pActivator: nullptr, pCaller: this, fDelay: 0.0);
  else
    COutputEvent::FireOutput(this: &this->m_OnCommentaryNewGame, pActivator: nullptr, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100F56B0
// Name: public: void CCommentaryAuto::InputMultiplayerSpawned(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryAuto::InputMultiplayerSpawned(CCommentaryAuto *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnCommentaryMultiplayerSpawn, pActivator: nullptr, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100F5770
// Name: public: virtual void CPointCommentaryNode::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPointCommentaryNode::Precache(
        CPointCommentaryNode *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  const char *pszValue; // edi
  const char *DebugName; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  v3 = *(const char **)((int (__thiscall *)(CPointCommentaryNode *, _BYTE *))this->GetModelName)(a1: this, a2: v6);
  if ( v3 == nullptr )
    v3 = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
  if ( this->m_iszCommentaryFile.m_Value.pszValue != nullptr )
  {
    CBaseEntity::PrecacheScriptSound(soundname: this->m_iszCommentaryFile.m_Value.pszValue);
  }
  else
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "%s: %s has no commentary file.\n", pszValue, DebugName);
  }
  if ( this->m_iszCommentaryFileNoHDR.m_Value.pszValue != nullptr )
    CBaseEntity::PrecacheScriptSound(soundname: this->m_iszCommentaryFileNoHDR.m_Value.pszValue);
  CBaseAnimating::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F5800
// Name: public: bool CPointCommentaryNode::PreventsMovement(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPointCommentaryNode::PreventsMovement(CPointCommentaryNode *this)
{
  unsigned int m_Index; // edx
  bool result; // al

  m_Index = this->m_hViewPosition.m_Value.m_Index;
  if ( m_Index == -1 )
    return this->m_bPreventMovement;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return this->m_bPreventMovement;
  result = true;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    return this->m_bPreventMovement;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F5850
// Name: public: virtual void CCommentaryViewPosition::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCommentaryViewPosition::Precache(
        CCommentaryViewPosition *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/redglow1.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F5890
// Name: public: bool CPointCommentaryNode::HasViewTarget(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPointCommentaryNode::HasViewTarget(CPointCommentaryNode *this)
{
  unsigned int m_Index; // eax
  unsigned int v2; // eax
  BOOL result; // eax

  m_Index = this->m_hViewTarget.m_Index;
  result = true;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    v2 = this->m_hViewPosition.m_Value.m_Index;
    if ( v2 == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_SerialNumber != HIWORD(v2)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_pEntity == nullptr )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F5A50
// Name: public: virtual void CCommentaryViewPosition::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryViewPosition::Spawn(CCommentaryViewPosition *this)
{
  this->Precache(this);
  this->m_ModelName.pszValue = "sprites/redglow1.vmt";
  CBaseEntity::DispatchUpdateTransmitState(this);
  CSprite::Spawn(this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::AddEffects(this, nEffects: 16);
  UTIL_SetSize(pEnt: this, vecMin: &vec3_origin, vecMax: &vec3_origin);
}

//------------------------------------------------------------------------------
// Address: 0x100F5AC0
// Name: public: void CCommentarySystem::CalculateCommentaryState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::CalculateCommentaryState(CCommentarySystem *this)
{
  const char *pszValue; // eax
  char szFullName[512]; // [esp+0h] [ebp-200h] BYREF

  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  V_snprintf(pDest: szFullName, maxLen: 512, pFormat: "maps/%s_commentary.txt", pszValue);
  if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: szFullName, a3: nullptr) )
  {
    CCollisionProperty::TestCollision(this: (ConVar *)&commentary_available.IConVar, value: 1);
    if ( commentary.m_pParent != nullptr && commentary.m_pParent->m_Value.m_nValue != 0 )
      g_bInCommentaryMode = true;
  }
  else
  {
    g_bInCommentaryMode = false;
    CCollisionProperty::TestCollision(this: (ConVar *)&commentary_available.IConVar, value: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5B50
// Name: public: class CPointCommentaryNode __near * CCommentarySystem::GetNodeUnderCrosshair(void)
// Source: json
//------------------------------------------------------------------------------
CPointCommentaryNode *__thiscall CCommentarySystem::GetNodeUnderCrosshair(CCommentarySystem *this)
{
  CBasePlayer *LocalPlayer; // eax
  const IHandleEntity *v2; // esi
  CGameTrace tr; // [esp+Ch] [ebp-78h] BYREF
  Vector vecAbsEnd; // [esp+60h] [ebp-24h] BYREF
  Vector vecForward; // [esp+6Ch] [ebp-18h] BYREF
  Vector vecSrc; // [esp+78h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+84h] [ebp+0h] BYREF

  if ( gpGlobals->maxClients > 1 )
    LocalPlayer = UTIL_PlayerByIndex(playerIndex: 1);
  else
    LocalPlayer = UTIL_GetLocalPlayer();
  v2 = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return nullptr;
  LocalPlayer->EyePosition(this: LocalPlayer, result: &vecSrc);
  ((void (__thiscall *)(const IHandleEntity *, Vector *, _DWORD))v2->__vftable[148].GetRefEHandle)(
    a1: v2,
    a2: &vecForward,
    a3: 0);
  vecAbsEnd.y = vecSrc.y + (float)(vecForward.y * 56755.84);
  g_bTracingVsCommentaryNodes = true;
  vecAbsEnd.x = vecSrc.x + (float)(vecForward.x * 56755.84);
  vecAbsEnd.z = vecSrc.z + (float)(vecForward.z * 56755.84);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)v2,
    vecAbsStart: &vecSrc,
    &vecAbsEnd,
    mask: 0x200400Bu,
    ignore: v2,
    collisionGroup: 0,
    ptr: &tr);
  g_bTracingVsCommentaryNodes = false;
  if ( tr.m_pEnt != nullptr )
    return (CPointCommentaryNode *)__RTDynamicCast(
                                     inptr: tr.m_pEnt,
                                     VfDelta: 0,
                                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                                     TargetType: &CPointCommentaryNode `RTTI Type Descriptor',
                                     isReference: 0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F5C50
// Name: public: class CPointCommentaryNode __near * CCommentarySystem::GetActiveNode(void)
// Source: json
//------------------------------------------------------------------------------
CPointCommentaryNode *__thiscall CCommentarySystem::GetActiveNode(CCommentarySystem *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hActiveCommentaryNode.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CPointCommentaryNode *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100F5C80
// Name: bool Commentary_IsCommentaryEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Commentary_IsCommentaryEntity(CBaseEntity *pEntity)
{
  int v1; // edx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  v1 = 0;
  if ( g_CommentarySystem.m_hSpawnedEntities.m_Size == 0 )
    return pEntity->m_iName.m_Value.pszValue == "commentary_semaphore";
  while ( 1 )
  {
    m_Index = g_CommentarySystem.m_hSpawnedEntities.m_Memory.m_pMemory[v1].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( pEntity == m_pEntity )
      break;
    if ( ++v1 == g_CommentarySystem.m_hSpawnedEntities.m_Size )
      return pEntity->m_iName.m_Value.pszValue == "commentary_semaphore";
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F5CF0
// Name: bool IsListeningToCommentary(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsListeningToCommentary()
{
  return g_CommentarySystem.m_hActiveCommentaryNode.m_Index != -1
      && g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_SerialNumber == HIWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)
      && g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F5D30
// Name: public: void CPointCommentaryNode::TeleportTo(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPointCommentaryNode::TeleportTo(CPointCommentaryNode *this@<ecx>, int a2@<ebx>, CBasePlayer *pPlayer)
{
  float z; // eax
  bool v5; // zf
  const Vector *v7; // eax
  Vector *v8; // eax
  CGameTrace trace; // [esp+4h] [ebp-84h] BYREF
  QAngle vecAngle; // [esp+58h] [ebp-30h] BYREF
  Vector vecToNode; // [esp+64h] [ebp-24h] BYREF
  Vector vecTarget; // [esp+70h] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+7Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+88h] [ebp+0h] BYREF
  CBasePlayer *pPlayera; // [esp+90h] [ebp+8h]

  z = this->m_vecTeleportOrigin.z;
  *(_QWORD *)&vecTarget.x = *(_QWORD *)&this->m_vecTeleportOrigin.x;
  v5 = vec3_origin.x == this->m_vecTeleportOrigin.x;
  vecTarget.z = z;
  if ( v5 && vec3_origin.y == this->m_vecTeleportOrigin.y && vec3_origin.z == this->m_vecTeleportOrigin.z )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    vecTarget = this->m_vecAbsOrigin;
  }
  pPlayera = (CBasePlayer *)((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int))pPlayer->m_Collision.OBBMaxs)(
                              a1: &pPlayer->m_Collision,
                              a2);
  v7 = pPlayer->m_Collision.OBBMins(this: &pPlayer->m_Collision);
  vecAbsEnd.x = vecTarget.x;
  vecAbsEnd.y = vecTarget.y;
  vecAbsEnd.z = vecTarget.z - 500.0;
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &vecTarget,
    &vecAbsEnd,
    hullMin: v7,
    hullMax: (const Vector *)pPlayera,
    mask: 0x200400Bu,
    ignore: pPlayer,
    collisionGroup: 0,
    ptr: &trace);
  pPlayer->Teleport(this: pPlayer, a2: &trace.endpos, a3: nullptr, a4: &vec3_origin, a5: true);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v8 = pPlayer->EyePosition(this: pPlayer, result: &vecAbsEnd);
  vecToNode.x = this->m_vecAbsOrigin.x - v8->x;
  vecToNode.y = this->m_vecAbsOrigin.y - v8->y;
  vecToNode.z = this->m_vecAbsOrigin.z - v8->z;
  VectorNormalize(vec: &vecToNode);
  vecAbsEnd.x = 0.0;
  vecAbsEnd.y = 0.0;
  vecAbsEnd.z = 1.0;
  VectorAngles(forward: &vecToNode, pseudoup: &vecAbsEnd, angles: &vecAngle);
  CBasePlayer::SnapEyeAngles(this: pPlayer, viewAngles: &vecAngle);
}

//------------------------------------------------------------------------------
// Address: 0x100F5F00
// Name: public: void CPointCommentaryNode::UpdateViewThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::UpdateViewThink(CPointCommentaryNode *this)
{
  CPointCommentaryNode *v1; // ebx
  bool v2; // zf
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  unsigned int m_Index; // eax
  CHandle<CBaseEntity> *p_m_hViewTarget; // edi
  CHandle<CBaseEntity> *p_m_hViewTargetAngles; // ebx
  const CBaseEntity *EntityByName; // eax
  CBaseEntity *v9; // eax
  CBaseEntity *v10; // eax
  CBaseEntity *v11; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  float m_flGroundChangeTime; // eax
  CBaseEntity *v14; // eax
  CBaseEntity *v15; // edi
  float z; // xmm0_4
  CBaseEntity *v17; // edi
  CBaseEntity *v18; // edi
  float *v19; // eax
  float v20; // xmm0_4
  CBaseEntity *v21; // eax
  const QAngle *AbsAngles; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  CBaseEntity *v24; // eax
  CBaseEntity *v25; // eax
  const Vector *AbsOrigin; // eax
  CBaseEntity *v27; // eax
  Vector *(__thiscall *v28)(CBaseEntity *, Vector *); // edx
  float *p_x; // edi
  float *v30; // eax
  double v31; // xmm0_8
  __m128d v32; // xmm0
  double v33; // xmm0_8
  float v34; // xmm1_4
  float v35; // eax
  CBaseEntity *v36; // eax
  CBaseEntity *v37; // eax
  unsigned int v38; // eax
  CBaseCombatWeapon *v39; // eax
  CHandle<CBaseEntity> *p_m_hViewPositionMover; // ebx
  const CBaseEntity *v41; // eax
  CBaseEntity *v42; // eax
  CBaseEntity *v43; // eax
  double v44; // xmm1_8
  double v45; // xmm0_8
  unsigned int v46; // eax
  CBaseEntity *m_pEntity; // edi
  float *v48; // eax
  float v49; // xmm2_4
  CHandle<CBaseEntity> v50; // eax
  CBaseEntity *v51; // ecx
  const Vector *srcAngle; // [esp+18h] [ebp-50h]
  const QAngle *srcAnglea; // [esp+18h] [ebp-50h]
  const Vector *srcAngleb; // [esp+18h] [ebp-50h]
  const QAngle *srcAnglec; // [esp+18h] [ebp-50h]
  Vector v56; // [esp+28h] [ebp-40h] BYREF
  Vector vecCurEye; // [esp+34h] [ebp-34h] BYREF
  QAngle angGoal; // [esp+40h] [ebp-28h] BYREF
  QAngle angCurrent; // [esp+4Ch] [ebp-1Ch] BYREF
  float flBlendPerc; // [esp+58h] [ebp-10h]
  float mod; // [esp+5Ch] [ebp-Ch]
  float v62; // [esp+60h] [ebp-8h]
  CBaseEntity *v63; // [esp+64h] [ebp-4h]
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  v1 = this;
  v2 = !this->m_bActive.m_Value;
  v63 = this;
  if ( v2 )
    return;
  v3 = gpGlobals->maxClients > 1 ? UTIL_PlayerByIndex(playerIndex: 1) : UTIL_GetLocalPlayer();
  v4 = v3;
  if ( v3 == nullptr )
    return;
  m_Index = v1->m_hViewTarget.m_Index;
  p_m_hViewTarget = &v1->m_hViewTarget;
  LODWORD(v62) = &v1->m_hViewTarget;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    p_m_hViewTargetAngles = &v1->m_hViewTargetAngles;
    if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)p_m_hViewTargetAngles)
      && CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&v63[1].m_flGroundChangeTime) )
    {
      EntityByName = CreateEntityByName(className: "point_commentary_viewpoint", iForceEdictIndex: -1, bNotify: true);
      CHandle<CBaseEntity>::operator=(this: p_m_hViewTargetAngles, val: EntityByName);
      srcAngle = v4->EyePosition(this: v4, result: &vecCurEye);
      v9 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles);
      CBaseEntity::SetAbsOrigin(this: v9, absOrigin: srcAngle);
      srcAnglea = v4->EyeAngles(this: v4);
      v10 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles);
      CBaseEntity::SetAbsAngles(this: v10, absAngles: srcAnglea);
      v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles);
      CBasePlayer::SetViewEntity(this: v4, pEntity: v11, bShouldDrawPlayer: true);
      if ( CBaseCombatCharacter::GetActiveWeapon(this: v4) != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v4);
        ActiveWeapon->Holster(this: ActiveWeapon, a2: nullptr);
      }
    }
    m_flGroundChangeTime = v63[1].m_flGroundChangeTime;
    if ( m_flGroundChangeTime != NAN )
    {
      if ( g_pEntityList->m_EntPtrArray[LOWORD(m_flGroundChangeTime)].m_SerialNumber == HIWORD(LODWORD(m_flGroundChangeTime))
        && g_pEntityList->m_EntPtrArray[LOWORD(m_flGroundChangeTime)].m_pEntity != nullptr )
      {
        v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v63[1].m_flGroundChangeTime);
        v15 = v14;
        if ( (v14->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v14, a2: (int)&savedregs);
        angCurrent.x = v15->m_angAbsRotation.x;
        angCurrent.y = v15->m_angAbsRotation.y;
        z = v15->m_angAbsRotation.z;
        v17 = v63;
        angCurrent.z = z;
        v62 = COERCE_FLOAT(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v63[1].m_flNonShadowMass));
        v18 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v17[1].m_flGroundChangeTime);
        if ( (v18->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v18, a2: (int)&savedregs);
        v19 = (float *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v62) + 588))(a1: COERCE_FLOAT(LODWORD(v62)));
        vecCurEye.x = *v19 - v18->m_vecAbsOrigin.x;
        vecCurEye.y = v19[1] - v18->m_vecAbsOrigin.y;
        v20 = v19[2] - v18->m_vecAbsOrigin.z;
        goto LABEL_26;
      }
      p_m_hViewTarget = (CHandle<CBaseEntity> *)LODWORD(v62);
    }
    if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles) != nullptr )
    {
      v21 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles);
      AbsAngles = CBaseEntity::GetAbsAngles(this: v21);
      angCurrent.x = AbsAngles->x;
      angCurrent.y = AbsAngles->y;
      EyePosition = v4->EyePosition;
      angCurrent.z = AbsAngles->z;
      srcAngleb = EyePosition(this: v4, result: &v56);
      v24 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles);
      CBaseEntity::SetAbsOrigin(this: v24, absOrigin: srcAngleb);
      v62 = COERCE_FLOAT(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTarget));
      v25 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles);
      AbsOrigin = CBaseEntity::GetAbsOrigin(this: v25);
    }
    else
    {
      angCurrent = *v4->EyeAngles(this: v4);
      *(float *)&v27 = COERCE_FLOAT(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTarget));
      v28 = v4->EyePosition;
      v62 = *(float *)&v27;
      AbsOrigin = v28(this: v4, result: &v56);
    }
    p_x = &AbsOrigin->x;
    v30 = (float *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v62) + 588))(a1: COERCE_FLOAT(LODWORD(v62)));
    vecCurEye.x = *v30 - *p_x;
    vecCurEye.y = v30[1] - p_x[1];
    v20 = v30[2] - p_x[2];
LABEL_26:
    vecCurEye.z = v20;
    VectorAngles(forward: &vecCurEye, angles: &angGoal);
    v62 = AngleDiff(destAngle: angGoal.x, srcAngle: angCurrent.x);
    flBlendPerc = AngleDiff(destAngle: angGoal.y, srcAngle: angCurrent.y);
    __libm_sse2_log(a1: (__m128d)0x3FE0000000000000uLL);
    *(float *)&v31 = v31;
    v32.m128d_f64[0] = (float)((float)(*(float *)&v31 * 3.3333333) * gpGlobals->frametime);
    __libm_sse2_exp(a1: v32);
    v34 = v33;
    mod = 1.0 - v34;
    angCurrent.x = AngleNormalize(angle: (float)((float)(1.0 - v34) * v62) + angCurrent.x);
    angCurrent.y = AngleNormalize(angle: (float)(mod * flBlendPerc) + angCurrent.y);
    v35 = v63[1].m_flGroundChangeTime;
    if ( v35 != NAN
      && g_pEntityList->m_EntPtrArray[LOWORD(v35)].m_SerialNumber == HIWORD(LODWORD(v35))
      && g_pEntityList->m_EntPtrArray[LOWORD(v35)].m_pEntity != nullptr )
    {
      v36 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&v63[1].m_flGroundChangeTime);
      CBaseEntity::SetAbsAngles(this: v36, absAngles: &angCurrent);
    }
    else
    {
      if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles) != nullptr )
      {
        v37 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewTargetAngles);
        CBaseEntity::SetAbsAngles(this: v37, absAngles: &angCurrent);
      }
      CBasePlayer::SnapEyeAngles(this: v4, viewAngles: &angCurrent);
    }
    CBaseEntity::SetNextThink(this: v63, thinkTime: gpGlobals->curtime, szContext: s_pCommentaryUpdateViewThink);
    v1 = (CPointCommentaryNode *)v63;
  }
  v38 = v1->m_hViewPosition.m_Value.m_Index;
  if ( v38 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v38].m_SerialNumber == HIWORD(v38)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v38].m_pEntity != nullptr )
  {
    if ( CBaseCombatCharacter::GetActiveWeapon(this: v4) != nullptr )
    {
      v39 = CBaseCombatCharacter::GetActiveWeapon(this: v4);
      v39->Holster(this: v39, a2: nullptr);
    }
    p_m_hViewPositionMover = &v1->m_hViewPositionMover;
    if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)p_m_hViewPositionMover) )
    {
      v41 = CreateEntityByName(className: "point_commentary_viewpoint", iForceEdictIndex: -1, bNotify: true);
      CHandle<CBaseEntity>::operator=(this: p_m_hViewPositionMover, val: v41);
      srcAnglec = v4->EyeAngles(this: v4);
      v42 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewPositionMover);
      CBaseEntity::SetAbsAngles(this: v42, absAngles: srcAnglec);
      v43 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hViewPositionMover);
      CBasePlayer::SetViewEntity(this: v4, pEntity: v43, bShouldDrawPlayer: true);
    }
    v44 = (float)((float)(gpGlobals->curtime - v63[1].m_vecAbsOrigin.y) * 0.5);
    v45 = 0.0;
    if ( v44 >= 0.0 )
    {
      v45 = 1.0;
      if ( v44 <= 1.0 )
        v45 = (float)((float)(gpGlobals->curtime - v63[1].m_vecAbsOrigin.y) * 0.5);
    }
    v46 = v63[1].m_hGroundEntity.m_Value.m_Index;
    flBlendPerc = v45;
    if ( v46 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_SerialNumber != HIWORD(v46) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_pEntity;
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    v48 = (float *)v4->EyePosition(this: v4, result: &v56);
    vecCurEye.x = (float)((float)(m_pEntity->m_vecAbsOrigin.x - *v48) * flBlendPerc) + *v48;
    vecCurEye.y = (float)((float)(m_pEntity->m_vecAbsOrigin.y - v48[1]) * flBlendPerc) + v48[1];
    v49 = (float)((float)(m_pEntity->m_vecAbsOrigin.z - v48[2]) * flBlendPerc) + v48[2];
    v50.m_Index = p_m_hViewPositionMover->m_Index;
    vecCurEye.z = v49;
    if ( v50.m_Index == -1 || g_pEntityList->m_EntPtrArray[LOWORD(v50.m_Index)].m_SerialNumber != HIWORD(v50.m_Index) )
      v51 = nullptr;
    else
      v51 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(v50.m_Index)].m_pEntity;
    CBaseEntity::SetAbsOrigin(this: v51, absOrigin: &vecCurEye);
    CBaseEntity::SetNextThink(this: v63, thinkTime: gpGlobals->curtime, szContext: s_pCommentaryUpdateViewThink);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6590
// Name: public: virtual void CPointCommentaryNode::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::SetTransmit(CPointCommentaryNode *this, CCheckTransmitInfo *pInfo, BOOL bAlways)
{
  edict_t *m_pPev; // eax
  unsigned int m_Index; // edx
  CBaseEntityList *v6; // ecx
  int v7; // eax
  CEntInfo *v8; // esi
  unsigned int v9; // edx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v14; // edx
  int v15; // eax
  CEntInfo *v16; // esi
  unsigned int v17; // edx
  int v18; // eax
  CEntInfo *v19; // eax
  IHandleEntity *v20; // ecx
  unsigned int v21; // edx
  int v22; // eax
  CEntInfo *v23; // esi
  unsigned int v24; // edx
  int v25; // eax
  CEntInfo *v26; // eax
  IHandleEntity *v27; // ecx
  unsigned int v28; // edx
  int v29; // eax
  CEntInfo *v30; // esi
  unsigned int v31; // edx
  int v32; // eax
  CEntInfo *v33; // eax

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseAnimating::SetTransmit(this, pInfo, bAlways);
    m_Index = this->m_hViewTarget.m_Index;
    v6 = g_pEntityList;
    if ( m_Index != -1 )
    {
      v7 = (unsigned __int16)m_Index;
      v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v9 = HIWORD(m_Index);
      if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
      {
        v10 = v7;
        v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
        v12 = &g_pEntityList->m_EntPtrArray[v10];
        if ( v11 )
          m_pEntity = v12->m_pEntity;
        else
          m_pEntity = nullptr;
        ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))m_pEntity->__vftable[7].SetRefEHandle)(
          a1: m_pEntity,
          a2: pInfo,
          a3: bAlways);
        v6 = g_pEntityList;
      }
    }
    v14 = this->m_hViewTargetAngles.m_Index;
    if ( v14 != -1 )
    {
      v15 = (unsigned __int16)v14;
      v16 = &v6->m_EntPtrArray[(unsigned __int16)v14];
      v17 = HIWORD(v14);
      if ( v16->m_SerialNumber == v17 && v16->m_pEntity != nullptr )
      {
        v18 = v15;
        v11 = v6->m_EntPtrArray[v18].m_SerialNumber == v17;
        v19 = &v6->m_EntPtrArray[v18];
        if ( v11 )
          v20 = v19->m_pEntity;
        else
          v20 = nullptr;
        ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))v20->__vftable[7].SetRefEHandle)(
          a1: v20,
          a2: pInfo,
          a3: bAlways);
        v6 = g_pEntityList;
      }
    }
    v21 = this->m_hViewPosition.m_Value.m_Index;
    if ( v21 != -1 )
    {
      v22 = (unsigned __int16)v21;
      v23 = &v6->m_EntPtrArray[(unsigned __int16)v21];
      v24 = HIWORD(v21);
      if ( v23->m_SerialNumber == v24 && v23->m_pEntity != nullptr )
      {
        v25 = v22;
        v11 = v6->m_EntPtrArray[v25].m_SerialNumber == v24;
        v26 = &v6->m_EntPtrArray[v25];
        if ( v11 )
          v27 = v26->m_pEntity;
        else
          v27 = nullptr;
        ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))v27->__vftable[7].SetRefEHandle)(
          a1: v27,
          a2: pInfo,
          a3: bAlways);
        v6 = g_pEntityList;
      }
    }
    v28 = this->m_hViewPositionMover.m_Index;
    if ( v28 != -1 )
    {
      v29 = (unsigned __int16)v28;
      v30 = &v6->m_EntPtrArray[(unsigned __int16)v28];
      v31 = HIWORD(v28);
      if ( v30->m_SerialNumber == v31 && v30->m_pEntity != nullptr )
      {
        v32 = v29;
        v11 = v6->m_EntPtrArray[v32].m_SerialNumber == v31;
        v33 = &v6->m_EntPtrArray[v32];
        if ( v11 )
          ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, BOOL))v33->m_pEntity->__vftable[7].SetRefEHandle)(
            a1: v33->m_pEntity,
            a2: pInfo,
            a3: bAlways);
        else
          (*(void (__stdcall **)(CCheckTransmitInfo *, BOOL))(MEMORY[0] + 88))(a1: pInfo, a2: bAlways);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6720
// Name: public: virtual char const __near * CCommentary_SaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCommentary_SaveRestoreBlockHandler::GetBlockName(CCommentary_SaveRestoreBlockHandler *this)
{
  return "Commentary";
}

//------------------------------------------------------------------------------
// Address: 0x100F6730
// Name: public: virtual void CCommentary_SaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentary_SaveRestoreBlockHandler::Save(CCommentary_SaveRestoreBlockHandler *this, ISave *pSave)
{
  pSave->WriteBool_2(this: pSave, a2: &g_bInCommentaryMode, a3: 1);
  if ( g_bInCommentaryMode )
  {
    pSave->WriteAll(this: pSave, a2: &g_CommentarySystem, a3: &CCommentarySystem::m_DataMap);
    pSave->WriteInt_2(this: pSave, a2: &CAI_BaseNPC::m_nDebugBits, a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6780
// Name: public: virtual void CCommentary_SaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentary_SaveRestoreBlockHandler::WriteSaveHeaders(
        CCommentary_SaveRestoreBlockHandler *this,
        ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &COMMENTARY_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100F67A0
// Name: public: virtual void CCommentary_SaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentary_SaveRestoreBlockHandler::ReadRestoreHeaders(
        CCommentary_SaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  pRestore->ReadShort(this: pRestore, a2: (__int16 *)&pRestore, a3: 1, a4: 0);
  this->m_fDoLoad = (_WORD)pRestore == (unsigned __int16)COMMENTARY_SAVE_RESTORE_VERSION;
}

//------------------------------------------------------------------------------
// Address: 0x100F67D0
// Name: public: virtual void CCommentary_SaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentary_SaveRestoreBlockHandler::Restore(
        CCommentary_SaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool createPlayers)
{
  if ( this->m_fDoLoad )
  {
    ((void (__thiscall *)(IRestore *, bool *))pRestore->ReadBool)(a1: pRestore, a2: &g_bInCommentaryMode);
    if ( g_bInCommentaryMode )
    {
      pRestore->ReadAll(this: pRestore, a2: &g_CommentarySystem, a3: &CCommentarySystem::m_DataMap);
      CAI_BaseNPC::m_nDebugBits = pRestore->ReadInt(this: pRestore);
    }
    CCollisionProperty::TestCollision(this: (ConVar *)&commentary.IConVar, value: g_bInCommentaryMode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6A00
// Name: public: void CPointCommentaryNode::SetNodeNumber(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::SetNodeNumber(CPointCommentaryNode *this, int iCount)
{
  CNetworkVarBase<int,CPointCommentaryNode::NetworkVar_m_iNodeNumber> *p_m_iNodeNumber; // esi
  edict_t *m_pPev; // ecx

  p_m_iNodeNumber = &this->m_iNodeNumber;
  if ( this->m_iNodeNumber.m_Value != iCount )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iNodeNumber->m_Value = iCount;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x52Cu);
      p_m_iNodeNumber->m_Value = iCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6A50
// Name: public: CPointCommentaryNode::CPointCommentaryNode(void)
// Source: json
//------------------------------------------------------------------------------
CPointCommentaryNode *__thiscall CPointCommentaryNode::CPointCommentaryNode(CPointCommentaryNode *this)
{
  edict_t *m_pPev; // ecx

  CBaseAnimating::CBaseAnimating(this);
  this->__vftable = (CPointCommentaryNode_vtbl *)&CPointCommentaryNode::`vftable';
  this->m_hViewTarget.m_Index = -1;
  this->m_hViewTargetAngles.m_Index = -1;
  this->m_hViewPosition.m_Value.m_Index = -1;
  this->m_hViewPositionMover.m_Index = -1;
  this->m_pOnCommentaryStarted.m_Value.iVal = 0;
  this->m_pOnCommentaryStarted.m_Value.eVal.m_Index = -1;
  this->m_pOnCommentaryStarted.m_Value.fieldType = FIELD_VOID;
  this->m_pOnCommentaryStopped.m_Value.iVal = 0;
  this->m_pOnCommentaryStopped.m_Value.eVal.m_Index = -1;
  this->m_pOnCommentaryStopped.m_Value.fieldType = FIELD_VOID;
  this->m_iNodeNumber.m_Value = 0;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    return this;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x52Cu);
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6B10
// Name: public: void CPointCommentaryNode::SpinThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::SpinThink(CPointCommentaryNode *this)
{
  bool m_Value; // al
  float v3; // xmm0_4
  float v4; // xmm0_4
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx

  m_Value = this->m_bActive.m_Value;
  if ( m_Value || this->m_bUnderCrosshair && this->m_nSkin.m_Value == 0 )
  {
    v3 = this->m_flPlaybackRate.m_Value;
    if ( m_Value )
    {
      if ( v3 != 3.0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          v4 = 3.0;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
          v4 = 3.0;
        }
LABEL_17:
        this->m_flPlaybackRate.m_Value = v4;
      }
    }
    else if ( v3 != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x37Cu);
      }
      v4 = 1.0;
      goto LABEL_17;
    }
    this->StudioFrameAdvance(this);
    this->DispatchAnimEvents(this, a2: this);
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100F6CA0
// Name: public: virtual void CPointCommentaryNode::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::Activate(CPointCommentaryNode *this)
{
  int m_iCommentaryNodeCount; // ebx
  edict_t *m_pPev; // ecx
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int m_Index; // eax
  const char *v7; // eax
  const char *v8; // esi
  const char *DebugName; // eax
  const char *v10; // eax
  CBaseEntity *v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // eax
  IHandleEntity *v14; // ecx
  edict_t *v15; // ecx
  unsigned int v16; // eax
  const char *v17; // eax
  const char *v18; // esi
  const char *v19; // eax
  const char *v20; // [esp-4h] [ebp-14h]
  const char *v21; // [esp-4h] [ebp-14h]
  IHandleEntity *m_pEntity; // [esp+Ch] [ebp-4h]

  m_iCommentaryNodeCount = g_CommentarySystem.m_iCommentaryNodeCount;
  if ( this->m_iNodeNumberMax.m_Value != g_CommentarySystem.m_iCommentaryNodeCount )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x530u);
    }
    this->m_iNodeNumberMax.m_Value = m_iCommentaryNodeCount;
  }
  pszValue = this->m_iszViewTarget.pszValue;
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
    this->m_hViewTarget.m_Index = EntityByName != nullptr
                                ? EntityByName->GetRefEHandle(this: EntityByName)->m_Index
                                : -1;
    m_Index = this->m_hViewTarget.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      v7 = this->m_iszViewTarget.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      v8 = this->m_iClassname.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      v20 = v7;
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(a1: "%s: %s could not find viewtarget %s.\n", v8, DebugName, v20);
    }
  }
  v10 = this->m_iszViewPosition.pszValue;
  if ( v10 != nullptr )
  {
    v11 = CGlobalEntityList::FindEntityByName(
            this: &gEntList,
            pStartEntity: nullptr,
            szName: v10,
            pSearchingEntity: nullptr,
            pActivator: nullptr,
            pCaller: nullptr,
            pFilter: nullptr);
    if ( v11 != nullptr )
    {
      v12 = v11->GetRefEHandle(this: v11)->m_Index;
      if ( v12 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        goto LABEL_26;
      }
    }
    else
    {
      v12 = -1;
    }
    m_pEntity = nullptr;
LABEL_26:
    v13 = this->m_hViewPosition.m_Value.m_Index;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v14 = nullptr;
    else
      v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    if ( v14 != m_pEntity )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v15 = this->m_Network.m_pPev;
        if ( v15 != nullptr )
          CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x4ACu);
      }
      this->m_hViewPosition.m_Value.m_Index = v12;
    }
    v16 = this->m_hViewPosition.m_Value.m_Index;
    if ( v16 == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity == nullptr )
    {
      v17 = this->m_iszViewPosition.pszValue;
      if ( v17 == nullptr )
        v17 = locale;
      v18 = this->m_iClassname.pszValue;
      if ( v18 == nullptr )
        v18 = locale;
      v21 = v17;
      v19 = CBaseEntity::GetDebugName(this);
      _Warning(a1: "%s: %s could not find viewposition %s.\n", v18, v19, v21);
    }
  }
  CBaseAnimating::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F6EC0
// Name: public: void CPointCommentaryNode::SetUnderCrosshair(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::SetUnderCrosshair(CPointCommentaryNode *this, bool bUnderCrosshair)
{
  bool v2; // zf
  CGlobalVars *v3; // edi
  CNetworkVarBase<float,CBaseEntity::NetworkVar_m_flAnimTime> *p_m_flAnimTime; // esi
  edict_t *m_pPev; // ecx

  if ( bUnderCrosshair )
  {
    v2 = !this->m_bActive.m_Value;
    this->m_bUnderCrosshair = true;
    if ( v2 )
    {
      v3 = gpGlobals;
      p_m_flAnimTime = &this->m_flAnimTime;
      if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          p_m_flAnimTime->m_Value = v3->curtime;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
          p_m_flAnimTime->m_Value = v3->curtime;
        }
      }
    }
  }
  else
  {
    this->m_bUnderCrosshair = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6F40
// Name: public: void CPointCommentaryNode::StartCommentary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::StartCommentary(CPointCommentaryNode *this)
{
  CBasePlayer *LocalPlayer; // eax
  edict_t *m_pPev; // ecx
  CGlobalVars *v4; // ebx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  const char *pszValue; // eax
  CGlobalVars *v8; // ebx
  edict_t *v9; // ecx
  unsigned int m_Index; // eax
  unsigned int v11; // eax
  float *v12; // eax
  const char *v13; // ecx
  edict_t **v14; // [esp+10h] [ebp-4h]

  if ( gpGlobals->maxClients > 1 )
    LocalPlayer = UTIL_PlayerByIndex(playerIndex: 1);
  else
    LocalPlayer = UTIL_GetLocalPlayer();
  v14 = (edict_t **)LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    if ( !this->m_bActive.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x520u);
      }
      this->m_bActive.m_Value = true;
    }
    v4 = gpGlobals;
    if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x64u);
      }
      this->m_flAnimTime.m_Value = v4->curtime;
    }
    this->m_flPrevAnimTime = gpGlobals->curtime;
    if ( this->m_nSkin.m_Value != 1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x36Cu);
      }
      this->m_nSkin.m_Value = 1;
    }
    COutputEvent::FireOutput(this: &this->m_pOnCommentaryStarted, pActivator: this, pCaller: this, fDelay: 0.0);
    if ( this->m_iszPreCommands.pszValue != nullptr )
    {
      g_CommentarySystem.m_bCommentaryConvarsChanging = true;
      pszValue = this->m_iszPreCommands.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      engine->ClientCommand(this: engine, a2: v14[6], a3: pszValue);
      engine->ClientCommand(this: engine, a2: v14[6], a3: "commentary_cvarsnotchanging\n");
    }
    v8 = gpGlobals;
    if ( this->m_flStartTime.m_Value != gpGlobals->curtime )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x524u);
      }
      this->m_flStartTime.m_Value = v8->curtime;
    }
    m_Index = this->m_hViewTarget.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      || (v11 = this->m_hViewPosition.m_Value.m_Index) != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber == HIWORD(v11)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity != nullptr )
    {
      v12 = (float *)((int (__thiscall *)(edict_t **))(*v14)[31].m_pUnk)(a1: v14);
      v13 = s_pCommentaryUpdateViewThink;
      this->m_vecOriginalAngles.x = *v12;
      this->m_vecOriginalAngles.y = v12[1];
      this->m_vecOriginalAngles.z = v12[2];
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CPointCommentaryNode::UpdateViewThink,
        thinkTime: gpGlobals->curtime,
        szContext: v13);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7180
// Name: public: void CPointCommentaryNode::CleanupPostCommentary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::CleanupPostCommentary(CPointCommentaryNode *this)
{
  CBasePlayer *LocalPlayer; // edi
  unsigned int m_Index; // eax
  CBaseEntityList *v4; // esi
  unsigned int v5; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  unsigned int v7; // eax
  int v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // eax
  IHandleEntity *m_pEntity; // ecx
  int v12; // edx
  IHandleEntity *v13; // eax
  unsigned int v14; // eax
  CBaseEntity *v15; // ecx
  unsigned int v16; // eax
  CBaseEntityList *v17; // edi
  int v18; // edx
  unsigned int v19; // esi
  unsigned int v20; // eax
  IHandleEntity *v21; // ecx
  int v22; // edx
  IHandleEntity *v23; // eax
  unsigned int v24; // eax
  CBaseEntity *v25; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v27; // ecx
  const char *fDelay; // [esp+4h] [ebp-14h]
  CBasePlayer *v29; // [esp+14h] [ebp-4h]

  if ( gpGlobals->maxClients > 1 )
  {
    v29 = UTIL_PlayerByIndex(playerIndex: 1);
    LocalPlayer = v29;
  }
  else
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    v29 = LocalPlayer;
  }
  if ( LocalPlayer != nullptr )
  {
    m_Index = this->m_hViewPositionMover.m_Index;
    v4 = g_pEntityList;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      || (v5 = this->m_hViewTargetAngles.m_Index) != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity != nullptr )
    {
      if ( CBaseCombatCharacter::GetActiveWeapon(this: LocalPlayer) != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: LocalPlayer);
        ActiveWeapon->Deploy(this: ActiveWeapon);
      }
      v4 = g_pEntityList;
    }
    v7 = this->m_hViewTargetAngles.m_Index;
    if ( v7 != -1 )
    {
      v8 = (unsigned __int16)v7;
      v9 = HIWORD(v7);
      if ( v4->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
        && v4->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
      {
        v10 = v29->m_hViewEntity.m_Value.m_Index;
        if ( v10 == -1 || v4->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          m_pEntity = nullptr;
        else
          m_pEntity = v4->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
        v12 = v8;
        v13 = v4->m_EntPtrArray[v12].m_SerialNumber == v9 ? v4->m_EntPtrArray[v12].m_pEntity : nullptr;
        if ( m_pEntity == v13 )
        {
          CBasePlayer::SetViewEntity(this: v29, pEntity: nullptr, bShouldDrawPlayer: true);
          v4 = g_pEntityList;
        }
      }
    }
    v14 = this->m_hViewTargetAngles.m_Index;
    if ( v14 == -1 || v4->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
      v15 = nullptr;
    else
      v15 = (CBaseEntity *)v4->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
    UTIL_Remove(oldObj: v15);
    v16 = this->m_hViewPositionMover.m_Index;
    v17 = g_pEntityList;
    if ( v16 != -1 )
    {
      v18 = (unsigned __int16)v16;
      v19 = HIWORD(v16);
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber == HIWORD(v16)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity != nullptr )
      {
        v20 = v29->m_hViewEntity.m_Value.m_Index;
        if ( v20 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
          v21 = nullptr;
        else
          v21 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
        v22 = v18;
        v23 = g_pEntityList->m_EntPtrArray[v22].m_SerialNumber == v19
            ? g_pEntityList->m_EntPtrArray[v22].m_pEntity
            : nullptr;
        if ( v21 == v23 )
        {
          CBasePlayer::SetViewEntity(this: v29, pEntity: nullptr, bShouldDrawPlayer: true);
          v17 = g_pEntityList;
        }
      }
    }
    v24 = this->m_hViewPositionMover.m_Index;
    if ( v24 == -1 || v17->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
      v25 = nullptr;
    else
      v25 = (CBaseEntity *)v17->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
    UTIL_Remove(oldObj: v25);
    if ( this->m_bActive.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x520u);
      }
      this->m_bActive.m_Value = false;
    }
    if ( this->m_flPlaybackRate.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v27 = this->m_Network.m_pPev;
        if ( v27 != nullptr )
          CBaseEdict::StateChanged(this: &v27->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flPlaybackRate.m_Value = 1.0;
    }
    fDelay = s_pCommentaryUpdateViewThink;
    this->m_bUnstoppable = false;
    this->m_flFinishedTime = 0.0;
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: fDelay);
    CEventQueue::CancelEvents(this: &g_EventQueue, pCaller: this);
    COutputEvent::FireOutput(this: &this->m_pOnCommentaryStopped, pActivator: this, pCaller: this, fDelay: 0.0);
    g_CommentarySystem.m_hActiveCommentaryNode.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F74D0
// Name: public: virtual void CCommentarySystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::LevelInitPreEntity(CCommentarySystem *this)
{
  this->m_hCurrentNode.m_Index = -1;
  this->m_bCommentaryConvarsChanging = false;
  this->m_iClearPressedButtons = 0;
  g_bInCommentaryMode = engine->IsInCommentaryMode(this: engine) != 0;
  CCommentarySystem::CalculateCommentaryState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F7510
// Name: public: void CCommentarySystem::ConvarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::ConvarChanged(
        CCommentarySystem *this,
        IConVar *pConVar,
        const char *pOldString,
        float flOldValue)
{
  int v5; // ebx
  modifiedconvars_t *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  int m_nAllocationCount; // eax
  CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int> > *p_m_ModifiedConvars; // esi
  int m_Size; // edi
  modifiedconvars_t *m_pMemory; // ecx
  int v13; // eax
  modifiedconvars_t *v14; // edi
  modifiedconvars_t newConvar; // [esp+Ch] [ebp-188h] BYREF
  ConVarRef var; // [esp+18Ch] [ebp-8h] BYREF
  IConVar *pConVara; // [esp+19Ch] [ebp+8h]

  ConVarRef::ConVarRef(this: &var, pConVar);
  v5 = 0;
  if ( this->m_ModifiedConvars.m_Size <= 0 )
  {
LABEL_5:
    v8 = var.m_pConVar->GetName(this: var.m_pConVar);
    V_strncpy(pDest: newConvar.pszConvar, pSrc: v8, maxLen: 128);
    V_strncpy(pDest: newConvar.pszCurrentValue, pSrc: var.m_pConVarState->m_Value.m_pszString, maxLen: 128);
    V_strncpy(pDest: newConvar.pszOrgValue, pSrc: pOldString, maxLen: 128);
    m_nAllocationCount = this->m_ModifiedConvars.m_Memory.m_nAllocationCount;
    p_m_ModifiedConvars = &this->m_ModifiedConvars;
    m_Size = this->m_ModifiedConvars.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<modifiedconvars_t,int>::Grow(
        this: &p_m_ModifiedConvars->m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_ModifiedConvars->m_Size;
    m_pMemory = p_m_ModifiedConvars->m_Memory.m_pMemory;
    v13 = p_m_ModifiedConvars->m_Size - m_Size - 1;
    p_m_ModifiedConvars->m_pElements = p_m_ModifiedConvars->m_Memory.m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 384 * v13);
    v14 = &p_m_ModifiedConvars->m_Memory.m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = newConvar;
  }
  else
  {
    pConVara = nullptr;
    while ( 1 )
    {
      v6 = (modifiedconvars_t *)((char *)pConVara + (unsigned int)this->m_ModifiedConvars.m_Memory.m_pMemory);
      v7 = var.m_pConVar->GetName(this: var.m_pConVar);
      if ( V_strncmp(s1: v7, s2: v6->pszConvar, count: 128) == 0 )
        break;
      pConVara += 96;
      if ( ++v5 >= this->m_ModifiedConvars.m_Size )
        goto LABEL_5;
    }
    V_strncpy(
      pDest: this->m_ModifiedConvars.m_Memory.m_pMemory[v5].pszCurrentValue,
      pSrc: var.m_pConVarState->m_Value.m_pszString,
      maxLen: 128);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7650
// Name: void CV_GlobalChange_Commentary(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CV_GlobalChange_Commentary(IConVar *var, const char *pOldString, float flOldValue)
{
  if ( g_CommentarySystem.m_bCommentaryConvarsChanging )
    CCommentarySystem::ConvarChanged(this: &g_CommentarySystem, pConVar: var, pOldString, flOldValue);
}

//------------------------------------------------------------------------------
// Address: 0x100F7680
// Name: public: void CPointCommentaryNode::UpdateViewPostThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::UpdateViewPostThink(CPointCommentaryNode *this)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v3; // ebx
  unsigned int m_Index; // eax
  unsigned int v5; // eax
  float m_flFinishedTime; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  double v9; // xmm1_8
  float v10; // xmm0_4
  float v11; // xmm1_4
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float *v15; // eax
  CBaseEntity *v16; // eax
  CBaseEntity *v17; // eax
  CBaseEntity *v18; // eax
  CBaseEntity *v19; // edi
  Quaternion quatCurrent; // [esp+1Ch] [ebp-58h] BYREF
  Quaternion quatFinish; // [esp+2Ch] [ebp-48h] BYREF
  Quaternion quatOriginal; // [esp+3Ch] [ebp-38h] BYREF
  Vector vecCurEye; // [esp+4Ch] [ebp-28h] BYREF
  Vector vecPlayerPos; // [esp+58h] [ebp-1Ch] BYREF
  QAngle angCurrent; // [esp+64h] [ebp-10h] BYREF
  float flBlendPerc; // [esp+70h] [ebp-4h]
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  if ( gpGlobals->maxClients > 1 )
    LocalPlayer = UTIL_PlayerByIndex(playerIndex: 1);
  else
    LocalPlayer = UTIL_GetLocalPlayer();
  v3 = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return;
  m_Index = this->m_hViewPosition.m_Value.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
    || (v5 = this->m_hViewPositionMover.m_Index) == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity == nullptr )
  {
LABEL_26:
    CPointCommentaryNode::CleanupPostCommentary(this);
    this->m_bPreventChangesWhileMoving = false;
    return;
  }
  m_flFinishedTime = this->m_flFinishedTime;
  v7 = gpGlobals->curtime - m_flFinishedTime;
  v8 = m_flFinishedTime - this->m_flStartTime.m_Value;
  if ( v8 <= 2.0 )
    v9 = v8;
  else
    v9 = 2.0;
  v10 = v7 / (float)v9;
  if ( v10 >= 0.0 )
  {
    if ( v10 <= 1.0 )
      v11 = v10;
    else
      v11 = 1.0;
  }
  else
  {
    v11 = 0.0;
  }
  flBlendPerc = 1.0 - v11;
  if ( (float)(1.0 - v11) <= 0.0 )
  {
    v18 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hViewPositionMover);
    v19 = v18;
    if ( (v18->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v18, a2: (int)&savedregs);
    CBasePlayer::SnapEyeAngles(this: v3, viewAngles: &v19->m_angAbsRotation);
    goto LABEL_26;
  }
  v3->EyePosition(this: v3, result: &vecPlayerPos);
  EyePosition = v3->EyePosition;
  v13 = (float)(this->m_vecFinishOrigin.y - vecPlayerPos.y) * flBlendPerc;
  v14 = (float)(this->m_vecFinishOrigin.z - vecPlayerPos.z) * flBlendPerc;
  angCurrent.x = (float)(this->m_vecFinishOrigin.x - vecPlayerPos.x) * flBlendPerc;
  angCurrent.y = v13;
  angCurrent.z = v14;
  v15 = (float *)EyePosition(this: v3, result: (Vector *)&quatOriginal.y);
  vecCurEye.x = *v15 + angCurrent.x;
  vecCurEye.y = v15[1] + angCurrent.y;
  vecCurEye.z = v15[2] + angCurrent.z;
  v16 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hViewPositionMover);
  CBaseEntity::SetAbsOrigin(this: v16, absOrigin: &vecCurEye);
  if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hViewTarget) != nullptr )
  {
    AngleQuaternion(angles: &this->m_vecOriginalAngles, outQuat: &quatOriginal);
    AngleQuaternion(angles: &this->m_vecFinishAngles, outQuat: &quatFinish);
    QuaternionSlerp(p: &quatFinish, q: &quatOriginal, t: 1.0 - flBlendPerc, qt: &quatCurrent);
    QuaternionAngles(q: &quatCurrent, angles: &angCurrent);
    v17 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hViewPositionMover);
    CBaseEntity::SetAbsAngles(this: v17, absAngles: &angCurrent);
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: s_pCommentaryUpdateViewThink);
}

//------------------------------------------------------------------------------
// Address: 0x100F7920
// Name: public: void CPointCommentaryNode::FinishCommentary(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::FinishCommentary(CPointCommentaryNode *this, bool bBlendOut)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v4; // esi
  const char *pszValue; // eax
  unsigned int v6; // eax
  edict_t *m_pPev; // ecx
  edict_t *v8; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // esi
  unsigned int v11; // eax
  CBaseEntity *v12; // esi
  const char *v13; // ecx
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( gpGlobals->maxClients > 1 )
    LocalPlayer = UTIL_PlayerByIndex(playerIndex: 1);
  else
    LocalPlayer = UTIL_GetLocalPlayer();
  v4 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    if ( this->m_iszPostCommands.pszValue != nullptr )
    {
      g_CommentarySystem.m_bCommentaryConvarsChanging = true;
      pszValue = this->m_iszPostCommands.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      engine->ClientCommand(this: engine, a2: v4->m_Network.m_pPev, a3: pszValue);
      engine->ClientCommand(this: engine, a2: v4->m_Network.m_pPev, a3: "commentary_cvarsnotchanging\n");
    }
    this->m_flFinishedTime = gpGlobals->curtime;
    if ( bBlendOut
      && (v6 = this->m_hViewPositionMover.m_Index) != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity != nullptr )
    {
      if ( this->m_bActive.m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x520u);
        }
        this->m_bActive.m_Value = false;
      }
      if ( this->m_flPlaybackRate.m_Value != 1.0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v8 = this->m_Network.m_pPev;
          if ( v8 != nullptr )
            CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x37Cu);
        }
        this->m_flPlaybackRate.m_Value = 1.0;
      }
      m_Index = this->m_hViewPositionMover.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
      this->m_vecFinishOrigin.x = m_pEntity->m_vecAbsOrigin.x;
      this->m_vecFinishOrigin.y = m_pEntity->m_vecAbsOrigin.y;
      this->m_vecFinishOrigin.z = m_pEntity->m_vecAbsOrigin.z;
      v11 = this->m_hViewPositionMover.m_Index;
      if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
        v12 = nullptr;
      else
        v12 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      if ( (v12->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v12, a2: (int)&savedregs);
      v13 = s_pCommentaryUpdateViewThink;
      this->m_vecFinishAngles.x = v12->m_angAbsRotation.x;
      this->m_vecFinishAngles.y = v12->m_angAbsRotation.y;
      this->m_vecFinishAngles.z = v12->m_angAbsRotation.z;
      this->m_bPreventChangesWhileMoving = true;
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CPointCommentaryNode::UpdateViewPostThink,
        thinkTime: gpGlobals->curtime,
        szContext: v13);
    }
    else
    {
      CPointCommentaryNode::CleanupPostCommentary(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7B80
// Name: public: void CPointCommentaryNode::SetDisabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::SetDisabled(CPointCommentaryNode *this, bool bDisabled)
{
  int m_Value; // eax
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx

  this->m_bDisabled = bDisabled;
  if ( bDisabled )
  {
    CBaseEntity::AddEffects(this, nEffects: 32);
  }
  else
  {
    m_Value = this->m_fEffects.m_Value;
    v4 = m_Value & 0xFFFFFFDF;
    if ( m_Value != (m_Value & 0xFFFFFFDF) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      }
      this->m_fEffects.m_Value = v4;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7CC0
// Name: public: void CCommentarySystem::InitCommentary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::InitCommentary(CCommentarySystem *this)
{
  CCommentarySystem *v1; // esi
  void (__thiscall *InstallGlobalChangeCallback)(ICvar *, void (__cdecl *)(IConVar *, const char *, float)); // edx
  const char *m_pszString; // eax
  CBaseEntity *EntityByName; // edi
  const char *v5; // eax
  CBaseEdict *v6; // ecx
  bool v7; // al
  KeyValues *m_pkvSavedModifications; // ecx
  const char *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  IBaseFileSystem *v12; // eax
  unsigned int (__thiscall *Size)(IBaseFileSystem *, const char *, const char *); // eax
  void *v14; // esp
  KeyValues *FirstSubKey; // ebx
  KeyValues *Key; // eax
  const char *Name; // eax
  KeyValues *v18; // edi
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  KeyValues *Copy; // eax
  CBaseEntity *v22; // eax
  CBaseEntity *v23; // edi
  char *m_Index; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v28; // eax
  _DWORD *p_m_Index; // eax
  int i; // esi
  int v31; // esi
  _BYTE *j; // eax
  const char *v33; // ebx
  unsigned __int8 *v34; // eax
  unsigned int v35; // esi
  CPointCommentaryNode *v36; // eax
  CCommentarySystem *v37; // ecx
  CPointTemplate *v38; // eax
  int v39; // ecx
  KeyValues *NextKey; // eax
  int v41; // ebx
  void *v42; // esp
  int k; // edx
  unsigned int v44; // eax
  int v45; // edi
  IHandleEntity *m_pEntity; // eax
  int v47; // edi
  char *v48; // ebx
  int m; // edi
  unsigned int v50; // eax
  CBaseEntity *v51; // ecx
  int n; // edi
  unsigned int v53; // eax
  IHandleEntity *v54; // ecx
  void *v55; // [esp-20h] [ebp-B284h]
  _BYTE v56[12]; // [esp+0h] [ebp-B264h] BYREF
  _BYTE pBuffer[20480]; // [esp+Ch] [ebp-B258h] BYREF
  HierarchicalSpawnMapData_t pSpawnMapData[2048]; // [esp+500Ch] [ebp-6258h] BYREF
  CPointTemplate *pTemplates[2048]; // [esp+900Ch] [ebp-2258h] BYREF
  char pDest[512]; // [esp+B00Ch] [ebp-258h] BYREF
  CUtlBuffer buf; // [esp+B20Ch] [ebp-58h] BYREF
  _BYTE *v62; // [esp+B23Ch] [ebp-28h]
  void *inptr; // [esp+B240h] [ebp-24h]
  char pszValue[4]; // [esp+B244h] [ebp-20h] BYREF
  KeyValues *v65; // [esp+B248h] [ebp-1Ch]
  int v66; // [esp+B24Ch] [ebp-18h]
  KeyValues *v67; // [esp+B250h] [ebp-14h]
  CCommentarySystem *v68; // [esp+B254h] [ebp-10h]
  int iTemplateCount; // [esp+B258h] [ebp-Ch]
  bool v70; // [esp+B25Fh] [ebp-5h]
  char *s1; // [esp+B260h] [ebp-4h]

  v1 = this;
  InstallGlobalChangeCallback = cvar->InstallGlobalChangeCallback;
  v68 = this;
  InstallGlobalChangeCallback(this: cvar, a2: CV_GlobalChange_Commentary);
  v1->m_flNextTeleportTime = 0.0;
  v1->m_iTeleportStage = 0;
  v1->m_hLastCommentaryNode.m_Index = -1;
  if ( CGlobalEntityList::FindEntityByName(
         this: &gEntList,
         pStartEntity: nullptr,
         szName: "commentary_semaphore",
         pSearchingEntity: nullptr,
         pActivator: nullptr,
         pCaller: nullptr,
         pFilter: nullptr) != nullptr )
    return;
  if ( (`CCommentarySystem::InitCommentary'::`4'::`local static guard' & 1) == 0 )
  {
    `CCommentarySystem::InitCommentary'::`4'::`local static guard' |= 1u;
    `CCommentarySystem::InitCommentary'::`4'::infoTargetStr.m_iSerial = 0;
    `CCommentarySystem::InitCommentary'::`4'::infoTargetStr.m_iszString.pszValue = nullptr;
    `CCommentarySystem::InitCommentary'::`4'::infoTargetStr.m_pszString = "info_target";
    atexit(func: `CCommentarySystem::InitCommentary'::`4'::`dynamic atexit destructor for 'infoTargetStr'');
  }
  if ( (`CCommentarySystem::InitCommentary'::`4'::`local static guard' & 2) == 0 )
  {
    `CCommentarySystem::InitCommentary'::`4'::`local static guard' |= 2u;
    `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_iSerial = 0;
    `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_iszString.pszValue = nullptr;
    `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_pszString = "commentary_semaphore";
    atexit(func: `CCommentarySystem::InitCommentary'::`4'::`dynamic atexit destructor for 'commentarySpawnedSemaphoreName'');
  }
  m_pszString = `CCommentarySystem::InitCommentary'::`4'::infoTargetStr.m_pszString;
  if ( `CCommentarySystem::InitCommentary'::`4'::infoTargetStr.m_pszString == nullptr )
    m_pszString = locale;
  EntityByName = CreateEntityByName(className: m_pszString, iForceEdictIndex: -1, bNotify: true);
  v5 = `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_iszString.pszValue;
  if ( `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_iszString.pszValue != nullptr
    && `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_iSerial == CGameString::gm_iSerialNumber )
  {
    goto LABEL_13;
  }
  if ( `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_pszString != nullptr )
  {
    v5 = *(const char **)AllocPooledString(pszValue).pszValue;
    `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_iszString.pszValue = v5;
    `CCommentarySystem::InitCommentary'::`4'::commentarySpawnedSemaphoreName.m_iSerial = CGameString::gm_iSerialNumber;
LABEL_13:
    iTemplateCount = (int)v5;
    goto LABEL_14;
  }
  iTemplateCount = 0;
LABEL_14:
  if ( EntityByName->m_iName.m_Value.pszValue != (const char *)iTemplateCount )
  {
    if ( EntityByName->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&EntityByName->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = &EntityByName->m_Network.m_pPev->CBaseEdict;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xCCu);
    }
    EntityByName->m_iName.m_Value.pszValue = (const char *)iTemplateCount;
  }
  CGlobalEntityList::UpdateName(this: &gEntList, pEnt: EntityByName);
  v7 = engine->LockNetworkStringTables(this: engine, a2: false);
  m_pkvSavedModifications = v1->m_pkvSavedModifications;
  pszValue[0] = v7;
  if ( m_pkvSavedModifications != nullptr )
  {
    KeyValues::deleteThis(this: m_pkvSavedModifications);
    v1->m_pkvSavedModifications = nullptr;
  }
  v9 = gpGlobals->mapname.pszValue;
  if ( v9 == nullptr )
    v9 = locale;
  V_snprintf(pDest, maxLen: 512, pFormat: "maps/%s_commentary.txt", v9);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
  {
    v11 = KeyValues::KeyValues(this: v10, setName: "Commentary");
    v65 = v11;
  }
  else
  {
    v11 = nullptr;
    v65 = nullptr;
  }
  if ( filesystem != nullptr )
    v12 = &filesystem->IBaseFileSystem;
  else
    v12 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v11,
         filesystem: v12,
         resourceName: pDest,
         pathID: "MOD",
         pfnEvaluateSymbolProc: nullptr) )
  {
    _Msg(a1: "Commentary: Loading commentary data from %s. \n", pDest);
    Size = filesystem->Size;
    iTemplateCount = 0;
    v14 = alloca(4 * Size(this: &filesystem->IBaseFileSystem, a2: pDest, a3: "MOD"));
    v62 = v56;
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer, nSize: 20480, nFlags: 0);
    v66 = 0;
    FirstSubKey = KeyValues::GetFirstSubKey(this: v11);
    v67 = FirstSubKey;
    while ( FirstSubKey != nullptr )
    {
      s1 = (char *)KeyValues::GetName(this: FirstSubKey);
      if ( V_strncmp(s1, s2: "trackinfo", count: 9) != 0 )
      {
        Key = KeyValues::FindKey(this: FirstSubKey, keyName: "classname", bCreate: false);
        if ( Key != nullptr )
          s1 = (char *)KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: locale);
        if ( rr_remarkables_enabled.m_pParent == nullptr || rr_remarkables_enabled.m_pParent->m_Value.m_nValue == 0 )
          goto LABEL_50;
        Name = KeyValues::GetName(this: FirstSubKey);
        v70 = _V_strcmp(s1: Name, s2: "modify_entity") == 0;
        v18 = KeyValues::FindKey(this: FirstSubKey, keyName: "mapupdate", bCreate: false);
        if ( g_bInCommentaryMode || V_strncmp(s1, s2: "info_remarkable", count: 16) == 0 || v18 != nullptr )
        {
          if ( v70 )
          {
LABEL_44:
            if ( v1->m_pkvSavedModifications == nullptr )
            {
              v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v19 != nullptr )
                v20 = KeyValues::KeyValues(this: v19, setName: "Entities");
              else
                v20 = nullptr;
              v1->m_pkvSavedModifications = v20;
            }
            Copy = KeyValues::MakeCopy(this: FirstSubKey);
            KeyValues::AddSubKey(this: v1->m_pkvSavedModifications, pSubkey: Copy);
          }
LABEL_50:
          v22 = CreateEntityByName(className: s1, iForceEdictIndex: -1, bNotify: true);
          v23 = v22;
          inptr = v22;
          if ( v22 != nullptr )
          {
            CCommentarySystem::ParseEntKVBlock(this: v1, pNode: v22, pkvNode: FirstSubKey);
            m_Index = (char *)v23->GetRefEHandle(this: v23)->m_Index;
            m_Size = v1->m_hSpawnedEntities.m_Size;
            m_nAllocationCount = v1->m_hSpawnedEntities.m_Memory.m_nAllocationCount;
            s1 = m_Index;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_hSpawnedEntities,
                num: m_Size - m_nAllocationCount + 1);
            ++v1->m_hSpawnedEntities.m_Size;
            m_pMemory = v1->m_hSpawnedEntities.m_Memory.m_pMemory;
            v28 = v1->m_hSpawnedEntities.m_Size - m_Size - 1;
            v1->m_hSpawnedEntities.m_pElements = m_pMemory;
            if ( v28 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v28);
            p_m_Index = &v1->m_hSpawnedEntities.m_Memory.m_pMemory[m_Size].m_Index;
            if ( p_m_Index != nullptr )
              *p_m_Index = s1;
            CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
            KeyValues::RecursiveSaveToFile(this: FirstSubKey, &buf, indentLevel: 0);
            for ( i = buf.m_Put - 1; pBuffer[i] != 125; --i )
              ;
            v31 = i - 1;
            for ( j = pBuffer; *j != 123; ++j )
              ;
            v33 = &v62[v66];
            v34 = j + 2;
            v35 = pBuffer - v34 + v31;
            memcpy(dst: &v62[v66], src: v34, count: v35);
            v66 += v35;
            v55 = inptr;
            pSpawnMapData[m_Size].m_pMapData = v33;
            pSpawnMapData[m_Size].m_iMapDataLength = v35;
            v36 = (CPointCommentaryNode *)__RTDynamicCast(
                                            inptr: v55,
                                            VfDelta: 0,
                                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                                            TargetType: &CPointCommentaryNode `RTTI Type Descriptor',
                                            isReference: 0);
            if ( v36 != nullptr )
            {
              v37 = v68;
              ++v68->m_iCommentaryNodeCount;
              CPointCommentaryNode::SetNodeNumber(this: v36, iCount: v37->m_iCommentaryNodeCount);
            }
            v38 = (CPointTemplate *)__RTDynamicCast(
                                      inptr,
                                      VfDelta: 0,
                                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                                      TargetType: &CPointTemplate `RTTI Type Descriptor',
                                      isReference: 0);
            if ( v38 != nullptr )
            {
              v39 = iTemplateCount;
              pTemplates[iTemplateCount] = v38;
              iTemplateCount = v39 + 1;
            }
          }
          else
          {
            _Warning(a1: "Commentary: Failed to spawn commentary entity, type: '%s'\n", s1);
          }
          NextKey = KeyValues::GetNextKey(this: v67);
          v1 = v68;
          v67 = NextKey;
          FirstSubKey = NextKey;
          continue;
        }
        if ( v70 )
          goto LABEL_44;
      }
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      v67 = FirstSubKey;
    }
    CCommentarySystem::ApplyCommentaryModifications(this: v1);
    if ( iTemplateCount != 0 )
    {
      v41 = v1->m_hSpawnedEntities.m_Size;
      s1 = nullptr;
      v68 = (CCommentarySystem *)v41;
      if ( v41 != 0 )
      {
        v42 = alloca(4 * v41);
        s1 = v56;
        for ( k = 0; k != v41; ++k )
        {
          v44 = v1->m_hSpawnedEntities.m_Memory.m_pMemory[k].m_Index;
          v45 = 4 * k;
          if ( v44 == -1
            || (v41 = (int)v68, g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_SerialNumber != HIWORD(v44)) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_pEntity;
          }
          *(_DWORD *)&s1[v45] = m_pEntity;
        }
      }
      MapEntity_ParseAllEntites_SpawnTemplates(
        pTemplates,
        iTemplateCount,
        pSpawnedEntities: (CBaseEntity **)s1,
        pSpawnMapData,
        iSpawnedEntityCount: v41);
      v47 = v41 - 1;
      if ( v41 - 1 >= 0 )
      {
        v48 = s1;
        do
        {
          if ( *(_DWORD *)&v48[4 * v47] == 0 )
          {
            if ( v1->m_hSpawnedEntities.m_Size - v47 - 1 > 0 )
              _V_memmove(
                dest: &v1->m_hSpawnedEntities.m_Memory.m_pMemory[v47],
                src: &v1->m_hSpawnedEntities.m_Memory.m_pMemory[v47 + 1],
                count: 4 * (v1->m_hSpawnedEntities.m_Size - v47 - 1));
            --v1->m_hSpawnedEntities.m_Size;
          }
          --v47;
        }
        while ( v47 >= 0 );
      }
    }
    for ( m = 0; m != v1->m_hSpawnedEntities.m_Size; ++m )
    {
      v50 = v1->m_hSpawnedEntities.m_Memory.m_pMemory[m].m_Index;
      if ( v50 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v50].m_SerialNumber != HIWORD(v50) )
        v51 = nullptr;
      else
        v51 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v50].m_pEntity;
      DispatchSpawn(pEntity: v51, bRunVScripts: true);
    }
    PrecachePointTemplates();
    for ( n = 0; n < v1->m_hSpawnedEntities.m_Size; ++n )
    {
      v53 = v1->m_hSpawnedEntities.m_Memory.m_pMemory[n].m_Index;
      if ( v53 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_SerialNumber != HIWORD(v53) )
        v54 = nullptr;
      else
        v54 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v53].m_pEntity;
      v54->__vftable[12].dtr_IHandleEntity(this: v54);
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    _Msg(a1: "Commentary: Could not find commentary data file '%s'. \n", pDest);
  }
  KeyValues::deleteThis(this: v65);
  engine->LockNetworkStringTables(this: engine, a2: *(_DWORD *)pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x100F83B0
// Name: public: virtual void CCommentarySystem::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::OnRestore(CCommentarySystem *this)
{
  int v2; // ebx
  int v3; // edi
  ConVar *v4; // eax

  cvar->RemoveGlobalChangeCallback(this: cvar, a2: CV_GlobalChange_Commentary);
  if ( g_bInCommentaryMode )
  {
    v2 = 0;
    if ( this->m_ModifiedConvars.m_Size > 0 )
    {
      v3 = 0;
      do
      {
        v4 = cvar->FindVar_2(this: cvar, a2: &this->m_ModifiedConvars.m_Memory.m_pMemory[v3]);
        if ( v4 != nullptr )
          v4->SetValue_4(this: &v4->IConVar, a2: this->m_ModifiedConvars.m_Memory.m_pMemory[v3].pszCurrentValue);
        ++v2;
        ++v3;
      }
      while ( v2 < this->m_ModifiedConvars.m_Size );
    }
    cvar->InstallGlobalChangeCallback(this: cvar, a2: CV_GlobalChange_Commentary);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8810
// Name: public: virtual void CPointCommentaryNode::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::Spawn(CPointCommentaryNode *this)
{
  const char *v2; // edi
  int v3; // eax
  edict_t *m_pPev; // ecx
  Vector vecMin; // [esp+18h] [ebp-20h] BYREF
  Vector vecMax; // [esp+24h] [ebp-14h] BYREF
  char pszValue[4]; // [esp+30h] [ebp-8h] BYREF
  _BYTE v8[4]; // [esp+34h] [ebp-4h] BYREF

  v2 = *(const char **)((int (__thiscall *)(CPointCommentaryNode *, _BYTE *))this->GetModelName)(a1: this, a2: v8);
  if ( v2 == nullptr || *v2 == 0 )
  {
    v2 = "models/extras/info_speech.mdl";
    this->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
  this->Precache(this);
  this->SetModel(this, a2: v2);
  vecMax.x = 16.0;
  vecMax.y = 16.0;
  vecMax.z = 16.0;
  vecMin.x = -16.0;
  vecMin.y = -16.0;
  vecMin.z = -16.0;
  UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 3);
  CBaseEntity::AddEffects(this, nEffects: 16);
  v3 = CBaseAnimating::LookupSequence(this, label: "idle");
  CBaseAnimating::ResetSequence(this, nSequence: v3);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CPointCommentaryNode::SpinThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  if ( this->m_iNodeNumberMax.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x530u);
    }
    this->m_iNodeNumberMax.m_Value = 0;
  }
  CPointCommentaryNode::SetDisabled(this, bDisabled: this->m_bDisabled);
}

//------------------------------------------------------------------------------
// Address: 0x100F8970
// Name: void CC_CommentaryFinishNode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CommentaryFinishNode()
{
  CPointCommentaryNode *m_pEntity; // eax

  if ( g_CommentarySystem.m_hActiveCommentaryNode.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_SerialNumber == HIWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_pEntity != nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_SerialNumber == HIWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index) )
      m_pEntity = (CPointCommentaryNode *)g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_pEntity;
    else
      m_pEntity = nullptr;
    if ( m_pEntity->m_bActive.m_Value )
      CPointCommentaryNode::FinishCommentary(this: m_pEntity, bBlendOut: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F89D0
// Name: public: void CPointCommentaryNode::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::InputEnable(CPointCommentaryNode *this, inputdata_t *inputdata)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx

  this->m_bDisabled = false;
  v3 = this->m_fEffects.m_Value & 0xFFFFFFDF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F8A30
// Name: public: void CPointCommentaryNode::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::InputDisable(CPointCommentaryNode *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x100F8BF0
// Name: public: virtual void CCommentarySystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::LevelInitPostEntity(CCommentarySystem *this)
{
  MapLoadType_t eLoadType; // eax
  IGameEvent *v2; // eax

  if ( g_bInCommentaryMode
    || rr_remarkables_enabled.m_pParent != nullptr && rr_remarkables_enabled.m_pParent->m_Value.m_nValue != 0 )
  {
    eLoadType = gpGlobals->eLoadType;
    if ( eLoadType != MapLoad_LoadGame && eLoadType != MapLoad_Background )
    {
      this->m_bCommentaryEnabledMidGame = false;
      CCommentarySystem::InitCommentary(this);
      if ( g_bInCommentaryMode )
      {
        v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "playing_commentary", a3: 0, a4: 0);
        gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v2);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8C60
// Name: public: void CCommentarySystem::ShutDownCommentary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::ShutDownCommentary(CCommentarySystem *this)
{
  unsigned int m_Index; // ecx
  int v3; // edi
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CPointCommentaryNode **v9; // eax
  CPointCommentaryNode *v10; // ecx
  int i; // ebx
  CHandle<CBaseEntity> *m_pMemory; // ecx
  unsigned int v13; // eax
  CHandle<CBaseEntity> *v14; // edx
  unsigned int v15; // eax
  CBaseEntity *m_pEntity; // ecx
  CBaseEntity *EntityByName; // eax
  int j; // ebx
  ConVar *v19; // eax
  KeyValues *m_pkvSavedModifications; // ecx

  m_Index = this->m_hActiveCommentaryNode.m_Index;
  v3 = 0;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CPointCommentaryNode **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      if ( v10->m_bActive.m_Value )
      {
        CPointCommentaryNode::FinishCommentary(this: v10, bBlendOut: false);
      }
      else if ( v10->m_bPreventChangesWhileMoving )
      {
        CPointCommentaryNode::CleanupPostCommentary(this: v10);
      }
    }
  }
  for ( i = this->m_hSpawnedEntities.m_Size - 1; i >= 0; --i )
  {
    m_pMemory = this->m_hSpawnedEntities.m_Memory.m_pMemory;
    v13 = m_pMemory[i].m_Index;
    v14 = &m_pMemory[i];
    if ( v13 != -1 )
    {
      v3 = 0;
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber == HIWORD(v13)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity != nullptr )
      {
        v15 = v14->m_Index;
        if ( v14->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
        UTIL_Remove(oldObj: m_pEntity);
      }
    }
  }
  this->m_hSpawnedEntities.m_Size = 0;
  if ( this->m_hSpawnedEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_hSpawnedEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_hSpawnedEntities.m_Memory.m_pMemory);
      this->m_hSpawnedEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_hSpawnedEntities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_hSpawnedEntities.m_pElements = this->m_hSpawnedEntities.m_Memory.m_pMemory;
  this->m_iCommentaryNodeCount = 0;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: "commentary_semaphore",
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    UTIL_Remove(oldObj: EntityByName);
  cvar->RemoveGlobalChangeCallback(this: cvar, a2: CV_GlobalChange_Commentary);
  for ( j = 0; j < this->m_ModifiedConvars.m_Size; ++v3 )
  {
    v19 = cvar->FindVar_2(this: cvar, a2: &this->m_ModifiedConvars.m_Memory.m_pMemory[v3]);
    if ( v19 != nullptr )
      v19->SetValue_4(this: &v19->IConVar, a2: this->m_ModifiedConvars.m_Memory.m_pMemory[v3].pszOrgValue);
    ++j;
  }
  this->m_ModifiedConvars.m_Size = 0;
  if ( this->m_ModifiedConvars.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ModifiedConvars.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ModifiedConvars.m_Memory.m_pMemory);
      this->m_ModifiedConvars.m_Memory.m_pMemory = nullptr;
    }
    this->m_ModifiedConvars.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ModifiedConvars.m_pElements = this->m_ModifiedConvars.m_Memory.m_pMemory;
  m_pkvSavedModifications = this->m_pkvSavedModifications;
  if ( m_pkvSavedModifications != nullptr )
    KeyValues::deleteThis(this: m_pkvSavedModifications);
  this->m_pkvSavedModifications = nullptr;
  this->m_hCurrentNode.m_Index = -1;
  this->m_hActiveCommentaryNode.m_Index = -1;
  this->m_hLastCommentaryNode.m_Index = -1;
  this->m_iTeleportStage = 0;
  this->m_flNextTeleportTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100F8E30
// Name: public: void CCommentarySystem::JumpToNextNode(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::JumpToNextNode(CCommentarySystem *this, CBasePlayer *pPlayer)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *EntityByClassname; // esi
  unsigned int v6; // eax
  IHandleEntity *v7; // ecx
  void *v8; // eax
  unsigned int v9; // eax
  CPointCommentaryNode *v10; // eax

  if ( this->m_flNextTeleportTime <= gpGlobals->curtime && this->m_iTeleportStage == 0 )
  {
    m_Index = this->m_hLastCommentaryNode.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    EntityByClassname = (CBaseEntity *)m_pEntity;
    while ( 1 )
    {
      EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                            this: &gEntList,
                            pStartEntity: EntityByClassname,
                            szName: "point_commentary_node");
      v6 = this->m_hLastCommentaryNode.m_Index;
      if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
        v7 = nullptr;
      else
        v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
      if ( EntityByClassname == v7 )
        break;
      v8 = __RTDynamicCast(
             inptr: EntityByClassname,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CPointCommentaryNode `RTTI Type Descriptor',
             isReference: 0);
      if ( v8 != nullptr )
      {
        this->m_iTeleportStage = 1;
        this->m_hLastCommentaryNode.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 8))(a1: v8);
        this->m_flNextTeleportTime = gpGlobals->curtime;
        v9 = this->m_hActiveCommentaryNode.m_Index;
        if ( v9 != -1
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber == HIWORD(v9)
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity != nullptr )
        {
          v10 = (CPointCommentaryNode *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hActiveCommentaryNode);
          if ( v10->m_bActive.m_Value )
            CPointCommentaryNode::FinishCommentary(this: v10, bBlendOut: true);
        }
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8F50
// Name: void CC_CommentaryChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CommentaryChanged(IConVar *pConVar)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( (var.m_pConVarState->m_Value.m_nValue != 0) != g_bInCommentaryMode )
  {
    g_bInCommentaryMode = var.m_pConVarState->m_Value.m_nValue != 0;
    CCommentarySystem::CalculateCommentaryState(this: &g_CommentarySystem);
    if ( g_bInCommentaryMode )
    {
      g_CommentarySystem.m_bCommentaryEnabledMidGame = true;
      CCommentarySystem::InitCommentary(this: &g_CommentarySystem);
    }
    else
    {
      CCommentarySystem::ShutDownCommentary(this: &g_CommentarySystem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8FB0
// Name: public: void CPointCommentaryNode::PlayerActivated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::PlayerActivated(CPointCommentaryNode *this)
{
  gamestats->Event_Commentary(this: gamestats);
  if ( this->m_bActive.m_Value )
  {
    CPointCommentaryNode::FinishCommentary(this, bBlendOut: true);
  }
  else
  {
    CPointCommentaryNode::StartCommentary(this);
    g_CommentarySystem.m_hActiveCommentaryNode.m_Index = this->GetRefEHandle(this)->m_Index;
    g_CommentarySystem.m_hLastCommentaryNode.m_Index = this->GetRefEHandle(this)->m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F9000
// Name: public: void CPointCommentaryNode::InputStartCommentary(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::InputStartCommentary(CPointCommentaryNode *this, inputdata_t *inputdata)
{
  CPointCommentaryNode *m_pEntity; // eax

  if ( !this->m_bActive.m_Value )
  {
    if ( g_CommentarySystem.m_hActiveCommentaryNode.m_Index != -1
      && g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_SerialNumber == HIWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)
      && g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_pEntity != nullptr )
    {
      if ( g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_SerialNumber == HIWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index) )
        m_pEntity = (CPointCommentaryNode *)g_pEntityList->m_EntPtrArray[LOWORD(g_CommentarySystem.m_hActiveCommentaryNode.m_Index)].m_pEntity;
      else
        m_pEntity = nullptr;
      if ( m_pEntity->m_bActive.m_Value )
        CPointCommentaryNode::FinishCommentary(this: m_pEntity, bBlendOut: true);
    }
    gamestats->Event_Commentary(this: gamestats);
    if ( this->m_bActive.m_Value )
    {
      CPointCommentaryNode::FinishCommentary(this, bBlendOut: true);
    }
    else
    {
      CPointCommentaryNode::StartCommentary(this);
      g_CommentarySystem.m_hActiveCommentaryNode.m_Index = this->GetRefEHandle(this)->m_Index;
      g_CommentarySystem.m_hLastCommentaryNode.m_Index = this->GetRefEHandle(this)->m_Index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F90C0
// Name: public: void CPointCommentaryNode::InputStartUnstoppableCommentary(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointCommentaryNode::InputStartUnstoppableCommentary(
        CPointCommentaryNode *this,
        inputdata_t *inputdata)
{
  if ( !this->m_bActive.m_Value )
  {
    this->m_bUnstoppable = true;
    CPointCommentaryNode::InputStartCommentary(this, inputdata);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F94F0
// Name: public: virtual void CCommentarySystem::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCommentarySystem::LevelShutdownPreEntity(CCommentarySystem *this)
{
  CCommentarySystem::ShutDownCommentary(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F9500
// Name: public: void CCommentarySystem::PrePlayerRunCommand(class CBasePlayer __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentarySystem::PrePlayerRunCommand(
        CCommentarySystem *this,
        CBasePlayer *pPlayer,
        color32_s pUserCmds)
{
  CPointCommentaryNode *NodeUnderCrosshair; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CUserCmd *v7; // edi
  int v8; // ecx
  int v9; // eax
  color32_s v10; // ebx
  CPointCommentaryNode *ActiveNode; // eax
  CPointCommentaryNode *v12; // eax
  CPointCommentaryNode *v13; // ebx
  CPointCommentaryNode *v14; // eax
  CPointCommentaryNode *v15; // eax
  CPointCommentaryNode *v16; // eax
  CPointCommentaryNode *v17; // eax
  CPointCommentaryNode *v18; // eax
  unsigned int v19; // eax
  CPointCommentaryNode *v20; // eax
  int m_iTeleportStage; // eax
  float v22; // xmm1_4
  CPointCommentaryNode *v23; // eax
  CBasePlayer *v24; // [esp-8h] [ebp-20h]
  int v25; // [esp+8h] [ebp-10h]

  if ( !g_bInCommentaryMode || pPlayer->IsFakeClient(this: pPlayer) )
    return;
  NodeUnderCrosshair = CCommentarySystem::GetNodeUnderCrosshair(this);
  m_Index = this->m_hCurrentNode.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != NodeUnderCrosshair )
  {
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      BYTE1(CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCurrentNode)[1].m_vecBaseVelocity.m_Value.x) = 0;
    }
    if ( NodeUnderCrosshair != nullptr )
    {
      CPointCommentaryNode::SetUnderCrosshair(this: NodeUnderCrosshair, bUnderCrosshair: true);
      this->m_hCurrentNode.m_Index = NodeUnderCrosshair->GetRefEHandle(this: NodeUnderCrosshair)->m_Index;
    }
    else
    {
      this->m_hCurrentNode.m_Index = -1;
    }
  }
  v7 = (CUserCmd *)pUserCmds;
  v8 = *(_DWORD *)(*(_DWORD *)&pUserCmds + 36);
  v9 = v8 & (v8 ^ this->m_afPlayersLastButtons);
  this->m_afPlayersLastButtons = v8;
  if ( (v7->buttons & 0x20) == 0 )
    this->m_iClearPressedButtons &= ~0x20u;
  v10 = (color32_s)(v9 & 0x20);
  pUserCmds = v10;
  if ( (v9 & 0x20) != 0 )
  {
    if ( (v9 & 0x800) != 0 )
    {
      if ( CCommentarySystem::GetActiveNode(this) == nullptr
        || (ActiveNode = CCommentarySystem::GetActiveNode(this), !CPointCommentaryNode::CannotBeStopped(this: ActiveNode)) )
      {
        CCommentarySystem::JumpToNextNode(this, pPlayer);
LABEL_36:
        v7->buttons &= ~0x20u;
        this->m_iClearPressedButtons |= *(_DWORD *)&v10;
      }
    }
    else
    {
      if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCurrentNode) != nullptr )
      {
        if ( CCommentarySystem::GetActiveNode(this) == nullptr
          || (v12 = CCommentarySystem::GetActiveNode(this), !CPointCommentaryNode::CannotBeStopped(this: v12)) )
        {
          if ( CCommentarySystem::GetActiveNode(this) != nullptr )
          {
            v13 = (CPointCommentaryNode *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCurrentNode);
            if ( CCommentarySystem::GetActiveNode(this) != v13 )
            {
              v14 = CCommentarySystem::GetActiveNode(this);
              if ( v14->m_bActive.m_Value )
                CPointCommentaryNode::FinishCommentary(this: v14, bBlendOut: true);
            }
            v10 = pUserCmds;
          }
          v15 = (CPointCommentaryNode *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hCurrentNode);
          CPointCommentaryNode::PlayerActivated(this: v15);
        }
        goto LABEL_36;
      }
      if ( CCommentarySystem::GetActiveNode(this) != nullptr )
      {
        v16 = CCommentarySystem::GetActiveNode(this);
        if ( CPointCommentaryNode::HasViewTarget(this: v16) )
        {
          v17 = CCommentarySystem::GetActiveNode(this);
          if ( !CPointCommentaryNode::CannotBeStopped(this: v17) )
          {
            v18 = CCommentarySystem::GetActiveNode(this);
            if ( v18->m_bActive.m_Value )
              CPointCommentaryNode::FinishCommentary(this: v18, bBlendOut: true);
          }
          goto LABEL_36;
        }
      }
    }
  }
  v19 = this->m_hActiveCommentaryNode.m_Index;
  if ( v19 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber == HIWORD(v19)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity != nullptr )
  {
    v20 = CCommentarySystem::GetActiveNode(this);
    if ( CPointCommentaryNode::PreventsMovement(this: v20) )
    {
      v7->buttons &= 0xFFFFF9E1;
      v7->upmove = 0.0;
      v7->sidemove = 0.0;
      v7->forwardmove = 0.0;
    }
  }
  v7->buttons &= ~this->m_iClearPressedButtons;
  m_iTeleportStage = this->m_iTeleportStage;
  if ( m_iTeleportStage != 0 && gpGlobals->curtime >= this->m_flNextTeleportTime )
  {
    if ( m_iTeleportStage == 1 )
    {
      v25 = 26;
      this->m_iTeleportStage = 2;
      v22 = gpGlobals->curtime + 0.35;
      v24 = pPlayer;
LABEL_52:
      this->m_flNextTeleportTime = v22;
      pUserCmds = (color32_s)-16777216;
      UTIL_ScreenFade(pEntity: v24, color: &pUserCmds, fadeTime: 0.30000001, fadeHold: 0.0, flags: v25);
      return;
    }
    if ( m_iTeleportStage != 2 )
    {
      if ( m_iTeleportStage != 3 )
        return;
      v25 = 17;
      this->m_iTeleportStage = 0;
      v22 = gpGlobals->curtime + 0.25;
      v24 = pPlayer;
      goto LABEL_52;
    }
    if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hLastCommentaryNode) != nullptr )
    {
      v23 = (CPointCommentaryNode *)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hLastCommentaryNode);
      CPointCommentaryNode::TeleportTo(this: v23, a2: *(_DWORD *)&v10, pPlayer);
    }
    this->m_iTeleportStage = 3;
    this->m_flNextTeleportTime = gpGlobals->curtime + 0.6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F9860
// Name: void CommentarySystem_PePlayerRunCommand(class CBasePlayer __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommentarySystem_PePlayerRunCommand(CBasePlayer *player, CUserCmd *ucmd)
{
  CCommentarySystem::PrePlayerRunCommand(this: &g_CommentarySystem, pPlayer: player, pUserCmds: (color32_s)ucmd);
}

//------------------------------------------------------------------------------
// Address: 0x104014B0
// Name: _dynamic_initializer_for__commentary_available__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary_available__()
{
  ConVar::ConVar(
    this: &commentary_available,
    pName: "commentary_available",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Automatically set by the game when a commentary file is available for the current map.");
  return atexit(func: dynamic_atexit_destructor_for__commentary_available__);
}

//------------------------------------------------------------------------------
// Address: 0x104014E0
// Name: PrecachePointCommentaryNodePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int PrecachePointCommentaryNodePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  PrecachePointCommentaryNodePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&PrecachePointCommentaryNodePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401500
// Name: CPointCommentaryNode_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointCommentaryNode_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointCommentaryNode>(__formal: nullptr);
  CPointCommentaryNode_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401530
// Name: DT_PointCommentaryNode::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PointCommentaryNode::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PointCommentaryNode::g_SendTable);
  return atexit(func: DT_PointCommentaryNode::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401550
// Name: DT_PointCommentaryNode::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PointCommentaryNode::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PointCommentaryNode::ignored>();
  DT_PointCommentaryNode::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401620
// Name: CCommentarySystem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCommentarySystem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCommentarySystem>(__formal: nullptr);
  CCommentarySystem_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401630
// Name: modifiedconvars_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *modifiedconvars_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<modifiedconvars_t>();
  modifiedconvars_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401640
// Name: _dynamic_initializer_for__commentary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary__()
{
  ConVar::ConVar(
    this: &commentary,
    pName: "commentary",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Desired commentary mode state.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))CC_CommentaryChanged);
  return atexit(func: dynamic_atexit_destructor_for__commentary__);
}

//------------------------------------------------------------------------------
// Address: 0x10401670
// Name: _dynamic_initializer_for__commentary_cvarsnotchanging__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary_cvarsnotchanging__()
{
  ConCommand::ConCommand(
    this: &commentary_cvarsnotchanging,
    pName: "commentary_cvarsnotchanging",
    callback: CC_CommentaryNotChanging,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__commentary_cvarsnotchanging__);
}

//------------------------------------------------------------------------------
// Address: 0x104016A0
// Name: _dynamic_initializer_for__commentary_finishnode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary_finishnode__()
{
  ConCommand::ConCommand(
    this: &commentary_finishnode,
    pName: "commentary_finishnode",
    callback: CC_CommentaryFinishNode,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__commentary_finishnode__);
}

//------------------------------------------------------------------------------
// Address: 0x104016D0
// Name: _dynamic_initializer_for__commentary_auto__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary_auto__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CCommentaryAuto> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &commentary_auto,
           a3: "commentary_auto");
}

//------------------------------------------------------------------------------
// Address: 0x104016F0
// Name: CCommentaryAuto_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCommentaryAuto_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCommentaryAuto>(__formal: nullptr);
  CCommentaryAuto_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A590
// Name: _dynamic_atexit_destructor_for__commentary_available__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__commentary_available__()
{
  ConVar::~ConVar(this: &commentary_available);
}

//------------------------------------------------------------------------------
// Address: 0x1041A5A0
// Name: DT_PointCommentaryNode::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PointCommentaryNode::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PointCommentaryNode::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A5B0
// Name: _dynamic_atexit_destructor_for__commentary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__commentary__()
{
  ConVar::~ConVar(this: &commentary);
}

//------------------------------------------------------------------------------
// Address: 0x1041A5C0
// Name: _dynamic_atexit_destructor_for__commentary_cvarsnotchanging__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__commentary_cvarsnotchanging__()
{
  ConCommand::~ConCommand(this: &commentary_cvarsnotchanging);
}

//------------------------------------------------------------------------------
// Address: 0x1041A5D0
// Name: _dynamic_atexit_destructor_for__commentary_finishnode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__commentary_finishnode__()
{
  ConCommand::~ConCommand(this: &commentary_finishnode);
}

//------------------------------------------------------------------------------
// Address: 0x100F6C10
// Name: class CCommentaryAuto __near * _CreateEntityTemplate<class CCommentaryAuto>(class CCommentaryAuto __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCommentaryAuto *__cdecl _CreateEntityTemplate<CCommentaryAuto>(CCommentaryAuto *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x39Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CCommentaryAuto::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    v3[219] = 0;
    v3[222] = -1;
    v3[223] = 0;
    v3[225] = 0;
    v3[228] = -1;
    v3[229] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CCommentaryAuto *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8470
// Name: struct datamap_t __near * DataMapInit<class CCommentarySystem>(class CCommentarySystem __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCommentarySystem>()
{
  if ( (_S4_21 & 1) == 0 )
  {
    _S4_21 |= 1u;
    nameHolder_120.m_pszBase = "CCommentarySystem";
    nameHolder_120.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_120.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_120.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_120.m_Names.m_Size = 0;
    nameHolder_120.m_Names.m_pElements = nullptr;
    nameHolder_120.m_nLenBase = 17;
    atexit(func: DataMapInit_CCommentarySystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCommentarySystem::m_DataMap.baseMap = nullptr;
  if ( (_S4_21 & 2) == 0 )
  {
    _S4_21 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>,10>::`vftable';
    }
    dataDesc_115[4].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<modifiedconvars_t,CUtlMemory<modifiedconvars_t,int>>>'::`2'::ops;
    dataDesc_115[4].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_115[4].td = 0;
    *(_QWORD *)&dataDesc_115[4].override_field = 0;
    *(_QWORD *)&dataDesc_115[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_115[4].flatOffset[1] = 0;
    dataDesc_115[5].fieldType = FIELD_CUSTOM;
    dataDesc_115[5].fieldName = "m_hSpawnedEntities";
    dataDesc_115[5].fieldOffset = 64;
    dataDesc_115[5].fieldSize = 1;
    dataDesc_115[5].flags = 2;
    dataDesc_115[5].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    *(_QWORD *)&dataDesc_115[5].td = 0;
    *(_QWORD *)&dataDesc_115[5].override_field = 0;
    *(_QWORD *)&dataDesc_115[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_115[5].flatOffset[1] = 0;
    dataDesc_115[6].fieldType = FIELD_EHANDLE;
    dataDesc_115[6].fieldSize = 1;
    dataDesc_115[7].fieldType = FIELD_EHANDLE;
    dataDesc_115[8].fieldType = FIELD_EHANDLE;
    *(_QWORD *)dataDesc_115[6].flatOffset = 0;
    dataDesc_115[7].fieldSize = 1;
    dataDesc_115[6].flags = 2;
    dataDesc_115[8].fieldSize = 1;
    dataDesc_115[6].fieldTolerance = 0.0;
    dataDesc_115[7].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_115[7].flatOffset = 0;
    dataDesc_115[8].fieldTolerance = 0.0;
    dataDesc_115[9].fieldTolerance = 0.0;
    dataDesc_115[7].flags = 2;
    dataDesc_115[5].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_115[5].inputFunc = nullptr;
    dataDesc_115[6].fieldName = "m_hCurrentNode";
    dataDesc_115[6].fieldOffset = 84;
    dataDesc_115[6].externalName = nullptr;
    dataDesc_115[6].pSaveRestoreOps = nullptr;
    dataDesc_115[6].inputFunc = nullptr;
    dataDesc_115[6].td = nullptr;
    dataDesc_115[6].fieldSizeInBytes = 4;
    dataDesc_115[6].override_field = nullptr;
    dataDesc_115[6].override_count = 0;
    *(_DWORD *)&dataDesc_115[6].flatGroup = 0;
    dataDesc_115[7].fieldName = "m_hActiveCommentaryNode";
    dataDesc_115[7].fieldOffset = 88;
    dataDesc_115[7].externalName = nullptr;
    dataDesc_115[7].pSaveRestoreOps = nullptr;
    dataDesc_115[7].inputFunc = nullptr;
    dataDesc_115[7].td = nullptr;
    dataDesc_115[7].fieldSizeInBytes = 4;
    dataDesc_115[7].override_field = nullptr;
    dataDesc_115[7].override_count = 0;
    *(_DWORD *)&dataDesc_115[7].flatGroup = 0;
    dataDesc_115[8].fieldName = "m_hLastCommentaryNode";
    dataDesc_115[8].fieldOffset = 92;
    dataDesc_115[8].flags = 2;
    dataDesc_115[8].externalName = nullptr;
    dataDesc_115[8].pSaveRestoreOps = nullptr;
    dataDesc_115[8].inputFunc = nullptr;
    dataDesc_115[8].td = nullptr;
    dataDesc_115[8].fieldSizeInBytes = 4;
    dataDesc_115[8].override_field = nullptr;
    dataDesc_115[8].override_count = 0;
    *(_QWORD *)dataDesc_115[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_115[8].flatGroup = 0;
    dataDesc_115[9].fieldType = FIELD_INTEGER;
    dataDesc_115[9].fieldName = "m_iCommentaryNodeCount";
    dataDesc_115[9].fieldOffset = 16;
    *(_DWORD *)&dataDesc_115[9].fieldSize = 131073;
    dataDesc_115[9].externalName = nullptr;
    dataDesc_115[9].pSaveRestoreOps = nullptr;
    dataDesc_115[9].inputFunc = nullptr;
    dataDesc_115[9].td = nullptr;
    dataDesc_115[9].fieldSizeInBytes = 4;
    dataDesc_115[9].override_field = nullptr;
    dataDesc_115[9].override_count = 0;
    *(_QWORD *)dataDesc_115[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_115[9].flatGroup = 0;
  }
  CCommentarySystem::m_DataMap.dataNumFields = 9;
  CCommentarySystem::m_DataMap.dataDesc = &dataDesc_115[1];
  return &CCommentarySystem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F8A50
// Name: struct datamap_t __near * DataMapInit<class CCommentaryAuto>(class CCommentaryAuto __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCommentaryAuto>()
{
  if ( (_S6_9 & 1) == 0 )
  {
    _S6_9 |= 1u;
    nameHolder_122.m_pszBase = "CCommentaryAuto";
    nameHolder_122.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_122.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_122.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_122.m_Names.m_Size = 0;
    nameHolder_122.m_Names.m_pElements = nullptr;
    nameHolder_122.m_nLenBase = 15;
    atexit(func: DataMapInit_CCommentaryAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCommentaryAuto::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S6_9 & 2) == 0 )
  {
    _S6_9 |= 2u;
    *(_QWORD *)&dataDesc_117[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_117[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_117[2].override_count = 0;
    *(_QWORD *)dataDesc_117[2].flatOffset = 0;
    dataDesc_117[3].fieldSize = 1;
    *(_QWORD *)&dataDesc_117[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_117[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_117[3].override_count = 0;
    *(_QWORD *)dataDesc_117[3].flatOffset = 0;
    dataDesc_117[2].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_117[2].flatGroup = 0;
    dataDesc_117[3].fieldType = FIELD_CUSTOM;
    dataDesc_117[3].fieldName = "m_OnCommentaryMidGame";
    dataDesc_117[3].fieldOffset = 876;
    dataDesc_117[3].flags = 22;
    dataDesc_117[3].externalName = "OnCommentaryMidGame";
    dataDesc_117[3].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_117[3].flatGroup = 0;
    dataDesc_117[4].fieldType = FIELD_CUSTOM;
    dataDesc_117[4].fieldName = "m_OnCommentaryMultiplayerSpawn";
    dataDesc_117[4].fieldOffset = 900;
    *(_DWORD *)&dataDesc_117[4].fieldSize = 1441793;
    dataDesc_117[4].externalName = "OnCommentaryMultiplayerSpawn";
    dataDesc_117[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_117[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_117[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_117[4].override_count = 0;
    *(_QWORD *)dataDesc_117[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_117[4].flatGroup = 0;
  }
  CCommentaryAuto::m_DataMap.dataNumFields = 4;
  CCommentaryAuto::m_DataMap.dataDesc = &dataDesc_117[1];
  return &CCommentaryAuto::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F90E0
// Name: struct datamap_t __near * DataMapInit<class CPointCommentaryNode>(class CPointCommentaryNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointCommentaryNode>()
{
  char *Name; // eax

  if ( (_S2_66 & 1) == 0 )
  {
    _S2_66 |= 1u;
    nameHolder_123.m_pszBase = "CPointCommentaryNode";
    nameHolder_123.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_123.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_123.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_123.m_Names.m_Size = 0;
    nameHolder_123.m_Names.m_pElements = nullptr;
    nameHolder_123.m_nLenBase = 20;
    atexit(func: DataMapInit_CPointCommentaryNode__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointCommentaryNode::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2_66 & 2) == 0 )
  {
    _S2_66 |= 2u;
    *(_QWORD *)&dataDesc_118[26].inputFunc = 0;
    *(_QWORD *)&dataDesc_118[26].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_118[26].override_count = 0;
    *(_QWORD *)dataDesc_118[26].flatOffset = 0;
    dataDesc_118[26].pSaveRestoreOps = eventFuncs;
    dataDesc_118[27].pSaveRestoreOps = eventFuncs;
    dataDesc_118[27].fieldSize = 1;
    *(_QWORD *)&dataDesc_118[27].inputFunc = 0;
    *(_QWORD *)&dataDesc_118[27].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_118[27].override_count = 0;
    *(_QWORD *)dataDesc_118[27].flatOffset = 0;
    dataDesc_118[27].flags = 22;
    dataDesc_118[28].fieldSize = 1;
    *(_QWORD *)&dataDesc_118[28].td = 0;
    *(_QWORD *)&dataDesc_118[28].override_field = 0;
    *(_QWORD *)&dataDesc_118[28].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_118[28].flatOffset[1] = 0;
    dataDesc_118[28].flags = 8;
    dataDesc_118[29].fieldSize = 1;
    *(_QWORD *)&dataDesc_118[29].td = 0;
    *(_QWORD *)&dataDesc_118[29].override_field = 0;
    *(_QWORD *)&dataDesc_118[29].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_118[29].flatOffset[1] = 0;
    dataDesc_118[29].flags = 8;
    dataDesc_118[30].fieldSize = 1;
    *(_QWORD *)&dataDesc_118[30].td = 0;
    *(_QWORD *)&dataDesc_118[30].override_field = 0;
    *(_QWORD *)&dataDesc_118[30].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_118[30].flatOffset[1] = 0;
    *(_DWORD *)&dataDesc_118[26].flatGroup = 0;
    dataDesc_118[27].fieldType = FIELD_CUSTOM;
    dataDesc_118[27].fieldName = "m_pOnCommentaryStopped";
    dataDesc_118[27].fieldOffset = 1288;
    dataDesc_118[27].externalName = "OnCommentaryStopped";
    *(_DWORD *)&dataDesc_118[27].flatGroup = 0;
    dataDesc_118[28].fieldType = FIELD_VOID;
    dataDesc_118[28].fieldName = "InputStartCommentary";
    dataDesc_118[28].fieldOffset = 0;
    dataDesc_118[28].externalName = "StartCommentary";
    dataDesc_118[28].pSaveRestoreOps = nullptr;
    dataDesc_118[28].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCommentaryNode::InputStartCommentary;
    dataDesc_118[29].fieldType = FIELD_VOID;
    dataDesc_118[29].fieldName = "InputStartUnstoppableCommentary";
    dataDesc_118[29].fieldOffset = 0;
    dataDesc_118[29].externalName = "StartUnstoppableCommentary";
    dataDesc_118[29].pSaveRestoreOps = nullptr;
    dataDesc_118[29].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCommentaryNode::InputStartUnstoppableCommentary;
    dataDesc_118[30].fieldType = FIELD_VOID;
    dataDesc_118[30].fieldName = "InputEnable";
    dataDesc_118[30].fieldOffset = 0;
    dataDesc_118[30].flags = 8;
    dataDesc_118[30].externalName = "Enable";
    dataDesc_118[30].pSaveRestoreOps = nullptr;
    dataDesc_118[30].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCommentaryNode::InputEnable;
    dataDesc_118[31].fieldType = FIELD_VOID;
    dataDesc_118[31].fieldName = "InputDisable";
    dataDesc_118[31].fieldOffset = 0;
    dataDesc_118[31].fieldSize = 1;
    dataDesc_118[31].flags = 8;
    dataDesc_118[31].externalName = "Disable";
    dataDesc_118[31].pSaveRestoreOps = nullptr;
    dataDesc_118[31].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCommentaryNode::InputDisable;
    *(_QWORD *)&dataDesc_118[31].td = 0;
    *(_QWORD *)&dataDesc_118[31].override_field = 0;
    *(_QWORD *)&dataDesc_118[31].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_118[31].flatOffset[1] = 0;
    dataDesc_118[32].fieldType = FIELD_VOID;
    dataDesc_118[32].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_123,
                                   pszIdentifier: "SpinThink");
    dataDesc_118[32].fieldOffset = 0;
    dataDesc_118[32].fieldSize = 1;
    dataDesc_118[32].flags = 32;
    dataDesc_118[32].externalName = nullptr;
    dataDesc_118[32].pSaveRestoreOps = nullptr;
    dataDesc_118[32].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCommentaryNode::SpinThink;
    *(_QWORD *)&dataDesc_118[32].td = 0;
    *(_QWORD *)&dataDesc_118[32].override_field = 0;
    *(_QWORD *)&dataDesc_118[32].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_118[32].flatOffset[1] = 0;
    dataDesc_118[33].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_123, pszIdentifier: "UpdateViewThink");
    dataDesc_118[33].fieldSize = 1;
    dataDesc_118[33].fieldName = Name;
    dataDesc_118[33].fieldOffset = 0;
    dataDesc_118[33].flags = 32;
    dataDesc_118[33].externalName = nullptr;
    dataDesc_118[33].pSaveRestoreOps = nullptr;
    dataDesc_118[33].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCommentaryNode::UpdateViewThink;
    *(_QWORD *)&dataDesc_118[33].td = 0;
    *(_QWORD *)&dataDesc_118[33].override_field = 0;
    *(_QWORD *)&dataDesc_118[33].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_118[33].flatOffset[1] = 0;
    dataDesc_118[34].fieldType = FIELD_VOID;
    dataDesc_118[34].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_123,
                                   pszIdentifier: "UpdateViewPostThink");
    dataDesc_118[34].fieldOffset = 0;
    *(_DWORD *)&dataDesc_118[34].fieldSize = 2097153;
    dataDesc_118[34].externalName = nullptr;
    dataDesc_118[34].pSaveRestoreOps = nullptr;
    dataDesc_118[34].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCommentaryNode::UpdateViewPostThink;
    *(_QWORD *)&dataDesc_118[34].td = 0;
    *(_QWORD *)&dataDesc_118[34].override_field = 0;
    *(_QWORD *)&dataDesc_118[34].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_118[34].flatOffset[1] = 0;
  }
  CPointCommentaryNode::m_DataMap.dataNumFields = 34;
  CPointCommentaryNode::m_DataMap.dataDesc = &dataDesc_118[1];
  return &CPointCommentaryNode::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10401510
// Name: _dynamic_initializer_for__g_CPointCommentaryNode_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPointCommentaryNode_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPointCommentaryNode_ClassReg,
           pNetworkName: "CPointCommentaryNode",
           pTable: &DT_PointCommentaryNode::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A5E0
// Name: _ServerClassInit_DT_PointCommentaryNode::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PointCommentaryNode::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_37;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A640
// Name: _DataMapInit_CPointCommentaryNode__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointCommentaryNode__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_123);
}

//------------------------------------------------------------------------------
// Address: 0x1041A650
// Name: _dynamic_atexit_destructor_for__g_CommentarySystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CommentarySystem__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CommentarySystem.m_hSpawnedEntities);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CommentarySystem.m_ModifiedConvars);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_CommentarySystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041A670
// Name: _DataMapInit_CCommentarySystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCommentarySystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_120);
}

//------------------------------------------------------------------------------
// Address: 0x1041A680
// Name: _DataMapInit_modifiedconvars_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_modifiedconvars_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_121);
}

//------------------------------------------------------------------------------
// Address: 0x1041A690
// Name: _DataMapInit_CCommentaryAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCommentaryAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_122);
}

//------------------------------------------------------------------------------
// Address: 0x1041A6A0
// Name: _DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_124);
}

//------------------------------------------------------------------------------
// Address: 0x1041A6B0
// Name: _DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_125);
}

//------------------------------------------------------------------------------
// Address: 0x1041A6C0
// Name: _DataMapInit_CTargetCDAudioRep__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTargetCDAudioRep__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_126);
}

//------------------------------------------------------------------------------
// Address: 0x1041A6D0
// Name: _DataMapInit_CTargetChangeGravity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTargetChangeGravity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_127);
}

//------------------------------------------------------------------------------
// Address: 0x1041A6E0
// Name: _dynamic_atexit_destructor_for__ai_debug_ragdoll_magnets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_ragdoll_magnets__()
{
  ConVar::~ConVar(this: &ai_debug_ragdoll_magnets);
}

//------------------------------------------------------------------------------
// Address: 0x1041A6F0
// Name: _DataMapInit_CRagdollMagnet__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRagdollMagnet__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_128);
}
