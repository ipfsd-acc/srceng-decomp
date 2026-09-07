// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_env_ambient_light.cpp
// Functions: 17
// ============================================================

#include "game\client\c_env_ambient_light.h"

//------------------------------------------------------------------------------
// Address: 0x10066E10
// Name: public: virtual class ClientClass __near * C_EnvAmbientLight::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvAmbientLight::GetClientClass(C_EnvAmbientLight *this)
{
  return &__g_C_EnvAmbientLightClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10066EB0
// Name: protected: virtual void C_EnvAmbientLight::AddToPersonalSpatialEntityMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvAmbientLight::AddToPersonalSpatialEntityMgr(C_EnvAmbientLight *this)
{
  CSpatialEntityMgr::AddSpatialEntity(this: &s_EnvAmbientLightMgr, pSpatialEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x10066EC0
// Name: protected: virtual void C_EnvAmbientLight::RemoveFromPersonalSpatialEntityMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvAmbientLight::RemoveFromPersonalSpatialEntityMgr(C_EnvAmbientLight *this)
{
  CSpatialEntityMgr::RemoveSpatialEntity(this: &s_EnvAmbientLightMgr, pSpatialEntity: this);
}

//------------------------------------------------------------------------------
// Address: 0x10066ED0
// Name: public: class Vector C_SpatialEntityTemplate<class Vector>::BlendedValue(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_SpatialEntityTemplate<Vector>::BlendedValue(C_SpatialEntityTemplate<Vector> *this, Vector *result)
{
  Vector *v2; // eax
  float v3; // xmm3_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v2 = result;
  if ( C_SpatialEntityTemplate<Vector>::m_ForcedInfluence > 0.0 )
  {
    if ( C_SpatialEntityTemplate<Vector>::m_ForcedInfluence < 128.0 )
    {
      v3 = (float)(128.0 - C_SpatialEntityTemplate<Vector>::m_ForcedInfluence) * 0.0078125;
      v4 = (float)(C_SpatialEntityTemplate<Vector>::m_ForcedValue.y * (float)(1.0 - v3))
         + (float)(C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.y * v3);
      v5 = (float)(C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.z * v3)
         + (float)(C_SpatialEntityTemplate<Vector>::m_ForcedValue.z * (float)(1.0 - v3));
      result->x = (float)(C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.x * v3)
                + (float)(C_SpatialEntityTemplate<Vector>::m_ForcedValue.x * (float)(1.0 - v3));
      result->y = v4;
      result->z = v5;
    }
    else
    {
      *result = C_SpatialEntityTemplate<Vector>::m_ForcedValue;
    }
  }
  else
  {
    *result = C_SpatialEntityTemplate<Vector>::m_AccumulatedValue;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10066FB0
// Name: public: virtual void C_SpatialEntityTemplate<class Vector>::ResetAccumulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpatialEntityTemplate<Vector>::ResetAccumulation(C_SpatialEntityTemplate<Vector> *this)
{
  C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.x = 0.0;
  C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.y = 0.0;
  C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.z = 0.0;
  C_SpatialEntityTemplate<Vector>::m_ForcedValue.x = 0.0;
  C_SpatialEntityTemplate<Vector>::m_ForcedValue.y = 0.0;
  C_SpatialEntityTemplate<Vector>::m_ForcedValue.z = 0.0;
  C_SpatialEntityTemplate<Vector>::m_ForcedMinFalloff = this->m_minFalloff;
  C_SpatialEntityTemplate<Vector>::m_ForcedInfluence = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10067000
// Name: public: virtual void C_SpatialEntityTemplate<class Vector>::Accumulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpatialEntityTemplate<Vector>::Accumulate(C_SpatialEntityTemplate<Vector> *this)
{
  float m_flWeight; // xmm0_4
  float v2; // xmm2_4
  float v3; // xmm3_4

  if ( this->m_flInfluence > C_SpatialEntityTemplate<Vector>::m_ForcedInfluence )
  {
    C_SpatialEntityTemplate<Vector>::m_ForcedValue = this->m_Value;
    C_SpatialEntityTemplate<Vector>::m_ForcedMinFalloff = this->m_minFalloff;
    C_SpatialEntityTemplate<Vector>::m_ForcedInfluence = this->m_flInfluence;
  }
  m_flWeight = this->m_flWeight;
  v2 = this->m_Value.y * m_flWeight;
  v3 = this->m_Value.z * m_flWeight;
  C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.x = C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.x
                                                        + (float)(m_flWeight * this->m_Value.x);
  C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.y = C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.y + v2;
  C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.z = C_SpatialEntityTemplate<Vector>::m_AccumulatedValue.z + v3;
}

//------------------------------------------------------------------------------
// Address: 0x100670D0
// Name: public: virtual void C_EnvAmbientLight::ApplyAccumulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvAmbientLight::ApplyAccumulation(C_EnvAmbientLight *this)
{
  Vector rgbVal; // [esp+Ch] [ebp-Ch] BYREF

  C_SpatialEntityTemplate<Vector>::BlendedValue(this, result: &rgbVal);
  if ( (_S6_12 & 1) == 0 )
  {
    _S6_12 |= 1u;
    ConVarRef::ConVarRef(this: &mat_ambient_light_r, pName: "mat_ambient_light_r");
  }
  if ( (_S6_12 & 2) == 0 )
  {
    _S6_12 |= 2u;
    ConVarRef::ConVarRef(this: &mat_ambient_light_g, pName: "mat_ambient_light_g");
  }
  if ( (_S6_12 & 4) == 0 )
  {
    _S6_12 |= 4u;
    ConVarRef::ConVarRef(this: &mat_ambient_light_b, pName: "mat_ambient_light_b");
  }
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&mat_ambient_light_r) )
    ((void (__stdcall *)(_DWORD))mat_ambient_light_r.m_pConVar->SetValue_3)(a1: LODWORD(rgbVal.x));
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&mat_ambient_light_g) )
    ((void (__stdcall *)(_DWORD))mat_ambient_light_g.m_pConVar->SetValue_3)(a1: LODWORD(rgbVal.y));
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&mat_ambient_light_b) )
    ((void (__stdcall *)(_DWORD))mat_ambient_light_b.m_pConVar->SetValue_3)(a1: LODWORD(rgbVal.z));
}

//------------------------------------------------------------------------------
// Address: 0x100671C0
// Name: public: void CountdownTimer::Start(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CountdownTimer::Start(CountdownTimer *this, float duration)
{
  double v3; // st7
  float v4; // [esp+8h] [ebp-4h]

  v3 = CountdownTimer::Now((CEffectsClient *)this) + duration;
  if ( this->m_timestamp.m_Value != v3 )
  {
    this->NetworkStateChanged(this, a2: &this->m_timestamp);
    v4 = v3;
    this->m_timestamp.m_Value = v4;
  }
  if ( this->m_duration.m_Value != duration )
  {
    this->NetworkStateChanged(this, a2: &this->m_duration);
    this->m_duration.m_Value = duration;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067230
// Name: public: C_EnvAmbientLight::C_EnvAmbientLight(void)
// Source: json
//------------------------------------------------------------------------------
C_EnvAmbientLight *__thiscall C_EnvAmbientLight::C_EnvAmbientLight(C_EnvAmbientLight *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx

  C_BaseEntity::C_BaseEntity(this);
  this->C_SpatialEntityTemplate<Vector>::C_SpatialEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvAmbientLight_vtbl *)&C_EnvAmbientLight::`vftable'{for `IClientUnknown'};
  this->C_SpatialEntityTemplate<Vector>::C_SpatialEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvAmbientLight::`vftable'{for `IClientRenderable'};
  this->C_SpatialEntityTemplate<Vector>::C_SpatialEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvAmbientLight::`vftable'{for `IClientNetworkable'};
  this->C_SpatialEntityTemplate<Vector>::C_SpatialEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvAmbientLight::`vftable'{for `IClientThinkable'};
  this->C_SpatialEntityTemplate<Vector>::C_SpatialEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvAmbientLight::`vftable';
  this->m_colorTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_colorTimer.__vftable;
  this->m_colorTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_colorTimer.m_duration);
  v3 = this->m_colorTimer.__vftable;
  this->m_colorTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_colorTimer, a2: &this->m_colorTimer.m_timestamp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100672D0
// Name: public: virtual void C_EnvAmbientLight::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvAmbientLight::ClientThink(C_EnvAmbientLight *this)
{
  float *p_z; // edi
  float v3; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // [esp+8h] [ebp-4h]

  C_SpatialEntity::ClientThink(this);
  p_z = &this->m_vecTargetColor.z;
  if ( this->m_vecTargetColor.z > 0.0 )
  {
    if ( CountdownTimer::Now(this: (CEffectsClient *)&this->m_vecTargetColor) <= this->m_vecTargetColor.z )
    {
      v3 = 0.0;
      if ( this->m_vecTargetColor.z > 0.0 )
      {
        v3 = 0.0;
        v7 = this->m_vecTargetColor.z - CountdownTimer::Now(this: (CEffectsClient *)&this->m_vecTargetColor);
        v4 = v7 / this->m_vecTargetColor.y;
        if ( v4 >= 0.0 )
        {
          v3 = 1.0;
          if ( v4 <= 1.0 )
            v3 = v7 / this->m_vecTargetColor.y;
        }
      }
      v5 = this->m_vecStartColor.y - (float)((float)(this->m_vecStartColor.y - this->m_Value.z) * v3);
      v6 = this->m_vecStartColor.z - (float)((float)(this->m_vecStartColor.z - *((float *)&this->m_Value + 3)) * v3);
      *(float *)&this->m_bEnabled = this->m_vecStartColor.x
                                  - (float)((float)(this->m_vecStartColor.x - this->m_Value.y) * v3);
      this->m_flWeight = v5;
      this->m_flInfluence = v6;
    }
    else
    {
      *(float *)&this->m_bEnabled = this->m_vecStartColor.x;
      this->m_flWeight = this->m_vecStartColor.y;
      this->m_flInfluence = this->m_vecStartColor.z;
      if ( *p_z != -1.0 )
      {
        (*(void (__thiscall **)(Vector *, float *))(LODWORD(this->m_vecTargetColor.x) + 4))(
          a1: &this->m_vecTargetColor,
          a2: &this->m_vecTargetColor.z);
        *p_z = -1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067480
// Name: public: virtual char const __near * CSpatialEntityMgr::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSpatialEntityMgr::Name(CSpatialEntityMgr *this)
{
  return "Spatial Entity Mgr";
}

//------------------------------------------------------------------------------
// Address: 0x10411BC0
// Name: DT_EnvAmbientLight::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvAmbientLight::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvAmbientLight::g_RecvTable);
  return atexit(func: DT_EnvAmbientLight::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411BE0
// Name: DT_EnvAmbientLight::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvAmbientLight::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvAmbientLight::ignored>();
  DT_EnvAmbientLight::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104301C0
// Name: DT_EnvAmbientLight::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvAmbientLight::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvAmbientLight::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10067430
// Name: _C_EnvAmbientLight_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvAmbientLight_CreateObject(int entnum, int serialNum)
{
  C_EnvAmbientLight *v2; // eax
  C_EnvAmbientLight *v3; // eax
  C_EnvAmbientLight *v4; // esi

  v2 = (C_EnvAmbientLight *)C_BaseEntity::operator new(stAllocateBlock: 0xAE0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EnvAmbientLight::C_EnvAmbientLight(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411BF0
// Name: _dynamic_initializer_for____g_C_EnvDOFControllerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvDOFControllerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvDOFControllerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvDOFControllerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104301D0
// Name: _dynamic_atexit_destructor_for__s_EnvAmbientLightMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EnvAmbientLightMgr__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EnvAmbientLightMgr.m_SpatialEntities);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &s_EnvAmbientLightMgr);
}
