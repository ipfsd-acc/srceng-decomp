// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_surfacelib/fonteffects.cpp
// Functions: 411
// ============================================================

#include "vgui2\vgui_surfacelib\fonteffects.h"

//------------------------------------------------------------------------------
// Address: 0x10022C30
// Name: void ApplyRotaryEffectToTexture(int,int,unsigned char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyRotaryEffectToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, bool bRotary)
{
  int v4; // ecx
  unsigned __int8 *v5; // eax

  if ( bRotary )
  {
    v4 = rgbaWide;
    v5 = &rgba[-4 * rgbaWide * (int)((double)rgbaTall * -0.5)];
    if ( rgbaWide > 0 )
    {
      do
      {
        *v5 = 127;
        v5[1] = 127;
        v5[2] = 127;
        v5[3] = -1;
        v5 += 4;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022C80
// Name: void ApplyScanlineEffectToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyScanlineEffectToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iScanLines)
{
  int i; // esi
  unsigned __int8 *v6; // eax
  int j; // ecx

  if ( iScanLines >= 2 )
  {
    for ( i = 0; i < rgbaTall; rgba += 4 * rgbaWide )
    {
      if ( i % iScanLines != 0 )
      {
        v6 = rgba;
        if ( rgbaWide > 0 )
        {
          for ( j = rgbaWide; j != 0; --j )
          {
            *v6 = (int)(float)((float)*v6 * 0.69999999);
            v6[1] = (int)(float)((float)v6[1] * 0.69999999);
            v6[2] = (int)(float)((float)v6[2] * 0.69999999);
            v6 += 4;
          }
        }
      }
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022D20
// Name: void ApplyDropShadowToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyDropShadowToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iDropShadowOffset)
{
  int v5; // ecx
  int v6; // ecx
  int v7; // esi
  int v8; // ecx
  unsigned __int8 *v9; // eax
  int v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]
  int iDropShadowOffseta; // [esp+24h] [ebp+14h]

  if ( iDropShadowOffset != 0 )
  {
    v5 = rgbaTall - 1;
    if ( rgbaTall - 1 >= iDropShadowOffset )
    {
      v10 = rgbaWide - 1;
      iDropShadowOffseta = rgbaWide * v5;
      v6 = v5 - iDropShadowOffset;
      v7 = rgbaWide * v6 - iDropShadowOffset;
      v11 = v6 + 1;
      do
      {
        v8 = rgbaWide - 1;
        if ( v10 >= iDropShadowOffset )
        {
          v9 = &rgba[4 * v10 + 3 + 4 * iDropShadowOffseta];
          do
          {
            if ( *v9 == 0 )
            {
              *(v9 - 1) = 0;
              *(_WORD *)(v9 - 3) = 0;
              *v9 = rgba[4 * v7 + 3 + 4 * v8];
            }
            --v8;
            v9 -= 4;
          }
          while ( v8 >= iDropShadowOffset );
        }
        iDropShadowOffseta -= rgbaWide;
        v7 -= rgbaWide;
        --v11;
      }
      while ( v11 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022DB0
// Name: void ApplyOutlineToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyOutlineToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iOutlineSize)
{
  int v4; // esi
  int v5; // ecx
  unsigned __int8 *v6; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // esi
  int v10; // ecx
  int v11; // eax
  unsigned __int8 *v12; // eax
  int v13; // [esp+4h] [ebp-18h]
  int y; // [esp+8h] [ebp-14h]
  unsigned __int8 *v15; // [esp+Ch] [ebp-10h]
  int x; // [esp+10h] [ebp-Ch]
  int shadowX; // [esp+14h] [ebp-8h]
  unsigned __int8 *v18; // [esp+18h] [ebp-4h]

  v4 = iOutlineSize;
  if ( iOutlineSize != 0 )
  {
    v5 = 0;
    y = 0;
    if ( rgbaTall > 0 )
    {
      v15 = rgba + 3;
      do
      {
        x = 0;
        if ( rgbaWide > 0 )
        {
          v6 = v15;
          v18 = v15;
          do
          {
            if ( *v6 == 0 )
            {
              v7 = -v4;
              v8 = -v4;
              v13 = -v4;
              shadowX = -v4;
              if ( -v4 <= v4 )
              {
                do
                {
                  if ( v7 <= iOutlineSize )
                  {
                    v9 = v7 + v5;
                    v10 = rgbaWide * (v7 + v5);
                    do
                    {
                      if ( v8 != 0 || v7 != 0 )
                      {
                        v11 = v8 + x;
                        if ( v8 + x >= 0
                          && v11 < rgbaWide
                          && v9 >= 0
                          && v9 < rgbaTall
                          && *(v12 = &rgba[4 * v10 + 4 * v11]) != 0
                          && v12[1] != 0
                          && v12[2] != 0
                          && v12[3] != 0 )
                        {
                          v6 = v18;
                          *(v18 - 3) = 0;
                          *(v18 - 2) = 0;
                          *(v18 - 1) = 0;
                          *v18 = -1;
                        }
                        else
                        {
                          v6 = v18;
                        }
                      }
                      v8 = shadowX;
                      ++v7;
                      ++v9;
                      v10 += rgbaWide;
                    }
                    while ( v7 <= iOutlineSize );
                    v7 = v13;
                    v5 = y;
                  }
                  v4 = iOutlineSize;
                  shadowX = ++v8;
                }
                while ( v8 <= iOutlineSize );
              }
            }
            v6 += 4;
            ++x;
            v18 = v6;
          }
          while ( x < rgbaWide );
        }
        ++v5;
        v15 += 4 * rgbaWide;
        y = v5;
      }
      while ( v5 < rgbaTall );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022EC0
// Name: void ApplyGaussianBlurToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyGaussianBlurToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iBlur)
{
  void *v4; // esp
  float *v5; // edi
  double v6; // xmm0_8
  int v7; // esi
  int v8; // ebx
  float v9; // xmm0_4
  void *v10; // esp
  long double *v11; // esi
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  float v15; // xmm1_4
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  float v19; // xmm0_4
  int v20; // edx
  float *v21; // esi
  unsigned int v22; // ecx
  int v23; // ebx
  float v24; // xmm3_4
  float v25; // xmm4_4
  int v26; // ebx
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm4_4
  int v30; // ebx
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm4_4
  int v34; // ebx
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  int v38; // ecx
  int v39; // edx
  unsigned __int8 *v40; // eax
  float *v41; // edx
  int v42; // ecx
  float v43; // xmm3_4
  float v44; // xmm4_4
  unsigned __int8 *v45; // ecx
  int v46; // eax
  long double v47; // [esp+0h] [ebp-50h] BYREF
  _BYTE v48[12]; // [esp+8h] [ebp-48h]
  float v49; // [esp+14h] [ebp-3Ch]
  unsigned __int8 *v50; // [esp+18h] [ebp-38h]
  int v51; // [esp+1Ch] [ebp-34h]
  unsigned __int8 *v52; // [esp+20h] [ebp-30h]
  int v53; // [esp+24h] [ebp-2Ch]
  int i; // [esp+28h] [ebp-28h]
  long double *v55; // [esp+2Ch] [ebp-24h]
  long double *v56; // [esp+30h] [ebp-20h]
  int v57; // [esp+34h] [ebp-1Ch]
  unsigned __int8 *v58; // [esp+38h] [ebp-18h]
  unsigned __int8 *v59; // [esp+3Ch] [ebp-14h]
  unsigned __int8 *v60; // [esp+40h] [ebp-10h]
  unsigned __int8 *v61; // [esp+44h] [ebp-Ch]
  float *v62; // [esp+48h] [ebp-8h]
  int v63; // [esp+4Ch] [ebp-4h]

  if ( iBlur != 0 )
  {
    v4 = alloca(8 * iBlur + 4);
    v5 = (float *)&v47;
    v6 = (double)iBlur * 0.6830000000000001;
    v56 = &v47;
    if ( (iBlur & 0x40000000) == 0 )
    {
      *(double *)&v48[4] = v6 * 2.0 * v6;
      v7 = -iBlur;
      v8 = 2 * iBlur + 1;
      v49 = 1.0 / sqrt(v6 * 6.28 * v6);
      do
      {
        __libm_sse2_pow(x: v47, y: *(long double *)v48);
        v9 = 2.7 * v49;
        *v5 = v9;
        ++v7;
        ++v5;
        --v8;
      }
      while ( v8 != 0 );
    }
    v10 = alloca(4 * rgbaTall * rgbaWide);
    v11 = &v47;
    v55 = &v47;
    memcpy(dst: (unsigned __int8 *)&v47, src: rgba, count: 4 * rgbaTall * rgbaWide);
    v50 = rgba;
    v63 = 0;
    if ( rgbaTall > 0 )
    {
      v53 = -iBlur;
      do
      {
        v12 = 0;
        v49 = 0.0;
        if ( rgbaWide > 0 )
        {
          v13 = -iBlur;
          for ( i = -iBlur; ; v13 = i )
          {
            v14 = rgbaWide - 1;
            v15 = 0.0;
            if ( v12 + iBlur >= rgbaWide - 1 )
            {
              v51 = rgbaWide - 1;
            }
            else
            {
              v14 = v12 + iBlur;
              v51 = v12 + iBlur;
            }
            v16 = v13 <= 0 ? 0 : v13;
            v52 = (unsigned __int8 *)v16;
            if ( v16 <= v14 )
            {
              *(_DWORD *)&v48[8] = iBlur + v63;
              v62 = (float *)v56 + iBlur + v16 - v12;
              do
              {
                v17 = rgbaTall - 1;
                if ( *(int *)&v48[8] >= rgbaTall - 1 )
                {
                  v57 = rgbaTall - 1;
                }
                else
                {
                  v17 = *(_DWORD *)&v48[8];
                  v57 = *(_DWORD *)&v48[8];
                }
                v18 = v53 <= 0 ? 0 : v53;
                if ( v18 <= v17 )
                {
                  if ( v17 - v18 + 1 >= 4 )
                  {
                    v19 = *v62;
                    v61 = (unsigned __int8 *)v11 + 4 * v16 + 4 * rgbaWide * v18;
                    v58 = (unsigned __int8 *)v11 + 4 * v16 + 4 * rgbaWide * (v18 + 3);
                    v59 = (unsigned __int8 *)v11 + 4 * v16 + 4 * rgbaWide * (v18 + 2);
                    v20 = 16 * rgbaWide;
                    v21 = (float *)v56 + iBlur + v18 - v63 + 2;
                    v60 = (unsigned __int8 *)v55 + 4 * v16 + 4 * rgbaWide * (v18 + 1);
                    v22 = ((unsigned int)(v57 - v18 - 3) >> 2) + 1;
                    v18 += 4 * v22;
                    do
                    {
                      v23 = *v61;
                      v24 = *(v21 - 2);
                      v61 += v20;
                      v25 = (float)v23;
                      v26 = *v60;
                      v60 += v20;
                      v27 = (float)((float)(v24 * v19) * v25) + v15;
                      v28 = *(v21 - 1);
                      v29 = (float)v26;
                      v30 = *v59;
                      v59 += v20;
                      v31 = v27 + (float)((float)(v28 * v19) * v29);
                      v32 = *v21;
                      v33 = (float)v30;
                      v34 = *v58;
                      v58 += v20;
                      v35 = v31 + (float)((float)(v32 * v19) * v33);
                      v36 = v21[1];
                      v21 += 4;
                      --v22;
                      v15 = (float)((float)(v36 * v19) * (float)v34) + v35;
                    }
                    while ( v22 != 0 );
                    v11 = v55;
                    v16 = (int)v52;
                    v17 = v57;
                  }
                  if ( v18 <= v17 )
                  {
                    v37 = *v62;
                    v52 = (unsigned __int8 *)v11 + 4 * v16 + 4 * rgbaWide * v18;
                    v38 = v17 - v18;
                    v39 = iBlur + v18 - v63;
                    v40 = v52;
                    v41 = (float *)v56 + v39;
                    v42 = v38 + 1;
                    do
                    {
                      v43 = *v41;
                      v44 = (float)*v40;
                      ++v41;
                      v40 += 4 * rgbaWide;
                      --v42;
                      v15 = v15 + (float)((float)(v43 * v37) * v44);
                    }
                    while ( v42 != 0 );
                    v11 = v55;
                  }
                }
                ++v62;
                v52 = (unsigned __int8 *)++v16;
              }
              while ( v16 <= v51 );
              v12 = LODWORD(v49);
            }
            v45 = v50;
            v46 = (int)v15;
            *(_WORD *)(v50 + 1) = -1;
            *v45 = -1;
            if ( (int)v15 >= 255 )
              LOBYTE(v46) = -1;
            ++i;
            ++v12;
            v45[3] = v46;
            v50 = v45 + 4;
            v49 = *(float *)&v12;
            if ( v12 >= rgbaWide )
              break;
          }
        }
        ++v53;
        ++v63;
      }
      while ( v63 < rgbaTall );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023307
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: (unsigned __int8 *)string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023375
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _input_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x100233B0
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
// Address: 0x10023470
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
// Address: 0x1002349B
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax
  wchar_t drvstr[4]; // [esp+0h] [ebp-Ch] BYREF

  result = true;
  if ( drive != 0 )
  {
    drvstr[0] = drive + 64;
    wcscpy(&drvstr[1], L":\\");
    if ( GetDriveTypeW(lpRootPathName: drvstr) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100234F5
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  int v3; // ebx
  char *v5; // edi
  signed int FullPathNameA; // eax
  unsigned __int8 *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  int count; // [esp+8h] [ebp-4h]

  v3 = drive;
  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  else
  {
    v3 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v3 != 0 )
  {
    LOBYTE(drive) = v3 + 64;
    strcpy((char *)&drive + 1, ":.");
  }
  else
  {
    strcpy((char *)&drive, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: count, lpBuffer: v5, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_24;
  if ( v5 == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = calloc(count: maxlen, size: 1u);
    v5 = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: maxlen, lpBuffer: (LPSTR)v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_24:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *v5 = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10023619
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
// Address: 0x10023662
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
// Address: 0x100236E9
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
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023770
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
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
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
  else if ( count >= 0x80
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
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 100237C9 case 0 }
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
// Address: 0x10023AE0
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
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
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
  else if ( count >= 0x80
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
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 10023B39 case 0 }
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
// Address: 0x10023E41
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
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
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023EAE
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
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023F30
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _alloca_probe_16@<eax>(int a1@<eax>, int a2@<ecx>)
{
  char v2; // sp
  int v3; // ecx

  v3 = (v2 + 8 - (_BYTE)a1) & 0xF;
  return _chkstk(a1: __CFADD__(v3, a1) ? -1 : v3 + a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10023F60
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
    if ( (_BYTE)value != 0 || count < 0x80 || __sse2_available == 0 )
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
// Address: 0x100240FD
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024114
// Name: __snwprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snwprintf(unsigned __int16 *string, unsigned int count, const wchar_t *format, ...)
{
  int result; // eax
  int v4; // edi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+3Ch] [ebp+14h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._flag = 66;
    str._base = (char *)string;
    str._ptr = (char *)string;
    if ( count <= 0x3FFFFFFF )
      str._cnt = 2 * count;
    else
      str._cnt = 0x7FFFFFFF;
    result = _woutput_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr++ = 0;
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v4;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100241E4
// Name: _wcsncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsncpy(unsigned __int16 *dest, const wchar_t *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned __int16 *v4; // edi
  unsigned __int16 v5; // ax
  unsigned int v6; // ecx
  char v7; // cf
  unsigned int v8; // ecx
  unsigned __int16 *v9; // edi
  int i; // ecx

  v3 = count;
  v4 = dest;
  if ( count != 0 )
  {
    do
    {
      v5 = *(unsigned __int16 *)((char *)v4 + (char *)source - (char *)dest);
      *v4++ = v5;
      if ( v5 == 0 )
        break;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v6 = v3 - 1;
      if ( v6 != 0 )
      {
        v7 = v6 & 1;
        v8 = v6 >> 1;
        memset(v4, 0, 4 * v8);
        v9 = &v4[2 * v8];
        for ( i = v7; i != 0; --i )
          *v9++ = 0;
      }
    }
  }
  return dest;
}

//------------------------------------------------------------------------------
// Address: 0x10024230
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
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
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100242DC
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x100242F9
// Name: __snprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snprintf(char *string, unsigned int count, const char *format, ...)
{
  int result; // eax
  int v4; // edi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+3Ch] [ebp+14h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v4;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100243B0
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
      goto main_loop_entrance;
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
tail_loop_start:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance:
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
      goto tail_loop_start;
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
// Address: 0x100244D4
// Name: FindCompleteObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__thiscall FindCompleteObject(void **inptr)
{
  int v1; // edx
  _BYTE *result; // eax
  int v3; // edx

  v1 = *((_DWORD *)*inptr - 1);
  result = (char *)inptr - *(_DWORD *)(v1 + 4);
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    result -= *(unsigned int *)((char *)inptr - v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100244EA
// Name: PMDtoOffset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall PMDtoOffset@<eax>(const PMD *pmd@<eax>, char *pThis)
{
  int pdisp; // edx
  int v3; // ecx

  pdisp = pmd->pdisp;
  v3 = 0;
  if ( pdisp >= 0 )
    v3 = *(_DWORD *)(*(_DWORD *)&pThis[pdisp] + pmd->vdisp) + pmd->pdisp;
  return v3 + pmd->mdisp;
}

//------------------------------------------------------------------------------
// Address: 0x1002450E
// Name: FindMITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindMITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  const _s_RTTIBaseClassDescriptor *pSourceBCD; // [esp+Ch] [ebp-14h]
  const _s_RTTIBaseClassDescriptor *pTargetBCD; // [esp+10h] [ebp-10h]
  unsigned int nTargetBases; // [esp+14h] [ebp-Ch]
  unsigned int iTarget; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  pTargetBCD = nullptr;
  pSourceBCD = nullptr;
  nTargetBases = 0;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  while ( 1 )
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( pSourceBCD != nullptr )
        {
          if ( (v8->attributes & 3) == 0 && (pSourceBCD->attributes & 1) == 0 )
            return v8;
          return nullptr;
        }
        iTarget = i;
        pTargetBCD = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
        break;
    }
LABEL_12:
    if ( ++i >= numBaseClasses )
      return nullptr;
  }
  if ( pTargetBCD == nullptr )
  {
    pSourceBCD = v8;
    goto LABEL_12;
  }
  if ( i - iTarget > nTargetBases )
  {
    if ( (pTargetBCD->attributes & 3) == 0 )
      goto LABEL_20;
    return nullptr;
  }
  if ( (pTargetBCD->attributes & 0x40) == 0 )
  {
    if ( iTarget == 0 )
    {
LABEL_20:
      if ( (v8->attributes & 1) != 0 )
        return nullptr;
    }
    return pTargetBCD;
  }
  return (pTargetBCD->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) == 0
       ? pTargetBCD
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10024616
// Name: FindVITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindVITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassDescriptor *v7; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  bool v11; // al
  int v12; // eax
  const _s_RTTIBaseClassDescriptor *result; // eax
  const _s_RTTIBaseClassArray *pBaseClassArray; // [esp+Ch] [ebp-24h]
  const _s_RTTIBaseClassDescriptor *pCrossCastTargetBCD; // [esp+10h] [ebp-20h]
  const _s_RTTIBaseClassDescriptor *pCrossCastSourceBCD; // [esp+14h] [ebp-1Ch]
  int offsetDownCastResult; // [esp+18h] [ebp-18h]
  const _s_RTTIBaseClassDescriptor *pDownCastResultBCD; // [esp+1Ch] [ebp-14h]
  unsigned int nTargetBases; // [esp+20h] [ebp-10h]
  unsigned int iTarget; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-8h]
  bool fDownCastAllowed; // [esp+2Fh] [ebp-1h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  offsetDownCastResult = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v7 = nullptr;
  pDownCastResultBCD = nullptr;
  pCrossCastSourceBCD = nullptr;
  pCrossCastTargetBCD = nullptr;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  nTargetBases = 0;
  fDownCastAllowed = true;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  do
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( (v8->attributes & 3) == 0 )
          pCrossCastTargetBCD = v8;
        iTarget = i;
        v7 = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
      {
        if ( i - iTarget > nTargetBases )
        {
          if ( (v8->attributes & 5) == 0 )
            pCrossCastSourceBCD = v8;
        }
        else if ( fDownCastAllowed )
        {
          if ( (v7->attributes & 0x40) != 0 )
          {
            if ( (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 4) == 0;
          }
          else
          {
            if ( iTarget == 0 && (v8->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = true;
          }
          if ( fDownCastAllowed && v11 )
          {
            v12 = PMDtoOffset(pmd: &v7->where, pThis: pCompleteObject);
            if ( pDownCastResultBCD != nullptr && offsetDownCastResult != v12 )
              return nullptr;
            pDownCastResultBCD = v7;
            offsetDownCastResult = v12;
          }
        }
      }
    }
    ++i;
  }
  while ( i < numBaseClasses );
  if ( !fDownCastAllowed || (result = pDownCastResultBCD, pDownCastResultBCD == nullptr) )
  {
    if ( pCrossCastSourceBCD == nullptr )
      return nullptr;
    result = pCrossCastTargetBCD;
    if ( pCrossCastTargetBCD == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100248B0
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
      JUMPOUT(0x100233B6);
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
// Address: 0x10024940
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
// Address: 0x10024949
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x1002495C
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
// Address: 0x10024976
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
// Address: 0x100249EB
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int i; // esi
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( count == 0 )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
LABEL_20:
    for ( i = n; ; ++i )
    {
      if ( i >= count )
        return 0;
      if ( *v5 == 0 || *v5 != *v4 )
        break;
      ++v5;
      ++v4;
    }
    v10 = *(unsigned __int8 *)v5;
    v11 = *(unsigned __int8 *)v4;
  }
  else
  {
    v4 = last;
    v5 = first;
    while ( 1 )
    {
      v6 = *v5;
      v5 += 4;
      v4 += 4;
      if ( v6 == 0 || v6 != *(v4 - 4) )
        break;
      v7 = *(v5 - 3);
      if ( v7 == 0 || v7 != *(v4 - 3) )
      {
        v10 = *((unsigned __int8 *)v5 - 3);
        v11 = *((unsigned __int8 *)v4 - 3);
        return v10 - v11;
      }
      v8 = *(v5 - 2);
      if ( v8 == 0 || v8 != *(v4 - 2) )
      {
        v10 = *((unsigned __int8 *)v5 - 2);
        v11 = *((unsigned __int8 *)v4 - 2);
        return v10 - v11;
      }
      v9 = *(v5 - 1);
      if ( v9 == 0 || v9 != *(v4 - 1) )
      {
        v10 = *((unsigned __int8 *)v5 - 1);
        v11 = *((unsigned __int8 *)v4 - 1);
        return v10 - v11;
      }
      n += 4;
      if ( n >= count - 4 )
        goto LABEL_20;
    }
    v10 = *((unsigned __int8 *)v5 - 4);
    v11 = *((unsigned __int8 *)v4 - 4);
  }
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x10024AAB
// Name: IsRootUNCName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  unsigned __int8 *v9; // [esp+0h] [ebp-4h]

  strlen(buf: v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return false;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return false;
  v3 = path[2];
  if ( v3 == 92 )
    return false;
  if ( v3 == 47 )
    return false;
  v4 = path + 3;
  v5 = path[3];
  if ( v5 == 0 )
    return false;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 == 0 )
    return false;
  v6 = (char *)(v4 + 1);
  if ( *v6 == 0 )
    return false;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 != 0 );
  return *v6 == 0 || v6[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10024B25
// Name: _fullpath_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fullpath_helper(char *buf, const char *path, unsigned int sz, char **pBuf)
{
  int v4; // esi
  char *v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(UserBuf: buf, path, maxlen: sz);
  v6 = _errno();
  if ( v5 != nullptr )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(UserBuf: nullptr, path, maxlen: 0);
    *pBuf = result;
  }
  else
  {
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10024B85
// Name: __stat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stat64i32(const char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  unsigned int v3; // eax
  unsigned __int8 *v4; // eax
  const char *v5; // esi
  int v6; // eax
  __int64 v7; // rax
  int v8; // esi
  DWORD LastError; // eax
  int retval; // [esp+Ch] [ebp-26Ch]
  int drive; // [esp+10h] [ebp-268h]
  _FILETIME LocalFTime; // [esp+14h] [ebp-264h] BYREF
  int fd; // [esp+1Ch] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+20h] [ebp-258h] BYREF
  _SYSTEMTIME SystemTime; // [esp+160h] [ebp-118h] BYREF
  char pathbuf[260]; // [esp+170h] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  retval = 0;
  if ( name == nullptr || buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "?*") != nullptr )
  {
LABEL_5:
    *_errno() = 2;
    *__doserrno() = 2;
    return -1;
  }
  if ( name[1] == 58 )
  {
    if ( *name != 0 && name[2] == 0 )
      goto LABEL_5;
    v3 = _mbctolower(c: *name) - 96;
  }
  else
  {
    v3 = _getdrive();
  }
  drive = v3;
  fd = (int)FindFirstFileExA(
              lpFileName: name,
              fInfoLevelId: FindExInfoStandard,
              lpFindFileData: &findbuf,
              fSearchOp: FindExSearchNameMatch,
              lpSearchFilter: nullptr,
              dwAdditionalFlags: 0);
  if ( fd != -1 )
  {
    if ( (findbuf.dwFileAttributes & 0x400) != 0 && findbuf.dwReserved0 == -1610612724 )
    {
      fd = -1;
      if ( _sopen_s(pfh: &fd, path: name, oflag: 0, shflag: 64, pmode: 0) == 0 && fd != -1 )
      {
        v8 = _fstat64i32(fildes: fd, buf);
        _close(fh: fd);
        return v8;
      }
      goto LABEL_5;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime != 0 || findbuf.ftLastWriteTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_mtime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime != 0 || findbuf.ftLastAccessTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_atime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( findbuf.ftCreationTime.dwLowDateTime == 0 && findbuf.ftCreationTime.dwHighDateTime == 0 )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_45:
      FindClose(hFindFile: (HANDLE)fd);
      goto LABEL_46;
    }
    if ( FileTimeToLocalFileTime(lpFileTime: &findbuf.ftCreationTime, lpLocalFileTime: &LocalFTime)
      && FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
    {
      buf->st_ctime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
      goto LABEL_45;
    }
LABEL_49:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    FindClose(hFindFile: (HANDLE)fd);
    return -1;
  }
  fd = 0;
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "./\\") == nullptr )
    goto LABEL_5;
  v4 = (unsigned __int8 *)fullpath_helper(buf: pathbuf, path: name, sz: 0x104u, pBuf: (char **)&fd);
  v5 = (const char *)v4;
  if ( v4 == nullptr || (strlen(buf: v4), v6 != 3) && !IsRootUNCName(path: v5) || GetDriveTypeA(lpRootPathName: v5) <= 1 )
  {
    if ( fd != 0 )
      free(pMem: (void *)fd);
    goto LABEL_5;
  }
  if ( fd != 0 )
    free(pMem: (void *)fd);
  findbuf.dwFileAttributes = 16;
  findbuf.nFileSizeHigh = 0;
  findbuf.nFileSizeLow = 0;
  findbuf.cFileName[0] = 0;
  v7 = __loctotime64_t(yr: 1980, mo: 1, dy: 1, hr: 0, mn: 0, sc: 0, dstflag: -1);
  dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
  buf->st_mtime = v7;
  buf->st_atime = v7;
  buf->st_ctime = v7;
LABEL_46:
  buf->st_mode = __dtoxmode(attr: findbuf.dwFileAttributes, name: dwHighDateTime);
  buf->st_nlink = 1;
  buf->st_size = findbuf.nFileSizeLow;
  if ( findbuf.nFileSizeHigh != 0 )
  {
    retval = -1;
    buf->st_size = 0;
  }
  buf->st_ino = 0;
  buf->st_gid = 0;
  buf->st_uid = 0;
  buf->st_dev = drive - 1;
  buf->st_rdev = drive - 1;
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10024FDC
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
// Address: 0x10025063
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
// Address: 0x1002509B
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100250AE
// Name: _iswcntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswcntrl(unsigned __int16 c)
{
  return iswctype(c, mask: 0x20u);
}

//------------------------------------------------------------------------------
// Address: 0x100250C1
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, unsigned int dwReason, void *lpreserved)
{
  unsigned __int8 *v4; // eax
  _tiddata *v5; // esi
  int (__stdcall *v6)(unsigned int, unsigned __int8 *); // eax
  unsigned int v7; // [esp-8h] [ebp-30h]
  unsigned __int8 *v8; // [esp-4h] [ebp-2Ch]

  if ( dwReason == 1 )
  {
    if ( !_heap_init() )
      return 0;
    if ( _mtinit() == 0 )
    {
LABEL_5:
      CWin32Surface::DrawFlushText();
      return 0;
    }
    _RTC_Initialize();
    _acmdln = GetCommandLineA();
    _aenvptr = (char *)__crtGetEnvironmentStringsA();
    if ( _ioinit() < 0 )
    {
LABEL_7:
      _mtterm();
      goto LABEL_5;
    }
    if ( _setargv() < 0 || _setenvp() < 0 || _cinit(initFloatingPrecision: 0) != 0 )
    {
      _ioterm();
      goto LABEL_7;
    }
    ++_proc_attached;
  }
  else if ( dwReason != 0 )
  {
    if ( dwReason == 2 )
    {
      __set_flsgetvalue();
      v4 = calloc(count: 1u, size: 0x214u);
      v5 = (_tiddata *)v4;
      if ( v4 == nullptr )
        return 0;
      v8 = v4;
      v7 = __flsindex;
      v6 = (int (__stdcall *)(unsigned int, unsigned __int8 *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v6(a1: v7, a2: v8) == 0 )
      {
        free(pMem: v5);
        return 0;
      }
      _initptd(ptd: v5, ptloci: nullptr);
      v5->_tid = GetCurrentThreadId();
      v5->_thandle = -1;
    }
    else if ( dwReason == 3 )
    {
      _freeptd(ptd: nullptr);
    }
  }
  else
  {
    if ( _proc_attached <= 0 )
      return 0;
    --_proc_attached;
    if ( _C_Termination_Done == 0 )
      _cexit();
    if ( lpreserved == nullptr )
    {
      _ioterm();
      _mtterm();
      CWin32Surface::DrawFlushText();
      if ( __flsindex != -1 )
        _mtterm();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025225
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+10h] [ebp-1Ch]

  if ( dwReason == 0 && _proc_attached == 0
    || (dwReason == 1 || dwReason == 2) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
  {
    return 0;
  }
  v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
  retcode = v5;
  if ( dwReason == 1 && !v5 )
  {
    DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
    _CRT_INIT(hDllHandle, dwReason: 0, lpreserved);
  }
  if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
    return 0;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x1002531B
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x1002533E
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x1002535E
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
  bool v8; // zf
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
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
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
LABEL_17:
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
// Address: 0x10025473
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
// Address: 0x100254A0
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
// Address: 0x100254E0
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
      goto main_loop_entrance_0;
tail_loop_start_0:
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
    goto tail_loop_start_0;
  while ( 1 )
  {
main_loop_entrance_0:
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
      goto tail_loop_start_0;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x10025620
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
// Address: 0x100256CA
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x100256E0
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x100256EB
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
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
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
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
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
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x10025916
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
// Address: 0x10025941
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  const char *v3; // esi
  int v5; // eax
  _flt *v6; // eax
  _flt *v7; // ecx
  int flags; // eax
  long double v9; // st7
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-34h] BYREF
  long double tmp; // [esp+1Ch] [ebp-24h]
  _flt answerstruct; // [esp+24h] [ebp-1Ch] BYREF

  v3 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v3] & 8
       : _isctype_l(c: *(unsigned __int8 *)v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  v6 = _fltin2(flt: &answerstruct, str: v3, _Locale: &_loc_update.localeinfo);
  v7 = v6;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v6->nbytes];
  flags = v6->flags;
  if ( (v7->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v9 = _HUGE;
    if ( *v3 == 45 )
      v9 = -_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v9 = 0.0, 0.0 != v7->dval) )
  {
    tmp = v7->dval;
    goto LABEL_24;
  }
  tmp = v9;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x10025A64
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10025A7B
// Name: __wtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtol(const wchar_t *nptr)
{
  return wcstol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x10025A91
// Name: __wtoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtoi(const wchar_t *nptr)
{
  return _wtol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x10025A9C
// Name: __wtof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _wtof_l(wchar_t *nptr, localeinfo_struct *plocinfo)
{
  unsigned __int16 *v2; // esi
  long double result; // st7
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( iswctype(c: *v2, mask: 8u) != 0 )
      ++v2;
    result = _wfltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025B24
// Name: __wtof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _wtof(wchar_t *nptr)
{
  return _wtof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10025B37
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // esi
  long double result; // st7
  int v4; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v2] & 8
         : _isctype_l(c: *(unsigned __int8 *)v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    result = _fltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025BE2
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(const char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10025BF5
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
  bool v8; // zf
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
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
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
LABEL_17:
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
// Address: 0x10025D0B
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
// Address: 0x10025D37
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
// Address: 0x10025D88
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
// Address: 0x10025DB6
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025E0C
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x10025E3C
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
// Address: 0x10025E8D
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
// Address: 0x10025EBB
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalnum_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x107;
  else
    result = _isctype_l(c, mask: 263, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025F11
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalnum(int c)
{
  if ( __locale_changed != 0 )
    return _isalnum_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x107;
}

//------------------------------------------------------------------------------
// Address: 0x10025F50
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x10025F90
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd(v2, *(__m128d *)&S));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002606D
// Name: _copytlocinfo_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall copytlocinfo_nolock(threadlocaleinfostruct *ptlocid@<eax>, threadlocaleinfostruct *ptlocis@<ecx>)
{
  if ( ptlocis != nullptr && ptlocid != nullptr && ptlocid != ptlocis )
  {
    *ptlocid = *ptlocis;
    ptlocid->refcount = 0;
    __addlocaleref(ptloci: ptlocid);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026093
// Name: ___init_collate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_collate()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026096
// Name: __strcats
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _strcats(char *outstr, unsigned int sizeInBytes, int n, ...)
{
  int v3; // edi
  const char **p_n; // esi

  v3 = 0;
  if ( n > 0 )
  {
    p_n = (const char **)&n;
    do
    {
      if ( strcat_s(_Dst: outstr, _SizeInBytes: sizeInBytes, _Src: *++p_n) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      ++v3;
    }
    while ( v3 < n );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100260D7
// Name: ___lc_strtolc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __lc_strtolc(tagLC_STRINGS *names, char *locale)
{
  const char *v2; // esi
  unsigned int v4; // eax
  bool j; // zf
  const char *v6; // edi
  char v7; // bl
  int v8; // eax
  char *szCountry; // eax
  unsigned int v10; // [esp-Ch] [ebp-18h]
  const char *v12; // [esp-8h] [ebp-14h]
  unsigned int v13; // [esp-4h] [ebp-10h]
  int i; // [esp+18h] [ebp+Ch]

  memset(dst: (int)names, value: nullptr, count: sizeof(tagLC_STRINGS));
  v2 = locale;
  if ( *locale == 0 )
    return 0;
  if ( *locale == 46 && locale[1] != 0 )
  {
    if ( strncpy_s(_Dst: names->szCodePage, _SizeInBytes: 0x10u, _Src: locale + 1, _Count: 0xFu) != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    names->szCodePage[15] = 0;
    return 0;
  }
  i = 0;
  strcspn(string: (unsigned __int8 *)locale, control: "_.,");
  for ( j = v4 == 0; !j; j = v4 == 0 )
  {
    v6 = &v2[v4];
    v7 = v2[v4];
    if ( i != 0 )
    {
      if ( i == 1 )
      {
        if ( v4 >= 0x40 || v7 == 95 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 64;
        szCountry = names->szCountry;
      }
      else
      {
        if ( i != 2 || v4 >= 0x10 || v7 != 0 && v7 != 44 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 16;
        szCountry = names->szCodePage;
      }
      v8 = strncpy_s(_Dst: szCountry, _SizeInBytes: v10, _Src: v12, _Count: v13);
    }
    else
    {
      if ( v4 >= 0x40 || v7 == 46 )
        return -1;
      v8 = strncpy_s(_Dst: names->szLanguage, _SizeInBytes: 0x40u, _Src: v2, _Count: v4);
    }
    if ( v8 != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( v7 == 44 || v7 == 0 )
      return 0;
    ++i;
    v2 = v6 + 1;
    strcspn(string: (unsigned __int8 *)v6 + 1, control: "_.,");
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100261F6
// Name: ___lc_lctostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __lc_lctostr(char *locale, unsigned int sizeInBytes, const tagLC_STRINGS *names)
{
  if ( strcpy_s(_Dst: locale, _SizeInBytes: sizeInBytes, _Src: names->szLanguage) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( names->szCountry[0] != 0 )
    _strcats(outstr: locale, sizeInBytes, n: 2, "_", names->szCountry);
  if ( names->szCodePage[0] != 0 )
    _strcats(outstr: locale, sizeInBytes, n: 2, ".", names->szCodePage);
}

//------------------------------------------------------------------------------
// Address: 0x10026261
// Name: _setlocale_get_all
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall setlocale_get_all@<eax>(threadlocaleinfostruct *ploci@<esi>)
{
  char *result; // eax
  char *v2; // edi
  unsigned __int8 **v3; // eax
  int v4; // eax
  unsigned __int8 *locale; // [esp-8h] [ebp-1Ch]
  int *refcount; // [esp+4h] [ebp-10h]
  int same; // [esp+8h] [ebp-Ch]
  threadlocaleinfostruct::<unnamed_type_lc_category> *v8; // [esp+Ch] [ebp-8h]
  const $FAA2ED44176E8AD2BA02CFC02FF7315D *v9; // [esp+10h] [ebp-4h]

  same = 1;
  result = (char *)operator new(nSize: 0x355u);
  refcount = (int *)result;
  if ( result != nullptr )
  {
    v2 = result + 4;
    result[4] = 0;
    *(_DWORD *)result = 1;
    _strcats(outstr: result + 4, sizeInBytes: 0x351u, n: 3, "LC_COLLATE", "=", ploci->lc_category[1].locale);
    v9 = &__lc_category[1];
    v8 = &ploci->lc_category[1];
    do
    {
      if ( strcat_s(_Dst: v2, _SizeInBytes: 0x351u, _Src: ";") != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      v3 = (unsigned __int8 **)v8;
      locale = (unsigned __int8 *)v8[1].locale;
      ++v8;
      strcmp(str1: *v3, str2: locale);
      if ( v4 != 0 )
        same = 0;
      ++v9;
      _strcats(outstr: v2, sizeInBytes: 0x351u, n: 3, v9->catname, "=", v8->locale);
    }
    while ( (int)v9 < (int)&__lc_category[5] );
    if ( same != 0 )
    {
      free(pMem: refcount);
      if ( ploci->lc_category[0].refcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].refcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].refcount);
      }
      if ( ploci->lc_category[0].wrefcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].wrefcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].wrefcount);
      }
      result = ploci->lc_category[2].locale;
      ploci->lc_category[0].wrefcount = nullptr;
      ploci->lc_category[0].wlocale = nullptr;
      ploci->lc_category[0].refcount = nullptr;
      ploci->lc_category[0].locale = nullptr;
    }
    else
    {
      if ( ploci->lc_category[0].refcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].refcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].refcount);
      }
      if ( ploci->lc_category[0].wrefcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].wrefcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].wrefcount);
      }
      ploci->lc_category[0].wrefcount = nullptr;
      ploci->lc_category[0].wlocale = nullptr;
      ploci->lc_category[0].refcount = refcount;
      ploci->lc_category[0].locale = v2;
      return v2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100263C6
// Name: __expandlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _expandlocale(char *expr, char *output, unsigned int sizeInChars, tagLC_ID *id, unsigned int *cp)
{
  const char *v5; // esi
  _tiddata *v6; // eax
  tagLC_ID *p_cacheid; // ebx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  unsigned int charactersInExpression; // [esp+10h] [ebp-B0h]
  unsigned int *pcachecp; // [esp+14h] [ebp-ACh]
  char *cachein; // [esp+18h] [ebp-A8h]
  char *cacheout; // [esp+28h] [ebp-98h]
  tagLC_STRINGS names; // [esp+2Ch] [ebp-94h] BYREF

  v5 = expr;
  v6 = _getptd();
  pcachecp = &v6->_setloc_data._cachecp;
  p_cacheid = &v6->_setloc_data._cacheid;
  cachein = v6->_setloc_data._cachein;
  cacheout = v6->_setloc_data._cacheout;
  if ( expr == nullptr || output == nullptr || sizeInChars == 0 )
    return nullptr;
  if ( *expr == 67 && expr[1] == 0 )
  {
    if ( strcpy_s(_Dst: output, _SizeInBytes: sizeInChars, _Src: "C") == 0 )
    {
      if ( id != nullptr )
      {
        id->wLanguage = 0;
        id->wCountry = 0;
        id->wCodePage = 0;
      }
      if ( cp != nullptr )
        *cp = 0;
      return output;
    }
LABEL_12:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  strlen(buf: (unsigned __int8 *)expr);
  charactersInExpression = v9;
  if ( v9 >= 0x83
    || (strcmp(str1: (unsigned __int8 *)cacheout, str2: (unsigned __int8 *)expr), v10 != 0)
    && (strcmp(str1: (unsigned __int8 *)cachein, str2: (unsigned __int8 *)expr), v11 != 0) )
  {
    if ( __lc_strtolc(&names, locale: expr) == 0
      && __get_qualified_locale(lpInStr: &names, lpOutId: p_cacheid, lpOutStr: &names) != 0 )
    {
      *pcachecp = p_cacheid->wCodePage;
      __lc_lctostr(locale: cacheout, sizeInBytes: 0x83u, &names);
      if ( *expr == 0 || (v12 = charactersInExpression, charactersInExpression >= 0x83) )
      {
        v12 = 0;
        v5 = pHelpString;
      }
      if ( strncpy_s(_Dst: cachein, _SizeInBytes: 0x83u, _Src: v5, _Count: v12 + 1) != 0 )
        goto LABEL_12;
      goto LABEL_22;
    }
    return nullptr;
  }
LABEL_22:
  if ( id != nullptr )
    *id = *p_cacheid;
  if ( cp != nullptr )
    *cp = *pcachecp;
  if ( strcpy_s(_Dst: output, _SizeInBytes: sizeInChars, _Src: cacheout) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return cacheout;
}

//------------------------------------------------------------------------------
// Address: 0x100265E7
// Name: _setlocale_set_cat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall setlocale_set_cat@<eax>(threadlocaleinfostruct *ploci@<esi>, int category@<ecx>, char *locale)
{
  _tiddata *v4; // edi
  char *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int *v9; // ecx
  unsigned int id; // ecx
  _is_ctype_compatible *Lcid_c; // eax
  unsigned int v12; // edx
  int is_clike; // edx
  _is_ctype_compatible *v14; // eax
  unsigned int j; // eax
  int v16; // edi
  char *v17; // eax
  int v18; // ecx
  char *v19; // [esp-4h] [ebp-1D4h]
  unsigned int buf2; // [esp+10h] [ebp-1C0h]
  unsigned int oldhandle; // [esp+18h] [ebp-1B8h]
  unsigned int oldcodepage; // [esp+1Ch] [ebp-1B4h]
  tagLC_ID idtemp; // [esp+20h] [ebp-1B0h] BYREF
  unsigned int *v24; // [esp+28h] [ebp-1A8h]
  unsigned int cptemp; // [esp+2Ch] [ebp-1A4h] BYREF
  _is_ctype_compatible buf1; // [esp+30h] [ebp-1A0h]
  char *oldlocale; // [esp+38h] [ebp-198h]
  char *pch; // [esp+3Ch] [ebp-194h]
  int v29; // [esp+40h] [ebp-190h]
  int i; // [esp+44h] [ebp-18Ch]
  unsigned __int16 out[128]; // [esp+48h] [ebp-188h] BYREF
  char lctemp[132]; // [esp+148h] [ebp-88h] BYREF

  v29 = category;
  oldlocale = locale;
  v4 = _getptd();
  if ( _expandlocale(expr: locale, output: lctemp, sizeInChars: 0x83u, id: &idtemp, cp: &cptemp) == nullptr )
    return nullptr;
  v6 = (char *)ploci + 16 * category;
  strcmp(str1: (unsigned __int8 *)lctemp, str2: *((unsigned __int8 **)v6 + 18));
  if ( v7 != 0 )
  {
    strlen(buf: (unsigned __int8 *)lctemp);
    i = v8 + 5;
    pch = (char *)operator new(nSize: v8 + 5);
    if ( pch != nullptr )
    {
      oldlocale = *((char **)v6 + 18);
      v24 = &ploci->lc_handle[v29];
      oldhandle = *v24;
      buf1.is_clike = (int)&ploci->lc_id[v29];
      oldcodepage = ploci->lc_codepage;
      if ( strcpy_s(_Dst: pch + 4, _SizeInBytes: i - 4, _Src: lctemp) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      v9 = v24;
      *((_DWORD *)v6 + 18) = pch + 4;
      *v9 = idtemp.wLanguage;
      *(tagLC_ID *)buf1.is_clike = idtemp;
      if ( v29 == 2 )
      {
        i = 0;
        ploci->lc_codepage = cptemp;
        id = v4->_setloc_data._Lcid_c[4].id;
        buf1.is_clike = v4->_setloc_data._Lcid_c[4].is_clike;
        Lcid_c = v4->_setloc_data._Lcid_c;
        while ( ploci->lc_codepage != Lcid_c->id )
        {
          v12 = Lcid_c->id;
          ++i;
          Lcid_c->id = id;
          buf2 = v12;
          is_clike = Lcid_c->is_clike;
          Lcid_c->is_clike = buf1.is_clike;
          id = buf2;
          ++Lcid_c;
          buf1.is_clike = is_clike;
          if ( i >= 5 )
            goto LABEL_14;
        }
        if ( i != 0 )
        {
          v14 = &v4->_setloc_data._Lcid_c[i];
          v4->_setloc_data._Lcid_c[0].id = v14->id;
          v4->_setloc_data._Lcid_c[0].is_clike = v14->is_clike;
          v14->id = id;
          v14->is_clike = buf1.is_clike;
        }
LABEL_14:
        if ( i == 5 )
        {
          if ( __crtGetStringTypeA(
                 plocinfo: nullptr,
                 dwInfoType: 1u,
                 lpSrcStr: first_127char,
                 cchSrc: 127,
                 lpCharType: out,
                 code_page: ploci->lc_codepage,
                 lcid: ploci->lc_handle[2],
                 bError: 1) != 0 )
          {
            for ( j = 0; j < 0x7F; ++j )
              out[j] &= 0x1FFu;
            v4->_setloc_data._Lcid_c[0].is_clike = memcmp(lhs: out, rhs: ctype_loc_style, siz: 0xFEu) == 0;
          }
          else
          {
            v4->_setloc_data._Lcid_c[0].is_clike = 0;
          }
          v4->_setloc_data._Lcid_c[0].id = ploci->lc_codepage;
        }
        ploci->lc_clike = v4->_setloc_data._Lcid_c[0].is_clike;
      }
      if ( v29 == 1 )
        ploci->lc_collate_cp = cptemp;
      if ( ((int (__cdecl *)())__lc_category[v29].init)() == 0 )
      {
        if ( oldlocale != __clocalestr )
        {
          v16 = 2 * (v29 + 5);
          if ( InterlockedDecrement(lpAddend: ploci->lc_category[v29].refcount) == 0 )
          {
            free(pMem: *((void **)&ploci->refcount + 2 * v16));
            free(pMem: *((void **)v6 + 21));
            *((_DWORD *)v6 + 19) = 0;
          }
        }
        v17 = pch;
        v18 = 2 * (v29 + 5);
        *(_DWORD *)pch = 1;
        *(&ploci->refcount + 2 * v18) = (int)v17;
        return *((char **)v6 + 18);
      }
      v19 = pch;
      *((_DWORD *)v6 + 18) = oldlocale;
      free(pMem: v19);
      *v24 = oldhandle;
      ploci->lc_codepage = oldcodepage;
    }
    return nullptr;
  }
  return *((char **)v6 + 18);
}

//------------------------------------------------------------------------------
// Address: 0x10026921
// Name: _setlocale_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall setlocale_nolock(int _category, threadlocaleinfostruct *ploci, char *_locale)
{
  int v3; // ebx
  threadlocaleinfostruct *v4; // esi
  char *result; // eax
  unsigned __int8 *v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ebx
  unsigned int v9; // eax
  const $FAA2ED44176E8AD2BA02CFC02FF7315D *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned __int8 *v15; // edi
  unsigned __int8 **lc_category; // edi
  int v17; // eax
  int i; // [esp+10h] [ebp-94h]
  unsigned int len; // [esp+14h] [ebp-90h]
  unsigned int lena; // [esp+14h] [ebp-90h]
  int fLocaleSet; // [esp+18h] [ebp-8Ch]
  char lctemp[132]; // [esp+1Ch] [ebp-88h] BYREF

  v3 = 0;
  v4 = ploci;
  if ( _category != 0 )
  {
    if ( _locale != nullptr )
      return setlocale_set_cat(ploci, category: _category, locale: _locale);
    else
      return ploci->lc_category[_category].locale;
  }
  len = 1;
  fLocaleSet = 0;
  if ( _locale == nullptr )
    return setlocale_get_all(ploci: v4);
  if ( *_locale == 76 && _locale[1] == 67 && _locale[2] == 95 )
  {
    v6 = (unsigned __int8 *)_locale;
    do
    {
      strpbrk(string: v6, control: "=;");
      v8 = v7;
      if ( v7 == nullptr )
        return nullptr;
      v9 = v7 - v6;
      lena = v9;
      if ( v9 == 0 || *v8 == 59 )
        return nullptr;
      i = 1;
      v10 = &__lc_category[1];
      while ( 1 )
      {
        if ( strncmp(first: v10->catname, last: (const char *)v6, count: v9) == 0 )
        {
          strlen(buf: (unsigned __int8 *)v10->catname);
          if ( lena == v11 )
            break;
        }
        ++i;
        if ( (int)++v10 > (int)&__lc_category[5] )
          break;
        v9 = lena;
      }
      v12 = v8 + 1;
      strcspn(string: v12, control: ";");
      v14 = v13;
      if ( v13 == 0 && *v12 != 59 )
        return nullptr;
      if ( i <= 5 )
      {
        if ( strncpy_s(_Dst: lctemp, _SizeInBytes: 0x83u, _Src: (const char *)v12, _Count: v13) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        lctemp[v14] = 0;
        if ( setlocale_set_cat(ploci, category: i, locale: lctemp) != nullptr )
          ++fLocaleSet;
      }
      v15 = &v12[v14];
      if ( *v15 == 0 )
        break;
      v6 = v15 + 1;
    }
    while ( *v6 != 0 );
    result = nullptr;
    if ( fLocaleSet == 0 )
      return result;
    v4 = ploci;
    return setlocale_get_all(ploci: v4);
  }
  result = _expandlocale(expr: _locale, output: lctemp, sizeInChars: 0x83u, id: nullptr, cp: nullptr);
  if ( result != nullptr )
  {
    lc_category = (unsigned __int8 **)v4->lc_category;
    do
    {
      if ( v3 != 0 )
      {
        strcmp(str1: (unsigned __int8 *)lctemp, str2: *lc_category);
        if ( v17 == 0 || setlocale_set_cat(ploci: v4, category: v3, locale: lctemp) != nullptr )
          ++fLocaleSet;
        else
          len = 0;
      }
      ++v3;
      lc_category += 4;
    }
    while ( v3 <= 5 );
    result = nullptr;
    if ( len != 0 || fLocaleSet != 0 )
      return setlocale_get_all(ploci: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026B3D
// Name: _setlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl setlocale(unsigned int _category, char *_locale)
{
  _tiddata *v3; // esi
  unsigned __int8 *v4; // ebx
  int v5; // eax
  char *retval; // [esp+14h] [ebp-20h]

  retval = nullptr;
  if ( _category <= 5 )
  {
    v3 = _getptd();
    __updatetlocinfo();
    v3->_ownlocale |= 0x10u;
    v4 = calloc(count: 0xD8u, size: 1u);
    if ( v4 != nullptr )
    {
      _lock(locknum: 12);
      copytlocinfo_nolock(ptlocid: (threadlocaleinfostruct *)v4, ptlocis: v3->ptlocinfo);
      _unlock(locknum: 12);
      retval = setlocale_nolock(_category, ploci: (threadlocaleinfostruct *)v4, _locale);
      if ( retval != nullptr )
      {
        if ( _locale != nullptr )
        {
          strcmp(str1: (unsigned __int8 *)_locale, str2: (unsigned __int8 *)__clocalestr);
          if ( v5 != 0 )
            __locale_changed = 1;
        }
        _lock(locknum: 12);
        _updatetlocinfoEx_nolock(pptlocid: &v3->ptlocinfo, ptlocis: (threadlocaleinfostruct *)v4);
        __removelocaleref(ptloci: (threadlocaleinfostruct *)v4);
        if ( (v3->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
        {
          _updatetlocinfoEx_nolock(pptlocid: &__ptlocinfo, ptlocis: v3->ptlocinfo);
          __lconv = __ptlocinfo->lconv;
          _pctype = __ptlocinfo->pctype;
          __mb_cur_max = __ptlocinfo->mb_cur_max;
        }
        _unlock(locknum: 12);
      }
      else
      {
        __removelocaleref(ptloci: (threadlocaleinfostruct *)v4);
        __freetlocinfo(ptloci: (threadlocaleinfostruct *)v4);
      }
    }
    v3->_ownlocale &= ~0x10u;
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026CB1
// Name: ___libm_sse2_pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_pow()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100277A0
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
// Address: 0x10027828
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  if ( __get_sigabrt() != nullptr )
    raise(signum: 22);
  if ( (__abort_behavior & 2) != 0 )
    _call_reportfault(nDbgHookCode: 3, dwExceptionCode: 0x40000015u, dwExceptionFlags: 1u);
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1002785B
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
// Address: 0x1002787C
// Name: __GET_RTERRMSG
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const wchar_t *__cdecl _GET_RTERRMSG(int rterrnum)
{
  int v1; // eax

  v1 = 0;
  while ( rterrnum != rterrs[v1].rterrno )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return nullptr;
  }
  return rterrs[v1].rterrtxt;
}

//------------------------------------------------------------------------------
// Address: 0x100278A2
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  const wchar_t *v1; // edi
  unsigned int v2; // eax
  HANDLE StdHandle; // eax
  void *v4; // esi
  unsigned int i; // eax
  DWORD v6; // eax
  unsigned int bytes_written; // [esp+Ch] [ebp-1FCh] BYREF
  char buffer[500]; // [esp+10h] [ebp-1F8h] BYREF

  v1 = _GET_RTERRMSG(rterrnum);
  bytes_written = (unsigned int)v1;
  if ( v1 != nullptr )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v4 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        for ( i = 0; i < 0x1F4; ++i )
        {
          buffer[i] = v1[i];
          if ( v1[i] == 0 )
            break;
        }
        buffer[499] = 0;
        strlen(buf: (unsigned __int8 *)buffer);
        WriteFile(
          hFile: v4,
          lpBuffer: buffer,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &bytes_written,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( wcscpy_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"Runtime Error!\n\nProgram: ") != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      outmsg[285] = 0;
      if ( GetModuleFileNameW(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0
        && wcscpy_s(_Dst: &outmsg[25], _SizeInWords: 0x2FBu, _Src: L"<program name unknown>") != 0
        || wcslen(wcs: &outmsg[25]) + 1 > 0x3C
        && (v2 = wcslen(wcs: &outmsg[25]),
            wcsncpy_s(
              _Dst: (unsigned __int16 *)&vec4_origin_13.w + v2,
              _SizeInWords: 763 - (((char *)&vec4_origin_13.w + 2 * v2 - (char *)&outmsg[25]) >> 1),
              _Src: L"...",
              _Count: 3u) != 0)
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"\n\n") != 0
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: (const wchar_t *)bytes_written) != 0 )
      {
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      __crtMessageBoxW(lpText: outmsg, lpCaption: L"Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027A51
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
// Address: 0x10027A8A
// Name: ___getlocaleinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __getlocaleinfo(
        localeinfo_struct *plocinfo,
        int lc_type,
        unsigned int localehandle,
        unsigned int fieldtype,
        void **address)
{
  unsigned __int8 *v5; // ebx
  unsigned int LocaleInfoA; // esi
  unsigned int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  unsigned int LocaleInfoW; // eax
  int v12; // ebx
  unsigned __int8 *v13; // eax
  int buffersize; // [esp+Ch] [ebp-90h]
  int bufferused; // [esp+10h] [ebp-8Ch]
  unsigned int dw; // [esp+14h] [ebp-88h] BYREF
  unsigned __int8 cbuffer[128]; // [esp+18h] [ebp-84h] BYREF

  dw = (unsigned int)plocinfo;
  switch ( lc_type )
  {
    case 1:
      bufferused = 0;
      v5 = cbuffer;
      LocaleInfoA = __crtGetLocaleInfoA(
                      plocinfo,
                      Locale: localehandle,
                      LCType: fieldtype,
                      lpLCData: (char *)cbuffer,
                      cchData: 128);
      if ( LocaleInfoA == 0 )
      {
        if ( GetLastError() != 122 )
          return -1;
        v7 = __crtGetLocaleInfoA(
               plocinfo: (localeinfo_struct *)dw,
               Locale: localehandle,
               LCType: fieldtype,
               lpLCData: nullptr,
               cchData: 0);
        buffersize = v7;
        if ( v7 == 0 )
          return -1;
        v8 = calloc(count: v7, size: 1u);
        v5 = v8;
        if ( v8 == nullptr )
          return -1;
        bufferused = 1;
        LocaleInfoA = __crtGetLocaleInfoA(
                        plocinfo: (localeinfo_struct *)dw,
                        Locale: localehandle,
                        LCType: fieldtype,
                        lpLCData: (char *)v8,
                        cchData: buffersize);
        if ( LocaleInfoA == 0 )
          goto LABEL_9;
      }
      v9 = calloc(count: LocaleInfoA, size: 1u);
      *address = v9;
      if ( v9 == nullptr )
      {
        if ( bufferused == 0 )
          return -1;
LABEL_9:
        free(pMem: v5);
        return -1;
      }
      if ( strncpy_s(_Dst: (char *)v9, _SizeInBytes: LocaleInfoA, _Src: (const char *)v5, _Count: LocaleInfoA - 1) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      if ( bufferused != 0 )
        free(pMem: v5);
      break;
    case 2:
      *address = nullptr;
      LocaleInfoW = GetLocaleInfoW(Locale: localehandle, LCType: fieldtype, lpLCData: nullptr, cchData: 0);
      v12 = LocaleInfoW;
      if ( LocaleInfoW == 0
        || (v13 = calloc(count: LocaleInfoW, size: 2u), *address = v13, v13 == nullptr)
        || GetLocaleInfoW(Locale: localehandle, LCType: fieldtype, lpLCData: (LPWSTR)v13, cchData: v12) == 0 )
      {
        free(pMem: *address);
        *address = nullptr;
        return -1;
      }
      break;
    case 0:
      dw = 0;
      if ( GetLocaleInfoW(Locale: localehandle, LCType: fieldtype | 0x20000000, lpLCData: (LPWSTR)&dw, cchData: 2) == 0 )
        return -1;
      *(_BYTE *)address = dw;
      break;
    default:
      return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10027C36
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void *enull)
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x10027C45
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
// Address: 0x10027CB9
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
// Address: 0x10027D3B
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10027D57
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
// Address: 0x10027D99
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10027DB3
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
// Address: 0x10027DD2
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10027DE5
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10027DF8
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
  int v10; // eax
  char *v11; // esi
  threadlocaleinfostruct *locinfo; // eax
  char *v13; // esi
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // [esp-4h] [ebp-1Ch]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v16 = 22;
LABEL_3:
    *v8 = v16;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v16;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v16 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    *v11 = v11[1];
    *++v11 = *locinfo->lconv->decimal_point;
  }
  v13 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v14 = -1;
  else
    v14 = sizeInBytes + buf - v13;
  if ( strcpy_s(_Dst: v13, _SizeInBytes: v14, _Src: "e+000") != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( caps != 0 )
    *v13 = 69;
  if ( *pflt->mantissa != 48 )
  {
    v15 = pflt->decpt - 1;
    if ( v15 < 0 )
    {
      v15 = 1 - pflt->decpt;
      v13[1] = 45;
    }
    if ( v15 >= 100 )
    {
      v13[2] += v15 / 100;
      v15 %= 100;
    }
    if ( v15 >= 10 )
    {
      v13[3] += v15 / 10;
      LOBYTE(v15) = v15 % 10;
    }
    v13[4] += v15;
  }
  if ( (_outputformat & 1) != 0 && v13[2] == 48 )
    memmove(dst: (unsigned __int8 *)v13 + 2, src: (unsigned __int8 *)v13 + 3, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10027F59
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
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
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
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028020
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10028040
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
  int result; // eax
  unsigned int v9; // eax
  bool v10; // zf
  _BYTE *v11; // eax
  char *v12; // esi
  char *v13; // eax
  char *v14; // esi
  int x_low; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  char *i; // eax
  __int64 v19; // rax
  __int64 v20; // rcx
  _BYTE *v21; // esi
  _BYTE *v22; // edi
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-4h] [ebp-30h]
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
    v29 = 22;
LABEL_5:
    *v7 = v29;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v29;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v7 = _errno();
    v29 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v9 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v9 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v9, ndec, caps: 0);
    if ( result != 0 )
    {
      v10 = !_loc_update.updated;
      *buf = 0;
      if ( !v10 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    strrchr(string: (unsigned __int8 *)v6 + 2, chr: 0x65u);
    if ( v11 != nullptr )
    {
      *v11 = caps == 0 ? 112 : 80;
      v11[3] = 0;
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
    v6[1] = caps == 0 ? 120 : 88;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      v6[2] = 49;
      v12 = v6 + 3;
    }
    else
    {
      v6[2] = 48;
      v12 = v6 + 3;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v13 = v12;
    v14 = v12 + 1;
    pos = v13;
    if ( ndec != 0 )
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v13 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v16 = (unsigned __int16)(((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48);
        if ( v16 > 0x39 )
          LOBYTE(v16) = (caps != 0 ? 7 : 39) + ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        v17 = HIDWORD(mask);
        maskpos -= 4;
        *v14++ = v16;
        --ndec;
        mask = __PAIR64__(v17, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v14 - 1; *i == 102 || *i == 70; --i )
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
      memset(dst: (int)v14, value: (unsigned __int8 *)0x30, count: ndec);
      v14 += ndec;
    }
    if ( *pos == 0 )
      v14 = pos;
    *v14 = caps == 0 ? 112 : 80;
    HIDWORD(v20) = 0;
    v19 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v19 < 0 )
    {
      v14[1] = 45;
      v21 = v14 + 2;
      v19 = -v19;
    }
    else
    {
      v14[1] = 43;
      v21 = v14 + 2;
    }
    v22 = v21;
    *v21 = 48;
    if ( v19 >= 0 )
    {
      LODWORD(v20) = 1000;
      if ( v19 >= 1000 )
      {
        v28 = v20;
        v24 = v19 % v20;
        v23 = v19 / v28;
        *v21++ = v23 + 48;
        HIDWORD(exponent) = HIDWORD(v23);
        v19 = v24;
        if ( v21 != v22 )
          goto LABEL_60;
      }
    }
    if ( v19 >= 100 )
    {
LABEL_60:
      v26 = v19 % 100;
      v25 = v19 / 100;
      *v21 = v25 + 48;
      HIDWORD(exponent) = HIDWORD(v25);
      ++v21;
      v19 = v26;
    }
    if ( v21 != v22 || v19 >= 10 )
    {
      v27 = v19 % 10;
      *v21++ = v19 / 10 + 48;
      LOBYTE(v19) = v19 % 10;
      HIDWORD(exponent) = HIDWORD(v27);
    }
    *v21 = v19 + 48;
    v21[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100283B6
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
  char *v10; // esi
  int decpt; // eax
  int v12; // eax
  unsigned __int8 *v13; // esi
  int v14; // eax
  int v15; // edi
  int v16; // edi
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
      *(_WORD *)&buf[v8 + (pflt->sign == 45)] = 48;
    v10 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v10 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = (unsigned __int8 *)&v10[decpt];
    }
    else
    {
      strlen(buf: (unsigned __int8 *)v10);
      memmove(dst: (unsigned __int8 *)v10 + 1, src: (unsigned __int8 *)v10, count: v12 + 1);
      *v10 = 48;
      v13 = (unsigned __int8 *)(v10 + 1);
    }
    if ( ndec > 0 )
    {
      strlen(buf: v13);
      memmove(dst: v13 + 1, src: v13, count: v14 + 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v15 = pflt->decpt;
      if ( v15 < 0 )
      {
        v16 = -v15;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: (char *)v13 + 1, dist: ndec);
        memset(dst: (int)(v13 + 1), value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100284B9
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    v6 = -1;
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
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002857A
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
  int v8; // ebx
  BOOL v9; // eax
  char *v10; // edi
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    v8 = retstrflt.decpt - 1;
    v9 = retstrflt.sign == 45;
    v10 = &buf[v9];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v9;
    result = _fptostr(buf: v10, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
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
      if ( v8 < retstrflt.decpt - 1 )
        v10[strlen(v10) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028735
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
// Address: 0x10028760
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
// Address: 0x100287EB
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(void *enull)
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x100287FA
// Name: __call_reportfault
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _call_reportfault(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        int nDbgHookCode,
        unsigned int dwExceptionCode,
        unsigned int dwExceptionFlags)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // kr00_4
  BOOL v8; // edi
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+8h] [ebp-328h] BYREF
  _EXCEPTION_RECORD ExceptionRecord; // [esp+10h] [ebp-320h] BYREF
  _CONTEXT ContextRecord; // [esp+60h] [ebp-2D0h] BYREF
  unsigned int savedregs; // [esp+330h] [ebp+0h]
  void *retaddr; // [esp+334h] [ebp+4h] BYREF

  if ( nDbgHookCode != -1 )
    _crt_debugger_hook(_Reserved: nDbgHookCode);
  memset(dst: (int)&ExceptionRecord.ExceptionFlags, value: nullptr, count: 0x4Cu);
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionPointers.ContextRecord = &ContextRecord;
  ContextRecord.Eax = (unsigned int)&ContextRecord;
  ContextRecord.Ecx = v5;
  ContextRecord.Edx = v6;
  ContextRecord.Ebx = nDbgHookCode;
  ContextRecord.Esi = a2;
  ContextRecord.Edi = a1;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v7 = __readeflags();
  ContextRecord.EFlags = v7;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  ExceptionRecord.ExceptionCode = dwExceptionCode;
  ExceptionRecord.ExceptionFlags = dwExceptionFlags;
  ExceptionRecord.ExceptionAddress = retaddr;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v8 && nDbgHookCode != -1 )
    _crt_debugger_hook(_Reserved: nDbgHookCode);
}

//------------------------------------------------------------------------------
// Address: 0x10028923
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(unsigned int a1@<edi>)
{
  HANDLE CurrentProcess; // eax

  _call_reportfault(a1, a2: 0xC0000417, nDbgHookCode: 2, dwExceptionCode: 0xC0000417, dwExceptionFlags: 1u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000417);
}

//------------------------------------------------------------------------------
// Address: 0x10028948
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<edi>)
{
  void (*v1)(void); // eax

  v1 = (void (*)(void))DecodePointer(Ptr: __pInvalidArgHandler);
  if ( v1 == nullptr )
    _invoke_watson(a1);
  v1();
}

//------------------------------------------------------------------------------
// Address: 0x10028975
// Name: __invalid_parameter_noinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo()
{
  unsigned int v0; // edi

  _invalid_parameter(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10028985
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
// Address: 0x100289C7
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
// Address: 0x100289DA
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
// Address: 0x100289ED
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
// Address: 0x10028A10
// Name: __check_float_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _check_float_string@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        char **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        char *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = calloc(count: v5, size: 2u);
      *pFloatStr = (char *)v6;
      if ( v6 == nullptr )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy(dst: (unsigned __int8 *)*pFloatStr, src: (unsigned __int8 *)floatstring, count: *pnFloatStrSz);
    }
    else
    {
      v8 = _recalloc_crt(ptr: *pFloatStr, count: v5, size: 2u);
      if ( v8 == nullptr )
        return 0;
      *pFloatStr = (char *)v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028A67
// Name: _hextodec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl hextodec(unsigned __int8 chr)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = isdigit(c: chr) == 0;
  result = (char)chr;
  if ( v1 )
    return ((char)chr & 0xFFFFFFDF) - 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028A87
// Name: _inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall inc(int a1, _iobuf *fileptr)
{
  if ( --fileptr->_cnt < 0 )
    return _filbuf(str: fileptr);
  return *(unsigned __int8 *)fileptr->_ptr++;
}

//------------------------------------------------------------------------------
// Address: 0x10028A9D
// Name: _whiteout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall whiteout@<eax>(int *counter@<esi>, int a2@<ecx>, _iobuf *fileptr)
{
  int v3; // ebx
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  do
  {
    ++*counter;
    v3 = inc(a1: a2, fileptr);
    if ( v3 == -1 )
      break;
    v4 = isspace(c: (unsigned __int8)v3);
    a2 = v6;
  }
  while ( v4 != 0 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10028AC7
// Name: __input_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_l(_iobuf *stream, unsigned __int8 *format, localeinfo_struct *plocinfo, char *arglist)
{
  int result; // eax
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  unsigned __int8 v8; // al
  const unsigned __int8 *v9; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  const unsigned __int8 *v14; // eax
  _WORD *v15; // esi
  unsigned __int8 v16; // al
  int v17; // ebx
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  int v21; // ebx
  int v22; // ebx
  int i; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int j; // eax
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // ecx
  int v33; // eax
  int k; // eax
  int v35; // eax
  int v36; // ecx
  void (__cdecl *v37)(int, void *, char *, _LocaleUpdate *); // eax
  _WORD *v38; // edi
  int v39; // eax
  int v40; // eax
  unsigned __int8 *v41; // esi
  unsigned __int8 v42; // dl
  unsigned __int8 v43; // cl
  unsigned int v44; // edi
  int v45; // edx
  unsigned __int8 v46; // al
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // ecx
  unsigned __int64 v51; // kr00_8
  unsigned int v52; // edi
  unsigned int v53; // esi
  int v54; // eax
  int v55; // ecx
  int v56; // edi
  int v57; // ebx
  int v58; // eax
  int v59; // eax
  int v60; // ecx
  bool v61; // zf
  int v62; // [esp-14h] [ebp-21Ch]
  void *v63; // [esp-10h] [ebp-218h]
  char *v64; // [esp-Ch] [ebp-214h]
  int v65; // [esp-8h] [ebp-210h]
  int v66; // [esp-8h] [ebp-210h]
  int v67; // [esp-8h] [ebp-210h]
  int v68; // [esp-8h] [ebp-210h]
  int v69; // [esp-8h] [ebp-210h]
  int v70; // [esp-8h] [ebp-210h]
  int v71; // [esp-8h] [ebp-210h]
  int v72; // [esp-8h] [ebp-210h]
  int v73; // [esp-8h] [ebp-210h]
  int v74; // [esp-8h] [ebp-210h]
  char *arglistsave; // [esp+8h] [ebp-200h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-1FCh] BYREF
  int wctemp; // [esp+1Ch] [ebp-1ECh] BYREF
  char *v78; // [esp+20h] [ebp-1E8h]
  unsigned int number; // [esp+24h] [ebp-1E4h]
  char temp[4]; // [esp+28h] [ebp-1E0h] BYREF
  unsigned int nFloatStrSz; // [esp+2Ch] [ebp-1DCh] BYREF
  int integer64; // [esp+30h] [ebp-1D8h]
  unsigned __int8 prevchar; // [esp+37h] [ebp-1D1h]
  int malloc_FloatStrFlag; // [esp+38h] [ebp-1D0h] BYREF
  int count; // [esp+3Ch] [ebp-1CCh]
  unsigned __int64 num64; // [esp+40h] [ebp-1C8h]
  void *pointer; // [esp+48h] [ebp-1C0h]
  const unsigned __int8 *v88; // [esp+4Ch] [ebp-1BCh]
  int widthset; // [esp+50h] [ebp-1B8h]
  int comchr; // [esp+54h] [ebp-1B4h]
  char *pFloatStr; // [esp+58h] [ebp-1B0h] BYREF
  int started; // [esp+5Ch] [ebp-1ACh]
  char decimal; // [esp+60h] [ebp-1A8h]
  char negative; // [esp+61h] [ebp-1A7h]
  char fl_wchar_arg; // [esp+62h] [ebp-1A6h]
  char match; // [esp+63h] [ebp-1A5h]
  _iobuf *fileptr; // [esp+64h] [ebp-1A4h]
  char suppress; // [esp+6Bh] [ebp-19Dh]
  int width; // [esp+6Ch] [ebp-19Ch]
  char widechar; // [esp+73h] [ebp-195h]
  char chr[4]; // [esp+74h] [ebp-194h]
  char done_flag; // [esp+7Bh] [ebp-18Dh]
  int charcount; // [esp+7Ch] [ebp-18Ch] BYREF
  unsigned __int8 last; // [esp+83h] [ebp-185h]
  char floatstring[352]; // [esp+84h] [ebp-184h] BYREF
  char AsciiTable[32]; // [esp+1E4h] [ebp-24h] BYREF

  v78 = arglist;
  fileptr = stream;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  *(_DWORD *)chr = 0;
  if ( format == nullptr
    || stream == nullptr
    || (stream->_flag & 0x40) == 0
    && ((v5 = _fileno(stream)) == -1 || v5 == -2 ? (v6 = &__badioinfo) : (v6 = &__pioinfo[v5 >> 5][v5 & 0x1F]),
        (*((_BYTE *)v6 + 36) & 0x7F) != 0
     || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0)) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v8 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v8 == 0 )
    goto LABEL_288;
  v9 = format;
  while ( 2 )
  {
    if ( isspace(c: v8) != 0 )
    {
      --charcount;
      v10 = whiteout(counter: &charcount, a2: v65, fileptr);
      if ( v10 != -1 )
        _ungetc_nolock(ch: v10, str: fileptr);
      do
        ++v9;
      while ( isspace(c: *v9) != 0 );
      goto LABEL_272;
    }
    if ( *v9 != 37 )
      goto LABEL_264;
    if ( v9[1] == 37 )
    {
      ++v9;
LABEL_264:
      ++charcount;
      v57 = inc(a1: v65, fileptr);
      v58 = *v9++;
      *(_DWORD *)chr = v57;
      v88 = v9;
      if ( v58 == v57 )
      {
        if ( isleadbyte(c: v57) == 0 )
          goto LABEL_268;
        ++charcount;
        v59 = inc(a1: v74, fileptr);
        v60 = *v9++;
        v88 = v9;
        if ( v60 == v59 )
        {
          --charcount;
          goto LABEL_268;
        }
        if ( v59 != -1 )
          _ungetc_nolock(ch: v59, str: fileptr);
      }
      v61 = v57 == -1;
      goto LABEL_278;
    }
    number = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    decimal = 0;
    negative = 0;
    suppress = 0;
    done_flag = 0;
    fl_wchar_arg = 0;
    widechar = 0;
    last = 1;
    integer64 = 0;
    do
    {
      v11 = *++v9;
      v12 = isdigit(c: (unsigned __int8)v11);
      v13 = v66;
      if ( v12 != 0 )
      {
        ++widthset;
        width = 10 * width + v11 - 48;
        continue;
      }
      if ( v11 > 78 )
      {
        if ( v11 == 104 )
        {
          --last;
          --widechar;
        }
        else
        {
          if ( v11 == 108 )
          {
            v14 = v9 + 1;
            if ( v9[1] == 108 )
              goto LABEL_37;
            ++last;
          }
          else if ( v11 != 119 )
          {
            goto DEFAULT_LABEL;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v11 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
          default:
            break;
        }
        if ( v11 != 73 )
        {
          if ( v11 == 76 )
          {
            ++last;
            continue;
          }
DEFAULT_LABEL:
          ++done_flag;
          continue;
        }
        LOBYTE(v13) = v9[1];
        if ( (_BYTE)v13 == 54 )
        {
          v14 = v9 + 2;
          if ( v9[2] == 52 )
          {
LABEL_37:
            ++integer64;
            v9 = v14;
            num64 = 0;
            continue;
          }
        }
        if ( (_BYTE)v13 == 51 && v9[2] == 50 )
        {
          v9 += 2;
          continue;
        }
        if ( (_BYTE)v13 != 100 && (_BYTE)v13 != 105 && (_BYTE)v13 != 111 && (_BYTE)v13 != 120 && (_BYTE)v13 != 88 )
          goto DEFAULT_LABEL;
      }
    }
    while ( done_flag == 0 );
    v88 = v9;
    if ( suppress != 0 )
    {
      v15 = nullptr;
    }
    else
    {
      v15 = *(_WORD **)v78;
      arglistsave = v78;
      v78 += 4;
    }
    pointer = v15;
    done_flag = 0;
    if ( widechar == 0 )
    {
      v16 = *v9;
      if ( *v9 == 83 || (widechar = -1, v16 == 67) )
        widechar = 1;
    }
    v17 = *v9 | 0x20;
    comchr = v17;
    if ( v17 != 110 )
    {
      if ( v17 == 99 || v17 == 123 )
      {
        ++charcount;
        v18 = inc(a1: v13, fileptr);
      }
      else
      {
        v18 = whiteout(counter: &charcount, a2: v13, fileptr);
      }
      *(_DWORD *)chr = v18;
      if ( v18 == -1 )
        goto error_return;
      v15 = pointer;
      v9 = v88;
    }
    v19 = widthset;
    if ( widthset != 0 && width == 0 )
      goto LABEL_274;
    if ( v17 > 111 )
    {
      switch ( v17 )
      {
        case 'p':
          last = 1;
          break;
        case 's':
LABEL_129:
          if ( widechar > 0 )
            fl_wchar_arg = 1;
          goto scanit;
        case 'u':
          break;
        case 'x':
          goto LABEL_84;
        case '{':
          if ( widechar > 0 )
            fl_wchar_arg = 1;
          v41 = (unsigned __int8 *)(v9 + 1);
          if ( v9[1] == 94 )
          {
            v41 = (unsigned __int8 *)(v9 + 2);
            decimal = -1;
          }
          memset(dst: (int)AsciiTable, value: nullptr, count: sizeof(AsciiTable));
          if ( *v41 == 93 )
          {
            v42 = 93;
            ++v41;
            AsciiTable[11] = 32;
          }
          else
          {
            v42 = prevchar;
          }
          while ( 1 )
          {
            v46 = *v41;
            if ( *v41 == 93 )
              break;
            ++v41;
            if ( v46 == 45 && v42 != 0 && (v43 = *v41, *v41 != 93) )
            {
              ++v41;
              if ( v42 >= v43 )
              {
                last = v42;
                v42 = v43;
              }
              else
              {
                last = v43;
              }
              if ( v42 < last )
              {
                v44 = v42;
                v45 = (unsigned __int8)(last - v42);
                do
                {
                  AsciiTable[v44 >> 3] |= 1 << (v44 & 7);
                  ++v44;
                  --v45;
                }
                while ( v45 != 0 );
                v17 = comchr;
              }
              v19 = last & 7;
              AsciiTable[last >> 3] |= 1 << v19;
              v42 = 0;
            }
            else
            {
              v42 = v46;
              v19 = v46 & 7;
              AsciiTable[v46 >> 3] |= 1 << (v46 & 7);
              v17 = comchr;
            }
          }
          v88 = v41;
          v15 = pointer;
scanit:
          --charcount;
          v38 = v15;
          if ( *(_DWORD *)chr != -1 )
          {
            _ungetc_nolock(ch: *(int *)chr, str: fileptr);
            v19 = v68;
          }
          while ( 1 )
          {
            if ( widthset != 0 )
            {
              v39 = width--;
              if ( v39 == 0 )
                goto LABEL_202;
            }
            ++charcount;
            v40 = inc(a1: v19, fileptr);
            *(_DWORD *)chr = v40;
            if ( v40 == -1 )
              goto LABEL_200;
            if ( v17 != 99 )
            {
              if ( v17 != 115 )
                goto LABEL_293;
              if ( v40 >= 9 && v40 <= 13 )
              {
LABEL_200:
                --charcount;
                if ( v40 != -1 )
                  _ungetc_nolock(ch: v40, str: fileptr);
LABEL_202:
                if ( v38 != v15 )
                {
                  if ( suppress == 0 )
                  {
                    ++count;
                    if ( v17 != 99 )
                    {
                      if ( fl_wchar_arg != 0 )
                        *(_WORD *)pointer = 0;
                      else
                        *(_BYTE *)pointer = 0;
                    }
                  }
                  goto LABEL_262;
                }
                goto error_return;
              }
              if ( v40 == 32 )
              {
LABEL_293:
                if ( v17 != 123 )
                  goto LABEL_200;
                v19 = decimal ^ AsciiTable[v40 >> 3];
                v17 = comchr;
                if ( ((1 << (v40 & 7)) & v19) == 0 )
                  goto LABEL_200;
              }
            }
            if ( suppress != 0 )
            {
              v38 = (_WORD *)((char *)v38 + 1);
            }
            else
            {
              if ( fl_wchar_arg != 0 )
              {
                temp[0] = v40;
                if ( isleadbyte(c: v40) != 0 )
                {
                  ++charcount;
                  temp[1] = inc(a1: v69, fileptr);
                }
                wctemp = 63;
                _mbtowc_l(
                  pwc: (wchar_t *)&wctemp,
                  s: temp,
                  n: _loc_update.localeinfo.locinfo->mb_cur_max,
                  plocinfo: &_loc_update.localeinfo);
                *v15++ = wctemp;
              }
              else
              {
                *(_BYTE *)v15 = v40;
                v15 = (_WORD *)((char *)v15 + 1);
              }
              pointer = v15;
            }
          }
        default:
          goto LABEL_153;
      }
LABEL_209:
      v21 = *(_DWORD *)chr;
      if ( *(_DWORD *)chr == 45 )
      {
        negative = 1;
      }
      else if ( *(_DWORD *)chr != 43 )
      {
        goto getnum;
      }
      if ( --width == 0 && widthset != 0 )
      {
        done_flag = 1;
        goto getnum;
      }
      ++charcount;
      v21 = inc(a1: widthset, fileptr);
      goto LABEL_216;
    }
    switch ( v17 )
    {
      case 'o':
        goto LABEL_209;
      case 'c':
        if ( widthset == 0 )
        {
          ++width;
          widthset = 1;
        }
        goto LABEL_129;
      case 'd':
        goto LABEL_209;
      default:
        break;
    }
    if ( v17 <= 100 )
      goto LABEL_153;
    if ( v17 <= 103 )
    {
      v22 = 0;
      if ( *(_DWORD *)chr == 45 )
      {
        *pFloatStr = 45;
        v22 = 1;
        goto f_incwidth;
      }
      if ( *(_DWORD *)chr == 43 )
      {
f_incwidth:
        --width;
        ++charcount;
        *(_DWORD *)chr = inc(a1: v19, fileptr);
      }
      if ( widthset == 0 )
        width = -1;
      for ( i = (unsigned __int8)chr[0]; isdigit(c: i) != 0; i = (unsigned __int8)chr[0] )
      {
        v24 = width--;
        if ( v24 == 0 )
          break;
        ++started;
        pFloatStr[v22] = chr[0];
        if ( _check_float_string(
               pnFloatStrSz: &nFloatStrSz,
               &pFloatStr,
               nFloatStrUsed: ++v22,
               floatstring,
               pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
          goto error_return;
        ++charcount;
        *(_DWORD *)chr = inc(a1: v25, fileptr);
      }
      decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      if ( decimal == chr[0] )
      {
        v26 = width--;
        if ( v26 != 0 )
        {
          ++charcount;
          *(_DWORD *)chr = inc(a1: v67, fileptr);
          pFloatStr[v22] = decimal;
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: ++v22,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return;
          for ( j = (unsigned __int8)chr[0]; isdigit(c: j) != 0; j = (unsigned __int8)chr[0] )
          {
            v28 = width--;
            if ( v28 == 0 )
              break;
            ++started;
            pFloatStr[v22] = chr[0];
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return;
            ++charcount;
            *(_DWORD *)chr = inc(a1: v29, fileptr);
          }
        }
      }
      if ( started != 0 && (*(_DWORD *)chr == 101 || *(_DWORD *)chr == 69) )
      {
        v30 = width--;
        if ( v30 != 0 )
        {
          pFloatStr[v22] = 101;
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: ++v22,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return;
          ++charcount;
          *(_DWORD *)chr = inc(a1: v31, fileptr);
          if ( *(_DWORD *)chr == 45 )
          {
            pFloatStr[v22] = 45;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return;
f_incwidth2:
            v33 = width--;
            if ( v33 != 0 )
            {
              ++charcount;
              *(_DWORD *)chr = inc(a1: v32, fileptr);
            }
            else
            {
              width = 0;
            }
          }
          else if ( *(_DWORD *)chr == 43 )
          {
            goto f_incwidth2;
          }
          for ( k = (unsigned __int8)chr[0]; isdigit(c: k) != 0; k = (unsigned __int8)chr[0] )
          {
            v35 = width--;
            if ( v35 == 0 )
              break;
            ++started;
            pFloatStr[v22] = chr[0];
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return;
            ++charcount;
            *(_DWORD *)chr = inc(a1: v36, fileptr);
          }
        }
      }
      --charcount;
      if ( *(_DWORD *)chr != -1 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      if ( started != 0 )
      {
        if ( suppress == 0 )
        {
          ++count;
          v64 = pFloatStr;
          v63 = pointer;
          pFloatStr[v22] = 0;
          v62 = (char)last - 1;
          v37 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))DecodePointer(Ptr: Ptr);
          v37(a1: v62, a2: v63, a3: v64, a4: &_loc_update);
        }
        goto LABEL_262;
      }
      goto error_return;
    }
    if ( v17 != 105 )
    {
      if ( v17 == 110 )
      {
        v20 = charcount;
        if ( suppress == 0 )
        {
assign_num:
          if ( integer64 != 0 )
          {
            *(_QWORD *)v15 = num64;
          }
          else if ( last != 0 )
          {
            *(_DWORD *)v15 = v20;
          }
          else
          {
            *v15 = v20;
          }
        }
        goto LABEL_262;
      }
LABEL_153:
      if ( *v9 == *(_DWORD *)chr )
      {
        --match;
        if ( suppress == 0 )
          v78 = arglistsave;
        goto LABEL_262;
      }
LABEL_274:
      v61 = *(_DWORD *)chr == -1;
LABEL_278:
      if ( !v61 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      goto error_return;
    }
    comchr = 100;
LABEL_84:
    v21 = *(_DWORD *)chr;
    if ( *(_DWORD *)chr == 45 )
    {
      negative = 1;
      goto x_incwidth;
    }
    if ( *(_DWORD *)chr == 43 )
    {
x_incwidth:
      if ( --width != 0 || widthset == 0 )
      {
        ++charcount;
        v21 = inc(a1: widthset, fileptr);
        *(_DWORD *)chr = v21;
      }
      else
      {
        done_flag = 1;
      }
    }
    if ( v21 == 48 )
    {
      ++charcount;
      v47 = inc(a1: v19, fileptr);
      v21 = v47;
      *(_DWORD *)chr = v47;
      if ( (_BYTE)v47 != 120 && (_BYTE)v47 != 88 )
      {
        started = 1;
        if ( comchr != 120 )
        {
          if ( widthset != 0 && --width == 0 )
            ++done_flag;
          comchr = 111;
          goto getnum;
        }
        --charcount;
        if ( v47 != -1 )
          _ungetc_nolock(ch: v47, str: fileptr);
        v21 = 48;
LABEL_216:
        *(_DWORD *)chr = v21;
        goto getnum;
      }
      ++charcount;
      v21 = inc(a1: v48, fileptr);
      *(_DWORD *)chr = v21;
      if ( widthset != 0 )
      {
        width -= 2;
        if ( width < 1 )
          ++done_flag;
      }
      comchr = 120;
    }
getnum:
    if ( integer64 == 0 )
    {
      v20 = number;
      if ( done_flag == 0 )
      {
        while ( 1 )
        {
          if ( comchr == 120 || comchr == 112 )
          {
            if ( isxdigit(c: (unsigned __int8)v21) == 0 )
            {
LABEL_248:
              --charcount;
              if ( v21 != -1 )
                _ungetc_nolock(ch: v21, str: fileptr);
              break;
            }
            v56 = 16 * v20;
            v21 = hextodec(chr: v21);
            v55 = v73;
            *(_DWORD *)chr = v21;
          }
          else
          {
            v54 = isdigit(c: (unsigned __int8)v21);
            v55 = v72;
            if ( v54 == 0 )
              goto LABEL_248;
            if ( comchr == 111 )
            {
              if ( v21 >= 56 )
                goto LABEL_248;
              v56 = 8 * v20;
            }
            else
            {
              v56 = 10 * v20;
            }
          }
          ++started;
          v20 = v56 + v21 - 48;
          if ( widthset != 0 && --width == 0 )
            break;
          ++charcount;
          v21 = inc(a1: v55, fileptr);
          *(_DWORD *)chr = v21;
        }
      }
      if ( negative != 0 )
        v20 = -v20;
      goto LABEL_252;
    }
    if ( done_flag != 0 )
      goto LABEL_233;
    while ( 2 )
    {
      if ( comchr != 120 && comchr != 112 )
      {
        v49 = isdigit(c: (unsigned __int8)v21);
        v50 = v70;
        if ( v49 == 0 )
          break;
        if ( comchr == 111 )
        {
          if ( v21 >= 56 )
            break;
          v51 = 8 * num64;
        }
        else
        {
          v51 = 10 * num64;
        }
        goto LABEL_228;
      }
      if ( isxdigit(c: (unsigned __int8)v21) != 0 )
      {
        v52 = num64 >> 28;
        v53 = 16 * num64;
        v21 = hextodec(chr: v21);
        v50 = v71;
        *(_DWORD *)chr = v21;
        v51 = __PAIR64__(v52, v53);
LABEL_228:
        ++started;
        num64 = v21 - 48 + v51;
        if ( widthset != 0 && --width == 0 )
          goto LABEL_233;
        ++charcount;
        v21 = inc(a1: v50, fileptr);
        *(_DWORD *)chr = v21;
        continue;
      }
      break;
    }
    --charcount;
    if ( v21 != -1 )
      _ungetc_nolock(ch: v21, str: fileptr);
LABEL_233:
    v20 = number;
    if ( negative != 0 )
      num64 = -(__int64)num64;
LABEL_252:
    if ( comchr == 70 )
      started = 0;
    if ( started == 0 )
      goto error_return;
    if ( suppress == 0 )
    {
      ++count;
      v15 = pointer;
      goto assign_num;
    }
LABEL_262:
    ++match;
    v9 = ++v88;
LABEL_268:
    if ( *(_DWORD *)chr != -1 )
    {
LABEL_272:
      v8 = *v9;
      if ( *v9 == 0 )
        goto error_return;
      continue;
    }
    break;
  }
  if ( *v9 == 37 && v88[1] == 110 )
  {
    v9 = v88;
    goto LABEL_272;
  }
error_return:
  if ( malloc_FloatStrFlag == 1 )
    free(pMem: pFloatStr);
  if ( *(_DWORD *)chr == -1 )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
LABEL_288:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x10029ACB
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
// Address: 0x10029AE6
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029B11
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x10029B29
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10029B32
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10029B3B
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  void *v0; // esi

  v0 = (void *)_encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks(enull: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10029B6E
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
// Address: 0x10029B92
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

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
// Address: 0x10029C29
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  PVOID *v3; // ebx
  PVOID *v4; // edi
  void (*v5)(void); // ebx
  void (__cdecl **v6)(); // ebx
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-30h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-28h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-24h]
  void (**j)(void); // [esp+20h] [ebp-20h]
  void (**i)(void); // [esp+24h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      v3 = (PVOID *)DecodePointer(Ptr: __onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 != nullptr )
      {
        v4 = (PVOID *)DecodePointer(Ptr: __onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != (PVOID)_encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))DecodePointer(Ptr: *v4);
            *v4 = (PVOID)_encoded_null();
            v5();
            v6 = (void (__cdecl **)())DecodePointer(Ptr: __onexitbegin);
            v7 = (void (__cdecl **)())DecodePointer(Ptr: __onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (PVOID *)v7;
            }
            v3 = (PVOID *)onexitbegin;
          }
        }
      }
      for ( i = __xp_a; i < __xp_z; ++i )
      {
        if ( *i != nullptr )
          (*i)();
      }
    }
    for ( j = __xt_a; j < __xt_z; ++j )
    {
      if ( *j != nullptr )
        (*j)();
    }
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
// Address: 0x10029D69
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10029D7F
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10029D8E
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _amsg_exit(int rterrnum)
{
  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  _exit(code: 255);
}

//------------------------------------------------------------------------------
// Address: 0x10029DAC
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
    if ( _mbsnbicoll(s1: (const unsigned __int8 *)name, s2: *i, n: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_environ) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x10029DFE
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall copy_environ@<eax>(char **oldenviron@<eax>)
{
  char **result; // eax
  char **v3; // ecx
  unsigned __int8 *v4; // esi
  char *v5; // eax
  int v6; // edi
  char **newenviron; // [esp+4h] [ebp-4h]

  result = nullptr;
  v3 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v3;
        result = (char **)((char *)result + 1);
      }
      while ( *v3 != nullptr );
    }
    v4 = calloc(count: (unsigned int)result + 1, size: 4u);
    newenviron = (char **)v4;
    if ( v4 == nullptr )
      _amsg_exit(rterrnum: 9);
    v5 = *oldenviron;
    if ( *oldenviron != nullptr )
    {
      v6 = (char *)oldenviron - (char *)v4;
      do
      {
        *(_DWORD *)v4 = _strdup(string: v5);
        v4 += 4;
        v5 = *(char **)&v4[v6];
      }
      while ( v5 != nullptr );
    }
    *(_DWORD *)v4 = 0;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029E5E
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtsetenv(char **poption, int primary)
{
  const unsigned __int8 *v3; // esi
  const unsigned __int8 *v4; // eax
  const unsigned __int8 *v5; // edi
  char **v6; // eax
  char **v7; // eax
  unsigned __int16 **v8; // eax
  char **v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  char **v12; // esi
  unsigned __int8 *v13; // eax
  char **v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // edi
  int v17; // eax
  const char *v18; // eax
  const char *equal; // [esp+4h] [ebp-14h]
  char **env; // [esp+8h] [ebp-10h]
  int retval; // [esp+Ch] [ebp-Ch]
  BOOL remove; // [esp+10h] [ebp-8h]
  char *option; // [esp+14h] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = (const unsigned __int8 *)*poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_12;
  v4 = _mbschr(string: v3, c: 0x3Du);
  v5 = v4;
  equal = (const char *)v4;
  if ( v4 == nullptr || v3 == v4 )
    goto LABEL_12;
  remove = v4[1] == 0;
  v6 = _environ;
  if ( _environ == __initenv )
  {
    v6 = copy_environ(oldenviron: _environ);
    _environ = v6;
  }
  if ( v6 == nullptr )
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
      if ( remove )
        return 0;
      v7 = (char **)operator new(nSize: 4u);
      _environ = v7;
      if ( v7 == nullptr )
        return -1;
      *v7 = nullptr;
      if ( _wenviron == nullptr )
      {
        v8 = (unsigned __int16 **)operator new(nSize: 4u);
        _wenviron = v8;
        if ( v8 == nullptr )
          return -1;
        *v8 = nullptr;
      }
    }
  }
  v9 = _environ;
  env = _environ;
  if ( _environ == nullptr )
    return -1;
  v10 = findenv(len: v5 - (const unsigned __int8 *)option, name: option);
  v11 = v10;
  if ( v10 < 0 || *v9 == nullptr )
  {
    if ( !remove )
    {
      if ( v10 < 0 )
        v11 = -v10;
      if ( (int)(v11 + 2) <= (int)v11 )
        return -1;
      if ( v11 + 2 >= 0x3FFFFFFF )
        return -1;
      v13 = _recalloc_crt(ptr: _environ, count: 4u, size: v11 + 2);
      if ( v13 == nullptr )
        return -1;
      v14 = (char **)&v13[4 * v11];
      *v14 = option;
      v14[1] = nullptr;
      *poption = nullptr;
      goto LABEL_37;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v12 = &v9[v10];
  free(pMem: *v12);
  if ( !remove )
  {
    *v12 = option;
    *poption = nullptr;
    goto LABEL_38;
  }
  while ( *v12 != nullptr )
  {
    *v12 = v12[1];
    v12 = &env[++v11];
  }
  if ( v11 < 0x3FFFFFFF )
  {
    v13 = _recalloc_crt(ptr: _environ, count: v11, size: 4u);
    if ( v13 == nullptr )
      goto LABEL_38;
LABEL_37:
    _environ = (char **)v13;
  }
LABEL_38:
  if ( primary != 0 )
  {
    strlen(buf: option);
    v16 = calloc(count: v15 + 2, size: 1u);
    if ( v16 != nullptr )
    {
      strlen(buf: option);
      if ( strcpy_s(_Dst: (char *)v16, _SizeInBytes: v17 + 2, _Src: option) != 0 )
        _invoke_watson(a1: (unsigned int)v16);
      v18 = &equal[v16 - (unsigned __int8 *)option];
      *v18 = 0;
      if ( !SetEnvironmentVariableA(lpName: (LPCSTR)v16, lpValue: !remove ? v18 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pMem: v16);
    }
  }
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1002A0A0
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  const char *v6; // eax
  char v7; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInBytes;
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
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    v6[_Dst - _Src] = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A0FF
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
// Address: 0x1002A11C
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr_l(char *string, unsigned int c, localeinfo_struct *plocinfo)
{
  char *v3; // eax
  unsigned __int16 v4; // cx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = string;
  if ( string != nullptr )
  {
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      while ( 1 )
      {
        v4 = (unsigned __int8)*v3;
        if ( *v3 == 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v4 + 1] & 4) != 0 )
        {
          if ( *++v3 == 0 )
            goto LABEL_17;
          if ( c == ((unsigned __int8)*v3 | (v4 << 8)) )
            goto LABEL_15;
        }
        else if ( c == (unsigned __int8)*v3 )
        {
          break;
        }
        ++v3;
      }
      if ( c == (unsigned __int8)*v3 )
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
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A1CC
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbschr(char *string, unsigned int c)
{
  _mbschr_l(string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002A1E3
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi
  LPCRITICAL_SECTION *v2; // eax

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      v2 = &locktable + 2 * v0;
      *v2 = v1++;
      if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: *v2, dwSpinCount: 0xFA0u) )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A22D
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
  while ( (int)v0 < (int)&__security_cookie );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)&__security_cookie );
}

//------------------------------------------------------------------------------
// Address: 0x1002A284
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x1002A29B
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi
  _RTL_CRITICAL_SECTION *v3; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  v1 = &locktable + 2 * locknum;
  if ( *v1 != nullptr )
    return 1;
  v3 = (_RTL_CRITICAL_SECTION *)operator new(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    _lock(locknum: 10);
    if ( *v1 != nullptr )
    {
      free(pMem: v3);
    }
    else if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: v3, dwSpinCount: 0xFA0u) )
    {
      *v1 = v3;
    }
    else
    {
      free(pMem: v3);
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
// Address: 0x1002A35D
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi

  v1 = &locktable + 2 * locknum;
  if ( *v1 == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *v1);
}

//------------------------------------------------------------------------------
// Address: 0x1002A3D5
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x1002A57F
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(uintptr_t StackCookie)
{
  if ( StackCookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x1002A58E
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _getdrive()
{
  wchar_t *v0; // ebx
  signed int CurrentDirectoryW; // esi
  unsigned __int8 *v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  int memfree; // [esp+10h] [ebp-214h]
  wchar_t curdirstr[262]; // [esp+14h] [ebp-210h] BYREF

  memfree = 0;
  v0 = curdirstr;
  CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryW > 260 )
  {
    v2 = calloc(count: CurrentDirectoryW + 1, size: 2u);
    v0 = (wchar_t *)v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: CurrentDirectoryW + 1, lpBuffer: (LPWSTR)v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryW = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryW != 0 )
  {
    if ( v0[1] == 58 )
    {
      v4 = *v0;
      if ( v4 >= 0x61 && v4 <= 0x7A )
        v4 -= 32;
      v3 = v4 - 64;
    }
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
// Address: 0x1002A65C
// Name: __mbsnbicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicoll_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  int v5; // eax
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
      _invalid_parameter_noinfo();
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      v5 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: _loc_update.localeinfo.mbcinfo->mblcid,
             dwCmpFlags: 0x1001u,
             lpString1: (const char *)s1,
             cchCount1: n,
             lpString2: (const char *)s2,
             cchCount2: n,
             code_page: _loc_update.localeinfo.mbcinfo->mbcodepage);
      if ( v5 == 0 )
        goto LABEL_15;
      result = v5 - 2;
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
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002A73A
// Name: __mbsnbicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicoll(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbicoll_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002A754
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const WCHAR *v1; // eax
  unsigned int v2; // eax
  unsigned __int8 *v3; // eax
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
    v3 = calloc(count: v2, size: 1u);
    envp = (char *)v3;
    if ( v3 == nullptr )
      break;
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: *v0,
           cchWideChar: -1,
           lpMultiByteStr: (LPSTR)v3,
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
// Address: 0x1002A7EB
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _VEC_memcpy@<eax>(unsigned int a1@<ecx>, __m128i *a2@<edi>, const __m128i *a3@<esi>)
{
  int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int k; // edx
  __m128i si128; // xmm1
  __m128i v8; // xmm2
  __m128i v9; // xmm3
  __m128i v10; // xmm5
  __m128i v11; // xmm6
  __m128i v12; // xmm7
  unsigned int m; // edx
  unsigned int v14; // ecx
  char v15; // al
  unsigned int n; // ecx
  int ii; // ecx
  unsigned int v19; // eax
  int i; // ecx
  unsigned int j; // eax
  unsigned int v22; // [esp-10h] [ebp-14h]
  int v23; // [esp-Ch] [ebp-10h]

  v3 = (unsigned __int8)a3 & 0xF;
  if ( ((unsigned __int8)a3 & 0xF) != 0 )
  {
    v22 = a1 - (16 - v3);
    v19 = 16 - v3;
    for ( i = v19 & 3; i != 0; --i )
    {
      a2->m128i_i8[0] = a3->m128i_i8[0];
      a3 = (const __m128i *)((char *)a3 + 1);
      a2 = (__m128i *)((char *)a2 + 1);
    }
    for ( j = v19 >> 2; j != 0; --j )
    {
      a2->m128i_i32[0] = a3->m128i_i32[0];
      a3 = (const __m128i *)((char *)a3 + 4);
      a2 = (__m128i *)((char *)a2 + 4);
    }
    a1 = v22;
  }
  v4 = a1;
  v5 = a1 & 0x7F;
  for ( k = v4 >> 7; k != 0; --k )
  {
    si128 = _mm_load_si128(a3 + 1);
    v8 = _mm_load_si128(a3 + 2);
    v9 = _mm_load_si128(a3 + 3);
    *a2 = _mm_load_si128(a3);
    a2[1] = si128;
    a2[2] = v8;
    a2[3] = v9;
    v10 = _mm_load_si128(a3 + 5);
    v11 = _mm_load_si128(a3 + 6);
    v12 = _mm_load_si128(a3 + 7);
    a2[4] = _mm_load_si128(a3 + 4);
    a2[5] = v10;
    a2[6] = v11;
    a2[7] = v12;
    a3 += 8;
    a2 += 8;
  }
  if ( v5 != 0 )
  {
    for ( m = v5 >> 4; m != 0; --m )
      *a2++ = _mm_load_si128(a3++);
    v14 = v5 & 0xF;
    if ( v14 != 0 )
    {
      v15 = v14;
      for ( n = v14 >> 2; n != 0; --n )
      {
        a2->m128i_i32[0] = a3->m128i_i32[0];
        a3 = (const __m128i *)((char *)a3 + 4);
        a2 = (__m128i *)((char *)a2 + 4);
      }
      for ( ii = v15 & 3; ii != 0; --ii )
      {
        a2->m128i_i8[0] = a3->m128i_i8[0];
        a3 = (const __m128i *)((char *)a3 + 1);
        a2 = (__m128i *)((char *)a2 + 1);
      }
    }
  }
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x1002A8EE
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __sse2_available_init()
{
  __sse2_available = IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A8FE
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  unsigned int v5; // eax
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
  v5 = v2->_flag & 0xFFFFFFED | 2;
  v2->_flag = v5;
  v2->_cnt = 0;
  written = 0;
  if ( (v5 & 0x10C) == 0 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
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
// Address: 0x1002AA62
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
// Address: 0x1002AA95
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
// Address: 0x1002AAE2
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  int *v4; // ebx
  const char *v5; // edi
  int v7; // eax
  ioinfo *v8; // ecx
  ioinfo *v9; // eax
  char v10; // dl
  STATE v11; // ecx
  char *v12; // edi
  int v13; // eax
  char v14; // al
  bool v15; // zf
  int v16; // eax
  _output_l::__l2::<unnamed_type_buffer> *p_buffer; // edi
  int v18; // ecx
  _output_l::__l2::<unnamed_type_text> v19; // ebx
  char *sz; // eax
  char *v21; // ebx
  __int16 *v22; // eax
  _output_l::__l2::<unnamed_type_text> v23; // ecx
  signed int v24; // eax
  _WORD *v25; // esi
  __int64 v26; // rax
  int *v27; // ebx
  int v28; // esi
  char *v29; // eax
  int v30; // eax
  char *v31; // ebx
  void (__cdecl *v32)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v33; // ebx
  void (__cdecl *v34)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v35)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v36; // ebx
  unsigned int v37; // edi
  char *j; // esi
  int v39; // eax
  unsigned __int64 v40; // rcx
  int v41; // ecx
  char *v42; // eax
  _BYTE *v43; // esi
  _BYTE *i; // eax
  int v45; // eax
  int v46; // ebx
  int v47; // edi
  _iobuf *v48; // edi
  int v49; // eax
  int v50; // ebx
  wchar_t *v51; // esi
  int v52; // eax
  int v53; // ebx
  char v54; // al
  int v55; // [esp-14h] [ebp-298h]
  int v56; // [esp-10h] [ebp-294h]
  unsigned __int64 v57; // [esp-10h] [ebp-294h]
  int v58; // [esp-Ch] [ebp-290h]
  int v59; // [esp-8h] [ebp-28Ch]
  wchar_t v60; // [esp-4h] [ebp-288h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-278h] BYREF
  int capexp; // [esp+14h] [ebp-270h]
  STATE state; // [esp+18h] [ebp-26Ch]
  int padding; // [esp+20h] [ebp-264h]
  int retval; // [esp+24h] [ebp-260h] BYREF
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-25Ch] BYREF
  char *heapbuf; // [esp+38h] [ebp-24Ch]
  int hexadd; // [esp+3Ch] [ebp-248h]
  int no_output; // [esp+40h] [ebp-244h]
  _iobuf *f; // [esp+44h] [ebp-240h]
  char *v71; // [esp+48h] [ebp-23Ch]
  int bufferiswide; // [esp+4Ch] [ebp-238h]
  int fldwidth; // [esp+50h] [ebp-234h]
  int prefixlen; // [esp+54h] [ebp-230h]
  char prefix[4]; // [esp+58h] [ebp-22Ch] BYREF
  char *v76; // [esp+5Ch] [ebp-228h]
  int charsout; // [esp+60h] [ebp-224h] BYREF
  int radix; // [esp+64h] [ebp-220h] BYREF
  _output_l::__l2::<unnamed_type_text> text; // [esp+68h] [ebp-21Ch]
  int precision; // [esp+6Ch] [ebp-218h]
  char v81; // [esp+73h] [ebp-211h]
  int flags; // [esp+74h] [ebp-210h]
  _output_l::__l2::<unnamed_type_buffer> buffer; // [esp+78h] [ebp-20Ch] BYREF
  char L_buffer[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = (int *)argptr;
  v5 = format;
  f = stream;
  v76 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( stream != nullptr
    && ((stream->_flag & 0x40) != 0
     || ((v7 = _fileno(stream)) == -1 || v7 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v7 >> 5][v7 & 0x1F]),
         (*((_BYTE *)v8 + 36) & 0x7F) == 0
      && (v7 == -1 || v7 == -2 ? (v9 = &__badioinfo) : (v9 = &__pioinfo[v7 >> 5][v7 & 0x1F]), *((char *)v9 + 36) >= 0)))
    && format != nullptr )
  {
    v10 = *format;
    v11 = ST_NORMAL;
    charsout = 0;
    radix = 0;
    heapbuf = nullptr;
    v81 = v10;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v12 = (char *)(v5 + 1);
        v71 = v12;
        if ( charsout < 0 )
          break;
        if ( (unsigned __int8)(v10 - 32) > 0x58u )
          v13 = 0;
        else
          v13 = aCmd[v10] & 0xF;
        state = __lookuptable[8 * v13 + v11] >> 4;
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
            goto LABEL_224;
          case ST_FLAG:
            switch ( v10 )
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
            goto LABEL_224;
          case ST_WIDTH:
            if ( v10 == 42 )
            {
              v76 = (char *)(v4 + 1);
              fldwidth = *v4;
              if ( fldwidth < 0 )
              {
                flags |= 4u;
                fldwidth = -fldwidth;
              }
            }
            else
            {
              fldwidth = 10 * fldwidth + v10 - 48;
            }
            goto LABEL_224;
          case ST_DOT:
            precision = 0;
            goto LABEL_224;
          case ST_PRECIS:
            if ( v10 == 42 )
            {
              v76 = (char *)(v4 + 1);
              precision = *v4;
              if ( precision < 0 )
                precision = -1;
            }
            else
            {
              precision = 10 * precision + v10 - 48;
            }
            goto LABEL_224;
          case ST_SIZE:
            switch ( v10 )
            {
              case 'I':
                v14 = *v12;
                if ( *v12 == 54 && v12[1] == 52 )
                {
                  flags |= 0x8000u;
                  v71 = v12 + 2;
                }
                else if ( v14 == 51 && v12[1] == 50 )
                {
                  flags &= ~0x8000u;
                  v71 = v12 + 2;
                }
                else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
                {
                  state = ST_NORMAL;
NORMAL_STATE:
                  bufferiswide = 0;
                  v16 = _isleadbyte_l(c: v10, plocinfo: &_loc_update.localeinfo);
                  v15 = v16 == 0;
                  LOBYTE(v16) = v81;
                  if ( !v15 )
                  {
                    write_char(ch: v16, f, pnumwritten: &charsout);
                    LOBYTE(v16) = *v12;
                    v71 = v12 + 1;
                    if ( (_BYTE)v16 == 0 )
                      goto LABEL_2;
                  }
                  write_char(ch: v16, f, pnumwritten: &charsout);
                }
                break;
              case 'h':
                flags |= 0x20u;
                break;
              case 'l':
                if ( *v12 == 108 )
                {
                  flags |= 0x1000u;
                  v71 = v12 + 1;
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
            goto LABEL_224;
          case ST_TYPE:
            if ( v10 <= 100 )
            {
              if ( v10 == 100 )
              {
LABEL_118:
                flags |= 0x40u;
                goto LABEL_119;
              }
              if ( v10 > 83 )
              {
                if ( v10 == 88 )
                  goto LABEL_140;
                if ( v10 == 90 )
                {
                  v22 = (__int16 *)*v4;
                  v76 = (char *)(v4 + 1);
                  if ( v22 != nullptr && (v23.sz = *(char **)(v22 + 2), v23.sz != nullptr) )
                  {
                    v24 = *v22;
                    text.sz = v23.sz;
                    if ( (flags & 0x800) != 0 )
                    {
                      v24 /= 2;
                      bufferiswide = 1;
                    }
                    else
                    {
                      bufferiswide = 0;
                    }
                  }
                  else
                  {
                    text.sz = __nullstring;
                    strlen(buf: __nullstring);
                  }
                  goto LABEL_189;
                }
                if ( v10 != 97 )
                {
                  if ( v10 != 99 )
                    goto LABEL_190;
                  goto LABEL_93;
                }
              }
              else
              {
                if ( v10 == 83 )
                {
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
                  goto LABEL_83;
                }
                if ( v10 != 65 )
                {
                  if ( v10 != 67 )
                  {
                    if ( v10 != 69 && v10 != 71 )
                      goto LABEL_190;
                    goto LABEL_76;
                  }
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
LABEL_93:
                  v21 = (char *)(v4 + 1);
                  v76 = v21;
                  if ( (flags & 0x810) != 0 )
                  {
                    if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v21 - 2)) != 0 )
                      no_output = 1;
                  }
                  else
                  {
                    buffer.sz[0] = *(v21 - 4);
                    radix = 1;
                  }
                  text.sz = (char *)&buffer;
                  goto LABEL_190;
                }
LABEL_76:
                v10 += 32;
                capexp = 1;
                v81 = v10;
              }
LABEL_77:
              flags |= 0x40u;
              p_buffer = &buffer;
              text.sz = (char *)&buffer;
              padding = 512;
              if ( precision >= 0 )
              {
                if ( precision != 0 )
                {
                  if ( precision > 512 )
                    precision = 512;
                  if ( precision > 163 )
                  {
                    v28 = precision + 349;
                    v29 = (char *)operator new(nSize: precision + 349);
                    v10 = v81;
                    heapbuf = v29;
                    if ( v29 != nullptr )
                    {
                      text.sz = v29;
                      padding = v28;
                      p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)v29;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = v10 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v30 = *v4;
              v31 = (char *)(v4 + 2);
              LODWORD(tmp.x) = v30;
              HIDWORD(tmp.x) = *((_DWORD *)v31 - 1);
              v59 = capexp;
              v58 = precision;
              v76 = v31;
              v56 = v10;
              v55 = padding;
              v32 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))DecodePointer(Ptr: off_1004F48C);
              v32(a1: &tmp, a2: p_buffer, a3: v55, a4: v56, a5: v58, a6: v59, a7: &_loc_update);
              v33 = flags & 0x80;
              if ( (flags & 0x80) != 0 && precision == 0 )
              {
                v34 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_1004F498);
                v34(a1: p_buffer, a2: &_loc_update);
              }
              if ( v81 == 103 && v33 == 0 )
              {
                v35 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_1004F494);
                v35(a1: p_buffer, a2: &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen(buf: p_buffer->sz);
              goto LABEL_189;
            }
            if ( v10 > 112 )
            {
              if ( v10 != 115 )
              {
                if ( v10 != 117 )
                {
                  if ( v10 != 120 )
                    goto LABEL_190;
                  hexadd = 39;
                  goto COMMON_HEX;
                }
LABEL_119:
                radix = 10;
                goto COMMON_INT;
              }
LABEL_83:
              v18 = precision;
              if ( precision == -1 )
                v18 = 0x7FFFFFFF;
              v76 = (char *)(v4 + 1);
              v19.sz = (char *)*v4;
              text.sz = v19.sz;
              if ( (flags & 0x810) != 0 )
              {
                if ( v19.sz == nullptr )
                  text.sz = (char *)__wnullstring;
                sz = text.sz;
                bufferiswide = 1;
                while ( v18 != 0 )
                {
                  --v18;
                  if ( *(_WORD *)sz == 0 )
                    break;
                  sz += 2;
                }
                v24 = (sz - text.sz) >> 1;
              }
              else
              {
                if ( v19.sz == nullptr )
                  text.sz = __nullstring;
                for ( i = text.sz; v18 != 0; ++i )
                {
                  --v18;
                  if ( *i == 0 )
                    break;
                }
                v24 = i - text.sz;
              }
LABEL_189:
              radix = v24;
              goto LABEL_190;
            }
            if ( v10 == 112 )
            {
              precision = 8;
LABEL_140:
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
            if ( v10 < 101 )
              goto LABEL_190;
            if ( v10 <= 103 )
              goto LABEL_77;
            if ( v10 == 105 )
              goto LABEL_118;
            if ( v10 != 110 )
            {
              if ( v10 != 111 )
                goto LABEL_190;
              radix = 8;
              if ( (flags & 0x80u) != 0 )
                flags |= 0x200u;
COMMON_INT:
              if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
              {
                v26 = *(_QWORD *)v4;
                v27 = v4 + 2;
              }
              else
              {
                v27 = v4 + 1;
                if ( (flags & 0x20) != 0 )
                {
                  v76 = (char *)v27;
                  if ( (flags & 0x40) != 0 )
                    LODWORD(v26) = *((__int16 *)v27 - 2);
                  else
                    LODWORD(v26) = *((unsigned __int16 *)v27 - 2);
                  v26 = (int)v26;
LABEL_157:
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
                    v57 = __PAIR64__(v36, v37);
                    v40 = __PAIR64__(v36, v37) % radix;
                    v41 = v40 + 48;
                    padding = HIDWORD(v40);
                    v36 = (v57 / radix) >> 32;
                    v37 = v57 / radix;
                    if ( v41 > 57 )
                      LOBYTE(v41) = hexadd + v41;
                    *j = v41;
                  }
                  v42 = (char *)(&buffer.sz[511] - j);
                  v43 = j + 1;
                  radix = (int)v42;
                  text.sz = v43;
                  if ( (flags & 0x200) != 0 && (v42 == nullptr || *v43 != 48) )
                  {
                    *--text.sz = 48;
                    v24 = (signed int)(v42 + 1);
                    goto LABEL_189;
                  }
LABEL_190:
                  if ( no_output != 0 )
                    goto LABEL_222;
                  v45 = flags;
                  if ( (flags & 0x40) != 0 )
                  {
                    if ( (flags & 0x100) != 0 )
                    {
                      prefix[0] = 45;
                      goto LABEL_198;
                    }
                    if ( (flags & 1) != 0 )
                    {
                      prefix[0] = 43;
                      goto LABEL_198;
                    }
                    if ( (flags & 2) != 0 )
                    {
                      prefix[0] = 32;
LABEL_198:
                      prefixlen = 1;
                    }
                  }
                  v46 = fldwidth - radix - prefixlen;
                  padding = v46;
                  if ( (flags & 0xC) == 0 )
                  {
                    v47 = fldwidth - radix - prefixlen;
                    if ( v46 > 0 )
                    {
                      do
                      {
                        LOBYTE(v45) = 32;
                        --v47;
                        write_char(ch: v45, f, pnumwritten: &charsout);
                      }
                      while ( charsout != -1 && v47 > 0 );
                    }
                  }
                  v48 = f;
                  write_string(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
                  if ( (flags & 8) != 0 && (flags & 4) == 0 )
                  {
                    do
                    {
                      if ( v46 <= 0 )
                        break;
                      LOBYTE(v49) = 48;
                      --v46;
                      write_char(ch: v49, f: v48, pnumwritten: &charsout);
                    }
                    while ( charsout != -1 );
                  }
                  v50 = radix;
                  if ( bufferiswide != 0 && radix > 0 )
                  {
                    v51 = (wchar_t *)text.sz;
                    while ( 1 )
                    {
                      v60 = *v51;
                      --v50;
                      ++v51;
                      v52 = wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v60);
                      if ( v52 != 0 || retval == 0 )
                        break;
                      write_string(string: L_buffer, f: v48, pnumwritten: &charsout, len: retval);
                      if ( v50 == 0 )
                        goto LABEL_217;
                    }
                    charsout = -1;
                  }
                  else
                  {
                    write_string(string: text.sz, f: v48, pnumwritten: &charsout, len: radix);
                  }
LABEL_217:
                  if ( charsout >= 0 && (flags & 4) != 0 )
                  {
                    v53 = padding;
                    do
                    {
                      if ( v53 <= 0 )
                        break;
                      LOBYTE(v52) = 32;
                      --v53;
                      write_char(ch: v52, f: v48, pnumwritten: &charsout);
                    }
                    while ( charsout != -1 );
                  }
                  goto LABEL_222;
                }
                LODWORD(v26) = *(v27 - 1);
                if ( (flags & 0x40) != 0 )
                  v26 = (int)v26;
                else
                  HIDWORD(v26) = 0;
              }
              v76 = (char *)v27;
              goto LABEL_157;
            }
            v25 = (_WORD *)*v4;
            v76 = (char *)(v4 + 1);
            if ( _get_printf_count_output() == 0 )
              goto LABEL_2;
            if ( (flags & 0x20) != 0 )
              *v25 = charsout;
            else
              *(_DWORD *)v25 = charsout;
            no_output = 1;
LABEL_222:
            if ( heapbuf != nullptr )
            {
              free(pMem: heapbuf);
              heapbuf = nullptr;
            }
LABEL_224:
            v5 = v71;
            v54 = *v71;
            v81 = v54;
            if ( v54 == 0 )
              goto LABEL_226;
            v11 = state;
            v4 = (int *)v76;
            v10 = v54;
            break;
          default:
            goto LABEL_224;
        }
      }
    }
LABEL_226:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B68E
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
// Address: 0x1002B72A
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close(int fh)
{
  ioinfo **v2; // edi
  int v3; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = &__pioinfo[fh >> 5], v3 = (fh & 0x1F) << 6, (*(&(*v2)->osfile + v3) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
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
// Address: 0x1002B7EE
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fileno(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B814
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
// Address: 0x1002B845
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
      v5 = _fileno(stream: str);
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
// Address: 0x1002B8AD
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = _fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002B8F5
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  void **v2; // eax
  _BYTE *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v4 & 2) != 0 && _fflush_nolock(str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: __piob[i]);
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
// Address: 0x1002B9CF
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002B9D8
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x1002B9DE
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
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)_lookuptrailbytes )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_1004F760;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_1004F7C0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002BA8F
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
// Address: 0x1002BAAF
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_1004F9B0 )
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
// Address: 0x1002BAF0
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
// Address: 0x1002BB22
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_1004F9B0 )
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
// Address: 0x1002BB5E
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
// Address: 0x1002BB8D
// Name: __filbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _filbuf(_iobuf *str)
{
  int flag; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-Ch]
  unsigned int bufsiz; // [esp-4h] [ebp-8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return -1;
  }
  v2 = flag | 1;
  str->_flag = v2;
  if ( (v2 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v3 = _fileno(stream: str);
  v4 = _read(fh: v3, buf: base, cnt: bufsiz);
  str->_cnt = v4;
  if ( v4 == 0 || v4 == -1 )
  {
    str->_flag |= v4 != 0 ? 32 : 16;
    str->_cnt = 0;
    return -1;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( _fileno(stream: str) == -1 || _fileno(stream: str) == -2 )
    {
      v6 = &__badioinfo;
    }
    else
    {
      v5 = &__pioinfo[_fileno(stream: str) >> 5];
      v6 = &(*v5)[_fileno(stream: str) & 0x1F];
    }
    if ( (v6->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v7 = str->_flag;
    if ( (v7 & 8) != 0 && (v7 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  --str->_cnt;
  result = (unsigned __int8)*ptr;
  str->_ptr = ptr + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002BCAF
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _read_nolock(int fh, char *inputbuf, unsigned int cnt)
{
  unsigned int v3; // edx
  int result; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // esi
  char v8; // cl
  char *v9; // ebx
  char *v10; // ecx
  char *v11; // eax
  char v12; // cl
  bool v13; // zf
  ioinfo *v14; // ecx
  char v15; // cl
  ioinfo *v16; // ecx
  char v17; // cl
  ioinfo *v18; // ecx
  ioinfo *v19; // eax
  char *v20; // eax
  char *v21; // ebx
  char v22; // al
  char *v23; // eax
  char *v24; // ebx
  int v25; // ecx
  int v26; // eax
  char v27; // dl
  char *v28; // ebx
  int v29; // ebx
  DWORD LastError; // eax
  ioinfo *v31; // edx
  BOOL v32; // ecx
  char *v33; // ebx
  int v34; // ecx
  char *v35; // esi
  __int16 v36; // [esp-Ch] [ebp-2Ch]
  unsigned int inputsize; // [esp+4h] [ebp-1Ch]
  int os_read; // [esp+8h] [ebp-18h] BYREF
  int retval; // [esp+Ch] [ebp-14h]
  void *buf; // [esp+10h] [ebp-10h]
  int bytes_read; // [esp+14h] [ebp-Ch]
  wchar_t wpeekchr; // [esp+18h] [ebp-8h] BYREF
  char tmode; // [esp+1Eh] [ebp-2h]
  char peekchr; // [esp+1Fh] [ebp-1h] BYREF
  char *p; // [esp+30h] [ebp+10h]
  char *pa; // [esp+30h] [ebp+10h]

  v3 = cnt;
  retval = -2;
  inputsize = cnt;
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
    _invalid_parameter_noinfo();
    return -1;
  }
  v5 = &__pioinfo[fh >> 5];
  v6 = *v5;
  v7 = (fh & 0x1F) << 6;
  v8 = *(&(*v5)->osfile + v7);
  if ( (v8 & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  bytes_read = 0;
  if ( cnt == 0 || (v8 & 2) != 0 )
    return 0;
  if ( inputbuf == nullptr )
    goto LABEL_18;
  tmode = (char)(2 * *((_BYTE *)v6 + v7 + 36)) >> 1;
  if ( tmode != 1 )
  {
    if ( tmode != 2 )
    {
LABEL_16:
      v9 = inputbuf;
      buf = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v3 >> 1 >= 4 )
    cnt = v3 >> 1;
  v9 = (char *)operator new(nSize: cnt);
  buf = v9;
  if ( v9 == nullptr )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  *(_QWORD *)&(*v5)->pipech2[v7 + 3] = _lseeki64_nolock(fh, pos: 0, mthd: 1);
LABEL_26:
  v10 = (char *)*v5 + v7;
  v11 = v9;
  if ( (v10[4] & 0x48) != 0 )
  {
    v12 = v10[5];
    if ( v12 != 10 && cnt != 0 )
    {
      --cnt;
      v13 = tmode == 0;
      *v9 = v12;
      v14 = *v5;
      v11 = v9 + 1;
      bytes_read = 1;
      *(&v14->pipech + v7) = 10;
      if ( !v13 )
      {
        v15 = (*v5)->pipech2[v7];
        if ( v15 != 10 && cnt != 0 )
        {
          *v11 = v15;
          v16 = *v5;
          v11 = v9 + 2;
          --cnt;
          v13 = tmode == 1;
          bytes_read = 2;
          v16->pipech2[v7] = 10;
          if ( v13 )
          {
            v17 = (*v5)->pipech2[v7 + 1];
            if ( v17 != 10 && cnt != 0 )
            {
              *v11 = v17;
              v18 = *v5;
              v11 = v9 + 3;
              --cnt;
              bytes_read = 3;
              v18->pipech2[v7 + 1] = 10;
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(
          hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
          lpBuffer: v11,
          nNumberOfBytesToRead: cnt,
          lpNumberOfBytesRead: (LPDWORD)&os_read,
          lpOverlapped: nullptr)
    || os_read < 0
    || os_read > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      retval = 0;
      goto error_return_0;
    }
    goto LABEL_92;
  }
  v19 = *v5;
  bytes_read += os_read;
  v20 = &v19->osfile + v7;
  if ( *v20 < 0 )
  {
    if ( tmode != 2 )
    {
      if ( os_read != 0 && *v9 == 10 )
        *v20 |= 4u;
      else
        *v20 &= ~4u;
      v21 = (char *)buf;
      p = (char *)buf;
      bytes_read += (int)buf;
      if ( (unsigned int)buf < bytes_read )
      {
        do
        {
          v22 = *p;
          if ( *p == 26 )
          {
            v23 = &(*v5)->osfile + v7;
            if ( (*v23 & 0x40) != 0 )
              *v21++ = *p;
            else
              *v23 |= 2u;
            break;
          }
          if ( v22 == 13 )
          {
            if ( (unsigned int)p < bytes_read - 1 )
            {
              if ( p[1] == 10 )
              {
                p += 2;
                goto LABEL_52;
              }
              ++p;
LABEL_63:
              *v21 = 13;
LABEL_64:
              ++v21;
              continue;
            }
            ++p;
            if ( !ReadFile(
                    hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
                    lpBuffer: &peekchr,
                    nNumberOfBytesToRead: 1u,
                    lpNumberOfBytesRead: (LPDWORD)&os_read,
                    lpOverlapped: nullptr)
              && GetLastError() != 0
              || os_read == 0 )
            {
              goto LABEL_63;
            }
            if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
            {
              if ( peekchr != 10 )
              {
                *v21 = 13;
                *(&(*v5)->pipech + v7) = peekchr;
                goto LABEL_64;
              }
LABEL_52:
              *v21 = 10;
              goto LABEL_64;
            }
            if ( v21 == buf && peekchr == 10 )
              goto LABEL_52;
            _lseeki64_nolock(fh, pos: -1, mthd: 1);
            if ( peekchr != 10 )
              goto LABEL_63;
          }
          else
          {
            *v21++ = v22;
            ++p;
          }
        }
        while ( (unsigned int)p < bytes_read );
      }
      bytes_read = v21 - (_BYTE *)buf;
      if ( tmode != 1 || v21 == buf )
        goto error_return_0;
      v24 = v21 - 1;
      LOBYTE(v25) = *v24;
      if ( *v24 < 0 )
      {
        v26 = 1;
        v25 = (unsigned __int8)v25;
        while ( _lookuptrailbytes[v25] == 0 && v26 <= 4 && v24 >= buf )
        {
          v25 = (unsigned __int8)*--v24;
          ++v26;
        }
        v27 = *v24;
        if ( _lookuptrailbytes[(unsigned __int8)*v24] == 0 )
        {
          *_errno() = 42;
LABEL_93:
          retval = -1;
          goto error_return_0;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v24] + 1 == v26 )
        {
          v24 += v26;
        }
        else if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
        {
          v28 = v24 + 1;
          *(&(*v5)->pipech + v7) = v27;
          if ( v26 >= 2 )
            (*v5)->pipech2[v7] = *v28++;
          if ( v26 == 3 )
            (*v5)->pipech2[v7 + 1] = *v28++;
          v24 = &v28[-v26];
        }
        else
        {
          _lseeki64_nolock(fh, pos: -v26, mthd: 1);
        }
      }
      else
      {
        ++v24;
      }
      v29 = v24 - (_BYTE *)buf;
      bytes_read = MultiByteToWideChar(
                     CodePage: 0xFDE9u,
                     dwFlags: 0,
                     lpMultiByteStr: (LPCCH)buf,
                     cbMultiByte: v29,
                     lpWideCharStr: (LPWSTR)inputbuf,
                     cchWideChar: inputsize >> 1);
      if ( bytes_read != 0 )
      {
        v31 = *v5;
        v32 = bytes_read != v29;
        bytes_read *= 2;
        *(int *)((char *)&v31->utf8translations + v7) = v32;
        goto error_return_0;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(oserrno: LastError);
      goto LABEL_93;
    }
    if ( os_read != 0 && *(_WORD *)v9 == 10 )
      *v20 |= 4u;
    else
      *v20 &= ~4u;
    v33 = (char *)buf;
    pa = (char *)buf;
    bytes_read += (int)buf;
    if ( (unsigned int)buf >= bytes_read )
    {
LABEL_129:
      bytes_read = v33 - (_BYTE *)buf;
      goto error_return_0;
    }
    while ( 1 )
    {
      v34 = *(unsigned __int16 *)pa;
      if ( v34 == 26 )
      {
        v35 = &(*v5)->osfile + v7;
        if ( (*v35 & 0x40) != 0 )
        {
          *(_WORD *)v33 = *(_WORD *)pa;
          v33 += 2;
        }
        else
        {
          *v35 |= 2u;
        }
        goto LABEL_129;
      }
      if ( v34 == 13 )
      {
        if ( (unsigned int)pa < bytes_read - 2 )
        {
          if ( *((_WORD *)pa + 1) == 10 )
          {
            pa += 4;
            goto LABEL_110;
          }
          pa += 2;
LABEL_121:
          v36 = 13;
LABEL_122:
          *(_WORD *)v33 = v36;
          goto LABEL_123;
        }
        pa += 2;
        if ( !ReadFile(
                hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
                lpBuffer: &wpeekchr,
                nNumberOfBytesToRead: 2u,
                lpNumberOfBytesRead: (LPDWORD)&os_read,
                lpOverlapped: nullptr)
          && GetLastError() != 0
          || os_read == 0 )
        {
          goto LABEL_121;
        }
        if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
        {
          if ( wpeekchr != 10 )
          {
            *(_WORD *)v33 = 13;
            *(&(*v5)->pipech + v7) = wpeekchr;
            (*v5)->pipech2[v7] = HIBYTE(wpeekchr);
            (*v5)->pipech2[v7 + 1] = 10;
LABEL_123:
            v33 += 2;
            goto LABEL_124;
          }
LABEL_110:
          v36 = 10;
          goto LABEL_122;
        }
        if ( v33 == buf && wpeekchr == 10 )
          goto LABEL_110;
        _lseeki64_nolock(fh, pos: -2, mthd: 1);
        if ( wpeekchr != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v33 = v34;
        v33 += 2;
        pa += 2;
      }
LABEL_124:
      if ( (unsigned int)pa >= bytes_read )
        goto LABEL_129;
    }
  }
error_return_0:
  if ( buf != inputbuf )
    free(pMem: buf);
  result = retval;
  if ( retval == -2 )
    return bytes_read;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002C266
// Name: __read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _read(int fh, char *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_7:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_7;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _read_nolock(fh, inputbuf: buf, cnt);
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
// Address: 0x1002C35C
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  unsigned __int8 *v0; // eax
  unsigned __int8 *v2; // eax
  int v3; // ebx
  unsigned __int8 **v4; // edi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int i; // edi
  ioinfo *v8; // esi
  int j; // ebx
  ioinfo *v10; // esi
  DWORD v11; // eax
  HANDLE StdHandle; // eax
  int v13; // edi
  DWORD FileType; // eax
  _STARTUPINFOW StartupInfo; // [esp+4h] [ebp-4Ch] BYREF
  int *posfhnd; // [esp+48h] [ebp-8h]
  char *posfile; // [esp+4Ch] [ebp-4h]

  GetStartupInfoW(lpStartupInfo: &StartupInfo);
  v0 = calloc(count: 0x20u, size: 0x40u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = (ioinfo *)v0;
  _nhandle = 32;
  if ( v0 < v0 + 2048 )
  {
    v2 = v0 + 5;
    do
    {
      *(_DWORD *)(v2 - 5) = -1;
      *(_WORD *)(v2 - 1) = 2560;
      *(_DWORD *)(v2 + 3) = 0;
      *(_WORD *)(v2 + 31) = 2560;
      v2[33] = 10;
      *(_DWORD *)(v2 + 51) = 0;
      v2[47] = 0;
      v2 += 64;
    }
    while ( (ioinfo *)(v2 - 5) < &__pioinfo[0][32] );
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v3 = *(_DWORD *)StartupInfo.lpReserved2;
    posfile = (char *)(StartupInfo.lpReserved2 + 4);
    posfhnd = (int *)&StartupInfo.lpReserved2[v3 + 4];
    if ( v3 >= 2048 )
      v3 = 2048;
    if ( (int)_nhandle < v3 )
    {
      v4 = (unsigned __int8 **)&unk_10054AC4;
      while ( 1 )
      {
        v5 = calloc(count: 0x20u, size: 0x40u);
        if ( v5 == nullptr )
          break;
        _nhandle += 32;
        *v4 = v5;
        if ( v5 < v5 + 2048 )
        {
          v6 = v5 + 5;
          do
          {
            *(_DWORD *)(v6 - 5) = -1;
            *(_DWORD *)(v6 + 3) = 0;
            v6[31] &= 0x80u;
            *(_DWORD *)(v6 + 51) = 0;
            *(_WORD *)(v6 - 1) = 2560;
            *((_WORD *)v6 + 16) = 2570;
            v6[47] = 0;
            v6 += 64;
          }
          while ( v6 - 5 < *v4 + 2048 );
        }
        ++v4;
        if ( (int)_nhandle >= v3 )
          goto LABEL_19;
      }
      v3 = _nhandle;
    }
LABEL_19:
    for ( i = 0; i < v3; ++posfile )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*posfile & 1) != 0
        && ((*posfile & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v8 = &__pioinfo[i >> 5][i & 0x1F];
        v8->osfhnd = *posfhnd;
        v8->osfile = *posfile;
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v8->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v8->lockinitflag;
      }
      ++posfhnd;
      ++i;
    }
  }
  for ( j = 0; j < 3; ++j )
  {
    v10 = &__pioinfo[0][j];
    if ( v10->osfhnd == -1 || v10->osfhnd == -2 )
    {
      v10->osfile = -127;
      if ( j != 0 )
        v11 = -(j != 1) - 11;
      else
        v11 = -10;
      StdHandle = GetStdHandle(nStdHandle: v11);
      v13 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v10->osfhnd = v13;
        if ( (unsigned __int8)FileType == 2 )
        {
          v10->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v10->osfile |= 8u;
        }
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v10->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v10->lockinitflag;
      }
      else
      {
        v10->osfile |= 0x40u;
        v10->osfhnd = -2;
      }
    }
    else
    {
      v10->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002C5A1
// Name: __ioterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _ioterm()
{
  void **v0; // edi
  char *v1; // eax
  _RTL_CRITICAL_SECTION *v2; // esi

  v0 = (void **)__pioinfo;
  do
  {
    v1 = (char *)*v0;
    if ( *v0 != nullptr )
    {
      if ( v1 < v1 + 2048 )
      {
        v2 = (_RTL_CRITICAL_SECTION *)(v1 + 12);
        do
        {
          if ( v2[-1].SpinCount != 0 )
            DeleteCriticalSection(lpCriticalSection: v2);
          v2 = (_RTL_CRITICAL_SECTION *)((char *)v2 + 64);
        }
        while ( &v2[-1].OwningThread < (void **)((char *)*v0 + 2048) );
      }
      free(pMem: *v0);
      *v0 = nullptr;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&__piob );
}

//------------------------------------------------------------------------------
// Address: 0x1002C5F4
// Name: __lseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _lseek_nolock(int fh, LONG pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD v5; // edi
  DWORD LastError; // eax
  char *p_osfile; // eax

  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  else
  {
    v5 = SetFilePointer(hFile: osfhandle, lDistanceToMove: pos, lpDistanceToMoveHigh: nullptr, dwMoveMethod: mthd);
    if ( v5 == -1 )
      LastError = GetLastError();
    else
      LastError = 0;
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return -1;
    }
    else
    {
      p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
      *p_osfile &= ~2u;
      return v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C670
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-8h] [ebp-28h]
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
// Address: 0x1002C700
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
// Address: 0x1002C746
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x1002C762
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x1002C779
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002C792
// Name: _EH4_GlobalUnwind2(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _EH4_GlobalUnwind2(PVOID TargetFrame, PEXCEPTION_RECORD ExceptionRecord)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint, ExceptionRecord, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002C7AB
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002C7C2
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall _VEC_memzero(_BYTE *a1, unsigned int a2)
{
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  char *result; // eax
  unsigned int v6; // edx
  char v7; // al
  unsigned int k; // edx
  int i; // edx
  unsigned int j; // ebx
  unsigned int v11; // [esp-4h] [ebp-Ch]

  v2 = (unsigned __int8)a1 & 0xF;
  if ( ((unsigned __int8)a1 & 0xF) != 0 )
  {
    v11 = a2 - (16 - v2);
    for ( i = (16 - (_BYTE)v2) & 3; i != 0; --i )
      *a1++ = 0;
    for ( j = (unsigned int)(16 - v2) >> 2; j != 0; --j )
    {
      *(_DWORD *)a1 = 0;
      a1 += 4;
    }
    a2 = v11;
  }
  v3 = a2;
  v4 = a2 & 0x7F;
  for ( result = (char *)(v3 >> 7); result != nullptr; --result )
  {
    *(_OWORD *)a1 = 0;
    *((_OWORD *)a1 + 1) = 0;
    *((_OWORD *)a1 + 2) = 0;
    *((_OWORD *)a1 + 3) = 0;
    *((_OWORD *)a1 + 4) = 0;
    *((_OWORD *)a1 + 5) = 0;
    *((_OWORD *)a1 + 6) = 0;
    *((_OWORD *)a1 + 7) = 0;
    a1 += 128;
  }
  if ( v4 != 0 )
  {
    result = (char *)(v4 >> 4);
    if ( v4 >> 4 != 0 )
    {
      do
      {
        *(_OWORD *)a1 = 0;
        a1 += 16;
        --result;
      }
      while ( result != nullptr );
    }
    v6 = v4 & 0xF;
    if ( v6 != 0 )
    {
      v7 = v6;
      for ( k = v6 >> 2; k != 0; --k )
      {
        *(_DWORD *)a1 = 0;
        a1 += 4;
      }
      for ( result = (char *)(v7 & 3); result != nullptr; --result )
        *a1++ = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002C87C
// Name: write_char_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char_0(_iobuf *f@<eax>, int *pnumwritten@<esi>, wchar_t ch)
{
  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr) && _fputwc_nolock(ch, str: f) == 0xFFFF )
    *pnumwritten = -1;
  else
    ++*pnumwritten;
}

//------------------------------------------------------------------------------
// Address: 0x1002C8AB
// Name: write_string_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string_0(wchar_t *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      --len;
      write_char_0(f, pnumwritten, ch: *string++);
      if ( *pnumwritten == -1 )
      {
        if ( *_errno() != 42 )
          return;
        write_char_0(f, pnumwritten, ch: 0x3Fu);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C8FE
// Name: __woutput_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _woutput_l(_iobuf *stream, const wchar_t *format, localeinfo_struct *plocinfo, char *argptr)
{
  const wchar_t *v4; // esi
  int *v5; // edi
  bool v6; // zf
  int v8; // edx
  STATE v9; // ecx
  const wchar_t *v10; // esi
  int v11; // eax
  int v12; // eax
  _woutput_l::__l2::<unnamed_type_buffer> *p_buffer; // edi
  int v14; // ebx
  _woutput_l::__l2::<unnamed_type_text> v15; // edi
  unsigned __int8 *j; // esi
  int v17; // eax
  __int16 *v18; // eax
  _woutput_l::__l2::<unnamed_type_text> v19; // ecx
  int v20; // eax
  int v21; // eax
  _WORD *v22; // esi
  __int64 v23; // rax
  int *v24; // edi
  int v25; // esi
  char *v26; // eax
  int v27; // ecx
  void (__cdecl *v28)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v29; // ebx
  void (__cdecl *v30)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v31)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v32; // ebx
  unsigned int v33; // edi
  char *i; // esi
  int v35; // eax
  int v36; // ecx
  unsigned __int64 v37; // kr08_8
  char *v38; // eax
  _BYTE *v39; // esi
  char *sz; // eax
  int v41; // ebx
  int v42; // edi
  int v43; // edi
  const char *v44; // edi
  int v45; // ebx
  int v46; // edi
  int v47; // eax
  int v48; // [esp-14h] [ebp-494h]
  int v49; // [esp-10h] [ebp-490h]
  int v50; // [esp-Ch] [ebp-48Ch]
  int v51; // [esp-8h] [ebp-488h]
  wchar_t v52; // [esp-4h] [ebp-484h]
  int padding; // [esp+10h] [ebp-470h]
  _CRT_DOUBLE tmp; // [esp+14h] [ebp-46Ch] BYREF
  int wchar; // [esp+1Ch] [ebp-464h] BYREF
  int capexp; // [esp+20h] [ebp-460h]
  STATE state; // [esp+24h] [ebp-45Ch]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-458h] BYREF
  int no_output; // [esp+38h] [ebp-448h]
  int hexadd; // [esp+3Ch] [ebp-444h]
  const wchar_t *v61; // [esp+40h] [ebp-440h]
  char *heapbuf; // [esp+44h] [ebp-43Ch]
  char tempchar[4]; // [esp+48h] [ebp-438h] BYREF
  wchar_t prefix[2]; // [esp+4Ch] [ebp-434h] BYREF
  int fldwidth; // [esp+50h] [ebp-430h]
  int bufferiswide; // [esp+54h] [ebp-42Ch]
  int prefixlen; // [esp+58h] [ebp-428h]
  _iobuf *f; // [esp+5Ch] [ebp-424h]
  int retval; // [esp+60h] [ebp-420h]
  char *v70; // [esp+64h] [ebp-41Ch]
  int charsout; // [esp+68h] [ebp-418h] BYREF
  int textlen; // [esp+6Ch] [ebp-414h]
  _woutput_l::__l2::<unnamed_type_text> text; // [esp+70h] [ebp-410h]
  int precision; // [esp+74h] [ebp-40Ch]
  int flags; // [esp+78h] [ebp-408h]
  _woutput_l::__l2::<unnamed_type_buffer> buffer; // [esp+7Ch] [ebp-404h] BYREF

  v4 = format;
  v5 = (int *)argptr;
  f = stream;
  v70 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( f == nullptr || format == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    v6 = !_loc_update.updated;
    goto LABEL_3;
  }
  v8 = *format;
  v9 = ST_NORMAL;
  charsout = 0;
  textlen = 0;
  heapbuf = nullptr;
  retval = v8;
  if ( (_WORD)v8 == 0 )
  {
LABEL_217:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 2 )
  {
    v10 = v4 + 1;
    v61 = v10;
    if ( charsout < 0 )
      goto LABEL_217;
    if ( (unsigned __int16)(v8 - 32) > 0x58u )
      v11 = 0;
    else
      v11 = aCmd[(unsigned __int16)v8] & 0xF;
    state = __lookuptable[8 * v11 + v9] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE_0;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_214;
      case ST_FLAG:
        switch ( (unsigned __int16)v8 )
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
        goto LABEL_214;
      case ST_WIDTH:
        if ( (_WORD)v8 == 42 )
        {
          v70 = (char *)(v5 + 1);
          fldwidth = *v5;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + (unsigned __int16)v8 - 48;
        }
        goto LABEL_214;
      case ST_DOT:
        precision = 0;
        goto LABEL_214;
      case ST_PRECIS:
        if ( (_WORD)v8 == 42 )
        {
          v70 = (char *)(v5 + 1);
          precision = *v5;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + (unsigned __int16)v8 - 48;
        }
        goto LABEL_214;
      case ST_SIZE:
        switch ( (unsigned __int16)v8 )
        {
          case 'I':
            v12 = *v10;
            if ( v12 == 54 && v10[1] == 52 )
            {
              flags |= 0x8000u;
              v61 = v10 + 2;
            }
            else if ( v12 == 51 && v10[1] == 50 )
            {
              flags &= ~0x8000u;
              v61 = v10 + 2;
            }
            else if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 117 && v12 != 120 && v12 != 88 )
            {
              state = ST_NORMAL;
NORMAL_STATE_0:
              bufferiswide = 1;
              write_char_0(f, pnumwritten: &charsout, ch: v8);
            }
            break;
          case 'h':
            flags |= 0x20u;
            break;
          case 'l':
            if ( *v10 == 108 )
            {
              flags |= 0x1000u;
              v61 = v10 + 1;
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
        goto LABEL_214;
      case ST_TYPE:
        if ( (unsigned __int16)v8 <= 0x64u )
        {
          if ( (unsigned __int16)v8 == 100 )
            goto LABEL_111;
          if ( (unsigned __int16)v8 > 0x53u )
          {
            if ( (unsigned __int16)v8 != 88 )
            {
              if ( (unsigned __int16)v8 == 90 )
              {
                v18 = (__int16 *)*v5;
                v70 = (char *)(v5 + 1);
                if ( v18 != nullptr && (v19.sz = *(char **)(v18 + 2), v19.sz != nullptr) )
                {
                  v20 = *v18;
                  text.sz = v19.sz;
                  if ( (flags & 0x800) != 0 )
                  {
                    v21 = v20 - (v20 >> 31);
                    bufferiswide = 1;
LABEL_179:
                    v20 = v21 >> 1;
                    goto LABEL_180;
                  }
                  bufferiswide = 0;
                }
                else
                {
                  text.sz = __nullstring;
                  strlen(buf: __nullstring);
                }
LABEL_180:
                textlen = v20;
                goto LABEL_181;
              }
              if ( (unsigned __int16)v8 == 97 )
                goto LABEL_65;
              if ( (unsigned __int16)v8 != 99 )
                goto LABEL_181;
              goto LABEL_86;
            }
LABEL_134:
            hexadd = 7;
COMMON_HEX_0:
            retval = 16;
            if ( (flags & 0x80u) != 0 )
            {
              prefix[0] = 48;
              prefix[1] = hexadd + 81;
              prefixlen = 2;
            }
COMMON_INT_0:
            if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
            {
              v23 = *(_QWORD *)v5;
              v24 = v5 + 2;
            }
            else
            {
              v24 = v5 + 1;
              if ( (flags & 0x20) != 0 )
              {
                v70 = (char *)v24;
                if ( (flags & 0x40) != 0 )
                  LODWORD(v23) = *((__int16 *)v24 - 2);
                else
                  LODWORD(v23) = *((unsigned __int16 *)v24 - 2);
                v23 = (int)v23;
LABEL_151:
                if ( (flags & 0x40) != 0 && v23 < 0 )
                {
                  v23 = -v23;
                  flags |= 0x100u;
                }
                v32 = HIDWORD(v23);
                v33 = v23;
                if ( (flags & 0x9000) == 0 )
                  v32 = 0;
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
                if ( (v32 | (unsigned int)v23) == 0 )
                  prefixlen = 0;
                for ( i = &buffer.sz[511]; ; --i )
                {
                  v35 = precision--;
                  if ( v35 <= 0 && (v32 | v33) == 0 )
                    break;
                  v36 = __PAIR64__(v32, v33) % retval + 48;
                  v37 = __PAIR64__(v32, v33) / retval;
                  v32 = HIDWORD(v37);
                  v33 = v37;
                  if ( v36 > 57 )
                    LOBYTE(v36) = hexadd + v36;
                  *i = v36;
                }
                v38 = (char *)((char *)&buffer.wz[255] + 1 - i);
                v39 = i + 1;
                textlen = (int)v38;
                text.sz = v39;
                if ( (flags & 0x200) != 0 && (v38 == nullptr || *v39 != 48) )
                {
                  *--text.sz = 48;
                  v20 = (int)(v38 + 1);
                  goto LABEL_180;
                }
                goto LABEL_181;
              }
              LODWORD(v23) = *(v24 - 1);
              if ( (flags & 0x40) != 0 )
                v23 = (int)v23;
              else
                HIDWORD(v23) = 0;
            }
            v70 = (char *)v24;
            goto LABEL_151;
          }
          switch ( (unsigned __int16)v8 )
          {
            case 'S':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_71:
              v14 = precision;
              if ( precision == -1 )
                v14 = 0x7FFFFFFF;
              v70 = (char *)(v5 + 1);
              v15.sz = (char *)*v5;
              text.sz = v15.sz;
              if ( (flags & 0x20) == 0 )
              {
                if ( v15.sz == nullptr )
                  text.sz = (char *)__wnullstring;
                sz = text.sz;
                bufferiswide = 1;
                while ( v14 != 0 )
                {
                  --v14;
                  if ( *(_WORD *)sz == 0 )
                    break;
                  sz += 2;
                }
                v21 = sz - text.sz;
                goto LABEL_179;
              }
              if ( v15.sz == nullptr )
                text.sz = __nullstring;
              textlen = 0;
              for ( j = (unsigned __int8 *)text.sz; textlen < v14; ++textlen )
              {
                if ( *j == 0 )
                  break;
                if ( _isleadbyte_l(c: *j, plocinfo: &_loc_update.localeinfo) != 0 )
                  ++j;
                ++j;
              }
              break;
            case 'A':
              goto LABEL_64;
            case 'C':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_86:
              v17 = *(unsigned __int16 *)v5;
              bufferiswide = 1;
              v70 = (char *)(v5 + 1);
              wchar = v17;
              if ( (flags & 0x20) != 0 )
              {
                tempchar[0] = v17;
                tempchar[1] = 0;
                if ( _mbtowc_l(
                       pwc: (wchar_t *)&buffer,
                       s: tempchar,
                       n: _loc_update.localeinfo.locinfo->mb_cur_max,
                       plocinfo: &_loc_update.localeinfo) < 0 )
                  no_output = 1;
              }
              else
              {
                buffer.wz[0] = v17;
              }
              text.sz = (char *)&buffer;
              textlen = 1;
              break;
            case 'E':
            case 'G':
LABEL_64:
              v8 += 32;
              capexp = 1;
              retval = v8;
LABEL_65:
              flags |= 0x40u;
              p_buffer = &buffer;
              text.sz = (char *)&buffer;
              textlen = 512;
              if ( precision >= 0 )
              {
                if ( precision != 0 )
                {
                  if ( precision > 512 )
                    precision = 512;
                  if ( precision <= 163 )
                  {
                    LOBYTE(v8) = retval;
                  }
                  else
                  {
                    v25 = precision + 349;
                    v26 = (char *)operator new(nSize: precision + 349);
                    LOBYTE(v8) = retval;
                    heapbuf = v26;
                    if ( v26 != nullptr )
                    {
                      text.sz = v26;
                      textlen = v25;
                      p_buffer = (_woutput_l::__l2::<unnamed_type_buffer> *)v26;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = (_WORD)v8 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v27 = *(_DWORD *)v70;
              v70 += 8;
              HIDWORD(tmp.x) = *((_DWORD *)v70 - 1);
              v51 = capexp;
              v50 = precision;
              LODWORD(tmp.x) = v27;
              v49 = (char)v8;
              v48 = textlen;
              v28 = (void (__cdecl *)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))DecodePointer(Ptr: off_1004F48C);
              v28(a1: &tmp, a2: p_buffer, a3: v48, a4: v49, a5: v50, a6: v51, a7: &_loc_update);
              v29 = flags & 0x80;
              if ( (flags & 0x80) != 0 && precision == 0 )
              {
                v30 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_1004F498);
                v30(a1: p_buffer, a2: &_loc_update);
              }
              if ( (_WORD)retval == 103 && v29 == 0 )
              {
                v31 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_1004F494);
                v31(a1: p_buffer, a2: &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_woutput_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen(buf: p_buffer->sz);
              goto LABEL_180;
            default:
              break;
          }
LABEL_181:
          if ( no_output != 0 )
            goto LABEL_212;
          if ( (flags & 0x40) != 0 )
          {
            if ( (flags & 0x100) != 0 )
            {
              v52 = 45;
            }
            else if ( (flags & 1) != 0 )
            {
              v52 = 43;
            }
            else
            {
              if ( (flags & 2) == 0 )
                goto LABEL_190;
              v52 = 32;
            }
            prefix[0] = v52;
            prefixlen = 1;
          }
LABEL_190:
          v41 = fldwidth - textlen - prefixlen;
          padding = v41;
          if ( (flags & 0xC) == 0 )
          {
            v42 = fldwidth - textlen - prefixlen;
            if ( v41 > 0 )
            {
              do
              {
                --v42;
                write_char_0(f, pnumwritten: &charsout, ch: 0x20u);
              }
              while ( charsout != -1 && v42 > 0 );
            }
          }
          write_string_0(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
          if ( (flags & 8) != 0 && (flags & 4) == 0 )
          {
            v43 = v41;
            if ( v41 > 0 )
            {
              do
              {
                --v43;
                write_char_0(f, pnumwritten: &charsout, ch: 0x30u);
              }
              while ( charsout != -1 && v43 > 0 );
            }
          }
          if ( bufferiswide != 0 || textlen <= 0 )
          {
            write_string_0(string: text.wz, f, pnumwritten: &charsout, len: textlen);
          }
          else
          {
            v44 = text.sz;
            v45 = textlen;
            while ( 1 )
            {
              --v45;
              retval = _mbtowc_l(
                         pwc: (wchar_t *)&wchar,
                         s: v44,
                         n: _loc_update.localeinfo.locinfo->mb_cur_max,
                         plocinfo: &_loc_update.localeinfo);
              if ( retval <= 0 )
                break;
              write_char_0(f, pnumwritten: &charsout, ch: wchar);
              v44 += retval;
              if ( v45 <= 0 )
                goto LABEL_207;
            }
            charsout = -1;
          }
LABEL_207:
          if ( charsout >= 0 && (flags & 4) != 0 )
          {
            v46 = padding;
            do
            {
              if ( v46 <= 0 )
                break;
              --v46;
              write_char_0(f, pnumwritten: &charsout, ch: 0x20u);
            }
            while ( charsout != -1 );
          }
LABEL_212:
          if ( heapbuf != nullptr )
          {
            free(pMem: heapbuf);
            heapbuf = nullptr;
          }
LABEL_214:
          v4 = v61;
          v47 = *v61;
          retval = v47;
          if ( (_WORD)v47 == 0 )
            goto LABEL_217;
          v9 = state;
          v5 = (int *)v70;
          v8 = v47;
          continue;
        }
        if ( (unsigned __int16)v8 > 0x70u )
        {
          if ( (unsigned __int16)v8 != 115 )
          {
            if ( (unsigned __int16)v8 != 117 )
            {
              if ( (unsigned __int16)v8 != 120 )
                goto LABEL_181;
              hexadd = 39;
              goto COMMON_HEX_0;
            }
            goto LABEL_112;
          }
          goto LABEL_71;
        }
        if ( (unsigned __int16)v8 == 112 )
        {
          precision = 8;
          goto LABEL_134;
        }
        if ( (unsigned __int16)v8 < 0x65u )
          goto LABEL_181;
        if ( (unsigned __int16)v8 <= 0x67u )
          goto LABEL_65;
        if ( (unsigned __int16)v8 == 105 )
        {
LABEL_111:
          flags |= 0x40u;
LABEL_112:
          retval = 10;
          goto COMMON_INT_0;
        }
        if ( (unsigned __int16)v8 != 110 )
        {
          if ( (unsigned __int16)v8 != 111 )
            goto LABEL_181;
          retval = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
          goto COMMON_INT_0;
        }
        v22 = (_WORD *)*v5;
        v70 = (char *)(v5 + 1);
        if ( _get_printf_count_output() != 0 )
        {
          if ( (flags & 0x20) != 0 )
            *v22 = charsout;
          else
            *(_DWORD *)v22 = charsout;
          no_output = 1;
          goto LABEL_212;
        }
        *_errno() = 22;
        _invalid_parameter_noinfo();
        v6 = !_loc_update.updated;
LABEL_3:
        if ( !v6 )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      default:
        goto LABEL_214;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D5C5
// Name: public: std::__non_rtti_object::__non_rtti_object(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::__non_rtti_object *__thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const char *_Message)
{
  std::bad_typeid::bad_typeid(this, _Message);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D5E2
// Name: public: virtual std::__non_rtti_object::~__non_rtti_object(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::__non_rtti_object::~__non_rtti_object(std::__non_rtti_object *this)
{
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::exception::`vftable';
  std::exception::_Tidy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D673
// Name: public: std::__non_rtti_object::__non_rtti_object(class std::__non_rtti_object const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::__non_rtti_object *__thiscall std::__non_rtti_object::__non_rtti_object(
        std::__non_rtti_object *this,
        const std::__non_rtti_object *that)
{
  std::bad_typeid::bad_typeid(this, that);
  this->__vftable = (std::__non_rtti_object_vtbl *)&std::__non_rtti_object::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D6DC
// Name: __fullpath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  char *v8; // ebx
  DWORD v9; // eax
  char *pfname; // [esp+Ch] [ebp-4h] BYREF

  if ( path == nullptr || *path == 0 )
    return _getcwd(pnbuf: UserBuf, maxlen);
  if ( UserBuf != nullptr )
  {
    v6 = maxlen;
    if ( maxlen == 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v8 = UserBuf;
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
    v7 = calloc(count: v6, size: 1u);
    v8 = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      return nullptr;
    }
  }
  v9 = GetFullPathNameA(lpFileName: path, nBufferLength: v6, lpBuffer: v8, lpFilePart: &pfname);
  if ( v9 >= v6 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    *_errno() = 34;
    return nullptr;
  }
  if ( v9 == 0 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    goto LABEL_5;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1002D7D3
// Name: ___dtoxmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __dtoxmode(char attr, const char *name)
{
  const char *v2; // ecx
  char v3; // dl
  int v4; // edi
  unsigned int v5; // edi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // esi

  v2 = name;
  if ( name[1] == 58 )
    v2 = name + 2;
  v3 = *v2;
  if ( (*v2 == 92 || v3 == 47) && v2[1] == 0 || (attr & 0x10) != 0 || (v4 = 0x8000, v3 == 0) )
    v4 = 16448;
  v5 = ~(attr << 7) & 0x80 | 0x100 | v4;
  v6 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Eu);
  v7 = v6;
  if ( v6 != nullptr
    && (_mbsicmp(s1: v6, s2: ".exe") == 0
     || _mbsicmp(s1: v7, s2: ".cmd") == 0
     || _mbsicmp(s1: v7, s2: ".bat") == 0
     || _mbsicmp(s1: v7, s2: ".com") == 0) )
  {
    v5 |= 0x40u;
  }
  return (v5 >> 3) & 0x38 | v5 | (((v5 >> 3) & 0x38 | v5) >> 6) & 7;
}

//------------------------------------------------------------------------------
// Address: 0x1002D890
// Name: __fstat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fstat64i32(int fildes, _stat64i32 *buf)
{
  int v3; // edi
  DWORD v4; // eax
  DWORD LastError; // eax
  unsigned __int16 v6; // cx
  unsigned int v7; // ecx
  BOOL v8; // eax
  unsigned __int16 st_mode; // ax
  unsigned __int16 v10; // ax
  _FILETIME LocalFTime; // [esp+14h] [ebp-74h] BYREF
  int fildesa; // [esp+1Ch] [ebp-6Ch]
  unsigned int ulAvail; // [esp+20h] [ebp-68h] BYREF
  int retval; // [esp+24h] [ebp-64h]
  _BY_HANDLE_FILE_INFORMATION bhfi; // [esp+28h] [ebp-60h] BYREF
  _SYSTEMTIME SystemTime; // [esp+5Ch] [ebp-2Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+70h] [ebp-18h]

  fildesa = fildes;
  retval = 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return -1;
  }
  memset(dst: (int)buf, value: nullptr, count: sizeof(_stat64i32));
  if ( fildes == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fildes < 0
    || fildes >= _nhandle
    || (ulAvail = (unsigned int)&__pioinfo[fildes >> 5],
        v3 = (fildes & 0x1F) << 6,
        (*(_BYTE *)(*(_DWORD *)ulAvail + v3 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    goto LABEL_3;
  }
  __lock_fhandle(fh: fildesa);
  ms_exc.registration.TryLevel = 0;
  if ( (*(_BYTE *)(*(_DWORD *)ulAvail + v3 + 4) & 1) == 0 )
    goto LABEL_12;
  v4 = GetFileType(hFile: *(HANDLE *)(*(_DWORD *)ulAvail + ((fildes & 0x1F) << 6))) & 0xFFFF7FFF;
  switch ( v4 )
  {
    case 1u:
      buf->st_mode = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ino = 0;
      buf->st_nlink = 1;
      if ( GetFileInformationByHandle(
             hFile: *(HANDLE *)(*(_DWORD *)ulAvail + ((fildes & 0x1F) << 6)),
             lpFileInformation: &bhfi) )
      {
        st_mode = buf->st_mode;
        if ( (bhfi.dwFileAttributes & 1) != 0 )
          v10 = st_mode | 0x124;
        else
          v10 = st_mode | 0x1B6;
        buf->st_mode = v10;
        if ( bhfi.ftLastWriteTime.dwLowDateTime != 0 || bhfi.ftLastWriteTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &bhfi.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_mtime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_mtime = 0;
        }
        if ( bhfi.ftLastAccessTime.dwLowDateTime != 0 || bhfi.ftLastAccessTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &bhfi.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_atime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_atime = buf->st_mtime;
        }
        if ( bhfi.ftCreationTime.dwLowDateTime != 0 || bhfi.ftCreationTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &bhfi.ftCreationTime, lpLocalFileTime: &LocalFTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_ctime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_ctime = buf->st_mtime;
        }
        buf->st_size = bhfi.nFileSizeLow;
        buf->st_mode |= 0x8000u;
        buf->st_dev = 0;
        buf->st_rdev = 0;
        goto done;
      }
      goto LABEL_19;
    case 2u:
      v6 = 0x2000;
LABEL_22:
      buf->st_mode = v6;
      v7 = fildesa;
      buf->st_dev = fildesa;
      buf->st_rdev = v7;
      buf->st_nlink = 1;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ctime = 0;
      buf->st_mtime = 0;
      buf->st_atime = 0;
      if ( v4 == 2 )
      {
        buf->st_size = 0;
      }
      else
      {
        v8 = PeekNamedPipe(
               hNamedPipe: *(HANDLE *)(*(_DWORD *)ulAvail + ((fildes & 0x1F) << 6)),
               lpBuffer: nullptr,
               nBufferSize: 0,
               lpBytesRead: nullptr,
               lpTotalBytesAvail: &ulAvail,
               lpBytesLeftThisMessage: nullptr);
        buf->st_size = v8 ? ulAvail : 0;
      }
      goto done;
    case 3u:
      v6 = 4096;
      goto LABEL_22;
    default:
      break;
  }
  if ( v4 != 0 )
  {
LABEL_19:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    goto LABEL_13;
  }
LABEL_12:
  *_errno() = 9;
LABEL_13:
  retval = -1;
done:
  ms_exc.registration.TryLevel = -2;
  _unlock_fhandle(fh: fildesa);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1002DBE2
// Name: _tsopen_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall tsopen_nolock@<eax>(
        int *pfh@<eax>,
        unsigned int a2@<edi>,
        int *punlock_flag,
        const char *path,
        int oflag,
        int shflag,
        char pmode)
{
  unsigned int v8; // eax
  int v10; // eax
  char *v11; // eax
  DWORD v12; // eax
  DWORD FileType; // eax
  char *p_osfile; // eax
  DWORD LastError; // esi
  char v16; // cl
  _BYTE *v17; // eax
  signed int v18; // edi
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // edi
  __int64 v23; // rax
  int nolock; // eax
  __int64 v25; // rax
  DWORD v26; // eax
  int v27; // ebx
  int v28; // eax
  _BYTE *v29; // eax
  _BYTE *v30; // eax
  bool v31; // zf
  char *v32; // eax
  HANDLE v33; // eax
  DWORD v34; // eax
  char *v35; // eax
  int v36; // [esp-10h] [ebp-48h]
  DWORD v37; // [esp-Ch] [ebp-44h]
  int v38; // [esp-8h] [ebp-40h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+8h] [ebp-30h] BYREF
  int fmode; // [esp+14h] [ebp-24h] BYREF
  void *osfh; // [esp+18h] [ebp-20h]
  int bom; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned int filecreate; // [esp+20h] [ebp-18h]
  unsigned int fileshare; // [esp+24h] [ebp-14h]
  unsigned int fileattrib; // [esp+28h] [ebp-10h]
  unsigned int fileaccess; // [esp+2Ch] [ebp-Ch]
  int retvalue; // [esp+30h] [ebp-8h]
  char inputbuf; // [esp+34h] [ebp-4h] BYREF
  char v49; // [esp+35h] [ebp-3h]
  char tmode; // [esp+36h] [ebp-2h]
  char fileflags; // [esp+37h] [ebp-1h]

  fmode = 0;
  tmode = 0;
  retvalue = 0;
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = nullptr;
  if ( (oflag & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    fileflags = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    fileflags = 16;
  }
  if ( _get_fmode(pMode: &fmode) != 0 )
    _invoke_watson(a1: a2);
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || fmode != 0x8000) )
    fileflags |= 0x80u;
  if ( (oflag & 3) != 0 )
  {
    if ( (oflag & 3) != 1 )
    {
      if ( (oflag & 3) != 2 )
        goto LABEL_40;
      goto LABEL_13;
    }
    if ( (oflag & 8) != 0 && (oflag & 0x70000) != 0 )
    {
LABEL_13:
      fileaccess = -1073741824;
      goto LABEL_18;
    }
    fileaccess = 0x40000000;
  }
  else
  {
    fileaccess = 0x80000000;
  }
LABEL_18:
  switch ( shflag )
  {
    case 16:
      fileshare = 0;
      break;
    case 32:
      fileshare = 1;
      break;
    case 48:
      fileshare = 2;
      break;
    case 64:
      fileshare = 3;
      break;
    case 128:
      fileshare = fileaccess == 0x80000000;
      break;
    default:
      goto LABEL_40;
  }
  v8 = oflag & 0x700;
  if ( v8 > 0x400 )
  {
    if ( v8 != 1280 )
    {
      if ( v8 == 1536 )
        goto LABEL_41;
      if ( v8 != 1792 )
        goto LABEL_40;
    }
    filecreate = 1;
    goto LABEL_43;
  }
  if ( (oflag & 0x700) == 0x400 || (oflag & 0x700) == 0 )
  {
    filecreate = 3;
    goto LABEL_43;
  }
  if ( v8 == 256 )
  {
    filecreate = 4;
    goto LABEL_43;
  }
  if ( v8 == 512 )
  {
LABEL_41:
    filecreate = 5;
    goto LABEL_43;
  }
  if ( v8 != 768 )
  {
LABEL_40:
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  filecreate = 2;
LABEL_43:
  fileattrib = 128;
  if ( (oflag & 0x100) != 0 && (pmode & ~(_BYTE)_umaskval & 0x80u) == 0 )
    fileattrib = 1;
  if ( (oflag & 0x40) != 0 )
  {
    fileattrib |= 0x4000000u;
    fileaccess |= 0x10000u;
    fileshare |= 4u;
  }
  if ( (oflag & 0x1000) != 0 )
    fileattrib |= 0x100u;
  if ( (oflag & 0x20) != 0 )
  {
    fileattrib |= 0x8000000u;
  }
  else if ( (oflag & 0x10) != 0 )
  {
    fileattrib |= 0x10000000u;
  }
  v10 = _alloc_osfhnd();
  *pfh = v10;
  if ( v10 == -1 )
  {
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 24;
    return *_errno();
  }
  v37 = fileattrib;
  *punlock_flag = 1;
  osfh = CreateFileA(
           lpFileName: path,
           dwDesiredAccess: fileaccess,
           dwShareMode: fileshare,
           lpSecurityAttributes: &SecurityAttributes,
           dwCreationDisposition: filecreate,
           dwFlagsAndAttributes: v37,
           hTemplateFile: nullptr);
  if ( osfh != (void *)-1
    || (fileaccess & 0xC0000000) == 0xC0000000
    && (oflag & 1) != 0
    && (fileaccess &= ~0x80000000,
        (osfh = CreateFileA(
                  lpFileName: path,
                  dwDesiredAccess: fileaccess,
                  dwShareMode: fileshare,
                  lpSecurityAttributes: &SecurityAttributes,
                  dwCreationDisposition: filecreate,
                  dwFlagsAndAttributes: fileattrib,
                  hTemplateFile: nullptr)) != (void *)-1) )
  {
    FileType = GetFileType(hFile: osfh);
    switch ( FileType )
    {
      case 0u:
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
        LastError = GetLastError();
        _dosmaperr(oserrno: LastError);
        CloseHandle(hObject: osfh);
        if ( LastError == 0 )
          *_errno() = 13;
        return *_errno();
      case 2u:
        fileflags |= 0x40u;
        break;
      case 3u:
        fileflags |= 8u;
        break;
      default:
        break;
    }
    _set_osfhnd(fh: *pfh, value: (int)osfh);
    v16 = fileflags | 1;
    __pioinfo[*pfh >> 5][*pfh & 0x1F].osfile = fileflags | 1;
    v17 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
    *v17 &= 0x80u;
    v49 = v16 & 0x48;
    fileflags = v16;
    if ( (v16 & 0x48) == 0 )
    {
      if ( v16 >= 0 )
        goto LABEL_131;
      if ( (oflag & 2) != 0 )
      {
        v18 = _lseek_nolock(fh: *pfh, pos: -1, mthd: 2u);
        if ( v18 == -1 )
        {
          if ( *__doserrno() != 131 )
          {
LABEL_74:
            _close_nolock(fh: *pfh);
            return *_errno();
          }
        }
        else
        {
          v36 = *pfh;
          inputbuf = 0;
          if ( _read_nolock(fh: v36, &inputbuf, cnt: 1u) == 0
            && inputbuf == 26
            && _chsize_nolock(filedes: *pfh, size: v18) == -1
            || _lseek_nolock(fh: *pfh, pos: 0, mthd: 0) == -1 )
          {
            goto LABEL_74;
          }
        }
      }
    }
    if ( fileflags >= 0 )
    {
LABEL_131:
      v29 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      *v29 ^= (tmode ^ *v29) & 0x7F;
      v30 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      v31 = v49 == 0;
      *v30 = *v30 & 0x7F | (BYTE2(oflag) << 7);
      if ( v31 && (oflag & 8) != 0 )
      {
        v32 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *v32 |= 0x20u;
      }
      if ( (fileaccess & 0xC0000000) != 0xC0000000 || (oflag & 1) == 0 )
        return retvalue;
      CloseHandle(hObject: osfh);
      v33 = CreateFileA(
              lpFileName: path,
              dwDesiredAccess: fileaccess & 0x7FFFFFFF,
              dwShareMode: fileshare,
              lpSecurityAttributes: &SecurityAttributes,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: fileattrib,
              hTemplateFile: nullptr);
      if ( v33 != (HANDLE)-1 )
      {
        __pioinfo[*pfh >> 5][*pfh & 0x1F].osfhnd = (int)v33;
        return retvalue;
      }
      v34 = GetLastError();
      _dosmaperr(oserrno: v34);
      v35 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
      *v35 &= ~1u;
      _free_osfhnd(fh: *pfh);
      return *_errno();
    }
    if ( (oflag & 0x74000) == 0 )
    {
      if ( (fmode & 0x74000) != 0 )
        oflag |= fmode & 0x74000;
      else
        oflag |= 0x4000u;
    }
    v19 = oflag & 0x74000;
    if ( (oflag & 0x74000) == 0x4000 )
    {
      tmode = 0;
      goto LABEL_95;
    }
    if ( v19 == 0x10000 || v19 == 81920 )
    {
      if ( (oflag & 0x301) != 0x301 )
        goto LABEL_95;
    }
    else if ( v19 != 0x20000 && v19 != 147456 )
    {
      if ( v19 == 0x40000 || v19 == 278528 )
        tmode = 1;
LABEL_95:
      if ( (oflag & 0x70000) == 0 )
        goto LABEL_131;
      bom = 0;
      if ( (fileflags & 0x40) != 0 )
        goto LABEL_131;
      v20 = fileaccess & 0xC0000000;
      if ( (fileaccess & 0xC0000000) == 0x40000000 )
      {
        v21 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate <= 2 )
          goto LABEL_104;
        if ( filecreate > 4 )
          goto LABEL_103;
        if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2) != 0 )
        {
          v25 = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0);
          v26 = HIDWORD(v25) & v25;
          goto LABEL_119;
        }
      }
      else
      {
        if ( v20 == 0x80000000 )
          goto LABEL_109;
        if ( v20 != -1073741824 )
          goto LABEL_131;
        v21 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate > 2 )
        {
          if ( filecreate > 4 )
          {
LABEL_103:
            if ( v21 != 5 )
              goto LABEL_131;
            goto LABEL_104;
          }
          if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2) != 0 )
          {
            v23 = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0);
            if ( (HIDWORD(v23) & (unsigned int)v23) == 0xFFFFFFFF )
              goto LABEL_74;
LABEL_109:
            nolock = _read_nolock(fh: *pfh, inputbuf: (char *)&bom, cnt: 3u);
            if ( nolock == -1 )
              goto LABEL_74;
            if ( nolock != 2 )
            {
              if ( nolock != 3 )
              {
LABEL_126:
                v26 = _lseek_nolock(fh: *pfh, pos: 0, mthd: 0);
LABEL_119:
                if ( v26 == -1 )
                  goto LABEL_74;
                goto LABEL_131;
              }
              if ( bom == 12565487 )
              {
                tmode = 1;
                goto LABEL_131;
              }
            }
            if ( (unsigned __int16)bom == 65534 )
            {
              _close_nolock(fh: *pfh);
              *_errno() = 22;
              return 22;
            }
            if ( (unsigned __int16)bom == 65279 )
            {
              if ( _lseek_nolock(fh: *pfh, pos: 2, mthd: 0) == -1 )
                goto LABEL_74;
              tmode = 2;
              goto LABEL_131;
            }
            goto LABEL_126;
          }
        }
      }
LABEL_104:
      v22 = 0;
      if ( tmode == 1 )
      {
        bom = 12565487;
        v38 = 3;
LABEL_128:
        v27 = v38;
        while ( 1 )
        {
          v28 = _write(fh: *pfh, buf: (char *)&bom + v22, cnt: v27 - v22);
          if ( v28 == -1 )
            goto LABEL_74;
          v22 += v28;
          if ( v27 <= v22 )
            goto LABEL_131;
        }
      }
      if ( tmode == 2 )
      {
        bom = 65279;
        v38 = 2;
        goto LABEL_128;
      }
      goto LABEL_131;
    }
    tmode = 2;
    goto LABEL_95;
  }
  v11 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
  *v11 &= ~1u;
  v12 = GetLastError();
  _dosmaperr(oserrno: v12);
  return *_errno();
}

//------------------------------------------------------------------------------
// Address: 0x1002E316
// Name: __sopen_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_helper(const char *path, int oflag, int shflag, int pmode, int *pfh, int bSecure)
{
  int result; // eax
  char *p_osfile; // eax
  int retval; // [esp+14h] [ebp-20h]
  int unlock_flag; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  unlock_flag = 0;
  if ( pfh == nullptr || (*pfh = -1, path == nullptr) || bSecure != 0 && (pmode & 0xFFFFFE7F) != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    retval = tsopen_nolock(pfh, a2: 0, punlock_flag: &unlock_flag, path, oflag, shflag, pmode);
    ms_exc.registration.TryLevel = -2;
    if ( unlock_flag != 0 )
    {
      if ( retval != 0 )
      {
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
      }
      _unlock_fhandle(fh: *pfh);
    }
    result = retval;
    if ( retval != 0 )
      *pfh = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E3DA
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_s(int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(path, oflag, shflag, pmode, pfh, bSecure: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002E3FA
// Name: ___loctotime64_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __loctotime64_t(int yr, int mo, int dy, unsigned int hr, unsigned int mn, unsigned int sc, int dstflag)
{
  int v7; // ebx
  int v8; // esi
  int *v9; // eax
  int v10; // ecx
  unsigned int v11; // edi
  int timezone; // [esp+Ch] [ebp-40h] BYREF
  int dstbias; // [esp+10h] [ebp-3Ch] BYREF
  int v15; // [esp+14h] [ebp-38h]
  int daylight; // [esp+18h] [ebp-34h] BYREF
  int v17; // [esp+1Ch] [ebp-30h]
  int tmpdays; // [esp+20h] [ebp-2Ch]
  tm tb; // [esp+24h] [ebp-28h] BYREF

  v7 = mo;
  v8 = yr - 1900;
  v15 = mo;
  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( yr - 1900 < 70
    || v8 > 1100
    || (unsigned int)(mo - 1) > 0xB
    || hr > 0x17
    || mn > 0x3B
    || sc > 0x3B
    || dy < 1
    || (v9 = &_days[mo], v10 = *(v9 - 1), *v9 - v10 < dy)
    && ((v8 % 4 != 0 || v8 % 100 == 0) && yr % 400 != 0 || (v7 = v15, v15 != 2) || dy > 29) )
  {
    *_errno() = 22;
    return -1;
  }
  else
  {
    tmpdays = dy + v10;
    if ( (v8 % 4 == 0 && v8 % 100 != 0 || yr % 400 == 0) && v7 > 2 )
      ++tmpdays;
    __tzset();
    if ( _get_daylight(_Daylight: &daylight) != 0
      || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
      || _get_timezone(_Timezone: &timezone) != 0 )
    {
      _invoke_watson(a1: 0x190u);
    }
    v17 = (unsigned __int64)(365 * (v8 - 70LL) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17) >> 32;
    tb.tm_yday = tmpdays;
    v11 = sc
        + timezone
        + 60
        * (mn
         + 60
         * (hr + 24 * (tmpdays + 365 * (yr - 1970) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17)));
    tb.tm_year = yr - 1900;
    tb.tm_mon = v15 - 1;
    tb.tm_hour = hr;
    tb.tm_min = mn;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && daylight != 0 && _isindst(&tb) != 0 )
      v11 += dstbias;
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E661
// Name: __mbctolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x10) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         plocinfo: &_loc_update.localeinfo,
         Locale: _loc_update.localeinfo.mbcinfo->mblcid,
         dwMapFlags: 0x100u,
         lpSrcStr: val,
         cchSrc: 2,
         lpDestStr: (char *)ret,
         cchDest: 2,
         code_page: _loc_update.localeinfo.mbcinfo->mbcodepage,
         bError: 1) != 0 )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x1002E707
// Name: __mbctolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower(unsigned int c)
{
  return _mbctolower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002E71A
// Name: __mbspbrk_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk_l(unsigned __int8 *string, unsigned __int8 *charset, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // ecx
  unsigned __int8 *i; // eax
  unsigned __int8 v5; // dl
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strpbrk(string, control: charset);
LABEL_22:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v3 = string;
  if ( string != nullptr && charset != nullptr )
  {
    if ( *string != 0 )
    {
      do
      {
        for ( i = charset; *i != 0; ++i )
        {
          v5 = *i;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[*i + 1] & 4) != 0 )
          {
            if ( v5 == *v3 && i[1] == v3[1] || i[1] == 0 )
              break;
            ++i;
          }
          else if ( v5 == *v3 )
          {
            break;
          }
        }
        if ( *i != 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[*v3 + 1] & 4) != 0 && *++v3 == 0 )
          break;
        ++v3;
      }
      while ( *v3 != 0 );
    }
    goto LABEL_22;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x1002E7DF
// Name: __mbspbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk(unsigned __int8 *string, unsigned __int8 *charset)
{
  _mbspbrk_l(string, charset, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002E7F6
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
// Address: 0x1002E825
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  unsigned __int8 *mbctype; // eax
  int v3; // ecx
  int i; // edi
  unsigned __int8 *mbcasemap; // eax
  int j; // esi

  memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  mbctype = ptmbci->mbctype;
  v3 = (char *)&__initialmbcinfo - (char *)ptmbci;
  for ( i = 257; i != 0; --i )
  {
    *mbctype = mbctype[v3];
    ++mbctype;
  }
  mbcasemap = ptmbci->mbcasemap;
  for ( j = 256; j != 0; --j )
  {
    *mbcasemap = mbcasemap[v3];
    ++mbcasemap;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E889
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
  int v6; // eax
  unsigned __int16 v7; // cx
  unsigned __int8 v8; // cl
  unsigned int v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // dl
  int v12; // [esp+8h] [ebp-51Ch]
  _cpinfo cpinfo; // [esp+Ch] [ebp-518h] BYREF
  unsigned __int16 wVector[256]; // [esp+20h] [ebp-504h] BYREF
  unsigned __int8 upVector[256]; // [esp+220h] [ebp-304h] BYREF
  unsigned __int8 lowVector[256]; // [esp+320h] [ebp-204h] BYREF
  unsigned __int8 sbVector[256]; // [esp+420h] [ebp-104h] BYREF

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
        v2 = v3[1];
        v3 += 2;
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
    v6 = 0;
    while ( 1 )
    {
      v7 = wVector[v6];
      if ( (v7 & 1) != 0 )
      {
        ptmbci->mbctype[v6 + 1] |= 0x10u;
        v8 = lowVector[v6];
      }
      else
      {
        if ( (v7 & 2) == 0 )
        {
          ptmbci->mbcasemap[v6] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v6 + 1] |= 0x20u;
        v8 = upVector[v6];
      }
      ptmbci->mbcasemap[v6] = v8;
LABEL_16:
      if ( (unsigned int)++v6 >= 0x100 )
        return;
    }
  }
  v9 = 0;
  v12 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v10 = &ptmbci->mbcasemap[v9];
    if ( (unsigned int)&v10[v12 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v9 + 1] |= 0x10u;
      v11 = v9 + 32;
LABEL_23:
      *v10 = v11;
      goto LABEL_25;
    }
    if ( (unsigned int)&v10[v12] <= 0x19 )
    {
      ptmbci->mbctype[v9 + 1] |= 0x20u;
      v11 = v9 - 32;
      goto LABEL_23;
    }
    *v10 = 0;
LABEL_25:
    ++v9;
  }
  while ( v9 < 0x100 );
}

//------------------------------------------------------------------------------
// Address: 0x1002EA19
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
// Address: 0x1002EABD
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
// Address: 0x1002EB39
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // cl
  unsigned int k; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned __int16 *mbulinfo; // eax
  int v12; // ecx
  unsigned __int16 *v13; // ecx
  int j; // edx
  unsigned __int8 *v15; // eax
  int m; // ecx
  int v17; // edx
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
        v8 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v8;
        do
        {
          while ( *v8 != 0 )
          {
            LOBYTE(v9) = v8[1];
            if ( (_BYTE)v9 == 0 )
              break;
            v10 = *v8;
            v9 = (unsigned __int8)v9;
            while ( v10 <= v9 )
            {
              ptmbci->mbctype[v10 + 1] |= _rgctypeflag[irg];
              v9 = v8[1];
              ++v10;
            }
            SystemCP = codepagea;
            v8 += 2;
          }
          ++irg;
          v8 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(codepage: SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v13 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v12);
        for ( j = 6; j != 0; --j )
          *mbulinfo++ = *v13++;
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
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( cpinfo.MaxCharSize <= 1 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] != 0 )
        {
          v5 = &cpinfo.LeadByte[1];
          do
          {
            v6 = *v5;
            if ( *v5 == 0 )
              break;
            for ( k = *(v5 - 1); k <= v6; ++k )
              ptmbci->mbctype[k + 1] |= 4u;
            v5 += 2;
          }
          while ( *(v5 - 1) != 0 );
        }
        v15 = &ptmbci->mbctype[2];
        for ( m = 254; m != 0; --m )
          *v15++ |= 8u;
        ptmbci->mblcid = CPtoLCID(codepage: ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v17;
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
// Address: 0x1002ED22
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
  v3 = (threadmbcinfostruct *)operator new(nSize: 0x220u);
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
// Address: 0x1002EEBC
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
// Address: 0x1002EEDA
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+14h] [ebp+8h]

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
  for ( ptlocia = 6; ptlocia != 0; --ptlocia )
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
// Address: 0x1002EF69
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+Ch] [ebp+8h]

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
    for ( ptlocia = 6; ptlocia != 0; --ptlocia )
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
// Address: 0x1002F002
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
  _DWORD *v9; // eax
  int ptlocia; // [esp+14h] [ebp+8h]

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
  for ( ptlocia = 6; ptlocia != 0; --ptlocia )
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
// Address: 0x1002F14D
// Name: __updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl _updatetlocinfoEx_nolock(
        threadlocaleinfostruct **pptlocid,
        threadlocaleinfostruct *ptlocis)
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
// Address: 0x1002F19A
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
    ptloci = _updatetlocinfoEx_nolock(pptlocid: &v0->ptlocinfo, ptlocis: __ptlocinfo);
    _unlock(locknum: 12);
    ptlocinfo = ptloci;
  }
  if ( ptlocinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptlocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x1002F213
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID _encoded_null()
{
  return EncodePointer(Ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002F21C
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}

//------------------------------------------------------------------------------
// Address: 0x1002F225
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__set_flsgetvalue()
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: __getvalueindex);
  if ( Value == nullptr )
  {
    Value = DecodePointer(Ptr: gpFlsGetValue);
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: Value);
  }
  return Value;
}

//------------------------------------------------------------------------------
// Address: 0x1002F259
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mtterm()
{
  void (__stdcall *v0)(unsigned int); // eax
  unsigned int v1; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v1 = __flsindex;
    v0 = (void (__stdcall *)(unsigned int))DecodePointer(Ptr: gpFlsFree);
    v0(a1: v1);
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
// Address: 0x1002F296
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  int savedregs; // [esp+28h] [ebp+0h]

  GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  ptd->_pxcptacttab = (void *)_XcptActTab;
  ptd->_terrno = 0;
  ptd->_holdrand = 1;
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  _lock(locknum: 13);
  InterlockedIncrement(lpAddend: &ptd->ptmbcinfo->refcount);
  _unlock(locknum: 13);
  _lock(locknum: 12);
  ptd->ptlocinfo = ptloci;
  if ( ptloci == nullptr )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptloci: ptd->ptlocinfo);
  savedregs = 268628780;
  _unlock(locknum: 12);
}

//------------------------------------------------------------------------------
// Address: 0x1002F34A
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  int (__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  unsigned __int8 *v4; // eax
  int (__stdcall *v5)(unsigned int, unsigned __int8 *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  unsigned __int8 *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = (int (__stdcall *)(unsigned int))__set_flsgetvalue();
  v3 = (_tiddata *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = calloc(count: 1u, size: 0x214u);
    v3 = (_tiddata *)v4;
    if ( v4 != nullptr )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, unsigned __int8 *))DecodePointer(Ptr: gpFlsSetValue);
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
// Address: 0x1002F3C3
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd()
{
  _tiddata *result; // eax

  result = _getptd_noexit();
  if ( result == nullptr )
    _amsg_exit(rterrnum: 16);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002F3DD
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
    if ( *((_DWORD *)data + 16) != 0 )
      free(pMem: *((void **)data + 16));
    if ( *((_DWORD *)data + 17) != 0 )
      free(pMem: *((void **)data + 17));
    if ( *((_DWORD *)data + 18) != 0 )
      free(pMem: *((void **)data + 18));
    if ( *((const _XCPT_ACTION **)data + 23) != _XcptActTab )
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
    savedregs = 268629221;
    _unlock(locknum: 12);
    free(pMem: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F50C
// Name: __freeptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freeptd(_tiddata *ptd)
{
  int (__stdcall *Value)(unsigned int); // eax
  void (__stdcall *v2)(unsigned int, _DWORD); // eax
  unsigned int v3; // [esp-8h] [ebp-8h]
  unsigned int v4; // [esp-8h] [ebp-8h]

  if ( __flsindex != -1 )
  {
    if ( ptd == nullptr && TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr )
    {
      v3 = __flsindex;
      Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex);
      ptd = (_tiddata *)Value(a1: v3);
    }
    v4 = __flsindex;
    v2 = (void (__stdcall *)(unsigned int, _DWORD))DecodePointer(Ptr: gpFlsSetValue);
    v2(a1: v4, a2: 0);
    _freefls(data: ptd);
  }
  if ( __getvalueindex != -1 )
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002F57A
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinit()
{
  HMODULE ModuleHandleW; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  unsigned __int8 *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, unsigned __int8 *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-Ch] [ebp-10h]
  unsigned __int8 *v11; // [esp-8h] [ebp-Ch]

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  v1 = ModuleHandleW;
  if ( ModuleHandleW == nullptr )
  {
    _mtterm();
    return 0;
  }
  gpFlsAlloc = GetProcAddress(hModule: ModuleHandleW, lpProcName: "FlsAlloc");
  gpFlsGetValue = GetProcAddress(hModule: v1, lpProcName: "FlsGetValue");
  gpFlsSetValue = GetProcAddress(hModule: v1, lpProcName: "FlsSetValue");
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
    gpFlsAlloc = EncodePointer(Ptr: gpFlsAlloc);
    gpFlsGetValue = EncodePointer(Ptr: gpFlsGetValue);
    gpFlsSetValue = EncodePointer(Ptr: gpFlsSetValue);
    gpFlsFree = EncodePointer(Ptr: gpFlsFree);
    if ( _mtinitlocks() != 0 )
    {
      v5 = (int (__stdcall *)(_DWORD))DecodePointer(Ptr: gpFlsAlloc);
      __flsindex = v5(a1: _freefls);
      if ( __flsindex != -1 )
      {
        v6 = calloc(count: 1u, size: 0x214u);
        v7 = (_tiddata *)v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          v10 = __flsindex;
          v8 = (int (__stdcall *)(unsigned int, unsigned __int8 *))DecodePointer(Ptr: gpFlsSetValue);
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
    _mtterm();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F6F5
// Name: _iswctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswctype(unsigned __int16 c, unsigned __int16 mask)
{
  unsigned __int16 v3; // ax
  int d; // [esp+0h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
    return 0;
  if ( c >= 0x100u )
  {
    if ( !GetStringTypeW(dwInfoType: 1u, lpSrcStr: &c, cchSrc: 1, lpCharType: (LPWORD)&d) )
      d = 0;
    v3 = d;
  }
  else
  {
    v3 = _pwctype[c];
  }
  return mask & v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002F74A
// Name: __setenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setenvp()
{
  char *v0; // esi
  int v1; // edi
  int v3; // eax
  unsigned __int8 *v4; // edi
  char *i; // esi
  int v6; // eax
  unsigned int v7; // ebx
  unsigned __int8 *v8; // eax

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
    v4 = calloc(count: v1 + 1, size: 4u);
    _environ = (char **)v4;
    if ( v4 != nullptr )
    {
      for ( i = _aenvptr; ; i += v7 )
      {
        if ( *i == 0 )
        {
          free(pMem: _aenvptr);
          _aenvptr = nullptr;
          *(_DWORD *)v4 = 0;
          __env_initialized = 1;
          return 0;
        }
        strlen(buf: i);
        v7 = v6 + 1;
        if ( *i != 61 )
          break;
LABEL_15:
        ;
      }
      v8 = calloc(count: v6 + 1, size: 1u);
      *(_DWORD *)v4 = v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: (char *)v8, _SizeInBytes: v7, _Src: i) != 0 )
          _invoke_watson(a1: (unsigned int)v4);
        v4 += 4;
        goto LABEL_15;
      }
      free(pMem: _environ);
      _environ = nullptr;
      return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F826
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
// Address: 0x1002F9C0
// Name: __setargv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setargv()
{
  int v0; // edi
  unsigned int v1; // eax
  char **v2; // esi
  int numchars; // [esp+Ch] [ebp-Ch] BYREF
  int numargs; // [esp+10h] [ebp-8h] BYREF
  char *cmdstart; // [esp+14h] [ebp-4h]

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(hModule: nullptr, lpFilename: pgmname, nSize: 0x104u);
  _pgmptr = pgmname;
  if ( _acmdln == nullptr || (cmdstart = _acmdln, *_acmdln == 0) )
    cmdstart = pgmname;
  parse_cmdline(cmdstart, &numchars, argv: nullptr, args: nullptr, &numargs);
  if ( (unsigned int)numargs >= 0x3FFFFFFF )
    return -1;
  if ( numchars == -1 )
    return -1;
  v0 = numargs;
  v1 = 4 * numargs + numchars;
  if ( v1 < numchars )
    return -1;
  v2 = (char **)operator new(nSize: v1);
  if ( v2 == nullptr )
    return -1;
  parse_cmdline(cmdstart, &numchars, argv: v2, args: (char *)&v2[v0], &numargs);
  __argc = numargs - 1;
  __argv = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA7B
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __crtGetEnvironmentStringsA()
{
  LPWCH EnvironmentStringsW; // eax
  WCHAR *v1; // ebx
  unsigned int v3; // eax
  char *v4; // eax
  int nSizeW; // [esp+8h] [ebp-Ch]
  int nSizeA; // [esp+Ch] [ebp-8h]
  char *aEnv; // [esp+10h] [ebp-4h]

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = EnvironmentStringsW;
  if ( EnvironmentStringsW == nullptr )
    return nullptr;
  for ( ; *EnvironmentStringsW != 0; ++EnvironmentStringsW )
  {
    do
      ++EnvironmentStringsW;
    while ( *EnvironmentStringsW != 0 );
  }
  nSizeW = EnvironmentStringsW - v1 + 1;
  v3 = WideCharToMultiByte(
         CodePage: 0,
         dwFlags: 0,
         lpWideCharStr: v1,
         cchWideChar: nSizeW,
         lpMultiByteStr: nullptr,
         cbMultiByte: 0,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: nullptr);
  nSizeA = v3;
  if ( v3 != 0 && (v4 = (char *)operator new(nSize: v3), aEnv = v4, v4 != nullptr) )
  {
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: v1,
           cchWideChar: nSizeW,
           lpMultiByteStr: v4,
           cbMultiByte: nSizeA,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(pMem: aEnv);
      aEnv = nullptr;
    }
    FreeEnvironmentStringsW(penv: v1);
    return aEnv;
  }
  else
  {
    FreeEnvironmentStringsW(penv: v1);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FB12
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1002FB38
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Terminate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1002FB5E
// Name: __XcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _XcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  int result; // eax
  _DWORD *v3; // esi
  int *v4; // ecx
  int *v5; // eax
  void (__cdecl *v6)(int); // edx
  int v7; // ebx
  int v8; // ecx
  int i; // ecx
  int v10; // eax
  int v11; // edi

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
    while ( v5 < v4 + 36 );
    if ( v5 >= v4 + 36 || *v5 != xcptnum )
      v5 = nullptr;
    if ( v5 != nullptr && (v6 = (void (__cdecl *)(int))v5[2]) != nullptr )
    {
      if ( v6 == (void (__cdecl *)(int))5 )
      {
        v5[2] = 0;
        return 1;
      }
      else
      {
        if ( v6 != (void (__cdecl *)(int))1 )
        {
          v7 = v3[24];
          v3[24] = pxcptinfoptrs;
          v8 = v5[1];
          if ( v8 == 8 )
          {
            for ( i = 36; i < 144; i += 12 )
              *(_DWORD *)(i + v3[23] + 8) = 0;
            v10 = *v5;
            v11 = v3[25];
            switch ( v10 )
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
              case -1073741131:
                v3[25] = 141;
                break;
              case -1073741132:
                v3[25] = 142;
                break;
              default:
                break;
            }
            v6(a1: 8);
            v3[25] = v11;
          }
          else
          {
            v5[2] = 0;
            v6(a1: v8);
          }
          v3[24] = v7;
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
// Address: 0x1002FCA8
// Name: ___CppXcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __CppXcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  if ( xcptnum == -529697949 )
    return _XcptFilter(xcptnum: 0xE06D7363, pxcptinfoptrs);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002FCC8
// Name: DllMain(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1002FCCE
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
      v4 |= (v4 | 0x4711) << 16;
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
// Address: 0x1002FD69
// Name: _wcscpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcscpy_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  int result; // eax
  const wchar_t *v6; // eax
  wchar_t v7; // cx

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInWords;
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
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    *(const wchar_t *)((char *)v6 + (char *)_Dst - (char *)_Src) = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  result = 0;
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002FDCC
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringA_stat(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  const char *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  unsigned int v18; // eax
  void *v19; // esp
  WCHAR *v20; // edi
  WCHAR *v21; // eax
  int v22; // eax
  _DWORD v23[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v24; // [esp+8h] [ebp-14h] BYREF
  int inbuff_size; // [esp+Ch] [ebp-10h]
  wchar_t *inwbuffer; // [esp+10h] [ebp-Ch]
  int retval; // [esp+14h] [ebp-8h]

  if ( cchSrc > 0 )
  {
    v9 = lpSrcStr;
    v10 = cchSrc;
    while ( 1 )
    {
      --v10;
      if ( *v9 == 0 )
        break;
      ++v9;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    v11 = cchSrc - v10 - 1;
    if ( v11 < cchSrc )
      v11 = cchSrc - v10;
    cchSrc = v11;
  }
  retval = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v12 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 8 * (bError != 0) + 1,
          lpMultiByteStr: lpSrcStr,
          cbMultiByte: cchSrc,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v13 = v12;
  inbuff_size = v12;
  if ( v12 == 0 )
    return 0;
  if ( v12 > 0 && 0xFFFFFFE0 / v12 >= 2 )
  {
    v15 = 2 * v12 + 8;
    if ( v15 > 0x400 )
    {
      v17 = (wchar_t *)operator new(nSize: 2 * v13 + 8);
      if ( v17 != nullptr )
      {
        *(_DWORD *)v17 = 56797;
        goto LABEL_20;
      }
    }
    else
    {
      v16 = alloca(v15);
      v17 = (wchar_t *)v23;
      if ( v23 != nullptr )
      {
        v23[0] = 52428;
LABEL_20:
        v17 += 4;
      }
    }
    inwbuffer = v17;
    goto LABEL_23;
  }
  inwbuffer = nullptr;
LABEL_23:
  if ( inwbuffer == nullptr )
    return 0;
  if ( MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 1u,
         lpMultiByteStr: lpSrcStr,
         cbMultiByte: cchSrc,
         lpWideCharStr: inwbuffer,
         cchWideChar: v13) != 0 )
  {
    retval = LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v13, lpDestStr: nullptr, cchDest: 0);
    if ( retval != 0 )
    {
      if ( (dwMapFlags & 0x400) != 0 )
      {
        if ( cchDest != 0 && retval <= cchDest )
          LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v13, (LPWSTR)lpDestStr, cchDest);
        goto LABEL_46;
      }
      if ( retval <= 0 || 0xFFFFFFE0 / retval < 2 )
      {
        v20 = nullptr;
LABEL_39:
        if ( v20 != nullptr )
        {
          if ( LCMapStringW(
                 Locale,
                 dwMapFlags,
                 lpSrcStr: inwbuffer,
                 cchSrc: inbuff_size,
                 lpDestStr: v20,
                 cchDest: retval) != 0 )
          {
            if ( cchDest != 0 )
              v22 = WideCharToMultiByte(
                      CodePage: code_page,
                      dwFlags: 0,
                      lpWideCharStr: v20,
                      cchWideChar: retval,
                      lpMultiByteStr: lpDestStr,
                      cbMultiByte: cchDest,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
            else
              v22 = WideCharToMultiByte(
                      CodePage: code_page,
                      dwFlags: 0,
                      lpWideCharStr: v20,
                      cchWideChar: retval,
                      lpMultiByteStr: nullptr,
                      cbMultiByte: 0,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
            retval = v22;
          }
          _freea(_Memory: v20);
        }
        goto LABEL_46;
      }
      v18 = 2 * retval + 8;
      if ( v18 > 0x400 )
      {
        v21 = (WCHAR *)operator new(nSize: 2 * retval + 8);
        if ( v21 != nullptr )
        {
          *(_DWORD *)v21 = 56797;
          v21 += 4;
        }
        v20 = v21;
        goto LABEL_39;
      }
      v19 = alloca(v18);
      if ( v23 != nullptr )
      {
        v23[0] = 52428;
        v20 = (WCHAR *)&v24;
        goto LABEL_39;
      }
    }
  }
LABEL_46:
  _freea(_Memory: inwbuffer);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1002FFB3
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        UINT code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             Locale,
             dwMapFlags,
             lpSrcStr,
             cchSrc,
             lpDestStr,
             cchDest,
             code_page,
             bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002FFF9
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
// Address: 0x100300C0
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
// Address: 0x10030160
// Name: __fltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _fltin2(_flt *flt, const char *str, localeinfo_struct *_Locale)
{
  int v3; // ebx
  INTRNCVT_STATUS v4; // eax
  const char *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const char *v7; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v7 = str;
  v3 = 0;
  flags = __strgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v3 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v4 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v4 == INTRNCVT_OVERFLOW )
      v3 = 128;
    if ( (flags & 1) != 0 || v4 == INTRNCVT_UNDERFLOW )
      v3 |= 0x100u;
  }
  flt->nbytes = EndPtr - v7;
  flt->dval = x.x;
  flt->flags = v3;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x10030207
// Name: wcstoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstoxl(const wchar_t *nptr, const wchar_t **endptr, unsigned int ibase, int flags)
{
  const wchar_t *v4; // edi
  wchar_t v6; // si
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  int v11; // eax
  const wchar_t *v12; // edi
  unsigned __int16 v13; // [esp-10h] [ebp-1Ch]
  unsigned int number; // [esp+8h] [ebp-4h]

  v4 = nptr;
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  number = 0;
  do
  {
    v6 = *v4;
    v13 = *v4++;
  }
  while ( iswctype(c: v13, mask: 8u) != 0 );
  if ( v6 == 45 )
  {
    flags |= 2u;
  }
  else if ( v6 != 43 )
  {
    goto LABEL_14;
  }
  v6 = *v4++;
LABEL_14:
  if ( ibase != 0 )
    goto LABEL_21;
  if ( _wchartodigit(ch: v6) == 0 )
  {
    v7 = *v4;
    if ( v7 != 120 && v7 != 88 )
    {
      ibase = 8;
      goto LABEL_26;
    }
    ibase = 16;
LABEL_21:
    if ( ibase == 16 && _wchartodigit(ch: v6) == 0 )
    {
      v8 = *v4;
      if ( v8 == 120 || v8 == 88 )
      {
        v6 = v4[1];
        v4 += 2;
      }
    }
    goto LABEL_26;
  }
  ibase = 10;
LABEL_26:
  v9 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v10 = _wchartodigit(ch: v6);
    if ( v10 == -1 )
    {
      if ( (v6 < 0x41u || v6 > 0x5Au) && (unsigned __int16)(v6 - 97) > 0x19u )
        break;
      v11 = v6;
      if ( (unsigned __int16)(v6 - 97) <= 0x19u )
        v11 = v6 - 32;
      v10 = v11 - 55;
    }
    if ( v10 >= ibase )
      break;
    flags |= 8u;
    if ( number < v9 || number == v9 && v10 <= 0xFFFFFFFF % ibase )
    {
      number = v10 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v6 = *v4++;
  }
  v12 = v4 - 1;
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
      v12 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v12;
  if ( (flags & 2) != 0 )
    return -number;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x100303C9
// Name: _wcstol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstol(const wchar_t *nptr, wchar_t **endptr, unsigned int ibase)
{
  return wcstoxl(nptr, (const wchar_t **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100303E3
// Name: __wfltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _wfltin2(_flt *flt, const wchar_t *str, localeinfo_struct *_Locale)
{
  int v3; // ebx
  INTRNCVT_STATUS v4; // eax
  const wchar_t *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const wchar_t *v7; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v7 = str;
  v3 = 0;
  flags = __wstrgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v3 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v4 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v4 == INTRNCVT_OVERFLOW )
      v3 = 128;
    if ( (flags & 1) != 0 || v4 == INTRNCVT_UNDERFLOW )
      v3 |= 0x100u;
  }
  flt->nbytes = EndPtr - v7;
  flt->dval = x.x;
  flt->flags = v3;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x1003048C
// Name: ___wstrgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __wstrgtold12_l(
        _LDBL12 *pld12,
        const wchar_t **p_end_ptr,
        const wchar_t *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  const wchar_t *v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  const wchar_t *v15; // edx
  char *v16; // ecx
  char *v17; // ecx
  int v18; // eax
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  char *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  _LDBL12 *v26; // ecx
  char v27; // al
  _LDBL12 *v28; // ecx
  int v29; // eax
  _LDBL12 *v30; // ebx
  __int16 v31; // ax
  __int16 v32; // si
  unsigned __int16 v33; // cx
  int v34; // eax
  _WORD *v35; // edi
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // esi
  __int16 v39; // cx
  unsigned int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // esi
  int v44; // eax
  int v45; // edi
  int v46; // eax
  __int16 v47; // cx
  int v48; // esi
  unsigned int v49; // edx
  __int16 v50; // ax
  int v51; // [esp-Ch] [ebp-8Ch]
  int v52; // [esp-Ch] [ebp-8Ch]
  _LDBL12 *v53; // [esp+8h] [ebp-78h]
  __int16 man_sign; // [esp+Ch] [ebp-74h]
  unsigned int result_flags; // [esp+10h] [ebp-70h]
  int found_decpoint; // [esp+14h] [ebp-6Ch]
  unsigned __int8 *found_decpointa; // [esp+14h] [ebp-6Ch]
  int pow; // [esp+18h] [ebp-68h]
  int powa; // [esp+18h] [ebp-68h]
  int exp_sign; // [esp+1Ch] [ebp-64h]
  int exp_signa; // [esp+1Ch] [ebp-64h]
  int found_exponent; // [esp+20h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+20h] [ebp-60h]
  int found_digit; // [esp+24h] [ebp-5Ch]
  int found_digita; // [esp+24h] [ebp-5Ch]
  char *manp; // [esp+28h] [ebp-58h]
  char *manpa; // [esp+28h] [ebp-58h]
  const wchar_t *savedp; // [esp+2Ch] [ebp-54h]
  int savedpa; // [esp+2Ch] [ebp-54h]
  int exp_adj; // [esp+30h] [ebp-50h]
  int exp_adja; // [esp+30h] [ebp-50h]
  unsigned int manlen; // [esp+34h] [ebp-4Ch]
  __int16 manlena; // [esp+34h] [ebp-4Ch]
  __int64 v74; // [esp+38h] [ebp-48h] BYREF
  int v75; // [esp+40h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+44h] [ebp-3Ch] BYREF
  _BYTE v77[12]; // [esp+54h] [ebp-2Ch] BYREF
  char buf[28]; // [esp+60h] [ebp-20h] BYREF

  v8 = 0;
  manp = buf;
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
    _invalid_parameter_noinfo();
    return 0;
  }
  v10 = str;
  savedp = str;
  while ( 1 )
  {
    v11 = *v10;
    if ( v11 != 32 && v11 != 9 && v11 != 10 && v11 != 13 )
      break;
    ++v10;
  }
  while ( 2 )
  {
    v12 = *v10++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_11;
        if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v13 = v12 - 43;
        if ( v13 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v14 = v13 - 2;
        if ( v14 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v14 != 3 )
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_11;
        if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v12 == 43 || v12 == 45 )
          goto LABEL_32;
        if ( v12 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v12 <= 67 || v12 > 69 && (unsigned int)(v12 - 100) > 1 )
          goto LABEL_74;
        v52 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
        {
LABEL_11:
          v51 = 3;
LABEL_12:
          v8 = v51;
          --v10;
        }
        else
        {
          if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v52 = 5;
            goto LABEL_15;
          }
          if ( v12 != 48 )
          {
LABEL_36:
            v15 = savedp;
            goto LABEL_81;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            v16 = manp;
            ++manlen;
            ++manp;
            *v16 = v12 - 48;
          }
          LOWORD(v12) = *v10++;
        }
        v12 = (unsigned __int16)v12;
        if ( (unsigned __int16)v12 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_45;
LABEL_24:
        v52 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( (_WORD)v12 == 48 )
          {
            --exp_adj;
            LOWORD(v12) = *v10++;
          }
        }
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            v17 = manp++;
            --exp_adj;
            *v17 = v12 - 48;
          }
          LOWORD(v12) = *v10++;
        }
        v12 = (unsigned __int16)v12;
LABEL_45:
        if ( v12 != 43 && v12 != 45 )
          goto LABEL_28;
LABEL_32:
        --v10;
        v52 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int16)(v12 - 48) > 9u )
          goto LABEL_36;
        v51 = 4;
        goto LABEL_12;
      case 6:
        savedp = v10 - 2;
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_62;
        v18 = v12 - 43;
        if ( v18 == 0 )
          goto LABEL_69;
        v19 = v18 - 2;
        if ( v19 == 0 )
          goto LABEL_68;
        v20 = v19 == 3;
LABEL_66:
        if ( !v20 )
          goto LABEL_36;
        v52 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_62;
        v20 = (_WORD)v12 == 48;
        goto LABEL_66;
      case 8:
        found_exponent = 1;
        while ( (_WORD)v12 == 48 )
          LOWORD(v12) = *v10++;
        if ( (unsigned __int16)(v12 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v51 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v23 = 0;
        while ( 2 )
        {
          if ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
          {
            v23 = 10 * v23 + (unsigned __int16)v12 - 48;
            if ( v23 <= 5200 )
            {
              LOWORD(v12) = *v10++;
              continue;
            }
            v23 = 5201;
          }
          break;
        }
        pow = v23;
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
          LOWORD(v12) = *v10++;
LABEL_74:
        v15 = v10 - 1;
        goto LABEL_81;
      case 11:
        if ( implicit_E != 0 )
        {
          v21 = v12 - 43;
          savedp = v10 - 1;
          if ( v21 != 0 )
          {
            if ( v21 != 2 )
            {
              v15 = v10 - 1;
              goto LABEL_81;
            }
LABEL_68:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_69:
            v52 = 7;
LABEL_15:
            v8 = v52;
          }
          continue;
        }
        v15 = v10 - 1;
LABEL_81:
        *p_end_ptr = v15;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_177:
          v47 = 0;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_178;
        }
        if ( manlen <= 0x18 )
        {
          v22 = manp;
        }
        else
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          manlen = 24;
          v22 = manp - 1;
          ++exp_adj;
        }
        if ( manlen == 0 )
          goto LABEL_177;
        while ( *--v22 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v24 = pow;
        if ( exp_sign < 0 )
          v24 = -pow;
        v25 = exp_adj + v24;
        if ( found_exponent == 0 )
          v25 += scale;
        if ( found_decpoint == 0 )
          v25 -= decpt;
        if ( v25 > 5200 )
        {
          v48 = 0;
          v50 = 0x7FFF;
          v49 = 0x80000000;
          v47 = 0;
          result_flags = 2;
          goto LABEL_178;
        }
        if ( v25 < -5200 )
        {
          result_flags = 1;
          goto LABEL_177;
        }
        v26 = &_pow10pos[-8];
        savedpa = v25;
        if ( v25 != 0 )
        {
          if ( v25 < 0 )
          {
            savedpa = -v25;
            v26 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          if ( savedpa != 0 )
          {
            while ( 1 )
            {
              v27 = savedpa;
              savedpa >>= 3;
              v28 = v26 + 7;
              v29 = v27 & 7;
              v53 = v28;
              if ( v29 == 0 )
                goto LABEL_172;
              v30 = &v28[v29];
              if ( *(_WORD *)v30->ld12 >= 0x8000u )
              {
                v74 = *(_QWORD *)v30->ld12;
                v75 = *(_DWORD *)&v30->ld12[8];
                --*(_DWORD *)((char *)&v74 + 2);
                v30 = (_LDBL12 *)&v74;
              }
              manpa = nullptr;
              memset(v77, 0, sizeof(v77));
              v31 = *(_WORD *)&v30->ld12[10] & 0x7FFF;
              v32 = (*(_WORD *)&tmpld12.ld12[10] ^ *(_WORD *)&v30->ld12[10]) & 0x8000;
              manlena = v32;
              v33 = v31 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF
                || (*(_WORD *)&v30->ld12[10] & 0x7FFF) == 0x7FFF
                || v33 > 0xBFFDu )
              {
                break;
              }
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_171:
                *(_DWORD *)&tmpld12.ld12[8] = v34;
                goto LABEL_172;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v33, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v31 != 0
                  || (++v33, (*(_DWORD *)&v30->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v30->ld12[4] != 0
                  || *(_DWORD *)v30->ld12 != 0 )
                {
                  exp_signa = 0;
                  v35 = &v77[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v30->ld12[8];
                    do
                    {
                      exp_adja = 0;
                      v36 = *(unsigned __int16 *)found_exponenta * *(unsigned __int16 *)found_decpointa;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        exp_adja = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( exp_adja != 0 )
                        ++*v35;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    ++v35;
                    ++exp_signa;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_181;
                  do
                  {
                    if ( *(int *)&v77[8] < 0 )
                      break;
                    v40 = *(_DWORD *)v77;
                    *(_DWORD *)v77 *= 2;
                    v41 = (v40 >> 31) | (2 * *(_DWORD *)&v77[4]);
                    v42 = *(__int64 *)&v77[4] >> 31;
                    --v39;
                    *(_DWORD *)&v77[4] = v41;
                    *(_DWORD *)&v77[8] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_181:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v77[0] & 1) != 0 )
                          ++manpa;
                        v44 = *(_DWORD *)&v77[8];
                        *(_DWORD *)&v77[8] >>= 1;
                        v45 = (v44 << 31) | (*(_DWORD *)&v77[4] >> 1);
                        v46 = *(__int64 *)v77 >> 1;
                        --v43;
                        *(_DWORD *)&v77[4] = v45;
                        *(_DWORD *)v77 = v46;
                      }
                      while ( v43 != 0 );
                      if ( manpa != nullptr )
                        *(_WORD *)v77 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v77 > 0x8000u || (*(_DWORD *)v77 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v77[2] == -1 )
                    {
                      *(_DWORD *)&v77[2] = 0;
                      if ( *(_DWORD *)&v77[6] == -1 )
                      {
                        *(_DWORD *)&v77[6] = 0;
                        if ( *(_WORD *)&v77[10] == 0xFFFF )
                        {
                          *(_WORD *)&v77[10] = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++*(_WORD *)&v77[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v77[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v77[2];
                    }
                  }
                  if ( (unsigned __int16)v39 < 0x7FFFu )
                  {
                    *(_WORD *)tmpld12.ld12 = *(_WORD *)&v77[2];
                    *(_DWORD *)&tmpld12.ld12[2] = *(_DWORD *)&v77[4];
                    *(_DWORD *)&tmpld12.ld12[6] = *(_DWORD *)&v77[8];
                    *(_WORD *)&tmpld12.ld12[10] = manlena | v39;
                  }
                  else
                  {
                    *(_DWORD *)&tmpld12.ld12[4] = 0;
                    *(_DWORD *)tmpld12.ld12 = 0;
                    *(_DWORD *)&tmpld12.ld12[8] = manlena == 0 ? 2147450880 : -32768;
                  }
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
LABEL_172:
              if ( savedpa == 0 )
                goto LABEL_173;
              v26 = v53;
            }
            *(_DWORD *)&tmpld12.ld12[4] = 0;
            v34 = v32 == 0 ? 2147450880 : -32768;
            *(_DWORD *)tmpld12.ld12 = 0;
            goto LABEL_171;
          }
        }
LABEL_173:
        v47 = *(_WORD *)tmpld12.ld12;
        v48 = *(_DWORD *)&tmpld12.ld12[2];
        v49 = *(_DWORD *)&tmpld12.ld12[6];
        v50 = *(_WORD *)&tmpld12.ld12[10];
LABEL_178:
        *(_DWORD *)&pld12->ld12[2] = v48;
        *(_WORD *)&pld12->ld12[10] = man_sign | v50;
        *(_WORD *)pld12->ld12 = v47;
        *(_DWORD *)&pld12->ld12[6] = v49;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030BCC
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
  _LDBL12 *v24; // ecx
  char v25; // al
  _LDBL12 *v26; // ecx
  int v27; // eax
  _LDBL12 *v28; // ebx
  __int16 v29; // ax
  __int16 v30; // si
  unsigned __int16 v31; // cx
  int v32; // eax
  _WORD *v33; // edi
  unsigned int v34; // eax
  unsigned int v35; // edx
  unsigned int v36; // esi
  __int16 v37; // cx
  unsigned int v38; // eax
  int v39; // esi
  int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // edi
  int v44; // eax
  __int16 v45; // cx
  int v46; // esi
  unsigned int v47; // edx
  __int16 v48; // ax
  int v49; // [esp-8h] [ebp-8Ch]
  int v50; // [esp-8h] [ebp-8Ch]
  _LDBL12 *v51; // [esp+8h] [ebp-7Ch]
  __int16 man_sign; // [esp+10h] [ebp-74h]
  __int16 v53; // [esp+14h] [ebp-70h]
  unsigned int result_flags; // [esp+18h] [ebp-6Ch]
  int exp_sign; // [esp+1Ch] [ebp-68h]
  int exp_signa; // [esp+1Ch] [ebp-68h]
  int pow; // [esp+20h] [ebp-64h]
  int powa; // [esp+20h] [ebp-64h]
  int found_exponent; // [esp+24h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+24h] [ebp-60h]
  int found_decpoint; // [esp+28h] [ebp-5Ch]
  unsigned __int8 *found_decpointa; // [esp+28h] [ebp-5Ch]
  int found_digit; // [esp+2Ch] [ebp-58h]
  int found_digita; // [esp+2Ch] [ebp-58h]
  const char *savedp; // [esp+30h] [ebp-54h]
  int savedpa; // [esp+30h] [ebp-54h]
  int exp_adj; // [esp+34h] [ebp-50h]
  int exp_adja; // [esp+34h] [ebp-50h]
  unsigned int manlen; // [esp+38h] [ebp-4Ch]
  unsigned int manlena; // [esp+38h] [ebp-4Ch]
  __int64 v71; // [esp+3Ch] [ebp-48h] BYREF
  int v72; // [esp+44h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+48h] [ebp-3Ch] BYREF
  _BYTE v74[12]; // [esp+58h] [ebp-2Ch] BYREF
  char buf[28]; // [esp+64h] [ebp-20h] BYREF

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
    _invalid_parameter_noinfo();
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
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_32;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (unsigned __int8)(v13 - 100) > 1u )
          goto LABEL_74;
        v50 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v49 = 3;
LABEL_12:
          v8 = v49;
          --v11;
        }
        else
        {
          if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v50 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_36:
            v16 = savedp;
            goto LABEL_81;
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
          goto LABEL_45;
LABEL_24:
        v50 = 4;
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
LABEL_45:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_32:
        --v11;
        v50 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_36;
        v49 = 4;
        goto LABEL_12;
      case 6:
        savedp = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_62;
        v17 = v13 - 43;
        if ( v17 == 0 )
          goto LABEL_69;
        v18 = v17 - 2;
        if ( v18 == 0 )
          goto LABEL_68;
        v19 = v18 == 3;
LABEL_66:
        if ( !v19 )
          goto LABEL_36;
        v50 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_62;
        v19 = v13 == 48;
        goto LABEL_66;
      case 8:
        found_exponent = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v49 = 9;
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
LABEL_74:
        v16 = v11 - 1;
        goto LABEL_81;
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
              goto LABEL_81;
            }
LABEL_68:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_69:
            v50 = 7;
LABEL_15:
            v8 = v50;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_81:
        *p_end_ptr = v16;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_176:
          v45 = 0;
          v48 = 0;
          v47 = 0;
          v46 = 0;
          goto LABEL_177;
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
          goto LABEL_176;
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
          v46 = 0;
          v48 = 0x7FFF;
          v47 = 0x80000000;
          v45 = 0;
          result_flags = 2;
          goto LABEL_177;
        }
        if ( v23 < -5200 )
        {
          result_flags = 1;
          goto LABEL_176;
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
          if ( savedpa != 0 )
          {
            while ( 1 )
            {
              v25 = savedpa;
              savedpa >>= 3;
              v26 = v24 + 7;
              v27 = v25 & 7;
              v51 = v26;
              if ( v27 == 0 )
                goto LABEL_171;
              v28 = &v26[v27];
              if ( *(_WORD *)v28->ld12 >= 0x8000u )
              {
                v71 = *(_QWORD *)v28->ld12;
                v72 = *(_DWORD *)&v28->ld12[8];
                --*(_DWORD *)((char *)&v71 + 2);
                v28 = (_LDBL12 *)&v71;
              }
              exp_adja = 0;
              memset(v74, 0, sizeof(v74));
              v29 = *(_WORD *)&v28->ld12[10] & 0x7FFF;
              v30 = (*(_WORD *)&tmpld12.ld12[10] ^ *(_WORD *)&v28->ld12[10]) & 0x8000;
              v53 = v30;
              v31 = v29 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF
                || (*(_WORD *)&v28->ld12[10] & 0x7FFF) == 0x7FFF
                || v31 > 0xBFFDu )
              {
                break;
              }
              if ( v31 <= 0x3FBFu )
              {
                v32 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_170:
                *(_DWORD *)&tmpld12.ld12[8] = v32;
                goto LABEL_171;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v31, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v29 != 0
                  || (++v31, (*(_DWORD *)&v28->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v28->ld12[4] != 0
                  || *(_DWORD *)v28->ld12 != 0 )
                {
                  exp_signa = 0;
                  v33 = &v74[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v28->ld12[8];
                    do
                    {
                      manlena = 0;
                      v34 = *(unsigned __int16 *)found_decpointa * *(unsigned __int16 *)found_exponenta;
                      v35 = *((_DWORD *)v33 - 1);
                      v36 = v35 + v34;
                      if ( v35 + v34 < v35 || v36 < v34 )
                        manlena = 1;
                      *((_DWORD *)v33 - 1) = v36;
                      if ( manlena != 0 )
                        ++*v33;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    ++v33;
                    ++exp_signa;
                  }
                  v37 = v31 - 16382;
                  if ( v37 <= 0 )
                    goto LABEL_180;
                  do
                  {
                    if ( *(int *)&v74[8] < 0 )
                      break;
                    v38 = *(_DWORD *)v74;
                    *(_DWORD *)v74 *= 2;
                    v39 = (v38 >> 31) | (2 * *(_DWORD *)&v74[4]);
                    v40 = *(__int64 *)&v74[4] >> 31;
                    --v37;
                    *(_DWORD *)&v74[4] = v39;
                    *(_DWORD *)&v74[8] = v40;
                  }
                  while ( v37 > 0 );
                  if ( v37 <= 0 )
                  {
LABEL_180:
                    if ( --v37 < 0 )
                    {
                      v41 = (unsigned __int16)-v37;
                      v37 = 0;
                      do
                      {
                        if ( (v74[0] & 1) != 0 )
                          ++exp_adja;
                        v42 = *(_DWORD *)&v74[8];
                        *(_DWORD *)&v74[8] >>= 1;
                        v43 = (v42 << 31) | (*(_DWORD *)&v74[4] >> 1);
                        v44 = *(__int64 *)v74 >> 1;
                        --v41;
                        *(_DWORD *)&v74[4] = v43;
                        *(_DWORD *)v74 = v44;
                      }
                      while ( v41 != 0 );
                      if ( exp_adja != 0 )
                        *(_WORD *)v74 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v74 > 0x8000u || (*(_DWORD *)v74 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v74[2] == -1 )
                    {
                      *(_DWORD *)&v74[2] = 0;
                      if ( *(_DWORD *)&v74[6] == -1 )
                      {
                        *(_DWORD *)&v74[6] = 0;
                        if ( *(_WORD *)&v74[10] == 0xFFFF )
                        {
                          *(_WORD *)&v74[10] = 0x8000;
                          ++v37;
                        }
                        else
                        {
                          ++*(_WORD *)&v74[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v74[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v74[2];
                    }
                  }
                  if ( (unsigned __int16)v37 < 0x7FFFu )
                  {
                    *(_WORD *)tmpld12.ld12 = *(_WORD *)&v74[2];
                    *(_DWORD *)&tmpld12.ld12[2] = *(_DWORD *)&v74[4];
                    *(_DWORD *)&tmpld12.ld12[6] = *(_DWORD *)&v74[8];
                    *(_WORD *)&tmpld12.ld12[10] = v53 | v37;
                  }
                  else
                  {
                    *(_DWORD *)&tmpld12.ld12[4] = 0;
                    *(_DWORD *)tmpld12.ld12 = 0;
                    *(_DWORD *)&tmpld12.ld12[8] = v53 == 0 ? 2147450880 : -32768;
                  }
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
LABEL_171:
              if ( savedpa == 0 )
                goto LABEL_172;
              v24 = v51;
            }
            *(_DWORD *)&tmpld12.ld12[4] = 0;
            v32 = v30 == 0 ? 2147450880 : -32768;
            *(_DWORD *)tmpld12.ld12 = 0;
            goto LABEL_170;
          }
        }
LABEL_172:
        v45 = *(_WORD *)tmpld12.ld12;
        v46 = *(_DWORD *)&tmpld12.ld12[2];
        v47 = *(_DWORD *)&tmpld12.ld12[6];
        v48 = *(_WORD *)&tmpld12.ld12[10];
LABEL_177:
        *(_WORD *)pld12->ld12 = v45;
        *(_WORD *)&pld12->ld12[10] = man_sign | v48;
        *(_DWORD *)&pld12->ld12[2] = v46;
        *(_DWORD *)&pld12->ld12[6] = v47;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100312A8
// Name: ___libm_error_support
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_error_support(long double *arg1, long double *arg2, long double *retval, error_types input_tag)
{
  int (__cdecl *v4)(_exception *); // eax
  long double *v5; // esi
  long double v6; // st7
  long double *v7; // ecx
  long double v8; // st7
  _exception exc; // [esp+0h] [ebp-28h] BYREF
  char double_zero[8]; // [esp+20h] [ebp-8h] BYREF

  memset(double_zero, 0, sizeof(double_zero));
  if ( pmatherr_set != 0 )
    v4 = (int (__cdecl *)(_exception *))DecodePointer(Ptr: _pmatherr);
  else
    v4 = (int (__cdecl *)(_exception *))__init_collate;
  if ( input_tag > exp10_overflow )
  {
    switch ( input_tag )
    {
      case log_nan:
        exc.name = "log";
        goto LABEL_38;
      case log10_nan:
        exc.name = "log10";
        goto LABEL_38;
      case exp_nan:
        exc.name = "exp";
        goto LABEL_38;
      case atan_nan:
        exc.name = "atan";
        goto LABEL_38;
      case ceil_nan:
        exc.name = "ceil";
        goto LABEL_38;
      case floor_nan:
        exc.name = "floor";
        goto LABEL_38;
      case pow_nan:
        goto $LN36_2;
      case modf_nan:
        exc.name = "modf";
        goto LABEL_38;
      case acos_nan:
        goto $LN30_0;
      case asin_nan:
        goto $LN8_9;
      case sin_naninf:
        exc.name = "sin";
        goto LABEL_54;
      case cos_naninf:
        exc.name = "cos";
        goto LABEL_54;
      case tan_naninf:
        exc.name = "tan";
LABEL_54:
        v5 = retval;
        v8 = *arg1 * *(double *)double_zero;
        *retval = v8;
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        goto LABEL_55;
      default:
        return;
    }
  }
  if ( input_tag == exp10_overflow )
  {
    exc.type = 3;
    exc.name = "exp10";
LABEL_17:
    v5 = retval;
    exc.arg1 = *arg1;
    exc.arg2 = *arg2;
    exc.retval = *retval;
    if ( v4(a1: &exc) == 0 )
      *_errno() = 34;
    goto LABEL_57;
  }
  if ( input_tag > pow_underflow )
  {
    switch ( input_tag )
    {
      case pow_zero_to_zero:
        *retval = 1.0;
        return;
      case pow_zero_to_negative:
        exc.type = 2;
LABEL_16:
        exc.name = "pow";
        goto LABEL_17;
      case pow_neg_to_non_integer:
$LN36_2:
        exc.name = "pow";
        break;
      case pow_nan_to_zero:
        exc.name = "pow";
LABEL_38:
        v7 = arg1;
        v5 = retval;
        *retval = *arg1;
LABEL_24:
        exc.arg1 = *v7;
        exc.arg2 = *arg2;
        v8 = *v5;
LABEL_55:
        exc.retval = v8;
        exc.type = 1;
        if ( v4(a1: &exc) == 0 )
          *_errno() = 33;
        goto LABEL_57;
      case acos_gt_one:
$LN30_0:
        exc.name = "acos";
        break;
      case asin_gt_one:
$LN8_9:
        exc.name = "asin";
        break;
      default:
        return;
    }
LABEL_23:
    v7 = arg1;
    v5 = retval;
    goto LABEL_24;
  }
  switch ( input_tag )
  {
    case pow_underflow:
      exc.name = "pow";
      goto LABEL_20;
    case log_zero:
      exc.type = 2;
      exc.name = "log";
      goto LABEL_17;
    case log_negative:
      exc.name = "log";
      goto LABEL_23;
    case log10_zero:
      exc.type = 2;
      exc.name = "log10";
      goto LABEL_17;
    case log10_negative:
      exc.name = "log10";
      goto LABEL_23;
    case exp_overflow:
      exc.type = 3;
      exc.name = "exp";
      goto LABEL_17;
    default:
      break;
  }
  if ( input_tag != exp_underflow )
  {
    if ( input_tag != pow_overflow )
      return;
    exc.type = 3;
    goto LABEL_16;
  }
  exc.name = "exp";
LABEL_20:
  v5 = retval;
  exc.arg1 = *arg1;
  exc.arg2 = *arg2;
  v6 = *retval;
  exc.type = 4;
  exc.retval = v6;
  v4(a1: &exc);
LABEL_57:
  *v5 = exc.retval;
}

//------------------------------------------------------------------------------
// Address: 0x10031574
// Name: __sse2_mathfcns_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sse2_mathfcns_init()
{
  __use_sse2_mathfcns = IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031584
// Name: __ceil_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _ceil_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]

  v1 = _ctrlfp(newctrl: newcw, _mask: 0xFFFFu);
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xCu, x, savedcw: v1);
    }
    return _except1(flags: 8, opcode: 12, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
      return v4;
    }
    else
    {
      return _except1(flags: 16, opcode: 12, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003165C
// Name: _get_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall get_lc_time@<eax>(__lc_time_data *lc_time@<ecx>, threadlocaleinfostruct *ploci@<eax>)
{
  unsigned int wLanguage; // ebx
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // edi
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // edi
  int v28; // edi
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  int v33; // edi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  int v37; // edi
  int v38; // edi
  int v39; // edi
  int v40; // edi
  int v41; // edi
  int v42; // edi
  int v43; // edi
  int v44; // edi
  int v45; // edi
  int v46; // edi
  int v47; // edi
  int v48; // edi
  int v49; // edi
  int v50; // edi
  int v51; // edi
  int v52; // edi
  int v53; // edi
  int v54; // edi
  int v55; // edi
  int v56; // edi
  int v57; // edi
  int v58; // edi
  int v59; // edi
  int v60; // edi
  int v61; // edi
  int v62; // edi
  int v63; // edi
  int v64; // edi
  int v65; // edi
  int v66; // edi
  int v67; // edi
  int v68; // edi
  int v69; // edi
  int v70; // edi
  int v71; // edi
  int v72; // edi
  int v73; // edi
  int v74; // edi
  int v75; // edi
  int v76; // edi
  int v77; // edi
  int v78; // edi
  int v79; // edi
  int v80; // edi
  int v81; // edi
  int v82; // edi
  int v83; // edi
  int v84; // edi
  int v85; // edi
  int v86; // edi
  int v87; // edi
  int v88; // edi
  int v89; // edi
  int v90; // edi
  localeinfo_struct locinfo; // [esp+8h] [ebp-Ch] BYREF
  unsigned int ctryid; // [esp+10h] [ebp-4h]

  wLanguage = ploci->lc_id[5].wLanguage;
  ctryid = ploci->lc_id[5].wCountry;
  if ( lc_time == nullptr )
    return -1;
  locinfo.mbcinfo = nullptr;
  locinfo.locinfo = ploci;
  v5 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: wLanguage,
         fieldtype: 0x31u,
         address: (void **)&lc_time->wday_abbr[1]);
  v6 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: wLanguage,
         fieldtype: 0x32u,
         address: (void **)&lc_time->wday_abbr[2])
     | v5;
  v7 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: wLanguage,
         fieldtype: 0x33u,
         address: (void **)&lc_time->wday_abbr[3])
     | v6;
  v8 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: wLanguage,
         fieldtype: 0x34u,
         address: (void **)&lc_time->wday_abbr[4])
     | v7;
  v9 = __getlocaleinfo(
         plocinfo: &locinfo,
         lc_type: 1,
         localehandle: wLanguage,
         fieldtype: 0x35u,
         address: (void **)&lc_time->wday_abbr[5])
     | v8;
  v10 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x36u,
          address: (void **)&lc_time->wday_abbr[6])
      | v9;
  v11 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x37u,
          address: (void **)lc_time->wday_abbr)
      | v10;
  v12 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x2Au,
          address: (void **)&lc_time->wday[1])
      | v11;
  v13 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x2Bu,
          address: (void **)&lc_time->wday[2])
      | v12;
  v14 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x2Cu,
          address: (void **)&lc_time->wday[3])
      | v13;
  v15 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x2Du,
          address: (void **)&lc_time->wday[4])
      | v14;
  v16 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x2Eu,
          address: (void **)&lc_time->wday[5])
      | v15;
  v17 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x2Fu,
          address: (void **)&lc_time->wday[6])
      | v16;
  v18 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x30u,
          address: (void **)lc_time->wday)
      | v17;
  v19 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x44u,
          address: (void **)lc_time->month_abbr)
      | v18;
  v20 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x45u,
          address: (void **)&lc_time->month_abbr[1])
      | v19;
  v21 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x46u,
          address: (void **)&lc_time->month_abbr[2])
      | v20;
  v22 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x47u,
          address: (void **)&lc_time->month_abbr[3])
      | v21;
  v23 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x48u,
          address: (void **)&lc_time->month_abbr[4])
      | v22;
  v24 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x49u,
          address: (void **)&lc_time->month_abbr[5])
      | v23;
  v25 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x4Au,
          address: (void **)&lc_time->month_abbr[6])
      | v24;
  v26 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x4Bu,
          address: (void **)&lc_time->month_abbr[7])
      | v25;
  v27 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x4Cu,
          address: (void **)&lc_time->month_abbr[8])
      | v26;
  v28 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x4Du,
          address: (void **)&lc_time->month_abbr[9])
      | v27;
  v29 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x4Eu,
          address: (void **)&lc_time->month_abbr[10])
      | v28;
  v30 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x4Fu,
          address: (void **)&lc_time->month_abbr[11])
      | v29;
  v31 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x38u,
          address: (void **)lc_time->month)
      | v30;
  v32 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x39u,
          address: (void **)&lc_time->month[1])
      | v31;
  v33 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x3Au,
          address: (void **)&lc_time->month[2])
      | v32;
  v34 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x3Bu,
          address: (void **)&lc_time->month[3])
      | v33;
  v35 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x3Cu,
          address: (void **)&lc_time->month[4])
      | v34;
  v36 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x3Du,
          address: (void **)&lc_time->month[5])
      | v35;
  v37 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x3Eu,
          address: (void **)&lc_time->month[6])
      | v36;
  v38 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x3Fu,
          address: (void **)&lc_time->month[7])
      | v37;
  v39 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x40u,
          address: (void **)&lc_time->month[8])
      | v38;
  v40 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x41u,
          address: (void **)&lc_time->month[9])
      | v39;
  v41 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x42u,
          address: (void **)&lc_time->month[10])
      | v40;
  v42 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x43u,
          address: (void **)&lc_time->month[11])
      | v41;
  v43 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x28u,
          address: (void **)lc_time->ampm)
      | v42;
  v44 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: wLanguage,
          fieldtype: 0x29u,
          address: (void **)&lc_time->ampm[1])
      | v43;
  v45 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: ctryid,
          fieldtype: 0x1Fu,
          address: (void **)&lc_time->ww_sdatefmt)
      | v44;
  v46 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: ctryid,
          fieldtype: 0x20u,
          address: (void **)&lc_time->ww_ldatefmt)
      | v45;
  v47 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 1,
          localehandle: ctryid,
          fieldtype: 0x1003u,
          address: (void **)&lc_time->ww_timefmt)
      | v46;
  v48 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 0,
          localehandle: ctryid,
          fieldtype: 0x1009u,
          address: (void **)&lc_time->ww_caltype)
      | v47;
  lc_time->ww_lcid = ctryid;
  v49 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x31u,
          address: (void **)&lc_time->_W_wday_abbr[1])
      | v48;
  v50 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x32u,
          address: (void **)&lc_time->_W_wday_abbr[2])
      | v49;
  v51 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x33u,
          address: (void **)&lc_time->_W_wday_abbr[3])
      | v50;
  v52 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x34u,
          address: (void **)&lc_time->_W_wday_abbr[4])
      | v51;
  v53 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x35u,
          address: (void **)&lc_time->_W_wday_abbr[5])
      | v52;
  v54 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x36u,
          address: (void **)&lc_time->_W_wday_abbr[6])
      | v53;
  v55 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x37u,
          address: (void **)lc_time->_W_wday_abbr)
      | v54;
  v56 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x2Au,
          address: (void **)&lc_time->_W_wday[1])
      | v55;
  v57 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x2Bu,
          address: (void **)&lc_time->_W_wday[2])
      | v56;
  v58 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x2Cu,
          address: (void **)&lc_time->_W_wday[3])
      | v57;
  v59 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x2Du,
          address: (void **)&lc_time->_W_wday[4])
      | v58;
  v60 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x2Eu,
          address: (void **)&lc_time->_W_wday[5])
      | v59;
  v61 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x2Fu,
          address: (void **)&lc_time->_W_wday[6])
      | v60;
  v62 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x30u,
          address: (void **)lc_time->_W_wday)
      | v61;
  v63 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x44u,
          address: (void **)lc_time->_W_month_abbr)
      | v62;
  v64 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x45u,
          address: (void **)&lc_time->_W_month_abbr[1])
      | v63;
  v65 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x46u,
          address: (void **)&lc_time->_W_month_abbr[2])
      | v64;
  v66 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x47u,
          address: (void **)&lc_time->_W_month_abbr[3])
      | v65;
  v67 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x48u,
          address: (void **)&lc_time->_W_month_abbr[4])
      | v66;
  v68 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x49u,
          address: (void **)&lc_time->_W_month_abbr[5])
      | v67;
  v69 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x4Au,
          address: (void **)&lc_time->_W_month_abbr[6])
      | v68;
  v70 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x4Bu,
          address: (void **)&lc_time->_W_month_abbr[7])
      | v69;
  v71 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x4Cu,
          address: (void **)&lc_time->_W_month_abbr[8])
      | v70;
  v72 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x4Du,
          address: (void **)&lc_time->_W_month_abbr[9])
      | v71;
  v73 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x4Eu,
          address: (void **)&lc_time->_W_month_abbr[10])
      | v72;
  v74 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x4Fu,
          address: (void **)&lc_time->_W_month_abbr[11])
      | v73;
  v75 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x38u,
          address: (void **)lc_time->_W_month)
      | v74;
  v76 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x39u,
          address: (void **)&lc_time->_W_month[1])
      | v75;
  v77 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x3Au,
          address: (void **)&lc_time->_W_month[2])
      | v76;
  v78 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x3Bu,
          address: (void **)&lc_time->_W_month[3])
      | v77;
  v79 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x3Cu,
          address: (void **)&lc_time->_W_month[4])
      | v78;
  v80 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x3Du,
          address: (void **)&lc_time->_W_month[5])
      | v79;
  v81 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x3Eu,
          address: (void **)&lc_time->_W_month[6])
      | v80;
  v82 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x3Fu,
          address: (void **)&lc_time->_W_month[7])
      | v81;
  v83 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x40u,
          address: (void **)&lc_time->_W_month[8])
      | v82;
  v84 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x41u,
          address: (void **)&lc_time->_W_month[9])
      | v83;
  v85 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x42u,
          address: (void **)&lc_time->_W_month[10])
      | v84;
  v86 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x43u,
          address: (void **)&lc_time->_W_month[11])
      | v85;
  v87 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x28u,
          address: (void **)lc_time->_W_ampm)
      | v86;
  v88 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: wLanguage,
          fieldtype: 0x29u,
          address: (void **)&lc_time->_W_ampm[1])
      | v87;
  v89 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: ctryid,
          fieldtype: 0x1Fu,
          address: (void **)&lc_time->_W_ww_sdatefmt)
      | v88;
  v90 = __getlocaleinfo(
          plocinfo: &locinfo,
          lc_type: 2,
          localehandle: ctryid,
          fieldtype: 0x20u,
          address: (void **)&lc_time->_W_ww_ldatefmt)
      | v89;
  return v90
       | __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 2,
           localehandle: ctryid,
           fieldtype: 0x1003u,
           address: (void **)&lc_time->_W_ww_timefmt);
}

//------------------------------------------------------------------------------
// Address: 0x10031E5B
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
    free(pMem: lc_time->_W_wday_abbr[1]);
    free(pMem: lc_time->_W_wday_abbr[2]);
    free(pMem: lc_time->_W_wday_abbr[3]);
    free(pMem: lc_time->_W_wday_abbr[4]);
    free(pMem: lc_time->_W_wday_abbr[5]);
    free(pMem: lc_time->_W_wday_abbr[6]);
    free(pMem: lc_time->_W_wday_abbr[0]);
    free(pMem: lc_time->_W_wday[1]);
    free(pMem: lc_time->_W_wday[2]);
    free(pMem: lc_time->_W_wday[3]);
    free(pMem: lc_time->_W_wday[4]);
    free(pMem: lc_time->_W_wday[5]);
    free(pMem: lc_time->_W_wday[6]);
    free(pMem: lc_time->_W_wday[0]);
    free(pMem: lc_time->_W_month_abbr[0]);
    free(pMem: lc_time->_W_month_abbr[1]);
    free(pMem: lc_time->_W_month_abbr[2]);
    free(pMem: lc_time->_W_month_abbr[3]);
    free(pMem: lc_time->_W_month_abbr[4]);
    free(pMem: lc_time->_W_month_abbr[5]);
    free(pMem: lc_time->_W_month_abbr[6]);
    free(pMem: lc_time->_W_month_abbr[7]);
    free(pMem: lc_time->_W_month_abbr[8]);
    free(pMem: lc_time->_W_month_abbr[9]);
    free(pMem: lc_time->_W_month_abbr[10]);
    free(pMem: lc_time->_W_month_abbr[11]);
    free(pMem: lc_time->_W_month[0]);
    free(pMem: lc_time->_W_month[1]);
    free(pMem: lc_time->_W_month[2]);
    free(pMem: lc_time->_W_month[3]);
    free(pMem: lc_time->_W_month[4]);
    free(pMem: lc_time->_W_month[5]);
    free(pMem: lc_time->_W_month[6]);
    free(pMem: lc_time->_W_month[7]);
    free(pMem: lc_time->_W_month[8]);
    free(pMem: lc_time->_W_month[9]);
    free(pMem: lc_time->_W_month[10]);
    free(pMem: lc_time->_W_month[11]);
    free(pMem: lc_time->_W_ampm[0]);
    free(pMem: lc_time->_W_ampm[1]);
    free(pMem: lc_time->_W_ww_sdatefmt);
    free(pMem: lc_time->_W_ww_ldatefmt);
    free(pMem: lc_time->_W_ww_timefmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100321D2
// Name: ___init_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_time(threadlocaleinfostruct *ploci)
{
  __lc_time_data *v1; // edi
  __lc_time_data *lc_time_curr; // eax

  if ( ploci->lc_handle[5] != 0 )
  {
    v1 = (__lc_time_data *)calloc(count: 1u, size: 0x164u);
    if ( v1 == nullptr )
      return 1;
    if ( get_lc_time(lc_time: v1, ploci) != 0 )
    {
      __free_lc_time(lc_time: v1);
      free(pMem: v1);
      return 1;
    }
    v1->refcount = 1;
  }
  else
  {
    v1 = &__lc_time_c;
  }
  lc_time_curr = ploci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c )
    InterlockedDecrement(lpAddend: &lc_time_curr->refcount);
  ploci->lc_time_curr = v1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003224F
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_num(lconv *l)
{
  wchar_t *W_thousands_sep; // esi

  if ( l != nullptr )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(pMem: l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(pMem: l->thousands_sep);
    if ( l->grouping != __lconv_c.grouping )
      free(pMem: l->grouping);
    if ( l->_W_decimal_point != __lconv_c._W_decimal_point )
      free(pMem: l->_W_decimal_point);
    W_thousands_sep = l->_W_thousands_sep;
    if ( W_thousands_sep != __lconv_c._W_thousands_sep )
      free(pMem: W_thousands_sep);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100322B8
// Name: ___init_numeric
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_numeric(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // esi
  lconv *v2; // ebx
  int *v4; // eax
  int *v5; // eax
  int v6; // esi
  unsigned int wCountry; // esi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  char *grouping; // eax
  char v13; // cl
  char *v14; // esi
  localeinfo_struct locinfo; // [esp+Ch] [ebp-10h] BYREF
  int *lc_refcount; // [esp+14h] [ebp-8h]
  int *lconv_num_refcount; // [esp+18h] [ebp-4h]

  v1 = ploci;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = nullptr;
  if ( ploci->lc_handle[4] != 0 || ploci->lc_handle[3] != 0 )
  {
    v2 = (lconv *)calloc(count: 1u, size: 0x50u);
    if ( v2 == nullptr )
      return 1;
    qmemcpy(v2, ploci->lconv, sizeof(lconv));
    v4 = (int *)operator new(nSize: 4u);
    lc_refcount = v4;
    if ( v4 == nullptr )
    {
      free(pMem: v2);
      return 1;
    }
    *v4 = 0;
    if ( ploci->lc_handle[4] == 0 )
    {
      v2->decimal_point = __lconv_c.decimal_point;
      v2->thousands_sep = __lconv_c.thousands_sep;
      v2->grouping = __lconv_c.grouping;
      v2->_W_decimal_point = __lconv_c._W_decimal_point;
      lconv_num_refcount = nullptr;
      v2->_W_thousands_sep = __lconv_c._W_thousands_sep;
LABEL_26:
      v1 = ploci;
      *lc_refcount = 1;
      if ( lconv_num_refcount != nullptr )
        *lconv_num_refcount = 1;
      goto LABEL_28;
    }
    v5 = (int *)operator new(nSize: 4u);
    lconv_num_refcount = v5;
    if ( v5 == nullptr )
    {
      v6 = 1;
LABEL_11:
      free(pMem: v2);
      free(pMem: lc_refcount);
      return v6;
    }
    *v5 = 0;
    wCountry = ploci->lc_id[4].wCountry;
    v8 = __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 1,
           localehandle: wCountry,
           fieldtype: 0xEu,
           address: (void **)&v2->decimal_point);
    v9 = __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 1,
           localehandle: wCountry,
           fieldtype: 0xFu,
           address: (void **)&v2->thousands_sep)
       | v8;
    v10 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x10u,
            address: (void **)&v2->grouping)
        | v9;
    v11 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 2,
            localehandle: wCountry,
            fieldtype: 0xEu,
            address: (void **)&v2->_W_decimal_point)
        | v10;
    if ( (v11
        | __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 2,
            localehandle: wCountry,
            fieldtype: 0xFu,
            address: (void **)&v2->_W_thousands_sep)) != 0 )
    {
      __free_lconv_num(l: v2);
      v6 = -1;
      goto LABEL_11;
    }
    grouping = v2->grouping;
    while ( 1 )
    {
      if ( *grouping == 0 )
        goto LABEL_26;
      v13 = *grouping;
      if ( *grouping >= 48 && v13 <= 57 )
        break;
      if ( v13 == 59 )
      {
        v14 = grouping;
        do
        {
          *v14 = v14[1];
          ++v14;
        }
        while ( *v14 != 0 );
      }
      else
      {
LABEL_18:
        ++grouping;
      }
    }
    *grouping = v13 - 48;
    goto LABEL_18;
  }
  lconv_num_refcount = nullptr;
  lc_refcount = nullptr;
  v2 = &__lconv_c;
LABEL_28:
  if ( v1->lconv_num_refcount != nullptr )
    InterlockedDecrement(lpAddend: v1->lconv_num_refcount);
  if ( v1->lconv_intl_refcount != nullptr && InterlockedDecrement(lpAddend: v1->lconv_intl_refcount) == 0 )
  {
    free(pMem: v1->lconv_intl_refcount);
    free(pMem: v1->lconv);
  }
  v1->lconv_num_refcount = lconv_num_refcount;
  v1->lconv_intl_refcount = lc_refcount;
  v1->lconv = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100324A8
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_mon(lconv *l)
{
  wchar_t *W_negative_sign; // esi

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
    if ( l->negative_sign != __lconv_c.negative_sign )
      free(pMem: l->negative_sign);
    if ( l->_W_int_curr_symbol != __lconv_c._W_int_curr_symbol )
      free(pMem: l->_W_int_curr_symbol);
    if ( l->_W_currency_symbol != __lconv_c._W_currency_symbol )
      free(pMem: l->_W_currency_symbol);
    if ( l->_W_mon_decimal_point != __lconv_c._W_mon_decimal_point )
      free(pMem: l->_W_mon_decimal_point);
    if ( l->_W_mon_thousands_sep != __lconv_c._W_mon_thousands_sep )
      free(pMem: l->_W_mon_thousands_sep);
    if ( l->_W_positive_sign != __lconv_c._W_positive_sign )
      free(pMem: l->_W_positive_sign);
    W_negative_sign = l->_W_negative_sign;
    if ( W_negative_sign != __lconv_c._W_negative_sign )
      free(pMem: W_negative_sign);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100325A6
// Name: ___init_monetary
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_monetary(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // esi
  unsigned __int8 *v2; // ebx
  int *v4; // eax
  int *v5; // eax
  unsigned int wCountry; // esi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // edi
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // edi
  char *v27; // eax
  char v28; // cl
  char *v29; // esi
  int *v30; // ecx
  localeinfo_struct locinfo; // [esp+Ch] [ebp-10h] BYREF
  int *lc_refcount; // [esp+14h] [ebp-8h]
  int *lconv_mon_refcount; // [esp+18h] [ebp-4h]

  v1 = ploci;
  lconv_mon_refcount = nullptr;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = nullptr;
  if ( ploci->lc_handle[3] != 0 || ploci->lc_handle[4] != 0 )
  {
    v2 = calloc(count: 1u, size: 0x50u);
    if ( v2 == nullptr )
      return 1;
    v4 = (int *)operator new(nSize: 4u);
    lc_refcount = v4;
    if ( v4 == nullptr )
    {
      free(pMem: v2);
      return 1;
    }
    *v4 = 0;
    if ( ploci->lc_handle[3] == 0 )
    {
      qmemcpy(v2, &__lconv_c, 80);
LABEL_25:
      *(_DWORD *)v2 = ploci->lconv->decimal_point;
      v1 = ploci;
      *((_DWORD *)v2 + 1) = ploci->lconv->thousands_sep;
      *((_DWORD *)v2 + 2) = ploci->lconv->grouping;
      *((_DWORD *)v2 + 12) = ploci->lconv->_W_decimal_point;
      v30 = lc_refcount;
      *((_DWORD *)v2 + 13) = ploci->lconv->_W_thousands_sep;
      *v30 = 1;
      if ( lconv_mon_refcount != nullptr )
        *lconv_mon_refcount = 1;
      goto LABEL_27;
    }
    v5 = (int *)operator new(nSize: 4u);
    lconv_mon_refcount = v5;
    if ( v5 == nullptr )
    {
      free(pMem: v2);
      free(pMem: lc_refcount);
      return 1;
    }
    *v5 = 0;
    wCountry = ploci->lc_id[3].wCountry;
    v7 = __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 1,
           localehandle: wCountry,
           fieldtype: 0x15u,
           address: (void **)v2 + 3);
    v8 = __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 1,
           localehandle: wCountry,
           fieldtype: 0x14u,
           address: (void **)v2 + 4)
       | v7;
    v9 = __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 1,
           localehandle: wCountry,
           fieldtype: 0x16u,
           address: (void **)v2 + 5)
       | v8;
    v10 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x17u,
            address: (void **)v2 + 6)
        | v9;
    v11 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x18u,
            address: (void **)v2 + 7)
        | v10;
    v12 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x50u,
            address: (void **)v2 + 8)
        | v11;
    v13 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 1,
            localehandle: wCountry,
            fieldtype: 0x51u,
            address: (void **)v2 + 9)
        | v12;
    v14 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x1Au,
            address: (void **)v2 + 10)
        | v13;
    v15 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x19u,
            address: (void **)(v2 + 41))
        | v14;
    v16 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x54u,
            address: (void **)(v2 + 42))
        | v15;
    v17 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x55u,
            address: (void **)(v2 + 43))
        | v16;
    v18 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x56u,
            address: (void **)v2 + 11)
        | v17;
    v19 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x57u,
            address: (void **)(v2 + 45))
        | v18;
    v20 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x52u,
            address: (void **)(v2 + 46))
        | v19;
    v21 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 0,
            localehandle: wCountry,
            fieldtype: 0x53u,
            address: (void **)(v2 + 47))
        | v20;
    v22 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 2,
            localehandle: wCountry,
            fieldtype: 0x15u,
            address: (void **)v2 + 14)
        | v21;
    v23 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 2,
            localehandle: wCountry,
            fieldtype: 0x14u,
            address: (void **)v2 + 15)
        | v22;
    v24 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 2,
            localehandle: wCountry,
            fieldtype: 0x16u,
            address: (void **)v2 + 16)
        | v23;
    v25 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 2,
            localehandle: wCountry,
            fieldtype: 0x17u,
            address: (void **)v2 + 17)
        | v24;
    v26 = __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 2,
            localehandle: wCountry,
            fieldtype: 0x50u,
            address: (void **)v2 + 18)
        | v25;
    if ( (v26
        | __getlocaleinfo(
            plocinfo: &locinfo,
            lc_type: 2,
            localehandle: wCountry,
            fieldtype: 0x51u,
            address: (void **)v2 + 19)) != 0 )
    {
      __free_lconv_mon(l: (lconv *)v2);
      free(pMem: v2);
      free(pMem: lc_refcount);
      free(pMem: lconv_mon_refcount);
      return 1;
    }
    v27 = *((char **)v2 + 7);
    while ( 1 )
    {
      if ( *v27 == 0 )
        goto LABEL_25;
      v28 = *v27;
      if ( *v27 >= 48 && v28 <= 57 )
        break;
      if ( v28 == 59 )
      {
        v29 = v27;
        do
        {
          *v29 = v29[1];
          ++v29;
        }
        while ( *v29 != 0 );
      }
      else
      {
LABEL_17:
        ++v27;
      }
    }
    *v27 = v28 - 48;
    goto LABEL_17;
  }
  lconv_mon_refcount = nullptr;
  lc_refcount = nullptr;
  v2 = (unsigned __int8 *)&__lconv_c;
LABEL_27:
  if ( v1->lconv_mon_refcount != nullptr )
    InterlockedDecrement(lpAddend: v1->lconv_mon_refcount);
  if ( v1->lconv_intl_refcount != nullptr && InterlockedDecrement(lpAddend: v1->lconv_intl_refcount) == 0 )
  {
    free(pMem: v1->lconv);
    free(pMem: v1->lconv_intl_refcount);
  }
  v1->lconv_mon_refcount = lconv_mon_refcount;
  v1->lconv_intl_refcount = lc_refcount;
  v1->lconv = (lconv *)v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10032906
// Name: ___init_ctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_ctype(threadlocaleinfostruct *ploci)
{
  int v1; // ebx
  unsigned __int8 *v2; // eax
  int j; // eax
  unsigned __int8 *v4; // eax
  int v5; // ecx
  int v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // edi
  unsigned __int16 *v9; // ecx
  bool v10; // cc
  unsigned __int8 *v11; // edx
  unsigned __int16 *v12; // ecx
  unsigned __int8 v13; // dl
  unsigned int v14; // ecx
  unsigned __int8 *k; // ecx
  int *v16; // eax
  unsigned int lc_codepage; // [esp-Ch] [ebp-64h]
  localeinfo_struct locinfo; // [esp+Ch] [ebp-4Ch] BYREF
  const unsigned __int8 *v20; // [esp+14h] [ebp-44h]
  const unsigned __int16 *v21; // [esp+18h] [ebp-40h]
  unsigned __int16 *v22; // [esp+1Ch] [ebp-3Ch]
  const unsigned __int8 *v23; // [esp+20h] [ebp-38h]
  unsigned __int8 *v24; // [esp+24h] [ebp-34h]
  int mb_cur_max; // [esp+28h] [ebp-30h]
  int *refcount; // [esp+2Ch] [ebp-2Ch]
  unsigned __int8 *newcumap; // [esp+30h] [ebp-28h]
  unsigned __int8 *cbuffer; // [esp+34h] [ebp-24h]
  int i; // [esp+38h] [ebp-20h]
  unsigned __int16 *newctype1; // [esp+3Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+40h] [ebp-18h] BYREF

  v1 = 0;
  refcount = nullptr;
  newctype1 = nullptr;
  i = 0;
  newcumap = nullptr;
  cbuffer = nullptr;
  locinfo.locinfo = ploci;
  locinfo.mbcinfo = nullptr;
  if ( ploci->lc_handle[2] != 0 )
  {
    if ( ploci->lc_codepage == 0
      && __getlocaleinfo(
           plocinfo: &locinfo,
           lc_type: 0,
           localehandle: ploci->lc_id[2].wLanguage,
           fieldtype: 0x1004u,
           address: (void **)&ploci->lc_codepage) != 0 )
    {
      goto error_cleanup_0;
    }
    refcount = (int *)operator new(nSize: 4u);
    newctype1 = (unsigned __int16 *)calloc(count: 0x180u, size: 2u);
    i = (int)calloc(count: 0x180u, size: 1u);
    newcumap = calloc(count: 0x180u, size: 1u);
    v2 = calloc(count: 0x101u, size: 1u);
    cbuffer = v2;
    if ( refcount == nullptr )
      goto error_cleanup_0;
    if ( newctype1 == nullptr )
      goto error_cleanup_0;
    if ( v2 == nullptr )
      goto error_cleanup_0;
    if ( i == 0 )
      goto error_cleanup_0;
    if ( newcumap == nullptr )
      goto error_cleanup_0;
    *refcount = 0;
    for ( j = 0; j < 256; ++j )
      cbuffer[j] = j;
    if ( !GetCPInfo(CodePage: ploci->lc_codepage, &lpCPInfo) || lpCPInfo.MaxCharSize > 5 )
      goto error_cleanup_0;
    mb_cur_max = LOWORD(lpCPInfo.MaxCharSize);
    if ( LOWORD(lpCPInfo.MaxCharSize) > 1u && lpCPInfo.LeadByte[0] != 0 )
    {
      v4 = &lpCPInfo.LeadByte[1];
      do
      {
        LOBYTE(v5) = *v4;
        if ( *v4 == 0 )
          break;
        v6 = *(v4 - 1);
        v5 = (unsigned __int8)v5;
        while ( v6 <= v5 )
        {
          cbuffer[v6] = 32;
          v5 = *v4;
          ++v6;
        }
        v4 += 2;
      }
      while ( *(v4 - 1) != 0 );
    }
    lc_codepage = ploci->lc_codepage;
    v21 = newctype1 + 128;
    if ( __crtGetStringTypeA(
           plocinfo: nullptr,
           dwInfoType: 1u,
           lpSrcStr: (const char *)cbuffer,
           cchSrc: 256,
           lpCharType: newctype1 + 128,
           code_page: lc_codepage,
           lcid: 0,
           bError: 0) != 0
      && __crtLCMapStringA(
           plocinfo: nullptr,
           Locale: ploci->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: (const char *)cbuffer + 1,
           cchSrc: 255,
           lpDestStr: (char *)(i + 129),
           cchDest: 255,
           code_page: ploci->lc_codepage,
           bError: 0) != 0
      && __crtLCMapStringA(
           plocinfo: nullptr,
           Locale: ploci->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: (const char *)cbuffer + 1,
           cchSrc: 255,
           lpDestStr: (char *)newcumap + 129,
           cchDest: 255,
           code_page: ploci->lc_codepage,
           bError: 0) != 0 )
    {
      v7 = (unsigned __int8 *)newctype1;
      v8 = (unsigned __int8 *)i;
      v9 = newctype1 + 127;
      v10 = mb_cur_max <= 1;
      newctype1[127] = 0;
      v11 = newcumap;
      v22 = v9;
      v8[127] = 0;
      v11[127] = 0;
      v8[128] = 0;
      v20 = v8 + 128;
      v23 = v11 + 128;
      v11[128] = 0;
      if ( !v10 && lpCPInfo.LeadByte[0] != 0 )
      {
        v12 = (unsigned __int16 *)&lpCPInfo.LeadByte[1];
        newctype1 = (unsigned __int16 *)&lpCPInfo.LeadByte[1];
        do
        {
          v13 = *(_BYTE *)v12;
          if ( *(_BYTE *)v12 == 0 )
            break;
          v14 = *((unsigned __int8 *)v12 - 1);
          i = v14;
          if ( v14 <= v13 )
          {
            for ( k = &v7[2 * v14 + 256]; ; k = v24 )
            {
              ++i;
              *(_WORD *)k = 0x8000;
              v24 = k + 2;
              if ( i > *(unsigned __int8 *)newctype1 )
                break;
            }
          }
          v12 = newctype1 + 1;
          newctype1 = v12;
        }
        while ( *((_BYTE *)v12 - 1) != 0 );
      }
      memcpy(dst: v7, src: v7 + 512, count: 0xFEu);
      memcpy(dst: v8, src: v8 + 256, count: 0x7Fu);
      memcpy(dst: newcumap, src: newcumap + 256, count: 0x7Fu);
      if ( ploci->ctype1_refcount != nullptr && InterlockedDecrement(lpAddend: ploci->ctype1_refcount) == 0 )
      {
        free(pMem: ploci->ctype1 - 127);
        free(pMem: (void *)(ploci->pclmap - 128));
        free(pMem: (void *)(ploci->pcumap - 128));
        free(pMem: ploci->ctype1_refcount);
      }
      v16 = refcount;
      *refcount = 1;
      ploci->ctype1_refcount = v16;
      ploci->pctype = v21;
      ploci->ctype1 = v22;
      ploci->pclmap = v20;
      ploci->pcumap = v23;
      ploci->mb_cur_max = mb_cur_max;
    }
    else
    {
error_cleanup_0:
      free(pMem: refcount);
      free(pMem: newctype1);
      free(pMem: (void *)i);
      free(pMem: newcumap);
      v1 = 1;
    }
    free(pMem: cbuffer);
    return v1;
  }
  else
  {
    if ( ploci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ploci->ctype1_refcount);
    ploci->ctype1_refcount = nullptr;
    ploci->ctype1 = nullptr;
    ploci->pctype = asc_10046B90;
    ploci->pclmap = &__newclmap[128];
    ploci->pcumap = &__newcumap[128];
    ploci->mb_cur_max = 1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032CAD
// Name: ____lc_codepage_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl ___lc_codepage_func()
{
  _tiddata *v0; // ecx
  threadlocaleinfostruct *ptlocinfo; // eax

  v0 = _getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != __ptlocinfo && (__globallocalestatus & v0->_ownlocale) == 0 )
    ptlocinfo = __updatetlocinfo();
  return ptlocinfo->lc_codepage;
}

//------------------------------------------------------------------------------
// Address: 0x10032CD3
// Name: _strcat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcat_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  const char *v6; // edx
  char *v7; // esi
  int v8; // esi
  char v9; // al

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInBytes;
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
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v8 = v7 - _Src;
      do
      {
        v9 = *v6;
        v6[v8] = *v6;
        ++v6;
        if ( v9 == 0 )
          break;
        --v3;
      }
      while ( v3 != 0 );
      if ( v3 == 0 )
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
  _invalid_parameter_noinfo();
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10032D40
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
// Address: 0x10032D86
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src, unsigned int _Count)
{
  unsigned int v5; // edi
  int v6; // esi
  const char *v7; // edx
  char *v8; // ecx
  char v9; // cl
  char v10; // dl

  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v6;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  v5 = _SizeInBytes;
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
      v7[_Dst - _Src] = *v7;
      ++v7;
      if ( v9 == 0 )
        break;
      --v5;
    }
    while ( v5 != 0 );
  }
  else
  {
    do
    {
      v10 = v8[_Src - _Dst];
      *v8++ = v10;
      if ( v10 == 0 )
        break;
      if ( --v5 == 0 )
        break;
      --_Count;
    }
    while ( _Count != 0 );
    if ( _Count == 0 )
      *v8 = 0;
  }
  if ( v5 != 0 )
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
// Address: 0x10032E3B
// Name: TranslateName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl TranslateName(const tagLOCALETAB *lpTable, int high, const char **ppchName)
{
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  const tagLOCALETAB *v6; // edi

  v3 = 0;
  v4 = 1;
  while ( v3 <= high )
  {
    if ( v4 == 0 )
      break;
    v5 = (v3 + high) / 2;
    v6 = &lpTable[v5];
    v4 = _stricmp(dst: *ppchName, src: v6->szName);
    if ( v4 != 0 )
    {
      if ( v4 >= 0 )
        v3 = v5 + 1;
      else
        high = v5 - 1;
    }
    else
    {
      *ppchName = v6->chAbbrev;
    }
  }
  return v4 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10032E9D
// Name: ProcessCodePage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __usercall ProcessCodePage@<eax>(char *lpCodePageStr@<esi>, setloc_struct *_psetloc_data@<edi>, int a3@<ecx>)
{
  int v3; // eax
  int v4; // eax
  int iCodePage; // [esp+0h] [ebp-4h] BYREF

  iCodePage = a3;
  if ( lpCodePageStr != nullptr && *lpCodePageStr != 0 )
  {
    strcmp(str1: (unsigned __int8 *)lpCodePageStr, str2: "ACP");
    if ( v3 != 0 )
    {
      strcmp(str1: (unsigned __int8 *)lpCodePageStr, str2: "OCP");
      if ( v4 != 0 )
        return atol(nptr: lpCodePageStr);
      if ( GetLocaleInfoW(
             Locale: _psetloc_data->lcidCountry,
             LCType: 0x2000000Bu,
             lpLCData: (LPWSTR)&iCodePage,
             cchData: 2) != 0 )
        return iCodePage;
      return 0;
    }
  }
  if ( GetLocaleInfoW(Locale: _psetloc_data->lcidCountry, LCType: 0x20001004u, lpLCData: (LPWSTR)&iCodePage, cchData: 2) == 0 )
    return 0;
  if ( iCodePage != 0 )
    return iCodePage;
  return GetACP();
}

//------------------------------------------------------------------------------
// Address: 0x10032F21
// Name: TestDefaultCountry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl TestDefaultCountry(__int16 lcid)
{
  int v1; // eax

  v1 = 0;
  while ( lcid != __rglangidNotDefault[v1] )
  {
    if ( (unsigned int)++v1 >= 10 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10032F46
// Name: LcidFromHexString
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall LcidFromHexString(int a1, char *lpHexString)
{
  int i; // esi
  char v3; // cl

  for ( i = 0; ; i = v3 + 16 * i - 48 )
  {
    v3 = *lpHexString;
    if ( *lpHexString == 0 )
      break;
    ++lpHexString;
    if ( (unsigned __int8)(v3 - 97) > 5u )
    {
      if ( (unsigned __int8)(v3 - 65) <= 5u )
        v3 -= 7;
    }
    else
    {
      v3 -= 39;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10032F77
// Name: GetPrimaryLen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall GetPrimaryLen(int a1, char *pchLanguage)
{
  int result; // eax
  char v3; // cl

  for ( result = 0; ; ++result )
  {
    v3 = *pchLanguage++;
    if ( (v3 < 65 || v3 > 90) && (unsigned __int8)(v3 - 97) > 0x19u )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032F92
// Name: CountryEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CountryEnumProc(char *lpLcidString)
{
  _tiddata *v1; // esi
  int v2; // ecx
  int v3; // edi
  char rgcInfo[120]; // [esp+8h] [ebp-7Ch] BYREF

  v1 = _getptd();
  v3 = LcidFromHexString(a1: v2, lpHexString: lpLcidString);
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: v1->_setloc_data.bAbbrevCountry != 0 ? 7 : 4098,
         lpLCData: rgcInfo,
         cchData: 120) != 0 )
  {
    if ( _stricmp(dst: v1->_setloc_data.pchCountry, src: rgcInfo) == 0 && TestDefaultCountry(lcid: v3) != 0 )
    {
      v1->_setloc_data.iLcidState |= 4u;
      v1->_setloc_data.lcidCountry = v3;
      v1->_setloc_data.lcidLanguage = v3;
    }
    return (v1->_setloc_data.iLcidState & 4) == 0;
  }
  else
  {
    v1->_setloc_data.iLcidState = 0;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033039
// Name: TestDefaultLanguage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall TestDefaultLanguage@<eax>(unsigned int lcid@<eax>, int bTestPrimary, setloc_struct *_psetloc_data)
{
  int v4; // ecx
  BOOL result; // eax
  char *pchLanguage; // esi
  int PrimaryLen; // edi
  int v8; // eax
  unsigned int dwLanguage; // [esp+4h] [ebp-4h] BYREF

  result = false;
  if ( GetLocaleInfoW(Locale: lcid & 0x3FF | 0x400, LCType: 0x20000001u, lpLCData: (LPWSTR)&dwLanguage, cchData: 2) != 0 )
  {
    if ( lcid == dwLanguage )
      return true;
    if ( bTestPrimary == 0 )
      return true;
    pchLanguage = _psetloc_data->pchLanguage;
    PrimaryLen = GetPrimaryLen(a1: v4, pchLanguage: _psetloc_data->pchLanguage);
    strlen(buf: pchLanguage);
    if ( PrimaryLen != v8 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033094
// Name: LangCountryEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall LangCountryEnumProc(char *lpLcidString)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  int v3; // edi
  int v5; // eax
  int v6; // edx
  int v7; // eax
  BOOL v8; // eax
  char *pchLanguage; // [esp-4h] [ebp-8Ch]
  char rgcInfo[120]; // [esp+Ch] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = LcidFromHexString(a1: v2, lpHexString: lpLcidString);
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: p_setloc_data->bAbbrevCountry != 0 ? 7 : 4098,
         lpLCData: rgcInfo,
         cchData: 120) == 0 )
    goto LABEL_2;
  if ( _stricmp(dst: p_setloc_data->pchCountry, src: rgcInfo) == 0 )
  {
    if ( GetLocaleInfoA(
           Locale: v3,
           LCType: p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097,
           lpLCData: rgcInfo,
           cchData: 120) == 0 )
      goto LABEL_2;
    if ( _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) == 0 )
    {
      p_setloc_data->iLcidState |= 0x304u;
      p_setloc_data->lcidLanguage = v3;
LABEL_15:
      p_setloc_data->lcidCountry = v3;
      goto LABEL_16;
    }
    if ( (p_setloc_data->iLcidState & 2) != 0 )
      goto LABEL_16;
    if ( p_setloc_data->iPrimaryLen != 0
      && _strnicmp(dst: p_setloc_data->pchLanguage, src: rgcInfo, count: p_setloc_data->iPrimaryLen) == 0 )
    {
      pchLanguage = p_setloc_data->pchLanguage;
      p_setloc_data->iLcidState |= 2u;
      p_setloc_data->lcidCountry = v3;
      strlen(buf: pchLanguage);
      if ( v5 == p_setloc_data->iPrimaryLen )
        p_setloc_data->lcidLanguage = v3;
    }
    else if ( (p_setloc_data->iLcidState & 1) == 0 && TestDefaultCountry(lcid: v3) != 0 )
    {
      p_setloc_data->iLcidState = v6 | 1;
      goto LABEL_15;
    }
  }
LABEL_16:
  if ( (p_setloc_data->iLcidState & 0x300) == 0x300 )
    return (p_setloc_data->iLcidState & 4) == 0;
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097,
         lpLCData: rgcInfo,
         cchData: 120) == 0 )
  {
LABEL_2:
    p_setloc_data->iLcidState = 0;
    return 1;
  }
  if ( _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) == 0 )
  {
    p_setloc_data->iLcidState |= 0x200u;
    if ( p_setloc_data->bAbbrevLanguage != 0 )
    {
      p_setloc_data->iLcidState |= 0x100u;
      goto LABEL_30;
    }
    if ( p_setloc_data->iPrimaryLen == 0 || (strlen(buf: p_setloc_data->pchLanguage), v7 != p_setloc_data->iPrimaryLen) )
    {
LABEL_29:
      p_setloc_data->iLcidState |= 0x100u;
LABEL_30:
      if ( p_setloc_data->lcidLanguage == 0 )
        p_setloc_data->lcidLanguage = v3;
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v8 = TestDefaultLanguage(lcid: v3, bTestPrimary: 1, _psetloc_data: p_setloc_data);
  }
  else
  {
    if ( p_setloc_data->bAbbrevLanguage != 0
      || p_setloc_data->iPrimaryLen == 0
      || _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) != 0 )
    {
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v8 = TestDefaultLanguage(lcid: v3, bTestPrimary: 0, _psetloc_data: p_setloc_data);
  }
  if ( v8 )
    goto LABEL_29;
  return (p_setloc_data->iLcidState & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10033265
// Name: LanguageEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall LanguageEnumProc(char *lpLcidString)
{
  setloc_struct *p_setloc_data; // esi
  int v2; // ecx
  LCID v3; // edi
  BOOL v5; // eax
  char rgcInfo[120]; // [esp+8h] [ebp-7Ch] BYREF

  p_setloc_data = &_getptd()->_setloc_data;
  v3 = LcidFromHexString(a1: v2, lpHexString: lpLcidString);
  if ( GetLocaleInfoA(
         Locale: v3,
         LCType: p_setloc_data->bAbbrevLanguage != 0 ? 3 : 4097,
         lpLCData: rgcInfo,
         cchData: 120) == 0 )
  {
    p_setloc_data->iLcidState = 0;
    return 1;
  }
  if ( _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) == 0 )
  {
    if ( p_setloc_data->bAbbrevLanguage != 0 )
    {
LABEL_11:
      p_setloc_data->iLcidState |= 4u;
      p_setloc_data->lcidLanguage = v3;
      p_setloc_data->lcidCountry = v3;
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v5 = TestDefaultLanguage(lcid: v3, bTestPrimary: 1, _psetloc_data: p_setloc_data);
  }
  else
  {
    if ( p_setloc_data->bAbbrevLanguage != 0
      || p_setloc_data->iPrimaryLen == 0
      || _stricmp(dst: p_setloc_data->pchLanguage, src: rgcInfo) != 0 )
    {
      return (p_setloc_data->iLcidState & 4) == 0;
    }
    v5 = TestDefaultLanguage(lcid: v3, bTestPrimary: 0, _psetloc_data: p_setloc_data);
  }
  if ( v5 )
    goto LABEL_11;
  return (p_setloc_data->iLcidState & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10033325
// Name: GetLcidFromLangCountry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall GetLcidFromLangCountry(setloc_struct *_psetloc_data@<esi>)
{
  int v1; // eax
  int v2; // eax
  bool v3; // zf
  int PrimaryLen; // eax
  int iLcidState; // eax
  char *pchCountry; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  strlen(buf: _psetloc_data->pchLanguage);
  pchCountry = _psetloc_data->pchCountry;
  _psetloc_data->bAbbrevLanguage = v1 == 3;
  strlen(buf: pchCountry);
  _psetloc_data->lcidLanguage = 0;
  v3 = _psetloc_data->bAbbrevLanguage == 0;
  _psetloc_data->bAbbrevCountry = v2 == 3;
  if ( v3 )
    PrimaryLen = GetPrimaryLen(a1: v7, pchLanguage: _psetloc_data->pchLanguage);
  else
    PrimaryLen = 2;
  _psetloc_data->iPrimaryLen = PrimaryLen;
  EnumSystemLocalesA(lpLocaleEnumProc: LangCountryEnumProc, dwFlags: 1u);
  iLcidState = _psetloc_data->iLcidState;
  if ( (iLcidState & 0x100) == 0 || (iLcidState & 0x200) == 0 || (iLcidState & 7) == 0 )
    _psetloc_data->iLcidState = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003338C
// Name: GetLcidFromLanguage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall GetLcidFromLanguage(setloc_struct *_psetloc_data@<esi>)
{
  int v1; // eax
  BOOL v2; // eax
  int PrimaryLen; // eax
  int v4; // [esp-4h] [ebp-4h]

  strlen(buf: _psetloc_data->pchLanguage);
  v2 = v1 == 3;
  _psetloc_data->bAbbrevLanguage = v2;
  if ( v2 )
    PrimaryLen = 2;
  else
    PrimaryLen = GetPrimaryLen(a1: v4, pchLanguage: _psetloc_data->pchLanguage);
  _psetloc_data->iPrimaryLen = PrimaryLen;
  EnumSystemLocalesA(lpLocaleEnumProc: LanguageEnumProc, dwFlags: 1u);
  if ( (_psetloc_data->iLcidState & 4) == 0 )
    _psetloc_data->iLcidState = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100333C8
// Name: ___get_qualified_locale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __get_qualified_locale(tagLC_STRINGS *const lpInStr, tagLC_ID *lpOutId, tagLC_STRINGS *lpOutStr)
{
  setloc_struct *p_setloc_data; // edi
  char **p_pchCountry; // ebx
  char *pchLanguage; // eax
  int v6; // ecx
  char *v7; // ebx
  char *v8; // ebx
  int v9; // eax
  LCID UserDefaultLCID; // eax
  UINT v11; // eax
  unsigned __int16 v12; // si
  int iCodePage; // [esp+14h] [ebp+8h]

  p_setloc_data = &_getptd()->_setloc_data;
  if ( lpInStr == nullptr )
  {
    p_setloc_data->iLcidState |= 0x104u;
LABEL_23:
    UserDefaultLCID = GetUserDefaultLCID();
    p_setloc_data->lcidLanguage = UserDefaultLCID;
    p_setloc_data->lcidCountry = UserDefaultLCID;
    goto LABEL_24;
  }
  p_setloc_data->pchLanguage = (char *)lpInStr;
  p_pchCountry = &p_setloc_data->pchCountry;
  p_setloc_data->pchCountry = lpInStr->szCountry;
  if ( lpInStr != (tagLC_STRINGS *const)-64 && lpInStr->szCountry[0] != 0 )
    TranslateName(lpTable: __rg_country, high: 22, ppchName: (const char **)&p_setloc_data->pchCountry);
  pchLanguage = p_setloc_data->pchLanguage;
  p_setloc_data->iLcidState = 0;
  if ( pchLanguage == nullptr || *pchLanguage == 0 )
  {
    v8 = *p_pchCountry;
    if ( v8 == nullptr || *v8 == 0 )
    {
      p_setloc_data->iLcidState = 260;
      goto LABEL_23;
    }
    strlen(buf: v8);
    p_setloc_data->bAbbrevCountry = v9 == 3;
    EnumSystemLocalesA(lpLocaleEnumProc: CountryEnumProc, dwFlags: 1u);
    if ( (p_setloc_data->iLcidState & 4) == 0 )
      p_setloc_data->iLcidState = 0;
LABEL_24:
    if ( p_setloc_data->iLcidState == 0 )
      return 0;
    goto LABEL_25;
  }
  if ( *p_pchCountry != nullptr && **p_pchCountry != 0 )
    GetLcidFromLangCountry(_psetloc_data: p_setloc_data);
  else
    GetLcidFromLanguage(_psetloc_data: p_setloc_data);
  if ( p_setloc_data->iLcidState == 0 )
  {
    if ( TranslateName(lpTable: __rg_language, high: 64, ppchName: (const char **)&p_setloc_data->pchLanguage) )
    {
      v7 = *p_pchCountry;
      if ( v7 != nullptr && *v7 != 0 )
        GetLcidFromLangCountry(_psetloc_data: p_setloc_data);
      else
        GetLcidFromLanguage(_psetloc_data: p_setloc_data);
    }
    goto LABEL_24;
  }
LABEL_25:
  v11 = ProcessCodePage(
          lpCodePageStr: lpInStr != nullptr ? lpInStr->szCodePage : nullptr,
          _psetloc_data: p_setloc_data,
          a3: v6);
  v12 = v11;
  iCodePage = v11;
  if ( v11 == 0
    || v11 == 65000
    || v11 == 65001
    || !IsValidCodePage(CodePage: (unsigned __int16)v11)
    || !IsValidLocale(Locale: p_setloc_data->lcidLanguage, dwFlags: 1u) )
  {
    return 0;
  }
  if ( lpOutId != nullptr )
  {
    lpOutId->wLanguage = p_setloc_data->lcidLanguage;
    lpOutId->wCountry = p_setloc_data->lcidCountry;
    lpOutId->wCodePage = v12;
  }
  if ( lpOutStr == nullptr )
    return 1;
  if ( lpOutId->wLanguage == 2068 )
  {
    if ( strcpy_s(_Dst: lpOutStr->szLanguage, _SizeInBytes: 0x40u, _Src: "Norwegian-Nynorsk") != 0 )
      _invoke_watson(a1: (unsigned int)p_setloc_data);
  }
  else if ( GetLocaleInfoA(
              Locale: p_setloc_data->lcidLanguage,
              LCType: 0x1001u,
              lpLCData: lpOutStr->szLanguage,
              cchData: 64) == 0 )
  {
    return 0;
  }
  if ( GetLocaleInfoA(Locale: p_setloc_data->lcidCountry, LCType: 0x1002u, lpLCData: lpOutStr->szCountry, cchData: 64) != 0 )
  {
    _itoa_s(val: iCodePage, buf: lpOutStr->szCodePage, sizeInTChars: 0x10u, radix: 10);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100335B9
// Name: _memcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl memcmp(unsigned __int8 *lhs, unsigned __int8 *rhs, unsigned int siz)
{
  unsigned int v3; // edi
  unsigned __int8 *v4; // ecx
  unsigned __int8 *v5; // eax
  BOOL v6; // ebx
  int v7; // esi
  BOOL v8; // ebx
  BOOL v9; // ebx
  BOOL v10; // ebx
  BOOL v11; // ebx
  BOOL v12; // ebx
  BOOL v13; // ebx
  BOOL v14; // ebx
  BOOL v15; // ebx
  BOOL v16; // ebx
  BOOL v17; // ebx
  BOOL v18; // ebx
  BOOL v19; // ebx
  BOOL v20; // ebx
  BOOL v21; // ebx
  BOOL v22; // ebx
  BOOL v23; // ebx
  BOOL v24; // ebx
  BOOL v25; // ebx
  BOOL v26; // ebx
  BOOL v27; // ebx
  BOOL v28; // ebx
  BOOL v29; // ebx
  BOOL v30; // ebx
  unsigned __int8 *v31; // eax
  unsigned __int8 *v32; // kr00_4
  unsigned __int8 *v33; // kr04_4
  unsigned __int8 *v34; // ecx
  int result; // eax
  int v36; // edx
  BOOL v37; // edx
  BOOL v38; // edx
  BOOL v39; // edx
  int v40; // edx
  BOOL v41; // edx
  BOOL v42; // edx
  BOOL v43; // edx
  int v44; // edx
  BOOL v45; // edx
  BOOL v46; // edx
  BOOL v47; // edx
  int v48; // edx
  BOOL v49; // edx
  BOOL v50; // edx
  BOOL v51; // edx
  BOOL v52; // edx
  BOOL v53; // edx
  BOOL v54; // edx
  int v55; // edx
  BOOL v56; // edx
  BOOL v57; // edx
  BOOL v58; // edx
  int v59; // edx
  int v60; // esi
  int v61; // edx
  int v62; // edx
  BOOL v63; // edx
  BOOL v64; // edx
  BOOL v65; // edx
  int v66; // edx
  BOOL v67; // edx
  BOOL v68; // edx
  BOOL v69; // edx
  int v70; // edx
  BOOL v71; // edx
  BOOL v72; // edx
  BOOL v73; // edx
  int v74; // edx
  BOOL v75; // edx
  BOOL v76; // edx
  BOOL v77; // edx
  int v78; // edx
  BOOL v79; // edx
  BOOL v80; // edx
  BOOL v81; // edx
  BOOL v82; // edx
  BOOL v83; // edx
  BOOL v84; // edx
  int v85; // edx
  BOOL v86; // edx
  BOOL v87; // edx
  BOOL v88; // edx
  int v89; // edx
  BOOL v90; // edx
  BOOL v91; // edx
  BOOL v92; // edx
  int v93; // edx
  BOOL v94; // edx
  BOOL v95; // edx
  BOOL v96; // edx
  int v97; // edx
  BOOL v98; // edx
  BOOL v99; // edx
  BOOL v100; // edx
  int v101; // edx
  BOOL v102; // edx
  BOOL v103; // edx
  BOOL v104; // edx
  int v105; // edx
  BOOL v106; // edx
  BOOL v107; // edx
  BOOL v108; // edx
  BOOL v109; // edx
  BOOL v110; // edx
  BOOL v111; // edx
  int v112; // edx
  BOOL v113; // edx
  BOOL v114; // edx
  BOOL v115; // edx
  int v116; // edx
  BOOL v117; // edx
  BOOL v118; // edx
  BOOL v119; // edx
  int v120; // edx
  BOOL v121; // edx
  BOOL v122; // edx
  BOOL v123; // edx
  int v124; // edx
  BOOL v125; // edx
  BOOL v126; // edx
  BOOL v127; // edx
  int v128; // edx
  BOOL v129; // edx
  BOOL v130; // edx
  BOOL v131; // edx
  BOOL v132; // edx
  BOOL v133; // edx
  BOOL v134; // edx
  int v135; // edx
  BOOL v136; // edx
  BOOL v137; // edx
  BOOL v138; // edx
  int v139; // edx
  BOOL v140; // edx
  BOOL v141; // edx
  BOOL v142; // edx
  BOOL v143; // edx
  BOOL v144; // edx
  BOOL v145; // edx
  int v146; // eax
  int v147; // ecx
  BOOL v148; // edx
  BOOL v149; // edx
  BOOL v150; // edx

  v3 = siz;
  switch ( siz )
  {
    case 0u:
      return 0;
    case 1u:
      v146 = *lhs;
      v147 = *rhs;
LABEL_425:
      result = v146 - v147;
      if ( result != 0 )
        return 2 * (result > 0) - 1;
      return result;
    case 2u:
      if ( *lhs != *rhs )
      {
        v150 = *lhs > (unsigned int)*rhs;
        result = 2 * v150 - 1;
        if ( 2 * v150 != 1 )
          return result;
      }
      v146 = lhs[1];
      v147 = rhs[1];
      goto LABEL_425;
    case 3u:
      if ( *lhs != *rhs )
      {
        v148 = *lhs > (unsigned int)*rhs;
        result = 2 * v148 - 1;
        if ( 2 * v148 != 1 )
          return result;
      }
      if ( lhs[1] != rhs[1] )
      {
        v149 = lhs[1] > (unsigned int)rhs[1];
        result = 2 * v149 - 1;
        if ( 2 * v149 != 1 )
          return result;
      }
      v146 = lhs[2];
      v147 = rhs[2];
      goto LABEL_425;
    case 4u:
      if ( *lhs != *rhs )
      {
        v143 = *lhs > (unsigned int)*rhs;
        result = 2 * v143 - 1;
        if ( 2 * v143 != 1 )
          return result;
      }
      if ( lhs[1] != rhs[1] )
      {
        v144 = lhs[1] > (unsigned int)rhs[1];
        result = 2 * v144 - 1;
        if ( 2 * v144 != 1 )
          return result;
      }
      if ( lhs[2] != rhs[2] )
      {
        v145 = lhs[2] > (unsigned int)rhs[2];
        result = 2 * v145 - 1;
        if ( 2 * v145 != 1 )
          return result;
      }
      v146 = lhs[3];
      v147 = rhs[3];
      goto LABEL_425;
    default:
      break;
  }
  v4 = rhs;
  v5 = lhs;
  while ( 2 )
  {
    v32 = v5;
    v33 = v4;
    v31 = &v5[v3];
    v34 = &v4[v3];
    switch ( v3 )
    {
      case 0u:
        return 0;
      case 1u:
        goto $LN103;
      case 2u:
        goto $LN88_1;
      case 3u:
        goto $LN73;
      case 4u:
        goto $LN120;
      case 5u:
        goto $LN105_0;
      case 6u:
        goto $LN90;
      case 7u:
        goto $LN75_1;
      case 8u:
        goto $LN122_0;
      case 9u:
        goto $LN107;
      case 0xAu:
        goto $LN92;
      case 0xBu:
        goto $LN77;
      case 0xCu:
        goto $LN124;
      case 0xDu:
        goto $LN109;
      case 0xEu:
        goto $LN94;
      case 0xFu:
        goto $LN79;
      case 0x10u:
        goto $LN126;
      case 0x11u:
        goto $LN111;
      case 0x12u:
        goto $LN96_0;
      case 0x13u:
        goto $LN81;
      case 0x14u:
        goto $LN128;
      case 0x15u:
        goto $LN113_0;
      case 0x16u:
        goto $LN98;
      case 0x17u:
        goto $LN83;
      case 0x18u:
        goto $LN130_1;
      case 0x19u:
        goto $LN115;
      case 0x1Au:
        goto $LN100;
      case 0x1Bu:
        goto $LN85;
      case 0x1Cu:
        v36 = *((_DWORD *)v31 - 7);
        if ( v36 == *((_DWORD *)v34 - 7) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v36 != *(v34 - 28) )
          {
            v37 = (unsigned __int8)v36 > (unsigned int)*(v34 - 28);
            v7 = 2 * v37 - 1;
            if ( 2 * v37 != 1 )
              return v7;
          }
          if ( *(v31 - 27) != *(v34 - 27) )
          {
            v38 = *(v31 - 27) > (unsigned int)*(v34 - 27);
            v7 = 2 * v38 - 1;
            if ( 2 * v38 != 1 )
              return v7;
          }
          if ( *(v31 - 26) != *(v34 - 26) )
          {
            v39 = *(v31 - 26) > (unsigned int)*(v34 - 26);
            v7 = 2 * v39 - 1;
            if ( 2 * v39 != 1 )
              return v7;
          }
          v7 = *(v31 - 25) - *(v34 - 25);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 25) > (unsigned int)*(v34 - 25)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN130_1:
        v40 = *((_DWORD *)v31 - 6);
        if ( v40 == *((_DWORD *)v34 - 6) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v40 != *(v34 - 24) )
          {
            v41 = (unsigned __int8)v40 > (unsigned int)*(v34 - 24);
            v7 = 2 * v41 - 1;
            if ( 2 * v41 != 1 )
              return v7;
          }
          if ( *(v31 - 23) != *(v34 - 23) )
          {
            v42 = *(v31 - 23) > (unsigned int)*(v34 - 23);
            v7 = 2 * v42 - 1;
            if ( 2 * v42 != 1 )
              return v7;
          }
          if ( *(v31 - 22) != *(v34 - 22) )
          {
            v43 = *(v31 - 22) > (unsigned int)*(v34 - 22);
            v7 = 2 * v43 - 1;
            if ( 2 * v43 != 1 )
              return v7;
          }
          v7 = *(v31 - 21) - *(v34 - 21);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 21) > (unsigned int)*(v34 - 21)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN128:
        v44 = *((_DWORD *)v31 - 5);
        if ( v44 == *((_DWORD *)v34 - 5) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v44 != *(v34 - 20) )
          {
            v45 = (unsigned __int8)v44 > (unsigned int)*(v34 - 20);
            v7 = 2 * v45 - 1;
            if ( 2 * v45 != 1 )
              return v7;
          }
          if ( *(v31 - 19) != *(v34 - 19) )
          {
            v46 = *(v31 - 19) > (unsigned int)*(v34 - 19);
            v7 = 2 * v46 - 1;
            if ( 2 * v46 != 1 )
              return v7;
          }
          if ( *(v31 - 18) != *(v34 - 18) )
          {
            v47 = *(v31 - 18) > (unsigned int)*(v34 - 18);
            v7 = 2 * v47 - 1;
            if ( 2 * v47 != 1 )
              return v7;
          }
          v7 = *(v31 - 17) - *(v34 - 17);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 17) > (unsigned int)*(v34 - 17)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN126:
        v48 = *((_DWORD *)v31 - 4);
        if ( v48 == *((_DWORD *)v34 - 4) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v48 != *(v34 - 16) )
          {
            v49 = (unsigned __int8)v48 > (unsigned int)*(v34 - 16);
            v7 = 2 * v49 - 1;
            if ( 2 * v49 != 1 )
              return v7;
          }
          if ( *(v31 - 15) != *(v34 - 15) )
          {
            v50 = *(v31 - 15) > (unsigned int)*(v34 - 15);
            v7 = 2 * v50 - 1;
            if ( 2 * v50 != 1 )
              return v7;
          }
          if ( *(v31 - 14) != *(v34 - 14) )
          {
            v51 = *(v31 - 14) > (unsigned int)*(v34 - 14);
            v7 = 2 * v51 - 1;
            if ( 2 * v51 != 1 )
              return v7;
          }
          v7 = *(v31 - 13) - *(v34 - 13);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 13) > (unsigned int)*(v34 - 13)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN124:
        if ( *((_DWORD *)v31 - 3) == *((_DWORD *)v34 - 3) )
        {
          v7 = 0;
        }
        else
        {
          if ( *(v31 - 12) != *(v34 - 12) )
          {
            v52 = *(v31 - 12) > (unsigned int)*(v34 - 12);
            v7 = 2 * v52 - 1;
            if ( 2 * v52 != 1 )
              return v7;
          }
          if ( *(v31 - 11) != *(v34 - 11) )
          {
            v53 = *(v31 - 11) > (unsigned int)*(v34 - 11);
            v7 = 2 * v53 - 1;
            if ( 2 * v53 != 1 )
              return v7;
          }
          if ( *(v31 - 10) != *(v34 - 10) )
          {
            v54 = *(v31 - 10) > (unsigned int)*(v34 - 10);
            v7 = 2 * v54 - 1;
            if ( 2 * v54 != 1 )
              return v7;
          }
          v7 = *(v31 - 9) - *(v34 - 9);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 9) > (unsigned int)*(v34 - 9)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN122_0:
        v55 = *((_DWORD *)v31 - 2);
        if ( v55 == *((_DWORD *)v34 - 2) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v55 != *(v34 - 8) )
          {
            v56 = (unsigned __int8)v55 > (unsigned int)*(v34 - 8);
            v7 = 2 * v56 - 1;
            if ( 2 * v56 != 1 )
              return v7;
          }
          if ( *(v31 - 7) != *(v34 - 7) )
          {
            v57 = *(v31 - 7) > (unsigned int)*(v34 - 7);
            v7 = 2 * v57 - 1;
            if ( 2 * v57 != 1 )
              return v7;
          }
          if ( *(v31 - 6) != *(v34 - 6) )
          {
            v58 = *(v31 - 6) > (unsigned int)*(v34 - 6);
            v7 = 2 * v58 - 1;
            if ( 2 * v58 != 1 )
              return v7;
          }
          v7 = *(v31 - 5) - *(v34 - 5);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 5) > (unsigned int)*(v34 - 5)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN120:
        v59 = *((_DWORD *)v31 - 1);
        if ( v59 == *((_DWORD *)v34 - 1) )
        {
          result = 0;
        }
        else
        {
          v60 = (unsigned __int8)v59 - *(v34 - 4);
          if ( (v60 == 0 || (v61 = 2 * ((unsigned __int8)v59 > (unsigned int)*(v34 - 4)) - 1, 2 * (v60 > 0) == 1))
            && (*(v31 - 3) == *(v34 - 3)
             || (v61 = 2 * (*(v31 - 3) > (unsigned int)*(v34 - 3)) - 1, 2 * (*(v31 - 3) > (unsigned int)*(v34 - 3)) == 1))
            && (*(v31 - 2) == *(v34 - 2)
             || (v61 = 2 * (*(v31 - 2) > (unsigned int)*(v34 - 2)) - 1, 2 * (*(v31 - 2) > (unsigned int)*(v34 - 2)) == 1)) )
          {
            result = *(v31 - 1) - *(v34 - 1);
            if ( result != 0 )
              result = 2 * (result > 0) - 1;
          }
          else
          {
            result = v61;
          }
        }
        if ( result == 0 )
          return 0;
        return result;
      case 0x1Du:
        v62 = *(_DWORD *)(v31 - 29);
        if ( v62 == *(_DWORD *)(v34 - 29) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v62 != *(v34 - 29) )
          {
            v63 = (unsigned __int8)v62 > (unsigned int)*(v34 - 29);
            v7 = 2 * v63 - 1;
            if ( 2 * v63 != 1 )
              return v7;
          }
          if ( *(v31 - 28) != *(v34 - 28) )
          {
            v64 = *(v31 - 28) > (unsigned int)*(v34 - 28);
            v7 = 2 * v64 - 1;
            if ( 2 * v64 != 1 )
              return v7;
          }
          if ( *(v31 - 27) != *(v34 - 27) )
          {
            v65 = *(v31 - 27) > (unsigned int)*(v34 - 27);
            v7 = 2 * v65 - 1;
            if ( 2 * v65 != 1 )
              return v7;
          }
          v7 = *(v31 - 26) - *(v34 - 26);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 26) > (unsigned int)*(v34 - 26)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN115:
        v66 = *(_DWORD *)(v31 - 25);
        if ( v66 == *(_DWORD *)(v34 - 25) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v66 != *(v34 - 25) )
          {
            v67 = (unsigned __int8)v66 > (unsigned int)*(v34 - 25);
            v7 = 2 * v67 - 1;
            if ( 2 * v67 != 1 )
              return v7;
          }
          if ( *(v31 - 24) != *(v34 - 24) )
          {
            v68 = *(v31 - 24) > (unsigned int)*(v34 - 24);
            v7 = 2 * v68 - 1;
            if ( 2 * v68 != 1 )
              return v7;
          }
          if ( *(v31 - 23) != *(v34 - 23) )
          {
            v69 = *(v31 - 23) > (unsigned int)*(v34 - 23);
            v7 = 2 * v69 - 1;
            if ( 2 * v69 != 1 )
              return v7;
          }
          v7 = *(v31 - 22) - *(v34 - 22);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 22) > (unsigned int)*(v34 - 22)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN113_0:
        v70 = *(_DWORD *)(v31 - 21);
        if ( v70 == *(_DWORD *)(v34 - 21) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v70 != *(v34 - 21) )
          {
            v71 = (unsigned __int8)v70 > (unsigned int)*(v34 - 21);
            v7 = 2 * v71 - 1;
            if ( 2 * v71 != 1 )
              return v7;
          }
          if ( *(v31 - 20) != *(v34 - 20) )
          {
            v72 = *(v31 - 20) > (unsigned int)*(v34 - 20);
            v7 = 2 * v72 - 1;
            if ( 2 * v72 != 1 )
              return v7;
          }
          if ( *(v31 - 19) != *(v34 - 19) )
          {
            v73 = *(v31 - 19) > (unsigned int)*(v34 - 19);
            v7 = 2 * v73 - 1;
            if ( 2 * v73 != 1 )
              return v7;
          }
          v7 = *(v31 - 18) - *(v34 - 18);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 18) > (unsigned int)*(v34 - 18)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN111:
        v74 = *(_DWORD *)(v31 - 17);
        if ( v74 == *(_DWORD *)(v34 - 17) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v74 != *(v34 - 17) )
          {
            v75 = (unsigned __int8)v74 > (unsigned int)*(v34 - 17);
            v7 = 2 * v75 - 1;
            if ( 2 * v75 != 1 )
              return v7;
          }
          if ( *(v31 - 16) != *(v34 - 16) )
          {
            v76 = *(v31 - 16) > (unsigned int)*(v34 - 16);
            v7 = 2 * v76 - 1;
            if ( 2 * v76 != 1 )
              return v7;
          }
          if ( *(v31 - 15) != *(v34 - 15) )
          {
            v77 = *(v31 - 15) > (unsigned int)*(v34 - 15);
            v7 = 2 * v77 - 1;
            if ( 2 * v77 != 1 )
              return v7;
          }
          v7 = *(v31 - 14) - *(v34 - 14);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 14) > (unsigned int)*(v34 - 14)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN109:
        v78 = *(_DWORD *)(v31 - 13);
        if ( v78 == *(_DWORD *)(v34 - 13) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v78 != *(v34 - 13) )
          {
            v79 = (unsigned __int8)v78 > (unsigned int)*(v34 - 13);
            v7 = 2 * v79 - 1;
            if ( 2 * v79 != 1 )
              return v7;
          }
          if ( *(v31 - 12) != *(v34 - 12) )
          {
            v80 = *(v31 - 12) > (unsigned int)*(v34 - 12);
            v7 = 2 * v80 - 1;
            if ( 2 * v80 != 1 )
              return v7;
          }
          if ( *(v31 - 11) != *(v34 - 11) )
          {
            v81 = *(v31 - 11) > (unsigned int)*(v34 - 11);
            v7 = 2 * v81 - 1;
            if ( 2 * v81 != 1 )
              return v7;
          }
          v7 = *(v31 - 10) - *(v34 - 10);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 10) > (unsigned int)*(v34 - 10)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN107:
        if ( *(_DWORD *)(v31 - 9) == *(_DWORD *)(v34 - 9) )
        {
          v7 = 0;
        }
        else
        {
          if ( *(v31 - 9) != *(v34 - 9) )
          {
            v82 = *(v31 - 9) > (unsigned int)*(v34 - 9);
            v7 = 2 * v82 - 1;
            if ( 2 * v82 != 1 )
              return v7;
          }
          if ( *(v31 - 8) != *(v34 - 8) )
          {
            v83 = *(v31 - 8) > (unsigned int)*(v34 - 8);
            v7 = 2 * v83 - 1;
            if ( 2 * v83 != 1 )
              return v7;
          }
          if ( *(v31 - 7) != *(v34 - 7) )
          {
            v84 = *(v31 - 7) > (unsigned int)*(v34 - 7);
            v7 = 2 * v84 - 1;
            if ( 2 * v84 != 1 )
              return v7;
          }
          v7 = *(v31 - 6) - *(v34 - 6);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 6) > (unsigned int)*(v34 - 6)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN105_0:
        v85 = *(_DWORD *)(v31 - 5);
        if ( v85 == *(_DWORD *)(v34 - 5) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v85 != *(v34 - 5) )
          {
            v86 = (unsigned __int8)v85 > (unsigned int)*(v34 - 5);
            v7 = 2 * v86 - 1;
            if ( 2 * v86 != 1 )
              return v7;
          }
          if ( *(v31 - 4) != *(v34 - 4) )
          {
            v87 = *(v31 - 4) > (unsigned int)*(v34 - 4);
            v7 = 2 * v87 - 1;
            if ( 2 * v87 != 1 )
              return v7;
          }
          if ( *(v31 - 3) != *(v34 - 3) )
          {
            v88 = *(v31 - 3) > (unsigned int)*(v34 - 3);
            v7 = 2 * v88 - 1;
            if ( 2 * v88 != 1 )
              return v7;
          }
          v7 = *(v31 - 2) - *(v34 - 2);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 2) > (unsigned int)*(v34 - 2)) - 1;
        }
        if ( v7 != 0 )
          return v7;
        goto $LN103;
      case 0x1Eu:
        v89 = *(_DWORD *)(v31 - 30);
        if ( v89 == *(_DWORD *)(v34 - 30) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v89 != *(v34 - 30) )
          {
            v90 = (unsigned __int8)v89 > (unsigned int)*(v34 - 30);
            v7 = 2 * v90 - 1;
            if ( 2 * v90 != 1 )
              return v7;
          }
          if ( *(v31 - 29) != *(v34 - 29) )
          {
            v91 = *(v31 - 29) > (unsigned int)*(v34 - 29);
            v7 = 2 * v91 - 1;
            if ( 2 * v91 != 1 )
              return v7;
          }
          if ( *(v31 - 28) != *(v34 - 28) )
          {
            v92 = *(v31 - 28) > (unsigned int)*(v34 - 28);
            v7 = 2 * v92 - 1;
            if ( 2 * v92 != 1 )
              return v7;
          }
          v7 = *(v31 - 27) - *(v34 - 27);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 27) > (unsigned int)*(v34 - 27)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN100:
        v93 = *(_DWORD *)(v31 - 26);
        if ( v93 == *(_DWORD *)(v34 - 26) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v93 != *(v34 - 26) )
          {
            v94 = (unsigned __int8)v93 > (unsigned int)*(v34 - 26);
            v7 = 2 * v94 - 1;
            if ( 2 * v94 != 1 )
              return v7;
          }
          if ( *(v31 - 25) != *(v34 - 25) )
          {
            v95 = *(v31 - 25) > (unsigned int)*(v34 - 25);
            v7 = 2 * v95 - 1;
            if ( 2 * v95 != 1 )
              return v7;
          }
          if ( *(v31 - 24) != *(v34 - 24) )
          {
            v96 = *(v31 - 24) > (unsigned int)*(v34 - 24);
            v7 = 2 * v96 - 1;
            if ( 2 * v96 != 1 )
              return v7;
          }
          v7 = *(v31 - 23) - *(v34 - 23);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 23) > (unsigned int)*(v34 - 23)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN98:
        v97 = *(_DWORD *)(v31 - 22);
        if ( v97 == *(_DWORD *)(v34 - 22) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v97 != *(v34 - 22) )
          {
            v98 = (unsigned __int8)v97 > (unsigned int)*(v34 - 22);
            v7 = 2 * v98 - 1;
            if ( 2 * v98 != 1 )
              return v7;
          }
          if ( *(v31 - 21) != *(v34 - 21) )
          {
            v99 = *(v31 - 21) > (unsigned int)*(v34 - 21);
            v7 = 2 * v99 - 1;
            if ( 2 * v99 != 1 )
              return v7;
          }
          if ( *(v31 - 20) != *(v34 - 20) )
          {
            v100 = *(v31 - 20) > (unsigned int)*(v34 - 20);
            v7 = 2 * v100 - 1;
            if ( 2 * v100 != 1 )
              return v7;
          }
          v7 = *(v31 - 19) - *(v34 - 19);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 19) > (unsigned int)*(v34 - 19)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN96_0:
        v101 = *(_DWORD *)(v31 - 18);
        if ( v101 == *(_DWORD *)(v34 - 18) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v101 != *(v34 - 18) )
          {
            v102 = (unsigned __int8)v101 > (unsigned int)*(v34 - 18);
            v7 = 2 * v102 - 1;
            if ( 2 * v102 != 1 )
              return v7;
          }
          if ( *(v31 - 17) != *(v34 - 17) )
          {
            v103 = *(v31 - 17) > (unsigned int)*(v34 - 17);
            v7 = 2 * v103 - 1;
            if ( 2 * v103 != 1 )
              return v7;
          }
          if ( *(v31 - 16) != *(v34 - 16) )
          {
            v104 = *(v31 - 16) > (unsigned int)*(v34 - 16);
            v7 = 2 * v104 - 1;
            if ( 2 * v104 != 1 )
              return v7;
          }
          v7 = *(v31 - 15) - *(v34 - 15);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 15) > (unsigned int)*(v34 - 15)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN94:
        v105 = *(_DWORD *)(v31 - 14);
        if ( v105 == *(_DWORD *)(v34 - 14) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v105 != *(v34 - 14) )
          {
            v106 = (unsigned __int8)v105 > (unsigned int)*(v34 - 14);
            v7 = 2 * v106 - 1;
            if ( 2 * v106 != 1 )
              return v7;
          }
          if ( *(v31 - 13) != *(v34 - 13) )
          {
            v107 = *(v31 - 13) > (unsigned int)*(v34 - 13);
            v7 = 2 * v107 - 1;
            if ( 2 * v107 != 1 )
              return v7;
          }
          if ( *(v31 - 12) != *(v34 - 12) )
          {
            v108 = *(v31 - 12) > (unsigned int)*(v34 - 12);
            v7 = 2 * v108 - 1;
            if ( 2 * v108 != 1 )
              return v7;
          }
          v7 = *(v31 - 11) - *(v34 - 11);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 11) > (unsigned int)*(v34 - 11)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN92:
        if ( *(_DWORD *)(v31 - 10) == *(_DWORD *)(v34 - 10) )
        {
          v7 = 0;
        }
        else
        {
          if ( *(v31 - 10) != *(v34 - 10) )
          {
            v109 = *(v31 - 10) > (unsigned int)*(v34 - 10);
            v7 = 2 * v109 - 1;
            if ( 2 * v109 != 1 )
              return v7;
          }
          if ( *(v31 - 9) != *(v34 - 9) )
          {
            v110 = *(v31 - 9) > (unsigned int)*(v34 - 9);
            v7 = 2 * v110 - 1;
            if ( 2 * v110 != 1 )
              return v7;
          }
          if ( *(v31 - 8) != *(v34 - 8) )
          {
            v111 = *(v31 - 8) > (unsigned int)*(v34 - 8);
            v7 = 2 * v111 - 1;
            if ( 2 * v111 != 1 )
              return v7;
          }
          v7 = *(v31 - 7) - *(v34 - 7);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 7) > (unsigned int)*(v34 - 7)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN90:
        v112 = *(_DWORD *)(v31 - 6);
        if ( v112 == *(_DWORD *)(v34 - 6) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v112 != *(v34 - 6) )
          {
            v113 = (unsigned __int8)v112 > (unsigned int)*(v34 - 6);
            v7 = 2 * v113 - 1;
            if ( 2 * v113 != 1 )
              return v7;
          }
          if ( *(v31 - 5) != *(v34 - 5) )
          {
            v114 = *(v31 - 5) > (unsigned int)*(v34 - 5);
            v7 = 2 * v114 - 1;
            if ( 2 * v114 != 1 )
              return v7;
          }
          if ( *(v31 - 4) != *(v34 - 4) )
          {
            v115 = *(v31 - 4) > (unsigned int)*(v34 - 4);
            v7 = 2 * v115 - 1;
            if ( 2 * v115 != 1 )
              return v7;
          }
          v7 = *(v31 - 3) - *(v34 - 3);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 3) > (unsigned int)*(v34 - 3)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN88_1:
        if ( *((_WORD *)v31 - 1) == *((_WORD *)v34 - 1) )
          return 0;
        goto LABEL_335;
      case 0x1Fu:
        if ( *(_DWORD *)(v31 - 31) == *(_DWORD *)(v34 - 31) )
        {
          v7 = 0;
        }
        else
        {
          if ( *(v31 - 31) != *(v34 - 31) )
          {
            v117 = *(v31 - 31) > (unsigned int)*(v34 - 31);
            v7 = 2 * v117 - 1;
            if ( 2 * v117 != 1 )
              return v7;
          }
          if ( *(v31 - 30) != *(v34 - 30) )
          {
            v118 = *(v31 - 30) > (unsigned int)*(v34 - 30);
            v7 = 2 * v118 - 1;
            if ( 2 * v118 != 1 )
              return v7;
          }
          if ( *(v31 - 29) != *(v34 - 29) )
          {
            v119 = *(v31 - 29) > (unsigned int)*(v34 - 29);
            v7 = 2 * v119 - 1;
            if ( 2 * v119 != 1 )
              return v7;
          }
          v7 = *(v31 - 28) - *(v34 - 28);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 28) > (unsigned int)*(v34 - 28)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN85:
        v120 = *(_DWORD *)(v31 - 27);
        if ( v120 == *(_DWORD *)(v34 - 27) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v120 != *(v34 - 27) )
          {
            v121 = (unsigned __int8)v120 > (unsigned int)*(v34 - 27);
            v7 = 2 * v121 - 1;
            if ( 2 * v121 != 1 )
              return v7;
          }
          if ( *(v31 - 26) != *(v34 - 26) )
          {
            v122 = *(v31 - 26) > (unsigned int)*(v34 - 26);
            v7 = 2 * v122 - 1;
            if ( 2 * v122 != 1 )
              return v7;
          }
          if ( *(v31 - 25) != *(v34 - 25) )
          {
            v123 = *(v31 - 25) > (unsigned int)*(v34 - 25);
            v7 = 2 * v123 - 1;
            if ( 2 * v123 != 1 )
              return v7;
          }
          v7 = *(v31 - 24) - *(v34 - 24);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 24) > (unsigned int)*(v34 - 24)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN83:
        v124 = *(_DWORD *)(v31 - 23);
        if ( v124 == *(_DWORD *)(v34 - 23) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v124 != *(v34 - 23) )
          {
            v125 = (unsigned __int8)v124 > (unsigned int)*(v34 - 23);
            v7 = 2 * v125 - 1;
            if ( 2 * v125 != 1 )
              return v7;
          }
          if ( *(v31 - 22) != *(v34 - 22) )
          {
            v126 = *(v31 - 22) > (unsigned int)*(v34 - 22);
            v7 = 2 * v126 - 1;
            if ( 2 * v126 != 1 )
              return v7;
          }
          if ( *(v31 - 21) != *(v34 - 21) )
          {
            v127 = *(v31 - 21) > (unsigned int)*(v34 - 21);
            v7 = 2 * v127 - 1;
            if ( 2 * v127 != 1 )
              return v7;
          }
          v7 = *(v31 - 20) - *(v34 - 20);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 20) > (unsigned int)*(v34 - 20)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN81:
        v128 = *(_DWORD *)(v31 - 19);
        if ( v128 == *(_DWORD *)(v34 - 19) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v128 != *(v34 - 19) )
          {
            v129 = (unsigned __int8)v128 > (unsigned int)*(v34 - 19);
            v7 = 2 * v129 - 1;
            if ( 2 * v129 != 1 )
              return v7;
          }
          if ( *(v31 - 18) != *(v34 - 18) )
          {
            v130 = *(v31 - 18) > (unsigned int)*(v34 - 18);
            v7 = 2 * v130 - 1;
            if ( 2 * v130 != 1 )
              return v7;
          }
          if ( *(v31 - 17) != *(v34 - 17) )
          {
            v131 = *(v31 - 17) > (unsigned int)*(v34 - 17);
            v7 = 2 * v131 - 1;
            if ( 2 * v131 != 1 )
              return v7;
          }
          v7 = *(v31 - 16) - *(v34 - 16);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 16) > (unsigned int)*(v34 - 16)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN79:
        if ( *(_DWORD *)(v31 - 15) == *(_DWORD *)(v34 - 15) )
        {
          v7 = 0;
        }
        else
        {
          if ( *(v31 - 15) != *(v34 - 15) )
          {
            v132 = *(v31 - 15) > (unsigned int)*(v34 - 15);
            v7 = 2 * v132 - 1;
            if ( 2 * v132 != 1 )
              return v7;
          }
          if ( *(v31 - 14) != *(v34 - 14) )
          {
            v133 = *(v31 - 14) > (unsigned int)*(v34 - 14);
            v7 = 2 * v133 - 1;
            if ( 2 * v133 != 1 )
              return v7;
          }
          if ( *(v31 - 13) != *(v34 - 13) )
          {
            v134 = *(v31 - 13) > (unsigned int)*(v34 - 13);
            v7 = 2 * v134 - 1;
            if ( 2 * v134 != 1 )
              return v7;
          }
          v7 = *(v31 - 12) - *(v34 - 12);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 12) > (unsigned int)*(v34 - 12)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN77:
        v135 = *(_DWORD *)(v31 - 11);
        if ( v135 == *(_DWORD *)(v34 - 11) )
        {
          v7 = 0;
        }
        else
        {
          if ( (unsigned __int8)v135 != *(v34 - 11) )
          {
            v136 = (unsigned __int8)v135 > (unsigned int)*(v34 - 11);
            v7 = 2 * v136 - 1;
            if ( 2 * v136 != 1 )
              return v7;
          }
          if ( *(v31 - 10) != *(v34 - 10) )
          {
            v137 = *(v31 - 10) > (unsigned int)*(v34 - 10);
            v7 = 2 * v137 - 1;
            if ( 2 * v137 != 1 )
              return v7;
          }
          if ( *(v31 - 9) != *(v34 - 9) )
          {
            v138 = *(v31 - 9) > (unsigned int)*(v34 - 9);
            v7 = 2 * v138 - 1;
            if ( 2 * v138 != 1 )
              return v7;
          }
          v7 = *(v31 - 8) - *(v34 - 8);
          if ( v7 != 0 )
            v7 = 2 * (*(v31 - 8) > (unsigned int)*(v34 - 8)) - 1;
        }
        if ( v7 != 0 )
          return v7;
$LN75_1:
        v139 = *(_DWORD *)(v31 - 7);
        if ( v139 != *(_DWORD *)(v34 - 7) )
        {
          if ( (unsigned __int8)v139 == *(v34 - 7)
            || (v140 = (unsigned __int8)v139 > (unsigned int)*(v34 - 7), v7 = 2 * v140 - 1, 2 * v140 == 1) )
          {
            if ( *(v31 - 6) == *(v34 - 6)
              || (v141 = *(v31 - 6) > (unsigned int)*(v34 - 6), v7 = 2 * v141 - 1, 2 * v141 == 1) )
            {
              if ( *(v31 - 5) == *(v34 - 5)
                || (v142 = *(v31 - 5) > (unsigned int)*(v34 - 5), v7 = 2 * v142 - 1, 2 * v142 == 1) )
              {
                v7 = *(v31 - 4) - *(v34 - 4);
                if ( v7 != 0 )
                  v7 = 2 * (*(v31 - 4) > (unsigned int)*(v34 - 4)) - 1;
                goto LABEL_414;
              }
            }
          }
          return v7;
        }
        v7 = 0;
LABEL_414:
        if ( v7 != 0 )
          return v7;
$LN73:
        if ( *(v31 - 3) != *(v34 - 3) )
        {
          v116 = 2 * (*(v31 - 3) > (unsigned int)*(v34 - 3)) - 1;
          if ( 2 * (*(v31 - 3) > (unsigned int)*(v34 - 3)) != 1 )
            return v116;
        }
LABEL_335:
        if ( *(v31 - 2) != *(v34 - 2) )
        {
          v116 = 2 * (*(v31 - 2) > (unsigned int)*(v34 - 2)) - 1;
          if ( 2 * (*(v31 - 2) > (unsigned int)*(v34 - 2)) != 1 )
            return v116;
        }
$LN103:
        result = *(v31 - 1) - *(v34 - 1);
        if ( result != 0 )
          return 2 * (result > 0) - 1;
        return result;
      default:
        if ( *(_DWORD *)v32 == *(_DWORD *)v33 )
        {
          v7 = 0;
        }
        else
        {
          if ( *v32 != *v33 )
          {
            v6 = *v32 > (unsigned int)*v33;
            v7 = 2 * v6 - 1;
            if ( 2 * v6 != 1 )
              return v7;
          }
          if ( v32[1] != v33[1] )
          {
            v8 = v32[1] > (unsigned int)v33[1];
            v7 = 2 * v8 - 1;
            if ( 2 * v8 != 1 )
              return v7;
          }
          if ( v32[2] != v33[2] )
          {
            v9 = v32[2] > (unsigned int)v33[2];
            v7 = 2 * v9 - 1;
            if ( 2 * v9 != 1 )
              return v7;
          }
          v7 = v32[3] - v33[3];
          if ( v7 != 0 )
            v7 = 2 * (v32[3] > (unsigned int)v33[3]) - 1;
        }
        if ( v7 != 0 )
          return v7;
        if ( *((_DWORD *)v32 + 1) == *((_DWORD *)v33 + 1) )
        {
          v7 = 0;
        }
        else
        {
          if ( v32[4] != v33[4] )
          {
            v10 = v32[4] > (unsigned int)v33[4];
            v7 = 2 * v10 - 1;
            if ( 2 * v10 != 1 )
              return v7;
          }
          if ( v32[5] != v33[5] )
          {
            v11 = v32[5] > (unsigned int)v33[5];
            v7 = 2 * v11 - 1;
            if ( 2 * v11 != 1 )
              return v7;
          }
          if ( v32[6] != v33[6] )
          {
            v12 = v32[6] > (unsigned int)v33[6];
            v7 = 2 * v12 - 1;
            if ( 2 * v12 != 1 )
              return v7;
          }
          v7 = v32[7] - v33[7];
          if ( v7 != 0 )
            v7 = 2 * (v32[7] > (unsigned int)v33[7]) - 1;
        }
        if ( v7 != 0 )
          return v7;
        if ( *((_DWORD *)v32 + 2) == *((_DWORD *)v33 + 2) )
        {
          v7 = 0;
        }
        else
        {
          if ( v32[8] != v33[8] )
          {
            v13 = v32[8] > (unsigned int)v33[8];
            v7 = 2 * v13 - 1;
            if ( 2 * v13 != 1 )
              return v7;
          }
          if ( v32[9] != v33[9] )
          {
            v14 = v32[9] > (unsigned int)v33[9];
            v7 = 2 * v14 - 1;
            if ( 2 * v14 != 1 )
              return v7;
          }
          if ( v32[10] != v33[10] )
          {
            v15 = v32[10] > (unsigned int)v33[10];
            v7 = 2 * v15 - 1;
            if ( 2 * v15 != 1 )
              return v7;
          }
          v7 = v32[11] - v33[11];
          if ( v7 != 0 )
            v7 = 2 * (v32[11] > (unsigned int)v33[11]) - 1;
        }
        if ( v7 != 0 )
          return v7;
        if ( *((_DWORD *)v32 + 3) == *((_DWORD *)v33 + 3) )
        {
          v7 = 0;
        }
        else
        {
          if ( v32[12] != v33[12] )
          {
            v16 = v32[12] > (unsigned int)v33[12];
            v7 = 2 * v16 - 1;
            if ( 2 * v16 != 1 )
              return v7;
          }
          if ( v32[13] != v33[13] )
          {
            v17 = v32[13] > (unsigned int)v33[13];
            v7 = 2 * v17 - 1;
            if ( 2 * v17 != 1 )
              return v7;
          }
          if ( v32[14] != v33[14] )
          {
            v18 = v32[14] > (unsigned int)v33[14];
            v7 = 2 * v18 - 1;
            if ( 2 * v18 != 1 )
              return v7;
          }
          v7 = v32[15] - v33[15];
          if ( v7 != 0 )
            v7 = 2 * (v32[15] > (unsigned int)v33[15]) - 1;
        }
        if ( v7 != 0 )
          return v7;
        if ( *((_DWORD *)v32 + 4) == *((_DWORD *)v33 + 4) )
        {
          v7 = 0;
        }
        else
        {
          if ( v32[16] != v33[16] )
          {
            v19 = v32[16] > (unsigned int)v33[16];
            v7 = 2 * v19 - 1;
            if ( 2 * v19 != 1 )
              return v7;
          }
          if ( v32[17] != v33[17] )
          {
            v20 = v32[17] > (unsigned int)v33[17];
            v7 = 2 * v20 - 1;
            if ( 2 * v20 != 1 )
              return v7;
          }
          if ( v32[18] != v33[18] )
          {
            v21 = v32[18] > (unsigned int)v33[18];
            v7 = 2 * v21 - 1;
            if ( 2 * v21 != 1 )
              return v7;
          }
          v7 = v32[19] - v33[19];
          if ( v7 != 0 )
            v7 = 2 * (v32[19] > (unsigned int)v33[19]) - 1;
        }
        if ( v7 != 0 )
          return v7;
        if ( *((_DWORD *)v32 + 5) == *((_DWORD *)v33 + 5) )
        {
          v7 = 0;
        }
        else
        {
          if ( v32[20] != v33[20] )
          {
            v22 = v32[20] > (unsigned int)v33[20];
            v7 = 2 * v22 - 1;
            if ( 2 * v22 != 1 )
              return v7;
          }
          if ( v32[21] != v33[21] )
          {
            v23 = v32[21] > (unsigned int)v33[21];
            v7 = 2 * v23 - 1;
            if ( 2 * v23 != 1 )
              return v7;
          }
          if ( v32[22] != v33[22] )
          {
            v24 = v32[22] > (unsigned int)v33[22];
            v7 = 2 * v24 - 1;
            if ( 2 * v24 != 1 )
              return v7;
          }
          v7 = v32[23] - v33[23];
          if ( v7 != 0 )
            v7 = 2 * (v32[23] > (unsigned int)v33[23]) - 1;
        }
        if ( v7 != 0 )
          return v7;
        if ( *((_DWORD *)v32 + 6) == *((_DWORD *)v33 + 6) )
        {
          v7 = 0;
        }
        else
        {
          if ( v32[24] != v33[24] )
          {
            v25 = v32[24] > (unsigned int)v33[24];
            v7 = 2 * v25 - 1;
            if ( 2 * v25 != 1 )
              return v7;
          }
          if ( v32[25] != v33[25] )
          {
            v26 = v32[25] > (unsigned int)v33[25];
            v7 = 2 * v26 - 1;
            if ( 2 * v26 != 1 )
              return v7;
          }
          if ( v32[26] != v33[26] )
          {
            v27 = v32[26] > (unsigned int)v33[26];
            v7 = 2 * v27 - 1;
            if ( 2 * v27 != 1 )
              return v7;
          }
          v7 = v32[27] - v33[27];
          if ( v7 != 0 )
            v7 = 2 * (v32[27] > (unsigned int)v33[27]) - 1;
        }
        if ( v7 != 0 )
          return v7;
        if ( *((_DWORD *)v32 + 7) == *((_DWORD *)v33 + 7) )
        {
          v7 = 0;
        }
        else
        {
          if ( v32[28] != v33[28] )
          {
            v28 = v32[28] > (unsigned int)v33[28];
            v7 = 2 * v28 - 1;
            if ( 2 * v28 != 1 )
              return v7;
          }
          if ( v32[29] != v33[29] )
          {
            v29 = v32[29] > (unsigned int)v33[29];
            v7 = 2 * v29 - 1;
            if ( 2 * v29 != 1 )
              return v7;
          }
          if ( v32[30] != v33[30] )
          {
            v30 = v32[30] > (unsigned int)v33[30];
            v7 = 2 * v30 - 1;
            if ( 2 * v30 != 1 )
              return v7;
          }
          v7 = v32[31] - v33[31];
          if ( v7 != 0 )
            v7 = 2 * (v32[31] > (unsigned int)v33[31]) - 1;
        }
        if ( v7 != 0 )
          return v7;
        v5 = v32 + 32;
        v4 = v33 + 32;
        v3 -= 32;
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034B0D
// Name: __crtGetStringTypeA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetStringTypeA_stat(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        int bError)
{
  wchar_t *v7; // ebx
  int v8; // eax
  int v9; // edi
  unsigned int v11; // eax
  void *v12; // esp
  wchar_t *v13; // eax
  int v14; // eax
  _DWORD v15[3]; // [esp+0h] [ebp-14h] BYREF
  int retval2; // [esp+Ch] [ebp-8h]

  v7 = nullptr;
  retval2 = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v8 = MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 8 * (bError != 0) + 1,
         lpMultiByteStr: lpSrcStr,
         cbMultiByte: cchSrc,
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  v9 = v8;
  if ( v8 == 0 )
    return 0;
  if ( v8 > 0 && (unsigned int)v8 <= 0x7FFFFFF0 )
  {
    v11 = 2 * v8 + 8;
    if ( v11 > 0x400 )
    {
      v13 = (wchar_t *)operator new(nSize: 2 * v9 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_12;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (wchar_t *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_12:
        v13 += 4;
      }
    }
    v7 = v13;
  }
  if ( v7 == nullptr )
    return 0;
  memset(dst: (int)v7, value: nullptr, count: 2 * v9);
  v14 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 1u,
          lpMultiByteStr: lpSrcStr,
          cbMultiByte: cchSrc,
          lpWideCharStr: v7,
          cchWideChar: v9);
  if ( v14 != 0 )
    retval2 = GetStringTypeW(dwInfoType, lpSrcStr: v7, cchSrc: v14, lpCharType);
  _freea(_Memory: v7);
  return retval2;
}

//------------------------------------------------------------------------------
// Address: 0x10034BF4
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(
             plocinfo: &_loc_update.localeinfo,
             dwInfoType,
             lpSrcStr,
             cchSrc,
             lpCharType,
             code_page,
             bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034C40
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
// Address: 0x10034C80
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void *enull)
{
  ctrlc_action = enull;
  ctrlbreak_action = (void (__cdecl *)(int))enull;
  abort_action = enull;
  term_action = (void (__cdecl *)(int))enull;
}

//------------------------------------------------------------------------------
// Address: 0x10034C9E
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
  while ( result < &pxcptacttab[12] );
  if ( result >= &pxcptacttab[12] || result->SigNum != signum )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034CD5
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl __get_sigabrt())(int)
{
  return (void (__cdecl *)(int))DecodePointer(Ptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x10034CE2
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl raise(int signum)
{
  _tiddata *v1; // edi
  _tiddata *v2; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v5)(int); // eax
  void (__cdecl *v6)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v1 = nullptr;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v5 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v5 = ctrlbreak_action;
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
      p_XcptAction = (void (__cdecl **)(int))&ctrlc_action;
      v5 = (void (__cdecl *)(int))ctrlc_action;
LABEL_18:
      siglock = 1;
      v6 = (void (__cdecl *)(int))DecodePointer(Ptr: v5);
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
        _invalid_parameter_noinfo();
        return -1;
      }
LABEL_15:
      p_XcptAction = (void (__cdecl **)(int))&abort_action;
      v5 = (void (__cdecl *)(int))abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v2 = _getptd_noexit();
  v1 = v2;
  if ( v2 == nullptr )
    return -1;
  p_XcptAction = &siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v2->_pxcptacttab)->XcptAction;
  v6 = *p_XcptAction;
LABEL_19:
  sigact = v6;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( sigact == nullptr )
    _exit(code: 3);
  if ( siglock != 0 )
    _lock(locknum: 0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v1->_tpxcptinfoptrs;
    v1->_tpxcptinfoptrs = nullptr;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v1->_tfpecode;
    v1->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = 3; indx < 12; ++indx )
      *((_DWORD *)v1->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null();
$LN37:
  if ( siglock != 0 )
    _unlock(locknum: 0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(a1: 8, a2: v1->_tfpecode);
  else
    sigact(a1: signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v1->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v1->_tfpecode = oldfpecode;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10034E85
// Name: ___crtMessageBoxW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtMessageBoxW(const wchar_t *lpText, const wchar_t *lpCaption, unsigned int uType)
{
  HMODULE LibraryW; // eax
  HMODULE v4; // ebx
  int (__stdcall *MessageBoxW)(HWND, LPCWSTR, LPCWSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  BOOL (__stdcall *GetUserObjectInformationW)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v10)(void); // edi
  int (__stdcall *v11)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // eax
  int (__stdcall *v12)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // ebx
  int v13; // eax
  int (*v14)(void); // eax
  int (__stdcall *v15)(HWND__ *); // eax
  int (__stdcall *v16)(HWND__ *, const wchar_t *, const wchar_t *, unsigned int); // eax
  unsigned int nDummy; // [esp+Ch] [ebp-24h] BYREF
  const wchar_t *v19; // [esp+10h] [ebp-20h]
  const wchar_t *v20; // [esp+14h] [ebp-1Ch]
  void *enull; // [esp+18h] [ebp-18h]
  HWND__ *hWndParent; // [esp+1Ch] [ebp-14h]
  tagUSEROBJECTFLAGS uof; // [esp+20h] [ebp-10h] BYREF

  v19 = lpText;
  v20 = lpCaption;
  hWndParent = nullptr;
  enull = _encoded_null();
  if ( pfnMessageBox == nullptr )
  {
    LibraryW = LoadLibraryW(lpLibFileName: L"USER32.DLL");
    v4 = LibraryW;
    if ( LibraryW == nullptr )
      return 0;
    MessageBoxW = (int (__stdcall *)(HWND, LPCWSTR, LPCWSTR, UINT))GetProcAddress(
                                                                     hModule: LibraryW,
                                                                     lpProcName: "MessageBoxW");
    if ( MessageBoxW == nullptr )
      return 0;
    pfnMessageBox = EncodePointer(Ptr: MessageBoxW);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: v4, lpProcName: "GetActiveWindow");
    pfnGetActiveWindow = EncodePointer(Ptr: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: v4, lpProcName: "GetLastActivePopup");
    pfnGetLastActivePopup = EncodePointer(Ptr: GetLastActivePopup);
    GetUserObjectInformationW = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                          hModule: v4,
                                                                                          lpProcName: "GetUserObjectInformationW");
    pfnGetUserObjectInformation = EncodePointer(Ptr: GetUserObjectInformationW);
    if ( pfnGetUserObjectInformation != nullptr )
    {
      GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                           hModule: v4,
                                                           lpProcName: "GetProcessWindowStation");
      pfnGetProcessWindowStation = EncodePointer(Ptr: GetProcessWindowStation);
    }
  }
  if ( pfnGetProcessWindowStation == enull
    || pfnGetUserObjectInformation == enull
    || (v10 = (int (*)(void))DecodePointer(Ptr: pfnGetProcessWindowStation),
        v11 = (int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))DecodePointer(Ptr: pfnGetUserObjectInformation),
        v12 = v11,
        v10 == nullptr)
    || v11 == nullptr
    || (v13 = v10()) != 0 && v12(a1: v13, a2: 1, a3: &uof, a4: 12, a5: &nDummy) != 0 && (uof.dwFlags & 1) != 0 )
  {
    if ( pfnGetActiveWindow != enull )
    {
      v14 = (int (*)(void))DecodePointer(Ptr: pfnGetActiveWindow);
      if ( v14 != nullptr )
      {
        hWndParent = (HWND__ *)v14();
        if ( hWndParent != nullptr && pfnGetLastActivePopup != enull )
        {
          v15 = (int (__stdcall *)(HWND__ *))DecodePointer(Ptr: pfnGetLastActivePopup);
          if ( v15 != nullptr )
            hWndParent = (HWND__ *)v15(a1: hWndParent);
        }
      }
    }
  }
  else
  {
    uType |= 0x200000u;
  }
  v16 = (int (__stdcall *)(HWND__ *, const wchar_t *, const wchar_t *, unsigned int))DecodePointer(Ptr: pfnMessageBox);
  if ( v16 != nullptr )
    return v16(a1: hWndParent, a2: v19, a3: v20, a4: uType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10034FF1
// Name: _wcscat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcscat_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  int result; // eax
  const wchar_t *v6; // ecx
  unsigned __int16 *v7; // edx
  int v8; // edx
  wchar_t v9; // ax

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInWords;
  if ( _SizeInWords == 0 )
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
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v8 = (char *)v7 - (char *)_Src;
      do
      {
        v9 = *v6;
        *(const wchar_t *)((char *)v6 + v8) = *v6;
        ++v6;
        if ( v9 == 0 )
          break;
        --v3;
      }
      while ( v3 != 0 );
      result = 0;
      if ( v3 == 0 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return result;
    }
  }
  *_Dst = 0;
LABEL_3:
  v4 = 22;
  *_errno() = 22;
LABEL_4:
  _invalid_parameter_noinfo();
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10035066
// Name: _wcsncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcsncpy_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src, unsigned int _Count)
{
  unsigned int v4; // ebx
  unsigned int v6; // edi
  int v7; // esi
  const wchar_t *v8; // ecx
  unsigned __int16 *v9; // eax
  wchar_t v10; // ax
  unsigned __int16 v11; // cx

  v4 = _Count;
  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v7 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v7;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInWords == 0 )
      return 0;
    goto LABEL_7;
  }
  v6 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v8 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v9 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v10 = *v8;
      *(const wchar_t *)((char *)v8 + (char *)_Dst - (char *)_Src) = *v8;
      ++v8;
      if ( v10 == 0 )
        break;
      --v6;
    }
    while ( v6 != 0 );
  }
  else
  {
    do
    {
      v11 = *(unsigned __int16 *)((char *)v9 + (char *)_Src - (char *)_Dst);
      *v9++ = v11;
      if ( v11 == 0 )
        break;
      if ( --v6 == 0 )
        break;
      --v4;
    }
    while ( v4 != 0 );
    if ( v4 == 0 )
      *v9 = 0;
  }
  if ( v6 != 0 )
    return 0;
  if ( v4 != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v7 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInWords - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x10035133
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_error_mode(int em)
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
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10035172
// Name: __crtGetLocaleInfoA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetLocaleInfoA_stat(
        localeinfo_struct *plocinfo,
        LCID Locale,
        LCTYPE LCType,
        char *lpLCData,
        int cchData)
{
  int v5; // esi
  int LocaleInfoW; // eax
  int v7; // ecx
  unsigned int v9; // eax
  void *v10; // esp
  WCHAR *v11; // ebx
  WCHAR *v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-18h] BYREF
  int v15; // [esp+8h] [ebp-10h] BYREF
  int buff_size; // [esp+Ch] [ebp-Ch]
  int code_page; // [esp+10h] [ebp-8h]

  v5 = 0;
  code_page = plocinfo->locinfo->lc_codepage;
  LocaleInfoW = GetLocaleInfoW(Locale, LCType, lpLCData: nullptr, cchData: 0);
  v7 = LocaleInfoW;
  buff_size = LocaleInfoW;
  if ( LocaleInfoW == 0 )
    return 0;
  if ( LocaleInfoW <= 0 || 0xFFFFFFE0 / LocaleInfoW < 2 )
  {
    v11 = nullptr;
  }
  else
  {
    v9 = 2 * LocaleInfoW + 8;
    if ( v9 > 0x400 )
    {
      v12 = (WCHAR *)operator new(nSize: 2 * v7 + 8);
      if ( v12 != nullptr )
      {
        *(_DWORD *)v12 = 56797;
        v12 += 4;
      }
      v11 = v12;
    }
    else
    {
      v10 = alloca(v9);
      if ( &v14 == nullptr )
        return 0;
      v14 = 52428;
      v11 = (WCHAR *)&v15;
    }
  }
  if ( v11 == nullptr )
    return 0;
  if ( GetLocaleInfoW(Locale, LCType, lpLCData: v11, cchData: buff_size) != 0 )
  {
    if ( cchData != 0 )
      v13 = WideCharToMultiByte(
              CodePage: code_page,
              dwFlags: 0,
              lpWideCharStr: v11,
              cchWideChar: -1,
              lpMultiByteStr: lpLCData,
              cbMultiByte: cchData,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
    else
      v13 = WideCharToMultiByte(
              CodePage: code_page,
              dwFlags: 0,
              lpWideCharStr: v11,
              cchWideChar: -1,
              lpMultiByteStr: nullptr,
              cbMultiByte: 0,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
    v5 = v13;
  }
  _freea(_Memory: v11);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1003524C
// Name: ___crtGetLocaleInfoA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetLocaleInfoA(localeinfo_struct *plocinfo, LCID Locale, LCTYPE LCType, char *lpLCData, int cchData)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetLocaleInfoA_stat(plocinfo: &_loc_update.localeinfo, Locale, LCType, lpLCData, cchData);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10035290
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
// Address: 0x100352BD
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
// Address: 0x10035365
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
// Address: 0x1003540D
// Name: __fptostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fptostr(char *buf, unsigned int sizeInBytes, int digits, _strflt *pflt)
{
  _strflt *v4; // ecx
  char *mantissa; // ebx
  int v6; // eax
  int v7; // esi
  int v9; // edx
  char *v10; // eax
  char v11; // cl
  int v12; // eax

  v4 = pflt;
  mantissa = pflt->mantissa;
  v6 = 0;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return v7;
  }
  v9 = digits;
  *buf = 0;
  if ( digits > 0 )
    v6 = digits;
  if ( sizeInBytes <= v6 + 1 )
  {
    *_errno() = 34;
    v7 = 34;
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
      --v9;
    }
    while ( v9 > 0 );
    v4 = pflt;
  }
  *v10 = 0;
  if ( v9 >= 0 && *mantissa >= 53 )
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
// Address: 0x100354C0
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __dtold(_LDOUBLE *pld, long double *px)
{
  int v3; // ebx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  __int16 v7; // bx
  __int16 v8; // di
  _LDOUBLE *v9; // eax
  __int16 v10; // cx
  int v11; // edx
  int v12; // ecx
  unsigned int msb; // [esp+Ch] [ebp-4h]
  __int16 sign; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)px + 3) >> 4) & 0x7FF;
  sign = *((_WORD *)px + 3) & 0x8000;
  v4 = *((_DWORD *)px + 1);
  v5 = *(_DWORD *)px;
  v6 = v4 & 0xFFFFF;
  msb = 0x80000000;
  if ( (_WORD)v3 != 0 )
  {
    if ( (unsigned __int16)v3 == 2047 )
    {
      v8 = 0x7FFF;
      goto LABEL_10;
    }
    v7 = v3 + 15360;
  }
  else
  {
    if ( v6 == 0 && v5 == 0 )
    {
      v9 = pld;
      v10 = sign;
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_14;
    }
    v7 = 15361;
    msb = 0;
  }
  v8 = v7;
LABEL_10:
  v11 = msb | (v6 << 11) | (v5 >> 21);
  v9 = pld;
  v12 = v5 << 11;
  while ( 1 )
  {
    *(_DWORD *)pld->ld = v12;
    *(_DWORD *)&pld->ld[4] = v11;
    if ( v11 < 0 )
      break;
    v11 = (*(_DWORD *)pld->ld >> 31) | (2 * v11);
    v12 = 2 * *(_DWORD *)pld->ld;
    --v8;
  }
  v10 = v8 | sign;
LABEL_14:
  *(_WORD *)&v9->ld[8] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x10035573
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  int v5; // eax
  char *v6; // esi
  _BYTE v8[26]; // [esp-Eh] [ebp-4Ah] BYREF
  _LDOUBLE ld; // [esp+Ch] [ebp-30h] BYREF
  char *_Dst; // [esp+18h] [ebp-24h]
  _FloatOutStruct autofos; // [esp+1Ch] [ebp-20h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(pld: &ld, px: &x.x);
  v5 = _I10_OUTPUT(ld, ndigits: 17, output_flags: 0, fos: &autofos);
  v6 = _Dst;
  v4->flag = v5;
  v4->sign = autofos.sign;
  v4->decpt = autofos.exp;
  if ( strcpy_s(_Dst: v6, _SizeInBytes: resultsize, _Src: autofos.man) != 0 )
  {
    memset(v8, 0, 14);
    _invoke_watson(a1: (unsigned int)v8);
  }
  v4->mantissa = v6;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10035610
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
// Address: 0x100356F0
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
// Address: 0x1003570F
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn _fptrap()
{
  _amsg_exit(rterrnum: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10035718
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _controlfp_s(unsigned int *_CurrentState, unsigned int newctrl, unsigned int mask)
{
  unsigned int v4; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl: 0, mask: 0);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    v4 = mask & 0xFFF7FFFF;
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl, mask: v4);
    else
      _control87(newctrl, mask: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035777
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _crt_debugger_hook()
{
  _debugger_hook_dummy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003577F
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock(int ch, _iobuf *str)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int flag; // eax
  char *v7; // eax
  int v8; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v2 = _fileno(stream: str);
    if ( v2 == -1 || v2 == -2 )
      v3 = &__badioinfo;
    else
      v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
      || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt != 0 )
      return -1;
    ++str->_ptr;
  }
  v7 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v7 != (_BYTE)ch )
    {
      str->_ptr = v7 + 1;
      return -1;
    }
  }
  else
  {
    *v7 = ch;
  }
  v8 = str->_flag;
  ++str->_cnt;
  str->_flag = v8 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}

//------------------------------------------------------------------------------
// Address: 0x10035862
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
// Address: 0x10035978
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10035992
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
// Address: 0x100359CB
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_eh_hooks()
{
  __pInconsistency = (void (__cdecl *)())EncodePointer(Ptr: terminate);
}

//------------------------------------------------------------------------------
// Address: 0x100359DC
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(int (__stdcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

//------------------------------------------------------------------------------
// Address: 0x100359EB
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(int (__cdecl *enull)(unsigned int))
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x10035A00
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
// Address: 0x10035A40
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
// Address: 0x10035A90
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x10000000)
      && (PESection = _FindPESection(
                        pImageBase: (unsigned __int8 *)0x10000000,
                        rva: (unsigned int)(pTarget - 0x10000000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035B4C
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
// Address: 0x10035CA8
// Name: __SEH_epilog4_GS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _SEH_epilog4_GS()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10035CB7
// Name: __crtCompareStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _crtCompareStringA_stat(
        localeinfo_struct *plocinfo,
        const char *lpString2,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        int cchCount2,
        UINT code_page)
{
  const char *v8; // eax
  int v9; // edi
  int v11; // ecx
  int v12; // esi
  int v13; // ecx
  const char *v14; // eax
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
  WCHAR *v29; // eax
  WCHAR *v30; // edi
  _DWORD v32[3]; // [esp+0h] [ebp-38h] BYREF
  int buff_size1; // [esp+Ch] [ebp-2Ch]
  int retcode; // [esp+10h] [ebp-28h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-24h]
  LPCCH v36; // [esp+18h] [ebp-20h]
  wchar_t *wbuffer1; // [esp+1Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+20h] [ebp-18h] BYREF

  v8 = lpString1;
  v9 = cchCount1;
  lpMultiByteStr = lpString1;
  v36 = lpString2;
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0;
  }
  else
  {
    v11 = cchCount1;
    while ( 1 )
    {
      --v11;
      if ( *v8 == 0 )
        break;
      ++v8;
      if ( v11 == 0 )
      {
        v11 = -1;
        break;
      }
    }
    v9 = -1 - v11 + cchCount1;
    cchCount1 = v9;
  }
  v12 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0;
  }
  else
  {
    v13 = cchCount2;
    v14 = lpString2;
    while ( 1 )
    {
      --v13;
      if ( *v14 == 0 )
        break;
      ++v14;
      if ( v13 == 0 )
      {
        v13 = -1;
        break;
      }
    }
    v12 = -1 - v13 + cchCount2;
    cchCount2 = v12;
  }
  retcode = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  if ( v9 != 0 && v12 != 0 )
    goto LABEL_44;
  if ( v9 == v12 )
    return 2;
  if ( v12 > 1 )
    return 1;
  if ( v9 > 1 )
    return 3;
  if ( !GetCPInfo(CodePage: code_page, &lpCPInfo) )
    return 0;
  if ( v9 > 0 )
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
          if ( (unsigned int)*lpMultiByteStr >= *LeadByte && (unsigned int)*lpMultiByteStr <= v17 )
            return 2;
          LeadByte += 2;
          if ( *LeadByte == 0 )
            return 3;
        }
      }
    }
    return 3;
  }
  if ( v12 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      for ( i = lpCPInfo.LeadByte; *i != 0; i += 2 )
      {
        v19 = i[1];
        if ( v19 == 0 )
          break;
        if ( (unsigned int)*v36 >= *i && (unsigned int)*v36 <= v19 )
          return 2;
      }
    }
    return 1;
  }
LABEL_44:
  v20 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 9u,
          lpMultiByteStr,
          cbMultiByte: v9,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v21 = v20;
  buff_size1 = v20;
  if ( v20 == 0 )
    return 0;
  if ( v20 > 0 && 0xFFFFFFE0 / v20 >= 2 )
  {
    v22 = 2 * v20 + 8;
    if ( v22 > 0x400 )
    {
      v24 = (wchar_t *)operator new(nSize: 2 * v21 + 8);
      if ( v24 != nullptr )
      {
        *(_DWORD *)v24 = 56797;
        goto LABEL_52;
      }
    }
    else
    {
      v23 = alloca(v22);
      v24 = (wchar_t *)v32;
      if ( v32 != nullptr )
      {
        v32[0] = 52428;
LABEL_52:
        v24 += 4;
      }
    }
    wbuffer1 = v24;
    goto LABEL_55;
  }
  wbuffer1 = nullptr;
LABEL_55:
  if ( wbuffer1 == nullptr )
    return 0;
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
            lpMultiByteStr: v36,
            cbMultiByte: cchCount2,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v26 = v25;
    if ( v25 != 0 )
    {
      if ( v25 <= 0 || 0xFFFFFFE0 / v25 < 2 )
      {
        v30 = nullptr;
LABEL_68:
        if ( v30 != nullptr )
        {
          if ( MultiByteToWideChar(
                 CodePage: code_page,
                 dwFlags: 1u,
                 lpMultiByteStr: v36,
                 cbMultiByte: cchCount2,
                 lpWideCharStr: v30,
                 cchWideChar: v26) != 0 )
            retcode = CompareStringW(
                        Locale,
                        dwCmpFlags,
                        lpString1: wbuffer1,
                        cchCount1: buff_size1,
                        lpString2: v30,
                        cchCount2: v26);
          _freea(_Memory: v30);
        }
        goto error_cleanup_2;
      }
      v27 = 2 * v25 + 8;
      if ( v27 > 0x400 )
      {
        v29 = (WCHAR *)operator new(nSize: 2 * v26 + 8);
        if ( v29 != nullptr )
        {
          *(_DWORD *)v29 = 56797;
          goto LABEL_65;
        }
      }
      else
      {
        v28 = alloca(v27);
        v29 = (WCHAR *)v32;
        if ( v32 != nullptr )
        {
          v32[0] = 52428;
LABEL_65:
          v29 += 4;
        }
      }
      v30 = v29;
      goto LABEL_68;
    }
  }
error_cleanup_2:
  _freea(_Memory: wbuffer1);
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x10035F25
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             lpString2,
             Locale,
             dwCmpFlags,
             lpString1,
             cchCount1,
             cchCount2,
             code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10035F67
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strnicoll_l(const char *_string1, const char *_string2, unsigned int count, localeinfo_struct *plocinfo)
{
  int result; // eax
  LCID v5; // ecx
  int v6; // eax
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
      _invalid_parameter_noinfo();
LABEL_16:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    v5 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( v5 != 0 )
    {
      v6 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: v5,
             dwCmpFlags: 0x1001u,
             lpString1: _string1,
             cchCount1: count,
             lpString2: _string2,
             cchCount2: count,
             code_page: _loc_update.localeinfo.locinfo->lc_collate_cp);
      if ( v6 == 0 )
      {
        *_errno() = 22;
        goto LABEL_16;
      }
      result = v6 - 2;
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
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036051
// Name: __mbsrchr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsrchr_l(unsigned __int8 *str, unsigned int c, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // ecx
  unsigned __int8 v5; // dl
  int v6; // eax
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  v3 = nullptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v4 = str;
  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strrchr(string: str, chr: c);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  do
  {
    v5 = *v4;
    v6 = *v4;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v6 + 1] & 4) != 0 )
    {
      v5 = *++v4;
      if ( *v4 != 0 )
      {
        if ( c == (v5 | (v6 << 8)) )
          v3 = v4 - 1;
        goto LABEL_16;
      }
      v7 = v3 == nullptr;
    }
    else
    {
      v7 = c == v6;
    }
    if ( v7 )
      v3 = v4;
LABEL_16:
    ++v4;
  }
  while ( v5 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x100360FB
// Name: __mbsrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsrchr(unsigned __int8 *str, unsigned int c)
{
  _mbsrchr_l(str, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10036112
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
// Address: 0x10036197
// Name: __lseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
doubleint __cdecl _lseeki64(int fh, __int64 pos, DWORD mthd)
{
  ioinfo **v4; // edi
  int v5; // esi
  __int64 r; // [esp+10h] [ebp-24h]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return (doubleint)-1LL;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return (doubleint)-1LL;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _lseeki64_nolock(fh, pos, mthd).bigint;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return (doubleint)r;
}

//------------------------------------------------------------------------------
// Address: 0x10036281
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _write_nolock(int fh, char *buf, unsigned int cnt)
{
  ioinfo **v4; // ebx
  ioinfo *v5; // eax
  int v6; // edi
  char v7; // cl
  BOOL v8; // esi
  UINT ConsoleCP; // eax
  char *v10; // ebx
  unsigned __int8 v11; // cl
  ioinfo **v12; // esi
  int v13; // eax
  int v14; // eax
  DWORD v15; // eax
  signed int v16; // esi
  ioinfo *v17; // eax
  int v18; // esi
  ioinfo *v19; // ecx
  char v20; // dl
  char *v21; // ebx
  unsigned int v22; // esi
  unsigned int v23; // ecx
  char *v24; // eax
  char v25; // dl
  signed int v26; // esi
  char *v27; // ebx
  unsigned int v28; // ecx
  char *v29; // eax
  int v30; // edx
  signed int v31; // esi
  unsigned int v32; // ecx
  WCHAR *v33; // eax
  int v34; // edx
  int v35; // esi
  int v36; // ebx
  BOOL v37; // [esp+8h] [ebp-1AE4h]
  unsigned int Mode; // [esp+Ch] [ebp-1AE0h] BYREF
  ioinfo **v39; // [esp+10h] [ebp-1ADCh]
  unsigned int v40; // [esp+14h] [ebp-1AD8h] BYREF
  unsigned int NumberOfBytesWritten; // [esp+18h] [ebp-1AD4h] BYREF
  int v42; // [esp+1Ch] [ebp-1AD0h]
  char *s; // [esp+20h] [ebp-1ACCh]
  unsigned int v44; // [esp+24h] [ebp-1AC8h]
  char v45; // [esp+2Bh] [ebp-1AC1h]
  unsigned int v46; // [esp+2Ch] [ebp-1AC0h]
  wchar_t pwc[2]; // [esp+30h] [ebp-1ABCh] BYREF
  char Buffer[1704]; // [esp+34h] [ebp-1AB8h] BYREF
  char v49[3416]; // [esp+6DCh] [ebp-1410h] BYREF
  WCHAR WideCharStr[854]; // [esp+1434h] [ebp-6B8h] BYREF
  char MultiByteStr[8]; // [esp+1AE0h] [ebp-Ch] BYREF

  s = buf;
  v44 = 0;
  v42 = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v4 = &__pioinfo[fh >> 5];
  v5 = *v4;
  v6 = (fh & 0x1F) << 6;
  v7 = (char)(2 * *((_BYTE *)*v4 + v6 + 36)) >> 1;
  v39 = v4;
  v45 = v7;
  if ( (v7 == 2 || v7 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( (*(&v5->osfile + v6) & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2u);
  if ( _isatty(fh) != 0 && *(&(*v4)->osfile + v6) < 0 )
  {
    v8 = _getptd()->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: *(HANDLE *)((char *)&(*v4)->osfhnd + v6), lpMode: &Mode) && (!v8 || v45 != 0) )
    {
      ConsoleCP = GetConsoleCP();
      v10 = s;
      Mode = ConsoleCP;
      NumberOfBytesWritten = 0;
      v46 = 0;
      while ( 1 )
      {
        if ( v45 != 0 )
        {
          if ( v45 == 1 || v45 == 2 )
          {
            v18 = *(unsigned __int16 *)v10;
            v10 += 2;
            v46 += 2;
            *(_DWORD *)pwc = v18;
            v37 = v18 == 10;
          }
          if ( v45 == 1 || v45 == 2 )
          {
            if ( _putwch_nolock(ch: pwc[0]) != pwc[0] )
              goto LABEL_85;
            v44 += 2;
            if ( v37 )
            {
              wcscpy(pwc, L"\r");
              if ( _putwch_nolock(ch: 0xDu) != pwc[0] )
                goto LABEL_85;
              ++v44;
              ++v42;
            }
          }
          goto LABEL_43;
        }
        v11 = *v10;
        v12 = v39;
        v37 = *v10 == 10;
        v13 = (int)*v39 + v6;
        if ( *(_DWORD *)(v13 + 56) != 0 )
        {
          MultiByteStr[0] = *(_BYTE *)(v13 + 52);
          MultiByteStr[1] = v11;
          *(_DWORD *)(v13 + 56) = 0;
          v14 = mbtowc(pwc, s: MultiByteStr, n: 2u);
        }
        else
        {
          if ( isleadbyte(c: v11) != 0 )
          {
            if ( cnt + s - v10 <= 1 )
            {
              v19 = *v12;
              v20 = *v10;
              ++v44;
              *(&v19->dbcsBuffer + v6) = v20;
              *(int *)((char *)&(*v12)->dbcsBufferUsed + v6) = 1;
              goto LABEL_86;
            }
            if ( mbtowc(pwc, s: v10, n: 2u) == -1 )
              goto LABEL_86;
            ++v10;
            ++v46;
            goto LABEL_27;
          }
          v14 = mbtowc(pwc, s: v10, n: 1u);
        }
        if ( v14 == -1 )
          goto LABEL_86;
LABEL_27:
        ++v10;
        ++v46;
        v15 = WideCharToMultiByte(
                CodePage: Mode,
                dwFlags: 0,
                lpWideCharStr: pwc,
                cchWideChar: 1,
                lpMultiByteStr: MultiByteStr,
                cbMultiByte: 5,
                lpDefaultChar: nullptr,
                lpUsedDefaultChar: nullptr);
        v16 = v15;
        if ( v15 == 0 )
          goto LABEL_86;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: MultiByteStr,
                nNumberOfBytesToWrite: v15,
                lpNumberOfBytesWritten: &NumberOfBytesWritten,
                lpOverlapped: nullptr) )
          goto LABEL_85;
        v44 = v42 + v46;
        if ( (int)NumberOfBytesWritten < v16 )
          goto LABEL_86;
        if ( v37 )
        {
          v17 = *v39;
          MultiByteStr[0] = 13;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&v17->osfhnd + v6),
                  lpBuffer: MultiByteStr,
                  nNumberOfBytesToWrite: 1u,
                  lpNumberOfBytesWritten: &NumberOfBytesWritten,
                  lpOverlapped: nullptr) )
            goto LABEL_85;
          if ( (int)NumberOfBytesWritten < 1 )
            goto LABEL_86;
          ++v42;
          ++v44;
        }
LABEL_43:
        if ( v46 >= cnt )
          goto LABEL_86;
      }
    }
  }
  if ( *(&(*v4)->osfile + v6) >= 0 )
  {
    if ( WriteFile(
           hFile: (HANDLE)(*v4)[fh & 0x1F].osfhnd,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: &v40,
           lpOverlapped: nullptr) )
    {
      *(_DWORD *)pwc = 0;
      v44 = v40;
      goto LABEL_86;
    }
  }
  else
  {
    *(_DWORD *)pwc = 0;
    if ( v45 != 0 )
    {
      if ( v45 == 2 )
      {
        v27 = s;
        while ( 1 )
        {
          v46 = 0;
          v28 = v27 - s;
          v29 = Buffer;
          do
          {
            if ( v28 >= cnt )
              break;
            v30 = *(unsigned __int16 *)v27;
            v27 += 2;
            v28 += 2;
            Mode = (unsigned int)v27;
            if ( v30 == 10 )
            {
              v42 += 2;
              *(_WORD *)v29 = 13;
              v27 = (char *)Mode;
              v29 += 2;
              v46 += 2;
            }
            v46 += 2;
            *(_WORD *)v29 = v30;
            v29 += 2;
          }
          while ( v46 < 0x13FE );
          v31 = v29 - Buffer;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                  lpBuffer: Buffer,
                  nNumberOfBytesToWrite: v29 - Buffer,
                  lpNumberOfBytesWritten: &v40,
                  lpOverlapped: nullptr) )
            break;
          v44 += v40;
          if ( (int)v40 < v31 || v27 - s >= cnt )
            goto LABEL_86;
        }
      }
      else
      {
        NumberOfBytesWritten = (unsigned int)s;
        while ( 1 )
        {
          v46 = 0;
          v32 = NumberOfBytesWritten - (_DWORD)s;
          v33 = WideCharStr;
          do
          {
            if ( v32 >= cnt )
              break;
            v34 = *(unsigned __int16 *)NumberOfBytesWritten;
            NumberOfBytesWritten += 2;
            v32 += 2;
            if ( v34 == 10 )
            {
              *v33++ = 13;
              v46 += 2;
            }
            v46 += 2;
            *v33++ = v34;
          }
          while ( v46 < 0x6A8 );
          v35 = 0;
          v36 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: WideCharStr,
                  cchWideChar: v33 - WideCharStr,
                  lpMultiByteStr: v49,
                  cbMultiByte: 3413,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v36 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                    lpBuffer: &v49[v35],
                    nNumberOfBytesToWrite: v36 - v35,
                    lpNumberOfBytesWritten: &v40,
                    lpOverlapped: nullptr) )
          {
            v35 += v40;
            if ( v36 <= v35 )
              goto LABEL_80;
          }
          *(_DWORD *)pwc = GetLastError();
LABEL_80:
          if ( v36 <= v35 )
          {
            v44 = NumberOfBytesWritten - (_DWORD)s;
            if ( NumberOfBytesWritten - (unsigned int)s < cnt )
              continue;
          }
          goto LABEL_86;
        }
      }
    }
    else
    {
      v21 = s;
      while ( 1 )
      {
        v22 = 0;
        v23 = v21 - s;
        v24 = Buffer;
        do
        {
          if ( v23 >= cnt )
            break;
          v25 = *v21++;
          ++v23;
          Mode = (unsigned int)v21;
          if ( v25 == 10 )
          {
            ++v42;
            *v24++ = 13;
            ++v22;
          }
          *v24++ = v25;
          ++v22;
        }
        while ( v22 < 0x13FF );
        v26 = v24 - Buffer;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: Buffer,
                nNumberOfBytesToWrite: v24 - Buffer,
                lpNumberOfBytesWritten: &v40,
                lpOverlapped: nullptr) )
          break;
        v44 += v40;
        if ( (int)v40 < v26 || v21 - s >= cnt )
          goto LABEL_86;
      }
    }
  }
LABEL_85:
  *(_DWORD *)pwc = GetLastError();
LABEL_86:
  if ( v44 == 0 )
  {
    if ( *(_DWORD *)pwc != 0 )
    {
      if ( *(_DWORD *)pwc == 5 )
      {
        *_errno() = 9;
        *__doserrno() = 5;
      }
      else
      {
        _dosmaperr(oserrno: *(unsigned int *)pwc);
      }
    }
    else
    {
      if ( (*(&(*v39)->osfile + v6) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
      *__doserrno() = 0;
    }
    return -1;
  }
  return v44 - v42;
}

//------------------------------------------------------------------------------
// Address: 0x1003697E
// Name: __write
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _write(int fh, char *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _write_nolock(fh, buf, cnt);
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
// Address: 0x10036A52
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)operator new(nSize: 0x1000u);
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
// Address: 0x10036A9B
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isatty(int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return 0;
  }
  return __pioinfo[fh >> 5][fh & 0x1F].osfile & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x10036AF1
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x10036B07
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
    _invalid_parameter_noinfo();
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
        _invalid_parameter_noinfo();
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
// Address: 0x10036C5C
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_s(int *pRetValue, char *dst, unsigned int sizeInBytes, wchar_t wchar)
{
  return _wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10036C79
// Name: __set_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_osfhnd(int fh, void *value)
{
  ioinfo **v2; // edi
  int v3; // esi

  if ( fh >= 0
    && fh < _nhandle
    && (v2 = &__pioinfo[fh >> 5], *(int *)((char *)&(*v2)->osfhnd + (v3 = (fh & 0x1F) << 6)) == -1) )
  {
    if ( __app_type == 1 )
    {
      if ( fh != 0 )
      {
        if ( fh == 1 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF5, hHandle: value);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF4, hHandle: value);
        }
      }
      else
      {
        SetStdHandle(nStdHandle: 0xFFFFFFF6, hHandle: value);
      }
    }
    *(int *)((char *)&(*v2)->osfhnd + v3) = (int)value;
    return 0;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036CFA
// Name: __free_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _free_osfhnd(int fh)
{
  ioinfo **v1; // edi
  int v2; // esi

  if ( fh < 0
    || fh >= _nhandle
    || (v1 = &__pioinfo[fh >> 5], v2 = (fh & 0x1F) << 6, (*(&(*v1)->osfile + v2) & 1) == 0)
    || (*v1)[fh & 0x1F].osfhnd == -1 )
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
    *(int *)((char *)&(*v1)->osfhnd + v2) = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036D80
// Name: __get_osfhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_osfhandle(int fh)
{
  ioinfo *v2; // ecx
  int v3; // eax

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = __pioinfo[fh >> 5], (*(&v2->osfile + (v3 = (fh & 0x1F) << 6)) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  return *(int *)((char *)&v2->osfhnd + v3);
}

//------------------------------------------------------------------------------
// Address: 0x10036DE9
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
      retval = InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v1->lock, dwSpinCount: 0xFA0u);
      ++v1->lockinitflag;
    }
    _unlock(locknum: 10);
  }
  if ( retval )
    EnterCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10036E88
// Name: __unlock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_fhandle(int fh)
{
  LeaveCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
}

//------------------------------------------------------------------------------
// Address: 0x10036EAF
// Name: __alloc_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _alloc_osfhnd()
{
  int v0; // edi
  ioinfo *v2; // esi
  unsigned __int8 *v3; // eax
  ioinfo **v4; // ecx
  int failed; // [esp+14h] [ebp-24h]
  int fh; // [esp+1Ch] [ebp-1Ch]

  fh = -1;
  v0 = 0;
  failed = 0;
  if ( _mtinitlocknum(locknum: 11) == 0 )
    return -1;
  _lock(locknum: 11);
  while ( v0 < 64 )
  {
    v2 = __pioinfo[v0];
    if ( v2 == nullptr )
    {
      v3 = calloc(count: 0x20u, size: 0x40u);
      if ( v3 != nullptr )
      {
        v4 = &__pioinfo[v0];
        *v4 = (ioinfo *)v3;
        _nhandle += 32;
        while ( v3 < (unsigned __int8 *)&(*v4)[32] )
        {
          v3[4] = 0;
          *(_DWORD *)v3 = -1;
          v3[5] = 10;
          *((_DWORD *)v3 + 2) = 0;
          v3 += 64;
        }
        fh = 32 * v0;
        __pioinfo[(32 * v0) >> 5]->osfile = 1;
        if ( !__lock_fhandle(fh: 32 * v0) )
          fh = -1;
      }
      break;
    }
    while ( v2 < &__pioinfo[v0][32] )
    {
      if ( (v2->osfile & 1) == 0 )
      {
        if ( v2->lockinitflag == 0 )
        {
          _lock(locknum: 10);
          if ( v2->lockinitflag == 0 )
          {
            if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v2->lock, dwSpinCount: 0xFA0u) )
              ++v2->lockinitflag;
            else
              failed = 1;
          }
          _unlock(locknum: 10);
        }
        if ( failed == 0 )
        {
          EnterCriticalSection(lpCriticalSection: &v2->lock);
          if ( (v2->osfile & 1) == 0 )
          {
            v2->osfile = 1;
            v2->osfhnd = -1;
            fh = 32 * v0 + v2 - __pioinfo[v0];
            break;
          }
          LeaveCriticalSection(lpCriticalSection: &v2->lock);
        }
      }
      ++v2;
    }
    if ( fh != -1 )
      break;
    ++v0;
  }
  _unlock(locknum: 11);
  return fh;
}

//------------------------------------------------------------------------------
// Address: 0x10037048
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _commit(int filedes)
{
  ioinfo **v2; // edi
  int v3; // esi
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (v2 = &__pioinfo[filedes >> 5], (*(&(*v2)->osfile + (v3 = (filedes & 0x1F) << 6)) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh: filedes);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(fh: filedes);
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
// Address: 0x10037121
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  _iobuf *v1; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    if ( __piob[i] != nullptr )
    {
      v1 = (_iobuf *)__piob[i];
      if ( (v1->_flag & 0x83) != 0 && fclose(stream: v1) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
        free(pMem: __piob[i]);
        __piob[i] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x100371C0
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100371E0
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
// Address: 0x10037225
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
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-20h]

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
// Address: 0x100372A9
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100372CC
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x100372E0);
}

//------------------------------------------------------------------------------
// Address: 0x100372D5
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
// Address: 0x100372F4
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x100372F7
// Name: __fputwc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _fputwc_nolock(wchar_t ch, _iobuf *str)
{
  ioinfo **v2; // edi
  ioinfo *v3; // eax
  ioinfo **v4; // edi
  ioinfo *v5; // eax
  ioinfo **v6; // edi
  ioinfo *v7; // eax
  int v9; // edi
  bool v10; // sf
  int v11; // eax
  int size; // [esp+Ch] [ebp-10h] BYREF
  char mbc[8]; // [esp+10h] [ebp-Ch] BYREF

  if ( (str->_flag & 0x40) != 0
    || (_fileno(stream: str) == -1 || _fileno(stream: str) == -2
      ? (v3 = &__badioinfo)
      : (v2 = &__pioinfo[_fileno(stream: str) >> 5], v3 = &(*v2)[_fileno(stream: str) & 0x1F]),
        (*((_BYTE *)v3 + 36) & 0x7F) == 2
     || (_fileno(stream: str) == -1 || _fileno(stream: str) == -2
       ? (v5 = &__badioinfo)
       : (v4 = &__pioinfo[_fileno(stream: str) >> 5], v5 = &(*v4)[_fileno(stream: str) & 0x1F]),
         (*((_BYTE *)v5 + 36) & 0x7F) == 1
      || (_fileno(stream: str) == -1 || _fileno(stream: str) == -2
        ? (v7 = &__badioinfo)
        : (v6 = &__pioinfo[_fileno(stream: str) >> 5], v7 = &(*v6)[_fileno(stream: str) & 0x1F]),
          v7->osfile >= 0))) )
  {
    v10 = str->_cnt - 2 < 0;
    str->_cnt -= 2;
    if ( v10 )
    {
      return _flswbuf(ch, str);
    }
    else
    {
      *(_WORD *)str->_ptr = ch;
      str->_ptr += 2;
      return ch;
    }
  }
  else
  {
    if ( wctomb_s(pRetValue: &size, dst: mbc, sizeInBytes: 5u, wchar: ch) != 0 )
      return -1;
    v9 = 0;
    if ( size > 0 )
    {
      while ( 1 )
      {
        v10 = --str->_cnt < 0;
        if ( v10 )
        {
          v11 = _flsbuf(ch: mbc[v9], (int)str);
        }
        else
        {
          *str->_ptr = mbc[v9];
          v11 = *(unsigned __int8 *)str->_ptr++;
        }
        if ( v11 == -1 )
          break;
        if ( ++v9 >= size )
          return ch;
      }
      return -1;
    }
    return ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003747E
// Name: __mbsicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsicmp_l(const unsigned __int8 *s1, const unsigned __int8 *s2, localeinfo_struct *plocinfo)
{
  const unsigned __int8 *v3; // edx
  int result; // eax
  const unsigned __int8 *v5; // ebx
  threadmbcinfostruct *mbcinfo; // eax
  int v7; // ecx
  const unsigned __int8 *v8; // edx
  unsigned __int16 v9; // si
  int v10; // eax
  __int16 v11; // dx
  char *v12; // ecx
  int v13; // ecx
  unsigned __int16 v14; // cx
  int v15; // eax
  unsigned __int16 v16; // dx
  char *v17; // ecx
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int8 szResult[4]; // [esp+10h] [ebp-4h] BYREF
  const unsigned __int8 *s1a; // [esp+1Ch] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = _stricmp_l(dst: (const char *)s1, src: (const char *)s2, plocinfo: &_loc_update.localeinfo);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  while ( 1 )
  {
    v7 = *v3;
    v8 = v3 + 1;
    s1a = v8;
    if ( (mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) != 0 )
    {
      if ( *v8 != 0 )
      {
        v10 = __crtLCMapStringA(
                plocinfo: &_loc_update.localeinfo,
                Locale: mbcinfo->mblcid,
                dwMapFlags: 0x200u,
                lpSrcStr: (const char *)v8 - 1,
                cchSrc: 2,
                lpDestStr: (char *)szResult,
                cchDest: 2,
                code_page: mbcinfo->mbcodepage,
                bError: 1);
        if ( v10 == 1 )
        {
          v9 = szResult[0];
        }
        else
        {
          if ( v10 != 2 )
            goto LABEL_37;
          v9 = szResult[1] + (szResult[0] << 8);
        }
        ++s1a;
        mbcinfo = _loc_update.localeinfo.mbcinfo;
      }
      else
      {
        v9 = 0;
      }
    }
    else
    {
      v11 = v7;
      v12 = (char *)mbcinfo + v7;
      v9 = (v12[29] & 0x10) != 0 ? (unsigned __int8)v12[285] : v11;
    }
    v13 = *v5++;
    if ( (mbcinfo->mbctype[(unsigned __int8)v13 + 1] & 4) != 0 )
      break;
    v16 = v13;
    v17 = (char *)mbcinfo + v13;
    if ( (v17[29] & 0x10) != 0 )
      v14 = (unsigned __int8)v17[285];
    else
      v14 = v16;
LABEL_34:
    if ( v14 != v9 )
    {
      result = v14 < v9 ? 1 : -1;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( v9 == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
    v3 = s1a;
  }
  if ( *v5 == 0 )
  {
    v14 = 0;
    goto LABEL_34;
  }
  v15 = __crtLCMapStringA(
          plocinfo: &_loc_update.localeinfo,
          Locale: mbcinfo->mblcid,
          dwMapFlags: 0x200u,
          lpSrcStr: (const char *)v5 - 1,
          cchSrc: 2,
          lpDestStr: (char *)szResult,
          cchDest: 2,
          code_page: mbcinfo->mbcodepage,
          bError: 1);
  if ( v15 == 1 )
  {
    v14 = szResult[0];
LABEL_30:
    mbcinfo = _loc_update.localeinfo.mbcinfo;
    ++v5;
    goto LABEL_34;
  }
  if ( v15 == 2 )
  {
    v14 = szResult[1] + (szResult[0] << 8);
    goto LABEL_30;
  }
LABEL_37:
  *_errno() = 22;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10037675
// Name: __mbsicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsicmp(const unsigned __int8 *s1, const unsigned __int8 *s2)
{
  return _mbsicmp_l(s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003768C
// Name: __chsize_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chsize_nolock(int filedes, __int64 size)
{
  doubleint v2; // rax
  int v3; // edi
  unsigned int v4; // esi
  HANDLE ProcessHeap; // eax
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // of
  unsigned int v10; // kr08_4
  int v11; // esi
  HANDLE v12; // eax
  doubleint v13; // rax
  void *osfhandle; // eax
  unsigned int *v15; // esi
  doubleint v16; // rax
  __int64 place; // [esp+Ch] [ebp-18h]
  __int64 retval; // [esp+14h] [ebp-10h]
  int oldmode; // [esp+1Ch] [ebp-8h]
  char *v20; // [esp+20h] [ebp-4h]

  HIDWORD(retval) = 0;
  place = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 1u).bigint;
  if ( (HIDWORD(place) & (unsigned int)place) == 0xFFFFFFFF )
    return *_errno();
  v2.bigint = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 2u).bigint;
  if ( (v2.twoints.upperhalf & v2.twoints.lowerhalf) == -1 )
    return *_errno();
  v3 = (unsigned __int64)(size - v2.bigint) >> 32;
  v4 = size - v2.twoints.lowerhalf;
  if ( v3 >= 0 && (size >= v2.bigint && (unsigned __int64)(size - v2.bigint) >> 32 != 0 || v4 != 0) )
  {
    ProcessHeap = GetProcessHeap();
    v20 = (char *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 8u, dwBytes: 0x1000u);
    if ( v20 == nullptr )
    {
      *_errno() = 12;
      return *_errno();
    }
    oldmode = _setmode_nolock(fh: filedes, mode: 0x8000);
    while ( 1 )
    {
      v7 = v3 < 0 || v3 <= 0 && v4 < 0x1000 ? v4 : 4096;
      v8 = _write_nolock(fh: filedes, buf: v20, cnt: v7);
      if ( v8 == -1 )
        break;
      v9 = __OFSUB__(__PAIR64__(v3, v4), v8);
      v10 = v4 - v8;
      v3 = (__PAIR64__(v3, v4) - v8) >> 32;
      v4 -= v8;
      if ( v3 < 0 || (v3 < 0) ^ v9 | (v3 == 0) && v10 == 0 )
      {
        v11 = 0;
        goto LABEL_20;
      }
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v11 = -1;
    HIDWORD(retval) = -1;
LABEL_20:
    _setmode_nolock(fh: filedes, mode: oldmode);
    v12 = GetProcessHeap();
    HeapFree(hHeap: v12, dwFlags: 0, lpMem: v20);
    goto LABEL_28;
  }
  if ( v3 < 0 )
  {
    v13.bigint = _lseeki64_nolock(fh: filedes, pos: size, mthd: 0).bigint;
    if ( (v13.twoints.upperhalf & v13.twoints.lowerhalf) == -1 )
      return *_errno();
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    retval = SetEndOfFile(hFile: osfhandle) - 1;
    if ( (HIDWORD(retval) & (unsigned int)retval) == 0xFFFFFFFF )
    {
      *_errno() = 13;
      v15 = __doserrno();
      *v15 = GetLastError();
      v11 = retval;
LABEL_28:
      if ( (HIDWORD(retval) & v11) == 0xFFFFFFFF )
        return *_errno();
    }
  }
  v16.bigint = _lseeki64_nolock(fh: filedes, pos: place, mthd: 0).bigint;
  if ( (v16.twoints.upperhalf & v16.twoints.lowerhalf) == -1 )
    return *_errno();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10037842
// Name: __setmode_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmode_nolock(int fh, int mode)
{
  ioinfo **v2; // edx
  int v3; // esi
  char *v4; // ecx
  int v5; // edi
  int v6; // eax
  _BYTE *v7; // ecx
  char v8; // dl

  v2 = &__pioinfo[fh >> 5];
  v3 = (fh & 0x1F) << 6;
  v4 = (char *)*v2 + v3;
  v5 = v4[4] & 0x80;
  v6 = (char)(2 * v4[36]) >> 1;
  if ( mode == 0x4000 )
  {
    v4[4] |= 0x80u;
    *((_BYTE *)*v2 + v3 + 36) &= 0x80u;
  }
  else if ( mode == 0x8000 )
  {
    v4[4] &= ~0x80u;
  }
  else
  {
    if ( mode == 0x10000 || mode == 0x20000 )
    {
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 2;
    }
    else
    {
      if ( mode != 0x40000 )
        goto LABEL_11;
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 1;
    }
    *v7 = v8;
  }
LABEL_11:
  if ( v5 != 0 )
    return v6 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x100378FD
// Name: __get_fmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_fmode(int *pMode)
{
  if ( pMode != nullptr )
  {
    *pMode = _fmode;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003792A
// Name: _tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall tzset_nolock(unsigned int a1@<edi>)
{
  unsigned __int8 *v1; // eax
  char *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // edi
  int v8; // edi
  const char *v9; // esi
  char v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int negdiff; // [esp+14h] [ebp-38h]
  UINT lc_cp; // [esp+18h] [ebp-34h]
  int defused; // [esp+1Ch] [ebp-30h] BYREF
  int nochange; // [esp+20h] [ebp-2Ch]
  int dstbias; // [esp+24h] [ebp-28h] BYREF
  int daylight; // [esp+28h] [ebp-24h] BYREF
  char **tzname; // [esp+2Ch] [ebp-20h]
  int timezone; // [esp+30h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  negdiff = 0;
  nochange = 0;
  timezone = 0;
  daylight = 0;
  dstbias = 0;
  _lock(locknum: 7);
  ms_exc.registration.TryLevel = 0;
  tzname = __tzname();
  if ( _get_timezone(_Timezone: &timezone) != 0
    || _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0 )
  {
LABEL_12:
    _invoke_watson(a1);
  }
  lc_cp = ___lc_codepage_func();
  tzapiused = 0;
  a1 = -1;
  dstend.yr = -1;
  dststart.yr = -1;
  v1 = (unsigned __int8 *)_getenv_helper_nolock(option: "TZ");
  v2 = (char *)v1;
  if ( v1 == nullptr || *v1 == 0 )
  {
    if ( lastTZ != nullptr )
    {
      free(pMem: lastTZ);
      lastTZ = nullptr;
    }
    if ( GetTimeZoneInformation(lpTimeZoneInformation: &tzinfo) != -1 )
    {
      tzapiused = 1;
      timezone = 60 * tzinfo.Bias;
      if ( tzinfo.StandardDate.wMonth != 0 )
        timezone = 60 * tzinfo.StandardBias + 60 * tzinfo.Bias;
      if ( tzinfo.DaylightDate.wMonth != 0 && tzinfo.DaylightBias != 0 )
      {
        daylight = 1;
        dstbias = 60 * (tzinfo.DaylightBias - tzinfo.StandardBias);
      }
      else
      {
        daylight = 0;
        dstbias = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.StandardName,
             cchWideChar: -1,
             lpMultiByteStr: *tzname,
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        **tzname = 0;
      }
      else
      {
        (*tzname)[63] = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.DaylightName,
             cchWideChar: -1,
             lpMultiByteStr: tzname[1],
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        *tzname[1] = 0;
      }
      else
      {
        tzname[1][63] = 0;
      }
    }
    goto LABEL_30;
  }
  if ( lastTZ != nullptr )
  {
    strcmp(str1: v1, str2: (unsigned __int8 *)lastTZ);
    if ( v3 == 0 )
    {
LABEL_30:
      nochange = 1;
      goto LABEL_31;
    }
    if ( lastTZ != nullptr )
      free(pMem: lastTZ);
  }
  strlen(buf: v2);
  lastTZ = (char *)operator new(nSize: v4 + 1);
  if ( lastTZ == nullptr )
    goto LABEL_30;
  strlen(buf: v2);
  if ( strcpy_s(_Dst: lastTZ, _SizeInBytes: v5 + 1, _Src: v2) != 0 )
    goto LABEL_12;
LABEL_31:
  v6 = timezone;
  *__timezone() = v6;
  v7 = daylight;
  *__daylight() = v7;
  v8 = dstbias;
  *__dstbias() = v8;
  ms_exc.registration.TryLevel = -2;
  _unlock(locknum: 7);
  if ( nochange == 0 )
  {
    a1 = (unsigned int)tzname;
    if ( strncpy_s(_Dst: *tzname, _SizeInBytes: 0x40u, _Src: v2, _Count: 3u) != 0 )
      goto LABEL_12;
    v9 = v2 + 3;
    if ( *v9 == 45 )
    {
      negdiff = 1;
      ++v9;
    }
    timezone = 3600 * atol(nptr: v9);
    while ( 1 )
    {
      v10 = *v9;
      if ( *v9 != 43 && (v10 < 48 || v10 > 57) )
        break;
      ++v9;
    }
    if ( *v9 == 58 )
    {
      v11 = atol(nptr: ++v9);
      timezone += 60 * v11;
      while ( *v9 >= 48 && *v9 <= 57 )
        ++v9;
      if ( *v9 == 58 )
      {
        v12 = atol(nptr: ++v9);
        timezone += v12;
        while ( *v9 >= 48 && *v9 <= 57 )
          ++v9;
      }
    }
    if ( negdiff != 0 )
      timezone = -timezone;
    daylight = *v9;
    if ( daylight != 0 )
    {
      if ( strncpy_s(_Dst: *(char **)(a1 + 4), _SizeInBytes: 0x40u, _Src: v9, _Count: 3u) != 0 )
        goto LABEL_12;
    }
    else
    {
      **(_BYTE **)(a1 + 4) = 0;
    }
    v13 = timezone;
    *__timezone() = v13;
    v14 = daylight;
    *__daylight() = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037E34
// Name: _isindst_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isindst_nolock@<eax>(tm *tb@<edi>)
{
  int result; // eax
  int tm_year; // edx
  int v3; // eax
  int v4; // ecx
  int tm_yday; // edx
  int v6; // eax
  int endmonth; // [esp+4h] [ebp-Ch]
  int endweek; // [esp+8h] [ebp-8h]
  int daylight; // [esp+Ch] [ebp-4h] BYREF

  daylight = 0;
  result = _get_daylight(_Daylight: &daylight);
  if ( result != 0 )
    _invoke_watson(a1: (unsigned int)tb);
  if ( daylight != 0 )
  {
    tm_year = tb->tm_year;
    if ( tm_year != dststart.yr || tm_year != dstend.yr )
    {
      if ( tzapiused != 0 )
      {
        if ( tzinfo.DaylightDate.wYear != 0 )
          cvtdate(
            trantype: 1,
            datetype: 0,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.DaylightDate.wDay,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        else
          cvtdate(
            trantype: 1,
            datetype: 1,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: tzinfo.DaylightDate.wDay,
            dayofweek: tzinfo.DaylightDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        if ( tzinfo.StandardDate.wYear != 0 )
          cvtdate(
            trantype: 0,
            datetype: 0,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.StandardDate.wDay,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
        else
          cvtdate(
            trantype: 0,
            datetype: 1,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: tzinfo.StandardDate.wDay,
            dayofweek: tzinfo.StandardDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
      }
      else
      {
        v3 = 3;
        v4 = 2;
        endmonth = 11;
        endweek = 1;
        if ( tm_year < 107 )
        {
          v3 = 4;
          v4 = 1;
          endmonth = 10;
          endweek = 5;
        }
        cvtdate(
          trantype: 1,
          datetype: 1,
          year: tm_year,
          month: v3,
          week: v4,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
        cvtdate(
          trantype: 0,
          datetype: 1,
          year: tb->tm_year,
          month: endmonth,
          week: endweek,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
      }
    }
    tm_yday = tb->tm_yday;
    if ( dststart.yd >= dstend.yd )
    {
      if ( tm_yday < dstend.yd || tm_yday > dststart.yd )
        return 1;
      if ( tm_yday <= dstend.yd || tm_yday >= dststart.yd )
        goto LABEL_28;
    }
    else if ( tm_yday >= dststart.yd && tm_yday <= dstend.yd )
    {
      if ( tm_yday > dststart.yd && tm_yday < dstend.yd )
        return 1;
LABEL_28:
      v6 = 1000 * (tb->tm_sec + 60 * (tb->tm_min + 60 * tb->tm_hour));
      if ( tm_yday == dststart.yd )
        return v6 >= dststart.ms;
      else
        return v6 < dstend.ms;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003800B
// Name: ___tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __tzset(unsigned int a1@<edi>)
{
  if ( first_time == 0 )
  {
    _lock(locknum: 6);
    if ( first_time == 0 )
    {
      tzset_nolock(a1);
      ++first_time;
    }
    _unlock(locknum: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003805A
// Name: __isindst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isindst(tm *tb)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 6);
  retval = isindst_nolock(tb);
  _unlock(locknum: 6);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003809B
// Name: __get_daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_daylight(int *_Daylight)
{
  if ( _Daylight != nullptr )
  {
    *_Daylight = _daylight;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100380C8
// Name: __get_dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_dstbias(int *_Daylight_savings_bias)
{
  if ( _Daylight_savings_bias != nullptr )
  {
    *_Daylight_savings_bias = _dstbias;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100380F5
// Name: __get_timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_timezone(int *_Timezone)
{
  if ( _Timezone != nullptr )
  {
    *_Timezone = _timezone;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038122
// Name: ___daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __daylight()
{
  return &_daylight;
}

//------------------------------------------------------------------------------
// Address: 0x10038128
// Name: ___dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __dstbias()
{
  return &_dstbias;
}

//------------------------------------------------------------------------------
// Address: 0x1003812E
// Name: ___timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __timezone()
{
  return &_timezone;
}

//------------------------------------------------------------------------------
// Address: 0x10038134
// Name: ___tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__cdecl __tzname()
{
  return _tzname;
}

//------------------------------------------------------------------------------
// Address: 0x1003813A
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
// Address: 0x1003818D
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead(unsigned __int8 tst)
{
  return x_ismbbtype_l(plocinfo: nullptr, tst, cmask: 0, kmask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x100381A5
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
  int v8; // edi
  unsigned int *v9; // esi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // edi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  int v20; // edx
  unsigned int *v21; // ecx
  int v22; // esi
  int v23; // eax
  unsigned int *v24; // ebx
  bool n; // zf
  int v26; // eax
  unsigned int v27; // edx
  unsigned int *v28; // ecx
  unsigned int v29; // edi
  int ii; // ecx
  unsigned int *v31; // ecx
  unsigned int v32; // esi
  int v33; // edi
  int v34; // eax
  int v35; // edx
  int *v36; // ebx
  int v37; // edx
  unsigned int *v38; // ecx
  int v39; // eax
  int v40; // edx
  int *v41; // ebx
  int v42; // edx
  unsigned int *v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // edx
  unsigned int *v47; // ecx
  unsigned int v48; // ebx
  int v49; // edx
  int v50; // [esp+8h] [ebp-38h]
  char v51; // [esp+10h] [ebp-30h]
  int v52; // [esp+10h] [ebp-30h]
  int v53; // [esp+14h] [ebp-2Ch]
  int v54; // [esp+14h] [ebp-2Ch]
  char v55; // [esp+14h] [ebp-2Ch]
  int v56; // [esp+14h] [ebp-2Ch]
  int v57; // [esp+14h] [ebp-2Ch]
  int v58; // [esp+14h] [ebp-2Ch]
  int v59; // [esp+18h] [ebp-28h]
  int v60; // [esp+18h] [ebp-28h]
  int v61; // [esp+18h] [ebp-28h]
  int v62; // [esp+18h] [ebp-28h]
  int v63; // [esp+18h] [ebp-28h]
  int v64; // [esp+18h] [ebp-28h]
  int v65; // [esp+1Ch] [ebp-24h]
  unsigned int v66; // [esp+20h] [ebp-20h]
  int m; // [esp+20h] [ebp-20h]
  int jj; // [esp+20h] [ebp-20h]
  int k; // [esp+20h] [ebp-20h]
  int j; // [esp+20h] [ebp-20h]
  unsigned int v71; // [esp+24h] [ebp-1Ch]
  int v72; // [esp+28h] [ebp-18h]
  int v73; // [esp+2Ch] [ebp-14h]
  unsigned int v74; // [esp+30h] [ebp-10h] BYREF
  int v75; // [esp+34h] [ebp-Ch]
  int v76; // [esp+38h] [ebp-8h] BYREF

  v2 = *(_WORD *)&pld12->ld12[10];
  v50 = v2 & 0x8000;
  v74 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v75 = *(_DWORD *)&pld12->ld12[2];
  v76 = v4;
  if ( v3 != -16383 )
  {
    v65 = 0;
    v71 = v74;
    v72 = v75;
    v73 = v76;
    v8 = DoubleFormat.precision - 1;
    v53 = v3;
    v59 = DoubleFormat.precision / 32;
    v9 = &v74 + DoubleFormat.precision / 32;
    v51 = 31 - DoubleFormat.precision % 32;
    if ( ((1 << v51) & *v9) != 0 )
    {
      v10 = DoubleFormat.precision / 32;
      for ( i = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v74 + v59)) == 0; i; i = *(&v74 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_21;
      }
      v12 = v8 / 32;
      v65 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v74 + v8 / 32;
      v66 = v13 + *v14;
      if ( v66 >= *v14 )
      {
        v15 = v66 < v13;
        goto LABEL_18;
      }
LABEL_19:
      v65 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = v66;
        if ( v12 < 0 || v65 == 0 )
          break;
        v65 = 0;
        v14 = &v74 + v12;
        v16 = *v14 + 1;
        v66 = v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
    }
LABEL_21:
    *v9 &= -1 << v51;
    if ( v59 + 1 < 3 )
      memset(&v74 + v59 + 1, 0, 4 * (3 - (v59 + 1)));
    if ( v65 != 0 )
      ++v3;
    if ( v3 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v3 > DoubleFormat.min_exp )
      {
        if ( v3 < DoubleFormat.max_exp )
        {
          v5 = DoubleFormat.bias + v3;
          v74 &= ~0x80000000;
          v44 = DoubleFormat.exp_width / 32;
          v45 = DoubleFormat.exp_width % 32;
          v64 = 0;
          for ( j = 0; j < 3; ++j )
          {
            v58 = ~(-1 << v45) & *(&v74 + j);
            *(&v74 + j) = v64 | (*(&v74 + j) >> v45);
            v64 = v58 << (32 - v45);
          }
          v46 = 2;
          v47 = (unsigned int *)(&v76 - v44);
          do
          {
            if ( v46 < v44 )
              *(&v74 + v46) = 0;
            else
              *(&v74 + v46) = *v47;
            --v47;
            --v46;
          }
          while ( v46 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v75 = 0;
          v76 = 0;
          v74 = 0x80000000;
          v39 = DoubleFormat.exp_width / 32;
          v40 = DoubleFormat.exp_width % 32;
          v63 = 0;
          for ( k = 0; k < 3; ++k )
          {
            v41 = (int *)(&v74 + k);
            v57 = ~(-1 << v40) & *v41;
            *v41 = v63 | ((unsigned int)*v41 >> v40);
            v63 = v57 << (32 - v40);
          }
          v42 = 2;
          v43 = (unsigned int *)(&v76 - v39);
          do
          {
            if ( v42 < v39 )
              *(&v74 + v42) = 0;
            else
              *(&v74 + v42) = *v43;
            --v43;
            --v42;
          }
          while ( v42 >= 0 );
          v5 = DoubleFormat.max_exp + DoubleFormat.bias;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_78;
      }
      v74 = v71;
      v75 = v72;
      v17 = (DoubleFormat.min_exp - v53) / 32;
      v76 = v73;
      v18 = (DoubleFormat.min_exp - v53) % 32;
      v60 = 0;
      for ( m = 0; m < 3; ++m )
      {
        v19 = (int *)(&v74 + m);
        v54 = ~(-1 << v18) & *v19;
        *v19 = v60 | ((unsigned int)*v19 >> v18);
        v60 = v54 << (32 - v18);
      }
      v20 = 2;
      v21 = (unsigned int *)(&v76 - v17);
      do
      {
        if ( v20 < v17 )
          *(&v74 + v20) = 0;
        else
          *(&v74 + v20) = *v21;
        --v21;
        --v20;
      }
      while ( v20 >= 0 );
      v22 = DoubleFormat.precision - 1;
      v23 = DoubleFormat.precision / 32;
      v52 = DoubleFormat.precision / 32;
      v24 = &v74 + DoubleFormat.precision / 32;
      v55 = 31 - DoubleFormat.precision % 32;
      if ( ((1 << v55) & *v24) != 0 )
      {
        for ( n = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v74 + v23)) == 0; n; n = *(&v74 + v23) == 0 )
        {
          if ( ++v23 >= 3 )
            goto LABEL_51;
        }
        v26 = v22 / 32;
        v61 = 0;
        v27 = 1 << (31 - v22 % 32);
        v28 = &v74 + v22 / 32;
        v29 = *v28 + v27;
        if ( v29 < *v28 || v29 < v27 )
          v61 = 1;
        *v28 = v29;
        for ( ii = v61; --v26 >= 0 && ii != 0; ii = v33 )
        {
          v31 = &v74 + v26;
          v32 = *v31 + 1;
          v33 = 0;
          if ( v32 < *v31 || *v31 == -1 )
            v33 = 1;
          *v31 = v32;
        }
      }
LABEL_51:
      *v24 &= -1 << v55;
      if ( v52 + 1 < 3 )
        memset(&v74 + v52 + 1, 0, 4 * (3 - (v52 + 1)));
      v34 = (DoubleFormat.exp_width + 1) / 32;
      v35 = (DoubleFormat.exp_width + 1) % 32;
      v62 = 0;
      for ( jj = 0; jj < 3; ++jj )
      {
        v36 = (int *)(&v74 + jj);
        v56 = ~(-1 << v35) & *v36;
        *v36 = v62 | ((unsigned int)*v36 >> v35);
        v62 = v56 << (32 - v35);
      }
      v37 = 2;
      v38 = (unsigned int *)(&v76 - v34);
      do
      {
        if ( v37 < v34 )
          *(&v74 + v37) = 0;
        else
          *(&v74 + v37) = *v38;
        --v38;
        --v37;
      }
      while ( v37 >= 0 );
    }
    else
    {
      v74 = 0;
      v75 = 0;
      v76 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_78;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v74 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_78;
    }
  }
  v74 = 0;
  v75 = 0;
  v76 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_78:
  v48 = v74 | (v50 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v49 = v75;
    HIDWORD(d->x) = v48;
    LODWORD(d->x) = v49;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v48;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100386F6
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
  int v8; // edi
  unsigned int *v9; // esi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // edi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  int v20; // edx
  unsigned int *v21; // ecx
  int v22; // esi
  int v23; // eax
  unsigned int *v24; // ebx
  bool n; // zf
  int v26; // eax
  unsigned int v27; // edx
  unsigned int *v28; // ecx
  unsigned int v29; // edi
  int ii; // ecx
  unsigned int *v31; // ecx
  unsigned int v32; // esi
  int v33; // edi
  int v34; // eax
  int v35; // edx
  int *v36; // ebx
  int v37; // edx
  unsigned int *v38; // ecx
  int v39; // eax
  int v40; // edx
  int *v41; // ebx
  int v42; // edx
  unsigned int *v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // edx
  unsigned int *v47; // ecx
  float v48; // ebx
  float v49; // edx
  int v50; // [esp+8h] [ebp-38h]
  char v51; // [esp+10h] [ebp-30h]
  int v52; // [esp+10h] [ebp-30h]
  int v53; // [esp+14h] [ebp-2Ch]
  int v54; // [esp+14h] [ebp-2Ch]
  char v55; // [esp+14h] [ebp-2Ch]
  int v56; // [esp+14h] [ebp-2Ch]
  int v57; // [esp+14h] [ebp-2Ch]
  int v58; // [esp+14h] [ebp-2Ch]
  int v59; // [esp+18h] [ebp-28h]
  int v60; // [esp+18h] [ebp-28h]
  int v61; // [esp+18h] [ebp-28h]
  int v62; // [esp+18h] [ebp-28h]
  int v63; // [esp+18h] [ebp-28h]
  int v64; // [esp+18h] [ebp-28h]
  int v65; // [esp+1Ch] [ebp-24h]
  unsigned int v66; // [esp+20h] [ebp-20h]
  int m; // [esp+20h] [ebp-20h]
  int jj; // [esp+20h] [ebp-20h]
  int k; // [esp+20h] [ebp-20h]
  int j; // [esp+20h] [ebp-20h]
  unsigned int v71; // [esp+24h] [ebp-1Ch]
  float v72; // [esp+28h] [ebp-18h]
  int v73; // [esp+2Ch] [ebp-14h]
  unsigned int v74; // [esp+30h] [ebp-10h] BYREF
  float v75; // [esp+34h] [ebp-Ch]
  int v76; // [esp+38h] [ebp-8h] BYREF

  v2 = *(_WORD *)&pld12->ld12[10];
  v50 = v2 & 0x8000;
  v74 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v75 = *(float *)&pld12->ld12[2];
  v76 = v4;
  if ( v3 != -16383 )
  {
    v65 = 0;
    v71 = v74;
    v72 = v75;
    v73 = v76;
    v8 = FloatFormat.precision - 1;
    v53 = v3;
    v59 = FloatFormat.precision / 32;
    v9 = &v74 + FloatFormat.precision / 32;
    v51 = 31 - FloatFormat.precision % 32;
    if ( ((1 << v51) & *v9) != 0 )
    {
      v10 = FloatFormat.precision / 32;
      for ( i = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v74 + v59)) == 0; i; i = *(&v74 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_21;
      }
      v12 = v8 / 32;
      v65 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v74 + v8 / 32;
      v66 = v13 + *v14;
      if ( v66 >= *v14 )
      {
        v15 = v66 < v13;
        goto LABEL_18;
      }
LABEL_19:
      v65 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = v66;
        if ( v12 < 0 || v65 == 0 )
          break;
        v65 = 0;
        v14 = &v74 + v12;
        v16 = *v14 + 1;
        v66 = v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
    }
LABEL_21:
    *v9 &= -1 << v51;
    if ( v59 + 1 < 3 )
      memset(&v74 + v59 + 1, 0, 4 * (3 - (v59 + 1)));
    if ( v65 != 0 )
      ++v3;
    if ( v3 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v3 > FloatFormat.min_exp )
      {
        if ( v3 < FloatFormat.max_exp )
        {
          v5 = FloatFormat.bias + v3;
          v74 &= ~0x80000000;
          v44 = FloatFormat.exp_width / 32;
          v45 = FloatFormat.exp_width % 32;
          v64 = 0;
          for ( j = 0; j < 3; ++j )
          {
            v58 = ~(-1 << v45) & *(&v74 + j);
            *(&v74 + j) = v64 | (*(&v74 + j) >> v45);
            v64 = v58 << (32 - v45);
          }
          v46 = 2;
          v47 = (unsigned int *)(&v76 - v44);
          do
          {
            if ( v46 < v44 )
              *(&v74 + v46) = 0;
            else
              *(&v74 + v46) = *v47;
            --v47;
            --v46;
          }
          while ( v46 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v75 = 0.0;
          v76 = 0;
          v74 = 0x80000000;
          v39 = FloatFormat.exp_width / 32;
          v40 = FloatFormat.exp_width % 32;
          v63 = 0;
          for ( k = 0; k < 3; ++k )
          {
            v41 = (int *)(&v74 + k);
            v57 = ~(-1 << v40) & *v41;
            *v41 = v63 | ((unsigned int)*v41 >> v40);
            v63 = v57 << (32 - v40);
          }
          v42 = 2;
          v43 = (unsigned int *)(&v76 - v39);
          do
          {
            if ( v42 < v39 )
              *(&v74 + v42) = 0;
            else
              *(&v74 + v42) = *v43;
            --v43;
            --v42;
          }
          while ( v42 >= 0 );
          v5 = FloatFormat.max_exp + FloatFormat.bias;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_78;
      }
      v74 = v71;
      v75 = v72;
      v17 = (FloatFormat.min_exp - v53) / 32;
      v76 = v73;
      v18 = (FloatFormat.min_exp - v53) % 32;
      v60 = 0;
      for ( m = 0; m < 3; ++m )
      {
        v19 = (int *)(&v74 + m);
        v54 = ~(-1 << v18) & *v19;
        *v19 = v60 | ((unsigned int)*v19 >> v18);
        v60 = v54 << (32 - v18);
      }
      v20 = 2;
      v21 = (unsigned int *)(&v76 - v17);
      do
      {
        if ( v20 < v17 )
          *(&v74 + v20) = 0;
        else
          *(&v74 + v20) = *v21;
        --v21;
        --v20;
      }
      while ( v20 >= 0 );
      v22 = FloatFormat.precision - 1;
      v23 = FloatFormat.precision / 32;
      v52 = FloatFormat.precision / 32;
      v24 = &v74 + FloatFormat.precision / 32;
      v55 = 31 - FloatFormat.precision % 32;
      if ( ((1 << v55) & *v24) != 0 )
      {
        for ( n = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v74 + v23)) == 0; n; n = *(&v74 + v23) == 0 )
        {
          if ( ++v23 >= 3 )
            goto LABEL_51;
        }
        v26 = v22 / 32;
        v61 = 0;
        v27 = 1 << (31 - v22 % 32);
        v28 = &v74 + v22 / 32;
        v29 = *v28 + v27;
        if ( v29 < *v28 || v29 < v27 )
          v61 = 1;
        *v28 = v29;
        for ( ii = v61; --v26 >= 0 && ii != 0; ii = v33 )
        {
          v31 = &v74 + v26;
          v32 = *v31 + 1;
          v33 = 0;
          if ( v32 < *v31 || *v31 == -1 )
            v33 = 1;
          *v31 = v32;
        }
      }
LABEL_51:
      *v24 &= -1 << v55;
      if ( v52 + 1 < 3 )
        memset(&v74 + v52 + 1, 0, 4 * (3 - (v52 + 1)));
      v34 = (FloatFormat.exp_width + 1) / 32;
      v35 = (FloatFormat.exp_width + 1) % 32;
      v62 = 0;
      for ( jj = 0; jj < 3; ++jj )
      {
        v36 = (int *)(&v74 + jj);
        v56 = ~(-1 << v35) & *v36;
        *v36 = v62 | ((unsigned int)*v36 >> v35);
        v62 = v56 << (32 - v35);
      }
      v37 = 2;
      v38 = (unsigned int *)(&v76 - v34);
      do
      {
        if ( v37 < v34 )
          *(&v74 + v37) = 0;
        else
          *(&v74 + v37) = *v38;
        --v38;
        --v37;
      }
      while ( v37 >= 0 );
    }
    else
    {
      v74 = 0;
      v75 = 0.0;
      v76 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_78;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v74 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_78;
    }
  }
  v74 = 0;
  v75 = 0.0;
  v76 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_78:
  LODWORD(v48) = v74 | (v50 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v49 = v75;
    f[1].f = v48;
    f->f = v49;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v48;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038C47
// Name: __wchartodigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wchartodigit(wchar_t ch)
{
  int v2; // ecx
  wchar_t v3; // dx

  if ( ch < 0x30u )
    return -1;
  if ( ch < 0x3Au )
    return ch - 48;
  v2 = 65296;
  if ( ch >= 0xFF10u )
  {
    v3 = -230;
LABEL_39:
    if ( ch < v3 )
      return ch - v2;
    return -1;
  }
  v2 = 1632;
  if ( ch >= 0x660u )
  {
    if ( ch < 0x66Au )
      return ch - v2;
    v2 = 1776;
    if ( ch >= 0x6F0u )
    {
      if ( ch < 0x6FAu )
        return ch - v2;
      v2 = 2406;
      if ( ch >= 0x966u )
      {
        if ( ch < 0x970u )
          return ch - v2;
        v2 = 2534;
        if ( ch >= 0x9E6u )
        {
          if ( ch < 0x9F0u )
            return ch - v2;
          v2 = 2662;
          if ( ch >= 0xA66u )
          {
            if ( ch < 0xA70u )
              return ch - v2;
            v2 = 2790;
            if ( ch >= 0xAE6u )
            {
              if ( ch < 0xAF0u )
                return ch - v2;
              v2 = 2918;
              if ( ch >= 0xB66u )
              {
                if ( ch < 0xB70u )
                  return ch - v2;
                v2 = 3174;
                if ( ch >= 0xC66u )
                {
                  if ( ch < 0xC70u )
                    return ch - v2;
                  v2 = 3302;
                  if ( ch >= 0xCE6u )
                  {
                    if ( ch < 0xCF0u )
                      return ch - v2;
                    v2 = 3430;
                    if ( ch >= 0xD66u )
                    {
                      if ( ch < 0xD70u )
                        return ch - v2;
                      v2 = 3664;
                      if ( ch >= 0xE50u )
                      {
                        if ( ch < 0xE5Au )
                          return ch - v2;
                        v2 = 3792;
                        if ( ch >= 0xED0u )
                        {
                          if ( ch < 0xEDAu )
                            return ch - v2;
                          v2 = 3872;
                          if ( ch >= 0xF20u )
                          {
                            if ( ch < 0xF2Au )
                              return ch - v2;
                            v2 = 4160;
                            if ( ch >= 0x1040u )
                            {
                              if ( ch < 0x104Au )
                                return ch - v2;
                              v2 = 6112;
                              if ( ch >= 0x17E0u )
                              {
                                if ( ch < 0x17EAu )
                                  return ch - v2;
                                v2 = 6160;
                                if ( ch >= 0x1810u )
                                {
                                  v3 = 6170;
                                  goto LABEL_39;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10038DE7
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  __int64 v4; // rcx
  _LDBL12 *v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // ebx
  int v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // esi
  int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // esi
  unsigned int v17; // esi
  int v18; // edx
  unsigned int v19; // edx
  unsigned int v20; // edi
  int v21; // ecx
  int v22; // edi
  unsigned int v23; // ecx
  __int64 v24; // kr10_8
  unsigned int tmp; // [esp+Ch] [ebp-18h]
  unsigned int tmp_4; // [esp+10h] [ebp-14h]
  int tmp_8; // [esp+14h] [ebp-10h]
  int v28; // [esp+18h] [ebp-Ch]
  unsigned int v29; // [esp+1Ch] [ebp-8h]
  int v30; // [esp+1Ch] [ebp-8h]
  __int16 expn; // [esp+20h] [ebp-4h]
  _LDBL12 *ld12a; // [esp+34h] [ebp+10h]
  int ld12b; // [esp+34h] [ebp+10h]
  int ld12c; // [esp+34h] [ebp+10h]
  int ld12d; // [esp+34h] [ebp+10h]

  HIDWORD(v4) = 0;
  expn = 16462;
  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  *(_DWORD *)&ld12->ld12[8] = 0;
  if ( manlen != 0 )
  {
    ld12a = nullptr;
    do
    {
      tmp = *(_DWORD *)ld12->ld12;
      __SET_PAIR__(tmp_4, v4, *(_QWORD *)ld12->ld12);
      tmp_8 = *(_DWORD *)&ld12->ld12[8];
      v5 = ld12a;
      ld12b = 0;
      v6 = HIDWORD(v4);
      v7 = v4 >> 31;
      v8 = (v6 >> 31) | (2 * (_DWORD)v5);
      v9 = __SPAIR64__(v7, 2 * *(_DWORD *)ld12->ld12) >> 31;
      v29 = v9;
      v10 = 4 * *(_DWORD *)ld12->ld12;
      v11 = (v7 >> 31) | (2 * v8);
      v12 = 5 * *(_DWORD *)ld12->ld12;
      *(_DWORD *)ld12->ld12 = v10;
      *(_DWORD *)&ld12->ld12[4] = v9;
      *(_DWORD *)&ld12->ld12[8] = v11;
      if ( v12 < v10 || v12 < tmp )
        ld12b = 1;
      *(_DWORD *)ld12->ld12 = v12;
      if ( ld12b != 0 )
      {
        ld12c = 0;
        ++v9;
        if ( v29 + 1 < v29 || v29 == -1 )
          ld12c = 1;
        *(_DWORD *)&ld12->ld12[4] = v9;
        if ( ld12c != 0 )
          *(_DWORD *)&ld12->ld12[8] = ++v11;
      }
      ld12d = 0;
      v13 = v9 + tmp_4;
      if ( v9 + tmp_4 < v9 || v13 < tmp_4 )
        ld12d = 1;
      *(_DWORD *)&ld12->ld12[4] = v13;
      if ( ld12d != 0 )
        *(_DWORD *)&ld12->ld12[8] = ++v11;
      v30 = 0;
      v14 = (v13 >> 31) | (2 * (tmp_8 + v11));
      __SET_PAIR__(v16, v15, 2LL * v12);
      HIDWORD(v4) = v16 | (2 * v13);
      *(_DWORD *)&ld12->ld12[8] = v14;
      v28 = v14;
      ld12a = (_LDBL12 *)v14;
      *(_DWORD *)ld12->ld12 = v15;
      *(_DWORD *)&ld12->ld12[4] = HIDWORD(v4);
      v17 = *manptr;
      LODWORD(v4) = v15 + v17;
      if ( v15 + v17 < v15 || (unsigned int)v4 < v17 )
        v30 = 1;
      *(_DWORD *)ld12->ld12 = v4;
      if ( v30 != 0 )
      {
        LODWORD(v4) = HIDWORD(v4) + 1;
        v18 = 0;
        if ( (unsigned int)(HIDWORD(v4) + 1) < HIDWORD(v4) || HIDWORD(v4) == -1 )
          v18 = 1;
        ++HIDWORD(v4);
        *(_DWORD *)&ld12->ld12[4] = v4;
        if ( v18 != 0 )
        {
          ld12a = (_LDBL12 *)(v28 + 1);
          *(_DWORD *)&ld12->ld12[8] = v28 + 1;
        }
      }
      --manlen;
      ++manptr;
      *(_DWORD *)&ld12->ld12[4] = HIDWORD(v4);
      *(_DWORD *)&ld12->ld12[8] = ld12a;
    }
    while ( manlen != 0 );
  }
  if ( *(_DWORD *)&ld12->ld12[8] == 0 )
  {
    v19 = *(_DWORD *)&ld12->ld12[4];
    do
    {
      expn -= 16;
      v20 = HIWORD(v19);
      v19 = HIWORD(*(_DWORD *)ld12->ld12) | (v19 << 16);
      v21 = *(_DWORD *)ld12->ld12 << 16;
      *(_DWORD *)&ld12->ld12[4] = v19;
      *(_DWORD *)ld12->ld12 = v21;
    }
    while ( v20 == 0 );
    *(_DWORD *)&ld12->ld12[8] = v20;
  }
  v22 = *(_DWORD *)&ld12->ld12[8];
  if ( (v22 & 0x8000) == 0 )
  {
    v23 = *(_DWORD *)&ld12->ld12[4];
    do
    {
      --expn;
      v22 = (v23 >> 31) | (2 * v22);
      v24 = 2LL * *(unsigned int *)ld12->ld12;
      v23 = HIDWORD(v24) | (2 * v23);
      *(_DWORD *)ld12->ld12 = v24;
      *(_DWORD *)&ld12->ld12[4] = v23;
      *(_DWORD *)&ld12->ld12[8] = v22;
    }
    while ( (v22 & 0x8000) == 0 );
  }
  *(_WORD *)&ld12->ld12[10] = expn;
}

//------------------------------------------------------------------------------
// Address: 0x10038FCB
// Name: __raise_exc_ex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc_ex(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        float *parg1,
        float *presult,
        int isfloat)
{
  char v7; // cl
  unsigned int *v8; // esi
  char v9; // al
  int v10; // eax
  _FPIEEE_RECORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _FPIEEE_RECORD *v14; // eax
  unsigned int v15; // ecx
  float *v16; // edi
  _FPIEEE_RECORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax

  v7 = flags;
  prec->Cause = 0;
  prec->Enable = 0;
  prec->Status = 0;
  if ( (v7 & 0x10) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 1u;
    flags = -1073741681;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 2u;
    flags = -1073741677;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 4u;
    flags = -1073741679;
  }
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 8u;
    flags = -1073741682;
  }
  if ( (v7 & 8) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 0x10u;
    flags = -1073741680;
  }
  v8 = pcw;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(16 * *pcw)) & 0x10;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(2 * *v8)) & 8;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 1)) & 4;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 3)) & 2;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 5)) & 1;
  v9 = _statfp();
  if ( (v9 & 1) != 0 )
    *(_DWORD *)&prec->Status |= 0x10u;
  if ( (v9 & 4) != 0 )
    *(_DWORD *)&prec->Status |= 8u;
  if ( (v9 & 8) != 0 )
    *(_DWORD *)&prec->Status |= 4u;
  if ( (v9 & 0x10) != 0 )
    *(_DWORD *)&prec->Status |= 2u;
  if ( (v9 & 0x20) != 0 )
    *(_DWORD *)&prec->Status |= 1u;
  v10 = *v8 & 0xC00;
  switch ( v10 )
  {
    case 0:
      *(_DWORD *)prec &= 0xFFFFFFFC;
      break;
    case 1024:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 2;
LABEL_27:
      *(_DWORD *)v11 = v12;
      break;
    case 3072:
      *(_DWORD *)prec |= 3u;
      break;
    default:
      break;
  }
  v13 = *v8 & 0x300;
  switch ( v13 )
  {
    case 0:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 4;
LABEL_36:
      *(_DWORD *)v14 = v15;
      break;
    case 768:
      *(_DWORD *)prec &= 0xFFFFFFE3;
      break;
    default:
      break;
  }
  *(_DWORD *)prec ^= (*(_DWORD *)prec ^ (32 * opcode)) & 0x1FFE0;
  *((_DWORD *)&prec->Operand1 + 4) |= 1u;
  v16 = presult;
  if ( isfloat != 0 )
  {
    *((_DWORD *)&prec->Operand1 + 4) &= 0xFFFFFFE1;
    prec->Operand1.Value.Fp32Value = *parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) &= 0xFFFFFFE1;
    prec->Result.Value.Fp32Value = *v16;
  }
  else
  {
    *((_DWORD *)&prec->Operand1 + 4) = *((_DWORD *)&prec->Operand1 + 4) & 0xFFFFFFE1 | 2;
    prec->Operand1.Value.Fp64Value = *(double *)parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) = *((_DWORD *)&prec->Result + 4) & 0xFFFFFFE1 | 2;
    prec->Result.Value.Fp64Value = *(double *)v16;
  }
  _clrfp();
  RaiseException(
    dwExceptionCode: flags,
    dwExceptionFlags: 0,
    nNumberOfArguments: 1u,
    lpArguments: (const ULONG_PTR *)&prec);
  v17 = prec;
  if ( (*(_BYTE *)&prec->Enable & 0x10) != 0 )
    *v8 &= ~1u;
  if ( (*(_BYTE *)&v17->Enable & 8) != 0 )
    *v8 &= ~4u;
  if ( (*(_BYTE *)&v17->Enable & 4) != 0 )
    *v8 &= ~8u;
  if ( (*(_BYTE *)&v17->Enable & 2) != 0 )
    *v8 &= ~0x10u;
  if ( (*(_BYTE *)&v17->Enable & 1) != 0 )
    *v8 &= ~0x20u;
  v18 = *(_DWORD *)v17 & 3;
  if ( v18 == 0 )
  {
    *v8 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v19 = v18 - 1;
  if ( v19 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v20 = v19 - 1;
  if ( v20 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v8 = v21;
    goto LABEL_59;
  }
  if ( v20 == 1 )
    *v8 |= 0xC00u;
LABEL_59:
  v22 = (*(_DWORD *)v17 >> 2) & 7;
  if ( v22 == 0 )
  {
    v24 = *v8 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v23 = v22 - 1;
  if ( v23 == 0 )
  {
    v24 = *v8 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v8 = v24;
    goto LABEL_66;
  }
  if ( v23 == 1 )
    *v8 &= 0xFFFFF3FF;
LABEL_66:
  if ( isfloat != 0 )
    *v16 = v17->Result.Value.Fp32Value;
  else
    *(double *)v16 = v17->Result.Value.Fp64Value;
}

//------------------------------------------------------------------------------
// Address: 0x100392A7
// Name: __handle_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _handle_exc(char flags, long double *presult, __int16 cw)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  long double dbl; // st7
  BOOL v7; // esi
  int v8; // ecx
  double v9; // st7
  BOOL v10; // edx
  int v11; // eax
  double v13; // [esp+18h] [ebp-14h]
  int expn; // [esp+24h] [ebp-8h] BYREF
  int flags_p; // [esp+28h] [ebp-4h]

  v3 = flags & 0x1F;
  flags_p = v3;
  if ( (flags & 8) != 0 && (cw & 1) != 0 )
  {
    _set_statfp(sw: 1u);
    v3 = flags & 0x17;
    goto LABEL_46;
  }
  if ( (flags & 4) != 0 && (cw & 4) != 0 )
  {
    _set_statfp(sw: 4u);
    v3 = flags & 0x1B;
    goto LABEL_46;
  }
  if ( (flags & 1) != 0 && (cw & 8) != 0 )
  {
    _set_statfp(sw: 8u);
    v4 = cw & 0xC00;
    if ( (cw & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = flags & 0x1E;
            goto LABEL_46;
          }
          v5 = presult;
          dbl = _d_max.dbl;
          if ( *presult <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = dbl;
          goto LABEL_24;
        }
        v5 = presult;
        if ( *presult <= 0.0 )
        {
          dbl = _d_max.dbl;
LABEL_22:
          dbl = -dbl;
          goto LABEL_23;
        }
LABEL_20:
        dbl = _d_inf.dbl;
        goto LABEL_23;
      }
      v5 = presult;
      if ( *presult > 0.0 )
      {
        dbl = _d_max.dbl;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = presult;
      if ( *presult > 0.0 )
        goto LABEL_20;
    }
    dbl = _d_inf.dbl;
    goto LABEL_22;
  }
  if ( (flags & 2) != 0 && (cw & 0x10) != 0 )
  {
    v7 = (flags & 0x10) != 0;
    if ( 0.0 == *presult )
    {
      v7 = true;
      goto LABEL_43;
    }
    v13 = _decomp(x: *presult, pexp: &expn);
    v8 = expn - 1536;
    if ( expn - 1536 >= -1074 )
    {
      v10 = v13 < 0.0;
      HIWORD(v13) = BYTE6(v13) & 0xF | 0x10;
      if ( v8 < -1021 )
      {
        v11 = -1021 - v8;
        do
        {
          if ( (LOBYTE(v13) & 1) != 0 && !v7 )
            v7 = true;
          LODWORD(v13) >>= 1;
          if ( (BYTE4(v13) & 1) != 0 )
            LODWORD(v13) |= 0x80000000;
          HIDWORD(v13) >>= 1;
          --v11;
        }
        while ( v11 != 0 );
      }
      if ( !v10 )
        goto LABEL_41;
      v9 = -v13;
    }
    else
    {
      v7 = true;
      v9 = v13 * 0.0;
    }
    v13 = v9;
LABEL_41:
    *presult = v13;
LABEL_43:
    if ( v7 )
      _set_statfp(sw: 0x10u);
    flags_p &= ~2u;
    v3 = flags_p;
  }
LABEL_46:
  if ( (flags & 0x10) != 0 && (cw & 0x20) != 0 )
  {
    _set_statfp(sw: 0x20u);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003948B
// Name: __set_errno_from_matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_errno_from_matherr(int matherrtype)
{
  if ( matherrtype == 1 )
  {
    *_errno() = 33;
  }
  else if ( matherrtype > 1 && matherrtype <= 3 )
  {
    *_errno() = 34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100394B8
// Name: __errcode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _errcode(char flags)
{
  if ( (flags & 0x20) != 0 )
    return 5;
  if ( (flags & 8) != 0 )
    return 1;
  if ( (flags & 4) != 0 )
    return 2;
  if ( (flags & 1) != 0 )
    return 3;
  return 2 * (flags & 2);
}

//------------------------------------------------------------------------------
// Address: 0x100394EC
// Name: __umatherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _umatherr(
        int type,
        unsigned int opcode,
        long double arg1,
        long double arg2,
        long double retval,
        unsigned int cw)
{
  int v6; // eax
  char *v7; // eax

  v6 = 0;
  while ( dword_10050738[2 * v6] != opcode )
  {
    if ( ++v6 >= 29 )
    {
      v7 = nullptr;
      goto LABEL_5;
    }
  }
  v7 = (&off_1005073C)[2 * v6];
LABEL_5:
  if ( v7 != nullptr )
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    if ( __init_collate() == 0 )
      _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
  else
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003958C
// Name: __handle_qnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _handle_qnan1(unsigned int opcode, long double x, unsigned int savedcw)
{
  if ( _matherr_flag == 0 )
    return _umatherr(type: 1, opcode, arg1: x, arg2: 0.0, retval: x, cw: savedcw);
  *_errno() = 33;
  _ctrlfp(newctrl: savedcw, _mask: 0xFFFFu);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x100395E1
// Name: __except1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _except1@<st0>(
        int a1@<ebp>,
        int flags,
        int opcode,
        long double arg,
        long double result,
        unsigned int cw)
{
  int v6; // eax
  int v8; // [esp+1Ch] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+28h] [ebp-80h]
  int v10; // [esp+9Ch] [ebp-Ch]
  void *v11; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v10 = a1;
  v11 = retaddr;
  if ( !_handle_exc(flags, presult: &result, cw) )
  {
    rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
    _raise_exc_ex(
      prec: (_FPIEEE_RECORD *)&v8,
      pcw: &cw,
      flags,
      opcode,
      parg1: (float *)&arg,
      presult: (float *)&result,
      isfloat: 0);
  }
  v6 = _errcode(flags);
  if ( _matherr_flag == 0 && v6 != 0 )
    return _umatherr(type: v6, opcode, arg1: arg, arg2: 0.0, retval: result, cw);
  _set_errno_from_matherr(matherrtype: v6);
  _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100396AB
// Name: __frnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _frnd(long double x)
{
  return rint(x);
}

//------------------------------------------------------------------------------
// Address: 0x100396BF
// Name: __set_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _set_exp(long double x, __int16 exp)
{
  long double retval; // [esp+0h] [ebp-8h]

  retval = x;
  HIWORD(retval) = HIWORD(x) & 0x800F | (16 * (exp + 1022));
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x100396EC
// Name: __sptype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sptype(long double x)
{
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
      return 1;
  }
  else if ( x == -INFINITY )
  {
    return 2;
  }
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF8 )
    return 3;
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF0 && ((HIDWORD(x) & 0x7FFFF) != 0 || LODWORD(x) != 0) )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039752
// Name: __decomp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _decomp(long double x, int *pexp)
{
  long double result; // st7
  int v3; // edx
  int v4; // edx
  BOOL v5; // eax

  result = 0.0;
  if ( 0.0 == x )
  {
    v3 = 0;
  }
  else if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
  {
    v4 = -1021;
    v5 = x < 0.0;
    while ( (BYTE6(x) & 0x10) == 0 )
    {
      HIDWORD(x) *= 2;
      if ( SLODWORD(x) < 0 )
        HIDWORD(x) |= 1u;
      LODWORD(x) *= 2;
      --v4;
    }
    HIWORD(x) &= ~0x10u;
    if ( v5 )
      HIWORD(x) |= 0x8000u;
    result = _set_exp(x, exp: 0);
  }
  else
  {
    result = _set_exp(x, exp: 0);
    v3 = ((HIWORD(x) >> 4) & 0x7FF) - 1022;
  }
  *pexp = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039815
// Name: __statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _statfp@<eax>(__int16 a1@<fpstat>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10039825
// Name: __clrfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _clrfp@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10039836
// Name: __ctrlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _ctrlfp()
{
  __int16 oldCw; // [esp+0h] [ebp-4h]

  return oldCw;
}

//------------------------------------------------------------------------------
// Address: 0x10039861
// Name: __set_statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_statfp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100398B9
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
// Address: 0x1003992B
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
// Address: 0x10039964
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _stricmp_l(const char *dst, const char *src, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  const char *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( dst != nullptr )
  {
    v4 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
          v6 = _tolower_l(c: *(unsigned __int8 *)v4++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v5 != 0 && v5 == v6 );
        result = v5 - v6;
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
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039A24
// Name: __stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _stricmp(const char *dst, const char *src)
{
  if ( __locale_changed != 0 )
    return _stricmp_l(dst, src, plocinfo: nullptr);
  if ( dst != nullptr && src != nullptr )
    return __ascii_stricmp(dst, src);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10039A6B
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp_l(char *dst, char *src, unsigned int count, localeinfo_struct *plocinfo)
{
  char *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (v4 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
            v6 = _tolower_l(c: (unsigned __int8)*v4++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v5 != 0 && v5 == v6 );
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
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039B4D
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp(char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039BA0
// Name: xtoa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge xtoa_s@<eax>(
        unsigned int val@<eax>,
        char *buf@<ecx>,
        unsigned int sizeInTChars,
        unsigned int radix,
        int is_neg)
{
  char *v5; // esi
  unsigned int v6; // ebx
  int *v8; // eax
  char *v9; // edi
  char v10; // dl
  unsigned int v11; // et2
  char v12; // dl
  char *v13; // ecx
  char v14; // al
  int v15; // [esp-8h] [ebp-10h]

  v5 = buf;
  v6 = 0;
  if ( buf == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  if ( sizeInTChars == 0 )
    goto LABEL_4;
  *buf = 0;
  if ( sizeInTChars <= (unsigned int)(is_neg != 0) + 1 )
  {
LABEL_7:
    v8 = _errno();
    v15 = 34;
    goto LABEL_5;
  }
  if ( radix - 2 > 0x22 )
  {
LABEL_4:
    v8 = _errno();
    v15 = 22;
LABEL_5:
    *v8 = v15;
    _invalid_parameter_noinfo();
    return v15;
  }
  if ( is_neg != 0 )
  {
    v6 = 1;
    *buf++ = 45;
    val = -val;
  }
  v9 = buf;
  do
  {
    v11 = val % radix;
    val /= radix;
    v10 = v11;
    if ( v11 <= 9 )
      v12 = v10 + 48;
    else
      v12 = v10 + 87;
    *buf++ = v12;
    ++v6;
  }
  while ( val != 0 && v6 < sizeInTChars );
  if ( v6 >= sizeInTChars )
  {
    *v5 = 0;
    goto LABEL_7;
  }
  *buf = 0;
  v13 = buf - 1;
  do
  {
    v14 = *v13;
    *v13-- = *v9;
    *v9++ = v14;
  }
  while ( v9 < v13 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039C5A
// Name: __itoa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _itoa_s(int val, char *buf, unsigned int sizeInTChars, unsigned int radix)
{
  if ( radix == 10 && val < 0 )
    return xtoa_s(val, buf, sizeInTChars, radix: 0xAu, is_neg: 1);
  else
    return xtoa_s(val, buf, sizeInTChars, radix, is_neg: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10039C84
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  unsigned __int16 v4; // dx
  int v6; // eax
  int v7; // eax
  __int16 v8; // ax
  int v9; // ebx
  bool v10; // zf
  char v11; // cl
  int v12; // ecx
  _LDBL12 *p_tmp12; // eax
  unsigned __int8 *v14; // esi
  __int16 v15; // cx
  unsigned __int16 v16; // di
  _WORD *v17; // esi
  unsigned int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // eax
  __int16 v21; // di
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // esi
  int v27; // ecx
  unsigned __int16 v28; // si
  int v29; // eax
  _WORD *v30; // edi
  unsigned __int8 *v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  __int16 v35; // si
  unsigned int v36; // ecx
  unsigned int v37; // edx
  int v38; // eax
  unsigned int v39; // ecx
  int v40; // edi
  int v41; // ecx
  int v42; // edi
  int v43; // esi
  unsigned int v44; // eax
  int v45; // ebx
  int v46; // eax
  int v47; // esi
  int v48; // eax
  int v49; // ebx
  int v50; // eax
  char *man; // ebx
  unsigned int v52; // edx
  unsigned int v53; // edi
  unsigned int v54; // ecx
  int v55; // esi
  int v56; // ecx
  unsigned int v57; // esi
  unsigned int v58; // edi
  int v59; // edx
  unsigned int v60; // edx
  char v61; // al
  char *v62; // ebx
  _FloatOutStruct *v63; // eax
  char v64; // bl
  unsigned __int8 *v65; // [esp+10h] [ebp-70h]
  unsigned __int8 *v66; // [esp+14h] [ebp-6Ch]
  _LDBL12 *v67; // [esp+18h] [ebp-68h]
  __int16 sign; // [esp+20h] [ebp-60h]
  int v69; // [esp+24h] [ebp-5Ch]
  __int16 v70; // [esp+24h] [ebp-5Ch]
  __int16 v71; // [esp+28h] [ebp-58h]
  unsigned __int8 *v72; // [esp+28h] [ebp-58h]
  int v73; // [esp+2Ch] [ebp-54h]
  int v74; // [esp+2Ch] [ebp-54h]
  int v75; // [esp+30h] [ebp-50h]
  int v76; // [esp+30h] [ebp-50h]
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  int v79; // [esp+38h] [ebp-48h]
  int v80; // [esp+38h] [ebp-48h]
  _LDBL12 *v81; // [esp+3Ch] [ebp-44h]
  int v82; // [esp+3Ch] [ebp-44h]
  int v83; // [esp+3Ch] [ebp-44h]
  unsigned int v84; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v87; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v91[12]; // [esp+70h] [ebp-10h] BYREF

  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  v4 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 8);
  *(_DWORD *)&ld12_one_tenth.ld12[8] = 1073466572;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  if ( v4 != 0 )
  {
    if ( v4 != 0x7FFF )
      goto LABEL_28;
    fos->exp = 1;
    if ( (*(_DWORD *)&ld.ld[4] != 0x80000000 || *(_DWORD *)ld.ld != 0) && (*(_DWORD *)&ld.ld[4] & 0x40000000) == 0 )
    {
      v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#SNAN");
      goto LABEL_25;
    }
    if ( sign != 0 && *(_DWORD *)&ld.ld[4] == -1073741824 )
    {
      if ( *(_DWORD *)ld.ld == 0 )
      {
        v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#IND");
        goto LABEL_22;
      }
    }
    else if ( *(_DWORD *)&ld.ld[4] == 0x80000000 && *(_DWORD *)ld.ld == 0 )
    {
      v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#INF");
LABEL_22:
      if ( v7 == 0 )
      {
        fos->ManLen = 5;
        return 0;
      }
LABEL_14:
      _invoke_watson(a1: *(unsigned int *)ld.ld);
    }
    v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#QNAN");
LABEL_25:
    if ( v6 == 0 )
    {
      fos->ManLen = 6;
      return 0;
    }
    goto LABEL_14;
  }
  if ( *(_DWORD *)&ld.ld[4] == 0 && *(_DWORD *)ld.ld == 0 )
  {
    fos->exp = 0;
    fos->sign = sign != -32768 ? 32 : 45;
    *(_WORD *)&fos->ManLen = 12289;
    fos->man[1] = 0;
    return 1;
  }
LABEL_28:
  v8 = (77 * (HIBYTE(v4) + 2 * ld.ld[7]) + 19728 * (unsigned int)v4 - 323162868) >> 16;
  *(_WORD *)ld12.ld12 = 0;
  v9 = -v8;
  digcount = v8;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&ld.ld[4];
  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)ld.ld;
  v67 = &_pow10pos[-8];
  if ( v8 != 0 )
  {
    v10 = v8 == 0;
    if ( v8 > 0 )
    {
      v9 = v8;
      v67 = &_pow10neg[-8];
      v10 = v8 == 0;
    }
    if ( !v10 )
    {
      do
      {
        v67 += 7;
        v11 = v9;
        v9 >>= 3;
        v12 = v11 & 7;
        if ( v12 != 0 )
        {
          p_tmp12 = &v67[v12];
          v81 = p_tmp12;
          if ( *(_WORD *)p_tmp12->ld12 >= 0x8000u )
          {
            *(_DWORD *)tmp12.ld12 = *(_DWORD *)p_tmp12->ld12;
            *(_DWORD *)&tmp12.ld12[4] = *(_DWORD *)&p_tmp12->ld12[4];
            v14 = &p_tmp12->ld12[8];
            p_tmp12 = &tmp12;
            *(_DWORD *)&tmp12.ld12[8] = *(_DWORD *)v14;
            --*(_DWORD *)&tmp12.ld12[2];
            v81 = &tmp12;
          }
          v79 = 0;
          memset(v91, 0, sizeof(v91));
          v71 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000;
          v15 = *(_WORD *)&p_tmp12->ld12[10] & 0x7FFF;
          v16 = v15 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
          if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
            || (*(_WORD *)&p_tmp12->ld12[10] & 0x7FFF) == 0x7FFF
            || v16 > 0xBFFDu )
          {
            *(_DWORD *)&ld12.ld12[8] = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000u) == 0
                                     ? 2147450880
                                     : -32768;
          }
          else
          {
            if ( v16 > 0x3FBFu )
            {
              if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
              {
                ++v16;
                if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
                  && *(_DWORD *)&ld12.ld12[4] == 0
                  && *(_DWORD *)ld12.ld12 == 0 )
                {
                  *(_WORD *)&ld12.ld12[10] = 0;
                  continue;
                }
              }
              if ( v15 != 0
                || (++v16, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&p_tmp12->ld12[4] != 0
                || *(_DWORD *)p_tmp12->ld12 != 0 )
              {
                v73 = 0;
                v17 = &v91[4];
                for ( i = 5; i > 0; --i )
                {
                  v75 = i;
                  v65 = &ld12.ld12[2 * v73];
                  v66 = &p_tmp12->ld12[8];
                  do
                  {
                    v18 = *((_DWORD *)v17 - 1);
                    v19 = *(unsigned __int16 *)v66 * *(unsigned __int16 *)v65;
                    v69 = 0;
                    v20 = v18 + v19;
                    if ( v18 + v19 < v18 || v20 < v19 )
                      v69 = 1;
                    *((_DWORD *)v17 - 1) = v20;
                    if ( v69 != 0 )
                      ++*v17;
                    v65 += 2;
                    v66 -= 2;
                    --v75;
                  }
                  while ( v75 > 0 );
                  p_tmp12 = v81;
                  ++v17;
                  ++v73;
                }
                v21 = v16 - 16382;
                if ( v21 <= 0 )
                  goto LABEL_172;
                do
                {
                  if ( *(int *)&v91[8] < 0 )
                    break;
                  v22 = *(_DWORD *)v91;
                  *(_DWORD *)v91 *= 2;
                  v23 = *(_DWORD *)&v91[4];
                  *(_DWORD *)&v91[4] = (v22 >> 31) | (2 * *(_DWORD *)&v91[4]);
                  --v21;
                  *(_DWORD *)&v91[8] = (v23 >> 31) | (2 * *(_DWORD *)&v91[8]);
                }
                while ( v21 > 0 );
                if ( v21 <= 0 )
                {
LABEL_172:
                  if ( --v21 < 0 )
                  {
                    v24 = (unsigned __int16)-v21;
                    v21 = 0;
                    do
                    {
                      if ( (v91[0] & 1) != 0 )
                        ++v79;
                      v25 = *(_DWORD *)&v91[8];
                      *(_DWORD *)&v91[8] >>= 1;
                      v26 = __SPAIR64__(v25, *(unsigned int *)&v91[4]) >> 1;
                      v27 = *(__int64 *)v91 >> 1;
                      --v24;
                      *(_DWORD *)&v91[4] = v26;
                      *(_DWORD *)v91 = v27;
                    }
                    while ( v24 != 0 );
                    if ( v79 != 0 )
                      *(_WORD *)v91 |= 1u;
                  }
                }
                if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
                {
                  if ( *(_DWORD *)&v91[2] == -1 )
                  {
                    *(_DWORD *)&v91[2] = 0;
                    if ( *(_DWORD *)&v91[6] == -1 )
                    {
                      *(_DWORD *)&v91[6] = 0;
                      if ( *(_WORD *)&v91[10] == 0xFFFF )
                      {
                        *(_WORD *)&v91[10] = 0x8000;
                        ++v21;
                      }
                      else
                      {
                        ++*(_WORD *)&v91[10];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v91[6];
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)&v91[2];
                  }
                }
                if ( (unsigned __int16)v21 < 0x7FFFu )
                {
                  *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
                  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
                  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
                  *(_WORD *)&ld12.ld12[10] = v71 | v21;
                }
                else
                {
                  *(_DWORD *)&ld12.ld12[4] = 0;
                  *(_DWORD *)ld12.ld12 = 0;
                  *(_DWORD *)&ld12.ld12[8] = v71 == 0 ? 2147450880 : -32768;
                }
                continue;
              }
            }
            *(_DWORD *)&ld12.ld12[8] = 0;
          }
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
        }
      }
      while ( v9 != 0 );
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] < 0x3FFFu )
    goto LABEL_134;
  ++digcount;
  v76 = 0;
  memset(v91, 0, sizeof(v91));
  v70 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
  v28 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
  if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
    || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
    || v28 > 0xBFFDu )
  {
    *(_DWORD *)&ld12.ld12[4] = 0;
    v29 = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) == 0 ? 2147450880 : -32768;
    *(_DWORD *)ld12.ld12 = 0;
  }
  else
  {
    if ( v28 > 0x3FBFu )
    {
      v29 = 0;
      if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
      {
        ++v28;
        if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0 && *(_DWORD *)&ld12.ld12[4] == 0 && *(_DWORD *)ld12.ld12 == 0 )
        {
          *(_WORD *)&ld12.ld12[10] = 0;
          goto LABEL_134;
        }
      }
      if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
        || (++v28, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
        || *(_DWORD *)&ld12_one_tenth.ld12[4] != 0
        || *(_DWORD *)ld12_one_tenth.ld12 != 0 )
      {
        v74 = 0;
        v30 = &v91[4];
        for ( j = 5; j > 0; --j )
        {
          v80 = j;
          v72 = &ld12_one_tenth.ld12[8];
          v31 = &ld12.ld12[2 * v74];
          do
          {
            v82 = 0;
            v32 = *(unsigned __int16 *)v31 * *(unsigned __int16 *)v72;
            v33 = *((_DWORD *)v30 - 1);
            v34 = v33 + v32;
            if ( v33 + v32 < v33 || v34 < v32 )
              v82 = 1;
            *((_DWORD *)v30 - 1) = v34;
            if ( v82 != 0 )
              ++*v30;
            v72 -= 2;
            v31 += 2;
            --v80;
          }
          while ( v80 > 0 );
          ++v30;
          ++v74;
        }
        v35 = v28 - 16382;
        if ( v35 <= 0 )
          goto LABEL_173;
        do
        {
          if ( *(int *)&v91[8] < 0 )
            break;
          v36 = *(_DWORD *)v91;
          *(_DWORD *)v91 *= 2;
          v37 = *(_DWORD *)&v91[4];
          *(_DWORD *)&v91[4] = (v36 >> 31) | (2 * *(_DWORD *)&v91[4]);
          --v35;
          *(_DWORD *)&v91[8] = (v37 >> 31) | (2 * *(_DWORD *)&v91[8]);
        }
        while ( v35 > 0 );
        if ( v35 <= 0 )
        {
LABEL_173:
          if ( --v35 < 0 )
          {
            v38 = (unsigned __int16)-v35;
            v35 = 0;
            do
            {
              if ( (v91[0] & 1) != 0 )
                ++v76;
              v39 = *(_DWORD *)&v91[8];
              *(_DWORD *)&v91[8] >>= 1;
              v40 = __SPAIR64__(v39, *(unsigned int *)&v91[4]) >> 1;
              v41 = *(__int64 *)v91 >> 1;
              --v38;
              *(_DWORD *)&v91[4] = v40;
              *(_DWORD *)v91 = v41;
            }
            while ( v38 != 0 );
            if ( v76 != 0 )
              *(_WORD *)v91 |= 1u;
          }
        }
        if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
        {
          if ( *(_DWORD *)&v91[2] == -1 )
          {
            *(_DWORD *)&v91[2] = 0;
            if ( *(_DWORD *)&v91[6] == -1 )
            {
              *(_DWORD *)&v91[6] = 0;
              if ( *(_WORD *)&v91[10] == 0xFFFF )
              {
                *(_WORD *)&v91[10] = 0x8000;
                ++v35;
              }
              else
              {
                ++*(_WORD *)&v91[10];
              }
            }
            else
            {
              ++*(_DWORD *)&v91[6];
            }
          }
          else
          {
            ++*(_DWORD *)&v91[2];
          }
        }
        if ( (unsigned __int16)v35 < 0x7FFFu )
        {
          *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
          *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
          *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
          *(_WORD *)&ld12.ld12[10] = v70 | v35;
        }
        else
        {
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
          *(_DWORD *)&ld12.ld12[8] = v70 == 0 ? 2147450880 : -32768;
        }
        goto LABEL_134;
      }
    }
    else
    {
      v29 = 0;
    }
    *(_DWORD *)&ld12.ld12[4] = 0;
    *(_DWORD *)ld12.ld12 = 0;
  }
  *(_DWORD *)&ld12.ld12[8] = v29;
LABEL_134:
  v42 = ndigits;
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    v42 = digcount + ndigits;
    if ( v42 <= 0 )
    {
      fos->exp = 0;
      *(_WORD *)&fos->ManLen = 12289;
      fos->sign = sign != -32768 ? 32 : 45;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( v42 > 21 )
    v42 = 21;
  v43 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  v83 = 8;
  do
  {
    v44 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v45 = (v44 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v46 = *(__int64 *)&ld12.ld12[4] >> 31;
    v10 = v83-- == 1;
    *(_DWORD *)&ld12.ld12[4] = v45;
    *(_DWORD *)&ld12.ld12[8] = v46;
  }
  while ( !v10 );
  if ( v43 < 0 )
  {
    v47 = (unsigned __int8)-(char)v43;
    if ( v47 != 0 )
    {
      do
      {
        v48 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v49 = (v48 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v50 = *(__int64 *)ld12.ld12 >> 1;
        --v47;
        *(_DWORD *)&ld12.ld12[4] = v49;
        *(_DWORD *)ld12.ld12 = v50;
      }
      while ( v47 > 0 );
    }
  }
  man = fos->man;
  v87 = fos->man;
  for ( digcounta = v42 + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v52 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v53 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v54 = (v52 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v55 = 2 * v54;
    v56 = (v54 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v57 = (v53 >> 31) | v55;
    v58 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v58 < *(_DWORD *)tmp12.ld12 )
    {
      v59 = 0;
      if ( v57 + 1 < v57 || v57 == -1 )
        v59 = 1;
      ++v57;
      if ( v59 != 0 )
        ++v56;
    }
    v60 = *(_DWORD *)&tmp12.ld12[4] + v57;
    v84 = *(_DWORD *)&tmp12.ld12[4] + v57;
    if ( *(_DWORD *)&tmp12.ld12[4] + v57 < v57 || v60 < *(_DWORD *)&tmp12.ld12[4] )
      ++v56;
    *(_DWORD *)ld12.ld12 = 2 * v58;
    *(_DWORD *)&ld12.ld12[8] = (v60 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v56));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v58 >> 31) | (2 * v84);
  }
  v61 = *(man - 1);
  v62 = man - 2;
  if ( v61 >= 53 )
  {
    while ( v62 >= v87 && *v62 == 57 )
      *v62-- = 48;
    v63 = fos;
    if ( v62 < v87 )
    {
      ++v62;
      ++fos->exp;
    }
    ++*v62;
  }
  else
  {
    while ( v62 >= v87 && *v62 == 48 )
      --v62;
    v63 = fos;
    if ( v62 < v87 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != -32768 ? 32 : 45;
      *v87 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v64 = (_BYTE)v62 - (_BYTE)v63 - 3;
  v63->ManLen = v64;
  v63->man[v64] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A57C
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
// Address: 0x1003A60A
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
// Address: 0x1003A6AA
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // [esp+14h] [ebp-Ch]
  __int16 oldCw; // [esp+1Ch] [ebp-4h]
  unsigned int newabs; // [esp+2Ch] [ebp+Ch]

  v2 = 0;
  if ( (oldCw & 1) != 0 )
    v2 = 16;
  if ( (oldCw & 4) != 0 )
    v2 |= 8u;
  if ( (oldCw & 8) != 0 )
    v2 |= 4u;
  if ( (oldCw & 0x10) != 0 )
    v2 |= 2u;
  if ( (oldCw & 0x20) != 0 )
    v2 |= 1u;
  if ( (oldCw & 2) != 0 )
    v2 |= 0x80000u;
  v3 = oldCw & 0xC00;
  if ( (oldCw & 0xC00) != 0 )
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
  if ( (oldCw & 0x300) != 0 )
  {
    if ( (oldCw & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (oldCw & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  newabs = result;
  if ( result != v2 )
  {
    v6 = hw_cw(abstr: result);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    newabs = v8;
    result = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
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
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
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
    v15 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v18 = 0;
      if ( (v17 & 0x80u) != 0 )
        v18 = 16;
      if ( (v17 & 0x200) != 0 )
        v18 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v18 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v18 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v18 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v18 |= 0x80000u;
      v19 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v19 )
        {
          case 8192:
            v18 |= 0x100u;
            break;
          case 16384:
            v18 |= 0x200u;
            break;
          case 24576:
            v18 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v20 = (v17 & 0x8040) - 64;
      if ( v20 != 0 )
      {
        v21 = v20 - 32704;
        if ( v21 != 0 )
        {
          if ( v21 == 64 )
            v18 |= 0x1000000u;
        }
        else
        {
          v18 |= 0x3000000u;
        }
      }
      else
      {
        v18 |= 0x2000000u;
      }
      v16 = v18;
    }
    v22 = newabs ^ v16;
    result = newabs | v16;
    if ( (v22 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A9BC
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  unsigned int cchWritten; // [esp+0h] [ebp-4h] BYREF

  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1
    || !WriteConsoleW(
          hConsoleOutput: _confh,
          lpBuffer: &ch,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: &cchWritten,
          lpReserved: nullptr) )
  {
    return -1;
  }
  else
  {
    return ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A9FE
// Name: __flswbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flswbuf(unsigned __int16 ch, _iobuf *str)
{
  int flag; // eax
  int v5; // eax
  unsigned int v6; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v9; // edi
  ioinfo *v10; // eax
  doubleint v11; // rax
  unsigned __int16 v12; // bx
  char mbc[4]; // [esp+4h] [ebp-4h] BYREF
  int fh; // [esp+14h] [ebp+Ch]

  fh = _fileno(stream: str);
  flag = str->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    str->_flag |= 0x20u;
    return 0xFFFF;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    str->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      str->_flag = flag | 0x20;
      return 0xFFFF;
    }
    str->_ptr = str->_base;
    str->_flag = flag & 0xFFFFFFFE;
  }
  v5 = str->_flag;
  str->_cnt = 0;
  *(_DWORD *)mbc = 0;
  v6 = v5 & 0xFFFFFFED | 2;
  str->_flag = v6;
  if ( (v6 & 0x10C) == 0 && (str != &__iob_func()[1] && str != &__iob_func()[2] || _isatty(fh) == 0) )
    _getbuf(str);
  if ( (str->_flag & 0x108) != 0 )
  {
    base = str->_base;
    ptr = str->_ptr;
    str->_ptr = base + 2;
    v9 = ptr - base;
    str->_cnt = str->_bufsiz - 2;
    if ( v9 <= 0 )
    {
      if ( fh == -1 || fh == -2 )
        v10 = &__badioinfo;
      else
        v10 = &__pioinfo[fh >> 5][fh & 0x1F];
      if ( (v10->osfile & 0x20) != 0 )
      {
        v11.bigint = _lseeki64(fh, pos: 0, mthd: 2u).bigint;
        if ( (v11.twoints.upperhalf & v11.twoints.lowerhalf) == -1 )
          goto LABEL_28;
      }
    }
    else
    {
      *(_DWORD *)mbc = _write(fh, buf: base, cnt: v9);
    }
    v12 = ch;
    *(_WORD *)str->_base = ch;
  }
  else
  {
    v9 = 2;
    v12 = ch;
    *(_WORD *)mbc = ch;
    *(_DWORD *)mbc = _write(fh, buf: mbc, cnt: 2u);
  }
  if ( *(_DWORD *)mbc != v9 )
  {
LABEL_28:
    str->_flag |= 0x20u;
    return 0xFFFF;
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1003AB80
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
// Address: 0x1003ABE1
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONOUT$",
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
// Address: 0x1003AC00
// Name: ___termconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconout()
{
  HANDLE result; // eax

  result = _confh;
  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _confh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003AC20
// Name: public: virtual _com_error::~_com_error(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _com_error::~_com_error(_com_error *this)
{
  IErrorInfo *m_perrinfo; // eax
  char *m_pszMsg; // esi

  m_perrinfo = this->m_perrinfo;
  this->__vftable = (_com_error_vtbl *)&_com_error::`vftable';
  if ( m_perrinfo != nullptr )
    m_perrinfo->Release(this: m_perrinfo);
  m_pszMsg = this->m_pszMsg;
  if ( m_pszMsg != nullptr )
    LocalFree(hMem: m_pszMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1003AC50
// Name: void _com_raise_error(long,struct IErrorInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn _com_raise_error(HRESULT hr, IErrorInfo *perrinfo)
{
  _DWORD pExceptionObject[4]; // [esp+0h] [ebp-10h] BYREF

  pExceptionObject[0] = &_com_error::`vftable';
  pExceptionObject[1] = hr;
  pExceptionObject[2] = perrinfo;
  pExceptionObject[3] = 0;
  _CxxThrowException(pExceptionObject, pThrowInfo: &_TI1_AV_com_error__);
}

//------------------------------------------------------------------------------
// Address: 0x1003AC90
// Name: public: _com_error::_com_error(class _com_error const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_com_error *__thiscall _com_error::_com_error(_com_error *this, const _com_error *that)
{
  IErrorInfo *m_perrinfo; // edx

  this->__vftable = (_com_error_vtbl *)&_com_error::`vftable';
  this->m_hresult = that->m_hresult;
  m_perrinfo = that->m_perrinfo;
  this->m_perrinfo = m_perrinfo;
  this->m_pszMsg = nullptr;
  if ( m_perrinfo != nullptr )
    m_perrinfo->AddRef(this: m_perrinfo);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003AD12
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x1003AD18
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003AE96
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003AECA
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003AF2E
// Name: ___DestructExceptionObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __DestructExceptionObject(EHExceptionRecord *pExcept)
{
  const _s_ThrowInfo *pThrowInfo; // eax
  void (__cdecl *pmfnUnwind)(); // eax

  if ( pExcept != nullptr && pExcept->ExceptionCode == -529697949 )
  {
    pThrowInfo = pExcept->params.pThrowInfo;
    if ( pThrowInfo != nullptr )
    {
      pmfnUnwind = pThrowInfo->pmfnUnwind;
      if ( pmfnUnwind != nullptr )
        _CallMemberFunction0(pthis: pExcept->params.pExceptionObject, pmfn: pmfnUnwind);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AF90
// Name: _CallSettingFrame(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _CallSettingFrame(unsigned int funclet, unsigned int pRN, unsigned int dwInCode)
{
  void (*v3)(void); // eax
  int v4; // ecx

  _NLG_Notify1(a1: dwInCode);
  v3();
  v4 = dwInCode;
  if ( dwInCode == 256 )
    v4 = 2;
  _NLG_Notify1(a1: v4);
}

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10018E70
// Name: void ApplyRotaryEffectToTexture(int,int,unsigned char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyRotaryEffectToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, bool bRotary)
{
  int v4; // ecx
  unsigned __int8 *v5; // eax

  if ( bRotary )
  {
    v4 = rgbaWide;
    v5 = &rgba[-4 * rgbaWide * (int)((double)rgbaTall * -0.5)];
    if ( rgbaWide > 0 )
    {
      do
      {
        *v5 = 127;
        v5[1] = 127;
        v5[2] = 127;
        v5[3] = -1;
        v5 += 4;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018EC0
// Name: void ApplyScanlineEffectToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyScanlineEffectToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iScanLines)
{
  int i; // esi
  unsigned __int8 *v6; // eax
  int j; // ecx

  if ( iScanLines >= 2 )
  {
    for ( i = 0; i < rgbaTall; rgba += 4 * rgbaWide )
    {
      if ( i % iScanLines != 0 )
      {
        v6 = rgba;
        if ( rgbaWide > 0 )
        {
          for ( j = rgbaWide; j != 0; --j )
          {
            *v6 = (int)(float)((float)*v6 * 0.69999999);
            v6[1] = (int)(float)((float)v6[1] * 0.69999999);
            v6[2] = (int)(float)((float)v6[2] * 0.69999999);
            v6 += 4;
          }
        }
      }
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018F60
// Name: void ApplyDropShadowToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyDropShadowToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iDropShadowOffset)
{
  int v5; // ecx
  int v6; // ecx
  int v7; // esi
  int v8; // ecx
  unsigned __int8 *v9; // eax
  int v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]
  int iDropShadowOffseta; // [esp+24h] [ebp+14h]

  if ( iDropShadowOffset != 0 )
  {
    v5 = rgbaTall - 1;
    if ( rgbaTall - 1 >= iDropShadowOffset )
    {
      v10 = rgbaWide - 1;
      iDropShadowOffseta = rgbaWide * v5;
      v6 = v5 - iDropShadowOffset;
      v7 = rgbaWide * v6 - iDropShadowOffset;
      v11 = v6 + 1;
      do
      {
        v8 = rgbaWide - 1;
        if ( v10 >= iDropShadowOffset )
        {
          v9 = &rgba[4 * v10 + 3 + 4 * iDropShadowOffseta];
          do
          {
            if ( *v9 == 0 )
            {
              *(v9 - 1) = 0;
              *(_WORD *)(v9 - 3) = 0;
              *v9 = rgba[4 * v7 + 3 + 4 * v8];
            }
            --v8;
            v9 -= 4;
          }
          while ( v8 >= iDropShadowOffset );
        }
        iDropShadowOffseta -= rgbaWide;
        v7 -= rgbaWide;
        --v11;
      }
      while ( v11 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018FF0
// Name: void ApplyOutlineToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyOutlineToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iOutlineSize)
{
  int v4; // esi
  int v5; // ecx
  unsigned __int8 *v6; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // esi
  int v10; // ecx
  int v11; // eax
  unsigned __int8 *v12; // eax
  int v13; // [esp+4h] [ebp-18h]
  int y; // [esp+8h] [ebp-14h]
  unsigned __int8 *v15; // [esp+Ch] [ebp-10h]
  int x; // [esp+10h] [ebp-Ch]
  int shadowX; // [esp+14h] [ebp-8h]
  unsigned __int8 *v18; // [esp+18h] [ebp-4h]

  v4 = iOutlineSize;
  if ( iOutlineSize != 0 )
  {
    v5 = 0;
    y = 0;
    if ( rgbaTall > 0 )
    {
      v15 = rgba + 3;
      do
      {
        x = 0;
        if ( rgbaWide > 0 )
        {
          v6 = v15;
          v18 = v15;
          do
          {
            if ( *v6 == 0 )
            {
              v7 = -v4;
              v8 = -v4;
              v13 = -v4;
              shadowX = -v4;
              if ( -v4 <= v4 )
              {
                do
                {
                  if ( v7 <= iOutlineSize )
                  {
                    v9 = v7 + v5;
                    v10 = rgbaWide * (v7 + v5);
                    do
                    {
                      if ( v8 != 0 || v7 != 0 )
                      {
                        v11 = v8 + x;
                        if ( v8 + x >= 0
                          && v11 < rgbaWide
                          && v9 >= 0
                          && v9 < rgbaTall
                          && *(v12 = &rgba[4 * v10 + 4 * v11]) != 0
                          && v12[1] != 0
                          && v12[2] != 0
                          && v12[3] != 0 )
                        {
                          v6 = v18;
                          *(v18 - 3) = 0;
                          *(v18 - 2) = 0;
                          *(v18 - 1) = 0;
                          *v18 = -1;
                        }
                        else
                        {
                          v6 = v18;
                        }
                      }
                      v8 = shadowX;
                      ++v7;
                      ++v9;
                      v10 += rgbaWide;
                    }
                    while ( v7 <= iOutlineSize );
                    v7 = v13;
                    v5 = y;
                  }
                  v4 = iOutlineSize;
                  shadowX = ++v8;
                }
                while ( v8 <= iOutlineSize );
              }
            }
            v6 += 4;
            ++x;
            v18 = v6;
          }
          while ( x < rgbaWide );
        }
        ++v5;
        v15 += 4 * rgbaWide;
        y = v5;
      }
      while ( v5 < rgbaTall );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019100
// Name: void ApplyGaussianBlurToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyGaussianBlurToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iBlur)
{
  void *v4; // esp
  float *v5; // edi
  double v6; // xmm0_8
  int v7; // esi
  int v8; // ebx
  float v9; // xmm0_4
  void *v10; // esp
  unsigned __int8 *v11; // esi
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  float v15; // xmm1_4
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  float v19; // xmm0_4
  int v20; // edx
  float *v21; // esi
  unsigned int v22; // ecx
  int v23; // ebx
  float v24; // xmm3_4
  float v25; // xmm4_4
  int v26; // ebx
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm4_4
  int v30; // ebx
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm4_4
  int v34; // ebx
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  int v38; // ecx
  int v39; // edx
  unsigned __int8 *v40; // eax
  float *v41; // edx
  int v42; // ecx
  float v43; // xmm3_4
  float v44; // xmm4_4
  unsigned __int8 *v45; // ecx
  int v46; // eax
  unsigned __int8 v47[12]; // [esp+0h] [ebp-50h] BYREF
  double v48; // [esp+Ch] [ebp-44h]
  float v49; // [esp+14h] [ebp-3Ch]
  unsigned __int8 *v50; // [esp+18h] [ebp-38h]
  int v51; // [esp+1Ch] [ebp-34h]
  unsigned __int8 *v52; // [esp+20h] [ebp-30h]
  int v53; // [esp+24h] [ebp-2Ch]
  int i; // [esp+28h] [ebp-28h]
  unsigned __int8 *v55; // [esp+2Ch] [ebp-24h]
  unsigned __int8 *v56; // [esp+30h] [ebp-20h]
  int v57; // [esp+34h] [ebp-1Ch]
  unsigned __int8 *v58; // [esp+38h] [ebp-18h]
  unsigned __int8 *v59; // [esp+3Ch] [ebp-14h]
  unsigned __int8 *v60; // [esp+40h] [ebp-10h]
  unsigned __int8 *v61; // [esp+44h] [ebp-Ch]
  float *v62; // [esp+48h] [ebp-8h]
  int v63; // [esp+4Ch] [ebp-4h]

  if ( iBlur != 0 )
  {
    v4 = alloca(8 * iBlur + 4);
    v5 = (float *)v47;
    v6 = (double)iBlur * 0.6830000000000001;
    v56 = v47;
    if ( (iBlur & 0x40000000) == 0 )
    {
      v48 = v6 * 2.0 * v6;
      v7 = -iBlur;
      v8 = 2 * iBlur + 1;
      v49 = 1.0 / sqrt(v6 * 6.28 * v6);
      do
      {
        __libm_sse2_pow();
        v9 = 2.7 * v49;
        *v5 = v9;
        ++v7;
        ++v5;
        --v8;
      }
      while ( v8 != 0 );
    }
    v10 = alloca(4 * rgbaTall * rgbaWide);
    v11 = v47;
    v55 = v47;
    memcpy(dst: v47, src: rgba, count: 4 * rgbaTall * rgbaWide);
    v50 = rgba;
    v63 = 0;
    if ( rgbaTall > 0 )
    {
      v53 = -iBlur;
      do
      {
        v12 = 0;
        v49 = 0.0;
        if ( rgbaWide > 0 )
        {
          v13 = -iBlur;
          for ( i = -iBlur; ; v13 = i )
          {
            v14 = rgbaWide - 1;
            v15 = 0.0;
            if ( v12 + iBlur >= rgbaWide - 1 )
            {
              v51 = rgbaWide - 1;
            }
            else
            {
              v14 = v12 + iBlur;
              v51 = v12 + iBlur;
            }
            v16 = v13 <= 0 ? 0 : v13;
            v52 = (unsigned __int8 *)v16;
            if ( v16 <= v14 )
            {
              HIDWORD(v48) = iBlur + v63;
              v62 = (float *)&v56[4 * iBlur + 4 * (v16 - v12)];
              do
              {
                v17 = rgbaTall - 1;
                if ( SHIDWORD(v48) >= rgbaTall - 1 )
                {
                  v57 = rgbaTall - 1;
                }
                else
                {
                  v17 = HIDWORD(v48);
                  v57 = HIDWORD(v48);
                }
                v18 = v53 <= 0 ? 0 : v53;
                if ( v18 <= v17 )
                {
                  if ( v17 - v18 + 1 >= 4 )
                  {
                    v19 = *v62;
                    v61 = &v11[4 * v16 + 4 * rgbaWide * v18];
                    v58 = &v11[4 * v16 + 4 * rgbaWide * (v18 + 3)];
                    v59 = &v11[4 * v16 + 4 * rgbaWide * (v18 + 2)];
                    v20 = 16 * rgbaWide;
                    v21 = (float *)&v56[4 * iBlur + 8 + 4 * (v18 - v63)];
                    v60 = &v55[4 * v16 + 4 * rgbaWide * (v18 + 1)];
                    v22 = ((unsigned int)(v57 - v18 - 3) >> 2) + 1;
                    v18 += 4 * v22;
                    do
                    {
                      v23 = *v61;
                      v24 = *(v21 - 2);
                      v61 += v20;
                      v25 = (float)v23;
                      v26 = *v60;
                      v60 += v20;
                      v27 = (float)((float)(v24 * v19) * v25) + v15;
                      v28 = *(v21 - 1);
                      v29 = (float)v26;
                      v30 = *v59;
                      v59 += v20;
                      v31 = v27 + (float)((float)(v28 * v19) * v29);
                      v32 = *v21;
                      v33 = (float)v30;
                      v34 = *v58;
                      v58 += v20;
                      v35 = v31 + (float)((float)(v32 * v19) * v33);
                      v36 = v21[1];
                      v21 += 4;
                      --v22;
                      v15 = (float)((float)(v36 * v19) * (float)v34) + v35;
                    }
                    while ( v22 != 0 );
                    v11 = v55;
                    v16 = (int)v52;
                    v17 = v57;
                  }
                  if ( v18 <= v17 )
                  {
                    v37 = *v62;
                    v52 = &v11[4 * v16 + 4 * rgbaWide * v18];
                    v38 = v17 - v18;
                    v39 = iBlur + v18 - v63;
                    v40 = v52;
                    v41 = (float *)&v56[4 * v39];
                    v42 = v38 + 1;
                    do
                    {
                      v43 = *v41;
                      v44 = (float)*v40;
                      ++v41;
                      v40 += 4 * rgbaWide;
                      --v42;
                      v15 = v15 + (float)((float)(v43 * v37) * v44);
                    }
                    while ( v42 != 0 );
                    v11 = v55;
                  }
                }
                ++v62;
                v52 = (unsigned __int8 *)++v16;
              }
              while ( v16 <= v51 );
              v12 = LODWORD(v49);
            }
            v45 = v50;
            v46 = (int)v15;
            *(_WORD *)(v50 + 1) = -1;
            *v45 = -1;
            if ( (int)v15 >= 255 )
              LOBYTE(v46) = -1;
            ++i;
            ++v12;
            v45[3] = v46;
            v50 = v45 + 4;
            v49 = *(float *)&v12;
            if ( v12 >= rgbaWide )
              break;
          }
        }
        ++v53;
        ++v63;
      }
      while ( v63 < rgbaTall );
    }
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004C1060
// Name: void ApplyRotaryEffectToTexture(int,int,unsigned char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyRotaryEffectToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, bool bRotary)
{
  int v4; // ecx
  unsigned __int8 *v5; // eax

  if ( bRotary )
  {
    v4 = rgbaWide;
    v5 = &rgba[-4 * rgbaWide * (int)((double)rgbaTall * -0.5)];
    if ( rgbaWide > 0 )
    {
      do
      {
        *v5 = 127;
        v5[1] = 127;
        v5[2] = 127;
        v5[3] = -1;
        v5 += 4;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C10B0
// Name: void ApplyScanlineEffectToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyScanlineEffectToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iScanLines)
{
  int i; // esi
  unsigned __int8 *v6; // eax
  int j; // ecx

  if ( iScanLines >= 2 )
  {
    for ( i = 0; i < rgbaTall; rgba += 4 * rgbaWide )
    {
      if ( i % iScanLines != 0 )
      {
        v6 = rgba;
        if ( rgbaWide > 0 )
        {
          for ( j = rgbaWide; j != 0; --j )
          {
            *v6 = (int)(float)((float)*v6 * 0.69999999);
            v6[1] = (int)(float)((float)v6[1] * 0.69999999);
            v6[2] = (int)(float)((float)v6[2] * 0.69999999);
            v6 += 4;
          }
        }
      }
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1150
// Name: void ApplyDropShadowToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyDropShadowToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iDropShadowOffset)
{
  int v5; // ecx
  int v6; // ebp
  int v7; // ecx
  int v8; // esi
  int v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // [esp+4h] [ebp-8h]
  int iDropShadowOffseta; // [esp+1Ch] [ebp+10h]

  if ( iDropShadowOffset != 0 )
  {
    v5 = rgbaTall - 1;
    if ( rgbaTall - 1 >= iDropShadowOffset )
    {
      v11 = rgbaWide - 1;
      v6 = rgbaWide * v5;
      v7 = v5 - iDropShadowOffset;
      v8 = rgbaWide * v7 - iDropShadowOffset;
      iDropShadowOffseta = v7 + 1;
      do
      {
        v9 = rgbaWide - 1;
        if ( v11 >= iDropShadowOffset )
        {
          v10 = &rgba[4 * v11 + 3 + 4 * v6];
          do
          {
            if ( *v10 == 0 )
            {
              *(v10 - 3) = 0;
              *(v10 - 2) = 0;
              *(v10 - 1) = 0;
              *v10 = rgba[4 * v8 + 3 + 4 * v9];
            }
            --v9;
            v10 -= 4;
          }
          while ( v9 >= iDropShadowOffset );
        }
        v6 -= rgbaWide;
        v8 -= rgbaWide;
        --iDropShadowOffseta;
      }
      while ( iDropShadowOffseta != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C11E0
// Name: void ApplyOutlineToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyOutlineToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iOutlineSize)
{
  int v4; // ebx
  int v5; // ecx
  unsigned __int8 *v6; // ebp
  int v7; // edx
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  bool v13; // zf
  unsigned __int8 *v14; // eax
  int x; // [esp+4h] [ebp-14h]
  int y; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v4 = iOutlineSize;
  if ( iOutlineSize != 0 )
  {
    v5 = 0;
    v17 = 0;
    if ( rgbaTall > 0 )
    {
      v6 = rgba + 3;
      v18 = rgba + 3;
      do
      {
        for ( y = 0; y < rgbaWide; ++y )
        {
          if ( *v6 == 0 )
          {
            v7 = -v4;
            v8 = -v4;
            v19 = -v4;
            for ( x = -v4; v8 <= v4; x = v8 )
            {
              if ( v7 <= v4 )
              {
                v9 = v7 + v5;
                v10 = rgbaWide * (v7 + v5);
                do
                {
                  if ( v8 != 0 || v7 != 0 )
                  {
                    v11 = y + v8;
                    if ( v11 >= 0 && v11 < rgbaWide && v9 >= 0 && v9 < rgbaTall )
                    {
                      v12 = v10 + v11;
                      v13 = rgba[4 * v12] == 0;
                      v14 = &rgba[4 * v12];
                      if ( !v13 && v14[1] != 0 && v14[2] != 0 && v14[3] != 0 )
                      {
                        *(v6 - 3) = 0;
                        *(v6 - 2) = 0;
                        *(v6 - 1) = 0;
                        *v6 = -1;
                      }
                    }
                  }
                  v4 = iOutlineSize;
                  v8 = x;
                  ++v7;
                  v10 += rgbaWide;
                  ++v9;
                }
                while ( v7 <= iOutlineSize );
                v7 = v19;
                v5 = v17;
              }
              ++v8;
            }
          }
          v6 += 4;
        }
        ++v5;
        v6 = &v18[4 * rgbaWide];
        v17 = v5;
        v18 = v6;
      }
      while ( v5 < rgbaTall );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1320
// Name: void ApplyGaussianBlurToTexture(int,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyGaussianBlurToTexture(int rgbaWide, int rgbaTall, unsigned __int8 *rgba, int iBlur)
{
  void *v4; // esp
  float *v5; // edi
  double v6; // xmm0_8
  int v7; // esi
  int v8; // ebx
  float v9; // xmm0_4
  void *v10; // esp
  unsigned __int8 *v11; // esi
  int v12; // edx
  int v13; // ebx
  int v14; // eax
  float v15; // xmm1_4
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  float v19; // xmm0_4
  int v20; // edx
  float *v21; // esi
  unsigned int v22; // ecx
  int v23; // ebx
  float v24; // xmm3_4
  float v25; // xmm4_4
  int v26; // ebx
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm4_4
  int v30; // ebx
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm4_4
  int v34; // ebx
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  int v38; // ecx
  int v39; // edx
  unsigned __int8 *v40; // eax
  float *v41; // edx
  int v42; // ecx
  float v43; // xmm3_4
  float v44; // xmm4_4
  unsigned __int8 *v45; // ecx
  int v46; // eax
  unsigned __int8 v47[12]; // [esp+0h] [ebp-50h] BYREF
  double v48; // [esp+Ch] [ebp-44h]
  float v49; // [esp+14h] [ebp-3Ch]
  unsigned __int8 *v50; // [esp+18h] [ebp-38h]
  int v51; // [esp+1Ch] [ebp-34h]
  unsigned __int8 *v52; // [esp+20h] [ebp-30h]
  int v53; // [esp+24h] [ebp-2Ch]
  int i; // [esp+28h] [ebp-28h]
  unsigned __int8 *v55; // [esp+2Ch] [ebp-24h]
  unsigned __int8 *v56; // [esp+30h] [ebp-20h]
  int v57; // [esp+34h] [ebp-1Ch]
  unsigned __int8 *v58; // [esp+38h] [ebp-18h]
  unsigned __int8 *v59; // [esp+3Ch] [ebp-14h]
  unsigned __int8 *v60; // [esp+40h] [ebp-10h]
  unsigned __int8 *v61; // [esp+44h] [ebp-Ch]
  float *v62; // [esp+48h] [ebp-8h]
  int v63; // [esp+4Ch] [ebp-4h]

  if ( iBlur != 0 )
  {
    v4 = alloca(8 * iBlur + 4);
    v5 = (float *)v47;
    v56 = v47;
    if ( (iBlur & 0x40000000) == 0 )
    {
      v6 = (double)iBlur * 0.6830000000000001 * ((double)iBlur * 0.6830000000000001);
      v48 = v6 * 2.0;
      v49 = 1.0 / sqrt(v6 * 6.28);
      v7 = -iBlur;
      v8 = 2 * iBlur + 1;
      do
      {
        __libm_sse2_pow();
        v9 = 2.7 * v49;
        *v5 = v9;
        ++v7;
        ++v5;
        --v8;
      }
      while ( v8 != 0 );
    }
    v10 = alloca(4 * rgbaTall * rgbaWide);
    v11 = v47;
    v55 = v47;
    memcpy(dst: v47, src: rgba, count: 4 * rgbaTall * rgbaWide);
    v50 = rgba;
    v63 = 0;
    if ( rgbaTall > 0 )
    {
      v53 = -iBlur;
      do
      {
        v12 = 0;
        v49 = 0.0;
        if ( rgbaWide > 0 )
        {
          v13 = -iBlur;
          for ( i = -iBlur; ; v13 = i )
          {
            v14 = rgbaWide - 1;
            v15 = 0.0;
            if ( v12 + iBlur >= rgbaWide - 1 )
            {
              v51 = rgbaWide - 1;
            }
            else
            {
              v14 = v12 + iBlur;
              v51 = v12 + iBlur;
            }
            v16 = v13 <= 0 ? 0 : v13;
            v52 = (unsigned __int8 *)v16;
            if ( v16 <= v14 )
            {
              HIDWORD(v48) = iBlur + v63;
              v62 = (float *)&v56[4 * iBlur + 4 * (v16 - v12)];
              do
              {
                v17 = rgbaTall - 1;
                if ( SHIDWORD(v48) >= rgbaTall - 1 )
                {
                  v57 = rgbaTall - 1;
                }
                else
                {
                  v17 = HIDWORD(v48);
                  v57 = HIDWORD(v48);
                }
                v18 = v53 <= 0 ? 0 : v53;
                if ( v17 - v18 + 1 >= 4 )
                {
                  v19 = *v62;
                  v61 = &v11[4 * v16 + 4 * rgbaWide * v18];
                  v58 = &v11[4 * v16 + 4 * rgbaWide * (v18 + 3)];
                  v59 = &v11[4 * v16 + 4 * rgbaWide * (v18 + 2)];
                  v20 = 16 * rgbaWide;
                  v21 = (float *)&v56[4 * iBlur + 8 + 4 * (v18 - v63)];
                  v60 = &v55[4 * v16 + 4 * rgbaWide * (v18 + 1)];
                  v22 = ((unsigned int)(v57 - v18 - 3) >> 2) + 1;
                  v18 += 4 * v22;
                  do
                  {
                    v23 = *v61;
                    v24 = *(v21 - 2);
                    v61 += v20;
                    v25 = (float)v23;
                    v26 = *v60;
                    v60 += v20;
                    v27 = (float)((float)(v24 * v19) * v25) + v15;
                    v28 = *(v21 - 1);
                    v29 = (float)v26;
                    v30 = *v59;
                    v59 += v20;
                    v31 = v27 + (float)((float)(v28 * v19) * v29);
                    v32 = *v21;
                    v33 = (float)v30;
                    v34 = *v58;
                    v58 += v20;
                    v35 = v31 + (float)((float)(v32 * v19) * v33);
                    v36 = (float)(v21[1] * v19) * (float)v34;
                    v21 += 4;
                    --v22;
                    v15 = v35 + v36;
                  }
                  while ( v22 != 0 );
                  v11 = v55;
                  v16 = (int)v52;
                  v17 = v57;
                }
                if ( v18 <= v17 )
                {
                  v37 = *v62;
                  v52 = &v11[4 * v16 + 4 * rgbaWide * v18];
                  v38 = v17 - v18;
                  v39 = iBlur + v18 - v63;
                  v40 = v52;
                  v41 = (float *)&v56[4 * v39];
                  v42 = v38 + 1;
                  do
                  {
                    v43 = *v41;
                    v44 = (float)*v40;
                    ++v41;
                    v40 += 4 * rgbaWide;
                    --v42;
                    v15 = (float)((float)(v43 * v37) * v44) + v15;
                  }
                  while ( v42 != 0 );
                  v11 = v55;
                }
                ++v62;
                v52 = (unsigned __int8 *)++v16;
              }
              while ( v16 <= v51 );
              v12 = LODWORD(v49);
            }
            v45 = v50;
            v46 = (int)v15;
            v50[2] = -1;
            v45[1] = -1;
            *v45 = -1;
            if ( (int)v15 >= 255 )
              LOBYTE(v46) = -1;
            ++i;
            ++v12;
            v45[3] = v46;
            v50 = v45 + 4;
            v49 = *(float *)&v12;
            if ( v12 >= rgbaWide )
              break;
          }
        }
        ++v53;
        ++v63;
      }
      while ( v63 < rgbaTall );
    }
  }
}

} // namespace vgui_perftest
