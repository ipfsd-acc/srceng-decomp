// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/main.cpp
// Functions: 20
// ============================================================

#include "vphysics\main.h"

//------------------------------------------------------------------------------
// Address: 0x10003280
// Name: DllMain(x,x,x)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  if ( fdwReason == 1 )
    MathLib_Init(
      gamma: 2.2,
      texGamma: 2.2,
      brightness: 0.0,
      overbright: 2,
      bAllow3DNow: false,
      bAllowSSE: false,
      bAllowSSE2: false,
      bAllowMMX: false);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100032E0
// Name: public: virtual void __near * CPhysicsInterface::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CPhysicsInterface::QueryInterface(CPhysicsInterface *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10003300
// Name: public: virtual class IPhysicsObjectPairHash __near * CPhysicsInterface::CreateObjectPairHash(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
IPhysicsObjectPairHash *__thiscall CPhysicsInterface::CreateObjectPairHash(CPhysicsInterface *this)
{
  return CreateObjectPairHash();
}

//------------------------------------------------------------------------------
// Address: 0x10003310
// Name: public: virtual void CPhysicsCollisionSet::EnableCollisions(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollisionSet::EnableCollisions(CPhysicsCollisionSet *this, int index0, int index1)
{
  this->m_bits[index0] |= 1 << index1;
  this->m_bits[index1] |= 1 << index0;
}

//------------------------------------------------------------------------------
// Address: 0x10003340
// Name: public: virtual void CPhysicsCollisionSet::DisableCollisions(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollisionSet::DisableCollisions(CPhysicsCollisionSet *this, int index0, int index1)
{
  this->m_bits[index0] &= ~(1 << index1);
  this->m_bits[index1] &= ~(1 << index0);
}

//------------------------------------------------------------------------------
// Address: 0x10003380
// Name: public: virtual bool CPhysicsCollisionSet::ShouldCollide(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsCollisionSet::ShouldCollide(CPhysicsCollisionSet *this, int index0, char index1)
{
  return ((1 << index1) & this->m_bits[index0]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003440
// Name: public: virtual void CBaseAppSystem<class IPhysics>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IPhysics>::Reconnect(
        CBaseAppSystem<IPhysics> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10003460
// Name: public: virtual class IPhysicsEnvironment __near * CPhysicsInterface::GetActiveEnvironmentByIndex(int)
// Source: json
//------------------------------------------------------------------------------
IPhysicsEnvironment *__thiscall CPhysicsInterface::GetActiveEnvironmentByIndex(CPhysicsInterface *this, int index)
{
  if ( index < 0 || index >= this->m_envList.m_Size )
    return nullptr;
  else
    return this->m_envList.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x10003480
// Name: public: virtual class IPhysicsCollisionSet __near * CPhysicsInterface::FindCollisionSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CPhysicsCollisionSet *__thiscall CPhysicsInterface::FindCollisionSet(CPhysicsInterface *this, void *id)
{
  IVP_VHash_Store *m_pCollisionSetHash; // ecx
  void *elem; // eax

  m_pCollisionSetHash = this->m_pCollisionSetHash;
  if ( m_pCollisionSetHash != nullptr
    && (int)(elem = IVP_VHash_Store::find_elem(this: m_pCollisionSetHash, key_elem: id)) > 0
    && (int)elem <= this->m_collisionSets.m_Size )
  {
    return &this->m_collisionSets.m_Memory.m_pMemory[(int)elem - 1];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100034C0
// Name: vphys_sleep_timeout
// Source: json
//------------------------------------------------------------------------------
void __cdecl vphys_sleep_timeout(const CCommand *args)
{
  const char *v1; // eax
  int i; // eax
  IPhysicsEnvironment *v3; // ecx
  float fFreezeCheckTime; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    v1 = str;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    fFreezeCheckTime = V_atof(str: v1);
    for ( i = 0; i >= 0; ++i )
    {
      if ( i >= g_MainDLLInterface.m_envList.m_Size )
        break;
      v3 = g_MainDLLInterface.m_envList.m_Memory.m_pMemory[i];
      if ( v3 == nullptr )
        break;
      *(float *)&v3[1].Simulate = fFreezeCheckTime;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003620
// Name: public: virtual bool CTier1AppSystem<class IPhysics,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier1AppSystem<IPhysics,0>::Connect(
        CTier1AppSystem<IPhysics,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003640
// Name: public: virtual void CTier1AppSystem<class IPhysics,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTier1AppSystem<IPhysics,0>::Disconnect(CTier1AppSystem<IPhysics,0> *this)
{
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10003650
// Name: public: virtual enum InitReturnVal_t CTier1AppSystem<class IPhysics,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier1AppSystem<IPhysics,0>::Init(CTier1AppSystem<IPhysics,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003670
// Name: public: virtual void CTier1AppSystem<class IPhysics,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier1AppSystem<IPhysics,0>::Shutdown(CTier1AppSystem<IPhysics,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10003680
// Name: public: virtual void CPhysicsInterface::DestroyEnvironment(class IPhysicsEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsInterface::DestroyEnvironment(CPhysicsInterface *this, IPhysicsEnvironment *pEnvironment)
{
  CUtlVector<IPhysicsPlayerController *,CUtlMemory<IPhysicsPlayerController *,int>>::FindAndRemove(
    this: &this->m_envList,
    src: &pEnvironment);
  if ( pEnvironment != nullptr )
    ((void (__thiscall *)(IPhysicsEnvironment *, int))pEnvironment->dtr_IPhysicsEnvironment)(a1: pEnvironment, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100036B0
// Name: public: virtual void CPhysicsInterface::DestroyAllCollisionSets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsInterface::DestroyAllCollisionSets(CPhysicsInterface *this)
{
  IVP_VHash_Store *m_pCollisionSetHash; // edi

  CUtlVector<CPhysicsCollisionSet,CUtlMemory<CPhysicsCollisionSet,int>>::Purge(this: &this->m_collisionSets);
  m_pCollisionSetHash = this->m_pCollisionSetHash;
  if ( m_pCollisionSetHash != nullptr )
  {
    IVP_VHash_Store::~IVP_VHash_Store(this: this->m_pCollisionSetHash);
    free(data: m_pCollisionSetHash);
  }
  this->m_pCollisionSetHash = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100036E0
// Name: public: virtual class IPhysicsEnvironment __near * CPhysicsInterface::CreateEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsEnvironment *__thiscall CPhysicsInterface::CreateEnvironment(CPhysicsInterface *this)
{
  IPhysicsEnvironment *PhysicsEnvironment; // eax
  int m_Size; // edi
  IPhysicsEnvironment *v4; // ebx
  int m_nAllocationCount; // eax
  IPhysicsEnvironment **m_pMemory; // ecx
  int v7; // eax
  IPhysicsEnvironment **v8; // eax

  PhysicsEnvironment = CreatePhysicsEnvironment();
  m_Size = this->m_envList.m_Size;
  v4 = PhysicsEnvironment;
  m_nAllocationCount = this->m_envList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_envList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_envList.m_Size;
  m_pMemory = this->m_envList.m_Memory.m_pMemory;
  v7 = this->m_envList.m_Size - m_Size - 1;
  this->m_envList.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_envList.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = v4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10003750
// Name: public: virtual class IPhysicsCollisionSet __near * CPhysicsInterface::FindOrCreateCollisionSet(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
CPhysicsCollisionSet *__thiscall CPhysicsInterface::FindOrCreateCollisionSet(
        CPhysicsInterface *this,
        void *id,
        int maxElementCount)
{
  IVP_VHash_Store *v4; // eax
  IVP_VHash_Store *v5; // eax
  CPhysicsCollisionSet *result; // eax
  int v7; // ebx

  if ( this->m_pCollisionSetHash == nullptr )
  {
    v4 = (IVP_VHash_Store *)p_malloc(size: 0x14u);
    if ( v4 != nullptr )
      v5 = IVP_VHash_Store::IVP_VHash_Store(this: v4, size_i: 256);
    else
      v5 = nullptr;
    this->m_pCollisionSetHash = v5;
  }
  if ( maxElementCount > 32 )
    return nullptr;
  result = (CPhysicsCollisionSet *)this->FindCollisionSet(this, a2: id);
  if ( result == nullptr )
  {
    v7 = CUtlVector<CPhysicsCollisionSet,CUtlMemory<CPhysicsCollisionSet,int>>::InsertBefore(
           this: &this->m_collisionSets,
           elem: this->m_collisionSets.m_Size);
    IVP_VHash_Store::add_elem(this: this->m_pCollisionSetHash, key_elem: id, elem: (void *)(v7 + 1));
    return &this->m_collisionSets.m_Memory.m_pMemory[v7];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B2D0
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class IPhysics>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IPhysics>::GetDependencies(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100032D0
// Name: __CreateCPhysicsInterfaceIPhysics_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysicsInterface *__cdecl _CreateCPhysicsInterfaceIPhysics_interface()
{
  return &g_MainDLLInterface;
}
