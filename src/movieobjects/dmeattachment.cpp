// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeattachment.cpp
// Functions: 10
// ============================================================

#include "movieobjects\dmeattachment.h"

//------------------------------------------------------------------------------
// Address: 0x004B3270
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3350
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3790
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B37C0
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B3880
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AC0A0
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFC60
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AC0D0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC0E0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFC70
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005045D0
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005046B0
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00504AF0
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504B20
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504BE0
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067D290
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681F70
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067D2C0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D2D0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00681F80
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004B78F0
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B79D0
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7E10
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B7E40
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B7F00
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059ACB0
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC50
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ACE0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059ACF0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC60
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005015D0
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005016B0
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00501AF0
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00501B20
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00501BE0
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EF910
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3EC0
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EF940
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF950
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3ED0
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00470550
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470630
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470A70
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00470AA0
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00470B60
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00569E70
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E150
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00569EA0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569EB0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E160
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00474280
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474360
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004747A0
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004747D0
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474890
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00579F70
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E280
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579FA0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579FB0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E290
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D4720
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4800
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4C40
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D4C70
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D4D30
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B0530
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B50F0
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0560
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0570
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5100
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00474FF0
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004750D0
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475510
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475540
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475600
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF60
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580260
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF90
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BFA0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580270
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004FA5F0
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA6D0
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FAB10
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FAB40
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FAC00
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E87B0
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECD60
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E87E0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E87F0
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ECD70
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047F200
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F2E0
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F720
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F750
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F820
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00579810
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D970
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579840
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579850
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D980
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00581FF0
// Name: protected: void CDmeAttachment::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::OnConstruction(CDmeAttachment *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMaterial *v4; // eax

  this->m_bIsRigid.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "isRigid",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bIsRigid);
  this->m_bIsWorldAligned.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "isWorldAligned",
                                           type: AT_BOOL,
                                           pMemory: &this->m_bIsWorldAligned);
  if ( g_pMaterialSystem != nullptr )
  {
    if ( CDmeAttachment::sm_pMatAttachment != nullptr )
    {
      CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: CDmeAttachment::sm_pMatAttachment);
    }
    else
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
      else
        v3 = nullptr;
      KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v3, keyName: "$ignorez", value: 0);
      v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__DmeAttachment", a3: v3);
      CDmeAttachment::sm_pMatAttachment = v4;
      if ( v4 != nullptr )
      {
        CMaterialReference::Init(this: &this->m_MatRefAttachment, pMaterial: v4);
        CDmeAttachment::sm_pMatAttachment->DecrementReferenceCount(this: CDmeAttachment::sm_pMatAttachment);
        g_pMaterialSystem->CacheUsedMaterials(this: g_pMaterialSystem);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005820D0
// Name: public: virtual void CDmeAttachment::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeAttachment::Draw(
        CDmeAttachment *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const matrix3x4_t *shapeToWorld,
        CDmeDrawSettings *pDrawSettings)
{
  int v6; // esi
  IMesh *v7; // edi
  float *m_pCurrPosition; // eax
  int v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  int v17; // eax
  float *v18; // eax
  int m_nVertexCount; // eax
  int v20; // ecx
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1E8h] BYREF

  if ( g_pMaterialSystem != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3,
           a3: a4,
           a4: a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 84))(a1: v6);
    (*(void (__thiscall **)(int, const matrix3x4_t *))(*(_DWORD *)v6 + 92))(a1: v6, a2: shapeToWorld);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v6 + 36))(
      a1: v6,
      a2: CDmeAttachment::sm_pMatAttachment,
      a3: 0);
    v7 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 228))(
                    a1: v6,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v7;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v7, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v9 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v9;
    if ( v9 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v9;
    v10 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v10;
    *v10 = 6.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
    if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
    v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
    *v12 = 0.0;
    v12[1] = 0.0;
    v12[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v13 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v13;
    if ( v13 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v13;
    v14 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v14;
    *v14 = 0.0;
    v14[1] = 6.0;
    v14[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
    if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
    v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
    *v16 = 0.0;
    v16[1] = 0.0;
    v16[2] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
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
    v18[2] = 6.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    v20 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = v20;
    if ( v20 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    {
      m_nVertexCount = v20;
      meshBuilder.m_VertexBuilder.m_nVertexCount = v20;
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
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v7->Draw_2(this: v7, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 80))(a1: v6, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00582510
// Name: public: virtual bool CDmeAttachment::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttachment::IsA(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00582540
// Name: public: virtual int CDmeAttachment::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttachment::GetInheritanceDepth(CDmeAttachment *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttachment::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00582610
// Name: protected: virtual void CDmeAttachment::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttachment::PerformConstruction(CDmeAttachment *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeShape::OnConstruction(this);
  CDmeAttachment::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B7720
// Name: _dynamic_initializer_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttachment::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttachment pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC770
// Name: _dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttachment::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttachment::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B7750
// Name: _dynamic_initializer_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttachment_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7760
// Name: _dynamic_initializer_for__g_CDmeAttachment_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttachment_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttachment_Helper,
           classname: "DmeAttachment",
           pFactory: &g_CDmeAttachment_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC780
// Name: _dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttachment_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeAttachment_Factory.m_CallBackList);
}

} // namespace vmap
