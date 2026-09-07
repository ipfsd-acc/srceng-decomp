// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapsidelist.cpp
// Functions: 25
// ============================================================

#include "hammer\mapsidelist.h"

//------------------------------------------------------------------------------
// Address: 0x1013E270
// Name: public: virtual char const __near * CMapSideList::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapSideList::GetType(CMapSideList *this)
{
  return CMapSideList::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013E280
// Name: public: virtual int CMapSideList::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapSideList::IsMapClass(CMapSideList *this, const char *Type)
{
  return Type == CMapSideList::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013E2A0
// Name: protected: void CMapSideList::UpdateParentKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::UpdateParentKey(CMapSideList *this)
{
  CMapEntity *v2; // eax
  char szValue[512]; // [esp+4h] [ebp-200h] BYREF

  CMapWorld::FaceID_FaceListsToString(
    pszList: szValue,
    nSize: 512,
    pFullFaceList: &this->m_Faces,
    pPartialFaceList: nullptr);
  v2 = (CMapEntity *)__RTDynamicCast(
                       inptr: this->m_pParent,
                       VfDelta: 0,
                       SrcType: &CMapAtom `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  if ( v2 != nullptr )
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: this->m_szKeyName, szValue);
}

//------------------------------------------------------------------------------
// Address: 0x1013E300
// Name: public: virtual unsigned int CMapSideList::GetSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapSideList::GetSize(CMapSideList *this)
{
  return 4 * this->m_Faces.m_Size + 4;
}

//------------------------------------------------------------------------------
// Address: 0x1013E310
// Name: public: virtual void CMapSideList::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::CalcBounds(CMapSideList *this, int bFullUpdate)
{
  int i; // ebx
  Vector Center; // [esp+Ch] [ebp-Ch] BYREF

  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, pt: &this->m_Origin);
  BoundBox::ResetBounds(this: &this->m_CullBox);
  BoundBox::UpdateBounds(this: &this->m_CullBox, pt: &this->m_Origin);
  for ( i = 0; i < this->m_Faces.m_Size; ++i )
  {
    CMapFace::GetCenter(this: this->m_Faces.m_Memory.m_pMemory[i], &Center);
    BoundBox::UpdateBounds(this: &this->m_CullBox, pt: &Center);
  }
  this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
  this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
  this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
  this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
  this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
  this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
}

//------------------------------------------------------------------------------
// Address: 0x1013E3B0
// Name: public: virtual void CMapSideList::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::OnRemoveFromWorld(CMapSideList *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  int v4; // edi
  CMapFace *v5; // ecx
  CMapClass *v6; // eax

  CMapClass::OnRemoveFromWorld(this, pWorld, bNotifyChildren);
  v4 = 0;
  if ( this->m_Faces.m_Size <= 0 )
  {
    this->m_Faces.m_Size = 0;
  }
  else
  {
    do
    {
      v5 = this->m_Faces.m_Memory.m_pMemory[v4];
      v6 = (CMapClass *)v5->GetParent(this: v5);
      CMapClass::UpdateDependency(this, pOldAttached: v6, pNewAttached: nullptr);
      ++v4;
    }
    while ( v4 < this->m_Faces.m_Size );
    this->m_Faces.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E410
// Name: public: virtual void CMapSideList::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapSideList::Render3D(CMapSideList *this@<ecx>, int a2@<ebx>, int a3@<edi>, CRender3D *pRender)
{
  IMatRenderContext *v5; // edi
  IMesh *v6; // ebx
  int m_Size; // eax
  int v8; // edi
  int v9; // edi
  float *m_pCurrPosition; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  int m_nVertexCount; // eax
  IMatRenderContext *v14; // esi
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-208h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-20h]
  Vector Center; // [esp+1F0h] [ebp-1Ch] BYREF
  IMatRenderContext *v18; // [esp+1FCh] [ebp-10h]
  int v19; // [esp+208h] [ebp-4h]

  if ( this->m_pParent->IsSelected(this: this->m_pParent) )
  {
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v19 = 0;
    v5 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(
                                a1: materials,
                                a2: a3);
    v18 = v5;
    pRenderContext.m_pObject = v5;
    LOBYTE(v19) = 1;
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    LOBYTE(v19) = 2;
    v6 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v5->GetDynamicMesh)(
                    a1: v5,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0,
                    a6: a2);
    m_Size = this->m_Faces.m_Size;
    meshBuilder.m_pMesh = v6;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v8 = 2 * m_Size;
    v6->SetPrimitiveType(this: v6, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v8, a3: v8, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v8;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v6, nMaxVertexCount: v8, desc: &meshBuilder);
    v9 = 0;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    if ( this->m_Faces.m_Size > 0 )
    {
      do
      {
        CMapFace::GetCenter(this: this->m_Faces.m_Memory.m_pMemory[v9], &Center);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        y = this->m_Origin.y;
        z = this->m_Origin.z;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = this->m_Origin.x;
        m_pCurrPosition[1] = y;
        m_pCurrPosition[2] = z;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = Center;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ++v9;
      }
      while ( v9 < this->m_Faces.m_Size );
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v6->Draw_2(this: v6, a2: -1, a3: 0);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v19) = 3;
    v14 = v18;
    v18->EndRender(this: v18);
    LOBYTE(v19) = 0;
    v14->Release(this: v14);
    v19 = 4;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    v19 = -1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E740
// Name: public: CMapSideList::CMapSideList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSideList *__thiscall CMapSideList::CMapSideList(CMapSideList *this, const char *pszKeyName)
{
  CMapFace **m_pMemory; // edx
  int *v4; // edx

  CMapClass::CMapClass(this);
  this->__vftable = (CMapSideList_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapSideList_vtbl *)&CMapSideList::`vftable';
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = m_pMemory;
  this->m_LostFaceIDs.m_Memory.m_pMemory = nullptr;
  this->m_LostFaceIDs.m_Memory.m_nAllocationCount = 0;
  this->m_LostFaceIDs.m_Memory.m_nGrowSize = 0;
  v4 = this->m_LostFaceIDs.m_Memory.m_pMemory;
  this->m_LostFaceIDs.m_Size = 0;
  this->m_LostFaceIDs.m_pElements = v4;
  strcpy(this->m_szKeyName, pszKeyName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013E800
// Name: public: virtual char const __near * CMapSideList::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapSideList::GetDescription(CMapSideList *this)
{
  return "Side list helper";
}

//------------------------------------------------------------------------------
// Address: 0x1013E810
// Name: public: virtual CMapSideList::~CMapSideList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::~CMapSideList(CMapSideList *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_LostFaceIDs; // esi

  this->__vftable = (CMapSideList_vtbl *)&CMapSideList::`vftable';
  p_m_LostFaceIDs = &this->m_LostFaceIDs;
  this->m_LostFaceIDs.m_Size = 0;
  if ( this->m_LostFaceIDs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_LostFaceIDs->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_LostFaceIDs->m_Memory.m_pMemory);
      p_m_LostFaceIDs->m_Memory.m_pMemory = nullptr;
    }
    p_m_LostFaceIDs->m_Memory.m_nAllocationCount = 0;
  }
  p_m_LostFaceIDs->m_pElements = p_m_LostFaceIDs->m_Memory.m_pMemory;
  if ( p_m_LostFaceIDs->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_LostFaceIDs->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_LostFaceIDs->m_Memory.m_pMemory);
      p_m_LostFaceIDs->m_Memory.m_pMemory = nullptr;
    }
    p_m_LostFaceIDs->m_Memory.m_nAllocationCount = 0;
  }
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&this->m_Faces);
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013E8C0
// Name: public: virtual class CMapClass __near * CMapSideList::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapSideList *__thiscall CMapSideList::CopyFrom(CMapSideList *this, CVisGroup *pOther, bool bUpdateDependencies)
{
  char *v4; // edi
  char *v5; // eax
  char v6; // cl
  int i; // edi
  CMapFace *v8; // ecx
  CMapClass *v9; // eax

  v4 = (char *)__RTDynamicCast(
                 inptr: pOther,
                 VfDelta: 0,
                 SrcType: &CMapClass `RTTI Type Descriptor',
                 TargetType: &CMapSideList `RTTI Type Descriptor',
                 isReference: 0);
  CMapClass::CopyFrom(this, pFrom: pOther, bUpdateDependencies);
  v5 = v4 + 216;
  do
  {
    v6 = *v5;
    v5[(char *)this - v4] = *v5;
    ++v5;
  }
  while ( v6 != 0 );
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int>>::AddVectorToTail(
    this: &this->m_Faces,
    src: (const CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *)(v4 + 296));
  if ( bUpdateDependencies )
  {
    for ( i = 0; i < this->m_Faces.m_Size; ++i )
    {
      v8 = this->m_Faces.m_Memory.m_pMemory[i];
      v9 = (CMapClass *)v8->GetParent(this: v8);
      CMapClass::UpdateDependency(this, pOldAttached: v9, pNewAttached: nullptr);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013E960
// Name: protected: bool CMapSideList::ReplaceSolidFaces(class CMapSolid __near *,class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapSideList::ReplaceSolidFaces(CMapSideList *this, CMapSolid *pOrigSolid, CMapSolid *pNewSolid)
{
  bool result; // al
  int v4; // ebx
  int v5; // ecx
  unsigned int v6; // esi
  int v7; // esi
  int v8; // edi
  int m_Size; // ecx
  int v10; // eax
  CMapFace **m_pMemory; // edx
  int v12; // ecx
  unsigned int v13; // ebx
  int v14; // [esp+4h] [ebp-18h]
  int i; // [esp+10h] [ebp-Ch]
  CMapFace **v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+14h] [ebp-8h]
  bool bDidSomething; // [esp+1Bh] [ebp-1h]

  result = false;
  v4 = 0;
  bDidSomething = false;
  i = 0;
  if ( pOrigSolid->Faces.nCount > 0 )
  {
    do
    {
      if ( v4 >= pOrigSolid->Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, pOrigSolid->Faces.nCount);
        v5 = v4 + 1;
        if ( v4 + 1 != pOrigSolid->Faces.nCount )
        {
          v6 = v5 / 6;
          if ( 6 * (v5 / 6) < v5 )
            ++v6;
          if ( v6 != pOrigSolid->Faces.nBlocks )
          {
            if ( v6 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &pOrigSolid->Faces, nNewBlocks: v6);
          }
          pOrigSolid->Faces.nCount = v4 + 1;
        }
      }
      v7 = v4 / 6;
      v8 = v4 % 6;
      m_Size = this->m_Faces.m_Size;
      v10 = 0;
      v14 = m_Size;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_Faces.m_Memory.m_pMemory;
        v17 = m_pMemory;
        do
        {
          if ( *m_pMemory != nullptr )
          {
            if ( (*m_pMemory)->m_nFaceID == pOrigSolid->Faces.Blocks[v4 / 6][v8].m_nFaceID )
            {
              v18 = v10;
              if ( v10 != -1 )
              {
                if ( v4 >= pNewSolid->Faces.nCount )
                {
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, pNewSolid->Faces.nCount);
                  v12 = v4 + 1;
                  if ( v4 + 1 != pNewSolid->Faces.nCount )
                  {
                    v13 = v12 / 6;
                    if ( 6 * (v12 / 6) < v12 )
                      ++v13;
                    if ( v13 != pNewSolid->Faces.nBlocks )
                    {
                      if ( v13 > 0x57 )
                        _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
                      BlockArray<CMapFace,6,86>::GetBlocks(this: &pNewSolid->Faces, nNewBlocks: v13);
                    }
                    v4 = i;
                    pNewSolid->Faces.nCount = i + 1;
                  }
                  v10 = v18;
                }
                this->m_Faces.m_Memory.m_pMemory[v10] = &pNewSolid->Faces.Blocks[v7][v8];
                CMapClass::UpdateDependency(this, pOldAttached: pOrigSolid, pNewAttached: pNewSolid);
                bDidSomething = true;
              }
              break;
            }
            m_pMemory = v17;
            m_Size = v14;
          }
          ++v10;
          v17 = ++m_pMemory;
        }
        while ( v10 < m_Size );
      }
      i = ++v4;
    }
    while ( v4 < pOrigSolid->Faces.nCount );
    return bDidSomething;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013EB80
// Name: public: static class CMapClass __near * CMapSideList::CreateMapSideList(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSideList *__cdecl CMapSideList::CreateMapSideList(CHelperInfo *pHelperInfo)
{
  char *v1; // esi
  CMapSideList *v2; // eax
  CMapSideList *v4; // eax

  if ( pHelperInfo->m_Parameters.m_Size > 0 && (v1 = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) != nullptr )
  {
    v2 = (CMapSideList *)operator new(nSize: 0x150u);
    if ( v2 != nullptr )
      return CMapSideList::CMapSideList(this: v2, pszKeyName: v1);
  }
  else
  {
    v4 = (CMapSideList *)operator new(nSize: 0x150u);
    if ( v4 != nullptr )
      return CMapSideList::CMapSideList(this: v4, pszKeyName: "sides");
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013EC20
// Name: public: CMapSideList::CMapSideList(void)
// Source: json
//------------------------------------------------------------------------------
CMapSideList *__thiscall CMapSideList::CMapSideList(CMapSideList *this)
{
  CMapFace **m_pMemory; // edx
  int *v3; // edx

  CMapClass::CMapClass(this);
  this->__vftable = (CMapSideList_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapSideList_vtbl *)&CMapSideList::`vftable';
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Faces.m_Memory.m_pMemory;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = m_pMemory;
  this->m_LostFaceIDs.m_Memory.m_pMemory = nullptr;
  this->m_LostFaceIDs.m_Memory.m_nAllocationCount = 0;
  this->m_LostFaceIDs.m_Memory.m_nGrowSize = 0;
  v3 = this->m_LostFaceIDs.m_Memory.m_pMemory;
  this->m_LostFaceIDs.m_Size = 0;
  this->m_LostFaceIDs.m_pElements = v3;
  this->m_szKeyName[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013ECF0
// Name: protected: void CMapSideList::BuildFaceListForValue(char const __near *,class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::BuildFaceListForValue(CMapSideList *this, const char *pszValue, CMapWorld *pWorld)
{
  CMapSideList *v3; // edi
  int m_Size; // eax
  int v5; // ebx
  CMapFace *v6; // ecx
  int v7; // eax
  CMapClass *v8; // eax
  int v9; // eax
  int v10; // eax
  CMapFace *v11; // ebx
  int v12; // ecx
  CUtlMemory<CCullTreeNode *,int> *p_m_Faces; // esi
  int v14; // eax
  CCullTreeNode **m_pMemory; // edx
  CMapClass *v16; // eax
  int v17; // edi
  int m_nAllocationCount; // eax
  CCullTreeNode **v19; // ecx
  int v20; // eax
  CMapFace **v21; // eax
  CMapFace **v22; // eax
  CMapFaceList NewFaces; // [esp+Ch] [ebp-24h] BYREF
  CMapSideList *v24; // [esp+20h] [ebp-10h]
  int v25; // [esp+2Ch] [ebp-4h]
  int i; // [esp+38h] [ebp+8h]

  v3 = this;
  v24 = this;
  memset(&NewFaces, 0, sizeof(NewFaces));
  v25 = 2;
  CMapWorld::FaceID_StringToFaceLists(
    this: pWorld,
    pFullFaceList: (CUtlMemory<CCullTreeNode *,int> *)&NewFaces,
    pPartialFaceList: nullptr,
    pszValue);
  m_Size = v3->m_Faces.m_Size;
  if ( m_Size > 0 )
  {
    v5 = m_Size - 1;
    do
    {
      v6 = v3->m_Faces.m_Memory.m_pMemory[v5];
      if ( v6 != nullptr )
      {
        v7 = 0;
        if ( NewFaces.m_Size <= 0 )
          goto LABEL_9;
        while ( NewFaces.m_Memory.m_pMemory[v7] != v6 )
        {
          if ( ++v7 >= NewFaces.m_Size )
            goto LABEL_9;
        }
        if ( v7 == -1 )
        {
LABEL_9:
          v8 = (CMapClass *)v6->GetParent(this: v6);
          CMapClass::UpdateDependency(this: v3, pOldAttached: v8, pNewAttached: nullptr);
          v9 = v3->m_Faces.m_Size;
          if ( v9 > 0 )
          {
            if ( v5 != v9 - 1 )
              v3->m_Faces.m_Memory.m_pMemory[v5] = v3->m_Faces.m_Memory.m_pMemory[v9 - 1];
            --v3->m_Faces.m_Size;
          }
        }
      }
      --v5;
    }
    while ( v5 >= 0 );
  }
  v10 = 0;
  for ( i = 0; v10 < NewFaces.m_Size; i = v10 )
  {
    v11 = NewFaces.m_Memory.m_pMemory[v10];
    if ( v11 != nullptr )
    {
      v12 = v3->m_Faces.m_Size;
      p_m_Faces = (CUtlMemory<CCullTreeNode *,int> *)&v3->m_Faces;
      v14 = 0;
      if ( v12 <= 0 )
        goto LABEL_22;
      m_pMemory = p_m_Faces->m_pMemory;
      while ( *m_pMemory != (CCullTreeNode *)v11 )
      {
        ++v14;
        ++m_pMemory;
        if ( v14 >= v12 )
          goto LABEL_22;
      }
      if ( v14 == -1 )
      {
LABEL_22:
        v16 = (CMapClass *)v11->GetParent(this: v11);
        CMapClass::UpdateDependency(this: v3, pOldAttached: nullptr, pNewAttached: v16);
        v17 = v3->m_Faces.m_Size;
        m_nAllocationCount = p_m_Faces->m_nAllocationCount;
        if ( v17 + 1 > m_nAllocationCount )
          CUtlMemory<CVisGroup *,int>::Grow(this: p_m_Faces, num: v17 - m_nAllocationCount + 1);
        ++p_m_Faces[1].m_pMemory;
        v19 = p_m_Faces->m_pMemory;
        v20 = (int)p_m_Faces[1].m_pMemory - v17 - 1;
        p_m_Faces[1].m_nAllocationCount = (int)p_m_Faces->m_pMemory;
        if ( v20 > 0 )
          _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
        v21 = (CMapFace **)&p_m_Faces->m_pMemory[v17];
        v3 = v24;
        if ( v21 != nullptr )
          *v21 = v11;
      }
    }
    v10 = i + 1;
  }
  v3->CalcBounds(this: v3, a2: 0);
  v25 = 4;
  v22 = NewFaces.m_Memory.m_pMemory;
  NewFaces.m_Size = 0;
  if ( NewFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( NewFaces.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: NewFaces.m_Memory.m_pMemory);
      v22 = nullptr;
      NewFaces.m_Memory.m_pMemory = nullptr;
    }
    NewFaces.m_Memory.m_nAllocationCount = 0;
  }
  NewFaces.m_pElements = v22;
  v25 = -1;
  if ( NewFaces.m_Memory.m_nGrowSize >= 0 && NewFaces.m_Memory.m_pMemory != nullptr )
    free(pMem: NewFaces.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1013EEF0
// Name: public: virtual class CMapClass __near * CMapSideList::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapSideList *__thiscall CMapSideList::Copy(CMapSideList *this, BOOL bUpdateDependencies)
{
  CMapSideList *v3; // eax
  CMapSideList *v4; // esi

  v3 = (CMapSideList *)operator new(nSize: 0x150u);
  if ( v3 != nullptr )
    v4 = CMapSideList::CMapSideList(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1013EF70
// Name: public: virtual void CMapSideList::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::OnParentKeyChanged(CMapSideList *this, const char *pszKey, const char *pszValue)
{
  CMapWorld *WorldObject; // edi

  WorldObject = CMapClass::GetWorldObject(pStart: this);
  if ( WorldObject != nullptr && _V_stricmp(s1: pszKey, s2: this->m_szKeyName) == 0 )
    CMapSideList::BuildFaceListForValue(this, pszValue, pWorld: WorldObject);
}

//------------------------------------------------------------------------------
// Address: 0x1013EFB0
// Name: protected: virtual void CMapSideList::UpdateDependencies(class CMapWorld __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::UpdateDependencies(CMapSideList *this, CMapWorld *pWorld, CMapClass *pObject)
{
  CMapSolid *v4; // ecx
  int m_Size; // eax
  int v6; // eax
  CMapFace *FaceID; // edi
  int v8; // ecx
  int v9; // eax
  CMapFace **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v12; // edi
  CMapFace **v13; // ecx
  int v14; // eax
  CMapFace **v15; // eax
  int v16; // ecx
  CMapEntity *v17; // eax
  char pszList[512]; // [esp+4h] [ebp-208h] BYREF
  CMapSolid *pSolid; // [esp+204h] [ebp-8h]
  CMapFace *pFace; // [esp+208h] [ebp-4h]
  int i; // [esp+218h] [ebp+Ch]

  v4 = (CMapSolid *)__RTDynamicCast(
                      inptr: pObject,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapSolid `RTTI Type Descriptor',
                      isReference: 0);
  pSolid = v4;
  if ( v4 != nullptr )
  {
    m_Size = this->m_LostFaceIDs.m_Size;
    if ( m_Size > 0 )
    {
      v6 = m_Size - 1;
      i = v6;
      if ( v6 >= 0 )
      {
        while ( 1 )
        {
          FaceID = CMapSolid::FindFaceID(this: v4, nFaceID: this->m_LostFaceIDs.m_Memory.m_pMemory[v6]);
          pFace = FaceID;
          if ( FaceID != nullptr )
          {
            v8 = this->m_Faces.m_Size;
            v9 = 0;
            if ( v8 <= 0 )
              goto LABEL_13;
            m_pMemory = this->m_Faces.m_Memory.m_pMemory;
            while ( *m_pMemory != FaceID )
            {
              ++v9;
              ++m_pMemory;
              if ( v9 >= v8 )
                goto LABEL_13;
            }
            if ( v9 == -1 )
            {
LABEL_13:
              m_nAllocationCount = this->m_Faces.m_Memory.m_nAllocationCount;
              v12 = this->m_Faces.m_Size;
              if ( v8 + 1 > m_nAllocationCount )
                CUtlMemory<CVisGroup *,int>::Grow(
                  this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_Faces,
                  num: v12 - m_nAllocationCount + 1);
              ++this->m_Faces.m_Size;
              v13 = this->m_Faces.m_Memory.m_pMemory;
              v14 = this->m_Faces.m_Size - v12 - 1;
              this->m_Faces.m_pElements = v13;
              if ( v14 > 0 )
                _V_memmove(dest: &v13[v12 + 1], src: &v13[v12], count: 4 * v14);
              v15 = &this->m_Faces.m_Memory.m_pMemory[v12];
              if ( v15 != nullptr )
                *v15 = pFace;
            }
            v16 = this->m_LostFaceIDs.m_Size;
            if ( v16 > 0 )
            {
              if ( i != v16 - 1 )
                this->m_LostFaceIDs.m_Memory.m_pMemory[i] = this->m_LostFaceIDs.m_Memory.m_pMemory[v16 - 1];
              --this->m_LostFaceIDs.m_Size;
            }
          }
          v6 = --i;
          if ( i < 0 )
            break;
          v4 = pSolid;
        }
      }
      CMapWorld::FaceID_FaceListsToString(pszList, nSize: 512, pFullFaceList: &this->m_Faces, pPartialFaceList: nullptr);
      v17 = (CMapEntity *)__RTDynamicCast(
                            inptr: this->m_pParent,
                            VfDelta: 0,
                            SrcType: &CMapAtom `RTTI Type Descriptor',
                            TargetType: &CMapEntity `RTTI Type Descriptor',
                            isReference: 0);
      if ( v17 != nullptr )
        CMapEntity::NotifyChildKeyChanged(this: v17, pChild: this, szKey: this->m_szKeyName, szValue: pszList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F140
// Name: class CMapClass __near * CMapSideList_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapSideList *__cdecl CMapSideList_CreateObject()
{
  CMapSideList *v0; // eax

  v0 = (CMapSideList *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return CMapSideList::CMapSideList(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013F1A0
// Name: protected: void CMapSideList::RebuildFaceList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::RebuildFaceList(CMapSideList *this)
{
  CMapWorld *WorldObject; // edi
  CMapClass *v3; // eax
  char *v4; // eax
  const char *Value; // eax

  WorldObject = CMapClass::GetWorldObject(pStart: this);
  if ( WorldObject != nullptr )
  {
    v3 = this->GetParent(this);
    v4 = (char *)__RTDynamicCast(
                   inptr: v3,
                   VfDelta: 0,
                   SrcType: &CMapClass `RTTI Type Descriptor',
                   TargetType: &CMapEntity `RTTI Type Descriptor',
                   isReference: 0);
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
              this: (WCKeyValuesT<WCKVBase_Dict> *)(v4 + 220),
              pszKey: this->m_szKeyName,
              piIndex: nullptr);
    if ( Value != nullptr )
      CMapSideList::BuildFaceListForValue(this, pszValue: Value, pWorld: WorldObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F200
// Name: protected: class CMapFace __near * CMapSideList::FindFaceIDInList(int,class CUtlReferenceVector<class CMapClass> const __near &)
// Source: json
//------------------------------------------------------------------------------
CMapFace *__thiscall CMapSideList::FindFaceIDInList(
        CMapSideList *this,
        int nFaceID,
        const CUtlReferenceVector<CMapClass> *List)
{
  const CUtlReferenceVector<CMapClass> *v3; // edx
  int v4; // ebx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v6; // ecx
  CMapClass *v7; // edi
  CMapSolid *v8; // eax
  CMapFace *result; // eax
  CMapClass *i; // eax
  CMapSolid *v11; // eax
  EnumChildrenPos_t pos2; // [esp+Ch] [ebp-9Ch] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+90h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v14; // [esp+94h] [ebp-14h]
  void *inptr; // [esp+98h] [ebp-10h]
  int v16; // [esp+A4h] [ebp-4h]

  v3 = List;
  v4 = 0;
  if ( List->m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    m_pObject = v3->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&v3->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&v3->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      inptr = v3->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&v3->m_Memory + 2) >> 27)][v4
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&v3->m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v6 = m_pObject->m_References.m_pHead;
      if ( v6 != nullptr )
        v6->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v14 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v7 = (CMapClass *)inptr;
    v16 = -1;
    if ( inptr != nullptr )
    {
      if ( v14 != nullptr )
      {
        v14->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v14;
      }
      else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
      {
        *((_DWORD *)inptr + 8) = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v14 = nullptr;
      m_pHead = nullptr;
      inptr = nullptr;
    }
    v8 = (CMapSolid *)__RTDynamicCast(
                        inptr: v7,
                        VfDelta: 0,
                        SrcType: &CMapClass `RTTI Type Descriptor',
                        TargetType: &CMapSolid `RTTI Type Descriptor',
                        isReference: 0);
    if ( v8 != nullptr )
    {
      result = CMapSolid::FindFaceID(this: v8, nFaceID);
      if ( result != nullptr )
        return result;
    }
    for ( i = CMapClass::GetFirstDescendent(this: v7, pos: (CMapClass *)&pos2);
          i != nullptr;
          i = CMapClass::GetNextDescendent(this: v7, pos: (CMapClass *)&pos2) )
    {
      v11 = (CMapSolid *)__RTDynamicCast(
                           inptr: i,
                           VfDelta: 0,
                           SrcType: &CMapClass `RTTI Type Descriptor',
                           TargetType: &CMapSolid `RTTI Type Descriptor',
                           isReference: 0);
      if ( v11 != nullptr )
      {
        result = CMapSolid::FindFaceID(this: v11, nFaceID);
        if ( result != nullptr )
          return result;
      }
    }
    if ( ++v4 >= List->m_Size )
      return nullptr;
    v3 = List;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F360
// Name: public: virtual void CMapSideList::OnNotifyDependent(class CMapClass __near *,enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::OnNotifyDependent(CMapSideList *this, CMapSolid *pObject, int eNotifyType)
{
  CMapSolid *v4; // edi
  int m_Size; // eax
  int v6; // eax
  CMapFace *v7; // esi
  int v8; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v11; // eax
  int *v12; // eax
  int v13; // ecx
  int m_nFaceID; // [esp+4h] [ebp-4h]
  CMapSolid *pSolid; // [esp+10h] [ebp+8h]
  int i; // [esp+14h] [ebp+Ch]

  if ( !CMapDoc::m_pMapDoc->m_bLoading )
  {
    if ( eNotifyType != 0 )
    {
      if ( eNotifyType == 1 || eNotifyType == 7 )
      {
        v4 = (CMapSolid *)__RTDynamicCast(
                            inptr: pObject,
                            VfDelta: 0,
                            SrcType: &CMapClass `RTTI Type Descriptor',
                            TargetType: &CMapSolid `RTTI Type Descriptor',
                            isReference: 0);
        pSolid = v4;
        if ( v4 != nullptr )
        {
          m_Size = this->m_Faces.m_Size;
          if ( m_Size > 0 )
          {
            v6 = m_Size - 1;
            i = v6;
            if ( v6 >= 0 )
            {
              while ( 1 )
              {
                v7 = this->m_Faces.m_Memory.m_pMemory[v6];
                if ( v7 != nullptr && v7->GetParent(this: v7) == v4 )
                {
                  v8 = this->m_LostFaceIDs.m_Size;
                  m_nFaceID = v7->m_nFaceID;
                  m_nAllocationCount = this->m_LostFaceIDs.m_Memory.m_nAllocationCount;
                  if ( v8 + 1 > m_nAllocationCount )
                    CUtlMemory<IDmFormatUpdater *,int>::Grow(
                      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_LostFaceIDs,
                      num: v8 - m_nAllocationCount + 1);
                  ++this->m_LostFaceIDs.m_Size;
                  m_pMemory = this->m_LostFaceIDs.m_Memory.m_pMemory;
                  v11 = this->m_LostFaceIDs.m_Size - v8 - 1;
                  this->m_LostFaceIDs.m_pElements = m_pMemory;
                  if ( v11 > 0 )
                    _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
                  v12 = &this->m_LostFaceIDs.m_Memory.m_pMemory[v8];
                  if ( v12 != nullptr )
                    *v12 = m_nFaceID;
                  v13 = this->m_Faces.m_Size;
                  if ( v13 > 0 )
                  {
                    if ( i != v13 - 1 )
                      this->m_Faces.m_Memory.m_pMemory[i] = this->m_Faces.m_Memory.m_pMemory[v13 - 1];
                    --this->m_Faces.m_Size;
                  }
                }
                v6 = --i;
                if ( i < 0 )
                  break;
                v4 = pSolid;
              }
            }
            CMapSideList::UpdateParentKey(this);
          }
        }
      }
    }
    else
    {
      this->m_Faces.m_Size = 0;
      CMapSideList::RebuildFaceList(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F4C0
// Name: protected: void CMapSideList::ReplaceFacesInCopy(class CMapSideList __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::ReplaceFacesInCopy(
        CMapSideList *this,
        CMapSideList *pCopy,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  const CUtlReferenceVector<CMapClass> *v4; // esi
  int v5; // edx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v7; // ecx
  CMapClass *v8; // edi
  CMapClass *v9; // ebx
  CMapSolid *v10; // esi
  CMapSolid *v11; // eax
  CMapClass *FirstDescendent; // esi
  CMapClass *i; // edi
  CMapSolid *v14; // esi
  CMapSolid *v15; // eax
  CMapEntity *v16; // eax
  char pszList[512]; // [esp+8h] [ebp-32Ch] BYREF
  EnumChildrenPos_t e2; // [esp+208h] [ebp-12Ch] BYREF
  EnumChildrenPos_t e1; // [esp+28Ch] [ebp-A8h] BYREF
  CMapSideList *v20; // [esp+310h] [ebp-24h]
  CMapClass *pOriginal; // [esp+314h] [ebp-20h]
  int pos; // [esp+318h] [ebp-1Ch]
  CUtlReference<CMapClass> *m_pHead; // [esp+31Ch] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v24; // [esp+320h] [ebp-14h]
  void *inptr; // [esp+324h] [ebp-10h]
  int v26; // [esp+330h] [ebp-4h]

  v4 = OriginalList;
  v5 = 0;
  v20 = this;
  pos = 0;
  if ( OriginalList->m_Size > 0 )
  {
    while ( 1 )
    {
      m_pObject = v4->m_Memory.m_pMemory[v5 >> (*((int *)&v4->m_Memory + 2) >> 27)][v5
                                                                                  & ((32 * *((_DWORD *)&v4->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = v4->m_Memory.m_pMemory[v5 >> (*((int *)&v4->m_Memory + 2) >> 27)][v5
                                                                                & ((32 * *((_DWORD *)&v4->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v7 = m_pObject->m_References.m_pHead;
        if ( v7 != nullptr )
          v7->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v24 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v8 = (CMapClass *)inptr;
      pOriginal = (CMapClass *)inptr;
      v26 = -1;
      if ( inptr != nullptr )
      {
        if ( v24 != nullptr )
        {
          v24->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v24;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v24 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      v9 = NewList->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&NewList->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&NewList->m_Memory + 2)) >> 5)].m_pObject;
      if ( v8 != v20 )
      {
        v10 = (CMapSolid *)__RTDynamicCast(
                             inptr: v8,
                             VfDelta: 0,
                             SrcType: &CMapClass `RTTI Type Descriptor',
                             TargetType: &CMapSolid `RTTI Type Descriptor',
                             isReference: 0);
        if ( v10 != nullptr )
        {
          v11 = (CMapSolid *)__RTDynamicCast(
                               inptr: v9,
                               VfDelta: 0,
                               SrcType: &CMapClass `RTTI Type Descriptor',
                               TargetType: &CMapSolid `RTTI Type Descriptor',
                               isReference: 0);
          if ( v11 != nullptr )
            CMapSideList::ReplaceSolidFaces(this: pCopy, pOrigSolid: v10, pNewSolid: v11);
        }
        FirstDescendent = CMapClass::GetFirstDescendent(this: v8, pos: (CMapClass *)&e1);
        for ( i = CMapClass::GetFirstDescendent(this: v9, pos: (CMapClass *)&e2);
              FirstDescendent != nullptr;
              i = CMapClass::GetNextDescendent(this: v9, pos: (CMapClass *)&e2) )
        {
          v14 = (CMapSolid *)__RTDynamicCast(
                               inptr: FirstDescendent,
                               VfDelta: 0,
                               SrcType: &CMapClass `RTTI Type Descriptor',
                               TargetType: &CMapSolid `RTTI Type Descriptor',
                               isReference: 0);
          if ( v14 != nullptr )
          {
            v15 = (CMapSolid *)__RTDynamicCast(
                                 inptr: i,
                                 VfDelta: 0,
                                 SrcType: &CMapClass `RTTI Type Descriptor',
                                 TargetType: &CMapSolid `RTTI Type Descriptor',
                                 isReference: 0);
            if ( v15 != nullptr )
              CMapSideList::ReplaceSolidFaces(this: pCopy, pOrigSolid: v14, pNewSolid: v15);
          }
          FirstDescendent = CMapClass::GetNextDescendent(this: pOriginal, pos: (CMapClass *)&e1);
        }
        v5 = pos;
      }
      pos = ++v5;
      if ( v5 >= OriginalList->m_Size )
        break;
      v4 = OriginalList;
    }
  }
  CMapWorld::FaceID_FaceListsToString(pszList, nSize: 512, pFullFaceList: &pCopy->m_Faces, pPartialFaceList: nullptr);
  v16 = (CMapEntity *)__RTDynamicCast(
                        inptr: pCopy->m_pParent,
                        VfDelta: 0,
                        SrcType: &CMapAtom `RTTI Type Descriptor',
                        TargetType: &CMapEntity `RTTI Type Descriptor',
                        isReference: 0);
  if ( v16 != nullptr )
    CMapEntity::NotifyChildKeyChanged(this: v16, pChild: pCopy, szKey: pCopy->m_szKeyName, szValue: pszList);
}

//------------------------------------------------------------------------------
// Address: 0x1013F710
// Name: public: virtual void CMapSideList::OnClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::OnClone(
        CMapSideList *this,
        CMapSideList *pCloneObject,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  CMapSideList::ReplaceFacesInCopy(this, pCopy: pCloneObject, OriginalList, NewList);
}

//------------------------------------------------------------------------------
// Address: 0x1013F730
// Name: public: virtual void CMapSideList::OnPaste(class CMapClass __near *,class CMapWorld __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSideList::OnPaste(
        CMapSideList *this,
        CMapClass *pCopyObject,
        CMapWorld *pSourceWorld,
        CMapWorld *pDestWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  CMapClass *v6; // esi
  CMapClass *(__thiscall *GetParent)(CMapClass *); // edx
  CMapSideList *v8; // edi
  CMapClass *v9; // eax
  char *v10; // eax
  char *Value; // eax
  char *v12; // edx
  char v13; // cl
  const char *i; // eax
  int v15; // eax
  CMapFace *FaceIDInList; // ebx
  float z; // edi
  float x; // eax
  float v19; // ecx
  int v20; // eax
  CMapFace **v21; // eax
  char szVal[512]; // [esp+8h] [ebp-204h] BYREF
  CMapSideList *v23; // [esp+208h] [ebp-4h]

  v6 = pCopyObject;
  GetParent = pCopyObject->GetParent;
  v8 = this;
  v23 = this;
  v9 = GetParent(this: pCopyObject);
  v10 = (char *)__RTDynamicCast(
                  inptr: v9,
                  VfDelta: 0,
                  SrcType: &CMapClass `RTTI Type Descriptor',
                  TargetType: &CMapEntity `RTTI Type Descriptor',
                  isReference: 0);
  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                    this: (WCKeyValuesT<WCKVBase_Dict> *)(v10 + 220),
                    pszKey: v8->m_szKeyName,
                    piIndex: nullptr);
  if ( Value != nullptr )
  {
    v12 = (char *)(szVal - Value);
    do
    {
      v13 = *Value;
      Value[(_DWORD)v12] = *Value;
      ++Value;
    }
    while ( v13 != 0 );
    for ( i = strtok(string: szVal, control: " "); i != nullptr; v8 = v23 )
    {
      v15 = atoi(nptr: i);
      FaceIDInList = CMapSideList::FindFaceIDInList(this: v8, nFaceID: v15, List: OriginalList);
      if ( FaceIDInList != nullptr )
      {
        z = v6[1].m_BoundingBox.bmaxs.z;
        x = v6[1].m_BoundingBox.bmaxs.x;
        if ( LODWORD(z) + 1 > SLODWORD(x) )
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&v6[1].m_BoundingBox.bmins.z,
            num: LODWORD(z) - LODWORD(x) + 1);
        ++LODWORD(v6[1].m_BoundingBox.bmaxs.z);
        v19 = v6[1].m_BoundingBox.bmins.z;
        v20 = LODWORD(v6[1].m_BoundingBox.bmaxs.z) - LODWORD(z) - 1;
        *(float *)&v6[1].m_Render2DBox.__vftable = v19;
        if ( v20 > 0 )
          _V_memmove(
            dest: (void *)(LODWORD(v19) + 4 * LODWORD(z) + 4),
            src: (const void *)(LODWORD(v19) + 4 * LODWORD(z)),
            count: 4 * v20);
        v21 = (CMapFace **)(LODWORD(v6[1].m_BoundingBox.bmins.z) + 4 * LODWORD(z));
        if ( v21 != nullptr )
          *v21 = FaceIDInList;
      }
      i = strtok(string: nullptr, control: " ");
      v6 = pCopyObject;
    }
  }
  CMapSideList::ReplaceFacesInCopy(this: v8, pCopy: (CMapSideList *)v6, OriginalList, NewList);
}
