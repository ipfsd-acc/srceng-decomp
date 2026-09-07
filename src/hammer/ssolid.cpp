// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/ssolid.cpp
// Functions: 44
// ============================================================

#include "hammer\ssolid.h"

//------------------------------------------------------------------------------
// Address: 0x100A8540
// Name: int CheckFace(class Vector __near *,int,class Vector __near *,float,class CCheckFaceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall CheckFace@<eax>(
        int a1@<ebp>,
        Vector *Points,
        int nPoints,
        Vector *pNormal,
        float dist,
        CCheckFaceInfo *pInfo)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  CCheckFaceInfo *v7; // ecx
  Vector *v8; // edx
  Vector *v9; // edi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm6_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v20; // eax
  float *p_x; // edi
  int j; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  Vector *v27; // eax
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm0_4
  int v33; // eax
  float *p_z; // ecx
  float v35; // [esp-Ch] [ebp-48h]
  float v36; // [esp-8h] [ebp-44h]
  Vector v37; // [esp+Ch] [ebp-30h] BYREF
  Vector edgenormal; // [esp+18h] [ebp-24h]
  _EXCEPTION_REGISTRATION_RECORD *v39; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  int v41; // [esp+2Ch] [ebp-10h]
  int v42; // [esp+30h] [ebp-Ch]
  void *v43; // [esp+34h] [ebp-8h]
  int v44; // [esp+38h] [ebp-4h] BYREF
  void *retaddr; // [esp+3Ch] [ebp+0h]

  v42 = a1;
  v43 = retaddr;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v7 = pInfo;
  v41 = -1;
  i = (int)&_ehhandler__CheckFace__YAHPAVVector__H0MPAVCCheckFaceInfo___Z;
  v39 = ExceptionList;
  LODWORD(edgenormal.z) = &v44;
  if ( pInfo == nullptr )
  {
    if ( (_S1_10 & 1) == 0 )
    {
      _S1_10 |= 1u;
      dummyinfo.iPoint = -1;
      v41 = -1;
    }
    pInfo = &dummyinfo;
    v7 = &dummyinfo;
    dummyinfo.iPoint = -1;
  }
  if ( v7->iPoint == -2 )
    return 1;
  v8 = pNormal;
  if ( pNormal != nullptr )
  {
    v9 = Points;
  }
  else
  {
    if ( (_S1_10 & 2) == 0 )
    {
      _S1_10 |= 2u;
      v41 = -1;
    }
    v9 = Points;
    x = Points[1].x;
    y = Points[1].y;
    z = Points[1].z;
    v13 = Points[2].x - x;
    v14 = Points->x - x;
    v35 = x;
    v15 = Points[2].y - y;
    v16 = Points->y - y;
    v36 = y;
    v17 = Points->z - z;
    v18 = Points[2].z - z;
    pNormal = &normal;
    normal.x = (float)(v18 * v16) - (float)(v15 * v17);
    normal.y = (float)(v17 * v13) - (float)(v18 * v14);
    normal.z = (float)(v15 * v14) - (float)(v16 * v13);
    VectorNormalize(vec: &normal);
    v8 = &normal;
    v7 = pInfo;
    dist = (float)((float)(v36 * normal.y) + (float)(normal.x * v35)) + (float)(z * normal.z);
  }
  if ( nPoints == 0 )
  {
    strcpy(v7->szDescription, "no points");
    v7->iPoint = -2;
    return 0;
  }
  if ( nPoints < 3 )
  {
    strcpy(v7->szDescription, "fewer than three points");
    v7->iPoint = -2;
    return 0;
  }
  LODWORD(v20) = v7->iPoint + 1;
  edgenormal.y = v20;
  if ( SLODWORD(v20) >= nPoints )
  {
LABEL_32:
    v7->iPoint = -2;
    return 1;
  }
  LODWORD(edgenormal.x) = LODWORD(v20) + 1;
  p_x = &v9[LODWORD(v20)].x;
  while ( 2 )
  {
    *(float *)&pInfo->iPoint = v20;
    for ( j = 0; j < 3; ++j )
    {
      v23 = p_x[j];
      if ( v23 > 16384.0 || v23 < -16384.0 )
      {
        strcpy(pInfo->szDescription, "out of range");
        return 0;
      }
    }
    v24 = v8->x;
    v25 = p_x[1];
    v26 = (float)((float)((float)(v8->x * *p_x) + (float)(v8->y * v25)) + (float)(p_x[2] * v8->z)) - dist;
    if ( v26 < -0.5 || v26 > 0.5 )
    {
      strcpy(pInfo->szDescription, "point off plane");
      return 0;
    }
    else
    {
      v27 = &Points[nPoints != LODWORD(edgenormal.x) ? LODWORD(edgenormal.x) : 0];
      v28 = v27->x - *p_x;
      v29 = v27->y - v25;
      v30 = v27->z - p_x[2];
      if ( fsqrt((float)((float)(v29 * v29) + (float)(v30 * v30)) + (float)(v28 * v28)) >= 0.1 )
      {
        v31 = v8->y;
        v32 = v8->z;
        v37.x = (float)(v31 * v30) - (float)(v32 * v29);
        v37.y = (float)(v32 * v28) - (float)(v24 * v30);
        v37.z = (float)(v24 * v29) - (float)(v31 * v28);
        VectorNormalize(vec: &v37);
        v33 = 0;
        p_z = &Points->z;
        do
        {
          if ( v33 != LODWORD(edgenormal.y)
            && (float)((float)((float)(*(p_z - 1) * v37.y) + (float)(*(p_z - 2) * v37.x)) + (float)(*p_z * v37.z)) > (float)((float)((float)((float)(p_x[1] * v37.y) + (float)(*p_x * v37.x)) + (float)(p_x[2] * v37.z)) + 0.5) )
          {
            strcpy(pInfo->szDescription, "face is not convex");
            return 0;
          }
          ++v33;
          p_z += 3;
        }
        while ( v33 < nPoints );
        ++LODWORD(edgenormal.x);
        p_x += 3;
        ++LODWORD(edgenormal.y);
        if ( SLODWORD(edgenormal.y) < nPoints )
        {
          v20 = edgenormal.y;
          v8 = pNormal;
          continue;
        }
        v7 = pInfo;
        goto LABEL_32;
      }
      strcpy(pInfo->szDescription, "edge is too small");
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8A80
// Name: public: unsigned long CSSolid::GetConnectionVertex(class CSSEdge __near *,class CSSEdge __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSSolid::GetConnectionVertex(CSSolid *this, CSSEdge *pEdge1, CSSEdge *pEdge2)
{
  unsigned int hvStart; // ecx
  unsigned int result; // eax
  unsigned int hvEnd; // edx

  hvStart = pEdge2->hvStart;
  result = pEdge1->hvStart;
  if ( result != hvStart )
  {
    hvEnd = pEdge2->hvEnd;
    if ( result != hvEnd )
    {
      result = pEdge1->hvEnd;
      if ( result != hvStart && result != hvEnd )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8AB0
// Name: public: class CMapSolid __near * CSSolid::Detach(void)
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__thiscall CSSolid::Detach(CSSolid *this)
{
  CMapSolid *result; // eax

  result = this->m_pMapSolid;
  this->m_pMapSolid = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8AC0
// Name: private: void CSSolid::ShowHandles(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::ShowHandles(CSSolid *this, int bShowVertices, int bShowEdges)
{
  this->m_bShowEdges = bShowEdges;
  this->m_bShowVertices = bShowVertices;
}

//------------------------------------------------------------------------------
// Address: 0x100A8AE0
// Name: public: CSSFace::~CSSFace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSFace::~CSSFace(CSSFace *this)
{
  CEditDispMgr *v2; // eax

  if ( this->m_hDisp != 0xFFFF )
  {
    v2 = EditDispMgr();
    v2->Destroy(this: v2, a2: this->m_hDisp);
    this->m_hDisp = -1;
  }
  this->m_bVisible = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A8B20
// Name: public: CSSEdge::CSSEdge(void)
// Source: json
//------------------------------------------------------------------------------
CSSEdge *__thiscall CSSEdge::CSSEdge(CSSEdge *this)
{
  this->m_bVisible = 0;
  this->m_bSelected = 0;
  this->m_bUse = 1;
  this->Faces[1] = 0;
  this->Faces[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A8B40
// Name: public: CSSEdge::~CSSEdge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSEdge::~CSSEdge(CSSEdge *this)
{
  this->m_bVisible = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A8B50
// Name: public: void CSSEdge::GetCenterPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSEdge::GetCenterPoint(CSSEdge *this, Vector *Point)
{
  *Point = this->ptCenter;
}

//------------------------------------------------------------------------------
// Address: 0x100A8B70
// Name: public: CSSVertex::CSSVertex(void)
// Source: json
//------------------------------------------------------------------------------
CSSVertex *__thiscall CSSVertex::CSSVertex(CSSVertex *this)
{
  this->m_bVisible = 0;
  this->m_bSelected = 0;
  this->m_bUse = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A8B90
// Name: public: CSSVertex::~CSSVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSVertex::~CSSVertex(CSSVertex *this)
{
  *(_QWORD *)&this->pos.y = 0;
  this->pos.x = 0.0;
  this->id = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A8BB0
// Name: public: void CSSVertex::GetPosition(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSVertex::GetPosition(CSSVertex *this, Vector *Position)
{
  *Position = this->pos;
}

//------------------------------------------------------------------------------
// Address: 0x100A8BD0
// Name: public: CSSFace::CSSFace(void)
// Source: json
//------------------------------------------------------------------------------
CSSFace *__thiscall CSSFace::CSSFace(CSSFace *this)
{
  this->m_bVisible = 0;
  this->m_bSelected = 0;
  this->m_bUse = 1;
  this->nEdges = 0;
  this->bModified = 0;
  this->m_nFaceID = 0;
  this->m_hDisp = -1;
  memset(dst: (unsigned __int8 *)&this->texture, value: 0, count: sizeof(this->texture));
  this->texture.scale[0] = g_pGameConfig->m_fDefaultTextureScale;
  this->texture.scale[1] = g_pGameConfig->m_fDefaultTextureScale;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A90B0
// Name: public: CSSolid::CSSolid(void)
// Source: json
//------------------------------------------------------------------------------
CSSolid *__thiscall CSSolid::CSSolid(CSSolid *this)
{
  *(_DWORD *)&this->m_Vertices.nCount = 0;
  this->m_Edges.nBlocks = 0;
  this->m_Edges.nCount = 0;
  this->m_Faces.nBlocks = 0;
  this->m_Faces.nCount = 0;
  this->m_nVertices = 0;
  this->m_nEdges = 0;
  this->m_nFaces = 0;
  this->m_curid = 1;
  this->m_pMapSolid = nullptr;
  this->m_bShowVertices = 1;
  this->m_bShowEdges = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9140
// Name: public: CSSolid::~CSSolid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::~CSSolid(CSSolid *this)
{
  this->m_pMapSolid = nullptr;
  BlockArray<CSSFace,16,10>::GetBlocks(this: &this->m_Faces, nNewBlocks: 0);
  BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: 0);
  BlockArray<CSSVertex,16,32>::GetBlocks(this: &this->m_Vertices, nNewBlocks: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A91B0
// Name: public: int CSSolid::GetHandleInfo(struct SSHANDLEINFO __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSSolid::GetHandleInfo(CSSolid *this, SSHANDLEINFO *pInfo, unsigned int id)
{
  CSSolid *v3; // ebx
  int v4; // esi
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // edi
  unsigned int v6; // ebx
  int v7; // esi
  BlockArray<CSSEdge,16,32> *p_m_Edges; // edi
  unsigned int v9; // ebx
  int v10; // esi
  BlockArray<CSSFace,16,10> *p_m_Faces; // edi
  unsigned int v12; // ebx
  unsigned int v14; // ebx
  int v15; // ebx
  unsigned int v16; // eax
  int v17; // ecx
  unsigned int v18; // esi
  float *p_x; // eax
  double v20; // st7
  unsigned int v21; // ebx
  int v22; // ebx
  unsigned int v23; // eax
  int v24; // ecx
  unsigned int v25; // esi
  double v26; // st7
  int v27; // ebx
  unsigned int v28; // ebx
  int v29; // ebx
  unsigned int v30; // eax
  int v31; // ecx
  unsigned int v32; // esi
  double x; // st7
  int p_ptCenter; // ebx
  __int16 v35; // [esp+Ch] [ebp-8h]
  __int16 v36; // [esp+Ch] [ebp-8h]
  __int16 v37; // [esp+Ch] [ebp-8h]
  CSSVertex **v39; // [esp+10h] [ebp-4h]
  CSSEdge **v40; // [esp+10h] [ebp-4h]
  CSSFace **v41; // [esp+10h] [ebp-4h]
  unsigned int ida; // [esp+20h] [ebp+Ch]
  unsigned int idb; // [esp+20h] [ebp+Ch]
  unsigned int idc; // [esp+20h] [ebp+Ch]

  v3 = this;
  v4 = 0;
  if ( this->m_nVertices <= 0 )
  {
LABEL_14:
    v7 = 0;
    if ( v3->m_nEdges <= 0 )
    {
LABEL_27:
      v10 = 0;
      if ( v3->m_nFaces <= 0 )
      {
LABEL_40:
        pInfo->Type = shtNothing;
        return 0;
      }
      else
      {
        p_m_Faces = &v3->m_Faces;
        while ( 1 )
        {
          if ( v10 >= p_m_Faces->nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v10, p_m_Faces->nCount);
            if ( v10 + 1 != p_m_Faces->nCount )
            {
              v12 = (v10 + 1) / 16;
              if ( (int)(16 * v12) < v10 + 1 )
                ++v12;
              if ( v12 != p_m_Faces->nBlocks )
              {
                if ( v12 > 0xB )
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
                BlockArray<CSSFace,16,10>::GetBlocks(this: p_m_Faces, nNewBlocks: v12);
              }
              v3 = this;
              p_m_Faces->nCount = v10 + 1;
            }
          }
          if ( p_m_Faces->Blocks[v10 / 16][v10 % 16].id == id )
            break;
          if ( ++v10 >= v3->m_nFaces )
            goto LABEL_40;
        }
        pInfo->Type = shtFace;
        pInfo->iIndex = v10;
        if ( v10 >= p_m_Faces->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v10, p_m_Faces->nCount);
          if ( v10 + 1 != p_m_Faces->nCount )
          {
            v28 = (v10 + 1) / 16;
            if ( (int)(16 * v28) < v10 + 1 )
              ++v28;
            if ( v28 != p_m_Faces->nBlocks )
            {
              if ( v28 > 0xB )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
              BlockArray<CSSFace,16,10>::GetBlocks(this: p_m_Faces, nNewBlocks: v28);
            }
            p_m_Faces->nCount = v10 + 1;
          }
        }
        v41 = &p_m_Faces->Blocks[v10 / 16];
        v29 = v10 % 16;
        pInfo->pData = &(*v41)[v29];
        if ( v10 >= p_m_Faces->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v10, p_m_Faces->nCount);
          if ( v10 + 1 != p_m_Faces->nCount )
          {
            v30 = (v10 + 1) / 16;
            idc = v30;
            if ( (int)(16 * v30) < v10 + 1 )
              idc = ++v30;
            if ( v30 != p_m_Faces->nBlocks )
            {
              if ( v30 > 0xB )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
              BlockArray<CSSFace,16,10>::GetBlocks(this: p_m_Faces, nNewBlocks: idc);
            }
            p_m_Faces->nCount = v10 + 1;
          }
        }
        pInfo->p2DHandle = &(*v41)[v29];
        if ( v10 >= p_m_Faces->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v10, p_m_Faces->nCount);
          v31 = v10 + 1;
          v37 = v10 + 1;
          if ( v10 + 1 != p_m_Faces->nCount )
          {
            v32 = v31 / 16;
            if ( 16 * (v31 / 16) < v31 )
              ++v32;
            if ( v32 != p_m_Faces->nBlocks )
            {
              if ( v32 > 0xB )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
              BlockArray<CSSFace,16,10>::GetBlocks(this: p_m_Faces, nNewBlocks: v32);
              LOWORD(v31) = v37;
            }
            p_m_Faces->nCount = v31;
          }
        }
        x = (*v41)[v29].ptCenter.x;
        p_ptCenter = (int)&(*v41)[v29].ptCenter;
        pInfo->pos.x = x;
        pInfo->pos.y = *(float *)(p_ptCenter + 4);
        pInfo->pos.z = *(float *)(p_ptCenter + 8);
        return 1;
      }
    }
    else
    {
      p_m_Edges = &v3->m_Edges;
      while ( 1 )
      {
        if ( v7 >= p_m_Edges->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v7, p_m_Edges->nCount);
          if ( v7 + 1 != p_m_Edges->nCount )
          {
            v9 = (v7 + 1) / 16;
            if ( (int)(16 * v9) < v7 + 1 )
              ++v9;
            if ( v9 != p_m_Edges->nBlocks )
            {
              if ( v9 > 0x21 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
              BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v9);
            }
            v3 = this;
            p_m_Edges->nCount = v7 + 1;
          }
        }
        if ( p_m_Edges->Blocks[v7 / 16][v7 % 16].id == id )
          break;
        if ( ++v7 >= v3->m_nEdges )
          goto LABEL_27;
      }
      pInfo->Type = shtEdge;
      pInfo->iIndex = v7;
      if ( v7 >= p_m_Edges->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v7, p_m_Edges->nCount);
        if ( v7 + 1 != p_m_Edges->nCount )
        {
          v21 = (v7 + 1) / 16;
          if ( (int)(16 * v21) < v7 + 1 )
            ++v21;
          if ( v21 != p_m_Edges->nBlocks )
          {
            if ( v21 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v21);
          }
          p_m_Edges->nCount = v7 + 1;
        }
      }
      v40 = &p_m_Edges->Blocks[v7 / 16];
      v22 = (v7 % 16) << 6;
      pInfo->pData = (char *)*v40 + v22;
      if ( v7 >= p_m_Edges->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v7, p_m_Edges->nCount);
        if ( v7 + 1 != p_m_Edges->nCount )
        {
          v23 = (v7 + 1) / 16;
          idb = v23;
          if ( (int)(16 * v23) < v7 + 1 )
            idb = ++v23;
          if ( v23 != p_m_Edges->nBlocks )
          {
            if ( v23 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: idb);
          }
          p_m_Edges->nCount = v7 + 1;
        }
      }
      pInfo->p2DHandle = (CSSEdge *)((char *)*v40 + v22);
      if ( v7 >= p_m_Edges->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v7, p_m_Edges->nCount);
        v24 = v7 + 1;
        v36 = v7 + 1;
        if ( v7 + 1 != p_m_Edges->nCount )
        {
          v25 = v24 / 16;
          if ( 16 * (v24 / 16) < v24 )
            ++v25;
          if ( v25 != p_m_Edges->nBlocks )
          {
            if ( v25 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v25);
            LOWORD(v24) = v36;
          }
          p_m_Edges->nCount = v24;
        }
      }
      v26 = *(float *)((char *)&(*v40)->ptCenter.x + v22);
      v27 = (int)&(*v40)->ptCenter + v22;
      pInfo->pos.x = v26;
      pInfo->pos.y = *(float *)(v27 + 4);
      pInfo->pos.z = *(float *)(v27 + 8);
      return 1;
    }
  }
  else
  {
    p_m_Vertices = &this->m_Vertices;
    while ( 1 )
    {
      if ( v4 >= p_m_Vertices->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_m_Vertices->nCount);
        if ( v4 + 1 != p_m_Vertices->nCount )
        {
          v6 = (v4 + 1) / 16;
          if ( (int)(16 * v6) < v4 + 1 )
            ++v6;
          if ( v6 != p_m_Vertices->nBlocks )
          {
            if ( v6 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v6);
          }
          v3 = this;
          p_m_Vertices->nCount = v4 + 1;
        }
      }
      if ( p_m_Vertices->Blocks[v4 / 16][v4 % 16].id == id )
        break;
      if ( ++v4 >= v3->m_nVertices )
        goto LABEL_14;
    }
    pInfo->Type = shtVertex;
    pInfo->iIndex = v4;
    if ( v4 >= p_m_Vertices->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_m_Vertices->nCount);
      if ( v4 + 1 != p_m_Vertices->nCount )
      {
        v14 = (v4 + 1) / 16;
        if ( (int)(16 * v14) < v4 + 1 )
          ++v14;
        if ( v14 != p_m_Vertices->nBlocks )
        {
          if ( v14 > 0x21 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
          BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v14);
        }
        p_m_Vertices->nCount = v4 + 1;
      }
    }
    v39 = &p_m_Vertices->Blocks[v4 / 16];
    v15 = v4 % 16;
    pInfo->pData = &(*v39)[v15];
    if ( v4 >= p_m_Vertices->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_m_Vertices->nCount);
      if ( v4 + 1 != p_m_Vertices->nCount )
      {
        v16 = (v4 + 1) / 16;
        ida = v16;
        if ( (int)(16 * v16) < v4 + 1 )
          ida = ++v16;
        if ( v16 != p_m_Vertices->nBlocks )
        {
          if ( v16 > 0x21 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
          BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: ida);
        }
        p_m_Vertices->nCount = v4 + 1;
      }
    }
    pInfo->p2DHandle = &(*v39)[v15];
    if ( v4 >= p_m_Vertices->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_m_Vertices->nCount);
      v17 = v4 + 1;
      v35 = v4 + 1;
      if ( v4 + 1 != p_m_Vertices->nCount )
      {
        v18 = v17 / 16;
        if ( 16 * (v17 / 16) < v17 )
          ++v18;
        if ( v18 != p_m_Vertices->nBlocks )
        {
          if ( v18 > 0x21 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
          BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v18);
          LOWORD(v17) = v35;
        }
        p_m_Vertices->nCount = v17;
      }
    }
    p_x = &(*v39)[v15].pos.x;
    pInfo->pos.x = *p_x;
    pInfo->pos.y = p_x[1];
    v20 = p_x[2];
    pInfo->pos.z = v20;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A99C0
// Name: private: int CSSolid::GetEdgeIndex(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSSolid::GetEdgeIndex(CSSolid *this, unsigned int v1, unsigned int v2)
{
  const char *v3; // esi
  BlockArray<CSSEdge,16,32> *p_m_Edges; // edi
  int v5; // ebx
  unsigned int v6; // edi
  CSSEdge *v7; // eax
  unsigned int hvStart; // edx
  CSSolid *v10; // [esp+10h] [ebp-4h]

  v3 = nullptr;
  v10 = this;
  if ( this->m_nEdges <= 0 )
    return -1;
  p_m_Edges = &this->m_Edges;
  while ( 1 )
  {
    if ( (int)v3 >= p_m_Edges->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v3, p_m_Edges->nCount);
      v5 = (int)(v3 + 1);
      if ( v3 + 1 == (const char *)p_m_Edges->nCount )
      {
        this = v10;
      }
      else
      {
        v6 = v5 / 16;
        if ( 16 * (v5 / 16) < v5 )
          ++v6;
        if ( v6 != v10->m_Edges.nBlocks )
        {
          if ( v6 > 0x21 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
          BlockArray<CSSEdge,16,32>::GetBlocks(this: &v10->m_Edges, nNewBlocks: v6);
        }
        v10->m_Edges.nCount = v5;
        this = v10;
      }
    }
    v7 = &this->m_Edges.Blocks[(int)v3 / 16][(int)v3 % 16];
    p_m_Edges = &this->m_Edges;
    hvStart = v7->hvStart;
    if ( hvStart == v1 && v7->hvEnd == v2 )
      break;
    if ( hvStart == v2 && v7->hvEnd == v1 )
      break;
    if ( (int)++v3 >= this->m_nEdges )
      return -1;
  }
  return (int)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A9AE0
// Name: private: int CSSolid::GetVertexIndex(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSSolid::GetVertexIndex(CSSolid *this, const Vector *Point, float fLeniency)
{
  const char *v3; // esi
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // edi
  int v5; // ebx
  unsigned int v6; // edi
  CSSVertex *v7; // edx
  __int64 Vertex; // [esp+Ch] [ebp-14h]
  float Vertex_8; // [esp+14h] [ebp-Ch]
  CSSolid *v11; // [esp+1Ch] [ebp-4h]
  float fLeniencya; // [esp+2Ch] [ebp+Ch]

  v3 = nullptr;
  v11 = this;
  if ( this->m_nVertices <= 0 )
    return -1;
  p_m_Vertices = &this->m_Vertices;
  fLeniencya = fLeniency * fLeniency;
  while ( 1 )
  {
    if ( (int)v3 >= p_m_Vertices->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v3, p_m_Vertices->nCount);
      v5 = (int)(v3 + 1);
      if ( v3 + 1 == (const char *)p_m_Vertices->nCount )
      {
        this = v11;
      }
      else
      {
        v6 = v5 / 16;
        if ( 16 * (v5 / 16) < v5 )
          ++v6;
        if ( v6 != v11->m_Vertices.nBlocks )
        {
          if ( v6 > 0x21 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
          BlockArray<CSSVertex,16,32>::GetBlocks(this: &v11->m_Vertices, nNewBlocks: v6);
        }
        v11->m_Vertices.nCount = v5;
        this = v11;
      }
    }
    v7 = this->m_Vertices.Blocks[(int)v3 / 16];
    p_m_Vertices = &this->m_Vertices;
    Vertex = *(_QWORD *)&v7[(int)v3 % 16].pos.x;
    Vertex_8 = v7[(int)v3 % 16].pos.z;
    if ( (float)((float)((float)((float)(Point->x - *(float *)&Vertex) * (float)(Point->x - *(float *)&Vertex))
                       + (float)((float)(Point->y - *((float *)&Vertex + 1))
                               * (float)(Point->y - *((float *)&Vertex + 1))))
               + (float)((float)(Point->z - Vertex_8) * (float)(Point->z - Vertex_8))) <= fLeniencya )
      break;
    if ( (int)++v3 >= this->m_nVertices )
      return -1;
  }
  return (int)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A9C30
// Name: private: void CSSolid::CalcEdgeCenter(class CSSEdge __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::CalcEdgeCenter(CSSolid *this, Vector *pEdge)
{
  int iIndex; // edi
  int v5; // edi
  CSSVertex *v6; // ecx
  SSHANDLEINFO hi; // [esp+Ch] [ebp-20h] BYREF
  Vector *pt1; // [esp+34h] [ebp+8h]

  CSSolid::GetHandleInfo(this, pInfo: &hi, id: LODWORD(pEdge[2].z));
  iIndex = hi.iIndex;
  if ( hi.iIndex >= this->m_Vertices.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)hi.iIndex, this->m_Vertices.nCount);
    BlockArray<CSSVertex,16,32>::SetCount(this: &this->m_Vertices, nObjects: iIndex + 1);
  }
  pt1 = &this->m_Vertices.Blocks[iIndex / 16][iIndex % 16].pos;
  CSSolid::GetHandleInfo(this, pInfo: &hi, id: LODWORD(pEdge[3].x));
  v5 = hi.iIndex;
  if ( hi.iIndex >= this->m_Vertices.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)hi.iIndex, this->m_Vertices.nCount);
    BlockArray<CSSVertex,16,32>::SetCount(this: &this->m_Vertices, nObjects: v5 + 1);
  }
  v6 = this->m_Vertices.Blocks[v5 / 16];
  pEdge[3].y = (float)(v6[v5 % 16].pos.x + pt1->x) * 0.5;
  pEdge[3].z = (float)(v6[v5 % 16].pos.y + pt1->y) * 0.5;
  pEdge[4].x = (float)(v6[v5 % 16].pos.z + pt1->z) * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x100A9D50
// Name: public: bool CSSolid::HasDisps(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSSolid::HasDisps(CSSolid *this)
{
  const char *v1; // esi
  BlockArray<CSSFace,16,10> *p_m_Faces; // edi
  int v3; // ebx
  unsigned int v4; // edi
  CSSolid *v6; // [esp+10h] [ebp-4h]

  v1 = nullptr;
  v6 = this;
  if ( this->m_nFaces <= 0 )
    return 0;
  p_m_Faces = &this->m_Faces;
  while ( 1 )
  {
    if ( (int)v1 >= p_m_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v1, p_m_Faces->nCount);
      v3 = (int)(v1 + 1);
      if ( v1 + 1 == (const char *)p_m_Faces->nCount )
      {
        this = v6;
      }
      else
      {
        v4 = v3 / 16;
        if ( 16 * (v3 / 16) < v3 )
          ++v4;
        if ( v4 != v6->m_Faces.nBlocks )
        {
          if ( v4 > 0xB )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
          BlockArray<CSSFace,16,10>::GetBlocks(this: &v6->m_Faces, nNewBlocks: v4);
        }
        v6->m_Faces.nCount = v3;
        this = v6;
      }
    }
    p_m_Faces = &this->m_Faces;
    if ( this->m_Faces.Blocks[(int)v1 / 16][(int)v1 % 16].m_hDisp != 0xFFFF )
      break;
    if ( (int)++v1 >= this->m_nFaces )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A9E50
// Name: public: void CSSolid::DestroyDisps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::DestroyDisps(CSSolid *this)
{
  const char *v1; // edi
  BlockArray<CSSFace,16,10> *p_m_Faces; // esi
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi
  CEditDispMgr *v6; // eax
  CSSolid *i; // [esp+8h] [ebp-4h]

  v1 = nullptr;
  for ( i = this; (int)v1 < i->m_nFaces; ++v1 )
  {
    p_m_Faces = &this->m_Faces;
    if ( (int)v1 >= this->m_Faces.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v1, this->m_Faces.nCount);
      v3 = (int)(v1 + 1);
      if ( v1 + 1 != (const char *)p_m_Faces->nCount )
      {
        v4 = v3 / 16;
        if ( 16 * (v3 / 16) < v3 )
          ++v4;
        if ( v4 != i->m_Faces.nBlocks )
        {
          if ( v4 > 0xB )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
          BlockArray<CSSFace,16,10>::GetBlocks(this: &i->m_Faces, nNewBlocks: v4);
        }
        i->m_Faces.nCount = v3;
      }
    }
    v5 = (int)&i->m_Faces.Blocks[(int)v1 / 16][(int)v1 % 16];
    if ( *(_WORD *)(v5 + 892) != 0xFFFF )
    {
      v6 = EditDispMgr();
      v6->Destroy(this: v6, a2: *(_WORD *)(v5 + 892));
      *(_WORD *)(v5 + 892) = -1;
    }
    this = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9F70
// Name: private: class CSSFace __near * CSSolid::AddFace(int __near *)
// Source: json
//------------------------------------------------------------------------------
CSSFace *__thiscall CSSolid::AddFace(CSSolid *this, int *piNewIndex)
{
  int v3; // esi
  unsigned int v4; // eax
  int v5; // esi
  CSSFace *result; // eax
  unsigned int m_curid; // ecx
  int v8; // [esp+Ch] [ebp-4h]

  v3 = this->m_nFaces + 1;
  this->m_nFaces = v3;
  if ( v3 != this->m_Faces.nCount )
  {
    v4 = v3 / 16;
    v8 = v3 / 16;
    if ( 16 * (v3 / 16) < v3 )
      v8 = ++v4;
    if ( v4 != this->m_Faces.nBlocks )
    {
      if ( v4 > 0xB )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
        v4 = v8;
      }
      BlockArray<CSSFace,16,10>::GetBlocks(this: &this->m_Faces, nNewBlocks: v4);
    }
    this->m_Faces.nCount = v3;
  }
  if ( piNewIndex != nullptr )
    *piNewIndex = this->m_nFaces - 1;
  v5 = this->m_nFaces - 1;
  if ( v5 >= this->m_Faces.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v5, this->m_Faces.nCount);
    BlockArray<CSSFace,16,10>::SetCount(this: &this->m_Faces, nObjects: v5 + 1);
  }
  result = &this->m_Faces.Blocks[v5 / 16][v5 % 16];
  m_curid = this->m_curid;
  this->m_curid = m_curid + 1;
  result->id = m_curid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA070
// Name: private: class CSSEdge __near * CSSolid::AddEdge(int __near *)
// Source: json
//------------------------------------------------------------------------------
CSSEdge *__thiscall CSSolid::AddEdge(CSSolid *this, int *piNewIndex)
{
  int v3; // edi
  CSSEdge *result; // eax
  unsigned int m_curid; // ecx

  BlockArray<CSSEdge,16,32>::SetCount(this: &this->m_Edges, nObjects: ++this->m_nEdges);
  if ( piNewIndex != nullptr )
    *piNewIndex = this->m_nEdges - 1;
  v3 = this->m_nEdges - 1;
  if ( v3 >= this->m_Edges.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, this->m_Edges.nCount);
    BlockArray<CSSEdge,16,32>::SetCount(this: &this->m_Edges, nObjects: v3 + 1);
  }
  result = &this->m_Edges.Blocks[v3 / 16][v3 % 16];
  m_curid = this->m_curid;
  this->m_curid = m_curid + 1;
  result->id = m_curid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA110
// Name: private: class CSSVertex __near * CSSolid::AddVertex(int __near *)
// Source: json
//------------------------------------------------------------------------------
CSSVertex *__thiscall CSSolid::AddVertex(CSSolid *this, int *piNewIndex)
{
  int v3; // edi
  CSSVertex *result; // eax
  unsigned int m_curid; // ecx

  BlockArray<CSSVertex,16,32>::SetCount(this: &this->m_Vertices, nObjects: ++this->m_nVertices);
  if ( piNewIndex != nullptr )
    *piNewIndex = this->m_nVertices - 1;
  v3 = this->m_nVertices - 1;
  if ( v3 >= this->m_Vertices.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, this->m_Vertices.nCount);
    BlockArray<CSSVertex,16,32>::SetCount(this: &this->m_Vertices, nObjects: v3 + 1);
  }
  result = &this->m_Vertices.Blocks[v3 / 16][v3 % 16];
  m_curid = this->m_curid;
  this->m_curid = m_curid + 1;
  result->id = m_curid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA1A0
// Name: private: void CSSolid::FromMapSolid(class CMapSolid __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::FromMapSolid(CSSolid *this, CMapSolid *p, bool bSkipDisplacementFaces)
{
  CMapSolid *m_pMapSolid; // eax
  int v4; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v6; // ebx
  unsigned int v7; // esi
  unsigned int v8; // ebx
  CSSFace *v9; // eax
  CEditDispMgr *v10; // eax
  CEditDispMgr *v11; // eax
  CMapDisp *v12; // esi
  CEditDispMgr *v13; // eax
  CMapDisp *v14; // eax
  int v15; // ecx
  int v16; // eax
  CSSolid *v17; // edi
  const Vector *v18; // ebx
  CSSFace *VertexIndex; // esi
  CSSVertex *v20; // eax
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // ebx
  int v22; // ecx
  unsigned int v23; // edi
  CSSFace *id; // ebx
  const char *EdgeIndex; // esi
  CSSEdge *v26; // esi
  BlockArray<CSSEdge,16,32> *p_m_Edges; // ebx
  int v28; // ecx
  unsigned int v29; // edi
  int nCount; // [esp+10h] [ebp-28h]
  int fLeniency; // [esp+14h] [ebp-24h]
  int v32; // [esp+18h] [ebp-20h]
  CSSFace *v33; // [esp+1Ch] [ebp-1Ch]
  CSSFace *v34; // [esp+20h] [ebp-18h]
  int nSolidFaces; // [esp+24h] [ebp-14h]
  int nFacePoints; // [esp+28h] [ebp-10h]
  Vector *pFacePoints; // [esp+2Ch] [ebp-Ch]
  CSSFace *pFace; // [esp+30h] [ebp-8h] BYREF
  unsigned int hFirstVertex; // [esp+34h] [ebp-4h]
  BlockArray<CMapFace,6,86> *hLastVertex; // [esp+40h] [ebp+8h]

  m_pMapSolid = p;
  v4 = 0;
  hFirstVertex = (unsigned int)this;
  if ( p == nullptr )
    m_pMapSolid = this->m_pMapSolid;
  this->m_nFaces = 0;
  this->m_nEdges = 0;
  this->m_nVertices = 0;
  nCount = m_pMapSolid->Faces.nCount;
  nSolidFaces = 0;
  if ( nCount > 0 )
  {
    p_Faces = &m_pMapSolid->Faces;
    for ( hLastVertex = &m_pMapSolid->Faces; ; p_Faces = hLastVertex )
    {
      if ( v4 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_Faces->nCount);
        v6 = v4 + 1;
        if ( v4 + 1 != p_Faces->nCount )
        {
          v7 = v6 / 6;
          if ( 6 * (v6 / 6) < v6 )
            ++v7;
          if ( v7 != hLastVertex->nBlocks )
          {
            if ( v7 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: hLastVertex, nNewBlocks: v7);
          }
          hLastVertex->nCount = v6;
        }
      }
      v8 = (unsigned int)&hLastVertex->Blocks[v4 / 6u][v4 % 6u];
      if ( !bSkipDisplacementFaces || *(_WORD *)(v8 + 420) == 0xFFFF )
      {
        v9 = CSSolid::AddFace(this: (CSSolid *)hFirstVertex, piNewIndex: nullptr);
        qmemcpy(v9->PlanePts, (const void *)(v8 + 364), sizeof(v9->PlanePts));
        qmemcpy(&v9->texture, (const void *)(v8 + 20), sizeof(v9->texture));
        v9->normal = *(Vector *)(v8 + 348);
        v9->m_nFaceID = *(_DWORD *)(v8 + 412);
        v33 = v9;
        if ( *(_WORD *)(v8 + 420) != 0xFFFF )
        {
          v10 = EditDispMgr();
          v33->m_hDisp = v10->Create(this: v10);
          v11 = EditDispMgr();
          v12 = v11->GetDisp(this: v11, a2: v33->m_hDisp);
          v13 = EditDispMgr();
          v14 = v13->GetDisp(this: v13, a2: *(_WORD *)(v8 + 420));
          CMapDisp::CopyFrom(this: v12, pMapDisp: v14, bUpdateDependencies: false);
        }
        v15 = *(_DWORD *)(v8 + 344);
        v16 = 0;
        fLeniency = v15;
        v32 = *(_DWORD *)(v8 + 340);
        pFacePoints = nullptr;
        v34 = nullptr;
        for ( nFacePoints = 0; v16 <= fLeniency; nFacePoints = v16 )
        {
          v17 = (CSSolid *)hFirstVertex;
          if ( v16 >= v15 )
          {
            pFace = v34;
            id = v34;
          }
          else
          {
            v18 = (const Vector *)(v32 + 12 * v16);
            VertexIndex = (CSSFace *)CSSolid::GetVertexIndex(this: (CSSolid *)hFirstVertex, Point: v18, fLeniency: 0.1);
            pFace = VertexIndex;
            if ( VertexIndex == (CSSFace *)-1 )
            {
              v20 = CSSolid::AddVertex(this: v17, piNewIndex: (int *)&pFace);
              VertexIndex = pFace;
              v20->pos = *v18;
            }
            p_m_Vertices = &v17->m_Vertices;
            if ( (int)VertexIndex >= v17->m_Vertices.nCount )
            {
              _Error(
                this: (ISceneTokenProcessor *)&stru_105DC45C,
                a2: (const char *)VertexIndex,
                v17->m_Vertices.nCount);
              v22 = (int)&VertexIndex->m_bVisible + 1;
              if ( (int *)((char *)&VertexIndex->m_bVisible + 1) != (int *)v17->m_Vertices.nCount )
              {
                v23 = v22 / 16;
                if ( 16 * (v22 / 16) < v22 )
                  ++v23;
                if ( v23 != p_m_Vertices->nBlocks )
                {
                  if ( v23 > 0x21 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                  BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v23);
                }
                v17 = (CSSolid *)hFirstVertex;
                p_m_Vertices->nCount = (_WORD)VertexIndex + 1;
              }
            }
            id = (CSSFace *)p_m_Vertices->Blocks[(int)VertexIndex / 16][(int)VertexIndex % 16].id;
            pFace = id;
            if ( nFacePoints == 0 )
              v34 = id;
          }
          if ( pFacePoints != nullptr )
          {
            EdgeIndex = (const char *)CSSolid::GetEdgeIndex(
                                        this: v17,
                                        v1: (unsigned int)pFacePoints,
                                        v2: (unsigned int)id);
            if ( EdgeIndex == (const char *)-1 )
            {
              v26 = CSSolid::AddEdge(this: v17, piNewIndex: (int *)&pFace);
              v26->hvStart = (unsigned int)pFacePoints;
              v26->hvEnd = (unsigned int)id;
              CSSolid::CalcEdgeCenter(this: v17, pEdge: (Vector *)v26);
            }
            else
            {
              p_m_Edges = &v17->m_Edges;
              if ( (int)EdgeIndex >= v17->m_Edges.nCount )
              {
                _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: EdgeIndex, v17->m_Edges.nCount);
                v28 = (int)(EdgeIndex + 1);
                if ( EdgeIndex + 1 != (const char *)v17->m_Edges.nCount )
                {
                  v29 = v28 / 16;
                  if ( 16 * (v28 / 16) < v28 )
                    ++v29;
                  if ( v29 != p_m_Edges->nBlocks )
                  {
                    if ( v29 > 0x21 )
                      _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                    BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v29);
                  }
                  p_m_Edges->nCount = (_WORD)EdgeIndex + 1;
                }
              }
              v26 = &p_m_Edges->Blocks[(int)EdgeIndex / 16][(int)EdgeIndex % 16];
              id = pFace;
            }
            v33->Edges[v33->nEdges++] = v26->id;
            if ( v26->Faces[0] != 0 )
            {
              if ( v26->Faces[1] != 0 )
              {
                v26->Faces[0] = v33->id;
                AfxMessageBox(lpszText: "Edge with both face id's already filled, skipping...", nType: 0, nIDHelp: 0);
              }
              else
              {
                v26->Faces[1] = v33->id;
              }
            }
            else
            {
              v26->Faces[0] = v33->id;
            }
          }
          v15 = fLeniency;
          v16 = nFacePoints + 1;
          pFacePoints = (Vector *)id;
        }
        v4 = nSolidFaces;
      }
      nSolidFaces = ++v4;
      if ( v4 >= nCount )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA620
// Name: private: class CSSEdge __near * __near * CSSolid::FindAffectedEdges(unsigned long __near *,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
CSSEdge **__thiscall CSSolid::FindAffectedEdges(
        CSSolid *this,
        unsigned int *pHandles,
        unsigned int *iNumHandles,
        int *iNumEdges)
{
  int *v5; // ebx
  CSSolid *v6; // esi
  const char *i; // edi
  int v8; // ebx
  unsigned int v9; // esi
  CSSEdge *v10; // eax
  int v11; // edx
  int j; // ecx
  unsigned int *pHandlesa; // [esp+18h] [ebp+8h]

  v5 = iNumEdges;
  v6 = this;
  *iNumEdges = 0;
  if ( (int)iNumHandles > 0 )
  {
    pHandlesa = iNumHandles;
    do
    {
      for ( i = nullptr; (int)i < v6->m_nEdges; ++i )
      {
        if ( (int)i >= v6->m_Edges.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: i, v6->m_Edges.nCount);
          v8 = (int)(i + 1);
          if ( i + 1 != (const char *)v6->m_Edges.nCount )
          {
            v9 = v8 / 16;
            if ( 16 * (v8 / 16) < v8 )
              ++v9;
            if ( v9 != this->m_Edges.nBlocks )
            {
              if ( v9 > 0x21 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
              BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: v9);
            }
            this->m_Edges.nCount = v8;
            v6 = this;
          }
          v5 = iNumEdges;
        }
        v10 = &v6->m_Edges.Blocks[(int)i / 16][(int)i % 16];
        if ( v10->hvStart == *pHandles || v10->hvEnd == *pHandles )
        {
          v11 = *v5;
          for ( j = 0; j < v11; ++j )
          {
            if ( ppEdges[j] == v10 )
              break;
          }
          if ( j == v11 )
          {
            ppEdges[v11] = v10;
            ++*v5;
          }
        }
      }
      ++pHandles;
      pHandlesa = (unsigned int *)((char *)pHandlesa - 1);
    }
    while ( pHandlesa != nullptr );
  }
  return ppEdges;
}

//------------------------------------------------------------------------------
// Address: 0x100AA770
// Name: private: void CSSolid::SetVertexPosition(int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::SetVertexPosition(CSSolid *this, int iVertex, float x, float y, float z)
{
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // edi
  float *p_x; // eax

  p_m_Vertices = &this->m_Vertices;
  if ( iVertex >= this->m_Vertices.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)iVertex, this->m_Vertices.nCount);
    BlockArray<CSSVertex,16,32>::SetCount(this: p_m_Vertices, nObjects: iVertex + 1);
  }
  p_x = &p_m_Vertices->Blocks[iVertex / 16][iVertex % 16].pos.x;
  *p_x = x;
  p_x[1] = y;
  p_x[2] = z;
}

//------------------------------------------------------------------------------
// Address: 0x100AA7F0
// Name: private: void CSSolid::DeleteEdge(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::DeleteEdge(CSSolid *this, int iEdge)
{
  CSSolid *v2; // esi
  int nCount; // eax
  BlockArray<CSSEdge,16,32> *p_m_Edges; // ebx
  const char *v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  unsigned int v9; // eax
  CSSEdge *v10; // esi
  __int16 v11; // cx
  unsigned int v12; // eax
  int v13; // edi
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ebx
  BlockArray<CSSFace,16,10> *p_m_Faces; // edi
  int v18; // ecx
  unsigned int v19; // esi
  int v20; // esi
  int v21; // eax
  int v22; // ecx
  _DWORD *v23; // edx
  unsigned int edgeid; // [esp+Ch] [ebp-Ch]
  int nNewBlocks; // [esp+10h] [ebp-8h]
  int nNewBlocksa; // [esp+10h] [ebp-8h]
  int iEdgea; // [esp+20h] [ebp+8h]
  int iEdgeb; // [esp+20h] [ebp+8h]
  int iEdgec; // [esp+20h] [ebp+8h]

  v2 = this;
  nCount = this->m_Edges.nCount;
  p_m_Edges = &this->m_Edges;
  v5 = (const char *)iEdge;
  if ( iEdge >= nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)iEdge, nCount);
    BlockArray<CSSEdge,16,32>::SetCount(this: p_m_Edges, nObjects: iEdge + 1);
  }
  edgeid = p_m_Edges->Blocks[iEdge / 16][iEdge % 16].id;
  if ( iEdge < v2->m_nEdges - 1 )
  {
    do
    {
      v6 = p_m_Edges->nCount;
      v7 = (int)(v5 + 1);
      iEdgea = (int)(v5 + 1);
      if ( (int)(v5 + 1) >= v6 )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v5 + 1, v6);
        v8 = (int)(v5 + 2);
        if ( v5 + 2 != (const char *)p_m_Edges->nCount )
        {
          v9 = v8 / 16;
          nNewBlocks = v8 / 16;
          if ( 16 * (v8 / 16) < v8 )
            nNewBlocks = ++v9;
          if ( v9 != p_m_Edges->nBlocks )
          {
            if ( v9 > 0x21 )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
              v9 = nNewBlocks;
            }
            BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v9);
          }
          p_m_Edges->nCount = (_WORD)v5 + 2;
        }
      }
      nNewBlocksa = v7 / 16;
      v10 = &p_m_Edges->Blocks[v7 / 16][v7 % 16];
      if ( (int)v5 >= p_m_Edges->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v5, p_m_Edges->nCount);
        v11 = (_WORD)v5 + 1;
        if ( iEdgea != p_m_Edges->nCount )
        {
          v12 = nNewBlocksa;
          if ( 16 * nNewBlocksa < iEdgea )
            v12 = ++nNewBlocksa;
          if ( v12 != p_m_Edges->nBlocks )
          {
            if ( v12 > 0x21 )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
              v12 = nNewBlocksa;
            }
            BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v12);
            v11 = (_WORD)v5 + 1;
          }
          p_m_Edges->nCount = v11;
        }
      }
      qmemcpy(
        &p_m_Edges->Blocks[(int)v5 / 16][(int)v5 % 16],
        v10,
        sizeof(p_m_Edges->Blocks[(int)v5 / 16][(int)v5 % 16]));
      ++v5;
    }
    while ( iEdgea < this->m_nEdges - 1 );
    v2 = this;
  }
  v13 = --v2->m_nEdges;
  if ( v13 >= p_m_Edges->nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v13, p_m_Edges->nCount);
    v14 = v13 + 1;
    if ( v13 + 1 != p_m_Edges->nCount )
    {
      v15 = v14 / 16;
      iEdgeb = v14 / 16;
      if ( 16 * (v14 / 16) < v14 )
        iEdgeb = ++v15;
      if ( v15 != p_m_Edges->nBlocks )
      {
        if ( v15 > 0x21 )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
          v15 = iEdgeb;
        }
        BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v15);
      }
      p_m_Edges->nCount = v13 + 1;
    }
  }
  memset(
    dst: (unsigned __int8 *)&p_m_Edges->Blocks[v13 / 16][v13 % 16],
    value: 0,
    count: sizeof(p_m_Edges->Blocks[v13 / 16][v13 % 16]));
  v16 = 0;
  if ( v2->m_nFaces > 0 )
  {
    p_m_Faces = &v2->m_Faces;
    iEdgec = (int)&v2->m_Faces;
    do
    {
      if ( v16 >= p_m_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v16, p_m_Faces->nCount);
        v18 = v16 + 1;
        if ( v16 + 1 != p_m_Faces->nCount )
        {
          v19 = v18 / 16;
          if ( 16 * (v18 / 16) < v18 )
            ++v19;
          if ( v19 != p_m_Faces->nBlocks )
          {
            if ( v19 > 0xB )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
            BlockArray<CSSFace,16,10>::GetBlocks(this: p_m_Faces, nNewBlocks: v19);
          }
          p_m_Faces->nCount = v16 + 1;
        }
      }
      v20 = (int)&p_m_Faces->Blocks[v16 / 16][v16 % 16];
      v21 = 0;
      v22 = *(_DWORD *)(v20 + 512);
      if ( v22 > 0 )
      {
        v23 = (_DWORD *)(v20 + 32);
        while ( *v23 != edgeid )
        {
          ++v21;
          ++v23;
          if ( v21 >= v22 )
            goto LABEL_50;
        }
        memcpy(
          dst: (unsigned __int8 *)(v20 + 4 * v21 + 32),
          src: (unsigned __int8 *)(v20 + 4 * v21 + 36),
          count: 4 * (v22 - v21));
        --*(_DWORD *)(v20 + 512);
LABEL_50:
        p_m_Faces = (BlockArray<CSSFace,16,10> *)iEdgec;
      }
      ++v16;
    }
    while ( v16 < this->m_nFaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AAB70
// Name: private: void CSSolid::DeleteVertex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::DeleteVertex(CSSolid *this, const char *iVertex)
{
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // edi
  int v3; // ebx
  int v4; // ecx
  unsigned int v5; // esi
  const char *v6; // ecx
  CSSVertex *v7; // esi
  unsigned int v8; // eax
  CSSVertex *v9; // eax
  int v10; // ecx
  CSSVertex *v11; // eax
  int v12; // esi
  BlockArray<CSSVertex,16,32> *v13; // edi
  int v14; // ecx
  unsigned int v15; // ebx
  CSSolid *v16; // [esp+Ch] [ebp-8h]
  int nNewBlocks; // [esp+10h] [ebp-4h]

  v16 = this;
  if ( (int)iVertex < this->m_nVertices - 1 )
  {
    p_m_Vertices = &this->m_Vertices;
    do
    {
      v3 = (int)(iVertex + 1);
      if ( (int)(iVertex + 1) >= p_m_Vertices->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: iVertex + 1, p_m_Vertices->nCount);
        v4 = (int)(iVertex + 2);
        if ( iVertex + 2 != (const char *)p_m_Vertices->nCount )
        {
          v5 = v4 / 16;
          if ( 16 * (v4 / 16) < v4 )
            ++v5;
          if ( v5 != p_m_Vertices->nBlocks )
          {
            if ( v5 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v5);
          }
          p_m_Vertices->nCount = (_WORD)iVertex + 2;
        }
      }
      nNewBlocks = v3 / 16;
      v6 = iVertex;
      v7 = &p_m_Vertices->Blocks[v3 / 16][v3 % 16];
      if ( (int)iVertex >= p_m_Vertices->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: iVertex, p_m_Vertices->nCount);
        if ( v3 != p_m_Vertices->nCount )
        {
          v8 = v3 / 16;
          if ( 16 * nNewBlocks < v3 )
            v8 = ++nNewBlocks;
          if ( v8 != p_m_Vertices->nBlocks )
          {
            if ( v8 > 0x21 )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
              v8 = nNewBlocks;
            }
            BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v8);
          }
          p_m_Vertices->nCount = v3;
        }
        v6 = iVertex;
      }
      v9 = p_m_Vertices->Blocks[(int)v6 / 16];
      v10 = (int)v6 % 16;
      *(_QWORD *)&v9[v10].m_bVisible = *(_QWORD *)&v7->m_bVisible;
      v11 = &v9[v10];
      *(_QWORD *)&v11->m_bUse = *(_QWORD *)&v7->m_bUse;
      *(_QWORD *)&v11->m_r.left = *(_QWORD *)&v7->m_r.left;
      *(_QWORD *)&v11->m_r.right = *(_QWORD *)&v7->m_r.right;
      *(_QWORD *)&v11->pos.x = *(_QWORD *)&v7->pos.x;
      *(_QWORD *)&v11->pos.z = *(_QWORD *)&v7->pos.z;
      ++iVertex;
    }
    while ( v3 < v16->m_nVertices - 1 );
    this = v16;
  }
  v12 = --this->m_nVertices;
  v13 = &this->m_Vertices;
  if ( v12 >= this->m_Vertices.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v12, this->m_Vertices.nCount);
    v14 = v12 + 1;
    if ( v12 + 1 != v13->nCount )
    {
      v15 = v14 / 16;
      if ( 16 * (v14 / 16) < v14 )
        ++v15;
      if ( v15 != v13->nBlocks )
      {
        if ( v15 > 0x21 )
          _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
        BlockArray<CSSVertex,16,32>::GetBlocks(this: v13, nNewBlocks: v15);
      }
      v13->nCount = v12 + 1;
    }
  }
  memset(
    dst: (unsigned __int8 *)&v13->Blocks[v12 / 16][v12 % 16],
    value: 0,
    count: sizeof(v13->Blocks[v12 / 16][v12 % 16]));
}

//------------------------------------------------------------------------------
// Address: 0x100AADD0
// Name: private: void CSSolid::DeleteFace(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::DeleteFace(CSSolid *this, int iFace)
{
  int nCount; // eax
  BlockArray<CSSFace,16,10> *p_m_Faces; // ebx
  int v4; // edi
  CEditDispMgr *v5; // eax
  CSSolid *v6; // eax
  const char *v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  unsigned int v11; // eax
  CSSFace *v12; // esi
  __int16 v13; // cx
  unsigned int v14; // eax
  int v15; // esi
  int v16; // ecx
  unsigned int v17; // edi
  int v18; // esi
  int nNewBlocks; // [esp+Ch] [ebp-8h]
  int nNewBlocksa; // [esp+Ch] [ebp-8h]
  int iFacea; // [esp+1Ch] [ebp+8h]

  nCount = this->m_Faces.nCount;
  p_m_Faces = &this->m_Faces;
  if ( iFace >= nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)iFace, nCount);
    BlockArray<CSSFace,16,10>::SetCount(this: p_m_Faces, nObjects: iFace + 1);
  }
  v4 = (int)&p_m_Faces->Blocks[iFace / 16][iFace % 16];
  if ( v4 != 0 && *(_WORD *)(v4 + 892) != 0xFFFF )
  {
    v5 = EditDispMgr();
    v5->Destroy(this: v5, a2: *(_WORD *)(v4 + 892));
    *(_WORD *)(v4 + 892) = -1;
  }
  v6 = this;
  v7 = (const char *)iFace;
  if ( iFace < this->m_nFaces - 1 )
  {
    do
    {
      v8 = p_m_Faces->nCount;
      v9 = (int)(v7 + 1);
      iFacea = (int)(v7 + 1);
      if ( (int)(v7 + 1) >= v8 )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v7 + 1, v8);
        v10 = (int)(v7 + 2);
        if ( v7 + 2 != (const char *)p_m_Faces->nCount )
        {
          v11 = v10 / 16;
          nNewBlocks = v10 / 16;
          if ( 16 * (v10 / 16) < v10 )
            nNewBlocks = ++v11;
          if ( v11 != p_m_Faces->nBlocks )
          {
            if ( v11 > 0xB )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
              v11 = nNewBlocks;
            }
            BlockArray<CSSFace,16,10>::GetBlocks(this: p_m_Faces, nNewBlocks: v11);
          }
          p_m_Faces->nCount = (_WORD)v7 + 2;
        }
      }
      nNewBlocksa = v9 / 16;
      v12 = &p_m_Faces->Blocks[v9 / 16][v9 % 16];
      if ( (int)v7 >= p_m_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v7, p_m_Faces->nCount);
        v13 = (_WORD)v7 + 1;
        if ( iFacea != p_m_Faces->nCount )
        {
          v14 = nNewBlocksa;
          if ( 16 * nNewBlocksa < iFacea )
            v14 = ++nNewBlocksa;
          if ( v14 != p_m_Faces->nBlocks )
          {
            if ( v14 > 0xB )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
              v14 = nNewBlocksa;
            }
            BlockArray<CSSFace,16,10>::GetBlocks(this: p_m_Faces, nNewBlocks: v14);
            v13 = (_WORD)v7 + 1;
          }
          p_m_Faces->nCount = v13;
        }
      }
      qmemcpy(
        &p_m_Faces->Blocks[(int)v7 / 16][(int)v7 % 16],
        v12,
        sizeof(p_m_Faces->Blocks[(int)v7 / 16][(int)v7 % 16]));
      ++v7;
    }
    while ( iFacea < this->m_nFaces - 1 );
    v6 = this;
  }
  v15 = --v6->m_nFaces;
  if ( v15 >= p_m_Faces->nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v15, p_m_Faces->nCount);
    v16 = v15 + 1;
    if ( v15 + 1 != p_m_Faces->nCount )
    {
      v17 = v16 / 16;
      if ( 16 * (v16 / 16) < v16 )
        ++v17;
      if ( v17 != p_m_Faces->nBlocks )
      {
        if ( v17 > 0xB )
          _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
        BlockArray<CSSFace,16,10>::GetBlocks(this: p_m_Faces, nNewBlocks: v17);
      }
      p_m_Faces->nCount = v15 + 1;
    }
  }
  v18 = (int)&p_m_Faces->Blocks[v15 / 16][v15 % 16];
  *(_DWORD *)(v18 + 512) = 0;
  *(_DWORD *)(v18 + 516) = 0;
  *(_DWORD *)(v18 + 888) = 0;
  *(_WORD *)(v18 + 892) = -1;
  memset(dst: (unsigned __int8 *)(v18 + 568), value: 0, count: 0x140u);
  *(float *)(v18 + 864) = g_pGameConfig->m_fDefaultTextureScale;
  *(float *)(v18 + 868) = g_pGameConfig->m_fDefaultTextureScale;
}

//------------------------------------------------------------------------------
// Address: 0x100AB0B0
// Name: private: int CSSolid::CanMergeVertices(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSSolid::CanMergeVertices(CSSolid *this)
{
  int m_nVertices; // eax
  const char *edx1; // edx
  int v3; // ebx
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // esi
  int v5; // ecx
  unsigned int v6; // edi
  float *p_m_bVisible; // edi
  const char *v8; // ecx
  int v9; // ecx
  unsigned int v10; // ebx
  int v11; // eax
  CSSVertex *v12; // ecx
  bool v13; // zf
  int v14; // ecx
  CSSolid *v16; // [esp+10h] [ebp-Ch]
  int v2; // [esp+14h] [ebp-8h]
  const char *v1; // [esp+18h] [ebp-4h]

  m_nVertices = this->m_nVertices;
  edx1 = nullptr;
  v16 = this;
  v1 = nullptr;
  if ( m_nVertices <= 0 )
    return 0;
  while ( 1 )
  {
    v3 = 0;
    v2 = 0;
    if ( m_nVertices > 0 )
      break;
LABEL_28:
    m_nVertices = this->m_nVertices;
    v1 = ++edx1;
    if ( (int)edx1 >= m_nVertices )
      return 0;
  }
  while ( edx1 == (const char *)v3 )
  {
LABEL_27:
    v2 = ++v3;
    if ( v3 >= this->m_nVertices )
      goto LABEL_28;
  }
  p_m_Vertices = &this->m_Vertices;
  if ( v3 >= this->m_Vertices.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, this->m_Vertices.nCount);
    v5 = v3 + 1;
    if ( v3 + 1 != p_m_Vertices->nCount )
    {
      v6 = v5 / 16;
      if ( 16 * (v5 / 16) < v5 )
        ++v6;
      if ( v6 != p_m_Vertices->nBlocks )
      {
        if ( v6 > 0x21 )
          _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
        BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v6);
      }
      p_m_Vertices->nCount = v3 + 1;
    }
  }
  p_m_bVisible = (float *)&p_m_Vertices->Blocks[v3 / 16][v3 % 16].m_bVisible;
  v8 = v1;
  if ( (int)v1 >= p_m_Vertices->nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v1, p_m_Vertices->nCount);
    v9 = (int)(v1 + 1);
    if ( v1 + 1 != (const char *)p_m_Vertices->nCount )
    {
      v10 = v9 / 16;
      if ( 16 * (v9 / 16) < v9 )
        ++v10;
      if ( v10 != p_m_Vertices->nBlocks )
      {
        if ( v10 > 0x21 )
          _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
        BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v10);
      }
      v3 = v2;
      p_m_Vertices->nCount = (_WORD)v1 + 1;
    }
    v8 = v1;
  }
  v11 = (int)v8 % 16;
  v12 = p_m_Vertices->Blocks[(int)v8 / 16];
  v11 *= 6;
  v13 = p_m_bVisible[8] == *(&v12->pos.x + 2 * v11);
  v14 = (int)&v12->pos + 8 * v11;
  if ( !v13 || p_m_bVisible[9] != *(float *)(v14 + 4) || p_m_bVisible[10] != *(float *)(v14 + 8) )
  {
    edx1 = v1;
    this = v16;
    goto LABEL_27;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AB290
// Name: private: unsigned long __near * CSSolid::MergeSameVertices(int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall CSSolid::MergeSameVertices(CSSolid *this, int *nDeleted)
{
  int i; // eax
  CSSolid *v3; // edx
  int m_nVertices; // ecx
  int v5; // ebx
  CSSolid *v6; // esi
  unsigned int v7; // edi
  float *p_m_bVisible; // edi
  unsigned int v9; // eax
  CSSVertex *v10; // ecx
  bool v11; // zf
  int p_pos; // ecx
  CSSolid *v13; // esi
  int nCount; // eax
  int v15; // edi
  int v16; // edx
  int v17; // ecx
  unsigned int v18; // edi
  unsigned int id; // edi
  int v20; // eax
  unsigned int v21; // edi
  unsigned int v22; // ecx
  CSSEdge **AffectedEdges; // eax
  signed int v24; // esi
  CSSEdge **j; // ebx
  CSSEdge *v26; // eax
  CSSEdge *v27; // eax
  signed int v29; // esi
  int v30; // edi
  CSSolid *v31; // ebx
  unsigned int v32; // ebx
  CSSolid *v33; // eax
  CSSEdge *v34; // eax
  const char *v35; // ebx
  BlockArray<CSSEdge,16,32> *p_m_Edges; // esi
  int v37; // edi
  unsigned int v38; // ebx
  int v39; // ecx
  CSSEdge *v40; // edi
  int v41; // ebx
  unsigned int v42; // edi
  CSSEdge *v43; // eax
  unsigned int hvStart; // ecx
  unsigned int v45; // esi
  int v46; // ecx
  int v47; // edi
  unsigned int v48; // esi
  int v49; // eax
  int v50; // ecx
  _DWORD *v51; // edx
  CSSolid *v52; // ecx
  int v53; // ebx
  int v54; // esi
  __int16 v55; // cx
  unsigned int v56; // esi
  int v57; // esi
  int v58; // edx
  int v59; // edi
  int v60; // eax
  _DWORD *v61; // ecx
  int v62; // ebx
  CSSolid *v63; // ecx
  unsigned int id2; // [esp+Ch] [ebp-18h] BYREF
  int f; // [esp+10h] [ebp-14h] BYREF
  unsigned int hV2; // [esp+14h] [ebp-10h]
  int nMerged; // [esp+18h] [ebp-Ch]
  int v1; // [esp+1Ch] [ebp-8h]
  CSSolid *v69; // [esp+20h] [ebp-4h]

  v69 = this;
  nMerged = 0;
  *nDeleted = 0;
DoVertices:
  for ( i = 0; ; f = i )
  {
    v3 = v69;
    m_nVertices = v69->m_nVertices;
    v1 = i;
    if ( i >= m_nVertices )
      break;
    v5 = 0;
    if ( m_nVertices > 0 )
    {
      v6 = v69;
      while ( 1 )
      {
        if ( i != v5 )
        {
          if ( v5 >= v6->m_Vertices.nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v5, v6->m_Vertices.nCount);
            if ( v5 + 1 != v6->m_Vertices.nCount )
            {
              v7 = (v5 + 1) / 16;
              if ( (int)(16 * v7) < v5 + 1 )
                ++v7;
              if ( v7 != v6->m_Vertices.nBlocks )
              {
                if ( v7 > 0x21 )
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                BlockArray<CSSVertex,16,32>::GetBlocks(this: &v6->m_Vertices, nNewBlocks: v7);
              }
              v6->m_Vertices.nCount = v5 + 1;
            }
          }
          p_m_bVisible = (float *)&v6->m_Vertices.Blocks[v5 / 16][v5 % 16].m_bVisible;
          if ( v1 >= v6->m_Vertices.nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v1, v6->m_Vertices.nCount);
            if ( v1 + 1 != v6->m_Vertices.nCount )
            {
              v9 = (v1 + 1) / 16;
              f = v9;
              if ( (int)(16 * v9) < v1 + 1 )
                f = ++v9;
              if ( v9 != v6->m_Vertices.nBlocks )
              {
                if ( v9 > 0x21 )
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                BlockArray<CSSVertex,16,32>::GetBlocks(this: &v6->m_Vertices, nNewBlocks: f);
              }
              v6->m_Vertices.nCount = v1 + 1;
            }
          }
          v10 = v6->m_Vertices.Blocks[v1 / 16];
          v11 = p_m_bVisible[8] == v10[v1 % 16].pos.x;
          p_pos = (int)&v10[v1 % 16].pos;
          if ( v11 && p_m_bVisible[9] == *(float *)(p_pos + 4) && p_m_bVisible[10] == *(float *)(p_pos + 8) )
            break;
        }
        v6 = v69;
        i = v1;
        f = ++v5;
        if ( v5 >= v69->m_nVertices )
          goto LABEL_29;
      }
      v13 = v69;
      nCount = v69->m_Vertices.nCount;
      ++nMerged;
      if ( v1 >= nCount )
      {
        v15 = v1;
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v1, nCount);
        v16 = v13->m_Vertices.nCount;
        v17 = v15 + 1;
        f = v15 + 1;
        if ( v15 + 1 != v16 )
        {
          v18 = v17 / 16;
          if ( 16 * (v17 / 16) < v17 )
            ++v18;
          if ( v18 != v13->m_Vertices.nBlocks )
          {
            if ( v18 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSVertex,16,32>::GetBlocks(this: &v13->m_Vertices, nNewBlocks: v18);
            LOWORD(v17) = f;
          }
          v13->m_Vertices.nCount = v17;
        }
      }
      id = v13->m_Vertices.Blocks[v1 / 16][v1 % 16].id;
      v20 = v13->m_Vertices.nCount;
      f = id;
      if ( v5 >= v20 )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v5, v20);
        if ( v5 + 1 != v13->m_Vertices.nCount )
        {
          v21 = (v5 + 1) / 16;
          if ( (int)(16 * v21) < v5 + 1 )
            ++v21;
          if ( v21 != v13->m_Vertices.nBlocks )
          {
            if ( v21 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSVertex,16,32>::GetBlocks(this: &v13->m_Vertices, nNewBlocks: v21);
          }
          id = f;
          v13->m_Vertices.nCount = v5 + 1;
        }
      }
      v22 = v13->m_Vertices.Blocks[v5 / 16][v5 % 16].id;
      hDeletedList[(*nDeleted)++] = id;
      hV2 = v22;
      CSSolid::DeleteVertex(this: v13, iVertex: (const char *)v1);
      AffectedEdges = CSSolid::FindAffectedEdges(
                        this: v13,
                        pHandles: (unsigned int *)&f,
                        iNumHandles: (unsigned int *)1,
                        iNumEdges: (int *)&id2);
      v24 = 0;
      for ( j = AffectedEdges; v24 < (int)id2; ++v24 )
      {
        v26 = j[v24];
        if ( v26->hvStart == id )
          v26->hvStart = hV2;
        v27 = j[v24];
        if ( v27->hvEnd == id )
          v27->hvEnd = hV2;
        CSSolid::CalcEdgeCenter(this: v69, pEdge: (Vector *)j[v24]);
      }
      goto DoVertices;
    }
LABEL_29:
    ++i;
  }
  if ( nMerged == 0 )
    return nullptr;
  v29 = 0;
  if ( v69->m_nEdges > 0 )
  {
    v30 = 1;
    do
    {
      if ( v29 < v69->m_Edges.nCount )
      {
        v31 = v69;
      }
      else
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v29, v69->m_Edges.nCount);
        v31 = v69;
        if ( v30 != v69->m_Edges.nCount )
        {
          v32 = v30 / 16;
          if ( 16 * (v30 / 16) < v30 )
            ++v32;
          if ( v32 != v69->m_Edges.nBlocks )
          {
            if ( v32 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: &v69->m_Edges, nNewBlocks: v32);
          }
          v33 = v69;
          v69->m_Edges.nCount = v30;
          v31 = v33;
        }
      }
      v34 = &v31->m_Edges.Blocks[v29 / 16][v29 % 16];
      if ( v34->hvStart == v34->hvEnd )
      {
        hDeletedList[(*nDeleted)++] = v34->id;
        CSSolid::DeleteEdge(this: v31, iEdge: v29--);
        --v30;
      }
      ++v29;
      ++v30;
      id2 = v29;
    }
    while ( v29 < v31->m_nEdges );
    goto LABEL_72;
  }
DoEdges:
  v35 = nullptr;
  nMerged = 0;
  while ( (int)v35 < v3->m_nEdges )
  {
    p_m_Edges = &v3->m_Edges;
    if ( (int)v35 >= v3->m_Edges.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v35, v3->m_Edges.nCount);
      v37 = (int)(v35 + 1);
      if ( v35 + 1 != (const char *)p_m_Edges->nCount )
      {
        v38 = v37 / 16;
        if ( 16 * (v37 / 16) < v37 )
          ++v38;
        if ( v38 != p_m_Edges->nBlocks )
        {
          if ( v38 > 0x21 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
          BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v38);
        }
        p_m_Edges->nCount = v37;
      }
    }
    v39 = nMerged;
    v40 = &p_m_Edges->Blocks[nMerged / 16][nMerged % 16];
    v41 = 0;
    for ( id2 = (unsigned int)v40; v41 < v69->m_nEdges; f = ++v41 )
    {
      if ( v39 != v41 )
      {
        if ( v41 >= p_m_Edges->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v41, p_m_Edges->nCount);
          if ( v41 + 1 != p_m_Edges->nCount )
          {
            v42 = (v41 + 1) / 16;
            if ( (int)(16 * v42) < v41 + 1 )
              ++v42;
            if ( v42 != p_m_Edges->nBlocks )
            {
              if ( v42 > 0x21 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
              BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v42);
            }
            v40 = (CSSEdge *)id2;
            p_m_Edges->nCount = v41 + 1;
          }
        }
        v43 = &p_m_Edges->Blocks[v41 / 16][v41 % 16];
        hvStart = v40->hvStart;
        if ( v43->hvStart == hvStart && v43->hvEnd == v40->hvEnd || v43->hvEnd == hvStart && v43->hvStart == v40->hvEnd )
        {
          v45 = v43->id;
          v46 = v40->id;
          v47 = 0;
          id2 = v45;
          f = v46;
          if ( v69->m_nFaces > 0 )
          {
            v1 = (int)&v69->m_Faces;
            do
            {
              if ( v47 >= *(__int16 *)(v1 + 44) )
              {
                _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v47, *(__int16 *)(v1 + 44));
                if ( v47 + 1 != *(__int16 *)(v1 + 44) )
                {
                  v48 = (v47 + 1) / 16;
                  if ( (int)(16 * v48) < v47 + 1 )
                    ++v48;
                  if ( v48 != *(__int16 *)(v1 + 46) )
                  {
                    if ( v48 > 0xB )
                      _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
                    BlockArray<CSSFace,16,10>::GetBlocks(this: (BlockArray<CSSFace,16,10> *)v1, nNewBlocks: v48);
                  }
                  v45 = id2;
                  *(_WORD *)(v1 + 44) = v47 + 1;
                }
              }
              v49 = *(_DWORD *)(v1 + 4 * (v47 / 16)) + 912 * (v47 % 16);
              v50 = 0;
              if ( *(int *)(v49 + 512) > 0 )
              {
                v51 = (_DWORD *)(v49 + 32);
                while ( *v51 != v45 )
                {
                  ++v50;
                  ++v51;
                  if ( v50 >= *(_DWORD *)(v49 + 512) )
                    goto LABEL_119;
                }
                *(_DWORD *)(v49 + 4 * v50 + 32) = f;
              }
LABEL_119:
              hV2 = ++v47;
            }
            while ( v47 < v69->m_nFaces );
          }
          hDeletedList[*nDeleted] = v45;
          v52 = v69;
          ++*nDeleted;
          CSSolid::DeleteEdge(this: v52, iEdge: v41);
LABEL_72:
          v3 = v69;
          goto DoEdges;
        }
        v39 = nMerged;
      }
    }
    v3 = v69;
    nMerged = v39 + 1;
    id2 = v39 + 1;
    v35 = (const char *)(v39 + 1);
  }
  v53 = 0;
  f = 0;
  if ( v3->m_nFaces > 0 )
  {
    v1 = (int)&v3->m_Faces;
    nMerged = 1;
    do
    {
      v54 = v1;
      if ( v53 >= *(__int16 *)(v1 + 44) )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v53, *(__int16 *)(v1 + 44));
        if ( nMerged != *(__int16 *)(v54 + 44) )
        {
          v55 = nMerged;
          v56 = nMerged / 16;
          if ( 16 * (nMerged / 16) < nMerged )
            ++v56;
          if ( v56 != *(__int16 *)(v1 + 46) )
          {
            if ( v56 > 0xB )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
            BlockArray<CSSFace,16,10>::GetBlocks(this: (BlockArray<CSSFace,16,10> *)v1, nNewBlocks: v56);
            v55 = nMerged;
          }
          *(_WORD *)(v1 + 44) = v55;
        }
      }
      v57 = *(_DWORD *)(v1 + 4 * (v53 / 16)) + 912 * (v53 % 16);
DoConcurrentEdges:
      v58 = *(_DWORD *)(v57 + 512);
      v59 = 0;
      hV2 = v57 + 32;
      while ( v59 < v58 )
      {
        v60 = 0;
        if ( v58 > 0 )
        {
          v61 = (_DWORD *)(v57 + 32);
          while ( v60 == v59 || *(_DWORD *)hV2 != *v61 )
          {
            ++v60;
            ++v61;
            if ( v60 >= v58 )
              goto LABEL_140;
          }
          memcpy(
            dst: (unsigned __int8 *)(v57 + 4 * v60 + 32),
            src: (unsigned __int8 *)(v57 + 4 * v60 + 36),
            count: 4 * (v58 - v60));
          --*(_DWORD *)(v57 + 512);
          goto DoConcurrentEdges;
        }
LABEL_140:
        ++v59;
        hV2 += 4;
      }
      v62 = f;
      if ( v58 < 3 )
      {
        hDeletedList[*nDeleted] = *(_DWORD *)(v57 + 908);
        v63 = v69;
        ++*nDeleted;
        CSSolid::DeleteFace(this: v63, iFace: v62--);
        --nMerged;
      }
      ++nMerged;
      v53 = v62 + 1;
      f = v53;
      id2 = v53;
    }
    while ( v53 < v69->m_nFaces );
  }
  return hDeletedList;
}

//------------------------------------------------------------------------------
// Address: 0x100ABB80
// Name: public: void __near * CSSolid::GetHandleData(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CSSolid::GetHandleData(CSSolid *this, unsigned int id)
{
  int HandleInfo; // eax
  SSHANDLEINFO hi; // [esp+0h] [ebp-1Ch] BYREF

  HandleInfo = CSSolid::GetHandleInfo(this, pInfo: &hi, id);
  return HandleInfo != 0 ? hi.pData : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100ABBA0
// Name: private: class Vector __near * CSSolid::CreatePointList(class CSSFace __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CSSolid::CreatePointList(CSSolid *this, ATL::CStringData *face)
{
  CSSFace *v2; // esi
  int v4; // eax
  int v5; // ecx
  char *v6; // ebx
  int nEdges; // eax
  float *v8; // ebx
  int v9; // ecx
  int HandleInfo; // eax
  _DWORD *v11; // esi
  int v12; // eax
  _DWORD *v13; // edi
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // edi
  unsigned int v17; // esi
  int v18; // eax
  float *v19; // eax
  int v20; // ecx
  double v21; // st7
  CSSFace *v22; // eax
  CAfxStringMgr *StringManager; // eax
  CSSFace *v24; // esi
  CAfxStringMgr *v25; // eax
  SSHANDLEINFO pInfo; // [esp+Ch] [ebp-3Ch] BYREF
  void *p; // [esp+28h] [ebp-20h]
  CSSolid *v29; // [esp+2Ch] [ebp-1Ch]
  int iNextEdge; // [esp+30h] [ebp-18h]
  int v31; // [esp+34h] [ebp-14h]
  unsigned int *Edges; // [esp+38h] [ebp-10h]
  int v33; // [esp+44h] [ebp-4h]

  v2 = (CSSFace *)face;
  v4 = 12 * ((int)&face[32].pStringMgr->__vftable + 1);
  v5 = (12 * (unsigned __int64)((unsigned int)&face[32].pStringMgr->__vftable + 1)) >> 32 != 0;
  v29 = this;
  v6 = (char *)operator new[](nSize: v4 | -v5);
  p = v6;
  v33 = -1;
  nEdges = v2->nEdges;
  if ( nEdges <= 0 )
    return (Vector *)v6;
  v8 = (float *)(v6 + 8);
  v9 = 1;
  v31 = 1;
  Edges = v2->Edges;
  while ( 1 )
  {
    iNextEdge = v9;
    if ( v9 == nEdges )
      iNextEdge = 0;
    HandleInfo = CSSolid::GetHandleInfo(this, &pInfo, id: *Edges);
    v11 = HandleInfo != 0 ? pInfo.pData : nullptr;
    v12 = CSSolid::GetHandleInfo(this, &pInfo, id: (unsigned int)(&face[2].pStringMgr)[iNextEdge]);
    v13 = v12 != 0 ? pInfo.pData : nullptr;
    if ( v11 == nullptr || v13 == nullptr )
      break;
    v14 = v11[8];
    v15 = v13[8];
    if ( v14 != v15 )
    {
      v16 = v13[9];
      if ( v14 != v16 )
      {
        v17 = v11[9];
        if ( v17 != v15 && v17 != v16 )
        {
LABEL_15:
          StringManager = AfxGetStringManager();
          if ( StringManager == nullptr )
            ATL::AtlThrowImpl(hr: -2147467259);
          face = StringManager->GetNilString(this: StringManager) + 1;
          v33 = 5;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&face,
            pszFormat: "Conversion error!\nhVertex = %08X",
            0);
          v24 = (CSSFace *)face;
          AfxMessageBox(lpszText: (const char *)face, nType: 0, nIDHelp: 0);
          goto LABEL_21;
        }
        v14 = v17;
      }
    }
    if ( v14 == 0 )
      goto LABEL_15;
    v18 = CSSolid::GetHandleInfo(this: v29, &pInfo, id: v14);
    v19 = v18 != 0 ? (float *)pInfo.pData : nullptr;
    ++Edges;
    v20 = v31 + 1;
    *(v8 - 2) = v19[8];
    v31 = v20;
    *(v8 - 1) = v19[9];
    v8 += 3;
    v21 = v19[10];
    v22 = (CSSFace *)face;
    *(v8 - 3) = v21;
    nEdges = v22->nEdges;
    if ( v20 - 1 >= nEdges )
      return (Vector *)p;
    this = v29;
    v9 = v31;
  }
  v25 = AfxGetStringManager();
  if ( v25 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  face = v25->GetNilString(this: v25) + 1;
  v33 = 2;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&face,
    pszFormat: "Conversion error!\nedgeCur = %08X, edgeNext = %08X",
    v11,
    v13);
  v24 = (CSSFace *)face;
  AfxMessageBox(lpszText: (const char *)face, nType: 0, nIDHelp: 0);
LABEL_21:
  v33 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)&v24[-1].id) <= 0 )
    (*(void (__thiscall **)(_DWORD, Vector *))(*(_DWORD *)LODWORD(v24[-1].ptCenter.x) + 4))(
      a1: LODWORD(v24[-1].ptCenter.x),
      a2: &v24[-1].ptCenter);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100ABDE0
// Name: private: int __near * CSSolid::CreatePointIndexList(class CSSFace __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CSSolid::CreatePointIndexList(CSSolid *this, CSSFace *face, int *piPoints)
{
  int *v5; // edx
  int nEdges; // eax
  int v7; // ecx
  int HandleInfo; // eax
  _DWORD *v9; // esi
  int v10; // eax
  unsigned int v11; // ecx
  _DWORD *v12; // eax
  int v13; // edx
  int v14; // eax
  int *v15; // eax
  int v16; // ecx
  SSHANDLEINFO hi; // [esp+8h] [ebp-44h] BYREF
  SSHANDLEINFO pInfo; // [esp+24h] [ebp-28h] BYREF
  int *v20; // [esp+40h] [ebp-Ch]
  int iNextEdge; // [esp+44h] [ebp-8h]
  int *pts; // [esp+48h] [ebp-4h]
  CSSFace *facea; // [esp+54h] [ebp+8h]
  int piPointsa; // [esp+58h] [ebp+Ch]

  if ( piPoints != nullptr )
  {
    v5 = piPoints;
    pts = piPoints;
  }
  else
  {
    pts = (int *)operator new[](nSize: 4 * (face->nEdges + 1));
    v5 = pts;
  }
  nEdges = face->nEdges;
  if ( nEdges <= 0 )
    return v5;
  v20 = v5;
  v7 = 1;
  piPointsa = 1;
  facea = (CSSFace *)face->Edges;
  while ( 1 )
  {
    iNextEdge = v7;
    if ( v7 == nEdges )
      iNextEdge = 0;
    HandleInfo = CSSolid::GetHandleInfo(this, &pInfo, id: facea->m_bVisible);
    v9 = HandleInfo != 0 ? pInfo.pData : nullptr;
    v10 = CSSolid::GetHandleInfo(this, &pInfo, id: face->Edges[iNextEdge]);
    v11 = v9[8];
    v12 = v10 != 0 ? pInfo.pData : nullptr;
    v13 = v12[8];
    if ( v11 != v13 )
    {
      v14 = v12[9];
      if ( v11 != v14 )
      {
        v11 = v9[9];
        if ( v11 != v13 && v11 != v14 )
          v11 = 0;
      }
    }
    CSSolid::GetHandleInfo(this, pInfo: &hi, id: v11);
    v15 = v20;
    v16 = piPointsa;
    facea = (CSSFace *)((char *)facea + 4);
    *v20 = hi.iIndex;
    ++piPointsa;
    v20 = v15 + 1;
    nEdges = face->nEdges;
    if ( v16 >= nEdges )
      break;
    v7 = piPointsa;
  }
  return pts;
}

//------------------------------------------------------------------------------
// Address: 0x100ABEF0
// Name: private: unsigned long __near * CSSolid::CreatePointHandleList(class CSSFace __near &,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int *__thiscall CSSolid::CreatePointHandleList(CSSolid *this, CSSFace *face, unsigned int *phPoints)
{
  unsigned int *v4; // ecx
  int nEdges; // eax
  int v6; // edi
  int HandleInfo; // eax
  _DWORD *v8; // esi
  int v9; // eax
  unsigned int v10; // ecx
  _DWORD *v11; // eax
  int v12; // edx
  int v13; // eax
  unsigned int *v14; // eax
  SSHANDLEINFO pInfo; // [esp+4h] [ebp-28h] BYREF
  unsigned int *v17; // [esp+20h] [ebp-Ch]
  CSSolid *v18; // [esp+24h] [ebp-8h]
  unsigned int *pts; // [esp+28h] [ebp-4h]
  CSSFace *facea; // [esp+34h] [ebp+8h]
  int phPointsa; // [esp+38h] [ebp+Ch]

  v18 = this;
  if ( phPoints != nullptr )
  {
    v4 = phPoints;
    pts = phPoints;
  }
  else
  {
    pts = (unsigned int *)operator new[](nSize: 4 * (face->nEdges + 1));
    v4 = pts;
  }
  nEdges = face->nEdges;
  if ( nEdges <= 0 )
    return v4;
  v17 = v4;
  v6 = 1;
  phPointsa = 1;
  facea = (CSSFace *)face->Edges;
  while ( 1 )
  {
    if ( v6 == nEdges )
      v6 = 0;
    HandleInfo = CSSolid::GetHandleInfo(this: v18, &pInfo, id: facea->m_bVisible);
    v8 = HandleInfo != 0 ? pInfo.pData : nullptr;
    v9 = CSSolid::GetHandleInfo(this: v18, &pInfo, id: face->Edges[v6]);
    v10 = v8[8];
    v11 = v9 != 0 ? pInfo.pData : nullptr;
    v12 = v11[8];
    if ( v10 != v12 )
    {
      v13 = v11[9];
      if ( v10 != v13 )
      {
        v10 = v8[9];
        if ( v10 != v12 && v10 != v13 )
          v10 = 0;
      }
    }
    v14 = v17;
    facea = (CSSFace *)((char *)facea + 4);
    *v17 = v10;
    ++phPointsa;
    v17 = v14 + 1;
    nEdges = face->nEdges;
    if ( phPointsa - 1 >= nEdges )
      break;
    v6 = phPointsa;
  }
  return pts;
}

//------------------------------------------------------------------------------
// Address: 0x100ABFF0
// Name: public: bool CSSolid::IsValidWithDisps(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSSolid::IsValidWithDisps(CSSolid *this)
{
  CSSolid *v1; // esi
  int v3; // edi
  int v4; // ebx
  unsigned int v5; // esi
  CSSFace *v6; // esi
  Vector *PointList; // eax
  CCheckFaceInfo pInfo; // [esp+14h] [ebp-8Ch] BYREF
  int v9; // [esp+98h] [ebp-8h]
  CSSolid *v10; // [esp+9Ch] [ebp-4h]
  int _A0; // [esp+A0h] [ebp+0h] BYREF

  v1 = this;
  v10 = this;
  if ( CSSolid::HasDisps(this) == 0 )
    return 1;
  v3 = 0;
  if ( v1->m_nFaces <= 0 )
    return 1;
  while ( 1 )
  {
    if ( v3 >= v1->m_Faces.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, v1->m_Faces.nCount);
      v4 = v3 + 1;
      if ( v3 + 1 != v1->m_Faces.nCount )
      {
        v5 = v4 / 16;
        if ( 16 * (v4 / 16) < v4 )
          ++v5;
        if ( v5 != v10->m_Faces.nBlocks )
        {
          if ( v5 > 0xB )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
          BlockArray<CSSFace,16,10>::GetBlocks(this: &v10->m_Faces, nNewBlocks: v5);
        }
        v10->m_Faces.nCount = v4;
      }
    }
    v6 = &v10->m_Faces.Blocks[v3 / 16][v3 % 16];
    if ( v6->m_hDisp != 0xFFFF )
    {
      PointList = CSSolid::CreatePointList(this: v10, face: (ATL::CStringData *)v6);
      if ( v6->nEdges != 4 )
        break;
      pInfo.iPoint = -1;
      if ( CheckFace(a1: (int)&_A0, Points: PointList, nPoints: 4, pNormal: nullptr, dist: 0.0, &pInfo) == 0 )
        break;
    }
    v9 = ++v3;
    if ( v3 >= v10->m_nFaces )
      return 1;
    v1 = v10;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AC140
// Name: private: void CSSolid::ToMapSolid(class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::ToMapSolid(CSSolid *this, CMapSolid *p)
{
  CMapSolid *m_pMapSolid; // esi
  CSSolid *v3; // ebx
  int v4; // edi
  int v5; // ecx
  unsigned int v6; // esi
  int v7; // esi
  Vector *PointList; // eax
  TextureAlignment_t Id; // eax
  CEditDispMgr *v10; // eax
  int v11; // ebx
  CEditDispMgr *v12; // eax
  CMapDisp *v13; // ebx
  CEditDispMgr *v14; // eax
  CMapDisp *v15; // eax
  CEditDispMgr *v16; // eax
  int v17; // ecx
  unsigned int v18; // esi
  CMapFace *v19; // esi
  int v20; // [esp-8h] [ebp-1F4h]
  CMapFace SolidFace; // [esp+Ch] [ebp-1E0h] BYREF
  int hDisp; // [esp+1C8h] [ebp-24h]
  int b; // [esp+1CCh] [ebp-20h] BYREF
  int r; // [esp+1D0h] [ebp-1Ch] BYREF
  int g; // [esp+1D4h] [ebp-18h] BYREF
  Vector *pts; // [esp+1D8h] [ebp-14h]
  CSSolid *v27; // [esp+1DCh] [ebp-10h]
  int v28; // [esp+1E8h] [ebp-4h]

  m_pMapSolid = p;
  v3 = this;
  v27 = this;
  if ( p == nullptr )
  {
    p = this->m_pMapSolid;
    m_pMapSolid = this->m_pMapSolid;
  }
  BlockArray<CMapFace,6,86>::SetCount(this: &m_pMapSolid->Faces, nObjects: this->m_nFaces);
  m_pMapSolid->GetRenderColor_2(
    this: m_pMapSolid,
    a2: (unsigned __int8 *)&r,
    a3: (unsigned __int8 *)&g,
    a4: (unsigned __int8 *)&b);
  v4 = 0;
  if ( v3->m_nFaces > 0 )
  {
    while ( 1 )
    {
      if ( v4 >= v3->m_Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, v3->m_Faces.nCount);
        v5 = v4 + 1;
        if ( v4 + 1 != v3->m_Faces.nCount )
        {
          v6 = v5 / 16;
          if ( 16 * (v5 / 16) < v5 )
            ++v6;
          if ( v6 != v3->m_Faces.nBlocks )
          {
            if ( v6 > 0xB )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
            BlockArray<CSSFace,16,10>::GetBlocks(this: &v3->m_Faces, nNewBlocks: v6);
          }
          v3->m_Faces.nCount = v4 + 1;
        }
      }
      v7 = (int)&v3->m_Faces.Blocks[v4 / 16][v4 % 16];
      CMapFace::CMapFace(this: &SolidFace);
      v28 = 0;
      _V_memcpy(dest: &SolidFace.texture, src: (const void *)(v7 + 568), count: 320);
      CMapFace::SetTexture(this: &SolidFace, pszNewTex: SolidFace.texture.texture, bRescaleTextureCoordinates: false);
      SolidFace.m_nFaceID = *(_DWORD *)(v7 + 888);
      PointList = CSSolid::CreatePointList(this: v27, face: (ATL::CStringData *)v7);
      v20 = *(_DWORD *)(v7 + 512);
      pts = PointList;
      CMapFace::CreateFace(this: &SolidFace, pPoints: PointList, _nPoints: v20, bIsCordonFace: false);
      if ( CMapFace::IsTextureAxisValid(this: &SolidFace) == 0 )
      {
        Id = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
        CMapFace::InitializeTextureAxes(this: &SolidFace, eAlignment: Id, dwFlags: 3u);
      }
      if ( *(_WORD *)(v7 + 892) != 0xFFFF )
      {
        v10 = EditDispMgr();
        v11 = v10->Create(this: v10);
        hDisp = v11;
        v12 = EditDispMgr();
        v13 = v12->GetDisp(this: v12, a2: v11);
        v14 = EditDispMgr();
        v15 = v14->GetDisp(this: v14, a2: *(_WORD *)(v7 + 892));
        CMapDisp::CopyFrom(this: v13, pMapDisp: v15, bUpdateDependencies: false);
        v13->m_CoreDispInfo.m_Surf.m_PointStartIndex = (v13->m_CoreDispInfo.m_Surf.m_PointStartIndex + 3) % 4;
        CMapDisp::InitDispSurfaceData(this: v13, pFace: &SolidFace, bGenerateStartPoint: false);
        CMapDisp::Create(this: v13, a2: (int)v13);
        if ( SolidFace.m_DispHandle != 0xFFFF )
        {
          v16 = EditDispMgr();
          v16->Destroy(this: v16, a2: *(_DWORD *)&SolidFace.m_DispHandle);
        }
        SolidFace.m_DispHandle = hDisp;
      }
      if ( v4 >= p->Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p->Faces.nCount);
        v17 = v4 + 1;
        if ( v4 + 1 != p->Faces.nCount )
        {
          v18 = v17 / 6;
          if ( 6 * (v17 / 6) < v17 )
            ++v18;
          if ( v18 != p->Faces.nBlocks )
          {
            if ( v18 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &p->Faces, nNewBlocks: v18);
          }
          p->Faces.nCount = v4 + 1;
        }
      }
      v19 = &p->Faces.Blocks[v4 / 6][v4 % 6];
      CMapFace::CopyFrom(this: v19, pObject: &SolidFace, dwFlags: 2u, bUpdateDependencies: true);
      v19->SetRenderColor_2(this: v19, a2: r, a3: g, a4: b);
      v19->SetParent(this: v19, a2: p);
      operator delete(p: pts);
      v28 = -1;
      CMapFace::~CMapFace(this: &SolidFace);
      pts = (Vector *)++v4;
      if ( v4 >= v27->m_nFaces )
        break;
      v3 = v27;
    }
    m_pMapSolid = p;
  }
  m_pMapSolid->PostUpdate(this: m_pMapSolid, a2: Notify_Changed);
}

//------------------------------------------------------------------------------
// Address: 0x100AC4C0
// Name: public: void CSSolid::MoveSelectedHandles(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::MoveSelectedHandles(CSSolid *this, const Vector *Delta)
{
  int v2; // edi
  int v3; // esi
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // edi
  int v5; // ecx
  unsigned int v6; // ebx
  int v7; // ecx
  unsigned int v8; // eax
  int v9; // eax
  CSSolid *v10; // eax
  int v11; // ebx
  BlockArray<CSSEdge,16,32> *p_m_Edges; // esi
  int v13; // edi
  unsigned int v14; // esi
  CSSEdge *v15; // eax
  int v16; // edx
  unsigned int v17; // esi
  int v18; // ebx
  BlockArray<CSSVertex,16,32> *v19; // edi
  int nCount; // eax
  int iIndex; // esi
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  int v25; // ecx
  unsigned int v26; // ebx
  float *p_x; // eax
  CSSEdge **AffectedEdges; // eax
  const Vector *v29; // ebx
  int v30; // esi
  CSSEdge **k; // edi
  unsigned int MoveVertices[128]; // [esp+Ch] [ebp-23Ch] BYREF
  SSHANDLEINFO hi; // [esp+20Ch] [ebp-3Ch] BYREF
  float v34; // [esp+228h] [ebp-20h]
  float v35; // [esp+22Ch] [ebp-1Ch]
  float v36; // [esp+230h] [ebp-18h]
  int bAddStart; // [esp+234h] [ebp-14h]
  CSSolid *v38; // [esp+238h] [ebp-10h]
  BlockArray<CSSEdge,16,32> *j; // [esp+23Ch] [ebp-Ch]
  int nMoveVertices; // [esp+240h] [ebp-8h]
  int i; // [esp+244h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v38 = this;
  nMoveVertices = 0;
  if ( this->m_nVertices > 0 )
  {
    p_m_Vertices = &this->m_Vertices;
    do
    {
      if ( v3 >= p_m_Vertices->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_m_Vertices->nCount);
        v5 = v3 + 1;
        if ( v3 + 1 != p_m_Vertices->nCount )
        {
          v6 = v5 / 16;
          if ( 16 * (v5 / 16) < v5 )
            ++v6;
          if ( v6 != p_m_Vertices->nBlocks )
          {
            if ( v6 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v6);
          }
          p_m_Vertices->nCount = v3 + 1;
        }
      }
      i = (int)&p_m_Vertices->Blocks[v3 / 16];
      if ( *(_DWORD *)(*(_DWORD *)i + 48 * (v3 % 16) + 4) != 0 )
      {
        if ( v3 >= p_m_Vertices->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_m_Vertices->nCount);
          v7 = v3 + 1;
          if ( v3 + 1 != p_m_Vertices->nCount )
          {
            v8 = v7 / 16;
            j = (BlockArray<CSSEdge,16,32> *)(v7 / 16);
            if ( 16 * (v7 / 16) < v7 )
              j = (BlockArray<CSSEdge,16,32> *)++v8;
            if ( v8 != p_m_Vertices->nBlocks )
            {
              if ( v8 > 0x21 )
              {
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                v8 = (unsigned int)j;
              }
              BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v8);
            }
            p_m_Vertices->nCount = v3 + 1;
          }
        }
        v9 = nMoveVertices;
        MoveVertices[nMoveVertices] = *(_DWORD *)(*(_DWORD *)i + 48 * (v3 % 16) + 44);
        nMoveVertices = v9 + 1;
      }
      i = ++v3;
    }
    while ( v3 < v38->m_nVertices );
    v2 = nMoveVertices;
  }
  v10 = v38;
  v11 = 0;
  if ( v38->m_nEdges > 0 )
  {
    p_m_Edges = &v38->m_Edges;
    for ( j = &v38->m_Edges; ; p_m_Edges = j )
    {
      if ( v11 >= p_m_Edges->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v11, p_m_Edges->nCount);
        v13 = v11 + 1;
        if ( v11 + 1 != p_m_Edges->nCount )
        {
          v14 = v13 / 16;
          if ( 16 * (v13 / 16) < v13 )
            ++v14;
          if ( v14 != j->nBlocks )
          {
            if ( v14 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: j, nNewBlocks: v14);
          }
          j->nCount = v13;
        }
        v2 = nMoveVertices;
      }
      v15 = &j->Blocks[v11 / 16][v11 % 16];
      if ( v15->m_bSelected != 0 )
      {
        v16 = 0;
        bAddStart = 1;
        i = 1;
        if ( v2 <= 0 )
          goto LABEL_46;
        do
        {
          v17 = MoveVertices[v16];
          if ( v15->hvStart == v17 )
            bAddStart = 0;
          if ( v15->hvEnd == v17 )
            i = 0;
          ++v16;
        }
        while ( v16 < v2 );
        if ( bAddStart != 0 )
        {
LABEL_46:
          MoveVertices[v2++] = v15->hvStart;
          nMoveVertices = v2;
        }
        if ( i != 0 )
        {
          MoveVertices[v2++] = v15->hvEnd;
          nMoveVertices = v2;
        }
      }
      v10 = v38;
      i = ++v11;
      if ( v11 >= v38->m_nEdges )
        break;
    }
  }
  v18 = 0;
  i = 0;
  if ( v2 > 0 )
  {
    v19 = &v10->m_Vertices;
    do
    {
      CSSolid::GetHandleInfo(this: v38, pInfo: &hi, id: MoveVertices[v18]);
      nCount = v19->nCount;
      iIndex = hi.iIndex;
      v22 = *((float *)hi.pData + 8) + Delta->x;
      v23 = *((float *)hi.pData + 9) + Delta->y;
      v24 = *((float *)hi.pData + 10) + Delta->z;
      v34 = v22;
      v35 = v23;
      v36 = v24;
      if ( hi.iIndex >= nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)hi.iIndex, nCount);
        v25 = iIndex + 1;
        if ( iIndex + 1 != v19->nCount )
        {
          v26 = v25 / 16;
          if ( 16 * (v25 / 16) < v25 )
            ++v26;
          if ( v26 != v19->nBlocks )
          {
            if ( v26 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSVertex,16,32>::GetBlocks(this: v19, nNewBlocks: v26);
          }
          v18 = i;
          v19->nCount = iIndex + 1;
        }
        v22 = v34;
        v23 = v35;
        v24 = v36;
      }
      p_x = &v19->Blocks[iIndex / 16][iIndex % 16].pos.x;
      ++v18;
      *p_x = v22;
      p_x[1] = v23;
      p_x[2] = v24;
      i = v18;
    }
    while ( v18 < nMoveVertices );
    v2 = nMoveVertices;
  }
  AffectedEdges = CSSolid::FindAffectedEdges(
                    this: v38,
                    pHandles: MoveVertices,
                    iNumHandles: (unsigned int *)v2,
                    iNumEdges: (int *)&Delta);
  v29 = Delta;
  v30 = 0;
  for ( k = AffectedEdges; v30 < (int)v29; ++v30 )
    CSSolid::CalcEdgeCenter(this: v38, pEdge: (Vector *)k[v30]);
}

//------------------------------------------------------------------------------
// Address: 0x100AC8D0
// Name: public: int CSSolid::SplitFaceByVertices(class CSSVertex __near *,class CSSVertex __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSSolid::SplitFaceByVertices(CSSolid *this, CSSVertex *pVertex1, CSSVertex *pVertex2)
{
  unsigned int *p_id; // esi
  unsigned int *v5; // ebx
  unsigned __int8 *AffectedEdges; // eax
  int v8; // ebx
  unsigned __int8 *v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // ebx
  int v14; // ecx
  CSSEdge *v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // eax
  int HandleInfo; // eax
  CSSFace *v19; // ebx
  CSSFace *v20; // eax
  CSSolid *v21; // edi
  CSSEdge *v22; // eax
  unsigned int *v23; // ecx
  CSSEdge *v24; // esi
  unsigned int v25; // edx
  unsigned int v26; // eax
  unsigned int v27; // ecx
  unsigned int v28; // ecx
  unsigned int v29; // eax
  CSSVertex *PointHandleList; // edx
  int nEdges; // eax
  int v32; // esi
  int EdgeIndex; // esi
  int v34; // ecx
  unsigned int v35; // edi
  CSSolid *v36; // ecx
  unsigned int v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // ecx
  int v42; // ecx
  int v43; // esi
  BlockArray<CSSEdge,16,32> *p_m_Edges; // ebx
  int v45; // ecx
  unsigned int v46; // edi
  int v47; // edi
  const char *nCount; // eax
  int v49; // ecx
  unsigned int v50; // esi
  unsigned int v51; // edx
  int v52; // ecx
  unsigned int v53; // eax
  CSSFace *v54; // eax
  int v55; // ecx
  int v56; // eax
  unsigned int v57; // [esp-8h] [ebp-260h]
  unsigned int id; // [esp-4h] [ebp-25Ch]
  CSSEdge *pEdges2[64]; // [esp+Ch] [ebp-24Ch] BYREF
  unsigned int hNewEdges[64]; // [esp+10Ch] [ebp-14Ch] BYREF
  SSHANDLEINFO pInfo; // [esp+20Ch] [ebp-4Ch] BYREF
  CSSFace *pFace; // [esp+228h] [ebp-30h]
  CSSEdge *pNewEdge; // [esp+22Ch] [ebp-2Ch]
  CSSFace *pStoreFace; // [esp+230h] [ebp-28h]
  int bFirst; // [esp+234h] [ebp-24h]
  CSSFace *pNewFace; // [esp+238h] [ebp-20h]
  int v67; // [esp+23Ch] [ebp-1Ch]
  int v1index; // [esp+240h] [ebp-18h]
  unsigned int *v69; // [esp+244h] [ebp-14h]
  unsigned int *v70; // [esp+248h] [ebp-10h]
  CSSolid *v71; // [esp+24Ch] [ebp-Ch]
  int i; // [esp+250h] [ebp-8h]
  int iNumEdges1; // [esp+254h] [ebp-4h] BYREF
  unsigned int nNewEdges; // [esp+260h] [ebp+8h]
  int nNewEdgesa; // [esp+260h] [ebp+8h]
  int nNewEdgesb; // [esp+260h] [ebp+8h]

  p_id = &pVertex2->id;
  v5 = &pVertex1->id;
  id = pVertex2->id;
  v57 = pVertex1->id;
  v71 = this;
  v69 = &pVertex2->id;
  v70 = &pVertex1->id;
  if ( CSSolid::GetEdgeIndex(this, v1: v57, v2: id) == -1 )
  {
    nNewEdges = 0;
    AffectedEdges = (unsigned __int8 *)CSSolid::FindAffectedEdges(
                                         this,
                                         pHandles: v5,
                                         iNumHandles: (unsigned int *)1,
                                         iNumEdges: &iNumEdges1);
    v8 = iNumEdges1;
    memcpy(dst: (unsigned __int8 *)hNewEdges, src: AffectedEdges, count: 4 * iNumEdges1);
    v9 = (unsigned __int8 *)CSSolid::FindAffectedEdges(
                              this,
                              pHandles: p_id,
                              iNumHandles: (unsigned int *)1,
                              iNumEdges: (int *)&pVertex2);
    memcpy(dst: (unsigned __int8 *)pEdges2, src: v9, count: 4 * (_DWORD)pVertex2);
    v10 = 0;
    i = 0;
    if ( v8 > 0 )
    {
      do
      {
        v11 = hNewEdges[v10];
        v12 = *(_DWORD *)(v11 + 52);
        v13 = *(_DWORD *)(v11 + 56);
        v14 = 0;
        if ( (int)pVertex2 > 0 )
        {
          while ( 1 )
          {
            v15 = pEdges2[v14];
            v16 = v15->Faces[0];
            if ( v12 == v16 )
              break;
            v17 = v15->Faces[1];
            if ( v12 == v17 )
              break;
            if ( v13 == v16 || v13 == v17 )
            {
              nNewEdges = v13;
              goto LABEL_13;
            }
            if ( ++v14 >= (int)pVertex2 )
              goto LABEL_13;
          }
          nNewEdges = v12;
        }
LABEL_13:
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < iNumEdges1 );
      if ( nNewEdges != 0 )
      {
        HandleInfo = CSSolid::GetHandleInfo(this, &pInfo, id: nNewEdges);
        v19 = HandleInfo != 0 ? (CSSFace *)pInfo.pData : nullptr;
        pFace = v19;
        v20 = CSSolid::AddFace(this, piNewIndex: nullptr);
        qmemcpy(&v20->texture, &v19->texture, sizeof(v20->texture));
        v21 = v71;
        pNewFace = v20;
        v22 = CSSolid::AddEdge(this: v71, piNewIndex: nullptr);
        v23 = v69;
        v24 = v22;
        v22->hvStart = *v70;
        v25 = *v23;
        pNewEdge = v22;
        v22->hvEnd = v25;
        CSSolid::CalcEdgeCenter(this: v21, pEdge: (Vector *)v22);
        v26 = v24->Faces[0];
        v27 = v19->id;
        if ( v26 == 0 || v26 == v27 )
        {
          v24->Faces[0] = v27;
        }
        else if ( v24->Faces[1] == 0 )
        {
          v24->Faces[1] = v27;
        }
        v28 = pNewFace->id;
        v29 = v24->Faces[0];
        if ( v29 == 0 || v29 == v28 )
        {
          v24->Faces[0] = v28;
        }
        else if ( v24->Faces[1] == 0 )
        {
          v24->Faces[1] = v28;
        }
        bFirst = 1;
        pStoreFace = v19;
        PointHandleList = (CSSVertex *)CSSolid::CreatePointHandleList(this: v21, face: v19, phPoints: nullptr);
        nEdges = v19->nEdges;
        pVertex2 = PointHandleList;
        i = nEdges;
        v1index = 0;
        iNumEdges1 = 0;
        nNewEdgesa = 0;
        if ( nEdges > 0 )
        {
          while ( 1 )
          {
            v32 = nNewEdgesa + 1;
            v67 = nNewEdgesa + 1;
            if ( nNewEdgesa + 1 == nEdges )
            {
              v32 = 0;
            }
            else if ( nNewEdgesa == -2 )
            {
              v32 = nEdges - 1;
            }
            EdgeIndex = CSSolid::GetEdgeIndex(
                          this: v21,
                          v1: *(&PointHandleList->m_bVisible + nNewEdgesa),
                          v2: *(&PointHandleList->m_bVisible + v32));
            if ( EdgeIndex >= v21->m_Edges.nCount )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)EdgeIndex, v21->m_Edges.nCount);
              v34 = EdgeIndex + 1;
              if ( EdgeIndex + 1 != v21->m_Edges.nCount )
              {
                v35 = v34 / 16;
                if ( 16 * (v34 / 16) < v34 )
                  ++v35;
                if ( v35 != v71->m_Edges.nBlocks )
                {
                  if ( v35 > 0x21 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                  BlockArray<CSSEdge,16,32>::GetBlocks(this: &v71->m_Edges, nNewBlocks: v35);
                }
                v36 = v71;
                v71->m_Edges.nCount = EdgeIndex + 1;
                v21 = v36;
              }
            }
            v37 = v19->id;
            v38 = (int)&v21->m_Edges.Blocks[EdgeIndex / 16][EdgeIndex % 16];
            if ( *(_DWORD *)(v38 + 52) == v37 )
              *(_DWORD *)(v38 + 52) = 0;
            if ( *(_DWORD *)(v38 + 56) == v37 )
              *(_DWORD *)(v38 + 56) = 0;
            v39 = *(&pVertex2->m_bVisible + nNewEdgesa);
            if ( v39 == *v70 )
            {
              v1index = nNewEdgesa;
            }
            else if ( v39 == *v69 )
            {
              iNumEdges1 = nNewEdgesa;
            }
            PointHandleList = pVertex2;
            nNewEdgesa = v67;
            if ( v67 >= i )
              break;
            nEdges = i;
          }
          v24 = pNewEdge;
        }
        while ( 2 )
        {
          v40 = v1index;
          v41 = 0;
          nNewEdgesb = 0;
          while ( 1 )
          {
            if ( v40 == i )
              v40 = 0;
            if ( v40 == iNumEdges1 )
              break;
            v42 = v40 + 1;
            v70 = (unsigned int *)(v40 + 1);
            if ( v40 + 1 == i )
            {
              v42 = 0;
            }
            else if ( v40 == -2 )
            {
              v42 = i - 1;
            }
            v43 = CSSolid::GetEdgeIndex(
                    this: v21,
                    v1: *(&PointHandleList->m_bVisible + v40),
                    v2: *(&PointHandleList->m_bVisible + v42));
            p_m_Edges = &v21->m_Edges;
            if ( v43 >= v21->m_Edges.nCount )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v43, v21->m_Edges.nCount);
              v45 = v43 + 1;
              if ( v43 + 1 != v21->m_Edges.nCount )
              {
                v46 = v45 / 16;
                if ( 16 * (v45 / 16) < v45 )
                  ++v46;
                if ( v46 != p_m_Edges->nBlocks )
                {
                  if ( v46 > 0x21 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                  BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v46);
                }
                p_m_Edges->nCount = v43 + 1;
              }
            }
            v69 = (unsigned int *)&p_m_Edges->Blocks[v43 / 16];
            v47 = (v43 % 16) << 6;
            hNewEdges[nNewEdgesb++] = *(_DWORD *)(*v69 + v47 + 60);
            if ( v43 >= p_m_Edges->nCount )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v43, p_m_Edges->nCount);
              nCount = (const char *)p_m_Edges->nCount;
              v49 = v43 + 1;
              v67 = v43 + 1;
              if ( (const char *)(v43 + 1) != nCount )
              {
                v50 = v49 / 16;
                if ( 16 * (v49 / 16) < v49 )
                  ++v50;
                if ( v50 != p_m_Edges->nBlocks )
                {
                  if ( v50 > 0x21 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                  BlockArray<CSSEdge,16,32>::GetBlocks(this: p_m_Edges, nNewBlocks: v50);
                  LOWORD(v49) = v67;
                }
                p_m_Edges->nCount = v49;
              }
            }
            v51 = pFace->id;
            v52 = *(_DWORD *)(*v69 + v47 + 52);
            v53 = v47 + *v69;
            if ( v52 == 0 || v52 == v51 )
            {
              *(_DWORD *)(v53 + 52) = v51;
LABEL_82:
              v40 = (int)v70;
              v41 = nNewEdgesb;
              v21 = v71;
              v24 = pNewEdge;
              PointHandleList = pVertex2;
            }
            else
            {
              if ( *(_DWORD *)(v53 + 56) != 0 )
                goto LABEL_82;
              v41 = nNewEdgesb;
              v21 = v71;
              v24 = pNewEdge;
              *(_DWORD *)(v53 + 56) = v51;
              v40 = (int)v70;
              PointHandleList = pVertex2;
            }
          }
          v54 = pStoreFace;
          hNewEdges[v41] = v24->id;
          v55 = v41 + 1;
          v54->nEdges = v55;
          memcpy(dst: (unsigned __int8 *)v54->Edges, src: (unsigned __int8 *)hNewEdges, count: 4 * v55);
          if ( bFirst != 0 )
          {
            v56 = v1index;
            pStoreFace = pNewFace;
            PointHandleList = pVertex2;
            v1index = iNumEdges1;
            iNumEdges1 = v56;
            bFirst = 0;
            continue;
          }
          break;
        }
        operator delete(p: pVertex2);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ACE10
// Name: private: unsigned long __near * CSSolid::CreateNewVertexList(class CSSFace __near *,class CSSEdge __near *,class CSSEdge __near *,int __near &,int __near &,class CSSVertex __near *,class CSSVertex __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CSSolid::CreateNewVertexList(
        CSSolid *this,
        CSSFace *pFace,
        CSSEdge *pEdge1,
        CSSEdge *pEdge2,
        int *nv1index,
        int *nv2index,
        CSSVertex *pNewVertex1,
        CSSVertex *pNewVertex2)
{
  unsigned int *m_pMemory; // esi
  int nEdges; // edi
  int v11; // edx
  int v12; // ebx
  int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  int *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int hvEnd; // ecx
  unsigned int v22; // eax
  int *v23; // ecx
  unsigned int v24; // eax
  int v25; // eax
  int v26; // edi
  int v27; // eax
  unsigned int *v28; // edi
  CSSVertex *v29; // ecx
  int m_Size; // eax
  int v31; // edi
  int v32; // eax
  int m_nGrowSize; // edi
  unsigned __int8 *v35; // ebx
  int v36; // edi
  int v37; // [esp-4h] [ebp-40h]
  CUtlVector<unsigned long,CUtlMemory<unsigned long,int> > hVertexList; // [esp+Ch] [ebp-30h] BYREF
  int iPass; // [esp+20h] [ebp-1Ch]
  int v40; // [esp+24h] [ebp-18h]
  int v41; // [esp+28h] [ebp-14h]
  int v42; // [esp+2Ch] [ebp-10h]
  int v43; // [esp+38h] [ebp-4h]
  int nVertices; // [esp+44h] [ebp+8h]

  memset(&hVertexList, 0, sizeof(hVertexList));
  v43 = 1;
  v37 = pFace->nEdges + 4;
  hVertexList.m_Size = 0;
  CUtlVector<unsigned long,CUtlMemory<unsigned long,int>>::InsertMultipleBefore(
    this: (CUtlVector<CLightingPreviewLightDescription *,CUtlMemory<CLightingPreviewLightDescription *,int> > *)&hVertexList,
    elem: 0,
    num: v37);
  m_pMemory = hVertexList.m_Memory.m_pMemory;
  CSSolid::CreatePointHandleList(this, face: pFace, phPoints: hVertexList.m_Memory.m_pMemory);
  *nv1index = -1;
  *nv2index = -1;
  nEdges = pFace->nEdges;
  nVertices = nEdges;
  iPass = 0;
  v42 = nEdges - 1;
  while ( 2 )
  {
    v11 = 0;
    if ( nEdges <= 0 )
      goto LABEL_54;
    while ( 1 )
    {
      v12 = v11 - 1;
      v41 = v11 - 1;
      if ( v11 - 1 == nVertices )
      {
        v12 = 0;
      }
      else
      {
        if ( v11 != 0 )
          goto LABEL_8;
        v12 = v42;
      }
      v41 = v12;
LABEL_8:
      v13 = v11 + 1;
      v40 = v11 + 1;
      v14 = v11 + 1;
      if ( v11 + 1 == nVertices )
      {
        v14 = 0;
      }
      else if ( v11 == -2 )
      {
        v14 = v42;
      }
      if ( *nv1index == -1 )
        break;
LABEL_25:
      if ( *nv2index == -1 )
      {
        v20 = m_pMemory[v11];
        hvEnd = pEdge2->hvEnd;
        if ( v20 != hvEnd )
        {
          if ( v20 != pEdge2->hvStart )
          {
LABEL_37:
            v13 = v40;
            goto LABEL_38;
          }
          v12 = v41;
        }
        v22 = m_pMemory[v12];
        if ( v22 == pEdge2->hvStart || v22 == hvEnd )
        {
          v23 = nv2index;
          *nv2index = v11;
        }
        else
        {
          v23 = nv2index;
        }
        v24 = m_pMemory[v14];
        if ( v24 == pEdge2->hvStart || v24 == pEdge2->hvEnd )
          *v23 = v14;
        if ( *v23 != -1 )
        {
          m_Size = hVertexList.m_Size;
          v31 = *v23;
          if ( hVertexList.m_Size + 1 > hVertexList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&hVertexList,
              num: hVertexList.m_Size - hVertexList.m_Memory.m_nAllocationCount + 1);
            m_Size = hVertexList.m_Size;
            m_pMemory = hVertexList.m_Memory.m_pMemory;
          }
          hVertexList.m_Size = m_Size + 1;
          v32 = m_Size - v31;
          hVertexList.m_pElements = m_pMemory;
          if ( v32 > 0 )
            _V_memmove(dest: &m_pMemory[v31 + 1], src: &m_pMemory[v31], count: 4 * v32);
          v28 = &m_pMemory[v31];
          if ( v28 != nullptr )
          {
            v29 = pNewVertex2;
            goto LABEL_52;
          }
          goto LABEL_53;
        }
        goto LABEL_37;
      }
LABEL_38:
      v11 = v13;
      if ( v13 >= nVertices )
        goto LABEL_54;
    }
    v15 = m_pMemory[v11];
    v16 = pEdge1->hvEnd;
    if ( v15 != v16 )
    {
      if ( v15 == pEdge1->hvStart )
      {
        v12 = v41;
        goto LABEL_16;
      }
LABEL_24:
      v12 = v41;
      v13 = v40;
      goto LABEL_25;
    }
LABEL_16:
    v17 = m_pMemory[v12];
    if ( v17 == pEdge1->hvStart || v17 == v16 )
    {
      v18 = nv1index;
      *nv1index = v11;
    }
    else
    {
      v18 = nv1index;
    }
    v19 = m_pMemory[v14];
    if ( v19 == pEdge1->hvStart || v19 == pEdge1->hvEnd )
      *v18 = v14;
    if ( *v18 == -1 )
      goto LABEL_24;
    v25 = hVertexList.m_Size;
    v26 = *v18;
    if ( hVertexList.m_Size + 1 > hVertexList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)&hVertexList,
        num: hVertexList.m_Size - hVertexList.m_Memory.m_nAllocationCount + 1);
      v25 = hVertexList.m_Size;
      m_pMemory = hVertexList.m_Memory.m_pMemory;
    }
    hVertexList.m_Size = v25 + 1;
    v27 = v25 - v26;
    hVertexList.m_pElements = m_pMemory;
    if ( v27 > 0 )
      _V_memmove(dest: &m_pMemory[v26 + 1], src: &m_pMemory[v26], count: 4 * v27);
    v28 = &m_pMemory[v26];
    if ( v28 != nullptr )
    {
      v29 = pNewVertex1;
LABEL_52:
      *v28 = v29->id;
    }
LABEL_53:
    ++nVertices;
    ++v42;
LABEL_54:
    if ( *nv1index == -1 )
    {
      if ( *nv2index == -1 )
      {
        v43 = 2;
        m_nGrowSize = hVertexList.m_Memory.m_nGrowSize;
        hVertexList.m_Size = 0;
        if ( hVertexList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            free(pMem: m_pMemory);
            m_pMemory = nullptr;
            hVertexList.m_Memory.m_pMemory = nullptr;
          }
          hVertexList.m_Memory.m_nAllocationCount = 0;
        }
        hVertexList.m_pElements = m_pMemory;
        v43 = -1;
        if ( m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            free(pMem: m_pMemory);
            hVertexList.m_Memory.m_pMemory = nullptr;
          }
          hVertexList.m_Memory.m_nAllocationCount = 0;
        }
        return nullptr;
      }
LABEL_66:
      if ( ++iPass != 2 )
      {
        nEdges = nVertices;
        continue;
      }
    }
    else if ( *nv2index == -1 )
    {
      goto LABEL_66;
    }
    break;
  }
  v35 = (unsigned __int8 *)operator new[](nSize: 4 * nVertices);
  memcpy(dst: v35, src: (unsigned __int8 *)m_pMemory, count: 4 * nVertices);
  v43 = 3;
  v36 = hVertexList.m_Memory.m_nGrowSize;
  hVertexList.m_Size = 0;
  if ( hVertexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      m_pMemory = nullptr;
      hVertexList.m_Memory.m_pMemory = nullptr;
    }
    hVertexList.m_Memory.m_nAllocationCount = 0;
  }
  hVertexList.m_pElements = m_pMemory;
  v43 = -1;
  if ( v36 >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      hVertexList.m_Memory.m_pMemory = nullptr;
    }
    hVertexList.m_Memory.m_nAllocationCount = 0;
  }
  return v35;
}

//------------------------------------------------------------------------------
// Address: 0x100AD180
// Name: public: void CSSolid::SerializeDXF(struct _iobuf __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSSolid::SerializeDXF(CSSolid *this, _iobuf *stream, int nObject)
{
  CSSolid *v3; // ebx
  const char *v4; // esi
  BlockArray<CSSFace,16,10> *p_m_Faces; // edi
  int v6; // ecx
  unsigned int v7; // edi
  int nEdges; // ecx
  const char *v9; // esi
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // edi
  int v11; // ecx
  unsigned int v12; // ebx
  const char *v13; // esi
  BlockArray<CSSFace,16,10> *v14; // edi
  int v15; // ecx
  unsigned int v16; // ebx
  CSSFace *v17; // esi
  int *PointIndexList; // ebx
  int i; // eax
  int v20; // eax
  int j; // edi
  bool v22; // zf
  int v23; // eax
  int v24; // ecx
  char string[8]; // [esp+8h] [ebp-8Ch] BYREF
  __int64 szName_104; // [esp+8Ch] [ebp-8h] OVERLAPPED
  int szName_124; // [esp+A0h] [ebp+Ch]
  const char *szName_124a; // [esp+A0h] [ebp+Ch]

  v3 = this;
  HIDWORD(szName_104) = this;
  sprintf(string: &string[4], format: "OBJECT%03d", nObject);
  v4 = nullptr;
  szName_124 = 0;
  if ( v3->m_nFaces > 0 )
  {
    p_m_Faces = &v3->m_Faces;
    do
    {
      if ( (int)v4 >= p_m_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v4, p_m_Faces->nCount);
        v6 = (int)(v4 + 1);
        if ( v4 + 1 != (const char *)p_m_Faces->nCount )
        {
          v7 = v6 / 16;
          if ( 16 * (v6 / 16) < v6 )
            ++v7;
          if ( v7 != v3->m_Faces.nBlocks )
          {
            if ( v7 > 0xB )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
            BlockArray<CSSFace,16,10>::GetBlocks(this: &v3->m_Faces, nNewBlocks: v7);
          }
          v3->m_Faces.nCount = (_WORD)v4 + 1;
        }
      }
      nEdges = v3->m_Faces.Blocks[(int)v4 / 16][(int)v4 % 16].nEdges;
      p_m_Faces = &v3->m_Faces;
      ++v4;
      szName_124 = szName_124 + nEdges - 2;
      LODWORD(szName_104) = v4;
    }
    while ( (int)v4 < v3->m_nFaces );
  }
  fprintf(
    str: stream,
    format: "0\nPOLYLINE\n8\n%s\n66\n1\n70\n64\n71\n%u\n72\n%u\n",
    &string[4],
    v3->m_nVertices,
    szName_124);
  fprintf(str: stream, format: "62\n50\n");
  v9 = nullptr;
  if ( v3->m_nVertices > 0 )
  {
    p_m_Vertices = &v3->m_Vertices;
    do
    {
      if ( (int)v9 >= p_m_Vertices->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v9, p_m_Vertices->nCount);
        v11 = (int)(v9 + 1);
        if ( v9 + 1 != (const char *)p_m_Vertices->nCount )
        {
          v12 = v11 / 16;
          if ( 16 * (v11 / 16) < v11 )
            ++v12;
          if ( v12 != p_m_Vertices->nBlocks )
          {
            if ( v12 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v12);
          }
          v3 = (CSSolid *)HIDWORD(szName_104);
          p_m_Vertices->nCount = (_WORD)v9 + 1;
        }
      }
      fprintf(
        str: stream,
        format: "0\nVERTEX\n8\n%s\n10\n%.6f\n20\n%.6f\n30\n%.6f\n70\n192\n",
        &string[4],
        p_m_Vertices->Blocks[(int)v9 / 16][(int)v9 % 16].pos.x,
        p_m_Vertices->Blocks[(int)v9 / 16][(int)v9 % 16].pos.y,
        p_m_Vertices->Blocks[(int)v9 / 16][(int)v9 % 16].pos.z);
      ++v9;
    }
    while ( (int)v9 < v3->m_nVertices );
  }
  v13 = nullptr;
  szName_124a = nullptr;
  if ( v3->m_nFaces > 0 )
  {
    while ( 1 )
    {
      v14 = &v3->m_Faces;
      if ( (int)v13 >= v3->m_Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v13, v3->m_Faces.nCount);
        v15 = (int)(v13 + 1);
        if ( v13 + 1 != (const char *)v3->m_Faces.nCount )
        {
          v16 = v15 / 16;
          if ( 16 * (v15 / 16) < v15 )
            ++v16;
          if ( v16 != v14->nBlocks )
          {
            if ( v16 > 0xB )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
            BlockArray<CSSFace,16,10>::GetBlocks(this: v14, nNewBlocks: v16);
          }
          v3 = (CSSolid *)HIDWORD(szName_104);
          v14->nCount = (_WORD)v13 + 1;
        }
      }
      v17 = &v14->Blocks[(int)v13 / 16][(int)v13 % 16];
      PointIndexList = CSSolid::CreatePointIndexList(this: v3, face: v17, piPoints: nullptr);
      for ( i = 0; i < v17->nEdges; ++i )
        ++PointIndexList[i];
      v20 = v17->nEdges;
      for ( j = 0; j < v20 - 2; ++j )
      {
        v22 = j == v20 - 3;
        v23 = PointIndexList[j + 2];
        if ( !v22 )
          v23 = -v23;
        v24 = *PointIndexList;
        if ( j != 0 )
          v24 = -v24;
        fprintf(
          str: stream,
          format: "0\nVERTEX\n8\n%s\n10\n0\n20\n0\n30\n0\n70\n128\n71\n%d\n72\n%d\n73\n%d\n",
          &string[4],
          v24,
          PointIndexList[j + 1],
          v23);
        v20 = v17->nEdges;
      }
      LODWORD(szName_104) = ++szName_124a;
      if ( (int)szName_124a >= *(_DWORD *)(HIDWORD(szName_104) + 284) )
        break;
      v13 = szName_124a;
      v3 = (CSSolid *)HIDWORD(szName_104);
    }
  }
  fprintf(str: stream, format: "0\nSEQEND\n8\n%s\n", &string[4]);
}

//------------------------------------------------------------------------------
// Address: 0x100AD510
// Name: public: void CSSolid::Convert(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSSolid::Convert(CSSolid *this, int bFromMap, bool bSkipDisplacementFaces)
{
  if ( bFromMap != 0 )
    CSSolid::FromMapSolid(this, p: nullptr, bSkipDisplacementFaces);
  else
    CSSolid::ToMapSolid(this, p: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100AD540
// Name: public: int CSSolid::SplitFaceByEdges(class CSSEdge __near *,class CSSEdge __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSSolid::SplitFaceByEdges(CSSolid *this, CSSEdge *pEdge1, CSSEdge *pEdge2)
{
  unsigned int v3; // eax
  unsigned int v5; // ecx
  unsigned int v6; // edx
  int HandleInfo; // eax
  CSSFace *v9; // esi
  CSSEdge *v10; // edi
  CSSVertex *v11; // eax
  unsigned int id; // esi
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  int v16; // esi
  int v17; // edx
  int v18; // eax
  CSSFace *v19; // esi
  CSSVertex *v20; // eax
  int p_pos; // eax
  CSSVertex *v22; // ecx
  unsigned int v23; // edx
  CSSEdge *v24; // eax
  CSSVertex *v25; // ecx
  CSSEdge *v26; // eax
  CSSVertex *v27; // edi
  CSSEdge *v28; // eax
  CSSEdge *v29; // eax
  CSSVertex *v30; // edi
  CSSEdge *v31; // eax
  CSSFace *v32; // edi
  unsigned __int8 *v33; // eax
  int nEdges; // edx
  int v35; // esi
  int v36; // edi
  int v37; // eax
  BlockArray<CSSEdge,16,32> *p_m_Edges; // edi
  int v39; // ecx
  int EdgeIndex; // esi
  unsigned int v41; // edi
  CSSEdge *v42; // eax
  unsigned int v43; // ecx
  int v44; // edx
  int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // ecx
  int v48; // esi
  int v49; // ecx
  unsigned int v50; // edi
  int v51; // eax
  int v52; // edi
  const char *nCount; // eax
  int v54; // ecx
  unsigned int v55; // esi
  int v56; // edx
  int v57; // ecx
  int v58; // eax
  int v59; // eax
  int v60; // ecx
  bool v61; // cc
  int v62; // esi
  int v63; // edx
  int v64; // ecx
  unsigned int v65; // esi
  CSSFace *v66; // esi
  CSSEdge *v67; // edi
  int v68; // ecx
  int v69; // edx
  unsigned int v70; // eax
  int v71; // ecx
  int v72; // edi
  int v73; // ecx
  unsigned int v74; // esi
  int v75; // esi
  int v76; // ecx
  int v77; // eax
  const char *v78; // eax
  int v79; // ecx
  unsigned int v80; // edi
  int v81; // eax
  unsigned int v82; // ecx
  int v83; // esi
  __int16 v84; // cx
  unsigned int v85; // edi
  int v86; // edi
  __int16 v87; // cx
  unsigned int v88; // eax
  unsigned int hNewEdges[64]; // [esp+8h] [ebp-15Ch] BYREF
  SSHANDLEINFO pInfo; // [esp+108h] [ebp-5Ch] BYREF
  CSSFace *pNewFace; // [esp+124h] [ebp-40h]
  CSSVertex *pNewVertex2; // [esp+128h] [ebp-3Ch]
  CSSFace *pFace; // [esp+12Ch] [ebp-38h]
  CSSVertex *pNewVertex1; // [esp+130h] [ebp-34h]
  CSSEdge **v95; // [esp+134h] [ebp-30h]
  unsigned int id1; // [esp+138h] [ebp-2Ch]
  unsigned int id2; // [esp+13Ch] [ebp-28h]
  CSSolid *v98; // [esp+140h] [ebp-24h]
  CSSEdge *pNewEdgeMid; // [esp+144h] [ebp-20h]
  int nv1index; // [esp+148h] [ebp-1Ch] BYREF
  int nv2index; // [esp+14Ch] [ebp-18h] BYREF
  CSSFace *pUpdFace; // [esp+150h] [ebp-14h] BYREF
  int iFace; // [esp+154h] [ebp-10h]
  int nNewEdges; // [esp+158h] [ebp-Ch]
  int iNewVertex1; // [esp+15Ch] [ebp-8h] BYREF
  int nVertices; // [esp+160h] [ebp-4h]
  int pEdge1a; // [esp+16Ch] [ebp+8h]
  int pEdge2a; // [esp+170h] [ebp+Ch]

  v3 = pEdge1->Faces[0];
  v5 = pEdge2->Faces[0];
  v98 = this;
  if ( v3 != v5 )
  {
    v6 = pEdge2->Faces[1];
    if ( v3 != v6 )
    {
      v3 = pEdge1->Faces[1];
      if ( v3 != v5 && v3 != v6 )
        return 0;
    }
  }
  HandleInfo = CSSolid::GetHandleInfo(this, &pInfo, id: v3);
  v9 = HandleInfo != 0 ? (CSSFace *)pInfo.pData : nullptr;
  pFace = v9;
  pNewFace = CSSolid::AddFace(this, piNewIndex: nullptr);
  v10 = CSSolid::AddEdge(this, piNewIndex: nullptr);
  pNewEdgeMid = v10;
  pNewVertex1 = CSSolid::AddVertex(this, piNewIndex: &iNewVertex1);
  v11 = CSSolid::AddVertex(this, piNewIndex: (int *)&pUpdFace);
  id = v9->id;
  pNewVertex2 = v11;
  v13 = v10->Faces[0];
  if ( v13 == 0 || v13 == id )
  {
    v10->Faces[0] = id;
  }
  else if ( v10->Faces[1] == 0 )
  {
    v10->Faces[1] = id;
  }
  v14 = pNewFace->id;
  v15 = v10->Faces[0];
  if ( v15 == 0 || v15 == v14 )
  {
    v10->Faces[0] = v14;
  }
  else if ( v10->Faces[1] == 0 )
  {
    v10->Faces[1] = v14;
  }
  qmemcpy(&pNewFace->texture, &pFace->texture, sizeof(pNewFace->texture));
  v16 = iNewVertex1;
  if ( iNewVertex1 >= this->m_Vertices.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)iNewVertex1, this->m_Vertices.nCount);
    BlockArray<CSSVertex,16,32>::SetCount(this: &this->m_Vertices, nObjects: v16 + 1);
  }
  v17 = v16 / 16;
  v18 = v16 % 16;
  v19 = pUpdFace;
  this->m_Vertices.Blocks[v17][v18].pos = pEdge1->ptCenter;
  if ( (int)v19 >= this->m_Vertices.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v19, this->m_Vertices.nCount);
    BlockArray<CSSVertex,16,32>::SetCount(this: &this->m_Vertices, nObjects: (int)&v19->m_bVisible + 1);
  }
  v20 = this->m_Vertices.Blocks[(int)v19 / 16];
  v20[(int)v19 % 16].pos.x = pEdge2->ptCenter.x;
  p_pos = (int)&v20[(int)v19 % 16].pos;
  *(float *)(p_pos + 4) = pEdge2->ptCenter.y;
  v22 = pNewVertex1;
  *(float *)(p_pos + 8) = pEdge2->ptCenter.z;
  v23 = v22->id;
  v24 = pNewEdgeMid;
  v25 = pNewVertex2;
  pNewEdgeMid->hvStart = v23;
  v24->hvEnd = v25->id;
  CSSolid::CalcEdgeCenter(this, pEdge: (Vector *)v24);
  v26 = CSSolid::AddEdge(this, piNewIndex: nullptr);
  v27 = pNewVertex1;
  v26->hvStart = pEdge1->hvStart;
  v26->hvEnd = v27->id;
  CSSolid::CalcEdgeCenter(this, pEdge: (Vector *)v26);
  v28 = CSSolid::AddEdge(this, piNewIndex: nullptr);
  v28->hvStart = pEdge1->hvEnd;
  v28->hvEnd = v27->id;
  CSSolid::CalcEdgeCenter(this, pEdge: (Vector *)v28);
  v29 = CSSolid::AddEdge(this, piNewIndex: nullptr);
  v30 = pNewVertex2;
  v29->hvStart = pEdge2->hvStart;
  v29->hvEnd = v30->id;
  CSSolid::CalcEdgeCenter(this, pEdge: (Vector *)v29);
  v31 = CSSolid::AddEdge(this, piNewIndex: nullptr);
  v31->hvStart = pEdge2->hvEnd;
  v31->hvEnd = v30->id;
  CSSolid::CalcEdgeCenter(this, pEdge: (Vector *)v31);
  v32 = pFace;
  iNewVertex1 = 1;
  iFace = (int)pFace;
  v33 = CSSolid::CreateNewVertexList(this, pFace, pEdge1, pEdge2, &nv1index, &nv2index, pNewVertex1, pNewVertex2);
  nEdges = v32->nEdges;
  pUpdFace = (CSSFace *)v33;
  nVertices = nEdges;
  if ( nv1index != -1 )
    ++nVertices;
  v35 = nv2index;
  v36 = nVertices;
  if ( nv2index != -1 )
    v36 = ++nVertices;
  v37 = 0;
  if ( v36 > 0 )
  {
    p_m_Edges = &this->m_Edges;
    do
    {
      v39 = v37 + 1;
      nNewEdges = v37 + 1;
      if ( v37 + 1 == nVertices )
      {
        v39 = 0;
      }
      else if ( v37 == -2 )
      {
        v39 = nVertices - 1;
      }
      EdgeIndex = CSSolid::GetEdgeIndex(this, v1: *(&pUpdFace->m_bVisible + v37), v2: *(&pUpdFace->m_bVisible + v39));
      if ( EdgeIndex >= p_m_Edges->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)EdgeIndex, p_m_Edges->nCount);
        if ( EdgeIndex + 1 != p_m_Edges->nCount )
        {
          v41 = (EdgeIndex + 1) / 16;
          if ( (int)(16 * v41) < EdgeIndex + 1 )
            ++v41;
          if ( v41 != this->m_Edges.nBlocks )
          {
            if ( v41 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: v41);
          }
          this->m_Edges.nCount = EdgeIndex + 1;
        }
      }
      v42 = &this->m_Edges.Blocks[EdgeIndex / 16][EdgeIndex % 16];
      v43 = pFace->id;
      p_m_Edges = &this->m_Edges;
      if ( v42->Faces[0] == v43 )
        v42->Faces[0] = 0;
      if ( v42->Faces[1] == v43 )
        v42->Faces[1] = 0;
      v37 = nNewEdges;
    }
    while ( nNewEdges < nVertices );
    v35 = nv2index;
    v36 = nVertices;
  }
  v44 = nv1index;
  while ( 2 )
  {
    v45 = 0;
    nNewEdges = 0;
    v46 = v44;
    while ( 1 )
    {
      if ( v46 == v36 )
        v46 = 0;
      if ( v46 == v35 )
        break;
      v47 = v46 + 1;
      id1 = v46 + 1;
      if ( v46 + 1 == v36 )
      {
        v47 = 0;
      }
      else if ( v46 == -2 )
      {
        v47 = v36 - 1;
      }
      this = v98;
      v48 = CSSolid::GetEdgeIndex(this: v98, v1: *(&pUpdFace->m_bVisible + v46), v2: *(&pUpdFace->m_bVisible + v47));
      if ( v48 >= this->m_Edges.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v48, this->m_Edges.nCount);
        v49 = v48 + 1;
        if ( v48 + 1 != this->m_Edges.nCount )
        {
          v50 = v49 / 16;
          if ( 16 * (v49 / 16) < v49 )
            ++v50;
          if ( v50 != this->m_Edges.nBlocks )
          {
            if ( v50 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: v50);
          }
          this->m_Edges.nCount = v48 + 1;
        }
      }
      v95 = &this->m_Edges.Blocks[v48 / 16];
      v51 = nNewEdges;
      v52 = (v48 % 16) << 6;
      hNewEdges[nNewEdges] = *(unsigned int *)((char *)&(*v95)->Faces[2] + v52);
      nNewEdges = v51 + 1;
      if ( v48 >= this->m_Edges.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v48, this->m_Edges.nCount);
        nCount = (const char *)this->m_Edges.nCount;
        v54 = v48 + 1;
        id2 = v48 + 1;
        if ( (const char *)(v48 + 1) != nCount )
        {
          v55 = v54 / 16;
          if ( 16 * (v54 / 16) < v54 )
            ++v55;
          if ( v55 != this->m_Edges.nBlocks )
          {
            if ( v55 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: v55);
            LOWORD(v54) = id2;
          }
          this->m_Edges.nCount = v54;
        }
      }
      v56 = *(_DWORD *)(iFace + 908);
      v57 = *(unsigned int *)((char *)(*v95)->Faces + v52);
      v58 = (int)*v95 + v52;
      if ( v57 == 0 || v57 == v56 )
      {
        *(_DWORD *)(v58 + 52) = v56;
LABEL_77:
        v46 = id1;
        v45 = nNewEdges;
        v36 = nVertices;
        v35 = nv2index;
      }
      else
      {
        if ( *(_DWORD *)(v58 + 56) != 0 )
          goto LABEL_77;
        v45 = nNewEdges;
        v36 = nVertices;
        v35 = nv2index;
        *(_DWORD *)(v58 + 56) = v56;
        v46 = id1;
      }
    }
    hNewEdges[v45] = pNewEdgeMid->id;
    v59 = iFace;
    v60 = v45 + 1;
    *(_DWORD *)(iFace + 512) = v60;
    memcpy(dst: (unsigned __int8 *)(v59 + 32), src: (unsigned __int8 *)hNewEdges, count: 4 * v60);
    if ( iNewVertex1 != 0 )
    {
      v44 = v35;
      v35 = nv1index;
      nv1index = v44;
      nv2index = v35;
      iFace = (int)pNewFace;
      iNewVertex1 = 0;
      continue;
    }
    break;
  }
  operator delete(p: pUpdFace);
  v61 = this->m_nFaces <= 0;
  iFace = 0;
  if ( !v61 )
  {
    do
    {
      v62 = iFace;
      if ( iFace >= this->m_Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)iFace, this->m_Faces.nCount);
        v63 = this->m_Faces.nCount;
        v64 = v62 + 1;
        iNewVertex1 = v62 + 1;
        if ( v62 + 1 != v63 )
        {
          v65 = v64 / 16;
          if ( 16 * (v64 / 16) < v64 )
            ++v65;
          if ( v65 != this->m_Faces.nBlocks )
          {
            if ( v65 > 0xB )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
            BlockArray<CSSFace,16,10>::GetBlocks(this: &this->m_Faces, nNewBlocks: v65);
            LOWORD(v64) = iNewVertex1;
          }
          this->m_Faces.nCount = v64;
        }
      }
      v66 = &this->m_Faces.Blocks[iFace / 16][iFace % 16];
      pUpdFace = v66;
      if ( v66 != pNewFace && v66 != pFace )
      {
        v67 = (CSSEdge *)CSSolid::CreateNewVertexList(
                           this,
                           pFace: v66,
                           pEdge1,
                           pEdge2,
                           &nv1index,
                           &nv2index,
                           pNewVertex1,
                           pNewVertex2);
        pNewEdgeMid = v67;
        if ( v67 != nullptr )
        {
          v68 = v66->nEdges;
          v69 = 0;
          nNewEdges = 0;
          nVertices = v68;
          if ( nv1index != -1 )
            nVertices = ++v68;
          if ( nv2index != -1 )
            nVertices = ++v68;
          v70 = 0;
          if ( v68 > 0 )
          {
            this = v98;
            do
            {
              v71 = v70 + 1;
              id2 = v70 + 1;
              if ( v70 + 1 == nVertices )
              {
                v71 = 0;
              }
              else if ( v70 == -2 )
              {
                v71 = nVertices - 1;
              }
              v72 = CSSolid::GetEdgeIndex(
                      this,
                      v1: *(&pNewEdgeMid->m_bVisible + v70),
                      v2: *(&pNewEdgeMid->m_bVisible + v71));
              if ( v72 >= this->m_Edges.nCount )
              {
                _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v72, this->m_Edges.nCount);
                v73 = v72 + 1;
                if ( v72 + 1 != this->m_Edges.nCount )
                {
                  v74 = v73 / 16;
                  if ( 16 * (v73 / 16) < v73 )
                    ++v74;
                  if ( v74 != this->m_Edges.nBlocks )
                  {
                    if ( v74 > 0x21 )
                      _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                    BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: v74);
                  }
                  this->m_Edges.nCount = v72 + 1;
                }
              }
              iNewVertex1 = pUpdFace->id;
              v95 = &this->m_Edges.Blocks[v72 / 16];
              v75 = (v72 % 16) << 6;
              v76 = *(unsigned int *)((char *)(*v95)->Faces + v75);
              v77 = (int)*v95 + v75;
              if ( v76 == 0 || v76 == iNewVertex1 )
              {
                *(_DWORD *)(v77 + 52) = iNewVertex1;
              }
              else if ( *(_DWORD *)(v77 + 56) == 0 )
              {
                *(_DWORD *)(v77 + 56) = iNewVertex1;
              }
              if ( v72 >= this->m_Edges.nCount )
              {
                _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v72, this->m_Edges.nCount);
                v78 = (const char *)this->m_Edges.nCount;
                v79 = v72 + 1;
                id1 = v72 + 1;
                if ( (const char *)(v72 + 1) != v78 )
                {
                  v80 = v79 / 16;
                  if ( 16 * (v79 / 16) < v79 )
                    ++v80;
                  if ( v80 != this->m_Edges.nBlocks )
                  {
                    if ( v80 > 0x21 )
                      _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                    BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: v80);
                    LOWORD(v79) = id1;
                  }
                  this->m_Edges.nCount = v79;
                }
              }
              v81 = nNewEdges;
              hNewEdges[nNewEdges] = *(unsigned int *)((char *)&(*v95)->Faces[2] + v75);
              nNewEdges = v81 + 1;
              v70 = id2;
            }
            while ( (int)id2 < nVertices );
            v67 = pNewEdgeMid;
            v66 = pUpdFace;
            v69 = nNewEdges;
          }
          v66->nEdges = v69;
          memcpy(dst: (unsigned __int8 *)v66->Edges, src: (unsigned __int8 *)hNewEdges, count: 4 * v69);
          operator delete(p: v67);
        }
      }
      iNewVertex1 = ++iFace;
    }
    while ( iFace < this->m_nFaces );
  }
  v82 = pEdge2->id;
  v83 = 0;
  id1 = pEdge1->id;
  id2 = v82;
  if ( this->m_nEdges > 0 )
  {
    pEdge2a = 1;
    do
    {
      if ( v83 >= this->m_Edges.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v83, this->m_Edges.nCount);
        if ( pEdge2a != this->m_Edges.nCount )
        {
          v84 = pEdge2a;
          v85 = pEdge2a / 16;
          if ( 16 * (pEdge2a / 16) < pEdge2a )
            ++v85;
          if ( v85 != this->m_Edges.nBlocks )
          {
            if ( v85 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: v85);
            v84 = pEdge2a;
          }
          this->m_Edges.nCount = v84;
        }
      }
      v95 = &this->m_Edges.Blocks[v83 / 16];
      v86 = (v83 % 16) << 6;
      if ( *(unsigned int *)((char *)&(*v95)->Faces[2] + v86) == id1 )
        goto LABEL_152;
      if ( v83 >= this->m_Edges.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v83, this->m_Edges.nCount);
        if ( pEdge2a != this->m_Edges.nCount )
        {
          v87 = pEdge2a;
          v88 = pEdge2a / 16;
          pEdge1a = pEdge2a / 16;
          if ( 16 * (pEdge2a / 16) < pEdge2a )
            pEdge1a = ++v88;
          if ( v88 != this->m_Edges.nBlocks )
          {
            if ( v88 > 0x21 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
            BlockArray<CSSEdge,16,32>::GetBlocks(this: &this->m_Edges, nNewBlocks: pEdge1a);
            v87 = pEdge2a;
          }
          this->m_Edges.nCount = v87;
        }
      }
      if ( *(unsigned int *)((char *)&(*v95)->Faces[2] + v86) == id2 )
      {
LABEL_152:
        CSSolid::DeleteEdge(this, iEdge: v83--);
        --pEdge2a;
      }
      ++pEdge2a;
      ++v83;
    }
    while ( v83 < this->m_nEdges );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ADFC0
// Name: public: int CSSolid::SplitFace(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSSolid::SplitFace(CSSolid *this, unsigned int h1, unsigned int h2)
{
  int result; // eax
  int HandleInfo; // eax
  int v6; // eax
  SSHANDLEINFO pInfo; // [esp+4h] [ebp-38h] BYREF
  SSHANDLEINFO hi; // [esp+20h] [ebp-1Ch] BYREF

  CSSolid::GetHandleInfo(this, pInfo: &hi, id: h1);
  result = 0;
  if ( this->m_nFaces != 119 )
  {
    if ( hi.Type == shtEdge )
    {
      HandleInfo = CSSolid::GetHandleInfo(this, &pInfo, id: h2);
      return CSSolid::SplitFaceByEdges(
               this,
               pEdge1: (CSSEdge *)hi.pData,
               pEdge2: HandleInfo != 0 ? (CSSEdge *)pInfo.pData : nullptr);
    }
    else if ( hi.Type == shtVertex )
    {
      v6 = CSSolid::GetHandleInfo(this, &pInfo, id: h2);
      return CSSolid::SplitFaceByVertices(
               this,
               pVertex1: (CSSVertex *)hi.pData,
               pVertex2: v6 != 0 ? (CSSVertex *)pInfo.pData : nullptr);
    }
  }
  return result;
}
