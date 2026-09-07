// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/materialsystem/materialsystemutil.cpp
// Functions: 9
// ============================================================

#include "public\materialsystem\materialsystemutil.h"

//------------------------------------------------------------------------------
// Address: 0x1027F5B0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F5F0
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1027F600
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F640
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F670
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F6B0
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F6E0
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F720
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F790
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x10002AB0
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025D1A0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D1E0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D210
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1025D260
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D290
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D2D0
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D340
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace MaterialSystem

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00576D10
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576D50
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576D80
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00576DD0
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576E10
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576E80
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005DA460
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA4A0
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DA4B0
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA4F0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA520
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x005DA570
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA5B0
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA5E0
// Name: public: void CTextureReference::Init(char const __near *,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(
        CTextureReference *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        BOOL bComplain,
        int nAdditionalCreationFlags)
{
  ITexture *m_pTexture; // ecx
  ITexture *v7; // eax

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  v7 = materials->FindTexture(
         this: materials,
         a2: pTextureName,
         a3: pTextureGroupName,
         a4: bComplain,
         a5: nAdditionalCreationFlags);
  this->m_pTexture = v7;
  if ( v7 != nullptr )
    v7->IncrementReferenceCount(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x005DA640
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA680
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA6F0
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027A270
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1027F700
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F740
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F780
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F7B0
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F7F0
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F820
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F860
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F8D0
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1014D1B0
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B7FB0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8000
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8040
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8070
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x102B80C0
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8100
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8130
// Name: public: void CTextureReference::Init(char const __near *,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(
        CTextureReference *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        BOOL bComplain,
        int nAdditionalCreationFlags)
{
  ITexture *m_pTexture; // ecx
  ITexture *v7; // eax

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  v7 = materials->FindTexture(
         this: materials,
         a2: pTextureName,
         a3: pTextureGroupName,
         a4: bComplain,
         a5: nAdditionalCreationFlags);
  this->m_pTexture = v7;
  if ( v7 != nullptr )
    v7->IncrementReferenceCount(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x102B8190
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B81D0
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8240
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0057BE20
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057BE60
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057BE90
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEE0
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057BF20
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057BF90
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace hlmv

// ============================================================
// Overlay from materialsystemtest (Missing functions)
// ============================================================
namespace materialsystemtest {

//------------------------------------------------------------------------------
// Address: 0x0040CCC0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CD00
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CD30
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0040CD80
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CDF0
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace materialsystemtest

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C8AB0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C8AF0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C8B20
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x005C8B70
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C8BB0
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C8C20
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace mdlcompile

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004208B0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004208F0
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00420900
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420940
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420970
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004209C0
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004209F0
// Name: public: void CTextureReference::Init(char const __near *,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(
        CTextureReference *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        BOOL bComplain,
        int nAdditionalCreationFlags)
{
  ITexture *m_pTexture; // ecx
  ITexture *v7; // eax

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  v7 = materials->FindTexture(
         this: materials,
         a2: pTextureName,
         a3: pTextureGroupName,
         a4: bComplain,
         a5: nAdditionalCreationFlags);
  this->m_pTexture = v7;
  if ( v7 != nullptr )
    v7->IncrementReferenceCount(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00420A50
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420A90
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420B00
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0053BB60
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053BBA0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053BBD0
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0053BC20
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053BC60
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053BCD0
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054F610
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F650
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F680
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0054F6D0
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F710
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F780
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006055D0
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00605B80
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605BC0
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605C00
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605C30
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00605C80
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605CC0
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605CF0
// Name: public: void CTextureReference::Init(char const __near *,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(
        CTextureReference *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        BOOL bComplain,
        int nAdditionalCreationFlags)
{
  ITexture *m_pTexture; // ecx
  ITexture *v7; // eax

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  v7 = materials->FindTexture(
         this: materials,
         a2: pTextureName,
         a3: pTextureGroupName,
         a4: bComplain,
         a5: nAdditionalCreationFlags);
  this->m_pTexture = v7;
  if ( v7 != nullptr )
    v7->IncrementReferenceCount(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00605D50
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605D90
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605E00
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005513B0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005513F0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00551420
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00551470
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005514B0
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00551520
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005C0EA0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C0EE0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C0F10
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x005C0F60
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C0FA0
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C1010
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00547F80
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00547FC0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00548000
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00548050
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00548090
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00548100
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace uvlightmap

// ============================================================
// Overlay from valve_avi (Missing functions)
// ============================================================
namespace valve_avi {

//------------------------------------------------------------------------------
// Address: 0x10009CD0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009D10
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10009D20
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009D60
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009D90
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x10009DE0
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009E10
// Name: public: void CTextureReference::InitProceduralTexture(char const __near *,char const __near *,int,int,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::InitProceduralTexture(
        CTextureReference *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        int w,
        int h,
        ImageFormat fmt,
        int nFlags)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  this->m_pTexture = materials->CreateProceduralTexture(
                       this: materials,
                       a2: pTextureName,
                       a3: pTextureGroupName,
                       a4: w,
                       a5: h,
                       a6: fmt,
                       a7: nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10009E70
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009EE0
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace valve_avi

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10049C70
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004A3F0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A430
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A470
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A4A0
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A4D0
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A510
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A580
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        KeyValues *pVMTKeyValues)
{
  IMaterial *v5; // eax
  IMaterial *m_pMaterial; // ecx
  IMaterial *v7; // esi

  v5 = materials->FindProceduralMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: pVMTKeyValues);
  m_pMaterial = this->m_pMaterial;
  v7 = v5;
  if ( this->m_pMaterial != v5 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v7;
    if ( v7 != nullptr )
      v7->IncrementReferenceCount(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A5E0
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00468EC0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468F00
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00468F10
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468F50
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468F80
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468FC0
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468FF0
// Name: public: void CTextureReference::Init(char const __near *,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(
        CTextureReference *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        BOOL bComplain,
        int nAdditionalCreationFlags)
{
  ITexture *m_pTexture; // ecx
  ITexture *v7; // eax

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  v7 = materials->FindTexture(
         this: materials,
         a2: pTextureName,
         a3: pTextureGroupName,
         a4: bComplain,
         a5: nAdditionalCreationFlags);
  this->m_pTexture = v7;
  if ( v7 != nullptr )
    v7->IncrementReferenceCount(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00469050
// Name: public: void CTextureReference::InitRenderTarget(int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t,bool,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::InitRenderTarget(
        CTextureReference *this,
        int w,
        int h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat fmt,
        MaterialRenderTargetDepth_t depth,
        bool bHDR,
        char *pStrOptionalName)
{
  ITexture *m_pTexture; // ecx
  unsigned int v10; // eax

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  v10 = 12;
  if ( depth == MATERIAL_RT_DEPTH_ONLY )
    v10 = 13;
  this->m_pTexture = materials->CreateNamedRenderTargetTextureEx(
                       this: materials,
                       a2: pStrOptionalName,
                       a3: w,
                       a4: h,
                       a5: sizeMode,
                       a6: fmt,
                       a7: depth,
                       a8: v10,
                       a9: bHDR);
}

//------------------------------------------------------------------------------
// Address: 0x004690D0
// Name: public: class CMaterialReference const __near & CMaterialReference::operator=(class CMaterialReference const __near &)
// Source: json
//------------------------------------------------------------------------------
const CMaterialReference *__thiscall CMaterialReference::operator=(
        CMaterialReference *this,
        const CMaterialReference *ref)
{
  IMaterial *m_pMaterial; // ecx
  IMaterial *v4; // edi

  m_pMaterial = this->m_pMaterial;
  v4 = ref->m_pMaterial;
  if ( m_pMaterial != ref->m_pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v4;
    if ( v4 != nullptr )
      v4->IncrementReferenceCount(this: v4);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00469110
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469180
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        KeyValues *pVMTKeyValues)
{
  IMaterial *v5; // eax
  IMaterial *m_pMaterial; // ecx
  IMaterial *v7; // esi

  v5 = materials->FindProceduralMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: pVMTKeyValues);
  m_pMaterial = this->m_pMaterial;
  v7 = v5;
  if ( this->m_pMaterial != v5 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v7;
    if ( v7 != nullptr )
      v7->IncrementReferenceCount(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004691E0
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00651170
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006511B0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006511E0
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00651230
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00651270
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006512E0
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace vmap

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036ED40
// Name: public: CTextureReference::CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(CTextureReference *this)
{
  this->m_pTexture = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1036F2F0
// Name: public: void CMaterialReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Shutdown(CMaterialReference *this, bool bDeleteIfUnreferenced)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    if ( bDeleteIfUnreferenced )
      this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F330
// Name: public: void CTextureReference::Shutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Shutdown(CTextureReference *this, bool bDeleteIfUnReferenced)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    if ( bDeleteIfUnReferenced )
      this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F370
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F3A0
// Name: public: void CMaterialReference::Init(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, const char *pMaterialName, KeyValues *pVMTKeyValues)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  this->m_pMaterial = materials->CreateMaterial(this: materials, a2: pMaterialName, a3: pVMTKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1036F3F0
// Name: public: void CMaterialReference::Init(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, IMaterial *pMaterial)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = pMaterial;
    if ( pMaterial != nullptr )
      pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F430
// Name: public: void CMaterialReference::Init(class CMaterialReference __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(CMaterialReference *this, CMaterialReference *ref)
{
  IMaterial *m_pMaterial; // ecx
  IMaterial *v4; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != ref->m_pMaterial )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    v4 = ref->m_pMaterial;
    this->m_pMaterial = ref->m_pMaterial;
    if ( v4 != nullptr )
      v4->IncrementReferenceCount(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F470
// Name: public: CTextureReference::~CTextureReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::~CTextureReference(CTextureReference *this)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F4A0
// Name: public: void CTextureReference::Init(char const __near *,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(
        CTextureReference *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        BOOL bComplain,
        int nAdditionalCreationFlags)
{
  ITexture *m_pTexture; // ecx
  ITexture *v7; // eax

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  v7 = materials->FindTexture(
         this: materials,
         a2: pTextureName,
         a3: pTextureGroupName,
         a4: bComplain,
         a5: nAdditionalCreationFlags);
  this->m_pTexture = v7;
  if ( v7 != nullptr )
    v7->IncrementReferenceCount(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1036F500
// Name: public: void CTextureReference::Init(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::Init(CTextureReference *this, ITexture *pTexture)
{
  ITexture *m_pTexture; // ecx

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = pTexture;
    if ( pTexture != nullptr )
      pTexture->IncrementReferenceCount(this: pTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F540
// Name: public: void CTextureReference::InitRenderTarget(int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t,bool,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureReference::InitRenderTarget(
        CTextureReference *this,
        int w,
        int h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat fmt,
        MaterialRenderTargetDepth_t depth,
        bool bHDR,
        char *pStrOptionalName)
{
  ITexture *m_pTexture; // ecx
  unsigned int v10; // eax

  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr && materials != nullptr )
  {
    m_pTexture->DecrementReferenceCount(this: m_pTexture);
    this->m_pTexture = nullptr;
  }
  v10 = 12;
  if ( depth == MATERIAL_RT_DEPTH_ONLY )
    v10 = 13;
  this->m_pTexture = materials->CreateNamedRenderTargetTextureEx(
                       this: materials,
                       a2: pStrOptionalName,
                       a3: w,
                       a4: h,
                       a5: sizeMode,
                       a6: fmt,
                       a7: depth,
                       a8: v10,
                       a9: bHDR);
}

//------------------------------------------------------------------------------
// Address: 0x1036F5B0
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F620
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        KeyValues *pVMTKeyValues)
{
  IMaterial *v5; // eax
  IMaterial *m_pMaterial; // ecx
  IMaterial *v7; // esi

  v5 = materials->FindProceduralMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: pVMTKeyValues);
  m_pMaterial = this->m_pMaterial;
  v7 = v5;
  if ( this->m_pMaterial != v5 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v7;
    if ( v7 != nullptr )
      v7->IncrementReferenceCount(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F680
// Name: public: CTextureReference::CTextureReference(class CTextureReference const __near &)
// Source: json
//------------------------------------------------------------------------------
CTextureReference *__thiscall CTextureReference::CTextureReference(
        CTextureReference *this,
        const CTextureReference *ref)
{
  ITexture *m_pTexture; // ecx

  this->m_pTexture = nullptr;
  m_pTexture = ref->m_pTexture;
  if ( ref->m_pTexture != nullptr )
  {
    this->m_pTexture = m_pTexture;
    m_pTexture->IncrementReferenceCount(this: m_pTexture);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1036F6B0
// Name: public: class CTextureReference const __near & CTextureReference::operator=(class CTextureReference __near &)
// Source: json
//------------------------------------------------------------------------------
const CTextureReference *__thiscall CTextureReference::operator=(CTextureReference *this, CTextureReference *ref)
{
  ITexture *m_pTexture; // ecx
  ITexture *v4; // edi

  m_pTexture = this->m_pTexture;
  v4 = ref->m_pTexture;
  if ( m_pTexture != ref->m_pTexture )
  {
    if ( m_pTexture != nullptr && materials != nullptr )
    {
      m_pTexture->DecrementReferenceCount(this: m_pTexture);
      this->m_pTexture = nullptr;
    }
    this->m_pTexture = v4;
    if ( v4 != nullptr )
      v4->IncrementReferenceCount(this: v4);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1036F700
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037F1F0
// Name: public: CMaterialReference::~CMaterialReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::~CMaterialReference(CMaterialReference *this)
{
  IMaterial *m_pMaterial; // ecx

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr && materials != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037F220
// Name: public: void CMaterialReference::Init(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialReference::Init(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  IMaterial *v5; // eax
  IMaterial *v6; // esi
  IMaterial *m_pMaterial; // ecx

  v5 = materials->FindMaterial(this: materials, a2: pMaterialName, a3: pTextureGroupName, a4: bComplain, a5: 0);
  v6 = v5;
  if ( v5 != nullptr )
    v5->IsErrorMaterial(this: v5);
  m_pMaterial = this->m_pMaterial;
  if ( this->m_pMaterial != v6 )
  {
    if ( m_pMaterial != nullptr && materials != nullptr )
    {
      m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
      this->m_pMaterial = nullptr;
    }
    this->m_pMaterial = v6;
    if ( v6 != nullptr )
      v6->IncrementReferenceCount(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037F290
// Name: public: CMaterialReference::CMaterialReference(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMaterialReference::CMaterialReference(
        CMaterialReference *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL bComplain)
{
  this->m_pMaterial = nullptr;
  if ( pMaterialName != nullptr )
    CMaterialReference::Init(this, pMaterialName, pTextureGroupName, bComplain);
  return this;
}

} // namespace server
