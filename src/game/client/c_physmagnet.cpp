// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_physmagnet.cpp
// Functions: 20
// ============================================================

#include "game\client\c_physmagnet.h"

//------------------------------------------------------------------------------
// Address: 0x1007A170
// Name: public: virtual class ClientClass __near * C_PhysMagnet::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PhysMagnet::GetClientClass(C_PhysMagnet *this)
{
  return &__g_C_PhysMagnetClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1007A1F0
// Name: public: virtual void C_PhysMagnet::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysMagnet::PostDataUpdate(C_PhysMagnet *this, DataUpdateType_t updateType)
{
  C_BaseAnimating::PostDataUpdate(this, updateType);
}

//------------------------------------------------------------------------------
// Address: 0x1007A200
// Name: public: virtual bool C_PhysMagnet::GetShadowCastDirection(class Vector __near *,enum ShadowType_t)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_PhysMagnet::GetShadowCastDirection(C_PhysMagnet *this, Vector *pDirection, ShadowType_t shadowType)
{
  pDirection->x = 0.0;
  pDirection->y = 0.0;
  pDirection->z = -1.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007A230
// Name: public: C_PhysMagnet::C_PhysMagnet(void)
// Source: json
//------------------------------------------------------------------------------
C_PhysMagnet *__thiscall C_PhysMagnet::C_PhysMagnet(C_PhysMagnet *this)
{
  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PhysMagnet_vtbl *)&C_PhysMagnet::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PhysMagnet::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PhysMagnet::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PhysMagnet::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PhysMagnet::`vftable';
  this->m_aAttachedObjectsFromServer.m_Memory.m_pMemory = nullptr;
  this->m_aAttachedObjectsFromServer.m_Memory.m_nAllocationCount = 0;
  this->m_aAttachedObjectsFromServer.m_Memory.m_nGrowSize = 0;
  this->m_aAttachedObjectsFromServer.m_Size = 0;
  this->m_aAttachedObjectsFromServer.m_pElements = nullptr;
  this->m_aAttachedObjects.m_Memory.m_pMemory = nullptr;
  this->m_aAttachedObjects.m_Memory.m_nAllocationCount = 0;
  this->m_aAttachedObjects.m_Memory.m_nGrowSize = 0;
  this->m_aAttachedObjects.m_Size = 0;
  this->m_aAttachedObjects.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10412BD0
// Name: DT_PhysMagnet::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysMagnet::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PhysMagnet::g_RecvTable);
  return atexit(func: DT_PhysMagnet::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412BF0
// Name: DT_PhysMagnet::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysMagnet::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PhysMagnet::ignored>();
  DT_PhysMagnet::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430770
// Name: DT_PhysMagnet::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysMagnet::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PhysMagnet::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1007A2A0
// Name: _C_PhysMagnet_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PhysMagnet_CreateObject(int entnum, int serialNum)
{
  C_PhysMagnet *v2; // eax
  C_PhysMagnet *v3; // eax
  C_PhysMagnet *v4; // esi

  v2 = (C_PhysMagnet *)C_BaseEntity::operator new(stAllocateBlock: 0xCE0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PhysMagnet::C_PhysMagnet(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412C00
// Name: _dynamic_initializer_for__r_pixelvisibility_partial__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_pixelvisibility_partial__()
{
  ConVar::ConVar(this: &r_pixelvisibility_partial, pName: "r_pixelvisibility_partial", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_pixelvisibility_partial__);
}

//------------------------------------------------------------------------------
// Address: 0x10412C30
// Name: _dynamic_initializer_for__r_dopixelvisibility__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_dopixelvisibility__()
{
  ConVar::ConVar(this: &r_dopixelvisibility, pName: "r_dopixelvisibility", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_dopixelvisibility__);
}

//------------------------------------------------------------------------------
// Address: 0x10412C60
// Name: _dynamic_initializer_for__r_drawpixelvisibility__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawpixelvisibility__()
{
  ConVar::ConVar(
    this: &r_drawpixelvisibility,
    pName: "r_drawpixelvisibility",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show the occlusion proxies",
    callback: (void (__cdecl *)(IConVar *, const char *, float))PixelvisDrawChanged);
  return atexit(func: dynamic_atexit_destructor_for__r_drawpixelvisibility__);
}

//------------------------------------------------------------------------------
// Address: 0x10412C90
// Name: _dynamic_initializer_for__r_pixelvisibility_spew__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_pixelvisibility_spew__()
{
  ConVar::ConVar(this: &r_pixelvisibility_spew, pName: "r_pixelvisibility_spew", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_pixelvisibility_spew__);
}

//------------------------------------------------------------------------------
// Address: 0x10412CC0
// Name: _dynamic_initializer_for__s_OcclusionQueries__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_OcclusionQueries__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_OcclusionQueries__);
}

//------------------------------------------------------------------------------
// Address: 0x10430780
// Name: _dynamic_atexit_destructor_for__r_pixelvisibility_partial__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_pixelvisibility_partial__()
{
  ConVar::~ConVar(this: &r_pixelvisibility_partial);
}

//------------------------------------------------------------------------------
// Address: 0x10430790
// Name: _dynamic_atexit_destructor_for__r_dopixelvisibility__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_dopixelvisibility__()
{
  ConVar::~ConVar(this: &r_dopixelvisibility);
}

//------------------------------------------------------------------------------
// Address: 0x104307A0
// Name: _dynamic_atexit_destructor_for__r_drawpixelvisibility__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawpixelvisibility__()
{
  ConVar::~ConVar(this: &r_drawpixelvisibility);
}

//------------------------------------------------------------------------------
// Address: 0x104307B0
// Name: _dynamic_atexit_destructor_for__r_pixelvisibility_spew__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_pixelvisibility_spew__()
{
  ConVar::~ConVar(this: &r_pixelvisibility_spew);
}

//------------------------------------------------------------------------------
// Address: 0x104307C0
// Name: _dynamic_atexit_destructor_for__pixelvis_debug_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__pixelvis_debug_command__()
{
  ConCommand::~ConCommand(this: &pixelvis_debug_command);
}

//------------------------------------------------------------------------------
// Address: 0x104307D0
// Name: _dynamic_atexit_destructor_for__g_PixelVisibilitySystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PixelVisibilitySystem__()
{
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::~CUtlMultiList<CPixelVisibilityQuery,unsigned short>(this: &g_PixelVisibilitySystem.m_queryList);
  CUtlMultiList<CPixelVisSet,unsigned short>::~CUtlMultiList<CPixelVisSet,unsigned short>(this: &g_PixelVisibilitySystem.m_setList);
  IGameSystem::~IGameSystem(this: &g_PixelVisibilitySystem);
}

//------------------------------------------------------------------------------
// Address: 0x104307F0
// Name: _dynamic_atexit_destructor_for__s_OcclusionQueries__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_OcclusionQueries__()
{
  CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int>>::~CUtlVector<OcclusionQueryHiddenData_t,CUtlMemory<OcclusionQueryHiddenData_t,int>>(this: &s_OcclusionQueries);
}
