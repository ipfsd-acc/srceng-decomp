// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/env_detail_controller.cpp
// Functions: 60
// ============================================================

#include "game\shared\env_detail_controller.h"

//------------------------------------------------------------------------------
// Address: 0x100D1950
// Name: public: virtual class ClientClass __near * C_EnvDetailController::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvDetailController::GetClientClass(C_EnvDetailController *this)
{
  return &__g_C_EnvDetailControllerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100D19E0
// Name: class C_EnvDetailController __near * GetDetailController(void)
// Source: json
//------------------------------------------------------------------------------
C_EnvDetailController *__cdecl GetDetailController()
{
  return s_detailController;
}

//------------------------------------------------------------------------------
// Address: 0x100D1AC0
// Name: CC_EnvDetailControllerFactory
// Source: json
//------------------------------------------------------------------------------
C_EnvDetailController *__cdecl CC_EnvDetailControllerFactory()
{
  C_BaseEntity *v0; // eax
  C_EnvDetailController *v1; // esi

  v0 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v1 = (C_EnvDetailController *)v0;
  if ( v0 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v0);
  v1->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvDetailController_vtbl *)&C_EnvDetailController::`vftable'{for `IClientUnknown'};
  v1->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvDetailController::`vftable'{for `IClientRenderable'};
  v1->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvDetailController::`vftable'{for `IClientNetworkable'};
  v1->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvDetailController::`vftable'{for `IClientThinkable'};
  v1->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvDetailController::`vftable';
  s_detailController = v1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x104155F0
// Name: DT_DetailController::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DetailController::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_DetailController::g_RecvTable);
  return atexit(func: DT_DetailController::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415610
// Name: DT_DetailController::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DetailController::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_DetailController::ignored>();
  DT_DetailController::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431540
// Name: DT_DetailController::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DetailController::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_DetailController::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100D1A50
// Name: _C_EnvDetailController_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvDetailController_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  C_EnvDetailController *v3; // esi
  bool (__thiscall *Init)(C_BaseEntity *, int, int); // eax

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = (C_EnvDetailController *)v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvDetailController_vtbl *)&C_EnvDetailController::`vftable'{for `IClientUnknown'};
  v3->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvDetailController::`vftable'{for `IClientRenderable'};
  v3->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvDetailController::`vftable'{for `IClientNetworkable'};
  v3->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvDetailController::`vftable'{for `IClientThinkable'};
  v3->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvDetailController::`vftable';
  Init = v3->Init;
  s_detailController = v3;
  Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10415620
// Name: _dynamic_initializer_for__cl_tree_sway_dir_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_tree_sway_dir_command__()
{
  ConCommand::ConCommand(
    this: &cl_tree_sway_dir_command,
    pName: "cl_tree_sway_dir",
    callback: (void (__cdecl *)())cl_tree_sway_dir,
    pHelpString: "sets tree sway wind direction and strength",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_tree_sway_dir_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10415650
// Name: _dynamic_initializer_for__s_windControllers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_windControllers__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_windControllers__);
}

//------------------------------------------------------------------------------
// Address: 0x10415660
// Name: _dynamic_initializer_for__g_EventList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EventList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EventList__);
}

//------------------------------------------------------------------------------
// Address: 0x10415670
// Name: _dynamic_initializer_for__g_EventStrings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EventStrings__()
{
  CStringRegistry::CStringRegistry(this: &g_EventStrings);
  return atexit(func: dynamic_atexit_destructor_for__g_EventStrings__);
}

//------------------------------------------------------------------------------
// Address: 0x10415690
// Name: _dynamic_initializer_for__r_swingflashlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_swingflashlight__()
{
  ConVar::ConVar(
    this: (ConVar *)&stru_10640DB4.m_InternalKeyFocusTicked_register,
    pName: "r_swingflashlight",
    pDefaultValue: "1",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_swingflashlight__);
}

//------------------------------------------------------------------------------
// Address: 0x104156C0
// Name: _dynamic_initializer_for__r_flashlightlockposition__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightlockposition__()
{
  ConVar::ConVar(
    this: (ConVar *)&stru_10640DB4.m_OverridableColorEntries.m_Memory.m_nAllocationCount,
    pName: "r_flashlightlockposition",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightlockposition__);
}

//------------------------------------------------------------------------------
// Address: 0x104156F0
// Name: _dynamic_initializer_for__r_flashlightfov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightfov__()
{
  ConVar::ConVar(this: (ConVar *)&stru_10640DB4.m_NavUp, pName: "r_flashlightfov", pDefaultValue: "53.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightfov__);
}

//------------------------------------------------------------------------------
// Address: 0x10415720
// Name: _dynamic_initializer_for__r_flashlightoffsetx__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightoffsetx__()
{
  ConVar::ConVar(
    this: (ConVar *)&stru_10640DB4.m_m_nBgTextureId2_register,
    pName: "r_flashlightoffsetright",
    pDefaultValue: "5.0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightoffsetx__);
}

//------------------------------------------------------------------------------
// Address: 0x10415750
// Name: _dynamic_initializer_for__r_flashlightoffsety__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightoffsety__()
{
  ConVar::ConVar(
    this: (ConVar *)&stru_10640DB4.m_nRowHeight,
    pName: "r_flashlightoffsetup",
    pDefaultValue: "-5.0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightoffsety__);
}

//------------------------------------------------------------------------------
// Address: 0x10415780
// Name: _dynamic_initializer_for__r_flashlightoffsetz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightoffsetz__()
{
  ConVar::ConVar(this: &r_flashlightoffsetz, pName: "r_flashlightoffsetforward", pDefaultValue: "0.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightoffsetz__);
}

//------------------------------------------------------------------------------
// Address: 0x104157B0
// Name: _dynamic_initializer_for__r_flashlightnear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightnear__()
{
  ConVar::ConVar(this: &r_flashlightnear, pName: "r_flashlightnear", pDefaultValue: "4.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightnear__);
}

//------------------------------------------------------------------------------
// Address: 0x104157E0
// Name: _dynamic_initializer_for__r_flashlightfar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightfar__()
{
  ConVar::ConVar(this: &r_flashlightfar, pName: "r_flashlightfar", pDefaultValue: "750.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightfar__);
}

//------------------------------------------------------------------------------
// Address: 0x10415810
// Name: _dynamic_initializer_for__r_flashlightconstant__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightconstant__()
{
  ConVar::ConVar(this: &r_flashlightconstant, pName: "r_flashlightconstant", pDefaultValue: "0.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightconstant__);
}

//------------------------------------------------------------------------------
// Address: 0x10415840
// Name: _dynamic_initializer_for__r_flashlightlinear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightlinear__()
{
  ConVar::ConVar(this: &r_flashlightlinear, pName: "r_flashlightlinear", pDefaultValue: "100.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightlinear__);
}

//------------------------------------------------------------------------------
// Address: 0x10415870
// Name: _dynamic_initializer_for__r_flashlightquadratic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightquadratic__()
{
  ConVar::ConVar(this: &r_flashlightquadratic, pName: "r_flashlightquadratic", pDefaultValue: "0.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightquadratic__);
}

//------------------------------------------------------------------------------
// Address: 0x104158A0
// Name: _dynamic_initializer_for__r_flashlightvisualizetrace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightvisualizetrace__()
{
  ConVar::ConVar(
    this: &r_flashlightvisualizetrace,
    pName: "r_flashlightvisualizetrace",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightvisualizetrace__);
}

//------------------------------------------------------------------------------
// Address: 0x104158D0
// Name: _dynamic_initializer_for__r_flashlightambient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightambient__()
{
  ConVar::ConVar(this: &r_flashlightambient, pName: "r_flashlightambient", pDefaultValue: "0.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightambient__);
}

//------------------------------------------------------------------------------
// Address: 0x10415900
// Name: _dynamic_initializer_for__r_flashlightshadowatten__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightshadowatten__()
{
  ConVar::ConVar(this: &r_flashlightshadowatten, pName: "r_flashlightshadowatten", pDefaultValue: "0.35", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightshadowatten__);
}

//------------------------------------------------------------------------------
// Address: 0x10415930
// Name: _dynamic_initializer_for__r_flashlightladderdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightladderdist__()
{
  ConVar::ConVar(this: &r_flashlightladderdist, pName: "r_flashlightladderdist", pDefaultValue: "40.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightladderdist__);
}

//------------------------------------------------------------------------------
// Address: 0x10415960
// Name: _dynamic_initializer_for__r_flashlight_topdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlight_topdown__()
{
  ConVar::ConVar(this: &r_flashlight_topdown, pName: "r_flashlight_topdown", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlight_topdown__);
}

//------------------------------------------------------------------------------
// Address: 0x10415990
// Name: _dynamic_initializer_for__r_flashlightnearoffsetscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightnearoffsetscale__()
{
  ConVar::ConVar(
    this: &r_flashlightnearoffsetscale,
    pName: "r_flashlightnearoffsetscale",
    pDefaultValue: "1.0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightnearoffsetscale__);
}

//------------------------------------------------------------------------------
// Address: 0x104159C0
// Name: _dynamic_initializer_for__r_flashlighttracedistcutoff__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlighttracedistcutoff__()
{
  ConVar::ConVar(
    this: &r_flashlighttracedistcutoff,
    pName: "r_flashlighttracedistcutoff",
    pDefaultValue: "128",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlighttracedistcutoff__);
}

//------------------------------------------------------------------------------
// Address: 0x104159F0
// Name: _dynamic_initializer_for__r_flashlightbacktraceoffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightbacktraceoffset__()
{
  ConVar::ConVar(
    this: &r_flashlightbacktraceoffset,
    pName: "r_flashlightbacktraceoffset",
    pDefaultValue: "0.4",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightbacktraceoffset__);
}

//------------------------------------------------------------------------------
// Address: 0x10415A20
// Name: _dynamic_initializer_for__r_flashlightmuzzleflashfov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightmuzzleflashfov__()
{
  ConVar::ConVar(
    this: &r_flashlightmuzzleflashfov,
    pName: "r_flashlightmuzzleflashfov",
    pDefaultValue: "120",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightmuzzleflashfov__);
}

//------------------------------------------------------------------------------
// Address: 0x10415A50
// Name: _dynamic_initializer_for__g_EntityHighlightEffects__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EntityHighlightEffects__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EntityHighlightEffects__);
}

//------------------------------------------------------------------------------
// Address: 0x10415A60
// Name: _dynamic_initializer_for__cl_foundry_ShowEntityHighlights__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_foundry_ShowEntityHighlights__()
{
  ConVar::ConVar(
    this: &cl_foundry_ShowEntityHighlights,
    pName: "cl_foundry_ShowEntityHighlights",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_foundry_ShowEntityHighlights__);
}

//------------------------------------------------------------------------------
// Address: 0x10415A90
// Name: _dynamic_initializer_for____g_C_TEFoundryHelpers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEFoundryHelpers__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEFoundryHelpers);
  _g_C_TEFoundryHelpers.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEFoundryHelpers_vtbl *)&C_TEFoundryHelpers::`vftable'{for `IClientUnknown'};
  _g_C_TEFoundryHelpers.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEFoundryHelpers::`vftable'{for `IClientNetworkable'};
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEFoundryHelpers__);
}

//------------------------------------------------------------------------------
// Address: 0x10415AC0
// Name: _dynamic_initializer_for____g_C_TEFoundryHelpersClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEFoundryHelpersClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEFoundryHelpersClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEFoundryHelpersClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431550
// Name: _dynamic_atexit_destructor_for__cl_tree_sway_dir_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_tree_sway_dir_command__()
{
  ConCommand::~ConCommand(this: &cl_tree_sway_dir_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431560
// Name: _dynamic_atexit_destructor_for__s_windControllers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_windControllers__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&s_windControllers);
  if ( s_windControllers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_windControllers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_windControllers.m_Memory.m_pMemory);
      s_windControllers.m_Memory.m_pMemory = nullptr;
    }
    s_windControllers.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104315B0
// Name: _dynamic_atexit_destructor_for__g_EventStrings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EventStrings__()
{
  CStringRegistry::~CStringRegistry(this: &g_EventStrings);
}

//------------------------------------------------------------------------------
// Address: 0x104315C0
// Name: _dynamic_atexit_destructor_for__g_EventList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EventList__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_EventList);
}

//------------------------------------------------------------------------------
// Address: 0x104315D0
// Name: _dynamic_atexit_destructor_for__r_swingflashlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_swingflashlight__()
{
  ConVar::~ConVar(this: (ConVar *)&stru_10640DB4.m_InternalKeyFocusTicked_register);
}

//------------------------------------------------------------------------------
// Address: 0x104315E0
// Name: _dynamic_atexit_destructor_for__r_flashlightlockposition__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightlockposition__()
{
  ConVar::~ConVar(this: (ConVar *)&stru_10640DB4.m_OverridableColorEntries.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x104315F0
// Name: _dynamic_atexit_destructor_for__r_flashlightfov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightfov__()
{
  ConVar::~ConVar(this: (ConVar *)&stru_10640DB4.m_NavUp);
}

//------------------------------------------------------------------------------
// Address: 0x10431600
// Name: _dynamic_atexit_destructor_for__r_flashlightoffsetx__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightoffsetx__()
{
  ConVar::~ConVar(this: (ConVar *)&stru_10640DB4.m_m_nBgTextureId2_register);
}

//------------------------------------------------------------------------------
// Address: 0x10431610
// Name: _dynamic_atexit_destructor_for__r_flashlightoffsety__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightoffsety__()
{
  ConVar::~ConVar(this: (ConVar *)&stru_10640DB4.m_nRowHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10431620
// Name: _dynamic_atexit_destructor_for__r_flashlightoffsetz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightoffsetz__()
{
  ConVar::~ConVar(this: &r_flashlightoffsetz);
}

//------------------------------------------------------------------------------
// Address: 0x10431630
// Name: _dynamic_atexit_destructor_for__r_flashlightnear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightnear__()
{
  ConVar::~ConVar(this: &r_flashlightnear);
}

//------------------------------------------------------------------------------
// Address: 0x10431640
// Name: _dynamic_atexit_destructor_for__r_flashlightfar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightfar__()
{
  ConVar::~ConVar(this: &r_flashlightfar);
}

//------------------------------------------------------------------------------
// Address: 0x10431650
// Name: _dynamic_atexit_destructor_for__r_flashlightconstant__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightconstant__()
{
  ConVar::~ConVar(this: &r_flashlightconstant);
}

//------------------------------------------------------------------------------
// Address: 0x10431660
// Name: _dynamic_atexit_destructor_for__r_flashlightlinear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightlinear__()
{
  ConVar::~ConVar(this: &r_flashlightlinear);
}

//------------------------------------------------------------------------------
// Address: 0x10431670
// Name: _dynamic_atexit_destructor_for__r_flashlightquadratic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightquadratic__()
{
  ConVar::~ConVar(this: &r_flashlightquadratic);
}

//------------------------------------------------------------------------------
// Address: 0x10431680
// Name: _dynamic_atexit_destructor_for__r_flashlightvisualizetrace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightvisualizetrace__()
{
  ConVar::~ConVar(this: &r_flashlightvisualizetrace);
}

//------------------------------------------------------------------------------
// Address: 0x10431690
// Name: _dynamic_atexit_destructor_for__r_flashlightambient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightambient__()
{
  ConVar::~ConVar(this: &r_flashlightambient);
}

//------------------------------------------------------------------------------
// Address: 0x104316A0
// Name: _dynamic_atexit_destructor_for__r_flashlightshadowatten__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightshadowatten__()
{
  ConVar::~ConVar(this: &r_flashlightshadowatten);
}

//------------------------------------------------------------------------------
// Address: 0x104316B0
// Name: _dynamic_atexit_destructor_for__r_flashlightladderdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightladderdist__()
{
  ConVar::~ConVar(this: &r_flashlightladderdist);
}

//------------------------------------------------------------------------------
// Address: 0x104316C0
// Name: _dynamic_atexit_destructor_for__r_flashlight_topdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlight_topdown__()
{
  ConVar::~ConVar(this: &r_flashlight_topdown);
}

//------------------------------------------------------------------------------
// Address: 0x104316D0
// Name: _dynamic_atexit_destructor_for__r_flashlightnearoffsetscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightnearoffsetscale__()
{
  ConVar::~ConVar(this: &r_flashlightnearoffsetscale);
}

//------------------------------------------------------------------------------
// Address: 0x104316E0
// Name: _dynamic_atexit_destructor_for__r_flashlighttracedistcutoff__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlighttracedistcutoff__()
{
  ConVar::~ConVar(this: &r_flashlighttracedistcutoff);
}

//------------------------------------------------------------------------------
// Address: 0x104316F0
// Name: _dynamic_atexit_destructor_for__r_flashlightbacktraceoffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightbacktraceoffset__()
{
  ConVar::~ConVar(this: &r_flashlightbacktraceoffset);
}

//------------------------------------------------------------------------------
// Address: 0x10431700
// Name: _dynamic_atexit_destructor_for__r_flashlightmuzzleflashfov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightmuzzleflashfov__()
{
  ConVar::~ConVar(this: &r_flashlightmuzzleflashfov);
}

//------------------------------------------------------------------------------
// Address: 0x10431710
// Name: _dynamic_atexit_destructor_for__cl_foundry_ShowEntityHighlights__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_foundry_ShowEntityHighlights__()
{
  ConVar::~ConVar(this: &cl_foundry_ShowEntityHighlights);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10111210
// Name: public: virtual class ServerClass __near * CEnvDetailController::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvDetailController::GetServerClass(CEnvDetailController *this)
{
  return &g_CEnvDetailController_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10111390
// Name: public: virtual bool CEnvDetailController::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEnvDetailController::KeyValue(CEnvDetailController *this, const char *szKeyName, const char *szValue)
{
  long double v4; // st7
  edict_t *v6; // ecx
  long double v7; // st7
  edict_t *m_pPev; // ecx
  float szValuea; // [esp+14h] [ebp+Ch]
  float szValueb; // [esp+14h] [ebp+Ch]

  if ( szKeyName != "fademindist" && _V_stricmp(s1: szKeyName, s2: "fademindist") != 0 )
  {
    if ( szKeyName == "fademaxdist" || _V_stricmp(s1: szKeyName, s2: "fademaxdist") == 0 )
    {
      v7 = atof(nptr: szValue);
      if ( this->m_flFadeEndDist.m_Value != v7 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
        }
        szValueb = v7;
        this->m_flFadeEndDist.m_Value = szValueb;
      }
    }
    return 1;
  }
  v4 = atof(nptr: szValue);
  szValuea = v4;
  if ( this->m_flFadeStartDist.m_Value == v4 )
    return 1;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    this->m_flFadeStartDist.m_Value = szValuea;
    return 1;
  }
  else
  {
    v6 = this->m_Network.m_pPev;
    if ( v6 != nullptr )
      CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x354u);
    this->m_flFadeStartDist.m_Value = szValuea;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402690
// Name: DT_DetailController::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DetailController::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_DetailController::g_SendTable);
  return atexit(func: DT_DetailController::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104026B0
// Name: DT_DetailController::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DetailController::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_DetailController::ignored>();
  DT_DetailController::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AD80
// Name: DT_DetailController::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DetailController::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_DetailController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104026C0
// Name: _dynamic_initializer_for__env_dof_controller__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_dof_controller__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvDOFController> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_dof_controller,
           a3: "env_dof_controller");
}

//------------------------------------------------------------------------------
// Address: 0x1041AD90
// Name: _ServerClassInit_DT_DetailController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_DetailController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_81;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
