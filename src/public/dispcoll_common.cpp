// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/dispcoll_common.cpp
// Functions: 41
// ============================================================

#include "public\dispcoll_common.h"

//------------------------------------------------------------------------------
// Address: 0x1015EFA0
// Name: protected: bool CDispCollTree::ResolveRayPlaneIntersect(float,float,class Vector const __near &,float,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::ResolveRayPlaneIntersect(
        CDispCollTree *this,
        float flStart,
        float flEnd,
        const Vector *vecNormal,
        float flDist,
        CDispCollHelper *pHelper)
{
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4

  if ( flStart > 0.0 && flEnd > 0.0 )
    return 0;
  if ( flStart >= 0.0 || flEnd >= 0.0 )
  {
    v7 = flStart - flEnd;
    if ( flStart < 0.0 || flEnd > 0.0 )
    {
      if ( (float)(flStart - flEnd) == 0.0 )
        v9 = 0.0;
      else
        v9 = (float)(flStart + 0.03125) / v7;
      if ( pHelper->m_flEndFrac > v9 )
        pHelper->m_flEndFrac = v9;
    }
    else
    {
      if ( (float)(flStart - flEnd) == 0.0 )
        v8 = 0.0;
      else
        v8 = (float)(flStart - 0.03125) / v7;
      if ( v8 > pHelper->m_flStartFrac )
      {
        pHelper->m_flStartFrac = v8;
        pHelper->m_vecImpactNormal = *vecNormal;
        pHelper->m_flImpactDist = flDist;
        return 1;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F060
// Name: protected: bool CDispCollTree::FacePlane(struct Ray_t const __near &,class Vector const __near &,class CDispCollTri __near *,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::FacePlane(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *rayDir,
        CDispCollTri *pTri,
        CDispCollHelper *pHelper)
{
  float x; // xmm6_4
  float v7; // xmm0_4
  float y; // xmm3_4
  float v9; // xmm5_4
  float z; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float flDist; // [esp+24h] [ebp+8h]

  x = ray->m_Extents.x;
  v7 = pTri->m_vecNormal.x;
  if ( v7 >= 0.0 )
    x = -x;
  y = pTri->m_vecNormal.y;
  v9 = ray->m_Extents.y;
  if ( y >= 0.0 )
    v9 = -v9;
  z = pTri->m_vecNormal.z;
  v11 = ray->m_Extents.z;
  if ( z >= 0.0 )
    v11 = -v11;
  flDist = pTri->m_flDist;
  v12 = flDist - (float)((float)((float)(y * v9) + (float)(v7 * x)) + (float)(z * v11));
  return CDispCollTree::ResolveRayPlaneIntersect(
           this,
           flStart: (float)((float)((float)(y * ray->m_Start.y) + (float)(v7 * ray->m_Start.x)) + (float)(z * ray->m_Start.z))
         - v12,
           flEnd: (float)((float)((float)(v7 * (float)(ray->m_Start.x + ray->m_Delta.x))
                         + (float)(y * (float)(ray->m_Delta.y + ray->m_Start.y)))
                 + (float)(z * (float)(ray->m_Delta.z + ray->m_Start.z)))
         - v12,
           vecNormal: &pTri->m_vecNormal,
           flDist,
           pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x1015F170
// Name: public: bool CDispCollTree::PointInBounds(class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDispCollTree::PointInBounds(
        CDispCollTree *this,
        const Vector *vecBoxCenter,
        const Vector *vecBoxMin,
        const Vector *vecBoxMax,
        bool bPoint)
{
  float y; // xmm4_4
  float z; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  Vector vecExpandBounds[2]; // [esp+0h] [ebp-18h] BYREF

  if ( bPoint )
    return IsPointInBox(pt: vecBoxCenter, boxMin: &this->m_mins, boxMax: &this->m_maxs);
  y = this->m_mins.y;
  z = this->m_mins.z;
  v8 = (float)(vecBoxMax->y - vecBoxMin->y) * 0.5;
  v9 = (float)(vecBoxMax->x - vecBoxMin->x) * 0.5;
  v10 = (float)(vecBoxMax->z - vecBoxMin->z) * 0.5;
  vecExpandBounds[0].x = this->m_mins.x - v9;
  v11 = this->m_maxs.x + v9;
  v12 = y - v8;
  v13 = this->m_maxs.y + v8;
  v14 = this->m_maxs.z + v10;
  vecExpandBounds[0].y = v12;
  vecExpandBounds[0].z = z - v10;
  vecExpandBounds[1].x = v11;
  vecExpandBounds[1].y = v13;
  vecExpandBounds[1].z = v14;
  return IsPointInBox(pt: vecBoxCenter, boxMin: vecExpandBounds, boxMax: &vecExpandBounds[1]);
}

//------------------------------------------------------------------------------
// Address: 0x1015F240
// Name: public: virtual void CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::Lock(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015F280
// Name: public: virtual bool CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::TryLock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::TryLock(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this)
{
  DWORD CurrentThreadId; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_mutex, CurrentThreadId, 0) != 0 )
  {
    return 0;
  }
  ++this->m_mutex.m_depth;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F2B0
// Name: public: virtual void CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::Unlock(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this)
{
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)&this->m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1015F3B0
// Name: public: struct memhandle_t__ __near * CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::CreateResource(class CDispCollTree __near * const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::CreateResource(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this,
        CDispCollTree *const *createParams,
        bool bCreateLocked)
{
  _DWORD *v4; // edi
  unsigned __int16 Handle; // ax
  memhandle_t__ *v6; // edi

  CDataManagerBase::EnsureCapacity(
    this,
    size: 18 * (*createParams)->m_aTrisCache.m_Size + 12 * (*createParams)->m_aEdgePlanes.m_Size);
  v4 = *createParams;
  this->Lock(this);
  Handle = CDataManagerBase::CreateHandle(this, bCreateLocked);
  v6 = CDataManagerBase::StoreResourceInHandle(
         this,
         memoryIndex: Handle,
         pStore: v4,
         realSize: 18 * v4[47] + 12 * v4[52]);
  this->Unlock(this);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1015F430
// Name: private: virtual unsigned int CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::GetRealSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::GetRealSize(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this,
        _DWORD *pStore)
{
  return 18 * pStore[47] + 12 * pStore[52];
}

//------------------------------------------------------------------------------
// Address: 0x1015F460
// Name: public: void CDispCollTri::CalcPlane(class CDispVector<class Vector> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTri::CalcPlane(CDispCollTri *this, CDispVector<Vector> *m_aVerts)
{
  int v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  Vector *p_m_vecNormal; // edi
  __int16 v11; // cx
  int i; // ecx

  v3 = this->m_TriData[1].m_IndexDummy & 0x1FF;
  v4 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].z
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v5 = m_aVerts->m_Memory.m_pMemory[v3].y - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v6 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].y
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v7 = m_aVerts->m_Memory.m_pMemory[v3].z - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v8 = m_aVerts->m_Memory.m_pMemory[v3].x - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v9 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].x
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  p_m_vecNormal = &this->m_vecNormal;
  this->m_vecNormal.x = (float)(v6 * v7) - (float)(v4 * v5);
  this->m_vecNormal.y = (float)(v4 * v8) - (float)(v7 * v9);
  this->m_vecNormal.z = (float)(v5 * v9) - (float)(v6 * v8);
  VectorNormalize(vec: &this->m_vecNormal);
  v11 = *((_WORD *)this + 3) & 0xFFC0 | 0x28;
  this->m_flDist = (float)((float)(m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y
                                 * this->m_vecNormal.y)
                         + (float)(this->m_vecNormal.x
                                 * m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x))
                 + (float)(m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z * this->m_vecNormal.z);
  *((_WORD *)this + 3) = v11;
  for ( i = 0; i < 3; ++i )
  {
    if ( p_m_vecNormal->x < 0.0 )
      *((_WORD *)this + 3) |= (1 << i) & 7;
    if ( p_m_vecNormal->x == 1.0 )
      *((_WORD *)this + 3) ^= (*((_WORD *)this + 3) ^ (8 * i)) & 0x38;
    p_m_vecNormal = (Vector *)((char *)p_m_vecNormal + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015F5D0
// Name: public: void CDispCollTri::FindMinMax(class CDispVector<class Vector> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTri::FindMinMax(CDispCollTri *this, CDispVector<Vector> *m_aVerts)
{
  Vector *m_pMemory; // eax
  float x; // xmm0_4
  char v4; // si
  float v5; // xmm1_4
  int v6; // edi
  float v7; // xmm2_4
  float v8; // xmm0_4
  char v9; // al
  __int16 v10; // ax
  unsigned __int16 m_IndexDummy; // si
  unsigned __int16 v12; // ax
  Vector *v13; // edx
  float y; // xmm2_4
  int v15; // esi
  char v16; // di
  float v17; // xmm0_4
  float v18; // xmm0_4
  int v19; // esi
  char v20; // al
  unsigned __int16 v21; // ax
  Vector *v22; // edx
  char v23; // di
  float z; // xmm0_4
  float v25; // xmm0_4
  char v26; // al

  m_pMemory = m_aVerts->m_Memory.m_pMemory;
  x = m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v4 = 0;
  if ( x > m_aVerts->m_Memory.m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x )
  {
    x = m_aVerts->m_Memory.m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x;
    v4 = 1;
  }
  if ( x > m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].x )
    v4 = 2;
  v5 = m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x;
  v6 = this->m_TriData[2].m_IndexDummy & 0x1FF;
  v7 = m_pMemory[v6].x;
  v8 = m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v9 = 0;
  if ( v5 > v8 )
  {
    v8 = v5;
    v9 = 1;
  }
  if ( v7 > v8 )
    v9 = 2;
  v10 = (v4 & 3 | (unsigned __int16)(4 * (v9 & 3))) << 9;
  m_IndexDummy = this->m_TriData[1].m_IndexDummy;
  v12 = this->m_TriData[0].m_IndexDummy & 0xE1FF | v10;
  this->m_TriData[0].m_IndexDummy = v12;
  v13 = m_aVerts->m_Memory.m_pMemory;
  y = m_aVerts->m_Memory.m_pMemory[v6].y;
  v15 = m_IndexDummy & 0x1FF;
  v16 = 0;
  v17 = m_aVerts->m_Memory.m_pMemory[v12 & 0x1FF].y;
  if ( v17 > m_aVerts->m_Memory.m_pMemory[v15].y )
  {
    v17 = m_aVerts->m_Memory.m_pMemory[v15].y;
    v16 = 1;
  }
  if ( v17 > y )
    v16 = 2;
  v18 = v13[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v19 = this->m_TriData[2].m_IndexDummy & 0x1FF;
  v20 = 0;
  if ( v13[this->m_TriData[1].m_IndexDummy & 0x1FF].y > v18 )
  {
    v18 = v13[this->m_TriData[1].m_IndexDummy & 0x1FF].y;
    v20 = 1;
  }
  if ( v13[v19].y > v18 )
    v20 = 2;
  v21 = this->m_TriData[1].m_IndexDummy & 0xE1FF | ((v16 & 3 | (unsigned __int16)(4 * (v20 & 3))) << 9);
  this->m_TriData[1].m_IndexDummy = v21;
  v22 = m_aVerts->m_Memory.m_pMemory;
  v23 = 0;
  z = m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  if ( z > m_aVerts->m_Memory.m_pMemory[v21 & 0x1FF].z )
  {
    z = m_aVerts->m_Memory.m_pMemory[v21 & 0x1FF].z;
    v23 = 1;
  }
  if ( z > m_aVerts->m_Memory.m_pMemory[v19].z )
    v23 = 2;
  v25 = v22[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v26 = 0;
  if ( v22[this->m_TriData[1].m_IndexDummy & 0x1FF].z > v25 )
  {
    v25 = v22[this->m_TriData[1].m_IndexDummy & 0x1FF].z;
    v26 = 1;
  }
  if ( v22[this->m_TriData[2].m_IndexDummy & 0x1FF].z > v25 )
    v26 = 2;
  this->m_TriData[2].m_IndexDummy = this->m_TriData[2].m_IndexDummy & 0xE1FF
                                  | ((v23 & 3 | (unsigned __int16)(4 * (v26 & 3))) << 9);
}

//------------------------------------------------------------------------------
// Address: 0x1015F810
// Name: protected: bool CDispCollTree::EdgeCrossAxis<0>(struct Ray_t const __near &,unsigned short,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::EdgeCrossAxis<0>(
        CDispCollTree *this,
        const Ray_t *ray,
        unsigned __int16 iPlane,
        CDispCollHelper *pHelper)
{
  Vector *m_pMemory; // edx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  Vector flStart; // [esp+0h] [ebp-Ch] BYREF

  if ( iPlane == 0xFFFF )
    return 1;
  m_pMemory = this->m_aEdgePlanes.m_Memory.m_pMemory;
  if ( (iPlane & 0x8000) != 0 )
  {
    x = -m_pMemory[iPlane & 0x7FFF].x;
    y = -m_pMemory[iPlane & 0x7FFF].y;
    z = -m_pMemory[iPlane & 0x7FFF].z;
  }
  else
  {
    x = m_pMemory[iPlane].x;
    y = m_pMemory[iPlane].y;
    z = m_pMemory[iPlane].z;
  }
  v9 = ray->m_Extents.y;
  flStart.z = z;
  flStart.y = y;
  flStart.x = 0.0;
  if ( y >= 0.0 )
    v9 = -v9;
  v10 = ray->m_Extents.z;
  if ( z >= 0.0 )
    v10 = -v10;
  return CDispCollTree::ResolveRayPlaneIntersect(
           this,
           flStart: (float)((float)(y * ray->m_Start.y) + (float)(z * ray->m_Start.z))
         - (float)(x - (float)((float)(v10 * z) + (float)(v9 * y))),
           flEnd: (float)((float)((float)(ray->m_Delta.z + ray->m_Start.z) * z)
                 + (float)((float)(ray->m_Delta.y + ray->m_Start.y) * y))
         - (float)(x - (float)((float)(v10 * z) + (float)(v9 * y))),
           vecNormal: &flStart,
           flDist: x,
           pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x1015F940
// Name: protected: bool CDispCollTree::EdgeCrossAxis<1>(struct Ray_t const __near &,unsigned short,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::EdgeCrossAxis<1>(
        CDispCollTree *this,
        const Ray_t *ray,
        unsigned __int16 iPlane,
        CDispCollHelper *pHelper)
{
  Vector *m_pMemory; // edx
  float x; // xmm5_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  Vector flStart; // [esp+0h] [ebp-Ch] BYREF

  if ( iPlane == 0xFFFF )
    return 1;
  m_pMemory = this->m_aEdgePlanes.m_Memory.m_pMemory;
  if ( (iPlane & 0x8000) != 0 )
  {
    x = -m_pMemory[iPlane & 0x7FFF].x;
    y = -m_pMemory[iPlane & 0x7FFF].y;
    z = -m_pMemory[iPlane & 0x7FFF].z;
  }
  else
  {
    x = m_pMemory[iPlane].x;
    y = m_pMemory[iPlane].y;
    z = m_pMemory[iPlane].z;
  }
  v9 = ray->m_Extents.z;
  flStart.z = z;
  flStart.x = x;
  flStart.y = 0.0;
  if ( z >= 0.0 )
    v9 = -v9;
  v10 = ray->m_Extents.x;
  if ( x >= 0.0 )
    v10 = -v10;
  return CDispCollTree::ResolveRayPlaneIntersect(
           this,
           flStart: (float)((float)(z * ray->m_Start.z) + (float)(ray->m_Start.x * x))
         - (float)(y - (float)((float)(v9 * z) + (float)(v10 * x))),
           flEnd: (float)((float)((float)(ray->m_Delta.z + ray->m_Start.z) * z)
                 + (float)((float)(ray->m_Delta.x + ray->m_Start.x) * x))
         - (float)(y - (float)((float)(v9 * z) + (float)(v10 * x))),
           vecNormal: &flStart,
           flDist: y,
           pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x1015FA60
// Name: protected: bool CDispCollTree::EdgeCrossAxis<2>(struct Ray_t const __near &,unsigned short,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::EdgeCrossAxis<2>(
        CDispCollTree *this,
        const Ray_t *ray,
        unsigned __int16 iPlane,
        CDispCollHelper *pHelper)
{
  Vector *m_pMemory; // edx
  float x; // xmm4_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  Vector flStart; // [esp+0h] [ebp-Ch] BYREF

  if ( iPlane == 0xFFFF )
    return 1;
  m_pMemory = this->m_aEdgePlanes.m_Memory.m_pMemory;
  if ( (iPlane & 0x8000) != 0 )
  {
    x = -m_pMemory[iPlane & 0x7FFF].x;
    y = -m_pMemory[iPlane & 0x7FFF].y;
    z = -m_pMemory[iPlane & 0x7FFF].z;
  }
  else
  {
    x = m_pMemory[iPlane].x;
    y = m_pMemory[iPlane].y;
    z = m_pMemory[iPlane].z;
  }
  v9 = ray->m_Extents.x;
  flStart.y = y;
  flStart.x = x;
  flStart.z = 0.0;
  if ( x >= 0.0 )
    v9 = -v9;
  v10 = ray->m_Extents.y;
  if ( y >= 0.0 )
    v10 = -v10;
  return CDispCollTree::ResolveRayPlaneIntersect(
           this,
           flStart: (float)((float)(y * ray->m_Start.y) + (float)(ray->m_Start.x * x))
         - (float)(z - (float)((float)(v10 * y) + (float)(v9 * x))),
           flEnd: (float)((float)((float)(ray->m_Delta.y + ray->m_Start.y) * y)
                 + (float)((float)(ray->m_Delta.x + ray->m_Start.x) * x))
         - (float)(z - (float)((float)(v10 * y) + (float)(v9 * x))),
           vecNormal: &flStart,
           flDist: z,
           pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x1015FDF0
// Name: protected: void CDispCollTree::AABBTree_GenerateBoxes_r(int,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDispCollTree::AABBTree_GenerateBoxes_r(
        CDispCollTree *this,
        int nodeIndex,
        Vector *pMins,
        Vector *pMaxs)
{
  int m_Size; // ecx
  const CDispCollTri *v7; // eax
  CDispCollNode *m_pMemory; // eax
  int v9; // ecx
  __m128 x; // xmm1
  __m128 y; // xmm2
  CDispCollNode *v12; // eax
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  CDispCollNode *v18; // edx
  __m128 v19; // xmm1
  int p_m_maxs; // eax
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  _BYTE childMaxs[52]; // [esp+8h] [ebp-6Ch] OVERLAPPED BYREF
  _BYTE childMins[52]; // [esp+3Ch] [ebp-38h] OVERLAPPED BYREF
  int i; // [esp+70h] [ebp-4h]
  int nodeIndexa; // [esp+7Ch] [ebp+8h]
  const CDispCollTri *tria; // [esp+84h] [ebp+10h]
  const CDispCollTri *tri; // [esp+84h] [ebp+10h]

  ClearBounds(mins: pMins, maxs: pMaxs);
  m_Size = this->m_nodes.m_Size;
  if ( nodeIndex < m_Size )
  {
    i = 4 * nodeIndex + 1;
    v7 = nullptr;
    for ( tri = nullptr; ; v7 = tri )
    {
      CDispCollTree::AABBTree_GenerateBoxes_r(
        this,
        nodeIndex: i,
        pMins: (Vector *)&childMins[(_DWORD)v7],
        pMaxs: (Vector *)&childMaxs[(_DWORD)v7]);
      AddPointToBounds(v: (const Vector *)&childMins[(_DWORD)tri], mins: pMins, maxs: pMaxs);
      AddPointToBounds(v: (const Vector *)&childMaxs[(_DWORD)tri], mins: pMins, maxs: pMaxs);
      ++i;
      tri = (const CDispCollTri *)((char *)tri + 12);
      if ( (int)tri >= 48 )
        break;
    }
    m_pMemory = this->m_nodes.m_Memory.m_pMemory;
    v9 = nodeIndex;
    m_pMemory[v9].m_mins.x = *(__m128 *)childMins;
    x = m_pMemory[nodeIndex].m_mins.x;
    m_pMemory[v9].m_mins.y = *(__m128 *)&childMins[12];
    m_pMemory[v9].m_mins.z = *(__m128 *)&childMins[24];
    y = m_pMemory[nodeIndex].m_mins.y;
    v12 = &m_pMemory[nodeIndex];
    v13 = _mm_shuffle_ps(x, y, 68);
    v14 = _mm_shuffle_ps(x, y, 238);
    z = v12->m_mins.z;
    v16 = _mm_shuffle_ps(z, *(__m128 *)&childMins[36], 238);
    v17 = _mm_shuffle_ps(z, *(__m128 *)&childMins[36], 68);
    v12->m_mins.x = _mm_shuffle_ps(v13, v17, 136);
    v12->m_mins.y = _mm_shuffle_ps(v13, v17, 221);
    v12->m_mins.z = _mm_shuffle_ps(v14, v16, 136);
    v18 = this->m_nodes.m_Memory.m_pMemory;
    v18[v9].m_maxs.x = *(__m128 *)childMaxs;
    v19 = v18[nodeIndex].m_maxs.x;
    p_m_maxs = (int)&v18[nodeIndex].m_maxs;
    *(_OWORD *)(p_m_maxs + 16) = *(_OWORD *)&childMaxs[12];
    *(_OWORD *)(p_m_maxs + 32) = *(_OWORD *)&childMaxs[24];
    v21 = v18[nodeIndex].m_maxs.y;
    v22 = _mm_shuffle_ps(v19, v21, 68);
    v23 = _mm_shuffle_ps(v19, v21, 238);
    v24 = _mm_shuffle_ps(v18[nodeIndex].m_maxs.z, *(__m128 *)&childMaxs[36], 68);
    v25 = _mm_shuffle_ps(v18[nodeIndex].m_maxs.z, *(__m128 *)&childMaxs[36], 238);
    *(__m128 *)p_m_maxs = _mm_shuffle_ps(v22, v24, 136);
    *(__m128 *)(p_m_maxs + 16) = _mm_shuffle_ps(v22, v24, 221);
    *(__m128 *)(p_m_maxs + 32) = _mm_shuffle_ps(v23, v25, 136);
  }
  else
  {
    nodeIndexa = 2 * (nodeIndex - m_Size);
    for ( i = 2; i != 0; --i )
    {
      tria = &this->m_aTris.m_Memory.m_pMemory[this->m_leaves.m_Memory.m_pMemory->m_tris[nodeIndexa]];
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[0].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[1].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[2].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      ++nodeIndexa;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160000
// Name: protected: void CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(struct Ray_t const __near &,class Vector const __near &,int,struct RayDispOutput_t __near &,class CDispCollTri __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(
        CDispCollTree *this@<ecx>,
        float a2@<ebp>,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        int iNode,
        RayDispOutput_t *output,
        CDispCollTri **pImpactTri)
{
  CDispCollTree *v7; // esi
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  float v12; // edx
  int v13; // edi
  __m128 v14; // xmm7
  __m128 v15; // xmm6
  int v16; // ecx
  __m128 *p_x; // eax
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm3
  __m128 v24; // xmm7
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  CDispCollLeaf *m_pMemory; // ecx
  int v30; // edx
  int v31; // eax
  CDispCollTri *v32; // ecx
  CDispCollTri *v33; // esi
  CDispCollTri *v34; // ecx
  float v35; // xmm2_4
  CDispCollTri *v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  CDispCollTri *v39; // xmm0_4
  float v40; // xmm1_4
  _BYTE v41[1552]; // [esp-Ch] [ebp-65Ch] OVERLAPPED
  __m128 v42; // [esp+604h] [ebp-4Ch]
  CDispCollTri *v43; // [esp+62Ch] [ebp-24h]
  CDispCollTree *v44; // [esp+630h] [ebp-20h]
  float v45; // [esp+634h] [ebp-1Ch] BYREF
  CDispCollTri *pTri1; // [esp+638h] [ebp-18h] BYREF
  float v47; // [esp+63Ch] [ebp-14h] BYREF
  float flU; // [esp+640h] [ebp-10h]
  float flV; // [esp+644h] [ebp-Ch]
  float flT; // [esp+648h] [ebp-8h]
  float retaddr; // [esp+650h] [ebp+0h]

  flV = a2;
  flT = retaddr;
  v7 = this;
  v44 = this;
  *(__m128 *)&v41[96] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->x), (__m128)LODWORD(vecInvDelta->x), 0);
  *(__m128 *)&v41[112] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->y), (__m128)LODWORD(vecInvDelta->y), 0);
  *(__m128 *)&v41[128] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->z), (__m128)LODWORD(vecInvDelta->z), 0);
  *(__m128 *)&v41[16] = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.y), (__m128)LODWORD(ray->m_Start.y), 0);
  v9 = 0;
  v9.m128_f32[0] = ray->m_Extents.x + 0.03125;
  *(__m128 *)&v41[48] = _mm_shuffle_ps(v9, v9, 0);
  v10 = 0;
  v10.m128_f32[0] = ray->m_Extents.y + 0.03125;
  *(__m128 *)&v41[64] = _mm_shuffle_ps(v10, v10, 0);
  v11 = 0;
  v12 = 0.0;
  v11.m128_f32[0] = ray->m_Extents.z + 0.03125;
  v13 = 0;
  v14 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.x), (__m128)LODWORD(ray->m_Start.x), 0);
  v15 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.z), (__m128)LODWORD(ray->m_Start.z), 0);
  *(__m128 *)v41 = v14;
  *(__m128 *)&v41[32] = v15;
  *(__m128 *)&v41[80] = _mm_shuffle_ps(v11, v11, 0);
  *(_DWORD *)&v41[144] = iNode;
  *(_DWORD *)&v41[1520] = 0;
  while ( 1 )
  {
    v16 = *(_DWORD *)&v41[4 * LODWORD(v12) + 144];
    if ( v16 >= v7->m_nodes.m_Size )
      break;
    p_x = &v7->m_nodes.m_Memory.m_pMemory[v16].m_mins.x;
    ++LODWORD(v12);
    v18 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(p_x[4], *(__m128 *)&v41[16]), *(__m128 *)&v41[64]), *(__m128 *)&v41[112]);
    v19 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(*p_x, v14), *(__m128 *)&v41[48]), *(__m128 *)&v41[96]);
    v20 = _mm_sub_ps(_mm_sub_ps(p_x[2], v15), *(__m128 *)&v41[80]);
    v21 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(p_x[5], v15), *(__m128 *)&v41[80]), *(__m128 *)&v41[128]);
    v22 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(p_x[1], *(__m128 *)&v41[16]), *(__m128 *)&v41[64]), *(__m128 *)&v41[112]);
    *(__m128 *)&v41[1536] = _mm_add_ps(_mm_sub_ps(p_x[3], v14), *(__m128 *)&v41[48]);
    v23 = _mm_mul_ps(v20, *(__m128 *)&v41[128]);
    v24 = _mm_mul_ps(*(__m128 *)&v41[1536], *(__m128 *)&v41[96]);
    v42 = v18;
    v25 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_max_ps(_mm_max_ps(_mm_min_ps(v19, v24), _mm_min_ps(v22, v18)), _mm_min_ps(v23, v21)),
                Four_Zeros),
              _mm_min_ps(
                _mm_min_ps(_mm_min_ps(_mm_max_ps(v19, v24), _mm_max_ps(v22, v18)), _mm_max_ps(v23, v21)),
                Four_Ones)));
    flU = v12;
    if ( v25 != 0 )
    {
      v26 = 4 * v16 + 1;
      if ( (v25 & 1) != 0 )
      {
        *(_DWORD *)&v41[1520] = v13 + 1;
        *(_DWORD *)&v41[4 * *(_DWORD *)&v41[1520] + 144] = v26;
        v13 = *(_DWORD *)&v41[1520];
      }
      if ( (v25 & 2) != 0 )
      {
        *(_DWORD *)&v41[1520] = v13 + 1;
        *(_DWORD *)&v41[4 * *(_DWORD *)&v41[1520] + 144] = v26 + 1;
        v13 = *(_DWORD *)&v41[1520];
        v12 = flU;
      }
      if ( (v25 & 4) != 0 )
      {
        *(_DWORD *)&v41[1520] = v13 + 1;
        *(_DWORD *)&v41[4 * *(_DWORD *)&v41[1520] + 144] = v26 + 2;
        v13 = *(_DWORD *)&v41[1520];
        v12 = flU;
      }
      if ( (v25 & 8) != 0 )
      {
        *(_DWORD *)&v41[1520] = v13 + 1;
        *(_DWORD *)&v41[4 * *(_DWORD *)&v41[1520] + 144] = v26 + 3;
        v13 = *(_DWORD *)&v41[1520];
      }
    }
    if ( SLODWORD(v12) > v13 )
    {
      v27 = LODWORD(v12);
      flU = v12;
      goto LABEL_15;
    }
    v14 = *(__m128 *)v41;
    v15 = *(__m128 *)&v41[32];
  }
  v27 = LODWORD(v12);
  flU = v12;
LABEL_15:
  if ( SLODWORD(v12) <= v13 )
  {
    do
    {
      v28 = *(_DWORD *)&v41[4 * v27 + 144] - v7->m_nodes.m_Size;
      m_pMemory = v7->m_leaves.m_Memory.m_pMemory;
      v30 = m_pMemory[v28].m_tris[0];
      v31 = m_pMemory[v28].m_tris[1];
      v32 = v7->m_aTris.m_Memory.m_pMemory;
      v33 = &v32[v30];
      LOWORD(v30) = v33->m_TriData[0].m_IndexDummy;
      v34 = &v32[v31];
      LOWORD(v31) = v33->m_TriData[1].m_IndexDummy;
      v43 = v34;
      if ( ComputeIntersectionBarycentricCoordinates(
             ray,
             v1: &v44->m_aVerts.m_Memory.m_pMemory[v30 & 0x1FF],
             v2: &v44->m_aVerts.m_Memory.m_pMemory[v33->m_TriData[2].m_IndexDummy & 0x1FF],
             v3: &v44->m_aVerts.m_Memory.m_pMemory[v31 & 0x1FF],
             u: &v45,
             v: (float *)&pTri1,
             t: &v47) )
      {
        v35 = v45;
        if ( v45 >= 0.0 )
        {
          v36 = pTri1;
          if ( *(float *)&pTri1 >= 0.0 && (float)(v45 + *(float *)&pTri1) <= 1.0 )
          {
            v37 = v47;
            if ( v47 > 0.0 && output->dist > v47 )
            {
              *pImpactTri = v33;
              output->u = v35;
              LODWORD(output->v) = v36;
              output->dist = v37;
            }
          }
        }
      }
      v7 = v44;
      if ( ComputeIntersectionBarycentricCoordinates(
             ray,
             v1: &v44->m_aVerts.m_Memory.m_pMemory[v43->m_TriData[0].m_IndexDummy & 0x1FF],
             v2: &v44->m_aVerts.m_Memory.m_pMemory[v43->m_TriData[2].m_IndexDummy & 0x1FF],
             v3: &v44->m_aVerts.m_Memory.m_pMemory[v43->m_TriData[1].m_IndexDummy & 0x1FF],
             u: &v45,
             v: (float *)&pTri1,
             t: &v47) )
      {
        v38 = v45;
        if ( v45 >= 0.0 )
        {
          v39 = pTri1;
          if ( *(float *)&pTri1 >= 0.0 && (float)(v45 + *(float *)&pTri1) <= 1.0 )
          {
            v40 = v47;
            if ( v47 > 0.0 && output->dist > v47 )
            {
              *pImpactTri = v43;
              output->u = v38;
              LODWORD(output->v) = v39;
              output->dist = v40;
            }
          }
        }
      }
      v27 = LODWORD(flU) + 1;
      LODWORD(flU) = v27;
    }
    while ( v27 <= *(int *)&v41[1520] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160430
// Name: protected: void CDispCollTree::AABBTree_TreeTrisRayTest(struct Ray_t const __near &,class Vector const __near &,int,class CBaseTrace __near *,bool,class CDispCollTri __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDispCollTree::AABBTree_TreeTrisRayTest(
        CDispCollTree *this@<ecx>,
        int a2@<ebp>,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        int iNode,
        CBaseTrace *pTrace,
        bool bSide,
        CDispCollTri **pImpactTri)
{
  CDispCollTree *v8; // esi
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  CDispCollTri *v13; // edx
  int v14; // edi
  __m128 v15; // xmm7
  __m128 v16; // xmm6
  int v17; // ecx
  __m128 *p_x; // eax
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm7
  int v26; // eax
  int v27; // ecx
  CDispCollTri *v28; // eax
  int v29; // eax
  CDispCollLeaf *m_pMemory; // ecx
  int v31; // edx
  int v32; // eax
  CDispCollTri *v33; // ecx
  CDispCollTri *v34; // esi
  CDispCollTri *v35; // ecx
  double v36; // st7
  double v37; // st7
  CDispCollTri *v38; // edx
  _BYTE v39[1552]; // [esp-Ch] [ebp-64Ch] OVERLAPPED
  __m128 v40; // [esp+604h] [ebp-3Ch]
  CDispCollTri *v41; // [esp+624h] [ebp-1Ch]
  CDispCollTree *v42; // [esp+628h] [ebp-18h]
  float v43; // [esp+62Ch] [ebp-14h]
  CDispCollTri *pTri1; // [esp+630h] [ebp-10h]
  int v45; // [esp+634h] [ebp-Ch]
  float flFrac; // [esp+638h] [ebp-8h]
  float retaddr; // [esp+640h] [ebp+0h]

  v45 = a2;
  flFrac = retaddr;
  v8 = this;
  v42 = this;
  *(__m128 *)&v39[96] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->x), (__m128)LODWORD(vecInvDelta->x), 0);
  *(__m128 *)&v39[112] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->y), (__m128)LODWORD(vecInvDelta->y), 0);
  *(__m128 *)&v39[128] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->z), (__m128)LODWORD(vecInvDelta->z), 0);
  *(__m128 *)&v39[16] = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.y), (__m128)LODWORD(ray->m_Start.y), 0);
  v10 = 0;
  v10.m128_f32[0] = ray->m_Extents.x + 0.03125;
  *(__m128 *)&v39[48] = _mm_shuffle_ps(v10, v10, 0);
  v11 = 0;
  v11.m128_f32[0] = ray->m_Extents.y + 0.03125;
  *(__m128 *)&v39[64] = _mm_shuffle_ps(v11, v11, 0);
  v12 = 0;
  v13 = nullptr;
  v12.m128_f32[0] = ray->m_Extents.z + 0.03125;
  v14 = 0;
  v15 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.x), (__m128)LODWORD(ray->m_Start.x), 0);
  v16 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.z), (__m128)LODWORD(ray->m_Start.z), 0);
  *(__m128 *)v39 = v15;
  *(__m128 *)&v39[32] = v16;
  *(__m128 *)&v39[80] = _mm_shuffle_ps(v12, v12, 0);
  *(_DWORD *)&v39[144] = iNode;
  *(_DWORD *)&v39[1520] = 0;
  while ( 1 )
  {
    v17 = *(_DWORD *)&v39[4 * (_DWORD)v13 + 144];
    if ( v17 >= v8->m_nodes.m_Size )
      break;
    p_x = &v8->m_nodes.m_Memory.m_pMemory[v17].m_mins.x;
    v13 = (CDispCollTri *)((char *)v13 + 1);
    v19 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(p_x[4], *(__m128 *)&v39[16]), *(__m128 *)&v39[64]), *(__m128 *)&v39[112]);
    v20 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(*p_x, v15), *(__m128 *)&v39[48]), *(__m128 *)&v39[96]);
    v21 = _mm_sub_ps(_mm_sub_ps(p_x[2], v16), *(__m128 *)&v39[80]);
    v22 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(p_x[5], v16), *(__m128 *)&v39[80]), *(__m128 *)&v39[128]);
    v23 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(p_x[1], *(__m128 *)&v39[16]), *(__m128 *)&v39[64]), *(__m128 *)&v39[112]);
    *(__m128 *)&v39[1536] = _mm_add_ps(_mm_sub_ps(p_x[3], v15), *(__m128 *)&v39[48]);
    v24 = _mm_mul_ps(v21, *(__m128 *)&v39[128]);
    v25 = _mm_mul_ps(*(__m128 *)&v39[1536], *(__m128 *)&v39[96]);
    v40 = v19;
    v26 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_max_ps(_mm_max_ps(_mm_min_ps(v20, v25), _mm_min_ps(v23, v19)), _mm_min_ps(v24, v22)),
                Four_Zeros),
              _mm_min_ps(
                _mm_min_ps(_mm_min_ps(_mm_max_ps(v20, v25), _mm_max_ps(v23, v19)), _mm_max_ps(v24, v22)),
                Four_Ones)));
    pTri1 = v13;
    if ( v26 != 0 )
    {
      v27 = 4 * v17 + 1;
      if ( (v26 & 1) != 0 )
      {
        *(_DWORD *)&v39[1520] = v14 + 1;
        *(_DWORD *)&v39[4 * *(_DWORD *)&v39[1520] + 144] = v27;
        v14 = *(_DWORD *)&v39[1520];
      }
      if ( (v26 & 2) != 0 )
      {
        *(_DWORD *)&v39[1520] = v14 + 1;
        *(_DWORD *)&v39[4 * *(_DWORD *)&v39[1520] + 144] = v27 + 1;
        v14 = *(_DWORD *)&v39[1520];
        v13 = pTri1;
      }
      if ( (v26 & 4) != 0 )
      {
        *(_DWORD *)&v39[1520] = v14 + 1;
        *(_DWORD *)&v39[4 * *(_DWORD *)&v39[1520] + 144] = v27 + 2;
        v14 = *(_DWORD *)&v39[1520];
        v13 = pTri1;
      }
      if ( (v26 & 8) != 0 )
      {
        *(_DWORD *)&v39[1520] = v14 + 1;
        *(_DWORD *)&v39[4 * *(_DWORD *)&v39[1520] + 144] = v27 + 3;
        v14 = *(_DWORD *)&v39[1520];
      }
    }
    if ( (int)v13 > v14 )
    {
      v28 = v13;
      pTri1 = v13;
      goto LABEL_15;
    }
    v16 = *(__m128 *)&v39[32];
    v15 = *(__m128 *)v39;
  }
  v28 = v13;
  pTri1 = v13;
LABEL_15:
  if ( (int)v13 <= v14 )
  {
    do
    {
      v29 = *(_DWORD *)&v39[4 * (_DWORD)v28 + 144] - v8->m_nodes.m_Size;
      m_pMemory = v8->m_leaves.m_Memory.m_pMemory;
      v31 = m_pMemory[v29].m_tris[0];
      v32 = m_pMemory[v29].m_tris[1];
      v33 = v8->m_aTris.m_Memory.m_pMemory;
      v34 = &v33[v31];
      LOWORD(v31) = v34->m_TriData[0].m_IndexDummy;
      v35 = &v33[v32];
      LOWORD(v32) = v34->m_TriData[1].m_IndexDummy;
      v41 = v35;
      v36 = IntersectRayWithTriangle(
              ray,
              v1: &v42->m_aVerts.m_Memory.m_pMemory[v31 & 0x1FF],
              v2: &v42->m_aVerts.m_Memory.m_pMemory[v34->m_TriData[2].m_IndexDummy & 0x1FF],
              v3: &v42->m_aVerts.m_Memory.m_pMemory[v32 & 0x1FF],
              oneSided: bSide);
      v43 = v36;
      if ( v36 >= 0.0 && pTrace->fraction > v43 )
      {
        pTrace->fraction = v43;
        *pImpactTri = v34;
      }
      v8 = v42;
      v37 = IntersectRayWithTriangle(
              ray,
              v1: &v42->m_aVerts.m_Memory.m_pMemory[v41->m_TriData[0].m_IndexDummy & 0x1FF],
              v2: &v42->m_aVerts.m_Memory.m_pMemory[v41->m_TriData[2].m_IndexDummy & 0x1FF],
              v3: &v42->m_aVerts.m_Memory.m_pMemory[v41->m_TriData[1].m_IndexDummy & 0x1FF],
              oneSided: bSide);
      v43 = v37;
      if ( v37 >= 0.0 && pTrace->fraction > v43 )
      {
        v38 = v41;
        pTrace->fraction = v43;
        *pImpactTri = v38;
      }
      v28 = (CDispCollTri *)((char *)&pTri1->m_TriData[0].m_Index + 1);
      pTri1 = v28;
    }
    while ( (int)v28 <= *(int *)&v39[1520] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101607F0
// Name: protected: int CDispCollTree::AABBTree_BuildTreeTrisInSphere_r(class Vector const __near &,float,int,unsigned short __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CDispCollTree::AABBTree_BuildTreeTrisInSphere_r@<eax>(
        CDispCollTree *this@<ecx>,
        int a2@<ebp>,
        const Vector *center,
        float radius,
        int iNode,
        unsigned __int16 *pIndexOut,
        unsigned __int16 indexMax)
{
  __m128 x_low; // xmm3
  __m128 y_low; // xmm4
  __m128 z_low; // xmm5
  int m_Size; // edx
  __m128 v11; // xmm1
  int v12; // edi
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  int v16; // eax
  int v17; // esi
  CDispCollNode *v18; // edx
  __m128 z; // xmm2
  __m128 x; // xmm7
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  int v28; // edx
  int v29; // esi
  int v31; // eax
  int v32; // edx
  int v33; // eax
  _DWORD v34[3]; // [esp-Ch] [ebp-5ECh]
  __m128 v35; // [esp+564h] [ebp-7Ch]
  __m128 v36; // [esp+574h] [ebp-6Ch]
  _BYTE v37[76]; // [esp+584h] [ebp-5Ch] OVERLAPPED
  int v38; // [esp+5D0h] [ebp-10h]
  int listIndex; // [esp+5D4h] [ebp-Ch]
  int nTriCount; // [esp+5D8h] [ebp-8h]
  int retaddr; // [esp+5E0h] [ebp+0h]

  listIndex = a2;
  nTriCount = retaddr;
  *(_DWORD *)&v37[64] = this;
  x_low = (__m128)LODWORD(center->x);
  y_low = (__m128)LODWORD(center->y);
  z_low = (__m128)LODWORD(center->z);
  m_Size = this->m_nodes.m_Size;
  v11 = 0;
  v11.m128_f32[0] = radius * radius;
  v12 = 0;
  v34[0] = iNode;
  v13 = _mm_shuffle_ps(x_low, x_low, 0);
  v14 = _mm_shuffle_ps(y_low, y_low, 0);
  v15 = _mm_shuffle_ps(z_low, z_low, 0);
  v16 = 0;
  *(__m128 *)&v37[16] = v13;
  *(__m128 *)&v37[32] = v14;
  *(__m128 *)&v37[48] = v15;
  *(__m128 *)v37 = _mm_shuffle_ps(v11, v11, 0);
  *(_QWORD *)&v37[68] = (unsigned int)m_Size;
  while ( 1 )
  {
    v17 = v34[v16++];
    if ( v17 >= *(int *)&v37[68] )
      break;
    v18 = &this->m_nodes.m_Memory.m_pMemory[v17];
    z = v18->m_mins.z;
    x = v18->m_mins.x;
    v21 = _mm_sub_ps(v18->m_mins.y, v14);
    v22 = _mm_sub_ps(v14, v18->m_maxs.y);
    v35 = v21;
    v23 = _mm_sub_ps(z, v15);
    v24 = _mm_sub_ps(v15, v18->m_maxs.z);
    v36 = v23;
    v25 = _mm_max_ps(_mm_max_ps(Four_Zeros, v21), v22);
    v26 = _mm_max_ps(_mm_max_ps(Four_Zeros, _mm_sub_ps(x, v13)), _mm_sub_ps(v13, v18->m_maxs.x));
    v27 = _mm_max_ps(_mm_max_ps(Four_Zeros, v23), v24);
    v28 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v25, v25), _mm_mul_ps(v26, v26)), _mm_mul_ps(v27, v27)),
              *(__m128 *)v37));
    v38 = v28;
    if ( v28 != 0 )
    {
      v29 = 4 * v17 + 1;
      if ( (v28 & 1) != 0 )
        v34[++v12] = v29;
      if ( (v28 & 2) != 0 )
      {
        v34[++v12] = v29 + 1;
        LOBYTE(v28) = v38;
      }
      if ( (v28 & 4) != 0 )
      {
        v34[++v12] = v29 + 2;
        LOBYTE(v28) = v38;
      }
      if ( (v28 & 8) != 0 )
        v34[++v12] = v29 + 3;
    }
    if ( v16 > v12 )
      return *(_DWORD *)&v37[72];
    v14 = *(__m128 *)&v37[32];
    v15 = *(__m128 *)&v37[48];
    v13 = *(__m128 *)&v37[16];
  }
  v31 = v16 - 1;
  *(_DWORD *)&v37[68] = v31;
  if ( v31 <= v12 )
  {
    v38 = 2;
    do
    {
      if ( v38 <= indexMax )
      {
        v32 = v34[v31] - this->m_nodes.m_Size;
        v33 = *(_DWORD *)&v37[72];
        pIndexOut[*(_DWORD *)&v37[72]] = this->m_leaves.m_Memory.m_pMemory[v32].m_tris[0];
        this = *(CDispCollTree **)&v37[64];
        pIndexOut[v33 + 1] = *(_WORD *)(*(_DWORD *)(*(_DWORD *)&v37[64] + 160) + 4 * v32 + 2);
        v38 += 2;
        *(_DWORD *)&v37[72] = v33 + 2;
        v31 = *(_DWORD *)&v37[68];
      }
      *(_DWORD *)&v37[68] = ++v31;
    }
    while ( v31 <= v12 );
  }
  return *(_DWORD *)&v37[72];
}

//------------------------------------------------------------------------------
// Address: 0x101609F0
// Name: public: bool CDispCollTree::AABBTree_IntersectAABB(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CDispCollTree::AABBTree_IntersectAABB@<al>(
        CDispCollTree *this@<ecx>,
        float a2@<ebp>,
        const Vector *absMins,
        const Vector *absMaxs)
{
  float v4; // edi
  char v5; // al
  float x; // xmm5_4
  float y; // xmm3_4
  float z; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  __m128 v13; // xmm6
  float v14; // xmm3_4
  __m128 z_low; // xmm1
  __m128 v16; // xmm0
  int v17; // esi
  __m128 v18; // xmm0
  float v19; // ecx
  int v20; // edx
  __m128 *v21; // eax
  float v22; // eax
  int v23; // edx
  bool result; // al
  int v25; // esi
  int v26; // eax
  int v27; // esi
  __int16 *v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // xmm0_4
  int v32; // eax
  int v33; // esi
  _DWORD v34[3]; // [esp+14h] [ebp-60Ch]
  _BYTE nodeList_1348[124]; // [esp+584h] [ebp-9Ch] OVERLAPPED BYREF
  int v36; // [esp+600h] [ebp-20h]
  char v37; // [esp+604h] [ebp-1Ch]
  char v38; // [esp+605h] [ebp-1Bh]
  Vector extents; // [esp+608h] [ebp-18h]
  Vector center; // [esp+614h] [ebp-Ch]
  float plane; // [esp+620h] [ebp+0h]

  center.x = a2;
  center.y = plane;
  v4 = *(float *)&this;
  v5 = LOBYTE(this->m_nFlags) >> 2;
  LODWORD(extents.y) = this;
  if ( (v5 & 1) != 0 )
    return false;
  x = absMaxs->x;
  y = absMaxs->y;
  z = absMaxs->z;
  *(float *)&nodeList_1348[100] = (float)(absMaxs->x + absMins->x) * 0.5;
  v11 = (float)(y + absMins->y) * 0.5;
  v12 = (float)(z + absMins->z) * 0.5;
  v13 = _mm_shuffle_ps((__m128)LODWORD(absMins->x), (__m128)LODWORD(absMins->x), 0);
  v14 = y - v11;
  *(float *)&nodeList_1348[104] = v11;
  z_low = (__m128)LODWORD(absMins->z);
  *(__m128 *)nodeList_1348 = _mm_shuffle_ps((__m128)LODWORD(absMins->y), (__m128)LODWORD(absMins->y), 0);
  *(__m128 *)&nodeList_1348[16] = _mm_shuffle_ps(z_low, z_low, 0);
  v16 = 0;
  v16.m128_f32[0] = x;
  *(__m128 *)&nodeList_1348[32] = _mm_shuffle_ps(v16, v16, 0);
  *(__m128 *)&nodeList_1348[48] = _mm_shuffle_ps((__m128)LODWORD(absMaxs->y), (__m128)LODWORD(absMaxs->y), 0);
  v17 = 0;
  v18 = _mm_shuffle_ps((__m128)LODWORD(absMaxs->z), (__m128)LODWORD(absMaxs->z), 0);
  *(float *)&nodeList_1348[108] = v12;
  *(float *)&nodeList_1348[88] = x - *(float *)&nodeList_1348[100];
  *(float *)&nodeList_1348[92] = v14;
  *(float *)&nodeList_1348[96] = z - v12;
  v34[0] = 0;
  v19 = 0.0;
  *(__m128 *)&nodeList_1348[64] = v18;
  while ( 1 )
  {
    v20 = v34[v17++];
    if ( v20 >= *(_DWORD *)(LODWORD(v4) + 152) )
      break;
    v21 = (__m128 *)(*(_DWORD *)(LODWORD(v4) + 144) + 96 * v20);
    v22 = COERCE_FLOAT(
            _mm_movemask_ps(
              _mm_and_ps(
                _mm_and_ps(
                  _mm_cmple_ps(
                    _mm_max_ps(*(__m128 *)nodeList_1348, v21[1]),
                    _mm_min_ps(*(__m128 *)&nodeList_1348[48], v21[4])),
                  _mm_cmple_ps(_mm_max_ps(v13, *v21), _mm_min_ps(*(__m128 *)&nodeList_1348[32], v21[3]))),
                _mm_cmple_ps(
                  _mm_max_ps(*(__m128 *)&nodeList_1348[16], v21[2]),
                  _mm_min_ps(*(__m128 *)&nodeList_1348[64], v21[5])))));
    extents.z = v22;
    if ( v22 != 0.0 )
    {
      v23 = 4 * v20 + 1;
      if ( (LOBYTE(v22) & 1) != 0 )
        v34[++LODWORD(v19)] = v23;
      if ( (LOBYTE(v22) & 2) != 0 )
      {
        v34[++LODWORD(v19)] = v23 + 1;
        LOBYTE(v22) = LOBYTE(extents.z);
      }
      if ( (LOBYTE(v22) & 4) != 0 )
      {
        v34[++LODWORD(v19)] = v23 + 2;
        LOBYTE(v22) = LOBYTE(extents.z);
      }
      if ( (LOBYTE(v22) & 8) != 0 )
        v34[++LODWORD(v19)] = v23 + 3;
    }
    if ( v17 > SLODWORD(v19) )
      return false;
  }
  v25 = v17 - 1;
  extents.z = v19;
  LODWORD(extents.x) = v25;
  if ( v25 > SLODWORD(v19) )
    return false;
  while ( 1 )
  {
    v26 = v34[v25] - *(_DWORD *)(LODWORD(v4) + 152);
    v27 = *(_DWORD *)(LODWORD(v4) + 128);
    v28 = (__int16 *)(*(_DWORD *)(LODWORD(v4) + 160) + 4 * v26);
    v29 = *v28;
    v30 = v28[1];
    v31 = *(_DWORD *)(v27 + 24 * v29 + 8);
    v32 = v27 + 24 * v29;
    *(_DWORD *)&nodeList_1348[112] = v31;
    *(_QWORD *)&nodeList_1348[116] = *(_QWORD *)(v32 + 12);
    v36 = *(_DWORD *)(v32 + 20);
    v33 = v27 + 24 * v30;
    v38 = *(_BYTE *)(v32 + 6) & 7;
    v37 = (*(_BYTE *)(v32 + 6) >> 3) & 7;
    if ( IsBoxIntersectingTriangle(
           vecBoxCenter: (const Vector *)&nodeList_1348[100],
           vecBoxExtents: (const Vector *)&nodeList_1348[88],
           v1: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)v32 & 0x1FF)),
           v2: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)(v32 + 4) & 0x1FF)),
           v3: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)(v32 + 2) & 0x1FF)),
           plane: (const cplane_t *)&nodeList_1348[112],
           flTolerance: 0.0) )
    {
      break;
    }
    *(_QWORD *)&nodeList_1348[112] = *(_QWORD *)(v33 + 8);
    v4 = extents.y;
    *(_DWORD *)&nodeList_1348[120] = *(_DWORD *)(v33 + 16);
    v36 = *(_DWORD *)(v33 + 20);
    v38 = *(_BYTE *)(v33 + 6) & 7;
    v37 = (*(_BYTE *)(v33 + 6) >> 3) & 7;
    result = IsBoxIntersectingTriangle(
               vecBoxCenter: (const Vector *)&nodeList_1348[100],
               vecBoxExtents: (const Vector *)&nodeList_1348[88],
               v1: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)v33 & 0x1FF)),
               v2: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)(v33 + 4) & 0x1FF)),
               v3: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)(v33 + 2) & 0x1FF)),
               plane: (const cplane_t *)&nodeList_1348[112],
               flTolerance: 0.0);
    if ( result )
      break;
    v25 = LODWORD(extents.x) + 1;
    LODWORD(extents.x) = v25;
    if ( v25 > SLODWORD(extents.z) )
      return result;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10160D50
// Name: protected: void CDispCollTree::SweepAABBTriIntersect(struct Ray_t const __near &,class Vector const __near &,int,class CDispCollTri __near *,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::SweepAABBTriIntersect(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *rayDir,
        int iTri,
        CDispCollTri *pTri,
        CBaseTrace *pTrace)
{
  CDispCollTri *v6; // eax
  float v7; // xmm0_4
  int v8; // edx
  char *v9; // edi
  float *i; // esi
  unsigned int m_IndexDummy; // ecx
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm7_4
  int v15; // eax
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  int v22; // eax
  float v23; // xmm5_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  CDispCollTree *v29; // edi
  CDispCollTriCache *v30; // esi
  float m_flStartFrac; // xmm0_4
  CDispCollHelper helper; // [esp+0h] [ebp-24h] BYREF
  CDispCollTree *v33; // [esp+18h] [ebp-Ch]
  Vector *m_pMemory; // [esp+20h] [ebp-4h]

  v6 = pTri;
  helper.m_flEndFrac = 1.0;
  helper.m_flStartFrac = -99999.898;
  v7 = (float)((float)(ray->m_Delta.y * pTri->m_vecNormal.y) + (float)(ray->m_Delta.x * pTri->m_vecNormal.x))
     + (float)(ray->m_Delta.z * pTri->m_vecNormal.z);
  v33 = this;
  if ( v7 <= 0.03125 )
  {
    v8 = 2;
    m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
    v9 = (char *)&unk_103636E8;
    for ( i = &ray->m_Delta.z; ; --i )
    {
      m_IndexDummy = v6->m_TriData[v8].m_IndexDummy;
      v12 = i[8];
      v13 = *(i - 4);
      v14 = *i;
      v15 = v6->m_TriData[(m_IndexDummy >> 9) & 3].m_IndexDummy & 0x1FF;
      v16 = *(&m_pMemory->x + 2 * v15 + v15 + v8);
      v17 = (float)(v16 - v12) - v13;
      v18 = v17 - *i;
      if ( v17 > 0.0 && v18 > 0.0 )
        break;
      if ( v17 >= 0.0 || v18 >= 0.0 )
      {
        v19 = v17 - v18;
        if ( v17 < 0.0 || v18 > 0.0 )
        {
          if ( (float)(v17 - v18) == 0.0 )
            v21 = 0.0;
          else
            v21 = (float)(v17 + 0.03125) / v19;
          if ( helper.m_flEndFrac > v21 )
            helper.m_flEndFrac = v21;
        }
        else
        {
          if ( (float)(v17 - v18) == 0.0 )
            v20 = 0.0;
          else
            v20 = (float)(v17 - 0.03125) / v19;
          if ( v20 > helper.m_flStartFrac )
          {
            helper.m_flStartFrac = v20;
            helper.m_vecImpactNormal = *(Vector *)(v9 - 8);
            helper.m_flImpactDist = v16;
          }
        }
      }
      v22 = pTri->m_TriData[(m_IndexDummy >> 11) & 3].m_IndexDummy & 0x1FF;
      v23 = *(&m_pMemory->x + 2 * v22 + v22 + v8);
      v24 = v13 - (float)(v23 + v12);
      v25 = v24 + v14;
      if ( v24 > 0.0 && v25 > 0.0 )
        break;
      if ( v24 >= 0.0 || v25 >= 0.0 )
      {
        v26 = v24 - v25;
        if ( v24 < 0.0 || v25 > 0.0 )
        {
          if ( (float)(v24 - v25) == 0.0 )
            v28 = 0.0;
          else
            v28 = (float)(v24 + 0.03125) / v26;
          if ( helper.m_flEndFrac > v28 )
            helper.m_flEndFrac = v28;
        }
        else
        {
          if ( (float)(v24 - v25) == 0.0 )
            v27 = 0.0;
          else
            v27 = (float)(v24 - 0.03125) / v26;
          if ( v27 > helper.m_flStartFrac )
          {
            helper.m_flStartFrac = v27;
            helper.m_vecImpactNormal = *(Vector *)(v9 + 28);
            helper.m_flImpactDist = v23;
          }
        }
      }
      v9 -= 12;
      --v8;
      if ( (int)v9 < (int)byte_103636D0 )
      {
        v29 = v33;
        v30 = &v33->m_aTrisCache.m_Memory.m_pMemory[iTri];
        if ( CDispCollTree::EdgeCrossAxis<0>(this: v33, ray, iPlane: v30->m_iCrossX[0], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<0>(this: v29, ray, iPlane: v30->m_iCrossX[1], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<0>(this: v29, ray, iPlane: v30->m_iCrossX[2], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<1>(this: v29, ray, iPlane: v30->m_iCrossY[0], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<1>(this: v29, ray, iPlane: v30->m_iCrossY[1], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<1>(this: v29, ray, iPlane: v30->m_iCrossY[2], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<2>(this: v29, ray, iPlane: v30->m_iCrossZ[0], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<2>(this: v29, ray, iPlane: v30->m_iCrossZ[1], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<2>(this: v29, ray, iPlane: v30->m_iCrossZ[2], pHelper: &helper) != 0
          && CDispCollTree::FacePlane(this: v29, ray, rayDir, pTri, pHelper: &helper) != 0 )
        {
          m_flStartFrac = helper.m_flStartFrac;
          if ( (helper.m_flEndFrac > helper.m_flStartFrac || fabs(helper.m_flStartFrac - helper.m_flEndFrac) < 0.001)
            && helper.m_flStartFrac != -99999.898
            && pTrace->fraction > helper.m_flStartFrac )
          {
            if ( helper.m_flStartFrac < 0.0 )
              m_flStartFrac = 0.0;
            pTrace->fraction = m_flStartFrac;
            pTrace->plane.normal = helper.m_vecImpactNormal;
            pTrace->plane.dist = helper.m_flImpactDist;
            pTrace->dispFlags = (*((_WORD *)pTri + 3) >> 6) & 0x1F;
          }
        }
        return;
      }
      v6 = pTri;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161150
// Name: public: void CDispCollTree::GetVirtualMeshList(struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::GetVirtualMeshList(CDispCollTree *this, virtualmeshlist_t *pList)
{
  int v3; // esi
  int v4; // edx
  unsigned __int16 *v5; // ecx

  v3 = 2 * (1 << this->m_nPower) * (1 << this->m_nPower);
  pList->indexCount = 6 * (1 << this->m_nPower) * (1 << this->m_nPower);
  pList->triangleCount = v3;
  pList->vertexCount = this->m_aVerts.m_Size;
  pList->pVerts = this->m_aVerts.m_Memory.m_pMemory;
  v4 = 0;
  pList->pHull = nullptr;
  pList->surfacePropsIndex = this->m_nSurfaceProps[0];
  if ( v3 > 0 )
  {
    v5 = &pList->indices[1];
    do
    {
      *(v5 - 1) = this->m_aTris.m_Memory.m_pMemory[v4].m_TriData[0].m_IndexDummy & 0x1FF;
      *v5 = this->m_aTris.m_Memory.m_pMemory[v4].m_TriData[1].m_IndexDummy & 0x1FF;
      v5[1] = this->m_aTris.m_Memory.m_pMemory[v4].m_TriData[2].m_IndexDummy & 0x1FF;
      v5 += 3;
      ++v4;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101613F0
// Name: public: void CDispCollTree::Uncache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::Uncache(CDispCollTree *this)
{
  Vector *m_pMemory; // ecx

  this->m_aTrisCache.m_Size = 0;
  if ( this->m_aTrisCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aTrisCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aTrisCache.m_Memory.m_pMemory);
      this->m_aTrisCache.m_Memory.m_pMemory = nullptr;
    }
    this->m_aTrisCache.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aTrisCache.m_pElements = this->m_aTrisCache.m_Memory.m_pMemory;
  this->m_aEdgePlanes.m_Size = 0;
  if ( this->m_aEdgePlanes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_aEdgePlanes.m_pElements = this->m_aEdgePlanes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_aEdgePlanes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aEdgePlanes.m_Memory.m_pMemory);
      this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_aEdgePlanes.m_Memory.m_pMemory;
    this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
    this->m_aEdgePlanes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161490
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,class Vector const __near &,struct RayDispOutput_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        RayDispOutput_t *output)
{
  CDispCollTri *v5; // eax
  CDispCollTri *pImpactTri; // [esp+0h] [ebp-4h] BYREF

  pImpactTri = (CDispCollTri *)this;
  if ( (this->m_nFlags & 8) != 0 || (this->m_nContents & 0x4081) == 0 )
    return 0;
  pImpactTri = nullptr;
  CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(this, ray, vecInvDelta, iNode: 0, output, &pImpactTri);
  v5 = pImpactTri;
  if ( pImpactTri == nullptr )
    return 0;
  output->ndxVerts[0] = pImpactTri->m_TriData[0].m_IndexDummy & 0x1FF;
  output->ndxVerts[1] = v5->m_TriData[2].m_IndexDummy & 0x1FF;
  output->ndxVerts[2] = v5->m_TriData[1].m_IndexDummy & 0x1FF;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10161510
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,class Vector const __near &,class CBaseTrace __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        CBaseTrace *pTrace,
        bool bSide)
{
  CDispCollTri *v6; // eax
  CDispCollTri *pImpactTri; // [esp+0h] [ebp-4h] BYREF
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  pImpactTri = (CDispCollTri *)this;
  if ( (this->m_nFlags & 8) != 0 || (this->m_nContents & 0x4081) == 0 )
    return 0;
  pImpactTri = nullptr;
  CDispCollTree::AABBTree_TreeTrisRayTest(
    this,
    a2: (int)&savedregs,
    ray,
    vecInvDelta,
    iNode: 0,
    pTrace,
    bSide,
    &pImpactTri);
  v6 = pImpactTri;
  if ( pImpactTri == nullptr )
    return 0;
  pTrace->plane.normal.x = pImpactTri->m_vecNormal.x;
  pTrace->plane.normal.y = v6->m_vecNormal.y;
  pTrace->plane.normal.z = v6->m_vecNormal.z;
  pTrace->plane.dist = v6->m_flDist;
  pTrace->dispFlags = (*((_WORD *)v6 + 3) >> 6) & 0x1F;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101615A0
// Name: public: int CDispCollTree::AABBTree_GetTrisInSphere(class Vector const __near &,float,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispCollTree::AABBTree_GetTrisInSphere(
        CDispCollTree *this,
        const Vector *center,
        float radius,
        unsigned __int16 *pIndexOut,
        unsigned __int16 indexMax)
{
  float var10; // [esp+0h] [ebp+0h] BYREF

  return CDispCollTree::AABBTree_BuildTreeTrisInSphere_r(
           this,
           a2: (int)&var10,
           center,
           radius,
           iNode: 0,
           pIndexOut,
           indexMax);
}

//------------------------------------------------------------------------------
// Address: 0x101615D0
// Name: private: virtual void CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::DestroyResourceStorage(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::DestroyResourceStorage(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this,
        CDispCollTree *pStore)
{
  CDispCollTree::Uncache(this: pStore);
  pStore->m_hCache = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101616A0
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,struct RayDispOutput_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(CDispCollTree *this, const Ray_t *ray, RayDispOutput_t *output)
{
  VectorAligned *p_m_Delta; // ebx
  float y; // xmm0_4
  float z; // xmm0_4
  Vector vecInvDelta; // [esp+10h] [ebp-Ch] BYREF

  p_m_Delta = &ray->m_Delta;
  if ( !IsBoxIntersectingRay(
          boxMin: &this->m_mins,
          boxMax: &this->m_maxs,
          origin: &ray->m_Start,
          vecDelta: &ray->m_Delta,
          flTolerance: 0.03125) )
    return 0;
  if ( p_m_Delta->x == 0.0 )
    vecInvDelta.x = 3.4028235e38;
  else
    vecInvDelta.x = 1.0 / p_m_Delta->x;
  y = ray->m_Delta.y;
  if ( y == 0.0 )
    vecInvDelta.y = 3.4028235e38;
  else
    vecInvDelta.y = 1.0 / y;
  z = ray->m_Delta.z;
  if ( z == 0.0 )
    vecInvDelta.z = 3.4028235e38;
  else
    vecInvDelta.z = 1.0 / z;
  return CDispCollTree::AABBTree_Ray(this, ray, &vecInvDelta, output);
}

//------------------------------------------------------------------------------
// Address: 0x10161770
// Name: public: CDispCollTree::~CDispCollTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::~CDispCollTree(CDispCollTree *this)
{
  memhandle_t__ *m_hCache; // eax
  Vector *m_pMemory; // eax
  CDispCollTri *v4; // ecx
  CDispCollLeaf *v5; // edx
  CDispCollNode *v6; // eax
  CDispCollTri *v7; // ecx
  Vector *v8; // edx

  m_hCache = this->m_hCache;
  this->__vftable = (CDispCollTree_vtbl *)&CDispCollTree::`vftable';
  if ( m_hCache != (memhandle_t__ *)-1 )
    CDataManagerBase::DestroyResource(this: &g_DispCollTriCache, handle: m_hCache);
  m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
  this->m_aVerts.m_Size = 0;
  this->m_aVerts.m_Memory.m_nAllocated = 0;
  this->m_aVerts.m_pElements = m_pMemory;
  v4 = this->m_aTris.m_Memory.m_pMemory;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_Memory.m_nAllocated = 0;
  this->m_aTris.m_pElements = v4;
  this->m_aEdgePlanes.m_Size = 0;
  if ( this->m_aEdgePlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aEdgePlanes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aEdgePlanes.m_Memory.m_pMemory);
      this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
    }
    this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aEdgePlanes.m_pElements = this->m_aEdgePlanes.m_Memory.m_pMemory;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_aEdgePlanes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_aTrisCache);
  v5 = this->m_leaves.m_Memory.m_pMemory;
  this->m_leaves.m_Size = 0;
  this->m_leaves.m_Memory.m_nAllocated = 0;
  this->m_leaves.m_pElements = v5;
  v6 = this->m_nodes.m_Memory.m_pMemory;
  this->m_nodes.m_Size = 0;
  this->m_nodes.m_Memory.m_nAllocated = 0;
  this->m_nodes.m_pElements = v6;
  v7 = this->m_aTris.m_Memory.m_pMemory;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_Memory.m_nAllocated = 0;
  this->m_aTris.m_pElements = v7;
  v8 = this->m_aVerts.m_Memory.m_pMemory;
  this->m_aVerts.m_Size = 0;
  this->m_aVerts.m_Memory.m_nAllocated = 0;
  this->m_aVerts.m_pElements = v8;
}

//------------------------------------------------------------------------------
// Address: 0x10161870
// Name: protected: void CDispCollTree::AABBTree_CreateLeafs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::AABBTree_CreateLeafs(CDispCollTree *this)
{
  int m_nPower; // ecx
  int v3; // esi
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ebx
  int v14; // ecx
  int v15; // edx
  __int16 v16; // dx
  CDispVector<CDispCollLeaf> *p_m_leaves; // [esp+Ch] [ebp-14h]
  int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+18h] [ebp-8h]
  int iHgt; // [esp+1Ch] [ebp-4h]

  m_nPower = this->m_nPower;
  p_m_leaves = &this->m_leaves;
  v3 = (1 << m_nPower) * (1 << m_nPower);
  this->m_leaves.m_Size = 0;
  if ( v3 != 0 )
  {
    CUtlVector<CDispCollLeaf,CHunkMemory<CDispCollLeaf>>::GrowVector(
      this: &this->m_leaves,
      num: (1 << m_nPower) * (1 << m_nPower));
    if ( this->m_leaves.m_Size - v3 > 0 && v3 > 0 )
      _V_memmove(
        dest: &this->m_leaves.m_Memory.m_pMemory[v3],
        src: this->m_leaves.m_Memory.m_pMemory,
        count: 4 * (this->m_leaves.m_Size - v3));
  }
  v4 = 2 * this->m_nPower + 2;
  this->m_nodes.m_Size = 0;
  v5 = (1 << v4) / 3 - v3;
  if ( v5 != 0 )
  {
    CUtlVector<CDispCollNode,CHunkMemory<CDispCollNode>>::GrowVector(this: &this->m_nodes, num: v5);
    if ( this->m_nodes.m_Size - v5 > 0 && v5 > 0 )
      _V_memmove(
        dest: &this->m_nodes.m_Memory.m_pMemory[v5],
        src: this->m_nodes.m_Memory.m_pMemory,
        count: 96 * (this->m_nodes.m_Size - v5));
  }
  v6 = 1 << this->m_nPower;
  v7 = 0;
  iHgt = 0;
  v19 = v6;
  if ( v6 > 0 )
  {
    v18 = 0;
    do
    {
      v8 = 0;
      if ( v6 > 0 )
      {
        v20 = v7;
        do
        {
          v9 = iHgt;
          v10 = 0;
          v11 = 0;
          v12 = v8;
          if ( v8 != 0 )
          {
            do
            {
              v13 = (v12 & 1) << v11;
              v11 += 2;
              v10 |= v13;
              v12 >>= 1;
            }
            while ( v12 != 0 );
            v7 = v20;
          }
          v14 = 1;
          if ( iHgt != 0 )
          {
            do
            {
              v15 = (v9 & 1) << v14;
              v14 += 2;
              v10 |= v15;
              v9 >>= 1;
            }
            while ( v9 != 0 );
          }
          p_m_leaves->m_Memory.m_pMemory[v10].m_tris[0] = v7;
          v16 = v7 + 1;
          ++v8;
          v7 += 2;
          p_m_leaves->m_Memory.m_pMemory[v10].m_tris[1] = v16;
          v20 = v7;
        }
        while ( v8 < v19 );
        v6 = v19;
      }
      v7 = 2 * v6 + v18;
      ++iHgt;
      v18 = v7;
    }
    while ( iHgt < v6 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101619E0
// Name: protected: int CDispCollTree::AddPlane(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispCollTree::AddPlane(CDispCollTree *this, const Vector *vecNormal)
{
  const Vector *v2; // esi
  int m_Size; // eax
  float y; // xmm0_4
  DispCollPlaneIndex_t *v6; // ecx
  DispCollPlaneIndex_t planeIndex; // [esp+4h] [ebp-14h] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  v2 = vecNormal;
  m_Size = this->m_aEdgePlanes.m_Size;
  planeIndex.vecPlane.x = vecNormal->x;
  y = vecNormal->y;
  planeIndex.index = m_Size;
  planeIndex.vecPlane.y = y;
  planeIndex.vecPlane.z = vecNormal->z;
  vecNormal = nullptr;
  if ( CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::DoFind(
         this: &g_DispCollPlaneIndexHash,
         src: &planeIndex,
         &pBucket,
         pIndex: (int *)&vecNormal) )
  {
    v6 = &g_DispCollPlaneIndexHash.m_Buckets.m_Memory.m_pMemory[((unsigned int)vecNormal | (pBucket << 16)) >> 16].m_Memory.m_pMemory[(unsigned __int16)vecNormal];
    if ( v2->x == v6->vecPlane.x && v2->y == v6->vecPlane.y && v2->z == v6->vecPlane.z )
      return v6->index;
    else
      return v6->index | 0x8000;
  }
  else
  {
    CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
      this: (CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int> > *)&g_DispCollPlaneIndexHash.m_Buckets.m_Memory.m_pMemory[pBucket],
      elem: g_DispCollPlaneIndexHash.m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
      src: (const CSosOperator::InputData_t *)&planeIndex);
    return CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: &this->m_aEdgePlanes,
             elem: this->m_aEdgePlanes.m_Size,
             src: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161AE0
// Name: protected: bool CDispCollTree::Cache_EdgeCrossAxisX(class Vector const __near &,class Vector const __near &,class Vector const __near &,class CDispCollTri __near *,unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Cache_EdgeCrossAxisX(
        CDispCollTree *this,
        const Vector *vecEdge,
        const Vector *vecOnEdge,
        const Vector *vecOffEdge,
        CDispCollTri *pTri,
        unsigned __int16 *iPlane)
{
  double v7; // st5
  float v8; // xmm0_4
  double v9; // st6
  Vector vecNormal; // [esp+0h] [ebp-Ch] BYREF
  float flDist; // [esp+14h] [ebp+8h]
  float flOffDist; // [esp+18h] [ebp+Ch]

  vecNormal.x = 0.0;
  vecNormal.y = vecEdge->z;
  LODWORD(vecNormal.z) = LODWORD(vecEdge->y) ^ _mask__NegFloat_;
  VectorNormalize(vec: &vecNormal);
  if ( vecNormal.y == 0.0 || vecNormal.z == 0.0 )
  {
    *iPlane = -1;
    return 0;
  }
  else
  {
    v7 = vecOnEdge->y * vecNormal.y + vecOnEdge->z * vecNormal.z;
    flDist = v7;
    v8 = flDist;
    v9 = vecNormal.y * vecOffEdge->y + vecNormal.z * vecOffEdge->z;
    if ( fabs(v9 - v7) >= 0.03125 )
    {
      flOffDist = v9;
      if ( flOffDist > flDist )
      {
        v8 = -flDist;
        vecNormal.y = -vecNormal.y;
        vecNormal.z = -vecNormal.z;
      }
    }
    vecNormal.x = v8;
    *iPlane = CDispCollTree::AddPlane(this, &vecNormal);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161BF0
// Name: protected: bool CDispCollTree::Cache_EdgeCrossAxisY(class Vector const __near &,class Vector const __near &,class Vector const __near &,class CDispCollTri __near *,unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Cache_EdgeCrossAxisY(
        CDispCollTree *this,
        const Vector *vecEdge,
        const Vector *vecOnEdge,
        const Vector *vecOffEdge,
        CDispCollTri *pTri,
        unsigned __int16 *iPlane)
{
  double v7; // st5
  float v8; // xmm0_4
  double v9; // st6
  Vector vecNormal; // [esp+0h] [ebp-Ch] BYREF
  float flDist; // [esp+14h] [ebp+8h]
  float flOffDist; // [esp+18h] [ebp+Ch]

  LODWORD(vecNormal.x) = LODWORD(vecEdge->z) ^ _mask__NegFloat_;
  vecNormal.y = 0.0;
  vecNormal.z = vecEdge->x;
  VectorNormalize(vec: &vecNormal);
  if ( vecNormal.x == 0.0 || vecNormal.z == 0.0 )
  {
    *iPlane = -1;
    return 0;
  }
  else
  {
    v7 = vecOnEdge->x * vecNormal.x + vecOnEdge->z * vecNormal.z;
    flDist = v7;
    v8 = flDist;
    v9 = vecNormal.x * vecOffEdge->x + vecNormal.z * vecOffEdge->z;
    if ( fabs(v9 - v7) >= 0.03125 )
    {
      flOffDist = v9;
      if ( flOffDist > flDist )
      {
        vecNormal.x = -vecNormal.x;
        v8 = -flDist;
        vecNormal.z = -vecNormal.z;
      }
    }
    vecNormal.y = v8;
    *iPlane = CDispCollTree::AddPlane(this, &vecNormal);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161CF0
// Name: protected: bool CDispCollTree::Cache_EdgeCrossAxisZ(class Vector const __near &,class Vector const __near &,class Vector const __near &,class CDispCollTri __near *,unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Cache_EdgeCrossAxisZ(
        CDispCollTree *this,
        const Vector *vecEdge,
        const Vector *vecOnEdge,
        const Vector *vecOffEdge,
        CDispCollTri *pTri,
        unsigned __int16 *iPlane)
{
  double v7; // st5
  float v8; // xmm0_4
  double v9; // st6
  Vector vecNormal; // [esp+0h] [ebp-Ch] BYREF
  float flDist; // [esp+14h] [ebp+8h]
  float flOffDist; // [esp+18h] [ebp+Ch]

  vecNormal.x = vecEdge->y;
  LODWORD(vecNormal.y) = LODWORD(vecEdge->x) ^ _mask__NegFloat_;
  vecNormal.z = 0.0;
  VectorNormalize(vec: &vecNormal);
  if ( vecNormal.x == 0.0 || vecNormal.y == 0.0 )
  {
    *iPlane = -1;
    return 0;
  }
  else
  {
    v7 = vecOnEdge->x * vecNormal.x + vecOnEdge->y * vecNormal.y;
    flDist = v7;
    v8 = flDist;
    v9 = vecNormal.x * vecOffEdge->x + vecNormal.y * vecOffEdge->y;
    if ( fabs(v9 - v7) >= 0.03125 )
    {
      flOffDist = v9;
      if ( flOffDist > flDist )
      {
        vecNormal.x = -vecNormal.x;
        vecNormal.y = -vecNormal.y;
        v8 = -flDist;
      }
    }
    vecNormal.z = v8;
    *iPlane = CDispCollTree::AddPlane(this, &vecNormal);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161DF0
// Name: public: CDispCollTree::CDispCollTree(void)
// Source: json
//------------------------------------------------------------------------------
CDispCollTree *__thiscall CDispCollTree::CDispCollTree(CDispCollTree *this)
{
  Vector *m_pMemory; // eax
  CDispCollTri *v3; // ecx

  this->__vftable = (CDispCollTree_vtbl *)&CDispCollTree::`vftable';
  this->m_aVerts.m_Memory.m_pMemory = nullptr;
  this->m_aVerts.m_pElements = nullptr;
  this->m_aTris.m_Memory.m_pMemory = nullptr;
  this->m_aTris.m_Memory.m_nAllocated = 0;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_pElements = nullptr;
  this->m_nodes.m_Memory.m_pMemory = nullptr;
  this->m_nodes.m_Memory.m_nAllocated = 0;
  this->m_nodes.m_Size = 0;
  this->m_nodes.m_pElements = nullptr;
  this->m_leaves.m_Memory.m_pMemory = nullptr;
  this->m_leaves.m_Memory.m_nAllocated = 0;
  this->m_leaves.m_Size = 0;
  this->m_leaves.m_pElements = nullptr;
  this->m_aTrisCache.m_Memory.m_pMemory = nullptr;
  this->m_aTrisCache.m_Memory.m_nAllocationCount = 0;
  this->m_aTrisCache.m_Memory.m_nGrowSize = 0;
  this->m_aTrisCache.m_Size = 0;
  this->m_aTrisCache.m_pElements = nullptr;
  this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
  this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
  this->m_aEdgePlanes.m_Memory.m_nGrowSize = 0;
  this->m_aEdgePlanes.m_Size = 0;
  this->m_aEdgePlanes.m_pElements = nullptr;
  this->m_nPower = 0;
  this->m_nFlags = 0;
  this->m_vecSurfPoints[0].x = 0.0;
  this->m_vecSurfPoints[1].x = 0.0;
  this->m_vecSurfPoints[0].y = 0.0;
  this->m_vecSurfPoints[0].z = 0.0;
  this->m_vecSurfPoints[1].y = 0.0;
  this->m_vecSurfPoints[1].z = 0.0;
  this->m_vecSurfPoints[2].x = 0.0;
  this->m_vecSurfPoints[2].y = 0.0;
  this->m_vecSurfPoints[2].z = 0.0;
  this->m_vecSurfPoints[3].x = 0.0;
  this->m_vecSurfPoints[3].y = 0.0;
  this->m_vecSurfPoints[3].z = 0.0;
  this->m_nContents = -1;
  *(_DWORD *)this->m_nSurfaceProps = 0;
  this->m_vecStabDir.x = 0.0;
  this->m_vecStabDir.y = 0.0;
  this->m_vecStabDir.z = 0.0;
  this->m_mins.x = 3.4028235e38;
  this->m_mins.y = 3.4028235e38;
  this->m_mins.z = 3.4028235e38;
  this->m_maxs.x = -3.4028235e38;
  this->m_maxs.y = -3.4028235e38;
  this->m_maxs.z = -3.4028235e38;
  this->m_iCounter = 0;
  m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
  this->m_aVerts.m_Size = 0;
  this->m_aVerts.m_Memory.m_nAllocated = 0;
  this->m_aVerts.m_pElements = m_pMemory;
  v3 = this->m_aTris.m_Memory.m_pMemory;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_Memory.m_nAllocated = 0;
  this->m_aTris.m_pElements = v3;
  this->m_aEdgePlanes.m_Size = 0;
  if ( this->m_aEdgePlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aEdgePlanes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aEdgePlanes.m_Memory.m_pMemory);
      this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
    }
    this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aEdgePlanes.m_pElements = this->m_aEdgePlanes.m_Memory.m_pMemory;
  this->m_hCache = (memhandle_t__ *)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10161F90
// Name: protected: void CDispCollTree::AABBTree_CopyDispData(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::AABBTree_CopyDispData(CDispCollTree *this, CCoreDispInfo *pDisp)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  int v9; // eax
  int m_nPower; // ecx
  int v11; // ebx
  int m_nAllocated; // ecx
  int v13; // eax
  char *v14; // ecx
  Vector *m_pMemory; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  char *v22; // ecx
  CDispCollLeaf *v23; // edx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  char *v29; // ecx
  CDispCollNode *v30; // eax
  int v31; // edx
  CDispCollNode *v32; // edx
  int v33; // ecx
  int v34; // edx
  CoreDispVert_t *m_pVerts; // ecx
  double x; // st7
  float *v37; // eax
  int p_m_Vert; // ecx
  int v39; // edi
  __int16 v40; // cx
  int v41; // eax
  unsigned __int16 iVerts[4]; // [esp+Ch] [ebp-10h] BYREF
  int numLeaves; // [esp+14h] [ebp-8h]
  int iTri; // [esp+18h] [ebp-4h]

  this->m_nPower = pDisp->m_Power;
  this->m_nContents = pDisp->m_Surf.m_Contents;
  v3 = pDisp->m_Surf.m_Points[3].y - pDisp->m_Surf.m_Points[0].y;
  v4 = pDisp->m_Surf.m_Points[3].z - pDisp->m_Surf.m_Points[0].z;
  v5 = pDisp->m_Surf.m_Points[1].y - pDisp->m_Surf.m_Points[0].y;
  v6 = pDisp->m_Surf.m_Points[1].z - pDisp->m_Surf.m_Points[0].z;
  v7 = pDisp->m_Surf.m_Points[1].x - pDisp->m_Surf.m_Points[0].x;
  v8 = pDisp->m_Surf.m_Points[3].x - pDisp->m_Surf.m_Points[0].x;
  this->m_vecStabDir.x = (float)(v3 * v6) - (float)(v4 * v5);
  this->m_vecStabDir.y = (float)(v4 * v7) - (float)(v8 * v6);
  this->m_vecStabDir.z = (float)(v8 * v5) - (float)(v3 * v7);
  VectorNormalize(vec: &this->m_vecStabDir);
  qmemcpy(this->m_vecSurfPoints, pDisp->m_Surf.m_Points, sizeof(this->m_vecSurfPoints));
  v9 = CHunkAllocCredit::s_DbgInfoStackDepth + 1;
  CHunkAllocCredit::s_DbgInfoStackDepth = v9;
  if ( v9 < 8 )
    CHunkAllocCredit::s_DbgInfoStack[v9] = "AABBTree_CopyDispData";
  m_nPower = this->m_nPower;
  this->m_aVerts.m_Size = 0;
  v11 = ((1 << m_nPower) + 1) * ((1 << m_nPower) + 1);
  if ( v11 != 0 )
  {
    m_nAllocated = this->m_aVerts.m_Memory.m_nAllocated;
    if ( v11 > m_nAllocated )
    {
      v13 = v11 - m_nAllocated;
      numLeaves = v11 - m_nAllocated;
      if ( CHunkAllocCredit::s_DbgInfoStackDepth < 7 )
      {
        if ( CHunkAllocCredit::s_DbgInfoStackDepth < 0 )
          v14 = "CHunkMemory";
        else
          v14 = (char *)CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth];
      }
      else
      {
        v14 = (char *)unk_1069634C;
      }
      this->m_aVerts.m_Memory.m_pMemory = (Vector *)Hunk_AllocName(size: 12 * v13, name: v14, bClear: false);
      this->m_aVerts.m_Memory.m_nAllocated = numLeaves;
    }
    this->m_aVerts.m_Size += v11;
    m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
    v16 = this->m_aVerts.m_Size - v11;
    this->m_aVerts.m_pElements = m_pMemory;
    if ( v16 > 0 && v11 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v11], src: (unsigned __int8 *)m_pMemory, count: 12 * v16);
  }
  v17 = 1 << this->m_nPower;
  this->m_aTris.m_Size = 0;
  CUtlVector<CDispCollTri,CHunkMemory<CDispCollTri>>::InsertMultipleBefore(
    this: &this->m_aTris,
    elem: 0,
    num: 2 * v17 * v17);
  v18 = this->m_nPower;
  this->m_leaves.m_Size = 0;
  v19 = (1 << v18) * (1 << v18);
  numLeaves = v19;
  if ( v19 != 0 )
  {
    v20 = this->m_leaves.m_Memory.m_nAllocated;
    if ( v19 > v20 )
    {
      v21 = v19 - v20;
      iTri = v21;
      if ( CHunkAllocCredit::s_DbgInfoStackDepth < 7 )
      {
        if ( CHunkAllocCredit::s_DbgInfoStackDepth < 0 )
          v22 = "CHunkMemory";
        else
          v22 = (char *)CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth];
      }
      else
      {
        v22 = (char *)unk_1069634C;
      }
      this->m_leaves.m_Memory.m_pMemory = (CDispCollLeaf *)Hunk_AllocName(size: 4 * v21, name: v22, bClear: false);
      this->m_leaves.m_Memory.m_nAllocated = iTri;
      v19 = numLeaves;
    }
    this->m_leaves.m_Size += v19;
    v23 = this->m_leaves.m_Memory.m_pMemory;
    v24 = this->m_leaves.m_Size - v19;
    this->m_leaves.m_pElements = v23;
    if ( v24 > 0 && v19 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v23[v19], src: (unsigned __int8 *)v23, count: 4 * v24);
  }
  v25 = 2 * this->m_nPower + 2;
  this->m_nodes.m_Size = 0;
  v26 = (1 << v25) / 3 - numLeaves;
  iTri = v26;
  if ( v26 != 0 )
  {
    v27 = this->m_nodes.m_Memory.m_nAllocated;
    if ( v26 > v27 )
    {
      v28 = v26 - v27;
      numLeaves = v28;
      if ( CHunkAllocCredit::s_DbgInfoStackDepth < 7 )
      {
        if ( CHunkAllocCredit::s_DbgInfoStackDepth < 0 )
          v29 = "CHunkMemory";
        else
          v29 = (char *)CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth];
      }
      else
      {
        v29 = (char *)unk_1069634C;
      }
      v30 = (CDispCollNode *)Hunk_AllocName(size: 96 * v28, name: v29, bClear: false);
      v31 = numLeaves;
      this->m_nodes.m_Memory.m_pMemory = v30;
      v26 = iTri;
      this->m_nodes.m_Memory.m_nAllocated = v31;
    }
    this->m_nodes.m_Size += v26;
    v32 = this->m_nodes.m_Memory.m_pMemory;
    v33 = this->m_nodes.m_Size - v26;
    this->m_nodes.m_pElements = v32;
    if ( v33 > 0 && v26 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v32[v26], src: (unsigned __int8 *)v32, count: 96 * v33);
  }
  v34 = 0;
  this->m_nSize = 4
                * (this->m_leaves.m_Size
                 + 3
                 * (((1 << this->m_nPower) + 1) * ((1 << this->m_nPower) + 1)
                  + 4 * ((1 << this->m_nPower) * (1 << this->m_nPower) + 2 * this->m_nodes.m_Size)
                  + 171));
  iTri = 0;
  if ( this->m_aVerts.m_Size > 0 )
  {
    numLeaves = 0;
    do
    {
      m_pVerts = pDisp->m_pVerts;
      x = m_pVerts[v34].m_Vert.x;
      v37 = (float *)((char *)&this->m_aVerts.m_Memory.m_pMemory->x + numLeaves);
      numLeaves += 12;
      p_m_Vert = (int)&m_pVerts[v34].m_Vert;
      *v37 = x;
      ++v34;
      v37[1] = *(float *)(p_m_Vert + 4);
      v37[2] = *(float *)(p_m_Vert + 8);
      ++iTri;
    }
    while ( iTri < this->m_aVerts.m_Size );
  }
  iTri = 0;
  if ( this->m_aTris.m_Size > 0 )
  {
    v39 = 0;
    numLeaves = 0;
    do
    {
      CCoreDispInfo::GetTriIndices(this: pDisp, iTri, v1: iVerts, v2: &iVerts[1], v3: &iVerts[2]);
      this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[0].m_IndexDummy ^= (iVerts[0]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[0].m_IndexDummy)
                                                                       & 0x1FF;
      this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[1].m_IndexDummy ^= (iVerts[1]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[1].m_IndexDummy)
                                                                       & 0x1FF;
      this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[2].m_IndexDummy ^= (iVerts[2]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[2].m_IndexDummy)
                                                                       & 0x1FF;
      *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v39] + 3) ^= (*((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v39] + 3)
                                                               ^ (pDisp->m_pTris[iTri].m_uiTags << 6))
                                                              & 0x7C0;
      v40 = 1024;
      if ( (float)((float)(pDisp->m_pVerts[*(unsigned __int16 *)((_BYTE *)&this->m_aTris.m_Memory.m_pMemory->m_TriData[0].m_IndexDummy
                                                               + numLeaves)
                                         & 0x1FF].m_Alpha
                         + pDisp->m_pVerts[*(unsigned __int16 *)((_BYTE *)&this->m_aTris.m_Memory.m_pMemory->m_TriData[1].m_IndexDummy
                                                               + numLeaves)
                                         & 0x1FF].m_Alpha)
                 + pDisp->m_pVerts[*(unsigned __int16 *)((_BYTE *)&this->m_aTris.m_Memory.m_pMemory->m_TriData[2].m_IndexDummy
                                                       + numLeaves)
                                 & 0x1FF].m_Alpha) <= 382.5 )
        v40 = 512;
      *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v39] + 3) |= v40;
      *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v39] + 3) |= 0x40u;
      CDispCollTri::CalcPlane(this: &this->m_aTris.m_Memory.m_pMemory[v39], m_aVerts: &this->m_aVerts);
      CDispCollTri::FindMinMax(this: &this->m_aTris.m_Memory.m_pMemory[v39], m_aVerts: &this->m_aVerts);
      numLeaves += 24;
      ++v39;
      ++iTri;
    }
    while ( iTri < this->m_aTris.m_Size );
  }
  v41 = CHunkAllocCredit::s_DbgInfoStackDepth;
  if ( CHunkAllocCredit::s_DbgInfoStackDepth >= 0 )
  {
    CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth] = nullptr;
    CHunkAllocCredit::s_DbgInfoStackDepth = v41 - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162500
// Name: protected: void CDispCollTree::Cache_Create(class CDispCollTri __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::Cache_Create(CDispCollTree *this, CDispCollTri *pTri, CDispCollTriCache *iTri)
{
  Vector *m_pMemory; // ebx
  const Vector *v4; // esi
  float v5; // xmm0_4
  const Vector *v6; // edi
  const Vector *v7; // ebx
  float z; // xmm0_4
  CDispCollTree *v9; // esi
  Vector vecEdge; // [esp+Ch] [ebp-10h] BYREF
  CDispCollTree *v11; // [esp+18h] [ebp-4h]
  CDispCollTriCache *pCache; // [esp+28h] [ebp+Ch]

  v11 = this;
  m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
  v4 = &m_pMemory[pTri->m_TriData[0].m_IndexDummy & 0x1FF];
  v5 = m_pMemory[pTri->m_TriData[1].m_IndexDummy & 0x1FF].x - v4->x;
  v6 = &m_pMemory[pTri->m_TriData[1].m_IndexDummy & 0x1FF];
  v7 = &m_pMemory[pTri->m_TriData[2].m_IndexDummy & 0x1FF];
  pCache = &this->m_aTrisCache.m_Memory.m_pMemory[(_DWORD)iTri];
  vecEdge.x = v5;
  vecEdge.y = v6->y - v4->y;
  vecEdge.z = v6->z - v4->z;
  CDispCollTree::Cache_EdgeCrossAxisX(this, &vecEdge, vecOnEdge: v4, vecOffEdge: v7, pTri, iPlane: pCache->m_iCrossX);
  CDispCollTree::Cache_EdgeCrossAxisY(
    this: v11,
    &vecEdge,
    vecOnEdge: v4,
    vecOffEdge: v7,
    pTri,
    iPlane: pCache->m_iCrossY);
  CDispCollTree::Cache_EdgeCrossAxisZ(
    this: v11,
    &vecEdge,
    vecOnEdge: v4,
    vecOffEdge: v7,
    pTri,
    iPlane: pCache->m_iCrossZ);
  vecEdge.x = v7->x - v6->x;
  vecEdge.y = v7->y - v6->y;
  vecEdge.z = v7->z - v6->z;
  CDispCollTree::Cache_EdgeCrossAxisX(
    this: v11,
    &vecEdge,
    vecOnEdge: v6,
    vecOffEdge: v4,
    pTri,
    iPlane: &pCache->m_iCrossX[1]);
  CDispCollTree::Cache_EdgeCrossAxisY(
    this: v11,
    &vecEdge,
    vecOnEdge: v6,
    vecOffEdge: v4,
    pTri,
    iPlane: &pCache->m_iCrossY[1]);
  CDispCollTree::Cache_EdgeCrossAxisZ(
    this: v11,
    &vecEdge,
    vecOnEdge: v6,
    vecOffEdge: v4,
    pTri,
    iPlane: &pCache->m_iCrossZ[1]);
  vecEdge.x = v4->x - v7->x;
  vecEdge.y = v4->y - v7->y;
  z = v4->z;
  v9 = v11;
  vecEdge.z = z - v7->z;
  CDispCollTree::Cache_EdgeCrossAxisX(
    this: v11,
    &vecEdge,
    vecOnEdge: v7,
    vecOffEdge: v6,
    pTri,
    iPlane: &pCache->m_iCrossX[2]);
  CDispCollTree::Cache_EdgeCrossAxisY(
    this: v9,
    &vecEdge,
    vecOnEdge: v7,
    vecOffEdge: v6,
    pTri,
    iPlane: &pCache->m_iCrossY[2]);
  CDispCollTree::Cache_EdgeCrossAxisZ(
    this: v9,
    &vecEdge,
    vecOnEdge: v7,
    vecOffEdge: v6,
    pTri,
    iPlane: &pCache->m_iCrossZ[2]);
}

//------------------------------------------------------------------------------
// Address: 0x101626C0
// Name: class CDispCollTree __near * DispCollTrees_Alloc(int)
// Source: json
//------------------------------------------------------------------------------
CDispCollTree *__cdecl DispCollTrees_Alloc(int count)
{
  CDispCollTree *v2; // eax
  CDispCollTree *v3; // edx
  int v4; // esi
  CDispCollTree *v5; // ebx
  CDispCollTree *result; // eax
  int *p_m_iCounter; // ecx
  CDispCollTree *pTrees; // [esp+10h] [ebp+8h]

  v2 = (CDispCollTree *)Hunk_AllocName(size: 244 * count, name: "DispCollTrees_Alloc", bClear: false);
  v3 = v2;
  v4 = 0;
  pTrees = v2;
  g_nTrees = count;
  if ( count > 0 )
  {
    v5 = v2;
    do
    {
      if ( v5 != nullptr )
      {
        CDispCollTree::CDispCollTree(this: v5);
        v3 = pTrees;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < g_nTrees );
  }
  result = nullptr;
  if ( v3 != nullptr )
  {
    if ( count > 0 )
    {
      p_m_iCounter = &v3->m_iCounter;
      do
      {
        *p_m_iCounter = (int)result;
        result = (CDispCollTree *)((char *)result + 1);
        p_m_iCounter += 61;
      }
      while ( (int)result < count );
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10162740
// Name: void DispCollTrees_Free(class CDispCollTree __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispCollTrees_Free(CDispCollTree *pTrees)
{
  int v1; // esi

  v1 = 0;
  if ( g_nTrees <= 0 )
  {
    g_nTrees = 0;
  }
  else
  {
    do
    {
      CDispCollTree::~CDispCollTree(this: pTrees);
      ++v1;
      ++pTrees;
    }
    while ( v1 < g_nTrees );
    g_nTrees = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162780
// Name: public: void CDispCollTree::Cache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::Cache(CDispCollTree *this)
{
  int m_nPower; // ecx
  CDispCollTriCache *v3; // ebx
  int v4; // esi
  int v5; // [esp+4h] [ebp-4h]

  m_nPower = this->m_nPower;
  if ( this->m_aTrisCache.m_Size != 2 * (1 << m_nPower) * (1 << m_nPower) )
  {
    v3 = nullptr;
    this->m_aTrisCache.m_Size = 0;
    v4 = 2 * (1 << m_nPower) * (1 << m_nPower);
    CUtlVector<CDispCollTriCache,CUtlMemory<CDispCollTriCache,int>>::InsertMultipleBefore(
      this: &this->m_aTrisCache,
      elem: 0,
      num: v4);
    if ( v4 > 0 )
    {
      v5 = 0;
      do
      {
        CDispCollTree::Cache_Create(this, pTri: &this->m_aTris.m_Memory.m_pMemory[v5++], iTri: v3);
        v3 = (CDispCollTriCache *)((char *)v3 + 1);
      }
      while ( (int)v3 < v4 );
    }
    CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: (CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *)&g_DispCollPlaneIndexHash);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162800
// Name: public: virtual bool CDispCollTree::Create(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Create(CDispCollTree *this, CCoreDispInfo *pDisp)
{
  this->m_nFlags = pDisp->m_Surf.m_Flags;
  CDispCollTree::AABBTree_CopyDispData(this, pDisp);
  CDispCollTree::AABBTree_CreateLeafs(this);
  if ( this->m_aVerts.m_Size != 0 && this->m_nodes.m_Size != 0 )
  {
    CDispCollTree::AABBTree_GenerateBoxes_r(this, nodeIndex: 0, pMins: &this->m_mins, pMaxs: &this->m_maxs);
    this->m_mins.x = this->m_mins.x - 1.0;
    this->m_maxs.x = this->m_maxs.x + 1.0;
    this->m_mins.y = this->m_mins.y - 1.0;
    this->m_maxs.y = this->m_maxs.y + 1.0;
    this->m_mins.z = this->m_mins.z - 1.0;
    this->m_maxs.z = this->m_maxs.z + 1.0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101628B0
// Name: public: void CDispCollTree::LockCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::LockCache(CDispCollTree *this)
{
  int v2; // eax
  DWORD CurrentThreadId; // eax
  int v4; // eax
  memhandle_t__ *v5; // eax
  CDispCollTree *createParams; // [esp+4h] [ebp-4h] BYREF

  v2 = CDataManagerBase::LockResource(this: &g_DispCollTriCache, handle: this->m_hCache);
  if ( v2 == 0 || *(_DWORD *)(v2 + 188) != *(_DWORD *)(v2 + 136) )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_CacheMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_CacheMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_CacheMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_CacheMutex.m_depth;
    }
    v4 = CDataManagerBase::LockResource(this: &g_DispCollTriCache, handle: this->m_hCache);
    if ( v4 == 0 || *(_DWORD *)(v4 + 188) != *(_DWORD *)(v4 + 136) )
    {
      CDispCollTree::Cache(this);
      createParams = this;
      v5 = CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::CreateResource(
             this: &g_DispCollTriCache,
             &createParams,
             bCreateLocked: false);
      this->m_hCache = v5;
      CDataManagerBase::LockResource(this: &g_DispCollTriCache, handle: v5);
    }
    if ( --s_CacheMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_CacheMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162990
// Name: public: bool CDispCollTree::AABBTree_SweepAABB(struct Ray_t const __near &,class Vector const __near &,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CDispCollTree::AABBTree_SweepAABB@<al>(
        CDispCollTree *this@<ecx>,
        float a2@<ebp>,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        CBaseTrace *pTrace)
{
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm0
  int v10; // edi
  __m128 v11; // xmm7
  __m128 v12; // xmm6
  float y; // edx
  int v14; // ecx
  CDispCollNode *v15; // eax
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm3
  __m128 v22; // xmm7
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  CDispCollLeaf *m_pMemory; // ecx
  int v27; // edi
  int v28; // eax
  _BYTE v30[1552]; // [esp-Ch] [ebp-65Ch] OVERLAPPED
  __m128 v31; // [esp+604h] [ebp-4Ch]
  CDispCollTri *v32; // [esp+62Ch] [ebp-24h]
  Vector v33; // [esp+630h] [ebp-20h] BYREF
  Vector rayDir; // [esp+63Ch] [ebp-14h]
  float flFrac; // [esp+648h] [ebp-8h]
  float retaddr; // [esp+650h] [ebp+0h]

  rayDir.z = a2;
  flFrac = retaddr;
  if ( (this->m_nFlags & 4) != 0 )
    return false;
  v33 = ray->m_Delta.Vector;
  VectorNormalize(vec: &v33);
  rayDir.x = pTrace->fraction;
  *(__m128 *)&v30[96] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->x), (__m128)LODWORD(vecInvDelta->x), 0);
  *(__m128 *)&v30[112] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->y), (__m128)LODWORD(vecInvDelta->y), 0);
  *(__m128 *)&v30[128] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->z), (__m128)LODWORD(vecInvDelta->z), 0);
  *(__m128 *)&v30[16] = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.y), (__m128)LODWORD(ray->m_Start.y), 0);
  v7 = 0;
  v7.m128_f32[0] = ray->m_Extents.x + g_Vec3DispCollEpsilons.x;
  *(__m128 *)&v30[48] = _mm_shuffle_ps(v7, v7, 0);
  v8 = 0;
  v8.m128_f32[0] = ray->m_Extents.y + g_Vec3DispCollEpsilons.y;
  *(__m128 *)&v30[64] = _mm_shuffle_ps(v8, v8, 0);
  v9 = 0;
  v10 = 0;
  v9.m128_f32[0] = ray->m_Extents.z + g_Vec3DispCollEpsilons.z;
  v11 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.x), (__m128)LODWORD(ray->m_Start.x), 0);
  v12 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.z), (__m128)LODWORD(ray->m_Start.z), 0);
  *(__m128 *)v30 = v11;
  *(__m128 *)&v30[32] = v12;
  *(__m128 *)&v30[80] = _mm_shuffle_ps(v9, v9, 0);
  *(_DWORD *)&v30[144] = 0;
  y = 0.0;
  *(_DWORD *)&v30[1520] = 0;
  while ( 1 )
  {
    v14 = *(_DWORD *)&v30[4 * LODWORD(y) + 144];
    if ( v14 >= this->m_nodes.m_Size )
      break;
    v15 = &this->m_nodes.m_Memory.m_pMemory[v14];
    ++LODWORD(y);
    v16 = _mm_mul_ps(
            _mm_add_ps(_mm_sub_ps(v15->m_maxs.y, *(__m128 *)&v30[16]), *(__m128 *)&v30[64]),
            *(__m128 *)&v30[112]);
    v17 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(v15->m_mins.x, v11), *(__m128 *)&v30[48]), *(__m128 *)&v30[96]);
    v18 = _mm_sub_ps(_mm_sub_ps(v15->m_mins.z, v12), *(__m128 *)&v30[80]);
    v19 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(v15->m_maxs.z, v12), *(__m128 *)&v30[80]), *(__m128 *)&v30[128]);
    v20 = _mm_mul_ps(
            _mm_sub_ps(_mm_sub_ps(v15->m_mins.y, *(__m128 *)&v30[16]), *(__m128 *)&v30[64]),
            *(__m128 *)&v30[112]);
    *(__m128 *)&v30[1536] = _mm_add_ps(_mm_sub_ps(v15->m_maxs.x, v11), *(__m128 *)&v30[48]);
    v21 = _mm_mul_ps(v18, *(__m128 *)&v30[128]);
    v22 = _mm_mul_ps(*(__m128 *)&v30[1536], *(__m128 *)&v30[96]);
    v31 = v16;
    v23 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_max_ps(_mm_max_ps(_mm_min_ps(v17, v22), _mm_min_ps(v20, v16)), _mm_min_ps(v21, v19)),
                Four_Zeros),
              _mm_min_ps(
                _mm_min_ps(_mm_min_ps(_mm_max_ps(v17, v22), _mm_max_ps(v20, v16)), _mm_max_ps(v21, v19)),
                Four_Ones)));
    rayDir.y = y;
    if ( v23 != 0 )
    {
      v24 = 4 * v14 + 1;
      if ( (v23 & 1) != 0 )
      {
        *(_DWORD *)&v30[1520] = v10 + 1;
        *(_DWORD *)&v30[4 * *(_DWORD *)&v30[1520] + 144] = v24;
        v10 = *(_DWORD *)&v30[1520];
      }
      if ( (v23 & 2) != 0 )
      {
        *(_DWORD *)&v30[1520] = v10 + 1;
        *(_DWORD *)&v30[4 * *(_DWORD *)&v30[1520] + 144] = v24 + 1;
        v10 = *(_DWORD *)&v30[1520];
        y = rayDir.y;
      }
      if ( (v23 & 4) != 0 )
      {
        *(_DWORD *)&v30[1520] = v10 + 1;
        *(_DWORD *)&v30[4 * *(_DWORD *)&v30[1520] + 144] = v24 + 2;
        v10 = *(_DWORD *)&v30[1520];
        y = rayDir.y;
      }
      if ( (v23 & 8) != 0 )
      {
        *(_DWORD *)&v30[1520] = v10 + 1;
        *(_DWORD *)&v30[4 * *(_DWORD *)&v30[1520] + 144] = v24 + 3;
        v10 = *(_DWORD *)&v30[1520];
      }
    }
    if ( SLODWORD(y) > v10 )
      break;
    v11 = *(__m128 *)v30;
    v12 = *(__m128 *)&v30[32];
  }
  rayDir.y = y;
  if ( SLODWORD(y) <= v10 )
  {
    CDispCollTree::LockCache(this);
    do
    {
      v25 = *(_DWORD *)&v30[4 * LODWORD(rayDir.y) + 144] - this->m_nodes.m_Size;
      m_pMemory = this->m_leaves.m_Memory.m_pMemory;
      v27 = m_pMemory[v25].m_tris[1];
      v28 = m_pMemory[v25].m_tris[0];
      v32 = this->m_aTris.m_Memory.m_pMemory;
      CDispCollTree::SweepAABBTriIntersect(this, ray, rayDir: &v33, iTri: v28, pTri: &v32[v28], pTrace);
      CDispCollTree::SweepAABBTriIntersect(this, ray, rayDir: &v33, iTri: v27, pTri: &v32[v27], pTrace);
      ++LODWORD(rayDir.y);
    }
    while ( SLODWORD(rayDir.y) <= *(int *)&v30[1520] );
    CDataManagerBase::UnlockResource(this: &g_DispCollTriCache, handle: this->m_hCache);
  }
  return rayDir.x > pTrace->fraction;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1015F250
// Name: protected: bool CDispCollTree::ResolveRayPlaneIntersect(float,float,class Vector const __near &,float,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::ResolveRayPlaneIntersect(
        CDispCollTree *this,
        float flStart,
        float flEnd,
        const Vector *vecNormal,
        float flDist,
        CDispCollHelper *pHelper)
{
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4

  if ( flStart > 0.0 && flEnd > 0.0 )
    return 0;
  if ( flStart >= 0.0 || flEnd >= 0.0 )
  {
    v7 = flStart - flEnd;
    if ( flStart < 0.0 || flEnd > 0.0 )
    {
      if ( (float)(flStart - flEnd) == 0.0 )
        v9 = 0.0;
      else
        v9 = (float)(flStart + 0.03125) / v7;
      if ( pHelper->m_flEndFrac > v9 )
        pHelper->m_flEndFrac = v9;
    }
    else
    {
      if ( (float)(flStart - flEnd) == 0.0 )
        v8 = 0.0;
      else
        v8 = (float)(flStart - 0.03125) / v7;
      if ( v8 > pHelper->m_flStartFrac )
      {
        pHelper->m_flStartFrac = v8;
        pHelper->m_vecImpactNormal = *vecNormal;
        pHelper->m_flImpactDist = flDist;
        return 1;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F310
// Name: protected: bool CDispCollTree::FacePlane(struct Ray_t const __near &,class Vector const __near &,class CDispCollTri __near *,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::FacePlane(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *rayDir,
        CDispCollTri *pTri,
        CDispCollHelper *pHelper)
{
  float x; // xmm6_4
  float v7; // xmm0_4
  float y; // xmm3_4
  float v9; // xmm5_4
  float z; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float flDist; // [esp+24h] [ebp+8h]

  x = ray->m_Extents.x;
  v7 = pTri->m_vecNormal.x;
  if ( v7 >= 0.0 )
    x = -x;
  y = pTri->m_vecNormal.y;
  v9 = ray->m_Extents.y;
  if ( y >= 0.0 )
    v9 = -v9;
  z = pTri->m_vecNormal.z;
  v11 = ray->m_Extents.z;
  if ( z >= 0.0 )
    v11 = -v11;
  flDist = pTri->m_flDist;
  v12 = flDist - (float)((float)((float)(y * v9) + (float)(v7 * x)) + (float)(z * v11));
  return CDispCollTree::ResolveRayPlaneIntersect(
           this,
           flStart: (float)((float)((float)(y * ray->m_Start.y) + (float)(v7 * ray->m_Start.x)) + (float)(z * ray->m_Start.z))
         - v12,
           flEnd: (float)((float)((float)(v7 * (float)(ray->m_Start.x + ray->m_Delta.x))
                         + (float)(y * (float)(ray->m_Delta.y + ray->m_Start.y)))
                 + (float)(z * (float)(ray->m_Delta.z + ray->m_Start.z)))
         - v12,
           vecNormal: &pTri->m_vecNormal,
           flDist,
           pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x1015F420
// Name: public: bool CDispCollTree::PointInBounds(class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDispCollTree::PointInBounds(
        CDispCollTree *this,
        const Vector *vecBoxCenter,
        const Vector *vecBoxMin,
        const Vector *vecBoxMax,
        bool bPoint)
{
  float y; // xmm4_4
  float z; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  Vector vecExpandBounds[2]; // [esp+0h] [ebp-18h] BYREF

  if ( bPoint )
    return IsPointInBox(pt: vecBoxCenter, boxMin: &this->m_mins, boxMax: &this->m_maxs);
  y = this->m_mins.y;
  z = this->m_mins.z;
  v8 = (float)(vecBoxMax->y - vecBoxMin->y) * 0.5;
  v9 = (float)(vecBoxMax->x - vecBoxMin->x) * 0.5;
  v10 = (float)(vecBoxMax->z - vecBoxMin->z) * 0.5;
  vecExpandBounds[0].x = this->m_mins.x - v9;
  v11 = this->m_maxs.x + v9;
  v12 = y - v8;
  v13 = this->m_maxs.y + v8;
  v14 = this->m_maxs.z + v10;
  vecExpandBounds[0].y = v12;
  vecExpandBounds[0].z = z - v10;
  vecExpandBounds[1].x = v11;
  vecExpandBounds[1].y = v13;
  vecExpandBounds[1].z = v14;
  return IsPointInBox(pt: vecBoxCenter, boxMin: vecExpandBounds, boxMax: &vecExpandBounds[1]);
}

//------------------------------------------------------------------------------
// Address: 0x1015F4F0
// Name: public: virtual void CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::Lock(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015F530
// Name: public: virtual bool CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::TryLock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::TryLock(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this)
{
  DWORD CurrentThreadId; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_mutex, CurrentThreadId, 0) != 0 )
  {
    return 0;
  }
  ++this->m_mutex.m_depth;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015F560
// Name: public: virtual void CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::Unlock(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this)
{
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)&this->m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1015F660
// Name: public: struct memhandle_t__ __near * CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::CreateResource(class CDispCollTree __near * const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::CreateResource(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this,
        CDispCollTree *const *createParams,
        bool bCreateLocked)
{
  _DWORD *v4; // edi
  unsigned __int16 Handle; // ax
  memhandle_t__ *v6; // edi

  CDataManagerBase::EnsureCapacity(
    this,
    size: 18 * (*createParams)->m_aTrisCache.m_Size + 12 * (*createParams)->m_aEdgePlanes.m_Size);
  v4 = *createParams;
  this->Lock(this);
  Handle = CDataManagerBase::CreateHandle(this, bCreateLocked);
  v6 = CDataManagerBase::StoreResourceInHandle(
         this,
         memoryIndex: Handle,
         pStore: v4,
         realSize: 18 * v4[47] + 12 * v4[52]);
  this->Unlock(this);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1015F6E0
// Name: private: virtual unsigned int CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::GetRealSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::GetRealSize(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this,
        _DWORD *pStore)
{
  return 18 * pStore[47] + 12 * pStore[52];
}

//------------------------------------------------------------------------------
// Address: 0x1015F710
// Name: public: void CDispCollTri::CalcPlane(class CDispVector<class Vector> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTri::CalcPlane(CDispCollTri *this, CDispVector<Vector> *m_aVerts)
{
  int v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  Vector *p_m_vecNormal; // edi
  __int16 v11; // cx
  int i; // ecx

  v3 = this->m_TriData[1].m_IndexDummy & 0x1FF;
  v4 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].z
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v5 = m_aVerts->m_Memory.m_pMemory[v3].y - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v6 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].y
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v7 = m_aVerts->m_Memory.m_pMemory[v3].z - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v8 = m_aVerts->m_Memory.m_pMemory[v3].x - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v9 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].x
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  p_m_vecNormal = &this->m_vecNormal;
  this->m_vecNormal.x = (float)(v6 * v7) - (float)(v4 * v5);
  this->m_vecNormal.y = (float)(v4 * v8) - (float)(v7 * v9);
  this->m_vecNormal.z = (float)(v5 * v9) - (float)(v6 * v8);
  VectorNormalize(vec: &this->m_vecNormal);
  v11 = *((_WORD *)this + 3) & 0xFFC0 | 0x28;
  this->m_flDist = (float)((float)(m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y
                                 * this->m_vecNormal.y)
                         + (float)(this->m_vecNormal.x
                                 * m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x))
                 + (float)(m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z * this->m_vecNormal.z);
  *((_WORD *)this + 3) = v11;
  for ( i = 0; i < 3; ++i )
  {
    if ( p_m_vecNormal->x < 0.0 )
      *((_WORD *)this + 3) |= (1 << i) & 7;
    if ( p_m_vecNormal->x == 1.0 )
      *((_WORD *)this + 3) ^= (*((_WORD *)this + 3) ^ (8 * i)) & 0x38;
    p_m_vecNormal = (Vector *)((char *)p_m_vecNormal + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015F880
// Name: public: void CDispCollTri::FindMinMax(class CDispVector<class Vector> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTri::FindMinMax(CDispCollTri *this, CDispVector<Vector> *m_aVerts)
{
  Vector *m_pMemory; // eax
  float x; // xmm0_4
  char v4; // si
  float v5; // xmm1_4
  int v6; // edi
  float v7; // xmm2_4
  float v8; // xmm0_4
  char v9; // al
  __int16 v10; // ax
  unsigned __int16 m_IndexDummy; // si
  unsigned __int16 v12; // ax
  Vector *v13; // edx
  float y; // xmm2_4
  int v15; // esi
  char v16; // di
  float v17; // xmm0_4
  float v18; // xmm0_4
  int v19; // esi
  char v20; // al
  unsigned __int16 v21; // ax
  Vector *v22; // edx
  char v23; // di
  float z; // xmm0_4
  float v25; // xmm0_4
  char v26; // al

  m_pMemory = m_aVerts->m_Memory.m_pMemory;
  x = m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v4 = 0;
  if ( x > m_aVerts->m_Memory.m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x )
  {
    x = m_aVerts->m_Memory.m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x;
    v4 = 1;
  }
  if ( x > m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].x )
    v4 = 2;
  v5 = m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x;
  v6 = this->m_TriData[2].m_IndexDummy & 0x1FF;
  v7 = m_pMemory[v6].x;
  v8 = m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v9 = 0;
  if ( v5 > v8 )
  {
    v8 = v5;
    v9 = 1;
  }
  if ( v7 > v8 )
    v9 = 2;
  v10 = (v4 & 3 | (unsigned __int16)(4 * (v9 & 3))) << 9;
  m_IndexDummy = this->m_TriData[1].m_IndexDummy;
  v12 = this->m_TriData[0].m_IndexDummy & 0xE1FF | v10;
  this->m_TriData[0].m_IndexDummy = v12;
  v13 = m_aVerts->m_Memory.m_pMemory;
  y = m_aVerts->m_Memory.m_pMemory[v6].y;
  v15 = m_IndexDummy & 0x1FF;
  v16 = 0;
  v17 = m_aVerts->m_Memory.m_pMemory[v12 & 0x1FF].y;
  if ( v17 > m_aVerts->m_Memory.m_pMemory[v15].y )
  {
    v17 = m_aVerts->m_Memory.m_pMemory[v15].y;
    v16 = 1;
  }
  if ( v17 > y )
    v16 = 2;
  v18 = v13[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v19 = this->m_TriData[2].m_IndexDummy & 0x1FF;
  v20 = 0;
  if ( v13[this->m_TriData[1].m_IndexDummy & 0x1FF].y > v18 )
  {
    v18 = v13[this->m_TriData[1].m_IndexDummy & 0x1FF].y;
    v20 = 1;
  }
  if ( v13[v19].y > v18 )
    v20 = 2;
  v21 = this->m_TriData[1].m_IndexDummy & 0xE1FF | ((v16 & 3 | (unsigned __int16)(4 * (v20 & 3))) << 9);
  this->m_TriData[1].m_IndexDummy = v21;
  v22 = m_aVerts->m_Memory.m_pMemory;
  v23 = 0;
  z = m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  if ( z > m_aVerts->m_Memory.m_pMemory[v21 & 0x1FF].z )
  {
    z = m_aVerts->m_Memory.m_pMemory[v21 & 0x1FF].z;
    v23 = 1;
  }
  if ( z > m_aVerts->m_Memory.m_pMemory[v19].z )
    v23 = 2;
  v25 = v22[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v26 = 0;
  if ( v22[this->m_TriData[1].m_IndexDummy & 0x1FF].z > v25 )
  {
    v25 = v22[this->m_TriData[1].m_IndexDummy & 0x1FF].z;
    v26 = 1;
  }
  if ( v22[this->m_TriData[2].m_IndexDummy & 0x1FF].z > v25 )
    v26 = 2;
  this->m_TriData[2].m_IndexDummy = this->m_TriData[2].m_IndexDummy & 0xE1FF
                                  | ((v23 & 3 | (unsigned __int16)(4 * (v26 & 3))) << 9);
}

//------------------------------------------------------------------------------
// Address: 0x1015FAC0
// Name: protected: bool CDispCollTree::EdgeCrossAxis<0>(struct Ray_t const __near &,unsigned short,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::EdgeCrossAxis<0>(
        CDispCollTree *this,
        const Ray_t *ray,
        unsigned __int16 iPlane,
        CDispCollHelper *pHelper)
{
  Vector *m_pMemory; // edx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  Vector flStart; // [esp+0h] [ebp-Ch] BYREF

  if ( iPlane == 0xFFFF )
    return 1;
  m_pMemory = this->m_aEdgePlanes.m_Memory.m_pMemory;
  if ( (iPlane & 0x8000) != 0 )
  {
    x = -m_pMemory[iPlane & 0x7FFF].x;
    y = -m_pMemory[iPlane & 0x7FFF].y;
    z = -m_pMemory[iPlane & 0x7FFF].z;
  }
  else
  {
    x = m_pMemory[iPlane].x;
    y = m_pMemory[iPlane].y;
    z = m_pMemory[iPlane].z;
  }
  v9 = ray->m_Extents.y;
  flStart.z = z;
  flStart.y = y;
  flStart.x = 0.0;
  if ( y >= 0.0 )
    v9 = -v9;
  v10 = ray->m_Extents.z;
  if ( z >= 0.0 )
    v10 = -v10;
  return CDispCollTree::ResolveRayPlaneIntersect(
           this,
           flStart: (float)((float)(y * ray->m_Start.y) + (float)(z * ray->m_Start.z))
         - (float)(x - (float)((float)(v10 * z) + (float)(v9 * y))),
           flEnd: (float)((float)((float)(ray->m_Delta.z + ray->m_Start.z) * z)
                 + (float)((float)(ray->m_Delta.y + ray->m_Start.y) * y))
         - (float)(x - (float)((float)(v10 * z) + (float)(v9 * y))),
           vecNormal: &flStart,
           flDist: x,
           pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x1015FBF0
// Name: protected: bool CDispCollTree::EdgeCrossAxis<1>(struct Ray_t const __near &,unsigned short,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::EdgeCrossAxis<1>(
        CDispCollTree *this,
        const Ray_t *ray,
        unsigned __int16 iPlane,
        CDispCollHelper *pHelper)
{
  Vector *m_pMemory; // edx
  float x; // xmm5_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  Vector flStart; // [esp+0h] [ebp-Ch] BYREF

  if ( iPlane == 0xFFFF )
    return 1;
  m_pMemory = this->m_aEdgePlanes.m_Memory.m_pMemory;
  if ( (iPlane & 0x8000) != 0 )
  {
    x = -m_pMemory[iPlane & 0x7FFF].x;
    y = -m_pMemory[iPlane & 0x7FFF].y;
    z = -m_pMemory[iPlane & 0x7FFF].z;
  }
  else
  {
    x = m_pMemory[iPlane].x;
    y = m_pMemory[iPlane].y;
    z = m_pMemory[iPlane].z;
  }
  v9 = ray->m_Extents.z;
  flStart.z = z;
  flStart.x = x;
  flStart.y = 0.0;
  if ( z >= 0.0 )
    v9 = -v9;
  v10 = ray->m_Extents.x;
  if ( x >= 0.0 )
    v10 = -v10;
  return CDispCollTree::ResolveRayPlaneIntersect(
           this,
           flStart: (float)((float)(z * ray->m_Start.z) + (float)(ray->m_Start.x * x))
         - (float)(y - (float)((float)(v9 * z) + (float)(v10 * x))),
           flEnd: (float)((float)((float)(ray->m_Delta.z + ray->m_Start.z) * z)
                 + (float)((float)(ray->m_Delta.x + ray->m_Start.x) * x))
         - (float)(y - (float)((float)(v9 * z) + (float)(v10 * x))),
           vecNormal: &flStart,
           flDist: y,
           pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x1015FD10
// Name: protected: bool CDispCollTree::EdgeCrossAxis<2>(struct Ray_t const __near &,unsigned short,class CDispCollHelper __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::EdgeCrossAxis<2>(
        CDispCollTree *this,
        const Ray_t *ray,
        unsigned __int16 iPlane,
        CDispCollHelper *pHelper)
{
  Vector *m_pMemory; // edx
  float x; // xmm4_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  Vector flStart; // [esp+0h] [ebp-Ch] BYREF

  if ( iPlane == 0xFFFF )
    return 1;
  m_pMemory = this->m_aEdgePlanes.m_Memory.m_pMemory;
  if ( (iPlane & 0x8000) != 0 )
  {
    x = -m_pMemory[iPlane & 0x7FFF].x;
    y = -m_pMemory[iPlane & 0x7FFF].y;
    z = -m_pMemory[iPlane & 0x7FFF].z;
  }
  else
  {
    x = m_pMemory[iPlane].x;
    y = m_pMemory[iPlane].y;
    z = m_pMemory[iPlane].z;
  }
  v9 = ray->m_Extents.x;
  flStart.y = y;
  flStart.x = x;
  flStart.z = 0.0;
  if ( x >= 0.0 )
    v9 = -v9;
  v10 = ray->m_Extents.y;
  if ( y >= 0.0 )
    v10 = -v10;
  return CDispCollTree::ResolveRayPlaneIntersect(
           this,
           flStart: (float)((float)(y * ray->m_Start.y) + (float)(ray->m_Start.x * x))
         - (float)(z - (float)((float)(v10 * y) + (float)(v9 * x))),
           flEnd: (float)((float)((float)(ray->m_Delta.y + ray->m_Start.y) * y)
                 + (float)((float)(ray->m_Delta.x + ray->m_Start.x) * x))
         - (float)(z - (float)((float)(v10 * y) + (float)(v9 * x))),
           vecNormal: &flStart,
           flDist: z,
           pHelper);
}

//------------------------------------------------------------------------------
// Address: 0x101600A0
// Name: protected: void CDispCollTree::AABBTree_GenerateBoxes_r(int,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDispCollTree::AABBTree_GenerateBoxes_r(
        CDispCollTree *this,
        int nodeIndex,
        Vector *pMins,
        Vector *pMaxs)
{
  int m_Size; // ecx
  const CDispCollTri *v7; // eax
  CDispCollNode *m_pMemory; // eax
  int v9; // ecx
  __m128 x; // xmm1
  __m128 y; // xmm2
  CDispCollNode *v12; // eax
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  CDispCollNode *v18; // edx
  __m128 v19; // xmm1
  int p_m_maxs; // eax
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  _BYTE childMaxs[52]; // [esp+8h] [ebp-6Ch] OVERLAPPED BYREF
  _BYTE childMins[52]; // [esp+3Ch] [ebp-38h] OVERLAPPED BYREF
  int i; // [esp+70h] [ebp-4h]
  int nodeIndexa; // [esp+7Ch] [ebp+8h]
  const CDispCollTri *tria; // [esp+84h] [ebp+10h]
  const CDispCollTri *tri; // [esp+84h] [ebp+10h]

  ClearBounds(mins: pMins, maxs: pMaxs);
  m_Size = this->m_nodes.m_Size;
  if ( nodeIndex < m_Size )
  {
    i = 4 * nodeIndex + 1;
    v7 = nullptr;
    for ( tri = nullptr; ; v7 = tri )
    {
      CDispCollTree::AABBTree_GenerateBoxes_r(
        this,
        nodeIndex: i,
        pMins: (Vector *)&childMins[(_DWORD)v7],
        pMaxs: (Vector *)&childMaxs[(_DWORD)v7]);
      AddPointToBounds(v: (const Vector *)&childMins[(_DWORD)tri], mins: pMins, maxs: pMaxs);
      AddPointToBounds(v: (const Vector *)&childMaxs[(_DWORD)tri], mins: pMins, maxs: pMaxs);
      ++i;
      tri = (const CDispCollTri *)((char *)tri + 12);
      if ( (int)tri >= 48 )
        break;
    }
    m_pMemory = this->m_nodes.m_Memory.m_pMemory;
    v9 = nodeIndex;
    m_pMemory[v9].m_mins.x = *(__m128 *)childMins;
    x = m_pMemory[nodeIndex].m_mins.x;
    m_pMemory[v9].m_mins.y = *(__m128 *)&childMins[12];
    m_pMemory[v9].m_mins.z = *(__m128 *)&childMins[24];
    y = m_pMemory[nodeIndex].m_mins.y;
    v12 = &m_pMemory[nodeIndex];
    v13 = _mm_shuffle_ps(x, y, 68);
    v14 = _mm_shuffle_ps(x, y, 238);
    z = v12->m_mins.z;
    v16 = _mm_shuffle_ps(z, *(__m128 *)&childMins[36], 238);
    v17 = _mm_shuffle_ps(z, *(__m128 *)&childMins[36], 68);
    v12->m_mins.x = _mm_shuffle_ps(v13, v17, 136);
    v12->m_mins.y = _mm_shuffle_ps(v13, v17, 221);
    v12->m_mins.z = _mm_shuffle_ps(v14, v16, 136);
    v18 = this->m_nodes.m_Memory.m_pMemory;
    v18[v9].m_maxs.x = *(__m128 *)childMaxs;
    v19 = v18[nodeIndex].m_maxs.x;
    p_m_maxs = (int)&v18[nodeIndex].m_maxs;
    *(_OWORD *)(p_m_maxs + 16) = *(_OWORD *)&childMaxs[12];
    *(_OWORD *)(p_m_maxs + 32) = *(_OWORD *)&childMaxs[24];
    v21 = v18[nodeIndex].m_maxs.y;
    v22 = _mm_shuffle_ps(v19, v21, 68);
    v23 = _mm_shuffle_ps(v19, v21, 238);
    v24 = _mm_shuffle_ps(v18[nodeIndex].m_maxs.z, *(__m128 *)&childMaxs[36], 68);
    v25 = _mm_shuffle_ps(v18[nodeIndex].m_maxs.z, *(__m128 *)&childMaxs[36], 238);
    *(__m128 *)p_m_maxs = _mm_shuffle_ps(v22, v24, 136);
    *(__m128 *)(p_m_maxs + 16) = _mm_shuffle_ps(v22, v24, 221);
    *(__m128 *)(p_m_maxs + 32) = _mm_shuffle_ps(v23, v25, 136);
  }
  else
  {
    nodeIndexa = 2 * (nodeIndex - m_Size);
    for ( i = 2; i != 0; --i )
    {
      tria = &this->m_aTris.m_Memory.m_pMemory[this->m_leaves.m_Memory.m_pMemory->m_tris[nodeIndexa]];
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[0].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[1].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[2].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      ++nodeIndexa;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101602B0
// Name: protected: void CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(struct Ray_t const __near &,class Vector const __near &,int,struct RayDispOutput_t __near &,class CDispCollTri __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(
        CDispCollTree *this@<ecx>,
        float a2@<ebp>,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        int iNode,
        RayDispOutput_t *output,
        CDispCollTri **pImpactTri)
{
  CDispCollTree *v7; // esi
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  float v12; // edx
  int v13; // edi
  __m128 v14; // xmm7
  __m128 v15; // xmm6
  int v16; // ecx
  __m128 *p_x; // eax
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm3
  __m128 v24; // xmm7
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  CDispCollLeaf *m_pMemory; // ecx
  int v30; // edx
  int v31; // eax
  CDispCollTri *v32; // ecx
  CDispCollTri *v33; // esi
  CDispCollTri *v34; // ecx
  float v35; // xmm2_4
  CDispCollTri *v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  CDispCollTri *v39; // xmm0_4
  float v40; // xmm1_4
  _BYTE v41[1552]; // [esp-Ch] [ebp-65Ch] OVERLAPPED
  __m128 v42; // [esp+604h] [ebp-4Ch]
  CDispCollTri *v43; // [esp+62Ch] [ebp-24h]
  CDispCollTree *v44; // [esp+630h] [ebp-20h]
  float v45; // [esp+634h] [ebp-1Ch] BYREF
  CDispCollTri *pTri1; // [esp+638h] [ebp-18h] BYREF
  float v47; // [esp+63Ch] [ebp-14h] BYREF
  float flU; // [esp+640h] [ebp-10h]
  float flV; // [esp+644h] [ebp-Ch]
  float flT; // [esp+648h] [ebp-8h]
  float retaddr; // [esp+650h] [ebp+0h]

  flV = a2;
  flT = retaddr;
  v7 = this;
  v44 = this;
  *(__m128 *)&v41[96] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->x), (__m128)LODWORD(vecInvDelta->x), 0);
  *(__m128 *)&v41[112] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->y), (__m128)LODWORD(vecInvDelta->y), 0);
  *(__m128 *)&v41[128] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->z), (__m128)LODWORD(vecInvDelta->z), 0);
  *(__m128 *)&v41[16] = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.y), (__m128)LODWORD(ray->m_Start.y), 0);
  v9 = 0;
  v9.m128_f32[0] = ray->m_Extents.x + 0.03125;
  *(__m128 *)&v41[48] = _mm_shuffle_ps(v9, v9, 0);
  v10 = 0;
  v10.m128_f32[0] = ray->m_Extents.y + 0.03125;
  *(__m128 *)&v41[64] = _mm_shuffle_ps(v10, v10, 0);
  v11 = 0;
  v12 = 0.0;
  v11.m128_f32[0] = ray->m_Extents.z + 0.03125;
  v13 = 0;
  v14 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.x), (__m128)LODWORD(ray->m_Start.x), 0);
  v15 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.z), (__m128)LODWORD(ray->m_Start.z), 0);
  *(__m128 *)v41 = v14;
  *(__m128 *)&v41[32] = v15;
  *(__m128 *)&v41[80] = _mm_shuffle_ps(v11, v11, 0);
  *(_DWORD *)&v41[144] = iNode;
  *(_DWORD *)&v41[1520] = 0;
  while ( 1 )
  {
    v16 = *(_DWORD *)&v41[4 * LODWORD(v12) + 144];
    if ( v16 >= v7->m_nodes.m_Size )
      break;
    p_x = &v7->m_nodes.m_Memory.m_pMemory[v16].m_mins.x;
    ++LODWORD(v12);
    v18 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(p_x[4], *(__m128 *)&v41[16]), *(__m128 *)&v41[64]), *(__m128 *)&v41[112]);
    v19 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(*p_x, v14), *(__m128 *)&v41[48]), *(__m128 *)&v41[96]);
    v20 = _mm_sub_ps(_mm_sub_ps(p_x[2], v15), *(__m128 *)&v41[80]);
    v21 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(p_x[5], v15), *(__m128 *)&v41[80]), *(__m128 *)&v41[128]);
    v22 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(p_x[1], *(__m128 *)&v41[16]), *(__m128 *)&v41[64]), *(__m128 *)&v41[112]);
    *(__m128 *)&v41[1536] = _mm_add_ps(_mm_sub_ps(p_x[3], v14), *(__m128 *)&v41[48]);
    v23 = _mm_mul_ps(v20, *(__m128 *)&v41[128]);
    v24 = _mm_mul_ps(*(__m128 *)&v41[1536], *(__m128 *)&v41[96]);
    v42 = v18;
    v25 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_max_ps(_mm_max_ps(_mm_min_ps(v19, v24), _mm_min_ps(v22, v18)), _mm_min_ps(v23, v21)),
                Four_Zeros),
              _mm_min_ps(
                _mm_min_ps(_mm_min_ps(_mm_max_ps(v19, v24), _mm_max_ps(v22, v18)), _mm_max_ps(v23, v21)),
                Four_Ones)));
    flU = v12;
    if ( v25 != 0 )
    {
      v26 = 4 * v16 + 1;
      if ( (v25 & 1) != 0 )
      {
        *(_DWORD *)&v41[1520] = v13 + 1;
        *(_DWORD *)&v41[4 * *(_DWORD *)&v41[1520] + 144] = v26;
        v13 = *(_DWORD *)&v41[1520];
      }
      if ( (v25 & 2) != 0 )
      {
        *(_DWORD *)&v41[1520] = v13 + 1;
        *(_DWORD *)&v41[4 * *(_DWORD *)&v41[1520] + 144] = v26 + 1;
        v13 = *(_DWORD *)&v41[1520];
        v12 = flU;
      }
      if ( (v25 & 4) != 0 )
      {
        *(_DWORD *)&v41[1520] = v13 + 1;
        *(_DWORD *)&v41[4 * *(_DWORD *)&v41[1520] + 144] = v26 + 2;
        v13 = *(_DWORD *)&v41[1520];
        v12 = flU;
      }
      if ( (v25 & 8) != 0 )
      {
        *(_DWORD *)&v41[1520] = v13 + 1;
        *(_DWORD *)&v41[4 * *(_DWORD *)&v41[1520] + 144] = v26 + 3;
        v13 = *(_DWORD *)&v41[1520];
      }
    }
    if ( SLODWORD(v12) > v13 )
    {
      v27 = LODWORD(v12);
      flU = v12;
      goto LABEL_15;
    }
    v14 = *(__m128 *)v41;
    v15 = *(__m128 *)&v41[32];
  }
  v27 = LODWORD(v12);
  flU = v12;
LABEL_15:
  if ( SLODWORD(v12) <= v13 )
  {
    do
    {
      v28 = *(_DWORD *)&v41[4 * v27 + 144] - v7->m_nodes.m_Size;
      m_pMemory = v7->m_leaves.m_Memory.m_pMemory;
      v30 = m_pMemory[v28].m_tris[0];
      v31 = m_pMemory[v28].m_tris[1];
      v32 = v7->m_aTris.m_Memory.m_pMemory;
      v33 = &v32[v30];
      LOWORD(v30) = v33->m_TriData[0].m_IndexDummy;
      v34 = &v32[v31];
      LOWORD(v31) = v33->m_TriData[1].m_IndexDummy;
      v43 = v34;
      if ( ComputeIntersectionBarycentricCoordinates(
             ray,
             v1: &v44->m_aVerts.m_Memory.m_pMemory[v30 & 0x1FF],
             v2: &v44->m_aVerts.m_Memory.m_pMemory[v33->m_TriData[2].m_IndexDummy & 0x1FF],
             v3: &v44->m_aVerts.m_Memory.m_pMemory[v31 & 0x1FF],
             u: &v45,
             v: (float *)&pTri1,
             t: &v47) )
      {
        v35 = v45;
        if ( v45 >= 0.0 )
        {
          v36 = pTri1;
          if ( *(float *)&pTri1 >= 0.0 && (float)(v45 + *(float *)&pTri1) <= 1.0 )
          {
            v37 = v47;
            if ( v47 > 0.0 && output->dist > v47 )
            {
              *pImpactTri = v33;
              output->u = v35;
              LODWORD(output->v) = v36;
              output->dist = v37;
            }
          }
        }
      }
      v7 = v44;
      if ( ComputeIntersectionBarycentricCoordinates(
             ray,
             v1: &v44->m_aVerts.m_Memory.m_pMemory[v43->m_TriData[0].m_IndexDummy & 0x1FF],
             v2: &v44->m_aVerts.m_Memory.m_pMemory[v43->m_TriData[2].m_IndexDummy & 0x1FF],
             v3: &v44->m_aVerts.m_Memory.m_pMemory[v43->m_TriData[1].m_IndexDummy & 0x1FF],
             u: &v45,
             v: (float *)&pTri1,
             t: &v47) )
      {
        v38 = v45;
        if ( v45 >= 0.0 )
        {
          v39 = pTri1;
          if ( *(float *)&pTri1 >= 0.0 && (float)(v45 + *(float *)&pTri1) <= 1.0 )
          {
            v40 = v47;
            if ( v47 > 0.0 && output->dist > v47 )
            {
              *pImpactTri = v43;
              output->u = v38;
              LODWORD(output->v) = v39;
              output->dist = v40;
            }
          }
        }
      }
      v27 = LODWORD(flU) + 1;
      LODWORD(flU) = v27;
    }
    while ( v27 <= *(int *)&v41[1520] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101606E0
// Name: protected: void CDispCollTree::AABBTree_TreeTrisRayTest(struct Ray_t const __near &,class Vector const __near &,int,class CBaseTrace __near *,bool,class CDispCollTri __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDispCollTree::AABBTree_TreeTrisRayTest(
        CDispCollTree *this@<ecx>,
        int a2@<ebp>,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        int iNode,
        CBaseTrace *pTrace,
        int bSide,
        CDispCollTri **pImpactTri)
{
  CDispCollTree *v8; // esi
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  CDispCollTri *v13; // edx
  int v14; // edi
  __m128 v15; // xmm7
  __m128 v16; // xmm6
  int v17; // ecx
  __m128 *p_x; // eax
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm7
  int v26; // eax
  int v27; // ecx
  CDispCollTri *v28; // eax
  int v29; // eax
  CDispCollLeaf *m_pMemory; // ecx
  int v31; // edx
  int v32; // eax
  CDispCollTri *v33; // ecx
  CDispCollTri *v34; // esi
  CDispCollTri *v35; // ecx
  double v36; // st7
  double v37; // st7
  CDispCollTri *v38; // edx
  _BYTE v39[1552]; // [esp-Ch] [ebp-64Ch] OVERLAPPED
  __m128 v40; // [esp+604h] [ebp-3Ch]
  CDispCollTri *v41; // [esp+624h] [ebp-1Ch]
  CDispCollTree *v42; // [esp+628h] [ebp-18h]
  float v43; // [esp+62Ch] [ebp-14h]
  CDispCollTri *pTri1; // [esp+630h] [ebp-10h]
  int v45; // [esp+634h] [ebp-Ch]
  float flFrac; // [esp+638h] [ebp-8h]
  float retaddr; // [esp+640h] [ebp+0h]

  v45 = a2;
  flFrac = retaddr;
  v8 = this;
  v42 = this;
  *(__m128 *)&v39[96] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->x), (__m128)LODWORD(vecInvDelta->x), 0);
  *(__m128 *)&v39[112] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->y), (__m128)LODWORD(vecInvDelta->y), 0);
  *(__m128 *)&v39[128] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->z), (__m128)LODWORD(vecInvDelta->z), 0);
  *(__m128 *)&v39[16] = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.y), (__m128)LODWORD(ray->m_Start.y), 0);
  v10 = 0;
  v10.m128_f32[0] = ray->m_Extents.x + 0.03125;
  *(__m128 *)&v39[48] = _mm_shuffle_ps(v10, v10, 0);
  v11 = 0;
  v11.m128_f32[0] = ray->m_Extents.y + 0.03125;
  *(__m128 *)&v39[64] = _mm_shuffle_ps(v11, v11, 0);
  v12 = 0;
  v13 = nullptr;
  v12.m128_f32[0] = ray->m_Extents.z + 0.03125;
  v14 = 0;
  v15 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.x), (__m128)LODWORD(ray->m_Start.x), 0);
  v16 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.z), (__m128)LODWORD(ray->m_Start.z), 0);
  *(__m128 *)v39 = v15;
  *(__m128 *)&v39[32] = v16;
  *(__m128 *)&v39[80] = _mm_shuffle_ps(v12, v12, 0);
  *(_DWORD *)&v39[144] = iNode;
  *(_DWORD *)&v39[1520] = 0;
  while ( 1 )
  {
    v17 = *(_DWORD *)&v39[4 * (_DWORD)v13 + 144];
    if ( v17 >= v8->m_nodes.m_Size )
      break;
    p_x = &v8->m_nodes.m_Memory.m_pMemory[v17].m_mins.x;
    v13 = (CDispCollTri *)((char *)v13 + 1);
    v19 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(p_x[4], *(__m128 *)&v39[16]), *(__m128 *)&v39[64]), *(__m128 *)&v39[112]);
    v20 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(*p_x, v15), *(__m128 *)&v39[48]), *(__m128 *)&v39[96]);
    v21 = _mm_sub_ps(_mm_sub_ps(p_x[2], v16), *(__m128 *)&v39[80]);
    v22 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(p_x[5], v16), *(__m128 *)&v39[80]), *(__m128 *)&v39[128]);
    v23 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(p_x[1], *(__m128 *)&v39[16]), *(__m128 *)&v39[64]), *(__m128 *)&v39[112]);
    *(__m128 *)&v39[1536] = _mm_add_ps(_mm_sub_ps(p_x[3], v15), *(__m128 *)&v39[48]);
    v24 = _mm_mul_ps(v21, *(__m128 *)&v39[128]);
    v25 = _mm_mul_ps(*(__m128 *)&v39[1536], *(__m128 *)&v39[96]);
    v40 = v19;
    v26 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_max_ps(_mm_max_ps(_mm_min_ps(v20, v25), _mm_min_ps(v23, v19)), _mm_min_ps(v24, v22)),
                Four_Zeros),
              _mm_min_ps(
                _mm_min_ps(_mm_min_ps(_mm_max_ps(v20, v25), _mm_max_ps(v23, v19)), _mm_max_ps(v24, v22)),
                Four_Ones)));
    pTri1 = v13;
    if ( v26 != 0 )
    {
      v27 = 4 * v17 + 1;
      if ( (v26 & 1) != 0 )
      {
        *(_DWORD *)&v39[1520] = v14 + 1;
        *(_DWORD *)&v39[4 * *(_DWORD *)&v39[1520] + 144] = v27;
        v14 = *(_DWORD *)&v39[1520];
      }
      if ( (v26 & 2) != 0 )
      {
        *(_DWORD *)&v39[1520] = v14 + 1;
        *(_DWORD *)&v39[4 * *(_DWORD *)&v39[1520] + 144] = v27 + 1;
        v14 = *(_DWORD *)&v39[1520];
        v13 = pTri1;
      }
      if ( (v26 & 4) != 0 )
      {
        *(_DWORD *)&v39[1520] = v14 + 1;
        *(_DWORD *)&v39[4 * *(_DWORD *)&v39[1520] + 144] = v27 + 2;
        v14 = *(_DWORD *)&v39[1520];
        v13 = pTri1;
      }
      if ( (v26 & 8) != 0 )
      {
        *(_DWORD *)&v39[1520] = v14 + 1;
        *(_DWORD *)&v39[4 * *(_DWORD *)&v39[1520] + 144] = v27 + 3;
        v14 = *(_DWORD *)&v39[1520];
      }
    }
    if ( (int)v13 > v14 )
    {
      v28 = v13;
      pTri1 = v13;
      goto LABEL_15;
    }
    v16 = *(__m128 *)&v39[32];
    v15 = *(__m128 *)v39;
  }
  v28 = v13;
  pTri1 = v13;
LABEL_15:
  if ( (int)v13 <= v14 )
  {
    do
    {
      v29 = *(_DWORD *)&v39[4 * (_DWORD)v28 + 144] - v8->m_nodes.m_Size;
      m_pMemory = v8->m_leaves.m_Memory.m_pMemory;
      v31 = m_pMemory[v29].m_tris[0];
      v32 = m_pMemory[v29].m_tris[1];
      v33 = v8->m_aTris.m_Memory.m_pMemory;
      v34 = &v33[v31];
      LOWORD(v31) = v34->m_TriData[0].m_IndexDummy;
      v35 = &v33[v32];
      LOWORD(v32) = v34->m_TriData[1].m_IndexDummy;
      v41 = v35;
      v36 = IntersectRayWithTriangle(
              ray,
              v1: &v42->m_aVerts.m_Memory.m_pMemory[v31 & 0x1FF],
              v2: COERCE_FLOAT((unsigned int)&v42->m_aVerts.m_Memory.m_pMemory[v34->m_TriData[2].m_IndexDummy & 0x1FF]),
              v3: &v42->m_aVerts.m_Memory.m_pMemory[v32 & 0x1FF],
              oneSided: bSide);
      v43 = v36;
      if ( v36 >= 0.0 && pTrace->fraction > v43 )
      {
        pTrace->fraction = v43;
        *pImpactTri = v34;
      }
      v8 = v42;
      v37 = IntersectRayWithTriangle(
              ray,
              v1: &v42->m_aVerts.m_Memory.m_pMemory[v41->m_TriData[0].m_IndexDummy & 0x1FF],
              v2: COERCE_FLOAT((unsigned int)&v42->m_aVerts.m_Memory.m_pMemory[v41->m_TriData[2].m_IndexDummy & 0x1FF]),
              v3: &v42->m_aVerts.m_Memory.m_pMemory[v41->m_TriData[1].m_IndexDummy & 0x1FF],
              oneSided: bSide);
      v43 = v37;
      if ( v37 >= 0.0 && pTrace->fraction > v43 )
      {
        v38 = v41;
        pTrace->fraction = v43;
        *pImpactTri = v38;
      }
      v28 = (CDispCollTri *)((char *)&pTri1->m_TriData[0].m_Index + 1);
      pTri1 = v28;
    }
    while ( (int)v28 <= *(int *)&v39[1520] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160AA0
// Name: protected: int CDispCollTree::AABBTree_BuildTreeTrisInSphere_r(class Vector const __near &,float,int,unsigned short __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CDispCollTree::AABBTree_BuildTreeTrisInSphere_r@<eax>(
        CDispCollTree *this@<ecx>,
        int a2@<ebp>,
        const Vector *center,
        float radius,
        int iNode,
        unsigned __int16 *pIndexOut,
        unsigned __int16 indexMax)
{
  __m128 x_low; // xmm3
  __m128 y_low; // xmm4
  __m128 z_low; // xmm5
  int m_Size; // edx
  __m128 v11; // xmm1
  int v12; // edi
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  int v16; // eax
  int v17; // esi
  CDispCollNode *v18; // edx
  __m128 z; // xmm2
  __m128 x; // xmm7
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  int v28; // edx
  int v29; // esi
  int v31; // eax
  int v32; // edx
  int v33; // eax
  _DWORD v34[3]; // [esp-Ch] [ebp-5ECh]
  __m128 v35; // [esp+564h] [ebp-7Ch]
  __m128 v36; // [esp+574h] [ebp-6Ch]
  _BYTE v37[76]; // [esp+584h] [ebp-5Ch] OVERLAPPED
  int v38; // [esp+5D0h] [ebp-10h]
  int listIndex; // [esp+5D4h] [ebp-Ch]
  int nTriCount; // [esp+5D8h] [ebp-8h]
  int retaddr; // [esp+5E0h] [ebp+0h]

  listIndex = a2;
  nTriCount = retaddr;
  *(_DWORD *)&v37[64] = this;
  x_low = (__m128)LODWORD(center->x);
  y_low = (__m128)LODWORD(center->y);
  z_low = (__m128)LODWORD(center->z);
  m_Size = this->m_nodes.m_Size;
  v11 = 0;
  v11.m128_f32[0] = radius * radius;
  v12 = 0;
  v34[0] = iNode;
  v13 = _mm_shuffle_ps(x_low, x_low, 0);
  v14 = _mm_shuffle_ps(y_low, y_low, 0);
  v15 = _mm_shuffle_ps(z_low, z_low, 0);
  v16 = 0;
  *(__m128 *)&v37[16] = v13;
  *(__m128 *)&v37[32] = v14;
  *(__m128 *)&v37[48] = v15;
  *(__m128 *)v37 = _mm_shuffle_ps(v11, v11, 0);
  *(_QWORD *)&v37[68] = (unsigned int)m_Size;
  while ( 1 )
  {
    v17 = v34[v16++];
    if ( v17 >= *(int *)&v37[68] )
      break;
    v18 = &this->m_nodes.m_Memory.m_pMemory[v17];
    z = v18->m_mins.z;
    x = v18->m_mins.x;
    v21 = _mm_sub_ps(v18->m_mins.y, v14);
    v22 = _mm_sub_ps(v14, v18->m_maxs.y);
    v35 = v21;
    v23 = _mm_sub_ps(z, v15);
    v24 = _mm_sub_ps(v15, v18->m_maxs.z);
    v36 = v23;
    v25 = _mm_max_ps(_mm_max_ps(Four_Zeros, v21), v22);
    v26 = _mm_max_ps(_mm_max_ps(Four_Zeros, _mm_sub_ps(x, v13)), _mm_sub_ps(v13, v18->m_maxs.x));
    v27 = _mm_max_ps(_mm_max_ps(Four_Zeros, v23), v24);
    v28 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v25, v25), _mm_mul_ps(v26, v26)), _mm_mul_ps(v27, v27)),
              *(__m128 *)v37));
    v38 = v28;
    if ( v28 != 0 )
    {
      v29 = 4 * v17 + 1;
      if ( (v28 & 1) != 0 )
        v34[++v12] = v29;
      if ( (v28 & 2) != 0 )
      {
        v34[++v12] = v29 + 1;
        LOBYTE(v28) = v38;
      }
      if ( (v28 & 4) != 0 )
      {
        v34[++v12] = v29 + 2;
        LOBYTE(v28) = v38;
      }
      if ( (v28 & 8) != 0 )
        v34[++v12] = v29 + 3;
    }
    if ( v16 > v12 )
      return *(_DWORD *)&v37[72];
    v14 = *(__m128 *)&v37[32];
    v15 = *(__m128 *)&v37[48];
    v13 = *(__m128 *)&v37[16];
  }
  v31 = v16 - 1;
  *(_DWORD *)&v37[68] = v31;
  if ( v31 <= v12 )
  {
    v38 = 2;
    do
    {
      if ( v38 <= indexMax )
      {
        v32 = v34[v31] - this->m_nodes.m_Size;
        v33 = *(_DWORD *)&v37[72];
        pIndexOut[*(_DWORD *)&v37[72]] = this->m_leaves.m_Memory.m_pMemory[v32].m_tris[0];
        this = *(CDispCollTree **)&v37[64];
        pIndexOut[v33 + 1] = *(_WORD *)(*(_DWORD *)(*(_DWORD *)&v37[64] + 160) + 4 * v32 + 2);
        v38 += 2;
        *(_DWORD *)&v37[72] = v33 + 2;
        v31 = *(_DWORD *)&v37[68];
      }
      *(_DWORD *)&v37[68] = ++v31;
    }
    while ( v31 <= v12 );
  }
  return *(_DWORD *)&v37[72];
}

//------------------------------------------------------------------------------
// Address: 0x10160CA0
// Name: public: bool CDispCollTree::AABBTree_IntersectAABB(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CDispCollTree::AABBTree_IntersectAABB@<al>(
        CDispCollTree *this@<ecx>,
        float a2@<ebp>,
        const Vector *absMins,
        const Vector *absMaxs)
{
  float v4; // edi
  char v5; // al
  float x; // xmm5_4
  float y; // xmm3_4
  float z; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  __m128 v13; // xmm6
  float v14; // xmm3_4
  __m128 z_low; // xmm1
  __m128 v16; // xmm0
  int v17; // esi
  __m128 v18; // xmm0
  float v19; // ecx
  int v20; // edx
  __m128 *v21; // eax
  float v22; // eax
  int v23; // edx
  bool result; // al
  int v25; // esi
  int v26; // eax
  int v27; // esi
  __int16 *v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // xmm0_4
  int v32; // eax
  int v33; // esi
  _DWORD v34[3]; // [esp+14h] [ebp-60Ch]
  _BYTE nodeList_1348[124]; // [esp+584h] [ebp-9Ch] OVERLAPPED BYREF
  int v36; // [esp+600h] [ebp-20h]
  char v37; // [esp+604h] [ebp-1Ch]
  char v38; // [esp+605h] [ebp-1Bh]
  Vector extents; // [esp+608h] [ebp-18h]
  Vector center; // [esp+614h] [ebp-Ch]
  float plane; // [esp+620h] [ebp+0h]

  center.x = a2;
  center.y = plane;
  v4 = *(float *)&this;
  v5 = LOBYTE(this->m_nFlags) >> 2;
  LODWORD(extents.y) = this;
  if ( (v5 & 1) != 0 )
    return false;
  x = absMaxs->x;
  y = absMaxs->y;
  z = absMaxs->z;
  *(float *)&nodeList_1348[100] = (float)(absMaxs->x + absMins->x) * 0.5;
  v11 = (float)(y + absMins->y) * 0.5;
  v12 = (float)(z + absMins->z) * 0.5;
  v13 = _mm_shuffle_ps((__m128)LODWORD(absMins->x), (__m128)LODWORD(absMins->x), 0);
  v14 = y - v11;
  *(float *)&nodeList_1348[104] = v11;
  z_low = (__m128)LODWORD(absMins->z);
  *(__m128 *)nodeList_1348 = _mm_shuffle_ps((__m128)LODWORD(absMins->y), (__m128)LODWORD(absMins->y), 0);
  *(__m128 *)&nodeList_1348[16] = _mm_shuffle_ps(z_low, z_low, 0);
  v16 = 0;
  v16.m128_f32[0] = x;
  *(__m128 *)&nodeList_1348[32] = _mm_shuffle_ps(v16, v16, 0);
  *(__m128 *)&nodeList_1348[48] = _mm_shuffle_ps((__m128)LODWORD(absMaxs->y), (__m128)LODWORD(absMaxs->y), 0);
  v17 = 0;
  v18 = _mm_shuffle_ps((__m128)LODWORD(absMaxs->z), (__m128)LODWORD(absMaxs->z), 0);
  *(float *)&nodeList_1348[108] = v12;
  *(float *)&nodeList_1348[88] = x - *(float *)&nodeList_1348[100];
  *(float *)&nodeList_1348[92] = v14;
  *(float *)&nodeList_1348[96] = z - v12;
  v34[0] = 0;
  v19 = 0.0;
  *(__m128 *)&nodeList_1348[64] = v18;
  while ( 1 )
  {
    v20 = v34[v17++];
    if ( v20 >= *(_DWORD *)(LODWORD(v4) + 152) )
      break;
    v21 = (__m128 *)(*(_DWORD *)(LODWORD(v4) + 144) + 96 * v20);
    v22 = COERCE_FLOAT(
            _mm_movemask_ps(
              _mm_and_ps(
                _mm_and_ps(
                  _mm_cmple_ps(
                    _mm_max_ps(*(__m128 *)nodeList_1348, v21[1]),
                    _mm_min_ps(*(__m128 *)&nodeList_1348[48], v21[4])),
                  _mm_cmple_ps(_mm_max_ps(v13, *v21), _mm_min_ps(*(__m128 *)&nodeList_1348[32], v21[3]))),
                _mm_cmple_ps(
                  _mm_max_ps(*(__m128 *)&nodeList_1348[16], v21[2]),
                  _mm_min_ps(*(__m128 *)&nodeList_1348[64], v21[5])))));
    extents.z = v22;
    if ( v22 != 0.0 )
    {
      v23 = 4 * v20 + 1;
      if ( (LOBYTE(v22) & 1) != 0 )
        v34[++LODWORD(v19)] = v23;
      if ( (LOBYTE(v22) & 2) != 0 )
      {
        v34[++LODWORD(v19)] = v23 + 1;
        LOBYTE(v22) = LOBYTE(extents.z);
      }
      if ( (LOBYTE(v22) & 4) != 0 )
      {
        v34[++LODWORD(v19)] = v23 + 2;
        LOBYTE(v22) = LOBYTE(extents.z);
      }
      if ( (LOBYTE(v22) & 8) != 0 )
        v34[++LODWORD(v19)] = v23 + 3;
    }
    if ( v17 > SLODWORD(v19) )
      return false;
  }
  v25 = v17 - 1;
  extents.z = v19;
  LODWORD(extents.x) = v25;
  if ( v25 > SLODWORD(v19) )
    return false;
  while ( 1 )
  {
    v26 = v34[v25] - *(_DWORD *)(LODWORD(v4) + 152);
    v27 = *(_DWORD *)(LODWORD(v4) + 128);
    v28 = (__int16 *)(*(_DWORD *)(LODWORD(v4) + 160) + 4 * v26);
    v29 = *v28;
    v30 = v28[1];
    v31 = *(_DWORD *)(v27 + 24 * v29 + 8);
    v32 = v27 + 24 * v29;
    *(_DWORD *)&nodeList_1348[112] = v31;
    *(_QWORD *)&nodeList_1348[116] = *(_QWORD *)(v32 + 12);
    v36 = *(_DWORD *)(v32 + 20);
    v33 = v27 + 24 * v30;
    v38 = *(_BYTE *)(v32 + 6) & 7;
    v37 = (*(_BYTE *)(v32 + 6) >> 3) & 7;
    if ( IsBoxIntersectingTriangle(
           vecBoxCenter: (const Vector *)&nodeList_1348[100],
           vecBoxExtents: (const Vector *)&nodeList_1348[88],
           v1: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)v32 & 0x1FF)),
           v2: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)(v32 + 4) & 0x1FF)),
           v3: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)(v32 + 2) & 0x1FF)),
           plane: (const cplane_t *)&nodeList_1348[112],
           flTolerance: 0.0) )
    {
      break;
    }
    *(_QWORD *)&nodeList_1348[112] = *(_QWORD *)(v33 + 8);
    v4 = extents.y;
    *(_DWORD *)&nodeList_1348[120] = *(_DWORD *)(v33 + 16);
    v36 = *(_DWORD *)(v33 + 20);
    v38 = *(_BYTE *)(v33 + 6) & 7;
    v37 = (*(_BYTE *)(v33 + 6) >> 3) & 7;
    result = IsBoxIntersectingTriangle(
               vecBoxCenter: (const Vector *)&nodeList_1348[100],
               vecBoxExtents: (const Vector *)&nodeList_1348[88],
               v1: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)v33 & 0x1FF)),
               v2: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)(v33 + 4) & 0x1FF)),
               v3: (const Vector *)(*(_DWORD *)(LODWORD(extents.y) + 112) + 12 * (*(_WORD *)(v33 + 2) & 0x1FF)),
               plane: (const cplane_t *)&nodeList_1348[112],
               flTolerance: 0.0);
    if ( result )
      break;
    v25 = LODWORD(extents.x) + 1;
    LODWORD(extents.x) = v25;
    if ( v25 > SLODWORD(extents.z) )
      return result;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10161000
// Name: protected: void CDispCollTree::SweepAABBTriIntersect(struct Ray_t const __near &,class Vector const __near &,int,class CDispCollTri __near *,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::SweepAABBTriIntersect(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *rayDir,
        int iTri,
        CDispCollTri *pTri,
        CBaseTrace *pTrace)
{
  CDispCollTri *v6; // eax
  float v7; // xmm0_4
  int v8; // edx
  char *v9; // edi
  float *i; // esi
  unsigned int m_IndexDummy; // ecx
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm7_4
  int v15; // eax
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  int v22; // eax
  float v23; // xmm5_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  CDispCollTree *v29; // edi
  CDispCollTriCache *v30; // esi
  float m_flStartFrac; // xmm0_4
  CDispCollHelper helper; // [esp+0h] [ebp-24h] BYREF
  CDispCollTree *v33; // [esp+18h] [ebp-Ch]
  Vector *m_pMemory; // [esp+20h] [ebp-4h]

  v6 = pTri;
  helper.m_flEndFrac = 1.0;
  helper.m_flStartFrac = -99999.898;
  v7 = (float)((float)(ray->m_Delta.y * pTri->m_vecNormal.y) + (float)(ray->m_Delta.x * pTri->m_vecNormal.x))
     + (float)(ray->m_Delta.z * pTri->m_vecNormal.z);
  v33 = this;
  if ( v7 <= 0.03125 )
  {
    v8 = 2;
    m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
    v9 = (char *)&unk_10363788;
    for ( i = &ray->m_Delta.z; ; --i )
    {
      m_IndexDummy = v6->m_TriData[v8].m_IndexDummy;
      v12 = i[8];
      v13 = *(i - 4);
      v14 = *i;
      v15 = v6->m_TriData[(m_IndexDummy >> 9) & 3].m_IndexDummy & 0x1FF;
      v16 = *(&m_pMemory->x + 2 * v15 + v15 + v8);
      v17 = (float)(v16 - v12) - v13;
      v18 = v17 - *i;
      if ( v17 > 0.0 && v18 > 0.0 )
        break;
      if ( v17 >= 0.0 || v18 >= 0.0 )
      {
        v19 = v17 - v18;
        if ( v17 < 0.0 || v18 > 0.0 )
        {
          if ( (float)(v17 - v18) == 0.0 )
            v21 = 0.0;
          else
            v21 = (float)(v17 + 0.03125) / v19;
          if ( helper.m_flEndFrac > v21 )
            helper.m_flEndFrac = v21;
        }
        else
        {
          if ( (float)(v17 - v18) == 0.0 )
            v20 = 0.0;
          else
            v20 = (float)(v17 - 0.03125) / v19;
          if ( v20 > helper.m_flStartFrac )
          {
            helper.m_flStartFrac = v20;
            helper.m_vecImpactNormal = *(Vector *)(v9 - 8);
            helper.m_flImpactDist = v16;
          }
        }
      }
      v22 = pTri->m_TriData[(m_IndexDummy >> 11) & 3].m_IndexDummy & 0x1FF;
      v23 = *(&m_pMemory->x + 2 * v22 + v22 + v8);
      v24 = v13 - (float)(v23 + v12);
      v25 = v24 + v14;
      if ( v24 > 0.0 && v25 > 0.0 )
        break;
      if ( v24 >= 0.0 || v25 >= 0.0 )
      {
        v26 = v24 - v25;
        if ( v24 < 0.0 || v25 > 0.0 )
        {
          if ( (float)(v24 - v25) == 0.0 )
            v28 = 0.0;
          else
            v28 = (float)(v24 + 0.03125) / v26;
          if ( helper.m_flEndFrac > v28 )
            helper.m_flEndFrac = v28;
        }
        else
        {
          if ( (float)(v24 - v25) == 0.0 )
            v27 = 0.0;
          else
            v27 = (float)(v24 - 0.03125) / v26;
          if ( v27 > helper.m_flStartFrac )
          {
            helper.m_flStartFrac = v27;
            helper.m_vecImpactNormal = *(Vector *)(v9 + 28);
            helper.m_flImpactDist = v23;
          }
        }
      }
      v9 -= 12;
      --v8;
      if ( (int)v9 < (int)byte_10363770 )
      {
        v29 = v33;
        v30 = &v33->m_aTrisCache.m_Memory.m_pMemory[iTri];
        if ( CDispCollTree::EdgeCrossAxis<0>(this: v33, ray, iPlane: v30->m_iCrossX[0], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<0>(this: v29, ray, iPlane: v30->m_iCrossX[1], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<0>(this: v29, ray, iPlane: v30->m_iCrossX[2], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<1>(this: v29, ray, iPlane: v30->m_iCrossY[0], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<1>(this: v29, ray, iPlane: v30->m_iCrossY[1], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<1>(this: v29, ray, iPlane: v30->m_iCrossY[2], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<2>(this: v29, ray, iPlane: v30->m_iCrossZ[0], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<2>(this: v29, ray, iPlane: v30->m_iCrossZ[1], pHelper: &helper) != 0
          && CDispCollTree::EdgeCrossAxis<2>(this: v29, ray, iPlane: v30->m_iCrossZ[2], pHelper: &helper) != 0
          && CDispCollTree::FacePlane(this: v29, ray, rayDir, pTri, pHelper: &helper) != 0 )
        {
          m_flStartFrac = helper.m_flStartFrac;
          if ( (helper.m_flEndFrac > helper.m_flStartFrac || fabs(helper.m_flStartFrac - helper.m_flEndFrac) < 0.001)
            && helper.m_flStartFrac != -99999.898
            && pTrace->fraction > helper.m_flStartFrac )
          {
            if ( helper.m_flStartFrac < 0.0 )
              m_flStartFrac = 0.0;
            pTrace->fraction = m_flStartFrac;
            pTrace->plane.normal = helper.m_vecImpactNormal;
            pTrace->plane.dist = helper.m_flImpactDist;
            pTrace->dispFlags = (*((_WORD *)pTri + 3) >> 6) & 0x1F;
          }
        }
        return;
      }
      v6 = pTri;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161400
// Name: public: void CDispCollTree::GetVirtualMeshList(struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::GetVirtualMeshList(CDispCollTree *this, virtualmeshlist_t *pList)
{
  int v3; // esi
  int v4; // edx
  unsigned __int16 *v5; // ecx

  v3 = 2 * (1 << this->m_nPower) * (1 << this->m_nPower);
  pList->indexCount = 6 * (1 << this->m_nPower) * (1 << this->m_nPower);
  pList->triangleCount = v3;
  pList->vertexCount = this->m_aVerts.m_Size;
  pList->pVerts = this->m_aVerts.m_Memory.m_pMemory;
  v4 = 0;
  pList->pHull = nullptr;
  pList->surfacePropsIndex = this->m_nSurfaceProps[0];
  if ( v3 > 0 )
  {
    v5 = &pList->indices[1];
    do
    {
      *(v5 - 1) = this->m_aTris.m_Memory.m_pMemory[v4].m_TriData[0].m_IndexDummy & 0x1FF;
      *v5 = this->m_aTris.m_Memory.m_pMemory[v4].m_TriData[1].m_IndexDummy & 0x1FF;
      v5[1] = this->m_aTris.m_Memory.m_pMemory[v4].m_TriData[2].m_IndexDummy & 0x1FF;
      v5 += 3;
      ++v4;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161720
// Name: public: void CDispCollTree::Uncache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::Uncache(CDispCollTree *this)
{
  Vector *m_pMemory; // ecx

  this->m_aTrisCache.m_Size = 0;
  if ( this->m_aTrisCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aTrisCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aTrisCache.m_Memory.m_pMemory);
      this->m_aTrisCache.m_Memory.m_pMemory = nullptr;
    }
    this->m_aTrisCache.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aTrisCache.m_pElements = this->m_aTrisCache.m_Memory.m_pMemory;
  this->m_aEdgePlanes.m_Size = 0;
  if ( this->m_aEdgePlanes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_aEdgePlanes.m_pElements = this->m_aEdgePlanes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_aEdgePlanes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aEdgePlanes.m_Memory.m_pMemory);
      this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_aEdgePlanes.m_Memory.m_pMemory;
    this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
    this->m_aEdgePlanes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101617C0
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,class Vector const __near &,struct RayDispOutput_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        RayDispOutput_t *output)
{
  CDispCollTri *v5; // eax
  CDispCollTri *pImpactTri; // [esp+0h] [ebp-4h] BYREF
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  pImpactTri = (CDispCollTri *)this;
  if ( (this->m_nFlags & 8) != 0 || (this->m_nContents & 0x4081) == 0 )
    return 0;
  pImpactTri = nullptr;
  CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(
    this,
    a2: COERCE_FLOAT(&savedregs),
    ray,
    vecInvDelta,
    iNode: 0,
    output,
    &pImpactTri);
  v5 = pImpactTri;
  if ( pImpactTri == nullptr )
    return 0;
  output->ndxVerts[0] = pImpactTri->m_TriData[0].m_IndexDummy & 0x1FF;
  output->ndxVerts[1] = v5->m_TriData[2].m_IndexDummy & 0x1FF;
  output->ndxVerts[2] = v5->m_TriData[1].m_IndexDummy & 0x1FF;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10161840
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,class Vector const __near &,class CBaseTrace __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        CBaseTrace *pTrace,
        int bSide)
{
  CDispCollTri *v6; // eax
  CDispCollTri *pImpactTri; // [esp+0h] [ebp-4h] BYREF
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  pImpactTri = (CDispCollTri *)this;
  if ( (this->m_nFlags & 8) != 0 || (this->m_nContents & 0x4081) == 0 )
    return 0;
  pImpactTri = nullptr;
  CDispCollTree::AABBTree_TreeTrisRayTest(
    this,
    a2: (int)&savedregs,
    ray,
    vecInvDelta,
    iNode: 0,
    pTrace,
    bSide,
    &pImpactTri);
  v6 = pImpactTri;
  if ( pImpactTri == nullptr )
    return 0;
  pTrace->plane.normal.x = pImpactTri->m_vecNormal.x;
  pTrace->plane.normal.y = v6->m_vecNormal.y;
  pTrace->plane.normal.z = v6->m_vecNormal.z;
  pTrace->plane.dist = v6->m_flDist;
  pTrace->dispFlags = (*((_WORD *)v6 + 3) >> 6) & 0x1F;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101618D0
// Name: public: int CDispCollTree::AABBTree_GetTrisInSphere(class Vector const __near &,float,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispCollTree::AABBTree_GetTrisInSphere(
        CDispCollTree *this,
        const Vector *center,
        float radius,
        unsigned __int16 *pIndexOut,
        unsigned __int16 indexMax)
{
  float var10; // [esp+0h] [ebp+0h] BYREF

  return CDispCollTree::AABBTree_BuildTreeTrisInSphere_r(
           this,
           a2: (int)&var10,
           center,
           radius,
           iNode: 0,
           pIndexOut,
           indexMax);
}

//------------------------------------------------------------------------------
// Address: 0x10161900
// Name: private: virtual void CDataManager<class CDispCollTree,class CDispCollTree __near *,bool,class CThreadFastMutex>::DestroyResourceStorage(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::DestroyResourceStorage(
        CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex> *this,
        CDispCollTree *pStore)
{
  CDispCollTree::Uncache(this: pStore);
  pStore->m_hCache = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10161920
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,struct RayDispOutput_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(CDispCollTree *this, const Ray_t *ray, RayDispOutput_t *output)
{
  VectorAligned *p_m_Delta; // ebx
  float y; // xmm0_4
  float z; // xmm0_4
  Vector vecInvDelta; // [esp+10h] [ebp-Ch] BYREF

  p_m_Delta = &ray->m_Delta;
  if ( !IsBoxIntersectingRay(
          boxMin: &this->m_mins,
          boxMax: &this->m_maxs,
          origin: &ray->m_Start,
          vecDelta: &ray->m_Delta,
          flTolerance: 0.03125) )
    return 0;
  if ( p_m_Delta->x == 0.0 )
    vecInvDelta.x = 3.4028235e38;
  else
    vecInvDelta.x = 1.0 / p_m_Delta->x;
  y = ray->m_Delta.y;
  if ( y == 0.0 )
    vecInvDelta.y = 3.4028235e38;
  else
    vecInvDelta.y = 1.0 / y;
  z = ray->m_Delta.z;
  if ( z == 0.0 )
    vecInvDelta.z = 3.4028235e38;
  else
    vecInvDelta.z = 1.0 / z;
  return CDispCollTree::AABBTree_Ray(this, ray, &vecInvDelta, output);
}

//------------------------------------------------------------------------------
// Address: 0x101619F0
// Name: public: CDispCollTree::~CDispCollTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::~CDispCollTree(CDispCollTree *this)
{
  memhandle_t__ *m_hCache; // eax
  Vector *m_pMemory; // eax
  CDispCollTri *v4; // ecx
  CDispCollLeaf *v5; // edx
  CDispCollNode *v6; // eax
  CDispCollTri *v7; // ecx
  Vector *v8; // edx

  m_hCache = this->m_hCache;
  this->__vftable = (CDispCollTree_vtbl *)&CDispCollTree::`vftable';
  if ( m_hCache != (memhandle_t__ *)-1 )
    CDataManagerBase::DestroyResource(this: &g_DispCollTriCache, handle: m_hCache);
  m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
  this->m_aVerts.m_Size = 0;
  this->m_aVerts.m_Memory.m_nAllocated = 0;
  this->m_aVerts.m_pElements = m_pMemory;
  v4 = this->m_aTris.m_Memory.m_pMemory;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_Memory.m_nAllocated = 0;
  this->m_aTris.m_pElements = v4;
  this->m_aEdgePlanes.m_Size = 0;
  if ( this->m_aEdgePlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aEdgePlanes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aEdgePlanes.m_Memory.m_pMemory);
      this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
    }
    this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aEdgePlanes.m_pElements = this->m_aEdgePlanes.m_Memory.m_pMemory;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_aEdgePlanes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_aTrisCache);
  v5 = this->m_leaves.m_Memory.m_pMemory;
  this->m_leaves.m_Size = 0;
  this->m_leaves.m_Memory.m_nAllocated = 0;
  this->m_leaves.m_pElements = v5;
  v6 = this->m_nodes.m_Memory.m_pMemory;
  this->m_nodes.m_Size = 0;
  this->m_nodes.m_Memory.m_nAllocated = 0;
  this->m_nodes.m_pElements = v6;
  v7 = this->m_aTris.m_Memory.m_pMemory;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_Memory.m_nAllocated = 0;
  this->m_aTris.m_pElements = v7;
  v8 = this->m_aVerts.m_Memory.m_pMemory;
  this->m_aVerts.m_Size = 0;
  this->m_aVerts.m_Memory.m_nAllocated = 0;
  this->m_aVerts.m_pElements = v8;
}

//------------------------------------------------------------------------------
// Address: 0x10161AF0
// Name: protected: void CDispCollTree::AABBTree_CreateLeafs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::AABBTree_CreateLeafs(CDispCollTree *this)
{
  int m_nPower; // ecx
  int v3; // esi
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ebx
  int v14; // ecx
  int v15; // edx
  __int16 v16; // dx
  CDispVector<CDispCollLeaf> *p_m_leaves; // [esp+Ch] [ebp-14h]
  int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+18h] [ebp-8h]
  int iHgt; // [esp+1Ch] [ebp-4h]

  m_nPower = this->m_nPower;
  p_m_leaves = &this->m_leaves;
  v3 = (1 << m_nPower) * (1 << m_nPower);
  this->m_leaves.m_Size = 0;
  if ( v3 != 0 )
  {
    CUtlVector<CDispCollLeaf,CHunkMemory<CDispCollLeaf>>::GrowVector(
      this: &this->m_leaves,
      num: (1 << m_nPower) * (1 << m_nPower));
    if ( this->m_leaves.m_Size - v3 > 0 && v3 > 0 )
      _V_memmove(
        dest: &this->m_leaves.m_Memory.m_pMemory[v3],
        src: this->m_leaves.m_Memory.m_pMemory,
        count: 4 * (this->m_leaves.m_Size - v3));
  }
  v4 = 2 * this->m_nPower + 2;
  this->m_nodes.m_Size = 0;
  v5 = (1 << v4) / 3 - v3;
  if ( v5 != 0 )
  {
    CUtlVector<CDispCollNode,CHunkMemory<CDispCollNode>>::GrowVector(this: &this->m_nodes, num: v5);
    if ( this->m_nodes.m_Size - v5 > 0 && v5 > 0 )
      _V_memmove(
        dest: &this->m_nodes.m_Memory.m_pMemory[v5],
        src: this->m_nodes.m_Memory.m_pMemory,
        count: 96 * (this->m_nodes.m_Size - v5));
  }
  v6 = 1 << this->m_nPower;
  v7 = 0;
  iHgt = 0;
  v19 = v6;
  if ( v6 > 0 )
  {
    v18 = 0;
    do
    {
      v8 = 0;
      if ( v6 > 0 )
      {
        v20 = v7;
        do
        {
          v9 = iHgt;
          v10 = 0;
          v11 = 0;
          v12 = v8;
          if ( v8 != 0 )
          {
            do
            {
              v13 = (v12 & 1) << v11;
              v11 += 2;
              v10 |= v13;
              v12 >>= 1;
            }
            while ( v12 != 0 );
            v7 = v20;
          }
          v14 = 1;
          if ( iHgt != 0 )
          {
            do
            {
              v15 = (v9 & 1) << v14;
              v14 += 2;
              v10 |= v15;
              v9 >>= 1;
            }
            while ( v9 != 0 );
          }
          p_m_leaves->m_Memory.m_pMemory[v10].m_tris[0] = v7;
          v16 = v7 + 1;
          ++v8;
          v7 += 2;
          p_m_leaves->m_Memory.m_pMemory[v10].m_tris[1] = v16;
          v20 = v7;
        }
        while ( v8 < v19 );
        v6 = v19;
      }
      v7 = 2 * v6 + v18;
      ++iHgt;
      v18 = v7;
    }
    while ( iHgt < v6 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161C60
// Name: protected: int CDispCollTree::AddPlane(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispCollTree::AddPlane(CDispCollTree *this, const Vector *vecNormal)
{
  const Vector *v2; // esi
  int m_Size; // eax
  float y; // xmm0_4
  DispCollPlaneIndex_t *v6; // ecx
  DispCollPlaneIndex_t planeIndex; // [esp+4h] [ebp-14h] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  v2 = vecNormal;
  m_Size = this->m_aEdgePlanes.m_Size;
  planeIndex.vecPlane.x = vecNormal->x;
  y = vecNormal->y;
  planeIndex.index = m_Size;
  planeIndex.vecPlane.y = y;
  planeIndex.vecPlane.z = vecNormal->z;
  vecNormal = nullptr;
  if ( CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::DoFind(
         this: &g_DispCollPlaneIndexHash,
         src: &planeIndex,
         &pBucket,
         pIndex: (int *)&vecNormal) )
  {
    v6 = &g_DispCollPlaneIndexHash.m_Buckets.m_Memory.m_pMemory[((unsigned int)vecNormal | (pBucket << 16)) >> 16].m_Memory.m_pMemory[(unsigned __int16)vecNormal];
    if ( v2->x == v6->vecPlane.x && v2->y == v6->vecPlane.y && v2->z == v6->vecPlane.z )
      return v6->index;
    else
      return v6->index | 0x8000;
  }
  else
  {
    CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
      this: (CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int> > *)&g_DispCollPlaneIndexHash.m_Buckets.m_Memory.m_pMemory[pBucket],
      elem: g_DispCollPlaneIndexHash.m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
      src: (const CSosOperator::InputData_t *)&planeIndex);
    return CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: &this->m_aEdgePlanes,
             elem: this->m_aEdgePlanes.m_Size,
             src: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161D60
// Name: protected: bool CDispCollTree::Cache_EdgeCrossAxisX(class Vector const __near &,class Vector const __near &,class Vector const __near &,class CDispCollTri __near *,unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Cache_EdgeCrossAxisX(
        CDispCollTree *this,
        const Vector *vecEdge,
        const Vector *vecOnEdge,
        const Vector *vecOffEdge,
        CDispCollTri *pTri,
        unsigned __int16 *iPlane)
{
  double v7; // st5
  float v8; // xmm0_4
  double v9; // st6
  Vector vecNormal; // [esp+0h] [ebp-Ch] BYREF
  float flDist; // [esp+14h] [ebp+8h]
  float flOffDist; // [esp+18h] [ebp+Ch]

  vecNormal.x = 0.0;
  vecNormal.y = vecEdge->z;
  LODWORD(vecNormal.z) = LODWORD(vecEdge->y) ^ _mask__NegFloat_;
  VectorNormalize(vec: &vecNormal);
  if ( vecNormal.y == 0.0 || vecNormal.z == 0.0 )
  {
    *iPlane = -1;
    return 0;
  }
  else
  {
    v7 = vecOnEdge->y * vecNormal.y + vecOnEdge->z * vecNormal.z;
    flDist = v7;
    v8 = flDist;
    v9 = vecNormal.y * vecOffEdge->y + vecNormal.z * vecOffEdge->z;
    if ( fabs(v9 - v7) >= 0.03125 )
    {
      flOffDist = v9;
      if ( flOffDist > flDist )
      {
        v8 = -flDist;
        vecNormal.y = -vecNormal.y;
        vecNormal.z = -vecNormal.z;
      }
    }
    vecNormal.x = v8;
    *iPlane = CDispCollTree::AddPlane(this, &vecNormal);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161E70
// Name: protected: bool CDispCollTree::Cache_EdgeCrossAxisY(class Vector const __near &,class Vector const __near &,class Vector const __near &,class CDispCollTri __near *,unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Cache_EdgeCrossAxisY(
        CDispCollTree *this,
        const Vector *vecEdge,
        const Vector *vecOnEdge,
        const Vector *vecOffEdge,
        CDispCollTri *pTri,
        unsigned __int16 *iPlane)
{
  double v7; // st5
  float v8; // xmm0_4
  double v9; // st6
  Vector vecNormal; // [esp+0h] [ebp-Ch] BYREF
  float flDist; // [esp+14h] [ebp+8h]
  float flOffDist; // [esp+18h] [ebp+Ch]

  LODWORD(vecNormal.x) = LODWORD(vecEdge->z) ^ _mask__NegFloat_;
  vecNormal.y = 0.0;
  vecNormal.z = vecEdge->x;
  VectorNormalize(vec: &vecNormal);
  if ( vecNormal.x == 0.0 || vecNormal.z == 0.0 )
  {
    *iPlane = -1;
    return 0;
  }
  else
  {
    v7 = vecOnEdge->x * vecNormal.x + vecOnEdge->z * vecNormal.z;
    flDist = v7;
    v8 = flDist;
    v9 = vecNormal.x * vecOffEdge->x + vecNormal.z * vecOffEdge->z;
    if ( fabs(v9 - v7) >= 0.03125 )
    {
      flOffDist = v9;
      if ( flOffDist > flDist )
      {
        vecNormal.x = -vecNormal.x;
        v8 = -flDist;
        vecNormal.z = -vecNormal.z;
      }
    }
    vecNormal.y = v8;
    *iPlane = CDispCollTree::AddPlane(this, &vecNormal);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161F70
// Name: protected: bool CDispCollTree::Cache_EdgeCrossAxisZ(class Vector const __near &,class Vector const __near &,class Vector const __near &,class CDispCollTri __near *,unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Cache_EdgeCrossAxisZ(
        CDispCollTree *this,
        const Vector *vecEdge,
        const Vector *vecOnEdge,
        const Vector *vecOffEdge,
        CDispCollTri *pTri,
        unsigned __int16 *iPlane)
{
  double v7; // st5
  float v8; // xmm0_4
  double v9; // st6
  Vector vecNormal; // [esp+0h] [ebp-Ch] BYREF
  float flDist; // [esp+14h] [ebp+8h]
  float flOffDist; // [esp+18h] [ebp+Ch]

  vecNormal.x = vecEdge->y;
  LODWORD(vecNormal.y) = LODWORD(vecEdge->x) ^ _mask__NegFloat_;
  vecNormal.z = 0.0;
  VectorNormalize(vec: &vecNormal);
  if ( vecNormal.x == 0.0 || vecNormal.y == 0.0 )
  {
    *iPlane = -1;
    return 0;
  }
  else
  {
    v7 = vecOnEdge->x * vecNormal.x + vecOnEdge->y * vecNormal.y;
    flDist = v7;
    v8 = flDist;
    v9 = vecNormal.x * vecOffEdge->x + vecNormal.y * vecOffEdge->y;
    if ( fabs(v9 - v7) >= 0.03125 )
    {
      flOffDist = v9;
      if ( flOffDist > flDist )
      {
        vecNormal.x = -vecNormal.x;
        vecNormal.y = -vecNormal.y;
        v8 = -flDist;
      }
    }
    vecNormal.z = v8;
    *iPlane = CDispCollTree::AddPlane(this, &vecNormal);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162070
// Name: public: CDispCollTree::CDispCollTree(void)
// Source: json
//------------------------------------------------------------------------------
CDispCollTree *__thiscall CDispCollTree::CDispCollTree(CDispCollTree *this)
{
  Vector *m_pMemory; // eax
  CDispCollTri *v3; // ecx

  this->__vftable = (CDispCollTree_vtbl *)&CDispCollTree::`vftable';
  this->m_aVerts.m_Memory.m_pMemory = nullptr;
  this->m_aVerts.m_pElements = nullptr;
  this->m_aTris.m_Memory.m_pMemory = nullptr;
  this->m_aTris.m_Memory.m_nAllocated = 0;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_pElements = nullptr;
  this->m_nodes.m_Memory.m_pMemory = nullptr;
  this->m_nodes.m_Memory.m_nAllocated = 0;
  this->m_nodes.m_Size = 0;
  this->m_nodes.m_pElements = nullptr;
  this->m_leaves.m_Memory.m_pMemory = nullptr;
  this->m_leaves.m_Memory.m_nAllocated = 0;
  this->m_leaves.m_Size = 0;
  this->m_leaves.m_pElements = nullptr;
  this->m_aTrisCache.m_Memory.m_pMemory = nullptr;
  this->m_aTrisCache.m_Memory.m_nAllocationCount = 0;
  this->m_aTrisCache.m_Memory.m_nGrowSize = 0;
  this->m_aTrisCache.m_Size = 0;
  this->m_aTrisCache.m_pElements = nullptr;
  this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
  this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
  this->m_aEdgePlanes.m_Memory.m_nGrowSize = 0;
  this->m_aEdgePlanes.m_Size = 0;
  this->m_aEdgePlanes.m_pElements = nullptr;
  this->m_nPower = 0;
  this->m_nFlags = 0;
  this->m_vecSurfPoints[0].x = 0.0;
  this->m_vecSurfPoints[1].x = 0.0;
  this->m_vecSurfPoints[0].y = 0.0;
  this->m_vecSurfPoints[0].z = 0.0;
  this->m_vecSurfPoints[1].y = 0.0;
  this->m_vecSurfPoints[1].z = 0.0;
  this->m_vecSurfPoints[2].x = 0.0;
  this->m_vecSurfPoints[2].y = 0.0;
  this->m_vecSurfPoints[2].z = 0.0;
  this->m_vecSurfPoints[3].x = 0.0;
  this->m_vecSurfPoints[3].y = 0.0;
  this->m_vecSurfPoints[3].z = 0.0;
  this->m_nContents = -1;
  *(_DWORD *)this->m_nSurfaceProps = 0;
  this->m_vecStabDir.x = 0.0;
  this->m_vecStabDir.y = 0.0;
  this->m_vecStabDir.z = 0.0;
  this->m_mins.x = 3.4028235e38;
  this->m_mins.y = 3.4028235e38;
  this->m_mins.z = 3.4028235e38;
  this->m_maxs.x = -3.4028235e38;
  this->m_maxs.y = -3.4028235e38;
  this->m_maxs.z = -3.4028235e38;
  this->m_iCounter = 0;
  m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
  this->m_aVerts.m_Size = 0;
  this->m_aVerts.m_Memory.m_nAllocated = 0;
  this->m_aVerts.m_pElements = m_pMemory;
  v3 = this->m_aTris.m_Memory.m_pMemory;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_Memory.m_nAllocated = 0;
  this->m_aTris.m_pElements = v3;
  this->m_aEdgePlanes.m_Size = 0;
  if ( this->m_aEdgePlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aEdgePlanes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aEdgePlanes.m_Memory.m_pMemory);
      this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
    }
    this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aEdgePlanes.m_pElements = this->m_aEdgePlanes.m_Memory.m_pMemory;
  this->m_hCache = (memhandle_t__ *)-1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10162210
// Name: protected: void CDispCollTree::AABBTree_CopyDispData(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::AABBTree_CopyDispData(CDispCollTree *this, CCoreDispInfo *pDisp)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  int v9; // eax
  int m_nPower; // ecx
  int v11; // ebx
  int m_nAllocated; // ecx
  int v13; // eax
  const char *v14; // ecx
  Vector *m_pMemory; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  const char *v22; // ecx
  CDispCollLeaf *v23; // edx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  const char *v29; // ecx
  CDispCollNode *v30; // eax
  int v31; // edx
  CDispCollNode *v32; // edx
  int v33; // ecx
  int v34; // edx
  CoreDispVert_t *m_pVerts; // ecx
  double x; // st7
  float *v37; // eax
  int p_m_Vert; // ecx
  int v39; // edi
  __int16 v40; // cx
  int v41; // eax
  unsigned __int16 iVerts[4]; // [esp+Ch] [ebp-10h] BYREF
  int numLeaves; // [esp+14h] [ebp-8h]
  int iTri; // [esp+18h] [ebp-4h]

  this->m_nPower = pDisp->m_Power;
  this->m_nContents = pDisp->m_Surf.m_Contents;
  v3 = pDisp->m_Surf.m_Points[3].y - pDisp->m_Surf.m_Points[0].y;
  v4 = pDisp->m_Surf.m_Points[3].z - pDisp->m_Surf.m_Points[0].z;
  v5 = pDisp->m_Surf.m_Points[1].y - pDisp->m_Surf.m_Points[0].y;
  v6 = pDisp->m_Surf.m_Points[1].z - pDisp->m_Surf.m_Points[0].z;
  v7 = pDisp->m_Surf.m_Points[1].x - pDisp->m_Surf.m_Points[0].x;
  v8 = pDisp->m_Surf.m_Points[3].x - pDisp->m_Surf.m_Points[0].x;
  this->m_vecStabDir.x = (float)(v3 * v6) - (float)(v4 * v5);
  this->m_vecStabDir.y = (float)(v4 * v7) - (float)(v8 * v6);
  this->m_vecStabDir.z = (float)(v8 * v5) - (float)(v3 * v7);
  VectorNormalize(vec: &this->m_vecStabDir);
  qmemcpy(this->m_vecSurfPoints, pDisp->m_Surf.m_Points, sizeof(this->m_vecSurfPoints));
  v9 = CHunkAllocCredit::s_DbgInfoStackDepth + 1;
  CHunkAllocCredit::s_DbgInfoStackDepth = v9;
  if ( v9 < 8 )
    CHunkAllocCredit::s_DbgInfoStack[v9] = "AABBTree_CopyDispData";
  m_nPower = this->m_nPower;
  this->m_aVerts.m_Size = 0;
  v11 = ((1 << m_nPower) + 1) * ((1 << m_nPower) + 1);
  if ( v11 != 0 )
  {
    m_nAllocated = this->m_aVerts.m_Memory.m_nAllocated;
    if ( v11 > m_nAllocated )
    {
      v13 = v11 - m_nAllocated;
      numLeaves = v11 - m_nAllocated;
      if ( CHunkAllocCredit::s_DbgInfoStackDepth < 7 )
      {
        if ( CHunkAllocCredit::s_DbgInfoStackDepth < 0 )
          v14 = "CHunkMemory";
        else
          v14 = CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth];
      }
      else
      {
        v14 = (const char *)unk_1069634C;
      }
      this->m_aVerts.m_Memory.m_pMemory = (Vector *)Hunk_AllocName(size: 12 * v13, name: v14, bClear: false);
      this->m_aVerts.m_Memory.m_nAllocated = numLeaves;
    }
    this->m_aVerts.m_Size += v11;
    m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
    v16 = this->m_aVerts.m_Size - v11;
    this->m_aVerts.m_pElements = m_pMemory;
    if ( v16 > 0 && v11 > 0 )
      _V_memmove(dest: &m_pMemory[v11], src: m_pMemory, count: 12 * v16);
  }
  v17 = 1 << this->m_nPower;
  this->m_aTris.m_Size = 0;
  CUtlVector<CDispCollTri,CHunkMemory<CDispCollTri>>::InsertMultipleBefore(
    this: &this->m_aTris,
    elem: 0,
    num: 2 * v17 * v17);
  v18 = this->m_nPower;
  this->m_leaves.m_Size = 0;
  v19 = (1 << v18) * (1 << v18);
  numLeaves = v19;
  if ( v19 != 0 )
  {
    v20 = this->m_leaves.m_Memory.m_nAllocated;
    if ( v19 > v20 )
    {
      v21 = v19 - v20;
      iTri = v21;
      if ( CHunkAllocCredit::s_DbgInfoStackDepth < 7 )
      {
        if ( CHunkAllocCredit::s_DbgInfoStackDepth < 0 )
          v22 = "CHunkMemory";
        else
          v22 = CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth];
      }
      else
      {
        v22 = (const char *)unk_1069634C;
      }
      this->m_leaves.m_Memory.m_pMemory = (CDispCollLeaf *)Hunk_AllocName(size: 4 * v21, name: v22, bClear: false);
      this->m_leaves.m_Memory.m_nAllocated = iTri;
      v19 = numLeaves;
    }
    this->m_leaves.m_Size += v19;
    v23 = this->m_leaves.m_Memory.m_pMemory;
    v24 = this->m_leaves.m_Size - v19;
    this->m_leaves.m_pElements = v23;
    if ( v24 > 0 && v19 > 0 )
      _V_memmove(dest: &v23[v19], src: v23, count: 4 * v24);
  }
  v25 = 2 * this->m_nPower + 2;
  this->m_nodes.m_Size = 0;
  v26 = (1 << v25) / 3 - numLeaves;
  iTri = v26;
  if ( v26 != 0 )
  {
    v27 = this->m_nodes.m_Memory.m_nAllocated;
    if ( v26 > v27 )
    {
      v28 = v26 - v27;
      numLeaves = v28;
      if ( CHunkAllocCredit::s_DbgInfoStackDepth < 7 )
      {
        if ( CHunkAllocCredit::s_DbgInfoStackDepth < 0 )
          v29 = "CHunkMemory";
        else
          v29 = CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth];
      }
      else
      {
        v29 = (const char *)unk_1069634C;
      }
      v30 = (CDispCollNode *)Hunk_AllocName(size: 96 * v28, name: v29, bClear: false);
      v31 = numLeaves;
      this->m_nodes.m_Memory.m_pMemory = v30;
      v26 = iTri;
      this->m_nodes.m_Memory.m_nAllocated = v31;
    }
    this->m_nodes.m_Size += v26;
    v32 = this->m_nodes.m_Memory.m_pMemory;
    v33 = this->m_nodes.m_Size - v26;
    this->m_nodes.m_pElements = v32;
    if ( v33 > 0 && v26 > 0 )
      _V_memmove(dest: &v32[v26], src: v32, count: 96 * v33);
  }
  v34 = 0;
  this->m_nSize = 4
                * (this->m_leaves.m_Size
                 + 3
                 * (((1 << this->m_nPower) + 1) * ((1 << this->m_nPower) + 1)
                  + 4 * ((1 << this->m_nPower) * (1 << this->m_nPower) + 2 * this->m_nodes.m_Size)
                  + 171));
  iTri = 0;
  if ( this->m_aVerts.m_Size > 0 )
  {
    numLeaves = 0;
    do
    {
      m_pVerts = pDisp->m_pVerts;
      x = m_pVerts[v34].m_Vert.x;
      v37 = (float *)((char *)&this->m_aVerts.m_Memory.m_pMemory->x + numLeaves);
      numLeaves += 12;
      p_m_Vert = (int)&m_pVerts[v34].m_Vert;
      *v37 = x;
      ++v34;
      v37[1] = *(float *)(p_m_Vert + 4);
      v37[2] = *(float *)(p_m_Vert + 8);
      ++iTri;
    }
    while ( iTri < this->m_aVerts.m_Size );
  }
  iTri = 0;
  if ( this->m_aTris.m_Size > 0 )
  {
    v39 = 0;
    numLeaves = 0;
    do
    {
      CCoreDispInfo::GetTriIndices(this: pDisp, iTri, v1: iVerts, v2: &iVerts[1], v3: &iVerts[2]);
      this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[0].m_IndexDummy ^= (iVerts[0]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[0].m_IndexDummy)
                                                                       & 0x1FF;
      this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[1].m_IndexDummy ^= (iVerts[1]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[1].m_IndexDummy)
                                                                       & 0x1FF;
      this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[2].m_IndexDummy ^= (iVerts[2]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v39].m_TriData[2].m_IndexDummy)
                                                                       & 0x1FF;
      *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v39] + 3) ^= (*((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v39] + 3)
                                                               ^ (pDisp->m_pTris[iTri].m_uiTags << 6))
                                                              & 0x7C0;
      v40 = 1024;
      if ( (float)((float)(pDisp->m_pVerts[*(unsigned __int16 *)((_BYTE *)&this->m_aTris.m_Memory.m_pMemory->m_TriData[0].m_IndexDummy
                                                               + numLeaves)
                                         & 0x1FF].m_Alpha
                         + pDisp->m_pVerts[*(unsigned __int16 *)((_BYTE *)&this->m_aTris.m_Memory.m_pMemory->m_TriData[1].m_IndexDummy
                                                               + numLeaves)
                                         & 0x1FF].m_Alpha)
                 + pDisp->m_pVerts[*(unsigned __int16 *)((_BYTE *)&this->m_aTris.m_Memory.m_pMemory->m_TriData[2].m_IndexDummy
                                                       + numLeaves)
                                 & 0x1FF].m_Alpha) <= 382.5 )
        v40 = 512;
      *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v39] + 3) |= v40;
      *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v39] + 3) |= 0x40u;
      CDispCollTri::CalcPlane(this: &this->m_aTris.m_Memory.m_pMemory[v39], m_aVerts: &this->m_aVerts);
      CDispCollTri::FindMinMax(this: &this->m_aTris.m_Memory.m_pMemory[v39], m_aVerts: &this->m_aVerts);
      numLeaves += 24;
      ++v39;
      ++iTri;
    }
    while ( iTri < this->m_aTris.m_Size );
  }
  v41 = CHunkAllocCredit::s_DbgInfoStackDepth;
  if ( CHunkAllocCredit::s_DbgInfoStackDepth >= 0 )
  {
    CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth] = nullptr;
    CHunkAllocCredit::s_DbgInfoStackDepth = v41 - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162940
// Name: class CDispCollTree __near * DispCollTrees_Alloc(int)
// Source: json
//------------------------------------------------------------------------------
CDispCollTree *__cdecl DispCollTrees_Alloc(int count)
{
  CDispCollTree *v2; // eax
  CDispCollTree *v3; // edx
  int v4; // esi
  CDispCollTree *v5; // ebx
  CDispCollTree *result; // eax
  int *p_m_iCounter; // ecx
  CDispCollTree *pTrees; // [esp+10h] [ebp+8h]

  v2 = (CDispCollTree *)Hunk_AllocName(size: 244 * count, name: "DispCollTrees_Alloc", bClear: false);
  v3 = v2;
  v4 = 0;
  pTrees = v2;
  g_nTrees = count;
  if ( count > 0 )
  {
    v5 = v2;
    do
    {
      if ( v5 != nullptr )
      {
        CDispCollTree::CDispCollTree(this: v5);
        v3 = pTrees;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < g_nTrees );
  }
  result = nullptr;
  if ( v3 != nullptr )
  {
    if ( count > 0 )
    {
      p_m_iCounter = &v3->m_iCounter;
      do
      {
        *p_m_iCounter = (int)result;
        result = (CDispCollTree *)((char *)result + 1);
        p_m_iCounter += 61;
      }
      while ( (int)result < count );
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101629C0
// Name: void DispCollTrees_Free(class CDispCollTree __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispCollTrees_Free(CDispCollTree *pTrees)
{
  int v1; // esi

  v1 = 0;
  if ( g_nTrees <= 0 )
  {
    g_nTrees = 0;
  }
  else
  {
    do
    {
      CDispCollTree::~CDispCollTree(this: pTrees);
      ++v1;
      ++pTrees;
    }
    while ( v1 < g_nTrees );
    g_nTrees = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162A00
// Name: public: void CDispCollTree::Cache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::Cache(CDispCollTree *this)
{
  int m_nPower; // ecx
  int v3; // ebx
  int v4; // esi
  int v5; // [esp+4h] [ebp-4h]

  m_nPower = this->m_nPower;
  if ( this->m_aTrisCache.m_Size != 2 * (1 << m_nPower) * (1 << m_nPower) )
  {
    v3 = 0;
    this->m_aTrisCache.m_Size = 0;
    v4 = 2 * (1 << m_nPower) * (1 << m_nPower);
    CUtlVector<CDispCollTriCache,CUtlMemory<CDispCollTriCache,int>>::InsertMultipleBefore(
      this: &this->m_aTrisCache,
      elem: 0,
      num: v4);
    if ( v4 > 0 )
    {
      v5 = 0;
      do
        CDispCollTree::Cache_Create(this, pTri: &this->m_aTris.m_Memory.m_pMemory[v5++], iTri: v3++);
      while ( v3 < v4 );
    }
    CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: (CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *)&g_DispCollPlaneIndexHash);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162A80
// Name: public: virtual bool CDispCollTree::Create(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Create(CDispCollTree *this, CCoreDispInfo *pDisp)
{
  this->m_nFlags = pDisp->m_Surf.m_Flags;
  CDispCollTree::AABBTree_CopyDispData(this, pDisp);
  CDispCollTree::AABBTree_CreateLeafs(this);
  if ( this->m_aVerts.m_Size != 0 && this->m_nodes.m_Size != 0 )
  {
    CDispCollTree::AABBTree_GenerateBoxes_r(this, nodeIndex: 0, pMins: &this->m_mins, pMaxs: &this->m_maxs);
    this->m_mins.x = this->m_mins.x - 1.0;
    this->m_maxs.x = this->m_maxs.x + 1.0;
    this->m_mins.y = this->m_mins.y - 1.0;
    this->m_maxs.y = this->m_maxs.y + 1.0;
    this->m_mins.z = this->m_mins.z - 1.0;
    this->m_maxs.z = this->m_maxs.z + 1.0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162B30
// Name: public: void CDispCollTree::LockCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::LockCache(CDispCollTree *this)
{
  _DWORD *v2; // eax
  DWORD CurrentThreadId; // eax
  _DWORD *v4; // eax
  memhandle_t__ *v5; // eax
  CDispCollTree *createParams; // [esp+4h] [ebp-4h] BYREF

  v2 = CDataManagerBase::LockResource(this: &g_DispCollTriCache, handle: this->m_hCache);
  if ( v2 == nullptr || v2[47] != v2[34] )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_CacheMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_CacheMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_CacheMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_CacheMutex.m_depth;
    }
    v4 = CDataManagerBase::LockResource(this: &g_DispCollTriCache, handle: this->m_hCache);
    if ( v4 == nullptr || v4[47] != v4[34] )
    {
      CDispCollTree::Cache(this);
      createParams = this;
      v5 = CDataManager<CDispCollTree,CDispCollTree *,bool,CThreadFastMutex>::CreateResource(
             this: &g_DispCollTriCache,
             &createParams,
             bCreateLocked: false);
      this->m_hCache = v5;
      CDataManagerBase::LockResource(this: &g_DispCollTriCache, handle: v5);
    }
    if ( --s_CacheMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_CacheMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162C10
// Name: public: bool CDispCollTree::AABBTree_SweepAABB(struct Ray_t const __near &,class Vector const __near &,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CDispCollTree::AABBTree_SweepAABB@<al>(
        CDispCollTree *this@<ecx>,
        float a2@<ebp>,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        CBaseTrace *pTrace)
{
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm0
  int v10; // edi
  __m128 v11; // xmm7
  __m128 v12; // xmm6
  float y; // edx
  int v14; // ecx
  CDispCollNode *v15; // eax
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm3
  __m128 v22; // xmm7
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  CDispCollLeaf *m_pMemory; // ecx
  int v27; // edi
  int v28; // eax
  _BYTE v30[1552]; // [esp-Ch] [ebp-65Ch] OVERLAPPED
  __m128 v31; // [esp+604h] [ebp-4Ch]
  CDispCollTri *v32; // [esp+62Ch] [ebp-24h]
  Vector v33; // [esp+630h] [ebp-20h] BYREF
  Vector rayDir; // [esp+63Ch] [ebp-14h]
  float flFrac; // [esp+648h] [ebp-8h]
  float retaddr; // [esp+650h] [ebp+0h]

  rayDir.z = a2;
  flFrac = retaddr;
  if ( (this->m_nFlags & 4) != 0 )
    return false;
  v33 = ray->m_Delta.Vector;
  VectorNormalize(vec: &v33);
  rayDir.x = pTrace->fraction;
  *(__m128 *)&v30[96] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->x), (__m128)LODWORD(vecInvDelta->x), 0);
  *(__m128 *)&v30[112] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->y), (__m128)LODWORD(vecInvDelta->y), 0);
  *(__m128 *)&v30[128] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->z), (__m128)LODWORD(vecInvDelta->z), 0);
  *(__m128 *)&v30[16] = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.y), (__m128)LODWORD(ray->m_Start.y), 0);
  v7 = 0;
  v7.m128_f32[0] = ray->m_Extents.x + g_Vec3DispCollEpsilons.x;
  *(__m128 *)&v30[48] = _mm_shuffle_ps(v7, v7, 0);
  v8 = 0;
  v8.m128_f32[0] = ray->m_Extents.y + g_Vec3DispCollEpsilons.y;
  *(__m128 *)&v30[64] = _mm_shuffle_ps(v8, v8, 0);
  v9 = 0;
  v10 = 0;
  v9.m128_f32[0] = ray->m_Extents.z + g_Vec3DispCollEpsilons.z;
  v11 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.x), (__m128)LODWORD(ray->m_Start.x), 0);
  v12 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.z), (__m128)LODWORD(ray->m_Start.z), 0);
  *(__m128 *)v30 = v11;
  *(__m128 *)&v30[32] = v12;
  *(__m128 *)&v30[80] = _mm_shuffle_ps(v9, v9, 0);
  *(_DWORD *)&v30[144] = 0;
  y = 0.0;
  *(_DWORD *)&v30[1520] = 0;
  while ( 1 )
  {
    v14 = *(_DWORD *)&v30[4 * LODWORD(y) + 144];
    if ( v14 >= this->m_nodes.m_Size )
      break;
    v15 = &this->m_nodes.m_Memory.m_pMemory[v14];
    ++LODWORD(y);
    v16 = _mm_mul_ps(
            _mm_add_ps(_mm_sub_ps(v15->m_maxs.y, *(__m128 *)&v30[16]), *(__m128 *)&v30[64]),
            *(__m128 *)&v30[112]);
    v17 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(v15->m_mins.x, v11), *(__m128 *)&v30[48]), *(__m128 *)&v30[96]);
    v18 = _mm_sub_ps(_mm_sub_ps(v15->m_mins.z, v12), *(__m128 *)&v30[80]);
    v19 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(v15->m_maxs.z, v12), *(__m128 *)&v30[80]), *(__m128 *)&v30[128]);
    v20 = _mm_mul_ps(
            _mm_sub_ps(_mm_sub_ps(v15->m_mins.y, *(__m128 *)&v30[16]), *(__m128 *)&v30[64]),
            *(__m128 *)&v30[112]);
    *(__m128 *)&v30[1536] = _mm_add_ps(_mm_sub_ps(v15->m_maxs.x, v11), *(__m128 *)&v30[48]);
    v21 = _mm_mul_ps(v18, *(__m128 *)&v30[128]);
    v22 = _mm_mul_ps(*(__m128 *)&v30[1536], *(__m128 *)&v30[96]);
    v31 = v16;
    v23 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_max_ps(_mm_max_ps(_mm_min_ps(v17, v22), _mm_min_ps(v20, v16)), _mm_min_ps(v21, v19)),
                Four_Zeros),
              _mm_min_ps(
                _mm_min_ps(_mm_min_ps(_mm_max_ps(v17, v22), _mm_max_ps(v20, v16)), _mm_max_ps(v21, v19)),
                Four_Ones)));
    rayDir.y = y;
    if ( v23 != 0 )
    {
      v24 = 4 * v14 + 1;
      if ( (v23 & 1) != 0 )
      {
        *(_DWORD *)&v30[1520] = v10 + 1;
        *(_DWORD *)&v30[4 * *(_DWORD *)&v30[1520] + 144] = v24;
        v10 = *(_DWORD *)&v30[1520];
      }
      if ( (v23 & 2) != 0 )
      {
        *(_DWORD *)&v30[1520] = v10 + 1;
        *(_DWORD *)&v30[4 * *(_DWORD *)&v30[1520] + 144] = v24 + 1;
        v10 = *(_DWORD *)&v30[1520];
        y = rayDir.y;
      }
      if ( (v23 & 4) != 0 )
      {
        *(_DWORD *)&v30[1520] = v10 + 1;
        *(_DWORD *)&v30[4 * *(_DWORD *)&v30[1520] + 144] = v24 + 2;
        v10 = *(_DWORD *)&v30[1520];
        y = rayDir.y;
      }
      if ( (v23 & 8) != 0 )
      {
        *(_DWORD *)&v30[1520] = v10 + 1;
        *(_DWORD *)&v30[4 * *(_DWORD *)&v30[1520] + 144] = v24 + 3;
        v10 = *(_DWORD *)&v30[1520];
      }
    }
    if ( SLODWORD(y) > v10 )
      break;
    v11 = *(__m128 *)v30;
    v12 = *(__m128 *)&v30[32];
  }
  rayDir.y = y;
  if ( SLODWORD(y) <= v10 )
  {
    CDispCollTree::LockCache(this);
    do
    {
      v25 = *(_DWORD *)&v30[4 * LODWORD(rayDir.y) + 144] - this->m_nodes.m_Size;
      m_pMemory = this->m_leaves.m_Memory.m_pMemory;
      v27 = m_pMemory[v25].m_tris[1];
      v28 = m_pMemory[v25].m_tris[0];
      v32 = this->m_aTris.m_Memory.m_pMemory;
      CDispCollTree::SweepAABBTriIntersect(this, ray, rayDir: &v33, iTri: v28, pTri: &v32[v28], pTrace);
      CDispCollTree::SweepAABBTriIntersect(this, ray, rayDir: &v33, iTri: v27, pTri: &v32[v27], pTrace);
      ++LODWORD(rayDir.y);
    }
    while ( SLODWORD(rayDir.y) <= *(int *)&v30[1520] );
    CDataManagerBase::UnlockResource(this: &g_DispCollTriCache, handle: this->m_hCache);
  }
  return rayDir.x > pTrace->fraction;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10018B20
// Name: public: void CUtlHash<struct SampleData_t,bool (*)(struct SampleData_t const __near &,struct SampleData_t const __near &),unsigned int (*)(struct SampleData_t const __near &)>::Log(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::Log(
        CUtlHash<SampleData_t,bool (__cdecl*)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl*)(SampleData_t const &)> *this,
        const char *filename)
{
  _iobuf *v3; // eax
  _iobuf *v4; // ebx
  int v5; // esi
  int m_Size; // edi
  int v7; // eax
  int maxBucketSize; // [esp+10h] [ebp-8h]
  int numBucketsEmpty; // [esp+14h] [ebp-4h]
  const char *filenamea; // [esp+20h] [ebp+8h]

  v3 = fopen(file: filename, mode: "w");
  v4 = v3;
  v5 = 0;
  if ( v3 != nullptr )
  {
    m_Size = this->m_Buckets.m_Size;
    maxBucketSize = 0;
    numBucketsEmpty = 0;
    fprintf(str: v3, format: "\n%d Buckets\n", m_Size);
    if ( m_Size > 0 )
    {
      filenamea = nullptr;
      do
      {
        v7 = *(_DWORD *)&filenamea[(unsigned int)this->m_Buckets.m_Memory.m_pMemory + 12];
        if ( v7 > maxBucketSize )
          maxBucketSize = *(_DWORD *)&filenamea[(unsigned int)this->m_Buckets.m_Memory.m_pMemory + 12];
        if ( v7 == 0 )
          ++numBucketsEmpty;
        fprintf(str: v4, format: "Bucket %d: %d\n", v5, v7);
        filenamea += 20;
        ++v5;
      }
      while ( v5 < m_Size );
    }
    fprintf(str: v4, format: "\nBucketHeads Used: %d\n", m_Size - numBucketsEmpty);
    fprintf(str: v4, format: "Max Bucket Size: %d\n", maxBucketSize);
    fclose(stream: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018BD0
// Name: protected: bool CUtlHash<struct SampleData_t,bool (*)(struct SampleData_t const __near &,struct SampleData_t const __near &),unsigned int (*)(struct SampleData_t const __near &)>::DoFind(struct SampleData_t const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::DoFind(
        CUtlHash<PatchSampleData_t,bool (__cdecl*)(PatchSampleData_t const &,PatchSampleData_t const &),unsigned int (__cdecl*)(PatchSampleData_t const &)> *this,
        const PatchSampleData_t *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  int m_Size; // ecx
  CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *v9; // eax
  int v10; // edi
  int v11; // ebx
  const CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *bucket; // [esp+8h] [ebp-4h]
  int keyDataCount; // [esp+18h] [ebp+Ch]

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = v6;
  m_Size = this->m_Buckets.m_Memory.m_pMemory[v7].m_Size;
  v9 = &this->m_Buckets.m_Memory.m_pMemory[v7];
  v10 = 0;
  bucket = v9;
  keyDataCount = m_Size;
  if ( m_Size > 0 )
  {
    v11 = 0;
    while ( !this->m_CompareFunc(a1: &v9->m_Memory.m_pMemory[v11], a2: src) )
    {
      ++v10;
      ++v11;
      if ( v10 >= keyDataCount )
        break;
      v9 = (CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *)bucket;
    }
    m_Size = keyDataCount;
  }
  if ( v10 == m_Size )
    return 0;
  *pIndex = v10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019330
// Name: public: void CUtlHash<struct SampleData_t,bool (*)(struct SampleData_t const __near &,struct SampleData_t const __near &),unsigned int (*)(struct SampleData_t const __near &)>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::Purge(
        CUtlHash<PatchSampleData_t,bool (__cdecl*)(PatchSampleData_t const &,PatchSampleData_t const &),unsigned int (__cdecl*)(PatchSampleData_t const &)> *this)
{
  int v1; // edi
  int m_Size; // ebx
  CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *v3; // esi
  CUtlHash<PatchSampleData_t,bool (__cdecl*)(PatchSampleData_t const &,PatchSampleData_t const &),unsigned int (__cdecl*)(PatchSampleData_t const &)> *v4; // [esp+0h] [ebp-4h]

  v4 = this;
  if ( this->m_Buckets.m_Size > 0 )
  {
    v1 = 0;
    m_Size = this->m_Buckets.m_Size;
    while ( 1 )
    {
      v3 = &this->m_Buckets.m_Memory.m_pMemory[v1];
      CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      ++v1;
      --m_Size;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( m_Size == 0 )
        break;
      this = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047570
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100475C0
// Name: void __near * MemAlloc_ReallocAligned(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl MemAlloc_ReallocAligned(unsigned __int8 *ptr, unsigned int size, unsigned int align)
{
  void *v4; // ebx
  unsigned int v5; // esi
  unsigned __int8 *pResult; // [esp+10h] [ebp+10h]

  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( ((align - 1) & (unsigned int)ptr) != 0 )
    return nullptr;
  if ( ptr == nullptr )
    return (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  v4 = *(void **)(((unsigned int)ptr & 0xFFFFFFFC) - 4);
  v5 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v4);
  if ( v5 >= ptr - (_BYTE *)v4 + size )
    return ptr;
  pResult = (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  memcpy(dst: pResult, src: ptr, count: v5 - (ptr - (_BYTE *)v4));
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x10047660
// Name: public: void CUtlMemoryAligned<class CDispCollNode,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<CDispCollNode,16>::Grow(CUtlMemoryAligned<CDispCollNode,16> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  CDispCollNode *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  CDispCollNode *v9; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 96 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (CDispCollNode *)MemAlloc_ReallocAligned(
                                           ptr: (unsigned __int8 *)m_pMemory,
                                           size: v7,
                                           align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (CDispCollNode *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        v9[-1].m_maxs.z.m128_i32[3] = (int)v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100476F0
// Name: public: void CUtlMemoryAligned<class CDispCollLeaf,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<CDispCollLeaf,16>::Grow(CUtlMemoryAligned<CDispCollLeaf,16> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  unsigned __int8 *m_pMemory; // ecx
  void *v7; // eax
  CDispCollLeaf *v8; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    m_pMemory = (unsigned __int8 *)this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (CDispCollLeaf *)MemAlloc_ReallocAligned(
                                           ptr: m_pMemory,
                                           size: 4 * m_nAllocationCount,
                                           align: 0x10u);
    }
    else
    {
      v7 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nAllocationCount + 19);
      if ( v7 != nullptr )
      {
        v8 = (CDispCollLeaf *)(((unsigned int)v7 + 19) & 0xFFFFFFF0);
        v8[-1] = (CDispCollLeaf)v7;
        this->m_pMemory = v8;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047780
// Name: public: void CUtlMemoryAligned<class Vector,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<Vector,16>::Grow(CUtlMemoryAligned<Vector,16> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  unsigned __int8 *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  Vector *v9; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    m_pMemory = (unsigned __int8 *)this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (Vector *)MemAlloc_ReallocAligned(ptr: m_pMemory, size: v7, align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (Vector *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        LODWORD(v9[-1].z) = v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047810
// Name: public: void CUtlMemoryAligned<class CDispCollTri,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<CDispCollTri,16>::Grow(CUtlMemoryAligned<CDispCollTri,16> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  unsigned __int8 *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  CDispCollTri *v9; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    m_pMemory = (unsigned __int8 *)this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (CDispCollTri *)MemAlloc_ReallocAligned(ptr: m_pMemory, size: v7, align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (CDispCollTri *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        LODWORD(v9[-1].m_flDist) = v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100478A0
// Name: public: void CDispCollTri::CalcPlane(class CDispVector<class Vector> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTri::CalcPlane(CDispCollTri *this, CDispVector<Vector> *m_aVerts)
{
  int v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  Vector *p_m_vecNormal; // edi
  __int16 v11; // cx
  int i; // ecx

  v3 = this->m_TriData[1].m_IndexDummy & 0x1FF;
  v4 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].z
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v5 = m_aVerts->m_Memory.m_pMemory[v3].y - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v6 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].y
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v7 = m_aVerts->m_Memory.m_pMemory[v3].z - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v8 = m_aVerts->m_Memory.m_pMemory[v3].x - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v9 = m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].x
     - m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  p_m_vecNormal = &this->m_vecNormal;
  this->m_vecNormal.x = (float)(v6 * v7) - (float)(v4 * v5);
  this->m_vecNormal.y = (float)(v4 * v8) - (float)(v7 * v9);
  this->m_vecNormal.z = (float)(v5 * v9) - (float)(v6 * v8);
  VectorNormalize(vec: &this->m_vecNormal);
  v11 = *((_WORD *)this + 3) & 0xFFC0 | 0x28;
  this->m_flDist = (float)((float)(m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].y
                                 * this->m_vecNormal.y)
                         + (float)(m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x
                                 * this->m_vecNormal.x))
                 + (float)(m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z * this->m_vecNormal.z);
  *((_WORD *)this + 3) = v11;
  for ( i = 0; i < 3; ++i )
  {
    if ( p_m_vecNormal->x < 0.0 )
      *((_WORD *)this + 3) |= (1 << i) & 7;
    if ( p_m_vecNormal->x == 1.0 )
      *((_WORD *)this + 3) ^= (*((_WORD *)this + 3) ^ (8 * i)) & 0x38;
    p_m_vecNormal = (Vector *)((char *)p_m_vecNormal + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047A10
// Name: public: void CDispCollTri::FindMinMax(class CDispVector<class Vector> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTri::FindMinMax(CDispCollTri *this, CDispVector<Vector> *m_aVerts)
{
  Vector *m_pMemory; // eax
  float x; // xmm0_4
  char v4; // si
  float v5; // xmm1_4
  int v6; // edi
  float v7; // xmm2_4
  float v8; // xmm0_4
  char v9; // al
  __int16 v10; // ax
  unsigned __int16 m_IndexDummy; // si
  unsigned __int16 v12; // ax
  Vector *v13; // edx
  float y; // xmm2_4
  int v15; // esi
  char v16; // di
  float v17; // xmm0_4
  float v18; // xmm0_4
  int v19; // esi
  char v20; // al
  unsigned __int16 v21; // ax
  Vector *v22; // edx
  char v23; // di
  float z; // xmm0_4
  float v25; // xmm0_4
  char v26; // al

  m_pMemory = m_aVerts->m_Memory.m_pMemory;
  x = m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v4 = 0;
  if ( x > m_aVerts->m_Memory.m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x )
  {
    x = m_aVerts->m_Memory.m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x;
    v4 = 1;
  }
  if ( x > m_aVerts->m_Memory.m_pMemory[this->m_TriData[2].m_IndexDummy & 0x1FF].x )
    v4 = 2;
  v5 = m_pMemory[this->m_TriData[1].m_IndexDummy & 0x1FF].x;
  v6 = this->m_TriData[2].m_IndexDummy & 0x1FF;
  v7 = m_pMemory[v6].x;
  v8 = m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].x;
  v9 = 0;
  if ( v5 > v8 )
  {
    v8 = v5;
    v9 = 1;
  }
  if ( v7 > v8 )
    v9 = 2;
  v10 = (v4 & 3 | (unsigned __int16)(4 * (v9 & 3))) << 9;
  m_IndexDummy = this->m_TriData[1].m_IndexDummy;
  v12 = this->m_TriData[0].m_IndexDummy & 0xE1FF | v10;
  this->m_TriData[0].m_IndexDummy = v12;
  v13 = m_aVerts->m_Memory.m_pMemory;
  y = m_aVerts->m_Memory.m_pMemory[v6].y;
  v15 = m_IndexDummy & 0x1FF;
  v16 = 0;
  v17 = m_aVerts->m_Memory.m_pMemory[v12 & 0x1FF].y;
  if ( v17 > m_aVerts->m_Memory.m_pMemory[v15].y )
  {
    v17 = m_aVerts->m_Memory.m_pMemory[v15].y;
    v16 = 1;
  }
  if ( v17 > y )
    v16 = 2;
  v18 = v13[this->m_TriData[0].m_IndexDummy & 0x1FF].y;
  v19 = this->m_TriData[2].m_IndexDummy & 0x1FF;
  v20 = 0;
  if ( v13[this->m_TriData[1].m_IndexDummy & 0x1FF].y > v18 )
  {
    v18 = v13[this->m_TriData[1].m_IndexDummy & 0x1FF].y;
    v20 = 1;
  }
  if ( v13[v19].y > v18 )
    v20 = 2;
  v21 = this->m_TriData[1].m_IndexDummy & 0xE1FF | ((v16 & 3 | (unsigned __int16)(4 * (v20 & 3))) << 9);
  this->m_TriData[1].m_IndexDummy = v21;
  v22 = m_aVerts->m_Memory.m_pMemory;
  v23 = 0;
  z = m_aVerts->m_Memory.m_pMemory[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  if ( z > m_aVerts->m_Memory.m_pMemory[v21 & 0x1FF].z )
  {
    z = m_aVerts->m_Memory.m_pMemory[v21 & 0x1FF].z;
    v23 = 1;
  }
  if ( z > m_aVerts->m_Memory.m_pMemory[v19].z )
    v23 = 2;
  v25 = v22[this->m_TriData[0].m_IndexDummy & 0x1FF].z;
  v26 = 0;
  if ( v22[this->m_TriData[1].m_IndexDummy & 0x1FF].z > v25 )
  {
    v25 = v22[this->m_TriData[1].m_IndexDummy & 0x1FF].z;
    v26 = 1;
  }
  if ( v22[this->m_TriData[2].m_IndexDummy & 0x1FF].z > v25 )
    v26 = 2;
  this->m_TriData[2].m_IndexDummy = this->m_TriData[2].m_IndexDummy & 0xE1FF
                                  | ((v23 & 3 | (unsigned __int16)(4 * (v26 & 3))) << 9);
}

//------------------------------------------------------------------------------
// Address: 0x10047C50
// Name: protected: void CDispCollTree::AABBTree_GenerateBoxes_r(int,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CDispCollTree::AABBTree_GenerateBoxes_r(
        CDispCollTree *this,
        int nodeIndex,
        Vector *pMins,
        Vector *pMaxs)
{
  int m_Size; // ecx
  const CDispCollTri *v7; // eax
  CDispCollNode *m_pMemory; // eax
  int v9; // ecx
  __m128 x; // xmm1
  __m128 y; // xmm2
  CDispCollNode *v12; // eax
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 z; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  CDispCollNode *v18; // edx
  __m128 v19; // xmm1
  int p_m_maxs; // eax
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  _BYTE childMaxs[52]; // [esp+8h] [ebp-6Ch] OVERLAPPED BYREF
  _BYTE childMins[52]; // [esp+3Ch] [ebp-38h] OVERLAPPED BYREF
  int i; // [esp+70h] [ebp-4h]
  int nodeIndexa; // [esp+7Ch] [ebp+8h]
  const CDispCollTri *tria; // [esp+84h] [ebp+10h]
  const CDispCollTri *tri; // [esp+84h] [ebp+10h]

  ClearBounds(mins: pMins, maxs: pMaxs);
  m_Size = this->m_nodes.m_Size;
  if ( nodeIndex < m_Size )
  {
    i = 4 * nodeIndex + 1;
    v7 = nullptr;
    for ( tri = nullptr; ; v7 = tri )
    {
      CDispCollTree::AABBTree_GenerateBoxes_r(
        this,
        nodeIndex: i,
        pMins: (Vector *)&childMins[(_DWORD)v7],
        pMaxs: (Vector *)&childMaxs[(_DWORD)v7]);
      AddPointToBounds(v: (const Vector *)&childMins[(_DWORD)tri], mins: pMins, maxs: pMaxs);
      AddPointToBounds(v: (const Vector *)&childMaxs[(_DWORD)tri], mins: pMins, maxs: pMaxs);
      ++i;
      tri = (const CDispCollTri *)((char *)tri + 12);
      if ( (int)tri >= 48 )
        break;
    }
    m_pMemory = this->m_nodes.m_Memory.m_pMemory;
    v9 = nodeIndex;
    m_pMemory[v9].m_mins.x = *(__m128 *)childMins;
    x = m_pMemory[nodeIndex].m_mins.x;
    m_pMemory[v9].m_mins.y = *(__m128 *)&childMins[12];
    m_pMemory[v9].m_mins.z = *(__m128 *)&childMins[24];
    y = m_pMemory[nodeIndex].m_mins.y;
    v12 = &m_pMemory[nodeIndex];
    v13 = _mm_shuffle_ps(x, y, 68);
    v14 = _mm_shuffle_ps(x, y, 238);
    z = v12->m_mins.z;
    v16 = _mm_shuffle_ps(z, *(__m128 *)&childMins[36], 238);
    v17 = _mm_shuffle_ps(z, *(__m128 *)&childMins[36], 68);
    v12->m_mins.x = _mm_shuffle_ps(v13, v17, 136);
    v12->m_mins.y = _mm_shuffle_ps(v13, v17, 221);
    v12->m_mins.z = _mm_shuffle_ps(v14, v16, 136);
    v18 = this->m_nodes.m_Memory.m_pMemory;
    v18[v9].m_maxs.x = *(__m128 *)childMaxs;
    v19 = v18[nodeIndex].m_maxs.x;
    p_m_maxs = (int)&v18[nodeIndex].m_maxs;
    *(_OWORD *)(p_m_maxs + 16) = *(_OWORD *)&childMaxs[12];
    *(_OWORD *)(p_m_maxs + 32) = *(_OWORD *)&childMaxs[24];
    v21 = v18[nodeIndex].m_maxs.y;
    v22 = _mm_shuffle_ps(v19, v21, 68);
    v23 = _mm_shuffle_ps(v19, v21, 238);
    v24 = _mm_shuffle_ps(v18[nodeIndex].m_maxs.z, *(__m128 *)&childMaxs[36], 68);
    v25 = _mm_shuffle_ps(v18[nodeIndex].m_maxs.z, *(__m128 *)&childMaxs[36], 238);
    *(__m128 *)p_m_maxs = _mm_shuffle_ps(v22, v24, 136);
    *(__m128 *)(p_m_maxs + 16) = _mm_shuffle_ps(v22, v24, 221);
    *(__m128 *)(p_m_maxs + 32) = _mm_shuffle_ps(v23, v25, 136);
  }
  else
  {
    nodeIndexa = 2 * (nodeIndex - m_Size);
    for ( i = 2; i != 0; --i )
    {
      tria = &this->m_aTris.m_Memory.m_pMemory[this->m_leaves.m_Memory.m_pMemory->m_tris[nodeIndexa]];
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[0].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[1].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      AddPointToBounds(
        v: &this->m_aVerts.m_Memory.m_pMemory[tria->m_TriData[2].m_IndexDummy & 0x1FF],
        mins: pMins,
        maxs: pMaxs);
      ++nodeIndexa;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047E60
// Name: protected: void CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(struct Ray_t const __near &,class Vector const __near &,int,struct RayDispOutput_t __near &,class CDispCollTri __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(
        CDispCollTree *this@<ecx>,
        float a2@<ebp>,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        int iNode,
        RayDispOutput_t *output,
        CDispCollTri **pImpactTri)
{
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  int v12; // edx
  int v13; // edi
  __m128 v14; // xmm7
  __m128 v15; // xmm6
  int v16; // ecx
  CDispCollNode *v17; // eax
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm3
  __m128 v24; // xmm7
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  CDispCollLeaf *m_pMemory; // ecx
  int v29; // edi
  int v30; // eax
  CDispCollTri *v31; // ecx
  CDispCollTri *v32; // edi
  const Vector *v33; // ecx
  int v34; // edx
  int v35; // eax
  Vector *v36; // ecx
  float v37; // xmm2_4
  float v38; // xmm0_4
  CDispCollTri *v39; // xmm1_4
  CDispCollTri *v40; // edi
  Vector *v41; // ecx
  int v42; // edx
  float v43; // xmm2_4
  float v44; // xmm0_4
  CDispCollTri *v45; // xmm1_4
  _BYTE v46[1552]; // [esp-Ch] [ebp-65Ch] OVERLAPPED
  __m128 v47; // [esp+604h] [ebp-4Ch]
  const Vector *v48; // [esp+62Ch] [ebp-24h]
  float v49; // [esp+630h] [ebp-20h] BYREF
  Vector *v50; // [esp+634h] [ebp-1Ch]
  float v51; // [esp+638h] [ebp-18h] BYREF
  int flU; // [esp+63Ch] [ebp-14h]
  CDispCollTri *pTri1; // [esp+640h] [ebp-10h] BYREF
  float flV; // [esp+644h] [ebp-Ch]
  int listIndex; // [esp+648h] [ebp-8h]
  int retaddr; // [esp+650h] [ebp+0h]

  flV = a2;
  listIndex = retaddr;
  *(__m128 *)&v46[96] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->x), (__m128)LODWORD(vecInvDelta->x), 0);
  *(__m128 *)&v46[112] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->y), (__m128)LODWORD(vecInvDelta->y), 0);
  *(__m128 *)&v46[128] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->z), (__m128)LODWORD(vecInvDelta->z), 0);
  *(__m128 *)&v46[16] = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.y), (__m128)LODWORD(ray->m_Start.y), 0);
  v9 = 0;
  v9.m128_f32[0] = ray->m_Extents.x + 0.03125;
  *(__m128 *)&v46[48] = _mm_shuffle_ps(v9, v9, 0);
  v10 = 0;
  v10.m128_f32[0] = ray->m_Extents.y + 0.03125;
  *(__m128 *)&v46[64] = _mm_shuffle_ps(v10, v10, 0);
  v11 = 0;
  *(float *)&v12 = 0.0;
  v11.m128_f32[0] = ray->m_Extents.z + 0.03125;
  v13 = 0;
  v14 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.x), (__m128)LODWORD(ray->m_Start.x), 0);
  v15 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.z), (__m128)LODWORD(ray->m_Start.z), 0);
  *(__m128 *)v46 = v14;
  *(__m128 *)&v46[32] = v15;
  *(__m128 *)&v46[80] = _mm_shuffle_ps(v11, v11, 0);
  *(_DWORD *)&v46[144] = iNode;
  *(_DWORD *)&v46[1520] = 0;
  while ( 1 )
  {
    v16 = *(_DWORD *)&v46[4 * v12 + 144];
    if ( v16 >= this->m_nodes.m_Size )
      break;
    v17 = &this->m_nodes.m_Memory.m_pMemory[v16];
    pTri1 = (CDispCollTri *)++v12;
    v18 = _mm_mul_ps(
            _mm_add_ps(_mm_sub_ps(v17->m_maxs.y, *(__m128 *)&v46[16]), *(__m128 *)&v46[64]),
            *(__m128 *)&v46[112]);
    v19 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(v17->m_mins.x, v14), *(__m128 *)&v46[48]), *(__m128 *)&v46[96]);
    v20 = _mm_sub_ps(_mm_sub_ps(v17->m_mins.z, v15), *(__m128 *)&v46[80]);
    v21 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(v17->m_maxs.z, v15), *(__m128 *)&v46[80]), *(__m128 *)&v46[128]);
    v22 = _mm_mul_ps(
            _mm_sub_ps(_mm_sub_ps(v17->m_mins.y, *(__m128 *)&v46[16]), *(__m128 *)&v46[64]),
            *(__m128 *)&v46[112]);
    *(__m128 *)&v46[1536] = _mm_add_ps(_mm_sub_ps(v17->m_maxs.x, v14), *(__m128 *)&v46[48]);
    v23 = _mm_mul_ps(v20, *(__m128 *)&v46[128]);
    v24 = _mm_mul_ps(*(__m128 *)&v46[1536], *(__m128 *)&v46[96]);
    v47 = v18;
    v25 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_max_ps(_mm_max_ps(_mm_min_ps(v19, v24), _mm_min_ps(v22, v18)), _mm_min_ps(v23, v21)),
                Four_Zeros),
              _mm_min_ps(
                _mm_min_ps(_mm_min_ps(_mm_max_ps(v19, v24), _mm_max_ps(v22, v18)), _mm_max_ps(v23, v21)),
                Four_Ones)));
    if ( v25 != 0 )
    {
      v26 = 4 * v16 + 1;
      if ( (v25 & 1) != 0 )
      {
        *(_DWORD *)&v46[1520] = v13 + 1;
        *(_DWORD *)&v46[4 * *(_DWORD *)&v46[1520] + 144] = v26;
        v13 = *(_DWORD *)&v46[1520];
      }
      if ( (v25 & 2) != 0 )
      {
        *(_DWORD *)&v46[1520] = v13 + 1;
        *(_DWORD *)&v46[4 * *(_DWORD *)&v46[1520] + 144] = v26 + 1;
        v13 = *(_DWORD *)&v46[1520];
        v12 = (int)pTri1;
      }
      if ( (v25 & 4) != 0 )
      {
        *(_DWORD *)&v46[1520] = v13 + 1;
        *(_DWORD *)&v46[4 * *(_DWORD *)&v46[1520] + 144] = v26 + 2;
        v13 = *(_DWORD *)&v46[1520];
        v12 = (int)pTri1;
      }
      if ( (v25 & 8) != 0 )
      {
        *(_DWORD *)&v46[1520] = v13 + 1;
        *(_DWORD *)&v46[4 * *(_DWORD *)&v46[1520] + 144] = v26 + 3;
        v13 = *(_DWORD *)&v46[1520];
      }
    }
    if ( v12 > v13 )
      break;
    v14 = *(__m128 *)v46;
    v15 = *(__m128 *)&v46[32];
  }
  flU = v12;
  if ( v12 <= v13 )
  {
    do
    {
      v27 = *(_DWORD *)&v46[4 * flU + 144] - this->m_nodes.m_Size;
      m_pMemory = this->m_leaves.m_Memory.m_pMemory;
      v29 = m_pMemory[v27].m_tris[0];
      v30 = m_pMemory[v27].m_tris[1];
      v31 = this->m_aTris.m_Memory.m_pMemory;
      v32 = &v31[v29];
      v33 = (const Vector *)&v31[v30];
      v34 = v32->m_TriData[1].m_IndexDummy & 0x1FF;
      v35 = v32->m_TriData[2].m_IndexDummy & 0x1FF;
      v50 = (Vector *)v33;
      v36 = this->m_aVerts.m_Memory.m_pMemory;
      v48 = &v36[v35];
      if ( ComputeIntersectionBarycentricCoordinates(
             ray,
             v1: &v36[v32->m_TriData[0].m_IndexDummy & 0x1FF],
             v2: v48,
             v3: &v36[v34],
             u: &v49,
             v: &v51,
             t: (float *)&pTri1) )
      {
        v37 = v49;
        if ( v49 >= 0.0 )
        {
          v38 = v51;
          if ( v51 >= 0.0 && (float)(v49 + v51) <= 1.0 )
          {
            v39 = pTri1;
            if ( *(float *)&pTri1 > 0.0 && output->dist > *(float *)&pTri1 )
            {
              *pImpactTri = v32;
              output->u = v37;
              output->v = v38;
              LODWORD(output->dist) = v39;
            }
          }
        }
      }
      v40 = (CDispCollTri *)v50;
      v41 = this->m_aVerts.m_Memory.m_pMemory;
      v42 = HIWORD(v50->x) & 0x1FF;
      v50 = &v41[LOWORD(v50->y) & 0x1FF];
      if ( ComputeIntersectionBarycentricCoordinates(
             ray,
             v1: &v41[v40->m_TriData[0].m_IndexDummy & 0x1FF],
             v2: v50,
             v3: &v41[v42],
             u: &v49,
             v: &v51,
             t: (float *)&pTri1) )
      {
        v43 = v49;
        if ( v49 >= 0.0 )
        {
          v44 = v51;
          if ( v51 >= 0.0 && (float)(v49 + v51) <= 1.0 )
          {
            v45 = pTri1;
            if ( *(float *)&pTri1 > 0.0 && output->dist > *(float *)&pTri1 )
            {
              *pImpactTri = v40;
              output->u = v43;
              output->v = v44;
              LODWORD(output->dist) = v45;
            }
          }
        }
      }
      ++flU;
    }
    while ( flU <= *(int *)&v46[1520] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048280
// Name: protected: void CDispCollTree::AABBTree_TreeTrisRayTest(struct Ray_t const __near &,class Vector const __near &,int,class CBaseTrace __near *,bool,class CDispCollTri __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDispCollTree::AABBTree_TreeTrisRayTest(
        CDispCollTree *this@<ecx>,
        CDispCollTri *a2@<ebp>,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        int iNode,
        CBaseTrace *pTrace,
        bool bSide,
        CDispCollTri **pImpactTri)
{
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  float v13; // edx
  int v14; // edi
  __m128 v15; // xmm7
  __m128 v16; // xmm6
  int v17; // ecx
  CDispCollNode *v18; // eax
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm7
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  CDispCollLeaf *m_pMemory; // ecx
  int v30; // edi
  int v31; // eax
  CDispCollTri *v32; // ecx
  CDispCollTri *v33; // edi
  const Vector *v34; // ecx
  int v35; // edx
  int v36; // eax
  Vector *v37; // ecx
  double v38; // st7
  CDispCollTri *v39; // edi
  Vector *v40; // ecx
  int v41; // edx
  double v42; // st7
  _BYTE v43[1552]; // [esp-Ch] [ebp-64Ch] OVERLAPPED
  __m128 v44; // [esp+604h] [ebp-3Ch]
  Vector *v45; // [esp+628h] [ebp-18h]
  int v46; // [esp+62Ch] [ebp-14h]
  float v47; // [esp+630h] [ebp-10h]
  CDispCollTri *pTri1; // [esp+634h] [ebp-Ch]
  int listIndex; // [esp+638h] [ebp-8h]
  int retaddr; // [esp+640h] [ebp+0h]

  pTri1 = a2;
  listIndex = retaddr;
  *(__m128 *)&v43[96] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->x), (__m128)LODWORD(vecInvDelta->x), 0);
  *(__m128 *)&v43[112] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->y), (__m128)LODWORD(vecInvDelta->y), 0);
  *(__m128 *)&v43[128] = _mm_shuffle_ps((__m128)LODWORD(vecInvDelta->z), (__m128)LODWORD(vecInvDelta->z), 0);
  *(__m128 *)&v43[16] = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.y), (__m128)LODWORD(ray->m_Start.y), 0);
  v10 = 0;
  v10.m128_f32[0] = ray->m_Extents.x + 0.03125;
  *(__m128 *)&v43[48] = _mm_shuffle_ps(v10, v10, 0);
  v11 = 0;
  v11.m128_f32[0] = ray->m_Extents.y + 0.03125;
  *(__m128 *)&v43[64] = _mm_shuffle_ps(v11, v11, 0);
  v12 = 0;
  v13 = 0.0;
  v12.m128_f32[0] = ray->m_Extents.z + 0.03125;
  v14 = 0;
  v15 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.x), (__m128)LODWORD(ray->m_Start.x), 0);
  v16 = _mm_shuffle_ps((__m128)LODWORD(ray->m_Start.z), (__m128)LODWORD(ray->m_Start.z), 0);
  *(__m128 *)v43 = v15;
  *(__m128 *)&v43[32] = v16;
  *(__m128 *)&v43[80] = _mm_shuffle_ps(v12, v12, 0);
  *(_DWORD *)&v43[144] = iNode;
  *(_DWORD *)&v43[1520] = 0;
  while ( 1 )
  {
    v17 = *(_DWORD *)&v43[4 * LODWORD(v13) + 144];
    if ( v17 >= this->m_nodes.m_Size )
      break;
    v18 = &this->m_nodes.m_Memory.m_pMemory[v17];
    ++LODWORD(v13);
    v19 = _mm_mul_ps(
            _mm_add_ps(_mm_sub_ps(v18->m_maxs.y, *(__m128 *)&v43[16]), *(__m128 *)&v43[64]),
            *(__m128 *)&v43[112]);
    v20 = _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(v18->m_mins.x, v15), *(__m128 *)&v43[48]), *(__m128 *)&v43[96]);
    v21 = _mm_sub_ps(_mm_sub_ps(v18->m_mins.z, v16), *(__m128 *)&v43[80]);
    v22 = _mm_mul_ps(_mm_add_ps(_mm_sub_ps(v18->m_maxs.z, v16), *(__m128 *)&v43[80]), *(__m128 *)&v43[128]);
    v23 = _mm_mul_ps(
            _mm_sub_ps(_mm_sub_ps(v18->m_mins.y, *(__m128 *)&v43[16]), *(__m128 *)&v43[64]),
            *(__m128 *)&v43[112]);
    *(__m128 *)&v43[1536] = _mm_add_ps(_mm_sub_ps(v18->m_maxs.x, v15), *(__m128 *)&v43[48]);
    v24 = _mm_mul_ps(v21, *(__m128 *)&v43[128]);
    v25 = _mm_mul_ps(*(__m128 *)&v43[1536], *(__m128 *)&v43[96]);
    v44 = v19;
    v26 = _mm_movemask_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_max_ps(_mm_max_ps(_mm_min_ps(v20, v25), _mm_min_ps(v23, v19)), _mm_min_ps(v24, v22)),
                Four_Zeros),
              _mm_min_ps(
                _mm_min_ps(_mm_min_ps(_mm_max_ps(v20, v25), _mm_max_ps(v23, v19)), _mm_max_ps(v24, v22)),
                Four_Ones)));
    v47 = v13;
    if ( v26 != 0 )
    {
      v27 = 4 * v17 + 1;
      if ( (v26 & 1) != 0 )
      {
        *(_DWORD *)&v43[1520] = v14 + 1;
        *(_DWORD *)&v43[4 * *(_DWORD *)&v43[1520] + 144] = v27;
        v14 = *(_DWORD *)&v43[1520];
      }
      if ( (v26 & 2) != 0 )
      {
        *(_DWORD *)&v43[1520] = v14 + 1;
        *(_DWORD *)&v43[4 * *(_DWORD *)&v43[1520] + 144] = v27 + 1;
        v14 = *(_DWORD *)&v43[1520];
        v13 = v47;
      }
      if ( (v26 & 4) != 0 )
      {
        *(_DWORD *)&v43[1520] = v14 + 1;
        *(_DWORD *)&v43[4 * *(_DWORD *)&v43[1520] + 144] = v27 + 2;
        v14 = *(_DWORD *)&v43[1520];
        v13 = v47;
      }
      if ( (v26 & 8) != 0 )
      {
        *(_DWORD *)&v43[1520] = v14 + 1;
        *(_DWORD *)&v43[4 * *(_DWORD *)&v43[1520] + 144] = v27 + 3;
        v14 = *(_DWORD *)&v43[1520];
      }
    }
    if ( SLODWORD(v13) > v14 )
      break;
    v16 = *(__m128 *)&v43[32];
    v15 = *(__m128 *)v43;
  }
  v46 = LODWORD(v13);
  if ( SLODWORD(v13) <= v14 )
  {
    do
    {
      v28 = *(_DWORD *)&v43[4 * v46 + 144] - this->m_nodes.m_Size;
      m_pMemory = this->m_leaves.m_Memory.m_pMemory;
      v30 = m_pMemory[v28].m_tris[0];
      v31 = m_pMemory[v28].m_tris[1];
      v32 = this->m_aTris.m_Memory.m_pMemory;
      v33 = &v32[v30];
      v34 = (const Vector *)&v32[v31];
      v35 = v33->m_TriData[1].m_IndexDummy & 0x1FF;
      v36 = v33->m_TriData[2].m_IndexDummy & 0x1FF;
      v45 = (Vector *)v34;
      v37 = this->m_aVerts.m_Memory.m_pMemory;
      LODWORD(v47) = &v37[v36];
      v38 = IntersectRayWithTriangle(
              ray,
              v1: &v37[v33->m_TriData[0].m_IndexDummy & 0x1FF],
              v2: (const Vector *)LODWORD(v47),
              v3: &v37[v35],
              oneSided: bSide);
      v47 = v38;
      if ( v38 >= 0.0 && pTrace->fraction > v47 )
      {
        pTrace->fraction = v47;
        *pImpactTri = v33;
      }
      v39 = (CDispCollTri *)v45;
      v40 = this->m_aVerts.m_Memory.m_pMemory;
      v41 = HIWORD(v45->x) & 0x1FF;
      v45 = &v40[LOWORD(v45->y) & 0x1FF];
      v42 = IntersectRayWithTriangle(
              ray,
              v1: &v40[v39->m_TriData[0].m_IndexDummy & 0x1FF],
              v2: v45,
              v3: &v40[v41],
              oneSided: bSide);
      v47 = v42;
      if ( v42 >= 0.0 && pTrace->fraction > v47 )
      {
        pTrace->fraction = v47;
        *pImpactTri = v39;
      }
      ++v46;
    }
    while ( v46 <= *(int *)&v43[1520] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048630
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,class Vector const __near &,struct RayDispOutput_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        RayDispOutput_t *output)
{
  CDispCollTri *v5; // eax
  CDispCollTri *pImpactTri; // [esp+0h] [ebp-4h] BYREF
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  pImpactTri = (CDispCollTri *)this;
  if ( (this->m_nFlags & 8) != 0 || (this->m_nContents & 0x4081) == 0 )
    return 0;
  pImpactTri = nullptr;
  CDispCollTree::AABBTree_TreeTrisRayBarycentricTest(
    this,
    a2: COERCE_FLOAT(&savedregs),
    ray,
    vecInvDelta,
    iNode: 0,
    output,
    &pImpactTri);
  v5 = pImpactTri;
  if ( pImpactTri == nullptr )
    return 0;
  output->ndxVerts[0] = pImpactTri->m_TriData[0].m_IndexDummy & 0x1FF;
  output->ndxVerts[1] = v5->m_TriData[2].m_IndexDummy & 0x1FF;
  output->ndxVerts[2] = v5->m_TriData[1].m_IndexDummy & 0x1FF;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100486B0
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,class Vector const __near &,class CBaseTrace __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(
        CDispCollTree *this,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        CBaseTrace *pTrace,
        bool bSide)
{
  CDispCollTri *v6; // eax
  CDispCollTri *pImpactTri; // [esp+0h] [ebp-4h] BYREF
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  pImpactTri = (CDispCollTri *)this;
  if ( (this->m_nFlags & 8) != 0 || (this->m_nContents & 0x4081) == 0 )
    return 0;
  pImpactTri = nullptr;
  CDispCollTree::AABBTree_TreeTrisRayTest(
    this,
    a2: (CDispCollTri *)&savedregs,
    ray,
    vecInvDelta,
    iNode: 0,
    pTrace,
    bSide,
    &pImpactTri);
  v6 = pImpactTri;
  if ( pImpactTri == nullptr )
    return 0;
  pTrace->plane.normal.x = pImpactTri->m_vecNormal.x;
  pTrace->plane.normal.y = v6->m_vecNormal.y;
  pTrace->plane.normal.z = v6->m_vecNormal.z;
  pTrace->plane.dist = v6->m_flDist;
  pTrace->dispFlags = (*((_WORD *)v6 + 3) >> 6) & 0x1F;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100489D0
// Name: public: bool CDispCollTree::AABBTree_Ray(struct Ray_t const __near &,struct RayDispOutput_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::AABBTree_Ray(CDispCollTree *this, const Ray_t *ray, RayDispOutput_t *output)
{
  VectorAligned *p_m_Delta; // ebx
  float y; // xmm0_4
  float z; // xmm0_4
  Vector vecInvDelta; // [esp+10h] [ebp-Ch] BYREF

  p_m_Delta = &ray->m_Delta;
  if ( !IsBoxIntersectingRay(
          boxMin: &this->m_mins,
          boxMax: &this->m_maxs,
          origin: &ray->m_Start,
          vecDelta: &ray->m_Delta,
          flTolerance: 0.03125) )
    return 0;
  if ( p_m_Delta->x == 0.0 )
    vecInvDelta.x = 3.4028235e38;
  else
    vecInvDelta.x = 1.0 / p_m_Delta->x;
  y = ray->m_Delta.y;
  if ( y == 0.0 )
    vecInvDelta.y = 3.4028235e38;
  else
    vecInvDelta.y = 1.0 / y;
  z = ray->m_Delta.z;
  if ( z == 0.0 )
    vecInvDelta.z = 3.4028235e38;
  else
    vecInvDelta.z = 1.0 / z;
  return CDispCollTree::AABBTree_Ray(this, ray, &vecInvDelta, output);
}

//------------------------------------------------------------------------------
// Address: 0x10048AA0
// Name: public: void CUtlHash<struct DispCollPlaneIndex_t,class CPlaneIndexHashFuncs,class CPlaneIndexHashFuncs>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(
        CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs> *this)
{
  int v1; // edi
  int m_Size; // ebx
  CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int> > *v3; // esi
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs> *v4; // [esp+0h] [ebp-4h]

  v4 = this;
  if ( this->m_Buckets.m_Size > 0 )
  {
    v1 = 0;
    m_Size = this->m_Buckets.m_Size;
    do
    {
      v3 = &this->m_Buckets.m_Memory.m_pMemory[v1];
      v3->m_Size = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      ++v1;
      --m_Size;
      v3->m_pElements = v3->m_Memory.m_pMemory;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048B00
// Name: protected: void CDispCollTree::AABBTree_CreateLeafs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::AABBTree_CreateLeafs(CDispCollTree *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // edx
  int v5; // eax
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // ebx
  int v12; // ecx
  int v13; // edx
  __int16 v14; // dx
  CDispVector<CDispCollLeaf> *p_m_leaves; // [esp+Ch] [ebp-14h]
  int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  int iHgt; // [esp+1Ch] [ebp-4h]

  v2 = 0;
  p_m_leaves = &this->m_leaves;
  v3 = (1 << this->m_nPower) * (1 << this->m_nPower);
  this->m_leaves.m_Size = 0;
  CUtlVector<CDispCollLeaf,CUtlMemoryAligned<CDispCollLeaf,16>>::InsertMultipleBefore(
    this: &this->m_leaves,
    elem: 0,
    num: v3);
  v4 = 1 << (2 * this->m_nPower + 2);
  this->m_nodes.m_Size = 0;
  CUtlVector<CDispCollNode,CUtlMemoryAligned<CDispCollNode,16>>::InsertMultipleBefore(
    this: &this->m_nodes,
    elem: 0,
    num: v4 / 3 - v3);
  v5 = 1 << this->m_nPower;
  iHgt = 0;
  v17 = v5;
  if ( v5 > 0 )
  {
    v16 = 0;
    do
    {
      v6 = 0;
      if ( v5 > 0 )
      {
        v18 = v2;
        do
        {
          v7 = iHgt;
          v8 = 0;
          v9 = 0;
          v10 = v6;
          if ( v6 != 0 )
          {
            do
            {
              v11 = (v10 & 1) << v9;
              v9 += 2;
              v8 |= v11;
              v10 >>= 1;
            }
            while ( v10 != 0 );
            v2 = v18;
          }
          v12 = 1;
          if ( iHgt != 0 )
          {
            do
            {
              v13 = (v7 & 1) << v12;
              v12 += 2;
              v8 |= v13;
              v7 >>= 1;
            }
            while ( v7 != 0 );
          }
          p_m_leaves->m_Memory.m_pMemory[v8].m_tris[0] = v2;
          v14 = v2 + 1;
          ++v6;
          v2 += 2;
          p_m_leaves->m_Memory.m_pMemory[v8].m_tris[1] = v14;
          v18 = v2;
        }
        while ( v6 < v17 );
        v5 = v17;
      }
      v2 = 2 * v5 + v16;
      ++iHgt;
      v16 = v2;
    }
    while ( iHgt < v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048C10
// Name: public: CDispCollTree::CDispCollTree(void)
// Source: json
//------------------------------------------------------------------------------
CDispCollTree *__thiscall CDispCollTree::CDispCollTree(CDispCollTree *this)
{
  Vector *m_pMemory; // eax
  CDispCollTri *v3; // eax

  this->__vftable = (CDispCollTree_vtbl *)&CDispCollTree::`vftable';
  this->m_aVerts.m_Memory.m_pMemory = nullptr;
  this->m_aVerts.m_Memory.m_nAllocationCount = 0;
  this->m_aVerts.m_Memory.m_nGrowSize = 0;
  this->m_aVerts.m_pElements = nullptr;
  this->m_aTris.m_Memory.m_pMemory = nullptr;
  this->m_aTris.m_Memory.m_nAllocationCount = 0;
  this->m_aTris.m_Memory.m_nGrowSize = 0;
  this->m_aTris.m_Size = 0;
  this->m_aTris.m_pElements = nullptr;
  this->m_nodes.m_Memory.m_pMemory = nullptr;
  this->m_nodes.m_Memory.m_nAllocationCount = 0;
  this->m_nodes.m_Memory.m_nGrowSize = 0;
  this->m_nodes.m_Size = 0;
  this->m_nodes.m_pElements = nullptr;
  this->m_leaves.m_Memory.m_pMemory = nullptr;
  this->m_leaves.m_Memory.m_nAllocationCount = 0;
  this->m_leaves.m_Memory.m_nGrowSize = 0;
  this->m_leaves.m_Size = 0;
  this->m_leaves.m_pElements = nullptr;
  this->m_aTrisCache.m_Memory.m_pMemory = nullptr;
  this->m_aTrisCache.m_Memory.m_nAllocationCount = 0;
  this->m_aTrisCache.m_Memory.m_nGrowSize = 0;
  this->m_aTrisCache.m_Size = 0;
  this->m_aTrisCache.m_pElements = nullptr;
  this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
  this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
  this->m_aEdgePlanes.m_Memory.m_nGrowSize = 0;
  this->m_aEdgePlanes.m_Size = 0;
  this->m_aEdgePlanes.m_pElements = nullptr;
  this->m_nPower = 0;
  this->m_nFlags = 0;
  this->m_vecSurfPoints[0].x = 0.0;
  this->m_vecSurfPoints[1].x = 0.0;
  this->m_vecSurfPoints[0].y = 0.0;
  this->m_vecSurfPoints[0].z = 0.0;
  this->m_vecSurfPoints[1].y = 0.0;
  this->m_vecSurfPoints[1].z = 0.0;
  this->m_vecSurfPoints[2].x = 0.0;
  this->m_vecSurfPoints[2].y = 0.0;
  this->m_vecSurfPoints[2].z = 0.0;
  this->m_vecSurfPoints[3].x = 0.0;
  this->m_vecSurfPoints[3].y = 0.0;
  this->m_vecSurfPoints[3].z = 0.0;
  this->m_nContents = -1;
  *(_DWORD *)this->m_nSurfaceProps = 0;
  this->m_vecStabDir.x = 0.0;
  this->m_vecStabDir.y = 0.0;
  this->m_vecStabDir.z = 0.0;
  this->m_mins.x = 3.4028235e38;
  this->m_mins.y = 3.4028235e38;
  this->m_mins.z = 3.4028235e38;
  this->m_maxs.x = -3.4028235e38;
  this->m_maxs.y = -3.4028235e38;
  this->m_maxs.z = -3.4028235e38;
  this->m_iCounter = 0;
  this->m_aVerts.m_Size = 0;
  if ( this->m_aVerts.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pMemory & 0xFFFFFFFC) - 4));
      this->m_aVerts.m_Memory.m_pMemory = nullptr;
    }
    this->m_aVerts.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aVerts.m_pElements = this->m_aVerts.m_Memory.m_pMemory;
  this->m_aTris.m_Size = 0;
  if ( this->m_aTris.m_Memory.m_nGrowSize >= 0 )
  {
    v3 = this->m_aTris.m_Memory.m_pMemory;
    if ( v3 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)v3 & 0xFFFFFFFC) - 4));
      this->m_aTris.m_Memory.m_pMemory = nullptr;
    }
    this->m_aTris.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aTris.m_pElements = this->m_aTris.m_Memory.m_pMemory;
  this->m_aEdgePlanes.m_Size = 0;
  if ( this->m_aEdgePlanes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aEdgePlanes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aEdgePlanes.m_Memory.m_pMemory);
      this->m_aEdgePlanes.m_Memory.m_pMemory = nullptr;
    }
    this->m_aEdgePlanes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aEdgePlanes.m_pElements = this->m_aEdgePlanes.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048E10
// Name: protected: void CDispCollTree::AABBTree_CopyDispData(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCollTree::AABBTree_CopyDispData(CDispCollTree *this, CCoreDispInfo *pDisp)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  int v10; // ebx
  int v11; // ebx
  int m_nAllocationCount; // eax
  Vector *m_pMemory; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // ebx
  int v18; // eax
  CDispCollLeaf *v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  CDispCollNode *v24; // edx
  int v25; // ecx
  int v26; // ebx
  int v27; // edx
  CoreDispVert_t *m_pVerts; // ecx
  double x; // st7
  Vector *v30; // eax
  int p_m_Vert; // ecx
  int v32; // ebx
  unsigned __int16 iVerts[4]; // [esp+Ch] [ebp-Ch] BYREF
  int iTri; // [esp+14h] [ebp-4h]
  int numNodes; // [esp+20h] [ebp+8h]
  int numNodesa; // [esp+20h] [ebp+8h]
  int numNodesb; // [esp+20h] [ebp+8h]

  this->m_nPower = pDisp->m_Power;
  this->m_nContents = pDisp->m_Surf.m_Contents;
  v4 = pDisp->m_Surf.m_Points[3].y - pDisp->m_Surf.m_Points[0].y;
  v5 = pDisp->m_Surf.m_Points[3].z - pDisp->m_Surf.m_Points[0].z;
  v6 = pDisp->m_Surf.m_Points[1].y - pDisp->m_Surf.m_Points[0].y;
  v7 = pDisp->m_Surf.m_Points[1].z - pDisp->m_Surf.m_Points[0].z;
  v8 = pDisp->m_Surf.m_Points[1].x - pDisp->m_Surf.m_Points[0].x;
  v9 = pDisp->m_Surf.m_Points[3].x - pDisp->m_Surf.m_Points[0].x;
  this->m_vecStabDir.x = (float)(v4 * v7) - (float)(v5 * v6);
  this->m_vecStabDir.y = (float)(v5 * v8) - (float)(v9 * v7);
  this->m_vecStabDir.z = (float)(v9 * v6) - (float)(v4 * v8);
  VectorNormalize(vec: &this->m_vecStabDir);
  qmemcpy(this->m_vecSurfPoints, pDisp->m_Surf.m_Points, sizeof(this->m_vecSurfPoints));
  v10 = 1 << this->m_nPower;
  this->m_aVerts.m_Size = 0;
  v11 = (v10 + 1) * (v10 + 1);
  if ( v11 != 0 )
  {
    m_nAllocationCount = this->m_aVerts.m_Memory.m_nAllocationCount;
    if ( v11 > m_nAllocationCount )
      CUtlMemoryAligned<Vector,16>::Grow(this: &this->m_aVerts.m_Memory, num: v11 - m_nAllocationCount);
    this->m_aVerts.m_Size += v11;
    m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
    v14 = this->m_aVerts.m_Size - v11;
    this->m_aVerts.m_pElements = m_pMemory;
    if ( v14 > 0 && v11 > 0 )
      _V_memmove(dest: &m_pMemory[v11], src: m_pMemory, count: 12 * v14);
  }
  v15 = 1 << this->m_nPower;
  this->m_aTris.m_Size = 0;
  CUtlVector<CDispCollTri,CUtlMemoryAligned<CDispCollTri,16>>::InsertMultipleBefore(
    this: &this->m_aTris,
    elem: 0,
    num: 2 * v15 * v15);
  v16 = 1 << this->m_nPower;
  this->m_leaves.m_Size = 0;
  v17 = v16 * v16;
  if ( v17 != 0 )
  {
    v18 = this->m_leaves.m_Memory.m_nAllocationCount;
    if ( v17 > v18 )
      CUtlMemoryAligned<CDispCollLeaf,16>::Grow(this: &this->m_leaves.m_Memory, num: v17 - v18);
    this->m_leaves.m_Size += v17;
    v19 = this->m_leaves.m_Memory.m_pMemory;
    v20 = this->m_leaves.m_Size - v17;
    this->m_leaves.m_pElements = v19;
    if ( v20 > 0 && v17 > 0 )
      _V_memmove(dest: &v19[v17], src: v19, count: 4 * v20);
  }
  v21 = 2 * this->m_nPower + 2;
  this->m_nodes.m_Size = 0;
  v22 = (1 << v21) / 3 - v17;
  numNodes = v22;
  if ( v22 != 0 )
  {
    v23 = this->m_nodes.m_Memory.m_nAllocationCount;
    if ( v22 > v23 )
    {
      CUtlMemoryAligned<CDispCollNode,16>::Grow(this: &this->m_nodes.m_Memory, num: v22 - v23);
      v22 = numNodes;
    }
    this->m_nodes.m_Size += v22;
    v24 = this->m_nodes.m_Memory.m_pMemory;
    v25 = this->m_nodes.m_Size - v22;
    this->m_nodes.m_pElements = v24;
    if ( v25 > 0 && v22 > 0 )
      _V_memmove(dest: &v24[v22], src: v24, count: 96 * v25);
  }
  v26 = 0;
  v27 = 0;
  this->m_nSize = 4
                * (this->m_leaves.m_Size
                 + 3
                 * (((1 << this->m_nPower) + 1) * ((1 << this->m_nPower) + 1)
                  + 4 * ((1 << this->m_nPower) * (1 << this->m_nPower) + 2 * this->m_nodes.m_Size)
                  + 171));
  if ( this->m_aVerts.m_Size > 0 )
  {
    numNodesa = 0;
    do
    {
      m_pVerts = pDisp->m_pVerts;
      x = m_pVerts[v26].m_Vert.x;
      v30 = &this->m_aVerts.m_Memory.m_pMemory[numNodesa++];
      p_m_Vert = (int)&m_pVerts[v26].m_Vert;
      v30->x = x;
      ++v27;
      v30->y = *(float *)(p_m_Vert + 4);
      ++v26;
      v30->z = *(float *)(p_m_Vert + 8);
    }
    while ( v27 < this->m_aVerts.m_Size );
  }
  v32 = 0;
  iTri = 0;
  if ( this->m_aTris.m_Size > 0 )
  {
    numNodesb = 0;
    do
    {
      CCoreDispInfo::GetTriIndices(this: pDisp, iTri, v1: iVerts, v2: &iVerts[1], v3: &iVerts[2]);
      this->m_aTris.m_Memory.m_pMemory[v32].m_TriData[0].m_IndexDummy ^= (iVerts[0]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v32].m_TriData[0].m_IndexDummy)
                                                                       & 0x1FF;
      this->m_aTris.m_Memory.m_pMemory[v32].m_TriData[1].m_IndexDummy ^= (iVerts[1]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v32].m_TriData[1].m_IndexDummy)
                                                                       & 0x1FF;
      this->m_aTris.m_Memory.m_pMemory[v32].m_TriData[2].m_IndexDummy ^= (iVerts[2]
                                                                        ^ this->m_aTris.m_Memory.m_pMemory[v32].m_TriData[2].m_IndexDummy)
                                                                       & 0x1FF;
      *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v32] + 3) ^= (*((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v32] + 3)
                                                               ^ (pDisp->m_pTris[iTri].m_uiTags << 6))
                                                              & 0x7C0;
      if ( (float)((float)(pDisp->m_pVerts[this->m_aTris.m_Memory.m_pMemory[numNodesb].m_TriData[0].m_IndexDummy & 0x1FF].m_Alpha
                         + pDisp->m_pVerts[this->m_aTris.m_Memory.m_pMemory[numNodesb].m_TriData[1].m_IndexDummy & 0x1FF].m_Alpha)
                 + pDisp->m_pVerts[this->m_aTris.m_Memory.m_pMemory[numNodesb].m_TriData[2].m_IndexDummy & 0x1FF].m_Alpha) <= 382.5 )
        *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v32] + 3) |= 0x200u;
      else
        *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v32] + 3) |= 0x400u;
      *((_WORD *)&this->m_aTris.m_Memory.m_pMemory[v32] + 3) |= 0x40u;
      CDispCollTri::CalcPlane(this: &this->m_aTris.m_Memory.m_pMemory[v32], m_aVerts: &this->m_aVerts);
      CDispCollTri::FindMinMax(this: &this->m_aTris.m_Memory.m_pMemory[v32], m_aVerts: &this->m_aVerts);
      ++numNodesb;
      ++v32;
      ++iTri;
    }
    while ( iTri < this->m_aTris.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049270
// Name: public: virtual bool CDispCollTree::Create(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispCollTree::Create(CDispCollTree *this, CCoreDispInfo *pDisp)
{
  this->m_nFlags = pDisp->m_Surf.m_Flags;
  CDispCollTree::AABBTree_CopyDispData(this, pDisp);
  CDispCollTree::AABBTree_CreateLeafs(this);
  if ( this->m_aVerts.m_Size != 0 && this->m_nodes.m_Size != 0 )
  {
    CDispCollTree::AABBTree_GenerateBoxes_r(this, nodeIndex: 0, pMins: &this->m_mins, pMaxs: &this->m_maxs);
    this->m_mins.x = this->m_mins.x - 1.0;
    this->m_maxs.x = this->m_maxs.x + 1.0;
    this->m_mins.y = this->m_mins.y - 1.0;
    this->m_maxs.y = this->m_maxs.y + 1.0;
    this->m_mins.z = this->m_mins.z - 1.0;
    this->m_maxs.z = this->m_maxs.z + 1.0;
  }
  return 1;
}

} // namespace vrad_dll
