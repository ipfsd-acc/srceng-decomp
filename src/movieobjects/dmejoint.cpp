// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmejoint.cpp
// Functions: 13
// ============================================================

#include "movieobjects\dmejoint.h"

//------------------------------------------------------------------------------
// Address: 0x004B2A90
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2B50
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3040
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

//------------------------------------------------------------------------------
// Address: 0x004B30D0
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B3140
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B3170
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B31C0
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B6D90
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x005AC040
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFC40
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AC070
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC080
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFC50
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00503DE0
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00503EA0
// Name: public: static void CDmeJoint::DrawJointHierarchy(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeJoint::DrawJointHierarchy(bool bDrawJoints)
{
  CDmeJoint::sm_bDrawJoints = bDrawJoints;
}

//------------------------------------------------------------------------------
// Address: 0x00503EB0
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005043A0
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

//------------------------------------------------------------------------------
// Address: 0x00504430
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005044A0
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005044D0
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504520
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AC250
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x0067D230
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681F50
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067D260
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D270
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00681F60
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104DA740
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DA800
// Name: public: static void CDmeJoint::DrawJointHierarchy(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeJoint::DrawJointHierarchy(bool bDrawJoints)
{
  CDmeJoint::sm_bDrawJoints = bDrawJoints;
}

//------------------------------------------------------------------------------
// Address: 0x104DA810
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  const Vector *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->x;
        vecChildPosition.z = Position->z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DAD00
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

//------------------------------------------------------------------------------
// Address: 0x104DAD90
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104DAE00
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DAE30
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DAE80
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x1059A450
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x105C7420
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 0x8Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCEE0
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C7450
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7460
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CCEF0
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004B7270
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7330
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7820
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050BE70
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050BF30
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050C420
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0046FD70
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FE30
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470320
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

//------------------------------------------------------------------------------
// Address: 0x004703B0
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00470420
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00470450
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004704A0
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00516E20
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x00569E10
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E130
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00569E40
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569E50
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E140
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00473A80
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473B40
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Bookmarks; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Bookmarks = CDmeBookmarkSet::GetBookmarks(this: Transform);
        v10 = *(_QWORD *)&Bookmarks->m_Storage.x;
        vecChildPosition.z = Bookmarks->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474030
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

//------------------------------------------------------------------------------
// Address: 0x004740C0
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00474130
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474160
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004741B0
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004741E0
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x00579F10
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E260
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579F40
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579F50
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E270
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D4090
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4150
// Name: public: static void CDmeJoint::DrawJointHierarchy(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeJoint::DrawJointHierarchy(bool bDrawJoints)
{
  CDmeJoint::sm_bDrawJoints = bDrawJoints;
}

//------------------------------------------------------------------------------
// Address: 0x005D4160
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4650
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00474800
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004748C0
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  const Vector *Bookmarks; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Bookmarks = CDmeBookmarkSet::GetBookmarks(this: Transform);
        v10 = *(_QWORD *)&Bookmarks->x;
        vecChildPosition.z = Bookmarks->z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474DB0
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

//------------------------------------------------------------------------------
// Address: 0x00474E40
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00474EB0
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474EE0
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474F30
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00474F50
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x0057BF00
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580240
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF30
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF40
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580250
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00504ED0
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00504F90
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00505480
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047EA20
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EAE0
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EFD0
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

//------------------------------------------------------------------------------
// Address: 0x0047F060
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047F0D0
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F100
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F150
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00486CD0
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x005797B0
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D950
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005797E0
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005797F0
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D960
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005817E0
// Name: protected: void CDmeJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::OnConstruction(CDmeJoint *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeJoint::sm_pMatJoint != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: CDmeJoint::sm_pMatJoint);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 1);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeJoint", a3: v3);
      CDmeJoint::sm_pMatJoint = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefJoint, pMaterial: v4);
        CDmeJoint::sm_pMatJoint->DecrementReferenceCount(this: CDmeJoint::sm_pMatJoint);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005818A0
// Name: private: void CDmeJoint::DrawJoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::DrawJoints(CDmeJoint *this)
{
  int Phase; // edi
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  IMesh *v5; // ebx
  int v6; // edi
  CDmeDag *Child; // edi
  CDmeTransform *Transform; // eax
  CDmaVar<Vector> *Position; // eax
  __int64 v10; // xmm0_8
  float *m_pCurrPosition; // eax
  int v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int v19; // eax
  float *v20; // eax
  int v21; // eax
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  int v26; // ecx
  matrix3x4_t shapeToWorld; // [esp+Ch] [ebp-230h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-200h] BYREF
  Vector vecChildPosition; // [esp+224h] [ebp-18h]
  int cn; // [esp+230h] [ebp-Ch]
  CDmeDag *v31; // [esp+234h] [ebp-8h]
  int ci; // [esp+238h] [ebp-4h]

  v31 = this;
  if ( g_pMaterialSystem != nullptr )
  {
    Phase = CDmElementFramework::GetPhase(this);
    cn = Phase;
    CDmeDag::PushDagTransform(this);
    CDmeDag::GetShapeToWorldTransform(this, mat: &shapeToWorld);
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v4 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadMatrix(this: v4, a2: &shapeToWorld);
    v4->Bind(this: v4, a2: this->m_MatRefJoint.m_pMaterial, a3: nullptr);
    v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v5;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6 = 2 * Phase + 6;
    v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v5, nMaxVertexCount: v6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    for ( ci = 0; ci < cn; ++ci )
    {
      Child = CDmeDag::GetChild(this: v31, i: ci);
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: Child);
        Position = CDmeTransform::GetPosition(this: Transform);
        v10 = *(_QWORD *)&Position->m_Storage.x;
        vecChildPosition.z = Position->m_Storage.z;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *(_QWORD *)&vecChildPosition.x = v10;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
        if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = vecChildPosition;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -8355712;
        v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
        if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
      }
    }
    v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    v14[1] = 0.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 3.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v17 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v17;
    if ( v17 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v17;
    v18 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v18;
    *v18 = 0.0;
    v18[1] = 0.0;
    v18[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
    if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
    v20 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v20;
    *v20 = 0.0;
    v20[1] = 3.0;
    v20[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v21 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v21;
    if ( v21 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v21;
    v22 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v22;
    *v22 = 0.0;
    v22[1] = 0.0;
    v22[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
    if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
    v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
    *v24 = 0.0;
    v24[1] = 0.0;
    v24[2] = 3.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v26 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v26;
    if ( v26 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v26;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v26;
    }
    meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount *= 2;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v5->Draw_2(this: v5, a2: -1, a3: 0);
    v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
    v4->LoadIdentity(this: v4);
    CDmeDag::PopDagTransform(this: v31);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00581D90
// Name: public: virtual void CDmeJoint::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::Draw(CDmeJoint *this, CDmeDrawSettings *pDrawSettings)
{
  if ( CDmeJoint::sm_bDrawJoints && CDmeDag::IsVisible(this) )
    CDmeJoint::DrawJoints(this);
  CDmeDag::Draw(this, pDrawSettings);
}

//------------------------------------------------------------------------------
// Address: 0x00581E20
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00581E90
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00581EC0
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00581F10
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00581F30
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x006B76C0
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 0x8Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC750
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B76F0
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7700
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC760
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace vmap
