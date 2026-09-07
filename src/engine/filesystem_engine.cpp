// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/filesystem_engine.cpp
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10178020
// Name: path
// Source: json
//------------------------------------------------------------------------------
void __cdecl path()
{
  if ( g_pFileSystem != nullptr )
    g_pFileSystem->PrintSearchPaths(this: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10178040
// Name: fs_printopenfiles
// Source: json
//------------------------------------------------------------------------------
void __cdecl fs_printopenfiles()
{
  if ( g_pFileSystem != nullptr )
    g_pFileSystem->PrintOpenedFiles(this: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10178060
// Name: fs_warning_level
// Source: json
//------------------------------------------------------------------------------
void __cdecl fs_warning_level(const CCommand *args)
{
  FileWarningLevel_t v1; // esi

  if ( args->m_nArgc == 2 )
  {
    v1 = atoi(nptr: args->m_ppArgv[1]);
    switch ( v1 )
    {
      case FILESYSTEM_WARNING_QUIET:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_QUIET\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTUNCLOSED:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTUNCLOSED\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTUSAGE:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTUSAGE\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTALLACCESSES:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTALLACCESSES\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTALLACCESSES_READ:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTALLACCESSES_READ\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTALLACCESSES_READWRITE:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTALLACCESSES_READWRITE\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC\n");
LABEL_11:
        g_pFileSystem->SetWarningLevel(this: g_pFileSystem, a2: v1);
        break;
      default:
        _Warning(a1: "fs_warning_level = UNKNOWN!!!!!!!\n");
        break;
    }
  }
  else
  {
    _Warning(a1: "\"fs_warning_level n\" where n is one of:\n");
    _Warning(a1: "\t0:\tFILESYSTEM_WARNING_QUIET\n");
    _Warning(a1: "\t1:\tFILESYSTEM_WARNING_REPORTUNCLOSED\n");
    _Warning(a1: "\t2:\tFILESYSTEM_WARNING_REPORTUSAGE\n");
    _Warning(a1: "\t3:\tFILESYSTEM_WARNING_REPORTALLACCESSES\n");
    _Warning(a1: "\t4:\tFILESYSTEM_WARNING_REPORTALLACCESSES_READ\n");
    _Warning(a1: "\t5:\tFILESYSTEM_WARNING_REPORTALLACCESSES_READWRITE\n");
    _Warning(a1: "\t6:\tFILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178150
// Name: class CSysModule __near * FileSystem_LoadModule(char const __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl FileSystem_LoadModule(const char *path)
{
  if ( g_pFileSystem != nullptr )
    return g_pFileSystem->LoadModule(this: g_pFileSystem, a2: path, a3: nullptr, a4: true);
  else
    return Sys_LoadModule(pModuleName: path);
}

//------------------------------------------------------------------------------
// Address: 0x10178180
// Name: void FileSystem_UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_UnloadModule(struct CSysModule *pModule)
{
  Sys_UnloadModule(pModule);
}

//------------------------------------------------------------------------------
// Address: 0x10178190
// Name: fs_syncdvddevcache
// Source: json
//------------------------------------------------------------------------------
void __cdecl fs_syncdvddevcache()
{
  if ( g_pFileSystem != nullptr )
    g_pFileSystem->SyncDvdDevCache(this: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x101781B0
// Name: void CopyStagedAddons(class IFileSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyStagedAddons(int a1@<esi>, IFileSystem *pFileSystem, const char *pModPath)
{
  CUtlString *m_Size; // ebx
  unsigned int SteamAppID; // eax
  const char *i; // eax
  unsigned int v6; // eax
  CUtlString *v7; // edi
  CUtlString *m_pMemory; // ecx
  CUtlString *v9; // edi
  CUtlString *v10; // edi
  const char *v11; // eax
  const char *v12; // eax
  IFileSystem_vtbl *v13; // ebx
  const char *v14; // eax
  const char *v15; // [esp-8h] [ebp-34Ch]
  char szAddonsWildcard[260]; // [esp+4h] [ebp-340h] BYREF
  char szAddonInstallPath[260]; // [esp+108h] [ebp-23Ch] BYREF
  char szDestPath[260]; // [esp+20Ch] [ebp-138h] BYREF
  CUtlString v19; // [esp+310h] [ebp-34h] BYREF
  unsigned int nReadLength; // [esp+320h] [ebp-24h] BYREF
  int findHandleDir; // [esp+324h] [ebp-20h] BYREF
  HKEY__ *hKey; // [esp+328h] [ebp-1Ch] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecAddonVPKs; // [esp+32Ch] [ebp-18h] BYREF
  CUtlString *string; // [esp+340h] [ebp-4h]

  if ( RegOpenKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: "Software\\Valve\\Steam",
         ulOptions: 0,
         samDesired: 0x20019u,
         phkResult: &hKey) == 0 )
  {
    nReadLength = 260;
    if ( RegQueryValueExA(
           hKey,
           lpValueName: "SourceModInstallPath",
           lpReserved: nullptr,
           lpType: nullptr,
           lpData: (LPBYTE)szAddonInstallPath,
           lpcbData: &nReadLength) == 0 )
    {
      m_Size = nullptr;
      memset(&vecAddonVPKs, 0, sizeof(vecAddonVPKs));
      SteamAppID = GetSteamAppID();
      V_snprintf(
        pDest: szAddonsWildcard,
        maxLen: 260,
        pFormat: "%s%c%s%c%i%c%s",
        szAddonInstallPath,
        92,
        "addons",
        92,
        SteamAppID,
        92,
        "*.vpk");
      for ( i = (const char *)((int (__thiscall *)(IFileSystem *, char *, int *, int))pFileSystem->FindFirst)(
                                a1: pFileSystem,
                                a2: szAddonsWildcard,
                                a3: &findHandleDir,
                                a4: a1); i != nullptr; i = pFileSystem->FindNext(this: pFileSystem, a2: findHandleDir) )
      {
        v15 = i;
        v6 = GetSteamAppID();
        V_snprintf(
          pDest: szDestPath,
          maxLen: 260,
          pFormat: "%s%c%s%c%i%c%s",
          szAddonInstallPath,
          92,
          "addons",
          92,
          v6,
          92,
          v15);
        string = CUtlString::CUtlString(this: &v19, pString: szDestPath);
        v7 = m_Size;
        if ( (int)&m_Size->m_Storage.m_Memory.m_pMemory + 1 > vecAddonVPKs.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CPortalRect,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&vecAddonVPKs,
            num: (int)&m_Size->m_Storage.m_Memory.m_pMemory - vecAddonVPKs.m_Memory.m_nAllocationCount + 1);
          m_Size = (CUtlString *)vecAddonVPKs.m_Size;
        }
        m_pMemory = vecAddonVPKs.m_Memory.m_pMemory;
        m_Size = (CUtlString *)((char *)m_Size + 1);
        vecAddonVPKs.m_Size = (int)m_Size;
        vecAddonVPKs.m_pElements = vecAddonVPKs.m_Memory.m_pMemory;
        if ( (char *)m_Size - (char *)v7 - 1 > 0 )
        {
          _V_memmove(
            dest: &vecAddonVPKs.m_Memory.m_pMemory[(int)v7 + 1],
            src: &vecAddonVPKs.m_Memory.m_pMemory[(_DWORD)v7],
            count: 16 * ((char *)m_Size - (char *)v7 - 1));
          m_pMemory = vecAddonVPKs.m_Memory.m_pMemory;
        }
        v9 = &m_pMemory[(_DWORD)v7];
        if ( v9 != nullptr )
          CUtlString::CUtlString(this: v9, string);
        v19.m_Storage.m_nActualLength = 0;
        if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v19.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
            v19.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v19.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
      pFileSystem->FindClose(this: pFileSystem, a2: findHandleDir);
      if ( (int)m_Size > 0 )
      {
        v10 = vecAddonVPKs.m_Memory.m_pMemory;
        for ( string = m_Size; string != nullptr; string = (CUtlString *)((char *)string - 1) )
        {
          v11 = CUtlString::operator char const *(this: v10);
          v12 = V_UnqualifiedFileName(in: v11);
          V_snprintf(pDest: szDestPath, maxLen: 260, pFormat: "%s%s%c%s", pModPath, "addons", 92, v12);
          pFileSystem->RemoveFile(this: pFileSystem, a2: szDestPath, a3: nullptr);
          v13 = pFileSystem->IAppSystem::__vftable;
          v14 = CUtlString::operator char const *(this: v10);
          v13->RenameFile(this: pFileSystem, a2: v14, a3: szDestPath, a4: nullptr);
          ++v10;
        }
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecAddonVPKs);
      if ( vecAddonVPKs.m_Memory.m_nGrowSize >= 0 && vecAddonVPKs.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecAddonVPKs.m_Memory.m_pMemory);
    }
    RegCloseKey(hKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178410
// Name: void ReconcileAddonListFile(class IFileSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReconcileAddonListFile(IFileSystem *pFileSystem, const char *pModPath)
{
  int m_Size; // edi
  KeyValues *v3; // eax
  char *i; // eax
  int v5; // esi
  CUtlString *v6; // esi
  char *j; // edi
  int v8; // esi
  CUtlString *m_pMemory; // ebx
  char v10; // al
  CUtlString *v11; // eax
  KeyValues *v12; // edi
  CUtlString *v13; // esi
  int k; // ebx
  char *v15; // eax
  char *v16; // eax
  int v17; // ebx
  CUtlString *v18; // esi
  char *v19; // eax
  char *v20; // eax
  char *Name; // eax
  CUtlString *v22; // eax
  int v23; // ebx
  int v24; // esi
  CUtlString *v25; // edi
  char *v26; // eax
  int v27; // esi
  CUtlString *v28; // ebx
  CUtlString *v29; // edi
  unsigned int v30; // ebx
  int v31; // eax
  int v32; // esi
  KeyValues **v33; // edi
  int v34; // eax
  KeyValues **v35; // eax
  KeyValues *v36; // ebx
  KeyValues **v37; // edi
  int m; // esi
  int v39; // [esp-8h] [ebp-59Ch]
  int v40; // [esp-4h] [ebp-598h]
  char addonsInfoFile[260]; // [esp+Ch] [ebp-588h] BYREF
  char szVPKized[260]; // [esp+110h] [ebp-484h] BYREF
  char pDest[260]; // [esp+214h] [ebp-380h] BYREF
  char addonsWildcard[260]; // [esp+318h] [ebp-27Ch] BYREF
  char addoninfoFilename[260]; // [esp+41Ch] [ebp-178h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecAddonDirs; // [esp+520h] [ebp-74h] BYREF
  CUtlString v47; // [esp+534h] [ebp-60h] BYREF
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > vecDoomedSubkeys; // [esp+544h] [ebp-50h] BYREF
  int findHandleConfig; // [esp+558h] [ebp-3Ch] BYREF
  CUtlString v50; // [esp+55Ch] [ebp-38h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecAddonVPKs; // [esp+56Ch] [ebp-28h] BYREF
  KeyValues *pAddonList; // [esp+580h] [ebp-14h]
  int findHandleDir; // [esp+584h] [ebp-10h] BYREF
  unsigned int v54; // [esp+588h] [ebp-Ch]
  KeyValues *pIter; // [esp+58Ch] [ebp-8h]
  bool v56; // [esp+593h] [ebp-1h]

  m_Size = 0;
  v54 = 0;
  V_snprintf(pDest, maxLen: 260, pFormat: "%s%s", pModPath, "addonlist.txt");
  pAddonList = ReadKeyValuesFile(pFilename: pDest);
  if ( pAddonList == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      pAddonList = KeyValues::KeyValues(this: v3, setName: "AddonList");
    else
      pAddonList = nullptr;
  }
  memset(&vecAddonVPKs, 0, sizeof(vecAddonVPKs));
  V_snprintf(pDest: addonsWildcard, maxLen: 260, pFormat: "%s%s%c%s", pModPath, "addons", 92, "*.vpk");
  for ( i = (char *)pFileSystem->FindFirst(this: pFileSystem, a2: addonsWildcard, a3: &findHandleDir);
        i != nullptr;
        i = (char *)pFileSystem->FindNext(this: pFileSystem, a2: findHandleDir) )
  {
    pIter = (KeyValues *)CUtlString::CUtlString(this: &v50, pString: i);
    v5 = m_Size;
    if ( m_Size + 1 > vecAddonVPKs.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CPortalRect,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&vecAddonVPKs,
        num: m_Size - vecAddonVPKs.m_Memory.m_nAllocationCount + 1);
      m_Size = vecAddonVPKs.m_Size;
    }
    vecAddonVPKs.m_Size = ++m_Size;
    vecAddonVPKs.m_pElements = vecAddonVPKs.m_Memory.m_pMemory;
    if ( m_Size - v5 - 1 > 0 )
      _V_memmove(
        dest: &vecAddonVPKs.m_Memory.m_pMemory[v5 + 1],
        src: &vecAddonVPKs.m_Memory.m_pMemory[v5],
        count: 16 * (m_Size - v5 - 1));
    v6 = &vecAddonVPKs.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
      CUtlString::CUtlString(this: v6, string: (const CUtlString *)pIter);
    v50.m_Storage.m_nActualLength = 0;
    if ( v50.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v50.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50.m_Storage.m_Memory.m_pMemory);
        v50.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v50.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
  }
  pFileSystem->FindClose(this: pFileSystem, a2: findHandleDir);
  memset(&vecAddonDirs, 0, sizeof(vecAddonDirs));
  V_snprintf(pDest: addonsWildcard, maxLen: 260, pFormat: "%s%s%c%s", pModPath, "addons", 92, "*.*");
  for ( j = (char *)pFileSystem->FindFirst(this: pFileSystem, a2: addonsWildcard, a3: &findHandleDir);
        j != nullptr;
        j = (char *)((int (__thiscall *)(IFileSystem *))pFileSystem->FindNext)(a1: pFileSystem) )
  {
    if ( ((unsigned __int8 (__thiscall *)(IFileSystem *, int, int))pFileSystem->FindIsDirectory)(
           a1: pFileSystem,
           a2: findHandleDir,
           a3: v39) != 0
      && *j != 46 )
    {
      V_snprintf(pDest: szVPKized, maxLen: 260, pFormat: "%s.vpk", j);
      v8 = 0;
      pIter = (KeyValues *)CUtlString::CUtlString(this: &v50, pString: szVPKized);
      if ( vecAddonVPKs.m_Size <= 0 )
        goto LABEL_24;
      m_pMemory = vecAddonVPKs.m_Memory.m_pMemory;
      while ( !CUtlString::operator==(this: m_pMemory, src: (const CUtlString *)pIter) )
      {
        ++v8;
        ++m_pMemory;
        if ( v8 >= vecAddonVPKs.m_Size )
          goto LABEL_24;
      }
      if ( v8 < 0 || v8 >= vecAddonVPKs.m_Size )
LABEL_24:
        v10 = 0;
      else
        v10 = 1;
      v56 = v10 == 0;
      v50.m_Storage.m_nActualLength = 0;
      if ( v50.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v50.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50.m_Storage.m_Memory.m_pMemory);
          v50.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v50.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      if ( v56 )
      {
        V_snprintf(
          pDest: addonsInfoFile,
          maxLen: 260,
          pFormat: "%s%s%c%s%c%s",
          pModPath,
          "addons",
          92,
          j,
          92,
          "addoninfo.txt");
        if ( ((int (__thiscall *)(IFileSystem *, char *, int *, int))pFileSystem->FindFirst)(
               a1: pFileSystem,
               a2: addonsInfoFile,
               a3: &findHandleConfig,
               a4: v40) != 0 )
        {
          v11 = CUtlString::CUtlString(this: &v47, pString: j);
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
            this: &vecAddonDirs,
            elem: vecAddonDirs.m_Size,
            src: v11);
          v47.m_Storage.m_nActualLength = 0;
          if ( v47.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v47.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v47.m_Storage.m_Memory.m_pMemory);
              v47.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v47.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
        v40 = findHandleConfig;
        ((void (__thiscall *)(IFileSystem *))pFileSystem->FindClose)(a1: pFileSystem);
      }
    }
    v39 = findHandleDir;
  }
  pFileSystem->FindClose(this: pFileSystem, a2: findHandleDir);
  v12 = pAddonList;
  if ( vecAddonDirs.m_Size > 0 )
  {
    v13 = vecAddonDirs.m_Memory.m_pMemory;
    for ( k = vecAddonDirs.m_Size; k != 0; --k )
    {
      v15 = (char *)CUtlString::operator char const *(this: v13);
      if ( KeyValues::FindKey(this: v12, keyName: v15, bCreate: false) == nullptr )
      {
        v16 = (char *)CUtlString::operator char const *(this: v13);
        KeyValues::SetInt(this: v12, keyName: v16, value: 1);
      }
      ++v13;
    }
  }
  v17 = vecAddonVPKs.m_Size;
  if ( vecAddonVPKs.m_Size > 0 )
  {
    v18 = vecAddonVPKs.m_Memory.m_pMemory;
    do
    {
      v19 = (char *)CUtlString::operator char const *(this: v18);
      if ( KeyValues::FindKey(this: v12, keyName: v19, bCreate: false) == nullptr )
      {
        v20 = (char *)CUtlString::operator char const *(this: v18);
        KeyValues::SetInt(this: v12, keyName: v20, value: 1);
      }
      ++v18;
      --v17;
    }
    while ( v17 != 0 );
  }
  pIter = KeyValues::GetFirstSubKey(this: v12);
  memset(&vecDoomedSubkeys, 0, sizeof(vecDoomedSubkeys));
  for ( ; pIter != nullptr; pIter = KeyValues::GetNextKey(this: pIter) )
  {
    v54 |= 1u;
    Name = (char *)KeyValues::GetName(this: pIter);
    v22 = CUtlString::CUtlString(this: &v50, pString: Name);
    v23 = vecAddonDirs.m_Size;
    v24 = 0;
    findHandleConfig = (int)v22;
    if ( vecAddonDirs.m_Size <= 0 )
      goto LABEL_58;
    v25 = vecAddonDirs.m_Memory.m_pMemory;
    while ( !CUtlString::operator==(this: v25, src: (const CUtlString *)findHandleConfig) )
    {
      ++v24;
      ++v25;
      if ( v24 >= v23 )
        goto LABEL_58;
    }
    if ( v24 < 0 || v24 >= v23 )
    {
LABEL_58:
      v54 |= 2u;
      v26 = (char *)KeyValues::GetName(this: pIter);
      v27 = 0;
      v28 = CUtlString::CUtlString(this: &v47, pString: v26);
      if ( vecAddonVPKs.m_Size <= 0 )
        goto LABEL_65;
      v29 = vecAddonVPKs.m_Memory.m_pMemory;
      while ( !CUtlString::operator==(this: v29, src: v28) )
      {
        ++v27;
        ++v29;
        if ( v27 >= vecAddonVPKs.m_Size )
        {
          v56 = true;
          goto LABEL_67;
        }
      }
      if ( v27 < 0 || v27 >= vecAddonVPKs.m_Size )
      {
LABEL_65:
        v56 = true;
        goto LABEL_67;
      }
    }
    v56 = false;
LABEL_67:
    v30 = v54;
    if ( (v54 & 2) != 0 )
    {
      v30 = v54 & 0xFFFFFFFD;
      v54 &= ~2u;
      v47.m_Storage.m_nActualLength = 0;
      if ( v47.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v47.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v47.m_Storage.m_Memory.m_pMemory);
          v47.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v47.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
    if ( (v30 & 1) != 0 )
    {
      v54 = v30 & 0xFFFFFFFE;
      v50.m_Storage.m_nActualLength = 0;
      if ( v50.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v50.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50.m_Storage.m_Memory.m_pMemory);
          v50.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v50.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
    if ( v56 )
    {
      v31 = vecDoomedSubkeys.m_Size;
      v32 = vecDoomedSubkeys.m_Size;
      if ( vecDoomedSubkeys.m_Size + 1 > vecDoomedSubkeys.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&vecDoomedSubkeys,
          num: vecDoomedSubkeys.m_Size - vecDoomedSubkeys.m_Memory.m_nAllocationCount + 1);
        v31 = vecDoomedSubkeys.m_Size;
      }
      v33 = vecDoomedSubkeys.m_Memory.m_pMemory;
      vecDoomedSubkeys.m_Size = v31 + 1;
      v34 = v31 - v32;
      vecDoomedSubkeys.m_pElements = vecDoomedSubkeys.m_Memory.m_pMemory;
      if ( v34 > 0 )
        _V_memmove(
          dest: &vecDoomedSubkeys.m_Memory.m_pMemory[v32 + 1],
          src: &vecDoomedSubkeys.m_Memory.m_pMemory[v32],
          count: 4 * v34);
      v35 = &v33[v32];
      if ( v35 != nullptr )
        *v35 = pIter;
    }
  }
  v36 = pAddonList;
  v37 = vecDoomedSubkeys.m_Memory.m_pMemory;
  for ( m = 0; m < vecDoomedSubkeys.m_Size; ++m )
  {
    KeyValues::RemoveSubKey(this: v36, subKey: v37[m]);
    KeyValues::deleteThis(this: v37[m]);
  }
  V_snprintf(pDest: addoninfoFilename, maxLen: 260, pFormat: "%s%s", pModPath, "addonlist.txt");
  if ( KeyValues::GetFirstSubKey(this: v36) != nullptr )
  {
    KeyValues::SaveToFile(
      this: v36,
      filesystem: &pFileSystem->IBaseFileSystem,
      resourceName: addoninfoFilename,
      pathID: nullptr);
  }
  else if ( pFileSystem->FileExists(this: &pFileSystem->IBaseFileSystem, a2: addoninfoFilename, a3: nullptr) )
  {
    pFileSystem->RemoveFile(this: pFileSystem, a2: addoninfoFilename, a3: nullptr);
  }
  KeyValues::deleteThis(this: v36);
  if ( vecDoomedSubkeys.m_Memory.m_nGrowSize >= 0 && v37 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v37);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecAddonDirs);
  if ( vecAddonDirs.m_Memory.m_nGrowSize >= 0 && vecAddonDirs.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecAddonDirs.m_Memory.m_pMemory);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecAddonVPKs);
  if ( vecAddonVPKs.m_Memory.m_nGrowSize >= 0 && vecAddonVPKs.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecAddonVPKs.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10178A80
// Name: void FileSystem_UpdateAddonSearchPaths(class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_UpdateAddonSearchPaths(IFileSystem *pFileSystem)
{
  int j; // ebx
  void (__thiscall *GetVPKFileNames)(IFileSystem *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *); // edx
  int v4; // ebx
  const char *v5; // eax
  IFileSystem_vtbl *v6; // edi
  const char *v7; // eax
  KeyValues *KeyValuesFile; // eax
  KeyValues *k; // ebx
  const char *Name; // edi
  CUtlString *m_pMemory; // eax
  int m; // esi
  char **v13; // eax
  char gameSearchPath[2600]; // [esp+Ch] [ebp-E60h] BYREF
  char pDest[260]; // [esp+A34h] [ebp-438h] BYREF
  char addOnPath[260]; // [esp+B38h] [ebp-334h] BYREF
  char addonSearchString[260]; // [esp+C3Ch] [ebp-230h] BYREF
  char modPath[260]; // [esp+D40h] [ebp-12Ch] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > loadedVPKs; // [esp+E44h] [ebp-28h] BYREF
  CUtlStringList gameSearchPathList; // [esp+E58h] [ebp-14h] BYREF
  int i; // [esp+E74h] [ebp+8h]
  KeyValues *ia; // [esp+E74h] [ebp+8h]

  pFileSystem->GetSearchPath(this: pFileSystem, a2: "MOD", a3: false, a4: modPath, a5: 260);
  memset(&gameSearchPathList, 0, sizeof(gameSearchPathList));
  V_snprintf(pDest: addonSearchString, maxLen: 260, pFormat: "%s%s", modPath, "addons");
  pFileSystem->GetSearchPath(this: pFileSystem, a2: "GAME", a3: false, a4: gameSearchPath, a5: 2600);
  V_SplitString(pString: gameSearchPath, pSeparator: ";", outStrings: &gameSearchPathList);
  for ( j = 0; j < gameSearchPathList.m_Size; ++j )
  {
    if ( V_stristr(pStr: gameSearchPathList.m_Memory.m_pMemory[j], pSearch: addonSearchString) != nullptr )
      pFileSystem->RemoveSearchPath(this: pFileSystem, a2: gameSearchPathList.m_Memory.m_pMemory[j], a3: "GAME");
  }
  GetVPKFileNames = pFileSystem->GetVPKFileNames;
  memset(&loadedVPKs, 0, sizeof(loadedVPKs));
  GetVPKFileNames(this: pFileSystem, a2: &loadedVPKs);
  i = 0;
  if ( loadedVPKs.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = CUtlString::operator char const *(this: &loadedVPKs.m_Memory.m_pMemory[v4]);
      if ( V_stristr(pStr: v5, pSearch: addonSearchString) != nullptr )
      {
        v6 = pFileSystem->IAppSystem::__vftable;
        v7 = CUtlString::operator char const *(this: &loadedVPKs.m_Memory.m_pMemory[v4]);
        v6->RemoveVPKFile(this: pFileSystem, a2: v7);
      }
      ++v4;
      ++i;
    }
    while ( i < loadedVPKs.m_Size );
  }
  CopyStagedAddons(a1: (int)pFileSystem, pFileSystem, pModPath: modPath);
  ReconcileAddonListFile(pFileSystem, pModPath: modPath);
  V_snprintf(pDest, maxLen: 260, pFormat: "%s%s", modPath, "addonlist.txt");
  KeyValuesFile = ReadKeyValuesFile(pFilename: pDest);
  ia = KeyValuesFile;
  if ( KeyValuesFile != nullptr )
  {
    for ( k = KeyValues::GetFirstValue(this: KeyValuesFile); k != nullptr; k = KeyValues::GetNextValue(this: k) )
    {
      Name = KeyValues::GetName(this: k);
      if ( KeyValues::GetInt(this: k, keyName: nullptr, defaultValue: 0) != 0 )
      {
        V_snprintf(pDest: addOnPath, maxLen: 260, pFormat: "%s%s%c%s", modPath, "addons", 92, Name);
        if ( V_stristr(pStr: Name, pSearch: ".vpk") != nullptr )
          pFileSystem->AddVPKFile(this: pFileSystem, a2: addOnPath, a3: PATH_ADD_TO_TAIL);
        else
          pFileSystem->AddSearchPath(this: pFileSystem, a2: addOnPath, a3: "GAME", a4: PATH_ADD_TO_TAIL);
      }
    }
    KeyValues::deleteThis(this: ia);
  }
  modelloader->Studio_ReloadModels(this: modelloader, a2: RELOAD_EVERYTHING);
  materials->UncacheAllMaterials(this: materials);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&loadedVPKs);
  m_pMemory = loadedVPKs.m_Memory.m_pMemory;
  if ( loadedVPKs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( loadedVPKs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadedVPKs.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      loadedVPKs.m_Memory.m_pMemory = nullptr;
    }
    loadedVPKs.m_Memory.m_nAllocationCount = 0;
  }
  loadedVPKs.m_pElements = m_pMemory;
  if ( loadedVPKs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      loadedVPKs.m_Memory.m_pMemory = nullptr;
    }
    loadedVPKs.m_Memory.m_nAllocationCount = 0;
  }
  for ( m = 0; m < gameSearchPathList.m_Size; ++m )
    free(pMem: gameSearchPathList.m_Memory.m_pMemory[m]);
  v13 = gameSearchPathList.m_Memory.m_pMemory;
  gameSearchPathList.m_Size = 0;
  if ( gameSearchPathList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( gameSearchPathList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: gameSearchPathList.m_Memory.m_pMemory);
      v13 = nullptr;
      gameSearchPathList.m_Memory.m_pMemory = nullptr;
    }
    gameSearchPathList.m_Memory.m_nAllocationCount = 0;
  }
  gameSearchPathList.m_pElements = v13;
  gameSearchPathList.m_Size = 0;
  if ( gameSearchPathList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v13 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
      v13 = nullptr;
      gameSearchPathList.m_Memory.m_pMemory = nullptr;
    }
    gameSearchPathList.m_Memory.m_nAllocationCount = 0;
  }
  gameSearchPathList.m_pElements = v13;
  if ( gameSearchPathList.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x10178DD0
// Name: update_addon_paths
// Source: json
//------------------------------------------------------------------------------
void __cdecl update_addon_paths()
{
  if ( g_pFileSystem != nullptr )
    FileSystem_UpdateAddonSearchPaths(pFileSystem: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10178DF0
// Name: unload_all_addons
// Source: json
//------------------------------------------------------------------------------
void __cdecl unload_all_addons()
{
  int v0; // ebx
  int v1; // edi
  const char *v2; // eax
  IFileSystem_vtbl *v3; // esi
  const char *v4; // eax
  CUtlString *m_pMemory; // eax
  char addonSearchString[260]; // [esp+4h] [ebp-21Ch] BYREF
  char modPath[260]; // [esp+108h] [ebp-118h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > loadedVPKs; // [esp+20Ch] [ebp-14h] BYREF

  if ( g_pFileSystem != nullptr )
  {
    memset(&loadedVPKs, 0, sizeof(loadedVPKs));
    g_pFileSystem->GetSearchPath(this: g_pFileSystem, a2: "MOD", a3: false, a4: modPath, a5: 260);
    V_snprintf(pDest: addonSearchString, maxLen: 260, pFormat: "%s%s", modPath, "addons");
    g_pFileSystem->GetVPKFileNames(this: g_pFileSystem, a2: &loadedVPKs);
    v0 = 0;
    if ( loadedVPKs.m_Size > 0 )
    {
      v1 = 0;
      do
      {
        v2 = CUtlString::operator char const *(this: &loadedVPKs.m_Memory.m_pMemory[v1]);
        if ( V_stristr(pStr: v2, pSearch: addonSearchString) != nullptr )
        {
          v3 = g_pFileSystem->IAppSystem::__vftable;
          v4 = CUtlString::operator char const *(this: &loadedVPKs.m_Memory.m_pMemory[v1]);
          v3->RemoveVPKFile(this: g_pFileSystem, a2: v4);
        }
        ++v0;
        ++v1;
      }
      while ( v0 < loadedVPKs.m_Size );
    }
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&loadedVPKs);
    m_pMemory = loadedVPKs.m_Memory.m_pMemory;
    if ( loadedVPKs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( loadedVPKs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadedVPKs.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        loadedVPKs.m_Memory.m_pMemory = nullptr;
      }
      loadedVPKs.m_Memory.m_nAllocationCount = 0;
    }
    loadedVPKs.m_pElements = m_pMemory;
    if ( loadedVPKs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10178370
// Name: path
// Source: json
//------------------------------------------------------------------------------
void __cdecl path()
{
  if ( g_pFileSystem != nullptr )
    g_pFileSystem->PrintSearchPaths(this: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10178390
// Name: fs_printopenfiles
// Source: json
//------------------------------------------------------------------------------
void __cdecl fs_printopenfiles()
{
  if ( g_pFileSystem != nullptr )
    g_pFileSystem->PrintOpenedFiles(this: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x101783B0
// Name: fs_warning_level
// Source: json
//------------------------------------------------------------------------------
void __cdecl fs_warning_level(const CCommand *args)
{
  FileWarningLevel_t v1; // esi

  if ( args->m_nArgc == 2 )
  {
    v1 = atoi(nptr: args->m_ppArgv[1]);
    switch ( v1 )
    {
      case FILESYSTEM_WARNING_QUIET:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_QUIET\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTUNCLOSED:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTUNCLOSED\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTUSAGE:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTUSAGE\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTALLACCESSES:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTALLACCESSES\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTALLACCESSES_READ:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTALLACCESSES_READ\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTALLACCESSES_READWRITE:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTALLACCESSES_READWRITE\n");
        goto LABEL_11;
      case FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC:
        _Warning(a1: "fs_warning_level = FILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC\n");
LABEL_11:
        g_pFileSystem->SetWarningLevel(this: g_pFileSystem, a2: v1);
        break;
      default:
        _Warning(a1: "fs_warning_level = UNKNOWN!!!!!!!\n");
        break;
    }
  }
  else
  {
    _Warning(a1: "\"fs_warning_level n\" where n is one of:\n");
    _Warning(a1: "\t0:\tFILESYSTEM_WARNING_QUIET\n");
    _Warning(a1: "\t1:\tFILESYSTEM_WARNING_REPORTUNCLOSED\n");
    _Warning(a1: "\t2:\tFILESYSTEM_WARNING_REPORTUSAGE\n");
    _Warning(a1: "\t3:\tFILESYSTEM_WARNING_REPORTALLACCESSES\n");
    _Warning(a1: "\t4:\tFILESYSTEM_WARNING_REPORTALLACCESSES_READ\n");
    _Warning(a1: "\t5:\tFILESYSTEM_WARNING_REPORTALLACCESSES_READWRITE\n");
    _Warning(a1: "\t6:\tFILESYSTEM_WARNING_REPORTALLACCESSES_ASYNC\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101784A0
// Name: class CSysModule __near * FileSystem_LoadModule(char const __near *)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__cdecl FileSystem_LoadModule(const char *path)
{
  if ( g_pFileSystem != nullptr )
    return g_pFileSystem->LoadModule(this: g_pFileSystem, a2: path, a3: nullptr, a4: true);
  else
    return Sys_LoadModule(pModuleName: path);
}

//------------------------------------------------------------------------------
// Address: 0x101784D0
// Name: void FileSystem_UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_UnloadModule(struct CSysModule *pModule)
{
  Sys_UnloadModule(pModule);
}

//------------------------------------------------------------------------------
// Address: 0x101784E0
// Name: fs_syncdvddevcache
// Source: json
//------------------------------------------------------------------------------
void __cdecl fs_syncdvddevcache()
{
  if ( g_pFileSystem != nullptr )
    g_pFileSystem->SyncDvdDevCache(this: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10178500
// Name: void CopyStagedAddons(class IFileSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyStagedAddons(int a1@<esi>, IFileSystem *pFileSystem, const char *pModPath)
{
  CUtlString *m_Size; // ebx
  unsigned int SteamAppID; // eax
  const char *i; // eax
  unsigned int v6; // eax
  CUtlString *v7; // edi
  CUtlString *m_pMemory; // ecx
  CUtlString *v9; // edi
  CUtlString *v10; // edi
  const char *v11; // eax
  const char *v12; // eax
  IFileSystem_vtbl *v13; // ebx
  const char *v14; // eax
  const char *v15; // [esp-8h] [ebp-34Ch]
  char szAddonsWildcard[260]; // [esp+4h] [ebp-340h] BYREF
  char szAddonInstallPath[260]; // [esp+108h] [ebp-23Ch] BYREF
  char szDestPath[260]; // [esp+20Ch] [ebp-138h] BYREF
  CUtlString v19; // [esp+310h] [ebp-34h] BYREF
  unsigned int nReadLength; // [esp+320h] [ebp-24h] BYREF
  int findHandleDir; // [esp+324h] [ebp-20h] BYREF
  HKEY__ *hKey; // [esp+328h] [ebp-1Ch] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecAddonVPKs; // [esp+32Ch] [ebp-18h] BYREF
  CUtlString *string; // [esp+340h] [ebp-4h]

  if ( RegOpenKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: "Software\\Valve\\Steam",
         ulOptions: 0,
         samDesired: 0x20019u,
         phkResult: &hKey) == 0 )
  {
    nReadLength = 260;
    if ( RegQueryValueExA(
           hKey,
           lpValueName: "SourceModInstallPath",
           lpReserved: nullptr,
           lpType: nullptr,
           lpData: (LPBYTE)szAddonInstallPath,
           lpcbData: &nReadLength) == 0 )
    {
      m_Size = nullptr;
      memset(&vecAddonVPKs, 0, sizeof(vecAddonVPKs));
      SteamAppID = GetSteamAppID();
      V_snprintf(
        pDest: szAddonsWildcard,
        maxLen: 260,
        pFormat: "%s%c%s%c%i%c%s",
        szAddonInstallPath,
        92,
        "addons",
        92,
        SteamAppID,
        92,
        "*.vpk");
      for ( i = (const char *)((int (__thiscall *)(IFileSystem *, char *, int *, int))pFileSystem->FindFirst)(
                                a1: pFileSystem,
                                a2: szAddonsWildcard,
                                a3: &findHandleDir,
                                a4: a1); i != nullptr; i = pFileSystem->FindNext(this: pFileSystem, a2: findHandleDir) )
      {
        v15 = i;
        v6 = GetSteamAppID();
        V_snprintf(
          pDest: szDestPath,
          maxLen: 260,
          pFormat: "%s%c%s%c%i%c%s",
          szAddonInstallPath,
          92,
          "addons",
          92,
          v6,
          92,
          v15);
        string = CUtlString::CUtlString(this: &v19, pString: szDestPath);
        v7 = m_Size;
        if ( (int)&m_Size->m_Storage.m_Memory.m_pMemory + 1 > vecAddonVPKs.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CPortalRect,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&vecAddonVPKs,
            num: (int)&m_Size->m_Storage.m_Memory.m_pMemory - vecAddonVPKs.m_Memory.m_nAllocationCount + 1);
          m_Size = (CUtlString *)vecAddonVPKs.m_Size;
        }
        m_pMemory = vecAddonVPKs.m_Memory.m_pMemory;
        m_Size = (CUtlString *)((char *)m_Size + 1);
        vecAddonVPKs.m_Size = (int)m_Size;
        vecAddonVPKs.m_pElements = vecAddonVPKs.m_Memory.m_pMemory;
        if ( (char *)m_Size - (char *)v7 - 1 > 0 )
        {
          _V_memmove(
            dest: &vecAddonVPKs.m_Memory.m_pMemory[(int)v7 + 1],
            src: &vecAddonVPKs.m_Memory.m_pMemory[(_DWORD)v7],
            count: 16 * ((char *)m_Size - (char *)v7 - 1));
          m_pMemory = vecAddonVPKs.m_Memory.m_pMemory;
        }
        v9 = &m_pMemory[(_DWORD)v7];
        if ( v9 != nullptr )
          CUtlString::CUtlString(this: v9, string);
        v19.m_Storage.m_nActualLength = 0;
        if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v19.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
            v19.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v19.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
      pFileSystem->FindClose(this: pFileSystem, a2: findHandleDir);
      if ( (int)m_Size > 0 )
      {
        v10 = vecAddonVPKs.m_Memory.m_pMemory;
        for ( string = m_Size; string != nullptr; string = (CUtlString *)((char *)string - 1) )
        {
          v11 = CUtlString::operator char const *(this: v10);
          v12 = V_UnqualifiedFileName(in: v11);
          V_snprintf(pDest: szDestPath, maxLen: 260, pFormat: "%s%s%c%s", pModPath, "addons", 92, v12);
          pFileSystem->RemoveFile(this: pFileSystem, a2: szDestPath, a3: nullptr);
          v13 = pFileSystem->IAppSystem::__vftable;
          v14 = CUtlString::operator char const *(this: v10);
          v13->RenameFile(this: pFileSystem, a2: v14, a3: szDestPath, a4: nullptr);
          ++v10;
        }
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecAddonVPKs);
      if ( vecAddonVPKs.m_Memory.m_nGrowSize >= 0 && vecAddonVPKs.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecAddonVPKs.m_Memory.m_pMemory);
    }
    RegCloseKey(hKey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178760
// Name: void ReconcileAddonListFile(class IFileSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReconcileAddonListFile(IFileSystem *pFileSystem, const char *pModPath)
{
  int m_Size; // edi
  KeyValues *v3; // eax
  const char *i; // eax
  int v5; // esi
  CUtlString *v6; // esi
  const char *j; // edi
  int v8; // esi
  CUtlString *m_pMemory; // ebx
  char v10; // al
  const CUtlString *v11; // eax
  KeyValues *v12; // edi
  CUtlString *v13; // esi
  int k; // ebx
  const char *v15; // eax
  const char *v16; // eax
  int v17; // ebx
  CUtlString *v18; // esi
  const char *v19; // eax
  const char *v20; // eax
  const char *Name; // eax
  CUtlString *v22; // eax
  int v23; // ebx
  int v24; // esi
  CUtlString *v25; // edi
  const char *v26; // eax
  int v27; // esi
  const CUtlString *v28; // ebx
  CUtlString *v29; // edi
  unsigned int v30; // ebx
  int v31; // eax
  int v32; // esi
  KeyValues **v33; // edi
  int v34; // eax
  KeyValues **v35; // eax
  KeyValues *v36; // ebx
  KeyValues **v37; // edi
  int m; // esi
  int v39; // [esp-8h] [ebp-59Ch]
  int v40; // [esp-4h] [ebp-598h]
  char addonsInfoFile[260]; // [esp+Ch] [ebp-588h] BYREF
  char szVPKized[260]; // [esp+110h] [ebp-484h] BYREF
  char pDest[260]; // [esp+214h] [ebp-380h] BYREF
  char addonsWildcard[260]; // [esp+318h] [ebp-27Ch] BYREF
  char addoninfoFilename[260]; // [esp+41Ch] [ebp-178h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecAddonDirs; // [esp+520h] [ebp-74h] BYREF
  CUtlString v47; // [esp+534h] [ebp-60h] BYREF
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > vecDoomedSubkeys; // [esp+544h] [ebp-50h] BYREF
  int findHandleConfig; // [esp+558h] [ebp-3Ch] BYREF
  CUtlString v50; // [esp+55Ch] [ebp-38h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecAddonVPKs; // [esp+56Ch] [ebp-28h] BYREF
  KeyValues *pAddonList; // [esp+580h] [ebp-14h]
  int findHandleDir; // [esp+584h] [ebp-10h] BYREF
  unsigned int v54; // [esp+588h] [ebp-Ch]
  KeyValues *pIter; // [esp+58Ch] [ebp-8h]
  bool v56; // [esp+593h] [ebp-1h]

  m_Size = 0;
  v54 = 0;
  V_snprintf(pDest, maxLen: 260, pFormat: "%s%s", pModPath, "addonlist.txt");
  pAddonList = ReadKeyValuesFile(pFilename: pDest);
  if ( pAddonList == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      pAddonList = KeyValues::KeyValues(this: v3, setName: "AddonList");
    else
      pAddonList = nullptr;
  }
  memset(&vecAddonVPKs, 0, sizeof(vecAddonVPKs));
  V_snprintf(pDest: addonsWildcard, maxLen: 260, pFormat: "%s%s%c%s", pModPath, "addons", 92, "*.vpk");
  for ( i = pFileSystem->FindFirst(this: pFileSystem, a2: addonsWildcard, a3: &findHandleDir);
        i != nullptr;
        i = pFileSystem->FindNext(this: pFileSystem, a2: findHandleDir) )
  {
    pIter = (KeyValues *)CUtlString::CUtlString(this: &v50, pString: i);
    v5 = m_Size;
    if ( m_Size + 1 > vecAddonVPKs.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CPortalRect,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&vecAddonVPKs,
        num: m_Size - vecAddonVPKs.m_Memory.m_nAllocationCount + 1);
      m_Size = vecAddonVPKs.m_Size;
    }
    vecAddonVPKs.m_Size = ++m_Size;
    vecAddonVPKs.m_pElements = vecAddonVPKs.m_Memory.m_pMemory;
    if ( m_Size - v5 - 1 > 0 )
      _V_memmove(
        dest: &vecAddonVPKs.m_Memory.m_pMemory[v5 + 1],
        src: &vecAddonVPKs.m_Memory.m_pMemory[v5],
        count: 16 * (m_Size - v5 - 1));
    v6 = &vecAddonVPKs.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
      CUtlString::CUtlString(this: v6, string: (const CUtlString *)pIter);
    v50.m_Storage.m_nActualLength = 0;
    if ( v50.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v50.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50.m_Storage.m_Memory.m_pMemory);
        v50.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v50.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
  }
  pFileSystem->FindClose(this: pFileSystem, a2: findHandleDir);
  memset(&vecAddonDirs, 0, sizeof(vecAddonDirs));
  V_snprintf(pDest: addonsWildcard, maxLen: 260, pFormat: "%s%s%c%s", pModPath, "addons", 92, "*.*");
  for ( j = pFileSystem->FindFirst(this: pFileSystem, a2: addonsWildcard, a3: &findHandleDir);
        j != nullptr;
        j = (const char *)((int (__thiscall *)(IFileSystem *))pFileSystem->FindNext)(a1: pFileSystem) )
  {
    if ( ((unsigned __int8 (__thiscall *)(IFileSystem *, int, int))pFileSystem->FindIsDirectory)(
           a1: pFileSystem,
           a2: findHandleDir,
           a3: v39) != 0
      && *j != 46 )
    {
      V_snprintf(pDest: szVPKized, maxLen: 260, pFormat: "%s.vpk", j);
      v8 = 0;
      pIter = (KeyValues *)CUtlString::CUtlString(this: &v50, pString: szVPKized);
      if ( vecAddonVPKs.m_Size <= 0 )
        goto LABEL_24;
      m_pMemory = vecAddonVPKs.m_Memory.m_pMemory;
      while ( !CUtlString::operator==(this: m_pMemory, src: (const CUtlString *)pIter) )
      {
        ++v8;
        ++m_pMemory;
        if ( v8 >= vecAddonVPKs.m_Size )
          goto LABEL_24;
      }
      if ( v8 < 0 || v8 >= vecAddonVPKs.m_Size )
LABEL_24:
        v10 = 0;
      else
        v10 = 1;
      v56 = v10 == 0;
      v50.m_Storage.m_nActualLength = 0;
      if ( v50.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v50.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50.m_Storage.m_Memory.m_pMemory);
          v50.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v50.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      if ( v56 )
      {
        V_snprintf(
          pDest: addonsInfoFile,
          maxLen: 260,
          pFormat: "%s%s%c%s%c%s",
          pModPath,
          "addons",
          92,
          j,
          92,
          "addoninfo.txt");
        if ( ((int (__thiscall *)(IFileSystem *, char *, int *, int))pFileSystem->FindFirst)(
               a1: pFileSystem,
               a2: addonsInfoFile,
               a3: &findHandleConfig,
               a4: v40) != 0 )
        {
          v11 = CUtlString::CUtlString(this: &v47, pString: j);
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
            this: &vecAddonDirs,
            elem: vecAddonDirs.m_Size,
            src: v11);
          v47.m_Storage.m_nActualLength = 0;
          if ( v47.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v47.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v47.m_Storage.m_Memory.m_pMemory);
              v47.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            v47.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
        }
        v40 = findHandleConfig;
        ((void (__thiscall *)(IFileSystem *))pFileSystem->FindClose)(a1: pFileSystem);
      }
    }
    v39 = findHandleDir;
  }
  pFileSystem->FindClose(this: pFileSystem, a2: findHandleDir);
  v12 = pAddonList;
  if ( vecAddonDirs.m_Size > 0 )
  {
    v13 = vecAddonDirs.m_Memory.m_pMemory;
    for ( k = vecAddonDirs.m_Size; k != 0; --k )
    {
      v15 = CUtlString::operator char const *(this: v13);
      if ( KeyValues::FindKey(this: v12, keyName: v15, bCreate: false) == nullptr )
      {
        v16 = CUtlString::operator char const *(this: v13);
        KeyValues::SetInt(this: v12, keyName: v16, value: 1);
      }
      ++v13;
    }
  }
  v17 = vecAddonVPKs.m_Size;
  if ( vecAddonVPKs.m_Size > 0 )
  {
    v18 = vecAddonVPKs.m_Memory.m_pMemory;
    do
    {
      v19 = CUtlString::operator char const *(this: v18);
      if ( KeyValues::FindKey(this: v12, keyName: v19, bCreate: false) == nullptr )
      {
        v20 = CUtlString::operator char const *(this: v18);
        KeyValues::SetInt(this: v12, keyName: v20, value: 1);
      }
      ++v18;
      --v17;
    }
    while ( v17 != 0 );
  }
  pIter = KeyValues::GetFirstSubKey(this: v12);
  memset(&vecDoomedSubkeys, 0, sizeof(vecDoomedSubkeys));
  for ( ; pIter != nullptr; pIter = KeyValues::GetNextKey(this: pIter) )
  {
    v54 |= 1u;
    Name = KeyValues::GetName(this: pIter);
    v22 = CUtlString::CUtlString(this: &v50, pString: Name);
    v23 = vecAddonDirs.m_Size;
    v24 = 0;
    findHandleConfig = (int)v22;
    if ( vecAddonDirs.m_Size <= 0 )
      goto LABEL_58;
    v25 = vecAddonDirs.m_Memory.m_pMemory;
    while ( !CUtlString::operator==(this: v25, src: (const CUtlString *)findHandleConfig) )
    {
      ++v24;
      ++v25;
      if ( v24 >= v23 )
        goto LABEL_58;
    }
    if ( v24 < 0 || v24 >= v23 )
    {
LABEL_58:
      v54 |= 2u;
      v26 = KeyValues::GetName(this: pIter);
      v27 = 0;
      v28 = CUtlString::CUtlString(this: &v47, pString: v26);
      if ( vecAddonVPKs.m_Size <= 0 )
        goto LABEL_65;
      v29 = vecAddonVPKs.m_Memory.m_pMemory;
      while ( !CUtlString::operator==(this: v29, src: v28) )
      {
        ++v27;
        ++v29;
        if ( v27 >= vecAddonVPKs.m_Size )
        {
          v56 = true;
          goto LABEL_67;
        }
      }
      if ( v27 < 0 || v27 >= vecAddonVPKs.m_Size )
      {
LABEL_65:
        v56 = true;
        goto LABEL_67;
      }
    }
    v56 = false;
LABEL_67:
    v30 = v54;
    if ( (v54 & 2) != 0 )
    {
      v30 = v54 & 0xFFFFFFFD;
      v54 &= ~2u;
      v47.m_Storage.m_nActualLength = 0;
      if ( v47.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v47.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v47.m_Storage.m_Memory.m_pMemory);
          v47.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v47.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
    if ( (v30 & 1) != 0 )
    {
      v54 = v30 & 0xFFFFFFFE;
      v50.m_Storage.m_nActualLength = 0;
      if ( v50.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v50.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50.m_Storage.m_Memory.m_pMemory);
          v50.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v50.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
    if ( v56 )
    {
      v31 = vecDoomedSubkeys.m_Size;
      v32 = vecDoomedSubkeys.m_Size;
      if ( vecDoomedSubkeys.m_Size + 1 > vecDoomedSubkeys.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&vecDoomedSubkeys,
          num: vecDoomedSubkeys.m_Size - vecDoomedSubkeys.m_Memory.m_nAllocationCount + 1);
        v31 = vecDoomedSubkeys.m_Size;
      }
      v33 = vecDoomedSubkeys.m_Memory.m_pMemory;
      vecDoomedSubkeys.m_Size = v31 + 1;
      v34 = v31 - v32;
      vecDoomedSubkeys.m_pElements = vecDoomedSubkeys.m_Memory.m_pMemory;
      if ( v34 > 0 )
        _V_memmove(
          dest: &vecDoomedSubkeys.m_Memory.m_pMemory[v32 + 1],
          src: &vecDoomedSubkeys.m_Memory.m_pMemory[v32],
          count: 4 * v34);
      v35 = &v33[v32];
      if ( v35 != nullptr )
        *v35 = pIter;
    }
  }
  v36 = pAddonList;
  v37 = vecDoomedSubkeys.m_Memory.m_pMemory;
  for ( m = 0; m < vecDoomedSubkeys.m_Size; ++m )
  {
    KeyValues::RemoveSubKey(this: v36, subKey: v37[m]);
    KeyValues::deleteThis(this: v37[m]);
  }
  V_snprintf(pDest: addoninfoFilename, maxLen: 260, pFormat: "%s%s", pModPath, "addonlist.txt");
  if ( KeyValues::GetFirstSubKey(this: v36) != nullptr )
  {
    KeyValues::SaveToFile(
      this: v36,
      filesystem: &pFileSystem->IBaseFileSystem,
      resourceName: addoninfoFilename,
      pathID: nullptr);
  }
  else if ( pFileSystem->FileExists(this: &pFileSystem->IBaseFileSystem, a2: addoninfoFilename, a3: nullptr) )
  {
    pFileSystem->RemoveFile(this: pFileSystem, a2: addoninfoFilename, a3: nullptr);
  }
  KeyValues::deleteThis(this: v36);
  if ( vecDoomedSubkeys.m_Memory.m_nGrowSize >= 0 && v37 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v37);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecAddonDirs);
  if ( vecAddonDirs.m_Memory.m_nGrowSize >= 0 && vecAddonDirs.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecAddonDirs.m_Memory.m_pMemory);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecAddonVPKs);
  if ( vecAddonVPKs.m_Memory.m_nGrowSize >= 0 && vecAddonVPKs.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecAddonVPKs.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10179120
// Name: update_addon_paths
// Source: json
//------------------------------------------------------------------------------
void __cdecl update_addon_paths()
{
  if ( g_pFileSystem != nullptr )
    FileSystem_UpdateAddonSearchPaths(pFileSystem: g_pFileSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10179140
// Name: unload_all_addons
// Source: json
//------------------------------------------------------------------------------
void __cdecl unload_all_addons()
{
  int v0; // ebx
  int v1; // edi
  const char *v2; // eax
  IFileSystem_vtbl *v3; // esi
  const char *v4; // eax
  CUtlString *m_pMemory; // eax
  char addonSearchString[260]; // [esp+4h] [ebp-21Ch] BYREF
  char modPath[260]; // [esp+108h] [ebp-118h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > loadedVPKs; // [esp+20Ch] [ebp-14h] BYREF

  if ( g_pFileSystem != nullptr )
  {
    memset(&loadedVPKs, 0, sizeof(loadedVPKs));
    g_pFileSystem->GetSearchPath(this: g_pFileSystem, a2: "MOD", a3: false, a4: modPath, a5: 260);
    V_snprintf(pDest: addonSearchString, maxLen: 260, pFormat: "%s%s", modPath, "addons");
    g_pFileSystem->GetVPKFileNames(this: g_pFileSystem, a2: &loadedVPKs);
    v0 = 0;
    if ( loadedVPKs.m_Size > 0 )
    {
      v1 = 0;
      do
      {
        v2 = CUtlString::operator char const *(this: &loadedVPKs.m_Memory.m_pMemory[v1]);
        if ( V_stristr(pStr: v2, pSearch: addonSearchString) != nullptr )
        {
          v3 = g_pFileSystem->IAppSystem::__vftable;
          v4 = CUtlString::operator char const *(this: &loadedVPKs.m_Memory.m_pMemory[v1]);
          v3->RemoveVPKFile(this: g_pFileSystem, a2: v4);
        }
        ++v0;
        ++v1;
      }
      while ( v0 < loadedVPKs.m_Size );
    }
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&loadedVPKs);
    m_pMemory = loadedVPKs.m_Memory.m_pMemory;
    if ( loadedVPKs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( loadedVPKs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadedVPKs.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        loadedVPKs.m_Memory.m_pMemory = nullptr;
      }
      loadedVPKs.m_Memory.m_nAllocationCount = 0;
    }
    loadedVPKs.m_pElements = m_pMemory;
    if ( loadedVPKs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

} // namespace engine_xlsp
