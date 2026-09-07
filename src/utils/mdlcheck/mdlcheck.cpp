// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mdlcheck/mdlcheck.cpp
// Functions: 15
// ============================================================

#include "utils\mdlcheck\mdlcheck.h"

//------------------------------------------------------------------------------
// Address: 0x004030E0
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00403110
// Name: void printusage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn printusage()
{
  vprint(
    depth: 0,
    fmt: "usage:  mdlcheck <model source directory> <.mdl file directory>\n"
    "\t\t\t-v = verbose output\n"
    "\t\t\t-l = log to file log.txt\n"
    "\t\t\t-a = check for large animation data\n"
    "\t\t\t-n = no P4\n"
    "\t\t\n"
    "e.g.:  mdlcheck -l u:/hl2/hl2/hl2models u:/hl2/hl2/models\n");
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00403130
// Name: int LoadFile(char const __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadFile(const char *filename, void **bufferptr)
{
  unsigned __int8 *v2; // eax
  int filelength; // [esp+4h] [ebp-4h] BYREF

  v2 = COM_LoadFile(name: filename, len: &filelength);
  *bufferptr = v2;
  if ( v2 != nullptr )
    return filelength;
  vprint(depth: 0, fmt: "Couldn't load %s\n", filename);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403170
// Name: char __near * ExpandPath(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ExpandPath(char *path)
{
  char *result; // eax

  result = path;
  if ( *path != 47 && *path != 92 && path[1] != 58 )
  {
    sprintf(string: full, format: "%s%s", qdir, path);
    return full;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004031B0
// Name: bool GetModelNameFromSourceFile(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetModelNameFromSourceFile(const char *filename, char *modelname, int maxlen)
{
  unsigned __int8 *v4; // eax
  char v6; // bl
  char *v7; // esi
  const char *v8; // esi
  int v9; // eax
  int filelength; // [esp+Ch] [ebp-4h] BYREF
  char *buffer; // [esp+1Ch] [ebp+Ch]

  *modelname = 0;
  v4 = COM_LoadFile(name: filename, len: &filelength);
  buffer = (char *)v4;
  if ( v4 != nullptr )
  {
    v6 = 0;
    v7 = (char *)v4;
    while ( v7 != nullptr )
    {
      v7 = CC_ParseToken(data: v7);
      if ( strlen(unk_82C088) == 0 )
        break;
      if ( _V_stricmp(s1: unk_82C088, s2: "$modelname") == 0 )
      {
        CC_ParseToken(data: v7);
        strcpy(modelname, unk_82C088);
        strlwr(string: modelname);
        V_FixSlashes(pname: modelname, separator: 92);
        V_DefaultExtension(path: modelname, extension: ".mdl", pathStringLength: maxlen);
        v8 = filename;
LABEL_14:
        v6 = 1;
        goto LABEL_15;
      }
    }
    v8 = filename;
    V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: filename, pStartingDir: nullptr);
    V_StripFilename(path: qdir);
    _V_strlower(start: qdir);
    if ( qdir[0] != 0 )
      V_AppendSlash(pStr: qdir, strSize: 1024);
    ParseFromMemory(buffer, size: filelength);
    while ( GetToken(crossline: 1) != 0 )
    {
      if ( _V_stricmp(s1: token, s2: "$modelname") == 0 )
      {
        GetToken(crossline: 0);
        strcpy(modelname, token);
        strlwr(string: modelname);
        V_FixSlashes(pname: modelname, separator: 92);
        V_DefaultExtension(path: modelname, extension: ".mdl", pathStringLength: maxlen);
        goto LABEL_14;
      }
    }
LABEL_15:
    COM_FreeFile((unsigned __int8 *)buffer);
    if ( v6 == 0 )
    {
      v9 = vprint_owner(path: g_modelsources, filename: v8);
      vprint_queued(owner: v9, fmt: ".qc file %s missing $modelname directive!!!\n", v8);
    }
    return v6;
  }
  else
  {
    vprint(depth: 0, fmt: "Couldn't load %s\n", filename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403360
// Name: bool Studio_ConvertStudioHdrToNewVersion(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Studio_ConvertStudioHdrToNewVersion(studiohdr_t *pStudioHdr)
{
  int v2; // ebx
  int v4; // edx
  int v5; // ecx
  unsigned __int8 *v6; // edi
  int k; // edx
  int v8; // ecx
  char *v9; // ecx
  int m; // edi
  int v11; // ecx
  char *v12; // ecx
  int v13; // edx
  int j; // edx
  int v15; // ecx
  char *v16; // ecx
  int version; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  char bResult_3; // [esp+1Bh] [ebp+Bh]

  v2 = pStudioHdr->version;
  version = v2;
  if ( v2 == 49 )
    return 1;
  bResult_3 = 1;
  if ( v2 < 46 )
  {
    v4 = 0;
    for ( i = 0; v4 < pStudioHdr->numlocalanim; i = v4 )
    {
      v5 = v4;
      if ( v4 < 0 || v4 >= pStudioHdr->numlocalanim )
        v5 = 0;
      v6 = (unsigned __int8 *)pStudioHdr + 100 * v5 + pStudioHdr->localanimindex;
      if ( *((_DWORD *)v6 + 21) != 0 )
      {
        memset(dst: v6 + 16, value: 0, count: 0x54u);
        v4 = i;
        *((_DWORD *)v6 + 4) = 1;
        v2 = version;
        *((_DWORD *)v6 + 13) = -1;
        bResult_3 = 0;
      }
      ++v4;
    }
  }
  if ( v2 >= 47 )
  {
    if ( v2 == 47 )
    {
      for ( j = 0; j < pStudioHdr->numlocalanim; ++j )
      {
        v15 = j;
        if ( j < 0 || j >= pStudioHdr->numlocalanim )
          v15 = 0;
        v16 = (char *)pStudioHdr + 100 * v15 + pStudioHdr->localanimindex;
        if ( *((_DWORD *)v16 + 23) != 0 )
        {
          *((_DWORD *)v16 + 23) = 0;
          *((_WORD *)v16 + 44) = 0;
          bResult_3 = 0;
        }
      }
      goto LABEL_20;
    }
  }
  else
  {
    if ( pStudioHdr->unused4 != 0 )
    {
      pStudioHdr->unused4 = 0;
      bResult_3 = 0;
    }
    for ( k = 0; k < pStudioHdr->numlocalanim; *((_WORD *)v9 + 44) = 0 )
    {
      v8 = k;
      if ( k < 0 || k >= pStudioHdr->numlocalanim )
        v8 = 0;
      v9 = (char *)pStudioHdr + 100 * v8 + pStudioHdr->localanimindex;
      ++k;
      *((_DWORD *)v9 + 23) = 0;
    }
  }
  if ( v2 < 49 )
  {
LABEL_20:
    for ( m = 0; m < pStudioHdr->numlocalanim; ++m )
    {
      v11 = m;
      if ( m < 0 || m >= pStudioHdr->numlocalanim )
        v11 = 0;
      v12 = (char *)pStudioHdr + 100 * v11 + pStudioHdr->localanimindex;
      v13 = *((_DWORD *)v12 + 3);
      if ( (v13 & 0x40) != 0 )
      {
        *((_DWORD *)v12 + 3) = v13 & 0xFFFFFFBF;
        bResult_3 = 0;
      }
    }
  }
  pStudioHdr->version = 49;
  return bResult_3;
}

//------------------------------------------------------------------------------
// Address: 0x004034E0
// Name: bool SetupP4(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetupP4()
{
  struct CSysModule *Module; // eax
  struct CSysModule *v2; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IP4_vtbl *v4; // esi
  void *(__cdecl *v5)(const char *, int *); // eax
  char szPerforcePath[260]; // [esp+0h] [ebp-104h] BYREF

  if ( p4 != nullptr )
    return 1;
  V_ComposeFileName(path: g_modelsdir, filename: "../../bin/p4lib.dll", dest: szPerforcePath, destSize: 260);
  Module = Sys_LoadModule(pModuleName: szPerforcePath);
  v2 = Module;
  if ( Module != nullptr )
  {
    Factory = Sys_GetFactory(pModule: Module);
    if ( Factory != nullptr )
    {
      p4 = (IP4 *)((int (__stdcall *)(const char *))Factory)(a1: "VP4002");
      if ( p4 != nullptr )
      {
        FileSystem_Init(
          pBSPFilename: ".",
          maxMemoryUsage: 0,
          initType: FS_INIT_COMPATIBILITY_MODE,
          bOnlyUseFilename: false);
        v4 = p4->__vftable;
        v5 = FileSystem_GetFactory();
        v4->Connect(this: p4, a2: v5);
        p4->Init(this: p4);
      }
      return 1;
    }
    else
    {
      Sys_UnloadModule(pModule: v2);
      return 0;
    }
  }
  else
  {
    printf(format: "Can't load %s.\n", szPerforcePath);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004035C0
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
// Address: 0x00405630
// Name: void CheckForUnbuiltModels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckForUnbuiltModels()
{
  int m_NumElements; // ecx
  int v1; // ebx
  int v2; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *m_pMemory; // eax
  int v4; // esi
  int v5; // eax
  int toobig; // ecx
  int v7; // ecx
  int c; // [esp+4h] [ebp-4h]

  vprint_queued(owner: 0, fmt: "%s", "\n\n");
  m_NumElements = g_Analysis.models.m_Elements.m_Tree.m_NumElements;
  v1 = 0;
  c = g_Analysis.models.m_Elements.m_Tree.m_NumElements;
  if ( g_Analysis.models.m_Elements.m_Tree.m_NumElements > 0 )
  {
    v2 = g_Analysis.models.m_Elements.m_Tree.m_NumElements;
    m_pMemory = g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory;
    v4 = 0;
    do
    {
      if ( m_pMemory[v4].m_Data.elem.version != 0 )
      {
        if ( m_pMemory[v4].m_Data.elem.needsrecompile )
        {
          vprint_queued(
            owner: 0,
            fmt: "%s out of date,\n\tbuilt by %s\n",
            m_pMemory[v4].m_Data.key,
            m_pMemory[v4].m_Data.elem.qcfile);
          m_pMemory = g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory;
        }
        else
        {
          toobig = m_pMemory[v4].m_Data.elem.toobig;
          if ( toobig != 0 )
          {
            vprint_queued(
              owner: 0,
              fmt: "%s needs $animblocksize command (%d of animdata),\n\tbuilt by %s\n",
              m_pMemory[v4].m_Data.key,
              toobig,
              m_pMemory[v4].m_Data.elem.qcfile);
            m_pMemory = g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory;
          }
          else
          {
            ++v1;
          }
        }
      }
      else
      {
        v5 = vprint_owner(path: nullptr, filename: m_pMemory[v4].m_Data.elem.qcfile);
        vprint_queued(
          owner: v5,
          fmt: "Can't find %s,\n\tbuilt by %s\n",
          g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.key,
          g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.qcfile);
        m_pMemory = g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory;
      }
      ++v4;
      --v2;
    }
    while ( v2 != 0 );
    m_NumElements = c;
  }
  v7 = m_NumElements - v1;
  if ( v7 != 0 )
    vprint(depth: 0, fmt: "summary:  found %i missing .mdl's\n", v7);
}

//------------------------------------------------------------------------------
// Address: 0x00405810
// Name: void BuildFileList_R(class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildFileList_R(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *files,
        const char *dir,
        const char *extension)
{
  signed int v3; // kr00_4
  int v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbol *m_pMemory; // ecx
  int v8; // eax
  CUtlSymbol *v9; // eax
  char filename[256]; // [esp+4h] [ebp-450h] BYREF
  char directory[256]; // [esp+104h] [ebp-350h] BYREF
  char pDest[260]; // [esp+204h] [ebp-250h] BYREF
  _WIN32_FIND_DATAA wfd; // [esp+308h] [ebp-14Ch] BYREF
  void *ff; // [esp+448h] [ebp-Ch]
  int extlen; // [esp+44Ch] [ebp-8h]
  CUtlSymbol sym; // [esp+450h] [ebp-4h] BYREF

  sprintf(string: directory, format: "%s\\*.*", dir);
  ff = FindFirstFileA(lpFileName: directory, lpFindFileData: &wfd);
  if ( ff != (void *)-1 )
  {
    extlen = strlen(extension);
    do
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
        v3 = strlen(wfd.cFileName);
        if ( v3 > extlen )
        {
          strstr(str1: (unsigned __int8 *)wfd.cFileName, str2: ".360.");
          if ( v4 == 0 && _V_stricmp(s1: &wfd.cFileName[v3 - extlen], s2: extension) == 0 )
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
          }
        }
      }
    }
    while ( FindNextFileA(hFindFile: ff, lpFindFileData: &wfd) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405B30
// Name: bool ValidateModelFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ValidateModelFile(const char *modelname, int offset)
{
  _iobuf *v2; // esi
  const char *v4; // eax
  char v5; // cl
  int v6; // esi
  char v7; // bl
  int v8; // eax
  int v9; // eax
  int v10; // eax
  CUtlMap<char const *,ModelFile,int>::Node_t search; // [esp+8h] [ebp-21Ch] BYREF
  char shortname[263]; // [esp+11Ch] [ebp-108h] BYREF
  bool needsrecompile; // [esp+223h] [ebp-1h]

  v2 = fopen(file: modelname, mode: "rb");
  if ( v2 != nullptr )
  {
    v4 = &modelname[offset];
    do
    {
      v5 = *v4;
      v4[shortname - &modelname[offset]] = *v4;
      ++v4;
    }
    while ( v5 != 0 );
    V_FixSlashes(pname: shortname, separator: 92);
    fread(buffer: (void *)&buffer, elementSize: 0x400000u, count: 1u, stream: v2);
    fclose(stream: v2);
    if ( buffer.id == 1414743113 )
    {
      v6 = 0;
      v7 = 1;
      needsrecompile = false;
      if ( buffer.version < 44 || buffer.version > 49 )
      {
        vprint_queued(owner: 0, fmt: "Outdated model %s (ver %i != %i)\n", shortname, buffer.version, 49);
        v7 = 0;
      }
      if ( Studio_ConvertStudioHdrToNewVersion(pStudioHdr: &buffer) == 0 )
        needsrecompile = true;
      if ( checkani
        && *(_DWORD *)&buffer.name[buffer.localanimindex + 40] == 0
        && buffer.localseqindex - 100 * buffer.numlocalanim - buffer.localanimindex > 0x10000 )
      {
        v6 = buffer.localseqindex - 100 * buffer.numlocalanim - buffer.localanimindex;
      }
      search.key = shortname;
      v8 = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Find(
             this: &g_Analysis.models.m_Elements.m_Tree,
             &search);
      if ( v8 == -1 )
      {
        v9 = vprint_owner(path: nullptr, filename: modelname);
        vprint_queued(owner: v9, fmt: "Couldn't find a .qc which builds %s\n", modelname);
        return 0;
      }
      else
      {
        v10 = v8;
        g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem.version = buffer.version;
        g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem.needsrecompile = needsrecompile;
        g_Analysis.models.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem.toobig = v6;
        return v7;
      }
    }
    else
    {
      vprint_queued(owner: 0, fmt: "Bogus studiomdl header for %s, expecting 'IDST' four cc code\n", shortname);
      return 0;
    }
  }
  else
  {
    vprint_queued(owner: 0, fmt: "Unable to open .mdl file %s\n", modelname);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405CD0
// Name: void ProcessModelsDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessModelsDirectory(const char *basedir)
{
  int v1; // esi
  int m_Size; // ebx
  const char *v3; // eax
  const char *v4; // edi
  int v5; // ebx
  CUtlSymbol *m_pMemory; // eax
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > models; // [esp+Ch] [ebp-1Ch] BYREF
  int offset; // [esp+20h] [ebp-8h]
  int valid; // [esp+24h] [ebp-4h]

  v1 = 0;
  memset(&models, 0, sizeof(models));
  BuildFileList_R(files: &models, dir: basedir, extension: ".mdl");
  offset = strlen(basedir) + 1;
  vprint_queued(owner: 0, fmt: "%s", "\n\n");
  m_Size = models.m_Size;
  valid = 0;
  if ( models.m_Size > 0 )
  {
    do
    {
      v3 = CUtlSymbolTable::String(this: &g_Analysis.symbols, id: models.m_Memory.m_pMemory[v1]);
      v4 = v3;
      if ( verbose )
        vprint(depth: 0, fmt: "checking %i .mdl %s\n", v1, v3);
      if ( ValidateModelFile(modelname: v4, offset) != 0 )
        ++valid;
      ++v1;
    }
    while ( v1 < m_Size );
  }
  v5 = m_Size - valid;
  if ( v5 != 0 )
    vprint(depth: 0, fmt: "summary:  found %i .mdl errors\n", v5);
  m_pMemory = models.m_Memory.m_pMemory;
  models.m_Size = 0;
  if ( models.m_Memory.m_nGrowSize >= 0 )
  {
    if ( models.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: models.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      models.m_Memory.m_pMemory = nullptr;
    }
    models.m_Memory.m_nAllocationCount = 0;
  }
  models.m_pElements = m_pMemory;
  if ( models.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00405FE0
// Name: bool AddModelNameFromSource(class CUtlDict<struct ModelFile,int> __near &,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddModelNameFromSource(
        CUtlDict<ModelFile,int> *models,
        const char *filename,
        const char *modelname,
        int offset)
{
  int v4; // eax
  const char *v5; // ecx
  char v6; // dl
  char *v7; // eax
  char *v8; // edx
  char v9; // cl
  int v10; // eax
  CUtlMap<char const *,ModelFile,int>::Node_t search; // [esp+8h] [ebp-42Ch] BYREF
  char shortname2[260]; // [esp+11Ch] [ebp-318h] BYREF
  char shortname[260]; // [esp+220h] [ebp-214h] BYREF
  ModelFile mf; // [esp+324h] [ebp-110h] BYREF

  if ( modelname == nullptr
    || (search.key = modelname,
        (v4 = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Find(
                this: &models->m_Elements.m_Tree,
                &search)) == -1) )
  {
    strcpy(mf.qcfile, filename);
    strlwr(string: mf.qcfile);
    mf.version = 0;
    CUtlDict<ModelFile,int>::Insert(this: models, pName: modelname, element: &mf);
    return 1;
  }
  else
  {
    v5 = &filename[offset];
    do
    {
      v6 = *v5;
      v5[shortname - &filename[offset]] = *v5;
      ++v5;
    }
    while ( v6 != 0 );
    v7 = &models->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.qcfile[offset];
    v8 = (char *)(shortname2 - v7);
    do
    {
      v9 = *v7;
      v7[(_DWORD)v8] = *v7;
      ++v7;
    }
    while ( v9 != 0 );
    v10 = vprint_owner(path: nullptr, filename);
    vprint_queued(owner: v10, fmt: "multiple .qc's build %s\n  %s\n  %s\n", modelname, shortname, shortname2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004060D0
// Name: void ProcessSourceDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl ProcessSourceDirectory(const char *basedir)
{
  int m_Size; // edi
  int v2; // esi
  const char *v3; // eax
  int v4; // edi
  int m_NumElements; // ebx
  const char *key; // esi
  int v7; // ebx
  CUtlSymbol *m_pMemory; // eax
  QCFile modelname; // [esp+Ch] [ebp-124h] OVERLAPPED BYREF
  int offset; // [esp+110h] [ebp-20h]
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > files; // [esp+114h] [ebp-1Ch] BYREF
  unsigned int v12; // [esp+128h] [ebp-8h]
  int valid; // [esp+12Ch] [ebp-4h]

  memset(&files, 0, sizeof(files));
  BuildFileList_R(&files, dir: basedir, extension: ".qc");
  m_Size = files.m_Size;
  v2 = 0;
  for ( offset = strlen(basedir) + 1; v2 < m_Size; ++v2 )
  {
    memset(dst: (unsigned __int8 *)&modelname, value: 0, count: sizeof(modelname));
    v3 = CUtlSymbolTable::String(this: &g_Analysis.symbols, id: files.m_Memory.m_pMemory[v2]);
    CUtlDict<QCFile,int>::Insert(this: &g_Analysis.files, pName: v3, element: &modelname);
  }
  vprint_queued(owner: 0, fmt: "%s", "\n\n");
  v4 = 0;
  m_NumElements = g_Analysis.files.m_Elements.m_Tree.m_NumElements;
  valid = 0;
  if ( g_Analysis.files.m_Elements.m_Tree.m_NumElements > 0 )
  {
    v12 = 0;
    do
    {
      key = g_Analysis.files.m_Elements.m_Tree.m_Elements.m_pMemory[v12 / 0x118].m_Data.key;
      if ( verbose )
        vprint(
          depth: 0,
          fmt: "checking %i: %s\n",
          v4,
          g_Analysis.files.m_Elements.m_Tree.m_Elements.m_pMemory[v12 / 0x118].m_Data.key);
      if ( GetModelNameFromSourceFile(filename: key, modelname: &modelname.outputmodel[4], maxlen: 256) != 0
        && AddModelNameFromSource(
             models: &g_Analysis.models,
             filename: key,
             modelname: &modelname.outputmodel[4],
             offset) != 0 )
      {
        ++valid;
      }
      v12 += 280;
      ++v4;
    }
    while ( v4 < m_NumElements );
  }
  v7 = m_NumElements - valid;
  if ( v7 != 0 )
    vprint(depth: 0, fmt: "summary:  found %i .qc errors\n", v7);
  m_pMemory = files.m_Memory.m_pMemory;
  files.m_Size = 0;
  if ( files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: files.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      files.m_Memory.m_pMemory = nullptr;
    }
    files.m_Memory.m_nAllocationCount = 0;
  }
  files.m_pElements = m_pMemory;
  if ( files.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00406260
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int i; // esi
  const char *v4; // eax
  const char *v5; // ecx
  char *v6; // edx
  char v7; // al
  const char *v8; // ecx
  char *v9; // edx
  char v10; // al
  int v11; // eax
  CNonFatalLoggingResponsePolicy nonFatalLoggingResponsePolicy; // [esp+Ch] [ebp-4h] BYREF

  nonFatalLoggingResponsePolicy.__vftable = (CNonFatalLoggingResponsePolicy_vtbl *)&CNonFatalLoggingResponsePolicy::`vftable';
  _LoggingSystem_SetLoggingResponsePolicy(a1: &nonFatalLoggingResponsePolicy);
  for ( i = 1; i < argc; ++i )
  {
    v4 = argv[i];
    if ( *v4 == 45 )
    {
      switch ( v4[1] )
      {
        case 'a':
          checkani = true;
          continue;
        case 'l':
          uselogfile = true;
          continue;
        case 'n':
          nop4 = true;
          continue;
        case 'v':
          verbose = true;
          continue;
        default:
          goto LABEL_19;
      }
    }
  }
  vprint_init();
  vprint(depth: 0, fmt: "--- Source Model Consistency Checker ---\n\n");
  if ( argc < 3 || i != argc )
LABEL_19:
    printusage();
  if ( uselogfile )
  {
    _unlink(path: "log.txt");
    vprint(depth: 0, fmt: "    Outputting to log.txt\n");
  }
  v5 = argv[i - 2];
  v6 = g_modelsources;
  do
  {
    v7 = *v5;
    *v6++ = *v5++;
  }
  while ( v7 != 0 );
  v8 = argv[i - 1];
  v9 = g_modelsdir;
  do
  {
    v10 = *v8;
    *v9++ = *v8++;
  }
  while ( v10 != 0 );
  strstr(str1: (unsigned __int8 *)g_modelsdir, str2: "models");
  if ( v11 != 0 )
  {
    V_StripTrailingSlash(ppath: g_modelsources);
    V_StripTrailingSlash(ppath: g_modelsdir);
    if ( !nop4 )
      SetupP4();
    ProcessSourceDirectory(basedir: g_modelsources);
    ProcessModelsDirectory(basedir: g_modelsdir);
    CheckForUnbuiltModels();
    dump_print_queue();
    return 0;
  }
  else
  {
    vprint(depth: 0, fmt: "Models dir %s looks invalid (format:  u:/tf2/hl2/models)\n", g_modelsdir);
    return 0;
  }
}
