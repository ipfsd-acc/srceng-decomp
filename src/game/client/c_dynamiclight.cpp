// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_dynamiclight.cpp
// Functions: 10
// ============================================================

#include "game\client\c_dynamiclight.h"

//------------------------------------------------------------------------------
// Address: 0x10062DF0
// Name: public: virtual class ClientClass __near * C_DynamicLight::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_DynamicLight::GetClientClass(C_DynamicLight *this)
{
  return &__g_C_DynamicLightClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10062F30
// Name: public: virtual void C_DynamicLight::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DynamicLight::OnDataChanged(C_DynamicLight *this, DataUpdateType_t updateType)
{
  if ( updateType == DATA_UPDATE_CREATED )
    (*(void (__stdcall **)(_DWORD))(*((_DWORD *)this - 2) + 456))(a1: *(float *)(gpGlobals.m_Index + 12) + 0.05);
  C_BaseEntity::OnDataChanged(this, type: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10062F80
// Name: public: virtual void C_DynamicLight::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DynamicLight::Release(C_DynamicLight *this)
{
  float m_OuterAngle; // eax
  float m_SpotRadius; // eax

  m_OuterAngle = this->m_OuterAngle;
  if ( m_OuterAngle != 0.0 )
  {
    *(float *)(LODWORD(m_OuterAngle) + 24) = *(float *)(gpGlobals.m_Index + 12);
    this->m_OuterAngle = 0.0;
  }
  m_SpotRadius = this->m_SpotRadius;
  if ( m_SpotRadius != 0.0 )
  {
    *(float *)(LODWORD(m_SpotRadius) + 24) = *(float *)(gpGlobals.m_Index + 12);
    this->m_SpotRadius = 0.0;
  }
  C_BaseEntity::Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x10063060
// Name: public: virtual void C_DynamicLight::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DynamicLight::ClientThink(C_DynamicLight *this)
{
  const QAngle *v2; // eax
  float m_InnerAngle; // eax
  dlight_t *v4; // eax
  char v5; // cl
  char v6; // dl
  float *v7; // eax
  float v8; // ecx
  float v9; // xmm0_4
  float v10; // eax
  int (__thiscall *v11)(char *); // edx
  float *v12; // eax
  const Vector *v13; // eax
  float fraction; // xmm1_4
  float v15; // ecx
  float v16; // xmm0_4
  float v17; // xmm1_4
  unsigned __int8 v18; // cl
  unsigned __int8 v19; // dl
  float m_OuterAngle; // eax
  CGameTrace pm; // [esp+10h] [ebp-70h] BYREF
  Vector end; // [esp+64h] [ebp-1Ch] BYREF
  Vector forward; // [esp+70h] [ebp-10h] BYREF
  float v24; // [esp+7Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+80h] [ebp+0h] BYREF

  v2 = (const QAngle *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 44))(a1: (char *)this - 12);
  AngleVectors(angles: v2, &forward);
  m_InnerAngle = this->m_InnerAngle;
  if ( (this->m_CalcAbsoluteVelocityMutex.m_depth & 2) != 0 )
  {
    if ( m_InnerAngle != 0.0 )
    {
      *(float *)(LODWORD(m_InnerAngle) + 24) = *(float *)(gpGlobals.m_Index + 12);
      this->m_InnerAngle = 0.0;
    }
  }
  else
  {
    if ( m_InnerAngle == 0.0 || *(_DWORD *)(LODWORD(m_InnerAngle) + 36) != DWORD1(this->m_pfnTouch) )
    {
      v4 = effects->CL_AllocDlight(this: effects, a2: DWORD1(this->m_pfnTouch));
      LODWORD(this->m_InnerAngle) = v4;
      v4->minlight = 0.0;
    }
    *(_DWORD *)(LODWORD(this->m_InnerAngle) + 40) = BYTE1(this->m_CalcAbsoluteVelocityMutex.m_depth);
    *(float *)(LODWORD(this->m_InnerAngle) + 16) = *(float *)&this->m_bIsBlurred;
    *(_DWORD *)LODWORD(this->m_InnerAngle) = LOBYTE(this->m_CalcAbsoluteVelocityMutex.m_depth);
    if ( this->m_Radius > 0.0 )
      *(_DWORD *)LODWORD(this->m_InnerAngle) |= 1u;
    v5 = BYTE1(this->index);
    v6 = BYTE2(this->index);
    *(_BYTE *)(LODWORD(this->m_InnerAngle) + 20) = this->index;
    *(_BYTE *)(LODWORD(this->m_InnerAngle) + 21) = v5;
    *(_BYTE *)(LODWORD(this->m_InnerAngle) + 22) = v6;
    *(_BYTE *)(LODWORD(this->m_InnerAngle) + 23) = *(&this->m_bIsBlurred + 4);
    v7 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40))(a1: (char *)this - 12);
    v8 = this->m_InnerAngle;
    *(float *)(LODWORD(v8) + 4) = *v7;
    *(float *)(LODWORD(v8) + 8) = v7[1];
    *(float *)(LODWORD(v8) + 12) = v7[2];
    *(float *)(LODWORD(this->m_InnerAngle) + 56) = *(float *)&this->m_Flags;
    *(float *)(LODWORD(this->m_InnerAngle) + 60) = this->m_Radius;
    v9 = *(float *)(gpGlobals.m_Index + 12) + 1000000.0;
    *(float *)(LODWORD(this->m_InnerAngle) + 24) = v9;
    *(Vector *)(LODWORD(this->m_InnerAngle) + 44) = forward;
  }
  if ( this->m_Radius <= 0.0 || (this->m_CalcAbsoluteVelocityMutex.m_depth & 1) != 0 )
  {
    m_OuterAngle = this->m_OuterAngle;
    if ( m_OuterAngle != 0.0 )
    {
      *(float *)(LODWORD(m_OuterAngle) + 24) = *(float *)(gpGlobals.m_Index + 12);
      goto LABEL_20;
    }
  }
  else
  {
    v10 = this->m_OuterAngle;
    if ( v10 == 0.0 || *(_DWORD *)(LODWORD(v10) + 36) != -DWORD1(this->m_pfnTouch) )
      LODWORD(this->m_OuterAngle) = ((int (__stdcall *)(int))effects->CL_AllocDlight)(a1: -DWORD1(this->m_pfnTouch));
    v11 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40);
    v24 = *(float *)&this->m_bIsBlurred;
    v12 = (float *)v11(a1: (char *)this - 12);
    end.x = (float)(v24 * forward.x) + *v12;
    end.y = (float)(forward.y * v24) + v12[1];
    end.z = (float)(forward.z * v24) + v12[2];
    C_BaseEntity::PushEnableAbsRecomputations(bEnable: false);
    v13 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 40))(a1: (char *)this - 12);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: v13,
      vecAbsEnd: &end,
      mask: 0x2000Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &pm);
    C_BaseEntity::PopEnableAbsRecomputations();
    *(Vector *)(LODWORD(this->m_OuterAngle) + 4) = pm.endpos;
    fraction = pm.fraction;
    v15 = this->m_OuterAngle;
    if ( pm.fraction == 1.0 )
    {
      *(float *)(LODWORD(v15) + 24) = *(float *)(gpGlobals.m_Index + 12);
LABEL_20:
      this->m_OuterAngle = 0.0;
      goto LABEL_21;
    }
    *(_DWORD *)(LODWORD(v15) + 40) = BYTE1(this->m_CalcAbsoluteVelocityMutex.m_depth);
    *(_DWORD *)LODWORD(this->m_OuterAngle) = this->m_CalcAbsoluteVelocityMutex.m_depth & 0xC | 2;
    v16 = (float)(1.0 - fraction) * (float)(1.0 - fraction);
    *(float *)(LODWORD(this->m_OuterAngle) + 16) = *(float *)&this->m_Exponent;
    v17 = *(float *)(gpGlobals.m_Index + 12) + 1000000.0;
    *(float *)(LODWORD(this->m_OuterAngle) + 24) = v17;
    v18 = BYTE1(this->index);
    v19 = BYTE2(this->index);
    *(_BYTE *)(LODWORD(this->m_OuterAngle) + 20) = (int)(float)((float)LOBYTE(this->index) * v16);
    *(_BYTE *)(LODWORD(this->m_OuterAngle) + 21) = (int)(float)((float)v18 * v16);
    *(_BYTE *)(LODWORD(this->m_OuterAngle) + 22) = (int)(float)((float)v19 * v16);
    *(_BYTE *)(LODWORD(this->m_OuterAngle) + 23) = *(&this->m_bIsBlurred + 4);
    *(Vector *)(LODWORD(this->m_OuterAngle) + 44) = forward;
    render->TouchLight(this: render, a2: (dlight_t *)LODWORD(this->m_OuterAngle));
  }
LABEL_21:
  (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 3) + 456))(
    a1: (char *)this - 12,
    a2: *(float *)(gpGlobals.m_Index + 12) + 0.001);
}

//------------------------------------------------------------------------------
// Address: 0x10411910
// Name: DT_DynamicLight::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DynamicLight::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_DynamicLight::g_RecvTable);
  return atexit(func: DT_DynamicLight::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411930
// Name: DT_DynamicLight::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DynamicLight::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_DynamicLight::ignored>();
  DT_DynamicLight::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430140
// Name: DT_DynamicLight::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DynamicLight::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_DynamicLight::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10062FE0
// Name: _C_DynamicLight_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_DynamicLight_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9A0u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_DynamicLight::`vftable'{for `IClientUnknown'};
  v3[1] = &C_DynamicLight::`vftable'{for `IClientRenderable'};
  v3[2] = &C_DynamicLight::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_DynamicLight::`vftable'{for `IClientThinkable'};
  v3[4] = &C_DynamicLight::`vftable';
  v3[614] = 0;
  v3[615] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10411940
// Name: _dynamic_initializer_for__cl_portal_use_new_dissolve__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_portal_use_new_dissolve__()
{
  ConVar::ConVar(
    this: &cl_portal_use_new_dissolve,
    pName: "cl_portal_use_new_dissolve",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Use new dissolve effect");
  return atexit(func: dynamic_atexit_destructor_for__cl_portal_use_new_dissolve__);
}

//------------------------------------------------------------------------------
// Address: 0x10430150
// Name: _dynamic_atexit_destructor_for__cl_portal_use_new_dissolve__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_portal_use_new_dissolve__()
{
  ConVar::~ConVar(this: &cl_portal_use_new_dissolve);
}
