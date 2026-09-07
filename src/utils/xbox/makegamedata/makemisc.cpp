// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makemisc.cpp
// Functions: 17
// ============================================================

#include "utils\xbox\makegamedata\makemisc.h"

//------------------------------------------------------------------------------
// Address: 0x00407330
// Name: unsigned long CRC32_ProcessSingleBuffer(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CRC32_ProcessSingleBuffer(const void *p, int len)
{
  unsigned int crc; // [esp+0h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: p, nBuffer: len);
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x00407370
// Name: bool FindScriptFile(char const __near *,char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindScriptFile(const char *pFilename, char *pOutBuff, int nOutBuffSize, bool bCanFallback)
{
  char *v5; // eax
  char baseModPath[260]; // [esp+Ch] [ebp-30Ch] BYREF
  char scriptPath[260]; // [esp+110h] [ebp-208h] BYREF
  char baseScriptPath[260]; // [esp+214h] [ebp-104h] BYREF

  V_ComposeFileName(path: g_szModPath, filename: pFilename, dest: scriptPath, destSize: 260);
  V_strncpy(pDest: pOutBuff, pSrc: scriptPath, maxLen: nOutBuffSize);
  if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: scriptPath, a3: nullptr) )
  {
    if ( !bCanFallback )
      return 0;
    v5 = _V_strrchr(s: g_szModPath, c: 95);
    if ( v5 == nullptr )
      return 0;
    V_strncpy(pDest: baseModPath, pSrc: g_szModPath, maxLen: v5 - g_szModPath + 1);
    V_ComposeFileName(path: baseModPath, filename: "gameinfo.txt", dest: baseScriptPath, destSize: 260);
    if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: baseScriptPath, a3: nullptr) )
      return 0;
    V_ComposeFileName(path: baseModPath, filename: pFilename, dest: baseScriptPath, destSize: 260);
    if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: baseScriptPath, a3: nullptr) )
      return 0;
    V_strncpy(pDest: pOutBuff, pSrc: baseScriptPath, maxLen: nOutBuffSize);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004074A0
// Name: FindOrAddKVString
// Source: json
//------------------------------------------------------------------------------
void *__usercall FindOrAddKVString@<eax>(const char *pKeyName@<esi>, const char *pString@<eax>, kvType_t kvType)
{
  int v3; // eax
  int v4; // eax
  char cleanString[260]; // [esp+0h] [ebp-104h] BYREF

  V_strncpy(pDest: cleanString, pSrc: pString, maxLen: 260);
  _V_strlower(start: cleanString);
  V_FixSlashes(pname: cleanString, separator: 92);
  if ( kvType == KV_VMT && pKeyName != nullptr && V_stristr(pStr: pKeyName, pSearch: "include") == nullptr )
  {
    strchr(string: (unsigned __int8 *)cleanString, chr: 0x5Cu);
    if ( v3 != 0 )
    {
      strchr(string: (unsigned __int8 *)cleanString, chr: 0x2Eu);
      if ( v4 != 0 )
        V_StripExtension(in: cleanString, out: cleanString, outSize: 260);
    }
  }
  return CUtlFilenameSymbolTable::FindOrAddFileName(this: &g_KVStringPool, pFileName: cleanString);
}

//------------------------------------------------------------------------------
// Address: 0x004075E0
// Name: protected: void CUtlBuffer::PutTypeBin<__int64>(__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<__int64>(CUtlBuffer *this, unsigned __int64 src)
{
  int v3; // eax
  unsigned __int64 *v4; // eax

  if ( CUtlBuffer::CheckPut(this, nSize: 8) )
  {
    v3 = this->m_Put - this->m_nOffset;
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
    {
      v4 = (unsigned __int64 *)&this->m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
        {
          CByteswap::LowLevelByteSwap<unsigned __int64>(output: v4, input: &src);
          this->m_Put += 8;
          CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
          return;
        }
        if ( v4 != &src )
        {
          *v4 = src;
          this->m_Put += 8;
          CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
          return;
        }
      }
    }
    else
    {
      *(_QWORD *)&this->m_Memory.m_pMemory[v3] = src;
    }
    this->m_Put += 8;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407670
// Name: bool CreateTargetFile_RAW(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_RAW(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v4; // ecx
  bool v5; // bl
  char szPWLName[260]; // [esp+4h] [ebp-164h] BYREF
  CUtlBuffer sourceBuffer; // [esp+108h] [ebp-60h] BYREF
  CUtlBuffer targetBuffer; // [esp+138h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &sourceBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  V_StripExtension(in: pSourceName, out: szPWLName, outSize: 260);
  V_DefaultExtension(path: szPWLName, extension: ".pwl.raw", pathStringLength: 260);
  if ( DoesFileExist(pFilename: szPWLName) == 0 )
  {
    _Warning(a1: "Error: Missing PWL: '%s'\n", szPWLName);
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = targetBuffer.m_Memory.m_pMemory;
      if ( targetBuffer.m_Memory.m_pMemory != nullptr )
      {
        v4 = _g_pMemAlloc;
        goto LABEL_17;
      }
LABEL_18:
      targetBuffer.m_Memory.m_nAllocationCount = 0;
    }
LABEL_19:
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return false;
  }
  if ( !ReadFileToBuffer(pSourceName: szPWLName, buffer: &sourceBuffer, bText: false, bNoOpenFailureWarning: false) )
  {
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = targetBuffer.m_Memory.m_pMemory;
      if ( targetBuffer.m_Memory.m_pMemory != nullptr )
      {
        v4 = _g_pMemAlloc;
LABEL_17:
        v4->Free_2(this: v4, a2: m_pMemory);
        targetBuffer.m_Memory.m_pMemory = nullptr;
        goto LABEL_18;
      }
      goto LABEL_18;
    }
    goto LABEL_19;
  }
  v5 = WriteBufferToFile(pTargetName, buffer: &sourceBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
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

//------------------------------------------------------------------------------
// Address: 0x004077D0
// Name: bool WriteCompiledKVPool(bool)
// Source: json
//------------------------------------------------------------------------------
char __usercall WriteCompiledKVPool@<al>(int a1@<ebx>, bool bWriteToZip)
{
  int v2; // esi
  int v4; // eax
  const char *v5; // eax
  bool v6; // bl
  char modName[260]; // [esp+4h] [ebp-138h] BYREF
  CUtlBuffer kvPoolBuffer; // [esp+108h] [ebp-34h] BYREF
  unsigned int pulCRC; // [esp+138h] [ebp-4h] BYREF

  CUtlBuffer::CUtlBuffer(this: &kvPoolBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: &kvPoolBuffer, bActivate: true);
  V_FileBase(in: g_szModPath, out: modName, maxlen: 260);
  v2 = _V_strlen(str: modName);
  CRC32_Init(&pulCRC);
  CRC32_ProcessBuffer(&pulCRC, pBuffer: modName, nBuffer: v2);
  CRC32_Final(&pulCRC);
  if ( (kvPoolBuffer.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &kvPoolBuffer, pFmt: "%u", pulCRC);
  else
    CUtlBuffer::PutTypeBin<int>(this: &kvPoolBuffer, src: pulCRC);
  if ( CUtlFilenameSymbolTable::SaveToBuffer(this: &g_KVStringPool, buffer: &kvPoolBuffer) )
  {
    if ( kvPoolBuffer.m_nMaxPut > 4 )
    {
      v4 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-kvinfo") != 0 )
        CUtlFilenameSymbolTable::SpewStrings(this: &g_KVStringPool);
      v5 = "kvpool.ps3.image";
      if ( !g_bSonyPS3 )
        v5 = "kvpool.360.image";
      v6 = WriteBufferToFile(pTargetName: v5, buffer: &kvPoolBuffer, bWriteToZip, writeMode: WRITE_TO_DISK_NEVER);
      if ( kvPoolBuffer.m_Memory.m_nGrowSize >= 0 && kvPoolBuffer.m_Memory.m_pMemory != nullptr )
        ((void (__thiscall *)(IMemAlloc *, unsigned __int8 *, int))_g_pMemAlloc->Free_2)(
          a1: _g_pMemAlloc,
          a2: kvPoolBuffer.m_Memory.m_pMemory,
          a3: a1);
      return v6;
    }
    else
    {
      if ( kvPoolBuffer.m_Memory.m_nGrowSize >= 0 && kvPoolBuffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: kvPoolBuffer.m_Memory.m_pMemory);
      return 1;
    }
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_58DC44, a2: *(const char **)modName);
    if ( kvPoolBuffer.m_Memory.m_nGrowSize >= 0 && kvPoolBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: kvPoolBuffer.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004079C0
// Name: public: void CUtlBuffer::PutInt64(__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutInt64(CUtlBuffer *this, unsigned __int64 i)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%lld", i);
  else
    CUtlBuffer::PutTypeBin<__int64>(this, src: i);
}

//------------------------------------------------------------------------------
// Address: 0x004079F0
// Name: bool ProcessDXSupportConfig(bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall ProcessDXSupportConfig@<al>(int a1@<ebx>, bool bWriteToZip)
{
  KeyValues *v3; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *FirstSubKey; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  int Int; // eax
  KeyValues *j; // esi
  const char *v11; // eax
  bool v12; // bl
  const char *String; // [esp-Ch] [ebp-2ACh]
  char szSourcePath[260]; // [esp+0h] [ebp-2A0h] BYREF
  char szTempPath[260]; // [esp+104h] [ebp-19Ch] BYREF
  CUtlBuffer targetBuf; // [esp+208h] [ebp-98h] BYREF
  CUtlBuffer sourceBuf; // [esp+238h] [ebp-68h] BYREF
  CUtlBuffer kvBuffer; // [esp+268h] [ebp-38h] BYREF
  int nConsoleDXLevel; // [esp+298h] [ebp-8h]
  KeyValues *pKV; // [esp+29Ch] [ebp-4h]

  if ( !g_bIsPlatformZip )
    return false;
  V_ComposeFileName(path: g_szModPath, filename: "../bin", dest: szTempPath, destSize: 260);
  V_ComposeFileName(path: szTempPath, filename: "dxsupport.cfg", dest: szSourcePath, destSize: 260);
  v3 = nullptr;
  CUtlBuffer::CUtlBuffer(this: &sourceBuf, growSize: 0, initSize: 0, nFlags: 1);
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *, _DWORD, CUtlBuffer *, _DWORD, _DWORD, _DWORD, int))g_pFullFileSystem->ReadFile)(
         a1: &g_pFullFileSystem->IBaseFileSystem,
         a2: szSourcePath,
         a3: 0,
         a4: &sourceBuf,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: a1) != 0 )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: pDefaultValue);
      pKV = v5;
    }
    else
    {
      pKV = nullptr;
      v5 = nullptr;
    }
    if ( KeyValues::LoadFromBuffer(
           this: v5,
           resourceName: "dxsupport.cfg",
           buf: &sourceBuf,
           pFileSystem: nullptr,
           pPathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      nConsoleDXLevel = !g_bSonyPS3 + 97;
      FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
      if ( FirstSubKey != nullptr )
      {
        while ( v3 == nullptr )
        {
          for ( i = KeyValues::GetFirstSubKey(this: FirstSubKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
          {
            if ( v3 != nullptr )
              break;
            Name = KeyValues::GetName(this: i);
            if ( _V_stricmp(s1: Name, s2: "name") == 0 )
            {
              Int = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
              if ( Int == nConsoleDXLevel )
                v3 = FirstSubKey;
            }
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          if ( FirstSubKey == nullptr )
          {
            if ( v3 == nullptr )
            {
              v5 = pKV;
              goto LABEL_27;
            }
            break;
          }
        }
        CUtlBuffer::CUtlBuffer(this: &kvBuffer, growSize: 0, initSize: 0, nFlags: 1);
        CUtlBuffer::Printf(this: &kvBuffer, pFmt: "\"dxsupport\"\n");
        CUtlBuffer::Printf(this: &kvBuffer, pFmt: "{\n");
        CUtlBuffer::Printf(this: &kvBuffer, pFmt: "\t\"0\"\n");
        CUtlBuffer::Printf(this: &kvBuffer, pFmt: "\t{\n");
        for ( j = KeyValues::GetFirstSubKey(this: v3); j != nullptr; j = KeyValues::GetNextKey(this: j) )
        {
          String = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: pDefaultValue);
          v11 = KeyValues::GetName(this: j);
          CUtlBuffer::Printf(this: &kvBuffer, pFmt: "\t\t\"%s\" \"%s\"\n", v11, String);
        }
        CUtlBuffer::Printf(this: &kvBuffer, pFmt: "\t}\n");
        CUtlBuffer::Printf(this: &kvBuffer, pFmt: "}\n");
        CUtlBuffer::CUtlBuffer(this: &targetBuf, growSize: 0, initSize: 0, nFlags: 5);
        CUtlBuffer::ConvertCRLF(this: &kvBuffer, outBuf: &targetBuf);
        v12 = WriteBufferToFile(
                pTargetName: "dxsupport.cfg",
                buffer: &targetBuf,
                bWriteToZip,
                writeMode: WRITE_TO_DISK_NEVER);
        KeyValues::deleteThis(this: pKV);
        if ( targetBuf.m_Memory.m_nGrowSize >= 0 )
        {
          if ( targetBuf.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuf.m_Memory.m_pMemory);
            targetBuf.m_Memory.m_pMemory = nullptr;
          }
          targetBuf.m_Memory.m_nAllocationCount = 0;
        }
        if ( kvBuffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( kvBuffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: kvBuffer.m_Memory.m_pMemory);
            kvBuffer.m_Memory.m_pMemory = nullptr;
          }
          kvBuffer.m_Memory.m_nAllocationCount = 0;
        }
        if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
        return v12;
      }
      else
      {
LABEL_27:
        _Warning(
          a1: "Error! Couldn't find expected dxlevel %d in config file '%s'!\n",
          nConsoleDXLevel,
          "dxsupport.cfg");
        KeyValues::deleteThis(this: v5);
        if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
        return false;
      }
    }
    else
    {
      _Warning(a1: (const char *)&stru_58DCE4, "dxsupport.cfg");
      KeyValues::deleteThis(this: v5);
      if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
      return false;
    }
  }
  else
  {
    _Warning(a1: "Error! Couldn't open file '%s'!\n", "dxsupport.cfg");
    if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407D60
// Name: bool CreateTargetFile_LocalizedTXT(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_LocalizedTXT(char *pSourceName, char *pTargetName, bool bWriteToZip)
{
  bool v4; // bl
  unsigned __int8 *m_pMemory; // eax
  bool v6; // zf
  unsigned __int8 *v7; // edx
  wchar_t *v8; // esi
  bool v9; // bl
  wchar_t *i; // edi
  wchar_t *v11; // esi
  wchar_t string[4096]; // [esp+8h] [ebp-41ECh] BYREF
  wchar_t wcs1[4096]; // [esp+2008h] [ebp-21ECh] BYREF
  wchar_t token[128]; // [esp+4008h] [ebp-1ECh] BYREF
  char s1[128]; // [esp+4108h] [ebp-ECh] BYREF
  CUtlBuffer buffer; // [esp+4188h] [ebp-6Ch] BYREF
  CUtlBuffer buf; // [esp+41B8h] [ebp-3Ch] BYREF
  bool addQuotes[4]; // [esp+41EBh] [ebp-9h] BYREF
  bool quoted[4]; // [esp+41EFh] [ebp-5h] BYREF
  bool v20; // [esp+41F3h] [ebp-1h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName, &buffer, bText: false, bNoOpenFailureWarning: false) )
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
    return false;
  }
  if ( V_stristr(pStr: pSourceName, pSearch: "_english") != nullptr )
  {
    v4 = WriteBufferToFile(pTargetName, &buffer, bWriteToZip, writeMode: WRITE_TO_DISK_NEVER);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( buffer.m_Memory.m_nGrowSize < 0 )
      return v4;
    m_pMemory = buffer.m_Memory.m_pMemory;
    v6 = buffer.m_Memory.m_pMemory == nullptr;
LABEL_60:
    if ( !v6 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v4;
  }
  if ( (buffer.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buffer, pFmt: "%hd", 0);
  else
    CUtlBuffer::PutTypeBin<short>(this: &buffer, src: 0);
  CUtlBuffer::EnsureCapacity(this: &buf, num: buffer.m_Put);
  v7 = buffer.m_Memory.m_pMemory;
  if ( *(_WORD *)buffer.m_Memory.m_pMemory == 0xFEFF )
  {
    v8 = (wchar_t *)(buffer.m_Memory.m_pMemory + 2);
    if ( (buf.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &buf, pFmt: "%hd", -257);
    else
      CUtlBuffer::PutTypeBin<short>(this: &buf, src: 0xFEFFu);
    v9 = false;
    for ( i = ReadUnicodeToken(start: v8, token, tokenBufferSize: 128, quoted);
          token[0] != 0;
          i = ReadUnicodeToken(start: i, token, tokenBufferSize: 128, quoted) )
    {
      _V_UnicodeToUTF8(a1: token, a2: s1, a3: 128);
      if ( V_strnicmp(s1, s2: "//", n: 2) != 0 )
      {
        if ( _V_stricmp(s1, s2: "}") != 0 )
        {
          i = ReadUnicodeTokenNoSpecial(start: i, token: string, tokenBufferSize: 4096, quoted: addQuotes);
          if ( string[0] == 0 && !addQuotes[0] )
            break;
          if ( v9 )
          {
            if ( V_strnicmp(s1, s2: "[english]", n: 9) != 0 )
            {
              v11 = ReadUnicodeToken(start: i, token: wcs1, tokenBufferSize: 4096, quoted: &v20);
              WriteUnicodeString(&buf, string: token, addQuotes: quoted[0]);
              WriteAsciiStringAsUnicode(&buf, string: "\t", addQuotes: false);
              WriteUnicodeString(&buf, string, addQuotes: addQuotes[0]);
              if ( !v20
                && (wcsstr(wcs1, wcs2: L"[$") != nullptr
                 || wcsstr(wcs1, wcs2: L"[!$") != nullptr
                 || wcsstr(wcs1, wcs2: L"[ !$") != nullptr
                 || wcsstr(wcs1, wcs2: L"[ $") != nullptr) )
              {
                WriteAsciiStringAsUnicode(&buf, string: "\t", addQuotes: false);
                WriteUnicodeString(&buf, string: wcs1, addQuotes: false);
                i = v11;
              }
              WriteAsciiStringAsUnicode(&buf, string: "\n", addQuotes: false);
            }
          }
          else if ( _V_stricmp(s1, s2: "language") != 0 )
          {
            if ( _V_stricmp(s1, s2: "lang") == 0 || _V_stricmp(s1, s2: "tokens") == 0 )
            {
              WriteUnicodeString(&buf, string: token, addQuotes: quoted[0]);
              WriteAsciiStringAsUnicode(&buf, string: "\n", addQuotes: false);
              WriteAsciiStringAsUnicode(&buf, string: "{\n", addQuotes: false);
              v9 = _V_stricmp(s1, s2: "tokens") == 0;
            }
          }
          else
          {
            WriteUnicodeString(&buf, string: token, addQuotes: quoted[0]);
            WriteAsciiStringAsUnicode(&buf, string: "\t", addQuotes: false);
            WriteUnicodeString(&buf, string, addQuotes: addQuotes[0]);
            WriteAsciiStringAsUnicode(&buf, string: "\n", addQuotes: false);
          }
        }
        else
        {
          WriteAsciiStringAsUnicode(&buf, string: "}\n", addQuotes: false);
        }
      }
      else
      {
        i = ReadToEndOfLine(start: i);
      }
    }
    v4 = WriteBufferToFile(pTargetName, buffer: &buf, bWriteToZip, writeMode: WRITE_TO_DISK_NEVER);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    if ( buffer.m_Memory.m_nGrowSize < 0 )
      return v4;
    m_pMemory = buffer.m_Memory.m_pMemory;
    v6 = buffer.m_Memory.m_pMemory == nullptr;
    goto LABEL_60;
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      v7 = buffer.m_Memory.m_pMemory;
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && v7 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00408250
// Name: CompileKVToBuffer_r
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CompileKVToBuffer_r(kvType_t kvType, KeyValues *pKV, CUtlBuffer *buffer)
{
  bool result; // al
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  const char *v7; // esi
  int Int; // eax
  const char *String; // eax
  void *v10; // eax
  int i; // esi
  int v12; // eax
  unsigned __int64 Uint64; // rax
  void *Ptr; // eax
  char v15; // al
  void *defaultValue; // [esp+0h] [ebp-124h]
  int defaultValuea; // [esp+0h] [ebp-124h]
  char pDest[260]; // [esp+10h] [ebp-114h] BYREF
  const wchar_t *pValueString; // [esp+114h] [ebp-10h]
  Color v20; // [esp+118h] [ebp-Ch] BYREF
  Color defaultColor; // [esp+120h] [ebp-4h] BYREF
  KeyValues::types_t value; // [esp+134h] [ebp+10h]
  int valuea; // [esp+134h] [ebp+10h]
  float valueb; // [esp+134h] [ebp+10h]

  if ( (buffer->m_Flags & 1) != 0 || buffer->m_Error != 0 )
    return false;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKV);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      value = KeyValues::GetDataType(this: FirstSubKey, keyName: nullptr);
      Name = KeyValues::GetName(this: FirstSubKey);
      v7 = Name;
      if ( kvType != KV_VMT || value == TYPE_NONE || *Name != 37 )
        break;
$LN27:
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        goto LABEL_38;
    }
    if ( value == TYPE_INT )
    {
      Int = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
      if ( Int != 0 )
      {
        if ( Int == 1 )
        {
          value = TYPE_COMPILED_INT_1;
        }
        else if ( (unsigned int)(Int + 128) <= 0xFF )
        {
          value = TYPE_COMPILED_INT_BYTE;
        }
      }
      else
      {
        value = TYPE_COMPILED_INT_0;
      }
    }
    if ( (buffer->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buffer, pFmt: "%hu", (unsigned __int8)value);
    }
    else if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
    {
      buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = value;
      CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
    }
    V_strncpy(pDest, pSrc: v7, maxLen: 260);
    _V_strlower(start: pDest);
    V_FixSlashes(pname: pDest, separator: 92);
    defaultValue = CUtlFilenameSymbolTable::FindOrAddFileName(this: &g_KVStringPool, pFileName: pDest);
    if ( (buffer->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: buffer, pFmt: "%u", defaultValue);
    else
      CUtlBuffer::PutTypeBin<int>(this: buffer, src: (int)defaultValue);
    switch ( value )
    {
      case TYPE_NONE:
        CompileKVToBuffer_r(kvType, pKV: FirstSubKey, buffer);
        goto $LN27;
      case TYPE_STRING:
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: pDefaultValue);
        v10 = FindOrAddKVString(pKeyName: v7, pString: String, kvType);
        CUtlBuffer::PutUnsignedInt(this: buffer, u: (unsigned int)v10);
        goto $LN27;
      case TYPE_INT:
        v12 = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
        CUtlBuffer::PutInt(this: buffer, i: v12);
        goto $LN27;
      case TYPE_FLOAT:
        valueb = KeyValues::GetFloat(this: FirstSubKey, keyName: nullptr, defaultValue: 0.0);
        CUtlBuffer::PutFloat(this: buffer, f: valueb);
        goto $LN27;
      case TYPE_PTR:
        Ptr = KeyValues::GetPtr(this: FirstSubKey, keyName: nullptr, defaultValue: nullptr);
        CUtlBuffer::PutUnsignedInt(this: buffer, u: (unsigned int)Ptr);
        goto $LN27;
      case TYPE_WSTRING:
        pValueString = KeyValues::GetWString(this: FirstSubKey, keyName: nullptr, defaultValue: &word_58DD98);
        valuea = _V_wcslen(pwch: pValueString);
        CUtlBuffer::PutUnsignedShort(this: buffer, s: valuea);
        for ( i = 0; i < valuea; ++i )
        {
          defaultValuea = pValueString[i];
          if ( (buffer->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: buffer, pFmt: "%hu", defaultValuea);
          else
            CUtlBuffer::PutTypeBin<short>(this: buffer, src: defaultValuea);
        }
        goto $LN27;
      case TYPE_COLOR:
        defaultColor = 0;
        KeyValues::GetColor(this: FirstSubKey, result: &v20, keyName: nullptr, &defaultColor);
        CUtlBuffer::PutUnsignedChar(this: buffer, c: v20._color[0]);
        CUtlBuffer::PutUnsignedChar(this: buffer, c: v20._color[1]);
        CUtlBuffer::PutUnsignedChar(this: buffer, c: v20._color[2]);
        CUtlBuffer::PutUnsignedChar(this: buffer, c: v20._color[3]);
        goto $LN27;
      case TYPE_UINT64:
        Uint64 = KeyValues::GetUint64(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
        CUtlBuffer::PutInt64(this: buffer, i: Uint64);
        goto $LN27;
      case TYPE_COMPILED_INT_BYTE:
        v15 = KeyValues::GetInt(this: FirstSubKey, keyName: nullptr, defaultValue: 0);
        CUtlBuffer::PutChar(this: buffer, c: v15);
        goto $LN27;
      case TYPE_COMPILED_INT_0:
      case TYPE_COMPILED_INT_1:
        goto $LN27;
      default:
        result = false;
        break;
    }
  }
  else
  {
LABEL_38:
    if ( (buffer->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: buffer, pFmt: "%hu", 11);
    }
    else if ( CUtlBuffer::CheckPut(this: buffer, nSize: 1) )
    {
      buffer->m_Memory.m_pMemory[buffer->m_Put - buffer->m_nOffset] = 11;
      CUtlBuffer::AddNullTermination(this: buffer, nPut: ++buffer->m_Put);
      return buffer->m_Error == 0;
    }
    return buffer->m_Error == 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004085B0
// Name: bool CompileKVToBuffer(char const __near *,enum kvType_t,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CompileKVToBuffer(const char *pKVFilename, kvType_t kvType, CUtlBuffer *inBuffer, CUtlBuffer *outBuffer)
{
  unsigned __int8 *m_pMemory; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  int v7; // eax
  const char *Name; // eax
  void *v9; // eax
  int v11; // [esp-8h] [ebp-114h]
  char modName[260]; // [esp+8h] [ebp-104h] BYREF

  m_pMemory = inBuffer->m_Memory.m_pMemory;
  if ( V_stristr(pStr: (const char *)inBuffer->m_Memory.m_pMemory, pSearch: "#include") != nullptr
    || V_stristr(pStr: (const char *)m_pMemory, pSearch: "#base") != nullptr
    || V_stristr(pStr: (const char *)m_pMemory, pSearch: "[$") != nullptr )
  {
    return 0;
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "kv");
  else
    v6 = nullptr;
  if ( !KeyValues::LoadFromBuffer(
          this: v6,
          resourceName: pKVFilename,
          buf: inBuffer,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
    goto LABEL_14;
  CUtlBuffer::Purge(this: outBuffer);
  CUtlBuffer::ActivateByteSwapping(this: outBuffer, bActivate: true);
  CUtlBuffer::PutUnsignedChar(this: outBuffer, c: 0xAAu);
  V_FileBase(in: g_szModPath, out: modName, maxlen: 260);
  v7 = _V_strlen(str: modName);
  v11 = CRC32_ProcessSingleBuffer(p: modName, len: v7);
  if ( (outBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: outBuffer, pFmt: "%u", v11);
  else
    CUtlBuffer::PutTypeBin<int>(this: outBuffer, src: v11);
  if ( KeyValues::GetDataType(this: v6, keyName: nullptr) != TYPE_NONE )
    goto LABEL_14;
  CUtlBuffer::PutUnsignedChar(this: outBuffer, c: 0);
  Name = KeyValues::GetName(this: v6);
  v9 = FindOrAddKVString(pKeyName: nullptr, pString: Name, kvType);
  CUtlBuffer::PutUnsignedInt(this: outBuffer, u: (unsigned int)v9);
  if ( !CompileKVToBuffer_r(kvType, pKV: v6, buffer: outBuffer) )
  {
    _Warning(a1: "CompileKVToBuffer() failed on %s\n", pKVFilename);
LABEL_14:
    KeyValues::deleteThis(this: v6);
    return 0;
  }
  KeyValues::deleteThis(this: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408730
// Name: bool CreateTargetFile_CompiledKV_TXT(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_CompiledKV_TXT(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  bool v4; // al
  bool v5; // bl
  CUtlBuffer sourceBuffer; // [esp+8h] [ebp-60h] BYREF
  CUtlBuffer targetBuffer; // [esp+38h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &sourceBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName, buffer: &sourceBuffer, bText: true, bNoOpenFailureWarning: false) )
  {
    if ( CompileKVToBuffer(
           pKVFilename: pSourceName,
           kvType: KV_OTHER,
           inBuffer: &sourceBuffer,
           outBuffer: &targetBuffer) != 0 )
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
// Address: 0x00408850
// Name: public: CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned short> *__thiscall CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(
        CCountedStringPoolBase<unsigned short> *this,
        StringPoolCase_t caseSensitivity)
{
  int i; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // ecx
  int v7; // eax

  this->__vftable = (CCountedStringPoolBase<unsigned short>_vtbl *)&CCountedStringPoolBase<unsigned short>::`vftable';
  this->m_HashTable.m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Size = 0;
  this->m_HashTable.m_pElements = nullptr;
  this->m_Elements.m_Memory.m_pMemory = nullptr;
  this->m_Elements.m_Memory.m_nAllocationCount = 0;
  this->m_Elements.m_Memory.m_nGrowSize = 0;
  this->m_Elements.m_Size = 0;
  this->m_Elements.m_pElements = nullptr;
  if ( this->m_HashTable.m_Size < 1024 )
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: &this->m_HashTable,
      elem: this->m_HashTable.m_Size,
      num: 1024 - this->m_HashTable.m_Size);
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  this->m_FreeListStart = 0;
  m_Size = this->m_Elements.m_Size;
  m_nAllocationCount = this->m_Elements.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      this: (CUtlMemory<ResourceEntryInfo,int> *)&this->m_Elements,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Elements.m_Size;
  m_pMemory = this->m_Elements.m_Memory.m_pMemory;
  v7 = this->m_Elements.m_Size - m_Size - 1;
  this->m_Elements.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v7);
  this->m_Elements.m_Memory.m_pMemory->pString = nullptr;
  this->m_Elements.m_Memory.m_pMemory->nReferenceCount = 0;
  this->m_Elements.m_Memory.m_pMemory->nNextElement = 0;
  this->m_caseSensitivity = caseSensitivity;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408930
// Name: public: void CCountedStringPoolBase<unsigned short>::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCountedStringPoolBase<unsigned short>::FreeAll(CCountedStringPoolBase<unsigned short> *this)
{
  int i; // eax
  int v3; // edi
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned short>::hash_item_t *v6; // ecx
  int v7; // eax

  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  v3 = 0;
  for ( this->m_FreeListStart = 0; v3 < this->m_Elements.m_Size; ++v3 )
  {
    m_pMemory = this->m_Elements.m_Memory.m_pMemory;
    if ( m_pMemory[v3].pString != nullptr )
    {
      free(pMem: m_pMemory[v3].pString);
      this->m_Elements.m_Memory.m_pMemory[v3].pString = nullptr;
      this->m_Elements.m_Memory.m_pMemory[v3].nReferenceCount = 0;
      this->m_Elements.m_Memory.m_pMemory[v3].nNextElement = 0;
    }
  }
  this->m_Elements.m_Size = 0;
  m_nAllocationCount = this->m_Elements.m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount < 1 )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      this: (CUtlMemory<ResourceEntryInfo,int> *)&this->m_Elements,
      num: 1 - m_nAllocationCount);
  ++this->m_Elements.m_Size;
  v6 = this->m_Elements.m_Memory.m_pMemory;
  v7 = this->m_Elements.m_Size - 1;
  this->m_Elements.m_pElements = v6;
  if ( v7 > 0 )
    _V_memmove(dest: &v6[1], src: v6, count: 8 * v7);
  this->m_Elements.m_Memory.m_pMemory->pString = nullptr;
  this->m_Elements.m_Memory.m_pMemory->nReferenceCount = 0;
  this->m_Elements.m_Memory.m_pMemory->nNextElement = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004089F0
// Name: public: CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned int> *__thiscall CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(
        CCountedStringPoolBase<unsigned int> *this,
        StringPoolCase_t caseSensitivity)
{
  int i; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pMemory; // edx
  int v7; // eax

  this->__vftable = (CCountedStringPoolBase<unsigned int>_vtbl *)&CCountedStringPoolBase<unsigned int>::`vftable';
  this->m_HashTable.m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Size = 0;
  this->m_HashTable.m_pElements = nullptr;
  this->m_Elements.m_Memory.m_pMemory = nullptr;
  this->m_Elements.m_Memory.m_nAllocationCount = 0;
  this->m_Elements.m_Memory.m_nGrowSize = 0;
  this->m_Elements.m_Size = 0;
  this->m_Elements.m_pElements = nullptr;
  if ( this->m_HashTable.m_Size < 1024 )
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_HashTable,
      elem: this->m_HashTable.m_Size,
      num: 1024 - this->m_HashTable.m_Size);
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  this->m_FreeListStart = 0;
  m_Size = this->m_Elements.m_Size;
  m_nAllocationCount = this->m_Elements.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_Elements,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Elements.m_Size;
  m_pMemory = this->m_Elements.m_Memory.m_pMemory;
  v7 = this->m_Elements.m_Size - m_Size - 1;
  this->m_Elements.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v7);
  this->m_Elements.m_Memory.m_pMemory->pString = nullptr;
  this->m_Elements.m_Memory.m_pMemory->nReferenceCount = 0;
  this->m_Elements.m_Memory.m_pMemory->nNextElement = 0;
  this->m_caseSensitivity = caseSensitivity;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408AD0
// Name: public: void CCountedStringPoolBase<unsigned int>::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCountedStringPoolBase<unsigned int>::FreeAll(CCountedStringPoolBase<unsigned int> *this)
{
  int v2; // edi
  int i; // eax
  int v4; // ebx
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pMemory; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned int>::hash_item_t *v8; // ecx
  int v9; // eax

  v2 = 0;
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  v4 = 0;
  for ( this->m_FreeListStart = 0; v4 < this->m_Elements.m_Size; ++v2 )
  {
    m_pMemory = this->m_Elements.m_Memory.m_pMemory;
    if ( m_pMemory[v2].pString != nullptr )
    {
      free(pMem: m_pMemory[v2].pString);
      this->m_Elements.m_Memory.m_pMemory[v2].pString = nullptr;
      this->m_Elements.m_Memory.m_pMemory[v2].nReferenceCount = 0;
      this->m_Elements.m_Memory.m_pMemory[v2].nNextElement = 0;
    }
    ++v4;
  }
  this->m_Elements.m_Size = 0;
  m_Size = this->m_Elements.m_Size;
  m_nAllocationCount = this->m_Elements.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_Elements,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Elements.m_Size;
  v8 = this->m_Elements.m_Memory.m_pMemory;
  v9 = this->m_Elements.m_Size - m_Size - 1;
  this->m_Elements.m_pElements = v8;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[m_Size + 1], src: &v8[m_Size], count: 12 * v9);
  this->m_Elements.m_Memory.m_pMemory->pString = nullptr;
  this->m_Elements.m_Memory.m_pMemory->nReferenceCount = 0;
  this->m_Elements.m_Memory.m_pMemory->nNextElement = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CFC40
// Name: public: void CUtlMemory<struct CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
        CUtlMemory<CVTFTexture::ResourceMemorySection,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
