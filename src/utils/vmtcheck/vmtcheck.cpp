// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmtcheck/vmtcheck.cpp
// Functions: 6
// ============================================================

#include "utils\vmtcheck\vmtcheck.h"

//------------------------------------------------------------------------------
// Address: 0x004035B0
// Name: void printusage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn printusage()
{
  vprint(
    depth: 0,
    fmt: "usage:  vmtcheck <materials/.vmt root directory>\n"
    "\t\t\t-v = verbose output\n"
    "\t\t\t-l = log to file log.txt\n"
    "\t\t\n"
    "e.g.:  vmtcheck -l u:/hl2/hl2/materials\n");
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004035D0
// Name: public: virtual enum LoggingResponse_t CNonFatalLoggingResponsePolicy::OnLog(struct LoggingContext_t const __near *)
// Source: json
//------------------------------------------------------------------------------
LoggingResponse_t __thiscall CNonFatalLoggingResponsePolicy::OnLog(
        CNonFatalLoggingResponsePolicy *this,
        const LoggingContext_t *pContext)
{
  int v2; // eax
  LoggingResponse_t result; // eax

  result = pContext->m_Severity == LS_ASSERT
        && (v2 = _CommandLine(a1: this),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noassert") == 0)
        || pContext->m_Severity == LS_ERROR;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403610
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004036A0
// Name: void BuildFileList_R(class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildFileList_R(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *files,
        const char *dir,
        const char *extension)
{
  signed int v3; // edi
  signed int v4; // kr00_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v8; // eax
  CUtlSymbol *v9; // eax
  char filename[256]; // [esp+4h] [ebp-450h] BYREF
  char directory[256]; // [esp+104h] [ebp-350h] BYREF
  char pDest[260]; // [esp+204h] [ebp-250h] BYREF
  _WIN32_FIND_DATAA wfd; // [esp+308h] [ebp-14Ch] BYREF
  int extlen; // [esp+448h] [ebp-Ch]
  void *ff; // [esp+44Ch] [ebp-8h]
  CUtlSymbol sym; // [esp+450h] [ebp-4h] BYREF

  sprintf(string: directory, format: "%s\\*.*", dir);
  ff = FindFirstFileA(lpFileName: directory, lpFindFileData: &wfd);
  if ( ff != (void *)-1 )
  {
    v3 = strlen(extension);
    for ( extlen = v3; ; v3 = extlen )
    {
      if ( (wfd.dwFileAttributes & 0x10) != 0 )
      {
        if ( wfd.cFileName[0] != 46 )
        {
          sprintf(string: filename, format: "%s\\%s", dir, wfd.cFileName);
          BuildFileList_R(files, dir: filename, extension);
        }
      }
      else
      {
        v4 = strlen(wfd.cFileName);
        if ( v4 > v3 && _V_stricmp(s1: &wfd.cFileName[v4 - v3], s2: extension) == 0 )
        {
          V_snprintf(pDest, maxLen: 260, pFormat: "%s\\%s", dir, wfd.cFileName);
          strlwr(string: pDest);
          V_FixSlashes(pname: pDest, separator: 92);
          CUtlSymbolTable::AddString(this: &g_Analysis.symbols, result: &sym, pString: pDest);
          m_Size = files->m_Size;
          m_nAllocationCount = files->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CUtlSymbol,int>::Grow(this: &files->m_Memory, num: m_Size - m_nAllocationCount + 1);
          ++files->m_Size;
          m_pMemory = files->m_Memory.m_pMemory;
          v8 = files->m_Size - m_Size - 1;
          files->m_pElements = files->m_Memory.m_pMemory;
          if ( v8 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v8);
          v9 = &files->m_Memory.m_pMemory[m_Size];
          if ( v9 != nullptr )
            v9->m_Id = sym.m_Id;
          if ( files->m_Size % 3000 == 0 )
            vprint(depth: 0, fmt: "...found %i .vmt files\n", files->m_Size);
        }
      }
      if ( !FindNextFileA(hFindFile: ff, lpFindFileData: &wfd) )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403880
// Name: void ProcessMaterialsDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessMaterialsDirectory(const char *basedir)
{
  KeyValues *v1; // edi
  int m_Size; // ecx
  int v3; // esi
  const char *v4; // eax
  const char *v5; // ebx
  KeyValues *v6; // eax
  char v7; // bl
  int v8; // edx
  CUtlSymbol *m_pMemory; // eax
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > vmts; // [esp+14h] [ebp-24h] BYREF
  int offset; // [esp+28h] [ebp-10h]
  int valid; // [esp+2Ch] [ebp-Ch]
  int c; // [esp+30h] [ebp-8h]
  char v14; // [esp+37h] [ebp-1h]

  v1 = nullptr;
  vprint(depth: 0, fmt: "building .vmt list\n");
  memset(&vmts, 0, sizeof(vmts));
  BuildFileList_R(files: &vmts, dir: basedir, extension: ".vmt");
  vprint(depth: 0, fmt: "found %i .vmt files\n\n", vmts.m_Size);
  offset = strlen(basedir) - 9;
  if ( offset < 0 )
    _Error(a1: "Bogus offset\n");
  m_Size = vmts.m_Size;
  v3 = 0;
  c = vmts.m_Size;
  valid = 0;
  if ( vmts.m_Size > 0 )
  {
    do
    {
      v4 = CUtlSymbolTable::String(this: &g_Analysis.symbols, id: vmts.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( verbose != 0 )
        vprint(depth: 0, fmt: "checking %i .vmt %s\n", v3, v4);
      spewed = false;
      v14 = 1;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v1 = KeyValues::KeyValues(this: v6, setName: "Test");
      if ( KeyValues::LoadFromFile(
             this: v1,
             filesystem: g_pFileSystem,
             resourceName: &v5[offset],
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        v7 = v14;
      }
      else
      {
        v7 = 0;
      }
      KeyValues::deleteThis(this: v1);
      if ( v7 != 0 && !spewed )
        ++valid;
      if ( v3 > 0 && v3 % 0x3E8u == 0 )
        vprint(
          depth: 0,
          fmt: "Analyzed %i .vmt files (%.2f %%%%)\n",
          v3,
          (float)((float)((float)v3 * 100.0) / (float)c));
      ++v3;
      v1 = nullptr;
    }
    while ( v3 < c );
    m_Size = c;
  }
  v8 = m_Size;
  if ( m_Size <= 1 )
    v8 = 1;
  vprint(
    depth: 0,
    fmt: "\nSummary:  found %i/%i (%.2f percent) .vmt errors\n",
    m_Size - valid,
    m_Size,
    (double)(m_Size - valid) * 100.0 / (double)v8);
  m_pMemory = vmts.m_Memory.m_pMemory;
  vmts.m_Size = 0;
  if ( vmts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( vmts.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vmts.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      vmts.m_Memory.m_pMemory = nullptr;
    }
    vmts.m_Memory.m_nAllocationCount = 0;
  }
  vmts.m_pElements = m_pMemory;
  if ( vmts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00403A80
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int i; // esi
  const char *v4; // eax
  char v5; // al
  char *v6; // eax
  char *v7; // edx
  char v8; // cl
  int v9; // eax
  char workingdir[256]; // [esp+Ch] [ebp-200h] BYREF
  char vmtdir[256]; // [esp+10Ch] [ebp-100h] BYREF

  _LoggingSystem_SetLoggingResponsePolicy(a1: &s_NonFatalLoggingResponsePolicy);
  for ( i = 1; i < argc; ++i )
  {
    v4 = argv[i];
    if ( *v4 == 45 )
    {
      v5 = v4[1];
      if ( v5 == 108 )
      {
        uselogfile = true;
      }
      else
      {
        if ( v5 != 118 )
          goto LABEL_19;
        verbose = 1;
      }
    }
  }
  if ( argc < 2 || i != argc )
  {
    vprint(depth: 0, fmt: "Valve Software - vmtcheck.exe (%s)\n", "Dec 28 2010");
    vprint(depth: 0, fmt: "--- VMT File Consistency Checker ---\n");
LABEL_19:
    printusage();
  }
  if ( uselogfile )
  {
    _unlink(path: "log.txt");
    vprint(depth: 0, fmt: "    Outputting to log.txt\n");
  }
  vprint(depth: 0, fmt: "Valve Software - vmtcheck.exe (%s)\n", "Dec 28 2010");
  vprint(depth: 0, fmt: "--- VMT File Consistency Checker ---\n");
  vprint(depth: 0, fmt: "    Looking for messed up .vmt files...\n");
  v6 = (char *)argv[i - 1];
  v7 = (char *)(vmtdir - v6);
  do
  {
    v8 = *v6;
    v6[(_DWORD)v7] = *v6;
    ++v6;
  }
  while ( v8 != 0 );
  strstr(str1: (unsigned __int8 *)vmtdir, str2: "materials");
  if ( v9 != 0 )
  {
    workingdir[0] = 0;
    Q_getwd(out: workingdir, outSize: 256);
    CmdLib_InitFileSystem(pFilename: workingdir, maxMemoryUsage: 0);
    vprint(depth: 0, fmt: "game dir %s\nmaterials dir %s\n\n", gamedir, vmtdir);
    V_StripTrailingSlash(ppath: vmtdir);
    ProcessMaterialsDirectory(basedir: vmtdir);
    FileSystem_Term();
  }
  else
  {
    vprint(depth: 0, fmt: "Materials dir %s looks invalid (format:  u:/tf2/hl2/materials)\n", vmtdir);
  }
  return 0;
}
