// Original: tier3/tier3.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "tier3\tier3.h"

// Stub: ConnectTier3Libraries
void ConnectTier3Libraries() {}

// Stub: DisconnectTier3Libraries
void DisconnectTier3Libraries() {}

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00418700
// Name: void ConnectTier3Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier3Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int i; // esi

  for ( i = 0; i < nFactoryCount; ++i )
  {
    if ( g_pStudioRender == nullptr )
    {
      studiorender = (IStudioRender *)pFactoryList[i](a1: "VStudioRender026", a2: nullptr);
      g_pStudioRender = studiorender;
    }
    if ( g_pVGui == nullptr )
      g_pVGui = (vgui::IVGui *)pFactoryList[i](a1: "VGUI_ivgui008", a2: nullptr);
    if ( g_pVGuiInput == nullptr )
      g_pVGuiInput = (vgui::IInput *)pFactoryList[i](a1: "VGUI_Input005", a2: nullptr);
    if ( g_pVGuiPanel == nullptr )
      g_pVGuiPanel = (vgui::IPanel *)pFactoryList[i](a1: "VGUI_Panel009", a2: nullptr);
    if ( g_pVGuiSurface == nullptr )
      g_pVGuiSurface = (vgui::ISurface *)pFactoryList[i](a1: "VGUI_Surface030", a2: nullptr);
    if ( g_pVGuiSchemeManager == nullptr )
      g_pVGuiSchemeManager = (vgui::ISchemeManager *)pFactoryList[i](a1: "VGUI_Scheme010", a2: nullptr);
    if ( g_pVGuiSystem == nullptr )
      g_pVGuiSystem = (vgui::ISystem *)pFactoryList[i](a1: "VGUI_System010", a2: nullptr);
    if ( g_pVGuiLocalize == nullptr )
      g_pVGuiLocalize = (vgui::ILocalize *)pFactoryList[i](a1: "VGUI_Localize005", a2: nullptr);
    if ( g_pMatSystemSurface == nullptr )
      g_pMatSystemSurface = (IMatSystemSurface *)pFactoryList[i](a1: "MatSystemSurface006", a2: nullptr);
    if ( g_pDataCache == nullptr )
      g_pDataCache = (IDataCache *)pFactoryList[i](a1: "VDataCache003", a2: nullptr);
    if ( g_pMDLCache == nullptr )
    {
      mdlcache = (IMDLCache *)pFactoryList[i](a1: "MDLCache004", a2: nullptr);
      g_pMDLCache = mdlcache;
    }
    if ( g_pAVI == nullptr )
      g_pAVI = (IAvi *)pFactoryList[i](a1: "VAvi001", a2: nullptr);
    if ( g_pBIK == nullptr )
      g_pBIK = (IBik *)pFactoryList[i](a1: "VBik001", a2: nullptr);
    if ( g_pDmeMakefileUtils == nullptr )
      g_pDmeMakefileUtils = (IDmeMakefileUtils *)pFactoryList[i](a1: "VDmeMakeFileUtils001", a2: nullptr);
    if ( g_pPhysicsCollision == nullptr )
      g_pPhysicsCollision = (IPhysicsCollision *)pFactoryList[i](a1: "VPhysicsCollision007", a2: nullptr);
    if ( g_pSoundEmitterSystem == nullptr )
      g_pSoundEmitterSystem = (ISoundEmitterSystemBase *)pFactoryList[i](a1: "VSoundEmitter003", a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418900
// Name: void DisconnectTier3Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier3Libraries()
{
  g_pStudioRender = nullptr;
  studiorender = nullptr;
  g_pVGui = nullptr;
  g_pVGuiInput = nullptr;
  g_pVGuiPanel = nullptr;
  g_pVGuiSurface = nullptr;
  g_pVGuiLocalize = nullptr;
  g_pVGuiSchemeManager = nullptr;
  g_pVGuiSystem = nullptr;
  g_pMatSystemSurface = nullptr;
  g_pDataCache = nullptr;
  g_pMDLCache = nullptr;
  mdlcache = nullptr;
  g_pAVI = nullptr;
  g_pBIK = nullptr;
  g_pPhysicsCollision = nullptr;
  g_pDmeMakefileUtils = nullptr;
  g_pSoundEmitterSystem = nullptr;
}

} // namespace choreogen

// ============================================================
// Overlay from mdlbuild (Missing functions)
// ============================================================
namespace mdlbuild {

//------------------------------------------------------------------------------
// Address: 0x00405900
// Name: void ConnectTier3Libraries(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectTier3Libraries(void *(__cdecl **pFactoryList)(const char *, int *), int nFactoryCount)
{
  int i; // esi

  for ( i = 0; i < nFactoryCount; ++i )
  {
    if ( g_pStudioRender == nullptr )
    {
      studiorender = (IStudioRender *)pFactoryList[i](a1: "VStudioRender025", a2: nullptr);
      g_pStudioRender = studiorender;
    }
    if ( g_pVGui == nullptr )
      g_pVGui = (vgui::IVGui *)pFactoryList[i](a1: "VGUI_ivgui008", a2: nullptr);
    if ( g_pVGuiInput == nullptr )
      g_pVGuiInput = (vgui::IInput *)pFactoryList[i](a1: "VGUI_Input005", a2: nullptr);
    if ( g_pVGuiPanel == nullptr )
      g_pVGuiPanel = (vgui::IPanel *)pFactoryList[i](a1: "VGUI_Panel009", a2: nullptr);
    if ( g_pVGuiSurface == nullptr )
      g_pVGuiSurface = (vgui::ISurface *)pFactoryList[i](a1: "VGUI_Surface030", a2: nullptr);
    if ( g_pVGuiSchemeManager == nullptr )
      g_pVGuiSchemeManager = (vgui::ISchemeManager *)pFactoryList[i](a1: "VGUI_Scheme010", a2: nullptr);
    if ( g_pVGuiSystem == nullptr )
      g_pVGuiSystem = (vgui::ISystem *)pFactoryList[i](a1: "VGUI_System010", a2: nullptr);
    if ( g_pVGuiLocalize == nullptr )
      g_pVGuiLocalize = (vgui::ILocalize *)pFactoryList[i](a1: "VGUI_Localize004", a2: nullptr);
    if ( g_pMatSystemSurface == nullptr )
      g_pMatSystemSurface = (IMatSystemSurface *)pFactoryList[i](a1: "MatSystemSurface006", a2: nullptr);
    if ( g_pDataCache == nullptr )
      g_pDataCache = (IDataCache *)pFactoryList[i](a1: "VDataCache003", a2: nullptr);
    if ( g_pMDLCache == nullptr )
    {
      mdlcache = (IMDLCache *)pFactoryList[i](a1: "MDLCache004", a2: nullptr);
      g_pMDLCache = mdlcache;
    }
    if ( g_pAVI == nullptr )
      g_pAVI = (IAvi *)pFactoryList[i](a1: "VAvi001", a2: nullptr);
    if ( g_pBIK == nullptr )
      g_pBIK = (IBik *)pFactoryList[i](a1: "VBik001", a2: nullptr);
    if ( g_pDmeMakefileUtils == nullptr )
      g_pDmeMakefileUtils = (IDmeMakefileUtils *)pFactoryList[i](a1: "VDmeMakeFileUtils001", a2: nullptr);
    if ( g_pPhysicsCollision == nullptr )
      g_pPhysicsCollision = (IPhysicsCollision *)pFactoryList[i](a1: "VPhysicsCollision007", a2: nullptr);
    if ( g_pSoundEmitterSystem == nullptr )
      g_pSoundEmitterSystem = (ISoundEmitterSystemBase *)pFactoryList[i](a1: "VSoundEmitter002", a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405B00
// Name: void DisconnectTier3Libraries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectTier3Libraries()
{
  g_pStudioRender = nullptr;
  studiorender = nullptr;
  g_pVGui = nullptr;
  g_pVGuiInput = nullptr;
  g_pVGuiPanel = nullptr;
  g_pVGuiSurface = nullptr;
  g_pVGuiLocalize = nullptr;
  g_pVGuiSchemeManager = nullptr;
  g_pVGuiSystem = nullptr;
  g_pMatSystemSurface = nullptr;
  g_pDataCache = nullptr;
  g_pMDLCache = nullptr;
  mdlcache = nullptr;
  g_pAVI = nullptr;
  g_pBIK = nullptr;
  g_pPhysicsCollision = nullptr;
  g_pDmeMakefileUtils = nullptr;
  g_pSoundEmitterSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405BE0
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:ByteCopyDown+4[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x100
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:CopyUnwindUp+4[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 00405C3C case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405F45
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl _getenv_helper_nolock(char *option)
{
  unsigned __int8 **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = (unsigned __int8 **)_environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr
    || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = (unsigned __int8 **)_environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: (unsigned __int8 *)option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4 && (*v1)[v4] == 61 && _mbsnbicoll(s1: *v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
          return (const char *)&(*v1)[v4 + 1];
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405FC6
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = (char *)_getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406049
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dupenv_s(char **pBuffer, unsigned int *pBufferSizeInTChars, char *varname)
{
  unsigned __int8 *v3; // eax
  int v4; // eax
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax
  char *_Src; // [esp+10h] [ebp-20h]
  int retval; // [esp+14h] [ebp-1Ch]

  _lock(locknum: 7);
  if ( pBuffer != nullptr )
  {
    *pBuffer = nullptr;
    if ( pBufferSizeInTChars != nullptr )
      *pBufferSizeInTChars = 0;
    if ( varname != nullptr )
    {
      v3 = (unsigned __int8 *)_getenv_helper_nolock(option: varname);
      _Src = (char *)v3;
      if ( v3 != nullptr )
      {
        strlen(buf: v3);
        v5 = v4 + 1;
        v6 = calloc(nCount: v4 + 1, nElementSize: 1u);
        *pBuffer = (char *)v6;
        if ( v6 == nullptr )
        {
          *_errno() = 12;
          retval = *_errno();
          goto LABEL_14;
        }
        if ( strcpy_s(_Dst: (char *)v6, _SizeInBytes: v5, _Src) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        if ( pBufferSizeInTChars != nullptr )
          *pBufferSizeInTChars = v5;
      }
      retval = 0;
      goto LABEL_14;
    }
  }
  *_errno() = 22;
  _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  retval = 22;
LABEL_14:
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0040612F
// Name: __fullpath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  DWORD v8; // eax
  char *pfname; // [esp+Ch] [ebp-8h] BYREF
  char *buf; // [esp+10h] [ebp-4h]

  if ( path == nullptr || *path == 0 )
    return _getcwd(pnbuf: UserBuf, maxlen);
  if ( UserBuf != nullptr )
  {
    v6 = maxlen;
    if ( maxlen == 0 )
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    buf = UserBuf;
  }
  else
  {
    FullPathNameA = GetFullPathNameA(lpFileName: path, nBufferLength: 0, lpBuffer: nullptr, lpFilePart: nullptr);
    if ( FullPathNameA == 0 )
    {
LABEL_5:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      return nullptr;
    }
    v6 = maxlen;
    if ( maxlen <= FullPathNameA )
      v6 = FullPathNameA;
    v7 = calloc(nCount: v6, nElementSize: 1u);
    buf = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      return nullptr;
    }
  }
  v8 = GetFullPathNameA(lpFileName: path, nBufferLength: v6, lpBuffer: buf, lpFilePart: &pfname);
  if ( v8 >= v6 )
  {
    if ( UserBuf == nullptr )
      free(pMem: buf);
    *_errno() = 34;
    return nullptr;
  }
  if ( v8 == 0 )
  {
    if ( UserBuf == nullptr )
      free(pMem: buf);
    goto LABEL_5;
  }
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x00406240
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _alloca_probe_16()
{
  return _chkstk();
}

//------------------------------------------------------------------------------
// Address: 0x004063E4
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406400
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x00406430
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x100 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004064AA
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  if ( format != nullptr )
  {
    if ( count == 0 || string != nullptr )
    {
      str._cnt = 0x7FFFFFFF;
      if ( count <= 0x7FFFFFFF )
        str._cnt = count;
      str._flag = 66;
      str._base = string;
      str._ptr = string;
      result = _output_l(stream: &str, format, plocinfo, argptr: ap);
      v6 = result;
      if ( string != nullptr )
      {
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr = 0;
        return v6;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040655B
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x00406576
// Name: fast_error_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn fast_error_exit(int rterrnum)
{
  if ( __error_mode != 2 )
    _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  __crtExitProcess(status: 255);
}

//------------------------------------------------------------------------------
// Address: 0x0040659A
// Name: check_managed_app
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl check_managed_app()
{
  return (_WORD)MEMORY[0x400000] == 23117
      && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
      && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267
      && *(_DWORD *)(MEMORY[0x40003C] + 4194420) > 0xEu
      && *(_DWORD *)(MEMORY[0x40003C] + 4194536) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004065DB
// Name: __tmainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tmainCRTStartup()
{
  HANDLE ProcessHeap; // eax
  _OSVERSIONINFOA *v1; // eax
  _OSVERSIONINFOA *v2; // esi
  HANDLE v4; // eax
  int v5; // edi
  HANDLE v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned int winminor; // [esp+14h] [ebp-28h]
  unsigned int winmajor; // [esp+18h] [ebp-24h]
  int managedapp; // [esp+1Ch] [ebp-20h]
  BOOL managedappa; // [esp+1Ch] [ebp-20h]
  int mainret; // [esp+20h] [ebp-1Ch]

  ProcessHeap = GetProcessHeap();
  v1 = (_OSVERSIONINFOA *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 0, dwBytes: 0x94u);
  v2 = v1;
  if ( v1 == nullptr )
    fast_error_exit(rterrnum: 18);
  v1->dwOSVersionInfoSize = 148;
  if ( GetVersionExA(lpVersionInformation: v1) )
  {
    managedapp = v2->dwPlatformId;
    winmajor = v2->dwMajorVersion;
    winminor = v2->dwMinorVersion;
    v5 = v2->dwBuildNumber & 0x7FFF;
    v6 = GetProcessHeap();
    HeapFree(hHeap: v6, dwFlags: 0, lpMem: v2);
    if ( managedapp != 2 )
      v5 |= 0x8000u;
    _osplatform = managedapp;
    _winver = winminor + (winmajor << 8);
    _winmajor = winmajor;
    _winminor = winminor;
    _osver = v5;
    managedappa = check_managed_app();
    if ( !_heap_init() )
      fast_error_exit(rterrnum: 28);
    if ( _mtinit() == 0 )
      fast_error_exit(rterrnum: 16);
    _RTC_Initialize();
    if ( _ioinit() < 0 )
      _amsg_exit(rterrnum: 27);
    _acmdln = GetCommandLineA();
    _aenvptr = (char *)__crtGetEnvironmentStringsA();
    if ( _setargv() < 0 )
      _amsg_exit(rterrnum: 8);
    if ( _setenvp() < 0 )
      _amsg_exit(rterrnum: 9);
    v7 = _cinit(initFloatingPrecision: 1);
    if ( v7 != 0 )
      _amsg_exit(rterrnum: v7);
    __initenv = _environ;
    v8 = main(argc: __argc, argv: (const char **)__argv, envp: (const char **)_environ);
    mainret = v8;
    if ( !managedappa )
      exit(code: v8);
    _cexit();
    return mainret;
  }
  else
  {
    v4 = GetProcessHeap();
    HeapFree(hHeap: v4, dwFlags: 0, lpMem: v2);
    return 255;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406791
// Name: _mainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mainCRTStartup()
{
  __security_init_cookie();
  return _tmainCRTStartup();
}

//------------------------------------------------------------------------------
// Address: 0x0040679B
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: &v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: &v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040684A
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x00406860
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:ByteCopyDown_0+4[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x100
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:CopyUnwindUp_0+4[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 004068BC case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406BD0
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x407286);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406C56
// Name: _putenv_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl putenv_helper(char *name, const char *value)
{
  const CHAR *v3; // ebx
  const unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned int v6; // edi
  char *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  char *v11; // eax
  int v12; // ebx
  int v13; // eax
  unsigned __int16 *v14; // eax
  unsigned int v15; // eax
  char *newoption; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 *woption; // [esp+8h] [ebp-4h] BYREF

  newoption = nullptr;
  if ( __env_initialized == 0 )
    return -1;
  v3 = name;
  if ( name == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  if ( value != nullptr )
  {
    v8 = strnlen(str: name, maxsize: 0x7FFFu);
    v9 = strnlen(str: value, maxsize: 0x7FFFu);
    if ( v8 < 0x7FFF && v9 < 0x7FFF )
    {
      v10 = v9 + v8 + 2;
      v11 = (char *)_calloc_crt(count: v10, size: 1u);
      newoption = v11;
      if ( v11 != nullptr )
      {
        strcpy_s(_Dst: v11, _SizeInBytes: v10, _Src: name);
        newoption[v8] = 61;
        strcpy_s(_Dst: &newoption[v8 + 1], _SizeInBytes: v10 - (v8 + 1), _Src: value);
        v3 = name;
        goto LABEL_16;
      }
      return -1;
    }
LABEL_13:
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  v4 = _mbschr(string: (const unsigned __int8 *)name, c: 0x3Du);
  if ( v4 != nullptr
    && (v4 - (const unsigned __int8 *)name >= 0x7FFF || strnlen(str: (const char *)v4 + 1, maxsize: 0x7FFFu) >= 0x7FFF) )
  {
    goto LABEL_13;
  }
  strlen(buf: (unsigned __int8 *)name);
  v6 = v5 + 1;
  v7 = (char *)_calloc_crt(count: v5 + 1, size: 1u);
  newoption = v7;
  if ( v7 == nullptr )
    return -1;
  strcpy_s(_Dst: v7, _SizeInBytes: v6, _Src: name);
LABEL_16:
  if ( __crtsetenv(poption: &newoption, primary: 1) != 0 )
  {
    if ( newoption != nullptr )
      free(pMem: newoption);
    return -1;
  }
  if ( _wenviron == nullptr )
    return 0;
  woption = nullptr;
  v12 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v3,
          cbMultiByte: -1,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  if ( v12 == 0 )
    goto LABEL_29;
  if ( value != nullptr )
  {
    v13 = MultiByteToWideChar(
            CodePage: 0,
            dwFlags: 0,
            lpMultiByteStr: value,
            cbMultiByte: -1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    if ( v13 == 0 )
    {
LABEL_29:
      *_errno() = 42;
      return -1;
    }
    v12 += v13 + 1;
  }
  v14 = (unsigned __int16 *)_calloc_crt(count: v12, size: 2u);
  woption = v14;
  if ( v14 == nullptr )
    return -1;
  if ( MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: name,
         cbMultiByte: -1,
         lpWideCharStr: v14,
         cchWideChar: v12) == 0
    || value != nullptr
    && (v15 = wcslen(wcs: woption),
        woption[v15] = 61,
        MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: value,
          cbMultiByte: -1,
          lpWideCharStr: &woption[v15 + 1],
          cchWideChar: v12 - (v15 + 1)) == 0) )
  {
    free(pMem: woption);
    goto LABEL_29;
  }
  if ( __crtwsetenv(poption: &woption, primary: 0) != 0 )
  {
    if ( woption != nullptr )
      free(pMem: woption);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406E65
// Name: __putenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _putenv(char *option)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = putenv_helper(name: option, value: nullptr);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00406EB0
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x00406EDB
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax

  result = true;
  if ( drive != 0 )
  {
    LOBYTE(drive) = drive + 64;
    strcpy((char *)&drive + 1, ":\\");
    if ( GetDriveTypeA(lpRootPathName: (LPCSTR)&drive) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406F12
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  int v4; // eax
  char *v5; // edi
  signed int FullPathNameA; // eax
  unsigned __int8 *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  char drvstr[4]; // [esp+8h] [ebp-4h] BYREF
  signed int count; // [esp+14h] [ebp+8h]

  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    v4 = drive;
  }
  else
  {
    v4 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v4 != 0 )
  {
    drvstr[0] = v4 + 64;
    strcpy(&drvstr[1], ":.");
  }
  else
  {
    strcpy(drvstr, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: drvstr, nBufferLength: count, lpBuffer: pnbuf, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_25;
  if ( pnbuf == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = calloc(nCount: maxlen, nElementSize: 1u);
    v5 = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: drvstr, nBufferLength: maxlen, lpBuffer: (LPSTR)v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_25:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *pnbuf = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00407047
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00407090
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407117
// Name: __access
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access(const char *path, int amode)
{
  return -(_access_s(path, amode) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040712B
// Name: __spawnv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnv(int modeflag, const char *pathname, const char *const *argv)
{
  if ( pathname != nullptr && *pathname != 0 && argv != nullptr && *argv != nullptr && **(_BYTE **)argv != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040717A
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // ebx
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004071EC
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407280
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop;
    }
  }
  else
  {
    do
    {
main_loop:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040733E
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004073C0
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = (unsigned __int8)outbuffer[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = outbuffer[0];
        result = (unsigned __int8)outbuffer[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_18:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x004074D7
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407500
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance;
tail_loop_start:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start;
  while ( 1 )
  {
main_loop_entrance:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x00407640
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance_0;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start_0:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance_0:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start_0;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x00407770
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00407779
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x0040778C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004077A6
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407820
// Name: __allrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allrem(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // eax
  int v9; // ecx
  bool v10; // cf
  unsigned __int64 v11; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 == 0 )
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    result = v4 % (unsigned int)a2;
    if ( v2 - 1 < 0 )
      return result;
    return -(__int64)result;
  }
  v6 = __PAIR64__(v3, a2);
  v7 = a1;
  do
  {
    v6 >>= 1;
    v7 >>= 1;
  }
  while ( HIDWORD(v6) != 0 );
  v8 = v7 / (unsigned int)v6;
  v9 = HIDWORD(a2) * v8;
  v11 = (unsigned int)a2 * (unsigned __int64)v8;
  v10 = __CFADD__(v9, HIDWORD(v11));
  HIDWORD(v11) += v9;
  if ( v10 || v11 > a1 )
    v11 -= a2;
  result = v11 - a1;
  if ( v2 - 1 < 0 )
    return -(__int64)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004078E0
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040798A
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004079D9
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00407A02
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407A51
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x00407A7A
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // esi
  int v5; // eax
  int v6; // eax
  _flt *v7; // eax
  _flt *v8; // ecx
  int flags; // eax
  long double v10; // st7
  _flt answerstruct; // [esp+Ch] [ebp-30h] BYREF
  _LocaleUpdate _loc_update; // [esp+24h] [ebp-18h] BYREF
  long double tmp; // [esp+34h] [ebp-8h]

  v3 = (unsigned __int8 *)nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*v3] & 8
       : _isctype_l(c: *v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  strlen(buf: v3);
  v7 = _fltin2(
         flt: &answerstruct,
         str: (const char *)v3,
         len_ignore: v6,
         scale_ignore: 0,
         radix_ignore: 0,
         _Locale: &_loc_update.localeinfo);
  v8 = v7;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v7->nbytes];
  flags = v7->flags;
  if ( (v8->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v10 = *(double *)&_HUGE;
    if ( *v3 == 45 )
      v10 = -*(double *)&_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v10 = 0.0, 0.0 != v8->dval) )
  {
    tmp = v8->dval;
    goto LABEL_24;
  }
  tmp = v10;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x00407B95
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00407BA8
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  char v7; // bl
  const char *i; // edi
  int v9; // eax
  _BYTE *v10; // edi
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // eax
  unsigned __int16 v13; // cx
  unsigned int v14; // ecx
  int v15; // ecx
  const char *v16; // edi
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-14h] BYREF
  unsigned int number; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  number = 0;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[(unsigned __int8)v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: (unsigned __int8)v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v10 = i + 1;
    v7 = *v10;
    i = v10 + 1;
  }
LABEL_32:
  pctype = locinfo->pctype;
  v12 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v13 = pctype[(unsigned __int8)v7];
    if ( (v13 & 4) != 0 )
    {
      v14 = v7 - 48;
    }
    else
    {
      if ( (v13 & 0x103) == 0 )
        break;
      v15 = v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v15 = v7 - 32;
      v14 = v15 - 55;
    }
    if ( v14 >= ibase )
      break;
    flags |= 8u;
    if ( number < v12 || number == v12 && v14 <= 0xFFFFFFFF % ibase )
    {
      number = v14 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v16 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v16 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v16;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x00407DD3
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00407DFC
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00407E26
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x00407E40
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x00407E74
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x00407EE5
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x00407F65
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00407F7B
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407FBB
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00407FD2
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: (unsigned __int8 *)s);
    memmove(dst: (unsigned __int8 *)&s[dist], src: (unsigned __int8 *)s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407FEF
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00407FFD
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040800B
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v9; // edi
  int v11; // eax
  char *v12; // esi
  char *v13; // esi
  unsigned int v14; // ebx
  unsigned __int8 *v15; // ecx
  _BYTE *v16; // esi
  int v17; // eax
  _BYTE *v18; // esi
  _BYTE *v19; // esi
  int v20; // [esp-4h] [ebp-20h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v20 = 22;
LABEL_3:
    v9 = v20;
    *v8 = v20;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v9;
  }
  if ( ndec <= 0 )
    v11 = 0;
  else
    v11 = ndec;
  if ( sizeInBytes <= v11 + 9 )
  {
    v8 = _errno();
    v20 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v12 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v12 = buf + 1;
  }
  if ( ndec > 0 )
  {
    *v12 = v12[1];
    *++v12 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  }
  v13 = &v12[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v14 = -1;
  else
    v14 = sizeInBytes + buf - v13;
  if ( strcpy_s(_Dst: v13, _SizeInBytes: v14, _Src: "e+000") != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  v15 = (unsigned __int8 *)(v13 + 2);
  if ( caps != 0 )
    *v13 = 69;
  v16 = v13 + 1;
  if ( *pflt->mantissa != 48 )
  {
    v17 = pflt->decpt - 1;
    if ( v17 < 0 )
    {
      v17 = 1 - pflt->decpt;
      *v16 = 45;
    }
    v18 = v16 + 1;
    if ( v17 >= 100 )
    {
      *v18 += v17 / 100;
      v17 %= 100;
    }
    v19 = v18 + 1;
    if ( v17 >= 10 )
    {
      *v19 += v17 / 10;
      LOBYTE(v17) = v17 % 10;
    }
    v19[1] += v17;
  }
  if ( (_outputformat & 1) != 0 && *v15 == 48 )
    memmove(dst: v15, src: v15 + 1, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408178
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( sizeInBytes == -1 )
      v7 = -1;
    else
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408246
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00408264
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoa_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v6; // esi
  int *v7; // eax
  int v8; // esi
  int result; // eax
  unsigned int v10; // eax
  bool v11; // zf
  _BYTE *v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  char *v16; // esi
  char *v17; // eax
  char *v18; // esi
  int x_low; // eax
  unsigned __int16 v20; // ax
  unsigned int v21; // ecx
  char *i; // eax
  _BYTE *v23; // esi
  __int64 v24; // rax
  __int64 v25; // rcx
  _BYTE *v26; // esi
  _BYTE *v27; // edi
  __int64 v28; // rax
  __int64 v29; // rcx
  __int64 v30; // rax
  __int64 v31; // rcx
  __int64 v32; // rcx
  __int64 v33; // [esp-Ch] [ebp-38h]
  int v34; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v6 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = _errno();
    v34 = 22;
LABEL_5:
    v8 = v34;
    *v7 = v34;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v8;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v7 = _errno();
    v34 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v10 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v10 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v10, ndec, caps: 0);
    if ( result != 0 )
    {
      v11 = !_loc_update.updated;
      *buf = 0;
      if ( !v11 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v12 = v6 + 1;
    *v12 = caps == 0 ? 120 : 88;
    strrchr(string: v12 + 1, chr: 0x65u);
    if ( v13 != nullptr )
    {
      *v13 = caps == 0 ? 112 : 80;
      v13[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v14 = v6 + 1;
    *v14 = caps == 0 ? 120 : 88;
    v15 = v14 + 1;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      *v15 = 49;
      v16 = v15 + 1;
    }
    else
    {
      *v15 = 48;
      v16 = v15 + 1;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v17 = v16;
    v18 = v16 + 1;
    pos = v17;
    if ( ndec != 0 )
      *v17 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v17 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v20 = ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        if ( v20 > 0x39u )
          LOBYTE(v20) = (caps != 0 ? 7 : 39) + v20;
        v21 = HIDWORD(mask);
        maskpos -= 4;
        *v18++ = v20;
        --ndec;
        mask = __PAIR64__(v21, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v18 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: (int)v18, value: (unsigned __int8 *)0x30, count: ndec);
      v18 += ndec;
    }
    if ( *pos == 0 )
      v18 = pos;
    *v18 = caps == 0 ? 112 : 80;
    v23 = v18 + 1;
    HIDWORD(v25) = 0;
    v24 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v24 < 0 )
    {
      *v23 = 45;
      v26 = v23 + 1;
      v24 = -v24;
    }
    else
    {
      *v23 = 43;
      v26 = v23 + 1;
    }
    v27 = v26;
    *v26 = 48;
    if ( v24 >= 0 )
    {
      LODWORD(v25) = 1000;
      if ( v24 >= 1000 )
      {
        v33 = v25;
        v29 = v24 % v25;
        v28 = v24 / v33;
        *v26++ = v28 + 48;
        HIDWORD(exponent) = HIDWORD(v28);
        v24 = v29;
        if ( v26 != v27 )
          goto LABEL_60;
      }
    }
    if ( v24 >= 100 )
    {
LABEL_60:
      v31 = v24 % 100;
      v30 = v24 / 100;
      *v26 = v30 + 48;
      HIDWORD(exponent) = HIDWORD(v30);
      ++v26;
      v24 = v31;
    }
    if ( v26 != v27 || v24 >= 10 )
    {
      v32 = v24 % 10;
      *v26++ = v24 / 10 + 48;
      LOBYTE(v24) = v24 % 10;
      HIDWORD(exponent) = HIDWORD(v32);
    }
    *v26 = v24 + 48;
    v26[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004085D5
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // eax
  char *v11; // esi
  int decpt; // eax
  char *v13; // esi
  int v14; // ebx
  char *v15; // esi
  int v16; // ebx
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
    {
      v10 = &buf[v8 + (pflt->sign == 45)];
      *v10 = 48;
      v10[1] = 0;
    }
    v11 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v11 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = &v11[decpt];
    }
    else
    {
      shift(s: v11, dist: 1);
      *v11 = 48;
      v13 = v11 + 1;
    }
    if ( ndec > 0 )
    {
      shift(s: v13, dist: 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v14 = pflt->decpt;
      v15 = v13 + 1;
      if ( v14 < 0 )
      {
        v16 = -v14;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: v15, dist: ndec);
        memset(dst: (int)v15, value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004086CA
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v6 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408783
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  BOOL v8; // eax
  char *v9; // edi
  _strflt retstrflt; // [esp+Ch] [ebp-30h] BYREF
  int g_magnitude; // [esp+1Ch] [ebp-20h]
  char resstr[24]; // [esp+20h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    g_magnitude = retstrflt.decpt - 1;
    v8 = retstrflt.sign == 45;
    v9 = &buf[v8];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v8;
    result = _fptostr(buf: v9, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( g_magnitude < retstrflt.decpt - 1 )
        v9[strlen(v9) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408941
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _setdefaultprecision()
{
  int result; // eax

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040896A
// Name: __ms_p5_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ms_p5_test_fdiv()
{
  return 4195835.0 - 4195835.0 / 3145727.0 * 3145727.0 > 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004089A6
// Name: __ms_p5_mp_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ms_p5_mp_test_fdiv()
{
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *IsProcessorFeaturePresent)(DWORD); // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32");
  if ( ModuleHandleA != nullptr
    && (IsProcessorFeaturePresent = (BOOL (__stdcall *)(DWORD))GetProcAddress(
                                                                 hModule: ModuleHandleA,
                                                                 lpProcName: "IsProcessorFeaturePresent")) != nullptr )
  {
    return IsProcessorFeaturePresent(ProcessorFeature: 0);
  }
  else
  {
    return _ms_p5_test_fdiv();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004089CF
// Name: fastcopy_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastcopy_I(__m128i *dst, const __m128i *src, unsigned int len)
{
  unsigned int v5; // ecx
  __m128i si128; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm3
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  __m128i v11; // xmm7

  v5 = len >> 7;
  do
  {
    si128 = _mm_load_si128(src + 1);
    v7 = _mm_load_si128(src + 2);
    v8 = _mm_load_si128(src + 3);
    *dst = _mm_load_si128(src);
    dst[1] = si128;
    dst[2] = v7;
    dst[3] = v8;
    v9 = _mm_load_si128(src + 5);
    v10 = _mm_load_si128(src + 6);
    v11 = _mm_load_si128(src + 7);
    dst[4] = _mm_load_si128(src + 4);
    dst[5] = v9;
    dst[6] = v10;
    dst[7] = v11;
    src += 8;
    dst += 8;
    --v5;
  }
  while ( v5 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00408A56
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__m128i *__cdecl _VEC_memcpy(__m128i *dst, const __m128i *src, unsigned int len)
{
  int v3; // ecx
  __m128i *result; // eax
  int v5; // ecx
  unsigned int v6; // [esp+4h] [ebp-18h]

  v3 = (int)src % 16;
  result = dst;
  if ( (((int)dst % 16) | ((int)src % 16)) != 0 )
  {
    if ( v3 == (int)dst % 16 )
    {
      qmemcpy(dst, src, 16 - v3);
      _VEC_memcpy(dst: &dst->m128i_i8[16 - v3], src: &src->m128i_i8[16 - v3], len: len - (16 - v3));
    }
    else
    {
      qmemcpy(dst, src, len);
    }
    return dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastcopy_I(dst, src, len: len - v5);
      result = dst;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      qmemcpy(&result->m128i_i8[len - v5], &src->m128i_i8[len - v5], v6);
      return dst;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408B39
// Name: __sse2_mathfcns_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sse2_mathfcns_init()
{
  __use_sse2_mathfcns = 0;
  __use_sse2_mathfcns = _get_sse2_info();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408B4D
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(
        void (__cdecl *enull)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x00408B57
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(
        unsigned int a1@<eax>,
        unsigned int a2@<edx>,
        unsigned int a3@<ecx>,
        unsigned int a4@<ebx>,
        unsigned int a5@<edi>,
        unsigned int a6@<esi>)
{
  unsigned int v6; // kr00_4
  BOOL v7; // esi
  HANDLE CurrentProcess; // eax
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-80h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-30h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-28h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  ContextRecord.Eax = a1;
  ContextRecord.Ecx = a3;
  ContextRecord.Edx = a2;
  ContextRecord.Ebx = a4;
  ContextRecord.Esi = a6;
  ContextRecord.Edi = a5;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  ContextRecord.EFlags = v6;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  memset(dst: (int)&ExceptionRecord, value: nullptr, count: sizeof(ExceptionRecord));
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionRecord.ExceptionCode = -1073741811;
  ExceptionRecord.ExceptionAddress = retaddr;
  ExceptionPointers.ContextRecord = &ContextRecord;
  v7 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v7 )
    _crt_debugger_hook(_Reserved: 2);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC000000D);
}

//------------------------------------------------------------------------------
// Address: 0x00408C53
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int a3@<esi>)
{
  void (*v3)(void); // eax
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // [esp-4h] [ebp-4h]

  v3 = (void (*)(void))_decode_pointer(codedptr: __pInvalidArgHandler);
  if ( v3 == nullptr )
  {
    _crt_debugger_hook(_Reserved: 2);
    _invoke_watson(a1: v4, a2: v5, a3: v6, a4: a1, a5: a2, a6: a3);
  }
  v3();
}

//------------------------------------------------------------------------------
// Address: 0x00408C77
// Name: __mbsnbicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbicoll_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  int v7; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( s1 != nullptr && s2 != nullptr )
  {
    if ( n > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: 0x7FFFFFFFu);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      v7 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: _loc_update.localeinfo.mbcinfo->mblcid,
             dwCmpFlags: 0x1001u,
             lpString1: (const char *)s1,
             cchCount1: n,
             lpString2: (const char *)s2,
             cchCount2: n,
             code_page: _loc_update.localeinfo.mbcinfo->mbcodepage);
      if ( v7 == 0 )
        goto LABEL_15;
      result = v7 - 2;
    }
    else
    {
      result = _strnicoll_l(_string1: (const char *)s1, _string2: (const char *)s2, count: n, plocinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408D63
// Name: __mbsnbicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbicoll@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n)
{
  return _mbsnbicoll_l(a1, a2, s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00408D80
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_2;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_2:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408E0B
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const WCHAR *v1; // eax
  unsigned int v2; // eax
  char *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  char *envp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCWCH *)_wenviron;
  envp = nullptr;
  v1 = *_wenviron;
  if ( *_wenviron == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: v1,
           cchWideChar: -1,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    size = v2;
    if ( v2 == 0 )
      break;
    v3 = (char *)_calloc_crt(count: v2, size: 1u);
    envp = v3;
    if ( v3 == nullptr )
      break;
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: *v0,
           cchWideChar: -1,
           lpMultiByteStr: v3,
           cbMultiByte: size,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(pMem: envp);
      return -1;
    }
    if ( __crtsetenv(poption: &envp, primary: 0) < 0 && envp != nullptr )
    {
      free(pMem: envp);
      envp = nullptr;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00408EA0
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _amsg_exit(int rterrnum)
{
  void (__cdecl *v1)(int); // eax

  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  v1 = (void (__cdecl *)(int))_decode_pointer(codedptr: _aexit_rtn);
  v1(a1: 255);
}

//------------------------------------------------------------------------------
// Address: 0x00408EC4
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleA; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: "mscoree.dll");
  if ( ModuleHandleA != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleA, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408EEA
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x00408EFF
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x00408F08
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x00408F11
// Name: _initterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall initterm(void (__cdecl **pfbegin)()@<eax>, void (__cdecl **pfend)())
{
  while ( pfbegin < pfend )
  {
    if ( *pfbegin != nullptr )
      (*pfbegin)();
    ++pfbegin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408F29
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408F49
// Name: __get_osplatform
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_osplatform@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int *pValue)
{
  if ( pValue != nullptr && _osplatform != 0 )
  {
    *pValue = _osplatform;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408F80
// Name: __get_winmajor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_winmajor@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int *pValue)
{
  if ( pValue != nullptr && _osplatform != 0 )
  {
    *pValue = _winmajor;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408FBC
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // esi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) != 0 )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040904E
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  void **v3; // esi
  void *v4; // edi
  void (*v5)(void); // eax
  void (__cdecl **onexitbegin)(); // [esp+14h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      onexitbegin = (void (__cdecl **)())_decode_pointer(codedptr: __onexitbegin);
      v3 = (void **)_decode_pointer(codedptr: __onexitend);
      if ( onexitbegin != nullptr )
      {
        while ( --v3 >= (void **)onexitbegin )
        {
          if ( *v3 != nullptr )
          {
            v4 = *v3;
            if ( v4 != _encoded_null() )
            {
              v5 = (void (*)(void))_decode_pointer(codedptr: v4);
              v5();
            }
          }
        }
      }
      initterm(pfbegin: __xp_a, pfend: __xp_z);
    }
    initterm(pfbegin: __xt_a, pfend: __xt_z);
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409130
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00409141
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00409152
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00409161
// Name: __c_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _c_exit()
{
  doexit(code: 0, quick: 1, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00409170
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *_init_pointers())(int)
{
  void *v0; // esi
  void (__cdecl *result)(int); // eax

  v0 = _encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_initcrit(enull: v0);
  _initp_misc_invarg(enull: (void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_misc_winxfltr(enull: v0);
  _initp_eh_hooks(enull: v0);
  result = (void (__cdecl *)(int))_encode_pointer(ptr: _exit);
  _aexit_rtn = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004091BC
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strcpy_s@<eax>(unsigned int a1@<edi>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // al

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(a1: 0, a2: a1, a3: v4);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --a1;
  }
  while ( a1 != 0 );
  if ( a1 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409221
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x0040925C
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x0040926F
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x00409282
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x004092A0
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      *(&locktable + 2 * v0) = v1++;
      if ( __crtInitCritSecAndSpinCount(lpCriticalSection: *(&locktable + 2 * v0), dwSpinCount: 0xFA0u) == 0 )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004092E9
// Name: __mtdeletelocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &locktable;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(lpCriticalSection: *v0);
      free(pMem: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)&bad_alloc_Message_0 );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)&bad_alloc_Message_0 );
}

//------------------------------------------------------------------------------
// Address: 0x0040933E
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x00409353
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  if ( *(&locktable + 2 * locknum) != nullptr )
    return 1;
  v2 = (_RTL_CRITICAL_SECTION *)_malloc_crt(size: 0x18u);
  if ( v2 != nullptr )
  {
    _lock(locknum: 10);
    if ( *(&locktable + 2 * locknum) != nullptr )
    {
      free(pMem: v2);
    }
    else if ( __crtInitCritSecAndSpinCount(lpCriticalSection: v2, dwSpinCount: 0xFA0u) != 0 )
    {
      *(&locktable + 2 * locknum) = v2;
    }
    else
    {
      free(pMem: v2);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(locknum: 10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409416
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  if ( *(&locktable + 2 * locknum) == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x00409447
// Name: _strnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strnlen(const char *str, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++str )
  {
    if ( *str == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004094A9
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x004096D0
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00409758
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  unsigned int v0; // esi
  void (__cdecl *sigabrt)(int); // eax
  unsigned int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // kr00_4
  unsigned int v5; // [esp-4h] [ebp-88h]
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-80h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-30h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-28h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  if ( (__abort_behavior & 1) != 0 )
    _NMSG_WRITE(rterrnum: 10);
  sigabrt = __get_sigabrt();
  if ( sigabrt != nullptr )
  {
    sigabrt = (void (__cdecl *)(int))raise(signum: 22);
    v3 = v5;
  }
  if ( (__abort_behavior & 2) != 0 )
  {
    ContextRecord.Eax = (unsigned int)sigabrt;
    ContextRecord.Ecx = v3;
    ContextRecord.Edx = v2;
    ContextRecord.Esi = v0;
    LOWORD(ContextRecord.SegSs) = __SS__;
    LOWORD(ContextRecord.SegCs) = __CS__;
    LOWORD(ContextRecord.SegDs) = __DS__;
    LOWORD(ContextRecord.SegEs) = __ES__;
    LOWORD(ContextRecord.SegFs) = __FS__;
    LOWORD(ContextRecord.SegGs) = __GS__;
    v4 = __readeflags();
    ContextRecord.EFlags = v4;
    ContextRecord.Esp = (unsigned int)&retaddr;
    ContextRecord.ContextFlags = 65537;
    ContextRecord.Eip = (unsigned int)retaddr;
    ContextRecord.Ebp = savedregs;
    memset(dst: (int)&ExceptionRecord, value: nullptr, count: sizeof(ExceptionRecord));
    ExceptionPointers.ExceptionRecord = &ExceptionRecord;
    ExceptionRecord.ExceptionCode = 1073741845;
    ExceptionRecord.ExceptionAddress = retaddr;
    ExceptionPointers.ContextRecord = &ContextRecord;
    SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
    UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers);
  }
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x0040984B
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409869
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  unsigned int i; // edi
  unsigned int v2; // eax
  unsigned int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  HANDLE StdHandle; // eax
  void *v19; // ebp
  DWORD v20; // eax
  unsigned int NumberOfBytesWritten; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < 0x17; ++i )
  {
    if ( rterrnum == rterrs[i].rterrno )
      break;
  }
  if ( i < 0x17 )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v19 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        strlen(buf: rterrs[i].rterrtxt);
        WriteFile(
          hFile: v19,
          lpBuffer: rterrs[i].rterrtxt,
          nNumberOfBytesToWrite: v20,
          lpNumberOfBytesWritten: &NumberOfBytesWritten,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      v2 = strcpy_s(a1: i, _Dst: outmsg, _SizeInBytes: 0x314u, _Src: "Runtime Error!\n\nProgram: ");
      if ( v2 != 0 )
        _invoke_watson(a1: v2, a2: v3, a3: v4, a4: 0x314u, a5: i, a6: 0);
      outmsg[285] = 0;
      if ( GetModuleFileNameA(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0
        && strcpy_s(a1: i, _Dst: &outmsg[25], _SizeInBytes: 0x2FBu, _Src: "<program name unknown>") != 0 )
      {
        _invoke_watson(a1: 0, a2: v5, a3: v6, a4: 0x314u, a5: i, a6: (unsigned int)&outmsg[25]);
      }
      strlen(buf: &outmsg[25]);
      if ( (unsigned int)(v7 + 1) > 0x3C )
      {
        strlen(buf: &outmsg[25]);
        v9 = strncpy_s(
               _Dst: &outmsg[v8 - 34],
               _SizeInBytes: (char *)&gpFlsAlloc - &outmsg[v8 - 34],
               _Src: "...",
               _Count: 3u);
        if ( v9 != 0 )
          _invoke_watson(a1: v9, a2: v10, a3: v11, a4: 0x314u, a5: i, a6: 0);
      }
      v12 = strcat_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: "\n\n");
      if ( v12 != 0 )
        _invoke_watson(a1: v12, a2: v13, a3: v14, a4: 0x314u, a5: i, a6: 0);
      v15 = strcat_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: rterrs[i].rterrtxt);
      if ( v15 != 0 )
        _invoke_watson(a1: v15, a2: v16, a3: v17, a4: 0x314u, a5: i, a6: 0);
      __crtMessageBoxA(lpText: outmsg, lpCaption: "Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409A09
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409A42
// Name: _use_encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall use_encode_pointer@<eax>(unsigned int a1@<edi>)
{
  unsigned int v1; // ebx
  HMODULE ModuleHandleA; // eax
  char *v4; // esi
  unsigned __int8 *v5; // edi
  int v6; // eax
  int bEncode; // [esp+8h] [ebp-8h]
  int winmajor; // [esp+Ch] [ebp-4h] BYREF

  v1 = 0;
  bEncode = 1;
  winmajor = 0;
  _get_winmajor(a1: 0, a2: a1, pValue: (unsigned int *)&winmajor);
  if ( winmajor > 5 )
    return 1;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v4 = (char *)ModuleHandleA + *((_DWORD *)ModuleHandleA + 15);
  v5 = (unsigned __int8 *)&v4[*((unsigned __int16 *)v4 + 10) + 24];
  if ( *((_WORD *)v4 + 3) != 0 )
  {
    while ( 1 )
    {
      strcmp(str1: ".mixcrt", str2: v5);
      if ( v6 == 0 )
        break;
      ++v1;
      v5 += 40;
      if ( v1 >= *((unsigned __int16 *)v4 + 3) )
        return bEncode;
    }
    return 0;
  }
  return bEncode;
}

//------------------------------------------------------------------------------
// Address: 0x00409AAE
// Name: __encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __usercall _encode_pointer@<eax>(unsigned int a1@<edi>, void *ptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v3; // eax
  PVOID (__stdcall *EncodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  unsigned int v7; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr
    && __flsindex != -1
    && (v7 = __flsindex,
        Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex),
        (v3 = Value(a1: v7)) != 0) )
  {
    EncodePointer = *(PVOID (__stdcall **)(PVOID))(v3 + 504);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || use_encode_pointer(a1) == 0 )
      return ptr;
    EncodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "EncodePointer");
  }
  if ( EncodePointer != nullptr )
    return EncodePointer(Ptr: ptr);
  return ptr;
}

//------------------------------------------------------------------------------
// Address: 0x00409B1C
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __usercall _encoded_null@<eax>(unsigned int a1@<edi>)
{
  return _encode_pointer(a1, ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00409B25
// Name: __decode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __usercall _decode_pointer@<eax>(unsigned int a1@<edi>, void *codedptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v3; // eax
  PVOID (__stdcall *DecodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  unsigned int v7; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr
    && __flsindex != -1
    && (v7 = __flsindex,
        Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex),
        (v3 = Value(a1: v7)) != 0) )
  {
    DecodePointer = *(PVOID (__stdcall **)(PVOID))(v3 + 508);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || use_encode_pointer(a1) == 0 )
      return codedptr;
    DecodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "DecodePointer");
  }
  if ( DecodePointer != nullptr )
    return DecodePointer(Ptr: codedptr);
  return codedptr;
}

//------------------------------------------------------------------------------
// Address: 0x00409B93
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}

//------------------------------------------------------------------------------
// Address: 0x00409B9C
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *(__stdcall *__usercall __set_flsgetvalue@<eax>(unsigned int a1@<edi>))(unsigned int)
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: __getvalueindex);
  if ( Value == nullptr )
  {
    Value = _decode_pointer(a1, codedptr: gpFlsGetValue);
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: Value);
  }
  return (void *(__stdcall *)(unsigned int))Value;
}

//------------------------------------------------------------------------------
// Address: 0x00409BCE
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mtterm(unsigned int a1@<edi>)
{
  void (__stdcall *v1)(unsigned int); // eax
  unsigned int v2; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v2 = __flsindex;
    v1 = (void (__stdcall *)(unsigned int))_decode_pointer(a1, codedptr: gpFlsFree);
    v1(a1: v2);
    __flsindex = -1;
  }
  if ( __getvalueindex != -1 )
  {
    TlsFree(dwTlsIndex: __getvalueindex);
    __getvalueindex = -1;
  }
  _mtdeletelocks();
}

//------------------------------------------------------------------------------
// Address: 0x00409C0B
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  HINSTANCE__ *hKernel32; // [esp+10h] [ebp-1Ch]

  hKernel32 = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  ptd->_pxcptacttab = _XcptActTab;
  ptd->_holdrand = 1;
  if ( hKernel32 != nullptr && use_encode_pointer(a1: 1u) != 0 )
  {
    ptd->_encode_ptr = GetProcAddress(hModule: hKernel32, lpProcName: "EncodePointer");
    ptd->_decode_ptr = GetProcAddress(hModule: hKernel32, lpProcName: "DecodePointer");
  }
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  InterlockedIncrement(lpAddend: &__initialmbcinfo.refcount);
  _lock(locknum: 12);
  ptd->ptlocinfo = ptloci;
  if ( ptloci == nullptr )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptloci: ptd->ptlocinfo);
  _unlock(locknum: 12);
}

//------------------------------------------------------------------------------
// Address: 0x00409CCA
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  unsigned int v1; // edi
  void *(__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  _tiddata *v4; // eax
  int (__stdcall *v5)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  _tiddata *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = __set_flsgetvalue(a1: LastError);
  v3 = (_tiddata *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = (_tiddata *)_calloc_crt(count: 1u, size: 0x214u);
    v3 = v4;
    if ( v4 != nullptr )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(a1: v1, codedptr: gpFlsSetValue);
      if ( v5(a1: v8, a2: v10) != 0 )
      {
        _initptd(ptd: v3, ptloci: nullptr);
        CurrentThreadId = GetCurrentThreadId();
        v3->_thandle = -1;
        v3->_tid = CurrentThreadId;
      }
      else
      {
        free(pMem: v3);
        v3 = nullptr;
      }
    }
  }
  SetLastError(dwErrCode: v1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00409D41
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd()
{
  _tiddata *v0; // esi

  v0 = _getptd_noexit();
  if ( v0 == nullptr )
    _amsg_exit(rterrnum: 16);
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x00409D59
// Name: _freefls(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _freefls(void *data)
{
  threadmbcinfostruct *v1; // edi
  threadlocaleinfostruct *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( data != nullptr )
  {
    if ( *((_DWORD *)data + 9) != 0 )
      free(pMem: *((void **)data + 9));
    if ( *((_DWORD *)data + 11) != 0 )
      free(pMem: *((void **)data + 11));
    if ( *((_DWORD *)data + 13) != 0 )
      free(pMem: *((void **)data + 13));
    if ( *((_DWORD *)data + 15) != 0 )
      free(pMem: *((void **)data + 15));
    if ( *((_DWORD *)data + 17) != 0 )
      free(pMem: *((void **)data + 17));
    if ( *((_DWORD *)data + 18) != 0 )
      free(pMem: *((void **)data + 18));
    if ( *((_XCPT_ACTION **)data + 23) != _XcptActTab )
      free(pMem: *((void **)data + 23));
    _lock(locknum: 13);
    v1 = *((threadmbcinfostruct **)data + 26);
    if ( v1 != nullptr && InterlockedDecrement(lpAddend: *((volatile LONG **)data + 26)) == 0 && v1 != &__initialmbcinfo )
      free(pMem: v1);
    _unlock(locknum: 13);
    _lock(locknum: 12);
    v2 = *((threadlocaleinfostruct **)data + 27);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: *((threadlocaleinfostruct **)data + 27));
      if ( v2 != __ptlocinfo && v2 != &__initiallocinfo && v2->refcount == 0 )
        __freetlocinfo(ptloci: v2);
    }
    savedregs = 4234835;
    _unlock(locknum: 12);
    free(pMem: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409E7A
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinit()
{
  HMODULE ModuleHandleA; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-Ch] [ebp-10h]
  _tiddata *v11; // [esp-8h] [ebp-Ch]

  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  v1 = ModuleHandleA;
  if ( ModuleHandleA == nullptr )
  {
    _mtterm(a1: 0);
    return 0;
  }
  gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))GetProcAddress(
                                                                         hModule: ModuleHandleA,
                                                                         lpProcName: aFlsa);
  gpFlsGetValue = (void *(__stdcall *)(unsigned int))GetProcAddress(hModule: v1, lpProcName: "FlsGetValue");
  gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))GetProcAddress(hModule: v1, lpProcName: "FlsSetValue");
  FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(hModule: v1, lpProcName: "FlsFree");
  gpFlsFree = FlsFree;
  if ( gpFlsAlloc == nullptr || gpFlsGetValue == nullptr || gpFlsSetValue == nullptr || FlsFree == nullptr )
  {
    gpFlsGetValue = TlsGetValue;
    gpFlsAlloc = __crtTlsAlloc;
    gpFlsSetValue = TlsSetValue;
    gpFlsFree = TlsFree;
  }
  v4 = TlsAlloc();
  __getvalueindex = v4;
  if ( v4 != -1 && TlsSetValue(dwTlsIndex: v4, lpTlsValue: gpFlsGetValue) )
  {
    _init_pointers();
    gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))_encode_pointer(
                                                                           a1: (unsigned int)v1,
                                                                           ptr: gpFlsAlloc);
    gpFlsGetValue = (void *(__stdcall *)(unsigned int))_encode_pointer(a1: (unsigned int)v1, ptr: gpFlsGetValue);
    gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))_encode_pointer(a1: (unsigned int)v1, ptr: gpFlsSetValue);
    gpFlsFree = (int (__stdcall *)(unsigned int))_encode_pointer(a1: (unsigned int)v1, ptr: gpFlsFree);
    if ( _mtinitlocks() != 0 )
    {
      v5 = (int (__stdcall *)(_DWORD))_decode_pointer(a1: (unsigned int)v1, codedptr: gpFlsAlloc);
      __flsindex = v5(a1: _freefls);
      if ( __flsindex != -1 )
      {
        v6 = (_tiddata *)_calloc_crt(count: 1u, size: 0x214u);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          v10 = __flsindex;
          v8 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(
                                                              a1: (unsigned int)v1,
                                                              codedptr: gpFlsSetValue);
          if ( v8(a1: v10, a2: v11) != 0 )
          {
            _initptd(ptd: v7, ptloci: nullptr);
            CurrentThreadId = GetCurrentThreadId();
            v7->_thandle = -1;
            v7->_tid = CurrentThreadId;
            return 1;
          }
        }
      }
    }
    _mtterm(a1: (unsigned int)v1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409FFE
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void (__cdecl *enull)())
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040A008
// Name: fastzero_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastzero_I(_OWORD *dst, unsigned int len)
{
  unsigned int v3; // ecx

  v3 = len >> 7;
  do
  {
    *dst = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 0;
    dst[6] = 0;
    dst[7] = 0;
    dst += 8;
    --v3;
  }
  while ( v3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x0040A05F
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _VEC_memzero(int dst, int val, int len)
{
  char *result; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // [esp+4h] [ebp-Ch]

  result = (char *)dst;
  v4 = dst % 16;
  if ( dst % 16 != 0 )
  {
    memset((void *)dst, 0, 16 - v4);
    _VEC_memzero(dst: (void *)(16 - v4 + dst), val: 0, len: len - (16 - v4));
    return (char *)dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastzero_I((_OWORD *)dst, len: len - v5);
      result = (char *)dst;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      memset(&result[len - v5], 0, v6);
      return (char *)dst;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A0EE
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  bool v5; // zf
  char *base; // eax
  char *ptr; // edi
  signed int v8; // edi
  ioinfo *v9; // eax
  __int64 v10; // rax
  int written; // [esp+4h] [ebp-4h]

  v2 = (_iobuf *)str;
  str = _fileno(stream: (_iobuf *)str);
  flag = v2->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v2->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v2->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v2->_flag = flag | 0x20;
      return -1;
    }
    v2->_ptr = v2->_base;
    v2->_flag = flag & 0xFFFFFFFE;
  }
  v5 = (v2->_flag & 0x10C) == 0;
  v2->_flag = v2->_flag & 0xFFFFFFED | 2;
  v2->_cnt = 0;
  written = 0;
  if ( v5 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
    _getbuf(str: v2);
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    ptr = v2->_ptr;
    v2->_ptr = base + 1;
    v8 = ptr - base;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v8 <= 0 )
    {
      if ( str == -1 || str == -2 )
        v9 = &__badioinfo;
      else
        v9 = &__pioinfo[str >> 5][str & 0x1F];
      if ( (v9->osfile & 0x20) != 0 )
      {
        v10 = _lseeki64(fh: str, pos: 0, mthd: 2);
        if ( (HIDWORD(v10) & (unsigned int)v10) == 0xFFFFFFFF )
          goto LABEL_27;
      }
    }
    else
    {
      written = _write(fh: str, buf: base, cnt: v8);
    }
    *v2->_base = ch;
  }
  else
  {
    v8 = 1;
    written = _write(fh: str, buf: &ch, cnt: 1u);
  }
  if ( written != v8 )
  {
LABEL_27:
    v2->_flag |= 0x20u;
    return -1;
  }
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x0040A24E
// Name: write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>)
{
  bool v3; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr)
    && ((v3 = f->_cnt - 1 < 0, --f->_cnt, v3)
      ? (ch = _flsbuf(ch, str: (int)f))
      : (*f->_ptr = ch, ++f->_ptr, ch = (unsigned __int8)ch),
        ch == -1) )
  {
    *pnumwritten = -1;
  }
  else
  {
    ++*pnumwritten;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A281
// Name: write_multi_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_multi_char(int *pnumwritten@<eax>, char ch, int num, _iobuf *f)
{
  int *v4; // esi

  v4 = pnumwritten;
  do
  {
    if ( num <= 0 )
      break;
    LOBYTE(pnumwritten) = ch;
    --num;
    write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
  }
  while ( *v4 != -1 );
}

//------------------------------------------------------------------------------
// Address: 0x0040A2A5
// Name: write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(char *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  int *v4; // esi
  int *v6; // eax

  v4 = pnumwritten;
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      LOBYTE(pnumwritten) = *string;
      --len;
      write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
      ++string;
      if ( *v4 == -1 )
      {
        v6 = _errno();
        if ( *v6 != 42 )
          return;
        LOBYTE(v6) = 63;
        write_char(ch: (int)v6, f, pnumwritten: v4);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A2EF
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  const char *v4; // ebx
  int *p_charsout; // esi
  int *v6; // edi
  _DWORD *v8; // esi
  ioinfo *v9; // eax
  _DWORD *v10; // esi
  ioinfo *v11; // eax
  char v12; // dl
  STATE v13; // ecx
  bool v14; // zf
  int v15; // eax
  char v16; // al
  int v17; // eax
  _output_l::__l2::<unnamed_tag> *p_buffer; // ebx
  int v19; // ecx
  char *v20; // edi
  char *v21; // eax
  char *v22; // edi
  __int16 *v23; // eax
  char *v24; // ecx
  int v25; // eax
  __int64 v26; // rax
  int *v27; // edi
  int v28; // esi
  char *v29; // eax
  int v30; // eax
  unsigned int v31; // edi
  void (__cdecl *v32)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *); // eax
  unsigned int v33; // edi
  void (__cdecl *v34)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  void (__cdecl *v35)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  unsigned int v36; // ebx
  unsigned int v37; // edi
  char *j; // esi
  int v39; // eax
  unsigned __int64 v40; // rcx
  int v41; // ecx
  char *v42; // eax
  char *v43; // esi
  char *i; // eax
  int v45; // ebx
  _iobuf *v46; // edi
  char *v47; // esi
  wchar_t v48; // ax
  char v49; // al
  int v50; // [esp-14h] [ebp-A0h]
  int v51; // [esp-10h] [ebp-9Ch]
  unsigned __int64 v52; // [esp-10h] [ebp-9Ch]
  int v53; // [esp-Ch] [ebp-98h]
  int v54; // [esp-8h] [ebp-94h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-80h] BYREF
  int capexp; // [esp+14h] [ebp-78h]
  STATE state; // [esp+18h] [ebp-74h]
  int retval; // [esp+1Ch] [ebp-70h] BYREF
  int count; // [esp+24h] [ebp-68h]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-64h] BYREF
  char *heapbuf; // [esp+38h] [ebp-54h]
  int no_output; // [esp+3Ch] [ebp-50h]
  int hexadd; // [esp+40h] [ebp-4Ch]
  char *v64; // [esp+44h] [ebp-48h]
  int bufferiswide; // [esp+48h] [ebp-44h]
  int fldwidth; // [esp+4Ch] [ebp-40h]
  int prefixlen; // [esp+50h] [ebp-3Ch]
  char prefix[4]; // [esp+54h] [ebp-38h] BYREF
  int charsout; // [esp+58h] [ebp-34h] BYREF
  _iobuf *f; // [esp+5Ch] [ebp-30h]
  char *v71; // [esp+60h] [ebp-2Ch]
  int radix; // [esp+64h] [ebp-28h] BYREF
  char *string; // [esp+68h] [ebp-24h]
  int precision; // [esp+6Ch] [ebp-20h]
  char v75; // [esp+73h] [ebp-19h]
  int flags; // [esp+74h] [ebp-18h]
  _output_l::__l2::<unnamed_tag> buffer; // [esp+78h] [ebp-14h] BYREF
  char L_buffer[8]; // [esp+278h] [ebp+1ECh] BYREF

  v4 = format;
  p_charsout = nullptr;
  v6 = (int *)argptr;
  f = stream;
  v71 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( f == nullptr
    || (f->_flag & 0x40) == 0
    && (_fileno(stream: f) == -1 || _fileno(stream: f) == -2
      ? (v9 = &__badioinfo)
      : (ioinfo *)(v8 = (_DWORD *)(4 * (_fileno(stream: f) >> 5) + 4312448),
                   v9 = (ioinfo *)(*v8 + 56 * (_fileno(stream: f) & 0x1F)),
                   p_charsout = nullptr),
        (*((_BYTE *)v9 + 36) & 0x7F) != 0
     || (_fileno(stream: f) == -1 || _fileno(stream: f) == -2
       ? (v11 = &__badioinfo)
       : (ioinfo *)(v10 = (_DWORD *)(4 * (_fileno(stream: f) >> 5) + 4312448),
                    v11 = (ioinfo *)(*v10 + 56 * (_fileno(stream: f) & 0x1F)),
                    p_charsout = nullptr),
         *((char *)v11 + 36) < 0))
    || format == nullptr )
  {
    *_errno() = 22;
    goto LABEL_3;
  }
  v12 = *format;
  v13 = ST_NORMAL;
  v14 = *format == 0;
  charsout = 0;
  radix = 0;
  heapbuf = nullptr;
  v75 = v12;
  if ( v14 )
  {
LABEL_222:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 1 )
  {
    v64 = (char *)++v4;
    if ( charsout < 0 )
      goto LABEL_222;
    if ( (unsigned __int8)(v12 - 32) > 0x58u )
      v15 = 0;
    else
      v15 = byte_415100[v12] & 0xF;
    state = __lookuptable[8 * v15 + v13] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_219;
      case ST_FLAG:
        switch ( v12 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_219;
      case ST_WIDTH:
        if ( v12 == 42 )
        {
          v71 = (char *)(v6 + 1);
          fldwidth = *v6;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + v12 - 48;
        }
        goto LABEL_219;
      case ST_DOT:
        precision = 0;
        goto LABEL_219;
      case ST_PRECIS:
        if ( v12 == 42 )
        {
          v71 = (char *)(v6 + 1);
          precision = *v6;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + v12 - 48;
        }
        goto LABEL_219;
      case ST_SIZE:
        if ( v12 != 73 )
        {
          switch ( v12 )
          {
            case 'h':
              flags |= 0x20u;
              break;
            case 'l':
              if ( *v4 == 108 )
              {
                flags |= 0x1000u;
                v64 = (char *)(v4 + 1);
              }
              else
              {
                flags |= 0x10u;
              }
              break;
            case 'w':
              flags |= 0x800u;
              break;
            default:
              break;
          }
          goto LABEL_219;
        }
        v16 = *v4;
        if ( *v4 == 54 && v4[1] == 52 )
        {
          flags |= 0x8000u;
          v64 = (char *)(v4 + 2);
          goto LABEL_219;
        }
        if ( v16 == 51 && v4[1] == 50 )
        {
          flags &= ~0x8000u;
          v64 = (char *)(v4 + 2);
          goto LABEL_219;
        }
        if ( v16 == 100 || v16 == 105 || v16 == 111 || v16 == 117 || v16 == 120 || v16 == 88 )
          goto LABEL_219;
        state = ST_NORMAL;
NORMAL_STATE:
        bufferiswide = 0;
        v17 = _isleadbyte_l(c: (unsigned __int8)v12, plocinfo: &_loc_update.localeinfo);
        v14 = v17 == 0;
        LOBYTE(v17) = v75;
        if ( v14
          || (p_charsout = &charsout,
              write_char(ch: v17, f, pnumwritten: &charsout),
              LOBYTE(v17) = *v4,
              ++v4,
              v64 = (char *)v4,
              (_BYTE)v17 != 0) )
        {
          write_char(ch: v17, f, pnumwritten: &charsout);
          goto LABEL_219;
        }
LABEL_221:
        *_errno() = 22;
LABEL_3:
        _invalid_parameter(a1: (unsigned int)v4, a2: (unsigned int)v6, a3: (unsigned int)p_charsout);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      case ST_TYPE:
        if ( v12 <= 100 )
        {
          if ( v12 == 100 )
          {
LABEL_119:
            flags |= 0x40u;
            goto LABEL_120;
          }
          if ( v12 > 83 )
          {
            if ( v12 == 88 )
              goto LABEL_141;
            if ( v12 == 90 )
            {
              v23 = (__int16 *)*v6;
              v71 = (char *)(v6 + 1);
              if ( v23 != nullptr && (v24 = *((char **)v23 + 1)) != nullptr )
              {
                v25 = *v23;
                string = v24;
                if ( (flags & 0x800) != 0 )
                {
                  v25 /= 2;
                  bufferiswide = 1;
                }
                else
                {
                  bufferiswide = 0;
                }
              }
              else
              {
                string = __nullstring;
                strlen(buf: __nullstring);
              }
              goto LABEL_190;
            }
            if ( v12 != 97 )
            {
              if ( v12 != 99 )
                goto LABEL_191;
              goto LABEL_94;
            }
          }
          else
          {
            if ( v12 == 83 )
            {
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
              goto LABEL_84;
            }
            if ( v12 != 65 )
            {
              if ( v12 != 67 )
              {
                if ( v12 != 69 && v12 != 71 )
                  goto LABEL_191;
                goto LABEL_77;
              }
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
LABEL_94:
              v22 = (char *)(v6 + 1);
              v71 = v22;
              if ( (flags & 0x810) != 0 )
              {
                if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v22 - 2)) != 0 )
                  no_output = 1;
              }
              else
              {
                buffer.sz[0] = *(v22 - 4);
                radix = 1;
              }
              string = (char *)&buffer;
              goto LABEL_191;
            }
LABEL_77:
            v12 += 32;
            capexp = 1;
            v75 = v12;
          }
LABEL_78:
          flags |= 0x40u;
          p_buffer = &buffer;
          string = (char *)&buffer;
          count = 512;
          if ( precision >= 0 )
          {
            if ( precision != 0 )
            {
              if ( precision > 512 )
                precision = 512;
              if ( precision > 163 )
              {
                v28 = precision + 349;
                v29 = (char *)_malloc_crt(size: precision + 349);
                v12 = v75;
                heapbuf = v29;
                if ( v29 != nullptr )
                {
                  string = v29;
                  count = v28;
                  p_buffer = (_output_l::__l2::<unnamed_tag> *)v29;
                }
                else
                {
                  precision = 163;
                }
              }
            }
            else
            {
              precision = v12 == 103;
            }
          }
          else
          {
            precision = 6;
          }
          v30 = *v6;
          v31 = (unsigned int)(v6 + 2);
          LODWORD(tmp.x) = v30;
          HIDWORD(tmp.x) = *(_DWORD *)(v31 - 4);
          v54 = capexp;
          v53 = precision;
          v71 = (char *)v31;
          v51 = v12;
          v50 = count;
          v32 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(a1: v31, codedptr: codedptr);
          v32(a1: &tmp, a2: p_buffer, a3: v50, a4: v51, a5: v53, a6: v54, a7: &_loc_update);
          v33 = flags & 0x80;
          if ( (flags & 0x80) != 0 && precision == 0 )
          {
            v34 = (void (__cdecl *)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(
                                                                                         a1: v33,
                                                                                         codedptr: off_4183F4);
            v34(a1: p_buffer, a2: &_loc_update);
          }
          if ( v75 == 103 && v33 == 0 )
          {
            v35 = (void (__cdecl *)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(
                                                                                         a1: 0,
                                                                                         codedptr: off_4183F0);
            v35(a1: p_buffer, a2: &_loc_update);
          }
          if ( p_buffer->sz[0] == 45 )
          {
            flags |= 0x100u;
            p_buffer = (_output_l::__l2::<unnamed_tag> *)((char *)p_buffer + 1);
            string = (char *)p_buffer;
          }
          strlen(buf: p_buffer->sz);
          goto LABEL_190;
        }
        if ( v12 > 112 )
        {
          if ( v12 != 115 )
          {
            if ( v12 != 117 )
            {
              if ( v12 != 120 )
                goto LABEL_191;
              hexadd = 39;
              goto COMMON_HEX;
            }
LABEL_120:
            radix = 10;
            goto COMMON_INT;
          }
LABEL_84:
          v19 = precision;
          if ( precision == -1 )
            v19 = 0x7FFFFFFF;
          v71 = (char *)(v6 + 1);
          v20 = (char *)*v6;
          string = v20;
          if ( (flags & 0x810) != 0 )
          {
            if ( v20 == nullptr )
              string = (char *)__wnullstring;
            v21 = string;
            bufferiswide = 1;
            while ( v19 != 0 )
            {
              --v19;
              if ( *(_WORD *)v21 == 0 )
                break;
              v21 += 2;
            }
            v25 = (v21 - string) >> 1;
          }
          else
          {
            if ( v20 == nullptr )
              string = __nullstring;
            for ( i = string; v19 != 0; ++i )
            {
              --v19;
              if ( *i == 0 )
                break;
            }
            v25 = i - string;
          }
LABEL_190:
          radix = v25;
          goto LABEL_191;
        }
        if ( v12 == 112 )
        {
          precision = 8;
LABEL_141:
          hexadd = 7;
COMMON_HEX:
          radix = 16;
          if ( (flags & 0x80u) != 0 )
          {
            prefix[0] = 48;
            prefix[1] = hexadd + 81;
            prefixlen = 2;
          }
          goto COMMON_INT;
        }
        if ( v12 < 101 )
          goto LABEL_191;
        if ( v12 <= 103 )
          goto LABEL_78;
        if ( v12 == 105 )
          goto LABEL_119;
        if ( v12 != 110 )
        {
          if ( v12 != 111 )
            goto LABEL_191;
          radix = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
COMMON_INT:
          if ( (flags & 0x8000u) != 0 || (flags & 0x1000) != 0 )
          {
            v26 = *(_QWORD *)v6;
            v27 = v6 + 2;
          }
          else
          {
            v27 = v6 + 1;
            if ( (flags & 0x20) != 0 )
            {
              v71 = (char *)v27;
              if ( (flags & 0x40) != 0 )
                LODWORD(v26) = *((__int16 *)v27 - 2);
              else
                LODWORD(v26) = *((unsigned __int16 *)v27 - 2);
              v26 = (int)v26;
LABEL_158:
              if ( (flags & 0x40) != 0 && v26 < 0 )
              {
                v26 = -v26;
                flags |= 0x100u;
              }
              v36 = HIDWORD(v26);
              v37 = v26;
              if ( (flags & 0x9000) == 0 )
                v36 = 0;
              if ( precision >= 0 )
              {
                flags &= ~8u;
                if ( precision > 512 )
                  precision = 512;
              }
              else
              {
                precision = 1;
              }
              if ( (v36 | (unsigned int)v26) == 0 )
                prefixlen = 0;
              for ( j = &buffer.sz[511]; ; --j )
              {
                v39 = precision--;
                if ( v39 <= 0 && (v36 | v37) == 0 )
                  break;
                v52 = __PAIR64__(v36, v37);
                v40 = __PAIR64__(v36, v37) % radix;
                v41 = v40 + 48;
                count = HIDWORD(v40);
                v36 = (v52 / radix) >> 32;
                v37 = v52 / radix;
                if ( v41 > 57 )
                  LOBYTE(v41) = hexadd + v41;
                *j = v41;
              }
              v42 = (char *)(&buffer.sz[511] - j);
              v43 = j + 1;
              radix = (int)v42;
              string = v43;
              if ( (flags & 0x200) != 0 && (v42 == nullptr || *v43 != 48) )
              {
                *--string = 48;
                v25 = (int)(v42 + 1);
                goto LABEL_190;
              }
LABEL_191:
              if ( no_output != 0 )
                goto LABEL_217;
              if ( (flags & 0x40) != 0 )
              {
                if ( (flags & 0x100) != 0 )
                {
                  prefix[0] = 45;
                  goto LABEL_199;
                }
                if ( (flags & 1) != 0 )
                {
                  prefix[0] = 43;
                  goto LABEL_199;
                }
                if ( (flags & 2) != 0 )
                {
                  prefix[0] = 32;
LABEL_199:
                  prefixlen = 1;
                }
              }
              v45 = fldwidth - radix - prefixlen;
              if ( (flags & 0xC) == 0 )
                write_multi_char(pnumwritten: &charsout, ch: 32, num: fldwidth - radix - prefixlen, f);
              v46 = f;
              write_string(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
              if ( (flags & 8) != 0 && (flags & 4) == 0 )
                write_multi_char(pnumwritten: &charsout, ch: 48, num: v45, f: v46);
              if ( bufferiswide != 0 && radix > 0 )
              {
                v47 = string;
                count = radix;
                while ( 1 )
                {
                  v48 = *(_WORD *)v47;
                  --count;
                  v47 += 2;
                  if ( wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v48) != 0 || retval == 0 )
                    break;
                  write_string(string: L_buffer, f: v46, pnumwritten: &charsout, len: retval);
                  if ( count == 0 )
                    goto LABEL_214;
                }
                charsout = -1;
              }
              else
              {
                write_string(string, f: v46, pnumwritten: &charsout, len: radix);
              }
LABEL_214:
              if ( charsout >= 0 && (flags & 4) != 0 )
                write_multi_char(pnumwritten: &charsout, ch: 32, num: v45, f: v46);
              goto LABEL_217;
            }
            LODWORD(v26) = *(v27 - 1);
            if ( (flags & 0x40) != 0 )
              v26 = (int)v26;
            else
              HIDWORD(v26) = 0;
          }
          v71 = (char *)v27;
          goto LABEL_158;
        }
        p_charsout = (int *)*v6++;
        v71 = (char *)v6;
        if ( !_get_printf_count_output() )
          goto LABEL_221;
        if ( (flags & 0x20) != 0 )
          *(_WORD *)p_charsout = charsout;
        else
          *p_charsout = charsout;
        no_output = 1;
LABEL_217:
        if ( heapbuf != nullptr )
        {
          free(pMem: heapbuf);
          heapbuf = nullptr;
        }
LABEL_219:
        v4 = v64;
        v49 = *v64;
        v75 = *v64;
        if ( v75 == 0 )
          goto LABEL_222;
        v13 = state;
        v6 = (int *)v71;
        v12 = v49;
        break;
      default:
        goto LABEL_219;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AC83
// Name: long __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *pPtrs)
{
  _EXCEPTION_RECORD *ExceptionRecord; // eax
  unsigned int v2; // eax

  ExceptionRecord = pPtrs->ExceptionRecord;
  if ( pPtrs->ExceptionRecord->ExceptionCode == -529697949 && ExceptionRecord->NumberParameters == 3 )
  {
    v2 = ExceptionRecord->ExceptionInformation[0];
    if ( v2 == 429065504 || v2 == 429065505 || v2 == 429065506 || v2 == 26820608 )
      terminate();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040ACC0
// Name: ___CxxSetUnhandledExceptionFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __CxxSetUnhandledExceptionFilter()
{
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: __CxxUnhandledExceptionFilter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040ACCE
// Name: __initp_misc_winxfltr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winxfltr()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0040ACCF
// Name: __XcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _XcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  int result; // eax
  _DWORD *v3; // esi
  int *v4; // edx
  int *v5; // ecx
  int *v6; // eax
  void (__cdecl *v7)(int); // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  void *oldpxcptinfoptrs; // [esp+4h] [ebp-8h]

  result = (int)_getptd_noexit();
  v3 = (_DWORD *)result;
  if ( result != 0 )
  {
    v4 = *(int **)(result + 92);
    v5 = v4;
    do
    {
      if ( *v5 == xcptnum )
        break;
      v5 += 3;
    }
    while ( v5 < &v4[3 * _XcptActTabCount] );
    if ( v5 < &v4[3 * _XcptActTabCount] && *v5 == xcptnum )
      v6 = v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr && (v7 = (void (__cdecl *)(int))v6[2]) != nullptr )
    {
      if ( v7 == (void (__cdecl *)(int))5 )
      {
        v6[2] = 0;
        return 1;
      }
      else
      {
        if ( v7 != (void (__cdecl *)(int))1 )
        {
          oldpxcptinfoptrs = (void *)v3[24];
          v3[24] = pxcptinfoptrs;
          v8 = v6[1];
          if ( v8 == 8 )
          {
            v9 = _First_FPE_Indx;
            if ( _First_FPE_Indx < _First_FPE_Indx + _Num_FPE )
            {
              v10 = 12 * _First_FPE_Indx;
              do
              {
                *(_DWORD *)(v10 + v3[23] + 8) = 0;
                ++v9;
                v10 += 12;
              }
              while ( v9 < _First_FPE_Indx + _Num_FPE );
            }
            v11 = *v6;
            v12 = v3[25];
            switch ( v11 )
            {
              case -1073741682:
                v3[25] = 131;
                break;
              case -1073741680:
                v3[25] = 129;
                break;
              case -1073741679:
                v3[25] = 132;
                break;
              case -1073741677:
                v3[25] = 133;
                break;
              case -1073741683:
                v3[25] = 130;
                break;
              case -1073741681:
                v3[25] = 134;
                break;
              case -1073741678:
                v3[25] = 138;
                break;
              default:
                break;
            }
            v7(a1: 8);
            v3[25] = v12;
          }
          else
          {
            v6[2] = 0;
            v7(a1: v8);
          }
          v3[24] = oldpxcptinfoptrs;
        }
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040AE2D
// Name: __setenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setenvp()
{
  char *v0; // esi
  int v1; // edi
  int v3; // eax
  char **v4; // edi
  char *i; // esi
  int v6; // eax
  unsigned int v7; // ebp
  char *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  v0 = _aenvptr;
  v1 = 0;
  if ( _aenvptr != nullptr )
  {
    while ( *v0 != 0 )
    {
      if ( *v0 != 61 )
        ++v1;
      strlen(buf: v0);
      v0 += v3 + 1;
    }
    v4 = (char **)_calloc_crt(count: v1 + 1, size: 4u);
    _environ = v4;
    if ( v4 != nullptr )
    {
      for ( i = _aenvptr; ; i += v7 )
      {
        if ( *i == 0 )
        {
          free(pMem: _aenvptr);
          _aenvptr = nullptr;
          *v4 = nullptr;
          __env_initialized = 1;
          return 0;
        }
        strlen(buf: i);
        v7 = v6 + 1;
        if ( *i != 61 )
          break;
LABEL_16:
        ;
      }
      v8 = (char *)_calloc_crt(count: v6 + 1, size: 1u);
      *v4 = v8;
      if ( v8 != nullptr )
      {
        v9 = strcpy_s(a1: (unsigned int)v4, _Dst: v8, _SizeInBytes: v7, _Src: i);
        if ( v9 != 0 )
          _invoke_watson(a1: v9, a2: v10, a3: v11, a4: 0, a5: (unsigned int)v4, a6: (unsigned int)i);
        ++v4;
        goto LABEL_16;
      }
      free(pMem: _environ);
      _environ = nullptr;
      return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040AF08
// Name: parse_cmdline
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall parse_cmdline(char *cmdstart@<edx>, int *numchars@<edi>, char **argv, char *args, int *numargs)
{
  int *v5; // ecx
  char *v7; // edx
  char **v8; // ebx
  char v9; // bl
  char *v10; // ecx
  char **v11; // eax
  int v12; // ebx
  unsigned int v13; // ecx
  char v14; // al
  char *v15; // ecx
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-10h]
  BOOL inquote; // [esp+8h] [ebp-4h]
  BOOL inquotea; // [esp+8h] [ebp-4h]

  v5 = numargs;
  *numchars = 0;
  v7 = args;
  *numargs = 1;
  if ( argv != nullptr )
  {
    v8 = argv++;
    *v8 = args;
  }
  inquote = false;
  do
  {
    if ( *cmdstart == 34 )
    {
      v9 = 34;
      ++cmdstart;
      inquote = !inquote;
    }
    else
    {
      ++*numchars;
      if ( v7 != nullptr )
      {
        *v7 = *cmdstart;
        args = v7 + 1;
      }
      v9 = *cmdstart;
      v17 = (unsigned __int8)*cmdstart++;
      if ( _ismbblead(tst: v17) != 0 )
      {
        ++*numchars;
        if ( args != nullptr )
        {
          v10 = args++;
          *v10 = *cmdstart;
        }
        ++cmdstart;
      }
      v7 = args;
      v5 = numargs;
      if ( v9 == 0 )
      {
        --cmdstart;
        goto LABEL_18;
      }
    }
  }
  while ( inquote || v9 != 32 && v9 != 9 );
  if ( v7 != nullptr )
    *(v7 - 1) = 0;
LABEL_18:
  inquotea = false;
  while ( *cmdstart != 0 )
  {
    while ( *cmdstart == 32 || *cmdstart == 9 )
      ++cmdstart;
    if ( *cmdstart == 0 )
      break;
    if ( argv != nullptr )
    {
      v11 = argv++;
      *v11 = v7;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *cmdstart == 92 )
      {
        ++cmdstart;
        ++v13;
      }
      if ( *cmdstart == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( inquotea && cmdstart[1] == 34 )
          {
            ++cmdstart;
          }
          else
          {
            v12 = 0;
            inquotea = !inquotea;
          }
        }
        v13 >>= 1;
      }
      if ( v13 != 0 )
      {
        do
        {
          --v13;
          if ( v7 != nullptr )
            *v7++ = 92;
          ++*numchars;
        }
        while ( v13 != 0 );
        args = v7;
      }
      v14 = *cmdstart;
      if ( *cmdstart == 0 || !inquotea && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 != 0 )
      {
        if ( v7 != nullptr )
        {
          if ( _ismbblead(tst: v14) != 0 )
          {
            v15 = args++;
            *v15 = *cmdstart++;
            ++*numchars;
          }
          v16 = args++;
          *v16 = *cmdstart;
        }
        else if ( _ismbblead(tst: v14) != 0 )
        {
          ++cmdstart;
          ++*numchars;
        }
        ++*numchars;
        v7 = args;
      }
      ++cmdstart;
    }
    if ( v7 != nullptr )
    {
      *v7++ = 0;
      args = v7;
    }
    ++*numchars;
    v5 = numargs;
  }
  if ( argv != nullptr )
    *argv = nullptr;
  ++*v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040B0A0
// Name: __setargv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setargv()
{
  bool v0; // zf
  int v1; // edi
  unsigned int v2; // eax
  char **v3; // esi
  int numchars; // [esp+Ch] [ebp-Ch] BYREF
  int numargs; // [esp+10h] [ebp-8h] BYREF
  char *cmdstart; // [esp+14h] [ebp-4h]

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(hModule: nullptr, lpFilename: pgmname, nSize: 0x104u);
  _pgmptr = pgmname;
  if ( _acmdln == nullptr || (v0 = *_acmdln == 0, cmdstart = _acmdln, v0) )
    cmdstart = pgmname;
  parse_cmdline(cmdstart, &numchars, argv: nullptr, args: nullptr, &numargs);
  if ( (unsigned int)numargs >= 0x3FFFFFFF )
    return -1;
  if ( numchars == -1 )
    return -1;
  v1 = numargs;
  v2 = 4 * numargs + numchars;
  if ( v2 < numchars )
    return -1;
  v3 = (char **)_malloc_crt(size: v2);
  if ( v3 == nullptr )
    return -1;
  parse_cmdline(cmdstart, &numchars, argv: v3, args: (char *)&v3[v1], &numargs);
  __argc = numargs - 1;
  __argv = v3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B159
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsA()
{
  int v0; // eax
  char *v1; // ebx
  WCHAR *EnvironmentStringsW; // esi
  WCHAR *i; // eax
  unsigned int v5; // eax
  int v6; // ebp
  char *v7; // eax
  LPCH EnvironmentStrings; // eax
  char *v9; // esi
  unsigned int v10; // ebp
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // edi
  char *nSizeW; // [esp+10h] [ebp-8h]
  int cchWideChar; // [esp+14h] [ebp-4h]

  v0 = f_use_0;
  v1 = nullptr;
  EnvironmentStringsW = nullptr;
  if ( f_use_0 == 0 )
  {
    EnvironmentStringsW = GetEnvironmentStringsW();
    if ( EnvironmentStringsW != nullptr )
    {
      f_use_0 = 1;
      goto LABEL_8;
    }
    if ( GetLastError() == 120 )
    {
      v0 = 2;
      f_use_0 = 2;
    }
    else
    {
      v0 = f_use_0;
    }
  }
  if ( v0 == 1 )
  {
LABEL_8:
    if ( EnvironmentStringsW == nullptr )
    {
      EnvironmentStringsW = GetEnvironmentStringsW();
      if ( EnvironmentStringsW == nullptr )
        return nullptr;
    }
    for ( i = EnvironmentStringsW; *i != 0; ++i )
    {
      do
        ++i;
      while ( *i != 0 );
    }
    cchWideChar = i - EnvironmentStringsW + 1;
    v5 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: EnvironmentStringsW,
           cchWideChar,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    v6 = v5;
    if ( v5 != 0 )
    {
      v7 = (char *)_malloc_crt(size: v5);
      nSizeW = v7;
      if ( v7 != nullptr )
      {
        if ( WideCharToMultiByte(
               CodePage: 0,
               dwFlags: 0,
               lpWideCharStr: EnvironmentStringsW,
               cchWideChar,
               lpMultiByteStr: v7,
               cbMultiByte: v6,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: nullptr) == 0 )
        {
          free(pMem: nSizeW);
          nSizeW = nullptr;
        }
        v1 = nSizeW;
      }
    }
    FreeEnvironmentStringsW(penv: EnvironmentStringsW);
    return (unsigned __int8 *)v1;
  }
  if ( v0 != 2 && v0 != 0 )
    return nullptr;
  EnvironmentStrings = GetEnvironmentStrings();
  v9 = EnvironmentStrings;
  if ( EnvironmentStrings == nullptr )
    return nullptr;
  for ( ; *EnvironmentStrings != 0; ++EnvironmentStrings )
  {
    do
      ++EnvironmentStrings;
    while ( *EnvironmentStrings != 0 );
  }
  v10 = EnvironmentStrings - v9 + 1;
  v11 = (unsigned __int8 *)_malloc_crt(size: v10);
  v12 = v11;
  if ( v11 == nullptr )
  {
    FreeEnvironmentStringsA(penv: v9);
    return nullptr;
  }
  memcpy(dst: v11, src: (unsigned __int8 *)v9, count: v10);
  FreeEnvironmentStringsA(penv: v9);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x0040B28E
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  ioinfo *v0; // eax
  ioinfo *i; // ecx
  int v2; // edi
  unsigned __int8 *v3; // ebx
  int v4; // esi
  ioinfo *v5; // eax
  ioinfo *j; // edx
  ioinfo *v7; // esi
  int k; // ebx
  ioinfo *v9; // esi
  DWORD v10; // eax
  HANDLE StdHandle; // eax
  int v12; // edi
  DWORD FileType; // eax
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-64h] BYREF
  int fh; // [esp+54h] [ebp-20h]
  int *posfhnd; // [esp+58h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+5Ch] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  GetStartupInfoA(lpStartupInfo: &StartupInfo);
  ms_exc.registration.TryLevel = -2;
  v0 = (ioinfo *)_calloc_crt(count: 0x20u, size: 0x38u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = v0;
  _nhandle = 32;
  for ( i = v0 + 32; v0 < i; i = __pioinfo[0] + 32 )
  {
    v0->osfile = 0;
    v0->osfhnd = -1;
    v0->pipech = 10;
    v0->lockinitflag = 0;
    *((_BYTE *)v0 + 36) = 0;
    v0->pipech2[0] = 10;
    v0->pipech2[1] = 10;
    ++v0;
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v2 = *(_DWORD *)StartupInfo.lpReserved2;
    v3 = StartupInfo.lpReserved2 + 4;
    posfhnd = (int *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( v2 >= 2048 )
      v2 = 2048;
    v4 = 1;
    while ( (int)_nhandle < v2 )
    {
      v5 = (ioinfo *)_calloc_crt(count: 0x20u, size: 0x38u);
      if ( v5 == nullptr )
      {
        v2 = _nhandle;
        break;
      }
      __pioinfo[v4] = v5;
      _nhandle += 32;
      for ( j = v5 + 32; v5 < j; j = __pioinfo[v4] + 32 )
      {
        v5->osfile = 0;
        v5->osfhnd = -1;
        v5->pipech = 10;
        v5->lockinitflag = 0;
        *((_BYTE *)v5 + 36) &= 0x80u;
        v5->pipech2[0] = 10;
        v5->pipech2[1] = 10;
        ++v5;
      }
      ++v4;
    }
    for ( fh = 0; fh < v2; ++posfhnd )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*v3 & 1) != 0
        && ((*v3 & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v7 = &__pioinfo[fh >> 5][fh & 0x1F];
        v7->osfhnd = *posfhnd;
        v7->osfile = *v3;
        if ( __crtInitCritSecAndSpinCount(lpCriticalSection: &v7->lock, dwSpinCount: 0xFA0u) == 0 )
          return -1;
        ++v7->lockinitflag;
      }
      ++fh;
      ++v3;
    }
  }
  for ( k = 0; k < 3; ++k )
  {
    v9 = &__pioinfo[0][k];
    if ( v9->osfhnd == -1 || v9->osfhnd == -2 )
    {
      v9->osfile = -127;
      if ( k != 0 )
        v10 = -(k != 1) - 11;
      else
        v10 = -10;
      StdHandle = GetStdHandle(nStdHandle: v10);
      v12 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v9->osfhnd = v12;
        if ( (unsigned __int8)FileType == 2 )
        {
          v9->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v9->osfile |= 8u;
        }
        if ( __crtInitCritSecAndSpinCount(lpCriticalSection: &v9->lock, dwSpinCount: 0xFA0u) == 0 )
          return -1;
        ++v9->lockinitflag;
      }
      else
      {
        v9->osfile |= 0x40u;
        v9->osfhnd = -2;
      }
    }
    else
    {
      v9->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B4CE
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0040B4F2
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Terminate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0040B516
// Name: ___security_init_cookie
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __security_init_cookie()
{
  unsigned int v0; // esi
  DWORD v1; // esi
  DWORD v2; // esi
  DWORD v3; // esi
  uintptr_t v4; // esi
  _LARGE_INTEGER perfctr; // [esp+8h] [ebp-10h] BYREF
  FT systime; // [esp+10h] [ebp-8h] BYREF

  systime.ft_scalar = 0;
  if ( __security_cookie == -1153374642 || (__security_cookie & 0xFFFF0000) == 0 )
  {
    GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&systime);
    v0 = systime.ft_struct.dwLowDateTime ^ systime.ft_struct.dwHighDateTime;
    v1 = GetCurrentProcessId() ^ v0;
    v2 = GetCurrentThreadId() ^ v1;
    v3 = GetTickCount() ^ v2;
    QueryPerformanceCounter(lpPerformanceCount: &perfctr);
    v4 = perfctr.LowPart ^ perfctr.HighPart ^ v3;
    if ( v4 == -1153374642 )
    {
      v4 = -1153374641;
    }
    else if ( (v4 & 0xFFFF0000) == 0 )
    {
      v4 |= v4 << 16;
    }
    __security_cookie = v4;
    __security_cookie_complement = ~v4;
  }
  else
  {
    __security_cookie_complement = ~__security_cookie;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B5AA
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x0040B5B0
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)_calloc_crt(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)_calloc_crt(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&__security_cookie )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_418840;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_4188A0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B661
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x0040B681
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_418A90 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B6BD
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B6EB
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_418A90 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B721
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B74B
// Name: __stbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stbuf(_iobuf *str)
{
  int v1; // eax
  int v2; // eax
  char **v3; // edi
  char *v4; // eax
  char *v5; // edi

  v1 = _fileno(stream: str);
  if ( _isatty(fh: v1) == 0 )
    return 0;
  if ( str == &__iob_func()[1] )
  {
    v2 = 0;
  }
  else
  {
    if ( str != &__iob_func()[2] )
      return 0;
    v2 = 1;
  }
  ++_cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0;
  v3 = (char **)(4 * v2 + 4307096);
  if ( _stdbuf[v2] != nullptr || (v4 = (char *)_malloc_crt(size: 0x1000u), *v3 = v4, v4 != nullptr) )
  {
    v5 = *v3;
    str->_base = v5;
    str->_ptr = v5;
    str->_bufsiz = 4096;
    str->_cnt = 4096;
  }
  else
  {
    str->_base = (char *)&str->_charbuf;
    str->_ptr = (char *)&str->_charbuf;
    str->_bufsiz = 2;
    str->_cnt = 2;
  }
  str->_flag |= 0x1102u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B7E1
// Name: __ftbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ftbuf(int flag, _iobuf *str)
{
  if ( flag != 0 && (str->_flag & 0x1000) != 0 )
  {
    _flush(str);
    str->_flag &= 0xFFFFEEFF;
    str->_bufsiz = 0;
    str->_ptr = nullptr;
    str->_base = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B810
// Name: wfindenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall wfindenv@<eax>(unsigned int len@<edi>, const wchar_t *name)
{
  const wchar_t **i; // esi
  wchar_t v3; // ax

  for ( i = (const wchar_t **)_wenviron; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_wenviron) >> 2);
    if ( _wcsnicoll(_string1: name, _string2: *i, count: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_wenviron) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0040B861
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 **__usercall copy_environ@<eax>(unsigned __int16 **oldenviron@<edi>)
{
  unsigned __int16 **result; // eax
  unsigned __int16 **v2; // ecx
  unsigned __int16 **v3; // esi
  unsigned __int16 *v4; // eax
  unsigned __int16 **v5; // ebx
  unsigned __int16 **newenviron; // [esp+0h] [ebp-4h]

  result = nullptr;
  v2 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v2;
        result = (unsigned __int16 **)((char *)result + 1);
      }
      while ( *v2 != nullptr );
    }
    v3 = (unsigned __int16 **)_calloc_crt(count: (unsigned int)result + 1, size: 4u);
    newenviron = v3;
    if ( v3 == nullptr )
      _amsg_exit(rterrnum: 9);
    v4 = *oldenviron;
    v5 = oldenviron;
    while ( v4 != nullptr )
    {
      *v3++ = _wcsdup();
      v4 = *++v5;
    }
    *v3 = nullptr;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B8BE
// Name: ___crtwsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtwsetenv@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        unsigned __int16 **poption,
        int primary)
{
  const wchar_t *v5; // edi
  unsigned __int16 *v6; // eax
  unsigned __int16 *v7; // ebx
  unsigned __int16 **v8; // eax
  char **v9; // eax
  unsigned __int16 **v10; // eax
  int v11; // eax
  unsigned int v12; // ebx
  char *v13; // edi
  unsigned __int16 **v14; // eax
  unsigned int v15; // eax
  unsigned __int16 *v16; // edi
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned __int16 *v21; // ebx
  const wchar_t *v22; // ebx
  unsigned int v23; // eax
  char *v24; // eax
  unsigned int v25; // eax
  char *v26; // eax
  char *c_name; // [esp+8h] [ebp-18h]
  char *c_namea; // [esp+8h] [ebp-18h]
  unsigned int c_value; // [esp+Ch] [ebp-14h]
  char *c_valuea; // [esp+Ch] [ebp-14h]
  int size; // [esp+10h] [ebp-10h]
  int sizea; // [esp+10h] [ebp-10h]
  BOOL remove; // [esp+14h] [ebp-Ch]
  unsigned __int16 *option; // [esp+18h] [ebp-8h]
  int retval; // [esp+1Ch] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  v5 = *poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_13;
  v6 = wcschr(string: v5, ch: 0x3Du);
  v7 = v6;
  if ( v6 == nullptr || v5 == v6 )
    goto LABEL_13;
  remove = v6[1] == 0;
  v8 = _wenviron;
  if ( _wenviron == __winitenv )
  {
    v8 = copy_environ(oldenviron: _wenviron);
    v5 = option;
    _wenviron = v8;
  }
  if ( v8 == nullptr )
  {
    if ( primary != 0 && _environ != nullptr )
    {
      _wenvptr = (wchar_t *)__crtGetEnvironmentStringsW();
      if ( _wsetenvp() < 0 && __mbtow_environ() != 0 )
      {
LABEL_13:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove )
        return 0;
      if ( _environ != nullptr )
        goto LABEL_19;
      v9 = (char **)_malloc_crt(size: 4u);
      _environ = v9;
      if ( v9 == nullptr )
        return -1;
      *v9 = nullptr;
      if ( _wenviron == nullptr )
      {
LABEL_19:
        v10 = (unsigned __int16 **)_malloc_crt(size: 4u);
        _wenviron = v10;
        if ( v10 == nullptr )
          return -1;
        *v10 = nullptr;
      }
    }
  }
  c_name = (char *)_wenviron;
  if ( _wenviron == nullptr )
    return -1;
  c_value = v7 - v5;
  v11 = wfindenv(len: c_value, name: v5);
  v12 = v11;
  if ( v11 < 0 || *(_DWORD *)c_name == 0 )
  {
    if ( !remove )
    {
      if ( v11 < 0 )
        v12 = -v11;
      if ( (int)(v12 + 2) <= (int)v12 )
        return -1;
      if ( v12 + 2 >= 0x3FFFFFFF )
        return -1;
      v14 = (unsigned __int16 **)_recalloc_crt(ptr: _wenviron, count: 4u, size: v12 + 2);
      if ( v14 == nullptr )
        return -1;
      v12 = (unsigned int)&v14[v12];
      *(_DWORD *)v12 = option;
      *(_DWORD *)(v12 + 4) = 0;
      *poption = nullptr;
      goto LABEL_38;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v13 = &c_name[4 * v11];
  free(pMem: *(void **)v13);
  if ( !remove )
  {
    *(_DWORD *)v13 = option;
    *poption = nullptr;
    goto LABEL_39;
  }
  while ( *(_DWORD *)v13 != 0 )
  {
    *(_DWORD *)v13 = *((_DWORD *)v13 + 1);
    ++v12;
    v13 = &c_name[4 * v12];
  }
  if ( v12 < 0x3FFFFFFF )
  {
    v14 = (unsigned __int16 **)_recalloc_crt(ptr: _wenviron, count: v12, size: 4u);
    if ( v14 != nullptr )
LABEL_38:
      _wenviron = v14;
  }
LABEL_39:
  if ( primary != 0 )
  {
    v15 = wcslen(wcs: option);
    v16 = (unsigned __int16 *)_calloc_crt(count: v15 + 2, size: 2u);
    if ( v16 != nullptr )
    {
      v17 = wcslen(wcs: option);
      v18 = wcscpy_s(_Dst: v16, _SizeInWords: v17 + 2, _Src: option);
      if ( v18 != 0 )
        _invoke_watson(a1: v18, a2: v19, a3: v20, a4: v12, a5: (unsigned int)v16, a6: 0);
      v21 = &v16[c_value];
      *v21 = 0;
      v22 = v21 + 1;
      if ( f_use == 1 && !SetEnvironmentVariableW(lpName: v16, lpValue: !remove ? v22 : nullptr) )
      {
        if ( GetLastError() == 120 )
        {
          f_use = 0;
          goto LABEL_49;
        }
        retval = -1;
      }
      if ( f_use != 0 )
      {
LABEL_61:
        if ( retval == -1 )
          *_errno() = 42;
        free(pMem: v16);
        goto LABEL_64;
      }
LABEL_49:
      c_namea = nullptr;
      c_valuea = nullptr;
      v23 = WideCharToMultiByte(
              CodePage: 0,
              dwFlags: 0,
              lpWideCharStr: v16,
              cchWideChar: -1,
              lpMultiByteStr: nullptr,
              cbMultiByte: 0,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
      size = v23;
      if ( v23 != 0 )
      {
        v24 = (char *)_calloc_crt(count: v23, size: 1u);
        c_namea = v24;
        if ( v24 != nullptr
          && WideCharToMultiByte(
               CodePage: 0,
               dwFlags: 0,
               lpWideCharStr: v16,
               cchWideChar: -1,
               lpMultiByteStr: v24,
               cbMultiByte: size,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: nullptr) != 0 )
        {
          if ( remove )
            goto LABEL_57;
          v25 = WideCharToMultiByte(
                  CodePage: 0,
                  dwFlags: 0,
                  lpWideCharStr: v22,
                  cchWideChar: -1,
                  lpMultiByteStr: nullptr,
                  cbMultiByte: 0,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          sizea = v25;
          if ( v25 != 0 )
          {
            v26 = (char *)_calloc_crt(count: v25, size: 1u);
            c_valuea = v26;
            if ( v26 != nullptr )
            {
              if ( WideCharToMultiByte(
                     CodePage: 0,
                     dwFlags: 0,
                     lpWideCharStr: v22,
                     cchWideChar: -1,
                     lpMultiByteStr: v26,
                     cbMultiByte: sizea,
                     lpDefaultChar: nullptr,
                     lpUsedDefaultChar: nullptr) == 0 )
                retval = -1;
LABEL_57:
              if ( retval == -1 || SetEnvironmentVariableA(lpName: c_namea, lpValue: !remove ? c_valuea : nullptr) )
                goto LABEL_60;
            }
          }
        }
      }
      retval = -1;
LABEL_60:
      free(pMem: c_valuea);
      free(pMem: c_namea);
      goto LABEL_61;
    }
  }
LABEL_64:
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0040BC24
// Name: _wcslen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // eax
  __int16 v2; // cx

  v1 = wcs;
  do
    v2 = *v1++;
  while ( v2 != 0 );
  return v1 - wcs - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040BC3A
// Name: findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall findenv@<eax>(unsigned int len@<edi>, const char *name)
{
  const unsigned __int8 **i; // esi
  unsigned __int8 v3; // al

  for ( i = (const unsigned __int8 **)_environ; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_environ) >> 2);
    if ( _mbsnbicoll(a1: len, a2: (unsigned int)i, s1: (const unsigned __int8 *)name, s2: *i, n: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_environ) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0040BC87
// Name: copy_environ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall copy_environ_0@<eax>(char **oldenviron@<edi>)
{
  char **result; // eax
  char **v2; // ecx
  char **v3; // esi
  char *v4; // eax
  char **v5; // ebx
  char **newenviron; // [esp+0h] [ebp-4h]

  result = nullptr;
  v2 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v2;
        result = (char **)((char *)result + 1);
      }
      while ( *v2 != nullptr );
    }
    v3 = (char **)_calloc_crt(count: (unsigned int)result + 1, size: 4u);
    newenviron = v3;
    if ( v3 == nullptr )
      _amsg_exit(rterrnum: 9);
    v4 = *oldenviron;
    v5 = oldenviron;
    while ( v4 != nullptr )
    {
      *v3++ = _strdup(string: v4);
      v4 = *++v5;
    }
    *v3 = nullptr;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BCE4
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtsetenv@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, char **poption, int primary)
{
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // eax
  bool v7; // zf
  char **v8; // eax
  char **v9; // eax
  unsigned __int16 **v10; // eax
  char **v11; // esi
  int v12; // eax
  unsigned int v13; // edi
  char **v14; // esi
  char **v15; // eax
  char **v16; // ecx
  int v17; // eax
  char *v18; // edi
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // edx
  unsigned int v22; // ecx
  const char *v23; // eax
  char **env; // [esp+8h] [ebp-14h]
  int retval; // [esp+Ch] [ebp-10h]
  const char *equal; // [esp+10h] [ebp-Ch]
  int remove; // [esp+14h] [ebp-8h]
  char *option; // [esp+18h] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    return -1;
  }
  v5 = (const unsigned __int8 *)*poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_12;
  v6 = _mbschr(string: v5, c: 0x3Du);
  equal = (const char *)v6;
  if ( v6 == nullptr || v5 == v6 )
    goto LABEL_12;
  v7 = v6[1] == 0;
  v8 = _environ;
  remove = v7;
  if ( _environ == __initenv )
  {
    v8 = copy_environ_0(oldenviron: _environ);
    _environ = v8;
  }
  if ( v8 == nullptr )
  {
    if ( primary != 0 && _wenviron != nullptr )
    {
      if ( __wtomb_environ() != 0 )
      {
LABEL_12:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove != 0 )
        return 0;
      v9 = (char **)_malloc_crt(size: 4u);
      _environ = v9;
      if ( v9 == nullptr )
        return -1;
      *v9 = nullptr;
      if ( _wenviron == nullptr )
      {
        v10 = (unsigned __int16 **)_malloc_crt(size: 4u);
        _wenviron = v10;
        if ( v10 == nullptr )
          return -1;
        *v10 = nullptr;
      }
    }
  }
  v11 = _environ;
  env = _environ;
  if ( _environ == nullptr )
    return -1;
  v12 = findenv(len: equal - option, name: option);
  v13 = v12;
  if ( v12 < 0 || *v11 == nullptr )
  {
    if ( remove == 0 )
    {
      if ( v12 < 0 )
        v13 = -v12;
      if ( (int)(v13 + 2) <= (int)v13 )
        return -1;
      if ( v13 + 2 >= 0x3FFFFFFF )
        return -1;
      v15 = (char **)_recalloc_crt(ptr: _environ, count: 4u, size: v13 + 2);
      if ( v15 == nullptr )
        return -1;
      v16 = &v15[v13];
      *v16 = option;
      v16[1] = nullptr;
      *poption = nullptr;
      goto LABEL_36;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v14 = &v11[v12];
  free(pMem: *v14);
  if ( remove == 0 )
  {
    *v14 = option;
    *poption = nullptr;
    goto LABEL_37;
  }
  while ( *v14 != nullptr )
  {
    *v14 = v14[1];
    v14 = &env[++v13];
  }
  if ( v13 < 0x3FFFFFFF )
  {
    v15 = (char **)_recalloc_crt(ptr: _environ, count: v13, size: 4u);
    if ( v15 == nullptr )
      goto LABEL_37;
LABEL_36:
    _environ = v15;
  }
LABEL_37:
  if ( primary != 0 )
  {
    strlen(buf: option);
    v18 = (char *)_calloc_crt(count: v17 + 2, size: 1u);
    if ( v18 != nullptr )
    {
      strlen(buf: option);
      v20 = strcpy_s(a1: (unsigned int)v18, _Dst: v18, _SizeInBytes: v19 + 2, _Src: option);
      if ( v20 != 0 )
        _invoke_watson(a1: v20, a2: v21, a3: v22, a4: 0, a5: (unsigned int)v18, a6: (unsigned int)option);
      v23 = &equal[v18 - option];
      *v23 = 0;
      if ( !SetEnvironmentVariableA(lpName: v18, lpValue: remove == 0 ? v23 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pMem: v18);
    }
  }
  if ( remove != 0 )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0040BF30
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbschr_l(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        char *string,
        unsigned int c,
        localeinfo_struct *plocinfo)
{
  char *v5; // eax
  unsigned __int16 v6; // cx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v5 = string;
  if ( string != nullptr )
  {
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      while ( 1 )
      {
        v6 = (unsigned __int8)*v5;
        if ( *v5 == 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) != 0 )
        {
          if ( *++v5 == 0 )
            goto LABEL_17;
          if ( c == ((unsigned __int8)*v5 | (v6 << 8)) )
            goto LABEL_15;
        }
        else if ( c == (unsigned __int8)*v5 )
        {
          break;
        }
        ++v5;
      }
      if ( c == (unsigned __int8)*v5 )
        goto LABEL_15;
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      strchr(string, chr: c);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BFEA
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbschr(unsigned int a1@<edi>, unsigned int a2@<esi>, char *string, unsigned int c)
{
  _mbschr_l(a1, a2, string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040BFFD
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getdrive()
{
  unsigned __int8 *v0; // ebx
  signed int CurrentDirectoryA; // esi
  char *v2; // eax
  int v3; // edi
  int memfree; // [esp+10h] [ebp-7Ch]
  char curdirstr[264]; // [esp+14h] [ebp-78h] BYREF

  memfree = 0;
  v0 = (unsigned __int8 *)curdirstr;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryA > 260 )
  {
    v2 = (char *)_calloc_crt(count: CurrentDirectoryA + 1, size: 1u);
    v0 = (unsigned __int8 *)v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: CurrentDirectoryA + 1, lpBuffer: v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryA = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryA != 0 )
  {
    if ( v0[1] == 58 )
      v3 = toupper(c: *v0) - 64;
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040C0C3
// Name: comexecmd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall comexecmd@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        int mode,
        const char *name,
        const char *const *argv,
        const char *const *envp)
{
  int v7; // esi
  char *envblk; // [esp+4h] [ebp-8h] BYREF
  char *argblk; // [esp+8h] [ebp-4h] BYREF

  if ( name == nullptr || argv == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  if ( _cenvarg(argv, envp, &argblk, &envblk, name) == -1 )
    return -1;
  v7 = _dospawn(mode, name, cmdblk: argblk, envblk);
  free(pMem: argblk);
  free(pMem: envblk);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0040C13B
// Name: __spawnve
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _spawnve@<eax>(
        unsigned int a1@<esi>,
        int mode,
        char *name,
        const char *const *argv,
        const char *const *envp)
{
  const char *v5; // edi
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // eax
  const unsigned __int8 *v9; // eax
  int v10; // eax
  unsigned int v11; // esi
  char *v12; // eax
  char *v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // edx
  unsigned int v19; // ecx
  int v20; // eax
  unsigned int v21; // esi
  char *v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // ecx
  int v26; // eax
  char *v27; // edi
  unsigned int v28; // esi
  unsigned int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // ecx
  int save_errno; // [esp+8h] [ebp-14h]
  int rc; // [esp+Ch] [ebp-10h]
  const char **v34; // [esp+10h] [ebp-Ch]
  char *p; // [esp+14h] [ebp-8h]
  char *pathname; // [esp+18h] [ebp-4h]

  v5 = name;
  pathname = name;
  if ( name == nullptr || *name == 0 || argv == nullptr || *argv == nullptr || **(_BYTE **)argv == 0 )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)name, a3: a1);
    return -1;
  }
  v7 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x5Cu);
  v8 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Fu);
  if ( v8 != nullptr )
  {
    if ( v7 == nullptr || v8 > v7 )
      v7 = v8;
  }
  else if ( v7 == nullptr )
  {
    _mbschr(a1: (unsigned int)name, a2: 0, string: name, c: 0x3Au);
    v7 = v9;
    if ( v9 == nullptr )
    {
      strlen(buf: name);
      v11 = v10 + 3;
      v12 = (char *)_calloc_crt(count: v10 + 3, size: 1u);
      v13 = v12;
      pathname = v12;
      if ( v12 == nullptr )
        return -1;
      v14 = strcpy_s(a1: (unsigned int)v12, _Dst: v12, _SizeInBytes: v11, _Src: ".\\");
      if ( v14 != 0 )
        _invoke_watson(a1: v14, a2: v15, a3: v16, a4: 0, a5: (unsigned int)v13, a6: v11);
      v17 = strcat_s(_Dst: v13, _SizeInBytes: v11, _Src: name);
      if ( v17 != 0 )
        _invoke_watson(a1: v17, a2: v18, a3: v19, a4: 0, a5: (unsigned int)v13, a6: v11);
      v7 = (const unsigned __int8 *)(v13 + 2);
      v5 = name;
    }
  }
  rc = -1;
  if ( _mbsrchr(str: v7, c: 0x2Eu) == nullptr )
  {
    strlen(buf: pathname);
    v21 = v20 + 5;
    v22 = (char *)_calloc_crt(count: v20 + 5, size: 1u);
    p = v22;
    if ( v22 != nullptr )
    {
      v23 = strcpy_s(a1: (unsigned int)v5, _Dst: v22, _SizeInBytes: v21, _Src: pathname);
      if ( v23 != 0 )
        _invoke_watson(a1: v23, a2: v24, a3: v25, a4: 0, a5: (unsigned int)v5, a6: v21);
      strlen(buf: pathname);
      v27 = &p[v26];
      save_errno = *_errno();
      v28 = (unsigned int)&p[v21 - (_DWORD)v27];
      v34 = (const char **)(ext_strings + 12);
      while ( 1 )
      {
        v29 = strcpy_s(a1: (unsigned int)v27, _Dst: v27, _SizeInBytes: v28, _Src: *v34);
        if ( v29 != 0 )
          _invoke_watson(a1: v29, a2: v30, a3: v31, a4: 0, a5: (unsigned int)v27, a6: v28);
        if ( _access_s(path: p, amode: 0) == 0 )
          break;
        if ( (int)--v34 < (int)ext_strings )
          goto LABEL_33;
      }
      *_errno() = save_errno;
      rc = comexecmd(a1: 0, a2: (unsigned int)v27, mode, name: p, argv, envp);
LABEL_33:
      free(pMem: p);
      v5 = name;
      goto LABEL_34;
    }
    return -1;
  }
  if ( _access_s(path: pathname, amode: 0) == 0 )
    rc = comexecmd(a1: 0, a2: (unsigned int)v5, mode, name: pathname, argv, envp);
LABEL_34:
  if ( pathname != v5 )
    free(pMem: pathname);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x0040C35A
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040C3EE
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _close@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 4312448, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x0040C4BB
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fileno@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040C4E8
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pMem: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C514
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = _fileno(a1: 0, a2: (unsigned int)v4, stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040C576
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fflush_nolock@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *str)
{
  int v4; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v4 = _fileno(a1, a2, stream: str);
  return -(_commit(filedes: v4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040C5B8
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall flsall@<eax>(unsigned int a1@<ebx>, int flushflag)
{
  int i; // esi
  char **v3; // eax
  char *v4; // eax
  int v5; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v3 = (char **)&__piob[i];
    if ( *v3 != nullptr )
    {
      v4 = *v3;
      if ( (v4[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v4);
        v5 = *((_DWORD *)__piob[i] + 3);
        if ( (v5 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(a1, a2: 0, str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v5 & 2) != 0 && _fflush_nolock(a1, a2: 0, str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C692
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _flushall@<eax>(unsigned int a1@<ebx>)
{
  return flsall(a1, flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0040C69C
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-8h] [ebp-28h]
  int (__cdecl *v8)(int, int, int, int); // [esp-4h] [ebp-24h]

  v8 = unwind_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 == -2 || a3 != -2 && v4 <= a3 )
      break;
    v5 = 3 * v4;
    v6 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 0x10);
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: 1, a2: ExceptionList, a3: v8);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C72C
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind4(a1: *(_DWORD **)(a2 + 20), a2: *(_DWORD *)(a2 + 16), a3: *(_DWORD *)(a2 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C772
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x0040C78E
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x0040C7A5
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040C7BE
// Name: _EH4_GlobalUnwind(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _EH4_GlobalUnwind(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040C7D8
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x0040C7EF
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(uintptr_t StackCookie)
{
  if ( StackCookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x0040C7FE
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CPtoLCID@<eax>(int codepage@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  v1 = codepage - 932;
  if ( v1 == 0 )
    return 1041;
  v2 = v1 - 4;
  if ( v2 == 0 )
    return 2052;
  v3 = v2 - 13;
  if ( v3 == 0 )
    return 1042;
  if ( v3 == 1 )
    return 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040C82D
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  int v1; // ebp
  unsigned __int8 *mbctype; // ebx
  int v4; // eax
  unsigned __int8 *mbcasemap; // ecx
  int i; // esi

  v1 = 257;
  mbctype = ptmbci->mbctype;
  memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  v4 = (char *)&__initialmbcinfo - (char *)ptmbci;
  do
  {
    *mbctype = mbctype[v4];
    ++mbctype;
    --v1;
  }
  while ( v1 != 0 );
  mbcasemap = ptmbci->mbcasemap;
  for ( i = 256; i != 0; --i )
  {
    *mbcasemap = mbcasemap[v4];
    ++mbcasemap;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C882
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBUpLow(threadmbcinfostruct *ptmbci@<esi>)
{
  unsigned int i; // eax
  unsigned __int8 v2; // al
  unsigned __int8 *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned __int8 *v6; // ebx
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int8 v9; // cl
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // dl
  int v13; // [esp+8h] [ebp-80h]
  _cpinfo cpinfo; // [esp+Ch] [ebp-7Ch] BYREF
  unsigned __int16 wVector[256]; // [esp+20h] [ebp-68h] BYREF
  unsigned __int8 upVector[256]; // [esp+220h] [ebp+198h] BYREF
  unsigned __int8 lowVector[256]; // [esp+320h] [ebp+298h] BYREF
  unsigned __int8 sbVector[256]; // [esp+420h] [ebp+398h] BYREF

  if ( GetCPInfo(CodePage: ptmbci->mbcodepage, lpCPInfo: &cpinfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      sbVector[i] = i;
    v2 = cpinfo.LeadByte[0];
    sbVector[0] = 32;
    if ( cpinfo.LeadByte[0] != 0 )
    {
      v3 = &cpinfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset(dst: (int)&sbVector[v4], value: (unsigned __int8 *)0x20, count: v5 - v4 + 1);
        v6 = v3 + 1;
        v2 = *v6;
        v3 = v6 + 1;
      }
      while ( v2 != 0 );
    }
    __crtGetStringTypeA(
      plocinfo: nullptr,
      dwInfoType: 1u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpCharType: wVector,
      code_page: ptmbci->mbcodepage,
      lcid: ptmbci->mblcid,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x100u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)lowVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x200u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)upVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    v7 = 0;
    while ( 1 )
    {
      v8 = wVector[v7];
      if ( (v8 & 1) != 0 )
      {
        ptmbci->mbctype[v7 + 1] |= 0x10u;
        v9 = lowVector[v7];
      }
      else
      {
        if ( (v8 & 2) == 0 )
        {
          ptmbci->mbcasemap[v7] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v7 + 1] |= 0x20u;
        v9 = upVector[v7];
      }
      ptmbci->mbcasemap[v7] = v9;
LABEL_16:
      if ( (unsigned int)++v7 >= 0x100 )
        return;
    }
  }
  v10 = 0;
  v13 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v11 = &ptmbci->mbcasemap[v10];
    if ( (unsigned int)&v11[v13 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x10u;
      v12 = v10 + 32;
LABEL_23:
      *v11 = v12;
      goto LABEL_25;
    }
    if ( (unsigned int)&v11[v13] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x20u;
      v12 = v10 - 32;
      goto LABEL_23;
    }
    *v11 = 0;
LABEL_25:
    ++v10;
  }
  while ( v10 < 0x100 );
}

//------------------------------------------------------------------------------
// Address: 0x0040CA0C
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadmbcinfostruct *__cdecl __updatetmbcinfo()
{
  _tiddata *v0; // edi
  threadmbcinfostruct *ptmbcinfo; // esi

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    _lock(locknum: 13);
    ptmbcinfo = v0->ptmbcinfo;
    if ( ptmbcinfo != __ptmbcinfo )
    {
      if ( ptmbcinfo != nullptr
        && InterlockedDecrement(lpAddend: &ptmbcinfo->refcount) == 0
        && ptmbcinfo != &__initialmbcinfo )
      {
        free(pMem: ptmbcinfo);
      }
      v0->ptmbcinfo = __ptmbcinfo;
      ptmbcinfo = __ptmbcinfo;
      InterlockedIncrement(lpAddend: &__ptmbcinfo->refcount);
    }
    _unlock(locknum: 13);
  }
  if ( ptmbcinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptmbcinfo;
}

//------------------------------------------------------------------------------
// Address: 0x0040CAB0
// Name: getSystemCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __usercall getSystemCP@<eax>(int codepage@<esi>)
{
  UINT result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: nullptr);
  fSystemSet = 0;
  switch ( codepage )
  {
    case -2:
      fSystemSet = 1;
      result = GetOEMCP();
      goto LABEL_3;
    case -3:
      fSystemSet = 1;
      result = GetACP();
      goto LABEL_3;
    case -4:
      result = _loc_update.localeinfo.locinfo->lc_codepage;
      fSystemSet = 1;
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    default:
      break;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return codepage;
}

//------------------------------------------------------------------------------
// Address: 0x0040CB2A
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  bool v5; // cc
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // cl
  unsigned int k; // eax
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned __int16 *mbulinfo; // eax
  int v13; // ecx
  unsigned __int16 *v14; // ecx
  int j; // edx
  unsigned __int8 *v16; // eax
  int m; // ecx
  int v18; // edx
  unsigned int irg; // [esp+Ch] [ebp-20h]
  unsigned int icp; // [esp+10h] [ebp-1Ch]
  unsigned int icpa; // [esp+10h] [ebp-1Ch]
  _cpinfo cpinfo; // [esp+14h] [ebp-18h] BYREF
  int codepagea; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(codepage);
  codepagea = SystemCP;
  if ( SystemCP != 0 )
  {
    icp = 0;
    for ( i = 0; i < 5; ++i )
    {
      if ( _rgcode_page_info[i].code_page == SystemCP )
      {
        memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
        irg = 0;
        v9 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v9;
        do
        {
          while ( *v9 != 0 )
          {
            LOBYTE(v10) = v9[1];
            if ( (_BYTE)v10 == 0 )
              break;
            v11 = *v9;
            v10 = (unsigned __int8)v10;
            while ( v11 <= v10 )
            {
              ptmbci->mbctype[v11 + 1] |= _rgctypeflag[irg];
              v10 = v9[1];
              ++v11;
            }
            SystemCP = codepagea;
            v9 += 2;
          }
          ++irg;
          v9 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(codepage: SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v14 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v13);
        for ( j = 6; j != 0; --j )
          *mbulinfo++ = *v14++;
LABEL_26:
        setSBUpLow(ptmbci);
        return 0;
      }
      ++icp;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage(CodePage: (unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(CodePage: SystemCP, lpCPInfo: &cpinfo) )
    {
      memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
      v5 = cpinfo.MaxCharSize <= 1;
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( v5 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] != 0 )
        {
          v6 = &cpinfo.LeadByte[1];
          do
          {
            v7 = *v6;
            if ( *v6 == 0 )
              break;
            for ( k = *(v6 - 1); k <= v7; ++k )
              ptmbci->mbctype[k + 1] |= 4u;
            v6 += 2;
          }
          while ( *(v6 - 1) != 0 );
        }
        v16 = &ptmbci->mbctype[2];
        for ( m = 254; m != 0; --m )
          *v16++ |= 8u;
        ptmbci->mblcid = CPtoLCID(codepage: ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v18;
      }
      *(_DWORD *)ptmbci->mbulinfo = 0;
      *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
      *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
      goto LABEL_26;
    }
    if ( fSystemSet == 0 )
      return -1;
  }
  setSBCS(ptmbci);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CD03
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp(int codepage)
{
  _tiddata *v1; // edi
  threadmbcinfostruct *ptmbcinfo; // ebx
  threadmbcinfostruct *v3; // eax
  threadmbcinfostruct *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int retcode; // [esp+14h] [ebp-20h]
  UINT codepagea; // [esp+3Ch] [ebp+8h]

  retcode = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  ptmbcinfo = v1->ptmbcinfo;
  codepagea = getSystemCP(codepage);
  if ( codepagea == ptmbcinfo->mbcodepage )
    return 0;
  v3 = (threadmbcinfostruct *)_malloc_crt(size: 0x220u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    qmemcpy(v3, v1->ptmbcinfo, sizeof(threadmbcinfostruct));
    v3->refcount = 0;
    v5 = _setmbcp_nolock(codepage: codepagea, ptmbci: v3);
    retcode = v5;
    if ( v5 != 0 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != &__initialmbcinfo )
          free(pMem: v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( InterlockedDecrement(lpAddend: &v1->ptmbcinfo->refcount) == 0 && v1->ptmbcinfo != &__initialmbcinfo )
        free(pMem: v1->ptmbcinfo);
      v1->ptmbcinfo = v4;
      InterlockedIncrement(lpAddend: &v4->refcount);
      if ( (v1->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
      {
        _lock(locknum: 13);
        __mbcodepage = v4->mbcodepage;
        __ismbcodepage = v4->ismbcodepage;
        __mblcid = v4->mblcid;
        for ( i = 0; i < 5; ++i )
          __mbulinfo[i] = v4->mbulinfo[i];
        for ( j = 0; j < 257; ++j )
          _mbctype[j] = v4->mbctype[j];
        for ( k = 0; k < 256; ++k )
          _mbcasemap[k] = v4->mbcasemap[k];
        if ( InterlockedDecrement(lpAddend: &__ptmbcinfo->refcount) == 0 && __ptmbcinfo != &__initialmbcinfo )
          free(pMem: __ptmbcinfo);
        __ptmbcinfo = v4;
        InterlockedIncrement(lpAddend: &v4->refcount);
        _unlock(locknum: 13);
      }
    }
  }
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x0040CE9D
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initmbctable()
{
  if ( __mbctype_initialized == 0 )
  {
    _setmbcp(codepage: -3);
    __mbctype_initialized = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CEBB
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // eax
  int *lconv_intl_refcount; // eax
  int *lconv_mon_refcount; // eax
  int *lconv_num_refcount; // eax
  int *ctype1_refcount; // eax
  __lc_time_data *lc_time_curr; // eax
  void **p_refcount; // edi
  int i; // ebx
  _DWORD *v9; // eax

  lconv = ptloci->lconv;
  if ( lconv != nullptr && lconv != &__lconv_c )
  {
    lconv_intl_refcount = ptloci->lconv_intl_refcount;
    if ( lconv_intl_refcount != nullptr && *lconv_intl_refcount == 0 )
    {
      lconv_mon_refcount = ptloci->lconv_mon_refcount;
      if ( lconv_mon_refcount != nullptr && *lconv_mon_refcount == 0 )
      {
        free(pMem: ptloci->lconv_mon_refcount);
        __free_lconv_mon(l: ptloci->lconv);
      }
      lconv_num_refcount = ptloci->lconv_num_refcount;
      if ( lconv_num_refcount != nullptr && *lconv_num_refcount == 0 )
      {
        free(pMem: ptloci->lconv_num_refcount);
        __free_lconv_num(l: ptloci->lconv);
      }
      free(pMem: ptloci->lconv_intl_refcount);
      free(pMem: ptloci->lconv);
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount != nullptr && *ctype1_refcount == 0 )
  {
    free(pMem: ptloci->ctype1 - 127);
    free(pMem: (void *)(ptloci->pclmap - 128));
    free(pMem: (void *)(ptloci->pcumap - 128));
    free(pMem: ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c && lc_time_curr->refcount == 0 )
  {
    __free_lc_time(lc_time: ptloci->lc_time_curr);
    free(pMem: ptloci->lc_time_curr);
  }
  p_refcount = (void **)&ptloci->lc_category[0].refcount;
  for ( i = 6; i != 0; --i )
  {
    if ( *(p_refcount - 2) != __clocalestr && *p_refcount != nullptr && *(_DWORD *)*p_refcount == 0 )
      free(pMem: *p_refcount);
    if ( *(p_refcount - 1) != nullptr )
    {
      v9 = p_refcount[1];
      if ( v9 != nullptr && *v9 == 0 )
        free(pMem: p_refcount[1]);
    }
    p_refcount += 4;
  }
  free(pMem: ptloci);
}

//------------------------------------------------------------------------------
// Address: 0x0040CFFB
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int i; // ebp

  InterlockedIncrement(lpAddend: &ptloci->refcount);
  if ( ptloci->lconv_intl_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_intl_refcount);
  if ( ptloci->lconv_mon_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_mon_refcount);
  if ( ptloci->lconv_num_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_num_refcount);
  if ( ptloci->ctype1_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->ctype1_refcount);
  p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
  for ( i = 6; i != 0; --i )
  {
    if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
      InterlockedIncrement(lpAddend: *p_refcount);
    if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
      InterlockedIncrement(lpAddend: p_refcount[1]);
    p_refcount += 4;
  }
  InterlockedIncrement(lpAddend: &ptloci->lc_time_curr->refcount);
}

//------------------------------------------------------------------------------
// Address: 0x0040D081
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int i; // ebp

  if ( ptloci != nullptr )
  {
    InterlockedDecrement(lpAddend: &ptloci->refcount);
    if ( ptloci->lconv_intl_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_intl_refcount);
    if ( ptloci->lconv_mon_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_mon_refcount);
    if ( ptloci->lconv_num_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_num_refcount);
    if ( ptloci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->ctype1_refcount);
    p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
    for ( i = 6; i != 0; --i )
    {
      if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
        InterlockedDecrement(lpAddend: *p_refcount);
      if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
        InterlockedDecrement(lpAddend: p_refcount[1]);
      p_refcount += 4;
    }
    InterlockedDecrement(lpAddend: &ptloci->lc_time_curr->refcount);
  }
  return ptloci;
}

//------------------------------------------------------------------------------
// Address: 0x0040D10D
// Name: _updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__usercall updatetlocinfoEx_nolock@<eax>(
        threadlocaleinfostruct **pptlocid@<eax>,
        threadlocaleinfostruct *ptlocis@<edi>)
{
  threadlocaleinfostruct *v2; // esi

  if ( ptlocis == nullptr || pptlocid == nullptr )
    return nullptr;
  v2 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    __addlocaleref(ptloci: ptlocis);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: v2);
      if ( v2->refcount == 0 && v2 != &__initiallocinfo )
        __freetlocinfo(ptloci: v2);
    }
  }
  return ptlocis;
}

//------------------------------------------------------------------------------
// Address: 0x0040D14B
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __updatetlocinfo()
{
  _tiddata *v0; // esi
  threadlocaleinfostruct *ptlocinfo; // esi
  threadlocaleinfostruct *ptloci; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptlocinfo = _getptd()->ptlocinfo;
  }
  else
  {
    _lock(locknum: 12);
    ptloci = updatetlocinfoEx_nolock(pptlocid: &v0->ptlocinfo, ptlocis: __ptlocinfo);
    _unlock(locknum: 12);
    ptlocinfo = ptloci;
  }
  if ( ptlocinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptlocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x0040D1C1
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x0040D1DC
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringA_stat(
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  localeinfo_struct *plocinfo; // ecx
  localeinfo_struct *v9; // esi
  int v10; // ecx
  const char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // eax
  void *v21; // esp
  WCHAR *v22; // esi
  WCHAR *v23; // eax
  int v24; // eax
  int v26; // eax
  wchar_t *v27; // eax
  int v28; // eax
  int v29; // esi
  unsigned int v30; // eax
  void *v31; // esp
  char *v32; // edi
  char *v33; // eax
  _DWORD v34[2]; // [esp+0h] [ebp-20h] BYREF
  int v35; // [esp+8h] [ebp-18h] BYREF
  int AnsiCP; // [esp+Ch] [ebp-14h]
  char *cbuffer2; // [esp+10h] [ebp-10h]
  wchar_t *inwbuffer; // [esp+14h] [ebp-Ch]
  int retval; // [esp+18h] [ebp-8h] BYREF

  v9 = plocinfo;
  if ( f_use_1 == 0 )
  {
    if ( LCMapStringW(Locale: 0, dwMapFlags: 0x100u, lpSrcStr: &String2, cchSrc: 1, lpDestStr: nullptr, cchDest: 0) != 0 )
    {
      f_use_1 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_1 = 2;
    }
  }
  if ( cchSrc > 0 )
  {
    v10 = cchSrc;
    v11 = lpSrcStr;
    while ( 1 )
    {
      --v10;
      if ( *v11 == 0 )
        break;
      ++v11;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    v12 = cchSrc - v10 - 1;
    if ( v12 < cchSrc )
      v12 = cchSrc - v10;
    cchSrc = v12;
  }
  if ( f_use_1 != 2 && f_use_1 != 0 )
  {
    if ( f_use_1 == 1 )
    {
      retval = 0;
      if ( code_page == 0 )
        code_page = v9->locinfo->lc_codepage;
      v13 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 8 * (bError != 0) + 1,
              lpMultiByteStr: lpSrcStr,
              cbMultiByte: cchSrc,
              lpWideCharStr: nullptr,
              cchWideChar: 0);
      v14 = v13;
      if ( v13 != 0 )
      {
        if ( v13 <= 0 || 0xFFFFFFE0 / v13 < 2 )
        {
          inwbuffer = nullptr;
LABEL_30:
          if ( inwbuffer != nullptr )
          {
            if ( MultiByteToWideChar(
                   CodePage: code_page,
                   dwFlags: 1u,
                   lpMultiByteStr: lpSrcStr,
                   cbMultiByte: cchSrc,
                   lpWideCharStr: inwbuffer,
                   cchWideChar: v14) != 0 )
            {
              v18 = LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v14, lpDestStr: nullptr, cchDest: 0);
              v19 = v18;
              retval = v18;
              if ( v18 != 0 )
              {
                if ( (dwMapFlags & 0x400) != 0 )
                {
                  if ( cchDest != 0 && v18 <= cchDest )
                    LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v14, (LPWSTR)lpDestStr, cchDest);
                  goto LABEL_53;
                }
                if ( v18 <= 0 || 0xFFFFFFE0 / v18 < 2 )
                {
                  v22 = nullptr;
LABEL_46:
                  if ( v22 != nullptr )
                  {
                    if ( LCMapStringW(
                           Locale,
                           dwMapFlags,
                           lpSrcStr: inwbuffer,
                           cchSrc: v14,
                           lpDestStr: v22,
                           cchDest: retval) != 0 )
                    {
                      if ( cchDest != 0 )
                        v24 = WideCharToMultiByte(
                                CodePage: code_page,
                                dwFlags: 0,
                                lpWideCharStr: v22,
                                cchWideChar: retval,
                                lpMultiByteStr: lpDestStr,
                                cbMultiByte: cchDest,
                                lpDefaultChar: nullptr,
                                lpUsedDefaultChar: nullptr);
                      else
                        v24 = WideCharToMultiByte(
                                CodePage: code_page,
                                dwFlags: 0,
                                lpWideCharStr: v22,
                                cchWideChar: retval,
                                lpMultiByteStr: nullptr,
                                cbMultiByte: 0,
                                lpDefaultChar: nullptr,
                                lpUsedDefaultChar: nullptr);
                      retval = v24;
                    }
                    _freea(_Memory: v22);
                  }
                  goto LABEL_53;
                }
                v20 = 2 * v18 + 8;
                if ( v20 > 0x400 )
                {
                  v23 = (WCHAR *)_malloc_crt(size: 2 * v19 + 8);
                  if ( v23 != nullptr )
                  {
                    *(_DWORD *)v23 = 56797;
                    v23 += 4;
                  }
                  v22 = v23;
                  goto LABEL_46;
                }
                v21 = alloca(v20);
                if ( v34 != nullptr )
                {
                  v34[0] = 52428;
                  v22 = (WCHAR *)&v35;
                  goto LABEL_46;
                }
              }
            }
LABEL_53:
            _freea(_Memory: inwbuffer);
            return retval;
          }
          return 0;
        }
        v15 = 2 * v13 + 8;
        if ( v15 > 0x400 )
        {
          v17 = (wchar_t *)_malloc_crt(size: 2 * v14 + 8);
          if ( v17 != nullptr )
          {
            *(_DWORD *)v17 = 56797;
            goto LABEL_27;
          }
        }
        else
        {
          v16 = alloca(v15);
          v17 = (wchar_t *)v34;
          if ( v34 != nullptr )
          {
            v34[0] = 52428;
LABEL_27:
            v17 += 4;
          }
        }
        inwbuffer = v17;
        goto LABEL_30;
      }
    }
    return 0;
  }
  inwbuffer = nullptr;
  cbuffer2 = nullptr;
  if ( Locale == 0 )
    Locale = v9->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v9->locinfo->lc_codepage;
  v26 = __ansicp(lcid: Locale);
  AnsiCP = v26;
  if ( v26 == -1 )
    return 0;
  if ( v26 == code_page )
  {
    v29 = LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest);
    goto LABEL_78;
  }
  v27 = (wchar_t *)__convertcp(fromCP: code_page, toCP: v26, lpSrcStr, pcchSrc: &cchSrc, lpDestStr: nullptr, cchDest: 0);
  inwbuffer = v27;
  if ( v27 == nullptr )
    return 0;
  v28 = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)v27, cchSrc, lpDestStr: nullptr, cchDest: 0);
  retval = v28;
  if ( v28 != 0 )
  {
    if ( v28 <= 0 )
    {
      v32 = nullptr;
    }
    else
    {
      v30 = v28 + 8;
      if ( v30 > 0x400 )
      {
        v33 = (char *)_malloc_crt(size: v30);
        if ( v33 != nullptr )
        {
          *(_DWORD *)v33 = 56797;
          v33 += 8;
        }
        v32 = v33;
      }
      else
      {
        v31 = alloca(v30);
        if ( v34 == nullptr )
          goto LABEL_63;
        v34[0] = 52428;
        v32 = (char *)&v35;
      }
    }
    if ( v32 != nullptr )
    {
      memset(dst: (int)v32, value: nullptr, count: retval);
      retval = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)inwbuffer, cchSrc, lpDestStr: v32, cchDest: retval);
      if ( retval != 0 )
      {
        cbuffer2 = __convertcp(fromCP: AnsiCP, toCP: code_page, lpSrcStr: v32, pcchSrc: &retval, lpDestStr, cchDest);
        v29 = cbuffer2 != nullptr ? retval : 0;
      }
      else
      {
        v29 = 0;
      }
      _freea(_Memory: v32);
      goto LABEL_78;
    }
  }
LABEL_63:
  v29 = 0;
LABEL_78:
  if ( inwbuffer != nullptr )
    free(pMem: inwbuffer);
  if ( cbuffer2 != nullptr && lpDestStr != cbuffer2 )
    free(pMem: cbuffer2);
  return v29;
}

//------------------------------------------------------------------------------
// Address: 0x0040D57E
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, code_page, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D5C1
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D5F7
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040D605
// Name: __isctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_l(int c, int mask, localeinfo_struct *plocinfo)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char buffer[4]; // [esp+14h] [ebp-8h] BYREF
  unsigned __int16 chartype; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = c;
  if ( (unsigned int)(c + 1) <= 0x100 )
  {
    v4 = _loc_update.localeinfo.locinfo->pctype[c];
    goto LABEL_11;
  }
  ca = c >> 8;
  if ( _isleadbyte_l(c: HIBYTE(v3), plocinfo: &_loc_update.localeinfo) != 0 )
  {
    buffer[0] = ca;
    buffer[1] = v3;
    buffer[2] = 0;
    v5 = 2;
  }
  else
  {
    buffer[0] = v3;
    buffer[1] = 0;
    v5 = 1;
  }
  if ( __crtGetStringTypeA(
         plocinfo: &_loc_update.localeinfo,
         dwInfoType: 1u,
         lpSrcStr: buffer,
         cchSrc: v5,
         lpCharType: &chartype,
         code_page: _loc_update.localeinfo.locinfo->lc_codepage,
         lcid: _loc_update.localeinfo.locinfo->lc_handle[2],
         bError: 1) != 0 )
  {
    v4 = chartype;
LABEL_11:
    result = mask & v4;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040D6C0
// Name: __fltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _fltin2(
        _flt *flt,
        const char *str,
        int len_ignore,
        int scale_ignore,
        int radix_ignore,
        localeinfo_struct *_Locale)
{
  int v6; // ebx
  INTRNCVT_STATUS v7; // eax
  const char *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const char *v10; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v10 = str;
  v6 = 0;
  flags = __strgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v6 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v7 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v7 == INTRNCVT_OVERFLOW )
      v6 = 128;
    if ( (flags & 1) != 0 || v7 == INTRNCVT_UNDERFLOW )
      v6 |= 0x100u;
  }
  flt->nbytes = EndPtr - v10;
  flt->dval = x.x;
  flt->flags = v6;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x0040D765
// Name: ___strgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __strgtold12_l(
        _LDBL12 *pld12,
        const char **p_end_ptr,
        const char *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  char *v9; // edi
  const char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  const char *v16; // edx
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  _LDBL12 *v24; // esi
  char v25; // al
  int v26; // eax
  _LDBL12 *v27; // eax
  _LDBL12 *v28; // ebx
  __int16 v29; // dx
  __int16 v30; // ax
  unsigned __int16 v31; // dx
  __int16 v32; // ax
  unsigned __int16 v33; // di
  int v34; // eax
  _WORD *v35; // esi
  unsigned int v36; // ecx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  __int16 v39; // di
  unsigned int v40; // ecx
  int v41; // esi
  int v42; // ecx
  int v43; // esi
  unsigned int v44; // ecx
  int v45; // ebx
  int v46; // ecx
  __int16 v47; // cx
  int v48; // esi
  unsigned int v49; // edx
  __int16 v50; // ax
  int v51; // [esp-4h] [ebp-8Ch]
  int v52; // [esp-4h] [ebp-8Ch]
  int v53; // [esp+10h] [ebp-78h]
  __int16 man_sign; // [esp+14h] [ebp-74h]
  _LDBL12 *v55; // [esp+18h] [ebp-70h]
  unsigned int result_flags; // [esp+1Ch] [ebp-6Ch]
  int exp_sign; // [esp+20h] [ebp-68h]
  int exp_signa; // [esp+20h] [ebp-68h]
  int pow; // [esp+24h] [ebp-64h]
  int powa; // [esp+24h] [ebp-64h]
  int found_exponent; // [esp+28h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+28h] [ebp-60h]
  int found_decpoint; // [esp+2Ch] [ebp-5Ch]
  unsigned __int8 *found_decpointa; // [esp+2Ch] [ebp-5Ch]
  int found_digit; // [esp+30h] [ebp-58h]
  int found_digita; // [esp+30h] [ebp-58h]
  const char *savedp; // [esp+34h] [ebp-54h]
  int savedpa; // [esp+34h] [ebp-54h]
  int exp_adj; // [esp+38h] [ebp-50h]
  int exp_adja; // [esp+38h] [ebp-50h]
  unsigned int manlen; // [esp+3Ch] [ebp-4Ch]
  unsigned int manlena; // [esp+3Ch] [ebp-4Ch]
  __int64 v73; // [esp+40h] [ebp-48h] BYREF
  int v74; // [esp+48h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+4Ch] [ebp-3Ch] BYREF
  _BYTE v76[12]; // [esp+5Ch] [ebp-2Ch] BYREF
  char buf[28]; // [esp+68h] [ebp-20h] BYREF

  v8 = 0;
  v9 = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)buf, a3: 1u);
    return 0;
  }
  v11 = str;
  savedp = str;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( v14 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( v15 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_75;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_33;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (v13 <= 99 || v13 > 101) )
          goto LABEL_75;
        v52 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v51 = 3;
LABEL_12:
          v8 = v51;
          --v11;
        }
        else
        {
          if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v52 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_37:
            v16 = savedp;
            goto LABEL_82;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            ++manlen;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_46;
LABEL_24:
        v52 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( v13 == 48 )
          {
            --exp_adj;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            *v9++ = v13 - 48;
            --exp_adj;
          }
          v13 = *v11++;
        }
LABEL_46:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_33:
        --v11;
        v52 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_37;
        v51 = 4;
        goto LABEL_12;
      case 6:
        savedp = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v17 = v13 - 43;
        if ( v17 == 0 )
          goto LABEL_70;
        v18 = v17 - 2;
        if ( v18 == 0 )
          goto LABEL_69;
        v19 = v18 == 3;
LABEL_67:
        if ( !v19 )
          goto LABEL_37;
        v52 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v19 = v13 == 48;
        goto LABEL_67;
      case 8:
        found_exponent = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_75;
LABEL_63:
        v51 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v21 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v21 = 10 * v21 + v13 - 48;
            if ( v21 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v21 = 5201;
          }
          break;
        }
        pow = v21;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_75:
        v16 = v11 - 1;
        goto LABEL_82;
      case 11:
        if ( implicit_E != 0 )
        {
          v20 = v13 - 43;
          savedp = v11 - 1;
          if ( v20 != 0 )
          {
            if ( v20 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_82;
            }
LABEL_69:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_70:
            v52 = 7;
LABEL_15:
            v8 = v52;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_82:
        *p_end_ptr = v16;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_174:
          v47 = 0;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_175;
        }
        if ( manlen > 0x18 )
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          --v9;
          ++exp_adj;
          manlen = 24;
        }
        if ( manlen == 0 )
          goto LABEL_174;
        while ( *--v9 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v22 = pow;
        if ( exp_sign < 0 )
          v22 = -pow;
        v23 = exp_adj + v22;
        if ( found_exponent == 0 )
          v23 += scale;
        if ( found_decpoint == 0 )
          v23 -= decpt;
        if ( v23 > 5200 )
        {
          v48 = 0;
          v50 = 0x7FFF;
          v49 = 0x80000000;
          v47 = 0;
          result_flags = 2;
          goto LABEL_175;
        }
        if ( v23 < -5200 )
        {
          result_flags = 1;
          goto LABEL_174;
        }
        v24 = &_pow10pos[-8];
        savedpa = v23;
        if ( v23 != 0 )
        {
          if ( v23 < 0 )
          {
            savedpa = -v23;
            v24 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          while ( savedpa != 0 )
          {
            v25 = savedpa;
            savedpa >>= 3;
            v24 += 7;
            v26 = v25 & 7;
            manlena = (unsigned int)v24;
            if ( v26 != 0 )
            {
              v27 = &v24[v26];
              v28 = v27;
              v55 = v27;
              if ( *(_WORD *)v27->ld12 >= 0x8000u )
              {
                v73 = *(_QWORD *)v27->ld12;
                v74 = *(_DWORD *)&v27->ld12[8];
                --*(_DWORD *)((char *)&v73 + 2);
                v28 = (_LDBL12 *)&v73;
                v55 = (_LDBL12 *)&v73;
              }
              v29 = *(_WORD *)&v28->ld12[10];
              exp_adja = 0;
              memset(v76, 0, sizeof(v76));
              v30 = *(_WORD *)&tmpld12.ld12[10] ^ v29;
              v31 = v29 & 0x7FFF;
              v32 = v30 & 0x8000;
              v33 = v31 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF || v31 >= 0x7FFFu || v33 > 0xBFFDu )
              {
LABEL_167:
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                v34 = v32 != 0 ? -32768 : 2147450880;
                *(_DWORD *)tmpld12.ld12 = 0;
                goto LABEL_168;
              }
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_168:
                *(_DWORD *)&tmpld12.ld12[8] = v34;
                continue;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v33, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v31 != 0
                  || (++v33, (*(_DWORD *)&v28->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v28->ld12[4] != 0
                  || *(_DWORD *)v28->ld12 != 0 )
                {
                  exp_signa = 0;
                  v35 = &v76[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v28->ld12[8];
                    do
                    {
                      v53 = 0;
                      v36 = *(unsigned __int16 *)found_decpointa * *(unsigned __int16 *)found_exponenta;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        v53 = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( v53 != 0 )
                        ++*v35;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    v28 = v55;
                    ++v35;
                    ++exp_signa;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_178;
                  do
                  {
                    if ( *(int *)&v76[8] < 0 )
                      break;
                    v40 = *(_DWORD *)v76;
                    *(_DWORD *)v76 *= 2;
                    v41 = (v40 >> 31) | (2 * *(_DWORD *)&v76[4]);
                    v42 = *(__int64 *)&v76[4] >> 31;
                    --v39;
                    *(_DWORD *)&v76[4] = v41;
                    *(_DWORD *)&v76[8] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_178:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v76[0] & 1) != 0 )
                          ++exp_adja;
                        v44 = *(_DWORD *)&v76[8];
                        *(_DWORD *)&v76[8] >>= 1;
                        v45 = __SPAIR64__(v44, *(unsigned int *)&v76[4]) >> 1;
                        v46 = *(__int64 *)v76 >> 1;
                        --v43;
                        *(_DWORD *)&v76[4] = v45;
                        *(_DWORD *)v76 = v46;
                      }
                      while ( v43 != 0 );
                      if ( exp_adja != 0 )
                        *(_WORD *)v76 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v76 > 0x8000u || (*(_DWORD *)v76 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v76[2] == -1 )
                    {
                      *(_DWORD *)&v76[2] = 0;
                      if ( *(_DWORD *)&v76[6] == -1 )
                      {
                        *(_DWORD *)&v76[6] = 0;
                        if ( *(_WORD *)&v76[10] == 0xFFFF )
                        {
                          *(_WORD *)&v76[10] = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++*(_WORD *)&v76[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v76[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v76[2];
                    }
                  }
                  v24 = (_LDBL12 *)manlena;
                  if ( (unsigned __int16)v39 >= 0x7FFFu )
                    goto LABEL_167;
                  *(_WORD *)tmpld12.ld12 = *(_WORD *)&v76[2];
                  *(_QWORD *)&tmpld12.ld12[2] = *(_QWORD *)&v76[4];
                  *(_WORD *)&tmpld12.ld12[10] = v32 | v39;
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
            }
          }
        }
        v47 = *(_WORD *)tmpld12.ld12;
        v48 = *(_DWORD *)&tmpld12.ld12[2];
        v49 = *(_DWORD *)&tmpld12.ld12[6];
        v50 = *(_WORD *)&tmpld12.ld12[10];
LABEL_175:
        *(_WORD *)pld12->ld12 = v47;
        *(_WORD *)&pld12->ld12[10] = man_sign | v50;
        *(_DWORD *)&pld12->ld12[2] = v48;
        *(_DWORD *)&pld12->ld12[6] = v49;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DE25
// Name: __atodbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atodbl_l(_CRT_DOUBLE *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tod(pld12: &ld12, d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040DECB
// Name: __atoflt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atoflt_l(_CRT_FLOAT *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tof(pld12: &ld12, f: d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040DF71
// Name: __fptostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fptostr(char *buf, unsigned int sizeInBytes, int digits, _strflt *pflt)
{
  _strflt *v4; // ecx
  char *mantissa; // edi
  unsigned int v6; // esi
  int v8; // edx
  int v9; // eax
  char *v10; // eax
  char v11; // cl
  int v12; // eax

  v4 = pflt;
  mantissa = pflt->mantissa;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v6 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter(a1: 0, a2: (unsigned int)mantissa, a3: v6);
    return v6;
  }
  v8 = digits;
  *buf = 0;
  if ( digits <= 0 )
    v9 = 0;
  else
    v9 = digits;
  if ( sizeInBytes <= v9 + 1 )
  {
    *_errno() = 34;
    v6 = 34;
    goto LABEL_3;
  }
  *buf = 48;
  v10 = buf + 1;
  if ( digits > 0 )
  {
    do
    {
      v11 = *mantissa;
      if ( *mantissa != 0 )
        ++mantissa;
      else
        v11 = 48;
      *v10++ = v11;
      --v8;
    }
    while ( v8 > 0 );
    v4 = pflt;
  }
  *v10 = 0;
  if ( v8 >= 0 && *mantissa >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *buf == 49 )
  {
    ++v4->decpt;
  }
  else
  {
    strlen(buf: buf + 1);
    memmove(dst: (unsigned __int8 *)buf, src: (unsigned __int8 *)buf + 1, count: v12 + 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E02E
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __dtold(_LDOUBLE *pld, long double *px)
{
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax
  __int16 v7; // cx
  __int16 v8; // di
  _LDOUBLE *v9; // eax
  __int16 v10; // cx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  unsigned int msb; // [esp+Ch] [ebp-4h]
  __int16 sign; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)px + 3) >> 4) & 0x7FF;
  sign = *((_WORD *)px + 3) & 0x8000;
  v4 = *((_DWORD *)px + 1);
  v5 = *(_DWORD *)px;
  v6 = v4 & 0xFFFFF;
  msb = 0x80000000;
  if ( (_WORD)v3 == 0 )
  {
    if ( v6 == 0 && v5 == 0 )
    {
      v9 = pld;
      v10 = sign;
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_13;
    }
    v7 = 15361;
    msb = 0;
    goto LABEL_9;
  }
  if ( (unsigned __int16)v3 != 2047 )
  {
    v7 = v3 + 15360;
LABEL_9:
    v8 = v7;
    goto LABEL_10;
  }
  v8 = 0x7FFF;
LABEL_10:
  v11 = msb | (v6 << 11) | (v5 >> 21);
  v9 = pld;
  *(_DWORD *)&pld->ld[4] = v11;
  *(_DWORD *)pld->ld = v5 << 11;
  if ( (v11 & 0x80000000) == 0 )
  {
    do
    {
      v12 = *(__int64 *)pld->ld >> 31;
      v13 = 2 * *(_DWORD *)pld->ld;
      --v8;
      *(_DWORD *)&pld->ld[4] = v12;
      *(_DWORD *)pld->ld = v13;
    }
    while ( (v12 & 0x80000000) == 0 );
  }
  v10 = v8 | sign;
LABEL_13:
  *(_WORD *)&v9->ld[8] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x0040E0E9
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  int v5; // eax
  char *v6; // esi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  _BYTE v10[26]; // [esp-Eh] [ebp-4Ah] BYREF
  char *_Dst; // [esp+Ch] [ebp-30h]
  _FloatOutStruct autofos; // [esp+10h] [ebp-2Ch] BYREF
  _LDOUBLE ld; // [esp+2Ch] [ebp-10h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(pld: &ld, px: &x.x);
  v5 = _I10_OUTPUT(ld, ndigits: 17, output_flags: 0, fos: &autofos);
  v6 = _Dst;
  v4->flag = v5;
  v4->sign = autofos.sign;
  v4->decpt = autofos.exp;
  if ( strcpy_s(a1: (unsigned int)v10, _Dst: v6, _SizeInBytes: resultsize, _Src: autofos.man) != 0 )
  {
    memset(v10, 0, 14);
    _invoke_watson(a1: 0, a2: v7, a3: v8, a4: (unsigned int)v4, a5: (unsigned int)v10, a6: (unsigned int)v6);
  }
  v4->mantissa = v6;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040E180
// Name: __alldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldvrm(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  int v5; // esi
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  int result; // eax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v5 = v7 / (unsigned int)v6;
    v8 = (unsigned int)v5 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v5, HIDWORD(v8))
      || (HIDWORD(v8) = (a2 * (unsigned __int64)(unsigned int)v5) >> 32, v8 > a1) )
    {
      --v5;
    }
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    v5 = v4 / (unsigned int)a2;
  }
  result = v5;
  if ( v2 == 1 )
    return -v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E260
// Name: __aullshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __usercall _aullshr@<edx:eax>(unsigned __int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
    return 0;
  else
    return a1 >> a2;
}

//------------------------------------------------------------------------------
// Address: 0x0040E27F
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _fptrap()
{
  _amsg_exit(rterrnum: 2);
}

//------------------------------------------------------------------------------
// Address: 0x0040E288
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _controlfp_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned int *_CurrentState,
        unsigned int newctrl,
        unsigned int mask)
{
  unsigned int v5; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl: 0, mask: 0);
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0x16u, a3: 0);
    return 22;
  }
  else
  {
    v5 = mask & 0xFFF7FFFF;
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl, mask: v5);
    else
      _control87(newctrl, mask: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E2F2
// Name: has_osfxsr_set
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl has_osfxsr_set()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040E342
// Name: __get_sse2_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _get_sse2_info()
{
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4
  int cpu_feature; // [esp+18h] [ebp-4h]

  cpu_feature = 0;
  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
  if ( v1 != v0 )
  {
    __writeeflags(v0);
    _EAX = 0;
    __asm { cpuid }
    _EAX = 1;
    __asm { cpuid }
    cpu_feature = _EDX;
  }
  return (cpu_feature & 0x4000000) != 0 && has_osfxsr_set() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E3A2
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __sse2_available_init()
{
  __sse2_available = _get_sse2_info();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E3AF
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _crt_debugger_hook()
{
  _debugger_hook_dummy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E3B7
// Name: __crtCompareStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _crtCompareStringA_stat(
        localeinfo_struct *plocinfo,
        const char *lpString1,
        unsigned int Locale,
        DWORD dwCmpFlags,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        unsigned int code_page)
{
  int v10; // ecx
  const char *v11; // eax
  int v12; // edx
  LPCCH v13; // eax
  int v14; // ecx
  int result; // eax
  unsigned __int8 *LeadByte; // eax
  unsigned __int8 v17; // dl
  unsigned __int8 *i; // eax
  unsigned __int8 v19; // dl
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  void *v23; // esp
  wchar_t *v24; // eax
  int v25; // eax
  int v26; // ebx
  unsigned int v27; // eax
  void *v28; // esp
  WCHAR *v29; // edi
  WCHAR *v30; // eax
  CHAR *v31; // edi
  char *v32; // ebx
  int v33; // eax
  int v34; // esi
  const CHAR *v35; // eax
  int v36; // esi
  _DWORD v38[2]; // [esp+0h] [ebp-38h] BYREF
  int v39; // [esp+8h] [ebp-30h] BYREF
  int buff_size1; // [esp+Ch] [ebp-2Ch]
  int retcode; // [esp+10h] [ebp-28h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-24h]
  wchar_t *wbuffer1; // [esp+18h] [ebp-20h]
  LPCCH v44; // [esp+1Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+20h] [ebp-18h] BYREF

  lpMultiByteStr = lpString1;
  v44 = lpString2;
  if ( f_use_2 == 0 )
  {
    if ( CompareStringW(Locale: 0, dwCmpFlags: 0, lpString1: &String2, cchCount1: 1, lpString2: &String2, cchCount2: 1) != 0 )
    {
      f_use_2 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_2 = 2;
    }
  }
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0;
  }
  else
  {
    v10 = cchCount1;
    v11 = lpString1;
    while ( 1 )
    {
      --v10;
      if ( *v11 == 0 )
        break;
      ++v11;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    cchCount1 += -1 - v10;
  }
  v12 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0;
  }
  else
  {
    v13 = v44;
    v14 = cchCount2;
    while ( 1 )
    {
      --v14;
      if ( *v13 == 0 )
        break;
      ++v13;
      if ( v14 == 0 )
      {
        v14 = -1;
        break;
      }
    }
    v12 = -1 - v14 + cchCount2;
    cchCount2 = v12;
  }
  if ( f_use_2 == 2 || f_use_2 == 0 )
  {
    v31 = nullptr;
    v32 = nullptr;
    if ( Locale == 0 )
      Locale = plocinfo->locinfo->lc_handle[2];
    if ( code_page == 0 )
      code_page = plocinfo->locinfo->lc_codepage;
    v33 = __ansicp(lcid: Locale);
    v34 = v33;
    if ( v33 == -1 )
      return 0;
    if ( v33 != code_page )
    {
      v32 = __convertcp(
              fromCP: code_page,
              toCP: v33,
              lpSrcStr: lpMultiByteStr,
              pcchSrc: &cchCount1,
              lpDestStr: nullptr,
              cchDest: 0);
      if ( v32 == nullptr )
        return 0;
      v35 = __convertcp(
              fromCP: code_page,
              toCP: v34,
              lpSrcStr: v44,
              pcchSrc: &cchCount2,
              lpDestStr: nullptr,
              cchDest: 0);
      v31 = (CHAR *)v35;
      if ( v35 == nullptr )
      {
        free(pMem: v32);
        return 0;
      }
      lpMultiByteStr = v32;
      v44 = v35;
    }
    v36 = CompareStringA(Locale, dwCmpFlags, lpString1: lpMultiByteStr, cchCount1, lpString2: v44, cchCount2);
    if ( v32 != nullptr )
    {
      free(pMem: v32);
      free(pMem: v31);
    }
    return v36;
  }
  result = 1;
  if ( f_use_2 != 1 )
    return 0;
  retcode = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  if ( cchCount1 != 0 && v12 != 0 )
  {
LABEL_52:
    v20 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 9u,
            lpMultiByteStr: lpString1,
            cbMultiByte: cchCount1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v21 = v20;
    buff_size1 = v20;
    if ( v20 == 0 )
      return 0;
    if ( v20 <= 0 || 0xFFFFFFE0 / v20 < 2 )
    {
      wbuffer1 = nullptr;
LABEL_63:
      if ( wbuffer1 != nullptr )
      {
        if ( MultiByteToWideChar(
               CodePage: code_page,
               dwFlags: 1u,
               lpMultiByteStr,
               cbMultiByte: cchCount1,
               lpWideCharStr: wbuffer1,
               cchWideChar: v21) != 0 )
        {
          v25 = MultiByteToWideChar(
                  CodePage: code_page,
                  dwFlags: 9u,
                  lpMultiByteStr: v44,
                  cbMultiByte: cchCount2,
                  lpWideCharStr: nullptr,
                  cchWideChar: 0);
          v26 = v25;
          if ( v25 != 0 )
          {
            if ( v25 <= 0 || 0xFFFFFFE0 / v25 < 2 )
            {
              v29 = nullptr;
LABEL_75:
              if ( v29 != nullptr )
              {
                if ( MultiByteToWideChar(
                       CodePage: code_page,
                       dwFlags: 1u,
                       lpMultiByteStr: v44,
                       cbMultiByte: cchCount2,
                       lpWideCharStr: v29,
                       cchWideChar: v26) != 0 )
                  retcode = CompareStringW(
                              Locale,
                              dwCmpFlags,
                              lpString1: wbuffer1,
                              cchCount1: buff_size1,
                              lpString2: v29,
                              cchCount2: v26);
                _freea(_Memory: v29);
              }
              goto error_cleanup_0;
            }
            v27 = 2 * v25 + 8;
            if ( v27 > 0x400 )
            {
              v30 = (WCHAR *)_malloc_crt(size: 2 * v26 + 8);
              if ( v30 != nullptr )
              {
                *(_DWORD *)v30 = 56797;
                v30 += 4;
              }
              v29 = v30;
              goto LABEL_75;
            }
            v28 = alloca(v27);
            if ( v38 != nullptr )
            {
              v38[0] = 52428;
              v29 = (WCHAR *)&v39;
              goto LABEL_75;
            }
          }
        }
error_cleanup_0:
        _freea(_Memory: wbuffer1);
        return retcode;
      }
      return 0;
    }
    v22 = 2 * v20 + 8;
    if ( v22 > 0x400 )
    {
      v24 = (wchar_t *)_malloc_crt(size: 2 * v21 + 8);
      if ( v24 != nullptr )
      {
        *(_DWORD *)v24 = 56797;
        goto LABEL_60;
      }
    }
    else
    {
      v23 = alloca(v22);
      v24 = (wchar_t *)v38;
      if ( v38 != nullptr )
      {
        v38[0] = 52428;
LABEL_60:
        v24 += 4;
      }
    }
    wbuffer1 = v24;
    goto LABEL_63;
  }
  if ( cchCount1 == v12 )
    return 2;
  if ( v12 <= 1 )
  {
    if ( cchCount1 > 1 )
      return 3;
    if ( !GetCPInfo(CodePage: code_page, &lpCPInfo) )
      return 0;
    if ( cchCount1 > 0 )
    {
      if ( lpCPInfo.MaxCharSize >= 2 )
      {
        LeadByte = lpCPInfo.LeadByte;
        if ( lpCPInfo.LeadByte[0] != 0 )
        {
          while ( 1 )
          {
            v17 = LeadByte[1];
            if ( v17 == 0 )
              break;
            if ( (unsigned int)*lpString1 >= *LeadByte && (unsigned int)*lpString1 <= v17 )
              return 2;
            LeadByte += 2;
            if ( *LeadByte == 0 )
              return 3;
          }
        }
      }
      return 3;
    }
    if ( cchCount2 > 0 )
    {
      if ( lpCPInfo.MaxCharSize >= 2 )
      {
        for ( i = lpCPInfo.LeadByte; *i != 0; i += 2 )
        {
          v19 = i[1];
          if ( v19 == 0 )
            break;
          if ( (unsigned int)*v44 >= *i && (unsigned int)*v44 <= v19 )
            return 2;
        }
      }
      return 1;
    }
    goto LABEL_52;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E740
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringA(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        unsigned int code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             lpString1,
             Locale,
             dwCmpFlags,
             cchCount1,
             lpString2,
             cchCount2,
             code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E780
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _strnicoll_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const char *_string1,
        const char *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  int v8; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( count == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _string1 != nullptr && _string2 != nullptr )
  {
    if ( count > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: 0x7FFFFFFFu);
LABEL_16:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    v7 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( v7 != 0 )
    {
      v8 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: v7,
             dwCmpFlags: 0x1001u,
             lpString1: _string1,
             cchCount1: count,
             lpString2: _string2,
             cchCount2: count,
             code_page: _loc_update.localeinfo.locinfo->lc_collate_cp);
      if ( v8 == 0 )
      {
        *_errno() = 22;
        goto LABEL_16;
      }
      result = v8 - 2;
    }
    else
    {
      result = _strnicmp_l(dst: _string1, src: _string2, count, plocinfo: &_loc_update.localeinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E880
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  return *(_WORD *)pImageBase == 23117
      && *(_DWORD *)(v2 = &pImageBase[*((_DWORD *)pImageBase + 15)]) == 17744
      && *((_WORD *)v2 + 12) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x0040E8B0
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( *((_WORD *)v2 + 3) == 0 )
    return nullptr;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040E900
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x400000)
      && (PESection = _FindPESection(pImageBase: (unsigned __int8 *)0x400000, rva: (unsigned int)(pTarget - 0x400000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E9BB
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_terminate;
  if ( v0 != nullptr )
    v0();
  abort();
}

//------------------------------------------------------------------------------
// Address: 0x0040E9F4
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _initp_eh_hooks(unsigned int a1@<edi>)
{
  __pInconsistency = (void (__cdecl *)())_encode_pointer(a1, ptr: terminate);
}

//------------------------------------------------------------------------------
// Address: 0x0040EA05
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void (__cdecl *enull)(int))
{
  ctrlc_action = enull;
  ctrlbreak_action = enull;
  abort_action = enull;
  term_action = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040EA1E
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_XCPT_ACTION *__usercall siglookup@<eax>(int signum@<edx>, _XCPT_ACTION *pxcptacttab)
{
  _XCPT_ACTION *result; // eax

  result = pxcptacttab;
  do
  {
    if ( result->SigNum == signum )
      break;
    ++result;
  }
  while ( result < &pxcptacttab[_XcptActTabCount] );
  if ( result >= &pxcptacttab[_XcptActTabCount] || result->SigNum != signum )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040EA52
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__usercall __get_sigabrt@<eax>(unsigned int a1@<edi>))(int)
{
  return (void (__cdecl *)(int))_decode_pointer(a1, codedptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x0040EA5F
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall raise@<eax>(unsigned int a1@<esi>, int signum)
{
  _tiddata *v2; // edi
  _tiddata *v3; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v6)(int); // eax
  void (__cdecl *v7)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v2 = nullptr;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v6 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v6 = ctrlbreak_action;
      goto LABEL_18;
    }
    if ( signum != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( signum != 11 )
  {
    if ( signum == 2 )
    {
      p_XcptAction = &ctrlc_action;
      v6 = ctrlc_action;
LABEL_18:
      siglock = 1;
      v7 = (void (__cdecl *)(int))_decode_pointer(a1: 0, codedptr: v6);
      goto LABEL_19;
    }
    if ( signum != 4 )
    {
      if ( signum != 6 )
      {
        if ( signum == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter(a1: signum, a2: 0, a3: a1);
        return -1;
      }
LABEL_15:
      p_XcptAction = &abort_action;
      v6 = abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v3 = _getptd_noexit();
  v2 = v3;
  if ( v3 == nullptr )
    return -1;
  p_XcptAction = &siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v3->_pxcptacttab)->XcptAction;
  v7 = *p_XcptAction;
LABEL_19:
  sigact = v7;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( sigact == nullptr )
    _exit(code: 3);
  if ( siglock != 0 )
    _lock(locknum: 0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v2->_tpxcptinfoptrs;
    v2->_tpxcptinfoptrs = nullptr;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v2->_tfpecode;
    v2->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = _First_FPE_Indx; indx < _First_FPE_Indx + _Num_FPE; ++indx )
      *((_DWORD *)v2->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null(a1: (unsigned int)v2);
$LN37:
  if ( siglock != 0 )
    _unlock(locknum: 0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(a1: 8, a2: v2->_tfpecode);
  else
    sigact(a1: signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v2->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v2->_tfpecode = oldfpecode;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040EC0F
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(int (__stdcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040EC19
// Name: __initp_misc_initcrit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_initcrit(int (__stdcall *enull)(_RTL_CRITICAL_SECTION *, unsigned int))
{
  _pfnInitCritSecAndSpinCount = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040EC23
// Name: __crtInitCritSecNoSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _crtInitCritSecNoSpinCount(_RTL_CRITICAL_SECTION *lpCriticalSection, unsigned int dwSpinCount)
{
  InitializeCriticalSection(lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040EC33
// Name: ___crtInitCritSecAndSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall __crtInitCritSecAndSpinCount@<eax>(
        unsigned int a1@<ebx>,
        _RTL_CRITICAL_SECTION *lpCriticalSection,
        DWORD dwSpinCount)
{
  BOOL (__stdcall *InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION, DWORD); // esi
  unsigned int v4; // eax
  unsigned int v5; // edx
  HMODULE ModuleHandleA; // eax
  unsigned int v8; // [esp-4h] [ebp-38h]
  unsigned int osplatform; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  osplatform = 0;
  InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))_decode_pointer(
                                                                                           a1: 0,
                                                                                           codedptr: _pfnInitCritSecAndSpinCount);
  if ( InitializeCriticalSectionAndSpinCount == nullptr )
  {
    v4 = _get_osplatform(a1, a2: 0, pValue: &osplatform);
    if ( v4 != 0 )
      _invoke_watson(a1: v4, a2: v5, a3: v8, a4: a1, a5: 0, a6: 0);
    if ( osplatform == 1
      || (ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32.dll")) == nullptr
      || (InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))GetProcAddress(
                                                                                                   hModule: ModuleHandleA,
                                                                                                   lpProcName: "InitializeCriticalSec"
                                                                                                   "tionAndSpinCount")) == nullptr )
    {
      InitializeCriticalSectionAndSpinCount = _crtInitCritSecNoSpinCount;
    }
    _pfnInitCritSecAndSpinCount = (int (__stdcall *)(_RTL_CRITICAL_SECTION *, unsigned int))_encode_pointer(
                                                                                              a1: 0,
                                                                                              ptr: InitializeCriticalSectionAndSpinCount);
  }
  ms_exc.registration.TryLevel = 0;
  return InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}

//------------------------------------------------------------------------------
// Address: 0x0040ECF8
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(int (__cdecl *enull)(unsigned int))
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0040ED02
// Name: ___crtMessageBoxA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtMessageBoxA@<eax>(HMODULE a1@<edi>, const char *lpText, const char *lpCaption, unsigned int uType)
{
  HMODULE LibraryA; // eax
  int (__stdcall *MessageBoxA)(HWND, LPCSTR, LPCSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  unsigned int v8; // eax
  unsigned int v9; // edx
  BOOL (__stdcall *GetUserObjectInformationA)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v12)(void); // esi
  HMODULE v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edx
  int (*v17)(void); // eax
  int (__stdcall *v18)(HWND__ *); // eax
  int (__stdcall *v19)(HWND__ *, const char *, const char *, unsigned int); // eax
  LPCSTR lpProcName; // [esp+0h] [ebp-30h]
  LPCSTR lpProcNamea; // [esp+0h] [ebp-30h]
  tagUSEROBJECTFLAGS uof; // [esp+10h] [ebp-20h] BYREF
  unsigned int nDummy; // [esp+1Ch] [ebp-14h] BYREF
  unsigned int winmajor; // [esp+20h] [ebp-10h] BYREF
  unsigned int osplatform; // [esp+24h] [ebp-Ch] BYREF
  void *enull; // [esp+28h] [ebp-8h]
  HWND__ *hWndParent; // [esp+2Ch] [ebp-4h]

  enull = _encoded_null((unsigned int)a1);
  hWndParent = nullptr;
  osplatform = 0;
  winmajor = 0;
  if ( pfnMessageBox == nullptr )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "USER32.DLL");
    a1 = LibraryA;
    if ( LibraryA == nullptr )
      return 0;
    MessageBoxA = (int (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))GetProcAddress(
                                                                   hModule: LibraryA,
                                                                   lpProcName: "MessageBoxA");
    if ( MessageBoxA == nullptr )
      return 0;
    pfnMessageBox = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_encode_pointer(
                                                                                             (unsigned int)a1,
                                                                                             ptr: MessageBoxA);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: a1, lpProcName: "GetActiveWindow");
    pfnGetActiveWindow = (HWND__ *(__stdcall *)())_encode_pointer((unsigned int)a1, ptr: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: a1, lpProcName: "GetLastActivePopup");
    pfnGetLastActivePopup = (HWND__ *(__stdcall *)(HWND__ *))_encode_pointer((unsigned int)a1, ptr: GetLastActivePopup);
    v8 = _get_osplatform(a1: 0, a2: (unsigned int)a1, pValue: &osplatform);
    if ( v8 != 0 )
      _invoke_watson(
        a1: v8,
        a2: v9,
        a3: (unsigned int)lpProcName,
        a4: 0,
        a5: (unsigned int)a1,
        a6: (unsigned int)GetProcAddress);
    if ( osplatform == 2 )
    {
      GetUserObjectInformationA = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                            hModule: a1,
                                                                                            lpProcName: "GetUserObjectInformationA");
      pfnGetUserObjectInformation = (int (__stdcall *)(void *, int, void *, unsigned int, unsigned int *))_encode_pointer((unsigned int)a1, ptr: GetUserObjectInformationA);
      if ( pfnGetUserObjectInformation != nullptr )
      {
        GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                             hModule: a1,
                                                             lpProcName: "GetProcessWindowStation");
        pfnGetProcessWindowStation = (HWINSTA__ *(__stdcall *)())_encode_pointer(
                                                                   (unsigned int)a1,
                                                                   ptr: GetProcessWindowStation);
      }
    }
  }
  if ( pfnGetProcessWindowStation == enull
    || pfnGetUserObjectInformation == enull
    || (v12 = (int (*)(void))_decode_pointer((unsigned int)a1, codedptr: pfnGetProcessWindowStation),
        v13 = (HMODULE)_decode_pointer((unsigned int)a1, codedptr: pfnGetUserObjectInformation),
        a1 = v13,
        v12 == nullptr)
    || v13 == nullptr
    || (v14 = v12()) != 0
    && ((int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))a1)(
         a1: v14,
         a2: 1,
         a3: &uof,
         a4: 12,
         a5: &nDummy) != 0
    && (uof.dwFlags & 1) != 0 )
  {
    if ( pfnGetActiveWindow != enull )
    {
      v17 = (int (*)(void))_decode_pointer((unsigned int)a1, codedptr: pfnGetActiveWindow);
      if ( v17 != nullptr )
      {
        hWndParent = (HWND__ *)v17();
        if ( hWndParent != nullptr && pfnGetLastActivePopup != enull )
        {
          v18 = (int (__stdcall *)(HWND__ *))_decode_pointer((unsigned int)a1, codedptr: pfnGetLastActivePopup);
          if ( v18 != nullptr )
            hWndParent = (HWND__ *)v18(a1: hWndParent);
        }
      }
    }
  }
  else
  {
    v15 = _get_winmajor(a1: 0, a2: (unsigned int)a1, pValue: &winmajor);
    if ( v15 != 0 )
      _invoke_watson(
        a1: v15,
        a2: v16,
        a3: (unsigned int)lpProcNamea,
        a4: 0,
        a5: (unsigned int)a1,
        a6: (unsigned int)v12);
    if ( winmajor < 4 )
      uType |= 0x40000u;
    else
      uType |= 0x200000u;
  }
  v19 = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_decode_pointer(
                                                                                 (unsigned int)a1,
                                                                                 codedptr: pfnMessageBox);
  if ( v19 != nullptr )
    return v19(a1: hWndParent, a2: lpText, a3: lpCaption, a4: uType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040EEBF
// Name: _strcat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strcat_s@<eax>(unsigned int a1@<edi>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src != nullptr )
  {
    v7 = _Dst;
    do
    {
      if ( *v7 == 0 )
        break;
      ++v7;
      --a1;
    }
    while ( a1 != 0 );
    if ( a1 != 0 )
    {
      do
      {
        v8 = *v6;
        *v7++ = *v6++;
        if ( v8 == 0 )
          break;
        --a1;
      }
      while ( a1 != 0 );
      if ( a1 == 0 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return 0;
    }
  }
  *_Dst = 0;
LABEL_3:
  v4 = 22;
  *_errno() = 22;
LABEL_4:
  _invalid_parameter(a1: 0, a2: a1, a3: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040EF30
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strncpy_s@<eax>(
        unsigned int a1@<edi>,
        char *_Dst,
        unsigned int _SizeInBytes,
        const char *_Src,
        unsigned int _Count)
{
  unsigned int v6; // esi
  const char *v7; // edx
  char *v8; // eax
  char v9; // cl
  char v10; // cl

  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter(a1: 0, a2: a1, a3: v6);
      return v6;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v8 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v9 = *v7;
      *v8++ = *v7++;
      if ( v9 == 0 )
        break;
      --a1;
    }
    while ( a1 != 0 );
  }
  else
  {
    do
    {
      v10 = *v7;
      *v8++ = *v7++;
      if ( v10 == 0 )
        break;
      if ( --a1 == 0 )
        break;
      --_Count;
    }
    while ( _Count != 0 );
    if ( _Count == 0 )
      *v8 = 0;
  }
  if ( a1 != 0 )
    return 0;
  if ( _Count != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInBytes - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x0040EFE3
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _set_error_mode@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int em)
{
  int result; // eax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = __error_mode;
      __error_mode = em;
      return result;
    }
    if ( em == 3 )
      return __error_mode;
  }
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040F029
// Name: __lseeki64_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
doubleint __cdecl _lseeki64_nolock(int fh, __int64 pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD LastError; // eax
  char *p_osfile; // eax
  doubleint newpos; // [esp+8h] [ebp-8h] BYREF

  newpos.bigint = pos;
  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return (doubleint)-1LL;
  }
  newpos.twoints.lowerhalf = SetFilePointer(
                               hFile: osfhandle,
                               lDistanceToMove: newpos.twoints.lowerhalf,
                               lpDistanceToMoveHigh: &newpos.twoints.upperhalf,
                               dwMoveMethod: mthd);
  if ( newpos.twoints.lowerhalf == -1 )
  {
    LastError = GetLastError();
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return (doubleint)-1LL;
    }
  }
  p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
  *p_osfile &= ~2u;
  return newpos;
}

//------------------------------------------------------------------------------
// Address: 0x0040F0AC
// Name: __lseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _lseeki64@<eax>(unsigned int a1@<ebx>, int fh, __int64 pos, DWORD mthd)
{
  int v5; // esi
  unsigned int r; // [esp+10h] [ebp-24h]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: 0xFFFFFFFF);
    return -1;
  }
  v5 = fh & 0x1F;
  if ( (__pioinfo[fh >> 5][v5].osfile & 1) != 0 )
  {
    __lock_fhandle(fh);
    if ( (__pioinfo[fh >> 5][v5].osfile & 1) != 0 )
    {
      r = _lseeki64_nolock(fh, pos, mthd).twoints.lowerhalf;
    }
    else
    {
      *_errno() = 9;
      *__doserrno() = 0;
      r = -1;
    }
    _unlock_fhandle(fh);
    return r;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1: 4 * (fh >> 5) + 4312448, a2: 0, a3: v5 * 56);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F1C5
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write_nolock@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh, char *buf, DWORD cnt)
{
  int v6; // ebx
  _DWORD *v7; // edi
  ioinfo *v8; // eax
  char v9; // cl
  BOOL v10; // esi
  UINT v11; // eax
  char *v12; // esi
  DWORD v13; // eax
  int v14; // esi
  ioinfo *v15; // eax
  DWORD v16; // ecx
  ioinfo *v17; // eax
  unsigned int v18; // ecx
  char *v19; // eax
  unsigned __int16 *v20; // edx
  char v21; // dl
  int v22; // esi
  unsigned int v23; // esi
  unsigned int v24; // ecx
  char *v25; // eax
  unsigned __int16 *v26; // edx
  unsigned __int16 v27; // dx
  int v28; // esi
  DWORD v29; // ecx
  wchar_t *v30; // eax
  wchar_t v31; // dx
  int v32; // esi
  int v33; // edi
  unsigned int v34; // esi
  unsigned __int8 v35; // [esp-Ch] [ebp-8Ch]
  unsigned int consoleCP; // [esp+4h] [ebp-7Ch] BYREF
  int bCR; // [esp+8h] [ebp-78h]
  char *pch; // [esp+Ch] [ebp-74h]
  _DWORD *v39; // [esp+10h] [ebp-70h]
  int written; // [esp+14h] [ebp-6Ch] BYREF
  int lfcount; // [esp+18h] [ebp-68h]
  char *s; // [esp+1Ch] [ebp-64h]
  int charcount; // [esp+20h] [ebp-60h]
  char *v44; // [esp+24h] [ebp-5Ch]
  char tmode; // [esp+2Bh] [ebp-55h]
  DWORD tmpchar; // [esp+2Ch] [ebp-54h] BYREF
  unsigned __int16 *pu; // [esp+30h] [ebp-50h] BYREF
  char utf8_buf[1028]; // [esp+34h] [ebp-4Ch] BYREF
  wchar_t utf16_buf[170]; // [esp+438h] [ebp+3B8h] BYREF
  char mboutbuf[8]; // [esp+58Ch] [ebp+50Ch] BYREF

  s = buf;
  charcount = 0;
  lfcount = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  v6 = fh & 0x1F;
  v7 = (_DWORD *)(4 * (fh >> 5) + 4312448);
  v8 = &__pioinfo[fh >> 5][v6];
  v9 = (char)(2 * *((_BYTE *)v8 + 36)) >> 1;
  v39 = v7;
  tmode = v9;
  if ( (v9 == 2 || v9 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1: v6 * 56, a2: (unsigned int)v7, a3: 0);
    return -1;
  }
  if ( (v8->osfile & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2u);
  if ( _isatty(fh) != 0 && __pioinfo[fh >> 5][v6].osfile < 0 )
  {
    v10 = _getptd()->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd, lpMode: &consoleCP)
      && (!v10 || tmode != 0) )
    {
      v11 = GetConsoleCP();
      pu = nullptr;
      v12 = s;
      consoleCP = v11;
      pch = s;
      v44 = nullptr;
      while ( 1 )
      {
        if ( tmode != 0 )
        {
          if ( tmode == 1 || tmode == 2 )
          {
            v16 = *(unsigned __int16 *)v12;
            v44 += 2;
            tmpchar = v16;
            pch = v12 + 2;
            bCR = (_WORD)v16 == 10;
          }
          if ( tmode == 1 || tmode == 2 )
          {
            if ( _putwch_nolock(ch: tmpchar) != (_WORD)tmpchar )
              goto LABEL_82;
            ++charcount;
            if ( bCR != 0 )
            {
              tmpchar = 13;
              if ( _putwch_nolock(ch: 0xDu) != 13 )
                goto LABEL_82;
              ++charcount;
              ++lfcount;
            }
          }
        }
        else
        {
          v35 = *v12;
          bCR = *v12 == 10;
          if ( isleadbyte(c: v35) != 0 )
          {
            if ( cnt + s - v12 <= 1 || mbtowc(pwc: (wchar_t *)&tmpchar, s: v12, n: 2u) == -1 )
              goto LABEL_83;
            ++v12;
            ++v44;
          }
          else if ( mbtowc(pwc: (wchar_t *)&tmpchar, s: v12, n: 1u) == -1 )
          {
            goto LABEL_83;
          }
          ++v44;
          pch = v12 + 1;
          v13 = WideCharToMultiByte(
                  CodePage: consoleCP,
                  dwFlags: 0,
                  lpWideCharStr: (LPCWCH)&tmpchar,
                  cchWideChar: 1,
                  lpMultiByteStr: mboutbuf,
                  cbMultiByte: 5,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          v14 = v13;
          if ( v13 == 0 )
            goto LABEL_83;
          if ( !WriteFile(
                  hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                  lpBuffer: mboutbuf,
                  nNumberOfBytesToWrite: v13,
                  lpNumberOfBytesWritten: (LPDWORD)&pu,
                  lpOverlapped: nullptr) )
            goto LABEL_82;
          charcount += (int)pu;
          if ( (int)pu < v14 )
            goto LABEL_83;
          if ( bCR != 0 )
          {
            v15 = __pioinfo[fh >> 5];
            mboutbuf[0] = 13;
            if ( !WriteFile(
                    hFile: (HANDLE)v15[v6].osfhnd,
                    lpBuffer: mboutbuf,
                    nNumberOfBytesToWrite: 1u,
                    lpNumberOfBytesWritten: (LPDWORD)&pu,
                    lpOverlapped: nullptr) )
              goto LABEL_82;
            if ( (int)pu < 1 )
              goto LABEL_83;
            ++lfcount;
            ++charcount;
          }
        }
        if ( (unsigned int)v44 >= cnt )
          goto LABEL_83;
        v12 = pch;
      }
    }
  }
  v17 = &__pioinfo[fh >> 5][v6];
  if ( v17->osfile >= 0 )
  {
    if ( WriteFile(
           hFile: (HANDLE)v17->osfhnd,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: (LPDWORD)&written,
           lpOverlapped: nullptr) )
    {
      tmpchar = 0;
      charcount = written;
      goto LABEL_83;
    }
  }
  else
  {
    tmpchar = 0;
    if ( tmode != 0 )
    {
      if ( tmode == 2 )
      {
        pu = (unsigned __int16 *)s;
        while ( 1 )
        {
          v23 = 0;
          v24 = (char *)pu - s;
          v25 = utf8_buf;
          do
          {
            if ( v24 >= cnt )
              break;
            v26 = pu++;
            v27 = *v26;
            v24 += 2;
            if ( v27 == 10 )
            {
              lfcount += 2;
              *(_WORD *)v25 = 13;
              v25 += 2;
              v23 += 2;
            }
            v7 = v39;
            *(_WORD *)v25 = v27;
            v25 += 2;
            v23 += 2;
          }
          while ( v23 < 0x3FF );
          v28 = v25 - utf8_buf;
          if ( !WriteFile(
                  hFile: *(HANDLE *)(v6 * 56 + *v7),
                  lpBuffer: utf8_buf,
                  nNumberOfBytesToWrite: v25 - utf8_buf,
                  lpNumberOfBytesWritten: (LPDWORD)&written,
                  lpOverlapped: nullptr) )
            break;
          charcount += written;
          if ( written < v28 || (char *)pu - s >= cnt )
            goto LABEL_83;
        }
      }
      else
      {
        v44 = s;
        while ( 1 )
        {
          pu = nullptr;
          v29 = v44 - s;
          v30 = utf16_buf;
          do
          {
            if ( v29 >= cnt )
              break;
            v31 = *(_WORD *)v44;
            v44 += 2;
            v29 += 2;
            if ( v31 == 10 )
            {
              *v30++ = 13;
              ++pu;
            }
            ++pu;
            *v30++ = v31;
          }
          while ( (unsigned int)pu < 0x152 );
          v32 = 0;
          v33 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: utf16_buf,
                  cchWideChar: v30 - utf16_buf,
                  lpMultiByteStr: &utf8_buf[340],
                  cbMultiByte: 683,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v33 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)(v6 * 56 + *v39),
                    lpBuffer: &utf8_buf[v32 + 340],
                    nNumberOfBytesToWrite: v33 - v32,
                    lpNumberOfBytesWritten: (LPDWORD)&written,
                    lpOverlapped: nullptr) )
          {
            v32 += written;
            if ( v33 <= v32 )
              goto LABEL_77;
          }
          tmpchar = GetLastError();
LABEL_77:
          if ( v33 <= v32 )
          {
            charcount = v44 - s;
            if ( v44 - s < cnt )
              continue;
          }
          goto LABEL_83;
        }
      }
    }
    else
    {
      pu = (unsigned __int16 *)s;
      while ( 1 )
      {
        v44 = nullptr;
        v18 = (char *)pu - s;
        v19 = utf8_buf;
        do
        {
          if ( v18 >= cnt )
            break;
          v20 = pu;
          pu = (unsigned __int16 *)((char *)pu + 1);
          v21 = *(_BYTE *)v20;
          ++v18;
          if ( v21 == 10 )
          {
            ++lfcount;
            *v19++ = 13;
            ++v44;
          }
          *v19++ = v21;
          ++v44;
        }
        while ( (unsigned int)v44 < 0x400 );
        v22 = v19 - utf8_buf;
        if ( !WriteFile(
                hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                lpBuffer: utf8_buf,
                nNumberOfBytesToWrite: v19 - utf8_buf,
                lpNumberOfBytesWritten: (LPDWORD)&written,
                lpOverlapped: nullptr) )
          break;
        charcount += written;
        if ( written < v22 || (char *)pu - s >= cnt )
          goto LABEL_83;
      }
    }
  }
LABEL_82:
  tmpchar = GetLastError();
LABEL_83:
  if ( charcount == 0 )
  {
    v34 = 0;
    if ( tmpchar != 0 )
    {
      v34 = 5;
      if ( tmpchar != 5 )
      {
        _dosmaperr(oserrno: tmpchar);
        return -1;
      }
      *_errno() = 9;
    }
    else
    {
      if ( (*(_BYTE *)(v6 * 56 + *v39 + 4) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
    }
    *__doserrno() = v34;
    return -1;
  }
  return charcount - lfcount;
}

//------------------------------------------------------------------------------
// Address: 0x0040F78B
// Name: __write
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh, char *buf, DWORD cnt)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 4312448, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _write_nolock(a1, a2: 0, fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x0040F867
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)_malloc_crt(size: 0x1000u);
  str->_base = v1;
  if ( v1 != nullptr )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_base = (char *)&str->_charbuf;
    str->_bufsiz = 2;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

//------------------------------------------------------------------------------
// Address: 0x0040F8AB
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _isatty@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  else if ( fh >= 0 && fh < _nhandle )
  {
    return __pioinfo[fh >> 5][fh & 0x1F].osfile & 0x40;
  }
  else
  {
    *_errno() = 9;
    _invalid_parameter(a1, a2, a3: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F909
// Name: __wctomb_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wctomb_s_l(
        int *pRetValue,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  char *v5; // esi
  unsigned int v6; // edi
  int result; // eax
  int v8; // esi
  int v9; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v5 = dst;
  v6 = sizeInBytes;
  if ( dst == nullptr && sizeInBytes != 0 )
  {
    if ( pRetValue != nullptr )
      *pRetValue = 0;
    return 0;
  }
  if ( pRetValue != nullptr )
    *pRetValue = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: v6, a3: 0x16u);
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( wchar > 0xFFu )
    {
      if ( v5 != nullptr && v6 != 0 )
        memset(dst: (int)v5, value: nullptr, count: v6);
      goto LABEL_16;
    }
    if ( v5 != nullptr )
    {
      if ( v6 == 0 )
      {
LABEL_21:
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter(a1: 0, a2: v6, a3: 0x22u);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = wchar;
    }
    if ( pRetValue != nullptr )
      *pRetValue = 1;
LABEL_26:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  dst = nullptr;
  v9 = WideCharToMultiByte(
         CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
         dwFlags: 0,
         lpWideCharStr: &wchar,
         cchWideChar: 1,
         lpMultiByteStr: v5,
         cbMultiByte: v6,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: (LPBOOL)&dst);
  if ( v9 != 0 )
  {
    if ( dst == nullptr )
    {
      if ( pRetValue != nullptr )
        *pRetValue = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 != nullptr && v6 != 0 )
      memset(dst: (int)v5, value: nullptr, count: v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno() = 42;
  result = *_errno();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FA68
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_s(int *pRetValue, char *dst, unsigned int sizeInBytes, wchar_t wchar)
{
  return _wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040FA90
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040FB25
// Name: x_ismbbtype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( (kmask & _loc_update.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (cmask == 0 ? (result = 0) : (result = (unsigned __int16)(cmask & _loc_update.localeinfo.locinfo->pctype[tst])),
        result != 0) )
  {
    result = 1;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FB76
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead(unsigned __int8 tst)
{
  return x_ismbbtype_l(plocinfo: nullptr, tst, cmask: 0, kmask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x0040FB89
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  int v1; // esi
  void **v2; // eax
  _iobuf *v3; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    v1 = i;
    v2 = &__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = (_iobuf *)*v2;
      if ( (v3->_flag & 0x83) != 0 && fclose(stream: v3) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[v1] + 32));
        free(pMem: __piob[v1]);
        __piob[v1] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x0040FC28
// Name: __wcsnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _wcsnicoll_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const wchar_t *_string1,
        const wchar_t *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const wchar_t *v7; // edi
  unsigned int v8; // ecx
  wchar_t v9; // ax
  wchar_t v10; // cx
  wchar_t v11; // ax
  int v12; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  if ( count == 0 )
    return 0;
  if ( _string1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    return 0x7FFFFFFF;
  }
  v7 = _string2;
  if ( _string2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: 0, a3: a2);
    return 0x7FFFFFFF;
  }
  if ( count > 0x7FFFFFFF )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)_string2, a3: 0x7FFFFFFFu);
    return 0x7FFFFFFF;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v8 = _loc_update.localeinfo.locinfo->lc_handle[1];
  if ( v8 != 0 )
  {
    v12 = __crtCompareStringW(
            plocinfo: &_loc_update.localeinfo,
            Locale: v8,
            dwCmpFlags: 0x1001u,
            lpString1: _string1,
            cchCount1: count,
            lpString2: _string2,
            cchCount2: count,
            code_page: _loc_update.localeinfo.locinfo->lc_collate_cp);
    if ( v12 == 0 )
    {
      *_errno() = 22;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    result = v12 - 2;
  }
  else
  {
    do
    {
      v9 = *_string1;
      if ( *_string1 >= 0x41u && v9 <= 0x5Au )
        v9 += 32;
      v10 = v9;
      v11 = *v7;
      if ( *v7 >= 0x41u && v11 <= 0x5Au )
        v11 += 32;
      ++_string1;
      ++v7;
      --count;
    }
    while ( count != 0 && v10 != 0 && v10 == v11 );
    result = v10 - v11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FD69
// Name: __wcsnicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _wcsnicoll@<eax>(
        unsigned int a1@<esi>,
        const wchar_t *_string1,
        const wchar_t *_string2,
        unsigned int count)
{
  const wchar_t *v4; // ebx
  const wchar_t *v6; // edx
  wchar_t v7; // ax
  wchar_t v8; // cx
  wchar_t v9; // ax

  if ( __locale_changed != 0 )
    return _wcsnicoll_l(a1: 0, a2: a1, _string1, _string2, count, plocinfo: nullptr);
  v4 = _string1;
  if ( _string1 != nullptr && (v6 = _string2, _string2 != nullptr) && count <= 0x7FFFFFFF )
  {
    do
    {
      v7 = *v4;
      if ( *v4 >= 0x41u && v7 <= 0x5Au )
        v7 += 32;
      v8 = v7;
      v9 = *v6;
      if ( *v6 >= 0x41u && v9 <= 0x5Au )
        v9 += 32;
      ++v4;
      ++v6;
      --count;
    }
    while ( count != 0 && v8 != 0 && v8 == v9 );
    return v8 - v9;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: (unsigned int)_string1, a2: 0, a3: a1);
    return 0x7FFFFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FE0B
// Name: _wcscpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall wcscpy_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int16 *_Dst,
        unsigned int _SizeInWords,
        const wchar_t *_Src)
{
  unsigned int v4; // esi
  const wchar_t *v6; // esi
  unsigned __int16 *v7; // edx
  wchar_t v8; // ax

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(a1, a2: 0, a3: v4);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --a1;
  }
  while ( a1 != 0 );
  if ( a1 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040FE77
// Name: ___mbtow_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __mbtow_environ()
{
  LPCCH *v0; // esi
  const CHAR *v1; // eax
  unsigned int v2; // eax
  unsigned __int16 *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  unsigned __int16 *wenvp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCCH *)_environ;
  wenvp = nullptr;
  v1 = *_environ;
  if ( *_environ == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: v1,
           cbMultiByte: -1,
           lpWideCharStr: nullptr,
           cchWideChar: 0);
    size = v2;
    if ( v2 == 0 )
      return -1;
    v3 = (unsigned __int16 *)_calloc_crt(count: v2, size: 2u);
    wenvp = v3;
    if ( v3 == nullptr )
      return -1;
    if ( MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: *v0,
           cbMultiByte: -1,
           lpWideCharStr: v3,
           cchWideChar: size) == 0 )
      goto LABEL_10;
    if ( __crtwsetenv(a1: 0, a2: (unsigned int)MultiByteToWideChar, poption: &wenvp, primary: 0) < 0 )
    {
      if ( wenvp == nullptr )
        return -1;
LABEL_10:
      free(pMem: wenvp);
      return -1;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FEFC
// Name: __wsetenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wsetenvp()
{
  wchar_t *v0; // esi
  int v1; // edi
  unsigned __int16 **v3; // ebx
  wchar_t *i; // esi
  int v5; // eax
  unsigned int v6; // edi
  unsigned __int16 *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx

  v0 = _wenvptr;
  v1 = 0;
  if ( _wenvptr == nullptr )
    return -1;
  while ( *v0 != 0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += wcslen(wcs: v0) + 1;
  }
  v3 = (unsigned __int16 **)_calloc_crt(count: v1 + 1, size: 4u);
  _wenviron = v3;
  if ( v3 == nullptr )
    return -1;
  for ( i = _wenvptr; ; i += v6 )
  {
    if ( *i == 0 )
    {
      free(pMem: _wenvptr);
      _wenvptr = nullptr;
      *v3 = nullptr;
      __env_initialized = 1;
      return 0;
    }
    v5 = wcslen(wcs: i);
    v6 = v5 + 1;
    if ( *i != 61 )
      break;
LABEL_15:
    ;
  }
  v7 = (unsigned __int16 *)_calloc_crt(count: v5 + 1, size: 2u);
  *v3 = v7;
  if ( v7 != nullptr )
  {
    v8 = wcscpy_s(a1: (unsigned int)v3, _Dst: v7, _SizeInWords: v6, _Src: i);
    if ( v8 != 0 )
      _invoke_watson(a1: v8, a2: v9, a3: v10, a4: (unsigned int)v3, a5: v6, a6: (unsigned int)i);
    ++v3;
    goto LABEL_15;
  }
  free(pMem: _wenviron);
  _wenviron = nullptr;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FFD6
// Name: ___crtGetEnvironmentStringsW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsW()
{
  int v0; // eax
  int v1; // edi
  unsigned __int8 *EnvironmentStringsW; // esi
  unsigned __int8 *j; // eax
  unsigned int v5; // ebp
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ebx
  LPCH EnvironmentStrings; // eax
  char *v9; // ebp
  CHAR *i; // esi
  int v11; // eax
  int v12; // eax
  unsigned __int8 *v13; // eax
  char *v14; // edi
  wchar_t *v15; // esi
  int v16; // eax
  int v17; // [esp+10h] [ebp-4h]

  v0 = f_use_3;
  v1 = 0;
  EnvironmentStringsW = nullptr;
  if ( f_use_3 == 0 )
  {
    EnvironmentStringsW = (unsigned __int8 *)GetEnvironmentStringsW();
    if ( EnvironmentStringsW != nullptr )
    {
      f_use_3 = 1;
      goto LABEL_8;
    }
    if ( GetLastError() == 120 )
    {
      v0 = 2;
      f_use_3 = 2;
    }
    else
    {
      v0 = f_use_3;
    }
  }
  if ( v0 != 1 )
  {
    if ( v0 != 2 && v0 != 0 )
      return nullptr;
    EnvironmentStrings = GetEnvironmentStrings();
    v9 = EnvironmentStrings;
    if ( EnvironmentStrings == nullptr )
      return nullptr;
    for ( i = EnvironmentStrings; *i != 0; i += v12 + 1 )
    {
      v11 = MultiByteToWideChar(
              CodePage: 0,
              dwFlags: 1u,
              lpMultiByteStr: i,
              cbMultiByte: -1,
              lpWideCharStr: nullptr,
              cchWideChar: 0);
      if ( v11 == 0 )
        return nullptr;
      v1 += v11;
      strlen(buf: i);
    }
    v17 = v1 + 1;
    v13 = (unsigned __int8 *)_calloc_crt(count: v1 + 1, size: 2u);
    v7 = v13;
    if ( v13 != nullptr )
    {
      v14 = v9;
      v15 = (wchar_t *)v13;
      if ( *v9 == 0 )
      {
LABEL_28:
        *v15 = 0;
        FreeEnvironmentStringsA(penv: v9);
        return v7;
      }
      while ( MultiByteToWideChar(
                CodePage: 0,
                dwFlags: 1u,
                lpMultiByteStr: v14,
                cbMultiByte: -1,
                lpWideCharStr: v15,
                cchWideChar: v17 - (((char *)v15 - (char *)v7) >> 1)) != 0 )
      {
        strlen(buf: v14);
        v14 += v16 + 1;
        v15 += wcslen(wcs: v15) + 1;
        if ( *v14 == 0 )
          goto LABEL_28;
      }
      free(pMem: v7);
    }
    FreeEnvironmentStringsA(penv: v9);
    return nullptr;
  }
LABEL_8:
  if ( EnvironmentStringsW == nullptr )
  {
    EnvironmentStringsW = (unsigned __int8 *)GetEnvironmentStringsW();
    if ( EnvironmentStringsW == nullptr )
      return nullptr;
  }
  for ( j = EnvironmentStringsW; *(_WORD *)j != 0; j += 2 )
  {
    do
      j += 2;
    while ( *(_WORD *)j != 0 );
  }
  v5 = j - EnvironmentStringsW + 2;
  v6 = (unsigned __int8 *)_malloc_crt(size: v5);
  v7 = v6;
  if ( v6 != nullptr )
    memcpy(dst: v6, src: EnvironmentStringsW, count: v5);
  FreeEnvironmentStringsW(penv: (LPWCH)EnvironmentStringsW);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00410137
// Name: _wcschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcschr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  for ( result = (unsigned __int16 *)string; *result != 0; ++result )
  {
    if ( *result == ch )
      return result;
  }
  if ( *result != ch )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410159
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = (unsigned __int8)outbuffer[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = outbuffer[0];
        result = (unsigned __int8)outbuffer[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_18:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x00410271
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410298
// Name: __dospawn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _dospawn@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        int mode,
        const char *name,
        char *cmdblk,
        char *envblk)
{
  void *hProcess; // ebx
  char *v7; // eax
  int v9; // esi
  signed int v10; // eax
  unsigned __int8 *v11; // eax
  unsigned __int8 *lpReserved2; // eax
  unsigned __int8 *v13; // ecx
  unsigned __int8 *v14; // edi
  ioinfo *v15; // eax
  char osfile; // dl
  _BYTE *v17; // ecx
  int v18; // edx
  unsigned __int8 *j; // eax
  int v20; // edi
  BOOL v21; // esi
  DWORD LastError; // edi
  _STARTUPINFOA StartupInfo; // [esp+8h] [ebp-68h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+4Ch] [ebp-24h] BYREF
  unsigned int exitcode; // [esp+5Ch] [ebp-14h] BYREF
  char *CommandLine; // [esp+60h] [ebp-10h]
  unsigned int fdwCreate; // [esp+64h] [ebp-Ch]
  int i; // [esp+68h] [ebp-8h]
  char background; // [esp+6Fh] [ebp-1h]

  hProcess = nullptr;
  fdwCreate = 0;
  background = 0;
  if ( (unsigned int)mode >= 2 )
  {
    if ( mode <= 1 )
      goto LABEL_7;
    if ( mode > 3 )
    {
      if ( mode == 4 )
      {
        background = 1;
        goto LABEL_6;
      }
LABEL_7:
      *__doserrno() = 0;
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: a2);
      return -1;
    }
  }
LABEL_6:
  v7 = cmdblk;
  CommandLine = cmdblk;
  while ( *v7 != 0 )
  {
    do
      ++v7;
    while ( *v7 != 0 );
    if ( v7[1] != 0 )
      *v7++ = 32;
  }
  memset(dst: (int)&StartupInfo, value: nullptr, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  v9 = _nhandle;
  if ( _nhandle == 0 )
    goto LABEL_47;
  v10 = _nhandle - 1;
  do
  {
    if ( __pioinfo[v10 >> 5][v10 & 0x1F].osfile != 0 )
      break;
    --v9;
    --v10;
  }
  while ( v9 != 0 );
  if ( v9 >= 0 )
  {
LABEL_47:
    if ( (unsigned int)v9 < 0x3332 )
    {
      StartupInfo.cbReserved2 = 5 * v9 + 4;
      v11 = (unsigned __int8 *)_calloc_crt(count: StartupInfo.cbReserved2, size: 1u);
      StartupInfo.lpReserved2 = v11;
      if ( v11 != nullptr )
      {
        *(_DWORD *)v11 = v9;
        lpReserved2 = StartupInfo.lpReserved2;
        v13 = StartupInfo.lpReserved2 + 4;
        v14 = &StartupInfo.lpReserved2[v9 + 4];
        i = 0;
        if ( v9 > 0 )
        {
          do
          {
            v15 = &__pioinfo[i >> 5][i & 0x1F];
            osfile = v15->osfile;
            if ( (osfile & 0x10) != 0 )
            {
              *v13 = 0;
              *(_DWORD *)v14 = -1;
            }
            else
            {
              *v13 = osfile;
              *(_DWORD *)v14 = v15->osfhnd;
            }
            ++i;
            ++v13;
            v14 += 4;
          }
          while ( i < v9 );
          lpReserved2 = StartupInfo.lpReserved2;
        }
        if ( background != 0 )
        {
          v17 = lpReserved2 + 4;
          v18 = 0;
          for ( j = &lpReserved2[v9 + 4]; ; j += 4 )
          {
            v20 = v9 >= 3 ? 3 : v9;
            if ( v18 >= v20 )
              break;
            *v17 = 0;
            *(_DWORD *)j = -1;
            ++v18;
            ++v17;
          }
          fdwCreate = 8;
        }
        *__doserrno() = 0;
        v21 = CreateProcessA(
                lpApplicationName: name,
                lpCommandLine: CommandLine,
                lpProcessAttributes: nullptr,
                lpThreadAttributes: nullptr,
                bInheritHandles: true,
                dwCreationFlags: fdwCreate,
                lpEnvironment: envblk,
                lpCurrentDirectory: nullptr,
                lpStartupInfo: &StartupInfo,
                lpProcessInformation: &ProcessInformation);
        LastError = GetLastError();
        free(pMem: StartupInfo.lpReserved2);
        if ( v21 )
        {
          if ( mode == 2 )
            _exit(code: 0);
          if ( mode != 0 )
          {
            if ( mode != 4 )
            {
              hProcess = ProcessInformation.hProcess;
              goto LABEL_42;
            }
          }
          else
          {
            WaitForSingleObject(hHandle: ProcessInformation.hProcess, dwMilliseconds: 0xFFFFFFFF);
            GetExitCodeProcess(hProcess: ProcessInformation.hProcess, lpExitCode: &exitcode);
            hProcess = (void *)exitcode;
          }
          CloseHandle(hObject: ProcessInformation.hProcess);
LABEL_42:
          CloseHandle(hObject: ProcessInformation.hThread);
          return (int)hProcess;
        }
        _dosmaperr(oserrno: LastError);
        return -1;
      }
    }
  }
  *_errno() = 12;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004104A5
// Name: __cenvarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cenvarg(const char **argv, char **envp, char **argblk, char **envblk)
{
  const char *const *v4; // edi
  char *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  char *v8; // eax
  void **v9; // esi
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  int v15; // edi
  int v16; // eax
  char **v17; // esi
  char *v18; // eax
  int v19; // edi
  int v20; // eax
  char *EnvironmentStringsA; // eax
  const char **v22; // edi
  char *v23; // esi
  char *v24; // esi
  char v25; // cl
  char *v26; // esi
  int v27; // eax
  int v28; // ecx
  char *v29; // ecx
  int v30; // eax
  char *v31; // eax
  const unsigned __int8 **v32; // esi
  unsigned int v33; // edi
  unsigned int v34; // eax
  char *v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // ecx
  int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // edx
  unsigned int v42; // ecx
  int v43; // eax
  char *v44; // esi
  unsigned __int8 *v45; // esi
  const char **i; // edi
  unsigned int v47; // eax
  unsigned int v48; // edx
  unsigned int v49; // ecx
  int v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // edx
  unsigned int v53; // ecx
  unsigned int v54; // eax
  unsigned int v55; // edx
  unsigned int v56; // ecx
  unsigned int v57; // eax
  unsigned int v58; // edx
  unsigned int v59; // ecx
  unsigned int env_len; // [esp+Ch] [ebp-40h]
  int defined; // [esp+10h] [ebp-3Ch]
  unsigned int v62; // [esp+18h] [ebp-34h]
  unsigned int envsize; // [esp+1Ch] [ebp-30h]
  int cwd_end; // [esp+24h] [ebp-28h]
  int retval; // [esp+28h] [ebp-24h]
  int cwd_start; // [esp+30h] [ebp-1Ch]
  char *envbuf; // [esp+38h] [ebp-14h] BYREF
  char envpfx[12]; // [esp+3Ch] [ebp-10h] BYREF

  strcpy(envpfx, "SystemRoot");
  v4 = argv;
  v5 = (char *)*argv;
  retval = 0;
  envbuf = nullptr;
  defined = 0;
  v6 = 2;
  while ( v5 != nullptr )
  {
    strlen(buf: v5);
    ++v4;
    v6 += v7 + 1;
    v5 = (char *)*v4;
  }
  v62 = v6;
  v8 = (char *)_calloc_crt(count: v6, size: 1u);
  v9 = (void **)argblk;
  *argblk = v8;
  if ( v8 == nullptr )
  {
    *envblk = nullptr;
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v11 = _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: envpfx);
  if ( v11 != 0 )
  {
    if ( v11 == 22 )
      _invoke_watson(a1: 0x16u, a2: v12, a3: v13, a4: 0, a5: (unsigned int)v4, a6: (unsigned int)argblk);
    goto LABEL_18;
  }
  strlen(buf: envpfx);
  v15 = v14 + 2;
  envsize = v14 + 2;
  if ( envbuf != nullptr )
  {
    strlen(buf: envbuf);
    envsize = v16 + v15;
  }
  if ( envp == nullptr )
  {
    *envblk = nullptr;
    goto LABEL_20;
  }
  v17 = envp;
  v18 = *envp;
  v19 = 2;
  while ( v18 != nullptr )
  {
    strlen(buf: v18);
    ++v17;
    v19 += v20 + 1;
    v18 = *v17;
  }
  EnvironmentStringsA = _aenvptr;
  if ( _aenvptr != nullptr
    || (EnvironmentStringsA = (char *)__crtGetEnvironmentStringsA(),
        _aenvptr = EnvironmentStringsA,
        EnvironmentStringsA != nullptr) )
  {
    cwd_start = 0;
    if ( *EnvironmentStringsA != 0 )
    {
      v25 = *EnvironmentStringsA;
      v26 = EnvironmentStringsA;
      do
      {
        if ( v25 == 61 )
          break;
        strlen(buf: v26);
        v28 = cwd_start + v27 + 1;
        EnvironmentStringsA = _aenvptr;
        v26 = &_aenvptr[v28];
        cwd_start = v28;
        v25 = _aenvptr[v28];
      }
      while ( v25 != 0 );
    }
    v29 = (char *)cwd_start;
    for ( cwd_end = cwd_start; ; cwd_end = (int)EnvironmentStringsA )
    {
      v31 = &EnvironmentStringsA[(_DWORD)v29];
      if ( *v31 != 61 || v31[1] == 0 || v31[2] != 58 || v31[3] != 61 )
        break;
      strlen(buf: v31 + 4);
      EnvironmentStringsA = (char *)(cwd_end + v30 + 5);
      v29 = _aenvptr;
    }
    v32 = (const unsigned __int8 **)envp;
    v33 = cwd_end - cwd_start + v19;
    env_len = v33;
    while ( 1 )
    {
      if ( *v32 == nullptr )
      {
        v33 += envsize;
        goto LABEL_37;
      }
      strlen(buf: envpfx);
      if ( _mbsnicmp(s1: *v32, s2: (const unsigned __int8 *)envpfx, n: v34) == 0 )
        break;
      ++v32;
    }
    defined = 1;
LABEL_37:
    v35 = (char *)_calloc_crt(count: v33, size: 1u);
    v9 = (void **)argblk;
    *envblk = v35;
    if ( v35 == nullptr )
    {
      free(pMem: *argblk);
      *argblk = nullptr;
      *_errno() = 12;
      retval = -1;
      *__doserrno() = 8;
      goto done;
    }
LABEL_20:
    v22 = argv;
    v23 = (char *)*v9;
    if ( *argv != nullptr )
    {
      v36 = strcpy_s(a1: (unsigned int)argv, _Dst: v23, _SizeInBytes: v62, _Src: *argv);
      if ( v36 != 0 )
        _invoke_watson(a1: v36, a2: v37, a3: v38, a4: 0, a5: (unsigned int)argv, a6: (unsigned int)v23);
      strlen(buf: (char *)*argv);
      v24 = &v23[v39 + 1];
      v22 = argv + 1;
    }
    else
    {
      v24 = v23 + 1;
    }
    while ( *v22 != nullptr )
    {
      v40 = strcpy_s(a1: (unsigned int)v22, _Dst: v24, _SizeInBytes: v62 + *argblk - v24, _Src: *v22);
      if ( v40 != 0 )
        _invoke_watson(a1: v40, a2: v41, a3: v42, a4: 0, a5: (unsigned int)v22, a6: (unsigned int)v24);
      strlen(buf: (char *)*v22);
      v44 = &v24[v43];
      ++v22;
      *v44 = 32;
      v24 = v44 + 1;
    }
    *(v24 - 1) = 0;
    *v24 = 0;
    v45 = (unsigned __int8 *)*envblk;
    if ( envp != nullptr )
    {
      memcpy(dst: v45, src: (unsigned __int8 *)&_aenvptr[cwd_start], count: cwd_end - cwd_start);
      v45 += cwd_end - cwd_start;
      for ( i = (const char **)envp; *i != nullptr; ++i )
      {
        v47 = strcpy_s(
                a1: (unsigned int)i,
                _Dst: (char *)v45,
                _SizeInBytes: (unsigned int)&(*envblk)[env_len - (_DWORD)v45],
                _Src: *i);
        if ( v47 != 0 )
          _invoke_watson(a1: v47, a2: v48, a3: v49, a4: 0, a5: (unsigned int)i, a6: (unsigned int)v45);
        strlen(buf: (char *)*i);
        v45 += v50 + 1;
      }
      if ( defined == 0 )
      {
        v51 = strcpy_s(a1: envsize, _Dst: (char *)v45, _SizeInBytes: envsize, _Src: envpfx);
        if ( v51 != 0 )
          _invoke_watson(a1: v51, a2: v52, a3: v53, a4: 0, a5: envsize, a6: (unsigned int)v45);
        v54 = strcat_s(a1: envsize, _Dst: (char *)v45, _SizeInBytes: envsize, _Src: "=");
        if ( v54 != 0 )
          _invoke_watson(a1: v54, a2: v55, a3: v56, a4: 0, a5: envsize, a6: (unsigned int)v45);
        if ( envbuf != nullptr )
        {
          v57 = strcat_s(a1: envsize, _Dst: (char *)v45, _SizeInBytes: envsize, _Src: envbuf);
          if ( v57 != 0 )
            _invoke_watson(a1: v57, a2: v58, a3: v59, a4: 0, a5: envsize, a6: (unsigned int)v45);
        }
        v45 += envsize;
      }
    }
    if ( v45 != nullptr )
    {
      if ( v45 == (unsigned __int8 *)*envblk )
        *v45++ = 0;
      *v45 = 0;
    }
    goto done;
  }
  v9 = (void **)argblk;
LABEL_18:
  retval = -1;
  free(pMem: *v9);
  *v9 = nullptr;
  *envblk = nullptr;
done:
  if ( _aenvptr != nullptr )
    free(pMem: _aenvptr);
  _aenvptr = nullptr;
  if ( envbuf != nullptr )
    free(pMem: envbuf);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0041087C
// Name: __mbsrchr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsrchr_l(unsigned int a1@<edi>, unsigned __int8 *str, unsigned int c, localeinfo_struct *plocinfo)
{
  threadmbcinfostruct *mbcinfo; // esi
  char *v5; // ecx
  unsigned __int8 v6; // dl
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-14h] BYREF
  char *r; // [esp+18h] [ebp-4h]

  r = nullptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strrchr(string: str, chr: c);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v5 = (char *)str;
  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: (unsigned int)mbcinfo);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  do
  {
    v6 = *v5;
    v7 = (unsigned __int8)*v5;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) != 0 )
    {
      v6 = *++v5;
      if ( *v5 != 0 )
      {
        if ( c == (v6 | (v7 << 8)) )
          r = v5 - 1;
        goto LABEL_16;
      }
      v8 = r == nullptr;
    }
    else
    {
      v8 = c == v7;
    }
    if ( v8 )
      r = v5;
LABEL_16:
    ++v5;
  }
  while ( v6 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x0041093C
// Name: __mbsrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsrchr(unsigned int a1@<edi>, unsigned __int8 *str, unsigned int c)
{
  _mbsrchr_l(a1, str, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041094F
// Name: __free_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _free_osfhnd(int fh)
{
  int v1; // esi
  ioinfo *v2; // eax

  if ( fh < 0
    || fh >= _nhandle
    || (v1 = fh & 0x1F, ((v2 = &__pioinfo[fh >> 5][v1])->osfile & 1) == 0)
    || v2->osfhnd == -1 )
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
  else
  {
    if ( __app_type == 1 )
    {
      if ( fh != 0 )
      {
        if ( fh == 1 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF5, hHandle: nullptr);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF4, hHandle: nullptr);
        }
      }
      else
      {
        SetStdHandle(nStdHandle: 0xFFFFFFF6, hHandle: nullptr);
      }
    }
    __pioinfo[fh >> 5][v1].osfhnd = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004109D0
// Name: __get_osfhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_osfhandle@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh)
{
  ioinfo *v4; // eax

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  else if ( fh >= 0 && fh < _nhandle && ((v4 = &__pioinfo[fh >> 5][fh & 0x1F])->osfile & 1) != 0 )
  {
    return v4->osfhnd;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410A41
// Name: ___lock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl __lock_fhandle(int fh)
{
  ioinfo *v1; // esi
  BOOL retval; // [esp+10h] [ebp-1Ch]

  v1 = &__pioinfo[fh >> 5][fh & 0x1F];
  retval = true;
  if ( v1->lockinitflag == 0 )
  {
    _lock(locknum: 10);
    if ( v1->lockinitflag == 0 )
    {
      retval = __crtInitCritSecAndSpinCount(a1: 0, lpCriticalSection: &v1->lock, dwSpinCount: 0xFA0u);
      ++v1->lockinitflag;
    }
    _unlock(locknum: 10);
  }
  if ( retval )
    EnterCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00410AE1
// Name: __unlock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_fhandle(int fh)
{
  LeaveCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
}

//------------------------------------------------------------------------------
// Address: 0x00410B03
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __usercall _commit@<eax>(unsigned int a1@<edi>, int a2@<esi>, int filedes)
{
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (a1 = 4 * (filedes >> 5) + 4312448, (*(&__pioinfo[filedes >> 5]->osfile + (a2 = filedes & 0x1F)) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter(a1: 0, a2: a1, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh: filedes);
  if ( (__pioinfo[filedes >> 5][a2].osfile & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(a1: 0, a2: a1, fh: filedes);
    if ( FlushFileBuffers(hFile: osfhandle) )
      retval = 0;
    else
      retval = GetLastError();
    if ( retval == 0 )
      goto good;
    *__doserrno() = retval;
  }
  *_errno() = 9;
  retval = -1;
good:
  _unlock_fhandle(fh: filedes);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00410BE4
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00410C04
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind2(a1: *(_DWORD *)(a5 + 36), a2: *(_DWORD *)(a5 + 40));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410C49
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ecx
  int v7; // [esp-4h] [ebp-24h]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-20h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || a2 != -1 && v4 <= a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( *(_DWORD *)(v3 + 4 * v5 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: v6, a2: v7, a3: ExceptionList);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410CCD
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410CF0
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x410D04);
}

//------------------------------------------------------------------------------
// Address: 0x00410CF9
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge _NLG_Notify@<eax>(unsigned int result@<eax>, unsigned int a2@<ebp>, unsigned int a3)
{
  _NLG_Destination.dwCode = a3;
  _NLG_Destination.uoffDestination = result;
  _NLG_Destination.uoffFramePointer = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410D18
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x00410D1B
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __report_gsfailure()
{
  unsigned int v0; // eax
  unsigned int v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  unsigned int vars0; // [esp+328h] [ebp+0h]
  void *retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  GS_ContextRecord.Eax = v0;
  GS_ContextRecord.Ecx = v2;
  GS_ContextRecord.Edx = v1;
  GS_ContextRecord.Ebx = v3;
  GS_ContextRecord.Esi = v5;
  GS_ContextRecord.Edi = v4;
  LOWORD(GS_ContextRecord.SegSs) = __SS__;
  LOWORD(GS_ContextRecord.SegCs) = __CS__;
  LOWORD(GS_ContextRecord.SegDs) = __DS__;
  LOWORD(GS_ContextRecord.SegEs) = __ES__;
  LOWORD(GS_ContextRecord.SegFs) = __FS__;
  LOWORD(GS_ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  GS_ContextRecord.EFlags = v6;
  GS_ContextRecord.Ebp = vars0;
  GS_ContextRecord.Eip = (unsigned int)retaddr;
  GS_ContextRecord.Esp = (unsigned int)&v10;
  GS_ContextRecord.ContextFlags = 65537;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  UnhandledExceptionFilter(ExceptionInfo: &GS_ExceptionPointers);
  if ( DebuggerWasPresent == 0 )
    _crt_debugger_hook();
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000409);
}

//------------------------------------------------------------------------------
// Address: 0x00410E1F
// Name: __crtGetStringTypeA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetStringTypeA_stat(
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  localeinfo_struct *plocinfo; // ecx
  int v8; // eax
  wchar_t *v9; // ebx
  localeinfo_struct *v10; // edi
  int v11; // eax
  int v12; // edi
  unsigned int v13; // eax
  void *v14; // esp
  wchar_t *v15; // eax
  int v16; // eax
  char *v18; // esi
  int v19; // eax
  const char *v20; // eax
  BOOL StringTypeA; // edi
  _DWORD v22[3]; // [esp+0h] [ebp-14h] BYREF
  int retval2; // [esp+Ch] [ebp-8h] BYREF

  v8 = f_use_4;
  v9 = nullptr;
  v10 = plocinfo;
  if ( f_use_4 == 0 )
  {
    if ( GetStringTypeW(dwInfoType: 1u, lpSrcStr: &String2, cchSrc: 1, lpCharType: (LPWORD)&retval2) )
    {
      f_use_4 = 1;
      goto LABEL_10;
    }
    if ( GetLastError() == 120 )
    {
      v8 = 2;
      f_use_4 = 2;
    }
    else
    {
      v8 = f_use_4;
    }
  }
  if ( v8 != 2 && v8 != 0 )
  {
    if ( v8 != 1 )
      return 0;
LABEL_10:
    retval2 = 0;
    if ( code_page == 0 )
      code_page = v10->locinfo->lc_codepage;
    v11 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 8 * (bError != 0) + 1,
            lpMultiByteStr: lpSrcStr,
            cbMultiByte: cchSrc,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v12 = v11;
    if ( v11 == 0 )
      return 0;
    if ( v11 > 0 && (unsigned int)v11 <= 0x7FFFFFF0 )
    {
      v13 = 2 * v11 + 8;
      if ( v13 > 0x400 )
      {
        v15 = (wchar_t *)_malloc_crt(size: 2 * v12 + 8);
        if ( v15 != nullptr )
        {
          *(_DWORD *)v15 = 56797;
          goto LABEL_20;
        }
      }
      else
      {
        v14 = alloca(v13);
        v15 = (wchar_t *)v22;
        if ( v22 != nullptr )
        {
          v22[0] = 52428;
LABEL_20:
          v15 += 4;
        }
      }
      v9 = v15;
    }
    if ( v9 != nullptr )
    {
      memset(dst: (int)v9, value: nullptr, count: 2 * v12);
      v16 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 1u,
              lpMultiByteStr: lpSrcStr,
              cbMultiByte: cchSrc,
              lpWideCharStr: v9,
              cchWideChar: v12);
      if ( v16 != 0 )
        retval2 = GetStringTypeW(dwInfoType, lpSrcStr: v9, cchSrc: v16, lpCharType);
      _freea(_Memory: v9);
      return retval2;
    }
    return 0;
  }
  v18 = nullptr;
  if ( lcid == 0 )
    lcid = v10->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v10->locinfo->lc_codepage;
  v19 = __ansicp(lcid);
  if ( v19 == -1 )
    return 0;
  if ( v19 != code_page )
  {
    v20 = __convertcp(fromCP: code_page, toCP: v19, lpSrcStr, pcchSrc: &cchSrc, lpDestStr: nullptr, cchDest: 0);
    v18 = (char *)v20;
    if ( v20 == nullptr )
      return 0;
    lpSrcStr = v20;
  }
  StringTypeA = GetStringTypeA(Locale: lcid, dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( v18 != nullptr )
    free(pMem: v18);
  return StringTypeA;
}

//------------------------------------------------------------------------------
// Address: 0x00410FD7
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(dwInfoType, lpSrcStr, cchSrc, lpCharType, code_page, lcid, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411017
// Name: ___free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lc_time(__lc_time_data *lc_time)
{
  if ( lc_time != nullptr )
  {
    free(pMem: lc_time->wday_abbr[1]);
    free(pMem: lc_time->wday_abbr[2]);
    free(pMem: lc_time->wday_abbr[3]);
    free(pMem: lc_time->wday_abbr[4]);
    free(pMem: lc_time->wday_abbr[5]);
    free(pMem: lc_time->wday_abbr[6]);
    free(pMem: lc_time->wday_abbr[0]);
    free(pMem: lc_time->wday[1]);
    free(pMem: lc_time->wday[2]);
    free(pMem: lc_time->wday[3]);
    free(pMem: lc_time->wday[4]);
    free(pMem: lc_time->wday[5]);
    free(pMem: lc_time->wday[6]);
    free(pMem: lc_time->wday[0]);
    free(pMem: lc_time->month_abbr[0]);
    free(pMem: lc_time->month_abbr[1]);
    free(pMem: lc_time->month_abbr[2]);
    free(pMem: lc_time->month_abbr[3]);
    free(pMem: lc_time->month_abbr[4]);
    free(pMem: lc_time->month_abbr[5]);
    free(pMem: lc_time->month_abbr[6]);
    free(pMem: lc_time->month_abbr[7]);
    free(pMem: lc_time->month_abbr[8]);
    free(pMem: lc_time->month_abbr[9]);
    free(pMem: lc_time->month_abbr[10]);
    free(pMem: lc_time->month_abbr[11]);
    free(pMem: lc_time->month[0]);
    free(pMem: lc_time->month[1]);
    free(pMem: lc_time->month[2]);
    free(pMem: lc_time->month[3]);
    free(pMem: lc_time->month[4]);
    free(pMem: lc_time->month[5]);
    free(pMem: lc_time->month[6]);
    free(pMem: lc_time->month[7]);
    free(pMem: lc_time->month[8]);
    free(pMem: lc_time->month[9]);
    free(pMem: lc_time->month[10]);
    free(pMem: lc_time->month[11]);
    free(pMem: lc_time->ampm[0]);
    free(pMem: lc_time->ampm[1]);
    free(pMem: lc_time->ww_sdatefmt);
    free(pMem: lc_time->ww_ldatefmt);
    free(pMem: lc_time->ww_timefmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004111A7
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_num(lconv *l)
{
  char *grouping; // esi

  if ( l != nullptr )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(pMem: l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(pMem: l->thousands_sep);
    grouping = l->grouping;
    if ( grouping != __lconv_c.grouping )
      free(pMem: grouping);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004111E7
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_mon(lconv *l)
{
  char *negative_sign; // esi

  if ( l != nullptr )
  {
    if ( l->int_curr_symbol != __lconv_c.int_curr_symbol )
      free(pMem: l->int_curr_symbol);
    if ( l->currency_symbol != __lconv_c.currency_symbol )
      free(pMem: l->currency_symbol);
    if ( l->mon_decimal_point != __lconv_c.mon_decimal_point )
      free(pMem: l->mon_decimal_point);
    if ( l->mon_thousands_sep != __lconv_c.mon_thousands_sep )
      free(pMem: l->mon_thousands_sep);
    if ( l->mon_grouping != __lconv_c.mon_grouping )
      free(pMem: l->mon_grouping);
    if ( l->positive_sign != __lconv_c.positive_sign )
      free(pMem: l->positive_sign);
    negative_sign = l->negative_sign;
    if ( negative_sign != __lconv_c.negative_sign )
      free(pMem: negative_sign);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411270
// Name: _strcspn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcspn(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  int v5; // ecx
  signed __int32 v6[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v6, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v6, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v6, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x004112C0
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x00411300
// Name: ___ansicp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __ansicp(LCID lcid)
{
  char LCData[8]; // [esp+0h] [ebp-Ch] BYREF

  LCData[6] = 0;
  if ( GetLocaleInfoA(Locale: lcid, LCType: 0x1004u, lpLCData: LCData, cchData: 6) != 0 )
    return atol(nptr: LCData);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00411347
// Name: ___convertcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __convertcp(UINT fromCP, UINT toCP, char *lpSrcStr, int *pcchSrc, char *lpDestStr, int cchDest)
{
  int v6; // esi
  int v7; // eax
  bool v8; // cc
  unsigned int v9; // eax
  void *v10; // esp
  unsigned __int16 *v11; // eax
  char *v13; // ebx
  char *v14; // eax
  int v15; // eax
  _DWORD v16[3]; // [esp+0h] [ebp-40h] BYREF
  LPSTR lpMultiByteStr; // [esp+Ch] [ebp-34h]
  int *v18; // [esp+10h] [ebp-30h]
  int sb; // [esp+14h] [ebp-2Ch]
  unsigned __int8 *buf; // [esp+18h] [ebp-28h]
  int cchSrc; // [esp+1Ch] [ebp-24h]
  char *cbuffer; // [esp+20h] [ebp-20h]
  unsigned __int16 *wbuffer; // [esp+24h] [ebp-1Ch]
  _cpinfo cpi; // [esp+28h] [ebp-18h] BYREF

  buf = (unsigned __int8 *)lpSrcStr;
  v18 = pcchSrc;
  cchSrc = *pcchSrc;
  lpMultiByteStr = lpDestStr;
  cbuffer = nullptr;
  sb = 0;
  if ( fromCP != toCP )
  {
    if ( GetCPInfo(CodePage: fromCP, lpCPInfo: &cpi)
      && cpi.MaxCharSize == 1
      && GetCPInfo(CodePage: toCP, lpCPInfo: &cpi)
      && cpi.MaxCharSize == 1 )
    {
      v6 = cchSrc;
      sb = 1;
      if ( cchSrc == -1 )
      {
        strlen((char *)buf);
        v6 = v7 + 1;
      }
      v8 = v6 <= 0;
    }
    else
    {
      v6 = MultiByteToWideChar(
             CodePage: fromCP,
             dwFlags: 1u,
             lpMultiByteStr: (LPCCH)buf,
             cbMultiByte: cchSrc,
             lpWideCharStr: nullptr,
             cchWideChar: 0);
      v8 = v6 <= 0;
      if ( v6 == 0 )
        return nullptr;
    }
    if ( v8 || (unsigned int)v6 > 0x7FFFFFF0 )
    {
      wbuffer = nullptr;
LABEL_21:
      if ( wbuffer != nullptr )
      {
        memset(dst: (int)wbuffer, value: nullptr, count: 2 * v6);
        if ( MultiByteToWideChar(
               CodePage: fromCP,
               dwFlags: 1u,
               lpMultiByteStr: (LPCCH)buf,
               cbMultiByte: cchSrc,
               lpWideCharStr: wbuffer,
               cchWideChar: v6) != 0 )
        {
          v13 = lpMultiByteStr;
          if ( lpMultiByteStr != nullptr )
          {
            if ( WideCharToMultiByte(
                   CodePage: toCP,
                   dwFlags: 0,
                   lpWideCharStr: wbuffer,
                   cchWideChar: v6,
                   lpMultiByteStr,
                   cbMultiByte: cchDest,
                   lpDefaultChar: nullptr,
                   lpUsedDefaultChar: nullptr) != 0 )
              cbuffer = v13;
          }
          else if ( sb != 0
                 || (v6 = WideCharToMultiByte(
                            CodePage: toCP,
                            dwFlags: 0,
                            lpWideCharStr: wbuffer,
                            cchWideChar: v6,
                            lpMultiByteStr: nullptr,
                            cbMultiByte: 0,
                            lpDefaultChar: nullptr,
                            lpUsedDefaultChar: nullptr)) != 0 )
          {
            v14 = (char *)_calloc_crt(count: 1u, size: v6);
            cbuffer = v14;
            if ( v14 != nullptr )
            {
              v15 = WideCharToMultiByte(
                      CodePage: toCP,
                      dwFlags: 0,
                      lpWideCharStr: wbuffer,
                      cchWideChar: v6,
                      lpMultiByteStr: v14,
                      cbMultiByte: v6,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
              if ( v15 != 0 )
              {
                if ( cchSrc != -1 )
                  *v18 = v15;
              }
              else
              {
                free(pMem: cbuffer);
                cbuffer = nullptr;
              }
            }
          }
        }
        _freea(_Memory: wbuffer);
        return cbuffer;
      }
      return nullptr;
    }
    v9 = 2 * v6 + 8;
    if ( v9 > 0x400 )
    {
      v11 = (unsigned __int16 *)_malloc_crt(size: 2 * v6 + 8);
      if ( v11 != nullptr )
      {
        *(_DWORD *)v11 = 56797;
        goto LABEL_18;
      }
    }
    else
    {
      v10 = alloca(v9);
      v11 = (unsigned __int16 *)v16;
      if ( v16 != nullptr )
      {
        v16[0] = 52428;
LABEL_18:
        v11 += 4;
      }
    }
    wbuffer = v11;
    goto LABEL_21;
  }
  return cbuffer;
}

//------------------------------------------------------------------------------
// Address: 0x004114F9
// Name: __ld12tod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  unsigned int v55; // ebx
  int v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  int v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  int v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(_DWORD *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = nullptr;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = DoubleFormat.precision - 1;
    v64 = v3;
    v65 = DoubleFormat.precision / 32;
    v9 = &v60 + DoubleFormat.precision / 32;
    v66 = 31 - DoubleFormat.precision % 32;
    if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a != nullptr )
      ++v3;
    if ( v3 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v3 > DoubleFormat.min_exp )
      {
        if ( v3 < DoubleFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = DoubleFormat.bias + v3;
          v50 = DoubleFormat.exp_width / 32;
          v51 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12g = nullptr;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = DoubleFormat.exp_width / 32;
          v44 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12f = nullptr;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = DoubleFormat.bias + DoubleFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (DoubleFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (DoubleFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = nullptr;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = DoubleFormat.precision - 1;
      v25 = DoubleFormat.precision / 32;
      v65 = DoubleFormat.precision / 32;
      v26 = &v60 + DoubleFormat.precision / 32;
      v64 = 31 - DoubleFormat.precision % 32;
      if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (DoubleFormat.exp_width + 1) / 32;
      v37 = (DoubleFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = nullptr;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  v55 = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v56 = v61;
    HIDWORD(d->x) = v55;
    LODWORD(d->x) = v56;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411A3B
// Name: __ld12tof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tof(_LDBL12 *pld12, _CRT_FLOAT *f)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  float v55; // ebx
  float v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  float v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  float v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(float *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = nullptr;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = FloatFormat.precision - 1;
    v64 = v3;
    v65 = FloatFormat.precision / 32;
    v9 = &v60 + FloatFormat.precision / 32;
    v66 = 31 - FloatFormat.precision % 32;
    if ( ((1 << (31 - FloatFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a != nullptr )
      ++v3;
    if ( v3 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v3 > FloatFormat.min_exp )
      {
        if ( v3 < FloatFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = FloatFormat.bias + v3;
          v50 = FloatFormat.exp_width / 32;
          v51 = FloatFormat.exp_width % 32;
          v65 = 0;
          pld12g = nullptr;
          v67 = 32 - FloatFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0.0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = FloatFormat.exp_width / 32;
          v44 = FloatFormat.exp_width % 32;
          v65 = 0;
          pld12f = nullptr;
          v67 = 32 - FloatFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = FloatFormat.bias + FloatFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (FloatFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (FloatFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = nullptr;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = FloatFormat.precision - 1;
      v25 = FloatFormat.precision / 32;
      v65 = FloatFormat.precision / 32;
      v26 = &v60 + FloatFormat.precision / 32;
      v64 = 31 - FloatFormat.precision % 32;
      if ( ((1 << (31 - FloatFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (FloatFormat.exp_width + 1) / 32;
      v37 = (FloatFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = nullptr;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0.0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0.0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  LODWORD(v55) = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v56 = v61;
    f[1].f = v55;
    f->f = v56;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411F7D
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l(wchar_t *pwc, const char *s, signed int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  if ( s == nullptr || n == 0 )
    return 0;
  if ( *s == 0 )
  {
    if ( pwc != nullptr )
      *pwc = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( pwc != nullptr )
      *pwc = *(unsigned __int8 *)s;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(c: *s, plocinfo: &_loc_update.localeinfo) != 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    mb_cur_max = _loc_update.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && n >= mb_cur_max
      && (v7 = MultiByteToWideChar(
                 CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
                 dwFlags: 9u,
                 lpMultiByteStr: s,
                 cbMultiByte: mb_cur_max,
                 lpWideCharStr: pwc,
                 cchWideChar: pwc != nullptr) == 0,
          locinfo = _loc_update.localeinfo.locinfo,
          !v7)
      || (unsigned int)n >= locinfo->mb_cur_max && s[1] != 0 )
    {
      result = locinfo->mb_cur_max;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(
              CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
              dwFlags: 9u,
              lpMultiByteStr: s,
              cbMultiByte: 1,
              lpWideCharStr: pwc,
              cchWideChar: pwc != nullptr) != 0 )
  {
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00412090
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004120A7
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // edi
  int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  int v10; // esi
  unsigned int v11; // ecx
  unsigned int v12; // edi
  int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // esi
  int v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // edi
  int v20; // ecx
  __int16 expn; // [esp+Ch] [ebp-18h]
  int v22; // [esp+10h] [ebp-14h]
  int v23; // [esp+10h] [ebp-14h]
  unsigned int tmp_4; // [esp+18h] [ebp-Ch]
  int tmp_8; // [esp+1Ch] [ebp-8h]

  expn = 16462;
  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  for ( *(_DWORD *)&ld12->ld12[8] = 0; manlen != 0; ++manptr )
  {
    tmp_4 = *(_DWORD *)&ld12->ld12[4];
    tmp_8 = *(_DWORD *)&ld12->ld12[8];
    v22 = 0;
    v3 = __SPAIR64__(*(_QWORD *)&ld12->ld12[4] >> 31, *(__int64 *)ld12->ld12 >> 31) >> 31;
    v4 = *(_DWORD *)ld12->ld12;
    v5 = (2LL * *(_QWORD *)ld12->ld12) >> 31;
    v6 = 5 * *(_DWORD *)ld12->ld12;
    *(_DWORD *)ld12->ld12 *= 4;
    *(_DWORD *)&ld12->ld12[4] = v5;
    *(_DWORD *)&ld12->ld12[8] = v3;
    if ( 5 * v4 < 4 * v4 || v6 < v4 )
      v22 = 1;
    v7 = 0;
    *(_DWORD *)ld12->ld12 = v6;
    if ( v22 != 0 )
    {
      if ( v5 + 1 < v5 || v5 == -1 )
        v7 = 1;
      *(_DWORD *)&ld12->ld12[4] = v5 + 1;
      if ( v7 != 0 )
        *(_DWORD *)&ld12->ld12[8] = v3 + 1;
    }
    v8 = *(_DWORD *)&ld12->ld12[4];
    v9 = v8 + tmp_4;
    v10 = 0;
    if ( v8 + tmp_4 < v8 || v9 < tmp_4 )
      v10 = 1;
    *(_DWORD *)&ld12->ld12[4] = v9;
    if ( v10 != 0 )
      ++*(_DWORD *)&ld12->ld12[8];
    *(_DWORD *)&ld12->ld12[8] += tmp_8;
    v23 = 0;
    v11 = 2 * v6;
    v12 = (v6 >> 31) | (2 * v9);
    v13 = (v9 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
    *(_DWORD *)ld12->ld12 = v11;
    *(_DWORD *)&ld12->ld12[4] = v12;
    *(_DWORD *)&ld12->ld12[8] = v13;
    v14 = *manptr;
    v15 = v11 + v14;
    if ( v11 + v14 < v11 || v15 < v14 )
      v23 = 1;
    *(_DWORD *)ld12->ld12 = v15;
    if ( v23 != 0 )
    {
      v16 = 0;
      if ( v12 + 1 < v12 || v12 == -1 )
        v16 = 1;
      *(_DWORD *)&ld12->ld12[4] = v12 + 1;
      if ( v16 != 0 )
        *(_DWORD *)&ld12->ld12[8] = v13 + 1;
    }
    --manlen;
  }
  while ( *(_DWORD *)&ld12->ld12[8] == 0 )
  {
    v17 = *(_DWORD *)&ld12->ld12[4];
    *(_DWORD *)&ld12->ld12[8] = HIWORD(v17);
    expn -= 16;
    *(_QWORD *)ld12->ld12 = __PAIR64__(v17, *(_DWORD *)ld12->ld12) << 16;
  }
  if ( (*(_DWORD *)&ld12->ld12[8] & 0x8000) == 0 )
  {
    do
    {
      v18 = *(_DWORD *)ld12->ld12;
      v19 = *(_DWORD *)&ld12->ld12[4];
      --expn;
      *(_DWORD *)ld12->ld12 *= 2;
      v20 = (v19 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
      *(_DWORD *)&ld12->ld12[4] = (v18 >> 31) | (2 * v19);
      *(_DWORD *)&ld12->ld12[8] = v20;
    }
    while ( (v20 & 0x8000) == 0 );
  }
  *(_WORD *)&ld12->ld12[10] = expn;
}

//------------------------------------------------------------------------------
// Address: 0x00412273
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  __int16 v4; // cx
  unsigned __int16 v5; // dx
  int v6; // esi
  unsigned int v7; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ecx
  int v15; // ebx
  int v16; // ecx
  _LDBL12 *v17; // ecx
  __int16 v18; // di
  __int16 v19; // cx
  unsigned __int16 v20; // di
  __int16 v21; // cx
  unsigned __int16 v22; // ax
  _BYTE *v23; // edi
  unsigned int v24; // edi
  unsigned int v25; // edx
  unsigned int v26; // esi
  __int16 v27; // ax
  unsigned int v28; // edx
  int v29; // edi
  int v30; // edx
  int v31; // edx
  int v32; // edi
  int v33; // edx
  bool v34; // zf
  __int16 v35; // cx
  unsigned __int16 v36; // di
  _WORD *v37; // eax
  unsigned int v38; // edx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  __int16 v41; // di
  unsigned int v42; // edx
  int v43; // ebx
  int v44; // edx
  int v45; // eax
  int v46; // edx
  int v47; // ebx
  int v48; // edx
  int v49; // esi
  int k; // ebx
  unsigned int v51; // eax
  int v52; // edi
  int v53; // eax
  int v54; // esi
  int v55; // eax
  int v56; // edi
  int v57; // eax
  char *man; // ebx
  unsigned int v59; // edx
  unsigned int v60; // edi
  unsigned int v61; // ecx
  int v62; // esi
  int v63; // ecx
  unsigned int v64; // esi
  unsigned int v65; // edi
  int v66; // edx
  unsigned int v67; // edx
  char *v68; // ebx
  char v69; // al
  char *v70; // ebx
  _FloatOutStruct *v71; // eax
  char v72; // bl
  int v73; // [esp+10h] [ebp-70h]
  __int16 sign; // [esp+14h] [ebp-6Ch]
  _LDBL12 *v75; // [esp+18h] [ebp-68h]
  _LDBL12 *p_tmp12; // [esp+1Ch] [ebp-64h]
  int v77; // [esp+24h] [ebp-5Ch]
  unsigned __int8 *v78; // [esp+24h] [ebp-5Ch]
  unsigned __int8 *v79; // [esp+28h] [ebp-58h]
  int v80; // [esp+28h] [ebp-58h]
  unsigned __int8 *v81; // [esp+2Ch] [ebp-54h]
  int v82; // [esp+2Ch] [ebp-54h]
  int v83; // [esp+30h] [ebp-50h]
  int v84; // [esp+30h] [ebp-50h]
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  int v87; // [esp+38h] [ebp-48h]
  unsigned __int8 *v88; // [esp+38h] [ebp-48h]
  _WORD *v89; // [esp+3Ch] [ebp-44h]
  int v90; // [esp+3Ch] [ebp-44h]
  int v91; // [esp+3Ch] [ebp-44h]
  unsigned int v92; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v95; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v99[12]; // [esp+70h] [ebp-10h] BYREF

  *(_LDOUBLE *)v99 = ld;
  v4 = *(_WORD *)&ld.ld[8] & 0x8000;
  v5 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 10);
  ld12_one_tenth.ld12[10] = -5;
  ld12_one_tenth.ld12[11] = 63;
  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  v6 = *(_DWORD *)&v99[4];
  v7 = *(_DWORD *)v99;
  if ( v5 == 0 && *(_DWORD *)&v99[4] == 0 && *(_DWORD *)v99 == 0 )
  {
    fos->exp = 0;
    fos->sign = v4 != -32768 ? 32 : 45;
    fos->ManLen = 1;
    fos->man[0] = 48;
    fos->man[1] = 0;
    return 1;
  }
  if ( v5 == 0x7FFF )
  {
    fos->exp = 1;
    if ( (v6 != 0x80000000 || v7 != 0) && (v6 & 0x40000000) == 0 )
    {
      v9 = strcpy_s(a1: v7, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#SNAN");
LABEL_25:
      if ( v9 != 0 )
        _invoke_watson(a1: v9, a2: v10, a3: v11, a4: (unsigned int)fos, a5: v7, a6: 0);
      fos->ManLen = 6;
      return 0;
    }
    if ( v4 != 0 && v6 == -1073741824 )
    {
      if ( v7 == 0 )
      {
        v12 = strcpy_s(a1: 0, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#IND");
LABEL_21:
        if ( v12 != 0 )
          _invoke_watson(a1: v12, a2: v13, a3: v14, a4: (unsigned int)fos, a5: 0, a6: 0);
        fos->ManLen = 5;
        return 0;
      }
    }
    else if ( v6 == 0x80000000 && v7 == 0 )
    {
      v12 = strcpy_s(a1: 0, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#INF");
      goto LABEL_21;
    }
    v9 = strcpy_s(a1: v7, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#QNAN");
    goto LABEL_25;
  }
  digcount = (77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16;
  v15 = -digcount;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v99[4];
  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)v99;
  *(_WORD *)ld12.ld12 = 0;
  v75 = &_pow10pos[-8];
  if ( digcount != 0 )
  {
    if ( (__int16)((77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16) > 0 )
    {
      v15 = (__int16)((77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16);
      v75 = &_pow10neg[-8];
    }
    while ( v15 != 0 )
    {
      v75 += 7;
      v16 = v15 & 7;
      v15 >>= 3;
      if ( v16 != 0 )
      {
        v17 = &v75[v16];
        p_tmp12 = v17;
        if ( *(_WORD *)v17->ld12 >= 0x8000u )
        {
          tmp12 = *v17;
          --*(_DWORD *)&tmp12.ld12[2];
          p_tmp12 = &tmp12;
          v17 = &tmp12;
        }
        v18 = *(_WORD *)&v17->ld12[10];
        v19 = *(_WORD *)&ld12.ld12[10] ^ v18;
        v20 = v18 & 0x7FFF;
        v87 = 0;
        memset(v99, 0, sizeof(v99));
        v21 = v19 & 0x8000;
        v22 = v20 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF || v20 >= 0x7FFFu || v22 > 0xBFFDu )
        {
LABEL_81:
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
          *(_DWORD *)&ld12.ld12[8] = v21 != 0 ? -32768 : 2147450880;
          continue;
        }
        if ( v22 <= 0x3FBFu )
          goto LABEL_40;
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
        {
          ++v22;
          if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
            && *(_DWORD *)&ld12.ld12[4] == 0
            && *(_DWORD *)ld12.ld12 == 0 )
          {
            *(_WORD *)&ld12.ld12[10] = 0;
            continue;
          }
        }
        if ( v20 != 0
          || (++v22, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
          || *(_DWORD *)&p_tmp12->ld12[4] != 0
          || *(_DWORD *)p_tmp12->ld12 != 0 )
        {
          v23 = &v99[4];
          v77 = 0;
          v89 = &v99[4];
          for ( i = 5; i > 0; --i )
          {
            v83 = i;
            v79 = &ld12.ld12[2 * v77];
            v81 = &p_tmp12->ld12[8];
            do
            {
              v24 = *((_DWORD *)v23 - 1);
              v25 = *(unsigned __int16 *)v81 * *(unsigned __int16 *)v79;
              v73 = 0;
              v26 = v24 + v25;
              if ( v24 + v25 < v24 || v26 < v25 )
                v73 = 1;
              v23 = v89;
              *((_DWORD *)v89 - 1) = v26;
              if ( v73 != 0 )
                ++*v89;
              v79 += 2;
              v81 -= 2;
              --v83;
            }
            while ( v83 > 0 );
            v23 = v89 + 1;
            ++v77;
            ++v89;
          }
          v27 = v22 - 16382;
          if ( v27 <= 0 )
            goto LABEL_170;
          do
          {
            if ( *(int *)&v99[8] < 0 )
              break;
            v28 = *(_DWORD *)v99;
            *(_DWORD *)v99 *= 2;
            v29 = (v28 >> 31) | (2 * *(_DWORD *)&v99[4]);
            v30 = *(__int64 *)&v99[4] >> 31;
            --v27;
            *(_DWORD *)&v99[4] = v29;
            *(_DWORD *)&v99[8] = v30;
          }
          while ( v27 > 0 );
          if ( v27 <= 0 )
          {
LABEL_170:
            if ( --v27 < 0 )
            {
              v90 = (unsigned __int16)-v27;
              v27 = 0;
              do
              {
                if ( (v99[0] & 1) != 0 )
                  ++v87;
                v31 = *(_DWORD *)&v99[8];
                *(_DWORD *)&v99[8] >>= 1;
                v32 = (v31 << 31) | (*(_DWORD *)&v99[4] >> 1);
                v33 = *(__int64 *)v99 >> 1;
                v34 = v90-- == 1;
                *(_DWORD *)&v99[4] = v32;
                *(_DWORD *)v99 = v33;
              }
              while ( !v34 );
              if ( v87 != 0 )
                *(_WORD *)v99 |= 1u;
            }
          }
          if ( *(_WORD *)v99 > 0x8000u || (*(_DWORD *)v99 & 0x1FFFF) == 0x18000 )
          {
            if ( *(_DWORD *)&v99[2] == -1 )
            {
              *(_DWORD *)&v99[2] = 0;
              if ( *(_DWORD *)&v99[6] == -1 )
              {
                *(_DWORD *)&v99[6] = 0;
                if ( *(_WORD *)&v99[10] == 0xFFFF )
                {
                  *(_WORD *)&v99[10] = 0x8000;
                  ++v27;
                }
                else
                {
                  ++*(_WORD *)&v99[10];
                }
              }
              else
              {
                ++*(_DWORD *)&v99[6];
              }
            }
            else
            {
              ++*(_DWORD *)&v99[2];
            }
          }
          if ( (unsigned __int16)v27 >= 0x7FFFu )
            goto LABEL_81;
          *(_WORD *)ld12.ld12 = *(_WORD *)&v99[2];
          *(_QWORD *)&ld12.ld12[2] = *(_QWORD *)&v99[4];
          *(_WORD *)&ld12.ld12[10] = v21 | v27;
        }
        else
        {
LABEL_40:
          memset(&ld12, 0, sizeof(ld12));
        }
      }
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] >= 0x3FFFu )
  {
    ++digcount;
    v35 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
    v80 = 0;
    memset(v99, 0, sizeof(v99));
    v36 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
    if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
      || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
      || v36 > 0xBFFDu )
    {
      *(_DWORD *)&ld12.ld12[8] = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) != 0
                               ? -32768
                               : 2147450880;
    }
    else
    {
      if ( v36 > 0x3FBFu )
      {
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
        {
          ++v36;
          if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
            && *(_DWORD *)&ld12.ld12[4] == 0
            && *(_DWORD *)ld12.ld12 == 0 )
          {
            *(_WORD *)&ld12.ld12[10] = 0;
            goto LABEL_132;
          }
        }
        if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
          || (++v36, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
          || *(_DWORD *)&ld12_one_tenth.ld12[4] != 0
          || *(_DWORD *)ld12_one_tenth.ld12 != 0 )
        {
          v82 = 0;
          v37 = &v99[4];
          for ( j = 5; j > 0; --j )
          {
            v84 = j;
            v78 = &ld12_one_tenth.ld12[8];
            v88 = &ld12.ld12[2 * v82];
            do
            {
              v91 = 0;
              v38 = *(unsigned __int16 *)v88 * *(unsigned __int16 *)v78;
              v39 = *((_DWORD *)v37 - 1);
              v40 = v39 + v38;
              if ( v39 + v38 < v39 || v40 < v38 )
                v91 = 1;
              *((_DWORD *)v37 - 1) = v40;
              if ( v91 != 0 )
                ++*v37;
              v88 += 2;
              v78 -= 2;
              --v84;
            }
            while ( v84 > 0 );
            ++v37;
            ++v82;
          }
          v41 = v36 - 16382;
          if ( v41 <= 0 )
            goto LABEL_171;
          do
          {
            if ( *(int *)&v99[8] < 0 )
              break;
            v42 = *(_DWORD *)v99;
            *(_DWORD *)v99 *= 2;
            v43 = (v42 >> 31) | (2 * *(_DWORD *)&v99[4]);
            v44 = *(__int64 *)&v99[4] >> 31;
            --v41;
            *(_DWORD *)&v99[4] = v43;
            *(_DWORD *)&v99[8] = v44;
          }
          while ( v41 > 0 );
          if ( v41 <= 0 )
          {
LABEL_171:
            if ( --v41 < 0 )
            {
              v45 = (unsigned __int16)-v41;
              v41 = 0;
              do
              {
                if ( (v99[0] & 1) != 0 )
                  ++v80;
                v46 = *(_DWORD *)&v99[8];
                *(_DWORD *)&v99[8] >>= 1;
                v47 = (v46 << 31) | (*(_DWORD *)&v99[4] >> 1);
                v48 = *(__int64 *)v99 >> 1;
                --v45;
                *(_DWORD *)&v99[4] = v47;
                *(_DWORD *)v99 = v48;
              }
              while ( v45 != 0 );
              if ( v80 != 0 )
                *(_WORD *)v99 |= 1u;
            }
          }
          if ( *(_WORD *)v99 > 0x8000u || (*(_DWORD *)v99 & 0x1FFFF) == 0x18000 )
          {
            if ( *(_DWORD *)&v99[2] == -1 )
            {
              *(_DWORD *)&v99[2] = 0;
              if ( *(_DWORD *)&v99[6] == -1 )
              {
                *(_DWORD *)&v99[6] = 0;
                if ( *(_WORD *)&v99[10] == 0xFFFF )
                {
                  *(_WORD *)&v99[10] = 0x8000;
                  ++v41;
                }
                else
                {
                  ++*(_WORD *)&v99[10];
                }
              }
              else
              {
                ++*(_DWORD *)&v99[6];
              }
            }
            else
            {
              ++*(_DWORD *)&v99[2];
            }
          }
          if ( (unsigned __int16)v41 < 0x7FFFu )
          {
            *(_WORD *)ld12.ld12 = *(_WORD *)&v99[2];
            *(_QWORD *)&ld12.ld12[2] = *(_QWORD *)&v99[4];
            *(_WORD *)&ld12.ld12[10] = v35 | v41;
          }
          else
          {
            *(_DWORD *)&ld12.ld12[4] = 0;
            *(_DWORD *)ld12.ld12 = 0;
            *(_DWORD *)&ld12.ld12[8] = v35 != 0 ? -32768 : 2147450880;
          }
          goto LABEL_132;
        }
      }
      *(_DWORD *)&ld12.ld12[8] = 0;
    }
    *(_DWORD *)&ld12.ld12[4] = 0;
    *(_DWORD *)ld12.ld12 = 0;
  }
LABEL_132:
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    ndigits += digcount;
    if ( ndigits <= 0 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != (__int16)0x8000 ? 32 : 45;
      fos->man[0] = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( ndigits > 21 )
    ndigits = 21;
  v49 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  for ( k = 8; k != 0; --k )
  {
    v51 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v52 = (v51 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v53 = *(__int64 *)&ld12.ld12[4] >> 31;
    *(_DWORD *)&ld12.ld12[4] = v52;
    *(_DWORD *)&ld12.ld12[8] = v53;
  }
  if ( v49 < 0 )
  {
    v54 = (unsigned __int8)-(char)v49;
    if ( v54 != 0 )
    {
      do
      {
        v55 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v56 = (v55 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v57 = *(__int64 *)ld12.ld12 >> 1;
        --v54;
        *(_DWORD *)&ld12.ld12[4] = v56;
        *(_DWORD *)ld12.ld12 = v57;
      }
      while ( v54 > 0 );
    }
  }
  man = fos->man;
  v95 = fos->man;
  for ( digcounta = ndigits + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v59 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v60 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v61 = (v59 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v62 = 2 * v61;
    v63 = (v61 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v64 = (v60 >> 31) | v62;
    v65 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v65 < *(_DWORD *)tmp12.ld12 )
    {
      v66 = 0;
      if ( v64 + 1 < v64 || v64 == -1 )
        v66 = 1;
      ++v64;
      if ( v66 != 0 )
        ++v63;
    }
    v67 = *(_DWORD *)&tmp12.ld12[4] + v64;
    v92 = *(_DWORD *)&tmp12.ld12[4] + v64;
    if ( *(_DWORD *)&tmp12.ld12[4] + v64 < v64 || v67 < *(_DWORD *)&tmp12.ld12[4] )
      ++v63;
    *(_DWORD *)ld12.ld12 = 2 * v65;
    *(_DWORD *)&ld12.ld12[8] = (v67 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v63));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v65 >> 31) | (2 * v92);
  }
  v68 = man - 1;
  v69 = *v68;
  v70 = v68 - 1;
  if ( v69 >= 53 )
  {
    while ( v70 >= v95 && *v70 == 57 )
      *v70-- = 48;
    v71 = fos;
    if ( v70 < v95 )
    {
      ++v70;
      ++fos->exp;
    }
    ++*v70;
  }
  else
  {
    while ( v70 >= v95 && *v70 == 48 )
      --v70;
    v71 = fos;
    if ( v70 < v95 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != (__int16)0x8000 ? 32 : 45;
      *v95 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v72 = (_BYTE)v70 - (_BYTE)v71 - 3;
  v71->ManLen = v72;
  v71->man[v72] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412B39
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412BC7
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412C67
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v5; // ax
  __int16 v6; // bx
  unsigned int v7; // edx
  int v8; // eax
  __int16 v9; // ax
  int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  __int16 v16; // ax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  __int16 v22; // [esp+14h] [ebp-Ch]
  unsigned int v23; // [esp+1Ch] [ebp-4h]
  unsigned int maska; // [esp+28h] [ebp+8h]

  v2 = 0;
  if ( (v22 & 1) != 0 )
    v2 = 16;
  if ( (v22 & 4) != 0 )
    v2 |= 8u;
  if ( (v22 & 8) != 0 )
    v2 |= 4u;
  if ( (v22 & 0x10) != 0 )
    v2 |= 2u;
  if ( (v22 & 0x20) != 0 )
    v2 |= 1u;
  if ( (v22 & 2) != 0 )
    v2 |= 0x80000u;
  v3 = v22 & 0xC00;
  if ( v3 != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (v22 & 0x300) != 0 )
  {
    if ( (v22 & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (v22 & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  v23 = result;
  if ( result != v2 )
  {
    v5 = hw_cw(abstr: mask & newctrl | v2 & ~mask);
    v6 = v5;
    v7 = 0;
    if ( (v5 & 1) != 0 )
      v7 = 16;
    if ( (v5 & 4) != 0 )
      v7 |= 8u;
    if ( (v5 & 8) != 0 )
      v7 |= 4u;
    if ( (v5 & 0x10) != 0 )
      v7 |= 2u;
    if ( (v5 & 0x20) != 0 )
      v7 |= 1u;
    if ( (v5 & 2) != 0 )
      v7 |= 0x80000u;
    v8 = v5 & 0xC00;
    if ( (v6 & 0xC00) != 0 )
    {
      switch ( v8 )
      {
        case 1024:
          v7 |= 0x100u;
          break;
        case 2048:
          v7 |= 0x200u;
          break;
        case 3072:
          v7 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v6 & 0x300) != 0 )
    {
      if ( (v6 & 0x300) == 0x200 )
        v7 |= 0x10000u;
    }
    else
    {
      v7 |= 0x20000u;
    }
    if ( (v6 & 0x1000) != 0 )
      v7 |= 0x40000u;
    result = v7;
    v23 = v7;
  }
  if ( __sse2_available != 0 )
  {
    v9 = _mm_getcsr();
    v10 = 0;
    if ( (v9 & 0x80u) != 0 )
      v10 = 16;
    if ( (v9 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v9 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v9 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v9 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v9 & 0x100) != 0 )
      v10 |= 0x80000u;
    v11 = v9 & 0x6000;
    if ( (v9 & 0x6000) != 0 )
    {
      switch ( v11 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v12 = (v9 & 0x8040) - 64;
    if ( v12 != 0 )
    {
      v13 = v12 - 32704;
      if ( v13 != 0 )
      {
        if ( v13 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v14 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v14 == v10 )
    {
      v15 = v10;
    }
    else
    {
      maska = _hw_cw_sse2(a1: v11, abstr: v14);
      __set_fpsr_sse2(newMXCSR: maska);
      v16 = _mm_getcsr();
      v17 = 0;
      if ( (v16 & 0x80u) != 0 )
        v17 = 16;
      if ( (v16 & 0x200) != 0 )
        v17 |= 8u;
      if ( (v16 & 0x400) != 0 )
        v17 |= 4u;
      if ( (v16 & 0x800) != 0 )
        v17 |= 2u;
      if ( (v16 & 0x1000) != 0 )
        v17 |= 1u;
      if ( (v16 & 0x100) != 0 )
        v17 |= 0x80000u;
      v18 = v16 & 0x6000;
      if ( (v16 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v17 |= 0x100u;
            break;
          case 16384:
            v17 |= 0x200u;
            break;
          case 24576:
            v17 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v16 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v17 |= 0x1000000u;
        }
        else
        {
          v17 |= 0x3000000u;
        }
      }
      else
      {
        v17 |= 0x2000000u;
      }
      v15 = v17;
    }
    v21 = v23 ^ v15;
    result = v23 | v15;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412F6A
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _strnicmp_l(
        const char *a1@<edi>,
        unsigned int a2@<esi>,
        char *dst,
        char *src,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (a1 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v6 = _tolower_l(c: (unsigned __int8)*dst++, plocinfo: &_loc_update.localeinfo);
            v7 = v6;
            v8 = _tolower_l(c: *(unsigned __int8 *)a1++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v7 != 0 && v7 == v8 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter(a1: 0, a2: (unsigned int)src, a3: 0x7FFFFFFFu);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: (unsigned int)a1, a3: a2);
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041305A
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _strnicmp(unsigned int a1@<ebx>, const char *a2@<edi>, char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(a1: a2, a2: 0, dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, (unsigned int)a2, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004130B6
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  UINT ConsoleOutputCP; // eax
  DWORD v3; // eax
  int num_written; // [esp+4h] [ebp-10h] BYREF
  char mbc[8]; // [esp+8h] [ebp-Ch] BYREF

  if ( use_w == 0 )
    goto LABEL_10;
  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1 )
    return -1;
  if ( !WriteConsoleW(
          hConsoleOutput: _confh,
          lpBuffer: &ch,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: (LPDWORD)&num_written,
          lpReserved: nullptr) )
  {
    if ( use_w != 2 || GetLastError() != 120 )
      return -1;
    use_w = 0;
LABEL_10:
    ConsoleOutputCP = GetConsoleOutputCP();
    v3 = WideCharToMultiByte(
           CodePage: ConsoleOutputCP,
           dwFlags: 0,
           lpWideCharStr: &ch,
           cchWideChar: 1,
           lpMultiByteStr: mbc,
           cbMultiByte: 5,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    if ( _confh != (HANDLE)-1
      && WriteConsoleA(
           hConsoleOutput: _confh,
           lpBuffer: mbc,
           nNumberOfCharsToWrite: v3,
           lpNumberOfCharsWritten: (LPDWORD)&num_written,
           lpReserved: nullptr) )
    {
      return ch;
    }
    return -1;
  }
  use_w = 1;
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x00413178
// Name: wcsncnt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall wcsncnt@<eax>(const wchar_t *string@<eax>, int cnt)
{
  int v2; // ecx

  v2 = cnt;
  while ( v2 != 0 )
  {
    --v2;
    if ( *string == 0 )
      return cnt - v2 - 1;
    ++string;
  }
  v2 = -1;
  return cnt - v2 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413194
// Name: __crtCompareStringW_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtCompareStringW_stat(
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2,
        UINT code_page)
{
  localeinfo_struct *plocinfo; // ecx
  localeinfo_struct *v8; // ebx
  unsigned int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  void *v14; // esp
  unsigned __int8 *v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  void *v19; // esp
  CHAR *v20; // eax
  CHAR *v21; // ebx
  _DWORD v22[3]; // [esp+0h] [ebp-20h] BYREF
  int buff_size1; // [esp+Ch] [ebp-14h]
  int retcode; // [esp+10h] [ebp-10h]
  int buff_size2; // [esp+14h] [ebp-Ch]
  unsigned __int8 *buffer1; // [esp+18h] [ebp-8h]

  v8 = plocinfo;
  if ( f_use_5 == 0 )
  {
    if ( CompareStringW(Locale: 0, dwCmpFlags: 0, lpString1: &String2, cchCount1: 1, lpString2: &String2, cchCount2: 1) != 0 )
    {
      f_use_5 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_5 = 2;
    }
  }
  if ( cchCount1 > 0 )
    cchCount1 = wcsncnt(string: lpString1, cnt: cchCount1);
  if ( cchCount2 > 0 )
    cchCount2 = wcsncnt(string: lpString2, cnt: cchCount2);
  if ( cchCount1 != 0 && cchCount2 != 0 )
  {
    if ( f_use_5 == 1 )
      return CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2);
    if ( f_use_5 != 2 && f_use_5 != 0 )
      return 0;
    retcode = 0;
    if ( Locale == 0 )
      Locale = v8->locinfo->lc_handle[2];
    if ( code_page == 0 )
      code_page = v8->locinfo->lc_codepage;
    v10 = __ansicp(lcid: Locale);
    if ( code_page != v10 && v10 != -1 )
      code_page = v10;
    v11 = WideCharToMultiByte(
            CodePage: code_page,
            dwFlags: 0,
            lpWideCharStr: lpString1,
            cchWideChar: cchCount1,
            lpMultiByteStr: nullptr,
            cbMultiByte: 0,
            lpDefaultChar: nullptr,
            lpUsedDefaultChar: nullptr);
    v12 = v11;
    buff_size1 = v11;
    if ( v11 == 0 )
      return 0;
    if ( v11 <= 0 || 0xFFFFFFE0 / v11 == 0 )
    {
      buffer1 = nullptr;
LABEL_35:
      if ( buffer1 == nullptr )
        return 0;
      if ( WideCharToMultiByte(
             CodePage: code_page,
             dwFlags: 0,
             lpWideCharStr: lpString1,
             cchWideChar: cchCount1,
             lpMultiByteStr: (LPSTR)buffer1,
             cbMultiByte: v12,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: nullptr) == 0 )
        goto error_cleanup_1;
      v16 = WideCharToMultiByte(
              CodePage: code_page,
              dwFlags: 0,
              lpWideCharStr: lpString2,
              cchWideChar: cchCount2,
              lpMultiByteStr: nullptr,
              cbMultiByte: 0,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
      v17 = v16;
      buff_size2 = v16;
      if ( v16 == 0 )
        goto error_cleanup_1;
      if ( v16 <= 0 || 0xFFFFFFE0 / v16 == 0 )
      {
        v21 = nullptr;
LABEL_48:
        if ( v21 != nullptr )
        {
          if ( WideCharToMultiByte(
                 CodePage: code_page,
                 dwFlags: 0,
                 lpWideCharStr: lpString2,
                 cchWideChar: cchCount2,
                 lpMultiByteStr: v21,
                 cbMultiByte: buff_size2,
                 lpDefaultChar: nullptr,
                 lpUsedDefaultChar: nullptr) != 0 )
            retcode = CompareStringA(
                        Locale,
                        dwCmpFlags,
                        lpString1: (PCNZCH)buffer1,
                        cchCount1: buff_size1,
                        lpString2: v21,
                        cchCount2: buff_size2);
          _freea(_Memory: v21);
        }
error_cleanup_1:
        _freea(_Memory: buffer1);
        return retcode;
      }
      v18 = v16 + 8;
      if ( (unsigned int)(v17 + 8) > 0x400 )
      {
        v20 = (CHAR *)_malloc_crt(size: v17 + 8);
        if ( v20 != nullptr )
        {
          *(_DWORD *)v20 = 56797;
          goto LABEL_45;
        }
      }
      else
      {
        v19 = alloca(v18);
        v20 = (CHAR *)v22;
        if ( v22 != nullptr )
        {
          v22[0] = 52428;
LABEL_45:
          v20 += 8;
        }
      }
      v21 = v20;
      goto LABEL_48;
    }
    v13 = v11 + 8;
    if ( (unsigned int)(v12 + 8) > 0x400 )
    {
      v15 = (unsigned __int8 *)_malloc_crt(size: v12 + 8);
      if ( v15 != nullptr )
      {
        *(_DWORD *)v15 = 56797;
        goto LABEL_32;
      }
    }
    else
    {
      v14 = alloca(v13);
      v15 = (unsigned __int8 *)v22;
      if ( v22 != nullptr )
      {
        v22[0] = 52428;
LABEL_32:
        v15 += 8;
      }
    }
    buffer1 = v15;
    goto LABEL_35;
  }
  if ( cchCount1 == cchCount2 )
    return 2;
  else
    return 2 * (cchCount1 - cchCount2 >= 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004133E4
// Name: ___crtCompareStringW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringW(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringW_stat(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2, code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413424
// Name: __mbsnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsnicmp_l(
        const char *a1@<edi>,
        unsigned int a2@<esi>,
        char *s1,
        char *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  char *v6; // edi
  unsigned __int8 v7; // cl
  char v8; // cl
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // si
  bool v11; // cf
  const unsigned __int8 *v12; // ecx
  unsigned __int8 v13; // cl
  char *v14; // ecx
  int v15; // ecx
  unsigned __int16 v16; // dx
  unsigned __int16 v17; // cx
  char *v18; // ecx
  int v19; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-14h] BYREF
  int c1; // [esp+14h] [ebp-4h]

  if ( n == 0 )
    return;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    _strnicmp(a1: 0, a2: a1, dst: s1, src: s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v6 = s1;
  if ( s1 == nullptr || s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)s1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  while ( 1 )
  {
    v7 = *v6;
    --n;
    c1 = (unsigned __int8)*v6++;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v7 + 1] & 4) == 0 )
    {
      v14 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v14[29] & 0x10) != 0 )
        v15 = (unsigned __int8)v14[285];
      else
        v15 = (unsigned __int16)c1;
      c1 = v15;
      goto LABEL_25;
    }
    v8 = *v6;
    if ( *v6 == 0 )
    {
      c1 = 0;
LABEL_25:
      v10 = c1;
      goto LABEL_16;
    }
    HIBYTE(v9) = c1;
    ++v6;
    LOBYTE(v9) = v8;
    v10 = v9;
    v11 = v9 < _loc_update.localeinfo.mbcinfo->mbulinfo[0];
    c1 = v9;
    if ( v11 || v9 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( v9 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3] && v9 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
        v10 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v9;
    }
    else
    {
      v10 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v9;
    }
LABEL_16:
    c1 = (unsigned __int8)*s2;
    v12 = (const unsigned __int8 *)++s2;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)c1 + 1] & 4) == 0 )
    {
      v18 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v18[29] & 0x10) != 0 )
        v19 = (unsigned __int8)v18[285];
      else
        v19 = (unsigned __int16)c1;
      c1 = v19;
      goto LABEL_42;
    }
    v13 = *v12;
    if ( v13 == 0 )
    {
      c1 = 0;
LABEL_42:
      v17 = c1;
      goto LABEL_30;
    }
    HIBYTE(v16) = c1;
    ++s2;
    LOBYTE(v16) = v13;
    v17 = v16;
    v11 = v16 < _loc_update.localeinfo.mbcinfo->mbulinfo[0];
    c1 = v16;
    if ( v11 || v16 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( v16 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3] && v16 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
        v17 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v16;
    }
    else
    {
      v17 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v16;
    }
LABEL_30:
    if ( v17 != v10 )
      break;
    if ( v10 == 0 || n == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x004135ED
// Name: __mbsnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsnicmp(const char *a1@<edi>, unsigned int a2@<esi>, char *s1, char *s2, unsigned int n)
{
  _mbsnicmp_l(a1, a2, s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00413604
// Name: ___ascii_stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ascii_stricmp(const char *dst, const char *src)
{
  int v4; // eax
  int v5; // ecx

  do
  {
    v4 = *(unsigned __int8 *)dst++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *(unsigned __int8 *)src++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( v4 != 0 && v4 == v5 );
  return v4 - v5;
}

//------------------------------------------------------------------------------
// Address: 0x00413639
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _stricmp_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const char *dst,
        const char *src,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  const char *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( dst != nullptr )
  {
    v6 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v7 = _tolower_l(c: *(unsigned __int8 *)dst++, plocinfo: &_loc_update.localeinfo);
          v8 = v7;
          v9 = _tolower_l(c: *(unsigned __int8 *)v6++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v8 != 0 && v8 == v9 );
        result = v8 - v9;
      }
      else
      {
        result = __ascii_stricmp(dst, src);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: 0, a3: a2);
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041370C
// Name: __stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _stricmp@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, const char *dst, const char *src)
{
  if ( __locale_changed != 0 )
    return _stricmp_l(a1: a2, a2: 0, dst, src, plocinfo: nullptr);
  if ( dst != nullptr && src != nullptr )
    return __ascii_stricmp(dst, src);
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x0041375C
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __set_fpsr_sse2(unsigned int newMXCSR)
{
  if ( __sse2_available != 0 )
  {
    if ( (newMXCSR & 0x40) != 0 && _DAZ_ENABLED != 0 )
      _mm_setcsr(newMXCSR);
    else
      _mm_setcsr(newMXCSR & 0xFFFFFFBF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004137D0
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i != 0; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( *first == 0 || v7 == 0 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413831
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileA(
             lpFileName: "CONOUT$",
             dwDesiredAccess: 0x40000000u,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _confh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413850
// Name: ___termcon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termcon()
{
  HANDLE result; // eax

  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    CloseHandle(hObject: _confh);
  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041387E
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x00413890
// Name: _dynamic_initializer_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_ApplicationObject__()
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(
    this: &_s_ApplicationObject,
    pFileSystem: nullptr,
    pAppSystemParent: nullptr);
  _s_ApplicationObject.__vftable = (CMdlBuildApp_vtbl *)&CMdlBuildApp::`vftable';
  return atexit(func: dynamic_atexit_destructor_for____s_ApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x004138C0
// Name: _dynamic_initializer_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_SteamApplicationObject__()
{
  CSteamApplication::CSteamApplication(this: &_s_SteamApplicationObject, pAppSystemGroup: &_s_ApplicationObject);
  return atexit(func: dynamic_atexit_destructor_for____s_SteamApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x004138E0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413940
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413970
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: (CUtlVector<char,CUtlMemory<char,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: (CUtlVector<char,CUtlMemory<char,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x004139A0
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: (CUtlVector<char,CUtlMemory<char,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: (CUtlVector<char,CUtlMemory<char,int> > *)&_s_ApplicationObject.m_Modules);
}

} // namespace mdlbuild
