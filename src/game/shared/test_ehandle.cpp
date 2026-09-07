// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/test_ehandle.cpp
// Functions: 139
// ============================================================

#include "game\shared\test_ehandle.h"

//------------------------------------------------------------------------------
// Address: 0x10179E20
// Name: public: virtual class ClientClass __near * C_HandleTest::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_HandleTest::GetClientClass(C_HandleTest *this)
{
  return &__g_C_HandleTestClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10179ED0
// Name: public: virtual void C_HandleTest::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_HandleTest::OnDataChanged(C_HandleTest *this, DataUpdateType_t type)
{
  unsigned int v2; // edx
  IHandleEntity *m_pEntity; // eax

  v2 = *(_DWORD *)&this->m_bIsBlurred;
  if ( v2 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_SerialNumber != HIWORD(v2) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_pEntity;
  _Msg(a1: "m_bSendHandle: %d, m_Handle.Get: 0x%p\n", *((unsigned __int8 *)&this->m_bIsBlurred + 4), m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10413D70
// Name: _dynamic_initializer_for__Test_ProxyToggle_EnsureValue_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_ProxyToggle_EnsureValue_command__()
{
  ConCommand::ConCommand(
    this: &Test_ProxyToggle_EnsureValue_command,
    pName: "Test_ProxyToggle_EnsureValue",
    callback: (void (__cdecl *)())Test_ProxyToggle_EnsureValue,
    pHelpString: "Test_ProxyToggle_EnsureValue",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_ProxyToggle_EnsureValue_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF00
// Name: DT_HandleTest::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_HandleTest::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_HandleTest::g_RecvTable);
  return atexit(func: DT_HandleTest::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF20
// Name: DT_HandleTest::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_HandleTest::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_HandleTest::ignored>();
  DT_HandleTest::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041F310
// Name: _dynamic_initializer_for__test_freezeframe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_freezeframe__()
{
  ConCommand::ConCommand(
    this: &test_freezeframe,
    pName: "test_freezeframe",
    callback: testfreezeframe_f,
    pHelpString: "Test the freeze frame code.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__test_freezeframe__);
}

//------------------------------------------------------------------------------
// Address: 0x10430CA0
// Name: _dynamic_atexit_destructor_for__Test_ProxyToggle_EnsureValue_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_ProxyToggle_EnsureValue_command__()
{
  ConCommand::~ConCommand(this: &Test_ProxyToggle_EnsureValue_command);
}

//------------------------------------------------------------------------------
// Address: 0x10433D80
// Name: DT_HandleTest::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_HandleTest::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_HandleTest::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10434A00
// Name: _dynamic_atexit_destructor_for__test_freezeframe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__test_freezeframe__()
{
  ConCommand::~ConCommand(this: &test_freezeframe);
}

//------------------------------------------------------------------------------
// Address: 0x10179F20
// Name: _C_HandleTest_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_HandleTest_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_HandleTest::`vftable'{for `IClientUnknown'};
  v3[1] = &C_HandleTest::`vftable'{for `IClientRenderable'};
  v3[2] = &C_HandleTest::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_HandleTest::`vftable'{for `IClientThinkable'};
  v3[4] = &C_HandleTest::`vftable';
  v3[608] = -1;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10413DA0
// Name: _dynamic_initializer_for____g_C_BaseTriggerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseTriggerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseTriggerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseTriggerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CF30
// Name: _dynamic_initializer_for__g_CTextureScrollFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CTextureScrollFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "TextureScroll",
           a3: CCTextureScrollMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF50
// Name: _dynamic_initializer_for__g_CCurrentTimeFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CCurrentTimeFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "CurrentTime",
           a3: CCTimeMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF70
// Name: _dynamic_initializer_for__g_CToggleTextureFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CToggleTextureFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "ToggleTexture",
           a3: CCBaseToggleTextureProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF90
// Name: _dynamic_initializer_for__g_CHudTrain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudTrain_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudTrain_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudTrain,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1041CFB0
// Name: _dynamic_initializer_for__net_showusercmd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showusercmd__()
{
  ConVar::ConVar(
    this: &net_showusercmd,
    pName: "net_showusercmd",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show user command encoding");
  return atexit(func: dynamic_atexit_destructor_for__net_showusercmd__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CFE0
// Name: _dynamic_initializer_for__g_UserMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UserMessages__()
{
  RegisterUserMessages();
  return atexit(func: dynamic_atexit_destructor_for__g_UserMessages__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D000
// Name: _dynamic_initializer_for__r_visualizetraces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_visualizetraces__()
{
  ConVar::ConVar(this: &r_visualizetraces, pName: "r_visualizetraces", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_visualizetraces__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D030
// Name: _dynamic_initializer_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__developer__()
{
  ConVar::ConVar(
    this: &developer,
    pName: "developer",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Set developer message level");
  return atexit(func: dynamic_atexit_destructor_for__developer__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D060
// Name: _dynamic_initializer_for__violence_hblood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_hblood__()
{
  ConVar::ConVar(
    this: &violence_hblood,
    pName: "violence_hblood",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw human blood");
  return atexit(func: dynamic_atexit_destructor_for__violence_hblood__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D090
// Name: _dynamic_initializer_for__violence_hgibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_hgibs__()
{
  ConVar::ConVar(
    this: &violence_hgibs,
    pName: "violence_hgibs",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show human gib entities");
  return atexit(func: dynamic_atexit_destructor_for__violence_hgibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D0C0
// Name: _dynamic_initializer_for__violence_ablood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_ablood__()
{
  ConVar::ConVar(
    this: &violence_ablood,
    pName: "violence_ablood",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw alien blood");
  return atexit(func: dynamic_atexit_destructor_for__violence_ablood__);
}

//------------------------------------------------------------------------------
// Address: 0x1041D0F0
// Name: _dynamic_initializer_for__violence_agibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_agibs__()
{
  ConVar::ConVar(
    this: &violence_agibs,
    pName: "violence_agibs",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show alien gib entities");
  return atexit(func: dynamic_atexit_destructor_for__violence_agibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F340
// Name: _dynamic_initializer_for__r_visocclusion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_visocclusion__()
{
  ConVar::ConVar(this: &r_visocclusion, pName: "r_visocclusion", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_visocclusion__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F370
// Name: _dynamic_initializer_for__cl_maxrenderable_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_maxrenderable_dist__()
{
  ConVar::ConVar(
    this: &cl_maxrenderable_dist,
    pName: "cl_maxrenderable_dist",
    pDefaultValue: "3000",
    flags: 0x4000,
    pHelpString: "Max distance from the camera at which things will be rendered");
  return atexit(func: dynamic_atexit_destructor_for__cl_maxrenderable_dist__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3A0
// Name: _dynamic_initializer_for__r_entityclips__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_entityclips__()
{
  ConVar::ConVar(this: &r_entityclips, pName: "r_entityclips", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_entityclips__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3D0
// Name: _dynamic_initializer_for__r_deferopaquefastclipped__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_deferopaquefastclipped__()
{
  ConVar::ConVar(this: &r_deferopaquefastclipped, pName: "r_deferopaquefastclipped", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_deferopaquefastclipped__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F400
// Name: _dynamic_initializer_for__r_drawopaqueworld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawopaqueworld__()
{
  ConVar::ConVar(this: &r_drawopaqueworld, pName: "r_drawopaqueworld", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawopaqueworld__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F430
// Name: _dynamic_initializer_for__r_drawtranslucentworld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawtranslucentworld__()
{
  ConVar::ConVar(this: &r_drawtranslucentworld, pName: "r_drawtranslucentworld", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawtranslucentworld__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F460
// Name: _dynamic_initializer_for__r_3dsky__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_3dsky__()
{
  ConVar::ConVar(
    this: &r_3dsky,
    pName: "r_3dsky",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable the rendering of 3d sky boxes");
  return atexit(func: dynamic_atexit_destructor_for__r_3dsky__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F490
// Name: _dynamic_initializer_for__r_skybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_skybox__()
{
  ConVar::ConVar(
    this: &r_skybox,
    pName: "r_skybox",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable the rendering of sky boxes");
  return atexit(func: dynamic_atexit_destructor_for__r_skybox__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F4C0
// Name: _dynamic_initializer_for__r_drawviewmodel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawviewmodel__()
{
  ConVar::ConVar(this: &r_drawviewmodel, pName: "r_drawviewmodel", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawviewmodel__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F4F0
// Name: _dynamic_initializer_for__r_drawtranslucentrenderables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawtranslucentrenderables__()
{
  ConVar::ConVar(
    this: &r_drawtranslucentrenderables,
    pName: "r_drawtranslucentrenderables",
    pDefaultValue: "1",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawtranslucentrenderables__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F520
// Name: _dynamic_initializer_for__r_drawopaquerenderables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawopaquerenderables__()
{
  ConVar::ConVar(this: &r_drawopaquerenderables, pName: "r_drawopaquerenderables", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawopaquerenderables__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F550
// Name: _dynamic_initializer_for__r_flashlightdepth_drawtranslucents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightdepth_drawtranslucents__()
{
  ConVar::ConVar(
    this: &r_flashlightdepth_drawtranslucents,
    pName: "r_flashlightdepth_drawtranslucents",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightdepth_drawtranslucents__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F580
// Name: _dynamic_initializer_for__r_flashlightvolumetrics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightvolumetrics__()
{
  ConVar::ConVar(this: &r_flashlightvolumetrics, pName: "r_flashlightvolumetrics", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightvolumetrics__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F5B0
// Name: _dynamic_initializer_for__r_DrawDetailProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_DrawDetailProps__()
{
  ConVar::ConVar(
    this: &r_DrawDetailProps,
    pName: "r_DrawDetailProps",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "0=Off, 1=Normal, 2=Wireframe");
  return atexit(func: dynamic_atexit_destructor_for__r_DrawDetailProps__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F5E0
// Name: _dynamic_initializer_for__r_worldlistcache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_worldlistcache__()
{
  ConVar::ConVar(this: &r_worldlistcache, pName: "r_worldlistcache", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_worldlistcache__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F610
// Name: _dynamic_initializer_for__r_drawunderwateroverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawunderwateroverlay__()
{
  ConVar::ConVar(this: &r_drawunderwateroverlay, pName: "r_drawunderwateroverlay", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawunderwateroverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F640
// Name: _dynamic_initializer_for__r_drawscreenoverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawscreenoverlay__()
{
  ConVar::ConVar(this: &r_drawscreenoverlay, pName: "r_drawscreenoverlay", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawscreenoverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F670
// Name: _dynamic_initializer_for__fog_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_override__()
{
  ConVar::ConVar(
    this: &fog_override,
    pName: "fog_override",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Overrides the map's fog settings (-1 populates fog_ vars with map's values)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))FogOverrideCallback);
  return atexit(func: dynamic_atexit_destructor_for__fog_override__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F6A0
// Name: _dynamic_initializer_for__fog_start__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_start__()
{
  ConVar::ConVar(this: &fog_start, pName: "fog_start", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_start__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F6D0
// Name: _dynamic_initializer_for__fog_end__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_end__()
{
  ConVar::ConVar(this: &fog_end, pName: "fog_end", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_end__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F700
// Name: _dynamic_initializer_for__fog_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_color__()
{
  ConVar::ConVar(this: &fog_color, pName: "fog_color", pDefaultValue: "-1 -1 -1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_color__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F730
// Name: _dynamic_initializer_for__fog_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_enable__()
{
  ConVar::ConVar(this: &fog_enable, pName: "fog_enable", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F760
// Name: _dynamic_initializer_for__fog_startskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_startskybox__()
{
  ConVar::ConVar(this: &fog_startskybox, pName: "fog_startskybox", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_startskybox__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F790
// Name: _dynamic_initializer_for__fog_endskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_endskybox__()
{
  ConVar::ConVar(this: &fog_endskybox, pName: "fog_endskybox", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_endskybox__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F7C0
// Name: _dynamic_initializer_for__fog_maxdensityskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_maxdensityskybox__()
{
  ConVar::ConVar(this: &fog_maxdensityskybox, pName: "fog_maxdensityskybox", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_maxdensityskybox__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F7F0
// Name: _dynamic_initializer_for__fog_colorskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_colorskybox__()
{
  ConVar::ConVar(this: &fog_colorskybox, pName: "fog_colorskybox", pDefaultValue: "-1 -1 -1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_colorskybox__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F820
// Name: _dynamic_initializer_for__fog_enableskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_enableskybox__()
{
  ConVar::ConVar(this: &fog_enableskybox, pName: "fog_enableskybox", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_enableskybox__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F850
// Name: _dynamic_initializer_for__fog_maxdensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_maxdensity__()
{
  ConVar::ConVar(this: &fog_maxdensity, pName: "fog_maxdensity", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_maxdensity__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F880
// Name: _dynamic_initializer_for__fog_hdrcolorscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_hdrcolorscale__()
{
  ConVar::ConVar(this: &fog_hdrcolorscale, pName: "fog_hdrcolorscale", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_hdrcolorscale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F8B0
// Name: _dynamic_initializer_for__fog_hdrcolorscaleskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fog_hdrcolorscaleskybox__()
{
  ConVar::ConVar(this: &fog_hdrcolorscaleskybox, pName: "fog_hdrcolorscaleskybox", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__fog_hdrcolorscaleskybox__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F8E0
// Name: _dynamic_initializer_for__r_debugcheapwater__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_debugcheapwater__()
{
  ConVar::ConVar(this: &r_debugcheapwater, pName: "r_debugcheapwater", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_debugcheapwater__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F910
// Name: _dynamic_initializer_for__r_waterforceexpensive__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_waterforceexpensive__()
{
  ConVar::ConVar(this: &r_waterforceexpensive, pName: "r_waterforceexpensive", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_waterforceexpensive__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F940
// Name: _dynamic_initializer_for__r_waterforcereflectentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_waterforcereflectentities__()
{
  ConVar::ConVar(this: &r_waterforcereflectentities, pName: "r_waterforcereflectentities", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_waterforcereflectentities__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F970
// Name: _dynamic_initializer_for__r_WaterDrawRefraction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_WaterDrawRefraction__()
{
  ConVar::ConVar(
    this: &r_WaterDrawRefraction,
    pName: "r_WaterDrawRefraction",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable water refraction");
  return atexit(func: dynamic_atexit_destructor_for__r_WaterDrawRefraction__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F9A0
// Name: _dynamic_initializer_for__r_WaterDrawReflection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_WaterDrawReflection__()
{
  ConVar::ConVar(
    this: &r_WaterDrawReflection,
    pName: "r_WaterDrawReflection",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable water reflection");
  return atexit(func: dynamic_atexit_destructor_for__r_WaterDrawReflection__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F9D0
// Name: _dynamic_initializer_for__r_ForceWaterLeaf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_ForceWaterLeaf__()
{
  ConVar::ConVar(
    this: &r_ForceWaterLeaf,
    pName: "r_ForceWaterLeaf",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable for optimization to water - considers view in leaf under water for purposes of culling");
  return atexit(func: dynamic_atexit_destructor_for__r_ForceWaterLeaf__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA00
// Name: _dynamic_initializer_for__mat_drawwater__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_drawwater__()
{
  ConVar::ConVar(this: &mat_drawwater, pName: "mat_drawwater", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_drawwater__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA30
// Name: _dynamic_initializer_for__mat_clipz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_clipz__()
{
  ConVar::ConVar(this: &mat_clipz, pName: "mat_clipz", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_clipz__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA60
// Name: _dynamic_initializer_for__cl_drawmonitors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_drawmonitors__()
{
  ConVar::ConVar(this: &cl_drawmonitors, pName: "cl_drawmonitors", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_drawmonitors__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA90
// Name: _dynamic_initializer_for__r_eyewaterepsilon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyewaterepsilon__()
{
  ConVar::ConVar(this: &r_eyewaterepsilon, pName: "r_eyewaterepsilon", pDefaultValue: "7.0f", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_eyewaterepsilon__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FAC0
// Name: _dynamic_initializer_for__r_fastzreject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_fastzreject__()
{
  ConVar::ConVar(
    this: &r_fastzreject,
    pName: "r_fastzreject",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Activate/deactivates a fast z-setting algorithm to take advantage of hardware with fast z reject. Use -1 to default "
    "to hardware settings");
  return atexit(func: dynamic_atexit_destructor_for__r_fastzreject__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FAF0
// Name: _dynamic_initializer_for__r_simpleworldmodel_waterreflections_fullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_waterreflections_fullscreen__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_waterreflections_fullscreen,
    pName: "r_simpleworldmodel_waterreflections_fullscreen",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_fullscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB20
// Name: _dynamic_initializer_for__r_simpleworldmodel_drawforrecursionlevel_fullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_drawforrecursionlevel_fullscreen__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_drawforrecursionlevel_fullscreen,
    pName: "r_simpleworldmodel_drawforrecursionlevel_fullscreen",
    pDefaultValue: "-1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_fullscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB50
// Name: _dynamic_initializer_for__r_simpleworldmodel_drawbeyonddistance_fullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_drawbeyonddistance_fullscreen__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_drawbeyonddistance_fullscreen,
    pName: "r_simpleworldmodel_drawbeyonddistance_fullscreen",
    pDefaultValue: "-1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_fullscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB80
// Name: _dynamic_initializer_for__r_simpleworldmodel_waterreflections_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_waterreflections_splitscreen__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_waterreflections_splitscreen,
    pName: "r_simpleworldmodel_waterreflections_splitscreen",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_splitscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FBB0
// Name: _dynamic_initializer_for__r_simpleworldmodel_drawforrecursionlevel_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_drawforrecursionlevel_splitscreen__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_drawforrecursionlevel_splitscreen,
    pName: "r_simpleworldmodel_drawforrecursionlevel_splitscreen",
    pDefaultValue: "-1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_splitscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FBE0
// Name: _dynamic_initializer_for__r_simpleworldmodel_drawbeyonddistance_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_drawbeyonddistance_splitscreen__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_drawbeyonddistance_splitscreen,
    pName: "r_simpleworldmodel_drawbeyonddistance_splitscreen",
    pDefaultValue: "-1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_splitscreen__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC10
// Name: _dynamic_initializer_for__r_simpleworldmodel_waterreflections_pip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_waterreflections_pip__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_waterreflections_pip,
    pName: "r_simpleworldmodel_waterreflections_pip",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_pip__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC40
// Name: _dynamic_initializer_for__r_simpleworldmodel_drawforrecursionlevel_pip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_drawforrecursionlevel_pip__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_drawforrecursionlevel_pip,
    pName: "r_simpleworldmodel_drawforrecursionlevel_pip",
    pDefaultValue: "-1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_pip__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC70
// Name: _dynamic_initializer_for__r_simpleworldmodel_drawbeyonddistance_pip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_simpleworldmodel_drawbeyonddistance_pip__()
{
  ConVar::ConVar(
    this: &r_simpleworldmodel_drawbeyonddistance_pip,
    pName: "r_simpleworldmodel_drawbeyonddistance_pip",
    pDefaultValue: "-1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_pip__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FCA0
// Name: _dynamic_initializer_for__s_FrustumCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Frustum_t *dynamic_initializer_for__s_FrustumCache__()
{
  Frustum_t *result; // eax

  result = Frustum_t::Frustum_t(this: s_FrustumCache.m_Frustums);
  s_FrustumCache.m_nFrameCount = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FCC0
// Name: _dynamic_initializer_for__r_cheapwaterstart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_cheapwaterstart_command__()
{
  ConCommand::ConCommand(
    this: &r_cheapwaterstart_command,
    pName: "r_cheapwaterstart",
    callback: (void (__cdecl *)())r_cheapwaterstart,
    pHelpString: prType,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__r_cheapwaterstart_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FCF0
// Name: _dynamic_initializer_for__r_cheapwaterend_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_cheapwaterend_command__()
{
  ConCommand::ConCommand(
    this: &r_cheapwaterend_command,
    pName: "r_cheapwaterend",
    callback: (void (__cdecl *)())r_cheapwaterend,
    pHelpString: prType,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__r_cheapwaterend_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD20
// Name: _dynamic_initializer_for__g_WorldListCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WorldListCache__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WorldListCache__);
}

//------------------------------------------------------------------------------
// Address: 0x10433D90
// Name: _dynamic_atexit_destructor_for__net_showusercmd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showusercmd__()
{
  ConVar::~ConVar(this: &net_showusercmd);
}

//------------------------------------------------------------------------------
// Address: 0x10433DA0
// Name: _dynamic_atexit_destructor_for__g_UserMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UserMessages__()
{
  CUserMessages::~CUserMessages(this: &g_UserMessages);
}

//------------------------------------------------------------------------------
// Address: 0x10433DB0
// Name: _dynamic_atexit_destructor_for__r_visualizetraces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_visualizetraces__()
{
  ConVar::~ConVar(this: &r_visualizetraces);
}

//------------------------------------------------------------------------------
// Address: 0x10433DC0
// Name: _dynamic_atexit_destructor_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__developer__()
{
  ConVar::~ConVar(this: &developer);
}

//------------------------------------------------------------------------------
// Address: 0x10433DD0
// Name: _dynamic_atexit_destructor_for__violence_hblood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__violence_hblood__()
{
  ConVar::~ConVar(this: &violence_hblood);
}

//------------------------------------------------------------------------------
// Address: 0x10433DE0
// Name: _dynamic_atexit_destructor_for__violence_hgibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__violence_hgibs__()
{
  ConVar::~ConVar(this: &violence_hgibs);
}

//------------------------------------------------------------------------------
// Address: 0x10433DF0
// Name: _dynamic_atexit_destructor_for__violence_ablood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__violence_ablood__()
{
  ConVar::~ConVar(this: &violence_ablood);
}

//------------------------------------------------------------------------------
// Address: 0x10433E00
// Name: _dynamic_atexit_destructor_for__violence_agibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__violence_agibs__()
{
  ConVar::~ConVar(this: &violence_agibs);
}

//------------------------------------------------------------------------------
// Address: 0x10434A10
// Name: _dynamic_atexit_destructor_for__r_visocclusion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_visocclusion__()
{
  ConVar::~ConVar(this: &r_visocclusion);
}

//------------------------------------------------------------------------------
// Address: 0x10434A20
// Name: _dynamic_atexit_destructor_for__cl_maxrenderable_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_maxrenderable_dist__()
{
  ConVar::~ConVar(this: &cl_maxrenderable_dist);
}

//------------------------------------------------------------------------------
// Address: 0x10434A30
// Name: _dynamic_atexit_destructor_for__r_entityclips__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_entityclips__()
{
  ConVar::~ConVar(this: &r_entityclips);
}

//------------------------------------------------------------------------------
// Address: 0x10434A40
// Name: _dynamic_atexit_destructor_for__r_deferopaquefastclipped__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_deferopaquefastclipped__()
{
  ConVar::~ConVar(this: &r_deferopaquefastclipped);
}

//------------------------------------------------------------------------------
// Address: 0x10434A50
// Name: _dynamic_atexit_destructor_for__r_drawopaqueworld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawopaqueworld__()
{
  ConVar::~ConVar(this: &r_drawopaqueworld);
}

//------------------------------------------------------------------------------
// Address: 0x10434A60
// Name: _dynamic_atexit_destructor_for__r_drawtranslucentworld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawtranslucentworld__()
{
  ConVar::~ConVar(this: &r_drawtranslucentworld);
}

//------------------------------------------------------------------------------
// Address: 0x10434A70
// Name: _dynamic_atexit_destructor_for__r_3dsky__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_3dsky__()
{
  ConVar::~ConVar(this: &r_3dsky);
}

//------------------------------------------------------------------------------
// Address: 0x10434A80
// Name: _dynamic_atexit_destructor_for__r_skybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_skybox__()
{
  ConVar::~ConVar(this: &r_skybox);
}

//------------------------------------------------------------------------------
// Address: 0x10434A90
// Name: _dynamic_atexit_destructor_for__r_drawviewmodel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawviewmodel__()
{
  ConVar::~ConVar(this: &r_drawviewmodel);
}

//------------------------------------------------------------------------------
// Address: 0x10434AA0
// Name: _dynamic_atexit_destructor_for__r_drawtranslucentrenderables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawtranslucentrenderables__()
{
  ConVar::~ConVar(this: &r_drawtranslucentrenderables);
}

//------------------------------------------------------------------------------
// Address: 0x10434AB0
// Name: _dynamic_atexit_destructor_for__r_drawopaquerenderables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawopaquerenderables__()
{
  ConVar::~ConVar(this: &r_drawopaquerenderables);
}

//------------------------------------------------------------------------------
// Address: 0x10434AC0
// Name: _dynamic_atexit_destructor_for__r_flashlightdepth_drawtranslucents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightdepth_drawtranslucents__()
{
  ConVar::~ConVar(this: &r_flashlightdepth_drawtranslucents);
}

//------------------------------------------------------------------------------
// Address: 0x10434AD0
// Name: _dynamic_atexit_destructor_for__r_flashlightvolumetrics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightvolumetrics__()
{
  ConVar::~ConVar(this: &r_flashlightvolumetrics);
}

//------------------------------------------------------------------------------
// Address: 0x10434AE0
// Name: _dynamic_atexit_destructor_for__r_DrawDetailProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_DrawDetailProps__()
{
  ConVar::~ConVar(this: &r_DrawDetailProps);
}

//------------------------------------------------------------------------------
// Address: 0x10434AF0
// Name: _dynamic_atexit_destructor_for__r_worldlistcache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_worldlistcache__()
{
  ConVar::~ConVar(this: &r_worldlistcache);
}

//------------------------------------------------------------------------------
// Address: 0x10434B00
// Name: _dynamic_atexit_destructor_for__r_drawunderwateroverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawunderwateroverlay__()
{
  ConVar::~ConVar(this: &r_drawunderwateroverlay);
}

//------------------------------------------------------------------------------
// Address: 0x10434B10
// Name: _dynamic_atexit_destructor_for__r_drawscreenoverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawscreenoverlay__()
{
  ConVar::~ConVar(this: &r_drawscreenoverlay);
}

//------------------------------------------------------------------------------
// Address: 0x10434B20
// Name: _dynamic_atexit_destructor_for__fog_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_override__()
{
  ConVar::~ConVar(this: &fog_override);
}

//------------------------------------------------------------------------------
// Address: 0x10434B30
// Name: _dynamic_atexit_destructor_for__fog_start__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_start__()
{
  ConVar::~ConVar(this: &fog_start);
}

//------------------------------------------------------------------------------
// Address: 0x10434B40
// Name: _dynamic_atexit_destructor_for__fog_end__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_end__()
{
  ConVar::~ConVar(this: &fog_end);
}

//------------------------------------------------------------------------------
// Address: 0x10434B50
// Name: _dynamic_atexit_destructor_for__fog_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_color__()
{
  ConVar::~ConVar(this: &fog_color);
}

//------------------------------------------------------------------------------
// Address: 0x10434B60
// Name: _dynamic_atexit_destructor_for__fog_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_enable__()
{
  ConVar::~ConVar(this: &fog_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10434B70
// Name: _dynamic_atexit_destructor_for__fog_startskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_startskybox__()
{
  ConVar::~ConVar(this: &fog_startskybox);
}

//------------------------------------------------------------------------------
// Address: 0x10434B80
// Name: _dynamic_atexit_destructor_for__fog_endskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_endskybox__()
{
  ConVar::~ConVar(this: &fog_endskybox);
}

//------------------------------------------------------------------------------
// Address: 0x10434B90
// Name: _dynamic_atexit_destructor_for__fog_maxdensityskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_maxdensityskybox__()
{
  ConVar::~ConVar(this: &fog_maxdensityskybox);
}

//------------------------------------------------------------------------------
// Address: 0x10434BA0
// Name: _dynamic_atexit_destructor_for__fog_colorskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_colorskybox__()
{
  ConVar::~ConVar(this: &fog_colorskybox);
}

//------------------------------------------------------------------------------
// Address: 0x10434BB0
// Name: _dynamic_atexit_destructor_for__fog_enableskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_enableskybox__()
{
  ConVar::~ConVar(this: &fog_enableskybox);
}

//------------------------------------------------------------------------------
// Address: 0x10434BC0
// Name: _dynamic_atexit_destructor_for__fog_maxdensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_maxdensity__()
{
  ConVar::~ConVar(this: &fog_maxdensity);
}

//------------------------------------------------------------------------------
// Address: 0x10434BD0
// Name: _dynamic_atexit_destructor_for__fog_hdrcolorscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_hdrcolorscale__()
{
  ConVar::~ConVar(this: &fog_hdrcolorscale);
}

//------------------------------------------------------------------------------
// Address: 0x10434BE0
// Name: _dynamic_atexit_destructor_for__fog_hdrcolorscaleskybox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fog_hdrcolorscaleskybox__()
{
  ConVar::~ConVar(this: &fog_hdrcolorscaleskybox);
}

//------------------------------------------------------------------------------
// Address: 0x10434BF0
// Name: _dynamic_atexit_destructor_for__r_debugcheapwater__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_debugcheapwater__()
{
  ConVar::~ConVar(this: &r_debugcheapwater);
}

//------------------------------------------------------------------------------
// Address: 0x10434C00
// Name: _dynamic_atexit_destructor_for__r_waterforceexpensive__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_waterforceexpensive__()
{
  ConVar::~ConVar(this: &r_waterforceexpensive);
}

//------------------------------------------------------------------------------
// Address: 0x10434C10
// Name: _dynamic_atexit_destructor_for__r_waterforcereflectentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_waterforcereflectentities__()
{
  ConVar::~ConVar(this: &r_waterforcereflectentities);
}

//------------------------------------------------------------------------------
// Address: 0x10434C20
// Name: _dynamic_atexit_destructor_for__r_WaterDrawRefraction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_WaterDrawRefraction__()
{
  ConVar::~ConVar(this: &r_WaterDrawRefraction);
}

//------------------------------------------------------------------------------
// Address: 0x10434C30
// Name: _dynamic_atexit_destructor_for__r_WaterDrawReflection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_WaterDrawReflection__()
{
  ConVar::~ConVar(this: &r_WaterDrawReflection);
}

//------------------------------------------------------------------------------
// Address: 0x10434C40
// Name: _dynamic_atexit_destructor_for__r_ForceWaterLeaf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_ForceWaterLeaf__()
{
  ConVar::~ConVar(this: &r_ForceWaterLeaf);
}

//------------------------------------------------------------------------------
// Address: 0x10434C50
// Name: _dynamic_atexit_destructor_for__mat_drawwater__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_drawwater__()
{
  ConVar::~ConVar(this: &mat_drawwater);
}

//------------------------------------------------------------------------------
// Address: 0x10434C60
// Name: _dynamic_atexit_destructor_for__mat_clipz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_clipz__()
{
  ConVar::~ConVar(this: &mat_clipz);
}

//------------------------------------------------------------------------------
// Address: 0x10434C70
// Name: _dynamic_atexit_destructor_for__cl_drawmonitors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_drawmonitors__()
{
  ConVar::~ConVar(this: &cl_drawmonitors);
}

//------------------------------------------------------------------------------
// Address: 0x10434C80
// Name: _dynamic_atexit_destructor_for__r_eyewaterepsilon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyewaterepsilon__()
{
  ConVar::~ConVar(this: &r_eyewaterepsilon);
}

//------------------------------------------------------------------------------
// Address: 0x10434C90
// Name: _dynamic_atexit_destructor_for__r_fastzreject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_fastzreject__()
{
  ConVar::~ConVar(this: &r_fastzreject);
}

//------------------------------------------------------------------------------
// Address: 0x10434CA0
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_fullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_fullscreen__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_waterreflections_fullscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10434CB0
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_fullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_fullscreen__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_drawforrecursionlevel_fullscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10434CC0
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_fullscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_fullscreen__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_drawbeyonddistance_fullscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10434CD0
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_splitscreen__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_waterreflections_splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10434CE0
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_splitscreen__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_drawforrecursionlevel_splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10434CF0
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_splitscreen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_splitscreen__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_drawbeyonddistance_splitscreen);
}

//------------------------------------------------------------------------------
// Address: 0x10434D00
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_pip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_waterreflections_pip__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_waterreflections_pip);
}

//------------------------------------------------------------------------------
// Address: 0x10434D10
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_pip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_drawforrecursionlevel_pip__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_drawforrecursionlevel_pip);
}

//------------------------------------------------------------------------------
// Address: 0x10434D20
// Name: _dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_pip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_simpleworldmodel_drawbeyonddistance_pip__()
{
  ConVar::~ConVar(this: &r_simpleworldmodel_drawbeyonddistance_pip);
}

//------------------------------------------------------------------------------
// Address: 0x10434D30
// Name: _dynamic_atexit_destructor_for__r_cheapwaterstart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_cheapwaterstart_command__()
{
  ConCommand::~ConCommand(this: &r_cheapwaterstart_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434D40
// Name: _dynamic_atexit_destructor_for__r_cheapwaterend_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_cheapwaterend_command__()
{
  ConCommand::~ConCommand(this: &r_cheapwaterend_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434D50
// Name: _dynamic_atexit_destructor_for__mat_lpreview_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_lpreview_mode__()
{
  ConVar::~ConVar(this: &mat_lpreview_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10434D60
// Name: _dynamic_atexit_destructor_for__r_fade360style__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_fade360style__()
{
  ConVar::~ConVar(this: &r_fade360style);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10232F70
// Name: public: virtual class ServerClass __near * CHandleTest::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CHandleTest::GetServerClass(CHandleTest *this)
{
  return &g_CHandleTest_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10233090
// Name: public: CHandleTest::CHandleTest(void)
// Source: json
//------------------------------------------------------------------------------
CHandleTest *__thiscall CHandleTest::CHandleTest(CHandleTest *this)
{
  CHandleTest *result; // eax
  edict_t *m_pPev; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CHandleTest_vtbl *)&CHandleTest::`vftable';
  this->m_Handle.m_Value.m_Index = -1;
  result = this;
  if ( this->m_bSendHandle.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bSendHandle.m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
      this->m_bSendHandle.m_Value = false;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102330F0
// Name: public: virtual void CHandleTest::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHandleTest::SetTransmit(CHandleTest *this, CCheckTransmitInfo *pInfo, int bAlways)
{
  edict_t *m_pPev; // eax
  unsigned int m_Index; // ecx

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseEntity::SetTransmit(this, pInfo, bAlways);
    if ( this->m_bSendHandle.m_Value )
    {
      m_Index = this->m_Handle.m_Value.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        (*(void (__stdcall **)(CCheckTransmitInfo *, int))(MEMORY[0] + 88))(a1: pInfo, a2: bAlways);
      else
        ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, int))g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity->__vftable[7].SetRefEHandle)(
          a1: g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity,
          a2: pInfo,
          a3: bAlways);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10233190
// Name: void CC_Test_EHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Test_EHandle()
{
  IHandleEntity *m_pEntity; // edx
  char v1; // bl
  IHandleEntity *v2; // eax
  IHandleEntity *v3; // esi
  CBaseEdict *v4; // ecx
  IServerNetworkable *EntityByName; // eax
  CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *v6; // esi
  IServerNetworkable *v7; // eax
  const CBaseEntity *v8; // edi

  if ( g_HandleTest.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(g_HandleTest.m_Index)].m_SerialNumber == HIWORD(g_HandleTest.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(g_HandleTest.m_Index)].m_pEntity != nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[LOWORD(g_HandleTest.m_Index)].m_SerialNumber == HIWORD(g_HandleTest.m_Index) )
      m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(g_HandleTest.m_Index)].m_pEntity;
    else
      m_pEntity = nullptr;
    v1 = LOBYTE(m_pEntity[214].__vftable) == 0;
    if ( g_pEntityList->m_EntPtrArray[LOWORD(g_HandleTest.m_Index)].m_SerialNumber == HIWORD(g_HandleTest.m_Index) )
      v2 = g_pEntityList->m_EntPtrArray[LOWORD(g_HandleTest.m_Index)].m_pEntity;
    else
      v2 = nullptr;
    v3 = v2 + 214;
    if ( LOBYTE(v2[214].__vftable) != v1 )
    {
      if ( LOBYTE(v2[21].__vftable) != 0 )
      {
        LOBYTE(v2[22].__vftable) |= 1u;
        LOBYTE(v3->__vftable) = v1;
      }
      else
      {
        v4 = (CBaseEdict *)v2[6].__vftable;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: v4, offset: 0x358u);
        LOBYTE(v3->__vftable) = v1;
      }
    }
  }
  else
  {
    EntityByName = CreateEntityByName(className: "handle_test", iForceEdictIndex: -1, bNotify: true);
    v6 = (CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *)__RTDynamicCast(
                                                                                      inptr: EntityByName,
                                                                                      VfDelta: 0,
                                                                                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                                                                                      TargetType: &CHandleTest `RTTI Type Descriptor',
                                                                                      isReference: 0);
    if ( v6 == nullptr )
      _Warning(a1: "classname %s used to create wrong class type\n", "handle_test");
    v7 = CreateEntityByName(className: "handle_dummy", iForceEdictIndex: -1, bNotify: true);
    v8 = (const CBaseEntity *)__RTDynamicCast(
                                inptr: v7,
                                VfDelta: 0,
                                SrcType: &CBaseEntity `RTTI Type Descriptor',
                                TargetType: &CHandleDummy `RTTI Type Descriptor',
                                isReference: 0);
    if ( v8 == nullptr )
      _Warning(a1: "classname %s used to create wrong class type\n", "handle_dummy");
    CNetworkHandleBase<CBaseEntity,CEntityFlame::NetworkVar_m_hEntAttached>::Set(this: v6 + 213, val: v8);
    (*(void (__thiscall **)(CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *))(v6->m_Value.m_Index + 96))(a1: v6);
    g_HandleTest.m_Index = *(_DWORD *)(*(int (__thiscall **)(CNetworkHandleBase<CBaseEntity,CSprite::NetworkVar_m_hAttachedToEntity> *))(v6->m_Value.m_Index + 8))(a1: v6);
    _Msg(a1: "Created EHANDLE test entity. Run this command again to transmit the second ent.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10401000
// Name: _dynamic_initializer_for__test_dispatcheffect__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_dispatcheffect__()
{
  ConCommand::ConCommand(
    this: &test_dispatcheffect,
    pName: "test_dispatcheffect",
    callback: (void (__cdecl *)())CC_Player_TestDispatchEffect,
    pHelpString: "Test a clientside dispatch effect.\n"
    "\tUsage: test_dispatcheffect <effect name> <distance away> <flags> <magnitude> <scale>\n"
    "\tDefaults are: <distance 1024> <flags 0> <magnitude 0> <scale 0>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__test_dispatcheffect__);
}

//------------------------------------------------------------------------------
// Address: 0x10401B60
// Name: _dynamic_initializer_for__test_effect__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_effect__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTestEffect> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &test_effect,
           a3: "test_effect");
}

//------------------------------------------------------------------------------
// Address: 0x10402080
// Name: _dynamic_initializer_for__test_entity_blocker__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_entity_blocker__()
{
  ConCommand::ConCommand(
    this: &test_entity_blocker,
    pName: "test_entity_blocker",
    callback: CC_Test_Entity_Blocker,
    pHelpString: "Test command that drops an entity blocker out in front of the player.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__test_entity_blocker__);
}

//------------------------------------------------------------------------------
// Address: 0x10402E00
// Name: _dynamic_initializer_for__test_outtro_stats__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_outtro_stats__()
{
  ConCommand::ConCommand(
    this: &test_outtro_stats,
    pName: "test_outtro_stats",
    callback: CC_Test_Outtro_Stats,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__test_outtro_stats__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B490
// Name: DT_HandleTest::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_HandleTest::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_HandleTest::g_SendTable);
  return atexit(func: DT_HandleTest::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B4B0
// Name: DT_HandleTest::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_HandleTest::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_HandleTest::ignored>();
  DT_HandleTest::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B4C0
// Name: _dynamic_initializer_for__handle_test__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__handle_test__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CHandleTest> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &handle_test,
           a3: "handle_test");
}

//------------------------------------------------------------------------------
// Address: 0x1040B4E0
// Name: _dynamic_initializer_for__handle_dummy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__handle_dummy__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CHandleDummy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &handle_dummy,
           a3: "handle_dummy");
}

//------------------------------------------------------------------------------
// Address: 0x1040B500
// Name: _dynamic_initializer_for__Test_EHandle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_EHandle__()
{
  ConCommand::ConCommand(
    this: &Test_EHandle,
    pName: "Test_EHandle",
    callback: CC_Test_EHandle,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_EHandle__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B540
// Name: _dynamic_initializer_for__test_proxytoggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_proxytoggle__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTest_ProxyToggle_Networkable> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &test_proxytoggle,
           a3: "test_proxytoggle");
}

//------------------------------------------------------------------------------
// Address: 0x1040B7D0
// Name: _dynamic_initializer_for__test_traceline__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_traceline__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTestTraceline> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &test_traceline,
           a3: "test_traceline");
}

//------------------------------------------------------------------------------
// Address: 0x1040EA10
// Name: _dynamic_initializer_for__test_round_winpanel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_round_winpanel__()
{
  ConCommand::ConCommand(
    this: &test_round_winpanel,
    pName: "test_round_winpanel",
    callback: TestRoundWinpanel,
    pHelpString: locale,
    flags: 16386,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__test_round_winpanel__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EA40
// Name: _dynamic_initializer_for__test_match_winpanel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_match_winpanel__()
{
  ConCommand::ConCommand(
    this: &test_match_winpanel,
    pName: "test_match_winpanel",
    callback: TestMatchWinpanel,
    pHelpString: locale,
    flags: 16386,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__test_match_winpanel__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EA70
// Name: _dynamic_initializer_for__test_freezepanel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__test_freezepanel__()
{
  ConCommand::ConCommand(
    this: &test_freezepanel,
    pName: "test_freezepanel",
    callback: TestFreezePanel,
    pHelpString: locale,
    flags: 16386,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__test_freezepanel__);
}

//------------------------------------------------------------------------------
// Address: 0x1041A320
// Name: _dynamic_atexit_destructor_for__test_dispatcheffect__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__test_dispatcheffect__()
{
  ConCommand::~ConCommand(this: &test_dispatcheffect);
}

//------------------------------------------------------------------------------
// Address: 0x1041AAC0
// Name: _dynamic_atexit_destructor_for__test_entity_blocker__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__test_entity_blocker__()
{
  ConCommand::~ConCommand(this: &test_entity_blocker);
}

//------------------------------------------------------------------------------
// Address: 0x1041B0D0
// Name: _dynamic_atexit_destructor_for__test_outtro_stats__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__test_outtro_stats__()
{
  ConCommand::~ConCommand(this: &test_outtro_stats);
}

//------------------------------------------------------------------------------
// Address: 0x1041E750
// Name: DT_HandleTest::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_HandleTest::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_HandleTest::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E760
// Name: _dynamic_atexit_destructor_for__Test_EHandle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_EHandle__()
{
  ConCommand::~ConCommand(this: &Test_EHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA20
// Name: _dynamic_atexit_destructor_for__test_round_winpanel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__test_round_winpanel__()
{
  ConCommand::~ConCommand(this: &test_round_winpanel);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA40
// Name: _dynamic_atexit_destructor_for__test_freezepanel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__test_freezepanel__()
{
  ConCommand::~ConCommand(this: &test_freezepanel);
}

//------------------------------------------------------------------------------
// Address: 0x10401030
// Name: _dynamic_initializer_for__bugswap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bugswap__()
{
  ConCommand::ConCommand(
    this: &bugswap,
    pName: "bug_swap",
    callback: CC_Player_BugBaitSwap,
    pHelpString: "Automatically swaps the current weapon for the bug bait and back again.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bugswap__);
}

//------------------------------------------------------------------------------
// Address: 0x10401060
// Name: _dynamic_initializer_for__use__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__use__()
{
  ConCommand::ConCommand(
    this: &use,
    pName: "use",
    callback: (void (__cdecl *)())CC_Player_Use,
    pHelpString: "Use a particular weapon\t\nArguments: <weapon_name>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__use__);
}

//------------------------------------------------------------------------------
// Address: 0x10401090
// Name: _dynamic_initializer_for__noclip_fixup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__noclip_fixup__()
{
  ConVar::ConVar(this: &noclip_fixup, pName: "noclip_fixup", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__noclip_fixup__);
}

//------------------------------------------------------------------------------
// Address: 0x104010C0
// Name: _dynamic_initializer_for__noclip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__noclip_command__()
{
  ConCommand::ConCommand(
    this: &noclip_command,
    pName: "noclip",
    callback: (void (__cdecl *)())noclip,
    pHelpString: "Toggle. Player becomes non-solid and flies.  Optional argument of 0 or 1 to force enable/disable",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__noclip_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104010F0
// Name: _dynamic_initializer_for__god__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__god__()
{
  ConCommand::ConCommand(
    this: &god,
    pName: "god",
    callback: CC_God_f,
    pHelpString: "Toggle. Player becomes invulnerable.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__god__);
}

//------------------------------------------------------------------------------
// Address: 0x10401120
// Name: _dynamic_initializer_for__ent_setpos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_setpos_command__()
{
  ConCommand::ConCommand(
    this: &ent_setpos_command,
    pName: "ent_setpos",
    callback: (void (__cdecl *)())ent_setpos,
    pHelpString: "Move entity to position",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_setpos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10401150
// Name: _dynamic_initializer_for__ent_setang_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_setang_command__()
{
  ConCommand::ConCommand(
    this: &ent_setang_command,
    pName: "ent_setang",
    callback: (void (__cdecl *)())ent_setang,
    pHelpString: "Set entity angles",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_setang_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10401180
// Name: _dynamic_initializer_for__setpos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setpos_command__()
{
  ConCommand::ConCommand(
    this: &setpos_command,
    pName: "setpos",
    callback: (void (__cdecl *)())setpos,
    pHelpString: "Move player to specified origin (must have sv_cheats).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setpos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104011B0
// Name: _dynamic_initializer_for__setpos_player_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setpos_player_command__()
{
  ConCommand::ConCommand(
    this: &setpos_player_command,
    pName: "setpos_player",
    callback: (void (__cdecl *)())setpos_player,
    pHelpString: "Move specified player to specified origin (must have sv_cheats).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setpos_player_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104011E0
// Name: _dynamic_initializer_for__setang__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setang__()
{
  ConCommand::ConCommand(
    this: &setang,
    pName: "setang",
    callback: (void (__cdecl *)())CC_setang_f,
    pHelpString: "Snap player eyes to specified pitch yaw <roll:optional> (must have sv_cheats).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setang__);
}

//------------------------------------------------------------------------------
// Address: 0x10401210
// Name: _dynamic_initializer_for__setpos_exact_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setpos_exact_command__()
{
  ConCommand::ConCommand(
    this: &setpos_exact_command,
    pName: "setpos_exact",
    callback: (void (__cdecl *)())setpos_exact,
    pHelpString: "Move player to an exact specified origin (must have sv_cheats).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setpos_exact_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10401240
// Name: _dynamic_initializer_for__setang_exact_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setang_exact_command__()
{
  ConCommand::ConCommand(
    this: &setang_exact_command,
    pName: "setang_exact",
    callback: (void (__cdecl *)())setang_exact,
    pHelpString: "Snap player eyes and orientation to specified pitch yaw <roll:optional> (must have sv_cheats).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setang_exact_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10401270
// Name: _dynamic_initializer_for__notarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__notarget__()
{
  ConCommand::ConCommand(
    this: &notarget,
    pName: "notarget",
    callback: CC_Notarget_f,
    pHelpString: "Toggle. Player becomes hidden to NPCs.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__notarget__);
}

//------------------------------------------------------------------------------
// Address: 0x104012A0
// Name: _dynamic_initializer_for__hurtme__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hurtme__()
{
  ConCommand::ConCommand(
    this: &hurtme,
    pName: "hurtme",
    callback: (void (__cdecl *)())CC_HurtMe_f,
    pHelpString: "Hurts the player.\n\tArguments: <health to lose>",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hurtme__);
}

//------------------------------------------------------------------------------
// Address: 0x104012D0
// Name: _dynamic_initializer_for__groundlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__groundlist__()
{
  ConCommand::ConCommand(
    this: &groundlist,
    pName: "groundlist",
    callback: (void (__cdecl *)())CC_GroundList_f,
    pHelpString: "Display ground entity list <index>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__groundlist__);
}

//------------------------------------------------------------------------------
// Address: 0x10401300
// Name: _dynamic_initializer_for__s_DirtyKDTree__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DirtyKDTree__()
{
  CDirtySpatialPartitionEntityList::CDirtySpatialPartitionEntityList(
    this: &s_DirtyKDTree,
    name: "CDirtySpatialPartitionEntityList");
  return atexit(func: dynamic_atexit_destructor_for__s_DirtyKDTree__);
}

//------------------------------------------------------------------------------
// Address: 0x10401B80
// Name: _dynamic_initializer_for__env_blood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_blood__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBlood> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_blood,
           a3: "env_blood");
}

//------------------------------------------------------------------------------
// Address: 0x10402E30
// Name: _dynamic_initializer_for__s_Microphones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_Microphones__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_Microphones__);
}

//------------------------------------------------------------------------------
// Address: 0x10402E40
// Name: _dynamic_initializer_for__env_microphone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_microphone__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvMicrophone> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_microphone,
           a3: "env_microphone");
}

//------------------------------------------------------------------------------
// Address: 0x1040EAA0
// Name: _dynamic_initializer_for__mp_dump_timers_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_dump_timers_command__()
{
  ConCommand::ConCommand(
    this: &mp_dump_timers_command,
    pName: "mp_dump_timers",
    callback: mp_dump_timers,
    pHelpString: "Prints round timers to the console for debugging",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mp_dump_timers_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041A330
// Name: _dynamic_atexit_destructor_for__bugswap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bugswap__()
{
  ConCommand::~ConCommand(this: &bugswap);
}

//------------------------------------------------------------------------------
// Address: 0x1041A340
// Name: _dynamic_atexit_destructor_for__use__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__use__()
{
  ConCommand::~ConCommand(this: &use);
}

//------------------------------------------------------------------------------
// Address: 0x1041A350
// Name: _dynamic_atexit_destructor_for__noclip_fixup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__noclip_fixup__()
{
  ConVar::~ConVar(this: &noclip_fixup);
}

//------------------------------------------------------------------------------
// Address: 0x1041A360
// Name: _dynamic_atexit_destructor_for__noclip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__noclip_command__()
{
  ConCommand::~ConCommand(this: &noclip_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A370
// Name: _dynamic_atexit_destructor_for__god__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__god__()
{
  ConCommand::~ConCommand(this: &god);
}

//------------------------------------------------------------------------------
// Address: 0x1041A380
// Name: _dynamic_atexit_destructor_for__ent_setpos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_setpos_command__()
{
  ConCommand::~ConCommand(this: &ent_setpos_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A390
// Name: _dynamic_atexit_destructor_for__ent_setang_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_setang_command__()
{
  ConCommand::~ConCommand(this: &ent_setang_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A3A0
// Name: _dynamic_atexit_destructor_for__setpos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setpos_command__()
{
  ConCommand::~ConCommand(this: &setpos_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A3B0
// Name: _dynamic_atexit_destructor_for__setpos_player_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setpos_player_command__()
{
  ConCommand::~ConCommand(this: &setpos_player_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A3C0
// Name: _dynamic_atexit_destructor_for__setang__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setang__()
{
  ConCommand::~ConCommand(this: &setang);
}

//------------------------------------------------------------------------------
// Address: 0x1041A3D0
// Name: _dynamic_atexit_destructor_for__setpos_exact_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setpos_exact_command__()
{
  ConCommand::~ConCommand(this: &setpos_exact_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A3E0
// Name: _dynamic_atexit_destructor_for__setang_exact_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setang_exact_command__()
{
  ConCommand::~ConCommand(this: &setang_exact_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A3F0
// Name: _dynamic_atexit_destructor_for__notarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__notarget__()
{
  ConCommand::~ConCommand(this: &notarget);
}

//------------------------------------------------------------------------------
// Address: 0x1041A400
// Name: _dynamic_atexit_destructor_for__hurtme__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hurtme__()
{
  ConCommand::~ConCommand(this: &hurtme);
}

//------------------------------------------------------------------------------
// Address: 0x1041A410
// Name: _dynamic_atexit_destructor_for__groundlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__groundlist__()
{
  ConCommand::~ConCommand(this: &groundlist);
}

//------------------------------------------------------------------------------
// Address: 0x1041A420
// Name: _DataMapInit_CPointClientCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointClientCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_114);
}

//------------------------------------------------------------------------------
// Address: 0x1041A430
// Name: _DataMapInit_CPointServerCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointServerCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_115);
}

//------------------------------------------------------------------------------
// Address: 0x1041A440
// Name: _DataMapInit_CPointBroadcastClientCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPointBroadcastClientCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_116);
}

//------------------------------------------------------------------------------
// Address: 0x1041B0E0
// Name: _DataMapInit_CMessage__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMessage__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_179);
}

//------------------------------------------------------------------------------
// Address: 0x1041B0F0
// Name: _DataMapInit_CCredits__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCredits__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_177);
}

//------------------------------------------------------------------------------
// Address: 0x1041B100
// Name: _DataMapInit_COuttroStats__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_COuttroStats__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_178);
}

//------------------------------------------------------------------------------
// Address: 0x1041B110
// Name: _dynamic_atexit_destructor_for__s_Microphones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_Microphones__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_Microphones);
}

//------------------------------------------------------------------------------
// Address: 0x1041B120
// Name: _DataMapInit_CEnvMicrophone__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvMicrophone__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_180);
}

//------------------------------------------------------------------------------
// Address: 0x1041E770
// Name: _ServerClassInit_DT_HandleTest::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_HandleTest::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_223;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA50
// Name: _dynamic_atexit_destructor_for__mp_dump_timers_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_dump_timers_command__()
{
  ConCommand::~ConCommand(this: &mp_dump_timers_command);
}

} // namespace server
