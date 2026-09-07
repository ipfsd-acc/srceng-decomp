// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_initutils.cpp
// Functions: 13
// ============================================================

#include "game\server\ai_initutils.h"

//------------------------------------------------------------------------------
// Address: 0x10057280
// Name: public: virtual void CAI_TestHull::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_TestHull::Precache(CAI_TestHull *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CAI_BaseNPC::Precache(this);
  CBaseEntity::PrecacheModel(a1: a2, name: "models/player/ct_urban.mdl", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x100572A0
// Name: public: virtual bool CAI_TestHull::IsJumpLegal(class Vector const __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_TestHull::IsJumpLegal(
        CAI_TestHull *this,
        const Vector *startPos,
        const Vector *apex,
        const Vector *endPos)
{
  return CAI_BaseNPC::IsJumpLegal(this, startPos, apex, endPos, maxUp: 1024.0, maxDown: 1024.0, maxDist: 1024.0);
}

//------------------------------------------------------------------------------
// Address: 0x100572E0
// Name: public: virtual int CAI_TestHull::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_TestHull::ObjectCaps(CAI_TestHull *this)
{
  return CBaseEntity::ObjectCaps(this) & 0x7FFFFD7F | 0x200;
}

//------------------------------------------------------------------------------
// Address: 0x10057340
// Name: public: virtual struct datamap_t __near * CNodeEnt::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CNodeEnt::GetDataDescMap(CNodeEnt *this)
{
  return &CNodeEnt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100573D0
// Name: public: static class CAI_TestHull __near * CAI_TestHull::GetTestHull(void)
// Source: json
//------------------------------------------------------------------------------
CAI_TestHull *__cdecl CAI_TestHull::GetTestHull()
{
  CBaseEntity *EntityByName; // eax
  CAI_TestHull *v1; // esi

  if ( CAI_TestHull::pTestHull == nullptr )
  {
    EntityByName = CreateEntityByName(className: "aitesthull", iForceEdictIndex: -1, bNotify: true);
    v1 = (CAI_TestHull *)__RTDynamicCast(
                           inptr: EntityByName,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CAI_TestHull `RTTI Type Descriptor',
                           isReference: 0);
    if ( v1 == nullptr )
      _Warning(a1: "classname %s used to create wrong class type\n", "aitesthull");
    CAI_TestHull::pTestHull = v1;
    v1->Spawn(this: v1);
    CBaseEntity::AddFlag(this: CAI_TestHull::pTestHull, flags: 0x4000);
  }
  if ( CAI_TestHull::pTestHull->bInUse )
    DevMsg(a1: "WARNING: TestHull used and never returned!\n");
  CCollisionProperty::SetSolidFlags(
    this: &CAI_TestHull::pTestHull->m_Collision,
    flags: CAI_TestHull::pTestHull->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
  CAI_TestHull::pTestHull->bInUse = true;
  return CAI_TestHull::pTestHull;
}

//------------------------------------------------------------------------------
// Address: 0x10057490
// Name: public: static void CAI_TestHull::ReturnTestHull(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CAI_TestHull::ReturnTestHull()
{
  CAI_TestHull::pTestHull->bInUse = false;
  CCollisionProperty::SetSolidFlags(
    this: &CAI_TestHull::pTestHull->m_Collision,
    flags: CAI_TestHull::pTestHull->m_Collision.m_usSolidFlags.m_Value | 4);
  UTIL_SetSize(pEnt: CAI_TestHull::pTestHull, vecMin: &vec3_origin, vecMax: &vec3_origin);
  UTIL_RemoveImmediate(oldObj: CAI_TestHull::pTestHull);
  CAI_TestHull::pTestHull = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100574F0
// Name: public: virtual void CNodeEnt::SetOwnerEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodeEnt::SetOwnerEntity(CNodeEnt *this, CBaseEntity *pOwner)
{
  CBaseEntity::SetOwnerEntity(this, pOwner: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10057520
// Name: public: virtual void CAI_TestHull::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_TestHull::Spawn(CAI_TestHull *this)
{
  this->Precache(this);
  this->SetModel(this, a2: "models/player/ct_urban.mdl");
  this->m_eHull = HULL_HUMAN;
  CAI_BaseNPC::SetHullSizeNormal(this, force: false);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_STEP, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_iHealth.m_Value != 50 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 50;
  }
  this->bInUse = false;
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10057610
// Name: public: int CNodeEnt::Spawn(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNodeEnt::Spawn(CNodeEnt *this, char *pMapData)
{
  HintNodeData *p_m_NodeData; // edi
  bool v4; // zf
  CAI_Hint *v6; // ebx
  CAI_Hint *Hint; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // ebx
  int m_Value; // eax
  int v10; // edi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v11; // eax
  CBaseEdict *v12; // ecx
  CAI_Node *v13; // eax
  CAI_Node *v14; // edi
  int *m_pNodeIndexTable; // eax
  CAI_NetworkEditTools *m_pEditOps; // eax
  int nWCNodeID; // ecx
  Vector *m_pWCPosition; // ecx
  float *p_x; // eax
  int v20; // eax
  int savedregs; // [esp+20h] [ebp+0h] BYREF
  CAI_Hint *pHint; // [esp+28h] [ebp+8h]

  p_m_NodeData = &this->m_NodeData;
  this->m_NodeData.strEntityName.pszValue = this->m_iName.m_Value.pszValue;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  this->m_NodeData.vecPosition.x = this->m_vecAbsOrigin.x;
  this->m_NodeData.vecPosition.y = this->m_vecAbsOrigin.y;
  this->m_NodeData.vecPosition.z = this->m_vecAbsOrigin.z;
  v4 = this->m_NodeData.minState == NPC_STATE_NONE;
  this->m_NodeData.nNodeID = -1;
  if ( v4 )
    this->m_NodeData.minState = NPC_STATE_IDLE;
  if ( this->m_NodeData.maxState == NPC_STATE_NONE )
    this->m_NodeData.maxState = NPC_STATE_COMBAT;
  if ( this->m_iClassname.pszValue == "info_hint"
    || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "info_hint") != 0 )
  {
    if ( this->m_NodeData.nHintType != 0 )
      CAI_HintManager::CreateHint(pNodeData: p_m_NodeData, pMapData);
    else
      _Warning(
        a1: "info_hint (HammerID: %d, position (%.2f, %.2f, %.2f)) with no hint type.\n",
        this->m_NodeData.nWCNodeID,
        this->m_NodeData.vecPosition.x,
        this->m_NodeData.vecPosition.y,
        this->m_NodeData.vecPosition.z);
    UTIL_RemoveImmediate(oldObj: this);
    return -1;
  }
  else
  {
    v6 = nullptr;
    if ( (this->m_iClassname.pszValue == "info_node_hint"
       || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "info_node_hint") != 0
       || this->m_iClassname.pszValue == "info_node_air_hint"
       || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "info_node_air_hint") != 0)
      && (this->m_NodeData.nHintType != 0
       || this->m_NodeData.strGroup.pszValue != nullptr
       || p_m_NodeData->strEntityName.pszValue != nullptr) )
    {
      this->m_NodeData.nNodeID = CNodeEnt::m_nNodeCount;
      Hint = CAI_HintManager::CreateHint(pNodeData: p_m_NodeData, pMapData);
      p_m_spawnflags = &Hint->m_spawnflags;
      pHint = Hint;
      m_Value = Hint->m_spawnflags.m_Value;
      v10 = m_Value | this->m_spawnflags.m_Value;
      if ( m_Value != v10 )
      {
        v11 = p_m_spawnflags - 190;
        if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
        {
          LOBYTE(v11[22].m_Value) |= 1u;
        }
        else
        {
          v12 = (CBaseEdict *)v11[6].m_Value;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: v12, offset: 0x2F8u);
        }
        p_m_spawnflags->m_Value = v10;
      }
      v6 = pHint;
    }
    if ( !CAI_NetworkManager::gm_fNetworksLoaded || engine->IsInEditMode(this: engine) != 0 )
    {
      ++CNodeEnt::m_nNodeCount;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v14 = CAI_Network::AddNode(this: g_pBigAINet, origin: &this->m_vecAbsOrigin, yaw: this->m_angAbsRotation.y);
      v14->m_pHint = v6;
      m_pNodeIndexTable = g_pAINetworkManager->m_pEditOps->m_pNodeIndexTable;
      if ( m_pNodeIndexTable != nullptr )
        m_pNodeIndexTable[v14->m_iID] = this->m_NodeData.nWCNodeID;
      m_pEditOps = g_pAINetworkManager->m_pEditOps;
      nWCNodeID = this->m_NodeData.nWCNodeID;
      if ( m_pEditOps->m_nNextWCIndex <= nWCNodeID )
        m_pEditOps->m_nNextWCIndex = nWCNodeID + 1;
      if ( engine->IsInEditMode(this: engine) != 0 )
      {
        m_pWCPosition = g_pAINetworkManager->m_pEditOps->m_pWCPosition;
        if ( m_pWCPosition != nullptr )
        {
          p_x = &m_pWCPosition[v14->m_iID].x;
          *p_x = v14->m_vOrigin.x;
          p_x[1] = v14->m_vOrigin.y;
          p_x[2] = v14->m_vOrigin.z;
        }
      }
      if ( this->m_iClassname.pszValue == "info_node_air"
        || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "info_node_air") != 0
        || this->m_iClassname.pszValue == "info_node_air_hint"
        || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "info_node_air_hint") != 0 )
      {
        v14->m_eNodeType = NODE_AIR;
      }
      else if ( this->m_iClassname.pszValue == "info_node_climb"
             || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "info_node_climb") != 0 )
      {
        v14->m_eNodeType = NODE_CLIMB;
      }
      else
      {
        v14->m_eNodeType = NODE_GROUND;
      }
      v20 = 32 * this->m_spawnflags.m_Value;
      v14->m_eNodeInfo = v20;
      if ( (v20 & 0x4000) != 0 )
        v14->m_eNodeInfo = v20 | 0x8000000;
      if ( (this->m_debugOverlays & 0x1000000) != 0 )
      {
        CAI_NetworkEditTools::SetRebuildFlags(this: g_pAINetworkManager->m_pEditOps);
        v14->m_eNodeInfo |= 0x20000000u;
        CAI_NetworkBuilder::InitNodePosition(this: &g_AINetworkBuilder, pNetwork: g_pBigAINet, pNode: v14);
      }
      UTIL_RemoveImmediate(oldObj: this);
      return -1;
    }
    else
    {
      if ( v6 != nullptr )
      {
        if ( CNodeEnt::m_nNodeCount < 0 || CNodeEnt::m_nNodeCount >= g_pBigAINet->m_iNumNodes )
        {
          ++`CAI_Network::GetNode'::`8'::warningCount;
        }
        else
        {
          v13 = g_pBigAINet->m_pAInode[CNodeEnt::m_nNodeCount];
          if ( v13 != nullptr )
          {
            v13->m_pHint = v6;
            ++CNodeEnt::m_nNodeCount;
            UTIL_RemoveImmediate(oldObj: this);
            return -1;
          }
        }
        DevMsg(a1: "AI node graph corrupt\n");
      }
      ++CNodeEnt::m_nNodeCount;
      UTIL_RemoveImmediate(oldObj: this);
      return -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057AE0
// Name: public: virtual void CNodeEnt::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodeEnt::Spawn(CNodeEnt *this)
{
  CNodeEnt::Spawn(this, pMapData: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103FC750
// Name: HintNodeData_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *HintNodeData_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<HintNodeData>();
  HintNodeData_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FC760
// Name: CNodeEnt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CNodeEnt_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CNodeEnt>();
  CNodeEnt_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FC770
// Name: _dynamic_initializer_for__ai_debug_directnavprobe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_directnavprobe__()
{
  ConVar::ConVar(this: &ai_debug_directnavprobe, pName: "ai_debug_directnavprobe", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_directnavprobe__);
}
