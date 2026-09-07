// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/renderer/scaleformrendertarget.cpp
// Functions: 6
// ============================================================

#include "materialsystem\scaleformui\renderer\scaleformrendertarget.h"

//------------------------------------------------------------------------------
// Address: 0x10004580
// Name: public: ScaleformRenderTarget::ScaleformRenderTarget(class ScaleformRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
ScaleformRenderTarget *__thiscall ScaleformRenderTarget::ScaleformRenderTarget(
        ScaleformRenderTarget *this,
        ScaleformRenderer *pRenderer)
{
  GRenderTargetImplNode::GRenderTargetImplNode(this, plistRoot: &pRenderer->m_renderTargets);
  this->m_pRenderer = pRenderer;
  this->__vftable = (ScaleformRenderTarget_vtbl *)&ScaleformRenderTarget::`vftable';
  this->m_hRenderTargetTexture = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100045B0
// Name: public: void ScaleformRenderTarget::ReleaseResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderTarget::ReleaseResources(ScaleformRenderTarget *this)
{
  int m_hRenderTargetTexture; // eax

  m_hRenderTargetTexture = this->m_hRenderTargetTexture;
  if ( m_hRenderTargetTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hRenderTargetTexture);
    this->m_hRenderTargetTexture = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100045E0
// Name: public: void ScaleformRenderTarget::InitRenderTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderTarget::InitRenderTarget(ScaleformRenderTarget *this)
{
  int m_hRenderTargetTexture; // eax
  IShaderAPI_vtbl *v3; // edi
  int v4; // eax
  int width; // [esp+8h] [ebp-8h] BYREF
  int height; // [esp+Ch] [ebp-4h] BYREF

  m_hRenderTargetTexture = this->m_hRenderTargetTexture;
  if ( m_hRenderTargetTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hRenderTargetTexture);
    this->m_hRenderTargetTexture = 0;
  }
  materials->GetBackBufferDimensions(this: materials, a2: &width, a3: &height);
  v3 = g_pShaderAPI->__vftable;
  v4 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, _DWORD, int, const char *, const char *))materials->GetBackBufferFormat)(
         a1: materials,
         a2: 0,
         a3: 0,
         a4: 2,
         a5: "ScaleformRT",
         a6: "Scaleform textures");
  this->m_hRenderTargetTexture = ((int (__thiscall *)(IShaderAPI *, int, int, _DWORD, int))v3->CreateTexture)(
                                   a1: g_pShaderAPI,
                                   a2: width,
                                   a3: height,
                                   a4: 0,
                                   a5: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10004670
// Name: public: virtual bool ScaleformRenderTarget::InitRenderTarget(class GTexture __near *,class GTexture __near *,class GTexture __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformRenderTarget::InitRenderTarget(
        ScaleformRenderTarget *this,
        GTexture *ptarget,
        GTexture *pdepth,
        GTexture *pstencil)
{
  int m_hRenderTargetTexture; // eax

  m_hRenderTargetTexture = this->m_hRenderTargetTexture;
  if ( m_hRenderTargetTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hRenderTargetTexture);
    this->m_hRenderTargetTexture = 0;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100046A0
// Name: public: virtual ScaleformRenderTarget::~ScaleformRenderTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderTarget::~ScaleformRenderTarget(ScaleformRenderTarget *this)
{
  int m_hRenderTargetTexture; // eax
  ScaleformRenderer *m_pRenderer; // eax
  _RTL_CRITICAL_SECTION *p_cs; // edi

  this->__vftable = (ScaleformRenderTarget_vtbl *)&ScaleformRenderTarget::`vftable';
  m_hRenderTargetTexture = this->m_hRenderTargetTexture;
  if ( m_hRenderTargetTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hRenderTargetTexture);
    this->m_hRenderTargetTexture = 0;
  }
  m_pRenderer = this->m_pRenderer;
  if ( m_pRenderer != nullptr )
  {
    p_cs = &m_pRenderer->m_texturesLock.cs;
    EnterCriticalSection(lpCriticalSection: &m_pRenderer->m_texturesLock.cs);
    if ( this->pNext != nullptr )
    {
      this->pPrev->pNext = this->pNext;
      this->pNext->GRenderTargetImplNode::GRendererNode::$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = this->pPrev;
      this->pPrev = nullptr;
      this->pNext = nullptr;
    }
    LeaveCriticalSection(lpCriticalSection: p_cs);
  }
  GRenderTargetImplNode::~GRenderTargetImplNode(this);
}

//------------------------------------------------------------------------------
// Address: 0x10004770
// Name: public: void ScaleformRenderTarget::RemoveFromRenderer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformRenderTarget::RemoveFromRenderer(ScaleformRenderTarget *this)
{
  GAtomicInt<long> *p_RefCount; // ebx
  volatile int Value; // edi

  p_RefCount = &this->RefCount;
  Value = this->RefCount.Value;
  if ( Value != 0 )
  {
    while ( InterlockedCompareExchange(Destination: &p_RefCount->Value, Exchange: Value + 1, Comperand: Value) != Value )
    {
      Value = p_RefCount->Value;
      if ( p_RefCount->Value == 0 )
        goto LABEL_4;
    }
    if ( this->m_hRenderTargetTexture != 0 )
    {
      g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_hRenderTargetTexture);
      this->m_hRenderTargetTexture = 0;
    }
    if ( this->pNext != nullptr )
    {
      this->pPrev->pNext = this->pNext;
      this->pNext->GRenderTargetImplNode::GRendererNode::$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = this->pPrev;
      this->pPrev = nullptr;
      this->pNext = nullptr;
    }
    if ( InterlockedExchangeAdd(Addend: &p_RefCount->Value, Value: -1) == 1 )
      ((void (__thiscall *)(ScaleformRenderTarget *, int))this->dtr_GRenderTarget)(a1: this, a2: 1);
  }
  else
  {
LABEL_4:
    if ( this->pNext != nullptr )
    {
      this->pPrev->pNext = this->pNext;
      this->pNext->GRenderTargetImplNode::GRendererNode::$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = this->pPrev;
      this->pPrev = nullptr;
      this->pNext = nullptr;
    }
  }
}
