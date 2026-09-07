// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/point_spotlight.cpp
// Functions: 20
// ============================================================

#include "game\server\point_spotlight.h"

//------------------------------------------------------------------------------
// Address: 0x101D4BB0
// Name: public: virtual struct datamap_t __near * CPointSpotlight::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointSpotlight::GetDataDescMap(CPointSpotlight *this)
{
  return &CPointSpotlight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D4BC0
// Name: private: virtual int CPointSpotlight::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPointSpotlight::UpdateTransmitState(CPointSpotlight *this)
{
  if ( this->m_bEfficientSpotlight )
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
  else
    return CBaseEntity::SetTransmitState(this, nFlag: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101D4BE0
// Name: public: virtual void CPointSpotlight::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPointSpotlight::Precache(CPointSpotlight *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  this->m_nHaloSprite = CBaseEntity::PrecacheModel(a1: a2, name: "sprites/light_glow03.vmt", bPreload: true);
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/glow_test02.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x101D4C20
// Name: private: class Vector CPointSpotlight::SpotlightCurrentPos(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPointSpotlight::SpotlightCurrentPos(CPointSpotlight *this, Vector *result)
{
  float m_flSpotlightMaxLength; // xmm3_4
  unsigned int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm2_4
  int m_iEFlags; // eax
  CGameTrace tr; // [esp+8h] [ebp-6Ch] BYREF
  Vector vecAbsEnd; // [esp+5Ch] [ebp-18h] BYREF
  float v11; // [esp+68h] [ebp-Ch]
  float v12; // [esp+6Ch] [ebp-8h]
  float v13; // [esp+70h] [ebp-4h]
  IHandleEntity savedregs; // [esp+74h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, forward: &this->m_vSpotlightDir);
  m_flSpotlightMaxLength = this->m_flSpotlightMaxLength;
  v4 = (unsigned int)this->m_iEFlags >> 11;
  v5 = (float)(this->m_vSpotlightDir.y * 2.0) * m_flSpotlightMaxLength;
  v6 = (float)(this->m_vSpotlightDir.z * 2.0) * m_flSpotlightMaxLength;
  v11 = (float)(this->m_vSpotlightDir.x * 2.0) * m_flSpotlightMaxLength;
  v12 = v5;
  v13 = v6;
  if ( (v4 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  m_iEFlags = this->m_iEFlags;
  vecAbsEnd.x = this->m_vecAbsOrigin.x + v11;
  vecAbsEnd.y = this->m_vecAbsOrigin.y + v12;
  vecAbsEnd.z = this->m_vecAbsOrigin.z + v13;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &this->m_vecAbsOrigin,
    &vecAbsEnd,
    mask: 0x400Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: &tr);
  *result = tr.endpos;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D4D30
// Name: public: CPointSpotlight::CPointSpotlight(void)
// Source: json
//------------------------------------------------------------------------------
CPointSpotlight *__thiscall CPointSpotlight::CPointSpotlight(CPointSpotlight *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CPointSpotlight_vtbl *)&CPointSpotlight::`vftable';
  this->m_hSpotlight.m_Index = -1;
  this->m_hSpotlightTarget.m_Index = -1;
  this->m_OnOn.m_Value.iVal = 0;
  this->m_OnOn.m_Value.eVal.m_Index = -1;
  this->m_OnOn.m_Value.fieldType = FIELD_VOID;
  this->m_OnOff.m_Value.iVal = 0;
  this->m_OnOff.m_Value.eVal.m_Index = -1;
  this->m_OnOff.m_Value.fieldType = FIELD_VOID;
  this->m_flHDRColorScale = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D4D90
// Name: private: void CPointSpotlight::SpotlightDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::SpotlightDestroy(CPointSpotlight *this)
{
  unsigned int m_Index; // eax
  unsigned int v3; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v5; // eax

  m_Index = this->m_hSpotlight.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    COutputEvent::FireOutput(this: &this->m_OnOff, pActivator: this, pCaller: this, fDelay: 0.0);
    v3 = this->m_hSpotlight.m_Index;
    if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
    UTIL_Remove(oldObj: m_pEntity);
    v5 = this->m_hSpotlightTarget.m_Index;
    if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      UTIL_Remove(oldObj: nullptr);
    else
      UTIL_Remove(oldObj: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4E60
// Name: private: void CPointSpotlight::InputLightOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::InputLightOff(CPointSpotlight *this, inputdata_t *inputdata)
{
  bool v2; // zf

  if ( this->m_bSpotlightOn )
  {
    v2 = !this->m_bEfficientSpotlight;
    this->m_bSpotlightOn = false;
    if ( !v2 )
      CPointSpotlight::SpotlightDestroy(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4ED0
// Name: private: void CPointSpotlight::ComputeRenderInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::ComputeRenderInfo(CPointSpotlight *this)
{
  float m_flSpotlightCurLength; // xmm0_4
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity *v5; // esi
  CBaseEdict *v6; // ecx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  float m_flSpotlightMaxLength; // xmm0_4
  IHandleEntity *v10; // ecx
  IHandleEntity *v11; // esi
  int v12; // ebx
  CBaseEdict *v13; // ecx
  unsigned int v14; // eax
  IHandleEntity *v15; // ecx
  IHandleEntity *v16; // esi
  CBaseEdict *v17; // ecx
  unsigned int v18; // eax
  float *v19; // esi
  CBaseEdict *v20; // ecx
  float v21; // xmm0_4
  float v22; // xmm1_4
  unsigned int v23; // eax
  IHandleEntity *v24; // ecx
  float *v25; // esi
  CBaseEdict *v26; // ecx
  unsigned int v27; // eax
  IHandleEntity *v28; // ecx
  IHandleEntity *v29; // esi
  CBaseEdict *v30; // ecx
  double v31; // xmm0_8
  IHandleEntity *v32; // ecx
  float *v33; // esi
  float v34; // xmm0_4
  CBaseEdict *v35; // ecx

  m_flSpotlightCurLength = this->m_flSpotlightCurLength;
  m_Index = this->m_hSpotlightTarget.m_Index;
  if ( m_flSpotlightCurLength > (float)(this->m_flSpotlightMaxLength * 2.0) )
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v5 = m_pEntity + 46;
    if ( HIBYTE(m_pEntity[46].__vftable) != 0 )
    {
      if ( LOBYTE(m_pEntity[21].__vftable) != 0 )
      {
        LOBYTE(m_pEntity[22].__vftable) |= 1u;
      }
      else
      {
        v6 = (CBaseEdict *)m_pEntity[6].__vftable;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: v6, offset: 0xB8u);
      }
      HIBYTE(v5->__vftable) = 0;
    }
    v7 = this->m_hSpotlight.m_Index;
    if ( v7 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
    {
      v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      m_flSpotlightMaxLength = this->m_flSpotlightMaxLength;
      goto LABEL_45;
    }
    goto LABEL_15;
  }
  if ( m_flSpotlightCurLength <= this->m_flSpotlightMaxLength )
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      v15 = nullptr;
    else
      v15 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v16 = v15 + 46;
    if ( HIBYTE(v15[46].__vftable) != 1 )
    {
      if ( LOBYTE(v15[21].__vftable) != 0 )
      {
        LOBYTE(v15[22].__vftable) |= 1u;
      }
      else
      {
        v17 = (CBaseEdict *)v15[6].__vftable;
        if ( v17 != nullptr )
          CBaseEdict::StateChanged(this: v17, offset: 0xB8u);
      }
      HIBYTE(v16->__vftable) = 1;
    }
    v18 = this->m_hSpotlight.m_Index;
    if ( v18 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
      v8 = nullptr;
    else
      v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
    m_flSpotlightMaxLength = this->m_flSpotlightCurLength;
  }
  else
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      v10 = nullptr;
    else
      v10 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v11 = v10 + 46;
    v12 = (int)(float)(1.0
                     - (float)((float)(m_flSpotlightCurLength - this->m_flSpotlightMaxLength)
                             / this->m_flSpotlightMaxLength));
    if ( HIBYTE(v10[46].__vftable) != (_BYTE)v12 )
    {
      if ( LOBYTE(v10[21].__vftable) != 0 )
      {
        LOBYTE(v10[22].__vftable) |= 1u;
      }
      else
      {
        v13 = (CBaseEdict *)v10[6].__vftable;
        if ( v13 != nullptr )
          CBaseEdict::StateChanged(this: v13, offset: 0xB8u);
      }
      HIBYTE(v11->__vftable) = v12;
    }
    v14 = this->m_hSpotlight.m_Index;
    if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
    {
LABEL_15:
      m_flSpotlightMaxLength = this->m_flSpotlightMaxLength;
      v8 = nullptr;
      goto LABEL_45;
    }
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
    m_flSpotlightMaxLength = this->m_flSpotlightMaxLength;
  }
LABEL_45:
  v19 = (float *)&v8[243];
  if ( *(float *)&v8[243].__vftable != m_flSpotlightMaxLength )
  {
    if ( LOBYTE(v8[21].__vftable) != 0 )
    {
      LOBYTE(v8[22].__vftable) |= 1u;
    }
    else
    {
      v20 = (CBaseEdict *)v8[6].__vftable;
      if ( v20 != nullptr )
        CBaseEdict::StateChanged(this: v20, offset: 0x3CCu);
    }
    *v19 = m_flSpotlightMaxLength;
  }
  v21 = (float)(this->m_flSpotlightCurLength / this->m_flSpotlightMaxLength) * this->m_flSpotlightGoalWidth;
  v22 = 102.3;
  if ( v21 >= 0.0 )
  {
    if ( v21 > 102.3 )
      v21 = 102.3;
  }
  else
  {
    v21 = 0.0;
  }
  v23 = this->m_hSpotlight.m_Index;
  if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
    v24 = nullptr;
  else
    v24 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
  if ( v21 <= 102.3 )
    v22 = v21;
  v25 = (float *)&v24[242];
  if ( *(float *)&v24[242].__vftable != v22 )
  {
    if ( LOBYTE(v24[21].__vftable) != 0 )
    {
      LOBYTE(v24[22].__vftable) |= 1u;
    }
    else
    {
      v26 = (CBaseEdict *)v24[6].__vftable;
      if ( v26 != nullptr )
        CBaseEdict::StateChanged(this: v26, offset: 0x3C8u);
    }
    *v25 = v22;
  }
  v27 = this->m_hSpotlightTarget.m_Index;
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    if ( v27 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_SerialNumber != HIWORD(v27) )
      v28 = nullptr;
    else
      v28 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_pEntity;
    v29 = v28 + 213;
    if ( *(float *)&v28[213].__vftable != 0.0 )
    {
      if ( LOBYTE(v28[21].__vftable) != 0 )
      {
        LOBYTE(v28[22].__vftable) |= 1u;
        v29->__vftable = nullptr;
      }
      else
      {
        v30 = (CBaseEdict *)v28[6].__vftable;
        if ( v30 != nullptr )
          CBaseEdict::StateChanged(this: v30, offset: 0x354u);
        v29->__vftable = nullptr;
      }
    }
  }
  else
  {
    v31 = v21 * 1.8;
    if ( v27 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_SerialNumber != HIWORD(v27) )
      v32 = nullptr;
    else
      v32 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_pEntity;
    v33 = (float *)&v32[213];
    v34 = v31;
    if ( *(float *)&v32[213].__vftable != v34 )
    {
      if ( LOBYTE(v32[21].__vftable) != 0 )
      {
        LOBYTE(v32[22].__vftable) |= 1u;
        *v33 = v34;
      }
      else
      {
        v35 = (CBaseEdict *)v32[6].__vftable;
        if ( v35 != nullptr )
          CBaseEdict::StateChanged(this: v35, offset: 0x354u);
        *v33 = v34;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5330
// Name: private: void CPointSpotlight::SpotlightCreate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPointSpotlight::SpotlightCreate(CPointSpotlight *this@<ecx>, int a2@<esi>)
{
  unsigned int m_Index; // eax
  float m_flSpotlightMaxLength; // xmm0_4
  unsigned int v5; // edx
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  int m_iEFlags; // eax
  float v10; // xmm0_4
  IServerNetworkable *EntityByName; // eax
  unsigned int v12; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v14; // eax
  CBaseEntity *v15; // ecx
  unsigned int v16; // eax
  IHandleEntity *v17; // ecx
  unsigned int v18; // eax
  IHandleEntity *v19; // eax
  unsigned int v20; // eax
  IHandleEntity *v21; // ecx
  float *v22; // esi
  CBaseEdict *v23; // ecx
  unsigned int v24; // eax
  IHandleEntity *v25; // ecx
  IHandleEntity *v26; // esi
  CBaseEdict *v27; // ecx
  CBeam *v28; // eax
  unsigned int v29; // eax
  IHandleEntity *v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm1_4
  IHandleEntity *v33; // esi
  CBaseEdict *v34; // ecx
  unsigned int v35; // eax
  IHandleEntity *v36; // ecx
  _DWORD *v37; // esi
  int v38; // edi
  CBaseEdict *v39; // ecx
  unsigned int v40; // eax
  IHandleEntity *v41; // eax
  unsigned int v42; // eax
  IHandleEntity *v43; // ecx
  int m_nHaloSprite; // edi
  _DWORD *v45; // esi
  CBaseEdict *v46; // ecx
  unsigned int v47; // eax
  IHandleEntity *v48; // ecx
  IHandleEntity *v49; // esi
  CBaseEdict *v50; // ecx
  unsigned int v51; // eax
  IHandleEntity *v52; // ecx
  float m_flSpotlightGoalWidth; // xmm0_4
  float v54; // xmm1_4
  float *v55; // esi
  CBaseEdict *v56; // ecx
  unsigned int v57; // eax
  CBeam *v58; // ecx
  unsigned int v59; // eax
  CBaseEntityList *v60; // edx
  IHandleEntity *v61; // ecx
  IHandleEntity *v62; // esi
  CBaseEdict *v63; // ecx
  CBaseEntity *v64; // edi
  float v65; // eax
  IHandleEntity *v66; // ecx
  IHandleEntity *v67; // esi
  CBaseEdict *v68; // ecx
  float v69; // eax
  CBaseEntity *v70; // esi
  float v71; // eax
  CBeam *v72; // ecx
  CBaseEntity *v73; // esi
  float v74; // eax
  int v75; // [esp+8h] [ebp-78h]
  CGameTrace tr; // [esp+14h] [ebp-6Ch] BYREF
  Vector vecAbsEnd; // [esp+68h] [ebp-18h] BYREF
  const Vector *start; // [esp+74h] [ebp-Ch]
  CBaseEntity *pStartEntity; // [esp+78h] [ebp-8h]
  float m_flHDRColorScale; // [esp+7Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+80h] [ebp+0h] BYREF

  m_Index = this->m_hSpotlightTarget.m_Index;
  pStartEntity = this;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v75 = a2;
    AngleVectors(angles: &this->m_angAbsRotation, forward: &this->m_vSpotlightDir);
    m_flSpotlightMaxLength = this->m_flSpotlightMaxLength;
    v5 = (unsigned int)this->m_iEFlags >> 11;
    x = this->m_vSpotlightDir.x * m_flSpotlightMaxLength;
    y = this->m_vSpotlightDir.y * m_flSpotlightMaxLength;
    z = this->m_vSpotlightDir.z * m_flSpotlightMaxLength;
    vecAbsEnd.x = x;
    vecAbsEnd.y = y;
    vecAbsEnd.z = z;
    if ( (v5 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      z = vecAbsEnd.z;
      y = vecAbsEnd.y;
      x = vecAbsEnd.x;
    }
    m_iEFlags = this->m_iEFlags;
    vecAbsEnd.x = this->m_vecAbsOrigin.x + x;
    vecAbsEnd.y = this->m_vecAbsOrigin.y + y;
    v10 = this->m_vecAbsOrigin.z + z;
    start = &this->m_vecAbsOrigin;
    vecAbsEnd.z = v10;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)&this->m_vecAbsOrigin,
      vecAbsStart: &this->m_vecAbsOrigin,
      &vecAbsEnd,
      mask: 0x400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    EntityByName = CreateEntityByName(className: "spotlight_end", iForceEdictIndex: -1, bNotify: true);
    if ( EntityByName != nullptr )
      this->m_hSpotlightTarget.m_Index = *(_DWORD *)((int (__thiscall *)(IServerNetworkable *, int))EntityByName->GetEdict)(
                                                      a1: EntityByName,
                                                      a2);
    else
      this->m_hSpotlightTarget.m_Index = -1;
    v12 = this->m_hSpotlightTarget.m_Index;
    if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
    ((void (__thiscall *)(IHandleEntity *, int))m_pEntity->__vftable[8].dtr_IHandleEntity)(a1: m_pEntity, a2: v75);
    v14 = this->m_hSpotlightTarget.m_Index;
    if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
      v15 = nullptr;
    else
      v15 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
    CBaseEntity::SetAbsOrigin(this: v15, absOrigin: &tr.endpos);
    v16 = this->m_hSpotlightTarget.m_Index;
    if ( v16 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16) )
      v17 = nullptr;
    else
      v17 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
    ((void (__thiscall *)(IHandleEntity *, CPointSpotlight *))v17->__vftable[6].dtr_IHandleEntity)(a1: v17, a2: this);
    v18 = this->m_hSpotlightTarget.m_Index;
    if ( v18 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
      v19 = nullptr;
    else
      v19 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
    CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::operator=(
      this: (CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *)&v19[46],
      val: &this->m_clrRender);
    v20 = this->m_hSpotlightTarget.m_Index;
    if ( v20 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
      v21 = nullptr;
    else
      v21 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
    v22 = (float *)&v21[214];
    if ( *(float *)&v21[214].__vftable != this->m_flSpotlightMaxLength )
    {
      if ( LOBYTE(v21[21].__vftable) != 0 )
      {
        LOBYTE(v21[22].__vftable) |= 1u;
      }
      else
      {
        v23 = (CBaseEdict *)v21[6].__vftable;
        if ( v23 != nullptr )
          CBaseEdict::StateChanged(this: v23, offset: 0x358u);
      }
      *v22 = this->m_flSpotlightMaxLength;
    }
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
    {
      v24 = this->m_hSpotlightTarget.m_Index;
      if ( v24 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
        v25 = nullptr;
      else
        v25 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
      v26 = v25 + 213;
      if ( *(float *)&v25[213].__vftable != 0.0 )
      {
        if ( LOBYTE(v25[21].__vftable) != 0 )
        {
          LOBYTE(v25[22].__vftable) |= 1u;
        }
        else
        {
          v27 = (CBaseEdict *)v25[6].__vftable;
          if ( v27 != nullptr )
            CBaseEdict::StateChanged(this: v27, offset: 0x354u);
        }
        v26->__vftable = nullptr;
      }
    }
    v28 = CBeam::BeamCreate(pSpriteName: "sprites/glow_test02.vmt", width: this->m_flSpotlightGoalWidth);
    if ( v28 != nullptr )
      this->m_hSpotlight.m_Index = v28->GetRefEHandle(this: v28)->m_Index;
    else
      this->m_hSpotlight.m_Index = -1;
    v29 = this->m_hSpotlight.m_Index;
    if ( v29 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_SerialNumber != HIWORD(v29) )
      v30 = nullptr;
    else
      v30 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_pEntity;
    v32 = *(float *)&v30[214].__vftable;
    v33 = v30 + 214;
    m_flHDRColorScale = this->m_flHDRColorScale;
    v31 = m_flHDRColorScale;
    if ( v32 != m_flHDRColorScale )
    {
      if ( LOBYTE(v30[21].__vftable) != 0 )
      {
        LOBYTE(v30[22].__vftable) |= 1u;
      }
      else
      {
        v34 = (CBaseEdict *)v30[6].__vftable;
        if ( v34 != nullptr )
        {
          CBaseEdict::StateChanged(this: v34, offset: 0x358u);
          v31 = m_flHDRColorScale;
        }
      }
      *(float *)&v33->__vftable = v31;
    }
    v35 = this->m_hSpotlight.m_Index;
    if ( v35 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_SerialNumber != HIWORD(v35) )
      v36 = nullptr;
    else
      v36 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_pEntity;
    v37 = &v36[190].__vftable;
    v38 = (int)v36[190].__vftable | 0x8000;
    if ( v36[190].__vftable != (IHandleEntity_vtbl *)v38 )
    {
      if ( LOBYTE(v36[21].__vftable) != 0 )
      {
        LOBYTE(v36[22].__vftable) |= 1u;
      }
      else
      {
        v39 = (CBaseEdict *)v36[6].__vftable;
        if ( v39 != nullptr )
          CBaseEdict::StateChanged(this: v39, offset: 0x2F8u);
      }
      *v37 = v38;
    }
    v40 = this->m_hSpotlight.m_Index;
    if ( v40 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v40].m_SerialNumber != HIWORD(v40) )
      v41 = nullptr;
    else
      v41 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v40].m_pEntity;
    CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
      this: (CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *)&v41[46],
      rVal: this->m_clrRender.m_Value.r,
      gVal: this->m_clrRender.m_Value.g,
      bVal: this->m_clrRender.m_Value.b);
    v42 = this->m_hSpotlight.m_Index;
    if ( v42 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_SerialNumber != HIWORD(v42) )
      v43 = nullptr;
    else
      v43 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_pEntity;
    m_nHaloSprite = this->m_nHaloSprite;
    v45 = &v43[218].__vftable;
    if ( v43[218].__vftable != (IHandleEntity_vtbl *)m_nHaloSprite )
    {
      if ( LOBYTE(v43[21].__vftable) != 0 )
      {
        LOBYTE(v43[22].__vftable) |= 1u;
      }
      else
      {
        v46 = (CBaseEdict *)v43[6].__vftable;
        if ( v46 != nullptr )
          CBaseEdict::StateChanged(this: v46, offset: 0x368u);
      }
      *v45 = m_nHaloSprite;
    }
    v47 = this->m_hSpotlight.m_Index;
    if ( v47 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_SerialNumber != HIWORD(v47) )
      v48 = nullptr;
    else
      v48 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v47].m_pEntity;
    v49 = v48 + 244;
    if ( *(float *)&v48[244].__vftable != 60.0 )
    {
      if ( LOBYTE(v48[21].__vftable) != 0 )
      {
        LOBYTE(v48[22].__vftable) |= 1u;
      }
      else
      {
        v50 = (CBaseEdict *)v48[6].__vftable;
        if ( v50 != nullptr )
          CBaseEdict::StateChanged(this: v50, offset: 0x3D0u);
      }
      v49->__vftable = (IHandleEntity_vtbl *)1114636288;
    }
    v51 = this->m_hSpotlight.m_Index;
    if ( v51 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v51].m_SerialNumber != HIWORD(v51) )
      v52 = nullptr;
    else
      v52 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v51].m_pEntity;
    m_flSpotlightGoalWidth = this->m_flSpotlightGoalWidth;
    if ( m_flSpotlightGoalWidth > 102.3 )
      m_flSpotlightGoalWidth = 102.3;
    v54 = *(float *)&v52[242].__vftable;
    v55 = (float *)&v52[242];
    m_flHDRColorScale = m_flSpotlightGoalWidth;
    if ( v54 != m_flSpotlightGoalWidth )
    {
      if ( LOBYTE(v52[21].__vftable) != 0 )
      {
        LOBYTE(v52[22].__vftable) |= 1u;
      }
      else
      {
        v56 = (CBaseEdict *)v52[6].__vftable;
        if ( v56 != nullptr )
        {
          CBaseEdict::StateChanged(this: v56, offset: 0x3C8u);
          m_flSpotlightGoalWidth = m_flHDRColorScale;
        }
      }
      *v55 = m_flSpotlightGoalWidth;
    }
    v57 = this->m_hSpotlight.m_Index;
    if ( v57 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v57].m_SerialNumber != HIWORD(v57) )
      v58 = nullptr;
    else
      v58 = (CBeam *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v57].m_pEntity;
    CBeam::SetBeamFlags(this: v58, flags: 640);
    v59 = this->m_hSpotlight.m_Index;
    v60 = g_pEntityList;
    if ( v59 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v59].m_SerialNumber != HIWORD(v59) )
      v61 = nullptr;
    else
      v61 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v59].m_pEntity;
    v62 = v61 + 46;
    if ( HIBYTE(v61[46].__vftable) != 64 )
    {
      if ( LOBYTE(v61[21].__vftable) != 0 )
      {
        LOBYTE(v61[22].__vftable) |= 1u;
      }
      else
      {
        v63 = (CBaseEdict *)v61[6].__vftable;
        if ( v63 != nullptr )
          CBaseEdict::StateChanged(this: v63, offset: 0xB8u);
      }
      HIBYTE(v62->__vftable) = 64;
      v60 = g_pEntityList;
    }
    v64 = pStartEntity;
    v65 = pStartEntity[1].m_Network.m_PVSInfo.m_vCenter[1];
    if ( v65 == NAN || v60->m_EntPtrArray[LOWORD(v65)].m_SerialNumber != HIWORD(LODWORD(v65)) )
      v66 = nullptr;
    else
      v66 = v60->m_EntPtrArray[LOWORD(v65)].m_pEntity;
    v67 = v66 + 245;
    if ( *(float *)&v66[245].__vftable != 0.0 )
    {
      if ( LOBYTE(v66[21].__vftable) != 0 )
      {
        LOBYTE(v66[22].__vftable) |= 1u;
      }
      else
      {
        v68 = (CBaseEdict *)v66[6].__vftable;
        if ( v68 != nullptr )
          CBaseEdict::StateChanged(this: v68, offset: 0x3D4u);
      }
      v67->__vftable = nullptr;
      v60 = g_pEntityList;
    }
    v69 = v64[1].m_Network.m_PVSInfo.m_vCenter[2];
    if ( BYTE1(v64[1].__vftable) != 0 )
    {
      if ( v69 == NAN || v60->m_EntPtrArray[LOWORD(v69)].m_SerialNumber != HIWORD(LODWORD(v69)) )
        v70 = nullptr;
      else
        v70 = (CBaseEntity *)v60->m_EntPtrArray[LOWORD(v69)].m_pEntity;
      if ( (v70->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: v70, a2: (int)&savedregs);
        v60 = g_pEntityList;
      }
      if ( (v64->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: v64, a2: (int)&savedregs);
        v60 = g_pEntityList;
      }
      v71 = v64[1].m_Network.m_PVSInfo.m_vCenter[1];
      if ( v71 == NAN || v60->m_EntPtrArray[LOWORD(v71)].m_SerialNumber != HIWORD(LODWORD(v71)) )
        v72 = nullptr;
      else
        v72 = (CBeam *)v60->m_EntPtrArray[LOWORD(v71)].m_pEntity;
      CBeam::PointsInit(this: v72, start, end: &v70->m_vecAbsOrigin);
    }
    else
    {
      if ( v69 == NAN || v60->m_EntPtrArray[LOWORD(v69)].m_SerialNumber != HIWORD(LODWORD(v69)) )
        v73 = nullptr;
      else
        v73 = (CBaseEntity *)v60->m_EntPtrArray[LOWORD(v69)].m_pEntity;
      v74 = v64[1].m_Network.m_PVSInfo.m_vCenter[1];
      if ( v74 == NAN || v60->m_EntPtrArray[LOWORD(v74)].m_SerialNumber != HIWORD(LODWORD(v74)) )
        CBeam::EntsInit(this: nullptr, pStartEntity: v64, pEndEntity: v73);
      else
        CBeam::EntsInit(this: (CBeam *)v60->m_EntPtrArray[LOWORD(v74)].m_pEntity, pStartEntity: v64, pEndEntity: v73);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5B60
// Name: private: void CPointSpotlight::SpotlightUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPointSpotlight::SpotlightUpdate(CPointSpotlight *this@<ecx>, int a2@<ebp>, int a3@<esi>)
{
  unsigned int m_Index; // eax
  unsigned int v5; // eax
  CHandle<CSpotlightEnd> *p_m_hSpotlightTarget; // esi
  unsigned int v7; // eax
  Vector *v8; // eax
  float y; // ecx
  unsigned int v10; // eax
  float z; // ecx
  float v12; // xmm1_4
  float v13; // xmm2_4
  __int128 v14; // xmm0
  unsigned int v15; // eax
  __int128 v16; // xmm0
  float v17; // esi
  CBaseEntity *v18; // eax
  unsigned int v19; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v21; // eax
  float *v22; // eax
  unsigned int v23; // eax
  float *v24; // edi
  CBaseEntity *v25; // esi
  float v26; // eax
  unsigned int v27; // eax
  IHandleEntity *v28; // ecx
  double v29; // st7
  float x; // ecx
  __int128 v31; // [esp-28h] [ebp-4Ch] BYREF
  Vector v32; // [esp-Ch] [ebp-30h] BYREF
  Vector vTargetDir; // [esp+0h] [ebp-24h] BYREF
  Vector vecNewVelocity; // [esp+Ch] [ebp-18h]
  _DWORD v35[3]; // [esp+18h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+24h] [ebp+0h]

  v35[0] = a2;
  v35[1] = retaddr;
  m_Index = this->m_hSpotlight.m_Index;
  LODWORD(vecNewVelocity.x) = this;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( !this->m_bSpotlightOn )
    {
      CPointSpotlight::SpotlightDestroy(this);
      return;
    }
  }
  else
  {
    if ( !this->m_bSpotlightOn )
      return;
    CPointSpotlight::SpotlightCreate(this, a2: a3);
  }
  v5 = this->m_hSpotlightTarget.m_Index;
  p_m_hSpotlightTarget = &this->m_hSpotlightTarget;
  LODWORD(vecNewVelocity.y) = &this->m_hSpotlightTarget;
  if ( v5 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity != nullptr
    || (DevWarning(a1: "**Attempting to update point_spotlight but target ent is NULL\n"),
        CPointSpotlight::SpotlightDestroy(this),
        CPointSpotlight::SpotlightCreate(this, a2: (int)p_m_hSpotlightTarget),
        v7 = p_m_hSpotlightTarget->m_Index,
        p_m_hSpotlightTarget->m_Index != -1)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr )
  {
    v8 = CPointSpotlight::SpotlightCurrentPos(this, result: (Vector *)((char *)&v31 + 4));
    y = vecNewVelocity.y;
    this->m_vSpotlightCurrentPos = *v8;
    v10 = *(_DWORD *)LODWORD(y);
    if ( *(_DWORD *)LODWORD(y) == -1 )
    {
      z = 0.0;
      vecNewVelocity.z = 0.0;
    }
    else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10) )
    {
      LODWORD(vecNewVelocity.z) = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      z = vecNewVelocity.z;
    }
    else
    {
      vecNewVelocity.z = 0.0;
      z = 0.0;
    }
    if ( (*(_DWORD *)(LODWORD(z) + 196) & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(z), a2: (int)v35);
      z = vecNewVelocity.z;
    }
    v12 = this->m_vSpotlightCurrentPos.y;
    v13 = this->m_vSpotlightCurrentPos.z;
    v32.x = this->m_vSpotlightCurrentPos.x - *(float *)(LODWORD(z) + 460);
    v32.y = v12 - *(float *)(LODWORD(z) + 464);
    v32.z = v13 - *(float *)(LODWORD(z) + 468);
    v14 = 0;
    *(float *)&v14 = fsqrt((float)((float)(v32.y * v32.y) + (float)(v32.z * v32.z)) + (float)(v32.x * v32.x));
    v31 = v14;
    if ( *(float *)&v14 >= 1.0 )
    {
      vTargetDir = v32;
      VectorNormalize(vec: &vTargetDir);
      vTargetDir.y = vTargetDir.y * (float)(*(float *)&v31 * 10.0);
      vTargetDir.z = vTargetDir.z * (float)(*(float *)&v31 * 10.0);
      vTargetDir.x = vTargetDir.x * (float)(*(float *)&v31 * 10.0);
      v16 = 0;
      *(float *)&v16 = fsqrt(
                         (float)((float)(vTargetDir.y * vTargetDir.y) + (float)(vTargetDir.z * vTargetDir.z))
                       + (float)(vTargetDir.x * vTargetDir.x));
      v31 = v16;
      if ( *(float *)&v16 <= 200.0 )
      {
        v17 = vecNewVelocity.y;
      }
      else
      {
        VectorNormalize(vec: &vTargetDir);
        vTargetDir.x = vTargetDir.x * 200.0;
        vTargetDir.y = vTargetDir.y * 200.0;
        vTargetDir.z = vTargetDir.z * 200.0;
        VectorNormalize(vec: &v32);
        v17 = vecNewVelocity.y;
        v18 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)LODWORD(vecNewVelocity.y));
        CBaseEntity::SetAbsOrigin(this: v18, absOrigin: &this->m_vSpotlightCurrentPos);
      }
      v19 = *(_DWORD *)LODWORD(v17);
      if ( *(_DWORD *)LODWORD(v17) == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
      }
      CBaseEntity::SetAbsVelocity(this: m_pEntity, vecAbsVelocity: &vTargetDir);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)v35);
      v21 = *(_DWORD *)LODWORD(v17);
      if ( *(_DWORD *)LODWORD(v17) == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
      {
        v22 = nullptr;
      }
      else
      {
        v22 = (float *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
      }
      v22[218] = this->m_vecAbsOrigin.x;
      v22[219] = this->m_vecAbsOrigin.y;
      v22[220] = this->m_vecAbsOrigin.z;
      v23 = *(_DWORD *)LODWORD(v17);
      if ( *(_DWORD *)LODWORD(v17) == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
      {
        vecNewVelocity.y = 0.0;
      }
      else
      {
        LODWORD(vecNewVelocity.y) = g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
      }
      if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
        v24 = nullptr;
      else
        v24 = (float *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
      if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
        v25 = nullptr;
      else
        v25 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
      if ( (v25->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v25, a2: (int)v35);
      v26 = vecNewVelocity.y;
      *(float *)(LODWORD(vecNewVelocity.y) + 860) = v25->m_vecAbsOrigin.x - v24[218];
      *(float *)(LODWORD(v26) + 864) = v25->m_vecAbsOrigin.y - v24[219];
      *(float *)(LODWORD(v26) + 868) = v25->m_vecAbsOrigin.z - v24[220];
      v27 = *(_DWORD *)(LODWORD(vecNewVelocity.x) + 900);
      if ( v27 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_SerialNumber != HIWORD(v27) )
        v28 = nullptr;
      else
        v28 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_pEntity;
      v29 = VectorNormalize(vec: (Vector *)&v28[215]);
      x = vecNewVelocity.x;
      *(float *)(LODWORD(vecNewVelocity.x) + 908) = *(float *)(LODWORD(vecNewVelocity.x) + 908) * 0.6 + v29 * 0.4;
      CPointSpotlight::ComputeRenderInfo(this: (CPointSpotlight *)LODWORD(x));
    }
    else
    {
      v15 = *(_DWORD *)LODWORD(vecNewVelocity.y);
      if ( *(_DWORD *)LODWORD(vecNewVelocity.y) == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
      {
        CBaseEntity::SetAbsVelocity(this: nullptr, vecAbsVelocity: &vec3_origin);
      }
      else
      {
        CBaseEntity::SetAbsVelocity(
          this: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity,
          vecAbsVelocity: &vec3_origin);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6060
// Name: private: void CPointSpotlight::InputSetColor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::InputSetColor(CPointSpotlight *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *m_pEntity; // eax

  m_Index = this->m_hSpotlight.m_Index;
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
        m_pEntity = (CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *)v8->m_pEntity;
      else
        m_pEntity = nullptr;
      CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
        this: m_pEntity + 46,
        rVal: inputdata->value.iVal,
        gVal: BYTE1(inputdata->value.iszVal.pszValue),
        bVal: BYTE2(inputdata->value.iVal));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D60D0
// Name: private: void CPointSpotlight::InputForceUpdate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __userpurge CPointSpotlight::InputForceUpdate(
        CPointSpotlight *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        inputdata_t *inputdata)
{
  CPointSpotlight::SpotlightUpdate(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x101D60E0
// Name: private: void CPointSpotlight::CreateEfficientSpotlight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::CreateEfficientSpotlight(CPointSpotlight *this)
{
  unsigned int m_Index; // eax
  unsigned int v3; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v5; // eax
  float *v6; // eax
  unsigned int v7; // eax
  float *v8; // ebx
  CBaseEntity *v9; // edi
  IHandleEntity *v10; // eax
  unsigned int v11; // eax
  IHandleEntity *v12; // ecx
  unsigned int v13; // eax
  CBaseEntity *v14; // ecx
  Vector result; // [esp+8h] [ebp-10h] BYREF
  IHandleEntity *v16; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  m_Index = this->m_hSpotlightTarget.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    CPointSpotlight::SpotlightCreate(this, a2: (int)this);
    this->m_vSpotlightCurrentPos = *CPointSpotlight::SpotlightCurrentPos(this, &result);
    v3 = this->m_hSpotlightTarget.m_Index;
    if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
    CBaseEntity::SetAbsOrigin(this: m_pEntity, absOrigin: &this->m_vSpotlightCurrentPos);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v5 = this->m_hSpotlightTarget.m_Index;
    if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      v6 = nullptr;
    else
      v6 = (float *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    v6[218] = this->m_vecAbsOrigin.x;
    v6[219] = this->m_vecAbsOrigin.y;
    v6[220] = this->m_vecAbsOrigin.z;
    v7 = this->m_hSpotlightTarget.m_Index;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      v16 = nullptr;
    else
      v16 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      v8 = nullptr;
    else
      v8 = (float *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      v9 = nullptr;
    else
      v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    if ( (v9->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
    v10 = v16;
    *(float *)&v16[215].__vftable = v9->m_vecAbsOrigin.x - v8[218];
    *(float *)&v10[216].__vftable = v9->m_vecAbsOrigin.y - v8[219];
    *(float *)&v10[217].__vftable = v9->m_vecAbsOrigin.z - v8[220];
    v11 = this->m_hSpotlightTarget.m_Index;
    if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
      v12 = nullptr;
    else
      v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    this->m_flSpotlightCurLength = VectorNormalize(vec: (Vector *)&v12[215]);
    v13 = this->m_hSpotlightTarget.m_Index;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v14 = nullptr;
    else
      v14 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    CBaseEntity::SetMoveType(this: v14, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    CPointSpotlight::ComputeRenderInfo(this);
    COutputEvent::FireOutput(this: &this->m_OnOn, pActivator: this, pCaller: this, fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6360
// Name: public: virtual void CPointSpotlight::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::Activate(CPointSpotlight *this)
{
  unsigned int m_Index; // eax

  CBaseEntity::Activate(this);
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    this->m_bEfficientSpotlight = false;
  }
  if ( this->m_bEfficientSpotlight )
  {
    if ( this->m_bSpotlightOn )
      CPointSpotlight::CreateEfficientSpotlight(this);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D63D0
// Name: private: void CPointSpotlight::SpotlightThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPointSpotlight::SpotlightThink(CPointSpotlight *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // eax
  float thinkTime; // xmm0_4

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    thinkTime = gpGlobals->interval_per_tick + gpGlobals->curtime;
  }
  else
  {
    thinkTime = gpGlobals->curtime + 0.1;
  }
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  CPointSpotlight::SpotlightUpdate(this, a2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x101D6440
// Name: private: void CPointSpotlight::InputLightOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::InputLightOn(CPointSpotlight *this, inputdata_t *inputdata)
{
  bool v2; // zf

  if ( !this->m_bSpotlightOn )
  {
    v2 = !this->m_bEfficientSpotlight;
    this->m_bSpotlightOn = true;
    if ( !v2 )
      CPointSpotlight::CreateEfficientSpotlight(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6610
// Name: public: virtual void CPointSpotlight::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::Spawn(CPointSpotlight *this)
{
  bool v2; // cf
  const char *pszValue; // edi
  const char *DebugName; // eax
  const char *v5; // edi
  const char *v6; // eax
  float m_flSpotlightGoalWidth; // xmm0_4
  const char *v8; // edi
  const char *v9; // eax
  char m_Value; // cl

  this->Precache(this);
  UTIL_SetSize(pEnt: this, vecMin: &vec3_origin, vecMax: &vec3_origin);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = this->m_flSpotlightMaxLength > 0.0;
  this->m_bEfficientSpotlight = true;
  if ( !v2 )
  {
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "%s (%s) has an invalid spotlight length <= 0, setting to 500\n", pszValue, DebugName);
    this->m_flSpotlightMaxLength = 500.0;
  }
  if ( this->m_flSpotlightGoalWidth <= 0.0 )
  {
    v5 = this->m_iClassname.pszValue;
    if ( v5 == nullptr )
      v5 = locale;
    v6 = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "%s (%s) has an invalid spotlight width <= 0, setting to 10\n", v5, v6);
    this->m_flSpotlightGoalWidth = 10.0;
  }
  m_flSpotlightGoalWidth = this->m_flSpotlightGoalWidth;
  if ( m_flSpotlightGoalWidth > 102.3 )
  {
    v8 = this->m_iClassname.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    v9 = CBaseEntity::GetDebugName(this);
    DevMsg(
      a1: "%s (%s) has an invalid spotlight width %.1f (max %.1f).\n",
      v8,
      v9,
      m_flSpotlightGoalWidth,
      102.3000030517578);
    this->m_flSpotlightGoalWidth = 102.3;
  }
  this->m_vSpotlightTargetPos = vec3_origin;
  this->m_vSpotlightCurrentPos = vec3_origin;
  this->m_hSpotlight.m_Index = -1;
  this->m_hSpotlightTarget.m_Index = -1;
  this->m_vSpotlightDir = vec3_origin;
  m_Value = this->m_spawnflags.m_Value;
  this->m_flSpotlightCurLength = this->m_flSpotlightMaxLength;
  this->m_bSpotlightOn = m_Value & 1;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CPointSpotlight::SpotlightThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D6830
// Name: public: virtual void CPointSpotlight::OnEntityEvent(enum EntityEvent_t,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointSpotlight::OnEntityEvent(CPointSpotlight *this, EntityEvent_t event, void *pEventData)
{
  unsigned int m_Index; // eax
  unsigned int v5; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CBaseEntity **v11; // eax
  CBaseEntity *v12; // eax

  if ( event == ENTITY_EVENT_PARENT_CHANGED )
  {
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      this->m_bEfficientSpotlight = false;
      v5 = this->m_hSpotlightTarget.m_Index;
      if ( v5 != -1 )
      {
        v6 = (unsigned __int16)v5;
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v5];
        v8 = HIWORD(v5);
        if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
        {
          v9 = v6;
          v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
          v11 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v9];
          if ( v10 )
            v12 = *v11;
          else
            v12 = nullptr;
          CBaseEntity::SetMoveType(this: v12, val: MOVETYPE_FLY, moveCollide: MOVECOLLIDE_DEFAULT);
        }
      }
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CPointSpotlight::SpotlightThink,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
    }
  }
  CBaseEntity::OnEntityEvent(this, event, pEventData);
}

//------------------------------------------------------------------------------
// Address: 0x10408790
// Name: CPointSpotlight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointSpotlight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointSpotlight>(__formal: nullptr);
  CPointSpotlight_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D6470
// Name: struct datamap_t __near * DataMapInit<class CPointSpotlight>(class CPointSpotlight __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointSpotlight>()
{
  if ( (_S2_180 & 1) == 0 )
  {
    _S2_180 |= 1u;
    nameHolder_340.m_pszBase = "CPointSpotlight";
    nameHolder_340.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_340.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_340.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_340.m_Names.m_Size = 0;
    nameHolder_340.m_Names.m_pElements = nullptr;
    nameHolder_340.m_nLenBase = 15;
    atexit(func: DataMapInit_CPointSpotlight__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointSpotlight::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_180 & 2) == 0 )
  {
    _S2_180 |= 2u;
    *(_QWORD *)&dataDesc_325[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_325[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_325[15].override_count = 0;
    *(_QWORD *)dataDesc_325[15].flatOffset = 0;
    dataDesc_325[16].fieldSize = 1;
    dataDesc_325[15].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_325[15].flatGroup = 0;
    dataDesc_325[16].fieldType = FIELD_CUSTOM;
    dataDesc_325[16].fieldName = "m_OnOff";
    dataDesc_325[16].fieldOffset = 944;
    dataDesc_325[16].flags = 22;
    dataDesc_325[16].externalName = "OnLightOff";
    dataDesc_325[16].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_325[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_325[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_325[16].override_count = 0;
    *(_QWORD *)dataDesc_325[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_325[16].flatGroup = 0;
    dataDesc_325[17].fieldType = FIELD_VOID;
    dataDesc_325[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_340,
                                   pszIdentifier: "SpotlightThink");
    dataDesc_325[17].fieldOffset = 0;
    *(_DWORD *)&dataDesc_325[17].fieldSize = 2097153;
    dataDesc_325[17].externalName = nullptr;
    dataDesc_325[17].pSaveRestoreOps = nullptr;
    dataDesc_325[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointSpotlight::SpotlightThink;
    *(_QWORD *)&dataDesc_325[17].td = 0;
    *(_QWORD *)&dataDesc_325[17].override_field = 0;
    *(_QWORD *)&dataDesc_325[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_325[17].flatOffset[1] = 0;
  }
  CPointSpotlight::m_DataMap.dataNumFields = 17;
  CPointSpotlight::m_DataMap.dataDesc = &dataDesc_325[1];
  return &CPointSpotlight::m_DataMap;
}
