// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_vehicle_jeep.cpp
// Functions: 16
// ============================================================

#include "game\client\c_vehicle_jeep.h"

//------------------------------------------------------------------------------
// Address: 0x100940F0
// Name: public: virtual class ClientClass __near * C_PropJeep::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PropJeep::GetClientClass(C_PropJeep *this)
{
  return &__g_C_PropJeepClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10094180
// Name: public: C_PropJeep::C_PropJeep(void)
// Source: json
//------------------------------------------------------------------------------
C_PropJeep *__thiscall C_PropJeep::C_PropJeep(C_PropJeep *this)
{
  ConVarRef r_JeepFOV; // [esp+4h] [ebp-8h] BYREF

  C_PropVehicleDriveable::C_PropVehicleDriveable(this);
  this->C_PropVehicleDriveable::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PropJeep_vtbl *)&C_PropJeep::`vftable'{for `IClientUnknown'};
  this->C_PropVehicleDriveable::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PropJeep::`vftable'{for `IClientRenderable'};
  this->C_PropVehicleDriveable::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PropJeep::`vftable'{for `IClientNetworkable'};
  this->C_PropVehicleDriveable::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PropJeep::`vftable'{for `IClientThinkable'};
  this->C_PropVehicleDriveable::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PropJeep::`vftable'{for `C_BaseAnimating'};
  this->C_PropVehicleDriveable::IClientVehicle::IVehicle::__vftable = (IClientVehicle_vtbl *)&C_PropJeep::`vftable'{for `IClientVehicle'};
  this->m_vecEyeSpeed.x = 0.0;
  this->m_vecEyeSpeed.y = 0.0;
  this->m_vecEyeSpeed.z = 0.0;
  this->m_flViewAngleDeltaTime = 0.0;
  this->m_pHeadlight = nullptr;
  ConVarRef::ConVarRef(this: &r_JeepFOV, pName: "r_JeepFOV");
  this->m_ViewSmoothingData.flFOV = r_JeepFOV.m_pConVarState->m_Value.m_fValue;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10094210
// Name: public: virtual void C_PropVehicleDriveable::GetVehicleFOV(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::GetVehicleFOV(C_PropVehicleDriveable *this, float *flFOV)
{
  *flFOV = *((float *)&this->m_pfnThink + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10094220
// Name: public: virtual class IClientVehicle __near * C_PropVehicleDriveable::GetClientVehicle(void)
// Source: json
//------------------------------------------------------------------------------
IClientVehicle *__thiscall C_PropVehicleDriveable::GetClientVehicle(C_PropVehicleDriveable *this)
{
  if ( this != nullptr )
    return &this->IClientVehicle;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10094230
// Name: public: virtual class C_BaseEntity __near * C_PropVehicleDriveable::GetVehicleEnt(void)
// Source: json
//------------------------------------------------------------------------------
C_PropVehicleDriveable *__thiscall C_PropVehicleDriveable::GetVehicleEnt(C_PropVehicleDriveable *this)
{
  return (C_PropVehicleDriveable *)((char *)this - 3256);
}

//------------------------------------------------------------------------------
// Address: 0x10094240
// Name: public: virtual bool C_PropVehicleDriveable::HasGun(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PropVehicleDriveable::HasGun(C_PropVehicleDriveable *this)
{
  return this->m_bHasGun;
}

//------------------------------------------------------------------------------
// Address: 0x10094250
// Name: protected: virtual void C_PropVehicleDriveable::SetVehicleFOV(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleDriveable::SetVehicleFOV(C_PropVehicleDriveable *this, float flFOV)
{
  this->m_flFOV = flFOV;
}

//------------------------------------------------------------------------------
// Address: 0x10094270
// Name: public: virtual bool C_PropJeep::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_PropJeep::Simulate(C_PropJeep *this)
{
  CHeadlightEffect *v2; // eax
  CHeadlightEffect *v3; // eax
  int v4; // eax
  CHeadlightEffect *m_pHeadlight; // edi
  Vector vVector; // [esp+8h] [ebp-3Ch] BYREF
  Vector vecForward; // [esp+14h] [ebp-30h] BYREF
  Vector vecRight; // [esp+20h] [ebp-24h] BYREF
  Vector vecUp; // [esp+2Ch] [ebp-18h] BYREF
  QAngle vAngle; // [esp+38h] [ebp-Ch] BYREF

  if ( this->m_bHeadlightIsOn )
  {
    if ( this->m_pHeadlight == nullptr )
    {
      v2 = (CHeadlightEffect *)MemAlloc_Alloc(nSize: 0x70u);
      if ( v2 != nullptr )
        v3 = CHeadlightEffect::CHeadlightEffect(this: v2);
      else
        v3 = nullptr;
      this->m_pHeadlight = v3;
      if ( v3 == nullptr )
        return 1;
      CFlashlightEffect::TurnOn(this: &v3->CFlashlightEffect);
    }
    v4 = this->LookupAttachment(this: &this->IClientRenderable, a2: "headlight");
    if ( v4 != -1 )
    {
      this->GetAttachment_2(this: &this->IClientRenderable, a2: v4, a3: &vVector, a4: &vAngle);
      AngleVectors(angles: &vAngle, forward: &vecForward, right: &vecRight, up: &vecUp);
      this->m_pHeadlight->UpdateLight(
        this: this->m_pHeadlight,
        a2: &vVector,
        a3: &vecForward,
        a4: &vecRight,
        a5: &vecUp,
        a6: 1000);
      C_BaseAnimating::Simulate(this);
      return 1;
    }
  }
  else
  {
    m_pHeadlight = this->m_pHeadlight;
    if ( m_pHeadlight != nullptr )
    {
      CHeadlightEffect::~CHeadlightEffect(this: this->m_pHeadlight);
      C_BaseEntity::operator delete(pMem: m_pHeadlight);
      this->m_pHeadlight = nullptr;
    }
  }
  C_BaseAnimating::Simulate(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10094370
// Name: public: virtual void C_PropJeep::UpdateViewAngles(class C_BasePlayer __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropJeep::UpdateViewAngles(C_PropJeep *this, C_BasePlayer *pLocalPlayer, CUserCmd *pCmd)
{
  float v4; // xmm0_4
  int v5; // eax
  Vector vehicleEyeOrigin; // [esp+14h] [ebp-24h] BYREF
  QAngle vehicleEyeAngles; // [esp+20h] [ebp-18h] BYREF
  QAngle outAngles; // [esp+2Ch] [ebp-Ch] BYREF

  if ( r_JeepViewBlendTo.m_pParent != nullptr && r_JeepViewBlendTo.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( pCmd->mousedx != 0
      || pCmd->mousedy != 0
      || COERCE_FLOAT(
           (__int128)this->C_PropVehicleDriveable::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable
         & _mask__AbsFloat_) < 0.0099999998 )
    {
      v4 = 0.0;
    }
    else
    {
      v4 = *(float *)(gpGlobals.m_Index + 16) + *(float *)&this->m_hOwnerEntity.m_Index;
    }
    *(float *)&this->m_hOwnerEntity.m_Index = v4;
    if ( v4 > r_JeepViewBlendToTime.m_pParent->m_Value.m_fValue )
    {
      v5 = (*(int (__thiscall **)(char *, const char *))(*((_DWORD *)this - 813) + 132))(
             a1: (char *)this - 3252,
             a2: "vehicle_driver_eyes");
      C_BaseAnimating::GetAttachmentLocal(
        this: (C_PropJeep *)((char *)this - 3256),
        iAttachment: v5,
        origin: &vehicleEyeOrigin,
        angles: &vehicleEyeAngles);
      InterpolateAngles(
        start: &pCmd->viewangles,
        end: &vehicleEyeAngles,
        output: &outAngles,
        frac: r_JeepViewBlendToScale.m_pParent->m_Value.m_fValue);
      pCmd->viewangles = outAngles;
    }
  }
  C_PropVehicleDriveable::UpdateViewAngles(this, pLocalPlayer, pCmd);
}

//------------------------------------------------------------------------------
// Address: 0x10094530
// Name: void WheelDustCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WheelDustCallback(const CEffectData *data)
{
  float m_flScale; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  Particle *v12; // eax
  Particle *v13; // esi
  IUniformRandomStream *v14; // ecx
  IUniformRandomStream *v15; // ecx
  IUniformRandomStream *v16; // ecx
  double v17; // st7
  double v18; // st7
  double v19; // st6
  int v20; // eax
  Vector worldLight; // [esp+24h] [ebp-2Ch] BYREF
  float v22; // [esp+30h] [ebp-20h]
  float v23; // [esp+34h] [ebp-1Ch]
  Vector offset; // [esp+3Ch] [ebp-14h] BYREF
  float v25; // [esp+48h] [ebp-8h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+4Ch] [ebp-4h] BYREF

  CSimpleEmitter::Create(result: &pSimple, pDebugName: "dust");
  CParticleEffect::SetSortOrigin(this: pSimple.m_pObj, vSortOrigin: &data->m_vOrigin);
  CSimpleEmitter::SetNearClip(this: pSimple.m_pObj, nearClipMin: 32.0, nearClipMax: 64.0);
  m_flScale = data->m_flScale;
  v3 = data->m_vOrigin.y + (float)(data->m_flScale * data->m_vNormal.y);
  v4 = data->m_vOrigin.z + (float)(m_flScale * data->m_vNormal.z);
  offset.x = data->m_vOrigin.x + (float)(data->m_vNormal.x * m_flScale);
  offset.y = v3;
  offset.z = v4;
  engine->GetLightForPoint(this: engine, result: &worldLight, a3: &offset, a4: true);
  v5 = data->m_flScale * 16.0;
  LODWORD(v25) = LODWORD(v5) ^ _mask__NegFloat_;
  offset.x = _RandomFloat(this: v6, a2: COERCE_FLOAT(LODWORD(v5) ^ _mask__NegFloat_), a3: v5);
  offset.y = _RandomFloat(this: v7, a2: v25, a3: v5);
  _RandomFloat(this: v8, a2: v25, a3: v5);
  v9 = data->m_flScale;
  v10 = (float)(data->m_vOrigin.y + (float)(data->m_flScale * data->m_vNormal.y)) + offset.y;
  v11 = data->m_vOrigin.z + (float)(v9 * data->m_vNormal.z);
  offset.x = (float)(data->m_vOrigin.x + (float)(data->m_vNormal.x * v9)) + offset.x;
  offset.y = v10;
  offset.z = v11;
  v12 = CParticleEffect::AddParticle(
          this: pSimple.m_pObj,
          particleSize: 0x3Cu,
          material: g_Mat_DustPuff[0],
          origin: &offset);
  v13 = v12;
  if ( v12 != nullptr )
  {
    v12[1].m_Pos.z = 0.0;
    v12[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                       a1: random,
                       a2: 1048576000,
                       a3: 1056964608);
    v22 = _RandomFloat(this: v14, a2: -1.0, a3: 1.0);
    v23 = _RandomFloat(this: v15, a2: -1.0, a3: 1.0);
    v17 = _RandomFloat(this: v16, a2: -1.0, a3: 1.0);
    *(float *)&v13[1].m_pPrev = v22;
    LODWORD(worldLight.z) = &v13[1];
    *(float *)&v13[1].m_pNext = v23;
    *(float *)&v13[1].m_pSubTexture = v17;
    VectorNormalize(vec: (Vector *)LODWORD(worldLight.z));
    v18 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1098907648,
            a3: 1107296256);
    v19 = data->m_flScale + data->m_flScale;
    LODWORD(worldLight.z) = 150;
    LODWORD(worldLight.y) = 100;
    *(float *)&v13[1].m_pSubTexture = v18 * v19 + *(float *)&v13[1].m_pSubTexture;
    v20 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
    LOBYTE(v13[2].m_pPrev) = (int)(float)((float)((float)v20 * worldLight.x) + 16.0);
    BYTE1(v13[2].m_pPrev) = (int)(float)((float)((float)v20 * worldLight.y) + 8.0);
    BYTE2(v13[2].m_pPrev) = (int)(float)((float)v20 * worldLight.z);
    HIBYTE(v13[2].m_pPrev) = random->RandomInt(
                               this: random,
                               a2: (int)(float)(data->m_flScale * 64.0),
                               a3: (int)(float)(data->m_flScale * 128.0));
    LOBYTE(v13[2].m_pNext) = 0;
    BYTE1(v13[2].m_pNext) = (int)(float)((float)random->RandomInt(this: random, a2: 16, a3: 24) * data->m_flScale);
    BYTE2(v13[2].m_pNext) = (int)(float)((float)random->RandomInt(this: random, a2: 32, a3: 48) * data->m_flScale);
    v13[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
    *(float *)&v13[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                        a1: random,
                                        a2: -1073741824,
                                        a3: 0x40000000);
  }
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
}

//------------------------------------------------------------------------------
// Address: 0x10413FC0
// Name: DT_PropJeep::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PropJeep::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PropJeep::g_RecvTable);
  return atexit(func: DT_PropJeep::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413FE0
// Name: DT_PropJeep::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PropJeep::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PropJeep::ignored>();
  DT_PropJeep::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10414010
// Name: WheelDustPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int WheelDustPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  WheelDustPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&WheelDustPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430D40
// Name: DT_PropJeep::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PropJeep::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PropJeep::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10094470
// Name: _C_PropJeep_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PropJeep_CreateObject(int entnum, int serialNum)
{
  C_PropJeep *v2; // eax
  C_PropJeep *v3; // eax
  C_PropJeep *v4; // esi

  v2 = (C_PropJeep *)C_BaseEntity::operator new(stAllocateBlock: 0xE08u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PropJeep::C_PropJeep(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10413FF0
// Name: _dynamic_initializer_for__ClientEffectReg_WheelDustCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_WheelDustCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_WheelDustCallback,
           pEffectName: "WheelDust",
           fn: WheelDustCallback);
}
