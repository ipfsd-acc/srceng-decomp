// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/matsys_interface.cpp
// Functions: 254
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100E4F60
// Name: NukeModeSwitchSaveGames
// Source: json
//------------------------------------------------------------------------------
int NukeModeSwitchSaveGames()
{
  int result; // eax

  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: "SAVE\\modeswitchsave.sav", a3: nullptr) )
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: "SAVE\\modeswitchsave.sav", a3: nullptr);
  result = ((int (__thiscall *)(IBaseFileSystem *, const char *, _DWORD))g_pFileSystem->FileExists)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: "SAVE\\modeswitchsave.tga",
             a3: 0);
  if ( (_BYTE)result != 0 )
    return ((int (__thiscall *)(IFileSystem *, const char *, _DWORD))g_pFileSystem->RemoveFile)(
             a1: g_pFileSystem,
             a2: "SAVE\\modeswitchsave.tga",
             a3: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E4FD0
// Name: void mat_hdr_level_Callback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_hdr_level_Callback()
{
  vgui::CTreeViewListControl *v0; // ecx
  ECommandTarget_t TraceType; // eax

  if ( g_pMaterialSystemHardwareConfig->GetHardwareHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE
    && saverestore->IsValidSave(this: saverestore) != 0
    && modelloader->LastLoadedMapHasHDRLighting(this: modelloader)
    && CBaseServer::GetMaxClients(this: &sv) == 1
    && !sv.m_bIsLevelMainMenuBackground )
  {
    NukeModeSwitchSaveGames();
    TraceType = CTraceFilter::GetTraceType(this: v0);
    Cbuf_AddText(eTarget: TraceType, pText: "save modeswitchsave;wait;load modeswitchsave\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5040
// Name: bool MaterialConfigLightingChanged(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MaterialConfigLightingChanged()
{
  return s_bConfigLightingChanged;
}

//------------------------------------------------------------------------------
// Address: 0x100E5050
// Name: void ClearMaterialConfigLightingChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearMaterialConfigLightingChanged()
{
  s_bConfigLightingChanged = false;
}

//------------------------------------------------------------------------------
// Address: 0x100E5060
// Name: int GetScreenAspectMode(int,int)
// Source: json
//------------------------------------------------------------------------------
AspectRatioMode_t __cdecl GetScreenAspectMode(int width, int height)
{
  double v2; // st7
  AspectRatioMode_t m_Mode; // ecx
  double v4; // st7
  long double v5; // st6
  long double v6; // st6
  long double v7; // st6
  AspectRatioMode_t result; // eax
  float closestAspectRatioDist; // [esp+8h] [ebp+8h]

  v2 = (double)width;
  m_Mode = ASPECT_RATIO_4x3;
  closestAspectRatioDist = 99999.0;
  v4 = v2 / (double)height;
  v5 = fabs(flt_10416628 - v4);
  if ( v5 < 99999.0 )
  {
    m_Mode = g_RatioToAspectModes[0].m_Mode;
    closestAspectRatioDist = v5;
  }
  v6 = fabs(flt_10416630 - v4);
  if ( closestAspectRatioDist > v6 )
  {
    m_Mode = dword_1041662C;
    closestAspectRatioDist = v6;
  }
  v7 = fabs(flt_10416638 - v4);
  if ( closestAspectRatioDist > v7 )
  {
    m_Mode = dword_10416634;
    closestAspectRatioDist = v7;
  }
  result = dword_1041663C;
  if ( closestAspectRatioDist <= fabs(flt_10416640 - v4) )
    return m_Mode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E5110
// Name: void UpdateMaterialSystemConfig(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl UpdateMaterialSystemConfig()
{
  unsigned int v0; // [esp-8h] [ebp-8h]
  int v1; // [esp-4h] [ebp-4h]

  V_FileBase(in: com_gamedir, out: gamedir_2, maxlen: 260);
  if ( host_state.worldbrush != nullptr
    && host_state.worldbrush->lightdata == nullptr
    && _V_stricmp(s1: gamedir_2, s2: "infested") != 0 )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_fullbright.IConVar, value: 1, a2: v0, a3: v1);
  }
  if ( materials->UpdateConfig(this: materials, a2: false) )
    s_bConfigLightingChanged = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E5180
// Name: CreateWaterReflectionTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl CreateWaterReflectionTexture()
{
  int v0; // eax
  int v1; // eax
  IMaterialSystem_vtbl *v2; // edi
  int v3; // esi
  int v4; // eax

  v0 = _CommandLine();
  v1 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v0 + 28))(
         a1: v0,
         a2: "-reflectionTextureSize",
         a3: 1024);
  v2 = materials->__vftable;
  v3 = v1;
  v4 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int))materials->GetBackBufferFormat)(
         a1: materials,
         a2: 0,
         a3: 12,
         a4: 1);
  return ((ITexture *(__thiscall *)(IMaterialSystem *, const char *, int, int, int, int))v2->CreateNamedRenderTargetTextureEx2)(
           a1: materials,
           a2: "_rt_WaterReflection",
           a3: v3,
           a4: v3,
           a5: 2,
           a6: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100E51D0
// Name: CreateCameraTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl CreateCameraTexture()
{
  int v0; // eax
  int v1; // eax
  IMaterialSystem_vtbl *v2; // edi
  int v3; // esi
  int v4; // eax

  v0 = _CommandLine();
  v1 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v0 + 28))(a1: v0, a2: "-monitorTextureSize", a3: 256);
  v2 = materials->__vftable;
  v3 = v1;
  v4 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, _DWORD, int))materials->GetBackBufferFormat)(
         a1: materials,
         a2: 0,
         a3: 0,
         a4: 1);
  return ((ITexture *(__thiscall *)(IMaterialSystem *, const char *, int, int, int, int))v2->CreateNamedRenderTargetTextureEx2)(
           a1: materials,
           a2: "_rt_Camera",
           a3: v3,
           a4: v3,
           a5: 1,
           a6: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100E5220
// Name: CreateQuarterSizedFBTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__usercall CreateQuarterSizedFBTexture@<eax>(int n@<eax>, unsigned int iRenderTargetFlags)
{
  ImageFormat v2; // esi
  char nbuf[20]; // [esp+4h] [ebp-14h] BYREF

  sprintf(string: nbuf, format: "_rt_SmallFB%d", n);
  v2 = materials->GetBackBufferFormat(this: materials);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT )
    v2 = IMAGE_FORMAT_RGBA16161616F;
  return materials->CreateNamedRenderTargetTextureEx2(
           this: materials,
           a2: nbuf,
           a3: 0,
           a4: 0,
           a5: RT_SIZE_HDR,
           a6: v2,
           a7: MATERIAL_RT_DEPTH_SHARED,
           a8: 12u,
           a9: iRenderTargetFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100E5290
// Name: CreateTeenyFBTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__usercall CreateTeenyFBTexture@<eax>(int n@<eax>)
{
  ImageFormat v1; // esi
  char nbuf[20]; // [esp+4h] [ebp-14h] BYREF

  sprintf(string: nbuf, format: "_rt_TeenyFB%d", n);
  v1 = materials->GetBackBufferFormat(this: materials);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT )
    v1 = IMAGE_FORMAT_RGBA16161616F;
  return materials->CreateNamedRenderTargetTextureEx2(
           this: materials,
           a2: nbuf,
           a3: 32,
           a4: 32,
           a5: RT_SIZE_DEFAULT,
           a6: v1,
           a7: MATERIAL_RT_DEPTH_SHARED,
           a8: 12u,
           a9: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100E5300
// Name: mat_info
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_info()
{
  materials->SpewDriverInfo(this: materials);
}

//------------------------------------------------------------------------------
// Address: 0x100E5310
// Name: void TangentSpaceComputeBasis(class Vector __near &,class Vector __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TangentSpaceComputeBasis(
        Vector *tangentS,
        Vector *tangentT,
        const Vector *normal,
        const Vector *tVect,
        bool negateTangent)
{
  tangentS->x = (float)(tVect->z * normal->y) - (float)(normal->z * tVect->y);
  tangentS->y = (float)(normal->z * tVect->x) - (float)(normal->x * tVect->z);
  tangentS->z = (float)(normal->x * tVect->y) - (float)(tVect->x * normal->y);
  VectorNormalize(vec: tangentS);
  tangentT->x = (float)(tangentS->y * normal->z) - (float)(tangentS->z * normal->y);
  tangentT->y = (float)(normal->x * tangentS->z) - (float)(normal->z * tangentS->x);
  tangentT->z = (float)(tangentS->x * normal->y) - (float)(tangentS->y * normal->x);
  VectorNormalize(vec: tangentT);
  if ( negateTangent )
  {
    tangentS->x = tangentS->x * -1.0;
    tangentS->y = tangentS->y * -1.0;
    tangentS->z = tangentS->z * -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5420
// Name: void SetTexInfoBaseTexture2Flags(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetTexInfoBaseTexture2Flags()
{
  worldbrushdata_t *worldbrush; // eax
  int v1; // ecx
  int v2; // edx
  mtexinfo_t *v3; // ebx
  IMaterial *material; // esi
  int v5; // edi
  int v6; // eax
  int v7; // esi
  const char *v8; // eax
  int nParms; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  v1 = 0;
  if ( host_state.worldbrush->numtexinfo > 0 )
  {
    v2 = 0;
    do
    {
      worldbrush->texinfo[v2].texinfoFlags &= ~1u;
      worldbrush = host_state.worldbrush;
      ++v1;
      ++v2;
    }
    while ( v1 < host_state.worldbrush->numtexinfo );
  }
  i = 0;
  if ( worldbrush->numtexinfo > 0 )
  {
    v11 = 0;
    do
    {
      v3 = &worldbrush->texinfo[v11];
      material = v3->material;
      if ( material != nullptr )
      {
        v5 = (int)material->GetShaderParams(this: v3->material);
        v6 = material->ShaderParamCount(this: material);
        v7 = 0;
        nParms = v6;
        if ( v6 > 0 )
        {
          while ( 1 )
          {
            if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v5 + 4 * v7) + 72))(a1: *(_DWORD *)(v5 + 4 * v7)) != 0 )
            {
              v8 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v5 + 4 * v7) + 8))(a1: *(_DWORD *)(v5 + 4 * v7));
              if ( _V_stricmp(s1: v8, s2: "$basetexture2") == 0 )
                break;
            }
            if ( ++v7 >= nParms )
              goto LABEL_13;
          }
          v3->texinfoFlags |= 1u;
        }
LABEL_13:
        worldbrush = host_state.worldbrush;
      }
      ++v11;
      ++i;
    }
    while ( i < worldbrush->numtexinfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5500
// Name: ReadMaterialSystemConfigFromRegistry
// Source: json
//------------------------------------------------------------------------------
void __usercall ReadMaterialSystemConfigFromRegistry(MaterialSystem_Config_t *config@<edi>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *Key; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
  {
    v2 = KeyValues::KeyValues(this: v1, setName: "VideoConfig");
    v3 = v2;
    if ( v2 != nullptr )
    {
      if ( !ReadCurrentVideoConfig(pConfigKeys: v2, bDefault: false) )
      {
        KeyValues::deleteThis(this: v3);
        return;
      }
      Key = KeyValues::FindKey(this: v3, keyName: "setting.defaultres", bCreate: false);
      if ( Key != nullptr )
        config->m_VideoMode.m_Width = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
      v5 = KeyValues::FindKey(this: v3, keyName: "setting.defaultresheight", bCreate: false);
      if ( v5 != nullptr )
        config->m_VideoMode.m_Height = KeyValues::GetInt(this: v5, keyName: nullptr, defaultValue: 0);
      v6 = KeyValues::FindKey(this: v3, keyName: "setting.fullscreen", bCreate: false);
      if ( v6 != nullptr )
      {
        if ( KeyValues::GetInt(this: v6, keyName: nullptr, defaultValue: 0) != 0 )
          config->m_Flags &= ~1u;
        else
          config->m_Flags |= 1u;
      }
      v7 = KeyValues::FindKey(this: v3, keyName: "setting.nowindowborder", bCreate: false);
      if ( v7 != nullptr )
      {
        if ( KeyValues::GetInt(this: v7, keyName: nullptr, defaultValue: 0) != 0 )
        {
          config->m_Flags |= 0x20000u;
          UpdateVideoConfigConVars(pConfigKeys: v3);
          KeyValues::deleteThis(this: v3);
          return;
        }
        config->m_Flags &= ~0x20000u;
      }
      UpdateVideoConfigConVars(pConfigKeys: v3);
      KeyValues::deleteThis(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5600
// Name: OverrideMaterialSystemConfigFromCommandLine
// Source: json
//------------------------------------------------------------------------------
void __usercall OverrideMaterialSystemConfigFromCommandLine(MaterialSystem_Config_t *config@<esi>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-sw") != 0
    || (v2 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-startwindowed") != 0)
    || (v3 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-windowed") != 0)
    || (v4 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-window") != 0) )
  {
    config->m_Flags |= 1u;
  }
  else
  {
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-full") != 0
      || (v6 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-fullscreen") != 0) )
    {
      config->m_Flags &= ~1u;
    }
  }
  v7 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-width") != 0
    || (v8 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-w") != 0) )
  {
    v9 = _CommandLine();
    config->m_VideoMode.m_Width = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 28))(
                                    a1: v9,
                                    a2: "-width",
                                    a3: config->m_VideoMode.m_Width);
    v10 = _CommandLine();
    config->m_VideoMode.m_Width = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v10 + 28))(
                                    a1: v10,
                                    a2: "-w",
                                    a3: config->m_VideoMode.m_Width);
    v11 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-height") == 0 )
    {
      v12 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-h") == 0 )
        config->m_VideoMode.m_Height = 3 * config->m_VideoMode.m_Width / 4;
    }
  }
  v13 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-height") != 0
    || (v14 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-h") != 0) )
  {
    v15 = _CommandLine();
    config->m_VideoMode.m_Height = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 28))(
                                     a1: v15,
                                     a2: "-height",
                                     a3: config->m_VideoMode.m_Height);
    v16 = _CommandLine();
    config->m_VideoMode.m_Height = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v16 + 28))(
                                     a1: v16,
                                     a2: "-h",
                                     a3: config->m_VideoMode.m_Height);
  }
  v17 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v17 + 40))(a1: v17, a2: "-resizing") != 0 )
  {
    v18 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v18 + 12))(a1: v18, a2: "-resizing", a3: 0) != 0 )
      config->m_Flags |= 2u;
    else
      config->m_Flags &= ~2u;
  }
  v19 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v19 + 40))(a1: v19, a2: "-mat_vsync") != 0 )
  {
    v20 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v20 + 28))(a1: v20, a2: "-mat_vsync", a3: 1) != 0 )
      config->m_Flags &= ~8u;
    else
      config->m_Flags |= 8u;
  }
  v21 = _CommandLine();
  config->m_nAASamples = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v21 + 28))(
                           a1: v21,
                           a2: "-mat_antialias",
                           a3: config->m_nAASamples);
  v22 = _CommandLine();
  config->m_nAAQuality = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v22 + 28))(
                           a1: v22,
                           a2: "-mat_aaquality",
                           a3: config->m_nAAQuality);
  v23 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v23 + 40))(a1: v23, a2: "-safe") != 0 )
  {
    config->m_Flags |= 1u;
    config->m_VideoMode.m_Width = 640;
    config->m_VideoMode.m_Height = 480;
    config->m_VideoMode.m_RefreshRate = 0;
    config->m_nAASamples = 0;
    config->m_nAAQuality = 0;
    config->m_bWantTripleBuffered = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5840
// Name: mat_setvideomode
// Source: json
//------------------------------------------------------------------------------
void __usercall mat_setvideomode(int a1@<ebx>, int a2@<edi>, const CCommand *args)
{
  const char *v3; // eax
  int v4; // ebx
  const char *v5; // eax
  int v6; // edi
  const char *v7; // eax
  const char *v8; // esi

  if ( args->m_nArgc >= 4 )
  {
    v3 = defaultValue;
    if ( args->m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = V_atoi(str: v3);
    v5 = defaultValue;
    if ( args->m_nArgc > 2 )
      v5 = args->m_ppArgv[2];
    v6 = V_atoi(str: v5);
    v7 = defaultValue;
    if ( args->m_nArgc > 3 )
      v7 = args->m_ppArgv[3];
    V_atoi(str: v7);
    ((void (__thiscall *)(IVideoMode *, int, int))videomode->NoWindowBorder)(a1: videomode, a2, a3: a1);
    if ( args->m_nArgc >= 5 )
    {
      if ( args->m_nArgc > 4 )
        v8 = args->m_ppArgv[4];
      else
        v8 = defaultValue;
      V_atoi(str: v8);
    }
    ((void (__thiscall *)(IVideoMode *, int, int))videomode->SetMode)(a1: videomode, a2: v4, a3: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5910
// Name: mat_savechanges
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_savechanges()
{
  int v0; // eax
  int m_Width; // esi
  AspectRatioMode_t ScreenAspectMode; // eax
  int v3; // edx
  bool v4; // [esp-8h] [ebp-Ch]
  bool v5; // [esp-4h] [ebp-8h]

  v0 = _CommandLine();
  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 16))(a1: v0, a2: "-safe");
  UpdateMaterialSystemConfig();
  m_Width = g_pMaterialSystemConfig->m_VideoMode.m_Width;
  v5 = (g_pMaterialSystemConfig->m_Flags & 0x20000) != 0;
  v4 = (g_pMaterialSystemConfig->m_Flags & 1) == 0;
  ScreenAspectMode = GetScreenAspectMode(
                       width: g_pMaterialSystemConfig->m_VideoMode.m_Width,
                       height: g_pMaterialSystemConfig->m_VideoMode.m_Height);
  UpdateCurrentVideoConfig(
    nWidth: m_Width,
    nHeight: v3,
    nAspectRatioMode: ScreenAspectMode,
    bFullscreen: v4,
    bNoWindow: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100E5970
// Name: mat_debug
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_debug(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    materials->ToggleDebugMaterial(this: materials, a2: args->m_ppArgv[1]);
  else
    ConMsg(a1: "usage: mat_debug [ <material name> ]\n");
}

//------------------------------------------------------------------------------
// Address: 0x100E59B0
// Name: mat_suppress
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_suppress(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    materials->ToggleSuppressMaterial(this: materials, a2: args->m_ppArgv[1]);
  else
    ConMsg(a1: "usage: mat_suppress [ <material name> ]\n");
}

//------------------------------------------------------------------------------
// Address: 0x100E59F0
// Name: bool TangentSpaceSurfaceSetup(struct msurface2_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TangentSpaceSurfaceSetup(msurface2_t *surfID, Vector *tVect)
{
  mtexinfo_t *texinfo; // eax
  int v3; // ecx
  mtexinfo_t *v4; // eax
  double x; // st7
  int v6; // eax
  Vector sVect; // [esp+8h] [ebp-Ch] BYREF

  texinfo = host_state.worldbrush->texinfo;
  v3 = *((unsigned __int16 *)surfID + 11) >> 1;
  sVect.x = texinfo[*((unsigned __int16 *)surfID + 11) >> 1].textureVecsTexelsPerWorldUnits[0].x;
  sVect.y = texinfo[v3].textureVecsTexelsPerWorldUnits[0].y;
  sVect.z = texinfo[v3].textureVecsTexelsPerWorldUnits[0].z;
  v4 = host_state.worldbrush->texinfo;
  x = v4[v3].textureVecsTexelsPerWorldUnits[1].x;
  v6 = (int)&v4[v3].textureVecsTexelsPerWorldUnits[1];
  tVect->x = x;
  tVect->y = *(float *)(v6 + 4);
  tVect->z = *(float *)(v6 + 8);
  VectorNormalize(vec: &sVect);
  VectorNormalize(vec: tVect);
  return (float)((float)((float)(surfID->plane->normal.y
                               * (float)((float)(tVect->x * sVect.z) - (float)(tVect->z * sVect.x)))
                       + (float)(surfID->plane->normal.x
                               * (float)((float)(tVect->z * sVect.y) - (float)(tVect->y * sVect.z))))
               + (float)(surfID->plane->normal.z * (float)((float)(tVect->y * sVect.x) - (float)(tVect->x * sVect.y)))) > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E5AE0
// Name: void SurfComputeTextureCoordinate(struct msurface2_t __near *,class Vector const __near &,float restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SurfComputeTextureCoordinate(msurface2_t *surfID, const Vector *vec, float *pUV)
{
  mtexinfo_t *v3; // esi
  float v4; // xmm1_4
  float u; // [esp+10h] [ebp+8h]
  float ua; // [esp+10h] [ebp+8h]
  float v; // [esp+14h] [ebp+Ch]

  v3 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  u = (float)((float)((float)(v3->textureVecsTexelsPerWorldUnits[0].y * vec->y)
                    + (float)(v3->textureVecsTexelsPerWorldUnits[0].x * vec->x))
            + (float)(v3->textureVecsTexelsPerWorldUnits[0].z * vec->z))
    + v3->textureVecsTexelsPerWorldUnits[0].w;
  ua = u / (float)v3->material->GetMappingWidth(this: v3->material);
  v = (float)((float)((float)(v3->textureVecsTexelsPerWorldUnits[1].y * vec->y)
                    + (float)(vec->x * v3->textureVecsTexelsPerWorldUnits[1].x))
            + (float)(v3->textureVecsTexelsPerWorldUnits[1].z * vec->z))
    + v3->textureVecsTexelsPerWorldUnits[1].w;
  v4 = (float)v3->material->GetMappingHeight(this: v3->material);
  *pUV = ua;
  pUV[1] = v / v4;
}

//------------------------------------------------------------------------------
// Address: 0x100E5BB0
// Name: void SurfComputeLightmapCoordinate(struct SurfaceCtx_t const __near &,struct msurface2_t __near *,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SurfComputeLightmapCoordinate(
        const SurfaceCtx_t *ctx,
        msurface2_t *surfID,
        const Vector *vec,
        Vector2D *uv)
{
  Vector2D *v4; // eax
  int x_low; // xmm0_4
  float y; // xmm0_4
  float v7; // xmm0_4
  float *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4

  if ( (surfID->flags & 1) != 0 )
  {
    v4 = uv;
    uv->y = 0.5;
    uv->x = 0.5;
LABEL_3:
    x_low = LODWORD(v4->x);
    goto LABEL_4;
  }
  v4 = uv;
  if ( *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) != 0 )
  {
    v8 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
    v9 = (float)((float)((float)(v8[9] * vec->y) + (float)(v8[8] * vec->x)) + (float)(v8[10] * vec->z)) + v8[11];
    uv->x = v9;
    uv->x = (float)(v9
                  - (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
          + 0.5;
    v10 = (float)((float)((float)(v8[13] * vec->y) + (float)(vec->x * v8[12])) + (float)(v8[14] * vec->z)) + v8[15];
    uv->y = v10;
    uv->y = (float)(v10
                  - (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
          + 0.5;
    uv->x = ctx->m_Scale.x * uv->x;
    uv->y = ctx->m_Scale.y * uv->y;
    uv->x = ctx->m_Offset.x + uv->x;
    v7 = ctx->m_Offset.y + uv->y;
  }
  else
  {
    v7 = ctx->m_Offset.y + (float)(ctx->m_Scale.y * 0.5);
    uv->x = ctx->m_Offset.x + (float)(ctx->m_Scale.x * 0.5);
  }
  uv->y = v7;
  if ( uv->x >= 0.0 )
  {
    if ( uv->x <= 1.0 )
      goto LABEL_3;
    x_low = 1065353216;
  }
  else
  {
    x_low = 0;
  }
LABEL_4:
  LODWORD(v4->x) = x_low;
  y = v4->y;
  if ( y >= 0.0 )
  {
    if ( y > 1.0 )
      y = 1.0;
    v4->y = y;
  }
  else
  {
    v4->y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5DA0
// Name: void SurfSetupSurfaceContext(struct SurfaceCtx_t __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SurfSetupSurfaceContext(SurfaceCtx_t *ctx, msurface2_t *surfID)
{
  int v2; // eax
  __m128i v3; // xmm2
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  IMaterialSystem_vtbl *v7; // [esp+Ch] [ebp-4h]

  v7 = materials->__vftable;
  v2 = SortInfoToLightmapPage(sortID: surfID->materialSortID);
  v7->GetLightmapPageSize(this: materials, a2: v2, a3: ctx->m_LightmapPageSize, a4: &ctx->m_LightmapPageSize[1]);
  v3 = _mm_cvtsi32_si128(ctx->m_LightmapPageSize[0]);
  v4 = (float)ctx->m_LightmapPageSize[1];
  ctx->m_LightmapSize[0] = *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                         + 1;
  v5 = _mm_cvtepi32_ps(v3).m128_f32[0];
  ctx->m_LightmapSize[1] = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                         + 1;
  ctx->m_Scale.y = 1.0 / v4;
  ctx->m_Scale.x = 1.0 / v5;
  ctx->m_Offset.x = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                  * (float)(1.0 / v5);
  ctx->m_Offset.y = (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                  * (float)(1.0 / v4);
  v6 = 0.0;
  if ( v5 != 0.0 )
    v6 = (float)ctx->m_LightmapSize[0] / v5;
  ctx->m_BumpSTexCoordOffset = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E5EC0
// Name: void OverrideMaterialSystemConfig(struct MaterialSystem_Config_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverrideMaterialSystemConfig(MaterialSystem_Config_t *config)
{
  const char *ModDirectory; // esi
  ConVarRef mat_supportflashlight; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &mat_supportflashlight, pName: "mat_supportflashlight");
  if ( mat_supportflashlight.m_pConVarState->m_Value.m_nValue == -1 )
  {
    ModDirectory = COM_GetModDirectory();
    if ( _V_stricmp(s1: ModDirectory, s2: "portal") != 0 && _V_stricmp(s1: ModDirectory, s2: "tf") != 0 )
      mat_supportflashlight.m_pConVar->SetValue_2(this: mat_supportflashlight.m_pConVar, a2: 1);
    else
      mat_supportflashlight.m_pConVar->SetValue_2(this: mat_supportflashlight.m_pConVar, a2: 0);
  }
  config->m_bSupportFlashlight = mat_supportflashlight.m_pConVarState->m_Value.m_nValue != 0;
  if ( materials->OverrideConfig(this: materials, a2: config, a3: false) )
    s_bConfigLightingChanged = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E5F50
// Name: void InitMaterialSystemConfig(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMaterialSystemConfig(bool bInEditMode)
{
  const MaterialSystem_Config_t *v1; // eax
  int v2; // eax
  int m_nValue; // eax
  MaterialSystem_Config_t config; // [esp+0h] [ebp-64h] BYREF

  v1 = materials->GetCurrentConfigForVideoCard(this: materials);
  g_pMaterialSystemConfig = v1;
  if ( v1 == nullptr )
  {
    Sys_Error(error: "Could not get the material system config record!");
    v1 = g_pMaterialSystemConfig;
  }
  if ( !bInEditMode )
  {
    config = *v1;
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-autoconfig") != 0 )
      ResetVideoConfigToDefaults(pConfigKeys: nullptr);
    ReadMaterialSystemConfigFromRegistry(&config);
    OverrideMaterialSystemConfigFromCommandLine(&config);
    OverrideMaterialSystemConfig(&config);
    if ( mat_hdr_level.m_pParent != nullptr )
      m_nValue = mat_hdr_level.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    g_pMaterialSystemHardwareConfig->SetHDREnabled(this: g_pMaterialSystemHardwareConfig, a2: m_nValue >= 2);
    UpdateMaterialSystemConfig();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6010
// Name: void GetMaterialSystemConfigForBenchmarkUpload(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialSystemConfigForBenchmarkUpload(KeyValues *dataToUpload)
{
  IMaterialSystem_vtbl *v1; // esi
  int v2; // eax
  int Ram; // eax
  int CPUInformation; // edi
  int m_nValue; // eax
  int v6; // eax
  MaterialAdapterInfo_t driverInfo; // [esp+8h] [ebp-224h] BYREF

  v1 = materials->__vftable;
  v2 = ((int (__thiscall *)(IMaterialSystem *, MaterialAdapterInfo_t *))materials->GetCurrentAdapter)(
         a1: materials,
         a2: &driverInfo);
  ((void (__thiscall *)(IMaterialSystem *, int))v1->GetDisplayAdapterInfo)(a1: materials, a2: v2);
  KeyValues::SetInt(this: dataToUpload, keyName: "vendorID", value: driverInfo.m_VendorID);
  KeyValues::SetInt(this: dataToUpload, keyName: "deviceID", value: driverInfo.m_DeviceID);
  Ram = GetRam();
  KeyValues::SetInt(this: dataToUpload, keyName: "ram", value: Ram);
  CPUInformation = _GetCPUInformation();
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "cpu_speed",
    value: (int)((double)*(__int64 *)(CPUInformation + 8) * 0.000001));
  KeyValues::SetString(this: dataToUpload, keyName: "cpu", value: *(const char **)(CPUInformation + 16));
  KeyValues::SetInt(this: dataToUpload, keyName: "width", value: g_pMaterialSystemConfig->m_VideoMode.m_Width);
  KeyValues::SetInt(this: dataToUpload, keyName: "height", value: g_pMaterialSystemConfig->m_VideoMode.m_Height);
  KeyValues::SetInt(this: dataToUpload, keyName: "AASamples", value: g_pMaterialSystemConfig->m_nAASamples);
  KeyValues::SetInt(this: dataToUpload, keyName: "AAQuality", value: g_pMaterialSystemConfig->m_nAAQuality);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "TripleBuffered",
    value: g_pMaterialSystemConfig->m_bWantTripleBuffered);
  KeyValues::SetInt(this: dataToUpload, keyName: "AnisoLevel", value: g_pMaterialSystemConfig->m_nForceAnisotropicLevel);
  KeyValues::SetInt(this: dataToUpload, keyName: "SkipMipLevels", value: g_pMaterialSystemConfig->skipMipLevels);
  KeyValues::SetInt(this: dataToUpload, keyName: "DXLevel", value: g_pMaterialSystemConfig->dxSupportLevel);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "ShadowDepthTexture",
    value: g_pMaterialSystemConfig->m_bShadowDepthTexture);
  KeyValues::SetInt(this: dataToUpload, keyName: "MotionBlur", value: g_pMaterialSystemConfig->m_bMotionBlur);
  KeyValues::SetInt(this: dataToUpload, keyName: "Windowed", value: g_pMaterialSystemConfig->m_Flags & 1);
  KeyValues::SetInt(this: dataToUpload, keyName: "NoWaitForVSync", value: (g_pMaterialSystemConfig->m_Flags & 8) != 0);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "DisableSpecular",
    value: (g_pMaterialSystemConfig->m_Flags & 0x80) != 0);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "DisableBumpmapping",
    value: (g_pMaterialSystemConfig->m_Flags & 0x100) != 0);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "EnableParallaxMapping",
    value: (g_pMaterialSystemConfig->m_Flags & 0x200) != 0);
  KeyValues::SetInt(this: dataToUpload, keyName: "ZPrefill", value: (g_pMaterialSystemConfig->m_Flags & 0x400) != 0);
  if ( r_shadowrendertotexture.m_pParent != nullptr )
    m_nValue = r_shadowrendertotexture.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  KeyValues::SetInt(this: dataToUpload, keyName: "RenderToTextureShadows", value: m_nValue != 0);
  if ( r_flashlightdepthtexture.m_pParent != nullptr )
    v6 = r_flashlightdepthtexture.m_pParent->m_Value.m_nValue;
  else
    v6 = 0;
  KeyValues::SetInt(this: dataToUpload, keyName: "FlashlightDepthTexture", value: v6 != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100E6280
// Name: void PrintMaterialSystemConfig(struct MaterialSystem_Config_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintMaterialSystemConfig(const MaterialSystem_Config_t *config)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax

  _Warning(a1: "width: %d\n", config->m_VideoMode.m_Width);
  _Warning(a1: "height: %d\n", config->m_VideoMode.m_Height);
  _Warning(a1: "m_nForceAnisotropicLevel: %d\n", config->m_nForceAnisotropicLevel);
  _Warning(a1: "aasamples: %d\n", config->m_nAASamples);
  _Warning(a1: "aaquality: %d\n", config->m_nAAQuality);
  v1 = "true";
  if ( !config->m_bWantTripleBuffered )
    v1 = "false";
  _Warning(a1: "tripleBuffered: %s\n", v1);
  _Warning(a1: "skipMipLevels: %d\n", config->skipMipLevels);
  _Warning(a1: "dxSupportLevel: %d\n", config->dxSupportLevel);
  _Warning(a1: "monitorGamma: %f\n", config->m_fMonitorGamma);
  v2 = "true";
  if ( (config->m_Flags & 1) == 0 )
    v2 = "false";
  _Warning(a1: "MATSYS_VIDCFG_FLAGS_WINDOWED: %s\n", v2);
  v3 = "true";
  if ( SLOBYTE(config->m_Flags) >= 0 )
    v3 = "false";
  _Warning(a1: "MATSYS_VIDCFG_FLAGS_DISABLE_SPECULAR: %s\n", v3);
  v4 = "true";
  if ( (config->m_Flags & 0x200) == 0 )
    v4 = "false";
  _Warning(a1: "MATSYS_VIDCFG_FLAGS_ENABLE_PARALLAX_MAPPING: %s\n", v4);
  v5 = "true";
  if ( (config->m_Flags & 0x400) == 0 )
    v5 = "false";
  _Warning(a1: "MATSYS_VIDCFG_FLAGS_USE_Z_PREFILL: %s\n", v5);
  if ( r_shadowrendertotexture.m_pParent == nullptr
    || (v6 = "true", r_shadowrendertotexture.m_pParent->m_Value.m_nValue == 0) )
  {
    v6 = "false";
  }
  _Warning(a1: "r_shadowrendertotexture: %s\n", v6);
  v7 = "true";
  if ( !config->m_bMotionBlur )
    v7 = "false";
  _Warning(a1: "motionblur: %s\n", v7);
  v8 = "true";
  if ( !config->m_bShadowDepthTexture )
    v8 = "false";
  _Warning(a1: "shadowdepthtexture: %s\n", v8);
}

//------------------------------------------------------------------------------
// Address: 0x100E63E0
// Name: mat_configcurrent
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_configcurrent()
{
  const MaterialSystem_Config_t *v0; // eax

  v0 = materials->GetCurrentConfigForVideoCard(this: materials);
  PrintMaterialSystemConfig(config: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100E6400
// Name: InitDebugMaterials
// Source: json
//------------------------------------------------------------------------------
int __usercall InitDebugMaterials@<eax>(int a1@<esi>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // esi

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: InitDebugMaterials\n");
  g_materialEmpty = GL_LoadMaterial(pName: "debug/debugempty", pTextureGroupName: "Other textures", bPrecache: false);
  g_materialWireframe = GL_LoadMaterial(
                          pName: "debug/debugwireframe",
                          pTextureGroupName: "Other textures",
                          bPrecache: false);
  g_materialTranslucentSingleColor = GL_LoadMaterial(
                                       pName: "debug/debugtranslucentsinglecolor",
                                       pTextureGroupName: "Other textures",
                                       bPrecache: false);
  g_materialTranslucentVertexColor = GL_LoadMaterial(
                                       pName: "debug/debugtranslucentvertexcolor",
                                       pTextureGroupName: "Other textures",
                                       bPrecache: false);
  g_materialWorldWireframe = GL_LoadMaterial(
                               pName: "debug/debugworldwireframe",
                               pTextureGroupName: "Other textures",
                               bPrecache: false);
  g_materialWorldWireframeZBuffer = GL_LoadMaterial(
                                      pName: "debug/debugworldwireframezbuffer",
                                      pTextureGroupName: "Other textures",
                                      bPrecache: false);
  g_materialBrushWireframe = GL_LoadMaterial(
                               pName: "debug/debugbrushwireframe",
                               pTextureGroupName: "Other textures",
                               bPrecache: false);
  g_materialDecalWireframe = GL_LoadMaterial(
                               pName: "debug/debugdecalwireframe",
                               pTextureGroupName: "Other textures",
                               bPrecache: false);
  g_materialDebugLightmap = GL_LoadMaterial(
                              pName: "debug/debuglightmap",
                              pTextureGroupName: "Other textures",
                              bPrecache: false);
  g_materialDebugLightmapZBuffer = GL_LoadMaterial(
                                     pName: "debug/debuglightmapzbuffer",
                                     pTextureGroupName: "Other textures",
                                     bPrecache: false);
  g_materialDebugLuxels = GL_LoadMaterial(
                            pName: "debug/debugluxels",
                            pTextureGroupName: "Other textures",
                            bPrecache: false);
  g_materialLeafVisWireframe = GL_LoadMaterial(
                                 pName: "debug/debugleafviswireframe",
                                 pTextureGroupName: "Other textures",
                                 bPrecache: false);
  g_pMaterialWireframeVertexColor = GL_LoadMaterial(
                                      pName: "debug/debugwireframevertexcolor",
                                      pTextureGroupName: "Other textures",
                                      bPrecache: false);
  g_pMaterialWireframeVertexColorIgnoreZ = GL_LoadMaterial(
                                             pName: "debug/debugwireframevertexcolorignorez",
                                             pTextureGroupName: "Other textures",
                                             bPrecache: false);
  g_pMaterialLightSprite = GL_LoadMaterial(
                             pName: "engine/lightsprite",
                             pTextureGroupName: "Other textures",
                             bPrecache: false);
  g_pMaterialShadowBuild = GL_LoadMaterial(
                             pName: "engine/shadowbuild",
                             pTextureGroupName: "Other textures",
                             bPrecache: false);
  g_pMaterialMRMWireframe = GL_LoadMaterial(
                              pName: "debug/debugmrmwireframe",
                              pTextureGroupName: "Other textures",
                              bPrecache: false);
  g_pMaterialDebugFlat = GL_LoadMaterial(
                           pName: "debug/debugdrawflattriangles",
                           pTextureGroupName: "Other textures",
                           bPrecache: false);
  g_pMaterialAmbientCube = GL_LoadMaterial(
                             pName: "debug/debugambientcube",
                             pTextureGroupName: "Other textures",
                             bPrecache: false);
  g_pMaterialWriteZ = GL_LoadMaterial(pName: "engine/writez", pTextureGroupName: "Other textures", bPrecache: false);
  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v2 = KeyValues::KeyValues(this: v1, setName: "DepthWrite");
  else
    v2 = nullptr;
  KeyValues::SetInt(this: v2, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v2, keyName: "$alphatest", value: 0);
  KeyValues::SetInt(this: v2, keyName: "$nocull", value: 0);
  g_pMaterialDepthWrite[0][0] = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, const char *, KeyValues *, int))g_pMaterialSystem->FindProceduralMaterial)(
                                               a1: g_pMaterialSystem,
                                               a2: "__DepthWrite00",
                                               a3: "Other textures",
                                               a4: v2,
                                               a5: a1);
  g_pMaterialDepthWrite[0][0]->IncrementReferenceCount(this: g_pMaterialDepthWrite[0][0]);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "DepthWrite");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v4, keyName: "$alphatest", value: 0);
  KeyValues::SetInt(this: v4, keyName: "$nocull", value: 1);
  dword_105F3008 = (int)g_pMaterialSystem->FindProceduralMaterial(
                          this: g_pMaterialSystem,
                          a2: "__DepthWrite01",
                          a3: "Other textures",
                          a4: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_105F3008 + 48))(a1: dword_105F3008);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "DepthWrite");
  else
    v6 = nullptr;
  KeyValues::SetInt(this: v6, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v6, keyName: "$alphatest", value: 1);
  KeyValues::SetInt(this: v6, keyName: "$nocull", value: 0);
  dword_105F300C = (int)g_pMaterialSystem->FindProceduralMaterial(
                          this: g_pMaterialSystem,
                          a2: "__DepthWrite10",
                          a3: "Other textures",
                          a4: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_105F300C + 48))(a1: dword_105F300C);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "DepthWrite");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$alphatest", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$nocull", value: 1);
  dword_105F3010 = ((int (__thiscall *)(IMaterialSystem *, const char *, const char *))g_pMaterialSystem->FindProceduralMaterial)(
                     a1: g_pMaterialSystem,
                     a2: "__DepthWrite11",
                     a3: "Other textures");
  return (*(int (__thiscall **)(int))(*(_DWORD *)dword_105F3010 + 48))(a1: dword_105F3010);
}

//------------------------------------------------------------------------------
// Address: 0x100E67B0
// Name: ShutdownDebugMaterials
// Source: json
//------------------------------------------------------------------------------
void ShutdownDebugMaterials()
{
  IMaterial **v0; // esi
  int i; // edi

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: ShutdownDebugMaterials\n");
  GL_UnloadMaterial(pMaterial: g_materialEmpty);
  GL_UnloadMaterial(pMaterial: g_pMaterialLightSprite);
  GL_UnloadMaterial(pMaterial: g_pMaterialWireframeVertexColor);
  GL_UnloadMaterial(pMaterial: g_pMaterialWireframeVertexColorIgnoreZ);
  GL_UnloadMaterial(pMaterial: g_materialLeafVisWireframe);
  GL_UnloadMaterial(pMaterial: g_materialDebugLuxels);
  GL_UnloadMaterial(pMaterial: g_materialDebugLightmapZBuffer);
  GL_UnloadMaterial(pMaterial: g_materialDebugLightmap);
  GL_UnloadMaterial(pMaterial: g_materialDecalWireframe);
  GL_UnloadMaterial(pMaterial: g_materialBrushWireframe);
  GL_UnloadMaterial(pMaterial: g_materialWorldWireframeZBuffer);
  GL_UnloadMaterial(pMaterial: g_materialWorldWireframe);
  GL_UnloadMaterial(pMaterial: g_materialTranslucentSingleColor);
  GL_UnloadMaterial(pMaterial: g_materialTranslucentVertexColor);
  GL_UnloadMaterial(pMaterial: g_materialWireframe);
  GL_UnloadMaterial(pMaterial: g_pMaterialShadowBuild);
  GL_UnloadMaterial(pMaterial: g_pMaterialMRMWireframe);
  GL_UnloadMaterial(pMaterial: g_pMaterialWriteZ);
  GL_UnloadMaterial(pMaterial: g_pMaterialAmbientCube);
  GL_UnloadMaterial(pMaterial: g_pMaterialDebugFlat);
  v0 = g_pMaterialDepthWrite[0];
  do
  {
    for ( i = 2; i != 0; --i )
    {
      if ( *v0 != nullptr )
        (*v0)->DecrementReferenceCount(this: *v0);
      *v0++ = nullptr;
    }
  }
  while ( (int)v0 < (int)&g_pMaterialDebugFlat );
}

//------------------------------------------------------------------------------
// Address: 0x100E68F0
// Name: void BuildMSurfaceVertexArrays(struct worldbrushdata_t __near *,struct msurface2_t __near *,class CMeshBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfaceVertexArrays(worldbrushdata_t *pBrushData, msurface2_t *surfID, CMeshBuilder *builder)
{
  mvertex_t *v4; // edi
  float *m_pCurrPosition; // eax
  mtexinfo_t *v6; // esi
  IMaterial *material; // ecx
  int (__thiscall *GetMappingWidth)(IMaterial *); // edx
  int v9; // eax
  float v10; // xmm0_4
  IMaterial *v11; // esi
  int (__thiscall *GetMappingHeight)(IMaterial *); // edx
  float v13; // xmm1_4
  float *v14; // eax
  float v15; // xmm0_4
  float x; // xmm0_4
  float *v17; // eax
  Vector *v18; // edi
  float *m_pCurrNormal; // eax
  float z; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float y; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float *v27; // eax
  SurfaceCtx_t ctx; // [esp+4h] [ebp-60h] BYREF
  Vector tVect; // [esp+28h] [ebp-3Ch] BYREF
  Vector tangentT; // [esp+34h] [ebp-30h] BYREF
  Vector tangentS; // [esp+40h] [ebp-24h] BYREF
  Vector2D uv; // [esp+4Ch] [ebp-18h] BYREF
  int vertCount; // [esp+54h] [ebp-10h]
  float v34; // [esp+58h] [ebp-Ch]
  float v35; // [esp+5Ch] [ebp-8h]
  int i; // [esp+60h] [ebp-4h]
  bool negate_3; // [esp+73h] [ebp+Fh]

  SurfSetupSurfaceContext(&ctx, surfID);
  negate_3 = false;
  if ( (surfID->flags & 0x100) != 0 )
    negate_3 = TangentSpaceSurfaceSetup(surfID, &tVect);
  vertCount = HIBYTE(surfID->flags);
  i = 0;
  if ( vertCount != 0 )
  {
    do
    {
      v4 = &pBrushData->vertexes[pBrushData->vertindices[i + surfID->firstvertindex]];
      m_pCurrPosition = builder->m_VertexBuilder.m_pCurrPosition;
      *m_pCurrPosition = v4->position.x;
      m_pCurrPosition[1] = v4->position.y;
      m_pCurrPosition[2] = v4->position.z;
      v6 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
      material = v6->material;
      GetMappingWidth = material->GetMappingWidth;
      v35 = (float)((float)((float)(v6->textureVecsTexelsPerWorldUnits[0].y * v4->position.y)
                          + (float)(v6->textureVecsTexelsPerWorldUnits[0].x * v4->position.x))
                  + (float)(v6->textureVecsTexelsPerWorldUnits[0].z * v4->position.z))
          + v6->textureVecsTexelsPerWorldUnits[0].w;
      v9 = GetMappingWidth(this: material);
      v10 = (float)((float)((float)(v6->textureVecsTexelsPerWorldUnits[1].y * v4->position.y)
                          + (float)(v6->textureVecsTexelsPerWorldUnits[1].x * v4->position.x))
                  + (float)(v6->textureVecsTexelsPerWorldUnits[1].z * v4->position.z))
          + v6->textureVecsTexelsPerWorldUnits[1].w;
      v11 = v6->material;
      GetMappingHeight = v11->GetMappingHeight;
      v35 = v35 / (float)v9;
      v34 = v10;
      uv.x = v35;
      v13 = (float)GetMappingHeight(this: v11);
      v14 = builder->m_VertexBuilder.m_pCurrTexCoord[0];
      v15 = v34 / v13;
      *v14 = v35;
      v14[1] = v15;
      uv.y = v15;
      SurfComputeLightmapCoordinate(&ctx, surfID, vec: &v4->position, &uv);
      x = uv.x;
      *(Vector2D *)builder->m_VertexBuilder.m_pCurrTexCoord[1] = uv;
      if ( (surfID->flags & 8) != 0 )
      {
        if ( (float)((float)(ctx.m_BumpSTexCoordOffset * 3.0) + x) > 1.00001 )
          SurfComputeLightmapCoordinate(&ctx, surfID, vec: &v4->position, &uv);
        v17 = builder->m_VertexBuilder.m_pCurrTexCoord[2];
        *v17 = ctx.m_BumpSTexCoordOffset;
      }
      else
      {
        v17 = builder->m_VertexBuilder.m_pCurrTexCoord[2];
        *v17 = 0.0;
      }
      v17[1] = 0.0;
      v18 = &pBrushData->vertnormals[pBrushData->vertnormalindices[i
                                                                 + host_state.worldbrush->surfacenormals[surfID - host_state.worldbrush->surfaces2].firstvertnormal]];
      m_pCurrNormal = builder->m_VertexBuilder.m_pCurrNormal;
      *m_pCurrNormal = v18->x;
      m_pCurrNormal[1] = v18->y;
      m_pCurrNormal[2] = v18->z;
      if ( (surfID->flags & 0x100) != 0 )
      {
        z = v18->z;
        v21 = v18->y * tVect.x;
        tangentS.x = (float)(v18->y * tVect.z) - (float)(z * tVect.y);
        v22 = (float)(v18->x * tVect.y) - v21;
        tangentS.y = (float)(z * tVect.x) - (float)(v18->x * tVect.z);
        tangentS.z = v22;
        VectorNormalize(vec: &tangentS);
        y = v18->y;
        v24 = v18->z * tangentS.x;
        tangentT.x = (float)(v18->z * tangentS.y) - (float)(y * tangentS.z);
        v25 = v18->x * tangentS.y;
        tangentT.y = (float)(v18->x * tangentS.z) - v24;
        tangentT.z = (float)(y * tangentS.x) - v25;
        VectorNormalize(vec: &tangentT);
        v26 = tangentS.x;
        if ( negate_3 )
        {
          tangentS.y = tangentS.y * -1.0;
          v26 = tangentS.x * -1.0;
          tangentS.z = tangentS.z * -1.0;
        }
        v27 = (float *)((char *)builder->m_VertexBuilder.m_pTangentS
                      + builder->m_VertexBuilder.m_nCurrentVertex * builder->m_VertexBuilder.m_VertexSize_TangentS);
        *v27 = v26;
        v27[1] = tangentS.y;
        v27[2] = tangentS.z;
        *(Vector *)((char *)builder->m_VertexBuilder.m_pTangentT
                  + builder->m_VertexBuilder.m_nCurrentVertex * builder->m_VertexBuilder.m_VertexSize_TangentT) = tangentT;
      }
      if ( (surfID->flags & 0x800) != 0
        || (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].texinfoFlags & 1) == 0 )
      {
        *(_DWORD *)builder->m_VertexBuilder.m_pCurrColor = flatColor_0[2]
                                                         | ((flatColor_0[1]
                                                           | ((flatColor_0[0] | (flatColor_0[3] << 8)) << 8)) << 8);
      }
      else
      {
        *(_DWORD *)builder->m_VertexBuilder.m_pCurrColor = flatColorNoAlpha_0[2]
                                                         | ((flatColorNoAlpha_0[1]
                                                           | ((flatColorNoAlpha_0[0] | (flatColorNoAlpha_0[3] << 8)) << 8)) << 8);
      }
      CVertexBuilder::AdvanceVertex(this: &builder->m_VertexBuilder);
      ++i;
    }
    while ( i < vertCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6D10
// Name: void InitWellKnownRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitWellKnownRenderTargets(int a1@<esi>)
{
  ITexture *v1; // eax
  ITexture *v2; // eax
  ITexture *QuarterSizedFBTexture; // eax
  ITexture *v4; // eax
  ITexture *TeenyFBTexture; // eax
  ITexture *v6; // eax
  ITexture *v7; // eax
  IMaterialSystem_vtbl *v8; // esi
  int v9; // eax
  ITexture *v10; // eax
  IMaterialSystem_vtbl *v11; // esi
  int v12; // eax
  ITexture *v13; // eax
  ITexture *WaterReflectionTexture; // eax
  int v15; // eax
  int v16; // eax
  ITexture *v17; // eax
  ITexture *CameraTexture; // eax
  IMatRenderContext *v19; // eax
  IMatRenderContext *v20; // esi
  char dest[256]; // [esp+0h] [ebp-100h] BYREF

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: InitWellKnownRenderTargets\n");
  materials->BeginRenderTargetAllocation(this: materials);
  v1 = materials->CreateNamedRenderTargetTextureEx2(
         this: materials,
         a2: "_rt_PowerOfTwoFB",
         a3: 1024,
         a4: 1024,
         a5: 1,
         a6: 0,
         a7: 0,
         a8: 12,
         a9: 1);
  CTextureReference::Init(this: &g_PowerOfTwoFBTexture, pTexture: v1);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT )
  {
    v2 = materials->CreateNamedRenderTargetTextureEx2(
           this: materials,
           a2: "_rt_BuildCubemaps16bit",
           a3: 0,
           a4: 0,
           a5: 4,
           a6: 25,
           a7: 0,
           a8: 12,
           a9: 0);
    CTextureReference::Init(this: &g_BuildCubemaps16BitTexture, pTexture: v2);
  }
  QuarterSizedFBTexture = CreateQuarterSizedFBTexture(n: 0, iRenderTargetFlags: 0);
  CTextureReference::Init(this: &g_QuarterSizedFBTexture0, pTexture: QuarterSizedFBTexture);
  v4 = CreateQuarterSizedFBTexture(n: 1, iRenderTargetFlags: 0);
  CTextureReference::Init(this: &g_QuarterSizedFBTexture1, pTexture: v4);
  TeenyFBTexture = CreateTeenyFBTexture(n: 0);
  CTextureReference::Init(this: &g_TeenyFBTexture0, pTexture: TeenyFBTexture);
  v6 = CreateTeenyFBTexture(n: 1);
  CTextureReference::Init(this: &g_TeenyFBTexture1, pTexture: v6);
  v7 = CreateTeenyFBTexture(n: 2);
  CTextureReference::Init(this: &g_TeenyFBTexture2, pTexture: v7);
  _V_strcpy(dest, src: "_rt_FullFrameFB");
  v8 = materials->__vftable;
  v9 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int, int))materials->GetBackBufferFormat)(
         a1: materials,
         a2: 0,
         a3: 12,
         a4: 1,
         a5: a1);
  v10 = (ITexture *)((int (__thiscall *)(IMaterialSystem *, char *, int, int, int, int))v8->CreateNamedRenderTargetTextureEx2)(
                      a1: materials,
                      a2: dest,
                      a3: 1,
                      a4: 1,
                      a5: 4,
                      a6: v9);
  CTextureReference::Init(this: &g_FullFrameFBTexture0, pTexture: v10);
  sprintf(string: dest, format: "_rt_FullFrameFB%d", 1);
  v11 = materials->__vftable;
  v12 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int))materials->GetBackBufferFormat)(
          a1: materials,
          a2: 0,
          a3: 12,
          a4: 17);
  v13 = (ITexture *)((int (__thiscall *)(IMaterialSystem *, char *, int, int, int, int))v11->CreateNamedRenderTargetTextureEx2)(
                      a1: materials,
                      a2: dest,
                      a3: 1,
                      a4: 1,
                      a5: 4,
                      a6: v12);
  CTextureReference::Init(this: &g_FullFrameFBTexture1, pTexture: v13);
  materials->AddTextureAlias(this: materials, a2: "_rt_FullFrameDepth", a3: "_rt_PowerOfTwoFB");
  CTextureReference::Init(this: &g_FullFrameDepth, pTexture: nullptr);
  if ( g_pClientRenderTargets != nullptr )
  {
    g_pClientRenderTargets->InitClientRenderTargets(
      this: g_pClientRenderTargets,
      a2: materials,
      a3: g_pMaterialSystemHardwareConfig);
  }
  else
  {
    WaterReflectionTexture = CreateWaterReflectionTexture();
    CTextureReference::Init(this: &g_WaterReflectionTexture, pTexture: WaterReflectionTexture);
    v15 = _CommandLine();
    v16 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 28))(
            a1: v15,
            a2: "-reflectionTextureSize",
            a3: 1024);
    v17 = materials->CreateNamedRenderTargetTextureEx2(
            this: materials,
            a2: "_rt_WaterRefraction",
            a3: v16,
            a4: v16,
            a5: 2,
            a6: 0,
            a7: 0,
            a8: 12,
            a9: 1);
    CTextureReference::Init(this: &g_WaterRefractionTexture, pTexture: v17);
    CameraTexture = CreateCameraTexture();
    CTextureReference::Init(this: &g_CameraTexture, pTexture: CameraTexture);
  }
  materials->EndRenderTargetAllocation(this: materials);
  v19 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v20 = v19;
  if ( v19 != nullptr )
    v19->BeginRender(this: v19);
  ((void (__thiscall *)(IMatRenderContext *, ITexture *))v20->SetNonInteractiveTempFullscreenBuffer)(
    a1: v20,
    a2: g_FullFrameFBTexture0.m_pTexture);
  v20->EndRender(this: v20);
  v20->Release(this: v20);
}

//------------------------------------------------------------------------------
// Address: 0x100E6FE0
// Name: void ShutdownWellKnownRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ShutdownWellKnownRenderTargets(int a1@<esi>)
{
  int v1; // esi

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: ShutdownWellKnownRenderTargets\n");
  CTextureReference::Shutdown(this: &g_PowerOfTwoFBTexture, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_BuildCubemaps16BitTexture, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_QuarterSizedFBTexture0, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_QuarterSizedFBTexture1, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_QuarterSizedFBTexture2, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_QuarterSizedFBTexture3, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_TeenyFBTexture0, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_TeenyFBTexture1, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_TeenyFBTexture2, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_FullFrameFBTexture0, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_FullFrameFBTexture1, bDeleteIfUnReferenced: false);
  v1 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2: a1);
  if ( v1 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 704))(a1: v1, a2: 0);
  CTextureReference::Shutdown(this: &g_FullFrameDepth, bDeleteIfUnReferenced: false);
  materials->RemoveTextureAlias(this: materials, a2: "_rt_FullFrameDepth");
  if ( g_pClientRenderTargets != nullptr )
  {
    g_pClientRenderTargets->ShutdownClientRenderTargets(this: g_pClientRenderTargets);
  }
  else
  {
    CTextureReference::Shutdown(this: &g_WaterReflectionTexture, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &g_WaterRefractionTexture, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &g_CameraTexture, bDeleteIfUnReferenced: false);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 12))(a1: v1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 4))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100E7120
// Name: void ShutdownMaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ShutdownMaterialSystem(int a1@<esi>)
{
  ShutdownDebugMaterials();
  ShutdownWellKnownRenderTargets(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100E7130
// Name: VertexCountForSurfaceList
// Source: json
//------------------------------------------------------------------------------
int __fastcall VertexCountForSurfaceList(const surfacesortgroup_t *group, const CMSurfaceSortList *list)
{
  __int16 listHead; // cx
  int result; // eax
  materiallist_t *v4; // esi
  int v5; // edi
  int count; // edx
  int v7; // ebx
  int v8; // ecx
  unsigned int v9; // edx
  msurface2_t **v10; // ecx
  int _index; // [esp+0h] [ebp-Ch]
  materiallist_t *m_pMemory; // [esp+4h] [ebp-8h]
  int vertexCount; // [esp+8h] [ebp-4h]

  listHead = group->listHead;
  result = 0;
  vertexCount = 0;
  if ( listHead != -1 )
  {
    m_pMemory = list->m_list.m_Memory.m_pMemory;
    do
    {
      v4 = &m_pMemory[listHead];
      v5 = 0;
      count = v4->count;
      v7 = 0;
      v8 = 0;
      if ( count >= 2 )
      {
        v9 = ((unsigned int)(count - 2) >> 1) + 1;
        v10 = &v4->pSurfaces[1];
        _index = 2 * v9;
        do
        {
          v5 += HIBYTE((*(v10 - 1))->flags);
          v7 += HIBYTE((*v10)->flags);
          v10 += 2;
          --v9;
        }
        while ( v9 != 0 );
        result = vertexCount;
        v8 = _index;
      }
      if ( v8 < v4->count )
        result += HIBYTE(v4->pSurfaces[v8]->flags);
      listHead = v4->nextBlock;
      result += v5 + v7;
      vertexCount = result;
    }
    while ( LOWORD(v4->nextBlock) != 0xFFFF );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E71C0
// Name: void WorldStaticMeshDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldStaticMeshDestroy()
{
  IMatRenderContext *v0; // esi
  int v1; // edi
  int i; // ebx
  IMesh **m_pMemory; // eax

  v0 = materials->GetRenderContext(this: materials);
  v1 = 0;
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  for ( i = 0; i < g_Meshes.m_Size; ++v1 )
  {
    v0->DestroyStaticMesh(this: v0, a2: g_Meshes.m_Memory.m_pMemory[v1].pMesh);
    ++i;
  }
  m_pMemory = g_WorldStaticMeshes.m_Memory.m_pMemory;
  g_WorldStaticMeshes.m_Size = 0;
  if ( g_WorldStaticMeshes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorldStaticMeshes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorldStaticMeshes.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorldStaticMeshes.m_Memory.m_pMemory = nullptr;
    }
    g_WorldStaticMeshes.m_Memory.m_nAllocationCount = 0;
  }
  g_WorldStaticMeshes.m_pElements = m_pMemory;
  g_Meshes.m_Size = 0;
  if ( v0 != nullptr )
  {
    v0->EndRender(this: v0);
    v0->Release(this: v0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7270
// Name: void ReleaseMaterialSystemObjects(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseMaterialSystemObjects()
{
  DispInfo_ReleaseMaterialSystemObjects(pWorld: host_state.worldmodel);
  modelrender->ReleaseAllStaticPropColorData(this: modelrender);
  WorldStaticMeshDestroy();
  g_LostVideoMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E72A0
// Name: void MaterialSystem_DestroySortinfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSystem_DestroySortinfo()
{
  if ( materialSortInfoArray != nullptr )
  {
    WorldStaticMeshDestroy();
    free(pMem: materialSortInfoArray);
    materialSortInfoArray = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E72D0
// Name: int FindOrAddMesh(class IMaterial __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrAddMesh(IMaterial *pMaterial, int vertexCount)
{
  unsigned __int64 v2; // rax
  IMatRenderContext *v3; // esi
  int v4; // edi
  int v5; // eax
  int m_nValue; // edx
  int m_Size; // ecx
  int *p_vertCount; // edx
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  unsigned __int64 format; // [esp+Ch] [ebp-Ch]
  int nMaxVertices; // [esp+14h] [ebp-4h]

  v2 = pMaterial->GetVertexFormat(this: pMaterial);
  LODWORD(v2) = v2 & 0xFFFFFBFF;
  format = v2;
  v3 = materials->GetRenderContext(this: materials);
  v4 = 0;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v5 = v3->GetMaxVerticesToRender(this: v3, a2: pMaterial);
  nMaxVertices = v5;
  if ( mat_max_worldmesh_vertices.m_pParent == nullptr
    || (m_nValue = mat_max_worldmesh_vertices.m_pParent->m_Value.m_nValue) <= 1024 )
  {
    m_nValue = 1024;
  }
  if ( v5 > m_nValue )
  {
    if ( mat_max_worldmesh_vertices.m_pParent != nullptr )
      nMaxVertices = mat_max_worldmesh_vertices.m_pParent->m_Value.m_nValue;
    else
      nMaxVertices = 0;
  }
  m_Size = g_Meshes.m_Size;
  if ( g_Meshes.m_Size <= 0 )
  {
LABEL_15:
    v9 = g_Meshes.m_Size;
    if ( g_Meshes.m_Size + 1 > g_Meshes.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
        this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&g_Meshes,
        num: g_Meshes.m_Size - g_Meshes.m_Memory.m_nAllocationCount + 1);
      m_Size = g_Meshes.m_Size;
    }
    g_Meshes.m_Size = m_Size + 1;
    v10 = m_Size - v9;
    g_Meshes.m_pElements = g_Meshes.m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &g_Meshes.m_Memory.m_pMemory[v9 + 1], src: &g_Meshes.m_Memory.m_pMemory[v9], count: 24 * v10);
    v11 = v9;
    g_Meshes.m_Memory.m_pMemory[v11].vertCount = vertexCount;
    g_Meshes.m_Memory.m_pMemory[v11].vertexFormat = format;
    g_Meshes.m_Memory.m_pMemory[v11].pMaterial = pMaterial;
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return v9;
  }
  else
  {
    p_vertCount = &g_Meshes.m_Memory.m_pMemory->vertCount;
    while ( *((_QWORD *)p_vertCount + 1) != format || vertexCount + *p_vertCount > nMaxVertices )
    {
      ++v4;
      p_vertCount += 6;
      if ( v4 >= g_Meshes.m_Size )
        goto LABEL_15;
    }
    g_Meshes.m_Memory.m_pMemory[v4].vertCount += vertexCount;
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7460
// Name: void WorldStaticMeshCreate(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldStaticMeshCreate()
{
  int v0; // edi
  int v1; // esi
  void *v2; // esp
  int v3; // eax
  worldbrushdata_t *worldbrush; // eax
  int v5; // ebx
  msurface2_t *surfaces2; // esi
  msurface2_t *v7; // esi
  IMaterial *material; // ecx
  int k; // esi
  surfacesortgroup_t *p_m_emptyGroup; // ebx
  msurface2_t *SurfaceAtHead; // eax
  int v12; // eax
  IMatRenderContext *v13; // eax
  int v14; // esi
  IVBAllocTracker *v15; // ecx
  unsigned int v16; // ebx
  __int64 v17; // rax
  int *v18; // ebx
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // esi
  surfacesortgroup_t *v22; // eax
  __int16 listHead; // ax
  materiallist_t *m_pMemory; // ecx
  int v25; // ebx
  int *v26; // ebx
  int v27; // esi
  int m_nVertexCount; // eax
  IMesh *v29; // [esp-14h] [ebp-2ECh]
  int v30; // [esp-Ch] [ebp-2E4h]
  int v31; // [esp+0h] [ebp-2D8h] BYREF
  CMSurfaceSortList matSortArray; // [esp+Ch] [ebp-2CCh] BYREF
  CMeshBuilder meshBuilder; // [esp+CCh] [ebp-20Ch] BYREF
  int *v34; // [esp+2B4h] [ebp-24h]
  int v35; // [esp+2B8h] [ebp-20h]
  int *sortIndex; // [esp+2BCh] [ebp-1Ch]
  int i; // [esp+2C0h] [ebp-18h]
  int vertBufferIndex; // [esp+2C4h] [ebp-14h]
  int j; // [esp+2C8h] [ebp-10h]
  unsigned int m; // [esp+2CCh] [ebp-Ch]
  int surfaceIndex; // [esp+2D0h] [ebp-8h]
  bool bTools; // [esp+2D7h] [ebp-1h]

  r_framecount = 1;
  WorldStaticMeshDestroy();
  v0 = 0;
  g_Meshes.m_Size = 0;
  SetTexInfoBaseTexture2Flags();
  v1 = materials->GetNumSortIDs(this: materials);
  if ( v1 != 0 )
  {
    g_pShadowMgr->SetNumWorldMaterialBuckets(this: g_pShadowMgr, a2: v1);
    g_WorldStaticMeshes.m_Size = 0;
    CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&g_WorldStaticMeshes,
      elem: 0,
      num: v1);
    memset(
      dst: (unsigned __int8 *)g_WorldStaticMeshes.m_Memory.m_pMemory,
      value: 0,
      count: 4 * g_WorldStaticMeshes.m_Size);
    CMSurfaceSortList::CMSurfaceSortList(this: &matSortArray);
    CMSurfaceSortList::Init(this: &matSortArray, maxSortIDs: v1, minMaterialLists: 512);
    v2 = alloca(4 * g_WorldStaticMeshes.m_Size);
    sortIndex = &v31;
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-tools", a3: 0) != 0
      || (bTools = false, g_bReplayLoadedTools) )
    {
      bTools = true;
    }
    worldbrush = host_state.worldbrush;
    surfaceIndex = 0;
    if ( host_state.worldbrush->numsurfaces > 0 )
    {
      v5 = 0;
      do
      {
        surfaces2 = worldbrush->surfaces2;
        surfaces2[v5].flags &= ~0x100u;
        v7 = &surfaces2[v5];
        if ( bTools
          || (material = host_state.worldbrush->texinfo[*((unsigned __int16 *)v7 + 11) >> 1].material,
              (material->GetVertexFormat(this: material) & 0x30) != 0) )
        {
          v7->flags |= 0x100u;
        }
        if ( (v7->flags & 0x800) != 0 )
          v7->vertBufferIndex = -1;
        else
          CMSurfaceSortList::AddSurfaceToTail(
            this: &matSortArray,
            pSurface: v7,
            sortGroup: 0,
            sortID: v7->materialSortID);
        worldbrush = host_state.worldbrush;
        ++v5;
        ++surfaceIndex;
      }
      while ( surfaceIndex < host_state.worldbrush->numsurfaces );
    }
    for ( k = 0; k < g_WorldStaticMeshes.m_Size; ++k )
    {
      if ( ((unsigned __int8)(1 << ((k + LOBYTE(matSortArray.groupOffset[0])) & 7))
          & matSortArray.m_groupUsed.m_Memory.m_pMemory[(k + matSortArray.groupOffset[0]) >> 3]) != 0 )
        p_m_emptyGroup = &matSortArray.m_groups.m_Memory.m_pMemory[k + matSortArray.groupOffset[0]];
      else
        p_m_emptyGroup = &matSortArray.m_emptyGroup;
      j = VertexCountForSurfaceList(group: p_m_emptyGroup, list: &matSortArray);
      SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: &matSortArray, group: p_m_emptyGroup);
      g_WorldStaticMeshes.m_Memory.m_pMemory[k] = nullptr;
      if ( SurfaceAtHead != nullptr )
        v12 = FindOrAddMesh(
                pMaterial: host_state.worldbrush->texinfo[*((unsigned __int16 *)SurfaceAtHead + 11) >> 1].material,
                vertexCount: j);
      else
        v12 = -1;
      sortIndex[k] = v12;
    }
    v13 = materials->GetRenderContext(this: materials);
    v14 = (int)v13;
    surfaceIndex = (int)v13;
    if ( v13 != nullptr )
      v13->BeginRender(this: v13);
    i = 0;
    if ( g_Meshes.m_Size > 0 )
    {
      v15 = g_VBAllocTracker;
      v16 = 0;
      for ( m = 0; ; v16 = m )
      {
        if ( v15 != nullptr )
          v15->TrackMeshAllocations(this: v15, a2: "WorldStaticMeshCreate");
        v17 = ((__int64 (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)((char *)&g_Meshes.m_Memory.m_pMemory->pMaterial
                                                                       + v16)
                                                         + 80))(a1: *(IMaterial **)((char *)&g_Meshes.m_Memory.m_pMemory->pMaterial
                                                                                  + v16));
        v18 = (int *)((char *)g_Meshes.m_Memory.m_pMemory + v16);
        v19 = (*(int (__thiscall **)(int, _DWORD, _DWORD, const char *, int, _DWORD))(*(_DWORD *)v14 + 220))(
                a1: surfaceIndex,
                a2: v17 & 0xFFFFFBFF,
                a3: HIDWORD(v17),
                a4: "World Verts",
                a5: v18[1],
                a6: 0);
        v20 = m;
        *v18 = v19;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_bGenerateIndices = false;
        memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
        memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        v30 = *(int *)((char *)&g_Meshes.m_Memory.m_pMemory->vertCount + v20);
        v29 = *(IMesh **)((char *)&g_Meshes.m_Memory.m_pMemory->pMesh + v20);
        vertBufferIndex = 0;
        CMeshBuilder::Begin(
          this: &meshBuilder,
          pMesh: v29,
          type: MATERIAL_TRIANGLES,
          nVertexCount: v30,
          nIndexCount: 0,
          pMeshSettings: nullptr);
        v21 = 0;
        for ( j = 0; v21 < g_WorldStaticMeshes.m_Size; j = v21 )
        {
          if ( sortIndex[v21] == i )
          {
            g_WorldStaticMeshes.m_Memory.m_pMemory[v21] = g_Meshes.m_Memory.m_pMemory[m / 0x18].pMesh;
            v22 = ((unsigned __int8)(1 << ((v21 + LOBYTE(matSortArray.groupOffset[0])) & 7))
                 & matSortArray.m_groupUsed.m_Memory.m_pMemory[(v21 + matSortArray.groupOffset[0]) >> 3]) != 0
                ? &matSortArray.m_groups.m_Memory.m_pMemory[v21 + matSortArray.groupOffset[0]]
                : &matSortArray.m_emptyGroup;
            listHead = v22->listHead;
            if ( listHead != -1 )
            {
              m_pMemory = matSortArray.m_list.m_Memory.m_pMemory;
              do
              {
                v25 = listHead << 6;
                v35 = v25;
                v34 = (int *)((char *)&m_pMemory->count + v25);
                if ( *v34 > 0 )
                {
                  v26 = (int *)((char *)m_pMemory->pSurfaces + v25);
                  do
                  {
                    v27 = *v26;
                    *(_WORD *)(v27 + 20) = vertBufferIndex;
                    BuildMSurfaceVertexArrays(
                      pBrushData: host_state.worldbrush,
                      surfID: (msurface2_t *)v27,
                      builder: &meshBuilder);
                    vertBufferIndex += *(unsigned __int8 *)(v27 + 3);
                    ++v0;
                    ++v26;
                  }
                  while ( v0 < *v34 );
                  m_pMemory = matSortArray.m_list.m_Memory.m_pMemory;
                  v25 = v35;
                  v21 = j;
                  v0 = 0;
                }
                listHead = *(_WORD *)((char *)&m_pMemory->nextBlock + v25);
              }
              while ( listHead != -1 );
            }
          }
          ++v21;
        }
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: m_nVertexCount);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        v15 = g_VBAllocTracker;
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        if ( g_VBAllocTracker != nullptr )
        {
          g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
          if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
            && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
          {
            meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
            && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
          {
            meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
          }
          v15 = g_VBAllocTracker;
        }
        m += 24;
        v14 = surfaceIndex;
        if ( ++i >= g_Meshes.m_Size )
          break;
      }
    }
    if ( v14 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 12))(a1: v14);
      (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 4))(a1: v14);
    }
    CMSurfaceSortList::~CMSurfaceSortList(this: &matSortArray);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E79E0
// Name: void RestoreMaterialSystemObjects(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RestoreMaterialSystemObjects(char nChangeFlags)
{
  CStatTime *v1; // ecx
  IStaticPropMgrEngine *v2; // eax
  bool bThreadingAllowed; // [esp+4h] [ebp-4h]

  bThreadingAllowed = Host_AllowQueuedMaterialSystem(bAllow: false);
  g_LostVideoMemory = false;
  if ( (nChangeFlags & 1) != 0 )
    modelrender->RemoveAllDecalsFromAllModels(this: modelrender);
  if ( host_state.worldmodel != nullptr && materialSortInfoArray != nullptr )
  {
    if ( (nChangeFlags & 1) != 0 || materials->GetNumSortIDs(this: materials) == 0 )
    {
      R_LoadWorldGeometry(bDXChange: true);
    }
    else
    {
      modelloader->Map_LoadDisplacements(this: modelloader, a2: host_state.worldmodel, a3: true);
      WorldStaticMeshCreate();
      R_RedownloadAllLightmaps(this: v1);
    }
    R_StudioInitLightingCache();
    modelrender->RestoreAllStaticPropColorData(this: modelrender);
    v2 = StaticPropMgr();
    v2->RestoreStaticProps(this: v2);
  }
  Host_AllowQueuedMaterialSystem(bAllow: bThreadingAllowed);
}

//------------------------------------------------------------------------------
// Address: 0x100E7AA0
// Name: void InitMaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitMaterialSystem(int a1@<esi>)
{
  bool v1; // al

  ((void (__thiscall *)(IMaterialSystem *))materials->AddReleaseFunc)(a1: materials);
  ((void (__thiscall *)(IMaterialSystem *))materials->AddRestoreFunc)(a1: materials);
  v1 = g_pMaterialSystemHardwareConfig->PreferZPrepass(this: g_pMaterialSystemHardwareConfig);
  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&r_fastzreject.IConVar,
    value: v1,
    a2: (unsigned int)RestoreMaterialSystemObjects,
    a3: (int)ReleaseMaterialSystemObjects);
  UpdateMaterialSystemConfig();
  InitWellKnownRenderTargets(a1);
  InitDebugMaterials(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10312870
// Name: _dynamic_initializer_for__mat_force_tonemap_scale__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_tonemap_scale__()
{
  ConVar::ConVar(this: &mat_force_tonemap_scale, pName: "mat_force_tonemap_scale", pDefaultValue: "0.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_force_tonemap_scale__);
}

//------------------------------------------------------------------------------
// Address: 0x10313BD0
// Name: _dynamic_initializer_for__mat_texture_list__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list__()
{
  ConVar::ConVar(
    this: &mat_texture_list,
    pName: "mat_texture_list",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "For debugging, show a list of used textures per frame");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list__);
}

//------------------------------------------------------------------------------
// Address: 0x10313C00
// Name: _dynamic_initializer_for__mat_texture_list_on__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_on__()
{
  ConCommand::ConCommand(
    this: &mat_texture_list_on,
    pName: "+mat_texture_list",
    callback: mat_texture_list_on_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_on__);
}

//------------------------------------------------------------------------------
// Address: 0x10313C30
// Name: _dynamic_initializer_for__mat_texture_list_off__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_off__()
{
  ConCommand::ConCommand(
    this: &mat_texture_list_off,
    pName: "-mat_texture_list",
    callback: (void (__cdecl *)())mat_texture_list_off_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_off__);
}

//------------------------------------------------------------------------------
// Address: 0x10313C60
// Name: _dynamic_initializer_for__mat_texture_list_all__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_all__()
{
  ConVar::ConVar(
    this: &mat_texture_list_all,
    pName: "mat_texture_list_all",
    pDefaultValue: "0",
    flags: 4096,
    pHelpString: "If this is nonzero, then the texture list panel will show all currently-loaded textures.");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_all__);
}

//------------------------------------------------------------------------------
// Address: 0x10313C90
// Name: _dynamic_initializer_for__mat_texture_list_all_frames__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_all_frames__()
{
  ConVar::ConVar(
    this: &mat_texture_list_all_frames,
    pName: "mat_texture_list_all_frames",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "How many frames to sample texture memory for all textures.");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_all_frames__);
}

//------------------------------------------------------------------------------
// Address: 0x10313CC0
// Name: _dynamic_initializer_for__mat_texture_list_view__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_view__()
{
  ConVar::ConVar(
    this: &mat_texture_list_view,
    pName: "mat_texture_list_view",
    pDefaultValue: "1",
    flags: 4096,
    pHelpString: "If this is nonzero, then the texture list panel will render thumbnails of currently-loaded textures.");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_view__);
}

//------------------------------------------------------------------------------
// Address: 0x10313CF0
// Name: _dynamic_initializer_for__mat_show_texture_memory_usage__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_show_texture_memory_usage__()
{
  ConVar::ConVar(
    this: &mat_show_texture_memory_usage,
    pName: "mat_show_texture_memory_usage",
    pDefaultValue: "0",
    flags: 20480,
    pHelpString: "Display the texture memory usage on the HUD.");
  return atexit(func: dynamic_atexit_destructor_for__mat_show_texture_memory_usage__);
}

//------------------------------------------------------------------------------
// Address: 0x10313D20
// Name: _dynamic_initializer_for__mat_texture_list_exclude_editing__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_exclude_editing__()
{
  ConVar::ConVar(
    this: &mat_texture_list_exclude_editing,
    pName: "mat_texture_list_exclude_editing",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_exclude_editing__);
}

//------------------------------------------------------------------------------
// Address: 0x10313D50
// Name: _dynamic_initializer_for__mat_texture_list_txlod_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_txlod_command__()
{
  ConCommand::ConCommand(
    this: &mat_texture_list_txlod_command,
    pName: "mat_texture_list_txlod",
    callback: (void (__cdecl *)())mat_texture_list_txlod,
    pHelpString: "Adjust LOD of the last viewed texture +1 to inc resolution, -1 to dec resolution",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_txlod_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313EF0
// Name: _dynamic_initializer_for__mat_colorcorrection__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colorcorrection__()
{
  ConVar::ConVar(this: &mat_colorcorrection, pName: "mat_colorcorrection", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_colorcorrection__);
}

//------------------------------------------------------------------------------
// Address: 0x10313F20
// Name: _dynamic_initializer_for__mat_colcorrection_disableentities__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colcorrection_disableentities__()
{
  ConVar::ConVar(
    this: &mat_colcorrection_disableentities,
    pName: "mat_colcorrection_disableentities",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_colcorrection_disableentities__);
}

//------------------------------------------------------------------------------
// Address: 0x10313F50
// Name: _dynamic_initializer_for__mat_colcorrection_editor__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colcorrection_editor__()
{
  ConVar::ConVar(this: &mat_colcorrection_editor, pName: "mat_colcorrection_editor", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_colcorrection_editor__);
}

//------------------------------------------------------------------------------
// Address: 0x103143D0
// Name: _dynamic_initializer_for__mat_leafvis__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_leafvis__()
{
  ConVar::ConVar(
    this: &mat_leafvis,
    pName: "mat_leafvis",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Draw wireframe of: [0] nothing, [1] current leaf, [2] entire vis cluster, or [3] entire PVS (see mat_leafvis_draw_ma"
    "sk for what does/doesn't get drawn)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))LeafvisChanged);
  return atexit(func: dynamic_atexit_destructor_for__mat_leafvis__);
}

//------------------------------------------------------------------------------
// Address: 0x10314400
// Name: _dynamic_initializer_for__mat_leafvis_update_every_frame__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_leafvis_update_every_frame__()
{
  ConVar::ConVar(
    this: &mat_leafvis_update_every_frame,
    pName: "mat_leafvis_update_every_frame",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Updates leafvis debug render every frame (expensive)");
  return atexit(func: dynamic_atexit_destructor_for__mat_leafvis_update_every_frame__);
}

//------------------------------------------------------------------------------
// Address: 0x10314460
// Name: _dynamic_initializer_for__mat_leafvis_draw_mask__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_leafvis_draw_mask__()
{
  ConVar::ConVar(
    this: &mat_leafvis_draw_mask,
    pName: "mat_leafvis_draw_mask",
    pDefaultValue: "3",
    flags: 0,
    pHelpString: "A bitfield which affects leaf visibility debug rendering.  -1: show all, bit 0: render PVS-visible leafs, bit 1: ren"
    "der PVS- and frustum-visible leafs, bit 2: render frustum bounds, bit 3: render leaves out of PVS.");
  return atexit(func: dynamic_atexit_destructor_for__mat_leafvis_draw_mask__);
}

//------------------------------------------------------------------------------
// Address: 0x10314490
// Name: _dynamic_initializer_for__mat_leafvis_freeze__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_leafvis_freeze__()
{
  ConVar::ConVar(
    this: &mat_leafvis_freeze,
    pName: "mat_leafvis_freeze",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If set to 1, uses the last known leaf visibility data for visualization.  If set to 0, updates based on camera movement.");
  return atexit(func: dynamic_atexit_destructor_for__mat_leafvis_freeze__);
}

//------------------------------------------------------------------------------
// Address: 0x10314820
// Name: _dynamic_initializer_for__mat_defaultlightmap__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_defaultlightmap__()
{
  ConVar::ConVar(
    this: &mat_defaultlightmap,
    pName: "mat_defaultlightmap",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Default brightness for lightmaps where none have been created in the level.");
  return atexit(func: dynamic_atexit_destructor_for__mat_defaultlightmap__);
}

//------------------------------------------------------------------------------
// Address: 0x10314860
// Name: _dynamic_initializer_for__mat_edit_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_edit_command__()
{
  ConCommand::ConCommand(
    this: &mat_edit_command,
    pName: "mat_edit",
    callback: (void (__cdecl *)())mat_edit,
    pHelpString: "Bring up the material under the crosshair in the editor",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_edit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314890
// Name: _dynamic_initializer_for__mat_crosshair_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_command,
    pName: "mat_crosshair",
    callback: mat_crosshair,
    pHelpString: "Display the name of the material under the crosshair",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103148C0
// Name: _dynamic_initializer_for__mat_crosshair_edit_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_edit_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_edit_command,
    pName: "mat_crosshair_edit",
    callback: (void (__cdecl *)())mat_crosshair_edit,
    pHelpString: "open the material under the crosshair in the editor defined by mat_crosshair_edit_editor",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_edit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103148F0
// Name: _dynamic_initializer_for__mat_crosshair_explorer_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_explorer_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_explorer_command,
    pName: "mat_crosshair_explorer",
    callback: mat_crosshair_explorer,
    pHelpString: "open the material under the crosshair in explorer and highlight the vmt file",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_explorer_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314920
// Name: _dynamic_initializer_for__mat_crosshair_reloadmaterial_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_reloadmaterial_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_reloadmaterial_command,
    pName: "mat_crosshair_reloadmaterial",
    callback: mat_crosshair_reloadmaterial,
    pHelpString: "reload the material under the crosshair",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_reloadmaterial_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314950
// Name: _dynamic_initializer_for__mat_crosshair_printmaterial_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_printmaterial_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_printmaterial_command,
    pName: "mat_crosshair_printmaterial",
    callback: mat_crosshair_printmaterial,
    pHelpString: "print the material under the crosshair",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_printmaterial_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314BF0
// Name: _dynamic_initializer_for__mat_forcedynamic__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_forcedynamic__()
{
  ConVar::ConVar(this: &mat_forcedynamic, pName: &args.m_pArgvBuffer[460], pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_forcedynamic__);
}

//------------------------------------------------------------------------------
// Address: 0x10314DA0
// Name: _dynamic_initializer_for__mat_surfaceid__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_surfaceid__()
{
  ConVar::ConVar(this: &mat_surfaceid, pName: "mat_surfaceid", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_surfaceid__);
}

//------------------------------------------------------------------------------
// Address: 0x10314DD0
// Name: _dynamic_initializer_for__mat_surfacemat__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_surfacemat__()
{
  ConVar::ConVar(this: &mat_surfacemat, pName: "mat_surfacemat", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_surfacemat__);
}

//------------------------------------------------------------------------------
// Address: 0x10315390
// Name: _dynamic_initializer_for__mat_softwareskin__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_softwareskin__()
{
  ConVar::ConVar(this: &mat_softwareskin, pName: "mat_softwareskin", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_softwareskin__);
}

//------------------------------------------------------------------------------
// Address: 0x10315800
// Name: _dynamic_initializer_for__mat_shadowstate__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_shadowstate__()
{
  ConVar::ConVar(this: &mat_shadowstate, pName: "mat_shadowstate", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_shadowstate__);
}

//------------------------------------------------------------------------------
// Address: 0x10315830
// Name: _dynamic_initializer_for__mat_maxframelatency__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_maxframelatency__()
{
  ConVar::ConVar(this: &mat_maxframelatency, pName: "mat_maxframelatency", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_maxframelatency__);
}

//------------------------------------------------------------------------------
// Address: 0x10315860
// Name: _dynamic_initializer_for__mat_debugalttab__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_debugalttab__()
{
  ConVar::ConVar(this: &mat_debugalttab, pName: "mat_debugalttab", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_debugalttab__);
}

//------------------------------------------------------------------------------
// Address: 0x10315B80
// Name: _dynamic_initializer_for__mat_norendering__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_norendering__()
{
  ConVar::ConVar(this: &mat_norendering, pName: "mat_norendering", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_norendering__);
}

//------------------------------------------------------------------------------
// Address: 0x10315BB0
// Name: _dynamic_initializer_for__mat_wireframe__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_wireframe__()
{
  ConVar::ConVar(this: &mat_wireframe, pName: "mat_wireframe", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_wireframe__);
}

//------------------------------------------------------------------------------
// Address: 0x10315BE0
// Name: _dynamic_initializer_for__mat_luxels__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_luxels__()
{
  ConVar::ConVar(this: &mat_luxels, pName: "mat_luxels", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_luxels__);
}

//------------------------------------------------------------------------------
// Address: 0x10315C10
// Name: _dynamic_initializer_for__mat_normals__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_normals__()
{
  ConVar::ConVar(this: &mat_normals, pName: "mat_normals", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_normals__);
}

//------------------------------------------------------------------------------
// Address: 0x10315C40
// Name: _dynamic_initializer_for__mat_bumpbasis__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_bumpbasis__()
{
  ConVar::ConVar(this: &mat_bumpbasis, pName: "mat_bumpbasis", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_bumpbasis__);
}

//------------------------------------------------------------------------------
// Address: 0x10315C70
// Name: _dynamic_initializer_for__mat_envmapsize__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_envmapsize__()
{
  ConVar::ConVar(this: &mat_envmapsize, pName: "mat_envmapsize", pDefaultValue: "128", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_envmapsize__);
}

//------------------------------------------------------------------------------
// Address: 0x10315CA0
// Name: _dynamic_initializer_for__mat_envmaptgasize__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_envmaptgasize__()
{
  ConVar::ConVar(this: &mat_envmaptgasize, pName: "mat_envmaptgasize", pDefaultValue: "32.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_envmaptgasize__);
}

//------------------------------------------------------------------------------
// Address: 0x10315CD0
// Name: _dynamic_initializer_for__mat_levelflush__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_levelflush__()
{
  ConVar::ConVar(this: &mat_levelflush, pName: "mat_levelflush", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_levelflush__);
}

//------------------------------------------------------------------------------
// Address: 0x10315D00
// Name: _dynamic_initializer_for__mat_fastspecular__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fastspecular__()
{
  ConVar::ConVar(
    this: &mat_fastspecular,
    pName: "mat_fastspecular",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable/Disable specularity for visual testing.  Will not reload materials and will not affect perf.");
  return atexit(func: dynamic_atexit_destructor_for__mat_fastspecular__);
}

//------------------------------------------------------------------------------
// Address: 0x10315D30
// Name: _dynamic_initializer_for__mat_fullbright__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fullbright__()
{
  ConVar::ConVar(this: &mat_fullbright, pName: "mat_fullbright", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_fullbright__);
}

//------------------------------------------------------------------------------
// Address: 0x10315D60
// Name: _dynamic_initializer_for__mat_monitorgamma__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma,
    pName: "mat_monitorgamma",
    pDefaultValue: "2.2",
    flags: 16777344,
    pHelpString: "monitor gamma (typically 2.2 for CRT and 1.7 for LCD)",
    bMin: true,
    fMin: 1.6,
    bMax: true,
    fMax: 2.5999999);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma__);
}

//------------------------------------------------------------------------------
// Address: 0x10315DB0
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_range_min__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_range_min__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_range_min,
    pName: "mat_monitorgamma_tv_range_min",
    pDefaultValue: "16",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__);
}

//------------------------------------------------------------------------------
// Address: 0x10315DE0
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_range_max__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_range_max__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_range_max,
    pName: "mat_monitorgamma_tv_range_max",
    pDefaultValue: "235",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10315E10
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_exp__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_exp__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_exp,
    pName: "mat_monitorgamma_tv_exp",
    pDefaultValue: "2.5",
    flags: 0,
    pHelpString: defaultValue,
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 4.0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__);
}

//------------------------------------------------------------------------------
// Address: 0x10315E50
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_enabled__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_enabled__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_enabled,
    pName: "mat_monitorgamma_tv_enabled",
    pDefaultValue: "0",
    flags: 16777344,
    pHelpString: defaultValue);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x10315F10
// Name: _dynamic_initializer_for__mat_motion_blur_enabled__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_enabled__()
{
  ConVar::ConVar(this: &mat_motion_blur_enabled, pName: "mat_motion_blur_enabled", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x10315F40
// Name: _dynamic_initializer_for__mat_depthbias_normal__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_depthbias_normal__()
{
  ConVar::ConVar(this: &mat_depthbias_normal, pName: "mat_depthbias_normal", pDefaultValue: "0.0f", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_depthbias_normal__);
}

//------------------------------------------------------------------------------
// Address: 0x10315F70
// Name: _dynamic_initializer_for__mat_hdr_level__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_hdr_level__()
{
  ConVar::ConVar(
    this: &mat_hdr_level,
    pName: "mat_hdr_level",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Set to 0 for no HDR, 1 for LDR+bloom on HDR maps, and 2 for full HDR on HDR maps.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))mat_hdr_level_Callback);
  return atexit(func: dynamic_atexit_destructor_for__mat_hdr_level__);
}

//------------------------------------------------------------------------------
// Address: 0x10315FA0
// Name: _dynamic_initializer_for__mat_configcurrent_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_configcurrent_command__()
{
  ConCommand::ConCommand(
    this: &mat_configcurrent_command,
    pName: "mat_configcurrent",
    callback: mat_configcurrent,
    pHelpString: "show the current video control panel config for the material system",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_configcurrent_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10315FD0
// Name: _dynamic_initializer_for__mat_setvideomode_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_setvideomode_command__()
{
  ConCommand::ConCommand(
    this: &mat_setvideomode_command,
    pName: "mat_setvideomode",
    callback: (void (__cdecl *)())mat_setvideomode,
    pHelpString: "sets the width, height, windowed state of the material system",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_setvideomode_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10316000
// Name: _dynamic_initializer_for__mat_savechanges_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_savechanges_command__()
{
  ConCommand::ConCommand(
    this: &mat_savechanges_command,
    pName: "mat_savechanges",
    callback: mat_savechanges,
    pHelpString: "saves current video configuration to the registry",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_savechanges_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10316030
// Name: _dynamic_initializer_for__mat_debug_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_debug_command__()
{
  ConCommand::ConCommand(
    this: &mat_debug_command,
    pName: "mat_debug",
    callback: (void (__cdecl *)())mat_debug,
    pHelpString: "Activates debugging spew for a specific material.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_debug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10316060
// Name: _dynamic_initializer_for__mat_suppress_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_suppress_command__()
{
  ConCommand::ConCommand(
    this: &mat_suppress_command,
    pName: "mat_suppress",
    callback: (void (__cdecl *)())mat_suppress,
    pHelpString: "Supress a material from drawing",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_suppress_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10316090
// Name: _dynamic_initializer_for__mat_info_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_info_command__()
{
  ConCommand::ConCommand(
    this: &mat_info_command,
    pName: "mat_info",
    callback: mat_info,
    pHelpString: "Shows material system info",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_info_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103160D0
// Name: _dynamic_initializer_for__mat_max_worldmesh_vertices__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_max_worldmesh_vertices__()
{
  ConVar::ConVar(
    this: &mat_max_worldmesh_vertices,
    pName: "mat_max_worldmesh_vertices",
    pDefaultValue: "65536",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_max_worldmesh_vertices__);
}

//------------------------------------------------------------------------------
// Address: 0x10316100
// Name: _dynamic_initializer_for__mat_loadtextures__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_loadtextures__()
{
  ConVar::ConVar(this: &mat_loadtextures, pName: "mat_loadtextures", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_loadtextures__);
}

//------------------------------------------------------------------------------
// Address: 0x10316190
// Name: _dynamic_initializer_for__mat_excludetextures__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_excludetextures__()
{
  ConVar::ConVar(this: &mat_excludetextures, pName: "mat_excludetextures", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_excludetextures__);
}

//------------------------------------------------------------------------------
// Address: 0x103161C0
// Name: _dynamic_initializer_for__mat_glidnarb__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_glidnarb__()
{
  ConVar::ConVar(this: &mat_glidnarb, pName: "mat_glidnarb", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_glidnarb__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C0B0
// Name: _dynamic_initializer_for__mat_ambient_light_r__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_r__()
{
  ConVar::ConVar(this: &mat_ambient_light_r, pName: "mat_ambient_light_r", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_r__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C0E0
// Name: _dynamic_initializer_for__mat_ambient_light_g__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_g__()
{
  ConVar::ConVar(this: &mat_ambient_light_g, pName: "mat_ambient_light_g", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_g__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C110
// Name: _dynamic_initializer_for__mat_ambient_light_b__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_b__()
{
  ConVar::ConVar(this: &mat_ambient_light_b, pName: "mat_ambient_light_b", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_b__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F1E0
// Name: _dynamic_initializer_for__mat_drawTitleSafe__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_drawTitleSafe__()
{
  ConVar::ConVar(
    this: &mat_drawTitleSafe,
    pName: "mat_drawTitleSafe",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable title safe overlay");
  return atexit(func: dynamic_atexit_destructor_for__mat_drawTitleSafe__);
}

//------------------------------------------------------------------------------
// Address: 0x103222A0
// Name: _dynamic_atexit_destructor_for__mat_force_tonemap_scale__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_tonemap_scale__()
{
  ConVar::~ConVar(this: &mat_force_tonemap_scale);
}

//------------------------------------------------------------------------------
// Address: 0x10322990
// Name: _dynamic_atexit_destructor_for__mat_texture_list__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list__()
{
  ConVar::~ConVar(this: &mat_texture_list);
}

//------------------------------------------------------------------------------
// Address: 0x103229A0
// Name: _dynamic_atexit_destructor_for__mat_texture_list_on__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_on__()
{
  ConCommand::~ConCommand(this: &mat_texture_list_on);
}

//------------------------------------------------------------------------------
// Address: 0x103229B0
// Name: _dynamic_atexit_destructor_for__mat_texture_list_off__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_off__()
{
  ConCommand::~ConCommand(this: &mat_texture_list_off);
}

//------------------------------------------------------------------------------
// Address: 0x103229C0
// Name: _dynamic_atexit_destructor_for__mat_texture_list_all__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_all__()
{
  ConVar::~ConVar(this: &mat_texture_list_all);
}

//------------------------------------------------------------------------------
// Address: 0x103229D0
// Name: _dynamic_atexit_destructor_for__mat_texture_list_all_frames__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_all_frames__()
{
  ConVar::~ConVar(this: &mat_texture_list_all_frames);
}

//------------------------------------------------------------------------------
// Address: 0x103229E0
// Name: _dynamic_atexit_destructor_for__mat_texture_list_view__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_view__()
{
  ConVar::~ConVar(this: &mat_texture_list_view);
}

//------------------------------------------------------------------------------
// Address: 0x103229F0
// Name: _dynamic_atexit_destructor_for__mat_show_texture_memory_usage__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_show_texture_memory_usage__()
{
  ConVar::~ConVar(this: &mat_show_texture_memory_usage);
}

//------------------------------------------------------------------------------
// Address: 0x10322A00
// Name: _dynamic_atexit_destructor_for__mat_texture_list_exclude_editing__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_exclude_editing__()
{
  ConVar::~ConVar(this: &mat_texture_list_exclude_editing);
}

//------------------------------------------------------------------------------
// Address: 0x10322A10
// Name: _dynamic_atexit_destructor_for__mat_texture_list_txlod_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_txlod_command__()
{
  ConCommand::~ConCommand(this: &mat_texture_list_txlod_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322AB0
// Name: _dynamic_atexit_destructor_for__mat_colorcorrection__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_colorcorrection__()
{
  ConVar::~ConVar(this: &mat_colorcorrection);
}

//------------------------------------------------------------------------------
// Address: 0x10322AC0
// Name: _dynamic_atexit_destructor_for__mat_colcorrection_disableentities__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_colcorrection_disableentities__()
{
  ConVar::~ConVar(this: &mat_colcorrection_disableentities);
}

//------------------------------------------------------------------------------
// Address: 0x10322AD0
// Name: _dynamic_atexit_destructor_for__mat_colcorrection_editor__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_colcorrection_editor__()
{
  ConVar::~ConVar(this: &mat_colcorrection_editor);
}

//------------------------------------------------------------------------------
// Address: 0x10322C90
// Name: _dynamic_atexit_destructor_for__mat_leafvis__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_leafvis__()
{
  ConVar::~ConVar(this: &mat_leafvis);
}

//------------------------------------------------------------------------------
// Address: 0x10322CA0
// Name: _dynamic_atexit_destructor_for__mat_leafvis_update_every_frame__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_leafvis_update_every_frame__()
{
  ConVar::~ConVar(this: &mat_leafvis_update_every_frame);
}

//------------------------------------------------------------------------------
// Address: 0x10322CC0
// Name: _dynamic_atexit_destructor_for__mat_leafvis_draw_mask__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_leafvis_draw_mask__()
{
  ConVar::~ConVar(this: &mat_leafvis_draw_mask);
}

//------------------------------------------------------------------------------
// Address: 0x10322CD0
// Name: _dynamic_atexit_destructor_for__mat_leafvis_freeze__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_leafvis_freeze__()
{
  ConVar::~ConVar(this: &mat_leafvis_freeze);
}

//------------------------------------------------------------------------------
// Address: 0x10322F10
// Name: _dynamic_atexit_destructor_for__mat_defaultlightmap__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_defaultlightmap__()
{
  ConVar::~ConVar(this: &mat_defaultlightmap);
}

//------------------------------------------------------------------------------
// Address: 0x10322F20
// Name: _dynamic_atexit_destructor_for__mat_edit_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_edit_command__()
{
  ConCommand::~ConCommand(this: &mat_edit_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322F30
// Name: _dynamic_atexit_destructor_for__mat_crosshair_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_crosshair_command__()
{
  ConCommand::~ConCommand(this: &mat_crosshair_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322F40
// Name: _dynamic_atexit_destructor_for__mat_crosshair_edit_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_crosshair_edit_command__()
{
  ConCommand::~ConCommand(this: &mat_crosshair_edit_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322F50
// Name: _dynamic_atexit_destructor_for__mat_crosshair_explorer_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_crosshair_explorer_command__()
{
  ConCommand::~ConCommand(this: &mat_crosshair_explorer_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322F60
// Name: _dynamic_atexit_destructor_for__mat_crosshair_reloadmaterial_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_crosshair_reloadmaterial_command__()
{
  ConCommand::~ConCommand(this: &mat_crosshair_reloadmaterial_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322F70
// Name: _dynamic_atexit_destructor_for__mat_crosshair_printmaterial_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_crosshair_printmaterial_command__()
{
  ConCommand::~ConCommand(this: &mat_crosshair_printmaterial_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323090
// Name: _dynamic_atexit_destructor_for__mat_forcedynamic__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_forcedynamic__()
{
  ConVar::~ConVar(this: &mat_forcedynamic);
}

//------------------------------------------------------------------------------
// Address: 0x10323120
// Name: _dynamic_atexit_destructor_for__mat_surfaceid__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_surfaceid__()
{
  ConVar::~ConVar(this: &mat_surfaceid);
}

//------------------------------------------------------------------------------
// Address: 0x10323130
// Name: _dynamic_atexit_destructor_for__mat_surfacemat__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_surfacemat__()
{
  ConVar::~ConVar(this: &mat_surfacemat);
}

//------------------------------------------------------------------------------
// Address: 0x10323350
// Name: _dynamic_atexit_destructor_for__mat_softwareskin__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_softwareskin__()
{
  ConVar::~ConVar(this: &mat_softwareskin);
}

//------------------------------------------------------------------------------
// Address: 0x10323530
// Name: _dynamic_atexit_destructor_for__mat_shadowstate__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_shadowstate__()
{
  ConVar::~ConVar(this: &mat_shadowstate);
}

//------------------------------------------------------------------------------
// Address: 0x10323540
// Name: _dynamic_atexit_destructor_for__mat_maxframelatency__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_maxframelatency__()
{
  ConVar::~ConVar(this: &mat_maxframelatency);
}

//------------------------------------------------------------------------------
// Address: 0x10323550
// Name: _dynamic_atexit_destructor_for__mat_debugalttab__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debugalttab__()
{
  ConVar::~ConVar(this: &mat_debugalttab);
}

//------------------------------------------------------------------------------
// Address: 0x103236B0
// Name: _dynamic_atexit_destructor_for__mat_norendering__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_norendering__()
{
  ConVar::~ConVar(this: &mat_norendering);
}

//------------------------------------------------------------------------------
// Address: 0x103236C0
// Name: _dynamic_atexit_destructor_for__mat_wireframe__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_wireframe__()
{
  ConVar::~ConVar(this: &mat_wireframe);
}

//------------------------------------------------------------------------------
// Address: 0x103236D0
// Name: _dynamic_atexit_destructor_for__mat_luxels__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_luxels__()
{
  ConVar::~ConVar(this: &mat_luxels);
}

//------------------------------------------------------------------------------
// Address: 0x103236E0
// Name: _dynamic_atexit_destructor_for__mat_normals__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_normals__()
{
  ConVar::~ConVar(this: &mat_normals);
}

//------------------------------------------------------------------------------
// Address: 0x103236F0
// Name: _dynamic_atexit_destructor_for__mat_bumpbasis__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_bumpbasis__()
{
  ConVar::~ConVar(this: &mat_bumpbasis);
}

//------------------------------------------------------------------------------
// Address: 0x10323700
// Name: _dynamic_atexit_destructor_for__mat_envmapsize__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_envmapsize__()
{
  ConVar::~ConVar(this: &mat_envmapsize);
}

//------------------------------------------------------------------------------
// Address: 0x10323710
// Name: _dynamic_atexit_destructor_for__mat_envmaptgasize__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_envmaptgasize__()
{
  ConVar::~ConVar(this: &mat_envmaptgasize);
}

//------------------------------------------------------------------------------
// Address: 0x10323720
// Name: _dynamic_atexit_destructor_for__mat_levelflush__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_levelflush__()
{
  ConVar::~ConVar(this: &mat_levelflush);
}

//------------------------------------------------------------------------------
// Address: 0x10323730
// Name: _dynamic_atexit_destructor_for__mat_fastspecular__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fastspecular__()
{
  ConVar::~ConVar(this: &mat_fastspecular);
}

//------------------------------------------------------------------------------
// Address: 0x10323740
// Name: _dynamic_atexit_destructor_for__mat_fullbright__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fullbright__()
{
  ConVar::~ConVar(this: &mat_fullbright);
}

//------------------------------------------------------------------------------
// Address: 0x10323750
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma__()
{
  ConVar::~ConVar(this: &mat_monitorgamma);
}

//------------------------------------------------------------------------------
// Address: 0x10323760
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_range_min);
}

//------------------------------------------------------------------------------
// Address: 0x10323770
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_range_max);
}

//------------------------------------------------------------------------------
// Address: 0x10323780
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_exp);
}

//------------------------------------------------------------------------------
// Address: 0x10323790
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103237D0
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_enabled__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_enabled__()
{
  ConVar::~ConVar(this: &mat_motion_blur_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103237E0
// Name: _dynamic_atexit_destructor_for__mat_depthbias_normal__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_depthbias_normal__()
{
  ConVar::~ConVar(this: &mat_depthbias_normal);
}

//------------------------------------------------------------------------------
// Address: 0x103237F0
// Name: _dynamic_atexit_destructor_for__mat_hdr_level__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_hdr_level__()
{
  ConVar::~ConVar(this: &mat_hdr_level);
}

//------------------------------------------------------------------------------
// Address: 0x10323800
// Name: _dynamic_atexit_destructor_for__mat_configcurrent_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_configcurrent_command__()
{
  ConCommand::~ConCommand(this: &mat_configcurrent_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323810
// Name: _dynamic_atexit_destructor_for__mat_setvideomode_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_setvideomode_command__()
{
  ConCommand::~ConCommand(this: &mat_setvideomode_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323820
// Name: _dynamic_atexit_destructor_for__mat_savechanges_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_savechanges_command__()
{
  ConCommand::~ConCommand(this: &mat_savechanges_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323830
// Name: _dynamic_atexit_destructor_for__mat_debug_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debug_command__()
{
  ConCommand::~ConCommand(this: &mat_debug_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323840
// Name: _dynamic_atexit_destructor_for__mat_suppress_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_suppress_command__()
{
  ConCommand::~ConCommand(this: &mat_suppress_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323850
// Name: _dynamic_atexit_destructor_for__mat_info_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_info_command__()
{
  ConCommand::~ConCommand(this: &mat_info_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323860
// Name: _dynamic_atexit_destructor_for__mat_max_worldmesh_vertices__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_max_worldmesh_vertices__()
{
  ConVar::~ConVar(this: &mat_max_worldmesh_vertices);
}

//------------------------------------------------------------------------------
// Address: 0x10323880
// Name: _dynamic_atexit_destructor_for__mat_loadtextures__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_loadtextures__()
{
  ConVar::~ConVar(this: &mat_loadtextures);
}

//------------------------------------------------------------------------------
// Address: 0x103238B0
// Name: _dynamic_atexit_destructor_for__mat_excludetextures__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_excludetextures__()
{
  ConVar::~ConVar(this: &mat_excludetextures);
}

//------------------------------------------------------------------------------
// Address: 0x103238C0
// Name: _dynamic_atexit_destructor_for__mat_glidnarb__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_glidnarb__()
{
  ConVar::~ConVar(this: &mat_glidnarb);
}

//------------------------------------------------------------------------------
// Address: 0x10325E30
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_r__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_r__()
{
  ConVar::~ConVar(this: &mat_ambient_light_r);
}

//------------------------------------------------------------------------------
// Address: 0x10325E40
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_g__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_g__()
{
  ConVar::~ConVar(this: &mat_ambient_light_g);
}

//------------------------------------------------------------------------------
// Address: 0x10325E50
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_b__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_b__()
{
  ConVar::~ConVar(this: &mat_ambient_light_b);
}

//------------------------------------------------------------------------------
// Address: 0x10327220
// Name: _dynamic_atexit_destructor_for__mat_drawTitleSafe__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_drawTitleSafe__()
{
  ConVar::~ConVar(this: &mat_drawTitleSafe);
}

//------------------------------------------------------------------------------
// Address: 0x103128A0
// Name: _dynamic_initializer_for__envmap_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__envmap_command__()
{
  ConCommand::ConCommand(
    this: &envmap_command,
    pName: "envmap",
    callback: (void (__cdecl *)())envmap,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__envmap_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103128D0
// Name: _dynamic_initializer_for__lightprobe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lightprobe_command__()
{
  ConCommand::ConCommand(
    this: &lightprobe_command,
    pName: "lightprobe",
    callback: (void (__cdecl *)())lightprobe,
    pHelpString: "Samples the lighting environment.\n"
    "Creates a cubemap and a file indicating the local lighting in a subdirectory called 'materials/lightprobes'\n"
    ".The lightprobe command requires you specify a base file name.\n",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__lightprobe_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313F80
// Name: _dynamic_initializer_for__colorcorrectionui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__colorcorrectionui__()
{
  ConCommand::ConCommand(
    this: &colorcorrectionui,
    pName: "colorcorrectionui",
    callback: ShowHideColorCorrectionUI,
    pHelpString: "Show/hide the color correction tools UI.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__colorcorrectionui__);
}

//------------------------------------------------------------------------------
// Address: 0x10313FB0
// Name: _dynamic_initializer_for__print_colorcorrection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__print_colorcorrection__()
{
  ConCommand::ConCommand(
    this: &print_colorcorrection,
    pName: "print_colorcorrection",
    callback: PrintColorCorrection,
    pHelpString: "Display the color correction layer information.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__print_colorcorrection__);
}

//------------------------------------------------------------------------------
// Address: 0x10313FE0
// Name: _dynamic_initializer_for__LOG_CONSOLE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_CONSOLE__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "Console",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_13);
  LOG_CONSOLE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10314000
// Name: _dynamic_initializer_for__con_timestamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_timestamp__()
{
  ConVar::ConVar(
    this: &con_timestamp,
    pName: "con_timestamp",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Prefix console.log entries with timestamps");
  return atexit(func: dynamic_atexit_destructor_for__con_timestamp__);
}

//------------------------------------------------------------------------------
// Address: 0x10314030
// Name: _dynamic_initializer_for__con_logfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_logfile__()
{
  ConVar::ConVar(
    this: &con_logfile,
    pName: "con_logfile",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Console output gets written to this file",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: (void (__cdecl *)(IConVar *, const char *, float))ConsoleLogFileCallback);
  return atexit(func: dynamic_atexit_destructor_for__con_logfile__);
}

//------------------------------------------------------------------------------
// Address: 0x10314070
// Name: _dynamic_initializer_for__con_trace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_trace__()
{
  ConVar::ConVar(
    this: &con_trace,
    pName: "con_trace",
    pDefaultValue: "0",
    flags: 0x800000,
    pHelpString: "Print console text to low level printout.");
  return atexit(func: dynamic_atexit_destructor_for__con_trace__);
}

//------------------------------------------------------------------------------
// Address: 0x103140A0
// Name: _dynamic_initializer_for__con_notifytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_notifytime__()
{
  ConVar::ConVar(
    this: &con_notifytime,
    pName: "con_notifytime",
    pDefaultValue: "8",
    flags: 0x800000,
    pHelpString: "How long to display recent console text to the upper part of the game window");
  return atexit(func: dynamic_atexit_destructor_for__con_notifytime__);
}

//------------------------------------------------------------------------------
// Address: 0x103140D0
// Name: _dynamic_initializer_for__con_times__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_times__()
{
  ConVar::ConVar(
    this: &con_times,
    pName: "contimes",
    pDefaultValue: "8",
    flags: 0x800000,
    pHelpString: "Number of console lines to overlay for debugging.");
  return atexit(func: dynamic_atexit_destructor_for__con_times__);
}

//------------------------------------------------------------------------------
// Address: 0x10314100
// Name: _dynamic_initializer_for__con_drawnotify__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_drawnotify__()
{
  ConVar::ConVar(
    this: &con_drawnotify,
    pName: "con_drawnotify",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Disables drawing of notification area (for taking screenshots).");
  return atexit(func: dynamic_atexit_destructor_for__con_drawnotify__);
}

//------------------------------------------------------------------------------
// Address: 0x10314130
// Name: _dynamic_initializer_for__con_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_enable__()
{
  ConVar::ConVar(
    this: &con_enable,
    pName: "con_enable",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Allows the console to be activated.");
  return atexit(func: dynamic_atexit_destructor_for__con_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10314160
// Name: _dynamic_initializer_for__con_filter_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_filter_enable__()
{
  ConVar::ConVar(
    this: &con_filter_enable,
    pName: "con_filter_enable",
    pDefaultValue: "0",
    flags: 0x800000,
    pHelpString: "Filters console output based on the setting of con_filter_text. 1 filters completely, 2 displays filtered text brigh"
    "ter than other text.");
  return atexit(func: dynamic_atexit_destructor_for__con_filter_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10314190
// Name: _dynamic_initializer_for__con_filter_text__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_filter_text__()
{
  ConVar::ConVar(
    this: &con_filter_text,
    pName: "con_filter_text",
    pDefaultValue: defaultValue,
    flags: 0x800000,
    pHelpString: "Text with which to filter console spew. Set con_filter_enable 1 or 2 to activate.");
  return atexit(func: dynamic_atexit_destructor_for__con_filter_text__);
}

//------------------------------------------------------------------------------
// Address: 0x103141C0
// Name: _dynamic_initializer_for__con_filter_text_out__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_filter_text_out__()
{
  ConVar::ConVar(
    this: &con_filter_text_out,
    pName: "con_filter_text_out",
    pDefaultValue: defaultValue,
    flags: 0x800000,
    pHelpString: "Text with which to filter OUT of console spew. Set con_filter_enable 1 or 2 to activate.");
  return atexit(func: dynamic_atexit_destructor_for__con_filter_text_out__);
}

//------------------------------------------------------------------------------
// Address: 0x103141F0
// Name: _dynamic_initializer_for__con_nprint_bgalpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_nprint_bgalpha__()
{
  ConVar::ConVar(
    this: &con_nprint_bgalpha,
    pName: "con_nprint_bgalpha",
    pDefaultValue: "50",
    flags: 0,
    pHelpString: "Con_NPrint background alpha.");
  return atexit(func: dynamic_atexit_destructor_for__con_nprint_bgalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x10314220
// Name: _dynamic_initializer_for__con_nprint_bgborder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_nprint_bgborder__()
{
  ConVar::ConVar(
    this: &con_nprint_bgborder,
    pName: "con_nprint_bgborder",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "Con_NPrint border size.");
  return atexit(func: dynamic_atexit_destructor_for__con_nprint_bgborder__);
}

//------------------------------------------------------------------------------
// Address: 0x10314250
// Name: _dynamic_initializer_for__toggleconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__toggleconsole__()
{
  ConCommand::ConCommand(
    this: &toggleconsole,
    pName: "toggleconsole",
    callback: Con_ToggleConsole_f,
    pHelpString: "Show/hide the console.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__toggleconsole__);
}

//------------------------------------------------------------------------------
// Address: 0x10314280
// Name: _dynamic_initializer_for__hideconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hideconsole__()
{
  ConCommand::ConCommand(
    this: &hideconsole,
    pName: "hideconsole",
    callback: Con_HideConsole_f,
    pHelpString: "Hide the console.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hideconsole__);
}

//------------------------------------------------------------------------------
// Address: 0x103142B0
// Name: _dynamic_initializer_for__showconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showconsole__()
{
  ConCommand::ConCommand(
    this: &showconsole,
    pName: "showconsole",
    callback: Con_ShowConsole_f,
    pHelpString: "Show the console.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showconsole__);
}

//------------------------------------------------------------------------------
// Address: 0x103142E0
// Name: _dynamic_initializer_for__clear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clear__()
{
  ConCommand::ConCommand(
    this: &clear,
    pName: "clear",
    callback: Con_Clear_f,
    pHelpString: "Clear all console output.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__clear__);
}

//------------------------------------------------------------------------------
// Address: 0x10314310
// Name: _dynamic_initializer_for__log_dumpchannels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_dumpchannels__()
{
  ConCommand::ConCommand(
    this: &log_dumpchannels,
    pName: "log_dumpchannels",
    callback: Con_LogDumpChannels_f,
    pHelpString: "Dumps information about all logging channels.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_dumpchannels__);
}

//------------------------------------------------------------------------------
// Address: 0x10314340
// Name: _dynamic_initializer_for__log_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_level__()
{
  ConCommand::ConCommand(
    this: &log_level,
    pName: "log_level",
    callback: (void (__cdecl *)())Con_LogLevel_f,
    pHelpString: "Set the spew level of a logging channel.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_level__);
}

//------------------------------------------------------------------------------
// Address: 0x10314370
// Name: _dynamic_initializer_for__log_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_color__()
{
  ConCommand::ConCommand(
    this: &log_color,
    pName: "log_color",
    callback: (void (__cdecl *)())Con_LogColor_f,
    pHelpString: "Set the color of a logging channel.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_color__);
}

//------------------------------------------------------------------------------
// Address: 0x103143A0
// Name: _dynamic_initializer_for__log_flags__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_flags__()
{
  ConCommand::ConCommand(
    this: &log_flags,
    pName: "log_flags",
    callback: (void (__cdecl *)())Con_LogFlags_f,
    pHelpString: "Set the flags on a logging channel.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_flags__);
}

//------------------------------------------------------------------------------
// Address: 0x10314850
// Name: _dynamic_initializer_for__g_WorldStaticMeshes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WorldStaticMeshes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WorldStaticMeshes__);
}

//------------------------------------------------------------------------------
// Address: 0x10315890
// Name: _dynamic_initializer_for__g_PowerOfTwoFBTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PowerOfTwoFBTexture__()
{
  CTextureReference::CTextureReference(this: &g_PowerOfTwoFBTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_PowerOfTwoFBTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x103158B0
// Name: _dynamic_initializer_for__g_WaterReflectionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WaterReflectionTexture__()
{
  CTextureReference::CTextureReference(this: &g_WaterReflectionTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_WaterReflectionTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x103158D0
// Name: _dynamic_initializer_for__g_WaterRefractionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WaterRefractionTexture__()
{
  CTextureReference::CTextureReference(this: &g_WaterRefractionTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_WaterRefractionTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x103158F0
// Name: _dynamic_initializer_for__g_CameraTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CameraTexture__()
{
  CTextureReference::CTextureReference(this: &g_CameraTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_CameraTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10315910
// Name: _dynamic_initializer_for__g_BuildCubemaps16BitTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildCubemaps16BitTexture__()
{
  CTextureReference::CTextureReference(this: &g_BuildCubemaps16BitTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_BuildCubemaps16BitTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10315930
// Name: _dynamic_initializer_for__g_QuarterSizedFBTexture0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuarterSizedFBTexture0__()
{
  CTextureReference::CTextureReference(this: &g_QuarterSizedFBTexture0);
  return atexit(func: dynamic_atexit_destructor_for__g_QuarterSizedFBTexture0__);
}

//------------------------------------------------------------------------------
// Address: 0x10315950
// Name: _dynamic_initializer_for__g_QuarterSizedFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuarterSizedFBTexture1__()
{
  CTextureReference::CTextureReference(this: &g_QuarterSizedFBTexture1);
  return atexit(func: dynamic_atexit_destructor_for__g_QuarterSizedFBTexture1__);
}

//------------------------------------------------------------------------------
// Address: 0x10315970
// Name: _dynamic_initializer_for__g_QuarterSizedFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuarterSizedFBTexture2__()
{
  CTextureReference::CTextureReference(this: &g_QuarterSizedFBTexture2);
  return atexit(func: dynamic_atexit_destructor_for__g_QuarterSizedFBTexture2__);
}

//------------------------------------------------------------------------------
// Address: 0x10315990
// Name: _dynamic_initializer_for__g_QuarterSizedFBTexture3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuarterSizedFBTexture3__()
{
  CTextureReference::CTextureReference(this: &g_QuarterSizedFBTexture3);
  return atexit(func: dynamic_atexit_destructor_for__g_QuarterSizedFBTexture3__);
}

//------------------------------------------------------------------------------
// Address: 0x103159B0
// Name: _dynamic_initializer_for__g_TeenyFBTexture0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TeenyFBTexture0__()
{
  CTextureReference::CTextureReference(this: &g_TeenyFBTexture0);
  return atexit(func: dynamic_atexit_destructor_for__g_TeenyFBTexture0__);
}

//------------------------------------------------------------------------------
// Address: 0x103159D0
// Name: _dynamic_initializer_for__g_TeenyFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TeenyFBTexture1__()
{
  CTextureReference::CTextureReference(this: &g_TeenyFBTexture1);
  return atexit(func: dynamic_atexit_destructor_for__g_TeenyFBTexture1__);
}

//------------------------------------------------------------------------------
// Address: 0x103159F0
// Name: _dynamic_initializer_for__g_TeenyFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TeenyFBTexture2__()
{
  CTextureReference::CTextureReference(this: &g_TeenyFBTexture2);
  return atexit(func: dynamic_atexit_destructor_for__g_TeenyFBTexture2__);
}

//------------------------------------------------------------------------------
// Address: 0x10315A10
// Name: _dynamic_initializer_for__g_FullFrameFBTexture0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FullFrameFBTexture0__()
{
  CTextureReference::CTextureReference(this: &g_FullFrameFBTexture0);
  return atexit(func: dynamic_atexit_destructor_for__g_FullFrameFBTexture0__);
}

//------------------------------------------------------------------------------
// Address: 0x10315A30
// Name: _dynamic_initializer_for__g_FullFrameFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FullFrameFBTexture1__()
{
  CTextureReference::CTextureReference(this: &g_FullFrameFBTexture1);
  return atexit(func: dynamic_atexit_destructor_for__g_FullFrameFBTexture1__);
}

//------------------------------------------------------------------------------
// Address: 0x10315A50
// Name: _dynamic_initializer_for__g_FullFrameFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FullFrameFBTexture2__()
{
  CTextureReference::CTextureReference(this: &g_FullFrameFBTexture2);
  return atexit(func: dynamic_atexit_destructor_for__g_FullFrameFBTexture2__);
}

//------------------------------------------------------------------------------
// Address: 0x10315A70
// Name: _dynamic_initializer_for__g_FullFrameDepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FullFrameDepth__()
{
  CTextureReference::CTextureReference(this: &g_FullFrameDepth);
  return atexit(func: dynamic_atexit_destructor_for__g_FullFrameDepth__);
}

//------------------------------------------------------------------------------
// Address: 0x103160C0
// Name: _dynamic_initializer_for__g_Meshes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Meshes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Meshes__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F210
// Name: _dynamic_initializer_for__g_FocusPanelList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FocusPanelList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FocusPanelList__);
}

//------------------------------------------------------------------------------
// Address: 0x103222B0
// Name: _dynamic_atexit_destructor_for__envmap_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__envmap_command__()
{
  ConCommand::~ConCommand(this: &envmap_command);
}

//------------------------------------------------------------------------------
// Address: 0x103222C0
// Name: _dynamic_atexit_destructor_for__lightprobe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lightprobe_command__()
{
  ConCommand::~ConCommand(this: &lightprobe_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322AE0
// Name: _dynamic_atexit_destructor_for__colorcorrectionui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__colorcorrectionui__()
{
  ConCommand::~ConCommand(this: &colorcorrectionui);
}

//------------------------------------------------------------------------------
// Address: 0x10322AF0
// Name: _dynamic_atexit_destructor_for__print_colorcorrection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__print_colorcorrection__()
{
  ConCommand::~ConCommand(this: &print_colorcorrection);
}

//------------------------------------------------------------------------------
// Address: 0x10322B50
// Name: _dynamic_atexit_destructor_for__con_timestamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_timestamp__()
{
  ConVar::~ConVar(this: &con_timestamp);
}

//------------------------------------------------------------------------------
// Address: 0x10322B60
// Name: _dynamic_atexit_destructor_for__con_logfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_logfile__()
{
  ConVar::~ConVar(this: &con_logfile);
}

//------------------------------------------------------------------------------
// Address: 0x10322B70
// Name: _dynamic_atexit_destructor_for__con_trace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_trace__()
{
  ConVar::~ConVar(this: &con_trace);
}

//------------------------------------------------------------------------------
// Address: 0x10322B80
// Name: _dynamic_atexit_destructor_for__con_notifytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_notifytime__()
{
  ConVar::~ConVar(this: &con_notifytime);
}

//------------------------------------------------------------------------------
// Address: 0x10322B90
// Name: _dynamic_atexit_destructor_for__con_times__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_times__()
{
  ConVar::~ConVar(this: &con_times);
}

//------------------------------------------------------------------------------
// Address: 0x10322BA0
// Name: _dynamic_atexit_destructor_for__con_drawnotify__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_drawnotify__()
{
  ConVar::~ConVar(this: &con_drawnotify);
}

//------------------------------------------------------------------------------
// Address: 0x10322BB0
// Name: _dynamic_atexit_destructor_for__con_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_enable__()
{
  ConVar::~ConVar(this: &con_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10322BC0
// Name: _dynamic_atexit_destructor_for__con_filter_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_filter_enable__()
{
  ConVar::~ConVar(this: &con_filter_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10322BD0
// Name: _dynamic_atexit_destructor_for__con_filter_text__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_filter_text__()
{
  ConVar::~ConVar(this: &con_filter_text);
}

//------------------------------------------------------------------------------
// Address: 0x10322BE0
// Name: _dynamic_atexit_destructor_for__con_filter_text_out__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_filter_text_out__()
{
  ConVar::~ConVar(this: &con_filter_text_out);
}

//------------------------------------------------------------------------------
// Address: 0x10322BF0
// Name: _dynamic_atexit_destructor_for__con_nprint_bgalpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_nprint_bgalpha__()
{
  ConVar::~ConVar(this: &con_nprint_bgalpha);
}

//------------------------------------------------------------------------------
// Address: 0x10322C00
// Name: _dynamic_atexit_destructor_for__con_nprint_bgborder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_nprint_bgborder__()
{
  ConVar::~ConVar(this: &con_nprint_bgborder);
}

//------------------------------------------------------------------------------
// Address: 0x10322C10
// Name: _dynamic_atexit_destructor_for__toggleconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__toggleconsole__()
{
  ConCommand::~ConCommand(this: &toggleconsole);
}

//------------------------------------------------------------------------------
// Address: 0x10322C20
// Name: _dynamic_atexit_destructor_for__hideconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hideconsole__()
{
  ConCommand::~ConCommand(this: &hideconsole);
}

//------------------------------------------------------------------------------
// Address: 0x10322C30
// Name: _dynamic_atexit_destructor_for__showconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showconsole__()
{
  ConCommand::~ConCommand(this: &showconsole);
}

//------------------------------------------------------------------------------
// Address: 0x10322C40
// Name: _dynamic_atexit_destructor_for__clear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__clear__()
{
  ConCommand::~ConCommand(this: &clear);
}

//------------------------------------------------------------------------------
// Address: 0x10322C50
// Name: _dynamic_atexit_destructor_for__log_dumpchannels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_dumpchannels__()
{
  ConCommand::~ConCommand(this: &log_dumpchannels);
}

//------------------------------------------------------------------------------
// Address: 0x10322C60
// Name: _dynamic_atexit_destructor_for__log_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_level__()
{
  ConCommand::~ConCommand(this: &log_level);
}

//------------------------------------------------------------------------------
// Address: 0x10322C70
// Name: _dynamic_atexit_destructor_for__log_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_color__()
{
  ConCommand::~ConCommand(this: &log_color);
}

//------------------------------------------------------------------------------
// Address: 0x10322C80
// Name: _dynamic_atexit_destructor_for__log_flags__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_flags__()
{
  ConCommand::~ConCommand(this: &log_flags);
}

//------------------------------------------------------------------------------
// Address: 0x10322F80
// Name: _dynamic_atexit_destructor_for__g_WorldStaticMeshes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WorldStaticMeshes__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_WorldStaticMeshes);
}

//------------------------------------------------------------------------------
// Address: 0x10323560
// Name: _dynamic_atexit_destructor_for__g_PowerOfTwoFBTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PowerOfTwoFBTexture__()
{
  CTextureReference::~CTextureReference(this: &g_PowerOfTwoFBTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10323570
// Name: _dynamic_atexit_destructor_for__g_WaterReflectionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WaterReflectionTexture__()
{
  CTextureReference::~CTextureReference(this: &g_WaterReflectionTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10323580
// Name: _dynamic_atexit_destructor_for__g_WaterRefractionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WaterRefractionTexture__()
{
  CTextureReference::~CTextureReference(this: &g_WaterRefractionTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10323590
// Name: _dynamic_atexit_destructor_for__g_CameraTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CameraTexture__()
{
  CTextureReference::~CTextureReference(this: &g_CameraTexture);
}

//------------------------------------------------------------------------------
// Address: 0x103235A0
// Name: _dynamic_atexit_destructor_for__g_BuildCubemaps16BitTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BuildCubemaps16BitTexture__()
{
  CTextureReference::~CTextureReference(this: &g_BuildCubemaps16BitTexture);
}

//------------------------------------------------------------------------------
// Address: 0x103235B0
// Name: _dynamic_atexit_destructor_for__g_QuarterSizedFBTexture0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuarterSizedFBTexture0__()
{
  CTextureReference::~CTextureReference(this: &g_QuarterSizedFBTexture0);
}

//------------------------------------------------------------------------------
// Address: 0x103235C0
// Name: _dynamic_atexit_destructor_for__g_QuarterSizedFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuarterSizedFBTexture1__()
{
  CTextureReference::~CTextureReference(this: &g_QuarterSizedFBTexture1);
}

//------------------------------------------------------------------------------
// Address: 0x103235D0
// Name: _dynamic_atexit_destructor_for__g_QuarterSizedFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuarterSizedFBTexture2__()
{
  CTextureReference::~CTextureReference(this: &g_QuarterSizedFBTexture2);
}

//------------------------------------------------------------------------------
// Address: 0x103235E0
// Name: _dynamic_atexit_destructor_for__g_QuarterSizedFBTexture3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuarterSizedFBTexture3__()
{
  CTextureReference::~CTextureReference(this: &g_QuarterSizedFBTexture3);
}

//------------------------------------------------------------------------------
// Address: 0x103235F0
// Name: _dynamic_atexit_destructor_for__g_TeenyFBTexture0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TeenyFBTexture0__()
{
  CTextureReference::~CTextureReference(this: &g_TeenyFBTexture0);
}

//------------------------------------------------------------------------------
// Address: 0x10323600
// Name: _dynamic_atexit_destructor_for__g_TeenyFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TeenyFBTexture1__()
{
  CTextureReference::~CTextureReference(this: &g_TeenyFBTexture1);
}

//------------------------------------------------------------------------------
// Address: 0x10323610
// Name: _dynamic_atexit_destructor_for__g_TeenyFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TeenyFBTexture2__()
{
  CTextureReference::~CTextureReference(this: &g_TeenyFBTexture2);
}

//------------------------------------------------------------------------------
// Address: 0x10323620
// Name: _dynamic_atexit_destructor_for__g_FullFrameFBTexture0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FullFrameFBTexture0__()
{
  CTextureReference::~CTextureReference(this: &g_FullFrameFBTexture0);
}

//------------------------------------------------------------------------------
// Address: 0x10323630
// Name: _dynamic_atexit_destructor_for__g_FullFrameFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FullFrameFBTexture1__()
{
  CTextureReference::~CTextureReference(this: &g_FullFrameFBTexture1);
}

//------------------------------------------------------------------------------
// Address: 0x10323640
// Name: _dynamic_atexit_destructor_for__g_FullFrameFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FullFrameFBTexture2__()
{
  CTextureReference::~CTextureReference(this: &g_FullFrameFBTexture2);
}

//------------------------------------------------------------------------------
// Address: 0x10323650
// Name: _dynamic_atexit_destructor_for__g_FullFrameDepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FullFrameDepth__()
{
  CTextureReference::~CTextureReference(this: &g_FullFrameDepth);
}

//------------------------------------------------------------------------------
// Address: 0x10323870
// Name: _dynamic_atexit_destructor_for__g_Meshes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Meshes__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_Meshes);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100E4CE0
// Name: NukeModeSwitchSaveGames
// Source: json
//------------------------------------------------------------------------------
int NukeModeSwitchSaveGames()
{
  int result; // eax

  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: "SAVE\\modeswitchsave.sav", a3: nullptr) )
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: "SAVE\\modeswitchsave.sav", a3: nullptr);
  result = ((int (__thiscall *)(IBaseFileSystem *, const char *, _DWORD))g_pFileSystem->FileExists)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: "SAVE\\modeswitchsave.tga",
             a3: 0);
  if ( (_BYTE)result != 0 )
    return ((int (__thiscall *)(IFileSystem *, const char *, _DWORD))g_pFileSystem->RemoveFile)(
             a1: g_pFileSystem,
             a2: "SAVE\\modeswitchsave.tga",
             a3: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E4D50
// Name: void mat_hdr_level_Callback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_hdr_level_Callback()
{
  vgui::CTreeViewListControl *v0; // ecx
  ECommandTarget_t TraceType; // eax

  if ( g_pMaterialSystemHardwareConfig->GetHardwareHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE
    && saverestore->IsValidSave(this: saverestore) != 0
    && modelloader->LastLoadedMapHasHDRLighting(this: modelloader)
    && CBaseServer::GetMaxClients(this: &sv) == 1
    && !sv.m_bIsLevelMainMenuBackground )
  {
    NukeModeSwitchSaveGames();
    TraceType = CTraceFilter::GetTraceType(this: v0);
    Cbuf_AddText(eTarget: TraceType, pText: "save modeswitchsave;wait;load modeswitchsave\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4DC0
// Name: bool MaterialConfigLightingChanged(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MaterialConfigLightingChanged()
{
  return s_bConfigLightingChanged;
}

//------------------------------------------------------------------------------
// Address: 0x100E4DD0
// Name: void ClearMaterialConfigLightingChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearMaterialConfigLightingChanged()
{
  s_bConfigLightingChanged = false;
}

//------------------------------------------------------------------------------
// Address: 0x100E4DE0
// Name: int GetScreenAspectMode(int,int)
// Source: json
//------------------------------------------------------------------------------
AspectRatioMode_t __cdecl GetScreenAspectMode(int width, int height)
{
  double v2; // st7
  AspectRatioMode_t m_Mode; // ecx
  double v4; // st7
  long double v5; // st6
  long double v6; // st6
  long double v7; // st6
  AspectRatioMode_t result; // eax
  float closestAspectRatioDist; // [esp+8h] [ebp+8h]

  v2 = (double)width;
  m_Mode = ASPECT_RATIO_4x3;
  closestAspectRatioDist = 99999.0;
  v4 = v2 / (double)height;
  v5 = fabs(flt_10416628 - v4);
  if ( v5 < 99999.0 )
  {
    m_Mode = g_RatioToAspectModes[0].m_Mode;
    closestAspectRatioDist = v5;
  }
  v6 = fabs(flt_10416630 - v4);
  if ( closestAspectRatioDist > v6 )
  {
    m_Mode = dword_1041662C;
    closestAspectRatioDist = v6;
  }
  v7 = fabs(flt_10416638 - v4);
  if ( closestAspectRatioDist > v7 )
  {
    m_Mode = dword_10416634;
    closestAspectRatioDist = v7;
  }
  result = dword_1041663C;
  if ( closestAspectRatioDist <= fabs(flt_10416640 - v4) )
    return m_Mode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E4E90
// Name: void UpdateMaterialSystemConfig(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl UpdateMaterialSystemConfig()
{
  V_FileBase(in: com_gamedir, out: gamedir_2, maxlen: 260);
  if ( host_state.worldbrush != nullptr
    && host_state.worldbrush->lightdata == nullptr
    && _V_stricmp(s1: gamedir_2, s2: "infested") != 0 )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_fullbright.IConVar, value: 1);
  }
  if ( materials->UpdateConfig(this: materials, a2: false) )
    s_bConfigLightingChanged = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E4F00
// Name: CreateWaterReflectionTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl CreateWaterReflectionTexture()
{
  int v0; // eax
  int v1; // eax
  IMaterialSystem_vtbl *v2; // edi
  int v3; // esi
  int v4; // eax

  v0 = _CommandLine();
  v1 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v0 + 28))(
         a1: v0,
         a2: "-reflectionTextureSize",
         a3: 1024);
  v2 = materials->__vftable;
  v3 = v1;
  v4 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int))materials->GetBackBufferFormat)(
         a1: materials,
         a2: 0,
         a3: 12,
         a4: 1);
  return ((ITexture *(__thiscall *)(IMaterialSystem *, const char *, int, int, int, int))v2->CreateNamedRenderTargetTextureEx2)(
           a1: materials,
           a2: "_rt_WaterReflection",
           a3: v3,
           a4: v3,
           a5: 2,
           a6: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100E4F50
// Name: CreateCameraTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl CreateCameraTexture()
{
  int v0; // eax
  int v1; // eax
  IMaterialSystem_vtbl *v2; // edi
  int v3; // esi
  int v4; // eax

  v0 = _CommandLine();
  v1 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v0 + 28))(a1: v0, a2: "-monitorTextureSize", a3: 256);
  v2 = materials->__vftable;
  v3 = v1;
  v4 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, _DWORD, int))materials->GetBackBufferFormat)(
         a1: materials,
         a2: 0,
         a3: 0,
         a4: 1);
  return ((ITexture *(__thiscall *)(IMaterialSystem *, const char *, int, int, int, int))v2->CreateNamedRenderTargetTextureEx2)(
           a1: materials,
           a2: "_rt_Camera",
           a3: v3,
           a4: v3,
           a5: 1,
           a6: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100E4FA0
// Name: CreateQuarterSizedFBTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__usercall CreateQuarterSizedFBTexture@<eax>(int n@<eax>, unsigned int iRenderTargetFlags)
{
  ImageFormat v2; // esi
  char nbuf[20]; // [esp+4h] [ebp-14h] BYREF

  sprintf(string: nbuf, format: "_rt_SmallFB%d", n);
  v2 = materials->GetBackBufferFormat(this: materials);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT )
    v2 = IMAGE_FORMAT_RGBA16161616F;
  return materials->CreateNamedRenderTargetTextureEx2(
           this: materials,
           a2: nbuf,
           a3: 0,
           a4: 0,
           a5: RT_SIZE_HDR,
           a6: v2,
           a7: MATERIAL_RT_DEPTH_SHARED,
           a8: 12u,
           a9: iRenderTargetFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100E5010
// Name: CreateTeenyFBTexture
// Source: json
//------------------------------------------------------------------------------
ITexture *__usercall CreateTeenyFBTexture@<eax>(int n@<eax>)
{
  ImageFormat v1; // esi
  char nbuf[20]; // [esp+4h] [ebp-14h] BYREF

  sprintf(string: nbuf, format: "_rt_TeenyFB%d", n);
  v1 = materials->GetBackBufferFormat(this: materials);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT )
    v1 = IMAGE_FORMAT_RGBA16161616F;
  return materials->CreateNamedRenderTargetTextureEx2(
           this: materials,
           a2: nbuf,
           a3: 32,
           a4: 32,
           a5: RT_SIZE_DEFAULT,
           a6: v1,
           a7: MATERIAL_RT_DEPTH_SHARED,
           a8: 12u,
           a9: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100E5080
// Name: mat_info
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_info()
{
  materials->SpewDriverInfo(this: materials);
}

//------------------------------------------------------------------------------
// Address: 0x100E5090
// Name: void TangentSpaceComputeBasis(class Vector __near &,class Vector __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TangentSpaceComputeBasis(
        Vector *tangentS,
        Vector *tangentT,
        const Vector *normal,
        const Vector *tVect,
        bool negateTangent)
{
  tangentS->x = (float)(tVect->z * normal->y) - (float)(normal->z * tVect->y);
  tangentS->y = (float)(normal->z * tVect->x) - (float)(normal->x * tVect->z);
  tangentS->z = (float)(normal->x * tVect->y) - (float)(tVect->x * normal->y);
  VectorNormalize(vec: tangentS);
  tangentT->x = (float)(tangentS->y * normal->z) - (float)(tangentS->z * normal->y);
  tangentT->y = (float)(normal->x * tangentS->z) - (float)(normal->z * tangentS->x);
  tangentT->z = (float)(tangentS->x * normal->y) - (float)(tangentS->y * normal->x);
  VectorNormalize(vec: tangentT);
  if ( negateTangent )
  {
    tangentS->x = tangentS->x * -1.0;
    tangentS->y = tangentS->y * -1.0;
    tangentS->z = tangentS->z * -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E51A0
// Name: void SetTexInfoBaseTexture2Flags(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetTexInfoBaseTexture2Flags()
{
  worldbrushdata_t *worldbrush; // eax
  int v1; // ecx
  int v2; // edx
  mtexinfo_t *v3; // ebx
  IMaterial *material; // esi
  int v5; // edi
  int v6; // eax
  int v7; // esi
  const char *v8; // eax
  int nParms; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  v1 = 0;
  if ( host_state.worldbrush->numtexinfo > 0 )
  {
    v2 = 0;
    do
    {
      worldbrush->texinfo[v2].texinfoFlags &= ~1u;
      worldbrush = host_state.worldbrush;
      ++v1;
      ++v2;
    }
    while ( v1 < host_state.worldbrush->numtexinfo );
  }
  i = 0;
  if ( worldbrush->numtexinfo > 0 )
  {
    v11 = 0;
    do
    {
      v3 = &worldbrush->texinfo[v11];
      material = v3->material;
      if ( material != nullptr )
      {
        v5 = (int)material->GetShaderParams(this: v3->material);
        v6 = material->ShaderParamCount(this: material);
        v7 = 0;
        nParms = v6;
        if ( v6 > 0 )
        {
          while ( 1 )
          {
            if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v5 + 4 * v7) + 72))(a1: *(_DWORD *)(v5 + 4 * v7)) != 0 )
            {
              v8 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v5 + 4 * v7) + 8))(a1: *(_DWORD *)(v5 + 4 * v7));
              if ( _V_stricmp(s1: v8, s2: "$basetexture2") == 0 )
                break;
            }
            if ( ++v7 >= nParms )
              goto LABEL_13;
          }
          v3->texinfoFlags |= 1u;
        }
LABEL_13:
        worldbrush = host_state.worldbrush;
      }
      ++v11;
      ++i;
    }
    while ( i < worldbrush->numtexinfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5280
// Name: ReadMaterialSystemConfigFromRegistry
// Source: json
//------------------------------------------------------------------------------
void __usercall ReadMaterialSystemConfigFromRegistry(MaterialSystem_Config_t *config@<edi>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *Key; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
  {
    v2 = KeyValues::KeyValues(this: v1, setName: "VideoConfig");
    v3 = v2;
    if ( v2 != nullptr )
    {
      if ( !ReadCurrentVideoConfig(pConfigKeys: v2, bDefault: false) )
      {
        KeyValues::deleteThis(this: v3);
        return;
      }
      Key = KeyValues::FindKey(this: v3, keyName: "setting.defaultres", bCreate: false);
      if ( Key != nullptr )
        config->m_VideoMode.m_Width = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
      v5 = KeyValues::FindKey(this: v3, keyName: "setting.defaultresheight", bCreate: false);
      if ( v5 != nullptr )
        config->m_VideoMode.m_Height = KeyValues::GetInt(this: v5, keyName: nullptr, defaultValue: 0);
      v6 = KeyValues::FindKey(this: v3, keyName: "setting.fullscreen", bCreate: false);
      if ( v6 != nullptr )
      {
        if ( KeyValues::GetInt(this: v6, keyName: nullptr, defaultValue: 0) != 0 )
          config->m_Flags &= ~1u;
        else
          config->m_Flags |= 1u;
      }
      v7 = KeyValues::FindKey(this: v3, keyName: "setting.nowindowborder", bCreate: false);
      if ( v7 != nullptr )
      {
        if ( KeyValues::GetInt(this: v7, keyName: nullptr, defaultValue: 0) != 0 )
        {
          config->m_Flags |= 0x20000u;
          UpdateVideoConfigConVars(pConfigKeys: v3);
          KeyValues::deleteThis(this: v3);
          return;
        }
        config->m_Flags &= ~0x20000u;
      }
      UpdateVideoConfigConVars(pConfigKeys: v3);
      KeyValues::deleteThis(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5380
// Name: OverrideMaterialSystemConfigFromCommandLine
// Source: json
//------------------------------------------------------------------------------
void __usercall OverrideMaterialSystemConfigFromCommandLine(MaterialSystem_Config_t *config@<esi>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-sw") != 0
    || (v2 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-startwindowed") != 0)
    || (v3 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-windowed") != 0)
    || (v4 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-window") != 0) )
  {
    config->m_Flags |= 1u;
  }
  else
  {
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-full") != 0
      || (v6 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-fullscreen") != 0) )
    {
      config->m_Flags &= ~1u;
    }
  }
  v7 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-width") != 0
    || (v8 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-w") != 0) )
  {
    v9 = _CommandLine();
    config->m_VideoMode.m_Width = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 28))(
                                    a1: v9,
                                    a2: "-width",
                                    a3: config->m_VideoMode.m_Width);
    v10 = _CommandLine();
    config->m_VideoMode.m_Width = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v10 + 28))(
                                    a1: v10,
                                    a2: "-w",
                                    a3: config->m_VideoMode.m_Width);
    v11 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-height") == 0 )
    {
      v12 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-h") == 0 )
        config->m_VideoMode.m_Height = 3 * config->m_VideoMode.m_Width / 4;
    }
  }
  v13 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-height") != 0
    || (v14 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-h") != 0) )
  {
    v15 = _CommandLine();
    config->m_VideoMode.m_Height = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 28))(
                                     a1: v15,
                                     a2: "-height",
                                     a3: config->m_VideoMode.m_Height);
    v16 = _CommandLine();
    config->m_VideoMode.m_Height = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v16 + 28))(
                                     a1: v16,
                                     a2: "-h",
                                     a3: config->m_VideoMode.m_Height);
  }
  v17 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v17 + 40))(a1: v17, a2: "-resizing") != 0 )
  {
    v18 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v18 + 12))(a1: v18, a2: "-resizing", a3: 0) != 0 )
      config->m_Flags |= 2u;
    else
      config->m_Flags &= ~2u;
  }
  v19 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v19 + 40))(a1: v19, a2: "-mat_vsync") != 0 )
  {
    v20 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v20 + 28))(a1: v20, a2: "-mat_vsync", a3: 1) != 0 )
      config->m_Flags &= ~8u;
    else
      config->m_Flags |= 8u;
  }
  v21 = _CommandLine();
  config->m_nAASamples = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v21 + 28))(
                           a1: v21,
                           a2: "-mat_antialias",
                           a3: config->m_nAASamples);
  v22 = _CommandLine();
  config->m_nAAQuality = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v22 + 28))(
                           a1: v22,
                           a2: "-mat_aaquality",
                           a3: config->m_nAAQuality);
  v23 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v23 + 40))(a1: v23, a2: "-safe") != 0 )
  {
    config->m_Flags |= 1u;
    config->m_VideoMode.m_Width = 640;
    config->m_VideoMode.m_Height = 480;
    config->m_VideoMode.m_RefreshRate = 0;
    config->m_nAASamples = 0;
    config->m_nAAQuality = 0;
    config->m_bWantTripleBuffered = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E55C0
// Name: mat_setvideomode
// Source: json
//------------------------------------------------------------------------------
void __usercall mat_setvideomode(int a1@<ebx>, int a2@<edi>, const CCommand *args)
{
  const char *v3; // eax
  int v4; // ebx
  const char *v5; // eax
  int v6; // edi
  const char *v7; // eax
  const char *v8; // esi

  if ( args->m_nArgc >= 4 )
  {
    v3 = defaultValue;
    if ( args->m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = V_atoi(str: v3);
    v5 = defaultValue;
    if ( args->m_nArgc > 2 )
      v5 = args->m_ppArgv[2];
    v6 = V_atoi(str: v5);
    v7 = defaultValue;
    if ( args->m_nArgc > 3 )
      v7 = args->m_ppArgv[3];
    V_atoi(str: v7);
    ((void (__thiscall *)(IVideoMode *, int, int))videomode->NoWindowBorder)(a1: videomode, a2, a3: a1);
    if ( args->m_nArgc >= 5 )
    {
      if ( args->m_nArgc > 4 )
        v8 = args->m_ppArgv[4];
      else
        v8 = defaultValue;
      V_atoi(str: v8);
    }
    ((void (__thiscall *)(IVideoMode *, int, int))videomode->SetMode)(a1: videomode, a2: v4, a3: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5690
// Name: mat_savechanges
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_savechanges()
{
  int v0; // eax
  int m_Width; // esi
  AspectRatioMode_t ScreenAspectMode; // eax
  int v3; // edx
  bool v4; // [esp-8h] [ebp-Ch]
  bool v5; // [esp-4h] [ebp-8h]

  v0 = _CommandLine();
  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 16))(a1: v0, a2: "-safe");
  UpdateMaterialSystemConfig();
  m_Width = g_pMaterialSystemConfig->m_VideoMode.m_Width;
  v5 = (g_pMaterialSystemConfig->m_Flags & 0x20000) != 0;
  v4 = (g_pMaterialSystemConfig->m_Flags & 1) == 0;
  ScreenAspectMode = GetScreenAspectMode(
                       width: g_pMaterialSystemConfig->m_VideoMode.m_Width,
                       height: g_pMaterialSystemConfig->m_VideoMode.m_Height);
  UpdateCurrentVideoConfig(
    nWidth: m_Width,
    nHeight: v3,
    nAspectRatioMode: ScreenAspectMode,
    bFullscreen: v4,
    bNoWindow: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100E56F0
// Name: mat_debug
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_debug(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    materials->ToggleDebugMaterial(this: materials, a2: args->m_ppArgv[1]);
  else
    ConMsg(a1: "usage: mat_debug [ <material name> ]\n");
}

//------------------------------------------------------------------------------
// Address: 0x100E5730
// Name: mat_suppress
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_suppress(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    materials->ToggleSuppressMaterial(this: materials, a2: args->m_ppArgv[1]);
  else
    ConMsg(a1: "usage: mat_suppress [ <material name> ]\n");
}

//------------------------------------------------------------------------------
// Address: 0x100E5770
// Name: bool TangentSpaceSurfaceSetup(struct msurface2_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TangentSpaceSurfaceSetup(msurface2_t *surfID, Vector *tVect)
{
  mtexinfo_t *texinfo; // eax
  int v3; // ecx
  mtexinfo_t *v4; // eax
  double x; // st7
  int v6; // eax
  Vector sVect; // [esp+8h] [ebp-Ch] BYREF

  texinfo = host_state.worldbrush->texinfo;
  v3 = *((unsigned __int16 *)surfID + 11) >> 1;
  sVect.x = texinfo[*((unsigned __int16 *)surfID + 11) >> 1].textureVecsTexelsPerWorldUnits[0].x;
  sVect.y = texinfo[v3].textureVecsTexelsPerWorldUnits[0].y;
  sVect.z = texinfo[v3].textureVecsTexelsPerWorldUnits[0].z;
  v4 = host_state.worldbrush->texinfo;
  x = v4[v3].textureVecsTexelsPerWorldUnits[1].x;
  v6 = (int)&v4[v3].textureVecsTexelsPerWorldUnits[1];
  tVect->x = x;
  tVect->y = *(float *)(v6 + 4);
  tVect->z = *(float *)(v6 + 8);
  VectorNormalize(vec: &sVect);
  VectorNormalize(vec: tVect);
  return (float)((float)((float)(surfID->plane->normal.y
                               * (float)((float)(tVect->x * sVect.z) - (float)(tVect->z * sVect.x)))
                       + (float)(surfID->plane->normal.x
                               * (float)((float)(tVect->z * sVect.y) - (float)(tVect->y * sVect.z))))
               + (float)(surfID->plane->normal.z * (float)((float)(tVect->y * sVect.x) - (float)(tVect->x * sVect.y)))) > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E5860
// Name: void SurfComputeTextureCoordinate(struct msurface2_t __near *,class Vector const __near &,float restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SurfComputeTextureCoordinate(msurface2_t *surfID, const Vector *vec, float *pUV)
{
  mtexinfo_t *v3; // esi
  float v4; // xmm1_4
  float u; // [esp+10h] [ebp+8h]
  float ua; // [esp+10h] [ebp+8h]
  float v; // [esp+14h] [ebp+Ch]

  v3 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  u = (float)((float)((float)(v3->textureVecsTexelsPerWorldUnits[0].y * vec->y)
                    + (float)(v3->textureVecsTexelsPerWorldUnits[0].x * vec->x))
            + (float)(v3->textureVecsTexelsPerWorldUnits[0].z * vec->z))
    + v3->textureVecsTexelsPerWorldUnits[0].w;
  ua = u / (float)v3->material->GetMappingWidth(this: v3->material);
  v = (float)((float)((float)(v3->textureVecsTexelsPerWorldUnits[1].y * vec->y)
                    + (float)(vec->x * v3->textureVecsTexelsPerWorldUnits[1].x))
            + (float)(v3->textureVecsTexelsPerWorldUnits[1].z * vec->z))
    + v3->textureVecsTexelsPerWorldUnits[1].w;
  v4 = (float)v3->material->GetMappingHeight(this: v3->material);
  *pUV = ua;
  pUV[1] = v / v4;
}

//------------------------------------------------------------------------------
// Address: 0x100E5930
// Name: void SurfComputeLightmapCoordinate(struct SurfaceCtx_t const __near &,struct msurface2_t __near *,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SurfComputeLightmapCoordinate(
        const SurfaceCtx_t *ctx,
        msurface2_t *surfID,
        const Vector *vec,
        Vector2D *uv)
{
  Vector2D *v4; // eax
  int x_low; // xmm0_4
  float y; // xmm0_4
  float v7; // xmm0_4
  float *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4

  if ( (surfID->flags & 1) != 0 )
  {
    v4 = uv;
    uv->y = 0.5;
    uv->x = 0.5;
LABEL_3:
    x_low = LODWORD(v4->x);
    goto LABEL_4;
  }
  v4 = uv;
  if ( *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) != 0 )
  {
    v8 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
    v9 = (float)((float)((float)(v8[9] * vec->y) + (float)(v8[8] * vec->x)) + (float)(v8[10] * vec->z)) + v8[11];
    uv->x = v9;
    uv->x = (float)(v9
                  - (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
          + 0.5;
    v10 = (float)((float)((float)(v8[13] * vec->y) + (float)(vec->x * v8[12])) + (float)(v8[14] * vec->z)) + v8[15];
    uv->y = v10;
    uv->y = (float)(v10
                  - (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
          + 0.5;
    uv->x = ctx->m_Scale.x * uv->x;
    uv->y = ctx->m_Scale.y * uv->y;
    uv->x = ctx->m_Offset.x + uv->x;
    v7 = ctx->m_Offset.y + uv->y;
  }
  else
  {
    v7 = ctx->m_Offset.y + (float)(ctx->m_Scale.y * 0.5);
    uv->x = ctx->m_Offset.x + (float)(ctx->m_Scale.x * 0.5);
  }
  uv->y = v7;
  if ( uv->x >= 0.0 )
  {
    if ( uv->x <= 1.0 )
      goto LABEL_3;
    x_low = 1065353216;
  }
  else
  {
    x_low = 0;
  }
LABEL_4:
  LODWORD(v4->x) = x_low;
  y = v4->y;
  if ( y >= 0.0 )
  {
    if ( y > 1.0 )
      y = 1.0;
    v4->y = y;
  }
  else
  {
    v4->y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5B20
// Name: void SurfSetupSurfaceContext(struct SurfaceCtx_t __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SurfSetupSurfaceContext(SurfaceCtx_t *ctx, msurface2_t *surfID)
{
  int v2; // eax
  __m128i v3; // xmm2
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  IMaterialSystem_vtbl *v7; // [esp+Ch] [ebp-4h]

  v7 = materials->__vftable;
  v2 = SortInfoToLightmapPage(sortID: surfID->materialSortID);
  v7->GetLightmapPageSize(this: materials, a2: v2, a3: ctx->m_LightmapPageSize, a4: &ctx->m_LightmapPageSize[1]);
  v3 = _mm_cvtsi32_si128(ctx->m_LightmapPageSize[0]);
  v4 = (float)ctx->m_LightmapPageSize[1];
  ctx->m_LightmapSize[0] = *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                         + 1;
  v5 = _mm_cvtepi32_ps(v3).m128_f32[0];
  ctx->m_LightmapSize[1] = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                         + 1;
  ctx->m_Scale.y = 1.0 / v4;
  ctx->m_Scale.x = 1.0 / v5;
  ctx->m_Offset.x = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                  * (float)(1.0 / v5);
  ctx->m_Offset.y = (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
                                      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                  * (float)(1.0 / v4);
  v6 = 0.0;
  if ( v5 != 0.0 )
    v6 = (float)ctx->m_LightmapSize[0] / v5;
  ctx->m_BumpSTexCoordOffset = v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E5C40
// Name: void OverrideMaterialSystemConfig(struct MaterialSystem_Config_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverrideMaterialSystemConfig(MaterialSystem_Config_t *config)
{
  const char *ModDirectory; // esi
  ConVarRef mat_supportflashlight; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &mat_supportflashlight, pName: "mat_supportflashlight");
  if ( mat_supportflashlight.m_pConVarState->m_Value.m_nValue == -1 )
  {
    ModDirectory = COM_GetModDirectory();
    if ( _V_stricmp(s1: ModDirectory, s2: "portal") != 0 && _V_stricmp(s1: ModDirectory, s2: "tf") != 0 )
      mat_supportflashlight.m_pConVar->SetValue_2(this: mat_supportflashlight.m_pConVar, a2: 1);
    else
      mat_supportflashlight.m_pConVar->SetValue_2(this: mat_supportflashlight.m_pConVar, a2: 0);
  }
  config->m_bSupportFlashlight = mat_supportflashlight.m_pConVarState->m_Value.m_nValue != 0;
  if ( materials->OverrideConfig(this: materials, a2: config, a3: false) )
    s_bConfigLightingChanged = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E5CD0
// Name: void InitMaterialSystemConfig(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMaterialSystemConfig(bool bInEditMode)
{
  const MaterialSystem_Config_t *v1; // eax
  int v2; // eax
  int m_nValue; // eax
  MaterialSystem_Config_t config; // [esp+0h] [ebp-64h] BYREF

  v1 = materials->GetCurrentConfigForVideoCard(this: materials);
  g_pMaterialSystemConfig = v1;
  if ( v1 == nullptr )
  {
    Sys_Error(error: "Could not get the material system config record!");
    v1 = g_pMaterialSystemConfig;
  }
  if ( !bInEditMode )
  {
    config = *v1;
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-autoconfig") != 0 )
      ResetVideoConfigToDefaults(pConfigKeys: nullptr);
    ReadMaterialSystemConfigFromRegistry(&config);
    OverrideMaterialSystemConfigFromCommandLine(&config);
    OverrideMaterialSystemConfig(&config);
    if ( mat_hdr_level.m_pParent != nullptr )
      m_nValue = mat_hdr_level.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    g_pMaterialSystemHardwareConfig->SetHDREnabled(this: g_pMaterialSystemHardwareConfig, a2: m_nValue >= 2);
    UpdateMaterialSystemConfig();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E5D90
// Name: void GetMaterialSystemConfigForBenchmarkUpload(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialSystemConfigForBenchmarkUpload(KeyValues *dataToUpload)
{
  IMaterialSystem_vtbl *v1; // esi
  int v2; // eax
  int Ram; // eax
  int CPUInformation; // edi
  int m_nValue; // eax
  int v6; // eax
  MaterialAdapterInfo_t driverInfo; // [esp+8h] [ebp-224h] BYREF

  v1 = materials->__vftable;
  v2 = ((int (__thiscall *)(IMaterialSystem *, MaterialAdapterInfo_t *))materials->GetCurrentAdapter)(
         a1: materials,
         a2: &driverInfo);
  ((void (__thiscall *)(IMaterialSystem *, int))v1->GetDisplayAdapterInfo)(a1: materials, a2: v2);
  KeyValues::SetInt(this: dataToUpload, keyName: "vendorID", value: driverInfo.m_VendorID);
  KeyValues::SetInt(this: dataToUpload, keyName: "deviceID", value: driverInfo.m_DeviceID);
  Ram = GetRam();
  KeyValues::SetInt(this: dataToUpload, keyName: "ram", value: Ram);
  CPUInformation = _GetCPUInformation();
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "cpu_speed",
    value: (int)((double)*(__int64 *)(CPUInformation + 8) * 0.000001));
  KeyValues::SetString(this: dataToUpload, keyName: "cpu", value: *(const char **)(CPUInformation + 16));
  KeyValues::SetInt(this: dataToUpload, keyName: "width", value: g_pMaterialSystemConfig->m_VideoMode.m_Width);
  KeyValues::SetInt(this: dataToUpload, keyName: "height", value: g_pMaterialSystemConfig->m_VideoMode.m_Height);
  KeyValues::SetInt(this: dataToUpload, keyName: "AASamples", value: g_pMaterialSystemConfig->m_nAASamples);
  KeyValues::SetInt(this: dataToUpload, keyName: "AAQuality", value: g_pMaterialSystemConfig->m_nAAQuality);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "TripleBuffered",
    value: g_pMaterialSystemConfig->m_bWantTripleBuffered);
  KeyValues::SetInt(this: dataToUpload, keyName: "AnisoLevel", value: g_pMaterialSystemConfig->m_nForceAnisotropicLevel);
  KeyValues::SetInt(this: dataToUpload, keyName: "SkipMipLevels", value: g_pMaterialSystemConfig->skipMipLevels);
  KeyValues::SetInt(this: dataToUpload, keyName: "DXLevel", value: g_pMaterialSystemConfig->dxSupportLevel);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "ShadowDepthTexture",
    value: g_pMaterialSystemConfig->m_bShadowDepthTexture);
  KeyValues::SetInt(this: dataToUpload, keyName: "MotionBlur", value: g_pMaterialSystemConfig->m_bMotionBlur);
  KeyValues::SetInt(this: dataToUpload, keyName: "Windowed", value: g_pMaterialSystemConfig->m_Flags & 1);
  KeyValues::SetInt(this: dataToUpload, keyName: "NoWaitForVSync", value: (g_pMaterialSystemConfig->m_Flags & 8) != 0);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "DisableSpecular",
    value: (g_pMaterialSystemConfig->m_Flags & 0x80) != 0);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "DisableBumpmapping",
    value: (g_pMaterialSystemConfig->m_Flags & 0x100) != 0);
  KeyValues::SetInt(
    this: dataToUpload,
    keyName: "EnableParallaxMapping",
    value: (g_pMaterialSystemConfig->m_Flags & 0x200) != 0);
  KeyValues::SetInt(this: dataToUpload, keyName: "ZPrefill", value: (g_pMaterialSystemConfig->m_Flags & 0x400) != 0);
  if ( r_shadowrendertotexture.m_pParent != nullptr )
    m_nValue = r_shadowrendertotexture.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  KeyValues::SetInt(this: dataToUpload, keyName: "RenderToTextureShadows", value: m_nValue != 0);
  if ( r_flashlightdepthtexture.m_pParent != nullptr )
    v6 = r_flashlightdepthtexture.m_pParent->m_Value.m_nValue;
  else
    v6 = 0;
  KeyValues::SetInt(this: dataToUpload, keyName: "FlashlightDepthTexture", value: v6 != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100E6000
// Name: void PrintMaterialSystemConfig(struct MaterialSystem_Config_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintMaterialSystemConfig(const MaterialSystem_Config_t *config)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax

  _Warning(a1: "width: %d\n", config->m_VideoMode.m_Width);
  _Warning(a1: "height: %d\n", config->m_VideoMode.m_Height);
  _Warning(a1: "m_nForceAnisotropicLevel: %d\n", config->m_nForceAnisotropicLevel);
  _Warning(a1: "aasamples: %d\n", config->m_nAASamples);
  _Warning(a1: "aaquality: %d\n", config->m_nAAQuality);
  v1 = "true";
  if ( !config->m_bWantTripleBuffered )
    v1 = "false";
  _Warning(a1: "tripleBuffered: %s\n", v1);
  _Warning(a1: "skipMipLevels: %d\n", config->skipMipLevels);
  _Warning(a1: "dxSupportLevel: %d\n", config->dxSupportLevel);
  _Warning(a1: "monitorGamma: %f\n", config->m_fMonitorGamma);
  v2 = "true";
  if ( (config->m_Flags & 1) == 0 )
    v2 = "false";
  _Warning(a1: "MATSYS_VIDCFG_FLAGS_WINDOWED: %s\n", v2);
  v3 = "true";
  if ( SLOBYTE(config->m_Flags) >= 0 )
    v3 = "false";
  _Warning(a1: "MATSYS_VIDCFG_FLAGS_DISABLE_SPECULAR: %s\n", v3);
  v4 = "true";
  if ( (config->m_Flags & 0x200) == 0 )
    v4 = "false";
  _Warning(a1: "MATSYS_VIDCFG_FLAGS_ENABLE_PARALLAX_MAPPING: %s\n", v4);
  v5 = "true";
  if ( (config->m_Flags & 0x400) == 0 )
    v5 = "false";
  _Warning(a1: "MATSYS_VIDCFG_FLAGS_USE_Z_PREFILL: %s\n", v5);
  if ( r_shadowrendertotexture.m_pParent == nullptr
    || (v6 = "true", r_shadowrendertotexture.m_pParent->m_Value.m_nValue == 0) )
  {
    v6 = "false";
  }
  _Warning(a1: "r_shadowrendertotexture: %s\n", v6);
  v7 = "true";
  if ( !config->m_bMotionBlur )
    v7 = "false";
  _Warning(a1: "motionblur: %s\n", v7);
  v8 = "true";
  if ( !config->m_bShadowDepthTexture )
    v8 = "false";
  _Warning(a1: "shadowdepthtexture: %s\n", v8);
}

//------------------------------------------------------------------------------
// Address: 0x100E6160
// Name: mat_configcurrent
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_configcurrent()
{
  const MaterialSystem_Config_t *v0; // eax

  v0 = materials->GetCurrentConfigForVideoCard(this: materials);
  PrintMaterialSystemConfig(config: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100E6180
// Name: InitDebugMaterials
// Source: json
//------------------------------------------------------------------------------
int __usercall InitDebugMaterials@<eax>(int a1@<esi>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  KeyValues *v7; // eax
  KeyValues *v8; // esi

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: InitDebugMaterials\n");
  g_materialEmpty = GL_LoadMaterial(pName: "debug/debugempty", pTextureGroupName: "Other textures", bPrecache: false);
  g_materialWireframe = GL_LoadMaterial(
                          pName: "debug/debugwireframe",
                          pTextureGroupName: "Other textures",
                          bPrecache: false);
  g_materialTranslucentSingleColor = GL_LoadMaterial(
                                       pName: "debug/debugtranslucentsinglecolor",
                                       pTextureGroupName: "Other textures",
                                       bPrecache: false);
  g_materialTranslucentVertexColor = GL_LoadMaterial(
                                       pName: "debug/debugtranslucentvertexcolor",
                                       pTextureGroupName: "Other textures",
                                       bPrecache: false);
  g_materialWorldWireframe = GL_LoadMaterial(
                               pName: "debug/debugworldwireframe",
                               pTextureGroupName: "Other textures",
                               bPrecache: false);
  g_materialWorldWireframeZBuffer = GL_LoadMaterial(
                                      pName: "debug/debugworldwireframezbuffer",
                                      pTextureGroupName: "Other textures",
                                      bPrecache: false);
  g_materialBrushWireframe = GL_LoadMaterial(
                               pName: "debug/debugbrushwireframe",
                               pTextureGroupName: "Other textures",
                               bPrecache: false);
  g_materialDecalWireframe = GL_LoadMaterial(
                               pName: "debug/debugdecalwireframe",
                               pTextureGroupName: "Other textures",
                               bPrecache: false);
  g_materialDebugLightmap = GL_LoadMaterial(
                              pName: "debug/debuglightmap",
                              pTextureGroupName: "Other textures",
                              bPrecache: false);
  g_materialDebugLightmapZBuffer = GL_LoadMaterial(
                                     pName: "debug/debuglightmapzbuffer",
                                     pTextureGroupName: "Other textures",
                                     bPrecache: false);
  g_materialDebugLuxels = GL_LoadMaterial(
                            pName: "debug/debugluxels",
                            pTextureGroupName: "Other textures",
                            bPrecache: false);
  g_materialLeafVisWireframe = GL_LoadMaterial(
                                 pName: "debug/debugleafviswireframe",
                                 pTextureGroupName: "Other textures",
                                 bPrecache: false);
  g_pMaterialWireframeVertexColor = GL_LoadMaterial(
                                      pName: "debug/debugwireframevertexcolor",
                                      pTextureGroupName: "Other textures",
                                      bPrecache: false);
  g_pMaterialWireframeVertexColorIgnoreZ = GL_LoadMaterial(
                                             pName: "debug/debugwireframevertexcolorignorez",
                                             pTextureGroupName: "Other textures",
                                             bPrecache: false);
  g_pMaterialLightSprite = GL_LoadMaterial(
                             pName: "engine/lightsprite",
                             pTextureGroupName: "Other textures",
                             bPrecache: false);
  g_pMaterialShadowBuild = GL_LoadMaterial(
                             pName: "engine/shadowbuild",
                             pTextureGroupName: "Other textures",
                             bPrecache: false);
  g_pMaterialMRMWireframe = GL_LoadMaterial(
                              pName: "debug/debugmrmwireframe",
                              pTextureGroupName: "Other textures",
                              bPrecache: false);
  g_pMaterialDebugFlat = GL_LoadMaterial(
                           pName: "debug/debugdrawflattriangles",
                           pTextureGroupName: "Other textures",
                           bPrecache: false);
  g_pMaterialAmbientCube = GL_LoadMaterial(
                             pName: "debug/debugambientcube",
                             pTextureGroupName: "Other textures",
                             bPrecache: false);
  g_pMaterialWriteZ = GL_LoadMaterial(pName: "engine/writez", pTextureGroupName: "Other textures", bPrecache: false);
  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v2 = KeyValues::KeyValues(this: v1, setName: "DepthWrite");
  else
    v2 = nullptr;
  KeyValues::SetInt(this: v2, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v2, keyName: "$alphatest", value: 0);
  KeyValues::SetInt(this: v2, keyName: "$nocull", value: 0);
  g_pMaterialDepthWrite[0][0] = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, const char *, KeyValues *, int))g_pMaterialSystem->FindProceduralMaterial)(
                                               a1: g_pMaterialSystem,
                                               a2: "__DepthWrite00",
                                               a3: "Other textures",
                                               a4: v2,
                                               a5: a1);
  g_pMaterialDepthWrite[0][0]->IncrementReferenceCount(this: g_pMaterialDepthWrite[0][0]);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "DepthWrite");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v4, keyName: "$alphatest", value: 0);
  KeyValues::SetInt(this: v4, keyName: "$nocull", value: 1);
  dword_105F3008 = (int)g_pMaterialSystem->FindProceduralMaterial(
                          this: g_pMaterialSystem,
                          a2: "__DepthWrite01",
                          a3: "Other textures",
                          a4: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_105F3008 + 48))(a1: dword_105F3008);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "DepthWrite");
  else
    v6 = nullptr;
  KeyValues::SetInt(this: v6, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v6, keyName: "$alphatest", value: 1);
  KeyValues::SetInt(this: v6, keyName: "$nocull", value: 0);
  dword_105F300C = (int)g_pMaterialSystem->FindProceduralMaterial(
                          this: g_pMaterialSystem,
                          a2: "__DepthWrite10",
                          a3: "Other textures",
                          a4: v6);
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_105F300C + 48))(a1: dword_105F300C);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "DepthWrite");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$alphatest", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$nocull", value: 1);
  dword_105F3010 = ((int (__thiscall *)(IMaterialSystem *, const char *, const char *))g_pMaterialSystem->FindProceduralMaterial)(
                     a1: g_pMaterialSystem,
                     a2: "__DepthWrite11",
                     a3: "Other textures");
  return (*(int (__thiscall **)(int))(*(_DWORD *)dword_105F3010 + 48))(a1: dword_105F3010);
}

//------------------------------------------------------------------------------
// Address: 0x100E6530
// Name: ShutdownDebugMaterials
// Source: json
//------------------------------------------------------------------------------
void ShutdownDebugMaterials()
{
  IMaterial **v0; // esi
  int i; // edi

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: ShutdownDebugMaterials\n");
  GL_UnloadMaterial(pMaterial: g_materialEmpty);
  GL_UnloadMaterial(pMaterial: g_pMaterialLightSprite);
  GL_UnloadMaterial(pMaterial: g_pMaterialWireframeVertexColor);
  GL_UnloadMaterial(pMaterial: g_pMaterialWireframeVertexColorIgnoreZ);
  GL_UnloadMaterial(pMaterial: g_materialLeafVisWireframe);
  GL_UnloadMaterial(pMaterial: g_materialDebugLuxels);
  GL_UnloadMaterial(pMaterial: g_materialDebugLightmapZBuffer);
  GL_UnloadMaterial(pMaterial: g_materialDebugLightmap);
  GL_UnloadMaterial(pMaterial: g_materialDecalWireframe);
  GL_UnloadMaterial(pMaterial: g_materialBrushWireframe);
  GL_UnloadMaterial(pMaterial: g_materialWorldWireframeZBuffer);
  GL_UnloadMaterial(pMaterial: g_materialWorldWireframe);
  GL_UnloadMaterial(pMaterial: g_materialTranslucentSingleColor);
  GL_UnloadMaterial(pMaterial: g_materialTranslucentVertexColor);
  GL_UnloadMaterial(pMaterial: g_materialWireframe);
  GL_UnloadMaterial(pMaterial: g_pMaterialShadowBuild);
  GL_UnloadMaterial(pMaterial: g_pMaterialMRMWireframe);
  GL_UnloadMaterial(pMaterial: g_pMaterialWriteZ);
  GL_UnloadMaterial(pMaterial: g_pMaterialAmbientCube);
  GL_UnloadMaterial(pMaterial: g_pMaterialDebugFlat);
  v0 = g_pMaterialDepthWrite[0];
  do
  {
    for ( i = 2; i != 0; --i )
    {
      if ( *v0 != nullptr )
        (*v0)->DecrementReferenceCount(this: *v0);
      *v0++ = nullptr;
    }
  }
  while ( (int)v0 < (int)&g_pMaterialDebugFlat );
}

//------------------------------------------------------------------------------
// Address: 0x100E6670
// Name: void BuildMSurfaceVertexArrays(struct worldbrushdata_t __near *,struct msurface2_t __near *,class CMeshBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfaceVertexArrays(worldbrushdata_t *pBrushData, msurface2_t *surfID, CMeshBuilder *builder)
{
  mvertex_t *v4; // edi
  float *m_pCurrPosition; // eax
  mtexinfo_t *v6; // esi
  IMaterial *material; // ecx
  int (__thiscall *GetMappingWidth)(IMaterial *); // edx
  int v9; // eax
  float v10; // xmm0_4
  IMaterial *v11; // esi
  int (__thiscall *GetMappingHeight)(IMaterial *); // edx
  float v13; // xmm1_4
  float *v14; // eax
  float v15; // xmm0_4
  float x; // xmm0_4
  float *v17; // eax
  Vector *v18; // edi
  float *m_pCurrNormal; // eax
  float z; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float y; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float *v27; // eax
  SurfaceCtx_t ctx; // [esp+4h] [ebp-60h] BYREF
  Vector tVect; // [esp+28h] [ebp-3Ch] BYREF
  Vector tangentT; // [esp+34h] [ebp-30h] BYREF
  Vector tangentS; // [esp+40h] [ebp-24h] BYREF
  Vector2D uv; // [esp+4Ch] [ebp-18h] BYREF
  int vertCount; // [esp+54h] [ebp-10h]
  float v34; // [esp+58h] [ebp-Ch]
  float v35; // [esp+5Ch] [ebp-8h]
  int i; // [esp+60h] [ebp-4h]
  bool negate_3; // [esp+73h] [ebp+Fh]

  SurfSetupSurfaceContext(&ctx, surfID);
  negate_3 = false;
  if ( (surfID->flags & 0x100) != 0 )
    negate_3 = TangentSpaceSurfaceSetup(surfID, &tVect);
  vertCount = HIBYTE(surfID->flags);
  i = 0;
  if ( vertCount != 0 )
  {
    do
    {
      v4 = &pBrushData->vertexes[pBrushData->vertindices[i + surfID->firstvertindex]];
      m_pCurrPosition = builder->m_VertexBuilder.m_pCurrPosition;
      *m_pCurrPosition = v4->position.x;
      m_pCurrPosition[1] = v4->position.y;
      m_pCurrPosition[2] = v4->position.z;
      v6 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
      material = v6->material;
      GetMappingWidth = material->GetMappingWidth;
      v35 = (float)((float)((float)(v6->textureVecsTexelsPerWorldUnits[0].y * v4->position.y)
                          + (float)(v6->textureVecsTexelsPerWorldUnits[0].x * v4->position.x))
                  + (float)(v6->textureVecsTexelsPerWorldUnits[0].z * v4->position.z))
          + v6->textureVecsTexelsPerWorldUnits[0].w;
      v9 = GetMappingWidth(this: material);
      v10 = (float)((float)((float)(v6->textureVecsTexelsPerWorldUnits[1].y * v4->position.y)
                          + (float)(v6->textureVecsTexelsPerWorldUnits[1].x * v4->position.x))
                  + (float)(v6->textureVecsTexelsPerWorldUnits[1].z * v4->position.z))
          + v6->textureVecsTexelsPerWorldUnits[1].w;
      v11 = v6->material;
      GetMappingHeight = v11->GetMappingHeight;
      v35 = v35 / (float)v9;
      v34 = v10;
      uv.x = v35;
      v13 = (float)GetMappingHeight(this: v11);
      v14 = builder->m_VertexBuilder.m_pCurrTexCoord[0];
      v15 = v34 / v13;
      *v14 = v35;
      v14[1] = v15;
      uv.y = v15;
      SurfComputeLightmapCoordinate(&ctx, surfID, vec: &v4->position, &uv);
      x = uv.x;
      *(Vector2D *)builder->m_VertexBuilder.m_pCurrTexCoord[1] = uv;
      if ( (surfID->flags & 8) != 0 )
      {
        if ( (float)((float)(ctx.m_BumpSTexCoordOffset * 3.0) + x) > 1.00001 )
          SurfComputeLightmapCoordinate(&ctx, surfID, vec: &v4->position, &uv);
        v17 = builder->m_VertexBuilder.m_pCurrTexCoord[2];
        *v17 = ctx.m_BumpSTexCoordOffset;
      }
      else
      {
        v17 = builder->m_VertexBuilder.m_pCurrTexCoord[2];
        *v17 = 0.0;
      }
      v17[1] = 0.0;
      v18 = &pBrushData->vertnormals[pBrushData->vertnormalindices[i
                                                                 + host_state.worldbrush->surfacenormals[surfID - host_state.worldbrush->surfaces2].firstvertnormal]];
      m_pCurrNormal = builder->m_VertexBuilder.m_pCurrNormal;
      *m_pCurrNormal = v18->x;
      m_pCurrNormal[1] = v18->y;
      m_pCurrNormal[2] = v18->z;
      if ( (surfID->flags & 0x100) != 0 )
      {
        z = v18->z;
        v21 = v18->y * tVect.x;
        tangentS.x = (float)(v18->y * tVect.z) - (float)(z * tVect.y);
        v22 = (float)(v18->x * tVect.y) - v21;
        tangentS.y = (float)(z * tVect.x) - (float)(v18->x * tVect.z);
        tangentS.z = v22;
        VectorNormalize(vec: &tangentS);
        y = v18->y;
        v24 = v18->z * tangentS.x;
        tangentT.x = (float)(v18->z * tangentS.y) - (float)(y * tangentS.z);
        v25 = v18->x * tangentS.y;
        tangentT.y = (float)(v18->x * tangentS.z) - v24;
        tangentT.z = (float)(y * tangentS.x) - v25;
        VectorNormalize(vec: &tangentT);
        v26 = tangentS.x;
        if ( negate_3 )
        {
          tangentS.y = tangentS.y * -1.0;
          v26 = tangentS.x * -1.0;
          tangentS.z = tangentS.z * -1.0;
        }
        v27 = (float *)((char *)builder->m_VertexBuilder.m_pTangentS
                      + builder->m_VertexBuilder.m_nCurrentVertex * builder->m_VertexBuilder.m_VertexSize_TangentS);
        *v27 = v26;
        v27[1] = tangentS.y;
        v27[2] = tangentS.z;
        *(Vector *)((char *)builder->m_VertexBuilder.m_pTangentT
                  + builder->m_VertexBuilder.m_nCurrentVertex * builder->m_VertexBuilder.m_VertexSize_TangentT) = tangentT;
      }
      if ( (surfID->flags & 0x800) != 0
        || (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].texinfoFlags & 1) == 0 )
      {
        *(_DWORD *)builder->m_VertexBuilder.m_pCurrColor = flatColor_0[2]
                                                         | ((flatColor_0[1]
                                                           | ((flatColor_0[0] | (flatColor_0[3] << 8)) << 8)) << 8);
      }
      else
      {
        *(_DWORD *)builder->m_VertexBuilder.m_pCurrColor = flatColorNoAlpha_0[2]
                                                         | ((flatColorNoAlpha_0[1]
                                                           | ((flatColorNoAlpha_0[0] | (flatColorNoAlpha_0[3] << 8)) << 8)) << 8);
      }
      CVertexBuilder::AdvanceVertex(this: &builder->m_VertexBuilder);
      ++i;
    }
    while ( i < vertCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E6A90
// Name: void InitWellKnownRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitWellKnownRenderTargets(int a1@<esi>)
{
  ITexture *v1; // eax
  ITexture *v2; // eax
  ITexture *QuarterSizedFBTexture; // eax
  ITexture *v4; // eax
  ITexture *TeenyFBTexture; // eax
  ITexture *v6; // eax
  ITexture *v7; // eax
  IMaterialSystem_vtbl *v8; // esi
  int v9; // eax
  ITexture *v10; // eax
  IMaterialSystem_vtbl *v11; // esi
  int v12; // eax
  ITexture *v13; // eax
  ITexture *WaterReflectionTexture; // eax
  int v15; // eax
  int v16; // eax
  ITexture *v17; // eax
  ITexture *CameraTexture; // eax
  IMatRenderContext *v19; // eax
  IMatRenderContext *v20; // esi
  char dest[256]; // [esp+0h] [ebp-100h] BYREF

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: InitWellKnownRenderTargets\n");
  materials->BeginRenderTargetAllocation(this: materials);
  v1 = materials->CreateNamedRenderTargetTextureEx2(
         this: materials,
         a2: "_rt_PowerOfTwoFB",
         a3: 1024,
         a4: 1024,
         a5: 1,
         a6: 0,
         a7: 0,
         a8: 12,
         a9: 1);
  CTextureReference::Init(this: &g_PowerOfTwoFBTexture, pTexture: v1);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT )
  {
    v2 = materials->CreateNamedRenderTargetTextureEx2(
           this: materials,
           a2: "_rt_BuildCubemaps16bit",
           a3: 0,
           a4: 0,
           a5: 4,
           a6: 25,
           a7: 0,
           a8: 12,
           a9: 0);
    CTextureReference::Init(this: &g_BuildCubemaps16BitTexture, pTexture: v2);
  }
  QuarterSizedFBTexture = CreateQuarterSizedFBTexture(n: 0, iRenderTargetFlags: 0);
  CTextureReference::Init(this: &g_QuarterSizedFBTexture0, pTexture: QuarterSizedFBTexture);
  v4 = CreateQuarterSizedFBTexture(n: 1, iRenderTargetFlags: 0);
  CTextureReference::Init(this: &g_QuarterSizedFBTexture1, pTexture: v4);
  TeenyFBTexture = CreateTeenyFBTexture(n: 0);
  CTextureReference::Init(this: &g_TeenyFBTexture0, pTexture: TeenyFBTexture);
  v6 = CreateTeenyFBTexture(n: 1);
  CTextureReference::Init(this: &g_TeenyFBTexture1, pTexture: v6);
  v7 = CreateTeenyFBTexture(n: 2);
  CTextureReference::Init(this: &g_TeenyFBTexture2, pTexture: v7);
  _V_strcpy(dest, src: "_rt_FullFrameFB");
  v8 = materials->__vftable;
  v9 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int, int))materials->GetBackBufferFormat)(
         a1: materials,
         a2: 0,
         a3: 12,
         a4: 1,
         a5: a1);
  v10 = (ITexture *)((int (__thiscall *)(IMaterialSystem *, char *, int, int, int, int))v8->CreateNamedRenderTargetTextureEx2)(
                      a1: materials,
                      a2: dest,
                      a3: 1,
                      a4: 1,
                      a5: 4,
                      a6: v9);
  CTextureReference::Init(this: &g_FullFrameFBTexture0, pTexture: v10);
  sprintf(string: dest, format: "_rt_FullFrameFB%d", 1);
  v11 = materials->__vftable;
  v12 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int))materials->GetBackBufferFormat)(
          a1: materials,
          a2: 0,
          a3: 12,
          a4: 17);
  v13 = (ITexture *)((int (__thiscall *)(IMaterialSystem *, char *, int, int, int, int))v11->CreateNamedRenderTargetTextureEx2)(
                      a1: materials,
                      a2: dest,
                      a3: 1,
                      a4: 1,
                      a5: 4,
                      a6: v12);
  CTextureReference::Init(this: &g_FullFrameFBTexture1, pTexture: v13);
  materials->AddTextureAlias(this: materials, a2: "_rt_FullFrameDepth", a3: "_rt_PowerOfTwoFB");
  CTextureReference::Init(this: &g_FullFrameDepth, pTexture: nullptr);
  if ( g_pClientRenderTargets != nullptr )
  {
    g_pClientRenderTargets->InitClientRenderTargets(
      this: g_pClientRenderTargets,
      a2: materials,
      a3: g_pMaterialSystemHardwareConfig);
  }
  else
  {
    WaterReflectionTexture = CreateWaterReflectionTexture();
    CTextureReference::Init(this: &g_WaterReflectionTexture, pTexture: WaterReflectionTexture);
    v15 = _CommandLine();
    v16 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 28))(
            a1: v15,
            a2: "-reflectionTextureSize",
            a3: 1024);
    v17 = materials->CreateNamedRenderTargetTextureEx2(
            this: materials,
            a2: "_rt_WaterRefraction",
            a3: v16,
            a4: v16,
            a5: 2,
            a6: 0,
            a7: 0,
            a8: 12,
            a9: 1);
    CTextureReference::Init(this: &g_WaterRefractionTexture, pTexture: v17);
    CameraTexture = CreateCameraTexture();
    CTextureReference::Init(this: &g_CameraTexture, pTexture: CameraTexture);
  }
  materials->EndRenderTargetAllocation(this: materials);
  v19 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v20 = v19;
  if ( v19 != nullptr )
    v19->BeginRender(this: v19);
  ((void (__thiscall *)(IMatRenderContext *, ITexture *))v20->SetNonInteractiveTempFullscreenBuffer)(
    a1: v20,
    a2: g_FullFrameFBTexture0.m_pTexture);
  v20->EndRender(this: v20);
  v20->Release(this: v20);
}

//------------------------------------------------------------------------------
// Address: 0x100E6D60
// Name: void ShutdownWellKnownRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ShutdownWellKnownRenderTargets(int a1@<esi>)
{
  int v1; // esi

  if ( mat_debugalttab.m_pParent != nullptr && mat_debugalttab.m_pParent->m_Value.m_nValue != 0 )
    _Warning(a1: "mat_debugalttab: ShutdownWellKnownRenderTargets\n");
  CTextureReference::Shutdown(this: &g_PowerOfTwoFBTexture, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_BuildCubemaps16BitTexture, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_QuarterSizedFBTexture0, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_QuarterSizedFBTexture1, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_QuarterSizedFBTexture2, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_QuarterSizedFBTexture3, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_TeenyFBTexture0, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_TeenyFBTexture1, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_TeenyFBTexture2, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_FullFrameFBTexture0, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &g_FullFrameFBTexture1, bDeleteIfUnReferenced: false);
  v1 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2: a1);
  if ( v1 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 704))(a1: v1, a2: 0);
  CTextureReference::Shutdown(this: &g_FullFrameDepth, bDeleteIfUnReferenced: false);
  materials->RemoveTextureAlias(this: materials, a2: "_rt_FullFrameDepth");
  if ( g_pClientRenderTargets != nullptr )
  {
    g_pClientRenderTargets->ShutdownClientRenderTargets(this: g_pClientRenderTargets);
  }
  else
  {
    CTextureReference::Shutdown(this: &g_WaterReflectionTexture, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &g_WaterRefractionTexture, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &g_CameraTexture, bDeleteIfUnReferenced: false);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 12))(a1: v1);
  (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 4))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100E6EA0
// Name: void ShutdownMaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ShutdownMaterialSystem(int a1@<esi>)
{
  ShutdownDebugMaterials();
  ShutdownWellKnownRenderTargets(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100E6EB0
// Name: VertexCountForSurfaceList
// Source: json
//------------------------------------------------------------------------------
int __fastcall VertexCountForSurfaceList(const surfacesortgroup_t *group, const CMSurfaceSortList *list)
{
  __int16 listHead; // cx
  int result; // eax
  materiallist_t *v4; // esi
  int v5; // edi
  int count; // edx
  int v7; // ebx
  int v8; // ecx
  unsigned int v9; // edx
  msurface2_t **v10; // ecx
  int _index; // [esp+0h] [ebp-Ch]
  materiallist_t *m_pMemory; // [esp+4h] [ebp-8h]
  int vertexCount; // [esp+8h] [ebp-4h]

  listHead = group->listHead;
  result = 0;
  vertexCount = 0;
  if ( listHead != -1 )
  {
    m_pMemory = list->m_list.m_Memory.m_pMemory;
    do
    {
      v4 = &m_pMemory[listHead];
      v5 = 0;
      count = v4->count;
      v7 = 0;
      v8 = 0;
      if ( count >= 2 )
      {
        v9 = ((unsigned int)(count - 2) >> 1) + 1;
        v10 = &v4->pSurfaces[1];
        _index = 2 * v9;
        do
        {
          v5 += HIBYTE((*(v10 - 1))->flags);
          v7 += HIBYTE((*v10)->flags);
          v10 += 2;
          --v9;
        }
        while ( v9 != 0 );
        result = vertexCount;
        v8 = _index;
      }
      if ( v8 < v4->count )
        result += HIBYTE(v4->pSurfaces[v8]->flags);
      listHead = v4->nextBlock;
      result += v5 + v7;
      vertexCount = result;
    }
    while ( LOWORD(v4->nextBlock) != 0xFFFF );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E6F40
// Name: void WorldStaticMeshDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldStaticMeshDestroy()
{
  IMatRenderContext *v0; // esi
  int v1; // edi
  int i; // ebx
  IMesh **m_pMemory; // eax

  v0 = materials->GetRenderContext(this: materials);
  v1 = 0;
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  for ( i = 0; i < g_Meshes.m_Size; ++v1 )
  {
    v0->DestroyStaticMesh(this: v0, a2: g_Meshes.m_Memory.m_pMemory[v1].pMesh);
    ++i;
  }
  m_pMemory = g_WorldStaticMeshes.m_Memory.m_pMemory;
  g_WorldStaticMeshes.m_Size = 0;
  if ( g_WorldStaticMeshes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_WorldStaticMeshes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_WorldStaticMeshes.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_WorldStaticMeshes.m_Memory.m_pMemory = nullptr;
    }
    g_WorldStaticMeshes.m_Memory.m_nAllocationCount = 0;
  }
  g_WorldStaticMeshes.m_pElements = m_pMemory;
  g_Meshes.m_Size = 0;
  if ( v0 != nullptr )
  {
    v0->EndRender(this: v0);
    v0->Release(this: v0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7000
// Name: void ReleaseMaterialSystemObjects(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseMaterialSystemObjects()
{
  DispInfo_ReleaseMaterialSystemObjects(pWorld: host_state.worldmodel);
  modelrender->ReleaseAllStaticPropColorData(this: modelrender);
  WorldStaticMeshDestroy();
  g_LostVideoMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x100E7030
// Name: void MaterialSystem_DestroySortinfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSystem_DestroySortinfo()
{
  if ( materialSortInfoArray != nullptr )
  {
    WorldStaticMeshDestroy();
    free(pMem: materialSortInfoArray);
    materialSortInfoArray = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7060
// Name: int FindOrAddMesh(class IMaterial __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrAddMesh(IMaterial *pMaterial, int vertexCount)
{
  unsigned __int64 v2; // rax
  IMatRenderContext *v3; // esi
  int v4; // edi
  int v5; // eax
  int m_nValue; // edx
  int m_Size; // ecx
  int *p_vertCount; // edx
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  unsigned __int64 format; // [esp+Ch] [ebp-Ch]
  int nMaxVertices; // [esp+14h] [ebp-4h]

  v2 = pMaterial->GetVertexFormat(this: pMaterial);
  LODWORD(v2) = v2 & 0xFFFFFBFF;
  format = v2;
  v3 = materials->GetRenderContext(this: materials);
  v4 = 0;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v5 = v3->GetMaxVerticesToRender(this: v3, a2: pMaterial);
  nMaxVertices = v5;
  if ( mat_max_worldmesh_vertices.m_pParent == nullptr
    || (m_nValue = mat_max_worldmesh_vertices.m_pParent->m_Value.m_nValue) <= 1024 )
  {
    m_nValue = 1024;
  }
  if ( v5 > m_nValue )
  {
    if ( mat_max_worldmesh_vertices.m_pParent != nullptr )
      nMaxVertices = mat_max_worldmesh_vertices.m_pParent->m_Value.m_nValue;
    else
      nMaxVertices = 0;
  }
  m_Size = g_Meshes.m_Size;
  if ( g_Meshes.m_Size <= 0 )
  {
LABEL_15:
    v9 = g_Meshes.m_Size;
    if ( g_Meshes.m_Size + 1 > g_Meshes.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
        this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&g_Meshes,
        num: g_Meshes.m_Size - g_Meshes.m_Memory.m_nAllocationCount + 1);
      m_Size = g_Meshes.m_Size;
    }
    g_Meshes.m_Size = m_Size + 1;
    v10 = m_Size - v9;
    g_Meshes.m_pElements = g_Meshes.m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &g_Meshes.m_Memory.m_pMemory[v9 + 1], src: &g_Meshes.m_Memory.m_pMemory[v9], count: 24 * v10);
    v11 = v9;
    g_Meshes.m_Memory.m_pMemory[v11].vertCount = vertexCount;
    g_Meshes.m_Memory.m_pMemory[v11].vertexFormat = format;
    g_Meshes.m_Memory.m_pMemory[v11].pMaterial = pMaterial;
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return v9;
  }
  else
  {
    p_vertCount = &g_Meshes.m_Memory.m_pMemory->vertCount;
    while ( *((_QWORD *)p_vertCount + 1) != format || vertexCount + *p_vertCount > nMaxVertices )
    {
      ++v4;
      p_vertCount += 6;
      if ( v4 >= g_Meshes.m_Size )
        goto LABEL_15;
    }
    g_Meshes.m_Memory.m_pMemory[v4].vertCount += vertexCount;
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E71F0
// Name: void WorldStaticMeshCreate(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldStaticMeshCreate()
{
  int v0; // edi
  int v1; // esi
  void *v2; // esp
  int v3; // eax
  worldbrushdata_t *worldbrush; // eax
  int v5; // ebx
  msurface2_t *surfaces2; // esi
  msurface2_t *v7; // esi
  IMaterial *material; // ecx
  int k; // esi
  surfacesortgroup_t *p_m_emptyGroup; // ebx
  msurface2_t *SurfaceAtHead; // eax
  int v12; // eax
  IMatRenderContext *v13; // eax
  int v14; // esi
  IVBAllocTracker *v15; // ecx
  unsigned int v16; // ebx
  __int64 v17; // rax
  int *v18; // ebx
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // esi
  surfacesortgroup_t *v22; // eax
  __int16 listHead; // ax
  materiallist_t *m_pMemory; // ecx
  int v25; // ebx
  int *v26; // ebx
  int v27; // esi
  int m_nVertexCount; // eax
  IMesh *v29; // [esp-14h] [ebp-2ECh]
  int v30; // [esp-Ch] [ebp-2E4h]
  int v31; // [esp+0h] [ebp-2D8h] BYREF
  CMSurfaceSortList matSortArray; // [esp+Ch] [ebp-2CCh] BYREF
  CMeshBuilder meshBuilder; // [esp+CCh] [ebp-20Ch] BYREF
  int *v34; // [esp+2B4h] [ebp-24h]
  int v35; // [esp+2B8h] [ebp-20h]
  int *sortIndex; // [esp+2BCh] [ebp-1Ch]
  int i; // [esp+2C0h] [ebp-18h]
  int vertBufferIndex; // [esp+2C4h] [ebp-14h]
  int j; // [esp+2C8h] [ebp-10h]
  unsigned int m; // [esp+2CCh] [ebp-Ch]
  int surfaceIndex; // [esp+2D0h] [ebp-8h]
  bool bTools; // [esp+2D7h] [ebp-1h]

  r_framecount = 1;
  WorldStaticMeshDestroy();
  v0 = 0;
  g_Meshes.m_Size = 0;
  SetTexInfoBaseTexture2Flags();
  v1 = materials->GetNumSortIDs(this: materials);
  if ( v1 != 0 )
  {
    g_pShadowMgr->SetNumWorldMaterialBuckets(this: g_pShadowMgr, a2: v1);
    g_WorldStaticMeshes.m_Size = 0;
    CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&g_WorldStaticMeshes,
      elem: 0,
      num: v1);
    memset(
      dst: (unsigned __int8 *)g_WorldStaticMeshes.m_Memory.m_pMemory,
      value: 0,
      count: 4 * g_WorldStaticMeshes.m_Size);
    CMSurfaceSortList::CMSurfaceSortList(this: &matSortArray);
    CMSurfaceSortList::Init(this: &matSortArray, maxSortIDs: v1, minMaterialLists: 512);
    v2 = alloca(4 * g_WorldStaticMeshes.m_Size);
    sortIndex = &v31;
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-tools", a3: 0) != 0
      || (bTools = false, g_bReplayLoadedTools) )
    {
      bTools = true;
    }
    worldbrush = host_state.worldbrush;
    surfaceIndex = 0;
    if ( host_state.worldbrush->numsurfaces > 0 )
    {
      v5 = 0;
      do
      {
        surfaces2 = worldbrush->surfaces2;
        surfaces2[v5].flags &= ~0x100u;
        v7 = &surfaces2[v5];
        if ( bTools
          || (material = host_state.worldbrush->texinfo[*((unsigned __int16 *)v7 + 11) >> 1].material,
              (material->GetVertexFormat(this: material) & 0x30) != 0) )
        {
          v7->flags |= 0x100u;
        }
        if ( (v7->flags & 0x800) != 0 )
          v7->vertBufferIndex = -1;
        else
          CMSurfaceSortList::AddSurfaceToTail(
            this: &matSortArray,
            pSurface: v7,
            sortGroup: 0,
            sortID: v7->materialSortID);
        worldbrush = host_state.worldbrush;
        ++v5;
        ++surfaceIndex;
      }
      while ( surfaceIndex < host_state.worldbrush->numsurfaces );
    }
    for ( k = 0; k < g_WorldStaticMeshes.m_Size; ++k )
    {
      if ( ((unsigned __int8)(1 << ((k + LOBYTE(matSortArray.groupOffset[0])) & 7))
          & matSortArray.m_groupUsed.m_Memory.m_pMemory[(k + matSortArray.groupOffset[0]) >> 3]) != 0 )
        p_m_emptyGroup = &matSortArray.m_groups.m_Memory.m_pMemory[k + matSortArray.groupOffset[0]];
      else
        p_m_emptyGroup = &matSortArray.m_emptyGroup;
      j = VertexCountForSurfaceList(group: p_m_emptyGroup, list: &matSortArray);
      SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: &matSortArray, group: p_m_emptyGroup);
      g_WorldStaticMeshes.m_Memory.m_pMemory[k] = nullptr;
      if ( SurfaceAtHead != nullptr )
        v12 = FindOrAddMesh(
                pMaterial: host_state.worldbrush->texinfo[*((unsigned __int16 *)SurfaceAtHead + 11) >> 1].material,
                vertexCount: j);
      else
        v12 = -1;
      sortIndex[k] = v12;
    }
    v13 = materials->GetRenderContext(this: materials);
    v14 = (int)v13;
    surfaceIndex = (int)v13;
    if ( v13 != nullptr )
      v13->BeginRender(this: v13);
    i = 0;
    if ( g_Meshes.m_Size > 0 )
    {
      v15 = g_VBAllocTracker;
      v16 = 0;
      for ( m = 0; ; v16 = m )
      {
        if ( v15 != nullptr )
          v15->TrackMeshAllocations(this: v15, a2: "WorldStaticMeshCreate");
        v17 = ((__int64 (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)((char *)&g_Meshes.m_Memory.m_pMemory->pMaterial
                                                                       + v16)
                                                         + 80))(a1: *(IMaterial **)((char *)&g_Meshes.m_Memory.m_pMemory->pMaterial
                                                                                  + v16));
        v18 = (int *)((char *)g_Meshes.m_Memory.m_pMemory + v16);
        v19 = (*(int (__thiscall **)(int, _DWORD, _DWORD, const char *, int, _DWORD))(*(_DWORD *)v14 + 220))(
                a1: surfaceIndex,
                a2: v17 & 0xFFFFFBFF,
                a3: HIDWORD(v17),
                a4: "World Verts",
                a5: v18[1],
                a6: 0);
        v20 = m;
        *v18 = v19;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_bGenerateIndices = false;
        memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
        memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        v30 = *(int *)((char *)&g_Meshes.m_Memory.m_pMemory->vertCount + v20);
        v29 = *(IMesh **)((char *)&g_Meshes.m_Memory.m_pMemory->pMesh + v20);
        vertBufferIndex = 0;
        CMeshBuilder::Begin(
          this: &meshBuilder,
          pMesh: v29,
          type: MATERIAL_TRIANGLES,
          nVertexCount: v30,
          nIndexCount: 0,
          pMeshSettings: nullptr);
        v21 = 0;
        for ( j = 0; v21 < g_WorldStaticMeshes.m_Size; j = v21 )
        {
          if ( sortIndex[v21] == i )
          {
            g_WorldStaticMeshes.m_Memory.m_pMemory[v21] = g_Meshes.m_Memory.m_pMemory[m / 0x18].pMesh;
            v22 = ((unsigned __int8)(1 << ((v21 + LOBYTE(matSortArray.groupOffset[0])) & 7))
                 & matSortArray.m_groupUsed.m_Memory.m_pMemory[(v21 + matSortArray.groupOffset[0]) >> 3]) != 0
                ? &matSortArray.m_groups.m_Memory.m_pMemory[v21 + matSortArray.groupOffset[0]]
                : &matSortArray.m_emptyGroup;
            listHead = v22->listHead;
            if ( listHead != -1 )
            {
              m_pMemory = matSortArray.m_list.m_Memory.m_pMemory;
              do
              {
                v25 = listHead << 6;
                v35 = v25;
                v34 = (int *)((char *)&m_pMemory->count + v25);
                if ( *v34 > 0 )
                {
                  v26 = (int *)((char *)m_pMemory->pSurfaces + v25);
                  do
                  {
                    v27 = *v26;
                    *(_WORD *)(v27 + 20) = vertBufferIndex;
                    BuildMSurfaceVertexArrays(
                      pBrushData: host_state.worldbrush,
                      surfID: (msurface2_t *)v27,
                      builder: &meshBuilder);
                    vertBufferIndex += *(unsigned __int8 *)(v27 + 3);
                    ++v0;
                    ++v26;
                  }
                  while ( v0 < *v34 );
                  m_pMemory = matSortArray.m_list.m_Memory.m_pMemory;
                  v25 = v35;
                  v21 = j;
                  v0 = 0;
                }
                listHead = *(_WORD *)((char *)&m_pMemory->nextBlock + v25);
              }
              while ( listHead != -1 );
            }
          }
          ++v21;
        }
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: m_nVertexCount);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        v15 = g_VBAllocTracker;
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        if ( g_VBAllocTracker != nullptr )
        {
          g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
          if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
            && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
          {
            meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
          }
          if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
            && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
          {
            meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
          }
          v15 = g_VBAllocTracker;
        }
        m += 24;
        v14 = surfaceIndex;
        if ( ++i >= g_Meshes.m_Size )
          break;
      }
    }
    if ( v14 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 12))(a1: v14);
      (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 4))(a1: v14);
    }
    CMSurfaceSortList::~CMSurfaceSortList(this: &matSortArray);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7770
// Name: void RestoreMaterialSystemObjects(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RestoreMaterialSystemObjects(char nChangeFlags)
{
  void *v1; // ecx
  CStaticPropMgr *v2; // eax
  BOOL bThreadingAllowed; // [esp+4h] [ebp-4h]

  LOBYTE(bThreadingAllowed) = Host_AllowQueuedMaterialSystem(bAllow: false);
  g_LostVideoMemory = false;
  if ( (nChangeFlags & 1) != 0 )
    modelrender->RemoveAllDecalsFromAllModels(this: modelrender);
  if ( host_state.worldmodel != nullptr && materialSortInfoArray != nullptr )
  {
    if ( (nChangeFlags & 1) != 0 || materials->GetNumSortIDs(this: materials) == 0 )
    {
      R_LoadWorldGeometry(bDXChange: true);
    }
    else
    {
      modelloader->Map_LoadDisplacements(this: modelloader, a2: host_state.worldmodel, a3: true);
      WorldStaticMeshCreate();
      R_RedownloadAllLightmaps(this: v1);
    }
    R_StudioInitLightingCache();
    modelrender->RestoreAllStaticPropColorData(this: modelrender);
    v2 = StaticPropMgr();
    v2->RestoreStaticProps(this: v2);
  }
  Host_AllowQueuedMaterialSystem(bAllow: bThreadingAllowed);
}

//------------------------------------------------------------------------------
// Address: 0x100E7830
// Name: void InitMaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitMaterialSystem(int a1@<esi>)
{
  bool v1; // al

  materials->AddReleaseFunc(this: materials, a2: (void (__cdecl *)(int))ReleaseMaterialSystemObjects);
  materials->AddRestoreFunc(this: materials, a2: (void (__cdecl *)(int))RestoreMaterialSystemObjects);
  v1 = g_pMaterialSystemHardwareConfig->PreferZPrepass(this: g_pMaterialSystemHardwareConfig);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_fastzreject.IConVar, value: v1);
  UpdateMaterialSystemConfig();
  InitWellKnownRenderTargets(a1);
  InitDebugMaterials(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10312A50
// Name: _dynamic_initializer_for__mat_force_tonemap_scale__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_tonemap_scale__()
{
  ConVar::ConVar(this: &mat_force_tonemap_scale, pName: "mat_force_tonemap_scale", pDefaultValue: "0.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_force_tonemap_scale__);
}

//------------------------------------------------------------------------------
// Address: 0x10313D90
// Name: _dynamic_initializer_for__mat_texture_list__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list__()
{
  ConVar::ConVar(
    this: &mat_texture_list,
    pName: "mat_texture_list",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "For debugging, show a list of used textures per frame");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list__);
}

//------------------------------------------------------------------------------
// Address: 0x10313DC0
// Name: _dynamic_initializer_for__mat_texture_list_on__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_on__()
{
  ConCommand::ConCommand(
    this: &mat_texture_list_on,
    pName: "+mat_texture_list",
    callback: mat_texture_list_on_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_on__);
}

//------------------------------------------------------------------------------
// Address: 0x10313DF0
// Name: _dynamic_initializer_for__mat_texture_list_off__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_off__()
{
  ConCommand::ConCommand(
    this: &mat_texture_list_off,
    pName: "-mat_texture_list",
    callback: (void (__cdecl *)())mat_texture_list_off_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_off__);
}

//------------------------------------------------------------------------------
// Address: 0x10313E20
// Name: _dynamic_initializer_for__mat_texture_list_all__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_all__()
{
  ConVar::ConVar(
    this: &mat_texture_list_all,
    pName: "mat_texture_list_all",
    pDefaultValue: "0",
    flags: 4096,
    pHelpString: "If this is nonzero, then the texture list panel will show all currently-loaded textures.");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_all__);
}

//------------------------------------------------------------------------------
// Address: 0x10313E50
// Name: _dynamic_initializer_for__mat_texture_list_all_frames__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_all_frames__()
{
  ConVar::ConVar(
    this: &mat_texture_list_all_frames,
    pName: "mat_texture_list_all_frames",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "How many frames to sample texture memory for all textures.");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_all_frames__);
}

//------------------------------------------------------------------------------
// Address: 0x10313E80
// Name: _dynamic_initializer_for__mat_texture_list_view__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_view__()
{
  ConVar::ConVar(
    this: &mat_texture_list_view,
    pName: "mat_texture_list_view",
    pDefaultValue: "1",
    flags: 4096,
    pHelpString: "If this is nonzero, then the texture list panel will render thumbnails of currently-loaded textures.");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_view__);
}

//------------------------------------------------------------------------------
// Address: 0x10313EB0
// Name: _dynamic_initializer_for__mat_show_texture_memory_usage__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_show_texture_memory_usage__()
{
  ConVar::ConVar(
    this: &mat_show_texture_memory_usage,
    pName: "mat_show_texture_memory_usage",
    pDefaultValue: "0",
    flags: 20480,
    pHelpString: "Display the texture memory usage on the HUD.");
  return atexit(func: dynamic_atexit_destructor_for__mat_show_texture_memory_usage__);
}

//------------------------------------------------------------------------------
// Address: 0x10313EE0
// Name: _dynamic_initializer_for__mat_texture_list_exclude_editing__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_exclude_editing__()
{
  ConVar::ConVar(
    this: &mat_texture_list_exclude_editing,
    pName: "mat_texture_list_exclude_editing",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_exclude_editing__);
}

//------------------------------------------------------------------------------
// Address: 0x10313F10
// Name: _dynamic_initializer_for__mat_texture_list_txlod_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_txlod_command__()
{
  ConCommand::ConCommand(
    this: &mat_texture_list_txlod_command,
    pName: "mat_texture_list_txlod",
    callback: (void (__cdecl *)())mat_texture_list_txlod,
    pHelpString: "Adjust LOD of the last viewed texture +1 to inc resolution, -1 to dec resolution",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_txlod_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103140B0
// Name: _dynamic_initializer_for__mat_colorcorrection__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colorcorrection__()
{
  ConVar::ConVar(this: &mat_colorcorrection, pName: "mat_colorcorrection", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_colorcorrection__);
}

//------------------------------------------------------------------------------
// Address: 0x103140E0
// Name: _dynamic_initializer_for__mat_colcorrection_disableentities__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colcorrection_disableentities__()
{
  ConVar::ConVar(
    this: &mat_colcorrection_disableentities,
    pName: "mat_colcorrection_disableentities",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_colcorrection_disableentities__);
}

//------------------------------------------------------------------------------
// Address: 0x10314110
// Name: _dynamic_initializer_for__mat_colcorrection_editor__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colcorrection_editor__()
{
  ConVar::ConVar(this: &mat_colcorrection_editor, pName: "mat_colcorrection_editor", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_colcorrection_editor__);
}

//------------------------------------------------------------------------------
// Address: 0x10314590
// Name: _dynamic_initializer_for__mat_leafvis__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_leafvis__()
{
  ConVar::ConVar(
    this: &mat_leafvis,
    pName: "mat_leafvis",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Draw wireframe of: [0] nothing, [1] current leaf, [2] entire vis cluster, or [3] entire PVS (see mat_leafvis_draw_ma"
    "sk for what does/doesn't get drawn)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))LeafvisChanged);
  return atexit(func: dynamic_atexit_destructor_for__mat_leafvis__);
}

//------------------------------------------------------------------------------
// Address: 0x103145C0
// Name: _dynamic_initializer_for__mat_leafvis_update_every_frame__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_leafvis_update_every_frame__()
{
  ConVar::ConVar(
    this: &mat_leafvis_update_every_frame,
    pName: "mat_leafvis_update_every_frame",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Updates leafvis debug render every frame (expensive)");
  return atexit(func: dynamic_atexit_destructor_for__mat_leafvis_update_every_frame__);
}

//------------------------------------------------------------------------------
// Address: 0x10314620
// Name: _dynamic_initializer_for__mat_leafvis_draw_mask__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_leafvis_draw_mask__()
{
  ConVar::ConVar(
    this: &mat_leafvis_draw_mask,
    pName: "mat_leafvis_draw_mask",
    pDefaultValue: "3",
    flags: 0,
    pHelpString: "A bitfield which affects leaf visibility debug rendering.  -1: show all, bit 0: render PVS-visible leafs, bit 1: ren"
    "der PVS- and frustum-visible leafs, bit 2: render frustum bounds, bit 3: render leaves out of PVS.");
  return atexit(func: dynamic_atexit_destructor_for__mat_leafvis_draw_mask__);
}

//------------------------------------------------------------------------------
// Address: 0x10314650
// Name: _dynamic_initializer_for__mat_leafvis_freeze__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_leafvis_freeze__()
{
  ConVar::ConVar(
    this: &mat_leafvis_freeze,
    pName: "mat_leafvis_freeze",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If set to 1, uses the last known leaf visibility data for visualization.  If set to 0, updates based on camera movement.");
  return atexit(func: dynamic_atexit_destructor_for__mat_leafvis_freeze__);
}

//------------------------------------------------------------------------------
// Address: 0x103149E0
// Name: _dynamic_initializer_for__mat_defaultlightmap__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_defaultlightmap__()
{
  ConVar::ConVar(
    this: &mat_defaultlightmap,
    pName: "mat_defaultlightmap",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Default brightness for lightmaps where none have been created in the level.");
  return atexit(func: dynamic_atexit_destructor_for__mat_defaultlightmap__);
}

//------------------------------------------------------------------------------
// Address: 0x10314A20
// Name: _dynamic_initializer_for__mat_edit_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_edit_command__()
{
  ConCommand::ConCommand(
    this: &mat_edit_command,
    pName: "mat_edit",
    callback: (void (__cdecl *)())mat_edit,
    pHelpString: "Bring up the material under the crosshair in the editor",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_edit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314A50
// Name: _dynamic_initializer_for__mat_crosshair_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_command,
    pName: "mat_crosshair",
    callback: mat_crosshair,
    pHelpString: "Display the name of the material under the crosshair",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314A80
// Name: _dynamic_initializer_for__mat_crosshair_edit_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_edit_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_edit_command,
    pName: "mat_crosshair_edit",
    callback: (void (__cdecl *)())mat_crosshair_edit,
    pHelpString: "open the material under the crosshair in the editor defined by mat_crosshair_edit_editor",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_edit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314AB0
// Name: _dynamic_initializer_for__mat_crosshair_explorer_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_explorer_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_explorer_command,
    pName: "mat_crosshair_explorer",
    callback: (void (__cdecl *)())mat_crosshair_explorer,
    pHelpString: "open the material under the crosshair in explorer and highlight the vmt file",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_explorer_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314AE0
// Name: _dynamic_initializer_for__mat_crosshair_reloadmaterial_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_reloadmaterial_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_reloadmaterial_command,
    pName: "mat_crosshair_reloadmaterial",
    callback: mat_crosshair_reloadmaterial,
    pHelpString: "reload the material under the crosshair",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_reloadmaterial_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314B10
// Name: _dynamic_initializer_for__mat_crosshair_printmaterial_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_crosshair_printmaterial_command__()
{
  ConCommand::ConCommand(
    this: &mat_crosshair_printmaterial_command,
    pName: "mat_crosshair_printmaterial",
    callback: mat_crosshair_printmaterial,
    pHelpString: "print the material under the crosshair",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_crosshair_printmaterial_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314DB0
// Name: _dynamic_initializer_for__mat_forcedynamic__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_forcedynamic__()
{
  ConVar::ConVar(this: &mat_forcedynamic, pName: &args.m_pArgvBuffer[460], pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_forcedynamic__);
}

//------------------------------------------------------------------------------
// Address: 0x10314F60
// Name: _dynamic_initializer_for__mat_surfaceid__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_surfaceid__()
{
  ConVar::ConVar(this: &mat_surfaceid, pName: "mat_surfaceid", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_surfaceid__);
}

//------------------------------------------------------------------------------
// Address: 0x10314F90
// Name: _dynamic_initializer_for__mat_surfacemat__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_surfacemat__()
{
  ConVar::ConVar(this: &mat_surfacemat, pName: "mat_surfacemat", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_surfacemat__);
}

//------------------------------------------------------------------------------
// Address: 0x10315560
// Name: _dynamic_initializer_for__mat_softwareskin__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_softwareskin__()
{
  ConVar::ConVar(this: &mat_softwareskin, pName: "mat_softwareskin", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_softwareskin__);
}

//------------------------------------------------------------------------------
// Address: 0x10315A00
// Name: _dynamic_initializer_for__mat_maxframelatency__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_maxframelatency__()
{
  ConVar::ConVar(this: &mat_maxframelatency, pName: "mat_maxframelatency", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_maxframelatency__);
}

//------------------------------------------------------------------------------
// Address: 0x10315D50
// Name: _dynamic_initializer_for__mat_norendering__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_norendering__()
{
  ConVar::ConVar(this: &mat_norendering, pName: "mat_norendering", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_norendering__);
}

//------------------------------------------------------------------------------
// Address: 0x10315D80
// Name: _dynamic_initializer_for__mat_wireframe__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_wireframe__()
{
  ConVar::ConVar(this: &mat_wireframe, pName: "mat_wireframe", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_wireframe__);
}

//------------------------------------------------------------------------------
// Address: 0x10315E40
// Name: _dynamic_initializer_for__mat_envmapsize__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_envmapsize__()
{
  ConVar::ConVar(this: &mat_envmapsize, pName: "mat_envmapsize", pDefaultValue: "128", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_envmapsize__);
}

//------------------------------------------------------------------------------
// Address: 0x10315E70
// Name: _dynamic_initializer_for__mat_envmaptgasize__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_envmaptgasize__()
{
  ConVar::ConVar(this: &mat_envmaptgasize, pName: "mat_envmaptgasize", pDefaultValue: "32.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_envmaptgasize__);
}

//------------------------------------------------------------------------------
// Address: 0x10315EA0
// Name: _dynamic_initializer_for__mat_levelflush__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_levelflush__()
{
  ConVar::ConVar(this: &mat_levelflush, pName: "mat_levelflush", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_levelflush__);
}

//------------------------------------------------------------------------------
// Address: 0x10315ED0
// Name: _dynamic_initializer_for__mat_fastspecular__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fastspecular__()
{
  ConVar::ConVar(
    this: &mat_fastspecular,
    pName: "mat_fastspecular",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable/Disable specularity for visual testing.  Will not reload materials and will not affect perf.");
  return atexit(func: dynamic_atexit_destructor_for__mat_fastspecular__);
}

//------------------------------------------------------------------------------
// Address: 0x10315F00
// Name: _dynamic_initializer_for__mat_fullbright__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fullbright__()
{
  ConVar::ConVar(this: &mat_fullbright, pName: "mat_fullbright", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_fullbright__);
}

//------------------------------------------------------------------------------
// Address: 0x10315F30
// Name: _dynamic_initializer_for__mat_monitorgamma__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma,
    pName: "mat_monitorgamma",
    pDefaultValue: "2.2",
    flags: 16777344,
    pHelpString: "monitor gamma (typically 2.2 for CRT and 1.7 for LCD)",
    bMin: true,
    fMin: 1.6,
    bMax: true,
    fMax: 2.5999999);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma__);
}

//------------------------------------------------------------------------------
// Address: 0x10315F80
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_range_min__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_range_min__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_range_min,
    pName: "mat_monitorgamma_tv_range_min",
    pDefaultValue: "16",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__);
}

//------------------------------------------------------------------------------
// Address: 0x10315FB0
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_range_max__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_range_max__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_range_max,
    pName: "mat_monitorgamma_tv_range_max",
    pDefaultValue: "235",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10315FE0
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_exp__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_exp__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_exp,
    pName: "mat_monitorgamma_tv_exp",
    pDefaultValue: "2.5",
    flags: 0,
    pHelpString: defaultValue,
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 4.0);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__);
}

//------------------------------------------------------------------------------
// Address: 0x10316020
// Name: _dynamic_initializer_for__mat_monitorgamma_tv_enabled__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_monitorgamma_tv_enabled__()
{
  ConVar::ConVar(
    this: &mat_monitorgamma_tv_enabled,
    pName: "mat_monitorgamma_tv_enabled",
    pDefaultValue: "0",
    flags: 16777344,
    pHelpString: defaultValue);
  return atexit(func: dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x103160E0
// Name: _dynamic_initializer_for__mat_motion_blur_enabled__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_enabled__()
{
  ConVar::ConVar(this: &mat_motion_blur_enabled, pName: "mat_motion_blur_enabled", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x10316110
// Name: _dynamic_initializer_for__mat_depthbias_normal__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_depthbias_normal__()
{
  ConVar::ConVar(this: &mat_depthbias_normal, pName: "mat_depthbias_normal", pDefaultValue: "0.0f", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_depthbias_normal__);
}

//------------------------------------------------------------------------------
// Address: 0x10316140
// Name: _dynamic_initializer_for__mat_hdr_level__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_hdr_level__()
{
  ConVar::ConVar(
    this: &mat_hdr_level,
    pName: "mat_hdr_level",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Set to 0 for no HDR, 1 for LDR+bloom on HDR maps, and 2 for full HDR on HDR maps.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))mat_hdr_level_Callback);
  return atexit(func: dynamic_atexit_destructor_for__mat_hdr_level__);
}

//------------------------------------------------------------------------------
// Address: 0x10316170
// Name: _dynamic_initializer_for__mat_configcurrent_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_configcurrent_command__()
{
  ConCommand::ConCommand(
    this: &mat_configcurrent_command,
    pName: "mat_configcurrent",
    callback: mat_configcurrent,
    pHelpString: "show the current video control panel config for the material system",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_configcurrent_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103161A0
// Name: _dynamic_initializer_for__mat_setvideomode_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_setvideomode_command__()
{
  ConCommand::ConCommand(
    this: &mat_setvideomode_command,
    pName: "mat_setvideomode",
    callback: (void (__cdecl *)())mat_setvideomode,
    pHelpString: "sets the width, height, windowed state of the material system",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_setvideomode_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103161D0
// Name: _dynamic_initializer_for__mat_savechanges_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_savechanges_command__()
{
  ConCommand::ConCommand(
    this: &mat_savechanges_command,
    pName: "mat_savechanges",
    callback: mat_savechanges,
    pHelpString: "saves current video configuration to the registry",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_savechanges_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10316200
// Name: _dynamic_initializer_for__mat_debug_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_debug_command__()
{
  ConCommand::ConCommand(
    this: &mat_debug_command,
    pName: "mat_debug",
    callback: (void (__cdecl *)())mat_debug,
    pHelpString: "Activates debugging spew for a specific material.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_debug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10316230
// Name: _dynamic_initializer_for__mat_suppress_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_suppress_command__()
{
  ConCommand::ConCommand(
    this: &mat_suppress_command,
    pName: "mat_suppress",
    callback: (void (__cdecl *)())mat_suppress,
    pHelpString: "Supress a material from drawing",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_suppress_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10316260
// Name: _dynamic_initializer_for__mat_info_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_info_command__()
{
  ConCommand::ConCommand(
    this: &mat_info_command,
    pName: "mat_info",
    callback: mat_info,
    pHelpString: "Shows material system info",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_info_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103162A0
// Name: _dynamic_initializer_for__mat_max_worldmesh_vertices__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_max_worldmesh_vertices__()
{
  ConVar::ConVar(
    this: &mat_max_worldmesh_vertices,
    pName: "mat_max_worldmesh_vertices",
    pDefaultValue: "65536",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_max_worldmesh_vertices__);
}

//------------------------------------------------------------------------------
// Address: 0x103162D0
// Name: _dynamic_initializer_for__mat_loadtextures__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_loadtextures__()
{
  ConVar::ConVar(this: &mat_loadtextures, pName: "mat_loadtextures", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_loadtextures__);
}

//------------------------------------------------------------------------------
// Address: 0x10316360
// Name: _dynamic_initializer_for__mat_excludetextures__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_excludetextures__()
{
  ConVar::ConVar(this: &mat_excludetextures, pName: "mat_excludetextures", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_excludetextures__);
}

//------------------------------------------------------------------------------
// Address: 0x10316390
// Name: _dynamic_initializer_for__mat_glidnarb__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_glidnarb__()
{
  ConVar::ConVar(this: &mat_glidnarb, pName: "mat_glidnarb", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_glidnarb__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C2A0
// Name: _dynamic_initializer_for__mat_ambient_light_r__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_r__()
{
  ConVar::ConVar(this: &mat_ambient_light_r, pName: "mat_ambient_light_r", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_r__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C2D0
// Name: _dynamic_initializer_for__mat_ambient_light_g__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_g__()
{
  ConVar::ConVar(this: &mat_ambient_light_g, pName: "mat_ambient_light_g", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_g__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C300
// Name: _dynamic_initializer_for__mat_ambient_light_b__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_ambient_light_b__()
{
  ConVar::ConVar(this: &mat_ambient_light_b, pName: "mat_ambient_light_b", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_ambient_light_b__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F3B0
// Name: _dynamic_initializer_for__mat_drawTitleSafe__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_drawTitleSafe__()
{
  ConVar::ConVar(
    this: &mat_drawTitleSafe,
    pName: "mat_drawTitleSafe",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable title safe overlay");
  return atexit(func: dynamic_atexit_destructor_for__mat_drawTitleSafe__);
}

//------------------------------------------------------------------------------
// Address: 0x10322470
// Name: _dynamic_atexit_destructor_for__mat_force_tonemap_scale__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_tonemap_scale__()
{
  ConVar::~ConVar(this: &mat_force_tonemap_scale);
}

//------------------------------------------------------------------------------
// Address: 0x10322E60
// Name: _dynamic_atexit_destructor_for__mat_leafvis__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_leafvis__()
{
  ConVar::~ConVar(this: &mat_leafvis);
}

//------------------------------------------------------------------------------
// Address: 0x10322E70
// Name: _dynamic_atexit_destructor_for__mat_leafvis_update_every_frame__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_leafvis_update_every_frame__()
{
  ConVar::~ConVar(this: &mat_leafvis_update_every_frame);
}

//------------------------------------------------------------------------------
// Address: 0x10322E90
// Name: _dynamic_atexit_destructor_for__mat_leafvis_draw_mask__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_leafvis_draw_mask__()
{
  ConVar::~ConVar(this: &mat_leafvis_draw_mask);
}

//------------------------------------------------------------------------------
// Address: 0x10322EA0
// Name: _dynamic_atexit_destructor_for__mat_leafvis_freeze__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_leafvis_freeze__()
{
  ConVar::~ConVar(this: &mat_leafvis_freeze);
}

//------------------------------------------------------------------------------
// Address: 0x103230F0
// Name: _dynamic_atexit_destructor_for__mat_defaultlightmap__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_defaultlightmap__()
{
  ConVar::~ConVar(this: &mat_defaultlightmap);
}

//------------------------------------------------------------------------------
// Address: 0x10323100
// Name: _dynamic_atexit_destructor_for__mat_edit_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_edit_command__()
{
  ConCommand::~ConCommand(this: &mat_edit_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323110
// Name: _dynamic_atexit_destructor_for__mat_crosshair_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_crosshair_command__()
{
  ConCommand::~ConCommand(this: &mat_crosshair_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323140
// Name: _dynamic_atexit_destructor_for__mat_crosshair_reloadmaterial_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_crosshair_reloadmaterial_command__()
{
  ConCommand::~ConCommand(this: &mat_crosshair_reloadmaterial_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323150
// Name: _dynamic_atexit_destructor_for__mat_crosshair_printmaterial_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_crosshair_printmaterial_command__()
{
  ConCommand::~ConCommand(this: &mat_crosshair_printmaterial_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323270
// Name: _dynamic_atexit_destructor_for__mat_forcedynamic__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_forcedynamic__()
{
  ConVar::~ConVar(this: &mat_forcedynamic);
}

//------------------------------------------------------------------------------
// Address: 0x10323300
// Name: _dynamic_atexit_destructor_for__mat_surfaceid__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_surfaceid__()
{
  ConVar::~ConVar(this: &mat_surfaceid);
}

//------------------------------------------------------------------------------
// Address: 0x10323310
// Name: _dynamic_atexit_destructor_for__mat_surfacemat__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_surfacemat__()
{
  ConVar::~ConVar(this: &mat_surfacemat);
}

//------------------------------------------------------------------------------
// Address: 0x10323890
// Name: _dynamic_atexit_destructor_for__mat_norendering__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_norendering__()
{
  ConVar::~ConVar(this: &mat_norendering);
}

//------------------------------------------------------------------------------
// Address: 0x103238A0
// Name: _dynamic_atexit_destructor_for__mat_wireframe__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_wireframe__()
{
  ConVar::~ConVar(this: &mat_wireframe);
}

//------------------------------------------------------------------------------
// Address: 0x103238D0
// Name: _dynamic_atexit_destructor_for__mat_bumpbasis__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_bumpbasis__()
{
  ConVar::~ConVar(this: &mat_bumpbasis);
}

//------------------------------------------------------------------------------
// Address: 0x103238E0
// Name: _dynamic_atexit_destructor_for__mat_envmapsize__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_envmapsize__()
{
  ConVar::~ConVar(this: &mat_envmapsize);
}

//------------------------------------------------------------------------------
// Address: 0x103238F0
// Name: _dynamic_atexit_destructor_for__mat_envmaptgasize__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_envmaptgasize__()
{
  ConVar::~ConVar(this: &mat_envmaptgasize);
}

//------------------------------------------------------------------------------
// Address: 0x10323900
// Name: _dynamic_atexit_destructor_for__mat_levelflush__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_levelflush__()
{
  ConVar::~ConVar(this: &mat_levelflush);
}

//------------------------------------------------------------------------------
// Address: 0x10323910
// Name: _dynamic_atexit_destructor_for__mat_fastspecular__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fastspecular__()
{
  ConVar::~ConVar(this: &mat_fastspecular);
}

//------------------------------------------------------------------------------
// Address: 0x10323920
// Name: _dynamic_atexit_destructor_for__mat_fullbright__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fullbright__()
{
  ConVar::~ConVar(this: &mat_fullbright);
}

//------------------------------------------------------------------------------
// Address: 0x10323930
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma__()
{
  ConVar::~ConVar(this: &mat_monitorgamma);
}

//------------------------------------------------------------------------------
// Address: 0x10323940
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_min__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_range_min);
}

//------------------------------------------------------------------------------
// Address: 0x10323950
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_range_max__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_range_max);
}

//------------------------------------------------------------------------------
// Address: 0x10323960
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_exp__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_exp);
}

//------------------------------------------------------------------------------
// Address: 0x10323970
// Name: _dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_monitorgamma_tv_enabled__()
{
  ConVar::~ConVar(this: &mat_monitorgamma_tv_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103239B0
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_enabled__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_enabled__()
{
  ConVar::~ConVar(this: &mat_motion_blur_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103239C0
// Name: _dynamic_atexit_destructor_for__mat_depthbias_normal__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_depthbias_normal__()
{
  ConVar::~ConVar(this: &mat_depthbias_normal);
}

//------------------------------------------------------------------------------
// Address: 0x103239D0
// Name: _dynamic_atexit_destructor_for__mat_hdr_level__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_hdr_level__()
{
  ConVar::~ConVar(this: &mat_hdr_level);
}

//------------------------------------------------------------------------------
// Address: 0x103239E0
// Name: _dynamic_atexit_destructor_for__mat_configcurrent_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_configcurrent_command__()
{
  ConCommand::~ConCommand(this: &mat_configcurrent_command);
}

//------------------------------------------------------------------------------
// Address: 0x103239F0
// Name: _dynamic_atexit_destructor_for__mat_setvideomode_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_setvideomode_command__()
{
  ConCommand::~ConCommand(this: &mat_setvideomode_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323A00
// Name: _dynamic_atexit_destructor_for__mat_savechanges_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_savechanges_command__()
{
  ConCommand::~ConCommand(this: &mat_savechanges_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323A10
// Name: _dynamic_atexit_destructor_for__mat_debug_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debug_command__()
{
  ConCommand::~ConCommand(this: &mat_debug_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323A20
// Name: _dynamic_atexit_destructor_for__mat_suppress_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_suppress_command__()
{
  ConCommand::~ConCommand(this: &mat_suppress_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323A30
// Name: _dynamic_atexit_destructor_for__mat_info_command__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_info_command__()
{
  ConCommand::~ConCommand(this: &mat_info_command);
}

//------------------------------------------------------------------------------
// Address: 0x10323A40
// Name: _dynamic_atexit_destructor_for__mat_max_worldmesh_vertices__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_max_worldmesh_vertices__()
{
  ConVar::~ConVar(this: &mat_max_worldmesh_vertices);
}

//------------------------------------------------------------------------------
// Address: 0x10323A60
// Name: _dynamic_atexit_destructor_for__mat_loadtextures__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_loadtextures__()
{
  ConVar::~ConVar(this: &mat_loadtextures);
}

//------------------------------------------------------------------------------
// Address: 0x10323A90
// Name: _dynamic_atexit_destructor_for__mat_excludetextures__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_excludetextures__()
{
  ConVar::~ConVar(this: &mat_excludetextures);
}

//------------------------------------------------------------------------------
// Address: 0x10323AA0
// Name: _dynamic_atexit_destructor_for__mat_glidnarb__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_glidnarb__()
{
  ConVar::~ConVar(this: &mat_glidnarb);
}

//------------------------------------------------------------------------------
// Address: 0x10326020
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_r__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_r__()
{
  ConVar::~ConVar(this: &mat_ambient_light_r);
}

//------------------------------------------------------------------------------
// Address: 0x10326030
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_g__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_g__()
{
  ConVar::~ConVar(this: &mat_ambient_light_g);
}

//------------------------------------------------------------------------------
// Address: 0x10326040
// Name: _dynamic_atexit_destructor_for__mat_ambient_light_b__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_ambient_light_b__()
{
  ConVar::~ConVar(this: &mat_ambient_light_b);
}

//------------------------------------------------------------------------------
// Address: 0x10327410
// Name: _dynamic_atexit_destructor_for__mat_drawTitleSafe__
// Source: semantic_dyn_pfx_mat
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_drawTitleSafe__()
{
  ConVar::~ConVar(this: &mat_drawTitleSafe);
}

//------------------------------------------------------------------------------
// Address: 0x10312A80
// Name: _dynamic_initializer_for__envmap_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__envmap_command__()
{
  ConCommand::ConCommand(
    this: &envmap_command,
    pName: "envmap",
    callback: (void (__cdecl *)())envmap,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__envmap_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312AB0
// Name: _dynamic_initializer_for__lightprobe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lightprobe_command__()
{
  ConCommand::ConCommand(
    this: &lightprobe_command,
    pName: "lightprobe",
    callback: (void (__cdecl *)())lightprobe,
    pHelpString: "Samples the lighting environment.\n"
    "Creates a cubemap and a file indicating the local lighting in a subdirectory called 'materials/lightprobes'\n"
    ".The lightprobe command requires you specify a base file name.\n",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__lightprobe_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10314140
// Name: _dynamic_initializer_for__colorcorrectionui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__colorcorrectionui__()
{
  ConCommand::ConCommand(
    this: &colorcorrectionui,
    pName: "colorcorrectionui",
    callback: ShowHideColorCorrectionUI,
    pHelpString: "Show/hide the color correction tools UI.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__colorcorrectionui__);
}

//------------------------------------------------------------------------------
// Address: 0x10314170
// Name: _dynamic_initializer_for__print_colorcorrection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__print_colorcorrection__()
{
  ConCommand::ConCommand(
    this: &print_colorcorrection,
    pName: "print_colorcorrection",
    callback: PrintColorCorrection,
    pHelpString: "Display the color correction layer information.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__print_colorcorrection__);
}

//------------------------------------------------------------------------------
// Address: 0x103141A0
// Name: _dynamic_initializer_for__LOG_CONSOLE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_CONSOLE__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "Console",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_13);
  LOG_CONSOLE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10314230
// Name: _dynamic_initializer_for__con_trace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_trace__()
{
  ConVar::ConVar(
    this: &con_trace,
    pName: "con_trace",
    pDefaultValue: "0",
    flags: 0x800000,
    pHelpString: "Print console text to low level printout.");
  return atexit(func: dynamic_atexit_destructor_for__con_trace__);
}

//------------------------------------------------------------------------------
// Address: 0x10314260
// Name: _dynamic_initializer_for__con_notifytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_notifytime__()
{
  ConVar::ConVar(
    this: &con_notifytime,
    pName: "con_notifytime",
    pDefaultValue: "8",
    flags: 0x800000,
    pHelpString: "How long to display recent console text to the upper part of the game window");
  return atexit(func: dynamic_atexit_destructor_for__con_notifytime__);
}

//------------------------------------------------------------------------------
// Address: 0x10314290
// Name: _dynamic_initializer_for__con_times__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_times__()
{
  ConVar::ConVar(
    this: &con_times,
    pName: "contimes",
    pDefaultValue: "8",
    flags: 0x800000,
    pHelpString: "Number of console lines to overlay for debugging.");
  return atexit(func: dynamic_atexit_destructor_for__con_times__);
}

//------------------------------------------------------------------------------
// Address: 0x103142C0
// Name: _dynamic_initializer_for__con_drawnotify__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_drawnotify__()
{
  ConVar::ConVar(
    this: &con_drawnotify,
    pName: "con_drawnotify",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Disables drawing of notification area (for taking screenshots).");
  return atexit(func: dynamic_atexit_destructor_for__con_drawnotify__);
}

//------------------------------------------------------------------------------
// Address: 0x103142F0
// Name: _dynamic_initializer_for__con_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_enable__()
{
  ConVar::ConVar(
    this: &con_enable,
    pName: "con_enable",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Allows the console to be activated.");
  return atexit(func: dynamic_atexit_destructor_for__con_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10314320
// Name: _dynamic_initializer_for__con_filter_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_filter_enable__()
{
  ConVar::ConVar(
    this: &con_filter_enable,
    pName: "con_filter_enable",
    pDefaultValue: "0",
    flags: 0x800000,
    pHelpString: "Filters console output based on the setting of con_filter_text. 1 filters completely, 2 displays filtered text brigh"
    "ter than other text.");
  return atexit(func: dynamic_atexit_destructor_for__con_filter_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10314350
// Name: _dynamic_initializer_for__con_filter_text__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_filter_text__()
{
  ConVar::ConVar(
    this: &con_filter_text,
    pName: "con_filter_text",
    pDefaultValue: defaultValue,
    flags: 0x800000,
    pHelpString: "Text with which to filter console spew. Set con_filter_enable 1 or 2 to activate.");
  return atexit(func: dynamic_atexit_destructor_for__con_filter_text__);
}

//------------------------------------------------------------------------------
// Address: 0x10314380
// Name: _dynamic_initializer_for__con_filter_text_out__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_filter_text_out__()
{
  ConVar::ConVar(
    this: &con_filter_text_out,
    pName: "con_filter_text_out",
    pDefaultValue: defaultValue,
    flags: 0x800000,
    pHelpString: "Text with which to filter OUT of console spew. Set con_filter_enable 1 or 2 to activate.");
  return atexit(func: dynamic_atexit_destructor_for__con_filter_text_out__);
}

//------------------------------------------------------------------------------
// Address: 0x103143B0
// Name: _dynamic_initializer_for__con_nprint_bgalpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_nprint_bgalpha__()
{
  ConVar::ConVar(
    this: &con_nprint_bgalpha,
    pName: "con_nprint_bgalpha",
    pDefaultValue: "50",
    flags: 0,
    pHelpString: "Con_NPrint background alpha.");
  return atexit(func: dynamic_atexit_destructor_for__con_nprint_bgalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x103143E0
// Name: _dynamic_initializer_for__con_nprint_bgborder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__con_nprint_bgborder__()
{
  ConVar::ConVar(
    this: &con_nprint_bgborder,
    pName: "con_nprint_bgborder",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "Con_NPrint border size.");
  return atexit(func: dynamic_atexit_destructor_for__con_nprint_bgborder__);
}

//------------------------------------------------------------------------------
// Address: 0x10314410
// Name: _dynamic_initializer_for__toggleconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__toggleconsole__()
{
  ConCommand::ConCommand(
    this: &toggleconsole,
    pName: "toggleconsole",
    callback: Con_ToggleConsole_f,
    pHelpString: "Show/hide the console.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__toggleconsole__);
}

//------------------------------------------------------------------------------
// Address: 0x10314440
// Name: _dynamic_initializer_for__hideconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hideconsole__()
{
  ConCommand::ConCommand(
    this: &hideconsole,
    pName: "hideconsole",
    callback: Con_HideConsole_f,
    pHelpString: "Hide the console.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hideconsole__);
}

//------------------------------------------------------------------------------
// Address: 0x10314470
// Name: _dynamic_initializer_for__showconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showconsole__()
{
  ConCommand::ConCommand(
    this: &showconsole,
    pName: "showconsole",
    callback: Con_ShowConsole_f,
    pHelpString: "Show the console.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showconsole__);
}

//------------------------------------------------------------------------------
// Address: 0x103144A0
// Name: _dynamic_initializer_for__clear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clear__()
{
  ConCommand::ConCommand(
    this: &clear,
    pName: "clear",
    callback: Con_Clear_f,
    pHelpString: "Clear all console output.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__clear__);
}

//------------------------------------------------------------------------------
// Address: 0x103144D0
// Name: _dynamic_initializer_for__log_dumpchannels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_dumpchannels__()
{
  ConCommand::ConCommand(
    this: &log_dumpchannels,
    pName: "log_dumpchannels",
    callback: Con_LogDumpChannels_f,
    pHelpString: "Dumps information about all logging channels.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_dumpchannels__);
}

//------------------------------------------------------------------------------
// Address: 0x10314500
// Name: _dynamic_initializer_for__log_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_level__()
{
  ConCommand::ConCommand(
    this: &log_level,
    pName: "log_level",
    callback: (void (__cdecl *)())Con_LogLevel_f,
    pHelpString: "Set the spew level of a logging channel.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_level__);
}

//------------------------------------------------------------------------------
// Address: 0x10314530
// Name: _dynamic_initializer_for__log_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_color__()
{
  ConCommand::ConCommand(
    this: &log_color,
    pName: "log_color",
    callback: (void (__cdecl *)())Con_LogColor_f,
    pHelpString: "Set the color of a logging channel.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_color__);
}

//------------------------------------------------------------------------------
// Address: 0x10314560
// Name: _dynamic_initializer_for__log_flags__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_flags__()
{
  ConCommand::ConCommand(
    this: &log_flags,
    pName: "log_flags",
    callback: (void (__cdecl *)())Con_LogFlags_f,
    pHelpString: "Set the flags on a logging channel.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_flags__);
}

//------------------------------------------------------------------------------
// Address: 0x10314A10
// Name: _dynamic_initializer_for__g_WorldStaticMeshes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WorldStaticMeshes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WorldStaticMeshes__);
}

//------------------------------------------------------------------------------
// Address: 0x10315A60
// Name: _dynamic_initializer_for__g_PowerOfTwoFBTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PowerOfTwoFBTexture__()
{
  CTextureReference::CTextureReference(this: &g_PowerOfTwoFBTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_PowerOfTwoFBTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10315A80
// Name: _dynamic_initializer_for__g_WaterReflectionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WaterReflectionTexture__()
{
  CTextureReference::CTextureReference(this: &g_WaterReflectionTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_WaterReflectionTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10315AA0
// Name: _dynamic_initializer_for__g_WaterRefractionTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WaterRefractionTexture__()
{
  CTextureReference::CTextureReference(this: &g_WaterRefractionTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_WaterRefractionTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10315AC0
// Name: _dynamic_initializer_for__g_CameraTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CameraTexture__()
{
  CTextureReference::CTextureReference(this: &g_CameraTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_CameraTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10315AE0
// Name: _dynamic_initializer_for__g_BuildCubemaps16BitTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BuildCubemaps16BitTexture__()
{
  CTextureReference::CTextureReference(this: &g_BuildCubemaps16BitTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_BuildCubemaps16BitTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10315B00
// Name: _dynamic_initializer_for__g_QuarterSizedFBTexture0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuarterSizedFBTexture0__()
{
  CTextureReference::CTextureReference(this: &g_QuarterSizedFBTexture0);
  return atexit(func: dynamic_atexit_destructor_for__g_QuarterSizedFBTexture0__);
}

//------------------------------------------------------------------------------
// Address: 0x10315B20
// Name: _dynamic_initializer_for__g_QuarterSizedFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuarterSizedFBTexture1__()
{
  CTextureReference::CTextureReference(this: &g_QuarterSizedFBTexture1);
  return atexit(func: dynamic_atexit_destructor_for__g_QuarterSizedFBTexture1__);
}

//------------------------------------------------------------------------------
// Address: 0x10315B40
// Name: _dynamic_initializer_for__g_QuarterSizedFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuarterSizedFBTexture2__()
{
  CTextureReference::CTextureReference(this: &g_QuarterSizedFBTexture2);
  return atexit(func: dynamic_atexit_destructor_for__g_QuarterSizedFBTexture2__);
}

//------------------------------------------------------------------------------
// Address: 0x10315B60
// Name: _dynamic_initializer_for__g_QuarterSizedFBTexture3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuarterSizedFBTexture3__()
{
  CTextureReference::CTextureReference(this: &g_QuarterSizedFBTexture3);
  return atexit(func: dynamic_atexit_destructor_for__g_QuarterSizedFBTexture3__);
}

//------------------------------------------------------------------------------
// Address: 0x10315BA0
// Name: _dynamic_initializer_for__g_TeenyFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TeenyFBTexture1__()
{
  CTextureReference::CTextureReference(this: &g_TeenyFBTexture1);
  return atexit(func: dynamic_atexit_destructor_for__g_TeenyFBTexture1__);
}

//------------------------------------------------------------------------------
// Address: 0x10315BC0
// Name: _dynamic_initializer_for__g_TeenyFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TeenyFBTexture2__()
{
  CTextureReference::CTextureReference(this: &g_TeenyFBTexture2);
  return atexit(func: dynamic_atexit_destructor_for__g_TeenyFBTexture2__);
}

//------------------------------------------------------------------------------
// Address: 0x10315C00
// Name: _dynamic_initializer_for__g_FullFrameFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FullFrameFBTexture1__()
{
  CTextureReference::CTextureReference(this: &g_FullFrameFBTexture1);
  return atexit(func: dynamic_atexit_destructor_for__g_FullFrameFBTexture1__);
}

//------------------------------------------------------------------------------
// Address: 0x10315C20
// Name: _dynamic_initializer_for__g_FullFrameFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FullFrameFBTexture2__()
{
  CTextureReference::CTextureReference(this: &g_FullFrameFBTexture2);
  return atexit(func: dynamic_atexit_destructor_for__g_FullFrameFBTexture2__);
}

//------------------------------------------------------------------------------
// Address: 0x10316290
// Name: _dynamic_initializer_for__g_Meshes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Meshes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Meshes__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F3E0
// Name: _dynamic_initializer_for__g_FocusPanelList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FocusPanelList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FocusPanelList__);
}

//------------------------------------------------------------------------------
// Address: 0x10322480
// Name: _dynamic_atexit_destructor_for__envmap_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__envmap_command__()
{
  ConCommand::~ConCommand(this: &envmap_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322490
// Name: _dynamic_atexit_destructor_for__lightprobe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lightprobe_command__()
{
  ConCommand::~ConCommand(this: &lightprobe_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322CB0
// Name: _dynamic_atexit_destructor_for__colorcorrectionui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__colorcorrectionui__()
{
  ConCommand::~ConCommand(this: &colorcorrectionui);
}

//------------------------------------------------------------------------------
// Address: 0x10322D20
// Name: _dynamic_atexit_destructor_for__con_timestamp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_timestamp__()
{
  ConVar::~ConVar(this: &con_timestamp);
}

//------------------------------------------------------------------------------
// Address: 0x10322D30
// Name: _dynamic_atexit_destructor_for__con_logfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_logfile__()
{
  ConVar::~ConVar(this: &con_logfile);
}

//------------------------------------------------------------------------------
// Address: 0x10322D40
// Name: _dynamic_atexit_destructor_for__con_trace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_trace__()
{
  ConVar::~ConVar(this: &con_trace);
}

//------------------------------------------------------------------------------
// Address: 0x10322D50
// Name: _dynamic_atexit_destructor_for__con_notifytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_notifytime__()
{
  ConVar::~ConVar(this: &con_notifytime);
}

//------------------------------------------------------------------------------
// Address: 0x10322D60
// Name: _dynamic_atexit_destructor_for__con_times__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_times__()
{
  ConVar::~ConVar(this: &con_times);
}

//------------------------------------------------------------------------------
// Address: 0x10322D70
// Name: _dynamic_atexit_destructor_for__con_drawnotify__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_drawnotify__()
{
  ConVar::~ConVar(this: &con_drawnotify);
}

//------------------------------------------------------------------------------
// Address: 0x10322D80
// Name: _dynamic_atexit_destructor_for__con_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_enable__()
{
  ConVar::~ConVar(this: &con_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10322D90
// Name: _dynamic_atexit_destructor_for__con_filter_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_filter_enable__()
{
  ConVar::~ConVar(this: &con_filter_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10322DA0
// Name: _dynamic_atexit_destructor_for__con_filter_text__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_filter_text__()
{
  ConVar::~ConVar(this: &con_filter_text);
}

//------------------------------------------------------------------------------
// Address: 0x10322DB0
// Name: _dynamic_atexit_destructor_for__con_filter_text_out__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_filter_text_out__()
{
  ConVar::~ConVar(this: &con_filter_text_out);
}

//------------------------------------------------------------------------------
// Address: 0x10322DC0
// Name: _dynamic_atexit_destructor_for__con_nprint_bgalpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_nprint_bgalpha__()
{
  ConVar::~ConVar(this: &con_nprint_bgalpha);
}

//------------------------------------------------------------------------------
// Address: 0x10322DD0
// Name: _dynamic_atexit_destructor_for__con_nprint_bgborder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__con_nprint_bgborder__()
{
  ConVar::~ConVar(this: &con_nprint_bgborder);
}

//------------------------------------------------------------------------------
// Address: 0x10322DE0
// Name: _dynamic_atexit_destructor_for__toggleconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__toggleconsole__()
{
  ConCommand::~ConCommand(this: &toggleconsole);
}

//------------------------------------------------------------------------------
// Address: 0x10322DF0
// Name: _dynamic_atexit_destructor_for__hideconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hideconsole__()
{
  ConCommand::~ConCommand(this: &hideconsole);
}

//------------------------------------------------------------------------------
// Address: 0x10322E00
// Name: _dynamic_atexit_destructor_for__showconsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showconsole__()
{
  ConCommand::~ConCommand(this: &showconsole);
}

//------------------------------------------------------------------------------
// Address: 0x10322E10
// Name: _dynamic_atexit_destructor_for__clear__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__clear__()
{
  ConCommand::~ConCommand(this: &clear);
}

//------------------------------------------------------------------------------
// Address: 0x10322E20
// Name: _dynamic_atexit_destructor_for__log_dumpchannels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_dumpchannels__()
{
  ConCommand::~ConCommand(this: &log_dumpchannels);
}

//------------------------------------------------------------------------------
// Address: 0x10322E30
// Name: _dynamic_atexit_destructor_for__log_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_level__()
{
  ConCommand::~ConCommand(this: &log_level);
}

//------------------------------------------------------------------------------
// Address: 0x10322E40
// Name: _dynamic_atexit_destructor_for__log_color__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_color__()
{
  ConCommand::~ConCommand(this: &log_color);
}

//------------------------------------------------------------------------------
// Address: 0x10322E50
// Name: _dynamic_atexit_destructor_for__log_flags__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_flags__()
{
  ConCommand::~ConCommand(this: &log_flags);
}

//------------------------------------------------------------------------------
// Address: 0x10323160
// Name: _dynamic_atexit_destructor_for__g_WorldStaticMeshes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WorldStaticMeshes__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_WorldStaticMeshes);
}

//------------------------------------------------------------------------------
// Address: 0x103237A0
// Name: _dynamic_atexit_destructor_for__g_QuarterSizedFBTexture1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuarterSizedFBTexture1__()
{
  CTextureReference::~CTextureReference(this: &g_QuarterSizedFBTexture1);
}

//------------------------------------------------------------------------------
// Address: 0x103237B0
// Name: _dynamic_atexit_destructor_for__g_QuarterSizedFBTexture2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuarterSizedFBTexture2__()
{
  CTextureReference::~CTextureReference(this: &g_QuarterSizedFBTexture2);
}

//------------------------------------------------------------------------------
// Address: 0x103237C0
// Name: _dynamic_atexit_destructor_for__g_QuarterSizedFBTexture3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuarterSizedFBTexture3__()
{
  CTextureReference::~CTextureReference(this: &g_QuarterSizedFBTexture3);
}

//------------------------------------------------------------------------------
// Address: 0x10323A50
// Name: _dynamic_atexit_destructor_for__g_Meshes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Meshes__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_Meshes);
}

} // namespace engine_xlsp
