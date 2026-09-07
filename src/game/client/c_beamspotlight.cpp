// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_beamspotlight.cpp
// Functions: 16
// ============================================================

#include "game\client\c_beamspotlight.h"

//------------------------------------------------------------------------------
// Address: 0x100608C0
// Name: public: virtual class ClientClass __near * C_BeamSpotLight::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BeamSpotLight::GetClientClass(C_BeamSpotLight *this)
{
  return &__g_C_BeamSpotLightClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10060A20
// Name: public: virtual void C_BeamSpotLight::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BeamSpotLight::OnDataChanged(C_BeamSpotLight *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
    this->m_vSpotlightDir.z = this->m_flRotationSpeed;
  (*(void (__stdcall **)(int))(*((_DWORD *)this - 2) + 456))(a1: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x10060AD0
// Name: public: C_BeamSpotLight::C_BeamSpotLight(void)
// Source: json
//------------------------------------------------------------------------------
C_BeamSpotLight *__thiscall C_BeamSpotLight::C_BeamSpotLight(C_BeamSpotLight *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BeamSpotLight_vtbl *)&C_BeamSpotLight::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BeamSpotLight::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BeamSpotLight::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BeamSpotLight::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BeamSpotLight::`vftable';
  this->m_vSpotlightTargetPos = vec3_origin;
  this->m_vSpotlightCurrentPos = vec3_origin;
  this->m_vSpotlightDir = vec3_origin;
  this->m_hSpotlight.m_Index = -1;
  this->m_pDynamicLight = nullptr;
  this->m_pCache = nullptr;
  this->m_flSpotlightCurLength = 0.0;
  this->m_flLightScale = 100.0;
  this->m_lastTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10060B90
// Name: private: class Vector C_BeamSpotLight::SpotlightCurrentPos(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
Vector *__userpurge C_BeamSpotLight::SpotlightCurrentPos@<eax>(
        C_BeamSpotLight *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Vector *result)
{
  int v6; // eax
  const Vector *v7; // eax
  float z; // ecx
  int v9; // edi
  bool v10; // zf
  const Vector *v11; // eax
  CSpotlightTraceCacheEntry *v12; // ecx
  float m_radius; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float y; // xmm4_4
  float v18; // xmm5_4
  float x; // xmm3_4
  __int128 v20; // xmm0
  CSpotlightTraceCacheEntry *v21; // edi
  _DWORD v23[3]; // [esp-Ch] [ebp-84h] BYREF
  _BYTE tr[92]; // [esp+0h] [ebp-78h] OVERLAPPED
  QAngle angles; // [esp+5Ch] [ebp-1Ch]
  Vector position; // [esp+68h] [ebp-10h] BYREF
  float retaddr; // [esp+78h] [ebp+0h]

  position.y = a2;
  position.z = retaddr;
  v6 = ((int (__thiscall *)(C_BeamSpotLight *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->GetAbsAngles)(
         a1: this,
         a2: a3,
         a3: a4,
         a4: v23[0],
         a5: v23[1],
         a6: v23[2],
         a7: *(_DWORD *)tr,
         a8: *(_DWORD *)&tr[4],
         a9: *(_DWORD *)&tr[8],
         a10: *(_DWORD *)&tr[12],
         a11: *(_DWORD *)&tr[16],
         a12: *(_DWORD *)&tr[20],
         a13: *(_DWORD *)&tr[24],
         a14: *(_DWORD *)&tr[28],
         a15: *(_DWORD *)&tr[32],
         a16: *(_DWORD *)&tr[36],
         a17: *(_DWORD *)&tr[40],
         a18: *(_DWORD *)&tr[44],
         a19: *(_DWORD *)&tr[48],
         a20: *(_DWORD *)&tr[52],
         a21: *(_DWORD *)&tr[56],
         a22: *(_DWORD *)&tr[60],
         a23: *(_DWORD *)&tr[64],
         a24: *(_DWORD *)&tr[68],
         a25: *(_DWORD *)&tr[72],
         a26: *(_DWORD *)&tr[76],
         a27: *(_DWORD *)&tr[80],
         a28: *(_DWORD *)&tr[84],
         a29: *(_DWORD *)&tr[88],
         a30: LODWORD(angles.x),
         a31: LODWORD(angles.y),
         a32: LODWORD(angles.z));
  *(_DWORD *)&tr[88] = *(_DWORD *)(v6 + 8);
  *(_QWORD *)&tr[80] = *(_QWORD *)v6;
  LODWORD(position.x) = &this->m_vSpotlightDir;
  C_BaseEntity::GetVectors(this, pForward: &this->m_vSpotlightDir, pRight: nullptr, pUp: nullptr);
  v7 = this->GetAbsOrigin(this);
  z = v7->z;
  v9 = -1;
  v10 = this->m_pCache == nullptr;
  *(_QWORD *)&angles.x = *(_QWORD *)&v7->x;
  angles.z = z;
  if ( v10
    || (v9 = (int)(float)((float)(*(float *)&tr[4 * this->m_nRotationAxis + 80] * 64.0) * 0.0027777778) & 0x3F,
        v11 = this->GetAbsOrigin(this),
        (v12 = &this->m_pCache[v9])->m_radius <= 0.0)
    || (float)((float)((float)((float)(v12->m_origin.y - v11->y) * (float)(v12->m_origin.y - v11->y))
                     + (float)((float)(v12->m_origin.x - v11->x) * (float)(v12->m_origin.x - v11->x)))
             + (float)((float)(v12->m_origin.z - v11->z) * (float)(v12->m_origin.z - v11->z))) >= 1.0 )
  {
    UTIL_TraceLine(
      a1: (const IHandleEntity *)&position.y,
      a2: (int)this,
      vecAbsStart: COERCE_CONST_VECTOR_((float)((float)(*(float *)LODWORD(position.x) * 2.0) * this->m_flSpotlightMaxLength) + *(float *)&this),
      vecAbsEnd: COERCE_CONST_VECTOR_((float)((float)(*(float *)(LODWORD(position.x) + 4) * 2.0) * this->m_flSpotlightMaxLength) + 0.0),
      mask: COERCE_UNSIGNED_INT((float)((float)(*(float *)(LODWORD(position.x) + 8) * 2.0) * this->m_flSpotlightMaxLength) + COERCE_FLOAT(v23)),
      ignore: this,
      collisionGroup: 0,
      ptr: (CGameTrace *)v23);
    if ( v9 >= 0 )
    {
      y = angles.y;
      v18 = angles.z;
      x = angles.x;
      v20 = 0;
      v21 = &this->m_pCache[v9];
      *(float *)&v20 = fsqrt(
                         (float)((float)((float)(*(float *)&tr[4] - y) * (float)(*(float *)&tr[4] - y))
                               + (float)((float)(*(float *)&tr[8] - v18) * (float)(*(float *)&tr[8] - v18)))
                       + (float)((float)(*(float *)tr - x) * (float)(*(float *)tr - x)));
      *(_OWORD *)&tr[76] = v20;
      LODWORD(v21->m_radius) = v20;
      v21->m_origin.x = x;
      v21->m_origin.y = y;
      v21->m_origin.z = v18;
    }
    *result = *(Vector *)tr;
    return result;
  }
  else
  {
    m_radius = v12->m_radius;
    v15 = *(float *)(LODWORD(position.x) + 4) * m_radius;
    v16 = *(float *)(LODWORD(position.x) + 8) * m_radius;
    result->x = angles.x + (float)(*(float *)LODWORD(position.x) * m_radius);
    result->y = angles.y + v15;
    result->z = angles.z + v16;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060E40
// Name: CC_BeamSpotLightFactory
// Source: json
//------------------------------------------------------------------------------
C_BeamSpotLight *__cdecl CC_BeamSpotLightFactory()
{
  C_BeamSpotLight *v0; // eax

  v0 = (C_BeamSpotLight *)C_BaseEntity::operator new(stAllocateBlock: 0x9D8u);
  if ( v0 != nullptr )
    return C_BeamSpotLight::C_BeamSpotLight(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10060E60
// Name: private: void C_BeamSpotLight::SpotlightDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BeamSpotLight::SpotlightDestroy(C_BeamSpotLight *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  C_BaseEntity **v8; // eax

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
      v8 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        C_BaseEntity::Remove(this: *v8);
      else
        C_BaseEntity::Remove(this: nullptr);
      this->m_hSpotlight.m_Index = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060ED0
// Name: public: virtual void C_BeamSpotLight::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BeamSpotLight::Release(C_BeamSpotLight *this)
{
  C_BeamSpotLight::SpotlightDestroy(this: (C_BeamSpotLight *)((char *)this - 8));
  C_BaseEntity::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x10060EF0
// Name: private: void C_BeamSpotLight::SpotlightCreate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BeamSpotLight::SpotlightCreate(C_BeamSpotLight *this@<ecx>, int a2@<edi>)
{
  C_Beam *v3; // edi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // ecx
  float m_flHDRColorScale; // xmm0_4
  unsigned int v7; // eax
  unsigned __int8 r; // dl
  unsigned __int8 b; // bl
  IHandleEntity *v10; // eax
  unsigned __int8 g; // cl
  unsigned int v12; // ecx
  IHandleEntity *v13; // eax
  int m_nHaloIndex; // ecx
  unsigned int v15; // ecx
  IHandleEntity *v16; // ecx
  unsigned int v17; // ecx
  IHandleEntity *v18; // ecx
  float m_flSpotlightGoalWidth; // xmm0_4
  unsigned int v20; // ecx
  C_Beam *v21; // eax
  unsigned int v22; // ecx
  C_BaseEntity *v23; // eax
  unsigned int v24; // ecx
  IHandleEntity *v25; // ecx
  unsigned int v26; // ecx
  C_Beam *v27; // edi
  const Vector *v28; // eax
  Vector result; // [esp+Ch] [ebp-10h] BYREF
  CBaseHandle v30; // [esp+18h] [ebp-4h] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  this->m_vSpotlightTargetPos = *C_BeamSpotLight::SpotlightCurrentPos(
                                   this,
                                   a2: COERCE_FLOAT(&savedregs),
                                   a3: a2,
                                   a4: (int)this,
                                   &result);
  v3 = C_Beam::BeamCreate(pSpriteName: "sprites/glow_test02.vmt", width: this->m_flSpotlightGoalWidth);
  CBaseEntityList::AddNonNetworkableEntity(this: (CBaseEntityList *)cl_entitylist.m_Index, result: &v30, pEnt: v3);
  if ( v3 != nullptr )
    this->m_hSpotlight.m_Index = v3->GetRefEHandle(this: v3)->m_Index;
  else
    this->m_hSpotlight.m_Index = -1;
  m_Index = this->m_hSpotlight.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  m_flHDRColorScale = this->m_flHDRColorScale;
  if ( *(float *)&m_pEntity[609].__vftable != m_flHDRColorScale )
    *(float *)&m_pEntity[609].__vftable = m_flHDRColorScale;
  v7 = this->m_hSpotlight.m_Index;
  r = this->m_clrRender.m_Value.r;
  b = this->m_clrRender.m_Value.b;
  if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    v10 = nullptr;
  else
    v10 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  g = this->m_clrRender.m_Value.g;
  if ( LOBYTE(v10[27].__vftable) != r )
    LOBYTE(v10[27].__vftable) = r;
  if ( BYTE1(v10[27].__vftable) != g )
    BYTE1(v10[27].__vftable) = g;
  if ( BYTE2(v10[27].__vftable) != b )
    BYTE2(v10[27].__vftable) = b;
  v12 = this->m_hSpotlight.m_Index;
  if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
    v13 = nullptr;
  else
    v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
  m_nHaloIndex = this->m_nHaloIndex;
  if ( v13[614].__vftable != (IHandleEntity_vtbl *)m_nHaloIndex )
    v13[614].__vftable = (IHandleEntity_vtbl *)m_nHaloIndex;
  v15 = this->m_hSpotlight.m_Index;
  if ( v15 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
    v16 = nullptr;
  else
    v16 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
  if ( *(float *)&v16[640].__vftable != 60.0 )
    v16[640].__vftable = (IHandleEntity_vtbl *)1114636288;
  v17 = this->m_hSpotlight.m_Index;
  if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
    v18 = nullptr;
  else
    v18 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
  m_flSpotlightGoalWidth = this->m_flSpotlightGoalWidth;
  if ( m_flSpotlightGoalWidth > 102.3 )
    m_flSpotlightGoalWidth = 102.3;
  if ( *(float *)&v18[638].__vftable != m_flSpotlightGoalWidth )
    *(float *)&v18[638].__vftable = m_flSpotlightGoalWidth;
  v20 = this->m_hSpotlight.m_Index;
  if ( v20 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
    v21 = nullptr;
  else
    v21 = (C_Beam *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
  C_Beam::SetBeamFlags(this: v21, flags: 640);
  v22 = this->m_hSpotlight.m_Index;
  if ( v22 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber != HIWORD(v22) )
    v23 = nullptr;
  else
    v23 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity;
  C_BaseEntity::SetRenderAlpha(this: v23, a: 64);
  v24 = this->m_hSpotlight.m_Index;
  if ( v24 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
    v25 = nullptr;
  else
    v25 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
  if ( *(float *)&v25[641].__vftable != 0.0 )
    v25[641].__vftable = nullptr;
  v26 = this->m_hSpotlight.m_Index;
  if ( v26 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_SerialNumber != HIWORD(v26) )
    v27 = nullptr;
  else
    v27 = (C_Beam *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_pEntity;
  v28 = this->GetAbsOrigin(this);
  C_Beam::PointsInit(this: v27, start: v28, end: &this->m_vSpotlightTargetPos);
}

//------------------------------------------------------------------------------
// Address: 0x10061200
// Name: private: void C_BeamSpotLight::ComputeRenderInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BeamSpotLight::ComputeRenderInfo(C_BeamSpotLight *this)
{
  float m_flSpotlightMaxLength; // xmm1_4
  float m_flSpotlightCurLength; // xmm0_4
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  float v6; // xmm0_4
  unsigned int v7; // eax
  unsigned int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  unsigned int v11; // ecx
  IHandleEntity *v12; // ecx
  float v13; // xmm0_4
  unsigned __int8 r; // bl
  float v15; // xmm0_4
  int v16; // ecx
  int v17; // edx
  dlight_t *m_pDynamicLight; // eax
  const Vector *v19; // eax
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  dlight_t *v23; // eax
  ColorRGBExp32 color; // [esp+4h] [ebp-8h]
  unsigned __int8 c_1; // [esp+9h] [ebp-3h]
  unsigned __int8 c_2; // [esp+Ah] [ebp-2h]

  m_flSpotlightMaxLength = this->m_flSpotlightMaxLength;
  m_flSpotlightCurLength = this->m_flSpotlightCurLength;
  if ( m_flSpotlightCurLength > (float)(m_flSpotlightMaxLength * 2.0) )
  {
    C_BaseEntity::SetRenderAlpha(this, a: 0);
    m_Index = this->m_hSpotlight.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v6 = this->m_flSpotlightMaxLength;
      goto LABEL_15;
    }
    goto LABEL_5;
  }
  if ( m_flSpotlightCurLength <= m_flSpotlightMaxLength )
  {
    C_BaseEntity::SetRenderAlpha(this, a: 1);
    v8 = this->m_hSpotlight.m_Index;
    if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
    v6 = this->m_flSpotlightCurLength;
  }
  else
  {
    C_BaseEntity::SetRenderAlpha(
      this,
      a: (unsigned __int8)(int)(float)(1.0
                                  - (float)((float)(m_flSpotlightCurLength - m_flSpotlightMaxLength)
                                          / m_flSpotlightMaxLength)));
    v7 = this->m_hSpotlight.m_Index;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    {
LABEL_5:
      v6 = this->m_flSpotlightMaxLength;
      m_pEntity = nullptr;
      goto LABEL_15;
    }
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    v6 = this->m_flSpotlightMaxLength;
  }
LABEL_15:
  if ( *(float *)&m_pEntity[639].__vftable != v6 )
    *(float *)&m_pEntity[639].__vftable = v6;
  v9 = (float)(this->m_flSpotlightCurLength / this->m_flSpotlightMaxLength) * this->m_flSpotlightGoalWidth;
  v10 = 102.3;
  if ( v9 >= 0.0 )
  {
    if ( v9 > 102.3 )
      v9 = 102.3;
  }
  else
  {
    v9 = 0.0;
  }
  v11 = this->m_hSpotlight.m_Index;
  if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
    v12 = nullptr;
  else
    v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
  if ( v9 <= 102.3 )
    v10 = v9;
  if ( *(float *)&v12[638].__vftable != v10 )
    *(float *)&v12[638].__vftable = v10;
  if ( this->m_bHasDynamicLight )
  {
    v13 = v9 * 1.8;
    this->m_flLightScale = v13;
    if ( v13 > 0.0 )
    {
      c_2 = this->m_clrRender.m_Value.b;
      r = this->m_clrRender.m_Value.r;
      c_1 = this->m_clrRender.m_Value.g;
      v15 = (float)C_BaseEntity::GetRenderAlpha(this) * 0.0039215689;
      v16 = (int)(float)((float)c_1 * v15);
      v17 = (int)(float)((float)c_2 * v15);
      color.r = (int)(float)((float)r * v15);
      color.g = v16;
      *(_WORD *)&color.b = (unsigned __int8)v17;
      if ( color.r != 0 || (_BYTE)v16 != 0 || (_BYTE)v17 != 0 )
      {
        m_pDynamicLight = this->m_pDynamicLight;
        if ( m_pDynamicLight == nullptr || m_pDynamicLight->key != this->index )
          this->m_pDynamicLight = effects->CL_AllocDlight(this: effects, a2: this->index);
        this->m_pDynamicLight->radius = this->m_flLightScale * 3.0;
        v19 = this->GetAbsOrigin(this);
        z = v19->z;
        x = v19->x;
        y = v19->y;
        v23 = this->m_pDynamicLight;
        v23->origin.z = z + 5.0;
        v23->origin.x = x;
        v23->origin.y = y;
        this->m_pDynamicLight->die = *(float *)(gpGlobals.m_Index + 12) + 0.050000001;
        this->m_pDynamicLight->color = color;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061510
// Name: public: virtual void C_BeamSpotLight::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BeamSpotLight::ClientThink(C_BeamSpotLight *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  float v3; // xmm2_4
  float m_flSpotlightCurLength; // xmm1_4
  float x; // ecx
  C_BeamSpotLight *v7; // ecx
  int v8; // eax
  float v9; // xmm0_4
  int v10; // eax
  float v11; // xmm0_4
  float *v12; // eax
  bool v13; // zf
  char *v14; // eax
  int v15; // edx
  _DWORD *v16; // ecx
  float v17; // ecx
  C_BaseEntity *m_pEntity; // ebx
  const Vector *v19; // edi
  float v20; // eax
  float *v21; // ecx
  float v22; // xmm0_4
  float *v23; // eax
  float v24; // ecx
  C_Beam *v25; // eax
  unsigned int v26; // ecx
  int v28; // [esp+4h] [ebp-24h]
  Vector dir; // [esp+Ch] [ebp-1Ch] BYREF
  QAngle angles; // [esp+18h] [ebp-10h] BYREF
  float dt; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v3 = *(float *)(gpGlobals.m_Index + 12);
  m_flSpotlightCurLength = this->m_flSpotlightCurLength;
  dt = v3 - m_flSpotlightCurLength;
  if ( m_flSpotlightCurLength == 0.0 )
    dt = 0.0;
  this->m_flSpotlightCurLength = v3;
  x = this->m_vSpotlightDir.x;
  if ( x != NAN
    && g_pEntityList->m_EntPtrArray[LOWORD(x)].m_SerialNumber == HIWORD(LODWORD(x))
    && g_pEntityList->m_EntPtrArray[LOWORD(x)].m_pEntity != nullptr )
  {
    if ( LOBYTE(this->m_nHaloIndex) == 0 )
    {
      C_BeamSpotLight::SpotlightDestroy(this: (C_BeamSpotLight *)((char *)this - 12));
      (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 3) + 456))(a1: (char *)this - 12, a2: -1082130432);
      return;
    }
  }
  else
  {
    v7 = (C_BeamSpotLight *)((char *)this - 12);
    if ( LOBYTE(this->m_nHaloIndex) == 0 )
    {
      ((void (__stdcall *)(int))v7->SetNextClientThink)(a1: -1082130432);
      return;
    }
    C_BeamSpotLight::SpotlightCreate(this: v7, a2: a3);
  }
  v28 = a3;
  if ( *((float *)&this->m_bIsBlurred + 1) != 0.0 )
  {
    v8 = (*(int (__thiscall **)(char *, int))(*((_DWORD *)this - 3) + 44))(a1: (char *)this - 12, a2: a3);
    *(_QWORD *)&angles.x = *(_QWORD *)v8;
    v9 = *((float *)&this->m_bIsBlurred + 1) * dt;
    angles.z = *(float *)(v8 + 8);
    v10 = *(_DWORD *)&this->m_bIsBlurred;
    v11 = v9 + *(&angles.x + v10);
    v12 = &angles.x + v10;
    *v12 = v11;
    v13 = LODWORD(this->m_flLightScale) == 0;
    *v12 = (float)(unsigned __int16)(int)(float)(v11 * 182.04445) * 0.0054931641;
    if ( v13 )
    {
      v14 = (char *)MemAlloc_Alloc(nSize: 0x400u);
      if ( v14 != nullptr )
      {
        v15 = 63;
        v16 = v14 + 8;
        do
        {
          *(v16 - 2) = 0;
          *(v16 - 1) = 0;
          *v16 = 0;
          v16[1] = -1082130432;
          v16 += 4;
          --v15;
        }
        while ( v15 >= 0 );
      }
      else
      {
        v14 = nullptr;
      }
      LODWORD(this->m_flLightScale) = v14;
    }
    C_BaseEntity::SetAbsAngles(this: (C_BeamSpotLight *)((char *)this - 12), absAngles: &angles);
  }
  this->m_vSpotlightTargetPos = *C_BeamSpotLight::SpotlightCurrentPos(
                                   this: (C_BeamSpotLight *)((char *)this - 12),
                                   a2: COERCE_FLOAT(&savedregs),
                                   a3,
                                   a4: (int)this,
                                   result: (Vector *)&angles);
  v17 = this->m_vSpotlightDir.x;
  if ( v17 == NAN || g_pEntityList->m_EntPtrArray[LOWORD(v17)].m_SerialNumber != HIWORD(LODWORD(v17)) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(v17)].m_pEntity;
  v19 = (const Vector *)(*(int (__thiscall **)(char *, int, int))(*((_DWORD *)this - 3) + 40))(
                          a1: (char *)this - 12,
                          a2,
                          a3: v28);
  C_BaseEntity::SetNetworkOrigin(this: m_pEntity, org: v19);
  C_BaseEntity::SetLocalOrigin(this: m_pEntity, origin: v19);
  v20 = this->m_vSpotlightDir.x;
  if ( v20 == NAN || g_pEntityList->m_EntPtrArray[LOWORD(v20)].m_SerialNumber != HIWORD(LODWORD(v20)) )
    v21 = nullptr;
  else
    v21 = (float *)g_pEntityList->m_EntPtrArray[LOWORD(v20)].m_pEntity;
  v22 = this->m_vSpotlightTargetPos.x;
  if ( v22 != v21[646] || this->m_vSpotlightTargetPos.y != v21[647] || this->m_vSpotlightTargetPos.z != v21[648] )
  {
    v21[646] = v22;
    v21[647] = this->m_vSpotlightTargetPos.y;
    v21[648] = this->m_vSpotlightTargetPos.z;
  }
  v23 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40))(a1: (char *)this - 12);
  dir.x = this->m_vSpotlightTargetPos.x - *v23;
  dir.y = this->m_vSpotlightTargetPos.y - v23[1];
  dir.z = this->m_vSpotlightTargetPos.z - v23[2];
  this->m_vSpotlightDir.y = this->m_vSpotlightDir.y * 0.6 + VectorNormalize(vec: &dir) * 0.4;
  C_BeamSpotLight::ComputeRenderInfo(this: (C_BeamSpotLight *)((char *)this - 12));
  v24 = this->m_vSpotlightDir.x;
  if ( v24 == NAN || g_pEntityList->m_EntPtrArray[LOWORD(v24)].m_SerialNumber != HIWORD(LODWORD(v24)) )
    v25 = nullptr;
  else
    v25 = (C_Beam *)g_pEntityList->m_EntPtrArray[LOWORD(v24)].m_pEntity;
  C_Beam::RelinkBeam(this: v25);
  v26 = *(_DWORD *)&this->m_iParentAttachment;
  if ( (v26 == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_SerialNumber != HIWORD(v26)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_pEntity == nullptr)
    && *((float *)&this->m_bIsBlurred + 1) == 0.0 )
  {
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 3) + 456))(a1: (char *)this - 12, a2: -1082130432);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411720
// Name: DT_BeamSpotlight::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BeamSpotlight::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BeamSpotlight::g_RecvTable);
  return atexit(func: DT_BeamSpotlight::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411740
// Name: DT_BeamSpotlight::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BeamSpotlight::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BeamSpotlight::ignored>();
  DT_BeamSpotlight::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104300D0
// Name: DT_BeamSpotlight::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BeamSpotlight::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BeamSpotlight::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10060DF0
// Name: _C_BeamSpotLight_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BeamSpotLight_CreateObject(int entnum, int serialNum)
{
  C_BeamSpotLight *v2; // eax
  C_BeamSpotLight *v3; // eax
  C_BeamSpotLight *v4; // esi

  v2 = (C_BeamSpotLight *)C_BaseEntity::operator new(stAllocateBlock: 0x9D8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BeamSpotLight::C_BeamSpotLight(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411750
// Name: _dynamic_initializer_for__g_Cbeam_spotlightFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cbeam_spotlightFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BeamSpotLight *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "beam_spotlight",
             a3: "C_BeamSpotLight",
             a4: 2520,
             a5: CC_BeamSpotLightFactory);
  __g_C_BeamSpotLightClientClass.m_pMapClassname = "beam_spotlight";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411780
// Name: _dynamic_initializer_for____g_C_BreakablePropClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BreakablePropClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BreakablePropClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BreakablePropClientClass;
  return result;
}
