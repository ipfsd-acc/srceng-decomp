// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_rmisc.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100CE7E0
// Name: void R_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_Init()
{
  InitMathlib();
  UpdateMaterialSystemConfig();
}

//------------------------------------------------------------------------------
// Address: 0x100CE7F0
// Name: void R_LoadWorldGeometry(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LoadWorldGeometry(bool bDXChange)
{
  IOverlayMgr *v1; // eax

  MaterialSystem_DestroySortinfo();
  MaterialSystem_RegisterPaintSurfaces();
  MaterialSystem_RegisterLightmapSurfaces();
  MaterialSystem_CreateSortinfo();
  if ( bDXChange )
  {
    modelloader->Map_LoadDisplacements(this: modelloader, a2: host_state.worldmodel, a3: true);
    ((void (__cdecl *)(model_t *))modelloader->RecomputeSurfaceFlags)(a1: host_state.worldmodel);
  }
  else if ( !modelloader->Map_GetRenderInfoAllocated(this: modelloader) )
  {
    modelloader->Map_LoadDisplacements(this: modelloader, a2: host_state.worldmodel, a3: false);
    ((void (__cdecl *)(int))modelloader->Map_SetRenderInfoAllocated)(a1: 1);
  }
  Mod_MarkWaterSurfaces(pModel: host_state.worldmodel);
  GL_RebuildLightmaps();
  if ( bDXChange )
  {
    R_Surface_LevelInit();
    R_DecalReSortMaterials();
    v1 = OverlayMgr();
    v1->ReSortMaterials(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE8A0
// Name: void R_TimeRefresh_f(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl R_TimeRefresh_f()
{
  int v0; // eax
  int m_nValue; // edi
  CStatTime *v2; // ecx
  int v3; // esi
  CStatTime *v4; // ecx
  double v5; // st7
  int v6; // [esp+14h] [ebp-108h]
  double dest; // [esp+1Ch] [ebp-100h] BYREF
  int v8; // [esp+24h] [ebp-F8h]
  int v9; // [esp+28h] [ebp-F4h]
  int v10; // [esp+2Ch] [ebp-F0h]
  _BYTE view_16[216]; // [esp+44h] [ebp-D8h] OVERLAPPED BYREF

  *(_DWORD *)&view_16[100] = 0;
  *(_DWORD *)&view_16[104] = 1101004800;
  *(_DWORD *)&view_16[108] = 1120403456;
  *(_DWORD *)&view_16[112] = 1132068864;
  *(_DWORD *)&view_16[116] = 1148846080;
  *(_DWORD *)&view_16[120] = 1092616192;
  *(_DWORD *)&view_16[124] = 1084227584;
  *(_DWORD *)&view_16[128] = 0;
  *(_DWORD *)&view_16[132] = 2;
  view_16[204] = 4;
  view_16[0] = 0;
  ((void (__thiscall *)(IMaterialSystem *))materials->Flush)(a1: materials);
  _V_memset(dest: (char *)&dest + 4, fill: 0, count: 244);
  *(Vector *)&view_16[60] = g_MainViewOrigin[0];
  memset(&view_16[72], 0, 12);
  HIDWORD(dest) = 0;
  v8 = 0;
  v9 = videomode->GetModeWidth(this: videomode);
  v0 = videomode->GetModeHeight(this: videomode);
  *(_DWORD *)&view_16[52] = 1117126656;
  *(_DWORD *)&view_16[56] = 1117126656;
  v10 = v0;
  *(_DWORD *)&view_16[100] = 1065353216;
  *(_DWORD *)&view_16[84] = 1082130432;
  *(_DWORD *)&view_16[88] = 1182793728;
  *(_DWORD *)&view_16[92] = 1082130432;
  *(_DWORD *)&view_16[96] = 1182793728;
  if ( developer.m_pParent != nullptr )
    m_nValue = developer.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&developer.IConVar, value: 0, a2: 1u, a3: v6);
  *(float *)&view_16[212] = _Plat_FloatTime(this: v2);
  v3 = 0;
  *(_DWORD *)&view_16[208] = 0;
  do
  {
    *(float *)&view_16[76] = (double)*(int *)&view_16[208] * 0.0078125 * 360.0;
    ((void (__thiscall *)(IBaseClientDLL *))g_ClientDLL->RenderView)(a1: g_ClientDLL);
    Shader_SwapBuffers();
    *(_DWORD *)&view_16[208] = ++v3;
  }
  while ( v3 < 128 );
  ((void (__thiscall *)(IMaterialSystem *))materials->Flush)(a1: materials);
  Shader_SwapBuffers();
  v5 = _Plat_FloatTime(this: v4);
  *(float *)&view_16[212] = v5 - *(float *)&view_16[212];
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&developer.IConVar, value: m_nValue, a2: 1u, a3: (int)&dest + 4);
  ConMsg(a1: "%f seconds (%f fps)\n", *(float *)&view_16[212], 128.0 / *(float *)&view_16[212]);
}

//------------------------------------------------------------------------------
// Address: 0x100CEAE0
// Name: r_cleardecals
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_cleardecals(const CCommand *args)
{
  bool bPermanent; // [esp+0h] [ebp-4h]

  if ( host_state.worldmodel != nullptr )
  {
    bPermanent = false;
    if ( args->m_nArgc == 2 )
      bPermanent = _V_stricmp(s1: args->m_ppArgv[1], s2: "permanent") == 0;
    R_DecalTerm(pBrushData: host_state.worldmodel->brush.pShared, term_permanent_decals: bPermanent);
  }
  R_RemoveAllDecalsFromAllModels();
}

//------------------------------------------------------------------------------
// Address: 0x100CEB40
// Name: void R_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LevelInit()
{
  IStaticPropMgrEngine *v0; // eax
  ISpatialPartitionInternal *v1; // eax
  IStaticPropMgrEngine *v2; // eax
  IOverlayMgr *v3; // eax
  unsigned int numsurfaces; // [esp-20h] [ebp-2Ch]
  Vector *p_mins; // [esp-1Ch] [ebp-28h]
  const CCommand *v6; // [esp-14h] [ebp-20h]

  _ConDMsg(a1: &args.m_pArgSBuffer[24]);
  _COM_TimestampedLog(a1: &args.m_pArgSBuffer[4]);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: (const char *)&args,
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  memset32(d_lightstyleframe, 1, 0x100u);
  r_framecount = 1;
  memset32(d_lightstylevalue, 264, 0x100u);
  R_DecalInit();
  R_LoadSkys();
  R_InitStudio(args: v6);
  if ( sv.m_State < ss_active )
  {
    g_pShadowMgr->LevelShutdown(this: g_pShadowMgr);
    v0 = StaticPropMgr();
    v0->LevelShutdown(this: v0);
    v1 = SpatialPartition();
    p_mins = &host_state.worldmodel->mins;
    ((void (__thiscall *)(ISpatialPartitionInternal *))v1->Init)(a1: v1);
    v2 = StaticPropMgr();
    v2->LevelInit(this: v2);
    numsurfaces = host_state.worldbrush->numsurfaces;
    ((void (__thiscall *)(IShadowMgrInternal *))g_pShadowMgr->LevelInit)(a1: g_pShadowMgr);
  }
  modelloader->UnloadUnreferencedModels(this: modelloader);
  V_FileBase(in: com_gamedir, out: gamedir_1, maxlen: 260);
  if ( *(_DWORD *)(host_state.worldmodel->sprite.numframes + 168) == 0 && _V_stricmp(s1: gamedir_1, s2: "infested") != 0 )
  {
    _ConDMsg(a1: "Level unlit, setting 'mat_fullbright 1'\n");
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&mat_fullbright.IConVar,
      value: 1,
      a2: numsurfaces,
      a3: (int)p_mins);
  }
  UpdateMaterialSystemConfig();
  if ( mat_levelflush.m_pParent != nullptr && mat_levelflush.m_pParent->m_Value.m_nValue != 0 )
    materials->ResetTempHWMemory(this: materials, a2: false);
  materials->CacheUsedMaterials(this: materials);
  MaterialSystem_DestroySortinfo();
  MaterialSystem_RegisterPaintSurfaces();
  MaterialSystem_RegisterLightmapSurfaces();
  MaterialSystem_CreateSortinfo();
  if ( !modelloader->Map_GetRenderInfoAllocated(this: modelloader) )
  {
    modelloader->Map_LoadDisplacements(this: modelloader, a2: host_state.worldmodel, a3: false);
    modelloader->Map_SetRenderInfoAllocated(this: modelloader, a2: true);
  }
  Mod_MarkWaterSurfaces(pModel: host_state.worldmodel);
  GL_RebuildLightmaps();
  R_Surface_LevelInit();
  R_Areaportal_LevelInit();
  v3 = OverlayMgr();
  v3->CreateFragments(this: v3);
  _COM_TimestampedLog(a1: "R_LevelInit: Finish");
  g_RendererInLevel = true;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100CED60
// Name: void R_LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LevelShutdown()
{
  R_Surface_LevelShutdown();
  R_Areaportal_LevelShutdown();
  g_DispLightmapSamplePositions.m_Size = 0;
  g_DispLightmapSamplePositions.m_Memory.m_nAllocated = 0;
  g_DispLightmapSamplePositions.m_pElements = g_DispLightmapSamplePositions.m_Memory.m_pMemory;
  g_RendererInLevel = false;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100CE3D0
// Name: void R_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_Init()
{
  InitMathlib();
  UpdateMaterialSystemConfig();
}

//------------------------------------------------------------------------------
// Address: 0x100CE3E0
// Name: void R_LoadWorldGeometry(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LoadWorldGeometry(bool bDXChange)
{
  IOverlayMgr *v1; // eax

  MaterialSystem_DestroySortinfo();
  MaterialSystem_RegisterPaintSurfaces();
  MaterialSystem_RegisterLightmapSurfaces();
  MaterialSystem_CreateSortinfo();
  if ( bDXChange )
  {
    modelloader->Map_LoadDisplacements(this: modelloader, a2: host_state.worldmodel, a3: true);
    ((void (__cdecl *)(model_t *))modelloader->RecomputeSurfaceFlags)(a1: host_state.worldmodel);
  }
  else if ( !modelloader->Map_GetRenderInfoAllocated(this: modelloader) )
  {
    modelloader->Map_LoadDisplacements(this: modelloader, a2: host_state.worldmodel, a3: false);
    ((void (__cdecl *)(int))modelloader->Map_SetRenderInfoAllocated)(a1: 1);
  }
  Mod_MarkWaterSurfaces(pModel: host_state.worldmodel);
  GL_RebuildLightmaps();
  if ( bDXChange )
  {
    R_Surface_LevelInit();
    R_DecalReSortMaterials();
    v1 = OverlayMgr();
    v1->ReSortMaterials(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE490
// Name: void R_TimeRefresh_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_TimeRefresh_f()
{
  int v0; // eax
  int m_nValue; // edi
  int v2; // ecx
  int v3; // esi
  int v4; // ecx
  double v5; // st7
  CViewSetup view; // [esp+20h] [ebp-FCh] BYREF
  int i; // [esp+114h] [ebp-8h]
  float time; // [esp+118h] [ebp-4h]

  view.m_flAspectRatio = 0.0;
  view.m_flNearBlurDepth = 20.0;
  view.m_flNearFocusDepth = 100.0;
  view.m_flFarFocusDepth = 250.0;
  view.m_flFarBlurDepth = 1000.0;
  view.m_flNearBlurRadius = 10.0;
  view.m_flFarBlurRadius = 5.0;
  view.m_nDoFQuality = 0;
  view.m_nMotionBlurMode = MOTION_BLUR_GAME;
  *((_BYTE *)&view + 240) = 4;
  view.m_bCustomViewMatrix = false;
  materials->Flush(this: materials, a2: true);
  _V_memset(dest: (void *)&view, fill: 0, count: 244);
  view.origin = g_MainViewOrigin[0];
  memset((void *)&view.angles, 0, sizeof(view.angles));
  view.x = 0;
  view.y = 0;
  view.width = videomode->GetModeWidth(this: videomode);
  v0 = videomode->GetModeHeight(this: videomode);
  view.fov = 75.0;
  view.fovViewmodel = 75.0;
  view.height = v0;
  view.m_flAspectRatio = 1.0;
  view.zNear = 4.0;
  view.zFar = 16384.0;
  view.zNearViewmodel = 4.0;
  view.zFarViewmodel = 16384.0;
  if ( developer.m_pParent != nullptr )
    m_nValue = developer.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&developer.IConVar, value: 0);
  time = _Plat_FloatTime(a1: v2);
  v3 = 0;
  i = 0;
  do
  {
    view.angles.y = (double)i * 0.0078125 * 360.0;
    g_ClientDLL->RenderView(this: g_ClientDLL, a2: &view, a3: 1, a4: 3);
    Shader_SwapBuffers();
    i = ++v3;
  }
  while ( v3 < 128 );
  materials->Flush(this: materials, a2: true);
  Shader_SwapBuffers();
  v5 = _Plat_FloatTime(a1: v4);
  time = v5 - time;
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&developer.IConVar, value: m_nValue);
  ConMsg(a1: "%f seconds (%f fps)\n", time, 128.0 / time);
}

//------------------------------------------------------------------------------
// Address: 0x100CE6D0
// Name: r_cleardecals
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_cleardecals(const CCommand *args)
{
  bool bPermanent; // [esp+0h] [ebp-4h]

  if ( host_state.worldmodel != nullptr )
  {
    bPermanent = false;
    if ( args->m_nArgc == 2 )
      bPermanent = _V_stricmp(s1: args->m_ppArgv[1], s2: "permanent") == 0;
    R_DecalTerm(pBrushData: host_state.worldmodel->brush.pShared, term_permanent_decals: bPermanent);
  }
  R_RemoveAllDecalsFromAllModels();
}

//------------------------------------------------------------------------------
// Address: 0x100CE730
// Name: void R_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LevelInit()
{
  CStaticPropMgr *v0; // eax
  CSpatialPartition *v1; // eax
  CStaticPropMgr *v2; // eax
  IOverlayMgr *v3; // eax
  const CCommand *v4; // [esp-14h] [ebp-20h]

  _ConDMsg(a1: &args.m_pArgSBuffer[24]);
  _COM_TimestampedLog(a1: &args.m_pArgSBuffer[4]);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: (const char *)&args,
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  memset32(d_lightstyleframe, 1, 0x100u);
  r_framecount = 1;
  memset32(d_lightstylevalue, 264, 0x100u);
  R_DecalInit();
  R_LoadSkys();
  R_InitStudio(args: v4);
  if ( sv.m_State < ss_active )
  {
    g_pShadowMgr->LevelShutdown(this: g_pShadowMgr);
    v0 = StaticPropMgr();
    v0->LevelShutdown(this: v0);
    v1 = SpatialPartition();
    v1->Init(this: v1, a2: &host_state.worldmodel->mins, a3: &host_state.worldmodel->maxs);
    v2 = StaticPropMgr();
    v2->LevelInit(this: v2);
    g_pShadowMgr->LevelInit(this: g_pShadowMgr, a2: host_state.worldbrush->numsurfaces);
  }
  modelloader->UnloadUnreferencedModels(this: modelloader);
  V_FileBase(in: com_gamedir, out: gamedir_1, maxlen: 260);
  if ( *(_DWORD *)(host_state.worldmodel->sprite.numframes + 168) == 0 && _V_stricmp(s1: gamedir_1, s2: "infested") != 0 )
  {
    _ConDMsg(a1: "Level unlit, setting 'mat_fullbright 1'\n");
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_fullbright.IConVar, value: 1);
  }
  UpdateMaterialSystemConfig();
  if ( mat_levelflush.m_pParent != nullptr && mat_levelflush.m_pParent->m_Value.m_nValue != 0 )
    materials->ResetTempHWMemory(this: materials, a2: false);
  materials->CacheUsedMaterials(this: materials);
  MaterialSystem_DestroySortinfo();
  MaterialSystem_RegisterPaintSurfaces();
  MaterialSystem_RegisterLightmapSurfaces();
  MaterialSystem_CreateSortinfo();
  if ( !modelloader->Map_GetRenderInfoAllocated(this: modelloader) )
  {
    modelloader->Map_LoadDisplacements(this: modelloader, a2: host_state.worldmodel, a3: false);
    modelloader->Map_SetRenderInfoAllocated(this: modelloader, a2: true);
  }
  Mod_MarkWaterSurfaces(pModel: host_state.worldmodel);
  GL_RebuildLightmaps();
  R_Surface_LevelInit();
  R_Areaportal_LevelInit();
  v3 = OverlayMgr();
  v3->CreateFragments(this: v3);
  _COM_TimestampedLog(a1: "R_LevelInit: Finish");
  g_RendererInLevel = true;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100CE950
// Name: void R_LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LevelShutdown()
{
  R_Surface_LevelShutdown();
  R_Areaportal_LevelShutdown();
  g_DispLightmapSamplePositions.m_Size = 0;
  g_DispLightmapSamplePositions.m_Memory.m_nAllocated = 0;
  g_DispLightmapSamplePositions.m_pElements = g_DispLightmapSamplePositions.m_Memory.m_pMemory;
  g_RendererInLevel = false;
}

} // namespace engine_xlsp
