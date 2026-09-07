// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/renderutils.cpp
// Functions: 20
// ============================================================

#include "tier2\renderutils.h"

//------------------------------------------------------------------------------
// Address: 0x1027AE20
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x1027AEE0
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax
  IMaterial v5; // edx
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  IMaterial *v8; // eax
  IMaterial v9; // edx
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  IMaterial *v12; // eax
  IMaterial v13; // edx
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  IMaterial *v16; // eax
  IMaterial v17; // edx

  if ( (_S1_24 & 1) == 0 )
  {
    _S1_24 |= 1u;
    autoMutex___1.m_ownerID = 0;
    autoMutex___1.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex___1.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex___1, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex___1, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex___1.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex___1.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
  else
    v3 = nullptr;
  KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
  v4 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v3,
                      a4: a1);
  v5.__vftable = v4->__vftable;
  s_pWireframe = v4;
  v5.IncrementReferenceCount(this: v4);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "wireframe");
  else
    v7 = nullptr;
  KeyValues::SetInt(this: v7, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$ignorez", value: 1);
  v8 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v7);
  v9.__vftable = v8->__vftable;
  s_pWireframeIgnoreZ = v8;
  v9.IncrementReferenceCount(this: v8);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "unlitgeneric");
  else
    v11 = nullptr;
  KeyValues::SetInt(this: v11, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v11, keyName: "$vertexalpha", value: 1);
  v12 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v11);
  v13.__vftable = v12->__vftable;
  s_pVertexColor = v12;
  v13.IncrementReferenceCount(this: v12);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "unlitgeneric");
  else
    v15 = nullptr;
  KeyValues::SetInt(this: v15, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$ignorez", value: 1);
  v16 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *))g_pMaterialSystem->CreateMaterial)(
                       a1: g_pMaterialSystem,
                       a2: "__utilVertexColorIgnoreZ");
  v17.__vftable = v16->__vftable;
  s_pVertexColorIgnoreZ = v16;
  v17.IncrementReferenceCount(this: v16);
  if ( --autoMutex___1.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex___1, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1027B120
// Name: DrawAxes
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawAxes(const Vector *origin@<edi>, CMeshBuilder *meshBuilder@<esi>, Vector *pts, int idx, Color c)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float *m_pCurrPosition; // eax
  int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *v13; // eax
  float *v14; // eax
  int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float *v19; // eax
  float *v20; // eax
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *v25; // eax
  float start; // [esp+4h] [ebp-Ch]
  float start_4; // [esp+8h] [ebp-8h]
  float start_8; // [esp+Ch] [ebp-4h]

  v5 = origin->x + pts[idx].x;
  v6 = pts[idx].y + origin->y;
  v7 = pts[idx].z + origin->z;
  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = v5;
  m_pCurrPosition[1] = v6;
  m_pCurrPosition[2] = v7;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  start = v5;
  start_4 = v6;
  start_8 = v7;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  if ( (idx & 1) != 0 )
    v9 = idx - 1;
  else
    v9 = idx + 1;
  v10 = origin->x + pts[v9].x;
  v11 = pts[v9].y + origin->y;
  v12 = pts[v9].z + origin->z;
  v13 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v13 = v10;
  v13[1] = v11;
  v13[2] = v12;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v14 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v14 = start;
  v14[1] = start_4;
  v14[2] = start_8;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  if ( (idx & 2) != 0 )
    v15 = idx - 2;
  else
    v15 = idx + 2;
  v16 = origin->x + pts[v15].x;
  v17 = pts[v15].y + origin->y;
  v18 = pts[v15].z + origin->z;
  v19 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v19 = v16;
  v19[1] = v17;
  v19[2] = v18;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v20 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v20 = start;
  v20[1] = start_4;
  v20[2] = start_8;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  if ( (idx & 4) != 0 )
    v21 = idx - 4;
  else
    v21 = idx + 4;
  v22 = origin->x + pts[v21].x;
  v23 = pts[v21].y + origin->y;
  v24 = pts[v21].z + origin->z;
  v25 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v25 = v22;
  v25[1] = v23;
  v25[2] = v24;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1027B3E0
// Name: DrawExtrusionFace
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawExtrusionFace(
        int idx1@<eax>,
        CMeshBuilder *meshBuilder@<esi>,
        const Vector *start,
        const Vector *end,
        Vector *pts,
        int idx2,
        Color c)
{
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector *v11; // edi
  float *m_pCurrPosition; // eax
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float *v16; // eax
  float *v17; // eax
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float *v21; // eax
  float *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *v25; // eax
  float v26; // xmm0_4
  float *v27; // eax
  float *v28; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  Vector *ptsa; // [esp+1Ch] [ebp+10h]

  v7 = idx1;
  v8 = start->x + pts[v7].x;
  v9 = pts[v7].y + start->y;
  v10 = pts[v7].z + start->z;
  v11 = &pts[v7];
  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = v8;
  m_pCurrPosition[1] = v9;
  m_pCurrPosition[2] = v10;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v13 = start->x + pts[idx2].x;
  v14 = start->z + pts[idx2].z;
  v15 = pts[idx2].y + start->y;
  ptsa = &pts[idx2];
  v16 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v16 = v13;
  v16[1] = v15;
  v16[2] = v14;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v17 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v17 = v13;
  v17[1] = v15;
  v17[2] = v14;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v18 = end->x + ptsa->x;
  v19 = end->y + ptsa->y;
  v20 = ptsa->z + end->z;
  v21 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v21 = v18;
  v21[1] = v19;
  v21[2] = v20;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v22 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v22 = v18;
  v22[1] = v19;
  v22[2] = v20;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v23 = v11->y + end->y;
  v24 = v11->z + end->z;
  v25 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v26 = end->x + v11->x;
  *v25 = v26;
  v25[1] = v23;
  v25[2] = v24;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v27 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v27 = v26;
  v27[1] = v23;
  v27[2] = v24;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v28 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v29 = v11->y + start->y;
  v30 = v11->z + start->z;
  *v28 = start->x + v11->x;
  v28[1] = v29;
  v28[2] = v30;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1027B760
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,float,int,int,class Color,class IMaterial __near *,bool),class Vector,float,int,int,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,float,int,int,Color,IMaterial *,bool),Vector,float,int,int,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,float,int,int,Color,IMaterial *,bool),Vector,float,int,int,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, _DWORD, int, int, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: LODWORD(this->m_arg2),
    a3: this->m_arg3,
    a4: this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x1027B7C0
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x1027B810
// Name: public: virtual void CFunctor5<void (*)(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *),class Vector,class Vector,class Vector,class Color,class IMaterial __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor5<void (__cdecl *)(Vector const &,Vector const &,Vector const &,Color,IMaterial *),Vector,Vector,Vector,Color,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor5<void (__cdecl*)(Vector const &,Vector const &,Vector const &,Color,IMaterial *),Vector,Vector,Vector,Color,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, Vector *, Vector *, _DWORD, IMaterial *))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: *(_DWORD *)&this->m_arg4,
    a5: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x1027B830
// Name: void RenderWireframeSweptBox(class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeSweptBox(
        int a1@<esi>,
        const Vector *vStart,
        const Vector *vEnd,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        __int16 bZBuffer)
{
  IMatRenderContext *v8; // edi
  int v9; // esi
  IMaterial *v10; // eax
  IMesh *v11; // edi
  int v12; // ebx
  char v13; // al
  Vector *v14; // edi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  int v18; // ecx
  float v19; // xmm0_4
  int v20; // edi
  int v21; // esi
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // edi
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  matrix3x4_t fRotateMatrix; // [esp+8h] [ebp-2C4h] BYREF
  Vector pts[8]; // [esp+38h] [ebp-294h] BYREF
  float dot[8]; // [esp+98h] [ebp-234h]
  CMeshBuilder meshBuilder; // [esp+B8h] [ebp-214h] BYREF
  Vector temp; // [esp+2A0h] [ebp-2Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+2ACh] [ebp-20h]
  IMesh *pMesh; // [esp+2B0h] [ebp-1Ch]
  Vector vDelta; // [esp+2B4h] [ebp-18h]
  int v36; // [esp+2C0h] [ebp-Ch]
  int idx2; // [esp+2C4h] [ebp-8h]
  int i; // [esp+2C8h] [ebp-4h]

  InitializeStandardMaterials(a1);
  v8 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v9 = 0;
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  v10 = s_pWireframe;
  if ( (_BYTE)bZBuffer == 0 )
    v10 = s_pWireframeIgnoreZ;
  v8->Bind(this: v8, a2: v10, a3: nullptr);
  AngleMatrix(angles, matrix: &fRotateMatrix);
  v11 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMesh = v11;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 60, a3: 60, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 60;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 60, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  vDelta.x = vEnd->x - vStart->x;
  vDelta.y = vEnd->y - vStart->y;
  vDelta.z = vEnd->z - vStart->z;
  v12 = 0;
  v13 = 0;
  i = 0;
  idx2 = 0;
  v14 = pts;
  while ( 1 )
  {
    if ( (v13 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    temp.x = x;
    if ( (v13 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    temp.y = y;
    if ( (v13 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    temp.z = z;
    VectorRotate(in1: &temp.x, in2: &fRotateMatrix, out: &v14->x);
    v18 = idx2;
    v19 = (float)((float)(v14->y * vDelta.y) + (float)(v14->x * vDelta.x)) + (float)(v14->z * vDelta.z);
    dot[v9] = v19;
    if ( *(float *)((char *)dot + v18) > v19 )
    {
      v12 = i;
      idx2 = v9 * 4;
    }
    ++i;
    ++v9;
    ++v14;
    if ( v9 >= 8 )
      break;
    v13 = i;
  }
  DrawAxes(origin: vStart, &meshBuilder, pts, idx: v12, c);
  DrawAxes(origin: vEnd, &meshBuilder, pts, idx: v12 ^ 7, c);
  v20 = 2;
  i = 2;
  v36 = 3;
  while ( 1 )
  {
    v21 = 1 << ((v20 - 1) % 3);
    v22 = 1 << (v20 % 3);
    v23 = (v21 & v12) != 0 ? v12 - v21 : v21 + v12;
    v24 = (v12 & v22) != 0 ? v12 - v22 : v22 + v12;
    idx2 = v24;
    v25 = (v12 & v22) != 0 ? v23 - v22 : v23 + v22;
    DrawExtrusionFace(idx1: v23, &meshBuilder, start: vStart, end: vEnd, pts, idx2: v25, c);
    DrawExtrusionFace(idx1: idx2, &meshBuilder, start: vStart, end: vEnd, pts, idx2: v25, c);
    ++i;
    if ( --v36 == 0 )
      break;
    v20 = i;
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1027BC80
// Name: void DrawScreenSpaceRectangle(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawScreenSpaceRectangle(
        int a1@<edi>,
        int a2@<esi>,
        IMaterial *pMaterial,
        int nDestX,
        int nDestY,
        int nWidth,
        int nHeight,
        float flSrcTextureX0,
        float flSrcTextureY0,
        float flSrcTextureX1,
        float flSrcTextureY1,
        int nSrcTextureWidth,
        int nSrcTextureHeight,
        void *pClientRenderable,
        int nXDice,
        int nYDice,
        float fDepth)
{
  IMatRenderContext *v17; // ebx
  int v18; // edi
  IMesh_vtbl *v19; // eax
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v21; // esi
  int v22; // esi
  float v23; // xmm4_4
  float v24; // xmm3_4
  void (__thiscall *GetViewport)(IMatRenderContext *, int *, int *, int *, int *); // edx
  float v26; // xmm3_4
  float v27; // xmm4_4
  int v28; // ecx
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  int v32; // xmm1_4
  int v33; // edi
  bool v34; // dl
  float *v35; // eax
  float *v36; // eax
  int v37; // xmm3_4
  int v38; // xmm1_4
  float *v39; // eax
  _DWORD *v40; // eax
  _DWORD *v41; // eax
  int v42; // xmm3_4
  float v43; // xmm7_4
  float v44; // xmm5_4
  int v45; // eax
  float v46; // xmm1_4
  float *m_pCurrPosition; // eax
  float v48; // xmm1_4
  float v49; // xmm4_4
  float v50; // xmm3_4
  float v51; // xmm0_4
  float *m_pCurrNormal; // eax
  float *v53; // eax
  _DWORD *v54; // eax
  _DWORD *v55; // eax
  float *v56; // eax
  float v57; // xmm2_4
  float *v58; // eax
  float *v59; // eax
  _DWORD *v60; // eax
  _DWORD *v61; // eax
  float *v62; // eax
  float v63; // xmm3_4
  float v64; // xmm1_4
  float *v65; // eax
  float *v66; // eax
  _DWORD *v67; // eax
  _DWORD *v68; // eax
  float *v69; // eax
  float v70; // xmm2_4
  float *v71; // eax
  float *v72; // eax
  _DWORD *v73; // eax
  _DWORD *v74; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-248h] BYREF
  int nScreenWidth; // [esp+1ECh] [ebp-60h] BYREF
  int vx; // [esp+1F0h] [ebp-5Ch] BYREF
  int vy; // [esp+1F4h] [ebp-58h] BYREF
  int nScreenHeight; // [esp+1F8h] [ebp-54h] BYREF
  float v82; // [esp+1FCh] [ebp-50h]
  float v83; // [esp+200h] [ebp-4Ch]
  int vh; // [esp+204h] [ebp-48h] BYREF
  float v85; // [esp+208h] [ebp-44h]
  float v86; // [esp+20Ch] [ebp-40h]
  float flUWidth; // [esp+210h] [ebp-3Ch]
  float flWidth; // [esp+214h] [ebp-38h]
  int vw; // [esp+218h] [ebp-34h] BYREF
  IMesh *pMesh; // [esp+21Ch] [ebp-30h]
  float v91; // [esp+220h] [ebp-2Ch]
  int x; // [esp+224h] [ebp-28h]
  float v93; // [esp+228h] [ebp-24h]
  int xSegments; // [esp+22Ch] [ebp-20h]
  float flLeftU; // [esp+230h] [ebp-1Ch]
  float flLeftX; // [esp+234h] [ebp-18h]
  float flRightU; // [esp+238h] [ebp-14h]
  float flVHeight; // [esp+23Ch] [ebp-10h]
  float flTexelsPerPixelX; // [esp+240h] [ebp-Ch]
  float flTexelsPerPixelY; // [esp+244h] [ebp-8h]
  int flHeight; // [esp+248h] [ebp-4h]
  float flTopY; // [esp+260h] [ebp+14h]

  v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v17 != nullptr )
    v17->BeginRender(this: v17);
  if ( nWidth <= 0 || nHeight <= 0 )
  {
    if ( v17 == nullptr )
      return;
  }
  else
  {
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    v17->Bind(this: v17, a2: pMaterial, a3: pClientRenderable);
    xSegments = nXDice;
    if ( nXDice <= 1 )
      xSegments = 1;
    v18 = nYDice;
    if ( nYDice <= 1 )
      v18 = 1;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int, int))v17->GetDynamicMesh)(
                                     a1: v17,
                                     a2: 1,
                                     a3: 0,
                                     a4: 0,
                                     a5: 0,
                                     a6: a1,
                                     a7: a2);
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v19 = meshBuilder.m_pMesh->__vftable;
    flHeight = 4 * xSegments * v18;
    SetPrimitiveType = v19->SetPrimitiveType;
    pMesh = meshBuilder.m_pMesh;
    v21 = 6 * xSegments * v18;
    ((void (__stdcall *)(int))SetPrimitiveType)(a1: 2);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: flHeight, a3: v21, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v21;
    CVertexBuilder::AttachBegin(
      this: &meshBuilder.m_VertexBuilder,
      pMesh,
      nMaxVertexCount: flHeight,
      desc: &meshBuilder);
    v22 = 0;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v17->GetRenderTargetDimensions(this: v17, a2: &nScreenWidth, a3: &nScreenHeight);
    flLeftX = (float)nDestX - 0.5;
    flVHeight = (float)(nWidth + nDestX) - 0.5;
    *(float *)&flHeight = (float)(nHeight + nDestY) - 0.5;
    if ( nWidth <= 1 )
      v23 = 0.0;
    else
      v23 = (float)(flSrcTextureX1 - flSrcTextureX0) / (float)(nWidth - 1);
    flTexelsPerPixelX = v23;
    if ( nHeight <= 1 )
      v24 = 0.0;
    else
      v24 = (float)(flSrcTextureY1 - flSrcTextureY0) / (float)(nHeight - 1);
    GetViewport = v17->GetViewport;
    flTexelsPerPixelY = v24;
    v26 = 1.0 / (float)nSrcTextureWidth;
    v27 = 1.0 / (float)nSrcTextureHeight;
    flLeftU = (float)((float)(flSrcTextureX0 + 0.5) - (float)(flTexelsPerPixelX * 0.5)) * v26;
    flRightU = (float)((float)(flSrcTextureX1 + 0.5) + (float)(flTexelsPerPixelX * 0.5)) * v26;
    flTexelsPerPixelX = (float)((float)(flSrcTextureY0 + 0.5) - (float)(flTexelsPerPixelY * 0.5)) * v27;
    flTexelsPerPixelY = (float)((float)(flSrcTextureY1 + 0.5) + (float)(flTexelsPerPixelY * 0.5)) * v27;
    GetViewport(this: v17, a2: &vx, a3: &vy, a4: &vw, a5: &vh);
    v28 = xSegments;
    v29 = (float)((float)(flVHeight * 2.0) / (float)vw) - 1.0;
    v30 = (float)((float)(flLeftX * 2.0) / (float)vw) - 1.0;
    v31 = 1.0 - (float)((float)((float)((float)nDestY - 0.5) * 2.0) / (float)vh);
    *(float *)&v32 = 1.0 - (float)((float)(*(float *)&flHeight * 2.0) / (float)vh);
    flVHeight = v29;
    flLeftX = v30;
    flTopY = v31;
    flHeight = v32;
    if ( xSegments > 1 || v18 > 1 )
    {
      *(float *)&v42 = (float)(v31 - *(float *)&v32) / (float)v18;
      v43 = (float)(flRightU - flLeftU) / (float)xSegments;
      v44 = (float)(v29 - v30) / (float)xSegments;
      v45 = 0;
      flWidth = v44;
      flHeight = v42;
      flUWidth = v43;
      flVHeight = (float)(flTexelsPerPixelY - flTexelsPerPixelX) / (float)v18;
      x = 0;
      if ( xSegments > 0 )
      {
        do
        {
          if ( v18 > 0 )
          {
            flRightU = (float)((float)(v45 + 1) * v44) + v30;
            flTexelsPerPixelY = (float)((float)(v45 + 1) * v43) + flLeftU;
            v46 = (float)((float)v45 * v44) + v30;
            v93 = v46;
            v91 = (float)((float)v45 * v43) + flLeftU;
            while ( 1 )
            {
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = v46;
              v48 = (float)((float)v22 * flVHeight) + flTexelsPerPixelX;
              v49 = (float)v22 * *(float *)&v42;
              v50 = v91;
              v51 = v31 - v49;
              m_pCurrPosition[1] = v51;
              v86 = v51;
              m_pCurrPosition[2] = fDepth;
              m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              m_pCurrNormal[1] = 0.0;
              m_pCurrNormal[2] = 1.0;
              v53 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v50;
              v53[1] = v48;
              v54 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v54 = 0;
              v54[1] = 1065353216;
              v54[2] = 0;
              v55 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              v82 = v48;
              *v55 = 1065353216;
              v55[1] = 0;
              v55[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v56 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = flRightU;
              v57 = flTexelsPerPixelY;
              v56[1] = v86;
              v56[2] = fDepth;
              v58 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v58[1] = 0.0;
              v58[2] = 1.0;
              v59 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v57;
              v59[1] = v82;
              v60 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v60 = 0;
              v60[1] = 1065353216;
              v60[2] = 0;
              v61 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              *v61 = 1065353216;
              v61[1] = 0;
              v61[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v62 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              ++v22;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = flRightU;
              v83 = flTopY - (float)((float)v22 * *(float *)&flHeight);
              v62[1] = v83;
              v63 = flTexelsPerPixelY;
              v64 = (float)((float)v22 * flVHeight) + flTexelsPerPixelX;
              v62[2] = fDepth;
              v65 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v65[1] = 0.0;
              v65[2] = 1.0;
              v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v63;
              v66[1] = v64;
              v67 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v67 = 0;
              v67[1] = 1065353216;
              v67[2] = 0;
              v68 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              v85 = v64;
              *v68 = 1065353216;
              v68[1] = 0;
              v68[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v69 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = v93;
              v70 = v91;
              v69[1] = v83;
              v69[2] = fDepth;
              v71 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v71[1] = 0.0;
              v71[2] = 1.0;
              v72 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v70;
              v72[1] = v85;
              v73 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v73 = 0;
              v73[1] = 1065353216;
              v73[2] = 0;
              v74 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              *v74 = 1065353216;
              v74[1] = 0;
              v74[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v31 = flTopY;
              v42 = flHeight;
              if ( v22 >= v18 )
                break;
              v46 = v93;
            }
            v30 = flLeftX;
            v44 = flWidth;
            v43 = flUWidth;
            v45 = x;
            v28 = xSegments;
          }
          ++v45;
          v22 = 0;
          x = v45;
        }
        while ( v45 < v28 );
      }
    }
    else
    {
      v33 = 0;
      while ( 1 )
      {
        v34 = v33 == 0 || v33 == 3;
        if ( (v33 & 2) != 0 )
          v31 = *(float *)&v32;
        if ( v34 )
          v29 = v30;
        v35 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
        v35[1] = v31;
        v35[2] = fDepth;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
        v36[1] = 0.0;
        v36[2] = 1.0;
        v37 = (v33 & 2) != 0 ? LODWORD(flTexelsPerPixelY) : LODWORD(flTexelsPerPixelX);
        v38 = v34 ? LODWORD(flLeftU) : LODWORD(flRightU);
        v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v38;
        *((_DWORD *)v39 + 1) = v37;
        v40 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                       + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
        *v40 = 0;
        v40[1] = 1065353216;
        v40[2] = 0;
        v41 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                       + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
        *v41 = 1065353216;
        v41[1] = 0;
        v41[2] = 0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v33 >= 4 )
          break;
        v30 = flLeftX;
        v29 = flVHeight;
        v31 = flTopY;
        v32 = flHeight;
      }
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
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PopMatrix(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PopMatrix(this: v17);
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
  }
  v17->EndRender(this: v17);
  v17->Release(this: v17);
}

//------------------------------------------------------------------------------
// Address: 0x1027C650
// Name: void RenderWireframeSphere(class Vector const __near &,float,int,int,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeSphere(
        int a1@<esi>,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi,
        Color c,
        bool bZBuffer)
{
  IMatRenderContext *v7; // esi
  ICallQueue *v8; // edi
  float z; // ebx
  char *v10; // eax
  __int64 v11; // xmm0_8
  int v12; // edi
  int v13; // esi
  int v14; // ebx
  IMaterial *v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // ebx
  double v19; // xmm0_8
  double v20; // xmm0_8
  int v21; // esi
  double v22; // xmm0_8
  float *m_pCurrPosition; // edi
  double v24; // xmm0_8
  signed int m_nCurrentIndex; // ecx
  __int16 v26; // dx
  signed int v27; // ecx
  signed int v28; // ecx
  signed int v29; // ecx
  bool v30; // zf
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  long double v33; // [esp+0h] [ebp-230h]
  long double v34; // [esp+0h] [ebp-230h]
  long double v35; // [esp+0h] [ebp-230h]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-224h] BYREF
  __int64 v37; // [esp+1F4h] [ebp-3Ch]
  float theta; // [esp+200h] [ebp-30h]
  float v39; // [esp+204h] [ebp-2Ch]
  IMesh *pMesh; // [esp+208h] [ebp-28h]
  float v41; // [esp+20Ch] [ebp-24h]
  float v42; // [esp+210h] [ebp-20h]
  float v43; // [esp+214h] [ebp-1Ch]
  float phi; // [esp+218h] [ebp-18h]
  CMatRenderContextPtr pRenderContext; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v47; // [esp+224h] [ebp-Ch]
  float v48; // [esp+228h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+22Ch] [ebp-4h]
  unsigned __int8 chRed; // [esp+22Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+22Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+22Fh] [ebp-1h]
  int nThetaa; // [esp+240h] [ebp+10h]

  InitializeStandardMaterials(a1);
  v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v8 = v7->GetCallQueue(this: v7);
  if ( v8 != nullptr )
  {
    z = vCenter->z;
    v37 = *(_QWORD *)&vCenter->x;
    v10 = (char *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v10 != nullptr )
    {
      v11 = v37;
      *((_DWORD *)v10 + 3) = 1;
      *(_QWORD *)(v10 + 20) = v11;
      *((_DWORD *)v10 + 10) = nPhi;
      *(_DWORD *)v10 = &CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v10 + 2) = &CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v10 + 4) = RenderWireframeSphere;
      *((float *)v10 + 7) = z;
      *((float *)v10 + 8) = flRadius;
      *((_DWORD *)v10 + 9) = nTheta;
      *((Color *)v10 + 11) = c;
      v10[48] = bZBuffer;
    }
    else
    {
      v10 = nullptr;
    }
    v8->QueueFunctorInternal(this: v8, a2: (CFunctor *)v10);
    v7->EndRender(this: v7);
    v7->Release(this: v7);
  }
  else
  {
    v12 = nPhi;
    v13 = nPhi * (nTheta + 1);
    v14 = (nPhi - 1) * (4 * (nTheta + 1) - 4);
    nThetaa = nTheta + 1;
    v15 = s_pWireframe;
    v47 = nPhi - 1;
    if ( !bZBuffer )
      v15 = s_pWireframeIgnoreZ;
    pRenderContext.m_pObject->Bind(this: pRenderContext.m_pObject, a2: v15, a3: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    pMesh = pRenderContext.m_pObject->GetDynamicMesh(this: pRenderContext.m_pObject, a2: 1, a3: 0, a4: 0, a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_LINES,
      nVertexCount: v13,
      nIndexCount: v14,
      pMeshSettings: nullptr);
    chBlue = c._color[2];
    v16 = 0;
    chGreen = c._color[1];
    chRed = c._color[0];
    chAlpha = c._color[3];
    i = 0;
    if ( nPhi <= 0 )
    {
      v17 = nThetaa;
    }
    else
    {
      do
      {
        v17 = nThetaa;
        v18 = 0;
        if ( nThetaa > 0 )
        {
          v39 = (float)(nThetaa - 1);
          phi = (float)((float)v16 / (float)v47) * 3.141592653589793;
          v19 = phi;
          __libm_sse2_cos(x: v33);
          *(float *)&v19 = v19;
          v41 = *(float *)&v19 * flRadius;
          v20 = phi;
          __libm_sse2_sin(x: v34);
          *(float *)&v20 = v20;
          v48 = *(float *)&v20 * flRadius;
          v21 = chBlue | ((chGreen | ((chRed | (chAlpha << 8)) << 8)) << 8);
          do
          {
            theta = (float)((float)v18 / v39) * 6.283185307179586;
            v22 = theta;
            __libm_sse2_sin(x: v33);
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *(float *)&v22 = v22;
            v43 = (float)(*(float *)&v22 * v48) + vCenter->y;
            v42 = v41 + vCenter->z;
            v24 = theta;
            __libm_sse2_cos(x: v35);
            *(float *)&v24 = v24;
            *m_pCurrPosition = (float)(*(float *)&v24 * v48) + vCenter->x;
            m_pCurrPosition[1] = v43;
            m_pCurrPosition[2] = v42;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v21;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v18;
          }
          while ( v18 < nThetaa );
          v16 = i;
          v12 = nPhi;
          v17 = nThetaa;
        }
        i = ++v16;
      }
      while ( v16 < v12 );
    }
    if ( v47 > 0 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      v26 = 0;
      i = 0;
      v48 = *(float *)&v47;
      do
      {
        if ( v17 - 1 > 0 )
        {
          v47 = v17 - 1;
          do
          {
            meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v26
                                                                   + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v27 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v27;
            if ( v27 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v27;
            meshBuilder.m_IndexBuilder.m_pIndices[v27] = v17 + v26 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v28 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v28;
            if ( v28 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v28;
            meshBuilder.m_IndexBuilder.m_pIndices[v28] = v26 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v29 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v29;
            if ( v29 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v29;
            meshBuilder.m_IndexBuilder.m_pIndices[v29] = v26 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + 1;
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
            if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            ++v26;
            --v47;
          }
          while ( *(float *)&v47 != 0.0 );
        }
        v26 = v17 + i;
        v30 = LODWORD(v48)-- == 1;
        i += v17;
      }
      while ( !v30 );
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027CB60
// Name: void RenderSphereInternal(class Vector const __near &,float,int,int,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderSphereInternal(
        int a1@<esi>,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  ICallQueue *v9; // edi
  float z; // eax
  char *v11; // eax
  __int64 v12; // xmm0_8
  float v13; // ecx
  int v14; // edi
  int v15; // esi
  bool v16; // zf
  int v17; // esi
  int v18; // edx
  float v19; // xmm1_4
  int v20; // eax
  int v21; // esi
  double v22; // xmm0_8
  double v23; // xmm0_8
  int v24; // edi
  double v25; // xmm0_8
  double v26; // xmm0_8
  float *m_pCurrPosition; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float *v30; // eax
  signed int m_nCurrentIndex; // eax
  int v32; // esi
  signed int v33; // eax
  int v34; // ecx
  signed int v35; // eax
  signed int v36; // eax
  int m_nVertexCount; // eax
  long double v38; // [esp+0h] [ebp-25Ch]
  long double v39; // [esp+0h] [ebp-25Ch]
  long double v40; // [esp+0h] [ebp-25Ch]
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-254h] BYREF
  Vector4D vecTangent; // [esp+1F0h] [ebp-6Ch] BYREF
  float v43; // [esp+200h] [ebp-5Ch]
  float v44; // [esp+204h] [ebp-58h]
  float theta; // [esp+208h] [ebp-54h]
  float flOONTheta; // [esp+20Ch] [ebp-50h]
  float v47; // [esp+210h] [ebp-4Ch]
  float v48; // [esp+214h] [ebp-48h]
  float v49; // [esp+218h] [ebp-44h]
  IMesh *pMesh; // [esp+21Ch] [ebp-40h]
  Vector vecPos; // [esp+220h] [ebp-3Ch]
  Vector vecNormal; // [esp+22Ch] [ebp-30h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+238h] [ebp-24h]
  int phi; // [esp+23Ch] [ebp-20h]
  int idx; // [esp+240h] [ebp-1Ch]
  int j; // [esp+244h] [ebp-18h]
  unsigned __int8 chRed; // [esp+24Bh] [ebp-11h]
  float v58; // [esp+24Ch] [ebp-10h]
  unsigned __int8 chGreen; // [esp+253h] [ebp-9h]
  int i; // [esp+254h] [ebp-8h]
  unsigned __int8 chAlpha; // [esp+25Ah] [ebp-2h]
  unsigned __int8 chBlue; // [esp+25Bh] [ebp-1h]

  InitializeStandardMaterials(a1);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v9 = m_pObject->GetCallQueue(this: m_pObject);
  if ( v9 != nullptr )
  {
    z = vCenter->z;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vCenter->x;
    vecNormal.z = z;
    v11 = (char *)MemAlloc_Alloc(nSize: 0x38u);
    if ( v11 != nullptr )
    {
      v12 = *(_QWORD *)&vecNormal.x;
      v13 = vecNormal.z;
      *((_DWORD *)v11 + 3) = 1;
      *(_QWORD *)(v11 + 20) = v12;
      *((float *)v11 + 7) = v13;
      *((_DWORD *)v11 + 10) = nPhi;
      *((_DWORD *)v11 + 9) = nTheta;
      *(_DWORD *)v11 = &CFunctor7<void (__cdecl *)(Vector const &,float,int,int,Color,IMaterial *,bool),Vector,float,int,int,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v11 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,float,int,int,Color,IMaterial *,bool),Vector,float,int,int,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v11 + 4) = RenderSphereInternal;
      *((float *)v11 + 8) = flRadius;
      *((Color *)v11 + 11) = c;
      *((_DWORD *)v11 + 12) = pMaterial;
      v11[52] = bInsideOut;
      v9->QueueFunctorInternal(this: v9, a2: (CFunctor *)v11);
    }
    else
    {
      v9->QueueFunctorInternal(this: v9, a2: nullptr);
    }
  }
  else
  {
    v14 = nTheta;
    chGreen = c._color[1];
    chRed = c._color[0];
    chBlue = c._color[2];
    v15 = nTheta * (nPhi - 1);
    v16 = 2 * v15 == 0;
    v17 = 2 * v15;
    chAlpha = c._color[3];
    phi = (nTheta + 1) * (2 * nPhi - 2);
    if ( !v16 )
    {
      pRenderContext.m_pObject->Bind(this: pRenderContext.m_pObject, a2: pMaterial, a3: nullptr);
      pMesh = pRenderContext.m_pObject->GetDynamicMesh(this: pRenderContext.m_pObject, a2: 1, a3: 0, a4: 0, a5: 0);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh,
        type: MATERIAL_TRIANGLE_STRIP,
        nVertexCount: v17,
        nIndexCount: phi,
        pMeshSettings: nullptr);
      v18 = nPhi;
      v19 = (float)(nPhi - 1);
      *(float *)&idx = 1.0 / v19;
      v20 = 0;
      v49 = v19;
      v47 = (float)(nTheta - 1);
      flOONTheta = 1.0 / v47;
      for ( i = 0; v20 < v18; i = v20 )
      {
        v21 = 0;
        if ( v14 > 0 )
        {
          *(float *)&j = (float)v20;
          *(float *)&phi = (float)((float)v20 / v19) * 3.141592653589793;
          v22 = *(float *)&phi;
          __libm_sse2_sin(x: v38);
          *(float *)&v22 = v22;
          v58 = *(float *)&v22 * flRadius;
          v23 = *(float *)&phi;
          __libm_sse2_cos(x: v39);
          *(float *)&v23 = v23;
          v48 = *(float *)&v23 * flRadius;
          v24 = chBlue | ((chGreen | ((chRed | (chAlpha << 8)) << 8)) << 8);
          v43 = *(float *)&j * *(float *)&idx;
          do
          {
            v44 = (float)v21;
            theta = (float)((float)v21 / v47) * 6.283185307179586;
            v25 = theta;
            __libm_sse2_cos(x: v38);
            *(float *)&v25 = v25;
            vecPos.x = *(float *)&v25 * v58;
            v26 = theta;
            __libm_sse2_sin(x: v40);
            *(float *)&v26 = v26;
            vecPos.y = *(float *)&v26 * v58;
            vecPos.z = v48;
            vecNormal = vecPos;
            VectorNormalize(vec: &vecNormal);
            LODWORD(vecTangent.x) = LODWORD(vecPos.y) ^ _mask__NegFloat_;
            vecTangent.y = vecPos.x;
            *(_QWORD *)&vecTangent.z = 0x3F80000000000000LL;
            VectorNormalize(vec: (Vector *)&vecTangent);
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            v28 = vCenter->y + vecPos.y;
            v29 = vCenter->z + vecPos.z;
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + vecPos.x;
            m_pCurrPosition[1] = v28;
            m_pCurrPosition[2] = v29;
            *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
            *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_UserData) = vecTangent;
            v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v44 * flOONTheta;
            v30[1] = v43;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v21;
          }
          while ( v21 < nTheta );
          v19 = v49;
          v14 = nTheta;
          v20 = i;
          v18 = nPhi;
        }
        ++v20;
      }
      *(float *)&idx = 0.0;
      i = 0;
      if ( v18 - 1 > 0 )
      {
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        v58 = 0.0;
        do
        {
          if ( bInsideOut )
          {
            j = v14 - 1;
            if ( v14 - 1 >= 0 )
            {
              v32 = v14 - 1 + LODWORD(v58);
              do
              {
                meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v14
                                                                       + v32
                                                                       + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
                v33 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                idx = v32;
                meshBuilder.m_IndexBuilder.m_nCurrentIndex = v33;
                if ( v33 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                  meshBuilder.m_IndexBuilder.m_nIndexCount = v33;
                meshBuilder.m_IndexBuilder.m_pIndices[v33] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v32;
                m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
                if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
                  meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
                v14 = nTheta;
                --v32;
                --j;
              }
              while ( j >= 0 );
              v18 = nPhi;
            }
          }
          else
          {
            if ( v14 > 0 )
            {
              *(float *)&v34 = v58;
              *(float *)&j = v58;
              phi = v14;
              do
              {
                idx = v34;
                meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v14
                                                                       + v34
                                                                       + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
                v35 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                meshBuilder.m_IndexBuilder.m_nCurrentIndex = v35;
                if ( v35 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                  meshBuilder.m_IndexBuilder.m_nIndexCount = v35;
                meshBuilder.m_IndexBuilder.m_pIndices[v35] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v34;
                m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
                if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
                  meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
                v34 = j + 1;
                v16 = phi-- == 1;
                ++j;
              }
              while ( !v16 );
              v18 = nPhi;
            }
            if ( i < v18 - 2 )
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = idx
                                                                     + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
              v36 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = v36;
              if ( v36 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                meshBuilder.m_IndexBuilder.m_nIndexCount = v36;
              meshBuilder.m_IndexBuilder.m_pIndices[v36] = v14
                                                         + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                         + idx
                                                         + 1;
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
                meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
          }
          ++i;
          LODWORD(v58) += v14;
        }
        while ( i < v18 - 1 );
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
      meshBuilder.m_pMesh->UnlockMesh(
        this: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
        a4: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_pMesh = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    }
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1027D250
// Name: void RenderSphere(class Vector const __near &,float,int,int,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderSphere(
        int a1@<esi>,
        const Vector *vCenter,
        __int64 flRadius,
        int nPhi,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  RenderSphereInternal(
    a1,
    vCenter,
    flRadius: *(float *)&flRadius,
    nTheta: SHIDWORD(flRadius),
    nPhi,
    c,
    pMaterial,
    bInsideOut);
}

//------------------------------------------------------------------------------
// Address: 0x1027D280
// Name: void RenderWireframeBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        bool bZBuffer)
{
  IMatRenderContext *v7; // esi
  float z; // edi
  float v9; // ebx
  __int64 v10; // xmm0_8
  float v11; // ecx
  char *v12; // eax
  __int64 v13; // xmm0_8
  float v14; // edx
  float v15; // ecx
  IMaterial *v16; // eax
  IMatRenderContext v17; // edx
  IMesh *v18; // esi
  int v19; // esi
  int *v20; // ebx
  int i; // edi
  float *m_pCurrPosition; // ecx
  Vector *v23; // eax
  int v24; // eax
  float *v25; // ecx
  int v26; // eax
  double x; // st7
  Vector *v28; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  Vector p[8]; // [esp+Ch] [ebp-284h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-224h] BYREF
  __int64 v33; // [esp+254h] [ebp-3Ch]
  __int64 v34; // [esp+260h] [ebp-30h]
  __int64 v35; // [esp+26Ch] [ebp-24h]
  float v36; // [esp+274h] [ebp-1Ch]
  __int64 v37; // [esp+278h] [ebp-18h]
  float v38; // [esp+280h] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+284h] [ebp-Ch]
  IMesh *pMesh; // [esp+288h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+28Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+28Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+28Fh] [ebp-1h]

  InitializeStandardMaterials(a1);
  v7 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  pMesh = (IMesh *)v7->GetCallQueue(this: v7);
  if ( pMesh != nullptr )
  {
    z = vMaxs->z;
    v9 = vMins->z;
    v34 = *(_QWORD *)&vMaxs->x;
    v33 = *(_QWORD *)&vMins->x;
    v10 = *(_QWORD *)&angles->x;
    v36 = angles->z;
    v11 = vOrigin->z;
    v35 = v10;
    v37 = *(_QWORD *)&vOrigin->x;
    v38 = v11;
    v12 = (char *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v12 != nullptr )
    {
      v13 = v37;
      v14 = v38;
      v15 = v36;
      *((_DWORD *)v12 + 3) = 1;
      *(_QWORD *)(v12 + 20) = v13;
      *((_QWORD *)v12 + 4) = v35;
      *(_QWORD *)(v12 + 44) = v33;
      *((_QWORD *)v12 + 7) = v34;
      *((float *)v12 + 10) = v15;
      *(_DWORD *)v12 = &CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v12 + 2) = &CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v12 + 4) = RenderWireframeBox;
      *((float *)v12 + 7) = v14;
      *((float *)v12 + 13) = v9;
      *((float *)v12 + 16) = z;
      *((Color *)v12 + 17) = c;
      v12[72] = bZBuffer;
    }
    else
    {
      v12 = nullptr;
    }
    ((void (__thiscall *)(IMesh *, char *))pMesh->VertexCount)(a1: pMesh, a2: v12);
    v7->EndRender(this: v7);
    v7->Release(this: v7);
  }
  else
  {
    v16 = s_pWireframe;
    if ( !bZBuffer )
      v16 = s_pWireframeIgnoreZ;
    v7->Bind(this: v7, a2: v16, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chBlue = c._color[2];
    v17.__vftable = v7->__vftable;
    chGreen = c._color[1];
    chAlpha = c._color[3];
    v18 = v17.GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v18;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v18;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v18->SetPrimitiveType(this: v18, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 48, a3: 48, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v18->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 48;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v18, nMaxVertexCount: 48, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v19 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v20 = s_pBoxFaceIndices[0];
    do
    {
      for ( i = 0; i < 4; ++i )
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v23 = &p[v20[i]];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v23->x;
        m_pCurrPosition[1] = v23->y;
        m_pCurrPosition[2] = v23->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v19;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( i == 3 )
          v24 = 0;
        else
          v24 = i + 1;
        v25 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v26 = v20[v24];
        x = p[v26].x;
        v28 = &p[v26];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
        v25[1] = v28->y;
        v25[2] = v28->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v19;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      }
      v20 += 4;
    }
    while ( (int)v20 < (int)s_pBoxFaceIndicesInsideOut[0] );
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D6A0
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v10; // edi
  __int64 v11; // xmm0_8
  float v12; // ecx
  char *v13; // eax
  __int64 v14; // xmm0_8
  float v15; // edx
  float v16; // ecx
  __int64 v17; // xmm0_8
  ICallQueue *v18; // ecx
  IMatRenderContext v19; // eax
  IMesh *v20; // esi
  unsigned int v21; // ecx
  int v22; // edi
  ICallQueue *v23; // eax
  int v24; // xmm1_4
  int *v25; // eax
  int v26; // esi
  int v27; // edx
  int v28; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v31; // eax
  double v32; // st7
  Vector *v33; // eax
  float *m_pCurrNormal; // eax
  float *v35; // eax
  float *v36; // ecx
  float v37; // xmm0_4
  Vector *v38; // eax
  float *v39; // eax
  int v40; // xmm0_4
  float *v41; // eax
  float *v42; // ecx
  float v43; // xmm0_4
  Vector *v44; // eax
  float *v45; // eax
  int v46; // xmm0_4
  float *v47; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v51; // [esp+254h] [ebp-4Ch]
  __int64 v52; // [esp+260h] [ebp-40h]
  __int64 v53; // [esp+26Ch] [ebp-34h]
  float v54; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v10 = vMins->z;
    v51 = *(_QWORD *)&vMaxs->x;
    v52 = *(_QWORD *)&vMins->x;
    v11 = *(_QWORD *)&angles->x;
    v54 = angles->z;
    v12 = vOrigin->z;
    v53 = v11;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v12;
    v13 = (char *)MemAlloc_Alloc(nSize: 0x50u);
    if ( v13 != nullptr )
    {
      v14 = *(_QWORD *)&vecNormal.x;
      v15 = vecNormal.z;
      v16 = v54;
      *((_DWORD *)v13 + 3) = 1;
      *(_QWORD *)(v13 + 20) = v14;
      *((_QWORD *)v13 + 4) = v53;
      *(_QWORD *)(v13 + 44) = v52;
      v17 = v51;
      *((float *)v13 + 10) = v16;
      *((_QWORD *)v13 + 7) = v17;
      *((float *)v13 + 7) = v15;
      *(_DWORD *)v13 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v13 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v13 + 4) = RenderBoxInternal;
      *((float *)v13 + 13) = v10;
      *((float *)v13 + 16) = z;
      *((Color *)v13 + 17) = c;
      *((_DWORD *)v13 + 18) = pMaterial;
      v18 = pCallQueue;
      v13[76] = bInsideOut;
      v18->QueueFunctorInternal(this: v18, a2: (CFunctor *)v13);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v19.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v20 = v19.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v20;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v20;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v20->SetPrimitiveType(this: v20, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v20->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v20, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v21 = 0;
    i = 0;
    v22 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v23 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v24 = (v21 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v21 >> 1)) = v24;
      if ( bInsideOut )
      {
        v25 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v23);
        ppFaceIndices = v25;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v23);
        v25 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v23);
      }
      v26 = 1;
      while ( 1 )
      {
        v27 = v25[v26];
        v28 = v25[v26 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v31 = *v25;
        v32 = p[v31].x;
        v33 = &p[v31];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v32;
        i1 = v27;
        m_pCurrPosition[1] = v33->y;
        m_pCurrPosition[2] = v33->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v35[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v36 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v37 = vecNormal.x;
        v38 = &p[v28];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v38->x;
        v36[1] = v38->y;
        v36[2] = v38->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        v39 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v37;
        v39[1] = vecNormal.y;
        v39[2] = vecNormal.z;
        v40 = v26 == 1 ? 1065353216 : 0;
        v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v41 + 1) = v40;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v42 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v43 = vecNormal.x;
        v44 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v44->x;
        v42[1] = v44->y;
        v42[2] = v44->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        v45 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v43;
        v45[1] = vecNormal.y;
        v45[2] = vecNormal.z;
        v46 = v26 == 1 ? 0 : 1065353216;
        v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v46;
        v47[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v26 >= 3 )
          break;
        v25 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v23 = pCallQueue;
      v21 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1027DC40
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        __int16 bZBuffer,
        bool bInsideOut)
{
  IMaterial *v8; // ecx

  InitializeStandardMaterials(a1);
  v8 = s_pVertexColor;
  if ( (_BYTE)bZBuffer == 0 )
    v8 = s_pVertexColorIgnoreZ;
  RenderBoxInternal(a1, vOrigin, angles, vMins, vMaxs, c, pMaterial: v8, bInsideOut);
}

//------------------------------------------------------------------------------
// Address: 0x1027DCA0
// Name: void RenderLine(class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall RenderLine(int a1@<esi>, const Vector *v1, const Vector *v2, Color c, bool bZBuffer)
{
  IMatRenderContext *v5; // ebx
  float z; // edi
  float v7; // eax
  char *v8; // eax
  __int64 v9; // xmm0_8
  float v10; // ecx
  __int64 v11; // xmm0_8
  ICallQueue *v12; // ecx
  IMaterial *v13; // eax
  IMatRenderContext_vtbl *v14; // eax
  IMesh *v15; // edi
  float *m_pCurrPosition; // eax
  int v17; // esi
  int v18; // edx
  int v19; // ecx
  int v20; // esi
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-208h] BYREF
  __int64 v23; // [esp+1F4h] [ebp-20h]
  __int64 v24; // [esp+200h] [ebp-14h]
  float v25; // [esp+208h] [ebp-Ch]
  ICallQueue *pCallQueue; // [esp+20Ch] [ebp-8h]
  unsigned __int8 chAlpha; // [esp+210h] [ebp-4h]
  __int16 chRed; // [esp+211h] [ebp-3h] OVERLAPPED
  unsigned __int8 chBlue; // [esp+213h] [ebp-1h]

  InitializeStandardMaterials(a1);
  v5 = materials->GetRenderContext(this: materials);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  pCallQueue = v5->GetCallQueue(this: v5);
  if ( pCallQueue != nullptr )
  {
    z = v2->z;
    v23 = *(_QWORD *)&v2->x;
    v7 = v1->z;
    v24 = *(_QWORD *)&v1->x;
    v25 = v7;
    v8 = (char *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v8 != nullptr )
    {
      v9 = v24;
      v10 = v25;
      *((_DWORD *)v8 + 3) = 1;
      *(_QWORD *)(v8 + 20) = v9;
      v11 = v23;
      *((float *)v8 + 7) = v10;
      *((_QWORD *)v8 + 4) = v11;
      *(_DWORD *)v8 = &CFunctor4<void (__cdecl *)(Vector const &,Vector const &,Color,bool),Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v8 + 2) = &CFunctor4<void (__cdecl *)(Vector const &,Vector const &,Color,bool),Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v8 + 4) = RenderLine;
      *((float *)v8 + 10) = z;
      v8[48] = bZBuffer;
      v12 = pCallQueue;
      *((Color *)v8 + 11) = c;
      v12->QueueFunctorInternal(this: v12, a2: (CFunctor *)v8);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    v13 = s_pWireframe;
    if ( !bZBuffer )
      v13 = s_pWireframeIgnoreZ;
    v5->Bind(this: v5, a2: v13, a3: nullptr);
    chRed = *(_WORD *)c._color;
    v14 = v5->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v15 = v14->GetDynamicMesh(this: v5, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v15;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v15->SetPrimitiveType(this: v15, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v15->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v15, nMaxVertexCount: 2, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v17 = chAlpha;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v1->x;
    v18 = chBlue;
    m_pCurrPosition[1] = v1->y;
    v19 = HIBYTE(chRed);
    m_pCurrPosition[2] = v1->z;
    v20 = v18 | ((v19 | (((unsigned __int8)chRed | (v17 << 8)) << 8)) << 8);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v20;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = *v2;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v20;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v15->Draw_2(this: v15, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
  v5->EndRender(this: v5);
  v5->Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1027DFD0
// Name: void RenderTriangleInternal(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall RenderTriangleInternal(
        int a1@<esi>,
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        Color c,
        IMaterial *pMaterial)
{
  IMatRenderContext *v6; // edi
  float z; // esi
  float v8; // ebx
  float v9; // eax
  char *v10; // eax
  __int64 v11; // xmm0_8
  float v12; // ecx
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm5_4
  IMesh *v19; // edi
  float *m_pCurrPosition; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // esi
  int v24; // esi
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-224h] BYREF
  __int64 v31; // [esp+1F4h] [ebp-3Ch]
  __int64 v32; // [esp+200h] [ebp-30h]
  __int64 v33; // [esp+20Ch] [ebp-24h]
  float v34; // [esp+214h] [ebp-1Ch]
  ICallQueue *pCallQueue; // [esp+218h] [ebp-18h]
  CMatRenderContextPtr pRenderContext; // [esp+21Ch] [ebp-14h]
  Vector vecNormal; // [esp+220h] [ebp-10h] BYREF
  unsigned __int8 chBlue; // [esp+22Ch] [ebp-4h]
  unsigned __int8 chAlpha; // [esp+22Dh] [ebp-3h]
  __int16 chRed; // [esp+22Eh] [ebp-2h] OVERLAPPED

  InitializeStandardMaterials(a1);
  v6 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  pCallQueue = v6->GetCallQueue(this: v6);
  if ( pCallQueue != nullptr )
  {
    z = p3->z;
    v8 = p2->z;
    v31 = *(_QWORD *)&p3->x;
    v32 = *(_QWORD *)&p2->x;
    v9 = p1->z;
    v33 = *(_QWORD *)&p1->x;
    v34 = v9;
    v10 = (char *)MemAlloc_Alloc(nSize: 0x40u);
    if ( v10 != nullptr )
    {
      v11 = v33;
      v12 = v34;
      *((_DWORD *)v10 + 3) = 1;
      *(_QWORD *)(v10 + 20) = v11;
      *((_QWORD *)v10 + 4) = v32;
      *(_QWORD *)(v10 + 44) = v31;
      *((float *)v10 + 7) = v12;
      *(_DWORD *)v10 = &CFunctor5<void (__cdecl *)(Vector const &,Vector const &,Vector const &,Color,IMaterial *),Vector,Vector,Vector,Color,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v10 + 2) = &CFunctor5<void (__cdecl *)(Vector const &,Vector const &,Vector const &,Color,IMaterial *),Vector,Vector,Vector,Color,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v10 + 4) = RenderTriangleInternal;
      *((float *)v10 + 10) = v8;
      *((float *)v10 + 13) = z;
      *((Color *)v10 + 14) = c;
      *((_DWORD *)v10 + 15) = pMaterial;
    }
    else
    {
      v10 = nullptr;
    }
    pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: (CFunctor *)v10);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
  else
  {
    v6->Bind(this: v6, a2: pMaterial, a3: nullptr);
    v13 = p2->y - p1->y;
    v14 = p2->z - p1->z;
    v15 = p2->x - p1->x;
    chRed = *(_WORD *)c._color;
    chBlue = c._color[2];
    v16 = p3->y - p1->y;
    v17 = p3->z - p1->z;
    v18 = p3->x - p1->x;
    chAlpha = c._color[3];
    vecNormal.x = (float)(v17 * v13) - (float)(v16 * v14);
    vecNormal.y = (float)(v14 * v18) - (float)(v17 * v15);
    vecNormal.z = (float)(v16 * v15) - (float)(v13 * v18);
    VectorNormalize(vec: &vecNormal);
    v19 = v6->GetDynamicMesh(this: v6, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v19;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v19->SetPrimitiveType(this: v19, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 3, a3: 3, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v19->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 3;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v19, nMaxVertexCount: 3, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v21 = (unsigned __int8)chRed;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = p1->x;
    v22 = HIBYTE(chRed);
    m_pCurrPosition[1] = p1->y;
    v23 = chAlpha;
    m_pCurrPosition[2] = p1->z;
    v24 = chBlue | ((v22 | ((v21 | (v23 << 8)) << 8)) << 8);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
    v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v25[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = *p2;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
    v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v26[1] = 1.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = *p3;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
    v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v27[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v19->Draw_2(this: v19, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E470
// Name: void RenderTriangle(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderTriangle(
        int a1@<esi>,
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        Color c,
        __int16 bZBuffer)
{
  IMaterial *v6; // ecx

  InitializeStandardMaterials(a1);
  v6 = s_pVertexColor;
  if ( (_BYTE)bZBuffer == 0 )
    v6 = s_pVertexColorIgnoreZ;
  RenderTriangleInternal(a1, p1, p2, p3, c, pMaterial: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1031DF80
// Name: _dynamic_initializer_for__render_blanks_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__render_blanks_command__()
{
  ConCommand::ConCommand(
    this: &render_blanks_command,
    pName: "render_blanks",
    callback: (void (__cdecl *)())render_blanks,
    pHelpString: "render N blank frames",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__render_blanks_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326A60
// Name: _dynamic_atexit_destructor_for__render_blanks_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__render_blanks_command__()
{
  ConCommand::~ConCommand(this: &render_blanks_command);
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x1025D540
// Name: void DrawScreenSpaceRectangle(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawScreenSpaceRectangle(
        int a1@<edi>,
        int a2@<esi>,
        IMaterial *pMaterial,
        int nDestX,
        int nDestY,
        int nWidth,
        int nHeight,
        float flSrcTextureX0,
        float flSrcTextureY0,
        float flSrcTextureX1,
        float flSrcTextureY1,
        int nSrcTextureWidth,
        int nSrcTextureHeight,
        void *pClientRenderable,
        int nXDice,
        int nYDice,
        float fDepth)
{
  IMatRenderContext *v17; // ebx
  int v18; // edi
  IMesh_vtbl *v19; // eax
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v21; // esi
  int v22; // esi
  float v23; // xmm4_4
  float v24; // xmm3_4
  void (__thiscall *GetViewport)(IMatRenderContext *, int *, int *, int *, int *); // edx
  float v26; // xmm3_4
  float v27; // xmm4_4
  int v28; // ecx
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  int v32; // xmm1_4
  int v33; // edi
  bool v34; // dl
  float *v35; // eax
  float *v36; // eax
  int v37; // xmm3_4
  int v38; // xmm1_4
  float *v39; // eax
  _DWORD *v40; // eax
  _DWORD *v41; // eax
  int v42; // xmm3_4
  float v43; // xmm7_4
  float v44; // xmm5_4
  int v45; // eax
  float v46; // xmm1_4
  float *m_pCurrPosition; // eax
  float v48; // xmm1_4
  float v49; // xmm4_4
  float v50; // xmm3_4
  float v51; // xmm0_4
  float *m_pCurrNormal; // eax
  float *v53; // eax
  _DWORD *v54; // eax
  _DWORD *v55; // eax
  float *v56; // eax
  float v57; // xmm2_4
  float *v58; // eax
  float *v59; // eax
  _DWORD *v60; // eax
  _DWORD *v61; // eax
  float *v62; // eax
  float v63; // xmm3_4
  float v64; // xmm1_4
  float *v65; // eax
  float *v66; // eax
  _DWORD *v67; // eax
  _DWORD *v68; // eax
  float *v69; // eax
  float v70; // xmm2_4
  float *v71; // eax
  float *v72; // eax
  _DWORD *v73; // eax
  _DWORD *v74; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-248h] BYREF
  int nScreenWidth; // [esp+1ECh] [ebp-60h] BYREF
  int vx; // [esp+1F0h] [ebp-5Ch] BYREF
  int vy; // [esp+1F4h] [ebp-58h] BYREF
  int nScreenHeight; // [esp+1F8h] [ebp-54h] BYREF
  float v82; // [esp+1FCh] [ebp-50h]
  float v83; // [esp+200h] [ebp-4Ch]
  int vh; // [esp+204h] [ebp-48h] BYREF
  float v85; // [esp+208h] [ebp-44h]
  float v86; // [esp+20Ch] [ebp-40h]
  float flUWidth; // [esp+210h] [ebp-3Ch]
  float flWidth; // [esp+214h] [ebp-38h]
  int vw; // [esp+218h] [ebp-34h] BYREF
  IMesh *pMesh; // [esp+21Ch] [ebp-30h]
  float v91; // [esp+220h] [ebp-2Ch]
  int x; // [esp+224h] [ebp-28h]
  float v93; // [esp+228h] [ebp-24h]
  int xSegments; // [esp+22Ch] [ebp-20h]
  float flLeftU; // [esp+230h] [ebp-1Ch]
  float flLeftX; // [esp+234h] [ebp-18h]
  float flRightU; // [esp+238h] [ebp-14h]
  float flVHeight; // [esp+23Ch] [ebp-10h]
  float flTexelsPerPixelX; // [esp+240h] [ebp-Ch]
  float flTexelsPerPixelY; // [esp+244h] [ebp-8h]
  int flHeight; // [esp+248h] [ebp-4h]
  float flTopY; // [esp+260h] [ebp+14h]

  v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v17 != nullptr )
    v17->BeginRender(this: v17);
  if ( nWidth <= 0 || nHeight <= 0 )
  {
    if ( v17 == nullptr )
      return;
  }
  else
  {
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    v17->Bind(this: v17, a2: pMaterial, a3: pClientRenderable);
    xSegments = nXDice;
    if ( nXDice <= 1 )
      xSegments = 1;
    v18 = nYDice;
    if ( nYDice <= 1 )
      v18 = 1;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int, int))v17->GetDynamicMesh)(
                                     a1: v17,
                                     a2: 1,
                                     a3: 0,
                                     a4: 0,
                                     a5: 0,
                                     a6: a1,
                                     a7: a2);
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v19 = meshBuilder.m_pMesh->__vftable;
    flHeight = 4 * xSegments * v18;
    SetPrimitiveType = v19->SetPrimitiveType;
    pMesh = meshBuilder.m_pMesh;
    v21 = 6 * xSegments * v18;
    ((void (__stdcall *)(int))SetPrimitiveType)(a1: 2);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: flHeight, a3: v21, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v21;
    CVertexBuilder::AttachBegin(
      this: &meshBuilder.m_VertexBuilder,
      pMesh,
      nMaxVertexCount: flHeight,
      desc: &meshBuilder);
    v22 = 0;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v17->GetRenderTargetDimensions(this: v17, a2: &nScreenWidth, a3: &nScreenHeight);
    flLeftX = (float)nDestX - 0.5;
    flVHeight = (float)(nWidth + nDestX) - 0.5;
    *(float *)&flHeight = (float)(nHeight + nDestY) - 0.5;
    if ( nWidth <= 1 )
      v23 = 0.0;
    else
      v23 = (float)(flSrcTextureX1 - flSrcTextureX0) / (float)(nWidth - 1);
    flTexelsPerPixelX = v23;
    if ( nHeight <= 1 )
      v24 = 0.0;
    else
      v24 = (float)(flSrcTextureY1 - flSrcTextureY0) / (float)(nHeight - 1);
    GetViewport = v17->GetViewport;
    flTexelsPerPixelY = v24;
    v26 = 1.0 / (float)nSrcTextureWidth;
    v27 = 1.0 / (float)nSrcTextureHeight;
    flLeftU = (float)((float)(flSrcTextureX0 + 0.5) - (float)(flTexelsPerPixelX * 0.5)) * v26;
    flRightU = (float)((float)(flSrcTextureX1 + 0.5) + (float)(flTexelsPerPixelX * 0.5)) * v26;
    flTexelsPerPixelX = (float)((float)(flSrcTextureY0 + 0.5) - (float)(flTexelsPerPixelY * 0.5)) * v27;
    flTexelsPerPixelY = (float)((float)(flSrcTextureY1 + 0.5) + (float)(flTexelsPerPixelY * 0.5)) * v27;
    GetViewport(this: v17, a2: &vx, a3: &vy, a4: &vw, a5: &vh);
    v28 = xSegments;
    v29 = (float)((float)(flVHeight * 2.0) / (float)vw) - 1.0;
    v30 = (float)((float)(flLeftX * 2.0) / (float)vw) - 1.0;
    v31 = 1.0 - (float)((float)((float)((float)nDestY - 0.5) * 2.0) / (float)vh);
    *(float *)&v32 = 1.0 - (float)((float)(*(float *)&flHeight * 2.0) / (float)vh);
    flVHeight = v29;
    flLeftX = v30;
    flTopY = v31;
    flHeight = v32;
    if ( xSegments > 1 || v18 > 1 )
    {
      *(float *)&v42 = (float)(v31 - *(float *)&v32) / (float)v18;
      v43 = (float)(flRightU - flLeftU) / (float)xSegments;
      v44 = (float)(v29 - v30) / (float)xSegments;
      v45 = 0;
      flWidth = v44;
      flHeight = v42;
      flUWidth = v43;
      flVHeight = (float)(flTexelsPerPixelY - flTexelsPerPixelX) / (float)v18;
      x = 0;
      if ( xSegments > 0 )
      {
        do
        {
          if ( v18 > 0 )
          {
            flRightU = (float)((float)(v45 + 1) * v44) + v30;
            flTexelsPerPixelY = (float)((float)(v45 + 1) * v43) + flLeftU;
            v46 = (float)((float)v45 * v44) + v30;
            v93 = v46;
            v91 = (float)((float)v45 * v43) + flLeftU;
            while ( 1 )
            {
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = v46;
              v48 = (float)((float)v22 * flVHeight) + flTexelsPerPixelX;
              v49 = (float)v22 * *(float *)&v42;
              v50 = v91;
              v51 = v31 - v49;
              m_pCurrPosition[1] = v51;
              v86 = v51;
              m_pCurrPosition[2] = fDepth;
              m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              m_pCurrNormal[1] = 0.0;
              m_pCurrNormal[2] = 1.0;
              v53 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v50;
              v53[1] = v48;
              v54 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v54 = 0;
              v54[1] = 1065353216;
              v54[2] = 0;
              v55 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              v82 = v48;
              *v55 = 1065353216;
              v55[1] = 0;
              v55[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v56 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = flRightU;
              v57 = flTexelsPerPixelY;
              v56[1] = v86;
              v56[2] = fDepth;
              v58 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v58[1] = 0.0;
              v58[2] = 1.0;
              v59 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v57;
              v59[1] = v82;
              v60 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v60 = 0;
              v60[1] = 1065353216;
              v60[2] = 0;
              v61 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              *v61 = 1065353216;
              v61[1] = 0;
              v61[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v62 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              ++v22;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = flRightU;
              v83 = flTopY - (float)((float)v22 * *(float *)&flHeight);
              v62[1] = v83;
              v63 = flTexelsPerPixelY;
              v64 = (float)((float)v22 * flVHeight) + flTexelsPerPixelX;
              v62[2] = fDepth;
              v65 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v65[1] = 0.0;
              v65[2] = 1.0;
              v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v63;
              v66[1] = v64;
              v67 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v67 = 0;
              v67[1] = 1065353216;
              v67[2] = 0;
              v68 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              v85 = v64;
              *v68 = 1065353216;
              v68[1] = 0;
              v68[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v69 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = v93;
              v70 = v91;
              v69[1] = v83;
              v69[2] = fDepth;
              v71 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v71[1] = 0.0;
              v71[2] = 1.0;
              v72 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v70;
              v72[1] = v85;
              v73 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v73 = 0;
              v73[1] = 1065353216;
              v73[2] = 0;
              v74 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              *v74 = 1065353216;
              v74[1] = 0;
              v74[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v31 = flTopY;
              v42 = flHeight;
              if ( v22 >= v18 )
                break;
              v46 = v93;
            }
            v30 = flLeftX;
            v44 = flWidth;
            v43 = flUWidth;
            v45 = x;
            v28 = xSegments;
          }
          ++v45;
          v22 = 0;
          x = v45;
        }
        while ( v45 < v28 );
      }
    }
    else
    {
      v33 = 0;
      while ( 1 )
      {
        v34 = v33 == 0 || v33 == 3;
        if ( (v33 & 2) != 0 )
          v31 = *(float *)&v32;
        if ( v34 )
          v29 = v30;
        v35 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
        v35[1] = v31;
        v35[2] = fDepth;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
        v36[1] = 0.0;
        v36[2] = 1.0;
        v37 = (v33 & 2) != 0 ? LODWORD(flTexelsPerPixelY) : LODWORD(flTexelsPerPixelX);
        v38 = v34 ? LODWORD(flLeftU) : LODWORD(flRightU);
        v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v38;
        *((_DWORD *)v39 + 1) = v37;
        v40 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                       + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
        *v40 = 0;
        v40[1] = 1065353216;
        v40[2] = 0;
        v41 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                       + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
        *v41 = 1065353216;
        v41[1] = 0;
        v41[2] = 0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v33 >= 4 )
          break;
        v30 = flLeftX;
        v29 = flVHeight;
        v31 = flTopY;
        v32 = flHeight;
      }
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
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PopMatrix(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PopMatrix(this: v17);
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
  }
  v17->EndRender(this: v17);
  v17->Release(this: v17);
}

} // namespace MaterialSystem

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005DA720
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x005DA7E0
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<ecx>, int a2@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMaterial *v5; // eax
  IMaterial v6; // edx
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMaterial *v9; // eax
  IMaterial v10; // edx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  IMaterial *v13; // eax
  IMaterial v14; // edx
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  IMaterial *v17; // eax
  IMaterial v18; // edx

  if ( (_S1_9 & 1) == 0 )
  {
    _S1_9 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex__.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "wireframe");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$vertexcolor", value: 1);
  v5 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v4,
                      a4: a2,
                      a5: a1);
  v6.__vftable = v5->__vftable;
  s_pWireframe = v5;
  v6.IncrementReferenceCount(this: v5);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "wireframe");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
  v9 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v8);
  v10.__vftable = v9->__vftable;
  s_pWireframeIgnoreZ = v9;
  v10.IncrementReferenceCount(this: v9);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "unlitgeneric");
  else
    v12 = nullptr;
  KeyValues::SetInt(this: v12, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v12, keyName: "$vertexalpha", value: 1);
  v13 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v12);
  v14.__vftable = v13->__vftable;
  s_pVertexColor = v13;
  v14.IncrementReferenceCount(this: v13);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "unlitgeneric");
  else
    v16 = nullptr;
  KeyValues::SetInt(this: v16, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$ignorez", value: 1);
  v17 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColorIgnoreZ", a3: v16);
  v18.__vftable = v17->__vftable;
  s_pVertexColorIgnoreZ = v17;
  v18.IncrementReferenceCount(this: v17);
  if ( --autoMutex__.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x005DAA20
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x005DAA50
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v11; // edi
  __int64 v12; // xmm0_8
  float v13; // ecx
  char *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // edx
  float v17; // ecx
  __int64 v18; // xmm0_8
  ICallQueue *v19; // ecx
  IMatRenderContext v20; // eax
  IMesh *v21; // esi
  unsigned int v22; // ecx
  int v23; // edi
  ICallQueue *v24; // eax
  int v25; // xmm1_4
  int *v26; // eax
  int v27; // esi
  int v28; // edx
  int v29; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v32; // eax
  double v33; // st7
  Vector *v34; // eax
  float *m_pCurrNormal; // eax
  float *v36; // eax
  float *v37; // ecx
  float v38; // xmm0_4
  Vector *v39; // eax
  float *v40; // eax
  int v41; // xmm0_4
  float *v42; // eax
  float *v43; // ecx
  float v44; // xmm0_4
  Vector *v45; // eax
  float *v46; // eax
  int v47; // xmm0_4
  float *v48; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v52; // [esp+254h] [ebp-4Ch]
  __int64 v53; // [esp+260h] [ebp-40h]
  __int64 v54; // [esp+26Ch] [ebp-34h]
  float v55; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1, a2);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v11 = vMins->z;
    v52 = *(_QWORD *)&vMaxs->x;
    v53 = *(_QWORD *)&vMins->x;
    v12 = *(_QWORD *)&angles->x;
    v55 = angles->z;
    v13 = vOrigin->z;
    v54 = v12;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v13;
    v14 = (char *)MemAlloc_Alloc(nSize: 0x50u);
    if ( v14 != nullptr )
    {
      v15 = *(_QWORD *)&vecNormal.x;
      v16 = vecNormal.z;
      v17 = v55;
      *((_DWORD *)v14 + 3) = 1;
      *(_QWORD *)(v14 + 20) = v15;
      *((_QWORD *)v14 + 4) = v54;
      *(_QWORD *)(v14 + 44) = v53;
      v18 = v52;
      *((float *)v14 + 10) = v17;
      *((_QWORD *)v14 + 7) = v18;
      *((float *)v14 + 7) = v16;
      *(_DWORD *)v14 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v14 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v14 + 4) = RenderBoxInternal;
      *((float *)v14 + 13) = v11;
      *((float *)v14 + 16) = z;
      *((Color *)v14 + 17) = c;
      *((_DWORD *)v14 + 18) = pMaterial;
      v19 = pCallQueue;
      v14[76] = bInsideOut;
      v19->QueueFunctorInternal(this: v19, a2: (CFunctor *)v14);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v20.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v21 = v20.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v21;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v21;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v21->SetPrimitiveType(this: v21, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v21->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v21, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v22 = 0;
    i = 0;
    v23 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v24 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v25 = (v22 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v22 >> 1)) = v25;
      if ( bInsideOut )
      {
        v26 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v24);
        ppFaceIndices = v26;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
        v26 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
      }
      v27 = 1;
      while ( 1 )
      {
        v28 = v26[v27];
        v29 = v26[v27 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v32 = *v26;
        v33 = p[v32].x;
        v34 = &p[v32];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33;
        i1 = v28;
        m_pCurrPosition[1] = v34->y;
        m_pCurrPosition[2] = v34->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v36[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v37 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v38 = vecNormal.x;
        v39 = &p[v29];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39->x;
        v37[1] = v39->y;
        v37[2] = v39->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v40 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v38;
        v40[1] = vecNormal.y;
        v40[2] = vecNormal.z;
        v41 = v27 == 1 ? 1065353216 : 0;
        v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v42 + 1) = v41;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v44 = vecNormal.x;
        v45 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v45->x;
        v43[1] = v45->y;
        v43[2] = v45->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v44;
        v46[1] = vecNormal.y;
        v46[2] = vecNormal.z;
        v47 = v27 == 1 ? 0 : 1065353216;
        v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v47;
        v48[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v27 >= 3 )
          break;
        v26 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v24 = pCallQueue;
      v22 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005DAFF0
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  RenderBoxInternal(a1: (int)vMins, a2: a1, vOrigin, angles, vMins, vMaxs, c, pMaterial, bInsideOut);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027AF60
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x1027B020
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax
  IMaterial v5; // edx
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  IMaterial *v8; // eax
  IMaterial v9; // edx
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  IMaterial *v12; // eax
  IMaterial v13; // edx
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  IMaterial *v16; // eax
  IMaterial v17; // edx

  if ( (_S1_24 & 1) == 0 )
  {
    _S1_24 |= 1u;
    autoMutex___1.m_ownerID = 0;
    autoMutex___1.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex___1.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex___1, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex___1, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex___1.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex___1.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
  else
    v3 = nullptr;
  KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
  v4 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v3,
                      a4: a1);
  v5.__vftable = v4->__vftable;
  s_pWireframe = v4;
  v5.IncrementReferenceCount(this: v4);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "wireframe");
  else
    v7 = nullptr;
  KeyValues::SetInt(this: v7, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$ignorez", value: 1);
  v8 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v7);
  v9.__vftable = v8->__vftable;
  s_pWireframeIgnoreZ = v8;
  v9.IncrementReferenceCount(this: v8);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "unlitgeneric");
  else
    v11 = nullptr;
  KeyValues::SetInt(this: v11, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v11, keyName: "$vertexalpha", value: 1);
  v12 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v11);
  v13.__vftable = v12->__vftable;
  s_pVertexColor = v12;
  v13.IncrementReferenceCount(this: v12);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "unlitgeneric");
  else
    v15 = nullptr;
  KeyValues::SetInt(this: v15, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$ignorez", value: 1);
  v16 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *))g_pMaterialSystem->CreateMaterial)(
                       a1: g_pMaterialSystem,
                       a2: "__utilVertexColorIgnoreZ");
  v17.__vftable = v16->__vftable;
  s_pVertexColorIgnoreZ = v16;
  v17.IncrementReferenceCount(this: v16);
  if ( --autoMutex___1.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex___1, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1027B260
// Name: DrawAxes
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawAxes(const Vector *origin@<edi>, CMeshBuilder *meshBuilder@<esi>, Vector *pts, int idx, Color c)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float *m_pCurrPosition; // eax
  int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *v13; // eax
  float *v14; // eax
  int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float *v19; // eax
  float *v20; // eax
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *v25; // eax
  float start; // [esp+4h] [ebp-Ch]
  float start_4; // [esp+8h] [ebp-8h]
  float start_8; // [esp+Ch] [ebp-4h]

  v5 = origin->x + pts[idx].x;
  v6 = pts[idx].y + origin->y;
  v7 = pts[idx].z + origin->z;
  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = v5;
  m_pCurrPosition[1] = v6;
  m_pCurrPosition[2] = v7;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  start = v5;
  start_4 = v6;
  start_8 = v7;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  if ( (idx & 1) != 0 )
    v9 = idx - 1;
  else
    v9 = idx + 1;
  v10 = origin->x + pts[v9].x;
  v11 = pts[v9].y + origin->y;
  v12 = pts[v9].z + origin->z;
  v13 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v13 = v10;
  v13[1] = v11;
  v13[2] = v12;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v14 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v14 = start;
  v14[1] = start_4;
  v14[2] = start_8;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  if ( (idx & 2) != 0 )
    v15 = idx - 2;
  else
    v15 = idx + 2;
  v16 = origin->x + pts[v15].x;
  v17 = pts[v15].y + origin->y;
  v18 = pts[v15].z + origin->z;
  v19 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v19 = v16;
  v19[1] = v17;
  v19[2] = v18;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v20 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v20 = start;
  v20[1] = start_4;
  v20[2] = start_8;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  if ( (idx & 4) != 0 )
    v21 = idx - 4;
  else
    v21 = idx + 4;
  v22 = origin->x + pts[v21].x;
  v23 = pts[v21].y + origin->y;
  v24 = pts[v21].z + origin->z;
  v25 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v25 = v22;
  v25[1] = v23;
  v25[2] = v24;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1027B520
// Name: DrawExtrusionFace
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawExtrusionFace(
        int idx1@<eax>,
        CMeshBuilder *meshBuilder@<esi>,
        const Vector *start,
        const Vector *end,
        Vector *pts,
        int idx2,
        Color c)
{
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector *v11; // edi
  float *m_pCurrPosition; // eax
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float *v16; // eax
  float *v17; // eax
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float *v21; // eax
  float *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *v25; // eax
  float v26; // xmm0_4
  float *v27; // eax
  float *v28; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  Vector *ptsa; // [esp+1Ch] [ebp+10h]

  v7 = idx1;
  v8 = start->x + pts[v7].x;
  v9 = pts[v7].y + start->y;
  v10 = pts[v7].z + start->z;
  v11 = &pts[v7];
  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = v8;
  m_pCurrPosition[1] = v9;
  m_pCurrPosition[2] = v10;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v13 = start->x + pts[idx2].x;
  v14 = start->z + pts[idx2].z;
  v15 = pts[idx2].y + start->y;
  ptsa = &pts[idx2];
  v16 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v16 = v13;
  v16[1] = v15;
  v16[2] = v14;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v17 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v17 = v13;
  v17[1] = v15;
  v17[2] = v14;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v18 = end->x + ptsa->x;
  v19 = end->y + ptsa->y;
  v20 = ptsa->z + end->z;
  v21 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v21 = v18;
  v21[1] = v19;
  v21[2] = v20;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v22 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v22 = v18;
  v22[1] = v19;
  v22[2] = v20;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v23 = v11->y + end->y;
  v24 = v11->z + end->z;
  v25 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v26 = end->x + v11->x;
  *v25 = v26;
  v25[1] = v23;
  v25[2] = v24;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v27 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v27 = v26;
  v27[1] = v23;
  v27[2] = v24;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v28 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v29 = v11->y + start->y;
  v30 = v11->z + start->z;
  *v28 = start->x + v11->x;
  v28[1] = v29;
  v28[2] = v30;
  *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = c._color[2]
                                                       | ((c._color[1] | ((c._color[0] | (c._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x1027B8A0
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,float,int,int,class Color,class IMaterial __near *,bool),class Vector,float,int,int,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,float,int,int,Color,IMaterial *,bool),Vector,float,int,int,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,float,int,int,Color,IMaterial *,bool),Vector,float,int,int,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, _DWORD, int, int, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: LODWORD(this->m_arg2),
    a3: this->m_arg3,
    a4: this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x1027B900
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x1027B950
// Name: public: virtual void CFunctor5<void (*)(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *),class Vector,class Vector,class Vector,class Color,class IMaterial __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor5<void (__cdecl *)(Vector const &,Vector const &,Vector const &,Color,IMaterial *),Vector,Vector,Vector,Color,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor5<void (__cdecl*)(Vector const &,Vector const &,Vector const &,Color,IMaterial *),Vector,Vector,Vector,Color,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, Vector *, Vector *, _DWORD, IMaterial *))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: *(_DWORD *)&this->m_arg4,
    a5: this->m_arg5);
}

//------------------------------------------------------------------------------
// Address: 0x1027B970
// Name: void RenderWireframeSweptBox(class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeSweptBox(
        int a1@<esi>,
        const Vector *vStart,
        const Vector *vEnd,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        __int16 bZBuffer)
{
  IMatRenderContext *v8; // edi
  int v9; // esi
  IMaterial *v10; // eax
  IMesh *v11; // edi
  int v12; // ebx
  char v13; // al
  Vector *v14; // edi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  int v18; // ecx
  float v19; // xmm0_4
  int v20; // edi
  int v21; // esi
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // edi
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  matrix3x4_t fRotateMatrix; // [esp+8h] [ebp-2C4h] BYREF
  Vector pts[8]; // [esp+38h] [ebp-294h] BYREF
  float dot[8]; // [esp+98h] [ebp-234h]
  CMeshBuilder meshBuilder; // [esp+B8h] [ebp-214h] BYREF
  Vector temp; // [esp+2A0h] [ebp-2Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+2ACh] [ebp-20h]
  IMesh *pMesh; // [esp+2B0h] [ebp-1Ch]
  Vector vDelta; // [esp+2B4h] [ebp-18h]
  int v36; // [esp+2C0h] [ebp-Ch]
  int idx2; // [esp+2C4h] [ebp-8h]
  int i; // [esp+2C8h] [ebp-4h]

  InitializeStandardMaterials(a1);
  v8 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v9 = 0;
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  v10 = s_pWireframe;
  if ( (_BYTE)bZBuffer == 0 )
    v10 = s_pWireframeIgnoreZ;
  v8->Bind(this: v8, a2: v10, a3: nullptr);
  AngleMatrix(angles, matrix: &fRotateMatrix);
  v11 = v8->GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMesh = v11;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 60, a3: 60, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 60;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 60, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  vDelta.x = vEnd->x - vStart->x;
  vDelta.y = vEnd->y - vStart->y;
  vDelta.z = vEnd->z - vStart->z;
  v12 = 0;
  v13 = 0;
  i = 0;
  idx2 = 0;
  v14 = pts;
  while ( 1 )
  {
    if ( (v13 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    temp.x = x;
    if ( (v13 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    temp.y = y;
    if ( (v13 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    temp.z = z;
    VectorRotate(in1: &temp.x, in2: &fRotateMatrix, out: &v14->x);
    v18 = idx2;
    v19 = (float)((float)(v14->y * vDelta.y) + (float)(v14->x * vDelta.x)) + (float)(v14->z * vDelta.z);
    dot[v9] = v19;
    if ( *(float *)((char *)dot + v18) > v19 )
    {
      v12 = i;
      idx2 = v9 * 4;
    }
    ++i;
    ++v9;
    ++v14;
    if ( v9 >= 8 )
      break;
    v13 = i;
  }
  DrawAxes(origin: vStart, &meshBuilder, pts, idx: v12, c);
  DrawAxes(origin: vEnd, &meshBuilder, pts, idx: v12 ^ 7, c);
  v20 = 2;
  i = 2;
  v36 = 3;
  while ( 1 )
  {
    v21 = 1 << ((v20 - 1) % 3);
    v22 = 1 << (v20 % 3);
    v23 = (v21 & v12) != 0 ? v12 - v21 : v21 + v12;
    v24 = (v12 & v22) != 0 ? v12 - v22 : v22 + v12;
    idx2 = v24;
    v25 = (v12 & v22) != 0 ? v23 - v22 : v23 + v22;
    DrawExtrusionFace(idx1: v23, &meshBuilder, start: vStart, end: vEnd, pts, idx2: v25, c);
    DrawExtrusionFace(idx1: idx2, &meshBuilder, start: vStart, end: vEnd, pts, idx2: v25, c);
    ++i;
    if ( --v36 == 0 )
      break;
    v20 = i;
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1027BDC0
// Name: void DrawScreenSpaceRectangle(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawScreenSpaceRectangle(
        int a1@<edi>,
        int a2@<esi>,
        IMaterial *pMaterial,
        int nDestX,
        int nDestY,
        int nWidth,
        int nHeight,
        float flSrcTextureX0,
        float flSrcTextureY0,
        float flSrcTextureX1,
        float flSrcTextureY1,
        int nSrcTextureWidth,
        int nSrcTextureHeight,
        void *pClientRenderable,
        int nXDice,
        int nYDice,
        float fDepth)
{
  IMatRenderContext *v17; // ebx
  int v18; // edi
  IMesh_vtbl *v19; // eax
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v21; // esi
  int v22; // esi
  float v23; // xmm4_4
  float v24; // xmm3_4
  void (__thiscall *GetViewport)(IMatRenderContext *, int *, int *, int *, int *); // edx
  float v26; // xmm3_4
  float v27; // xmm4_4
  int v28; // ecx
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  int v32; // xmm1_4
  int v33; // edi
  bool v34; // dl
  float *v35; // eax
  float *v36; // eax
  int v37; // xmm3_4
  int v38; // xmm1_4
  float *v39; // eax
  _DWORD *v40; // eax
  _DWORD *v41; // eax
  int v42; // xmm3_4
  float v43; // xmm7_4
  float v44; // xmm5_4
  int v45; // eax
  float v46; // xmm1_4
  float *m_pCurrPosition; // eax
  float v48; // xmm1_4
  float v49; // xmm4_4
  float v50; // xmm3_4
  float v51; // xmm0_4
  float *m_pCurrNormal; // eax
  float *v53; // eax
  _DWORD *v54; // eax
  _DWORD *v55; // eax
  float *v56; // eax
  float v57; // xmm2_4
  float *v58; // eax
  float *v59; // eax
  _DWORD *v60; // eax
  _DWORD *v61; // eax
  float *v62; // eax
  float v63; // xmm3_4
  float v64; // xmm1_4
  float *v65; // eax
  float *v66; // eax
  _DWORD *v67; // eax
  _DWORD *v68; // eax
  float *v69; // eax
  float v70; // xmm2_4
  float *v71; // eax
  float *v72; // eax
  _DWORD *v73; // eax
  _DWORD *v74; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-248h] BYREF
  int nScreenWidth; // [esp+1ECh] [ebp-60h] BYREF
  int vx; // [esp+1F0h] [ebp-5Ch] BYREF
  int vy; // [esp+1F4h] [ebp-58h] BYREF
  int nScreenHeight; // [esp+1F8h] [ebp-54h] BYREF
  float v82; // [esp+1FCh] [ebp-50h]
  float v83; // [esp+200h] [ebp-4Ch]
  int vh; // [esp+204h] [ebp-48h] BYREF
  float v85; // [esp+208h] [ebp-44h]
  float v86; // [esp+20Ch] [ebp-40h]
  float flUWidth; // [esp+210h] [ebp-3Ch]
  float flWidth; // [esp+214h] [ebp-38h]
  int vw; // [esp+218h] [ebp-34h] BYREF
  IMesh *pMesh; // [esp+21Ch] [ebp-30h]
  float v91; // [esp+220h] [ebp-2Ch]
  int x; // [esp+224h] [ebp-28h]
  float v93; // [esp+228h] [ebp-24h]
  int xSegments; // [esp+22Ch] [ebp-20h]
  float flLeftU; // [esp+230h] [ebp-1Ch]
  float flLeftX; // [esp+234h] [ebp-18h]
  float flRightU; // [esp+238h] [ebp-14h]
  float flVHeight; // [esp+23Ch] [ebp-10h]
  float flTexelsPerPixelX; // [esp+240h] [ebp-Ch]
  float flTexelsPerPixelY; // [esp+244h] [ebp-8h]
  int flHeight; // [esp+248h] [ebp-4h]
  float flTopY; // [esp+260h] [ebp+14h]

  v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v17 != nullptr )
    v17->BeginRender(this: v17);
  if ( nWidth <= 0 || nHeight <= 0 )
  {
    if ( v17 == nullptr )
      return;
  }
  else
  {
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    v17->Bind(this: v17, a2: pMaterial, a3: pClientRenderable);
    xSegments = nXDice;
    if ( nXDice <= 1 )
      xSegments = 1;
    v18 = nYDice;
    if ( nYDice <= 1 )
      v18 = 1;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int, int))v17->GetDynamicMesh)(
                                     a1: v17,
                                     a2: 1,
                                     a3: 0,
                                     a4: 0,
                                     a5: 0,
                                     a6: a1,
                                     a7: a2);
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v19 = meshBuilder.m_pMesh->__vftable;
    flHeight = 4 * xSegments * v18;
    SetPrimitiveType = v19->SetPrimitiveType;
    pMesh = meshBuilder.m_pMesh;
    v21 = 6 * xSegments * v18;
    ((void (__stdcall *)(int))SetPrimitiveType)(a1: 2);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: flHeight, a3: v21, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v21;
    CVertexBuilder::AttachBegin(
      this: &meshBuilder.m_VertexBuilder,
      pMesh,
      nMaxVertexCount: flHeight,
      desc: &meshBuilder);
    v22 = 0;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v17->GetRenderTargetDimensions(this: v17, a2: &nScreenWidth, a3: &nScreenHeight);
    flLeftX = (float)nDestX - 0.5;
    flVHeight = (float)(nWidth + nDestX) - 0.5;
    *(float *)&flHeight = (float)(nHeight + nDestY) - 0.5;
    if ( nWidth <= 1 )
      v23 = 0.0;
    else
      v23 = (float)(flSrcTextureX1 - flSrcTextureX0) / (float)(nWidth - 1);
    flTexelsPerPixelX = v23;
    if ( nHeight <= 1 )
      v24 = 0.0;
    else
      v24 = (float)(flSrcTextureY1 - flSrcTextureY0) / (float)(nHeight - 1);
    GetViewport = v17->GetViewport;
    flTexelsPerPixelY = v24;
    v26 = 1.0 / (float)nSrcTextureWidth;
    v27 = 1.0 / (float)nSrcTextureHeight;
    flLeftU = (float)((float)(flSrcTextureX0 + 0.5) - (float)(flTexelsPerPixelX * 0.5)) * v26;
    flRightU = (float)((float)(flSrcTextureX1 + 0.5) + (float)(flTexelsPerPixelX * 0.5)) * v26;
    flTexelsPerPixelX = (float)((float)(flSrcTextureY0 + 0.5) - (float)(flTexelsPerPixelY * 0.5)) * v27;
    flTexelsPerPixelY = (float)((float)(flSrcTextureY1 + 0.5) + (float)(flTexelsPerPixelY * 0.5)) * v27;
    GetViewport(this: v17, a2: &vx, a3: &vy, a4: &vw, a5: &vh);
    v28 = xSegments;
    v29 = (float)((float)(flVHeight * 2.0) / (float)vw) - 1.0;
    v30 = (float)((float)(flLeftX * 2.0) / (float)vw) - 1.0;
    v31 = 1.0 - (float)((float)((float)((float)nDestY - 0.5) * 2.0) / (float)vh);
    *(float *)&v32 = 1.0 - (float)((float)(*(float *)&flHeight * 2.0) / (float)vh);
    flVHeight = v29;
    flLeftX = v30;
    flTopY = v31;
    flHeight = v32;
    if ( xSegments > 1 || v18 > 1 )
    {
      *(float *)&v42 = (float)(v31 - *(float *)&v32) / (float)v18;
      v43 = (float)(flRightU - flLeftU) / (float)xSegments;
      v44 = (float)(v29 - v30) / (float)xSegments;
      v45 = 0;
      flWidth = v44;
      flHeight = v42;
      flUWidth = v43;
      flVHeight = (float)(flTexelsPerPixelY - flTexelsPerPixelX) / (float)v18;
      x = 0;
      if ( xSegments > 0 )
      {
        do
        {
          if ( v18 > 0 )
          {
            flRightU = (float)((float)(v45 + 1) * v44) + v30;
            flTexelsPerPixelY = (float)((float)(v45 + 1) * v43) + flLeftU;
            v46 = (float)((float)v45 * v44) + v30;
            v93 = v46;
            v91 = (float)((float)v45 * v43) + flLeftU;
            while ( 1 )
            {
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = v46;
              v48 = (float)((float)v22 * flVHeight) + flTexelsPerPixelX;
              v49 = (float)v22 * *(float *)&v42;
              v50 = v91;
              v51 = v31 - v49;
              m_pCurrPosition[1] = v51;
              v86 = v51;
              m_pCurrPosition[2] = fDepth;
              m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              m_pCurrNormal[1] = 0.0;
              m_pCurrNormal[2] = 1.0;
              v53 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v50;
              v53[1] = v48;
              v54 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v54 = 0;
              v54[1] = 1065353216;
              v54[2] = 0;
              v55 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              v82 = v48;
              *v55 = 1065353216;
              v55[1] = 0;
              v55[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v56 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = flRightU;
              v57 = flTexelsPerPixelY;
              v56[1] = v86;
              v56[2] = fDepth;
              v58 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v58[1] = 0.0;
              v58[2] = 1.0;
              v59 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v57;
              v59[1] = v82;
              v60 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v60 = 0;
              v60[1] = 1065353216;
              v60[2] = 0;
              v61 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              *v61 = 1065353216;
              v61[1] = 0;
              v61[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v62 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              ++v22;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = flRightU;
              v83 = flTopY - (float)((float)v22 * *(float *)&flHeight);
              v62[1] = v83;
              v63 = flTexelsPerPixelY;
              v64 = (float)((float)v22 * flVHeight) + flTexelsPerPixelX;
              v62[2] = fDepth;
              v65 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v65[1] = 0.0;
              v65[2] = 1.0;
              v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v63;
              v66[1] = v64;
              v67 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v67 = 0;
              v67[1] = 1065353216;
              v67[2] = 0;
              v68 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              v85 = v64;
              *v68 = 1065353216;
              v68[1] = 0;
              v68[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v69 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = v93;
              v70 = v91;
              v69[1] = v83;
              v69[2] = fDepth;
              v71 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
              *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
              v71[1] = 0.0;
              v71[2] = 1.0;
              v72 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v70;
              v72[1] = v85;
              v73 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
              *v73 = 0;
              v73[1] = 1065353216;
              v73[2] = 0;
              v74 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
              *v74 = 1065353216;
              v74[1] = 0;
              v74[2] = 0;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v31 = flTopY;
              v42 = flHeight;
              if ( v22 >= v18 )
                break;
              v46 = v93;
            }
            v30 = flLeftX;
            v44 = flWidth;
            v43 = flUWidth;
            v45 = x;
            v28 = xSegments;
          }
          ++v45;
          v22 = 0;
          x = v45;
        }
        while ( v45 < v28 );
      }
    }
    else
    {
      v33 = 0;
      while ( 1 )
      {
        v34 = v33 == 0 || v33 == 3;
        if ( (v33 & 2) != 0 )
          v31 = *(float *)&v32;
        if ( v34 )
          v29 = v30;
        v35 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
        v35[1] = v31;
        v35[2] = fDepth;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
        v36[1] = 0.0;
        v36[2] = 1.0;
        v37 = (v33 & 2) != 0 ? LODWORD(flTexelsPerPixelY) : LODWORD(flTexelsPerPixelX);
        v38 = v34 ? LODWORD(flLeftU) : LODWORD(flRightU);
        v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v38;
        *((_DWORD *)v39 + 1) = v37;
        v40 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                       + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
        *v40 = 0;
        v40[1] = 1065353216;
        v40[2] = 0;
        v41 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                       + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
        *v41 = 1065353216;
        v41[1] = 0;
        v41[2] = 0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v33 >= 4 )
          break;
        v30 = flLeftX;
        v29 = flVHeight;
        v31 = flTopY;
        v32 = flHeight;
      }
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
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PopMatrix(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PopMatrix(this: v17);
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
  }
  v17->EndRender(this: v17);
  v17->Release(this: v17);
}

//------------------------------------------------------------------------------
// Address: 0x1027C790
// Name: void RenderWireframeSphere(class Vector const __near &,float,int,int,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeSphere(
        int a1@<esi>,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi,
        Color c,
        bool bZBuffer)
{
  IMatRenderContext *v7; // esi
  ICallQueue *v8; // edi
  float z; // ebx
  char *v10; // eax
  __int64 v11; // xmm0_8
  int v12; // edi
  int v13; // esi
  int v14; // ebx
  IMaterial *v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // ebx
  __m128 v19; // xmm0
  __m128d v20; // xmm0
  __m128i v21; // xmm0
  double v22; // xmm0_8
  double v23; // xmm0_8
  int v24; // esi
  __m128 v25; // xmm0
  __m128d v26; // xmm0
  __m128i v27; // xmm0
  float *m_pCurrPosition; // edi
  double v29; // xmm0_8
  double v30; // xmm0_8
  signed int m_nCurrentIndex; // ecx
  __int16 v32; // dx
  signed int v33; // ecx
  signed int v34; // ecx
  signed int v35; // ecx
  bool v36; // zf
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-224h] BYREF
  __int64 v40; // [esp+1F4h] [ebp-3Ch]
  unsigned int theta; // [esp+200h] [ebp-30h]
  float v42; // [esp+204h] [ebp-2Ch]
  IMesh *pMesh; // [esp+208h] [ebp-28h]
  float v44; // [esp+20Ch] [ebp-24h]
  float v45; // [esp+210h] [ebp-20h]
  float v46; // [esp+214h] [ebp-1Ch]
  unsigned int phi; // [esp+218h] [ebp-18h]
  CMatRenderContextPtr pRenderContext; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v50; // [esp+224h] [ebp-Ch]
  float v51; // [esp+228h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+22Ch] [ebp-4h]
  unsigned __int8 chRed; // [esp+22Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+22Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+22Fh] [ebp-1h]
  int nThetaa; // [esp+240h] [ebp+10h]

  InitializeStandardMaterials(a1);
  v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v8 = v7->GetCallQueue(this: v7);
  if ( v8 != nullptr )
  {
    z = vCenter->z;
    v40 = *(_QWORD *)&vCenter->x;
    v10 = (char *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v10 != nullptr )
    {
      v11 = v40;
      *((_DWORD *)v10 + 3) = 1;
      *(_QWORD *)(v10 + 20) = v11;
      *((_DWORD *)v10 + 10) = nPhi;
      *(_DWORD *)v10 = &CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v10 + 2) = &CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v10 + 4) = RenderWireframeSphere;
      *((float *)v10 + 7) = z;
      *((float *)v10 + 8) = flRadius;
      *((_DWORD *)v10 + 9) = nTheta;
      *((Color *)v10 + 11) = c;
      v10[48] = bZBuffer;
    }
    else
    {
      v10 = nullptr;
    }
    v8->QueueFunctorInternal(this: v8, a2: (CFunctor *)v10);
    v7->EndRender(this: v7);
    v7->Release(this: v7);
  }
  else
  {
    v12 = nPhi;
    v13 = nPhi * (nTheta + 1);
    v14 = (nPhi - 1) * (4 * (nTheta + 1) - 4);
    nThetaa = nTheta + 1;
    v15 = s_pWireframe;
    v50 = nPhi - 1;
    if ( !bZBuffer )
      v15 = s_pWireframeIgnoreZ;
    pRenderContext.m_pObject->Bind(this: pRenderContext.m_pObject, a2: v15, a3: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    pMesh = pRenderContext.m_pObject->GetDynamicMesh(this: pRenderContext.m_pObject, a2: 1, a3: 0, a4: 0, a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_LINES,
      nVertexCount: v13,
      nIndexCount: v14,
      pMeshSettings: nullptr);
    chBlue = c._color[2];
    v16 = 0;
    chGreen = c._color[1];
    chRed = c._color[0];
    chAlpha = c._color[3];
    i = 0;
    if ( nPhi <= 0 )
    {
      v17 = nThetaa;
    }
    else
    {
      do
      {
        v17 = nThetaa;
        v18 = 0;
        if ( nThetaa > 0 )
        {
          v42 = (float)(nThetaa - 1);
          v19 = 0;
          v19.m128_f32[0] = (float)v16 / (float)v50;
          v20 = _mm_cvtps_pd(v19);
          v20.m128d_f64[0] = v20.m128d_f64[0] * 3.141592653589793;
          v21 = (__m128i)_mm_cvtpd_ps(v20);
          phi = v21.m128i_i32[0];
          *(double *)v21.m128i_i64 = *(float *)v21.m128i_i32;
          __libm_sse2_cos(a1: v21);
          *(float *)&v22 = v22;
          v44 = *(float *)&v22 * flRadius;
          __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)phi));
          *(float *)&v23 = v23;
          v51 = *(float *)&v23 * flRadius;
          v24 = chBlue | ((chGreen | ((chRed | (chAlpha << 8)) << 8)) << 8);
          do
          {
            v25 = 0;
            v25.m128_f32[0] = (float)v18 / v42;
            v26 = _mm_cvtps_pd(v25);
            v26.m128d_f64[0] = v26.m128d_f64[0] * 6.283185307179586;
            v27 = (__m128i)_mm_cvtpd_ps(v26);
            theta = v27.m128i_i32[0];
            *(double *)v27.m128i_i64 = *(float *)v27.m128i_i32;
            __libm_sse2_sin(X: v27);
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *(float *)&v29 = v29;
            v46 = (float)(*(float *)&v29 * v51) + vCenter->y;
            v45 = v44 + vCenter->z;
            __libm_sse2_cos(a1: (__m128i)_mm_cvtps_pd((__m128)theta));
            *(float *)&v30 = v30;
            *m_pCurrPosition = (float)(*(float *)&v30 * v51) + vCenter->x;
            m_pCurrPosition[1] = v46;
            m_pCurrPosition[2] = v45;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v18;
          }
          while ( v18 < nThetaa );
          v16 = i;
          v12 = nPhi;
          v17 = nThetaa;
        }
        i = ++v16;
      }
      while ( v16 < v12 );
    }
    if ( v50 > 0 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      v32 = 0;
      i = 0;
      v51 = *(float *)&v50;
      do
      {
        if ( v17 - 1 > 0 )
        {
          v50 = v17 - 1;
          do
          {
            meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v32
                                                                   + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v33 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v33;
            if ( v33 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v33;
            meshBuilder.m_IndexBuilder.m_pIndices[v33] = v17 + v32 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v34 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v34;
            if ( v34 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v34;
            meshBuilder.m_IndexBuilder.m_pIndices[v34] = v32 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v35 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v35;
            if ( v35 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v35;
            meshBuilder.m_IndexBuilder.m_pIndices[v35] = v32 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + 1;
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
            if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            ++v32;
            --v50;
          }
          while ( *(float *)&v50 != 0.0 );
        }
        v32 = v17 + i;
        v36 = LODWORD(v51)-- == 1;
        i += v17;
      }
      while ( !v36 );
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027CCA0
// Name: void RenderSphereInternal(class Vector const __near &,float,int,int,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderSphereInternal(
        int a1@<esi>,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  ICallQueue *v9; // edi
  float z; // eax
  char *v11; // eax
  __int64 v12; // xmm0_8
  float v13; // ecx
  int v14; // edi
  int v15; // esi
  bool v16; // zf
  int v17; // esi
  int v18; // edx
  float v19; // xmm1_4
  int v20; // eax
  int v21; // esi
  __m128 v22; // xmm0
  __m128d v23; // xmm0
  __m128i v24; // xmm0
  double v25; // xmm0_8
  double v26; // xmm0_8
  int v27; // edi
  __m128 v28; // xmm0
  __m128d v29; // xmm0
  __m128i v30; // xmm0
  double v31; // xmm0_8
  double v32; // xmm0_8
  float *m_pCurrPosition; // eax
  float v34; // xmm1_4
  float v35; // xmm2_4
  float *v36; // eax
  signed int m_nCurrentIndex; // eax
  int v38; // esi
  signed int v39; // eax
  int v40; // ecx
  signed int v41; // eax
  signed int v42; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-254h] BYREF
  Vector4D vecTangent; // [esp+1F0h] [ebp-6Ch] BYREF
  float v46; // [esp+200h] [ebp-5Ch]
  float v47; // [esp+204h] [ebp-58h]
  unsigned int theta; // [esp+208h] [ebp-54h]
  float flOONTheta; // [esp+20Ch] [ebp-50h]
  float v50; // [esp+210h] [ebp-4Ch]
  float v51; // [esp+214h] [ebp-48h]
  float v52; // [esp+218h] [ebp-44h]
  IMesh *pMesh; // [esp+21Ch] [ebp-40h]
  Vector vecPos; // [esp+220h] [ebp-3Ch]
  Vector vecNormal; // [esp+22Ch] [ebp-30h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+238h] [ebp-24h]
  int phi; // [esp+23Ch] [ebp-20h]
  int idx; // [esp+240h] [ebp-1Ch]
  int j; // [esp+244h] [ebp-18h]
  unsigned __int8 chRed; // [esp+24Bh] [ebp-11h]
  float v61; // [esp+24Ch] [ebp-10h]
  unsigned __int8 chGreen; // [esp+253h] [ebp-9h]
  int i; // [esp+254h] [ebp-8h]
  unsigned __int8 chAlpha; // [esp+25Ah] [ebp-2h]
  unsigned __int8 chBlue; // [esp+25Bh] [ebp-1h]

  InitializeStandardMaterials(a1);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v9 = m_pObject->GetCallQueue(this: m_pObject);
  if ( v9 != nullptr )
  {
    z = vCenter->z;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vCenter->x;
    vecNormal.z = z;
    v11 = (char *)MemAlloc_Alloc(nSize: 0x38u);
    if ( v11 != nullptr )
    {
      v12 = *(_QWORD *)&vecNormal.x;
      v13 = vecNormal.z;
      *((_DWORD *)v11 + 3) = 1;
      *(_QWORD *)(v11 + 20) = v12;
      *((float *)v11 + 7) = v13;
      *((_DWORD *)v11 + 10) = nPhi;
      *((_DWORD *)v11 + 9) = nTheta;
      *(_DWORD *)v11 = &CFunctor7<void (__cdecl *)(Vector const &,float,int,int,Color,IMaterial *,bool),Vector,float,int,int,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v11 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,float,int,int,Color,IMaterial *,bool),Vector,float,int,int,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v11 + 4) = RenderSphereInternal;
      *((float *)v11 + 8) = flRadius;
      *((Color *)v11 + 11) = c;
      *((_DWORD *)v11 + 12) = pMaterial;
      v11[52] = bInsideOut;
      v9->QueueFunctorInternal(this: v9, a2: (CFunctor *)v11);
    }
    else
    {
      v9->QueueFunctorInternal(this: v9, a2: nullptr);
    }
  }
  else
  {
    v14 = nTheta;
    chGreen = c._color[1];
    chRed = c._color[0];
    chBlue = c._color[2];
    v15 = nTheta * (nPhi - 1);
    v16 = 2 * v15 == 0;
    v17 = 2 * v15;
    chAlpha = c._color[3];
    phi = (nTheta + 1) * (2 * nPhi - 2);
    if ( !v16 )
    {
      pRenderContext.m_pObject->Bind(this: pRenderContext.m_pObject, a2: pMaterial, a3: nullptr);
      pMesh = pRenderContext.m_pObject->GetDynamicMesh(this: pRenderContext.m_pObject, a2: 1, a3: 0, a4: 0, a5: 0);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh,
        type: MATERIAL_TRIANGLE_STRIP,
        nVertexCount: v17,
        nIndexCount: phi,
        pMeshSettings: nullptr);
      v18 = nPhi;
      v19 = (float)(nPhi - 1);
      *(float *)&idx = 1.0 / v19;
      v20 = 0;
      v52 = v19;
      v50 = (float)(nTheta - 1);
      flOONTheta = 1.0 / v50;
      for ( i = 0; v20 < v18; i = v20 )
      {
        v21 = 0;
        if ( v14 > 0 )
        {
          v22 = 0;
          *(float *)&j = (float)v20;
          v22.m128_f32[0] = (float)v20 / v19;
          v23 = _mm_cvtps_pd(v22);
          v23.m128d_f64[0] = v23.m128d_f64[0] * 3.141592653589793;
          v24 = (__m128i)_mm_cvtpd_ps(v23);
          phi = v24.m128i_i32[0];
          *(double *)v24.m128i_i64 = *(float *)v24.m128i_i32;
          __libm_sse2_sin(X: v24);
          *(float *)&v25 = v25;
          v61 = *(float *)&v25 * flRadius;
          __libm_sse2_cos(a1: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)phi));
          *(float *)&v26 = v26;
          v51 = *(float *)&v26 * flRadius;
          v27 = chBlue | ((chGreen | ((chRed | (chAlpha << 8)) << 8)) << 8);
          v46 = *(float *)&j * *(float *)&idx;
          do
          {
            v28 = 0;
            v47 = (float)v21;
            v28.m128_f32[0] = (float)v21 / v50;
            v29 = _mm_cvtps_pd(v28);
            v29.m128d_f64[0] = v29.m128d_f64[0] * 6.283185307179586;
            v30 = (__m128i)_mm_cvtpd_ps(v29);
            theta = v30.m128i_i32[0];
            *(double *)v30.m128i_i64 = *(float *)v30.m128i_i32;
            __libm_sse2_cos(a1: v30);
            *(float *)&v31 = v31;
            vecPos.x = *(float *)&v31 * v61;
            __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)theta));
            *(float *)&v32 = v32;
            vecPos.y = *(float *)&v32 * v61;
            vecPos.z = v51;
            vecNormal = vecPos;
            VectorNormalize(vec: &vecNormal);
            LODWORD(vecTangent.x) = LODWORD(vecPos.y) ^ _mask__NegFloat_;
            vecTangent.y = vecPos.x;
            *(_QWORD *)&vecTangent.z = 0x3F80000000000000LL;
            VectorNormalize(vec: (Vector *)&vecTangent);
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            v34 = vCenter->y + vecPos.y;
            v35 = vCenter->z + vecPos.z;
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + vecPos.x;
            m_pCurrPosition[1] = v34;
            m_pCurrPosition[2] = v35;
            *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v27;
            *(Vector4D *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_UserData) = vecTangent;
            v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v47 * flOONTheta;
            v36[1] = v46;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v21;
          }
          while ( v21 < nTheta );
          v19 = v52;
          v14 = nTheta;
          v20 = i;
          v18 = nPhi;
        }
        ++v20;
      }
      *(float *)&idx = 0.0;
      i = 0;
      if ( v18 - 1 > 0 )
      {
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        v61 = 0.0;
        do
        {
          if ( bInsideOut )
          {
            j = v14 - 1;
            if ( v14 - 1 >= 0 )
            {
              v38 = v14 - 1 + LODWORD(v61);
              do
              {
                meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v14
                                                                       + v38
                                                                       + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
                v39 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                idx = v38;
                meshBuilder.m_IndexBuilder.m_nCurrentIndex = v39;
                if ( v39 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                  meshBuilder.m_IndexBuilder.m_nIndexCount = v39;
                meshBuilder.m_IndexBuilder.m_pIndices[v39] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v38;
                m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
                if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
                  meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
                v14 = nTheta;
                --v38;
                --j;
              }
              while ( j >= 0 );
              v18 = nPhi;
            }
          }
          else
          {
            if ( v14 > 0 )
            {
              *(float *)&v40 = v61;
              *(float *)&j = v61;
              phi = v14;
              do
              {
                idx = v40;
                meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v14
                                                                       + v40
                                                                       + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
                v41 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                meshBuilder.m_IndexBuilder.m_nCurrentIndex = v41;
                if ( v41 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                  meshBuilder.m_IndexBuilder.m_nIndexCount = v41;
                meshBuilder.m_IndexBuilder.m_pIndices[v41] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v40;
                m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
                if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
                  meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
                v40 = j + 1;
                v16 = phi-- == 1;
                ++j;
              }
              while ( !v16 );
              v18 = nPhi;
            }
            if ( i < v18 - 2 )
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = idx
                                                                     + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
              v42 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = v42;
              if ( v42 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                meshBuilder.m_IndexBuilder.m_nIndexCount = v42;
              meshBuilder.m_IndexBuilder.m_pIndices[v42] = v14
                                                         + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                         + idx
                                                         + 1;
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
                meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
          }
          ++i;
          LODWORD(v61) += v14;
        }
        while ( i < v18 - 1 );
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
      meshBuilder.m_pMesh->UnlockMesh(
        this: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
        a4: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_pMesh = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    }
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1027D390
// Name: void RenderSphere(class Vector const __near &,float,int,int,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderSphere(
        int a1@<esi>,
        const Vector *vCenter,
        __int64 flRadius,
        int nPhi,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  RenderSphereInternal(
    a1,
    vCenter,
    flRadius: *(float *)&flRadius,
    nTheta: SHIDWORD(flRadius),
    nPhi,
    c,
    pMaterial,
    bInsideOut);
}

//------------------------------------------------------------------------------
// Address: 0x1027D3C0
// Name: void RenderWireframeBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        bool bZBuffer)
{
  IMatRenderContext *v7; // esi
  float z; // edi
  float v9; // ebx
  __int64 v10; // xmm0_8
  float v11; // ecx
  char *v12; // eax
  __int64 v13; // xmm0_8
  float v14; // edx
  float v15; // ecx
  IMaterial *v16; // eax
  IMatRenderContext v17; // edx
  IMesh *v18; // esi
  int v19; // esi
  int *v20; // ebx
  int i; // edi
  float *m_pCurrPosition; // ecx
  Vector *v23; // eax
  int v24; // eax
  float *v25; // ecx
  int v26; // eax
  double x; // st7
  Vector *v28; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  Vector p[8]; // [esp+Ch] [ebp-284h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-224h] BYREF
  __int64 v33; // [esp+254h] [ebp-3Ch]
  __int64 v34; // [esp+260h] [ebp-30h]
  __int64 v35; // [esp+26Ch] [ebp-24h]
  float v36; // [esp+274h] [ebp-1Ch]
  __int64 v37; // [esp+278h] [ebp-18h]
  float v38; // [esp+280h] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+284h] [ebp-Ch]
  IMesh *pMesh; // [esp+288h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+28Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+28Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+28Fh] [ebp-1h]

  InitializeStandardMaterials(a1);
  v7 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  pMesh = (IMesh *)v7->GetCallQueue(this: v7);
  if ( pMesh != nullptr )
  {
    z = vMaxs->z;
    v9 = vMins->z;
    v34 = *(_QWORD *)&vMaxs->x;
    v33 = *(_QWORD *)&vMins->x;
    v10 = *(_QWORD *)&angles->x;
    v36 = angles->z;
    v11 = vOrigin->z;
    v35 = v10;
    v37 = *(_QWORD *)&vOrigin->x;
    v38 = v11;
    v12 = (char *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v12 != nullptr )
    {
      v13 = v37;
      v14 = v38;
      v15 = v36;
      *((_DWORD *)v12 + 3) = 1;
      *(_QWORD *)(v12 + 20) = v13;
      *((_QWORD *)v12 + 4) = v35;
      *(_QWORD *)(v12 + 44) = v33;
      *((_QWORD *)v12 + 7) = v34;
      *((float *)v12 + 10) = v15;
      *(_DWORD *)v12 = &CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v12 + 2) = &CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v12 + 4) = RenderWireframeBox;
      *((float *)v12 + 7) = v14;
      *((float *)v12 + 13) = v9;
      *((float *)v12 + 16) = z;
      *((Color *)v12 + 17) = c;
      v12[72] = bZBuffer;
    }
    else
    {
      v12 = nullptr;
    }
    ((void (__thiscall *)(IMesh *, char *))pMesh->VertexCount)(a1: pMesh, a2: v12);
    v7->EndRender(this: v7);
    v7->Release(this: v7);
  }
  else
  {
    v16 = s_pWireframe;
    if ( !bZBuffer )
      v16 = s_pWireframeIgnoreZ;
    v7->Bind(this: v7, a2: v16, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chBlue = c._color[2];
    v17.__vftable = v7->__vftable;
    chGreen = c._color[1];
    chAlpha = c._color[3];
    v18 = v17.GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v18;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v18;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v18->SetPrimitiveType(this: v18, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 48, a3: 48, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v18->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 48;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v18, nMaxVertexCount: 48, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v19 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v20 = s_pBoxFaceIndices[0];
    do
    {
      for ( i = 0; i < 4; ++i )
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v23 = &p[v20[i]];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v23->x;
        m_pCurrPosition[1] = v23->y;
        m_pCurrPosition[2] = v23->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v19;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( i == 3 )
          v24 = 0;
        else
          v24 = i + 1;
        v25 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v26 = v20[v24];
        x = p[v26].x;
        v28 = &p[v26];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
        v25[1] = v28->y;
        v25[2] = v28->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v19;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      }
      v20 += 4;
    }
    while ( (int)v20 < (int)s_pBoxFaceIndicesInsideOut[0] );
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D7E0
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v10; // edi
  __int64 v11; // xmm0_8
  float v12; // ecx
  char *v13; // eax
  __int64 v14; // xmm0_8
  float v15; // edx
  float v16; // ecx
  __int64 v17; // xmm0_8
  ICallQueue *v18; // ecx
  IMatRenderContext v19; // eax
  IMesh *v20; // esi
  unsigned int v21; // ecx
  int v22; // edi
  ICallQueue *v23; // eax
  int v24; // xmm1_4
  int *v25; // eax
  int v26; // esi
  int v27; // edx
  int v28; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v31; // eax
  double v32; // st7
  Vector *v33; // eax
  float *m_pCurrNormal; // eax
  float *v35; // eax
  float *v36; // ecx
  float v37; // xmm0_4
  Vector *v38; // eax
  float *v39; // eax
  int v40; // xmm0_4
  float *v41; // eax
  float *v42; // ecx
  float v43; // xmm0_4
  Vector *v44; // eax
  float *v45; // eax
  int v46; // xmm0_4
  float *v47; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v51; // [esp+254h] [ebp-4Ch]
  __int64 v52; // [esp+260h] [ebp-40h]
  __int64 v53; // [esp+26Ch] [ebp-34h]
  float v54; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v10 = vMins->z;
    v51 = *(_QWORD *)&vMaxs->x;
    v52 = *(_QWORD *)&vMins->x;
    v11 = *(_QWORD *)&angles->x;
    v54 = angles->z;
    v12 = vOrigin->z;
    v53 = v11;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v12;
    v13 = (char *)MemAlloc_Alloc(nSize: 0x50u);
    if ( v13 != nullptr )
    {
      v14 = *(_QWORD *)&vecNormal.x;
      v15 = vecNormal.z;
      v16 = v54;
      *((_DWORD *)v13 + 3) = 1;
      *(_QWORD *)(v13 + 20) = v14;
      *((_QWORD *)v13 + 4) = v53;
      *(_QWORD *)(v13 + 44) = v52;
      v17 = v51;
      *((float *)v13 + 10) = v16;
      *((_QWORD *)v13 + 7) = v17;
      *((float *)v13 + 7) = v15;
      *(_DWORD *)v13 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v13 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v13 + 4) = RenderBoxInternal;
      *((float *)v13 + 13) = v10;
      *((float *)v13 + 16) = z;
      *((Color *)v13 + 17) = c;
      *((_DWORD *)v13 + 18) = pMaterial;
      v18 = pCallQueue;
      v13[76] = bInsideOut;
      v18->QueueFunctorInternal(this: v18, a2: (CFunctor *)v13);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v19.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v20 = v19.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v20;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v20;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v20->SetPrimitiveType(this: v20, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v20->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v20, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v21 = 0;
    i = 0;
    v22 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v23 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v24 = (v21 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v21 >> 1)) = v24;
      if ( bInsideOut )
      {
        v25 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v23);
        ppFaceIndices = v25;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v23);
        v25 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v23);
      }
      v26 = 1;
      while ( 1 )
      {
        v27 = v25[v26];
        v28 = v25[v26 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v31 = *v25;
        v32 = p[v31].x;
        v33 = &p[v31];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v32;
        i1 = v27;
        m_pCurrPosition[1] = v33->y;
        m_pCurrPosition[2] = v33->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v35[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v36 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v37 = vecNormal.x;
        v38 = &p[v28];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v38->x;
        v36[1] = v38->y;
        v36[2] = v38->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        v39 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v37;
        v39[1] = vecNormal.y;
        v39[2] = vecNormal.z;
        v40 = v26 == 1 ? 1065353216 : 0;
        v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v41 + 1) = v40;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v42 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v43 = vecNormal.x;
        v44 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v44->x;
        v42[1] = v44->y;
        v42[2] = v44->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        v45 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v43;
        v45[1] = vecNormal.y;
        v45[2] = vecNormal.z;
        v46 = v26 == 1 ? 0 : 1065353216;
        v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v46;
        v47[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v26 >= 3 )
          break;
        v25 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v23 = pCallQueue;
      v21 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1027DD80
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        __int16 bZBuffer,
        bool bInsideOut)
{
  IMaterial *v8; // ecx

  InitializeStandardMaterials(a1);
  v8 = s_pVertexColor;
  if ( (_BYTE)bZBuffer == 0 )
    v8 = s_pVertexColorIgnoreZ;
  RenderBoxInternal(a1, vOrigin, angles, vMins, vMaxs, c, pMaterial: v8, bInsideOut);
}

//------------------------------------------------------------------------------
// Address: 0x1027DDE0
// Name: void RenderLine(class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall RenderLine(int a1@<esi>, const Vector *v1, const Vector *v2, Color c, bool bZBuffer)
{
  IMatRenderContext *v5; // ebx
  float z; // edi
  float v7; // eax
  char *v8; // eax
  __int64 v9; // xmm0_8
  float v10; // ecx
  __int64 v11; // xmm0_8
  ICallQueue *v12; // ecx
  IMaterial *v13; // eax
  IMatRenderContext_vtbl *v14; // eax
  IMesh *v15; // edi
  float *m_pCurrPosition; // eax
  int v17; // esi
  int v18; // edx
  int v19; // ecx
  int v20; // esi
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-208h] BYREF
  __int64 v23; // [esp+1F4h] [ebp-20h]
  __int64 v24; // [esp+200h] [ebp-14h]
  float v25; // [esp+208h] [ebp-Ch]
  ICallQueue *pCallQueue; // [esp+20Ch] [ebp-8h]
  unsigned __int8 chAlpha; // [esp+210h] [ebp-4h]
  __int16 chRed; // [esp+211h] [ebp-3h] OVERLAPPED
  unsigned __int8 chBlue; // [esp+213h] [ebp-1h]

  InitializeStandardMaterials(a1);
  v5 = materials->GetRenderContext(this: materials);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  pCallQueue = v5->GetCallQueue(this: v5);
  if ( pCallQueue != nullptr )
  {
    z = v2->z;
    v23 = *(_QWORD *)&v2->x;
    v7 = v1->z;
    v24 = *(_QWORD *)&v1->x;
    v25 = v7;
    v8 = (char *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v8 != nullptr )
    {
      v9 = v24;
      v10 = v25;
      *((_DWORD *)v8 + 3) = 1;
      *(_QWORD *)(v8 + 20) = v9;
      v11 = v23;
      *((float *)v8 + 7) = v10;
      *((_QWORD *)v8 + 4) = v11;
      *(_DWORD *)v8 = &CFunctor4<void (__cdecl *)(Vector const &,Vector const &,Color,bool),Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v8 + 2) = &CFunctor4<void (__cdecl *)(Vector const &,Vector const &,Color,bool),Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v8 + 4) = RenderLine;
      *((float *)v8 + 10) = z;
      v8[48] = bZBuffer;
      v12 = pCallQueue;
      *((Color *)v8 + 11) = c;
      v12->QueueFunctorInternal(this: v12, a2: (CFunctor *)v8);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    v13 = s_pWireframe;
    if ( !bZBuffer )
      v13 = s_pWireframeIgnoreZ;
    v5->Bind(this: v5, a2: v13, a3: nullptr);
    chRed = *(_WORD *)c._color;
    v14 = v5->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v15 = v14->GetDynamicMesh(this: v5, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v15;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v15->SetPrimitiveType(this: v15, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v15->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v15, nMaxVertexCount: 2, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v17 = chAlpha;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = v1->x;
    v18 = chBlue;
    m_pCurrPosition[1] = v1->y;
    v19 = HIBYTE(chRed);
    m_pCurrPosition[2] = v1->z;
    v20 = v18 | ((v19 | (((unsigned __int8)chRed | (v17 << 8)) << 8)) << 8);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v20;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = *v2;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v20;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v15->Draw_2(this: v15, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
  v5->EndRender(this: v5);
  v5->Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1027E110
// Name: void RenderTriangleInternal(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall RenderTriangleInternal(
        int a1@<esi>,
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        Color c,
        IMaterial *pMaterial)
{
  IMatRenderContext *v6; // edi
  float z; // esi
  float v8; // ebx
  float v9; // eax
  char *v10; // eax
  __int64 v11; // xmm0_8
  float v12; // ecx
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm5_4
  IMesh *v19; // edi
  float *m_pCurrPosition; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // esi
  int v24; // esi
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-224h] BYREF
  __int64 v31; // [esp+1F4h] [ebp-3Ch]
  __int64 v32; // [esp+200h] [ebp-30h]
  __int64 v33; // [esp+20Ch] [ebp-24h]
  float v34; // [esp+214h] [ebp-1Ch]
  ICallQueue *pCallQueue; // [esp+218h] [ebp-18h]
  CMatRenderContextPtr pRenderContext; // [esp+21Ch] [ebp-14h]
  Vector vecNormal; // [esp+220h] [ebp-10h] BYREF
  unsigned __int8 chBlue; // [esp+22Ch] [ebp-4h]
  unsigned __int8 chAlpha; // [esp+22Dh] [ebp-3h]
  __int16 chRed; // [esp+22Eh] [ebp-2h] OVERLAPPED

  InitializeStandardMaterials(a1);
  v6 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  pCallQueue = v6->GetCallQueue(this: v6);
  if ( pCallQueue != nullptr )
  {
    z = p3->z;
    v8 = p2->z;
    v31 = *(_QWORD *)&p3->x;
    v32 = *(_QWORD *)&p2->x;
    v9 = p1->z;
    v33 = *(_QWORD *)&p1->x;
    v34 = v9;
    v10 = (char *)MemAlloc_Alloc(nSize: 0x40u);
    if ( v10 != nullptr )
    {
      v11 = v33;
      v12 = v34;
      *((_DWORD *)v10 + 3) = 1;
      *(_QWORD *)(v10 + 20) = v11;
      *((_QWORD *)v10 + 4) = v32;
      *(_QWORD *)(v10 + 44) = v31;
      *((float *)v10 + 7) = v12;
      *(_DWORD *)v10 = &CFunctor5<void (__cdecl *)(Vector const &,Vector const &,Vector const &,Color,IMaterial *),Vector,Vector,Vector,Color,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v10 + 2) = &CFunctor5<void (__cdecl *)(Vector const &,Vector const &,Vector const &,Color,IMaterial *),Vector,Vector,Vector,Color,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v10 + 4) = RenderTriangleInternal;
      *((float *)v10 + 10) = v8;
      *((float *)v10 + 13) = z;
      *((Color *)v10 + 14) = c;
      *((_DWORD *)v10 + 15) = pMaterial;
    }
    else
    {
      v10 = nullptr;
    }
    pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: (CFunctor *)v10);
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
  else
  {
    v6->Bind(this: v6, a2: pMaterial, a3: nullptr);
    v13 = p2->y - p1->y;
    v14 = p2->z - p1->z;
    v15 = p2->x - p1->x;
    chRed = *(_WORD *)c._color;
    chBlue = c._color[2];
    v16 = p3->y - p1->y;
    v17 = p3->z - p1->z;
    v18 = p3->x - p1->x;
    chAlpha = c._color[3];
    vecNormal.x = (float)(v17 * v13) - (float)(v16 * v14);
    vecNormal.y = (float)(v14 * v18) - (float)(v17 * v15);
    vecNormal.z = (float)(v16 * v15) - (float)(v13 * v18);
    VectorNormalize(vec: &vecNormal);
    v19 = v6->GetDynamicMesh(this: v6, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v19;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v19->SetPrimitiveType(this: v19, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 3, a3: 3, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v19->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 3;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v19, nMaxVertexCount: 3, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v21 = (unsigned __int8)chRed;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = p1->x;
    v22 = HIBYTE(chRed);
    m_pCurrPosition[1] = p1->y;
    v23 = chAlpha;
    m_pCurrPosition[2] = p1->z;
    v24 = chBlue | ((v22 | ((v21 | (v23 << 8)) << 8)) << 8);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
    v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v25[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = *p2;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
    v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v26[1] = 1.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = *p3;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v24;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
    v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v27[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v19->Draw_2(this: v19, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E5B0
// Name: void RenderTriangle(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderTriangle(
        int a1@<esi>,
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        Color c,
        __int16 bZBuffer)
{
  IMaterial *v6; // ecx

  InitializeStandardMaterials(a1);
  v6 = s_pVertexColor;
  if ( (_BYTE)bZBuffer == 0 )
    v6 = s_pVertexColorIgnoreZ;
  RenderTriangleInternal(a1, p1, p2, p3, c, pMaterial: v6);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B8270
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x102B8330
// Name: void RenderAxesAtOrigin(class Vector const __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RenderAxesAtOrigin(const Vector *vOrigin, float flScale, bool bZBuffer)
{
  RenderAxes(vOrigin, flScale, bZBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x102B8350
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax
  IMaterial v5; // edx
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  IMaterial *v8; // eax
  IMaterial v9; // edx
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  IMaterial *v12; // eax
  IMaterial v13; // edx
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  IMaterial *v16; // eax
  IMaterial v17; // edx

  if ( (_S1_30 & 1) == 0 )
  {
    _S1_30 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex__.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "wireframe");
  else
    v3 = nullptr;
  KeyValues::SetInt(this: v3, keyName: "$vertexcolor", value: 1);
  v4 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v3,
                      a4: a1);
  v5.__vftable = v4->__vftable;
  s_pWireframe = v4;
  v5.IncrementReferenceCount(this: v4);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "wireframe");
  else
    v7 = nullptr;
  KeyValues::SetInt(this: v7, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v7, keyName: "$ignorez", value: 1);
  v8 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v7);
  v9.__vftable = v8->__vftable;
  s_pWireframeIgnoreZ = v8;
  v9.IncrementReferenceCount(this: v8);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "unlitgeneric");
  else
    v11 = nullptr;
  KeyValues::SetInt(this: v11, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v11, keyName: "$vertexalpha", value: 1);
  v12 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v11);
  v13.__vftable = v12->__vftable;
  s_pVertexColor = v12;
  v13.IncrementReferenceCount(this: v12);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "unlitgeneric");
  else
    v15 = nullptr;
  KeyValues::SetInt(this: v15, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$ignorez", value: 1);
  v16 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *))g_pMaterialSystem->CreateMaterial)(
                       a1: g_pMaterialSystem,
                       a2: "__utilVertexColorIgnoreZ");
  v17.__vftable = v16->__vftable;
  s_pVertexColorIgnoreZ = v16;
  v17.IncrementReferenceCount(this: v16);
  if ( --autoMutex__.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x102B8590
// Name: public: virtual void CFunctor6<void (*)(class Vector const __near &,float,int,int,class Color,bool),class Vector,float,int,int,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, _DWORD, int, int, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: LODWORD(this->m_arg2),
    a3: this->m_arg3,
    a4: this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x102B85C0
// Name: public: virtual void CFunctor6<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool),class Vector,class QAngle,class Vector,class Vector,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x102B85F0
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x102B8620
// Name: public: virtual void CFunctor3<void (*)(class Vector const __near &,float,bool),class Vector,float,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor3<void (__cdecl *)(Vector const &,float,bool),Vector,float,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor3<void (__cdecl*)(Vector const &,float,bool),Vector,float,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: LODWORD(this->m_arg2),
    a3: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x102B8650
// Name: void RenderQuad(class IMaterial __near *,float,float,float,float,float,float,float,float,float,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderQuad(
        int a1@<edi>,
        IMaterial *pMaterial,
        float x,
        float y,
        float w,
        float h,
        float z,
        float s0,
        float t0,
        float s1,
        float t1,
        const Color *clr)
{
  IMatRenderContext *v12; // esi
  IMesh *v13; // edi
  float *v14; // eax
  float *m_pCurrPosition; // eax
  float *v16; // eax
  float *v17; // eax
  float *v18; // eax
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v12 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v12;
  if ( v12 != nullptr )
    v12->BeginRender(this: v12);
  v13 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, IMaterial *, int))v12->GetDynamicMesh)(
                   a1: v12,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: pMaterial,
                   a6: a1);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v13;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v13->SetPrimitiveType(this: v13, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v13->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v13, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = clr->_color[2]
                                                      | ((clr->_color[1]
                                                        | ((clr->_color[0] | (clr->_color[3] << 8)) << 8)) << 8);
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = s0;
  v14[1] = t0;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = z;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = clr->_color[2]
                                                      | ((clr->_color[1]
                                                        | ((clr->_color[0] | (clr->_color[3] << 8)) << 8)) << 8);
  v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = s1;
  v16[1] = t0;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = x + w;
  v17[1] = y;
  v17[2] = z;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = clr->_color[2]
                                                      | ((clr->_color[1]
                                                        | ((clr->_color[0] | (clr->_color[3] << 8)) << 8)) << 8);
  v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = s1;
  v18[1] = t1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = x + w;
  v19[1] = y + h;
  v19[2] = z;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = clr->_color[2]
                                                      | ((clr->_color[1]
                                                        | ((clr->_color[0] | (clr->_color[3] << 8)) << 8)) << 8);
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = s0;
  v20[1] = t1;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
  v21[1] = y + h;
  v21[2] = z;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v13->Draw_2(this: v13, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x102B8A20
// Name: public: void ICallQueue::QueueCall<void,class Vector const __near &,float,bool,class Vector,float,bool>(void (*)(class Vector const __near &,float,bool),class Vector const __near &,float const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,Vector const &,float,bool,Vector,float,bool>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(const Vector *, float, bool),
        const Vector *arg1,
        const float *arg2,
        const bool *arg3)
{
  char *v6; // eax

  v6 = (char *)operator new(nSize: 0x28u);
  if ( v6 != nullptr )
  {
    *((_DWORD *)v6 + 3) = 1;
    *((_DWORD *)v6 + 4) = pfnProxied;
    *(_DWORD *)v6 = &CFunctor3<void (__cdecl *)(Vector const &,float,bool),Vector,float,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    *((_DWORD *)v6 + 2) = &CFunctor3<void (__cdecl *)(Vector const &,float,bool),Vector,float,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    *(Vector *)(v6 + 20) = *arg1;
    *((float *)v6 + 8) = *arg2;
    v6[36] = *arg3;
    this->QueueFunctorInternal(this, a2: (CFunctor *)v6);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8A90
// Name: void RenderWireframeSphere(class Vector const __near &,float,int,int,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeSphere(
        int a1@<esi>,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi,
        Color c,
        bool bZBuffer)
{
  IMatRenderContext *v7; // esi
  ICallQueue *v8; // edi
  float z; // ebx
  char *v10; // eax
  __int64 v11; // xmm0_8
  int v12; // edi
  int v13; // esi
  int v14; // ebx
  IMaterial *v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // ebx
  double v19; // xmm0_8
  double v20; // xmm0_8
  int v21; // esi
  double v22; // xmm0_8
  float *m_pCurrPosition; // edi
  double v24; // xmm0_8
  signed int m_nCurrentIndex; // ecx
  __int16 v26; // dx
  signed int v27; // ecx
  signed int v28; // ecx
  signed int v29; // ecx
  bool v30; // zf
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  long double v33; // [esp+0h] [ebp-230h]
  long double v34; // [esp+0h] [ebp-230h]
  long double v35; // [esp+0h] [ebp-230h]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-224h] BYREF
  __int64 v37; // [esp+1F4h] [ebp-3Ch]
  float theta; // [esp+200h] [ebp-30h]
  float v39; // [esp+204h] [ebp-2Ch]
  IMesh *pMesh; // [esp+208h] [ebp-28h]
  float v41; // [esp+20Ch] [ebp-24h]
  float v42; // [esp+210h] [ebp-20h]
  float v43; // [esp+214h] [ebp-1Ch]
  float phi; // [esp+218h] [ebp-18h]
  CMatRenderContextPtr pRenderContext; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v47; // [esp+224h] [ebp-Ch]
  float v48; // [esp+228h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+22Ch] [ebp-4h]
  unsigned __int8 chRed; // [esp+22Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+22Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+22Fh] [ebp-1h]
  int nThetaa; // [esp+240h] [ebp+10h]

  InitializeStandardMaterials(a1);
  v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v8 = v7->GetCallQueue(this: v7);
  if ( v8 != nullptr )
  {
    z = vCenter->z;
    v37 = *(_QWORD *)&vCenter->x;
    v10 = (char *)operator new(nSize: 0x34u);
    if ( v10 != nullptr )
    {
      v11 = v37;
      *((_DWORD *)v10 + 3) = 1;
      *(_QWORD *)(v10 + 20) = v11;
      *((_DWORD *)v10 + 10) = nPhi;
      *(_DWORD *)v10 = &CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v10 + 2) = &CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v10 + 4) = RenderWireframeSphere;
      *((float *)v10 + 7) = z;
      *((float *)v10 + 8) = flRadius;
      *((_DWORD *)v10 + 9) = nTheta;
      *((Color *)v10 + 11) = c;
      v10[48] = bZBuffer;
    }
    else
    {
      v10 = nullptr;
    }
    v8->QueueFunctorInternal(this: v8, a2: (CFunctor *)v10);
    v7->EndRender(this: v7);
    v7->Release(this: v7);
  }
  else
  {
    v12 = nPhi;
    v13 = nPhi * (nTheta + 1);
    v14 = (nPhi - 1) * (4 * (nTheta + 1) - 4);
    nThetaa = nTheta + 1;
    v15 = s_pWireframe;
    v47 = nPhi - 1;
    if ( !bZBuffer )
      v15 = s_pWireframeIgnoreZ;
    pRenderContext.m_pObject->Bind(this: pRenderContext.m_pObject, a2: v15, a3: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    pMesh = pRenderContext.m_pObject->GetDynamicMesh(this: pRenderContext.m_pObject, a2: 1, a3: 0, a4: 0, a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_LINES,
      nVertexCount: v13,
      nIndexCount: v14,
      pMeshSettings: nullptr);
    chBlue = c._color[2];
    v16 = 0;
    chGreen = c._color[1];
    chRed = c._color[0];
    chAlpha = c._color[3];
    i = 0;
    if ( nPhi <= 0 )
    {
      v17 = nThetaa;
    }
    else
    {
      do
      {
        v17 = nThetaa;
        v18 = 0;
        if ( nThetaa > 0 )
        {
          v39 = (float)(nThetaa - 1);
          phi = (float)((float)v16 / (float)v47) * 3.141592653589793;
          v19 = phi;
          __libm_sse2_cos(x: v33);
          *(float *)&v19 = v19;
          v41 = *(float *)&v19 * flRadius;
          v20 = phi;
          __libm_sse2_sin(x: v34);
          *(float *)&v20 = v20;
          v48 = *(float *)&v20 * flRadius;
          v21 = chBlue | ((chGreen | ((chRed | (chAlpha << 8)) << 8)) << 8);
          do
          {
            theta = (float)((float)v18 / v39) * 6.283185307179586;
            v22 = theta;
            __libm_sse2_sin(x: v33);
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *(float *)&v22 = v22;
            v43 = (float)(*(float *)&v22 * v48) + vCenter->y;
            v42 = v41 + vCenter->z;
            v24 = theta;
            __libm_sse2_cos(x: v35);
            *(float *)&v24 = v24;
            *m_pCurrPosition = (float)(*(float *)&v24 * v48) + vCenter->x;
            m_pCurrPosition[1] = v43;
            m_pCurrPosition[2] = v42;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v21;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v18;
          }
          while ( v18 < nThetaa );
          v16 = i;
          v12 = nPhi;
          v17 = nThetaa;
        }
        i = ++v16;
      }
      while ( v16 < v12 );
    }
    if ( v47 > 0 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      v26 = 0;
      i = 0;
      v48 = *(float *)&v47;
      do
      {
        if ( v17 - 1 > 0 )
        {
          v47 = v17 - 1;
          do
          {
            meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v26
                                                                   + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v27 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v27;
            if ( v27 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v27;
            meshBuilder.m_IndexBuilder.m_pIndices[v27] = v17 + v26 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v28 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v28;
            if ( v28 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v28;
            meshBuilder.m_IndexBuilder.m_pIndices[v28] = v26 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v29 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v29;
            if ( v29 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v29;
            meshBuilder.m_IndexBuilder.m_pIndices[v29] = v26 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + 1;
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
            if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            ++v26;
            --v47;
          }
          while ( *(float *)&v47 != 0.0 );
        }
        v26 = v17 + i;
        v30 = LODWORD(v48)-- == 1;
        i += v17;
      }
      while ( !v30 );
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8FA0
// Name: void RenderWireframeBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        bool bZBuffer)
{
  IMatRenderContext *v7; // esi
  float z; // edi
  float v9; // ebx
  __int64 v10; // xmm0_8
  float v11; // ecx
  char *v12; // eax
  __int64 v13; // xmm0_8
  float v14; // edx
  float v15; // ecx
  IMaterial *v16; // eax
  IMatRenderContext v17; // edx
  IMesh *v18; // esi
  int v19; // esi
  int *v20; // ebx
  int i; // edi
  float *m_pCurrPosition; // ecx
  Vector *v23; // eax
  int v24; // eax
  float *v25; // ecx
  int v26; // eax
  double x; // st7
  Vector *v28; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  Vector p[8]; // [esp+Ch] [ebp-284h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-224h] BYREF
  __int64 v33; // [esp+254h] [ebp-3Ch]
  __int64 v34; // [esp+260h] [ebp-30h]
  __int64 v35; // [esp+26Ch] [ebp-24h]
  float v36; // [esp+274h] [ebp-1Ch]
  __int64 v37; // [esp+278h] [ebp-18h]
  float v38; // [esp+280h] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+284h] [ebp-Ch]
  IMesh *pMesh; // [esp+288h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+28Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+28Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+28Fh] [ebp-1h]

  InitializeStandardMaterials(a1);
  v7 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  pMesh = (IMesh *)v7->GetCallQueue(this: v7);
  if ( pMesh != nullptr )
  {
    z = vMaxs->z;
    v9 = vMins->z;
    v34 = *(_QWORD *)&vMaxs->x;
    v33 = *(_QWORD *)&vMins->x;
    v10 = *(_QWORD *)&angles->x;
    v36 = angles->z;
    v11 = vOrigin->z;
    v35 = v10;
    v37 = *(_QWORD *)&vOrigin->x;
    v38 = v11;
    v12 = (char *)operator new(nSize: 0x4Cu);
    if ( v12 != nullptr )
    {
      v13 = v37;
      v14 = v38;
      v15 = v36;
      *((_DWORD *)v12 + 3) = 1;
      *(_QWORD *)(v12 + 20) = v13;
      *((_QWORD *)v12 + 4) = v35;
      *(_QWORD *)(v12 + 44) = v33;
      *((_QWORD *)v12 + 7) = v34;
      *((float *)v12 + 10) = v15;
      *(_DWORD *)v12 = &CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v12 + 2) = &CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v12 + 4) = RenderWireframeBox;
      *((float *)v12 + 7) = v14;
      *((float *)v12 + 13) = v9;
      *((float *)v12 + 16) = z;
      *((Color *)v12 + 17) = c;
      v12[72] = bZBuffer;
    }
    else
    {
      v12 = nullptr;
    }
    ((void (__thiscall *)(IMesh *, char *))pMesh->VertexCount)(a1: pMesh, a2: v12);
    v7->EndRender(this: v7);
    v7->Release(this: v7);
  }
  else
  {
    v16 = s_pWireframe;
    if ( !bZBuffer )
      v16 = s_pWireframeIgnoreZ;
    v7->Bind(this: v7, a2: v16, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chBlue = c._color[2];
    v17.__vftable = v7->__vftable;
    chGreen = c._color[1];
    chAlpha = c._color[3];
    v18 = v17.GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v18;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v18;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v18->SetPrimitiveType(this: v18, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 48, a3: 48, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v18->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 48;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v18, nMaxVertexCount: 48, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v19 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v20 = s_pBoxFaceIndices[0];
    do
    {
      for ( i = 0; i < 4; ++i )
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v23 = &p[v20[i]];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v23->x;
        m_pCurrPosition[1] = v23->y;
        m_pCurrPosition[2] = v23->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v19;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( i == 3 )
          v24 = 0;
        else
          v24 = i + 1;
        v25 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v26 = v20[v24];
        x = p[v26].x;
        v28 = &p[v26];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
        v25[1] = v28->y;
        v25[2] = v28->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v19;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      }
      v20 += 4;
    }
    while ( (int)v20 < (int)s_pBoxFaceIndicesInsideOut[0] );
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B93C0
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v10; // edi
  __int64 v11; // xmm0_8
  float v12; // ecx
  char *v13; // eax
  __int64 v14; // xmm0_8
  float v15; // edx
  float v16; // ecx
  __int64 v17; // xmm0_8
  ICallQueue *v18; // ecx
  IMatRenderContext v19; // eax
  IMesh *v20; // esi
  unsigned int v21; // ecx
  int v22; // edi
  ICallQueue *v23; // eax
  int v24; // xmm1_4
  int *v25; // eax
  int v26; // esi
  int v27; // edx
  int v28; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v31; // eax
  double v32; // st7
  Vector *v33; // eax
  float *m_pCurrNormal; // eax
  float *v35; // eax
  float *v36; // ecx
  float v37; // xmm0_4
  Vector *v38; // eax
  float *v39; // eax
  int v40; // xmm0_4
  float *v41; // eax
  float *v42; // ecx
  float v43; // xmm0_4
  Vector *v44; // eax
  float *v45; // eax
  int v46; // xmm0_4
  float *v47; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v51; // [esp+254h] [ebp-4Ch]
  __int64 v52; // [esp+260h] [ebp-40h]
  __int64 v53; // [esp+26Ch] [ebp-34h]
  float v54; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v10 = vMins->z;
    v51 = *(_QWORD *)&vMaxs->x;
    v52 = *(_QWORD *)&vMins->x;
    v11 = *(_QWORD *)&angles->x;
    v54 = angles->z;
    v12 = vOrigin->z;
    v53 = v11;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v12;
    v13 = (char *)operator new(nSize: 0x50u);
    if ( v13 != nullptr )
    {
      v14 = *(_QWORD *)&vecNormal.x;
      v15 = vecNormal.z;
      v16 = v54;
      *((_DWORD *)v13 + 3) = 1;
      *(_QWORD *)(v13 + 20) = v14;
      *((_QWORD *)v13 + 4) = v53;
      *(_QWORD *)(v13 + 44) = v52;
      v17 = v51;
      *((float *)v13 + 10) = v16;
      *((_QWORD *)v13 + 7) = v17;
      *((float *)v13 + 7) = v15;
      *(_DWORD *)v13 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v13 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v13 + 4) = RenderBoxInternal;
      *((float *)v13 + 13) = v10;
      *((float *)v13 + 16) = z;
      *((Color *)v13 + 17) = c;
      *((_DWORD *)v13 + 18) = pMaterial;
      v18 = pCallQueue;
      v13[76] = bInsideOut;
      v18->QueueFunctorInternal(this: v18, a2: (CFunctor *)v13);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v19.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v20 = v19.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v20;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v20;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v20->SetPrimitiveType(this: v20, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v20->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v20, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v21 = 0;
    i = 0;
    v22 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v23 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v24 = (v21 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v21 >> 1)) = v24;
      if ( bInsideOut )
      {
        v25 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v23);
        ppFaceIndices = v25;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v23);
        v25 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v23);
      }
      v26 = 1;
      while ( 1 )
      {
        v27 = v25[v26];
        v28 = v25[v26 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v31 = *v25;
        v32 = p[v31].x;
        v33 = &p[v31];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v32;
        i1 = v27;
        m_pCurrPosition[1] = v33->y;
        m_pCurrPosition[2] = v33->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v35[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v36 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v37 = vecNormal.x;
        v38 = &p[v28];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v38->x;
        v36[1] = v38->y;
        v36[2] = v38->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        v39 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v37;
        v39[1] = vecNormal.y;
        v39[2] = vecNormal.z;
        v40 = v26 == 1 ? 1065353216 : 0;
        v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v41 + 1) = v40;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v42 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v43 = vecNormal.x;
        v44 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v44->x;
        v42[1] = v44->y;
        v42[2] = v44->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v22;
        v45 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v43;
        v45[1] = vecNormal.y;
        v45[2] = vecNormal.z;
        v46 = v26 == 1 ? 0 : 1065353216;
        v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v46;
        v47[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v26 >= 3 )
          break;
        v25 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v23 = pCallQueue;
      v21 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x102B9960
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  RenderBoxInternal(a1, vOrigin, angles, vMins, vMaxs, c, pMaterial, bInsideOut);
}

//------------------------------------------------------------------------------
// Address: 0x102B9990
// Name: void RenderAxes(class Vector const __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderAxes(int a1@<edi>, int a2@<esi>, const Vector *vOrigin, float flScale, bool bZBuffer)
{
  IMatRenderContext *v5; // ebx
  ICallQueue *v6; // eax
  __int64 v7; // xmm0_8
  IMaterial *v8; // eax
  IMesh *v9; // edi
  float *m_pCurrPosition; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float *v17; // eax
  float v18; // xmm1_4
  float v19; // xmm0_4
  float *v20; // eax
  float v21; // xmm1_4
  float *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm0_4
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F4h] BYREF
  Vector arg1; // [esp+1F0h] [ebp-Ch] BYREF

  InitializeStandardMaterials(a1: a2);
  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v6 = v5->GetCallQueue(this: v5);
  if ( v6 != nullptr )
  {
    v7 = *(_QWORD *)&vOrigin->x;
    arg1.z = vOrigin->z;
    *(_QWORD *)&arg1.x = v7;
    ICallQueue::QueueCall<void,Vector const &,float,bool,Vector,float,bool>(
      this: v6,
      pfnProxied: RenderAxesAtOrigin,
      &arg1,
      arg2: &flScale,
      arg3: &bZBuffer);
    v5->EndRender(this: v5);
    v5->Release(this: v5);
  }
  else
  {
    v8 = s_pWireframe;
    if ( !bZBuffer )
      v8 = s_pWireframeIgnoreZ;
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))v5->Bind)(a1: v5, a2: v8, a3: 0, a4: a1);
    v9 = v5->GetDynamicMesh(this: v5, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v9;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v9->SetPrimitiveType(this: v9, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 6, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v9, nMaxVertexCount: 6, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    y = vOrigin->y;
    z = vOrigin->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vOrigin->x;
    m_pCurrPosition[1] = y;
    m_pCurrPosition[2] = z;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v14 = vOrigin->y;
    v15 = vOrigin->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vOrigin->x + flScale;
    v13[1] = v14;
    v13[2] = v15;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v16 = vOrigin->y;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v18 = vOrigin->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vOrigin->x;
    v17[1] = v16;
    v17[2] = v18;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v19 = vOrigin->y;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v21 = vOrigin->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vOrigin->x;
    v20[1] = v19 + flScale;
    v20[2] = v21;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v23 = vOrigin->y;
    v24 = vOrigin->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vOrigin->x;
    v22[1] = v23;
    v22[2] = v24;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v25 = vOrigin->z;
    v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v27 = vOrigin->y;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vOrigin->x;
    v28 = v25 + flScale;
    v26[1] = v27;
    v26[2] = v28;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v9->Draw_2(this: v9, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    v5->EndRender(this: v5);
    v5->Release(this: v5);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0057B470
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x0057B530
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<ecx>, int a2@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMaterial *v5; // eax
  IMaterial v6; // edx
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMaterial *v9; // eax
  IMaterial v10; // edx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  IMaterial *v13; // eax
  IMaterial v14; // edx
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  IMaterial *v17; // eax
  IMaterial v18; // edx

  if ( (_S1_9 & 1) == 0 )
  {
    _S1_9 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex__.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "wireframe");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$vertexcolor", value: 1);
  v5 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v4,
                      a4: a2,
                      a5: a1);
  v6.__vftable = v5->__vftable;
  s_pWireframe = v5;
  v6.IncrementReferenceCount(this: v5);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "wireframe");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
  v9 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v8);
  v10.__vftable = v9->__vftable;
  s_pWireframeIgnoreZ = v9;
  v10.IncrementReferenceCount(this: v9);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "unlitgeneric");
  else
    v12 = nullptr;
  KeyValues::SetInt(this: v12, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v12, keyName: "$vertexalpha", value: 1);
  v13 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v12);
  v14.__vftable = v13->__vftable;
  s_pVertexColor = v13;
  v14.IncrementReferenceCount(this: v13);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "unlitgeneric");
  else
    v16 = nullptr;
  KeyValues::SetInt(this: v16, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$ignorez", value: 1);
  v17 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColorIgnoreZ", a3: v16);
  v18.__vftable = v17->__vftable;
  s_pVertexColorIgnoreZ = v17;
  v18.IncrementReferenceCount(this: v17);
  if ( --autoMutex__.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x0057B770
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x0057B780
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057B7B0
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x0057B820
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v11; // edi
  __int64 v12; // xmm0_8
  float v13; // ecx
  char *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // edx
  float v17; // ecx
  __int64 v18; // xmm0_8
  ICallQueue *v19; // ecx
  IMatRenderContext v20; // eax
  IMesh *v21; // esi
  unsigned int v22; // ecx
  int v23; // edi
  ICallQueue *v24; // eax
  int v25; // xmm1_4
  int *v26; // eax
  int v27; // esi
  int v28; // edx
  int v29; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v32; // eax
  double v33; // st7
  Vector *v34; // eax
  float *m_pCurrNormal; // eax
  float *v36; // eax
  float *v37; // ecx
  float v38; // xmm0_4
  Vector *v39; // eax
  float *v40; // eax
  int v41; // xmm0_4
  float *v42; // eax
  float *v43; // ecx
  float v44; // xmm0_4
  Vector *v45; // eax
  float *v46; // eax
  int v47; // xmm0_4
  float *v48; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v52; // [esp+254h] [ebp-4Ch]
  __int64 v53; // [esp+260h] [ebp-40h]
  __int64 v54; // [esp+26Ch] [ebp-34h]
  float v55; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1, a2);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v11 = vMins->z;
    v52 = *(_QWORD *)&vMaxs->x;
    v53 = *(_QWORD *)&vMins->x;
    v12 = *(_QWORD *)&angles->x;
    v55 = angles->z;
    v13 = vOrigin->z;
    v54 = v12;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v13;
    v14 = (char *)operator new(nSize: 0x50u);
    if ( v14 != nullptr )
    {
      v15 = *(_QWORD *)&vecNormal.x;
      v16 = vecNormal.z;
      v17 = v55;
      *((_DWORD *)v14 + 3) = 1;
      *(_QWORD *)(v14 + 20) = v15;
      *((_QWORD *)v14 + 4) = v54;
      *(_QWORD *)(v14 + 44) = v53;
      v18 = v52;
      *((float *)v14 + 10) = v17;
      *((_QWORD *)v14 + 7) = v18;
      *((float *)v14 + 7) = v16;
      *(_DWORD *)v14 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v14 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v14 + 4) = RenderBoxInternal;
      *((float *)v14 + 13) = v11;
      *((float *)v14 + 16) = z;
      *((Color *)v14 + 17) = c;
      *((_DWORD *)v14 + 18) = pMaterial;
      v19 = pCallQueue;
      v14[76] = bInsideOut;
      v19->QueueFunctorInternal(this: v19, a2: (CFunctor *)v14);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v20.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v21 = v20.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v21;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v21;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v21->SetPrimitiveType(this: v21, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v21->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v21, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v22 = 0;
    i = 0;
    v23 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v24 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v25 = (v22 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v22 >> 1)) = v25;
      if ( bInsideOut )
      {
        v26 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v24);
        ppFaceIndices = v26;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
        v26 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
      }
      v27 = 1;
      while ( 1 )
      {
        v28 = v26[v27];
        v29 = v26[v27 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v32 = *v26;
        v33 = p[v32].x;
        v34 = &p[v32];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33;
        i1 = v28;
        m_pCurrPosition[1] = v34->y;
        m_pCurrPosition[2] = v34->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v36[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v37 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v38 = vecNormal.x;
        v39 = &p[v29];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39->x;
        v37[1] = v39->y;
        v37[2] = v39->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v40 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v38;
        v40[1] = vecNormal.y;
        v40[2] = vecNormal.z;
        v41 = v27 == 1 ? 1065353216 : 0;
        v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v42 + 1) = v41;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v44 = vecNormal.x;
        v45 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v45->x;
        v43[1] = v45->y;
        v43[2] = v45->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v44;
        v46[1] = vecNormal.y;
        v46[2] = vecNormal.z;
        v47 = v27 == 1 ? 0 : 1065353216;
        v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v47;
        v48[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v27 >= 3 )
          break;
        v26 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v24 = pCallQueue;
      v22 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x0057BDC0
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        __int16 bZBuffer,
        bool bInsideOut)
{
  IMaterial *v9; // ecx

  InitializeStandardMaterials(a1, a2);
  v9 = s_pVertexColor;
  if ( (_BYTE)bZBuffer == 0 )
    v9 = s_pVertexColorIgnoreZ;
  RenderBoxInternal(a1: (int)angles, a2, vOrigin, angles, vMins, vMaxs, c, pMaterial: v9, bInsideOut);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C8080
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x005C8140
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x005C81C0
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<ecx>, int a2@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMaterial *v5; // eax
  IMaterial v6; // edx
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMaterial *v9; // eax
  IMaterial v10; // edx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  IMaterial *v13; // eax
  IMaterial v14; // edx
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  IMaterial *v17; // eax
  IMaterial v18; // edx

  if ( (_S1_10 & 1) == 0 )
  {
    _S1_10 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex__.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "wireframe");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$vertexcolor", value: 1);
  v5 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v4,
                      a4: a2,
                      a5: a1);
  v6.__vftable = v5->__vftable;
  s_pWireframe = v5;
  v6.IncrementReferenceCount(this: v5);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "wireframe");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
  v9 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v8);
  v10.__vftable = v9->__vftable;
  s_pWireframeIgnoreZ = v9;
  v10.IncrementReferenceCount(this: v9);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "unlitgeneric");
  else
    v12 = nullptr;
  KeyValues::SetInt(this: v12, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v12, keyName: "$vertexalpha", value: 1);
  v13 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v12);
  v14.__vftable = v13->__vftable;
  s_pVertexColor = v13;
  v14.IncrementReferenceCount(this: v13);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "unlitgeneric");
  else
    v16 = nullptr;
  KeyValues::SetInt(this: v16, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$ignorez", value: 1);
  v17 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColorIgnoreZ", a3: v16);
  v18.__vftable = v17->__vftable;
  s_pVertexColorIgnoreZ = v17;
  v18.IncrementReferenceCount(this: v17);
  if ( --autoMutex__.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x005C8400
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x005C8410
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C8440
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x005C84B0
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v11; // edi
  __int64 v12; // xmm0_8
  float v13; // ecx
  char *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // edx
  float v17; // ecx
  __int64 v18; // xmm0_8
  ICallQueue *v19; // ecx
  IMatRenderContext v20; // eax
  IMesh *v21; // esi
  unsigned int v22; // ecx
  int v23; // edi
  ICallQueue *v24; // eax
  int v25; // xmm1_4
  int *v26; // eax
  int v27; // esi
  int v28; // edx
  int v29; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v32; // eax
  double v33; // st7
  Vector *v34; // eax
  float *m_pCurrNormal; // eax
  float *v36; // eax
  float *v37; // ecx
  float v38; // xmm0_4
  Vector *v39; // eax
  float *v40; // eax
  int v41; // xmm0_4
  float *v42; // eax
  float *v43; // ecx
  float v44; // xmm0_4
  Vector *v45; // eax
  float *v46; // eax
  int v47; // xmm0_4
  float *v48; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v52; // [esp+254h] [ebp-4Ch]
  __int64 v53; // [esp+260h] [ebp-40h]
  __int64 v54; // [esp+26Ch] [ebp-34h]
  float v55; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1, a2);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v11 = vMins->z;
    v52 = *(_QWORD *)&vMaxs->x;
    v53 = *(_QWORD *)&vMins->x;
    v12 = *(_QWORD *)&angles->x;
    v55 = angles->z;
    v13 = vOrigin->z;
    v54 = v12;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v13;
    v14 = (char *)MemAlloc_Alloc(nSize: 0x50u);
    if ( v14 != nullptr )
    {
      v15 = *(_QWORD *)&vecNormal.x;
      v16 = vecNormal.z;
      v17 = v55;
      *((_DWORD *)v14 + 3) = 1;
      *(_QWORD *)(v14 + 20) = v15;
      *((_QWORD *)v14 + 4) = v54;
      *(_QWORD *)(v14 + 44) = v53;
      v18 = v52;
      *((float *)v14 + 10) = v17;
      *((_QWORD *)v14 + 7) = v18;
      *((float *)v14 + 7) = v16;
      *(_DWORD *)v14 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v14 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v14 + 4) = RenderBoxInternal;
      *((float *)v14 + 13) = v11;
      *((float *)v14 + 16) = z;
      *((Color *)v14 + 17) = c;
      *((_DWORD *)v14 + 18) = pMaterial;
      v19 = pCallQueue;
      v14[76] = bInsideOut;
      v19->QueueFunctorInternal(this: v19, a2: (CFunctor *)v14);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v20.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v21 = v20.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v21;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v21;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v21->SetPrimitiveType(this: v21, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v21->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v21, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v22 = 0;
    i = 0;
    v23 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v24 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v25 = (v22 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v22 >> 1)) = v25;
      if ( bInsideOut )
      {
        v26 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v24);
        ppFaceIndices = v26;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
        v26 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
      }
      v27 = 1;
      while ( 1 )
      {
        v28 = v26[v27];
        v29 = v26[v27 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v32 = *v26;
        v33 = p[v32].x;
        v34 = &p[v32];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33;
        i1 = v28;
        m_pCurrPosition[1] = v34->y;
        m_pCurrPosition[2] = v34->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v36[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v37 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v38 = vecNormal.x;
        v39 = &p[v29];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39->x;
        v37[1] = v39->y;
        v37[2] = v39->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v40 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v38;
        v40[1] = vecNormal.y;
        v40[2] = vecNormal.z;
        v41 = v27 == 1 ? 1065353216 : 0;
        v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v42 + 1) = v41;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v44 = vecNormal.x;
        v45 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v45->x;
        v43[1] = v45->y;
        v43[2] = v45->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v44;
        v46[1] = vecNormal.y;
        v46[2] = vecNormal.z;
        v47 = v27 == 1 ? 0 : 1065353216;
        v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v47;
        v48[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v27 >= 3 )
          break;
        v26 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v24 = pCallQueue;
      v22 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005C8A50
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        __int16 bZBuffer,
        bool bInsideOut)
{
  IMaterial *v9; // ecx

  InitializeStandardMaterials(a1, a2);
  v9 = s_pVertexColor;
  if ( (_BYTE)bZBuffer == 0 )
    v9 = s_pVertexColorIgnoreZ;
  RenderBoxInternal(a1: (int)angles, a2, vOrigin, angles, vMins, vMaxs, c, pMaterial: v9, bInsideOut);
}

} // namespace mdlcompile

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00420D80
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x00420E40
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<ecx>, int a2@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMaterial *v5; // eax
  IMaterial v6; // edx
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMaterial *v9; // eax
  IMaterial v10; // edx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  IMaterial *v13; // eax
  IMaterial v14; // edx
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  IMaterial *v17; // eax
  IMaterial v18; // edx

  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex__.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "wireframe");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$vertexcolor", value: 1);
  v5 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v4,
                      a4: a2,
                      a5: a1);
  v6.__vftable = v5->__vftable;
  s_pWireframe = v5;
  v6.IncrementReferenceCount(this: v5);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "wireframe");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
  v9 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v8);
  v10.__vftable = v9->__vftable;
  s_pWireframeIgnoreZ = v9;
  v10.IncrementReferenceCount(this: v9);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "unlitgeneric");
  else
    v12 = nullptr;
  KeyValues::SetInt(this: v12, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v12, keyName: "$vertexalpha", value: 1);
  v13 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v12);
  v14.__vftable = v13->__vftable;
  s_pVertexColor = v13;
  v14.IncrementReferenceCount(this: v13);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "unlitgeneric");
  else
    v16 = nullptr;
  KeyValues::SetInt(this: v16, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$ignorez", value: 1);
  v17 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColorIgnoreZ", a3: v16);
  v18.__vftable = v17->__vftable;
  s_pVertexColorIgnoreZ = v17;
  v18.IncrementReferenceCount(this: v17);
  if ( --autoMutex__.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x00421080
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x00421090
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004210C0
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x00421130
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v11; // edi
  __int64 v12; // xmm0_8
  float v13; // ecx
  char *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // edx
  float v17; // ecx
  __int64 v18; // xmm0_8
  ICallQueue *v19; // ecx
  IMatRenderContext v20; // eax
  IMesh *v21; // esi
  unsigned int v22; // ecx
  int v23; // edi
  ICallQueue *v24; // eax
  int v25; // xmm1_4
  int *v26; // eax
  int v27; // esi
  int v28; // edx
  int v29; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v32; // eax
  double v33; // st7
  Vector *v34; // eax
  float *m_pCurrNormal; // eax
  float *v36; // eax
  float *v37; // ecx
  float v38; // xmm0_4
  Vector *v39; // eax
  float *v40; // eax
  int v41; // xmm0_4
  float *v42; // eax
  float *v43; // ecx
  float v44; // xmm0_4
  Vector *v45; // eax
  float *v46; // eax
  int v47; // xmm0_4
  float *v48; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v52; // [esp+254h] [ebp-4Ch]
  __int64 v53; // [esp+260h] [ebp-40h]
  __int64 v54; // [esp+26Ch] [ebp-34h]
  float v55; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1, a2);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v11 = vMins->z;
    v52 = *(_QWORD *)&vMaxs->x;
    v53 = *(_QWORD *)&vMins->x;
    v12 = *(_QWORD *)&angles->x;
    v55 = angles->z;
    v13 = vOrigin->z;
    v54 = v12;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v13;
    v14 = (char *)operator new(nSize: 0x50u);
    if ( v14 != nullptr )
    {
      v15 = *(_QWORD *)&vecNormal.x;
      v16 = vecNormal.z;
      v17 = v55;
      *((_DWORD *)v14 + 3) = 1;
      *(_QWORD *)(v14 + 20) = v15;
      *((_QWORD *)v14 + 4) = v54;
      *(_QWORD *)(v14 + 44) = v53;
      v18 = v52;
      *((float *)v14 + 10) = v17;
      *((_QWORD *)v14 + 7) = v18;
      *((float *)v14 + 7) = v16;
      *(_DWORD *)v14 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v14 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v14 + 4) = RenderBoxInternal;
      *((float *)v14 + 13) = v11;
      *((float *)v14 + 16) = z;
      *((Color *)v14 + 17) = c;
      *((_DWORD *)v14 + 18) = pMaterial;
      v19 = pCallQueue;
      v14[76] = bInsideOut;
      v19->QueueFunctorInternal(this: v19, a2: (CFunctor *)v14);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v20.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v21 = v20.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v21;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v21;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v21->SetPrimitiveType(this: v21, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v21->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v21, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v22 = 0;
    i = 0;
    v23 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v24 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v25 = (v22 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v22 >> 1)) = v25;
      if ( bInsideOut )
      {
        v26 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v24);
        ppFaceIndices = v26;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
        v26 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
      }
      v27 = 1;
      while ( 1 )
      {
        v28 = v26[v27];
        v29 = v26[v27 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v32 = *v26;
        v33 = p[v32].x;
        v34 = &p[v32];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33;
        i1 = v28;
        m_pCurrPosition[1] = v34->y;
        m_pCurrPosition[2] = v34->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v36[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v37 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v38 = vecNormal.x;
        v39 = &p[v29];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39->x;
        v37[1] = v39->y;
        v37[2] = v39->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v40 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v38;
        v40[1] = vecNormal.y;
        v40[2] = vecNormal.z;
        v41 = v27 == 1 ? 1065353216 : 0;
        v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v42 + 1) = v41;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v44 = vecNormal.x;
        v45 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v45->x;
        v43[1] = v45->y;
        v43[2] = v45->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v44;
        v46[1] = vecNormal.y;
        v46[2] = vecNormal.z;
        v47 = v27 == 1 ? 0 : 1065353216;
        v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v47;
        v48[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v27 >= 3 )
          break;
        v26 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v24 = pCallQueue;
      v22 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x004216D0
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  RenderBoxInternal(a1: (int)vMins, a2: a1, vOrigin, angles, vMins, vMaxs, c, pMaterial, bInsideOut);
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006067A0
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x00606860
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<ecx>, int a2@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMaterial *v5; // eax
  IMaterial v6; // edx
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMaterial *v9; // eax
  IMaterial v10; // edx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  IMaterial *v13; // eax
  IMaterial v14; // edx
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  IMaterial *v17; // eax
  IMaterial v18; // edx

  if ( (_S1_11 & 1) == 0 )
  {
    _S1_11 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex__.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "wireframe");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$vertexcolor", value: 1);
  v5 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v4,
                      a4: a2,
                      a5: a1);
  v6.__vftable = v5->__vftable;
  s_pWireframe = v5;
  v6.IncrementReferenceCount(this: v5);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "wireframe");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
  v9 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v8);
  v10.__vftable = v9->__vftable;
  s_pWireframeIgnoreZ = v9;
  v10.IncrementReferenceCount(this: v9);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "unlitgeneric");
  else
    v12 = nullptr;
  KeyValues::SetInt(this: v12, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v12, keyName: "$vertexalpha", value: 1);
  v13 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v12);
  v14.__vftable = v13->__vftable;
  s_pVertexColor = v13;
  v14.IncrementReferenceCount(this: v13);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "unlitgeneric");
  else
    v16 = nullptr;
  KeyValues::SetInt(this: v16, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$ignorez", value: 1);
  v17 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColorIgnoreZ", a3: v16);
  v18.__vftable = v17->__vftable;
  s_pVertexColorIgnoreZ = v17;
  v18.IncrementReferenceCount(this: v17);
  if ( --autoMutex__.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x00606AA0
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x00606AD0
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v11; // edi
  __int64 v12; // xmm0_8
  float v13; // ecx
  char *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // edx
  float v17; // ecx
  __int64 v18; // xmm0_8
  ICallQueue *v19; // ecx
  IMatRenderContext v20; // eax
  IMesh *v21; // esi
  unsigned int v22; // ecx
  int v23; // edi
  ICallQueue *v24; // eax
  int v25; // xmm1_4
  int *v26; // eax
  int v27; // esi
  int v28; // edx
  int v29; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v32; // eax
  double v33; // st7
  Vector *v34; // eax
  float *m_pCurrNormal; // eax
  float *v36; // eax
  float *v37; // ecx
  float v38; // xmm0_4
  Vector *v39; // eax
  float *v40; // eax
  int v41; // xmm0_4
  float *v42; // eax
  float *v43; // ecx
  float v44; // xmm0_4
  Vector *v45; // eax
  float *v46; // eax
  int v47; // xmm0_4
  float *v48; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v52; // [esp+254h] [ebp-4Ch]
  __int64 v53; // [esp+260h] [ebp-40h]
  __int64 v54; // [esp+26Ch] [ebp-34h]
  float v55; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1, a2);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v11 = vMins->z;
    v52 = *(_QWORD *)&vMaxs->x;
    v53 = *(_QWORD *)&vMins->x;
    v12 = *(_QWORD *)&angles->x;
    v55 = angles->z;
    v13 = vOrigin->z;
    v54 = v12;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v13;
    v14 = (char *)MemAlloc_Alloc(nSize: 0x50u);
    if ( v14 != nullptr )
    {
      v15 = *(_QWORD *)&vecNormal.x;
      v16 = vecNormal.z;
      v17 = v55;
      *((_DWORD *)v14 + 3) = 1;
      *(_QWORD *)(v14 + 20) = v15;
      *((_QWORD *)v14 + 4) = v54;
      *(_QWORD *)(v14 + 44) = v53;
      v18 = v52;
      *((float *)v14 + 10) = v17;
      *((_QWORD *)v14 + 7) = v18;
      *((float *)v14 + 7) = v16;
      *(_DWORD *)v14 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v14 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v14 + 4) = RenderBoxInternal;
      *((float *)v14 + 13) = v11;
      *((float *)v14 + 16) = z;
      *((Color *)v14 + 17) = c;
      *((_DWORD *)v14 + 18) = pMaterial;
      v19 = pCallQueue;
      v14[76] = bInsideOut;
      v19->QueueFunctorInternal(this: v19, a2: (CFunctor *)v14);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v20.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v21 = v20.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v21;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v21;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v21->SetPrimitiveType(this: v21, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v21->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v21, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v22 = 0;
    i = 0;
    v23 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v24 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v25 = (v22 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v22 >> 1)) = v25;
      if ( bInsideOut )
      {
        v26 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v24);
        ppFaceIndices = v26;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
        v26 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
      }
      v27 = 1;
      while ( 1 )
      {
        v28 = v26[v27];
        v29 = v26[v27 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v32 = *v26;
        v33 = p[v32].x;
        v34 = &p[v32];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33;
        i1 = v28;
        m_pCurrPosition[1] = v34->y;
        m_pCurrPosition[2] = v34->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v36[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v37 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v38 = vecNormal.x;
        v39 = &p[v29];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39->x;
        v37[1] = v39->y;
        v37[2] = v39->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v40 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v38;
        v40[1] = vecNormal.y;
        v40[2] = vecNormal.z;
        v41 = v27 == 1 ? 1065353216 : 0;
        v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v42 + 1) = v41;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v44 = vecNormal.x;
        v45 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v45->x;
        v43[1] = v45->y;
        v43[2] = v45->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v44;
        v46[1] = vecNormal.y;
        v46[2] = vecNormal.z;
        v47 = v27 == 1 ? 0 : 1065353216;
        v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v47;
        v48[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v27 >= 3 )
          break;
        v26 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v24 = pCallQueue;
      v22 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00607070
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  RenderBoxInternal(a1: (int)vMins, a2: a1, vOrigin, angles, vMins, vMaxs, c, pMaterial, bInsideOut);
}

//------------------------------------------------------------------------------
// Address: 0x006070A0
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        __int16 bZBuffer,
        bool bInsideOut)
{
  IMaterial *v9; // ecx

  InitializeStandardMaterials(a1, a2);
  v9 = s_pVertexColor;
  if ( (_BYTE)bZBuffer == 0 )
    v9 = s_pVertexColorIgnoreZ;
  RenderBoxInternal(a1: (int)angles, a2, vOrigin, angles, vMins, vMaxs, c, pMaterial: v9, bInsideOut);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005C1040
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x005C1100
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x005C1180
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<ecx>, int a2@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMaterial *v5; // eax
  IMaterial v6; // edx
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMaterial *v9; // eax
  IMaterial v10; // edx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  IMaterial *v13; // eax
  IMaterial v14; // edx
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  IMaterial *v17; // eax
  IMaterial v18; // edx

  if ( (_S1_10 & 1) == 0 )
  {
    _S1_10 |= 1u;
    autoMutex__.m_ownerID = 0;
    autoMutex__.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex__.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex__, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex__, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex__.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex__.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "wireframe");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$vertexcolor", value: 1);
  v5 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v4,
                      a4: a2,
                      a5: a1);
  v6.__vftable = v5->__vftable;
  s_pWireframe = v5;
  v6.IncrementReferenceCount(this: v5);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "wireframe");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
  v9 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v8);
  v10.__vftable = v9->__vftable;
  s_pWireframeIgnoreZ = v9;
  v10.IncrementReferenceCount(this: v9);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "unlitgeneric");
  else
    v12 = nullptr;
  KeyValues::SetInt(this: v12, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v12, keyName: "$vertexalpha", value: 1);
  v13 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v12);
  v14.__vftable = v13->__vftable;
  s_pVertexColor = v13;
  v14.IncrementReferenceCount(this: v13);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "unlitgeneric");
  else
    v16 = nullptr;
  KeyValues::SetInt(this: v16, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$ignorez", value: 1);
  v17 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColorIgnoreZ", a3: v16);
  v18.__vftable = v17->__vftable;
  s_pVertexColorIgnoreZ = v17;
  v18.IncrementReferenceCount(this: v17);
  if ( --autoMutex__.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex__, 0);
}

//------------------------------------------------------------------------------
// Address: 0x005C13C0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x005C13D0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C1400
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x005C1470
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v11; // edi
  __int64 v12; // xmm0_8
  float v13; // ecx
  char *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // edx
  float v17; // ecx
  __int64 v18; // xmm0_8
  ICallQueue *v19; // ecx
  IMatRenderContext v20; // eax
  IMesh *v21; // esi
  unsigned int v22; // ecx
  int v23; // edi
  ICallQueue *v24; // eax
  int v25; // xmm1_4
  int *v26; // eax
  int v27; // esi
  int v28; // edx
  int v29; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v32; // eax
  double v33; // st7
  Vector *v34; // eax
  float *m_pCurrNormal; // eax
  float *v36; // eax
  float *v37; // ecx
  float v38; // xmm0_4
  Vector *v39; // eax
  float *v40; // eax
  int v41; // xmm0_4
  float *v42; // eax
  float *v43; // ecx
  float v44; // xmm0_4
  Vector *v45; // eax
  float *v46; // eax
  int v47; // xmm0_4
  float *v48; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v52; // [esp+254h] [ebp-4Ch]
  __int64 v53; // [esp+260h] [ebp-40h]
  __int64 v54; // [esp+26Ch] [ebp-34h]
  float v55; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1, a2);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v11 = vMins->z;
    v52 = *(_QWORD *)&vMaxs->x;
    v53 = *(_QWORD *)&vMins->x;
    v12 = *(_QWORD *)&angles->x;
    v55 = angles->z;
    v13 = vOrigin->z;
    v54 = v12;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v13;
    v14 = (char *)MemAlloc_Alloc(nSize: 0x50u);
    if ( v14 != nullptr )
    {
      v15 = *(_QWORD *)&vecNormal.x;
      v16 = vecNormal.z;
      v17 = v55;
      *((_DWORD *)v14 + 3) = 1;
      *(_QWORD *)(v14 + 20) = v15;
      *((_QWORD *)v14 + 4) = v54;
      *(_QWORD *)(v14 + 44) = v53;
      v18 = v52;
      *((float *)v14 + 10) = v17;
      *((_QWORD *)v14 + 7) = v18;
      *((float *)v14 + 7) = v16;
      *(_DWORD *)v14 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v14 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v14 + 4) = RenderBoxInternal;
      *((float *)v14 + 13) = v11;
      *((float *)v14 + 16) = z;
      *((Color *)v14 + 17) = c;
      *((_DWORD *)v14 + 18) = pMaterial;
      v19 = pCallQueue;
      v14[76] = bInsideOut;
      v19->QueueFunctorInternal(this: v19, a2: (CFunctor *)v14);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v20.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v21 = v20.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v21;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v21;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v21->SetPrimitiveType(this: v21, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v21->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v21, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v22 = 0;
    i = 0;
    v23 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v24 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset(&vecNormal, 0, sizeof(vecNormal));
      v25 = (v22 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v22 >> 1)) = v25;
      if ( bInsideOut )
      {
        v26 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v24);
        ppFaceIndices = v26;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
        v26 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
      }
      v27 = 1;
      while ( 1 )
      {
        v28 = v26[v27];
        v29 = v26[v27 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v32 = *v26;
        v33 = p[v32].x;
        v34 = &p[v32];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33;
        i1 = v28;
        m_pCurrPosition[1] = v34->y;
        m_pCurrPosition[2] = v34->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v36[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v37 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v38 = vecNormal.x;
        v39 = &p[v29];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39->x;
        v37[1] = v39->y;
        v37[2] = v39->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v40 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v38;
        v40[1] = vecNormal.y;
        v40[2] = vecNormal.z;
        v41 = v27 == 1 ? 1065353216 : 0;
        v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v42 + 1) = v41;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v44 = vecNormal.x;
        v45 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v45->x;
        v43[1] = v45->y;
        v43[2] = v45->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v44;
        v46[1] = vecNormal.y;
        v46[2] = vecNormal.z;
        v47 = v27 == 1 ? 0 : 1065353216;
        v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v47;
        v48[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v27 >= 3 )
          break;
        v26 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v24 = pCallQueue;
      v22 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005C1A10
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        __int16 bZBuffer,
        bool bInsideOut)
{
  IMaterial *v9; // ecx

  InitializeStandardMaterials(a1, a2);
  v9 = s_pVertexColor;
  if ( (_BYTE)bZBuffer == 0 )
    v9 = s_pVertexColorIgnoreZ;
  RenderBoxInternal(a1: (int)angles, a2, vOrigin, angles, vMins, vMaxs, c, pMaterial: v9, bInsideOut);
}

} // namespace studiomdl

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10370A70
// Name: GenerateBoxVertices
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateBoxVertices(const Vector *vOrigin, const Vector *vMins, const Vector *vMaxs, Vector *pVerts)
{
  const QAngle *angles; // ecx
  int v5; // ebx
  float *p_z; // esi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  matrix3x4_t fRotateMatrix; // [esp+Ch] [ebp-3Ch] BYREF
  Vector vecPos; // [esp+3Ch] [ebp-Ch] BYREF

  AngleMatrix(angles, matrix: &fRotateMatrix);
  v5 = 0;
  p_z = &pVerts->z;
  do
  {
    if ( (v5 & 1) != 0 )
      x = vMaxs->x;
    else
      x = vMins->x;
    vecPos.x = x;
    if ( (v5 & 2) != 0 )
      y = vMaxs->y;
    else
      y = vMins->y;
    vecPos.y = y;
    if ( (v5 & 4) != 0 )
      z = vMaxs->z;
    else
      z = vMins->z;
    vecPos.z = z;
    VectorRotate(in1: &vecPos.x, in2: &fRotateMatrix, out: p_z - 2);
    *(p_z - 2) = *(p_z - 2) + vOrigin->x;
    *(p_z - 1) = vOrigin->y + *(p_z - 1);
    *p_z = *p_z + vOrigin->z;
    ++v5;
    p_z += 3;
  }
  while ( v5 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x10370B30
// Name: void InitializeStandardMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeStandardMaterials(int a1@<ecx>, int a2@<esi>)
{
  DWORD CurrentThreadId; // ecx
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMaterial *v5; // eax
  IMaterial v6; // edx
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IMaterial *v9; // eax
  IMaterial v10; // edx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  IMaterial *v13; // eax
  IMaterial v14; // edx
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  IMaterial *v17; // eax
  IMaterial v18; // edx

  if ( (_S1_10 & 1) == 0 )
  {
    _S1_10 |= 1u;
    autoMutex___0.m_ownerID = 0;
    autoMutex___0.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != autoMutex___0.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&autoMutex___0, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &autoMutex___0, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++autoMutex___0.m_depth;
  }
  if ( s_bMaterialsInitialized )
  {
    if ( --autoMutex___0.m_depth != 0 )
      return;
    goto LABEL_23;
  }
  s_bMaterialsInitialized = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "wireframe");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "$vertexcolor", value: 1);
  v5 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int, int))g_pMaterialSystem->CreateMaterial)(
                      a1: g_pMaterialSystem,
                      a2: "__utilWireframe",
                      a3: v4,
                      a4: a2,
                      a5: a1);
  v6.__vftable = v5->__vftable;
  s_pWireframe = v5;
  v6.IncrementReferenceCount(this: v5);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "wireframe");
  else
    v8 = nullptr;
  KeyValues::SetInt(this: v8, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
  v9 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilWireframeIgnoreZ", a3: v8);
  v10.__vftable = v9->__vftable;
  s_pWireframeIgnoreZ = v9;
  v10.IncrementReferenceCount(this: v9);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "unlitgeneric");
  else
    v12 = nullptr;
  KeyValues::SetInt(this: v12, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v12, keyName: "$vertexalpha", value: 1);
  v13 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColor", a3: v12);
  v14.__vftable = v13->__vftable;
  s_pVertexColor = v13;
  v14.IncrementReferenceCount(this: v13);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "unlitgeneric");
  else
    v16 = nullptr;
  KeyValues::SetInt(this: v16, keyName: "$vertexcolor", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$vertexalpha", value: 1);
  KeyValues::SetInt(this: v16, keyName: "$ignorez", value: 1);
  v17 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__utilVertexColorIgnoreZ", a3: v16);
  v18.__vftable = v17->__vftable;
  s_pVertexColorIgnoreZ = v17;
  v18.IncrementReferenceCount(this: v17);
  if ( --autoMutex___0.m_depth == 0 )
LABEL_23:
    _InterlockedExchange((volatile __int32 *)&autoMutex___0, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10370DE0
// Name: public: virtual void CFunctor7<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool),class Vector,class QAngle,class Vector,class Vector,class Color,class IMaterial __near *,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor7<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, IMaterial *, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6,
    a7: this->m_arg7);
}

//------------------------------------------------------------------------------
// Address: 0x10370E10
// Name: void RenderWireframeSphere(class Vector const __near &,float,int,int,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeSphere(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vCenter,
        float flRadius,
        int nTheta,
        int nPhi,
        Color c,
        bool bZBuffer)
{
  IMatRenderContext *v8; // esi
  ICallQueue *v9; // edi
  float z; // ebx
  char *v11; // eax
  __int64 v12; // xmm0_8
  int v13; // edi
  int v14; // esi
  int v15; // ebx
  IMaterial *v16; // eax
  int v17; // ecx
  int v18; // esi
  int v19; // ebx
  __m128 v20; // xmm0
  __m128d v21; // xmm0
  __m128i v22; // xmm0
  double v23; // xmm0_8
  double v24; // xmm0_8
  int v25; // esi
  __m128 v26; // xmm0
  __m128d v27; // xmm0
  __m128i v28; // xmm0
  float *m_pCurrPosition; // edi
  double v30; // xmm0_8
  double v31; // xmm0_8
  signed int m_nCurrentIndex; // ecx
  __int16 v33; // dx
  signed int v34; // ecx
  signed int v35; // ecx
  signed int v36; // ecx
  bool v37; // zf
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-224h] BYREF
  __int64 v41; // [esp+1F4h] [ebp-3Ch]
  unsigned int theta; // [esp+200h] [ebp-30h]
  float v43; // [esp+204h] [ebp-2Ch]
  IMesh *pMesh; // [esp+208h] [ebp-28h]
  float v45; // [esp+20Ch] [ebp-24h]
  float v46; // [esp+210h] [ebp-20h]
  float v47; // [esp+214h] [ebp-1Ch]
  unsigned int phi; // [esp+218h] [ebp-18h]
  CMatRenderContextPtr pRenderContext; // [esp+21Ch] [ebp-14h]
  int i; // [esp+220h] [ebp-10h]
  int v51; // [esp+224h] [ebp-Ch]
  float v52; // [esp+228h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+22Ch] [ebp-4h]
  unsigned __int8 chRed; // [esp+22Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+22Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+22Fh] [ebp-1h]
  int nThetaa; // [esp+240h] [ebp+10h]

  InitializeStandardMaterials(a1, a2);
  v8 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  v9 = v8->GetCallQueue(this: v8);
  if ( v9 != nullptr )
  {
    z = vCenter->z;
    v41 = *(_QWORD *)&vCenter->x;
    v11 = (char *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v11 != nullptr )
    {
      v12 = v41;
      *((_DWORD *)v11 + 3) = 1;
      *(_QWORD *)(v11 + 20) = v12;
      *((_DWORD *)v11 + 10) = nPhi;
      *(_DWORD *)v11 = &CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v11 + 2) = &CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v11 + 4) = RenderWireframeSphere;
      *((float *)v11 + 7) = z;
      *((float *)v11 + 8) = flRadius;
      *((_DWORD *)v11 + 9) = nTheta;
      *((Color *)v11 + 11) = c;
      v11[48] = bZBuffer;
    }
    else
    {
      v11 = nullptr;
    }
    v9->QueueFunctorInternal(this: v9, a2: (CFunctor *)v11);
    v8->EndRender(this: v8);
    v8->Release(this: v8);
  }
  else
  {
    v13 = nPhi;
    v14 = nPhi * (nTheta + 1);
    v15 = (nPhi - 1) * (4 * (nTheta + 1) - 4);
    nThetaa = nTheta + 1;
    v16 = s_pWireframe;
    v51 = nPhi - 1;
    if ( !bZBuffer )
      v16 = s_pWireframeIgnoreZ;
    pRenderContext.m_pObject->Bind(this: pRenderContext.m_pObject, a2: v16, a3: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    pMesh = pRenderContext.m_pObject->GetDynamicMesh(this: pRenderContext.m_pObject, a2: 1, a3: 0, a4: 0, a5: 0);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_LINES,
      nVertexCount: v14,
      nIndexCount: v15,
      pMeshSettings: nullptr);
    chBlue = c._color[2];
    v17 = 0;
    chGreen = c._color[1];
    chRed = c._color[0];
    chAlpha = c._color[3];
    i = 0;
    if ( nPhi <= 0 )
    {
      v18 = nThetaa;
    }
    else
    {
      do
      {
        v18 = nThetaa;
        v19 = 0;
        if ( nThetaa > 0 )
        {
          v43 = (float)(nThetaa - 1);
          v20 = 0;
          v20.m128_f32[0] = (float)v17 / (float)v51;
          v21 = _mm_cvtps_pd(v20);
          v21.m128d_f64[0] = v21.m128d_f64[0] * 3.141592653589793;
          v22 = (__m128i)_mm_cvtpd_ps(v21);
          phi = v22.m128i_i32[0];
          *(double *)v22.m128i_i64 = *(float *)v22.m128i_i32;
          __libm_sse2_cos(X: v22);
          *(float *)&v23 = v23;
          v45 = *(float *)&v23 * flRadius;
          __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)phi));
          *(float *)&v24 = v24;
          v52 = *(float *)&v24 * flRadius;
          v25 = chBlue | ((chGreen | ((chRed | (chAlpha << 8)) << 8)) << 8);
          do
          {
            v26 = 0;
            v26.m128_f32[0] = (float)v19 / v43;
            v27 = _mm_cvtps_pd(v26);
            v27.m128d_f64[0] = v27.m128d_f64[0] * 6.283185307179586;
            v28 = (__m128i)_mm_cvtpd_ps(v27);
            theta = v28.m128i_i32[0];
            *(double *)v28.m128i_i64 = *(float *)v28.m128i_i32;
            __libm_sse2_sin(X: v28);
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *(float *)&v30 = v30;
            v47 = (float)(*(float *)&v30 * v52) + vCenter->y;
            v46 = v45 + vCenter->z;
            __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)theta));
            *(float *)&v31 = v31;
            *m_pCurrPosition = (float)(*(float *)&v31 * v52) + vCenter->x;
            m_pCurrPosition[1] = v47;
            m_pCurrPosition[2] = v46;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v25;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            ++v19;
          }
          while ( v19 < nThetaa );
          v17 = i;
          v13 = nPhi;
          v18 = nThetaa;
        }
        i = ++v17;
      }
      while ( v17 < v13 );
    }
    if ( v51 > 0 )
    {
      m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
      v33 = 0;
      i = 0;
      v52 = *(float *)&v51;
      do
      {
        if ( v18 - 1 > 0 )
        {
          v51 = v18 - 1;
          do
          {
            meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v33
                                                                   + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v34 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v34;
            if ( v34 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v34;
            meshBuilder.m_IndexBuilder.m_pIndices[v34] = v18 + v33 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v35 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v35;
            if ( v35 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v35;
            meshBuilder.m_IndexBuilder.m_pIndices[v35] = v33 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v36 = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v36;
            if ( v36 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v36;
            meshBuilder.m_IndexBuilder.m_pIndices[v36] = v33 + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + 1;
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
            if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            ++v33;
            --v51;
          }
          while ( *(float *)&v51 != 0.0 );
        }
        v33 = v18 + i;
        v37 = LODWORD(v52)-- == 1;
        i += v18;
      }
      while ( !v37 );
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10371320
// Name: void RenderWireframeBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderWireframeBox(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        bool bZBuffer)
{
  IMatRenderContext *v8; // esi
  float z; // edi
  float v10; // ebx
  __int64 v11; // xmm0_8
  float v12; // ecx
  char *v13; // eax
  __int64 v14; // xmm0_8
  float v15; // edx
  float v16; // ecx
  IMaterial *v17; // eax
  IMatRenderContext v18; // edx
  IMesh *v19; // esi
  int v20; // esi
  int *v21; // ebx
  int i; // edi
  float *m_pCurrPosition; // ecx
  Vector *v24; // eax
  int v25; // eax
  float *v26; // ecx
  int v27; // eax
  double x; // st7
  Vector *v29; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  Vector p[8]; // [esp+Ch] [ebp-284h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-224h] BYREF
  __int64 v34; // [esp+254h] [ebp-3Ch]
  __int64 v35; // [esp+260h] [ebp-30h]
  __int64 v36; // [esp+26Ch] [ebp-24h]
  float v37; // [esp+274h] [ebp-1Ch]
  __int64 v38; // [esp+278h] [ebp-18h]
  float v39; // [esp+280h] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+284h] [ebp-Ch]
  IMesh *pMesh; // [esp+288h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+28Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+28Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+28Fh] [ebp-1h]

  InitializeStandardMaterials(a1, a2);
  v8 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  pMesh = (IMesh *)v8->GetCallQueue(this: v8);
  if ( pMesh != nullptr )
  {
    z = vMaxs->z;
    v10 = vMins->z;
    v35 = *(_QWORD *)&vMaxs->x;
    v34 = *(_QWORD *)&vMins->x;
    v11 = *(_QWORD *)&angles->x;
    v37 = angles->z;
    v12 = vOrigin->z;
    v36 = v11;
    v38 = *(_QWORD *)&vOrigin->x;
    v39 = v12;
    v13 = (char *)MemAlloc_Alloc(nSize: 0x4Cu);
    if ( v13 != nullptr )
    {
      v14 = v38;
      v15 = v39;
      v16 = v37;
      *((_DWORD *)v13 + 3) = 1;
      *(_QWORD *)(v13 + 20) = v14;
      *((_QWORD *)v13 + 4) = v36;
      *(_QWORD *)(v13 + 44) = v34;
      *((_QWORD *)v13 + 7) = v35;
      *((float *)v13 + 10) = v16;
      *(_DWORD *)v13 = &CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v13 + 2) = &CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v13 + 4) = RenderWireframeBox;
      *((float *)v13 + 7) = v15;
      *((float *)v13 + 13) = v10;
      *((float *)v13 + 16) = z;
      *((Color *)v13 + 17) = c;
      v13[72] = bZBuffer;
    }
    else
    {
      v13 = nullptr;
    }
    ((void (__thiscall *)(IMesh *, char *))pMesh->VertexCount)(a1: pMesh, a2: v13);
    v8->EndRender(this: v8);
    v8->Release(this: v8);
  }
  else
  {
    v17 = s_pWireframe;
    if ( !bZBuffer )
      v17 = s_pWireframeIgnoreZ;
    v8->Bind(this: v8, a2: v17, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chBlue = c._color[2];
    v18.__vftable = v8->__vftable;
    chGreen = c._color[1];
    chAlpha = c._color[3];
    v19 = v18.GetDynamicMesh(this: v8, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v19;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v19;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v19->SetPrimitiveType(this: v19, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 48, a3: 48, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v19->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 48;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v19, nMaxVertexCount: 48, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v20 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v21 = s_pBoxFaceIndices[0];
    do
    {
      for ( i = 0; i < 4; ++i )
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v24 = &p[v21[i]];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v24->x;
        m_pCurrPosition[1] = v24->y;
        m_pCurrPosition[2] = v24->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v20;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( i == 3 )
          v25 = 0;
        else
          v25 = i + 1;
        v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v27 = v21[v25];
        x = p[v27].x;
        v29 = &p[v27];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
        v26[1] = v29->y;
        v26[2] = v29->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v20;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      }
      v21 += 4;
    }
    while ( (int)v21 < (int)s_pBoxFaceIndicesInsideOut[0] );
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10371740
// Name: void RenderBoxInternal(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBoxInternal(
        int a1@<ecx>,
        int a2@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  IMatRenderContext *m_pObject; // esi
  float z; // ebx
  float v11; // edi
  __int64 v12; // xmm0_8
  float v13; // ecx
  char *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // edx
  float v17; // ecx
  __int64 v18; // xmm0_8
  ICallQueue *v19; // ecx
  IMatRenderContext v20; // eax
  IMesh *v21; // esi
  unsigned int v22; // ecx
  int v23; // edi
  ICallQueue *v24; // eax
  int v25; // xmm1_4
  int *v26; // eax
  int v27; // esi
  int v28; // edx
  int v29; // ebx
  float *m_pCurrPosition; // ecx
  float x; // xmm1_4
  int v32; // eax
  double v33; // st7
  Vector *v34; // eax
  float *m_pCurrNormal; // eax
  float *v36; // eax
  float *v37; // ecx
  float v38; // xmm0_4
  Vector *v39; // eax
  float *v40; // eax
  int v41; // xmm0_4
  float *v42; // eax
  float *v43; // ecx
  float v44; // xmm0_4
  Vector *v45; // eax
  float *v46; // eax
  int v47; // xmm0_4
  float *v48; // eax
  int m_nVertexCount; // eax
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  __int64 v52; // [esp+254h] [ebp-4Ch]
  __int64 v53; // [esp+260h] [ebp-40h]
  __int64 v54; // [esp+26Ch] [ebp-34h]
  float v55; // [esp+274h] [ebp-2Ch]
  CMatRenderContextPtr pRenderContext; // [esp+278h] [ebp-28h]
  int i1; // [esp+27Ch] [ebp-24h]
  IMesh *pMesh; // [esp+280h] [ebp-20h]
  int i; // [esp+284h] [ebp-1Ch]
  int *ppFaceIndices; // [esp+288h] [ebp-18h]
  Vector vecNormal; // [esp+28Ch] [ebp-14h] BYREF
  ICallQueue *pCallQueue; // [esp+298h] [ebp-8h]
  unsigned __int8 chGreen; // [esp+29Dh] [ebp-3h]
  unsigned __int8 chAlpha; // [esp+29Eh] [ebp-2h]
  unsigned __int8 chBlue; // [esp+29Fh] [ebp-1h]

  InitializeStandardMaterials(a1, a2);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    z = vMaxs->z;
    v11 = vMins->z;
    v52 = *(_QWORD *)&vMaxs->x;
    v53 = *(_QWORD *)&vMins->x;
    v12 = *(_QWORD *)&angles->x;
    v55 = angles->z;
    v13 = vOrigin->z;
    v54 = v12;
    *(_QWORD *)&vecNormal.x = *(_QWORD *)&vOrigin->x;
    vecNormal.z = v13;
    v14 = (char *)MemAlloc_Alloc(nSize: 0x50u);
    if ( v14 != nullptr )
    {
      v15 = *(_QWORD *)&vecNormal.x;
      v16 = vecNormal.z;
      v17 = v55;
      *((_DWORD *)v14 + 3) = 1;
      *(_QWORD *)(v14 + 20) = v15;
      *((_QWORD *)v14 + 4) = v54;
      *(_QWORD *)(v14 + 44) = v53;
      v18 = v52;
      *((float *)v14 + 10) = v17;
      *((_QWORD *)v14 + 7) = v18;
      *((float *)v14 + 7) = v16;
      *(_DWORD *)v14 = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      *((_DWORD *)v14 + 2) = &CFunctor7<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,IMaterial *,bool),Vector,QAngle,Vector,Vector,Color,IMaterial *,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      *((_DWORD *)v14 + 4) = RenderBoxInternal;
      *((float *)v14 + 13) = v11;
      *((float *)v14 + 16) = z;
      *((Color *)v14 + 17) = c;
      *((_DWORD *)v14 + 18) = pMaterial;
      v19 = pCallQueue;
      v14[76] = bInsideOut;
      v19->QueueFunctorInternal(this: v19, a2: (CFunctor *)v14);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    m_pObject->Bind(this: m_pObject, a2: pMaterial, a3: nullptr);
    GenerateBoxVertices(vOrigin, vMins, vMaxs, pVerts: p);
    chGreen = c._color[1];
    v20.__vftable = m_pObject->__vftable;
    chBlue = c._color[2];
    chAlpha = c._color[3];
    v21 = v20.GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    pMesh = v21;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v21;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_TRIANGLES;
    v21->SetPrimitiveType(this: v21, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 36, a3: 36, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v21->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 36;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v21, nMaxVertexCount: 36, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v22 = 0;
    i = 0;
    v23 = chBlue | ((chGreen | ((c._color[0] | (chAlpha << 8)) << 8)) << 8);
    v24 = nullptr;
    pCallQueue = nullptr;
    while ( 1 )
    {
      memset((void *)&vecNormal, 0, sizeof(vecNormal));
      v25 = (v22 & 1) != 0 ? 1065353216 : -1082130432;
      *((_DWORD *)&vecNormal.x + (v22 >> 1)) = v25;
      if ( bInsideOut )
      {
        v26 = (int *)((char *)s_pBoxFaceIndicesInsideOut[0] + (_DWORD)v24);
        ppFaceIndices = v26;
      }
      else
      {
        ppFaceIndices = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
        v26 = (int *)((char *)s_pBoxFaceIndices[0] + (_DWORD)v24);
      }
      v27 = 1;
      while ( 1 )
      {
        v28 = v26[v27];
        v29 = v26[v27 + 1];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        x = vecNormal.x;
        v32 = *v26;
        v33 = p[v32].x;
        v34 = &p[v32];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33;
        i1 = v28;
        m_pCurrPosition[1] = v34->y;
        m_pCurrPosition[2] = v34->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = x;
        m_pCurrNormal[1] = vecNormal.y;
        m_pCurrNormal[2] = vecNormal.z;
        v36 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
        v36[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v37 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v38 = vecNormal.x;
        v39 = &p[v29];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v39->x;
        v37[1] = v39->y;
        v37[2] = v39->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v40 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v38;
        v40[1] = vecNormal.y;
        v40[2] = vecNormal.z;
        v41 = v27 == 1 ? 1065353216 : 0;
        v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
        *((_DWORD *)v42 + 1) = v41;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v43 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v44 = vecNormal.x;
        v45 = &p[i1];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v45->x;
        v43[1] = v45->y;
        v43[2] = v45->z;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v23;
        v46 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v44;
        v46[1] = vecNormal.y;
        v46[2] = vecNormal.z;
        v47 = v27 == 1 ? 0 : 1065353216;
        v48 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v47;
        v48[1] = 1.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        if ( ++v27 >= 3 )
          break;
        v26 = ppFaceIndices;
      }
      ++i;
      pCallQueue += 4;
      if ( (int)pCallQueue >= 96 )
        break;
      v24 = pCallQueue;
      v22 = i;
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
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10371CE0
// Name: void RenderBox(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,class IMaterial __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderBox(
        int a1@<esi>,
        const Vector *vOrigin,
        const QAngle *angles,
        const Vector *vMins,
        const Vector *vMaxs,
        Color c,
        IMaterial *pMaterial,
        bool bInsideOut)
{
  RenderBoxInternal(a1: (int)vMins, a2: a1, vOrigin, angles, vMins, vMaxs, c, pMaterial, bInsideOut);
}

} // namespace client
