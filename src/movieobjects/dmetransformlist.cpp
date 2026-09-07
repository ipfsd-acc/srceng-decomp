// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmetransformlist.cpp
// Functions: 4
// ============================================================

#include "movieobjects\dmetransformlist.h"

//------------------------------------------------------------------------------
// Address: 0x004B2310
// Name: public: void CDmeTransformList::SetTransform(int,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::SetTransform(CDmeTransformList *this, int nIndex, const matrix3x4_t *mat)
{
  CDmElement *v3; // eax
  CDmeTransform *v4; // esi

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v4 = (CDmeTransform *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeTransform::m_classType) )
    CDmeTransform::SetTransform(this: v4, transform: mat);
  else
    CDmeTransform::SetTransform(this: nullptr, transform: mat);
}

//------------------------------------------------------------------------------
// Address: 0x004B23D0
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B2400
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B2440
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004F9320
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F9350
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F9390
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x105947E0
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10594810
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10594860
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004AE8A0
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE8D0
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE910
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050BBF0
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050BC20
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050BC60
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00466670
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004666A0
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004666F0
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00469AB0
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00469AE0
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00469B20
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D3D60
// Name: public: void CDmeTransformList::SetTransform(int,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::SetTransform(CDmeTransformList *this, int nIndex, const matrix3x4_t *mat)
{
  int v3; // eax
  CDmeTransform *v4; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v4 = (CDmeTransform *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeTransform::m_classType.u) != 0 )
  {
    CDmeTransform::SetTransform(this: v4, transform: mat);
  }
  else
  {
    CDmeTransform::SetTransform(this: nullptr, transform: mat);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D3E20
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D3E50
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D3E90
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0046A6B0
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A6E0
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A720
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00504C40
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504C70
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504CC0
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047E7A0
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E7D0
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E810
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00577820
// Name: public: void CDmeTransformList::SetTransform(int,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::SetTransform(CDmeTransformList *this, int nIndex, const matrix3x4_t *mat)
{
  CDmElement *v3; // eax
  CDmeTransform *v4; // esi

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v4 = (CDmeTransform *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeTransform::m_classType) )
    CDmeTransform::SetTransform(this: v4, transform: mat);
  else
    CDmeTransform::SetTransform(this: nullptr, transform: mat);
}

//------------------------------------------------------------------------------
// Address: 0x005778E0
// Name: public: virtual bool CDmeTransformList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformList::IsA(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00577910
// Name: public: virtual int CDmeTransformList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformList::GetInheritanceDepth(CDmeTransformList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00577950
// Name: protected: virtual void CDmeTransformList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformList::PerformConstruction(CDmeTransformList *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Transforms.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "transforms",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Transforms);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Transforms.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
}

} // namespace vmap
