// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_virtualmesh.cpp
// Functions: 40
// ============================================================

#include "vphysics\physics_virtualmesh.h"

//------------------------------------------------------------------------------
// Address: 0x10027840
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-14h]
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = this->m_Head.value32.DepthAndSequence;
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100278A0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100278E0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10027920
// Name: public: static unsigned int CMeshInstance::ComputeRootLedgeSize(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__cdecl CMeshInstance::ComputeRootLedgeSize(const unsigned __int8 *pData)
{
  unsigned int v2; // edx
  const unsigned __int8 *p_triangleCount; // eax
  int v4; // esi
  int v5; // ecx
  unsigned int v6; // ecx
  int i; // [esp+4h] [ebp-Ch]
  packedhull_t *pHull; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]
  const unsigned __int8 *pDataa; // [esp+18h] [ebp+8h]

  if ( pData == nullptr )
    return nullptr;
  v2 = *pData;
  p_triangleCount = pData + 4;
  v4 = 16 * v2;
  v5 = 0;
  v9 = 0;
  pDataa = nullptr;
  pHull = (packedhull_t *)p_triangleCount;
  if ( v2 >= 2 )
  {
    v6 = ((v2 - 2) >> 1) + 1;
    i = 2 * v6;
    do
    {
      v9 += 16 * *p_triangleCount;
      pDataa += 16 * p_triangleCount[5];
      p_triangleCount += 10;
      --v6;
    }
    while ( v6 != 0 );
    p_triangleCount = &pHull->triangleCount;
    v5 = i;
  }
  if ( v5 < (int)v2 )
    v4 += 16 * p_triangleCount[4 * v5 + v5];
  return &pDataa[v9 + v4];
}

//------------------------------------------------------------------------------
// Address: 0x100279A0
// Name: public: unsigned int virtualmeshhull_t::TotalSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall virtualmeshhull_t::TotalSize(virtualmeshhull_t *this)
{
  virtualmeshhull_t *v1; // eax
  unsigned int hullCount; // esi
  int v3; // ebx
  int v4; // edi
  int v5; // ecx
  int v6; // edx
  unsigned __int8 *v7; // eax
  unsigned int v8; // edx
  int i; // [esp+Ch] [ebp-10h]
  virtualmeshhull_t *v11; // [esp+14h] [ebp-8h]
  int v12; // [esp+18h] [ebp-4h]

  v1 = this;
  hullCount = this->hullCount;
  v3 = 0;
  v4 = 0;
  v5 = 5 * hullCount + 4;
  v6 = 0;
  v11 = v1;
  v12 = 0;
  if ( hullCount >= 2 )
  {
    v7 = &v1[2].pad[2];
    v8 = ((hullCount - 2) >> 1) + 1;
    i = 2 * v8;
    do
    {
      v4 += 2 * (*(v7 - 5) + 2 * *(v7 - 7));
      v3 = v12 + 2 * (*v7 + 2 * *(v7 - 2));
      v7 += 10;
      --v8;
      v12 = v3;
    }
    while ( v8 != 0 );
    v1 = v11;
    v5 = 5 * hullCount + 4;
    v6 = i;
  }
  if ( v6 < (int)hullCount )
    v5 += 2 * (v1[v6 + 1].pad[v6 + 1] + 2 * *(&v1[v6 + 1].hullCount + v6));
  return v5 + v3 + v4;
}

//------------------------------------------------------------------------------
// Address: 0x10027A30
// Name: public: virtual unsigned int CPhysCollideVirtualMesh::GetSerializationSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollideVirtualMesh::GetSerializationSize(CPhysCollideVirtualMesh *this)
{
  virtualmeshhull_t *m_pHull; // ecx

  m_pHull = this->m_pHull;
  if ( m_pHull != nullptr )
    return virtualmeshhull_t::TotalSize(this: m_pHull);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10027A40
// Name: public: virtual unsigned int CPhysCollideVirtualMesh::SerializeToBuffer(char __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPhysCollideVirtualMesh::SerializeToBuffer(
        CPhysCollideVirtualMesh *this,
        char *pDest,
        bool bSwap)
{
  unsigned int result; // eax
  unsigned int v5; // esi

  result = this->GetSerializationSize(this);
  v5 = result;
  if ( result != 0 )
  {
    memcpy(dst: (unsigned __int8 *)pDest, src: (unsigned __int8 *)this->m_pHull, count: result);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027A70
// Name: public: virtual void CPhysCollideVirtualMesh::OutputDebugInfo(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideVirtualMesh::OutputDebugInfo(CPhysCollideVirtualMesh *this)
{
  _Msg(a1: "Virtual mesh!\n");
}

//------------------------------------------------------------------------------
// Address: 0x10027A80
// Name: public: virtual void IVP_SurfaceManager_VirtualMesh::remove_reference_to_ledge(class IVP_Compact_Ledge const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_VirtualMesh::remove_reference_to_ledge(
        IVP_SurfaceManager_VirtualMesh *this,
        const IVP_Compact_Ledge *ledge)
{
  CDataManagerBase::UnlockResource(this: &g_MeshManager, handle: this->m_pMesh->m_hMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10027AA0
// Name: public: virtual void IVP_SurfaceManager_VirtualMesh::get_all_terminal_ledges(class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_VirtualMesh::get_all_terminal_ledges(
        IVP_SurfaceManager_VirtualMesh *this,
        IVP_U_BigVector<IVP_Compact_Ledge> *resulting_ledges)
{
  this->m_pMesh->GetAllLedges(this: this->m_pMesh, a2: resulting_ledges);
}

//------------------------------------------------------------------------------
// Address: 0x10027AB0
// Name: public: virtual void CDataManager<class CMeshInstance,struct virtualmeshlist_t,class CMeshInstance __near *,class CThreadFastMutex>::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::Lock(
        CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex> *this)
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
// Address: 0x10027AF0
// Name: public: virtual bool CDataManager<class CMeshInstance,struct virtualmeshlist_t,class CMeshInstance __near *,class CThreadFastMutex>::TryLock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::TryLock(
        CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex> *this)
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
// Address: 0x10027B20
// Name: public: virtual void CDataManager<class CMeshInstance,struct virtualmeshlist_t,class CMeshInstance __near *,class CThreadFastMutex>::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::Unlock(
        CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex> *this)
{
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)&this->m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10027B80
// Name: private: void CMeshInstance::Init(struct virtualmeshlist_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshInstance::Init(CMeshInstance *this, const virtualmeshlist_t *list)
{
  const unsigned __int8 *v4; // edi
  int v5; // edx
  int v6; // edi
  float *v7; // ecx
  Vector *pVerts; // eax
  float y; // xmm0_4
  unsigned __int16 *v10; // edi
  virtualmeshhull_t *pHull; // esi
  unsigned __int8 *v12; // [esp-Ch] [ebp-28h]
  int pointSize; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  IVP_Compact_Poly_Point *pPoints; // [esp+14h] [ebp-8h]
  int ledgeSize; // [esp+18h] [ebp-4h]
  char *lista; // [esp+24h] [ebp+8h]

  ledgeSize = 48 * list->triangleCount;
  pointSize = 16 * list->vertexCount;
  v4 = &CMeshInstance::ComputeRootLedgeSize(pData: list->pHull)[pointSize + ledgeSize];
  this->m_hullCount = 0;
  this->m_memSize = (int)v4;
  lista = (char *)ivp_malloc_aligned(size: (int)v4, alignment: 16);
  this->m_pMemory = lista;
  pPoints = (IVP_Compact_Poly_Point *)&lista[ledgeSize];
  memset(dst: (unsigned __int8 *)lista, value: 0, count: (unsigned int)v4);
  v5 = 0;
  if ( list->vertexCount > 0 )
  {
    v6 = 0;
    v7 = &pPoints->k[2];
    do
    {
      pVerts = list->pVerts;
      y = list->pVerts[v6].y;
      *(v7 - 2) = list->pVerts[v6].x * g_PhysicsUnits.unitScaleMeters;
      *(v7 - 1) = -(float)(pVerts[v6].z * g_PhysicsUnits.unitScaleMeters);
      *v7 = g_PhysicsUnits.unitScaleMeters * y;
      ++v5;
      v7 += 4;
      ++v6;
    }
    while ( v5 < list->vertexCount );
  }
  i = 0;
  if ( list->triangleCount > 0 )
  {
    v10 = &list->indices[1];
    do
    {
      CVPhysicsVirtualMeshWriter::InitTwoSidedTriangleLege(
        pOut: (triangleledge_t *)lista,
        pPoints,
        v0: *(v10 - 1),
        v1: *v10,
        v2: v10[1],
        materialIndex: 0);
      lista += 48;
      v10 += 3;
      ++i;
    }
    while ( i < list->triangleCount );
  }
  pHull = (virtualmeshhull_t *)list->pHull;
  if ( pHull != nullptr )
  {
    this->m_hullCount = pHull->hullCount;
    v12 = (unsigned __int8 *)&this->m_pMemory[(unsigned __int16)(pointSize + ledgeSize)];
    this->m_hullOffset = pointSize + ledgeSize;
    CVPhysicsVirtualMeshWriter::UnpackLedgeListFromHull(pOut: v12, pHull, pPoints);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027CD0
// Name: public: virtual class IVP_SurfaceManager __near * CPhysCollideVirtualMesh::CreateSurfaceManager(short __near &)const
// Source: json
//------------------------------------------------------------------------------
IVP_SurfaceManager *__thiscall CPhysCollideVirtualMesh::CreateSurfaceManager(
        CPhysCollideVirtualMesh *this,
        __int16 *collideType)
{
  IVP_SurfaceManager *result; // eax

  *collideType = 3;
  result = (IVP_SurfaceManager *)p_malloc(size: 8u);
  if ( result == nullptr )
    return nullptr;
  result[1].__vftable = (IVP_SurfaceManager_vtbl *)this;
  result->__vftable = (IVP_SurfaceManager_vtbl *)&IVP_SurfaceManager_VirtualMesh::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027D10
// Name: public: virtual class Vector CPhysCollideVirtualMesh::GetOrthographicAreas(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideVirtualMesh::GetOrthographicAreas(
        IVP_SurfaceManager_VirtualMesh *this,
        IVP_U_Float_Point *rotation_inertia_out)
{
  rotation_inertia_out->k[0] = 1.0;
  rotation_inertia_out->k[1] = 1.0;
  rotation_inertia_out->k[2] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10027D80
// Name: public: virtual class Vector CPhysCollideVirtualMesh::GetMassCenter(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysCollideVirtualMesh::GetMassCenter(CPhysCollideVirtualMesh *this, Vector *result)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF

  this->m_params.pMeshEventHandler->GetWorldspaceBounds(
    this: this->m_params.pMeshEventHandler,
    a2: this->m_params.userData,
    a3: &mins,
    a4: &maxs);
  v3 = (float)(mins.y + maxs.y) * 0.5;
  v4 = (float)(maxs.z + mins.z) * 0.5;
  result->x = (float)(maxs.x + mins.x) * 0.5;
  result->y = v3;
  result->z = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027DF0
// Name: public: virtual float CPhysCollideVirtualMesh::GetSphereRadius(void)const
// Source: json
//------------------------------------------------------------------------------
double __usercall CPhysCollideVirtualMesh::GetSphereRadius@<st0>(
        CPhysCollideVirtualMesh *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>)
{
  float v4[3]; // [esp-Ch] [ebp-28h] BYREF
  Vector mins; // [esp+0h] [ebp-1Ch] BYREF
  float v6; // [esp+Ch] [ebp-10h]
  Vector maxs; // [esp+10h] [ebp-Ch]
  float retaddr; // [esp+1Ch] [ebp+0h]

  maxs.x = a2;
  maxs.y = retaddr;
  ((void (__thiscall *)(IVirtualMeshEvent *, void *, float *, float *, int))this->m_params.pMeshEventHandler->GetWorldspaceBounds)(
    a1: this->m_params.pMeshEventHandler,
    a2: this->m_params.userData,
    a3: v4,
    a4: &mins.y,
    a5: a3);
  return fsqrt(
           (float)((float)((float)(mins.z - (float)((float)(mins.z + v4[1]) * 0.5))
                         * (float)(mins.z - (float)((float)(mins.z + v4[1]) * 0.5)))
                 + (float)((float)(v6 - (float)((float)(v6 + v4[2]) * 0.5))
                         * (float)(v6 - (float)((float)(v6 + v4[2]) * 0.5))))
         + (float)((float)(mins.y - (float)((float)(mins.y + v4[0]) * 0.5))
                 * (float)(mins.y - (float)((float)(mins.y + v4[0]) * 0.5))));
}

//------------------------------------------------------------------------------
// Address: 0x10027ED0
// Name: public: virtual void IVP_SurfaceManager_VirtualMesh::get_radius_and_radius_dev_to_given_center(class IVP_U_Float_Point const __near *,float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_VirtualMesh::get_radius_and_radius_dev_to_given_center(
        IVP_SurfaceManager_VirtualMesh *this,
        const IVP_U_Float_Point *center,
        float *radius,
        float *radius_deviation)
{
  float v4; // xmm0_4
  float v5; // [esp+0h] [ebp-4h]

  v5 = ((double (__thiscall *)(CPhysCollideVirtualMesh *, IVP_SurfaceManager_VirtualMesh *))this->m_pMesh->GetSphereRadius)(
         a1: this->m_pMesh,
         a2: this);
  v4 = g_PhysicsUnits.unitScaleMeters * v5;
  *radius = g_PhysicsUnits.unitScaleMeters * v5;
  *radius_deviation = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10027F10
// Name: public: virtual void IVP_SurfaceManager_VirtualMesh::get_mass_center(class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_VirtualMesh::get_mass_center(
        IVP_SurfaceManager_VirtualMesh *this,
        IVP_U_Float_Point *mass_center_out)
{
  Vector center; // [esp+0h] [ebp-Ch] BYREF

  this->m_pMesh->GetMassCenter(this: this->m_pMesh, result: &center);
  mass_center_out->k[0] = g_PhysicsUnits.unitScaleMeters * center.x;
  LODWORD(mass_center_out->k[1]) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMeters * center.z) ^ _mask__NegFloat_;
  mass_center_out->k[2] = g_PhysicsUnits.unitScaleMeters * center.y;
}

//------------------------------------------------------------------------------
// Address: 0x10027F70
// Name: public: int IVP_U_BigVector<class IVP_Compact_Ledge>::add(class IVP_Compact_Ledge __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_U_BigVector<IVP_Compact_Ledge>::add(
        IVP_U_BigVector<IVP_Compact_Ledge> *this,
        IVP_Compact_Ledge *elem)
{
  int result; // eax

  if ( this->n_elems >= this->memsize )
    IVP_U_BigVector_Base::increment_mem(this);
  this->elems[this->n_elems] = (void *)elem;
  result = this->n_elems;
  this->n_elems = result + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027FA0
// Name: private: virtual unsigned int CDataManager<class CMeshInstance,struct virtualmeshlist_t,class CMeshInstance __near *,class CThreadFastMutex>::GetRealSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::GetRealSize(
        CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex> *this,
        void *pStore)
{
  return *(_DWORD *)pStore;
}

//------------------------------------------------------------------------------
// Address: 0x10027FB0
// Name: public: static class IVP_Compact_Surface __near * CPhysCollideVirtualMesh::CreateBoundingSurfaceFromRange(struct virtualmeshlist_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Surface *__usercall CPhysCollideVirtualMesh::CreateBoundingSurfaceFromRange@<eax>(
        IVP_SURBUILD_LEDGE_SOUP_MERGE_POINT_TYPES a1@<ebp>,
        const virtualmeshlist_t *list,
        int firstIndex,
        int indexCount)
{
  int v4; // ecx
  int v5; // eax
  unsigned __int16 *v6; // esi
  int v7; // edi
  Vector *pVerts; // eax
  int v9; // ecx
  float y; // xmm1_4
  float z; // xmm3_4
  int v12; // ecx
  float *p_x; // ecx
  float v14; // xmm1_4
  float v15; // xmm3_4
  int v16; // ecx
  float *v17; // eax
  float v18; // xmm1_4
  IVP_Compact_Ledge *v19; // eax
  IVP_Compact_Surface *v20; // esi
  _BYTE v22[12]; // [esp-Ch] [ebp-FCh] BYREF
  IVP_SurfaceBuilder_Ledge_Soup builder; // [esp+0h] [ebp-F0h] BYREF
  IVP_U_Point triVerts[3]; // [esp+A0h] [ebp-50h] BYREF
  IVP_Template_Surbuild_LedgeSoup params; // [esp+D0h] [ebp-20h] BYREF
  IVP_U_Vector<IVP_U_Point> triList; // [esp+E8h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+F0h] [ebp+0h]

  params.merge_points = a1;
  *(_DWORD *)&triList.memsize = retaddr;
  params.link_to_input_compact_ledges = IVP_FALSE;
  params.bUseFastApproximateInertiaTensor = IVP_FALSE;
  IVP_SurfaceBuilder_Ledge_Soup::IVP_SurfaceBuilder_Ledge_Soup(this: (IVP_SurfaceBuilder_Ledge_Soup *)v22);
  if ( HIWORD(params.link_to_input_compact_ledges) >= LOWORD(params.link_to_input_compact_ledges) )
    IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)&params.link_to_input_compact_ledges);
  *(_DWORD *)(params.bUseFastApproximateInertiaTensor + 4 * HIWORD(params.link_to_input_compact_ledges)) = &builder.all_spheres + 1;
  if ( ++HIWORD(params.link_to_input_compact_ledges) >= LOWORD(params.link_to_input_compact_ledges) )
    IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)&params.link_to_input_compact_ledges);
  *(_DWORD *)(params.bUseFastApproximateInertiaTensor + 4 * HIWORD(params.link_to_input_compact_ledges)) = &triVerts[0].k[1];
  if ( ++HIWORD(params.link_to_input_compact_ledges) >= LOWORD(params.link_to_input_compact_ledges) )
    IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)&params.link_to_input_compact_ledges);
  *(_DWORD *)(params.bUseFastApproximateInertiaTensor + 4 * HIWORD(params.link_to_input_compact_ledges)) = &triVerts[1].k[1];
  ++HIWORD(params.link_to_input_compact_ledges);
  v4 = (firstIndex + indexCount) / 3;
  v5 = firstIndex / 3;
  if ( firstIndex / 3 < v4 )
  {
    v6 = &list->indices[3 * v5 + 1];
    v7 = v4 - v5;
    do
    {
      pVerts = list->pVerts;
      v9 = *(v6 - 1);
      y = list->pVerts[*(v6 - 1)].y;
      *((float *)&builder.all_spheres + 2) = list->pVerts[*(v6 - 1)].x * g_PhysicsUnits.unitScaleMeters;
      z = pVerts[v9].z;
      v12 = *v6;
      *((float *)&builder.all_spheres + 3) = -(float)(z * g_PhysicsUnits.unitScaleMeters);
      p_x = &pVerts[v12].x;
      *((float *)&builder.all_spheres + 4) = g_PhysicsUnits.unitScaleMeters * y;
      v14 = p_x[1];
      triVerts[0].k[1] = *p_x * g_PhysicsUnits.unitScaleMeters;
      v15 = p_x[2];
      v16 = v6[1];
      triVerts[0].k[2] = -(float)(v15 * g_PhysicsUnits.unitScaleMeters);
      v17 = &pVerts[v16].x;
      triVerts[0].hesse_val = g_PhysicsUnits.unitScaleMeters * v14;
      v18 = v17[1];
      triVerts[1].k[1] = *v17 * g_PhysicsUnits.unitScaleMeters;
      triVerts[1].k[2] = -(float)(v17[2] * g_PhysicsUnits.unitScaleMeters);
      triVerts[1].hesse_val = v18 * g_PhysicsUnits.unitScaleMeters;
      v19 = IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge(points: (IVP_U_Vector<IVP_U_Point> *)&params.link_to_input_compact_ledges);
      IVP_SurfaceBuilder_Ledge_Soup::insert_ledge(this: (IVP_SurfaceBuilder_Ledge_Soup *)v22, c_ledge: v19);
      v6 += 3;
      --v7;
    }
    while ( v7 != 0 );
  }
  triVerts[2].k[1] = 0.0;
  params.force_convex_hull = nullptr;
  params.build_root_convex_hull = IVP_FALSE;
  LODWORD(triVerts[2].hesse_val) = 1;
  params.free_input_compact_ledges = IVP_TRUE;
  LODWORD(triVerts[2].k[2]) = 1;
  v20 = IVP_SurfaceBuilder_Ledge_Soup::compile(
          this: (IVP_SurfaceBuilder_Ledge_Soup *)v22,
          templ: (IVP_Template_Surbuild_LedgeSoup *)&triVerts[2].k[1]);
  IVP_SurfaceBuilder_Ledge_Soup::~IVP_SurfaceBuilder_Ledge_Soup(this: (IVP_SurfaceBuilder_Ledge_Soup *)v22);
  if ( (IVP_SURBUILD_LEDGE_SOUP_MERGE_POINT_TYPES *)params.bUseFastApproximateInertiaTensor != &params.merge_points
    && params.bUseFastApproximateInertiaTensor != IVP_FALSE )
  {
    free(data: (void *)params.bUseFastApproximateInertiaTensor);
  }
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x100281D0
// Name: public: struct memhandle_t__ __near * CDataManager<class CMeshInstance,struct virtualmeshlist_t,class CMeshInstance __near *,class CThreadFastMutex>::CreateResource(struct virtualmeshlist_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::CreateResource(
        CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex> *this,
        const virtualmeshlist_t *createParams,
        bool bCreateLocked)
{
  const unsigned __int8 *v4; // eax
  CMeshInstance *v5; // eax
  CMeshInstance *v6; // edi
  unsigned __int16 Handle; // ax
  memhandle_t__ *v8; // edi

  v4 = CMeshInstance::ComputeRootLedgeSize(pData: createParams->pHull);
  CDataManagerBase::EnsureCapacity(
    this,
    size: (unsigned int)&v4[48 * createParams->triangleCount + 16 * createParams->vertexCount]);
  v5 = (CMeshInstance *)p_malloc(size: 0xCu);
  v6 = nullptr;
  if ( v5 != nullptr )
  {
    v5->m_pMemory = nullptr;
    v6 = v5;
  }
  CMeshInstance::Init(this: v6, list: createParams);
  this->Lock(this);
  Handle = CDataManagerBase::CreateHandle(this, bCreateLocked);
  v8 = CDataManagerBase::StoreResourceInHandle(this, memoryIndex: Handle, pStore: v6, realSize: v6->m_memSize);
  this->Unlock(this);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10028260
// Name: private: virtual void CDataManager<class CMeshInstance,struct virtualmeshlist_t,class CMeshInstance __near *,class CThreadFastMutex>::DestroyResourceStorage(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::DestroyResourceStorage(
        CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex> *this,
        void **pStore)
{
  if ( pStore != nullptr )
  {
    if ( pStore[1] != nullptr )
    {
      ivp_free_aligned(data: pStore[1]);
      pStore[1] = nullptr;
    }
    free(data: pStore);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028290
// Name: FlushFrameLocks
// Source: json
//------------------------------------------------------------------------------
void FlushFrameLocks()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi
  int v2; // edi
  char *v3; // eax

  v0 = GenericThreadLocals::CThreadLocalBase::Get(this: &g_pMeshFrameLocks);
  v1 = v0;
  if ( v0 != nullptr )
  {
    v2 = 0;
    if ( (int)v0[3] > 0 )
    {
      do
        CDataManagerBase::UnlockResource(
          this: &g_MeshManager,
          handle: *(memhandle_t__ **)(*(_DWORD *)(*v1 + 4 * v2++) + 20));
      while ( v2 < v1[3] );
    }
    v1[3] = 0;
    v3 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_pMeshFrameLocks);
    CTSListBase::Push(this: &g_MeshFrameLocksPool, pNode: (TSLNodeBase_t *)(v3 - 4));
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_pMeshFrameLocks, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028300
// Name: void VirtualMeshPSI(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl VirtualMeshPSI()
{
  FlushFrameLocks();
}

//------------------------------------------------------------------------------
// Address: 0x10028310
// Name: private: class CMeshInstance __near * CPhysCollideVirtualMesh::BuildLedges(void)
// Source: json
//------------------------------------------------------------------------------
CMeshInstance *__thiscall CPhysCollideVirtualMesh::BuildLedges(CPhysCollideVirtualMesh *this)
{
  memhandle_t__ *v2; // eax
  virtualmeshlist_t createParams; // [esp+4h] [ebp-1818h] BYREF

  this->m_params.pMeshEventHandler->GetVirtualMesh(
    this: this->m_params.pMeshEventHandler,
    a2: this->m_params.userData,
    a3: &createParams);
  if ( createParams.pHull == nullptr )
    createParams.pHull = (unsigned __int8 *)this->m_pHull;
  if ( createParams.triangleCount == 0 )
    return nullptr;
  v2 = CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::CreateResource(
         this: &g_MeshManager,
         &createParams,
         bCreateLocked: false);
  this->m_ledgeCount = createParams.triangleCount;
  this->m_hMemory = v2;
  return (CMeshInstance *)CDataManagerBase::LockResource(this: &g_MeshManager, handle: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10028390
// Name: public: static struct virtualmeshhull_t __near * CPhysCollideVirtualMesh::CreateMeshBoundingHull(struct virtualmeshlist_t const __near &)
// Source: json
//------------------------------------------------------------------------------
virtualmeshhull_t *__cdecl CPhysCollideVirtualMesh::CreateMeshBoundingHull(const IVP_Compact_Ledge *list)
{
  const virtualmeshlist_t *v1; // esi
  IVP_Compact_Surface *BoundingSurfaceFromRange; // eax
  IVP_Compact_Surface *v3; // edi
  int offset_ledgetree_root; // eax
  int v5; // ecx
  char *v6; // eax
  const virtualmeshlist_t *v7; // eax
  virtualmeshhull_t *v8; // esi
  IVP_Compact_Surface *v10; // edi
  IVP_Compact_Surface *v11; // ebx
  int v12; // eax
  int v13; // ecx
  char *v14; // eax
  const IVP_Compact_Ledge *v15; // eax
  int v16; // eax
  int v17; // ecx
  char *v18; // eax
  const IVP_Compact_Ledge *v19; // eax
  virtualmeshhull_t *PackedHullFromLedges; // esi
  const IVP_Compact_Ledge *pLedges[2]; // [esp+8h] [ebp-Ch] BYREF
  IVP_Compact_Surface *pSurface; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  v1 = (const virtualmeshlist_t *)list;
  if ( *((_DWORD *)list + 2) == 0 )
    return nullptr;
  BoundingSurfaceFromRange = CPhysCollideVirtualMesh::CreateBoundingSurfaceFromRange(
                               a1: (IVP_SURBUILD_LEDGE_SOUP_MERGE_POINT_TYPES)&savedregs,
                               (const virtualmeshlist_t *)list,
                               firstIndex: 0,
                               indexCount: list->ledgetree_node_offset);
  v3 = BoundingSurfaceFromRange;
  pSurface = BoundingSurfaceFromRange;
  if ( BoundingSurfaceFromRange == nullptr )
    return nullptr;
  offset_ledgetree_root = BoundingSurfaceFromRange->offset_ledgetree_root;
  v5 = *(_DWORD *)((char *)&v3->mass_center.k[1] + offset_ledgetree_root);
  v6 = (char *)v3 + offset_ledgetree_root;
  if ( v5 != 0 )
    v7 = (const virtualmeshlist_t *)&v6[v5];
  else
    v7 = nullptr;
  list = (const IVP_Compact_Ledge *)v7;
  if ( CVPhysicsVirtualMeshWriter::LedgeCanBePacked(pLedge: (const IVP_Compact_Ledge *)v7, list: v1) )
  {
    v8 = CVPhysicsVirtualMeshWriter::CreatePackedHullFromLedges(list: v1, pLedges: &list, ledgeCount: 1);
    ivp_free_aligned(data: v3);
    return v8;
  }
  else
  {
    v10 = CPhysCollideVirtualMesh::CreateBoundingSurfaceFromRange(
            a1: (IVP_SURBUILD_LEDGE_SOUP_MERGE_POINT_TYPES)&savedregs,
            list: v1,
            firstIndex: 0,
            indexCount: v1->indexCount / 2);
    v11 = CPhysCollideVirtualMesh::CreateBoundingSurfaceFromRange(
            a1: (IVP_SURBUILD_LEDGE_SOUP_MERGE_POINT_TYPES)&savedregs,
            list: v1,
            firstIndex: v1->indexCount / 2,
            indexCount: v1->indexCount / 2);
    v12 = v10->offset_ledgetree_root;
    v13 = *(_DWORD *)((char *)&v10->mass_center.k[1] + v12);
    v14 = (char *)v10 + v12;
    if ( v13 != 0 )
      v15 = (const IVP_Compact_Ledge *)&v14[v13];
    else
      v15 = nullptr;
    pLedges[0] = v15;
    v16 = v11->offset_ledgetree_root;
    v17 = *(_DWORD *)((char *)&v11->mass_center.k[1] + v16);
    v18 = (char *)v11 + v16;
    if ( v17 != 0 )
      v19 = (const IVP_Compact_Ledge *)&v18[v17];
    else
      v19 = nullptr;
    pLedges[1] = v19;
    PackedHullFromLedges = CVPhysicsVirtualMeshWriter::CreatePackedHullFromLedges(list: v1, pLedges, ledgeCount: 2);
    ivp_free_aligned(data: v10);
    ivp_free_aligned(data: v11);
    ivp_free_aligned(data: pSurface);
    return PackedHullFromLedges;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100284A0
// Name: public: class CMeshInstance __near * CPhysCollideVirtualMesh::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
CMeshInstance *__thiscall CPhysCollideVirtualMesh::AddRef(CPhysCollideVirtualMesh *this)
{
  CMeshInstance *result; // eax
  DWORD CurrentThreadId; // ecx

  result = (CMeshInstance *)CDataManagerBase::LockResource(this: &g_MeshManager, handle: this->m_hMemory);
  if ( result == nullptr )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_BuildVirtualMeshMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_BuildVirtualMeshMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_BuildVirtualMeshMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_BuildVirtualMeshMutex.m_depth;
    }
    result = (CMeshInstance *)CDataManagerBase::LockResource(this: &g_MeshManager, handle: this->m_hMemory);
    if ( result == nullptr )
      result = CPhysCollideVirtualMesh::BuildLedges(this);
    if ( --s_BuildVirtualMeshMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_BuildVirtualMeshMutex, 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028530
// Name: public: virtual void IVP_SurfaceManager_VirtualMesh::add_reference_to_ledge(class IVP_Compact_Ledge const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_VirtualMesh::add_reference_to_ledge(
        IVP_SurfaceManager_VirtualMesh *this,
        const IVP_Compact_Ledge *ledge)
{
  CPhysCollideVirtualMesh::AddRef(this: this->m_pMesh);
}

//------------------------------------------------------------------------------
// Address: 0x10028540
// Name: public: virtual void CPhysCollideVirtualMesh::GetAllLedges(class IVP_U_BigVector<class IVP_Compact_Ledge> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideVirtualMesh::GetAllLedges(
        CPhysCollideVirtualMesh *this,
        IVP_U_BigVector<IVP_Compact_Ledge> *ledges)
{
  CPhysCollideVirtualMesh *v2; // esi
  char *m_pMemory; // eax
  int v4; // ebx
  char *v5; // edi

  v2 = this;
  m_pMemory = CPhysCollideVirtualMesh::AddRef(this)->m_pMemory;
  v4 = 0;
  if ( v2->m_ledgeCount > 0 )
  {
    v5 = m_pMemory;
    do
    {
      if ( ledges->n_elems >= ledges->memsize )
        IVP_U_BigVector_Base::increment_mem(this: ledges);
      ledges->elems[ledges->n_elems++] = v5;
      ++v4;
      v5 += 48;
    }
    while ( v4 < this->m_ledgeCount );
    v2 = this;
  }
  CDataManagerBase::UnlockResource(this: &g_MeshManager, handle: v2->m_hMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100285B0
// Name: public: CPhysCollideVirtualMesh::CPhysCollideVirtualMesh(struct virtualmeshparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideVirtualMesh *__thiscall CPhysCollideVirtualMesh::CPhysCollideVirtualMesh(
        CPhysCollideVirtualMesh *this,
        const virtualmeshparams_t *params)
{
  virtualmeshlist_t list; // [esp+4h] [ebp-1818h] BYREF

  this->__vftable = (CPhysCollideVirtualMesh_vtbl *)&CPhysCollideVirtualMesh::`vftable';
  this->m_params = *params;
  this->m_hMemory = (memhandle_t__ *)-1;
  this->m_ledgeCount = 0;
  this->m_pHull = nullptr;
  if ( params->buildOuterHull )
  {
    this->m_params.pMeshEventHandler->GetVirtualMesh(
      this: this->m_params.pMeshEventHandler,
      a2: this->m_params.userData,
      a3: &list);
    this->m_pHull = CPhysCollideVirtualMesh::CreateMeshBoundingHull((const IVP_Compact_Ledge *)&list);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028620
// Name: class CPhysCollide __near * CreateVirtualMesh(struct virtualmeshparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideVirtualMesh *__cdecl CreateVirtualMesh(const virtualmeshparams_t *params)
{
  CPhysCollideVirtualMesh *v1; // eax

  v1 = (CPhysCollideVirtualMesh *)p_malloc(size: 0x1Cu);
  if ( v1 != nullptr )
    return CPhysCollideVirtualMesh::CPhysCollideVirtualMesh(this: v1, params);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10028650
// Name: public: void CPhysCollideVirtualMesh::FrameRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideVirtualMesh::FrameRelease(CPhysCollideVirtualMesh *this)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v1; // esi
  TSLNodeBase_t *v2; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v5; // ecx
  int v6; // eax
  CPhysCollideVirtualMesh **v7; // eax

  v1 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_pMeshFrameLocks);
  if ( v1 == nullptr )
  {
    v2 = CTSListBase::Pop(this: &g_MeshFrameLocksPool);
    if ( v2 == nullptr )
    {
      v2 = (TSLNodeBase_t *)p_malloc(size: 0x18u);
      if ( v2 != nullptr )
      {
        *((_DWORD *)&v2->Next + 1) = 0;
        v2[1].Next = nullptr;
        *((_DWORD *)&v2[1].Next + 1) = 0;
        v2[2].Next = nullptr;
        *((_DWORD *)&v2[2].Next + 1) = 0;
      }
      else
      {
        v2 = nullptr;
      }
    }
    v1 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(&v2->Next + 1);
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_pMeshFrameLocks, a2: &v2->Next + 1);
  }
  m_pMemory = v1[1].m_pMemory;
  m_nAllocationCount = v1->m_nAllocationCount;
  if ( (int)m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(this: v1, num: (int)m_pMemory - m_nAllocationCount + 1);
  ++v1[1].m_pMemory;
  v5 = v1->m_pMemory;
  v6 = (char *)v1[1].m_pMemory - (char *)m_pMemory - 1;
  v1[1].m_nAllocationCount = (int)v1->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[(_DWORD)m_pMemory + 1], src: &v5[(_DWORD)m_pMemory], count: 4 * v6);
  v7 = (CPhysCollideVirtualMesh **)&v1->m_pMemory[(_DWORD)m_pMemory];
  if ( v7 != nullptr )
    *v7 = this;
}

//------------------------------------------------------------------------------
// Address: 0x100287B0
// Name: public: void CPhysCollideVirtualMesh::GetAllLedgesWithinRadius(class IVP_U_Point const __near *,float,class IVP_U_BigVector<class IVP_Compact_Ledge> __near *,class IVP_Compact_Ledge const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysCollideVirtualMesh::GetAllLedgesWithinRadius(
        CPhysCollideVirtualMesh *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const IVP_U_Point *observer_os,
        float radius,
        IVP_U_BigVector<IVP_Compact_Ledge> *resulting_ledges,
        const IVP_Compact_Ledge *pRootLedge)
{
  IVirtualMeshEvent *pMeshEventHandler; // ecx
  float v9; // xmm1_4
  int v10; // ebx
  void *userData; // edx
  CMeshInstance *v12; // edi
  int m_ledgeCount; // edx
  unsigned __int8 m_hullCount; // al
  int m_hullOffset; // edx
  int v16; // esi
  int v17; // eax
  char *v18; // edi
  int v19; // eax
  char *v20; // esi
  _DWORD v23[1537]; // [esp+10h] [ebp-1824h] BYREF
  _DWORD v24[2]; // [esp+1814h] [ebp-20h]
  float v25[3]; // [esp+181Ch] [ebp-18h] BYREF
  char *m_pMemory; // [esp+1828h] [ebp-Ch]
  int v27; // [esp+182Ch] [ebp-8h]
  int v28; // [esp+1830h] [ebp-4h]
  float v29; // [esp+1840h] [ebp+Ch]

  LODWORD(v25[2]) = COERCE_UNSIGNED_INT(observer_os->k[1] * g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_;
  pMeshEventHandler = this->m_params.pMeshEventHandler;
  v25[1] = observer_os->k[2] * g_PhysicsUnits.unitScaleMetersInv;
  v9 = observer_os->k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v10 = 0;
  userData = this->m_params.userData;
  v23[0] = 0;
  v25[0] = v9;
  ((void (__thiscall *)(IVirtualMeshEvent *, void *, float *, _DWORD, _DWORD *, int, int))pMeshEventHandler->GetTrianglesInSphere)(
    a1: pMeshEventHandler,
    a2: userData,
    a3: v25,
    a4: g_PhysicsUnits.unitScaleMetersInv * radius,
    a5: v23,
    a6: a3,
    a7: a2);
  if ( v23[0] != 0 )
  {
    v12 = CPhysCollideVirtualMesh::AddRef(this);
    m_pMemory = v12->m_pMemory;
    CPhysCollideVirtualMesh::FrameRelease(this);
    m_ledgeCount = this->m_ledgeCount;
    m_hullCount = v12->m_hullCount;
    v27 = 0;
    v28 = m_ledgeCount;
    if ( m_hullCount > 1u )
    {
      m_hullOffset = v12->m_hullOffset;
      v16 = 2;
      if ( m_hullCount <= 2u )
        v16 = m_hullCount;
      v17 = 0;
      v18 = v12->m_pMemory;
      do
      {
        v24[v17++] = &v18[m_hullOffset];
        m_hullOffset += 16 * *(__int16 *)&v18[m_hullOffset + 12] + 16;
      }
      while ( v17 < v16 );
      if ( pRootLedge == (const IVP_Compact_Ledge *)v24[0] )
        v28 /= 2;
      else
        v27 = v28 / 2;
    }
    v29 = radius * radius;
    if ( v23[0] > 0 )
    {
      do
      {
        v19 = *((unsigned __int16 *)&v23[1] + v10);
        if ( v19 >= v27 && v19 < v28 )
        {
          v20 = &m_pMemory[48 * v19];
          if ( IVP_Compact_Ledge_Solver::calc_qlen_PF_F_space(
                 ledge: (const IVP_Compact_Ledge *)v20,
                 tri: (const IVP_Compact_Triangle *)v20 + 1,
                 object_pos: observer_os) <= (double)v29 )
          {
            if ( resulting_ledges->n_elems >= resulting_ledges->memsize )
              IVP_U_BigVector_Base::increment_mem(this: resulting_ledges);
            resulting_ledges->elems[resulting_ledges->n_elems++] = v20;
          }
        }
        ++v10;
      }
      while ( v10 < v23[0] );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028930
// Name: public: int CPhysCollideVirtualMesh::GetRootLedges(class IVP_Compact_Ledge __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollideVirtualMesh::GetRootLedges(
        CPhysCollideVirtualMesh *this,
        IVP_Compact_Ledge **pLedges,
        int outCount)
{
  CPhysCollideVirtualMesh *v3; // esi
  CMeshInstance *v4; // eax
  int m_hullCount; // edi
  int m_hullOffset; // edx
  int v7; // ecx
  IVP_Compact_Ledge *v8; // esi

  v3 = this;
  v4 = CPhysCollideVirtualMesh::AddRef(this);
  m_hullCount = outCount;
  m_hullOffset = v4->m_hullOffset;
  if ( outCount >= v4->m_hullCount )
    m_hullCount = v4->m_hullCount;
  v7 = 0;
  if ( m_hullCount > 0 )
  {
    do
    {
      v8 = (IVP_Compact_Ledge *)&v4->m_pMemory[m_hullOffset];
      pLedges[v7++] = v8;
      m_hullOffset += 16 * v8->n_triangles + 16;
    }
    while ( v7 < m_hullCount );
    v3 = this;
  }
  CPhysCollideVirtualMesh::FrameRelease(this: v3);
  return m_hullCount;
}

//------------------------------------------------------------------------------
// Address: 0x10028990
// Name: public: virtual void IVP_SurfaceManager_VirtualMesh::insert_all_ledges_hitting_ray(class IVP_Ray_Solver __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_SurfaceManager_VirtualMesh::insert_all_ledges_hitting_ray(
        IVP_SurfaceManager_VirtualMesh *this@<ecx>,
        float a2@<ebp>,
        IVP_Ray_Solver *ray_solver,
        IVP_Real_Object *object)
{
  int i; // esi
  IVP_U_BigVector<IVP_Compact_Ledge> v6; // [esp+1Ch] [ebp-47Ch] BYREF
  IVP_Vector_of_Ledges_256 ledges; // [esp+28h] [ebp-470h] BYREF
  IVP_Ray_Solver_Os ray_solver_os; // [esp+438h] [ebp-60h] BYREF
  IVP_U_Point center; // [esp+488h] [ebp-10h] BYREF
  float retaddr; // [esp+498h] [ebp+0h]

  center.k[1] = a2;
  center.k[2] = retaddr;
  v6.elems = (void **)&ledges;
  v6.memsize = 256;
  v6.n_elems = 0;
  IVP_Ray_Solver_Os::IVP_Ray_Solver_Os(this: (IVP_Ray_Solver_Os *)&ledges.elem_buffer[254], so: ray_solver, obj: object);
  ray_solver_os.object = (IVP_Real_Object *)LODWORD(ray_solver_os.ray_start_point.k[1]);
  ray_solver_os.ray_length = ray_solver_os.ray_start_point.k[2];
  *((_DWORD *)&ray_solver_os.ray_length + 1) = LODWORD(ray_solver_os.ray_start_point.hesse_val);
  CPhysCollideVirtualMesh::GetAllLedgesWithinRadius(
    this: this->m_pMesh,
    a2: (int)&center.hesse_val,
    a3: (int)this,
    observer_os: (const IVP_U_Point *)&ray_solver_os.object,
    radius: ray_solver_os.ray_direction.hesse_val * 0.5,
    resulting_ledges: &v6,
    pRootLedge: nullptr);
  for ( i = v6.n_elems - 1; i >= 0; --i )
    IVP_Ray_Solver_Os::check_ray_against_compact_ledge_os(
      this: (IVP_Ray_Solver_Os *)&ledges.elem_buffer[254],
      ledge_to_compare: (const IVP_Compact_Ledge *)v6.elems[i]);
  if ( (IVP_Vector_of_Ledges_256 *)v6.elems != &ledges && v6.elems != nullptr )
    free(data: v6.elems);
}

//------------------------------------------------------------------------------
// Address: 0x10028A70
// Name: public: virtual class IVP_Compact_Ledge const __near * IVP_SurfaceManager_VirtualMesh::get_single_convex(void)const
// Source: json
//------------------------------------------------------------------------------
const IVP_Compact_Ledge *__thiscall IVP_SurfaceManager_VirtualMesh::get_single_convex(
        IVP_SurfaceManager_VirtualMesh *this)
{
  CPhysCollideVirtualMesh *m_pMesh; // edi
  CMeshInstance *v2; // eax
  int v3; // esi

  m_pMesh = this->m_pMesh;
  v2 = CPhysCollideVirtualMesh::AddRef(this: m_pMesh);
  if ( v2->m_hullCount == 1 )
  {
    v3 = (int)&v2->m_pMemory[v2->m_hullOffset];
    CPhysCollideVirtualMesh::FrameRelease(this: m_pMesh);
    return (const IVP_Compact_Ledge *)v3;
  }
  else
  {
    CPhysCollideVirtualMesh::FrameRelease(this: m_pMesh);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028AB0
// Name: public: virtual void IVP_SurfaceManager_VirtualMesh::get_all_ledges_within_radius(class IVP_U_Point const __near *,float,class IVP_Compact_Ledge const __near *,class IVP_Real_Object __near *,class IVP_Compact_Ledge const __near *,class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_SurfaceManager_VirtualMesh::get_all_ledges_within_radius(
        IVP_SurfaceManager_VirtualMesh *this@<ecx>,
        int a2@<ebx>,
        const IVP_U_Point *observer_os,
        float radius,
        const IVP_Compact_Ledge *root_ledge,
        IVP_Real_Object *other_object,
        const IVP_Compact_Ledge *other_reference_ledge,
        IVP_U_BigVector<IVP_Compact_Ledge> *resulting_ledges)
{
  int v8; // edi
  int RootLedges; // eax
  IVP_Compact_Ledge *v11; // ebx
  IVP_Compact_Ledge *pLedges[2]; // [esp+14h] [ebp-8h] BYREF
  int count; // [esp+2Ch] [ebp+10h]

  v8 = (int)root_ledge;
  if ( root_ledge != nullptr
    || (RootLedges = CPhysCollideVirtualMesh::GetRootLedges(this: this->m_pMesh, pLedges, outCount: 2),
        count = RootLedges,
        RootLedges == 0) )
  {
    CPhysCollideVirtualMesh::GetAllLedgesWithinRadius(
      this: this->m_pMesh,
      a2,
      a3: (int)this,
      observer_os,
      radius,
      resulting_ledges,
      pRootLedge: (const IVP_Compact_Ledge *)v8);
  }
  else if ( RootLedges > 0 )
  {
    do
    {
      v11 = pLedges[v8];
      if ( resulting_ledges->n_elems >= resulting_ledges->memsize )
      {
        IVP_U_BigVector_Base::increment_mem(this: resulting_ledges);
        RootLedges = count;
      }
      resulting_ledges->elems[resulting_ledges->n_elems++] = (void *)v11;
      ++v8;
    }
    while ( v8 < RootLedges );
  }
}
