// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_fish.cpp
// Functions: 12
// ============================================================

#include "game\client\c_fish.h"

//------------------------------------------------------------------------------
// Address: 0x1006B040
// Name: void RecvProxy_FishOriginX(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_FishOriginX(const CRecvProxyData *pData, float *pStruct, float *pOut)
{
  *pOut = pStruct[838] + pData->m_Value.m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x1006B060
// Name: void RecvProxy_FishOriginY(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_FishOriginY(const CRecvProxyData *pData, float *pStruct, float *pOut)
{
  *pOut = pStruct[839] + pData->m_Value.m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x1006B080
// Name: public: virtual class ClientClass __near * C_Fish::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Fish::GetClientClass(C_Fish *this)
{
  return &__g_C_FishClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006B1D0
// Name: public: virtual void C_Fish::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall C_Fish::Spawn(C_Fish *this)
{
  IUniformRandomStream *v2; // ecx
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // edx

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  this->m_angles.x = 0.0;
  this->m_angles.y = 0.0;
  this->m_angles.z = 0.0;
  this->m_actualAngles = this->m_angles;
  this->m_vel.x = 0.0;
  this->m_vel.y = 0.0;
  this->m_vel.z = 0.0;
  this->m_gotUpdate = false;
  this->m_localLifeState = 0;
  this->m_buoyancy = _RandomFloat(this: v2, a2: 0.40000001, a3: 1.0);
  SetNextClientThink = this->SetNextClientThink;
  this->m_averageError = 0.0;
  this->m_errorHistoryIndex = 0;
  this->m_errorHistoryCount = 0;
  ((void (__thiscall *)(C_Fish *, int))SetNextClientThink)(a1: this, a2: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x1006B2A0
// Name: public: virtual void C_Fish::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Fish::OnDataChanged(C_Fish *this, DataUpdateType_t type)
{
  if ( type == DATA_UPDATE_CREATED )
  {
    LOBYTE(this->m_poolOrigin.z) = 1;
    this->m_vecRenderOriginOverride.z = this->m_wigglePhase;
    *((float *)&this->m_vecRenderOriginOverride + 3) = this->m_wiggleRate;
    this->m_pos.x = this->m_actualPos.x;
    this->m_pos.y = 0.0;
    this->m_pos.z = 0.0;
    this->m_vel.x = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B300
// Name: public: C_Fish::C_Fish(void)
// Source: json
//------------------------------------------------------------------------------
C_Fish *__thiscall C_Fish::C_Fish(C_Fish *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx

  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Fish_vtbl *)&C_Fish::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Fish::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Fish::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Fish::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Fish::`vftable';
  this->m_wiggleTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_wiggleTimer.__vftable;
  this->m_wiggleTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_wiggleTimer.m_duration);
  v3 = this->m_wiggleTimer.__vftable;
  this->m_wiggleTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_wiggleTimer, a2: &this->m_wiggleTimer.m_timestamp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006B370
// Name: public: virtual void C_Fish::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_Fish::ClientThink(C_Fish *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float v4; // xmm1_4
  IUniformRandomStream *v5; // ecx
  float v6; // xmm0_4
  float x; // eax
  int v8; // eax
  int (__thiscall *v9)(char *); // eax
  float v10; // xmm0_4
  __m128 v11; // xmm0
  int (__thiscall *v12)(char *); // eax
  double v13; // xmm0_8
  __m128 v14; // xmm0
  int (__thiscall *v15)(char *); // eax
  double v16; // xmm0_8
  __m128 v17; // xmm0
  int (__thiscall *v18)(char *); // eax
  double v19; // xmm0_8
  __m128 v20; // xmm0
  double v21; // xmm0_8
  float v22; // xmm3_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float m_deathAngle; // xmm0_4
  __m128 v26; // xmm1
  float v27; // xmm3_4
  double v28; // xmm0_8
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  int v32; // eax
  int v33; // edx
  float v34; // xmm0_4
  int v35; // eax
  float *p_z; // ecx
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm0_4
  float v40; // xmm4_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  float z; // xmm2_4
  float v46; // xmm2_4
  C_BaseEntity *v47; // edi
  Vector *p_m_vel; // esi
  const char *v49; // [esp+4h] [ebp-6Ch]
  float error; // [esp+58h] [ebp-18h]
  float error_4; // [esp+5Ch] [ebp-14h]
  float error_8; // [esp+60h] [ebp-10h]

  if ( FishDebug.m_pParent != nullptr && FishDebug.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__cdecl *)(float *, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *, int, _DWORD, _DWORD, int, int, int, int))debugoverlay->AddLineOverlay)(
      a1: &this->m_vecRenderOriginOverride.y,
      a2: &this->m_wiggleTimer.m_timestamp,
      a3: 255,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 1036831949,
      a8: a2,
      a9: a3);
    if ( LODWORD(this->m_angles.x) == 1 )
    {
      v49 = "DYING";
      goto LABEL_7;
    }
    if ( LODWORD(this->m_angles.x) == 2 )
    {
      v49 = "DEAD";
LABEL_7:
      ((void (__cdecl *)(IVDebugOverlay *, float *, int, const char *))debugoverlay->AddTextOverlay_2)(
        a1: debugoverlay,
        a2: &this->m_vecRenderOriginOverride.y,
        a3: 1036831949,
        a4: v49);
    }
  }
  v4 = *(float *)(gpGlobals.m_Index + 16);
  error_8 = v4;
  if ( LODWORD(this->m_angles.x) == 0 && this->m_iName[255] != 0 )
  {
    this->m_angles.y = *((float *)&this->m_vecRenderOriginOverride + 3);
    LODWORD(this->m_angles.x) = 1;
    if ( _RandomInt((IUniformRandomStream *)this, a2: 0, a3: 100) >= 50 )
      v6 = -1.0;
    else
      v6 = 1.0;
    this->m_angles.z = _RandomFloat(this: v5, a2: 87.0, a3: 93.0) * v6;
  }
  x = this->m_angles.x;
  if ( x == 0.0 )
  {
    *((float *)&this->m_vecRenderOriginOverride + 3) = this->m_wiggleRate;
    this->m_vel.x = this->m_actualPos.x;
    this->m_vel.y = this->m_actualPos.y;
    this->m_vel.z = this->m_actualPos.z;
    if ( CountdownTimer::Now(this: (CEffectsClient *)&this->m_deathDepth) <= this->m_buoyancy )
    {
      m_deathAngle = 0.0;
      error = CountdownTimer::Now(this: (CEffectsClient *)&this->m_deathDepth) - this->m_buoyancy + this->m_deathAngle;
      if ( this->m_buoyancy > 0.0 )
        m_deathAngle = this->m_deathAngle;
      v26 = (__m128)(unsigned int)this->m_wiggleTimer.__vftable;
      error_4 = m_deathAngle;
      v27 = (float)(this->m_wiggleTimer.m_duration.m_Value * error_8) + v26.m128_f32[0];
      this->m_wiggleTimer.m_duration.m_Value = this->m_wiggleTimer.m_duration.m_Value - (float)(error_8 * 5.0);
      *(float *)&this->m_wiggleTimer.__vftable = v27;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v26));
      *(float *)&v28 = v28;
      this->m_vel.y = (float)(*(float *)&v28 * (float)((float)(1.0 - (float)(error / error_4)) * 6.0)) + this->m_vel.y;
    }
    v4 = error_8;
  }
  else
  {
    v8 = LODWORD(x) - 1;
    if ( v8 != 0 )
    {
      if ( v8 == 1 )
      {
        v9 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40);
        v10 = (float)((float)((float)((float)(this->m_poolOrigin.x - *((float *)&this->m_vecRenderOriginOverride + 3))
                                    - 0.5)
                            * 10.0)
                    * v4)
            + this->m_pos.z;
        this->m_vel.z = (float)((float)((float)(*((float *)&this->m_vecRenderOriginOverride + 3) - this->m_angles.y)
                                      / (float)(this->m_poolOrigin.x - this->m_angles.y))
                              * (float)((float)(*((float *)&this->m_vecRenderOriginOverride + 3) - this->m_angles.y)
                                      / (float)(this->m_poolOrigin.x - this->m_angles.y)))
                      * this->m_angles.z;
        this->m_pos.z = v10;
        v11 = 0;
        v11.m128_f32[0] = (float)((float)((float)v9(a1: (char *)this - 4) * 10.0) + *(float *)(gpGlobals.m_Index + 12))
                        * 2.3299999;
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v11));
        v12 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40);
        *(float *)&v13 = v13;
        this->m_vel.z = (float)((float)(*(float *)&v13 * 5.0) * v4) + this->m_vel.z;
        v14 = 0;
        v14.m128_f32[0] = (float)((float)((float)v12(a1: (char *)this - 4) * 10.0) + *(float *)(gpGlobals.m_Index + 12))
                        * 4.0;
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v14));
        v15 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40);
        *(float *)&v16 = v16;
        this->m_vel.x = (float)((float)(*(float *)&v16 * 7.0) * v4) + this->m_vel.x;
        v17 = 0;
        v17.m128_f32[0] = (float)((float)((float)v15(a1: (char *)this - 4) * 10.0) + *(float *)(gpGlobals.m_Index + 12))
                        * 4.0;
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v17));
        v18 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40);
        *(float *)&v19 = v19;
        this->m_pos.z = (float)((float)(*(float *)&v19 * 0.75) * v4) + this->m_pos.z;
        v20 = 0;
        v20.m128_f32[0] = (float)((float)((float)v18(a1: (char *)this - 4) * 10.0) + *(float *)(gpGlobals.m_Index + 12))
                        * 3.3329999;
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v20));
        *(float *)&v21 = v21;
        *(float *)&v21 = (float)((float)(*(float *)&v21 * 0.75) * v4) + this->m_pos.z;
        this->m_pos.z = *(float *)&v21 - (float)(*(float *)&v21 * v4);
      }
    }
    else
    {
      v22 = *((float *)&this->m_vecRenderOriginOverride + 3);
      v23 = this->m_poolOrigin.x;
      v24 = (float)((float)(v22 - this->m_angles.y) / (float)(v23 - this->m_angles.y))
          * (float)((float)(v22 - this->m_angles.y) / (float)(v23 - this->m_angles.y));
      this->m_vel.z = this->m_angles.z * v24;
      if ( (float)(v23 - 2.0) <= v22 )
        LODWORD(this->m_angles.x) = 2;
      else
        this->m_pos.z = (float)((float)((float)(1.0 - v24) * *(float *)&this->m_localLifeState) * v4) + this->m_pos.z;
    }
  }
  v29 = this->m_wiggleTimer.m_timestamp.m_Value - this->m_vecRenderOriginOverride.y;
  v30 = this->m_wigglePhase - this->m_vecRenderOriginOverride.z;
  v31 = fsqrt((float)((float)(0.0 * 0.0) + (float)(v29 * v29)) + (float)(v30 * v30));
  if ( LODWORD(this->m_angles.x) == 0 )
  {
    if ( (float)(v31 - this->m_errorHistory[19]) > 2.0 )
    {
      CountdownTimer::Start(this: (CountdownTimer *)&this->m_deathDepth, duration: 5.0);
      this->m_wiggleTimer.m_duration.m_Value = v31 * 2.0;
      if ( (float)(v31 * 2.0) > 30.0 )
        this->m_wiggleTimer.m_duration.m_Value = 30.0;
      v4 = error_8;
    }
    *(&this->m_poolOrigin.z + LODWORD(this->m_errorHistory[17])++) = v31;
    if ( SLODWORD(this->m_errorHistory[17]) < 20 )
    {
      v32 = LODWORD(this->m_errorHistory[18]);
      if ( v32 < 20 )
        LODWORD(this->m_errorHistory[18]) = v32 + 1;
    }
    else
    {
      this->m_errorHistory[17] = 0.0;
      LODWORD(this->m_errorHistory[18]) = 20;
    }
    v33 = LODWORD(this->m_errorHistory[18]);
    v34 = 0.0;
    this->m_errorHistory[19] = 0.0;
    if ( v33 != 0 )
    {
      v35 = 0;
      if ( v33 > 0 )
      {
        p_z = &this->m_poolOrigin.z;
        do
        {
          v34 = v34 + *p_z;
          ++v35;
          this->m_errorHistory[19] = v34;
          ++p_z;
        }
        while ( v35 < SLODWORD(this->m_errorHistory[18]) );
      }
      this->m_errorHistory[19] = this->m_errorHistory[19] / (float)v33;
    }
  }
  v37 = v31 * 0.050000001;
  if ( (float)(v31 * 0.050000001) > 1.0 )
    v37 = 1.0;
  v38 = v37 * v37;
  v39 = (float)((float)(v37 * v37) * 6.0) + 2.0;
  v40 = v38 * 115.0;
  v41 = (float)((float)(v29 * v40) * v4) + this->m_pos.x;
  v42 = (float)((float)((float)(v30 * v40) * v4) + this->m_pos.y)
      - (float)((float)(v39 * (float)((float)((float)(v30 * v40) * v4) + this->m_pos.y)) * v4);
  this->m_pos.y = v42;
  v43 = v41 - (float)((float)(v39 * v41) * v4);
  this->m_pos.x = v43;
  v44 = v43;
  z = this->m_pos.z;
  this->m_vecRenderOriginOverride.y = (float)(v44 * v4) + this->m_vecRenderOriginOverride.y;
  v46 = (float)(z * v4) + *((float *)&this->m_vecRenderOriginOverride + 3);
  this->m_vecRenderOriginOverride.z = this->m_vecRenderOriginOverride.z + (float)(v42 * v4);
  *((float *)&this->m_vecRenderOriginOverride + 3) = v46;
  C_BaseEntity::SetNetworkOrigin(
    this: (C_Fish *)((char *)this - 12),
    org: (const Vector *)&this->m_vecRenderOriginOverride.y);
  v47 = (C_Fish *)((char *)this - 12);
  C_BaseEntity::SetAbsOrigin(
    this: (C_Fish *)((char *)this - 12),
    absOrigin: (const Vector *)&this->m_vecRenderOriginOverride.y);
  p_m_vel = &this->m_vel;
  C_BaseEntity::SetNetworkAngles(this: v47, ang: (const QAngle *)p_m_vel);
  C_BaseEntity::SetAbsAngles(this: v47, absAngles: (const QAngle *)p_m_vel);
}

//------------------------------------------------------------------------------
// Address: 0x10411F40
// Name: DT_CFish::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CFish::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CFish::g_RecvTable);
  return atexit(func: DT_CFish::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411F60
// Name: DT_CFish::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CFish::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CFish::ignored>();
  DT_CFish::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430290
// Name: DT_CFish::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CFish::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CFish::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1006BA90
// Name: _C_Fish_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Fish_CreateObject(int entnum, int serialNum)
{
  C_Fish *v2; // eax
  C_Fish *v3; // eax
  C_Fish *v4; // esi

  v2 = (C_Fish *)C_BaseEntity::operator new(stAllocateBlock: 0xD88u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Fish::C_Fish(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411F70
// Name: _dynamic_initializer_for____g_C_FuncAreaPortalWindowClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncAreaPortalWindowClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncAreaPortalWindowClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncAreaPortalWindowClientClass;
  return result;
}
