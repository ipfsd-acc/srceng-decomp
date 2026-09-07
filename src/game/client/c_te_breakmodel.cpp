// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_breakmodel.cpp
// Functions: 13
// ============================================================

#include "game\client\c_te_breakmodel.h"

//------------------------------------------------------------------------------
// Address: 0x10256C00
// Name: public: virtual class ClientClass __near * C_TEBreakModel::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBreakModel::GetClientClass(C_TEBreakModel *this)
{
  return &__g_C_TEBreakModelClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10256C20
// Name: RecordBreakModel
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordBreakModel(
        const Vector *vel@<edi>,
        int nModelIndex@<eax>,
        const Vector *start,
        const QAngle *angles,
        const Vector *size,
        int nRandomization,
        int nCount,
        float flDuration,
        int nFlags)
{
  const struct model_t *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  const char *pModelName; // [esp+Ch] [ebp-4h]

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    if ( nModelIndex != 0 && (v10 = modelinfo->GetModel(this: modelinfo, a2: nModelIndex)) != nullptr )
      pModelName = modelinfo->GetModelName(this: modelinfo, a2: v10);
    else
      pModelName = prType;
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "TempEntity");
    else
      v12 = nullptr;
    KeyValues::SetInt(this: v12, keyName: "te", value: 9);
    KeyValues::SetString(this: v12, keyName: "name", value: "TE_BreakModel");
    KeyValues::SetFloat(this: v12, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v12, keyName: "originx", value: start->x);
    KeyValues::SetFloat(this: v12, keyName: "originy", value: start->y);
    KeyValues::SetFloat(this: v12, keyName: "originz", value: start->z);
    KeyValues::SetFloat(this: v12, keyName: "anglesx", value: angles->x);
    KeyValues::SetFloat(this: v12, keyName: "anglesy", value: angles->y);
    KeyValues::SetFloat(this: v12, keyName: "anglesz", value: angles->z);
    KeyValues::SetFloat(this: v12, keyName: "sizex", value: size->x);
    KeyValues::SetFloat(this: v12, keyName: "sizey", value: size->y);
    KeyValues::SetFloat(this: v12, keyName: "sizez", value: size->z);
    KeyValues::SetFloat(this: v12, keyName: "velx", value: vel->x);
    KeyValues::SetFloat(this: v12, keyName: "vely", value: vel->y);
    KeyValues::SetFloat(this: v12, keyName: "velz", value: vel->z);
    KeyValues::SetString(this: v12, keyName: "model", value: pModelName);
    KeyValues::SetInt(this: v12, keyName: "randomization", value: nRandomization);
    KeyValues::SetInt(this: v12, keyName: "count", value: nCount);
    KeyValues::SetFloat(this: v12, keyName: "duration", value: flDuration);
    KeyValues::SetInt(this: v12, keyName: "flags", value: nFlags);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v12);
    KeyValues::deleteThis(this: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256E70
// Name: void TE_BreakModel(class IRecipientFilter __near &,float,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,int,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BreakModel(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const QAngle *angles,
        const Vector *size,
        const Vector *vel,
        int modelindex,
        int randomization,
        int count,
        float time,
        int flags)
{
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))tempents->BreakModel)(
    a1: tempents,
    a2: pos,
    a3: angles,
    a4: size,
    a5: vel,
    a6: (float)randomization,
    a7: LODWORD(time),
    a8: count,
    a9: modelindex,
    a10: flags);
  RecordBreakModel(
    start: pos,
    angles,
    size,
    vel,
    nModelIndex: randomization,
    nRandomization: (int)time,
    nCount: count,
    flDuration: (float)modelindex,
    nFlags: flags);
}

//------------------------------------------------------------------------------
// Address: 0x10256EF0
// Name: public: virtual void C_TEBreakModel::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBreakModel::PostDataUpdate(C_TEBreakModel *this, DataUpdateType_t updateType)
{
  const Vector *vel; // [esp+38h] [ebp-10h]
  const Vector *start; // [esp+3Ch] [ebp-Ch]
  const QAngle *angles; // [esp+40h] [ebp-8h]
  const Vector *size; // [esp+44h] [ebp-4h]

  vel = (const Vector *)&this->m_vecSize.z;
  start = (const Vector *)&this->m_pNextDynamic;
  size = (const Vector *)&this->m_angRotation.z;
  angles = (const QAngle *)&this->m_vecOrigin.z;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))tempents->BreakModel)(
    a1: tempents,
    a2: &this->m_pNextDynamic,
    a3: &this->m_vecOrigin.z,
    a4: &this->m_angRotation.z,
    a5: &this->m_vecSize.z,
    a6: (float)SLODWORD(this->m_vecVelocity.z),
    a7: this->m_nCount,
    a8: this->m_nModelIndex,
    a9: this->m_nRandomization,
    a10: LOBYTE(this->m_fTime));
  RecordBreakModel(
    vel,
    nModelIndex: LODWORD(this->m_vecVelocity.z),
    start,
    angles,
    size,
    nRandomization: (int)*(float *)&this->m_nCount,
    nCount: this->m_nModelIndex,
    flDuration: (float)this->m_nRandomization,
    nFlags: LODWORD(this->m_fTime));
}

//------------------------------------------------------------------------------
// Address: 0x10257160
// Name: void TE_BreakModel(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_BreakModel(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IRecipientFilter *filter,
        float delay,
        KeyValues *pKeyValues)
{
  const char *String; // eax
  int Int; // edi
  int v8; // ebx
  int v9; // esi
  Vector vecVel; // [esp+38h] [ebp-3Ch] BYREF
  Vector vecOrigin; // [esp+44h] [ebp-30h] BYREF
  QAngle angles; // [esp+50h] [ebp-24h] BYREF
  Vector vecSize; // [esp+5Ch] [ebp-18h] BYREF
  Color c; // [esp+68h] [ebp-Ch] BYREF
  float flDuration; // [esp+6Ch] [ebp-8h]
  int nModelIndex; // [esp+70h] [ebp-4h] BYREF

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  angles.x = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesx", defaultValue: 0.0);
  angles.y = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesy", defaultValue: 0.0);
  angles.z = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesz", defaultValue: 0.0);
  vecSize.x = KeyValues::GetFloat(this: pKeyValues, keyName: "sizex", defaultValue: 0.0);
  vecSize.y = KeyValues::GetFloat(this: pKeyValues, keyName: "sizey", defaultValue: 0.0);
  vecSize.z = KeyValues::GetFloat(this: pKeyValues, keyName: "sizez", defaultValue: 0.0);
  vecVel.x = KeyValues::GetFloat(this: pKeyValues, keyName: "velx", defaultValue: 0.0);
  vecVel.y = KeyValues::GetFloat(this: pKeyValues, keyName: "vely", defaultValue: 0.0);
  vecVel.z = KeyValues::GetFloat(this: pKeyValues, keyName: "velz", defaultValue: 0.0);
  nModelIndex = 0;
  KeyValues::GetColor(this: pKeyValues, result: &c, keyName: "color", defaultColor: (const Color *)&nModelIndex);
  String = KeyValues::GetString(this: pKeyValues, keyName: "model", defaultValue: prType);
  if ( *String != 0 )
    nModelIndex = modelinfo->GetModelIndex(this: modelinfo, a2: String);
  else
    nModelIndex = 0;
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "randomization", defaultValue: 0);
  v8 = KeyValues::GetInt(this: pKeyValues, keyName: "count", defaultValue: 0);
  flDuration = KeyValues::GetFloat(this: pKeyValues, keyName: "duration", defaultValue: 0.0);
  v9 = KeyValues::GetInt(this: pKeyValues, keyName: "flags", defaultValue: 0);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))tempents->BreakModel)(
    a1: tempents,
    a2: &vecOrigin,
    a3: &angles,
    a4: &vecSize,
    a5: &vecVel,
    a6: (float)Int,
    a7: LODWORD(flDuration),
    a8: v8,
    a9: nModelIndex,
    a10: v9,
    a11: a2,
    a12: a3,
    a13: a1);
  RecordBreakModel(
    start: &vecOrigin,
    &angles,
    size: &vecSize,
    vel: &vecVel,
    nModelIndex: Int,
    nRandomization: (int)flDuration,
    nCount: v8,
    flDuration: (float)nModelIndex,
    nFlags: v9);
}

//------------------------------------------------------------------------------
// Address: 0x1042B890
// Name: DT_TEBreakModel::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBreakModel::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBreakModel::g_RecvTable);
  return atexit(func: DT_TEBreakModel::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B8B0
// Name: DT_TEBreakModel::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBreakModel::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBreakModel::ignored>();
  DT_TEBreakModel::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436950
// Name: DT_TEBreakModel::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBreakModel::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBreakModel::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10256C10
// Name: _C_TEBreakModel_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBreakModel_CreateObject()
{
  return &_g_C_TEBreakModel.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B8C0
// Name: _dynamic_initializer_for____g_C_TEBSPDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBSPDecal__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEBSPDecal);
  _g_C_TEBSPDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBSPDecal_vtbl *)&C_TEBSPDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEBSPDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBSPDecal::`vftable'{for `IClientNetworkable'};
  _g_C_TEBSPDecal.m_vecOrigin.x = 0.0;
  _g_C_TEBSPDecal.m_vecOrigin.y = 0.0;
  _g_C_TEBSPDecal.m_vecOrigin.z = 0.0;
  _g_C_TEBSPDecal.m_nEntity = 0;
  _g_C_TEBSPDecal.m_nIndex = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBSPDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B920
// Name: _dynamic_initializer_for____g_C_TEBSPDecalClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBSPDecalClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBSPDecalClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBSPDecalClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436960
// Name: _dynamic_atexit_destructor_for____g_C_TEBreakModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBreakModel__()
{
  _g_C_TEBreakModel.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBreakModel_vtbl *)&C_TEBreakModel::`vftable'{for `IClientUnknown'};
  _g_C_TEBreakModel.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBreakModel::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEBreakModel);
}

//------------------------------------------------------------------------------
// Address: 0x10436980
// Name: _dynamic_atexit_destructor_for____g_C_TEBSPDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBSPDecal__()
{
  _g_C_TEBSPDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBSPDecal_vtbl *)&C_TEBSPDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEBSPDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBSPDecal::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEBSPDecal);
}
