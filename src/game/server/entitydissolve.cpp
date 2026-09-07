// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/entitydissolve.cpp
// Functions: 18
// ============================================================

#include "game\server\entitydissolve.h"

//------------------------------------------------------------------------------
// Address: 0x1010AFB0
// Name: public: virtual struct datamap_t __near * CEntityDissolve::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEntityDissolve::GetDataDescMap(CEntityDissolve *this)
{
  return &CEntityDissolve::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010AFC0
// Name: public: virtual class ServerClass __near * CEntityDissolve::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEntityDissolve::GetServerClass(CEntityDissolve *this)
{
  return &g_CEntityDissolve_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1010B000
// Name: public: virtual void CEntityDissolve::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEntityDissolve::Precache(CEntityDissolve *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( *(_DWORD *)((int (__thiscall *)(CEntityDissolve *, _BYTE *))this->GetModelName)(a1: this, a2: v4) != 0 )
  {
    v3 = *(const char **)((int (__thiscall *)(CEntityDissolve *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
    if ( v3 == nullptr )
      v3 = locale;
    CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
  }
  else
  {
    CBaseEntity::PrecacheModel(a1: a2, name: "sprites/blueglow1.vmt", bPreload: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010B060
// Name: protected: void CEntityDissolve::InputDissolve(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDissolve::InputDissolve(CEntityDissolve *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax
  CBaseEntity *EntityGeneric; // edi
  const char *pszValue; // eax
  int v6; // ebx
  string_t strTarget; // [esp+28h] [ebp-4h] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    strTarget.pszValue = nullptr;
    p_value = (variant_t *)&strTarget;
  }
  strTarget.pszValue = (const char *)p_value->iVal;
  if ( strTarget.pszValue == nullptr )
    strTarget.pszValue = this->m_target.pszValue;
  EntityGeneric = nullptr;
  while ( 1 )
  {
    pszValue = strTarget.pszValue;
    if ( strTarget.pszValue == nullptr )
      pszValue = locale;
    EntityGeneric = CGlobalEntityList::FindEntityGeneric(
                      this: &gEntList,
                      pStartEntity: EntityGeneric,
                      szName: pszValue,
                      pSearchingEntity: this,
                      pActivator: inputdata->pActivator,
                      pCaller: nullptr);
    if ( EntityGeneric == nullptr )
      break;
    v6 = (int)EntityGeneric->GetBaseAnimating(this: EntityGeneric);
    if ( v6 != 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v6 + 904))(
        a1: v6,
        a2: 0,
        a3: LODWORD(gpGlobals->curtime),
        a4: 0,
        a5: this->m_nDissolveType.m_Value,
        a6: LODWORD(this->m_vecAbsOrigin.x),
        a7: LODWORD(this->m_vecAbsOrigin.y),
        a8: LODWORD(this->m_vecAbsOrigin.z),
        a9: this->m_nMagnitude.m_Value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010B3E0
// Name: protected: void CEntityDissolve::ElectrocuteThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDissolve::ElectrocuteThink(CEntityDissolve *this)
{
  CEntityDissolve *v1; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int *v4; // eax
  IUniformRandomStream *v5; // ecx
  int *v6; // ebx
  int v7; // esi
  _DWORD *v8; // edi
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  float thinkTime; // [esp+Ch] [ebp-24h]
  float vecForce_8; // [esp+1Ch] [ebp-14h]

  v1 = this;
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v4 = (int *)__RTDynamicCast(
                inptr: m_pEntity,
                VfDelta: 0,
                SrcType: &CBaseEntity `RTTI Type Descriptor',
                TargetType: &CRagdollProp `RTTI Type Descriptor',
                isReference: 0);
  v6 = v4;
  if ( v4 != nullptr )
  {
    v7 = 0;
    if ( v4[292] > 0 )
    {
      v8 = v4 + 298;
      do
      {
        _RandomFloat(this: v5, a2: -2400.0, a3: 2400.0);
        _RandomFloat(this: v9, a2: -2400.0, a3: 2400.0);
        vecForce_8 = _RandomFloat(this: v10, a2: -2400.0, a3: 2400.0);
        (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*v8 + 240))(a1: *v8, a2: LODWORD(vecForce_8));
        ++v7;
        v8 += 6;
      }
      while ( v7 < v6[292] );
      v1 = this;
    }
    thinkTime = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random) + gpGlobals->curtime;
    CBaseEntity::ThinkSet(
      this: v1,
      func: (void (__thiscall *)(CBaseEntity *))CEntityDissolve::ElectrocuteThink,
      thinkTime,
      szContext: (const char *)0x3DCCCCCD);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010B550
// Name: public: CEntityDissolve::CEntityDissolve(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDissolve *__thiscall CEntityDissolve::CEntityDissolve(CEntityDissolve *this)
{
  edict_t *m_pPev; // ecx
  CEntityDissolve *result; // eax
  edict_t *v4; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CEntityDissolve_vtbl *)&CEntityDissolve::`vftable';
  if ( this->m_flStartTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
    }
    this->m_flStartTime.m_Value = 0.0;
  }
  result = this;
  if ( this->m_nMagnitude.m_Value != 250 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nMagnitude.m_Value = 250;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x380u);
      this->m_nMagnitude.m_Value = 250;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010B5F0
// Name: public: static class CEntityDissolve __near * CEntityDissolve::Create(class CBaseEntity __near *,char const __near *,float,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CEntityDissolve *__usercall CEntityDissolve::Create@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        CBasePlayer *pTarget,
        const char *pMaterialName,
        float flStartTime,
        int nDissolveType,
        bool *pRagdollCreated)
{
  CBaseEntity *v8; // edi
  CEntityDissolve *result; // eax
  CEntityDissolve *v10; // esi
  int v11; // edx
  edict_t *m_pPev; // ecx
  CAI_BaseNPC *v13; // eax
  CAI_BaseNPC *v14; // eax
  const Vector *v15; // eax
  CBasePlayer *v16; // eax
  CBaseEdict *v17; // ecx
  const Vector *v18; // [esp+10h] [ebp-C4h]
  int v19; // [esp+14h] [ebp-C0h]
  CTakeDamageInfo ragdollInfo; // [esp+1Ch] [ebp-B8h] BYREF
  CTakeDamageInfo info; // [esp+78h] [ebp-5Ch] BYREF
  CBaseEntity *pRagdoll; // [esp+DCh] [ebp+8h]

  if ( pRagdollCreated != nullptr )
    *pRagdollCreated = false;
  if ( pMaterialName == nullptr )
    pMaterialName = "sprites/blueglow1.vmt";
  v8 = pTarget;
  if ( ((unsigned __int8 (__thiscall *)(CBasePlayer *, int))pTarget->IsPlayer)(a1: pTarget, a2) != 0 )
  {
    CBasePlayer::SetArmorValue(this: pTarget, value: 0);
    CTakeDamageInfo::CTakeDamageInfo(
      this: &info,
      pInflictor: pTarget,
      pAttacker: pTarget,
      flDamage: (float)pTarget->m_iHealth.m_Value,
      bitsDamageType: 4196352,
      iKillType: 0,
      iObjectsPenetrated: 0);
    CBaseEntity::TakeDamage(this: pTarget, a2: a3, inputInfo: &info);
    return nullptr;
  }
  else
  {
    result = (CEntityDissolve *)CreateEntityByName(
                                  className: "env_entity_dissolver",
                                  iForceEdictIndex: -1,
                                  bNotify: true);
    v10 = result;
    if ( result != nullptr )
    {
      v11 = nDissolveType;
      v19 = a1;
      if ( result->m_nDissolveType.m_Value != nDissolveType )
      {
        if ( result->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&result->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = result->m_Network.m_pPev;
          if ( m_pPev != nullptr )
          {
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
            v11 = nDissolveType;
          }
        }
        v10->m_nDissolveType.m_Value = v11;
      }
      if ( (v11 == 1 || v11 == 2)
        && ((unsigned __int8 (__thiscall *)(CBasePlayer *, int))pTarget->IsNPC)(a1: pTarget, a2: a1) != 0 )
      {
        v13 = pTarget->MyNPCPointer(this: pTarget);
        if ( v13->CanBecomeRagdoll(this: v13) )
        {
          CTakeDamageInfo::CTakeDamageInfo(this: &info);
          v14 = pTarget->MyNPCPointer(this: pTarget);
          pRagdoll = CreateServerRagdoll(
                       pAnimating: v14,
                       forceBone: 0,
                       &info,
                       collisionGroup: 1,
                       bUseLRURetirement: true);
          v18 = v8->m_Collision.OBBMaxs(this: &v8->m_Collision);
          v15 = v8->m_Collision.OBBMins(this: &v8->m_Collision);
          CBaseEntity::SetCollisionBounds(this: pRagdoll, mins: v15, maxs: v18);
          if ( v8->m_lifeState.m_Value == 0 )
          {
            v16 = UTIL_PlayerByIndex(playerIndex: 1);
            CTakeDamageInfo::CTakeDamageInfo(
              this: &ragdollInfo,
              pInflictor: v16,
              pAttacker: v16,
              flDamage: 10000.0,
              bitsDamageType: 4196608,
              iKillType: 0,
              iObjectsPenetrated: 0);
            CBaseEntity::TakeDamage(this: v8, a2: (int)v10, inputInfo: &ragdollInfo);
          }
          if ( pRagdollCreated != nullptr )
            *pRagdollCreated = true;
          UTIL_Remove(oldObj: v8);
          v8 = pRagdoll;
        }
      }
      v10->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&pMaterialName).pszValue;
      CBaseEntity::DispatchUpdateTransmitState(this: v10);
      ((void (__thiscall *)(CEntityDissolve *, CBaseEntity *, int, int))v10->SetParent)(
        a1: v10,
        a2: v8,
        a3: -1,
        a4: v19);
      CBaseEntity::SetLocalOrigin(this: v10, origin: &vec3_origin);
      CBaseEntity::SetLocalAngles(this: v10, angles: &vec3_angle);
      if ( v10->m_flStartTime.m_Value != flStartTime )
      {
        if ( v10->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v10->m_Network + 76) |= 1u;
        }
        else
        {
          v17 = &v10->m_Network.m_pPev->CBaseEdict;
          if ( v17 != nullptr )
            CBaseEdict::StateChanged(this: v17, offset: 0x354u);
        }
        v10->m_flStartTime.m_Value = flStartTime;
      }
      v10->Spawn(this: v10);
      v10->m_iEFlags |= 0x80u;
      CBaseEntity::DispatchUpdateTransmitState(this: v10);
      if ( nDissolveType == 1 || nDissolveType == 2 )
      {
        ((void (__thiscall *)(CBaseEntity *, const char *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, int, int, unsigned int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, int))v8->DispatchResponse)(
          a1: v8,
          a2: "TLK_ELECTROCUTESCREAM",
          a3: LODWORD(ragdollInfo.m_vecDamageForce.x),
          a4: LODWORD(ragdollInfo.m_vecDamageForce.y),
          a5: LODWORD(ragdollInfo.m_vecDamageForce.z),
          a6: LODWORD(ragdollInfo.m_vecDamagePosition.x),
          a7: LODWORD(ragdollInfo.m_vecDamagePosition.y),
          a8: LODWORD(ragdollInfo.m_vecDamagePosition.z),
          a9: LODWORD(ragdollInfo.m_vecReportedPosition.x),
          a10: LODWORD(ragdollInfo.m_vecReportedPosition.y),
          a11: LODWORD(ragdollInfo.m_vecReportedPosition.z),
          a12: ragdollInfo.m_hInflictor.m_Index,
          a13: ragdollInfo.m_hAttacker.m_Index,
          a14: ragdollInfo.m_hWeapon.m_Index,
          a15: LODWORD(ragdollInfo.m_flDamage),
          a16: LODWORD(ragdollInfo.m_flMaxDamage),
          a17: LODWORD(ragdollInfo.m_flBaseDamage),
          a18: ragdollInfo.m_bitsDamageType,
          a19: ragdollInfo.m_iDamageCustom,
          a20: ragdollInfo.m_iDamageStats,
          a21: ragdollInfo.m_iAmmoType,
          a22: LODWORD(ragdollInfo.m_flRadius),
          a23: ragdollInfo.m_iDamagedOtherPlayers,
          a24: ragdollInfo.m_iObjectsPenetrated,
          a25: ragdollInfo.m_uiBulletID,
          a26: LODWORD(info.m_vecDamageForce.x),
          a27: LODWORD(info.m_vecDamageForce.y),
          a28: LODWORD(info.m_vecDamageForce.z),
          a29: LODWORD(info.m_vecDamagePosition.x),
          a30: LODWORD(info.m_vecDamagePosition.y),
          a31: LODWORD(info.m_vecDamagePosition.z),
          a32: LODWORD(info.m_vecReportedPosition.x),
          a33: LODWORD(info.m_vecReportedPosition.y),
          a34: LODWORD(info.m_vecReportedPosition.z),
          a35: info.m_hInflictor.m_Index,
          a36: info.m_hAttacker.m_Index,
          a37: info.m_hWeapon.m_Index,
          a38: LODWORD(info.m_flDamage),
          a39: LODWORD(info.m_flMaxDamage),
          a40: LODWORD(info.m_flBaseDamage),
          a41: info.m_bitsDamageType,
          a42: info.m_iDamageCustom,
          a43: info.m_iDamageStats,
          a44: info.m_iAmmoType,
          a45: LODWORD(info.m_flRadius),
          a46: info.m_iDamagedOtherPlayers);
        return v10;
      }
      else
      {
        ((void (__thiscall *)(CBaseEntity *, const char *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, int, int, unsigned int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, int))v8->DispatchResponse)(
          a1: v8,
          a2: "TLK_DISSOLVESCREAM",
          a3: LODWORD(ragdollInfo.m_vecDamageForce.x),
          a4: LODWORD(ragdollInfo.m_vecDamageForce.y),
          a5: LODWORD(ragdollInfo.m_vecDamageForce.z),
          a6: LODWORD(ragdollInfo.m_vecDamagePosition.x),
          a7: LODWORD(ragdollInfo.m_vecDamagePosition.y),
          a8: LODWORD(ragdollInfo.m_vecDamagePosition.z),
          a9: LODWORD(ragdollInfo.m_vecReportedPosition.x),
          a10: LODWORD(ragdollInfo.m_vecReportedPosition.y),
          a11: LODWORD(ragdollInfo.m_vecReportedPosition.z),
          a12: ragdollInfo.m_hInflictor.m_Index,
          a13: ragdollInfo.m_hAttacker.m_Index,
          a14: ragdollInfo.m_hWeapon.m_Index,
          a15: LODWORD(ragdollInfo.m_flDamage),
          a16: LODWORD(ragdollInfo.m_flMaxDamage),
          a17: LODWORD(ragdollInfo.m_flBaseDamage),
          a18: ragdollInfo.m_bitsDamageType,
          a19: ragdollInfo.m_iDamageCustom,
          a20: ragdollInfo.m_iDamageStats,
          a21: ragdollInfo.m_iAmmoType,
          a22: LODWORD(ragdollInfo.m_flRadius),
          a23: ragdollInfo.m_iDamagedOtherPlayers,
          a24: ragdollInfo.m_iObjectsPenetrated,
          a25: ragdollInfo.m_uiBulletID,
          a26: LODWORD(info.m_vecDamageForce.x),
          a27: LODWORD(info.m_vecDamageForce.y),
          a28: LODWORD(info.m_vecDamageForce.z),
          a29: LODWORD(info.m_vecDamagePosition.x),
          a30: LODWORD(info.m_vecDamagePosition.y),
          a31: LODWORD(info.m_vecDamagePosition.z),
          a32: LODWORD(info.m_vecReportedPosition.x),
          a33: LODWORD(info.m_vecReportedPosition.y),
          a34: LODWORD(info.m_vecReportedPosition.z),
          a35: info.m_hInflictor.m_Index,
          a36: info.m_hAttacker.m_Index,
          a37: info.m_hWeapon.m_Index,
          a38: LODWORD(info.m_flDamage),
          a39: LODWORD(info.m_flMaxDamage),
          a40: LODWORD(info.m_flBaseDamage),
          a41: info.m_bitsDamageType,
          a42: info.m_iDamageCustom,
          a43: info.m_iDamageStats,
          a44: info.m_iAmmoType,
          a45: LODWORD(info.m_flRadius),
          a46: info.m_iDamagedOtherPlayers);
        return v10;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010B890
// Name: public: static class CEntityDissolve __near * CEntityDissolve::Create(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CEntityDissolve *__usercall CEntityDissolve::Create@<eax>(int a1@<ebx>, CBasePlayer *pTarget, CBaseEntity *pSource)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edi
  float *v5; // esi
  IHandleEntity_vtbl *v6; // eax
  const char *v8; // eax

  m_Index = pSource->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == nullptr )
    return nullptr;
  while ( 1 )
  {
    v5 = (float *)__RTDynamicCast(
                    inptr: m_pEntity,
                    VfDelta: 0,
                    SrcType: &CBaseEntity `RTTI Type Descriptor',
                    TargetType: &CEntityDissolve `RTTI Type Descriptor',
                    isReference: 0);
    if ( v5 != nullptr )
      break;
    v6 = m_pEntity[56].__vftable;
    if ( v6 == (IHandleEntity_vtbl *)-1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != (unsigned int)v6 >> 16 )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    }
    if ( m_pEntity == nullptr )
      return nullptr;
  }
  v8 = *(const char **)(*(int (__thiscall **)(float *, CBaseEntity **))(*(_DWORD *)v5 + 28))(a1: v5, a2: &pSource);
  if ( v8 == nullptr )
    v8 = locale;
  return CEntityDissolve::Create(
           a1,
           a2: (int)m_pEntity,
           a3: (int)v5,
           pTarget,
           pMaterialName: v8,
           flStartTime: v5[213],
           nDissolveType: *((_DWORD *)v5 + 220),
           pRagdollCreated: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1010B970
// Name: protected: void CEntityDissolve::DissolveThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDissolve::DissolveThink(CEntityDissolve *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  CBaseEntity *v9; // edi
  float m_Value; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  CBasePlayer *v13; // esi
  int v14; // eax
  CTakeDamageInfo info; // [esp+20h] [ebp-60h] BYREF
  _BYTE v16[4]; // [esp+7Ch] [ebp-4h] BYREF

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && (v3 = (unsigned __int16)m_Index,
        v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v5 = HIWORD(m_Index),
        v4->m_SerialNumber == v5)
    && v4->m_pEntity != nullptr )
  {
    v6 = v3;
    v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
    v8 = &g_pEntityList->m_EntPtrArray[v6];
    if ( v7 )
      v9 = (CBaseEntity *)v8->m_pEntity->__vftable[17].GetRefEHandle(this: v8->m_pEntity);
    else
      v9 = (CBaseEntity *)(*(int (__thiscall **)(_DWORD))(MEMORY[0] + 212))(a1: 0);
  }
  else
  {
    v9 = nullptr;
  }
  if ( *(_DWORD *)((int (__thiscall *)(CEntityDissolve *, _BYTE *))this->GetModelName)(a1: this, a2: v16) != 0 )
  {
    if ( v9 == nullptr )
    {
LABEL_20:
      UTIL_Remove(oldObj: this);
      return;
    }
  }
  else if ( v9 == nullptr )
  {
    return;
  }
  CBaseEntity::SetCollisionGroup(this: v9, collisionGroup: 16);
  if ( (v9->m_fFlags.m_Value & 0x40000000) != 0 )
    CBaseEntity::SetRenderAlpha(this, a: 0);
  m_Value = this->m_flStartTime.m_Value;
  v11 = this->m_flFadeInStart.m_Value;
  v12 = gpGlobals->curtime - m_Value;
  if ( v11 > v12 )
  {
    CBaseEntity::SetNextThink(this, thinkTime: v11 + m_Value, szContext: nullptr);
    return;
  }
  if ( v12 >= (float)(this->m_flFadeOutLength.m_Value + this->m_flFadeOutStart.m_Value) )
  {
    v13 = UTIL_PlayerByIndex(playerIndex: 1);
    v14 = g_pGameRules->Damage_GetNoPhysicsForce(this: g_pGameRules);
    CTakeDamageInfo::CTakeDamageInfo(
      this: &info,
      pInflictor: v13,
      pAttacker: v13,
      flDamage: 10000.0,
      bitsDamageType: v14 | 0x400000,
      iKillType: 0,
      iObjectsPenetrated: 0);
    CBaseEntity::TakeDamage(this: v9, a2: (int)v13, inputInfo: &info);
    if ( v9 != v13 )
      UTIL_Remove(oldObj: v9);
    goto LABEL_20;
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1010BCF0
// Name: public: virtual void CEntityDissolve::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDissolve::Spawn(CEntityDissolve *this)
{
  const char *v2; // eax
  int m_Value; // eax
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  edict_t *v12; // ecx
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  edict_t *v15; // ecx
  edict_t *v16; // ecx
  edict_t *v17; // ecx
  edict_t *v18; // ecx
  edict_t *v19; // ecx
  float curtime; // xmm0_4
  _BYTE v21[8]; // [esp+18h] [ebp-8h] BYREF

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CEntityDissolve *, _BYTE *))this->GetModelName)(a1: this, a2: v21);
  if ( v2 == nullptr )
    v2 = locale;
  UTIL_SetModel(pEntity: this, pModelName: v2);
  m_Value = this->m_nDissolveType.m_Value;
  if ( m_Value == 1 || m_Value == 2 )
  {
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( __RTDynamicCast(
           inptr: m_pEntity,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CRagdollProp `RTTI Type Descriptor',
           isReference: 0) != nullptr )
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CEntityDissolve::ElectrocuteThink,
        thinkTime: gpGlobals->curtime + 0.0099999998,
        szContext: s_pElectroThinkContext);
  }
  if ( this->m_flFadeInStart.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
    }
    this->m_flFadeInStart.m_Value = 0.0;
  }
  if ( this->m_flFadeInLength.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x35Cu);
    }
    this->m_flFadeInLength.m_Value = 1.0;
  }
  if ( this->m_flFadeOutModelStart.m_Value != 1.9 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x360u);
    }
    this->m_flFadeOutModelStart.m_Value = 1.9;
  }
  if ( this->m_flFadeOutModelLength.m_Value != 0.10000002 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x364u);
    }
    this->m_flFadeOutModelLength.m_Value = 0.10000002;
  }
  if ( this->m_flFadeOutStart.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x368u);
    }
    this->m_flFadeOutStart.m_Value = 2.0;
  }
  if ( this->m_flFadeOutLength.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x36Cu);
    }
    this->m_flFadeOutLength.m_Value = 0.0;
  }
  if ( this->m_nDissolveType.m_Value == 3 )
  {
    if ( this->m_flFadeInStart.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v12 = this->m_Network.m_pPev;
        if ( v12 != nullptr )
          CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x358u);
      }
      this->m_flFadeInStart.m_Value = 0.0;
    }
    if ( this->m_flFadeOutStart.m_Value != 0.2 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v13 = this->m_Network.m_pPev;
        if ( v13 != nullptr )
          CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x368u);
      }
      this->m_flFadeOutStart.m_Value = 0.2;
    }
    if ( this->m_flFadeOutModelStart.m_Value != 0.1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v14 = this->m_Network.m_pPev;
        if ( v14 != nullptr )
          CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x360u);
      }
      this->m_flFadeOutModelStart.m_Value = 0.1;
    }
    if ( this->m_flFadeOutModelLength.m_Value != 0.050000001 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v15 = this->m_Network.m_pPev;
        if ( v15 != nullptr )
          CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x364u);
      }
      this->m_flFadeOutModelLength.m_Value = 0.050000001;
    }
    if ( this->m_flFadeInLength.m_Value != 0.1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v16 = this->m_Network.m_pPev;
        if ( v16 != nullptr )
          CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x35Cu);
      }
      this->m_flFadeInLength.m_Value = 0.1;
    }
  }
  if ( this->m_nRenderMode.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v17 = this->m_Network.m_pPev;
      if ( v17 != nullptr )
        CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 1;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v18 = this->m_Network.m_pPev;
      if ( v18 != nullptr )
        CBaseEdict::StateChanged(this: &v18->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  if ( this->m_nRenderFX.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0xB4u);
    }
    this->m_nRenderFX.m_Value = 0;
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEntityDissolve::DissolveThink,
    thinkTime: 0.0,
    szContext: nullptr);
  curtime = gpGlobals->curtime;
  if ( curtime <= this->m_flStartTime.m_Value )
    CBaseEntity::SetNextThink(this, thinkTime: curtime + 0.0099999998, szContext: nullptr);
  else
    CEntityDissolve::DissolveThink(this);
}

//------------------------------------------------------------------------------
// Address: 0x104020B0
// Name: CEntityDissolve_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEntityDissolve_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEntityDissolve>();
  CEntityDissolve_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104020E0
// Name: DT_EntityDissolve::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityDissolve::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EntityDissolve::g_SendTable);
  return atexit(func: DT_EntityDissolve::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402100
// Name: DT_EntityDissolve::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityDissolve::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EntityDissolve::ignored>();
  DT_EntityDissolve::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AAD0
// Name: DT_EntityDissolve::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityDissolve::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EntityDissolve::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104020C0
// Name: _dynamic_initializer_for__g_CEntityDissolve_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEntityDissolve_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEntityDissolve_ClassReg,
           pNetworkName: "CEntityDissolve",
           pTable: &DT_EntityDissolve::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402110
// Name: _dynamic_initializer_for__env_entity_dissolver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_entity_dissolver__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEntityDissolve> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_entity_dissolver,
           a3: "env_entity_dissolver");
}

//------------------------------------------------------------------------------
// Address: 0x1041AAE0
// Name: _ServerClassInit_DT_EntityDissolve::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EntityDissolve::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_42;
  for ( i = 11; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AB00
// Name: _DataMapInit_CEntityDissolve__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEntityDissolve__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_151);
}
