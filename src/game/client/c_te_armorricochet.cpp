// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_armorricochet.cpp
// Functions: 20
// ============================================================

#include "game\client\c_te_armorricochet.h"

//------------------------------------------------------------------------------
// Address: 0x10253F40
// Name: RecordMetalSparks
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordMetalSparks(const Vector *direction@<edi>, const Vector *start)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "TempEntity");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "te", value: 5);
    KeyValues::SetString(this: v3, keyName: "name", value: "TE_MetalSparks");
    KeyValues::SetFloat(this: v3, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v3, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v3, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v3, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v3, keyName: "directionx", value: direction->x);
    KeyValues::SetFloat(this: v3, keyName: "directiony", value: direction->y);
    KeyValues::SetFloat(this: v3, keyName: "directionz", value: direction->z);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v3);
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10254070
// Name: public: virtual void C_TEMetalSparks::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEMetalSparks::PostDataUpdate(C_TEMetalSparks *this, DataUpdateType_t updateType)
{
  const Vector *p_z; // edi
  C_BaseTempEntity **p_m_pNextDynamic; // esi

  p_z = (const Vector *)&this->m_vecPos.z;
  p_m_pNextDynamic = &this->m_pNextDynamic;
  g_pEffects->MetalSparks(
    this: g_pEffects,
    a2: (const Vector *)&this->m_pNextDynamic,
    a3: (const Vector *)&this->m_vecPos.z);
  RecordMetalSparks(direction: p_z, start: (const Vector *)p_m_pNextDynamic);
}

//------------------------------------------------------------------------------
// Address: 0x102540A0
// Name: void TE_MetalSparks(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_MetalSparks(IRecipientFilter *filter, float delay, const Vector *pos, const Vector *dir)
{
  g_pEffects->MetalSparks(this: g_pEffects, a2: pos, a3: dir);
  RecordMetalSparks(start: pos, direction: dir);
}

//------------------------------------------------------------------------------
// Address: 0x102540D0
// Name: RecordArmorRicochet
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordArmorRicochet(const Vector *direction@<edi>, const Vector *start)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "TempEntity");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "te", value: 4);
    KeyValues::SetString(this: v3, keyName: "name", value: "TE_ArmorRicochet");
    KeyValues::SetFloat(this: v3, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v3, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v3, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v3, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v3, keyName: "directionx", value: direction->x);
    KeyValues::SetFloat(this: v3, keyName: "directiony", value: direction->y);
    KeyValues::SetFloat(this: v3, keyName: "directionz", value: direction->z);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v3);
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10254200
// Name: void TE_ArmorRicochet(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ArmorRicochet(IRecipientFilter *filter, float delay, const Vector *pos, const Vector *dir)
{
  g_pEffects->Ricochet(this: g_pEffects, a2: pos, a3: dir);
  RecordArmorRicochet(start: pos, direction: dir);
}

//------------------------------------------------------------------------------
// Address: 0x10254230
// Name: public: virtual void C_TEArmorRicochet::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEArmorRicochet::PostDataUpdate(C_TEArmorRicochet *this, DataUpdateType_t updateType)
{
  const Vector *p_z; // edi
  C_BaseTempEntity **p_m_pNextDynamic; // esi

  p_z = (const Vector *)&this->m_vecPos.z;
  p_m_pNextDynamic = &this->m_pNextDynamic;
  g_pEffects->Ricochet(
    this: g_pEffects,
    a2: (const Vector *)&this->m_pNextDynamic,
    a3: (const Vector *)&this->m_vecPos.z);
  RecordArmorRicochet(direction: p_z, start: (const Vector *)p_m_pNextDynamic);
}

//------------------------------------------------------------------------------
// Address: 0x10254260
// Name: public: virtual class ClientClass __near * C_TEMetalSparks::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEMetalSparks::GetClientClass(C_TEMetalSparks *this)
{
  return &__g_C_TEMetalSparksClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10254300
// Name: public: virtual class ClientClass __near * C_TEArmorRicochet::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEArmorRicochet::GetClientClass(C_TEArmorRicochet *this)
{
  return &__g_C_TEArmorRicochetClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042AFE0
// Name: DT_TEMetalSparks::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEMetalSparks::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEMetalSparks::g_RecvTable);
  return atexit(func: DT_TEMetalSparks::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B000
// Name: DT_TEMetalSparks::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEMetalSparks::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEMetalSparks::ignored>();
  DT_TEMetalSparks::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042B0A0
// Name: DT_TEArmorRicochet::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEArmorRicochet::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEArmorRicochet::g_RecvTable);
  return atexit(func: DT_TEArmorRicochet::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B0C0
// Name: DT_TEArmorRicochet::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEArmorRicochet::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEArmorRicochet::ignored>();
  DT_TEArmorRicochet::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436720
// Name: DT_TEMetalSparks::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEMetalSparks::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEMetalSparks::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436730
// Name: DT_TEArmorRicochet::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEArmorRicochet::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEArmorRicochet::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10254270
// Name: _C_TEMetalSparks_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEMetalSparks_CreateObject()
{
  return &_g_C_TEMetalSparks.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10254310
// Name: _C_TEArmorRicochet_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEArmorRicochet_CreateObject()
{
  return &_g_C_TEArmorRicochet.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B010
// Name: _dynamic_initializer_for____g_C_TEArmorRicochet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEArmorRicochet__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEArmorRicochet);
  _g_C_TEArmorRicochet.m_vecPos.x = 0.0;
  _g_C_TEArmorRicochet.m_vecPos.y = 0.0;
  _g_C_TEArmorRicochet.m_vecPos.z = 0.0;
  _g_C_TEArmorRicochet.m_vecDir.x = 0.0;
  _g_C_TEArmorRicochet.m_vecDir.y = 0.0;
  _g_C_TEArmorRicochet.m_vecDir.z = 0.0;
  _g_C_TEArmorRicochet.m_pModel = nullptr;
  _g_C_TEArmorRicochet.C_TEMetalSparks::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEArmorRicochet_vtbl *)&C_TEArmorRicochet::`vftable'{for `IClientUnknown'};
  _g_C_TEArmorRicochet.C_TEMetalSparks::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEArmorRicochet::`vftable'{for `IClientNetworkable'};
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEArmorRicochet__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B080
// Name: _dynamic_initializer_for____g_C_TEArmorRicochetClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEArmorRicochetClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEArmorRicochetClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEArmorRicochetClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042B0D0
// Name: _dynamic_initializer_for____g_C_TEBaseBeamClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBaseBeamClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBaseBeamClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBaseBeamClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436740
// Name: _dynamic_atexit_destructor_for____g_C_TEArmorRicochet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEArmorRicochet__()
{
  _g_C_TEArmorRicochet.C_TEMetalSparks::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEArmorRicochet_vtbl *)&C_TEMetalSparks::`vftable'{for `IClientUnknown'};
  _g_C_TEArmorRicochet.C_TEMetalSparks::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEMetalSparks::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEArmorRicochet);
}
