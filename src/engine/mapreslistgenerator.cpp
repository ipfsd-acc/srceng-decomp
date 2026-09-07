// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/mapreslistgenerator.cpp
// Functions: 32
// ============================================================

#include "engine\mapreslistgenerator.h"

//------------------------------------------------------------------------------
// Address: 0x101A04D0
// Name: void MapReslistGenerator_Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapReslistGenerator_Usage()
{
  _Msg(a1: "-makereslists usage:\n");
  _Msg(
    a1: "  [ -makereslists <optionalscriptfile> ] -- script file to control more complex makereslists operations (multiple passes, etc.)\n");
  _Msg(a1: "  [ -usereslistfile filename ] -- get map list from specified file, default is to build for maps/*.bsp\n");
  _Msg(a1: "  [ -startmap mapname ] -- restart generation at specified map (after crash, implies resume)\n");
  _Msg(a1: "  [ -condebug ] -- prepend console.log entries with mapname or engine if not in a map\n");
  _Msg(a1: "  [ +map mapname ] -- generate reslists for specified map and exit after that map\n");
  _Msg(a1: "  [ -rebuildaudio ] -- force rebuild of _other_rebuild.cache (metacache) file at exit\n");
  _Msg(a1: "  [ -forever ] -- when you get to the end of the maplist, start over from the top\n");
  _Msg(a1: "  [ -stringtables ] -- force rebuild of the .bsp's stringtable dictionary\n");
  _Msg(a1: "  [ -reslistdir ] -- default is 'reslists', use this to override\n");
  _Msg(a1: "  [ -startstage nnn ] -- when running from script file, this starts at specified stage\n");
  _Msg(a1: "  [ -collate ] -- skip everything, just merge the reslist from temp folders to the final folder again\n");
}

//------------------------------------------------------------------------------
// Address: 0x101A0530
// Name: class CMapReslistGenerator __near & MapReslistGenerator(void)
// Source: json
//------------------------------------------------------------------------------
CMapReslistGenerator *__cdecl MapReslistGenerator()
{
  return &g_MapReslistGenerator;
}

//------------------------------------------------------------------------------
// Address: 0x101A0540
// Name: ReslistLogLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ReslistLogLessFunc(CUtlString *pLHS, CUtlString *pRHS)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: pRHS);
  v3 = CUtlString::operator char const *(this: pLHS);
  if ( v3 == nullptr )
    return false;
  if ( v2 != nullptr )
    return _V_stricmp(s1: v3, s2: v2) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101A0580
// Name: public: void CMapReslistGenerator::StartReslistGeneration(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::StartReslistGeneration(CMapReslistGenerator *this)
{
  int m_iPauseFramesBetweenMaps; // eax

  m_iPauseFramesBetweenMaps = this->m_iPauseFramesBetweenMaps;
  this->m_iCurrentMap = 0;
  this->m_iFrameCountdownToRunningNextMap = m_iPauseFramesBetweenMaps;
  this->m_flNextMapRunTime = _Plat_FloatTime((CStatTime *)this) + (double)this->m_iPauseTimeBetweenMaps;
}

//------------------------------------------------------------------------------
// Address: 0x101A05A0
// Name: private: void CMapReslistGenerator::SetPrefix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::SetPrefix(CMapReslistGenerator *this, const char *mapname)
{
  V_snprintf(pDest: this->m_szPrefix, maxLen: 64, pFormat: "%s:  ", mapname);
}

//------------------------------------------------------------------------------
// Address: 0x101A05D0
// Name: public: char const __near * CMapReslistGenerator::LogPrefix(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapReslistGenerator::LogPrefix(CMapReslistGenerator *this)
{
  char *result; // eax

  result = "engine:  ";
  if ( !this->m_bLogToEngineList )
    return this->m_szPrefix;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A05E0
// Name: public: void CMapReslistGenerator::OnPlayerSpawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnPlayerSpawn(CMapReslistGenerator *this)
{
  if ( this->m_bLoggingEnabled )
  {
    this->m_iFrameCountdownToRunningNextMap = this->m_iPauseFramesBetweenMaps;
    this->m_flNextMapRunTime = _Plat_FloatTime((CStatTime *)this) + (double)this->m_iPauseTimeBetweenMaps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A0600
// Name: public: char const __near * CMapReslistGenerator::GetResListDirectory(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapReslistGenerator::GetResListDirectory(CMapReslistGenerator *this)
{
  return CUtlString::operator char const *(this: &this->m_sResListDir);
}

//------------------------------------------------------------------------------
// Address: 0x101A0610
// Name: public: bool CMapReslistGenerator::IsCreatingForXbox(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapReslistGenerator::IsCreatingForXbox(CMapReslistGenerator *this)
{
  return this->m_bLoggingEnabled && this->m_bCreatingForXbox;
}

//------------------------------------------------------------------------------
// Address: 0x101A2550
// Name: private: void CMapReslistGenerator::WriteMapLog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::WriteMapLog(CMapReslistGenerator *this)
{
  CMapReslistGenerator *v1; // edi
  bool v2; // zf
  const char *v3; // eax
  void *v4; // ebx
  int Inorder; // esi
  const char *v6; // eax
  IBaseFileSystem_vtbl *v7; // edx
  IBaseFileSystem_vtbl *v8; // edi
  int v9; // eax
  char *m_szLevelName; // [esp-8h] [ebp-118h]
  char path[260]; // [esp+4h] [ebp-10Ch] BYREF
  const char *pLine; // [esp+108h] [ebp-8h]
  CMapReslistGenerator *v13; // [esp+10Ch] [ebp-4h]

  v1 = this;
  v2 = this->m_szLevelName[0] == 0;
  v13 = this;
  if ( !v2 )
  {
    m_szLevelName = this->m_szLevelName;
    v3 = CUtlString::operator char const *(this: &this->m_sResListDir);
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s\\%s.lst", v3, m_szLevelName);
    v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: path, a3: "wt", a4: "DEFAULT_WRITE_PATH");
    if ( v4 != nullptr )
    {
      Inorder = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::FirstInorder(this: &v1->m_MapLog);
      if ( Inorder != -1 )
      {
        while ( 1 )
        {
          v6 = CUtlString::operator char const *(this: &v1->m_MapLog.m_Elements.m_pMemory[Inorder].m_Data);
          v7 = g_pFileSystem->IBaseFileSystem::__vftable;
          pLine = v6;
          v7->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: v4);
          v8 = g_pFileSystem->IBaseFileSystem::__vftable;
          v9 = _V_strlen(str: pLine);
          v8->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pLine, a3: v9, a4: v4);
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: v4);
          Inorder = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::NextInorder(
                      this: &v13->m_MapLog,
                      i: Inorder);
          if ( Inorder == -1 )
            break;
          v1 = v13;
        }
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2690
// Name: private: void CMapReslistGenerator::SpewTrackedDeletionsLog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::SpewTrackedDeletionsLog(CMapReslistGenerator *this)
{
  CMapReslistGenerator *v1; // edi
  void *v2; // ebx
  int Inorder; // esi
  IBaseFileSystem_vtbl *v4; // edi
  int v5; // eax
  char *str; // [esp+10h] [ebp-4h]

  v1 = this;
  if ( this->m_bTrackingDeletions )
  {
    v2 = g_pFileSystem->Open(
           this: &g_pFileSystem->IBaseFileSystem,
           a2: "undelete.lst",
           a3: "wt",
           a4: "DEFAULT_WRITE_PATH");
    if ( v2 != nullptr )
    {
      Inorder = CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::FirstInorder(this: &v1->m_DeletionListWarnings);
      if ( Inorder != 0xFFFF )
      {
        while ( 1 )
        {
          str = (char *)CUtlSymbolTable::String(
                          this: &v1->m_DeletionListWarningsSymbols,
                          id: v1->m_DeletionListWarnings.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data);
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: v2);
          v4 = g_pFileSystem->IBaseFileSystem::__vftable;
          v5 = _V_strlen(str);
          v4->Write(this: &g_pFileSystem->IBaseFileSystem, a2: str, a3: v5, a4: v2);
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: v2);
          Inorder = CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::NextInorder(
                      this: &this->m_DeletionListWarnings,
                      i: Inorder);
          if ( Inorder == 0xFFFF )
            break;
          v1 = this;
        }
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2910
// Name: bool BuildGeneralMapList(class CUtlVector<struct maplist_map_t,class CUtlMemory<struct maplist_map_t,int>> __near *,bool,char const __near *,char __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildGeneralMapList(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *aMaps,
        const char *bUseMapListFile,
        const char *pMapFile,
        char *pSystemMsg,
        int *iCurrentMap)
{
  int v5; // eax
  int v6; // ecx
  const char *First; // edi
  IBaseFileSystem_vtbl *v8; // esi
  char *v9; // eax
  _BYTE *v10; // eax
  const char *v11; // esi
  void *v12; // ebx
  int v13; // eax
  int v14; // esi
  char *v15; // edi
  const char *i; // esi
  int m_Size; // ebx
  int v18; // esi
  int v20; // eax
  int v21; // edi
  int v22; // edi
  int v23; // esi
  char szMap[260]; // [esp+Ch] [ebp-148h] BYREF
  maplist_map_t newMap; // [esp+110h] [ebp-44h] BYREF
  const char *startmap; // [esp+150h] [ebp-4h] BYREF

  if ( (_BYTE)bUseMapListFile != 0 )
  {
    v11 = pMapFile;
    if ( pMapFile == nullptr )
    {
      _Error(a1: "Unable to find %s maplist filename\n", pSystemMsg);
      return 0;
    }
    v12 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pMapFile, a3: "rb", a4: 0);
    if ( v12 == nullptr )
    {
      _Error(a1: "Unable to load %s maplist file: %s\n", pSystemMsg, v11);
      return 0;
    }
    v13 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v12);
    v14 = v13;
    if ( v13 > 0 )
    {
      v15 = (char *)MemAlloc_Alloc(nSize: v13 + 1);
      if ( v15 != nullptr
        && v14 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v15, a3: v14, a4: v12) )
      {
        v15[v14] = 0;
        for ( i = COM_Parse(data: v15); strlen(com_token) != 0; i = COM_Parse(data: i) )
        {
          V_strncpy(pDest: szMap, pSrc: com_token, maxLen: 260);
          if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: szMap) != 0 )
          {
            for ( ; COM_TokenWaiting(buffer: i) != 0; i = COM_Parse(data: i) )
              ;
            V_strncpy(pDest: newMap.name, pSrc: szMap, maxLen: 64);
            CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
              this: aMaps,
              elem: aMaps->m_Size,
              src: (const VMatrix *)&newMap);
          }
        }
      }
      free(pMem: v15);
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v12);
  }
  else
  {
    bUseMapListFile = nullptr;
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: "+map",
           a3: &bUseMapListFile) != 0
      && bUseMapListFile != nullptr )
    {
      if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: bUseMapListFile) != 0 )
      {
        V_strncpy(pDest: newMap.name, pSrc: bUseMapListFile, maxLen: 64);
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
          this: aMaps,
          elem: aMaps->m_Size,
          src: (const VMatrix *)&newMap);
      }
      v6 = _CommandLine();
      (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 16))(a1: v6, a2: "+map");
    }
    else
    {
      First = Sys_FindFirst(path: "maps/*.bsp", basename: nullptr, namelength: 0);
      while ( First != nullptr )
      {
        v8 = g_pFileSystem->IBaseFileSystem::__vftable;
        v9 = va(format: "maps/%s", First);
        if ( v8->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v9, a3: "MOD") )
        {
          V_strncpy(pDest: szMap, pSrc: First, maxLen: 260);
          strchr(string: (unsigned __int8 *)szMap, chr: 0x2Eu);
          if ( v10 != nullptr )
            *v10 = 0;
          First = Sys_FindNext(basename: nullptr, namelength: 0);
          if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: szMap) != 0 )
          {
            V_strncpy(pDest: newMap.name, pSrc: szMap, maxLen: 64);
            CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
              this: aMaps,
              elem: aMaps->m_Size,
              src: (const VMatrix *)&newMap);
          }
        }
        else
        {
          First = Sys_FindNext(basename: nullptr, namelength: 0);
        }
      }
      Sys_FindClose();
    }
  }
  m_Size = aMaps->m_Size;
  v18 = 0;
  if ( m_Size != 0 )
  {
    _Msg(a1: "%s: Creating for:\n", pSystemMsg);
    *iCurrentMap = 0;
    startmap = nullptr;
    v20 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v20 + 12))(
           a1: v20,
           a2: "-startmap",
           a3: &startmap) != 0
      && startmap != nullptr
      && m_Size > 0 )
    {
      v21 = 0;
      do
      {
        if ( _V_stricmp(s1: (const char *)&aMaps->m_Memory.m_pMemory[v21], s2: startmap) == 0 )
          *iCurrentMap = v18;
        ++v18;
        ++v21;
      }
      while ( v18 < m_Size );
    }
    v22 = 0;
    if ( m_Size > 0 )
    {
      v23 = 0;
      do
      {
        if ( v22 >= *iCurrentMap )
          _Msg(a1: "+  %s\n", &aMaps->m_Memory.m_pMemory[v23]);
        else
          _Msg(a1: "-  %s\n", &aMaps->m_Memory.m_pMemory[v23]);
        ++v22;
        ++v23;
      }
      while ( v22 < m_Size );
    }
    return 1;
  }
  else
  {
    _Msg(a1: "%s: No maps found\n", pSystemMsg);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2E10
// Name: public: void CMapReslistGenerator::BuildMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::BuildMapList(CMapReslistGenerator *this)
{
  int v2; // eax
  int v3; // eax
  bool v4; // al
  int v5; // eax
  bool bUseMapListFile; // [esp+4h] [ebp-8h]
  const char *pMapFile; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_bLoggingEnabled )
  {
    MapReslistGenerator_Usage();
    pMapFile = nullptr;
    v2 = _CommandLine();
    (*(void (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v2 + 12))(
      a1: v2,
      a2: "-usereslistfile",
      a3: &pMapFile);
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "+map") != 0 )
    {
      v4 = BuildGeneralMapList(
             aMaps: &this->m_Maps,
             bUseMapListFile: false,
             pMapFile,
             pSystemMsg: "reslists",
             iCurrentMap: &this->m_iCurrentMap);
    }
    else
    {
      v5 = _CommandLine();
      bUseMapListFile = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-usereslistfile") != 0;
      v4 = BuildGeneralMapList(
             aMaps: &this->m_Maps,
             bUseMapListFile,
             pMapFile,
             pSystemMsg: "reslists",
             iCurrentMap: &this->m_iCurrentMap);
    }
    if ( !v4 )
      this->m_bLoggingEnabled = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2FF0
// Name: void MapReslistGenerator_BuildMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapReslistGenerator_BuildMapList()
{
  CMapReslistGenerator::BuildMapList(this: &g_MapReslistGenerator);
}

//------------------------------------------------------------------------------
// Address: 0x101A3000
// Name: public: CMapReslistGenerator::~CMapReslistGenerator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::~CMapReslistGenerator(CMapReslistGenerator *this)
{
  bool v2; // sf

  v2 = this->m_sResListDir.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_sResListDir.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_sResListDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sResListDir.m_Storage.m_Memory.m_pMemory);
      this->m_sResListDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sResListDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::~CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>(this: &this->m_EngineLog);
  CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::~CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>(this: &this->m_MapLog);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_DeletionListWarningsSymbols);
  CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>(this: &this->m_DeletionListWarnings);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_DeletionList);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_AlreadyWrittenFileNames);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Maps);
}

//------------------------------------------------------------------------------
// Address: 0x101A3090
// Name: public: CMapReslistGenerator::CMapReslistGenerator(void)
// Source: json
//------------------------------------------------------------------------------
CMapReslistGenerator *__thiscall CMapReslistGenerator::CMapReslistGenerator(CMapReslistGenerator *this)
{
  this->m_bAutoQuit = false;
  this->m_Maps.m_Memory.m_pMemory = nullptr;
  this->m_Maps.m_Memory.m_nAllocationCount = 0;
  this->m_Maps.m_Memory.m_nGrowSize = 0;
  this->m_Maps.m_Size = 0;
  this->m_Maps.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_AlreadyWrittenFileNames,
    growSize: 0,
    initSize: 0,
    caseInsensitive: true);
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_DeletionList, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_DeletionListWarnings.m_LessFunc = (bool (__cdecl *)(const CUtlSymbol *, const CUtlSymbol *))CDefOps<unsigned short>::LessFunc;
  this->m_DeletionListWarnings.m_Elements.m_pMemory = nullptr;
  this->m_DeletionListWarnings.m_Elements.m_nAllocationCount = 0;
  this->m_DeletionListWarnings.m_Elements.m_nGrowSize = 0;
  this->m_DeletionListWarnings.m_pElements = this->m_DeletionListWarnings.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_DeletionListWarnings.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_DeletionListWarnings.m_FirstFree = -1;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_DeletionListWarningsSymbols,
    growSize: 0,
    initSize: 16,
    caseInsensitive: false);
  this->m_MapLog.m_LessFunc = ReslistLogLessFunc;
  this->m_MapLog.m_Elements.m_pMemory = nullptr;
  this->m_MapLog.m_Elements.m_nAllocationCount = 0;
  this->m_MapLog.m_Elements.m_nGrowSize = 0;
  this->m_MapLog.m_Root = -1;
  this->m_MapLog.m_NumElements = 0;
  this->m_MapLog.m_FirstFree = -1;
  this->m_MapLog.m_LastAlloc.index = -1;
  this->m_MapLog.m_pElements = this->m_MapLog.m_Elements.m_pMemory;
  this->m_EngineLog.m_LessFunc = ReslistLogLessFunc;
  this->m_EngineLog.m_Elements.m_pMemory = nullptr;
  this->m_EngineLog.m_Elements.m_nAllocationCount = 0;
  this->m_EngineLog.m_Elements.m_nGrowSize = 0;
  this->m_EngineLog.m_Root = -1;
  this->m_EngineLog.m_FirstFree = -1;
  this->m_EngineLog.m_NumElements = 0;
  this->m_EngineLog.m_LastAlloc.index = -1;
  this->m_EngineLog.m_pElements = this->m_EngineLog.m_Elements.m_pMemory;
  CUtlString::CUtlString(this: &this->m_sResListDir);
  this->m_bUsingMapList = false;
  *(_WORD *)&this->m_bTrackingDeletions = 0;
  this->m_iCurrentMap = 0;
  this->m_flNextMapRunTime = 0.0;
  this->m_iFrameCountdownToRunningNextMap = 0;
  this->m_szPrefix[0] = 0;
  this->m_szLevelName[0] = 0;
  this->m_iPauseTimeBetweenMaps = 2;
  this->m_iPauseFramesBetweenMaps = 300;
  *(_WORD *)&this->m_bRestartOnTransition = 0;
  this->m_bLogToEngineList = true;
  CUtlString::operator=(this: &this->m_sResListDir, src: "reslists");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A31F0
// Name: private: void CMapReslistGenerator::BuildEngineLogFromReslist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::BuildEngineLogFromReslist(CMapReslistGenerator *this)
{
  CUtlRBTree<CUtlString,int,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int> > *p_m_EngineLog; // esi
  const char *v3; // eax
  CFmtStrN<256> *v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // edi
  UtlRBTreeNode_t<CUtlString,int> *v9; // ecx
  UtlRBTreeNode_t<CUtlString,int> *m_pMemory; // ecx
  int v11; // edx
  UtlRBTreeNode_t<CUtlString,int> *v12; // edx
  CFmtStrN<256> v13; // [esp+Ch] [ebp-368h] BYREF
  characterset_t breakSet; // [esp+118h] [ebp-25Ch] BYREF
  char szToken[260]; // [esp+218h] [ebp-15Ch] BYREF
  CUtlBuffer buffer; // [esp+31Ch] [ebp-58h] BYREF
  CUtlString search; // [esp+34Ch] [ebp-28h] BYREF
  CUtlString insert; // [esp+35Ch] [ebp-18h] BYREF
  int parent; // [esp+36Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+373h] [ebp-1h] BYREF

  p_m_EngineLog = &this->m_EngineLog;
  CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &this->m_EngineLog);
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 1);
  v3 = CUtlString::operator char const *(this: &this->m_sResListDir);
  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "%s\\%s", v3, "engine.lst");
  if ( g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: v4->m_szBuf,
         a3: "DEFAULT_WRITE_PATH",
         a4: &buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: defaultValue);
    while ( CUtlBuffer::ParseToken(
              this: &buffer,
              pBreaks: &breakSet,
              pTokenBuf: szToken,
              nMaxLen: 260,
              bParseComments: true) > 0 )
    {
      CUtlString::CUtlString(this: &search, pString: szToken);
      v5 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
             this: p_m_EngineLog,
             &search);
      search.m_Storage.m_nActualLength = 0;
      if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( search.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
          search.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        search.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      if ( v5 == -1 )
      {
        CUtlString::CUtlString(this: &insert, pString: szToken);
        parent = -1;
        leftchild = false;
        CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::FindInsertionPosition(
          this: p_m_EngineLog,
          &insert,
          &parent,
          &leftchild);
        v6 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::NewNode(this: p_m_EngineLog);
        v7 = parent;
        v8 = v6;
        v9 = &p_m_EngineLog->m_Elements.m_pMemory[v6];
        v9->m_Parent = parent;
        v9->m_Right = -1;
        v9->m_Left = -1;
        v9->m_Tag = 0;
        if ( v7 == -1 )
        {
          p_m_EngineLog->m_Root = v6;
        }
        else
        {
          m_pMemory = p_m_EngineLog->m_Elements.m_pMemory;
          v11 = v7;
          if ( leftchild )
            m_pMemory[v11].m_Left = v6;
          else
            m_pMemory[v11].m_Right = v6;
        }
        CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::InsertRebalance(
          this: p_m_EngineLog,
          elem: v6);
        v12 = p_m_EngineLog->m_Elements.m_pMemory;
        ++p_m_EngineLog->m_NumElements;
        if ( &v12[v8] != (UtlRBTreeNode_t<CUtlString,int> *)-16 )
          CUtlString::CUtlString(this: &v12[v8].m_Data, string: &insert);
        insert.m_Storage.m_nActualLength = 0;
        if ( insert.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( insert.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.m_Storage.m_Memory.m_pMemory);
            insert.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          insert.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
    }
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101A33F0
// Name: private: void CMapReslistGenerator::LogToEngineReslist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::LogToEngineReslist(CMapReslistGenerator *this, const char *pLine)
{
  const char *v4; // eax
  CFmtStrN<256> *v5; // eax
  void *v6; // esi
  IBaseFileSystem_vtbl *v7; // edi
  int v8; // eax
  CFmtStrN<256> v9; // [esp+Ch] [ebp-11Ch] BYREF
  CUtlString search; // [esp+118h] [ebp-10h] BYREF
  int idx; // [esp+130h] [ebp+8h]

  CUtlString::CUtlString(this: &search, pString: pLine);
  idx = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
          this: &this->m_EngineLog,
          &search);
  search.m_Storage.m_nActualLength = 0;
  if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
  if ( idx == -1 )
  {
    CUtlString::CUtlString(this: &search, pString: pLine);
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Insert(
      this: &this->m_EngineLog,
      insert: &search);
    search.m_Storage.m_nActualLength = 0;
    if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
    v4 = CUtlString::operator char const *(this: &this->m_sResListDir);
    v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "%s\\%s", v4, "engine.lst");
    v6 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v5->m_szBuf, a3: "at", a4: "DEFAULT_WRITE_PATH");
    if ( v6 != nullptr )
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: v6);
      v7 = g_pFileSystem->IBaseFileSystem::__vftable;
      v8 = _V_strlen(str: pLine);
      v7->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pLine, a3: v8, a4: v6);
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: v6);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3540
// Name: private: void CMapReslistGenerator::OnResourcePrecachedFullPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnResourcePrecachedFullPath(
        CMapReslistGenerator *this,
        const char *fullPathFileName)
{
  int v3; // eax
  char *v4; // eax
  char *v5; // edi
  char *v6; // edi
  const char *v7; // edi
  int v8; // ebx
  char file[260]; // [esp+8h] [ebp-218h] BYREF
  char fixed[260]; // [esp+10Ch] [ebp-114h] BYREF
  CUtlString search; // [esp+210h] [ebp-10h] BYREF

  V_strncpy(pDest: fixed, pSrc: fullPathFileName, maxLen: 260);
  _V_strlower(start: fixed);
  V_FixSlashes(pname: fixed, separator: 92);
  if ( CUtlSymbolTable::Find(
         this: &this->m_AlreadyWrittenFileNames,
         result: (CUtlSymbol *)&fullPathFileName + 1,
         pString: fixed)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(
      this: &this->m_AlreadyWrittenFileNames,
      result: (CUtlSymbol *)&fullPathFileName + 1,
      pString: fixed);
    strstr(str1: (unsigned __int8 *)fixed, str2: ".mdl");
    if ( v3 != 0 )
    {
      V_strncpy(pDest: file, pSrc: fixed, maxLen: 250);
      strstr(str1: (unsigned __int8 *)file, str2: ".mdl");
      v5 = v4;
      V_strncpy(pDest: v4, pSrc: ".vvd", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
      V_strncpy(pDest: v5, pSrc: ".ani", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
      V_strncpy(pDest: v5, pSrc: ".dx90.vtx", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
      V_strncpy(pDest: v5, pSrc: ".phy", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
      V_strncpy(pDest: v5, pSrc: ".jpg", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
    }
    v6 = V_stristr(pStr: fixed, pSearch: host_parms.basedir);
    if ( v6 != nullptr )
    {
      v7 = &v6[_V_strlen(str: host_parms.basedir) + 1];
      if ( v7 != nullptr )
      {
        if ( this->m_bLogToEngineList )
        {
          CMapReslistGenerator::LogToEngineReslist(this, pLine: v7);
        }
        else
        {
          CUtlString::CUtlString(this: &search, pString: v7);
          v8 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
                 this: &this->m_MapLog,
                 &search);
          CUtlString::~CUtlString(this: &search);
          if ( v8 == -1 )
          {
            CUtlString::CUtlString(this: &search, pString: v7);
            CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Insert(
              this: &this->m_MapLog,
              insert: &search);
            CUtlString::~CUtlString(this: &search);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3730
// Name: private: static void CMapReslistGenerator::FileSystemLoggingFunc(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapReslistGenerator::FileSystemLoggingFunc(const char *fullPathFileName)
{
  CMapReslistGenerator::OnResourcePrecachedFullPath(this: &g_MapReslistGenerator, fullPathFileName);
}

//------------------------------------------------------------------------------
// Address: 0x101A3750
// Name: public: void CMapReslistGenerator::TrackDeletions(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::TrackDeletions(CMapReslistGenerator *this, const char *fullPathFileName)
{
  int v3; // eax
  char *v4; // eax
  char *v5; // edi
  char test[260]; // [esp+8h] [ebp-20Ch] BYREF
  char file[260]; // [esp+10Ch] [ebp-108h] BYREF
  CUtlSymbol sym; // [esp+210h] [ebp-4h] BYREF

  V_strncpy(pDest: test, pSrc: fullPathFileName, maxLen: 260);
  V_FixSlashes(pname: test, separator: 92);
  _V_strlower(start: test);
  CUtlSymbolTable::Find(this: &this->m_DeletionList, result: &sym, pString: test);
  if ( sym.m_Id != 0xFFFF )
  {
    CUtlSymbolTable::AddString(
      this: &this->m_DeletionListWarningsSymbols,
      result: (CUtlSymbol *)&fullPathFileName,
      pString: test);
    if ( CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::Find(
           this: &this->m_DeletionListWarnings,
           search: (const CUtlSymbol *)&fullPathFileName) == 0xFFFF )
    {
      _Msg(a1: "--> Referenced file marked for deletion \"%s\"\n", test);
      CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::Insert(
        this: &this->m_DeletionListWarnings,
        insert: (const CUtlSymbol *)&fullPathFileName);
    }
  }
  strstr(str1: (unsigned __int8 *)test, str2: ".mdl");
  if ( v3 != 0 )
  {
    V_strncpy(pDest: file, pSrc: test, maxLen: 250);
    strstr(str1: (unsigned __int8 *)file, str2: ".mdl");
    v5 = v4;
    V_strncpy(pDest: v4, pSrc: ".vvd", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".ani", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".dx80.vtx", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".dx90.vtx", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".sw.vtx", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".phy", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".jpg", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3930
// Name: private: static void CMapReslistGenerator::TrackDeletionsLoggingFunc(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapReslistGenerator::TrackDeletionsLoggingFunc(const char *fullPathFileName)
{
  CMapReslistGenerator::TrackDeletions(this: &g_MapReslistGenerator, fullPathFileName);
}

//------------------------------------------------------------------------------
// Address: 0x101A3950
// Name: void MapReslistGenerator_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapReslistGenerator_Shutdown()
{
  if ( g_MapReslistGenerator.m_bTrackingDeletions )
  {
    CMapReslistGenerator::SpewTrackedDeletionsLog(this: &g_MapReslistGenerator);
    g_pFileSystem->RemoveLoggingFunc(
      this: g_pFileSystem,
      a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::TrackDeletionsLoggingFunc);
    CUtlSymbolTable::RemoveAll(this: &g_MapReslistGenerator.m_DeletionList);
    CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::RemoveAll(this: &g_MapReslistGenerator.m_DeletionListWarnings);
    CUtlSymbolTable::RemoveAll(this: &g_MapReslistGenerator.m_DeletionListWarningsSymbols);
    g_MapReslistGenerator.m_bTrackingDeletions = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A39A0
// Name: public: void CMapReslistGenerator::EnableReslistGeneration(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::EnableReslistGeneration(CMapReslistGenerator *this, bool usemaplistfile)
{
  int v3; // eax
  int v4; // eax
  const char *v5; // eax
  int v6; // eax
  const char *v7; // eax
  CFmtStrN<256> *v8; // eax
  CFmtStrN<256> v9; // [esp+8h] [ebp-110h] BYREF
  const char *pszDir; // [esp+114h] [ebp-4h] BYREF

  if ( _V_stricmp(s1: "cstrike", s2: host_parms.mod) == 0 || _V_stricmp(s1: "cstrike15", s2: host_parms.mod) == 0 )
  {
    this->m_iPauseTimeBetweenMaps = 6;
    this->m_iPauseFramesBetweenMaps = 900;
  }
  this->m_bUsingMapList = usemaplistfile;
  this->m_bLoggingEnabled = true;
  pszDir = nullptr;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v3 + 12))(
         a1: v3,
         a2: "-reslistdir",
         a3: &pszDir) != 0
    && pszDir != nullptr )
  {
    V_strncpy(pDest: &v9.m_szBuf[3], pSrc: pszDir, maxLen: 260);
    V_StripTrailingSlash(ppath: &v9.m_szBuf[3]);
    _V_strlower(start: &v9.m_szBuf[3]);
    V_FixSlashes(pname: &v9.m_szBuf[3], separator: 92);
    if ( _V_strlen(str: &v9.m_szBuf[3]) > 0 )
      CUtlString::operator=(this: &this->m_sResListDir, src: &v9.m_szBuf[3]);
  }
  v4 = _CommandLine();
  this->m_bCreatingForXbox = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-xboxreslist") != 0;
  v5 = CUtlString::operator char const *(this: &this->m_sResListDir);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: v5, a3: "DEFAULT_WRITE_PATH");
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-startmap") != 0 )
  {
    CMapReslistGenerator::BuildEngineLogFromReslist(this);
  }
  else
  {
    v7 = CUtlString::operator char const *(this: &this->m_sResListDir);
    v8 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "%s\\%s", v7, "engine.lst");
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: v8->m_szBuf, a3: "DEFAULT_WRITE_PATH");
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &this->m_EngineLog);
  }
  g_pFileSystem->AddLoggingFunc(
    this: g_pFileSystem,
    a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::FileSystemLoggingFunc);
}

//------------------------------------------------------------------------------
// Address: 0x101A3B40
// Name: private: void CMapReslistGenerator::DoQuit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::DoQuit(CMapReslistGenerator *this)
{
  ECommandTarget_t TraceType; // eax

  TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
  Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
  g_pFileSystem->RemoveLoggingFunc(
    this: g_pFileSystem,
    a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::FileSystemLoggingFunc);
  this->m_bLogToEngineList = true;
}

//------------------------------------------------------------------------------
// Address: 0x101A3B80
// Name: public: void CMapReslistGenerator::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::RunFrame(CMapReslistGenerator *this)
{
  ECommandTarget_t v2; // eax
  int m_iCurrentMap; // eax
  bool v4; // zf
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  const char *v10; // [esp-Ch] [ebp-18h]
  float m_flNextMapRunTime; // [esp+8h] [ebp-4h]

  if ( this->m_bLoggingEnabled )
  {
    if ( --this->m_iFrameCountdownToRunningNextMap <= 0 && this->m_flNextMapRunTime != 0.0 )
    {
      m_flNextMapRunTime = this->m_flNextMapRunTime;
      if ( _Plat_FloatTime((CStatTime *)this) > (double)m_flNextMapRunTime )
      {
        CMapReslistGenerator::WriteMapLog(this);
        m_iCurrentMap = this->m_iCurrentMap;
        if ( m_iCurrentMap < 0 || m_iCurrentMap >= this->m_Maps.m_Size )
        {
          v9 = _CommandLine();
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(a1: v9, a2: "-forever") != 0 )
          {
            CMapReslistGenerator::StartReslistGeneration(this);
            this->m_bRestartOnTransition = true;
          }
          else
          {
            CMapReslistGenerator::DoQuit(this);
          }
        }
        else
        {
          v4 = !this->m_bRestartOnTransition;
          *(_QWORD *)&this->m_flNextMapRunTime = 0;
          if ( v4 )
          {
            v10 = va(format: "map %s\n", this->m_Maps.m_Memory.m_pMemory[m_iCurrentMap].name);
            TraceType = CTraceFilter::GetTraceType(this: v5);
            Cbuf_AddText(eTarget: TraceType, pText: v10, nTickDelay: 0);
            CMapReslistGenerator::SetPrefix(this, mapname: this->m_Maps.m_Memory.m_pMemory[this->m_iCurrentMap].name);
            if ( CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int>>::IsValidIndex(
                   this: (vgui::ImageList *)&this->m_Maps,
                   imageIndex: ++this->m_iCurrentMap) )
            {
              this->m_bRestartOnTransition = true;
            }
          }
          else
          {
            v7 = _CommandLine();
            (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 16))(a1: v7, a2: "-startmap");
            v8 = _CommandLine();
            (*(void (__thiscall **)(int, const char *, maplist_map_t *))(*(_DWORD *)v8 + 20))(
              a1: v8,
              a2: "-startmap",
              a3: &this->m_Maps.m_Memory.m_pMemory[this->m_iCurrentMap]);
            HostState_Restart();
          }
        }
      }
    }
  }
  else if ( this->m_bAutoQuit )
  {
    this->m_bAutoQuit = false;
    v2 = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
    Cbuf_AddText(eTarget: v2, pText: "quit\n", nTickDelay: 0);
    g_pFileSystem->RemoveLoggingFunc(
      this: g_pFileSystem,
      a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::FileSystemLoggingFunc);
    this->m_bLogToEngineList = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3D00
// Name: public: void CMapReslistGenerator::OnResourcePrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnResourcePrecached(CMapReslistGenerator *this, const char *relativePathFileName)
{
  char fullPath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_bLoggingEnabled
    && *relativePathFileName != 0
    && *relativePathFileName != 42
    && g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: relativePathFileName, a3: fullPath, a4: 260) != nullptr )
  {
    CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: fullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3D70
// Name: public: void CMapReslistGenerator::EnableDeletionsTracking(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::EnableDeletionsTracking(CMapReslistGenerator *this)
{
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // edx
  void *v3; // edi
  int v4; // esi
  char *v5; // eax
  const char *i; // esi
  char *v7; // edi
  int v8; // esi
  char *v9; // ebx
  const char *v10; // edi
  CUtlSymbolTable *v11; // esi
  char *v12; // [esp-4h] [ebp-12Ch]
  char filename[264]; // [esp+Ch] [ebp-11Ch] BYREF
  CUtlSymbolTable *v14; // [esp+114h] [ebp-14h]
  unsigned int deletions; // [esp+118h] [ebp-10h]
  unsigned int warnings; // [esp+11Ch] [ebp-Ch]
  char *pStart; // [esp+120h] [ebp-8h]
  CUtlSymbol sym; // [esp+124h] [ebp-4h] BYREF

  this->m_bTrackingDeletions = true;
  Open = g_pFileSystem->Open;
  v14 = (CUtlSymbolTable *)this;
  deletions = 0;
  warnings = 0;
  v3 = Open(this: &g_pFileSystem->IBaseFileSystem, a2: "deletions.bat", a3: "rb", a4: nullptr);
  if ( v3 != nullptr )
  {
    v4 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    if ( v4 > 0 )
    {
      v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
      pStart = v5;
      if ( v5 != nullptr )
      {
        if ( v4 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v5, a3: v4, a4: v3) )
        {
          v12 = pStart;
          pStart[v4] = 0;
          for ( i = COM_Parse(data: v12); strlen(com_token) != 0; i = COM_Parse(data: i) )
          {
            if ( _V_stricmp(s1: com_token, s2: "del") != 0 )
            {
              V_snprintf(pDest: filename, maxLen: 260, pFormat: "%s/%s", com_gamedir, com_token);
              for ( ; COM_TokenWaiting(buffer: i) != 0; i = COM_Parse(data: i) )
                ;
              V_FixSlashes(pname: filename, separator: 92);
              _V_strlower(start: filename);
              CUtlSymbolTable::AddString(this: &this->m_DeletionList, result: &sym, pString: filename);
              ++deletions;
            }
          }
        }
        v5 = pStart;
      }
      free(pMem: v5);
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    v7 = (char *)g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "undelete.lst", a3: "rb", a4: 0);
    pStart = v7;
    if ( v7 != nullptr )
    {
      v8 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
      if ( v8 > 0 )
      {
        v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
        if ( v9 != nullptr && v8 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v9, a3: v8, a4: v7) )
        {
          v9[v8] = 0;
          v10 = COM_Parse(data: v9);
          if ( strlen(com_token) != 0 )
          {
            v11 = v14;
            v14 = (CUtlSymbolTable *)((char *)v14 + 316);
            do
            {
              V_FixSlashes(pname: com_token, separator: 92);
              _V_strlower(start: com_token);
              CUtlSymbolTable::AddString(this: v14, result: &sym, pString: com_token);
              if ( CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::Find(
                     this: (CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl*)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short> > *)&v11[5].m_Lookup.m_Elements.m_nAllocationCount,
                     search: &sym) == 0xFFFF )
              {
                CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::Insert(
                  this: (CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl*)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short> > *)&v11[5].m_Lookup.m_Elements.m_nAllocationCount,
                  insert: &sym);
                ++warnings;
              }
              v10 = COM_Parse(data: v10);
            }
            while ( strlen(com_token) != 0 );
          }
          v7 = pStart;
        }
        free(pMem: v9);
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
    }
    g_pFileSystem->AddLoggingFunc(
      this: g_pFileSystem,
      a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::TrackDeletionsLoggingFunc);
    _Msg(
      a1: "Tracking deletions (%u files in deletion list in '%s', %u previous warnings loaded from '%s'\n",
      deletions,
      "deletions.bat",
      warnings,
      "undelete.lst");
  }
  else
  {
    _Warning(a1: "Unable to load deletions.bat file %s\n", "deletions.bat");
    this->m_bTrackingDeletions = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A40A0
// Name: void MapReslistGenerator_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapReslistGenerator_Init()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  bool usemaplistfile; // [esp+4h] [ebp-4h]

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-makereslists") != 0 )
  {
    v1 = _CommandLine();
    usemaplistfile = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-usereslistfile") != 0;
    CMapReslistGenerator::EnableReslistGeneration(this: &g_MapReslistGenerator, usemaplistfile);
  }
  else
  {
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-rebuildaudio") != 0 )
      g_MapReslistGenerator.m_bAutoQuit = true;
  }
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-trackdeletions") != 0 )
    CMapReslistGenerator::EnableDeletionsTracking(this: &g_MapReslistGenerator);
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-autoquit") != 0 )
    g_MapReslistGenerator.m_bAutoQuit = true;
}

//------------------------------------------------------------------------------
// Address: 0x101A4150
// Name: public: void CMapReslistGenerator::OnLevelLoadStart(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnLevelLoadStart(CMapReslistGenerator *this, const char *levelName)
{
  bool v3; // bl
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  IBaseFileSystem *v6; // eax
  char basename[260]; // [esp+8h] [ebp-208h] BYREF
  char path[260]; // [esp+10Ch] [ebp-104h] BYREF

  this->m_bLogToEngineList = false;
  V_strncpy(pDest: this->m_szLevelName, pSrc: levelName, maxLen: 64);
  if ( this->m_bLoggingEnabled )
  {
    CUtlSymbolTable::RemoveAll(this: &this->m_AlreadyWrittenFileNames);
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &this->m_MapLog);
    V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\%s.bsp", levelName);
    if ( this->m_bLoggingEnabled
      && path[0] != 0
      && path[0] != 42
      && g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: path, a3: basename, a4: 260) != nullptr )
    {
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: basename);
    }
    v3 = true;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ModInfo");
    else
      v5 = nullptr;
    if ( g_pFileSystem != nullptr )
      v6 = &g_pFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: "gameinfo.txt",
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      v3 = KeyValues::GetInt(this: v5, keyName: "nodegraph", defaultValue: 1) != 0;
    }
    KeyValues::deleteThis(this: v5);
    if ( v3 )
    {
      V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\graphs\\%s.ain", levelName);
      CMapReslistGenerator::OnResourcePrecached(this, relativePathFileName: path);
    }
  }
  else
  {
    V_FileBase(in: levelName, out: basename, maxlen: 260);
    _V_strlower(start: basename);
    V_snprintf(pDest: this->m_szPrefix, maxLen: 64, pFormat: "%s:  ", basename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A42D0
// Name: public: void CMapReslistGenerator::OnModelPrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnModelPrecached(CMapReslistGenerator *this, char *relativePathFileName)
{
  int v3; // eax
  char *v4; // eax
  char file[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_bLoggingEnabled )
  {
    strstr(str1: (unsigned __int8 *)relativePathFileName, str2: ".vmt");
    if ( v3 != 0 )
    {
      if ( V_strnicmp(s1: relativePathFileName, s2: "materials", n: 9) != 0 )
        V_snprintf(pDest: file, maxLen: 260, pFormat: "materials\\%s", relativePathFileName);
      else
        V_strncpy(pDest: file, pSrc: relativePathFileName, maxLen: 260);
      CMapReslistGenerator::OnResourcePrecached(this, relativePathFileName: file);
      strstr(str1: (unsigned __int8 *)file, str2: ".vmt");
      if ( v4 != nullptr )
      {
        V_strncpy(pDest: v4, pSrc: ".vtf", maxLen: 5);
        CMapReslistGenerator::OnResourcePrecached(this, relativePathFileName: file);
      }
    }
    else
    {
      CMapReslistGenerator::OnResourcePrecached(this, relativePathFileName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A43B0
// Name: public: void CMapReslistGenerator::OnSoundPrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnSoundPrecached(CMapReslistGenerator *this, const char *relativePathFileName)
{
  const char *v2; // esi
  char fullPathFileName[260]; // [esp+8h] [ebp-208h] BYREF
  char file[260]; // [esp+10Ch] [ebp-104h] BYREF

  v2 = relativePathFileName;
  if ( isalnum(c: *relativePathFileName) == 0 )
    v2 = relativePathFileName + 1;
  if ( V_strnicmp(s1: v2, s2: "sound", n: 5) != 0 )
    V_snprintf(pDest: file, maxLen: 260, pFormat: "sound\\%s", v2);
  else
    V_strncpy(pDest: file, pSrc: v2, maxLen: 260);
  if ( this->m_bLoggingEnabled
    && file[0] != 0
    && file[0] != 42
    && g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: file, a3: fullPathFileName, a4: 260) != nullptr )
  {
    CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101A0910
// Name: void MapReslistGenerator_Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapReslistGenerator_Usage()
{
  _Msg(a1: "-makereslists usage:\n");
  _Msg(
    a1: "  [ -makereslists <optionalscriptfile> ] -- script file to control more complex makereslists operations (multiple passes, etc.)\n");
  _Msg(a1: "  [ -usereslistfile filename ] -- get map list from specified file, default is to build for maps/*.bsp\n");
  _Msg(a1: "  [ -startmap mapname ] -- restart generation at specified map (after crash, implies resume)\n");
  _Msg(a1: "  [ -condebug ] -- prepend console.log entries with mapname or engine if not in a map\n");
  _Msg(a1: "  [ +map mapname ] -- generate reslists for specified map and exit after that map\n");
  _Msg(a1: "  [ -rebuildaudio ] -- force rebuild of _other_rebuild.cache (metacache) file at exit\n");
  _Msg(a1: "  [ -forever ] -- when you get to the end of the maplist, start over from the top\n");
  _Msg(a1: "  [ -stringtables ] -- force rebuild of the .bsp's stringtable dictionary\n");
  _Msg(a1: "  [ -reslistdir ] -- default is 'reslists', use this to override\n");
  _Msg(a1: "  [ -startstage nnn ] -- when running from script file, this starts at specified stage\n");
  _Msg(a1: "  [ -collate ] -- skip everything, just merge the reslist from temp folders to the final folder again\n");
}

//------------------------------------------------------------------------------
// Address: 0x101A0970
// Name: class CMapReslistGenerator __near & MapReslistGenerator(void)
// Source: json
//------------------------------------------------------------------------------
CMapReslistGenerator *__cdecl MapReslistGenerator()
{
  return &g_MapReslistGenerator;
}

//------------------------------------------------------------------------------
// Address: 0x101A0980
// Name: ReslistLogLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ReslistLogLessFunc(CUtlString *pLHS, CUtlString *pRHS)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: pRHS);
  v3 = CUtlString::operator char const *(this: pLHS);
  if ( v3 == nullptr )
    return false;
  if ( v2 != nullptr )
    return _V_stricmp(s1: v3, s2: v2) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101A09C0
// Name: public: void CMapReslistGenerator::StartReslistGeneration(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::StartReslistGeneration(CMapReslistGenerator *this)
{
  int m_iPauseFramesBetweenMaps; // eax

  m_iPauseFramesBetweenMaps = this->m_iPauseFramesBetweenMaps;
  this->m_iCurrentMap = 0;
  this->m_iFrameCountdownToRunningNextMap = m_iPauseFramesBetweenMaps;
  this->m_flNextMapRunTime = _Plat_FloatTime((CStatTime *)this) + (double)this->m_iPauseTimeBetweenMaps;
}

//------------------------------------------------------------------------------
// Address: 0x101A09E0
// Name: private: void CMapReslistGenerator::SetPrefix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::SetPrefix(CMapReslistGenerator *this, const char *mapname)
{
  V_snprintf(pDest: this->m_szPrefix, maxLen: 64, pFormat: "%s:  ", mapname);
}

//------------------------------------------------------------------------------
// Address: 0x101A0A10
// Name: public: char const __near * CMapReslistGenerator::LogPrefix(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapReslistGenerator::LogPrefix(CMapReslistGenerator *this)
{
  char *result; // eax

  result = "engine:  ";
  if ( !this->m_bLogToEngineList )
    return this->m_szPrefix;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0A20
// Name: public: void CMapReslistGenerator::OnPlayerSpawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnPlayerSpawn(CMapReslistGenerator *this)
{
  if ( this->m_bLoggingEnabled )
  {
    this->m_iFrameCountdownToRunningNextMap = this->m_iPauseFramesBetweenMaps;
    this->m_flNextMapRunTime = _Plat_FloatTime((CStatTime *)this) + (double)this->m_iPauseTimeBetweenMaps;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A0A40
// Name: public: char const __near * CMapReslistGenerator::GetResListDirectory(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapReslistGenerator::GetResListDirectory(CMapReslistGenerator *this)
{
  return CUtlString::operator char const *(this: &this->m_sResListDir);
}

//------------------------------------------------------------------------------
// Address: 0x101A0A50
// Name: public: bool CMapReslistGenerator::IsCreatingForXbox(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapReslistGenerator::IsCreatingForXbox(CMapReslistGenerator *this)
{
  return this->m_bLoggingEnabled && this->m_bCreatingForXbox;
}

//------------------------------------------------------------------------------
// Address: 0x101A2970
// Name: private: void CMapReslistGenerator::WriteMapLog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::WriteMapLog(CMapReslistGenerator *this)
{
  CMapReslistGenerator *v1; // edi
  bool v2; // zf
  const char *v3; // eax
  void *v4; // ebx
  int Inorder; // esi
  const char *v6; // eax
  IBaseFileSystem_vtbl *v7; // edx
  IBaseFileSystem_vtbl *v8; // edi
  int v9; // eax
  char *m_szLevelName; // [esp-8h] [ebp-118h]
  char path[260]; // [esp+4h] [ebp-10Ch] BYREF
  const char *pLine; // [esp+108h] [ebp-8h]
  CMapReslistGenerator *v13; // [esp+10Ch] [ebp-4h]

  v1 = this;
  v2 = this->m_szLevelName[0] == 0;
  v13 = this;
  if ( !v2 )
  {
    m_szLevelName = this->m_szLevelName;
    v3 = CUtlString::operator char const *(this: &this->m_sResListDir);
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s\\%s.lst", v3, m_szLevelName);
    v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: path, a3: "wt", a4: "DEFAULT_WRITE_PATH");
    if ( v4 != nullptr )
    {
      Inorder = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::FirstInorder(this: &v1->m_MapLog);
      if ( Inorder != -1 )
      {
        while ( 1 )
        {
          v6 = CUtlString::operator char const *(this: &v1->m_MapLog.m_Elements.m_pMemory[Inorder].m_Data);
          v7 = g_pFileSystem->IBaseFileSystem::__vftable;
          pLine = v6;
          v7->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: v4);
          v8 = g_pFileSystem->IBaseFileSystem::__vftable;
          v9 = _V_strlen(str: pLine);
          v8->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pLine, a3: v9, a4: v4);
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: v4);
          Inorder = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::NextInorder(
                      this: &v13->m_MapLog,
                      i: Inorder);
          if ( Inorder == -1 )
            break;
          v1 = v13;
        }
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2AB0
// Name: private: void CMapReslistGenerator::SpewTrackedDeletionsLog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::SpewTrackedDeletionsLog(CMapReslistGenerator *this)
{
  CMapReslistGenerator *v1; // edi
  void *v2; // ebx
  int Inorder; // esi
  IBaseFileSystem_vtbl *v4; // edi
  int v5; // eax
  char *str; // [esp+10h] [ebp-4h]

  v1 = this;
  if ( this->m_bTrackingDeletions )
  {
    v2 = g_pFileSystem->Open(
           this: &g_pFileSystem->IBaseFileSystem,
           a2: "undelete.lst",
           a3: "wt",
           a4: "DEFAULT_WRITE_PATH");
    if ( v2 != nullptr )
    {
      Inorder = (unsigned __int16)CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::FirstInorder(this: &v1->m_DeletionListWarnings);
      if ( Inorder != 0xFFFF )
      {
        while ( 1 )
        {
          str = (char *)CUtlSymbolTable::String(
                          this: &v1->m_DeletionListWarningsSymbols,
                          id: v1->m_DeletionListWarnings.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data);
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: v2);
          v4 = g_pFileSystem->IBaseFileSystem::__vftable;
          v5 = _V_strlen(str);
          v4->Write(this: &g_pFileSystem->IBaseFileSystem, a2: str, a3: v5, a4: v2);
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: v2);
          Inorder = (unsigned __int16)CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::NextInorder(
                                        this: &this->m_DeletionListWarnings,
                                        i: Inorder);
          if ( Inorder == 0xFFFF )
            break;
          v1 = this;
        }
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2D30
// Name: bool BuildGeneralMapList(class CUtlVector<struct maplist_map_t,class CUtlMemory<struct maplist_map_t,int>> __near *,bool,char const __near *,char __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildGeneralMapList(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *aMaps,
        const char *bUseMapListFile,
        const char *pMapFile,
        char *pSystemMsg,
        int *iCurrentMap)
{
  int v5; // eax
  int v6; // ecx
  const char *First; // edi
  IBaseFileSystem_vtbl *v8; // esi
  char *v9; // eax
  _BYTE *v10; // eax
  const char *v11; // esi
  void *v12; // ebx
  int v13; // eax
  int v14; // esi
  char *v15; // edi
  const char *i; // esi
  int m_Size; // ebx
  int v18; // esi
  int v20; // eax
  int v21; // edi
  int v22; // edi
  int v23; // esi
  int v24; // [esp+0h] [ebp-154h]
  char szMap[260]; // [esp+Ch] [ebp-148h] BYREF
  maplist_map_t newMap; // [esp+110h] [ebp-44h] BYREF
  const char *startmap; // [esp+150h] [ebp-4h] BYREF

  if ( (_BYTE)bUseMapListFile != 0 )
  {
    v11 = pMapFile;
    if ( pMapFile == nullptr )
    {
      _Error(a1: "Unable to find %s maplist filename\n", pSystemMsg);
      return 0;
    }
    v12 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pMapFile, a3: "rb", a4: 0);
    if ( v12 == nullptr )
    {
      _Error(a1: "Unable to load %s maplist file: %s\n", pSystemMsg, v11);
      return 0;
    }
    v13 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v12);
    v14 = v13;
    if ( v13 > 0 )
    {
      v15 = (char *)MemAlloc_Alloc(nSize: v13 + 1);
      if ( v15 != nullptr
        && v14 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v15, a3: v14, a4: v12) )
      {
        v15[v14] = 0;
        for ( i = COM_Parse(data: v15); strlen(com_token) != 0; i = COM_Parse(data: i) )
        {
          V_strncpy(pDest: szMap, pSrc: com_token, maxLen: 260);
          if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: szMap) != 0 )
          {
            for ( ; COM_TokenWaiting(buffer: i) != 0; i = COM_Parse(data: i) )
              ;
            V_strncpy(pDest: newMap.name, pSrc: szMap, maxLen: 64);
            CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
              this: aMaps,
              elem: aMaps->m_Size,
              src: (const VMatrix *)&newMap);
          }
        }
      }
      free(pMem: v15);
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v12);
  }
  else
  {
    bUseMapListFile = nullptr;
    v5 = _CommandLine(a1: v24);
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: "+map",
           a3: &bUseMapListFile) != 0
      && bUseMapListFile != nullptr )
    {
      if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: bUseMapListFile) != 0 )
      {
        V_strncpy(pDest: newMap.name, pSrc: bUseMapListFile, maxLen: 64);
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
          this: aMaps,
          elem: aMaps->m_Size,
          src: (const VMatrix *)&newMap);
      }
      v6 = _CommandLine(a1: v24);
      (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 16))(a1: v6, a2: "+map");
    }
    else
    {
      First = Sys_FindFirst(path: "maps/*.bsp", basename: nullptr, namelength: 0);
      while ( First != nullptr )
      {
        v8 = g_pFileSystem->IBaseFileSystem::__vftable;
        v9 = va(format: "maps/%s", First);
        if ( v8->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v9, a3: "MOD") )
        {
          V_strncpy(pDest: szMap, pSrc: First, maxLen: 260);
          strchr(string: (unsigned __int8 *)szMap, chr: 0x2Eu);
          if ( v10 != nullptr )
            *v10 = 0;
          First = Sys_FindNext(basename: nullptr, namelength: 0);
          if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: szMap) != 0 )
          {
            V_strncpy(pDest: newMap.name, pSrc: szMap, maxLen: 64);
            CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
              this: aMaps,
              elem: aMaps->m_Size,
              src: (const VMatrix *)&newMap);
          }
        }
        else
        {
          First = Sys_FindNext(basename: nullptr, namelength: 0);
        }
      }
      Sys_FindClose();
    }
  }
  m_Size = aMaps->m_Size;
  v18 = 0;
  if ( m_Size != 0 )
  {
    _Msg(a1: "%s: Creating for:\n", pSystemMsg);
    *iCurrentMap = 0;
    startmap = nullptr;
    v20 = _CommandLine(a1: v24);
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v20 + 12))(
           a1: v20,
           a2: "-startmap",
           a3: &startmap) != 0
      && startmap != nullptr
      && m_Size > 0 )
    {
      v21 = 0;
      do
      {
        if ( _V_stricmp(s1: (const char *)&aMaps->m_Memory.m_pMemory[v21], s2: startmap) == 0 )
          *iCurrentMap = v18;
        ++v18;
        ++v21;
      }
      while ( v18 < m_Size );
    }
    v22 = 0;
    if ( m_Size > 0 )
    {
      v23 = 0;
      do
      {
        if ( v22 >= *iCurrentMap )
          _Msg(a1: "+  %s\n", &aMaps->m_Memory.m_pMemory[v23]);
        else
          _Msg(a1: "-  %s\n", &aMaps->m_Memory.m_pMemory[v23]);
        ++v22;
        ++v23;
      }
      while ( v22 < m_Size );
    }
    return 1;
  }
  else
  {
    _Msg(a1: "%s: No maps found\n", pSystemMsg);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3230
// Name: public: void CMapReslistGenerator::BuildMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapReslistGenerator::BuildMapList(CMapReslistGenerator *this@<ecx>, int a2@<esi>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]
  const char *bUseMapListFile; // [esp+4h] [ebp-8h]
  const char *pMapFile; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_bLoggingEnabled )
  {
    MapReslistGenerator_Usage();
    pMapFile = nullptr;
    v3 = _CommandLine(a1: a2);
    (*(void (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v3 + 12))(
      a1: v3,
      a2: "-usereslistfile",
      a3: &pMapFile);
    v4 = _CommandLine(a1: v6);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "+map") != 0 )
    {
      LOBYTE(bUseMapListFile) = 0;
    }
    else
    {
      v5 = _CommandLine(a1: v7);
      LOBYTE(bUseMapListFile) = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(
                                  a1: v5,
                                  a2: "-usereslistfile") != 0;
    }
    if ( BuildGeneralMapList(
           aMaps: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)&this->m_Maps,
           bUseMapListFile,
           pMapFile,
           pSystemMsg: "reslists",
           iCurrentMap: &this->m_iCurrentMap) == 0 )
      this->m_bLoggingEnabled = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3410
// Name: void MapReslistGenerator_BuildMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall MapReslistGenerator_BuildMapList(int a1@<esi>)
{
  CMapReslistGenerator::BuildMapList(this: &g_MapReslistGenerator, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A3420
// Name: public: CMapReslistGenerator::~CMapReslistGenerator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::~CMapReslistGenerator(CMapReslistGenerator *this)
{
  bool v2; // sf

  v2 = this->m_sResListDir.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_sResListDir.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_sResListDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sResListDir.m_Storage.m_Memory.m_pMemory);
      this->m_sResListDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sResListDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::~CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>(this: &this->m_EngineLog);
  CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::~CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>(this: &this->m_MapLog);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_DeletionListWarningsSymbols);
  CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>(this: &this->m_DeletionListWarnings);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_DeletionList);
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_AlreadyWrittenFileNames);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Maps);
}

//------------------------------------------------------------------------------
// Address: 0x101A34B0
// Name: public: CMapReslistGenerator::CMapReslistGenerator(void)
// Source: json
//------------------------------------------------------------------------------
CMapReslistGenerator *__thiscall CMapReslistGenerator::CMapReslistGenerator(CMapReslistGenerator *this)
{
  this->m_bAutoQuit = false;
  this->m_Maps.m_Memory.m_pMemory = nullptr;
  this->m_Maps.m_Memory.m_nAllocationCount = 0;
  this->m_Maps.m_Memory.m_nGrowSize = 0;
  this->m_Maps.m_Size = 0;
  this->m_Maps.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_AlreadyWrittenFileNames,
    growSize: 0,
    initSize: 0,
    caseInsensitive: true);
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_DeletionList, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_DeletionListWarnings.m_LessFunc = (bool (__cdecl *)(const CUtlSymbol *, const CUtlSymbol *))CDefOps<unsigned short>::LessFunc;
  this->m_DeletionListWarnings.m_Elements.m_pMemory = nullptr;
  this->m_DeletionListWarnings.m_Elements.m_nAllocationCount = 0;
  this->m_DeletionListWarnings.m_Elements.m_nGrowSize = 0;
  this->m_DeletionListWarnings.m_pElements = this->m_DeletionListWarnings.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_DeletionListWarnings.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_DeletionListWarnings.m_FirstFree = -1;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_DeletionListWarningsSymbols,
    growSize: 0,
    initSize: 16,
    caseInsensitive: false);
  this->m_MapLog.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))ReslistLogLessFunc;
  this->m_MapLog.m_Elements.m_pMemory = nullptr;
  this->m_MapLog.m_Elements.m_nAllocationCount = 0;
  this->m_MapLog.m_Elements.m_nGrowSize = 0;
  this->m_MapLog.m_Root = -1;
  this->m_MapLog.m_NumElements = 0;
  this->m_MapLog.m_FirstFree = -1;
  this->m_MapLog.m_LastAlloc.index = -1;
  this->m_MapLog.m_pElements = this->m_MapLog.m_Elements.m_pMemory;
  this->m_EngineLog.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))ReslistLogLessFunc;
  this->m_EngineLog.m_Elements.m_pMemory = nullptr;
  this->m_EngineLog.m_Elements.m_nAllocationCount = 0;
  this->m_EngineLog.m_Elements.m_nGrowSize = 0;
  this->m_EngineLog.m_Root = -1;
  this->m_EngineLog.m_FirstFree = -1;
  this->m_EngineLog.m_NumElements = 0;
  this->m_EngineLog.m_LastAlloc.index = -1;
  this->m_EngineLog.m_pElements = this->m_EngineLog.m_Elements.m_pMemory;
  CUtlString::CUtlString(this: &this->m_sResListDir);
  this->m_bUsingMapList = false;
  *(_WORD *)&this->m_bTrackingDeletions = 0;
  this->m_iCurrentMap = 0;
  this->m_flNextMapRunTime = 0.0;
  this->m_iFrameCountdownToRunningNextMap = 0;
  this->m_szPrefix[0] = 0;
  this->m_szLevelName[0] = 0;
  this->m_iPauseTimeBetweenMaps = 2;
  this->m_iPauseFramesBetweenMaps = 300;
  *(_WORD *)&this->m_bRestartOnTransition = 0;
  this->m_bLogToEngineList = true;
  CUtlString::operator=(this: &this->m_sResListDir, src: "reslists");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A3610
// Name: private: void CMapReslistGenerator::BuildEngineLogFromReslist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::BuildEngineLogFromReslist(CMapReslistGenerator *this)
{
  CUtlRBTree<CUtlString,int,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int> > *p_m_EngineLog; // esi
  const char *v3; // eax
  CFmtStrN<256> *v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // edx
  int v8; // edi
  UtlRBTreeNode_t<CUtlString,int> *v9; // ecx
  UtlRBTreeNode_t<CUtlString,int> *m_pMemory; // ecx
  int v11; // edx
  UtlRBTreeNode_t<CUtlString,int> *v12; // edx
  CFmtStrN<256> v13; // [esp+Ch] [ebp-368h] BYREF
  characterset_t breakSet; // [esp+118h] [ebp-25Ch] BYREF
  char szToken[260]; // [esp+218h] [ebp-15Ch] BYREF
  CUtlBuffer buffer; // [esp+31Ch] [ebp-58h] BYREF
  CUtlString search; // [esp+34Ch] [ebp-28h] BYREF
  CUtlString insert; // [esp+35Ch] [ebp-18h] BYREF
  int parent; // [esp+36Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+373h] [ebp-1h] BYREF

  p_m_EngineLog = &this->m_EngineLog;
  CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &this->m_EngineLog);
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 1);
  v3 = CUtlString::operator char const *(this: &this->m_sResListDir);
  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "%s\\%s", v3, "engine.lst");
  if ( g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: v4->m_szBuf,
         a3: "DEFAULT_WRITE_PATH",
         a4: &buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: defaultValue);
    while ( CUtlBuffer::ParseToken(
              this: &buffer,
              pBreaks: &breakSet,
              pTokenBuf: szToken,
              nMaxLen: 260,
              bParseComments: true) > 0 )
    {
      CUtlString::CUtlString(this: &search, pString: szToken);
      v5 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
             this: p_m_EngineLog,
             &search);
      search.m_Storage.m_nActualLength = 0;
      if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( search.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
          search.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        search.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      if ( v5 == -1 )
      {
        CUtlString::CUtlString(this: &insert, pString: szToken);
        parent = -1;
        leftchild = false;
        CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::FindInsertionPosition(
          this: p_m_EngineLog,
          &insert,
          &parent,
          &leftchild);
        v6 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::NewNode(this: p_m_EngineLog);
        v7 = parent;
        v8 = v6;
        v9 = &p_m_EngineLog->m_Elements.m_pMemory[v6];
        v9->m_Parent = parent;
        v9->m_Right = -1;
        v9->m_Left = -1;
        v9->m_Tag = 0;
        if ( v7 == -1 )
        {
          p_m_EngineLog->m_Root = v6;
        }
        else
        {
          m_pMemory = p_m_EngineLog->m_Elements.m_pMemory;
          v11 = v7;
          if ( leftchild )
            m_pMemory[v11].m_Left = v6;
          else
            m_pMemory[v11].m_Right = v6;
        }
        CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::InsertRebalance(
          this: p_m_EngineLog,
          elem: v6);
        v12 = p_m_EngineLog->m_Elements.m_pMemory;
        ++p_m_EngineLog->m_NumElements;
        if ( &v12[v8] != (UtlRBTreeNode_t<CUtlString,int> *)-16 )
          CUtlString::CUtlString(this: &v12[v8].m_Data, string: &insert);
        insert.m_Storage.m_nActualLength = 0;
        if ( insert.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( insert.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.m_Storage.m_Memory.m_pMemory);
            insert.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          insert.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
    }
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101A3810
// Name: private: void CMapReslistGenerator::LogToEngineReslist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::LogToEngineReslist(CMapReslistGenerator *this, const char *pLine)
{
  const char *v4; // eax
  CFmtStrN<256> *v5; // eax
  void *v6; // esi
  IBaseFileSystem_vtbl *v7; // edi
  int v8; // eax
  CFmtStrN<256> v9; // [esp+Ch] [ebp-11Ch] BYREF
  CUtlString search; // [esp+118h] [ebp-10h] BYREF
  int idx; // [esp+130h] [ebp+8h]

  CUtlString::CUtlString(this: &search, pString: pLine);
  idx = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
          this: &this->m_EngineLog,
          &search);
  search.m_Storage.m_nActualLength = 0;
  if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
  if ( idx == -1 )
  {
    CUtlString::CUtlString(this: &search, pString: pLine);
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Insert(
      this: &this->m_EngineLog,
      insert: &search);
    search.m_Storage.m_nActualLength = 0;
    if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
    v4 = CUtlString::operator char const *(this: &this->m_sResListDir);
    v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "%s\\%s", v4, "engine.lst");
    v6 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v5->m_szBuf, a3: "at", a4: "DEFAULT_WRITE_PATH");
    if ( v6 != nullptr )
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: v6);
      v7 = g_pFileSystem->IBaseFileSystem::__vftable;
      v8 = _V_strlen(str: pLine);
      v7->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pLine, a3: v8, a4: v6);
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: v6);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3960
// Name: private: void CMapReslistGenerator::OnResourcePrecachedFullPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnResourcePrecachedFullPath(
        CMapReslistGenerator *this,
        const char *fullPathFileName)
{
  int v3; // eax
  char *v4; // eax
  char *v5; // edi
  char *v6; // edi
  const char *v7; // edi
  int v8; // ebx
  char file[260]; // [esp+8h] [ebp-218h] BYREF
  char fixed[260]; // [esp+10Ch] [ebp-114h] BYREF
  CUtlString search; // [esp+210h] [ebp-10h] BYREF

  V_strncpy(pDest: fixed, pSrc: fullPathFileName, maxLen: 260);
  _V_strlower(start: fixed);
  V_FixSlashes(pname: fixed, separator: 92);
  if ( CUtlSymbolTable::Find(
         this: &this->m_AlreadyWrittenFileNames,
         result: (CUtlSymbol *)&fullPathFileName + 1,
         pString: fixed)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(
      this: &this->m_AlreadyWrittenFileNames,
      result: (CUtlSymbol *)&fullPathFileName + 1,
      pString: fixed);
    strstr(str1: (unsigned __int8 *)fixed, str2: ".mdl");
    if ( v3 != 0 )
    {
      V_strncpy(pDest: file, pSrc: fixed, maxLen: 250);
      strstr(str1: (unsigned __int8 *)file, str2: ".mdl");
      v5 = v4;
      V_strncpy(pDest: v4, pSrc: ".vvd", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
      V_strncpy(pDest: v5, pSrc: ".ani", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
      V_strncpy(pDest: v5, pSrc: ".dx90.vtx", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
      V_strncpy(pDest: v5, pSrc: ".phy", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
      V_strncpy(pDest: v5, pSrc: ".jpg", maxLen: 10);
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: file);
    }
    v6 = V_stristr(pStr: fixed, pSearch: host_parms.basedir);
    if ( v6 != nullptr )
    {
      v7 = &v6[_V_strlen(str: host_parms.basedir) + 1];
      if ( v7 != nullptr )
      {
        if ( this->m_bLogToEngineList )
        {
          CMapReslistGenerator::LogToEngineReslist(this, pLine: v7);
        }
        else
        {
          CUtlString::CUtlString(this: &search, pString: v7);
          v8 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
                 this: &this->m_MapLog,
                 &search);
          CUtlString::~CUtlString(this: &search);
          if ( v8 == -1 )
          {
            CUtlString::CUtlString(this: &search, pString: v7);
            CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Insert(
              this: &this->m_MapLog,
              insert: &search);
            CUtlString::~CUtlString(this: &search);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3B50
// Name: private: static void CMapReslistGenerator::FileSystemLoggingFunc(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapReslistGenerator::FileSystemLoggingFunc(const char *fullPathFileName)
{
  CMapReslistGenerator::OnResourcePrecachedFullPath(this: &g_MapReslistGenerator, fullPathFileName);
}

//------------------------------------------------------------------------------
// Address: 0x101A3B70
// Name: public: void CMapReslistGenerator::TrackDeletions(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::TrackDeletions(CMapReslistGenerator *this, const char *fullPathFileName)
{
  int v3; // eax
  char *v4; // eax
  char *v5; // edi
  char test[260]; // [esp+8h] [ebp-20Ch] BYREF
  char file[260]; // [esp+10Ch] [ebp-108h] BYREF
  CUtlSymbol sym; // [esp+210h] [ebp-4h] BYREF

  V_strncpy(pDest: test, pSrc: fullPathFileName, maxLen: 260);
  V_FixSlashes(pname: test, separator: 92);
  _V_strlower(start: test);
  CUtlSymbolTable::Find(this: &this->m_DeletionList, result: &sym, pString: test);
  if ( sym.m_Id != 0xFFFF )
  {
    CUtlSymbolTable::AddString(
      this: &this->m_DeletionListWarningsSymbols,
      result: (CUtlSymbol *)&fullPathFileName,
      pString: test);
    if ( CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::Find(
           this: &this->m_DeletionListWarnings,
           search: (const CUtlSymbol *)&fullPathFileName) == 0xFFFF )
    {
      _Msg(a1: "--> Referenced file marked for deletion \"%s\"\n", test);
      CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::Insert(
        this: &this->m_DeletionListWarnings,
        insert: (const CUtlSymbol *)&fullPathFileName);
    }
  }
  strstr(str1: (unsigned __int8 *)test, str2: ".mdl");
  if ( v3 != 0 )
  {
    V_strncpy(pDest: file, pSrc: test, maxLen: 250);
    strstr(str1: (unsigned __int8 *)file, str2: ".mdl");
    v5 = v4;
    V_strncpy(pDest: v4, pSrc: ".vvd", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".ani", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".dx80.vtx", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".dx90.vtx", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".sw.vtx", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".phy", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
    V_strncpy(pDest: v5, pSrc: ".jpg", maxLen: 10);
    CMapReslistGenerator::TrackDeletions(this, fullPathFileName: file);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3D50
// Name: private: static void CMapReslistGenerator::TrackDeletionsLoggingFunc(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapReslistGenerator::TrackDeletionsLoggingFunc(const char *fullPathFileName)
{
  CMapReslistGenerator::TrackDeletions(this: &g_MapReslistGenerator, fullPathFileName);
}

//------------------------------------------------------------------------------
// Address: 0x101A3DC0
// Name: public: void CMapReslistGenerator::EnableReslistGeneration(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapReslistGenerator::EnableReslistGeneration(
        CMapReslistGenerator *this@<ecx>,
        int a2@<ebx>,
        bool usemaplistfile)
{
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  const char *v8; // eax
  CFmtStrN<256> *v9; // eax
  int v10; // [esp+0h] [ebp-118h]
  CFmtStrN<256> v11; // [esp+8h] [ebp-110h] BYREF
  const char *pszDir; // [esp+114h] [ebp-4h] BYREF

  if ( _V_stricmp(s1: "cstrike", s2: host_parms.mod) == 0 || _V_stricmp(s1: "cstrike15", s2: host_parms.mod) == 0 )
  {
    this->m_iPauseTimeBetweenMaps = 6;
    this->m_iPauseFramesBetweenMaps = 900;
  }
  this->m_bUsingMapList = usemaplistfile;
  this->m_bLoggingEnabled = true;
  pszDir = nullptr;
  v4 = _CommandLine(a1: a2);
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v4 + 12))(
         a1: v4,
         a2: "-reslistdir",
         a3: &pszDir) != 0
    && pszDir != nullptr )
  {
    V_strncpy(pDest: &v11.m_szBuf[3], pSrc: pszDir, maxLen: 260);
    V_StripTrailingSlash(ppath: &v11.m_szBuf[3]);
    _V_strlower(start: &v11.m_szBuf[3]);
    V_FixSlashes(pname: &v11.m_szBuf[3], separator: 92);
    if ( _V_strlen(str: &v11.m_szBuf[3]) > 0 )
      CUtlString::operator=(this: &this->m_sResListDir, src: &v11.m_szBuf[3]);
  }
  v5 = _CommandLine(a1: v10);
  this->m_bCreatingForXbox = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 40))(a1: v5) != 0;
  v6 = CUtlString::operator char const *(this: &this->m_sResListDir);
  g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: v6, a3: "DEFAULT_WRITE_PATH");
  v7 = _CommandLine(a1: "-xboxreslist");
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-startmap") != 0 )
  {
    CMapReslistGenerator::BuildEngineLogFromReslist(this);
  }
  else
  {
    v8 = CUtlString::operator char const *(this: &this->m_sResListDir);
    v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "%s\\%s", v8, "engine.lst");
    g_pFileSystem->RemoveFile(this: g_pFileSystem, a2: v9->m_szBuf, a3: "DEFAULT_WRITE_PATH");
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &this->m_EngineLog);
  }
  g_pFileSystem->AddLoggingFunc(
    this: g_pFileSystem,
    a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::FileSystemLoggingFunc);
}

//------------------------------------------------------------------------------
// Address: 0x101A3F60
// Name: private: void CMapReslistGenerator::DoQuit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::DoQuit(CMapReslistGenerator *this)
{
  ECommandTarget_t TraceType; // eax

  TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
  Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
  g_pFileSystem->RemoveLoggingFunc(
    this: g_pFileSystem,
    a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::FileSystemLoggingFunc);
  this->m_bLogToEngineList = true;
}

//------------------------------------------------------------------------------
// Address: 0x101A3FA0
// Name: public: void CMapReslistGenerator::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapReslistGenerator::RunFrame(CMapReslistGenerator *this@<ecx>, int a2@<edi>)
{
  ECommandTarget_t v3; // eax
  int m_iCurrentMap; // eax
  bool v5; // zf
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  const char *v11; // [esp-Ch] [ebp-18h]
  int v12; // [esp-4h] [ebp-10h]
  int v13; // [esp+0h] [ebp-Ch]
  float m_flNextMapRunTime; // [esp+8h] [ebp-4h]

  if ( this->m_bLoggingEnabled )
  {
    if ( --this->m_iFrameCountdownToRunningNextMap <= 0 && this->m_flNextMapRunTime != 0.0 )
    {
      m_flNextMapRunTime = this->m_flNextMapRunTime;
      if ( _Plat_FloatTime((CStatTime *)this) > (double)m_flNextMapRunTime )
      {
        CMapReslistGenerator::WriteMapLog(this);
        m_iCurrentMap = this->m_iCurrentMap;
        if ( m_iCurrentMap < 0 || m_iCurrentMap >= this->m_Maps.m_Size )
        {
          v10 = _CommandLine(a1: v13);
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-forever") != 0 )
          {
            CMapReslistGenerator::StartReslistGeneration(this);
            this->m_bRestartOnTransition = true;
          }
          else
          {
            CMapReslistGenerator::DoQuit(this);
          }
        }
        else
        {
          v5 = !this->m_bRestartOnTransition;
          *(_QWORD *)&this->m_flNextMapRunTime = 0;
          if ( v5 )
          {
            v11 = va(format: "map %s\n", this->m_Maps.m_Memory.m_pMemory[m_iCurrentMap].name);
            TraceType = CTraceFilter::GetTraceType(this: v6);
            Cbuf_AddText(eTarget: TraceType, pText: v11, nTickDelay: 0);
            CMapReslistGenerator::SetPrefix(this, mapname: this->m_Maps.m_Memory.m_pMemory[this->m_iCurrentMap].name);
            if ( CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int>>::IsValidIndex(
                   this: (vgui::ImageList *)&this->m_Maps,
                   imageIndex: ++this->m_iCurrentMap) )
            {
              this->m_bRestartOnTransition = true;
            }
          }
          else
          {
            v8 = _CommandLine(a1: a2);
            (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 16))(a1: v8, a2: "-startmap");
            v9 = _CommandLine(a1: v12);
            (*(void (__thiscall **)(int, const char *, maplist_map_t *))(*(_DWORD *)v9 + 20))(
              a1: v9,
              a2: "-startmap",
              a3: &this->m_Maps.m_Memory.m_pMemory[this->m_iCurrentMap]);
            HostState_Restart();
          }
        }
      }
    }
  }
  else if ( this->m_bAutoQuit )
  {
    this->m_bAutoQuit = false;
    v3 = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
    Cbuf_AddText(eTarget: v3, pText: "quit\n", nTickDelay: 0);
    g_pFileSystem->RemoveLoggingFunc(
      this: g_pFileSystem,
      a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::FileSystemLoggingFunc);
    this->m_bLogToEngineList = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4120
// Name: public: void CMapReslistGenerator::OnResourcePrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnResourcePrecached(CMapReslistGenerator *this, const char *relativePathFileName)
{
  char fullPath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_bLoggingEnabled
    && *relativePathFileName != 0
    && *relativePathFileName != 42
    && g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: relativePathFileName, a3: fullPath, a4: 260) != nullptr )
  {
    CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: fullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4180
// Name: public: void CMapReslistGenerator::EnableDeletionsTracking(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::EnableDeletionsTracking(CMapReslistGenerator *this)
{
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // edx
  void *v3; // edi
  int v4; // esi
  char *v5; // eax
  const char *i; // esi
  char *v7; // edi
  int v8; // esi
  char *v9; // ebx
  const char *v10; // edi
  CUtlSymbolTable *v11; // esi
  char *v12; // [esp-4h] [ebp-12Ch]
  char filename[264]; // [esp+Ch] [ebp-11Ch] BYREF
  CUtlSymbolTable *v14; // [esp+114h] [ebp-14h]
  unsigned int deletions; // [esp+118h] [ebp-10h]
  unsigned int warnings; // [esp+11Ch] [ebp-Ch]
  char *pStart; // [esp+120h] [ebp-8h]
  CUtlSymbol sym; // [esp+124h] [ebp-4h] BYREF

  this->m_bTrackingDeletions = true;
  Open = g_pFileSystem->Open;
  v14 = (CUtlSymbolTable *)this;
  deletions = 0;
  warnings = 0;
  v3 = Open(this: &g_pFileSystem->IBaseFileSystem, a2: "deletions.bat", a3: "rb", a4: nullptr);
  if ( v3 != nullptr )
  {
    v4 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    if ( v4 > 0 )
    {
      v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
      pStart = v5;
      if ( v5 != nullptr )
      {
        if ( v4 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v5, a3: v4, a4: v3) )
        {
          v12 = pStart;
          pStart[v4] = 0;
          for ( i = COM_Parse(data: v12); strlen(com_token) != 0; i = COM_Parse(data: i) )
          {
            if ( _V_stricmp(s1: com_token, s2: "del") != 0 )
            {
              V_snprintf(pDest: filename, maxLen: 260, pFormat: "%s/%s", com_gamedir, com_token);
              for ( ; COM_TokenWaiting(buffer: i) != 0; i = COM_Parse(data: i) )
                ;
              V_FixSlashes(pname: filename, separator: 92);
              _V_strlower(start: filename);
              CUtlSymbolTable::AddString(this: &this->m_DeletionList, result: &sym, pString: filename);
              ++deletions;
            }
          }
        }
        v5 = pStart;
      }
      free(pMem: v5);
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    v7 = (char *)g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "undelete.lst", a3: "rb", a4: 0);
    pStart = v7;
    if ( v7 != nullptr )
    {
      v8 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
      if ( v8 > 0 )
      {
        v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
        if ( v9 != nullptr && v8 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v9, a3: v8, a4: v7) )
        {
          v9[v8] = 0;
          v10 = COM_Parse(data: v9);
          if ( strlen(com_token) != 0 )
          {
            v11 = v14;
            v14 = (CUtlSymbolTable *)((char *)v14 + 316);
            do
            {
              V_FixSlashes(pname: com_token, separator: 92);
              _V_strlower(start: com_token);
              CUtlSymbolTable::AddString(this: v14, result: &sym, pString: com_token);
              if ( CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::Find(
                     this: (CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl*)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short> > *)&v11[5].m_Lookup.m_Elements.m_nAllocationCount,
                     search: &sym) == 0xFFFF )
              {
                CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl *)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>>::Insert(
                  this: (CUtlRBTree<CUtlSymbol,unsigned short,bool (__cdecl*)(CUtlSymbol const &,CUtlSymbol const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short> > *)&v11[5].m_Lookup.m_Elements.m_nAllocationCount,
                  insert: &sym);
                ++warnings;
              }
              v10 = COM_Parse(data: v10);
            }
            while ( strlen(com_token) != 0 );
          }
          v7 = pStart;
        }
        free(pMem: v9);
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
    }
    g_pFileSystem->AddLoggingFunc(
      this: g_pFileSystem,
      a2: (void (__cdecl *)(const char *, const char *))CMapReslistGenerator::TrackDeletionsLoggingFunc);
    _Msg(
      a1: "Tracking deletions (%u files in deletion list in '%s', %u previous warnings loaded from '%s'\n",
      deletions,
      "deletions.bat",
      warnings,
      "undelete.lst");
  }
  else
  {
    _Warning(a1: "Unable to load deletions.bat file %s\n", "deletions.bat");
    this->m_bTrackingDeletions = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A44B0
// Name: void MapReslistGenerator_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall MapReslistGenerator_Init(int a1@<ebx>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // [esp+0h] [ebp-8h]
  int v7; // [esp+0h] [ebp-8h]
  int v8; // [esp+0h] [ebp-8h]
  int v9; // [esp+0h] [ebp-8h]
  bool usemaplistfile; // [esp+4h] [ebp-4h]

  v1 = _CommandLine(a1: v6);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-makereslists") != 0 )
  {
    v2 = _CommandLine(a1: v7);
    usemaplistfile = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-usereslistfile") != 0;
    CMapReslistGenerator::EnableReslistGeneration(this: &g_MapReslistGenerator, a2: a1, usemaplistfile);
  }
  else
  {
    v3 = _CommandLine(a1: v7);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-rebuildaudio") != 0 )
      g_MapReslistGenerator.m_bAutoQuit = true;
  }
  v4 = _CommandLine(a1: v8);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-trackdeletions") != 0 )
    CMapReslistGenerator::EnableDeletionsTracking(this: &g_MapReslistGenerator);
  v5 = _CommandLine(a1: v9);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-autoquit") != 0 )
    g_MapReslistGenerator.m_bAutoQuit = true;
}

//------------------------------------------------------------------------------
// Address: 0x101A4560
// Name: public: void CMapReslistGenerator::OnLevelLoadStart(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnLevelLoadStart(CMapReslistGenerator *this, const char *levelName)
{
  bool v3; // bl
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  IBaseFileSystem *v6; // eax
  char basename[260]; // [esp+8h] [ebp-208h] BYREF
  char path[260]; // [esp+10Ch] [ebp-104h] BYREF

  this->m_bLogToEngineList = false;
  V_strncpy(pDest: this->m_szLevelName, pSrc: levelName, maxLen: 64);
  if ( this->m_bLoggingEnabled )
  {
    CUtlSymbolTable::RemoveAll(this: &this->m_AlreadyWrittenFileNames);
    CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &this->m_MapLog);
    V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\%s.bsp", levelName);
    if ( this->m_bLoggingEnabled
      && path[0] != 0
      && path[0] != 42
      && g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: path, a3: basename, a4: 260) != nullptr )
    {
      CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName: basename);
    }
    v3 = true;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ModInfo");
    else
      v5 = nullptr;
    if ( g_pFileSystem != nullptr )
      v6 = &g_pFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: "gameinfo.txt",
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      v3 = KeyValues::GetInt(this: v5, keyName: "nodegraph", defaultValue: 1) != 0;
    }
    KeyValues::deleteThis(this: v5);
    if ( v3 )
    {
      V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\graphs\\%s.ain", levelName);
      CMapReslistGenerator::OnResourcePrecached(this, relativePathFileName: path);
    }
  }
  else
  {
    V_FileBase(in: levelName, out: basename, maxlen: 260);
    _V_strlower(start: basename);
    V_snprintf(pDest: this->m_szPrefix, maxLen: 64, pFormat: "%s:  ", basename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A46E0
// Name: public: void CMapReslistGenerator::OnModelPrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnModelPrecached(CMapReslistGenerator *this, char *relativePathFileName)
{
  int v3; // eax
  char *v4; // eax
  char file[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_bLoggingEnabled )
  {
    strstr(str1: (unsigned __int8 *)relativePathFileName, str2: ".vmt");
    if ( v3 != 0 )
    {
      if ( V_strnicmp(s1: relativePathFileName, s2: "materials", n: 9) != 0 )
        V_snprintf(pDest: file, maxLen: 260, pFormat: "materials\\%s", relativePathFileName);
      else
        V_strncpy(pDest: file, pSrc: relativePathFileName, maxLen: 260);
      CMapReslistGenerator::OnResourcePrecached(this, relativePathFileName: file);
      strstr(str1: (unsigned __int8 *)file, str2: ".vmt");
      if ( v4 != nullptr )
      {
        V_strncpy(pDest: v4, pSrc: ".vtf", maxLen: 5);
        CMapReslistGenerator::OnResourcePrecached(this, relativePathFileName: file);
      }
    }
    else
    {
      CMapReslistGenerator::OnResourcePrecached(this, relativePathFileName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A47C0
// Name: public: void CMapReslistGenerator::OnSoundPrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapReslistGenerator::OnSoundPrecached(CMapReslistGenerator *this, const char *relativePathFileName)
{
  const char *v2; // esi
  char fullPathFileName[260]; // [esp+8h] [ebp-208h] BYREF
  char file[260]; // [esp+10Ch] [ebp-104h] BYREF

  v2 = relativePathFileName;
  if ( isalnum(c: *relativePathFileName) == 0 )
    v2 = relativePathFileName + 1;
  if ( V_strnicmp(s1: v2, s2: "sound", n: 5) != 0 )
    V_snprintf(pDest: file, maxLen: 260, pFormat: "sound\\%s", v2);
  else
    V_strncpy(pDest: file, pSrc: v2, maxLen: 260);
  if ( this->m_bLoggingEnabled
    && file[0] != 0
    && file[0] != 42
    && g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: file, a3: fullPathFileName, a4: 260) != nullptr )
  {
    CMapReslistGenerator::OnResourcePrecachedFullPath(this, fullPathFileName);
  }
}

} // namespace engine_xlsp
