// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmedrawsettings.cpp
// Functions: 22
// ============================================================

#include "movieobjects\dmedrawsettings.h"

//------------------------------------------------------------------------------
// Address: 0x00556380
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00556490
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005564C0
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00556500
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x005566F0
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x005567C0
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x005569B0
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AD6E0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD740
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD760
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD780
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD7A0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD7C0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0380
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0390
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005B03A0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005B03B0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005B03C0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005B03D0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x005AD710
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD720
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B03E0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005AC4A0
// Name: public: void CDmeDrawSettings::BindWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindWireframe(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bWireframeMaterialInitialized )
  {
    CDmeDrawSettings::s_bWireframeMaterialInitialized = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$decal", value: 0);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_WireframeMaterial,
      pMaterialName: "__DmeWireframe",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_WireframeMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005AC560
// Name: public: void CDmeDrawSettings::BindWireframeOnShaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindWireframeOnShaded(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bWireframeOnShadedMaterialInitialized )
  {
    CDmeDrawSettings::s_bWireframeOnShadedMaterialInitialized = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$decal", value: 0);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
      pMaterialName: "__DmeWireframeOnShaded",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_WireframeOnShadedMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005AC620
// Name: public: void CDmeDrawSettings::BindGray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindGray(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bFlatGrayMaterial )
  {
    CDmeDrawSettings::s_bFlatGrayMaterial = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "VertexLitGeneric");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$model", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_FlatGrayMaterial,
      pMaterialName: "__DmeFlatGray",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_FlatGrayMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005AC6C0
// Name: public: void CDmeDrawSettings::BindUnlitGray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindUnlitGray(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bUnlitGrayMaterial )
  {
    CDmeDrawSettings::s_bUnlitGrayMaterial = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "UnlitGeneric");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$model", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_UnlitGrayMaterial,
      pMaterialName: "__DmeUnlitGray",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_UnlitGrayMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005AD1D0
// Name: public: void CDmeDrawSettings::DrawDag(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeDrawSettings::DrawDag(CDmeDrawSettings *this@<ecx>, int a2@<edi>, CDmeDag *pDag)
{
  CDmeDag *v3; // esi
  int v5; // edi
  bool v6; // zf
  unsigned int m_Storage; // eax
  unsigned int v8; // eax
  void (__thiscall *v9)(int, int); // edx
  int v10; // eax
  int m_Size; // ecx
  CDmeDrawSettings::DrawType_t *m_pMemory; // ecx
  int v13; // edx
  int *v14; // ecx
  CDmAttribute *m_pAttribute; // ecx
  int v16; // ecx
  CDmeDag *v17; // eax
  int v18; // [esp-4h] [ebp-50h]
  VMatrix m; // [esp+8h] [ebp-44h] BYREF
  int value; // [esp+48h] [ebp-4h] BYREF

  v3 = pDag;
  if ( pDag != nullptr )
  {
    this->m_vHighlightPoints.m_Size = 0;
    v5 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    v6 = !this->m_bDeltaHighlight.m_Storage;
    this->m_IsAMaterialBound = false;
    if ( v6 )
    {
      m_Storage = this->m_DrawType.m_Storage;
      if ( m_Storage > 3 || m_Storage < 2 )
      {
        if ( this->m_bGrayShade.m_Storage )
          CDmeDrawSettings::BindGray(this);
      }
      else
      {
        CDmeDrawSettings::BindWireframe(this);
      }
    }
    else
    {
      CDmeDrawSettings::BindUnlitGray(this);
    }
    v3->Draw(this: v3, a2: this);
    v6 = !this->m_bDeltaHighlight.m_Storage;
    this->m_IsAMaterialBound = false;
    if ( !v6 || this->m_bWireframeOnShaded.m_Storage && ((v8 = this->m_DrawType.m_Storage) > 3 || v8 <= 1) )
    {
      (*(void (__thiscall **)(int, int, VMatrix *, int))(*(_DWORD *)v5 + 120))(a1: v5, a2: 1, a3: &m, a4: v18);
      v9 = *(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80);
      m.m[2][2] = m.m[2][2] + 0.00025000001;
      m.m[2][3] = m.m[2][3] + 0.00025000001;
      v9(a1: v5, a2: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 84))(a1: v5);
      (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v5 + 96))(a1: v5, a2: &m);
      CDmeDrawSettings::BindWireframeOnShaded(this);
      v10 = this->m_DrawType.m_Storage <= 3u ? this->m_DrawType.m_Storage : 0;
      m_Size = this->m_drawTypeStack.m_Size;
      value = v10;
      if ( m_Size >= this->m_drawTypeStack.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_drawTypeStack,
          num: 1);
        v10 = value;
      }
      ++this->m_drawTypeStack.m_Size;
      m_pMemory = this->m_drawTypeStack.m_Memory.m_pMemory;
      v13 = this->m_drawTypeStack.m_Size;
      this->m_drawTypeStack.m_pElements = m_pMemory;
      v14 = (int *)&m_pMemory[v13 - 1];
      if ( v14 != nullptr )
        *v14 = v10;
      m_pAttribute = this->m_DrawType.m_pAttribute;
      value = 2;
      CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
      v3->Draw(this: v3, a2: this);
      if ( this->m_drawTypeStack.m_Size != 0 )
      {
        v16 = this->m_drawTypeStack.m_Size;
        v17 = (CDmeDag *)this->m_drawTypeStack.m_Memory.m_pMemory[v16 - 1];
        this->m_drawTypeStack.m_Size = v16 - 1;
        pDag = v17;
        if ( (unsigned int)v17 >= 4 )
          pDag = nullptr;
        CDmAttribute::SetValue<int>(this: this->m_DrawType.m_pAttribute, value: (const int *)&pDag);
      }
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 88))(a1: v5);
    }
    if ( v5 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AD520
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AD630
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD660
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD6A0
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x005AD890
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x005AD960
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (const int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (const float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x005ADB50
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067EED0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EF30
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EF50
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EF70
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EF90
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EFB0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x00682890
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006828A0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006828B0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006828C0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006828D0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006828E0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x0067EF00
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EF10
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006828F0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104DFD10
// Name: public: void CDmeDrawSettings::BindWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindWireframe(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bWireframeMaterialInitialized )
  {
    CDmeDrawSettings::s_bWireframeMaterialInitialized = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$decal", value: 0);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_WireframeMaterial,
      pMaterialName: "__DmeWireframe",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_WireframeMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104DFDD0
// Name: public: void CDmeDrawSettings::BindWireframeOnShaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindWireframeOnShaded(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bWireframeOnShadedMaterialInitialized )
  {
    CDmeDrawSettings::s_bWireframeOnShadedMaterialInitialized = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$decal", value: 0);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
      pMaterialName: "__DmeWireframeOnShaded",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_WireframeOnShadedMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104DFE90
// Name: public: void CDmeDrawSettings::BindGray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindGray(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bFlatGrayMaterial )
  {
    CDmeDrawSettings::s_bFlatGrayMaterial = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "VertexLitGeneric");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$model", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_FlatGrayMaterial,
      pMaterialName: "__DmeFlatGray",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_FlatGrayMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104DFF30
// Name: public: void CDmeDrawSettings::BindUnlitGray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindUnlitGray(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bUnlitGrayMaterial )
  {
    CDmeDrawSettings::s_bUnlitGrayMaterial = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "UnlitGeneric");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$model", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_UnlitGrayMaterial,
      pMaterialName: "__DmeUnlitGray",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_UnlitGrayMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104E0A50
// Name: public: void CDmeDrawSettings::DrawDag(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeDrawSettings::DrawDag(CDmeDrawSettings *this@<ecx>, int a2@<edi>, CDmeDag *pDag)
{
  CDmeDag *v3; // esi
  int v5; // edi
  bool v6; // zf
  unsigned int m_Storage; // eax
  unsigned int v8; // eax
  void (__thiscall *v9)(int, int); // edx
  int v10; // eax
  int m_Size; // ecx
  CDmeDrawSettings::DrawType_t *m_pMemory; // ecx
  int v13; // edx
  int *v14; // ecx
  CDmAttribute *m_pAttribute; // ecx
  int v16; // ecx
  CDmeDag *v17; // eax
  int v18; // [esp-4h] [ebp-50h]
  VMatrix m; // [esp+8h] [ebp-44h] BYREF
  int value; // [esp+48h] [ebp-4h] BYREF

  v3 = pDag;
  if ( pDag != nullptr )
  {
    this->m_vHighlightPoints.m_Size = 0;
    v5 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    v6 = !this->m_bDeltaHighlight.m_Storage;
    this->m_IsAMaterialBound = false;
    if ( v6 )
    {
      m_Storage = this->m_DrawType.m_Storage;
      if ( m_Storage > 3 || m_Storage < 2 )
      {
        if ( this->m_bGrayShade.m_Storage )
          CDmeDrawSettings::BindGray(this);
      }
      else
      {
        CDmeDrawSettings::BindWireframe(this);
      }
    }
    else
    {
      CDmeDrawSettings::BindUnlitGray(this);
    }
    v3->Draw(this: v3, a2: this);
    v6 = !this->m_bDeltaHighlight.m_Storage;
    this->m_IsAMaterialBound = false;
    if ( !v6 || this->m_bWireframeOnShaded.m_Storage && ((v8 = this->m_DrawType.m_Storage) > 3 || v8 <= 1) )
    {
      (*(void (__thiscall **)(int, int, VMatrix *, int))(*(_DWORD *)v5 + 120))(a1: v5, a2: 1, a3: &m, a4: v18);
      v9 = *(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80);
      m.m[2][2] = m.m[2][2] + 0.00025000001;
      m.m[2][3] = m.m[2][3] + 0.00025000001;
      v9(a1: v5, a2: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 84))(a1: v5);
      (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v5 + 96))(a1: v5, a2: &m);
      CDmeDrawSettings::BindWireframeOnShaded(this);
      v10 = this->m_DrawType.m_Storage <= 3u ? this->m_DrawType.m_Storage : 0;
      m_Size = this->m_drawTypeStack.m_Size;
      value = v10;
      if ( m_Size >= this->m_drawTypeStack.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_drawTypeStack,
          num: 1);
        v10 = value;
      }
      ++this->m_drawTypeStack.m_Size;
      m_pMemory = this->m_drawTypeStack.m_Memory.m_pMemory;
      v13 = this->m_drawTypeStack.m_Size;
      this->m_drawTypeStack.m_pElements = m_pMemory;
      v14 = (int *)&m_pMemory[v13 - 1];
      if ( v14 != nullptr )
        *v14 = v10;
      m_pAttribute = this->m_DrawType.m_pAttribute;
      value = 2;
      CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
      v3->Draw(this: v3, a2: this);
      if ( this->m_drawTypeStack.m_Size != 0 )
      {
        v16 = this->m_drawTypeStack.m_Size;
        v17 = (CDmeDag *)this->m_drawTypeStack.m_Memory.m_pMemory[v16 - 1];
        this->m_drawTypeStack.m_Size = v16 - 1;
        pDag = v17;
        if ( (unsigned int)v17 >= 4 )
          pDag = nullptr;
        CDmAttribute::SetValue<int>(this: this->m_DrawType.m_pAttribute, value: (int *)&pDag);
      }
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 88))(a1: v5);
    }
    if ( v5 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104E0DA0
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104E0EB0
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104E0EE0
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104E0F20
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x104E1110
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x104E11E0
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x104E13D0
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C78E0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 0xE4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7940
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7960
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7980
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x105C79A0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x105C79C0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD040
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CD050
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x105CD060
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x105CD070
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x105CD080
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x105CD090
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x105C7910
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7920
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD0A0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0055E110
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0055E220
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055E250
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055E470
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x0055E540
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x0055E730
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056AAF0
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x0059C900
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C960
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C980
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C9A0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C9C0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C9E0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F570
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059F580
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0059F590
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0059F5A0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0059F5B0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0059F5C0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x0059C930
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C940
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F5D0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x00515A30
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x005ABFA0
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AC0B0
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AC0E0
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AC300
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x005AC3D0
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x005AC5C0
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F1950
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F19B0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005F19D0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005F19F0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1A10
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1A30
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x005F49C0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F49D0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005F49E0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005F49F0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A00
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A10
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x005F1980
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1990
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4A20
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00517C20
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00517D30
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00517D60
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00517F80
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x00518050
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x00518240
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005239A0
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x0056BAB0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BB10
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BB30
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BB50
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BB70
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BB90
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EA70
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EA80
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0056EA90
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0056EAA0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0056EAB0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0056EAC0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x0056BAE0
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BAF0
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EAD0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0051D570
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051D680
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D6B0
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D8D0
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x0051D9A0
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (const float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x0051DB90
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0052AD10
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x0057BBC0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC20
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC40
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC60
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC80
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCA0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBA0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBB0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBC0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBD0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBE0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBF0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBF0
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC00
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC00
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D9F00
// Name: public: void CDmeDrawSettings::BindWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindWireframe(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bWireframeMaterialInitialized )
  {
    CDmeDrawSettings::s_bWireframeMaterialInitialized = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$decal", value: 0);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_WireframeMaterial,
      pMaterialName: "__DmeWireframe",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_WireframeMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005D9FC0
// Name: public: void CDmeDrawSettings::BindWireframeOnShaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindWireframeOnShaded(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bWireframeOnShadedMaterialInitialized )
  {
    CDmeDrawSettings::s_bWireframeOnShadedMaterialInitialized = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$decal", value: 0);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
      pMaterialName: "__DmeWireframeOnShaded",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_WireframeOnShadedMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005DA080
// Name: public: void CDmeDrawSettings::BindGray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindGray(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bFlatGrayMaterial )
  {
    CDmeDrawSettings::s_bFlatGrayMaterial = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "VertexLitGeneric");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$model", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_FlatGrayMaterial,
      pMaterialName: "__DmeFlatGray",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_FlatGrayMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005DA120
// Name: public: void CDmeDrawSettings::BindUnlitGray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BindUnlitGray(CDmeDrawSettings *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatRenderContext *v4; // esi

  if ( !CDmeDrawSettings::s_bUnlitGrayMaterial )
  {
    CDmeDrawSettings::s_bUnlitGrayMaterial = true;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "UnlitGeneric");
    else
      v3 = nullptr;
    KeyValues::SetInt(this: v3, keyName: "$model", value: 1);
    KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
    CMaterialReference::Init(
      this: &CDmeDrawSettings::s_UnlitGrayMaterial,
      pMaterialName: "__DmeUnlitGray",
      pVMTKeyValues: v3);
  }
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: CDmeDrawSettings::s_UnlitGrayMaterial.m_pMaterial, a3: nullptr);
  this->m_IsAMaterialBound = true;
  v4->EndRender(this: v4);
  v4->Release(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x005DAC30
// Name: public: void CDmeDrawSettings::DrawDag(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeDrawSettings::DrawDag(CDmeDrawSettings *this@<ecx>, int a2@<edi>, CDmeDag *pDag)
{
  CDmeDag *v3; // esi
  int v5; // edi
  bool v6; // zf
  unsigned int m_Storage; // eax
  unsigned int v8; // eax
  void (__thiscall *v9)(int, int); // edx
  int v10; // eax
  int m_Size; // ecx
  CDmeDrawSettings::DrawType_t *m_pMemory; // ecx
  int v13; // edx
  int *v14; // ecx
  CDmAttribute *m_pAttribute; // ecx
  int v16; // ecx
  CDmeDag *v17; // eax
  int v18; // [esp-4h] [ebp-50h]
  VMatrix m; // [esp+8h] [ebp-44h] BYREF
  int value; // [esp+48h] [ebp-4h] BYREF

  v3 = pDag;
  if ( pDag != nullptr )
  {
    this->m_vHighlightPoints.m_Size = 0;
    v5 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    v6 = !this->m_bDeltaHighlight.m_Storage;
    this->m_IsAMaterialBound = false;
    if ( v6 )
    {
      m_Storage = this->m_DrawType.m_Storage;
      if ( m_Storage > 3 || m_Storage < 2 )
      {
        if ( this->m_bGrayShade.m_Storage )
          CDmeDrawSettings::BindGray(this);
      }
      else
      {
        CDmeDrawSettings::BindWireframe(this);
      }
    }
    else
    {
      CDmeDrawSettings::BindUnlitGray(this);
    }
    v3->Draw(this: v3, a2: this);
    v6 = !this->m_bDeltaHighlight.m_Storage;
    this->m_IsAMaterialBound = false;
    if ( !v6 || this->m_bWireframeOnShaded.m_Storage && ((v8 = this->m_DrawType.m_Storage) > 3 || v8 <= 1) )
    {
      (*(void (__thiscall **)(int, int, VMatrix *, int))(*(_DWORD *)v5 + 120))(a1: v5, a2: 1, a3: &m, a4: v18);
      v9 = *(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80);
      m.m[2][2] = m.m[2][2] + 0.00025000001;
      m.m[2][3] = m.m[2][3] + 0.00025000001;
      v9(a1: v5, a2: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 84))(a1: v5);
      (*(void (__thiscall **)(int, VMatrix *))(*(_DWORD *)v5 + 96))(a1: v5, a2: &m);
      CDmeDrawSettings::BindWireframeOnShaded(this);
      v10 = this->m_DrawType.m_Storage <= 3u ? this->m_DrawType.m_Storage : 0;
      m_Size = this->m_drawTypeStack.m_Size;
      value = v10;
      if ( m_Size >= this->m_drawTypeStack.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_drawTypeStack,
          num: 1);
        v10 = value;
      }
      ++this->m_drawTypeStack.m_Size;
      m_pMemory = this->m_drawTypeStack.m_Memory.m_pMemory;
      v13 = this->m_drawTypeStack.m_Size;
      this->m_drawTypeStack.m_pElements = m_pMemory;
      v14 = (int *)&m_pMemory[v13 - 1];
      if ( v14 != nullptr )
        *v14 = v10;
      m_pAttribute = this->m_DrawType.m_pAttribute;
      value = 2;
      CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
      v3->Draw(this: v3, a2: this);
      if ( this->m_drawTypeStack.m_Size != 0 )
      {
        v16 = this->m_drawTypeStack.m_Size;
        v17 = (CDmeDag *)this->m_drawTypeStack.m_Memory.m_pMemory[v16 - 1];
        this->m_drawTypeStack.m_Size = v16 - 1;
        pDag = v17;
        if ( (unsigned int)v17 >= 4 )
          pDag = nullptr;
        CDmAttribute::SetValue<int>(this: this->m_DrawType.m_pAttribute, value: (const int *)&pDag);
      }
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 80))(a1: v5, a2: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 88))(a1: v5);
    }
    if ( v5 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DAF80
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DB090
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DB0C0
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DB2E0
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x005DB3B0
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (const int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (const float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x005DB5A0
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EF850
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x006B0D70
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0DD0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0DF0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0E10
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0E30
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0E50
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x006B53B0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B53C0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006B53D0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006B53E0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006B53F0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006B5400
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x006B0DA0
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0DB0
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5410
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00485AC0
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x0051E670
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051E780
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E7B0
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E9D0
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x0051EAA0
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (const float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x0051EC90
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057DBA0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC00
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC20
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC40
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC60
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC80
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x00580B80
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580B90
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00580BA0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00580BB0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00580BC0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00580BD0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x0057DBD0
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DBE0
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580BE0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0050E850
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x005A4ED0
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A4FE0
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A5010
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A5230
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = (const CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                  a1: g_pDataModel.u,
                                  a2: v6,
                                  a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x005A5300
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x005A54F0
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EA800
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA860
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA880
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA8A0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA8C0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA8E0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED860
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED870
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005ED880
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005ED890
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8A0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8B0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x005EA830
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA840
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8C0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x005266B0
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005267C0
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005267F0
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00526A10
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x00526AE0
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (const int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (const float *)&value);
  value = (Color)0x1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (const float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x00526CD0
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005322E0
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x0057B450
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 228,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B4B0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B4D0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B4F0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B510
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B530
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E290
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2A0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2B0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2C0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2D0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2E0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x0057B480
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B490
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2F0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x006294E0
// Name: protected: CDmeDrawSettings::CDmeDrawSettings(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeDrawSettings *__thiscall CDmeDrawSettings::CDmeDrawSettings(
        CDmeDrawSettings *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short> *m_pMemory; // edx

  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeDrawSettings_vtbl *)&CDmeDrawSettings::`vftable';
  this->m_DrawType.m_pAttribute = nullptr;
  this->m_DrawType.m_Storage = 0;
  this->m_bBackfaceCulling.m_pAttribute = nullptr;
  this->m_bBackfaceCulling.m_Storage = false;
  this->m_bWireframeOnShaded.m_pAttribute = nullptr;
  this->m_bWireframeOnShaded.m_Storage = false;
  this->m_bXRay.m_pAttribute = nullptr;
  this->m_bXRay.m_Storage = false;
  this->m_bGrayShade.m_pAttribute = nullptr;
  this->m_bGrayShade.m_Storage = false;
  this->m_bNormals.m_pAttribute = nullptr;
  this->m_bNormals.m_Storage = false;
  this->m_NormalLength = 0;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_bDeltaHighlight.m_pAttribute = nullptr;
  this->m_bDeltaHighlight.m_Storage = false;
  this->m_flHighlightSize = 0;
  this->m_cHighlightColor.m_pAttribute = nullptr;
  this->m_cHighlightColor.m_Storage = (Color)-16777216;
  this->m_NotDrawable.m_LessFunc = nullptr;
  this->m_NotDrawable.m_Elements.m_pMemory = nullptr;
  this->m_NotDrawable.m_Elements.m_nAllocationCount = 0;
  this->m_NotDrawable.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_NotDrawable.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_NotDrawable.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_NotDrawable.m_FirstFree = -1;
  this->m_NotDrawable.m_pElements = m_pMemory;
  this->m_drawTypeStack.m_Memory.m_pMemory = nullptr;
  this->m_drawTypeStack.m_Memory.m_nAllocationCount = 0;
  this->m_drawTypeStack.m_Memory.m_nGrowSize = 0;
  this->m_drawTypeStack.m_Size = 0;
  this->m_drawTypeStack.m_pElements = nullptr;
  this->m_vHighlightPoints.m_Memory.m_pMemory = nullptr;
  this->m_vHighlightPoints.m_Memory.m_nAllocationCount = 0;
  this->m_vHighlightPoints.m_Memory.m_nGrowSize = 0;
  this->m_vHighlightPoints.m_Size = 0;
  this->m_vHighlightPoints.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006295F0
// Name: public: virtual bool CDmeDrawSettings::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDrawSettings::IsA(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00629620
// Name: public: virtual int CDmeDrawSettings::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::GetInheritanceDepth(CDmeDrawSettings *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDrawSettings::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00629840
// Name: protected: void CDmeDrawSettings::BuildKnownDrawableTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::BuildKnownDrawableTypes(CDmeDrawSettings *this)
{
  const CUtlSymbolLarge *v2; // eax
  const CUtlSymbolLarge *v3; // eax
  const CUtlSymbolLarge *v4; // eax
  const CUtlSymbolLarge *v5; // eax
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc == nullptr )
    CDmeDrawSettings::s_KnownDrawableTypes.m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &CDmeDrawSettings::s_KnownDrawableTypes);
  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeMesh");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v2);
  v3 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeJoint");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v3);
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeModel");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v4);
  v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v6, a3: "DmeAttachment");
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::InsertIfNotFound(
    this: &CDmeDrawSettings::s_KnownDrawableTypes,
    insert: v5);
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NotDrawable);
}

//------------------------------------------------------------------------------
// Address: 0x00629910
// Name: protected: void CDmeDrawSettings::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::OnConstruction(CDmeDrawSettings *this)
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl*)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short> > *p_m_NotDrawable; // ecx
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h] BYREF

  if ( CDmeDrawSettings::s_KnownDrawableTypes.m_NumElements == 0 )
    CDmeDrawSettings::BuildKnownDrawableTypes(this);
  p_m_NotDrawable = &this->m_NotDrawable;
  if ( this->m_NotDrawable.m_LessFunc == nullptr )
    p_m_NotDrawable->m_LessFunc = (bool (__cdecl *)(const CUtlSymbolLarge *, const CUtlSymbolLarge *))CDefOps<DmeTime_t>::LessFunc;
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::RemoveAll(this: p_m_NotDrawable);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "drawType", type: AT_INT, pMemory: &this->m_DrawType);
  this->m_DrawType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, (int *)&value);
  v15 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "backfaceCulling",
         type: AT_BOOL,
         pMemory: &this->m_bBackfaceCulling);
  this->m_bBackfaceCulling.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v15);
  v15 = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "wireframeOnShaded",
         type: AT_BOOL,
         pMemory: &this->m_bWireframeOnShaded);
  this->m_bWireframeOnShaded.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v15);
  v15 = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "xray", type: AT_BOOL, pMemory: &this->m_bXRay);
  this->m_bXRay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v15);
  v15 = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "grayShade", type: AT_BOOL, pMemory: &this->m_bGrayShade);
  this->m_bGrayShade.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v15);
  v15 = false;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "normals", type: AT_BOOL, pMemory: &this->m_bNormals);
  this->m_bNormals.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v15);
  value = (Color)1065353216;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "normalLength",
         type: AT_FLOAT,
         pMemory: &this->m_NormalLength);
  this->m_NormalLength.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, (float *)&value);
  value = (Color)word_1000000;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v10;
  CDmAttribute::SetValue<Color>(this: v10, &value);
  v15 = false;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightDeltas",
          type: AT_BOOL,
          pMemory: &this->m_bDeltaHighlight);
  this->m_bDeltaHighlight.m_pAttribute = v11;
  CDmAttribute::SetValue<bool>(this: v11, value: &v15);
  value = (Color)1069547520;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightSize",
          type: AT_FLOAT,
          pMemory: &this->m_flHighlightSize);
  this->m_flHighlightSize.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, (float *)&value);
  value = (Color)-7138049;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "highlightColor",
          type: AT_COLOR,
          pMemory: &this->m_cHighlightColor);
  this->m_cHighlightColor.m_pAttribute = v13;
  CDmAttribute::SetValue<Color>(this: v13, &value);
  this->m_IsAMaterialBound = false;
}

//------------------------------------------------------------------------------
// Address: 0x00629B00
// Name: protected: virtual void CDmeDrawSettings::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDrawSettings::PerformConstruction(CDmeDrawSettings *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDrawSettings::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063AB90
// Name: protected: virtual int CDmeDrawSettings::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDrawSettings::AllocatedSize(CDmeRigIKConstraintOperator *this)
{
  return 228;
}

//------------------------------------------------------------------------------
// Address: 0x006B9360
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDrawSettings::s_Allocator,
    blockSize: 0xE4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDrawSettings pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B93C0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x006B93E0
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_WireframeOnShadedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9400
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_FlatGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9420
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::CMaterialReference(
    this: &CDmeDrawSettings::s_UnlitGrayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9440
// Name: _dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD090
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDrawSettings::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD0A0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006BD0B0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_WireframeOnShadedMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_WireframeOnShadedMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006BD0C0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_FlatGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_FlatGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006BD0D0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_UnlitGrayMaterial__()
{
  CMaterialReference::~CMaterialReference(this: &CDmeDrawSettings::s_UnlitGrayMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x006BD0E0
// Name: _dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDrawSettings::s_KnownDrawableTypes__()
{
  CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolLarge,unsigned short,bool (__cdecl *)(CUtlSymbolLarge const &,CUtlSymbolLarge const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolLarge,unsigned short>,unsigned short>>(this: &CDmeDrawSettings::s_KnownDrawableTypes);
}

//------------------------------------------------------------------------------
// Address: 0x006B9390
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDrawSettings_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B93A0
// Name: _dynamic_initializer_for__g_CDmeDrawSettings_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDrawSettings_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDrawSettings_Helper,
           classname: "DmeDrawSettings",
           pFactory: &g_CDmeDrawSettings_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD0F0
// Name: _dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDrawSettings_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeDrawSettings_Factory.m_CallBackList);
}

} // namespace vmap
