// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/screenspaceeffects.cpp
// Functions: 16
// ============================================================

#include "game\client\screenspaceeffects.h"

//------------------------------------------------------------------------------
// Address: 0x101698E0
// Name: public: virtual void CScreenSpaceEffectManager::InitScreenSpaceEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::InitScreenSpaceEffects(CScreenSpaceEffectManager *this)
{
  int v2; // eax
  IScreenSpaceEffect *v3; // eax
  CScreenSpaceEffectRegistration *i; // edi
  IScreenSpaceEffect *m_pEffect; // esi
  bool bIsEnabled; // [esp+8h] [ebp-4h]

  v2 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-filmgrain") != 0 )
  {
    v3 = this->GetScreenSpaceEffect(this, a2: "filmgrain");
    v3->Enable(this: v3, a2: true);
  }
  for ( i = CScreenSpaceEffectRegistration::s_pHead; i != nullptr; i = i->m_pNext )
  {
    m_pEffect = i->m_pEffect;
    if ( m_pEffect != nullptr )
    {
      bIsEnabled = m_pEffect->IsEnabled(this: i->m_pEffect);
      m_pEffect->Init(this: m_pEffect);
      m_pEffect->Enable(this: m_pEffect, a2: bIsEnabled);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169960
// Name: public: virtual void CScreenSpaceEffectManager::ShutdownScreenSpaceEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::ShutdownScreenSpaceEffects(CScreenSpaceEffectManager *this)
{
  CScreenSpaceEffectRegistration *i; // esi
  IScreenSpaceEffect *m_pEffect; // ecx

  for ( i = CScreenSpaceEffectRegistration::s_pHead; i != nullptr; i = i->m_pNext )
  {
    m_pEffect = i->m_pEffect;
    if ( m_pEffect != nullptr )
      m_pEffect->Shutdown(this: m_pEffect);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169990
// Name: public: virtual class IScreenSpaceEffect __near * CScreenSpaceEffectManager::GetScreenSpaceEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IScreenSpaceEffect *__thiscall CScreenSpaceEffectManager::GetScreenSpaceEffect(
        CScreenSpaceEffectManager *this,
        const char *pEffectName)
{
  CScreenSpaceEffectRegistration *v2; // esi

  v2 = CScreenSpaceEffectRegistration::s_pHead;
  if ( CScreenSpaceEffectRegistration::s_pHead != nullptr )
  {
    while ( _V_stricmp(s1: v2->m_pEffectName, s2: pEffectName) != 0 )
    {
      v2 = v2->m_pNext;
      if ( v2 == nullptr )
        goto LABEL_4;
    }
    return v2->m_pEffect;
  }
  else
  {
LABEL_4:
    _Warning(a1: "Could not find screen space effect %s\n", pEffectName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101699E0
// Name: public: virtual void CScreenSpaceEffectManager::SetScreenSpaceEffectParams(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::SetScreenSpaceEffectParams(
        CScreenSpaceEffectManager *this,
        const char *pEffectName,
        KeyValues *params)
{
  IScreenSpaceEffect *v4; // eax

  v4 = this->GetScreenSpaceEffect(this, a2: pEffectName);
  if ( v4 != nullptr )
    this->SetScreenSpaceEffectParams(this, a2: v4, a3: params);
}

//------------------------------------------------------------------------------
// Address: 0x10169A10
// Name: public: virtual void CScreenSpaceEffectManager::SetScreenSpaceEffectParams(class IScreenSpaceEffect __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::SetScreenSpaceEffectParams(
        CScreenSpaceEffectManager *this,
        IScreenSpaceEffect *pEffect,
        KeyValues *params)
{
  if ( pEffect != nullptr )
    pEffect->SetParameters(this: pEffect, a2: params);
}

//------------------------------------------------------------------------------
// Address: 0x10169A30
// Name: public: virtual void CScreenSpaceEffectManager::EnableScreenSpaceEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::EnableScreenSpaceEffect(
        CScreenSpaceEffectManager *this,
        const char *pEffectName)
{
  IScreenSpaceEffect *v3; // eax

  v3 = this->GetScreenSpaceEffect(this, a2: pEffectName);
  if ( v3 != nullptr )
    this->EnableScreenSpaceEffect(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10169A60
// Name: public: virtual void CScreenSpaceEffectManager::EnableScreenSpaceEffect(class IScreenSpaceEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::EnableScreenSpaceEffect(
        CScreenSpaceEffectManager *this,
        IScreenSpaceEffect *pEffect)
{
  if ( pEffect != nullptr )
    pEffect->Enable(this: pEffect, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10169A80
// Name: public: virtual void CScreenSpaceEffectManager::DisableScreenSpaceEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::DisableScreenSpaceEffect(
        CScreenSpaceEffectManager *this,
        const char *pEffectName)
{
  IScreenSpaceEffect *v3; // eax

  v3 = this->GetScreenSpaceEffect(this, a2: pEffectName);
  if ( v3 != nullptr )
    this->DisableScreenSpaceEffect(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10169AB0
// Name: public: virtual void CScreenSpaceEffectManager::DisableScreenSpaceEffect(class IScreenSpaceEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::DisableScreenSpaceEffect(
        CScreenSpaceEffectManager *this,
        IScreenSpaceEffect *pEffect)
{
  if ( pEffect != nullptr )
    pEffect->Enable(this: pEffect, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10169AD0
// Name: public: virtual void CScreenSpaceEffectManager::DisableAllScreenSpaceEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::DisableAllScreenSpaceEffects(CScreenSpaceEffectManager *this)
{
  CScreenSpaceEffectRegistration *i; // esi
  IScreenSpaceEffect *m_pEffect; // ecx

  for ( i = CScreenSpaceEffectRegistration::s_pHead; i != nullptr; i = i->m_pNext )
  {
    m_pEffect = i->m_pEffect;
    if ( m_pEffect != nullptr )
      m_pEffect->Enable(this: m_pEffect, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169B00
// Name: public: virtual void CScreenSpaceEffectManager::RenderEffects(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScreenSpaceEffectManager::RenderEffects(CScreenSpaceEffectManager *this, int x, int y, int w, int h)
{
  CScreenSpaceEffectRegistration *i; // esi
  IScreenSpaceEffect *m_pEffect; // ecx

  for ( i = CScreenSpaceEffectRegistration::s_pHead; i != nullptr; i = i->m_pNext )
  {
    m_pEffect = i->m_pEffect;
    if ( m_pEffect != nullptr )
      m_pEffect->Render(this: m_pEffect, a2: x, a3: y, a4: w, a5: h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169B40
// Name: public: virtual void CExampleEffect::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExampleEffect::Init(CExampleEffect *this)
{
  this->m_bEnable = false;
}

//------------------------------------------------------------------------------
// Address: 0x10169B50
// Name: public: virtual void CExampleEffect::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExampleEffect::Shutdown(CExampleEffect *this)
{
  CMaterialReference::Shutdown(this: &this->m_Material, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x10169B60
// Name: public: virtual void CExampleEffect::SetParameters(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExampleEffect::SetParameters(CExampleEffect *this, KeyValues *params)
{
  KeyValues::GetDataType(this: params, keyName: "example_param");
}

//------------------------------------------------------------------------------
// Address: 0x10169B80
// Name: public: virtual void CExampleEffect::Render(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CExampleEffect::Render(
        CExampleEffect *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned int x,
        unsigned int y,
        unsigned int w,
        unsigned int h)
{
  ITexture *FullFrameFrameBufferTexture; // edi
  int v9; // eax
  int v10; // esi
  IMaterial *m_pMaterial; // ecx
  int (__thiscall *GetActualHeight)(ITexture *); // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  Rect_t actualRect; // [esp+30h] [ebp-14h] BYREF
  IMaterial *v18; // [esp+40h] [ebp-4h]

  if ( this->IsEnabled(this) )
  {
    UpdateScreenEffectTexture(
      a1: (int)this,
      a2: a3,
      textureIndex: 0,
      x: __SPAIR64__(y, x),
      w: __SPAIR64__(h, w),
      bDestFullScreen: false,
      pActualRect: &actualRect);
    FullFrameFrameBufferTexture = GetFullFrameFrameBufferTexture(textureIndex: 0);
    v9 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2, a3);
    v10 = v9;
    if ( v9 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
    m_pMaterial = this->m_Material.m_pMaterial;
    GetActualHeight = FullFrameFrameBufferTexture->GetActualHeight;
    v13 = *(_DWORD *)v10;
    v18 = m_pMaterial;
    v14 = ((int (__thiscall *)(ITexture *, _DWORD))GetActualHeight)(a1: FullFrameFrameBufferTexture, a2: 0);
    v15 = ((int (__thiscall *)(ITexture *, int))FullFrameFrameBufferTexture->GetActualWidth)(
            a1: FullFrameFrameBufferTexture,
            a2: v14);
    (*(void (__thiscall **)(int, IMaterial *, unsigned int, unsigned int, unsigned int, unsigned int, float, float, float, float, int))(v13 + 420))(
      a1: v10,
      a2: v18,
      a3: x,
      a4: y,
      a5: w,
      a6: h,
      a7: (float)actualRect.x,
      a8: (float)actualRect.y,
      a9: (float)(actualRect.width + actualRect.x - 1),
      a10: (float)(actualRect.height + actualRect.y - 1),
      a11: v15);
    (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 12))(a1: v10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC2B0
// Name: public: virtual bool CExampleEffect::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExampleEffect::IsEnabled(CExampleEffect *this)
{
  return this->m_bEnable;
}
