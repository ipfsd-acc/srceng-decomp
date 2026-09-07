// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_material.cpp
// Functions: 29
// ============================================================

#include "vphysics\physics_material.h"

//------------------------------------------------------------------------------
// Address: 0x10016E50
// Name: public: class CUtlSymbol CUtlSymbolTableMT::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbol *__thiscall CUtlSymbolTableMT::AddString(CUtlSymbolTableMT *this, CUtlSymbol *result, const char *pString)
{
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)&this->m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &this->m_lock);
  }
  else
  {
    this->m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::AddString(this, result, pString);
  this->m_lock.m_writerId = 0;
  this->m_lock.m_lockInfo.m_i32 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016EC0
// Name: public: virtual float CSurface::get_damping(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSurface::get_damping(CSurface *this)
{
  return this->data.physics.dampening;
}

//------------------------------------------------------------------------------
// Address: 0x10016ED0
// Name: public: char const __near * CPhysicsSurfaceProps::GetNameString(class CUtlSymbol)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysicsSurfaceProps::GetNameString(CPhysicsSurfaceProps *this, CUtlSymbol name)
{
  CUtlSymbolTableMT *p_m_strings; // edi
  CThreadSpinRWLock *p_m_lock; // esi
  signed __int32 m_i32; // ecx
  const char *result; // eax

  p_m_strings = &this->m_strings;
  p_m_lock = &this->m_strings.m_lock;
  if ( (this->m_strings.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &p_m_strings->m_lock);
  }
  result = CUtlSymbolTable::String(this: p_m_strings, id: name);
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016F40
// Name: public: virtual char const __near * CSurface::get_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSurface::get_name(CSurface *this)
{
  int m_nReaders; // ecx
  const char *result; // eax
  unsigned __int16 m_Id; // [esp+6h] [ebp-2h]

  m_Id = this->m_name.m_Id;
  if ( (g_SurfaceDatabase.m_strings.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_nReaders = g_SurfaceDatabase.m_strings.m_lock.m_lockInfo.m_nReaders,
        _InterlockedCompareExchange(
          (volatile signed __int32 *)&g_SurfaceDatabase.m_strings.m_lock,
          g_SurfaceDatabase.m_strings.m_lock.m_lockInfo.m_nReaders + 1,
          g_SurfaceDatabase.m_strings.m_lock.m_lockInfo.m_nReaders) != m_nReaders) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &g_SurfaceDatabase.m_strings.m_lock);
  }
  result = CUtlSymbolTable::String(this: &g_SurfaceDatabase.m_strings, id: (CUtlSymbol)m_Id);
  _InterlockedExchangeAdd((volatile signed __int32 *)&g_SurfaceDatabase.m_strings.m_lock, 0xFFFFFFFF);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016FB0
// Name: public: virtual char const __near * CPhysicsSurfaceProps::GetString(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysicsSurfaceProps::GetString(CPhysicsSurfaceProps *this, unsigned __int16 stringTableIndex)
{
  CUtlSymbolTableMT *p_m_strings; // edi
  CThreadSpinRWLock *p_m_lock; // esi
  signed __int32 m_i32; // ecx
  const char *result; // eax

  p_m_strings = &this->m_strings;
  p_m_lock = &this->m_strings.m_lock;
  if ( (this->m_strings.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: p_m_lock);
  }
  result = CUtlSymbolTable::String(this: p_m_strings, id: (CUtlSymbol)stringTableIndex);
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017010
// Name: public: virtual char const __near * CPhysicsSurfaceProps::GetReservedMaterialName(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysicsSurfaceProps::GetReservedMaterialName(CPhysicsSurfaceProps *this, int materialIndex)
{
  return materialIndex != 61440 ? nullptr : "$MATERIAL_INDEX_SHADOW";
}

//------------------------------------------------------------------------------
// Address: 0x10017030
// Name: public: virtual class ISaveRestoreOps __near * CPhysicsSurfaceProps::GetMaterialIndexDataOps(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
CMaterialIndexOps *__thiscall CPhysicsSurfaceProps::GetMaterialIndexDataOps(CPhysicsSurfaceProps *this)
{
  return MaterialIndexDataOps();
}

//------------------------------------------------------------------------------
// Address: 0x10017040
// Name: public: virtual float CIVPMaterialManager::get_elasticity(struct IVP_Contact_Situation __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CIVPMaterialManager::get_elasticity(CIVPMaterialManager *this, IVP_Contact_Situation *situation)
{
  double result; // st7
  float flElasticity; // [esp+8h] [ebp+8h]

  result = IVP_Material_Manager::get_elasticity(this, sit: situation);
  if ( result > 1.0 )
    return 1.0;
  flElasticity = result;
  if ( flElasticity < 0.0 )
    return 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017090
// Name: public: virtual class IVP_Material __near * CIVPMaterialManager::get_material_by_index(class IVP_Real_Object __near *,class IVP_U_Point const __near *,int)
// Source: json
//------------------------------------------------------------------------------
IVP_Material *__thiscall CIVPMaterialManager::get_material_by_index(
        CIVPMaterialManager *this,
        IVP_Real_Object *pObject,
        const IVP_U_Point *world_position,
        int index)
{
  int v4; // eax
  IVP_Material *result; // eax

  v4 = index;
  if ( index <= 127 )
    v4 = this->m_propMap[index];
  result = this->m_props->GetIVPMaterial(this: this->m_props, a2: v4);
  if ( result == nullptr )
    return this->m_props->GetIVPMaterial(this: this->m_props, a2: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017100
// Name: public: virtual float CIVPMaterialManager::get_friction_factor(struct IVP_Contact_Situation __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CIVPMaterialManager::get_friction_factor(CIVPMaterialManager *this, IVP_Contact_Situation *situation)
{
  double friction_factor; // st7
  float v5; // xmm0_4
  IVP_Real_Object *v6; // [esp-14h] [ebp-18h]
  IVP_Real_Object *v7; // [esp-10h] [ebp-14h]
  float wheelFriction; // [esp+0h] [ebp-4h] BYREF
  float factor; // [esp+Ch] [ebp+8h]

  wheelFriction = *(float *)&this;
  v7 = situation->objects[1];
  v6 = situation->objects[0];
  wheelFriction = 1.0;
  if ( ShouldOverrideWheelContactFriction(
         pFrictionOut: &wheelFriction,
         pivp0: v6,
         pivp1: v7,
         pNormal: &situation->surf_normal) )
  {
    return wheelFriction;
  }
  friction_factor = IVP_Material_Manager::get_friction_factor(this, sit: situation);
  if ( friction_factor < 0.0 )
    return 0.0;
  v5 = friction_factor;
  factor = friction_factor;
  if ( factor <= 1.0 )
    return v5;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10017190
// Name: public: virtual int CPhysicsSurfaceProps::SurfacePropCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsSurfaceProps::SurfacePropCount(CPhysicsSurfaceProps *this)
{
  return this->m_props.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100171A0
// Name: public: virtual void CPhysicsSurfaceProps::SetWorldMaterialIndexTable(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSurfaceProps::SetWorldMaterialIndexTable(
        CPhysicsSurfaceProps *this,
        int *pMapArray,
        int mapSize)
{
  int v3; // edx
  int v4; // eax
  unsigned __int16 *m_propMap; // ecx

  v3 = mapSize;
  if ( mapSize > 128 )
    v3 = 128;
  v4 = 0;
  if ( v3 > 0 )
  {
    m_propMap = this->m_ivpManager.m_propMap;
    do
      *m_propMap++ = pMapArray[v4++];
    while ( v4 < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017320
// Name: public: virtual int CPhysicsSurfaceProps::GetSurfaceIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsSurfaceProps::GetSurfaceIndex(CPhysicsSurfaceProps *this, const char *pPropertyName)
{
  int result; // eax
  CThreadSpinRWLock *p_m_lock; // esi
  int m_Size; // edx
  CUtlSymbol *i; // ecx
  CUtlSymbol id; // [esp+4h] [ebp-4h] BYREF

  if ( *pPropertyName == 36 && _V_stricmp(s1: pPropertyName, s2: "$MATERIAL_INDEX_SHADOW") == 0 )
    return 61440;
  p_m_lock = &this->m_strings.m_lock;
  if ( (this->m_strings.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &this->m_strings.m_lock);
  }
  else
  {
    this->m_strings.m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::Find(this: &this->m_strings, result: &id, pString: pPropertyName);
  result = 0;
  this->m_strings.m_lock.m_writerId = 0;
  p_m_lock->m_lockInfo.m_i32 = 0;
  if ( id.m_Id == 0xFFFF )
    return -1;
  m_Size = this->m_props.m_Size;
  if ( m_Size <= 0 )
    return -1;
  for ( i = &this->m_props.m_Memory.m_pMemory->m_name; i->m_Id != id.m_Id; i += 60 )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100173D0
// Name: public: virtual void CPhysicsSurfaceProps::GetPhysicsProperties(int,float __near *,float __near *,float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSurfaceProps::GetPhysicsProperties(
        CPhysicsSurfaceProps *this,
        int materialIndex,
        float *density,
        float *thickness,
        float *friction,
        float *elasticity)
{
  int m_shadowFallback; // eax
  CSurface *m_pMemory; // eax

  m_shadowFallback = materialIndex;
  if ( materialIndex > 127 )
  {
    if ( materialIndex != 61440 )
    {
      m_shadowFallback = 0;
      goto LABEL_6;
    }
    m_shadowFallback = this->m_shadowFallback;
  }
  if ( m_shadowFallback < 0 )
  {
LABEL_8:
    m_pMemory = nullptr;
    goto LABEL_9;
  }
LABEL_6:
  if ( m_shadowFallback > this->m_props.m_Size - 1 )
    goto LABEL_8;
  m_pMemory = &this->m_props.m_Memory.m_pMemory[m_shadowFallback];
LABEL_9:
  if ( m_pMemory != nullptr
    || (this->m_props.m_Size - 1 < 0 ? (m_pMemory = nullptr) : (m_pMemory = this->m_props.m_Memory.m_pMemory),
        m_pMemory != nullptr) )
  {
    if ( friction != nullptr )
      *friction = m_pMemory->data.physics.friction;
    if ( elasticity != nullptr )
      *elasticity = m_pMemory->data.physics.elasticity;
    if ( density != nullptr )
      *density = m_pMemory->data.physics.density;
    if ( thickness != nullptr )
      *thickness = m_pMemory->data.physics.thickness;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017460
// Name: public: virtual void CPhysicsSurfaceProps::GetPhysicsParameters(int,struct surfacephysicsparams_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSurfaceProps::GetPhysicsParameters(
        CPhysicsSurfaceProps *this,
        int surfaceDataIndex,
        surfacephysicsparams_t *pParamsOut)
{
  int m_shadowFallback; // eax
  CSurface *v4; // eax

  if ( pParamsOut == nullptr )
    return;
  m_shadowFallback = surfaceDataIndex;
  if ( surfaceDataIndex <= 127 )
    goto LABEL_6;
  if ( surfaceDataIndex == 61440 )
  {
    m_shadowFallback = this->m_shadowFallback;
LABEL_6:
    if ( m_shadowFallback < 0 )
      return;
    goto LABEL_7;
  }
  m_shadowFallback = 0;
LABEL_7:
  if ( m_shadowFallback <= this->m_props.m_Size - 1 )
  {
    v4 = &this->m_props.m_Memory.m_pMemory[m_shadowFallback];
    if ( v4 != nullptr )
      *pParamsOut = v4->data.physics;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100174C0
// Name: public: virtual struct surfacedata_t __near * CPhysicsSurfaceProps::GetSurfaceData(int)
// Source: json
//------------------------------------------------------------------------------
surfacedata_t *__thiscall CPhysicsSurfaceProps::GetSurfaceData(CPhysicsSurfaceProps *this, int materialIndex)
{
  int m_shadowFallback; // eax
  CSurface *v3; // eax

  m_shadowFallback = materialIndex;
  if ( materialIndex > 127 )
  {
    if ( materialIndex != 61440 )
    {
      m_shadowFallback = 0;
LABEL_6:
      if ( m_shadowFallback <= this->m_props.m_Size - 1 )
      {
        v3 = &this->m_props.m_Memory.m_pMemory[m_shadowFallback];
        if ( v3 != nullptr )
          return &v3->data;
      }
      goto LABEL_8;
    }
    m_shadowFallback = this->m_shadowFallback;
  }
  if ( m_shadowFallback >= 0 )
    goto LABEL_6;
LABEL_8:
  if ( this->m_props.m_Size - 1 >= 0 )
    return &this->m_props.m_Memory.m_pMemory->data;
  v3 = nullptr;
  return &v3->data;
}

//------------------------------------------------------------------------------
// Address: 0x10017520
// Name: public: virtual class IVP_Material __near * CPhysicsSurfaceProps::GetIVPMaterial(int)
// Source: json
//------------------------------------------------------------------------------
CSurface *__thiscall CPhysicsSurfaceProps::GetIVPMaterial(CPhysicsSurfaceProps *this, int materialIndex)
{
  int m_shadowFallback; // eax

  m_shadowFallback = materialIndex;
  if ( materialIndex <= 127 )
  {
LABEL_5:
    if ( m_shadowFallback < 0 )
      return nullptr;
    goto LABEL_6;
  }
  if ( materialIndex == 61440 )
  {
    m_shadowFallback = this->m_shadowFallback;
    goto LABEL_5;
  }
  m_shadowFallback = 0;
LABEL_6:
  if ( m_shadowFallback <= this->m_props.m_Size - 1 )
    return &this->m_props.m_Memory.m_pMemory[m_shadowFallback];
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10017560
// Name: public: virtual int CPhysicsSurfaceProps::GetIVPMaterialIndex(class IVP_Material const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsSurfaceProps::GetIVPMaterialIndex(CPhysicsSurfaceProps *this, const IVP_Material *pIVP)
{
  int result; // eax

  result = ((char *)pIVP - (char *)this->m_props.m_Memory.m_pMemory) / 120;
  if ( result < 0 || result >= this->m_props.m_Size )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017590
// Name: private: void CPhysicsSurfaceProps::CopyPhysicsProperties(class CSurface __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSurfaceProps::CopyPhysicsProperties(CPhysicsSurfaceProps *this, CSurface *pOut, int baseIndex)
{
  int m_shadowFallback; // eax
  CSurface *v4; // eax

  m_shadowFallback = baseIndex;
  if ( baseIndex <= 127 )
  {
LABEL_5:
    if ( m_shadowFallback < 0 )
      return;
    goto LABEL_6;
  }
  if ( baseIndex == 61440 )
  {
    m_shadowFallback = this->m_shadowFallback;
    goto LABEL_5;
  }
  m_shadowFallback = 0;
LABEL_6:
  if ( m_shadowFallback <= this->m_props.m_Size - 1 )
  {
    v4 = &this->m_props.m_Memory.m_pMemory[m_shadowFallback];
    if ( v4 != nullptr )
      qmemcpy(&pOut->data, &v4->data, sizeof(pOut->data));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017660
// Name: public: virtual char const __near * CPhysicsSurfaceProps::GetPropName(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysicsSurfaceProps::GetPropName(CPhysicsSurfaceProps *this, int surfaceDataIndex)
{
  int m_shadowFallback; // eax
  CSurface *v3; // eax

  m_shadowFallback = surfaceDataIndex;
  if ( surfaceDataIndex <= 127 )
  {
LABEL_5:
    if ( m_shadowFallback < 0 )
      return nullptr;
    goto LABEL_6;
  }
  if ( surfaceDataIndex == 61440 )
  {
    m_shadowFallback = this->m_shadowFallback;
    goto LABEL_5;
  }
  m_shadowFallback = 0;
LABEL_6:
  if ( m_shadowFallback <= this->m_props.m_Size - 1 )
  {
    v3 = &this->m_props.m_Memory.m_pMemory[m_shadowFallback];
    if ( v3 != nullptr )
      return CPhysicsSurfaceProps::GetNameString(this, name: v3->m_name);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10017840
// Name: public: virtual CPhysicsSurfaceProps::~CPhysicsSurfaceProps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSurfaceProps::~CPhysicsSurfaceProps(CPhysicsSurfaceProps *this)
{
  this->__vftable = (CPhysicsSurfaceProps_vtbl *)&CPhysicsSurfaceProps::`vftable';
  this->m_ivpManager.__vftable = (CIVPMaterialManager_vtbl *)&IVP_Material_Manager::`vftable';
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_fileList);
  CUtlVector<CSurface,CUtlMemory<CSurface,int>>::Purge(this: &this->m_props);
  if ( this->m_props.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_props.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_props.m_Memory.m_pMemory);
      this->m_props.m_Memory.m_pMemory = nullptr;
    }
    this->m_props.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_strings);
  this->__vftable = (CPhysicsSurfaceProps_vtbl *)&IPhysicsSurfaceProps::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100178A0
// Name: public: virtual class IVP_Material_Manager __near * CPhysicsSurfaceProps::GetIVPManager(void)
// Source: json
//------------------------------------------------------------------------------
CIVPMaterialManager *__thiscall CPhysicsSurfaceProps::GetIVPManager(CPhysicsSurfaceProps *this)
{
  return &this->m_ivpManager;
}

//------------------------------------------------------------------------------
// Address: 0x100178B0
// Name: public: virtual int CPhysicsSurfaceProps::RemapIVPMaterialIndex(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsSurfaceProps::RemapIVPMaterialIndex(CPhysicsSurfaceProps *this, int ivpMaterialIndex)
{
  int result; // eax

  result = ivpMaterialIndex;
  if ( ivpMaterialIndex <= 127 )
    return this->m_ivpManager.m_propMap[ivpMaterialIndex];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017900
// Name: private: bool CPhysicsSurfaceProps::AddFileToDatabase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsSurfaceProps::AddFileToDatabase(CPhysicsSurfaceProps *this, const char *pFilename)
{
  int v3; // eax
  int m_Size; // ecx
  CUtlSymbol *v5; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbol *m_pMemory; // ecx
  int v9; // eax
  CUtlSymbol *v10; // edi
  CUtlSymbol id; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_strings.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)&this->m_strings.m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &this->m_strings.m_lock);
  }
  else
  {
    this->m_strings.m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::AddString(this: &this->m_strings, result: &id, pString: pFilename);
  v3 = 0;
  this->m_strings.m_lock.m_writerId = 0;
  this->m_strings.m_lock.m_lockInfo.m_i32 = 0;
  m_Size = this->m_fileList.m_Size;
  if ( m_Size <= 0 )
  {
LABEL_9:
    m_nAllocationCount = this->m_fileList.m_Memory.m_nAllocationCount;
    v7 = this->m_fileList.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlSymbol,int>::Grow(this: &this->m_fileList.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++this->m_fileList.m_Size;
    m_pMemory = this->m_fileList.m_Memory.m_pMemory;
    v9 = this->m_fileList.m_Size - v7 - 1;
    this->m_fileList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 2 * v9);
    v10 = &this->m_fileList.m_Memory.m_pMemory[v7];
    if ( v10 != nullptr )
      v10->m_Id = id.m_Id;
    return 1;
  }
  else
  {
    v5 = this->m_fileList.m_Memory.m_pMemory;
    while ( v5->m_Id != id.m_Id )
    {
      ++v3;
      ++v5;
      if ( v3 >= m_Size )
        goto LABEL_9;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100179E0
// Name: public: virtual int CPhysicsSurfaceProps::ParseSurfaceData(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsSurfaceProps::ParseSurfaceData(
        CPhysicsSurfaceProps *this,
        const char *pFileName,
        const char *pTextfile)
{
  CPhysicsSurfaceProps *v3; // edi
  const char *v5; // esi
  CUtlSymbolTableMT *p_m_strings; // ebx
  unsigned __int16 v7; // dx
  CPhysicsSurfaceProps_vtbl *v8; // eax
  int m_shadowFallback; // eax
  int v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // eax
  CThreadSpinRWLock::LockInfo_t m_lockInfo; // ecx
  volatile signed __int32 *p_m_lock; // esi
  signed __int32 v16; // ecx
  const char *v17; // eax
  CPhysicsSurfaceProps *v18; // esi
  int v19; // eax
  const char *v20; // eax
  int m_Size; // eax
  char key[1024]; // [esp+Ch] [ebp-918h] BYREF
  char value[1024]; // [esp+40Ch] [ebp-518h] BYREF
  CSurface pOut; // [esp+80Ch] [ebp-118h] BYREF
  CSurface prop; // [esp+884h] [ebp-A0h] BYREF
  CUtlSymbol v26; // [esp+8FEh] [ebp-26h] BYREF
  CUtlSymbol v27; // [esp+900h] [ebp-24h] BYREF
  CUtlSymbol v28; // [esp+902h] [ebp-22h] BYREF
  CUtlSymbol v29; // [esp+904h] [ebp-20h] BYREF
  CUtlSymbol v30; // [esp+906h] [ebp-1Eh] BYREF
  CUtlSymbol v31; // [esp+908h] [ebp-1Ch] BYREF
  CUtlSymbol v32; // [esp+90Ah] [ebp-1Ah] BYREF
  CUtlSymbol v33; // [esp+90Ch] [ebp-18h] BYREF
  CUtlSymbol v34; // [esp+90Eh] [ebp-16h] BYREF
  CUtlSymbol v35; // [esp+910h] [ebp-14h] BYREF
  CUtlSymbol v36; // [esp+912h] [ebp-12h] BYREF
  CUtlSymbol v37; // [esp+914h] [ebp-10h] BYREF
  CUtlSymbol v38; // [esp+916h] [ebp-Eh] BYREF
  CUtlSymbol v39; // [esp+918h] [ebp-Ch] BYREF
  CUtlSymbol v40; // [esp+91Ah] [ebp-Ah] BYREF
  const char *pText; // [esp+91Ch] [ebp-8h]
  CPhysicsSurfaceProps *v42; // [esp+920h] [ebp-4h]

  v3 = this;
  v42 = this;
  if ( CPhysicsSurfaceProps::AddFileToDatabase(this, pFilename: pFileName) == 0 )
    return 0;
  v5 = pTextfile;
  do
  {
    v5 = ParseKeyvalue(pBuffer: v5, key, value);
    pText = v5;
    if ( strcmp(value, "{") != 0 )
      continue;
    prop.second_friction_x_enabled = IVP_FALSE;
    prop.__vftable = (CSurface_vtbl *)&CSurface::`vftable';
    prop.m_name.m_Id = -1;
    memset(dst: (unsigned __int8 *)&prop.data, value: 0, count: sizeof(prop.data));
    p_m_strings = &v3->m_strings;
    if ( (v3->m_strings.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || _InterlockedCompareExchange((volatile signed __int32 *)&v3->m_strings.m_lock, 0x10000, 0) != 0 )
    {
      CThreadSpinRWLock::SpinLockForWrite(this: &v3->m_strings.m_lock);
    }
    else
    {
      v3->m_strings.m_lock.m_writerId = GetCurrentThreadId();
    }
    CUtlSymbolTable::AddString(this: &v3->m_strings, result: (CUtlSymbol *)&pFileName + 1, pString: key);
    v7 = HIWORD(pFileName);
    v3->m_strings.m_lock.m_writerId = 0;
    v3->m_strings.m_lock.m_lockInfo.m_i32 = 0;
    v8 = v3->__vftable;
    prop.m_name.m_Id = v7;
    m_shadowFallback = v8->GetSurfaceIndex(this: v3, a2: key);
    if ( m_shadowFallback < 0 )
      m_shadowFallback = 0;
    if ( m_shadowFallback <= 127 )
      goto LABEL_15;
    if ( m_shadowFallback == 61440 )
    {
      m_shadowFallback = v3->m_shadowFallback;
LABEL_15:
      if ( m_shadowFallback < 0 )
        goto LABEL_20;
      v3 = v42;
      goto LABEL_17;
    }
    m_shadowFallback = 0;
LABEL_17:
    if ( m_shadowFallback <= v3->m_props.m_Size - 1 )
    {
      v10 = (int)&v42->m_props.m_Memory.m_pMemory[m_shadowFallback];
      if ( v10 != 0 )
        prop.data = *(surfacedata_t *)(v10 + 16);
    }
LABEL_20:
    while ( 1 )
    {
      pText = ParseKeyvalue(pBuffer: pText, key, value);
      if ( _V_stricmp(s1: key, s2: "}") == 0 )
        break;
      if ( _V_stricmp(s1: key, s2: "base") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "thickness") != 0 )
        {
          if ( _V_stricmp(s1: key, s2: "density") != 0 )
          {
            if ( _V_stricmp(s1: key, s2: "elasticity") != 0 )
            {
              if ( _V_stricmp(s1: key, s2: "friction") != 0 )
              {
                if ( _V_stricmp(s1: key, s2: "maxspeedfactor") != 0 )
                {
                  if ( _V_stricmp(s1: key, s2: "jumpfactor") != 0 )
                  {
                    if ( _V_stricmp(s1: key, s2: "climbable") != 0 )
                    {
                      if ( _V_stricmp(s1: key, s2: "audioReflectivity") != 0 )
                      {
                        if ( _V_stricmp(s1: key, s2: "audioHardnessFactor") != 0 )
                        {
                          if ( _V_stricmp(s1: key, s2: "audioHardMinVelocity") != 0 )
                          {
                            if ( _V_stricmp(s1: key, s2: "audioRoughnessFactor") != 0 )
                            {
                              if ( _V_stricmp(s1: key, s2: "scrapeRoughThreshold") != 0 )
                              {
                                if ( _V_stricmp(s1: key, s2: "impactHardThreshold") != 0 )
                                {
                                  if ( _V_stricmp(s1: key, s2: "stepleft") != 0 )
                                  {
                                    if ( _V_stricmp(s1: key, s2: "stepright") != 0 )
                                    {
                                      if ( _V_stricmp(s1: key, s2: "walkLeft") != 0 )
                                      {
                                        if ( _V_stricmp(s1: key, s2: "walkRight") != 0 )
                                        {
                                          if ( _V_stricmp(s1: key, s2: "runLeft") != 0 )
                                          {
                                            if ( _V_stricmp(s1: key, s2: "runRight") != 0 )
                                            {
                                              if ( _V_stricmp(s1: key, s2: "impactsoft") != 0 )
                                              {
                                                if ( _V_stricmp(s1: key, s2: "impacthard") != 0 )
                                                {
                                                  if ( _V_stricmp(s1: key, s2: "scrapesmooth") != 0 )
                                                  {
                                                    if ( _V_stricmp(s1: key, s2: "scraperough") != 0 )
                                                    {
                                                      if ( _V_stricmp(s1: key, s2: "bulletimpact") != 0 )
                                                      {
                                                        if ( _V_stricmp(s1: key, s2: "break") != 0 )
                                                        {
                                                          if ( _V_stricmp(s1: key, s2: "strain") != 0 )
                                                          {
                                                            if ( _V_stricmp(s1: key, s2: "rolling") != 0 )
                                                            {
                                                              if ( _V_stricmp(s1: key, s2: "gamematerial") != 0 )
                                                              {
                                                                if ( _V_stricmp(s1: key, s2: "dampening") == 0 )
                                                                  prop.data.physics.dampening = atof(nptr: value);
                                                              }
                                                              else if ( strlen(value) != 1 || isdigit(c: value[0]) != 0 )
                                                              {
                                                                prop.data.game.material = atoi(nptr: value);
                                                              }
                                                              else
                                                              {
                                                                prop.data.game.material = toupper(c: value[0]);
                                                              }
                                                            }
                                                            else
                                                            {
                                                              prop.data.sounds.rolling = CUtlSymbolTableMT::AddString(
                                                                                           this: p_m_strings,
                                                                                           result: &v36,
                                                                                           pString: value)->m_Id;
                                                            }
                                                          }
                                                          else
                                                          {
                                                            prop.data.sounds.strainSound = CUtlSymbolTableMT::AddString(
                                                                                             this: p_m_strings,
                                                                                             result: &v38,
                                                                                             pString: value)->m_Id;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          prop.data.sounds.breakSound = CUtlSymbolTableMT::AddString(
                                                                                          this: p_m_strings,
                                                                                          result: &v39,
                                                                                          pString: value)->m_Id;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        prop.data.sounds.bulletImpact = CUtlSymbolTableMT::AddString(
                                                                                          this: p_m_strings,
                                                                                          result: &v40,
                                                                                          pString: value)->m_Id;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      prop.data.sounds.scrapeRough = CUtlSymbolTableMT::AddString(
                                                                                       this: p_m_strings,
                                                                                       result: &v27,
                                                                                       pString: value)->m_Id;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    prop.data.sounds.scrapeSmooth = CUtlSymbolTableMT::AddString(
                                                                                      this: p_m_strings,
                                                                                      result: &v33,
                                                                                      pString: value)->m_Id;
                                                  }
                                                }
                                                else
                                                {
                                                  prop.data.sounds.impactHard = CUtlSymbolTableMT::AddString(
                                                                                  this: p_m_strings,
                                                                                  result: &v26,
                                                                                  pString: value)->m_Id;
                                                }
                                              }
                                              else
                                              {
                                                prop.data.sounds.impactSoft = CUtlSymbolTableMT::AddString(
                                                                                this: p_m_strings,
                                                                                result: &v35,
                                                                                pString: value)->m_Id;
                                              }
                                            }
                                            else
                                            {
                                              prop.data.sounds.runStepRight = CUtlSymbolTableMT::AddString(
                                                                                this: p_m_strings,
                                                                                result: &v29,
                                                                                pString: value)->m_Id;
                                            }
                                          }
                                          else
                                          {
                                            prop.data.sounds.runStepLeft = CUtlSymbolTableMT::AddString(
                                                                             this: p_m_strings,
                                                                             result: &v37,
                                                                             pString: value)->m_Id;
                                          }
                                        }
                                        else
                                        {
                                          prop.data.sounds.walkStepRight = CUtlSymbolTableMT::AddString(
                                                                             this: p_m_strings,
                                                                             result: &v28,
                                                                             pString: value)->m_Id;
                                        }
                                      }
                                      else
                                      {
                                        prop.data.sounds.walkStepLeft = CUtlSymbolTableMT::AddString(
                                                                          this: p_m_strings,
                                                                          result: &v30,
                                                                          pString: value)->m_Id;
                                      }
                                    }
                                    else
                                    {
                                      prop.data.sounds.walkStepRight = CUtlSymbolTableMT::AddString(
                                                                         this: p_m_strings,
                                                                         result: &v32,
                                                                         pString: value)->m_Id;
                                      prop.data.sounds.runStepRight = prop.data.sounds.walkStepRight;
                                    }
                                  }
                                  else
                                  {
                                    prop.data.sounds.walkStepLeft = CUtlSymbolTableMT::AddString(
                                                                      this: p_m_strings,
                                                                      result: &v31,
                                                                      pString: value)->m_Id;
                                    prop.data.sounds.runStepLeft = prop.data.sounds.walkStepLeft;
                                  }
                                }
                                else
                                {
                                  prop.data.audio.hardThreshold = atof(nptr: value);
                                }
                              }
                              else
                              {
                                prop.data.audio.roughThreshold = atof(nptr: value);
                              }
                            }
                            else
                            {
                              prop.data.audio.roughnessFactor = atof(nptr: value);
                            }
                          }
                          else
                          {
                            prop.data.audio.hardVelocityThreshold = atof(nptr: value);
                          }
                        }
                        else
                        {
                          prop.data.audio.hardnessFactor = atof(nptr: value);
                        }
                      }
                      else
                      {
                        prop.data.audio.reflectivity = atof(nptr: value);
                      }
                    }
                    else
                    {
                      prop.data.game.climbable = atoi(nptr: value);
                    }
                  }
                  else
                  {
                    prop.data.game.jumpFactor = atof(nptr: value);
                  }
                }
                else
                {
                  prop.data.game.maxSpeedFactor = atof(nptr: value);
                }
              }
              else
              {
                prop.data.physics.friction = atof(nptr: value);
              }
            }
            else
            {
              prop.data.physics.elasticity = atof(nptr: value);
            }
          }
          else
          {
            prop.data.physics.density = atof(nptr: value);
          }
        }
        else
        {
          prop.data.physics.thickness = atof(nptr: value);
        }
        goto LABEL_91;
      }
      v11 = &v42->__vftable;
      v12 = v42->GetSurfaceIndex(this: v42, a2: value);
      if ( v12 > 127 )
      {
        if ( v12 != 61440 )
        {
          v12 = 0;
LABEL_27:
          if ( v12 <= v11[21] - 1 )
          {
            v13 = v11[18] + 120 * v12;
            if ( v13 != 0 )
              prop.data = *(surfacedata_t *)(v13 + 16);
          }
          goto LABEL_91;
        }
        v12 = v11[96];
      }
      if ( v12 >= 0 )
        goto LABEL_27;
LABEL_91:
      if ( pText == nullptr )
        goto LABEL_106;
    }
    m_lockInfo = p_m_strings->m_lock.m_lockInfo;
    p_m_lock = (volatile signed __int32 *)&p_m_strings->m_lock;
    HIWORD(pTextfile) = prop.m_name.m_Id;
    if ( (m_lockInfo.m_i32 & 0x10000) != 0
      || (v16 = (unsigned __int16)*p_m_lock, _InterlockedCompareExchange(p_m_lock, v16 + 1, v16) != v16) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &p_m_strings->m_lock);
    }
    v17 = CUtlSymbolTable::String(this: p_m_strings, id: *(CUtlSymbol *)((char *)&pTextfile + 2));
    _InterlockedExchangeAdd(p_m_lock, 0xFFFFFFFF);
    v18 = v42;
    v19 = v42->GetSurfaceIndex(this: v42, a2: v17);
    if ( v19 < 0 )
    {
      CUtlVector<CSurface,CUtlMemory<CSurface,int>>::InsertBefore(
        this: &v18->m_props,
        elem: v18->m_props.m_Size,
        src: &prop);
    }
    else
    {
      if ( v19 > 127 )
      {
        if ( v19 != 61440 )
        {
          v19 = 0;
          goto LABEL_102;
        }
        v19 = v18->m_shadowFallback;
      }
      if ( v19 >= 0 )
      {
LABEL_102:
        if ( v19 <= v18->m_props.m_Size - 1 )
        {
          v18->m_props.m_Memory.m_pMemory[v19].data = prop.data;
          goto LABEL_106;
        }
      }
      MEMORY[0x10] = prop.data;
    }
LABEL_106:
    IVP_Material::~IVP_Material(this: &prop);
    v3 = v42;
    v5 = pText;
  }
  while ( v5 != nullptr );
  if ( !v3->m_init )
  {
    v3->m_init = true;
    pOut.second_friction_x_enabled = IVP_FALSE;
    pOut.__vftable = (CSurface_vtbl *)&CSurface::`vftable';
    pOut.m_name.m_Id = -1;
    memset(dst: (unsigned __int8 *)&pOut.data, value: 0, count: sizeof(pOut.data));
    v20 = v3->GetReservedMaterialName(this: v3, a2: 61440);
    pOut.m_name = (CUtlSymbol)CUtlSymbolTableMT::AddString(this: &v3->m_strings, result: &v34, pString: v20)->m_Id;
    CPhysicsSurfaceProps::CopyPhysicsProperties(this: v3, &pOut, baseIndex: 0);
    m_Size = v3->m_props.m_Size;
    pOut.data.physics.elasticity = 0.001;
    pOut.data.physics.friction = 0.80000001;
    v3->m_shadowFallback = CUtlVector<CSurface,CUtlMemory<CSurface,int>>::InsertBefore(
                             this: &v3->m_props,
                             elem: m_Size,
                             src: &pOut);
    IVP_Material::~IVP_Material(this: &pOut);
  }
  if ( v3->GetSurfaceIndex(this: v3, a2: "default") != 0 )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
      __debugbreak();
    _Warning(a1: "Physics materials broken!\n");
  }
  return v3->m_props.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100183E0
// Name: public: CPhysicsSurfaceProps::CPhysicsSurfaceProps(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsSurfaceProps *__thiscall CPhysicsSurfaceProps::CPhysicsSurfaceProps(CPhysicsSurfaceProps *this)
{
  CUtlSymbolTableMT *p_m_strings; // ebx
  CThreadSpinRWLock *p_m_lock; // ebx
  CUtlSymbol *v4; // eax
  unsigned int v5; // eax
  unsigned __int16 *m_propMap; // ecx
  CSurface *m_pMemory; // eax
  IMemAlloc_vtbl *v8; // edx
  CSurface *v9; // eax
  unsigned __int16 m_Id; // dx
  CUtlSymbol v12; // [esp+Ch] [ebp-4h] BYREF
  CUtlSymbol v13; // [esp+Eh] [ebp-2h] BYREF

  p_m_strings = &this->m_strings;
  this->__vftable = (CPhysicsSurfaceProps_vtbl *)&CPhysicsSurfaceProps::`vftable';
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_strings, growSize: 0, initSize: 32, caseInsensitive: true);
  p_m_lock = &p_m_strings->m_lock;
  CThreadSpinRWLock::CThreadSpinRWLock(this: p_m_lock);
  this->m_props.m_Memory.m_pMemory = nullptr;
  this->m_props.m_Memory.m_nAllocationCount = 0;
  this->m_props.m_Memory.m_nGrowSize = 0;
  this->m_props.m_Size = 0;
  this->m_props.m_pElements = nullptr;
  this->m_fileList.m_Memory.m_pMemory = nullptr;
  this->m_fileList.m_Memory.m_nAllocationCount = 8;
  this->m_fileList.m_Memory.m_nGrowSize = 8;
  v4 = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16);
  this->m_fileList.m_Memory.m_pMemory = v4;
  this->m_fileList.m_Size = 0;
  this->m_fileList.m_pElements = v4;
  IVP_Material_Manager::IVP_Material_Manager(this: &this->m_ivpManager, delete_on_env_delete_in: IVP_FALSE);
  this->m_ivpManager.__vftable = (CIVPMaterialManager_vtbl *)&CIVPMaterialManager::`vftable';
  v5 = 0;
  m_propMap = this->m_ivpManager.m_propMap;
  do
    *m_propMap++ = v5++;
  while ( v5 < 0x80 );
  this->m_ivpManager.m_props = this;
  if ( (p_m_lock->m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: p_m_lock);
  }
  else
  {
    p_m_lock->m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::AddString(this: &this->m_strings, result: &v12, pString: str);
  p_m_lock->m_writerId = 0;
  p_m_lock->m_lockInfo.m_i32 = 0;
  if ( this->m_props.m_Memory.m_nAllocationCount < 128 && this->m_props.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_props.m_Memory.m_nAllocationCount = 128;
    m_pMemory = this->m_props.m_Memory.m_pMemory;
    v8 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v9 = (CSurface *)((int (__stdcall *)(CSurface *, int))v8->Realloc_2)(a1: m_pMemory, a2: 15360);
    else
      v9 = (CSurface *)((int (__stdcall *)(int))v8->Alloc_2)(a1: 15360);
    this->m_props.m_Memory.m_pMemory = v9;
  }
  this->m_props.m_pElements = this->m_props.m_Memory.m_pMemory;
  if ( this->m_props.m_Size < 1 )
    CUtlVector<CSurface,CUtlMemory<CSurface,int>>::InsertMultipleBefore(
      this: &this->m_props,
      elem: this->m_props.m_Size,
      num: 1 - this->m_props.m_Size);
  if ( (p_m_lock->m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: p_m_lock);
  }
  else
  {
    p_m_lock->m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::AddString(this: &this->m_strings, result: &v13, pString: "default");
  m_Id = v13.m_Id;
  p_m_lock->m_writerId = 0;
  p_m_lock->m_lockInfo.m_i32 = 0;
  this->m_props.m_Memory.m_pMemory->m_name.m_Id = m_Id;
  this->m_props.m_Memory.m_pMemory->data.physics.friction = 0.80000001;
  this->m_props.m_Memory.m_pMemory->data.physics.elasticity = 0.25;
  this->m_props.m_Memory.m_pMemory->data.physics.density = 2000.0;
  this->m_props.m_Memory.m_pMemory->data.physics.thickness = 0.0;
  this->m_props.m_Memory.m_pMemory->data.physics.dampening = 0.0;
  this->m_init = false;
  this->m_shadowFallback = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008B740
// Name: public: virtual float CSurface::get_friction_factor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSurface::get_friction_factor(IVP_Material_Simple *this)
{
  return this->second_friction_x;
}

//------------------------------------------------------------------------------
// Address: 0x1008B760
// Name: public: virtual float CSurface::get_elasticity(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSurface::get_elasticity(IVP_Material_Simple *this)
{
  return this->elasticity;
}

//------------------------------------------------------------------------------
// Address: 0x10016F30
// Name: __CreateCPhysicsSurfacePropsIPhysicsSurfaceProps_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysicsSurfaceProps *__cdecl _CreateCPhysicsSurfacePropsIPhysicsSurfaceProps_interface()
{
  return &g_SurfaceDatabase;
}
