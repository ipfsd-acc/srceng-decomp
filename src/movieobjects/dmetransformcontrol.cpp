// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmetransformcontrol.cpp
// Functions: 18
// ============================================================

#include "movieobjects\dmetransformcontrol.h"

//------------------------------------------------------------------------------
// Address: 0x0055AE50
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformOperator *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x0055F800
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x0055F860
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x0055F8B0
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x0055F900
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x0055F950
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0055FA20
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0055FA40
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x0055FA50
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x0055FAF0
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055FB20
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055FB60
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0055FC30
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AE680
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B08D0
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AE6B0
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE6C0
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B08E0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004F8FF0
// Name: public: class Vector const __near & CDmeTransformControl::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransformControl::GetPosition(CDmeTransformControl *this)
{
  return &this->m_PositionValue;
}

//------------------------------------------------------------------------------
// Address: 0x005B1F80
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformOperator *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x005BBC40
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x005BBCA0
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005BBCF0
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005BBD40
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x005BBD90
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetOrientationAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransformControl::GetOrientationAttr(CDmeTransformControl *this)
{
  return this->m_OrientationValue.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005BBDA0
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005BBE70
// Name: public: class Quaternion const __near & CDmeTransformControl::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransformControl::GetOrientation(CDmeTransformControl *this)
{
  return &this->m_OrientationValue;
}

//------------------------------------------------------------------------------
// Address: 0x005BBE80
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetPositionChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetPositionChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_PositionChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005BBEA0
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005BBEC0
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x005BBED0
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x005BBEE0
// Name: public: class CDmeTransform __near * CDmeTransformControl::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__thiscall CDmeTransformControl::GetTransform(CDmeTransformControl *this)
{
  CDmElement *v2; // eax
  CDmeChannel *v3; // ecx
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  DmElementHandle_t *v6; // esi
  CDmeDag *v8; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_PositionChannel.m_Storage.m_Handle);
  if ( v2 == nullptr || (v3 = (CDmeChannel *)((char *)&v2[-1] + 64), v2 == (CDmElement *)4) )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
    if ( v4 == nullptr )
      return nullptr;
    v3 = (CDmeChannel *)((char *)&v4[-1] + 64);
    if ( v4 == (CDmElement *)4 )
      return nullptr;
  }
  v5 = CDmeChannel::GetToElement(this: v3);
  v6 = (DmElementHandle_t *)v5;
  if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransform::m_classType) )
    return v6;
  if ( v6 != nullptr
    && (*(unsigned __int8 (__thiscall **)(DmElementHandle_t *, CUtlSymbolLarge::<unnamed_type_u>))(*v6 + 16))(
         a1: v6,
         a2: CDmeConstraintSlave::m_classType.u) != 0
    && (v8 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v6 + 17))) != nullptr )
  {
    return (DmElementHandle_t *)CDmeDag::GetTransform(this: v8);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BBF90
// Name: public: class CDmeDag __near * CDmeTransformControl::GetDag(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeTransformControl::GetDag(CDmeTransformControl *this)
{
  DmElementHandle_t *Transform; // eax

  Transform = CDmeTransformControl::GetTransform(this);
  if ( Transform != nullptr )
    return CDmeTransform::GetDag(this: (CDmeTransform *)Transform);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005BBFB0
// Name: public: class Vector const __near & CDmeTransformControl::GetDefaultPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransformControl::GetDefaultPosition(CDmeTransformControl *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultPosition");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return (CDmaVar<Vector> *)&vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x005BBFD0
// Name: public: class Quaternion const __near & CDmeTransformControl::GetDefaultOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall CDmeTransformControl::GetDefaultOrientation(CDmeTransformControl *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultOrientation");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    return &quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005BC080
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BC0B0
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BC0F0
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005BC1C0
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063A900
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetPositionAttr(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDmeTransformControl::GetPositionAttr(vgui::BuildGroup *this)
{
  return this->m_pResourceName;
}

//------------------------------------------------------------------------------
// Address: 0x00680040
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682E80
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004F9000
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00680070
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680080
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682E90
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10329270
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetPositionAttr(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDmeTransformControl::GetPositionAttr(vgui::BuildGroup *this)
{
  return this->m_pResourceName;
}

//------------------------------------------------------------------------------
// Address: 0x104EA7C0
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x104EA820
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x104EA870
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x104EA8C0
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x104EA910
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetOrientationAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransformControl::GetOrientationAttr(CDmeTransformControl *this)
{
  return this->m_OrientationValue.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x104EA920
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x104EA9F0
// Name: public: class Vector const __near & CDmeTransformControl::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransformControl::GetPosition(CDmeTransformControl *this)
{
  return &this->m_PositionValue;
}

//------------------------------------------------------------------------------
// Address: 0x104EAA00
// Name: public: class Quaternion const __near & CDmeTransformControl::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransformControl::GetOrientation(CDmeTransformControl *this)
{
  return &this->m_OrientationValue;
}

//------------------------------------------------------------------------------
// Address: 0x104EAA10
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetPositionChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetPositionChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_PositionChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104EAA30
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104EAA50
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x104EAA60
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x104EAA70
// Name: public: class CDmeTransform __near * CDmeTransformControl::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__thiscall CDmeTransformControl::GetTransform(CDmeTransformControl *this)
{
  CDmElement *v2; // eax
  CDmeChannel *v3; // ecx
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  DmElementHandle_t *v6; // esi
  CDmeDag *v8; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_PositionChannel.m_Storage.m_Handle);
  if ( v2 == nullptr || (v3 = (CDmeChannel *)((char *)&v2[-1] + 64), v2 == (CDmElement *)4) )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
    if ( v4 == nullptr )
      return nullptr;
    v3 = (CDmeChannel *)((char *)&v4[-1] + 64);
    if ( v4 == (CDmElement *)4 )
      return nullptr;
  }
  v5 = CDmeChannel::GetToElement(this: v3);
  v6 = (DmElementHandle_t *)v5;
  if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransform::m_classType) )
    return v6;
  if ( v6 != nullptr
    && (*(unsigned __int8 (__thiscall **)(DmElementHandle_t *, CUtlSymbolLarge::<unnamed_type_u>))(*v6 + 16))(
         a1: v6,
         a2: CDmeConstraintSlave::m_classType.u) != 0
    && (v8 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v6 + 17))) != nullptr )
  {
    return (DmElementHandle_t *)CDmeDag::GetTransform(this: v8);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104EAB20
// Name: public: class CDmeDag __near * CDmeTransformControl::GetDag(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeTransformControl::GetDag(CDmeTransformControl *this)
{
  DmElementHandle_t *Transform; // eax

  Transform = CDmeTransformControl::GetTransform(this);
  if ( Transform != nullptr )
    return CDmeTransform::GetDag(this: (CDmeTransform *)Transform);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104EAB40
// Name: public: class Vector const __near & CDmeTransformControl::GetDefaultPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransformControl::GetDefaultPosition(CDmeTransformControl *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultPosition");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return (CDmaVar<Vector> *)&vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x104EAB60
// Name: public: class Quaternion const __near & CDmeTransformControl::GetDefaultOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall CDmeTransformControl::GetDefaultOrientation(CDmeTransformControl *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultOrientation");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    return &quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x104EAC10
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104EAC40
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104EAC80
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  operator delete(p: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x104EACA0
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformControl *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x104EAD60
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C7C50
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 0x90u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD190
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C7C80
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7C90
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD1A0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x005650E0
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x00565140
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x00565190
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005651E0
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x00565230
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00565300
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != 0 )
    return (CDmeChannel *)(v1 - 4);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00565320
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x00565330
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x005653D0
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565400
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565440
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00565460
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformControl *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x00565520
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059CFF0
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F7E0
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D020
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D030
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F7F0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005AE190
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x005AE1F0
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005AE240
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005AE290
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x005AE2E0
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005AE3B0
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != 0 )
    return (CDmeChannel *)(v1 - 4);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005AE3D0
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x005AE3E0
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x005AE480
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE4B0
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE4F0
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005AE510
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformControl *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x005AE5D0
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F1C80
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4AF0
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F1CB0
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1CC0
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B00
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051C6D0
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformOperator *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x00523EB0
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x00523F10
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x00523F60
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x00523FB0
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x00524000
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005240D0
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005240F0
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x00524100
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x005241A0
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005241D0
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524210
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005242E0
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056CC20
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F060
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056CC50
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056CC60
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F070
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00405BF0
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetPositionAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransformControl::GetPositionAttr(CDmeTransformControl *this)
{
  return this->m_PositionValue.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005228F0
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformOperator *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x0052B200
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x0052B260
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x0052B2B0
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x0052B300
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x0052B350
// Name: public: bool CDmeTransformControl::HasDefaultPosition(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::HasDefaultPosition(CDmeTransformControl *this)
{
  return CDmElement::HasAttribute(this, pAttributeName: "defaultPosition", type: AT_VECTOR3);
}

//------------------------------------------------------------------------------
// Address: 0x0052B360
// Name: public: bool CDmeTransformControl::HasDefaultOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::HasDefaultOrientation(CDmeTransformControl *this)
{
  return CDmElement::HasAttribute(this, pAttributeName: "defaultOrientation", type: AT_QUATERNION);
}

//------------------------------------------------------------------------------
// Address: 0x0052B370
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetOrientationAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransformControl::GetOrientationAttr(CDmeTransformControl *this)
{
  return this->m_OrientationValue.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0052B380
// Name: public: void CDmeTransformControl::SetDefaultPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetDefaultPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultPosition");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: "defaultPosition", type: AT_VECTOR3)) != nullptr )
  {
    CDmAttribute::SetValue<Vector>(this: Attribute, value: position);
    if ( Attribute != nullptr )
      Attribute->m_nFlags |= 0x40u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052B3D0
// Name: public: void CDmeTransformControl::SetDefaultOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetDefaultOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultOrientation");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: "defaultOrientation", type: AT_QUATERNION)) != nullptr )
  {
    CDmAttribute::SetValue<Quaternion>(this: Attribute, value: orientation);
    if ( Attribute != nullptr )
      Attribute->m_nFlags |= 0x40u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052B420
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0052B4F0
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0052B510
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x0052B520
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x0052B530
// Name: public: void CDmeTransformControl::SetPositionChannel(class CDmeChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPositionChannel(CDmeTransformControl *this, int pChannel)
{
  CDmeChannel *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pChannel != 0 )
  {
    v3 = (CDmeChannel *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(pChannel + 4));
    m_pAttribute = this->m_PositionChannel.m_pAttribute;
    pChannel = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_PositionChannel.m_pAttribute;
    pChannel = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pChannel);
}

//------------------------------------------------------------------------------
// Address: 0x0052B580
// Name: public: void CDmeTransformControl::SetOrientationChannel(class CDmeChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientationChannel(CDmeTransformControl *this, int pChannel)
{
  CDmeChannel *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pChannel != 0 )
  {
    v3 = (CDmeChannel *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(pChannel + 4));
    m_pAttribute = this->m_OrientationChannel.m_pAttribute;
    pChannel = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_OrientationChannel.m_pAttribute;
    pChannel = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pChannel);
}

//------------------------------------------------------------------------------
// Address: 0x0052B5D0
// Name: public: class CDmeTransform __near * CDmeTransformControl::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__thiscall CDmeTransformControl::GetTransform(CDmeTransformControl *this)
{
  CDmElement *v2; // eax
  CDmeChannel *v3; // ecx
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  DmElementHandle_t *v6; // esi
  CDmeDag *v8; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_PositionChannel.m_Storage.m_Handle);
  if ( v2 == nullptr || (v3 = (CDmeChannel *)((char *)&v2[-1] + 64), v2 == (CDmElement *)4) )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
    if ( v4 == nullptr )
      return nullptr;
    v3 = (CDmeChannel *)((char *)&v4[-1] + 64);
    if ( v4 == (CDmElement *)4 )
      return nullptr;
  }
  v5 = CDmeChannel::GetToElement(this: v3);
  v6 = (DmElementHandle_t *)v5;
  if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransform::m_classType) )
    return v6;
  if ( v6 != nullptr
    && (*(unsigned __int8 (__thiscall **)(DmElementHandle_t *, CUtlSymbolLarge::<unnamed_type_u>))(*v6 + 16))(
         a1: v6,
         a2: CDmeConstraintSlave::m_classType.u) != 0
    && (v8 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v6 + 17))) != nullptr )
  {
    return (DmElementHandle_t *)CDmeDag::GetTransform(this: v8);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052B710
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B740
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B780
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(
        CDmeTransformControl *this,
        void *(__cdecl **a2)(const char *, int *),
        int a3)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction(pFactoryList: a2, nFactoryCount: a3);
}

//------------------------------------------------------------------------------
// Address: 0x0052B850
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0057CD40
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F190
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD70
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD80
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F1A0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DF800
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformOperator *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x005E4280
// Name: public: class Vector const __near & CDmeTransformControl::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransformControl::GetPosition(CDmeTransformControl *this)
{
  return &this->m_PositionValue;
}

//------------------------------------------------------------------------------
// Address: 0x005E9440
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x005E94A0
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005E94F0
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005E9540
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x005E9590
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetPositionAttr(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDmeTransformControl::GetPositionAttr(vgui::BuildGroup *this)
{
  return this->m_pResourceName;
}

//------------------------------------------------------------------------------
// Address: 0x005E95A0
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetOrientationAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransformControl::GetOrientationAttr(CDmeTransformControl *this)
{
  return this->m_OrientationValue.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x005E95B0
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E9680
// Name: public: class Quaternion const __near & CDmeTransformControl::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransformControl::GetOrientation(CDmeTransformControl *this)
{
  return &this->m_OrientationValue;
}

//------------------------------------------------------------------------------
// Address: 0x005E9690
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetPositionChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetPositionChannel(CDmeTransformControl *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_PositionChannel.m_Storage.m_Handle);
  if ( v1 != 0 )
    return (CDmeChannel *)(v1 - 4);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005E96B0
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != 0 )
    return (CDmeChannel *)(v1 - 4);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005E96D0
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x005E96E0
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x005E96F0
// Name: public: class CDmeTransform __near * CDmeTransformControl::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformControl::GetTransform(CDmeTransformControl *this)
{
  int v2; // eax
  CDmeChannel *v3; // ecx
  int v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmeDag *v8; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_PositionChannel.m_Storage.m_Handle);
  if ( v2 == 0 || (v3 = (CDmeChannel *)(v2 - 4), v2 == 4) )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_OrientationChannel.m_Storage.m_Handle);
    if ( v4 == 0 )
      return nullptr;
    v3 = (CDmeChannel *)(v4 - 4);
    if ( v4 == 4 )
      return nullptr;
  }
  v5 = CDmeChannel::GetToElement(this: v3);
  v6 = v5;
  if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v6;
  if ( v6 != nullptr
    && v6->IsA(this: v6, a2: CDmeConstraintSlave::m_classType)
    && (v8 = (CDmeDag *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement_vtbl *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: v6[1].__vftable)) != nullptr )
  {
    return CDmeDag::GetTransform(this: v8);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E97A0
// Name: public: class CDmeDag __near * CDmeTransformControl::GetDag(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeTransformControl::GetDag(CDmeTransformControl *this)
{
  CDmeTransform *Transform; // eax

  Transform = CDmeTransformControl::GetTransform(this);
  if ( Transform != nullptr )
    return CDmeTransform::GetDag(this: Transform);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005E97C0
// Name: public: class Vector const __near & CDmeTransformControl::GetDefaultPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransformControl::GetDefaultPosition(CDmeTransformControl *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultPosition");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return (CDmaVar<Vector> *)&vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x005E97E0
// Name: public: class Quaternion const __near & CDmeTransformControl::GetDefaultOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall CDmeTransformControl::GetDefaultOrientation(CDmeTransformControl *this)
{
  CDmAttribute *Attribute; // eax

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultOrientation");
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    return &quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005E9890
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E98C0
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9900
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005E99D0
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B1E90
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5980
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1EC0
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1ED0
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5990
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00523B00
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformOperator *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x0052C350
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x0052C3B0
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x0052C400
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x0052C450
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x0052C4A0
// Name: public: bool CDmeTransformControl::HasDefaultPosition(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::HasDefaultPosition(CDmeTransformControl *this)
{
  return CDmElement::HasAttribute(this, pAttributeName: "defaultPosition", type: AT_VECTOR3);
}

//------------------------------------------------------------------------------
// Address: 0x0052C4B0
// Name: public: bool CDmeTransformControl::HasDefaultOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::HasDefaultOrientation(CDmeTransformControl *this)
{
  return CDmElement::HasAttribute(this, pAttributeName: "defaultOrientation", type: AT_QUATERNION);
}

//------------------------------------------------------------------------------
// Address: 0x0052C4C0
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetPositionAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransformControl::GetPositionAttr(CDmeTransformControl *this)
{
  return this->m_PositionValue.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0052C4D0
// Name: public: class CDmAttribute __near * CDmeTransformControl::GetOrientationAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransformControl::GetOrientationAttr(CDmeTransformControl *this)
{
  return this->m_OrientationValue.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0052C4E0
// Name: public: void CDmeTransformControl::SetDefaultPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetDefaultPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultPosition");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: "defaultPosition", type: AT_VECTOR3)) != nullptr )
  {
    CDmAttribute::SetValue<Vector>(this: Attribute, value: position);
    if ( Attribute != nullptr )
      Attribute->m_nFlags |= 0x40u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C530
// Name: public: void CDmeTransformControl::SetDefaultOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetDefaultOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName: "defaultOrientation");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this, pAttributeName: "defaultOrientation", type: AT_QUATERNION)) != nullptr )
  {
    CDmAttribute::SetValue<Quaternion>(this: Attribute, value: orientation);
    if ( Attribute != nullptr )
      Attribute->m_nFlags |= 0x40u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C580
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0052C650
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0052C670
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x0052C680
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x0052C690
// Name: public: void CDmeTransformControl::SetPositionChannel(class CDmeChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPositionChannel(CDmeTransformControl *this, int pChannel)
{
  CDmeChannel *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pChannel != 0 )
  {
    v3 = (CDmeChannel *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(pChannel + 4));
    m_pAttribute = this->m_PositionChannel.m_pAttribute;
    pChannel = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_PositionChannel.m_pAttribute;
    pChannel = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&pChannel);
}

//------------------------------------------------------------------------------
// Address: 0x0052C6E0
// Name: public: void CDmeTransformControl::SetOrientationChannel(class CDmeChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientationChannel(CDmeTransformControl *this, int pChannel)
{
  CDmeChannel *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pChannel != 0 )
  {
    v3 = (CDmeChannel *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)(pChannel + 4));
    m_pAttribute = this->m_OrientationChannel.m_pAttribute;
    pChannel = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_OrientationChannel.m_pAttribute;
    pChannel = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&pChannel);
}

//------------------------------------------------------------------------------
// Address: 0x0052C730
// Name: public: class CDmeTransform __near * CDmeTransformControl::GetTransform(void)const
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__thiscall CDmeTransformControl::GetTransform(CDmeTransformControl *this)
{
  CDmElement *v2; // eax
  CDmeChannel *v3; // ecx
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  DmElementHandle_t *v6; // esi
  CDmeDag *v8; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_PositionChannel.m_Storage.m_Handle);
  if ( v2 == nullptr || (v3 = (CDmeChannel *)((char *)&v2[-1] + 64), v2 == (CDmElement *)4) )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
    if ( v4 == nullptr )
      return nullptr;
    v3 = (CDmeChannel *)((char *)&v4[-1] + 64);
    if ( v4 == (CDmElement *)4 )
      return nullptr;
  }
  v5 = CDmeChannel::GetToElement(this: v3);
  v6 = (DmElementHandle_t *)v5;
  if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransform::m_classType) )
    return v6;
  if ( v6 != nullptr
    && (*(unsigned __int8 (__thiscall **)(DmElementHandle_t *, CUtlSymbolLarge::<unnamed_type_u>))(*v6 + 16))(
         a1: v6,
         a2: CDmeConstraintSlave::m_classType.u) != 0
    && (v8 = (CDmeDag *)g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)v6 + 17))) != nullptr )
  {
    return (DmElementHandle_t *)CDmeDag::GetTransform(this: v8);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C870
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C8A0
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C8E0
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0052C9B0
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED10
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581170
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED40
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED50
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00581180
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A70E0
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x005A7140
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005A7190
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005A71E0
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x005A7230
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005A7300
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != 0 )
    return (CDmeChannel *)(v1 - 4);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005A7320
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x005A7330
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x005A73D0
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7400
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7440
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005A7460
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformControl *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x005A7520
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EAB30
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED990
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EAB60
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAB70
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9A0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x005327D0
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x00532830
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x00532880
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x005328D0
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x00532920
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005329F0
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00532A10
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x00532A20
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x00532AC0
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532AF0
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532B30
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00532B50
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformOperator *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x00532C10
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057C560
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 144,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E860
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C590
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C5A0
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E870
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062E010
// Name: protected: virtual int CDmeTransformControl::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::AllocatedSize(CDmeTransformOperator *this)
{
  return 144;
}

//------------------------------------------------------------------------------
// Address: 0x006358F0
// Name: public: void CDmeTransformControl::GetManipulationTransform(struct matrix3x4_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationTransform(CDmeTransformControl *this, matrix3x4_t *transform)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *transform = m_pManipulationParams->Transform;
  else
    SetIdentityMatrix(matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x00635950
// Name: public: void CDmeTransformControl::GetManipulationRotationLocal(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationLocal(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationLocal;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x006359A0
// Name: public: void CDmeTransformControl::GetManipulationRotationParent(class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationRotationParent(CDmeTransformControl *this, Quaternion *rotation)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *rotation = m_pManipulationParams->RotationParent;
  else
    *rotation = quat_identity;
}

//------------------------------------------------------------------------------
// Address: 0x006359F0
// Name: public: void CDmeTransformControl::GetManipulationPivot(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::GetManipulationPivot(CDmeTransformControl *this, Vector *pivotPosition)
{
  CDmeTransformControl::ManipulationParams_t *m_pManipulationParams; // eax

  m_pManipulationParams = this->m_pManipulationParams;
  if ( m_pManipulationParams != nullptr )
    *pivotPosition = m_pManipulationParams->Pivot;
  else
    *pivotPosition = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x00635A40
// Name: protected: void CDmeTransformControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::OnConstruction(CDmeTransformControl *this)
{
  CDmaVar<Vector> *p_m_PositionValue; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_PositionValue = &this->m_PositionValue;
  this->m_PivotOffset.x = vec3_origin.x;
  this->m_PivotOffset.y = vec3_origin.y;
  *(_QWORD *)&this->m_PivotOffset.z = LODWORD(vec3_origin.z);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valuePosition",
         type: AT_VECTOR3,
         pMemory: &this->m_PositionValue);
  p_m_PositionValue->m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vec3_origin);
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "valueOrientation",
         type: AT_QUATERNION,
         pMemory: &this->m_OrientationValue);
  this->m_OrientationValue.m_pAttribute = v4;
  CDmAttribute::SetValue<Quaternion>(this: v4, value: &quat_identity);
  this->m_PositionChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "positionChannel",
                                           type: AT_FIRST_VALUE_TYPE,
                                           pMemory: &this->m_PositionChannel);
  CDmAttribute::SetElementTypeSymbol(this: this->m_PositionChannel.m_pAttribute, typeSymbol: CDmeChannel::m_classType);
  this->m_OrientationChannel.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "orientationChannel",
                                              type: AT_FIRST_VALUE_TYPE,
                                              pMemory: &this->m_OrientationChannel);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_OrientationChannel.m_pAttribute,
    typeSymbol: CDmeChannel::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00635B10
// Name: public: class CDmeChannel __near * CDmeTransformControl::GetOrientationChannel(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmeTransformControl::GetOrientationChannel(CDmeTransformControl *this)
{
  CDmElement *v1; // eax

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_OrientationChannel.m_Storage.m_Handle);
  if ( v1 != nullptr )
    return (CDmeChannel *)((char *)&v1[-1] + 64);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00635B30
// Name: public: void CDmeTransformControl::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetPosition(CDmeTransformControl *this, const Vector *position)
{
  CDmAttribute::SetValue<Vector>(this: this->m_PositionValue.m_pAttribute, value: position);
}

//------------------------------------------------------------------------------
// Address: 0x00635B40
// Name: public: void CDmeTransformControl::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::SetOrientation(CDmeTransformControl *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_OrientationValue.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x00635BE0
// Name: public: virtual bool CDmeTransformControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransformControl::IsA(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00635C10
// Name: public: virtual int CDmeTransformControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransformControl::GetInheritanceDepth(CDmeTransformControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransformControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00635C50
// Name: protected: virtual void CDmeTransformControl::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformDestruction(CDmeTransformControl *this)
{
  free(pMem: this->m_pManipulationParams);
  this->m_pManipulationParams = nullptr;
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00635D20
// Name: protected: virtual void CDmeTransformControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransformControl::PerformConstruction(CDmeTransformControl *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTransformControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006BA4D0
// Name: _dynamic_initializer_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformControl::s_Allocator,
    blockSize: 0x90u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD680
// Name: _dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BA500
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA510
// Name: _dynamic_initializer_for__g_CDmeTransformControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformControl_Helper,
           classname: "DmeTransformControl",
           pFactory: &g_CDmeTransformControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD690
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformControl_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTransformControl_Factory.m_CallBackList);
}

} // namespace vmap
