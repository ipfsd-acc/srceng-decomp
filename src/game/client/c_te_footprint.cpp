// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_footprint.cpp
// Functions: 9
// ============================================================

#include "game\client\c_te_footprint.h"

//------------------------------------------------------------------------------
// Address: 0x10259D70
// Name: public: virtual class ClientClass __near * C_TEFootprintDecal::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEFootprintDecal::GetClientClass(C_TEFootprintDecal *this)
{
  return &__g_C_TEFootprintDecalClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10259EB0
// Name: public: virtual void C_TEFootprintDecal::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEFootprintDecal::PostDataUpdate(C_TEFootprintDecal *this, DataUpdateType_t updateType)
{
  C_BaseEntity *BaseEntity; // eax
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  IVEfx_vtbl *v8; // [esp+4h] [ebp-4h]

  if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
  {
    BaseEntity = CClientEntityList::GetBaseEntity(
                   this: (CClientEntityList *)cl_entitylist.m_Index,
                   entnum: LODWORD(this->m_vecStart.z));
    v4 = &BaseEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( BaseEntity != nullptr )
    {
      v8 = effects->__vftable;
      v5 = ((int (__thiscall *)(C_BaseEntity *, C_BaseTempEntity **, float *, _DWORD, _DWORD))BaseEntity->GetAbsAngles)(
             a1: BaseEntity,
             a2: &this->m_pNextDynamic,
             a3: &this->m_vecOrigin.z,
             a4: 0,
             a5: 0);
      v6 = (*(int (__thiscall **)(_DWORD *, int))(*v4 + 40))(a1: v4, a2: v5);
      v7 = (*(int (__thiscall **)(_DWORD *, int))(v4[1] + 32))(a1: v4 + 1, a2: v6);
      ((void (__thiscall *)(IVEfx *, int, _DWORD, int))v8->DecalShoot)(
        a1: effects,
        a2: this->m_nEntity,
        a3: LODWORD(this->m_vecStart.z),
        a4: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10259F40
// Name: void TE_FootprintDecal(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_FootprintDecal(
        IRecipientFilter *filter,
        float delay,
        const Vector *origin,
        const Vector *right,
        int entity,
        int index)
{
  C_BaseEntity *BaseEntity; // eax
  _DWORD *v7; // esi
  IVEfx_vtbl *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax

  if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
  {
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: entity);
    v7 = &BaseEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( BaseEntity != nullptr )
    {
      v8 = effects->__vftable;
      v9 = ((int (__thiscall *)(C_BaseEntity *, const Vector *, const Vector *, _DWORD, _DWORD))BaseEntity->GetAbsAngles)(
             a1: BaseEntity,
             a2: origin,
             a3: right,
             a4: 0,
             a5: 0);
      v10 = (*(int (__thiscall **)(_DWORD *, int))(*v7 + 40))(a1: v7, a2: v9);
      v11 = (*(int (__thiscall **)(_DWORD *, int))(v7[1] + 32))(a1: v7 + 1, a2: v10);
      ((void (__thiscall *)(IVEfx *, int, int, int))v8->DecalShoot)(a1: effects, a2: index, a3: entity, a4: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042C1A0
// Name: DT_TEFootprintDecal::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFootprintDecal::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEFootprintDecal::g_RecvTable);
  return atexit(func: DT_TEFootprintDecal::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C1C0
// Name: DT_TEFootprintDecal::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFootprintDecal::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEFootprintDecal::ignored>();
  DT_TEFootprintDecal::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436B80
// Name: DT_TEFootprintDecal::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEFootprintDecal::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEFootprintDecal::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10259D80
// Name: _C_TEFootprintDecal_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEFootprintDecal_CreateObject()
{
  return &_g_C_TEFootprintDecal.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10436B90
// Name: _dynamic_atexit_destructor_for____g_C_TEFootprintDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEFootprintDecal__()
{
  _g_C_TEFootprintDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEFootprintDecal_vtbl *)&C_TEFootprintDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEFootprintDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEFootprintDecal::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEFootprintDecal);
}

//------------------------------------------------------------------------------
// Address: 0x10436BB0
// Name: _dynamic_atexit_destructor_for__fx_glass_velocity_cap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fx_glass_velocity_cap__()
{
  ConVar::~ConVar(this: &fx_glass_velocity_cap);
}
