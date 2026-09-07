// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_smoke.cpp
// Functions: 11
// ============================================================

#include "game\client\c_te_smoke.h"

//------------------------------------------------------------------------------
// Address: 0x10265290
// Name: RecordSmoke
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordSmoke(const Vector *start@<edi>, float flScale, int nFrameRate)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "TempEntity");
    else
      v4 = nullptr;
    KeyValues::SetInt(this: v4, keyName: "te", value: 6);
    KeyValues::SetString(this: v4, keyName: "name", value: "TE_Smoke");
    KeyValues::SetFloat(this: v4, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v4, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v4, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v4, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v4, keyName: "scale", value: flScale);
    KeyValues::SetInt(this: v4, keyName: "framerate", value: nFrameRate);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v4);
    KeyValues::deleteThis(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102653A0
// Name: public: virtual void C_TESmoke::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TESmoke::PostDataUpdate(C_TESmoke *this, DataUpdateType_t updateType)
{
  C_BaseTempEntity **p_m_pNextDynamic; // edi

  p_m_pNextDynamic = &this->m_pNextDynamic;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))g_pEffects->Smoke)(
    a1: &this->m_pNextDynamic,
    a2: LODWORD(this->m_vecOrigin.z),
    a3: *(float *)&this->m_nModelIndex * 10.0,
    a4: (float)SLODWORD(this->m_fScale));
  RecordSmoke(
    start: (const Vector *)p_m_pNextDynamic,
    flScale: *(float *)&this->m_nModelIndex * 10.0,
    nFrameRate: LODWORD(this->m_fScale));
}

//------------------------------------------------------------------------------
// Address: 0x10265400
// Name: void TE_Smoke(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Smoke(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int modelindex,
        float scale,
        int framerate)
{
  float scalea; // [esp+38h] [ebp+18h]

  scalea = scale * 10.0;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pEffects->Smoke)(
    a1: g_pEffects,
    a2: pos,
    a3: modelindex,
    a4: LODWORD(scalea),
    a5: (float)framerate);
  RecordSmoke(start: pos, flScale: scalea, nFrameRate: framerate);
}

//------------------------------------------------------------------------------
// Address: 0x10265460
// Name: public: virtual class ClientClass __near * C_TESmoke::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TESmoke::GetClientClass(C_TESmoke *this)
{
  return &__g_C_TESmokeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042CBF0
// Name: DT_TESmoke::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TESmoke::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TESmoke::g_RecvTable);
  return atexit(func: DT_TESmoke::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CC10
// Name: DT_TESmoke::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TESmoke::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TESmoke::ignored>();
  DT_TESmoke::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436E60
// Name: DT_TESmoke::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TESmoke::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TESmoke::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10265470
// Name: _C_TESmoke_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TESmoke_CreateObject()
{
  return &_g_C_TESmoke.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042CC20
// Name: _dynamic_initializer_for____g_C_TESparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TESparks__()
{
  C_TEParticleSystem::C_TEParticleSystem(this: &_g_C_TESparks);
  _g_C_TESparks.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TESparks_vtbl *)&C_TESparks::`vftable'{for `IClientUnknown'};
  _g_C_TESparks.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TESparks::`vftable'{for `IClientNetworkable'};
  return atexit(func: dynamic_atexit_destructor_for____g_C_TESparks__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CC50
// Name: _dynamic_initializer_for____g_C_TESparksClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TESparksClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TESparksClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TESparksClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436E70
// Name: _dynamic_atexit_destructor_for____g_C_TESparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TESparks__()
{
  _g_C_TESparks.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TESparks_vtbl *)&C_TESparks::`vftable'{for `IClientUnknown'};
  _g_C_TESparks.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TESparks::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TESparks);
}
