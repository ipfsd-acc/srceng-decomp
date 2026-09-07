// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxrenderconfig.cpp
// Functions: 2
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxrenderconfig.h"

//------------------------------------------------------------------------------
// Address: 0x1007A780
// Name: public: GFxRenderConfig::GFxRenderConfig(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxRenderConfig *__thiscall GFxRenderConfig::GFxRenderConfig(
        GFxRenderConfig *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4)
{
  this->__vftable = (GFxRenderConfig_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->SType = State_RenderConfig;
  this->__vftable = (GFxRenderConfig_vtbl *)&GFxRenderConfig::`vftable';
  this->pRenderer.pObject = nullptr;
  this->MaxCurvePixelError = 1.0;
  this->RenderFlags = a2;
  this->StrokerAAWidth = 1.2;
  this->RendererCapBits = a3;
  this->RendererVtxFmts = a4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A7D0
// Name: public: GFxRenderConfig::GFxRenderConfig(class GRenderer __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxRenderConfig::GFxRenderConfig(void *this, IShaderDevice *a2, unsigned int rendererFlags)
{
  IShaderAPI *v4; // ecx
  int v5; // ecx
  _DWORD v7[4]; // [esp+Ch] [ebp-14h] BYREF

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 1;
  *(_DWORD *)this = &GFxRenderConfig::`vftable';
  *((_DWORD *)this + 3) = 0;
  *((float *)this + 4) = 1.0;
  *((float *)this + 6) = 1.2;
  *((_DWORD *)this + 5) = rendererFlags;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2);
  v4 = *((IShaderAPI **)this + 3);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  *((_DWORD *)this + 3) = a2;
  if ( a2 != nullptr )
  {
    ((void (__thiscall *)(IShaderDevice *, _DWORD *))a2->ReacquireResources)(a1: a2, a2: v7);
    v5 = v7[1];
    *((_DWORD *)this + 7) = v7[0];
    *((_DWORD *)this + 8) = v5;
  }
  else
  {
    *((_DWORD *)this + 7) = 0;
    *((_DWORD *)this + 8) = 0;
  }
  return this;
}
