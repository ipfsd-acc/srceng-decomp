// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_spritespray.cpp
// Functions: 12
// ============================================================

#include "game\client\c_te_spritespray.h"

//------------------------------------------------------------------------------
// Address: 0x10265CF0
// Name: public: virtual class ClientClass __near * C_TESpriteSpray::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TESpriteSpray::GetClientClass(C_TESpriteSpray *this)
{
  return &__g_C_TESpriteSprayClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10265E20
// Name: RecordSpriteSpray
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordSpriteSpray(
        const Vector *direction@<edi>,
        int nModelIndex@<eax>,
        const Vector *start,
        int nSpeed,
        float flNoise,
        int nCount)
{
  const struct model_t *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  const char *pModelName; // [esp+Ch] [ebp-4h]

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    if ( nModelIndex != 0 && (v7 = modelinfo->GetModel(this: modelinfo, a2: nModelIndex)) != nullptr )
      pModelName = modelinfo->GetModelName(this: modelinfo, a2: v7);
    else
      pModelName = prType;
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "TempEntity");
    else
      v9 = nullptr;
    KeyValues::SetInt(this: v9, keyName: "te", value: 13);
    KeyValues::SetString(this: v9, keyName: "name", value: "TE_SpriteSpray");
    KeyValues::SetFloat(this: v9, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v9, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v9, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v9, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v9, keyName: "directionx", value: direction->x);
    KeyValues::SetFloat(this: v9, keyName: "directiony", value: direction->y);
    KeyValues::SetFloat(this: v9, keyName: "directionz", value: direction->z);
    KeyValues::SetString(this: v9, keyName: "model", value: pModelName);
    KeyValues::SetInt(this: v9, keyName: "speed", value: nSpeed);
    KeyValues::SetFloat(this: v9, keyName: "noise", value: flNoise);
    KeyValues::SetInt(this: v9, keyName: "count", value: nCount);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v9);
    KeyValues::deleteThis(this: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10265FD0
// Name: public: virtual void C_TESpriteSpray::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TESpriteSpray::PostDataUpdate(C_TESpriteSpray *this, DataUpdateType_t updateType)
{
  const Vector *p_z; // edi

  p_z = (const Vector *)&this->m_vecOrigin.z;
  tempents->Sprite_Spray(
    this: tempents,
    a2: (const Vector *)&this->m_pNextDynamic,
    a3: (const Vector *)&this->m_vecOrigin.z,
    a4: LODWORD(this->m_vecDirection.z),
    a5: LODWORD(this->m_fNoise),
    a6: (int)((double)this->m_nModelIndex * 0.2),
    a7: (int)(*(float *)&this->m_nSpeed * 100.0));
  RecordSpriteSpray(
    direction: p_z,
    nModelIndex: LODWORD(this->m_vecDirection.z),
    start: (const Vector *)&this->m_pNextDynamic,
    nSpeed: this->m_nModelIndex,
    flNoise: *(float *)&this->m_nSpeed,
    nCount: LODWORD(this->m_fNoise));
}

//------------------------------------------------------------------------------
// Address: 0x10266050
// Name: void TE_SpriteSpray(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_SpriteSpray(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir,
        int modelindex,
        int speed,
        float noise,
        int count)
{
  tempents->Sprite_Spray(
    this: tempents,
    a2: pos,
    a3: dir,
    a4: modelindex,
    a5: count,
    a6: (int)((double)speed * 0.2),
    a7: (int)(noise * 100.0));
  RecordSpriteSpray(start: pos, direction: dir, nModelIndex: modelindex, nSpeed: speed, flNoise: noise, nCount: count);
}

//------------------------------------------------------------------------------
// Address: 0x10266100
// Name: void TE_SpriteSpray(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_SpriteSpray(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IRecipientFilter *filter,
        float delay,
        KeyValues *pKeyValues)
{
  const char *String; // eax
  int v7; // ebx
  int Int; // edi
  int v9; // esi
  Vector vecDirection; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+38h] [ebp-10h] BYREF
  float flNoise; // [esp+44h] [ebp-4h]

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  vecDirection.x = KeyValues::GetFloat(this: pKeyValues, keyName: "directionx", defaultValue: 0.0);
  vecDirection.y = KeyValues::GetFloat(this: pKeyValues, keyName: "directiony", defaultValue: 0.0);
  vecDirection.z = KeyValues::GetFloat(this: pKeyValues, keyName: "directionz", defaultValue: 0.0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "model", defaultValue: prType);
  if ( *String != 0 )
    v7 = modelinfo->GetModelIndex(this: modelinfo, a2: String);
  else
    v7 = 0;
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "speed", defaultValue: 0);
  flNoise = KeyValues::GetFloat(this: pKeyValues, keyName: "noise", defaultValue: 0.0);
  v9 = KeyValues::GetInt(this: pKeyValues, keyName: "count", defaultValue: 0);
  ((void (__thiscall *)(ITempEnts *, Vector *, Vector *, int, int, int, int, int, int, int))tempents->Sprite_Spray)(
    a1: tempents,
    a2: &vecOrigin,
    a3: &vecDirection,
    a4: v7,
    a5: v9,
    a6: (int)((double)Int * 0.2),
    a7: (int)(flNoise * 100.0),
    a8: a2,
    a9: a3,
    a10: a1);
  RecordSpriteSpray(start: &vecOrigin, direction: &vecDirection, nModelIndex: v7, nSpeed: Int, flNoise, nCount: v9);
}

//------------------------------------------------------------------------------
// Address: 0x1042CDF0
// Name: DT_TESpriteSpray::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TESpriteSpray::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TESpriteSpray::g_RecvTable);
  return atexit(func: DT_TESpriteSpray::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CE10
// Name: DT_TESpriteSpray::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TESpriteSpray::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TESpriteSpray::ignored>();
  DT_TESpriteSpray::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436ED0
// Name: DT_TESpriteSpray::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TESpriteSpray::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TESpriteSpray::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10265D00
// Name: _C_TESpriteSpray_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TESpriteSpray_CreateObject()
{
  return &_g_C_TESpriteSpray.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042CE20
// Name: _dynamic_initializer_for____g_C_TEWorldDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEWorldDecal__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEWorldDecal);
  _g_C_TEWorldDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEWorldDecal_vtbl *)&C_TEWorldDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEWorldDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEWorldDecal::`vftable'{for `IClientNetworkable'};
  _g_C_TEWorldDecal.m_vecOrigin.x = 0.0;
  _g_C_TEWorldDecal.m_vecOrigin.y = 0.0;
  _g_C_TEWorldDecal.m_vecOrigin.z = 0.0;
  _g_C_TEWorldDecal.m_nIndex = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEWorldDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CE70
// Name: _dynamic_initializer_for____g_C_TEWorldDecalClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEWorldDecalClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEWorldDecalClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEWorldDecalClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436EE0
// Name: _dynamic_atexit_destructor_for____g_C_TESpriteSpray__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TESpriteSpray__()
{
  _g_C_TESpriteSpray.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TESpriteSpray_vtbl *)&C_TESpriteSpray::`vftable'{for `IClientUnknown'};
  _g_C_TESpriteSpray.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TESpriteSpray::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TESpriteSpray);
}
