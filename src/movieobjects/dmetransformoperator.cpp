// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmetransformoperator.cpp
// Functions: 13
// ============================================================

#include "movieobjects\dmetransformoperator.h"

//------------------------------------------------------------------------------
// Address: 0x0055A950
// Name: protected: void CDmeTransformOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::OnConstruction(CDmeTransformOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx
  CDmElement *v7; // ecx
  CDmElement *v8; // ecx
  CDmElement *v9; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_transform.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v2,
                                     pAttributeName: "transform",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_transform);
  CDmAttribute::SetElementTypeSymbol(this: this->m_transform.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_positionX.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "positionX",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionX);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_positionY.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v4,
                                     pAttributeName: "positionY",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionY);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_positionZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v5,
                                     pAttributeName: "positionZ",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionZ);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_orientationX.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v6,
                                        pAttributeName: "orientationX",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationX);
  if ( this != nullptr )
    v7 = &this->CDmElement;
  else
    v7 = nullptr;
  this->m_orientationY.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v7,
                                        pAttributeName: "orientationY",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationY);
  if ( this != nullptr )
    v8 = &this->CDmElement;
  else
    v8 = nullptr;
  this->m_orientationZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v8,
                                        pAttributeName: "orientationZ",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationZ);
  if ( this != nullptr )
    v9 = &this->CDmElement;
  else
    v9 = nullptr;
  this->m_orientationW.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v9,
                                        pAttributeName: "orientationW",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationW);
}

//------------------------------------------------------------------------------
// Address: 0x0055AA60
// Name: public: virtual void CDmeTransformOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::Operate(CDmeTransformOperator *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector> *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Quaternion orientation; // [esp+8h] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-Ch] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( Attribute != nullptr )
      v4 = CDmAttribute::GetValue<Vector>(this: Attribute);
    else
      v4 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    position = v4->m_Storage;
    orientation = CDmElement::GetValue<Quaternion>(this: v2, pAttributeName: "orientation")->m_Storage;
    position.x = this->m_positionX.m_Storage;
    position.y = this->m_positionY.m_Storage;
    position.z = this->m_positionZ.m_Storage;
    orientation.x = this->m_orientationX.m_Storage;
    orientation.y = this->m_orientationY.m_Storage;
    orientation.z = this->m_orientationZ.m_Storage;
    orientation.w = this->m_orientationW.m_Storage;
    v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( v5 != nullptr
      || (v5 = CDmElement::CreateAttribute(this: v2, pAttributeName: "position", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: v5, value: &position);
    }
    v6 = CDmElement::FindAttribute(this: v2, pAttributeName: "orientation");
    if ( v6 != nullptr
      || (v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v6, value: &orientation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055ABC0
// Name: public: virtual void CDmeTransformOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetInputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  MorphOp::AddAttr(attrs, pAttr: this->m_positionX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationW.m_pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x0055AC20
// Name: public: virtual void CDmeTransformOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetOutputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    MorphOp::AddAttr(attrs, pAttr: Attribute);
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "orientation");
    MorphOp::AddAttr(attrs, pAttr: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055ACE0
// Name: protected: CDmeTransformOperator::CDmeTransformOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformOperator *__thiscall CDmeTransformOperator::CDmeTransformOperator(
        CDmeTransformOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&CDmeTransformOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeTransformOperator::`vftable'{for `CDmElement'};
  this->m_transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_transform.m_pAttribute = nullptr;
  this->m_positionX = 0;
  this->m_positionY = 0;
  this->m_positionZ = 0;
  this->m_orientationX = 0;
  this->m_orientationY = 0;
  this->m_orientationZ = 0;
  this->m_orientationW = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0055ADD0
// Name: public: virtual bool CDmeTransformOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformOperator::IsA(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055AE00
// Name: public: virtual int CDmeTransformOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformOperator::GetInheritanceDepth(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055AEB0
// Name: protected: virtual void CDmeTransformOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::PerformConstruction(CDmeTransformOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
  CDmeTransformOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x005ADD70
// Name: _dynamic_initializer_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformOperator::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B05D0
// Name: _dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADDA0
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADDB0
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformOperator_Helper,
           classname: "DmeTransformOperator",
           pFactory: &g_CDmeTransformOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B05E0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformOperator_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005B1A10
// Name: protected: void CDmeTransformOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::OnConstruction(CDmeTransformOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx
  CDmElement *v7; // ecx
  CDmElement *v8; // ecx
  CDmElement *v9; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_transform.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v2,
                                     pAttributeName: "transform",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_transform);
  CDmAttribute::SetElementTypeSymbol(this: this->m_transform.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_positionX.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "positionX",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionX);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_positionY.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v4,
                                     pAttributeName: "positionY",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionY);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_positionZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v5,
                                     pAttributeName: "positionZ",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionZ);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_orientationX.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v6,
                                        pAttributeName: "orientationX",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationX);
  if ( this != nullptr )
    v7 = &this->CDmElement;
  else
    v7 = nullptr;
  this->m_orientationY.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v7,
                                        pAttributeName: "orientationY",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationY);
  if ( this != nullptr )
    v8 = &this->CDmElement;
  else
    v8 = nullptr;
  this->m_orientationZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v8,
                                        pAttributeName: "orientationZ",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationZ);
  if ( this != nullptr )
    v9 = &this->CDmElement;
  else
    v9 = nullptr;
  this->m_orientationW.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v9,
                                        pAttributeName: "orientationW",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationW);
}

//------------------------------------------------------------------------------
// Address: 0x005B1B20
// Name: public: virtual void CDmeTransformOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::Operate(CDmeTransformOperator *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector> *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Quaternion orientation; // [esp+8h] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-Ch] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( Attribute != nullptr )
      v4 = CDmAttribute::GetValue<Vector>(this: Attribute);
    else
      v4 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    position = v4->m_Storage;
    orientation = CDmElement::GetValue<Quaternion>(this: v2, pAttributeName: "orientation")->m_Storage;
    position.x = this->m_positionX.m_Storage;
    position.y = this->m_positionY.m_Storage;
    position.z = this->m_positionZ.m_Storage;
    orientation.x = this->m_orientationX.m_Storage;
    orientation.y = this->m_orientationY.m_Storage;
    orientation.z = this->m_orientationZ.m_Storage;
    orientation.w = this->m_orientationW.m_Storage;
    v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( v5 != nullptr
      || (v5 = CDmElement::CreateAttribute(this: v2, pAttributeName: "position", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: v5, value: &position);
    }
    v6 = CDmElement::FindAttribute(this: v2, pAttributeName: "orientation");
    if ( v6 != nullptr
      || (v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v6, value: &orientation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B1CF0
// Name: public: virtual void CDmeTransformOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetInputAttributes(
        CDmeTransformOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  MorphOp::AddAttr(attrs, pAttr: this->m_positionX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationW.m_pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x005B1D50
// Name: public: virtual void CDmeTransformOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetOutputAttributes(
        CDmeTransformOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    MorphOp::AddAttr(attrs, pAttr: Attribute);
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "orientation");
    MorphOp::AddAttr(attrs, pAttr: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B1E10
// Name: protected: CDmeTransformOperator::CDmeTransformOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformOperator *__thiscall CDmeTransformOperator::CDmeTransformOperator(
        CDmeTransformOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&CDmeTransformOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeTransformOperator::`vftable'{for `CDmElement'};
  this->m_transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_transform.m_pAttribute = nullptr;
  this->m_positionX = 0;
  this->m_positionY = 0;
  this->m_positionZ = 0;
  this->m_orientationX = 0;
  this->m_orientationY = 0;
  this->m_orientationZ = 0;
  this->m_orientationW = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B1F00
// Name: public: virtual bool CDmeTransformOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformOperator::IsA(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B1F30
// Name: public: virtual int CDmeTransformOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformOperator::GetInheritanceDepth(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B1FE0
// Name: protected: virtual void CDmeTransformOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::PerformConstruction(CDmeTransformOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
  CDmeTransformOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0067F560
// Name: _dynamic_initializer_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformOperator::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682AE0
// Name: _dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F590
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F5A0
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformOperator_Helper,
           classname: "DmeTransformOperator",
           pFactory: &g_CDmeTransformOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682AF0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTransformOperator_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051C160
// Name: protected: void CDmeTransformOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::OnConstruction(CDmeTransformOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx
  CDmElement *v7; // ecx
  CDmElement *v8; // ecx
  CDmElement *v9; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_transform.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v2,
                                     pAttributeName: "transform",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_transform);
  CDmAttribute::SetElementTypeSymbol(this: this->m_transform.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_positionX.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "positionX",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionX);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_positionY.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v4,
                                     pAttributeName: "positionY",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionY);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_positionZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v5,
                                     pAttributeName: "positionZ",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionZ);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_orientationX.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v6,
                                        pAttributeName: "orientationX",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationX);
  if ( this != nullptr )
    v7 = &this->CDmElement;
  else
    v7 = nullptr;
  this->m_orientationY.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v7,
                                        pAttributeName: "orientationY",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationY);
  if ( this != nullptr )
    v8 = &this->CDmElement;
  else
    v8 = nullptr;
  this->m_orientationZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v8,
                                        pAttributeName: "orientationZ",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationZ);
  if ( this != nullptr )
    v9 = &this->CDmElement;
  else
    v9 = nullptr;
  this->m_orientationW.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v9,
                                        pAttributeName: "orientationW",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationW);
}

//------------------------------------------------------------------------------
// Address: 0x0051C270
// Name: public: virtual void CDmeTransformOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::Operate(CDmeTransformOperator *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector> *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Quaternion orientation; // [esp+8h] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-Ch] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( Attribute != nullptr )
      v4 = CDmAttribute::GetValue<Vector>(this: Attribute);
    else
      v4 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    position = v4->m_Storage;
    orientation = CDmElement::GetValue<Quaternion>(this: v2, pAttributeName: "orientation")->m_Storage;
    position.x = this->m_positionX.m_Storage;
    position.y = this->m_positionY.m_Storage;
    position.z = this->m_positionZ.m_Storage;
    orientation.x = this->m_orientationX.m_Storage;
    orientation.y = this->m_orientationY.m_Storage;
    orientation.z = this->m_orientationZ.m_Storage;
    orientation.w = this->m_orientationW.m_Storage;
    v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( v5 != nullptr
      || (v5 = CDmElement::CreateAttribute(this: v2, pAttributeName: "position", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: v5, value: &position);
    }
    v6 = CDmElement::FindAttribute(this: v2, pAttributeName: "orientation");
    if ( v6 != nullptr
      || (v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v6, value: &orientation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051C440
// Name: public: virtual void CDmeTransformOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetInputAttributes(
        CDmeTransformOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  MorphOp::AddAttr(attrs, pAttr: this->m_positionX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationW.m_pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x0051C4A0
// Name: public: virtual void CDmeTransformOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetOutputAttributes(
        CDmeTransformOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    MorphOp::AddAttr(attrs, pAttr: Attribute);
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "orientation");
    MorphOp::AddAttr(attrs, pAttr: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051C560
// Name: protected: CDmeTransformOperator::CDmeTransformOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformOperator *__thiscall CDmeTransformOperator::CDmeTransformOperator(
        CDmeTransformOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&CDmeTransformOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeTransformOperator::`vftable'{for `CDmElement'};
  this->m_transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_transform.m_pAttribute = nullptr;
  this->m_positionX = 0;
  this->m_positionY = 0;
  this->m_positionZ = 0;
  this->m_orientationX = 0;
  this->m_orientationY = 0;
  this->m_orientationZ = 0;
  this->m_orientationW = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051C650
// Name: public: virtual bool CDmeTransformOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformOperator::IsA(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C680
// Name: public: virtual int CDmeTransformOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformOperator::GetInheritanceDepth(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C730
// Name: protected: virtual void CDmeTransformOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::PerformConstruction(CDmeTransformOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
  CDmeTransformOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0056C140
// Name: _dynamic_initializer_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformOperator::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056ECC0
// Name: _dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C170
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C180
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformOperator_Helper,
           classname: "DmeTransformOperator",
           pFactory: &g_CDmeTransformOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056ECD0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformOperator_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00522380
// Name: protected: void CDmeTransformOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::OnConstruction(CDmeTransformOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx
  CDmElement *v7; // ecx
  CDmElement *v8; // ecx
  CDmElement *v9; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_transform.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v2,
                                     pAttributeName: "transform",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_transform);
  CDmAttribute::SetElementTypeSymbol(this: this->m_transform.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_positionX.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "positionX",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionX);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_positionY.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v4,
                                     pAttributeName: "positionY",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionY);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_positionZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v5,
                                     pAttributeName: "positionZ",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionZ);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_orientationX.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v6,
                                        pAttributeName: "orientationX",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationX);
  if ( this != nullptr )
    v7 = &this->CDmElement;
  else
    v7 = nullptr;
  this->m_orientationY.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v7,
                                        pAttributeName: "orientationY",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationY);
  if ( this != nullptr )
    v8 = &this->CDmElement;
  else
    v8 = nullptr;
  this->m_orientationZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v8,
                                        pAttributeName: "orientationZ",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationZ);
  if ( this != nullptr )
    v9 = &this->CDmElement;
  else
    v9 = nullptr;
  this->m_orientationW.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v9,
                                        pAttributeName: "orientationW",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationW);
}

//------------------------------------------------------------------------------
// Address: 0x00522490
// Name: public: virtual void CDmeTransformOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::Operate(CDmeTransformOperator *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector> *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Quaternion orientation; // [esp+8h] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-Ch] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( Attribute != nullptr )
      v4 = CDmAttribute::GetValue<Vector>(this: Attribute);
    else
      v4 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    position = v4->m_Storage;
    orientation = CDmElement::GetValue<Quaternion>(this: v2, pAttributeName: "orientation")->m_Storage;
    position.x = this->m_positionX.m_Storage;
    position.y = this->m_positionY.m_Storage;
    position.z = this->m_positionZ.m_Storage;
    orientation.x = this->m_orientationX.m_Storage;
    orientation.y = this->m_orientationY.m_Storage;
    orientation.z = this->m_orientationZ.m_Storage;
    orientation.w = this->m_orientationW.m_Storage;
    v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( v5 != nullptr
      || (v5 = CDmElement::CreateAttribute(this: v2, pAttributeName: "position", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: v5, value: &position);
    }
    v6 = CDmElement::FindAttribute(this: v2, pAttributeName: "orientation");
    if ( v6 != nullptr
      || (v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v6, value: &orientation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00522660
// Name: public: virtual void CDmeTransformOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetInputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  MorphOp::AddAttr(attrs, pAttr: this->m_positionX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationW.m_pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x005226C0
// Name: public: virtual void CDmeTransformOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetOutputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    MorphOp::AddAttr(attrs, pAttr: Attribute);
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "orientation");
    MorphOp::AddAttr(attrs, pAttr: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00522780
// Name: protected: CDmeTransformOperator::CDmeTransformOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformOperator *__thiscall CDmeTransformOperator::CDmeTransformOperator(
        CDmeTransformOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&CDmeTransformOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeTransformOperator::`vftable'{for `CDmElement'};
  this->m_transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_transform.m_pAttribute = nullptr;
  this->m_positionX = 0;
  this->m_positionY = 0;
  this->m_positionZ = 0;
  this->m_orientationX = 0;
  this->m_orientationY = 0;
  this->m_orientationZ = 0;
  this->m_orientationW = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00522870
// Name: public: virtual bool CDmeTransformOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformOperator::IsA(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005228A0
// Name: public: virtual int CDmeTransformOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformOperator::GetInheritanceDepth(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522950
// Name: protected: virtual void CDmeTransformOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::PerformConstruction(CDmeTransformOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
  CDmeTransformOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057C260
// Name: _dynamic_initializer_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformOperator::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDF0
// Name: _dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C290
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2A0
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformOperator_Helper,
           classname: "DmeTransformOperator",
           pFactory: &g_CDmeTransformOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE00
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformOperator_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DF290
// Name: protected: void CDmeTransformOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::OnConstruction(CDmeTransformOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx
  CDmElement *v7; // ecx
  CDmElement *v8; // ecx
  CDmElement *v9; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_transform.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v2,
                                     pAttributeName: "transform",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_transform);
  CDmAttribute::SetElementTypeSymbol(this: this->m_transform.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_positionX.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "positionX",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionX);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_positionY.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v4,
                                     pAttributeName: "positionY",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionY);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_positionZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v5,
                                     pAttributeName: "positionZ",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionZ);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_orientationX.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v6,
                                        pAttributeName: "orientationX",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationX);
  if ( this != nullptr )
    v7 = &this->CDmElement;
  else
    v7 = nullptr;
  this->m_orientationY.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v7,
                                        pAttributeName: "orientationY",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationY);
  if ( this != nullptr )
    v8 = &this->CDmElement;
  else
    v8 = nullptr;
  this->m_orientationZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v8,
                                        pAttributeName: "orientationZ",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationZ);
  if ( this != nullptr )
    v9 = &this->CDmElement;
  else
    v9 = nullptr;
  this->m_orientationW.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v9,
                                        pAttributeName: "orientationW",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationW);
}

//------------------------------------------------------------------------------
// Address: 0x005DF3A0
// Name: public: virtual void CDmeTransformOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::Operate(CDmeTransformOperator *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector> *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Quaternion orientation; // [esp+8h] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-Ch] BYREF

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( Attribute != nullptr )
      v4 = CDmAttribute::GetValue<Vector>(this: Attribute);
    else
      v4 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    position = v4->m_Storage;
    orientation = CDmElement::GetValue<Quaternion>(this: v2, pAttributeName: "orientation")->m_Storage;
    position.x = this->m_positionX.m_Storage;
    position.y = this->m_positionY.m_Storage;
    position.z = this->m_positionZ.m_Storage;
    orientation.x = this->m_orientationX.m_Storage;
    orientation.y = this->m_orientationY.m_Storage;
    orientation.z = this->m_orientationZ.m_Storage;
    orientation.w = this->m_orientationW.m_Storage;
    v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( v5 != nullptr
      || (v5 = CDmElement::CreateAttribute(this: v2, pAttributeName: "position", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: v5, value: &position);
    }
    v6 = CDmElement::FindAttribute(this: v2, pAttributeName: "orientation");
    if ( v6 != nullptr
      || (v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v6, value: &orientation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DF570
// Name: public: virtual void CDmeTransformOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetInputAttributes(
        CDmeTransformOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  MorphOp::AddAttr(attrs, pAttr: this->m_positionX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationW.m_pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x005DF5D0
// Name: public: virtual void CDmeTransformOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetOutputAttributes(
        CDmeTransformOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_transform.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    MorphOp::AddAttr(attrs, pAttr: Attribute);
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "orientation");
    MorphOp::AddAttr(attrs, pAttr: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DF690
// Name: protected: CDmeTransformOperator::CDmeTransformOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformOperator *__thiscall CDmeTransformOperator::CDmeTransformOperator(
        CDmeTransformOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&CDmeTransformOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeTransformOperator::`vftable'{for `CDmElement'};
  this->m_transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_transform.m_pAttribute = nullptr;
  this->m_positionX = 0;
  this->m_positionY = 0;
  this->m_positionZ = 0;
  this->m_orientationX = 0;
  this->m_orientationY = 0;
  this->m_orientationZ = 0;
  this->m_orientationW = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DF780
// Name: public: virtual bool CDmeTransformOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformOperator::IsA(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DF7B0
// Name: public: virtual int CDmeTransformOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformOperator::GetInheritanceDepth(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DF860
// Name: protected: virtual void CDmeTransformOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::PerformConstruction(CDmeTransformOperator *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
  CDmeTransformOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x006B13B0
// Name: _dynamic_initializer_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformOperator::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B55E0
// Name: _dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B13E0
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B13F0
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformOperator_Helper,
           classname: "DmeTransformOperator",
           pFactory: &g_CDmeTransformOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B55F0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTransformOperator_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00523600
// Name: protected: void CDmeTransformOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::OnConstruction(CDmeTransformOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx
  CDmElement *v7; // ecx
  CDmElement *v8; // ecx
  CDmElement *v9; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_transform.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v2,
                                     pAttributeName: "transform",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_transform);
  CDmAttribute::SetElementTypeSymbol(this: this->m_transform.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_positionX.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "positionX",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionX);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_positionY.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v4,
                                     pAttributeName: "positionY",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionY);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_positionZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v5,
                                     pAttributeName: "positionZ",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionZ);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_orientationX.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v6,
                                        pAttributeName: "orientationX",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationX);
  if ( this != nullptr )
    v7 = &this->CDmElement;
  else
    v7 = nullptr;
  this->m_orientationY.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v7,
                                        pAttributeName: "orientationY",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationY);
  if ( this != nullptr )
    v8 = &this->CDmElement;
  else
    v8 = nullptr;
  this->m_orientationZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v8,
                                        pAttributeName: "orientationZ",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationZ);
  if ( this != nullptr )
    v9 = &this->CDmElement;
  else
    v9 = nullptr;
  this->m_orientationW.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v9,
                                        pAttributeName: "orientationW",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationW);
}

//------------------------------------------------------------------------------
// Address: 0x00523710
// Name: public: virtual void CDmeTransformOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::Operate(CDmeTransformOperator *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector> *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Quaternion orientation; // [esp+8h] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-Ch] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( Attribute != nullptr )
      v4 = CDmAttribute::GetValue<Vector>(this: Attribute);
    else
      v4 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    position = v4->m_Storage;
    orientation = CDmElement::GetValue<Quaternion>(this: v2, pAttributeName: "orientation")->m_Storage;
    position.x = this->m_positionX.m_Storage;
    position.y = this->m_positionY.m_Storage;
    position.z = this->m_positionZ.m_Storage;
    orientation.x = this->m_orientationX.m_Storage;
    orientation.y = this->m_orientationY.m_Storage;
    orientation.z = this->m_orientationZ.m_Storage;
    orientation.w = this->m_orientationW.m_Storage;
    v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( v5 != nullptr
      || (v5 = CDmElement::CreateAttribute(this: v2, pAttributeName: "position", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: v5, value: &position);
    }
    v6 = CDmElement::FindAttribute(this: v2, pAttributeName: "orientation");
    if ( v6 != nullptr
      || (v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v6, value: &orientation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523870
// Name: public: virtual void CDmeTransformOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetInputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  MorphOp::AddAttr(attrs, pAttr: this->m_positionX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationW.m_pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x005238D0
// Name: public: virtual void CDmeTransformOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetOutputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    MorphOp::AddAttr(attrs, pAttr: Attribute);
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "orientation");
    MorphOp::AddAttr(attrs, pAttr: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523990
// Name: protected: CDmeTransformOperator::CDmeTransformOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformOperator *__thiscall CDmeTransformOperator::CDmeTransformOperator(
        CDmeTransformOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&CDmeTransformOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeTransformOperator::`vftable'{for `CDmElement'};
  this->m_transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_transform.m_pAttribute = nullptr;
  this->m_positionX = 0;
  this->m_positionY = 0;
  this->m_positionZ = 0;
  this->m_orientationX = 0;
  this->m_orientationY = 0;
  this->m_orientationZ = 0;
  this->m_orientationW = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00523A80
// Name: public: virtual bool CDmeTransformOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformOperator::IsA(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523AB0
// Name: public: virtual int CDmeTransformOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformOperator::GetInheritanceDepth(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523B60
// Name: protected: virtual void CDmeTransformOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::PerformConstruction(CDmeTransformOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
  CDmeTransformOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057E230
// Name: _dynamic_initializer_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformOperator::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580DD0
// Name: _dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E260
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E270
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformOperator_Helper,
           classname: "DmeTransformOperator",
           pFactory: &g_CDmeTransformOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580DE0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformOperator_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0052AB10
// Name: protected: void CDmeTransformOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::OnConstruction(CDmeTransformOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx
  CDmElement *v7; // ecx
  CDmElement *v8; // ecx
  CDmElement *v9; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_transform.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v2,
                                     pAttributeName: "transform",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_transform);
  CDmAttribute::SetElementTypeSymbol(this: this->m_transform.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_positionX.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "positionX",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionX);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_positionY.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v4,
                                     pAttributeName: "positionY",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionY);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_positionZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v5,
                                     pAttributeName: "positionZ",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionZ);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_orientationX.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v6,
                                        pAttributeName: "orientationX",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationX);
  if ( this != nullptr )
    v7 = &this->CDmElement;
  else
    v7 = nullptr;
  this->m_orientationY.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v7,
                                        pAttributeName: "orientationY",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationY);
  if ( this != nullptr )
    v8 = &this->CDmElement;
  else
    v8 = nullptr;
  this->m_orientationZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v8,
                                        pAttributeName: "orientationZ",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationZ);
  if ( this != nullptr )
    v9 = &this->CDmElement;
  else
    v9 = nullptr;
  this->m_orientationW.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v9,
                                        pAttributeName: "orientationW",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationW);
}

//------------------------------------------------------------------------------
// Address: 0x0052AC20
// Name: public: virtual void CDmeTransformOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::Operate(CDmeTransformOperator *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector> *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Quaternion orientation; // [esp+8h] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-Ch] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( Attribute != nullptr )
      v4 = (CDmaVar<Vector> *)CDmAttribute::GetValue<Vector>(this: Attribute);
    else
      v4 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    position = v4->m_Storage;
    orientation = CDmElement::GetValue<Quaternion>(this: v2, pAttributeName: "orientation")->m_Storage;
    position.x = this->m_positionX.m_Storage;
    position.y = this->m_positionY.m_Storage;
    position.z = this->m_positionZ.m_Storage;
    orientation.x = this->m_orientationX.m_Storage;
    orientation.y = this->m_orientationY.m_Storage;
    orientation.z = this->m_orientationZ.m_Storage;
    orientation.w = this->m_orientationW.m_Storage;
    v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( v5 != nullptr
      || (v5 = CDmElement::CreateAttribute(this: v2, pAttributeName: "position", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: v5, value: &position);
    }
    v6 = CDmElement::FindAttribute(this: v2, pAttributeName: "orientation");
    if ( v6 != nullptr
      || (v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v6, value: &orientation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052AD80
// Name: public: virtual void CDmeTransformOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetInputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  MorphOp::AddAttr(attrs, pAttr: this->m_positionX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationW.m_pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x0052ADE0
// Name: public: virtual void CDmeTransformOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetOutputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    MorphOp::AddAttr(attrs, pAttr: Attribute);
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "orientation");
    MorphOp::AddAttr(attrs, pAttr: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052AEA0
// Name: protected: CDmeTransformOperator::CDmeTransformOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformOperator *__thiscall CDmeTransformOperator::CDmeTransformOperator(
        CDmeTransformOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&CDmeTransformOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeTransformOperator::`vftable'{for `CDmElement'};
  this->m_transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_transform.m_pAttribute = nullptr;
  this->m_positionX = 0;
  this->m_positionY = 0;
  this->m_positionZ = 0;
  this->m_orientationX = 0;
  this->m_orientationY = 0;
  this->m_orientationZ = 0;
  this->m_orientationW = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052AF90
// Name: public: virtual bool CDmeTransformOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformOperator::IsA(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052AFC0
// Name: public: virtual int CDmeTransformOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformOperator::GetInheritanceDepth(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B060
// Name: protected: virtual void CDmeTransformOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::PerformConstruction(CDmeTransformOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
  CDmeTransformOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x0057BA80
// Name: _dynamic_initializer_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformOperator::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4C0
// Name: _dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BAB0
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BAC0
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformOperator_Helper,
           classname: "DmeTransformOperator",
           pFactory: &g_CDmeTransformOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E4D0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformOperator_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062DB10
// Name: protected: void CDmeTransformOperator::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::OnConstruction(CDmeTransformOperator *this)
{
  CDmElement *v2; // ecx
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx
  CDmElement *v5; // ecx
  CDmElement *v6; // ecx
  CDmElement *v7; // ecx
  CDmElement *v8; // ecx
  CDmElement *v9; // ecx

  if ( this != nullptr )
    v2 = &this->CDmElement;
  else
    v2 = nullptr;
  this->m_transform.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v2,
                                     pAttributeName: "transform",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_transform);
  CDmAttribute::SetElementTypeSymbol(this: this->m_transform.m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  if ( this != nullptr )
    v3 = &this->CDmElement;
  else
    v3 = nullptr;
  this->m_positionX.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v3,
                                     pAttributeName: "positionX",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionX);
  if ( this != nullptr )
    v4 = &this->CDmElement;
  else
    v4 = nullptr;
  this->m_positionY.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v4,
                                     pAttributeName: "positionY",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionY);
  if ( this != nullptr )
    v5 = &this->CDmElement;
  else
    v5 = nullptr;
  this->m_positionZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this: v5,
                                     pAttributeName: "positionZ",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_positionZ);
  if ( this != nullptr )
    v6 = &this->CDmElement;
  else
    v6 = nullptr;
  this->m_orientationX.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v6,
                                        pAttributeName: "orientationX",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationX);
  if ( this != nullptr )
    v7 = &this->CDmElement;
  else
    v7 = nullptr;
  this->m_orientationY.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v7,
                                        pAttributeName: "orientationY",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationY);
  if ( this != nullptr )
    v8 = &this->CDmElement;
  else
    v8 = nullptr;
  this->m_orientationZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v8,
                                        pAttributeName: "orientationZ",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationZ);
  if ( this != nullptr )
    v9 = &this->CDmElement;
  else
    v9 = nullptr;
  this->m_orientationW.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this: v9,
                                        pAttributeName: "orientationW",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_orientationW);
}

//------------------------------------------------------------------------------
// Address: 0x0062DC20
// Name: public: virtual void CDmeTransformOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::Operate(CDmeTransformOperator *this)
{
  CDmElement *v2; // edi
  CDmAttribute *Attribute; // eax
  CDmaVar<Vector> *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  Quaternion orientation; // [esp+8h] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-Ch] BYREF

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  if ( v2 != nullptr )
  {
    if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
      `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( Attribute != nullptr )
      v4 = CDmAttribute::GetValue<Vector>(this: Attribute);
    else
      v4 = &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
    position = v4->m_Storage;
    orientation = CDmElement::GetValue<Quaternion>(this: v2, pAttributeName: "orientation")->m_Storage;
    position.x = this->m_positionX.m_Storage;
    position.y = this->m_positionY.m_Storage;
    position.z = this->m_positionZ.m_Storage;
    orientation.x = this->m_orientationX.m_Storage;
    orientation.y = this->m_orientationY.m_Storage;
    orientation.z = this->m_orientationZ.m_Storage;
    orientation.w = this->m_orientationW.m_Storage;
    v5 = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    if ( v5 != nullptr
      || (v5 = CDmElement::CreateAttribute(this: v2, pAttributeName: "position", type: AT_VECTOR3)) != nullptr )
    {
      CDmAttribute::SetValue<Vector>(this: v5, value: &position);
    }
    v6 = CDmElement::FindAttribute(this: v2, pAttributeName: "orientation");
    if ( v6 != nullptr
      || (v6 = CDmElement::CreateAttribute(this: v2, pAttributeName: "orientation", type: AT_QUATERNION)) != nullptr )
    {
      CDmAttribute::SetValue<Quaternion>(this: v6, value: &orientation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062DD80
// Name: public: virtual void CDmeTransformOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetInputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  MorphOp::AddAttr(attrs, pAttr: this->m_positionX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_positionZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationX.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationY.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationZ.m_pAttribute);
  MorphOp::AddAttr(attrs, pAttr: this->m_orientationW.m_pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x0062DDE0
// Name: public: virtual void CDmeTransformOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::GetOutputAttributes(
        CDmeTransformOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_transform.m_Storage.m_Handle);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: v2, pAttributeName: "position");
    MorphOp::AddAttr(attrs, pAttr: Attribute);
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "orientation");
    MorphOp::AddAttr(attrs, pAttr: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062DEA0
// Name: protected: CDmeTransformOperator::CDmeTransformOperator(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformOperator *__thiscall CDmeTransformOperator::CDmeTransformOperator(
        CDmeTransformOperator *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&IDmeOperator::`vftable';
  CDmElement::CDmElement(this: &this->CDmElement, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->CDmeOperator::IDmeOperator::__vftable = (CDmeTransformOperator_vtbl *)&CDmeTransformOperator::`vftable'{for `IDmeOperator'};
  this->CDmeOperator::CDmElement::__vftable = (CDmElement_vtbl *)&CDmeTransformOperator::`vftable'{for `CDmElement'};
  this->m_transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_transform.m_pAttribute = nullptr;
  this->m_positionX = 0;
  this->m_positionY = 0;
  this->m_positionZ = 0;
  this->m_orientationX = 0;
  this->m_orientationY = 0;
  this->m_orientationZ = 0;
  this->m_orientationW = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062DF90
// Name: public: virtual bool CDmeTransformOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformOperator::IsA(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062DFC0
// Name: public: virtual int CDmeTransformOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformOperator::GetInheritanceDepth(CDmeTransformOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062E070
// Name: protected: virtual void CDmeTransformOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformOperator::PerformConstruction(CDmeTransformOperator *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
  CDmeTransformOperator::OnConstruction(this: (CDmeTransformOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x006B99F0
// Name: _dynamic_initializer_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformOperator::s_Allocator,
    blockSize: 0x90u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD2E0
// Name: _dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9A20
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9A30
// Name: _dynamic_initializer_for__g_CDmeTransformOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformOperator_Helper,
           classname: "DmeTransformOperator",
           pFactory: &g_CDmeTransformOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD2F0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTransformOperator_Factory.m_CallBackList);
}

} // namespace vmap
