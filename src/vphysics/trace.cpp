// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/trace.cpp
// Functions: 79
// ============================================================

#include "vphysics\trace.h"

//------------------------------------------------------------------------------
// Address: 0x10001F90
// Name: public: int CUtlVector<int,class CUtlMemoryFixedGrowable<int,64,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v7; // ebx
  int *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
  {
    v7 = num + m_Size - m_nAllocationCount;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<int,int>::ConvertToGrowableMemory(this: &this->m_Memory, nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: v7);
  }
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v10 = v9 - elem - num;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v10);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003520
// Name: public: void CUtlVector<class CPhysicsCollisionSet,class CUtlMemory<class CPhysicsCollisionSet,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPhysicsCollisionSet,CUtlMemory<CPhysicsCollisionSet,int>>::Purge(
        CUtlVector<CPhysicsCollisionSet,CUtlMemory<CPhysicsCollisionSet,int> > *this)
{
  int v2; // ecx
  int v3; // edx
  bool v4; // sf
  CPhysicsCollisionSet *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      this->m_Memory.m_pMemory[v3--].__vftable = (CPhysicsCollisionSet_vtbl *)&IPhysicsCollisionSet::`vftable';
      --v2;
    }
    while ( v2 >= 0 );
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003590
// Name: public: int CUtlVector<class CPhysicsCollisionSet,class CUtlMemory<class CPhysicsCollisionSet,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPhysicsCollisionSet,CUtlMemory<CPhysicsCollisionSet,int>>::InsertBefore(
        CUtlVector<CPhysicsCollisionSet,CUtlMemory<CPhysicsCollisionSet,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPhysicsCollisionSet *m_pMemory; // ecx
  int v6; // eax
  CPhysicsCollisionSet *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPhysicsCollisionSet,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 132 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->__vftable = (CPhysicsCollisionSet_vtbl *)&CPhysicsCollisionSet::`vftable';
    memset(dst: (unsigned __int8 *)v7->m_bits, value: 0, count: sizeof(v7->m_bits));
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10009F40
// Name: public: int CUtlVector<struct bboxcache_t,class CUtlMemory<struct bboxcache_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bboxcache_t,CUtlMemory<bboxcache_t,int>>::InsertBefore(
        CUtlVector<bboxcache_t,CUtlMemory<bboxcache_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bboxcache_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bboxcache_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10011D60
// Name: public: CUtlVector<class IPhysicsObject __near *,class CUtlMemory<class IPhysicsObject __near *,int>>::~CUtlVector<class IPhysicsObject __near *,class CUtlMemory<class IPhysicsObject __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011DD0
// Name: public: void CUtlVector<class CPhysicsFluidController __near *,class CUtlMemory<class CPhysicsFluidController __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPhysicsFluidController *,CUtlMemory<CPhysicsFluidController *,int>>::PurgeAndDeleteElements(
        CUtlVector<CPhysicsFluidController *,CUtlMemory<CPhysicsFluidController *,int> > *this)
{
  int i; // edi
  CPhysicsFluidController *v3; // ecx
  bool v4; // sf
  CPhysicsFluidController **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CPhysicsFluidController *, int))v3->dtr_IPhysicsFluidController)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011E40
// Name: public: bool CUtlVector<class IPhysicsPlayerController __near *,class CUtlMemory<class IPhysicsPlayerController __near *,int>>::FindAndRemove(class IPhysicsPlayerController __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<IPhysicsPlayerController *,CUtlMemory<IPhysicsPlayerController *,int>>::FindAndRemove(
        CUtlVector<IPhysicsEnvironment *,CUtlMemory<IPhysicsEnvironment *,int> > *this,
        IPhysicsEnvironment **src)
{
  int m_Size; // edx
  int v4; // eax
  IPhysicsEnvironment **m_pMemory; // ebx
  IPhysicsEnvironment **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100175F0
// Name: public: void CUtlVector<class CSurface,class CUtlMemory<class CSurface,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CSurface,CUtlMemory<CSurface,int>>::Purge(
        CUtlVector<CSurface,CUtlMemory<CSurface,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CSurface *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      ((void (__thiscall *)(CSurface *, _DWORD))this->m_Memory.m_pMemory[v3].dtr_IVP_Material)(
        a1: &this->m_Memory.m_pMemory[v3],
        a2: 0);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100176C0
// Name: public: int CUtlVector<class CSurface,class CUtlMemory<class CSurface,int>>::InsertBefore(int,class CSurface const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSurface,CUtlMemory<CSurface,int>>::InsertBefore(
        CUtlVector<CSurface,CUtlMemory<CSurface,int> > *this,
        int elem,
        const CSurface *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSurface *m_pMemory; // ecx
  int v7; // eax
  CSurface *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CSurface,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 120 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->__vftable = (CSurface_vtbl *)&IVP_Material::`vftable';
    v8->material_type = src->material_type;
    v8->second_friction_x_enabled = src->second_friction_x_enabled;
    v8->__vftable = (CSurface_vtbl *)&CSurface::`vftable';
    v8->m_name.m_Id = src->m_name.m_Id;
    v8->m_pad = src->m_pad;
    qmemcpy(&v8->data, &src->data, sizeof(v8->data));
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10017770
// Name: public: int CUtlVector<class CSurface,class CUtlMemory<class CSurface,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSurface,CUtlMemory<CSurface,int>>::InsertMultipleBefore(
        CUtlVector<CSurface,CUtlMemory<CSurface,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // ecx
  CSurface *m_pMemory; // edx
  int v10; // eax
  int v11; // ebx
  CSurface *v12; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CSurface,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 120 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          v12->second_friction_x_enabled = IVP_FALSE;
          v12->__vftable = (CSurface_vtbl *)&CSurface::`vftable';
          v12->m_name.m_Id = -1;
          memset(dst: (unsigned __int8 *)&v12->data, value: 0, count: sizeof(v12->data));
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10018E60
// Name: public: int CUtlVector<struct CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,class CUtlMemory<struct CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,int>>::InsertBefore(int,struct CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,CUtlMemory<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,int>>::InsertBefore(
        CUtlVector<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,CUtlMemory<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,int> > *this,
        int elem,
        const CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *m_pMemory; // ecx
  int v7; // eax
  CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsMotionController::PredictionCommandOffsets_t,int>::Grow(
      (CUtlMemory<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10018EE0
// Name: public: int CUtlVector<class IPhysicsObject __near *,class CUtlMemory<class IPhysicsObject __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001D790
// Name: public: int CUtlVector<struct CPhysicsEnvironment::PredictedData_t,class CUtlMemory<struct CPhysicsEnvironment::PredictedData_t,int>>::InsertBefore(int,struct CPhysicsEnvironment::PredictedData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPhysicsEnvironment::PredictedData_t,CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>>::InsertBefore(
        CUtlVector<CCollisionSolver::realobjectpair_t,CUtlMemory<CCollisionSolver::realobjectpair_t,int> > *this,
        int elem,
        const CCollisionSolver::realobjectpair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CCollisionSolver::realobjectpair_t *m_pMemory; // ecx
  int v7; // eax
  CCollisionSolver::realobjectpair_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>::Grow(
      (CUtlMemory<CUtlMultiList<void *,unsigned short>::ListElem_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001D800
// Name: public: int CUtlVector<struct CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,class CUtlMemory<struct CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,int>>::InsertBefore(int,struct CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,CUtlMemory<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,int>>::InsertBefore(
        CUtlVector<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,CUtlMemory<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,int> > *this,
        int elem,
        const CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 744 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021810
// Name: public: int CUtlVector<class Vector,class CUtlMemoryFixed<class Vector,8,0>>::AddToTail(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0>>::AddToTail(
        CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *this,
        const Vector *src)
{
  int m_Size; // esi
  Vector *v3; // eax

  m_Size = this->m_Size;
  this->m_Size = m_Size + 1;
  this->m_pElements = (Vector *)this;
  v3 = (Vector *)((char *)this + 12 * m_Size);
  if ( v3 != nullptr )
    *v3 = *src;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10021BF0
// Name: public: class CUtlVector<class Vector,class CUtlMemoryFixed<class Vector,8,0>> __near & CUtlVector<class Vector,class CUtlMemoryFixed<class Vector,8,0>>::operator=(class CUtlVector<class Vector,class CUtlMemoryFixed<class Vector,8,0>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *__thiscall CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0>>::operator=(
        CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *this,
        const CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *other)
{
  CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *result; // eax
  const CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *v3; // ecx
  int m_Size; // ebx
  int v5; // edi
  char *v6; // esi
  unsigned int v7; // edi
  char *v8; // edx
  float *v9; // esi
  int v10; // ecx
  char *v11; // edx
  int v12; // ebx
  double v13; // st7
  int i; // [esp+Ch] [ebp-8h]

  result = this;
  v3 = other;
  m_Size = other->m_Size;
  v5 = 0;
  result->m_Size = 0;
  if ( m_Size != 0 )
  {
    result->m_Size = m_Size;
    result->m_pElements = (Vector *)result;
  }
  if ( m_Size >= 4 )
  {
    v6 = &other->m_Memory.m_Memory[28];
    v7 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    i = 4 * v7;
    v8 = &result->m_Memory.m_Memory[16];
    do
    {
      v8 += 48;
      *((float *)v8 - 16) = *((float *)v6 - 7);
      v6 += 48;
      --v7;
      *((float *)v8 - 15) = *((float *)v6 - 18);
      *((float *)v8 - 14) = *((float *)v6 - 17);
      *((float *)v8 - 13) = *((float *)v6 - 16);
      *((float *)v8 - 12) = *(float *)&v8[(char *)other - (char *)result - 48];
      *((float *)v8 - 11) = *((float *)v6 - 14);
      *((float *)v8 - 10) = *((float *)v6 - 13);
      *((float *)v8 - 9) = *((float *)v6 - 12);
      *((float *)v8 - 8) = *((float *)v6 - 11);
      *((float *)v8 - 7) = *((float *)v6 - 10);
      *((float *)v8 - 6) = *((float *)v6 - 9);
      *((float *)v8 - 5) = *((float *)v6 - 8);
    }
    while ( v7 != 0 );
    v3 = other;
    v5 = i;
  }
  if ( v5 < m_Size )
  {
    v9 = (float *)&v3->m_Memory.m_Memory[12 * v5];
    v10 = (char *)v3 - (char *)result;
    v11 = &result->m_Memory.m_Memory[12 * v5 + 4];
    v12 = m_Size - v5;
    do
    {
      v13 = *v9;
      v9 += 3;
      *((float *)v11 - 1) = v13;
      v11 += 12;
      --v12;
      *((float *)v11 - 3) = *(float *)&v11[v10 - 12];
      *((float *)v11 - 2) = *(v9 - 1);
    }
    while ( v12 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021CD0
// Name: public: void CUtlVector<struct CPredictedPlayerController::PlayerControllerPredictionBackups_t,class CUtlMemory<struct CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::RemoveMultipleFromHead(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::RemoveMultipleFromHead(
        CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int> > *this,
        int num)
{
  int v3; // ecx
  int v4; // edx
  CNormalList *p_frictionSnapshotNormals; // eax

  v3 = num - 1;
  if ( num - 1 >= 0 )
  {
    v4 = v3;
    do
    {
      p_frictionSnapshotNormals = &this->m_Memory.m_pMemory[v4--].Backup_OnPredictionCommandChanged.frictionSnapshotNormals;
      --v3;
      p_frictionSnapshotNormals->m_Normals.m_Size = 0;
      p_frictionSnapshotNormals->m_Normals.m_pElements = (Vector *)p_frictionSnapshotNormals;
    }
    while ( v3 >= 0 );
  }
  if ( this->m_Size - num > 0 && num > 0 )
    _V_memmove(dest: this->m_Memory.m_pMemory, src: &this->m_Memory.m_pMemory[num], count: 200 * (this->m_Size - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x10021D40
// Name: public: void CUtlVector<struct CPredictedPlayerController::PlayerControllerPredictionBackups_t,class CUtlMemory<struct CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::Purge(
        CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int> > *this)
{
  int v2; // ecx
  int v3; // edx
  CNormalList *p_frictionSnapshotNormals; // eax
  CPredictedPlayerController::PlayerControllerPredictionBackups_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      p_frictionSnapshotNormals = &this->m_Memory.m_pMemory[v3].Backup_OnPredictionCommandChanged.frictionSnapshotNormals;
      --v2;
      --v3;
      p_frictionSnapshotNormals->m_Normals.m_Size = 0;
      p_frictionSnapshotNormals->m_Normals.m_pElements = (Vector *)p_frictionSnapshotNormals;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022720
// Name: public: int CUtlVector<struct CPredictedPlayerController::PlayerControllerPredictionBackups_t,class CUtlMemory<struct CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::InsertBefore(int,struct CPredictedPlayerController::PlayerControllerPredictionBackups_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::InsertBefore(
        CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int> > *this,
        int elem,
        const CPredictedPlayerController::PlayerControllerPredictionBackups_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CPredictedPlayerController::PlayerControllerPredictionBackups_t *m_pMemory; // ecx
  int v7; // eax
  CPredictedPlayerController::PlayerControllerPredictionBackups_t *v8; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 200 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t::BackupData_t(
      this: &v8->Backup_OnPredictionCommandChanged,
      __that: &src->Backup_OnPredictionCommandChanged);
    v8->iCommandNum = src->iCommandNum;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10028710
// Name: public: CTSPool<class CUtlVector<class CPhysCollideVirtualMesh __near *,class CUtlMemory<class CPhysCollideVirtualMesh __near *,int>>>::~CTSPool<class CUtlVector<class CPhysCollideVirtualMesh __near *,class CUtlMemory<class CPhysCollideVirtualMesh __near *,int>>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<CUtlVector<CPhysCollideVirtualMesh *,CUtlMemory<CPhysCollideVirtualMesh *,int>>>::~CTSPool<CUtlVector<CPhysCollideVirtualMesh *,CUtlMemory<CPhysCollideVirtualMesh *,int>>>(
        CTSPool<CUtlVector<CPhysCollideVirtualMesh *,CUtlMemory<CPhysCollideVirtualMesh *,int> > > *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  void *v4; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
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
        goto LABEL_4;
    }
    Next[2].Next = nullptr;
    if ( *((int *)&Next[1].Next + 1) >= 0 )
    {
      if ( *((_DWORD *)&Next->Next + 1) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)&Next->Next + 1));
        *((_DWORD *)&Next->Next + 1) = 0;
      }
      Next[1].Next = nullptr;
    }
    v4 = *((void **)&Next->Next + 1);
    *((_DWORD *)&Next[2].Next + 1) = v4;
    if ( *((int *)&Next[1].Next + 1) >= 0 )
    {
      if ( v4 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
        *((_DWORD *)&Next->Next + 1) = 0;
      }
      Next[1].Next = nullptr;
    }
    free(data: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x10028B40
// Name: public: void leafmap_t::SetRLESpans(int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall leafmap_t::SetRLESpans(
        leafmap_t *this,
        unsigned __int16 startVertIndex,
        int spanCountIn,
        unsigned __int8 *pSpans)
{
  int v4; // eax
  unsigned __int16 v5; // ax
  unsigned __int8 *v6; // esi

  v4 = 0;
  this->flags = 0;
  if ( spanCountIn <= 14 )
  {
    if ( spanCountIn == 1 )
    {
      v5 = *pSpans;
      this->flags = 2;
      this->startVert[0] = startVertIndex;
      this->vertCount = v5;
    }
    else
    {
      this->startVert[0] = startVertIndex;
      this->flags = 4;
      this->vertCount = 0;
      this->spanCount = spanCountIn;
      if ( spanCountIn > 0 )
      {
        v6 = pSpans;
        do
        {
          v6[(char *)&this->startVert[1] - (char *)pSpans] = *v6;
          if ( (v4 & 1) == 0 )
            this->vertCount += *v6;
          ++v4;
          ++v6;
        }
        while ( v4 < spanCountIn );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028BB0
// Name: public: virtual float CTraceIVP::Radius(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTraceIVP::Radius(CTraceIVP *this)
{
  return this->m_radius;
}

//------------------------------------------------------------------------------
// Address: 0x10028BC0
// Name: GetLeafNodesList
// Source: json
//------------------------------------------------------------------------------
int __usercall GetLeafNodesList@<eax>(
        const IVP_Compact_Ledgetree_Node *pRoot@<ecx>,
        const IVP_Compact_Ledgetree_Node **pNodesOut@<edi>)
{
  int v2; // edx
  int result; // eax
  const IVP_Compact_Ledgetree_Node *pList[512]; // [esp+4h] [ebp-800h]

  v2 = 0;
  result = 0;
  while ( pRoot != nullptr )
  {
    if ( pRoot->offset_right_node != 0 )
    {
      pList[v2++] = (const IVP_Compact_Ledgetree_Node *)((char *)pRoot + pRoot->offset_right_node);
      ++pRoot;
    }
    else
    {
      pNodesOut[result++] = pRoot;
      if ( v2 == 0 )
        return result;
      pRoot = pList[--v2];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028C00
// Name: public: struct simplexvert_t __near & simplexvert_t::operator=(struct simplexvert_t const __near &)
// Source: json
//------------------------------------------------------------------------------
simplexvert_t *__thiscall simplexvert_t::operator=(simplexvert_t *this, const simplexvert_t *__that)
{
  __int16 v3; // dx

  v3 = *((_WORD *)this + 6);
  this->position = __that->position;
  *((_WORD *)this + 6) ^= (*((_WORD *)__that + 6) ^ v3) & 0x7FFF;
  *((_WORD *)this + 6) = *((_WORD *)__that + 6) ^ (*((_WORD *)this + 6) ^ *((_WORD *)__that + 6)) & 0x7FFF;
  this->obstacleIndex = __that->obstacleIndex;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028C60
// Name: public: bool simplex_t::SolveVoronoiRegion2(struct simplexvert_t const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall simplex_t::SolveVoronoiRegion2(simplex_t *this, const simplexvert_t *newPoint, Vector *pOut)
{
  float y; // xmm3_4
  float z; // xmm5_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  __int16 v8; // dx
  float v9; // xmm6_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  __int16 v16; // dx

  y = newPoint->position.y;
  z = newPoint->position.z;
  v5 = this->verts[0].position.y - y;
  v6 = this->verts[0].position.x - newPoint->position.x;
  v7 = this->verts[0].position.z - z;
  if ( (float)((float)((float)(y * v5) + (float)(newPoint->position.x * v6)) + (float)(z * v7)) >= 0.0 )
  {
    v16 = *((_WORD *)this->verts + 6);
    this->vertCount = 1;
    this->verts[0].position = newPoint->position;
    *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v16) & 0x7FFF;
    *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6)
                                ^ (*((_WORD *)this->verts + 6)
                                 ^ *((_WORD *)newPoint + 6))
                                & 0x7FFF;
    this->verts[0].obstacleIndex = newPoint->obstacleIndex;
    *pOut = newPoint->position;
  }
  else
  {
    this->vertCount = 2;
    v8 = *((_WORD *)&this->verts[1] + 6);
    this->verts[1].position = newPoint->position;
    *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ v8) & 0x7FFF;
    *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                    ^ (*((_WORD *)&this->verts[1] + 6)
                                     ^ *((_WORD *)newPoint + 6))
                                    & 0x7FFF;
    this->verts[1].obstacleIndex = newPoint->obstacleIndex;
    v9 = newPoint->position.z;
    v10 = newPoint->position.y;
    v11 = (float)(v9 * v5) - (float)(v10 * v7);
    v12 = (float)(newPoint->position.x * v7) - (float)(v9 * v6);
    v13 = (float)(v10 * v6) - (float)(newPoint->position.x * v5);
    pOut->x = (float)(v12 * v7) - (float)(v5 * v13);
    pOut->y = (float)(v6 * v13) - (float)(v11 * v7);
    pOut->z = (float)(v5 * v11) - (float)(v6 * v12);
    if ( (float)((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13)) <= 0.0000000099999999 )
    {
      v14 = v7 * 0.0;
      pOut->x = v5 - v14;
      pOut->y = v14 - v6;
      pOut->z = (float)(v6 * 0.0) - (float)(v5 * 0.0);
      return false;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10028E40
// Name: public: bool simplex_t::SolveVoronoiRegion3(struct simplexvert_t const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall simplex_t::SolveVoronoiRegion3(simplex_t *this, const simplexvert_t *newPoint, Vector *pOut)
{
  float y; // xmm6_4
  float v5; // xmm2_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  simplexvert_t *v9; // edi
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  __int16 v13; // ax
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v18; // xmm0_4
  simplexvert_t *v19; // ecx
  __int16 v20; // ax
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  __int16 v24; // dx
  float z; // [esp+18h] [ebp-Ch]
  float v28; // [esp+1Ch] [ebp-8h]
  float newPointa; // [esp+2Ch] [ebp+8h]
  Vector ABC; // 0:^18.12

  y = newPoint->position.y;
  v5 = this->verts[1].position.y - y;
  v6 = this->verts[0].position.y - y;
  v28 = y;
  z = newPoint->position.z;
  v7 = this->verts[0].position.z - z;
  v8 = this->verts[1].position.x - newPoint->position.x;
  v9 = &this->verts[1];
  v10 = this->verts[0].position.x - newPoint->position.x;
  newPointa = newPoint->position.x;
  v11 = this->verts[1].position.z - z;
  ABC.x = (float)(v11 * v6) - (float)(v7 * v5);
  ABC.y = (float)(v7 * v8) - (float)(v11 * v10);
  ABC.z = (float)(v10 * v5) - (float)(v6 * v8);
  v12 = newPoint->position.y;
  if ( (float)((float)((float)(v28 * (float)((float)(ABC.z * v8) - (float)(v11 * ABC.x)))
                     + (float)(newPointa * (float)((float)(v11 * ABC.y) - (float)(ABC.z * v5))))
             + (float)(z * (float)((float)(ABC.x * v5) - (float)(v8 * ABC.y)))) < 0.0 )
  {
    if ( (float)((float)((float)(v12 * v5) + (float)(newPointa * v8)) + (float)(newPoint->position.z * v11)) < 0.0 )
    {
      this->vertCount = 2;
      v13 = *((_WORD *)this->verts + 6);
      this->verts[0].position = newPoint->position;
      *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v13) & 0x7FFF;
      *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6)
                                  ^ (*((_WORD *)this->verts + 6)
                                   ^ *((_WORD *)newPoint + 6))
                                  & 0x7FFF;
      this->verts[0].obstacleIndex = newPoint->obstacleIndex;
      v14 = (float)(newPoint->position.z * v5) - (float)(newPoint->position.y * v11);
      v15 = (float)(newPoint->position.x * v11) - (float)(newPoint->position.z * v8);
      v16 = (float)(newPoint->position.y * v8) - (float)(newPoint->position.x * v5);
      pOut->x = (float)(v15 * v11) - (float)(v16 * v5);
      pOut->y = (float)(v16 * v8) - (float)(v11 * v14);
      pOut->z = (float)(v14 * v5) - (float)(v15 * v8);
      return false;
    }
    v18 = newPoint->position.z;
    goto LABEL_10;
  }
  v18 = newPoint->position.z;
  if ( (float)((float)((float)(v12 * (float)((float)(v7 * ABC.x) - (float)(ABC.z * v10)))
                     + (float)(newPointa * (float)((float)(ABC.z * v6) - (float)(v7 * ABC.y))))
             + (float)(v18 * (float)((float)(v10 * ABC.y) - (float)(v6 * ABC.x)))) <= 0.0 )
  {
LABEL_10:
    if ( (float)((float)((float)(v12 * v6) + (float)(newPointa * v10)) + (float)(v18 * v7)) >= 0.0 )
    {
      v24 = *((_WORD *)this->verts + 6);
      this->vertCount = 1;
      this->verts[0].position = newPoint->position;
      *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v24) & 0x7FFF;
      *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6)
                                  ^ (*((_WORD *)this->verts + 6)
                                   ^ *((_WORD *)newPoint + 6))
                                  & 0x7FFF;
      this->verts[0].obstacleIndex = newPoint->obstacleIndex;
      *pOut = newPoint->position;
    }
    else
    {
      this->vertCount = 2;
      v20 = *((_WORD *)&this->verts[1] + 6);
      v9->position.x = newPoint->position.x;
      this->verts[1].position.y = newPoint->position.y;
      this->verts[1].position.z = newPoint->position.z;
      *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ v20) & 0x7FFF;
      *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                      ^ (*((_WORD *)&this->verts[1] + 6)
                                       ^ *((_WORD *)newPoint + 6))
                                      & 0x7FFF;
      this->verts[1].obstacleIndex = newPoint->obstacleIndex;
      v21 = (float)(newPoint->position.z * v6) - (float)(newPoint->position.y * v7);
      v22 = (float)(newPoint->position.y * v10) - (float)(newPoint->position.x * v6);
      v23 = (float)(newPoint->position.x * v7) - (float)(newPoint->position.z * v10);
      pOut->x = (float)(v23 * v7) - (float)(v22 * v6);
      pOut->y = (float)(v22 * v10) - (float)(v21 * v7);
      pOut->z = (float)(v21 * v6) - (float)(v23 * v10);
    }
    return false;
  }
  this->vertCount = 3;
  v19 = &this->verts[2];
  if ( (float)((float)((float)(newPoint->position.y * ABC.y) + (float)(newPoint->position.x * ABC.x))
             + (float)(newPoint->position.z * ABC.z)) >= 0.0 )
  {
    simplexvert_t::operator=(this: v19, __that: v9);
    simplexvert_t::operator=(this: v9, __that: newPoint);
    *pOut = ABC;
  }
  else
  {
    simplexvert_t::operator=(this: v19, __that: newPoint);
    pOut->x = -ABC.x;
    pOut->y = -ABC.y;
    pOut->z = -ABC.z;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10029330
// Name: CalculateSeparatingPlane
// Source: json
//------------------------------------------------------------------------------
void __usercall CalculateSeparatingPlane(
        ITraceObject *sweepObject@<eax>,
        simplex_t *simplex@<ecx>,
        CGameTrace *ptr,
        CTraceRay *ray,
        ITraceObject *obstacle)
{
  int vertCount; // ebx
  int v7; // edi
  int v8; // edx
  int v9; // eax
  _WORD *v10; // edi
  int v11; // eax
  bool v12; // zf
  int v13; // eax
  int i; // eax
  float z; // xmm6_4
  float y; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  unsigned int obstacleIndex[4]; // [esp+Ch] [ebp-58h]
  unsigned int testIndex[4]; // [esp+1Ch] [ebp-48h]
  Vector t0; // [esp+2Ch] [ebp-38h] BYREF
  Vector t3; // [esp+38h] [ebp-2Ch] BYREF
  Vector t2; // [esp+44h] [ebp-20h] BYREF
  Vector t1; // [esp+50h] [ebp-14h] BYREF
  int v44; // [esp+5Ch] [ebp-8h]
  int obstacleCount; // [esp+60h] [ebp-4h]

  vertCount = simplex->vertCount;
  v7 = simplex->verts[0].obstacleIndex;
  v8 = 1;
  v9 = *((_WORD *)simplex->verts + 6) & 0x7FFF;
  obstacleCount = 1;
  testIndex[0] = v9;
  obstacleIndex[0] = v7;
  if ( vertCount > 1 )
  {
    v10 = (_WORD *)&simplex->verts[1] + 6;
    v44 = vertCount - 1;
    do
    {
      v11 = 0;
      v12 = obstacleCount == 0;
      if ( obstacleCount > 0 )
      {
        do
        {
          if ( obstacleIndex[v11] == (unsigned __int16)v10[1] )
            break;
          ++v11;
        }
        while ( v11 < obstacleCount );
        v12 = v11 == obstacleCount;
      }
      if ( v12 )
      {
        v13 = obstacleCount;
        obstacleIndex[obstacleCount] = (unsigned __int16)v10[1];
        obstacleCount = v13 + 1;
      }
      for ( i = 0; i < v8; ++i )
      {
        if ( testIndex[i] == (*v10 & 0x7FFF) )
          break;
      }
      if ( i == v8 )
        testIndex[v8++] = *v10 & 0x7FFF;
      v10 += 8;
      --v44;
    }
    while ( v44 != 0 );
    v9 = testIndex[0];
    v7 = obstacleIndex[0];
  }
  if ( vertCount == 2 && v8 == 2 )
  {
    sweepObject->GetVertByIndex(this: sweepObject, result: &t2, a3: v9);
    sweepObject->GetVertByIndex(this: sweepObject, result: &t1, a3: testIndex[1]);
    z = ray->m_delta.z;
    y = ray->m_delta.y;
    v17 = (float)((float)(t1.y - t2.y) * z) - (float)((float)(t1.z - t2.z) * y);
    v18 = (float)((float)(t1.z - t2.z) * ray->m_delta.x) - (float)(z * (float)(t1.x - t2.x));
    v19 = (float)(y * (float)(t1.x - t2.x)) - (float)((float)(t1.y - t2.y) * ray->m_delta.x);
    v20 = (float)(v19 * (float)(t1.y - t2.y)) - (float)(v18 * (float)(t1.z - t2.z));
    v21 = (float)((float)(t1.z - t2.z) * v17) - (float)(v19 * (float)(t1.x - t2.x));
    v22 = (float)(v18 * (float)(t1.x - t2.x)) - (float)((float)(t1.y - t2.y) * v17);
    ptr->plane.normal.x = v20;
    ptr->plane.normal.y = v21;
    ptr->plane.normal.z = v22;
    VectorNormalize(vec: &ptr->plane.normal);
  }
  else if ( v8 == 3 )
  {
    sweepObject->GetVertByIndex(this: sweepObject, result: &t1, a3: v9);
    sweepObject->GetVertByIndex(this: sweepObject, result: &t3, a3: testIndex[1]);
    sweepObject->GetVertByIndex(this: sweepObject, result: &t2, a3: testIndex[2]);
    v23 = (float)((float)(t3.z - t1.z) * (float)(t2.x - t1.x)) - (float)((float)(t2.z - t1.z) * (float)(t3.x - t1.x));
    v24 = (float)((float)(t2.y - t1.y) * (float)(t3.x - t1.x)) - (float)((float)(t3.y - t1.y) * (float)(t2.x - t1.x));
    ptr->plane.normal.x = (float)((float)(t3.y - t1.y) * (float)(t2.z - t1.z))
                        - (float)((float)(t3.z - t1.z) * (float)(t2.y - t1.y));
    ptr->plane.normal.y = v23;
    ptr->plane.normal.z = v24;
    VectorNormalize(vec: &ptr->plane.normal);
    v25 = ptr->plane.normal.y;
    v26 = ptr->plane.normal.z;
    if ( (float)((float)((float)(ray->m_delta.y * v25) + (float)(ptr->plane.normal.x * ray->m_delta.x))
               + (float)(ray->m_delta.z * v26)) > 0.0 )
    {
      ptr->plane.normal.x = -ptr->plane.normal.x;
      ptr->plane.normal.y = -v25;
      ptr->plane.normal.z = -v26;
    }
  }
  else if ( v8 == 2 && obstacleCount == 2 )
  {
    sweepObject->GetVertByIndex(this: sweepObject, result: &t0, a3: v9);
    sweepObject->GetVertByIndex(this: sweepObject, result: &t1, a3: testIndex[1]);
    obstacle->GetVertByIndex(this: obstacle, result: &t2, a3: v7);
    obstacle->GetVertByIndex(this: obstacle, result: &t3, a3: obstacleIndex[1]);
    v27 = (float)((float)(t1.z - t0.z) * (float)(t3.x - t2.x)) - (float)((float)(t3.z - t2.z) * (float)(t1.x - t0.x));
    v28 = (float)((float)(t3.y - t2.y) * (float)(t1.x - t0.x)) - (float)((float)(t1.y - t0.y) * (float)(t3.x - t2.x));
    ptr->plane.normal.x = (float)((float)(t1.y - t0.y) * (float)(t3.z - t2.z))
                        - (float)((float)(t1.z - t0.z) * (float)(t3.y - t2.y));
    ptr->plane.normal.y = v27;
    ptr->plane.normal.z = v28;
    VectorNormalize(vec: &ptr->plane.normal);
    v29 = ptr->plane.normal.y;
    v30 = ptr->plane.normal.z;
    if ( (float)((float)((float)(ray->m_delta.y * v29) + (float)(ptr->plane.normal.x * ray->m_delta.x))
               + (float)(ray->m_delta.z * v30)) > 0.0 )
    {
      ptr->plane.normal.x = -ptr->plane.normal.x;
      ptr->plane.normal.y = -v29;
      ptr->plane.normal.z = -v30;
    }
  }
  else if ( obstacleCount == 3 )
  {
    obstacle->GetVertByIndex(this: obstacle, result: &t3, a3: v7);
    obstacle->GetVertByIndex(this: obstacle, result: &t2, a3: obstacleIndex[1]);
    obstacle->GetVertByIndex(this: obstacle, result: &t0, a3: obstacleIndex[2]);
    v32 = (float)((float)(t2.z - t3.z) * (float)(t0.x - t3.x)) - (float)((float)(t0.z - t3.z) * (float)(t2.x - t3.x));
    v33 = (float)((float)(t0.y - t3.y) * (float)(t2.x - t3.x)) - (float)((float)(t2.y - t3.y) * (float)(t0.x - t3.x));
    ptr->plane.normal.x = (float)((float)(t2.y - t3.y) * (float)(t0.z - t3.z))
                        - (float)((float)(t2.z - t3.z) * (float)(t0.y - t3.y));
    ptr->plane.normal.y = v32;
    ptr->plane.normal.z = v33;
    VectorNormalize(vec: &ptr->plane.normal);
    v34 = ptr->plane.normal.y;
    v35 = ptr->plane.normal.z;
    if ( (float)((float)((float)(ray->m_delta.y * v34) + (float)(ptr->plane.normal.x * ray->m_delta.x))
               + (float)(ray->m_delta.z * v35)) > 0.0 )
    {
      ptr->plane.normal.x = -ptr->plane.normal.x;
      ptr->plane.normal.y = -v34;
      ptr->plane.normal.z = -v35;
    }
  }
  else
  {
    v36 = -ray->m_dir.y;
    v37 = -ray->m_dir.z;
    ptr->plane.normal.x = -ray->m_dir.x;
    ptr->plane.normal.y = v36;
    ptr->plane.normal.z = v37;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029880
// Name: public: class Vector simplex_t::ClipRayToTetrahedronBase(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall simplex_t::ClipRayToTetrahedronBase(simplex_t *this, Vector *result, const Vector *dir)
{
  float x; // xmm2_4
  float v4; // xmm5_4
  float y; // xmm6_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float z; // xmm3_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm7_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  int v31; // eax
  __int16 v32; // ax
  __int64 v33; // xmm0_8
  Vector *v34; // eax
  float v35; // ecx
  __int16 v36; // dx
  __int64 v37; // xmm0_8
  float v38; // ecx
  __int16 v39; // dx
  __int64 v40; // xmm0_8
  float v41; // ecx
  __int64 v42; // xmm0_8
  __int16 v43; // ax
  __int16 v44; // ax
  float v45; // ecx
  float AB; // [esp+0h] [ebp-7Ch]
  float BD_8; // [esp+14h] [ebp-68h]
  Vector BCD; // [esp+18h] [ebp-64h]
  Vector BC; // [esp+24h] [ebp-58h]
  Vector AD; // [esp+30h] [ebp-4Ch]
  Vector ACD; // [esp+3Ch] [ebp-40h]
  Vector ABC; // [esp+48h] [ebp-34h]
  float v53; // [esp+54h] [ebp-28h]
  float v54; // [esp+58h] [ebp-24h]
  float v55; // [esp+5Ch] [ebp-20h]
  float v56; // [esp+60h] [ebp-1Ch]
  float v57; // [esp+64h] [ebp-18h]
  float v58; // [esp+68h] [ebp-14h]
  float v59; // [esp+6Ch] [ebp-10h]
  float v60; // [esp+70h] [ebp-Ch]
  float v61; // [esp+74h] [ebp-8h]
  float v62; // [esp+78h] [ebp-4h]
  float dira; // [esp+88h] [ebp+Ch]

  x = this->verts[3].position.x;
  v4 = this->verts[2].position.x;
  y = this->verts[3].position.y;
  v6 = this->verts[1].position.x;
  v7 = this->verts[1].position.y;
  z = this->verts[0].position.z;
  v9 = this->verts[3].position.z;
  v60 = this->verts[0].position.x;
  v55 = v4;
  AB = v60 - x;
  v10 = this->verts[0].position.y;
  v57 = v6;
  AD.x = v4 - x;
  v11 = this->verts[2].position.y;
  v59 = v10;
  v12 = v10 - y;
  v62 = v7;
  v13 = v7 - y;
  v54 = v11;
  v14 = v11 - y;
  BC.x = v6 - v60;
  BC.y = v62 - v59;
  BCD.x = v6 - x;
  v56 = this->verts[1].position.z;
  v58 = z;
  BC.z = v56 - z;
  v15 = z - v9;
  v61 = x;
  v53 = this->verts[2].position.z;
  BD_8 = v53 - v58;
  v16 = v53 - v9;
  ABC.x = (float)((float)(v56 - v9) * v12) - (float)(v13 * v15);
  ABC.y = (float)(v15 * BCD.x) - (float)((float)(v56 - v9) * AB);
  v53 = v13 * AB;
  ABC.z = (float)(v13 * AB) - (float)(v12 * BCD.x);
  ACD.x = (float)(v16 * v13) - (float)(v14 * (float)(v56 - v9));
  v18 = (float)((float)(v56 - v9) * AD.x) - (float)(v16 * BCD.x);
  v19 = (float)(v14 * BCD.x) - (float)(v13 * AD.x);
  ACD.y = v18;
  v20 = (float)(v14 * v15) - (float)(v16 * v12);
  AD.y = (float)(v16 * AB) - (float)(v15 * AD.x);
  AD.z = (float)(v12 * AD.x) - (float)(v14 * AB);
  v21 = dir->y;
  BCD.z = (float)((float)(v62 - v59) * (float)(v55 - v60)) - (float)((float)(v54 - v59) * (float)(v57 - v60));
  dira = dir->z;
  v22 = (float)((float)(v54 - v59) * BC.z) - (float)(BD_8 * (float)(v62 - v59));
  v23 = dir->x;
  v24 = (float)((float)(dir->x * ABC.x) + (float)(v21 * ABC.y)) + (float)(dira * ABC.z);
  ACD.z = v19;
  AD.x = v20;
  BCD.x = v22;
  BCD.y = (float)(BD_8 * (float)(v57 - v60)) - (float)(BC.z * (float)(v55 - v60));
  if ( v24 <= 0.0 )
    v62 = 1.0e24;
  else
    v62 = (float)((float)((float)(ABC.y * this->verts[3].position.y) + (float)(v61 * ABC.x))
                + (float)(ABC.z * this->verts[3].position.z))
        / v24;
  v54 = (float)((float)(v23 * ACD.x) + (float)(v21 * ACD.y)) + (float)(dira * v19);
  if ( v54 <= 0.0 )
  {
    v25 = 1.0e24;
  }
  else
  {
    v53 = ACD.y * this->verts[3].position.y;
    v25 = (float)((float)(v53 + (float)(v61 * ACD.x)) + (float)(v19 * this->verts[3].position.z)) / v54;
  }
  v57 = v25;
  v26 = (float)((float)(v23 * v20) + (float)(v21 * AD.y)) + (float)(dira * AD.z);
  if ( v26 <= 0.0 )
    v27 = 1.0e24;
  else
    v27 = (float)((float)((float)(AD.y * this->verts[3].position.y) + (float)(v61 * v20))
                + (float)(AD.z * this->verts[3].position.z))
        / v26;
  v28 = (float)((float)(v23 * v22) + (float)(v21 * BCD.y)) + (float)(dira * BCD.z);
  if ( v28 <= 0.0 )
    v29 = 1.0e24;
  else
    v29 = (float)((float)((float)(v60 * v22) + (float)(v59 * BCD.y)) + (float)(v58 * BCD.z)) / v28;
  v30 = v29;
  v31 = 3;
  if ( v29 > v62 )
  {
    v31 = 0;
    v30 = v62;
  }
  if ( v30 > v57 )
  {
    v31 = 1;
    v30 = v57;
  }
  if ( v30 > v27 )
    v31 = 2;
  this->vertCount = 3;
  switch ( v31 )
  {
    case 0:
      v32 = *((_WORD *)&this->verts[2] + 6);
      this->verts[2].position.x = this->verts[3].position.x;
      v33 = *(_QWORD *)&ABC.x;
      this->verts[2].position.y = this->verts[3].position.y;
      this->verts[2].position.z = this->verts[3].position.z;
      *((_WORD *)&this->verts[2] + 6) ^= (*((_WORD *)&this->verts[3] + 6) ^ v32) & 0x7FFF;
      *((_WORD *)&this->verts[2] + 6) = *((_WORD *)&this->verts[3] + 6)
                                      ^ (*((_WORD *)&this->verts[2] + 6)
                                       ^ *((_WORD *)&this->verts[3] + 6))
                                      & 0x7FFF;
      this->verts[2].obstacleIndex = this->verts[3].obstacleIndex;
      v35 = ABC.z;
      *(_QWORD *)&result->x = v33;
      result->z = v35;
      v34 = result;
      break;
    case 1:
      v36 = *((_WORD *)this->verts + 6);
      this->verts[0].position.x = this->verts[3].position.x;
      v37 = *(_QWORD *)&ACD.x;
      this->verts[0].position.y = this->verts[3].position.y;
      this->verts[0].position.z = this->verts[3].position.z;
      *((_WORD *)this->verts + 6) ^= (*((_WORD *)&this->verts[3] + 6) ^ v36) & 0x7FFF;
      *((_WORD *)this->verts + 6) = *((_WORD *)&this->verts[3] + 6)
                                  ^ (*((_WORD *)this->verts + 6)
                                   ^ *((_WORD *)&this->verts[3] + 6))
                                  & 0x7FFF;
      this->verts[0].obstacleIndex = this->verts[3].obstacleIndex;
      v38 = ACD.z;
      *(_QWORD *)&result->x = v37;
      result->z = v38;
      v34 = result;
      break;
    case 2:
      v39 = *((_WORD *)&this->verts[1] + 6);
      this->verts[1].position.x = this->verts[3].position.x;
      v40 = *(_QWORD *)&AD.x;
      this->verts[1].position.y = this->verts[3].position.y;
      this->verts[1].position.z = this->verts[3].position.z;
      *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)&this->verts[3] + 6) ^ v39) & 0x7FFF;
      *((_WORD *)&this->verts[1] + 6) = *((_WORD *)&this->verts[3] + 6)
                                      ^ (*((_WORD *)&this->verts[1] + 6)
                                       ^ *((_WORD *)&this->verts[3] + 6))
                                      & 0x7FFF;
      this->verts[1].obstacleIndex = this->verts[3].obstacleIndex;
      v41 = AD.z;
      *(_QWORD *)&result->x = v40;
      result->z = v41;
      v34 = result;
      break;
    case 3:
      this->verts[3].position.x = this->verts[1].position.x;
      v42 = *(_QWORD *)&BCD.x;
      this->verts[3].position.y = this->verts[1].position.y;
      this->verts[3].position.z = this->verts[1].position.z;
      *((_WORD *)&this->verts[3] + 6) ^= (*((_WORD *)&this->verts[3] + 6) ^ *((_WORD *)&this->verts[1] + 6)) & 0x7FFF;
      *((_WORD *)&this->verts[3] + 6) = *((_WORD *)&this->verts[1] + 6)
                                      ^ (*((_WORD *)&this->verts[3] + 6)
                                       ^ *((_WORD *)&this->verts[1] + 6))
                                      & 0x7FFF;
      this->verts[3].obstacleIndex = this->verts[1].obstacleIndex;
      v43 = *((_WORD *)&this->verts[1] + 6);
      this->verts[1].position = this->verts[2].position;
      *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)&this->verts[2] + 6) ^ v43) & 0x7FFF;
      *((_WORD *)&this->verts[1] + 6) = *((_WORD *)&this->verts[2] + 6)
                                      ^ (*((_WORD *)&this->verts[1] + 6)
                                       ^ *((_WORD *)&this->verts[2] + 6))
                                      & 0x7FFF;
      this->verts[1].obstacleIndex = this->verts[2].obstacleIndex;
      v44 = *((_WORD *)&this->verts[2] + 6);
      this->verts[2].position = this->verts[3].position;
      *((_WORD *)&this->verts[2] + 6) ^= (*((_WORD *)&this->verts[3] + 6) ^ v44) & 0x7FFF;
      *((_WORD *)&this->verts[2] + 6) = *((_WORD *)&this->verts[3] + 6)
                                      ^ (*((_WORD *)&this->verts[2] + 6)
                                       ^ *((_WORD *)&this->verts[3] + 6))
                                      & 0x7FFF;
      this->verts[2].obstacleIndex = this->verts[3].obstacleIndex;
      v45 = BCD.z;
      *(_QWORD *)&result->x = v42;
      result->z = v45;
      v34 = result;
      break;
  }
  return v34;
}

//------------------------------------------------------------------------------
// Address: 0x10029EF0
// Name: public: class Vector simplex_t::ClipRayToTetrahedron(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall simplex_t::ClipRayToTetrahedron(simplex_t *this, Vector *result, const Vector *dir)
{
  float x; // xmm2_4
  float y; // xmm6_4
  float z; // xmm7_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm6_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  int v28; // eax
  int v29; // eax
  Vector *v30; // eax
  float v31; // ecx
  __int64 v32; // xmm0_8
  __int16 v33; // dx
  __int64 v34; // xmm0_8
  float v35; // ecx
  __int64 v36; // xmm0_8
  float v37; // ecx
  float AD; // [esp+0h] [ebp-4Ch]
  float AB; // [esp+Ch] [ebp-40h]
  Vector ACD; // [esp+18h] [ebp-34h]
  Vector ADB; // [esp+24h] [ebp-28h]
  Vector ABC; // [esp+30h] [ebp-1Ch]
  float v43; // [esp+3Ch] [ebp-10h]
  float v44; // [esp+40h] [ebp-Ch]
  float v45; // [esp+44h] [ebp-8h]
  float v46; // [esp+48h] [ebp-4h]

  x = this->verts[3].position.x;
  y = this->verts[3].position.y;
  z = this->verts[3].position.z;
  v6 = this->verts[0].position.x;
  v7 = this->verts[1].position.x;
  v8 = this->verts[2].position.x;
  v9 = this->verts[0].position.z;
  v10 = this->verts[1].position.y - y;
  v44 = y;
  ADB.x = v7 - x;
  v11 = this->verts[1].position.z - z;
  v12 = v9 - z;
  AB = v6 - x;
  v13 = this->verts[0].position.y - y;
  v46 = z;
  AD = v8 - x;
  v14 = this->verts[2].position.y - y;
  v45 = x;
  v15 = this->verts[2].position.z - z;
  ABC.x = (float)(v11 * v13) - (float)(v10 * v12);
  v43 = v10 * AB;
  ABC.y = (float)(v12 * ADB.x) - (float)(v11 * AB);
  ABC.z = (float)(v10 * AB) - (float)(v13 * ADB.x);
  ACD.x = (float)(v15 * v10) - (float)(v14 * v11);
  v16 = (float)(v14 * ADB.x) - (float)(v10 * AD);
  ACD.y = (float)(v11 * AD) - (float)(v15 * ADB.x);
  v17 = (float)(v14 * v12) - (float)(v15 * v13);
  ACD.z = v16;
  ADB.x = v17;
  ADB.y = (float)(v15 * AB) - (float)(v12 * AD);
  ADB.z = (float)(v13 * AD) - (float)(v14 * AB);
  v18 = dir->y;
  v19 = dir->x;
  v20 = dir->z;
  v21 = (float)((float)(v18 * ABC.y) + (float)(dir->x * ABC.x)) + (float)(v20 * ABC.z);
  if ( v21 <= 0.0 )
    v22 = 1.0e24;
  else
    v22 = (float)((float)((float)(v45 * ABC.x) + (float)(v44 * ABC.y)) + (float)(v46 * ABC.z)) / v21;
  v43 = v22;
  v23 = (float)((float)(v18 * ACD.y) + (float)(v19 * ACD.x)) + (float)(v20 * v16);
  if ( v23 <= 0.0 )
  {
    v25 = 1.0e24;
    v24 = v46;
  }
  else
  {
    v24 = v46;
    v25 = (float)((float)((float)(v45 * ACD.x) + (float)(v44 * ACD.y)) + (float)(v46 * v16)) / v23;
  }
  v26 = (float)((float)(v18 * ADB.y) + (float)(v19 * v17)) + (float)(v20 * ADB.z);
  if ( v26 <= 0.0 )
    v27 = 1.0e24;
  else
    v27 = (float)((float)((float)(v45 * v17) + (float)(v44 * ADB.y)) + (float)(v24 * ADB.z)) / v26;
  v28 = 2;
  if ( v27 > v43 )
  {
    v28 = 0;
    v27 = v43;
  }
  if ( v27 > v25 )
    v28 = 1;
  this->vertCount = 3;
  if ( v28 != 0 )
  {
    v29 = v28 - 1;
    if ( v29 != 0 )
    {
      if ( v29 == 1 )
      {
        v32 = *(_QWORD *)&ADB.x;
        this->verts[1].position = this->verts[3].position;
        *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)&this->verts[1] + 6) ^ *((_WORD *)&this->verts[3] + 6)) & 0x7FFF;
        v30 = result;
        *((_WORD *)&this->verts[1] + 6) = *((_WORD *)&this->verts[3] + 6)
                                        ^ (*((_WORD *)&this->verts[1] + 6)
                                         ^ *((_WORD *)&this->verts[3] + 6))
                                        & 0x7FFF;
        this->verts[1].obstacleIndex = this->verts[3].obstacleIndex;
        v31 = ADB.z;
        *(_QWORD *)&result->x = v32;
      }
      else
      {
        v30 = result;
        v31 = vec3_origin.z;
        *(_QWORD *)&result->x = *(_QWORD *)&vec3_origin.x;
      }
      v30->z = v31;
    }
    else
    {
      v33 = *((_WORD *)this->verts + 6);
      this->verts[0].position.x = this->verts[3].position.x;
      v34 = *(_QWORD *)&ACD.x;
      this->verts[0].position.y = this->verts[3].position.y;
      this->verts[0].position.z = this->verts[3].position.z;
      *((_WORD *)this->verts + 6) ^= (*((_WORD *)&this->verts[3] + 6) ^ v33) & 0x7FFF;
      *((_WORD *)this->verts + 6) = *((_WORD *)&this->verts[3] + 6)
                                  ^ (*((_WORD *)this->verts + 6)
                                   ^ *((_WORD *)&this->verts[3] + 6))
                                  & 0x7FFF;
      this->verts[0].obstacleIndex = this->verts[3].obstacleIndex;
      v35 = ACD.z;
      *(_QWORD *)&result->x = v34;
      result->z = v35;
      return result;
    }
  }
  else
  {
    v36 = *(_QWORD *)&ABC.x;
    this->verts[2].position = this->verts[3].position;
    *((_WORD *)&this->verts[2] + 6) ^= (*((_WORD *)&this->verts[2] + 6) ^ *((_WORD *)&this->verts[3] + 6)) & 0x7FFF;
    *((_WORD *)&this->verts[2] + 6) = *((_WORD *)&this->verts[3] + 6)
                                    ^ (*((_WORD *)&this->verts[2] + 6)
                                     ^ *((_WORD *)&this->verts[3] + 6))
                                    & 0x7FFF;
    this->verts[2].obstacleIndex = this->verts[3].obstacleIndex;
    v37 = ABC.z;
    *(_QWORD *)&result->x = v36;
    result->z = v37;
    return result;
  }
  return v30;
}

//------------------------------------------------------------------------------
// Address: 0x1002A320
// Name: public: float simplex_t::ClipRayToTriangle(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall simplex_t::ClipRayToTriangle(simplex_t *this, const Vector *dir, float epsilon)
{
  float z; // xmm5_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float x; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm5_4
  float v21; // xmm0_4
  int v22; // eax
  float BC; // [esp+4h] [ebp-5Ch]
  float BC_4; // [esp+8h] [ebp-58h]
  float BC_8; // [esp+Ch] [ebp-54h]
  Vector AC; // [esp+10h] [ebp-50h]
  Vector AB; // [esp+1Ch] [ebp-44h]
  Vector ABC; // [esp+28h] [ebp-38h] BYREF
  Vector edgeAB; // [esp+34h] [ebp-2Ch] BYREF
  Vector edgeBC; // [esp+40h] [ebp-20h] BYREF
  Vector edgeAC; // [esp+4Ch] [ebp-14h] BYREF
  float dot; // [esp+58h] [ebp-8h]
  float y; // [esp+5Ch] [ebp-4h]
  float dmin; // [esp+68h] [ebp+8h]

  z = this->verts[1].position.z;
  v5 = this->verts[0].position.y - this->verts[2].position.y;
  v6 = this->verts[0].position.z - this->verts[2].position.z;
  v7 = this->verts[0].position.x - this->verts[2].position.x;
  x = this->verts[1].position.x;
  v9 = x - this->verts[0].position.x;
  v10 = x - this->verts[2].position.x;
  y = this->verts[1].position.y;
  v11 = y - this->verts[2].position.y;
  BC_4 = y - this->verts[0].position.y;
  dot = z;
  v12 = z - this->verts[2].position.z;
  BC_8 = dot - this->verts[0].position.z;
  AB.z = v6;
  AC.y = v11;
  AB.y = v5;
  AC.z = v12;
  AB.x = v7;
  AC.x = v10;
  ABC.x = (float)(v12 * v5) - (float)(v11 * v6);
  ABC.y = (float)(v6 * v10) - (float)(v12 * v7);
  ABC.z = (float)(v11 * v7) - (float)(v5 * v10);
  VectorNormalize(vec: &ABC);
  edgeAB.x = (float)(ABC.z * v5) - (float)(ABC.y * v6);
  edgeAB.y = (float)(v6 * ABC.x) - (float)(ABC.z * v7);
  edgeAB.z = (float)(ABC.y * v7) - (float)(v5 * ABC.x);
  edgeAC.x = (float)(ABC.y * v12) - (float)(ABC.z * v11);
  edgeAC.z = (float)(v11 * ABC.x) - (float)(ABC.y * v10);
  edgeAC.y = (float)(ABC.z * v10) - (float)(v12 * ABC.x);
  edgeBC.x = (float)(ABC.z * BC_4) - (float)(ABC.y * BC_8);
  edgeBC.y = (float)(BC_8 * ABC.x) - (float)(ABC.z * v9);
  edgeBC.z = (float)(ABC.y * v9) - (float)(BC_4 * ABC.x);
  VectorNormalize(vec: &edgeAB);
  VectorNormalize(vec: &edgeAC);
  VectorNormalize(vec: &edgeBC);
  v13 = dir->y;
  v14 = dir->x;
  v15 = dir->z;
  v16 = (float)((float)(v13 * edgeAB.y) + (float)(dir->x * edgeAB.x)) + (float)(v15 * edgeAB.z);
  if ( v16 <= 0.0 )
    BC = 1.0e24;
  else
    BC = (float)((float)((float)(this->verts[0].position.y * edgeAB.y) + (float)(this->verts[0].position.x * edgeAB.x))
               + (float)(this->verts[0].position.z * edgeAB.z))
       / v16;
  v17 = (float)((float)(v13 * edgeAC.y) + (float)(v14 * edgeAC.x)) + (float)(v15 * edgeAC.z);
  if ( v17 <= 0.0 )
    v18 = 1.0e24;
  else
    v18 = (float)((float)((float)(this->verts[1].position.y * edgeAC.y) + (float)(edgeAC.x * this->verts[1].position.x))
                + (float)(this->verts[1].position.z * edgeAC.z))
        / v17;
  v19 = (float)((float)(v13 * edgeBC.y) + (float)(v14 * edgeBC.x)) + (float)(v15 * edgeBC.z);
  if ( v19 <= 0.0 )
    v20 = 1.0e24;
  else
    v20 = (float)((float)((float)(this->verts[1].position.y * edgeBC.y) + (float)(edgeBC.x * this->verts[1].position.x))
                + (float)(this->verts[1].position.z * edgeBC.z))
        / v19;
  v21 = BC;
  LODWORD(AC.z) = &edgeBC;
  v22 = 0;
  LODWORD(AC.x) = &edgeAB;
  LODWORD(AC.y) = &edgeAC;
  dmin = BC;
  if ( BC > v18 )
  {
    v21 = v18;
    dmin = v18;
    v22 = 1;
  }
  if ( v21 > v20 )
  {
    v22 = 2;
    dmin = v20;
  }
  dot = (float)((float)(*(float *)(*((_DWORD *)&AC.x + v22) + 4) * v13) + (float)(**((float **)&AC.x + v22) * v14))
      + (float)(*(float *)(*((_DWORD *)&AC.x + v22) + 8) * v15);
  if ( dot > 0.0 )
    return epsilon / dot + dmin;
  else
    return 1.0e24;
}

//------------------------------------------------------------------------------
// Address: 0x1002A6D0
// Name: public: CPhysicsTrace::CPhysicsTrace(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsTrace *__thiscall CPhysicsTrace::CPhysicsTrace(CPhysicsTrace *this)
{
  IVP_U_Matrix::init(this: &g_IdentityMatrix);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002A6F0
// Name: public: void FourVectors::RotateBy(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FourVectors::RotateBy(FourVectors *this, const matrix3x4_t *matrix)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128 v5; // xmm7
  __m128 z; // xmm0
  __m128 v7; // xmm6
  __m128 v8; // xmm2
  __m128 v9; // [esp-10h] [ebp-1Ch]

  v2 = *(__m128 *)&matrix->m_flMatVal[2][0];
  v3 = *(__m128 *)&matrix->m_flMatVal[0][0];
  v4 = *(__m128 *)&matrix->m_flMatVal[1][0];
  v5 = _mm_add_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), this->y),
         _mm_mul_ps(
           _mm_shuffle_ps(*(__m128 *)&matrix->m_flMatVal[0][0], *(__m128 *)&matrix->m_flMatVal[0][0], 0),
           this->x));
  v9 = _mm_shuffle_ps(v3, v3, 170);
  z = this->z;
  v7 = _mm_add_ps(
         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), this->y), _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), this->x)),
         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), z));
  v8 = _mm_add_ps(
         _mm_mul_ps(_mm_shuffle_ps(v2, v2, 170), z),
         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), this->x), _mm_mul_ps(_mm_shuffle_ps(v2, v2, 85), this->y)));
  this->x = _mm_add_ps(v5, _mm_mul_ps(v9, z));
  this->y = v7;
  this->z = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1002A7B0
// Name: GetPackedIndex
// Source: json
//------------------------------------------------------------------------------
int __usercall GetPackedIndex@<eax>(const IVP_U_Float_Point *dir@<eax>, const IVP_Compact_Ledge *pLedge)
{
  float v2; // xmm3_4
  float v3; // xmm2_4
  float v4; // xmm4_4
  $D94D6EC998D8AC7437E59ECF9B271F0E *v5; // eax
  int ledgetree_node_offset; // ebx
  float v7; // xmm1_4
  int v8; // edx
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  _DWORD *j; // edx
  int triCount; // [esp+Ch] [ebp-10h]
  const IVP_Compact_Poly_Point *pPoints; // [esp+10h] [ebp-Ch]
  const IVP_Compact_Triangle *pBestTri; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v2 = dir->k[0];
  v3 = dir->k[1];
  v4 = dir->k[2];
  v5 = &pLedge[1].___u1;
  ledgetree_node_offset = (unsigned __int16)pLedge[1].ledgetree_node_offset;
  v7 = (float)((float)(*(float *)((char *)&pLedge[ledgetree_node_offset].ledgetree_node_offset + pLedge->c_point_offset)
                     * v3)
             + (float)(v2 * *(float *)((char *)&pLedge[ledgetree_node_offset].c_point_offset + pLedge->c_point_offset)))
     + (float)(*(float *)((char *)&pLedge[ledgetree_node_offset] + pLedge->c_point_offset + 8) * v4);
  triCount = pLedge->n_triangles;
  pBestTri = (const IVP_Compact_Triangle *)&pLedge[1];
  for ( i = 0; i < triCount; ++i )
  {
    v5 = ($D94D6EC998D8AC7437E59ECF9B271F0E *)((char *)v5
                                             + *(int *)((char *)IVP_Compact_Edge::prev_table
                                                      + ((unsigned __int8)v5 & 0xC)));
    v8 = v5->ledgetree_node_offset;
    v9 = (unsigned __int16)v5->ledgetree_node_offset;
    v10 = v9;
    do
    {
      pPoints = (const IVP_Compact_Poly_Point *)((char *)pLedge + pLedge->c_point_offset);
      if ( (float)((float)((float)(pPoints[v10].k[1] * v3) + (float)(v2 * pPoints[v10].k[0]))
                 + (float)(pPoints[v10].k[2] * v4)) > v7 )
      {
        ledgetree_node_offset = v10;
        v7 = (float)((float)(pPoints[v10].k[1] * v3) + (float)(v2 * pPoints[v10].k[0]))
           + (float)(pPoints[v10].k[2] * v4);
        pBestTri = (const IVP_Compact_Triangle *)((unsigned int)v5 & 0xFFFFFFF0);
        goto LABEL_6;
      }
      v5 = ($D94D6EC998D8AC7437E59ECF9B271F0E *)((char *)v5
                                               + 4 * ((2 * v8) >> 17)
                                               + *(int *)((char *)IVP_Compact_Edge::prev_table
                                                        + (((_BYTE)v5 + 4 * (unsigned __int8)((2 * v8) >> 17)) & 0xC)));
      v8 = v5->ledgetree_node_offset;
      v10 = (unsigned __int16)v5->ledgetree_node_offset;
    }
    while ( v10 != v9 );
    if ( v10 != ledgetree_node_offset )
      break;
LABEL_6:
    ;
  }
  v11 = ((char *)pBestTri - (char *)pLedge - 16) >> 4;
  v12 = 0;
  for ( j = (_DWORD *)pBestTri->c_three_edges; (unsigned __int16)*j != ledgetree_node_offset; ++j )
  {
    if ( ++v12 >= 3 )
      return 4 * v11;
  }
  return v12 + 4 * v11;
}

//------------------------------------------------------------------------------
// Address: 0x1002A8F0
// Name: void InitLeafmap(class IVP_Compact_Ledge __near *,struct leafmap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall InitLeafmap(int a1@<ebp>, IVP_Compact_Ledge *pLedge, leafmap_t *pLeafmapOut)
{
  leafmap_t *v3; // edx
  int v4; // ecx
  int n_triangles; // edi
  int v6; // esi
  _DWORD *v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  signed int v11; // ecx
  _DWORD *v12; // eax
  int j; // edx
  int v14; // edi
  int v15; // ecx
  int v16; // edi
  char v17; // al
  unsigned __int8 v18; // cl
  char hesse_val_low; // al
  unsigned __int16 *startVert; // esi
  unsigned __int8 *v21; // [esp-20h] [ebp-140h]
  _BYTE v22[12]; // [esp-Ch] [ebp-12Ch] BYREF
  unsigned __int8 spans[128]; // [esp+0h] [ebp-120h] BYREF
  char hasVert[128]; // [esp+80h] [ebp-A0h] BYREF
  IVP_U_Float_Point tmp; // [esp+100h] [ebp-20h]
  unsigned __int8 v26; // [esp+113h] [ebp-Dh]
  int vertCount; // [esp+114h] [ebp-Ch]
  int i; // [esp+118h] [ebp-8h]
  int retaddr; // [esp+120h] [ebp+0h]

  vertCount = a1;
  i = retaddr;
  v3 = pLeafmapOut;
  v4 = 0;
  pLeafmapOut->pLeaf = (void *)pLedge;
  *(_DWORD *)&pLeafmapOut->vertCount = 0;
  if ( pLedge != nullptr && (*((_BYTE *)pLedge + 8) & 3) == 0 )
  {
    n_triangles = pLedge->n_triangles;
    if ( n_triangles <= 512 )
    {
      v6 = 0x1FFFFFF;
      if ( n_triangles > 0 )
      {
        v7 = (_DWORD *)&pLedge[1] + 2;
        LODWORD(tmp.hesse_val) = pLedge->n_triangles;
        do
        {
          v8 = (unsigned __int16)*(v7 - 1);
          if ( v8 < v6 )
            v6 = (unsigned __int16)*(v7 - 1);
          if ( v8 > v4 )
            v4 = (unsigned __int16)*(v7 - 1);
          v9 = (unsigned __int16)*v7;
          if ( v9 < v6 )
            v6 = (unsigned __int16)*v7;
          if ( v9 > v4 )
            v4 = (unsigned __int16)*v7;
          v10 = (unsigned __int16)v7[1];
          if ( v10 < v6 )
            v6 = (unsigned __int16)v7[1];
          if ( v10 > v4 )
            v4 = (unsigned __int16)v7[1];
          v7 += 4;
          --LODWORD(tmp.hesse_val);
        }
        while ( LODWORD(tmp.hesse_val) != 0 );
        v3 = pLeafmapOut;
      }
      v11 = v4 - v6 + 1;
      LODWORD(tmp.k[2]) = v11;
      if ( v11 < 128 )
      {
        memset(dst: &spans[116], value: 0, count: v11);
        if ( n_triangles > 0 )
        {
          v12 = (_DWORD *)&pLedge[1] + 2;
          for ( j = n_triangles; j != 0; --j )
          {
            spans[(unsigned __int16)*(v12 - 1) - v6 + 116] = 1;
            spans[(unsigned __int16)*v12 - v6 + 116] = 1;
            v14 = (unsigned __int16)v12[1] - v6;
            v12 += 4;
            spans[v14 + 116] = 1;
          }
        }
        v15 = 1;
        v16 = 0;
        v26 = spans[116];
        v17 = 1;
        LODWORD(tmp.hesse_val) = 1;
        if ( SLODWORD(tmp.k[2]) <= 1 )
        {
LABEL_30:
          v21 = v22;
          v22[v16] = v17;
          leafmap_t::SetRLESpans(this: pLeafmapOut, startVertIndex: v6, spanCountIn: v16 + 1, pSpans: v21);
        }
        else
        {
          while ( v16 < 128 )
          {
            v18 = spans[v15 + 116];
            if ( v26 != v18 )
            {
              v22[v16] = v17;
              v17 = 0;
              v26 = v18;
              ++v16;
            }
            v15 = LODWORD(tmp.hesse_val) + 1;
            ++v17;
            LODWORD(tmp.hesse_val) = v15;
            if ( v15 >= SLODWORD(tmp.k[2]) )
            {
              if ( v16 >= 128 )
                break;
              goto LABEL_30;
            }
          }
        }
        v3 = pLeafmapOut;
      }
    }
  }
  if ( (v3->flags & 6) == 0 )
  {
    hesse_val_low = 0;
    v3->flags = 1;
    tmp.hesse_val = 0.0;
    startVert = v3->startVert;
    while ( 1 )
    {
      *(float *)&hasVert[116] = (float)(2 * ((hesse_val_low & 1) == 0) - 1);
      *(float *)&hasVert[120] = (float)(2 * ((hesse_val_low & 2) == 0) - 1);
      *(float *)&hasVert[124] = (float)(2 * ((hesse_val_low & 4) == 0) - 1);
      *startVert++ = GetPackedIndex(dir: (const IVP_U_Float_Point *)&hasVert[116], pLedge);
      ++LODWORD(tmp.hesse_val);
      if ( SLODWORD(tmp.hesse_val) >= 8 )
        break;
      hesse_val_low = LOBYTE(tmp.hesse_val);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AB10
// Name: public: bool CTraceIVP::BuildLeafmapCacheRLE(struct leafmap_t const restrict __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceIVP::BuildLeafmapCacheRLE(CTraceIVP *this, const leafmap_t *pLeafmap)
{
  int eax1a; // eax
  int esi1; // esi
  const VectorAligned *v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // edi
  __m128 *p_y; // edx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  bool v20; // cc
  int spanCount; // edx
  int v22; // edx
  int v23; // edx
  int v24; // edx
  __m128 v25; // xmm1
  VectorAligned *v26; // edx
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  int v; // [esp+8h] [ebp-30h]
  int v_4; // [esp+Ch] [ebp-2Ch]
  int v_8; // [esp+10h] [ebp-28h]
  int v3; // [esp+18h] [ebp-20h]
  int v2; // [esp+1Ch] [ebp-1Ch]
  int v1; // [esp+20h] [ebp-18h]
  int v0; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  const VectorAligned *pVerts; // [esp+30h] [ebp-8h]
  int spanIndex; // [esp+34h] [ebp-4h]

  eax1a = (pLeafmap->vertCount + 3) >> 2;
  this->m_cacheCount = eax1a;
  esi1 = LOBYTE(pLeafmap->startVert[1]);
  v4 = (const VectorAligned *)((char *)&this->m_pLedge[pLeafmap->startVert[0]] + this->m_pLedge->c_point_offset);
  v5 = eax1a;
  v6 = 0;
  v7 = 1;
  spanIndex = 1;
  pVerts = v4;
  i = 0;
  if ( v5 - 1 > 0 )
  {
    p_y = &this->m_vertCache[0].y;
    do
    {
      if ( esi1 >= 4 )
      {
        p_y[-1] = (__m128)v4[v6];
        *p_y = (__m128)v4[v6 + 1];
        p_y[1] = (__m128)v4[v6 + 2];
        v15 = (__m128)v4[v6 + 3];
        v6 += 4;
        esi1 -= 4;
      }
      else
      {
        if ( esi1 == 0 )
        {
          v6 += *((unsigned __int8 *)&pLeafmap->startVert[1] + v7);
          esi1 = *((unsigned __int8 *)&pLeafmap->startVert[1] + v7 + 1);
          v7 += 2;
          spanIndex = v7;
        }
        v0 = v6;
        v9 = v6 + 1;
        v10 = esi1 - 1;
        if ( v10 == 0 )
        {
          v9 += *((unsigned __int8 *)&pLeafmap->startVert[1] + v7);
          v10 = *((unsigned __int8 *)&pLeafmap->startVert[1] + v7 + 1);
          v7 += 2;
          spanIndex = v7;
        }
        v1 = v9;
        v11 = v9 + 1;
        v12 = v10 - 1;
        if ( v12 == 0 )
        {
          v11 += *((unsigned __int8 *)&pLeafmap->startVert[1] + v7);
          v12 = *((unsigned __int8 *)&pLeafmap->startVert[1] + v7 + 1);
          v7 += 2;
          spanIndex = v7;
        }
        v2 = v11;
        v13 = v11 + 1;
        v14 = v12 - 1;
        if ( v14 == 0 )
        {
          v13 += *((unsigned __int8 *)&pLeafmap->startVert[1] + v7);
          v14 = *((unsigned __int8 *)&pLeafmap->startVert[1] + v7 + 1);
          spanIndex = v7 + 2;
        }
        p_y[-1] = (__m128)pVerts[v0];
        v3 = v13;
        *p_y = (__m128)pVerts[v1];
        v6 = v13 + 1;
        esi1 = v14 - 1;
        p_y[1] = (__m128)pVerts[v2];
        v15 = (__m128)pVerts[v3];
      }
      v16 = _mm_shuffle_ps(p_y[-1], *p_y, 68);
      v17 = _mm_shuffle_ps(p_y[-1], *p_y, 238);
      v18 = _mm_shuffle_ps(p_y[1], v15, 68);
      v19 = _mm_shuffle_ps(p_y[1], v15, 238);
      p_y[-1] = _mm_shuffle_ps(v16, v18, 136);
      *p_y = _mm_shuffle_ps(v16, v18, 221);
      p_y[1] = _mm_shuffle_ps(v17, v19, 136);
      p_y += 3;
      v20 = i + 1 < this->m_cacheCount - 1;
      v7 = spanIndex;
      ++i;
      v4 = pVerts;
    }
    while ( v20 );
  }
  spanCount = pLeafmap->spanCount;
  if ( v7 >= spanCount )
    goto LABEL_20;
  if ( esi1 == 0 )
  {
    esi1 = *((unsigned __int8 *)&pLeafmap->startVert[1] + v7 + 1);
    v6 += *((unsigned __int8 *)&pLeafmap->startVert[1] + v7);
    v7 += 2;
  }
  if ( v7 >= spanCount )
  {
LABEL_20:
    v = v6;
    if ( esi1 > 1 )
    {
      --esi1;
      ++v6;
    }
  }
  else
  {
    v = v6++;
    --esi1;
  }
  v22 = pLeafmap->spanCount;
  if ( v7 >= v22 )
    goto LABEL_27;
  if ( esi1 == 0 )
  {
    esi1 = *((unsigned __int8 *)&pLeafmap->startVert[1] + v7 + 1);
    v6 += *((unsigned __int8 *)&pLeafmap->startVert[1] + v7);
    v7 += 2;
  }
  if ( v7 >= v22 )
  {
LABEL_27:
    v_4 = v6;
    if ( esi1 > 1 )
    {
      --esi1;
      ++v6;
    }
  }
  else
  {
    v_4 = v6++;
    --esi1;
  }
  v23 = pLeafmap->spanCount;
  if ( v7 >= v23 )
    goto LABEL_34;
  if ( esi1 == 0 )
  {
    esi1 = *((unsigned __int8 *)&pLeafmap->startVert[1] + v7 + 1);
    v6 += *((unsigned __int8 *)&pLeafmap->startVert[1] + v7);
    v7 += 2;
  }
  if ( v7 >= v23 )
  {
LABEL_34:
    v_8 = v6;
    if ( esi1 > 1 )
    {
      --esi1;
      ++v6;
    }
  }
  else
  {
    v_8 = v6++;
    --esi1;
  }
  if ( v7 < pLeafmap->spanCount && esi1 == 0 )
    v6 += *((unsigned __int8 *)&pLeafmap->startVert[1] + v7);
  v24 = 6 * this->m_cacheCount;
  *(VectorAligned *)((char *)&this->m_matrix.vv + 8 * v24) = v4[v];
  v25 = *(__m128 *)((char *)&this->m_matrix.vv + 8 * v24);
  v26 = (VectorAligned *)((char *)&this->m_matrix.vv + 8 * v24);
  v26[1] = v4[v_4];
  v26[2] = v4[v_8];
  v27 = (__m128)v26[1];
  v28 = _mm_shuffle_ps(v25, v27, 68);
  v29 = _mm_shuffle_ps(v25, v27, 238);
  v30 = (__m128)v4[v6];
  v31 = _mm_shuffle_ps((__m128)v26[2], v30, 68);
  v32 = _mm_shuffle_ps((__m128)v26[2], v30, 238);
  *(__m128 *)v26 = _mm_shuffle_ps(v28, v31, 136);
  v26[1] = (VectorAligned)_mm_shuffle_ps(v28, v31, 221);
  v26[2] = (VectorAligned)_mm_shuffle_ps(v29, v32, 136);
  FourVectors::RotateManyBy(
    pVectors: this->m_vertCache,
    numVectors: this->m_cacheCount,
    rotationMatrix: &this->m_ivpLocalToHLWorld);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002AE20
// Name: public: bool CTraceIVP::BuildLeafmapCache(struct leafmap_t const restrict __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceIVP::BuildLeafmapCache(CTraceIVP *this, const leafmap_t *pLeafmap)
{
  unsigned __int8 flags; // al
  int v4; // eax
  int v5; // edx
  const IVP_Compact_Ledge *m_pLedge; // esi
  __m128 *v7; // eax
  __m128 *p_y; // edx
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  unsigned int v15; // esi
  int v16; // edi
  IVP_U_Point *v17; // edx
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  int pointCount; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]
  int ia; // [esp+10h] [ebp+8h]

  if ( pLeafmap == nullptr )
    return 0;
  flags = pLeafmap->flags;
  if ( (flags & 6) == 0 || this->m_bHasTranslation )
    return 0;
  if ( (flags & 4) != 0 )
    return CTraceIVP::BuildLeafmapCacheRLE(this, pLeafmap);
  v4 = pLeafmap->startVert[0];
  pointCount = pLeafmap->vertCount;
  v5 = (pointCount + 3) >> 2;
  m_pLedge = this->m_pLedge;
  this->m_cacheCount = v5;
  v7 = (__m128 *)((char *)&m_pLedge[v4] + m_pLedge->c_point_offset);
  i = 0;
  if ( v5 - 1 > 0 )
  {
    p_y = &this->m_vertCache[0].y;
    do
    {
      ++i;
      p_y[-1] = *v7;
      v9 = p_y[-1];
      *p_y = v7[1];
      p_y[1] = v7[2];
      v10 = v7[3];
      v11 = _mm_shuffle_ps(v9, *p_y, 68);
      v12 = _mm_shuffle_ps(v9, *p_y, 238);
      v13 = _mm_shuffle_ps(p_y[1], v10, 68);
      v14 = _mm_shuffle_ps(p_y[1], v10, 238);
      p_y[-1] = _mm_shuffle_ps(v11, v13, 136);
      *p_y = _mm_shuffle_ps(v11, v13, 221);
      p_y[1] = _mm_shuffle_ps(v12, v14, 136);
      v7 += 4;
      p_y += 3;
    }
    while ( i < this->m_cacheCount - 1 );
  }
  v15 = ((_BYTE)pointCount - 1) & 3;
  v16 = 1;
  if ( v15 <= 1 )
    v16 = ((_BYTE)pointCount - 1) & 3;
  ia = 2;
  if ( (((_BYTE)pointCount - 1) & 3) != 3 )
    ia = ((_BYTE)pointCount - 1) & 3;
  v17 = &this->m_matrix.vv + 3 * this->m_cacheCount;
  *v17 = *(IVP_U_Point *)v7;
  v18 = *(__m128 *)v17;
  v17[1] = (IVP_U_Point)v7[v16];
  v17[2] = (IVP_U_Point)v7[ia];
  v19 = (__m128)v17[1];
  v20 = _mm_shuffle_ps(v18, v19, 68);
  v21 = _mm_shuffle_ps(v18, v19, 238);
  v22 = v7[v15];
  v23 = _mm_shuffle_ps((__m128)v17[2], v22, 68);
  v24 = _mm_shuffle_ps((__m128)v17[2], v22, 238);
  *(__m128 *)v17 = _mm_shuffle_ps(v20, v23, 136);
  v17[1] = (IVP_U_Point)_mm_shuffle_ps(v20, v23, 221);
  v17[2] = (IVP_U_Point)_mm_shuffle_ps(v21, v24, 136);
  FourVectors::RotateManyBy(
    pVectors: this->m_vertCache,
    numVectors: this->m_cacheCount,
    rotationMatrix: &this->m_ivpLocalToHLWorld);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002AFD0
// Name: public: bool CTraceIVP::BuildSingleTriangleCache(class IVP_Compact_Ledge const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceIVP::BuildSingleTriangleCache(CTraceIVP *this, const IVP_Compact_Ledge *pLedge)
{
  int ledgetree_node_offset; // edx
  int v4; // esi
  int v5; // edi
  const IVP_Compact_Ledge *m_pLedge; // eax
  char *v7; // ecx
  __m128 v8; // xmm0
  __m128 y; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2

  if ( pLedge->n_triangles > 2 )
    return 0;
  ledgetree_node_offset = pLedge[1].ledgetree_node_offset;
  v4 = *((_DWORD *)&pLedge[1] + 2);
  v5 = *(_DWORD *)&pLedge[1].n_triangles;
  m_pLedge = this->m_pLedge;
  this->m_cacheCount = 1;
  v7 = (char *)m_pLedge + m_pLedge->c_point_offset;
  v8 = *(__m128 *)&v7[16 * (unsigned __int16)ledgetree_node_offset];
  this->m_vertCache[0].x = v8;
  this->m_vertCache[0].y = *(__m128 *)&v7[16 * (unsigned __int16)v4];
  this->m_vertCache[0].z = *(__m128 *)&v7[16 * (unsigned __int16)v5];
  y = this->m_vertCache[0].y;
  v10 = v8;
  v11 = _mm_shuffle_ps(this->m_vertCache[0].x, y, 68);
  v12 = _mm_shuffle_ps(this->m_vertCache[0].x, y, 238);
  v13 = _mm_shuffle_ps(this->m_vertCache[0].z, v10, 68);
  v14 = _mm_shuffle_ps(this->m_vertCache[0].z, v10, 238);
  this->m_vertCache[0].x = _mm_shuffle_ps(v11, v13, 136);
  this->m_vertCache[0].y = _mm_shuffle_ps(v11, v13, 221);
  this->m_vertCache[0].z = _mm_shuffle_ps(v12, v14, 136);
  FourVectors::RotateBy(this: this->m_vertCache, matrix: &this->m_ivpLocalToHLWorld);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B0C0
// Name: public: int CTraceIVP::SupportMapCached(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTraceIVP::SupportMapCached(CTraceIVP *this, const Vector *dir, Vector *pOut)
{
  int m_cacheCount; // edx
  __m128 v5; // xmm3
  __m128 v6; // xmm5
  __m128 v7; // xmm6
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 *p_z; // eax
  int v12; // edx
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  int result; // eax
  FourVectors *v21; // ecx
  float v22; // xmm1_4
  __m128 fourDir_20; // [esp+14h] [ebp-3Ch]

  m_cacheCount = this->m_cacheCount;
  v5 = g_IndexBase;
  v6 = _mm_shuffle_ps((__m128)LODWORD(dir->x), (__m128)LODWORD(dir->x), 0);
  v7 = _mm_shuffle_ps((__m128)LODWORD(dir->y), (__m128)LODWORD(dir->y), 0);
  v8 = _mm_shuffle_ps((__m128)LODWORD(dir->z), (__m128)LODWORD(dir->z), 0);
  fourDir_20 = v8;
  v9 = g_IndexBase;
  v10 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(this->m_vertCache[0].y, v7), _mm_mul_ps(this->m_vertCache[0].x, v6)),
          _mm_mul_ps(this->m_vertCache[0].z, v8));
  if ( m_cacheCount > 1 )
  {
    p_z = &this->m_vertCache[1].z;
    v12 = m_cacheCount - 1;
    while ( 1 )
    {
      v9 = _mm_add_ps(v9, Four_Fours);
      v13 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(p_z[-1], v7), _mm_mul_ps(p_z[-2], v6)), _mm_mul_ps(*p_z, v8));
      v14 = _mm_cmplt_ps(v10, v13);
      p_z += 3;
      --v12;
      v5 = _mm_or_ps(_mm_andnot_ps(v14, v5), _mm_and_ps(v14, v9));
      v10 = _mm_max_ps(v13, v10);
      if ( v12 == 0 )
        break;
      v8 = fourDir_20;
    }
  }
  v15 = _mm_shuffle_ps(v10, v10, 78);
  v16 = _mm_cmplt_ps(v10, v15);
  v17 = _mm_max_ps(v15, v10);
  v18 = _mm_cmplt_ps(v17, _mm_shuffle_ps(v17, v17, 57));
  v19 = _mm_or_ps(_mm_and_ps(_mm_shuffle_ps(v5, v5, 78), v16), _mm_andnot_ps(v16, v5));
  result = (__int64)COERCE_FLOAT(
                      COERCE_UNSIGNED_INT(_mm_shuffle_ps(v19, v19, 57).m128_f32[0]) & v18.m128_i32[0]
                    | COERCE_UNSIGNED_INT(_mm_andnot_ps(v18, v19).m128_f32[0]));
  v21 = &this->m_vertCache[result >> 2];
  v22 = v21->y.m128_f32[result & 3];
  v18.m128_i32[0] = v21->z.m128_i32[result & 3];
  LODWORD(pOut->x) = v21->x.m128_i32[result & 3];
  pOut->y = v22;
  LODWORD(pOut->z) = v18.m128_i32[0];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B240
// Name: public: virtual int CTraceIVP::SupportMap(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge CTraceIVP::SupportMap@<eax>(
        CTraceIVP *this@<ecx>,
        const IVP_U_Float_Point *a2@<ebp>,
        const Vector *dir,
        Vector *pOut)
{
  bool v5; // zf
  const leafmap_t *m_pLeafmap; // eax
  char *v8; // esi
  float y; // xmm0_4
  const leafmap_t *v10; // eax
  int v11; // ecx
  float *v12; // edx
  int v13; // eax
  float v14; // xmm0_4
  float *v15; // edx
  float *v16; // edx
  int v17; // esi
  char *v18; // ecx
  float v19; // xmm0_4
  int n_triangles; // edx
  CVisitHash *m_pVisitHash; // eax
  const leafmap_t *v22; // edx
  float hesse_val; // xmm2_4
  unsigned int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  unsigned int v28; // ecx
  const IVP_Compact_Ledge *v29; // edx
  CVisitHash *v30; // edi
  int v31; // edx
  float v32; // xmm1_4
  float v33; // xmm0_4
  int v34; // eax
  bool v35; // cc
  float v36; // xmm1_4
  int v37; // eax
  CVisitHash *v38; // ecx
  int v39; // esi
  int v40; // edx
  float x; // [esp-Ch] [ebp-4Ch] BYREF
  float v42; // [esp-8h] [ebp-48h]
  float v43; // [esp-4h] [ebp-44h]
  IVP_U_Float_Point mapdir; // [esp+0h] [ebp-40h] BYREF
  int v45; // [esp+1Ch] [ebp-24h]
  CTraceIVP *v46; // [esp+20h] [ebp-20h]
  int v47; // [esp+24h] [ebp-1Ch]
  int stopVert; // [esp+28h] [ebp-18h]
  int vertCount; // [esp+2Ch] [ebp-14h]
  int triCount; // [esp+30h] [ebp-10h]
  const IVP_U_Float_Point *pPoints; // [esp+34h] [ebp-Ch]
  int pointCount; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  pPoints = a2;
  pointCount = retaddr;
  v5 = this->m_cacheCount == 0;
  v46 = this;
  if ( !v5 )
    return CTraceIVP::SupportMapCached(this, dir, pOut);
  m_pLeafmap = this->m_pLeafmap;
  if ( m_pLeafmap != nullptr && (m_pLeafmap->flags & 2) != 0 )
  {
    v8 = (char *)this->m_pLedge + this->m_pLedge->c_point_offset;
    mapdir.k[1] = dir->x;
    LODWORD(mapdir.k[2]) = LODWORD(dir->z) ^ _mask__NegFloat_;
    y = dir->y;
    stopVert = (int)v8;
    mapdir.hesse_val = y;
    IVP_U_Matrix3::vimult3(
      this: &this->m_matrix,
      p_in: (IVP_U_Float_Point *)&mapdir.k[1],
      p_out: (IVP_U_Float_Point *)&x);
    v10 = this->m_pLeafmap;
    v11 = v10->startVert[0];
    vertCount = v10->vertCount;
    v12 = (float *)&v8[16 * v11];
    v13 = 1;
    v14 = (float)((float)(v12[1] * v42) + (float)(*v12 * x)) + (float)(v12[2] * v43);
    triCount = v11;
    if ( vertCount > 1 )
    {
      if ( vertCount - 1 >= 4 )
      {
        v46 = (CTraceIVP *)(vertCount - 3);
        v15 = v12 + 10;
        do
        {
          if ( (float)((float)((float)(*(v15 - 5) * v42) + (float)(*(v15 - 6) * x)) + (float)(*(v15 - 4) * v43)) > v14 )
          {
            v14 = (float)((float)(*(v15 - 5) * v42) + (float)(*(v15 - 6) * x)) + (float)(*(v15 - 4) * v43);
            triCount = v11 + v13;
          }
          if ( (float)((float)((float)(*(v15 - 1) * v42) + (float)(*(v15 - 2) * x)) + (float)(*v15 * v43)) > v14 )
          {
            v14 = (float)((float)(*(v15 - 1) * v42) + (float)(*(v15 - 2) * x)) + (float)(*v15 * v43);
            triCount = v13 + v11 + 1;
          }
          if ( (float)((float)((float)(v15[3] * v42) + (float)(v15[2] * x)) + (float)(v15[4] * v43)) > v14 )
          {
            v14 = (float)((float)(v15[3] * v42) + (float)(v15[2] * x)) + (float)(v15[4] * v43);
            triCount = v11 + v13 + 2;
          }
          if ( (float)((float)((float)(v15[7] * v42) + (float)(v15[6] * x)) + (float)(v15[8] * v43)) > v14 )
          {
            v14 = (float)((float)(v15[7] * v42) + (float)(v15[6] * x)) + (float)(v15[8] * v43);
            triCount = v11 + v13 + 3;
          }
          v13 += 4;
          v15 += 16;
        }
        while ( v13 < (int)v46 );
      }
      if ( v13 < vertCount )
      {
        v16 = (float *)(stopVert + 16 * (v13 + v11) + 8);
        do
        {
          if ( (float)((float)((float)(*(v16 - 1) * v42) + (float)(*(v16 - 2) * x)) + (float)(*v16 * v43)) > v14 )
          {
            v14 = (float)((float)(*(v16 - 1) * v42) + (float)(*(v16 - 2) * x)) + (float)(*v16 * v43);
            triCount = v13 + v11;
          }
          ++v13;
          v16 += 4;
        }
        while ( v13 < vertCount );
      }
    }
    v17 = triCount;
    VectorTransform(in1: (const float *)(stopVert + 16 * triCount), in2: &this->m_ivpLocalToHLWorld, out: &pOut->x);
  }
  else
  {
    v18 = (char *)this->m_pLedge + this->m_pLedge->c_point_offset;
    x = dir->x;
    LODWORD(v42) = LODWORD(dir->z) ^ _mask__NegFloat_;
    v19 = dir->y;
    vertCount = (int)v18;
    v43 = v19;
    IVP_U_Matrix3::vimult3(
      this: &this->m_matrix,
      p_in: (const IVP_U_Float_Point *)&x,
      p_out: (IVP_U_Float_Point *)&mapdir.k[1]);
    n_triangles = this->m_pLedge->n_triangles;
    m_pVisitHash = this->m_pVisitHash;
    v5 = m_pVisitHash->m_vertVisitID++ == 0xFFFF;
    v47 = n_triangles;
    if ( v5 )
      memset(dst: (unsigned __int8 *)m_pVisitHash, value: 0, count: 0x800u);
    v22 = this->m_pLeafmap;
    hesse_val = mapdir.hesse_val;
    v24 = 0;
    v25 = 0;
    if ( v22 != nullptr && (v22->flags & 1) != 0 )
    {
      if ( mapdir.k[2] >= 0.0 )
        v26 = 0;
      else
        v26 = 2;
      if ( mapdir.hesse_val >= 0.0 )
        v27 = 0;
      else
        v27 = 4;
      v28 = this->m_pLeafmap->startVert[(mapdir.k[1] < 0.0) + v26 + v27];
      v24 = v28 >> 2;
      v25 = v28 & 3;
    }
    v29 = &this->m_pLedge[v24 + 1];
    v17 = *(&v29->ledgetree_node_offset + v25);
    v30 = this->m_pVisitHash;
    v31 = (int)(&v29->___u1 + v25);
    v17 = (unsigned __int16)v17;
    v32 = (float)(*(float *)(vertCount + 16 * v17 + 4) * mapdir.k[2])
        + (float)(*(float *)(vertCount + 16 * v17) * mapdir.k[1]);
    v33 = *(float *)(vertCount + 16 * (unsigned __int16)v17 + 8);
    v34 = v17 & 0x1FF;
    v30->m_vertVisit[v34].visitID = v30->m_vertVisitID;
    v35 = v47 <= 0;
    stopVert = (unsigned __int16)v17;
    v36 = v32 + (float)(v33 * hesse_val);
    v30->m_vertVisit[v34].vertID = v17;
    triCount = 0;
    if ( !v35 )
    {
      do
      {
        v31 += *(int *)((char *)IVP_Compact_Edge::prev_table + (v31 & 0xC));
        v37 = (unsigned __int16)*(_DWORD *)v31;
        v45 = v37;
        do
        {
          v38 = v46->m_pVisitHash;
          if ( *(_DWORD *)&v38->m_vertVisit[v37 & 0x1FF] != __PAIR32__(v37 + HIWORD(v37), v38->m_vertVisitID) )
          {
            v39 = v37 & 0x1FF;
            v38->m_vertVisit[v39].visitID = v38->m_vertVisitID;
            v38->m_vertVisit[v39].vertID = v37 + HIWORD(v37);
            if ( (float)((float)((float)(*(float *)(vertCount + 16 * v37 + 4) * mapdir.k[2])
                               + (float)(*(float *)(vertCount + 16 * v37) * mapdir.k[1]))
                       + (float)(*(float *)(vertCount + 16 * v37 + 8) * mapdir.hesse_val)) > v36 )
            {
              v17 = v37;
              v36 = (float)((float)(*(float *)(vertCount + 16 * v37 + 4) * mapdir.k[2])
                          + (float)(*(float *)(vertCount + 16 * v37) * mapdir.k[1]))
                  + (float)(*(float *)(vertCount + 16 * v37 + 8) * mapdir.hesse_val);
              stopVert = v37;
              goto LABEL_40;
            }
          }
          v40 = v31 + 4 * ((2 * *(_DWORD *)v31) >> 17);
          v31 = *(int *)((char *)IVP_Compact_Edge::prev_table + (v40 & 0xC)) + v40;
          v37 = (unsigned __int16)*(_DWORD *)v31;
        }
        while ( v37 != v45 );
        v17 = stopVert;
        if ( v37 != stopVert )
          break;
LABEL_40:
        ++triCount;
      }
      while ( triCount < v47 );
    }
    VectorTransform(in1: (const float *)(vertCount + 16 * v17), in2: &v46->m_ivpLocalToHLWorld, out: &pOut->x);
  }
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x1002B6D0
// Name: public: virtual class Vector CTraceIVP::GetVertByIndex(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CTraceIVP::GetVertByIndex(CTraceIVP *this, Vector *result, int index)
{
  int v3; // edx
  FourVectors *v4; // ecx
  Vector out; // [esp+0h] [ebp-Ch] BYREF

  if ( this->m_cacheCount != 0 )
  {
    v3 = index & 3;
    v4 = &this->m_vertCache[index >> 2];
    result->x = v4->x.m128_f32[v3];
    result->y = v4->y.m128_f32[v3];
    result->z = v4->z.m128_f32[v3];
  }
  else
  {
    VectorTransform(
      in1: (const float *)((char *)&this->m_pLedge[index].c_point_offset + this->m_pLedge->c_point_offset),
      in2: &this->m_ivpLocalToHLWorld,
      out: &out.x);
    *result = out;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B750
// Name: public: CTraceAABB::CTraceAABB(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CTraceAABB *__thiscall CTraceAABB::CTraceAABB(
        CTraceAABB *this,
        const Vector *hlmins,
        const Vector *hlmaxs,
        bool isPoint)
{
  CTraceAABB *result; // eax
  float v5; // xmm0_4

  result = this;
  this->__vftable = (CTraceAABB_vtbl *)&CTraceAABB::`vftable';
  if ( isPoint )
  {
    *(_QWORD *)this->m_x = 0;
    *(_QWORD *)this->m_y = 0;
    *(_QWORD *)this->m_z = 0;
    this->m_empty = true;
    this->m_radius = 0.0;
  }
  else
  {
    this->m_x[0] = hlmaxs->x;
    this->m_x[1] = hlmins->x;
    this->m_y[0] = hlmaxs->y;
    this->m_y[1] = hlmins->y;
    this->m_z[0] = hlmaxs->z;
    this->m_z[1] = hlmins->z;
    v5 = fsqrt((float)((float)(hlmaxs->x * hlmaxs->x) + (float)(hlmaxs->y * hlmaxs->y)) + (float)(hlmaxs->z * hlmaxs->z));
    this->m_empty = false;
    this->m_radius = v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B820
// Name: public: virtual int CTraceAABB::SupportMap(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTraceAABB::SupportMap(CTraceAABB *this, const Vector *dir, Vector *pOut)
{
  float z; // eax
  int v5; // edx
  int v6; // esi

  if ( this->m_empty )
  {
    pOut->x = 0.0;
    pOut->y = 0.0;
    pOut->z = 0.0;
    return 0;
  }
  else
  {
    z = dir->z;
    v5 = LODWORD(dir->x) >> 31;
    v6 = LODWORD(dir->y) >> 31;
    pOut->x = this->m_x[v5];
    LODWORD(z) >>= 31;
    pOut->y = this->m_y[v6];
    pOut->z = this->m_z[LODWORD(z)];
    return v5 | (2 * (v6 | (2 * LODWORD(z))));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B880
// Name: public: virtual class Vector CTraceAABB::GetVertByIndex(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CTraceAABB::GetVertByIndex(CTraceAABB *this, Vector *result, int index)
{
  result->x = this->m_x[index & 1];
  result->y = this->m_y[(index >> 1) & 1];
  result->z = this->m_z[(index >> 2) & 1];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B8C0
// Name: public: void CTraceRay::Init(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceRay::Init(CTraceRay *this, const Vector *hlstart, const Vector *delta)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  double m_length; // st7

  this->m_start = *hlstart;
  v3 = hlstart->y + delta->y;
  v4 = hlstart->z + delta->z;
  this->m_end.x = hlstart->x + delta->x;
  this->m_end.y = v3;
  this->m_end.z = v4;
  this->m_delta = *delta;
  this->m_dir = *delta;
  v5 = fsqrt((float)((float)(delta->y * delta->y) + (float)(delta->x * delta->x)) + (float)(delta->z * delta->z));
  this->m_length = v5;
  this->m_ooBaseLength = 0.0;
  if ( v5 > 0.0 )
  {
    this->m_ooBaseLength = 1.0 / v5;
    this->m_dir.x = (float)(1.0 / v5) * this->m_dir.x;
    this->m_dir.y = this->m_dir.y * (float)(1.0 / v5);
    this->m_dir.z = this->m_dir.z * (float)(1.0 / v5);
  }
  m_length = this->m_length;
  this->m_bestDist = 0.0;
  this->m_baseLength = m_length;
}

//------------------------------------------------------------------------------
// Address: 0x1002B9B0
// Name: public: class CBaseTrace __near & CBaseTrace::operator=(class CBaseTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseTrace *__thiscall CBaseTrace::operator=(CBaseTrace *this, const CBaseTrace *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002BA40
// Name: public: virtual unsigned int CDefConvexInfo::GetContents(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDefConvexInfo::GetContents(CDefConvexInfo *this, int convexGameData)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BA50
// Name: public: void CTraceSolverSweptObject::InitOSRay(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTraceSolverSweptObject::InitOSRay(CTraceSolverSweptObject *this@<ecx>, int a2@<ebp>)
{
  CTraceRay *m_ray; // eax
  CTraceIVP *m_obstacleIVP; // ecx
  CTraceRay *v5; // eax
  CTraceIVP *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  IVP_U_Float_Point v11; // [esp-10h] [ebp-1Ch] BYREF
  int v12; // [esp+0h] [ebp-Ch]
  void *v13; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v12 = a2;
  v13 = retaddr;
  m_ray = this->m_ray;
  m_obstacleIVP = this->m_obstacleIVP;
  this->m_rayLengthOS = m_ray->m_length * g_PhysicsUnits.unitScaleMeters;
  v11.k[0] = m_ray->m_start.x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(v11.k[1]) = COERCE_UNSIGNED_INT(m_ray->m_start.z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v11.k[2] = m_ray->m_start.y * g_PhysicsUnits.unitScaleMeters;
  IVP_U_Matrix::vimult4(this: &m_obstacleIVP->m_matrix, p_in: &v11, p_out: &this->m_rayStartOS);
  v5 = this->m_ray;
  v11.k[0] = v5->m_delta.x * g_PhysicsUnits.unitScaleMeters;
  v6 = this->m_obstacleIVP;
  LODWORD(v11.k[1]) = COERCE_UNSIGNED_INT(v5->m_delta.z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v11.k[2] = v5->m_delta.y * g_PhysicsUnits.unitScaleMeters;
  IVP_U_Matrix3::vimult3(this: &v6->m_matrix, p_in: &v11, p_out: &this->m_rayDeltaOS);
  v7 = this->m_rayDeltaOS.k[1];
  v8 = this->m_rayDeltaOS.k[2];
  this->m_rayDirOS.k[0] = this->m_rayDeltaOS.k[0];
  this->m_rayDirOS.k[1] = v7;
  this->m_rayDirOS.k[2] = v8;
  IVP_U_Float_Point::fast_normize(this: &this->m_rayDirOS);
  v9 = (float)(this->m_rayDeltaOS.k[1] * 0.5) + this->m_rayStartOS.k[1];
  v10 = (float)(this->m_rayDeltaOS.k[2] * 0.5) + this->m_rayStartOS.k[2];
  this->m_rayCenterOS.k[0] = (float)(this->m_rayDeltaOS.k[0] * 0.5) + this->m_rayStartOS.k[0];
  this->m_rayCenterOS.k[1] = v9;
  this->m_rayCenterOS.k[2] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x1002BBB0
// Name: public: bool simplex_t::SolveVoronoiRegion4(struct simplexvert_t const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall simplex_t::SolveVoronoiRegion4(simplex_t *this, const simplexvert_t *newPoint, Vector *pOut)
{
  float z; // xmm7_4
  float x; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm2_4
  simplexvert_t *v10; // eax
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  int v14; // edx
  __int16 v16; // ax
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  __int16 v21; // dx
  __int16 v22; // cx
  __int16 v23; // cx
  float v24; // xmm5_4
  float y; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  __int16 v29; // cx
  __int16 v30; // cx
  float v31; // xmm3_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  __int16 v34; // cx
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  __int16 v38; // ax
  float v39; // xmm3_4
  float v40; // xmm5_4
  float v41; // xmm4_4
  __int16 v42; // cx
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  __int16 v46; // ax
  float v47; // xmm5_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  __int16 v52; // cx
  float v53; // xmm3_4
  float v54; // xmm5_4
  float v55; // xmm4_4
  float v56; // xmm6_4
  float v57; // xmm7_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  __int16 v64; // cx
  __int16 v65; // cx
  float v66; // xmm1_4
  float v67; // xmm2_4
  __int16 v68; // cx
  float ACxACD; // [esp+8h] [ebp-8Ch]
  float ACxACD_4; // [esp+Ch] [ebp-88h]
  float ACxACD_8; // [esp+10h] [ebp-84h]
  float ABxABC; // [esp+14h] [ebp-80h]
  float ABxABC_4; // [esp+18h] [ebp-7Ch]
  float ABxABC_8; // [esp+1Ch] [ebp-78h]
  float ADBxAB; // [esp+20h] [ebp-74h]
  float ADBxAB_4; // [esp+24h] [ebp-70h]
  float ADBxAB_8; // [esp+28h] [ebp-6Ch]
  float ABCxAC; // [esp+2Ch] [ebp-68h]
  float ABCxAC_4; // [esp+30h] [ebp-64h]
  float ABCxAC_8; // [esp+34h] [ebp-60h]
  float ADxADB; // [esp+38h] [ebp-5Ch]
  float ADxADB_4; // [esp+3Ch] [ebp-58h]
  float ADxADB_8; // [esp+40h] [ebp-54h]
  float ACDxAD; // [esp+44h] [ebp-50h]
  float ACDxAD_4; // [esp+48h] [ebp-4Ch]
  float ACDxAD_8; // [esp+4Ch] [ebp-48h]
  float AC_4; // [esp+54h] [ebp-40h]
  float AC_8; // [esp+58h] [ebp-3Ch]
  float ADB_8; // [esp+64h] [ebp-30h]
  float v90; // [esp+68h] [ebp-2Ch]
  float ACD; // [esp+6Ch] [ebp-28h]
  float ACD_4; // [esp+70h] [ebp-24h]
  float ACD_8; // [esp+74h] [ebp-20h]
  float ABC; // [esp+78h] [ebp-1Ch]
  float ABC_8; // [esp+80h] [ebp-14h]
  float AD; // [esp+84h] [ebp-10h]
  float AD_4; // [esp+88h] [ebp-Ch]
  float AD_8; // [esp+8Ch] [ebp-8h]
  float newPointb; // [esp+9Ch] [ebp+8h]
  float newPointa; // [esp+9Ch] [ebp+8h]

  z = newPoint->position.z;
  newPointb = newPoint->position.y;
  x = newPoint->position.x;
  v7 = this->verts[0].position.y - newPointb;
  v8 = this->verts[1].position.y - newPointb;
  AC_8 = this->verts[1].position.z - z;
  AD = this->verts[2].position.x - newPoint->position.x;
  AD_4 = this->verts[2].position.y - newPointb;
  AD_8 = this->verts[2].position.z - z;
  v9 = this->verts[0].position.z - z;
  v10 = &this->verts[2];
  v11 = this->verts[1].position.x - newPoint->position.x;
  ABC = (float)(AC_8 * v7) - (float)(v9 * v8);
  v12 = this->verts[0].position.x - newPoint->position.x;
  ABC_8 = (float)(v12 * v8) - (float)(v11 * v7);
  ACD = (float)(AD_8 * v8) - (float)(AD_4 * AC_8);
  ACD_4 = (float)(AC_8 * AD) - (float)(AD_8 * v11);
  ACD_8 = (float)(AD_4 * v11) - (float)(AD * v8);
  AC_4 = v8;
  ADB_8 = (float)(AD * v7) - (float)(AD_4 * v12);
  ABCxAC = (float)((float)((float)(v11 * v9) - (float)(AC_8 * v12)) * AC_8) - (float)(ABC_8 * v8);
  ABCxAC_4 = (float)(ABC_8 * v11) - (float)(AC_8 * ABC);
  ABCxAC_8 = (float)(ABC * v8) - (float)((float)((float)(v11 * v9) - (float)(AC_8 * v12)) * v11);
  ABxABC = (float)(ABC_8 * v7) - (float)((float)((float)(v11 * v9) - (float)(AC_8 * v12)) * v9);
  ABxABC_4 = (float)(ABC * v9) - (float)(ABC_8 * v12);
  ABxABC_8 = (float)((float)((float)(v11 * v9) - (float)(AC_8 * v12)) * v12) - (float)(ABC * v7);
  ACDxAD = (float)(ACD_4 * AD_8) - (float)(ACD_8 * AD_4);
  ACDxAD_4 = (float)(ACD_8 * AD) - (float)(AD_8 * ACD);
  ACDxAD_8 = (float)(AD_4 * ACD) - (float)(ACD_4 * AD);
  ACxACD = (float)(ACD_8 * v8) - (float)(ACD_4 * AC_8);
  ACxACD_4 = (float)(AC_8 * ACD) - (float)(ACD_8 * v11);
  ACxACD_8 = (float)(ACD_4 * v11) - (float)(ACD * v8);
  ADBxAB = (float)((float)((float)(AD_8 * v12) - (float)(AD * v9)) * v9) - (float)(ADB_8 * v7);
  v13 = (float)(AD_4 * v9) - (float)(AD_8 * v7);
  ADBxAB_4 = (float)(ADB_8 * v12) - (float)(v13 * v9);
  ADBxAB_8 = (float)(v13 * v7) - (float)((float)((float)(AD_8 * v12) - (float)(AD * v9)) * v12);
  ADxADB = (float)(ADB_8 * AD_4) - (float)((float)((float)(AD_8 * v12) - (float)(AD * v9)) * AD_8);
  ADxADB_4 = (float)(AD_8 * v13) - (float)(ADB_8 * AD);
  ADxADB_8 = (float)((float)((float)(AD_8 * v12) - (float)(AD * v9)) * AD) - (float)(AD_4 * v13);
  v14 = (float)((float)((float)(newPoint->position.x * ABC)
                      + (float)(newPointb * (float)((float)(v11 * v9) - (float)(AC_8 * v12))))
              + (float)(z * ABC_8)) < 0.0;
  v90 = newPoint->position.z;
  newPointa = newPoint->position.y;
  if ( (float)((float)((float)(ACD_4 * newPointa) + (float)(newPoint->position.x * ACD)) + (float)(ACD_8 * v90)) < 0.0 )
    v14 |= 2u;
  if ( (float)((float)((float)((float)((float)(AD_8 * v12) - (float)(AD * v9)) * newPointa)
                     + (float)(x * (float)((float)(AD_4 * v9) - (float)(AD_8 * v7))))
             + (float)(ADB_8 * v90)) < 0.0 )
    v14 |= 4u;
  switch ( v14 )
  {
    case 0:
      simplexvert_t::operator=(this: &this->verts[3], __that: newPoint);
      this->vertCount = 4;
      return 1;
    case 1:
      return simplex_t::SolveVoronoiRegion3(this, newPoint, pOut);
    case 2:
      simplexvert_t::operator=(this: this->verts, __that: v10);
      return simplex_t::SolveVoronoiRegion3(this, newPoint, pOut);
    case 3:
      if ( (float)((float)((float)(ABCxAC_4 * newPointa) + (float)(x * ABCxAC)) + (float)(ABCxAC_8 * v90)) >= 0.0 )
      {
        if ( (float)((float)((float)(ABxABC_4 * newPointa) + (float)(x * ABxABC)) + (float)(ABxABC_8 * v90)) >= 0.0 )
          goto LABEL_24;
        if ( (float)((float)((float)(x * v12) + (float)(newPointa * v7)) + (float)(v90 * v9)) >= 0.0 )
          goto LABEL_23;
        this->vertCount = 2;
        v30 = *((_WORD *)&this->verts[1] + 6);
        this->verts[1].position.x = newPoint->position.x;
        this->verts[1].position.y = newPoint->position.y;
        this->verts[1].position.z = newPoint->position.z;
        *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ v30) & 0x7FFF;
        *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                        ^ (*((_WORD *)&this->verts[1] + 6)
                                         ^ *((_WORD *)newPoint + 6))
                                        & 0x7FFF;
        this->verts[1].obstacleIndex = newPoint->obstacleIndex;
        v31 = (float)(newPoint->position.z * v7) - (float)(newPoint->position.y * v9);
        v32 = (float)(newPoint->position.y * v12) - (float)(newPoint->position.x * v7);
        v33 = (float)(newPoint->position.x * v9) - (float)(newPoint->position.z * v12);
        pOut->x = (float)(v33 * v9) - (float)(v32 * v7);
        pOut->y = (float)(v32 * v12) - (float)(v31 * v9);
        pOut->z = (float)(v31 * v7) - (float)(v33 * v12);
        return 0;
      }
      else if ( (float)((float)((float)(ACxACD_4 * newPointa) + (float)(x * ACxACD)) + (float)(ACxACD_8 * v90)) >= 0.0 )
      {
        if ( (float)((float)((float)(ACDxAD_4 * newPointa) + (float)(x * ACDxAD)) + (float)(ACDxAD_8 * v90)) >= 0.0 )
        {
          this->vertCount = 3;
          v29 = *((_WORD *)this->verts + 6);
          this->verts[0].position.x = newPoint->position.x;
          this->verts[0].position.y = newPoint->position.y;
          this->verts[0].position.z = newPoint->position.z;
          *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v29) & 0x7FFF;
          *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6)
                                      ^ (*((_WORD *)this->verts + 6)
                                       ^ *((_WORD *)newPoint + 6))
                                      & 0x7FFF;
          this->verts[0].obstacleIndex = newPoint->obstacleIndex;
          pOut->x = -ACD;
          pOut->y = -ACD_4;
          pOut->z = -ACD_8;
        }
        else
        {
          simplexvert_t::operator=(this: this->verts, __that: v10);
          this->vertCount = 2;
          v23 = *((_WORD *)&this->verts[1] + 6);
          this->verts[1].position.x = newPoint->position.x;
          this->verts[1].position.y = newPoint->position.y;
          this->verts[1].position.z = newPoint->position.z;
          *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ v23) & 0x7FFF;
          *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                          ^ (*((_WORD *)&this->verts[1] + 6)
                                           ^ *((_WORD *)newPoint + 6))
                                          & 0x7FFF;
          this->verts[1].obstacleIndex = newPoint->obstacleIndex;
          v24 = newPoint->position.z;
          y = newPoint->position.y;
          v26 = (float)(AD_4 * v24) - (float)(AD_8 * y);
          v27 = (float)(newPoint->position.x * AD_8) - (float)(v24 * AD);
          v28 = (float)(y * AD) - (float)(newPoint->position.x * AD_4);
          pOut->x = (float)(v27 * AD_8) - (float)(v28 * AD_4);
          pOut->y = (float)(v28 * AD) - (float)(AD_8 * v26);
          pOut->z = (float)(AD_4 * v26) - (float)(v27 * AD);
        }
        return 0;
      }
      else
      {
        if ( (float)((float)((float)(x * v11) + (float)(newPointa * AC_4)) + (float)(AC_8 * v90)) >= 0.0 )
          goto LABEL_14;
        this->vertCount = 2;
        v16 = *((_WORD *)this->verts + 6);
        this->verts[0].position = newPoint->position;
        *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v16) & 0x7FFF;
        *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6)
                                    ^ (*((_WORD *)this->verts + 6)
                                     ^ *((_WORD *)newPoint + 6))
                                    & 0x7FFF;
        this->verts[0].obstacleIndex = newPoint->obstacleIndex;
        v17 = newPoint->position.y;
        v18 = (float)(newPoint->position.z * AC_4) - (float)(AC_8 * v17);
        v19 = (float)(v17 * v11) - (float)(newPoint->position.x * AC_4);
        v20 = (float)(newPoint->position.x * AC_8) - (float)(newPoint->position.z * v11);
        pOut->x = (float)(v20 * AC_8) - (float)(v19 * AC_4);
        pOut->y = (float)(v19 * v11) - (float)(v18 * AC_8);
        pOut->z = (float)(v18 * AC_4) - (float)(v20 * v11);
        return 0;
      }
    case 4:
      simplexvert_t::operator=(this: &this->verts[1], __that: v10);
      return simplex_t::SolveVoronoiRegion3(this, newPoint, pOut);
    case 5:
      if ( (float)((float)((float)(x * ADBxAB) + (float)(ADBxAB_4 * newPointa)) + (float)(ADBxAB_8 * v90)) < 0.0 )
      {
        if ( (float)((float)((float)(ABxABC_4 * newPointa) + (float)(x * ABxABC)) + (float)(ABxABC_8 * v90)) < 0.0 )
        {
          if ( (float)((float)((float)(x * v12) + (float)(newPointa * v7)) + (float)(v90 * v9)) < 0.0 )
          {
            this->vertCount = 2;
            v38 = *((_WORD *)&this->verts[1] + 6);
            this->verts[1].position = newPoint->position;
            *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ v38) & 0x7FFF;
            *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                            ^ (*((_WORD *)&this->verts[1] + 6)
                                             ^ *((_WORD *)newPoint + 6))
                                            & 0x7FFF;
            this->verts[1].obstacleIndex = newPoint->obstacleIndex;
            v39 = (float)(newPoint->position.z * v7) - (float)(newPoint->position.y * v9);
            v40 = (float)(newPoint->position.y * v12) - (float)(newPoint->position.x * v7);
            v41 = (float)(newPoint->position.x * v9) - (float)(newPoint->position.z * v12);
            pOut->x = (float)(v41 * v9) - (float)(v40 * v7);
            pOut->y = (float)(v40 * v12) - (float)(v39 * v9);
            pOut->z = (float)(v39 * v7) - (float)(v41 * v12);
            return 0;
          }
LABEL_14:
          v21 = *((_WORD *)this->verts + 6);
          this->vertCount = 1;
          this->verts[0].position = newPoint->position;
          *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v21) & 0x7FFF;
          v22 = *((_WORD *)newPoint + 6);
          goto LABEL_15;
        }
        if ( (float)((float)((float)(ABCxAC_4 * newPointa) + (float)(x * ABCxAC)) + (float)(ABCxAC_8 * v90)) < 0.0 )
        {
          this->vertCount = 2;
          v42 = *((_WORD *)this->verts + 6);
          this->verts[0].position.x = newPoint->position.x;
          this->verts[0].position.y = newPoint->position.y;
          this->verts[0].position.z = newPoint->position.z;
          *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v42) & 0x7FFF;
          *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6)
                                      ^ (*((_WORD *)this->verts + 6)
                                       ^ *((_WORD *)newPoint + 6))
                                      & 0x7FFF;
          this->verts[0].obstacleIndex = newPoint->obstacleIndex;
          v43 = (float)(newPoint->position.z * AC_4) - (float)(newPoint->position.y * AC_8);
          v44 = (float)(newPoint->position.y * v11) - (float)(newPoint->position.x * AC_4);
          v45 = (float)(newPoint->position.x * AC_8) - (float)(newPoint->position.z * v11);
          pOut->x = (float)(v45 * AC_8) - (float)(v44 * AC_4);
          pOut->y = (float)(v44 * v11) - (float)(v43 * AC_8);
          pOut->z = (float)(v43 * AC_4) - (float)(v45 * v11);
          return 0;
        }
LABEL_24:
        this->vertCount = 3;
        v10->position.x = newPoint->position.x;
        v35 = ABC;
        v36 = (float)(v11 * v9) - (float)(AC_8 * v12);
        this->verts[2].position.y = newPoint->position.y;
        v37 = ABC_8;
        this->verts[2].position.z = newPoint->position.z;
        *((_WORD *)&this->verts[2] + 6) ^= (*((_WORD *)newPoint + 6) ^ *((_WORD *)&this->verts[2] + 6)) & 0x7FFF;
        *((_WORD *)&this->verts[2] + 6) = *((_WORD *)newPoint + 6)
                                        ^ (*((_WORD *)&this->verts[2] + 6)
                                         ^ *((_WORD *)newPoint + 6))
                                        & 0x7FFF;
        this->verts[2].obstacleIndex = newPoint->obstacleIndex;
LABEL_25:
        pOut->x = -v35;
        pOut->y = -v36;
        pOut->z = -v37;
        return 0;
      }
      if ( (float)((float)((float)(x * ADxADB) + (float)(ADxADB_4 * newPointa)) + (float)(ADxADB_8 * v90)) >= 0.0 )
      {
LABEL_36:
        this->vertCount = 3;
        this->verts[1].position = newPoint->position;
        v35 = (float)(AD_4 * v9) - (float)(AD_8 * v7);
        v36 = (float)(AD_8 * v12) - (float)(AD * v9);
        v37 = ADB_8;
        *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ *((_WORD *)&this->verts[1] + 6)) & 0x7FFF;
        *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                        ^ (*((_WORD *)&this->verts[1] + 6)
                                         ^ *((_WORD *)newPoint + 6))
                                        & 0x7FFF;
        this->verts[1].obstacleIndex = newPoint->obstacleIndex;
        goto LABEL_25;
      }
      if ( (float)((float)((float)(AD_4 * newPointa) + (float)(x * AD)) + (float)(AD_8 * v90)) >= 0.0 )
        goto LABEL_14;
      simplexvert_t::operator=(this: this->verts, __that: v10);
      this->vertCount = 2;
      v46 = *((_WORD *)&this->verts[1] + 6);
      this->verts[1].position.x = newPoint->position.x;
      this->verts[1].position.y = newPoint->position.y;
      this->verts[1].position.z = newPoint->position.z;
      *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ v46) & 0x7FFF;
      *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                      ^ (*((_WORD *)&this->verts[1] + 6)
                                       ^ *((_WORD *)newPoint + 6))
                                      & 0x7FFF;
      this->verts[1].obstacleIndex = newPoint->obstacleIndex;
LABEL_35:
      v47 = newPoint->position.z;
      v48 = newPoint->position.y;
      v49 = (float)(AD_4 * v47) - (float)(AD_8 * v48);
      v50 = (float)(newPoint->position.x * AD_8) - (float)(v47 * AD);
      v51 = (float)(v48 * AD) - (float)(newPoint->position.x * AD_4);
      pOut->x = (float)(v50 * AD_8) - (float)(v51 * AD_4);
      pOut->y = (float)(v51 * AD) - (float)(AD_8 * v49);
      pOut->z = (float)(AD_4 * v49) - (float)(v50 * AD);
      return 0;
    case 6:
      if ( (float)((float)((float)(ACDxAD_4 * newPointa) + (float)(x * ACDxAD)) + (float)(ACDxAD_8 * v90)) >= 0.0 )
      {
        if ( (float)((float)((float)(ACxACD_4 * newPointa) + (float)(x * ACxACD)) + (float)(ACxACD_8 * v90)) >= 0.0 )
        {
          this->vertCount = 3;
          v64 = *((_WORD *)this->verts + 6);
          this->verts[0].position.x = newPoint->position.x;
          v35 = ACD;
          v36 = (float)(AC_8 * AD) - (float)(AD_8 * v11);
          this->verts[0].position.y = newPoint->position.y;
          v37 = ACD_8;
          this->verts[0].position.z = newPoint->position.z;
          *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v64) & 0x7FFF;
          *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6)
                                      ^ (*((_WORD *)this->verts + 6)
                                       ^ *((_WORD *)newPoint + 6))
                                      & 0x7FFF;
          this->verts[0].obstacleIndex = newPoint->obstacleIndex;
          goto LABEL_25;
        }
        v56 = AC_4;
        v57 = this->verts[1].position.z - z;
        if ( (float)((float)((float)(x * v11) + (float)(newPointa * AC_4)) + (float)(AC_8 * v90)) >= 0.0 )
          goto LABEL_23;
LABEL_46:
        this->vertCount = 2;
        this->verts[0].position = newPoint->position;
        *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ *((_WORD *)this->verts + 6)) & 0x7FFF;
        *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6)
                                    ^ (*((_WORD *)this->verts + 6)
                                     ^ *((_WORD *)newPoint + 6))
                                    & 0x7FFF;
        this->verts[0].obstacleIndex = newPoint->obstacleIndex;
        v58 = (float)(newPoint->position.z * v56) - (float)(newPoint->position.y * v57);
        v59 = (float)(newPoint->position.x * v57) - (float)(newPoint->position.z * v11);
        v60 = (float)(newPoint->position.y * v11) - (float)(newPoint->position.x * v56);
        v61 = (float)(v59 * v57) - (float)(v60 * v56);
        v62 = v60 * v11;
        v63 = v59 * v11;
LABEL_47:
        pOut->x = v61;
        pOut->y = v62 - (float)(v58 * v57);
        pOut->z = (float)(v58 * v56) - v63;
        return 0;
      }
      else
      {
        if ( (float)((float)((float)(x * ADxADB) + (float)(ADxADB_4 * newPointa)) + (float)(ADxADB_8 * v90)) < 0.0 )
        {
          if ( (float)((float)((float)(AD_4 * newPointa) + (float)(x * AD)) + (float)(AD_8 * v90)) < 0.0 )
          {
            simplexvert_t::operator=(this: this->verts, __that: v10);
            this->vertCount = 2;
            v52 = *((_WORD *)&this->verts[1] + 6);
            this->verts[1].position.x = newPoint->position.x;
            this->verts[1].position.y = newPoint->position.y;
            this->verts[1].position.z = newPoint->position.z;
            *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ v52) & 0x7FFF;
            *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                            ^ (*((_WORD *)&this->verts[1] + 6)
                                             ^ *((_WORD *)newPoint + 6))
                                            & 0x7FFF;
            this->verts[1].obstacleIndex = newPoint->obstacleIndex;
            goto LABEL_35;
          }
LABEL_23:
          v34 = *((_WORD *)this->verts + 6);
          this->vertCount = 1;
          this->verts[0].position.x = newPoint->position.x;
          this->verts[0].position.y = newPoint->position.y;
          this->verts[0].position.z = newPoint->position.z;
          *((_WORD *)this->verts + 6) ^= (*((_WORD *)newPoint + 6) ^ v34) & 0x7FFF;
          v22 = *((_WORD *)newPoint + 6);
LABEL_15:
          *((_WORD *)this->verts + 6) = *((_WORD *)newPoint + 6) ^ (*((_WORD *)this->verts + 6) ^ v22) & 0x7FFF;
          this->verts[0].obstacleIndex = newPoint->obstacleIndex;
          *pOut = newPoint->position;
          return 0;
        }
        if ( (float)((float)((float)(x * ADBxAB) + (float)(ADBxAB_4 * newPointa)) + (float)(ADBxAB_8 * v90)) >= 0.0 )
          goto LABEL_36;
LABEL_43:
        this->vertCount = 2;
        this->verts[1].position = newPoint->position;
        *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ *((_WORD *)&this->verts[1] + 6)) & 0x7FFF;
        *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                        ^ (*((_WORD *)&this->verts[1] + 6)
                                         ^ *((_WORD *)newPoint + 6))
                                        & 0x7FFF;
        this->verts[1].obstacleIndex = newPoint->obstacleIndex;
        v53 = (float)(newPoint->position.z * v7) - (float)(newPoint->position.y * v9);
        v54 = (float)(newPoint->position.y * v12) - (float)(newPoint->position.x * v7);
        v55 = (float)(newPoint->position.x * v9) - (float)(newPoint->position.z * v12);
        pOut->x = (float)(v55 * v9) - (float)(v54 * v7);
        pOut->y = (float)(v54 * v12) - (float)(v53 * v9);
        pOut->z = (float)(v53 * v7) - (float)(v55 * v12);
        return 0;
      }
    case 7:
      if ( (float)((float)((float)(x * v12) + (float)(newPointa * v7)) + (float)(v90 * v9)) < 0.0 )
        goto LABEL_43;
      v56 = AC_4;
      v57 = this->verts[1].position.z - z;
      if ( (float)((float)((float)(x * v11) + (float)(newPointa * AC_4)) + (float)(AC_8 * v90)) < 0.0 )
        goto LABEL_46;
      if ( (float)((float)((float)(AD_4 * newPointa) + (float)(x * AD)) + (float)(AD_8 * v90)) >= 0.0 )
        goto LABEL_23;
      simplexvert_t::operator=(this: this->verts, __that: v10);
      this->vertCount = 2;
      v65 = *((_WORD *)&this->verts[1] + 6);
      this->verts[1].position.x = newPoint->position.x;
      v56 = AD_4;
      this->verts[1].position.y = newPoint->position.y;
      v57 = AD_8;
      this->verts[1].position.z = newPoint->position.z;
      *((_WORD *)&this->verts[1] + 6) ^= (*((_WORD *)newPoint + 6) ^ v65) & 0x7FFF;
      *((_WORD *)&this->verts[1] + 6) = *((_WORD *)newPoint + 6)
                                      ^ (*((_WORD *)&this->verts[1] + 6)
                                       ^ *((_WORD *)newPoint + 6))
                                      & 0x7FFF;
      this->verts[1].obstacleIndex = newPoint->obstacleIndex;
      v58 = (float)(newPoint->position.z * AD_4) - (float)(newPoint->position.y * AD_8);
      v66 = (float)(newPoint->position.x * AD_8) - (float)(newPoint->position.z * AD);
      v67 = (float)(newPoint->position.y * AD) - (float)(newPoint->position.x * AD_4);
      v61 = (float)(v66 * AD_8) - (float)(v67 * AD_4);
      v62 = v67 * AD;
      v63 = v66 * AD;
      goto LABEL_47;
    default:
      v68 = *((_WORD *)&this->verts[3] + 6);
      this->verts[3].position.x = x;
      this->verts[3].position.y = newPoint->position.y;
      this->verts[3].position.z = newPoint->position.z;
      *((_WORD *)&this->verts[3] + 6) ^= (*((_WORD *)newPoint + 6) ^ v68) & 0x7FFF;
      *((_WORD *)&this->verts[3] + 6) = *((_WORD *)newPoint + 6)
                                      ^ (*((_WORD *)&this->verts[3] + 6)
                                       ^ *((_WORD *)newPoint + 6))
                                      & 0x7FFF;
      this->verts[3].obstacleIndex = newPoint->obstacleIndex;
      this->vertCount = 4;
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CEF0
// Name: public: bool CTraceSolver::SolveMeshIntersection(struct simplex_t __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CTraceSolver::SolveMeshIntersection@<al>(
        CTraceSolver *this@<ecx>,
        Vector *p_tmp@<ebx>,
        simplex_t *simplex,
        float *pflDist)
{
  int v7; // ebx
  __int16 v8; // ax
  CTraceRay *m_ray; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  __int16 v13; // ax
  ITraceObject *m_obstacle; // ecx
  unsigned __int16 v15; // ax
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  int vertCount; // eax
  __int16 v21; // cx
  char *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  CTraceRay *v29; // edi
  float v30; // xmm3_4
  float v31; // xmm6_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm7_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm5_4
  float v40; // xmm2_4
  simplexvert_t vert; // [esp+8h] [ebp-44h] BYREF
  Vector v43; // [esp+18h] [ebp-34h] BYREF
  Vector BD; // [esp+24h] [ebp-28h] BYREF
  Vector tmp; // [esp+30h] [ebp-1Ch] BYREF
  Vector v; // [esp+3Ch] [ebp-10h] BYREF
  float v47; // [esp+48h] [ebp-4h]
  simplex_t *simplexa; // [esp+54h] [ebp+8h]

  if ( simplex->vertCount < 4 )
    return 0;
  simplex_t::ClipRayToTetrahedronBase(this: simplex, result: &v, dir: &this->m_ray->m_dir);
  v7 = 0;
  while ( 1 )
  {
    VectorNormalize(vec: &v);
    v8 = ((int (__thiscall *)(ITraceObject *, Vector *, simplexvert_t *, Vector *))this->m_sweepObject->SupportMap)(
           a1: this->m_sweepObject,
           a2: &v,
           a3: &vert,
           a4: p_tmp);
    *((_WORD *)&vert + 6) ^= (*((_WORD *)&vert + 6) ^ v8) & 0x7FFF;
    m_ray = this->m_ray;
    if ( (float)((float)((float)(m_ray->m_delta.y * v.y) + (float)(m_ray->m_delta.x * v.x))
               + (float)(m_ray->m_delta.z * v.z)) <= 0.0 )
    {
      x = m_ray->m_start.x;
      tmp.x = m_ray->m_start.x;
      y = m_ray->m_start.y;
      tmp.y = y;
      z = m_ray->m_start.z;
      v13 = 0;
    }
    else
    {
      x = m_ray->m_end.x;
      tmp.x = x;
      y = m_ray->m_end.y;
      tmp.y = y;
      z = m_ray->m_end.z;
      v13 = 1;
    }
    vert.position.y = vert.position.y + y;
    m_obstacle = this->m_obstacle;
    *((_WORD *)&vert + 6) = *((_WORD *)&vert + 6) & 0x7FFF | (v13 << 15);
    vert.position.z = vert.position.z + z;
    p_tmp = &tmp;
    tmp.z = z;
    vert.position.x = vert.position.x + x;
    BD.x = -v.x;
    BD.y = -v.y;
    BD.z = -v.z;
    v15 = ((int (__thiscall *)(ITraceObject *, Vector *))m_obstacle->SupportMap)(a1: m_obstacle, a2: &BD);
    v16 = vert.position.x - tmp.x;
    v17 = simplex->verts[0].position.x;
    vert.position.y = vert.position.y - tmp.y;
    vert.position.z = vert.position.z - tmp.z;
    v18 = (float)((float)(vert.position.y * v.y) + (float)((float)(vert.position.x - tmp.x) * v.x))
        + (float)(vert.position.z * v.z);
    v19 = (float)((float)((float)(simplex->verts[0].position.y * v.y) + (float)(v17 * v.x))
                + (float)(simplex->verts[0].position.z * v.z))
        + g_PhysicsUnits.collisionSweepIncrementalEpsilon;
    vert.obstacleIndex = v15;
    vert.position.x = vert.position.x - tmp.x;
    if ( v19 >= v18 )
      break;
    vertCount = simplex->vertCount;
    v21 = *((_WORD *)&simplex->verts[vertCount] + 6);
    v22 = (char *)simplex + vertCount * 16;
    *(float *)v22 = v16;
    *((_DWORD *)v22 + 1) = LODWORD(vert.position.y);
    *((_DWORD *)v22 + 2) = LODWORD(vert.position.z);
    *((_WORD *)v22 + 6) ^= (*((_WORD *)&vert + 6) ^ v21) & 0x7FFF;
    *((_WORD *)v22 + 6) = *((_WORD *)&vert + 6) ^ (*((_WORD *)&vert + 6) ^ *((_WORD *)v22 + 6)) & 0x7FFF;
    *((_WORD *)v22 + 7) = vert.obstacleIndex;
    ++simplex->vertCount;
    v = *simplex_t::ClipRayToTetrahedron(this: simplex, result: &v43, dir: &this->m_ray->m_dir);
    if ( ++v7 >= 100 )
      return 0;
  }
  v23 = simplex->verts[0].position.x;
  v24 = simplex->verts[0].position.z;
  v25 = simplex->verts[1].position.x;
  v26 = simplex->verts[0].position.y;
  v27 = simplex->verts[1].position.z;
  v28 = simplex->verts[1].position.y;
  v29 = this->m_ray;
  BD.x = simplex->verts[2].position.x - simplex->verts[0].position.x;
  v30 = simplex->verts[2].position.z - v24;
  v31 = v25 - v23;
  *(float *)&simplexa = v23;
  v32 = simplex->verts[2].position.y;
  v33 = v27 - v24;
  v34 = v28 - v26;
  v47 = v24;
  v35 = v32 - v26;
  v36 = v35 * v33;
  v37 = (float)(v33 * BD.x) - (float)(v30 * v31);
  v38 = (float)(v35 * v31) - (float)(v34 * BD.x);
  v39 = (float)(v30 * v34) - v36;
  v40 = (float)((float)(v29->m_dir.y * v37) + (float)(v29->m_dir.x * v39)) + (float)(v29->m_dir.z * v38);
  if ( v40 <= 0.0 )
    *pflDist = 1.0e24;
  else
    *pflDist = (float)((float)((float)(v26 * v37) + (float)(*(float *)&simplexa * v39)) + (float)(v47 * v38)) / v40;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002D260
// Name: public: CTSPool<class CVisitHash>::~CTSPool<class CVisitHash>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<CVisitHash>::~CTSPool<CVisitHash>(CTSPool<CVisitHash> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
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
        goto LABEL_4;
    }
    free(data: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D2C0
// Name: public: virtual class Vector CTraceCone::GetVertByIndex(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CTraceCone::GetVertByIndex(CTraceCone *this, Vector *result, int index)
{
  __int64 v3; // xmm0_8
  float z; // ecx

  v3 = *(_QWORD *)&this->m_cone.origin.x;
  z = this->m_cone.origin.z;
  *(_QWORD *)&result->x = v3;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D2E0
// Name: public: virtual float CTraceCone::Radius(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTraceCone::Radius(CTraceCone *this)
{
  return this->m_radius + this->m_cone.h;
}

//------------------------------------------------------------------------------
// Address: 0x1002D2F0
// Name: public: virtual int CTraceCone::SupportMap(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTraceCone::SupportMap(CTraceCone *this, const Vector *dir, Vector *pOut)
{
  float z; // eax
  float y; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float m_radius; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector unitDir; // [esp+0h] [ebp-Ch] BYREF

  z = dir->z;
  *(_QWORD *)&unitDir.x = *(_QWORD *)&dir->x;
  unitDir.z = z;
  VectorNormalize(vec: &unitDir);
  y = this->m_cone.normal.y;
  v6 = this->m_cone.normal.z;
  v7 = (float)((float)(y * unitDir.y) + (float)(this->m_cone.normal.x * unitDir.x)) + (float)(v6 * unitDir.z);
  if ( v7 <= COERCE_FLOAT(LODWORD(this->m_sinTheta) ^ _mask__NegFloat_) )
  {
    *pOut = this->m_cone.origin;
    return 0;
  }
  else
  {
    unitDir.x = unitDir.x - (float)(this->m_cone.normal.x * v7);
    unitDir.y = unitDir.y - (float)(y * v7);
    unitDir.z = unitDir.z - (float)(v6 * v7);
    if ( VectorNormalize(vec: &unitDir) <= 0.000099999997 )
    {
      *pOut = this->m_centerBase;
    }
    else
    {
      m_radius = this->m_radius;
      v9 = this->m_centerBase.y + (float)(unitDir.y * m_radius);
      v10 = this->m_centerBase.z + (float)(unitDir.z * m_radius);
      pOut->x = this->m_centerBase.x + (float)(m_radius * unitDir.x);
      pOut->y = v9;
      pOut->z = v10;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D440
// Name: class CVisitHash __near * AllocVisitHash(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AllocVisitHash()
{
  TSLNodeBase_t *v0; // eax
  void *v1; // esi

  v0 = CTSListBase::Pop(this: &g_VisitHashPool);
  if ( v0 != nullptr )
    return (int)(&v0->Next + 1);
  v1 = p_malloc(size: 0x808u);
  if ( v1 == nullptr )
    return 4;
  *((_WORD *)v1 + 1026) = 1;
  memset(dst: (unsigned __int8 *)v1 + 4, value: 0, count: 0x800u);
  return (int)v1 + 4;
}

//------------------------------------------------------------------------------
// Address: 0x1002D4A0
// Name: public: void CTraceIVP::SetLedge(class IVP_Compact_Ledge const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceIVP::SetLedge(CTraceIVP *this, const IVP_Compact_Ledge *pLedge, int nIndex)
{
  const collidemap_t *m_pCollideMap; // edx
  const leafmap_t *v5; // eax
  char v6; // al
  int v7; // eax
  const IVP_Compact_Ledge **leafmap; // ecx
  const leafmap_t *v9; // [esp-4h] [ebp-10h]

  this->m_pLedge = pLedge;
  this->m_pLeafmap = nullptr;
  if ( pLedge != nullptr )
  {
    m_pCollideMap = this->m_pCollideMap;
    this->m_cacheCount = 0;
    if ( m_pCollideMap != nullptr )
    {
      if ( nIndex < m_pCollideMap->leafCount )
      {
        v5 = &m_pCollideMap->leafmap[nIndex];
        if ( (const IVP_Compact_Ledge *)v5->pLeaf == pLedge )
        {
          this->m_pLeafmap = v5;
          v6 = CTraceIVP::BuildLeafmapCache(this, pLeafmap: v5);
          goto LABEL_14;
        }
      }
      v7 = 0;
      if ( m_pCollideMap->leafCount > 0 )
      {
        leafmap = (const IVP_Compact_Ledge **)m_pCollideMap->leafmap;
        while ( *leafmap != pLedge )
        {
          ++v7;
          leafmap += 6;
          if ( v7 >= m_pCollideMap->leafCount )
            goto LABEL_15;
        }
        v9 = &m_pCollideMap->leafmap[v7];
        this->m_pLeafmap = v9;
        v6 = CTraceIVP::BuildLeafmapCache(this, pLeafmap: v9);
LABEL_14:
        if ( v6 != 0 )
          return;
      }
    }
    else if ( pLedge->n_triangles == 2 )
    {
      v6 = CTraceIVP::BuildSingleTriangleCache(this, pLedge);
      goto LABEL_14;
    }
LABEL_15:
    if ( this->m_pVisitHash == nullptr )
      this->m_pVisitHash = (CVisitHash *)AllocVisitHash();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D540
// Name: public: CTraceIVP::CTraceIVP(class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
CTraceIVP *__userpurge CTraceIVP::CTraceIVP@<eax>(
        CTraceIVP *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const CPhysCollide *pCollide)
{
  const IVP_Compact_Surface *v5; // eax
  float v6; // xmm0_4

  this->__vftable = (CTraceIVP_vtbl *)&CTraceIVP::`vftable';
  this->m_pCollideMap = (const collidemap_t *)((int (__thiscall *)(const CPhysCollide *, int, int))pCollide->GetCollideMap)(
                                                a1: pCollide,
                                                a2,
                                                a3);
  v5 = pCollide->GetCompactSurface(this: pCollide);
  this->m_pSurface = v5;
  this->m_pLedge = nullptr;
  this->m_pVisitHash = nullptr;
  this->m_bHasTranslation = false;
  v6 = fsqrt(
         (float)((float)((float)(v5->mass_center.k[0] * v5->mass_center.k[0])
                       + (float)(v5->mass_center.k[1] * v5->mass_center.k[1]))
               + (float)(v5->mass_center.k[2] * v5->mass_center.k[2]))
       - -0.00000011920929);
  this->m_matrix = g_IdentityMatrix;
  this->m_ivpLocalToHLWorld = g_IdentityIVPToHLWorld;
  this->m_radius = (float)(v5->upper_limit_radius + v6) * g_PhysicsUnits.unitScaleMetersInv;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D650
// Name: public: CTraceSolverAABBTree::CTraceSolverAABBTree(class CGameTrace __near *,struct Ray_t const __near &,class CTraceIVP __near *,class CTraceRay __near &,class CTraceAABB __near &,class CPhysCollideAABBTree const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CTraceSolverAABBTree *__thiscall CTraceSolverAABBTree::CTraceSolverAABBTree(
        CTraceSolverAABBTree *this,
        CGameTrace *ptr,
        const Ray_t *raySrc,
        CTraceIVP *pObstacle,
        CTraceRay *rayIn,
        CTraceAABB *boxIn,
        const CPhysCollideAABBTree *pTree,
        const Vector *axis)
{
  CTraceSolverAABBTree *result; // eax
  float m_baseLength; // xmm0_4
  float collisionSweepEpsilon; // xmm0_4

  result = this;
  this->__vftable = (CTraceSolverAABBTree_vtbl *)&CTraceSolver::`vftable';
  this->m_pTotalTrace = ptr;
  this->m_sweepObject = boxIn;
  this->m_obstacle = pObstacle;
  this->m_ray = rayIn;
  this->m_traceLength = 0.0;
  m_baseLength = rayIn->m_baseLength;
  if ( m_baseLength <= 0.0000000099999999 )
    m_baseLength = 0.0000000099999999;
  this->m_totalTraceLength = m_baseLength;
  this->m_pointClosestToIntersection = *axis;
  collisionSweepEpsilon = g_PhysicsUnits.collisionSweepEpsilon;
  this->m_pObstacleIVP = pObstacle;
  this->m_bbox = boxIn;
  this->m_TraceRay = rayIn;
  this->m_epsilon = collisionSweepEpsilon;
  this->__vftable = (CTraceSolverAABBTree_vtbl *)&CTraceSolverAABBTree::`vftable';
  qmemcpy((void *)&this->m_raySrc, raySrc, sizeof(this->m_raySrc));
  this->m_pTree = pTree;
  this->m_bDidTrace = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D700
// Name: GetAABBForLedge
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall GetAABBForLedge(
        const IVP_Compact_Ledgetree_Node *pNode@<edi>,
        CTraceIVP *ivp@<esi>,
        int a3@<ebp>,
        __m128 *a4,
        __m128 *a5)
{
  __m128 v5; // [esp-Ch] [ebp-3Ch]
  __m128 v6; // [esp-Ch] [ebp-3Ch]
  _BYTE fl4Maxs_4[40]; // [esp+4h] [ebp-2Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h]

  *(_DWORD *)&fl4Maxs_4[32] = a3;
  *(_DWORD *)&fl4Maxs_4[36] = retaddr;
  if ( pNode->offset_right_node != 0 && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
    __debugbreak();
  CTraceIVP::SetLedge(
    this: ivp,
    pLedge: (const IVP_Compact_Ledge *)((char *)pNode + pNode->offset_compact_ledge),
    nIndex: pNode->nLedgeIndex);
  ivp->SupportMap(this: ivp, a2: &g_xneg, a3: (Vector *)&fl4Maxs_4[16]);
  *(_OWORD *)fl4Maxs_4 = *(_OWORD *)&fl4Maxs_4[16];
  ivp->SupportMap(this: ivp, a2: &g_yneg, a3: (Vector *)&fl4Maxs_4[16]);
  v5 = *(__m128 *)&fl4Maxs_4[16];
  ivp->SupportMap(this: ivp, a2: (const Vector *)v5.m128_i32[0], a3: (Vector *)v5.m128_i32[1]);
  *a4 = _mm_sub_ps(_mm_min_ps(_mm_min_ps(*(__m128 *)fl4Maxs_4, v5), *(__m128 *)&fl4Maxs_4[16]), Four_DistEpsilons);
  ivp->SupportMap(this: ivp, a2: &g_xpos, a3: (Vector *)&fl4Maxs_4[16]);
  v6 = *(__m128 *)&fl4Maxs_4[16];
  ivp->SupportMap(this: ivp, a2: (const Vector *)v6.m128_i32[0], a3: (Vector *)v6.m128_i32[1]);
  *(_OWORD *)fl4Maxs_4 = *(_OWORD *)&fl4Maxs_4[16];
  ivp->SupportMap(this: ivp, a2: &g_zpos, a3: (Vector *)&fl4Maxs_4[16]);
  *a5 = _mm_add_ps(_mm_max_ps(_mm_max_ps(v6, *(__m128 *)fl4Maxs_4), *(__m128 *)&fl4Maxs_4[16]), Four_DistEpsilons);
}

//------------------------------------------------------------------------------
// Address: 0x1002D800
// Name: public: bool CTraceSolver::SweepSingleConvex(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CTraceSolver::SweepSingleConvex@<al>(
        CTraceSolver *this@<ecx>,
        Vector *p_lastVert@<edi>,
        Vector *p_tmp@<esi>)
{
  Vector *v4; // ebx
  bool v5; // zf
  Vector *p_m_pointClosestToIntersection; // edi
  __int16 v7; // ax
  CTraceRay *m_ray; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  __int16 v12; // ax
  ITraceObject *m_obstacle; // ecx
  unsigned __int16 v14; // ax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  char v19; // al
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v23; // xmm5_4
  float m_epsilon; // xmm0_4
  int v25; // ebx
  float v26; // xmm1_4
  float v27; // xmm2_4
  __int16 v28; // ax
  CTraceRay *v29; // eax
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  __int16 v33; // ax
  ITraceObject *v34; // ecx
  unsigned __int16 v35; // ax
  float v36; // xmm0_4
  bool v37; // cc
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  CTraceRay *v42; // eax
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm0_4
  float m_length; // xmm0_4
  ITraceObject *m_sweepObject; // eax
  float v50; // xmm0_4
  CTraceRay *v51; // [esp+1Ch] [ebp-ACh]
  ITraceObject *epsilon; // [esp+20h] [ebp-A8h]
  simplex_t simplex; // [esp+30h] [ebp-98h] BYREF
  float v56[3]; // [esp+74h] [ebp-54h] BYREF
  Vector lastVert; // [esp+80h] [ebp-48h] BYREF
  Vector normal; // [esp+8Ch] [ebp-3Ch]
  float backupDistance; // [esp+98h] [ebp-30h]
  Vector tmp; // [esp+9Ch] [ebp-2Ch] BYREF
  float flDist; // [esp+A8h] [ebp-20h] BYREF
  Vector dir; // [esp+ACh] [ebp-1Ch] BYREF
  simplexvert_t vert; // [esp+B8h] [ebp-10h] BYREF

  v4 = nullptr;
  v5 = vec3_origin.x == this->m_pointClosestToIntersection.x;
  p_m_pointClosestToIntersection = &this->m_pointClosestToIntersection;
  simplex.vertCount = 0;
  if ( v5
    && vec3_origin.y == this->m_pointClosestToIntersection.y
    && vec3_origin.z == this->m_pointClosestToIntersection.z )
  {
    p_m_pointClosestToIntersection->x = 1.0;
    this->m_pointClosestToIntersection.y = 0.0;
    this->m_pointClosestToIntersection.z = 0.0;
  }
  dir.x = -p_m_pointClosestToIntersection->x;
  dir.y = -this->m_pointClosestToIntersection.y;
  dir.z = -this->m_pointClosestToIntersection.z;
  VectorNormalize(vec: &dir);
  while ( 2 )
  {
    v7 = ((int (__thiscall *)(ITraceObject *, Vector *, simplexvert_t *, Vector *, Vector *))this->m_sweepObject->SupportMap)(
           a1: this->m_sweepObject,
           a2: &dir,
           a3: &vert,
           a4: p_lastVert,
           a5: p_tmp);
    *((_WORD *)&vert + 6) ^= (*((_WORD *)&vert + 6) ^ v7) & 0x7FFF;
    m_ray = this->m_ray;
    if ( (float)((float)((float)(m_ray->m_delta.y * dir.y) + (float)(dir.x * m_ray->m_delta.x))
               + (float)(m_ray->m_delta.z * dir.z)) <= 0.0 )
    {
      x = m_ray->m_start.x;
      tmp.x = m_ray->m_start.x;
      y = m_ray->m_start.y;
      tmp.y = y;
      z = m_ray->m_start.z;
      v12 = 0;
    }
    else
    {
      x = m_ray->m_end.x;
      tmp.x = x;
      y = m_ray->m_end.y;
      tmp.y = y;
      z = m_ray->m_end.z;
      v12 = 1;
    }
    vert.position.y = vert.position.y + y;
    m_obstacle = this->m_obstacle;
    *((_WORD *)&vert + 6) = *((_WORD *)&vert + 6) & 0x7FFF | (v12 << 15);
    vert.position.z = vert.position.z + z;
    p_tmp = &tmp;
    tmp.z = z;
    vert.position.x = vert.position.x + x;
    lastVert.x = -dir.x;
    lastVert.y = -dir.y;
    lastVert.z = -dir.z;
    p_lastVert = &lastVert;
    v14 = ((int (__thiscall *)(ITraceObject *))m_obstacle->SupportMap)(a1: m_obstacle);
    v15 = vert.position.x - tmp.x;
    v16 = vert.position.y - tmp.y;
    v17 = vert.position.z - tmp.z;
    v18 = (float)((float)((float)(vert.position.y - tmp.y) * dir.y) + (float)((float)(vert.position.x - tmp.x) * dir.x))
        + (float)((float)(vert.position.z - tmp.z) * dir.z);
    vert.obstacleIndex = v14;
    vert.position.x = vert.position.x - tmp.x;
    vert.position.y = vert.position.y - tmp.y;
    vert.position.z = vert.position.z - tmp.z;
    if ( v18 >= 0.0 )
    {
      switch ( simplex.vertCount )
      {
        case 0:
          simplex.vertCount = 1;
          simplex.verts[0].position.x = v15;
          simplex.verts[0].position.y = v16;
          simplex.verts[0].position.z = v17;
          *((_WORD *)simplex.verts + 6) = *((_WORD *)&vert + 6);
          simplex.verts[0].obstacleIndex = v14;
          p_m_pointClosestToIntersection->x = v15;
          p_m_pointClosestToIntersection->y = v16;
          p_m_pointClosestToIntersection->z = v17;
          goto LABEL_16;
        case 1:
          v19 = simplex_t::SolveVoronoiRegion2(this: &simplex, newPoint: &vert, pOut: p_m_pointClosestToIntersection);
          goto LABEL_15;
        case 2:
          v19 = simplex_t::SolveVoronoiRegion3(this: &simplex, newPoint: &vert, pOut: p_m_pointClosestToIntersection);
          goto LABEL_15;
        case 3:
          v19 = simplex_t::SolveVoronoiRegion4(this: &simplex, newPoint: &vert, pOut: p_m_pointClosestToIntersection);
LABEL_15:
          if ( v19 != 0 )
            goto LABEL_44;
LABEL_16:
          v20 = -p_m_pointClosestToIntersection->y;
          v21 = -p_m_pointClosestToIntersection->z;
          dir.x = -p_m_pointClosestToIntersection->x;
          dir.y = v20;
          dir.z = v21;
          VectorNormalize(vec: &dir);
          v4 = (Vector *)((char *)v4 + 1);
          if ( (int)v4 >= 100 )
            return 0;
          continue;
        default:
LABEL_44:
          memset(dst: (unsigned __int8 *)&this->m_trace, value: 0, count: sizeof(this->m_trace));
          this->m_trace.fraction = 1.0;
          this->m_trace.fractionleftsolid = 0.0;
          this->m_trace.surface = nullsurface;
          if ( this->m_ray->m_length == 0.0
            || (flDist = 0.0, CTraceSolver::SolveMeshIntersection(this, p_tmp: v4, &simplex, pflDist: &flDist) == 0)
            || (m_length = this->m_ray->m_length) <= flDist )
          {
            this->m_traceLength = 0.0;
            *(_WORD *)&this->m_trace.allsolid = 257;
            return 1;
          }
          else
          {
            epsilon = this->m_obstacle;
            v51 = this->m_ray;
            m_sweepObject = this->m_sweepObject;
            this->m_traceLength = m_length - flDist;
            CalculateSeparatingPlane(
              sweepObject: m_sweepObject,
              &simplex,
              ptr: &this->m_trace,
              ray: v51,
              obstacle: epsilon);
            v50 = (float)((float)(this->m_ray->m_dir.y * this->m_trace.plane.normal.y)
                        + (float)(this->m_trace.plane.normal.x * this->m_ray->m_dir.x))
                + (float)(this->m_ray->m_dir.z * this->m_trace.plane.normal.z);
            if ( v50 < 0.0 )
              this->m_traceLength = (float)(this->m_epsilon / v50) + this->m_traceLength;
            if ( this->m_traceLength < 0.0 )
              this->m_traceLength = 0.0;
            this->m_trace.contents = 1;
            return 1;
          }
      }
    }
    break;
  }
  v23 = fabs(v18);
  m_epsilon = this->m_epsilon;
  flDist = v23;
  if ( m_epsilon <= v23 || this->m_ray->m_length <= 0.0 )
    return 0;
  normal = dir;
  if ( v23 > 0.0 )
  {
    v25 = 0;
    while ( 1 )
    {
      lastVert = vert.position;
      switch ( simplex.vertCount )
      {
        case 0:
          simplex.vertCount = 1;
          simplexvert_t::operator=(this: simplex.verts, __that: &vert);
          *p_m_pointClosestToIntersection = vert.position;
          break;
        case 1:
          simplex_t::SolveVoronoiRegion2(this: &simplex, newPoint: &vert, pOut: p_m_pointClosestToIntersection);
          break;
        case 2:
          simplex_t::SolveVoronoiRegion3(this: &simplex, newPoint: &vert, pOut: p_m_pointClosestToIntersection);
          break;
        case 3:
          simplex_t::SolveVoronoiRegion4(this: &simplex, newPoint: &vert, pOut: p_m_pointClosestToIntersection);
          break;
        default:
          break;
      }
      v26 = -p_m_pointClosestToIntersection->y;
      v27 = -p_m_pointClosestToIntersection->z;
      dir.x = -p_m_pointClosestToIntersection->x;
      dir.y = v26;
      dir.z = v27;
      VectorNormalize(vec: &dir);
      v28 = ((int (__thiscall *)(ITraceObject *, Vector *, simplexvert_t *, Vector *, Vector *))this->m_sweepObject->SupportMap)(
              a1: this->m_sweepObject,
              a2: &dir,
              a3: &vert,
              a4: p_lastVert,
              a5: &tmp);
      *((_WORD *)&vert + 6) ^= (*((_WORD *)&vert + 6) ^ v28) & 0x7FFF;
      v29 = this->m_ray;
      if ( (float)((float)((float)(v29->m_delta.y * dir.y) + (float)(dir.x * v29->m_delta.x))
                 + (float)(v29->m_delta.z * dir.z)) <= 0.0 )
      {
        v30 = v29->m_start.x;
        tmp.x = v29->m_start.x;
        v31 = v29->m_start.y;
        tmp.y = v31;
        v32 = v29->m_start.z;
        v33 = 0;
      }
      else
      {
        v30 = v29->m_end.x;
        tmp.x = v30;
        v31 = v29->m_end.y;
        tmp.y = v31;
        v32 = v29->m_end.z;
        v33 = 1;
      }
      vert.position.y = vert.position.y + v31;
      v34 = this->m_obstacle;
      *((_WORD *)&vert + 6) = *((_WORD *)&vert + 6) & 0x7FFF | (v33 << 15);
      vert.position.z = vert.position.z + v32;
      tmp.z = v32;
      vert.position.x = vert.position.x + v30;
      v56[0] = -dir.x;
      v56[1] = -dir.y;
      v56[2] = -dir.z;
      p_lastVert = (Vector *)v56;
      v35 = ((int (__thiscall *)(ITraceObject *))v34->SupportMap)(a1: v34);
      vert.position.y = vert.position.y - tmp.y;
      vert.position.x = vert.position.x - tmp.x;
      vert.position.z = vert.position.z - tmp.z;
      v36 = -(float)((float)((float)(vert.position.y * dir.y) + (float)(vert.position.x * dir.x))
                   + (float)(vert.position.z * dir.z));
      v37 = v36 <= this->m_epsilon;
      vert.obstacleIndex = v35;
      if ( !v37 )
        return 0;
      v23 = flDist;
      if ( v36 > flDist )
      {
        v23 = -(float)((float)((float)(vert.position.y * dir.y) + (float)(vert.position.x * dir.x))
                     + (float)(vert.position.z * dir.z));
        flDist = v23;
        normal = dir;
      }
      if ( (float)(v36
                 - (float)-(float)((float)((float)(lastVert.y * dir.y) + (float)(lastVert.x * dir.x))
                                 + (float)(lastVert.z * dir.z))) <= -0.000099999997
        && ++v25 < 20 )
      {
        continue;
      }
      break;
    }
  }
  v38 = this->m_epsilon;
  LODWORD(v39) = COERCE_UNSIGNED_INT(
                   (float)((float)(this->m_ray->m_delta.y * normal.y) + (float)(this->m_ray->m_delta.x * normal.x))
                 + (float)(this->m_ray->m_delta.z * normal.z))
               ^ _mask__NegFloat_;
  backupDistance = v39;
  if ( -(v38 * 0.1) <= v39 && (v39 >= -0.000099999997 || v38 * 0.9 <= v23) )
    return 0;
  memset(dst: (unsigned __int8 *)&this->m_trace, value: 0, count: sizeof(this->m_trace));
  v40 = 0.0;
  this->m_trace.fraction = 1.0;
  v41 = -1.0 / backupDistance;
  this->m_trace.fractionleftsolid = 0.0;
  this->m_trace.surface = nullsurface;
  v42 = this->m_ray;
  v43 = this->m_epsilon;
  v44 = v42->m_length - (float)((float)((float)(v43 - flDist) * v42->m_baseLength) * v41);
  this->m_traceLength = v44;
  if ( v44 < 0.0 )
  {
    v5 = simplex.vertCount == 3;
    this->m_traceLength = 0.0;
    if ( v5 )
    {
      backupDistance = simplex_t::ClipRayToTriangle(this: &simplex, dir: &v42->m_dir, epsilon: v43);
      v40 = backupDistance;
    }
    v45 = this->m_ray->m_length;
    if ( v45 > v40 )
      this->m_traceLength = v45 - v40;
  }
  v46 = -normal.y;
  v47 = -normal.z;
  this->m_trace.plane.normal.x = -normal.x;
  this->m_trace.plane.normal.y = v46;
  this->m_trace.plane.normal.z = v47;
  this->m_trace.contents = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002E090
// Name: void TraceGetAABB_r(class Vector __near *,class Vector __near *,class IVP_Compact_Ledgetree_Node const __near *,class CTraceIVP __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TraceGetAABB_r(Vector *pMins, Vector *pMaxs, const IVP_Compact_Ledgetree_Node *node, CTraceIVP *ivp)
{
  Vector tmp; // [esp+Ch] [ebp-Ch] BYREF

  while ( node->offset_right_node != 0 )
  {
    TraceGetAABB_r(pMins, pMaxs, node: node + 1, ivp);
    node = (const IVP_Compact_Ledgetree_Node *)((char *)node + node->offset_right_node);
  }
  CTraceIVP::SetLedge(
    this: ivp,
    pLedge: (const IVP_Compact_Ledge *)((char *)node + node->offset_compact_ledge),
    nIndex: node->nLedgeIndex);
  ivp->SupportMap(this: ivp, a2: &g_xneg, a3: &tmp);
  AddPointToBounds(v: &tmp, mins: pMins, maxs: pMaxs);
  ivp->SupportMap(this: ivp, a2: &g_yneg, a3: &tmp);
  AddPointToBounds(v: &tmp, mins: pMins, maxs: pMaxs);
  ivp->SupportMap(this: ivp, a2: &g_zneg, a3: &tmp);
  AddPointToBounds(v: &tmp, mins: pMins, maxs: pMaxs);
  ivp->SupportMap(this: ivp, a2: &g_xpos, a3: &tmp);
  AddPointToBounds(v: &tmp, mins: pMins, maxs: pMaxs);
  ivp->SupportMap(this: ivp, a2: &g_ypos, a3: &tmp);
  AddPointToBounds(v: &tmp, mins: pMins, maxs: pMaxs);
  ivp->SupportMap(this: ivp, a2: &g_zpos, a3: &tmp);
  AddPointToBounds(v: &tmp, mins: pMins, maxs: pMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x1002E1A0
// Name: void TraceGetExtent_r(class IVP_Compact_Ledgetree_Node const __near *,class CTraceIVP __near &,class Vector const __near &,float __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TraceGetExtent_r(
        const IVP_Compact_Ledgetree_Node *node,
        CTraceIVP *ivp,
        const Vector *dir,
        float *dot,
        Vector *point)
{
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float v9; // xmm0_4
  Vector tmp; // [esp+Ch] [ebp-Ch] BYREF

  while ( node->offset_right_node != 0 )
  {
    TraceGetExtent_r(node: node + 1, ivp, dir, dot, point);
    node = (const IVP_Compact_Ledgetree_Node *)((char *)node + node->offset_right_node);
  }
  CTraceIVP::SetLedge(
    this: ivp,
    pLedge: (const IVP_Compact_Ledge *)((char *)node + node->offset_compact_ledge),
    nIndex: node->nLedgeIndex);
  ivp->SupportMap(this: ivp, a2: dir, a3: &tmp);
  y = tmp.y;
  x = tmp.x;
  z = tmp.z;
  v9 = (float)((float)(dir->y * tmp.y) + (float)(dir->x * tmp.x)) + (float)(dir->z * tmp.z);
  if ( v9 > *dot )
  {
    *dot = v9;
    point->x = x;
    point->y = y;
    point->z = z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E250
// Name: public: CTraceIVP::CTraceIVP(class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
CTraceIVP *__userpurge CTraceIVP::CTraceIVP@<eax>(
        CTraceIVP *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const CPhysCollide *pCollide,
        const Vector *origin,
        const QAngle *angles)
{
  const IVP_Compact_Surface *v7; // ecx
  bool v8; // al
  __int128 v9; // xmm0
  const IVP_Compact_Surface *m_pSurface; // edx
  float v11; // xmm2_4
  __int128 v14; // [esp-10h] [ebp-1Ch]

  this->__vftable = (CTraceIVP_vtbl *)&CTraceIVP::`vftable';
  this->m_pCollideMap = (const collidemap_t *)((int (__thiscall *)(const CPhysCollide *, int, int))pCollide->GetCollideMap)(
                                                a1: pCollide,
                                                a2,
                                                a3);
  v7 = pCollide->GetCompactSurface(this: pCollide);
  this->m_pSurface = v7;
  this->m_pLedge = nullptr;
  this->m_pVisitHash = nullptr;
  v8 = vec3_origin.x == origin->x && vec3_origin.y == origin->y && vec3_origin.z == origin->z;
  this->m_bHasTranslation = !v8;
  v9 = 0;
  *(float *)&v9 = fsqrt(
                    (float)((float)((float)(v7->mass_center.k[0] * v7->mass_center.k[0])
                                  + (float)(v7->mass_center.k[1] * v7->mass_center.k[1]))
                          + (float)(v7->mass_center.k[2] * v7->mass_center.k[2]))
                  - -0.00000011920929);
  v14 = v9;
  ConvertRotationToIVP(angles: (const QAngle *)DWORD1(v14), out: (IVP_U_Matrix3 *)DWORD2(v14));
  *(float *)&v9 = origin->y;
  this->m_matrix.vv.k[0] = origin->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(this->m_matrix.vv.k[1]) = COERCE_UNSIGNED_INT(origin->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  this->m_matrix.vv.k[2] = g_PhysicsUnits.unitScaleMeters * *(float *)&v9;
  *(float *)&v9 = g_PhysicsUnits.unitScaleMetersInv;
  this->m_ivpLocalToHLWorld.m_flMatVal[0][0] = this->m_matrix.rows[0].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  this->m_ivpLocalToHLWorld.m_flMatVal[0][1] = this->m_matrix.rows[0].k[1] * *(float *)&v9;
  this->m_ivpLocalToHLWorld.m_flMatVal[0][2] = this->m_matrix.rows[0].k[2] * *(float *)&v9;
  this->m_ivpLocalToHLWorld.m_flMatVal[1][0] = this->m_matrix.rows[2].k[0] * *(float *)&v9;
  this->m_ivpLocalToHLWorld.m_flMatVal[1][1] = this->m_matrix.rows[2].k[1] * *(float *)&v9;
  m_pSurface = this->m_pSurface;
  this->m_ivpLocalToHLWorld.m_flMatVal[1][2] = this->m_matrix.rows[2].k[2] * *(float *)&v9;
  this->m_ivpLocalToHLWorld.m_flMatVal[2][0] = this->m_matrix.rows[1].k[0] * (float)(*(float *)&v9 * -1.0);
  this->m_ivpLocalToHLWorld.m_flMatVal[2][1] = this->m_matrix.rows[1].k[1] * (float)(*(float *)&v9 * -1.0);
  this->m_ivpLocalToHLWorld.m_flMatVal[2][2] = this->m_matrix.rows[1].k[2] * (float)(*(float *)&v9 * -1.0);
  this->m_ivpLocalToHLWorld.m_flMatVal[0][3] = *(float *)&v9 * this->m_matrix.vv.k[0];
  v11 = this->m_matrix.vv.k[2] * *(float *)&v9;
  this->m_ivpLocalToHLWorld.m_flMatVal[2][3] = this->m_matrix.vv.k[1] * (float)(*(float *)&v9 * -1.0);
  this->m_ivpLocalToHLWorld.m_flMatVal[1][3] = v11;
  this->m_radius = (float)(m_pSurface->upper_limit_radius + *(float *)&v14) * g_PhysicsUnits.unitScaleMetersInv;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002E470
// Name: public: virtual void CTraceSolver::DoSweep(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceSolver::DoSweep(CTraceSolver *this)
{
  CGameTrace *p_m_trace; // esi
  CGameTrace *m_pTotalTrace; // edi

  p_m_trace = &this->m_trace;
  memset(dst: (unsigned __int8 *)&this->m_trace, value: 0, count: sizeof(this->m_trace));
  p_m_trace->fraction = 1.0;
  p_m_trace->fractionleftsolid = 0.0;
  p_m_trace->surface = nullsurface;
  CTraceSolver::SweepSingleConvex(this, p_lastVert: (Vector *)this, p_tmp: &p_m_trace->startpos);
  m_pTotalTrace = this->m_pTotalTrace;
  CBaseTrace::operator=(this: m_pTotalTrace, __that: p_m_trace);
  m_pTotalTrace->fractionleftsolid = p_m_trace->fractionleftsolid;
  m_pTotalTrace->surface = p_m_trace->surface;
  m_pTotalTrace->hitgroup = p_m_trace->hitgroup;
  m_pTotalTrace->physicsbone = p_m_trace->physicsbone;
  m_pTotalTrace->worldSurfaceIndex = p_m_trace->worldSurfaceIndex;
  m_pTotalTrace->m_pEnt = p_m_trace->m_pEnt;
  m_pTotalTrace->hitbox = p_m_trace->hitbox;
}

//------------------------------------------------------------------------------
// Address: 0x1002E500
// Name: public: void CTraceSolverSweptObject::SweepAgainstNode(class IVP_Compact_Ledgetree_Node const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceSolverSweptObject::SweepAgainstNode(
        CTraceSolverSweptObject *this,
        const IVP_Compact_Ledgetree_Node *node)
{
  int offset_compact_ledge; // edi
  int v4; // eax
  const IVP_Compact_Ledge *v6; // edi
  CGameTrace *m_pTotalTrace; // eax
  float m_traceLength; // xmm0_4
  CTraceRay *m_ray; // eax
  CGameTrace *v10; // ecx
  CTraceRay *v11; // eax
  float v12; // xmm0_4
  float x; // xmm4_4
  float z; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  unsigned int ledgeContents; // [esp+14h] [ebp+8h]

  offset_compact_ledge = node->offset_compact_ledge;
  v4 = *(int *)((char *)&node->offset_compact_ledge + offset_compact_ledge);
  v6 = (const IVP_Compact_Ledge *)((char *)node + offset_compact_ledge);
  ledgeContents = this->m_pConvexInfo->GetContents(this: this->m_pConvexInfo, a2: v4);
  if ( (ledgeContents & this->m_contentsMask) != 0 )
  {
    CTraceIVP::SetLedge(this: this->m_obstacleIVP, pLedge: v6, nIndex: node->nLedgeIndex);
    if ( CTraceSolver::SweepSingleConvex(this, p_lastVert: (Vector *)v6, p_tmp: (Vector *)this) != 0
      && this->m_totalTraceLength > this->m_traceLength )
    {
      m_pTotalTrace = this->m_pTotalTrace;
      m_pTotalTrace->plane.normal.x = this->m_trace.plane.normal.x;
      m_pTotalTrace->plane.normal.y = this->m_trace.plane.normal.y;
      m_pTotalTrace->plane.normal.z = this->m_trace.plane.normal.z;
      this->m_pTotalTrace->startsolid = this->m_trace.startsolid;
      this->m_pTotalTrace->allsolid = this->m_trace.allsolid;
      m_traceLength = this->m_traceLength;
      m_ray = this->m_ray;
      v10 = this->m_pTotalTrace;
      this->m_totalTraceLength = m_traceLength;
      v10->fraction = m_ray->m_ooBaseLength * m_traceLength;
      v11 = this->m_ray;
      v12 = (float)((float)(this->m_epsilon * 2.0) + this->m_traceLength) * v11->m_ooBaseLength;
      if ( v12 < 1.0 )
      {
        x = v11->m_start.x;
        v11->m_length = v11->m_baseLength * v12;
        z = v11->m_delta.z;
        v15 = x + (float)(v11->m_delta.x * v12);
        v16 = v11->m_start.z;
        v11->m_end.y = v11->m_start.y + (float)(v11->m_delta.y * v12);
        v11->m_end.x = v15;
        v17 = z * v12;
        v18 = v12 * 0.5;
        v11->m_end.z = v16 + v17;
        v11->m_bestDist = 0.0;
        this->m_rayLengthOS = this->m_ray->m_length * g_PhysicsUnits.unitScaleMeters;
        v19 = (float)(this->m_rayDeltaOS.k[1] * v18) + this->m_rayStartOS.k[1];
        v20 = (float)(this->m_rayDeltaOS.k[2] * v18) + this->m_rayStartOS.k[2];
        this->m_rayCenterOS.k[0] = (float)(this->m_rayDeltaOS.k[0] * v18) + this->m_rayStartOS.k[0];
        this->m_rayCenterOS.k[1] = v19;
        this->m_rayCenterOS.k[2] = v20;
      }
      this->m_pTotalTrace->contents = ledgeContents;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E6B0
// Name: public: void CTraceSolverSweptObject::SweepLedgeTree(class IVP_Compact_Ledgetree_Node const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceSolverSweptObject::SweepLedgeTree(
        CTraceSolverSweptObject *this,
        const IVP_Compact_Ledgetree_Node *node)
{
  const IVP_Compact_Ledgetree_Node *v2; // edx
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  int offset_right_node; // eax
  float v10; // xmm1_4
  float m_rayLengthOS; // xmm6_4
  float v12; // xmm5_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  const IVP_Compact_Ledgetree_Node *v16; // ecx
  float v17; // xmm4_4
  float v18; // xmm7_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  const IVP_Compact_Ledgetree_Node *v24; // eax
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  int v29; // edi
  const IVP_Compact_Ledgetree_Node *pNodeList[256]; // [esp+0h] [ebp-408h]
  float v31; // [esp+400h] [ebp-8h]
  float lastDist; // [esp+404h] [ebp-4h]
  int nListCount; // [esp+410h] [ebp+8h]

  v2 = node;
  v4 = node->radius + this->m_sweepObjectRadius;
  v5 = node->center.k[0] - this->m_rayCenterOS.k[0];
  v6 = node->center.k[1] - this->m_rayCenterOS.k[1];
  v7 = node->center.k[2] - this->m_rayCenterOS.k[2];
  if ( this->m_rayLengthOS > 0.0 )
  {
    v8 = (float)(this->m_rayDirOS.k[1] * v7) - (float)(this->m_rayDirOS.k[2] * v6);
    if ( (float)(v4 * v4) <= (float)((float)((float)((float)((float)(this->m_rayDirOS.k[2] * v5)
                                                           - (float)(this->m_rayDirOS.k[0] * v7))
                                                   * (float)((float)(this->m_rayDirOS.k[2] * v5)
                                                           - (float)(this->m_rayDirOS.k[0] * v7)))
                                           + (float)(v8 * v8))
                                   + (float)((float)((float)(this->m_rayDirOS.k[0] * v6)
                                                   - (float)(this->m_rayDirOS.k[1] * v5))
                                           * (float)((float)(this->m_rayDirOS.k[0] * v6)
                                                   - (float)(this->m_rayDirOS.k[1] * v5)))) )
      return;
    goto LABEL_3;
  }
  if ( (float)(v4 * v4) > (float)((float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v7 * v7)) )
  {
LABEL_3:
    if ( node->offset_right_node == 0 )
    {
      CTraceSolverSweptObject::SweepAgainstNode(this, node);
      return;
    }
    nListCount = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        offset_right_node = v2->offset_right_node;
        if ( v2->offset_right_node != 0 )
          break;
        CTraceSolverSweptObject::SweepAgainstNode(this, node: v2);
LABEL_29:
        if ( nListCount - 1 < 0 )
          return;
        v2 = pNodeList[--nListCount];
      }
      v10 = v2[1].radius + this->m_sweepObjectRadius;
      m_rayLengthOS = this->m_rayLengthOS;
      v12 = 1.0e24;
      v13 = v2[1].center.k[0] - this->m_rayCenterOS.k[0];
      v14 = v2[1].center.k[1] - this->m_rayCenterOS.k[1];
      v15 = v2[1].center.k[2] - this->m_rayCenterOS.k[2];
      v16 = v2 + 1;
      lastDist = 1.0e24;
      v17 = v10 * v10;
      if ( m_rayLengthOS <= 0.0 )
      {
        if ( v17 > (float)((float)((float)(v14 * v14) + (float)(v13 * v13)) + (float)(v15 * v15)) )
        {
LABEL_18:
          v12 = (float)((float)((float)(this->m_rayStartOS.k[1] - v2[1].center.k[1])
                              * (float)(this->m_rayStartOS.k[1] - v2[1].center.k[1]))
                      + (float)((float)(this->m_rayStartOS.k[0] - v2[1].center.k[0])
                              * (float)(this->m_rayStartOS.k[0] - v2[1].center.k[0])))
              + (float)((float)(this->m_rayStartOS.k[2] - v2[1].center.k[2])
                      * (float)(this->m_rayStartOS.k[2] - v2[1].center.k[2]));
          lastDist = v12;
          goto LABEL_13;
        }
        v31 = (float)(m_rayLengthOS * 0.5) + v10;
      }
      else
      {
        v18 = this->m_rayDirOS.k[2];
        v19 = (float)(v15 * this->m_rayDirOS.k[1]) - (float)(v14 * v18);
        if ( v17 > (float)((float)((float)((float)((float)(v13 * v18) - (float)(this->m_rayDirOS.k[0] * v15))
                                         * (float)((float)(v13 * v18) - (float)(this->m_rayDirOS.k[0] * v15)))
                                 + (float)(v19 * v19))
                         + (float)((float)((float)(this->m_rayDirOS.k[0] * v14) - (float)(v13 * this->m_rayDirOS.k[1]))
                                 * (float)((float)(this->m_rayDirOS.k[0] * v14) - (float)(v13 * this->m_rayDirOS.k[1])))) )
          goto LABEL_18;
        v12 = lastDist;
      }
      v16 = nullptr;
LABEL_13:
      v20 = *(float *)((char *)&v2->radius + offset_right_node) + this->m_sweepObjectRadius;
      v21 = *(float *)((char *)v2->center.k + offset_right_node) - this->m_rayCenterOS.k[0];
      v22 = *(float *)((char *)&v2->center.k[1] + offset_right_node) - this->m_rayCenterOS.k[1];
      v23 = *(float *)((char *)&v2->center.k[2] + offset_right_node) - this->m_rayCenterOS.k[2];
      v24 = (const IVP_Compact_Ledgetree_Node *)((char *)v2 + offset_right_node);
      v25 = v20 * v20;
      if ( this->m_rayLengthOS <= 0.0 )
      {
        if ( v25 > (float)((float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v23 * v23)) )
          goto LABEL_20;
        v31 = (float)(this->m_rayLengthOS * 0.5) + v20;
LABEL_26:
        if ( v16 == nullptr )
          goto LABEL_29;
        v2 = v16;
      }
      else
      {
        v26 = this->m_rayDirOS.k[2];
        v27 = (float)(v23 * this->m_rayDirOS.k[1]) - (float)(v22 * v26);
        if ( v25 <= (float)((float)((float)((float)((float)(v21 * v26) - (float)(this->m_rayDirOS.k[0] * v23))
                                          * (float)((float)(v21 * v26) - (float)(this->m_rayDirOS.k[0] * v23)))
                                  + (float)(v27 * v27))
                          + (float)((float)((float)(this->m_rayDirOS.k[0] * v22) - (float)(v21 * this->m_rayDirOS.k[1]))
                                  * (float)((float)(this->m_rayDirOS.k[0] * v22) - (float)(v21 * this->m_rayDirOS.k[1])))) )
          goto LABEL_26;
        v12 = lastDist;
LABEL_20:
        if ( v16 != nullptr )
        {
          v28 = this->m_rayStartOS.k[1] - v24->center.k[1];
          v29 = nListCount++;
          if ( (float)((float)((float)(v28 * v28)
                             + (float)((float)(this->m_rayStartOS.k[0] - v24->center.k[0])
                                     * (float)(this->m_rayStartOS.k[0] - v24->center.k[0])))
                     + (float)((float)(this->m_rayStartOS.k[2] - v24->center.k[2])
                             * (float)(this->m_rayStartOS.k[2] - v24->center.k[2]))) <= v12 )
          {
            v2 = v24;
            pNodeList[v29] = v16;
          }
          else
          {
            v2 = v16;
            pNodeList[v29] = v24;
          }
        }
        else
        {
          v2 = v24;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EAB0
// Name: public: virtual void CTraceSolverSweptObject::DoSweep(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTraceSolverSweptObject::DoSweep(CTraceSolverSweptObject *this@<ecx>, int a2@<ebp>)
{
  CTraceSolverSweptObject::InitOSRay(this, a2);
  CTraceSolverSweptObject::SweepLedgeTree(
    this,
    node: (const IVP_Compact_Ledgetree_Node *)((char *)this->m_obstacleIVP->m_pSurface
                                       + this->m_obstacleIVP->m_pSurface->offset_ledgetree_root));
}

//------------------------------------------------------------------------------
// Address: 0x1002EAD0
// Name: public: virtual void CTraceSolverAABBTree::DoSweep(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceSolverAABBTree::DoSweep(CTraceSolverAABBTree *this)
{
  int v2; // ebx
  __m128 *v3; // ecx
  const IVP_Compact_Ledgetree_Node *v4; // eax
  CGameTrace *m_pTotalTrace; // eax
  float m_traceLength; // xmm0_4
  CTraceRay *m_ray; // eax
  CGameTrace *v8; // ecx
  CTraceRay *v9; // eax
  float v10; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  CTraceRay *v13; // eax
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  int nCount; // [esp+8h] [ebp-8h]
  int v18; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v2 = 0;
  nCount = this->m_pTree->m_pNodes.m_Size;
  if ( nCount > 0 )
  {
    v18 = 0;
    do
    {
      v3 = &this->m_pTree->m_pBounds[v18];
      if ( IsBoxIntersectingRay(
             boxMin: v3,
             boxMax: v3 + 1,
             a3: (int)&savedregs,
             ray: &this->m_raySrc,
             fl4Tolerance: &Four_Zeros) )
      {
        this->m_bDidTrace = true;
        memset(dst: (unsigned __int8 *)&this->m_trace, value: 0, count: sizeof(this->m_trace));
        this->m_trace.fraction = 1.0;
        this->m_trace.fractionleftsolid = 0.0;
        this->m_trace.surface = nullsurface;
        v4 = this->m_pTree->m_pNodes.m_Memory.m_pMemory[v2];
        CTraceIVP::SetLedge(
          this: this->m_pObstacleIVP,
          pLedge: (const IVP_Compact_Ledge *)((char *)v4 + v4->offset_compact_ledge),
          nIndex: v4->nLedgeIndex);
        if ( CTraceSolver::SweepSingleConvex(this, p_lastVert: &this->m_trace.startpos, p_tmp: (Vector *)this) != 0
          && this->m_totalTraceLength > this->m_traceLength )
        {
          m_pTotalTrace = this->m_pTotalTrace;
          m_pTotalTrace->plane.normal.x = this->m_trace.plane.normal.x;
          m_pTotalTrace->plane.normal.y = this->m_trace.plane.normal.y;
          m_pTotalTrace->plane.normal.z = this->m_trace.plane.normal.z;
          this->m_pTotalTrace->startsolid = this->m_trace.startsolid;
          this->m_pTotalTrace->allsolid = this->m_trace.allsolid;
          m_traceLength = this->m_traceLength;
          m_ray = this->m_ray;
          v8 = this->m_pTotalTrace;
          this->m_totalTraceLength = m_traceLength;
          v8->fraction = m_ray->m_ooBaseLength * m_traceLength;
          this->m_pTotalTrace->contents = 33570827;
          v9 = this->m_ray;
          v10 = (float)((float)(this->m_epsilon * 2.0) + this->m_traceLength) * v9->m_ooBaseLength;
          if ( v10 < 1.0 )
          {
            y = v9->m_delta.y;
            z = v9->m_delta.z;
            this->m_raySrc.m_Delta.x = v9->m_delta.x * v10;
            this->m_raySrc.m_Delta.y = y * v10;
            this->m_raySrc.m_Delta.z = z * v10;
            v13 = this->m_ray;
            v13->m_length = v13->m_baseLength * v10;
            v14 = v13->m_delta.z * v10;
            v15 = v13->m_start.y + (float)(v13->m_delta.y * v10);
            v16 = v13->m_start.z;
            v13->m_end.x = v13->m_start.x + (float)(v13->m_delta.x * v10);
            v13->m_end.y = v15;
            v13->m_end.z = v16 + v14;
            v13->m_bestDist = 0.0;
          }
        }
      }
      v18 += 2;
      ++v2;
    }
    while ( v2 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ECC0
// Name: public: void CPhysicsTrace::SweepBoxIVP(struct Ray_t const __near &,unsigned int,class IConvexInfo __near *,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CPhysicsTrace::SweepBoxIVP(
        CPhysicsTrace *this@<ecx>,
        float a2@<ebp>,
        const Ray_t *raySrc,
        unsigned int contentsMask,
        IConvexInfo *pConvexInfo,
        const CPhysCollide *pCollide,
        const Vector *surfaceOrigin,
        const QAngle *surfaceAngles,
        CGameTrace *ptr)
{
  float x; // xmm3_4
  float y; // xmm5_4
  float z; // xmm6_4
  bool v12; // zf
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm2_4
  __int128 v16; // xmm0
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  IConvexInfo *v27; // eax
  float fraction; // xmm0_4
  _DWORD v29[3]; // [esp-Ch] [ebp-82Ch] BYREF
  CTraceIVP ivp; // [esp+0h] [ebp-820h] BYREF
  _BYTE solver_76[168]; // [esp+6FCh] [ebp-124h] OVERLAPPED BYREF
  _DWORD v32[3]; // [esp+7ACh] [ebp-74h] BYREF
  CTraceRay ray; // [esp+7B8h] [ebp-68h] BYREF
  float v34; // [esp+7F8h] [ebp-28h]
  CTraceAABB box; // [esp+7FCh] [ebp-24h] BYREF
  float retaddr; // [esp+820h] [ebp+0h]

  box.m_z[1] = a2;
  box.m_radius = retaddr;
  memset(dst: (unsigned __int8 *)ptr, value: 0, count: sizeof(CGameTrace));
  ptr->fraction = 1.0;
  ptr->fractionleftsolid = 0.0;
  ptr->surface = nullsurface;
  x = raySrc->m_Extents.x;
  y = raySrc->m_Extents.y;
  z = raySrc->m_Extents.z;
  v12 = !raySrc->m_IsRay;
  LODWORD(ray.m_ooBaseLength) = &CTraceAABB::`vftable';
  if ( v12 )
  {
    v34 = -x;
    v13 = raySrc->m_Extents.z;
    box.m_y[0] = -z;
    v14 = raySrc->m_Extents.x;
    box.m_x[0] = -y;
    v15 = (float)((float)(v14 * v14) + (float)(raySrc->m_Extents.y * raySrc->m_Extents.y)) + (float)(v13 * v13);
    v16 = 0;
    ray.m_bestDist = x;
    *(float *)&box.__vftable = y;
    box.m_x[1] = z;
    *(float *)&v16 = fsqrt(v15);
    *(_OWORD *)&solver_76[152] = v16;
    LODWORD(box.m_y[1]) = v16;
    LOBYTE(box.m_z[0]) = 0;
  }
  else
  {
    v34 = 0.0;
    ray.m_bestDist = 0.0;
    memset(&box, 0, 20);
    LOBYTE(box.m_z[0]) = 1;
  }
  CTraceIVP::CTraceIVP(
    this: (CTraceIVP *)v29,
    a2: (int)raySrc,
    a3: (int)ptr,
    pCollide,
    origin: &vec3_origin,
    angles: surfaceAngles);
  v17 = raySrc->m_Start.y;
  v18 = surfaceOrigin->z;
  v19 = raySrc->m_Start.z;
  v20 = -surfaceOrigin->y;
  *(float *)&solver_76[156] = raySrc->m_Start.x - surfaceOrigin->x;
  v32[0] = *(_DWORD *)&solver_76[156];
  v21 = v17 + v20;
  v22 = raySrc->m_Delta.x;
  v23 = raySrc->m_Delta.z;
  v24 = v19 - v18;
  v25 = raySrc->m_Delta.y;
  ray.m_start.x = v22 + *(float *)&solver_76[156];
  ray.m_start.z = v24 + v23;
  v26 = fsqrt((float)((float)(v25 * v25) + (float)(v22 * v22)) + (float)(v23 * v23));
  *(float *)&v32[1] = v21;
  *(float *)&v32[2] = v24;
  ray.m_start.y = v25 + v21;
  ray.m_end.x = v22;
  ray.m_end.y = v25;
  ray.m_end.z = v23;
  ray.m_delta.x = v22;
  ray.m_delta.y = v25;
  ray.m_delta.z = v23;
  ray.m_dir.x = v26;
  ray.m_dir.z = 0.0;
  if ( v26 > 0.0 )
  {
    ray.m_dir.z = 1.0 / v26;
    ray.m_delta.x = v22 * (float)(1.0 / v26);
    ray.m_delta.y = v25 * (float)(1.0 / v26);
    ray.m_delta.z = v23 * (float)(1.0 / v26);
  }
  ray.m_dir.y = v26;
  ray.m_length = 0.0;
  *(_DWORD *)&solver_76[24] = ptr;
  *(_DWORD *)&solver_76[12] = &ray.m_ooBaseLength;
  *(_DWORD *)&solver_76[16] = v29;
  *(_DWORD *)&solver_76[20] = v32;
  *(_DWORD *)&solver_76[28] = 0;
  if ( v26 <= 0.0000000099999999 )
    *(_DWORD *)&solver_76[32] = 841731191;
  else
    *(float *)&solver_76[32] = v26;
  v27 = pConvexInfo;
  *(_DWORD *)solver_76 = *(_DWORD *)&solver_76[156];
  *(float *)&solver_76[4] = v21;
  *(float *)&solver_76[8] = v24;
  *(float *)&solver_76[40] = g_PhysicsUnits.collisionSweepEpsilon;
  ivp.m_vertCache[31].z.m128_i32[1] = (int)&CTraceSolverSweptObject::`vftable';
  *(_DWORD *)&solver_76[56] = &CDefConvexInfo::`vftable';
  *(_DWORD *)&solver_76[44] = v29;
  *(_DWORD *)&solver_76[52] = contentsMask;
  if ( pConvexInfo == nullptr )
    v27 = (IConvexInfo *)&solver_76[56];
  *(_DWORD *)&solver_76[48] = v27;
  *(float *)&solver_76[140] = box.m_y[1];
  CTraceSolverSweptObject::InitOSRay(
    this: (CTraceSolverSweptObject *)&ivp.m_vertCache[31].z.m128_i16[2],
    a2: (int)&box.m_z[1]);
  CTraceSolverSweptObject::SweepLedgeTree(
    this: (CTraceSolverSweptObject *)&ivp.m_vertCache[31].z.m128_i16[2],
    node: (const IVP_Compact_Ledgetree_Node *)(*(_DWORD *)(*(_DWORD *)&solver_76[44] + 8)
                                       + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&solver_76[44] + 8) + 32)));
  ptr->startpos.x = raySrc->m_Start.x + raySrc->m_StartOffset.x;
  ptr->startpos.y = raySrc->m_StartOffset.y + raySrc->m_Start.y;
  ptr->startpos.z = raySrc->m_StartOffset.z + raySrc->m_Start.z;
  fraction = ptr->fraction;
  ptr->endpos.x = (float)(raySrc->m_Delta.x * fraction) + ptr->startpos.x;
  ptr->endpos.y = (float)(raySrc->m_Delta.y * fraction) + ptr->startpos.y;
  ptr->endpos.z = (float)(raySrc->m_Delta.z * fraction) + ptr->startpos.z;
  if ( ptr->fraction < 1.0 || ptr->allsolid || ptr->startsolid )
    ptr->plane.dist = (float)((float)(ptr->plane.normal.y * ptr->endpos.y) + (float)(ptr->plane.normal.x * ptr->endpos.x))
                    + (float)(ptr->plane.normal.z * ptr->endpos.z);
  v29[0] = &CTraceIVP::`vftable';
  if ( ivp.m_pSurface != nullptr )
    CTSListBase::Push(this: &g_VisitHashPool, pNode: (TSLNodeBase_t *)&ivp.m_pSurface[-1].dummy[2]);
}

//------------------------------------------------------------------------------
// Address: 0x1002F0C0
// Name: public: bool CPhysicsTrace::SweepBoxAxisAlignedIVP(struct Ray_t const __near &,class CPhysCollide const __near *,class CPhysCollideAABBTree const __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CPhysicsTrace::SweepBoxAxisAlignedIVP@<al>(
        CPhysicsTrace *this@<ecx>,
        int a2@<ebp>,
        const Ray_t *raySrc,
        const CPhysCollide *pSurface,
        const CPhysCollideAABBTree *pTree,
        CGameTrace *ptr)
{
  char result; // al
  bool m_IsRay; // cl
  float *p_x; // eax
  float fraction; // xmm0_4
  _DWORD v10[3]; // [esp-Ch] [ebp-84Ch] BYREF
  CTraceIVP ivp; // [esp+0h] [ebp-840h] BYREF
  CTraceSolverAABBTree solver; // [esp+6B0h] [ebp-190h] BYREF
  CTraceRay rayIVP; // [esp+7B8h] [ebp-88h] BYREF
  __m128 box_24; // [esp+814h] [ebp-2Ch] OVERLAPPED BYREF
  VectorAligned *p_m_Delta; // [esp+82Ch] [ebp-14h]
  char m_totalTraceLength_low; // [esp+833h] [ebp-Dh]
  _DWORD v17[3]; // [esp+834h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+840h] [ebp+0h]

  v17[0] = a2;
  v17[1] = retaddr;
  memset(dst: (unsigned __int8 *)ptr, value: 0, count: sizeof(CGameTrace));
  ptr->fraction = 1.0;
  ptr->fractionleftsolid = 0.0;
  ptr->surface = nullsurface;
  box_24 = Four_Zeros;
  result = IsBoxIntersectingRay(
             boxMin: &pTree->m_fl4Mins,
             boxMax: &pTree->m_fl4Maxs,
             a3: (int)v17,
             ray: raySrc,
             fl4Tolerance: &box_24);
  if ( result != 0 )
  {
    CTraceIVP::CTraceIVP(this: (CTraceIVP *)v10, a2: (int)raySrc, a3: (int)ptr, pCollide: pSurface);
    m_IsRay = raySrc->m_IsRay;
    box_24.m128_f32[1] = -raySrc->m_Extents.x;
    box_24.m128_f32[2] = -raySrc->m_Extents.y;
    box_24.m128_f32[3] = -raySrc->m_Extents.z;
    CTraceAABB::CTraceAABB(
      this: (CTraceAABB *)&rayIVP.m_ooBaseLength,
      hlmins: (const Vector *)&box_24.m128_i16[2],
      hlmaxs: &raySrc->m_Extents,
      isPoint: m_IsRay);
    p_m_Delta = &raySrc->m_Delta;
    CTraceRay::Init(this: (CTraceRay *)(&solver.m_pTree + 3), hlstart: &raySrc->m_Start, delta: &raySrc->m_Delta);
    CTraceSolverAABBTree::CTraceSolverAABBTree(
      this: (CTraceSolverAABBTree *)&ivp.m_vertCache[31].z.m128_i16[2],
      ptr,
      raySrc,
      pObstacle: (CTraceIVP *)v10,
      rayIn: (CTraceRay *)(&solver.m_pTree + 3),
      boxIn: (CTraceAABB *)&rayIVP.m_ooBaseLength,
      pTree,
      axis: &raySrc->m_Start);
    CTraceSolverAABBTree::DoSweep(this: (CTraceSolverAABBTree *)&ivp.m_vertCache[31].z.m128_i16[2]);
    p_x = &p_m_Delta->x;
    ptr->startpos.x = raySrc->m_Start.x + raySrc->m_StartOffset.x;
    ptr->startpos.y = raySrc->m_StartOffset.y + raySrc->m_Start.y;
    ptr->startpos.z = raySrc->m_StartOffset.z + raySrc->m_Start.z;
    fraction = ptr->fraction;
    ptr->endpos.x = (float)(*p_x * fraction) + ptr->startpos.x;
    ptr->endpos.y = (float)(p_x[1] * fraction) + ptr->startpos.y;
    ptr->endpos.z = (float)(p_x[2] * fraction) + ptr->startpos.z;
    if ( ptr->fraction < 1.0 || ptr->allsolid || ptr->startsolid )
      ptr->plane.dist = (float)((float)(ptr->plane.normal.y * ptr->endpos.y)
                              + (float)(ptr->endpos.x * ptr->plane.normal.x))
                      + (float)(ptr->plane.normal.z * ptr->endpos.z);
    m_totalTraceLength_low = LOBYTE(solver.m_totalTraceLength);
    v10[0] = &CTraceIVP::`vftable';
    if ( ivp.m_pSurface != nullptr )
      CTSListBase::Push(this: &g_VisitHashPool, pNode: (TSLNodeBase_t *)&ivp.m_pSurface[-1].dummy[2]);
    return m_totalTraceLength_low;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002F2C0
// Name: public: void CPhysicsTrace::SweepIVP(class Vector const __near &,class Vector const __near &,class CPhysCollide const __near *,class QAngle const __near &,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsTrace::SweepIVP(
        CPhysicsTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *start,
        const Vector *end,
        const CPhysCollide *pSweptSurface,
        const QAngle *sweptAngles,
        const CPhysCollide *pSurface,
        const Vector *surfaceOrigin,
        const QAngle *surfaceAngles,
        CGameTrace *ptr)
{
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  void *v20; // eax
  CPhysCollide_vtbl *v21; // edx
  const IVP_Compact_Surface *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  int v26; // edx
  int v27; // eax
  float v28; // xmm0_4
  __int16 v29; // cx
  CBaseEntity *v30; // eax
  int v31; // ecx
  float fraction; // xmm0_4
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  _DWORD v39[3]; // [esp-Ch] [ebp-F0Ch] BYREF
  CTraceIVP ivp; // [esp+0h] [ebp-F00h] BYREF
  CTraceIVP sweptObject; // [esp+6B0h] [ebp-850h] BYREF
  _BYTE solver_76[256]; // [esp+DACh] [ebp-154h] OVERLAPPED BYREF
  float v43; // [esp+EACh] [ebp-54h]
  CTraceRay ray; // [esp+EB0h] [ebp-50h] BYREF
  IVP_U_BigVector<IVP_Compact_Ledge> objectLedges; // [esp+EF0h] [ebp-10h] BYREF
  void **retaddr; // [esp+F00h] [ebp+0h]

  objectLedges.n_elems = a2;
  objectLedges.elems = retaddr;
  memset(dst: (unsigned __int8 *)ptr, value: 0, count: sizeof(CGameTrace));
  ptr->fraction = 1.0;
  ptr->fractionleftsolid = 0.0;
  ptr->surface = nullsurface;
  CTraceIVP::CTraceIVP(
    this: (CTraceIVP *)&ivp.m_vertCache[31].z.m128_i16[2],
    a2: a3,
    a3: (int)ptr,
    pCollide: pSweptSurface,
    origin: &vec3_origin,
    angles: sweptAngles);
  CTraceIVP::CTraceIVP(
    this: (CTraceIVP *)v39,
    a2: a3,
    a3: (int)ptr,
    pCollide: pSurface,
    origin: &vec3_origin,
    angles: surfaceAngles);
  v12 = start->x - surfaceOrigin->x;
  v13 = start->y - surfaceOrigin->y;
  v14 = start->z - surfaceOrigin->z;
  v15 = end->z - surfaceOrigin->z;
  v16 = (float)(end->x - surfaceOrigin->x) - v12;
  v17 = (float)(end->y - surfaceOrigin->y) - v13;
  *(float *)&solver_76[248] = v12;
  *(float *)&solver_76[252] = v13;
  v18 = v15 - v14;
  ray.m_start.y = v17 + v13;
  ray.m_start.z = v18 + v14;
  v43 = v14;
  v19 = fsqrt((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18));
  ray.m_start.x = v16 + v12;
  ray.m_end.x = v16;
  ray.m_end.y = v17;
  ray.m_end.z = v18;
  ray.m_delta.x = v16;
  ray.m_delta.y = v17;
  ray.m_delta.z = v18;
  ray.m_dir.x = v19;
  ray.m_dir.z = 0.0;
  if ( v19 > 0.0 )
  {
    ray.m_dir.z = 1.0 / v19;
    ray.m_delta.x = (float)(1.0 / v19) * v16;
    ray.m_delta.y = (float)(1.0 / v19) * v17;
    ray.m_delta.z = (float)(1.0 / v19) * v18;
  }
  ray.m_dir.y = v19;
  ray.m_length = 0.0;
  LODWORD(ray.m_baseLength) = 32;
  ray.m_ooBaseLength = 0.0;
  v20 = p_malloc(size: 0x80u);
  v21 = pSweptSurface->__vftable;
  LODWORD(ray.m_bestDist) = v20;
  v22 = (const IVP_Compact_Surface *)((int (__thiscall *)(const CPhysCollide *, float *, int, int))v21->GetCompactSurface)(
                                       a1: pSweptSurface,
                                       a2: &ray.m_baseLength,
                                       a3,
                                       a4);
  IVP_Compact_Ledge_Solver::get_all_ledges(
    surface: v22,
    all_ledges_out: (IVP_U_BigVector<IVP_Compact_Ledge> *)LODWORD(ray.m_bestDist));
  for ( objectLedges.memsize = LODWORD(ray.m_ooBaseLength) - 1; objectLedges.memsize >= 0; --objectLedges.memsize )
  {
    memset(dst: &solver_76[160], value: 0, count: 0x54u);
    *(_DWORD *)&solver_76[204] = 1065353216;
    *(csurface_t *)&solver_76[220] = nullsurface;
    *(_DWORD *)&solver_76[216] = 0;
    CTraceIVP::SetLedge(
      this: (CTraceIVP *)&ivp.m_vertCache[31].z.m128_i16[2],
      pLedge: *(const IVP_Compact_Ledge **)(LODWORD(ray.m_bestDist) + 4 * objectLedges.memsize),
      nIndex: 0);
    v23 = start->x - surfaceOrigin->x;
    v24 = start->y - surfaceOrigin->y;
    v25 = start->z - surfaceOrigin->z;
    *(_DWORD *)&solver_76[24] = &solver_76[160];
    *(_DWORD *)&solver_76[28] = 0;
    *(_DWORD *)&solver_76[12] = &ivp.m_vertCache[31].z.m128_i32[1];
    *(_DWORD *)&solver_76[16] = v39;
    *(_DWORD *)&solver_76[20] = &solver_76[248];
    if ( ray.m_dir.y <= 0.0000000099999999 )
      *(_DWORD *)&solver_76[32] = 841731191;
    else
      *(float *)&solver_76[32] = ray.m_dir.y;
    *(float *)solver_76 = v23;
    *(float *)&solver_76[140] = sweptObject.m_matrix.vv.k[1];
    *(float *)&solver_76[4] = v24;
    *(float *)&solver_76[8] = v25;
    sweptObject.m_vertCache[31].z.m128_i32[1] = (int)&CTraceSolverSweptObject::`vftable';
    *(_DWORD *)&solver_76[56] = &CDefConvexInfo::`vftable';
    *(_DWORD *)&solver_76[44] = v39;
    *(_DWORD *)&solver_76[52] = -1;
    *(_DWORD *)&solver_76[48] = &solver_76[56];
    *(float *)&solver_76[40] = g_PhysicsUnits.globalCollisionTolerance;
    CTraceSolverSweptObject::InitOSRay(
      this: (CTraceSolverSweptObject *)&sweptObject.m_vertCache[31].z.m128_i16[2],
      a2: (int)&objectLedges.n_elems);
    CTraceSolverSweptObject::SweepLedgeTree(
      this: (CTraceSolverSweptObject *)&sweptObject.m_vertCache[31].z.m128_i16[2],
      node: (const IVP_Compact_Ledgetree_Node *)(*(_DWORD *)(*(_DWORD *)&solver_76[44] + 8)
                                         + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&solver_76[44] + 8) + 32)));
    if ( ptr->fraction > *(float *)&solver_76[204] )
    {
      CBaseTrace::operator=(this: ptr, __that: (const CBaseTrace *)&solver_76[160]);
      v26 = *(_DWORD *)&solver_76[224];
      v27 = *(_DWORD *)&solver_76[228];
      v28 = *(float *)&solver_76[216];
      ptr->surface.name = *(const char **)&solver_76[220];
      v29 = *(_WORD *)&solver_76[232];
      *(_DWORD *)&ptr->surface.surfaceProps = v26;
      LOWORD(v26) = *(_WORD *)&solver_76[234];
      ptr->hitgroup = v27;
      v30 = *(CBaseEntity **)&solver_76[236];
      ptr->physicsbone = v29;
      v31 = *(_DWORD *)&solver_76[240];
      ptr->fractionleftsolid = v28;
      ptr->worldSurfaceIndex = v26;
      ptr->m_pEnt = v30;
      ptr->hitbox = v31;
    }
  }
  fraction = ptr->fraction;
  v33 = end->y * fraction;
  v34 = end->z * fraction;
  v35 = 1.0 - fraction;
  v36 = (float)(v35 * start->x) + (float)(ptr->fraction * end->x);
  v37 = (float)(v35 * start->y) + v33;
  v38 = (float)(v35 * start->z) + v34;
  ptr->endpos.x = v36;
  ptr->endpos.y = v37;
  ptr->endpos.z = v38;
  if ( ptr->fraction < 1.0 || ptr->allsolid || ptr->startsolid )
    ptr->plane.dist = (float)((float)(ptr->plane.normal.y * v37) + (float)(v36 * ptr->plane.normal.x))
                    + (float)(ptr->plane.normal.z * ptr->endpos.z);
  if ( (IVP_U_BigVector<IVP_Compact_Ledge> *)LODWORD(ray.m_bestDist) != &objectLedges )
  {
    if ( LODWORD(ray.m_bestDist) != 0 )
      free(data: (void *)LODWORD(ray.m_bestDist));
    ray.m_bestDist = 0.0;
    ray.m_baseLength = 0.0;
  }
  ray.m_ooBaseLength = 0.0;
  v39[0] = &CTraceIVP::`vftable';
  if ( ivp.m_pSurface != nullptr )
    CTSListBase::Push(this: &g_VisitHashPool, pNode: (TSLNodeBase_t *)&ivp.m_pSurface[-1].dummy[2]);
  ivp.m_vertCache[31].z.m128_i32[1] = (int)&CTraceIVP::`vftable';
  if ( sweptObject.m_pSurface != nullptr )
    CTSListBase::Push(this: &g_VisitHashPool, pNode: (TSLNodeBase_t *)&sweptObject.m_pSurface[-1].dummy[2]);
}

//------------------------------------------------------------------------------
// Address: 0x1002F760
// Name: public: void CPhysicsTrace::GetAABB(class Vector __near *,class Vector __near *,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsTrace::GetAABB(
        CPhysicsTrace *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        Vector *pMins,
        Vector *pMaxs,
        const CPhysCollide *pCollide,
        const Vector *collideOrigin,
        const QAngle *collideAngles)
{
  int v8; // eax
  const IVP_Compact_Surface *(__thiscall *GetCompactSurface)(CPhysCollide *); // eax
  int v10; // eax
  const IVP_Compact_Ledgetree_Node *v11; // esi
  _DWORD v12[2]; // [esp-Ch] [ebp-6CCh] BYREF
  int v13; // [esp-4h] [ebp-6C4h]
  CTraceIVP ivp; // [esp+0h] [ebp-6C0h] BYREF
  float v15; // [esp+6B0h] [ebp-10h]
  Vector tmp; // [esp+6B4h] [ebp-Ch] BYREF
  float retaddr; // [esp+6C0h] [ebp+0h]

  tmp.x = a2;
  tmp.y = retaddr;
  CTraceIVP::CTraceIVP(
    this: (CTraceIVP *)v12,
    a2: a3,
    a3: (int)pCollide,
    pCollide,
    origin: collideOrigin,
    angles: collideAngles);
  v8 = v13 + *(_DWORD *)(v13 + 32);
  if ( *(_DWORD *)v8 != 0 )
  {
    GetCompactSurface = pCollide->GetCompactSurface;
    ivp.m_pCollideMap = nullptr;
    ivp.__vftable = nullptr;
    v10 = (int)GetCompactSurface(this: pCollide);
    v11 = (const IVP_Compact_Ledgetree_Node *)(v10 + *(_DWORD *)(v10 + 32));
    ClearBounds(mins: pMins, maxs: pMaxs);
    TraceGetAABB_r(pMins, pMaxs, node: v11, ivp: (CTraceIVP *)v12);
  }
  else
  {
    CTraceIVP::SetLedge(
      this: (CTraceIVP *)v12,
      pLedge: (const IVP_Compact_Ledge *)(v8 + *(_DWORD *)(v8 + 4)),
      nIndex: *(unsigned __int8 *)(v8 + 27));
    CTraceIVP::SupportMap(
      this: (CTraceIVP *)v12,
      a2: (const IVP_U_Float_Point *)&tmp,
      dir: &g_xneg,
      pOut: (Vector *)&ivp.m_vertCache[31].z.m128_u16[4]);
    LODWORD(pMins->x) = ivp.m_vertCache[31].z.m128_i32[2];
    CTraceIVP::SupportMap(
      this: (CTraceIVP *)v12,
      a2: (const IVP_U_Float_Point *)&tmp,
      dir: &g_yneg,
      pOut: (Vector *)&ivp.m_vertCache[31].z.m128_u16[4]);
    LODWORD(pMins->y) = ivp.m_vertCache[31].z.m128_i32[3];
    CTraceIVP::SupportMap(
      this: (CTraceIVP *)v12,
      a2: (const IVP_U_Float_Point *)&tmp,
      dir: &g_zneg,
      pOut: (Vector *)&ivp.m_vertCache[31].z.m128_u16[4]);
    pMins->z = v15;
    CTraceIVP::SupportMap(
      this: (CTraceIVP *)v12,
      a2: (const IVP_U_Float_Point *)&tmp,
      dir: &g_xpos,
      pOut: (Vector *)&ivp.m_vertCache[31].z.m128_u16[4]);
    LODWORD(pMaxs->x) = ivp.m_vertCache[31].z.m128_i32[2];
    CTraceIVP::SupportMap(
      this: (CTraceIVP *)v12,
      a2: (const IVP_U_Float_Point *)&tmp,
      dir: &g_ypos,
      pOut: (Vector *)&ivp.m_vertCache[31].z.m128_u16[4]);
    LODWORD(pMaxs->y) = ivp.m_vertCache[31].z.m128_i32[3];
    CTraceIVP::SupportMap(
      this: (CTraceIVP *)v12,
      a2: (const IVP_U_Float_Point *)&tmp,
      dir: &g_zpos,
      pOut: (Vector *)&ivp.m_vertCache[31].z.m128_u16[4]);
    pMaxs->z = v15;
  }
  v12[0] = &CTraceIVP::`vftable';
  if ( ivp.m_pSurface != nullptr )
    CTSListBase::Push(this: &g_VisitHashPool, pNode: (TSLNodeBase_t *)&ivp.m_pSurface[-1].dummy[2]);
}

//------------------------------------------------------------------------------
// Address: 0x1002F8F0
// Name: public: class Vector CPhysicsTrace::GetExtent(class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
Vector *__userpurge CPhysicsTrace::GetExtent@<eax>(
        CPhysicsTrace *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        Vector *result,
        const CPhysCollide *pCollide,
        const Vector *collideOrigin,
        const QAngle *collideAngles,
        const Vector *direction)
{
  int v8; // eax
  const IVP_Compact_Surface *(__thiscall *GetCompactSurface)(CPhysCollide *); // eax
  int v10; // eax
  const IVP_Compact_Ledgetree_Node *v11; // ecx
  _DWORD v13[2]; // [esp-Ch] [ebp-6CCh] BYREF
  int v14; // [esp-4h] [ebp-6C4h]
  _BYTE ivp[1716]; // [esp+0h] [ebp-6C0h] OVERLAPPED BYREF
  Vector out; // [esp+6B4h] [ebp-Ch] BYREF
  float retaddr; // [esp+6C0h] [ebp+0h]

  out.x = a2;
  out.y = retaddr;
  CTraceIVP::CTraceIVP(
    this: (CTraceIVP *)v13,
    a2: a3,
    a3: (int)pCollide,
    pCollide,
    origin: collideOrigin,
    angles: collideAngles);
  v8 = v14 + *(_DWORD *)(v14 + 32);
  if ( *(_DWORD *)v8 != 0 )
  {
    GetCompactSurface = pCollide->GetCompactSurface;
    *(_DWORD *)&ivp[4] = 0;
    *(_DWORD *)ivp = 0;
    v10 = (int)GetCompactSurface(this: pCollide);
    v11 = (const IVP_Compact_Ledgetree_Node *)(v10 + *(_DWORD *)(v10 + 32));
    *(Vector *)&ivp[1704] = vec3_origin;
    *(_DWORD *)&ivp[1700] = -915135488;
    TraceGetExtent_r(
      node: v11,
      ivp: (CTraceIVP *)v13,
      dir: direction,
      dot: (float *)&ivp[1700],
      point: (Vector *)&ivp[1704]);
  }
  else
  {
    CTraceIVP::SetLedge(
      this: (CTraceIVP *)v13,
      pLedge: (const IVP_Compact_Ledge *)(v8 + *(_DWORD *)(v8 + 4)),
      nIndex: *(unsigned __int8 *)(v8 + 27));
    CTraceIVP::SupportMap(
      this: (CTraceIVP *)v13,
      a2: (const IVP_U_Float_Point *)&out,
      dir: direction,
      pOut: (Vector *)&ivp[1704]);
  }
  *result = *(Vector *)&ivp[1704];
  v13[0] = &CTraceIVP::`vftable';
  if ( *(_DWORD *)&ivp[8] != 0 )
    CTSListBase::Push(this: &g_VisitHashPool, pNode: (TSLNodeBase_t *)(*(_DWORD *)&ivp[8] - 4));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA20
// Name: public: bool CPhysicsTrace::IsBoxIntersectingCone(class Vector const __near &,class Vector const __near &,struct truncatedcone_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CPhysicsTrace::IsBoxIntersectingCone@<al>(
        CPhysicsTrace *this@<ecx>,
        float a2@<ebp>,
        const Vector *boxAbsMins,
        const Vector *boxAbsMaxs,
        const truncatedcone_t *cone)
{
  float x; // xmm1_4
  float v6; // xmm3_4
  bool v7; // zf
  bool v8; // dl
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  __int128 v16; // xmm2
  float y; // xmm5_4
  float z; // xmm6_4
  long double v19; // st7
  float v20; // xmm1_4
  _BYTE v22[92]; // [esp-Ch] [ebp-1ACh] OVERLAPPED BYREF
  _BYTE solver_76[64]; // [esp+A4h] [ebp-FCh] OVERLAPPED
  Vector v24; // [esp+E4h] [ebp-BCh] BYREF
  CTraceRay ray; // [esp+F0h] [ebp-B0h] BYREF
  float v26; // [esp+130h] [ebp-70h]
  CTraceCone traceCone; // [esp+134h] [ebp-6Ch] BYREF
  void **v28; // [esp+16Ch] [ebp-34h] BYREF
  float v29; // [esp+170h] [ebp-30h]
  float v30; // [esp+174h] [ebp-2Ch]
  CTraceAABB box; // [esp+178h] [ebp-28h] BYREF
  _UNKNOWN *retaddr; // [esp+1A0h] [ebp+0h]

  box.m_radius = a2;
  *(_DWORD *)&box.m_empty = retaddr;
  memset(dst: v22, value: 0, count: 0x54u);
  x = boxAbsMaxs->x;
  *(_DWORD *)&v22[60] = nullsurface.name;
  v6 = boxAbsMins->x;
  v7 = x == boxAbsMins->x;
  *(_DWORD *)&v22[44] = 1065353216;
  *(_DWORD *)&v22[56] = 0;
  *(_DWORD *)&v22[64] = *(_DWORD *)&nullsurface.surfaceProps;
  v8 = v7 && boxAbsMaxs->y == boxAbsMins->y && boxAbsMaxs->z == boxAbsMins->z;
  v9 = cone->origin.x;
  v10 = boxAbsMaxs->z - cone->origin.z;
  v11 = boxAbsMins->y - cone->origin.y;
  v12 = boxAbsMins->z - cone->origin.z;
  *(float *)&solver_76[52] = x - cone->origin.x;
  v13 = boxAbsMaxs->y - cone->origin.y;
  v14 = v6 - v9;
  v28 = &CTraceAABB::`vftable';
  if ( v8 )
  {
    v30 = 0.0;
    v29 = 0.0;
    memset(&box, 0, 20);
    LOBYTE(box.m_z[0]) = 1;
  }
  else
  {
    *(float *)&box.__vftable = v13;
    box.m_x[1] = v10;
    v29 = *(float *)&solver_76[52];
    v15 = (float)((float)(v13 * v13) + (float)(v10 * v10)) + (float)(v29 * v29);
    v16 = 0;
    v30 = v14;
    box.m_x[0] = v11;
    box.m_y[0] = v12;
    *(float *)&v16 = fsqrt(v15);
    *(_OWORD *)&solver_76[48] = v16;
    LODWORD(box.m_y[1]) = v16;
    LOBYTE(box.m_z[0]) = 0;
  }
  y = cone->origin.y;
  z = cone->origin.z;
  traceCone.m_cone.origin = cone->normal;
  traceCone.m_cone.normal.x = cone->h;
  traceCone.m_cone.normal.y = cone->theta;
  LODWORD(ray.m_ooBaseLength) = &CTraceCone::`vftable';
  ray.m_bestDist = v9 - v9;
  v26 = y - y;
  *(float *)&traceCone.__vftable = z - z;
  LODWORD(traceCone.m_centerBase.x) = &box.m_z[1];
  LODWORD(traceCone.m_centerBase.y) = &traceCone.m_cone.h;
  traceCone.m_centerBase.z = traceCone.m_cone.normal.y * 0.017453292;
  v19 = (float)(traceCone.m_cone.normal.y * 0.017453292);
  box.m_z[1] = cos(v19);
  traceCone.m_cone.h = sin(v19);
  traceCone.m_cone.normal.z = (float)(traceCone.m_cone.h * traceCone.m_cone.normal.x) / box.m_z[1];
  traceCone.m_cone.theta = (float)(v9 - v9) + (float)(traceCone.m_cone.origin.x * traceCone.m_cone.normal.x);
  v24 = vec3_origin;
  ray.m_start = vec3_origin;
  v20 = sqrt(0.0);
  traceCone.m_radius = (float)(y - y) + (float)(traceCone.m_cone.origin.y * traceCone.m_cone.normal.x);
  traceCone.m_sinTheta = (float)(z - z) + (float)(traceCone.m_cone.origin.z * traceCone.m_cone.normal.x);
  memset(&ray.m_end, 0, 24);
  ray.m_dir.x = v20;
  ray.m_dir.z = 0.0;
  if ( v20 > 0.0 )
  {
    ray.m_dir.z = 1.0 / v20;
    ray.m_delta.x = (float)(1.0 / v20) * 0.0;
    ray.m_delta.y = ray.m_delta.x;
    ray.m_delta.z = ray.m_delta.x;
  }
  ray.m_length = 0.0;
  *(_DWORD *)&solver_76[24] = v22;
  *(_DWORD *)&solver_76[28] = 0;
  ray.m_dir.y = v20;
  *(_DWORD *)&v22[88] = &CTraceSolver::`vftable';
  *(_DWORD *)&solver_76[12] = &v28;
  *(_DWORD *)&solver_76[16] = &ray.m_ooBaseLength;
  *(_DWORD *)&solver_76[20] = &v24;
  if ( v20 <= 0.0000000099999999 )
    *(_DWORD *)&solver_76[32] = 841731191;
  else
    *(float *)&solver_76[32] = v20;
  *(Vector *)solver_76 = *boxAbsMaxs;
  *(float *)&solver_76[40] = g_PhysicsUnits.collisionSweepEpsilon;
  CTraceSolver::DoSweep(this: (CTraceSolver *)&v22[88]);
  return v22[55];
}

//------------------------------------------------------------------------------
// Address: 0x1002FE10
// Name: public: void CPhysicsTrace::SweepBoxIVP(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsTrace::SweepBoxIVP(
        CPhysicsTrace *this@<ecx>,
        int a2@<ebp>,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs,
        const CPhysCollide *pCollide,
        const Vector *surfaceOrigin,
        const QAngle *surfaceAngles,
        CGameTrace *ptr)
{
  _BYTE v11[12]; // [esp-Ch] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a2;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v11, start, end, mins, maxs);
  CPhysicsTrace::SweepBoxIVP(
    this,
    a2: COERCE_FLOAT((Ray_t *)&ray.m_IsRay),
    raySrc: (const Ray_t *)v11,
    contentsMask: 0xFFFFFFFF,
    pConvexInfo: nullptr,
    pCollide,
    surfaceOrigin,
    surfaceAngles,
    ptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002FE80
// Name: void Trace_DestroyAABBTree(class CPhysCollideAABBTree __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Trace_DestroyAABBTree(CPhysCollideAABBTree *pTree)
{
  __m128 *m_pBounds; // eax

  if ( pTree != nullptr )
  {
    m_pBounds = pTree->m_pBounds;
    if ( m_pBounds != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pBounds & 0xFFFFFFFC) - 4));
    CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&pTree->m_pNodes);
    free(data: (void *)pTree);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FEC0
// Name: public: void CPhysCollideAABBTree::Init(class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysCollideAABBTree::Init(
        CPhysCollideAABBTree *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const CPhysCollide *pSurface)
{
  CPhysCollideAABBTree *Next; // esi
  const IVP_Compact_Surface *(__thiscall *GetCompactSurface)(CPhysCollide *); // edx
  int v7; // eax
  int LeafNodesList; // edi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  const IVP_Compact_Ledgetree_Node *v13; // edi
  __m128 *m_pBounds; // eax
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 *v17; // eax
  int v18; // edi
  const IVP_Compact_Surface *m_pSurface; // eax
  TSLNodeBase_t **v20; // esi
  const IVP_Compact_Ledgetree_Node *v22[3]; // [esp-Ch] [ebp-EDCh] BYREF
  const IVP_Compact_Ledgetree_Node *pNodes[512]; // [esp+0h] [ebp-ED0h] BYREF
  CTraceIVP ivp; // [esp+800h] [ebp-6D0h]
  CUtlVector<IVP_Compact_Ledgetree_Node const *,CUtlMemory<IVP_Compact_Ledgetree_Node const *,int> > *p_m_pNodes; // [esp+EB0h] [ebp-20h]
  int v26; // [esp+EB4h] [ebp-1Ch]
  TSLHead_t m_Head; // [esp+EB8h] [ebp-18h]
  int nCount; // [esp+EC0h] [ebp-10h]
  _DWORD v29[2]; // [esp+EC4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+ED0h] [ebp+0h]

  v29[0] = a2;
  v29[1] = retaddr;
  Next = this;
  GetCompactSurface = pSurface->GetCompactSurface;
  m_Head.value.Next = (TSLNodeBase_t *)this;
  v7 = ((int (__thiscall *)(const CPhysCollide *, int, int))GetCompactSurface)(a1: pSurface, a2: a3, a3: a4);
  LeafNodesList = GetLeafNodesList(
                    pRoot: (const IVP_Compact_Ledgetree_Node *)(v7 + *(_DWORD *)(v7 + 32)),
                    pNodesOut: v22);
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v26 = LeafNodesList;
  v10 = (int)Alloc_2(this: _g_pMemAlloc, a2: 32 * LeafNodesList + 19);
  if ( v10 != 0 )
  {
    v11 = (v10 + 19) & 0xFFFFFFF0;
    *(_DWORD *)(v11 - 4) = v10;
  }
  else
  {
    v11 = 0;
  }
  Next->m_pBounds = (__m128 *)v11;
  m_Head.value32.DepthAndSequence = LeafNodesList;
  m_Head.value.Next = nullptr;
  p_m_pNodes = &Next->m_pNodes;
  Next->m_pNodes.m_Size = 0;
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::InsertMultipleBefore(
    this: (CUtlVector<int,CUtlMemory<int,int> > *)&Next->m_pNodes,
    elem: (int)m_Head.value.Next,
    num: m_Head.value32.DepthAndSequence);
  CTraceIVP::CTraceIVP(
    this: (CTraceIVP *)&pNodes[509],
    a2: LeafNodesList,
    a3: (int)Next,
    pCollide: pSurface,
    origin: &vec3_origin,
    angles: &vec3_angle);
  v12 = 0;
  nCount = 0;
  if ( LeafNodesList > 0 )
  {
    m_Head.value32.DepthAndSequence = 0;
    while ( 1 )
    {
      v13 = v22[v12];
      p_m_pNodes->m_Memory.m_pMemory[v12] = v13;
      GetAABBForLedge(
        pNode: v13,
        ivp: (CTraceIVP *)&pNodes[509],
        a3: (int)v29,
        a4: (__m128 *)((char *)Next->m_pBounds + m_Head.value32.DepthAndSequence),
        a5: (__m128 *)((char *)Next->m_pBounds + m_Head.value32.DepthAndSequence + 16));
      m_Head.value32.DepthAndSequence += 32;
      Next = (CPhysCollideAABBTree *)m_Head.value.Next;
      if ( ++nCount >= v26 )
        break;
      v12 = nCount;
    }
    LeafNodesList = v26;
  }
  m_pBounds = Next->m_pBounds;
  v15 = *m_pBounds;
  v16 = m_pBounds[1];
  if ( LeafNodesList > 1 )
  {
    v17 = m_pBounds + 2;
    v18 = LeafNodesList - 1;
    do
    {
      v15 = _mm_min_ps(v15, *v17);
      v16 = _mm_max_ps(v16, v17[1]);
      v17 += 2;
      --v18;
    }
    while ( v18 != 0 );
  }
  m_pSurface = ivp.m_pSurface;
  Next->m_fl4Mins = v15;
  Next->m_fl4Maxs = v16;
  pNodes[509] = (const IVP_Compact_Ledgetree_Node *)&CTraceIVP::`vftable';
  if ( m_pSurface != nullptr )
  {
    v20 = (TSLNodeBase_t **)&m_pSurface[-1].dummy[2];
    m_Head = g_VisitHashPool.m_Head;
    v26 = g_VisitHashPool.m_Head.value32.DepthAndSequence + 65537;
    p_m_pNodes = (CUtlVector<IVP_Compact_Ledgetree_Node const *,CUtlMemory<IVP_Compact_Ledgetree_Node const *,int> > *)v20;
    ivp.m_vertCache[31].z.m128_i32[3] = (int)&g_VisitHashPool;
    for ( *v20 = g_VisitHashPool.m_Head.value.Next;
          (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: ivp.m_vertCache[31].z.m128_i32[3],
                             a2: p_m_pNodes,
                             a3: v26,
                             a4: m_Head.value.Next,
                             a5: m_Head.value32.DepthAndSequence) == 0;
          *v20 = g_VisitHashPool.m_Head.value.Next )
    {
      _mm_pause();
      m_Head = g_VisitHashPool.m_Head;
      v26 = g_VisitHashPool.m_Head.value32.DepthAndSequence + 65537;
      p_m_pNodes = (CUtlVector<IVP_Compact_Ledgetree_Node const *,CUtlMemory<IVP_Compact_Ledgetree_Node const *,int> > *)v20;
      ivp.m_vertCache[31].z.m128_i32[3] = (int)&g_VisitHashPool;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030060
// Name: class CPhysCollideAABBTree __near * Trace_CreateAABBTree(class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideAABBTree *__cdecl Trace_CreateAABBTree(const CPhysCollide *pSurface)
{
  CPhysCollideAABBTree *v1; // esi
  CPhysCollideAABBTree *v2; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v1 = nullptr;
  if ( pSurface == nullptr || pSurface->GetCompactSurface(this: pSurface) == nullptr )
    return nullptr;
  v2 = (CPhysCollideAABBTree *)p_malloc(size: 0x40u);
  if ( v2 != nullptr )
  {
    v2->m_pNodes.m_Memory.m_pMemory = nullptr;
    v2->m_pNodes.m_Memory.m_nAllocationCount = 0;
    v2->m_pNodes.m_Memory.m_nGrowSize = 0;
    v2->m_pNodes.m_Size = 0;
    v2->m_pNodes.m_pElements = nullptr;
    v2->m_pBounds = nullptr;
    v1 = v2;
  }
  CPhysCollideAABBTree::Init(this: v1, a2: (int)&savedregs, a3: (int)pSurface, a4: (int)v1, pSurface);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10021870
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_shadowcontrolparams_t>(struct vphysics_save_shadowcontrolparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_shadowcontrolparams_t>()
{
  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    nameHolder_14.m_pszBase = "vphysics_save_shadowcontrolparams_t";
    nameHolder_14.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_14.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_14.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_14.m_Names.m_Size = 0;
    nameHolder_14.m_Names.m_pElements = nullptr;
    nameHolder_14.m_nLenBase = 35;
    atexit(func: DataMapInit_vphysics_save_shadowcontrolparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_shadowcontrolparams_t::m_DataMap.baseMap = nullptr;
  vphysics_save_shadowcontrolparams_t::m_DataMap.dataNumFields = 8;
  vphysics_save_shadowcontrolparams_t::m_DataMap.dataDesc = &dataDesc_14[1];
  return &vphysics_save_shadowcontrolparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100218F0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_cshadowcontroller_t>(struct vphysics_save_cshadowcontroller_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_cshadowcontroller_t>()
{
  ISaveRestoreOps *v0; // eax

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    nameHolder_15.m_pszBase = "vphysics_save_cshadowcontroller_t";
    nameHolder_15.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_15.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_15.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_15.m_Names.m_Size = 0;
    nameHolder_15.m_Names.m_pElements = nullptr;
    nameHolder_15.m_nLenBase = 33;
    atexit(func: DataMapInit_vphysics_save_cshadowcontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_cshadowcontroller_t::m_DataMap.baseMap = nullptr;
  if ( (_S2_1 & 2) == 0 )
  {
    _S2_1 |= 2u;
    v0 = MaterialIndexDataOps();
    *(_QWORD *)dataDesc_15[8].flatOffset = 0;
    dataDesc_15[7].pSaveRestoreOps = v0;
    *(_QWORD *)dataDesc_15[9].flatOffset = 0;
    dataDesc_15[8].fieldType = FIELD_BOOLEAN;
    dataDesc_15[8].fieldSize = 1;
    dataDesc_15[9].fieldType = FIELD_BOOLEAN;
    dataDesc_15[9].fieldSize = 1;
    dataDesc_15[10].fieldType = FIELD_BOOLEAN;
    dataDesc_15[10].fieldSize = 1;
    dataDesc_15[11].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)&dataDesc_15[7].td = 0;
    *(_QWORD *)&dataDesc_15[7].override_field = 0;
    *(_QWORD *)&dataDesc_15[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_15[7].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_15[10].flatOffset = 0;
    dataDesc_15[7].inputFunc = nullptr;
    dataDesc_15[8].fieldName = "enable";
    dataDesc_15[8].fieldOffset = 76;
    dataDesc_15[8].flags = 2;
    dataDesc_15[8].externalName = nullptr;
    dataDesc_15[8].pSaveRestoreOps = nullptr;
    dataDesc_15[8].inputFunc = nullptr;
    dataDesc_15[8].td = nullptr;
    dataDesc_15[8].fieldSizeInBytes = 1;
    dataDesc_15[8].override_field = nullptr;
    dataDesc_15[8].override_count = 0;
    dataDesc_15[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_15[8].flatGroup = 0;
    dataDesc_15[9].fieldName = "allowPhysicsMovement";
    dataDesc_15[9].fieldOffset = 77;
    dataDesc_15[9].flags = 2;
    dataDesc_15[9].externalName = nullptr;
    dataDesc_15[9].pSaveRestoreOps = nullptr;
    dataDesc_15[9].inputFunc = nullptr;
    dataDesc_15[9].td = nullptr;
    dataDesc_15[9].fieldSizeInBytes = 1;
    dataDesc_15[9].override_field = nullptr;
    dataDesc_15[9].override_count = 0;
    dataDesc_15[9].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_15[9].flatGroup = 0;
    dataDesc_15[10].fieldName = "allowPhysicsRotation";
    dataDesc_15[10].fieldOffset = 78;
    dataDesc_15[10].flags = 2;
    dataDesc_15[10].externalName = nullptr;
    dataDesc_15[10].pSaveRestoreOps = nullptr;
    dataDesc_15[10].inputFunc = nullptr;
    dataDesc_15[10].td = nullptr;
    dataDesc_15[10].fieldSizeInBytes = 1;
    dataDesc_15[10].override_field = nullptr;
    dataDesc_15[10].override_count = 0;
    dataDesc_15[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_15[10].flatGroup = 0;
    dataDesc_15[11].fieldName = "isPhysicallyControlled";
    dataDesc_15[11].fieldOffset = 79;
    *(_DWORD *)&dataDesc_15[11].fieldSize = 131073;
    dataDesc_15[11].externalName = nullptr;
    dataDesc_15[11].pSaveRestoreOps = nullptr;
    dataDesc_15[11].inputFunc = nullptr;
    dataDesc_15[11].td = nullptr;
    dataDesc_15[11].fieldSizeInBytes = 1;
    dataDesc_15[11].override_field = nullptr;
    dataDesc_15[11].override_count = 0;
    dataDesc_15[11].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_15[11].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[11].flatGroup = 0;
    dataDesc_15[12].fieldType = FIELD_EMBEDDED;
    dataDesc_15[12].fieldName = "shadowParams";
    dataDesc_15[12].fieldTolerance = 0.0;
    dataDesc_15[12].fieldOffset = 80;
    *(_DWORD *)&dataDesc_15[12].fieldSize = 131073;
    dataDesc_15[12].externalName = nullptr;
    dataDesc_15[12].pSaveRestoreOps = nullptr;
    dataDesc_15[12].inputFunc = nullptr;
    dataDesc_15[12].td = &vphysics_save_shadowcontrolparams_t::m_DataMap;
    dataDesc_15[12].fieldSizeInBytes = 48;
    dataDesc_15[12].override_field = nullptr;
    dataDesc_15[12].override_count = 0;
    *(_QWORD *)dataDesc_15[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_15[12].flatGroup = 0;
  }
  vphysics_save_cshadowcontroller_t::m_DataMap.dataNumFields = 12;
  vphysics_save_cshadowcontroller_t::m_DataMap.dataDesc = &dataDesc_15[1];
  return &vphysics_save_cshadowcontroller_t::m_DataMap;
}
