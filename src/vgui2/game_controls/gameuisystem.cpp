// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuisystem.cpp
// Functions: 22
// ============================================================

#include "vgui2\game_controls\gameuisystem.h"

//------------------------------------------------------------------------------
// Address: 0x0041C3D0
// Name: public: virtual char const __near * CGameUISystem::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGameUISystem::GetName(CGameUISystem *this)
{
  return CUtlString::operator char const *(this: &this->m_GameUIDef.m_pName);
}

//------------------------------------------------------------------------------
// Address: 0x0041C3E0
// Name: public: virtual void CGameUISystem::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::Release(CGameUISystem *this)
{
  const char *v2; // eax

  v2 = (const char *)this->GetName(this);
  DevMsg(a1: "CGameUISystem[%p]::Release( name = %s )\n", this, v2);
  CGameUISystemMgr::OnScreenReleased(this: g_pGameUISystemMgrImpl, pScreen: this);
  CGameUIDefinition::Shutdown(this: &this->m_GameUIDef);
  ((void (__thiscall *)(CGameUISystem *, int))this->dtr_CGameUISystem)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041C420
// Name: public: virtual void CGameUISystem::LoadEmptyGameUI(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::LoadEmptyGameUI(CGameUISystem *this, CGameLayer *pName)
{
  CGameUIDefinition *p_m_GameUIDef; // esi

  p_m_GameUIDef = &this->m_GameUIDef;
  CGameUIDefinition::Shutdown(this: &this->m_GameUIDef);
  CGameUIDefinition::CreateDefault(this: p_m_GameUIDef, pName);
}

//------------------------------------------------------------------------------
// Address: 0x0041C440
// Name: public: virtual bool CGameUISystem::LoadGameUIDefinition(class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUISystem::LoadGameUIDefinition(CGameUISystem *this, CUtlBuffer *buf, const char *pFileName)
{
  CGameUIDefinition *p_m_GameUIDef; // esi
  char v6; // bl
  CDmxElement *ppRoot; // [esp+8h] [ebp-4h] BYREF

  BeginDMXContext();
  ppRoot = nullptr;
  if ( UnserializeDMX(buf, &ppRoot, pFileName) )
  {
    p_m_GameUIDef = &this->m_GameUIDef;
    v6 = CGameUIDefinition::Unserialize(this: p_m_GameUIDef, pElement: ppRoot);
    CleanupDMX(pRoot: ppRoot);
    if ( v6 != 0 )
    {
      CGameUIDefinition::InitializeScripts(this: p_m_GameUIDef);
      EndDMXContext(bDecommitMemory: true);
      return 1;
    }
    else
    {
      EndDMXContext(bDecommitMemory: true);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Unable to read game UI config %s! UtlBuffer is the wrong type!\n", pFileName);
    EndDMXContext(bDecommitMemory: true);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C4E0
// Name: public: virtual bool CGameUISystem::ExecuteScript(class KeyValues __near *,class KeyValues __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUISystem::ExecuteScript(CGameUISystem *this, KeyValues *kvEvent, KeyValues **ppResult)
{
  return CGameUIDefinition::ExecuteScript(this: &this->m_GameUIDef, args: kvEvent, ppResult);
}

//------------------------------------------------------------------------------
// Address: 0x0041C4F0
// Name: public: virtual void CGameUISystem::SetStageSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::SetStageSize(CGameUISystem *this, int nWide, int nTall)
{
  CGameUIDefinition::SetStageSize(this: &this->m_GameUIDef, nWide, nTall);
}

//------------------------------------------------------------------------------
// Address: 0x0041C500
// Name: public: virtual void CGameUISystem::GetStageSize(class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::GetStageSize(CGameUISystem *this, Vector2D *stageSize)
{
  CGameUIDefinition::GetStageSize(this: &this->m_GameUIDef, stageSize);
}

//------------------------------------------------------------------------------
// Address: 0x0041C610
// Name: bool KeyValuesDumpAsDevMsg(class KeyValues __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl KeyValuesDumpAsDevMsg(KeyValues *pKeyValues, int nIndentLevel, int nDeveloperLevel)
{
  CKeyValuesDumpContextAsDevMsg ctx; // [esp+0h] [ebp-Ch] BYREF
  int v5; // [esp+8h] [ebp-4h]

  ctx.m_nDeveloperLevel = (int)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v5 = nDeveloperLevel;
  return KeyValues::Dump(this: pKeyValues, pDump: (IKeyValuesDumpContext *)&ctx.m_nDeveloperLevel, nIndentLevel);
}

//------------------------------------------------------------------------------
// Address: 0x0041C640
// Name: public: virtual bool CGameUISystem::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUISystem::Init(CGameUISystem *this, KeyValues *kvLoadSettings)
{
  const char *v3; // eax
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v6; // [esp+8h] [ebp-4h]

  v3 = (const char *)this->GetName(this);
  DevMsg(a1: "CGameUISystem[%p]::Init( name = %s )\n", this, v3);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v6 = 1;
  KeyValues::Dump(this: kvLoadSettings, &pDump, nIndentLevel: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C690
// Name: private: void CGameUISystem::RenderDynamicLayer(struct LayerRenderLists_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::RenderDynamicLayer(
        CGameUISystem *this,
        LayerRenderLists_t *renderList,
        int geometryIndex)
{
  int v3; // ebx
  int v4; // edi
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v5; // eax
  int v6; // esi
  unsigned int TriangleCount; // eax
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // edi
  IMesh *m_VertexSize_Position; // edi
  int v11; // esi
  int m_Size; // eax
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v13; // ebp
  int v14; // ebx
  int m_nTotalIndexCount; // ecx
  int v16; // edi
  int v17; // esi
  CRenderGeometry *v18; // eax
  Vector2D *m_pMemory; // eax
  float y; // xmm0_4
  double x; // st7
  float *m_pCurrNormal; // eax
  unsigned __int16 v23; // dx
  Vector2D *v24; // eax
  double v25; // st7
  float v26; // xmm0_4
  float *v27; // eax
  bool v28; // zf
  MaterialPrimitiveType_t v29; // esi
  int v30; // eax
  CMatRenderContextPtr pRenderContext; // [esp+34h] [ebp-1F4h]
  CMatRenderContextPtr pRenderContexta; // [esp+34h] [ebp-1F4h]
  IMesh *pMesh; // [esp+38h] [ebp-1F0h]
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-1ECh] BYREF

  v3 = geometryIndex;
  v4 = 0;
  v5 = &renderList->m_RenderGeometryLists.m_Memory.m_pMemory[geometryIndex];
  v6 = 0;
  if ( v5->m_Size > 0 )
  {
    pRenderContext.m_pObject = nullptr;
    do
    {
      TriangleCount = CRenderGeometry::GetTriangleCount(this: (vgui::Panel *)((char *)pRenderContext.m_pObject
                                                                            + (unsigned int)v5->m_Memory.m_pMemory));
      pRenderContext.m_pObject += 25;
      v6 += TriangleCount;
      ++v4;
      v5 = &renderList->m_RenderGeometryLists.m_Memory.m_pMemory[v3];
    }
    while ( v4 < v5->m_Size );
    if ( v6 != 0 && renderList->m_pMaterial != nullptr )
    {
      v8 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
      v9 = v8;
      pMesh = (IMesh *)v8;
      if ( v8 != nullptr )
        v8->BeginRender(this: v8);
      m_VertexSize_Position = v9->GetDynamicMesh(
                                this: v9,
                                a2: true,
                                a3: nullptr,
                                a4: nullptr,
                                a5: renderList->m_pMaterial);
      meshBuilder.m_VertexSize_Position = (int)m_VertexSize_Position;
      if ( m_VertexSize_Position != nullptr )
      {
        CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight);
        meshBuilder.m_Type = (MaterialPrimitiveType_t)m_VertexSize_Position;
        LOBYTE(meshBuilder.m_IndexBuilder.m_pIndices) = 1;
        *(_DWORD *)&meshBuilder.m_bGenerateIndices = 2;
        v11 = 3 * v6;
        m_VertexSize_Position->SetPrimitiveType(this: m_VertexSize_Position, a2: MATERIAL_TRIANGLES);
        (*(void (__thiscall **)(MaterialPrimitiveType_t, int, int, int *, _DWORD))(*(_DWORD *)meshBuilder.m_Type + 68))(
          a1: meshBuilder.m_Type,
          a2: v11,
          a3: v11,
          a4: &meshBuilder.m_VertexSize_BoneWeight,
          a5: 0);
        meshBuilder.m_IndexBuilder.m_nIndexOffset = 0;
        LOBYTE(meshBuilder.m_VertexBuilder.m_VertexSize_Position) = 0;
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = (int)&m_VertexSize_Position->IIndexBuffer;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_IndexBuilder.m_nOffset = meshBuilder.MeshDesc_t::IndexDesc_t::m_nOffset;
        meshBuilder.m_IndexBuilder.m_nIndexCount = v11;
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = (IIndexBuffer *)meshBuilder.m_pMesh;
        CVertexBuilder::AttachBegin(
          this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight,
          pMesh: m_VertexSize_Position,
          nMaxVertexCount: v11,
          desc: (const MeshDesc_t *)&meshBuilder.m_VertexSize_BoneWeight);
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        CVertexBuilder::Reset(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
        m_Size = renderList->m_RenderGeometryLists.m_Memory.m_pMemory[v3].m_Size;
        v13 = &renderList->m_RenderGeometryLists.m_Memory.m_pMemory[v3];
        v14 = 0;
        if ( m_Size > 0 )
        {
          m_nTotalIndexCount = meshBuilder.m_IndexBuilder.m_nTotalIndexCount;
          v16 = 0;
          pRenderContexta.m_pObject = (IMatRenderContext *)m_Size;
          do
          {
            v17 = 0;
            v18 = &v13->m_Memory.m_pMemory[v16];
            if ( v18->m_Positions.m_Size > 0 )
            {
              do
              {
                m_pMemory = v18->m_Positions.m_Memory.m_pMemory;
                y = m_pMemory[v17].y;
                x = m_pMemory[v17].x;
                m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
                m_pCurrNormal[1] = y;
                m_pCurrNormal[2] = 0.0;
                HIBYTE(v23) = HIBYTE(*(_DWORD *)&v13->m_Memory.m_pMemory[v16].m_VertexColors.m_Memory.m_pMemory[v17]);
                LOBYTE(v23) = v13->m_Memory.m_pMemory[v16].m_VertexColors.m_Memory.m_pMemory[v17];
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (unsigned __int8)BYTE2(*(_DWORD *)&v13->m_Memory.m_pMemory[v16].m_VertexColors.m_Memory.m_pMemory[v17])
                                                                          | (((unsigned __int8)BYTE1(*(_DWORD *)&v13->m_Memory.m_pMemory[v16].m_VertexColors.m_Memory.m_pMemory[v17])
                                                                            | (v23 << 8)) << 8);
                v24 = v13->m_Memory.m_pMemory[v16].m_TextureCoords.m_Memory.m_pMemory;
                v25 = v24[v17].x;
                v26 = v24[v17].y;
                v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v25;
                *++v27 = v26;
                v27[1] = 0.0;
                CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
                ++v17;
                v18 = &v13->m_Memory.m_pMemory[v16];
              }
              while ( v17 < v18->m_Positions.m_Size );
              m_nTotalIndexCount = meshBuilder.m_IndexBuilder.m_nTotalIndexCount;
            }
            *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * m_nTotalIndexCount) = v14
                                                                                      + LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex);
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
            *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = v14 + LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + 1;
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
            *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = v14 + LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + 2;
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
            *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = v14 + LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex);
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
            *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = v14 + LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + 2;
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
            *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = v14 + LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + 3;
            m_nTotalIndexCount = (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer
                               + meshBuilder.m_IndexBuilder.m_nTotalIndexCount;
            v14 += 4;
            ++v16;
            v28 = pRenderContexta.m_pObject-- == (IMatRenderContext *)1;
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount = m_nTotalIndexCount;
            meshBuilder.m_IndexBuilder.m_nIndexOffset = m_nTotalIndexCount;
          }
          while ( !v28 );
          m_VertexSize_Position = (IMesh *)meshBuilder.m_VertexSize_Position;
        }
        if ( LOBYTE(meshBuilder.m_IndexBuilder.m_pIndices) != 0 )
        {
          v29 = *(_DWORD *)&meshBuilder.m_bGenerateIndices;
          v30 = CMeshBuilder::IndicesFromVertices(
                  this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight,
                  type: *(MaterialPrimitiveType_t *)&meshBuilder.m_bGenerateIndices,
                  nVertexCount: meshBuilder.m_VertexBuilder.m_nCurrentVertex);
          CIndexBuilder::GenerateIndices(
            this: (CIndexBuilder *)&meshBuilder.m_IndexBuilder.m_nOffset,
            primitiveType: v29,
            nIndexCount: v30);
        }
        (*(void (__thiscall **)(MaterialPrimitiveType_t, int, int, int *))(*(_DWORD *)meshBuilder.m_Type + 80))(
          a1: meshBuilder.m_Type,
          a2: meshBuilder.m_VertexBuilder.m_nCurrentVertex,
          a3: meshBuilder.m_IndexBuilder.m_nIndexOffset,
          a4: &meshBuilder.m_VertexSize_BoneWeight);
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
        *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify = 0;
        meshBuilder.m_VertexBuilder.m_NumBoneWeights = -1;
        meshBuilder.m_Type = MATERIAL_POINTS;
        m_VertexSize_Position->Draw_2(this: m_VertexSize_Position, a2: -1, a3: 0);
        if ( *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify != 0
          && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder.m_VertexBuilder.m_bModify + 8))(a1: *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify) != 0 )
        {
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder.m_VertexBuilder.m_bModify + 16))(a1: *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify);
        }
        if ( meshBuilder.m_IndexBuilder.m_nMaxIndexCount != 0
          && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)meshBuilder.m_IndexBuilder.m_nMaxIndexCount + 8))(a1: meshBuilder.m_IndexBuilder.m_nMaxIndexCount) != 0 )
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)meshBuilder.m_IndexBuilder.m_nMaxIndexCount + 16))(a1: meshBuilder.m_IndexBuilder.m_nMaxIndexCount);
        }
      }
      ((void (__thiscall *)(IMesh *))pMesh->BeginCastBuffer)(a1: pMesh);
      pMesh->GetVertexFormat(this: pMesh);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CB10
// Name: private: void CGameUISystem::RenderTextLayer(class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameUISystem::RenderTextLayer(
        CGameUISystem *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *renderGeometry)
{
  int v4; // ebx
  int m_VertexSize_Position; // ebp
  int v6; // eax
  IMesh *m_pObject; // esi
  CRenderGeometry *m_pMemory; // ecx
  int v9; // ebp
  int v10; // esi
  CRenderGeometry *i; // eax
  float y; // xmm0_4
  double x; // st7
  float *m_pCurrNormal; // eax
  color32_s *v15; // eax
  unsigned __int16 v16; // dx
  Vector2D *v17; // eax
  double v18; // st7
  float v19; // xmm0_4
  float *v20; // eax
  MaterialPrimitiveType_t v21; // esi
  int v22; // eax
  CMatRenderContextPtr pRenderContext; // [esp+14h] [ebp-1F0h]
  CMeshBuilder meshBuilder; // [esp+18h] [ebp-1ECh] BYREF

  v4 = 0;
  if ( renderGeometry->m_Size != 0 )
  {
    m_VertexSize_Position = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                              a1: g_pMaterialSystem,
                              a2);
    meshBuilder.m_VertexSize_BoneWeight = m_VertexSize_Position;
    if ( m_VertexSize_Position != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)m_VertexSize_Position + 8))(a1: m_VertexSize_Position);
    v6 = ((int (__thiscall *)(CGameUISystemSurface *, int, int))g_pGameUISystemSurface->GetMaterial)(
           a1: g_pGameUISystemSurface,
           a2: renderGeometry->m_Memory.m_pMemory->m_SheetSequenceNumber,
           a3);
    m_pObject = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, int))(*(_DWORD *)m_VertexSize_Position + 228))(
                           a1: m_VertexSize_Position,
                           a2: 1,
                           a3: 0,
                           a4: 0,
                           a5: v6);
    pRenderContext.m_pObject = (IMatRenderContext *)m_pObject;
    if ( m_pObject != nullptr )
    {
      CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight);
      CMeshBuilder::Begin(
        this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight,
        pMesh: m_pObject,
        type: 7,
        numPrimitives: renderGeometry->m_Size);
      if ( renderGeometry->m_Size > 0 )
      {
        m_pMemory = renderGeometry->m_Memory.m_pMemory;
        v9 = 0;
        do
        {
          v10 = 0;
          for ( i = &m_pMemory[v9]; v10 < i->m_Positions.m_Size; i = &renderGeometry->m_Memory.m_pMemory[v9] )
          {
            y = i->m_Positions.m_Memory.m_pMemory[v10].y;
            x = i->m_Positions.m_Memory.m_pMemory[v10].x;
            m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
            *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
            m_pCurrNormal[1] = y;
            m_pCurrNormal[2] = 0.0;
            v15 = &renderGeometry->m_Memory.m_pMemory[v9].m_VertexColors.m_Memory.m_pMemory[v10];
            HIBYTE(v16) = v15->a;
            LOBYTE(v16) = v15->r;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v15->b | ((v15->g | (v16 << 8)) << 8);
            v17 = renderGeometry->m_Memory.m_pMemory[v9].m_TextureCoords.m_Memory.m_pMemory;
            v18 = v17[v10].x;
            v19 = v17[v10].y;
            v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v18;
            *++v20 = v19;
            v20[1] = 0.0;
            CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
            m_pMemory = renderGeometry->m_Memory.m_pMemory;
            ++v10;
          }
          ++v4;
          ++v9;
        }
        while ( v4 < renderGeometry->m_Size );
        m_VertexSize_Position = meshBuilder.m_VertexSize_Position;
        m_pObject = (IMesh *)pRenderContext.m_pObject;
      }
      if ( LOBYTE(meshBuilder.m_IndexBuilder.m_pIndices) != 0 )
      {
        v21 = *(_DWORD *)&meshBuilder.m_bGenerateIndices;
        v22 = CMeshBuilder::IndicesFromVertices(
                this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight,
                type: *(MaterialPrimitiveType_t *)&meshBuilder.m_bGenerateIndices,
                nVertexCount: meshBuilder.m_VertexBuilder.m_nCurrentVertex);
        CIndexBuilder::GenerateIndices(
          this: (CIndexBuilder *)&meshBuilder.m_IndexBuilder.m_nOffset,
          primitiveType: v21,
          nIndexCount: v22);
        m_VertexSize_Position = meshBuilder.m_VertexSize_Position;
        m_pObject = (IMesh *)pRenderContext.m_pObject;
      }
      (*(void (__thiscall **)(MaterialPrimitiveType_t, int, int, int *))(*(_DWORD *)meshBuilder.m_Type + 80))(
        a1: meshBuilder.m_Type,
        a2: meshBuilder.m_VertexBuilder.m_nCurrentVertex,
        a3: meshBuilder.m_IndexBuilder.m_nIndexOffset,
        a4: &meshBuilder.m_VertexSize_BoneWeight);
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify = 0;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = -1;
      meshBuilder.m_Type = MATERIAL_POINTS;
      m_pObject->Draw_2(this: m_pObject, a2: -1, a3: 0);
      if ( *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify != 0
        && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder.m_VertexBuilder.m_bModify + 8))(a1: *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify) != 0 )
      {
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder.m_VertexBuilder.m_bModify + 16))(a1: *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify);
      }
      if ( meshBuilder.m_IndexBuilder.m_nMaxIndexCount != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)meshBuilder.m_IndexBuilder.m_nMaxIndexCount + 8))(a1: meshBuilder.m_IndexBuilder.m_nMaxIndexCount) != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)meshBuilder.m_IndexBuilder.m_nMaxIndexCount + 16))(a1: meshBuilder.m_IndexBuilder.m_nMaxIndexCount);
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)m_VertexSize_Position + 12))(a1: m_VertexSize_Position);
      (*(void (__thiscall **)(int))(*(_DWORD *)m_VertexSize_Position + 4))(a1: m_VertexSize_Position);
    }
    else
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)m_VertexSize_Position + 12))(a1: m_VertexSize_Position);
      (*(void (__thiscall **)(int))(*(_DWORD *)m_VertexSize_Position + 4))(a1: m_VertexSize_Position);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CDA0
// Name: private: void CGameUISystem::GenerateUIMesh(class IMatRenderContext __near *,class IMesh __near *,class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>> __near &,class CSheet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::GenerateUIMesh(
        CGameUISystem *this,
        IMatRenderContext *pRenderContext,
        IMesh *pMesh,
        CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *renderGeometry,
        CSheet *pSheet)
{
  int v5; // ebp
  int v6; // esi
  int v7; // edi
  int m_SheetSequenceNumber; // esi
  CRenderGeometry *v9; // ecx
  int m_tms; // edi
  float flAge; // xmm0_4
  SheetSequenceSample_t *SampleForSequence; // esi
  int v13; // edi
  CRenderGeometry *v14; // eax
  Vector2D *m_pMemory; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float *m_pCurrNormal; // eax
  float v19; // xmm1_4
  float m_fLeft_U0; // xmm3_4
  float m_fRight_U0; // xmm1_4
  Vector2D *v22; // ecx
  float m_fTop_V0; // xmm4_4
  float v24; // xmm0_4
  float *v25; // eax
  float m_fBottom_V0; // xmm2_4
  float v27; // xmm2_4
  float *v28; // eax
  Vector2D *v29; // edx
  float *v30; // eax
  float v31; // xmm0_4
  bool v32; // zf
  int m_nCurrentVertex; // eax
  float flAgeScale; // [esp+3Ch] [ebp-238h]
  int v35; // [esp+58h] [ebp-21Ch]
  color32_s v36; // [esp+58h] [ebp-21Ch]
  color32_s v37; // [esp+58h] [ebp-21Ch]
  int nIndex; // [esp+5Ch] [ebp-218h]
  int sampleHeight; // [esp+60h] [ebp-214h]
  DmeTime_t flY; // [esp+68h] [ebp-20Ch] BYREF
  float flX; // [esp+6Ch] [ebp-208h]
  float sampleWidth; // [esp+70h] [ebp-204h]
  CMeshBuilder meshBuilder; // [esp+74h] [ebp-200h] BYREF
  int x; // [esp+260h] [ebp-14h] BYREF
  int v45; // [esp+264h] [ebp-10h] BYREF
  int y; // [esp+268h] [ebp-Ch] BYREF
  int width; // [esp+26Ch] [ebp-8h] BYREF
  _BYTE v48[4]; // [esp+270h] [ebp-4h] BYREF

  v5 = 0;
  v6 = 0;
  v35 = 0;
  if ( renderGeometry->m_Size > 0 )
  {
    v7 = 0;
    do
    {
      v35 += CRenderGeometry::GetTriangleCount(this: (vgui::Panel *)&renderGeometry->m_Memory.m_pMemory[v7]);
      ++v6;
      ++v7;
    }
    while ( v6 < renderGeometry->m_Size );
  }
  memset(&meshBuilder.m_IndexBuilder.m_nMaxIndexCount, 0, 12);
  meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nBufferOffset = 0;
  meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = -1;
  *(_DWORD *)&meshBuilder.m_IndexBuilder.m_bModify = 0;
  *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify = 0;
  meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = -1;
  *((_DWORD *)&meshBuilder.m_VertexBuilder + 60) = 0;
  memset(&meshBuilder.m_VertexBuilder.m_nVertexCount, 0, 12);
  meshBuilder.m_VertexBuilder.m_nBufferOffset = 0;
  meshBuilder.m_VertexBuilder.m_NumBoneWeights = -1;
  meshBuilder.m_Type = (MaterialPrimitiveType_t)pMesh;
  LOBYTE(meshBuilder.m_IndexBuilder.m_pIndices) = 1;
  *(_DWORD *)&meshBuilder.m_bGenerateIndices = 2;
  pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLES);
  (*(void (__thiscall **)(MaterialPrimitiveType_t, int, int, int *, _DWORD))(*(_DWORD *)meshBuilder.m_Type + 68))(
    a1: meshBuilder.m_Type,
    a2: 6 * v35,
    a3: 6 * v35,
    a4: &meshBuilder.m_VertexSize_BoneWeight,
    a5: 0);
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = (int)&pMesh->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nOffset = meshBuilder.MeshDesc_t::IndexDesc_t::m_nOffset;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 6 * v35;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = (IIndexBuffer *)meshBuilder.m_pMesh;
  *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify = pMesh;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = 0;
  LOBYTE(meshBuilder.m_VertexBuilder.m_VertexSize_Position) = 0;
  qmemcpy(&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight, &meshBuilder.m_VertexSize_BoneWeight, 164);
  meshBuilder.m_VertexBuilder.m_nVertexCount = 6 * v35;
  meshBuilder.m_VertexBuilder.m_pPosition = meshBuilder.m_pPosition != nullptr ? (float *)2 : nullptr;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
  LOBYTE(meshBuilder.m_VertexBuilder.m_nMaxVertexCount) = 0;
  if ( meshBuilder.m_VertexBuilder.m_nBufferFirstVertex == -1 )
  {
    meshBuilder.m_VertexBuilder.m_nBufferOffset = 0;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = (unsigned int)meshBuilder.m_pIndices;
    *((_DWORD *)&meshBuilder.m_VertexBuilder + 60) = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
  }
  meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
  CVertexBuilder::Reset(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
  pRenderContext->GetViewport(this: pRenderContext, a2: &v45, a3: &width, a4: (int *)v48, a5: &x);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "meshBuilder",
    a3: 0,
    a4: "meshBuilder",
    a5: false,
    a6: 4);
  sampleHeight = 0;
  if ( renderGeometry->m_Size > 0 )
  {
    nIndex = renderGeometry->m_Size;
    do
    {
      m_SheetSequenceNumber = renderGeometry->m_Memory.m_pMemory[v5].m_SheetSequenceNumber;
      v9 = &renderGeometry->m_Memory.m_pMemory[v5];
      if ( v9->m_bAnimate )
      {
        CRenderGeometry::GetAnimStartTime(this: v9, result: &flY);
        m_tms = flY.m_tms;
        flAge = (float)(CGameUISystemMgr::GetTime(this: g_pGameUISystemMgrImpl, result: (DmeTime_t *)&y)->m_tms - m_tms)
              * 0.000099999997;
        flAgeScale = renderGeometry->m_Memory.m_pMemory[v5].m_AnimationRate
                   * 512.0
                   / pSheet->m_SheetInfo.m_Memory.m_pMemory[m_SheetSequenceNumber].m_flFrameSpan;
        SampleForSequence = (SheetSequenceSample_t *)CSheet::GetSampleForSequence(
                                                       this: pSheet,
                                                       flAge,
                                                       flAgeScale,
                                                       nSequence: m_SheetSequenceNumber,
                                                       bForceLoop: true);
      }
      else
      {
        SampleForSequence = pSheet->m_SheetInfo.m_Memory.m_pMemory[m_SheetSequenceNumber].m_pSamples;
      }
      v13 = 0;
      v14 = &renderGeometry->m_Memory.m_pMemory[v5];
      if ( v14->m_Positions.m_Size > 0 )
      {
        do
        {
          m_pMemory = v14->m_Positions.m_Memory.m_pMemory;
          v16 = m_pMemory[v13].x;
          v17 = m_pMemory[v13].y;
          m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
          *meshBuilder.m_VertexBuilder.m_pCurrNormal = v16;
          m_pCurrNormal[1] = v17;
          m_pCurrNormal[2] = 0.0;
          v36 = renderGeometry->m_Memory.m_pMemory[v5].m_VertexColors.m_Memory.m_pMemory[v13];
          flX = v17;
          v19 = 1.0 - SampleForSequence->m_fBlendFactor;
          sampleWidth = v16;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v36.b
                                                                    | ((v36.g
                                                                      | ((v36.r
                                                                        | ((unsigned __int8)(int)(float)((float)HIBYTE(*(unsigned int *)&v36) * v19) << 8)) << 8)) << 8);
          m_fLeft_U0 = SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
          m_fRight_U0 = SampleForSequence->m_TextureCoordData[0].m_fRight_U0;
          v22 = renderGeometry->m_Memory.m_pMemory[v5].m_TextureCoords.m_Memory.m_pMemory;
          m_fTop_V0 = SampleForSequence->m_TextureCoordData[0].m_fTop_V0;
          v24 = v22[v13].y;
          v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          m_fBottom_V0 = SampleForSequence->m_TextureCoordData[0].m_fBottom_V0;
          *(float *)&meshBuilder.m_VertexSize_Position = m_fRight_U0
                                                       - SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
          v27 = m_fBottom_V0 - m_fTop_V0;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float)((float)(m_fRight_U0 - m_fLeft_U0) * v22[v13].x)
                                                          + m_fLeft_U0;
          *++v25 = (float)(v24 * v27) + m_fTop_V0;
          v25[1] = 0.0;
          CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
          v28 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
          *meshBuilder.m_VertexBuilder.m_pCurrNormal = sampleWidth;
          *++v28 = flX;
          v28[1] = 0.0;
          v37 = renderGeometry->m_Memory.m_pMemory[v5].m_VertexColors.m_Memory.m_pMemory[v13];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v37.b
                                                                    | ((v37.g
                                                                      | ((v37.r
                                                                        | ((unsigned __int8)(int)(float)((float)HIBYTE(*(unsigned int *)&v37) * SampleForSequence->m_fBlendFactor) << 8)) << 8)) << 8);
          v29 = renderGeometry->m_Memory.m_pMemory[v5].m_TextureCoords.m_Memory.m_pMemory;
          v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          v31 = (float)(v29[v13].y * v27) + SampleForSequence->m_TextureCoordData[0].m_fTop_V1;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float)(v29[v13].x
                                                                  * *(float *)&meshBuilder.m_VertexSize_Position)
                                                          + SampleForSequence->m_TextureCoordData[0].m_fLeft_U1;
          *++v30 = v31;
          v30[1] = 0.0;
          CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
          ++v13;
          v14 = &renderGeometry->m_Memory.m_pMemory[v5];
        }
        while ( v13 < v14->m_Positions.m_Size );
      }
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = sampleHeight + LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex);
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 2;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 4;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = sampleHeight + LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex);
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 4;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 6;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 1;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 3;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 5;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 1;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 5;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      *(_WORD *)(meshBuilder.m_IndexBuilder.m_nOffset + 2 * meshBuilder.m_IndexBuilder.m_nTotalIndexCount) = LOWORD(meshBuilder.m_IndexBuilder.m_nCurrentIndex) + sampleHeight + 7;
      ++v5;
      v32 = nIndex-- == 1;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount += (int)meshBuilder.m_IndexBuilder.m_pIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_IndexBuilder.m_nTotalIndexCount;
      sampleHeight += 8;
    }
    while ( !v32 );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  if ( LOBYTE(meshBuilder.m_IndexBuilder.m_pIndices) != 0 )
  {
    switch ( *(_DWORD *)&meshBuilder.m_bGenerateIndices )
    {
      case 4:
        m_nCurrentVertex = 2 * meshBuilder.m_VertexBuilder.m_nCurrentVertex - 2;
        break;
      case 5:
        m_nCurrentVertex = 2 * meshBuilder.m_VertexBuilder.m_nCurrentVertex;
        break;
      case 6:
        m_nCurrentVertex = 3 * meshBuilder.m_VertexBuilder.m_nCurrentVertex - 6;
        break;
      case 7:
        m_nCurrentVertex = 6 * meshBuilder.m_VertexBuilder.m_nCurrentVertex / 4;
        break;
      case 0xA:
        m_nCurrentVertex = 0;
        break;
      default:
        m_nCurrentVertex = meshBuilder.m_VertexBuilder.m_nCurrentVertex;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: (CIndexBuilder *)&meshBuilder.m_IndexBuilder.m_nOffset,
      primitiveType: *(MaterialPrimitiveType_t *)&meshBuilder.m_bGenerateIndices,
      nIndexCount: m_nCurrentVertex);
  }
  (*(void (__thiscall **)(MaterialPrimitiveType_t, int, int, int *))(*(_DWORD *)meshBuilder.m_Type + 80))(
    a1: meshBuilder.m_Type,
    a2: meshBuilder.m_VertexBuilder.m_nCurrentVertex,
    a3: meshBuilder.m_IndexBuilder.m_nIndexOffset,
    a4: &meshBuilder.m_VertexSize_BoneWeight);
}

//------------------------------------------------------------------------------
// Address: 0x0041D820
// Name: private: void CGameUISystem::RenderStaticLayer(struct LayerRenderLists_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::RenderStaticLayer(
        CGameUISystem *this,
        LayerRenderLists_t *renderList,
        int geometryIndex)
{
  int v3; // edi
  int v4; // ebp
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v5; // eax
  int v6; // esi
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  IMesh *v9; // ebp
  int v10; // [esp+14h] [ebp-8h]

  v3 = geometryIndex;
  v4 = 0;
  v5 = &renderList->m_RenderGeometryLists.m_Memory.m_pMemory[geometryIndex];
  v6 = 0;
  v10 = 0;
  if ( v5->m_Size > 0 )
  {
    do
    {
      v10 += CRenderGeometry::GetTriangleCount(this: (vgui::Panel *)&v5->m_Memory.m_pMemory[v4]);
      ++v6;
      v5 = &renderList->m_RenderGeometryLists.m_Memory.m_pMemory[v3];
      ++v4;
    }
    while ( v6 < v5->m_Size );
    if ( v10 != 0 && renderList->m_pSheet != nullptr )
    {
      v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
      v8 = v7;
      if ( v7 != nullptr )
        v7->BeginRender(this: v7);
      v8->Bind(this: v8, a2: renderList->m_pMaterial, a3: nullptr);
      v9 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      CGameUISystem::GenerateUIMesh(
        this,
        pRenderContext: v8,
        pMesh: v9,
        renderGeometry: &renderList->m_RenderGeometryLists.m_Memory.m_pMemory[v3],
        pSheet: renderList->m_pSheet);
      v9->Draw_2(this: v9, a2: -1, a3: 0);
      v8->EndRender(this: v8);
      v8->Release(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EAE0
// Name: private: void CGameUISystem::RenderTextLayer(class IRenderContext __near *,class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::RenderTextLayer(
        CGameUISystem *this,
        IRenderContext *pRenderContext,
        CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *renderGeometry)
{
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v3; // esi
  const ResourceBinding_t<CTextureBits> *v4; // eax
  bool v5; // cc
  CRenderGeometry *m_pMemory; // edx
  int m_nVertexCount; // edi
  int v8; // ecx
  CRenderGeometry *v9; // eax
  float x; // xmm1_4
  Vector2D *v11; // eax
  float y; // xmm0_4
  float v13; // xmm3_4
  GameUIVertex_t *v14; // eax
  GameUIVertex_t *v15; // eax
  int v16; // esi
  IRenderDevice *v17; // eax
  const ResourceBinding_t<CRenderBufferBits> *(__thiscall *CreateDynamicIndexBuffer)(IRenderContext *, const BufferDesc_t *, int); // edx
  int v19; // edi
  const ResourceBinding_t<CRenderBufferBits> *v20; // eax
  int v21; // edi
  bool v22; // al
  int v23; // ecx
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v24; // esi
  BOOL v25; // edx
  int v26; // eax
  __int16 v27; // di
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  void (__thiscall *UnlockIndexBuffer)(IRenderContext *, const ResourceBinding_t<CRenderBufferBits> *, int, LockDesc_t *); // edx
  const ResourceBinding_t<CRenderBufferBits> *v34; // esi
  IRenderDevice *v35; // eax
  const ResourceBinding_t<CRenderBufferBits> *m_hVertexBuffer; // eax
  IRenderDevice *v37; // eax
  int v38; // [esp+21Ch] [ebp-7Ch]
  int v39; // [esp+21Ch] [ebp-7Ch]
  GameUIVertex_t *v40; // [esp+220h] [ebp-78h] BYREF
  int v41; // [esp+224h] [ebp-74h] BYREF
  CInterlockedIntT<int> *p_m_nRefCount; // [esp+228h] [ebp-70h]
  _DWORD v43[8]; // [esp+22Ch] [ebp-6Ch] BYREF
  const ResourceBinding_t<CRenderBufferBits> *v44; // [esp+24Ch] [ebp-4Ch]
  int v45; // [esp+254h] [ebp-44h]
  CDynamicVertexData<GameUIVertex_t> v46; // [esp+258h] [ebp-40h] BYREF

  v3 = renderGeometry;
  if ( renderGeometry->m_Size != 0 )
  {
    v4 = g_pGameUISystemSurface->GetTextureHandle(
           this: g_pGameUISystemSurface,
           a2: renderGeometry->m_Memory.m_pMemory->m_SheetSequenceNumber);
    pRenderContext->BindTexture(this: pRenderContext, a2: 0, a3: v4, a4: RENDER_PIXEL_SHADER);
    CDynamicVertexData<GameUIVertex_t>::CDynamicVertexData<GameUIVertex_t>(
      this: &v46,
      pRenderContext,
      nVertexCount: 4 * renderGeometry->m_Size,
      pDebugName: "gamelayer",
      pBudgetGroup: "game_controls");
    CDynamicVertexData<GameUIVertex_t>::Lock(this: &v46);
    v5 = renderGeometry->m_Size <= 0;
    v40 = nullptr;
    if ( v5 )
    {
      m_nVertexCount = v46.m_nVertexCount;
    }
    else
    {
      m_pMemory = renderGeometry->m_Memory.m_pMemory;
      v38 = 0;
      m_nVertexCount = v46.m_nVertexCount;
      do
      {
        v8 = 0;
        v9 = &m_pMemory[v38];
        if ( m_pMemory[v38].m_Positions.m_Size > 0 )
        {
          do
          {
            x = v9->m_Positions.m_Memory.m_pMemory[v8].x;
            v46.m_Scratch.m_vecPosition.y = v9->m_Positions.m_Memory.m_pMemory[v8].y;
            v46.m_Scratch.m_vecPosition.z = 0.0;
            v46.m_Scratch.m_vecPosition.x = x;
            v46.m_Scratch.m_color = (VertexColor_t)v9->m_VertexColors.m_Memory.m_pMemory[v8];
            v11 = v9->m_TextureCoords.m_Memory.m_pMemory;
            y = v11[v8].y;
            v13 = v11[v8].x;
            v14 = v46.m_pMemory;
            v46.m_Scratch.m_vecTexCoord.y = y;
            v46.m_Scratch.m_vecTexCoord.x = v13;
            v46.m_pMemory[m_nVertexCount].m_vecPosition.x = x;
            v15 = &v14[m_nVertexCount];
            v15->m_vecPosition.y = v46.m_Scratch.m_vecPosition.y;
            v15->m_vecPosition.z = v46.m_Scratch.m_vecPosition.z;
            v15->m_color = v46.m_Scratch.m_color;
            v15->m_vecTexCoord = v46.m_Scratch.m_vecTexCoord;
            m_pMemory = renderGeometry->m_Memory.m_pMemory;
            m_nVertexCount = v46.m_nVertexIncrement + v46.m_nVertexCount;
            ++v8;
            v9 = &renderGeometry->m_Memory.m_pMemory[v38];
            v46.m_nVertexCount += v46.m_nVertexIncrement;
          }
          while ( v8 < v9->m_Positions.m_Size );
          v3 = renderGeometry;
        }
        ++v38;
        v5 = (int)&v40->m_vecPosition.x + 1 < v3->m_Size;
        v40 = (GameUIVertex_t *)((char *)v40 + 1);
      }
      while ( v5 );
    }
    v40 = v46.m_pMemory;
    v46.m_pRenderContext->UnlockVertexBuffer(
      this: v46.m_pRenderContext,
      a2: v46.m_hVertexBuffer,
      a3: 24 * m_nVertexCount,
      a4: (LockDesc_t *)&v40);
    v46.m_pRenderContext->BindVertexBuffer(this: v46.m_pRenderContext, a2: 0, a3: v46.m_hVertexBuffer, a4: 0, a5: 24);
    v16 = 6 * v3->m_Size;
    v17 = pRenderContext->GetDevice(this: pRenderContext);
    v17->GetIndexBufferDesc(this: v17, a2: nullptr, a3: (BufferDesc_t *)v43);
    CreateDynamicIndexBuffer = pRenderContext->CreateDynamicIndexBuffer;
    v19 = v43[0] & 0x7FFFFFFF;
    v43[1] = 2;
    v43[0] = v16;
    v43[2] = "gamelayer";
    v43[3] = "game_controls";
    v20 = CreateDynamicIndexBuffer(this: pRenderContext, a2: (const BufferDesc_t *)v43, a3: 0);
    v21 = (v16 ^ v19) & 0x7FFFFFFF ^ v19;
    v44 = v20;
    v45 = v21;
    p_m_nRefCount = &v20->m_nRefCount;
    _InterlockedExchangeAdd(&v20->m_nRefCount.m_value, 1u);
    v22 = pRenderContext->LockIndexBuffer(
            this: pRenderContext,
            a2: v20,
            a3: 2 * ((2 * v21) >> 1),
            a4: (LockDesc_t *)&v41);
    v23 = v41;
    v24 = renderGeometry;
    v25 = v22;
    v26 = 0;
    v39 = 0;
    v40 = nullptr;
    if ( renderGeometry->m_Size > 0 )
    {
      do
      {
        v27 = v39;
        *(_WORD *)(v23 + 2 * v26) = v39;
        v39 += 4;
        v28 = v25 + v26;
        *(_WORD *)(v23 + 2 * v28) = v27 + 1;
        v29 = v25 + v28;
        *(_WORD *)(v23 + 2 * v29) = v27 + 2;
        v30 = v25 + v29;
        *(_WORD *)(v23 + 2 * v30) = v27;
        v31 = v25 + v30;
        *(_WORD *)(v23 + 2 * v31) = v27 + 2;
        v24 = renderGeometry;
        v32 = v25 + v31;
        *(_WORD *)(v23 + 2 * v32) = v27 + 3;
        v26 = v25 + v32;
        v5 = (int)&v40->m_vecPosition.x + 1 < renderGeometry->m_Size;
        v40 = (GameUIVertex_t *)((char *)v40 + 1);
      }
      while ( v5 );
      v21 = v45;
    }
    UnlockIndexBuffer = pRenderContext->UnlockIndexBuffer;
    v41 = v23;
    UnlockIndexBuffer(this: pRenderContext, a2: v44, a3: 2 * v26, a4: (LockDesc_t *)&v41);
    pRenderContext->BindIndexBuffer(this: pRenderContext, a2: v44, a3: 0);
    pRenderContext->DrawIndexed(this: pRenderContext, a2: RENDER_PRIM_TRIANGLES, a3: 0, a4: 6 * v24->m_Size, a5: 0);
    v34 = v44;
    if ( v44 != nullptr )
    {
      pRenderContext->DestroyDynamicIndexBuffer(this: pRenderContext, a2: v44);
      _InterlockedExchangeAdd(&p_m_nRefCount->m_value, 0xFFFFFFFF);
      v44 = nullptr;
      v34 = nullptr;
    }
    if ( v21 < 0 && v34 != nullptr )
    {
      _InterlockedExchangeAdd(&v34->m_nRefCount.m_value, 0xFFFFFFFF);
      v35 = pRenderContext->GetDevice(this: pRenderContext);
      v35->DestroyIndexBuffer(this: v35, a2: v34);
    }
    m_hVertexBuffer = v46.m_hVertexBuffer;
    if ( v46.m_hVertexBuffer != nullptr )
    {
      v46.m_pRenderContext->DestroyDynamicVertexBuffer(this: v46.m_pRenderContext, a2: v46.m_hVertexBuffer);
      _InterlockedExchangeAdd(&v46.m_hVertexBuffer->m_nRefCount.m_value, 0xFFFFFFFF);
      m_hVertexBuffer = nullptr;
      v46.m_hVertexBuffer = nullptr;
    }
    if ( *((int *)&v46.CVertexData<GameUIVertex_t> + 12) < 0 && m_hVertexBuffer != nullptr )
    {
      _InterlockedExchangeAdd(&m_hVertexBuffer->m_nRefCount.m_value, 0xFFFFFFFF);
      v37 = v46.m_pRenderContext->GetDevice(this: v46.m_pRenderContext);
      v37->DestroyVertexBuffer(this: v37, a2: v46.m_hVertexBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EEA0
// Name: private: void CGameUISystem::RenderStaticLayer(class IRenderContext __near *,struct LayerRenderLists_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::RenderStaticLayer(
        CGameUISystem *this,
        IRenderContext *pRenderContext,
        LayerRenderLists_t *renderList,
        int geometryIndex)
{
  LayerRenderLists_t *v4; // esi
  int v5; // edi
  int m_Size; // eax
  int v7; // ebx
  unsigned int TriangleCount; // eax
  CVTFTexture *v9; // ecx
  int v10; // edi
  int m_nVertexCount; // edi
  CRenderGeometry *v12; // esi
  DmeTime_t *Time; // eax
  CSheet *m_pSheet; // ecx
  SheetSequenceSample_t *SampleForSequence; // eax
  int j; // ecx
  float x; // xmm5_4
  Vector2D *m_pMemory; // edx
  float m_fTop_V0; // xmm4_4
  float m_fLeft_U0; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  GameUIVertex_t *v25; // edx
  Vector2D *v26; // edx
  float v27; // xmm2_4
  IRenderDevice *(__thiscall *GetDevice)(IRenderContext *); // eax
  int v29; // edi
  int v30; // eax
  const ResourceBinding_t<CRenderBufferBits> *(__thiscall *CreateDynamicIndexBuffer)(IRenderContext *, const BufferDesc_t *, int); // edx
  int v32; // esi
  const ResourceBinding_t<CRenderBufferBits> *v33; // eax
  int v34; // esi
  bool v35; // al
  GameUIVertex_t *v36; // ecx
  BOOL v37; // edx
  int v38; // eax
  __int16 v39; // si
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  const ResourceBinding_t<CRenderBufferBits> *v51; // esi
  void (__thiscall *UnlockIndexBuffer)(IRenderContext *, const ResourceBinding_t<CRenderBufferBits> *, int, LockDesc_t *); // edx
  const ResourceBinding_t<CRenderBufferBits> *m_hVertexBuffer; // eax
  IRenderDevice *v54; // eax
  float flAgeScale; // [esp+3ACh] [ebp-ACh]
  int nSequence; // [esp+3C8h] [ebp-90h]
  int nSequencea; // [esp+3C8h] [ebp-90h]
  unsigned int nSequenceb; // [esp+3C8h] [ebp-90h]
  unsigned int nSequencec; // [esp+3C8h] [ebp-90h]
  int i; // [esp+3CCh] [ebp-8Ch]
  int v61; // [esp+3CCh] [ebp-8Ch]
  int v62; // [esp+3CCh] [ebp-8Ch]
  GameUIVertex_t *m_tms; // [esp+3D0h] [ebp-88h] BYREF
  GameUIVertex_t *v64; // [esp+3D4h] [ebp-84h]
  GameUIVertex_t *v65; // [esp+3D8h] [ebp-80h] BYREF
  int v66; // [esp+3DCh] [ebp-7Ch]
  CInterlockedIntT<int> *p_m_nRefCount; // [esp+3E0h] [ebp-78h]
  DmeTime_t result; // [esp+3E4h] [ebp-74h] BYREF
  CDynamicVertexData<GameUIVertex_t> v69; // [esp+3E8h] [ebp-70h] BYREF
  _DWORD v70[4]; // [esp+428h] [ebp-30h] BYREF
  DmeTime_t v71; // [esp+438h] [ebp-20h] BYREF
  const ResourceBinding_t<CRenderBufferBits> *v72; // [esp+44Ch] [ebp-Ch]
  int v73; // [esp+454h] [ebp-4h]

  v4 = renderList;
  v5 = geometryIndex;
  m_Size = renderList->m_RenderGeometryLists.m_Memory.m_pMemory[geometryIndex].m_Size;
  v7 = 0;
  p_m_nRefCount = (CInterlockedIntT<int> *)(20 * geometryIndex);
  v64 = (GameUIVertex_t *)m_Size;
  if ( m_Size != 0 )
  {
    v66 = 0;
    nSequence = 0;
    if ( m_Size > 0 )
    {
      for ( i = m_Size; i != 0; --i )
      {
        TriangleCount = CRenderGeometry::GetTriangleCount(this: (vgui::Panel *)&renderList->m_RenderGeometryLists.m_Memory.m_pMemory[v5].m_Memory.m_pMemory[v7]);
        v9 = (CVTFTexture *)&renderList->m_RenderGeometryLists.m_Memory.m_pMemory[v5].m_Memory.m_pMemory[v7];
        v66 += TriangleCount + 2 * TriangleCount;
        nSequence += CFontAmalgam::GetCount(this: v9);
        ++v7;
      }
      if ( v66 != 0 )
      {
        renderList->m_hTexture.m_pBinding->m_nLastBindFrame = g_nResourceFrameCount;
        pRenderContext->BindTexture(
          this: pRenderContext,
          a2: 0,
          a3: renderList->m_hTexture.m_pBinding,
          a4: RENDER_PIXEL_SHADER);
        CDynamicVertexData<GameUIVertex_t>::CDynamicVertexData<GameUIVertex_t>(
          this: &v69,
          pRenderContext,
          nVertexCount: 2 * nSequence,
          pDebugName: "gamelayer",
          pBudgetGroup: "game_controls");
        v10 = (2 * *((_DWORD *)&v69.CVertexData<GameUIVertex_t> + 12)) >> 1;
        v69.m_nVertexIncrement = v69.m_pRenderContext->LockVertexBuffer(
                                   this: v69.m_pRenderContext,
                                   a2: v69.m_hVertexBuffer,
                                   a3: 24 * v10,
                                   a4: (LockDesc_t *)&v65);
        v69.m_nMaxVertexCount = v10 * v69.m_nVertexIncrement;
        m_nVertexCount = 0;
        v69.m_nVertexCount = 0;
        v69.m_pMemory = v65;
        v61 = 0;
        v65 = v64;
        while ( 1 )
        {
          v12 = (CRenderGeometry *)(v61
                                  + *(volatile int *)((char *)&p_m_nRefCount->m_value
                                                    + (unsigned int)v4->m_RenderGeometryLists.m_Memory.m_pMemory));
          nSequencea = v12->m_SheetSequenceNumber;
          if ( v12->m_bAnimate )
          {
            CRenderGeometry::GetAnimStartTime(this: v12, &result);
            m_tms = (GameUIVertex_t *)result.m_tms;
            Time = CGameUISystemMgr::GetTime(this: g_pGameUISystemMgrImpl, result: &v71);
            m_pSheet = renderList->m_pSheet;
            flAgeScale = v12->m_AnimationRate
                       * 512.0
                       / m_pSheet->m_SheetInfo.m_Memory.m_pMemory[nSequencea].m_flFrameSpan;
            SampleForSequence = (SheetSequenceSample_t *)CSheet::GetSampleForSequence(
                                                           this: m_pSheet,
                                                           flAge: (float)(Time->m_tms - (int)m_tms) * 0.000099999997,
                                                           flAgeScale,
                                                           nSequence: nSequencea,
                                                           bForceLoop: true);
            m_nVertexCount = v69.m_nVertexCount;
          }
          else
          {
            SampleForSequence = renderList->m_pSheet->m_SheetInfo.m_Memory.m_pMemory[v12->m_SheetSequenceNumber].m_pSamples;
          }
          for ( j = 0; j < v12->m_Positions.m_Size; v69.m_nVertexCount += v69.m_nVertexIncrement )
          {
            x = v12->m_Positions.m_Memory.m_pMemory[j].x;
            v69.m_Scratch.m_vecPosition.y = v12->m_Positions.m_Memory.m_pMemory[j].y;
            v69.m_Scratch.m_vecPosition.z = 0.0;
            v69.m_Scratch.m_vecPosition.x = x;
            nSequenceb = (unsigned int)v12->m_VertexColors.m_Memory.m_pMemory[j];
            HIBYTE(nSequenceb) = (int)(float)((float)HIBYTE(nSequenceb)
                                            * (float)(1.0 - SampleForSequence->m_fBlendFactor));
            v69.m_Scratch.m_color = (VertexColor_t)nSequenceb;
            m_pMemory = v12->m_TextureCoords.m_Memory.m_pMemory;
            m_fTop_V0 = SampleForSequence->m_TextureCoordData[0].m_fTop_V0;
            m_fLeft_U0 = SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
            v21 = SampleForSequence->m_TextureCoordData[0].m_fBottom_V0 - m_fTop_V0;
            v22 = (float)(m_pMemory[j].y * v21) + m_fTop_V0;
            v23 = SampleForSequence->m_TextureCoordData[0].m_fRight_U0
                - SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
            v24 = v23 * m_pMemory[j].x;
            v69.m_Scratch.m_vecTexCoord.y = v22;
            v25 = &v69.m_pMemory[m_nVertexCount];
            v69.m_Scratch.m_vecTexCoord.x = v24 + m_fLeft_U0;
            v25->m_vecPosition.x = x;
            v25->m_vecPosition.y = v69.m_Scratch.m_vecPosition.y;
            v25->m_vecPosition.z = v69.m_Scratch.m_vecPosition.z;
            v25->m_color = v69.m_Scratch.m_color;
            v25->m_vecTexCoord = v69.m_Scratch.m_vecTexCoord;
            v69.m_nVertexCount += v69.m_nVertexIncrement;
            nSequencec = (unsigned int)v12->m_VertexColors.m_Memory.m_pMemory[j];
            HIBYTE(nSequencec) = (int)(float)((float)HIBYTE(nSequencec) * SampleForSequence->m_fBlendFactor);
            v69.m_Scratch.m_color = (VertexColor_t)nSequencec;
            v26 = v12->m_TextureCoords.m_Memory.m_pMemory;
            v27 = (float)(v26[j].y * v21) + SampleForSequence->m_TextureCoordData[0].m_fTop_V1;
            v69.m_Scratch.m_vecTexCoord.x = (float)(v26[j].x * v23)
                                          + SampleForSequence->m_TextureCoordData[0].m_fLeft_U1;
            v69.m_Scratch.m_vecTexCoord.y = v27;
            v69.m_pMemory[v69.m_nVertexCount] = v69.m_Scratch;
            m_nVertexCount = v69.m_nVertexIncrement + v69.m_nVertexCount;
            ++j;
          }
          v61 += 100;
          v65 = (GameUIVertex_t *)((char *)v65 - 1);
          if ( v65 == nullptr )
            break;
          v4 = renderList;
        }
        m_tms = v69.m_pMemory;
        v69.m_pRenderContext->UnlockVertexBuffer(
          this: v69.m_pRenderContext,
          a2: v69.m_hVertexBuffer,
          a3: 24 * m_nVertexCount,
          a4: (LockDesc_t *)&m_tms);
        v69.m_pRenderContext->BindVertexBuffer(
          this: v69.m_pRenderContext,
          a2: 0,
          a3: v69.m_hVertexBuffer,
          a4: 0,
          a5: 24);
        GetDevice = pRenderContext->GetDevice;
        v29 = 2 * v66;
        result.m_tms = 2 * v66;
        v30 = (int)GetDevice(this: pRenderContext);
        (*(void (__thiscall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v30 + 136))(a1: v30, a2: 0, a3: v70);
        CreateDynamicIndexBuffer = pRenderContext->CreateDynamicIndexBuffer;
        v32 = v70[0] & 0x7FFFFFFF;
        v70[1] = 2;
        v70[0] = v29;
        v70[2] = "gamelayer";
        v70[3] = "game_controls";
        v33 = CreateDynamicIndexBuffer(this: pRenderContext, a2: (const BufferDesc_t *)v70, a3: 0);
        v34 = (v29 ^ v32) & 0x7FFFFFFF ^ v32;
        v72 = v33;
        v73 = v34;
        p_m_nRefCount = &v33->m_nRefCount;
        _InterlockedExchangeAdd(&v33->m_nRefCount.m_value, 1u);
        v35 = pRenderContext->LockIndexBuffer(
                this: pRenderContext,
                a2: v33,
                a3: 2 * ((2 * v34) >> 1),
                a4: (LockDesc_t *)&m_tms);
        v36 = m_tms;
        v37 = v35;
        v38 = 0;
        v62 = 0;
        do
        {
          v39 = v62;
          *((_WORD *)&v36->m_vecPosition.x + v38) = v62;
          v40 = v37 + v38;
          *((_WORD *)&v36->m_vecPosition.x + v40) = v62 + 2;
          v41 = v37 + v40;
          *((_WORD *)&v36->m_vecPosition.x + v41) = v62 + 4;
          v42 = v37 + v41;
          *((_WORD *)&v36->m_vecPosition.x + v42) = v62;
          v43 = v37 + v42;
          *((_WORD *)&v36->m_vecPosition.x + v43) = v62 + 4;
          v62 += 8;
          v44 = v37 + v43;
          *((_WORD *)&v36->m_vecPosition.x + v44) = v39 + 6;
          v45 = v37 + v44;
          *((_WORD *)&v36->m_vecPosition.x + v45) = v39 + 1;
          v46 = v37 + v45;
          *((_WORD *)&v36->m_vecPosition.x + v46) = v39 + 3;
          v47 = v37 + v46;
          *((_WORD *)&v36->m_vecPosition.x + v47) = v39 + 5;
          v48 = v37 + v47;
          *((_WORD *)&v36->m_vecPosition.x + v48) = v39 + 1;
          v49 = v37 + v48;
          *((_WORD *)&v36->m_vecPosition.x + v49) = v39 + 5;
          v50 = v37 + v49;
          *((_WORD *)&v36->m_vecPosition.x + v50) = v39 + 7;
          v38 = v37 + v50;
          v64 = (GameUIVertex_t *)((char *)v64 - 1);
        }
        while ( v64 != nullptr );
        v51 = v72;
        UnlockIndexBuffer = pRenderContext->UnlockIndexBuffer;
        m_tms = v36;
        UnlockIndexBuffer(this: pRenderContext, a2: v72, a3: 2 * v38, a4: (LockDesc_t *)&m_tms);
        pRenderContext->BindIndexBuffer(this: pRenderContext, a2: v51, a3: 0);
        pRenderContext->DrawIndexed(this: pRenderContext, a2: RENDER_PRIM_TRIANGLES, a3: 0, a4: result.m_tms, a5: 0);
        if ( v51 != nullptr )
        {
          pRenderContext->DestroyDynamicIndexBuffer(this: pRenderContext, a2: v51);
          _InterlockedExchangeAdd(&p_m_nRefCount->m_value, 0xFFFFFFFF);
        }
        m_hVertexBuffer = v69.m_hVertexBuffer;
        if ( v69.m_hVertexBuffer != nullptr )
        {
          v69.m_pRenderContext->DestroyDynamicVertexBuffer(this: v69.m_pRenderContext, a2: v69.m_hVertexBuffer);
          _InterlockedExchangeAdd(&v69.m_hVertexBuffer->m_nRefCount.m_value, 0xFFFFFFFF);
          m_hVertexBuffer = nullptr;
          v69.m_hVertexBuffer = nullptr;
        }
        if ( (*((_DWORD *)&v69.CVertexData<GameUIVertex_t> + 12) & 0x80000000) != 0 && m_hVertexBuffer != nullptr )
        {
          _InterlockedExchangeAdd(&m_hVertexBuffer->m_nRefCount.m_value, 0xFFFFFFFF);
          v54 = v69.m_pRenderContext->GetDevice(this: v69.m_pRenderContext);
          v54->DestroyVertexBuffer(this: v54, a2: v69.m_hVertexBuffer);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F800
// Name: public: static class CGameUISystem __near * CGameUISystem::FromScriptHandle(int)
// Source: json
//------------------------------------------------------------------------------
CGameUISystem *__cdecl CGameUISystem::FromScriptHandle(int iScriptHandle)
{
  unsigned __int16 v1; // ax
  CUtlMap<int,CGameUISystem *,unsigned short>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  search.key = iScriptHandle;
  v1 = CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_mapScriptHandles.m_Tree,
         &search);
  if ( v1 == 0xFFFF )
    return nullptr;
  else
    return g_mapScriptHandles.m_Tree.m_Elements.m_pMemory[v1].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041F990
// Name: public: virtual int CGameUISystem::GetScriptHandle(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CGameUISystem::GetScriptHandle(vgui::BuildGroup *this)
{
  return this->m_pBuildContext;
}

//------------------------------------------------------------------------------
// Address: 0x0041FB80
// Name: public: CGameUISystem::CGameUISystem(void)
// Source: json
//------------------------------------------------------------------------------
CGameUISystem *__thiscall CGameUISystem::CGameUISystem(CGameUISystem *this)
{
  CGameUISystem *insert; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (CGameUISystem_vtbl *)&CGameUISystem::`vftable';
  CGameUIDefinition::CGameUIDefinition(this: &this->m_GameUIDef, pGameUISystem: this);
  this->m_iScriptHandle = ++g_iSerialHandle_0;
  this->m_bDrawReport = true;
  insert = this;
  CUtlMap<int,CGameUISystem *,unsigned short>::InsertOrReplace(
    this: &g_mapScriptHandles,
    key: &this->m_iScriptHandle,
    &insert);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041FD50
// Name: public: virtual void CGameUISystem::Render(struct Rect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGameUISystem::Render(CGameUISystem *this@<ecx>, const Rect_t *viewport, int a3, Rect_t *viewporta)
{
  CGameUISystem *m_nAllocationCount; // ebx
  CGameUIDefinition *p_m_GameUIDef; // esi
  int v6; // ebp
  IMatRenderContext *v7; // eax
  int v8; // esi
  int m_Size; // eax
  int v10; // edi
  int v11; // ecx
  int v12; // ebp
  int v13; // ebp
  int v14; // ebp
  int v15; // ebx
  void *v16; // eax
  double v17; // [esp+34h] [ebp-54h]
  double v18; // [esp+3Ch] [ebp-4Ch]
  double v19; // [esp+44h] [ebp-44h]
  int v20; // [esp+6Ch] [ebp-1Ch]
  CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > renderLists; // [esp+70h] [ebp-18h] BYREF
  void *v22; // [esp+84h] [ebp-4h]
  int retaddr; // [esp+88h] [ebp+0h]
  Rect_t *viewportb; // [esp+94h] [ebp+Ch]

  m_nAllocationCount = this;
  p_m_GameUIDef = &this->m_GameUIDef;
  if ( this->m_GameUIDef.GetVisible(this: &this->m_GameUIDef) )
  {
    v6 = 0;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "Render",
      a3: 0,
      a4: "Render",
      a5: false,
      a6: 4);
    CGameUIDefinition::UpdateGeometry(this: p_m_GameUIDef);
    CGameUIDefinition::UpdateRenderTransforms(this: p_m_GameUIDef, viewport: viewporta);
    renderLists.m_Size = 0;
    renderLists.m_pElements = nullptr;
    v22 = nullptr;
    retaddr = 0;
    CGameUIDefinition::GetRenderData(
      this: p_m_GameUIDef,
      renderLists: (CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *)&renderLists.m_Size);
    v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v8 = (int)v7;
    if ( v7 != nullptr )
      v7->BeginRender(this: v7);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v8 + 148))(a1: v8, a2: 1.0, a3: -1.0, a4: 1.0);
    v19 = (float)((float)viewporta->height + 0.5);
    v18 = (float)((float)viewporta->width + 0.5);
    v17 = (float)((float)viewporta->y + 0.5);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v8 + 128))(
      a1: v8,
      a2: COERCE_UNSIGNED_INT64((float)((float)viewporta->x + 0.5)),
      a3: HIDWORD(COERCE_UNSIGNED_INT64((float)((float)viewporta->x + 0.5))),
      a4: LODWORD(v17),
      a5: HIDWORD(v17),
      a6: LODWORD(v18),
      a7: HIDWORD(v18),
      a8: LODWORD(v19),
      a9: HIDWORD(v19),
      a10: COERCE_UNSIGNED_INT64(-1.0),
      a11: HIDWORD(COERCE_UNSIGNED_INT64(-1.0)),
      a12: COERCE_UNSIGNED_INT64(1.0),
      a13: HIDWORD(COERCE_UNSIGNED_INT64(1.0)));
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(a1: v8, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 80))(a1: v8, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 84))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 124))(a1: v8);
    viewportb = nullptr;
    renderLists.m_Memory.m_pMemory = nullptr;
    v20 = 0;
    if ( retaddr > 0 )
    {
      renderLists.m_Memory.m_nGrowSize = retaddr;
      m_Size = renderLists.m_Size;
      v10 = 0;
      do
      {
        v11 = *(_DWORD *)(v10 + m_Size + 20);
        if ( v11 != 0 )
        {
          if ( v11 == 1 )
          {
            v13 = 0;
            if ( *(int *)(v10 + m_Size + 12) > 0 )
            {
              do
              {
                CGameUISystem::RenderDynamicLayer(
                  this: m_nAllocationCount,
                  renderList: (LayerRenderLists_t *)(v10 + m_Size),
                  geometryIndex: v13);
                m_Size = renderLists.m_Size;
                ++renderLists.m_Memory.m_pMemory;
                ++v13;
              }
              while ( v13 < *(_DWORD *)(v10 + renderLists.m_Size + 12) );
            }
          }
          else if ( v11 == 2 )
          {
            v14 = 0;
            if ( *(int *)(v10 + m_Size + 12) > 0 )
            {
              v15 = 0;
              do
              {
                CGameUISystem::RenderTextLayer(
                  this: (CGameUISystem *)renderLists.m_Memory.m_nAllocationCount,
                  a2: v14,
                  a3: v8,
                  renderGeometry: (CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *)(v15 + *(_DWORD *)(v10 + m_Size)));
                m_Size = renderLists.m_Size;
                ++v20;
                ++v14;
                v15 += 20;
              }
              while ( v14 < *(_DWORD *)(v10 + renderLists.m_Size + 12) );
              m_nAllocationCount = (CGameUISystem *)renderLists.m_Memory.m_nAllocationCount;
            }
          }
        }
        else
        {
          v12 = 0;
          if ( *(int *)(v10 + m_Size + 12) > 0 )
          {
            do
            {
              CGameUISystem::RenderStaticLayer(
                this: m_nAllocationCount,
                renderList: (LayerRenderLists_t *)(v10 + m_Size),
                geometryIndex: v12);
              m_Size = renderLists.m_Size;
              viewportb = (Rect_t *)((char *)viewportb + 1);
              ++v12;
            }
            while ( v12 < *(_DWORD *)(v10 + renderLists.m_Size + 12) );
          }
        }
        v10 += 36;
        --renderLists.m_Memory.m_nGrowSize;
      }
      while ( renderLists.m_Memory.m_nGrowSize != 0 );
      v6 = v20;
    }
    if ( m_nAllocationCount->m_bDrawReport )
    {
      m_nAllocationCount->m_bDrawReport = false;
      _Msg(a1: "Total static draw calls in UI: %d\n", viewportb);
      _Msg(a1: "Total dynamic draw calls in UI: %d\n", renderLists.m_Memory.m_pMemory);
      _Msg(a1: "Total font draw calls in UI: %d\n", v6);
      _Msg(a1: "Total draw calls in UI: %d\n", (char *)viewportb + (unsigned int)renderLists.m_Memory.m_pMemory + v6);
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 80))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 80))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 80))(a1: v8, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 88))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
    CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int>>::RemoveAll(this: (CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *)&renderLists.m_Memory.m_nAllocationCount);
    v16 = (void *)renderLists.m_Memory.m_nAllocationCount;
    if ( renderLists.m_Size >= 0 )
    {
      if ( renderLists.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)renderLists.m_Memory.m_nAllocationCount);
        v16 = nullptr;
        renderLists.m_Memory.m_nAllocationCount = 0;
      }
      renderLists.m_Memory.m_nGrowSize = 0;
    }
    v22 = v16;
    if ( renderLists.m_Size >= 0 )
    {
      if ( v16 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        renderLists.m_Memory.m_nAllocationCount = 0;
      }
      renderLists.m_Memory.m_nGrowSize = 0;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004200A0
// Name: public: virtual void CGameUISystem::Render(class IRenderContext __near *,struct Rect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUISystem::Render(CGameUISystem *this, IRenderContext *pRenderContext, const Rect_t *viewport)
{
  CGameUISystem *v3; // ebp
  CGameUIDefinition *p_m_GameUIDef; // edi
  int v5; // ebx
  void (__thiscall *SetConstantBufferData)(IRenderContext *, ConstantBufferHandle_t__ *, const void *, int); // edx
  float v8; // xmm1_4
  float height; // xmm0_4
  int m_nAllocationCount; // eax
  int v11; // esi
  int v12; // ecx
  int v13; // ebp
  void *v14; // eax
  float pViewportInfo[4]; // [esp+38h] [ebp-28h] BYREF
  CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > renderLists; // [esp+48h] [ebp-18h] BYREF
  void *v17; // [esp+5Ch] [ebp-4h]
  LayerRenderLists_t *viewporta; // [esp+68h] [ebp+8h]

  v3 = this;
  p_m_GameUIDef = &this->m_GameUIDef;
  LODWORD(pViewportInfo[0]) = this;
  if ( this->m_GameUIDef.GetVisible(this: &this->m_GameUIDef) )
  {
    CGameUIDefinition::UpdateGeometry(this: p_m_GameUIDef);
    CGameUIDefinition::UpdateRenderTransforms(this: p_m_GameUIDef, viewport);
    v5 = 0;
    memset(&renderLists.m_Memory.m_nAllocationCount, 0, 16);
    v17 = nullptr;
    CGameUIDefinition::GetRenderData(
      this: p_m_GameUIDef,
      renderLists: (CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *)&renderLists.m_Memory.m_nAllocationCount);
    pRenderContext->SetCullMode(this: pRenderContext, a2: RENDER_CULLMODE_CULL_NONE);
    pRenderContext->SetBlendMode(this: pRenderContext, a2: RENDER_BLEND_ALPHABLENDING, a3: nullptr);
    ((void (__thiscall *)(IRenderContext *, RenderShaderHandle_t__ *, unsigned int))pRenderContext->BindVertexShader)(
      a1: pRenderContext,
      a2: g_pGameUISystemMgrImpl->m_hVertexShader,
      a3: g_pGameUISystemMgrImpl->m_hInputLayout.m_Handle);
    pRenderContext->BindShader(
      this: pRenderContext,
      a2: RENDER_PIXEL_SHADER,
      a3: g_pGameUISystemMgrImpl->m_hPixelShader);
    SetConstantBufferData = pRenderContext->SetConstantBufferData;
    pViewportInfo[1] = (float)viewport->x + 0.5;
    v8 = (float)viewport->y + 0.5;
    pViewportInfo[3] = (float)viewport->width;
    height = (float)viewport->height;
    pViewportInfo[2] = v8;
    *(float *)&renderLists.m_Memory.m_pMemory = height;
    SetConstantBufferData(
      this: pRenderContext,
      a2: g_pGameUISystemMgrImpl->m_hConstBuffer,
      a3: &pViewportInfo[1],
      a4: 16);
    pRenderContext->BindConstantBuffer(
      this: pRenderContext,
      a2: RENDER_VERTEX_SHADER,
      a3: g_pGameUISystemMgrImpl->m_hConstBuffer,
      a4: 0,
      a5: 0);
    if ( (int)renderLists.m_pElements > 0 )
    {
      viewporta = renderLists.m_pElements;
      m_nAllocationCount = renderLists.m_Memory.m_nAllocationCount;
      v11 = 0;
      do
      {
        v12 = *(_DWORD *)(v11 + m_nAllocationCount + 20);
        if ( v12 != 0 )
        {
          if ( v12 == 2 && *(int *)(v11 + m_nAllocationCount + 12) > 0 )
          {
            v13 = 0;
            do
            {
              CGameUISystem::RenderTextLayer(
                this: (CGameUISystem *)LODWORD(pViewportInfo[0]),
                pRenderContext,
                renderGeometry: (CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *)(v13
                                                                               + *(_DWORD *)(v11 + m_nAllocationCount)));
              m_nAllocationCount = renderLists.m_Memory.m_nAllocationCount;
              ++v5;
              v13 += 20;
            }
            while ( v5 < *(_DWORD *)(v11 + renderLists.m_Memory.m_nAllocationCount + 12) );
            v3 = (CGameUISystem *)LODWORD(pViewportInfo[0]);
          }
        }
        else if ( *(int *)(v11 + m_nAllocationCount + 12) > 0 )
        {
          do
          {
            CGameUISystem::RenderStaticLayer(
              this: v3,
              pRenderContext,
              renderList: (LayerRenderLists_t *)(v11 + m_nAllocationCount),
              geometryIndex: v5);
            m_nAllocationCount = renderLists.m_Memory.m_nAllocationCount;
            ++v5;
          }
          while ( v5 < *(_DWORD *)(v11 + renderLists.m_Memory.m_nAllocationCount + 12) );
        }
        v11 += 36;
        v5 = 0;
        viewporta = (LayerRenderLists_t *)((char *)viewporta - 1);
      }
      while ( viewporta != nullptr );
    }
    CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int>>::RemoveAll(this: (CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *)&renderLists.m_Memory.m_nAllocationCount);
    v14 = (void *)renderLists.m_Memory.m_nAllocationCount;
    if ( renderLists.m_Size >= 0 )
    {
      if ( renderLists.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)renderLists.m_Memory.m_nAllocationCount);
        v14 = nullptr;
        renderLists.m_Memory.m_nAllocationCount = 0;
      }
      renderLists.m_Memory.m_nGrowSize = 0;
    }
    v17 = v14;
    if ( renderLists.m_Size >= 0 && v14 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C510
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<int,class CGameUISystem __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,class CGameUISystem __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,class CGameUISystem __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00420290
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CGraphicGroup>(class CGraphicGroup __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CGraphicGroup>()
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    dword_5BA44C = 9;
    dword_5BA478 = 9;
    dword_5BA450 = 108;
    dword_5BA454 = 8;
    dword_5BA458 = -1;
    dword_5BA45C = 0;
    dword_5BA460 = 0;
    dword_5BA464 = 0;
    dword_5BA468 = 0;
    dword_5BA46C = 0;
    dword_5BA470 = (int)"scale";
    dword_5BA474 = (int)"1 1";
    dword_5BA47C = 116;
    dword_5BA480 = 8;
    dword_5BA484 = -1;
    dword_5BA488 = 0;
    dword_5BA48C = 0;
    dword_5BA490 = 0;
    dword_5BA494 = 0;
    dword_5BA498 = 0;
    dword_5BA49C = (int)"rotation";
    dword_5BA4A0 = (int)"0";
    dword_5BA4A4 = 3;
    dword_5BA4A8 = 124;
    dword_5BA4AC = 4;
    dword_5BA4B0 = -1;
    dword_5BA4B4 = 0;
    dword_5BA4B8 = 0;
    dword_5BA4BC = 0;
    dword_5BA4C0 = 0;
    dword_5BA4C4 = 0;
    dword_5BA4C8 = (int)"maintainaspectratio";
    dword_5BA4CC = (int)"0";
    dword_5BA4D0 = 4;
    dword_5BA4D4 = 156;
    dword_5BA4D8 = 1;
    dword_5BA4DC = -1;
    dword_5BA4E0 = 0;
    dword_5BA4E4 = 0;
    dword_5BA4E8 = 0;
    dword_5BA4EC = 0;
    dword_5BA4F0 = 0;
    dword_5BA4F4 = (int)"sublayertype";
    dword_5BA4F8 = (int)"0";
    dword_5BA4FC = 2;
    dword_5BA500 = 152;
    dword_5BA504 = 4;
    dword_5BA508 = -1;
    dword_5BA50C = 0;
    dword_5BA510 = 0;
    dword_5BA514 = 0;
    dword_5BA518 = 0;
    dword_5BA51C = 0;
    dword_5BA520 = (int)"visible";
    dword_5BA524 = (int)"1";
    dword_5BA528 = 4;
    dword_5BA52C = 157;
    dword_5BA530 = 1;
    dword_5BA534 = -1;
    dword_5BA538 = 0;
    dword_5BA53C = 0;
    dword_5BA540 = 0;
    dword_5BA544 = 0;
    dword_5BA548 = 0;
    dword_5BA54C = (int)"initialstate";
    dword_5BA550 = (int)"-1";
    dword_5BA554 = 2;
    dword_5BA558 = 352;
    dword_5BA55C = 4;
    dword_5BA560 = -1;
    dword_5BA564 = 0;
    dword_5BA568 = 0;
    dword_5BA57C = (int)"0";
    dword_5BA5A8 = (int)"255 255 255 255";
    dword_5BA5D4 = (int)"255 255 255 255";
    dword_5BA600 = (int)"255 255 255 255";
    dword_5BA5AC = 8;
    dword_5BA5D8 = 8;
    dword_5BA604 = 8;
    dword_5BA56C = 0;
    dword_5BA570 = 0;
    dword_5BA574 = 0;
    dword_5BA578 = (int)"horizgradient";
    dword_5BA580 = 4;
    dword_5BA584 = 140;
    dword_5BA588 = 1;
    dword_5BA58C = -1;
    dword_5BA590 = 0;
    dword_5BA594 = 0;
    dword_5BA598 = 0;
    dword_5BA59C = 0;
    dword_5BA5A0 = 0;
    dword_5BA5A4 = (int)"color";
    dword_5BA5B0 = 128;
    dword_5BA5B4 = 4;
    dword_5BA5B8 = -1;
    dword_5BA5BC = 0;
    dword_5BA5C0 = 0;
    dword_5BA5C4 = 0;
    dword_5BA5C8 = 0;
    dword_5BA5CC = 0;
    dword_5BA5D0 = (int)"topcolor";
    dword_5BA5DC = 132;
    dword_5BA5E0 = 4;
    dword_5BA5E4 = -1;
    dword_5BA5E8 = 0;
    dword_5BA5EC = 0;
    dword_5BA5F0 = 0;
    dword_5BA5F4 = 0;
    dword_5BA5F8 = 0;
    dword_5BA5FC = (int)"bottomcolor";
    dword_5BA608 = 136;
    dword_5BA60C = 4;
    dword_5BA610 = -1;
    dword_5BA614 = 0;
    dword_5BA618 = 0;
    dword_5BA61C = 0;
    dword_5BA620 = 0;
    dword_5BA624 = 0;
    dword_5BA628 = 0;
    dword_5BA62C = 0;
    dword_5BA630 = 0;
    dword_5BA634 = 0;
    dword_5BA638 = 0;
    dword_5BA63C = -1;
    dword_5BA640 = 0;
    dword_5BA644 = 0;
    dword_5BA648 = 0;
    dword_5BA64C = 0;
    dword_5BA650 = 0;
  }
  return unpack_0;
}
