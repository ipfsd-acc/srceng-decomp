// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/closedcaptions.cpp
// Functions: 1
// ============================================================

#include "public\closedcaptions.h"

//------------------------------------------------------------------------------
// Address: 0x100BF710
// Name: public: bool AsyncCaption_t::LoadFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge AsyncCaption_t::LoadFromFile@<al>(AsyncCaption_t *this@<ecx>, int a2@<esi>, const char *pchFullPath)
{
  void *v4; // edi
  const char *v6; // esi
  const char *directorysize; // eax
  int v8; // eax
  int v9; // edi
  signed int m_Size; // eax
  bool v11; // sf
  CUtlBuffer dirbuffer; // [esp+8h] [ebp-3Ch] BYREF
  void *context; // [esp+38h] [ebp-Ch] BYREF
  void *fh; // [esp+3Ch] [ebp-8h]
  char v15; // [esp+43h] [ebp-1h] BYREF

  v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pchFullPath, a3: "rb", a4: 0);
  fh = v4;
  if ( v4 == nullptr )
    return 0;
  CUtlBuffer::CUtlBuffer(this: &dirbuffer, growSize: 0, initSize: 0, nFlags: 0);
  ((void (__thiscall *)(IBaseFileSystem *, CompiledCaptionHeader_t *, int, void *, int))g_pFullFileSystem->Read)(
    a1: &g_pFullFileSystem->IBaseFileSystem,
    a2: &this->m_Header,
    a3: 24,
    a4: v4,
    a5: a2);
  v6 = pchFullPath;
  if ( this->m_Header.magic != 1145258838 )
    _Error(this: (ISceneTokenProcessor *)&stru_104718AC, a2: pchFullPath);
  if ( this->m_Header.version != 1 )
    _Error(this: (ISceneTokenProcessor *)&stru_1047188C, a2: v6);
  directorysize = (const char *)this->m_Header.directorysize;
  if ( (unsigned int)directorysize > 0x10000 )
    _Error(this: (ISceneTokenProcessor *)&stru_10471868, a2: directorysize, v6);
  v8 = this->m_Header.directorysize;
  v9 = 12 * v8;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
    this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_CaptionDirectory,
    num: v8);
  CUtlBuffer::EnsureCapacity(this: &dirbuffer, num: v9);
  ((void (__thiscall *)(IBaseFileSystem *, unsigned __int8 *, int))g_pFullFileSystem->Read)(
    a1: &g_pFullFileSystem->IBaseFileSystem,
    a2: dirbuffer.m_Memory.m_pMemory,
    a3: v9);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: fh);
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::CopyArray(
    this: &this->m_CaptionDirectory,
    pArray: (const CaptionLookup_t *)&dirbuffer.m_Memory.m_pMemory[dirbuffer.m_Get - dirbuffer.m_nOffset],
    size: this->m_Header.directorysize);
  m_Size = this->m_CaptionDirectory.m_Size;
  this->m_CaptionDirectory.m_bNeedsSort = false;
  if ( m_Size > 1 )
  {
    context = this->m_CaptionDirectory.m_pLessContext;
    fh = &v15;
    qsort_s(
      base: this->m_CaptionDirectory.m_Memory.m_pMemory,
      num: m_Size,
      width: 0xCu,
      comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::CompareHelper,
      &context);
  }
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pchFullPath + 1, pStr: pchFullPath);
  v11 = dirbuffer.m_Memory.m_nGrowSize < 0;
  this->m_DataBaseFile.m_Id = HIWORD(pchFullPath);
  if ( !v11 && dirbuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirbuffer.m_Memory.m_pMemory);
  return 1;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100EDE60
// Name: public: bool AsyncCaption_t::LoadFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge AsyncCaption_t::LoadFromFile@<al>(AsyncCaption_t *this@<ecx>, int a2@<esi>, const char *pchFullPath)
{
  void *v4; // edi
  const char *v6; // esi
  const char *directorysize; // eax
  int v8; // eax
  int v9; // edi
  signed int m_Size; // eax
  bool v11; // sf
  CUtlBuffer dirbuffer; // [esp+8h] [ebp-3Ch] BYREF
  void *context; // [esp+38h] [ebp-Ch] BYREF
  void *fh; // [esp+3Ch] [ebp-8h]
  char v15; // [esp+43h] [ebp-1h] BYREF

  v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pchFullPath, a3: "rb", a4: 0);
  fh = v4;
  if ( v4 == nullptr )
    return 0;
  CUtlBuffer::CUtlBuffer(this: &dirbuffer, growSize: 0, initSize: 0, nFlags: 0);
  ((void (__thiscall *)(IBaseFileSystem *, CompiledCaptionHeader_t *, int, void *, int))g_pFullFileSystem->Read)(
    a1: &g_pFullFileSystem->IBaseFileSystem,
    a2: &this->m_Header,
    a3: 24,
    a4: v4,
    a5: a2);
  v6 = pchFullPath;
  if ( this->m_Header.magic != 1145258838 )
    _Error(this: (ISceneTokenProcessor *)&stru_104582E8, a2: pchFullPath);
  if ( this->m_Header.version != 1 )
    _Error(this: (ISceneTokenProcessor *)&stru_104582C8, a2: v6);
  directorysize = (const char *)this->m_Header.directorysize;
  if ( (unsigned int)directorysize > 0x10000 )
    _Error(this: (ISceneTokenProcessor *)&stru_104582A4, a2: directorysize, v6);
  v8 = this->m_Header.directorysize;
  v9 = 12 * v8;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
    this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_CaptionDirectory,
    num: v8);
  CUtlBuffer::EnsureCapacity(this: &dirbuffer, num: v9);
  ((void (__thiscall *)(IBaseFileSystem *, unsigned __int8 *, int))g_pFullFileSystem->Read)(
    a1: &g_pFullFileSystem->IBaseFileSystem,
    a2: dirbuffer.m_Memory.m_pMemory,
    a3: v9);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: fh);
  CUtlVector<CaptionLookup_t,CUtlMemory<CaptionLookup_t,int>>::CopyArray(
    this: &this->m_CaptionDirectory,
    pArray: (const CaptionLookup_t *)&dirbuffer.m_Memory.m_pMemory[dirbuffer.m_Get - dirbuffer.m_nOffset],
    size: this->m_Header.directorysize);
  m_Size = this->m_CaptionDirectory.m_Size;
  this->m_CaptionDirectory.m_bNeedsSort = false;
  if ( m_Size > 1 )
  {
    context = this->m_CaptionDirectory.m_pLessContext;
    fh = &v15;
    qsort_s(
      base: (char *)this->m_CaptionDirectory.m_Memory.m_pMemory,
      num: m_Size,
      width: 0xCu,
      comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CaptionLookup_t,CCaptionLookupLess>::CompareHelper,
      &context);
  }
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pchFullPath + 1, pStr: pchFullPath);
  v11 = dirbuffer.m_Memory.m_nGrowSize < 0;
  this->m_DataBaseFile.m_Id = HIWORD(pchFullPath);
  if ( !v11 && dirbuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirbuffer.m_Memory.m_pMemory);
  return 1;
}

} // namespace server
