// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/hammerscene.cpp
// Functions: 7
// ============================================================

#include "hammer\hammerscene.h"

//------------------------------------------------------------------------------
// Address: 0x10045890
// Name: public: virtual char const __near * CSceneTokenProcessor::CurrentToken(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSceneTokenProcessor::CurrentToken(CSceneTokenProcessor *this)
{
  return token;
}

//------------------------------------------------------------------------------
// Address: 0x100458A0
// Name: public: virtual bool CSceneTokenProcessor::GetToken(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::GetToken(CSceneTokenProcessor *this, bool crossline)
{
  return GetToken(crossline) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100458C0
// Name: public: virtual bool CSceneTokenProcessor::TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::TokenAvailable(CSceneTokenProcessor *this)
{
  return TokenAvailable() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100458D0
// Name: public: virtual void CSceneTokenProcessor::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSceneTokenProcessor::Error(CSceneTokenProcessor *this, const char *fmt, ...)
{
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list ap; // [esp+810h] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  _Warning(a1: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x10045910
// Name: char __near * ExpandPath(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ExpandPath(char *path)
{
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: path,
    a3: "GAME",
    a4: fullpath,
    a5: 512,
    a6: FILTER_NONE,
    a7: nullptr);
  return fullpath;
}

//------------------------------------------------------------------------------
// Address: 0x10045940
// Name: int LoadFile(char const __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadFile(const char *filename, void **bufferptr)
{
  void *v2; // ebx
  int v3; // esi
  _BYTE *v4; // edi

  v2 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: "rb", a4: 0);
  if ( v2 != nullptr )
  {
    v3 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
    v4 = MemAlloc_Alloc(nSize: v3 + 1);
    v4[v3] = 0;
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4, a3: v3, a4: v2);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
    *bufferptr = v4;
    return v3;
  }
  else
  {
    *bufferptr = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100459D0
// Name: class CChoreoScene __near * HammerLoadScene(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoScene *__cdecl HammerLoadScene(char *pFilename)
{
  if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr) )
    return nullptr;
  LoadScriptFile(filename: pFilename, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
  return ChoreoLoadScene(filename: pFilename, callback: nullptr, tokenizer: &g_TokenProcessor, pfn: _Msg);
}
