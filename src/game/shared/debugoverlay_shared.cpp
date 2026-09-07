// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/debugoverlay_shared.cpp
// Functions: 139
// ============================================================

#include "game\shared\debugoverlay_shared.h"

//------------------------------------------------------------------------------
// Address: 0x100C59B0
// Name: void NDebugOverlay::Line(class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Line(
        const Vector *origin,
        const Vector *target,
        int r,
        int g,
        int b,
        int noDepthTest,
        float duration)
{
  if ( C_BasePlayer::GetLocalPlayer(nSlot: 0) != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(const Vector *, const Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: origin,
      a2: target,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(duration));
}

//------------------------------------------------------------------------------
// Address: 0x100C5A00
// Name: void NDebugOverlay::EntityTextAtPosition(class Vector const __near &,int,char const __near *,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::EntityTextAtPosition(
        const Vector *origin,
        int text_offset,
        const char *text,
        float duration,
        int r,
        int g,
        int b,
        int a)
{
  if ( debugoverlay != nullptr )
    ((void (__cdecl *)(IVDebugOverlay *, const Vector *, int, _DWORD, int, int, int, int, const char *))debugoverlay->AddTextOverlayRGB)(
      a1: debugoverlay,
      a2: origin,
      a3: text_offset,
      a4: LODWORD(duration),
      a5: r,
      a6: g,
      a7: b,
      a8: a,
      a9: text);
}

//------------------------------------------------------------------------------
// Address: 0x100C5A40
// Name: void NDebugOverlay::Box(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Box(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        int r,
        int g,
        int b,
        int a,
        float flDuration)
{
  if ( debugoverlay != nullptr )
    ((void (__stdcall *)(const Vector *, const Vector *, const Vector *, QAngle *, int, int, int, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: origin,
      a2: mins,
      a3: maxs,
      a4: &vec3_angle,
      a5: r,
      a6: g,
      a7: b,
      a8: a,
      a9: LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x100C5A90
// Name: void NDebugOverlay::Cross(class Vector const __near &,float,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Cross(
        const Vector *position,
        float radius,
        int r,
        int g,
        int b,
        int bNoDepthTest,
        float flDuration)
{
  C_BasePlayer *LocalPlayer; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  Vector clientForward; // [esp+2Ch] [ebp-3Ch] BYREF
  Vector clientUp; // [esp+38h] [ebp-30h] BYREF
  float v16; // [esp+44h] [ebp-24h] BYREF
  float v17; // [esp+48h] [ebp-20h]
  float v18; // [esp+4Ch] [ebp-1Ch]
  float v19; // [esp+50h] [ebp-18h] BYREF
  float v20; // [esp+54h] [ebp-14h]
  float v21; // [esp+58h] [ebp-10h]
  Vector clientRight; // [esp+5Ch] [ebp-Ch] BYREF

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
  if ( LocalPlayer != nullptr )
  {
    C_BasePlayer::EyeVectors(this: LocalPlayer, pForward: &clientForward, pRight: &clientRight, pUp: &clientUp);
    x = position->x;
    v19 = position->x + (float)(clientRight.x * radius);
    y = position->y;
    v20 = y + (float)(clientRight.y * radius);
    v10 = position->z - (float)(clientRight.z * radius);
    v21 = position->z + (float)(clientRight.z * radius);
    v16 = x - (float)(clientRight.x * radius);
    v17 = y - (float)(clientRight.y * radius);
    v18 = v10;
    if ( C_BasePlayer::GetLocalPlayer(nSlot: 0) != nullptr && debugoverlay != nullptr )
      ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
        a1: &v16,
        a2: &v19,
        a3: r,
        a4: g,
        a5: b,
        a6: bNoDepthTest,
        a7: LODWORD(flDuration));
    v11 = position->x;
    v16 = position->x + (float)(clientUp.x * radius);
    v12 = position->y;
    v17 = v12 + (float)(clientUp.y * radius);
    v13 = position->z - (float)(clientUp.z * radius);
    v18 = position->z + (float)(clientUp.z * radius);
    v19 = v11 - (float)(clientUp.x * radius);
    v20 = v12 - (float)(clientUp.y * radius);
    v21 = v13;
    if ( C_BasePlayer::GetLocalPlayer(nSlot: 0) != nullptr && debugoverlay != nullptr )
      ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
        a1: &v19,
        a2: &v16,
        a3: r,
        a4: g,
        a5: b,
        a6: bNoDepthTest,
        a7: LODWORD(flDuration));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412880
// Name: _dynamic_initializer_for__debug_materialmodifycontrol_client__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_materialmodifycontrol_client__()
{
  ConVar::ConVar(
    this: &debug_materialmodifycontrol_client,
    pName: "debug_materialmodifycontrol_client",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__debug_materialmodifycontrol_client__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E630
// Name: _dynamic_initializer_for__debug_postproc__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_postproc__()
{
  ConVar::ConVar(
    this: &debug_postproc,
    pName: "mat_debug_postprocessing_effects",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "0 = off, 1 = show post-processing passes in quadrants of the screen, 2 = only apply post-processing to the centre of the screen");
  return atexit(func: dynamic_atexit_destructor_for__debug_postproc__);
}

//------------------------------------------------------------------------------
// Address: 0x104306E0
// Name: _dynamic_atexit_destructor_for__debug_materialmodifycontrol_client__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_materialmodifycontrol_client__()
{
  ConVar::~ConVar(this: &debug_materialmodifycontrol_client);
}

//------------------------------------------------------------------------------
// Address: 0x10434610
// Name: _dynamic_atexit_destructor_for__debug_postproc__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_postproc__()
{
  ConVar::~ConVar(this: &debug_postproc);
}

//------------------------------------------------------------------------------
// Address: 0x104128B0
// Name: _dynamic_initializer_for____g_C_MaterialModifyControlClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_MaterialModifyControlClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_MaterialModifyControlClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_MaterialModifyControlClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E660
// Name: _dynamic_initializer_for__mat_dynamic_tonemapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dynamic_tonemapping__()
{
  ConVar::ConVar(this: &mat_dynamic_tonemapping, pName: "mat_dynamic_tonemapping", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_dynamic_tonemapping__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E690
// Name: _dynamic_initializer_for__mat_tonemapping_occlusion_use_stencil__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_tonemapping_occlusion_use_stencil__()
{
  ConVar::ConVar(
    this: &mat_tonemapping_occlusion_use_stencil,
    pName: "mat_tonemapping_occlusion_use_stencil",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_tonemapping_occlusion_use_stencil__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E6C0
// Name: _dynamic_initializer_for__mat_autoexposure_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_autoexposure_max__()
{
  ConVar::ConVar(this: &mat_autoexposure_max, pName: "mat_autoexposure_max", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_autoexposure_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E6F0
// Name: _dynamic_initializer_for__mat_autoexposure_max_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_autoexposure_max_multiplier__()
{
  ConVar::ConVar(
    this: &mat_autoexposure_max_multiplier,
    pName: "mat_autoexposure_max_multiplier",
    pDefaultValue: "1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_autoexposure_max_multiplier__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E720
// Name: _dynamic_initializer_for__mat_autoexposure_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_autoexposure_min__()
{
  ConVar::ConVar(this: &mat_autoexposure_min, pName: "mat_autoexposure_min", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_autoexposure_min__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E750
// Name: _dynamic_initializer_for__mat_show_histogram__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_show_histogram__()
{
  ConVar::ConVar(this: &mat_show_histogram, pName: "mat_show_histogram", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_show_histogram__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E780
// Name: _dynamic_initializer_for__mat_hdr_uncapexposure__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_hdr_uncapexposure__()
{
  ConVar::ConVar(this: &mat_hdr_uncapexposure, pName: "mat_hdr_uncapexposure", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_hdr_uncapexposure__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E7B0
// Name: _dynamic_initializer_for__mat_force_bloom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_bloom__()
{
  ConVar::ConVar(this: &mat_force_bloom, pName: "mat_force_bloom", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_force_bloom__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E7E0
// Name: _dynamic_initializer_for__mat_disable_bloom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_disable_bloom__()
{
  ConVar::ConVar(this: &mat_disable_bloom, pName: "mat_disable_bloom", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_disable_bloom__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E810
// Name: _dynamic_initializer_for__mat_debug_bloom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_debug_bloom__()
{
  ConVar::ConVar(this: &mat_debug_bloom, pName: "mat_debug_bloom", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_debug_bloom__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E840
// Name: _dynamic_initializer_for__mat_colorcorrection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colorcorrection__()
{
  ConVar::ConVar(this: &mat_colorcorrection, pName: "mat_colorcorrection", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_colorcorrection__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E870
// Name: _dynamic_initializer_for__mat_accelerate_adjust_exposure_down__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_accelerate_adjust_exposure_down__()
{
  ConVar::ConVar(
    this: &mat_accelerate_adjust_exposure_down,
    pName: "mat_accelerate_adjust_exposure_down",
    pDefaultValue: "40.0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_accelerate_adjust_exposure_down__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E8A0
// Name: _dynamic_initializer_for__mat_hdr_manual_tonemap_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_hdr_manual_tonemap_rate__()
{
  ConVar::ConVar(
    this: &mat_hdr_manual_tonemap_rate,
    pName: "mat_hdr_manual_tonemap_rate",
    pDefaultValue: "1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_hdr_manual_tonemap_rate__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E8D0
// Name: _dynamic_initializer_for__mat_non_hdr_bloom_scalefactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_non_hdr_bloom_scalefactor__()
{
  ConVar::ConVar(
    this: &mat_non_hdr_bloom_scalefactor,
    pName: "mat_non_hdr_bloom_scalefactor",
    pDefaultValue: ".3",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_non_hdr_bloom_scalefactor__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E900
// Name: _dynamic_initializer_for__mat_bloom_scalefactor_scalar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_bloom_scalefactor_scalar__()
{
  ConVar::ConVar(
    this: &mat_bloom_scalefactor_scalar,
    pName: "mat_bloom_scalefactor_scalar",
    pDefaultValue: "1.0",
    flags: 0x80000);
  return atexit(func: dynamic_atexit_destructor_for__mat_bloom_scalefactor_scalar__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E930
// Name: _dynamic_initializer_for__mat_exposure_center_region_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_exposure_center_region_x__()
{
  ConVar::ConVar(
    this: &mat_exposure_center_region_x,
    pName: "mat_exposure_center_region_x",
    pDefaultValue: "0.9",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_exposure_center_region_x__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E960
// Name: _dynamic_initializer_for__mat_exposure_center_region_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_exposure_center_region_y__()
{
  ConVar::ConVar(
    this: &mat_exposure_center_region_y,
    pName: "mat_exposure_center_region_y",
    pDefaultValue: "0.85",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_exposure_center_region_y__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E990
// Name: _dynamic_initializer_for__mat_tonemap_algorithm__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_tonemap_algorithm__()
{
  ConVar::ConVar(
    this: &mat_tonemap_algorithm,
    pName: "mat_tonemap_algorithm",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "0 = Original Algorithm 1 = New Algorithm");
  return atexit(func: dynamic_atexit_destructor_for__mat_tonemap_algorithm__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9C0
// Name: _dynamic_initializer_for__mat_force_tonemap_percent_target__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_tonemap_percent_target__()
{
  ConVar::ConVar(
    this: &mat_force_tonemap_percent_target,
    pName: "mat_force_tonemap_percent_target",
    pDefaultValue: "-1",
    flags: 0x4000,
    pHelpString: "Override. Old default was 60.");
  return atexit(func: dynamic_atexit_destructor_for__mat_force_tonemap_percent_target__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E9F0
// Name: _dynamic_initializer_for__mat_force_tonemap_percent_bright_pixels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_tonemap_percent_bright_pixels__()
{
  ConVar::ConVar(
    this: &mat_force_tonemap_percent_bright_pixels,
    pName: "mat_force_tonemap_percent_bright_pixels",
    pDefaultValue: "-1",
    flags: 0x4000,
    pHelpString: "Override. Old value was 2.0");
  return atexit(func: dynamic_atexit_destructor_for__mat_force_tonemap_percent_bright_pixels__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA20
// Name: _dynamic_initializer_for__mat_force_tonemap_min_avglum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_tonemap_min_avglum__()
{
  ConVar::ConVar(
    this: &mat_force_tonemap_min_avglum,
    pName: "mat_force_tonemap_min_avglum",
    pDefaultValue: "-1",
    flags: 0x4000,
    pHelpString: "Override. Old default was 3.0");
  return atexit(func: dynamic_atexit_destructor_for__mat_force_tonemap_min_avglum__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA50
// Name: _dynamic_initializer_for__mat_force_tonemap_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_force_tonemap_scale__()
{
  ConVar::ConVar(this: &mat_force_tonemap_scale, pName: "mat_force_tonemap_scale", pDefaultValue: "0.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_force_tonemap_scale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EA80
// Name: _dynamic_initializer_for__mat_fullbright___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fullbright___1()
{
  ConVar::ConVar(this: &mat_fullbright, pName: "mat_fullbright", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_fullbright___1);
}

//------------------------------------------------------------------------------
// Address: 0x1041EAB0
// Name: _dynamic_initializer_for__mat_grain_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_grain_enable__()
{
  ConVar::ConVar(this: &mat_grain_enable, pName: "mat_grain_enable", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_grain_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EAE0
// Name: _dynamic_initializer_for__mat_vignette_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_vignette_enable__()
{
  ConVar::ConVar(this: &mat_vignette_enable, pName: "mat_vignette_enable", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_vignette_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB10
// Name: _dynamic_initializer_for__mat_local_contrast_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_local_contrast_enable__()
{
  ConVar::ConVar(this: &mat_local_contrast_enable, pName: "mat_local_contrast_enable", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_local_contrast_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB40
// Name: _dynamic_initializer_for__mat_blur_r__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_blur_r__()
{
  ConVar::ConVar(this: &mat_blur_r, pName: "mat_blur_r", pDefaultValue: "0.7", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_blur_r__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB70
// Name: _dynamic_initializer_for__mat_blur_g__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_blur_g__()
{
  ConVar::ConVar(this: &mat_blur_g, pName: "mat_blur_g", pDefaultValue: "0.7", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_blur_g__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EBA0
// Name: _dynamic_initializer_for__mat_blur_b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_blur_b__()
{
  ConVar::ConVar(this: &mat_blur_b, pName: "mat_blur_b", pDefaultValue: "0.7", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_blur_b__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EBD0
// Name: _dynamic_initializer_for__mat_tonemap_query_lag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_tonemap_query_lag__()
{
  ConVar::ConVar(
    this: &mat_tonemap_query_lag,
    pName: "mat_tonemap_query_lag",
    pDefaultValue: "2",
    flags: 0x4000,
    pHelpString: "Tone mapping frame lag",
    bMin: true,
    fMin: 2.0,
    bMax: true,
    fMax: 12.0);
  return atexit(func: dynamic_atexit_destructor_for__mat_tonemap_query_lag__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EC20
// Name: _dynamic_initializer_for__s_LocalPostProcessParameters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__s_LocalPostProcessParameters__()
{
  memset(dst: (int)s_LocalPostProcessParameters, value: nullptr, count: sizeof(s_LocalPostProcessParameters));
  s_LocalPostProcessParameters[0].m_flParameters[3] = 0.80000001;
  s_LocalPostProcessParameters[0].m_flParameters[4] = 1.1;
}

//------------------------------------------------------------------------------
// Address: 0x1041EC60
// Name: _dynamic_initializer_for__g_PPInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_PPInit__()
{
  s_viewFadeColor[0].x = 0.0;
  s_viewFadeColor[0].y = 0.0;
  s_viewFadeColor[0].z = 0.0;
  s_viewFadeColor[0].w = 0.0;
  s_bViewFadeModulate[0] = false;
}

//------------------------------------------------------------------------------
// Address: 0x1041EC90
// Name: _dynamic_initializer_for__g_CBloomAddFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CBloomAddFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "BloomAdd",
           a3: CCBloomAddMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041ECB0
// Name: _dynamic_initializer_for__mat_software_aa_strength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_software_aa_strength__()
{
  ConVar::ConVar(
    this: &mat_software_aa_strength,
    pName: "mat_software_aa_strength",
    pDefaultValue: "-1.0",
    flags: 0,
    pHelpString: "Software AA - perform a software anti-aliasing post-process (an alternative/supplement to MSAA). This value sets the"
    " strength of the effect: (0.0 - off), (1.0 - full)");
  return atexit(func: dynamic_atexit_destructor_for__mat_software_aa_strength__);
}

//------------------------------------------------------------------------------
// Address: 0x1041ECE0
// Name: _dynamic_initializer_for__mat_software_aa_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_software_aa_quality__()
{
  ConVar::ConVar(
    this: &mat_software_aa_quality,
    pName: "mat_software_aa_quality",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Software AA quality mode: (0 - 5-tap filter), (1 - 9-tap filter)");
  return atexit(func: dynamic_atexit_destructor_for__mat_software_aa_quality__);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED10
// Name: _dynamic_initializer_for__mat_software_aa_edge_threshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_software_aa_edge_threshold__()
{
  ConVar::ConVar(
    this: &mat_software_aa_edge_threshold,
    pName: "mat_software_aa_edge_threshold",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Software AA - adjusts the sensitivity of the software AA shader's edge detection (default 1.0 - a lower value will s"
    "often more edges, a higher value will soften fewer)");
  return atexit(func: dynamic_atexit_destructor_for__mat_software_aa_edge_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED40
// Name: _dynamic_initializer_for__mat_software_aa_blur_one_pixel_lines__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_software_aa_blur_one_pixel_lines__()
{
  ConVar::ConVar(
    this: &mat_software_aa_blur_one_pixel_lines,
    pName: "mat_software_aa_blur_one_pixel_lines",
    pDefaultValue: "0.5",
    flags: 0,
    pHelpString: "How much software AA should blur one-pixel thick lines: (0.0 - none), (1.0 - lots)");
  return atexit(func: dynamic_atexit_destructor_for__mat_software_aa_blur_one_pixel_lines__);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED70
// Name: _dynamic_initializer_for__mat_software_aa_tap_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_software_aa_tap_offset__()
{
  ConVar::ConVar(
    this: &mat_software_aa_tap_offset,
    pName: "mat_software_aa_tap_offset",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Software AA - adjusts the displacement of the taps used by the software AA shader (default 1.0 - a lower value will "
    "make the image sharper, higher will make it blurrier)");
  return atexit(func: dynamic_atexit_destructor_for__mat_software_aa_tap_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EDA0
// Name: _dynamic_initializer_for__mat_software_aa_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_software_aa_debug__()
{
  ConVar::ConVar(
    this: &mat_software_aa_debug,
    pName: "mat_software_aa_debug",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Software AA debug mode: (0 - off), (1 - show number of 'unlike' samples: 0->black, 1->red, 2->green, 3->blue), (2 - "
    "show anti-alias blend strength), (3 - show averaged 'unlike' colour)");
  return atexit(func: dynamic_atexit_destructor_for__mat_software_aa_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EDD0
// Name: _dynamic_initializer_for__mat_software_aa_strength_vgui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_software_aa_strength_vgui__()
{
  ConVar::ConVar(
    this: &mat_software_aa_strength_vgui,
    pName: "mat_software_aa_strength_vgui",
    pDefaultValue: "-1.0",
    flags: 0,
    pHelpString: "Same as mat_software_aa_strength, but forced to this value when called by the post vgui AA pass.");
  return atexit(func: dynamic_atexit_destructor_for__mat_software_aa_strength_vgui__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE00
// Name: _dynamic_initializer_for__g_Cengine_postFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cengine_postFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "engine_post",
           a3: CCEnginePostMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE20
// Name: _dynamic_initializer_for__mat_dump_rts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dump_rts__()
{
  ConVar::ConVar(this: &mat_dump_rts, pName: "mat_dump_rts", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mat_dump_rts__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE50
// Name: _dynamic_initializer_for__r_queued_post_processing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_queued_post_processing__()
{
  ConVar::ConVar(this: &r_queued_post_processing, pName: "r_queued_post_processing", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_queued_post_processing__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE80
// Name: _dynamic_initializer_for__mat_postprocess_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_postprocess_x__()
{
  ConVar::ConVar(this: &mat_postprocess_x, pName: "mat_postprocess_x", pDefaultValue: "4", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_postprocess_x__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EEB0
// Name: _dynamic_initializer_for__mat_postprocess_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_postprocess_y__()
{
  ConVar::ConVar(this: &mat_postprocess_y, pName: "mat_postprocess_y", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_postprocess_y__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EEE0
// Name: _dynamic_initializer_for__mat_postprocess_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_postprocess_enable__()
{
  ConVar::ConVar(this: &mat_postprocess_enable, pName: "mat_postprocess_enable", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_postprocess_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF10
// Name: _dynamic_initializer_for__g_CMotionBlurFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CMotionBlurFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "MotionBlur",
           a3: CCMotionBlurMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF30
// Name: _dynamic_initializer_for__mat_motion_blur_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_enabled__()
{
  ConVar::ConVar(this: &mat_motion_blur_enabled, pName: "mat_motion_blur_enabled", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF60
// Name: _dynamic_initializer_for__mat_motion_blur_forward_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_forward_enabled__()
{
  ConVar::ConVar(
    this: &mat_motion_blur_forward_enabled,
    pName: "mat_motion_blur_forward_enabled",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_forward_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF90
// Name: _dynamic_initializer_for__mat_motion_blur_falling_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_falling_min__()
{
  ConVar::ConVar(
    this: &mat_motion_blur_falling_min,
    pName: "mat_motion_blur_falling_min",
    pDefaultValue: "10.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_falling_min__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EFC0
// Name: _dynamic_initializer_for__mat_motion_blur_falling_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_falling_max__()
{
  ConVar::ConVar(
    this: &mat_motion_blur_falling_max,
    pName: "mat_motion_blur_falling_max",
    pDefaultValue: "20.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_falling_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F000
// Name: _dynamic_initializer_for__mat_motion_blur_falling_intensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_falling_intensity__()
{
  ConVar::ConVar(
    this: &mat_motion_blur_falling_intensity,
    pName: "mat_motion_blur_falling_intensity",
    pDefaultValue: "1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_falling_intensity__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F030
// Name: _dynamic_initializer_for__mat_motion_blur_rotation_intensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_rotation_intensity__()
{
  ConVar::ConVar(
    this: &mat_motion_blur_rotation_intensity,
    pName: "mat_motion_blur_rotation_intensity",
    pDefaultValue: "1.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_rotation_intensity__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F060
// Name: _dynamic_initializer_for__mat_motion_blur_strength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_motion_blur_strength__()
{
  ConVar::ConVar(this: &mat_motion_blur_strength, pName: "mat_motion_blur_strength", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_motion_blur_strength__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F090
// Name: _dynamic_initializer_for__mat_dof_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_enabled__()
{
  ConVar::ConVar(this: &mat_dof_enabled, pName: "mat_dof_enabled", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0C0
// Name: _dynamic_initializer_for__mat_dof_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_override__()
{
  ConVar::ConVar(this: &mat_dof_override, pName: "mat_dof_override", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_override__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0F0
// Name: _dynamic_initializer_for__mat_dof_near_blur_depth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_near_blur_depth__()
{
  ConVar::ConVar(this: &mat_dof_near_blur_depth, pName: "mat_dof_near_blur_depth", pDefaultValue: "20.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_near_blur_depth__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F120
// Name: _dynamic_initializer_for__mat_dof_near_focus_depth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_near_focus_depth__()
{
  ConVar::ConVar(this: &mat_dof_near_focus_depth, pName: "mat_dof_near_focus_depth", pDefaultValue: "100.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_near_focus_depth__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F150
// Name: _dynamic_initializer_for__mat_dof_far_focus_depth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_far_focus_depth__()
{
  ConVar::ConVar(this: &mat_dof_far_focus_depth, pName: "mat_dof_far_focus_depth", pDefaultValue: "250.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_far_focus_depth__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F180
// Name: _dynamic_initializer_for__mat_dof_far_blur_depth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_far_blur_depth__()
{
  ConVar::ConVar(this: &mat_dof_far_blur_depth, pName: "mat_dof_far_blur_depth", pDefaultValue: "1000.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_far_blur_depth__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F1B0
// Name: _dynamic_initializer_for__mat_dof_near_blur_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_near_blur_radius__()
{
  ConVar::ConVar(this: &mat_dof_near_blur_radius, pName: "mat_dof_near_blur_radius", pDefaultValue: "10.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_near_blur_radius__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F1E0
// Name: _dynamic_initializer_for__mat_dof_far_blur_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_far_blur_radius__()
{
  ConVar::ConVar(this: &mat_dof_far_blur_radius, pName: "mat_dof_far_blur_radius", pDefaultValue: "5.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_far_blur_radius__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F210
// Name: _dynamic_initializer_for__mat_dof_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dof_quality__()
{
  ConVar::ConVar(this: &mat_dof_quality, pName: "mat_dof_quality", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_dof_quality__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F240
// Name: _dynamic_initializer_for__cl_blurClearAlpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_blurClearAlpha__()
{
  ConVar::ConVar(
    this: &cl_blurClearAlpha,
    pName: "cl_blurClearAlpha",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "0-255, but 0 has errors at the moment");
  return atexit(func: dynamic_atexit_destructor_for__cl_blurClearAlpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F270
// Name: _dynamic_initializer_for__cl_blurDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_blurDebug__()
{
  ConVar::ConVar(this: &cl_blurDebug, pName: "cl_blurDebug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_blurDebug__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F2A0
// Name: _dynamic_initializer_for__cl_blurTapSize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_blurTapSize__()
{
  ConVar::ConVar(this: &cl_blurTapSize, pName: "cl_blurTapSize", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_blurTapSize__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F2D0
// Name: _dynamic_initializer_for__cl_blurPasses__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_blurPasses__()
{
  ConVar::ConVar(this: &cl_blurPasses, pName: "cl_blurPasses", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_blurPasses__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F300
// Name: _dynamic_initializer_for__g_Precipitations___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Precipitations___0()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Precipitations___0);
}

//------------------------------------------------------------------------------
// Address: 0x10434620
// Name: _dynamic_atexit_destructor_for__mat_dynamic_tonemapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dynamic_tonemapping__()
{
  ConVar::~ConVar(this: &mat_dynamic_tonemapping);
}

//------------------------------------------------------------------------------
// Address: 0x10434630
// Name: _dynamic_atexit_destructor_for__mat_tonemapping_occlusion_use_stencil__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_tonemapping_occlusion_use_stencil__()
{
  ConVar::~ConVar(this: &mat_tonemapping_occlusion_use_stencil);
}

//------------------------------------------------------------------------------
// Address: 0x10434640
// Name: _dynamic_atexit_destructor_for__mat_autoexposure_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_autoexposure_max__()
{
  ConVar::~ConVar(this: &mat_autoexposure_max);
}

//------------------------------------------------------------------------------
// Address: 0x10434650
// Name: _dynamic_atexit_destructor_for__mat_autoexposure_max_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_autoexposure_max_multiplier__()
{
  ConVar::~ConVar(this: &mat_autoexposure_max_multiplier);
}

//------------------------------------------------------------------------------
// Address: 0x10434660
// Name: _dynamic_atexit_destructor_for__mat_autoexposure_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_autoexposure_min__()
{
  ConVar::~ConVar(this: &mat_autoexposure_min);
}

//------------------------------------------------------------------------------
// Address: 0x10434670
// Name: _dynamic_atexit_destructor_for__mat_show_histogram__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_show_histogram__()
{
  ConVar::~ConVar(this: &mat_show_histogram);
}

//------------------------------------------------------------------------------
// Address: 0x10434680
// Name: _dynamic_atexit_destructor_for__mat_hdr_uncapexposure__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_hdr_uncapexposure__()
{
  ConVar::~ConVar(this: &mat_hdr_uncapexposure);
}

//------------------------------------------------------------------------------
// Address: 0x10434690
// Name: _dynamic_atexit_destructor_for__mat_force_bloom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_bloom__()
{
  ConVar::~ConVar(this: &mat_force_bloom);
}

//------------------------------------------------------------------------------
// Address: 0x104346A0
// Name: _dynamic_atexit_destructor_for__mat_disable_bloom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_disable_bloom__()
{
  ConVar::~ConVar(this: &mat_disable_bloom);
}

//------------------------------------------------------------------------------
// Address: 0x104346B0
// Name: _dynamic_atexit_destructor_for__mat_debug_bloom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debug_bloom__()
{
  ConVar::~ConVar(this: &mat_debug_bloom);
}

//------------------------------------------------------------------------------
// Address: 0x104346C0
// Name: _dynamic_atexit_destructor_for__mat_colorcorrection__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_colorcorrection__()
{
  ConVar::~ConVar(this: &mat_colorcorrection);
}

//------------------------------------------------------------------------------
// Address: 0x104346D0
// Name: _dynamic_atexit_destructor_for__mat_accelerate_adjust_exposure_down__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_accelerate_adjust_exposure_down__()
{
  ConVar::~ConVar(this: &mat_accelerate_adjust_exposure_down);
}

//------------------------------------------------------------------------------
// Address: 0x104346E0
// Name: _dynamic_atexit_destructor_for__mat_hdr_manual_tonemap_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_hdr_manual_tonemap_rate__()
{
  ConVar::~ConVar(this: &mat_hdr_manual_tonemap_rate);
}

//------------------------------------------------------------------------------
// Address: 0x104346F0
// Name: _dynamic_atexit_destructor_for__mat_non_hdr_bloom_scalefactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_non_hdr_bloom_scalefactor__()
{
  ConVar::~ConVar(this: &mat_non_hdr_bloom_scalefactor);
}

//------------------------------------------------------------------------------
// Address: 0x10434700
// Name: _dynamic_atexit_destructor_for__mat_bloom_scalefactor_scalar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_bloom_scalefactor_scalar__()
{
  ConVar::~ConVar(this: &mat_bloom_scalefactor_scalar);
}

//------------------------------------------------------------------------------
// Address: 0x10434710
// Name: _dynamic_atexit_destructor_for__mat_exposure_center_region_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_exposure_center_region_x__()
{
  ConVar::~ConVar(this: &mat_exposure_center_region_x);
}

//------------------------------------------------------------------------------
// Address: 0x10434720
// Name: _dynamic_atexit_destructor_for__mat_exposure_center_region_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_exposure_center_region_y__()
{
  ConVar::~ConVar(this: &mat_exposure_center_region_y);
}

//------------------------------------------------------------------------------
// Address: 0x10434730
// Name: _dynamic_atexit_destructor_for__mat_tonemap_algorithm__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_tonemap_algorithm__()
{
  ConVar::~ConVar(this: &mat_tonemap_algorithm);
}

//------------------------------------------------------------------------------
// Address: 0x10434740
// Name: _dynamic_atexit_destructor_for__mat_force_tonemap_percent_target__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_tonemap_percent_target__()
{
  ConVar::~ConVar(this: &mat_force_tonemap_percent_target);
}

//------------------------------------------------------------------------------
// Address: 0x10434750
// Name: _dynamic_atexit_destructor_for__mat_force_tonemap_percent_bright_pixels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_tonemap_percent_bright_pixels__()
{
  ConVar::~ConVar(this: &mat_force_tonemap_percent_bright_pixels);
}

//------------------------------------------------------------------------------
// Address: 0x10434760
// Name: _dynamic_atexit_destructor_for__mat_force_tonemap_min_avglum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_tonemap_min_avglum__()
{
  ConVar::~ConVar(this: &mat_force_tonemap_min_avglum);
}

//------------------------------------------------------------------------------
// Address: 0x10434770
// Name: _dynamic_atexit_destructor_for__mat_force_tonemap_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_force_tonemap_scale__()
{
  ConVar::~ConVar(this: &mat_force_tonemap_scale);
}

//------------------------------------------------------------------------------
// Address: 0x10434780
// Name: _dynamic_atexit_destructor_for__mat_fullbright___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fullbright___1()
{
  ConVar::~ConVar(this: &mat_fullbright);
}

//------------------------------------------------------------------------------
// Address: 0x10434790
// Name: _dynamic_atexit_destructor_for__mat_grain_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_grain_enable__()
{
  ConVar::~ConVar(this: &mat_grain_enable);
}

//------------------------------------------------------------------------------
// Address: 0x104347A0
// Name: _dynamic_atexit_destructor_for__mat_vignette_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_vignette_enable__()
{
  ConVar::~ConVar(this: &mat_vignette_enable);
}

//------------------------------------------------------------------------------
// Address: 0x104347B0
// Name: _dynamic_atexit_destructor_for__mat_local_contrast_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_local_contrast_enable__()
{
  ConVar::~ConVar(this: &mat_local_contrast_enable);
}

//------------------------------------------------------------------------------
// Address: 0x104347C0
// Name: _dynamic_atexit_destructor_for__mat_blur_r__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_blur_r__()
{
  ConVar::~ConVar(this: &mat_blur_r);
}

//------------------------------------------------------------------------------
// Address: 0x104347D0
// Name: _dynamic_atexit_destructor_for__mat_blur_g__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_blur_g__()
{
  ConVar::~ConVar(this: &mat_blur_g);
}

//------------------------------------------------------------------------------
// Address: 0x104347E0
// Name: _dynamic_atexit_destructor_for__mat_blur_b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_blur_b__()
{
  ConVar::~ConVar(this: &mat_blur_b);
}

//------------------------------------------------------------------------------
// Address: 0x104347F0
// Name: _dynamic_atexit_destructor_for__mat_tonemap_query_lag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_tonemap_query_lag__()
{
  ConVar::~ConVar(this: &mat_tonemap_query_lag);
}

//------------------------------------------------------------------------------
// Address: 0x10434800
// Name: _dynamic_atexit_destructor_for__mat_software_aa_strength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_software_aa_strength__()
{
  ConVar::~ConVar(this: &mat_software_aa_strength);
}

//------------------------------------------------------------------------------
// Address: 0x10434810
// Name: _dynamic_atexit_destructor_for__mat_software_aa_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_software_aa_quality__()
{
  ConVar::~ConVar(this: &mat_software_aa_quality);
}

//------------------------------------------------------------------------------
// Address: 0x10434820
// Name: _dynamic_atexit_destructor_for__mat_software_aa_edge_threshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_software_aa_edge_threshold__()
{
  ConVar::~ConVar(this: &mat_software_aa_edge_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x10434830
// Name: _dynamic_atexit_destructor_for__mat_software_aa_blur_one_pixel_lines__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_software_aa_blur_one_pixel_lines__()
{
  ConVar::~ConVar(this: &mat_software_aa_blur_one_pixel_lines);
}

//------------------------------------------------------------------------------
// Address: 0x10434840
// Name: _dynamic_atexit_destructor_for__mat_software_aa_tap_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_software_aa_tap_offset__()
{
  ConVar::~ConVar(this: &mat_software_aa_tap_offset);
}

//------------------------------------------------------------------------------
// Address: 0x10434850
// Name: _dynamic_atexit_destructor_for__mat_software_aa_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_software_aa_debug__()
{
  ConVar::~ConVar(this: &mat_software_aa_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10434860
// Name: _dynamic_atexit_destructor_for__mat_software_aa_strength_vgui__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_software_aa_strength_vgui__()
{
  ConVar::~ConVar(this: &mat_software_aa_strength_vgui);
}

//------------------------------------------------------------------------------
// Address: 0x10434870
// Name: _dynamic_atexit_destructor_for__mat_dump_rts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dump_rts__()
{
  ConVar::~ConVar(this: &mat_dump_rts);
}

//------------------------------------------------------------------------------
// Address: 0x10434880
// Name: _dynamic_atexit_destructor_for__r_queued_post_processing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_queued_post_processing__()
{
  ConVar::~ConVar(this: &r_queued_post_processing);
}

//------------------------------------------------------------------------------
// Address: 0x10434890
// Name: _dynamic_atexit_destructor_for__mat_postprocess_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_postprocess_x__()
{
  ConVar::~ConVar(this: &mat_postprocess_x);
}

//------------------------------------------------------------------------------
// Address: 0x104348A0
// Name: _dynamic_atexit_destructor_for__mat_postprocess_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_postprocess_y__()
{
  ConVar::~ConVar(this: &mat_postprocess_y);
}

//------------------------------------------------------------------------------
// Address: 0x104348B0
// Name: _dynamic_atexit_destructor_for__mat_postprocess_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_postprocess_enable__()
{
  ConVar::~ConVar(this: &mat_postprocess_enable);
}

//------------------------------------------------------------------------------
// Address: 0x104348C0
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_enabled__()
{
  ConVar::~ConVar(this: &mat_motion_blur_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x104348D0
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_forward_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_forward_enabled__()
{
  ConVar::~ConVar(this: &mat_motion_blur_forward_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x104348E0
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_falling_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_falling_min__()
{
  ConVar::~ConVar(this: &mat_motion_blur_falling_min);
}

//------------------------------------------------------------------------------
// Address: 0x104348F0
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_falling_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_falling_max__()
{
  ConVar::~ConVar(this: &mat_motion_blur_falling_max);
}

//------------------------------------------------------------------------------
// Address: 0x10434900
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_falling_intensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_falling_intensity__()
{
  ConVar::~ConVar(this: &mat_motion_blur_falling_intensity);
}

//------------------------------------------------------------------------------
// Address: 0x10434910
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_rotation_intensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_rotation_intensity__()
{
  ConVar::~ConVar(this: &mat_motion_blur_rotation_intensity);
}

//------------------------------------------------------------------------------
// Address: 0x10434920
// Name: _dynamic_atexit_destructor_for__mat_motion_blur_strength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_motion_blur_strength__()
{
  ConVar::~ConVar(this: &mat_motion_blur_strength);
}

//------------------------------------------------------------------------------
// Address: 0x10434930
// Name: _dynamic_atexit_destructor_for__mat_dof_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_enabled__()
{
  ConVar::~ConVar(this: &mat_dof_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x10434940
// Name: _dynamic_atexit_destructor_for__mat_dof_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_override__()
{
  ConVar::~ConVar(this: &mat_dof_override);
}

//------------------------------------------------------------------------------
// Address: 0x10434950
// Name: _dynamic_atexit_destructor_for__mat_dof_near_blur_depth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_near_blur_depth__()
{
  ConVar::~ConVar(this: &mat_dof_near_blur_depth);
}

//------------------------------------------------------------------------------
// Address: 0x10434960
// Name: _dynamic_atexit_destructor_for__mat_dof_near_focus_depth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_near_focus_depth__()
{
  ConVar::~ConVar(this: &mat_dof_near_focus_depth);
}

//------------------------------------------------------------------------------
// Address: 0x10434970
// Name: _dynamic_atexit_destructor_for__mat_dof_far_focus_depth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_far_focus_depth__()
{
  ConVar::~ConVar(this: &mat_dof_far_focus_depth);
}

//------------------------------------------------------------------------------
// Address: 0x10434980
// Name: _dynamic_atexit_destructor_for__mat_dof_far_blur_depth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_far_blur_depth__()
{
  ConVar::~ConVar(this: &mat_dof_far_blur_depth);
}

//------------------------------------------------------------------------------
// Address: 0x10434990
// Name: _dynamic_atexit_destructor_for__mat_dof_near_blur_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_near_blur_radius__()
{
  ConVar::~ConVar(this: &mat_dof_near_blur_radius);
}

//------------------------------------------------------------------------------
// Address: 0x104349A0
// Name: _dynamic_atexit_destructor_for__mat_dof_far_blur_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_far_blur_radius__()
{
  ConVar::~ConVar(this: &mat_dof_far_blur_radius);
}

//------------------------------------------------------------------------------
// Address: 0x104349B0
// Name: _dynamic_atexit_destructor_for__mat_dof_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dof_quality__()
{
  ConVar::~ConVar(this: &mat_dof_quality);
}

//------------------------------------------------------------------------------
// Address: 0x104349C0
// Name: _dynamic_atexit_destructor_for__cl_blurClearAlpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_blurClearAlpha__()
{
  ConVar::~ConVar(this: &cl_blurClearAlpha);
}

//------------------------------------------------------------------------------
// Address: 0x104349D0
// Name: _dynamic_atexit_destructor_for__cl_blurDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_blurDebug__()
{
  ConVar::~ConVar(this: &cl_blurDebug);
}

//------------------------------------------------------------------------------
// Address: 0x104349E0
// Name: _dynamic_atexit_destructor_for__cl_blurTapSize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_blurTapSize__()
{
  ConVar::~ConVar(this: &cl_blurTapSize);
}

//------------------------------------------------------------------------------
// Address: 0x104349F0
// Name: _dynamic_atexit_destructor_for__cl_blurPasses__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_blurPasses__()
{
  ConVar::~ConVar(this: &cl_blurPasses);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100FAE60
// Name: void NDebugOverlay::BoxAngles(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::BoxAngles(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *angles,
        int r,
        int g,
        int b,
        int a,
        float duration)
{
  if ( debugoverlay != nullptr )
    ((void (__thiscall *)(IVDebugOverlay *, const Vector *, const Vector *, const Vector *, const QAngle *, int, int, int, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: debugoverlay,
      a2: origin,
      a3: mins,
      a4: maxs,
      a5: angles,
      a6: r,
      a7: g,
      a8: b,
      a9: a,
      a10: LODWORD(duration));
}

//------------------------------------------------------------------------------
// Address: 0x100FAEB0
// Name: void NDebugOverlay::SweptBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::SweptBox(
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs,
        const QAngle *angles,
        int r,
        int g,
        int b,
        int a,
        float flDuration)
{
  if ( debugoverlay != nullptr )
    ((void (__thiscall *)(IVDebugOverlay *, const Vector *, const Vector *, const Vector *, const Vector *, const QAngle *, int, int, int, int, _DWORD))debugoverlay->AddSweptBoxOverlay)(
      a1: debugoverlay,
      a2: start,
      a3: end,
      a4: mins,
      a5: maxs,
      a6: angles,
      a7: r,
      a8: g,
      a9: b,
      a10: a,
      a11: LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x100FAF00
// Name: void NDebugOverlay::Line(class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Line(
        const Vector *origin,
        const Vector *target,
        int r,
        int g,
        int b,
        int noDepthTest,
        float duration)
{
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(const Vector *, const Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: origin,
      a2: target,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(duration));
}

//------------------------------------------------------------------------------
// Address: 0x100FAF50
// Name: void NDebugOverlay::EntityTextAtPosition(class Vector const __near &,int,char const __near *,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::EntityTextAtPosition(
        const Vector *origin,
        int text_offset,
        const char *text,
        float duration,
        int r,
        int g,
        int b,
        int a)
{
  if ( debugoverlay != nullptr )
    ((void (__cdecl *)(IVDebugOverlay *, const Vector *, int, _DWORD, int, int, int, int, const char *))debugoverlay->AddTextOverlayRGB)(
      a1: debugoverlay,
      a2: origin,
      a3: text_offset,
      a4: LODWORD(duration),
      a5: r,
      a6: g,
      a7: b,
      a8: a,
      a9: text);
}

//------------------------------------------------------------------------------
// Address: 0x100FAF90
// Name: void NDebugOverlay::Grid(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Grid(const Vector *vPosition)
{
  if ( debugoverlay != nullptr )
    debugoverlay->AddGridOverlay(this: debugoverlay, a2: vPosition);
}

//------------------------------------------------------------------------------
// Address: 0x100FAFB0
// Name: void NDebugOverlay::ScreenText(float,float,char const __near *,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::ScreenText(
        float flXpos,
        float flYpos,
        const char *text,
        int r,
        int g,
        int b,
        int a,
        float duration)
{
  if ( debugoverlay != nullptr )
    ((void (__thiscall *)(IVDebugOverlay *, _DWORD, _DWORD, _DWORD, int, int, int, int, const char *))debugoverlay->AddScreenTextOverlay)(
      a1: debugoverlay,
      a2: LODWORD(flXpos),
      a3: LODWORD(flYpos),
      a4: LODWORD(duration),
      a5: r,
      a6: g,
      a7: b,
      a8: a,
      a9: text);
}

//------------------------------------------------------------------------------
// Address: 0x100FB000
// Name: void NDebugOverlay::PurgeTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::PurgeTextOverlays()
{
  if ( debugoverlay != nullptr )
    debugoverlay->PurgeTextOverlays(this: debugoverlay);
}

//------------------------------------------------------------------------------
// Address: 0x100FB020
// Name: void NDebugOverlay::Box(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Box(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        int r,
        int g,
        int b,
        int a,
        float flDuration)
{
  if ( debugoverlay != nullptr )
    ((void (__stdcall *)(const Vector *, const Vector *, const Vector *, QAngle *, int, int, int, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: origin,
      a2: mins,
      a3: maxs,
      a4: &vec3_angle,
      a5: r,
      a6: g,
      a7: b,
      a8: a,
      a9: LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x100FB070
// Name: void NDebugOverlay::BoxDirection(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::BoxDirection(
        const Vector *origin,
        const Vector *mins,
        const Vector *maxs,
        const Vector *orientation,
        int r,
        int g,
        int b,
        int a,
        float duration)
{
  QAngle f_angles; // [esp+4h] [ebp-Ch] BYREF

  f_angles.x = vec3_angle.x;
  f_angles.z = vec3_angle.z;
  f_angles.y = UTIL_VecToYaw(vec: orientation);
  if ( debugoverlay != nullptr )
    ((void (__thiscall *)(IVDebugOverlay *, const Vector *, const Vector *, const Vector *, QAngle *, int, int, int, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: debugoverlay,
      a2: origin,
      a3: mins,
      a4: maxs,
      a5: &f_angles,
      a6: r,
      a7: g,
      a8: b,
      a9: a,
      a10: LODWORD(duration));
}

//------------------------------------------------------------------------------
// Address: 0x100FB0E0
// Name: void NDebugOverlay::EntityBounds(class CBaseEntity const __near *,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::EntityBounds(const CBaseEntity *pEntity, int r, int g, int b, int a, float flDuration)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // esi
  const QAngle *v7; // edi
  int v8; // ebx
  int v9; // eax
  const CBaseEntity *pEntitya; // [esp+18h] [ebp+8h]

  p_m_Collision = &pEntity->m_Collision;
  v7 = pEntity->m_Collision.GetCollisionAngles(this: &pEntity->m_Collision);
  v8 = (int)p_m_Collision->OBBMaxs(this: p_m_Collision);
  pEntitya = (const CBaseEntity *)p_m_Collision->OBBMins(this: p_m_Collision);
  v9 = (int)p_m_Collision->GetCollisionOrigin(this: p_m_Collision);
  if ( debugoverlay != nullptr )
    ((void (__thiscall *)(IVDebugOverlay *, int, const CBaseEntity *, int, const QAngle *, int, int, int, int, _DWORD))debugoverlay->AddBoxOverlay)(
      a1: debugoverlay,
      a2: v9,
      a3: pEntitya,
      a4: v8,
      a5: v7,
      a6: r,
      a7: g,
      a8: b,
      a9: a,
      a10: LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x100FB160
// Name: void NDebugOverlay::Triangle(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Triangle(
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        int r,
        int g,
        int b,
        int a,
        int noDepthTest,
        float duration)
{
  CBasePlayer *ListenServerHost; // eax
  float x; // xmm1_4
  float v11; // xmm0_4
  float z; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  Vector clipForward; // [esp+10h] [ebp-30h] BYREF
  Vector clipOrigin; // [esp+1Ch] [ebp-24h] BYREF
  Vector to3; // [esp+28h] [ebp-18h]
  Vector to2; // [esp+34h] [ebp-Ch]

  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    CBasePlayer::EyePositionAndVectors(
      this: ListenServerHost,
      pPosition: &clipOrigin,
      pForward: &clipForward,
      pRight: nullptr,
      pUp: nullptr);
    if ( g_pGameRules->IsTopDown(this: g_pGameRules) )
      goto LABEL_11;
    x = p1->x;
    v11 = p1->y - clipOrigin.y;
    z = p1->z;
    v13 = p2->x;
    v14 = p2->y - clipOrigin.y;
    to2.z = p2->z - clipOrigin.z;
    to3.x = p3->x - clipOrigin.x;
    v15 = z - clipOrigin.z;
    v16 = x - clipOrigin.x;
    to3.z = p3->z - clipOrigin.z;
    v17 = v13 - clipOrigin.x;
    v18 = p3->y - clipOrigin.y;
    v19 = to2.z;
    to2.x = v17;
    if ( (float)((float)((float)(v11 * v11) + (float)(v16 * v16)) + (float)(v15 * v15)) > 90000000.0 )
    {
      if ( (float)((float)((float)(v14 * v14) + (float)(v17 * v17)) + (float)(to2.z * to2.z)) > 90000000.0 )
      {
        if ( (float)((float)((float)(v18 * v18) + (float)(to3.x * to3.x)) + (float)(to3.z * to3.z)) > 90000000.0 )
          return;
        v19 = to2.z;
      }
      v17 = to2.x;
    }
    if ( (float)((float)((float)(v11 * clipForward.y) + (float)(v16 * clipForward.x)) + (float)(v15 * clipForward.z)) >= 0.0
      || (float)((float)((float)(v14 * clipForward.y) + (float)(v17 * clipForward.x)) + (float)(v19 * clipForward.z)) >= 0.0
      || (float)((float)((float)(v18 * clipForward.y) + (float)(to3.x * clipForward.x)) + (float)(to3.z * clipForward.z)) >= 0.0 )
    {
LABEL_11:
      if ( debugoverlay != nullptr )
        ((void (__thiscall *)(IVDebugOverlay *, const Vector *, const Vector *, const Vector *, int, int, int, int, int, _DWORD))debugoverlay->AddTriangleOverlay)(
          a1: debugoverlay,
          a2: p1,
          a3: p2,
          a4: p3,
          a5: r,
          a6: g,
          a7: b,
          a8: a,
          a9: noDepthTest,
          a10: LODWORD(duration));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB350
// Name: void NDebugOverlay::Cross3D(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Cross3D(
        const Vector *position,
        const Vector *mins,
        const Vector *maxs,
        int r,
        int g,
        int b,
        int noDepthTest,
        float fDuration)
{
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  Vector start; // [esp+64h] [ebp-18h] BYREF
  Vector end; // [esp+70h] [ebp-Ch] BYREF

  v8 = mins->x + position->x;
  v9 = mins->y + position->y;
  v10 = maxs->y + position->y;
  start.z = mins->z + position->z;
  v11 = maxs->x + position->x;
  end.y = v10;
  v12 = maxs->z + position->z;
  start.x = v8;
  start.y = v9;
  end.x = v11;
  end.z = v12;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &start,
      a2: &end,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(fDuration));
  v13 = maxs->x - mins->x;
  start.x = v13 + start.x;
  end.x = end.x - v13;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &start,
      a2: &end,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(fDuration));
  v14 = maxs->y - mins->y;
  start.y = v14 + start.y;
  end.y = end.y - v14;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &start,
      a2: &end,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(fDuration));
  v15 = maxs->x - mins->x;
  start.x = start.x - v15;
  end.x = v15 + end.x;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &start,
      a2: &end,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(fDuration));
}

//------------------------------------------------------------------------------
// Address: 0x100FB520
// Name: void NDebugOverlay::Cross3D(class Vector const __near &,float,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Cross3D(
        const Vector *position,
        float size,
        int r,
        int g,
        int b,
        int noDepthTest,
        float flDuration)
{
  float z; // xmm2_4
  float v8; // xmm0_4
  float x; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm2_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // [esp+48h] [ebp-18h] BYREF
  float v16; // [esp+4Ch] [ebp-14h]
  float v17; // [esp+50h] [ebp-10h]
  float v18; // [esp+54h] [ebp-Ch] BYREF
  float y; // [esp+58h] [ebp-8h]
  float v20; // [esp+5Ch] [ebp-4h]

  z = position->z;
  v8 = position->x + size;
  v18 = position->x - size;
  y = position->y;
  v20 = z;
  v15 = v8;
  v16 = y;
  v17 = z;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &v15,
      a2: &v18,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  x = position->x;
  v10 = position->y + size;
  v16 = position->y - size;
  v11 = position->z;
  v15 = x;
  v17 = v11;
  v18 = x;
  y = v10;
  v20 = v11;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &v18,
      a2: &v15,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  v12 = position->y;
  v13 = position->z - size;
  v14 = position->z + size;
  v15 = position->x;
  v16 = v12;
  v17 = v13;
  v18 = v15;
  y = v12;
  v20 = v14;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &v18,
      a2: &v15,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x100FB690
// Name: void NDebugOverlay::Cross3DOriented(class Vector const __near &,class QAngle const __near &,float,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Cross3DOriented(
        const Vector *position,
        const QAngle *angles,
        float size,
        int r,
        int g,
        int b,
        int noDepthTest,
        float flDuration)
{
  float x; // xmm0_4
  float y; // xmm4_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // [esp+48h] [ebp-3Ch] BYREF
  float v21; // [esp+4Ch] [ebp-38h]
  float v22; // [esp+50h] [ebp-34h]
  float v23; // [esp+54h] [ebp-30h] BYREF
  float v24; // [esp+58h] [ebp-2Ch]
  float v25; // [esp+5Ch] [ebp-28h]
  Vector right; // [esp+60h] [ebp-24h] BYREF
  Vector up; // [esp+6Ch] [ebp-18h] BYREF
  Vector forward; // [esp+78h] [ebp-Ch] BYREF

  AngleVectors(angles, &forward, &right, &up);
  forward.x = forward.x * size;
  up.x = up.x * size;
  forward.y = forward.y * size;
  up.y = up.y * size;
  forward.z = forward.z * size;
  x = position->x;
  up.z = up.z * size;
  v23 = x - (float)(right.x * size);
  y = position->y;
  v24 = y - (float)(right.y * size);
  v10 = position->z - (float)(right.z * size);
  v11 = x + (float)(right.x * size);
  v12 = y + (float)(right.y * size);
  v13 = position->z + (float)(right.z * size);
  right.x = right.x * size;
  right.y = right.y * size;
  right.z = right.z * size;
  v25 = v10;
  v20 = v11;
  v21 = v12;
  v22 = v13;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &v20,
      a2: &v23,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  v14 = position->x + forward.x;
  v20 = position->x - forward.x;
  v15 = position->y + forward.y;
  v21 = position->y - forward.y;
  v16 = position->z + forward.z;
  v22 = position->z - forward.z;
  v23 = v14;
  v24 = v15;
  v25 = v16;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &v23,
      a2: &v20,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  v17 = position->x + up.x;
  v20 = position->x - up.x;
  v18 = position->y + up.y;
  v21 = position->y - up.y;
  v19 = position->z + up.z;
  v22 = position->z - up.z;
  v23 = v17;
  v24 = v18;
  v25 = v19;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &v23,
      a2: &v20,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x100FB8E0
// Name: void NDebugOverlay::HorzArrow(class Vector const __near &,class Vector const __near &,float,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::HorzArrow(
        const Vector *startPos,
        const Vector *endPos,
        float width,
        int r,
        int g,
        int b,
        int a,
        int noDepthTest,
        float flDuration)
{
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm5_4
  float v18; // ecx
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float x; // [esp+C8h] [ebp-7Ch]
  Vector p7; // [esp+CCh] [ebp-78h] BYREF
  Vector p4; // [esp+D8h] [ebp-6Ch] BYREF
  Vector p3; // [esp+E4h] [ebp-60h] BYREF
  Vector p5; // [esp+F0h] [ebp-54h] BYREF
  Vector p2; // [esp+FCh] [ebp-48h] BYREF
  float v33; // [esp+108h] [ebp-3Ch]
  float v34; // [esp+10Ch] [ebp-38h]
  Vector p1; // [esp+114h] [ebp-30h] BYREF
  Vector p6; // [esp+120h] [ebp-24h] BYREF
  Vector lineDir; // [esp+12Ch] [ebp-18h] BYREF
  float v38; // [esp+138h] [ebp-Ch]
  float z; // [esp+13Ch] [ebp-8h]
  float y; // [esp+140h] [ebp-4h]
  float startPosa; // [esp+14Ch] [ebp+8h]
  float endPosa; // [esp+150h] [ebp+Ch]
  float widtha; // [esp+154h] [ebp+10h]

  lineDir.x = endPos->x - startPos->x;
  lineDir.y = endPos->y - startPos->y;
  lineDir.z = endPos->z - startPos->z;
  VectorNormalize(vec: &lineDir);
  v12 = lineDir.y - (float)(lineDir.z * 0.0);
  v13 = (float)(lineDir.x * 0.0) - (float)(lineDir.y * 0.0);
  v14 = (float)((float)(lineDir.z * 0.0) - lineDir.x) * (float)(width * 0.5);
  v15 = v12 * (float)(width * 0.5);
  v16 = v13 * (float)(width * 0.5);
  p1.x = startPos->x - v15;
  p1.y = startPos->y - v14;
  endPosa = lineDir.y * width;
  p1.z = startPos->z - v16;
  startPosa = lineDir.z * width;
  widtha = lineDir.x * width;
  x = endPos->x;
  v34 = endPos->y - endPosa;
  z = endPos->z;
  v33 = x - widtha;
  p2.x = (float)(x - widtha) - v15;
  p2.z = (float)(z - startPosa) - v16;
  p2.y = v34 - v14;
  v17 = v12 * width;
  y = (float)((float)(lineDir.z * 0.0) - lineDir.x) * width;
  v38 = v13 * width;
  v18 = endPos->z;
  v19 = (float)(z - startPosa) - (float)(v13 * width);
  p3.x = (float)(x - widtha) - v17;
  p3.y = v34 - y;
  *(_QWORD *)&p4.x = *(_QWORD *)&endPos->x;
  v33 = x - widtha;
  y = endPos->y;
  v34 = y - endPosa;
  v20 = endPos->z;
  p5.y = (float)((float)((float)(lineDir.z * 0.0) - lineDir.x) * width) + (float)(y - endPosa);
  z = v20;
  p5.z = (float)(v13 * width) + (float)(v20 - startPosa);
  v21 = v15;
  v22 = v15 + startPos->x;
  p5.x = v17 + (float)(x - widtha);
  v23 = v14;
  v24 = v14 + startPos->y;
  v25 = v16;
  v26 = v16 + startPos->z;
  p3.z = v19;
  p4.z = v18;
  p6.x = v21 + (float)(x - widtha);
  p6.y = v23 + (float)(y - endPosa);
  p6.z = v25 + (float)(z - startPosa);
  p7.x = v22;
  p7.y = v24;
  p7.z = v26;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p1,
      a2: &p2,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p2,
      a2: &p3,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p3,
      a2: &p4,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p4,
      a2: &p5,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p5,
      a2: &p6,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p6,
      a2: &p7,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( a > 0 )
  {
    NDebugOverlay::Triangle(p1: &p5, p2: &p4, &p3, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(&p1, p2: &p7, p3: &p6, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(p1: &p6, &p2, p3: &p1, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(p1: &p3, p2: &p4, p3: &p5, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(p1: &p6, p2: &p7, p3: &p1, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(&p1, &p2, p3: &p6, r, g, b, a, noDepthTest, duration: flDuration);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FBDA0
// Name: void NDebugOverlay::YawArrow(class Vector const __near &,float,float,float,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::YawArrow(
        const Vector *startPos,
        float yaw,
        float length,
        float width,
        int r,
        int g,
        int b,
        int a,
        int noDepthTest,
        float flDuration)
{
  float v10; // xmm3_4
  Vector endPos; // [esp+1Ch] [ebp-18h] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  UTIL_YawToVector(result: &forward, yaw);
  v10 = startPos->x + (float)(forward.x * length);
  endPos.y = startPos->y + (float)(forward.y * length);
  endPos.z = startPos->z + (float)(forward.z * length);
  endPos.x = v10;
  NDebugOverlay::HorzArrow(startPos, &endPos, width, r, g, b, a, noDepthTest, flDuration);
}

//------------------------------------------------------------------------------
// Address: 0x100FBE50
// Name: void NDebugOverlay::VertArrow(class Vector const __near &,class Vector const __near &,float,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::VertArrow(
        const Vector *startPos,
        const Vector *endPos,
        float width,
        int r,
        int g,
        int b,
        int a,
        int noDepthTest,
        float flDuration)
{
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v15; // ecx
  Vector sideDir; // [esp+B8h] [ebp-B4h] BYREF
  float x; // [esp+C4h] [ebp-A8h]
  float v18; // [esp+C8h] [ebp-A4h]
  float v19; // [esp+CCh] [ebp-A0h]
  Vector p7; // [esp+D0h] [ebp-9Ch] BYREF
  float y; // [esp+DCh] [ebp-90h]
  Vector p4; // [esp+E0h] [ebp-8Ch] BYREF
  float z; // [esp+ECh] [ebp-80h]
  Vector p3; // [esp+F0h] [ebp-7Ch] BYREF
  Vector p2; // [esp+FCh] [ebp-70h] BYREF
  Vector p5; // [esp+108h] [ebp-64h] BYREF
  Vector upVec; // [esp+114h] [ebp-58h] BYREF
  Vector lineDir; // [esp+120h] [ebp-4Ch] BYREF
  Vector p1; // [esp+12Ch] [ebp-40h] BYREF
  Vector p6; // [esp+138h] [ebp-34h] BYREF
  float v31; // [esp+144h] [ebp-28h]
  float v32; // [esp+148h] [ebp-24h]
  float v33; // [esp+14Ch] [ebp-20h]
  float v34; // [esp+150h] [ebp-1Ch]
  float v35; // [esp+158h] [ebp-14h]
  float v36; // [esp+15Ch] [ebp-10h]
  float v37; // [esp+160h] [ebp-Ch]
  float v38; // [esp+164h] [ebp-8h]
  float v39; // [esp+168h] [ebp-4h]
  float radius; // [esp+178h] [ebp+Ch]
  float widtha; // [esp+17Ch] [ebp+10h]

  lineDir.x = endPos->x - startPos->x;
  lineDir.y = endPos->y - startPos->y;
  lineDir.z = endPos->z - startPos->z;
  VectorNormalize(vec: &lineDir);
  VectorVectors(forward: &lineDir, right: &sideDir, up: &upVec);
  v10 = upVec.x * (float)(width * 0.5);
  v11 = upVec.y * (float)(width * 0.5);
  v12 = upVec.z * (float)(width * 0.5);
  x = startPos->x;
  p1.x = x - v10;
  y = startPos->y;
  p1.y = y - v11;
  z = startPos->z;
  p1.z = z - v12;
  v13 = lineDir.x * width;
  radius = endPos->x;
  v32 = radius - (float)(lineDir.x * width);
  v19 = endPos->y;
  v33 = v19 - (float)(lineDir.y * width);
  v18 = endPos->z;
  v34 = v18 - (float)(lineDir.z * width);
  p2.x = v32 - v10;
  p2.y = v33 - v11;
  v35 = lineDir.y * width;
  v36 = lineDir.z * width;
  p2.z = v34 - v12;
  widtha = upVec.x * width;
  v37 = radius - v13;
  v38 = v19 - v35;
  v39 = v18 - v36;
  p3.x = (float)(radius - v13) - widtha;
  p3.y = (float)(v19 - v35) - (float)(upVec.y * width);
  p3.z = (float)(v18 - v36) - (float)(upVec.z * width);
  *(_QWORD *)&p4.x = *(_QWORD *)&endPos->x;
  v32 = widtha;
  v33 = upVec.y * width;
  v15 = endPos->z;
  v34 = upVec.z * width;
  v37 = radius - v13;
  v38 = endPos->y - v35;
  v39 = endPos->z - v36;
  p5.x = (float)(radius - v13) + widtha;
  p5.y = v38 + (float)(upVec.y * width);
  p5.z = v39 + (float)(upVec.z * width);
  p6.x = (float)(radius - v13) + v10;
  v31 = upVec.z * width;
  p4.z = v15;
  v35 = v11;
  v36 = v12;
  p6.y = v38 + v11;
  p6.z = v39 + v12;
  p7.y = y + v11;
  p7.x = x + v10;
  p7.z = z + v12;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p1,
      a2: &p2,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p2,
      a2: &p3,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p3,
      a2: &p4,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p4,
      a2: &p5,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p5,
      a2: &p6,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &p6,
      a2: &p7,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( a > 0 )
  {
    NDebugOverlay::Triangle(p1: &p5, p2: &p4, &p3, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(&p1, p2: &p7, p3: &p6, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(p1: &p6, &p2, p3: &p1, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(p1: &p3, p2: &p4, p3: &p5, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(p1: &p6, p2: &p7, p3: &p1, r, g, b, a, noDepthTest, duration: flDuration);
    NDebugOverlay::Triangle(&p1, &p2, p3: &p6, r, g, b, a, noDepthTest, duration: flDuration);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC3D0
// Name: void NDebugOverlay::Axis(class Vector const __near &,class QAngle const __near &,float,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Axis(
        const Vector *position,
        const QAngle *angles,
        float size,
        int noDepthTest,
        float flDuration)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  Vector zvec; // [esp+44h] [ebp-24h] BYREF
  Vector yvec; // [esp+50h] [ebp-18h] BYREF
  Vector xvec; // [esp+5Ch] [ebp-Ch] BYREF

  AngleVectors(angles, forward: &xvec, right: &yvec, up: &zvec);
  x = position->x;
  y = position->y;
  z = position->z;
  xvec.x = position->x + (float)(xvec.x * size);
  xvec.z = z + (float)(xvec.z * size);
  xvec.y = y + (float)(xvec.y * size);
  yvec.y = y - (float)(yvec.y * size);
  yvec.z = z - (float)(yvec.z * size);
  yvec.x = x - (float)(yvec.x * size);
  zvec.x = x + (float)(zvec.x * size);
  zvec.y = y + (float)(zvec.y * size);
  zvec.z = z + (float)(zvec.z * size);
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(const Vector *, Vector *, int, _DWORD, _DWORD, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: position,
      a2: &xvec,
      a3: 255,
      a4: 0,
      a5: 0,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(const Vector *, Vector *, _DWORD, int, _DWORD, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: position,
      a2: &yvec,
      a3: 0,
      a4: 255,
      a5: 0,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(const Vector *, Vector *, _DWORD, _DWORD, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: position,
      a2: &zvec,
      a3: 0,
      a4: 0,
      a5: 255,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x100FC560
// Name: void NDebugOverlay::Sphere(class Vector const __near &,float,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Sphere(
        const Vector *center,
        float radius,
        int r,
        int g,
        int b,
        int noDepthTest,
        float flDuration)
{
  float y; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float z; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  __m128 v17; // xmm0
  __m128d v18; // xmm0
  __m128i v19; // xmm0
  double v20; // xmm0_8
  double v21; // xmm0_8
  const Vector *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  __m128 v25; // xmm0
  float v26; // xmm1_4
  __m128d v27; // xmm0
  __m128i v28; // xmm0
  double v29; // xmm0_8
  double v30; // xmm0_8
  float v31; // xmm1_4
  float v32; // xmm2_4
  __m128 v33; // xmm0
  __m128d v34; // xmm0
  __m128i v35; // xmm0
  double v36; // xmm0_8
  double v37; // xmm0_8
  float v38; // [esp+98h] [ebp-38h] BYREF
  float v39; // [esp+9Ch] [ebp-34h]
  float v40; // [esp+A0h] [ebp-30h]
  float x; // [esp+A4h] [ebp-2Ch] BYREF
  float v42; // [esp+A8h] [ebp-28h]
  float v43; // [esp+ACh] [ebp-24h]
  Vector lastEdge; // [esp+B0h] [ebp-20h] BYREF
  Vector edge; // [esp+BCh] [ebp-14h] BYREF
  float v46; // [esp+C8h] [ebp-8h]
  float angle; // [esp+CCh] [ebp-4h]

  y = center->y;
  v8 = center->z + radius;
  v9 = center->z + COERCE_FLOAT(LODWORD(radius) ^ _mask__NegFloat_);
  x = center->x;
  v42 = y;
  v43 = v8;
  LODWORD(v46) = LODWORD(radius) ^ _mask__NegFloat_;
  v38 = x;
  v39 = y;
  v40 = v9;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &v38,
      a2: &x,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  v10 = center->x;
  v11 = center->y + v46;
  v39 = center->y + radius;
  z = center->z;
  v38 = v10;
  v40 = z;
  x = v10;
  v42 = v11;
  v43 = z;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &x,
      a2: &v38,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  v13 = center->z;
  v14 = center->x + v46;
  v38 = center->x + radius;
  v39 = center->y;
  v40 = v13;
  x = v14;
  v42 = v39;
  v43 = v13;
  if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
    ((void (__stdcall *)(float *, float *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: &x,
      a2: &v38,
      a3: r,
      a4: g,
      a5: b,
      a6: noDepthTest,
      a7: LODWORD(flDuration));
  v15 = center->y;
  v16 = center->z;
  lastEdge.x = center->x + radius;
  v17 = 0;
  lastEdge.y = v15;
  lastEdge.z = v16;
  angle = 0.0;
  do
  {
    v17.m128_f32[0] = v17.m128_f32[0] * 0.0055555557;
    v18 = _mm_cvtps_pd(v17);
    v18.m128d_f64[0] = v18.m128d_f64[0] * 3.141592653589793;
    v19 = (__m128i)_mm_cvtpd_ps(v18);
    v46 = *(float *)v19.m128i_i32;
    *(double *)v19.m128i_i64 = *(float *)v19.m128i_i32;
    __libm_sse2_cos(X: v19);
    *(float *)&v20 = v20;
    edge.x = (float)(*(float *)&v20 * radius) + center->x;
    edge.y = center->y;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v46)));
    *(float *)&v21 = v21;
    edge.z = (float)(*(float *)&v21 * radius) + center->z;
    if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
      ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
        a1: &edge,
        a2: &lastEdge,
        a3: r,
        a4: g,
        a5: b,
        a6: noDepthTest,
        a7: LODWORD(flDuration));
    lastEdge = edge;
    v17 = (__m128)LODWORD(angle);
    v17.m128_f32[0] = angle + 22.5;
    angle = angle + 22.5;
  }
  while ( angle <= 360.0 );
  v22 = center;
  v23 = center->x;
  v24 = center->z;
  lastEdge.y = center->y + radius;
  v25 = 0;
  lastEdge.x = v23;
  lastEdge.z = v24;
  angle = 0.0;
  do
  {
    v25.m128_f32[0] = v25.m128_f32[0] * 0.0055555557;
    v26 = v22->x;
    v27 = _mm_cvtps_pd(v25);
    v27.m128d_f64[0] = v27.m128d_f64[0] * 3.141592653589793;
    v28 = (__m128i)_mm_cvtpd_ps(v27);
    v46 = *(float *)v28.m128i_i32;
    edge.x = v26;
    *(double *)v28.m128i_i64 = *(float *)v28.m128i_i32;
    __libm_sse2_cos(X: v28);
    *(float *)&v29 = v29;
    edge.y = (float)(*(float *)&v29 * radius) + center->y;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v46)));
    *(float *)&v30 = v30;
    edge.z = (float)(*(float *)&v30 * radius) + center->z;
    if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
      ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
        a1: &edge,
        a2: &lastEdge,
        a3: r,
        a4: g,
        a5: b,
        a6: noDepthTest,
        a7: LODWORD(flDuration));
    v22 = center;
    lastEdge = edge;
    v25 = (__m128)LODWORD(angle);
    v25.m128_f32[0] = angle + 22.5;
    angle = angle + 22.5;
  }
  while ( angle <= 360.0 );
  v31 = center->x;
  v32 = center->z;
  lastEdge.y = center->y + radius;
  v33 = 0;
  lastEdge.x = v31;
  lastEdge.z = v32;
  angle = 0.0;
  do
  {
    v33.m128_f32[0] = v33.m128_f32[0] * 0.0055555557;
    v34 = _mm_cvtps_pd(v33);
    v34.m128d_f64[0] = v34.m128d_f64[0] * 3.141592653589793;
    v35 = (__m128i)_mm_cvtpd_ps(v34);
    v46 = *(float *)v35.m128i_i32;
    *(double *)v35.m128i_i64 = *(float *)v35.m128i_i32;
    __libm_sse2_cos(X: v35);
    *(float *)&v36 = v36;
    edge.x = (float)(*(float *)&v36 * radius) + center->x;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v46)));
    *(float *)&v37 = v37;
    edge.y = (float)(*(float *)&v37 * radius) + center->y;
    edge.z = center->z;
    if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
      ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
        a1: &edge,
        a2: &lastEdge,
        a3: r,
        a4: g,
        a5: b,
        a6: noDepthTest,
        a7: LODWORD(flDuration));
    lastEdge = edge;
    v33 = (__m128)LODWORD(angle);
    v33.m128_f32[0] = angle + 22.5;
    angle = angle + 22.5;
  }
  while ( angle <= 360.0 );
}

//------------------------------------------------------------------------------
// Address: 0x100FCA10
// Name: void NDebugOverlay::Circle(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Circle(
        const Vector *position,
        const Vector *xAxis,
        const Vector *yAxis,
        float radius,
        int r,
        int g,
        int b,
        int a,
        int bNoDepthTest,
        float flDuration)
{
  float v10; // xmm0_4
  const Vector *v11; // esi
  float z; // xmm3_4
  const Vector *v13; // edi
  float v14; // xmm4_4
  int v15; // ebx
  long double v16; // st7
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  CBasePlayer *ListenServerHost; // eax
  IVDebugOverlay *v22; // ecx
  Vector vecLastPosition; // [esp+2Ch] [ebp-30h] BYREF
  Vector vecStart; // [esp+38h] [ebp-24h] BYREF
  Vector vecPosition; // [esp+44h] [ebp-18h] BYREF
  float v26; // [esp+50h] [ebp-Ch]
  float *p_position; // [esp+54h] [ebp-8h]
  const Vector **p_xAxis; // [esp+58h] [ebp-4h]

  v10 = radius;
  v11 = xAxis;
  z = xAxis->z;
  v13 = position;
  v14 = position->x + (float)(xAxis->x * radius);
  vecStart.y = position->y + (float)(xAxis->y * radius);
  vecStart.z = position->z + (float)(z * radius);
  vecStart.x = v14;
  vecPosition = vecStart;
  v15 = 1;
  p_position = (float *)&position;
  p_xAxis = &xAxis;
  while ( 1 )
  {
    vecLastPosition = vecPosition;
    v26 = (float)v15 * 0.39269909;
    v16 = sin(v26);
    v17 = (float *)p_xAxis;
    *p_position = cos(v26);
    *v17 = v16;
    v18 = (float)(*(float *)&xAxis * yAxis->y) * v10;
    v19 = v13->y + (float)((float)(v11->y * *(float *)&position) * v10);
    v20 = (float)(v13->z + (float)((float)(v11->z * *(float *)&position) * v10))
        + (float)((float)(*(float *)&xAxis * yAxis->z) * v10);
    vecPosition.x = (float)(v13->x + (float)((float)(v11->x * *(float *)&position) * v10))
                  + (float)((float)(*(float *)&xAxis * yAxis->x) * v10);
    vecPosition.y = v19 + v18;
    vecPosition.z = v20;
    ListenServerHost = UTIL_GetListenServerHost();
    v22 = debugoverlay;
    if ( ListenServerHost != nullptr && debugoverlay != nullptr )
    {
      ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
        a1: &vecLastPosition,
        a2: &vecPosition,
        a3: r,
        a4: g,
        a5: b,
        a6: bNoDepthTest,
        a7: LODWORD(flDuration));
      v22 = debugoverlay;
    }
    if ( a != 0 && v15 > 1 )
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, int, int, int, int, int, _DWORD))v22->AddTriangleOverlay)(
        a1: v22,
        a2: &vecStart,
        a3: &vecLastPosition,
        a4: &vecPosition,
        a5: r,
        a6: g,
        a7: b,
        a8: a,
        a9: bNoDepthTest,
        a10: LODWORD(flDuration));
    if ( (unsigned int)++v15 > 0x10 )
      break;
    v10 = radius;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FCBF0
// Name: void NDebugOverlay::Sphere(class Vector const __near &,class QAngle const __near &,float,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::Sphere(
        const Vector *position,
        const QAngle *angles,
        float radius,
        int r,
        int g,
        int b,
        int a,
        int bNoDepthTest,
        float flDuration)
{
  matrix3x4_t xform; // [esp+28h] [ebp-54h] BYREF
  Vector xAxis; // [esp+58h] [ebp-24h] BYREF
  Vector zAxis; // [esp+64h] [ebp-18h] BYREF
  Vector yAxis; // [esp+70h] [ebp-Ch] BYREF

  AngleMatrix(angles, position, matrix: &xform);
  MatrixGetColumn(in: &xform, column: 0, out: &xAxis);
  MatrixGetColumn(in: &xform, column: 1, out: &yAxis);
  MatrixGetColumn(in: &xform, column: 2, out: &zAxis);
  NDebugOverlay::Circle(position, &xAxis, &yAxis, radius, r, g, b, a, bNoDepthTest, flDuration);
  NDebugOverlay::Circle(position, xAxis: &yAxis, yAxis: &zAxis, radius, r, g, b, a, bNoDepthTest, flDuration);
  NDebugOverlay::Circle(position, &xAxis, yAxis: &zAxis, radius, r, g, b, a, bNoDepthTest, flDuration);
}

//------------------------------------------------------------------------------
// Address: 0x100FCCF0
// Name: void NDebugOverlay::Text(class Vector const __near &,char const __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall NDebugOverlay::Text(
        float a1@<ebp>,
        const Vector *origin,
        const char *text,
        bool bViewCheck,
        float duration)
{
  CBasePlayer *ListenServerHost; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  float z; // xmm4_4
  __int128 v9; // xmm0
  int v10; // [esp+10h] [ebp-94h] BYREF
  _BYTE tr[92]; // [esp+1Ch] [ebp-88h] OVERLAPPED
  Vector v12; // [esp+80h] [ebp-24h] BYREF
  Vector clipForward; // [esp+8Ch] [ebp-18h] BYREF
  Vector clipOrigin; // [esp+98h] [ebp-Ch] BYREF
  float retaddr; // [esp+A4h] [ebp+0h]

  clipOrigin.x = a1;
  clipOrigin.y = retaddr;
  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    CBasePlayer::EyePositionAndVectors(
      this: ListenServerHost,
      pPosition: &clipForward,
      pForward: &v12,
      pRight: nullptr,
      pUp: nullptr);
    if ( g_pGameRules->IsTopDown(this: g_pGameRules)
      || (x = origin->x,
          y = origin->y,
          z = origin->z,
          (float)((float)((float)((float)(clipForward.y - y) * (float)(clipForward.y - y))
                        + (float)((float)(clipForward.x - x) * (float)(clipForward.x - x)))
                + (float)((float)(clipForward.z - z) * (float)(clipForward.z - z))) <= 90000000.0)
      && (float)((float)((float)((float)(y - clipForward.y) * v12.y) + (float)((float)(x - clipForward.x) * v12.x))
               + (float)((float)(z - clipForward.z) * v12.z)) >= 0.0
      && (!bViewCheck
       || (UTIL_TraceLine(
             a1: (const IHandleEntity *)&clipOrigin,
             a2: (int)origin,
             vecAbsStart: &clipForward,
             vecAbsEnd: origin,
             mask: 0x4081u,
             ignore: nullptr,
             collisionGroup: 0,
             ptr: (CGameTrace *)&v10),
           v9 = 0,
           *(float *)&v9 = fsqrt(
                             (float)((float)((float)(*(float *)&tr[4] - origin->y)
                                           * (float)(*(float *)&tr[4] - origin->y))
                                   + (float)((float)(*(float *)&tr[8] - origin->z)
                                           * (float)(*(float *)&tr[8] - origin->z)))
                           + (float)((float)(*(float *)tr - origin->x) * (float)(*(float *)tr - origin->x))),
           *(_OWORD *)&tr[76] = v9,
           *(float *)&v9 <= 10.0)) )
    {
      if ( debugoverlay != nullptr )
        ((void (__cdecl *)(IVDebugOverlay *, const Vector *, _DWORD, const char *))debugoverlay->AddTextOverlay_2)(
          a1: debugoverlay,
          a2: origin,
          a3: LODWORD(duration),
          a4: text);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FCE70
// Name: void NDebugOverlay::DrawTickMarkedLine(class Vector const __near &,class Vector const __near &,float,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::DrawTickMarkedLine(
        const Vector *startPos,
        const Vector *endPos,
        float tickDist,
        int tickTextDist,
        int r,
        int g,
        int b,
        int noDepthTest,
        float duration)
{
  CBasePlayer *v9; // ebx
  double v10; // st7
  Vector *(__thiscall *BodyDirection2D)(CBaseCombatCharacter *, Vector *); // edx
  float *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float z; // eax
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  int v20; // ebx
  int v21; // edi
  int v22; // esi
  float v23; // xmm2_4
  float y; // xmm1_4
  float x; // xmm0_4
  char text[28]; // [esp+30h] [ebp-6Ch] BYREF
  Vector textPos; // [esp+4Ch] [ebp-50h] BYREF
  Vector tickRight; // [esp+58h] [ebp-44h] BYREF
  Vector sideDir; // [esp+64h] [ebp-38h]
  Vector tickLeft; // [esp+70h] [ebp-2Ch] BYREF
  Vector lineDir; // [esp+7Ch] [ebp-20h] BYREF
  Vector tickPos; // [esp+88h] [ebp-14h]
  int numTicks; // [esp+94h] [ebp-8h]
  int tickTextCnt; // [esp+98h] [ebp-4h]
  int savedregs; // [esp+9Ch] [ebp+0h] BYREF

  v9 = UTIL_PlayerByIndex(playerIndex: CBaseEntity::m_nDebugPlayer);
  if ( v9 != nullptr )
  {
    lineDir.x = endPos->x - startPos->x;
    lineDir.y = endPos->y - startPos->y;
    lineDir.z = endPos->z - startPos->z;
    v10 = VectorNormalize(vec: &lineDir) / tickDist;
    BodyDirection2D = v9->BodyDirection2D;
    numTicks = (int)v10;
    v12 = (float *)BodyDirection2D(this: v9, result: &textPos);
    v13 = *v12;
    v14 = v12[1];
    v15 = v12[2];
    z = startPos->z;
    v17 = v14 * 4.0;
    v18 = v13 * 4.0;
    v19 = v15 * 4.0;
    *(_QWORD *)&tickPos.x = *(_QWORD *)&startPos->x;
    sideDir.x = (float)(v19 * lineDir.y) - (float)(v17 * lineDir.z);
    tickPos.z = z;
    tickTextCnt = 0;
    sideDir.y = (float)(v18 * lineDir.z) - (float)(v19 * lineDir.x);
    sideDir.z = (float)(v17 * lineDir.x) - (float)(v18 * lineDir.y);
    if ( UTIL_GetListenServerHost() == nullptr )
      goto LABEL_5;
    if ( debugoverlay != nullptr )
    {
      v20 = noDepthTest;
      ((void (__stdcall *)(const Vector *, const Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
        a1: startPos,
        a2: endPos,
        a3: r,
        a4: g,
        a5: b,
        a6: noDepthTest,
        a7: LODWORD(duration));
    }
    else
    {
LABEL_5:
      v20 = noDepthTest;
    }
    v21 = numTicks + 1;
    v22 = 0;
    if ( numTicks + 1 > 0 )
    {
      v23 = tickPos.z;
      y = tickPos.y;
      x = tickPos.x;
      do
      {
        tickLeft.x = x - sideDir.x;
        tickLeft.y = y - sideDir.y;
        tickLeft.z = v23 - sideDir.z;
        tickRight.x = x + sideDir.x;
        tickRight.y = y + sideDir.y;
        tickRight.z = v23 + sideDir.z;
        if ( tickTextCnt == tickTextDist )
        {
          V_snprintf(pDest: text, maxLen: 25, pFormat: "%i", v22);
          textPos.x = tickLeft.x;
          textPos.y = tickLeft.y;
          textPos.z = tickLeft.z + 8.0;
          if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
            ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
              a1: &tickLeft,
              a2: &tickRight,
              a3: 255,
              a4: 255,
              a5: 255,
              a6: v20,
              a7: LODWORD(duration));
          NDebugOverlay::Text(a1: COERCE_FLOAT(&savedregs), origin: &textPos, text, bViewCheck: true, duration: 0.0);
          tickTextCnt = 0;
        }
        else if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
        {
          ((void (__stdcall *)(Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
            a1: &tickLeft,
            a2: &tickRight,
            a3: r,
            a4: g,
            a5: b,
            a6: v20,
            a7: LODWORD(duration));
        }
        ++tickTextCnt;
        ++v22;
        x = (float)(lineDir.x * tickDist) + tickPos.x;
        y = (float)(lineDir.y * tickDist) + tickPos.y;
        v23 = (float)(lineDir.z * tickDist) + tickPos.z;
        tickPos.x = x;
        tickPos.y = y;
        tickPos.z = v23;
      }
      while ( v22 < v21 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD140
// Name: void NDebugOverlay::DrawGroundCrossHairOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NDebugOverlay::DrawGroundCrossHairOverlay()
{
  CBasePlayer *v0; // eax
  CBasePlayer *v1; // esi
  CGameTrace tr; // [esp+28h] [ebp-84h] BYREF
  Vector vForward; // [esp+7Ch] [ebp-30h] BYREF
  Vector vSource; // [esp+88h] [ebp-24h] BYREF
  Vector endPos; // [esp+94h] [ebp-18h] BYREF
  Vector startPos; // [esp+A0h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+ACh] [ebp+0h] BYREF

  v0 = UTIL_PlayerByIndex(playerIndex: CBaseEntity::m_nDebugPlayer);
  v1 = v0;
  if ( v0 != nullptr )
  {
    v0->EyePosition(this: v0, result: &vSource);
    CBasePlayer::EyeVectors(this: v1, pForward: &vForward, pRight: nullptr, pUp: nullptr);
    startPos.y = vSource.y + (float)(vForward.y * 2048.0);
    startPos.x = vSource.x + (float)(vForward.x * 2048.0);
    startPos.z = vSource.z + (float)(vForward.z * 2048.0);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)v1,
      vecAbsStart: &vSource,
      vecAbsEnd: &startPos,
      mask: 0x200400Bu,
      ignore: v1,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction != 1.0
      && (float)((float)((float)(tr.plane.normal.x + tr.plane.normal.y) * 0.0) + tr.plane.normal.z) > 0.5 )
    {
      startPos.x = tr.endpos.x - 6.0;
      tr.endpos.z = tr.endpos.z + 1.0;
      startPos.y = tr.endpos.y;
      startPos.z = tr.endpos.z;
      endPos.x = tr.endpos.x + 6.0;
      endPos.y = tr.endpos.y;
      endPos.z = tr.endpos.z;
      if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
        ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, _DWORD, _DWORD))debugoverlay->AddLineOverlay)(
          a1: &startPos,
          a2: &endPos,
          a3: 255,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: 0);
      startPos.x = tr.endpos.x;
      startPos.y = tr.endpos.y - 6.0;
      startPos.z = tr.endpos.z;
      endPos.x = tr.endpos.x;
      endPos.y = tr.endpos.y + 6.0;
      endPos.z = tr.endpos.z;
      if ( UTIL_GetListenServerHost() != nullptr && debugoverlay != nullptr )
        ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, _DWORD, _DWORD))debugoverlay->AddLineOverlay)(
          a1: &startPos,
          a2: &endPos,
          a3: 255,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FF920
// Name: _dynamic_initializer_for__debug_overlay_fullposition__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_overlay_fullposition__()
{
  ConVar::ConVar(this: &debug_overlay_fullposition, pName: "debug_overlay_fullposition", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__debug_overlay_fullposition__);
}

//------------------------------------------------------------------------------
// Address: 0x104017E0
// Name: _dynamic_initializer_for__debug_visibility_monitor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_visibility_monitor__()
{
  ConVar::ConVar(this: &debug_visibility_monitor, pName: "debug_visibility_monitor", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__debug_visibility_monitor__);
}

//------------------------------------------------------------------------------
// Address: 0x10405CE0
// Name: _dynamic_initializer_for__debug_materialmodifycontrol__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_materialmodifycontrol__()
{
  ConVar::ConVar(this: &debug_materialmodifycontrol, pName: "debug_materialmodifycontrol", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__debug_materialmodifycontrol__);
}

//------------------------------------------------------------------------------
// Address: 0x10407530
// Name: _dynamic_initializer_for__debug_touchlinks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_touchlinks__()
{
  ConVar::ConVar(
    this: &debug_touchlinks,
    pName: "debug_touchlinks",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Spew touch link activity");
  return atexit(func: dynamic_atexit_destructor_for__debug_touchlinks__);
}

//------------------------------------------------------------------------------
// Address: 0x104078A0
// Name: _dynamic_initializer_for__debug_physimpact__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_physimpact__()
{
  ConVar::ConVar(this: &debug_physimpact, pName: "debug_physimpact", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__debug_physimpact__);
}

//------------------------------------------------------------------------------
// Address: 0x10419A90
// Name: _dynamic_atexit_destructor_for__debug_overlay_fullposition__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_overlay_fullposition__()
{
  ConVar::~ConVar(this: &debug_overlay_fullposition);
}

//------------------------------------------------------------------------------
// Address: 0x1041A700
// Name: _dynamic_atexit_destructor_for__debug_visibility_monitor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_visibility_monitor__()
{
  ConVar::~ConVar(this: &debug_visibility_monitor);
}

//------------------------------------------------------------------------------
// Address: 0x1041C3B0
// Name: _dynamic_atexit_destructor_for__debug_materialmodifycontrol__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_materialmodifycontrol__()
{
  ConVar::~ConVar(this: &debug_materialmodifycontrol);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD30
// Name: _dynamic_atexit_destructor_for__debug_touchlinks__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_touchlinks__()
{
  ConVar::~ConVar(this: &debug_touchlinks);
}

//------------------------------------------------------------------------------
// Address: 0x1041CF00
// Name: _dynamic_atexit_destructor_for__debug_physimpact__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_physimpact__()
{
  ConVar::~ConVar(this: &debug_physimpact);
}

//------------------------------------------------------------------------------
// Address: 0x10401810
// Name: _dynamic_initializer_for__vismon_poll_frequency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vismon_poll_frequency__()
{
  ConVar::ConVar(this: &vismon_poll_frequency, pName: "vismon_poll_frequency", pDefaultValue: ".5", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__vismon_poll_frequency__);
}

//------------------------------------------------------------------------------
// Address: 0x10401840
// Name: _dynamic_initializer_for__vismon_trace_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vismon_trace_limit__()
{
  ConVar::ConVar(this: &vismon_trace_limit, pName: "vismon_trace_limit", pDefaultValue: "12", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__vismon_trace_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x10407560
// Name: _dynamic_initializer_for__CPortalTouchScope::m_CallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CPortalTouchScope::m_CallQueue__()
{
  CTSQueue<CFunctor *,0,1>::CTSQueue<CFunctor *,0,1>(this: &CPortalTouchScope::m_CallQueue.m_queue);
  CPortalTouchScope::m_CallQueue.m_bNoQueue = false;
  return atexit(func: dynamic_atexit_destructor_for__CPortalTouchScope::m_CallQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x10407580
// Name: _dynamic_initializer_for__g_DataObjectAccessSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataObjectAccessSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_DataObjectAccessSystem, name: nullptr);
  g_DataObjectAccessSystem.__vftable = (CDataObjectAccessSystem_vtbl *)&CDataObjectAccessSystem::`vftable';
  _V_memset(dest: g_DataObjectAccessSystem.m_Accessors, fill: 0, count: 128);
  return atexit(func: dynamic_atexit_destructor_for__g_DataObjectAccessSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x104075C0
// Name: _dynamic_initializer_for__sv_thinktimecheck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_thinktimecheck__()
{
  ConVar::ConVar(
    this: &sv_thinktimecheck,
    pName: "sv_thinktimecheck",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Check for thinktimes all on same timestamp.");
  return atexit(func: dynamic_atexit_destructor_for__sv_thinktimecheck__);
}

//------------------------------------------------------------------------------
// Address: 0x104075F0
// Name: _dynamic_initializer_for__g_ThinkChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ThinkChecker__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ThinkChecker__);
}

//------------------------------------------------------------------------------
// Address: 0x10419AA0
// Name: _dynamic_atexit_destructor_for__ai_debug_los__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_los__()
{
  ConVar::~ConVar(this: &ai_debug_los);
}

//------------------------------------------------------------------------------
// Address: 0x10419AB0
// Name: _dynamic_atexit_destructor_for__ent_messages_draw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_messages_draw__()
{
  ConVar::~ConVar(this: &ent_messages_draw);
}

//------------------------------------------------------------------------------
// Address: 0x10419AC0
// Name: _dynamic_atexit_destructor_for__g_ModelSoundsSymbolHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ModelSoundsSymbolHelper__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ModelSoundsSymbolHelper);
}

//------------------------------------------------------------------------------
// Address: 0x10419AD0
// Name: _dynamic_atexit_destructor_for__ent_name__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_name__()
{
  ConCommand::~ConCommand(this: &ent_name);
}

//------------------------------------------------------------------------------
// Address: 0x10419AE0
// Name: _dynamic_atexit_destructor_for__ent_text__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_text__()
{
  ConCommand::~ConCommand(this: &ent_text);
}

//------------------------------------------------------------------------------
// Address: 0x10419AF0
// Name: _dynamic_atexit_destructor_for__ent_script_dump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_script_dump__()
{
  ConCommand::~ConCommand(this: &ent_script_dump);
}

//------------------------------------------------------------------------------
// Address: 0x10419B00
// Name: _dynamic_atexit_destructor_for__ent_bbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_bbox__()
{
  ConCommand::~ConCommand(this: &ent_bbox);
}

//------------------------------------------------------------------------------
// Address: 0x10419B10
// Name: _dynamic_atexit_destructor_for__ent_absbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_absbox__()
{
  ConCommand::~ConCommand(this: &ent_absbox);
}

//------------------------------------------------------------------------------
// Address: 0x10419B20
// Name: _dynamic_atexit_destructor_for__ent_rbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_rbox__()
{
  ConCommand::~ConCommand(this: &ent_rbox);
}

//------------------------------------------------------------------------------
// Address: 0x10419B30
// Name: _dynamic_atexit_destructor_for__ent_attachments__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_attachments__()
{
  ConCommand::~ConCommand(this: &ent_attachments);
}

//------------------------------------------------------------------------------
// Address: 0x10419B40
// Name: _dynamic_atexit_destructor_for__ent_viewoffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_viewoffset__()
{
  ConCommand::~ConCommand(this: &ent_viewoffset);
}

//------------------------------------------------------------------------------
// Address: 0x10419B50
// Name: _dynamic_atexit_destructor_for__ent_remove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_remove__()
{
  ConCommand::~ConCommand(this: &ent_remove);
}

//------------------------------------------------------------------------------
// Address: 0x10419B60
// Name: _dynamic_atexit_destructor_for__ent_remove_all__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_remove_all__()
{
  ConCommand::~ConCommand(this: &ent_remove_all);
}

//------------------------------------------------------------------------------
// Address: 0x10419B70
// Name: _dynamic_atexit_destructor_for__ent_setname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_setname__()
{
  ConCommand::~ConCommand(this: &ent_setname);
}

//------------------------------------------------------------------------------
// Address: 0x1041A710
// Name: _dynamic_atexit_destructor_for__vismon_poll_frequency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vismon_poll_frequency__()
{
  ConVar::~ConVar(this: &vismon_poll_frequency);
}

//------------------------------------------------------------------------------
// Address: 0x1041A720
// Name: _dynamic_atexit_destructor_for__vismon_trace_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vismon_trace_limit__()
{
  ConVar::~ConVar(this: &vismon_trace_limit);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD40
// Name: _dynamic_atexit_destructor_for__sv_thinktimecheck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_thinktimecheck__()
{
  ConVar::~ConVar(this: &sv_thinktimecheck);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD50
// Name: _dynamic_atexit_destructor_for__g_DataObjectAccessSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataObjectAccessSystem__()
{
  IGameSystem::~IGameSystem(this: &g_DataObjectAccessSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD60
// Name: _dynamic_atexit_destructor_for__g_WatcherList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WatcherList__()
{
  CUtlMultiList<watcher_t,unsigned short>::~CUtlMultiList<watcher_t,unsigned short>(this: (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *)&g_WatcherList);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD70
// Name: _dynamic_atexit_destructor_for__CPortalTouchScope::m_CallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CPortalTouchScope::m_CallQueue__()
{
  CTSQueue<CFunctor *,0,1>::Purge(this: &CPortalTouchScope::m_CallQueue.m_queue);
  free(pMem: CPortalTouchScope::m_CallQueue.m_queue.m_Head.value.pNode);
  CTSListBase::Detach(this: &CPortalTouchScope::m_CallQueue.m_queue.m_FreeNodes);
}

//------------------------------------------------------------------------------
// Address: 0x1041CDA0
// Name: _dynamic_atexit_destructor_for__g_ThinkChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThinkChecker__()
{
  CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>::~CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>(this: &g_ThinkChecker.m_Thinkers);
}

//------------------------------------------------------------------------------
// Address: 0x1041CDB0
// Name: _dynamic_atexit_destructor_for__g_SolverList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SolverList__()
{
  CBaseEntityClassList::~CBaseEntityClassList(this: &g_SolverList);
}

//------------------------------------------------------------------------------
// Address: 0x1041CDC0
// Name: _DataMapInit_CPhysicsNPCSolver__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsNPCSolver__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_309);
}

//------------------------------------------------------------------------------
// Address: 0x1041CDD0
// Name: _DataMapInit_CPhysicsEntitySolver__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsEntitySolver__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_310);
}

} // namespace server
