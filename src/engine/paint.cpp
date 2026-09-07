// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/paint.cpp
// Functions: 61
// ============================================================

#include "engine\paint.h"

//------------------------------------------------------------------------------
// Address: 0x100D9510
// Name: public: void ICallQueue::QueueCall<class IMDLCache __near *,class IMDLCache,void>(class IMDLCache __near *,void (IMDLCache::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<IMDLCache *,IMDLCache,void>(
        ICallQueue *this,
        IMDLCache *pObject,
        void (__thiscall *pfnProxied)(IMDLCache *this))
{
  CFunctor *v4; // eax

  v4 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMDLCache *,void (__thiscall IMDLCache::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMDLCache *,void (__thiscall IMDLCache::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4[2].m_nUserID = (unsigned int)pObject;
    this->QueueFunctorInternal(this, a2: v4);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0170
// Name: public: CUtlMemoryFixedGrowable<struct LightingState_t,256,int>::CUtlMemoryFixedGrowable<struct LightingState_t,256,int>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryFixedGrowable<LightingState_t,256,int> *__thiscall CUtlMemoryFixedGrowable<LightingState_t,256,int>::CUtlMemoryFixedGrowable<LightingState_t,256,int>(
        CUtlMemoryFixedGrowable<LightingState_t,256,int> *this,
        int nGrowSize,
        int nInitSize)
{
  char *m_pFixedMemory; // edi
  int v4; // ebx
  float *p_z; // esi

  m_pFixedMemory = (char *)this->m_pFixedMemory;
  this->m_pMemory = this->m_pFixedMemory;
  this->m_nAllocationCount = 256;
  this->m_nGrowSize = -1;
  v4 = 255;
  p_z = &this->m_pFixedMemory[0].r_boxcolor[1].z;
  do
  {
    `vector constructor iterator'(
      __t: m_pFixedMemory,
      __s: 0xCu,
      __n: 6,
      __f: (void *(__thiscall *)(void *))Vector2D::Vector2D);
    *(_DWORD *)m_pFixedMemory = 0;
    *(p_z - 2) = 0.0;
    *(p_z - 4) = 0.0;
    *(p_z - 3) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    *((_QWORD *)p_z + 6) = 0;
    m_pFixedMemory += 92;
    p_z += 23;
    --v4;
  }
  while ( v4 >= 0 );
  this->m_nMallocGrowSize = nGrowSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E0DB0
// Name: public: void ICallQueue::QueueCall<class CModelRender __near *,class CModelRender,void,int,struct memhandle_t__ __near * __near *,int,struct memhandle_t__ __near * __near *>(class CModelRender __near *,void (CModelRender::*)(int,struct memhandle_t__ __near * __near *),int const __near &,struct memhandle_t__ __near * __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CModelRender *,CModelRender,void,int,memhandle_t__ * *,int,memhandle_t__ * *>(
        ICallQueue *this,
        CFunctor_vtbl *pObject,
        void (__thiscall *__ptr64 pfnProxied)(CModelRender *this, int, memhandle_t__ **),
        CFunctor_vtbl **arg1,
        memhandle_t__ **const *arg2)
{
  CFunctor *v6; // eax

  v6 = (CFunctor *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v6 != nullptr )
  {
    v6[1].m_nUserID = 1;
    v6->__vftable = (CFunctor_vtbl *)&CMemberFunctor2<CModelRender *,void (__thiscall CModelRender::*)(int,memhandle_t__ * *),int,memhandle_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v6[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor2<CModelRender *,void (__thiscall CModelRender::*)(int,memhandle_t__ * *),int,memhandle_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v6[2] = (CFunctor)pfnProxied;
    v6[3].__vftable = pObject;
    v6[4].__vftable = *arg1;
    v6[4].m_nUserID = (unsigned int)*arg2;
    this->QueueFunctorInternal(this, a2: v6);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0E20
// Name: public: void ICallQueue::QueueCall<class CModelRender __near *,class CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>,int,struct memhandle_t__ __near *,struct memhandle_t__ __near *>(class CModelRender __near *,int (CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>::*)(struct memhandle_t__ __near *),struct memhandle_t__ __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CModelRender *,CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,int,memhandle_t__ *,memhandle_t__ *>(
        ICallQueue *this,
        CModelRender *pObject,
        int (__thiscall *pfnProxied)(CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *> *this, memhandle_t__ *),
        CFunctor_vtbl **arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    v5[3].__vftable = *arg1;
    this->QueueFunctorInternal(this, a2: v5);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102B20
// Name: public: void ICallQueue::QueueCall<void,struct msurface2_t __near *,class Vector,struct msurface2_t __near *,class Vector>(void (*)(struct msurface2_t __near *,class Vector),struct msurface2_t __near * const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,msurface2_t *,Vector,msurface2_t *,Vector>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(msurface2_t *, Vector),
        msurface2_t *const *arg1,
        const Vector *arg2)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5->__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(msurface2_t *,Vector),msurface2_t *,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(msurface2_t *,Vector),msurface2_t *,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].m_nUserID = (unsigned int)*arg1;
    *(Vector *)&v5[3].__vftable = *arg2;
    this->QueueFunctorInternal(this, a2: v5);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102B90
// Name: public: void ICallQueue::QueueCall<void,bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float,bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float>(void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool const __near &,int const __near &,class Vector const __near &,int const __near &,struct decal_t __near * __near * const __near &,int const __near &,int const __near &,int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,bool,int,Vector,int,decal_t * *,int,int,int,float,bool,int,Vector,int,decal_t * *,int,int,int,float>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(bool, int, Vector, int, decal_t **, int, int, int, float),
        const bool *arg1,
        const int *arg2,
        const Vector *arg3,
        const int *arg4,
        decal_t **const *arg5,
        const int *arg6,
        const int *arg7,
        const int *arg8,
        const float *arg9)
{
  CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *v12; // eax
  CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *v13; // eax

  v12 = (CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v12 != nullptr )
  {
    v13 = CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>(
            this: v12,
            pfnProxied,
            arg1,
            arg2,
            arg3,
            arg4,
            arg5,
            arg6,
            arg7,
            arg8,
            arg9);
    this->QueueFunctorInternal(this, a2: v13);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116090
// Name: public: void ICallQueue::QueueCall<void,int,struct BrushArrayInstanceData_t const __near *,int,int,struct BrushArrayInstanceData_t const __near *,int>(void (*)(int,struct BrushArrayInstanceData_t const __near *,int),int const __near &,struct BrushArrayInstanceData_t const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,int,BrushArrayInstanceData_t const *,int,int,BrushArrayInstanceData_t const *,int>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(int, const BrushArrayInstanceData_t *, int),
        unsigned int *arg1,
        CFunctor_vtbl **arg2,
        unsigned int *arg3)
{
  CFunctor *v6; // eax

  v6 = (CFunctor *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v6 != nullptr )
  {
    v6[1].m_nUserID = 1;
    v6[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v6->__vftable = (CFunctor_vtbl *)&CFunctor3<void (__cdecl *)(int,BrushArrayInstanceData_t const *,int),int,BrushArrayInstanceData_t const *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v6[1].__vftable = (CFunctor_vtbl *)&CFunctor3<void (__cdecl *)(int,BrushArrayInstanceData_t const *,int),int,BrushArrayInstanceData_t const *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v6[2].m_nUserID = *arg1;
    v6[3].__vftable = *arg2;
    v6[3].m_nUserID = *arg3;
    this->QueueFunctorInternal(this, a2: v6);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8650
// Name: void R_UpdatePaintmapRect(int,unsigned char __near *,int,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_UpdatePaintmapRect(int paintmap, unsigned __int8 *pPaintData, int numRects, Rect_t *pRects)
{
  materials->UpdatePaintmap(this: materials, a2: paintmap, a3: pPaintData, a4: numRects, a5: pRects);
}

//------------------------------------------------------------------------------
// Address: 0x101C8680
// Name: public: virtual unsigned char __near * CPaintmapDataManager::GetPaintmapData(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CPaintmapDataManager::GetPaintmapData(CPaintmapDataManager *this, int paintmap)
{
  if ( paintmap < 0 || paintmap >= this->m_iPaintmaps )
    return nullptr;
  else
    return this->m_pPaintTextureDataArray[paintmap].m_backbuffer;
}

//------------------------------------------------------------------------------
// Address: 0x101C86B0
// Name: void DecodeDataRLE(unsigned int const __near *,unsigned int,struct msurface2_t __near *,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeDataRLE(
        const unsigned int *pRLEStart,
        unsigned int rleCount,
        msurface2_t *surfID,
        unsigned int *pOutput)
{
  const unsigned int *v4; // edx
  const unsigned int *v5; // ecx
  int v7; // eax
  signed int v8; // ebx
  int v9; // eax
  const unsigned int *pEndOfData; // [esp+8h] [ebp+8h]

  v4 = pRLEStart;
  v5 = &pRLEStart[rleCount];
  pEndOfData = v5;
  while ( v4 < v5 )
  {
    v7 = *v4++;
    if ( v7 >= 0 )
    {
      if ( v7 > 0 )
      {
        do
        {
          *pOutput++ = *v4++;
          --v7;
        }
        while ( v7 != 0 );
      }
    }
    else
    {
      v8 = -v7;
      v9 = *v4++;
      if ( v8 > 0 )
      {
        memset32(pOutput, v9, v8);
        v5 = pEndOfData;
        pOutput += v8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8710
// Name: class Vector FindClosestPointToTriangle(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl FindClosestPointToTriangle(
        Vector *result,
        const Vector *p,
        const Vector *a,
        const Vector *b,
        const Vector *c)
{
  float x; // xmm1_4
  float z; // xmm4_4
  float v10; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float y; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v19; // edx
  float v20; // ecx
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // ecx
  float v24; // edx
  float v25; // edx
  float v26; // ecx
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm5_4
  float v36; // xmm2_4
  float v37; // [esp+10h] [ebp-60h]
  float bc; // [esp+18h] [ebp-58h]
  float bc_4; // [esp+1Ch] [ebp-54h]
  float bc_8; // [esp+20h] [ebp-50h]
  float ab; // [esp+24h] [ebp-4Ch]
  float ab_4; // [esp+28h] [ebp-48h]
  float ab_8; // [esp+2Ch] [ebp-44h]
  float n; // [esp+30h] [ebp-40h]
  float n_4; // [esp+34h] [ebp-3Ch]
  float n_8; // [esp+38h] [ebp-38h]
  float ac; // [esp+3Ch] [ebp-34h]
  float ac_4; // [esp+40h] [ebp-30h]
  float ac_8; // [esp+44h] [ebp-2Ch]
  float tpC; // [esp+48h] [ebp-28h]
  float v51; // [esp+4Ch] [ebp-24h]
  float tpA; // [esp+54h] [ebp-1Ch]
  float tpAa; // [esp+54h] [ebp-1Ch]
  float projACdenom; // [esp+58h] [ebp-18h]
  float projACnom; // [esp+5Ch] [ebp-14h]
  float v56; // [esp+60h] [ebp-10h]
  float v57; // [esp+60h] [ebp-10h]
  float projBCnom; // [esp+64h] [ebp-Ch]
  float projABdenom; // [esp+68h] [ebp-8h]
  float projABdenoma; // [esp+68h] [ebp-8h]
  float projABnom; // [esp+6Ch] [ebp-4h]
  float projABnoma; // [esp+6Ch] [ebp-4h]
  float pa; // [esp+7Ch] [ebp+Ch]
  float ad; // [esp+80h] [ebp+10h]
  float aa; // [esp+80h] [ebp+10h]
  float bb; // [esp+84h] [ebp+14h]
  float ba; // [esp+84h] [ebp+14h]
  float cb; // [esp+88h] [ebp+18h]
  float cc; // [esp+88h] [ebp+18h]
  float ca; // [esp+88h] [ebp+18h]

  x = b->x;
  z = b->z;
  v10 = c->z - z;
  v12 = a->z;
  v13 = a->x;
  ab_8 = z - v12;
  v14 = c->x;
  ac = c->x - a->x;
  ab = b->x - a->x;
  y = a->y;
  ac_4 = c->y - y;
  ac_8 = c->z - v12;
  ab_4 = b->y - y;
  bc_8 = v10;
  bc = c->x - b->x;
  bc_4 = c->y - b->y;
  cb = p->x - a->x;
  v16 = p->y;
  ad = p->z;
  v56 = p->x - b->x;
  projABnom = (float)((float)((float)(v16 - y) * ab_4) + (float)(cb * (float)(b->x - v13)))
            + (float)((float)(ad - v12) * ab_8);
  projABdenom = (float)((float)(v56 * (float)(v13 - b->x)) + (float)((float)(v16 - b->y) * (float)(y - b->y)))
              + (float)((float)(ad - b->z) * (float)(v12 - b->z));
  v37 = y - c->y;
  projACnom = (float)((float)((float)(v16 - y) * ac_4) + (float)(cb * ac)) + (float)((float)(ad - v12) * ac_8);
  v17 = p->x - v14;
  projACdenom = (float)((float)(v17 * (float)(v13 - v14)) + (float)((float)(v16 - c->y) * v37))
              + (float)((float)(ad - c->z) * (float)(v12 - c->z));
  if ( projABnom <= 0.0 && projACnom <= 0.0 )
  {
    v19 = a->y;
    result->x = a->x;
    v20 = a->z;
    result->y = v19;
    result->z = v20;
    return result;
  }
  bb = b->y;
  v21 = p->y;
  cc = p->z;
  projBCnom = (float)((float)((float)(v21 - bb) * bc_4) + (float)(v56 * bc)) + (float)((float)(cc - b->z) * bc_8);
  v22 = (float)((float)(v17 * (float)(x - v14)) + (float)((float)(v21 - c->y) * (float)(bb - c->y)))
      + (float)((float)(cc - c->z) * (float)(b->z - c->z));
  if ( projABdenom <= 0.0 && projBCnom <= 0.0 )
  {
    result->x = b->x;
    v23 = b->y;
    v24 = b->z;
    result->y = v23;
    result->z = v24;
    return result;
  }
  if ( projACdenom <= 0.0 && v22 <= 0.0 )
  {
    result->x = c->x;
    v25 = c->y;
    v26 = c->z;
    result->y = v25;
    result->z = v26;
    return result;
  }
  n = (float)(ac_8 * ab_4) - (float)(ac_4 * ab_8);
  n_4 = (float)(ab_8 * ac) - (float)(ac_8 * ab);
  n_8 = (float)(ac_4 * ab) - (float)(ac * ab_4);
  tpA = x - p->x;
  v57 = v13 - p->x;
  ba = a->y;
  aa = a->z;
  pa = b->z;
  ca = b->y;
  tpC = (float)((float)((float)((float)((float)(ba - p->y) * (float)(pa - p->z))
                              - (float)((float)(aa - p->z) * (float)(ca - p->y)))
                      * n)
              + (float)((float)((float)((float)(aa - p->z) * tpA) - (float)((float)(pa - p->z) * v57)) * n_4))
      + (float)((float)((float)((float)(ca - p->y) * v57) - (float)((float)(ba - p->y) * tpA)) * n_8);
  if ( tpC <= 0.0 && projABnom >= 0.0 && projABdenom >= 0.0 )
  {
    v27 = projABnom / (float)(projABdenom + projABnom);
    v28 = ab_4 * v27;
    v29 = ab_8 * v27;
    v30 = v13 + (float)(ab * v27);
LABEL_14:
    result->x = v30;
    result->y = ba + v28;
    result->z = aa + v29;
    return result;
  }
  v51 = v14 - p->x;
  projABnoma = c->z;
  projABdenoma = c->y;
  tpAa = (float)((float)((float)((float)((float)(ca - p->y) * (float)(projABnoma - p->z))
                               - (float)((float)(pa - p->z) * (float)(projABdenoma - p->y)))
                       * n)
               + (float)((float)((float)((float)(pa - p->z) * v51) - (float)((float)(projABnoma - p->z) * tpA)) * n_4))
       + (float)((float)((float)((float)(projABdenoma - p->y) * tpA) - (float)((float)(ca - p->y) * v51)) * n_8);
  if ( tpAa > 0.0 || projBCnom < 0.0 || v22 < 0.0 )
  {
    v32 = (float)((float)((float)((float)((float)(projABdenoma - p->y) * (float)(aa - p->z))
                                - (float)((float)(projABnoma - p->z) * (float)(ba - p->y)))
                        * n)
                + (float)((float)((float)((float)(projABnoma - p->z) * v57) - (float)((float)(aa - p->z) * v51)) * n_4))
        + (float)((float)((float)((float)(ba - p->y) * v51) - (float)((float)(projABdenoma - p->y) * v57)) * n_8);
    if ( v32 <= 0.0 && projACnom >= 0.0 && projACdenom >= 0.0 )
    {
      v33 = projACnom / (float)(projACdenom + projACnom);
      v28 = ac_4 * v33;
      v29 = ac_8 * v33;
      v30 = v13 + (float)(v33 * ac);
      goto LABEL_14;
    }
    v34 = 1.0 / (float)((float)(v32 + tpAa) + tpC);
    v35 = v32 * v34;
    v36 = (float)(1.0 - (float)(tpAa * v34)) - v35;
    result->x = (float)((float)(v13 * (float)(tpAa * v34)) + (float)(x * v35)) + (float)(v14 * v36);
    result->y = (float)((float)(ba * (float)(tpAa * v34)) + (float)(ca * v35)) + (float)(projABdenoma * v36);
    result->z = (float)((float)(aa * (float)(tpAa * v34)) + (float)(v35 * pa)) + (float)(projABnoma * v36);
    return result;
  }
  else
  {
    v31 = projBCnom / (float)(v22 + projBCnom);
    result->y = ca + (float)(bc_4 * v31);
    result->x = x + (float)(bc * v31);
    result->z = pa + (float)(bc_8 * v31);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8E40
// Name: bool IsSurfaceInFrontOfPlane(struct msurface2_t __near *,class VPlane const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsSurfaceInFrontOfPlane(msurface2_t *surfID, const VPlane *plane)
{
  cplane_t *eax1; // eax
  int firstvertindex; // eax
  unsigned __int16 *vertindices; // ecx
  mvertex_t *vertexes; // edx
  float *p_x; // edi
  float x; // ebx
  mvertex_t *v9; // edi
  int v10; // eax
  float trianglePlane; // [esp+20h] [ebp-28h]
  float v2; // [esp+3Ch] [ebp-Ch]
  float v2_4; // [esp+40h] [ebp-8h]
  float v2_8; // [esp+44h] [ebp-4h]
  Vector normal; // 0:^14.12

  eax1 = surfID->plane;
  trianglePlane = eax1->dist;
  normal = eax1->normal;
  if ( AlmostEqual(
         a: (float)((float)(plane->m_Normal.y * normal.y) + (float)(plane->m_Normal.x * eax1->normal.x))
       + (float)(plane->m_Normal.z * normal.z),
         b: 1.0,
         maxUlps: 10)
    && AlmostEqual(a: plane->m_Dist, b: trianglePlane, maxUlps: 10) )
  {
    return true;
  }
  if ( HIBYTE(surfID->flags) < 3u )
    return false;
  firstvertindex = surfID->firstvertindex;
  vertindices = host_state.worldbrush->vertindices;
  vertexes = host_state.worldbrush->vertexes;
  p_x = &vertexes[vertindices[firstvertindex]].position.x;
  v2 = *p_x;
  v2_8 = p_x[2];
  v2_4 = p_x[1];
  x = vertexes[vertindices[firstvertindex + 1]].position.x;
  v9 = &vertexes[vertindices[firstvertindex + 1]];
  v10 = vertindices[firstvertindex + 2];
  return (float)((float)((float)((float)(plane->m_Normal.y
                                       * (float)((float)(normal.y * 0.1)
                                               + (float)((float)((float)((float)(v9->position.y - v2_4)
                                                                       + (float)(vertexes[v10].position.y - v2_4))
                                                               * 0.25)
                                                       + v2_4)))
                               + (float)(plane->m_Normal.x
                                       * (float)((float)(normal.x * 0.1)
                                               + (float)((float)((float)((float)(x - v2)
                                                                       + (float)(vertexes[v10].position.x - v2))
                                                               * 0.25)
                                                       + v2))))
                       + (float)(plane->m_Normal.z
                               * (float)((float)(normal.z * 0.1)
                                       + (float)((float)((float)((float)(v9->position.z - v2_8)
                                                               + (float)(vertexes[v10].position.z - v2_8))
                                                       * 0.25)
                                               + v2_8))))
               - plane->m_Dist) >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101C9050
// Name: private: void CUtlDataEnvelope::Assign(class CUtlDataEnvelope const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDataEnvelope::Assign(CUtlDataEnvelope *this, CUtlDataEnvelope *from)
{
  CUtlDataEnvelope *m_pData; // ebx
  int m_nBytes; // esi
  unsigned __int8 *v5; // eax

  m_pData = from;
  m_nBytes = from->m_nBytes;
  if ( m_nBytes != 0 )
  {
    if ( m_nBytes > 4 )
      m_pData = (CUtlDataEnvelope *)from->m_pData;
  }
  else
  {
    m_pData = nullptr;
  }
  if ( m_pData != nullptr )
  {
    this->m_nBytes = m_nBytes;
    if ( m_nBytes <= 4 )
    {
      memcpy(dst: (unsigned __int8 *)this, src: (unsigned __int8 *)m_pData, count: m_nBytes);
    }
    else
    {
      v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: m_nBytes);
      this->m_pData = v5;
      memcpy(dst: v5, src: (unsigned __int8 *)m_pData, count: m_nBytes);
    }
  }
  else
  {
    this->m_pData = nullptr;
    this->m_nBytes = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C90C0
// Name: void MarkSurfaceBrushes(int,struct worldbrushdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkSurfaceBrushes(int nSurfIndex, worldbrushdata_t *pData)
{
  dfacebrushlist_t *m_pSurfaceBrushList; // edx
  unsigned int m_nFaceBrushCount; // ecx
  unsigned __int16 *p_m_nFaceBrushStart; // edi
  int v5; // eax

  m_pSurfaceBrushList = pData->m_pSurfaceBrushList;
  if ( m_pSurfaceBrushList != nullptr )
  {
    m_nFaceBrushCount = m_pSurfaceBrushList[nSurfIndex].m_nFaceBrushCount;
    if ( m_nFaceBrushCount > 1 )
      p_m_nFaceBrushStart = &pData->m_pSurfaceBrushes[m_pSurfaceBrushList[nSurfIndex].m_nFaceBrushStart];
    else
      p_m_nFaceBrushStart = &m_pSurfaceBrushList[nSurfIndex].m_nFaceBrushStart;
    v5 = 0;
    if ( (_WORD)m_nFaceBrushCount != 0 )
    {
      do
        g_BSPData.map_brushes.m_pArray[p_m_nFaceBrushStart[v5++]].contents |= 0x40000u;
      while ( v5 < m_pSurfaceBrushList[nSurfIndex].m_nFaceBrushCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C9130
// Name: public: virtual void CPaintmapDataManager::GetPaintmapSize(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::GetPaintmapSize(
        CPaintmapDataManager *this,
        int paintmap,
        int *width,
        int *height)
{
  CPaintTextureData *v4; // eax

  if ( paintmap >= 0 && paintmap < this->m_iPaintmaps )
  {
    v4 = &this->m_pPaintTextureDataArray[paintmap];
    *width = v4->m_nPaintWidth;
    *height = v4->m_nPaintHeight;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C9160
// Name: public: virtual void CPaintmapDataManager::OnRestorePaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::OnRestorePaintmaps(CPaintmapDataManager *this)
{
  int v1; // edx
  int v2; // esi

  v1 = 0;
  if ( this->m_iPaintmaps > 0 )
  {
    v2 = 0;
    do
    {
      this->m_pPaintTextureDataArray[v2].m_nDirtyFlag = PAINTMAP_DIRTY_FULLRECT;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_iPaintmaps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C9190
// Name: unsigned char BlendColor(unsigned char,unsigned char,float,float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl BlendColor(
        unsigned __int8 colorIndex,
        unsigned __int8 nPrePixel,
        float flAlpha,
        float flPaintCoatPercent,
        float flMaxAlpha)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  if ( colorIndex == 4 )
  {
    if ( paint_alpha_offset_enabled.m_pParent != nullptr && paint_alpha_offset_enabled.m_pParent->m_Value.m_nValue != 0 )
      return 32 * (nPrePixel >> 5);
    else
      return 0x80;
  }
  else
  {
    v6 = (float)(nPrePixel & 0x1F) * 0.032258064;
    if ( v6 >= 0.0 )
    {
      v7 = 1.0;
      if ( v6 <= 1.0 )
        v7 = (float)(nPrePixel & 0x1F) * 0.032258064;
    }
    else
    {
      v7 = 0.0;
    }
    v8 = (float)(flAlpha * flPaintCoatPercent) + v7;
    if ( v8 >= 0.0 )
    {
      if ( v8 > flMaxAlpha )
        v8 = flMaxAlpha;
      return (32 * colorIndex) | (int)(float)(v8 * 31.0);
    }
    else
    {
      return (32 * colorIndex) | (int)(float)(0.0 * 31.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C9240
// Name: float ComputeCircleAlpha(struct PaintRect_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputeCircleAlpha(const PaintRect_t *paintRect, int x, int y)
{
  float v4; // xmm0_4
  double v5; // st7
  double result; // st7
  double v7; // st7
  float v8; // xmm0_4
  float v9; // [esp+8h] [ebp-2Ch]
  float v10; // [esp+24h] [ebp-10h]
  float v11; // [esp+24h] [ebp-10h]

  v9 = fsqrt(
         (float)((float)((float)y - paintRect->uvCenter.y) * (float)((float)y - paintRect->uvCenter.y))
       + (float)((float)((float)x - paintRect->uvCenter.x) * (float)((float)x - paintRect->uvCenter.x)));
  v4 = (float)(v9 / paintRect->flCircleRadius) + paintRect->flCenterAlpha;
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      v5 = Bias(
             x: (float)(v9 / paintRect->flCircleRadius) + paintRect->flCenterAlpha,
             biasAmt: paintsplat_bias.m_pParent->m_Value.m_fValue);
    else
      v5 = Bias(x: 1.0, biasAmt: paintsplat_bias.m_pParent->m_Value.m_fValue);
  }
  else
  {
    v5 = Bias(x: 0.0, biasAmt: paintsplat_bias.m_pParent->m_Value.m_fValue);
  }
  result = 1.0 - v5;
  if ( paintsplat_noise_enabled.m_pParent != nullptr && paintsplat_noise_enabled.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = result;
    v7 = _RandomFloat(
           this: (IUniformRandomStream *)paintsplat_max_alpha_noise.m_pParent,
           a2: COERCE_FLOAT(LODWORD(paintsplat_max_alpha_noise.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_),
           a3: paintsplat_max_alpha_noise.m_pParent->m_Value.m_fValue)
       + v10;
    if ( v7 >= 0.0 )
    {
      v8 = v7;
      v11 = v7;
      if ( v11 > 1.0 )
        return 1.0;
      return v8;
    }
    else
    {
      return 0.0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C9370
// Name: private: unsigned int CPaintTextureData::BlendLuxel(struct PaintRect_t const __near &,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::BlendLuxel(
        CPaintTextureData *this,
        const PaintRect_t *paintRect,
        int x,
        int y,
        float flNewAlpha,
        float flMaxAlpha)
{
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // bl
  unsigned __int8 v8; // al

  v6 = &this->m_backbuffer[y * this->m_nPaintWidth + x];
  v7 = *v6;
  v8 = BlendColor(
         colorIndex: paintRect->colorIndex,
         nPrePixel: *v6,
         flAlpha: flNewAlpha,
         flPaintCoatPercent: paintRect->flPaintCoatPercent,
         flMaxAlpha);
  if ( v7 == v8 )
    return 0;
  *v6 = v8;
  if ( ((v7 ^ v8) & 0xE0) != 0 )
    return 3;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C93E0
// Name: private: unsigned int CPaintTextureData::AddSurroundingAlpha(struct PaintRect_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::AddSurroundingAlpha(
        CPaintTextureData *this,
        const PaintRect_t *paintRect,
        int x,
        const PaintRect_t *y)
{
  msurfacelighting_t *surfacelighting; // ecx
  unsigned int v6; // eax
  unsigned int v7; // esi
  int v8; // ebx
  unsigned int v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // eax
  int v13; // ecx
  int v14; // esi
  unsigned int v15; // esi
  unsigned int v16; // esi
  unsigned int v17; // esi
  int v18; // eax
  unsigned int v19; // esi
  const PaintRect_t *v20; // eax
  unsigned int v21; // esi
  unsigned int v22; // esi
  unsigned int v23; // esi
  unsigned int v24; // esi
  unsigned int v25; // esi
  unsigned int v26; // esi
  unsigned int v27; // esi
  unsigned int v28; // esi
  unsigned int v29; // esi
  unsigned int v30; // eax
  unsigned int v31; // esi
  unsigned int v32; // esi
  unsigned int v33; // esi
  unsigned int v34; // esi
  unsigned int v35; // esi
  const PaintRect_t *v36; // [esp+28h] [ebp+Ch]
  const PaintRect_t *paintRecta; // [esp+2Ch] [ebp+10h]

  surfacelighting = host_state.worldbrush->surfacelighting;
  v6 = ((char *)paintRect->surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
  v7 = 0;
  v8 = x;
  switch ( ((int)y <= *(__int16 *)((char *)&surfacelighting->m_OffsetIntoLightmapPage[1] + v6) ? 0 : 4)
         | (x >= *(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v6)
               + *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v6)
          ? 0
          : 2)
         | ((int)y >= *(__int16 *)((char *)&surfacelighting->m_OffsetIntoLightmapPage[1] + v6)
                    + *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + v6)
          ? 0
          : 8)
         | (x > *(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v6)) )
  {
    case 1:
      return CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
    case 2:
      return CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
    case 3:
      v10 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      return CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v10;
    case 4:
      return CPaintTextureData::BlendLuxel(
               this,
               paintRect,
               x,
               y: (int)&y[-1].surfID + 3,
               flNewAlpha: 0.0,
               flMaxAlpha: 1.0);
    case 5:
      v11 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      paintRecta = (const PaintRect_t *)((char *)y - 1);
      v12 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x - 1,
              y: (int)paintRecta,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
      goto LABEL_7;
    case 6:
      v11 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      paintRecta = (const PaintRect_t *)((char *)y - 1);
      v12 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x + 1,
              y: (int)paintRecta,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
LABEL_7:
      v13 = (int)paintRecta;
      goto LABEL_8;
    case 7:
      v15 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v16 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x - 1,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v15;
      v17 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v16;
      v8 = x + 1;
      v18 = (int)&y[-1].surfID + 3;
      goto LABEL_12;
    case 8:
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: (int)&y->rect.x + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
    case 9:
      v11 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v12 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x - 1,
              y: (int)&y->rect.x + 1,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
      v13 = (int)&y->rect.x + 1;
      goto LABEL_8;
    case 0xA:
      v11 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v12 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x + 1,
              y: (int)&y->rect.x + 1,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
      v13 = (int)&y->rect.x + 1;
LABEL_8:
      v14 = v12 | v11;
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: v13, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v14;
    case 0xB:
      v21 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v22 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x - 1,
              y: (int)&y->rect.x + 1,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v21;
      v17 = CPaintTextureData::BlendLuxel(this, paintRect, x, y: (int)&y->rect.x + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0)
          | v22;
      v8 = x + 1;
      v18 = (int)&y->rect.x + 1;
LABEL_12:
      v19 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8, y: v18, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v17;
      v20 = y;
      goto LABEL_22;
    case 0xC:
      v14 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
      v13 = (int)&y->rect.x + 1;
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: v13, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v14;
    case 0xD:
      v23 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
      v24 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x - 1,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v23;
      v25 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v24;
      v26 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x - 1,
              y: (int)&y->rect.x + 1,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v25;
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: (int)&y->rect.x + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0)
           | v26;
    case 0xE:
      v27 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
      v28 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x + 1,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v27;
      v29 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v28;
      v36 = (const PaintRect_t *)((char *)&y->rect.x + 1);
      v30 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: v8 + 1,
              y: (int)&y->rect.x + 1,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
      goto LABEL_21;
    case 0xF:
      v31 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
      v32 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: x - 1,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v31;
      v33 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v32;
      v36 = (const PaintRect_t *)((char *)&y->rect.x + 1);
      v34 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: v8 - 1,
              y: (int)&y->rect.x + 1,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v33;
      v35 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: v8 + 1,
              y: (int)&y[-1].surfID + 3,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0)
          | v34;
      v29 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8 + 1, (int)y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v35;
      v30 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: v8 + 1,
              y: (int)&y->rect.x + 1,
              flNewAlpha: 0.0,
              flMaxAlpha: 1.0);
LABEL_21:
      v19 = v30 | v29;
      v20 = v36;
LABEL_22:
      v7 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8, y: (int)v20, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v19;
      break;
    default:
      return v7;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101C9A90
// Name: private: unsigned int CPaintTextureData::DrawLine(struct PaintRect_t const __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::DrawLine(
        CPaintTextureData *this,
        const PaintRect_t *paintRect,
        int x1,
        unsigned int x2,
        int y)
{
  __int16 *v7; // eax
  int v8; // edx
  int v10; // ecx
  double v11; // st7
  unsigned int v12; // eax
  int v13; // eax
  double v14; // st7
  float v15; // xmm3_4
  unsigned __int8 colorIndex; // cl
  unsigned __int8 *v17; // edx
  unsigned __int8 v18; // bl
  char v19; // al
  float v20; // xmm0_4
  float v21; // xmm1_4
  unsigned int result; // eax
  bool v23; // zf
  CPaintTextureData *v24; // ecx
  const PaintRect_t *v25; // [esp-18h] [ebp-30h]
  float v26; // [esp-14h] [ebp-2Ch]
  float v27; // [esp-14h] [ebp-2Ch]
  int v28; // [esp-14h] [ebp-2Ch]
  const PaintRect_t *v29; // [esp-10h] [ebp-28h]
  int flNewAlpha; // [esp+0h] [ebp-18h]
  CPaintTextureData *v31; // [esp+4h] [ebp-14h]
  float m_fValue; // [esp+8h] [ebp-10h]
  int v33; // [esp+Ch] [ebp-Ch]
  signed int v34; // [esp+10h] [ebp-8h]
  int sMax; // [esp+14h] [ebp-4h]
  int start; // [esp+20h] [ebp+8h]
  int starta; // [esp+20h] [ebp+8h]
  float v38; // [esp+2Ch] [ebp+14h]
  int v39; // [esp+2Ch] [ebp+14h]

  v7 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                 + (((char *)paintRect->surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v8 = v7[5];
  start = v7[4];
  v34 = x2;
  flNewAlpha = v7[2];
  v10 = x1;
  v31 = this;
  sMax = 0;
  v33 = x1;
  m_fValue = 1.0;
  if ( y == v8 || y == v8 + v7[3] )
  {
    m_fValue = paint_max_surface_border_alpha.m_pParent->m_Value.m_fValue;
  }
  else
  {
    if ( x1 == start )
    {
      if ( paintRect->colorIndex == 4 )
      {
        v11 = 1.0;
      }
      else
      {
        v11 = ComputeCircleAlpha(paintRect, x: x1, y);
        v10 = x1;
      }
      v26 = v11;
      v12 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: v10,
              y,
              flNewAlpha: v26,
              flMaxAlpha: paint_max_surface_border_alpha.m_pParent->m_Value.m_fValue);
      v10 = x1;
      sMax = v12;
      v33 = x1 + 1;
    }
    v13 = x2;
    if ( x2 == start + flNewAlpha )
    {
      if ( paintRect->colorIndex == 4 )
      {
        v14 = 1.0;
      }
      else
      {
        v14 = ComputeCircleAlpha(paintRect, x: x2, y);
        v13 = x2;
      }
      v27 = v14;
      sMax |= CPaintTextureData::BlendLuxel(
                this,
                paintRect,
                x: v13,
                y,
                flNewAlpha: v27,
                flMaxAlpha: paint_max_surface_border_alpha.m_pParent->m_Value.m_fValue);
      v10 = x1;
      v34 = x2 - 1;
    }
  }
  starta = v33;
  if ( v33 <= v34 )
  {
    do
    {
      if ( paintRect->colorIndex == 4 )
      {
        v15 = 1.0;
      }
      else
      {
        v38 = ComputeCircleAlpha(paintRect, x: starta, y);
        v15 = v38;
      }
      colorIndex = paintRect->colorIndex;
      v39 = 0;
      v17 = &this->m_backbuffer[y * this->m_nPaintWidth + starta];
      v18 = *v17;
      if ( colorIndex == 4 )
      {
        if ( paint_alpha_offset_enabled.m_pParent != nullptr
          && paint_alpha_offset_enabled.m_pParent->m_Value.m_nValue != 0 )
        {
          v19 = 32 * (v18 >> 5);
        }
        else
        {
          v19 = 0x80;
        }
      }
      else
      {
        v20 = (float)(v18 & 0x1F) * 0.032258064;
        if ( v20 >= 0.0 )
        {
          if ( v20 > 1.0 )
            v20 = 1.0;
        }
        else
        {
          v20 = 0.0;
        }
        v21 = (float)(paintRect->flPaintCoatPercent * v15) + v20;
        if ( v21 >= 0.0 )
        {
          if ( v21 > m_fValue )
            v21 = m_fValue;
        }
        else
        {
          v21 = 0.0;
        }
        v19 = (32 * colorIndex) | (int)(float)(v21 * 31.0);
      }
      if ( v18 != v19 )
      {
        *v17 = v19;
        v39 = 1;
        if ( ((v18 ^ (unsigned __int8)v19) & 0xE0) != 0 )
          v39 = 3;
      }
      sMax |= v39;
      this = v31;
      ++starta;
    }
    while ( starta <= v34 );
    v10 = x1;
  }
  result = sMax;
  if ( paint_alpha_offset_enabled.m_pParent != nullptr
    && paint_alpha_offset_enabled.m_pParent->m_Value.m_nValue != 0
    && paintRect->colorIndex != 4 )
  {
    v23 = v10 == x2;
    v29 = (const PaintRect_t *)y;
    v28 = v10;
    v25 = paintRect;
    v24 = this;
    if ( !v23 )
    {
      sMax |= CPaintTextureData::AddSurroundingAlpha(this, paintRect, x: v28, (const PaintRect_t *)y);
      v29 = (const PaintRect_t *)y;
      v28 = x2;
      v25 = paintRect;
      v24 = this;
    }
    return sMax | CPaintTextureData::AddSurroundingAlpha(this: v24, paintRect: v25, x: v28, y: v29);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C9D20
// Name: private: unsigned int CPaintTextureData::Draw2Lines(struct PaintRect_t const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::Draw2Lines(
        CPaintTextureData *this,
        const PaintRect_t *paintRect,
        float x,
        float y)
{
  int v6; // edx
  float v7; // xmm1_4
  int v8; // ecx
  int v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // eax
  int v15; // [esp+0h] [ebp-10h]
  int maxX; // [esp+4h] [ebp-Ch]
  int maxY; // [esp+Ch] [ebp-4h]
  int y2; // [esp+18h] [ebp+8h]
  int x1; // [esp+1Ch] [ebp+Ch]
  signed int x2; // [esp+20h] [ebp+10h]

  v6 = paintRect->rect.y;
  v7 = paintRect->uvCenter.x;
  v8 = paintRect->rect.x;
  maxY = paintRect->rect.height + v6 - 1;
  v15 = v6;
  maxX = paintRect->rect.width + paintRect->rect.x - 1;
  x1 = (int)(float)((float)(v7 - x) - 0.5);
  if ( x1 <= paintRect->rect.x )
    x1 = paintRect->rect.x;
  v10 = (int)(float)((float)(paintRect->uvCenter.y - y) - 0.5);
  if ( v10 <= v6 )
    v10 = paintRect->rect.y;
  x2 = (int)(float)((float)(v7 + x) + 0.5);
  if ( x2 >= paintRect->rect.width + paintRect->rect.x - 1 )
    x2 = paintRect->rect.width + paintRect->rect.x - 1;
  y2 = (int)(float)((float)(paintRect->uvCenter.y + y) + 0.5);
  if ( y2 >= maxY )
    y2 = maxY;
  if ( x1 > maxX )
    return 0;
  v11 = x2;
  if ( x2 < v8 )
    return 0;
  v12 = 0;
  if ( v6 <= v10 && v10 <= maxY )
  {
    v13 = CPaintTextureData::DrawLine(this, paintRect, x1, x2, y: v10);
    v6 = v15;
    v12 = v13;
    v11 = x2;
  }
  if ( v10 != y2 && v6 <= y2 && y2 <= maxY )
    v12 |= CPaintTextureData::DrawLine(this, paintRect, x1, x2: v11, y: y2);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x101C9E30
// Name: private: unsigned int CPaintTextureData::DrawCircle(struct PaintRect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPaintTextureData::DrawCircle(CPaintTextureData *this, const PaintRect_t *paintRect)
{
  int result; // eax
  unsigned int v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  unsigned int v8; // esi
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  int v12; // [esp+4h] [ebp-Ch]
  float v13; // [esp+8h] [ebp-8h]
  float flCircleRadius; // [esp+Ch] [ebp-4h]
  float error; // [esp+18h] [ebp+8h]

  LODWORD(v13) = LODWORD(paintRect->flCircleRadius) ^ _mask__NegFloat_;
  result = 0;
  flCircleRadius = paintRect->flCircleRadius;
  error = 0.0;
  v12 = 0;
  if ( flCircleRadius >= 0.0 )
  {
    do
    {
      v5 = CPaintTextureData::Draw2Lines(this, paintRect, x: flCircleRadius, y: error);
      v6 = flCircleRadius;
      v7 = error;
      v8 = v5;
      if ( flCircleRadius != error )
      {
        v7 = error;
        v6 = flCircleRadius;
        v8 = CPaintTextureData::Draw2Lines(this, paintRect, x: error, y: flCircleRadius) | v5;
      }
      v12 |= v8;
      v9 = v7 + v13;
      v10 = v7 + 1.0;
      v11 = v9 + v10;
      error = v10;
      v13 = v11;
      if ( v11 >= 0.0 )
      {
        v6 = v6 - 1.0;
        flCircleRadius = v6;
        v13 = (float)(v11 - v6) - v6;
      }
    }
    while ( v6 >= v10 );
    return v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C9F20
// Name: bool ComputePaintRect(struct msurface2_t __near *,class Vector const __near &,float,struct PaintRect_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall ComputePaintRect@<al>(
        float a1@<ebp>,
        msurface2_t *surfID,
        const Vector *vPosition,
        float flSphereRadius,
        PaintRect_t *paintRect)
{
  __int128 v5; // xmm0
  float y; // xmm3_4
  float z; // xmm4_4
  mtexinfo_t *texinfo; // eax
  int v9; // edx
  float *v10; // eax
  __int16 *v11; // edx
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  int v16; // eax
  msurfacelighting_t *surfacelighting; // ecx
  __int128 v18; // xmm2
  float v19; // xmm5_4
  int v20; // esi
  int v21; // edx
  char *v22; // eax
  float v23; // ecx
  int v24; // eax
  __int128 v25; // xmm3
  float v26; // xmm5_4
  float v27; // xmm1_4
  double v28; // st7
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  int v33; // ecx
  int x_low; // edi
  float v35; // xmm4_4
  int v36; // esi
  int v37; // edx
  int v38; // ecx
  int v39; // esi
  int v40; // edx
  int v41; // ecx
  SurfaceCtx_t v43; // [esp+14h] [ebp-80h] BYREF
  _BYTE v44[44]; // [esp+38h] [ebp-5Ch] OVERLAPPED
  int v45; // [esp+64h] [ebp-30h]
  __int128 v46; // [esp+68h] [ebp-2Ch]
  int v47; // [esp+80h] [ebp-14h]
  Vector2D uvCenter; // [esp+84h] [ebp-10h]
  int tMax; // [esp+8Ch] [ebp-8h]
  int vars0; // [esp+94h] [ebp+0h]

  uvCenter.y = a1;
  tMax = vars0;
  *(float *)&v47 = (float)((float)((float)(vPosition->y * surfID->plane->normal.y)
                                 + (float)(vPosition->x * surfID->plane->normal.x))
                         + (float)(vPosition->z * surfID->plane->normal.z))
                 - surfID->plane->dist;
  v5 = 0;
  *(float *)&v5 = fsqrt((float)(flSphereRadius * flSphereRadius) - (float)(*(float *)&v47 * *(float *)&v47));
  *(_OWORD *)&v44[16] = v5;
  SurfSetupSurfaceContext(ctx: &v43, surfID);
  y = vPosition->y;
  z = vPosition->z;
  texinfo = host_state.worldbrush->texinfo;
  v9 = *((unsigned __int16 *)surfID + 11) >> 1;
  *(float *)&v5 = texinfo[v9].lightmapVecsLuxelsPerWorldUnits[0].y;
  v10 = (float *)&texinfo[v9];
  v11 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v12 = (float)(v43.m_Offset.y
              + (float)(v43.m_Scale.y
                      * (float)((float)((float)((float)((float)((float)(v10[13] * y) + (float)(vPosition->x * v10[12]))
                                                      + (float)(v10[14] * z))
                                              + v10[15])
                                      - (float)v11[1])
                              + 0.5)))
      / v43.m_Scale.y;
  *(float *)&v44[32] = (float)(v43.m_Offset.x
                             + (float)(v43.m_Scale.x
                                     * (float)((float)((float)((float)((float)((float)(*(float *)&v5 * y)
                                                                             + (float)(vPosition->x * v10[8]))
                                                                     + (float)(v10[10] * z))
                                                             + v10[11])
                                                     - (float)*v11)
                                             + 0.5)))
                     / v43.m_Scale.x;
  *(float *)&v44[36] = v12;
  v13 = v10[12];
  v14 = v10[14];
  v18 = 0;
  *(float *)&v18 = (float)((float)(v10[8] * v10[8]) + (float)(v10[9] * v10[9])) + (float)(v10[10] * v10[10]);
  v15 = v10[13];
  v16 = (char *)surfID - (char *)host_state.worldbrush->surfaces2;
  surfacelighting = host_state.worldbrush->surfacelighting;
  *(float *)&v18 = fsqrt(*(float *)&v18);
  v46 = v18;
  v19 = (float)((float)(v13 * v13) + (float)(v15 * v15)) + (float)(v14 * v14);
  v16 &= 0xFFFFFFE0;
  v20 = *(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v16);
  v21 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v16);
  v22 = (char *)surfacelighting + v16;
  LODWORD(v23) = *((__int16 *)v22 + 5);
  v24 = *((__int16 *)v22 + 3);
  v25 = 0;
  *(float *)&v25 = fsqrt(v19);
  *((float *)&v46 + 2) = *(float *)&v18 * *(float *)&v44[16];
  *(_OWORD *)v44 = v25;
  *((float *)&v46 + 3) = *(float *)&v25 * *(float *)&v44[16];
  v26 = v12 - (float)(*(float *)&v25 * *(float *)&v44[16]);
  v27 = v12 + (float)(*(float *)&v25 * *(float *)&v44[16]);
  uvCenter.x = v23;
  v45 = v21;
  *(_DWORD *)&v44[40] = v24;
  if ( (float)(*(float *)&v44[32] + (float)(*(float *)&v18 * *(float *)&v44[16])) < (float)v20
    || (float)(v20 + v21) < (float)(*(float *)&v44[32] - (float)(*(float *)&v18 * *(float *)&v44[16]))
    || v27 < (float)SLODWORD(v23)
    || (float)(LODWORD(v23) + v24) < v26 )
  {
    return false;
  }
  v28 = *((float *)&v46 + 3);
  if ( *((float *)&v46 + 2) >= (double)*((float *)&v46 + 3) )
    v28 = *((float *)&v46 + 2);
  *((float *)&v46 + 3) = floor(X: v28 + 0.5);
  v29 = *(float *)&v47;
  paintRect->flCircleRadius = *((float *)&v46 + 3);
  v30 = *((float *)&v46 + 3);
  v31 = *(float *)&v44[36];
  paintRect->flCenterAlpha = v29 / flSphereRadius;
  v32 = *(float *)&v44[32];
  v33 = (int)(float)((float)(*(float *)&v44[32] - v30) - 0.5);
  paintRect->uvCenter.x = *(float *)&v44[32];
  paintRect->uvCenter.y = v31;
  paintRect->surfID = surfID;
  v47 = v33;
  if ( v33 <= v20 )
    v47 = v20;
  x_low = LODWORD(uvCenter.x);
  v35 = (float)(v31 - v30) - 0.5;
  if ( (int)v35 > SLODWORD(uvCenter.x) )
    x_low = (int)v35;
  v36 = v45 + v20 + 1;
  v37 = (int)(float)((float)(v32 + v30) + 0.5);
  if ( v37 >= v36 )
    v37 = v36;
  v45 = (int)(float)((float)(v31 + v30) + 0.5);
  v38 = *(_DWORD *)&v44[40] + LODWORD(uvCenter.x) + 1;
  if ( v45 < v38 )
    v38 = v45;
  v39 = v47;
  paintRect->rect.x = v47;
  v40 = v37 - v39;
  v41 = v38 - x_low;
  paintRect->rect.y = x_low;
  paintRect->rect.width = v40;
  paintRect->rect.height = v41;
  return v40 > 0 && v41 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CA330
// Name: public: void CPaintmapDataManager::RemoveAllPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::RemoveAllPaint(CPaintmapDataManager *this)
{
  int v2; // ebx
  CPaintTextureData *v3; // esi
  int numbrushes; // edx
  cbrush_t *m_pArray; // ecx
  int i; // eax
  int v7; // [esp+Ch] [ebp-4h]

  v2 = 0;
  if ( this->m_pPaintTextureDataArray != nullptr && this->m_iPaintmaps != 0 )
  {
    v7 = 0;
    do
    {
      v3 = &this->m_pPaintTextureDataArray[v7];
      _V_memset(dest: v3->m_backbuffer, fill: 128, count: v3->m_nPaintWidth * v3->m_nPaintHeight);
      ++v7;
      ++v2;
      v3->m_nDirtyFlag = PAINTMAP_DIRTY_FULLRECT;
    }
    while ( v2 != this->m_iPaintmaps );
  }
  numbrushes = g_BSPData.numbrushes;
  m_pArray = g_BSPData.map_brushes.m_pArray;
  for ( i = 0; i < numbrushes; ++i )
    m_pArray[i].contents &= ~0x40000u;
}

//------------------------------------------------------------------------------
// Address: 0x101CA3B0
// Name: public: void CPaintmapDataManager::PaintAllSurfaces(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::PaintAllSurfaces(CPaintmapDataManager *this, unsigned __int8 color)
{
  int v3; // ebx
  CPaintTextureData *m_pPaintTextureDataArray; // esi
  int numsurfaces; // edx
  int v6; // ecx
  int numbrushes; // edx
  cbrush_t *m_pArray; // ecx
  int j; // eax
  int i; // [esp+Ch] [ebp-4h]
  int colora; // [esp+18h] [ebp+8h]

  v3 = 0;
  if ( this->m_pPaintTextureDataArray != nullptr )
  {
    i = 0;
    if ( this->m_iPaintmaps != 0 )
    {
      colora = (unsigned __int8)(32 * color) | 0x1F;
      do
      {
        m_pPaintTextureDataArray = this->m_pPaintTextureDataArray;
        _V_memset(
          dest: m_pPaintTextureDataArray[v3].m_backbuffer,
          fill: colora,
          count: m_pPaintTextureDataArray[v3].m_nPaintWidth * m_pPaintTextureDataArray[v3].m_nPaintHeight);
        m_pPaintTextureDataArray[v3++].m_nDirtyFlag = PAINTMAP_DIRTY_FULLRECT;
        ++i;
      }
      while ( i != this->m_iPaintmaps );
    }
  }
  numsurfaces = host_state.worldbrush->numsurfaces;
  if ( numsurfaces > 0 )
  {
    v6 = 0;
    do
    {
      host_state.worldbrush->surfaces2[v6++].flags |= 0x200000u;
      --numsurfaces;
    }
    while ( numsurfaces != 0 );
  }
  numbrushes = g_BSPData.numbrushes;
  m_pArray = g_BSPData.map_brushes.m_pArray;
  for ( j = 0; j < numbrushes; ++j )
    m_pArray[j].contents |= 0x40000u;
}

//------------------------------------------------------------------------------
// Address: 0x101CA480
// Name: public: virtual void CPaintmapDataManager::AllocatePaintmapData(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::AllocatePaintmapData(
        CPaintmapDataManager *this,
        int iPaintmapID,
        int iCorrespondingLightMapWidth,
        int iCorrespondingLightMapHeight)
{
  CPaintTextureData *v4; // esi
  unsigned __int8 *v5; // eax
  int v6; // [esp-8h] [ebp-Ch]

  v4 = &this->m_pPaintTextureDataArray[iPaintmapID];
  v4->m_nPaintWidth = iCorrespondingLightMapWidth;
  v4->m_nPaintHeight = iCorrespondingLightMapHeight;
  v4->m_lightmapPageID = iPaintmapID;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: iCorrespondingLightMapHeight * iCorrespondingLightMapWidth);
  v6 = v4->m_nPaintHeight * v4->m_nPaintWidth;
  v4->m_backbuffer = v5;
  _V_memset(dest: v5, fill: 128, count: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101CA4E0
// Name: public: virtual void CFunctor4<void (*)(int,unsigned char __near *,int,struct Rect_t __near *),int,unsigned char __near *,int,class CUtlEnvelope<struct Rect_t>,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor4<void (__cdecl *)(int,unsigned char *,int,Rect_t *),int,unsigned char *,int,CUtlEnvelope<Rect_t>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor4<void (__cdecl*)(int,unsigned char *,int,Rect_t *),int,unsigned char *,int,CUtlEnvelope<Rect_t>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  int m_nBytes; // edx
  Rect_t *p_m_arg4; // eax

  m_nBytes = this->m_arg4.m_nBytes;
  p_m_arg4 = (Rect_t *)&this->m_arg4;
  if ( m_nBytes != 0 )
  {
    if ( m_nBytes > 4 )
      p_m_arg4 = (Rect_t *)p_m_arg4->x;
  }
  else
  {
    p_m_arg4 = nullptr;
  }
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2, a3: this->m_arg3, a4: p_m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x101CA5F0
// Name: public: void CPaintTextureData::GetPixels(struct Rect_t const __near &,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintTextureData::GetPixels(
        CPaintTextureData *this,
        const Rect_t *splatRect,
        CUtlMemory<char,int> *surfColors)
{
  const Rect_t *v4; // ecx
  int v5; // edi
  int v7; // edx
  unsigned __int8 v8; // bl
  float v9; // xmm0_4
  unsigned __int8 v10; // bl
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax
  bool v15; // zf
  unsigned __int8 *v16; // eax
  CPaintTextureData *v17; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]
  int y; // [esp+1Ch] [ebp+Ch]

  v4 = splatRect;
  v5 = 0;
  v17 = this;
  for ( i = 0; v5 < v4->height; i = v5 )
  {
    v7 = 0;
    for ( y = 0; v7 < v4->width; y = v7 )
    {
      v8 = this->m_backbuffer[this->m_nPaintWidth * (v5 + v4->y) + v4->x + v7];
      v9 = (float)(v8 & 0x1F) * 0.032258064;
      v10 = v8 >> 5;
      if ( v9 >= 0.0 )
      {
        if ( v9 > 1.0 )
          v9 = 1.0;
      }
      else
      {
        v9 = 0.0;
      }
      if ( v9 > paint_min_valid_alpha_value.m_pParent->m_Value.m_fValue )
      {
        m_pMemory = (int)surfColors[1].m_pMemory;
        m_nAllocationCount = surfColors->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
        {
          CUtlMemory<bool,int>::Grow(this: surfColors, num: m_pMemory - m_nAllocationCount + 1);
          v7 = y;
        }
        ++surfColors[1].m_pMemory;
        v13 = (unsigned __int8 *)surfColors->m_pMemory;
        v14 = (int)&surfColors[1].m_pMemory[-m_pMemory - 1];
        surfColors[1].m_nAllocationCount = (int)surfColors->m_pMemory;
        if ( v14 > 0 )
        {
          _V_memmove(dest: &v13[m_pMemory + 1], src: &v13[m_pMemory], count: v14);
          v7 = y;
        }
        v4 = splatRect;
        v15 = &surfColors->m_pMemory[m_pMemory] == nullptr;
        v16 = (unsigned __int8 *)&surfColors->m_pMemory[m_pMemory];
        v5 = i;
        if ( !v15 )
          *v16 = v10;
      }
      if ( debug_paint_alpha.m_pParent != nullptr && debug_paint_alpha.m_pParent->m_Value.m_nValue != 0 )
      {
        Con_NPrintf(idx: v7 + v5 * v4->width, fmt: "(%d, %d), Alpha: %f\n", v7, v5, v9);
        v4 = splatRect;
        v7 = y;
        v5 = i;
      }
      this = v17;
      ++v7;
    }
    ++v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CA740
// Name: void GetPaintColorFromSurface(struct msurface2_t __near *,class Vector const __near &,class Vector const __near &,float,class VPlane const __near &,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetPaintColorFromSurface(
        msurface2_t *surfID,
        const Vector *vPosition,
        const Vector *vContactNormal,
        float flSphereRadius,
        const VPlane *basePlane,
        CUtlMemory<char,int> *surfColors)
{
  int lightmapPageID; // esi
  PaintRect_t paintRect; // [esp+0h] [ebp-2Ch] BYREF
  int _2C; // [esp+2Ch] [ebp+0h] BYREF

  if ( (surfID->flags & 0x200000) != 0
    && (float)((float)((float)(vContactNormal->y * surfID->plane->normal.y)
                     + (float)(vContactNormal->x * surfID->plane->normal.x))
             + (float)(vContactNormal->z * surfID->plane->normal.z)) >= 0.89999998 )
  {
    lightmapPageID = materialSortInfoArray[surfID->materialSortID].lightmapPageID;
    if ( ComputePaintRect(a1: COERCE_FLOAT(&_2C), surfID, vPosition, flSphereRadius, &paintRect) )
      CPaintTextureData::GetPixels(
        this: &g_PaintManager.m_pPaintTextureDataArray[lightmapPageID],
        splatRect: &paintRect.rect,
        surfColors);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CA7F0
// Name: public: void ICallQueue::QueueCall<void,int,unsigned char __near *,int,struct Rect_t __near *,int,unsigned char __near *,int,class CUtlEnvelope<struct Rect_t>>(void (*)(int,unsigned char __near *,int,struct Rect_t __near *),int const __near &,unsigned char __near * const __near &,int const __near &,class CUtlEnvelope<struct Rect_t> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,int,unsigned char *,int,Rect_t *,int,unsigned char *,int,CUtlEnvelope<Rect_t>>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(int, unsigned __int8 *, int, Rect_t *),
        int *arg1,
        unsigned __int8 **arg2,
        int *arg3,
        const CUtlEnvelope<Rect_t> *arg4)
{
  CUtlDataEnvelope *v7; // esi

  v7 = (CUtlDataEnvelope *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v7 != nullptr )
  {
    v7[1].m_nBytes = 1;
    v7[2].m_pData = (unsigned __int8 *)pfnProxied;
    v7->m_pData = (unsigned __int8 *)&CFunctor4<void (__cdecl *)(int,unsigned char *,int,Rect_t *),int,unsigned char *,int,CUtlEnvelope<Rect_t>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v7[1].m_pData = (unsigned __int8 *)&CFunctor4<void (__cdecl *)(int,unsigned char *,int,Rect_t *),int,unsigned char *,int,CUtlEnvelope<Rect_t>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v7[2].m_nBytes = *arg1;
    v7[3].m_pData = *arg2;
    v7[3].m_nBytes = *arg3;
    CUtlDataEnvelope::Assign(this: v7 + 4, from: &arg4->CUtlDataEnvelope);
    this->QueueFunctorInternal(this, a2: (CFunctor *)v7);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CA990
// Name: void R_UpdatePaintmap(class ICallQueue __near *,int,unsigned char __near *,int,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_UpdatePaintmap(
        ICallQueue *pCallQueue,
        int paintmap,
        unsigned __int8 *pPaintData,
        int numRects,
        Rect_t *pRects)
{
  unsigned __int8 *v5; // edi
  signed int v6; // esi
  unsigned int v7; // [esp-Ch] [ebp-18h]
  CUtlEnvelope<Rect_t> dst; // [esp+4h] [ebp-8h] BYREF

  if ( pCallQueue != nullptr )
  {
    v5 = (unsigned __int8 *)pRects;
    v6 = 16 * numRects;
    if ( pRects != nullptr )
    {
      dst.m_nBytes = 16 * numRects;
      v7 = 16 * numRects;
      if ( v6 <= 4 )
      {
        memcpy((unsigned __int8 *)&dst, src: (unsigned __int8 *)pRects, count: v7);
      }
      else
      {
        dst.m_pData = (unsigned __int8 *)MemAlloc_Alloc(nSize: v7);
        memcpy(dst: dst.m_pData, src: v5, count: v6);
      }
    }
    else
    {
      dst.m_pData = nullptr;
      dst.m_nBytes = 0;
    }
    ICallQueue::QueueCall<void,int,unsigned char *,int,Rect_t *,int,unsigned char *,int,CUtlEnvelope<Rect_t>>(
      this: pCallQueue,
      pfnProxied: R_UpdatePaintmapRect,
      arg1: &paintmap,
      arg2: &pPaintData,
      arg3: &numRects,
      arg4: &dst);
    if ( dst.m_nBytes > 4 )
      free(pMem: dst.m_pData);
  }
  else
  {
    materials->UpdatePaintmap(this: materials, a2: paintmap, a3: pPaintData, a4: numRects, a5: pRects);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CAA40
// Name: public: void CPaintmapDataManager::UpdatePaintmapTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::UpdatePaintmapTextures(CPaintmapDataManager *this)
{
  IMatRenderContext *m_pObject; // edi
  IMaterialSystem *v3; // esi
  CFunctor *v4; // eax
  ICallQueue *v5; // ecx
  int v6; // esi
  int v7; // edi
  CPaintTextureData *v8; // eax
  PaintDirtyFlags_t m_nDirtyFlag; // ecx
  unsigned __int8 *m_backbuffer; // eax
  CPaintTextureData *m_pPaintTextureDataArray; // eax
  ICallQueue *v12; // ebx
  IMaterialSystem *v13; // esi
  CFunctor *v14; // eax
  CUtlEnvelope<Rect_t> arg4; // [esp+Ch] [ebp-1Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+14h] [ebp-14h]
  int arg1; // [esp+18h] [ebp-10h] BYREF
  unsigned __int8 *arg2; // [esp+1Ch] [ebp-Ch] BYREF
  int arg3; // [esp+20h] [ebp-8h] BYREF
  ICallQueue *pCallQueue; // [esp+24h] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    v3 = materials;
    v4 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v4 != nullptr )
    {
      v5 = pCallQueue;
      v4[1].m_nUserID = 1;
      v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v4[2].__vftable = (CFunctor_vtbl *) __thiscall IMaterialSystem::`vcall'{556,{flat}};
      v4[2].m_nUserID = (unsigned int)v3;
      v5->QueueFunctorInternal(this: v5, a2: v4);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    materials->BeginUpdatePaintmaps(this: materials);
  }
  v6 = 0;
  if ( this->m_iPaintmaps > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->m_pPaintTextureDataArray[v7];
      m_nDirtyFlag = v8->m_nDirtyFlag;
      if ( m_nDirtyFlag != PAINTMAP_CLEAN )
      {
        if ( m_nDirtyFlag == PAINTMAP_DIRTY_FULLRECT )
        {
          m_backbuffer = v8->m_backbuffer;
          arg3 = 0;
          arg2 = m_backbuffer;
          arg1 = v6;
          if ( pCallQueue != nullptr )
          {
            arg4.m_pData = nullptr;
            arg4.m_nBytes = 0;
            ICallQueue::QueueCall<void,int,unsigned char *,int,Rect_t *,int,unsigned char *,int,CUtlEnvelope<Rect_t>>(
              this: pCallQueue,
              pfnProxied: R_UpdatePaintmapRect,
              &arg1,
              &arg2,
              &arg3,
              &arg4);
            if ( arg4.m_nBytes > 4 )
              free(pMem: arg4.m_pData);
            arg4.m_nBytes = 0;
          }
          else
          {
            materials->UpdatePaintmap(this: materials, a2: v6, a3: m_backbuffer, a4: 0, a5: nullptr);
          }
        }
        else
        {
          R_UpdatePaintmap(
            pCallQueue,
            paintmap: v6,
            pPaintData: this->m_pPaintTextureDataArray[v7].m_backbuffer,
            numRects: this->m_pPaintTextureDataArray[v7].m_dirtyRects.m_Size,
            pRects: this->m_pPaintTextureDataArray[v7].m_dirtyRects.m_Memory.m_pMemory);
        }
        m_pPaintTextureDataArray = this->m_pPaintTextureDataArray;
        m_pPaintTextureDataArray[v7].m_nDirtyFlag = PAINTMAP_CLEAN;
        m_pPaintTextureDataArray[v7].m_dirtyRects.m_Size = 0;
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->m_iPaintmaps );
    m_pObject = pRenderContext.m_pObject;
  }
  v12 = pCallQueue;
  if ( pCallQueue != nullptr )
  {
    v13 = materials;
    v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v14 != nullptr )
    {
      v14[1].m_nUserID = 1;
      v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v14[2].__vftable = (CFunctor_vtbl *) __thiscall IMaterialSystem::`vcall'{560,{flat}};
      v14[2].m_nUserID = (unsigned int)v13;
      v12->QueueFunctorInternal(this: v12, a2: v14);
    }
    else
    {
      v12->QueueFunctorInternal(this: v12, a2: nullptr);
    }
  }
  else
  {
    materials->EndUpdatePaintmaps(this: materials);
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x101CAC30
// Name: public: void CPaintTextureData::GetSurfacePaintData(struct msurface2_t __near *,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintTextureData::GetSurfacePaintData(
        CPaintTextureData *this,
        msurface2_t *surfID,
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *data)
{
  _WORD *v3; // eax
  int v4; // ebx
  int v5; // esi
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // esi
  __int16 x; // [esp+0h] [ebp-8h]
  __int16 y; // [esp+10h] [ebp+8h]
  const unsigned __int8 *pEnd; // [esp+14h] [ebp+Ch]

  if ( this->m_backbuffer != nullptr )
  {
    v3 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                   + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
    x = v3[4];
    y = v3[5];
    v4 = (__int16)(v3[2] + 1);
    v5 = v4 * (__int16)(v3[3] + 1);
    CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(this: data, num: v5 + (4 - v5 % 4) % 4);
    m_pMemory = data->m_Memory.m_pMemory;
    v7 = &data->m_Memory.m_pMemory[v5];
    v8 = &this->m_backbuffer[x + this->m_nPaintWidth * y];
    for ( pEnd = v7; m_pMemory < pEnd; m_pMemory += v4 )
    {
      _V_memcpy(dest: m_pMemory, src: v8, count: v4);
      v8 += this->m_nPaintWidth;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CAD00
// Name: void R_PaintLeaf(struct mleaf_t __near *,struct paintinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_PaintLeaf(mleaf_t *pLeaf, paintinfo_t *paintinfo)
{
  int v2; // eax
  msurface2_t *v3; // ecx
  unsigned int flags; // eax
  int m_Size; // edx
  CUtlMemory<S3RGBA,int> *p_m_aApplySurfs; // ebx
  int v7; // eax
  S3RGBA *m_pMemory; // esi
  float *p_x; // eax
  float v10; // xmm1_4
  float y; // xmm5_4
  float v12; // xmm2_4
  float z; // xmm6_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float m_flSize; // xmm1_4
  float v18; // xmm0_4
  unsigned int flags_high; // edx
  mvertex_t *vertexes; // esi
  unsigned __int16 *v21; // ecx
  mvertex_t *v22; // eax
  float v23; // edi
  unsigned __int16 *v24; // edi
  mvertex_t *v25; // eax
  float v26; // ecx
  float v27; // edx
  mvertex_t *v28; // eax
  float v29; // ecx
  float v30; // edx
  float v31; // eax
  Vector *ClosestPointToTriangle; // eax
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  int v39; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v41; // ecx
  int v42; // eax
  S3RGBA *v43; // esi
  int nummarksurfaces; // edx
  Vector result; // [esp+0h] [ebp-88h] BYREF
  float v46; // [esp+14h] [ebp-74h]
  Vector c; // [esp+18h] [ebp-70h] BYREF
  Vector b; // [esp+24h] [ebp-64h] BYREF
  float v49; // [esp+34h] [ebp-54h]
  float v50; // [esp+38h] [ebp-50h]
  Vector a; // [esp+3Ch] [ebp-4Ch] BYREF
  float v52; // [esp+48h] [ebp-40h]
  msurface2_t **pHandle; // [esp+4Ch] [ebp-3Ch]
  msurface2_t *v54; // [esp+50h] [ebp-38h]
  unsigned int v55; // [esp+54h] [ebp-34h]
  VPlane v56; // [esp+58h] [ebp-30h]
  int i; // [esp+68h] [ebp-20h]
  float v58; // [esp+6Ch] [ebp-1Ch]
  float v59; // [esp+70h] [ebp-18h]
  float v60; // [esp+74h] [ebp-14h]
  float v61; // [esp+78h] [ebp-10h]
  float v62; // [esp+7Ch] [ebp-Ch]
  float x; // [esp+80h] [ebp-8h]
  char v64; // [esp+87h] [ebp-1h]

  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v2 = 0;
  i = 0;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v3 = pHandle[v2];
      flags = v3->flags;
      v54 = v3;
      if ( (flags & 0x100020) == 0 && (flags & 0x800) == 0 )
      {
        m_Size = paintinfo->m_aApplySurfs.m_Size;
        p_m_aApplySurfs = (CUtlMemory<S3RGBA,int> *)&paintinfo->m_aApplySurfs;
        v7 = 0;
        if ( m_Size <= 0 )
          goto LABEL_10;
        m_pMemory = p_m_aApplySurfs->m_pMemory;
        while ( (msurface2_t *)*m_pMemory != v3 )
        {
          ++v7;
          ++m_pMemory;
          if ( v7 >= m_Size )
            goto LABEL_10;
        }
        if ( v7 == -1 )
        {
LABEL_10:
          if ( materialSortInfoArray != nullptr && materialSortInfoArray[v3->materialSortID].lightmapPageID >= 0 )
          {
            p_x = &v3->plane->normal.x;
            v10 = *p_x;
            y = paintinfo->m_vPosition.y;
            v12 = p_x[1];
            z = paintinfo->m_vPosition.z;
            v14 = p_x[2];
            v15 = p_x[3];
            x = paintinfo->m_vPosition.x;
            v61 = y;
            v62 = z;
            v16 = (float)(x * v10) + (float)(y * v12);
            v56.m_Normal.x = v10;
            m_flSize = paintinfo->m_flSize;
            v18 = (float)(v16 + (float)(z * v14)) - v15;
            v56.m_Normal.y = v12;
            v56.m_Normal.z = v14;
            v56.m_Dist = v15;
            if ( v18 <= m_flSize && v18 >= 0.0 )
            {
              flags_high = HIBYTE(v3->flags);
              vertexes = host_state.worldbrush->vertexes;
              v21 = &host_state.worldbrush->vertindices[v3->firstvertindex];
              v22 = &vertexes[*v21];
              a.x = v22->position.x;
              v23 = v22->position.y;
              a.z = v22->position.z;
              a.y = v23;
              v64 = 0;
              if ( flags_high > 2 )
              {
                v52 = m_flSize;
                v24 = v21 + 1;
                v55 = flags_high - 2;
                do
                {
                  v25 = &vertexes[*v24];
                  v26 = v25->position.y;
                  b.x = v25->position.x;
                  v27 = v25->position.z;
                  v28 = &vertexes[v24[1]];
                  b.y = v26;
                  v29 = v28->position.x;
                  b.z = v27;
                  v30 = v28->position.y;
                  v31 = v28->position.z;
                  c.x = v29;
                  c.y = v30;
                  c.z = v31;
                  ClosestPointToTriangle = FindClosestPointToTriangle(&result, p: &paintinfo->m_vPosition, &a, &b, &c);
                  v33 = ClosestPointToTriangle->x;
                  v34 = ClosestPointToTriangle->y;
                  v35 = ClosestPointToTriangle->z;
                  v36 = (float)((float)((float)(ClosestPointToTriangle->x * v56.m_Normal.x)
                                      + (float)(v34 * v56.m_Normal.y))
                              + (float)(v56.m_Normal.z * v35))
                      - v56.m_Dist;
                  if ( v36 < 0.0 )
                  {
                    v37 = v36 + 0.1;
                    v33 = (float)(v37 * v56.m_Normal.x) + v33;
                    v34 = (float)(v37 * v56.m_Normal.y) + v34;
                    v35 = (float)(v37 * v56.m_Normal.z) + v35;
                  }
                  if ( (float)(v52 * v52) > (float)((float)((float)((float)(v61 - v34) * (float)(v61 - v34))
                                                          + (float)((float)(x - v33) * (float)(x - v33)))
                                                  + (float)((float)(v62 - v35) * (float)(v62 - v35))) )
                  {
                    if ( v64 == 0
                      || (v46 = v60 - v62,
                          v49 = v34 - v61,
                          v50 = v35 - v62,
                          (float)((float)((float)((float)(v59 - v61) * (float)(v59 - v61))
                                        + (float)((float)(v58 - x) * (float)(v58 - x)))
                                + (float)((float)(v60 - v62) * (float)(v60 - v62))) > (float)((float)((float)((float)(v34 - v61) * (float)(v34 - v61)) + (float)((float)(v33 - x) * (float)(v33 - x)))
                                                                                            + (float)((float)(v35 - v62) * (float)(v35 - v62)))) )
                    {
                      v60 = v35;
                      v59 = v34;
                      v58 = v33;
                    }
                    v64 = 1;
                  }
                  ++v24;
                  --v55;
                }
                while ( v55 != 0 );
                if ( v64 != 0 )
                {
                  v38 = (float)((float)((float)(v59 - v61) * (float)(v59 - v61))
                              + (float)((float)(v58 - x) * (float)(v58 - x)))
                      + (float)((float)(v60 - v62) * (float)(v60 - v62));
                  if ( paintinfo->m_flCurrentDistance > v38 )
                  {
                    paintinfo->m_flCurrentDistance = v38;
                    paintinfo->m_plane = v56;
                  }
                  v39 = paintinfo->m_aApplySurfs.m_Size;
                  m_nAllocationCount = paintinfo->m_aApplySurfs.m_Memory.m_nAllocationCount;
                  if ( v39 + 1 > m_nAllocationCount )
                    CUtlMemory<INetMessage *,int>::Grow(this: p_m_aApplySurfs, num: v39 - m_nAllocationCount + 1);
                  ++paintinfo->m_aApplySurfs.m_Size;
                  v41 = p_m_aApplySurfs->m_pMemory;
                  v42 = paintinfo->m_aApplySurfs.m_Size - v39 - 1;
                  paintinfo->m_aApplySurfs.m_pElements = paintinfo->m_aApplySurfs.m_Memory.m_pMemory;
                  if ( v42 > 0 )
                    _V_memmove(dest: &v41[v39 + 1], src: &v41[v39], count: 4 * v42);
                  v43 = &p_m_aApplySurfs->m_pMemory[v39];
                  if ( v43 != nullptr )
                    *v43 = (S3RGBA)v54;
                }
              }
            }
          }
        }
      }
      nummarksurfaces = pLeaf->nummarksurfaces;
      v2 = i + 1;
      i = v2;
    }
    while ( v2 < nummarksurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB100
// Name: void R_PaintNode(struct mnode_t __near *,struct paintinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_PaintNode(mnode_t *node, paintinfo_t *paintinfo)
{
  mnode_t *v2; // esi
  float v3; // xmm0_4
  float m_flSize; // xmm1_4

  v2 = node;
  if ( node != nullptr )
  {
    while ( v2->contents < 0 )
    {
      v3 = (float)((float)((float)(v2->plane->normal.y * paintinfo->m_vPosition.y)
                         + (float)(v2->plane->normal.x * paintinfo->m_vPosition.x))
                 + (float)(v2->plane->normal.z * paintinfo->m_vPosition.z))
         - v2->plane->dist;
      m_flSize = paintinfo->m_flSize;
      if ( v3 <= m_flSize )
      {
        if ( COERCE_FLOAT(LODWORD(m_flSize) ^ _mask__NegFloat_) <= v3 )
          R_PaintNode(node: v2->children[0], paintinfo);
        v2 = v2->children[1];
      }
      else
      {
        v2 = v2->children[0];
      }
      if ( v2 == nullptr )
        return;
    }
    R_PaintLeaf(pLeaf: (mleaf_t *)v2, paintinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB190
// Name: void TracePaintSphere(struct model_t const __near *,class Vector const __near &,class Vector const __near &,float,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TracePaintSphere(
        const model_t *pModel,
        const Vector *vPosition,
        const Vector *vContactNormal,
        float flSphereRadius,
        CUtlMemory<char,int> *surfColors)
{
  worldbrushdata_t *pShared; // ecx
  int firstnode; // eax
  int v7; // esi
  paintinfo_t paintinfo; // [esp+4h] [ebp-44h] BYREF
  int i; // [esp+44h] [ebp-4h]

  if ( g_PaintManager.m_bShouldRegister && g_PaintManager.m_pPaintTextureDataArray != nullptr && pModel != nullptr )
  {
    surfColors[1].m_pMemory = nullptr;
    pShared = pModel->brush.pShared;
    firstnode = pModel->brush.firstnode;
    paintinfo.m_vPosition = *vPosition;
    paintinfo.m_flSize = flSphereRadius;
    memset(&paintinfo.m_aApplySurfs, 0, 21);
    paintinfo.m_flCurrentDistance = 3.4028235e38;
    paintinfo.m_pBrush = pShared;
    R_PaintNode(node: &pShared->nodes[firstnode], &paintinfo);
    v7 = 0;
    for ( i = paintinfo.m_aApplySurfs.m_Size; v7 < i; ++v7 )
      GetPaintColorFromSurface(
        surfID: paintinfo.m_aApplySurfs.m_Memory.m_pMemory[v7],
        vPosition,
        vContactNormal,
        flSphereRadius,
        basePlane: &paintinfo.m_plane,
        surfColors);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&paintinfo.m_aApplySurfs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB280
// Name: void R_RedownloadAllPaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_RedownloadAllPaintmaps()
{
  int v0; // edx
  int v1; // ecx

  if ( g_PaintManager.m_bShouldRegister )
  {
    v0 = 0;
    if ( g_PaintManager.m_iPaintmaps > 0 )
    {
      v1 = 0;
      do
      {
        ++v0;
        g_PaintManager.m_pPaintTextureDataArray[v1++].m_nDirtyFlag = PAINTMAP_DIRTY_FULLRECT;
      }
      while ( v0 < g_PaintManager.m_iPaintmaps );
    }
    CPaintmapDataManager::UpdatePaintmapTextures(this: &g_PaintManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB2D0
// Name: void EncodeDataRLE(unsigned int const __near *,unsigned int,class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EncodeDataRLE(
        const unsigned int *pBuffer,
        int nDwordCount,
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *data)
{
  const unsigned int *v3; // ebx
  const unsigned int *v4; // esi
  const unsigned int *v5; // edi
  unsigned int v6; // ecx
  const unsigned int *v7; // eax
  unsigned int v8; // edi
  int v9; // edx
  int v10; // edi
  int v11; // ebx
  int *m_pMemory; // edx
  unsigned int *v13; // eax
  int *v14; // edi
  int *v15; // ecx
  int v16; // edx
  unsigned int *v17; // esi
  CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int> > v18; // [esp+4h] [ebp-1034h] BYREF
  unsigned int v19; // [esp+101Ch] [ebp-1Ch]
  int src; // [esp+1020h] [ebp-18h] BYREF
  int v21; // [esp+1024h] [ebp-14h]
  unsigned int v22; // [esp+1028h] [ebp-10h]
  const unsigned int *v23; // [esp+102Ch] [ebp-Ch]
  const unsigned int *v24; // [esp+1030h] [ebp-8h]
  int v25; // [esp+1034h] [ebp-4h] BYREF
  int num; // [esp+1044h] [ebp+Ch]

  if ( nDwordCount != 0 )
  {
    v18.m_Memory.m_pMemory = v18.m_Memory.m_pFixedMemory;
    v18.m_pElements = v18.m_Memory.m_pFixedMemory;
    v3 = &pBuffer[nDwordCount];
    v4 = pBuffer + 2;
    v5 = pBuffer;
    v21 = *pBuffer;
    v6 = pBuffer[1];
    v7 = pBuffer + 34;
    v18.m_Memory.m_nAllocationCount = 1024;
    v18.m_Memory.m_nGrowSize = -1;
    v18.m_Memory.m_nMallocGrowSize = 0;
    v18.m_Size = 0;
    v23 = pBuffer;
    v22 = v6;
    num = 0;
    v24 = pBuffer + 34;
    if ( pBuffer + 2 < v3 )
    {
      while ( 1 )
      {
        v8 = *v4;
        v19 = *v4;
        if ( v21 == v6 && v6 == v8 )
        {
          v9 = (int)(v4 - 2);
          v25 = (int)(v4 - 2);
          v10 = v4 - 2 - v23;
          src = v10;
          if ( v10 != 0 )
          {
            CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, &src);
            src = (int)v23;
            CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, &src);
            v7 = v24;
            num += v10 + 1;
            v9 = v25;
          }
          if ( ++v4 < v3 )
          {
            do
            {
              if ( *v4 != v21 )
                break;
              if ( ++v4 >= v7 && v7 < v3 - 256 )
                v7 += 32;
            }
            while ( v4 < v3 );
            v24 = v7;
          }
          v25 = -(((int)v4 - v9) >> 2);
          CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, src: &v25);
          v25 = v21;
          CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, src: &v25);
          num += 2;
          if ( v4 < v3 )
          {
            v19 = *v4;
            v22 = v19 + 1;
          }
          v6 = v22;
          v7 = v24;
          v8 = v19;
          v23 = v4;
        }
        ++v4;
        v21 = v6;
        v22 = v8;
        if ( v4 >= v7 && v7 < v3 - 256 )
        {
          v7 += 32;
          v24 = v7;
        }
        if ( v4 >= v3 )
          break;
        v6 = v22;
      }
      v5 = v23;
    }
    v11 = v3 - v5;
    v25 = v11;
    if ( v11 != 0 )
    {
      CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, src: &v25);
      v25 = (int)v5;
      CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, src: &v25);
      num += v11 + 1;
    }
    data->m_Size = 0;
    CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
      this: data,
      elem: 0,
      num);
    m_pMemory = v18.m_Memory.m_pMemory;
    v13 = (unsigned int *)data->m_Memory.m_pMemory;
    v14 = &v18.m_Memory.m_pMemory[v18.m_Size];
    v15 = v18.m_Memory.m_pMemory;
    if ( v18.m_Memory.m_pMemory < v14 )
    {
      do
      {
        v16 = *v15;
        *v13 = *v15;
        if ( v16 >= 0 )
        {
          v17 = (unsigned int *)v15[1];
          ++v13;
          v15 += 2;
          if ( v16 > 0 )
          {
            do
            {
              *v13++ = *v17++;
              --v16;
            }
            while ( v16 != 0 );
          }
        }
        else
        {
          v13[1] = v15[1];
          v13 += 2;
          v15 += 2;
        }
      }
      while ( v15 < v14 );
      m_pMemory = v18.m_Memory.m_pMemory;
    }
    v18.m_Size = 0;
    if ( v18.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        v18.m_Memory.m_pMemory = nullptr;
      }
      v18.m_Memory.m_nAllocationCount = 0;
    }
    v18.m_pElements = m_pMemory;
    if ( v18.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB560
// Name: public: void CPaintmapDataManager::GetPaintmapDataRLE(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::GetPaintmapDataRLE(
        CPaintmapDataManager *this,
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *data)
{
  worldbrushdata_t *worldbrush; // eax
  msurface2_t *v3; // eax
  CPaintTextureData *v4; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  unsigned int *v9; // edi
  int v10; // edi
  int v11; // eax
  unsigned int *v12; // ecx
  int v13; // eax
  unsigned int *v14; // eax
  int v15; // ecx
  unsigned int *v16; // edi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > rleData; // [esp+4h] [ebp-34h] BYREF
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > surfPaintData; // [esp+18h] [ebp-20h] BYREF
  CPaintmapDataManager *v19; // [esp+2Ch] [ebp-Ch]
  unsigned int v20; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  v19 = this;
  i = 0;
  if ( host_state.worldbrush->numsurfaces > 0 )
  {
    v20 = 0;
    do
    {
      v3 = &worldbrush->surfaces2[v20 / 0x20];
      if ( (v3->flags & 0x200000) != 0 )
      {
        v4 = &v19->m_pPaintTextureDataArray[materialSortInfoArray[v3->materialSortID].lightmapPageID];
        memset(&surfPaintData, 0, sizeof(surfPaintData));
        CPaintTextureData::GetSurfacePaintData(this: v4, surfID: v3, data: &surfPaintData);
        memset(&rleData, 0, sizeof(rleData));
        EncodeDataRLE(
          pBuffer: (const unsigned int *)surfPaintData.m_Memory.m_pMemory,
          nDwordCount: surfPaintData.m_Size / 4,
          data: &rleData);
        m_Size = data->m_Size;
        m_nAllocationCount = data->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)data,
            num: m_Size - m_nAllocationCount + 1);
        ++data->m_Size;
        m_pMemory = data->m_Memory.m_pMemory;
        v8 = data->m_Size - m_Size - 1;
        data->m_pElements = data->m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &data->m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = i;
        v10 = data->m_Size;
        v11 = data->m_Memory.m_nAllocationCount;
        if ( v10 + 1 > v11 )
          CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)data, num: v10 - v11 + 1);
        ++data->m_Size;
        v12 = data->m_Memory.m_pMemory;
        v13 = data->m_Size - v10 - 1;
        data->m_pElements = data->m_Memory.m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
        v14 = &data->m_Memory.m_pMemory[v10];
        v15 = rleData.m_Size;
        if ( v14 != nullptr )
          *v14 = rleData.m_Size;
        v16 = rleData.m_Memory.m_pMemory;
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
          this: data,
          elem: data->m_Size,
          num: v15,
          pToInsert: rleData.m_Memory.m_pMemory);
        if ( rleData.m_Memory.m_nGrowSize >= 0 && v16 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        if ( surfPaintData.m_Memory.m_nGrowSize >= 0 && surfPaintData.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfPaintData.m_Memory.m_pMemory);
      }
      worldbrush = host_state.worldbrush;
      v20 += 32;
      ++i;
    }
    while ( i < host_state.worldbrush->numsurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB7E0
// Name: public: void CPaintmapDataManager::RemovePaint(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::RemovePaint(CPaintmapDataManager *this, const model_t *pModel)
{
  const model_t *v2; // eax
  CPaintmapDataManager *v3; // esi
  msurface2_t *v4; // eax
  int materialSortID; // ecx
  msurfacelighting_t *surfacelighting; // edx
  unsigned int v7; // eax
  int v8; // edi
  CPaintTextureData *v9; // ecx
  __int16 *v10; // eax
  int v11; // edx
  int v12; // esi
  int v13; // edi
  int v14; // eax
  unsigned __int8 *v15; // esi
  CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *p_m_dirtyRects; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int v19; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v21; // eax
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v22; // ebx
  vgui::Panel *rect; // [esp+4h] [ebp-24h]
  vgui::Panel *rect_4; // [esp+8h] [ebp-20h]
  int rect_12; // [esp+10h] [ebp-18h]
  int v26; // [esp+14h] [ebp-14h]
  unsigned int count; // [esp+18h] [ebp-10h]
  int counta; // [esp+18h] [ebp-10h]
  int y; // [esp+20h] [ebp-8h]
  unsigned __int8 *ya; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v2 = pModel;
  v3 = this;
  if ( pModel != nullptr && this->m_pPaintTextureDataArray != nullptr )
  {
    i = 0;
    if ( pModel->brush.nummodelsurfaces > 0 )
    {
      while ( 1 )
      {
        v4 = &host_state.worldbrush->surfaces2[i + v2->brush.firstmodelsurface];
        materialSortID = v4->materialSortID;
        surfacelighting = host_state.worldbrush->surfacelighting;
        v7 = ((char *)v4 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
        v8 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v7);
        v9 = &v3->m_pPaintTextureDataArray[materialSortInfoArray[materialSortID].lightmapPageID];
        v10 = (__int16 *)((char *)surfacelighting->m_LightmapMins + v7);
        rect = (vgui::Panel *)v10[4];
        rect_4 = (vgui::Panel *)v10[5];
        v11 = v10[3] + 1;
        v12 = 0;
        v13 = v8 + 1;
        rect_12 = v11;
        for ( y = 0; v12 < v11; y = v12 )
        {
          v14 = 0;
          if ( v13 > 0 )
          {
            count = (unsigned int)rect_4 + v12;
            do
            {
              v15 = &v9->m_backbuffer[count * v9->m_nPaintWidth + v14++];
              *((_BYTE *)&rect->__vftable + (_DWORD)v15) = 0x80;
            }
            while ( v14 < v13 );
            v12 = y;
          }
          ++v12;
        }
        p_m_dirtyRects = (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&v9->m_dirtyRects;
        v9->m_nDirtyFlag = (v9->m_nDirtyFlag == PAINTMAP_DIRTY_FULLRECT) + 1;
        m_Size = v9->m_dirtyRects.m_Size;
        m_nAllocationCount = v9->m_dirtyRects.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          v19 = m_Size - m_nAllocationCount + 1;
          v26 = v19;
          if ( p_m_dirtyRects->m_nGrowSize < 0 )
          {
            p_m_dirtyRects->m_nGrowSize = (int)p_m_dirtyRects[1].m_pMemory;
            if ( m_nAllocationCount != 0 )
            {
              counta = 16 * m_nAllocationCount;
              ya = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nAllocationCount);
              memcpy(dst: ya, src: (unsigned __int8 *)p_m_dirtyRects->m_pMemory, count: counta);
              v19 = v26;
              p_m_dirtyRects->m_pMemory = (UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *)ya;
            }
            else
            {
              p_m_dirtyRects->m_pMemory = nullptr;
            }
          }
          CUtlMemory<CPortalRect,int>::Grow(this: p_m_dirtyRects, num: v19);
          v11 = rect_12;
        }
        ++p_m_dirtyRects[1366].m_nGrowSize;
        m_pMemory = (unsigned __int8 *)p_m_dirtyRects->m_pMemory;
        v21 = p_m_dirtyRects[1366].m_nGrowSize - m_Size - 1;
        p_m_dirtyRects[1367].m_pMemory = p_m_dirtyRects->m_pMemory;
        if ( v21 > 0 )
        {
          _V_memmove(dest: &m_pMemory[16 * m_Size + 16], src: &m_pMemory[16 * m_Size], count: 16 * v21);
          v11 = rect_12;
        }
        v22 = &p_m_dirtyRects->m_pMemory[m_Size];
        if ( v22 != nullptr )
        {
          v22->m_Element.panel = rect;
          v22->m_Element.labelPanel = rect_4;
          v22->m_Previous = v13;
          v22->m_Next = v11;
        }
        if ( ++i >= pModel->brush.nummodelsurfaces )
          break;
        v3 = this;
        v2 = pModel;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB9A0
// Name: public: virtual void CPaintmapDataManager::BeginPaintmapsDataAllocation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::BeginPaintmapsDataAllocation(
        CPaintmapDataManager *this,
        unsigned int iPaintmapCount)
{
  int v3; // ecx
  unsigned int *v4; // eax
  CPaintTextureData *v5; // eax
  int v6; // esi
  CPaintTextureData *v7; // ecx
  Rect_t *m_pFixedMemory; // eax
  int iPaintmapCounta; // [esp+10h] [ebp+8h]

  this->DestroyPaintmapsData(this);
  this->m_iPaintmaps = iPaintmapCount;
  v3 = (16428 * (unsigned __int64)iPaintmapCount) >> 32 != 0 ? -1 : 16428 * iPaintmapCount;
  v4 = (unsigned int *)MemAlloc_Alloc(nSize: __CFADD__(v3, 4) ? -1 : v3 + 4);
  if ( v4 != nullptr )
  {
    *v4 = iPaintmapCount;
    v5 = (CPaintTextureData *)(v4 + 1);
    v6 = iPaintmapCount - 1;
    iPaintmapCounta = (int)v5;
    v7 = v5;
    if ( v6 >= 0 )
    {
      m_pFixedMemory = v5->m_dirtyRects.m_Memory.m_pFixedMemory;
      do
      {
        m_pFixedMemory[-1].x = (int)m_pFixedMemory;
        m_pFixedMemory[-1].y = 1024;
        m_pFixedMemory[-1].width = -1;
        m_pFixedMemory[-1].height = 0;
        m_pFixedMemory[1024].x = 0;
        m_pFixedMemory[1024].y = (int)m_pFixedMemory;
        m_pFixedMemory[-2].x = 0;
        v7->m_nPaintWidth = 0;
        m_pFixedMemory[-2].width = 0;
        m_pFixedMemory[-2].height = 0;
        ++v7;
        m_pFixedMemory = (Rect_t *)((char *)m_pFixedMemory + 16428);
        --v6;
      }
      while ( v6 >= 0 );
      v5 = (CPaintTextureData *)iPaintmapCounta;
    }
    this->m_pPaintTextureDataArray = v5;
  }
  else
  {
    this->m_pPaintTextureDataArray = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CBA50
// Name: public: bool CPaintTextureData::Paint(struct PaintRect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPaintTextureData::Paint(CPaintTextureData *this, const PaintRect_t *paintRect)
{
  unsigned int v3; // eax
  char v4; // bl
  int y; // ecx
  int width; // edx
  int height; // eax
  msurface2_t *surfID; // ecx
  int v9; // ecx
  msurfacelighting_t *surfacelighting; // edx
  int v11; // edi
  char *v12; // eax
  int v13; // ecx
  int v14; // edx
  int x; // eax
  CPaintTextureData *v16; // eax
  Rect_t rect; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int nChangeFlags; // [esp+1Ch] [ebp-Ch]
  CPaintTextureData *v20; // [esp+20h] [ebp-8h]
  int tMax; // [esp+24h] [ebp-4h]

  v20 = this;
  v3 = CPaintTextureData::DrawCircle(this, paintRect);
  v4 = v3;
  nChangeFlags = v3;
  if ( (v3 & 1) == 0 )
    return (v4 & 2) != 0;
  if ( paint_alpha_offset_enabled.m_pParent == nullptr
    || paint_alpha_offset_enabled.m_pParent->m_Value.m_nValue == 0
    || paintRect->colorIndex == 4 )
  {
    this->m_nDirtyFlag = (this->m_nDirtyFlag == PAINTMAP_DIRTY_FULLRECT) + 1;
    CUtlVector<Rect_t,CUtlMemoryFixedGrowable<Rect_t,1024,int>>::InsertBefore(
      this: &this->m_dirtyRects,
      elem: this->m_dirtyRects.m_Size,
      src: &paintRect->rect);
    return (v4 & 2) != 0;
  }
  y = paintRect->rect.y;
  width = paintRect->rect.width;
  rect.x = paintRect->rect.x;
  height = paintRect->rect.height;
  rect.y = y;
  surfID = paintRect->surfID;
  rect.height = height;
  v9 = (char *)surfID - (char *)host_state.worldbrush->surfaces2;
  rect.width = width;
  surfacelighting = host_state.worldbrush->surfacelighting;
  v9 &= 0xFFFFFFE0;
  v11 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v9);
  v12 = (char *)surfacelighting + v9;
  v13 = *(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v9);
  v14 = *((__int16 *)v12 + 5);
  tMax = *((__int16 *)v12 + 3);
  x = paintRect->rect.x;
  if ( paintRect->rect.x > v13 )
  {
    --rect.x;
    ++rect.width;
  }
  if ( paintRect->rect.y > v14 )
  {
    --rect.y;
    ++rect.height;
  }
  if ( paintRect->rect.width + x - 1 < v13 + v11 )
    ++rect.width;
  if ( paintRect->rect.height + paintRect->rect.y - 1 < v14 + tMax )
    ++rect.height;
  v16 = v20;
  v20->m_nDirtyFlag = (v20->m_nDirtyFlag == PAINTMAP_DIRTY_FULLRECT) + 1;
  CUtlVector<Rect_t,CUtlMemoryFixedGrowable<Rect_t,1024,int>>::InsertBefore(
    this: &v16->m_dirtyRects,
    elem: v16->m_dirtyRects.m_Size,
    src: &rect);
  return (nChangeFlags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CBB80
// Name: public: void CPaintTextureData::SetSurfacePaintData(struct msurface2_t __near *,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintTextureData::SetSurfacePaintData(
        CPaintTextureData *this,
        msurface2_t *surfID,
        const CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *data)
{
  unsigned __int8 *m_backbuffer; // eax
  __int16 *v4; // eax
  int v5; // edx
  unsigned __int8 *m_pMemory; // ebx
  unsigned __int8 *v7; // esi
  int v8; // edi
  char *v9; // esi
  BOOL v10; // eax
  CUtlVectorFixedGrowable<Rect_t,1024> *p_m_dirtyRects; // ecx
  Rect_t rect; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 *v13; // [esp+10h] [ebp-8h]
  CPaintTextureData *v14; // [esp+14h] [ebp-4h]
  const unsigned __int8 *pEnd; // [esp+24h] [ebp+Ch]

  m_backbuffer = this->m_backbuffer;
  v14 = this;
  v13 = m_backbuffer;
  if ( m_backbuffer != nullptr )
  {
    v4 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                   + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
    v5 = v4[4];
    rect.y = v4[5];
    m_pMemory = data->m_Memory.m_pMemory;
    v7 = &v13[rect.y * this->m_nPaintWidth];
    v8 = v4[2] + 1;
    rect.height = v4[3] + 1;
    v9 = (char *)&v7[v5];
    rect.x = v5;
    rect.width = v8;
    for ( pEnd = &m_pMemory[v8 * rect.height]; m_pMemory < pEnd; m_pMemory += v8 )
    {
      _V_memcpy(dest: v9, src: m_pMemory, count: v8);
      this = v14;
      v9 += v14->m_nPaintWidth;
    }
    v10 = this->m_nDirtyFlag == PAINTMAP_DIRTY_FULLRECT;
    p_m_dirtyRects = &this->m_dirtyRects;
    p_m_dirtyRects[-1].m_pElements = (Rect_t *)(v10 + 1);
    CUtlVector<Rect_t,CUtlMemoryFixedGrowable<Rect_t,1024,int>>::InsertBefore(
      this: p_m_dirtyRects,
      elem: p_m_dirtyRects->m_Size,
      src: &rect);
    surfID->flags |= 0x200000u;
    MarkSurfaceBrushes(nSurfIndex: surfID - host_state.worldbrush->surfaces2, pData: host_state.worldbrush);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CBC50
// Name: public: void CPaintmapDataManager::LoadPaintmapDataRLE(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::LoadPaintmapDataRLE(CPaintmapDataManager *this, unsigned int data)
{
  unsigned int *v2; // edi
  const unsigned int *v3; // eax
  msurface2_t *v4; // ebx
  const unsigned int *v5; // edi
  char *v6; // ecx
  int v7; // eax
  unsigned __int8 *m_pMemory; // edx
  int v9; // esi
  bool v10; // zf
  int v11; // esi
  int m_Size; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > rawPaintData; // [esp+4h] [ebp-20h] BYREF
  const unsigned int *pEnd; // [esp+18h] [ebp-Ch]
  CPaintmapDataManager *v15; // [esp+1Ch] [ebp-8h]
  int lightmapID; // [esp+20h] [ebp-4h]
  unsigned int nRLESize; // [esp+2Ch] [ebp+8h]

  v2 = *(unsigned int **)data;
  v3 = (const unsigned int *)(*(_DWORD *)data + 4 * *(_DWORD *)(data + 12));
  v15 = this;
  pEnd = v3;
  while ( v2 < pEnd )
  {
    v4 = &host_state.worldbrush->surfaces2[*v2];
    v5 = v2 + 2;
    nRLESize = *(v5 - 1);
    v6 = (char *)host_state.worldbrush->surfacelighting
       + (((char *)v4 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
    v7 = (*((__int16 *)v6 + 2) + 1) * (*((__int16 *)v6 + 3) + 1);
    lightmapID = materialSortInfoArray[v4->materialSortID].lightmapPageID;
    m_pMemory = nullptr;
    memset(&rawPaintData, 0, sizeof(rawPaintData));
    v9 = (4 - v7 % 4) % 4;
    v10 = v7 + v9 == 0;
    v11 = v7 + v9;
    m_Size = 0;
    if ( !v10 )
    {
      if ( v11 > 0 )
      {
        CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&rawPaintData, num: v11);
        m_Size = rawPaintData.m_Size;
        m_pMemory = rawPaintData.m_Memory.m_pMemory;
      }
      rawPaintData.m_Size = v11 + m_Size;
      rawPaintData.m_pElements = m_pMemory;
      if ( m_Size > 0 && v11 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v11], src: m_pMemory, count: m_Size);
        m_pMemory = rawPaintData.m_Memory.m_pMemory;
      }
    }
    DecodeDataRLE(
      pRLEStart: v5,
      rleCount: nRLESize,
      surfID: v4,
      pOutput: (unsigned int *)m_pMemory,
      nDwordCount: (unsigned int)v11 >> 2);
    v2 = (unsigned int *)&v5[nRLESize];
    CPaintTextureData::SetSurfacePaintData(
      this: &v15->m_pPaintTextureDataArray[lightmapID],
      surfID: v4,
      data: &rawPaintData);
    if ( rawPaintData.m_Memory.m_nGrowSize >= 0 && rawPaintData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rawPaintData.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CBD90
// Name: bool R_PaintSurface(struct msurface2_t __near *,class Vector const __near &,float,class VPlane const __near &,unsigned char,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl R_PaintSurface(
        msurface2_t *surfID,
        const Vector *vPosition,
        float flSphereRadius,
        const VPlane *basePlane,
        unsigned __int8 colorIndex,
        float flPaintCoatPercent)
{
  int lightmapPageID; // edi
  PaintRect_t paintRect; // [esp+0h] [ebp-2Ch] BYREF
  int _2C; // [esp+2Ch] [ebp+0h] BYREF

  lightmapPageID = materialSortInfoArray[surfID->materialSortID].lightmapPageID;
  paintRect.colorIndex = colorIndex;
  paintRect.flPaintCoatPercent = flPaintCoatPercent;
  if ( !ComputePaintRect(a1: COERCE_FLOAT(&_2C), surfID, vPosition, flSphereRadius, &paintRect)
    || !CPaintTextureData::Paint(this: &g_PaintManager.m_pPaintTextureDataArray[lightmapPageID], &paintRect) )
  {
    return 0;
  }
  surfID->flags |= 0x200000u;
  MarkSurfaceBrushes(nSurfIndex: surfID - host_state.worldbrush->surfaces2, pData: host_state.worldbrush);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CBE20
// Name: bool ShootPaintSphere(struct model_t const __near *,class Vector const __near &,unsigned char,float,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShootPaintSphere(
        const model_t *pModel,
        const Vector *vPosition,
        unsigned __int8 colorIndex,
        float flSphereRadius,
        float flPaintCoatPercent)
{
  char v5; // bl
  worldbrushdata_t *pShared; // ecx
  int firstnode; // eax
  int v8; // edi
  paintinfo_t paintinfo; // [esp+1Ch] [ebp-44h] BYREF
  int i; // [esp+5Ch] [ebp-4h]

  v5 = 0;
  if ( !g_PaintManager.m_bShouldRegister || g_PaintManager.m_pPaintTextureDataArray == nullptr || pModel == nullptr )
    return 0;
  pShared = pModel->brush.pShared;
  firstnode = pModel->brush.firstnode;
  paintinfo.m_vPosition = *vPosition;
  paintinfo.m_flSize = flSphereRadius;
  memset(&paintinfo.m_aApplySurfs, 0, sizeof(paintinfo.m_aApplySurfs));
  paintinfo.m_flCurrentDistance = 3.4028235e38;
  paintinfo.m_pBrush = pShared;
  paintinfo.m_bPainting = true;
  R_PaintNode(node: &pShared->nodes[firstnode], &paintinfo);
  v8 = 0;
  for ( i = paintinfo.m_aApplySurfs.m_Size; v8 < i; ++v8 )
  {
    if ( IsSurfaceInFrontOfPlane(surfID: paintinfo.m_aApplySurfs.m_Memory.m_pMemory[v8], plane: &paintinfo.m_plane)
      && R_PaintSurface(
           surfID: paintinfo.m_aApplySurfs.m_Memory.m_pMemory[v8],
           vPosition,
           flSphereRadius,
           basePlane: &paintinfo.m_plane,
           colorIndex,
           flPaintCoatPercent) != 0 )
    {
      v5 = 1;
    }
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&paintinfo.m_aApplySurfs);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101CBF30
// Name: public: virtual void CPaintmapDataManager::DestroyPaintmapsData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::DestroyPaintmapsData(CPaintmapDataManager *this)
{
  int v2; // ebx
  CPaintTextureData *m_pPaintTextureDataArray; // esi
  CPaintTextureData *v4; // ecx
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( this->m_pPaintTextureDataArray != nullptr )
  {
    for ( i = 0; i != this->m_iPaintmaps; ++i )
    {
      m_pPaintTextureDataArray = this->m_pPaintTextureDataArray;
      if ( m_pPaintTextureDataArray[v2].m_backbuffer != nullptr )
      {
        free(pMem: m_pPaintTextureDataArray[v2].m_backbuffer);
        m_pPaintTextureDataArray[v2].m_backbuffer = nullptr;
      }
      ++v2;
    }
    v4 = this->m_pPaintTextureDataArray;
    if ( v4 != nullptr )
      CPaintTextureData::`vector deleting destructor'(this: v4, a2: 3u);
    this->m_pPaintTextureDataArray = nullptr;
    this->m_iPaintmaps = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027B7F0
// Name: public: virtual void CFunctor4<void (*)(class Vector const __near &,class Vector const __near &,class Color,bool),class Vector,class Vector,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor4<void (__cdecl *)(Vector const &,Vector const &,Color,bool),Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor4<void (__cdecl*)(Vector const &,Vector const &,Color,bool),Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, Vector *, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: *(_DWORD *)&this->m_arg3,
    a4: this->m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x1031D260
// Name: _dynamic_initializer_for__paint_max_surface_border_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__paint_max_surface_border_alpha__()
{
  ConVar::ConVar(
    this: &paint_max_surface_border_alpha,
    pName: "paint_max_surface_border_alpha",
    pDefaultValue: "0.7f",
    flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__paint_max_surface_border_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D290
// Name: _dynamic_initializer_for__paint_alpha_offset_enabled__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__paint_alpha_offset_enabled__()
{
  ConVar::ConVar(
    this: &paint_alpha_offset_enabled,
    pName: "paint_alpha_offset_enabled",
    pDefaultValue: "1",
    flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__paint_alpha_offset_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D350
// Name: _dynamic_initializer_for__paint_min_valid_alpha_value__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__paint_min_valid_alpha_value__()
{
  ConVar::ConVar(
    this: &paint_min_valid_alpha_value,
    pName: "paint_min_valid_alpha_value",
    pDefaultValue: "0.7f",
    flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__paint_min_valid_alpha_value__);
}

//------------------------------------------------------------------------------
// Address: 0x103265A0
// Name: _dynamic_atexit_destructor_for__paint_max_surface_border_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paint_max_surface_border_alpha__()
{
  ConVar::~ConVar(this: &paint_max_surface_border_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x103265B0
// Name: _dynamic_atexit_destructor_for__paint_alpha_offset_enabled__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paint_alpha_offset_enabled__()
{
  ConVar::~ConVar(this: &paint_alpha_offset_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103265F0
// Name: _dynamic_atexit_destructor_for__paint_min_valid_alpha_value__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paint_min_valid_alpha_value__()
{
  ConVar::~ConVar(this: &paint_min_valid_alpha_value);
}

//------------------------------------------------------------------------------
// Address: 0x1031D2C0
// Name: _dynamic_initializer_for__paintsplat_bias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__paintsplat_bias__()
{
  ConVar::ConVar(
    this: &paintsplat_bias,
    pName: "paintsplat_bias",
    pDefaultValue: "0.1f",
    flags: 24576,
    pHelpString: "Change bias value for computing circle buffer");
  return atexit(func: dynamic_atexit_destructor_for__paintsplat_bias__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D2F0
// Name: _dynamic_initializer_for__paintsplat_noise_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__paintsplat_noise_enabled__()
{
  ConVar::ConVar(this: &paintsplat_noise_enabled, pName: "paintsplat_noise_enabled", pDefaultValue: "1", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__paintsplat_noise_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D320
// Name: _dynamic_initializer_for__paintsplat_max_alpha_noise__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__paintsplat_max_alpha_noise__()
{
  ConVar::ConVar(
    this: &paintsplat_max_alpha_noise,
    pName: "paintsplat_max_alpha_noise",
    pDefaultValue: "0.1f",
    flags: 24576,
    pHelpString: "Max noise value of circle alpha");
  return atexit(func: dynamic_atexit_destructor_for__paintsplat_max_alpha_noise__);
}

//------------------------------------------------------------------------------
// Address: 0x103265C0
// Name: _dynamic_atexit_destructor_for__paintsplat_bias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paintsplat_bias__()
{
  ConVar::~ConVar(this: &paintsplat_bias);
}

//------------------------------------------------------------------------------
// Address: 0x103265D0
// Name: _dynamic_atexit_destructor_for__paintsplat_noise_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paintsplat_noise_enabled__()
{
  ConVar::~ConVar(this: &paintsplat_noise_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103265E0
// Name: _dynamic_atexit_destructor_for__paintsplat_max_alpha_noise__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paintsplat_max_alpha_noise__()
{
  ConVar::~ConVar(this: &paintsplat_max_alpha_noise);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100D9100
// Name: public: void ICallQueue::QueueCall<class IMDLCache __near *,class IMDLCache,void>(class IMDLCache __near *,void (IMDLCache::*)(void))
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<IMDLCache *,IMDLCache,void>(
        ICallQueue *this,
        IMDLCache *pObject,
        void (__thiscall *pfnProxied)(IMDLCache *this))
{
  CFunctor *v4; // eax

  v4 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMDLCache *,void (__thiscall IMDLCache::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMDLCache *,void (__thiscall IMDLCache::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4[2].m_nUserID = (unsigned int)pObject;
    this->QueueFunctorInternal(this, a2: v4);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFF00
// Name: public: CUtlMemoryFixedGrowable<struct LightingState_t,256,int>::CUtlMemoryFixedGrowable<struct LightingState_t,256,int>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemoryFixedGrowable<LightingState_t,256,int> *__thiscall CUtlMemoryFixedGrowable<LightingState_t,256,int>::CUtlMemoryFixedGrowable<LightingState_t,256,int>(
        CUtlMemoryFixedGrowable<LightingState_t,256,int> *this,
        int nGrowSize,
        int nInitSize)
{
  LightingState_t *m_pFixedMemory; // edi
  int v4; // ebx
  float *p_z; // esi

  m_pFixedMemory = this->m_pFixedMemory;
  this->m_pMemory = this->m_pFixedMemory;
  this->m_nAllocationCount = 256;
  this->m_nGrowSize = -1;
  v4 = 255;
  p_z = &this->m_pFixedMemory[0].r_boxcolor[1].z;
  do
  {
    `vector constructor iterator'(
      __t: m_pFixedMemory,
      __s: 0xCu,
      __n: 6,
      __f: (void *(__thiscall *)(void *))Vector2D::Vector2D);
    m_pFixedMemory->r_boxcolor[0].x = 0.0;
    *(p_z - 2) = 0.0;
    *(p_z - 4) = 0.0;
    *(p_z - 3) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    p_z[5] = 0.0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    p_z[9] = 0.0;
    p_z[10] = 0.0;
    p_z[11] = 0.0;
    *((_QWORD *)p_z + 6) = 0;
    ++m_pFixedMemory;
    p_z += 23;
    --v4;
  }
  while ( v4 >= 0 );
  this->m_nMallocGrowSize = nGrowSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E0B40
// Name: public: void ICallQueue::QueueCall<class CModelRender __near *,class CModelRender,void,int,struct memhandle_t__ __near * __near *,int,struct memhandle_t__ __near * __near *>(class CModelRender __near *,void (CModelRender::*)(int,struct memhandle_t__ __near * __near *),int const __near &,struct memhandle_t__ __near * __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CModelRender *,CModelRender,void,int,memhandle_t__ * *,int,memhandle_t__ * *>(
        ICallQueue *this,
        CFunctor_vtbl *pObject,
        void (__thiscall *__ptr64 pfnProxied)(CModelRender *this, int, memhandle_t__ **),
        CFunctor_vtbl **arg1,
        memhandle_t__ **const *arg2)
{
  CFunctor *v6; // eax

  v6 = (CFunctor *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v6 != nullptr )
  {
    v6[1].m_nUserID = 1;
    v6->__vftable = (CFunctor_vtbl *)&CMemberFunctor2<CModelRender *,void (__thiscall CModelRender::*)(int,memhandle_t__ * *),int,memhandle_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v6[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor2<CModelRender *,void (__thiscall CModelRender::*)(int,memhandle_t__ * *),int,memhandle_t__ * *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v6[2] = (CFunctor)pfnProxied;
    v6[3].__vftable = pObject;
    v6[4].__vftable = *arg1;
    v6[4].m_nUserID = (unsigned int)*arg2;
    this->QueueFunctorInternal(this, a2: v6);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0BB0
// Name: public: void ICallQueue::QueueCall<class CModelRender __near *,class CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>,int,struct memhandle_t__ __near *,struct memhandle_t__ __near *>(class CModelRender __near *,int (CManagedDataCacheClient<class CColorMeshData,struct colormeshparams_t,class CColorMeshData __near *>::*)(struct memhandle_t__ __near *),struct memhandle_t__ __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CModelRender *,CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>,int,memhandle_t__ *,memhandle_t__ *>(
        ICallQueue *this,
        CModelRender *pObject,
        int (__thiscall *pfnProxied)(CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *> *this, memhandle_t__ *),
        CFunctor_vtbl **arg1)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CModelRender *,int (__thiscall CManagedDataCacheClient<CColorMeshData,colormeshparams_t,CColorMeshData *>::*)(memhandle_t__ *),memhandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5[2].m_nUserID = (unsigned int)pObject;
    v5[3].__vftable = *arg1;
    this->QueueFunctorInternal(this, a2: v5);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102B10
// Name: public: void ICallQueue::QueueCall<void,struct msurface2_t __near *,class Vector,struct msurface2_t __near *,class Vector>(void (*)(struct msurface2_t __near *,class Vector),struct msurface2_t __near * const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,msurface2_t *,Vector,msurface2_t *,Vector>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(msurface2_t *, Vector),
        msurface2_t *const *arg1,
        const Vector *arg2)
{
  CFunctor *v5; // eax

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v5 != nullptr )
  {
    v5[1].m_nUserID = 1;
    v5[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v5->__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(msurface2_t *,Vector),msurface2_t *,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(msurface2_t *,Vector),msurface2_t *,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2].m_nUserID = (unsigned int)*arg1;
    *(Vector *)&v5[3].__vftable = *arg2;
    this->QueueFunctorInternal(this, a2: v5);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102B80
// Name: public: void ICallQueue::QueueCall<void,bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float,bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float>(void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool const __near &,int const __near &,class Vector const __near &,int const __near &,struct decal_t __near * __near * const __near &,int const __near &,int const __near &,int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,bool,int,Vector,int,decal_t * *,int,int,int,float,bool,int,Vector,int,decal_t * *,int,int,int,float>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(bool, int, Vector, int, decal_t **, int, int, int, float),
        const bool *arg1,
        const int *arg2,
        const Vector *arg3,
        const int *arg4,
        decal_t **const *arg5,
        const int *arg6,
        const int *arg7,
        const int *arg8,
        const float *arg9)
{
  CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *v12; // eax
  CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *v13; // eax

  v12 = (CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v12 != nullptr )
  {
    v13 = CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>(
            this: v12,
            pfnProxied,
            arg1,
            arg2,
            arg3,
            arg4,
            arg5,
            arg6,
            arg7,
            arg8,
            arg9);
    this->QueueFunctorInternal(this, a2: v13);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116230
// Name: public: void ICallQueue::QueueCall<void,int,struct BrushArrayInstanceData_t const __near *,int,int,struct BrushArrayInstanceData_t const __near *,int>(void (*)(int,struct BrushArrayInstanceData_t const __near *,int),int const __near &,struct BrushArrayInstanceData_t const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,int,BrushArrayInstanceData_t const *,int,int,BrushArrayInstanceData_t const *,int>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(int, const BrushArrayInstanceData_t *, int),
        unsigned int *arg1,
        CFunctor_vtbl **arg2,
        unsigned int *arg3)
{
  CFunctor *v6; // eax

  v6 = (CFunctor *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v6 != nullptr )
  {
    v6[1].m_nUserID = 1;
    v6[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v6->__vftable = (CFunctor_vtbl *)&CFunctor3<void (__cdecl *)(int,BrushArrayInstanceData_t const *,int),int,BrushArrayInstanceData_t const *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v6[1].__vftable = (CFunctor_vtbl *)&CFunctor3<void (__cdecl *)(int,BrushArrayInstanceData_t const *,int),int,BrushArrayInstanceData_t const *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v6[2].m_nUserID = *arg1;
    v6[3].__vftable = *arg2;
    v6[3].m_nUserID = *arg3;
    this->QueueFunctorInternal(this, a2: v6);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8AB0
// Name: void R_UpdatePaintmapRect(int,unsigned char __near *,int,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_UpdatePaintmapRect(int paintmap, unsigned __int8 *pPaintData, int numRects, Rect_t *pRects)
{
  materials->UpdatePaintmap(this: materials, a2: paintmap, a3: pPaintData, a4: numRects, a5: pRects);
}

//------------------------------------------------------------------------------
// Address: 0x101C8AE0
// Name: public: virtual unsigned char __near * CPaintmapDataManager::GetPaintmapData(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CPaintmapDataManager::GetPaintmapData(CPaintmapDataManager *this, int paintmap)
{
  if ( paintmap < 0 || paintmap >= this->m_iPaintmaps )
    return nullptr;
  else
    return this->m_pPaintTextureDataArray[paintmap].m_backbuffer;
}

//------------------------------------------------------------------------------
// Address: 0x101C8B10
// Name: void DecodeDataRLE(unsigned int const __near *,unsigned int,struct msurface2_t __near *,unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecodeDataRLE(
        const unsigned int *pRLEStart,
        unsigned int rleCount,
        msurface2_t *surfID,
        unsigned int *pOutput)
{
  const unsigned int *v4; // edx
  const unsigned int *v5; // ecx
  int v7; // eax
  signed int v8; // ebx
  int v9; // eax
  const unsigned int *pEndOfData; // [esp+8h] [ebp+8h]

  v4 = pRLEStart;
  v5 = &pRLEStart[rleCount];
  pEndOfData = v5;
  while ( v4 < v5 )
  {
    v7 = *v4++;
    if ( v7 >= 0 )
    {
      if ( v7 > 0 )
      {
        do
        {
          *pOutput++ = *v4++;
          --v7;
        }
        while ( v7 != 0 );
      }
    }
    else
    {
      v8 = -v7;
      v9 = *v4++;
      if ( v8 > 0 )
      {
        memset32(pOutput, v9, v8);
        v5 = pEndOfData;
        pOutput += v8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8B70
// Name: class Vector FindClosestPointToTriangle(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl FindClosestPointToTriangle(
        Vector *result,
        const Vector *p,
        const Vector *a,
        const Vector *b,
        const Vector *c)
{
  float x; // xmm1_4
  float z; // xmm4_4
  float v10; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float y; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v19; // edx
  float v20; // ecx
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // ecx
  float v24; // edx
  float v25; // edx
  float v26; // ecx
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm5_4
  float v36; // xmm2_4
  float v37; // [esp+10h] [ebp-60h]
  float bc; // [esp+18h] [ebp-58h]
  float bc_4; // [esp+1Ch] [ebp-54h]
  float bc_8; // [esp+20h] [ebp-50h]
  float ab; // [esp+24h] [ebp-4Ch]
  float ab_4; // [esp+28h] [ebp-48h]
  float ab_8; // [esp+2Ch] [ebp-44h]
  float n; // [esp+30h] [ebp-40h]
  float n_4; // [esp+34h] [ebp-3Ch]
  float n_8; // [esp+38h] [ebp-38h]
  float ac; // [esp+3Ch] [ebp-34h]
  float ac_4; // [esp+40h] [ebp-30h]
  float ac_8; // [esp+44h] [ebp-2Ch]
  float tpC; // [esp+48h] [ebp-28h]
  float v51; // [esp+4Ch] [ebp-24h]
  float tpA; // [esp+54h] [ebp-1Ch]
  float tpAa; // [esp+54h] [ebp-1Ch]
  float projACdenom; // [esp+58h] [ebp-18h]
  float projACnom; // [esp+5Ch] [ebp-14h]
  float v56; // [esp+60h] [ebp-10h]
  float v57; // [esp+60h] [ebp-10h]
  float projBCnom; // [esp+64h] [ebp-Ch]
  float projABdenom; // [esp+68h] [ebp-8h]
  float projABdenoma; // [esp+68h] [ebp-8h]
  float projABnom; // [esp+6Ch] [ebp-4h]
  float projABnoma; // [esp+6Ch] [ebp-4h]
  float pa; // [esp+7Ch] [ebp+Ch]
  float ad; // [esp+80h] [ebp+10h]
  float aa; // [esp+80h] [ebp+10h]
  float bb; // [esp+84h] [ebp+14h]
  float ba; // [esp+84h] [ebp+14h]
  float cb; // [esp+88h] [ebp+18h]
  float cc; // [esp+88h] [ebp+18h]
  float ca; // [esp+88h] [ebp+18h]

  x = b->x;
  z = b->z;
  v10 = c->z - z;
  v12 = a->z;
  v13 = a->x;
  ab_8 = z - v12;
  v14 = c->x;
  ac = c->x - a->x;
  ab = b->x - a->x;
  y = a->y;
  ac_4 = c->y - y;
  ac_8 = c->z - v12;
  ab_4 = b->y - y;
  bc_8 = v10;
  bc = c->x - b->x;
  bc_4 = c->y - b->y;
  cb = p->x - a->x;
  v16 = p->y;
  ad = p->z;
  v56 = p->x - b->x;
  projABnom = (float)((float)((float)(v16 - y) * ab_4) + (float)(cb * (float)(b->x - v13)))
            + (float)((float)(ad - v12) * ab_8);
  projABdenom = (float)((float)(v56 * (float)(v13 - b->x)) + (float)((float)(v16 - b->y) * (float)(y - b->y)))
              + (float)((float)(ad - b->z) * (float)(v12 - b->z));
  v37 = y - c->y;
  projACnom = (float)((float)((float)(v16 - y) * ac_4) + (float)(cb * ac)) + (float)((float)(ad - v12) * ac_8);
  v17 = p->x - v14;
  projACdenom = (float)((float)(v17 * (float)(v13 - v14)) + (float)((float)(v16 - c->y) * v37))
              + (float)((float)(ad - c->z) * (float)(v12 - c->z));
  if ( projABnom <= 0.0 && projACnom <= 0.0 )
  {
    v19 = a->y;
    result->x = a->x;
    v20 = a->z;
    result->y = v19;
    result->z = v20;
    return result;
  }
  bb = b->y;
  v21 = p->y;
  cc = p->z;
  projBCnom = (float)((float)((float)(v21 - bb) * bc_4) + (float)(v56 * bc)) + (float)((float)(cc - b->z) * bc_8);
  v22 = (float)((float)(v17 * (float)(x - v14)) + (float)((float)(v21 - c->y) * (float)(bb - c->y)))
      + (float)((float)(cc - c->z) * (float)(b->z - c->z));
  if ( projABdenom <= 0.0 && projBCnom <= 0.0 )
  {
    result->x = b->x;
    v23 = b->y;
    v24 = b->z;
    result->y = v23;
    result->z = v24;
    return result;
  }
  if ( projACdenom <= 0.0 && v22 <= 0.0 )
  {
    result->x = c->x;
    v25 = c->y;
    v26 = c->z;
    result->y = v25;
    result->z = v26;
    return result;
  }
  n = (float)(ac_8 * ab_4) - (float)(ac_4 * ab_8);
  n_4 = (float)(ab_8 * ac) - (float)(ac_8 * ab);
  n_8 = (float)(ac_4 * ab) - (float)(ac * ab_4);
  tpA = x - p->x;
  v57 = v13 - p->x;
  ba = a->y;
  aa = a->z;
  pa = b->z;
  ca = b->y;
  tpC = (float)((float)((float)((float)((float)(ba - p->y) * (float)(pa - p->z))
                              - (float)((float)(aa - p->z) * (float)(ca - p->y)))
                      * n)
              + (float)((float)((float)((float)(aa - p->z) * tpA) - (float)((float)(pa - p->z) * v57)) * n_4))
      + (float)((float)((float)((float)(ca - p->y) * v57) - (float)((float)(ba - p->y) * tpA)) * n_8);
  if ( tpC <= 0.0 && projABnom >= 0.0 && projABdenom >= 0.0 )
  {
    v27 = projABnom / (float)(projABdenom + projABnom);
    v28 = ab_4 * v27;
    v29 = ab_8 * v27;
    v30 = v13 + (float)(ab * v27);
LABEL_14:
    result->x = v30;
    result->y = ba + v28;
    result->z = aa + v29;
    return result;
  }
  v51 = v14 - p->x;
  projABnoma = c->z;
  projABdenoma = c->y;
  tpAa = (float)((float)((float)((float)((float)(ca - p->y) * (float)(projABnoma - p->z))
                               - (float)((float)(pa - p->z) * (float)(projABdenoma - p->y)))
                       * n)
               + (float)((float)((float)((float)(pa - p->z) * v51) - (float)((float)(projABnoma - p->z) * tpA)) * n_4))
       + (float)((float)((float)((float)(projABdenoma - p->y) * tpA) - (float)((float)(ca - p->y) * v51)) * n_8);
  if ( tpAa > 0.0 || projBCnom < 0.0 || v22 < 0.0 )
  {
    v32 = (float)((float)((float)((float)((float)(projABdenoma - p->y) * (float)(aa - p->z))
                                - (float)((float)(projABnoma - p->z) * (float)(ba - p->y)))
                        * n)
                + (float)((float)((float)((float)(projABnoma - p->z) * v57) - (float)((float)(aa - p->z) * v51)) * n_4))
        + (float)((float)((float)((float)(ba - p->y) * v51) - (float)((float)(projABdenoma - p->y) * v57)) * n_8);
    if ( v32 <= 0.0 && projACnom >= 0.0 && projACdenom >= 0.0 )
    {
      v33 = projACnom / (float)(projACdenom + projACnom);
      v28 = ac_4 * v33;
      v29 = ac_8 * v33;
      v30 = v13 + (float)(v33 * ac);
      goto LABEL_14;
    }
    v34 = 1.0 / (float)((float)(v32 + tpAa) + tpC);
    v35 = v32 * v34;
    v36 = (float)(1.0 - (float)(tpAa * v34)) - v35;
    result->x = (float)((float)(v13 * (float)(tpAa * v34)) + (float)(x * v35)) + (float)(v14 * v36);
    result->y = (float)((float)(ba * (float)(tpAa * v34)) + (float)(ca * v35)) + (float)(projABdenoma * v36);
    result->z = (float)((float)(aa * (float)(tpAa * v34)) + (float)(v35 * pa)) + (float)(projABnoma * v36);
    return result;
  }
  else
  {
    v31 = projBCnom / (float)(v22 + projBCnom);
    result->y = ca + (float)(bc_4 * v31);
    result->x = x + (float)(bc * v31);
    result->z = pa + (float)(bc_8 * v31);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C92A0
// Name: bool IsSurfaceInFrontOfPlane(struct msurface2_t __near *,class VPlane const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsSurfaceInFrontOfPlane(msurface2_t *surfID, const VPlane *plane)
{
  cplane_t *v2; // eax
  int firstvertindex; // eax
  unsigned __int16 *vertindices; // ecx
  mvertex_t *vertexes; // edx
  float *p_x; // edi
  float x; // ebx
  mvertex_t *v9; // edi
  int v10; // eax
  float trianglePlane_12; // [esp+20h] [ebp-28h]
  float vOrigin; // [esp+3Ch] [ebp-Ch]
  float vOrigin_4; // [esp+40h] [ebp-8h]
  float vOrigin_8; // [esp+44h] [ebp-4h]
  Vector trianglePlane; // 0:^14.12

  v2 = surfID->plane;
  trianglePlane_12 = v2->dist;
  trianglePlane = v2->normal;
  if ( AlmostEqual(
         a: (float)((float)(plane->m_Normal.y * trianglePlane.y) + (float)(plane->m_Normal.x * v2->normal.x))
       + (float)(plane->m_Normal.z * trianglePlane.z),
         b: 1.0,
         maxUlps: 10)
    && AlmostEqual(a: plane->m_Dist, b: trianglePlane_12, maxUlps: 10) )
  {
    return true;
  }
  if ( HIBYTE(surfID->flags) < 3u )
    return false;
  firstvertindex = surfID->firstvertindex;
  vertindices = host_state.worldbrush->vertindices;
  vertexes = host_state.worldbrush->vertexes;
  p_x = &vertexes[vertindices[firstvertindex]].position.x;
  vOrigin = *p_x;
  vOrigin_8 = p_x[2];
  vOrigin_4 = p_x[1];
  x = vertexes[vertindices[firstvertindex + 1]].position.x;
  v9 = &vertexes[vertindices[firstvertindex + 1]];
  v10 = vertindices[firstvertindex + 2];
  return (float)((float)((float)((float)(plane->m_Normal.y
                                       * (float)((float)(trianglePlane.y * 0.1)
                                               + (float)((float)((float)((float)(v9->position.y - vOrigin_4)
                                                                       + (float)(vertexes[v10].position.y - vOrigin_4))
                                                               * 0.25)
                                                       + vOrigin_4)))
                               + (float)(plane->m_Normal.x
                                       * (float)((float)(trianglePlane.x * 0.1)
                                               + (float)((float)((float)((float)(x - vOrigin)
                                                                       + (float)(vertexes[v10].position.x - vOrigin))
                                                               * 0.25)
                                                       + vOrigin))))
                       + (float)(plane->m_Normal.z
                               * (float)((float)(trianglePlane.z * 0.1)
                                       + (float)((float)((float)((float)(v9->position.z - vOrigin_8)
                                                               + (float)(vertexes[v10].position.z - vOrigin_8))
                                                       * 0.25)
                                               + vOrigin_8))))
               - plane->m_Dist) >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101C94B0
// Name: private: void CUtlDataEnvelope::Assign(class CUtlDataEnvelope const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDataEnvelope::Assign(CUtlDataEnvelope *this, CUtlDataEnvelope *from)
{
  CUtlDataEnvelope *m_pData; // ebx
  int m_nBytes; // esi
  unsigned __int8 *v5; // eax

  m_pData = from;
  m_nBytes = from->m_nBytes;
  if ( m_nBytes != 0 )
  {
    if ( m_nBytes > 4 )
      m_pData = (CUtlDataEnvelope *)from->m_pData;
  }
  else
  {
    m_pData = nullptr;
  }
  if ( m_pData != nullptr )
  {
    this->m_nBytes = m_nBytes;
    if ( m_nBytes <= 4 )
    {
      memcpy(dst: (unsigned __int8 *)this, src: (unsigned __int8 *)m_pData, count: m_nBytes);
    }
    else
    {
      v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: m_nBytes);
      this->m_pData = v5;
      memcpy(dst: v5, src: (unsigned __int8 *)m_pData, count: m_nBytes);
    }
  }
  else
  {
    this->m_pData = nullptr;
    this->m_nBytes = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C9520
// Name: void MarkSurfaceBrushes(int,struct worldbrushdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkSurfaceBrushes(int nSurfIndex, worldbrushdata_t *pData)
{
  dfacebrushlist_t *m_pSurfaceBrushList; // edx
  unsigned int m_nFaceBrushCount; // ecx
  unsigned __int16 *p_m_nFaceBrushStart; // edi
  int v5; // eax

  m_pSurfaceBrushList = pData->m_pSurfaceBrushList;
  if ( m_pSurfaceBrushList != nullptr )
  {
    m_nFaceBrushCount = m_pSurfaceBrushList[nSurfIndex].m_nFaceBrushCount;
    if ( m_nFaceBrushCount > 1 )
      p_m_nFaceBrushStart = &pData->m_pSurfaceBrushes[m_pSurfaceBrushList[nSurfIndex].m_nFaceBrushStart];
    else
      p_m_nFaceBrushStart = &m_pSurfaceBrushList[nSurfIndex].m_nFaceBrushStart;
    v5 = 0;
    if ( (_WORD)m_nFaceBrushCount != 0 )
    {
      do
        g_BSPData.map_brushes.m_pArray[p_m_nFaceBrushStart[v5++]].contents |= 0x40000u;
      while ( v5 < m_pSurfaceBrushList[nSurfIndex].m_nFaceBrushCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C9590
// Name: public: virtual void CPaintmapDataManager::GetPaintmapSize(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::GetPaintmapSize(
        CPaintmapDataManager *this,
        int paintmap,
        int *width,
        int *height)
{
  CPaintTextureData *v4; // eax

  if ( paintmap >= 0 && paintmap < this->m_iPaintmaps )
  {
    v4 = &this->m_pPaintTextureDataArray[paintmap];
    *width = v4->m_nPaintWidth;
    *height = v4->m_nPaintHeight;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C95C0
// Name: public: virtual void CPaintmapDataManager::OnRestorePaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::OnRestorePaintmaps(CPaintmapDataManager *this)
{
  int v1; // edx
  int v2; // esi

  v1 = 0;
  if ( this->m_iPaintmaps > 0 )
  {
    v2 = 0;
    do
    {
      this->m_pPaintTextureDataArray[v2].m_nDirtyFlag = PAINTMAP_DIRTY_FULLRECT;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_iPaintmaps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C95F0
// Name: unsigned char BlendColor(unsigned char,unsigned char,float,float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl BlendColor(
        unsigned __int8 colorIndex,
        unsigned __int8 nPrePixel,
        float flAlpha,
        float flPaintCoatPercent,
        float flMaxAlpha)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  if ( colorIndex == 4 )
  {
    if ( paint_alpha_offset_enabled.m_pParent != nullptr && paint_alpha_offset_enabled.m_pParent->m_Value.m_nValue != 0 )
      return 32 * (nPrePixel >> 5);
    else
      return 0x80;
  }
  else
  {
    v6 = (float)(nPrePixel & 0x1F) * 0.032258064;
    if ( v6 >= 0.0 )
    {
      v7 = 1.0;
      if ( v6 <= 1.0 )
        v7 = (float)(nPrePixel & 0x1F) * 0.032258064;
    }
    else
    {
      v7 = 0.0;
    }
    v8 = (float)(flAlpha * flPaintCoatPercent) + v7;
    if ( v8 >= 0.0 )
    {
      if ( v8 > flMaxAlpha )
        v8 = flMaxAlpha;
      return (32 * colorIndex) | (int)(float)(v8 * 31.0);
    }
    else
    {
      return (32 * colorIndex) | (int)(float)(0.0 * 31.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C96A0
// Name: float ComputeCircleAlpha(struct PaintRect_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputeCircleAlpha(const PaintRect_t *paintRect, int x, int y)
{
  float v4; // xmm0_4
  double v5; // st7
  double result; // st7
  double v7; // st7
  float v8; // xmm0_4
  float v9; // [esp+8h] [ebp-2Ch]
  float v10; // [esp+24h] [ebp-10h]
  float v11; // [esp+24h] [ebp-10h]

  v9 = fsqrt(
         (float)((float)((float)y - paintRect->uvCenter.y) * (float)((float)y - paintRect->uvCenter.y))
       + (float)((float)((float)x - paintRect->uvCenter.x) * (float)((float)x - paintRect->uvCenter.x)));
  v4 = (float)(v9 / paintRect->flCircleRadius) + paintRect->flCenterAlpha;
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      v5 = Bias(
             x: (float)(v9 / paintRect->flCircleRadius) + paintRect->flCenterAlpha,
             biasAmt: paintsplat_bias.m_pParent->m_Value.m_fValue);
    else
      v5 = Bias(x: 1.0, biasAmt: paintsplat_bias.m_pParent->m_Value.m_fValue);
  }
  else
  {
    v5 = Bias(x: 0.0, biasAmt: paintsplat_bias.m_pParent->m_Value.m_fValue);
  }
  result = 1.0 - v5;
  if ( paintsplat_noise_enabled.m_pParent != nullptr && paintsplat_noise_enabled.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = result;
    v7 = _RandomFloat(
           this: (IUniformRandomStream *)paintsplat_max_alpha_noise.m_pParent,
           a2: COERCE_FLOAT(LODWORD(paintsplat_max_alpha_noise.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_),
           a3: paintsplat_max_alpha_noise.m_pParent->m_Value.m_fValue)
       + v10;
    if ( v7 >= 0.0 )
    {
      v8 = v7;
      v11 = v7;
      if ( v11 > 1.0 )
        return 1.0;
      return v8;
    }
    else
    {
      return 0.0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C97D0
// Name: private: unsigned int CPaintTextureData::BlendLuxel(struct PaintRect_t const __near &,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::BlendLuxel(
        CPaintTextureData *this,
        const PaintRect_t *paintRect,
        int x,
        int y,
        float flNewAlpha,
        float flMaxAlpha)
{
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // bl
  unsigned __int8 v8; // al

  v6 = &this->m_backbuffer[y * this->m_nPaintWidth + x];
  v7 = *v6;
  v8 = BlendColor(
         colorIndex: paintRect->colorIndex,
         nPrePixel: *v6,
         flAlpha: flNewAlpha,
         flPaintCoatPercent: paintRect->flPaintCoatPercent,
         flMaxAlpha);
  if ( v7 == v8 )
    return 0;
  *v6 = v8;
  if ( ((v7 ^ v8) & 0xE0) != 0 )
    return 3;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C9840
// Name: private: unsigned int CPaintTextureData::AddSurroundingAlpha(struct PaintRect_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::AddSurroundingAlpha(
        CPaintTextureData *this,
        const PaintRect_t *paintRect,
        int x,
        int y)
{
  msurfacelighting_t *surfacelighting; // ecx
  unsigned int v6; // eax
  unsigned int v7; // esi
  int v8; // ebx
  unsigned int v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // eax
  int v13; // ecx
  int v14; // esi
  unsigned int v15; // esi
  unsigned int v16; // esi
  unsigned int v17; // esi
  int v18; // eax
  unsigned int v19; // esi
  int v20; // eax
  unsigned int v21; // esi
  unsigned int v22; // esi
  unsigned int v23; // esi
  unsigned int v24; // esi
  unsigned int v25; // esi
  unsigned int v26; // esi
  unsigned int v27; // esi
  unsigned int v28; // esi
  unsigned int v29; // esi
  unsigned int v30; // eax
  unsigned int v31; // esi
  unsigned int v32; // esi
  unsigned int v33; // esi
  unsigned int v34; // esi
  unsigned int v35; // esi
  int xa; // [esp+28h] [ebp+Ch]
  int ya; // [esp+2Ch] [ebp+10h]

  surfacelighting = host_state.worldbrush->surfacelighting;
  v6 = ((char *)paintRect->surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
  v7 = 0;
  v8 = x;
  switch ( (y <= *(__int16 *)((char *)&surfacelighting->m_OffsetIntoLightmapPage[1] + v6) ? 0 : 4)
         | (x >= *(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v6)
               + *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v6)
          ? 0
          : 2)
         | (y >= *(__int16 *)((char *)&surfacelighting->m_OffsetIntoLightmapPage[1] + v6)
               + *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + v6)
          ? 0
          : 8)
         | (x > *(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v6)) )
  {
    case 1:
      return CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
    case 2:
      return CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
    case 3:
      v10 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      return CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v10;
    case 4:
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
    case 5:
      v11 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      ya = y - 1;
      v12 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y: ya, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      goto LABEL_7;
    case 6:
      v11 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      ya = y - 1;
      v12 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, y: ya, flNewAlpha: 0.0, flMaxAlpha: 1.0);
LABEL_7:
      v13 = ya;
      goto LABEL_8;
    case 7:
      v15 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v16 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v15;
      v17 = CPaintTextureData::BlendLuxel(this, paintRect, x, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v16;
      v8 = x + 1;
      v18 = y - 1;
      goto LABEL_12;
    case 8:
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
    case 9:
      v11 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v12 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v13 = y + 1;
      goto LABEL_8;
    case 0xA:
      v11 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v12 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v13 = y + 1;
LABEL_8:
      v14 = v12 | v11;
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: v13, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v14;
    case 0xB:
      v21 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v22 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v21;
      v17 = CPaintTextureData::BlendLuxel(this, paintRect, x, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v22;
      v8 = x + 1;
      v18 = y + 1;
LABEL_12:
      v19 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8, y: v18, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v17;
      v20 = y;
      goto LABEL_22;
    case 0xC:
      v14 = CPaintTextureData::BlendLuxel(this, paintRect, x, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v13 = y + 1;
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: v13, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v14;
    case 0xD:
      v23 = CPaintTextureData::BlendLuxel(this, paintRect, x, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v24 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v23;
      v25 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v24;
      v26 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v25;
      return CPaintTextureData::BlendLuxel(this, paintRect, x, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v26;
    case 0xE:
      v27 = CPaintTextureData::BlendLuxel(this, paintRect, x, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v28 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v27;
      v29 = CPaintTextureData::BlendLuxel(this, paintRect, x: x + 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v28;
      xa = y + 1;
      v30 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8 + 1, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      goto LABEL_21;
    case 0xF:
      v31 = CPaintTextureData::BlendLuxel(this, paintRect, x, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
      v32 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v31;
      v33 = CPaintTextureData::BlendLuxel(this, paintRect, x: x - 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v32;
      xa = y + 1;
      v34 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8 - 1, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v33;
      v35 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8 + 1, y: y - 1, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v34;
      v29 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8 + 1, y, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v35;
      v30 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8 + 1, y: y + 1, flNewAlpha: 0.0, flMaxAlpha: 1.0);
LABEL_21:
      v19 = v30 | v29;
      v20 = xa;
LABEL_22:
      v7 = CPaintTextureData::BlendLuxel(this, paintRect, x: v8, y: v20, flNewAlpha: 0.0, flMaxAlpha: 1.0) | v19;
      break;
    default:
      return v7;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101C9EF0
// Name: private: unsigned int CPaintTextureData::DrawLine(struct PaintRect_t const __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::DrawLine(
        CPaintTextureData *this,
        const PaintRect_t *paintRect,
        int x1,
        int x2,
        int y)
{
  __int16 *v7; // eax
  int v8; // edx
  int v10; // ecx
  double v11; // st7
  unsigned int v12; // eax
  int v13; // eax
  double v14; // st7
  float v15; // xmm3_4
  unsigned __int8 colorIndex; // cl
  unsigned __int8 *v17; // edx
  unsigned __int8 v18; // bl
  char v19; // al
  float v20; // xmm0_4
  float v21; // xmm1_4
  unsigned int result; // eax
  bool v23; // zf
  CPaintTextureData *v24; // ecx
  const PaintRect_t *v25; // [esp-4h] [ebp-30h]
  float flNewAlphaa; // [esp+0h] [ebp-2Ch]
  float flNewAlphab; // [esp+0h] [ebp-2Ch]
  int flNewAlpha; // [esp+0h] [ebp-2Ch]
  int v29; // [esp+4h] [ebp-28h]
  int sMax; // [esp+14h] [ebp-18h]
  CPaintTextureData *v31; // [esp+18h] [ebp-14h]
  float flMaxAlpha; // [esp+1Ch] [ebp-10h]
  int start; // [esp+20h] [ebp-Ch]
  int end; // [esp+24h] [ebp-8h]
  unsigned int nChangeFlags; // [esp+28h] [ebp-4h]
  int x; // [esp+34h] [ebp+8h]
  int xa; // [esp+34h] [ebp+8h]
  float flAlphaa; // [esp+40h] [ebp+14h]
  int flAlpha; // [esp+40h] [ebp+14h]

  v7 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                 + (((char *)paintRect->surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v8 = v7[5];
  x = v7[4];
  end = x2;
  sMax = v7[2];
  v10 = x1;
  v31 = this;
  nChangeFlags = 0;
  start = x1;
  flMaxAlpha = 1.0;
  if ( y == v8 || y == v8 + v7[3] )
  {
    flMaxAlpha = paint_max_surface_border_alpha.m_pParent->m_Value.m_fValue;
  }
  else
  {
    if ( x1 == x )
    {
      if ( paintRect->colorIndex == 4 )
      {
        v11 = 1.0;
      }
      else
      {
        v11 = ComputeCircleAlpha(paintRect, x: x1, y);
        v10 = x1;
      }
      flNewAlphaa = v11;
      v12 = CPaintTextureData::BlendLuxel(
              this,
              paintRect,
              x: v10,
              y,
              flNewAlpha: flNewAlphaa,
              flMaxAlpha: paint_max_surface_border_alpha.m_pParent->m_Value.m_fValue);
      v10 = x1;
      nChangeFlags = v12;
      start = x1 + 1;
    }
    v13 = x2;
    if ( x2 == x + sMax )
    {
      if ( paintRect->colorIndex == 4 )
      {
        v14 = 1.0;
      }
      else
      {
        v14 = ComputeCircleAlpha(paintRect, x: x2, y);
        v13 = x2;
      }
      flNewAlphab = v14;
      nChangeFlags |= CPaintTextureData::BlendLuxel(
                        this,
                        paintRect,
                        x: v13,
                        y,
                        flNewAlpha: flNewAlphab,
                        flMaxAlpha: paint_max_surface_border_alpha.m_pParent->m_Value.m_fValue);
      v10 = x1;
      end = x2 - 1;
    }
  }
  xa = start;
  if ( start <= end )
  {
    do
    {
      if ( paintRect->colorIndex == 4 )
      {
        v15 = 1.0;
      }
      else
      {
        flAlphaa = ComputeCircleAlpha(paintRect, x: xa, y);
        v15 = flAlphaa;
      }
      colorIndex = paintRect->colorIndex;
      flAlpha = 0;
      v17 = &this->m_backbuffer[y * this->m_nPaintWidth + xa];
      v18 = *v17;
      if ( colorIndex == 4 )
      {
        if ( paint_alpha_offset_enabled.m_pParent != nullptr
          && paint_alpha_offset_enabled.m_pParent->m_Value.m_nValue != 0 )
        {
          v19 = 32 * (v18 >> 5);
        }
        else
        {
          v19 = 0x80;
        }
      }
      else
      {
        v20 = (float)(v18 & 0x1F) * 0.032258064;
        if ( v20 >= 0.0 )
        {
          if ( v20 > 1.0 )
            v20 = 1.0;
        }
        else
        {
          v20 = 0.0;
        }
        v21 = (float)(paintRect->flPaintCoatPercent * v15) + v20;
        if ( v21 >= 0.0 )
        {
          if ( v21 > flMaxAlpha )
            v21 = flMaxAlpha;
        }
        else
        {
          v21 = 0.0;
        }
        v19 = (32 * colorIndex) | (int)(float)(v21 * 31.0);
      }
      if ( v18 != v19 )
      {
        *v17 = v19;
        flAlpha = 1;
        if ( ((v18 ^ (unsigned __int8)v19) & 0xE0) != 0 )
          flAlpha = 3;
      }
      nChangeFlags |= flAlpha;
      this = v31;
      ++xa;
    }
    while ( xa <= end );
    v10 = x1;
  }
  result = nChangeFlags;
  if ( paint_alpha_offset_enabled.m_pParent != nullptr
    && paint_alpha_offset_enabled.m_pParent->m_Value.m_nValue != 0
    && paintRect->colorIndex != 4 )
  {
    v23 = v10 == x2;
    v29 = y;
    flNewAlpha = v10;
    v25 = paintRect;
    v24 = this;
    if ( !v23 )
    {
      nChangeFlags |= CPaintTextureData::AddSurroundingAlpha(this, paintRect, x: flNewAlpha, y);
      v29 = y;
      flNewAlpha = x2;
      v25 = paintRect;
      v24 = this;
    }
    return nChangeFlags | CPaintTextureData::AddSurroundingAlpha(this: v24, paintRect: v25, x: flNewAlpha, y: v29);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CA180
// Name: private: unsigned int CPaintTextureData::Draw2Lines(struct PaintRect_t const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::Draw2Lines(
        CPaintTextureData *this,
        const PaintRect_t *paintRect,
        float x,
        float y)
{
  int v6; // edx
  float v7; // xmm1_4
  int v8; // ecx
  int v10; // ebx
  int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // eax
  int v15; // [esp+0h] [ebp-10h]
  int maxX; // [esp+4h] [ebp-Ch]
  int maxY; // [esp+Ch] [ebp-4h]
  int y2; // [esp+18h] [ebp+8h]
  int x1; // [esp+1Ch] [ebp+Ch]
  int x2; // [esp+20h] [ebp+10h]

  v6 = paintRect->rect.y;
  v7 = paintRect->uvCenter.x;
  v8 = paintRect->rect.x;
  maxY = paintRect->rect.height + v6 - 1;
  v15 = v6;
  maxX = paintRect->rect.width + paintRect->rect.x - 1;
  x1 = (int)(float)((float)(v7 - x) - 0.5);
  if ( x1 <= paintRect->rect.x )
    x1 = paintRect->rect.x;
  v10 = (int)(float)((float)(paintRect->uvCenter.y - y) - 0.5);
  if ( v10 <= v6 )
    v10 = paintRect->rect.y;
  x2 = (int)(float)((float)(v7 + x) + 0.5);
  if ( x2 >= paintRect->rect.width + paintRect->rect.x - 1 )
    x2 = paintRect->rect.width + paintRect->rect.x - 1;
  y2 = (int)(float)((float)(paintRect->uvCenter.y + y) + 0.5);
  if ( y2 >= maxY )
    y2 = maxY;
  if ( x1 > maxX )
    return 0;
  v11 = x2;
  if ( x2 < v8 )
    return 0;
  v12 = 0;
  if ( v6 <= v10 && v10 <= maxY )
  {
    v13 = CPaintTextureData::DrawLine(this, paintRect, x1, x2, y: v10);
    v6 = v15;
    v12 = v13;
    v11 = x2;
  }
  if ( v10 != y2 && v6 <= y2 && y2 <= maxY )
    v12 |= CPaintTextureData::DrawLine(this, paintRect, x1, x2: v11, y: y2);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x101CA290
// Name: private: unsigned int CPaintTextureData::DrawCircle(struct PaintRect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPaintTextureData::DrawCircle(CPaintTextureData *this, const PaintRect_t *paintRect)
{
  unsigned int result; // eax
  unsigned int v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  unsigned int v8; // esi
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  unsigned int nChangeFlags; // [esp+14h] [ebp-Ch]
  float error; // [esp+18h] [ebp-8h]
  float x; // [esp+1Ch] [ebp-4h]
  float y; // [esp+28h] [ebp+8h]

  LODWORD(error) = LODWORD(paintRect->flCircleRadius) ^ _mask__NegFloat_;
  result = 0;
  x = paintRect->flCircleRadius;
  y = 0.0;
  nChangeFlags = 0;
  if ( x >= 0.0 )
  {
    do
    {
      v5 = CPaintTextureData::Draw2Lines(this, paintRect, x, y);
      v6 = x;
      v7 = y;
      v8 = v5;
      if ( x != y )
      {
        v7 = y;
        v6 = x;
        v8 = CPaintTextureData::Draw2Lines(this, paintRect, x: y, y: x) | v5;
      }
      nChangeFlags |= v8;
      v9 = v7 + error;
      v10 = v7 + 1.0;
      v11 = v9 + v10;
      y = v10;
      error = v11;
      if ( v11 >= 0.0 )
      {
        v6 = v6 - 1.0;
        x = v6;
        error = (float)(v11 - v6) - v6;
      }
    }
    while ( v6 >= v10 );
    return nChangeFlags;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CA380
// Name: bool ComputePaintRect(struct msurface2_t __near *,class Vector const __near &,float,struct PaintRect_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall ComputePaintRect@<al>(
        int a1@<ebp>,
        msurface2_t *surfID,
        const Vector *vPosition,
        float flSphereRadius,
        PaintRect_t *paintRect)
{
  __int128 v5; // xmm0
  float y; // xmm3_4
  float z; // xmm4_4
  mtexinfo_t *texinfo; // eax
  int v9; // edx
  float *v10; // eax
  __int16 *v11; // edx
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  int v16; // eax
  msurfacelighting_t *surfacelighting; // ecx
  __int128 v18; // xmm2
  float v19; // xmm5_4
  int v20; // esi
  int v21; // edx
  char *v22; // eax
  int v23; // ecx
  int v24; // eax
  __int128 v25; // xmm3
  float v26; // xmm5_4
  float v27; // xmm1_4
  double v28; // st7
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  int v33; // ecx
  int v34; // edi
  float v35; // xmm4_4
  int v36; // esi
  int v37; // edx
  int v38; // ecx
  int v39; // esi
  int v40; // edx
  int v41; // ecx
  int v43; // [esp+14h] [ebp-80h] BYREF
  _BYTE ctx_8[32]; // [esp+28h] [ebp-6Ch] OVERLAPPED
  __int128 v45; // [esp+48h] [ebp-4Ch]
  float v46; // [esp+58h] [ebp-3Ch]
  float v47; // [esp+5Ch] [ebp-38h]
  int v48; // [esp+60h] [ebp-34h]
  _BYTE uvCenter[20]; // [esp+64h] [ebp-30h] OVERLAPPED
  int v50; // [esp+80h] [ebp-14h]
  int v51; // [esp+84h] [ebp-10h]
  int v52; // [esp+88h] [ebp-Ch]
  int startX; // [esp+8Ch] [ebp-8h]
  int retaddr; // [esp+94h] [ebp+0h]

  v52 = a1;
  startX = retaddr;
  *(float *)&v50 = (float)((float)((float)(vPosition->y * surfID->plane->normal.y)
                                 + (float)(vPosition->x * surfID->plane->normal.x))
                         + (float)(vPosition->z * surfID->plane->normal.z))
                 - surfID->plane->dist;
  v5 = 0;
  *(float *)&v5 = fsqrt((float)(flSphereRadius * flSphereRadius) - (float)(*(float *)&v50 * *(float *)&v50));
  v45 = v5;
  SurfSetupSurfaceContext(ctx: (SurfaceCtx_t *)&v43, surfID);
  y = vPosition->y;
  z = vPosition->z;
  texinfo = host_state.worldbrush->texinfo;
  v9 = *((unsigned __int16 *)surfID + 11) >> 1;
  *(float *)&v5 = texinfo[v9].lightmapVecsLuxelsPerWorldUnits[0].y;
  v10 = (float *)&texinfo[v9];
  v11 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v12 = (float)(*(float *)&ctx_8[4]
              + (float)(*(float *)&ctx_8[12]
                      * (float)((float)((float)((float)((float)((float)(v10[13] * y) + (float)(vPosition->x * v10[12]))
                                                      + (float)(v10[14] * z))
                                              + v10[15])
                                      - (float)v11[1])
                              + 0.5)))
      / *(float *)&ctx_8[12];
  v46 = (float)(*(float *)ctx_8
              + (float)(*(float *)&ctx_8[8]
                      * (float)((float)((float)((float)((float)((float)(*(float *)&v5 * y)
                                                              + (float)(vPosition->x * v10[8]))
                                                      + (float)(v10[10] * z))
                                              + v10[11])
                                      - (float)*v11)
                              + 0.5)))
      / *(float *)&ctx_8[8];
  v47 = v12;
  v13 = v10[12];
  v14 = v10[14];
  v18 = 0;
  *(float *)&v18 = (float)((float)(v10[8] * v10[8]) + (float)(v10[9] * v10[9])) + (float)(v10[10] * v10[10]);
  v15 = v10[13];
  v16 = (char *)surfID - (char *)host_state.worldbrush->surfaces2;
  surfacelighting = host_state.worldbrush->surfacelighting;
  *(float *)&v18 = fsqrt(*(float *)&v18);
  *(_OWORD *)&uvCenter[4] = v18;
  v19 = (float)((float)(v13 * v13) + (float)(v15 * v15)) + (float)(v14 * v14);
  v16 &= 0xFFFFFFE0;
  v20 = *(__int16 *)((char *)surfacelighting->m_OffsetIntoLightmapPage + v16);
  v21 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v16);
  v22 = (char *)surfacelighting + v16;
  v23 = *((__int16 *)v22 + 5);
  v24 = *((__int16 *)v22 + 3);
  v25 = 0;
  *(float *)&v25 = fsqrt(v19);
  *(float *)&uvCenter[12] = *(float *)&v18 * *(float *)&v45;
  *(_OWORD *)&ctx_8[16] = v25;
  *(float *)&uvCenter[16] = *(float *)&v25 * *(float *)&v45;
  v26 = v12 - (float)(*(float *)&v25 * *(float *)&v45);
  v27 = v12 + (float)(*(float *)&v25 * *(float *)&v45);
  v51 = v23;
  *(_DWORD *)uvCenter = v21;
  v48 = v24;
  if ( (float)(v46 + (float)(*(float *)&v18 * *(float *)&v45)) < (float)v20
    || (float)(v20 + v21) < (float)(v46 - (float)(*(float *)&v18 * *(float *)&v45))
    || v27 < (float)v23
    || (float)(v23 + v24) < v26 )
  {
    return false;
  }
  v28 = *(float *)&uvCenter[16];
  if ( *(float *)&uvCenter[12] >= (double)*(float *)&uvCenter[16] )
    v28 = *(float *)&uvCenter[12];
  *(float *)&uvCenter[16] = floor(X: v28 + 0.5);
  v29 = *(float *)&v50;
  paintRect->flCircleRadius = *(float *)&uvCenter[16];
  v30 = *(float *)&uvCenter[16];
  v31 = v47;
  paintRect->flCenterAlpha = v29 / flSphereRadius;
  v32 = v46;
  v33 = (int)(float)((float)(v46 - v30) - 0.5);
  paintRect->uvCenter.x = v46;
  paintRect->uvCenter.y = v31;
  paintRect->surfID = surfID;
  v50 = v33;
  if ( v33 <= v20 )
    v50 = v20;
  v34 = v51;
  v35 = (float)(v31 - v30) - 0.5;
  if ( (int)v35 > v51 )
    v34 = (int)v35;
  v36 = *(_DWORD *)uvCenter + v20 + 1;
  v37 = (int)(float)((float)(v32 + v30) + 0.5);
  if ( v37 >= v36 )
    v37 = v36;
  *(_DWORD *)uvCenter = (int)(float)((float)(v31 + v30) + 0.5);
  v38 = v48 + v51 + 1;
  if ( *(int *)uvCenter < v38 )
    v38 = *(_DWORD *)uvCenter;
  v39 = v50;
  paintRect->rect.x = v50;
  v40 = v37 - v39;
  v41 = v38 - v34;
  paintRect->rect.y = v34;
  paintRect->rect.width = v40;
  paintRect->rect.height = v41;
  return v40 > 0 && v41 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CA700
// Name: public: void CPaintmapDataManager::RemoveAllPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::RemoveAllPaint(CPaintmapDataManager *this)
{
  int v2; // ebx
  CPaintTextureData *v3; // esi
  int numbrushes; // edx
  cbrush_t *m_pArray; // ecx
  int i; // eax
  int v7; // [esp+Ch] [ebp-4h]

  v2 = 0;
  if ( this->m_pPaintTextureDataArray != nullptr && this->m_iPaintmaps != 0 )
  {
    v7 = 0;
    do
    {
      v3 = &this->m_pPaintTextureDataArray[v7];
      _V_memset(dest: v3->m_backbuffer, fill: 128, count: v3->m_nPaintWidth * v3->m_nPaintHeight);
      ++v7;
      ++v2;
      v3->m_nDirtyFlag = PAINTMAP_DIRTY_FULLRECT;
    }
    while ( v2 != this->m_iPaintmaps );
  }
  numbrushes = g_BSPData.numbrushes;
  m_pArray = g_BSPData.map_brushes.m_pArray;
  for ( i = 0; i < numbrushes; ++i )
    m_pArray[i].contents &= ~0x40000u;
}

//------------------------------------------------------------------------------
// Address: 0x101CA780
// Name: public: void CPaintmapDataManager::PaintAllSurfaces(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::PaintAllSurfaces(CPaintmapDataManager *this, unsigned __int8 color)
{
  int v3; // ebx
  CPaintTextureData *m_pPaintTextureDataArray; // esi
  int numsurfaces; // edx
  int v6; // ecx
  int numbrushes; // edx
  cbrush_t *m_pArray; // ecx
  int j; // eax
  int i; // [esp+Ch] [ebp-4h]
  int colora; // [esp+18h] [ebp+8h]

  v3 = 0;
  if ( this->m_pPaintTextureDataArray != nullptr )
  {
    i = 0;
    if ( this->m_iPaintmaps != 0 )
    {
      colora = (unsigned __int8)(32 * color) | 0x1F;
      do
      {
        m_pPaintTextureDataArray = this->m_pPaintTextureDataArray;
        _V_memset(
          dest: m_pPaintTextureDataArray[v3].m_backbuffer,
          fill: colora,
          count: m_pPaintTextureDataArray[v3].m_nPaintWidth * m_pPaintTextureDataArray[v3].m_nPaintHeight);
        m_pPaintTextureDataArray[v3++].m_nDirtyFlag = PAINTMAP_DIRTY_FULLRECT;
        ++i;
      }
      while ( i != this->m_iPaintmaps );
    }
  }
  numsurfaces = host_state.worldbrush->numsurfaces;
  if ( numsurfaces > 0 )
  {
    v6 = 0;
    do
    {
      host_state.worldbrush->surfaces2[v6++].flags |= 0x200000u;
      --numsurfaces;
    }
    while ( numsurfaces != 0 );
  }
  numbrushes = g_BSPData.numbrushes;
  m_pArray = g_BSPData.map_brushes.m_pArray;
  for ( j = 0; j < numbrushes; ++j )
    m_pArray[j].contents |= 0x40000u;
}

//------------------------------------------------------------------------------
// Address: 0x101CA850
// Name: public: virtual void CPaintmapDataManager::AllocatePaintmapData(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::AllocatePaintmapData(
        CPaintmapDataManager *this,
        int iPaintmapID,
        int iCorrespondingLightMapWidth,
        int iCorrespondingLightMapHeight)
{
  CPaintTextureData *v4; // esi
  unsigned __int8 *v5; // eax
  int v6; // [esp-8h] [ebp-Ch]

  v4 = &this->m_pPaintTextureDataArray[iPaintmapID];
  v4->m_nPaintWidth = iCorrespondingLightMapWidth;
  v4->m_nPaintHeight = iCorrespondingLightMapHeight;
  v4->m_lightmapPageID = iPaintmapID;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: iCorrespondingLightMapHeight * iCorrespondingLightMapWidth);
  v6 = v4->m_nPaintHeight * v4->m_nPaintWidth;
  v4->m_backbuffer = v5;
  _V_memset(dest: v5, fill: 128, count: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101CA8B0
// Name: public: virtual void CFunctor4<void (*)(int,unsigned char __near *,int,struct Rect_t __near *),int,unsigned char __near *,int,class CUtlEnvelope<struct Rect_t>,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor4<void (__cdecl *)(int,unsigned char *,int,Rect_t *),int,unsigned char *,int,CUtlEnvelope<Rect_t>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor4<void (__cdecl*)(int,unsigned char *,int,Rect_t *),int,unsigned char *,int,CUtlEnvelope<Rect_t>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  int m_nBytes; // edx
  Rect_t *p_m_arg4; // eax

  m_nBytes = this->m_arg4.m_nBytes;
  p_m_arg4 = (Rect_t *)&this->m_arg4;
  if ( m_nBytes != 0 )
  {
    if ( m_nBytes > 4 )
      p_m_arg4 = (Rect_t *)p_m_arg4->x;
  }
  else
  {
    p_m_arg4 = nullptr;
  }
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2, a3: this->m_arg3, a4: p_m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x101CA9C0
// Name: public: void CPaintTextureData::GetPixels(struct Rect_t const __near &,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintTextureData::GetPixels(
        CPaintTextureData *this,
        const Rect_t *splatRect,
        CUtlMemory<char,int> *surfColors)
{
  const Rect_t *v4; // ecx
  int v5; // edi
  int v7; // edx
  unsigned __int8 v8; // bl
  float v9; // xmm0_4
  unsigned __int8 v10; // bl
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax
  bool v15; // zf
  unsigned __int8 *v16; // eax
  CPaintTextureData *v17; // [esp+14h] [ebp-Ch]
  int y; // [esp+1Ch] [ebp-4h]
  int x; // [esp+2Ch] [ebp+Ch]

  v4 = splatRect;
  v5 = 0;
  v17 = this;
  for ( y = 0; v5 < v4->height; y = v5 )
  {
    v7 = 0;
    for ( x = 0; v7 < v4->width; x = v7 )
    {
      v8 = this->m_backbuffer[this->m_nPaintWidth * (v5 + v4->y) + v4->x + v7];
      v9 = (float)(v8 & 0x1F) * 0.032258064;
      v10 = v8 >> 5;
      if ( v9 >= 0.0 )
      {
        if ( v9 > 1.0 )
          v9 = 1.0;
      }
      else
      {
        v9 = 0.0;
      }
      if ( v9 > paint_min_valid_alpha_value.m_pParent->m_Value.m_fValue )
      {
        m_pMemory = (int)surfColors[1].m_pMemory;
        m_nAllocationCount = surfColors->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
        {
          CUtlMemory<bool,int>::Grow(this: surfColors, num: m_pMemory - m_nAllocationCount + 1);
          v7 = x;
        }
        ++surfColors[1].m_pMemory;
        v13 = (unsigned __int8 *)surfColors->m_pMemory;
        v14 = (int)&surfColors[1].m_pMemory[-m_pMemory - 1];
        surfColors[1].m_nAllocationCount = (int)surfColors->m_pMemory;
        if ( v14 > 0 )
        {
          _V_memmove(dest: &v13[m_pMemory + 1], src: &v13[m_pMemory], count: v14);
          v7 = x;
        }
        v4 = splatRect;
        v15 = &surfColors->m_pMemory[m_pMemory] == nullptr;
        v16 = (unsigned __int8 *)&surfColors->m_pMemory[m_pMemory];
        v5 = y;
        if ( !v15 )
          *v16 = v10;
      }
      if ( debug_paint_alpha.m_pParent != nullptr && debug_paint_alpha.m_pParent->m_Value.m_nValue != 0 )
      {
        Con_NPrintf(idx: v7 + v5 * v4->width, fmt: "(%d, %d), Alpha: %f\n", v7, v5, v9);
        v4 = splatRect;
        v7 = x;
        v5 = y;
      }
      this = v17;
      ++v7;
    }
    ++v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CAB10
// Name: void GetPaintColorFromSurface(struct msurface2_t __near *,class Vector const __near &,class Vector const __near &,float,class VPlane const __near &,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetPaintColorFromSurface(
        msurface2_t *surfID,
        const Vector *vPosition,
        const Vector *vContactNormal,
        float flSphereRadius,
        const VPlane *basePlane,
        CUtlMemory<char,int> *surfColors)
{
  int lightmapPageID; // esi
  PaintRect_t paintRect; // [esp+Ch] [ebp-2Ch] BYREF
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  if ( (surfID->flags & 0x200000) != 0
    && (float)((float)((float)(vContactNormal->y * surfID->plane->normal.y)
                     + (float)(vContactNormal->x * surfID->plane->normal.x))
             + (float)(vContactNormal->z * surfID->plane->normal.z)) >= 0.89999998 )
  {
    lightmapPageID = materialSortInfoArray[surfID->materialSortID].lightmapPageID;
    if ( ComputePaintRect(a1: (int)&savedregs, surfID, vPosition, flSphereRadius, &paintRect) )
      CPaintTextureData::GetPixels(
        this: &g_PaintManager.m_pPaintTextureDataArray[lightmapPageID],
        splatRect: &paintRect.rect,
        surfColors);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CABC0
// Name: public: void ICallQueue::QueueCall<void,int,unsigned char __near *,int,struct Rect_t __near *,int,unsigned char __near *,int,class CUtlEnvelope<struct Rect_t>>(void (*)(int,unsigned char __near *,int,struct Rect_t __near *),int const __near &,unsigned char __near * const __near &,int const __near &,class CUtlEnvelope<struct Rect_t> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<void,int,unsigned char *,int,Rect_t *,int,unsigned char *,int,CUtlEnvelope<Rect_t>>(
        ICallQueue *this,
        void (__cdecl *pfnProxied)(int, unsigned __int8 *, int, Rect_t *),
        int *arg1,
        unsigned __int8 **arg2,
        int *arg3,
        const CUtlEnvelope<Rect_t> *arg4)
{
  CUtlDataEnvelope *v7; // esi

  v7 = (CUtlDataEnvelope *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v7 != nullptr )
  {
    v7[1].m_nBytes = 1;
    v7[2].m_pData = (unsigned __int8 *)pfnProxied;
    v7->m_pData = (unsigned __int8 *)&CFunctor4<void (__cdecl *)(int,unsigned char *,int,Rect_t *),int,unsigned char *,int,CUtlEnvelope<Rect_t>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v7[1].m_pData = (unsigned __int8 *)&CFunctor4<void (__cdecl *)(int,unsigned char *,int,Rect_t *),int,unsigned char *,int,CUtlEnvelope<Rect_t>,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v7[2].m_nBytes = *arg1;
    v7[3].m_pData = *arg2;
    v7[3].m_nBytes = *arg3;
    CUtlDataEnvelope::Assign(this: v7 + 4, from: &arg4->CUtlDataEnvelope);
    this->QueueFunctorInternal(this, a2: (CFunctor *)v7);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CAD60
// Name: void R_UpdatePaintmap(class ICallQueue __near *,int,unsigned char __near *,int,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_UpdatePaintmap(
        ICallQueue *pCallQueue,
        int paintmap,
        unsigned __int8 *pPaintData,
        int numRects,
        Rect_t *pRects)
{
  unsigned __int8 *v5; // edi
  signed int v6; // esi
  unsigned int v7; // [esp-Ch] [ebp-18h]
  CUtlEnvelope<Rect_t> dst; // [esp+4h] [ebp-8h] BYREF

  if ( pCallQueue != nullptr )
  {
    v5 = (unsigned __int8 *)pRects;
    v6 = 16 * numRects;
    if ( pRects != nullptr )
    {
      dst.m_nBytes = 16 * numRects;
      v7 = 16 * numRects;
      if ( v6 <= 4 )
      {
        memcpy((unsigned __int8 *)&dst, src: (unsigned __int8 *)pRects, count: v7);
      }
      else
      {
        dst.m_pData = (unsigned __int8 *)MemAlloc_Alloc(nSize: v7);
        memcpy(dst: dst.m_pData, src: v5, count: v6);
      }
    }
    else
    {
      dst.m_pData = nullptr;
      dst.m_nBytes = 0;
    }
    ICallQueue::QueueCall<void,int,unsigned char *,int,Rect_t *,int,unsigned char *,int,CUtlEnvelope<Rect_t>>(
      this: pCallQueue,
      pfnProxied: R_UpdatePaintmapRect,
      arg1: &paintmap,
      arg2: &pPaintData,
      arg3: &numRects,
      arg4: &dst);
    if ( dst.m_nBytes > 4 )
      free(pMem: dst.m_pData);
  }
  else
  {
    materials->UpdatePaintmap(this: materials, a2: paintmap, a3: pPaintData, a4: numRects, a5: pRects);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CAE10
// Name: public: void CPaintmapDataManager::UpdatePaintmapTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::UpdatePaintmapTextures(CPaintmapDataManager *this)
{
  IMatRenderContext *m_pObject; // edi
  IMaterialSystem *v3; // esi
  CFunctor *v4; // eax
  ICallQueue *v5; // ecx
  int v6; // esi
  int v7; // edi
  CPaintTextureData *v8; // eax
  PaintDirtyFlags_t m_nDirtyFlag; // ecx
  unsigned __int8 *m_backbuffer; // eax
  CPaintTextureData *m_pPaintTextureDataArray; // eax
  ICallQueue *v12; // ebx
  IMaterialSystem *v13; // esi
  CFunctor *v14; // eax
  CUtlEnvelope<Rect_t> arg4; // [esp+Ch] [ebp-1Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+14h] [ebp-14h]
  int arg1; // [esp+18h] [ebp-10h] BYREF
  unsigned __int8 *arg2; // [esp+1Ch] [ebp-Ch] BYREF
  int arg3; // [esp+20h] [ebp-8h] BYREF
  ICallQueue *pCallQueue; // [esp+24h] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pCallQueue = m_pObject->GetCallQueue(this: m_pObject);
  if ( pCallQueue != nullptr )
  {
    v3 = materials;
    v4 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v4 != nullptr )
    {
      v5 = pCallQueue;
      v4[1].m_nUserID = 1;
      v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v4[2].__vftable = (CFunctor_vtbl *) __thiscall IMaterialSystem::`vcall'{556,{flat}};
      v4[2].m_nUserID = (unsigned int)v3;
      v5->QueueFunctorInternal(this: v5, a2: v4);
    }
    else
    {
      pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
    }
  }
  else
  {
    materials->BeginUpdatePaintmaps(this: materials);
  }
  v6 = 0;
  if ( this->m_iPaintmaps > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->m_pPaintTextureDataArray[v7];
      m_nDirtyFlag = v8->m_nDirtyFlag;
      if ( m_nDirtyFlag != PAINTMAP_CLEAN )
      {
        if ( m_nDirtyFlag == PAINTMAP_DIRTY_FULLRECT )
        {
          m_backbuffer = v8->m_backbuffer;
          arg3 = 0;
          arg2 = m_backbuffer;
          arg1 = v6;
          if ( pCallQueue != nullptr )
          {
            arg4.m_pData = nullptr;
            arg4.m_nBytes = 0;
            ICallQueue::QueueCall<void,int,unsigned char *,int,Rect_t *,int,unsigned char *,int,CUtlEnvelope<Rect_t>>(
              this: pCallQueue,
              pfnProxied: R_UpdatePaintmapRect,
              &arg1,
              &arg2,
              &arg3,
              &arg4);
            if ( arg4.m_nBytes > 4 )
              free(pMem: arg4.m_pData);
            arg4.m_nBytes = 0;
          }
          else
          {
            materials->UpdatePaintmap(this: materials, a2: v6, a3: m_backbuffer, a4: 0, a5: nullptr);
          }
        }
        else
        {
          R_UpdatePaintmap(
            pCallQueue,
            paintmap: v6,
            pPaintData: this->m_pPaintTextureDataArray[v7].m_backbuffer,
            numRects: this->m_pPaintTextureDataArray[v7].m_dirtyRects.m_Size,
            pRects: this->m_pPaintTextureDataArray[v7].m_dirtyRects.m_Memory.m_pMemory);
        }
        m_pPaintTextureDataArray = this->m_pPaintTextureDataArray;
        m_pPaintTextureDataArray[v7].m_nDirtyFlag = PAINTMAP_CLEAN;
        m_pPaintTextureDataArray[v7].m_dirtyRects.m_Size = 0;
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->m_iPaintmaps );
    m_pObject = pRenderContext.m_pObject;
  }
  v12 = pCallQueue;
  if ( pCallQueue != nullptr )
  {
    v13 = materials;
    v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v14 != nullptr )
    {
      v14[1].m_nUserID = 1;
      v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v14[2].__vftable = (CFunctor_vtbl *) __thiscall IMaterialSystem::`vcall'{560,{flat}};
      v14[2].m_nUserID = (unsigned int)v13;
      v12->QueueFunctorInternal(this: v12, a2: v14);
    }
    else
    {
      v12->QueueFunctorInternal(this: v12, a2: nullptr);
    }
  }
  else
  {
    materials->EndUpdatePaintmaps(this: materials);
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x101CB000
// Name: public: void CPaintTextureData::GetSurfacePaintData(struct msurface2_t __near *,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintTextureData::GetSurfacePaintData(
        CPaintTextureData *this,
        msurface2_t *surfID,
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *data)
{
  _WORD *v3; // eax
  int v4; // ebx
  int v5; // esi
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // esi
  __int16 x; // [esp+0h] [ebp-8h]
  __int16 y; // [esp+10h] [ebp+8h]
  const unsigned __int8 *pEnd; // [esp+14h] [ebp+Ch]

  if ( this->m_backbuffer != nullptr )
  {
    v3 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                   + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
    x = v3[4];
    y = v3[5];
    v4 = (__int16)(v3[2] + 1);
    v5 = v4 * (__int16)(v3[3] + 1);
    CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(this: data, num: v5 + (4 - v5 % 4) % 4);
    m_pMemory = data->m_Memory.m_pMemory;
    v7 = &data->m_Memory.m_pMemory[v5];
    v8 = &this->m_backbuffer[x + this->m_nPaintWidth * y];
    for ( pEnd = v7; m_pMemory < pEnd; m_pMemory += v4 )
    {
      _V_memcpy(dest: m_pMemory, src: v8, count: v4);
      v8 += this->m_nPaintWidth;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB0D0
// Name: void R_PaintLeaf(struct mleaf_t __near *,struct paintinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_PaintLeaf(mleaf_t *pLeaf, paintinfo_t *paintinfo)
{
  int v2; // eax
  msurface2_t *v3; // ecx
  unsigned int flags; // eax
  int m_Size; // edx
  CUtlMemory<S3RGBA,int> *p_m_aApplySurfs; // ebx
  int v7; // eax
  S3RGBA *m_pMemory; // esi
  float *p_x; // eax
  float v10; // xmm1_4
  float y; // xmm5_4
  float v12; // xmm2_4
  float z; // xmm6_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float m_flSize; // xmm1_4
  float v18; // xmm0_4
  unsigned int flags_high; // edx
  mvertex_t *vertexes; // esi
  unsigned __int16 *v21; // ecx
  mvertex_t *v22; // eax
  float v23; // edi
  unsigned __int16 *v24; // edi
  mvertex_t *v25; // eax
  float v26; // ecx
  float v27; // edx
  mvertex_t *v28; // eax
  float v29; // ecx
  float v30; // edx
  float v31; // eax
  Vector *ClosestPointToTriangle; // eax
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  int v39; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v41; // ecx
  int v42; // eax
  S3RGBA *v43; // esi
  int nummarksurfaces; // edx
  Vector result; // [esp+0h] [ebp-88h] BYREF
  float v46; // [esp+14h] [ebp-74h]
  Vector c; // [esp+18h] [ebp-70h] BYREF
  Vector b; // [esp+24h] [ebp-64h] BYREF
  float v49; // [esp+34h] [ebp-54h]
  float v50; // [esp+38h] [ebp-50h]
  Vector a; // [esp+3Ch] [ebp-4Ch] BYREF
  float v52; // [esp+48h] [ebp-40h]
  msurface2_t **pHandle; // [esp+4Ch] [ebp-3Ch]
  msurface2_t *v54; // [esp+50h] [ebp-38h]
  unsigned int v55; // [esp+54h] [ebp-34h]
  VPlane v56; // [esp+58h] [ebp-30h]
  int i; // [esp+68h] [ebp-20h]
  float v58; // [esp+6Ch] [ebp-1Ch]
  float v59; // [esp+70h] [ebp-18h]
  float v60; // [esp+74h] [ebp-14h]
  float v61; // [esp+78h] [ebp-10h]
  float v62; // [esp+7Ch] [ebp-Ch]
  float x; // [esp+80h] [ebp-8h]
  char v64; // [esp+87h] [ebp-1h]

  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v2 = 0;
  i = 0;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v3 = pHandle[v2];
      flags = v3->flags;
      v54 = v3;
      if ( (flags & 0x100020) == 0 && (flags & 0x800) == 0 )
      {
        m_Size = paintinfo->m_aApplySurfs.m_Size;
        p_m_aApplySurfs = (CUtlMemory<S3RGBA,int> *)&paintinfo->m_aApplySurfs;
        v7 = 0;
        if ( m_Size <= 0 )
          goto LABEL_10;
        m_pMemory = p_m_aApplySurfs->m_pMemory;
        while ( (msurface2_t *)*m_pMemory != v3 )
        {
          ++v7;
          ++m_pMemory;
          if ( v7 >= m_Size )
            goto LABEL_10;
        }
        if ( v7 == -1 )
        {
LABEL_10:
          if ( materialSortInfoArray != nullptr && materialSortInfoArray[v3->materialSortID].lightmapPageID >= 0 )
          {
            p_x = &v3->plane->normal.x;
            v10 = *p_x;
            y = paintinfo->m_vPosition.y;
            v12 = p_x[1];
            z = paintinfo->m_vPosition.z;
            v14 = p_x[2];
            v15 = p_x[3];
            x = paintinfo->m_vPosition.x;
            v61 = y;
            v62 = z;
            v16 = (float)(x * v10) + (float)(y * v12);
            v56.m_Normal.x = v10;
            m_flSize = paintinfo->m_flSize;
            v18 = (float)(v16 + (float)(z * v14)) - v15;
            v56.m_Normal.y = v12;
            v56.m_Normal.z = v14;
            v56.m_Dist = v15;
            if ( v18 <= m_flSize && v18 >= 0.0 )
            {
              flags_high = HIBYTE(v3->flags);
              vertexes = host_state.worldbrush->vertexes;
              v21 = &host_state.worldbrush->vertindices[v3->firstvertindex];
              v22 = &vertexes[*v21];
              a.x = v22->position.x;
              v23 = v22->position.y;
              a.z = v22->position.z;
              a.y = v23;
              v64 = 0;
              if ( flags_high > 2 )
              {
                v52 = m_flSize;
                v24 = v21 + 1;
                v55 = flags_high - 2;
                do
                {
                  v25 = &vertexes[*v24];
                  v26 = v25->position.y;
                  b.x = v25->position.x;
                  v27 = v25->position.z;
                  v28 = &vertexes[v24[1]];
                  b.y = v26;
                  v29 = v28->position.x;
                  b.z = v27;
                  v30 = v28->position.y;
                  v31 = v28->position.z;
                  c.x = v29;
                  c.y = v30;
                  c.z = v31;
                  ClosestPointToTriangle = FindClosestPointToTriangle(&result, p: &paintinfo->m_vPosition, &a, &b, &c);
                  v33 = ClosestPointToTriangle->x;
                  v34 = ClosestPointToTriangle->y;
                  v35 = ClosestPointToTriangle->z;
                  v36 = (float)((float)((float)(ClosestPointToTriangle->x * v56.m_Normal.x)
                                      + (float)(v34 * v56.m_Normal.y))
                              + (float)(v56.m_Normal.z * v35))
                      - v56.m_Dist;
                  if ( v36 < 0.0 )
                  {
                    v37 = v36 + 0.1;
                    v33 = (float)(v37 * v56.m_Normal.x) + v33;
                    v34 = (float)(v37 * v56.m_Normal.y) + v34;
                    v35 = (float)(v37 * v56.m_Normal.z) + v35;
                  }
                  if ( (float)(v52 * v52) > (float)((float)((float)((float)(v61 - v34) * (float)(v61 - v34))
                                                          + (float)((float)(x - v33) * (float)(x - v33)))
                                                  + (float)((float)(v62 - v35) * (float)(v62 - v35))) )
                  {
                    if ( v64 == 0
                      || (v46 = v60 - v62,
                          v49 = v34 - v61,
                          v50 = v35 - v62,
                          (float)((float)((float)((float)(v59 - v61) * (float)(v59 - v61))
                                        + (float)((float)(v58 - x) * (float)(v58 - x)))
                                + (float)((float)(v60 - v62) * (float)(v60 - v62))) > (float)((float)((float)((float)(v34 - v61) * (float)(v34 - v61)) + (float)((float)(v33 - x) * (float)(v33 - x)))
                                                                                            + (float)((float)(v35 - v62) * (float)(v35 - v62)))) )
                    {
                      v60 = v35;
                      v59 = v34;
                      v58 = v33;
                    }
                    v64 = 1;
                  }
                  ++v24;
                  --v55;
                }
                while ( v55 != 0 );
                if ( v64 != 0 )
                {
                  v38 = (float)((float)((float)(v59 - v61) * (float)(v59 - v61))
                              + (float)((float)(v58 - x) * (float)(v58 - x)))
                      + (float)((float)(v60 - v62) * (float)(v60 - v62));
                  if ( paintinfo->m_flCurrentDistance > v38 )
                  {
                    paintinfo->m_flCurrentDistance = v38;
                    paintinfo->m_plane = v56;
                  }
                  v39 = paintinfo->m_aApplySurfs.m_Size;
                  m_nAllocationCount = paintinfo->m_aApplySurfs.m_Memory.m_nAllocationCount;
                  if ( v39 + 1 > m_nAllocationCount )
                    CUtlMemory<INetMessage *,int>::Grow(this: p_m_aApplySurfs, num: v39 - m_nAllocationCount + 1);
                  ++paintinfo->m_aApplySurfs.m_Size;
                  v41 = p_m_aApplySurfs->m_pMemory;
                  v42 = paintinfo->m_aApplySurfs.m_Size - v39 - 1;
                  paintinfo->m_aApplySurfs.m_pElements = paintinfo->m_aApplySurfs.m_Memory.m_pMemory;
                  if ( v42 > 0 )
                    _V_memmove(dest: &v41[v39 + 1], src: &v41[v39], count: 4 * v42);
                  v43 = &p_m_aApplySurfs->m_pMemory[v39];
                  if ( v43 != nullptr )
                    *v43 = (S3RGBA)v54;
                }
              }
            }
          }
        }
      }
      nummarksurfaces = pLeaf->nummarksurfaces;
      v2 = i + 1;
      i = v2;
    }
    while ( v2 < nummarksurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB4D0
// Name: void R_PaintNode(struct mnode_t __near *,struct paintinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_PaintNode(mnode_t *node, paintinfo_t *paintinfo)
{
  mnode_t *v2; // esi
  float v3; // xmm0_4
  float m_flSize; // xmm1_4

  v2 = node;
  if ( node != nullptr )
  {
    while ( v2->contents < 0 )
    {
      v3 = (float)((float)((float)(v2->plane->normal.y * paintinfo->m_vPosition.y)
                         + (float)(v2->plane->normal.x * paintinfo->m_vPosition.x))
                 + (float)(v2->plane->normal.z * paintinfo->m_vPosition.z))
         - v2->plane->dist;
      m_flSize = paintinfo->m_flSize;
      if ( v3 <= m_flSize )
      {
        if ( COERCE_FLOAT(LODWORD(m_flSize) ^ _mask__NegFloat_) <= v3 )
          R_PaintNode(node: v2->children[0], paintinfo);
        v2 = v2->children[1];
      }
      else
      {
        v2 = v2->children[0];
      }
      if ( v2 == nullptr )
        return;
    }
    R_PaintLeaf(pLeaf: (mleaf_t *)v2, paintinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB650
// Name: void R_RedownloadAllPaintmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_RedownloadAllPaintmaps()
{
  int v0; // edx
  int v1; // ecx

  if ( g_PaintManager.m_bShouldRegister )
  {
    v0 = 0;
    if ( g_PaintManager.m_iPaintmaps > 0 )
    {
      v1 = 0;
      do
      {
        ++v0;
        g_PaintManager.m_pPaintTextureDataArray[v1++].m_nDirtyFlag = PAINTMAP_DIRTY_FULLRECT;
      }
      while ( v0 < g_PaintManager.m_iPaintmaps );
    }
    CPaintmapDataManager::UpdatePaintmapTextures(this: &g_PaintManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB6A0
// Name: void EncodeDataRLE(unsigned int const __near *,unsigned int,class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EncodeDataRLE(
        const unsigned int *pBuffer,
        int nDwordCount,
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *data)
{
  const unsigned int *v3; // ebx
  const unsigned int *v4; // esi
  const unsigned int *v5; // edi
  unsigned int v6; // ecx
  const unsigned int *v7; // eax
  unsigned int v8; // edi
  int v9; // edx
  int v10; // edi
  int v11; // ebx
  int *m_pMemory; // edx
  unsigned int *v13; // eax
  int *v14; // edi
  int *v15; // ecx
  int v16; // edx
  unsigned int *v17; // esi
  CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int> > v18; // [esp+4h] [ebp-1034h] BYREF
  unsigned int v19; // [esp+101Ch] [ebp-1Ch]
  int src; // [esp+1020h] [ebp-18h] BYREF
  int v21; // [esp+1024h] [ebp-14h]
  unsigned int v22; // [esp+1028h] [ebp-10h]
  const unsigned int *v23; // [esp+102Ch] [ebp-Ch]
  const unsigned int *v24; // [esp+1030h] [ebp-8h]
  int v25; // [esp+1034h] [ebp-4h] BYREF
  int num; // [esp+1044h] [ebp+Ch]

  if ( nDwordCount != 0 )
  {
    v18.m_Memory.m_pMemory = v18.m_Memory.m_pFixedMemory;
    v18.m_pElements = v18.m_Memory.m_pFixedMemory;
    v3 = &pBuffer[nDwordCount];
    v4 = pBuffer + 2;
    v5 = pBuffer;
    v21 = *pBuffer;
    v6 = pBuffer[1];
    v7 = pBuffer + 34;
    v18.m_Memory.m_nAllocationCount = 1024;
    v18.m_Memory.m_nGrowSize = -1;
    v18.m_Memory.m_nMallocGrowSize = 0;
    v18.m_Size = 0;
    v23 = pBuffer;
    v22 = v6;
    num = 0;
    v24 = pBuffer + 34;
    if ( pBuffer + 2 < v3 )
    {
      while ( 1 )
      {
        v8 = *v4;
        v19 = *v4;
        if ( v21 == v6 && v6 == v8 )
        {
          v9 = (int)(v4 - 2);
          v25 = (int)(v4 - 2);
          v10 = v4 - 2 - v23;
          src = v10;
          if ( v10 != 0 )
          {
            CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, &src);
            src = (int)v23;
            CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, &src);
            v7 = v24;
            num += v10 + 1;
            v9 = v25;
          }
          if ( ++v4 < v3 )
          {
            do
            {
              if ( *v4 != v21 )
                break;
              if ( ++v4 >= v7 && v7 < v3 - 256 )
                v7 += 32;
            }
            while ( v4 < v3 );
            v24 = v7;
          }
          v25 = -(((int)v4 - v9) >> 2);
          CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, src: &v25);
          v25 = v21;
          CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, src: &v25);
          num += 2;
          if ( v4 < v3 )
          {
            v19 = *v4;
            v22 = v19 + 1;
          }
          v6 = v22;
          v7 = v24;
          v8 = v19;
          v23 = v4;
        }
        ++v4;
        v21 = v6;
        v22 = v8;
        if ( v4 >= v7 && v7 < v3 - 256 )
        {
          v7 += 32;
          v24 = v7;
        }
        if ( v4 >= v3 )
          break;
        v6 = v22;
      }
      v5 = v23;
    }
    v11 = v3 - v5;
    v25 = v11;
    if ( v11 != 0 )
    {
      CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, src: &v25);
      v25 = (int)v5;
      CUtlVector<int,CUtlMemoryFixedGrowable<int,1024,int>>::InsertBefore(this: &v18, elem: v18.m_Size, src: &v25);
      num += v11 + 1;
    }
    data->m_Size = 0;
    CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
      this: data,
      elem: 0,
      num);
    m_pMemory = v18.m_Memory.m_pMemory;
    v13 = (unsigned int *)data->m_Memory.m_pMemory;
    v14 = &v18.m_Memory.m_pMemory[v18.m_Size];
    v15 = v18.m_Memory.m_pMemory;
    if ( v18.m_Memory.m_pMemory < v14 )
    {
      do
      {
        v16 = *v15;
        *v13 = *v15;
        if ( v16 >= 0 )
        {
          v17 = (unsigned int *)v15[1];
          ++v13;
          v15 += 2;
          if ( v16 > 0 )
          {
            do
            {
              *v13++ = *v17++;
              --v16;
            }
            while ( v16 != 0 );
          }
        }
        else
        {
          v13[1] = v15[1];
          v13 += 2;
          v15 += 2;
        }
      }
      while ( v15 < v14 );
      m_pMemory = v18.m_Memory.m_pMemory;
    }
    v18.m_Size = 0;
    if ( v18.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        v18.m_Memory.m_pMemory = nullptr;
      }
      v18.m_Memory.m_nAllocationCount = 0;
    }
    v18.m_pElements = m_pMemory;
    if ( v18.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CB930
// Name: public: void CPaintmapDataManager::GetPaintmapDataRLE(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::GetPaintmapDataRLE(
        CPaintmapDataManager *this,
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *data)
{
  worldbrushdata_t *worldbrush; // eax
  msurface2_t *v3; // eax
  CPaintTextureData *v4; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  unsigned int *v9; // edi
  int v10; // edi
  int v11; // eax
  unsigned int *v12; // ecx
  int v13; // eax
  unsigned int *v14; // eax
  int v15; // ecx
  unsigned int *v16; // edi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > rleData; // [esp+4h] [ebp-34h] BYREF
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > surfPaintData; // [esp+18h] [ebp-20h] BYREF
  CPaintmapDataManager *v19; // [esp+2Ch] [ebp-Ch]
  unsigned int v20; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  v19 = this;
  i = 0;
  if ( host_state.worldbrush->numsurfaces > 0 )
  {
    v20 = 0;
    do
    {
      v3 = &worldbrush->surfaces2[v20 / 0x20];
      if ( (v3->flags & 0x200000) != 0 )
      {
        v4 = &v19->m_pPaintTextureDataArray[materialSortInfoArray[v3->materialSortID].lightmapPageID];
        memset(&surfPaintData, 0, sizeof(surfPaintData));
        CPaintTextureData::GetSurfacePaintData(this: v4, surfID: v3, data: &surfPaintData);
        memset(&rleData, 0, sizeof(rleData));
        EncodeDataRLE(
          pBuffer: (const unsigned int *)surfPaintData.m_Memory.m_pMemory,
          nDwordCount: surfPaintData.m_Size / 4,
          data: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&rleData);
        m_Size = data->m_Size;
        m_nAllocationCount = data->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)data,
            num: m_Size - m_nAllocationCount + 1);
        ++data->m_Size;
        m_pMemory = data->m_Memory.m_pMemory;
        v8 = data->m_Size - m_Size - 1;
        data->m_pElements = data->m_Memory.m_pMemory;
        if ( v8 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
        v9 = &data->m_Memory.m_pMemory[m_Size];
        if ( v9 != nullptr )
          *v9 = i;
        v10 = data->m_Size;
        v11 = data->m_Memory.m_nAllocationCount;
        if ( v10 + 1 > v11 )
          CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)data, num: v10 - v11 + 1);
        ++data->m_Size;
        v12 = data->m_Memory.m_pMemory;
        v13 = data->m_Size - v10 - 1;
        data->m_pElements = data->m_Memory.m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
        v14 = &data->m_Memory.m_pMemory[v10];
        v15 = rleData.m_Size;
        if ( v14 != nullptr )
          *v14 = rleData.m_Size;
        v16 = rleData.m_Memory.m_pMemory;
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
          this: data,
          elem: data->m_Size,
          num: v15,
          pToInsert: rleData.m_Memory.m_pMemory);
        if ( rleData.m_Memory.m_nGrowSize >= 0 && v16 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        if ( surfPaintData.m_Memory.m_nGrowSize >= 0 && surfPaintData.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfPaintData.m_Memory.m_pMemory);
      }
      worldbrush = host_state.worldbrush;
      v20 += 32;
      ++i;
    }
    while ( i < host_state.worldbrush->numsurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CBBB0
// Name: public: void CPaintmapDataManager::RemovePaint(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::RemovePaint(CPaintmapDataManager *this, const model_t *pModel)
{
  const model_t *v2; // eax
  CPaintmapDataManager *v3; // esi
  msurface2_t *v4; // eax
  int materialSortID; // ecx
  msurfacelighting_t *surfacelighting; // edx
  unsigned int v7; // eax
  int v8; // edi
  CPaintTextureData *v9; // ecx
  __int16 *v10; // eax
  int v11; // edx
  int v12; // esi
  int v13; // edi
  int v14; // eax
  unsigned __int8 *v15; // esi
  CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *p_m_dirtyRects; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int v19; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v21; // eax
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v22; // ebx
  vgui::Panel *rect; // [esp+4h] [ebp-24h]
  vgui::Panel *rect_4; // [esp+8h] [ebp-20h]
  int rect_12; // [esp+10h] [ebp-18h]
  int v26; // [esp+14h] [ebp-14h]
  unsigned int count; // [esp+18h] [ebp-10h]
  int counta; // [esp+18h] [ebp-10h]
  int y; // [esp+20h] [ebp-8h]
  unsigned __int8 *ya; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v2 = pModel;
  v3 = this;
  if ( pModel != nullptr && this->m_pPaintTextureDataArray != nullptr )
  {
    i = 0;
    if ( pModel->brush.nummodelsurfaces > 0 )
    {
      while ( 1 )
      {
        v4 = &host_state.worldbrush->surfaces2[i + v2->brush.firstmodelsurface];
        materialSortID = v4->materialSortID;
        surfacelighting = host_state.worldbrush->surfacelighting;
        v7 = ((char *)v4 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
        v8 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v7);
        v9 = &v3->m_pPaintTextureDataArray[materialSortInfoArray[materialSortID].lightmapPageID];
        v10 = (__int16 *)((char *)surfacelighting->m_LightmapMins + v7);
        rect = (vgui::Panel *)v10[4];
        rect_4 = (vgui::Panel *)v10[5];
        v11 = v10[3] + 1;
        v12 = 0;
        v13 = v8 + 1;
        rect_12 = v11;
        for ( y = 0; v12 < v11; y = v12 )
        {
          v14 = 0;
          if ( v13 > 0 )
          {
            count = (unsigned int)rect_4 + v12;
            do
            {
              v15 = &v9->m_backbuffer[count * v9->m_nPaintWidth + v14++];
              *((_BYTE *)&rect->__vftable + (_DWORD)v15) = 0x80;
            }
            while ( v14 < v13 );
            v12 = y;
          }
          ++v12;
        }
        p_m_dirtyRects = (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&v9->m_dirtyRects;
        v9->m_nDirtyFlag = (v9->m_nDirtyFlag == PAINTMAP_DIRTY_FULLRECT) + 1;
        m_Size = v9->m_dirtyRects.m_Size;
        m_nAllocationCount = v9->m_dirtyRects.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          v19 = m_Size - m_nAllocationCount + 1;
          v26 = v19;
          if ( p_m_dirtyRects->m_nGrowSize < 0 )
          {
            p_m_dirtyRects->m_nGrowSize = (int)p_m_dirtyRects[1].m_pMemory;
            if ( m_nAllocationCount != 0 )
            {
              counta = 16 * m_nAllocationCount;
              ya = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nAllocationCount);
              memcpy(dst: ya, src: (unsigned __int8 *)p_m_dirtyRects->m_pMemory, count: counta);
              v19 = v26;
              p_m_dirtyRects->m_pMemory = (UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *)ya;
            }
            else
            {
              p_m_dirtyRects->m_pMemory = nullptr;
            }
          }
          CUtlMemory<CPortalRect,int>::Grow(this: p_m_dirtyRects, num: v19);
          v11 = rect_12;
        }
        ++p_m_dirtyRects[1366].m_nGrowSize;
        m_pMemory = (unsigned __int8 *)p_m_dirtyRects->m_pMemory;
        v21 = p_m_dirtyRects[1366].m_nGrowSize - m_Size - 1;
        p_m_dirtyRects[1367].m_pMemory = p_m_dirtyRects->m_pMemory;
        if ( v21 > 0 )
        {
          _V_memmove(dest: &m_pMemory[16 * m_Size + 16], src: &m_pMemory[16 * m_Size], count: 16 * v21);
          v11 = rect_12;
        }
        v22 = &p_m_dirtyRects->m_pMemory[m_Size];
        if ( v22 != nullptr )
        {
          v22->m_Element.panel = rect;
          v22->m_Element.labelPanel = rect_4;
          v22->m_Previous = v13;
          v22->m_Next = v11;
        }
        if ( ++i >= pModel->brush.nummodelsurfaces )
          break;
        v3 = this;
        v2 = pModel;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CBD70
// Name: public: virtual void CPaintmapDataManager::BeginPaintmapsDataAllocation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::BeginPaintmapsDataAllocation(
        CPaintmapDataManager *this,
        unsigned int iPaintmapCount)
{
  int v3; // ecx
  unsigned int *v4; // eax
  CPaintTextureData *v5; // eax
  int v6; // esi
  CPaintTextureData *v7; // ecx
  Rect_t *m_pFixedMemory; // eax
  int iPaintmapCounta; // [esp+10h] [ebp+8h]

  this->DestroyPaintmapsData(this);
  this->m_iPaintmaps = iPaintmapCount;
  v3 = (16428 * (unsigned __int64)iPaintmapCount) >> 32 != 0 ? -1 : 16428 * iPaintmapCount;
  v4 = (unsigned int *)MemAlloc_Alloc(nSize: __CFADD__(v3, 4) ? -1 : v3 + 4);
  if ( v4 != nullptr )
  {
    *v4 = iPaintmapCount;
    v5 = (CPaintTextureData *)(v4 + 1);
    v6 = iPaintmapCount - 1;
    iPaintmapCounta = (int)v5;
    v7 = v5;
    if ( v6 >= 0 )
    {
      m_pFixedMemory = v5->m_dirtyRects.m_Memory.m_pFixedMemory;
      do
      {
        m_pFixedMemory[-1].x = (int)m_pFixedMemory;
        m_pFixedMemory[-1].y = 1024;
        m_pFixedMemory[-1].width = -1;
        m_pFixedMemory[-1].height = 0;
        m_pFixedMemory[1024].x = 0;
        m_pFixedMemory[1024].y = (int)m_pFixedMemory;
        m_pFixedMemory[-2].x = 0;
        v7->m_nPaintWidth = 0;
        m_pFixedMemory[-2].width = 0;
        m_pFixedMemory[-2].height = 0;
        ++v7;
        m_pFixedMemory = (Rect_t *)((char *)m_pFixedMemory + 16428);
        --v6;
      }
      while ( v6 >= 0 );
      v5 = (CPaintTextureData *)iPaintmapCounta;
    }
    this->m_pPaintTextureDataArray = v5;
  }
  else
  {
    this->m_pPaintTextureDataArray = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CBF50
// Name: public: void CPaintTextureData::SetSurfacePaintData(struct msurface2_t __near *,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintTextureData::SetSurfacePaintData(
        CPaintTextureData *this,
        msurface2_t *surfID,
        const CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *data)
{
  unsigned __int8 *m_backbuffer; // eax
  __int16 *v4; // eax
  int v5; // edx
  unsigned __int8 *m_pMemory; // ebx
  unsigned __int8 *v7; // esi
  int v8; // edi
  char *v9; // esi
  BOOL v10; // eax
  CUtlVectorFixedGrowable<Rect_t,1024> *p_m_dirtyRects; // ecx
  Rect_t rect; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 *v13; // [esp+10h] [ebp-8h]
  CPaintTextureData *v14; // [esp+14h] [ebp-4h]
  const unsigned __int8 *pEnd; // [esp+24h] [ebp+Ch]

  m_backbuffer = this->m_backbuffer;
  v14 = this;
  v13 = m_backbuffer;
  if ( m_backbuffer != nullptr )
  {
    v4 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                   + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
    v5 = v4[4];
    rect.y = v4[5];
    m_pMemory = data->m_Memory.m_pMemory;
    v7 = &v13[rect.y * this->m_nPaintWidth];
    v8 = v4[2] + 1;
    rect.height = v4[3] + 1;
    v9 = (char *)&v7[v5];
    rect.x = v5;
    rect.width = v8;
    for ( pEnd = &m_pMemory[v8 * rect.height]; m_pMemory < pEnd; m_pMemory += v8 )
    {
      _V_memcpy(dest: v9, src: m_pMemory, count: v8);
      this = v14;
      v9 += v14->m_nPaintWidth;
    }
    v10 = this->m_nDirtyFlag == PAINTMAP_DIRTY_FULLRECT;
    p_m_dirtyRects = &this->m_dirtyRects;
    p_m_dirtyRects[-1].m_pElements = (Rect_t *)(v10 + 1);
    CUtlVector<Rect_t,CUtlMemoryFixedGrowable<Rect_t,1024,int>>::InsertBefore(
      this: p_m_dirtyRects,
      elem: p_m_dirtyRects->m_Size,
      src: &rect);
    surfID->flags |= 0x200000u;
    MarkSurfaceBrushes(nSurfIndex: surfID - host_state.worldbrush->surfaces2, pData: host_state.worldbrush);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC020
// Name: public: void CPaintmapDataManager::LoadPaintmapDataRLE(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::LoadPaintmapDataRLE(CPaintmapDataManager *this, unsigned int data)
{
  unsigned int *v2; // edi
  const unsigned int *v3; // eax
  msurface2_t *v4; // ebx
  const unsigned int *v5; // edi
  char *v6; // ecx
  int v7; // eax
  unsigned __int8 *m_pMemory; // edx
  int v9; // esi
  bool v10; // zf
  int v11; // esi
  int m_Size; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > rawPaintData; // [esp+4h] [ebp-20h] BYREF
  const unsigned int *pEnd; // [esp+18h] [ebp-Ch]
  CPaintmapDataManager *v15; // [esp+1Ch] [ebp-8h]
  int lightmapID; // [esp+20h] [ebp-4h]
  unsigned int nRLESize; // [esp+2Ch] [ebp+8h]

  v2 = *(unsigned int **)data;
  v3 = (const unsigned int *)(*(_DWORD *)data + 4 * *(_DWORD *)(data + 12));
  v15 = this;
  pEnd = v3;
  while ( v2 < pEnd )
  {
    v4 = &host_state.worldbrush->surfaces2[*v2];
    v5 = v2 + 2;
    nRLESize = *(v5 - 1);
    v6 = (char *)host_state.worldbrush->surfacelighting
       + (((char *)v4 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
    v7 = (*((__int16 *)v6 + 2) + 1) * (*((__int16 *)v6 + 3) + 1);
    lightmapID = materialSortInfoArray[v4->materialSortID].lightmapPageID;
    m_pMemory = nullptr;
    memset(&rawPaintData, 0, sizeof(rawPaintData));
    v9 = (4 - v7 % 4) % 4;
    v10 = v7 + v9 == 0;
    v11 = v7 + v9;
    m_Size = 0;
    if ( !v10 )
    {
      if ( v11 > 0 )
      {
        CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&rawPaintData, num: v11);
        m_Size = rawPaintData.m_Size;
        m_pMemory = rawPaintData.m_Memory.m_pMemory;
      }
      rawPaintData.m_Size = v11 + m_Size;
      rawPaintData.m_pElements = m_pMemory;
      if ( m_Size > 0 && v11 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v11], src: m_pMemory, count: m_Size);
        m_pMemory = rawPaintData.m_Memory.m_pMemory;
      }
    }
    DecodeDataRLE(pRLEStart: v5, rleCount: nRLESize, surfID: v4, pOutput: (unsigned int *)m_pMemory);
    v2 = (unsigned int *)&v5[nRLESize];
    CPaintTextureData::SetSurfacePaintData(
      this: &v15->m_pPaintTextureDataArray[lightmapID],
      surfID: v4,
      data: &rawPaintData);
    if ( rawPaintData.m_Memory.m_nGrowSize >= 0 && rawPaintData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rawPaintData.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC160
// Name: bool R_PaintSurface(struct msurface2_t __near *,class Vector const __near &,float,class VPlane const __near &,unsigned char,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl R_PaintSurface(
        msurface2_t *surfID,
        const Vector *vPosition,
        float flSphereRadius,
        const VPlane *basePlane,
        unsigned __int8 colorIndex,
        float flPaintCoatPercent)
{
  int lightmapPageID; // edi
  PaintRect_t paintRect; // [esp+14h] [ebp-2Ch] BYREF
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  lightmapPageID = materialSortInfoArray[surfID->materialSortID].lightmapPageID;
  paintRect.colorIndex = colorIndex;
  paintRect.flPaintCoatPercent = flPaintCoatPercent;
  if ( !ComputePaintRect(a1: (int)&savedregs, surfID, vPosition, flSphereRadius, &paintRect)
    || !CPaintTextureData::Paint(this: &g_PaintManager.m_pPaintTextureDataArray[lightmapPageID], &paintRect) )
  {
    return 0;
  }
  surfID->flags |= 0x200000u;
  MarkSurfaceBrushes(nSurfIndex: surfID - host_state.worldbrush->surfaces2, pData: host_state.worldbrush);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CC1F0
// Name: bool ShootPaintSphere(struct model_t const __near *,class Vector const __near &,unsigned char,float,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShootPaintSphere(
        const model_t *pModel,
        const Vector *vPosition,
        unsigned __int8 colorIndex,
        float flSphereRadius,
        float flPaintCoatPercent)
{
  char v5; // bl
  worldbrushdata_t *pShared; // ecx
  int firstnode; // eax
  int v8; // edi
  paintinfo_t paintinfo; // [esp+1Ch] [ebp-44h] BYREF
  int numSurf; // [esp+5Ch] [ebp-4h]

  v5 = 0;
  if ( !g_PaintManager.m_bShouldRegister || g_PaintManager.m_pPaintTextureDataArray == nullptr || pModel == nullptr )
    return 0;
  pShared = pModel->brush.pShared;
  firstnode = pModel->brush.firstnode;
  paintinfo.m_vPosition = *vPosition;
  paintinfo.m_flSize = flSphereRadius;
  memset(&paintinfo.m_aApplySurfs, 0, sizeof(paintinfo.m_aApplySurfs));
  paintinfo.m_flCurrentDistance = 3.4028235e38;
  paintinfo.m_pBrush = pShared;
  paintinfo.m_bPainting = true;
  R_PaintNode(node: &pShared->nodes[firstnode], &paintinfo);
  v8 = 0;
  for ( numSurf = paintinfo.m_aApplySurfs.m_Size; v8 < numSurf; ++v8 )
  {
    if ( IsSurfaceInFrontOfPlane(surfID: paintinfo.m_aApplySurfs.m_Memory.m_pMemory[v8], plane: &paintinfo.m_plane)
      && R_PaintSurface(
           surfID: paintinfo.m_aApplySurfs.m_Memory.m_pMemory[v8],
           vPosition,
           flSphereRadius,
           basePlane: &paintinfo.m_plane,
           colorIndex,
           flPaintCoatPercent) != 0 )
    {
      v5 = 1;
    }
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&paintinfo.m_aApplySurfs);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101CC300
// Name: public: virtual void CPaintmapDataManager::DestroyPaintmapsData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintmapDataManager::DestroyPaintmapsData(CPaintmapDataManager *this)
{
  int v2; // ebx
  CPaintTextureData *m_pPaintTextureDataArray; // esi
  CPaintTextureData *v4; // ecx
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( this->m_pPaintTextureDataArray != nullptr )
  {
    for ( i = 0; i != this->m_iPaintmaps; ++i )
    {
      m_pPaintTextureDataArray = this->m_pPaintTextureDataArray;
      if ( m_pPaintTextureDataArray[v2].m_backbuffer != nullptr )
      {
        free(pMem: m_pPaintTextureDataArray[v2].m_backbuffer);
        m_pPaintTextureDataArray[v2].m_backbuffer = nullptr;
      }
      ++v2;
    }
    v4 = this->m_pPaintTextureDataArray;
    if ( v4 != nullptr )
      CPaintTextureData::`vector deleting destructor'(this: v4, a2: 3u);
    this->m_pPaintTextureDataArray = nullptr;
    this->m_iPaintmaps = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027B930
// Name: public: virtual void CFunctor4<void (*)(class Vector const __near &,class Vector const __near &,class Color,bool),class Vector,class Vector,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor4<void (__cdecl *)(Vector const &,Vector const &,Color,bool),Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor4<void (__cdecl*)(Vector const &,Vector const &,Color,bool),Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, Vector *, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: *(_DWORD *)&this->m_arg3,
    a4: this->m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x1031D450
// Name: _dynamic_initializer_for__paint_max_surface_border_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__paint_max_surface_border_alpha__()
{
  ConVar::ConVar(
    this: &paint_max_surface_border_alpha,
    pName: "paint_max_surface_border_alpha",
    pDefaultValue: "0.7f",
    flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__paint_max_surface_border_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D480
// Name: _dynamic_initializer_for__paint_alpha_offset_enabled__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__paint_alpha_offset_enabled__()
{
  ConVar::ConVar(
    this: &paint_alpha_offset_enabled,
    pName: "paint_alpha_offset_enabled",
    pDefaultValue: "1",
    flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__paint_alpha_offset_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D540
// Name: _dynamic_initializer_for__paint_min_valid_alpha_value__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__paint_min_valid_alpha_value__()
{
  ConVar::ConVar(
    this: &paint_min_valid_alpha_value,
    pName: "paint_min_valid_alpha_value",
    pDefaultValue: "0.7f",
    flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__paint_min_valid_alpha_value__);
}

//------------------------------------------------------------------------------
// Address: 0x10326790
// Name: _dynamic_atexit_destructor_for__paint_max_surface_border_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paint_max_surface_border_alpha__()
{
  ConVar::~ConVar(this: &paint_max_surface_border_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x103267A0
// Name: _dynamic_atexit_destructor_for__paint_alpha_offset_enabled__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paint_alpha_offset_enabled__()
{
  ConVar::~ConVar(this: &paint_alpha_offset_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103267E0
// Name: _dynamic_atexit_destructor_for__paint_min_valid_alpha_value__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paint_min_valid_alpha_value__()
{
  ConVar::~ConVar(this: &paint_min_valid_alpha_value);
}

//------------------------------------------------------------------------------
// Address: 0x1031D4B0
// Name: _dynamic_initializer_for__paintsplat_bias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__paintsplat_bias__()
{
  ConVar::ConVar(
    this: &paintsplat_bias,
    pName: "paintsplat_bias",
    pDefaultValue: "0.1f",
    flags: 24576,
    pHelpString: "Change bias value for computing circle buffer");
  return atexit(func: dynamic_atexit_destructor_for__paintsplat_bias__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D4E0
// Name: _dynamic_initializer_for__paintsplat_noise_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__paintsplat_noise_enabled__()
{
  ConVar::ConVar(this: &paintsplat_noise_enabled, pName: "paintsplat_noise_enabled", pDefaultValue: "1", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__paintsplat_noise_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D510
// Name: _dynamic_initializer_for__paintsplat_max_alpha_noise__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__paintsplat_max_alpha_noise__()
{
  ConVar::ConVar(
    this: &paintsplat_max_alpha_noise,
    pName: "paintsplat_max_alpha_noise",
    pDefaultValue: "0.1f",
    flags: 24576,
    pHelpString: "Max noise value of circle alpha");
  return atexit(func: dynamic_atexit_destructor_for__paintsplat_max_alpha_noise__);
}

//------------------------------------------------------------------------------
// Address: 0x103267B0
// Name: _dynamic_atexit_destructor_for__paintsplat_bias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paintsplat_bias__()
{
  ConVar::~ConVar(this: &paintsplat_bias);
}

//------------------------------------------------------------------------------
// Address: 0x103267C0
// Name: _dynamic_atexit_destructor_for__paintsplat_noise_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paintsplat_noise_enabled__()
{
  ConVar::~ConVar(this: &paintsplat_noise_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103267D0
// Name: _dynamic_atexit_destructor_for__paintsplat_max_alpha_noise__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__paintsplat_max_alpha_noise__()
{
  ConVar::~ConVar(this: &paintsplat_max_alpha_noise);
}

} // namespace engine_xlsp
