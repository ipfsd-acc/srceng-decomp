// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_physicsprop.cpp
// Functions: 13
// ============================================================

#include "game\client\c_te_physicsprop.h"

//------------------------------------------------------------------------------
// Address: 0x10263AC0
// Name: public: virtual class ClientClass __near * C_TEPhysicsProp::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEPhysicsProp::GetClientClass(C_TEPhysicsProp *this)
{
  return &__g_C_TEPhysicsPropClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10263C80
// Name: RecordPhysicsProp
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordPhysicsProp(
        const Vector *vel@<edi>,
        int nModelIndex@<eax>,
        const Vector *start,
        const QAngle *angles,
        int flags,
        int nSkin,
        int nEffects,
        color24 renderColor)
{
  const struct model_t *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  const char *pModelName; // [esp+Ch] [ebp-8h]
  Color convertedRenderColor; // [esp+10h] [ebp-4h]

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    if ( nModelIndex != 0 && (v9 = modelinfo->GetModel(this: modelinfo, a2: nModelIndex)) != nullptr )
      pModelName = modelinfo->GetModelName(this: modelinfo, a2: v9);
    else
      pModelName = prType;
    *(_WORD *)convertedRenderColor._color = *(_WORD *)&renderColor.r;
    *(_WORD *)&convertedRenderColor._color[2] = renderColor.b;
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "TempEntity");
    else
      v11 = nullptr;
    KeyValues::SetInt(this: v11, keyName: "te", value: 11);
    KeyValues::SetString(this: v11, keyName: "name", value: "TE_PhysicsProp");
    KeyValues::SetFloat(this: v11, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v11, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v11, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v11, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v11, keyName: "anglesx", value: angles->x);
    KeyValues::SetFloat(this: v11, keyName: "anglesy", value: angles->y);
    KeyValues::SetFloat(this: v11, keyName: "anglesz", value: angles->z);
    KeyValues::SetFloat(this: v11, keyName: "velx", value: vel->x);
    KeyValues::SetFloat(this: v11, keyName: "vely", value: vel->y);
    KeyValues::SetFloat(this: v11, keyName: "velz", value: vel->z);
    KeyValues::SetString(this: v11, keyName: "model", value: pModelName);
    KeyValues::SetInt(this: v11, keyName: "breakmodel", value: flags);
    KeyValues::SetInt(this: v11, keyName: "skin", value: nSkin);
    KeyValues::SetInt(this: v11, keyName: "effects", value: nEffects);
    KeyValues::SetColor(this: v11, keyName: "rendercolor", value: convertedRenderColor);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v11);
    KeyValues::deleteThis(this: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263EA0
// Name: void TE_PhysicsProp(class IRecipientFilter __near &,float,int,int,class Vector const __near &,class QAngle const __near &,class Vector const __near &,int,int,struct color24)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_PhysicsProp(
        IRecipientFilter *filter,
        float delay,
        int modelindex,
        int skin,
        const Vector *pos,
        const QAngle *angles,
        const Vector *vel,
        int flags,
        int effects,
        color24 renderColor)
{
  int v10; // [esp-4h] [ebp-10h]

  HIBYTE(v10) = HIBYTE(tempents);
  *(color24 *)&v10 = renderColor;
  ((void (__stdcall *)(int, int, const Vector *, const QAngle *, const Vector *, int, int, int))tempents->PhysicsProp)(
    a1: modelindex,
    a2: skin,
    a3: pos,
    a4: angles,
    a5: vel,
    a6: flags,
    a7: effects,
    a8: v10);
  RecordPhysicsProp(
    start: pos,
    angles,
    vel,
    nModelIndex: modelindex,
    flags,
    nSkin: skin,
    nEffects: effects,
    renderColor);
}

//------------------------------------------------------------------------------
// Address: 0x10263F10
// Name: public: virtual void C_TEPhysicsProp::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEPhysicsProp::PostDataUpdate(C_TEPhysicsProp *this, DataUpdateType_t updateType)
{
  unsigned __int8 v3; // bl
  const Vector *p_z; // edi
  int v5; // [esp-4h] [ebp-14h]
  color24 v6; // [esp-4h] [ebp-14h]
  __int16 clrRenderConverted; // [esp+Ch] [ebp-4h]

  v3 = BYTE2(this->m_nEffects);
  HIBYTE(v5) = HIBYTE(this);
  clrRenderConverted = this->m_nEffects;
  LOWORD(v5) = clrRenderConverted;
  BYTE2(v5) = v3;
  p_z = (const Vector *)&this->m_angRotation.z;
  ((void (__thiscall *)(ITempEnts *, _DWORD, int, C_BaseTempEntity **, float *, float *, int, int, int))tempents->PhysicsProp)(
    a1: tempents,
    a2: LODWORD(this->m_vecVelocity.z),
    a3: this->m_nModelIndex,
    a4: &this->m_pNextDynamic,
    a5: &this->m_vecOrigin.z,
    a6: &this->m_angRotation.z,
    a7: this->m_nSkin,
    a8: this->m_nFlags,
    a9: v5);
  *(_WORD *)&v6.r = clrRenderConverted;
  v6.b = v3;
  RecordPhysicsProp(
    vel: p_z,
    nModelIndex: LODWORD(this->m_vecVelocity.z),
    start: (const Vector *)&this->m_pNextDynamic,
    angles: (const QAngle *)&this->m_vecOrigin.z,
    flags: this->m_nSkin,
    nSkin: this->m_nModelIndex,
    nEffects: this->m_nFlags,
    renderColor: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10263FA0
// Name: void TE_PhysicsProp(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl TE_PhysicsProp(IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  const char *String; // eax
  int Int; // edi
  int v5; // ebx
  __int16 v6; // si
  char v7; // ecx^3
  int defaultValue; // [esp+0h] [ebp-48h]
  color24 defaultValuea; // [esp+0h] [ebp-48h]
  Vector vecVel; // [esp+10h] [ebp-38h] BYREF
  Vector vecOrigin; // [esp+1Ch] [ebp-2Ch] BYREF
  QAngle angles; // [esp+28h] [ebp-20h] BYREF
  ITempEnts_vtbl *v13; // [esp+34h] [ebp-14h]
  int nSkin; // [esp+38h] [ebp-10h]
  Color renderColor; // [esp+3Ch] [ebp-Ch] BYREF
  int nModelIndex; // [esp+40h] [ebp-8h]
  Color convertedRenderColor; // [esp+44h] [ebp-4h] OVERLAPPED BYREF

  nSkin = KeyValues::GetInt(this: pKeyValues, keyName: "skin", defaultValue: 0);
  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  angles.x = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesx", defaultValue: 0.0);
  angles.y = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesy", defaultValue: 0.0);
  angles.z = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesz", defaultValue: 0.0);
  vecVel.x = KeyValues::GetFloat(this: pKeyValues, keyName: "velx", defaultValue: 0.0);
  vecVel.y = KeyValues::GetFloat(this: pKeyValues, keyName: "vely", defaultValue: 0.0);
  vecVel.z = KeyValues::GetFloat(this: pKeyValues, keyName: "velz", defaultValue: 0.0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "model", defaultValue: prType);
  if ( *String != 0 )
    nModelIndex = modelinfo->GetModelIndex(this: modelinfo, a2: String);
  else
    nModelIndex = 0;
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "breakmodel", defaultValue: 0);
  v5 = KeyValues::GetInt(this: pKeyValues, keyName: "effects", defaultValue: 0);
  convertedRenderColor = 0;
  KeyValues::GetColor(
    this: pKeyValues,
    result: &renderColor,
    keyName: "rendercolor",
    defaultColor: &convertedRenderColor);
  *(_WORD *)convertedRenderColor._color = *(_WORD *)renderColor._color;
  v6 = *(_WORD *)renderColor._color;
  HIBYTE(defaultValue) = v7;
  v13 = tempents->__vftable;
  LOWORD(defaultValue) = *(_WORD *)renderColor._color;
  BYTE2(defaultValue) = renderColor._color[2];
  convertedRenderColor._color[2] = renderColor._color[2];
  ((void (__thiscall *)(ITempEnts *, int, int, Vector *, QAngle *, Vector *, int, int, int))v13->PhysicsProp)(
    a1: tempents,
    a2: nModelIndex,
    a3: nSkin,
    a4: &vecOrigin,
    a5: &angles,
    a6: &vecVel,
    a7: Int,
    a8: v5,
    a9: defaultValue);
  *(_WORD *)&defaultValuea.r = v6;
  defaultValuea.b = convertedRenderColor._color[2];
  RecordPhysicsProp(
    start: &vecOrigin,
    &angles,
    vel: &vecVel,
    nModelIndex,
    flags: Int,
    nSkin,
    nEffects: v5,
    renderColor: defaultValuea);
}

//------------------------------------------------------------------------------
// Address: 0x1042C8E0
// Name: DT_TEPhysicsProp::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPhysicsProp::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEPhysicsProp::g_RecvTable);
  return atexit(func: DT_TEPhysicsProp::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C900
// Name: DT_TEPhysicsProp::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPhysicsProp::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEPhysicsProp::ignored>();
  DT_TEPhysicsProp::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436D70
// Name: DT_TEPhysicsProp::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEPhysicsProp::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEPhysicsProp::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10263AD0
// Name: _C_TEPhysicsProp_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEPhysicsProp_CreateObject()
{
  return &_g_C_TEPhysicsProp.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042C910
// Name: _dynamic_initializer_for__cl_playerspraydisable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_playerspraydisable__()
{
  ConVar::ConVar(
    this: &cl_playerspraydisable,
    pName: "cl_playerspraydisable",
    pDefaultValue: "0",
    flags: 136,
    pHelpString: "Disable player sprays.");
  return atexit(func: dynamic_atexit_destructor_for__cl_playerspraydisable__);
}

//------------------------------------------------------------------------------
// Address: 0x10436D80
// Name: _dynamic_atexit_destructor_for____g_C_TEPhysicsProp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEPhysicsProp__()
{
  _g_C_TEPhysicsProp.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEPhysicsProp_vtbl *)&C_TEPhysicsProp::`vftable'{for `IClientUnknown'};
  _g_C_TEPhysicsProp.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEPhysicsProp::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEPhysicsProp);
}

//------------------------------------------------------------------------------
// Address: 0x10436DA0
// Name: _dynamic_atexit_destructor_for__cl_playerspraydisable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_playerspraydisable__()
{
  ConVar::~ConVar(this: &cl_playerspraydisable);
}

//------------------------------------------------------------------------------
// Address: 0x10436DB0
// Name: _dynamic_atexit_destructor_for____g_C_TEPlayerDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEPlayerDecal__()
{
  _g_C_TEPlayerDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEPlayerDecal_vtbl *)&C_TEPlayerDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEPlayerDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEPlayerDecal::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEPlayerDecal);
}
