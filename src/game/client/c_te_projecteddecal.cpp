// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_projecteddecal.cpp
// Functions: 13
// ============================================================

#include "game\client\c_te_projecteddecal.h"

//------------------------------------------------------------------------------
// Address: 0x10264B20
// Name: public: virtual class ClientClass __near * C_TEProjectedDecal::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEProjectedDecal::GetClientClass(C_TEProjectedDecal *this)
{
  return &__g_C_TEProjectedDecalClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10264C10
// Name: RecordProjectDecal
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordProjectDecal(const QAngle *angles@<edi>, const Vector *pos, float flDistance, int index)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  const char *value; // eax

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "TempEntity");
    else
      v5 = nullptr;
    KeyValues::SetInt(this: v5, keyName: "te", value: 18);
    KeyValues::SetString(this: v5, keyName: "name", value: "TE_ProjectDecal");
    KeyValues::SetFloat(this: v5, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v5, keyName: "originx", value: pos->x);
    KeyValues::SetFloat(this: v5, keyName: "originy", value: pos->y);
    KeyValues::SetFloat(this: v5, keyName: "originz", value: pos->z);
    KeyValues::SetFloat(this: v5, keyName: "anglesx", value: angles->x);
    KeyValues::SetFloat(this: v5, keyName: "anglesy", value: angles->y);
    KeyValues::SetFloat(this: v5, keyName: "anglesz", value: angles->z);
    KeyValues::SetFloat(this: v5, keyName: "distance", value: flDistance);
    value = effects->Draw_DecalNameFromIndex(this: effects, a2: index);
    KeyValues::SetString(this: v5, keyName: "decalname", value);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v5);
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264DA0
// Name: void TE_ProjectDecal(class IRecipientFilter __near &,float,class Vector const __near *,class QAngle const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ProjectDecal(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const QAngle *angles,
        float distance,
        int index)
{
  int v6; // ebx
  const Vector *v7; // esi
  const QAngle *v8; // edi
  CGameTrace tr; // [esp+14h] [ebp-6Ch] BYREF
  Vector fwd; // [esp+68h] [ebp-18h] BYREF
  Vector endpos; // [esp+74h] [ebp-Ch] BYREF

  v6 = index;
  v7 = pos;
  v8 = angles;
  RecordProjectDecal(pos, angles, flDistance: distance, index);
  AngleVectors(angles: v8, forward: &fwd);
  endpos.x = (float)(fwd.x * distance) + v7->x;
  endpos.y = (float)(fwd.y * distance) + v7->y;
  endpos.z = (float)(fwd.z * distance) + v7->z;
  pos = (const Vector *)&CTraceFilterHitAll::`vftable';
  UTIL_TraceLine(vecAbsStart: v7, vecAbsEnd: &endpos, mask: 0xFFFFFFFF, pFilter: (ITraceFilter *)&pos, ptr: &tr);
  if ( tr.fraction != 1.0 )
  {
    if ( tr.hitbox != 0 )
      staticpropmgr->AddDecalToStaticProp(
        this: staticpropmgr,
        a2: v7,
        a3: &endpos,
        a4: tr.hitbox - 1,
        a5: v6,
        a6: false,
        a7: &tr);
    else
      (*(void (__thiscall **)(struct CBaseEntity *, const Vector *, Vector *, Vector *, _DWORD, int, _DWORD, CGameTrace *, int))(*(_DWORD *)tr.m_pEnt + 472))(
        a1: tr.m_pEnt,
        a2: v7,
        a3: &endpos,
        a4: &endpos,
        a5: 0,
        a6: v6,
        a7: 0,
        a8: &tr,
        a9: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10264E90
// Name: public: virtual void C_TEProjectedDecal::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEProjectedDecal::PostDataUpdate(C_TEProjectedDecal *this, DataUpdateType_t updateType)
{
  CBroadcastRecipientFilter filter; // [esp+18h] [ebp-20h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  C_RecipientFilter::AddAllPlayers(this: &filter);
  TE_ProjectDecal(
    &filter,
    delay: 0.0,
    pos: (const Vector *)&this->m_pNextDynamic,
    angles: (const QAngle *)&this->m_vecOrigin.z,
    distance: this->m_angRotation.z,
    index: LODWORD(this->m_flDistance));
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10264EF0
// Name: void TE_ProjectDecal(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_ProjectDecal(int a1@<esi>, IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  const char *String; // eax
  int v5; // eax
  Vector vecOrigin; // [esp+1Ch] [ebp-1Ch] BYREF
  QAngle angles; // [esp+28h] [ebp-10h] BYREF
  float flDistance; // [esp+34h] [ebp-4h]

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  angles.x = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesx", defaultValue: 0.0);
  angles.y = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesy", defaultValue: 0.0);
  angles.z = KeyValues::GetFloat(this: pKeyValues, keyName: "anglesz", defaultValue: 0.0);
  flDistance = KeyValues::GetFloat(this: pKeyValues, keyName: "distance", defaultValue: 0.0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "decalname", defaultValue: prType);
  v5 = ((int (__thiscall *)(IVEfx *, const char *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))effects->Draw_DecalIndexFromName)(
         a1: effects,
         a2: String,
         a3: a1,
         a4: LODWORD(vecOrigin.x),
         a5: LODWORD(vecOrigin.y),
         a6: LODWORD(vecOrigin.z),
         a7: LODWORD(angles.x),
         a8: LODWORD(angles.y),
         a9: LODWORD(angles.z));
  TE_ProjectDecal(filter, delay: 0.0, pos: &vecOrigin, &angles, distance: flDistance, index: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1042CAA0
// Name: DT_TEProjectedDecal::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEProjectedDecal::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEProjectedDecal::g_RecvTable);
  return atexit(func: DT_TEProjectedDecal::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CAC0
// Name: DT_TEProjectedDecal::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEProjectedDecal::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEProjectedDecal::ignored>();
  DT_TEProjectedDecal::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436DE0
// Name: DT_TEProjectedDecal::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEProjectedDecal::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEProjectedDecal::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10264B30
// Name: _C_TEProjectedDecal_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEProjectedDecal_CreateObject()
{
  return &_g_C_TEProjectedDecal.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042CAD0
// Name: _dynamic_initializer_for____g_C_TEShowLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEShowLine__()
{
  C_TEParticleSystem::C_TEParticleSystem(this: &_g_C_TEShowLine);
  _g_C_TEShowLine.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEShowLine_vtbl *)&C_TEShowLine::`vftable'{for `IClientUnknown'};
  _g_C_TEShowLine.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEShowLine::`vftable'{for `IClientNetworkable'};
  _g_C_TEShowLine.m_vecEnd.x = 0.0;
  _g_C_TEShowLine.m_vecEnd.y = 0.0;
  _g_C_TEShowLine.m_vecEnd.z = 0.0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEShowLine__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CB20
// Name: _dynamic_initializer_for____g_C_TEShowLineClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEShowLineClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEShowLineClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEShowLineClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436DF0
// Name: _dynamic_atexit_destructor_for____g_C_TEProjectedDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEProjectedDecal__()
{
  _g_C_TEProjectedDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEProjectedDecal_vtbl *)&C_TEProjectedDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEProjectedDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEProjectedDecal::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEProjectedDecal);
}

//------------------------------------------------------------------------------
// Address: 0x10436E10
// Name: _dynamic_atexit_destructor_for____g_C_TEShowLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEShowLine__()
{
  _g_C_TEShowLine.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEShowLine_vtbl *)&C_TEShowLine::`vftable'{for `IClientUnknown'};
  _g_C_TEShowLine.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEShowLine::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEShowLine);
}
