// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/animatespecifictextureproxy.cpp
// Functions: 108
// ============================================================

#include "game\client\animatespecifictextureproxy.h"

//------------------------------------------------------------------------------
// Address: 0x10008CD0
// Name: public: virtual bool CAnimateSpecificTexture::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAnimateSpecificTexture::Init(
        CAnimateSpecificTexture *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  const char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "onlyAnimateOnTexture", defaultValue: prType);
  if ( String == nullptr )
    return false;
  CUtlString::Set(this: &this->m_OnlyAnimateOnTexture, pValue: String);
  return CBaseAnimatedTextureProxy::Init(this, pMaterial, pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x10008D20
// Name: public: virtual void CAnimateSpecificTexture::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimateSpecificTexture::OnBind(CAnimateSpecificTexture *this, void *pC_BaseEntity)
{
  ITexture *v3; // edi
  const char *v4; // ebx
  const char *v5; // eax

  v3 = this->m_AnimatedTextureVar->GetTextureValue(this: this->m_AnimatedTextureVar);
  v4 = CUtlString::operator char const *(this: &this->m_OnlyAnimateOnTexture);
  v5 = (const char *)v3->GetName(this: v3);
  if ( _V_stricmp(s1: v5, s2: v4) == 0 )
    CBaseAnimatedTextureProxy::OnBind(this, pEntity: pC_BaseEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10008D70
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008DB0
// Name: public: virtual float CAnimateSpecificTexture::GetAnimationStartTime(void __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAnimateSpecificTexture::GetAnimationStartTime(CAnimatedTextureProxy *this, void *pBaseEntity)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10008DC0
// Name: CCAnimateSpecificTextureFactory
// Source: json
//------------------------------------------------------------------------------
CBaseAnimatedTextureProxy *__cdecl CCAnimateSpecificTextureFactory()
{
  CBaseAnimatedTextureProxy *v0; // eax
  CBaseAnimatedTextureProxy *v1; // esi

  v0 = (CBaseAnimatedTextureProxy *)MemAlloc_Alloc(nSize: 0x24u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CBaseAnimatedTextureProxy::CBaseAnimatedTextureProxy(this: v0);
  v1->__vftable = (CBaseAnimatedTextureProxy_vtbl *)&CAnimateSpecificTexture::`vftable';
  CUtlString::CUtlString(this: (CUtlString *)&v1[1]);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x104111D0
// Name: _dynamic_initializer_for__spec_track__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_track__()
{
  ConVar::ConVar(
    this: &spec_track,
    pName: "spec_track",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Tracks an entity in spec mode");
  return atexit(func: dynamic_atexit_destructor_for__spec_track__);
}

//------------------------------------------------------------------------------
// Address: 0x10411280
// Name: _dynamic_initializer_for__spec_freeze_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_freeze_time__()
{
  ConVar::ConVar(
    this: &spec_freeze_time,
    pName: "spec_freeze_time",
    pDefaultValue: "5.0",
    flags: 0x2000,
    pHelpString: "Time spend frozen in observer freeze cam.");
  return atexit(func: dynamic_atexit_destructor_for__spec_freeze_time__);
}

//------------------------------------------------------------------------------
// Address: 0x104112B0
// Name: _dynamic_initializer_for__spec_freeze_traveltime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_freeze_traveltime__()
{
  ConVar::ConVar(
    this: &spec_freeze_traveltime,
    pName: "spec_freeze_traveltime",
    pDefaultValue: "0.7",
    flags: 24576,
    pHelpString: "Time taken to zoom in to frame a target in observer freeze cam.",
    bMin: true,
    fMin: 0.0099999998,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__spec_freeze_traveltime__);
}

//------------------------------------------------------------------------------
// Address: 0x10411300
// Name: _dynamic_initializer_for__spec_freeze_distance_min__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_freeze_distance_min__()
{
  ConVar::ConVar(
    this: &spec_freeze_distance_min,
    pName: "spec_freeze_distance_min",
    pDefaultValue: "80",
    flags: 0x4000,
    pHelpString: "Minimum random distance from the target to stop when framing them in observer freeze cam.");
  return atexit(func: dynamic_atexit_destructor_for__spec_freeze_distance_min__);
}

//------------------------------------------------------------------------------
// Address: 0x10411330
// Name: _dynamic_initializer_for__spec_freeze_distance_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_freeze_distance_max__()
{
  ConVar::ConVar(
    this: &spec_freeze_distance_max,
    pName: "spec_freeze_distance_max",
    pDefaultValue: "90",
    flags: 0x4000,
    pHelpString: "Maximum random distance from the target to stop when framing them in observer freeze cam.");
  return atexit(func: dynamic_atexit_destructor_for__spec_freeze_distance_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10411360
// Name: _dynamic_initializer_for__spec_freeze_panel_extended_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_freeze_panel_extended_time__()
{
  ConVar::ConVar(
    this: &spec_freeze_panel_extended_time,
    pName: "spec_freeze_panel_extended_time",
    pDefaultValue: "0.0",
    flags: 0x2000,
    pHelpString: "Time spent with the freeze panel still up after observer freeze cam is done.");
  return atexit(func: dynamic_atexit_destructor_for__spec_freeze_panel_extended_time__);
}

//------------------------------------------------------------------------------
// Address: 0x104168C0
// Name: _dynamic_initializer_for__spec_autodirector__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_autodirector__()
{
  ConVar::ConVar(
    this: &spec_autodirector,
    pName: "spec_autodirector",
    pDefaultValue: "1",
    flags: 1073741832,
    pHelpString: "Auto-director chooses best view modes while spectating");
  return atexit(func: dynamic_atexit_destructor_for__spec_autodirector__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE40
// Name: _dynamic_initializer_for__spec_pos_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_pos_command__()
{
  ConCommand::ConCommand(
    this: &spec_pos_command,
    pName: "spec_pos",
    callback: (void (__cdecl *)())spec_pos,
    pHelpString: "dump position and angles to the console",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__spec_pos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10427970
// Name: _dynamic_initializer_for__spec_menu_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_menu_command__()
{
  ConCommand::ConCommand(
    this: &spec_menu_command,
    pName: "spec_menu",
    callback: (void (__cdecl *)())spec_menu,
    pHelpString: "Activates spectator menu",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__spec_menu_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104279A0
// Name: _dynamic_initializer_for__spec_gui_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_gui_command__()
{
  ConCommand::ConCommand(
    this: &spec_gui_command,
    pName: "spec_gui",
    callback: (void (__cdecl *)())spec_gui,
    pHelpString: "Shows or hides the spectator bar",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__spec_gui_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1042FF90
// Name: _dynamic_atexit_destructor_for__spec_track__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_track__()
{
  ConVar::~ConVar(this: &spec_track);
}

//------------------------------------------------------------------------------
// Address: 0x1042FFC0
// Name: _dynamic_atexit_destructor_for__spec_freeze_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_freeze_time__()
{
  ConVar::~ConVar(this: &spec_freeze_time);
}

//------------------------------------------------------------------------------
// Address: 0x1042FFD0
// Name: _dynamic_atexit_destructor_for__spec_freeze_traveltime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_freeze_traveltime__()
{
  ConVar::~ConVar(this: &spec_freeze_traveltime);
}

//------------------------------------------------------------------------------
// Address: 0x1042FFE0
// Name: _dynamic_atexit_destructor_for__spec_freeze_distance_min__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_freeze_distance_min__()
{
  ConVar::~ConVar(this: &spec_freeze_distance_min);
}

//------------------------------------------------------------------------------
// Address: 0x1042FFF0
// Name: _dynamic_atexit_destructor_for__spec_freeze_distance_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_freeze_distance_max__()
{
  ConVar::~ConVar(this: &spec_freeze_distance_max);
}

//------------------------------------------------------------------------------
// Address: 0x10430000
// Name: _dynamic_atexit_destructor_for__spec_freeze_panel_extended_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_freeze_panel_extended_time__()
{
  ConVar::~ConVar(this: &spec_freeze_panel_extended_time);
}

//------------------------------------------------------------------------------
// Address: 0x10431A70
// Name: _dynamic_atexit_destructor_for__spec_autodirector__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_autodirector__()
{
  ConVar::~ConVar(this: &spec_autodirector);
}

//------------------------------------------------------------------------------
// Address: 0x104341C0
// Name: _dynamic_atexit_destructor_for__spec_pos_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_pos_command__()
{
  ConCommand::~ConCommand(this: &spec_pos_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435DB0
// Name: _dynamic_atexit_destructor_for__spec_menu_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_menu_command__()
{
  ConCommand::~ConCommand(this: &spec_menu_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435DC0
// Name: _dynamic_atexit_destructor_for__spec_gui_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spec_gui_command__()
{
  ConCommand::~ConCommand(this: &spec_gui_command);
}

//------------------------------------------------------------------------------
// Address: 0x10411200
// Name: _dynamic_initializer_for__cl_smooth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_smooth__()
{
  ConVar::ConVar(
    this: &cl_smooth,
    pName: "cl_smooth",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Smooth view/eye origin after prediction errors");
  return atexit(func: dynamic_atexit_destructor_for__cl_smooth__);
}

//------------------------------------------------------------------------------
// Address: 0x10411230
// Name: _dynamic_initializer_for__cl_smoothtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_smoothtime__()
{
  ConVar::ConVar(
    this: &cl_smoothtime,
    pName: "cl_smoothtime",
    pDefaultValue: "0.1",
    flags: 0,
    pHelpString: "Smooth client's view after prediction error over this many seconds",
    bMin: true,
    fMin: 0.0099999998,
    bMax: true,
    fMax: 2.0);
  return atexit(func: dynamic_atexit_destructor_for__cl_smoothtime__);
}

//------------------------------------------------------------------------------
// Address: 0x104168F0
// Name: _dynamic_initializer_for__s_HLTVCamera__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_HLTVCamera__()
{
  C_HLTVCamera::C_HLTVCamera(this: &s_HLTVCamera);
  return atexit(func: dynamic_atexit_destructor_for__s_HLTVCamera__);
}

//------------------------------------------------------------------------------
// Address: 0x10416910
// Name: _dynamic_initializer_for__g_HudTextureMemoryPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HudTextureMemoryPool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_HudTextureMemoryPool,
    blockSize: 0xACu,
    numElements: 128,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_HudTextureMemoryPool__);
}

//------------------------------------------------------------------------------
// Address: 0x10416940
// Name: _dynamic_initializer_for__hidehud__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hidehud__()
{
  ConVar::ConVar(this: &hidehud, pName: "hidehud", pDefaultValue: "0", flags: 49152);
  return atexit(func: dynamic_atexit_destructor_for__hidehud__);
}

//------------------------------------------------------------------------------
// Address: 0x10416970
// Name: _dynamic_initializer_for__gHUD__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gHUD__()
{
  gHUD[0].m_clrNormal = 0;
  gHUD[0].m_clrCaution = 0;
  gHUD[0].m_clrYellowish = 0;
  gHUD[0].m_HudList.m_Memory.m_pMemory = nullptr;
  gHUD[0].m_HudList.m_Memory.m_nAllocationCount = 0;
  gHUD[0].m_HudList.m_Memory.m_nGrowSize = 0;
  gHUD[0].m_HudList.m_Size = 0;
  gHUD[0].m_HudList.m_pElements = nullptr;
  gHUD[0].m_HudPanelList.m_Memory.m_pMemory = nullptr;
  gHUD[0].m_HudPanelList.m_Memory.m_nAllocationCount = 0;
  gHUD[0].m_HudPanelList.m_Memory.m_nGrowSize = 0;
  gHUD[0].m_HudPanelList.m_Size = 0;
  gHUD[0].m_HudPanelList.m_pElements = nullptr;
  gHUD[0].m_RenderGroupNames.m_Memory.m_pMemory = nullptr;
  gHUD[0].m_RenderGroupNames.m_Memory.m_nAllocationCount = 0;
  gHUD[0].m_RenderGroupNames.m_Memory.m_nGrowSize = 0;
  gHUD[0].m_RenderGroupNames.m_Size = 0;
  gHUD[0].m_RenderGroupNames.m_pElements = nullptr;
  gHUD[0].m_RenderGroups.m_Tree.m_Elements.m_pMemory = nullptr;
  gHUD[0].m_RenderGroups.m_Tree.m_Elements.m_nAllocationCount = 0;
  gHUD[0].m_RenderGroups.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&gHUD[0].m_RenderGroups.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&gHUD[0].m_RenderGroups.m_Tree.m_FirstFree = -1;
  gHUD[0].m_RenderGroups.m_Tree.m_pElements = nullptr;
  gHUD[0].m_RenderGroups.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))lessFunc;
  gHUD[0].m_flScreenShotTime = -1.0;
  gHUD[0].m_nSplitScreenSlot = -1;
  gHUD[0].m_bEngineIsInGame = false;
  return atexit(func: dynamic_atexit_destructor_for__gHUD__);
}

//------------------------------------------------------------------------------
// Address: 0x10416A30
// Name: _dynamic_initializer_for__testhudanim_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__testhudanim_command__()
{
  ConCommand::ConCommand(
    this: &testhudanim_command,
    pName: "testhudanim",
    callback: (void (__cdecl *)())testhudanim,
    pHelpString: "Test a hud element animation.\n\tArguments: <anim name>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__testhudanim_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10416A60
// Name: _dynamic_initializer_for__g_HudIcons__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HudIcons__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_HudIcons__);
}

//------------------------------------------------------------------------------
// Address: 0x10416A70
// Name: _dynamic_initializer_for__g_CHudAnimationInfo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudAnimationInfo_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudAnimationInfo_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudAnimationInfo,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10416A90
// Name: _dynamic_initializer_for__cl_animationinfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_animationinfo_command__()
{
  ConCommand::ConCommand(
    this: &cl_animationinfo_command,
    pName: "cl_animationinfo",
    callback: (void (__cdecl *)())cl_animationinfo,
    pHelpString: "Hud element to examine.",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))HudElementCompletion);
  return atexit(func: dynamic_atexit_destructor_for__cl_animationinfo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10416AC0
// Name: _dynamic_initializer_for__hud_saytext_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_saytext_time__()
{
  ConVar::ConVar(this: &hud_saytext_time, pName: "hud_saytext_time", pDefaultValue: "12", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__hud_saytext_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10416AF0
// Name: _dynamic_initializer_for__cl_showtextmsg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showtextmsg__()
{
  ConVar::ConVar(
    this: &cl_showtextmsg,
    pName: "cl_showtextmsg",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable/disable text messages printing on the screen.");
  return atexit(func: dynamic_atexit_destructor_for__cl_showtextmsg__);
}

//------------------------------------------------------------------------------
// Address: 0x10416B20
// Name: _dynamic_initializer_for__cl_chat_active__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_chat_active__()
{
  ConVar::ConVar(this: &cl_chat_active, pName: "cl_chat_active", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_chat_active__);
}

//------------------------------------------------------------------------------
// Address: 0x10416B50
// Name: _dynamic_initializer_for__cl_chatfilters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_chatfilters__()
{
  ConVar::ConVar(
    this: &cl_chatfilters,
    pName: "cl_chatfilters",
    pDefaultValue: "63",
    flags: 136,
    pHelpString: "Stores the chat filter settings ");
  return atexit(func: dynamic_atexit_destructor_for__cl_chatfilters__);
}

//------------------------------------------------------------------------------
// Address: 0x10416B80
// Name: _dynamic_initializer_for__cl_chatfilter_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_chatfilter_version__()
{
  ConVar::ConVar(
    this: &cl_chatfilter_version,
    pName: "cl_chatfilter_version",
    pDefaultValue: "0",
    flags: 152,
    pHelpString: "Stores the chat filter version");
  return atexit(func: dynamic_atexit_destructor_for__cl_chatfilter_version__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DE70
// Name: _dynamic_initializer_for__getpos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__getpos_command__()
{
  ConCommand::ConCommand(
    this: &getpos_command,
    pName: "getpos",
    callback: (void (__cdecl *)())getpos,
    pHelpString: "dump position and angles to the console",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__getpos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DEA0
// Name: _dynamic_initializer_for__getpos_exact__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__getpos_exact__()
{
  ConCommand::ConCommand(
    this: &getpos_exact,
    pName: "getpos_exact",
    callback: (void (__cdecl *)())getpos,
    pHelpString: "dump origin and angles to the console",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__getpos_exact__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DED0
// Name: _dynamic_initializer_for__r_DrawBeams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_DrawBeams__()
{
  ConVar::ConVar(
    this: &r_DrawBeams,
    pName: "r_DrawBeams",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "0=Off, 1=Normal, 2=Wireframe");
  return atexit(func: dynamic_atexit_destructor_for__r_DrawBeams__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF00
// Name: _dynamic_initializer_for__s_ViewRenderBeams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ViewRenderBeams__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_ViewRenderBeams__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF10
// Name: _dynamic_initializer_for__beamRandom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUniformRandomStream *dynamic_initializer_for__beamRandom__()
{
  return CUniformRandomStream::CUniformRandomStream(this: &beamRandom);
}

//------------------------------------------------------------------------------
// Address: 0x1041DF20
// Name: _dynamic_initializer_for__cl_beam_test_traces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_beam_test_traces__()
{
  ConVar::ConVar(
    this: &cl_beam_test_traces,
    pName: "cl_beam_test_traces",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Enable debug overlay on traces that determine where the client-side visible env_beam is drawn. Has no bearing on the"
    " server-side damage-causing part of the beam.");
  return atexit(func: dynamic_atexit_destructor_for__cl_beam_test_traces__);
}

//------------------------------------------------------------------------------
// Address: 0x104279D0
// Name: _dynamic_initializer_for__togglescores_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__togglescores_command__()
{
  ConCommand::ConCommand(
    this: &togglescores_command,
    pName: "togglescores",
    callback: togglescores,
    pHelpString: "Toggles score panel",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__togglescores_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10427A00
// Name: _dynamic_initializer_for__hidescores_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hidescores_command__()
{
  ConCommand::ConCommand(
    this: &hidescores_command,
    pName: "hidescores",
    callback: hidescores,
    pHelpString: "Forcibly hide score panel",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hidescores_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10427A30
// Name: _dynamic_initializer_for__g_CC4PanelFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CC4PanelFactory__()
{
  CPanelMetaClassMgrImp *v0; // eax

  v0 = PanelMetaClassMgr();
  return ((int (__thiscall *)(CPanelMetaClassMgrImp *, const char *, CPanelFactory<CC4Panel,VGuiScreenInitData_t> *))v0->InstallPanelType)(
           a1: v0,
           a2: "c4_panel",
           a3: &g_CC4PanelFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10427A50
// Name: _dynamic_initializer_for__g_CViewC4PanelFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CViewC4PanelFactory__()
{
  CPanelMetaClassMgrImp *v0; // eax

  v0 = PanelMetaClassMgr();
  return ((int (__thiscall *)(CPanelMetaClassMgrImp *, const char *, CPanelFactory<CViewC4Panel,VGuiScreenInitData_t> *))v0->InstallPanelType)(
           a1: v0,
           a2: "c4_view_panel",
           a3: &g_CViewC4PanelFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10427A70
// Name: _dynamic_initializer_for____g_C_DecoyProjectileClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_DecoyProjectileClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_DecoyProjectileClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_DecoyProjectileClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042FFA0
// Name: _dynamic_atexit_destructor_for__cl_smooth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_smooth__()
{
  ConVar::~ConVar(this: &cl_smooth);
}

//------------------------------------------------------------------------------
// Address: 0x1042FFB0
// Name: _dynamic_atexit_destructor_for__cl_smoothtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_smoothtime__()
{
  ConVar::~ConVar(this: &cl_smoothtime);
}

//------------------------------------------------------------------------------
// Address: 0x10431A80
// Name: _dynamic_atexit_destructor_for__s_HLTVCamera__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_HLTVCamera__()
{
  s_HLTVCamera.m_LastCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  s_HLTVCamera.__vftable = (C_HLTVCamera_vtbl *)&CGameEventListener::`vftable';
  s_HLTVCamera.m_nDebugID = 13;
  if ( s_HLTVCamera.m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &s_HLTVCamera);
    s_HLTVCamera.m_bRegisteredForEvents = false;
  }
  s_HLTVCamera.__vftable = (C_HLTVCamera_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10431AD0
// Name: _dynamic_atexit_destructor_for__hidehud__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hidehud__()
{
  ConVar::~ConVar(this: &hidehud);
}

//------------------------------------------------------------------------------
// Address: 0x10431AE0
// Name: _dynamic_atexit_destructor_for__testhudanim_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__testhudanim_command__()
{
  ConCommand::~ConCommand(this: &testhudanim_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431AF0
// Name: _dynamic_atexit_destructor_for__g_HudTextureMemoryPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_HudTextureMemoryPool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_HudTextureMemoryPool);
}

//------------------------------------------------------------------------------
// Address: 0x10431B00
// Name: _dynamic_atexit_destructor_for__g_HudIcons__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_HudIcons__()
{
  CHudIcons::~CHudIcons(this: &g_HudIcons);
}

//------------------------------------------------------------------------------
// Address: 0x10431B10
// Name: _dynamic_atexit_destructor_for__gHUD__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gHUD__()
{
  CHud::~CHud(this: gHUD);
}

//------------------------------------------------------------------------------
// Address: 0x10431B20
// Name: _dynamic_atexit_destructor_for__cl_animationinfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_animationinfo_command__()
{
  ConCommand::~ConCommand(this: &cl_animationinfo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431B30
// Name: _dynamic_atexit_destructor_for__hud_saytext_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_saytext_time__()
{
  ConVar::~ConVar(this: &hud_saytext_time);
}

//------------------------------------------------------------------------------
// Address: 0x10431B40
// Name: _dynamic_atexit_destructor_for__cl_showtextmsg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showtextmsg__()
{
  ConVar::~ConVar(this: &cl_showtextmsg);
}

//------------------------------------------------------------------------------
// Address: 0x10431B50
// Name: _dynamic_atexit_destructor_for__cl_chat_active__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_chat_active__()
{
  ConVar::~ConVar(this: &cl_chat_active);
}

//------------------------------------------------------------------------------
// Address: 0x10431B60
// Name: _dynamic_atexit_destructor_for__cl_chatfilters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_chatfilters__()
{
  ConVar::~ConVar(this: &cl_chatfilters);
}

//------------------------------------------------------------------------------
// Address: 0x10431B70
// Name: _dynamic_atexit_destructor_for__cl_chatfilter_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_chatfilter_version__()
{
  ConVar::~ConVar(this: &cl_chatfilter_version);
}

//------------------------------------------------------------------------------
// Address: 0x104341D0
// Name: _dynamic_atexit_destructor_for__getpos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__getpos_command__()
{
  ConCommand::~ConCommand(this: &getpos_command);
}

//------------------------------------------------------------------------------
// Address: 0x104341E0
// Name: _dynamic_atexit_destructor_for__getpos_exact__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__getpos_exact__()
{
  ConCommand::~ConCommand(this: &getpos_exact);
}

//------------------------------------------------------------------------------
// Address: 0x104341F0
// Name: _dynamic_atexit_destructor_for__r_DrawBeams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_DrawBeams__()
{
  ConVar::~ConVar(this: &r_DrawBeams);
}

//------------------------------------------------------------------------------
// Address: 0x10434200
// Name: _dynamic_atexit_destructor_for__cl_beam_test_traces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_beam_test_traces__()
{
  ConVar::~ConVar(this: &cl_beam_test_traces);
}

//------------------------------------------------------------------------------
// Address: 0x10434210
// Name: _dynamic_atexit_destructor_for__s_ViewRenderBeams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ViewRenderBeams__()
{
  s_ViewRenderBeams.__vftable = (CViewRenderBeams_vtbl *)&CViewRenderBeams::`vftable';
  CViewRenderBeams::ClearBeams(this: &s_ViewRenderBeams);
}

//------------------------------------------------------------------------------
// Address: 0x10434230
// Name: _dynamic_atexit_destructor_for__shake_show__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__shake_show__()
{
  ConVar::~ConVar(this: &shake_show);
}

//------------------------------------------------------------------------------
// Address: 0x10434240
// Name: _dynamic_atexit_destructor_for__shake_stop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__shake_stop__()
{
  ConCommand::~ConCommand(this: &shake_stop);
}

//------------------------------------------------------------------------------
// Address: 0x10434250
// Name: _dynamic_atexit_destructor_for__shake_testpunch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__shake_testpunch__()
{
  ConCommand::~ConCommand(this: &shake_testpunch);
}

//------------------------------------------------------------------------------
// Address: 0x10434260
// Name: _DataMapInit_screenfade_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_screenfade_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_36);
}

//------------------------------------------------------------------------------
// Address: 0x10434270
// Name: _DataMapInit_screenshake_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_screenshake_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_37);
}

//------------------------------------------------------------------------------
// Address: 0x10434280
// Name: _DataMapInit_screentilt_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_screentilt_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_38);
}

//------------------------------------------------------------------------------
// Address: 0x10434290
// Name: _dynamic_atexit_destructor_for__g_ViewEffects__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ViewEffects__()
{
  int v0; // esi
  void *v1; // edx
  void *v2; // eax
  void *v3; // eax

  v0 = dword_10653D78 - 1;
  for ( g_ViewEffects[0].__vftable = (CViewEffects_vtbl *)&CViewEffects::`vftable'; v0 >= 0; --v0 )
    C_BaseEntity::operator delete(pMem: *(void **)(dword_10653D6C + 4 * v0));
  v1 = (void *)dword_10653D6C;
  dword_10653D78 = 0;
  if ( dword_10653D74 >= 0 )
  {
    if ( dword_10653D6C != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dword_10653D6C);
      v1 = nullptr;
      dword_10653D6C = 0;
    }
    dword_10653D70 = 0;
  }
  v2 = (void *)dword_10653DA4;
  dword_10653D7C = (int)v1;
  dword_10653DB0 = 0;
  if ( dword_10653DAC >= 0 )
  {
    if ( dword_10653DA4 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dword_10653DA4);
      v1 = (void *)dword_10653D6C;
      v2 = nullptr;
      dword_10653DA4 = 0;
    }
    dword_10653DA8 = 0;
  }
  dword_10653DB4 = (int)v2;
  if ( dword_10653DAC >= 0 )
  {
    if ( v2 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
      v1 = (void *)dword_10653D6C;
      dword_10653DA4 = 0;
    }
    dword_10653DA8 = 0;
  }
  v3 = (void *)dword_10653D80;
  dword_10653D8C = 0;
  if ( dword_10653D88 >= 0 )
  {
    if ( dword_10653D80 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dword_10653D80);
      v1 = (void *)dword_10653D6C;
      v3 = nullptr;
      dword_10653D80 = 0;
    }
    dword_10653D84 = 0;
  }
  dword_10653D90 = (int)v3;
  if ( dword_10653D88 >= 0 )
  {
    if ( v3 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
      v1 = (void *)dword_10653D6C;
      dword_10653D80 = 0;
    }
    dword_10653D84 = 0;
  }
  dword_10653D78 = 0;
  if ( dword_10653D74 >= 0 )
  {
    if ( v1 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1);
      v1 = nullptr;
      dword_10653D6C = 0;
    }
    dword_10653D70 = 0;
  }
  dword_10653D7C = (int)v1;
  if ( dword_10653D74 >= 0 )
  {
    if ( v1 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1);
      dword_10653D6C = 0;
    }
    dword_10653D70 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10434440
// Name: _dynamic_atexit_destructor_for__r_updaterefracttexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_updaterefracttexture__()
{
  ConVar::~ConVar(this: &r_updaterefracttexture);
}

//------------------------------------------------------------------------------
// Address: 0x10434450
// Name: _dynamic_atexit_destructor_for__r_depthoverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_depthoverlay__()
{
  ConVar::~ConVar(this: &r_depthoverlay);
}

//------------------------------------------------------------------------------
// Address: 0x10434460
// Name: _dynamic_atexit_destructor_for__viewanim_create_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewanim_create_command__()
{
  ConCommand::~ConCommand(this: &viewanim_create_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434470
// Name: _dynamic_atexit_destructor_for__viewanim_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewanim_test__()
{
  ConCommand::~ConCommand(this: &viewanim_test);
}

//------------------------------------------------------------------------------
// Address: 0x10434480
// Name: _dynamic_atexit_destructor_for__viewanim_reset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewanim_reset__()
{
  ConCommand::~ConCommand(this: &viewanim_reset);
}

//------------------------------------------------------------------------------
// Address: 0x10434490
// Name: _dynamic_atexit_destructor_for__viewanim_addkeyframe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewanim_addkeyframe_command__()
{
  ConCommand::~ConCommand(this: &viewanim_addkeyframe_command);
}

//------------------------------------------------------------------------------
// Address: 0x104344A0
// Name: _dynamic_atexit_destructor_for__viewanim_save_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewanim_save_command__()
{
  ConCommand::~ConCommand(this: &viewanim_save_command);
}

//------------------------------------------------------------------------------
// Address: 0x104344B0
// Name: _dynamic_atexit_destructor_for__viewanim_load_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewanim_load_command__()
{
  ConCommand::~ConCommand(this: &viewanim_load_command);
}

//------------------------------------------------------------------------------
// Address: 0x104344C0
// Name: _dynamic_atexit_destructor_for__cl_drawmaterial__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_drawmaterial__()
{
  ConVar::~ConVar(this: &cl_drawmaterial);
}

//------------------------------------------------------------------------------
// Address: 0x104344D0
// Name: _dynamic_atexit_destructor_for__mat_showwatertextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_showwatertextures__()
{
  ConVar::~ConVar(this: &mat_showwatertextures);
}

//------------------------------------------------------------------------------
// Address: 0x104344E0
// Name: _dynamic_atexit_destructor_for__mat_wateroverlaysize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_wateroverlaysize__()
{
  ConVar::~ConVar(this: &mat_wateroverlaysize);
}

//------------------------------------------------------------------------------
// Address: 0x104344F0
// Name: _dynamic_atexit_destructor_for__mat_showframebuffertexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_showframebuffertexture__()
{
  ConVar::~ConVar(this: &mat_showframebuffertexture);
}

//------------------------------------------------------------------------------
// Address: 0x10434500
// Name: _dynamic_atexit_destructor_for__mat_framebuffercopyoverlaysize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_framebuffercopyoverlaysize__()
{
  ConVar::~ConVar(this: &mat_framebuffercopyoverlaysize);
}

//------------------------------------------------------------------------------
// Address: 0x10434510
// Name: _dynamic_atexit_destructor_for__mat_showcamerarendertarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_showcamerarendertarget__()
{
  ConVar::~ConVar(this: &mat_showcamerarendertarget);
}

//------------------------------------------------------------------------------
// Address: 0x10434520
// Name: _dynamic_atexit_destructor_for__mat_camerarendertargetoverlaysize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_camerarendertargetoverlaysize__()
{
  ConVar::~ConVar(this: &mat_camerarendertargetoverlaysize);
}

//------------------------------------------------------------------------------
// Address: 0x10434530
// Name: _dynamic_atexit_destructor_for__mat_hsv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_hsv__()
{
  ConVar::~ConVar(this: &mat_hsv);
}

//------------------------------------------------------------------------------
// Address: 0x10434540
// Name: _dynamic_atexit_destructor_for__mat_yuv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_yuv__()
{
  ConVar::~ConVar(this: &mat_yuv);
}

//------------------------------------------------------------------------------
// Address: 0x10434550
// Name: _dynamic_atexit_destructor_for__cl_overdraw_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_overdraw_test__()
{
  ConVar::~ConVar(this: &cl_overdraw_test);
}

//------------------------------------------------------------------------------
// Address: 0x10434560
// Name: _dynamic_atexit_destructor_for__mat_drawTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_drawTexture__()
{
  ConVar::~ConVar(this: &mat_drawTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10434570
// Name: _dynamic_atexit_destructor_for__mat_drawTextureScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_drawTextureScale__()
{
  ConVar::~ConVar(this: &mat_drawTextureScale);
}

//------------------------------------------------------------------------------
// Address: 0x10434580
// Name: _dynamic_atexit_destructor_for__mat_wireframe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_wireframe__()
{
  ConVar::~ConVar(this: &mat_wireframe);
}

//------------------------------------------------------------------------------
// Address: 0x10434590
// Name: _dynamic_atexit_destructor_for__mat_showlightmappage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_showlightmappage__()
{
  ConVar::~ConVar(this: &mat_showlightmappage);
}

//------------------------------------------------------------------------------
// Address: 0x104345A0
// Name: _dynamic_atexit_destructor_for__cl_drawshadowtexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_drawshadowtexture__()
{
  ConVar::~ConVar(this: &cl_drawshadowtexture);
}

//------------------------------------------------------------------------------
// Address: 0x104345B0
// Name: _dynamic_atexit_destructor_for__cl_shadowtextureoverlaysize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_shadowtextureoverlaysize__()
{
  ConVar::~ConVar(this: &cl_shadowtextureoverlaysize);
}

//------------------------------------------------------------------------------
// Address: 0x104345C0
// Name: _dynamic_atexit_destructor_for__r_flashlightdrawdepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightdrawdepth__()
{
  ConVar::~ConVar(this: &r_flashlightdrawdepth);
}

//------------------------------------------------------------------------------
// Address: 0x104345D0
// Name: _dynamic_atexit_destructor_for__r_screenoverlay_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_screenoverlay_command__()
{
  ConCommand::~ConCommand(this: &r_screenoverlay_command);
}

//------------------------------------------------------------------------------
// Address: 0x104345E0
// Name: _dynamic_atexit_destructor_for__mat_bloomscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_bloomscale__()
{
  ConVar::~ConVar(this: &mat_bloomscale);
}

//------------------------------------------------------------------------------
// Address: 0x104345F0
// Name: _dynamic_atexit_destructor_for__mat_hdr_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_hdr_level__()
{
  ConVar::~ConVar(this: &mat_hdr_level);
}

//------------------------------------------------------------------------------
// Address: 0x10434600
// Name: _dynamic_atexit_destructor_for__mat_bloomamount_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_bloomamount_rate__()
{
  ConVar::~ConVar(this: &mat_bloomamount_rate);
}

//------------------------------------------------------------------------------
// Address: 0x10435DD0
// Name: _dynamic_atexit_destructor_for__togglescores_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__togglescores_command__()
{
  ConCommand::~ConCommand(this: &togglescores_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435DE0
// Name: _dynamic_atexit_destructor_for__hidescores_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hidescores_command__()
{
  ConCommand::~ConCommand(this: &hidescores_command);
}
