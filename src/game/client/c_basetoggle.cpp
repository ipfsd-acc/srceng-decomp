// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_basetoggle.cpp
// Functions: 31
// ============================================================

#include "game\client\c_basetoggle.h"

//------------------------------------------------------------------------------
// Address: 0x1005ECD0
// Name: public: virtual class ClientClass __near * C_BaseToggle::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseToggle::GetClientClass(C_BaseToggle *this)
{
  return &__g_C_BaseToggleClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1005EDA0
// Name: public: virtual struct datamap_t __near * C_BaseToggle::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseToggle::GetPredDescMap(C_BaseToggle *this)
{
  return &C_BaseToggle::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1005EDB0
// Name: public: virtual bool C_BaseToggle::PredictionIsPhysicallySimulated(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseToggle::PredictionIsPhysicallySimulated(C_BaseToggle *this)
{
  return this->m_movementType == 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005EDC0
// Name: public: virtual class ClientClass __near * C_BaseButton::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseButton::GetClientClass(C_BaseButton *this)
{
  return &__g_C_BaseButtonClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1005EEC0
// Name: public: virtual void C_BaseToggle::GetGroundVelocityToApply(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseToggle::GetGroundVelocityToApply(C_BaseToggle *this, Vector *vecGroundVel)
{
  *vecGroundVel = this->m_vecVelocity;
  if ( !C_BaseEntity::GetPredictable(this) )
    vecGroundVel->z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1005EF00
// Name: public: virtual class C_BasePlayer __near * C_BaseToggle::GetPredictionOwner(void)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__thiscall C_BaseToggle::GetPredictionOwner(C_BaseToggle *this)
{
  unsigned int m_Index; // ecx
  C_BasePlayer *result; // eax

  m_Index = this->m_hPredictionOwner.m_Index;
  if ( m_Index == -1 )
    return nullptr;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  result = (C_BasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( result == nullptr || !result->m_bIsLocalPlayer )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005EF40
// Name: public: virtual void C_BaseToggle::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseToggle::PostDataUpdate(C_BaseToggle *this, DataUpdateType_t updateType)
{
  const Vector *NetworkOrigin; // eax
  bool v4; // zf

  C_BaseEntity::PostDataUpdate(this, updateType);
  NetworkOrigin = C_BaseEntity::GetNetworkOrigin(this: (C_BaseToggle *)((char *)this - 8));
  *((float *)&this->m_bIsBlurred + 1) = NetworkOrigin->x;
  *(float *)&this->m_hPredictionOwner.m_Index = NetworkOrigin->y;
  this->m_vLastNetworked.x = NetworkOrigin->z;
  this->m_vLastNetworked.y = *(float *)(gpGlobals.m_Index + 12);
  if ( !C_BaseEntity::GetPredictionEligible(this: (C_BaseToggle *)((char *)this - 8))
    || LOBYTE(this->m_movementType) == 0 )
  {
    goto LABEL_5;
  }
  v4 = LODWORD(this->m_vecFinalDest.y) == 0;
  if ( LODWORD(this->m_vecFinalDest.y) == 0 )
  {
    C_BaseEntity::SetPredictionEligible(this: (C_BaseToggle *)((char *)this - 8), canpredict: false);
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 424))(a1: (char *)this - 8);
LABEL_5:
    v4 = LODWORD(this->m_vecFinalDest.y) == 0;
  }
  LOBYTE(this->m_movementType) = !v4;
}

//------------------------------------------------------------------------------
// Address: 0x1005EFD0
// Name: public: class Vector C_BaseToggle::PredictPosition(float)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BaseToggle::PredictPosition(C_BaseToggle *this, Vector *result, float fCurTime)
{
  float m_flMoveTargetTime; // xmm3_4
  Vector *v4; // eax
  float v5; // xmm0_4
  __int64 v6; // xmm0_8
  float v7; // ecx
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float z; // edx
  const Vector *NetworkOrigin; // eax
  __int64 v13; // xmm0_8
  float v14; // eax

  if ( this->m_movementType == 1 && (m_flMoveTargetTime = this->m_flMoveTargetTime) > 0.0 )
  {
    v4 = result;
    if ( m_flMoveTargetTime <= fCurTime )
    {
      z = this->m_vecFinalDest.z;
      *(_QWORD *)&result->x = *(_QWORD *)&this->m_vecFinalDest.x;
      result->z = z;
    }
    else
    {
      v5 = m_flMoveTargetTime - this->m_fLastNetworkedTime;
      if ( v5 > 0.0 )
      {
        v8 = (float)(m_flMoveTargetTime - fCurTime) / v5;
        v9 = (float)(this->m_vecFinalDest.y * (float)(1.0 - v8)) + (float)(this->m_vLastNetworked.y * v8);
        v10 = (float)(this->m_vLastNetworked.z * v8) + (float)(this->m_vecFinalDest.z * (float)(1.0 - v8));
        result->x = (float)(this->m_vLastNetworked.x * v8) + (float)(this->m_vecFinalDest.x * (float)(1.0 - v8));
        result->y = v9;
        result->z = v10;
      }
      else
      {
        v6 = *(_QWORD *)&this->m_vecFinalDest.x;
        v7 = this->m_vecFinalDest.z;
        *(_QWORD *)&result->x = v6;
        result->z = v7;
      }
    }
  }
  else
  {
    NetworkOrigin = C_BaseEntity::GetNetworkOrigin(this);
    v13 = *(_QWORD *)&NetworkOrigin->x;
    v14 = NetworkOrigin->z;
    *(_QWORD *)&result->x = v13;
    result->z = v14;
    return result;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1005F0E0
// Name: public: virtual bool C_BaseToggle::ShouldPredict(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseToggle::ShouldPredict(C_BaseToggle *this)
{
  int result; // eax

  if ( cl_predict_basetoggles.m_pParent == nullptr )
    return 0;
  if ( cl_predict_basetoggles.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  result = 1;
  if ( this->m_movementType != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005F100
// Name: public: virtual void C_BaseToggle::PhysicsSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseToggle::PhysicsSimulate(C_BaseToggle *this)
{
  C_BasePlayer *v2; // eax
  float fCurTime; // [esp+0h] [ebp-14h]
  Vector vOrigin; // [esp+8h] [ebp-Ch] BYREF

  C_BaseEntity::PhysicsSimulate(this);
  if ( C_BaseEntity::GetPredictable(this) )
  {
    v2 = this->GetPredictionOwner(this);
    fCurTime = C_BasePlayer::PredictedServerTime(this: v2);
    C_BaseToggle::PredictPosition(this, result: &vOrigin, fCurTime);
    if ( this->m_vecFinalDest.x == vOrigin.x
      && this->m_vecFinalDest.y == vOrigin.y
      && this->m_vecFinalDest.z == vOrigin.z )
    {
      C_BaseEntity::SetLocalVelocity(this, vecVelocity: &vec3_origin);
    }
    C_BaseEntity::SetLocalOrigin(this, origin: &vOrigin);
    C_BaseEntity::SetNetworkOrigin(this, org: &vOrigin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411550
// Name: DT_BaseToggle::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseToggle::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseToggle::g_RecvTable);
  return atexit(func: DT_BaseToggle::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411570
// Name: DT_BaseToggle::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseToggle::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseToggle::ignored>();
  DT_BaseToggle::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411580
// Name: C_BaseToggle_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseToggle_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseToggle::m_PredMap.dataNumFields = 1;
  C_BaseToggle::m_PredMap.dataDesc = (typedescription_t *)&unk_10601408;
}

//------------------------------------------------------------------------------
// Address: 0x104115F0
// Name: DT_BaseButton::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseButton::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseButton::g_RecvTable);
  return atexit(func: DT_BaseButton::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411610
// Name: DT_BaseButton::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseButton::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseButton::ignored>();
  DT_BaseButton::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430060
// Name: DT_BaseToggle::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseToggle::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseToggle::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430080
// Name: DT_BaseButton::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseButton::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseButton::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1005F1A0
// Name: _C_BaseButton_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseButton_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9B8u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3[608] = -1;
  *v3 = &C_BaseButton::`vftable'{for `IClientUnknown'};
  v3[1] = &C_BaseButton::`vftable'{for `IClientRenderable'};
  v3[2] = &C_BaseButton::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_BaseButton::`vftable'{for `IClientThinkable'};
  v3[4] = &C_BaseButton::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104115A0
// Name: _dynamic_initializer_for__cl_predict_basetoggles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predict_basetoggles__()
{
  ConVar::ConVar(this: &cl_predict_basetoggles, pName: "cl_predict_basetoggles", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_predict_basetoggles__);
}

//------------------------------------------------------------------------------
// Address: 0x104115D0
// Name: _dynamic_initializer_for____g_C_BaseButtonClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseButtonClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseButtonClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseButtonClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411620
// Name: _dynamic_initializer_for__cl_righthand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_righthand__()
{
  ConVar::ConVar(
    this: &cl_righthand,
    pName: "cl_righthand",
    pDefaultValue: "1",
    flags: 32896,
    pHelpString: "Use right-handed view models.");
  return atexit(func: dynamic_atexit_destructor_for__cl_righthand__);
}

//------------------------------------------------------------------------------
// Address: 0x10411650
// Name: _dynamic_initializer_for__vm_draw_addon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vm_draw_addon__()
{
  ConVar::ConVar(this: &vm_draw_addon, pName: "vm_draw_addon", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vm_draw_addon__);
}

//------------------------------------------------------------------------------
// Address: 0x10411680
// Name: _dynamic_initializer_for__ss_righthand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
SplitScreenConVarRef *dynamic_initializer_for__ss_righthand__()
{
  return SplitScreenConVarRef::SplitScreenConVarRef(this: &ss_righthand, pName: "cl_righthand", bIgnoreMissing: true);
}

//------------------------------------------------------------------------------
// Address: 0x104116A0
// Name: _dynamic_initializer_for__vm_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vm_debug__()
{
  ConVar::ConVar(this: &vm_debug, pName: "vm_debug", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__vm_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x104116D0
// Name: _dynamic_initializer_for__vm_draw_always__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vm_draw_always__()
{
  ConVar::ConVar(
    this: &vm_draw_always,
    pName: "vm_draw_always",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "1 - Always draw view models, 2 - Never draw view models.  Should be done before map launches.");
  return atexit(func: dynamic_atexit_destructor_for__vm_draw_always__);
}

//------------------------------------------------------------------------------
// Address: 0x10411700
// Name: _dynamic_initializer_for____g_C_BeamSpotLightClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BeamSpotLightClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BeamSpotLightClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BeamSpotLightClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430070
// Name: _dynamic_atexit_destructor_for__cl_predict_basetoggles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predict_basetoggles__()
{
  ConVar::~ConVar(this: &cl_predict_basetoggles);
}

//------------------------------------------------------------------------------
// Address: 0x10430090
// Name: _dynamic_atexit_destructor_for__cl_righthand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_righthand__()
{
  ConVar::~ConVar(this: &cl_righthand);
}

//------------------------------------------------------------------------------
// Address: 0x104300A0
// Name: _dynamic_atexit_destructor_for__vm_draw_addon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vm_draw_addon__()
{
  ConVar::~ConVar(this: &vm_draw_addon);
}

//------------------------------------------------------------------------------
// Address: 0x104300B0
// Name: _dynamic_atexit_destructor_for__vm_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vm_debug__()
{
  ConVar::~ConVar(this: &vm_debug);
}

//------------------------------------------------------------------------------
// Address: 0x104300C0
// Name: _dynamic_atexit_destructor_for__vm_draw_always__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vm_draw_always__()
{
  ConVar::~ConVar(this: &vm_draw_always);
}
