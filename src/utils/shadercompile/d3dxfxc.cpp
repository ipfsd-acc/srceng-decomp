// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/shadercompile/d3dxfxc.cpp
// Functions: 8
// ============================================================

#include "utils\shadercompile\d3dxfxc.h"

//------------------------------------------------------------------------------
// Address: 0x10008480
// Name: public: virtual bool InterceptFxc::Private::CResponse::Succeeded(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall InterceptFxc::Private::CResponse::Succeeded(InterceptFxc::Private::CResponse *this)
{
  return this->m_pShader != nullptr && this->m_hr == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100084A0
// Name: public: virtual unsigned int InterceptFxc::Private::CResponse::GetResultBufferLen(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall InterceptFxc::Private::CResponse::GetResultBufferLen(InterceptFxc::Private::CResponse *this)
{
  if ( this->Succeeded(this) )
    return this->m_pShader->GetBufferSize(this: this->m_pShader);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100084C0
// Name: public: virtual void const __near * InterceptFxc::Private::CResponse::GetResultBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall InterceptFxc::Private::CResponse::GetResultBuffer(InterceptFxc::Private::CResponse *this)
{
  if ( this->Succeeded(this) )
    return this->m_pShader->GetBufferPointer(this: this->m_pShader);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100084E0
// Name: public: virtual char const __near * InterceptFxc::Private::CResponse::GetListing(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall InterceptFxc::Private::CResponse::GetListing(InterceptFxc::Private::CResponse *this)
{
  if ( this->m_pListing != nullptr )
    return (const char *)this->m_pListing->GetBufferPointer(this: this->m_pListing);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008550
// Name: void InterceptFxc::Private::FastShaderCompile(enum InterceptFxc::ExecutableEnum,char const __near *,struct _D3DXMACRO const __near *,char const __near *,struct CmdSink::IResponse __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InterceptFxc::Private::FastShaderCompile(
        InterceptFxc::ExecutableEnum nExecutable,
        const char *pszFilename,
        const _D3DXMACRO *pMacros,
        const char *pszModel,
        CmdSink::IResponse **ppResponse)
{
  HINSTANCE__ *LibraryA; // eax
  int (__stdcall *Proxy_D3DXCompileShaderFromFile)(); // eax
  int v7; // esi
  CmdSink::IResponse *v8; // eax
  ID3DXBuffer *v9; // ecx
  ID3DXBuffer *v10; // edx
  ID3DXBuffer *pErrorMessages; // [esp+Ch] [ebp-8h] BYREF
  ID3DXBuffer *pShader; // [esp+10h] [ebp-4h] BYREF

  pShader = nullptr;
  pErrorMessages = nullptr;
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    s_dxModule.m_hModule = nullptr;
    s_dxModule.m_arrFuncs[0] = nullptr;
    atexit(func: InterceptFxc::Private::FastShaderCompile_::_2_::_dynamic_atexit_destructor_for__s_dxModule__);
  }
  if ( s_dxModule.m_hModule != nullptr )
  {
    Proxy_D3DXCompileShaderFromFile = s_dxModule.m_arrFuncs[0];
  }
  else
  {
    LibraryA = LoadLibraryA(lpLibFileName: "dx_proxy.dll");
    s_dxModule.m_hModule = LibraryA;
    if ( LibraryA == nullptr
      || (Proxy_D3DXCompileShaderFromFile = GetProcAddress(
                                              hModule: LibraryA,
                                              lpProcName: "Proxy_D3DXCompileShaderFromFile"),
          s_dxModule.m_arrFuncs[0] = Proxy_D3DXCompileShaderFromFile,
          s_dxModule.m_hModule == nullptr) )
    {
      v7 = -2147221503;
      goto LABEL_11;
    }
  }
  if ( Proxy_D3DXCompileShaderFromFile != nullptr )
    v7 = ((int (__stdcall *)(const char *, const _D3DXMACRO *, _DWORD, const char *, const char *, _DWORD, ID3DXBuffer **, ID3DXBuffer **, _DWORD))Proxy_D3DXCompileShaderFromFile)(
           a1: pszFilename,
           a2: pMacros,
           a3: 0,
           a4: "main",
           a5: pszModel,
           a6: 0,
           a7: &pShader,
           a8: &pErrorMessages,
           a9: 0);
  else
    v7 = -2147221502;
LABEL_11:
  if ( ppResponse != nullptr )
  {
    v8 = (CmdSink::IResponse *)operator new(nSize: 0x10u);
    if ( v8 != nullptr )
    {
      v9 = pErrorMessages;
      v10 = pShader;
      v8[3].__vftable = (CmdSink::IResponse_vtbl *)v7;
      v8->__vftable = (CmdSink::IResponse_vtbl *)&InterceptFxc::Private::CResponse::`vftable';
      v8[1].__vftable = (CmdSink::IResponse_vtbl *)v10;
      v8[2].__vftable = (CmdSink::IResponse_vtbl *)v9;
      *ppResponse = v8;
    }
    else
    {
      *ppResponse = nullptr;
    }
  }
  else
  {
    if ( pShader != nullptr )
      pShader->Release(this: pShader);
    if ( pErrorMessages != nullptr )
      pErrorMessages->Release(this: pErrorMessages);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100086D0
// Name: void InterceptFxc::ExecuteCommand(enum InterceptFxc::ExecutableEnum,char const __near *,struct CmdSink::IResponse __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InterceptFxc::ExecuteCommand(
        InterceptFxc::ExecutableEnum nExecutable,
        char *pCommand,
        CmdSink::IResponse **ppResponse)
{
  void *v3; // esp
  char *v4; // ebx
  char *i; // esi
  int v6; // ecx
  char v7; // al
  const char *j; // esi
  int v9; // eax
  int v10; // eax
  char v11; // al
  char *v12; // esi
  char *v13; // edi
  const char *v14; // ebx
  _BYTE *v15; // eax
  _BYTE *v16; // eax
  int m_Size; // edi
  int v18; // eax
  unsigned __int64 *m_pMemory; // esi
  int v20; // eax
  char *v21; // ecx
  char v22[12]; // [esp+0h] [ebp-48h] BYREF
  char pDest; // [esp+Ch] [ebp-3Ch] BYREF
  __int64 v24; // [esp+Dh] [ebp-3Bh]
  __int64 v25; // [esp+15h] [ebp-33h]
  __int16 v26; // [esp+1Dh] [ebp-2Bh]
  char v27; // [esp+1Fh] [ebp-29h]
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > v28; // [esp+20h] [ebp-28h] BYREF
  unsigned __int64 src; // [esp+34h] [ebp-14h] BYREF
  char *v30; // [esp+3Ch] [ebp-Ch]
  char *pSrc; // [esp+40h] [ebp-8h]
  const char *v32; // [esp+44h] [ebp-4h]

  v3 = alloca(strlen(pCommand) + 1);
  v4 = v22;
  HIDWORD(src) = strcpy(v22, pCommand);
  memset(&v28, 0, sizeof(v28));
  pSrc = nullptr;
  for ( i = v22; ; i = (char *)v32 )
  {
    if ( isspace(c: *i) != 0 )
    {
      do
        v6 = *++i;
      while ( isspace(c: v6) != 0 );
    }
    v7 = *i;
    if ( *i == 0 )
      break;
    while ( v7 != 47 && v7 != 45 || i[1] != 68 )
    {
      v7 = *++i;
      if ( v7 == 0 )
        goto LABEL_9;
    }
    v12 = i + 2;
    if ( v12 == nullptr )
      break;
    v13 = v12;
    v30 = v12;
    v14 = setName;
    strchr(string: v12, chr: 0x3Du);
    if ( v15 != nullptr )
    {
      v14 = v15 + 1;
      *v15 = 0;
      v12 = v15 + 1;
    }
    strchr(string: v12, chr: 0x20u);
    if ( v16 != nullptr )
    {
      *v16 = 0;
      v32 = v16 + 1;
    }
    else
    {
      v32 = setName;
    }
    if ( strncmp(first: v13, last: "SHADER_MODEL_", count: 0xDu) == 0 )
      pSrc = v13 + 13;
    m_Size = v28.m_Size;
    v18 = v28.m_Size;
    if ( v28.m_Size + 1 > v28.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
        this: (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)&v28,
        num: v28.m_Size - v28.m_Memory.m_nAllocationCount + 1);
      v18 = v28.m_Size;
    }
    m_pMemory = v28.m_Memory.m_pMemory;
    v28.m_Size = v18 + 1;
    v20 = v18 - m_Size;
    v28.m_pElements = v28.m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v28.m_Memory.m_pMemory[m_Size + 1], src: &v28.m_Memory.m_pMemory[m_Size], count: 8 * v20);
    v21 = v30;
    HIDWORD(m_pMemory[m_Size]) = v14;
    v4 = (char *)HIDWORD(src);
    LODWORD(m_pMemory[m_Size]) = v21;
  }
LABEL_9:
  src = 0;
  CUtlVector<_D3DXMACRO,CUtlMemory<_D3DXMACRO,int>>::InsertBefore(this: &v28, elem: v28.m_Size, &src);
  pDest = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  if ( pSrc != nullptr )
    V_strncpy(&pDest, pSrc, maxLen: 19);
  _V_strlower(start: &pDest);
  j = setName;
  strstr(str1: (unsigned __int8 *)pCommand, str2: ">output.txt ");
  if ( v9 != 0 )
  {
    v10 = v9 - (_DWORD)pCommand;
    v4[v10] = 0;
    for ( j = &v4[v10]; j > v4; --j )
    {
      v11 = *(j - 1);
      if ( v11 == 0 )
        break;
      if ( v11 == 32 )
        break;
    }
  }
  InterceptFxc::Private::FastShaderCompile(
    nExecutable,
    pszFilename: j,
    pMacros: (const _D3DXMACRO *)v28.m_Memory.m_pMemory,
    pszModel: &pDest,
    ppResponse);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&v28);
}

//------------------------------------------------------------------------------
// Address: 0x100088E0
// Name: bool InterceptFxc::TryExecuteCommand(char const __near *,struct CmdSink::IResponse __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InterceptFxc::TryExecuteCommand(char *pCommand, CmdSink::IResponse **ppResponse)
{
  int v2; // eax
  unsigned __int8 *v3; // esi
  unsigned __int8 *i; // edi
  InterceptFxc::ExecutableEnum v5; // ebx
  unsigned __int8 *v6; // eax
  char *v8; // esi

  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    v2 = _CommandLine();
    s_bNoIntercept = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nointercept") != 0;
  }
  if ( s_bNoIntercept )
    return 0;
  v3 = (unsigned __int8 *)pCommand;
  if ( *pCommand != 0 )
  {
    do
    {
      if ( isspace(c: (char)*v3) == 0 )
        break;
      ++v3;
    }
    while ( *v3 != 0 );
  }
  for ( i = v3; *i != 0; ++i )
  {
    if ( isspace(c: (char)*i) != 0 )
      break;
  }
  v5 = EXEC_FXC;
  while ( 1 )
  {
    strstr(str1: v3, str2: (unsigned __int8 *)g_pExecutables[v5]);
    if ( v3 == v6 )
      break;
    if ( ++v5 >= EXEC_COUNT )
      return 0;
  }
  v8 = (char *)i;
  if ( *i != 0 )
  {
    do
    {
      if ( isspace(c: *v8) == 0 )
        break;
      ++v8;
    }
    while ( *v8 != 0 );
  }
  InterceptFxc::ExecuteCommand(nExecutable: v5, pCommand: v8, ppResponse);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100519D0
// Name: _InterceptFxc::Private::FastShaderCompile_::_2_::_dynamic_atexit_destructor_for__s_dxModule__
// Source: json
//------------------------------------------------------------------------------
void __cdecl InterceptFxc::Private::FastShaderCompile_::_2_::_dynamic_atexit_destructor_for__s_dxModule__()
{
  if ( s_dxModule.m_hModule != nullptr )
  {
    FreeLibrary(hLibModule: s_dxModule.m_hModule);
    s_dxModule.m_hModule = nullptr;
    s_dxModule.m_arrFuncs[0] = nullptr;
  }
}
