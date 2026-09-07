// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/maketextures.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004182B0
// Name: Add1024TextureFilenameToDictionary
// Source: json
//------------------------------------------------------------------------------
void __usercall Add1024TextureFilenameToDictionary(const char *pFilename@<esi>)
{
  char cleanFilename[262]; // [esp+0h] [ebp-108h] BYREF
  CUtlSymbol result; // [esp+106h] [ebp-2h] BYREF

  if ( V_stristr(pStr: pFilename, pSearch: ".vtf") != nullptr
    && V_stristr(pStr: pFilename, pSearch: ".pwl.vtf") == nullptr
    && V_stristr(pStr: pFilename, pSearch: ".ps3.vtf") == nullptr
    && V_stristr(pStr: pFilename, pSearch: ".360.vtf") == nullptr )
  {
    V_strncpy(pDest: cleanFilename, pSrc: pFilename, maxLen: 260);
    _V_strlower(start: cleanFilename);
    V_RemoveDotSlashes(pFilename: cleanFilename, separator: 92);
    if ( CUtlSymbolTable::Find(this: &g_Allow1024TextureTable, &result, pString: cleanFilename)->m_Id == 0xFFFF )
      CUtlSymbolTable::AddString(this: &g_Allow1024TextureTable, &result, pString: cleanFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418370
// Name: bool GetPreloadData_VTF(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetPreloadData_VTF(const char *pFilename, CUtlBuffer *fileBufferIn, CUtlBuffer *preloadBufferOut)
{
  bool VTFPreloadPS3Data; // al

  if ( g_bSonyPS3 )
    VTFPreloadPS3Data = GetVTFPreloadPS3Data(pDebugName: pFilename, fileBufferIn, preloadBufferOut);
  else
    VTFPreloadPS3Data = GetVTFPreload360Data(pDebugName: pFilename, fileBufferIn, preloadBufferOut);
  if ( VTFPreloadPS3Data )
    return 1;
  _Warning(a1: "Can't preload: '%s', has bad version\n", pFilename);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004183C0
// Name: bool CreateTargetFile_VTF(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_VTF(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  const char *v3; // esi
  bool v5; // al
  bool v6; // bl
  char pDest[260]; // [esp+8h] [ebp-164h] BYREF
  CUtlBuffer sourceBuffer; // [esp+10Ch] [ebp-60h] BYREF
  CUtlBuffer targetBuffer; // [esp+13Ch] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &sourceBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  v3 = pSourceName;
  V_strncpy(pDest, pSrc: pSourceName, maxLen: 260);
  _V_strlower(start: pDest);
  V_RemoveDotSlashes(pFilename: pDest, separator: 92);
  LOBYTE(pSourceName) = CUtlSymbolTable::Find(
                          this: &g_Allow1024TextureTable,
                          result: (CUtlSymbol *)&pSourceName + 1,
                          pString: pDest)->m_Id != 0xFFFF;
  if ( ReadFileToBuffer(pSourceName: v3, buffer: &sourceBuffer, bText: false, bNoOpenFailureWarning: false) )
  {
    if ( g_bSonyPS3 )
      v5 = ConvertVTFToPS3Format(
             pDebugName: v3,
             sourceBuf: &sourceBuffer,
             targetBuf: &targetBuffer,
             pCompressFunc: nullptr,
             bAllow1024Texture: (bool)pSourceName);
    else
      v5 = ConvertVTFTo360Format(
             pDebugName: v3,
             sourceBuf: &sourceBuffer,
             targetBuf: &targetBuffer,
             pCompressFunc: nullptr,
             bAllow1024Texture: (bool)pSourceName);
    v6 = v5;
    if ( v5 )
      v6 = WriteBufferToFile(pTargetName, buffer: &targetBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( targetBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
        targetBuffer.m_Memory.m_pMemory = nullptr;
      }
      targetBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return v6;
  }
  else
  {
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( targetBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
        targetBuffer.m_Memory.m_pMemory = nullptr;
      }
      targetBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418530
// Name: bool CreateTargetFile_VMT(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_VMT(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  bool v4; // al
  bool v5; // bl
  CUtlBuffer sourceBuffer; // [esp+8h] [ebp-60h] BYREF
  CUtlBuffer targetBuffer; // [esp+38h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &sourceBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName, buffer: &sourceBuffer, bText: true, bNoOpenFailureWarning: false) )
  {
    if ( CompileKVToBuffer(pKVFilename: pSourceName, kvType: KV_VMT, inBuffer: &sourceBuffer, outBuffer: &targetBuffer) != 0 )
    {
      v4 = WriteBufferToFile(pTargetName, buffer: &targetBuffer, bWriteToZip, writeMode: WRITE_TO_DISK_NEVER);
    }
    else
    {
      _Warning(a1: "Not Compiling: %s\n", pSourceName);
      v4 = WriteBufferToFile(pTargetName, buffer: &sourceBuffer, bWriteToZip, writeMode: WRITE_TO_DISK_NEVER);
    }
    v5 = v4;
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( targetBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
        targetBuffer.m_Memory.m_pMemory = nullptr;
      }
      targetBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return v5;
  }
  else
  {
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( targetBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
        targetBuffer.m_Memory.m_pMemory = nullptr;
      }
      targetBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418650
// Name: bool BuildPWLTextureList(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildPWLTextureList()
{
  CUtlBuffer buffer; // [esp+0h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00418690
// Name: bool BuildAllow1024TextureList(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildAllow1024TextureList()
{
  int v0; // ebx
  int v2; // edi
  const char *v3; // esi
  fileList_t *m_pMemory; // eax
  int v5; // eax
  int v6; // esi
  const char *v7; // eax
  char dest[260]; // [esp+Ch] [ebp-554h] BYREF
  char szFilename[260]; // [esp+110h] [ebp-450h] BYREF
  characterset_t breakSet; // [esp+214h] [ebp-34Ch] BYREF
  char szToken[260]; // [esp+314h] [ebp-24Ch] BYREF
  char szFullPath[260]; // [esp+418h] [ebp-148h] BYREF
  CUtlBuffer buffer; // [esp+51Ch] [ebp-44h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+54Ch] [ebp-14h] BYREF

  v0 = 0;
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  FindScriptFile(pFilename: "materials/allow1024.txt", pOutBuff: szFilename, nOutBuffSize: 260, bCanFallback: true);
  if ( ReadFileToBuffer(pSourceName: szFilename, &buffer, bText: true, bNoOpenFailureWarning: true) )
  {
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: pDefaultValue);
    while ( CUtlBuffer::ParseToken(
              this: &buffer,
              pBreaks: &breakSet,
              pTokenBuf: szToken,
              nMaxLen: 260,
              bParseComments: true) > 0 )
    {
      V_ComposeFileName(path: "materials", filename: szToken, dest, destSize: 260);
      V_ComposeFileName(path: g_szModPath, filename: dest, dest: szFullPath, destSize: 260);
      _V_strlower(start: szFullPath);
      V_RemoveDotSlashes(pFilename: szFullPath, separator: 92);
      if ( V_stristr(pStr: szFullPath, pSearch: "*") != nullptr || V_stristr(pStr: szFullPath, pSearch: "?") != nullptr )
      {
        memset(&fileList, 0, sizeof(fileList));
        FindFiles(pFileMask: szFullPath, bRecurse: true, &fileList);
        v2 = 0;
        if ( fileList.m_Size > 0 )
        {
          do
          {
            v3 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v0].fileName);
            Add1024TextureFilenameToDictionary(pFilename: v3);
            ++v2;
            ++v0;
          }
          while ( v2 < fileList.m_Size );
          v0 = 0;
        }
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
        m_pMemory = fileList.m_Memory.m_pMemory;
        if ( fileList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( fileList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            fileList.m_Memory.m_pMemory = nullptr;
          }
          fileList.m_Memory.m_nAllocationCount = 0;
        }
        fileList.m_pElements = m_pMemory;
        if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      }
      else
      {
        Add1024TextureFilenameToDictionary(pFilename: szFullPath);
        v0 = 0;
      }
    }
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-spewallow1024") != 0 )
    {
      _Msg(a1: "Allow 1024 Textures:\n");
      v6 = 0;
      if ( g_Allow1024TextureTable.m_Lookup.m_NumElements != 0 )
      {
        do
        {
          v7 = CUtlSymbolTable::String(this: &g_Allow1024TextureTable, id: (CUtlSymbol)v6);
          _Msg(a1: (const char *)&stru_58D3D0, v7);
          ++v6;
        }
        while ( v6 < g_Allow1024TextureTable.m_Lookup.m_NumElements );
      }
    }
    if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
    return 0;
  }
}
