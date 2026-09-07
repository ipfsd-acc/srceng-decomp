// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/scriptedtarget.cpp
// Functions: 18
// ============================================================

#include "game\server\scriptedtarget.h"

//------------------------------------------------------------------------------
// Address: 0x101551C0
// Name: public: virtual int CScriptedTarget::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CScriptedTarget::ObjectCaps(CAI_GoalEntity *this)
{
  return CBaseEntity::ObjectCaps(this) & 0xFFFFFD7F | 0x200;
}

//------------------------------------------------------------------------------
// Address: 0x102108A0
// Name: public: virtual struct datamap_t __near * CScriptedTarget::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CScriptedTarget::GetDataDescMap(CScriptedTarget *this)
{
  return &CScriptedTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102108B0
// Name: public: void CScriptedTarget::TurnOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedTarget::TurnOff(CScriptedTarget *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // ecx
  int v10; // eax

  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->m_iDisabled = 1;
  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      v10 = (int)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity);
      if ( g_interactionScriptedTarget > 0 )
        (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v10 + 988))(
          a1: v10,
          a2: g_interactionScriptedTarget,
          a3: 0,
          a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210940
// Name: public: virtual int CScriptedTarget::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptedTarget::DrawDebugTextOverlays(CScriptedTarget *this)
{
  int result; // eax
  int v3; // edi
  int v4; // edi
  CBaseEntity *NextTarget; // eax
  const char *DebugName; // eax
  unsigned int m_Index; // ecx
  int v8; // edi
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  int v12; // eax
  bool v13; // zf
  CBaseEntity **v14; // eax
  CBaseEntity *v15; // eax
  const char *v16; // eax
  char tempstr[512]; // [esp+20h] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    if ( this->m_iDisabled != 0 )
      V_strncpy(pDest: tempstr, pSrc: "State: Off", maxLen: 512);
    else
      V_strncpy(pDest: tempstr, pSrc: "State: On", maxLen: 512);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    NextTarget = CBaseEntity::GetNextTarget(this);
    if ( NextTarget != nullptr )
    {
      DebugName = CBaseEntity::GetDebugName(this: NextTarget);
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Next: %s", DebugName);
    }
    else
    {
      V_strncpy(pDest: tempstr, pSrc: "Next: -NONE-", maxLen: 512);
    }
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    m_Index = this->m_hTargetEnt.m_Index;
    v8 = v4 + 1;
    if ( m_Index != -1
      && (v9 = (unsigned __int16)m_Index,
          v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v11 = HIWORD(m_Index),
          v10->m_SerialNumber == v11)
      && v10->m_pEntity != nullptr )
    {
      v12 = v9;
      v13 = g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == v11;
      v14 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v12];
      if ( v13 )
        v15 = *v14;
      else
        v15 = nullptr;
      v16 = CBaseEntity::GetDebugName(this: v15);
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "User: %s", v16);
    }
    else if ( this->m_iDisabled != 0 )
    {
      V_strncpy(pDest: tempstr, pSrc: "User: -NONE-", maxLen: 512);
    }
    else
    {
      V_strncpy(pDest: tempstr, pSrc: "User: -LOOKING-", maxLen: 512);
    }
    CBaseEntity::EntityText(this, text_offset: v8, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v8 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10210B00
// Name: public: virtual void CScriptedTarget::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptedTarget::DrawDebugGeometryOverlays(CScriptedTarget *this)
{
  unsigned int v2; // eax
  Vector *p_m_vecAbsOrigin; // edi
  unsigned int v4; // edx
  CBaseEntity *NextTarget; // ebx
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *m_pEntity; // ebx
  const Vector *v14; // eax
  Vector mins; // [esp+10h] [ebp-18h] BYREF
  Vector maxs; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( (this->m_debugOverlays & 0x24) != 0 )
  {
    if ( this->m_iDisabled != 0 )
    {
      v2 = (unsigned int)this->m_iEFlags >> 11;
      maxs.x = 5.0;
      maxs.y = 5.0;
      maxs.z = 5.0;
      mins.x = -5.0;
      mins.y = -5.0;
      mins.z = -5.0;
      if ( (v2 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      p_m_vecAbsOrigin = &this->m_vecAbsOrigin;
      NDebugOverlay::Box(origin: &this->m_vecAbsOrigin, &mins, &maxs, r: 200, g: 100, b: 100, a: 0, flDuration: 0.0);
    }
    else
    {
      mins.x = 8.0;
      mins.y = 8.0;
      mins.z = 8.0;
      maxs.x = -8.0;
      maxs.y = -8.0;
      maxs.z = -8.0;
      NDebugOverlay::Cross3D(
        position: &this->m_vLastPosition,
        mins: &maxs,
        maxs: &mins,
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: 1,
        fDuration: 0.1);
      v4 = (unsigned int)this->m_iEFlags >> 11;
      mins.x = 5.0;
      mins.y = 5.0;
      mins.z = 5.0;
      maxs.x = -5.0;
      maxs.y = -5.0;
      maxs.z = -5.0;
      if ( (v4 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      p_m_vecAbsOrigin = &this->m_vecAbsOrigin;
      NDebugOverlay::Box(
        origin: &this->m_vecAbsOrigin,
        mins: &maxs,
        maxs: &mins,
        r: 255,
        g: 0,
        b: 0,
        a: 0,
        flDuration: 0.0);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      NDebugOverlay::Line(
        origin: &this->m_vecAbsOrigin,
        target: &this->m_vLastPosition,
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: 1,
        duration: 0.0);
    }
    NextTarget = CBaseEntity::GetNextTarget(this);
    if ( NextTarget != nullptr )
    {
      if ( (NextTarget->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: NextTarget, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      NDebugOverlay::Line(
        origin: p_m_vecAbsOrigin,
        target: &NextTarget->m_vecAbsOrigin,
        r: 200,
        g: 100,
        b: 100,
        noDepthTest: 1,
        duration: 0.0);
    }
    m_Index = this->m_hTargetEnt.m_Index;
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
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v14 = (const Vector *)((int (__thiscall *)(IHandleEntity *, Vector *))m_pEntity->__vftable[42].dtr_IHandleEntity)(
                                a1: m_pEntity,
                                a2: &mins);
        NDebugOverlay::Line(origin: p_m_vecAbsOrigin, target: v14, r: 0, g: 255, b: 0, noDepthTest: 1, duration: 0.0);
      }
    }
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10210D90
// Name: public: void CScriptedTarget::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CScriptedTarget::InputDisable(CScriptedTarget *this, inputdata_t *inputdata)
{
  CScriptedTarget::TurnOff(this);
}

//------------------------------------------------------------------------------
// Address: 0x10210DA0
// Name: public: class CBaseEntity __near * CScriptedTarget::FindEntity(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CBasePlayer *__usercall CScriptedTarget::FindEntity@<eax>(CScriptedTarget *this@<ecx>, int a2@<ebp>)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  CBasePlayer *v5; // esi
  int v6; // eax
  unsigned int v8; // ecx
  CBaseEntity *CurrentEntity; // esi
  const char *v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  __int128 v13; // xmm0
  int v14; // eax
  _DWORD v15[3]; // [esp+10h] [ebp-834h] BYREF
  __int128 sphere_2044; // [esp+818h] [ebp-2Ch] OVERLAPPED
  unsigned __int64 v17; // [esp+830h] [ebp-14h]
  int v18; // [esp+838h] [ebp-Ch] BYREF
  float flNearestDist; // [esp+83Ch] [ebp-8h]
  float retaddr; // [esp+844h] [ebp+0h]

  v18 = a2;
  flNearestDist = retaddr;
  pszValue = this->m_iszEntity.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v5 = EntityByName;
  if ( EntityByName != nullptr && (EntityByName->m_fFlags.m_Value & 0x4000) != 0 )
  {
    v6 = (int)EntityByName->MyNPCPointer(this: EntityByName);
    if ( g_interactionScriptedTarget > 0
      && (*(unsigned __int8 (__thiscall **)(int, int, _DWORD, CScriptedTarget *))(*(_DWORD *)v6 + 988))(
           a1: v6,
           a2: g_interactionScriptedTarget,
           a3: 0,
           a4: this) != 0 )
    {
      return v5;
    }
  }
  v8 = (unsigned int)this->m_iEFlags >> 11;
  v17 = 1182793728;
  if ( (v8 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&v18);
  CEntitySphereQuery::CEntitySphereQuery(
    this: (CEntitySphereQuery *)v15,
    center: &this->m_vecAbsOrigin,
    radius: this->m_flRadius,
    flagMask: 0);
  CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v15);
  if ( CurrentEntity == nullptr )
    return nullptr;
  do
  {
    if ( (CurrentEntity->m_fFlags.m_Value & 0x4000) != 0 )
    {
      v10 = this->m_iszEntity.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
      if ( CurrentEntity->m_iClassname.pszValue == v10
        || CBaseEntity::ClassMatchesComplex(this: CurrentEntity, pszClassOrWildcard: v10) != 0 )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&v18);
        if ( (CurrentEntity->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: CurrentEntity, a2: (int)&v18);
        v11 = CurrentEntity->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
        v12 = (float)((float)(CurrentEntity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)
                    * (float)(CurrentEntity->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y))
            + (float)(v11 * v11);
        v13 = 0;
        *(float *)&v13 = fsqrt(
                           v12
                         + (float)((float)(CurrentEntity->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)
                                 * (float)(CurrentEntity->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)));
        sphere_2044 = v13;
        if ( *(float *)&v17 > *(float *)&v13 )
          v17 = __PAIR64__((unsigned int)CurrentEntity, sphere_2044);
      }
    }
    ++v15[0];
    CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v15);
  }
  while ( CurrentEntity != nullptr );
  v5 = (CBasePlayer *)HIDWORD(v17);
  if ( HIDWORD(v17) != 0
    && (v14 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v17) + 296))(a1: HIDWORD(v17)),
        g_interactionScriptedTarget > 0)
    && (*(unsigned __int8 (__thiscall **)(int, int, _DWORD, CScriptedTarget *))(*(_DWORD *)v14 + 988))(
         a1: v14,
         a2: g_interactionScriptedTarget,
         a3: 0,
         a4: this) != 0 )
  {
    return v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210FB0
// Name: public: void CScriptedTarget::ScriptThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CScriptedTarget::ScriptThink(CScriptedTarget *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // eax
  CBasePlayer *Entity; // eax

  m_Index = this->m_hTargetEnt.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    this->m_flPauseDoneTime = 0.0;
    Entity = CScriptedTarget::FindEntity(this, a2);
    CAI_BaseNPC::SetTarget(this, pTarget: Entity);
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10211020
// Name: public: void CScriptedTarget::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CScriptedTarget::TurnOn(CScriptedTarget *this@<ecx>, int a2@<ebp>)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  this->m_vLastPosition.x = this->m_vecAbsOrigin.x;
  this->m_vLastPosition.y = this->m_vecAbsOrigin.y;
  this->m_vLastPosition.z = this->m_vecAbsOrigin.z;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CScriptedTarget::ScriptThink,
    thinkTime: 0.0,
    szContext: nullptr);
  this->m_iDisabled = 0;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102110A0
// Name: public: virtual void CScriptedTarget::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CScriptedTarget::Spawn(CScriptedTarget *this@<ecx>, int a2@<ebp>)
{
  if ( g_interactionScriptedTarget == 0 )
    g_interactionScriptedTarget = CBaseCombatCharacter::GetInteractionID();
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  this->m_vLastPosition.x = this->m_vecAbsOrigin.x;
  this->m_vLastPosition.y = this->m_vecAbsOrigin.y;
  this->m_vLastPosition.z = this->m_vecAbsOrigin.z;
  if ( this->m_iDisabled == 0 )
    CScriptedTarget::TurnOn(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10211110
// Name: public: CScriptedTarget::CScriptedTarget(void)
// Source: json
//------------------------------------------------------------------------------
CScriptedTarget *__thiscall CScriptedTarget::CScriptedTarget(CScriptedTarget *this)
{
  CAI_BaseNPC::CAI_BaseNPC(this);
  this->CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CScriptedTarget_vtbl *)&CScriptedTarget::`vftable'{for `CBaseCombatCharacter'};
  this->CAI_BaseNPC::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CScriptedTarget::`vftable'{for `CAI_DefMovementSink'};
  this->CAI_BaseNPC::IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&CScriptedTarget::`vftable'{for `IAI_BehaviorBridge'};
  this->m_AtTarget.m_Value.iVal = 0;
  this->m_AtTarget.m_Value.eVal.m_Index = -1;
  this->m_AtTarget.m_Value.fieldType = FIELD_VOID;
  this->m_LeaveTarget.m_Value.iVal = 0;
  this->m_LeaveTarget.m_Value.eVal.m_Index = -1;
  this->m_LeaveTarget.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102111A0
// Name: public: void CScriptedTarget::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge CScriptedTarget::InputEnable(CScriptedTarget *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  CScriptedTarget::TurnOn(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x104097D0
// Name: _dynamic_initializer_for__scripted_scene__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scripted_scene__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSceneEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &scripted_scene,
           a3: "scripted_scene");
}

//------------------------------------------------------------------------------
// Address: 0x10409AC0
// Name: _dynamic_initializer_for__scripted_sequence__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scripted_sequence__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_ScriptedSequence> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &scripted_sequence,
           a3: "scripted_sequence");
}

//------------------------------------------------------------------------------
// Address: 0x10409B20
// Name: _dynamic_initializer_for__scripted_sentence__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scripted_sentence__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_ScriptedSentence> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &scripted_sentence,
           a3: "scripted_sentence");
}

//------------------------------------------------------------------------------
// Address: 0x10409B40
// Name: _dynamic_initializer_for__scripted_target__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scripted_target__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CScriptedTarget> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &scripted_target,
           a3: "scripted_target");
}

//------------------------------------------------------------------------------
// Address: 0x10409B60
// Name: CScriptedTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CScriptedTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CScriptedTarget>();
  CScriptedTarget_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104097F0
// Name: _dynamic_initializer_for__g_CSceneEntity_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSceneEntity_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSceneEntity_ClassReg,
           pNetworkName: "CSceneEntity",
           pTable: &DT_SceneEntity::g_SendTable);
}
