// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_bspdecal.cpp
// Functions: 11
// ============================================================

#include "game\client\c_te_bspdecal.h"

//------------------------------------------------------------------------------
// Address: 0x10131FB0
// Name: public: virtual int C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102573A0
// Name: public: virtual class ClientClass __near * C_TEBSPDecal::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBSPDecal::GetClientClass(C_TEBSPDecal *this)
{
  return &__g_C_TEBSPDecalClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102574B0
// Name: void TE_BSPDecal(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BSPDecal(IRecipientFilter *filter, float delay, const Vector *pos, int entity, int index)
{
  C_BaseEntity *BaseEntity; // esi
  IVEfx_vtbl *v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax

  BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: entity);
  if ( BaseEntity != nullptr )
  {
    if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
    {
      v6 = effects->__vftable;
      v7 = ((int (__thiscall *)(C_BaseEntity *, const Vector *, _DWORD, int, _DWORD))BaseEntity->GetAbsAngles)(
             a1: BaseEntity,
             a2: pos,
             a3: 0,
             a4: 1,
             a5: 0);
      v8 = ((int (__thiscall *)(C_BaseEntity *, int))BaseEntity->GetAbsOrigin)(a1: BaseEntity, a2: v7);
      v9 = ((int (__thiscall *)(IClientRenderable *, int))BaseEntity->GetModel)(
             a1: &BaseEntity->IClientRenderable,
             a2: v8);
      ((void (__thiscall *)(IVEfx *, int, int, int))v6->DecalShoot)(a1: effects, a2: index, a3: entity, a4: v9);
    }
  }
  else
  {
    _DevMsg(a1: 1, a2: "Decal: entity = %i");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10257540
// Name: public: virtual void C_TEBSPDecal::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBSPDecal::PostDataUpdate(C_TEBSPDecal *this, DataUpdateType_t updateType)
{
  C_BaseEntity *BaseEntity; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  IVEfx_vtbl *v7; // [esp+8h] [ebp-4h]

  BaseEntity = CClientEntityList::GetBaseEntity(
                 this: (CClientEntityList *)cl_entitylist.m_Index,
                 entnum: LODWORD(this->m_vecOrigin.z));
  if ( BaseEntity != nullptr )
  {
    if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
    {
      v7 = effects->__vftable;
      v4 = ((int (__thiscall *)(C_BaseEntity *, C_BaseTempEntity **, _DWORD, int, _DWORD))BaseEntity->GetAbsAngles)(
             a1: BaseEntity,
             a2: &this->m_pNextDynamic,
             a3: 0,
             a4: 1,
             a5: 0);
      v5 = ((int (__thiscall *)(C_BaseEntity *, int))BaseEntity->GetAbsOrigin)(a1: BaseEntity, a2: v4);
      v6 = ((int (__thiscall *)(IClientRenderable *, int))BaseEntity->GetModel)(
             a1: &BaseEntity->IClientRenderable,
             a2: v5);
      ((void (__thiscall *)(IVEfx *, int, _DWORD, int))v7->DecalShoot)(
        a1: effects,
        a2: this->m_nEntity,
        a3: LODWORD(this->m_vecOrigin.z),
        a4: v6);
    }
  }
  else
  {
    _DevMsg(a1: 1, a2: "Decal: entity = %i");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042B940
// Name: DT_TEBSPDecal::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBSPDecal::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBSPDecal::g_RecvTable);
  return atexit(func: DT_TEBSPDecal::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B960
// Name: DT_TEBSPDecal::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBSPDecal::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBSPDecal::ignored>();
  DT_TEBSPDecal::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104369A0
// Name: DT_TEBSPDecal::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBSPDecal::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBSPDecal::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102573B0
// Name: _C_TEBSPDecal_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBSPDecal_CreateObject()
{
  return &_g_C_TEBSPDecal.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B970
// Name: _dynamic_initializer_for____g_C_TEBubbles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBubbles__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEBubbles);
  _g_C_TEBubbles.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBubbles_vtbl *)&C_TEBubbles::`vftable'{for `IClientUnknown'};
  _g_C_TEBubbles.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBubbles::`vftable'{for `IClientNetworkable'};
  _g_C_TEBubbles.m_vecMins.x = 0.0;
  _g_C_TEBubbles.m_vecMins.y = 0.0;
  _g_C_TEBubbles.m_vecMins.z = 0.0;
  _g_C_TEBubbles.m_vecMaxs.x = 0.0;
  _g_C_TEBubbles.m_vecMaxs.y = 0.0;
  _g_C_TEBubbles.m_vecMaxs.z = 0.0;
  _g_C_TEBubbles.m_fHeight = 0.0;
  _g_C_TEBubbles.m_nModelIndex = 0;
  _g_C_TEBubbles.m_nCount = 0;
  _g_C_TEBubbles.m_fSpeed = 0.0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBubbles__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B9F0
// Name: _dynamic_initializer_for____g_C_TEBubblesClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBubblesClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBubblesClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBubblesClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104369B0
// Name: _dynamic_atexit_destructor_for____g_C_TEBubbles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBubbles__()
{
  _g_C_TEBubbles.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBubbles_vtbl *)&C_TEBubbles::`vftable'{for `IClientUnknown'};
  _g_C_TEBubbles.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBubbles::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEBubbles);
}
