// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/loadscreenupdate.cpp
// Functions: 50
// ============================================================

#include "engine\loadscreenupdate.h"

//------------------------------------------------------------------------------
// Address: 0x1019F820
// Name: public: virtual void __near * CLoaderMemAlloc::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Alloc(CLoaderMemAlloc *this, unsigned int nSize)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->Alloc_2(this: this->m_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1019F860
// Name: public: virtual void __near * CLoaderMemAlloc::Realloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Realloc(CLoaderMemAlloc *this, void *pMem, unsigned int nSize)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->Realloc_2(this: this->m_pMemAlloc, a2: pMem, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1019F8A0
// Name: public: virtual void CLoaderMemAlloc::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::Free(CLoaderMemAlloc *this, void *pMem)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  this->m_pMemAlloc->Free_2(this: this->m_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x1019F8E0
// Name: public: virtual void __near * CLoaderMemAlloc::Alloc(unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Alloc(CLoaderMemAlloc *this, unsigned int nSize, const char *pFileName, int nLine)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->Alloc(this: this->m_pMemAlloc, a2: nSize, a3: pFileName, a4: nLine);
}

//------------------------------------------------------------------------------
// Address: 0x1019F910
// Name: public: virtual void __near * CLoaderMemAlloc::Realloc(void __near *,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Realloc(
        CLoaderMemAlloc *this,
        void *pMem,
        unsigned int nSize,
        const char *pFileName,
        int nLine)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->Realloc(this: this->m_pMemAlloc, a2: pMem, a3: nSize, a4: pFileName, a5: nLine);
}

//------------------------------------------------------------------------------
// Address: 0x1019F950
// Name: public: virtual void CLoaderMemAlloc::Free(void __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::Free(CLoaderMemAlloc *this, void *pMem, const char *pFileName, int nLine)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  this->m_pMemAlloc->Free(this: this->m_pMemAlloc, a2: pMem, a3: pFileName, a4: nLine);
}

//------------------------------------------------------------------------------
// Address: 0x1019F990
// Name: public: virtual void __near * CLoaderMemAlloc::RegionAlloc(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::RegionAlloc(CLoaderMemAlloc *this, int region, unsigned int nSize)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->RegionAlloc_2(this: this->m_pMemAlloc, a2: region, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1019F9D0
// Name: public: virtual void __near * CLoaderMemAlloc::RegionAlloc(int,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::RegionAlloc(
        CLoaderMemAlloc *this,
        int region,
        unsigned int nSize,
        const char *pFileName,
        int nLine)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->RegionAlloc(this: this->m_pMemAlloc, a2: region, a3: nSize, a4: pFileName, a5: nLine);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA10
// Name: public: virtual void __near * CLoaderMemAlloc::Expand_NoLongerSupported(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Expand_NoLongerSupported(CLoaderMemAlloc *this, void *a1, unsigned int a2)
{
  return this->m_pMemAlloc->Expand_NoLongerSupported_2(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA20
// Name: public: virtual void __near * CLoaderMemAlloc::Expand_NoLongerSupported(void __near *,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Expand_NoLongerSupported(
        CLoaderMemAlloc *this,
        void *a1,
        unsigned int a2,
        const char *a3,
        int a4)
{
  return this->m_pMemAlloc->Expand_NoLongerSupported(this: this->m_pMemAlloc, a2: a1, a3: a2, a4: a3, a5: a4);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA30
// Name: public: virtual unsigned int CLoaderMemAlloc::GetSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLoaderMemAlloc::GetSize(CLoaderMemAlloc *this, void *a1)
{
  return this->m_pMemAlloc->GetSize(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA40
// Name: public: virtual void CLoaderMemAlloc::PushAllocDbgInfo(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::PushAllocDbgInfo(CLoaderMemAlloc *this, const char *a1, int a2)
{
  this->m_pMemAlloc->PushAllocDbgInfo(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA50
// Name: public: virtual void CLoaderMemAlloc::PopAllocDbgInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::PopAllocDbgInfo(CLoaderMemAlloc *this)
{
  this->m_pMemAlloc->PopAllocDbgInfo(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA60
// Name: public: virtual int CLoaderMemAlloc::CrtSetBreakAlloc(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtSetBreakAlloc(CLoaderMemAlloc *this, int a1)
{
  return this->m_pMemAlloc->CrtSetBreakAlloc(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA70
// Name: public: virtual int CLoaderMemAlloc::CrtIsValidHeapPointer(void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtIsValidHeapPointer(CLoaderMemAlloc *this, const void *a1)
{
  return this->m_pMemAlloc->CrtIsValidHeapPointer(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA80
// Name: public: virtual int CLoaderMemAlloc::CrtIsValidPointer(void const __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CrtIsValidPointer(ConVar *this, int value, unsigned int a2, int a3)
{
  ((void (__thiscall *)(ConCommandBase *, int, unsigned int, int))this->m_pNext->ConCommandBase::__vftable[1].IsFlagSet)(
    a1: this->m_pNext,
    a2: value,
    a3: a2,
    a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1019FA90
// Name: public: virtual int CLoaderMemAlloc::CrtCheckMemory(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtCheckMemory(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->CrtCheckMemory(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FAA0
// Name: public: virtual int CLoaderMemAlloc::CrtSetDbgFlag(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtSetDbgFlag(CLoaderMemAlloc *this, int a1)
{
  return this->m_pMemAlloc->CrtSetDbgFlag(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FAB0
// Name: public: virtual void CLoaderMemAlloc::CrtMemCheckpoint(struct _CrtMemState __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CrtMemCheckpoint(CLoaderMemAlloc *this, _CrtMemState *a1)
{
  this->m_pMemAlloc->CrtMemCheckpoint(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FAC0
// Name: public: virtual void CLoaderMemAlloc::DumpStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::DumpStats(CLoaderMemAlloc *this)
{
  this->m_pMemAlloc->DumpStats(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FAD0
// Name: public: virtual void CLoaderMemAlloc::DumpStatsFileBase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::DumpStatsFileBase(CLoaderMemAlloc *this, const char *a1)
{
  this->m_pMemAlloc->DumpStatsFileBase(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FAE0
// Name: public: virtual unsigned int CLoaderMemAlloc::ComputeMemoryUsedBy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLoaderMemAlloc::ComputeMemoryUsedBy(CLoaderMemAlloc *this, const char *a1)
{
  return this->m_pMemAlloc->ComputeMemoryUsedBy(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FAF0
// Name: public: virtual void __near * CLoaderMemAlloc::CrtSetReportFile(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::CrtSetReportFile(CLoaderMemAlloc *this, int a1, void *a2)
{
  return this->m_pMemAlloc->CrtSetReportFile(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB00
// Name: public: virtual void __near * CLoaderMemAlloc::CrtSetReportHook(void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::CrtSetReportHook(CLoaderMemAlloc *this, void *a1)
{
  return this->m_pMemAlloc->CrtSetReportHook(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB10
// Name: public: virtual int CLoaderMemAlloc::CrtDbgReport(int,char const __near *,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtDbgReport(
        CLoaderMemAlloc *this,
        int a1,
        const char *a2,
        int a3,
        const char *a4,
        const char *a5)
{
  return this->m_pMemAlloc->CrtDbgReport(this: this->m_pMemAlloc, a2: a1, a3: a2, a4: a3, a5: a4, a6: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB20
// Name: public: virtual int CLoaderMemAlloc::heapchk(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::heapchk(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->heapchk(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB30
// Name: public: virtual bool CLoaderMemAlloc::IsDebugHeap(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLoaderMemAlloc::IsDebugHeap(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->IsDebugHeap(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB40
// Name: public: virtual void CLoaderMemAlloc::GetActualDbgInfo(char const __near * __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::GetActualDbgInfo(CLoaderMemAlloc *this, const char **a1, int *a2)
{
  this->m_pMemAlloc->GetActualDbgInfo(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB50
// Name: public: virtual void CLoaderMemAlloc::RegisterAllocation(char const __near *,int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::RegisterAllocation(
        CLoaderMemAlloc *this,
        const char *a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  this->m_pMemAlloc->RegisterAllocation(this: this->m_pMemAlloc, a2: a1, a3: a2, a4: a3, a5: a4, a6: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB60
// Name: public: virtual void CLoaderMemAlloc::RegisterDeallocation(char const __near *,int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::RegisterDeallocation(
        CLoaderMemAlloc *this,
        const char *a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  this->m_pMemAlloc->RegisterDeallocation(this: this->m_pMemAlloc, a2: a1, a3: a2, a4: a3, a5: a4, a6: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB70
// Name: public: virtual int CLoaderMemAlloc::GetVersion(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::GetVersion(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->GetVersion(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB80
// Name: public: virtual void CLoaderMemAlloc::CompactHeap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CompactHeap(CLoaderMemAlloc *this)
{
  this->m_pMemAlloc->CompactHeap(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FB90
// Name: public: virtual unsigned int (*CLoaderMemAlloc::SetAllocFailHandler(unsigned int (*)(unsigned int)))(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int (__cdecl *__thiscall CLoaderMemAlloc::SetAllocFailHandler(
        CLoaderMemAlloc *this,
        unsigned int (__cdecl *a1)(unsigned int)))(unsigned int)
{
  return this->m_pMemAlloc->SetAllocFailHandler(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FBA0
// Name: public: virtual void CLoaderMemAlloc::DumpBlockStats(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::DumpBlockStats(CLoaderMemAlloc *this, void *a1)
{
  this->m_pMemAlloc->DumpBlockStats(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FBC0
// Name: public: virtual void CLoaderMemAlloc::SetStatsExtraInfo(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::SetStatsExtraInfo(CLoaderMemAlloc *this, const char *a1, const char *a2)
{
  this->m_pMemAlloc->SetStatsExtraInfo(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FBE0
// Name: public: virtual unsigned int CLoaderMemAlloc::MemoryAllocFailed(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLoaderMemAlloc::MemoryAllocFailed(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->MemoryAllocFailed(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FBF0
// Name: public: virtual void CLoaderMemAlloc::CompactIncremental(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CompactIncremental(CLoaderMemAlloc *this)
{
  this->m_pMemAlloc->CompactIncremental(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FC00
// Name: public: virtual void CLoaderMemAlloc::OutOfMemory(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::OutOfMemory(CLoaderMemAlloc *this, unsigned int a1)
{
  this->m_pMemAlloc->OutOfMemory(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FC20
// Name: public: virtual void CLoaderMemAlloc::GlobalMemoryStatus(unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::GlobalMemoryStatus(CLoaderMemAlloc *this, unsigned int *a1, unsigned int *a2)
{
  this->m_pMemAlloc->GlobalMemoryStatus(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FC40
// Name: public: virtual class IVirtualMemorySection __near * CLoaderMemAlloc::AllocateVirtualMemorySection(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IVirtualMemorySection *__thiscall CLoaderMemAlloc::AllocateVirtualMemorySection(CLoaderMemAlloc *this, unsigned int a1)
{
  return this->m_pMemAlloc->AllocateVirtualMemorySection(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FC60
// Name: public: virtual int CLoaderMemAlloc::GetGenericMemoryStats(struct GenericMemoryStat_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::GetGenericMemoryStats(CLoaderMemAlloc *this, GenericMemoryStat_t **a1)
{
  return this->m_pMemAlloc->GetGenericMemoryStats(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A4660
// Name: __heapchk
// Source: json
//------------------------------------------------------------------------------
void __cdecl _heapchk()
{
  _g_pMemAlloc->heapchk(this: _g_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x10265810
// Name: public: virtual int CLoaderMemAlloc::CrtSetReportMode(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CrtSetReportMode(ConVar *this, const char *value, int a2)
{
  ((void (__thiscall *)(ConCommandBase *, const char *, int))this->m_pNext->ConCommandBase::__vftable[1].dtr_ConCommandBase)(
    a1: this->m_pNext,
    a2: value,
    a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10319CD0
// Name: _dynamic_initializer_for__update_addon_paths_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__update_addon_paths_command__()
{
  ConCommand::ConCommand(
    this: &update_addon_paths_command,
    pName: "update_addon_paths",
    callback: update_addon_paths,
    pHelpString: "Reloads the search paths for game addons.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__update_addon_paths_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BD70
// Name: _dynamic_initializer_for__load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__load_command__()
{
  ConCommand::ConCommand(
    this: &load_command,
    pName: "load",
    callback: (void (__cdecl *)())Host_Loadgame_f,
    pHelpString: "Load a saved game.",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))g_load_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__load_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325180
// Name: _dynamic_atexit_destructor_for__update_addon_paths_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__update_addon_paths_command__()
{
  ConCommand::~ConCommand(this: &update_addon_paths_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C60
// Name: _dynamic_atexit_destructor_for__load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__load_command__()
{
  ConCommand::~ConCommand(this: &load_command);
}

//------------------------------------------------------------------------------
// Address: 0x101A4670
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10319D00
// Name: _dynamic_initializer_for__unload_all_addons_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__unload_all_addons_command__()
{
  ConCommand::ConCommand(
    this: &unload_all_addons_command,
    pName: "unload_all_addons",
    callback: unload_all_addons,
    pHelpString: "Reloads the search paths for game addons.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__unload_all_addons_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325190
// Name: _dynamic_atexit_destructor_for__unload_all_addons_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__unload_all_addons_command__()
{
  ConCommand::~ConCommand(this: &unload_all_addons_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101844E0
// Name: __heapchk
// Source: json
//------------------------------------------------------------------------------
void __cdecl _heapchk()
{
  _g_pMemAlloc->heapchk(this: _g_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FCA0
// Name: public: virtual void __near * CLoaderMemAlloc::Realloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Realloc(CLoaderMemAlloc *this, void *pMem, unsigned int nSize)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->Realloc_2(this: this->m_pMemAlloc, a2: pMem, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1019FCE0
// Name: public: virtual void CLoaderMemAlloc::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::Free(CLoaderMemAlloc *this, void *pMem)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  this->m_pMemAlloc->Free_2(this: this->m_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x1019FD20
// Name: public: virtual void __near * CLoaderMemAlloc::Alloc(unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Alloc(CLoaderMemAlloc *this, unsigned int nSize, const char *pFileName, int nLine)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->Alloc(this: this->m_pMemAlloc, a2: nSize, a3: pFileName, a4: nLine);
}

//------------------------------------------------------------------------------
// Address: 0x1019FD50
// Name: public: virtual void __near * CLoaderMemAlloc::Realloc(void __near *,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Realloc(
        CLoaderMemAlloc *this,
        void *pMem,
        unsigned int nSize,
        const char *pFileName,
        int nLine)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->Realloc(this: this->m_pMemAlloc, a2: pMem, a3: nSize, a4: pFileName, a5: nLine);
}

//------------------------------------------------------------------------------
// Address: 0x1019FD90
// Name: public: virtual void CLoaderMemAlloc::Free(void __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::Free(CLoaderMemAlloc *this, void *pMem, const char *pFileName, int nLine)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  this->m_pMemAlloc->Free(this: this->m_pMemAlloc, a2: pMem, a3: pFileName, a4: nLine);
}

//------------------------------------------------------------------------------
// Address: 0x1019FDD0
// Name: public: virtual void __near * CLoaderMemAlloc::RegionAlloc(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::RegionAlloc(CLoaderMemAlloc *this, int region, unsigned int nSize)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->RegionAlloc_2(this: this->m_pMemAlloc, a2: region, a3: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1019FE10
// Name: public: virtual void __near * CLoaderMemAlloc::RegionAlloc(int,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::RegionAlloc(
        CLoaderMemAlloc *this,
        int region,
        unsigned int nSize,
        const char *pFileName,
        int nLine)
{
  if ( _g_pMemAlloc == this && !this->m_bPaused )
    g_pMaterialSystem->RefreshFrontBufferNonInteractive(this: g_pMaterialSystem);
  return this->m_pMemAlloc->RegionAlloc(this: this->m_pMemAlloc, a2: region, a3: nSize, a4: pFileName, a5: nLine);
}

//------------------------------------------------------------------------------
// Address: 0x1019FE50
// Name: public: virtual void __near * CLoaderMemAlloc::Expand_NoLongerSupported(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Expand_NoLongerSupported(CLoaderMemAlloc *this, void *a1, unsigned int a2)
{
  return this->m_pMemAlloc->Expand_NoLongerSupported_2(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FE60
// Name: public: virtual void __near * CLoaderMemAlloc::Expand_NoLongerSupported(void __near *,unsigned int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::Expand_NoLongerSupported(
        CLoaderMemAlloc *this,
        void *a1,
        unsigned int a2,
        const char *a3,
        int a4)
{
  return this->m_pMemAlloc->Expand_NoLongerSupported(this: this->m_pMemAlloc, a2: a1, a3: a2, a4: a3, a5: a4);
}

//------------------------------------------------------------------------------
// Address: 0x1019FE70
// Name: public: virtual unsigned int CLoaderMemAlloc::GetSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLoaderMemAlloc::GetSize(CLoaderMemAlloc *this, void *a1)
{
  return this->m_pMemAlloc->GetSize(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FE80
// Name: public: virtual void CLoaderMemAlloc::PushAllocDbgInfo(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::PushAllocDbgInfo(CLoaderMemAlloc *this, const char *a1, int a2)
{
  this->m_pMemAlloc->PushAllocDbgInfo(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FE90
// Name: public: virtual void CLoaderMemAlloc::PopAllocDbgInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::PopAllocDbgInfo(CLoaderMemAlloc *this)
{
  this->m_pMemAlloc->PopAllocDbgInfo(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FEA0
// Name: public: virtual int CLoaderMemAlloc::CrtSetBreakAlloc(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtSetBreakAlloc(CLoaderMemAlloc *this, int a1)
{
  return this->m_pMemAlloc->CrtSetBreakAlloc(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FEB0
// Name: public: virtual int CLoaderMemAlloc::CrtIsValidHeapPointer(void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtIsValidHeapPointer(CLoaderMemAlloc *this, const void *a1)
{
  return this->m_pMemAlloc->CrtIsValidHeapPointer(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FEC0
// Name: public: virtual int CLoaderMemAlloc::CrtIsValidPointer(void const __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CrtIsValidPointer(ConVar *this, int value, unsigned int a2, int a3)
{
  ((void (__thiscall *)(ConCommandBase *, int, unsigned int, int))this->m_pNext->ConCommandBase::__vftable[1].IsFlagSet)(
    a1: this->m_pNext,
    a2: value,
    a3: a2,
    a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1019FED0
// Name: public: virtual int CLoaderMemAlloc::CrtCheckMemory(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtCheckMemory(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->CrtCheckMemory(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FEE0
// Name: public: virtual int CLoaderMemAlloc::CrtSetDbgFlag(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtSetDbgFlag(CLoaderMemAlloc *this, int a1)
{
  return this->m_pMemAlloc->CrtSetDbgFlag(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FEF0
// Name: public: virtual void CLoaderMemAlloc::CrtMemCheckpoint(struct _CrtMemState __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CrtMemCheckpoint(CLoaderMemAlloc *this, _CrtMemState *a1)
{
  this->m_pMemAlloc->CrtMemCheckpoint(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF00
// Name: public: virtual void CLoaderMemAlloc::DumpStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::DumpStats(CLoaderMemAlloc *this)
{
  this->m_pMemAlloc->DumpStats(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF10
// Name: public: virtual void CLoaderMemAlloc::DumpStatsFileBase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::DumpStatsFileBase(CLoaderMemAlloc *this, const char *a1)
{
  this->m_pMemAlloc->DumpStatsFileBase(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF20
// Name: public: virtual unsigned int CLoaderMemAlloc::ComputeMemoryUsedBy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLoaderMemAlloc::ComputeMemoryUsedBy(CLoaderMemAlloc *this, const char *a1)
{
  return this->m_pMemAlloc->ComputeMemoryUsedBy(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF30
// Name: public: virtual void __near * CLoaderMemAlloc::CrtSetReportFile(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::CrtSetReportFile(CLoaderMemAlloc *this, int a1, void *a2)
{
  return this->m_pMemAlloc->CrtSetReportFile(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF40
// Name: public: virtual void __near * CLoaderMemAlloc::CrtSetReportHook(void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CLoaderMemAlloc::CrtSetReportHook(CLoaderMemAlloc *this, void *a1)
{
  return this->m_pMemAlloc->CrtSetReportHook(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF50
// Name: public: virtual int CLoaderMemAlloc::CrtDbgReport(int,char const __near *,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::CrtDbgReport(
        CLoaderMemAlloc *this,
        int a1,
        const char *a2,
        int a3,
        const char *a4,
        const char *a5)
{
  return this->m_pMemAlloc->CrtDbgReport(this: this->m_pMemAlloc, a2: a1, a3: a2, a4: a3, a5: a4, a6: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF60
// Name: public: virtual int CLoaderMemAlloc::heapchk(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::heapchk(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->heapchk(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF70
// Name: public: virtual bool CLoaderMemAlloc::IsDebugHeap(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLoaderMemAlloc::IsDebugHeap(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->IsDebugHeap(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF80
// Name: public: virtual void CLoaderMemAlloc::GetActualDbgInfo(char const __near * __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::GetActualDbgInfo(CLoaderMemAlloc *this, const char **a1, int *a2)
{
  this->m_pMemAlloc->GetActualDbgInfo(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF90
// Name: public: virtual void CLoaderMemAlloc::RegisterAllocation(char const __near *,int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::RegisterAllocation(
        CLoaderMemAlloc *this,
        const char *a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  this->m_pMemAlloc->RegisterAllocation(this: this->m_pMemAlloc, a2: a1, a3: a2, a4: a3, a5: a4, a6: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1019FFA0
// Name: public: virtual void CLoaderMemAlloc::RegisterDeallocation(char const __near *,int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::RegisterDeallocation(
        CLoaderMemAlloc *this,
        const char *a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  this->m_pMemAlloc->RegisterDeallocation(this: this->m_pMemAlloc, a2: a1, a3: a2, a4: a3, a5: a4, a6: a5);
}

//------------------------------------------------------------------------------
// Address: 0x1019FFB0
// Name: public: virtual int CLoaderMemAlloc::GetVersion(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::GetVersion(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->GetVersion(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FFC0
// Name: public: virtual void CLoaderMemAlloc::CompactHeap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CompactHeap(CLoaderMemAlloc *this)
{
  this->m_pMemAlloc->CompactHeap(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x1019FFD0
// Name: public: virtual unsigned int (*CLoaderMemAlloc::SetAllocFailHandler(unsigned int (*)(unsigned int)))(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int (__cdecl *__thiscall CLoaderMemAlloc::SetAllocFailHandler(
        CLoaderMemAlloc *this,
        unsigned int (__cdecl *a1)(unsigned int)))(unsigned int)
{
  return this->m_pMemAlloc->SetAllocFailHandler(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FFE0
// Name: public: virtual void CLoaderMemAlloc::DumpBlockStats(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::DumpBlockStats(CLoaderMemAlloc *this, void *a1)
{
  this->m_pMemAlloc->DumpBlockStats(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A0000
// Name: public: virtual void CLoaderMemAlloc::SetStatsExtraInfo(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::SetStatsExtraInfo(CLoaderMemAlloc *this, const char *a1, const char *a2)
{
  this->m_pMemAlloc->SetStatsExtraInfo(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x101A0020
// Name: public: virtual unsigned int CLoaderMemAlloc::MemoryAllocFailed(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLoaderMemAlloc::MemoryAllocFailed(CLoaderMemAlloc *this)
{
  return this->m_pMemAlloc->MemoryAllocFailed(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x101A0030
// Name: public: virtual void CLoaderMemAlloc::CompactIncremental(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::CompactIncremental(CLoaderMemAlloc *this)
{
  this->m_pMemAlloc->CompactIncremental(this: this->m_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x101A0040
// Name: public: virtual void CLoaderMemAlloc::OutOfMemory(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::OutOfMemory(CLoaderMemAlloc *this, unsigned int a1)
{
  this->m_pMemAlloc->OutOfMemory(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A0060
// Name: public: virtual void CLoaderMemAlloc::GlobalMemoryStatus(unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoaderMemAlloc::GlobalMemoryStatus(CLoaderMemAlloc *this, unsigned int *a1, unsigned int *a2)
{
  this->m_pMemAlloc->GlobalMemoryStatus(this: this->m_pMemAlloc, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x101A0080
// Name: public: virtual class IVirtualMemorySection __near * CLoaderMemAlloc::AllocateVirtualMemorySection(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IVirtualMemorySection *__thiscall CLoaderMemAlloc::AllocateVirtualMemorySection(CLoaderMemAlloc *this, unsigned int a1)
{
  return this->m_pMemAlloc->AllocateVirtualMemorySection(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A00A0
// Name: public: virtual int CLoaderMemAlloc::GetGenericMemoryStats(struct GenericMemoryStat_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoaderMemAlloc::GetGenericMemoryStats(CLoaderMemAlloc *this, GenericMemoryStat_t **a1)
{
  return this->m_pMemAlloc->GetGenericMemoryStats(this: this->m_pMemAlloc, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10319EB0
// Name: _dynamic_initializer_for__update_addon_paths_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__update_addon_paths_command__()
{
  ConCommand::ConCommand(
    this: &update_addon_paths_command,
    pName: "update_addon_paths",
    callback: (void (__cdecl *)(const CCommand *))update_addon_paths,
    pHelpString: "Reloads the search paths for game addons.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__update_addon_paths_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325370
// Name: _dynamic_atexit_destructor_for__update_addon_paths_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__update_addon_paths_command__()
{
  ConCommand::~ConCommand(this: &update_addon_paths_command);
}

//------------------------------------------------------------------------------
// Address: 0x10319EE0
// Name: _dynamic_initializer_for__unload_all_addons_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__unload_all_addons_command__()
{
  ConCommand::ConCommand(
    this: &unload_all_addons_command,
    pName: "unload_all_addons",
    callback: (void (__cdecl *)(const CCommand *))unload_all_addons,
    pHelpString: "Reloads the search paths for game addons.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__unload_all_addons_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325380
// Name: _dynamic_atexit_destructor_for__unload_all_addons_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__unload_all_addons_command__()
{
  ConCommand::~ConCommand(this: &unload_all_addons_command);
}

} // namespace engine_xlsp
