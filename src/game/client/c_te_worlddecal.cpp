// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_worlddecal.cpp
// Functions: 11
// ============================================================

#include "game\client\c_te_worlddecal.h"

//------------------------------------------------------------------------------
// Address: 0x10266270
// Name: public: virtual class ClientClass __near * C_TEWorldDecal::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEWorldDecal::GetClientClass(C_TEWorldDecal *this)
{
  return &__g_C_TEWorldDecalClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10266330
// Name: RecordWorldDecal
// Source: json
//------------------------------------------------------------------------------
void __usercall RecordWorldDecal(const Vector *pos@<edi>, int index)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  const char *value; // eax

  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "TempEntity");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "te", value: 1);
    KeyValues::SetString(this: v3, keyName: "name", value: "TE_WorldDecal");
    KeyValues::SetFloat(this: v3, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    KeyValues::SetFloat(this: v3, keyName: "originx", value: pos->x);
    KeyValues::SetFloat(this: v3, keyName: "originy", value: pos->y);
    KeyValues::SetFloat(this: v3, keyName: "originz", value: pos->z);
    value = effects->Draw_DecalNameFromIndex(this: effects, a2: index);
    KeyValues::SetString(this: v3, keyName: "decalname", value);
    ToolFramework_PostToolMessage(hEntity: 0, msg: v3);
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10266460
// Name: public: virtual void C_TEWorldDecal::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEWorldDecal::PostDataUpdate(C_TEWorldDecal *this, DataUpdateType_t updateType)
{
  C_BaseEntity *BaseEntity; // eax
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  IVEfx_vtbl *v8; // [esp+8h] [ebp-4h]

  if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
  {
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: 0);
    v4 = &BaseEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( BaseEntity != nullptr )
    {
      v8 = effects->__vftable;
      v5 = ((int (__thiscall *)(C_BaseEntity *, C_BaseTempEntity **, _DWORD, _DWORD, _DWORD))BaseEntity->GetAbsAngles)(
             a1: BaseEntity,
             a2: &this->m_pNextDynamic,
             a3: 0,
             a4: 0,
             a5: 0);
      v6 = (*(int (__thiscall **)(_DWORD *, int))(*v4 + 40))(a1: v4, a2: v5);
      v7 = (*(int (__thiscall **)(_DWORD *, int))(v4[1] + 32))(a1: v4 + 1, a2: v6);
      ((void (__thiscall *)(IVEfx *, _DWORD, _DWORD, int))v8->DecalShoot)(
        a1: effects,
        a2: LODWORD(this->m_vecOrigin.z),
        a3: 0,
        a4: v7);
    }
  }
  RecordWorldDecal(pos: (const Vector *)&this->m_pNextDynamic, index: LODWORD(this->m_vecOrigin.z));
}

//------------------------------------------------------------------------------
// Address: 0x102664F0
// Name: void TE_WorldDecal(class IRecipientFilter __near &,float,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_WorldDecal(IRecipientFilter *filter, float delay, const Vector *pos, int index)
{
  C_BaseEntity *BaseEntity; // eax
  _DWORD *v5; // esi
  IVEfx_vtbl *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax

  if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
  {
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: 0);
    v5 = &BaseEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( BaseEntity != nullptr )
    {
      v6 = effects->__vftable;
      v7 = ((int (__thiscall *)(C_BaseEntity *, const Vector *, _DWORD, _DWORD, _DWORD))BaseEntity->GetAbsAngles)(
             a1: BaseEntity,
             a2: pos,
             a3: 0,
             a4: 0,
             a5: 0);
      v8 = (*(int (__thiscall **)(_DWORD *, int))(*v5 + 40))(a1: v5, a2: v7);
      v9 = (*(int (__thiscall **)(_DWORD *, int))(v5[1] + 32))(a1: v5 + 1, a2: v8);
      ((void (__thiscall *)(IVEfx *, int, _DWORD, int))v6->DecalShoot)(a1: effects, a2: index, a3: 0, a4: v9);
    }
  }
  RecordWorldDecal(pos, index);
}

//------------------------------------------------------------------------------
// Address: 0x10266570
// Name: void TE_WorldDecal(class IRecipientFilter __near &,float,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_WorldDecal(int a1@<esi>, IRecipientFilter *filter, float delay, KeyValues *pKeyValues)
{
  const char *String; // eax
  int v5; // eax
  Vector vecOrigin; // [esp+14h] [ebp-Ch] BYREF

  vecOrigin.x = KeyValues::GetFloat(this: pKeyValues, keyName: "originx", defaultValue: 0.0);
  vecOrigin.y = KeyValues::GetFloat(this: pKeyValues, keyName: "originy", defaultValue: 0.0);
  vecOrigin.z = KeyValues::GetFloat(this: pKeyValues, keyName: "originz", defaultValue: 0.0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "decalname", defaultValue: prType);
  v5 = ((int (__thiscall *)(IVEfx *, const char *, int, _DWORD, _DWORD, _DWORD))effects->Draw_DecalIndexFromName)(
         a1: effects,
         a2: String,
         a3: a1,
         a4: LODWORD(vecOrigin.x),
         a5: LODWORD(vecOrigin.y),
         a6: LODWORD(vecOrigin.z));
  TE_WorldDecal(filter, delay: 0.0, pos: &vecOrigin, index: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1042CE90
// Name: DT_TEWorldDecal::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEWorldDecal::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEWorldDecal::g_RecvTable);
  return atexit(func: DT_TEWorldDecal::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CEB0
// Name: DT_TEWorldDecal::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEWorldDecal::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEWorldDecal::ignored>();
  DT_TEWorldDecal::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436F00
// Name: DT_TEWorldDecal::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEWorldDecal::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEWorldDecal::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10266280
// Name: _C_TEWorldDecal_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEWorldDecal_CreateObject()
{
  return &_g_C_TEWorldDecal.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042CEC0
// Name: _dynamic_initializer_for____g_C_TestTracelineClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TestTracelineClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TestTracelineClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TestTracelineClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436F10
// Name: _dynamic_atexit_destructor_for____g_C_TEWorldDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEWorldDecal__()
{
  _g_C_TEWorldDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEWorldDecal_vtbl *)&C_TEWorldDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEWorldDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEWorldDecal::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEWorldDecal);
}
