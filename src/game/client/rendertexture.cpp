// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/rendertexture.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10163C20
// Name: void ReleaseRenderTargets(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseRenderTargets(char nChangeFlags)
{
  CTextureReference *v1; // esi

  if ( (nChangeFlags & 1) == 0 )
  {
    CTextureReference::Shutdown(this: &s_pPowerOfTwoFrameBufferTexture, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &s_pCameraTexture, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &s_pWaterReflectionTexture, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &s_pWaterRefractionTexture, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &s_pQuarterSizedFB0, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &s_pQuarterSizedFB1, bDeleteIfUnReferenced: false);
    CTextureReference::Shutdown(this: &s_pFullFrameDepthTexture, bDeleteIfUnReferenced: false);
    v1 = s_pFullFrameFrameBufferTexture;
    do
      CTextureReference::Shutdown(this: v1++, bDeleteIfUnReferenced: false);
    while ( (int)v1 < (int)&s_pSmallBufferHDR0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163CA0
// Name: class ITexture __near * GetFullscreenTexture(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetFullscreenTexture()
{
  ITexture *result; // eax
  ITexture *v1; // eax
  void (__thiscall *AddReleaseFunc)(IMaterialSystem *, void (__cdecl *)(int)); // edx

  result = s_pFullscreenTexture.m_pTexture;
  if ( s_pFullscreenTexture.m_pTexture == nullptr )
  {
    v1 = materials->FindTexture(this: materials, a2: "_rt_Fullscreen", a3: "RenderTargets", a4: 1, a5: 0);
    CTextureReference::Init(this: &s_pFullscreenTexture, pTexture: v1);
    if ( byte_1064F684 == 0 )
    {
      AddReleaseFunc = materials->AddReleaseFunc;
      byte_1064F684 = 1;
      AddReleaseFunc(this: materials, a2: ReleaseRenderTargets);
    }
    return s_pFullscreenTexture.m_pTexture;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163D00
// Name: class ITexture __near * GetCameraTexture(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetCameraTexture()
{
  ITexture *result; // eax
  ITexture *v1; // eax
  void (__thiscall *AddReleaseFunc)(IMaterialSystem *, void (__cdecl *)(int)); // edx

  result = s_pCameraTexture.m_pTexture;
  if ( s_pCameraTexture.m_pTexture == nullptr )
  {
    v1 = materials->FindTexture(this: materials, a2: "_rt_Camera", a3: "RenderTargets", a4: 1, a5: 0);
    CTextureReference::Init(this: &s_pCameraTexture, pTexture: v1);
    if ( byte_1064F684 == 0 )
    {
      AddReleaseFunc = materials->AddReleaseFunc;
      byte_1064F684 = 1;
      AddReleaseFunc(this: materials, a2: ReleaseRenderTargets);
    }
    return s_pCameraTexture.m_pTexture;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163D60
// Name: class ITexture __near * GetFullFrameDepthTexture(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetFullFrameDepthTexture()
{
  ITexture *result; // eax
  ITexture *v1; // eax
  void (__thiscall *AddReleaseFunc)(IMaterialSystem *, void (__cdecl *)(int)); // edx

  result = s_pFullFrameDepthTexture.m_pTexture;
  if ( s_pFullFrameDepthTexture.m_pTexture == nullptr )
  {
    v1 = materials->FindTexture(this: materials, a2: "_rt_FullFrameDepth", a3: "RenderTargets", a4: 1, a5: 0);
    CTextureReference::Init(this: &s_pFullFrameDepthTexture, pTexture: v1);
    if ( byte_1064F684 == 0 )
    {
      AddReleaseFunc = materials->AddReleaseFunc;
      byte_1064F684 = 1;
      AddReleaseFunc(this: materials, a2: ReleaseRenderTargets);
    }
    return s_pFullFrameDepthTexture.m_pTexture;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163DC0
// Name: class ITexture __near * GetFullFrameFrameBufferTexture(int)
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetFullFrameFrameBufferTexture(int textureIndex)
{
  CTextureReference *v1; // esi
  ITexture *v2; // eax
  void (__thiscall *AddReleaseFunc)(IMaterialSystem *, void (__cdecl *)(int)); // edx
  char name[256]; // [esp+4h] [ebp-100h] BYREF

  v1 = &s_pFullFrameFrameBufferTexture[textureIndex];
  if ( v1->m_pTexture == nullptr )
  {
    if ( textureIndex != 0 )
      V_snprintf(pDest: name, maxLen: 256, pFormat: "_rt_FullFrameFB%d", textureIndex);
    else
      _V_strcpy(dest: name, src: "_rt_FullFrameFB");
    v2 = materials->FindTexture(this: materials, a2: name, a3: "RenderTargets", a4: 1, a5: 0);
    CTextureReference::Init(this: v1, pTexture: v2);
    if ( byte_1064F684 == 0 )
    {
      AddReleaseFunc = materials->AddReleaseFunc;
      byte_1064F684 = 1;
      AddReleaseFunc(this: materials, a2: ReleaseRenderTargets);
    }
  }
  return v1->m_pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10163E70
// Name: class ITexture __near * GetWaterReflectionTexture(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetWaterReflectionTexture()
{
  ITexture *result; // eax
  ITexture *v1; // eax
  void (__thiscall *AddReleaseFunc)(IMaterialSystem *, void (__cdecl *)(int)); // edx

  result = s_pWaterReflectionTexture.m_pTexture;
  if ( s_pWaterReflectionTexture.m_pTexture == nullptr )
  {
    v1 = materials->FindTexture(this: materials, a2: "_rt_WaterReflection", a3: "RenderTargets", a4: 1, a5: 0);
    CTextureReference::Init(this: &s_pWaterReflectionTexture, pTexture: v1);
    if ( byte_1064F684 == 0 )
    {
      AddReleaseFunc = materials->AddReleaseFunc;
      byte_1064F684 = 1;
      AddReleaseFunc(this: materials, a2: ReleaseRenderTargets);
    }
    return s_pWaterReflectionTexture.m_pTexture;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163ED0
// Name: class ITexture __near * GetWaterRefractionTexture(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetWaterRefractionTexture()
{
  ITexture *result; // eax
  ITexture *v1; // eax
  void (__thiscall *AddReleaseFunc)(IMaterialSystem *, void (__cdecl *)(int)); // edx

  result = s_pWaterRefractionTexture.m_pTexture;
  if ( s_pWaterRefractionTexture.m_pTexture == nullptr )
  {
    v1 = materials->FindTexture(this: materials, a2: "_rt_WaterRefraction", a3: "RenderTargets", a4: 1, a5: 0);
    CTextureReference::Init(this: &s_pWaterRefractionTexture, pTexture: v1);
    if ( byte_1064F684 == 0 )
    {
      AddReleaseFunc = materials->AddReleaseFunc;
      byte_1064F684 = 1;
      AddReleaseFunc(this: materials, a2: ReleaseRenderTargets);
    }
    return s_pWaterRefractionTexture.m_pTexture;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10163F30
// Name: class ITexture __near * GetPowerOfTwoFrameBufferTexture(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__cdecl GetPowerOfTwoFrameBufferTexture()
{
  ITexture *result; // eax
  ITexture *v1; // eax
  void (__thiscall *AddReleaseFunc)(IMaterialSystem *, void (__cdecl *)(int)); // edx

  result = s_pPowerOfTwoFrameBufferTexture.m_pTexture;
  if ( s_pPowerOfTwoFrameBufferTexture.m_pTexture == nullptr )
  {
    v1 = materials->FindTexture(this: materials, a2: "_rt_PowerOfTwoFB", a3: "RenderTargets", a4: 1, a5: 0);
    CTextureReference::Init(this: &s_pPowerOfTwoFrameBufferTexture, pTexture: v1);
    if ( byte_1064F684 == 0 )
    {
      AddReleaseFunc = materials->AddReleaseFunc;
      byte_1064F684 = 1;
      AddReleaseFunc(this: materials, a2: ReleaseRenderTargets);
    }
    return s_pPowerOfTwoFrameBufferTexture.m_pTexture;
  }
  return result;
}
