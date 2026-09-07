// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/singleplayersharedmemory.cpp
// Functions: 15
// ============================================================

#include "engine\singleplayersharedmemory.h"

//------------------------------------------------------------------------------
// Address: 0x101D7D40
// Name: public: virtual bool CSPSharedMemory::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSPSharedMemory::Init(CSPSharedMemory *this, unsigned int iSize)
{
  unsigned __int8 *v3; // eax

  if ( this->m_Size != 0 )
    return 0;
  v3 = (unsigned __int8 *)MemAlloc_Alloc(nSize: iSize);
  this->m_pMemory = v3;
  this->m_Size = iSize;
  memset(dst: v3, value: 0, count: iSize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D7D90
// Name: public: virtual void CSPSharedMemory::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSPSharedMemory::AddRef(CSPSharedMemory *this)
{
  ++this->m_iRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x101D7DA0
// Name: public: virtual void CSPSharedMemory::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSPSharedMemory::Release(CSPSharedMemory *this)
{
  int m_Size; // esi
  int v3; // eax

  if ( this->m_iRefCount-- == 1 )
  {
    m_Size = s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size;
    v3 = s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size - 1;
    if ( s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size - 1 >= 0 )
    {
      while ( s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Memory.m_pMemory[v3] != this )
      {
        if ( --v3 < 0 )
          return;
      }
      if ( s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size > 0 )
      {
        if ( v3 != s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size - 1 )
        {
          s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Memory.m_pMemory[v3] = s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Memory.m_pMemory[s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size - 1];
          m_Size = s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size;
        }
        s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size = m_Size - 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7DF0
// Name: public: CSPSharedMemoryManager::~CSPSharedMemoryManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSPSharedMemoryManager::~CSPSharedMemoryManager(CSPSharedMemoryManager *this)
{
  int i; // edi
  CSPSharedMemory **v3; // esi
  const char *v4; // eax

  for ( i = this->m_SharedSpaces.m_Size - 1; i >= 0; --i )
  {
    v3 = &this->m_SharedSpaces.m_Memory.m_pMemory[i];
    v4 = CUtlString::operator char const *(this: &(*v3)->m_Name);
    _Warning(a1: "Shared memory space %s (%i) still has %i references.\n", v4, (*v3)->m_iEntNum, (*v3)->m_iRefCount);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101D7E40
// Name: public: class ISPSharedMemory __near * CSPSharedMemoryManager::GetSharedMemory(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSPSharedMemory *__thiscall CSPSharedMemoryManager::GetSharedMemory(
        CSPSharedMemoryManager *this,
        const char *szName,
        int ent_num)
{
  int v4; // edi
  CSPSharedMemory *v5; // eax
  CSPSharedMemory *v6; // edi
  CSPSharedMemory *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSPSharedMemory **m_pMemory; // ecx
  int v11; // eax
  CSPSharedMemory **v12; // edi

  v4 = this->m_SharedSpaces.m_Size - 1;
  if ( v4 < 0 )
  {
LABEL_5:
    v5 = (CSPSharedMemory *)MemAlloc_Alloc(nSize: 0x24u);
    v6 = v5;
    v7 = nullptr;
    if ( v5 != nullptr )
    {
      v5->__vftable = (CSPSharedMemory_vtbl *)&CSPSharedMemory::`vftable';
      CUtlString::CUtlString(this: &v5->m_Name);
      v6->m_pMemory = nullptr;
      v6->m_Size = 0;
      v6->m_iRefCount = 0;
      v7 = v6;
    }
    CUtlString::operator=(this: &v7->m_Name, src: szName);
    v7->m_iEntNum = ent_num;
    m_Size = this->m_SharedSpaces.m_Size;
    m_nAllocationCount = this->m_SharedSpaces.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
    ++this->m_SharedSpaces.m_Size;
    m_pMemory = this->m_SharedSpaces.m_Memory.m_pMemory;
    v11 = this->m_SharedSpaces.m_Size - m_Size - 1;
    this->m_SharedSpaces.m_pElements = this->m_SharedSpaces.m_Memory.m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = &this->m_SharedSpaces.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = v7;
    v7->AddRef(this: v7);
    return v7;
  }
  else
  {
    while ( !CUtlString::operator==(this: &this->m_SharedSpaces.m_Memory.m_pMemory[v4]->m_Name, src: szName)
         || this->m_SharedSpaces.m_Memory.m_pMemory[v4]->m_iEntNum != ent_num )
    {
      if ( --v4 < 0 )
        goto LABEL_5;
    }
    this->m_SharedSpaces.m_Memory.m_pMemory[v4]->AddRef(this: this->m_SharedSpaces.m_Memory.m_pMemory[v4]);
    return this->m_SharedSpaces.m_Memory.m_pMemory[v4];
  }
}

//------------------------------------------------------------------------------
// Address: 0x103101F0
// Name: _dynamic_initializer_for__play__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__play__()
{
  ConCommand::ConCommand(
    this: &play,
    pName: "play",
    callback: (void (__cdecl *)())S_Play,
    pHelpString: "Play a sound.",
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__play__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B210
// Name: _dynamic_initializer_for__memory_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__memory_command__()
{
  ConCommand::ConCommand(
    this: &memory_command,
    pName: "memory",
    callback: memory,
    pHelpString: "Print memory stats.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__memory_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10320C10
// Name: _dynamic_atexit_destructor_for__play__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__play__()
{
  ConCommand::~ConCommand(this: &play);
}

//------------------------------------------------------------------------------
// Address: 0x103258D0
// Name: _dynamic_atexit_destructor_for__memory_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__memory_command__()
{
  ConCommand::~ConCommand(this: &memory_command);
}

//------------------------------------------------------------------------------
// Address: 0x10310220
// Name: _dynamic_initializer_for__playflush__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playflush__()
{
  ConCommand::ConCommand(
    this: &playflush,
    pName: "playflush",
    callback: (void (__cdecl *)())S_Play,
    pHelpString: "Play a sound, reloading from disk in case of changes.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playflush__);
}

//------------------------------------------------------------------------------
// Address: 0x10310250
// Name: _dynamic_initializer_for__playvol__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playvol__()
{
  ConCommand::ConCommand(
    this: &playvol,
    pName: "playvol",
    callback: (void (__cdecl *)())S_PlayVol,
    pHelpString: "Play a sound at a specified volume.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__playvol__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B240
// Name: _dynamic_initializer_for__startdemos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startdemos_command__()
{
  ConCommand::ConCommand(
    this: &startdemos_command,
    pName: "startdemos",
    callback: (void (__cdecl *)())startdemos,
    pHelpString: "Play demos in demo sequence.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startdemos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10320C20
// Name: _dynamic_atexit_destructor_for__playflush__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playflush__()
{
  ConCommand::~ConCommand(this: &playflush);
}

//------------------------------------------------------------------------------
// Address: 0x10320C30
// Name: _dynamic_atexit_destructor_for__playvol__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playvol__()
{
  ConCommand::~ConCommand(this: &playvol);
}

//------------------------------------------------------------------------------
// Address: 0x103258E0
// Name: _dynamic_atexit_destructor_for__startdemos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startdemos_command__()
{
  ConCommand::~ConCommand(this: &startdemos_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101D80D0
// Name: public: virtual bool CSPSharedMemory::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSPSharedMemory::Init(CSPSharedMemory *this, unsigned int iSize)
{
  unsigned __int8 *v3; // eax

  if ( this->m_Size != 0 )
    return 0;
  v3 = (unsigned __int8 *)MemAlloc_Alloc(nSize: iSize);
  this->m_pMemory = v3;
  this->m_Size = iSize;
  memset(dst: v3, value: 0, count: iSize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D8110
// Name: public: virtual void CSPSharedMemory::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSPSharedMemory::AddRef(CSPSharedMemory *this)
{
  ++this->m_iRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x101D8120
// Name: public: virtual void CSPSharedMemory::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSPSharedMemory::Release(CSPSharedMemory *this)
{
  int m_Size; // esi
  int v3; // eax

  if ( this->m_iRefCount-- == 1 )
  {
    m_Size = s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size;
    v3 = s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size - 1;
    if ( s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size - 1 >= 0 )
    {
      while ( s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Memory.m_pMemory[v3] != this )
      {
        if ( --v3 < 0 )
          return;
      }
      if ( s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size > 0 )
      {
        if ( v3 != s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size - 1 )
        {
          s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Memory.m_pMemory[v3] = s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Memory.m_pMemory[s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size - 1];
          m_Size = s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size;
        }
        s_SinglePlayerSharedMemoryManager.m_SharedSpaces.m_Size = m_Size - 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8170
// Name: public: CSPSharedMemoryManager::~CSPSharedMemoryManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSPSharedMemoryManager::~CSPSharedMemoryManager(CSPSharedMemoryManager *this)
{
  int i; // edi
  CSPSharedMemory **v3; // esi
  const char *v4; // eax

  for ( i = this->m_SharedSpaces.m_Size - 1; i >= 0; --i )
  {
    v3 = &this->m_SharedSpaces.m_Memory.m_pMemory[i];
    v4 = CUtlString::operator char const *(this: &(*v3)->m_Name);
    _Warning(a1: "Shared memory space %s (%i) still has %i references.\n", v4, (*v3)->m_iEntNum, (*v3)->m_iRefCount);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101D81C0
// Name: public: class ISPSharedMemory __near * CSPSharedMemoryManager::GetSharedMemory(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSPSharedMemory *__thiscall CSPSharedMemoryManager::GetSharedMemory(
        CSPSharedMemoryManager *this,
        const char *szName,
        int ent_num)
{
  int v4; // edi
  CSPSharedMemory *v5; // eax
  CSPSharedMemory *v6; // edi
  CSPSharedMemory *v7; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSPSharedMemory **m_pMemory; // ecx
  int v11; // eax
  CSPSharedMemory **v12; // edi

  v4 = this->m_SharedSpaces.m_Size - 1;
  if ( v4 < 0 )
  {
LABEL_5:
    v5 = (CSPSharedMemory *)MemAlloc_Alloc(nSize: 0x24u);
    v6 = v5;
    v7 = nullptr;
    if ( v5 != nullptr )
    {
      v5->__vftable = (CSPSharedMemory_vtbl *)&CSPSharedMemory::`vftable';
      CUtlString::CUtlString(this: &v5->m_Name);
      v6->m_pMemory = nullptr;
      v6->m_Size = 0;
      v6->m_iRefCount = 0;
      v7 = v6;
    }
    CUtlString::operator=(this: &v7->m_Name, src: szName);
    v7->m_iEntNum = ent_num;
    m_Size = this->m_SharedSpaces.m_Size;
    m_nAllocationCount = this->m_SharedSpaces.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
    ++this->m_SharedSpaces.m_Size;
    m_pMemory = this->m_SharedSpaces.m_Memory.m_pMemory;
    v11 = this->m_SharedSpaces.m_Size - m_Size - 1;
    this->m_SharedSpaces.m_pElements = this->m_SharedSpaces.m_Memory.m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = &this->m_SharedSpaces.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = v7;
    v7->AddRef(this: v7);
    return v7;
  }
  else
  {
    while ( !CUtlString::operator==(this: &this->m_SharedSpaces.m_Memory.m_pMemory[v4]->m_Name, src: szName)
         || this->m_SharedSpaces.m_Memory.m_pMemory[v4]->m_iEntNum != ent_num )
    {
      if ( --v4 < 0 )
        goto LABEL_5;
    }
    this->m_SharedSpaces.m_Memory.m_pMemory[v4]->AddRef(this: this->m_SharedSpaces.m_Memory.m_pMemory[v4]);
    return this->m_SharedSpaces.m_Memory.m_pMemory[v4];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031B400
// Name: _dynamic_initializer_for__memory_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__memory_command__()
{
  ConCommand::ConCommand(
    this: &memory_command,
    pName: "memory",
    callback: (void (__cdecl *)(const CCommand *))memory,
    pHelpString: "Print memory stats.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__memory_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325AC0
// Name: _dynamic_atexit_destructor_for__memory_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__memory_command__()
{
  ConCommand::~ConCommand(this: &memory_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031B430
// Name: _dynamic_initializer_for__startdemos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startdemos_command__()
{
  ConCommand::ConCommand(
    this: &startdemos_command,
    pName: "startdemos",
    callback: startdemos,
    pHelpString: "Play demos in demo sequence.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startdemos_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325AD0
// Name: _dynamic_atexit_destructor_for__startdemos_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startdemos_command__()
{
  ConCommand::~ConCommand(this: &startdemos_command);
}

} // namespace engine_xlsp
