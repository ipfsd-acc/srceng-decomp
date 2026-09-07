// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_entity_maker.cpp
// Functions: 22
// ============================================================

#include "game\server\env_entity_maker.h"

//------------------------------------------------------------------------------
// Address: 0x10113660
// Name: public: virtual struct datamap_t __near * CEnvEntityMaker::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvEntityMaker::GetDataDescMap(CEnvEntityMaker *this)
{
  return &CEnvEntityMaker::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10113670
// Name: public: virtual struct ScriptClassDesc_t __near * CEnvEntityMaker::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall CEnvEntityMaker::GetScriptDesc(CEnvEntityMaker *this)
{
  return GetScriptDesc<CEnvEntityMaker>();
}

//------------------------------------------------------------------------------
// Address: 0x10113690
// Name: public: virtual void CEnvEntityMaker::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::Spawn(CEnvEntityMaker *this)
{
  this->m_vecEntityMins = vec3_origin;
  this->m_vecEntityMaxs = vec3_origin;
  this->m_hCurrentInstance.m_Index = -1;
  this->m_hCurrentBlocker.m_Index = -1;
  this->m_vecBlockerOrigin = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x10113730
// Name: private: bool CEnvEntityMaker::IsPlayerLooking(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEnvEntityMaker::IsPlayerLooking(CEnvEntityMaker *this)
{
  int v1; // ebx
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  float *v5; // eax
  Vector v7; // [esp+Ch] [ebp-24h] BYREF
  Vector vLookDir; // [esp+18h] [ebp-18h] BYREF
  Vector vTargetDir; // [esp+24h] [ebp-Ch] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 0;
  while ( 1 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: v1);
    v4 = v3;
    if ( v3 != nullptr )
    {
      v3->EyeDirection3D(this: v3, result: &vLookDir);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v5 = (float *)v4->EyePosition(this: v4, result: &v7);
      vTargetDir.x = this->m_vecAbsOrigin.x - *v5;
      vTargetDir.y = this->m_vecAbsOrigin.y - v5[1];
      vTargetDir.z = this->m_vecAbsOrigin.z - v5[2];
      VectorNormalize(vec: &vTargetDir);
      if ( (float)((float)((float)(vTargetDir.x * vLookDir.x) + (float)(vLookDir.y * vTargetDir.y))
                 + (float)(vLookDir.z * vTargetDir.z)) > 0.0 )
        break;
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10113840
// Name: public: static bool CMemberScriptBinding1<class CBaseEntity __near *,void (CBaseEntity::*)(char const __near *),void,char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(char const *),void,char const *>::Call(
        void (__stdcall *pFunction)(const char *),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 1 || pReturn != nullptr || pContext == nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = locale;
  pFunction(a1: m_int);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101138B0
// Name: private: class CPointTemplate __near * CEnvEntityMaker::FindTemplate(void)
// Source: json
//------------------------------------------------------------------------------
CPointTemplate *__thiscall CEnvEntityMaker::FindTemplate(CEnvEntityMaker *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  void *v4; // edi
  const char *v5; // eax
  const char *v6; // esi

  pszValue = this->m_iszTemplate.pszValue;
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
  v4 = __RTDynamicCast(
         inptr: EntityByName,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CPointTemplate `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 == nullptr )
  {
    v5 = this->m_iszTemplate.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    v6 = this->m_iName.m_Value.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    _Warning(a1: "env_entity_maker %s failed to find template %s.\n", v6, v5);
  }
  return (CPointTemplate *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10113930
// Name: private: bool CEnvEntityMaker::HasRoomToSpawn(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEnvEntityMaker::HasRoomToSpawn(CEnvEntityMaker *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // edi
  unsigned int v11; // ecx
  int v12; // eax
  CEntInfo *v13; // edx
  unsigned int v14; // ecx
  int v15; // eax
  CBaseEntity **v16; // eax
  CBaseEntity *v17; // edi
  CGameTrace tr; // [esp+8h] [ebp-54h] BYREF
  IHandleEntity savedregs; // [esp+5Ch] [ebp+0h] BYREF

  m_Index = this->m_hCurrentBlocker.m_Index;
  if ( m_Index == -1 )
    goto LABEL_12;
  v3 = (unsigned __int16)m_Index;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v5 = HIWORD(m_Index);
  if ( v4->m_SerialNumber != v5 || v4->m_pEntity == nullptr )
    goto LABEL_12;
  v6 = v3;
  v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
  v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
  if ( v7 )
    v9 = *v8;
  else
    v9 = nullptr;
  if ( (v9->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
  if ( v9->m_vecAbsOrigin.x != this->m_vecBlockerOrigin.x
    || v9->m_vecAbsOrigin.y != this->m_vecBlockerOrigin.y
    || v9->m_vecAbsOrigin.z != this->m_vecBlockerOrigin.z )
  {
LABEL_12:
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      vecAbsEnd: &this->m_vecAbsOrigin,
      hullMin: &this->m_vecEntityMins,
      hullMax: &this->m_vecEntityMaxs,
      mask: 0x200400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.m_pEnt != nullptr )
    {
      this->m_hCurrentBlocker.m_Index = *(_DWORD *)((int (*)(void))tr.m_pEnt->GetRefEHandle)();
    }
    else
    {
      if ( !tr.startsolid )
        return 1;
      this->m_hCurrentBlocker.m_Index = -1;
    }
    v11 = this->m_hCurrentBlocker.m_Index;
    if ( v11 != -1 )
    {
      v12 = (unsigned __int16)v11;
      v13 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v11];
      v14 = HIWORD(v11);
      if ( v13->m_SerialNumber == v14 && v13->m_pEntity != nullptr )
      {
        v15 = v12;
        v7 = g_pEntityList->m_EntPtrArray[v15].m_SerialNumber == v14;
        v16 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v15];
        if ( v7 )
          v17 = *v16;
        else
          v17 = nullptr;
        if ( (v17->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&savedregs);
        this->m_vecBlockerOrigin.x = v17->m_vecAbsOrigin.x;
        this->m_vecBlockerOrigin.y = v17->m_vecAbsOrigin.y;
        this->m_vecBlockerOrigin.z = v17->m_vecAbsOrigin.z;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10113AE0
// Name: public: void CEnvEntityMaker::CheckSpawnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::CheckSpawnThink(CEnvEntityMaker *this)
{
  unsigned int m_Index; // eax

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  m_Index = this->m_hCurrentInstance.m_Index;
  if ( (m_Index == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
     || (this->m_spawnflags.m_Value & 2) == 0)
    && CEnvEntityMaker::HasRoomToSpawn(this) != 0
    && ((this->m_spawnflags.m_Value & 4) != 0 || CEnvEntityMaker::IsPlayerLooking(this) == 0) )
  {
    CEnvEntityMaker::SpawnEntity(this, vecAlternateOrigin: vec3_invalid, vecAlternateAngles: vec3_angle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113BE0
// Name: public: void CEnvEntityMaker::SpawnEntity(class Vector,class QAngle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::SpawnEntity(
        CEnvEntityMaker *this,
        Vector vecAlternateOrigin,
        QAngle vecAlternateAngles)
{
  CPointTemplate *Template; // ebx
  CBaseEntity *m_pEntity; // edi
  float z; // ecx
  unsigned int v7; // edx
  float v8; // eax
  unsigned int m_Index; // eax
  double v10; // st7
  CBaseEntity *p_m_vecEntityMins; // edi
  CBaseEntity *v12; // eax
  CBaseEntity *v13; // ebx
  CBaseEntity *v14; // eax
  int i; // ebx
  bool v16; // zf
  float v17; // ecx
  CBaseEntity *Parent; // eax
  const QAngle *AbsAngles; // eax
  float v20; // xmm0_4
  float m_flPostSpawnDirectionVariance; // xmm3_4
  float v22; // xmm3_4
  float v23; // xmm3_4
  float m_flPostSpawnSpeed; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // ecx
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > hNewEntities; // [esp+24h] [ebp-70h] BYREF
  Vector vUp; // [esp+38h] [ebp-5Ch] BYREF
  Vector vRight; // [esp+44h] [ebp-50h] BYREF
  Vector vForward; // [esp+50h] [ebp-44h] BYREF
  Vector vecSpawnOrigin; // [esp+5Ch] [ebp-38h] BYREF
  QAngle vecSpawnAngles; // [esp+68h] [ebp-2Ch] BYREF
  QAngle angSpawnDir; // [esp+74h] [ebp-20h] BYREF
  Vector vecShootDir; // [esp+80h] [ebp-14h] BYREF
  CPointTemplate *pTemplate; // [esp+8Ch] [ebp-8h]
  float v35; // [esp+90h] [ebp-4h]
  int savedregs; // [esp+94h] [ebp+0h] BYREF

  Template = CEnvEntityMaker::FindTemplate(this);
  m_pEntity = nullptr;
  pTemplate = Template;
  if ( Template != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    z = this->m_vecAbsOrigin.z;
    v7 = (unsigned int)this->m_iEFlags >> 11;
    *(_QWORD *)&vecSpawnOrigin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    vecSpawnOrigin.z = z;
    if ( (v7 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v8 = this->m_angAbsRotation.z;
    *(_QWORD *)&vecSpawnAngles.x = *(_QWORD *)&this->m_angAbsRotation.x;
    vecSpawnAngles.z = v8;
    if ( vec3_invalid.x != vecAlternateOrigin.x
      || vec3_invalid.y != vecAlternateOrigin.y
      || vec3_invalid.z != vecAlternateOrigin.z )
    {
      vecSpawnOrigin = vecAlternateOrigin;
      vecSpawnAngles = vecAlternateAngles;
    }
    memset(&hNewEntities, 0, sizeof(hNewEntities));
    if ( CPointTemplate::CreateInstance(
           this: Template,
           vecOrigin: &vecSpawnOrigin,
           vecAngles: &vecSpawnAngles,
           pEntities: &hNewEntities,
           pEntityMaker: this,
           bCreateTime: false) != 0
      && hNewEntities.m_Size != 0 )
    {
      if ( *hNewEntities.m_Memory.m_pMemory != nullptr )
        this->m_hCurrentInstance.m_Index = *(_DWORD *)(*(int (__thiscall **)(CBaseEntity *))(**(_DWORD **)hNewEntities.m_Memory.m_pMemory
                                                                                           + 8))(a1: *hNewEntities.m_Memory.m_pMemory);
      else
        this->m_hCurrentInstance.m_Index = -1;
      m_Index = this->m_hCurrentInstance.m_Index;
      this->m_hCurrentBlocker.m_Index = m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
      this->m_vecBlockerOrigin.x = m_pEntity->m_vecAbsOrigin.x;
      this->m_vecBlockerOrigin.y = m_pEntity->m_vecAbsOrigin.y;
      v10 = m_pEntity->m_vecAbsOrigin.z;
      p_m_vecEntityMins = (CBaseEntity *)&this->m_vecEntityMins;
      this->m_vecBlockerOrigin.z = v10;
      if ( vec3_origin.x == this->m_vecEntityMins.x
        && vec3_origin.y == this->m_vecEntityMins.y
        && vec3_origin.z == this->m_vecEntityMins.z )
      {
        v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hCurrentInstance);
        CCollisionProperty::CollisionAABBToWorldAABB(
          this: &v12->m_Collision,
          entityMins: &v12->m_Collision.m_vecMins.m_Value,
          entityMaxs: &v12->m_Collision.m_vecMaxs.m_Value,
          pWorldMins: &this->m_vecEntityMins,
          pWorldMaxs: &this->m_vecEntityMaxs);
        v13 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hCurrentInstance);
        if ( (v13->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
        *(float *)&p_m_vecEntityMins->__vftable = *(float *)&p_m_vecEntityMins->__vftable - v13->m_vecAbsOrigin.x;
        this->m_vecEntityMins.y = this->m_vecEntityMins.y - v13->m_vecAbsOrigin.y;
        this->m_vecEntityMins.z = this->m_vecEntityMins.z - v13->m_vecAbsOrigin.z;
        v14 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hCurrentInstance);
        p_m_vecEntityMins = v14;
        if ( (v14->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v14, a2: (int)&savedregs);
        this->m_vecEntityMaxs.x = this->m_vecEntityMaxs.x - p_m_vecEntityMins->m_vecAbsOrigin.x;
        this->m_vecEntityMaxs.y = this->m_vecEntityMaxs.y - p_m_vecEntityMins->m_vecAbsOrigin.y;
        this->m_vecEntityMaxs.z = this->m_vecEntityMaxs.z - p_m_vecEntityMins->m_vecAbsOrigin.z;
      }
      COutputEvent::FireOutput(this: &this->m_pOutputOnSpawned, pActivator: this, pCaller: this, fDelay: 0.0);
      if ( (this->m_spawnflags.m_Value & 1) != 0 )
      {
        CBaseEntity::ThinkSet(
          this,
          func: (void (__thiscall *)(CBaseEntity *))CEnvEntityMaker::CheckSpawnThink,
          thinkTime: 0.0,
          szContext: nullptr);
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
      }
      if ( this->m_flPostSpawnSpeed != 0.0 )
      {
        for ( i = 0; i < hNewEntities.m_Size; ++i )
        {
          p_m_vecEntityMins = hNewEntities.m_Memory.m_pMemory[i];
          if ( p_m_vecEntityMins->m_MoveType.m_Value != 0 )
          {
            v16 = !this->m_bPostSpawnUseAngles;
            v17 = this->m_angPostSpawnDirection.z;
            *(_QWORD *)&angSpawnDir.x = *(_QWORD *)&this->m_angPostSpawnDirection.x;
            angSpawnDir.z = v17;
            if ( !v16 )
            {
              if ( CBaseEntity::GetParent(this) != nullptr )
              {
                Parent = CBaseEntity::GetParent(this);
                AbsAngles = CBaseEntity::GetAbsAngles(this: Parent);
                v20 = angSpawnDir.x + AbsAngles->x;
              }
              else
              {
                AbsAngles = CBaseEntity::GetAbsAngles(this);
                v20 = AbsAngles->x + angSpawnDir.x;
              }
              angSpawnDir.x = v20;
              angSpawnDir.y = AbsAngles->y + angSpawnDir.y;
              angSpawnDir.z = AbsAngles->z + angSpawnDir.z;
            }
            AngleVectors(angles: &angSpawnDir, forward: &vForward, right: &vRight, up: &vUp);
            vecShootDir = vForward;
            v35 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1082130432,
                    a3: 1065353216);
            m_flPostSpawnDirectionVariance = this->m_flPostSpawnDirectionVariance;
            vecShootDir.x = (float)((float)(vRight.x * v35) * m_flPostSpawnDirectionVariance) + vecShootDir.x;
            vecShootDir.y = vecShootDir.y + (float)((float)(vRight.y * v35) * m_flPostSpawnDirectionVariance);
            vecShootDir.z = vecShootDir.z + (float)((float)(vRight.z * v35) * m_flPostSpawnDirectionVariance);
            v35 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1082130432,
                    a3: 1065353216);
            v22 = this->m_flPostSpawnDirectionVariance;
            vecShootDir.x = (float)((float)(vForward.x * v35) * v22) + vecShootDir.x;
            vecShootDir.y = (float)((float)(vForward.y * v35) * v22) + vecShootDir.y;
            vecShootDir.z = (float)((float)(vForward.z * v35) * v22) + vecShootDir.z;
            v35 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1082130432,
                    a3: 1065353216);
            v23 = this->m_flPostSpawnDirectionVariance;
            vecShootDir.x = (float)((float)(vUp.x * v35) * v23) + vecShootDir.x;
            vecShootDir.y = (float)((float)(vUp.y * v35) * v23) + vecShootDir.y;
            vecShootDir.z = (float)((float)(vUp.z * v35) * v23) + vecShootDir.z;
            VectorNormalize(vec: &vecShootDir);
            m_flPostSpawnSpeed = this->m_flPostSpawnSpeed;
            vecShootDir.x = m_flPostSpawnSpeed * vecShootDir.x;
            vecShootDir.y = vecShootDir.y * m_flPostSpawnSpeed;
            vecShootDir.z = vecShootDir.z * m_flPostSpawnSpeed;
            m_pPhysicsObject = p_m_vecEntityMins->m_pPhysicsObject;
            if ( m_pPhysicsObject != nullptr )
              m_pPhysicsObject->AddVelocity(this: m_pPhysicsObject, a2: &vecShootDir, a3: nullptr);
            else
              CBaseEntity::SetAbsVelocity(this: p_m_vecEntityMins, vecAbsVelocity: &vecShootDir);
          }
        }
      }
      CPointTemplate::CreationComplete(this: pTemplate, a2: (int)p_m_vecEntityMins, entities: &hNewEntities);
    }
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hNewEntities);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114200
// Name: public: void CEnvEntityMaker::SpawnEntityFromScript(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::SpawnEntityFromScript(CEnvEntityMaker *this)
{
  CEnvEntityMaker::SpawnEntity(this, vecAlternateOrigin: vec3_invalid, vecAlternateAngles: vec3_angle);
}

//------------------------------------------------------------------------------
// Address: 0x10114240
// Name: public: void CEnvEntityMaker::SpawnEntityAtEntityOriginFromScript(struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::SpawnEntityAtEntityOriginFromScript(CEnvEntityMaker *this, HSCRIPT__ *hEntity)
{
  IScriptVM_vtbl *v3; // esi
  ScriptClassDesc_t *ScriptDesc; // eax
  CBaseEntity *v5; // esi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( hEntity != nullptr )
  {
    v3 = g_pScriptVM->__vftable;
    ScriptDesc = GetScriptDesc();
    v5 = (CBaseEntity *)v3->GetInstanceValue(this: g_pScriptVM, a2: hEntity, a3: ScriptDesc);
    if ( v5 != nullptr )
    {
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
      CEnvEntityMaker::SpawnEntity(
        this,
        vecAlternateOrigin: v5->m_vecAbsOrigin,
        vecAlternateAngles: v5->m_angAbsRotation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101142F0
// Name: public: void CEnvEntityMaker::SpawnEntityAtNamedEntityOriginFromScript(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::SpawnEntityAtNamedEntityOriginFromScript(CEnvEntityMaker *this, const char *pszName)
{
  CBasePlayer *EntityByName; // eax
  CBaseEntity *v4; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszName,
                   pSearchingEntity: this,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v4 = EntityByName;
  if ( EntityByName != nullptr )
  {
    if ( (EntityByName->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
    CEnvEntityMaker::SpawnEntity(this, vecAlternateOrigin: v4->m_vecAbsOrigin, vecAlternateAngles: v4->m_angAbsRotation);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114380
// Name: public: void CEnvEntityMaker::SpawnEntityAtLocationFromScript(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::SpawnEntityAtLocationFromScript(
        CEnvEntityMaker *this,
        const Vector *vecAlternateOrigin,
        QAngle *vecAlternateAngles)
{
  CEnvEntityMaker::SpawnEntity(this, vecAlternateOrigin: *vecAlternateOrigin, vecAlternateAngles: *vecAlternateAngles);
}

//------------------------------------------------------------------------------
// Address: 0x101143C0
// Name: public: void CEnvEntityMaker::InputForceSpawn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::InputForceSpawn(CEnvEntityMaker *this, inputdata_t *inputdata)
{
  if ( CEnvEntityMaker::FindTemplate(this) != nullptr )
  {
    if ( (this->m_spawnflags.m_Value & 8) != 0 && CEnvEntityMaker::HasRoomToSpawn(this) == 0
      || (this->m_spawnflags.m_Value & 0x10) != 0 && CEnvEntityMaker::IsPlayerLooking(this) != 0 )
    {
      COutputEvent::FireOutput(this: &this->m_pOutputOnFailedSpawn, pActivator: this, pCaller: this, fDelay: 0.0);
    }
    else
    {
      CEnvEntityMaker::SpawnEntity(this, vecAlternateOrigin: vec3_invalid, vecAlternateAngles: vec3_angle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114460
// Name: public: void CEnvEntityMaker::InputForceSpawnAtEntityOrigin(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::InputForceSpawnAtEntityOrigin(CEnvEntityMaker *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  CBasePlayer *EntityByName; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: iVal,
                   pSearchingEntity: this,
                   pActivator: inputdata->pActivator,
                   pCaller: inputdata->pCaller,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
  {
    if ( (EntityByName->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
    if ( (EntityByName->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
    CEnvEntityMaker::SpawnEntity(
      this,
      vecAlternateOrigin: EntityByName->m_vecAbsOrigin,
      vecAlternateAngles: EntityByName->m_angAbsRotation);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101145A0
// Name: public: virtual void CEnvEntityMaker::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvEntityMaker::Activate(CEnvEntityMaker *this)
{
  const char *pszValue; // eax

  CBaseEntity::Activate(this);
  if ( this->m_iszTemplate.pszValue != nullptr )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
      CEnvEntityMaker::SpawnEntity(this, vecAlternateOrigin: vec3_invalid, vecAlternateAngles: vec3_angle);
  }
  else
  {
    pszValue = this->m_iName.m_Value.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _Warning(a1: "env_entity_maker %s has no template entity!\n", pszValue);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114A60
// Name: void InitCEnvEntityMakerScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCEnvEntityMakerScriptDesc()
{
  ScriptFunctionBinding_t *v0; // eax
  ScriptFunctionBinding_t *v1; // esi
  ScriptFunctionBinding_t *v2; // esi
  ScriptFunctionBinding_t *v3; // esi

  if ( !bInitialized_2 )
  {
    bInitialized_2 = true;
    g_CEnvEntityMaker_ScriptDesc.m_pszDescription = "env_entity_maker";
    g_CEnvEntityMaker_ScriptDesc.m_pszScriptName = "CEnvEntityMaker";
    g_CEnvEntityMaker_ScriptDesc.m_pszClassname = "CEnvEntityMaker";
    g_CEnvEntityMaker_ScriptDesc.m_pBaseDesc = GetScriptDesc();
    g_CEnvEntityMaker_ScriptDesc.pHelper = GetScriptInstanceHelper_CBaseEntity();
    v0 = &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                               this: &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings,
                                                                               elem: g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = "Create an entity at the location of the maker";
    v0->m_desc.m_pszScriptName = "SpawnEntity";
    v0->m_desc.m_pszFunction = "SpawnEntityFromScript";
    v0->m_desc.m_ReturnType = 0;
    v0->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding0<CEnvEntityMaker *,void (__thiscall CEnvEntityMaker::*)(void),void>::Call;
    v0->m_pFunction = CEnvEntityMaker::SpawnEntityFromScript;
    v0->m_flags = 1;
    v1 = &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                               this: &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings,
                                                                               elem: g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "Create an entity at the location of a specified entity instance";
    v1->m_desc.m_pszScriptName = "SpawnEntityAtEntityOrigin";
    v1->m_desc.m_pszFunction = "SpawnEntityAtEntityOriginFromScript";
    ScriptDeduceFunctionSignature<CBaseEntity *,CBaseEntity,void,HSCRIPT__ *>(pDesc: &v1->m_desc);
    v1->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(HSCRIPT__ *),void,HSCRIPT__ *>::Call;
    v1->m_pFunction = CEnvEntityMaker::SpawnEntityAtEntityOriginFromScript;
    v1->m_flags = 1;
    v2 = &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                               this: &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings,
                                                                               elem: g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings.m_Size)];
    v2->m_desc.m_pszDescription = "Create an entity at the location of a named entity";
    v2->m_desc.m_pszScriptName = "SpawnEntityAtNamedEntityOrigin";
    v2->m_desc.m_pszFunction = "SpawnEntityAtNamedEntityOriginFromScript";
    ScriptDeduceFunctionSignature<void,char const *>(pDesc: &v2->m_desc);
    v2->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding1<CBaseEntity *,void (__thiscall CBaseEntity::*)(char const *),void,char const *>::Call;
    v2->m_pFunction = CEnvEntityMaker::SpawnEntityAtNamedEntityOriginFromScript;
    v2->m_flags = 1;
    v3 = &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                               this: &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings,
                                                                               elem: g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings.m_Size)];
    v3->m_desc.m_pszDescription = "Create an entity at a specified location and orientaton, orientation is Euler angle in"
                                  " degrees (pitch, yaw, roll)";
    v3->m_desc.m_pszScriptName = "SpawnEntityAtLocation";
    v3->m_desc.m_pszFunction = "SpawnEntityAtLocationFromScript";
    ScriptDeduceFunctionSignature<CEnvEntityMaker *,CEnvEntityMaker,void,Vector const &,Vector const &>(pDesc: &v3->m_desc);
    v3->m_pfnBinding = (bool (__cdecl *)(void *, void *, ScriptVariant_t *, int, ScriptVariant_t *))CMemberScriptBinding2<CBaseEntity *,void (__thiscall CBaseEntity::*)(Vector const &,Vector const &),void,Vector const &,Vector const &>::Call;
    v3->m_pFunction = CEnvEntityMaker::SpawnEntityAtLocationFromScript;
    v3->m_flags = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402770
// Name: CEnvEntityMaker_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvEntityMaker_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvEntityMaker>();
  CEnvEntityMaker_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10114510
// Name: class CEnvEntityMaker __near * _CreateEntityTemplate<class CEnvEntityMaker>(class CEnvEntityMaker __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvEntityMaker *__cdecl _CreateEntityTemplate<CEnvEntityMaker>(CEnvEntityMaker *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3CCu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CEnvEntityMaker::`vftable';
    v3[219] = -1;
    v3[220] = -1;
    v3[231] = 0;
    v3[234] = -1;
    v3[235] = 0;
    v3[237] = 0;
    v3[240] = -1;
    v3[241] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CEnvEntityMaker *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402780
// Name: _dynamic_initializer_for__g_CEnvEntityMaker_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CEnvEntityMaker_ScriptDesc__()
{
  InitCEnvEntityMakerScriptDesc();
  g_CEnvEntityMaker_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CEnvEntityMaker_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CEnvEntityMaker_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x104027B0
// Name: _dynamic_initializer_for__env_entity_maker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_entity_maker__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvEntityMaker> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_entity_maker,
           a3: "env_entity_maker");
}

//------------------------------------------------------------------------------
// Address: 0x104027D0
// Name: _dynamic_initializer_for__env_instructor_hint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_instructor_hint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvInstructorHint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_instructor_hint,
           a3: "env_instructor_hint");
}
