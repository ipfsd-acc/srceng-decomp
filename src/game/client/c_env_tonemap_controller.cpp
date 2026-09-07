// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_env_tonemap_controller.cpp
// Functions: 7
// ============================================================

#include "game\client\c_env_tonemap_controller.h"

//------------------------------------------------------------------------------
// Address: 0x1006A380
// Name: public: virtual class ClientClass __near * C_EnvTonemapController::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvTonemapController::GetClientClass(C_EnvTonemapController *this)
{
  return &__g_C_EnvTonemapControllerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006A560
// Name: public: C_EnvTonemapController::C_EnvTonemapController(void)
// Source: json
//------------------------------------------------------------------------------
C_EnvTonemapController *__thiscall C_EnvTonemapController::C_EnvTonemapController(C_EnvTonemapController *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->m_flCustomAutoExposureMin = 0.0;
  this->m_flCustomAutoExposureMax = 0.0;
  this->m_flCustomBloomScale = 0.0;
  this->m_flCustomBloomScaleMinimum = 0.0;
  this->m_flBloomExponent = 2.5;
  this->m_flBloomSaturation = 1.0;
  this->m_flTonemapPercentTarget = 65.0;
  this->m_flTonemapPercentBrightPixels = 2.0;
  this->m_bUseCustomBloomScale = false;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvTonemapController_vtbl *)&C_EnvTonemapController::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvTonemapController::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvTonemapController::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvTonemapController::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvTonemapController::`vftable';
  *(_WORD *)&this->m_bUseCustomAutoExposureMin = 0;
  this->m_flTonemapMinAvgLum = 3.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006A670
// Name: void GetTonemapSettingsFromEnvTonemapController(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetTonemapSettingsFromEnvTonemapController()
{
  C_BasePlayer *LocalPlayer; // eax
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  float *v3; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr
    && ((m_Index = LocalPlayer->m_hTonemapController.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      ? (m_pEntity = nullptr)
      : (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity),
        (v3 = (float *)__RTDynamicCast(
                         inptr: m_pEntity,
                         VfDelta: 0,
                         SrcType: &C_BaseEntity `RTTI Type Descriptor',
                         TargetType: &C_EnvTonemapController `RTTI Type Descriptor',
                         isReference: 0)) != nullptr) )
  {
    g_bUseCustomAutoExposureMin = *((_BYTE *)v3 + 2432);
    g_bUseCustomAutoExposureMax = *((_BYTE *)v3 + 2433);
    g_bUseCustomBloomScale = *((_BYTE *)v3 + 2434);
    g_flCustomAutoExposureMin = v3[609];
    g_flCustomAutoExposureMax = v3[610];
    g_flCustomBloomScale = v3[611];
    g_flCustomBloomScaleMinimum = v3[612];
    g_flBloomExponent = v3[613];
    g_flBloomSaturation = v3[614];
    g_flTonemapPercentTarget = v3[615];
    g_flTonemapPercentBrightPixels = v3[616];
    g_flTonemapMinAvgLum = v3[617];
  }
  else
  {
    g_flBloomExponent = 2.5;
    g_flBloomSaturation = 1.0;
    g_flTonemapPercentTarget = 65.0;
    g_flTonemapPercentBrightPixels = 2.0;
    g_bUseCustomAutoExposureMax = false;
    g_bUseCustomBloomScale = false;
    g_flTonemapMinAvgLum = 3.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411E50
// Name: DT_EnvTonemapController::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvTonemapController::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvTonemapController::g_RecvTable);
  return atexit(func: DT_EnvTonemapController::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411E70
// Name: DT_EnvTonemapController::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvTonemapController::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvTonemapController::ignored>();
  DT_EnvTonemapController::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430260
// Name: DT_EnvTonemapController::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvTonemapController::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvTonemapController::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1006A620
// Name: _C_EnvTonemapController_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvTonemapController_CreateObject(int entnum, int serialNum)
{
  C_EnvTonemapController *v2; // eax
  C_EnvTonemapController *v3; // eax
  C_EnvTonemapController *v4; // esi

  v2 = (C_EnvTonemapController *)C_BaseEntity::operator new(stAllocateBlock: 0x9A8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EnvTonemapController::C_EnvTonemapController(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}
