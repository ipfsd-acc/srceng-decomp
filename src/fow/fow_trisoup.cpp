// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fow/fow_trisoup.cpp
// Functions: 6
// ============================================================

#include "fow\fow_trisoup.h"

//------------------------------------------------------------------------------
// Address: 0x101FC120
// Name: private: int CFoW_TriSoupCollection::HorizontalSplitTri(class Vector __near *,int,class Vector __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFoW_TriSoupCollection::HorizontalSplitTri(
        CFoW_TriSoupCollection *this,
        Vector *pInVerts,
        int nVertCount,
        Vector *pOutVerts,
        float flDist,
        float flOnPlaneEpsilon)
{
  int v6; // ebx
  void *v7; // esp
  void *v8; // esp
  int v10; // esi
  float *p_z; // edx
  int v12; // ecx
  _DWORD *v13; // eax
  float v14; // xmm0_4
  int v15; // edx
  int v17; // esi
  int v18; // ecx
  int v19; // edi
  int v20; // edx
  Vector *v21; // eax
  int v22; // esi
  float v23; // xmm1_4
  int i; // ecx
  float v25; // xmm0_4
  _DWORD v26[6]; // [esp+0h] [ebp-38h] BYREF
  _DWORD v27[3]; // [esp+18h] [ebp-20h] BYREF
  Vector v28; // [esp+24h] [ebp-14h]
  float *v29; // [esp+34h] [ebp-4h]
  int v30; // [esp+44h] [ebp+Ch]
  int v31; // [esp+4Ch] [ebp+14h]
  int v33; // [esp+50h] [ebp+18h]

  v6 = nVertCount;
  v7 = alloca(16 * nVertCount);
  v29 = (float *)v26;
  v8 = alloca(16 * nVertCount);
  v10 = 0;
  v28 = vec3_origin;
  v27[0] = 0;
  v27[1] = 0;
  v27[2] = 1065353216;
  memset(&v26[3], 0, 12);
  if ( nVertCount > 0 )
  {
    p_z = &pInVerts->z;
    v12 = (char *)v29 - (char *)v26;
    v13 = v26;
    v31 = (char *)v29 - (char *)v26;
    v10 = nVertCount;
    while ( 1 )
    {
      v14 = (float)((float)((float)(*(p_z - 2) + *(p_z - 1)) * 0.0) + *p_z) - flDist;
      *(float *)((char *)v13 + v12) = v14;
      if ( v14 <= flOnPlaneEpsilon )
        *v13 = (float)-flOnPlaneEpsilon <= v14 ? 2 : 1;
      else
        *v13 = 0;
      ++v26[*v13 + 3];
      p_z += 3;
      ++v13;
      if ( --nVertCount == 0 )
        break;
      v12 = v31;
    }
  }
  v15 = v26[0];
  v29[v10] = *v29;
  v26[v10] = v15;
  if ( v26[3] == 0 )
    return 0;
  v17 = 0;
  v30 = 0;
  if ( v6 > 0 )
  {
    do
    {
      v33 = v17 + 1;
      v18 = v17 % v6;
      v19 = v26[v17 % v6];
      v20 = (v17 + 1) % v6;
      v21 = &pInVerts[v17 % v6];
      if ( v19 == 2 )
      {
        ++v30;
        pOutVerts->x = v21->x;
        pOutVerts->y = v21->y;
        ++pOutVerts;
        pOutVerts[-1].z = v21->z;
      }
      else
      {
        v22 = v26[v20];
        if ( v22 != 2 && v22 != v19 )
        {
          v23 = v29[v18] / (float)(v29[v18] - v29[v20]);
          for ( i = 0; i < 3; ++i )
          {
            v25 = *(float *)&v27[i];
            if ( v25 == 1.0 )
            {
              *(float *)((char *)&v28.x + i * 4) = flDist;
            }
            else if ( v25 == -1.0 )
            {
              *(float *)((char *)&v28.x + i * 4) = -flDist;
            }
            else
            {
              *(float *)((char *)&v28.x + i * 4) = (float)((float)(*(float *)((char *)&v27[i]
                                                                            + (char *)&pInVerts[v20]
                                                                            - (char *)v27)
                                                                 - *(float *)((char *)&v27[i] + (char *)v21
                                                                                              - (char *)v27))
                                                         * v23)
                                                 + *(float *)((char *)&v27[i] + (char *)v21 - (char *)v27);
            }
          }
          ++v30;
          *pOutVerts++ = v28;
        }
      }
      v17 = v33;
    }
    while ( v33 < v6 );
  }
  return v30;
}

//------------------------------------------------------------------------------
// Address: 0x101FC380
// Name: public: void CFoW_TriSoupCollection::RepopulateOccluders(class CFoW __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_TriSoupCollection::RepopulateOccluders(CFoW_TriSoupCollection *this, CFoW *pFoW)
{
  int i; // esi

  for ( i = 0; i < this->m_Occluders.m_Size; ++i )
    CFoW::AddTriSoupOccluder(
      this: pFoW,
      pOccluder: this->m_Occluders.m_Memory.m_pMemory[i],
      nSliceNum: this->m_Occluders.m_Memory.m_pMemory[i]->m_nSliceNum);
}

//------------------------------------------------------------------------------
// Address: 0x101FC420
// Name: public: CFoW_TriSoupCollection::CFoW_TriSoupCollection(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CFoW_TriSoupCollection *__thiscall CFoW_TriSoupCollection::CFoW_TriSoupCollection(
        CFoW_TriSoupCollection *this,
        unsigned int nID)
{
  this->m_Occluders.m_Memory.m_pMemory = nullptr;
  this->m_Occluders.m_Memory.m_nAllocationCount = 0;
  this->m_Occluders.m_Memory.m_nGrowSize = 0;
  this->m_Occluders.m_Size = 0;
  this->m_Occluders.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FC440
// Name: public: void CFoW_TriSoupCollection::Clear(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFoW_TriSoupCollection::Clear(CFoW_TriSoupCollection *this)
{
  CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int>>::PurgeAndDeleteElements(this: &this->m_Occluders);
}

//------------------------------------------------------------------------------
// Address: 0x101FC450
// Name: public: CFoW_TriSoupCollection::~CFoW_TriSoupCollection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_TriSoupCollection::~CFoW_TriSoupCollection(CFoW_TriSoupCollection *this)
{
  CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int>>::PurgeAndDeleteElements(this: &this->m_Occluders);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101FC460
// Name: public: void CFoW_TriSoupCollection::AddTri(class CFoW __near *,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_TriSoupCollection::AddTri(
        CFoW_TriSoupCollection *this,
        CFoW *pFoW,
        Vector *vPointA,
        Vector *vPointB,
        Vector *vPointC)
{
  const Vector *v5; // ebx
  const Vector *v6; // edi
  int v8; // ebx
  float v9; // xmm0_4
  CFoW_LineOccluder *v10; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CFoW_LineOccluder **m_pMemory; // ecx
  int v14; // eax
  CFoW_LineOccluder **v15; // eax
  Vector ey; // [esp+Ch] [ebp-B0h] BYREF
  float v17; // [esp+18h] [ebp-A4h]
  float v18; // [esp+1Ch] [ebp-A0h]
  Vector vOutVerts[8]; // [esp+24h] [ebp-98h] BYREF
  int nGridSize; // [esp+84h] [ebp-38h]
  float flIntercept; // [esp+88h] [ebp-34h]
  Vector vNormal; // [esp+8Ch] [ebp-30h]
  Vector vVerts[3]; // [esp+98h] [ebp-24h] BYREF

  v5 = vPointB;
  v6 = vPointA;
  vOutVerts[7].z = vPointA->x;
  nGridSize = LODWORD(vPointA->y);
  flIntercept = vPointA->z;
  vNormal = *vPointB;
  vVerts[0] = *vPointC;
  CFoW::GetVerticalGridInfo(
    this: pFoW,
    nBottomZ: (int *)&vVerts[1].z,
    nGridSize: (int *)&vOutVerts[6],
    nGridUnits: (int *)&vPointA,
    pVerticalLevels: (float **)&vPointB);
  ComputeTrianglePlane(v1: v6, v2: v5, v3: vPointC, normal: (Vector *)&vOutVerts[6].z, intercept: &vOutVerts[6].y);
  vVerts[2].x = vOutVerts[6].z;
  vVerts[2].y = vOutVerts[7].x;
  vVerts[2].z = 0.0;
  VectorNormalize(vec: &vVerts[2]);
  v8 = 0;
  vVerts[1].x = vVerts[2].x;
  for ( vVerts[1].y = vVerts[2].y; v8 < (int)vPointA; ++v8 )
  {
    v9 = (float)(int)(float)(*(&vPointB->x + v8) + 16.0);
    LODWORD(vVerts[1].z) = (int)(float)(*(&vPointB->x + v8) + 16.0);
    if ( CFoW_TriSoupCollection::HorizontalSplitTri(
           this,
           pInVerts: (Vector *)&vOutVerts[7].z,
           nVertCount: 3,
           pOutVerts: &ey,
           flDist: v9,
           flOnPlaneEpsilon: 0.0) == 2 )
    {
      v10 = (CFoW_LineOccluder *)operator new(nSize: 0x20u);
      if ( v10 != nullptr )
        vPointC = (Vector *)CFoW_LineOccluder::CFoW_LineOccluder(
                              this: v10,
                              bx: ey.x,
                              by: ey.y,
                              ex: v17,
                              ey: v18,
                              vNormal: (Vector2D *)&vVerts[1],
                              nSliceNum: v8);
      else
        vPointC = nullptr;
      m_Size = this->m_Occluders.m_Size;
      m_nAllocationCount = this->m_Occluders.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Occluders.m_Size;
      m_pMemory = this->m_Occluders.m_Memory.m_pMemory;
      v14 = this->m_Occluders.m_Size - m_Size - 1;
      this->m_Occluders.m_pElements = this->m_Occluders.m_Memory.m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
      v15 = &this->m_Occluders.m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = (CFoW_LineOccluder *)vPointC;
      CFoW::AddTriSoupOccluder(this: pFoW, pOccluder: (CFoW_LineOccluder *)vPointC, nSliceNum: v8);
    }
  }
}
