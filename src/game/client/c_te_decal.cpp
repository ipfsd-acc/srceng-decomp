// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_decal.cpp
// Functions: 12
// ============================================================

#include "game\client\c_te_decal.h"

//------------------------------------------------------------------------------
// Address: 0x10257B70
// Name: public: virtual class ClientClass __near * C_TEDecal::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEDecal::GetClientClass(C_TEDecal *this)
{
  return &__g_C_TEDecalClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10257C80
// Name: RecordDecal
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordDecal(const Vector *start@<edi>, const Vector *pos, int entity, int hitbox, int index)
{
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  const char *value; // eax

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) && entity == 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TempEntity");
    else
      v6 = nullptr;
    KeyValues::SetInt(this: v6, keyName: "te", value: 17);
    KeyValues::SetString(this: v6, keyName: "name", value: "TE_Decal");
    KeyValues::SetFloat(this: v6, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v6, keyName: "originx", value: pos->x);
    KeyValues::SetFloat(this: v6, keyName: "originy", value: pos->y);
    KeyValues::SetFloat(this: v6, keyName: "originz", value: pos->z);
    KeyValues::SetFloat(this: v6, keyName: "startx", value: start->x);
    KeyValues::SetFloat(this: v6, keyName: "starty", value: start->y);
    KeyValues::SetFloat(this: v6, keyName: "startz", value: start->z);
    KeyValues::SetInt(this: v6, keyName: "hitbox", value: hitbox);
    value = effects->Draw_DecalNameFromIndex(this: effects, a2: index);
    KeyValues::SetString(this: v6, keyName: "decalname", value);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v6);
    KeyValues::deleteThis(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257E10
// Name: void TE_Decal(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_Decal(
        int a1@<ebp>,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *start,
        int entity,
        int hitbox,
        int index)
{
  C_BaseEntity *BaseEntity; // eax
  _BYTE v9[12]; // [esp-Ch] [ebp-B4h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-A8h] BYREF
  Ray_t ray; // [esp+58h] [ebp-50h]
  _UNKNOWN *retaddr; // [esp+A8h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a1;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  RecordDecal(pos, start, entity, hitbox, index);
  if ( entity != 0 || hitbox == 0 )
  {
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: entity);
    if ( BaseEntity != nullptr )
      BaseEntity->AddDecal(
        this: BaseEntity,
        a2: start,
        a3: pos,
        a4: pos,
        a5: hitbox,
        a6: index,
        a7: false,
        a8: (CGameTrace *)v9,
        a9: -1);
  }
  else
  {
    ray.m_Extents.y = 0.0;
    Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start, end: pos);
    staticpropmgr->AddDecalToStaticProp(
      this: staticpropmgr,
      a2: start,
      a3: pos,
      a4: hitbox - 1,
      a5: index,
      a6: false,
      a7: (CGameTrace *)v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257ED0
// Name: public: virtual void C_TEDecal::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEDecal::PostDataUpdate(C_TEDecal *this, DataUpdateType_t updateType)
{
  CBroadcastRecipientFilter filter; // [esp+1Ch] [ebp-20h] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  C_RecipientFilter::AddAllPlayers(this: &filter);
  TE_Decal(
    a1: (int)&savedregs,
    &filter,
    delay: 0.0,
    pos: (const Vector *)&this->m_pNextDynamic,
    start: (const Vector *)&this->m_vecOrigin.z,
    entity: LODWORD(this->m_vecStart.z),
    hitbox: this->m_nEntity,
    index: this->m_nHitbox);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10257F30
// Name: void TE_Decal(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_Decal(int a1@<edi>, int a2@<esi>, IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  int Int; // esi
  const char *String; // eax
  C_BaseEntity *BaseEntity; // eax
  CGameTrace v9; // [esp+Ch] [ebp-70h] BYREF
  Vector vecStart; // [esp+60h] [ebp-1Ch] BYREF
  Vector vecOrigin; // [esp+6Ch] [ebp-10h] BYREF
  int v12; // [esp+78h] [ebp-4h]

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  vecStart.x = KeyValues::GetFloat(this: pKeyValues, keyName: "startx", defaultValue: 0.0);
  vecStart.y = KeyValues::GetFloat(this: pKeyValues, keyName: "starty", defaultValue: 0.0);
  vecStart.z = KeyValues::GetFloat(this: pKeyValues, keyName: "startz", defaultValue: 0.0);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "hitbox", defaultValue: 0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "decalname", defaultValue: prType);
  v12 = ((int (__thiscall *)(IVEfx *, const char *, int, int))effects->Draw_DecalIndexFromName)(
          a1: effects,
          a2: String,
          a3: a1,
          a4: a2);
  RecordDecal(pos: &vecOrigin, start: &vecStart, entity: 0, hitbox: Int, index: v12);
  if ( Int != 0 )
  {
    ((void (__thiscall *)(IStaticPropMgrClient *, Vector *, Vector *, int, int))staticpropmgr->AddDecalToStaticProp)(
      a1: staticpropmgr,
      a2: &vecStart,
      a3: &vecOrigin,
      a4: Int - 1,
      a5: v12);
  }
  else
  {
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: 0);
    if ( BaseEntity != nullptr )
      BaseEntity->AddDecal(
        this: BaseEntity,
        a2: &vecStart,
        a3: &vecOrigin,
        a4: &vecOrigin,
        a5: 0,
        a6: v12,
        a7: false,
        a8: &v9,
        a9: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042BC70
// Name: DT_TEDecal::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDecal::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEDecal::g_RecvTable);
  return atexit(func: DT_TEDecal::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BC90
// Name: DT_TEDecal::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDecal::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEDecal::ignored>();
  DT_TEDecal::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436A40
// Name: DT_TEDecal::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEDecal::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEDecal::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10257B80
// Name: _C_TEDecal_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEDecal_CreateObject()
{
  return &_g_C_TEDecal.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042BCA0
// Name: _dynamic_initializer_for____g_C_TEDynamicLight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEDynamicLight__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEDynamicLight);
  _g_C_TEDynamicLight.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEDynamicLight_vtbl *)&C_TEDynamicLight::`vftable'{for `IClientUnknown'};
  _g_C_TEDynamicLight.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEDynamicLight::`vftable'{for `IClientNetworkable'};
  _g_C_TEDynamicLight.m_vecOrigin.x = 0.0;
  _g_C_TEDynamicLight.m_vecOrigin.y = 0.0;
  _g_C_TEDynamicLight.m_vecOrigin.z = 0.0;
  _g_C_TEDynamicLight.r = 0;
  _g_C_TEDynamicLight.g = 0;
  _g_C_TEDynamicLight.b = 0;
  _g_C_TEDynamicLight.exponent = 0;
  _g_C_TEDynamicLight.m_fRadius = 0.0;
  _g_C_TEDynamicLight.m_fTime = 0.0;
  _g_C_TEDynamicLight.m_fDecay = 0.0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEDynamicLight__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BD20
// Name: _dynamic_initializer_for____g_C_TEDynamicLightClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEDynamicLightClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEDynamicLightClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEDynamicLightClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436A50
// Name: _dynamic_atexit_destructor_for____g_C_TEDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEDecal__()
{
  _g_C_TEDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEDecal_vtbl *)&C_TEDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEDecal::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEDecal);
}
