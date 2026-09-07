// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_vehicle_choreo_generic.cpp
// Functions: 28
// ============================================================

#include "game\client\c_vehicle_choreo_generic.h"

//------------------------------------------------------------------------------
// Address: 0x10013EA0
// Name: public: virtual int C_PropVehicleChoreoGeneric::GetPrimaryAmmoCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PropVehicleChoreoGeneric::GetPrimaryAmmoCount(vgui::TreeView *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100937C0
// Name: public: virtual class ClientClass __near * C_PropVehicleChoreoGeneric::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PropVehicleChoreoGeneric::GetClientClass(C_PropVehicleChoreoGeneric *this)
{
  return &__g_C_PropVehicleChoreoGenericClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100939E0
// Name: public: virtual struct datamap_t __near * C_PropVehicleChoreoGeneric::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_PropVehicleChoreoGeneric::GetDataDescMap(C_PropVehicleChoreoGeneric *this)
{
  return &C_PropVehicleChoreoGeneric::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100939F0
// Name: public: virtual void C_PropVehicleChoreoGeneric::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleChoreoGeneric::PreDataUpdate(
        C_PropVehicleChoreoGeneric *this,
        DataUpdateType_t updateType)
{
  C_BaseAnimating::PreDataUpdate(this, updateType);
  this->m_flYawMinCurrent = this->m_flYawMaxCurrent;
}

//------------------------------------------------------------------------------
// Address: 0x10093A10
// Name: public: virtual class C_BaseCombatCharacter __near * C_PropVehicleChoreoGeneric::GetPassenger(int)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatCharacter *__thiscall C_PropVehicleChoreoGeneric::GetPassenger(C_PropVehicleChoreoGeneric *this, int nRole)
{
  const char *m_iClassname; // ecx

  if ( nRole != 0 )
    return nullptr;
  m_iClassname = this->m_iClassname;
  if ( m_iClassname == (const char *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_iClassname].m_SerialNumber != (unsigned int)m_iClassname >> 16 )
  {
    return nullptr;
  }
  else
  {
    return (C_BaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_iClassname].m_pEntity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093A50
// Name: public: virtual int C_PropVehicleChoreoGeneric::GetPassengerRole(class C_BaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_PropVehicleChoreoGeneric::GetPassengerRole(
        C_PropVehicleChoreoGeneric *this,
        C_BaseCombatCharacter *pPassenger)
{
  const char *m_iClassname; // ecx

  m_iClassname = this->m_iClassname;
  if ( m_iClassname == (const char *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_iClassname].m_SerialNumber != (unsigned int)m_iClassname >> 16 )
  {
    return -(pPassenger != nullptr);
  }
  else
  {
    return -(pPassenger != g_pEntityList->m_EntPtrArray[(unsigned __int16)m_iClassname].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093A90
// Name: private: void C_PropVehicleChoreoGeneric::UpdateViewClamps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleChoreoGeneric::UpdateViewClamps(C_PropVehicleChoreoGeneric *this)
{
  float m_Value; // xmm0_4
  double v3; // xmm0_8
  __m128d v4; // xmm0
  double v5; // xmm0_8
  float v6; // xmm1_4
  float m_flPitchMinCurrent; // xmm1_4
  float v8; // xmm0_4
  double v9; // xmm0_8
  __m128d v10; // xmm0
  double v11; // xmm0_8
  float v12; // xmm1_4
  float m_flYawMaxCurrent; // xmm1_4
  float v14; // xmm0_4
  double v15; // xmm0_8
  __m128d v16; // xmm0
  double v17; // xmm0_8
  float v18; // xmm1_4
  float m_flYawMinCurrent; // xmm1_4
  float v20; // xmm0_4
  double v21; // xmm0_8
  __m128d v22; // xmm0
  double v23; // xmm0_8
  float v24; // xmm1_4
  float m_flPitchMaxCurrent; // [esp+0h] [ebp-8h]
  float v26; // [esp+0h] [ebp-8h]
  float v27; // [esp+0h] [ebp-8h]
  float v28; // [esp+0h] [ebp-8h]
  float v29; // [esp+4h] [ebp-4h]
  float v30; // [esp+4h] [ebp-4h]
  float v31; // [esp+4h] [ebp-4h]
  float v32; // [esp+4h] [ebp-4h]

  m_Value = this->m_vehicleView.flPitchMax.m_Value;
  m_flPitchMaxCurrent = this->m_flPitchMaxCurrent;
  v29 = m_Value;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(m_flPitchMaxCurrent - m_Value) & _mask__AbsFloat_) > 0.001 )
  {
    __libm_sse2_log(a1: (__m128d)0x3FC99999A0000000uLL);
    *(float *)&v3 = v3;
    v4.m128d_f64[0] = (float)((float)(*(float *)&v3 * 2.0) * *(float *)(gpGlobals.m_Index + 16));
    __libm_sse2_exp(a1: v4);
    v6 = v5;
    m_Value = v29 - (float)(v6 * (float)(v29 - m_flPitchMaxCurrent));
  }
  m_flPitchMinCurrent = this->m_flPitchMinCurrent;
  this->m_flPitchMaxCurrent = m_Value;
  v8 = this->m_vehicleView.flPitchMin.m_Value;
  v30 = m_flPitchMinCurrent;
  v26 = v8;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(m_flPitchMinCurrent - v8) & _mask__AbsFloat_) > 0.001 )
  {
    __libm_sse2_log(a1: (__m128d)0x3FC99999A0000000uLL);
    *(float *)&v9 = v9;
    v10.m128d_f64[0] = (float)((float)(*(float *)&v9 * 2.0) * *(float *)(gpGlobals.m_Index + 16));
    __libm_sse2_exp(a1: v10);
    v12 = v11;
    v8 = v26 - (float)(v12 * (float)(v26 - v30));
  }
  m_flYawMaxCurrent = this->m_flYawMaxCurrent;
  this->m_flPitchMinCurrent = v8;
  v14 = this->m_vehicleView.flYawMax.m_Value;
  v31 = m_flYawMaxCurrent;
  v27 = v14;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(m_flYawMaxCurrent - v14) & _mask__AbsFloat_) > 0.001 )
  {
    __libm_sse2_log(a1: (__m128d)0x3FC99999A0000000uLL);
    *(float *)&v15 = v15;
    v16.m128d_f64[0] = (float)((float)(*(float *)&v15 * 2.0) * *(float *)(gpGlobals.m_Index + 16));
    __libm_sse2_exp(a1: v16);
    v18 = v17;
    v14 = v27 - (float)(v18 * (float)(v27 - v31));
  }
  m_flYawMinCurrent = this->m_flYawMinCurrent;
  this->m_flYawMaxCurrent = v14;
  v20 = this->m_vehicleView.flYawMin.m_Value;
  v32 = m_flYawMinCurrent;
  v28 = v20;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(m_flYawMinCurrent - v20) & _mask__AbsFloat_) > 0.001 )
  {
    __libm_sse2_log(a1: (__m128d)0x3FC99999A0000000uLL);
    *(float *)&v21 = v21;
    v22.m128d_f64[0] = (float)((float)(*(float *)&v21 * 2.0) * *(float *)(gpGlobals.m_Index + 16));
    __libm_sse2_exp(a1: v22);
    v24 = v23;
    v20 = v28 - (float)(v24 * (float)(v28 - v32));
  }
  this->m_flYawMinCurrent = v20;
}

//------------------------------------------------------------------------------
// Address: 0x10093CB0
// Name: public: C_PropVehicleChoreoGeneric::C_PropVehicleChoreoGeneric(void)
// Source: json
//------------------------------------------------------------------------------
C_PropVehicleChoreoGeneric *__thiscall C_PropVehicleChoreoGeneric::C_PropVehicleChoreoGeneric(
        C_PropVehicleChoreoGeneric *this)
{
  C_DynamicProp::C_DynamicProp(this);
  this->IClientVehicle::IVehicle::__vftable = (IClientVehicle_vtbl *)&IClientVehicle::`vftable';
  this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PropVehicleChoreoGeneric_vtbl *)&C_PropVehicleChoreoGeneric::`vftable'{for `IClientUnknown'};
  this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PropVehicleChoreoGeneric::`vftable'{for `IClientRenderable'};
  this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PropVehicleChoreoGeneric::`vftable'{for `IClientNetworkable'};
  this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PropVehicleChoreoGeneric::`vftable'{for `IClientThinkable'};
  this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PropVehicleChoreoGeneric::`vftable'{for `C_BaseAnimating'};
  this->C_DynamicProp::C_BreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_PropVehicleChoreoGeneric::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->IClientVehicle::IVehicle::__vftable = (IClientVehicle_vtbl *)&C_PropVehicleChoreoGeneric::`vftable';
  this->m_hPlayer.m_Index = -1;
  this->m_hPrevPlayer.m_Index = -1;
  this->m_vehicleView.__vftable = (vehicleview_t_vtbl *)&vehicleview_t::`vftable';
  memset(dst: (int)&this->m_ViewSmoothingData, value: nullptr, count: sizeof(this->m_ViewSmoothingData));
  this->m_ViewSmoothingData.flPitchCurveZero = 10.0;
  this->m_ViewSmoothingData.pVehicle = this;
  this->m_ViewSmoothingData.flPitchCurveLinear = 45.0;
  this->m_ViewSmoothingData.flRollCurveLinear = 45.0;
  this->m_ViewSmoothingData.flRollCurveZero = 5.0;
  this->m_flFOV = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10093D70
// Name: public: virtual void C_PropVehicleChoreoGeneric::GetVehicleFOV(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleChoreoGeneric::GetVehicleFOV(C_PropVehicleChoreoGeneric *this, float *flFOV)
{
  *flFOV = *(float *)&this->m_VarMap.m_Entries.m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x10093D80
// Name: public: virtual class IClientVehicle __near * C_PropVehicleChoreoGeneric::GetClientVehicle(void)
// Source: json
//------------------------------------------------------------------------------
IClientVehicle *__thiscall C_PropVehicleChoreoGeneric::GetClientVehicle(C_PropVehicleChoreoGeneric *this)
{
  if ( this != nullptr )
    return &this->IClientVehicle;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10093D90
// Name: public: virtual class C_BaseEntity __near * C_PropVehicleChoreoGeneric::GetVehicleEnt(void)
// Source: json
//------------------------------------------------------------------------------
C_PropVehicleChoreoGeneric *__thiscall C_PropVehicleChoreoGeneric::GetVehicleEnt(C_PropVehicleChoreoGeneric *this)
{
  return (C_PropVehicleChoreoGeneric *)((char *)this - 3312);
}

//------------------------------------------------------------------------------
// Address: 0x10093DD0
// Name: public: virtual void C_PropVehicleChoreoGeneric::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleChoreoGeneric::PostDataUpdate(
        C_PropVehicleChoreoGeneric *this,
        DataUpdateType_t updateType)
{
  float m_flYawMaxCurrent; // ecx
  float m_flYawMinCurrent; // ecx
  float v5; // eax
  C_BaseEntity *m_pEntity; // ecx
  IHandleEntity *v7; // edi
  char z_low; // al

  C_BaseAnimating::PostDataUpdate(this, updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    this->m_vecCachedRenderMaxs.z = this->m_vehicleView.flYawMax.m_Value;
    *(float *)&this->IClientVehicle::IVehicle::__vftable = this->m_vehicleView.flYawMin.m_Value;
    this->m_flPitchMaxCurrent = this->m_vehicleView.flFOV.m_Value;
    this->m_flPitchMinCurrent = this->m_vehicleView.flRollCurveLinear.m_Value;
  }
  m_flYawMaxCurrent = this->m_flYawMaxCurrent;
  if ( m_flYawMaxCurrent == NAN
    || g_pEntityList->m_EntPtrArray[LOWORD(m_flYawMaxCurrent)].m_SerialNumber != HIWORD(LODWORD(m_flYawMaxCurrent))
    || g_pEntityList->m_EntPtrArray[LOWORD(m_flYawMaxCurrent)].m_pEntity == nullptr )
  {
    m_flYawMinCurrent = this->m_flYawMinCurrent;
    if ( m_flYawMinCurrent != NAN
      && g_pEntityList->m_EntPtrArray[LOWORD(m_flYawMinCurrent)].m_SerialNumber == HIWORD(LODWORD(m_flYawMinCurrent))
      && g_pEntityList->m_EntPtrArray[LOWORD(m_flYawMinCurrent)].m_pEntity != nullptr )
    {
      BYTE2(this->m_ViewSmoothingData.rollLockData.flUnlockTime) = 0;
      v5 = this->m_flYawMinCurrent;
      if ( v5 == NAN || g_pEntityList->m_EntPtrArray[LOWORD(v5)].m_SerialNumber != HIWORD(LODWORD(v5)) )
        m_pEntity = nullptr;
      else
        m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(v5)].m_pEntity;
      if ( v5 == NAN || g_pEntityList->m_EntPtrArray[LOWORD(v5)].m_SerialNumber != HIWORD(LODWORD(v5)) )
        v7 = nullptr;
      else
        v7 = g_pEntityList->m_EntPtrArray[LOWORD(v5)].m_pEntity;
      v7[1456].__vftable = (IHandleEntity_vtbl *)LODWORD(C_BaseEntity::GetLocalOrigin(this: m_pEntity)->z);
    }
  }
  z_low = LOBYTE(this->m_ViewSmoothingData.vecAngleDiffMin.z);
  this->m_ViewSmoothingData.flRollCurveZero = this->m_vehicleView.flRollCurveZero.m_Value;
  LOBYTE(this->m_flFOV) = z_low;
}

//------------------------------------------------------------------------------
// Address: 0x10093EF0
// Name: public: virtual void C_PropVehicleChoreoGeneric::GetVehicleViewPosition(int,class Vector __near *,class QAngle __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleChoreoGeneric::GetVehicleViewPosition(
        C_PropVehicleChoreoGeneric *this,
        int nRole,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles,
        float *pFOV)
{
  const char *m_iClassname; // edx
  C_BasePlayer *m_pEntity; // eax

  m_iClassname = this->m_iClassname;
  if ( m_iClassname == (const char *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_iClassname].m_SerialNumber != (unsigned int)m_iClassname >> 16 )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_iClassname].m_pEntity;
  }
  SharedVehicleViewSmoothing(
    pPlayer: m_pEntity,
    pAbsOrigin,
    pAbsAngles,
    bEnterAnimOn: (bool)this->m_iszScriptId,
    bExitAnimOn: BYTE1(this->m_iszScriptId),
    vecEyeExitEndpoint: (const Vector *)&this->m_VarMap,
    pData: (ViewSmoothingData_t *)&this->m_VarMap.m_nInterpolatedEntries,
    pFOV,
    bForceViewToAttachment: this->m_VarMap.m_Entries.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x10093F50
// Name: public: virtual void C_PropVehicleChoreoGeneric::UpdateViewAngles(class C_BasePlayer __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PropVehicleChoreoGeneric::UpdateViewAngles(
        C_PropVehicleChoreoGeneric *this,
        C_BasePlayer *pLocalPlayer,
        CUserCmd *pCmd)
{
  int v4; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  Vector vehicleEyeOrigin; // [esp+14h] [ebp-18h] BYREF
  QAngle vehicleEyeAngles; // [esp+20h] [ebp-Ch] BYREF
  float flAngleDiff; // [esp+38h] [ebp+Ch]
  float flAngleDiffa; // [esp+38h] [ebp+Ch]

  v4 = (*(int (__thiscall **)(char *, const char *))(*((_DWORD *)this - 827) + 132))(
         a1: (char *)this - 3308,
         a2: "vehicle_driver_eyes");
  C_BaseAnimating::GetAttachmentLocal(
    this: (C_PropVehicleChoreoGeneric *)((char *)this - 3312),
    iAttachment: v4,
    origin: &vehicleEyeOrigin,
    angles: &vehicleEyeAngles);
  C_PropVehicleChoreoGeneric::UpdateViewClamps(this: (C_PropVehicleChoreoGeneric *)((char *)this - 3312));
  flAngleDiff = AngleDiff(destAngle: pCmd->viewangles.y, srcAngle: vehicleEyeAngles.y);
  v6 = *(float *)&this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable;
  if ( v6 <= flAngleDiff )
  {
    v6 = *(float *)&this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable;
    if ( flAngleDiff <= v6 )
      v6 = flAngleDiff;
  }
  pCmd->viewangles.y = v6 + vehicleEyeAngles.y;
  flAngleDiffa = AngleDiff(destAngle: pCmd->viewangles.x, srcAngle: vehicleEyeAngles.x);
  v7 = *(float *)&this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable;
  if ( v7 <= flAngleDiffa )
  {
    v7 = *(float *)&this->C_DynamicProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
    if ( flAngleDiffa <= v7 )
      v7 = flAngleDiffa;
  }
  pCmd->viewangles.x = v7 + vehicleEyeAngles.x;
}

//------------------------------------------------------------------------------
// Address: 0x10413ED0
// Name: DT_PropVehicleChoreoGeneric::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PropVehicleChoreoGeneric::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PropVehicleChoreoGeneric::g_RecvTable);
  return atexit(func: DT_PropVehicleChoreoGeneric::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413EF0
// Name: DT_PropVehicleChoreoGeneric::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PropVehicleChoreoGeneric::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PropVehicleChoreoGeneric::ignored>();
  DT_PropVehicleChoreoGeneric::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413F00
// Name: C_PropVehicleChoreoGeneric_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_PropVehicleChoreoGeneric_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<C_PropVehicleChoreoGeneric>();
  C_PropVehicleChoreoGeneric_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430CF0
// Name: DT_PropVehicleChoreoGeneric::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PropVehicleChoreoGeneric::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PropVehicleChoreoGeneric::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10094030
// Name: _C_PropVehicleChoreoGeneric_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PropVehicleChoreoGeneric_CreateObject(int entnum, int serialNum)
{
  C_PropVehicleChoreoGeneric *v2; // eax
  C_PropVehicleChoreoGeneric *v3; // eax
  C_PropVehicleChoreoGeneric *v4; // esi

  v2 = (C_PropVehicleChoreoGeneric *)C_BaseEntity::operator new(stAllocateBlock: 0xDC8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PropVehicleChoreoGeneric::C_PropVehicleChoreoGeneric(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10094080
// Name: struct datamap_t __near * DataMapInit<class C_PropVehicleChoreoGeneric>(class C_PropVehicleChoreoGeneric __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<C_PropVehicleChoreoGeneric>()
{
  if ( (_S6_24 & 1) == 0 )
  {
    _S6_24 |= 1u;
    nameHolder_9.m_pszBase = "C_PropVehicleChoreoGeneric";
    nameHolder_9.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_9.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_9.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_9.m_Names.m_Size = 0;
    nameHolder_9.m_Names.m_pElements = nullptr;
    nameHolder_9.m_nLenBase = 26;
    atexit(func: DataMapInit_C_PropVehicleChoreoGeneric__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  C_PropVehicleChoreoGeneric::m_DataMap.baseMap = &C_BaseEntity::m_DataMap;
  C_PropVehicleChoreoGeneric::m_DataMap.dataNumFields = 1;
  C_PropVehicleChoreoGeneric::m_DataMap.dataDesc = &dataDesc_9[1];
  return &C_PropVehicleChoreoGeneric::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10413F10
// Name: _dynamic_initializer_for__r_JeepViewBlendTo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_JeepViewBlendTo__()
{
  ConVar::ConVar(this: &r_JeepViewBlendTo, pName: "r_JeepViewBlendTo", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_JeepViewBlendTo__);
}

//------------------------------------------------------------------------------
// Address: 0x10413F40
// Name: _dynamic_initializer_for__r_JeepViewBlendToScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_JeepViewBlendToScale__()
{
  ConVar::ConVar(this: &r_JeepViewBlendToScale, pName: "r_JeepViewBlendToScale", pDefaultValue: "0.03", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_JeepViewBlendToScale__);
}

//------------------------------------------------------------------------------
// Address: 0x10413F70
// Name: _dynamic_initializer_for__r_JeepViewBlendToTime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_JeepViewBlendToTime__()
{
  ConVar::ConVar(this: &r_JeepViewBlendToTime, pName: "r_JeepViewBlendToTime", pDefaultValue: "1.5", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_JeepViewBlendToTime__);
}

//------------------------------------------------------------------------------
// Address: 0x10413FA0
// Name: _dynamic_initializer_for____g_C_PropJeepClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PropJeepClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PropJeepClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PropJeepClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430D00
// Name: _DataMapInit_C_PropVehicleChoreoGeneric__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_C_PropVehicleChoreoGeneric__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_9);
}

//------------------------------------------------------------------------------
// Address: 0x10430D10
// Name: _dynamic_atexit_destructor_for__r_JeepViewBlendTo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_JeepViewBlendTo__()
{
  ConVar::~ConVar(this: &r_JeepViewBlendTo);
}

//------------------------------------------------------------------------------
// Address: 0x10430D20
// Name: _dynamic_atexit_destructor_for__r_JeepViewBlendToScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_JeepViewBlendToScale__()
{
  ConVar::~ConVar(this: &r_JeepViewBlendToScale);
}

//------------------------------------------------------------------------------
// Address: 0x10430D30
// Name: _dynamic_atexit_destructor_for__r_JeepViewBlendToTime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_JeepViewBlendToTime__()
{
  ConVar::~ConVar(this: &r_JeepViewBlendToTime);
}
